#ifndef __BDK_CSRS_PKO_H__
#define __BDK_CSRS_PKO_H__
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
 * Cavium PKO.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration pko_auraalg_e
 *
 * PKO Aura Modify Algorithm Enumeration
 * Enumerates the amount to decrement the FPA aura count during PKO_SEND_AURA_S
 * processing - see PKO_SEND_AURA_S[ALG]. When a PKO_SEND_AURA_S is present, the
 * hardware decrements the FPA count for aura PKO_SEND_AURA_S[AURA] by the amount
 * defined below. mbufs_freed is the number of FPA frees during all PKO processing
 * of all PKO_SEND_GATHER_S and PKO_SEND_LINK_S subdescriptors that are present prior
 * to this PKO_SEND_AURA_S in the PKO SEND descriptor.
 */
#define BDK_PKO_AURAALG_E_NOP (0) /**< No operation.
                                       aura_cnt = No change */
#define BDK_PKO_AURAALG_E_SUB (3) /**< Subtract.
                                       aura_cnt = aura_cnt - PKO_SEND_AURA_S[OFFSET]. */
#define BDK_PKO_AURAALG_E_SUBLEN (7) /**< Subtract length.
                                       aura_cnt = aura_cnt - PKO_SEND_AURA_S[OFFSET] - PKO_SEND_HDR_S[TOTAL]. */
#define BDK_PKO_AURAALG_E_SUBMBUF (0xb) /**< Subtract mbuf count.
                                       aura_cnt = aura_cnt - PKO_SEND_AURA_S[OFFSET] - mbufs_freed. */

/**
 * Enumeration pko_bar_e
 *
 * PKO Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_PKO_BAR_E_PKO_PF_BAR0 (0x854000000000ll) /**< Base address for standard registers. */
#define BDK_PKO_BAR_E_PKO_PF_BAR4 (0x854300000000ll) /**< Base address for MSI-X registers. */
#define BDK_PKO_BAR_E_PKO_VFX_BAR0(a) (0x854400000000ll + 0x100000ll * (a)) /**< Base address for standard registers. */

/**
 * Enumeration pko_ckl4alg_e
 *
 * PKO Checksum L4 Algorithm Enumeration
 * Enumerates the different L4 checksum algorithms for PKO_SEND_HDR_S[CKL4].
 */
#define BDK_PKO_CKL4ALG_E_NONE (0) /**< No checksum. */
#define BDK_PKO_CKL4ALG_E_SCTP (3) /**< SCTP L4 checksum. */
#define BDK_PKO_CKL4ALG_E_TCP (2) /**< TCP L4 checksum. */
#define BDK_PKO_CKL4ALG_E_UDP (1) /**< UDP L4 checksum. */

/**
 * Enumeration pko_coloralg_e
 *
 * PKO Color Algorithm Enumeration
 * Enumerates the different shaper update and internal color algorithms of PKO_SEND_EXT_S[COL].
 */
#define BDK_PKO_COLORALG_E_CIR_ONLY (2) /**< One-rate, two-color based on CIR. The packet uses and adjusts only the CIR counter as it
                                       traverses through an enabled shaper, and does not use nor adjust the PIR counter in
                                       the shaper. Since the PIR counter states are not used, the shapers cannot
                                       downgrade a packet to RED_SEND nor RED_DROP, and the packet can never be RED_SEND
                                       nor RED_DROP. The shapers can downgrade from GREEN to YELLOW, so the packet may
                                       end either GREEN or YELLOW after any shaper. Similar behavior to when
                                       PKO_*_PIR[ENABLE] is clear in all traversed shapers. */
#define BDK_PKO_COLORALG_E_FULL_COLOR (0) /**< Two-rate, three-color coloring. Normal enabled mode. Both the CIR and PIR counters are
                                       used and adjusted per mode as the packet traverses through an enabled shaper. The internal
                                       color of a packet can be any of GREEN, YELLOW, RED_SEND, or RED_DROP after a shaper,
                                       depending on the shaper state and configuration. This is the default when a PKO_SEND_EXT_S
                                       is not present in the descriptor. */
#define BDK_PKO_COLORALG_E_NO_COLOR (3) /**< No coloring. No shaper can change the packet from its initial GREEN color. Neither the CIR
                                       nor PIR counters are used nor adjusted in any shaper as this packet traverses.
                                       Similar behavior to when both PKO_*_CIR[ENABLE] and PKO_*_PIR[ENABLE] are clear
                                       in all traversed shapers. */
#define BDK_PKO_COLORALG_E_PIR_ONLY (1) /**< One-rate, two-color coloring based on PIR. The packet uses and adjusts only the
                                       PIR counter as it traverses through an enabled shaper, and does not use nor adjust the
                                       CIR counter in the shaper. Since the CIR counter states are not used, the shapers cannot
                                       downgrade a packet to YELLOW, and the packet can never be YELLOW. The shapers can
                                       downgrade from GREEN to RED_SEND or RED_DROP, so the packet may end GREEN, RED_SEND,
                                       or RED_DROP after any shaper. Similar behavior to when PKO_*_CIR[ENABLE] is clear in
                                       all traversed shapers. */

/**
 * Enumeration pko_colorresult_e
 *
 * PKO Color Result Enumeration
 * Enumerates the different colors of PKO_MEM_RESULT_S[COLOR] and PKO_*_PICK[COLOR].
 */
#define BDK_PKO_COLORRESULT_E_GREEN (0) /**< Green. */
#define BDK_PKO_COLORRESULT_E_RED_DROP (3) /**< Red, PKO will drop the packet. */
#define BDK_PKO_COLORRESULT_E_RED_SEND (2) /**< Red, PKO will send the packet. */
#define BDK_PKO_COLORRESULT_E_YELLOW (1) /**< Yellow. */

/**
 * Enumeration pko_cpsenddrop_e
 *
 * PKO Send-Packet Drop Error Codes Enumeration
 * Enumerates the error code for illegally constructed send-packet drops, stored in
 * PKO_PDM_STS[CP_SENDPKT_ERR_DROP_CODE].
 */
#define BDK_PKO_CPSENDDROP_E_DROP_EXTHDR_NPOS2 (3) /**< Send-packet dropped because PKO_SEND_EXT_S was not in position 2 (not following header). */
#define BDK_PKO_CPSENDDROP_E_DROP_HDR_EXTHDR_ONLY (2) /**< Send-packet dropped because it was a header and extended header only. */
#define BDK_PKO_CPSENDDROP_E_DROP_HDR_ONLY (1) /**< Send-packet dropped because software sent a PKO_SEND_HDR_S, without 'no data send' subdescriptors. */
#define BDK_PKO_CPSENDDROP_E_DROP_SIZE_16 (4) /**< Send-packet dropped because its was size 16. */
#define BDK_PKO_CPSENDDROP_E_SENDPASS (0) /**< No error. Send-packet was not dropped because of illegal construction. */

/**
 * Enumeration pko_dqop_e
 *
 * PKO DQ Operation Enumeration
 * Enumerates the different IOBDMA/LMTDMA operation codes and PKO_QUERY_RTN_S[DQOP] values.
 */
#define BDK_PKO_DQOP_E_CLOSE (2) /**< Close queue operation. See PKO_QUERY_LD_S and PKO_QUERY_DMA_S. */
#define BDK_PKO_DQOP_E_OPEN (1) /**< Open queue operation. See PKO_QUERY_LD_S and PKO_QUERY_DMA_S. */
#define BDK_PKO_DQOP_E_QUERY (3) /**< Query operation. See PKO_QUERY_LD_S and PKO_QUERY_DMA_S. */
#define BDK_PKO_DQOP_E_SEND (0) /**< Send operation. See PKO_SEND_DMA_S. */

/**
 * Enumeration pko_dqstatus_e
 *
 * PKO Descriptor Status Enumeration
 * Enumerates the different descriptor queue command results. See PKO_QUERY_RTN_S[DQSTATUS].
 */
#define BDK_PKO_DQSTATUS_E_DQALREADYCREATED (0xc) /**< This is a non-fatal error. PKO could not do the command because the DQ was already
                                       created. (For example, can't double open a DQ). */
#define BDK_PKO_DQSTATUS_E_DQBADSTATE (8) /**< PKO could not enqueue the descriptor because the queue was not ready to enqueue
                                       descriptors.
                                       
                                       Internal:
                                       Not used in hardware, currently. */
#define BDK_PKO_DQSTATUS_E_DQNOFPABUF (9) /**< PKO could not enqueue the descriptor because FPA could not allocate a free FPA buffer to
                                       hold the descriptor. IMPORTANT: This is a fatal error, and will require a reset. If this
                                       happens to a queue-open or queue-close command, the PDM internal state could be
                                       incoherrent. If this status is seen, it is an indication reset is needed. The interrupt
                                       PKO_FPA_NO_PTRS will be signaled as soon as the FPA returns the condition of
                                       having no pointers. */
#define BDK_PKO_DQSTATUS_E_DQNOTCREATED (0xd) /**< This is a non-fatal error. PKO could not do the command because the DQ was not already
                                       created. (For example, can't close a DQ that is not created). */
#define BDK_PKO_DQSTATUS_E_DQNOTEMPTY (0xe) /**< This is a non-fatal error. PKO could not do the command because the DQ was not empty. (For
                                       example, can't close a DQ that is not empty). */
#define BDK_PKO_DQSTATUS_E_DQSENDPKTDROP (0xf) /**< PKO dropped the send-packet command due to illegal construction; non-fatal. See
                                       PKO_PDM_STS[CP_SENDPKT_ERR_DROP]. Corresponding interrupts will fire. Reasons for failure:
                                       1. Send-packet contained more than 15 words (including header). 2. Only a header and
                                       extended header were sent. 3. Extended header was not in position 2. 4. Only a header was
                                       sent. */
#define BDK_PKO_DQSTATUS_E_PASS (0) /**< No error. In the case of an PKO_SEND_DMA_S, indicates that PKO successfully enqueued the
                                       descriptor. */

/**
 * Enumeration pko_lmac_e
 *
 * PKO LMAC Enumeration
 * Enumerates the values of PKO_LUT index.
 */
#define BDK_PKO_LMAC_E_BGXX_PORTX(a,b) (2 + 4 * (a) + (b)) /**< BGX {a} port {b} channel {c} LMAC index. */
#define BDK_PKO_LMAC_E_DPI (1) /**< DPI LMAC index. */
#define BDK_PKO_LMAC_E_LOOPBACK (0) /**< Loopback pipe LMAC index. */

/**
 * Enumeration pko_memalg_e
 *
 * PKO Memory Modify Algorithm Enumeration
 * Enumerates the different algorithms for modifying memory; see PKO_SEND_MEM_S[ALG].
 */
#define BDK_PKO_MEMALG_E_ADD (8) /**< Add.
                                       mem = mem + PKO_SEND_MEM_S[OFFSET]. */
#define BDK_PKO_MEMALG_E_ADDLEN (0xa) /**< Add length.
                                       mem = mem + PKO_SEND_MEM_S[OFFSET] + PKO_SEND_HDR_S[TOTAL]. */
#define BDK_PKO_MEMALG_E_ADDMBUF (0xc) /**< Add mbufs freed.
                                       mem = mem + PKO_SEND_MEM_S[OFFSET] + mbufs_freed. mbufs_freed is as defined in
                                       PKO_AURAALG_E. */
#define BDK_PKO_MEMALG_E_SET (0) /**< Set.
                                       mem = PKO_SEND_MEM_S[OFFSET]. */
#define BDK_PKO_MEMALG_E_SETRSLT (2) /**< Set the memory location to the final resulting color and state of the packet.
                                       PKO_MEM_RESULT_S indicates the store value. PKO_SEND_MEM_S[DSZ] must be B64.
                                       mem = PKO_MEM_RESULT_S. */
#define BDK_PKO_MEMALG_E_SETTSTMP (1) /**< Set the memory location to the timestamp the packet was at the interface. See the PTP
                                       chapter. When used, PKO_SEND_MEM_S[DSZ] must be B64 and PKO_SEND_HDR_S[TSTMP]
                                       must be set in the descriptor.
                                       For non-NULL interfaces:
                                       mem = MIO_PTP_CLOCK_HI at packet send.
                                       Else, for NULL interface:
                                       mem = 0x1. */
#define BDK_PKO_MEMALG_E_SUB (9) /**< Subtract.
                                       mem = mem - PKO_SEND_MEM_S[OFFSET].
                                       Note: IOI bandwidth is optimized if a memory decrement by one is used rather than any
                                       other memory set/add/sub. */
#define BDK_PKO_MEMALG_E_SUBLEN (0xb) /**< Subtract length.
                                       mem = mem - PKO_SEND_MEM_S[OFFSET] - PKO_SEND_HDR_S[TOTAL]. */
#define BDK_PKO_MEMALG_E_SUBMBUF (0xd) /**< Subtract mbufs freed.
                                       mem = mem - PKO_SEND_MEM_S[OFFSET] - mbufs_freed. mbufs_freed is as defined in
                                       PKO_AURAALG_E. */

/**
 * Enumeration pko_memdsz_e
 *
 * PKO Memory Data Size Enumeration
 * Enumerates the datum size for modifying memory; see PKO_SEND_MEM_S[DSZ].
 */
#define BDK_PKO_MEMDSZ_E_B16 (2) /**< 16 bits. PKO_SEND_MEM_S[ALG] must be PKO_MEMALG_E::SET. */
#define BDK_PKO_MEMDSZ_E_B32 (1) /**< 32 bits. PKO_SEND_MEM_S[ALG] must not be PKO_MEMALG_E::SETTSTMP nor PKO_MEMALG_E::SETRSLT. */
#define BDK_PKO_MEMDSZ_E_B64 (0) /**< 64 bits. */
#define BDK_PKO_MEMDSZ_E_B8 (3) /**< 8 bits. PKO_SEND_MEM_S[ALG] must be PKO_MEMALG_E::SET. */

/**
 * Enumeration pko_pf_int_vec_e
 *
 * PKO Interrupt Source Enumeration
 * Enumerates the different PKO-generated interrupts.
 */
#define BDK_PKO_PF_INT_VEC_E_PKO_DQ_ECC_DBE (3) /**< See interrupt clears PKO_DQ_ECC_DBE_W1C,
                                       interrupt sets PKO_DQ_ECC_DBE_W1S,
                                       enable clears PKO_DQ_ECC_DBE_INT_ENA_W1C, and
                                       enable sets PKO_DQ_ECC_DBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_DQ_ECC_SBE (2) /**< See interrupt clears PKO_DQ_ECC_SBE_W1C,
                                       interrupt sets PKO_DQ_ECC_SBE_W1S,
                                       enable clears PKO_DQ_ECC_SBE_INT_ENA_W1C, and
                                       enable sets PKO_DQ_ECC_SBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_L1_ECC_DBE (0xb) /**< See interrupt clears PKO_L1_ECC_DBE_W1C,
                                       interrupt sets PKO_L1_ECC_DBE_W1S,
                                       enable clears PKO_L1_ECC_DBE_INT_ENA_W1C, and
                                       enable sets PKO_L1_ECC_DBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_L1_ECC_SBE (0xa) /**< See interrupt clears PKO_L1_ECC_SBE_W1C,
                                       interrupt sets PKO_L1_ECC_SBE_W1S,
                                       enable clears PKO_L1_ECC_SBE_INT_ENA_W1C, and
                                       enable sets PKO_L1_ECC_SBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_L2_ECC_DBE (5) /**< See interrupt clears PKO_L2_ECC_DBE_W1C,
                                       interrupt sets PKO_L2_ECC_DBE_W1S,
                                       enable clears PKO_L2_ECC_DBE_INT_ENA_W1C, and
                                       enable sets PKO_L2_ECC_DBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_L2_ECC_SBE (4) /**< See interrupt clears PKO_L2_ECC_SBE_W1C,
                                       interrupt sets PKO_L2_ECC_SBE_W1S,
                                       enable clears PKO_L2_ECC_SBE_INT_ENA_W1C, and
                                       enable sets PKO_L2_ECC_SBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_L3_ECC_DBE (7) /**< See interrupt clears PKO_L3_ECC_DBE_W1C,
                                       interrupt sets PKO_L3_ECC_DBE_W1S,
                                       enable clears PKO_L3_ECC_DBE_INT_ENA_W1C, and
                                       enable sets PKO_L3_ECC_DBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_L3_ECC_SBE (6) /**< See interrupt clears PKO_L3_ECC_SBE_W1C,
                                       interrupt sets PKO_L3_ECC_SBE_W1S,
                                       enable clears PKO_L3_ECC_SBE_INT_ENA_W1C, and
                                       enable sets PKO_L3_ECC_SBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_LUT_ECC_DBE (1) /**< See interrupt clears PKO_LUT_ECC_DBE_W1C,
                                       interrupt sets PKO_LUT_ECC_DBE_W1S,
                                       enable clears PKO_LUT_ECC_DBE_INT_ENA_W1C, and
                                       enable sets PKO_LUT_ECC_DBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_LUT_ECC_SBE (0) /**< See interrupt clears PKO_LUT_ECC_SBE_W1C,
                                       interrupt sets PKO_LUT_ECC_SBE_W1S,
                                       enable clears PKO_LUT_ECC_SBE_INT_ENA_W1C, and
                                       enable sets PKO_LUT_ECC_SBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_NCB_ECC_DBE (0xf) /**< See interrupt clears PKO_NCB_ECC_DBE_W1C,
                                       interrupt sets PKO_NCB_ECC_DBE_W1S,
                                       enable clears PKO_NCB_ECC_DBE_INT_ENA_W1C, and
                                       enable sets PKO_NCB_ECC_DBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_NCB_ECC_SBE (0xe) /**< See interrupt clears PKO_NCB_ECC_SBE_W1C,
                                       interrupt sets PKO_NCB_ECC_SBE_W1S,
                                       enable clears PKO_NCB_ECC_SBE_INT_ENA_W1C, and
                                       enable sets PKO_NCB_ECC_SBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_NCB_INT (0x15) /**< See interrupt clears PKO_NCB_INT,
                                       interrupt sets PKO_NCB_INT_W1S,
                                       enable clears PKO_NCB_INT_ENA_W1C, and
                                       enable sets PKO_NCB_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_PDM_ECC_DBE (9) /**< See interrupt clears PKO_PDM_ECC_DBE_W1C,
                                       interrupt sets PKO_PDM_ECC_DBE_W1S,
                                       enable clears PKO_PDM_ECC_DBE_INT_ENA_W1C, and
                                       enable sets PKO_PDM_ECC_DBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_PDM_ECC_SBE (8) /**< See interrupt clears PKO_PDM_ECC_SBE_W1C,
                                       interrupt sets PKO_PDM_ECC_SBE_W1S,
                                       enable clears PKO_PDM_ECC_SBE_INT_ENA_W1C, and
                                       enable sets PKO_PDM_ECC_SBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_PDM_STS (0x14) /**< See interrupt clears PKO_PDM_STS,
                                       interrupt sets PKO_PDM_STS_W1S,
                                       enable clears PKO_PDM_STS_INT_ENA_W1C, and
                                       enable sets PKO_PDM_STS_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_PEB_DBE (0x11) /**< See interrupt clears PKO_PEB_ECC_DBE_W1C,
                                       interrupt sets PKO_PEB_ECC_DBE_W1S,
                                       enable clears PKO_PEB_ECC_DBE_INT_ENA_W1C, and
                                       enable sets PKO_PEB_ECC_DBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_PEB_ERR (0x12) /**< See interrupt clears PKO_PEB_ERR_INT,
                                       interrupt sets PKO_PEB_ERR_INT_W1S,
                                       enable clears PKO_PEB_ERR_INT_ENA_W1C, and
                                       enable sets PKO_PEB_ERR_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_PEB_SBE (0x10) /**< See interrupt clears PKO_PEB_ECC_SBE_W1C,
                                       interrupt sets PKO_PEB_ECC_SBE_W1S,
                                       enable clears PKO_PEB_ECC_SBE_INT_ENA_W1C, and
                                       enable sets PKO_PEB_ECC_SBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_PQ_DRAIN (0x13) /**< See interrupt clears PKO_PQ_DRAIN_W1C,
                                       interrupt sets PKO_PQ_DRAIN_W1S,
                                       enable clears PKO_PQ_DRAIN_INT_ENA_W1C, and
                                       enable sets PKO_PQ_DRAIN_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_PQ_ECC_DBE (0xd) /**< See interrupt clears PKO_PQ_ECC_DBE_W1C,
                                       interrupt sets PKO_PQ_ECC_DBE_W1S,
                                       enable clears PKO_PQ_ECC_DBE_INT_ENA_W1C, and
                                       enable sets PKO_PQ_ECC_DBE_INT_ENA_W1S. */
#define BDK_PKO_PF_INT_VEC_E_PKO_PQ_ECC_SBE (0xc) /**< See interrupt clears PKO_PQ_ECC_SBE_W1C,
                                       interrupt sets PKO_PQ_ECC_SBE_W1S,
                                       enable clears PKO_PQ_ECC_SBE_INT_ENA_W1C, and
                                       enable sets PKO_PQ_ECC_SBE_INT_ENA_W1S. */

/**
 * Enumeration pko_redalg_e
 *
 * PKO Red Algorithm Enumeration
 * Enumerates the different algorithms of PKO_SEND_HDR_S[SHP_RA].
 */
#define BDK_PKO_REDALG_E_DISCARD (3) /**< When the shaper is in RED state, discard this packet, same as if
                                       PKO_*_SHAPE[RED_ALGO] were 3 (DISCARD) in all shapers traversed by this packet. */
#define BDK_PKO_REDALG_E_SEND (1) /**< When a shaper traversed by this packet is in RED state, send the packet through
                                       it without stalling or dropping the packet, same as if PKO_*_SHAPE[RED_ALGO]
                                       were 1 (SEND) in all shapers traversed by the packet. (No shaper traversed by this packet
                                       can stall or drop this packet.) */
#define BDK_PKO_REDALG_E_STALL (2) /**< When the shaper is in RED state, stall this packet in the shaper until the shaper
                                       reaches yellow or green state, same as if PKO_*_SHAPE[RED_ALGO]
                                       were 2 (STALL) in all shapers traversed by this packet. (No shaper traversed by this
                                       packet can drop this packet.) */
#define BDK_PKO_REDALG_E_STD (0) /**< Standard shaper handling. When a shaper traversed by this packet is in RED state,
                                       this packet will be processed according to the shaper PKO_*_SHAPE[RED_ALGO]
                                       configuration. */

/**
 * Enumeration pko_sendcrcalg_e
 *
 * PKO Send CRC Algorithm Enumeration
 * Enumerates the CRC algorithm used; see PKO_SEND_CRC_S[ALG].
 */
#define BDK_PKO_SENDCRCALG_E_CRC32 (0) /**< Ethernet format big-endian CRC-32 (polynomial 0x04C11DB7). The initial value is usually
                                       0xFFFFFFFF, corrected for any appropriate header fields to be included. */
#define BDK_PKO_SENDCRCALG_E_CRC32C (1) /**< SCTP/iSCSI format big-endian CRC-32c (polynomial 0x11EDC6F41). The initial value is
                                       usually 0xFFFFFFFF, corrected for any appropriate header fields to be included. */
#define BDK_PKO_SENDCRCALG_E_ONES16 (2) /**< 16-bit one's complement checksumming algorithm. Cannot be used in conjuction
                                       with CKL4. */

/**
 * Enumeration pko_sendsubdc_e
 *
 * PKO Send Subdescriptor Operation Enumeration
 * Enumerates the different subdescriptor codes. The subdescriptor codes differentiate PKO send
 * descriptor words excluding PKO_SEND_HDR_S which is determined by its position as the first
 * subdescriptor.
 */
#define BDK_PKO_SENDSUBDC_E_AURA (0xb) /**< See PKO_SEND_AURA_S. */
#define BDK_PKO_SENDSUBDC_E_CRC (0xe) /**< See PKO_SEND_CRC_S. */
#define BDK_PKO_SENDSUBDC_E_EXT (0xd) /**< See PKO_SEND_EXT_S. */
#define BDK_PKO_SENDSUBDC_E_FREE (9) /**< See PKO_SEND_FREE_S. */
#define BDK_PKO_SENDSUBDC_E_GATHER0 (2) /**< See PKO_SEND_GATHER_S. Uses a 3-bit subdescriptor, discarding bit 0. */
#define BDK_PKO_SENDSUBDC_E_IMM (0xf) /**< See PKO_SEND_IMM_S. */
#define BDK_PKO_SENDSUBDC_E_JUMP0 (4) /**< See PKO_SEND_JUMP_S. Uses a 3-bit subdescriptor, discarding bit 0. */
#define BDK_PKO_SENDSUBDC_E_LINK0 (0) /**< See PKO_SEND_LINK_S. Uses a 3-bit subdescriptor, discarding bit 0. */
#define BDK_PKO_SENDSUBDC_E_MEM (0xc) /**< See PKO_SEND_MEM_S. */
#define BDK_PKO_SENDSUBDC_E_TSO (8) /**< See PKO_SEND_TSO_S. */
#define BDK_PKO_SENDSUBDC_E_WORK (0xa) /**< See PKO_SEND_WORK_S. */

/**
 * Structure pko_mem_result_s
 *
 * PKO Memory Value Structure
 * When PKO_SEND_MEM_S[ALG]=PKO_MEMALG_E::SETRSLT, the value written to memory is formed with
 * this structure.
 */
union bdk_pko_mem_result_s
{
    uint64_t u;
    struct bdk_pko_mem_result_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t nl                    : 1;  /**< [  3:  3] Null interface. The packet was processed by the null interface. */
        uint64_t color                 : 2;  /**< [  2:  1] Final color of the packet. Enumerated by PKO_COLORRESULT_E. */
        uint64_t v                     : 1;  /**< [  0:  0] Valid. Always set by hardware so software can distinguish from data that was (presumed to
                                                                 be) zeroed by software before the send operation. */
#else /* Word 0 - Little Endian */
        uint64_t v                     : 1;  /**< [  0:  0] Valid. Always set by hardware so software can distinguish from data that was (presumed to
                                                                 be) zeroed by software before the send operation. */
        uint64_t color                 : 2;  /**< [  2:  1] Final color of the packet. Enumerated by PKO_COLORRESULT_E. */
        uint64_t nl                    : 1;  /**< [  3:  3] Null interface. The packet was processed by the null interface. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_mem_result_s_s cn; */
};

/**
 * Structure pko_meta_desc_s
 *
 * PKO Meta-Packet Descriptor Structure
 * A meta packet descriptor represents its corresponding PKO SEND descriptor during PKOs
 * queueing, conditioning, and scheduling before transferring the packet. PKO_META_DESC_S is the
 * meta packet structure queued in DQs (in L2/DRAM). The PKO_*_PICK CSR's are the meta packet
 * structure while the packet is actively being conditioned and scheduled.
 */
union bdk_pko_meta_desc_s
{
    uint32_t u;
    struct bdk_pko_meta_desc_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t jump                  : 1;  /**< [ 31: 31] Set when the corresponding descriptor has a PKO_SEND_JUMP_S. See also
                                                                 PKO_*_PICK[JUMP]. */
        uint32_t fpd                   : 1;  /**< [ 30: 30] Set when the corresponding descriptor is stored at the beginning of a
                                                                 new cache line. See also PKO_*_PICK[FPD]. */
        uint32_t reserved_29           : 1;
        uint32_t adjust                : 9;  /**< [ 28: 20] See PKO_SEND_HDR_S[SHP_CHG]. */
        uint32_t col                   : 2;  /**< [ 19: 18] PKO_SEND_EXT_S[COL] if present in the corresponding packet descriptor,
                                                                 else 0x0 (i.e. PKO_COLORALG_E::FULL_COLOR). See also
                                                                 PKO_*_PICK[PIR_DIS,CIR_DIS]. */
        uint32_t ra                    : 2;  /**< [ 17: 16] See PKO_SEND_HDR_S[SHP_RA]. */
        uint32_t length                : 16; /**< [ 15:  0] Meta packet length. Generally, the size of the outgoing packet
                                                                 including pad, but excluding FCS and preamble.

                                                                 For metas corresponding to when PKO_SEND_HDR_S[TSO] is clear:

                                                                  [LENGTH] = PKO_PDM_DQ{a}_MINPAD[MINPAD] ?
                                                                               MAX(PKO_SEND_HDR_S[TOTAL], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               PKO_SEND_HDR_S[TOTAL]

                                                                 For metas corresponding to when PKO_SEND_HDR_S[TSO] is set:

                                                                  [LENGTH] = PKO_PDM_DQ{a}_MINPAD[MINPAD] ?
                                                                               MAX(FPS+PKO_SEND_HDR_S[TSO_SB], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               (FPS+PKO_SEND_HDR_S[TSO_SB])

                                                                 {a} is the DQ that the PKO SEND used. FPS is the number of payload bytes
                                                                 in the TSO segment. See also PKO_*_PICK[LENGTH]. */
#else /* Word 0 - Little Endian */
        uint32_t length                : 16; /**< [ 15:  0] Meta packet length. Generally, the size of the outgoing packet
                                                                 including pad, but excluding FCS and preamble.

                                                                 For metas corresponding to when PKO_SEND_HDR_S[TSO] is clear:

                                                                  [LENGTH] = PKO_PDM_DQ{a}_MINPAD[MINPAD] ?
                                                                               MAX(PKO_SEND_HDR_S[TOTAL], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               PKO_SEND_HDR_S[TOTAL]

                                                                 For metas corresponding to when PKO_SEND_HDR_S[TSO] is set:

                                                                  [LENGTH] = PKO_PDM_DQ{a}_MINPAD[MINPAD] ?
                                                                               MAX(FPS+PKO_SEND_HDR_S[TSO_SB], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               (FPS+PKO_SEND_HDR_S[TSO_SB])

                                                                 {a} is the DQ that the PKO SEND used. FPS is the number of payload bytes
                                                                 in the TSO segment. See also PKO_*_PICK[LENGTH]. */
        uint32_t ra                    : 2;  /**< [ 17: 16] See PKO_SEND_HDR_S[SHP_RA]. */
        uint32_t col                   : 2;  /**< [ 19: 18] PKO_SEND_EXT_S[COL] if present in the corresponding packet descriptor,
                                                                 else 0x0 (i.e. PKO_COLORALG_E::FULL_COLOR). See also
                                                                 PKO_*_PICK[PIR_DIS,CIR_DIS]. */
        uint32_t adjust                : 9;  /**< [ 28: 20] See PKO_SEND_HDR_S[SHP_CHG]. */
        uint32_t reserved_29           : 1;
        uint32_t fpd                   : 1;  /**< [ 30: 30] Set when the corresponding descriptor is stored at the beginning of a
                                                                 new cache line. See also PKO_*_PICK[FPD]. */
        uint32_t jump                  : 1;  /**< [ 31: 31] Set when the corresponding descriptor has a PKO_SEND_JUMP_S. See also
                                                                 PKO_*_PICK[JUMP]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_meta_desc_s_s cn; */
};

/**
 * Structure pko_send_aura_s
 *
 * PKO Send Aura Subdescriptor Structure
 * The send aura subdescriptor is used to decrement aura counts.
 *
 * When PKO_SEND_HDR_S[TSO] is set in the descriptor, the PKO_SEND_AURA_S
 * operations effectively execute only once for the descriptor, not once
 * per TSO segment.
 */
union bdk_pko_send_aura_s
{
    uint64_t u[2];
    struct bdk_pko_send_aura_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t subdc4                : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send aura. Enumerated by PKO_SENDSUBDC_E::AURA. */
        uint64_t reserved_49_59        : 11;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_40_47        : 8;
        uint64_t aura                  : 16; /**< [ 39: 24] Guest-aura number. The guest-aura to use for subsequent FPA frees in this
                                                                 PKO SEND descriptor and the aura whose aura count may be decremented by
                                                                 this PKO_SEND_AURA_S.

                                                                 For the FPA to not discard the free request, FPA_PF_MAP() must map
                                                                 [AURA] and PKO_PF_VF()_GMCTL[GMID] as valid. */
        uint64_t reserved_12_23        : 12;
        uint64_t alg                   : 4;  /**< [ 11:  8] Aura count adder algorithm. Combined with [OFFSET], determines the amount
                                                                 to decrement [AURA]'s aura count. Enumerated by PKO_AURAALG_E.

                                                                 [ALG] may commonly be NOP, and PKO_SEND_AURA_S sudescriptor
                                                                 usage may be infrequent, when the aura count corresponds to the number of
                                                                 buffers. This is because all FPA buffer frees from PKO (including those
                                                                 created while processing PKO_SEND_GATHER_S, PKO_SEND_LINK_S,
                                                                 PKO_SEND_JUMP_S, or PKO_SEND_FREE_S subdescriptors) are optionally
                                                                 subject to an FPA-automatic aura update which decrements the aura count
                                                                 by one. See the FPA chapter.

                                                                 The aura count change will not occur until after PKO dequeues the PKO SEND
                                                                 descriptor and starts processing it. Otherwise, PKO may create the FPA
                                                                 aura count decrement in any order relative to any aura count update
                                                                 needed to process any other PKO_SEND_AURA_S in this or any other PKO SEND,
                                                                 in any order relative to any PKO FPA frees needed to process this or
                                                                 any other PKO SEND, and in any order relative to any FPA frees/allocates
                                                                 needed for DQ DRAM buffering. The aura count change may occur in
                                                                 any order relative to any L2/DRAM updates or any work queue add
                                                                 needed to process this or any other PKO SEND. */
        uint64_t offset                : 8;  /**< [  7:  0] Constant value to subtract. Combined with [ALG], determines the amount
                                                                 to decrement [AURA]'s aura count. [OFFSET] could represent outside FCS
                                                                 bytes appended to a packet when coupled with PKO_SEND_HDR_S[TOTAL], or
                                                                 could directly indicate an aura quantum in other cases, for example.
                                                                 [OFFSET] must be zero when [ALG] is NOP.

                                                                 The aura count change will not occur until after PKO dequeues the PKO SEND
                                                                 descriptor and starts processing it. Otherwise, PKO may create the FPA
                                                                 aura count decrement in any order relative to any aura count update
                                                                 needed to process any other PKO_SEND_AURA_S in this or any other PKO SEND,
                                                                 in any order relative to any PKO FPA frees needed to process this or
                                                                 any other PKO SEND, and in any order relative to any FPA frees/allocates
                                                                 needed for DQ DRAM buffering. The aura count change may occur in
                                                                 any order relative to any L2/DRAM updates or any work queue add
                                                                 needed to process this or any other PKO SEND. */
#else /* Word 0 - Little Endian */
        uint64_t offset                : 8;  /**< [  7:  0] Constant value to subtract. Combined with [ALG], determines the amount
                                                                 to decrement [AURA]'s aura count. [OFFSET] could represent outside FCS
                                                                 bytes appended to a packet when coupled with PKO_SEND_HDR_S[TOTAL], or
                                                                 could directly indicate an aura quantum in other cases, for example.
                                                                 [OFFSET] must be zero when [ALG] is NOP.

                                                                 The aura count change will not occur until after PKO dequeues the PKO SEND
                                                                 descriptor and starts processing it. Otherwise, PKO may create the FPA
                                                                 aura count decrement in any order relative to any aura count update
                                                                 needed to process any other PKO_SEND_AURA_S in this or any other PKO SEND,
                                                                 in any order relative to any PKO FPA frees needed to process this or
                                                                 any other PKO SEND, and in any order relative to any FPA frees/allocates
                                                                 needed for DQ DRAM buffering. The aura count change may occur in
                                                                 any order relative to any L2/DRAM updates or any work queue add
                                                                 needed to process this or any other PKO SEND. */
        uint64_t alg                   : 4;  /**< [ 11:  8] Aura count adder algorithm. Combined with [OFFSET], determines the amount
                                                                 to decrement [AURA]'s aura count. Enumerated by PKO_AURAALG_E.

                                                                 [ALG] may commonly be NOP, and PKO_SEND_AURA_S sudescriptor
                                                                 usage may be infrequent, when the aura count corresponds to the number of
                                                                 buffers. This is because all FPA buffer frees from PKO (including those
                                                                 created while processing PKO_SEND_GATHER_S, PKO_SEND_LINK_S,
                                                                 PKO_SEND_JUMP_S, or PKO_SEND_FREE_S subdescriptors) are optionally
                                                                 subject to an FPA-automatic aura update which decrements the aura count
                                                                 by one. See the FPA chapter.

                                                                 The aura count change will not occur until after PKO dequeues the PKO SEND
                                                                 descriptor and starts processing it. Otherwise, PKO may create the FPA
                                                                 aura count decrement in any order relative to any aura count update
                                                                 needed to process any other PKO_SEND_AURA_S in this or any other PKO SEND,
                                                                 in any order relative to any PKO FPA frees needed to process this or
                                                                 any other PKO SEND, and in any order relative to any FPA frees/allocates
                                                                 needed for DQ DRAM buffering. The aura count change may occur in
                                                                 any order relative to any L2/DRAM updates or any work queue add
                                                                 needed to process this or any other PKO SEND. */
        uint64_t reserved_12_23        : 12;
        uint64_t aura                  : 16; /**< [ 39: 24] Guest-aura number. The guest-aura to use for subsequent FPA frees in this
                                                                 PKO SEND descriptor and the aura whose aura count may be decremented by
                                                                 this PKO_SEND_AURA_S.

                                                                 For the FPA to not discard the free request, FPA_PF_MAP() must map
                                                                 [AURA] and PKO_PF_VF()_GMCTL[GMID] as valid. */
        uint64_t reserved_40_47        : 8;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_49_59        : 11;
        uint64_t subdc4                : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send aura. Enumerated by PKO_SENDSUBDC_E::AURA. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_64_127       : 64;
#else /* Word 1 - Little Endian */
        uint64_t reserved_64_127       : 64;
#endif /* Word 1 - End */
    } s;
    /* struct bdk_pko_send_aura_s_s cn; */
};

/**
 * Structure pko_send_crc_s
 *
 * PKO Send CRC Subdescriptor Structure
 * The send CRC subdescriptor specifies a CRC calculation be performed during transmission.
 *
 * There may be up to 2 PKO_SEND_CRC_S per packet send descriptor. PKO_SEND_CRC_S constraints:
 * PKO_SEND_CRC_S subdescriptors must precede all PKO_SEND_LINK_S, PKO_SEND_GATHER_S, and
 * PKO_SEND_IMM_S subdescriptors in the packet descriptor.
 *
 * No two PKO_SEND_CRC_S subdescriptors can overlap. Two PKO_SEND_CRC_S would overlap if any
 * bytes are covered by both, or if the checksum calculated for one should be covered by the
 * other.
 *
 * If PKO_SEND_HDR_S[CKL4]=SCTP, PKO_SEND_CRC_S[INSERT] cannot be within SCTP checksum data
 * region.
 * The resulting SCTP checksum would become incorrect in this case.
 *
 * If PKO_SEND_HDR_S[CKL3] is set, the bytes covered or inserted by the CRC must not overlap the
 * IPv4 header bytes (including any options). The IPv4 header bytes (and options) start at byte
 * PKO_SEND_HDR_S[L3PTR] in the packet in this case.
 *
 * If PKO_SEND_HDR_S[CKL4] is nonzero, the bytes covered or inserted by each individual
 * PKO_SEND_CRC_S CRC must entirely reside within the L4 payload. The L4 (TCP/UDP) header
 * starts at byte PKO_SEND_HDR_S[L4PTR] in the packet in this case, and the L4 payload follows
 * the L4 header. In this case, the PKO will appear to calculate the L4 checksum last, after it
 * has completed all PKO_SEND_CRC_S CRCs.
 *
 * If the packet L2 or L3 header is to be marked, the bytes covered or inserted by the
 * PKO_SEND_CRC_S CRC must not overlap any of the relevant L2/L3 header bytes, including all
 * options, extension headers, etc. PKO_SEND_HDR_S[MARKPTR] locates the L2/L3 header in this
 * case. PKO marking is indirectly enabled and further positioned via PKO_SEND_HDR_S[FORMAT]
 * programming.
 *
 * A PKO_SEND_CRC_S must not be present in a descriptor when PKO_SEND_HDR_S[TSO] is set
 * in the descriptor.
 */
union bdk_pko_send_crc_s
{
    uint64_t u[2];
    struct bdk_pko_send_crc_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send CRC. Enumerated by PKO_SENDSUBDC_E::CRC. */
        uint64_t alg                   : 2;  /**< [ 59: 58] Checksum algorithm. See PKO_SENDCRCALG_E. */
        uint64_t reserved_49_57        : 9;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t insert                : 16; /**< [ 47: 32] Byte position relative to the first packet byte at which to insert the first byte of the
                                                                 calculated CRC. PKO does not allocate bytes as it inserts the CRC result into the packet,
                                                                 it overwrites four pre-supplied packet bytes using PKO_SEND_GATHER_S or PKO_SEND_LINK_S or
                                                                 PKO_SEND_IMM_S. The insertion point may not be within the start/size region of another
                                                                 PKO_SEND_CRC_S. */
        uint64_t start                 : 16; /**< [ 31: 16] Byte position relative to the first packet byte at which to start the checksum. */
        uint64_t size                  : 16; /**< [ 15:  0] Length of checksum region, must not be zero. The region is contiguous in packet
                                                                 bytes [START] through [START]+[SIZE]-1. Note that these covered reconstructed
                                                                 bytes need not be contiguous in L2/DRAM -- they can straddle any number of
                                                                 PKO_SEND_GATHER_S, PKO_SEND_LINK_S, or PKO_SEND_IMM_S subdescriptors. */
#else /* Word 0 - Little Endian */
        uint64_t size                  : 16; /**< [ 15:  0] Length of checksum region, must not be zero. The region is contiguous in packet
                                                                 bytes [START] through [START]+[SIZE]-1. Note that these covered reconstructed
                                                                 bytes need not be contiguous in L2/DRAM -- they can straddle any number of
                                                                 PKO_SEND_GATHER_S, PKO_SEND_LINK_S, or PKO_SEND_IMM_S subdescriptors. */
        uint64_t start                 : 16; /**< [ 31: 16] Byte position relative to the first packet byte at which to start the checksum. */
        uint64_t insert                : 16; /**< [ 47: 32] Byte position relative to the first packet byte at which to insert the first byte of the
                                                                 calculated CRC. PKO does not allocate bytes as it inserts the CRC result into the packet,
                                                                 it overwrites four pre-supplied packet bytes using PKO_SEND_GATHER_S or PKO_SEND_LINK_S or
                                                                 PKO_SEND_IMM_S. The insertion point may not be within the start/size region of another
                                                                 PKO_SEND_CRC_S. */
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_49_57        : 9;
        uint64_t alg                   : 2;  /**< [ 59: 58] Checksum algorithm. See PKO_SENDCRCALG_E. */
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send CRC. Enumerated by PKO_SENDSUBDC_E::CRC. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_96_127       : 32;
        uint64_t iv                    : 32; /**< [ 95: 64] Initial value of the checksum. */
#else /* Word 1 - Little Endian */
        uint64_t iv                    : 32; /**< [ 95: 64] Initial value of the checksum. */
        uint64_t reserved_96_127       : 32;
#endif /* Word 1 - End */
    } s;
    /* struct bdk_pko_send_crc_s_s cn; */
};

/**
 * Structure pko_send_free_s
 *
 * PKO Send Free Subdescriptor Structure
 * The send free subdescriptor requests a buffer be freed to FPA. PKO_SEND_FREE_S subdescriptors
 * must follow all PKO_SEND_LINK_S, PKO_SEND_GATHER_S, PKO_SEND_IMM_S, and
 * PKO_SEND_CRC_S subdescriptors in the packet descriptor. PKO will not initiate the free for
 * this subdescriptor until after it has completed all L2/DRAM fetches that service all prior
 * PKO_SEND_LINK_S and PKO_SEND_GATHER_S subdescriptors.
 */
union bdk_pko_send_free_s
{
    uint64_t u[2];
    struct bdk_pko_send_free_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send free. Enumerated by PKO_SENDSUBDC_E::FREE. */
        uint64_t reserved_49_59        : 11;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_40_47        : 8;
        uint64_t aura                  : 16; /**< [ 39: 24] Aura number. The aura to use FPA frees. */
        uint64_t reserved_0_23         : 24;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_23         : 24;
        uint64_t aura                  : 16; /**< [ 39: 24] Aura number. The aura to use FPA frees. */
        uint64_t reserved_40_47        : 8;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_49_59        : 11;
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send free. Enumerated by PKO_SENDSUBDC_E::FREE. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t addr                  : 64; /**< [127: 64] The IOVA L2/DRAM address within the buffer to be freed. [ADDR] must be
                                                                 naturally-aligned to 128 bytes.

                                                                 PKO sends [ADDR] to FPA as part of the buffer free. Either an FPA naturally-aligned
                                                                 pool or opaque pool may be appropriate. Refer to the FPA chapter.

                                                                 PKO frees the buffer to PKO_SEND_FREE_S[AURA].

                                                                 PKO will not free [ADDR] to FPA until after it has completed all
                                                                 L2/DRAM reads related to processing any PKO_SEND_GATHER_S and
                                                                 any PKO_SEND_LINK_S in the descriptor.
                                                                 Provided the path of meta descriptors from the DQ through PKO to an output FIFO is
                                                                 unmodified between the meta descriptors (as should normally be the case, but it is
                                                                 possible for software to change the path), PKO also will not free
                                                                 [ADDR] to FPA until after it has completed all L2/DRAM reads related
                                                                 to processing any PKO_SEND_GATHER_S and any PKO_SEND_LINK_S in any
                                                                 meta descriptor enqueued earlier in the same DQ. PKO may free [ADDR] in
                                                                 any order with respect to any processing of any descriptor that is
                                                                 in a different DQ. PKO may create the FPA
                                                                 free for [ADDR] in any order relative to any other PKO FPA
                                                                 frees needed to process this or any other PKO SEND descriptor,
                                                                 and in any order relative to any FPA frees/allocates needed for DQ DRAM
                                                                 buffering, and in any order relative to any FPA aura count
                                                                 updates needed to process a PKO_SEND_AURA_S subdescriptor in this
                                                                 or any other PKO SEND. The FPA free may occur in any order relative to any
                                                                 L2/DRAM updates or any work queue add needed to process this or
                                                                 any other PKO SEND.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO
                                                                 frees the buffer only once for the descriptor, not once per TSO segment.
                                                                 Software must not modify the path of meta descriptors from the DQ through
                                                                 PKO to an output FIFO between TSO segments. */
#else /* Word 1 - Little Endian */
        uint64_t addr                  : 64; /**< [127: 64] The IOVA L2/DRAM address within the buffer to be freed. [ADDR] must be
                                                                 naturally-aligned to 128 bytes.

                                                                 PKO sends [ADDR] to FPA as part of the buffer free. Either an FPA naturally-aligned
                                                                 pool or opaque pool may be appropriate. Refer to the FPA chapter.

                                                                 PKO frees the buffer to PKO_SEND_FREE_S[AURA].

                                                                 PKO will not free [ADDR] to FPA until after it has completed all
                                                                 L2/DRAM reads related to processing any PKO_SEND_GATHER_S and
                                                                 any PKO_SEND_LINK_S in the descriptor.
                                                                 Provided the path of meta descriptors from the DQ through PKO to an output FIFO is
                                                                 unmodified between the meta descriptors (as should normally be the case, but it is
                                                                 possible for software to change the path), PKO also will not free
                                                                 [ADDR] to FPA until after it has completed all L2/DRAM reads related
                                                                 to processing any PKO_SEND_GATHER_S and any PKO_SEND_LINK_S in any
                                                                 meta descriptor enqueued earlier in the same DQ. PKO may free [ADDR] in
                                                                 any order with respect to any processing of any descriptor that is
                                                                 in a different DQ. PKO may create the FPA
                                                                 free for [ADDR] in any order relative to any other PKO FPA
                                                                 frees needed to process this or any other PKO SEND descriptor,
                                                                 and in any order relative to any FPA frees/allocates needed for DQ DRAM
                                                                 buffering, and in any order relative to any FPA aura count
                                                                 updates needed to process a PKO_SEND_AURA_S subdescriptor in this
                                                                 or any other PKO SEND. The FPA free may occur in any order relative to any
                                                                 L2/DRAM updates or any work queue add needed to process this or
                                                                 any other PKO SEND.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO
                                                                 frees the buffer only once for the descriptor, not once per TSO segment.
                                                                 Software must not modify the path of meta descriptors from the DQ through
                                                                 PKO to an output FIFO between TSO segments. */
#endif /* Word 1 - End */
    } s;
    /* struct bdk_pko_send_free_s_s cn; */
};

/**
 * Structure pko_send_gather_s
 *
 * PKO Send Gather Subdescriptor Structure
 * The send gather subdescriptor requests a contiguous segment of bytes be transmitted.
 *
 * There may be multiple PKO_SEND_GATHER_S's in each PKO SEND descriptor. A
 * PKO_SEND_GATHER_S must not be present in a PKO SEND descriptor if the sum of all prior
 * PKO_SEND_GATHER_S[SIZE]s and PKO_SEND_IMM_S[SIZE]s meets or exceeds PKO_SEND_HDR_S[TOTAL].
 * (i.e. Some of the packet data from a PKO_SEND_GATHER_S must be used.) A
 * PKO_SEND_GATHER_S must not be present after a PKO_SEND_LINK_S in a PKO SEND descriptor.
 */
union bdk_pko_send_gather_s
{
    uint64_t u[2];
    struct bdk_pko_send_gather_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send gather. Enumerated by PKO_SENDSUBDC_E::GATHER0. */
        uint64_t ld_type               : 2;  /**< [ 59: 58] Specifies load transaction type to use for reading segment bytes. Enumerated by
                                                                 NIC_SEND_LD_TYPE_E. */
        uint64_t i                     : 1;  /**< [ 57: 57] Invert free. See PKO_SEND_HDR_S[DF,II].

                                                                 PKO frees the surrounding buffer when:

                                                                 _  PKO_SEND_HDR_S[DF] XOR ([I] AND NOT PKO_SEND_HDR_S[II]) = 0.

                                                                 PKO naturally aligns [ADDR] to 128 bytes before sending it to FPA as part of
                                                                 the buffer free. An FPA naturally-aligned pool is recommended, though opaque
                                                                 pool mode may also be possible. Refer to the FPA chapter.

                                                                 PKO frees the buffer to [AURA].

                                                                 PKO will not free [ADDR] to FPA until after it has finished reading
                                                                 this segment (and the PKI_BUFLINK_S that precedes this segment in
                                                                 the buffer, if necessary) from the buffer.
                                                                 Provided the path of meta descriptors from the DQ through PKO to an output FIFO is
                                                                 unmodified between the meta descriptors (as should normally be the case, but it is
                                                                 possible for software to change the path), PKO also will not free
                                                                 [ADDR] to FPA until after it has completed all L2/DRAM reads related
                                                                 to processing any PKO_SEND_GATHER_S and any PKO_SEND_LINK_S in any
                                                                 descriptor enqueued earlier in the same DQ. PKO may free [ADDR] in
                                                                 any order with respect to any processing of any descriptor that is
                                                                 in a different DQ. PKO may create the FPA
                                                                 free for [ADDR] in any order relative to any other PKO FPA
                                                                 frees needed to process this or any other PKO SEND descriptor,
                                                                 and in any order relative to any FPA frees/allocates needed for DQ DRAM
                                                                 buffering, and in any order relative to any FPA aura count
                                                                 updates needed to process a PKO_SEND_AURA_S subdescriptor in this
                                                                 or any other PKO SEND. The FPA free may occur in any order relative to any
                                                                 L2/DRAM updates or any work queue add needed to process this or
                                                                 any other PKO SEND.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO
                                                                 frees the surrounding buffer only once for the descriptor,
                                                                 not once per TSO segment.
                                                                 Software must not modify the path of meta descriptors from the DQ through
                                                                 PKO to an output FIFO between TSO segments. */
        uint64_t reserved_49_56        : 8;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_40_47        : 8;
        uint64_t aura                  : 16; /**< [ 39: 24] see PKO_SEND_FREE_S[AURA] */
        uint64_t reserved_16_23        : 8;
        uint64_t size                  : 16; /**< [ 15:  0] Size of segment, in bytes. [SIZE] must be nonzero.

                                                                 Let priorbytes = the sum of all prior PKO_SEND_GATHER_S[SIZE]s and
                                                                 PKO_SEND_IMM_S[SIZE]s in this descriptor. This PKO_SEND_GATHER_S
                                                                 must not be present in the descriptor when
                                                                 priorbytes >= PKO_SEND_HDR_S[TOTAL].

                                                                 The number of bytes used from this PKO_SEND_GATHER_S segment is:

                                                                 _    min(PKO_SEND_HDR_S[TOTAL]-priorbytes, [SIZE])

                                                                 It is legal for [SIZE] to exceed PKO_SEND_HDR_S[TOTAL]-priorbytes, but only when
                                                                 there is no subsequent PKO_SEND_GATHER_S, PKO_SEND_IMM_S, nor PKO_SEND_LINK_S
                                                                 in the descriptor.

                                                                 The sum of any PKO_SEND_IMM_S[SIZE]s, PKO_SEND_GATHER_S[SIZE]s, and
                                                                 PKO_SEND_LINK_S[SIZE]s in the descriptor plus any PKI_BUFLINK_S[SIZE]
                                                                 linked by any PKO_SEND_LINK_S must equal or exceed PKO_SEND_HDR_S[TOTAL]. */
#else /* Word 0 - Little Endian */
        uint64_t size                  : 16; /**< [ 15:  0] Size of segment, in bytes. [SIZE] must be nonzero.

                                                                 Let priorbytes = the sum of all prior PKO_SEND_GATHER_S[SIZE]s and
                                                                 PKO_SEND_IMM_S[SIZE]s in this descriptor. This PKO_SEND_GATHER_S
                                                                 must not be present in the descriptor when
                                                                 priorbytes >= PKO_SEND_HDR_S[TOTAL].

                                                                 The number of bytes used from this PKO_SEND_GATHER_S segment is:

                                                                 _    min(PKO_SEND_HDR_S[TOTAL]-priorbytes, [SIZE])

                                                                 It is legal for [SIZE] to exceed PKO_SEND_HDR_S[TOTAL]-priorbytes, but only when
                                                                 there is no subsequent PKO_SEND_GATHER_S, PKO_SEND_IMM_S, nor PKO_SEND_LINK_S
                                                                 in the descriptor.

                                                                 The sum of any PKO_SEND_IMM_S[SIZE]s, PKO_SEND_GATHER_S[SIZE]s, and
                                                                 PKO_SEND_LINK_S[SIZE]s in the descriptor plus any PKI_BUFLINK_S[SIZE]
                                                                 linked by any PKO_SEND_LINK_S must equal or exceed PKO_SEND_HDR_S[TOTAL]. */
        uint64_t reserved_16_23        : 8;
        uint64_t aura                  : 16; /**< [ 39: 24] see PKO_SEND_FREE_S[AURA] */
        uint64_t reserved_40_47        : 8;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_49_56        : 8;
        uint64_t i                     : 1;  /**< [ 57: 57] Invert free. See PKO_SEND_HDR_S[DF,II].

                                                                 PKO frees the surrounding buffer when:

                                                                 _  PKO_SEND_HDR_S[DF] XOR ([I] AND NOT PKO_SEND_HDR_S[II]) = 0.

                                                                 PKO naturally aligns [ADDR] to 128 bytes before sending it to FPA as part of
                                                                 the buffer free. An FPA naturally-aligned pool is recommended, though opaque
                                                                 pool mode may also be possible. Refer to the FPA chapter.

                                                                 PKO frees the buffer to [AURA].

                                                                 PKO will not free [ADDR] to FPA until after it has finished reading
                                                                 this segment (and the PKI_BUFLINK_S that precedes this segment in
                                                                 the buffer, if necessary) from the buffer.
                                                                 Provided the path of meta descriptors from the DQ through PKO to an output FIFO is
                                                                 unmodified between the meta descriptors (as should normally be the case, but it is
                                                                 possible for software to change the path), PKO also will not free
                                                                 [ADDR] to FPA until after it has completed all L2/DRAM reads related
                                                                 to processing any PKO_SEND_GATHER_S and any PKO_SEND_LINK_S in any
                                                                 descriptor enqueued earlier in the same DQ. PKO may free [ADDR] in
                                                                 any order with respect to any processing of any descriptor that is
                                                                 in a different DQ. PKO may create the FPA
                                                                 free for [ADDR] in any order relative to any other PKO FPA
                                                                 frees needed to process this or any other PKO SEND descriptor,
                                                                 and in any order relative to any FPA frees/allocates needed for DQ DRAM
                                                                 buffering, and in any order relative to any FPA aura count
                                                                 updates needed to process a PKO_SEND_AURA_S subdescriptor in this
                                                                 or any other PKO SEND. The FPA free may occur in any order relative to any
                                                                 L2/DRAM updates or any work queue add needed to process this or
                                                                 any other PKO SEND.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO
                                                                 frees the surrounding buffer only once for the descriptor,
                                                                 not once per TSO segment.
                                                                 Software must not modify the path of meta descriptors from the DQ through
                                                                 PKO to an output FIFO between TSO segments. */
        uint64_t ld_type               : 2;  /**< [ 59: 58] Specifies load transaction type to use for reading segment bytes. Enumerated by
                                                                 NIC_SEND_LD_TYPE_E. */
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send gather. Enumerated by PKO_SENDSUBDC_E::GATHER0. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t addr                  : 64; /**< [127: 64] ADDR is an IOVA L2/DRAM address of the first byte of packet data in the
                                                                 segment.

                                                                 The packet data pointed to is byte-invariant and endian settings do not matter. */
#else /* Word 1 - Little Endian */
        uint64_t addr                  : 64; /**< [127: 64] ADDR is an IOVA L2/DRAM address of the first byte of packet data in the
                                                                 segment.

                                                                 The packet data pointed to is byte-invariant and endian settings do not matter. */
#endif /* Word 1 - End */
    } s;
    /* struct bdk_pko_send_gather_s_s cn; */
};

/**
 * Structure pko_send_hdr_s
 *
 * PKO Send Header Subdescriptor Structure
 * The send header is the first subdescriptor word of every send operation.
 */
union bdk_pko_send_hdr_s
{
    uint64_t u[2];
    struct bdk_pko_send_hdr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t scntm1                : 3;  /**< [ 63: 61] Sub-descriptor count. PKO packs the send operation's number of sub-descriptors
                                                                 (minus one) here.  Software should not modify this. */
        uint64_t n2                    : 1;  /**< [ 60: 60] No L2 allocate. When clear, PKO allocates all packet load data into the L2 cache.
                                                                 When set, PKO does not allocate blocks containing segment bytes into the L2 cache.
                                                                 [N2] affects performance, but otherwise does not affect CNXXXX behavior. It may be
                                                                 advantageous to set [N2] if packet data will not be used after PKO sends the packet, which
                                                                 will allow the L2 cache to retain other more useful information.

                                                                 When allocating, PKO reads packet data with LDD transactions. When not allocating,
                                                                 PKO reads packet data with LDWB (when freeing the buffer surrounding the
                                                                 segment) or LDT (when not freeing the buffer surrounding the segment)
                                                                 transactions.

                                                                 Note that PKO_PDM_CFG[ALLOC_LDS] selects L2 cache allocation for any DQ descriptor/meta
                                                                 reads, and PKO_PTF_IOBP_CFG[IOBP0_L2_ALLOCATE] determines L2 cache allocation for
                                                                 any post-PKO_SEND_JUMP_S descriptor reads. Also, PKO always allocates packet data
                                                                 into the L2 cache on the first-pass packet read of a two-pass TCP/UDP checksum
                                                                 calculation, and may allocate portions of packet data into the L2 cache when
                                                                 PKO_SEND_HDR_S[TSO]==1. */
        uint64_t tso                   : 1;  /**< [ 59: 59] If set, segment a larger TCP source packet into
                                                                 multiple smaller TSO segment output packets. Software creates a single
                                                                 descriptor describing the source packet and including the PKO_SEND_HDR_S[TSO]=1,
                                                                 and PKO automatically outputs the resultant TSO segmented packets.

                                                                 For each produced segment, PKO duplicates the PKO SEND descriptor in the DQ
                                                                 and creates an independent meta descriptor (PKO_META_DESC_S and PKO_*_PICK)
                                                                 for scheduling, conditioning, and transmission. PKO duplicates/creates
                                                                 the L2, IP, and TCP headers from the source packet into the TSO segments,
                                                                 and distributes the source packet TCP payload bytes across the TSO
                                                                 segments. All the produced TSO segments will be sent out the MAC/interface in
                                                                 order, but PKO schedules each segment independently, so PKO can
                                                                 transmit packets from other DQ's between the TSO segments produced
                                                                 from the descriptor.

                                                                 <page>

                                                                 PKO simply copies most L2, IP, and TCP header fields from the source
                                                                 packet to the TSO segments. PKO modifies the following pre-segmented
                                                                 source packet fields in each produced TSO segment:

                                                                 * If PKO considers the L2 type/length field to be a length (see [L2LEN] below):
                                                                    o PKO sets the L2 length field to (FPS + [SB] - ([L2LEN] + 2)).

                                                                 * In the IPv4 case:
                                                                    o PKO sets IPv4.totallength to (FPS + [SB] - PKO_SEND_HDR_S[L3PTR]).
                                                                    o PKO calculates and inserts the IP checksum.
                                                                    o PKO increments the IP Identification field from the last segment
                                                                      by one. The IP Identification field in the first produced segment
                                                                      is unmodified from the pre-segmented source packet.

                                                                 * In the IPv6 case:
                                                                    o PKO sets IPv6.payloadlength to (FPS + [SB] - PKO_SEND_HDR_S[L3PTR] - 40).

                                                                 * PKO produces the TCP sequence number by adding the FPS from the prior
                                                                   segment to the TCP sequence number used in the prior segment.
                                                                   The TCP sequence number in the first produced segment is unmodified
                                                                   from the pre-segmented source packet.

                                                                 * PKO produces the TCP flags by logical-anding
                                                                   PKO_PEB_TSO_CFG[FSF, MSF, or LSF] with the pre-segmented source TCP flags -
                                                                   FSF is used for the first segment, MSF for the middle segments, and
                                                                   LSF for the last segment.

                                                                 Where FPS is the payload bytes in the TSO segment. For all but the last segment,
                                                                 FPS equals ([MSS]-[SB]). In the last segment, 0 < FPS <= ([MSS]-[SB]). The
                                                                 aggregate payload bytes in all produced segments is PKO_SEND_HDR_S[TOTAL]-[SB].

                                                                 <page>

                                                                 The meta-packet for each produced segment is the same as the meta-packet
                                                                 that would be produced for the pre-segmented source packet, with the
                                                                 following exceptions:

                                                                 * PKO_META_DESC_S[LENGTH] / PKO_*_PICK[LENGTH] for each TSO segment is
                                                                       (PKO_PDM_DQ*_MINPAD[MINPAD] ?
                                                                           MAX(PKO_PDM_CFG[PKO_PAD_MINLEN], (FPS+[SB])) :
                                                                           (FPS+[SB]))

                                                                 * PKO_META_DESC_S[FPD] / PKO_*_PICK[FPD] is independently calculated
                                                                   for each descriptor copy.

                                                                 <page>

                                                                 The following are constraints when PKO_SEND_HDR_S[TSO] is set
                                                                 in a descriptor:

                                                                 * 576 <= [MSS] < PKO_SEND_HDR_S[TOTAL] <= (128*[MSS] - 127*[SB])

                                                                 * PKO_SEND_HDR_S[CKL4] = TCP

                                                                 * PKO_SEND_HDR_S[L3PTR] must point to the first byte in the one and only IP header
                                                                   o IP tunneled packets are not supported with TSO.

                                                                 * PKO_SEND_HDR_S[L4PTR] must point to the first byte in the corresponding TCP header

                                                                 * In the IPv4 case:
                                                                    o PKO_SEND_HDR_S[TOTAL] = PKO_SEND_HDR_S[L3PTR]+(IPv4.totallength)
                                                                    o PKO_SEND_HDR_S[CKL3] = 1

                                                                 * In the IPv6 case:
                                                                    o PKO_SEND_HDR_S[TOTAL] = PKO_SEND_HDR_S[L3PTR]+40+(IPv6.payloadlength)
                                                                    o PKO_SEND_HDR_S[CKL3] = 0

                                                                 * If PKO considers the L2 type/length field to be a length (see [L2LEN] below):
                                                                    o [MSS] < 0x600
                                                                    o PKO_SEND_HDR_S[L3PTR] = [L2LEN] + 10 (likely, if not required)

                                                                 * else if PKO does not consider the L2 type/length field to be a length:
                                                                    o PKO_SEND_HDR_S[L3PTR] = [L2LEN] + 2

                                                                 * If any PKO_SEND_IMM_S's are present in the descriptor, they must never
                                                                   provide source packet bytes after the first [SB] bytes in the source packet.

                                                                 * PKO_MAC()_CFG[MIN_PAD_ENA] and PKO_PDM_CFG[PKO_PAD_MINLEN] must be set
                                                                   appropriately if minimum pad is required by the interface/MAC.
                                                                   PKO_PDM_DQ*_MINPAD[MINPAD] should normally also be set when minimum
                                                                   pad is required by the interface/MAC.

                                                                 * PKO_MAC()_CFG[FCS_ENA] should normally be set if the interface/MAC requires
                                                                   FCS. But an alternative is to enable FCS in the MAC in the cases when
                                                                   the MAC supports FCS generation.

                                                                 Hardware performance may be less optimal when a PKO_SEND_LINK_S is present in
                                                                 the descriptor with many links. PKO_SEND_GATHER_S usage is recommended
                                                                 with TSO. */
        uint64_t df                    : 1;  /**< [ 58: 58] Don't free. If set, by default PKO will not free the surrounding buffer after
                                                                 processing a packet segment. If clear, by default PKO will free the
                                                                 surrounding buffer after processing a packet segment.

                                                                 If [II] is set, [DF] controls whether PKO frees the surrounding buffer
                                                                 after processing a packet segment. If [II] is clear,
                                                                 PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[I] can invert the default
                                                                 behavior selected by [DF].

                                                                 PKO frees the buffer surrounding a PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S
                                                                 segment when:

                                                                 _   [DF] XOR (NOT [II] AND PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[I]) = 0.

                                                                 PKO naturally aligns PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR]
                                                                 to 128 bytes before sending it to FPA as part of the buffer free. An FPA
                                                                 naturally-aligned pool is recommended, though opaque pool mode may also
                                                                 be possible. Refer to the FPA chapter.

                                                                 PKO frees the buffer to the [AURA] contained in the descriptor (GATHER/LINK/JUMP/FREE).

                                                                 <page>

                                                                 PKO will not free PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR]
                                                                 to FPA until after it has finished reading the segment (and its preceding
                                                                 PKI_BUFLINK_S, if necessary) from the buffer.
                                                                 Provided the path of meta descriptors from the DQ through PKO to an output FIFO is
                                                                 unmodified between the meta descriptors (as should normally be the case, but it is
                                                                 possible for software to change the path), PKO also will not free
                                                                 PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR] to FPA
                                                                 until after it has completed all L2/DRAM reads related
                                                                 to processing any PKO_SEND_GATHER_S and any PKO_SEND_LINK_S in any
                                                                 descriptor enqueued earlier in the same DQ. PKO may free
                                                                 PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR] in
                                                                 any order with respect to any processing of any descriptor that is
                                                                 in a different DQ. PKO may create the FPA
                                                                 frees needed to process a PKO_SEND_GATHER_S or PKO_SEND_LINK_S subdescriptor
                                                                 in any order relative to any other PKO FPA frees needed to process
                                                                 this or any other PKO SEND descriptor, and in any order relative to
                                                                 any FPA frees/allocates needed for DQ DRAM buffering, and in any order
                                                                 relative any FPA aura count updates needed to process a PKO_SEND_AURA_S
                                                                 subdescriptor in this or any other PKO SEND. The FPA free may occur in any
                                                                 order relative to any L2/DRAM updates or any work queue add needed to
                                                                 process this or any other PKO SEND.

                                                                 Note that [DF] has no effect on any buffer frees from a PKO_SEND_FREE_S or
                                                                 PKO_SEND_JUMP_S.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO
                                                                 frees the surrounding buffer only once for the descriptor,
                                                                 not once per TSO segment.
                                                                 Software must not modify the path of meta descriptors from the DQ through
                                                                 PKO to an output FIFO between TSO segments. */
        uint64_t tso_eom               : 1;  /**< [ 57: 57] Reserved. Must be zero.
                                                                 Internal:
                                                                 End of message. PKO sets [EOM] in the last replicated packet descriptor. */
        uint64_t tstmp                 : 1;  /**< [ 56: 56] PTP timestamp. If set, a later PKO_SEND_MEM_S will be present in this descriptor with
                                                                 PKO_SEND_MEM_S[ALG] set to TSTMP to request IEEE 1588 PTP time-stamping. Furthermore, if
                                                                 set, [RA] must be PKO_REDALG_E::SEND.

                                                                 [TSTMP] must not be set when PKO_SEND_HDR_S[TSO] is set in the descriptor. */
        uint64_t format                : 7;  /**< [ 55: 49] Selects a CSR from the PKO_FORMAT()_CTL array which specifies
                                                                 how PKO will mark YELLOW and RED_SEND packets. [FORMAT] must
                                                                 be less than the size of the PKO_FORMAT()_CTL array.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO marks each TSO segment
                                                                 independently, using [FORMAT] for every TSO segment. */
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t ckl4                  : 2;  /**< [ 47: 46] Checksum L4, enumerated by PKO_CKL4ALG_E. If nonzero (not NONE):

                                                                 * PKO hardware calculates the Layer 4 TCP/UDP/SCTP checksum for the packet and inserts it
                                                                 into the packet, as described in Send CRC.

                                                                 * [L4PTR] selects the first byte of the L4 header, and [L3PTR] must indicate the location
                                                                 of the immediately proceeding and adjacent L3 header.

                                                                 * The L4 length field must not require more than [TOTAL] bytes in the packet and the L4
                                                                 length must be nonzero.

                                                                 * When PKO_SEND_CRC_S are present, the bytes covered or inserted by PKO_SEND_CRC_S must
                                                                 all reside in the L4 payload. Conceptually, PKO processes PKO_SEND_CRC_S before L4
                                                                 checksums when both are present.

                                                                 * When PKO_SEND_HDR_S[TSO] is set, [CKL4] must be TCP */
        uint64_t ckl3                  : 1;  /**< [ 45: 45] Checksum L3. If set, PKO hardware calculates the IPv4 header checksum and inserts it into
                                                                 the packet, as described in L4 checksum. When set, [L3PTR] selects the location of the
                                                                 first byte of the L3 header and no L3 header bytes selected by [L3PTR] can overlap with
                                                                 any bytes covered or inserted by PKO_SEND_CRC_S CRCs. When [CKL3] is set, [L3PTR] must
                                                                 point to a valid IPv4 header. When PKO_SEND_HDR_S[TSO] is set with an IPv4 packet,
                                                                 [CKL3] must be set. [CKL3] must never be set with an IPv6 packet. */
        uint64_t cklf                  : 2;  /**< [ 44: 43] Inner checksum L4, enumerated by PKO_CKL4ALG_E. Similar to [CKL4] but for inner L4. */
        uint64_t ckle                  : 1;  /**< [ 42: 42] Inner checksum L3. Similar to [CKL3] but for inner IP. */
        uint64_t shp_dis               : 1;  /**< [ 41: 41] Disables shaping for this packet.  Selects the shaper update and internal
                                                                 coloring algorithms used as the packet traverses enabled PKO DQ through
                                                                 L2 shapers. [SHP_DIS] has no effect on the L1 rate limiters. See
                                                                 PKO_META_DESC_S[COL], PKO_*_PICK[PIR_DIS,CIR_DIS] and PKO_COLORALG_E.
                                                                 When [SHP_DIS] is 1, PKO_META_DESC_S[COL] is set to NO_COLOR and
                                                                 both PKO_*_PICK[PIR_DIS,CIR_DIS] are asserted.  When [SHP_DIS] is 0
                                                                 PKO_*_SHAPE[YELLOW_DISABLE,RED_DISABLE] determine the packet
                                                                 coloring of the shaper.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO applies [SHP_DIS]
                                                                 to each TSO segment - PKO sets each PKO_META_DESC_S[COL]
                                                                 and PKO_nm_PICK[PIR_DIS,CIR_DIS] as described above. */
        uint64_t ii                    : 1;  /**< [ 40: 40] Ignore I. If set, ignore all PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[I] bits
                                                                 (effectively, force them all to zero) for the entire PKO SEND descriptor.

                                                                 If [II] is set, [DF] controls whether PKO frees the surrounding buffer
                                                                 after processing a packet segment. If [II] is clear,
                                                                 PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[I] can invert the default
                                                                 behavior selected by [DF].

                                                                 PKO frees the buffer surrounding a PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S
                                                                 segment when:

                                                                 _   [DF] XOR (NOT [II] AND PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[I]) = 0.

                                                                 PKO naturally aligns PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR] to
                                                                 128 bytes before sending it to FPA as part of the buffer free. An FPA
                                                                 naturally-aligned pool is recommended, though opaque pool mode may also be
                                                                 possible. Refer to the FPA chapter.

                                                                 PKO frees the buffer to the [AURA] contained in the descriptor (GATHER, LINK,
                                                                 JUMP, FREE)

                                                                 <page>

                                                                 PKO will not free PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR]
                                                                 to FPA until after it has finished reading the segment (and its preceding
                                                                 PKI_BUFLINK_S, if necessary) from the buffer.
                                                                 Provided the path of meta descriptors from the DQ through PKO to an output FIFO is
                                                                 unmodified between the meta descriptors (as should normally be the case, but it is
                                                                 possible for software to change the path), PKO also will not free
                                                                 PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR] to FPA
                                                                 until after it has completed all L2/DRAM reads related
                                                                 to processing any PKO_SEND_GATHER_S and any PKO_SEND_LINK_S in any
                                                                 descriptor enqueued earlier in the same DQ. PKO may free
                                                                 PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR] in
                                                                 any order with respect to any processing of any descriptor that is
                                                                 in a different DQ. PKO may create the FPA
                                                                 frees needed to process a PKO_SEND_GATHER_S or PKO_SEND_LINK_S subdescriptor
                                                                 in any order relative to any other PKO FPA frees needed to process
                                                                 this or any other PKO SEND descriptor, and in any order relative to
                                                                 any FPA frees/allocates needed for DQ DRAM buffering, and in any order
                                                                 relative any FPA aura count updates needed to process a PKO_SEND_AURA_S
                                                                 subdescriptor in this or any other PKO SEND.
                                                                 The FPA free may also occur in any order relative to any
                                                                 L2/DRAM updates or any work queue add needed to process this or
                                                                 any other PKO SEND. The FPA free may occur in any order relative to any
                                                                 L2/DRAM updates or any work queue add needed to process this or
                                                                 any other PKO SEND.

                                                                 <page>

                                                                 Note that [DF] has no effect on any buffer frees from a PKO_SEND_FREE_S or
                                                                 PKO_SEND_JUMP_S.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO
                                                                 frees the surrounding buffer only once for the descriptor,
                                                                 not once per TSO segment.
                                                                 Software must not modify the path of meta descriptors from the DQ through
                                                                 PKO to an output FIFO between TSO segments. */
        uint64_t l4ptr                 : 8;  /**< [ 39: 32] Layer 4 offset. Specifies the location of the first byte of the TCP/UDP/SCTP header for L4
                                                                 checksumming (layer checksumming) or shaper marking. The Layer 4 header must
                                                                 be exactly [L4PTR] bytes from the beginning of the packet. Software might populate this
                                                                 field for forwarded packets from a computation based off WQE[L4PTR], which is the IP
                                                                 location computed by PKI when the packet is parsed. When [CKL4] is nonzero, no L4 header
                                                                 bytes indicated by [L4PTR] can overlap with any bytes covered by or inserted by
                                                                 PKO_SEND_CRC_S CRCs (but the subsequent L4 payload bytes can overlap with the
                                                                 PKO_SEND_CRC_S CRC bytes).

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, [L4PTR] must point to the
                                                                 TCP header, which must be before PKO_SEND_HDR_S[TSO_SB]. */
        uint64_t l3ptr                 : 8;  /**< [ 31: 24] Layer 3 IP offset. Specifies the location of the first byte of the IP packet for L3
                                                                 checksum and/or L4 checksum and/or shaper marking. (See [CKL3,CKL4,FORMAT] and
                                                                 PKO_SEND_HDR_S[MARKPTR].) The IP packet must be exactly [L3PTR] bytes from the beginning
                                                                 of the packet. Software might populate this field for forwarded packets from a computation
                                                                 based off WQE[L3PTR], which is the IP location computed by PKI when the packet is parsed.

                                                                 When PKO_SEND_HDR_S[MARKPTR] is not present in the packet descriptor, [L3PTR] can also
                                                                 indicate the location of an L2 header. When [L3PTR] is used for any of [CKL3,CKL4] or
                                                                 marking calculations/modifications, then no L3 nor L2 header bytes indicated by
                                                                 [L3PTR] can overlap with any bytes covered by or inserted by PKO_SEND_CRC_S CRCs.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, [L3PTR] must point to the
                                                                 IP header, which must be before PKO_SEND_HDR_S[TSO_SB]. */
        uint64_t markptr               : 8;  /**< [ 23: 16] Mark pointer. Offset from packet start to byte to use for packet shaper marking.
                                                                 PKO_SEND_HDR_S[FORMAT] indirectly determines how this offset is used by PKO, including
                                                                 whether and how an L2 or L3 header is marked. [MARKPTR] is constrained as follows:

                                                                 * If either of PKO_SEND_HDR_S[CKL3,CKL4] is nonzero and a packet L3 header will be marked,
                                                                 then either (1.1) [MARKPTR] and PKO_SEND_HDR_S[L3PTR] must be equal and refer to the same
                                                                 L3 header, or (1.2) [MARKPTR] and PKO_SEND_HDR_S[L3PTR] must differ and refer to different
                                                                 non-overlapping L3 headers.

                                                                 * If a packet L2 header will be marked, then the entire L2 header must not overlap with
                                                                 computation enabled by either of PKO_SEND_HDR_S[CKL3,CKL4], and must not overlap with any
                                                                 PKO_SEND_CRC_S CRCs.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO marks each TSO segment
                                                                 independently, using [MARKPTR] for every TSO segment when present. */
        uint64_t total                 : 16; /**< [ 15:  0] The number of bytes that PKO will fetch from memory and immediate subdescriptors
                                                                 to create the outgoing packet. Also the size in bytes of the outgoing packet that
                                                                 PKO creates, excluding zero pad (if any) and outside FCS bytes (if any). Must
                                                                 be greater than 0 and not exceed 2^16 - 8 bytes (65528 bytes). PKO or an interface may
                                                                 append outside FCS to a packet. PKO appends outside FCS to the packet when
                                                                 PKO_MAC()_CFG[FCS_ENA] is set, and zero pads (when necessary, to force the pre-outside-FCS
                                                                 packet to be at least PKO_PDM_CFG[PKO_PAD_MINLEN] bytes) when PKO_MAC()_CFG[MIN_PAD_ENA]
                                                                 is set, where m is the MAC that the packet uses.

                                                                 The sum of all PKO_SEND_IMM_S[SIZE], PKO_SEND_GATHER_S[SIZE], and
                                                                 PKO_SEND_LINK_S[SIZE] in the descriptor plus any PKI_BUFLINK_S[SIZE]
                                                                 linked by any PKO_SEND_LINK_S must equal or exceed [TOTAL].

                                                                 [TOTAL] constraints when PKO_SEND_HDR_S[TSO] is set:
                                                                 * For IPv4: [TOTAL] = [L3PTR]+(IPv4.total length).
                                                                 * For IPv6: [TOTAL] = [L3PTR]+40+(IPv6.payload length).
                                                                 * 576 <= PKO_SEND_HDR_S[TSO_MSS] < [TOTAL] <=
                                                                 (128*PKO_SEND_HDR_S[TSO_MSS]-127*PKO_SEND_HDR_S[TSO_SB]). */
#else /* Word 0 - Little Endian */
        uint64_t total                 : 16; /**< [ 15:  0] The number of bytes that PKO will fetch from memory and immediate subdescriptors
                                                                 to create the outgoing packet. Also the size in bytes of the outgoing packet that
                                                                 PKO creates, excluding zero pad (if any) and outside FCS bytes (if any). Must
                                                                 be greater than 0 and not exceed 2^16 - 8 bytes (65528 bytes). PKO or an interface may
                                                                 append outside FCS to a packet. PKO appends outside FCS to the packet when
                                                                 PKO_MAC()_CFG[FCS_ENA] is set, and zero pads (when necessary, to force the pre-outside-FCS
                                                                 packet to be at least PKO_PDM_CFG[PKO_PAD_MINLEN] bytes) when PKO_MAC()_CFG[MIN_PAD_ENA]
                                                                 is set, where m is the MAC that the packet uses.

                                                                 The sum of all PKO_SEND_IMM_S[SIZE], PKO_SEND_GATHER_S[SIZE], and
                                                                 PKO_SEND_LINK_S[SIZE] in the descriptor plus any PKI_BUFLINK_S[SIZE]
                                                                 linked by any PKO_SEND_LINK_S must equal or exceed [TOTAL].

                                                                 [TOTAL] constraints when PKO_SEND_HDR_S[TSO] is set:
                                                                 * For IPv4: [TOTAL] = [L3PTR]+(IPv4.total length).
                                                                 * For IPv6: [TOTAL] = [L3PTR]+40+(IPv6.payload length).
                                                                 * 576 <= PKO_SEND_HDR_S[TSO_MSS] < [TOTAL] <=
                                                                 (128*PKO_SEND_HDR_S[TSO_MSS]-127*PKO_SEND_HDR_S[TSO_SB]). */
        uint64_t markptr               : 8;  /**< [ 23: 16] Mark pointer. Offset from packet start to byte to use for packet shaper marking.
                                                                 PKO_SEND_HDR_S[FORMAT] indirectly determines how this offset is used by PKO, including
                                                                 whether and how an L2 or L3 header is marked. [MARKPTR] is constrained as follows:

                                                                 * If either of PKO_SEND_HDR_S[CKL3,CKL4] is nonzero and a packet L3 header will be marked,
                                                                 then either (1.1) [MARKPTR] and PKO_SEND_HDR_S[L3PTR] must be equal and refer to the same
                                                                 L3 header, or (1.2) [MARKPTR] and PKO_SEND_HDR_S[L3PTR] must differ and refer to different
                                                                 non-overlapping L3 headers.

                                                                 * If a packet L2 header will be marked, then the entire L2 header must not overlap with
                                                                 computation enabled by either of PKO_SEND_HDR_S[CKL3,CKL4], and must not overlap with any
                                                                 PKO_SEND_CRC_S CRCs.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO marks each TSO segment
                                                                 independently, using [MARKPTR] for every TSO segment when present. */
        uint64_t l3ptr                 : 8;  /**< [ 31: 24] Layer 3 IP offset. Specifies the location of the first byte of the IP packet for L3
                                                                 checksum and/or L4 checksum and/or shaper marking. (See [CKL3,CKL4,FORMAT] and
                                                                 PKO_SEND_HDR_S[MARKPTR].) The IP packet must be exactly [L3PTR] bytes from the beginning
                                                                 of the packet. Software might populate this field for forwarded packets from a computation
                                                                 based off WQE[L3PTR], which is the IP location computed by PKI when the packet is parsed.

                                                                 When PKO_SEND_HDR_S[MARKPTR] is not present in the packet descriptor, [L3PTR] can also
                                                                 indicate the location of an L2 header. When [L3PTR] is used for any of [CKL3,CKL4] or
                                                                 marking calculations/modifications, then no L3 nor L2 header bytes indicated by
                                                                 [L3PTR] can overlap with any bytes covered by or inserted by PKO_SEND_CRC_S CRCs.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, [L3PTR] must point to the
                                                                 IP header, which must be before PKO_SEND_HDR_S[TSO_SB]. */
        uint64_t l4ptr                 : 8;  /**< [ 39: 32] Layer 4 offset. Specifies the location of the first byte of the TCP/UDP/SCTP header for L4
                                                                 checksumming (layer checksumming) or shaper marking. The Layer 4 header must
                                                                 be exactly [L4PTR] bytes from the beginning of the packet. Software might populate this
                                                                 field for forwarded packets from a computation based off WQE[L4PTR], which is the IP
                                                                 location computed by PKI when the packet is parsed. When [CKL4] is nonzero, no L4 header
                                                                 bytes indicated by [L4PTR] can overlap with any bytes covered by or inserted by
                                                                 PKO_SEND_CRC_S CRCs (but the subsequent L4 payload bytes can overlap with the
                                                                 PKO_SEND_CRC_S CRC bytes).

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, [L4PTR] must point to the
                                                                 TCP header, which must be before PKO_SEND_HDR_S[TSO_SB]. */
        uint64_t ii                    : 1;  /**< [ 40: 40] Ignore I. If set, ignore all PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[I] bits
                                                                 (effectively, force them all to zero) for the entire PKO SEND descriptor.

                                                                 If [II] is set, [DF] controls whether PKO frees the surrounding buffer
                                                                 after processing a packet segment. If [II] is clear,
                                                                 PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[I] can invert the default
                                                                 behavior selected by [DF].

                                                                 PKO frees the buffer surrounding a PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S
                                                                 segment when:

                                                                 _   [DF] XOR (NOT [II] AND PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[I]) = 0.

                                                                 PKO naturally aligns PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR] to
                                                                 128 bytes before sending it to FPA as part of the buffer free. An FPA
                                                                 naturally-aligned pool is recommended, though opaque pool mode may also be
                                                                 possible. Refer to the FPA chapter.

                                                                 PKO frees the buffer to the [AURA] contained in the descriptor (GATHER, LINK,
                                                                 JUMP, FREE)

                                                                 <page>

                                                                 PKO will not free PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR]
                                                                 to FPA until after it has finished reading the segment (and its preceding
                                                                 PKI_BUFLINK_S, if necessary) from the buffer.
                                                                 Provided the path of meta descriptors from the DQ through PKO to an output FIFO is
                                                                 unmodified between the meta descriptors (as should normally be the case, but it is
                                                                 possible for software to change the path), PKO also will not free
                                                                 PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR] to FPA
                                                                 until after it has completed all L2/DRAM reads related
                                                                 to processing any PKO_SEND_GATHER_S and any PKO_SEND_LINK_S in any
                                                                 descriptor enqueued earlier in the same DQ. PKO may free
                                                                 PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR] in
                                                                 any order with respect to any processing of any descriptor that is
                                                                 in a different DQ. PKO may create the FPA
                                                                 frees needed to process a PKO_SEND_GATHER_S or PKO_SEND_LINK_S subdescriptor
                                                                 in any order relative to any other PKO FPA frees needed to process
                                                                 this or any other PKO SEND descriptor, and in any order relative to
                                                                 any FPA frees/allocates needed for DQ DRAM buffering, and in any order
                                                                 relative any FPA aura count updates needed to process a PKO_SEND_AURA_S
                                                                 subdescriptor in this or any other PKO SEND.
                                                                 The FPA free may also occur in any order relative to any
                                                                 L2/DRAM updates or any work queue add needed to process this or
                                                                 any other PKO SEND. The FPA free may occur in any order relative to any
                                                                 L2/DRAM updates or any work queue add needed to process this or
                                                                 any other PKO SEND.

                                                                 <page>

                                                                 Note that [DF] has no effect on any buffer frees from a PKO_SEND_FREE_S or
                                                                 PKO_SEND_JUMP_S.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO
                                                                 frees the surrounding buffer only once for the descriptor,
                                                                 not once per TSO segment.
                                                                 Software must not modify the path of meta descriptors from the DQ through
                                                                 PKO to an output FIFO between TSO segments. */
        uint64_t shp_dis               : 1;  /**< [ 41: 41] Disables shaping for this packet.  Selects the shaper update and internal
                                                                 coloring algorithms used as the packet traverses enabled PKO DQ through
                                                                 L2 shapers. [SHP_DIS] has no effect on the L1 rate limiters. See
                                                                 PKO_META_DESC_S[COL], PKO_*_PICK[PIR_DIS,CIR_DIS] and PKO_COLORALG_E.
                                                                 When [SHP_DIS] is 1, PKO_META_DESC_S[COL] is set to NO_COLOR and
                                                                 both PKO_*_PICK[PIR_DIS,CIR_DIS] are asserted.  When [SHP_DIS] is 0
                                                                 PKO_*_SHAPE[YELLOW_DISABLE,RED_DISABLE] determine the packet
                                                                 coloring of the shaper.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO applies [SHP_DIS]
                                                                 to each TSO segment - PKO sets each PKO_META_DESC_S[COL]
                                                                 and PKO_nm_PICK[PIR_DIS,CIR_DIS] as described above. */
        uint64_t ckle                  : 1;  /**< [ 42: 42] Inner checksum L3. Similar to [CKL3] but for inner IP. */
        uint64_t cklf                  : 2;  /**< [ 44: 43] Inner checksum L4, enumerated by PKO_CKL4ALG_E. Similar to [CKL4] but for inner L4. */
        uint64_t ckl3                  : 1;  /**< [ 45: 45] Checksum L3. If set, PKO hardware calculates the IPv4 header checksum and inserts it into
                                                                 the packet, as described in L4 checksum. When set, [L3PTR] selects the location of the
                                                                 first byte of the L3 header and no L3 header bytes selected by [L3PTR] can overlap with
                                                                 any bytes covered or inserted by PKO_SEND_CRC_S CRCs. When [CKL3] is set, [L3PTR] must
                                                                 point to a valid IPv4 header. When PKO_SEND_HDR_S[TSO] is set with an IPv4 packet,
                                                                 [CKL3] must be set. [CKL3] must never be set with an IPv6 packet. */
        uint64_t ckl4                  : 2;  /**< [ 47: 46] Checksum L4, enumerated by PKO_CKL4ALG_E. If nonzero (not NONE):

                                                                 * PKO hardware calculates the Layer 4 TCP/UDP/SCTP checksum for the packet and inserts it
                                                                 into the packet, as described in Send CRC.

                                                                 * [L4PTR] selects the first byte of the L4 header, and [L3PTR] must indicate the location
                                                                 of the immediately proceeding and adjacent L3 header.

                                                                 * The L4 length field must not require more than [TOTAL] bytes in the packet and the L4
                                                                 length must be nonzero.

                                                                 * When PKO_SEND_CRC_S are present, the bytes covered or inserted by PKO_SEND_CRC_S must
                                                                 all reside in the L4 payload. Conceptually, PKO processes PKO_SEND_CRC_S before L4
                                                                 checksums when both are present.

                                                                 * When PKO_SEND_HDR_S[TSO] is set, [CKL4] must be TCP */
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t format                : 7;  /**< [ 55: 49] Selects a CSR from the PKO_FORMAT()_CTL array which specifies
                                                                 how PKO will mark YELLOW and RED_SEND packets. [FORMAT] must
                                                                 be less than the size of the PKO_FORMAT()_CTL array.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO marks each TSO segment
                                                                 independently, using [FORMAT] for every TSO segment. */
        uint64_t tstmp                 : 1;  /**< [ 56: 56] PTP timestamp. If set, a later PKO_SEND_MEM_S will be present in this descriptor with
                                                                 PKO_SEND_MEM_S[ALG] set to TSTMP to request IEEE 1588 PTP time-stamping. Furthermore, if
                                                                 set, [RA] must be PKO_REDALG_E::SEND.

                                                                 [TSTMP] must not be set when PKO_SEND_HDR_S[TSO] is set in the descriptor. */
        uint64_t tso_eom               : 1;  /**< [ 57: 57] Reserved. Must be zero.
                                                                 Internal:
                                                                 End of message. PKO sets [EOM] in the last replicated packet descriptor. */
        uint64_t df                    : 1;  /**< [ 58: 58] Don't free. If set, by default PKO will not free the surrounding buffer after
                                                                 processing a packet segment. If clear, by default PKO will free the
                                                                 surrounding buffer after processing a packet segment.

                                                                 If [II] is set, [DF] controls whether PKO frees the surrounding buffer
                                                                 after processing a packet segment. If [II] is clear,
                                                                 PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[I] can invert the default
                                                                 behavior selected by [DF].

                                                                 PKO frees the buffer surrounding a PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S
                                                                 segment when:

                                                                 _   [DF] XOR (NOT [II] AND PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[I]) = 0.

                                                                 PKO naturally aligns PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR]
                                                                 to 128 bytes before sending it to FPA as part of the buffer free. An FPA
                                                                 naturally-aligned pool is recommended, though opaque pool mode may also
                                                                 be possible. Refer to the FPA chapter.

                                                                 PKO frees the buffer to the [AURA] contained in the descriptor (GATHER/LINK/JUMP/FREE).

                                                                 <page>

                                                                 PKO will not free PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR]
                                                                 to FPA until after it has finished reading the segment (and its preceding
                                                                 PKI_BUFLINK_S, if necessary) from the buffer.
                                                                 Provided the path of meta descriptors from the DQ through PKO to an output FIFO is
                                                                 unmodified between the meta descriptors (as should normally be the case, but it is
                                                                 possible for software to change the path), PKO also will not free
                                                                 PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR] to FPA
                                                                 until after it has completed all L2/DRAM reads related
                                                                 to processing any PKO_SEND_GATHER_S and any PKO_SEND_LINK_S in any
                                                                 descriptor enqueued earlier in the same DQ. PKO may free
                                                                 PKO_SEND_GATHER_S/PKO_SEND_LINK_S/PKI_BUFLINK_S[ADDR] in
                                                                 any order with respect to any processing of any descriptor that is
                                                                 in a different DQ. PKO may create the FPA
                                                                 frees needed to process a PKO_SEND_GATHER_S or PKO_SEND_LINK_S subdescriptor
                                                                 in any order relative to any other PKO FPA frees needed to process
                                                                 this or any other PKO SEND descriptor, and in any order relative to
                                                                 any FPA frees/allocates needed for DQ DRAM buffering, and in any order
                                                                 relative any FPA aura count updates needed to process a PKO_SEND_AURA_S
                                                                 subdescriptor in this or any other PKO SEND. The FPA free may occur in any
                                                                 order relative to any L2/DRAM updates or any work queue add needed to
                                                                 process this or any other PKO SEND.

                                                                 Note that [DF] has no effect on any buffer frees from a PKO_SEND_FREE_S or
                                                                 PKO_SEND_JUMP_S.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO
                                                                 frees the surrounding buffer only once for the descriptor,
                                                                 not once per TSO segment.
                                                                 Software must not modify the path of meta descriptors from the DQ through
                                                                 PKO to an output FIFO between TSO segments. */
        uint64_t tso                   : 1;  /**< [ 59: 59] If set, segment a larger TCP source packet into
                                                                 multiple smaller TSO segment output packets. Software creates a single
                                                                 descriptor describing the source packet and including the PKO_SEND_HDR_S[TSO]=1,
                                                                 and PKO automatically outputs the resultant TSO segmented packets.

                                                                 For each produced segment, PKO duplicates the PKO SEND descriptor in the DQ
                                                                 and creates an independent meta descriptor (PKO_META_DESC_S and PKO_*_PICK)
                                                                 for scheduling, conditioning, and transmission. PKO duplicates/creates
                                                                 the L2, IP, and TCP headers from the source packet into the TSO segments,
                                                                 and distributes the source packet TCP payload bytes across the TSO
                                                                 segments. All the produced TSO segments will be sent out the MAC/interface in
                                                                 order, but PKO schedules each segment independently, so PKO can
                                                                 transmit packets from other DQ's between the TSO segments produced
                                                                 from the descriptor.

                                                                 <page>

                                                                 PKO simply copies most L2, IP, and TCP header fields from the source
                                                                 packet to the TSO segments. PKO modifies the following pre-segmented
                                                                 source packet fields in each produced TSO segment:

                                                                 * If PKO considers the L2 type/length field to be a length (see [L2LEN] below):
                                                                    o PKO sets the L2 length field to (FPS + [SB] - ([L2LEN] + 2)).

                                                                 * In the IPv4 case:
                                                                    o PKO sets IPv4.totallength to (FPS + [SB] - PKO_SEND_HDR_S[L3PTR]).
                                                                    o PKO calculates and inserts the IP checksum.
                                                                    o PKO increments the IP Identification field from the last segment
                                                                      by one. The IP Identification field in the first produced segment
                                                                      is unmodified from the pre-segmented source packet.

                                                                 * In the IPv6 case:
                                                                    o PKO sets IPv6.payloadlength to (FPS + [SB] - PKO_SEND_HDR_S[L3PTR] - 40).

                                                                 * PKO produces the TCP sequence number by adding the FPS from the prior
                                                                   segment to the TCP sequence number used in the prior segment.
                                                                   The TCP sequence number in the first produced segment is unmodified
                                                                   from the pre-segmented source packet.

                                                                 * PKO produces the TCP flags by logical-anding
                                                                   PKO_PEB_TSO_CFG[FSF, MSF, or LSF] with the pre-segmented source TCP flags -
                                                                   FSF is used for the first segment, MSF for the middle segments, and
                                                                   LSF for the last segment.

                                                                 Where FPS is the payload bytes in the TSO segment. For all but the last segment,
                                                                 FPS equals ([MSS]-[SB]). In the last segment, 0 < FPS <= ([MSS]-[SB]). The
                                                                 aggregate payload bytes in all produced segments is PKO_SEND_HDR_S[TOTAL]-[SB].

                                                                 <page>

                                                                 The meta-packet for each produced segment is the same as the meta-packet
                                                                 that would be produced for the pre-segmented source packet, with the
                                                                 following exceptions:

                                                                 * PKO_META_DESC_S[LENGTH] / PKO_*_PICK[LENGTH] for each TSO segment is
                                                                       (PKO_PDM_DQ*_MINPAD[MINPAD] ?
                                                                           MAX(PKO_PDM_CFG[PKO_PAD_MINLEN], (FPS+[SB])) :
                                                                           (FPS+[SB]))

                                                                 * PKO_META_DESC_S[FPD] / PKO_*_PICK[FPD] is independently calculated
                                                                   for each descriptor copy.

                                                                 <page>

                                                                 The following are constraints when PKO_SEND_HDR_S[TSO] is set
                                                                 in a descriptor:

                                                                 * 576 <= [MSS] < PKO_SEND_HDR_S[TOTAL] <= (128*[MSS] - 127*[SB])

                                                                 * PKO_SEND_HDR_S[CKL4] = TCP

                                                                 * PKO_SEND_HDR_S[L3PTR] must point to the first byte in the one and only IP header
                                                                   o IP tunneled packets are not supported with TSO.

                                                                 * PKO_SEND_HDR_S[L4PTR] must point to the first byte in the corresponding TCP header

                                                                 * In the IPv4 case:
                                                                    o PKO_SEND_HDR_S[TOTAL] = PKO_SEND_HDR_S[L3PTR]+(IPv4.totallength)
                                                                    o PKO_SEND_HDR_S[CKL3] = 1

                                                                 * In the IPv6 case:
                                                                    o PKO_SEND_HDR_S[TOTAL] = PKO_SEND_HDR_S[L3PTR]+40+(IPv6.payloadlength)
                                                                    o PKO_SEND_HDR_S[CKL3] = 0

                                                                 * If PKO considers the L2 type/length field to be a length (see [L2LEN] below):
                                                                    o [MSS] < 0x600
                                                                    o PKO_SEND_HDR_S[L3PTR] = [L2LEN] + 10 (likely, if not required)

                                                                 * else if PKO does not consider the L2 type/length field to be a length:
                                                                    o PKO_SEND_HDR_S[L3PTR] = [L2LEN] + 2

                                                                 * If any PKO_SEND_IMM_S's are present in the descriptor, they must never
                                                                   provide source packet bytes after the first [SB] bytes in the source packet.

                                                                 * PKO_MAC()_CFG[MIN_PAD_ENA] and PKO_PDM_CFG[PKO_PAD_MINLEN] must be set
                                                                   appropriately if minimum pad is required by the interface/MAC.
                                                                   PKO_PDM_DQ*_MINPAD[MINPAD] should normally also be set when minimum
                                                                   pad is required by the interface/MAC.

                                                                 * PKO_MAC()_CFG[FCS_ENA] should normally be set if the interface/MAC requires
                                                                   FCS. But an alternative is to enable FCS in the MAC in the cases when
                                                                   the MAC supports FCS generation.

                                                                 Hardware performance may be less optimal when a PKO_SEND_LINK_S is present in
                                                                 the descriptor with many links. PKO_SEND_GATHER_S usage is recommended
                                                                 with TSO. */
        uint64_t n2                    : 1;  /**< [ 60: 60] No L2 allocate. When clear, PKO allocates all packet load data into the L2 cache.
                                                                 When set, PKO does not allocate blocks containing segment bytes into the L2 cache.
                                                                 [N2] affects performance, but otherwise does not affect CNXXXX behavior. It may be
                                                                 advantageous to set [N2] if packet data will not be used after PKO sends the packet, which
                                                                 will allow the L2 cache to retain other more useful information.

                                                                 When allocating, PKO reads packet data with LDD transactions. When not allocating,
                                                                 PKO reads packet data with LDWB (when freeing the buffer surrounding the
                                                                 segment) or LDT (when not freeing the buffer surrounding the segment)
                                                                 transactions.

                                                                 Note that PKO_PDM_CFG[ALLOC_LDS] selects L2 cache allocation for any DQ descriptor/meta
                                                                 reads, and PKO_PTF_IOBP_CFG[IOBP0_L2_ALLOCATE] determines L2 cache allocation for
                                                                 any post-PKO_SEND_JUMP_S descriptor reads. Also, PKO always allocates packet data
                                                                 into the L2 cache on the first-pass packet read of a two-pass TCP/UDP checksum
                                                                 calculation, and may allocate portions of packet data into the L2 cache when
                                                                 PKO_SEND_HDR_S[TSO]==1. */
        uint64_t scntm1                : 3;  /**< [ 63: 61] Sub-descriptor count. PKO packs the send operation's number of sub-descriptors
                                                                 (minus one) here.  Software should not modify this. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t l2len                 : 8;  /**< [127:120] Offset in bytes to the two-byte L2 header-type/length field. If the type/length
                                                                 field value in the pre-segmented packet is 0 .. 1535, PKO considers it
                                                                 to be a length field, and modifies it for each produced segment. */
        uint64_t tso_fn                : 7;  /**< [119:113] Reserved. Must be zero.
                                                                 Internal:
                                                                 Frame number. PKO increases [FN] in every replicated packet descriptor. */
        uint64_t shp_chg               : 9;  /**< [112:104] Signed packet size adjustment. The packet size used for shaper {a} (PIR_ACCUM and
                                                                 CIR_ACCUM) and DWRR scheduler {a} (RR_COUNT) calculations at level {b} is:

                                                                 _  (PKO_{b}{a}_SHAPE[LENGTH_DISABLE]
                                                                        ? 0 : (PKO_{b}{a}_PICK[LENGTH] + [SHP_CHG])) + PKO_{b}{a}_SHAPE[ADJUST]

                                                                 where {b} = L1_SQ, L2_SQ, L3_SQ, L4_SQ, L5_SQ, or DQ and {a} selects one of the
                                                                 shapers at the level selected by {b}.

                                                                 [SHP_CHG] values -255 .. 255 are allowed. [SHP_CHG] value 0x100 (i.e. -256)
                                                                 is reserved and must never be used.

                                                                 [SHP_CHG] becomes PKO_META_DESC_S[ADJUST] and PKO_{b}m_PICK[ADJUST].

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO applies [SHP_CHG]
                                                                 to each TSO segment - PKO copies [SHP_CHG] to each PKO_META_DESC_S[ADJUST]
                                                                 and PKO_nm_PICK[ADJUST]. */
        uint64_t lfptr                 : 8;  /**< [103: 96] Inner Layer 4 Offset. Similar to [L4PTR] but for inner L4 as directed by [CKLF]. If
                                                                 [CKLF] and [CKL4] are both nonzero, then [LFPTR] must be > [L4PTR] + 20. */
        uint64_t leptr                 : 8;  /**< [ 95: 88] Inner Layer 3 IP Offset. Similar to [L3PTR] but for inner IP as directed by [CKLE]. If
                                                                 [CKLE] and [CKL3] are set, then [LEPTR] must be > [L3PTR] + 20. */
        uint64_t tso_sb                : 8;  /**< [ 87: 80] Start bytes. Location of the start byte of the TCP message payload (a.k.a the
                                                                 size of the headers preceding the TCP data - must point to the first byte
                                                                 following the TCP L4 header). PKO copies all bytes preceding [SB] to each
                                                                 segment, only modifying the specific fields mentioned above in each segment.

                                                                 [SB] must be >= [L2LEN]+42 in all cases, sometimes larger. [SB] must be
                                                                 >= PKO_SEND_HDR_S[L3PTR]+40 in all cases, sometimes larger. [SB] must be >=
                                                                 PKO_SEND_HDR_S[L4PTR]+20 in all cases, sometimes larger. */
        uint64_t shp_ra                : 2;  /**< [ 79: 78] Red algorithm. Enumerated by PKO_REDALG_E. Specifies handling of a packet that
                                                                 traverses a RED DQ through L2 shaper. (A shaper is in RED state when
                                                                 PKO_*_SHAPE_STATE[COLOR]=0x2.) Has no effect when the packet traverses no
                                                                 shapers that are in the RED state. When [RA]!=STD, [RA] over-rides the
                                                                 PKO_*_SHAPE[RED_ALGO] settings in all DQ through L2 shapers traversed
                                                                 by the packet. [RA] has no effect on the L1 rate limiters. See
                                                                 PKO_META_DESC_S[RA] and PKO_*_PICK[RED_ALGO_OVERRIDE].

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO applies [RA]
                                                                 to each TSO segment - PKO copies [RA] to each PKO_META_DESC_S[RA]
                                                                 and PKO_nm_PICK[RED_ALGO_OVERRIDE]. */
        uint64_t tso_mss               : 14; /**< [ 77: 64] Message segment size. The maximum message header + frame payload size (FPS) for
                                                                 each segment. The number of segments that PKO creates (num_segs) is

                                                                  num_segs = [ (total_payload + payload_per_seg - 1) / payload_per_seg ]

                                                                 where

                                                                  total_payload = PKO_SEND_HDR_S[TOTAL] - [SB]
                                                                  payload_per_seg = [MSS] - [SB]
                                                                  [ x ] indicates to round x down to the nearest whole number

                                                                 num_segs must be greater than 1 and must never exceed 128. [MSS] must
                                                                 be >= 576. [MSS] must be <= 1535 whenever PKO considers
                                                                 the length/type field selected by [L2LEN] to be a length field. */
#else /* Word 1 - Little Endian */
        uint64_t tso_mss               : 14; /**< [ 77: 64] Message segment size. The maximum message header + frame payload size (FPS) for
                                                                 each segment. The number of segments that PKO creates (num_segs) is

                                                                  num_segs = [ (total_payload + payload_per_seg - 1) / payload_per_seg ]

                                                                 where

                                                                  total_payload = PKO_SEND_HDR_S[TOTAL] - [SB]
                                                                  payload_per_seg = [MSS] - [SB]
                                                                  [ x ] indicates to round x down to the nearest whole number

                                                                 num_segs must be greater than 1 and must never exceed 128. [MSS] must
                                                                 be >= 576. [MSS] must be <= 1535 whenever PKO considers
                                                                 the length/type field selected by [L2LEN] to be a length field. */
        uint64_t shp_ra                : 2;  /**< [ 79: 78] Red algorithm. Enumerated by PKO_REDALG_E. Specifies handling of a packet that
                                                                 traverses a RED DQ through L2 shaper. (A shaper is in RED state when
                                                                 PKO_*_SHAPE_STATE[COLOR]=0x2.) Has no effect when the packet traverses no
                                                                 shapers that are in the RED state. When [RA]!=STD, [RA] over-rides the
                                                                 PKO_*_SHAPE[RED_ALGO] settings in all DQ through L2 shapers traversed
                                                                 by the packet. [RA] has no effect on the L1 rate limiters. See
                                                                 PKO_META_DESC_S[RA] and PKO_*_PICK[RED_ALGO_OVERRIDE].

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO applies [RA]
                                                                 to each TSO segment - PKO copies [RA] to each PKO_META_DESC_S[RA]
                                                                 and PKO_nm_PICK[RED_ALGO_OVERRIDE]. */
        uint64_t tso_sb                : 8;  /**< [ 87: 80] Start bytes. Location of the start byte of the TCP message payload (a.k.a the
                                                                 size of the headers preceding the TCP data - must point to the first byte
                                                                 following the TCP L4 header). PKO copies all bytes preceding [SB] to each
                                                                 segment, only modifying the specific fields mentioned above in each segment.

                                                                 [SB] must be >= [L2LEN]+42 in all cases, sometimes larger. [SB] must be
                                                                 >= PKO_SEND_HDR_S[L3PTR]+40 in all cases, sometimes larger. [SB] must be >=
                                                                 PKO_SEND_HDR_S[L4PTR]+20 in all cases, sometimes larger. */
        uint64_t leptr                 : 8;  /**< [ 95: 88] Inner Layer 3 IP Offset. Similar to [L3PTR] but for inner IP as directed by [CKLE]. If
                                                                 [CKLE] and [CKL3] are set, then [LEPTR] must be > [L3PTR] + 20. */
        uint64_t lfptr                 : 8;  /**< [103: 96] Inner Layer 4 Offset. Similar to [L4PTR] but for inner L4 as directed by [CKLF]. If
                                                                 [CKLF] and [CKL4] are both nonzero, then [LFPTR] must be > [L4PTR] + 20. */
        uint64_t shp_chg               : 9;  /**< [112:104] Signed packet size adjustment. The packet size used for shaper {a} (PIR_ACCUM and
                                                                 CIR_ACCUM) and DWRR scheduler {a} (RR_COUNT) calculations at level {b} is:

                                                                 _  (PKO_{b}{a}_SHAPE[LENGTH_DISABLE]
                                                                        ? 0 : (PKO_{b}{a}_PICK[LENGTH] + [SHP_CHG])) + PKO_{b}{a}_SHAPE[ADJUST]

                                                                 where {b} = L1_SQ, L2_SQ, L3_SQ, L4_SQ, L5_SQ, or DQ and {a} selects one of the
                                                                 shapers at the level selected by {b}.

                                                                 [SHP_CHG] values -255 .. 255 are allowed. [SHP_CHG] value 0x100 (i.e. -256)
                                                                 is reserved and must never be used.

                                                                 [SHP_CHG] becomes PKO_META_DESC_S[ADJUST] and PKO_{b}m_PICK[ADJUST].

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO applies [SHP_CHG]
                                                                 to each TSO segment - PKO copies [SHP_CHG] to each PKO_META_DESC_S[ADJUST]
                                                                 and PKO_nm_PICK[ADJUST]. */
        uint64_t tso_fn                : 7;  /**< [119:113] Reserved. Must be zero.
                                                                 Internal:
                                                                 Frame number. PKO increases [FN] in every replicated packet descriptor. */
        uint64_t l2len                 : 8;  /**< [127:120] Offset in bytes to the two-byte L2 header-type/length field. If the type/length
                                                                 field value in the pre-segmented packet is 0 .. 1535, PKO considers it
                                                                 to be a length field, and modifies it for each produced segment. */
#endif /* Word 1 - End */
    } s;
    /* struct bdk_pko_send_hdr_s_s cn; */
};

/**
 * Structure pko_send_imm_s
 *
 * PKO Send Immediate Subdescriptor Structure
 * The send immediate subdescriptor directly includes bytes of packet data.
 * The subdescriptor format is this 64-bit PKO_SEND_IMM_S followed immediately
 * by the packet data. The next subdescriptor (if any) follows the packet data
 * bytes (after rounding up to be a multiple of 16 bytes).
 *
 * There may be multiple PKO_SEND_IMM_S in one PKO SEND descriptor.  A PKO_SEND_IMM_S must
 * not be present in a PKO SEND descriptor when the sum of all prior PKO_SEND_GATHER_S[SIZE]s
 * and all prior PKO_SEND_IMM_S[SIZE]s equals or exceeds PKO_SEND_HDR_S[TOTAL]. (i.e. Some
 * immediate bytes must be usable.) Furthermore, all supplied immediate bytes must
 * be used. A PKO_SEND_IMM_S must precede a PKO_SEND_LINK_S in a PKO SEND descriptor.
 *
 * When PKO_SEND_HDR_S[TSO] is set in the descriptor, all PKO_SEND_IMM_S
 * bytes must be included in the the first PKO_SEND_HDR_S[TSO_SB] bytes of the
 * source packet.
 */
union bdk_pko_send_imm_s
{
    uint64_t u[2];
    struct bdk_pko_send_imm_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send immediate. Enumerated by PKO_SENDSUBDC_E::IMM. */
        uint64_t reserved_49_59        : 11;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_16_47        : 32;
        uint64_t size                  : 16; /**< [ 15:  0] Size of immediate (in bytes) that immediately follows this 64-bit structure.
                                                                 [SIZE] must be between 1 and 32 bytes. The next subdescriptor follow [SIZE]
                                                                 bytes later in the descriptor, rounded up to the next 8-byte aligned
                                                                 boundary.

                                                                 Let priorbytes = the sum of all prior PKO_SEND_GATHER_S[SIZE]s and
                                                                 PKO_SEND_IMM_S[SIZE]s in this descriptor. This PKO_SEND_IMM_S
                                                                 must only be present in the descriptor when
                                                                 (priorbytes + [SIZE]) <= PKO_SEND_HDR_S[TOTAL].
                                                                 That is, all supplied immediate bytes must be used.

                                                                 The sum of any PKO_SEND_IMM_S[SIZE]s, PKO_SEND_GATHER_S[SIZE]s, and
                                                                 PKO_SEND_LINK_S[SIZE]s in the descriptor plus any PKI_BUFLINK_S[SIZE]s
                                                                 linked by any PKO_SEND_LINK_S must equal or exceed PKO_SEND_HDR_S[TOTAL]. */
#else /* Word 0 - Little Endian */
        uint64_t size                  : 16; /**< [ 15:  0] Size of immediate (in bytes) that immediately follows this 64-bit structure.
                                                                 [SIZE] must be between 1 and 32 bytes. The next subdescriptor follow [SIZE]
                                                                 bytes later in the descriptor, rounded up to the next 8-byte aligned
                                                                 boundary.

                                                                 Let priorbytes = the sum of all prior PKO_SEND_GATHER_S[SIZE]s and
                                                                 PKO_SEND_IMM_S[SIZE]s in this descriptor. This PKO_SEND_IMM_S
                                                                 must only be present in the descriptor when
                                                                 (priorbytes + [SIZE]) <= PKO_SEND_HDR_S[TOTAL].
                                                                 That is, all supplied immediate bytes must be used.

                                                                 The sum of any PKO_SEND_IMM_S[SIZE]s, PKO_SEND_GATHER_S[SIZE]s, and
                                                                 PKO_SEND_LINK_S[SIZE]s in the descriptor plus any PKI_BUFLINK_S[SIZE]s
                                                                 linked by any PKO_SEND_LINK_S must equal or exceed PKO_SEND_HDR_S[TOTAL]. */
        uint64_t reserved_16_47        : 32;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_49_59        : 11;
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send immediate. Enumerated by PKO_SENDSUBDC_E::IMM. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t data                  : 64; /**< [127: 64] First 8 bytes of immediate data. */
#else /* Word 1 - Little Endian */
        uint64_t data                  : 64; /**< [127: 64] First 8 bytes of immediate data. */
#endif /* Word 1 - End */
    } s;
    /* struct bdk_pko_send_imm_s_s cn; */
};

/**
 * Structure pko_send_jump_s
 *
 * PKO Send Jump Subdescriptor Structure
 * The send jump subdescriptor selects a new address for fetching the next subdescriptor.
 *
 * This allows software to create subdescriptor lists longer than the 15 directly
 * supported by the hardware. There can be only one PKO_SEND_JUMP_S subdescriptor in a packet
 * descriptor. PKO_SEND_JUMP_S must be the last subdescriptor in the initial (up to 2
 * subdescriptor) portion of the packet descriptor and must precede all subdescriptors
 * other than PKO_SEND_HDR_S in the PKO SEND descriptor.
 */
union bdk_pko_send_jump_s
{
    uint64_t u[2];
    struct bdk_pko_send_jump_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send jump. Enumerated by PKO_SENDSUBDC_E::JUMP0. */
        uint64_t reserved_54_59        : 6;
        uint64_t f                     : 1;  /**< [ 53: 53] When set, PKO will free the buffer indicated by [ADDR] to FPA after it has read all
                                                                 subdescriptors from it. When clear, PKO will not free the buffer indicated by [ADDR].

                                                                 PKO sends [ADDR] to FPA as part of the buffer free when [F] is set. Either an FPA
                                                                 naturally-aligned pool or opaque pool may be appropriate. Refer to the FPA chapter.

                                                                 PKO frees the buffer to [AURA] specified in the descriptor.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO
                                                                 frees the buffer only once for the descriptor, not once per TSO segment.
                                                                 Software must not modify the path of meta descriptors from the DQ through
                                                                 PKO to an output FIFO between TSO segments. */
        uint64_t reserved_49_52        : 4;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_40_47        : 8;
        uint64_t aura                  : 16; /**< [ 39: 24] See PKO_SEND_FREE_S[AURA]. */
        uint64_t reserved_16_23        : 8;
        uint64_t size                  : 16; /**< [ 15:  0] Number of 16-byte subdescriptor words in the subdescriptor list that [ADDR]
                                                                 points to. The total size of a PKO SEND descriptor must never exceed 255 64-bit
                                                                 words. */
#else /* Word 0 - Little Endian */
        uint64_t size                  : 16; /**< [ 15:  0] Number of 16-byte subdescriptor words in the subdescriptor list that [ADDR]
                                                                 points to. The total size of a PKO SEND descriptor must never exceed 255 64-bit
                                                                 words. */
        uint64_t reserved_16_23        : 8;
        uint64_t aura                  : 16; /**< [ 39: 24] See PKO_SEND_FREE_S[AURA]. */
        uint64_t reserved_40_47        : 8;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_49_52        : 4;
        uint64_t f                     : 1;  /**< [ 53: 53] When set, PKO will free the buffer indicated by [ADDR] to FPA after it has read all
                                                                 subdescriptors from it. When clear, PKO will not free the buffer indicated by [ADDR].

                                                                 PKO sends [ADDR] to FPA as part of the buffer free when [F] is set. Either an FPA
                                                                 naturally-aligned pool or opaque pool may be appropriate. Refer to the FPA chapter.

                                                                 PKO frees the buffer to [AURA] specified in the descriptor.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO
                                                                 frees the buffer only once for the descriptor, not once per TSO segment.
                                                                 Software must not modify the path of meta descriptors from the DQ through
                                                                 PKO to an output FIFO between TSO segments. */
        uint64_t reserved_54_59        : 6;
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send jump. Enumerated by PKO_SENDSUBDC_E::JUMP0. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t addr                  : 64; /**< [127: 64] The IOVA L2/DRAM address of the first byte of the next subdescriptor. [ADDR]
                                                                 must be 128 byte aligned. PKO will ignore ADDR<3:0>.

                                                                 If PKO_PF_VF()_GMCTL[BE] is set for this VF, [ADDR] points to big-endian
                                                                 instructions, otherwise little-endian. */
#else /* Word 1 - Little Endian */
        uint64_t addr                  : 64; /**< [127: 64] The IOVA L2/DRAM address of the first byte of the next subdescriptor. [ADDR]
                                                                 must be 128 byte aligned. PKO will ignore ADDR<3:0>.

                                                                 If PKO_PF_VF()_GMCTL[BE] is set for this VF, [ADDR] points to big-endian
                                                                 instructions, otherwise little-endian. */
#endif /* Word 1 - End */
    } s;
    /* struct bdk_pko_send_jump_s_s cn; */
};

/**
 * Structure pko_send_link_s
 *
 * PKO Send Linked Subdescriptor Structure
 * The send linked subdescriptor requests a linked list of contiguous segments of bytes be
 * transmitted. PKO traverses as many links as needed, starting with the PKO_SEND_LINK_S
 * subdescriptor. Remaining segments are linked from their preceding segment by
 * a PKI_BUFLINK_S that precedes the preceding segment in L2/DRAM.
 *
 * At most one PKO_SEND_LINK_S can be present in each PKO SEND descriptor. A PKO_SEND_LINK_S
 * must follow all PKO_SEND_GATHER_S and PKO_SEND_IMM_S subdescriptors in the PKO send
 * descriptor. A PKO_SEND_LINK_S must not be present in a PKO SEND descriptor if the sum of all
 * PKO_SEND_GATHER_S[SIZE]s and PKO_SEND_IMM_S[SIZE]s in the descriptor meets or
 * exceeds PKO_SEND_HDR_S[TOTAL]. (i.e. Some of the packet data from a PKO_SEND_LINK_S
 * must be used.) The total number of bytes contributed from the PKO_SEND_LINK_S and its links
 * is PKO_SEND_HDR_S[TOTAL] minus the sum of all PKO_SEND_GATHER_S[SIZE]s and
 * PKO_SEND_IMM_S[SIZE]s in the descriptor. A PKO_SEND_LINK_S must follow all
 * PKO_SEND_GATHER_S and PKO_SEND_IMM_S subdescriptors in the PKO SEND descriptor.
 * The number of segments in a PKO_SEND_LINK_S chain must never exceed 200.
 */
union bdk_pko_send_link_s
{
    uint64_t u[2];
    struct bdk_pko_send_link_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send link. Enumerated by PKO_SENDSUBDC_E::LINK0. */
        uint64_t ld_type               : 2;  /**< [ 59: 58] Specifies load transaction type to use for reading segment bytes. Enumerated by
                                                                 NIC_SEND_LD_TYPE_E. */
        uint64_t i                     : 1;  /**< [ 57: 57] Invert free. See PKO_SEND_HDR_S[DF,II].

                                                                 PKO frees the surrounding buffer when:

                                                                 _  PKO_SEND_HDR_S[DF] XOR (NOT PKO_SEND_HDR_S[II] AND [I]) = 0.

                                                                 PKO naturally aligns [ADDR] to 128 bytes before sending it to FPA as part of
                                                                 the buffer free. An FPA naturally-aligned pool is recommended, though opaque
                                                                 pool mode may also be possible. Refer to the FPA chapter.

                                                                 PKO frees the buffer to [AURA].

                                                                 PKO will not free [ADDR] to FPA until after it has finished reading
                                                                 this segment (and the PKI_BUFLINK_S that precedes this segment in
                                                                 the buffer, if necessary) from the buffer.
                                                                 Provided the path of meta descriptors from the DQ through PKO to an output FIFO is
                                                                 unmodified between the meta descriptors (as should normally be the case, but it is
                                                                 possible for software to change the path), PKO also will not free
                                                                 [ADDR] to FPA until after it has completed all L2/DRAM reads related
                                                                 to processing any PKO_SEND_GATHER_S and any PKO_SEND_LINK_S in any
                                                                 descriptor enqueued earlier in the same DQ. PKO may free [ADDR] in
                                                                 any order with respect to any processing of any descriptor that is
                                                                 in a different DQ. PKO may create the FPA
                                                                 free for a PKO_SEND_LINK_S in any order relative to any PKO FPA
                                                                 frees needed to process this or any other PKO SEND descriptor,
                                                                 and in any order relative to any FPA frees/allocates needed for DQ DRAM
                                                                 buffering, and in any order relative to any FPA aura count
                                                                 updates needed to process a PKO_SEND_AURA_S subdescriptor in this
                                                                 or any other PKO SEND. The FPA free may occur in any order relative to any
                                                                 L2/DRAM updates or any work queue add needed to process this or
                                                                 any other PKO SEND.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO
                                                                 frees the surrounding buffer only once for the descriptor,
                                                                 not once per TSO segment.
                                                                 Software must not modify the path of meta descriptors from the DQ through
                                                                 PKO to an output FIFO between TSO segments. */
        uint64_t reserved_49_56        : 8;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_40_47        : 8;
        uint64_t aura                  : 16; /**< [ 39: 24] see PKO_SEND_FREE_S[AURA] */
        uint64_t reserved_16_23        : 8;
        uint64_t size                  : 16; /**< [ 15:  0] Size of segment, in bytes. [SIZE] must be nonzero.

                                                                 Let priorbytes = the sum of all prior PKO_SEND_GATHER_S[SIZE]s
                                                                 and PKO_SEND_IMM_S[SIZE]s in this descriptor. This PKO_SEND_LINK_S
                                                                 must not be present in the descriptor when
                                                                 priorbytes >= PKO_SEND_HDR_S[TOTAL].

                                                                 The number of bytes used from this PKO_SEND_LINK_S segment (the first
                                                                 in the linked series) is:

                                                                 _    min(PKO_SEND_HDR_S[TOTAL]-priorbytes, [SIZE])

                                                                 It is legal for [SIZE] to exceed PKO_SEND_HDR_S[TOTAL]-priorbytes.

                                                                 When PKO_SEND_HDR_S[TOTAL]-priorbytes is larger than [SIZE], PKO fetches
                                                                 more packet data from the next segment described by the PKI_BUFLINK_S
                                                                 that must reside in the 8 L2/DRAM bytes prior to [ADDR].

                                                                 The sum of all PKO_SEND_IMM_S[SIZE], PKO_SEND_GATHER_S[SIZE], and
                                                                 PKO_SEND_LINK_S[SIZE] in the descriptor plus any PKI_BUFLINK_S[SIZE]
                                                                 linked by any PKO_SEND_LINK_S must equal or exceed PKO_SEND_HDR_S[TOTAL]. */
#else /* Word 0 - Little Endian */
        uint64_t size                  : 16; /**< [ 15:  0] Size of segment, in bytes. [SIZE] must be nonzero.

                                                                 Let priorbytes = the sum of all prior PKO_SEND_GATHER_S[SIZE]s
                                                                 and PKO_SEND_IMM_S[SIZE]s in this descriptor. This PKO_SEND_LINK_S
                                                                 must not be present in the descriptor when
                                                                 priorbytes >= PKO_SEND_HDR_S[TOTAL].

                                                                 The number of bytes used from this PKO_SEND_LINK_S segment (the first
                                                                 in the linked series) is:

                                                                 _    min(PKO_SEND_HDR_S[TOTAL]-priorbytes, [SIZE])

                                                                 It is legal for [SIZE] to exceed PKO_SEND_HDR_S[TOTAL]-priorbytes.

                                                                 When PKO_SEND_HDR_S[TOTAL]-priorbytes is larger than [SIZE], PKO fetches
                                                                 more packet data from the next segment described by the PKI_BUFLINK_S
                                                                 that must reside in the 8 L2/DRAM bytes prior to [ADDR].

                                                                 The sum of all PKO_SEND_IMM_S[SIZE], PKO_SEND_GATHER_S[SIZE], and
                                                                 PKO_SEND_LINK_S[SIZE] in the descriptor plus any PKI_BUFLINK_S[SIZE]
                                                                 linked by any PKO_SEND_LINK_S must equal or exceed PKO_SEND_HDR_S[TOTAL]. */
        uint64_t reserved_16_23        : 8;
        uint64_t aura                  : 16; /**< [ 39: 24] see PKO_SEND_FREE_S[AURA] */
        uint64_t reserved_40_47        : 8;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_49_56        : 8;
        uint64_t i                     : 1;  /**< [ 57: 57] Invert free. See PKO_SEND_HDR_S[DF,II].

                                                                 PKO frees the surrounding buffer when:

                                                                 _  PKO_SEND_HDR_S[DF] XOR (NOT PKO_SEND_HDR_S[II] AND [I]) = 0.

                                                                 PKO naturally aligns [ADDR] to 128 bytes before sending it to FPA as part of
                                                                 the buffer free. An FPA naturally-aligned pool is recommended, though opaque
                                                                 pool mode may also be possible. Refer to the FPA chapter.

                                                                 PKO frees the buffer to [AURA].

                                                                 PKO will not free [ADDR] to FPA until after it has finished reading
                                                                 this segment (and the PKI_BUFLINK_S that precedes this segment in
                                                                 the buffer, if necessary) from the buffer.
                                                                 Provided the path of meta descriptors from the DQ through PKO to an output FIFO is
                                                                 unmodified between the meta descriptors (as should normally be the case, but it is
                                                                 possible for software to change the path), PKO also will not free
                                                                 [ADDR] to FPA until after it has completed all L2/DRAM reads related
                                                                 to processing any PKO_SEND_GATHER_S and any PKO_SEND_LINK_S in any
                                                                 descriptor enqueued earlier in the same DQ. PKO may free [ADDR] in
                                                                 any order with respect to any processing of any descriptor that is
                                                                 in a different DQ. PKO may create the FPA
                                                                 free for a PKO_SEND_LINK_S in any order relative to any PKO FPA
                                                                 frees needed to process this or any other PKO SEND descriptor,
                                                                 and in any order relative to any FPA frees/allocates needed for DQ DRAM
                                                                 buffering, and in any order relative to any FPA aura count
                                                                 updates needed to process a PKO_SEND_AURA_S subdescriptor in this
                                                                 or any other PKO SEND. The FPA free may occur in any order relative to any
                                                                 L2/DRAM updates or any work queue add needed to process this or
                                                                 any other PKO SEND.

                                                                 When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO
                                                                 frees the surrounding buffer only once for the descriptor,
                                                                 not once per TSO segment.
                                                                 Software must not modify the path of meta descriptors from the DQ through
                                                                 PKO to an output FIFO between TSO segments. */
        uint64_t ld_type               : 2;  /**< [ 59: 58] Specifies load transaction type to use for reading segment bytes. Enumerated by
                                                                 NIC_SEND_LD_TYPE_E. */
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send link. Enumerated by PKO_SENDSUBDC_E::LINK0. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t addr                  : 64; /**< [127: 64] IOVA L2/DRAM address of the first byte of packet data in the segment. The 8
                                                                 bytes prior to [ADDR] must always be valid readable L2/DRAM locations, and must
                                                                 contain a valid PKI_BUFLINK_S if the packet has more than [SIZE] bytes (i.e. the
                                                                 PKI_BUFLINK_S must be valid if PKO_SEND_HDR_S[TOTAL] minus the sum of all
                                                                 PKO_SEND_GATHER_S[SIZE]s and PKO_SEND_IMM_S[SIZE]s in the descriptor is greater
                                                                 than [SIZE].)

                                                                 If PKO_PF_VF()_GMCTL[BE] is set for this VF, the next-buffer pointer inside the
                                                                 structure that [ADDR] points to is big-endian, else little-endian.  The packet
                                                                 data pointed to is byte-invariant and endian settings do not matter. */
#else /* Word 1 - Little Endian */
        uint64_t addr                  : 64; /**< [127: 64] IOVA L2/DRAM address of the first byte of packet data in the segment. The 8
                                                                 bytes prior to [ADDR] must always be valid readable L2/DRAM locations, and must
                                                                 contain a valid PKI_BUFLINK_S if the packet has more than [SIZE] bytes (i.e. the
                                                                 PKI_BUFLINK_S must be valid if PKO_SEND_HDR_S[TOTAL] minus the sum of all
                                                                 PKO_SEND_GATHER_S[SIZE]s and PKO_SEND_IMM_S[SIZE]s in the descriptor is greater
                                                                 than [SIZE].)

                                                                 If PKO_PF_VF()_GMCTL[BE] is set for this VF, the next-buffer pointer inside the
                                                                 structure that [ADDR] points to is big-endian, else little-endian.  The packet
                                                                 data pointed to is byte-invariant and endian settings do not matter. */
#endif /* Word 1 - End */
    } s;
    /* struct bdk_pko_send_link_s_s cn; */
};

/**
 * Structure pko_send_mem_s
 *
 * PKO Send Memory Subdescriptor Structure
 * The send memory subdescriptor atomically sets, increments or decrements a memory location.
 *
 * PKO_SEND_MEM_S subdescriptors must follow all PKO_SEND_LINK_S, PKO_SEND_GATHER_S,
 * PKO_SEND_IMM_S, and PKO_SEND_CRC_S subdescriptors in the packet descriptor.
 * PKO will not initiate the memory update for this subdescriptor until after it has completed
 * all L2/DRAM fetches that service all prior PKO_SEND_LINK_S and PKO_SEND_GATHER_S
 * subdescriptors.
 *
 * Performance is best if a memory decrement by one is used rather than any other memory
 * set/increment/decrement. (Less internal bus bandwidth is used with memory decrements by one.)
 *
 * When PKO_SEND_HDR_S[TSO] is set in the descriptor, PKO executes the
 * PKO_SEND_MEM_S work add only while processing the last TSO segment, after
 * processing prior segments.
 */
union bdk_pko_send_mem_s
{
    uint64_t u[2];
    struct bdk_pko_send_mem_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates Send Memory. Enumerated by PKO_SENDSUBDC_E::MEM. */
        uint64_t alg                   : 4;  /**< [ 59: 56] Adder algorithm. How to modify the memory location, for example by setting or atomically
                                                                 incrementing. Enumerated by PKO_MEMALG_E.

                                                                 Unless [ALG] is SETTSTMP (PKO_SEND_HDR_S[TSTMP] must be set in this case),
                                                                 the PKO_SEND_MEM can complete in any order relative to the packet send
                                                                 on the physical interface. */
        uint64_t dsz                   : 2;  /**< [ 55: 54] Memory data size. The size of the word in memory, enumerated by PKO_MEMDSZ_E. */
        uint64_t wmem                  : 1;  /**< [ 53: 53] Wait for memory. When set, there must be an SSO ADD_WORK requested with the final
                                                                 PKO_SEND_WORK_S subdescriptor. PKO will wait for this PKO_SEND_MEM_S requested memory
                                                                 operation to complete and commit before initiating the ADD_WORK. When clear, the memory
                                                                 operation may complete after the ADD_WORK and potentially after software has begun
                                                                 servicing the work. */
        uint64_t reserved_49_52        : 4;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_16_47        : 32;
        uint64_t offset                : 16; /**< [ 15:  0] Adder offset. Constant value to add or subtract or set. If the count being modified is to
                                                                 represent the true packet size, then the offset would represent the outside FCS appended
                                                                 to the packet.

                                                                 Internal:
                                                                 Note IOB hardware has a special encoding for atomic decrement,
                                                                 therefore a change of minus one is twice as IOB bandwidth efficient as adding/subtracting
                                                                 other values or setting. */
#else /* Word 0 - Little Endian */
        uint64_t offset                : 16; /**< [ 15:  0] Adder offset. Constant value to add or subtract or set. If the count being modified is to
                                                                 represent the true packet size, then the offset would represent the outside FCS appended
                                                                 to the packet.

                                                                 Internal:
                                                                 Note IOB hardware has a special encoding for atomic decrement,
                                                                 therefore a change of minus one is twice as IOB bandwidth efficient as adding/subtracting
                                                                 other values or setting. */
        uint64_t reserved_16_47        : 32;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_49_52        : 4;
        uint64_t wmem                  : 1;  /**< [ 53: 53] Wait for memory. When set, there must be an SSO ADD_WORK requested with the final
                                                                 PKO_SEND_WORK_S subdescriptor. PKO will wait for this PKO_SEND_MEM_S requested memory
                                                                 operation to complete and commit before initiating the ADD_WORK. When clear, the memory
                                                                 operation may complete after the ADD_WORK and potentially after software has begun
                                                                 servicing the work. */
        uint64_t dsz                   : 2;  /**< [ 55: 54] Memory data size. The size of the word in memory, enumerated by PKO_MEMDSZ_E. */
        uint64_t alg                   : 4;  /**< [ 59: 56] Adder algorithm. How to modify the memory location, for example by setting or atomically
                                                                 incrementing. Enumerated by PKO_MEMALG_E.

                                                                 Unless [ALG] is SETTSTMP (PKO_SEND_HDR_S[TSTMP] must be set in this case),
                                                                 the PKO_SEND_MEM can complete in any order relative to the packet send
                                                                 on the physical interface. */
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates Send Memory. Enumerated by PKO_SENDSUBDC_E::MEM. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t addr                  : 64; /**< [127: 64] IOVA of the L2/DRAM address to be modified. [ADDR] must be naturally aligned to
                                                                 the size specified in [DSZ]. If PKO_PF_VF()_GMCTL[BE] is set for this VF, [ADDR]
                                                                 is a big-endian byte pointer. Otherwise, [ADDR] is a little-endian byte pointer. */
#else /* Word 1 - Little Endian */
        uint64_t addr                  : 64; /**< [127: 64] IOVA of the L2/DRAM address to be modified. [ADDR] must be naturally aligned to
                                                                 the size specified in [DSZ]. If PKO_PF_VF()_GMCTL[BE] is set for this VF, [ADDR]
                                                                 is a big-endian byte pointer. Otherwise, [ADDR] is a little-endian byte pointer. */
#endif /* Word 1 - End */
    } s;
    /* struct bdk_pko_send_mem_s_s cn; */
};

/**
 * Structure pko_send_work_s
 *
 * PKO Send Work Subdescriptor Structure
 * This subdescriptor adds work to the SSO. At most one PKO_SEND_WORK_S subdescriptor
 * can exist in the packet descriptor. If a PKO_SEND_WORK_S exists in the packet
 * descriptor, it must be the last subdescriptor. PKO will not initiate the work add
 * for this subdescriptor until after (1) it has completed all L2/DRAM fetches that
 * service all prior PKO_SEND_LINK_S and PKO_SEND_GATHER_S subdescriptors, (2) it has
 * fetched all subdescriptors in the descriptor, and (3) all PKO_SEND_MEM_S[WMEM]=1
 * L2/DRAM updates have completed.
 *
 * Provided the path of descriptors from the DQ through PKO to an output FIFO is
 * unmodified between the descriptors (as should normally be the case, but it is
 * possible for software to change the path), PKO also (1) will submit
 * the SSO add works from all descriptors in the DQ in order, and
 * (2) will not submit an SSO work add until after all prior descriptors
 * in the DQ have completed their PKO_SEND_LINK_S and PKO_SEND_GATHER_S
 * processing, and (3) will not submit an SSO work add until after
 * it has fetched all subdescriptors from prior descriptors in the DQ.
 *
 * When PKO_SEND_HDR[TSO] is set in the descriptor, PKO executes the
 * PKO_SEND_WORK_S work add only while processing the last TSO segment, after
 * processing prior segments.
 */
union bdk_pko_send_work_s
{
    uint64_t u[2];
    struct bdk_pko_send_work_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send work. Enumerated by PKO_SENDSUBDC_E::WORK. */
        uint64_t reserved_49_59        : 11;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_44_47        : 4;
        uint64_t grp                   : 10; /**< [ 43: 34] SSO group. The SSO group number to add work to. Note the upper two bits
                                                                 correspond to a node number. */
        uint64_t tt                    : 2;  /**< [ 33: 32] SSO tag type. The SSO tag type number to add work with. */
        uint64_t tag                   : 32; /**< [ 31:  0] Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0] Reserved. */
        uint64_t tt                    : 2;  /**< [ 33: 32] SSO tag type. The SSO tag type number to add work with. */
        uint64_t grp                   : 10; /**< [ 43: 34] SSO group. The SSO group number to add work to. Note the upper two bits
                                                                 correspond to a node number. */
        uint64_t reserved_44_47        : 4;
        uint64_t p                     : 1;  /**< [ 48: 48] Cacheline CRC, an 8-bit CRC is striped across each cacheline using this bit in
                                                                 each descriptor. */
        uint64_t reserved_49_59        : 11;
        uint64_t subdc                 : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send work. Enumerated by PKO_SENDSUBDC_E::WORK. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t addr                  : 64; /**< [127: 64] IOVA of the work-queue entry to be submitted to the SSO. [ADDR]<63:49> and
                                                                 [ADDR]<2:0> are ignored. */
#else /* Word 1 - Little Endian */
        uint64_t addr                  : 64; /**< [127: 64] IOVA of the work-queue entry to be submitted to the SSO. [ADDR]<63:49> and
                                                                 [ADDR]<2:0> are ignored. */
#endif /* Word 1 - End */
    } s;
    /* struct bdk_pko_send_work_s_s cn; */
};

/**
 * Register (NCB) pko_channel_level
 *
 * PKO PSE Level 2 Channel Level Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_channel_level_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t cc_level              : 1;  /**< [  0:  0](R/W) Channel credit level. Channels can be configured at levels 2 or 3 of the PSE hierarchy.
                                                                 0 = Selects the level-2 as the channel level.
                                                                 1 = Selects the level-3 as the channel level.

                                                                 [CC_LEVEL] determines whether PKO_L3_L2_SQ()_CHANNEL is associated with the L2 SQ's or
                                                                 the L3 SQ's. */
#else /* Word 0 - Little Endian */
        uint64_t cc_level              : 1;  /**< [  0:  0](R/W) Channel credit level. Channels can be configured at levels 2 or 3 of the PSE hierarchy.
                                                                 0 = Selects the level-2 as the channel level.
                                                                 1 = Selects the level-3 as the channel level.

                                                                 [CC_LEVEL] determines whether PKO_L3_L2_SQ()_CHANNEL is associated with the L2 SQ's or
                                                                 the L3 SQ's. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_channel_level_s cn; */
} bdk_pko_channel_level_t;

#define BDK_PKO_CHANNEL_LEVEL BDK_PKO_CHANNEL_LEVEL_FUNC()
static inline uint64_t BDK_PKO_CHANNEL_LEVEL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_CHANNEL_LEVEL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540000800f0ll;
    __bdk_csr_fatal("PKO_CHANNEL_LEVEL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_CHANNEL_LEVEL bdk_pko_channel_level_t
#define bustype_BDK_PKO_CHANNEL_LEVEL BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_CHANNEL_LEVEL "PKO_CHANNEL_LEVEL"
#define device_bar_BDK_PKO_CHANNEL_LEVEL 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_CHANNEL_LEVEL 0
#define arguments_BDK_PKO_CHANNEL_LEVEL -1,-1,-1,-1

/**
 * Register (NCB) pko_const
 *
 * PKO Constants Register
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t pdm_buf_size          : 16; /**< [ 31: 16](RO) Number of bytes in a PDM buffer. */
        uint64_t formats               : 8;  /**< [ 15:  8](RO) Number of PKO_FORMAT()_CTL registers. */
        uint64_t ptgfs                 : 4;  /**< [  7:  4](RO) Number of PKO_PTGF()_CFG registers. */
        uint64_t levels                : 4;  /**< [  3:  0](RO) Number of hierarchical shaping levels in PKO.  See PKO_*_CONST
                                                                 for the number of queues at each level. */
#else /* Word 0 - Little Endian */
        uint64_t levels                : 4;  /**< [  3:  0](RO) Number of hierarchical shaping levels in PKO.  See PKO_*_CONST
                                                                 for the number of queues at each level. */
        uint64_t ptgfs                 : 4;  /**< [  7:  4](RO) Number of PKO_PTGF()_CFG registers. */
        uint64_t formats               : 8;  /**< [ 15:  8](RO) Number of PKO_FORMAT()_CTL registers. */
        uint64_t pdm_buf_size          : 16; /**< [ 31: 16](RO) Number of bytes in a PDM buffer. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_const_s cn; */
} bdk_pko_const_t;

#define BDK_PKO_CONST BDK_PKO_CONST_FUNC()
static inline uint64_t BDK_PKO_CONST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_CONST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000d00010ll;
    __bdk_csr_fatal("PKO_CONST", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_CONST bdk_pko_const_t
#define bustype_BDK_PKO_CONST BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_CONST "PKO_CONST"
#define device_bar_BDK_PKO_CONST 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_CONST 0
#define arguments_BDK_PKO_CONST -1,-1,-1,-1

/**
 * Register (NCB) pko_const1
 *
 * PKO Constants Register 1
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_const1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_const1_s cn; */
} bdk_pko_const1_t;

#define BDK_PKO_CONST1 BDK_PKO_CONST1_FUNC()
static inline uint64_t BDK_PKO_CONST1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_CONST1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000d00018ll;
    __bdk_csr_fatal("PKO_CONST1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_CONST1 bdk_pko_const1_t
#define bustype_BDK_PKO_CONST1 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_CONST1 "PKO_CONST1"
#define device_bar_BDK_PKO_CONST1 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_CONST1 0
#define arguments_BDK_PKO_CONST1 -1,-1,-1,-1

/**
 * Register (NCB) pko_dpfi_ena
 *
 * PKO Descriptor Manager FPA Interface Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dpfi_ena_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Setting this bit enables the PKO to request/return pointers to FPA. This enable must be
                                                                 set after reset so that the PKO can fill its private pointer cache prior to setting the
                                                                 PKO_RDY flag in the PKO_STATUS register. */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Setting this bit enables the PKO to request/return pointers to FPA. This enable must be
                                                                 set after reset so that the PKO can fill its private pointer cache prior to setting the
                                                                 PKO_RDY flag in the PKO_STATUS register. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dpfi_ena_s cn; */
} bdk_pko_dpfi_ena_t;

#define BDK_PKO_DPFI_ENA BDK_PKO_DPFI_ENA_FUNC()
static inline uint64_t BDK_PKO_DPFI_ENA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DPFI_ENA_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000c00018ll;
    __bdk_csr_fatal("PKO_DPFI_ENA", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_DPFI_ENA bdk_pko_dpfi_ena_t
#define bustype_BDK_PKO_DPFI_ENA BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DPFI_ENA "PKO_DPFI_ENA"
#define device_bar_BDK_PKO_DPFI_ENA 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DPFI_ENA 0
#define arguments_BDK_PKO_DPFI_ENA -1,-1,-1,-1

/**
 * Register (NCB) pko_dpfi_flush
 *
 * PKO Descriptor Manager FPA Interface Flush Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dpfi_flush_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t flush_en              : 1;  /**< [  0:  0](R/W) Pointer cache flush enable. When set, this flag commands the DPFI logic to flush all valid
                                                                 pointers from the pointer cache and return them to the FPA. The flush operation is
                                                                 complete when the CACHE_FLUSHED flag in PKO_DPFI_STATUS is set. Clearing the FLUSH_EN flag
                                                                 results in the DPFI reloading its pointer cache. This flush mechanism should only be
                                                                 enabled when the PKO is quiescent and all DQs have been closed. */
#else /* Word 0 - Little Endian */
        uint64_t flush_en              : 1;  /**< [  0:  0](R/W) Pointer cache flush enable. When set, this flag commands the DPFI logic to flush all valid
                                                                 pointers from the pointer cache and return them to the FPA. The flush operation is
                                                                 complete when the CACHE_FLUSHED flag in PKO_DPFI_STATUS is set. Clearing the FLUSH_EN flag
                                                                 results in the DPFI reloading its pointer cache. This flush mechanism should only be
                                                                 enabled when the PKO is quiescent and all DQs have been closed. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dpfi_flush_s cn; */
} bdk_pko_dpfi_flush_t;

#define BDK_PKO_DPFI_FLUSH BDK_PKO_DPFI_FLUSH_FUNC()
static inline uint64_t BDK_PKO_DPFI_FLUSH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DPFI_FLUSH_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000c00008ll;
    __bdk_csr_fatal("PKO_DPFI_FLUSH", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_DPFI_FLUSH bdk_pko_dpfi_flush_t
#define bustype_BDK_PKO_DPFI_FLUSH BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DPFI_FLUSH "PKO_DPFI_FLUSH"
#define device_bar_BDK_PKO_DPFI_FLUSH 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DPFI_FLUSH 0
#define arguments_BDK_PKO_DPFI_FLUSH -1,-1,-1,-1

/**
 * Register (NCB) pko_dpfi_fpa_aura
 *
 * PKO Descriptor Manager FPA Interface Aura Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dpfi_fpa_aura_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t laura                 : 12; /**< [ 11:  0](R/W) FPA guest-aura to use for PKO command buffering allocations and frees. The
                                                                 FPA guest-aura selected by LAURA must correspond to a pool where the buffers (after
                                                                 any FPA_POOL()_CFG[BUF_OFFSET]) are at least of size PKO_CONST[PDM_BUF_SIZE] (4KB). */
#else /* Word 0 - Little Endian */
        uint64_t laura                 : 12; /**< [ 11:  0](R/W) FPA guest-aura to use for PKO command buffering allocations and frees. The
                                                                 FPA guest-aura selected by LAURA must correspond to a pool where the buffers (after
                                                                 any FPA_POOL()_CFG[BUF_OFFSET]) are at least of size PKO_CONST[PDM_BUF_SIZE] (4KB). */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dpfi_fpa_aura_s cn; */
} bdk_pko_dpfi_fpa_aura_t;

#define BDK_PKO_DPFI_FPA_AURA BDK_PKO_DPFI_FPA_AURA_FUNC()
static inline uint64_t BDK_PKO_DPFI_FPA_AURA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DPFI_FPA_AURA_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000c00010ll;
    __bdk_csr_fatal("PKO_DPFI_FPA_AURA", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_DPFI_FPA_AURA bdk_pko_dpfi_fpa_aura_t
#define bustype_BDK_PKO_DPFI_FPA_AURA BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DPFI_FPA_AURA "PKO_DPFI_FPA_AURA"
#define device_bar_BDK_PKO_DPFI_FPA_AURA 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DPFI_FPA_AURA 0
#define arguments_BDK_PKO_DPFI_FPA_AURA -1,-1,-1,-1

/**
 * Register (NCB) pko_dpfi_gmctl
 *
 * PKO Descriptor Manager FPA Guest Machine Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dpfi_gmctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Guest machine identifier. The GMID to send to FPA for descriptor buffer
                                                                 allocations and frees.
                                                                 Must be nonzero or FPA will drop requests; see FPA_PF_MAP().

                                                                 See also PKO_PF_VF()_GMCTL[GMID]. */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Guest machine identifier. The GMID to send to FPA for descriptor buffer
                                                                 allocations and frees.
                                                                 Must be nonzero or FPA will drop requests; see FPA_PF_MAP().

                                                                 See also PKO_PF_VF()_GMCTL[GMID]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dpfi_gmctl_s cn; */
} bdk_pko_dpfi_gmctl_t;

#define BDK_PKO_DPFI_GMCTL BDK_PKO_DPFI_GMCTL_FUNC()
static inline uint64_t BDK_PKO_DPFI_GMCTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DPFI_GMCTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000c00020ll;
    __bdk_csr_fatal("PKO_DPFI_GMCTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_DPFI_GMCTL bdk_pko_dpfi_gmctl_t
#define bustype_BDK_PKO_DPFI_GMCTL BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DPFI_GMCTL "PKO_DPFI_GMCTL"
#define device_bar_BDK_PKO_DPFI_GMCTL 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DPFI_GMCTL 0
#define arguments_BDK_PKO_DPFI_GMCTL -1,-1,-1,-1

/**
 * Register (NCB) pko_dpfi_status
 *
 * PKO Descriptor Manager FPA Interface Status Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dpfi_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ptr_cnt               : 32; /**< [ 63: 32](RO/H) The number of pointers currently in use for storing descriptors and meta-packets plus
                                                                 those available in the DPFI pointer cache. */
        uint64_t reserved_27_31        : 5;
        uint64_t xpd_fif_cnt           : 4;  /**< [ 26: 23](RO/H) XPD FIFO count. This FIFO has 8 entries and is used to hold pointers that are actively
                                                                 being returned to the FPA. Typically, the value of this counter is zero. Should the
                                                                 count be nonzero for a prolonged period it would indicate that the FPA is delayed in
                                                                 accepting pointers back from the PKO. */
        uint64_t dalc_fif_cnt          : 4;  /**< [ 22: 19](RO/H) Deallocation FIFO count. This FIFO has 8 entries and is used to buffer pointers that are
                                                                 being returned to the DPFI by the PKO PDM. The PKO does not immediately return these
                                                                 pointers to the FPA but instead holds them and uses them to replenish the pointer
                                                                 allocation FIFO saving an access to the FPA. Should the deallocation FIFO become full
                                                                 the next pointer pushed into it will push out the oldest pointer and this overflow will
                                                                 be transferred to the XPD FIFO and a pointer return request made to the FPA. Normally,
                                                                 the deallocation FIFO is empty or near empty. This FIFO can be drained and all pointers
                                                                 returned to the FPA by setting the FLUSH_EN bit in the PKO_DPFI_FLUSH CSR. When the
                                                                 flush is complete the CACHE_FLUSHED flag will be set in the PKO_DPFI_STATUS CSR and the
                                                                 DALC_FIF_CNT will be zero. */
        uint64_t alc_fif_cnt           : 5;  /**< [ 18: 14](RO/H) Allocation FIFO count. This FIFO has 16 entries and acts as a pointer prefetch buffer.
                                                                 The DPFI attempts to keep this FIFO full at all times. Out of reset, the PKO requests
                                                                 pointers from the FPA to fill this FIFO. The PKO_READY flag will not be asserted until
                                                                 the the Alloc FIFO is full. Once the PKO is enabled, SEND_PACKET commands that are
                                                                 received by the PKO and require pointers are serviced from this FIFO. Once a pointer
                                                                 is popped, a request is made to the FPA to replenish it. The FIFO provides an elastic
                                                                 store of pointers to handle the occasional bursts of pointer requests from PKO without
                                                                 incurring the larger FPA latency. The count should normally read 16 and prolonged
                                                                 periods where the FIFO is less than full indicates that the FPA is delayed in providing
                                                                 pointers to the PKO. This FIFO can be drained and all pointers returned to the FPA by
                                                                 setting the FLUSH_EN bit in the PKO_DPFI_FLUSH CSR. When the flush is complete the
                                                                 CACHE_FLUSHED flag will be set in the PKO_DPFI_STATUS CSR and the ALC_FIF_CNT will
                                                                 be zero. */
        uint64_t reserved_13           : 1;
        uint64_t isrd_ptr1_rtn_full    : 1;  /**< [ 12: 12](RO/H) ISRD pointer return register 1 contains a valid pointer. */
        uint64_t isrd_ptr0_rtn_full    : 1;  /**< [ 11: 11](RO/H) ISRD pointer return register 0 contains a valid pointer. */
        uint64_t isrm_ptr1_rtn_full    : 1;  /**< [ 10: 10](RO/H) ISRM pointer return register 1 contains a valid pointer. */
        uint64_t isrm_ptr0_rtn_full    : 1;  /**< [  9:  9](RO/H) ISRM pointer return register 0 contains a valid pointer. */
        uint64_t isrd_ptr1_val         : 1;  /**< [  8:  8](RO/H) ISRD pointer register 1 contains a valid pointer. */
        uint64_t isrd_ptr0_val         : 1;  /**< [  7:  7](RO/H) ISRD pointer register 0 contains a valid pointer. */
        uint64_t isrm_ptr1_val         : 1;  /**< [  6:  6](RO/H) ISRM pointer register 1 contains a valid pointer. */
        uint64_t isrm_ptr0_val         : 1;  /**< [  5:  5](RO/H) ISRM pointer register 0 contains a valid pointer. */
        uint64_t ptr_req_pend          : 1;  /**< [  4:  4](RO/H) DPFI has pointer requests to FPA pending. */
        uint64_t ptr_rtn_pend          : 1;  /**< [  3:  3](RO/H) DPFI has pointer returns to FPA pending. */
        uint64_t fpa_empty             : 1;  /**< [  2:  2](RO/H) FPA empty status:
                                                                 0 = FPA is providing pointers when requested.
                                                                 1 = FPA responded to pointer request with 'no pointers available'. */
        uint64_t dpfi_empty            : 1;  /**< [  1:  1](RO/H) DPFI pointer cache is empty. */
        uint64_t cache_flushed         : 1;  /**< [  0:  0](RO/H) Cache flushed:
                                                                 0 = Cache flush not enabled or in-progress.
                                                                 1 = Cache flush has completed. PKO_DPFI_STATUS[PTR_CNT] will read zero if all outstanding
                                                                 pointers have been returned to the FPA. */
#else /* Word 0 - Little Endian */
        uint64_t cache_flushed         : 1;  /**< [  0:  0](RO/H) Cache flushed:
                                                                 0 = Cache flush not enabled or in-progress.
                                                                 1 = Cache flush has completed. PKO_DPFI_STATUS[PTR_CNT] will read zero if all outstanding
                                                                 pointers have been returned to the FPA. */
        uint64_t dpfi_empty            : 1;  /**< [  1:  1](RO/H) DPFI pointer cache is empty. */
        uint64_t fpa_empty             : 1;  /**< [  2:  2](RO/H) FPA empty status:
                                                                 0 = FPA is providing pointers when requested.
                                                                 1 = FPA responded to pointer request with 'no pointers available'. */
        uint64_t ptr_rtn_pend          : 1;  /**< [  3:  3](RO/H) DPFI has pointer returns to FPA pending. */
        uint64_t ptr_req_pend          : 1;  /**< [  4:  4](RO/H) DPFI has pointer requests to FPA pending. */
        uint64_t isrm_ptr0_val         : 1;  /**< [  5:  5](RO/H) ISRM pointer register 0 contains a valid pointer. */
        uint64_t isrm_ptr1_val         : 1;  /**< [  6:  6](RO/H) ISRM pointer register 1 contains a valid pointer. */
        uint64_t isrd_ptr0_val         : 1;  /**< [  7:  7](RO/H) ISRD pointer register 0 contains a valid pointer. */
        uint64_t isrd_ptr1_val         : 1;  /**< [  8:  8](RO/H) ISRD pointer register 1 contains a valid pointer. */
        uint64_t isrm_ptr0_rtn_full    : 1;  /**< [  9:  9](RO/H) ISRM pointer return register 0 contains a valid pointer. */
        uint64_t isrm_ptr1_rtn_full    : 1;  /**< [ 10: 10](RO/H) ISRM pointer return register 1 contains a valid pointer. */
        uint64_t isrd_ptr0_rtn_full    : 1;  /**< [ 11: 11](RO/H) ISRD pointer return register 0 contains a valid pointer. */
        uint64_t isrd_ptr1_rtn_full    : 1;  /**< [ 12: 12](RO/H) ISRD pointer return register 1 contains a valid pointer. */
        uint64_t reserved_13           : 1;
        uint64_t alc_fif_cnt           : 5;  /**< [ 18: 14](RO/H) Allocation FIFO count. This FIFO has 16 entries and acts as a pointer prefetch buffer.
                                                                 The DPFI attempts to keep this FIFO full at all times. Out of reset, the PKO requests
                                                                 pointers from the FPA to fill this FIFO. The PKO_READY flag will not be asserted until
                                                                 the the Alloc FIFO is full. Once the PKO is enabled, SEND_PACKET commands that are
                                                                 received by the PKO and require pointers are serviced from this FIFO. Once a pointer
                                                                 is popped, a request is made to the FPA to replenish it. The FIFO provides an elastic
                                                                 store of pointers to handle the occasional bursts of pointer requests from PKO without
                                                                 incurring the larger FPA latency. The count should normally read 16 and prolonged
                                                                 periods where the FIFO is less than full indicates that the FPA is delayed in providing
                                                                 pointers to the PKO. This FIFO can be drained and all pointers returned to the FPA by
                                                                 setting the FLUSH_EN bit in the PKO_DPFI_FLUSH CSR. When the flush is complete the
                                                                 CACHE_FLUSHED flag will be set in the PKO_DPFI_STATUS CSR and the ALC_FIF_CNT will
                                                                 be zero. */
        uint64_t dalc_fif_cnt          : 4;  /**< [ 22: 19](RO/H) Deallocation FIFO count. This FIFO has 8 entries and is used to buffer pointers that are
                                                                 being returned to the DPFI by the PKO PDM. The PKO does not immediately return these
                                                                 pointers to the FPA but instead holds them and uses them to replenish the pointer
                                                                 allocation FIFO saving an access to the FPA. Should the deallocation FIFO become full
                                                                 the next pointer pushed into it will push out the oldest pointer and this overflow will
                                                                 be transferred to the XPD FIFO and a pointer return request made to the FPA. Normally,
                                                                 the deallocation FIFO is empty or near empty. This FIFO can be drained and all pointers
                                                                 returned to the FPA by setting the FLUSH_EN bit in the PKO_DPFI_FLUSH CSR. When the
                                                                 flush is complete the CACHE_FLUSHED flag will be set in the PKO_DPFI_STATUS CSR and the
                                                                 DALC_FIF_CNT will be zero. */
        uint64_t xpd_fif_cnt           : 4;  /**< [ 26: 23](RO/H) XPD FIFO count. This FIFO has 8 entries and is used to hold pointers that are actively
                                                                 being returned to the FPA. Typically, the value of this counter is zero. Should the
                                                                 count be nonzero for a prolonged period it would indicate that the FPA is delayed in
                                                                 accepting pointers back from the PKO. */
        uint64_t reserved_27_31        : 5;
        uint64_t ptr_cnt               : 32; /**< [ 63: 32](RO/H) The number of pointers currently in use for storing descriptors and meta-packets plus
                                                                 those available in the DPFI pointer cache. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dpfi_status_s cn; */
} bdk_pko_dpfi_status_t;

#define BDK_PKO_DPFI_STATUS BDK_PKO_DPFI_STATUS_FUNC()
static inline uint64_t BDK_PKO_DPFI_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DPFI_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000c00000ll;
    __bdk_csr_fatal("PKO_DPFI_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_DPFI_STATUS bdk_pko_dpfi_status_t
#define bustype_BDK_PKO_DPFI_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DPFI_STATUS "PKO_DPFI_STATUS"
#define device_bar_BDK_PKO_DPFI_STATUS 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DPFI_STATUS 0
#define arguments_BDK_PKO_DPFI_STATUS -1,-1,-1,-1

/**
 * Register (NCB) pko_dq#_bytes
 *
 * PKO PSE Descriptor Queue Sent Bytes Register
 * This register has the same bit fields as PKO_L1_SQ()_GREEN_BYTES.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_bytes_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t count                 : 48; /**< [ 47:  0](R/W/H) Count. The running count of bytes. Note that this count wraps. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 48; /**< [ 47:  0](R/W/H) Count. The running count of bytes. Note that this count wraps. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_bytes_s cn; */
} bdk_pko_dqx_bytes_t;

static inline uint64_t BDK_PKO_DQX_BYTES(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_BYTES(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x8540000000d8ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_BYTES", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_BYTES(a) bdk_pko_dqx_bytes_t
#define bustype_BDK_PKO_DQX_BYTES(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_BYTES(a) "PKO_DQX_BYTES"
#define device_bar_BDK_PKO_DQX_BYTES(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_BYTES(a) (a)
#define arguments_BDK_PKO_DQX_BYTES(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_cir
 *
 * PKO PSE Descriptor Queue Shaping Queue Committed Information Rate Register
 * This register has the same bit fields as PKO_L1_SQ()_CIR.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_cir_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_41_63        : 23;
        uint64_t burst_exponent        : 4;  /**< [ 40: 37](R/W) Burst exponent. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t burst_mantissa        : 8;  /**< [ 36: 29](R/W) Burst mantissa. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t reserved_17_28        : 12;
        uint64_t rate_divider_exponent : 4;  /**< [ 16: 13](R/W) Rate divider exponent. This 4-bit base-2 exponent is used to divide the credit rate by
                                                                 specifying the number of time-wheel turns required before the accumulator is increased.
                                                                 [RATE_DIVIDER_EXPONENT] should be used to specify data rates lower than ~10 Kbps and
                                                                 [RATE_EXPONENT] should be set to zero whenever it is used.

                                                                 The rate count = (1 << [RATE_DIVIDER_EXPONENT]). The supported range for
                                                                 [RATE_DIVIDER_EXPONENT] is 0 to 12. Programmed values greater than 12 are treated as 12.

                                                                 Note that for the L1-SQs, a time-wheel turn is 96 clocks (SCLK). For the other levels a
                                                                 time-wheel turn is 768 clocks (SCLK).

                                                                 For L1_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 96) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1
                                                                 <<[RATE_DIVIDER_EXPONENT])

                                                                 For L[5:2]_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 768) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1 <<
                                                                 [RATE_DIVIDER_EXPONENT]) */
        uint64_t rate_exponent         : 4;  /**< [ 12:  9](R/W) Rate exponent. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT].
                                                                 [RATE_EXPONENT] should be used to specify data rates higher than ~10 Kbps and
                                                                 [RATE_DIVIDER_EXPONENT] should be set to zero whenever it is nonzero. */
        uint64_t rate_mantissa         : 8;  /**< [  8:  1](R/W) Rate mantissa. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT]. */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable. Enables CIR shaping. */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable. Enables CIR shaping. */
        uint64_t rate_mantissa         : 8;  /**< [  8:  1](R/W) Rate mantissa. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT]. */
        uint64_t rate_exponent         : 4;  /**< [ 12:  9](R/W) Rate exponent. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT].
                                                                 [RATE_EXPONENT] should be used to specify data rates higher than ~10 Kbps and
                                                                 [RATE_DIVIDER_EXPONENT] should be set to zero whenever it is nonzero. */
        uint64_t rate_divider_exponent : 4;  /**< [ 16: 13](R/W) Rate divider exponent. This 4-bit base-2 exponent is used to divide the credit rate by
                                                                 specifying the number of time-wheel turns required before the accumulator is increased.
                                                                 [RATE_DIVIDER_EXPONENT] should be used to specify data rates lower than ~10 Kbps and
                                                                 [RATE_EXPONENT] should be set to zero whenever it is used.

                                                                 The rate count = (1 << [RATE_DIVIDER_EXPONENT]). The supported range for
                                                                 [RATE_DIVIDER_EXPONENT] is 0 to 12. Programmed values greater than 12 are treated as 12.

                                                                 Note that for the L1-SQs, a time-wheel turn is 96 clocks (SCLK). For the other levels a
                                                                 time-wheel turn is 768 clocks (SCLK).

                                                                 For L1_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 96) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1
                                                                 <<[RATE_DIVIDER_EXPONENT])

                                                                 For L[5:2]_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 768) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1 <<
                                                                 [RATE_DIVIDER_EXPONENT]) */
        uint64_t reserved_17_28        : 12;
        uint64_t burst_mantissa        : 8;  /**< [ 36: 29](R/W) Burst mantissa. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t burst_exponent        : 4;  /**< [ 40: 37](R/W) Burst exponent. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t reserved_41_63        : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_cir_s cn; */
} bdk_pko_dqx_cir_t;

static inline uint64_t BDK_PKO_DQX_CIR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_CIR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000280018ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_CIR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_CIR(a) bdk_pko_dqx_cir_t
#define bustype_BDK_PKO_DQX_CIR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_CIR(a) "PKO_DQX_CIR"
#define device_bar_BDK_PKO_DQX_CIR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_CIR(a) (a)
#define arguments_BDK_PKO_DQX_CIR(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_dropped_bytes
 *
 * PKO PSE Descriptor Queue Dropped Bytes Register
 * This register has the same bit fields as PKO_L1_SQ()_GREEN_BYTES.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_dropped_bytes_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t count                 : 48; /**< [ 47:  0](R/W/H) Count. The running count of bytes. Note that this count wraps. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 48; /**< [ 47:  0](R/W/H) Count. The running count of bytes. Note that this count wraps. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_dropped_bytes_s cn; */
} bdk_pko_dqx_dropped_bytes_t;

static inline uint64_t BDK_PKO_DQX_DROPPED_BYTES(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_DROPPED_BYTES(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x8540000000c8ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_DROPPED_BYTES", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_DROPPED_BYTES(a) bdk_pko_dqx_dropped_bytes_t
#define bustype_BDK_PKO_DQX_DROPPED_BYTES(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_DROPPED_BYTES(a) "PKO_DQX_DROPPED_BYTES"
#define device_bar_BDK_PKO_DQX_DROPPED_BYTES(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_DROPPED_BYTES(a) (a)
#define arguments_BDK_PKO_DQX_DROPPED_BYTES(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_dropped_packets
 *
 * PKO PSE Descriptor Queue Dropped Packets Register
 * This register has the same bit fields as PKO_L1_SQ()_GREEN_PACKETS.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_dropped_packets_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t count                 : 40; /**< [ 39:  0](R/W/H) Count. The running count of packets. Note that this count wraps. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 40; /**< [ 39:  0](R/W/H) Count. The running count of packets. Note that this count wraps. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_dropped_packets_s cn; */
} bdk_pko_dqx_dropped_packets_t;

static inline uint64_t BDK_PKO_DQX_DROPPED_PACKETS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_DROPPED_PACKETS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x8540000000c0ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_DROPPED_PACKETS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_DROPPED_PACKETS(a) bdk_pko_dqx_dropped_packets_t
#define bustype_BDK_PKO_DQX_DROPPED_PACKETS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_DROPPED_PACKETS(a) "PKO_DQX_DROPPED_PACKETS"
#define device_bar_BDK_PKO_DQX_DROPPED_PACKETS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_DROPPED_PACKETS(a) (a)
#define arguments_BDK_PKO_DQX_DROPPED_PACKETS(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_fifo
 *
 * INTERNAL: PKO PSE Descriptor Queue FIFO State Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_fifo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_15_63        : 49;
        uint64_t p_con                 : 1;  /**< [ 14: 14](RO/H) parent connect. Asserted when DQ is connected to its parent. */
        uint64_t head                  : 7;  /**< [ 13:  7](RO/H) DQ FIFO head pointer. */
        uint64_t tail                  : 7;  /**< [  6:  0](RO/H) DQ FIFO tail pointer. */
#else /* Word 0 - Little Endian */
        uint64_t tail                  : 7;  /**< [  6:  0](RO/H) DQ FIFO tail pointer. */
        uint64_t head                  : 7;  /**< [ 13:  7](RO/H) DQ FIFO head pointer. */
        uint64_t p_con                 : 1;  /**< [ 14: 14](RO/H) parent connect. Asserted when DQ is connected to its parent. */
        uint64_t reserved_15_63        : 49;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_fifo_s cn; */
} bdk_pko_dqx_fifo_t;

static inline uint64_t BDK_PKO_DQX_FIFO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_FIFO(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000300078ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_FIFO", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_FIFO(a) bdk_pko_dqx_fifo_t
#define bustype_BDK_PKO_DQX_FIFO(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_FIFO(a) "PKO_DQX_FIFO"
#define device_bar_BDK_PKO_DQX_FIFO(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_FIFO(a) (a)
#define arguments_BDK_PKO_DQX_FIFO(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_packets
 *
 * PKO PSE Descriptor Queue Sent Packets Register
 * This register has the same bit fields as PKO_L1_SQ()_GREEN_PACKETS.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_packets_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t count                 : 40; /**< [ 39:  0](R/W/H) Count. The running count of packets. Note that this count wraps. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 40; /**< [ 39:  0](R/W/H) Count. The running count of packets. Note that this count wraps. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_packets_s cn; */
} bdk_pko_dqx_packets_t;

static inline uint64_t BDK_PKO_DQX_PACKETS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_PACKETS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x8540000000d0ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_PACKETS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_PACKETS(a) bdk_pko_dqx_packets_t
#define bustype_BDK_PKO_DQX_PACKETS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_PACKETS(a) "PKO_DQX_PACKETS"
#define device_bar_BDK_PKO_DQX_PACKETS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_PACKETS(a) (a)
#define arguments_BDK_PKO_DQX_PACKETS(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_pick
 *
 * PKO PSE Descriptor Queue Shaping Queue Packet Pick State Debug Register
 * This CSR contains the meta for the DQ, and is for debug and reconfiguration
 * only and should never be written. See also PKO_META_DESC_S.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_pick_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dq                    : 10; /**< [ 63: 54](R/W/H) Descriptor queue. Index of originating descriptor queue. */
        uint64_t color                 : 2;  /**< [ 53: 52](R/W/H) See PKO_COLORRESULT_E. */
        uint64_t child                 : 10; /**< [ 51: 42](R/W/H) Child index. When the C_CON bit of this result is set, indicating that this result is
                                                                 connected in a flow that extends through the child result, this is the index of that child
                                                                 result. */
        uint64_t bubble                : 1;  /**< [ 41: 41](R/W/H) This metapacket is a fake passed forward after a prune. */
        uint64_t p_con                 : 1;  /**< [ 40: 40](R/W/H) Parent connected flag. This pick has more picks in front of it. */
        uint64_t c_con                 : 1;  /**< [ 39: 39](R/W/H) Child connected flag. This pick has more picks behind it. */
        uint64_t uid                   : 7;  /**< [ 38: 32](R/W/H) Unique ID. 7-bit unique value assigned at the DQ level, increments for each packet. */
        uint64_t jump                  : 1;  /**< [ 31: 31](R/W/H) Set when the corresponding descriptor contains a PKO_SEND_JUMP_S.  See also
                                                                 PKO_META_DESC_S[JUMP]. */
        uint64_t fpd                   : 1;  /**< [ 30: 30](R/W/H) First packet descriptor. Set when corresponding descriptor is the first in a cacheline.
                                                                 See also PKO_META_DESC_S[FPD]. */
        uint64_t ds                    : 1;  /**< [ 29: 29](R/W/H) PKO_SEND_HDR_S[DS] from the corresponding descriptor. Should always be zero.
                                                                 See also PKO_META_DESC_S[DS]. */
        uint64_t adjust                : 9;  /**< [ 28: 20](R/W/H) When [ADJUST] is 0x100, it indicates that this CSR does not contain a valid meta,
                                                                 and all other fields in this CSR are invalid and shouldn't be used.

                                                                 When [ADJUST] is not 0x100, it is the PKO_SEND_HDR_S[SHP_CHG] for the
                                                                 packet. See also PKO_META_DESC_S[ADJUST]. */
        uint64_t pir_dis               : 1;  /**< [ 19: 19](R/W/H) PIR disable. Peak shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or CIR_ONLY
                                                                 (i.e. [PIR_DIS]=PKO_SEND_EXT_S[COL<1>]). Zero if a PKO_SEND_EXT_S is not present in the
                                                                 corresponding descriptor. See PKO_COLORALG_E. [PIR_DIS] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[COL<1>]. */
        uint64_t cir_dis               : 1;  /**< [ 18: 18](R/W/H) CIR disable. Committed shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or
                                                                 PIR_ONLY (i.e. [CIR_DIS]=PKO_SEND_EXT_S[COL<0>]). Zero if a PKO_SEND_EXT_S is not
                                                                 present in the corresponding descriptor. See PKO_COLORALG_E. [CIR_DIS] is used by the
                                                                 DQ through L2 shapers, but not used by the L1 rate limiters. See also
                                                                 PKO_META_DESC_S[COL<0>]. */
        uint64_t red_algo_override     : 2;  /**< [ 17: 16](R/W/H) PKO_SEND_HDR_S[SHP_RA] from the corresponding packet descriptor.
                                                                 [RED_ALGO_OVERRIDE] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[RA]. */
        uint64_t length                : 16; /**< [ 15:  0](R/W/H) Meta packet length. Generally, the size of the outgoing packet
                                                                 including pad, but excluding FCS and preamble.

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] clear:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(PKO_SEND_HDR_S[TOTAL], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               PKO_SEND_HDR_S[TOTAL]

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] set:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(FPS+PKO_SEND_HDR_S[TSO_SB], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               (FPS+PKO_SEND_HDR_S[TSO_SB])

                                                                 d is the DQ that the PKO SEND used. FPS is the number of payload bytes
                                                                 in the TSO segment. See also PKO_META_DESC_S[LENGTH]. */
#else /* Word 0 - Little Endian */
        uint64_t length                : 16; /**< [ 15:  0](R/W/H) Meta packet length. Generally, the size of the outgoing packet
                                                                 including pad, but excluding FCS and preamble.

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] clear:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(PKO_SEND_HDR_S[TOTAL], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               PKO_SEND_HDR_S[TOTAL]

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] set:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(FPS+PKO_SEND_HDR_S[TSO_SB], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               (FPS+PKO_SEND_HDR_S[TSO_SB])

                                                                 d is the DQ that the PKO SEND used. FPS is the number of payload bytes
                                                                 in the TSO segment. See also PKO_META_DESC_S[LENGTH]. */
        uint64_t red_algo_override     : 2;  /**< [ 17: 16](R/W/H) PKO_SEND_HDR_S[SHP_RA] from the corresponding packet descriptor.
                                                                 [RED_ALGO_OVERRIDE] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[RA]. */
        uint64_t cir_dis               : 1;  /**< [ 18: 18](R/W/H) CIR disable. Committed shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or
                                                                 PIR_ONLY (i.e. [CIR_DIS]=PKO_SEND_EXT_S[COL<0>]). Zero if a PKO_SEND_EXT_S is not
                                                                 present in the corresponding descriptor. See PKO_COLORALG_E. [CIR_DIS] is used by the
                                                                 DQ through L2 shapers, but not used by the L1 rate limiters. See also
                                                                 PKO_META_DESC_S[COL<0>]. */
        uint64_t pir_dis               : 1;  /**< [ 19: 19](R/W/H) PIR disable. Peak shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or CIR_ONLY
                                                                 (i.e. [PIR_DIS]=PKO_SEND_EXT_S[COL<1>]). Zero if a PKO_SEND_EXT_S is not present in the
                                                                 corresponding descriptor. See PKO_COLORALG_E. [PIR_DIS] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[COL<1>]. */
        uint64_t adjust                : 9;  /**< [ 28: 20](R/W/H) When [ADJUST] is 0x100, it indicates that this CSR does not contain a valid meta,
                                                                 and all other fields in this CSR are invalid and shouldn't be used.

                                                                 When [ADJUST] is not 0x100, it is the PKO_SEND_HDR_S[SHP_CHG] for the
                                                                 packet. See also PKO_META_DESC_S[ADJUST]. */
        uint64_t ds                    : 1;  /**< [ 29: 29](R/W/H) PKO_SEND_HDR_S[DS] from the corresponding descriptor. Should always be zero.
                                                                 See also PKO_META_DESC_S[DS]. */
        uint64_t fpd                   : 1;  /**< [ 30: 30](R/W/H) First packet descriptor. Set when corresponding descriptor is the first in a cacheline.
                                                                 See also PKO_META_DESC_S[FPD]. */
        uint64_t jump                  : 1;  /**< [ 31: 31](R/W/H) Set when the corresponding descriptor contains a PKO_SEND_JUMP_S.  See also
                                                                 PKO_META_DESC_S[JUMP]. */
        uint64_t uid                   : 7;  /**< [ 38: 32](R/W/H) Unique ID. 7-bit unique value assigned at the DQ level, increments for each packet. */
        uint64_t c_con                 : 1;  /**< [ 39: 39](R/W/H) Child connected flag. This pick has more picks behind it. */
        uint64_t p_con                 : 1;  /**< [ 40: 40](R/W/H) Parent connected flag. This pick has more picks in front of it. */
        uint64_t bubble                : 1;  /**< [ 41: 41](R/W/H) This metapacket is a fake passed forward after a prune. */
        uint64_t child                 : 10; /**< [ 51: 42](R/W/H) Child index. When the C_CON bit of this result is set, indicating that this result is
                                                                 connected in a flow that extends through the child result, this is the index of that child
                                                                 result. */
        uint64_t color                 : 2;  /**< [ 53: 52](R/W/H) See PKO_COLORRESULT_E. */
        uint64_t dq                    : 10; /**< [ 63: 54](R/W/H) Descriptor queue. Index of originating descriptor queue. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_pick_s cn; */
} bdk_pko_dqx_pick_t;

static inline uint64_t BDK_PKO_DQX_PICK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_PICK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000300070ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_PICK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_PICK(a) bdk_pko_dqx_pick_t
#define bustype_BDK_PKO_DQX_PICK(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_PICK(a) "PKO_DQX_PICK"
#define device_bar_BDK_PKO_DQX_PICK(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_PICK(a) (a)
#define arguments_BDK_PKO_DQX_PICK(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_pir
 *
 * PKO PSE Descriptor Queue Shaping Queue Peak Information Rate Register
 * This register has the same bit fields as PKO_L1_SQ()_CIR.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_pir_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_41_63        : 23;
        uint64_t burst_exponent        : 4;  /**< [ 40: 37](R/W) Burst exponent. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t burst_mantissa        : 8;  /**< [ 36: 29](R/W) Burst mantissa. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t reserved_17_28        : 12;
        uint64_t rate_divider_exponent : 4;  /**< [ 16: 13](R/W) Rate divider exponent. This 4-bit base-2 exponent is used to divide the credit rate by
                                                                 specifying the number of time-wheel turns required before the accumulator is increased.
                                                                 [RATE_DIVIDER_EXPONENT] should be used to specify data rates lower than ~10 Kbps and
                                                                 [RATE_EXPONENT] should be set to zero whenever it is used.

                                                                 The rate count = (1 << [RATE_DIVIDER_EXPONENT]). The supported range for
                                                                 [RATE_DIVIDER_EXPONENT] is 0 to 12. Programmed values greater than 12 are treated as 12.

                                                                 Note that for the L1-SQs, a time-wheel turn is 96 clocks (SCLK). For the other levels a
                                                                 time-wheel turn is 768 clocks (SCLK).

                                                                 For L1_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 96) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1
                                                                 <<[RATE_DIVIDER_EXPONENT])

                                                                 For L[5:2]_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 768) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1 <<
                                                                 [RATE_DIVIDER_EXPONENT]) */
        uint64_t rate_exponent         : 4;  /**< [ 12:  9](R/W) Rate exponent. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT].
                                                                 [RATE_EXPONENT] should be used to specify data rates higher than ~10 Kbps and
                                                                 [RATE_DIVIDER_EXPONENT] should be set to zero whenever it is nonzero. */
        uint64_t rate_mantissa         : 8;  /**< [  8:  1](R/W) Rate mantissa. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT]. */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable. Enables CIR shaping. */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable. Enables CIR shaping. */
        uint64_t rate_mantissa         : 8;  /**< [  8:  1](R/W) Rate mantissa. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT]. */
        uint64_t rate_exponent         : 4;  /**< [ 12:  9](R/W) Rate exponent. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT].
                                                                 [RATE_EXPONENT] should be used to specify data rates higher than ~10 Kbps and
                                                                 [RATE_DIVIDER_EXPONENT] should be set to zero whenever it is nonzero. */
        uint64_t rate_divider_exponent : 4;  /**< [ 16: 13](R/W) Rate divider exponent. This 4-bit base-2 exponent is used to divide the credit rate by
                                                                 specifying the number of time-wheel turns required before the accumulator is increased.
                                                                 [RATE_DIVIDER_EXPONENT] should be used to specify data rates lower than ~10 Kbps and
                                                                 [RATE_EXPONENT] should be set to zero whenever it is used.

                                                                 The rate count = (1 << [RATE_DIVIDER_EXPONENT]). The supported range for
                                                                 [RATE_DIVIDER_EXPONENT] is 0 to 12. Programmed values greater than 12 are treated as 12.

                                                                 Note that for the L1-SQs, a time-wheel turn is 96 clocks (SCLK). For the other levels a
                                                                 time-wheel turn is 768 clocks (SCLK).

                                                                 For L1_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 96) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1
                                                                 <<[RATE_DIVIDER_EXPONENT])

                                                                 For L[5:2]_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 768) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1 <<
                                                                 [RATE_DIVIDER_EXPONENT]) */
        uint64_t reserved_17_28        : 12;
        uint64_t burst_mantissa        : 8;  /**< [ 36: 29](R/W) Burst mantissa. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t burst_exponent        : 4;  /**< [ 40: 37](R/W) Burst exponent. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t reserved_41_63        : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_pir_s cn; */
} bdk_pko_dqx_pir_t;

static inline uint64_t BDK_PKO_DQX_PIR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_PIR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000280020ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_PIR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_PIR(a) bdk_pko_dqx_pir_t
#define bustype_BDK_PKO_DQX_PIR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_PIR(a) "PKO_DQX_PIR"
#define device_bar_BDK_PKO_DQX_PIR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_PIR(a) (a)
#define arguments_BDK_PKO_DQX_PIR(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_pointers
 *
 * INTERNAL: PKO PSE Descriptor Queue Linked List Pointers Debug Register
 *
 * This register has the same bit fields as PKO_L3_SQ(0..255)_POINTERS.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_pointers_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t prev                  : 8;  /**< [ 23: 16](R/W/H) Previous pointer. The linked-list previous pointer. */
        uint64_t reserved_8_15         : 8;
        uint64_t next                  : 8;  /**< [  7:  0](R/W/H) Next pointer. The linked-list next pointer. */
#else /* Word 0 - Little Endian */
        uint64_t next                  : 8;  /**< [  7:  0](R/W/H) Next pointer. The linked-list next pointer. */
        uint64_t reserved_8_15         : 8;
        uint64_t prev                  : 8;  /**< [ 23: 16](R/W/H) Previous pointer. The linked-list previous pointer. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_pointers_s cn; */
} bdk_pko_dqx_pointers_t;

static inline uint64_t BDK_PKO_DQX_POINTERS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_POINTERS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000280078ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_POINTERS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_POINTERS(a) bdk_pko_dqx_pointers_t
#define bustype_BDK_PKO_DQX_POINTERS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_POINTERS(a) "PKO_DQX_POINTERS"
#define device_bar_BDK_PKO_DQX_POINTERS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_POINTERS(a) (a)
#define arguments_BDK_PKO_DQX_POINTERS(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_sched_state
 *
 * PKO PSE Descriptor Queue Scheduling Control State Register
 * This register has the same bit fields as PKO_L2_SQ()_SCHED_STATE.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_sched_state_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_25_63        : 39;
        uint64_t rr_count              : 25; /**< [ 24:  0](R/W/H) Round-robin (DWRR) deficit counter. A 25-bit signed integer count. For diagnostic use. */
#else /* Word 0 - Little Endian */
        uint64_t rr_count              : 25; /**< [ 24:  0](R/W/H) Round-robin (DWRR) deficit counter. A 25-bit signed integer count. For diagnostic use. */
        uint64_t reserved_25_63        : 39;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_sched_state_s cn; */
} bdk_pko_dqx_sched_state_t;

static inline uint64_t BDK_PKO_DQX_SCHED_STATE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_SCHED_STATE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000280028ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_SCHED_STATE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_SCHED_STATE(a) bdk_pko_dqx_sched_state_t
#define bustype_BDK_PKO_DQX_SCHED_STATE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_SCHED_STATE(a) "PKO_DQX_SCHED_STATE"
#define device_bar_BDK_PKO_DQX_SCHED_STATE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_SCHED_STATE(a) (a)
#define arguments_BDK_PKO_DQX_SCHED_STATE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_schedule
 *
 * PKO PSE Descriptor Queue Scheduling Control Register
 * This register has the same bit fields as PKO_L2_SQ()_SCHEDULE.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_schedule_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t prio                  : 4;  /**< [ 27: 24](R/W) Priority. The priority used for this SQ in the (lower-level) parent's scheduling
                                                                 algorithm. When this SQ is not used, we recommend setting [PRIO] to zero. The legal [PRIO]
                                                                 values are 0-9 when the SQ is used. In addition to priority, [PRIO] determines whether the
                                                                 SQ is a static queue or not: If [PRIO] equals PKO_*_SQn_TOPOLOGY[RR_PRIO], where
                                                                 PKO_*_TOPOLOGY[PARENT] for this SQ equals n, then this is a round-robin child queue into
                                                                 the shaper at the next level. */
        uint64_t rr_quantum            : 24; /**< [ 23:  0](R/W) Round-robin (DWRR) quantum. The deficit-weighted round-robin quantum (24-bit unsigned
                                                                 integer). The packet size used in all DWRR (RR_COUNT) calculations is:

                                                                 _  (PKO_nm_SHAPE[LENGTH_DISABLE] ? 0 : (PKO_nm_PICK[LENGTH] + PKO_nm_PICK[ADJUST]))
                                                                    + PKO_nm_SHAPE[ADJUST]

                                                                 where nm corresponds to this PKO_nm_SCHEDULE CSR.

                                                                 Typically [RR_QUANTUM] should be at or near the MTU or more (to limit or prevent
                                                                 negative accumulations of PKO_*_SCHED_STATE[RR_COUNT] (i.e. the deficit count)). */
#else /* Word 0 - Little Endian */
        uint64_t rr_quantum            : 24; /**< [ 23:  0](R/W) Round-robin (DWRR) quantum. The deficit-weighted round-robin quantum (24-bit unsigned
                                                                 integer). The packet size used in all DWRR (RR_COUNT) calculations is:

                                                                 _  (PKO_nm_SHAPE[LENGTH_DISABLE] ? 0 : (PKO_nm_PICK[LENGTH] + PKO_nm_PICK[ADJUST]))
                                                                    + PKO_nm_SHAPE[ADJUST]

                                                                 where nm corresponds to this PKO_nm_SCHEDULE CSR.

                                                                 Typically [RR_QUANTUM] should be at or near the MTU or more (to limit or prevent
                                                                 negative accumulations of PKO_*_SCHED_STATE[RR_COUNT] (i.e. the deficit count)). */
        uint64_t prio                  : 4;  /**< [ 27: 24](R/W) Priority. The priority used for this SQ in the (lower-level) parent's scheduling
                                                                 algorithm. When this SQ is not used, we recommend setting [PRIO] to zero. The legal [PRIO]
                                                                 values are 0-9 when the SQ is used. In addition to priority, [PRIO] determines whether the
                                                                 SQ is a static queue or not: If [PRIO] equals PKO_*_SQn_TOPOLOGY[RR_PRIO], where
                                                                 PKO_*_TOPOLOGY[PARENT] for this SQ equals n, then this is a round-robin child queue into
                                                                 the shaper at the next level. */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_schedule_s cn; */
} bdk_pko_dqx_schedule_t;

static inline uint64_t BDK_PKO_DQX_SCHEDULE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_SCHEDULE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000280008ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_SCHEDULE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_SCHEDULE(a) bdk_pko_dqx_schedule_t
#define bustype_BDK_PKO_DQX_SCHEDULE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_SCHEDULE(a) "PKO_DQX_SCHEDULE"
#define device_bar_BDK_PKO_DQX_SCHEDULE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_SCHEDULE(a) (a)
#define arguments_BDK_PKO_DQX_SCHEDULE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_shape
 *
 * PKO PSE Descriptor Queue Shaping Control Register
 * This register has the same bit fields as PKO_L3_SQ()_SHAPE.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_shape_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t schedule_list         : 2;  /**< [ 26: 25](R/W) Shaper scheduling list. Restricts shaper scheduling to specific lists.
                                                                   0x0 = Normal (selected for nearly all scheduling/shaping applications).
                                                                   0x1 = Green-only.
                                                                   0x2 = Yellow-only.
                                                                   0x3 = Red-only. */
        uint64_t length_disable        : 1;  /**< [ 24: 24](R/W) Length disable. Disables the use of packet lengths in DWRR scheduling
                                                                 and shaping calculations such that only the value of [ADJUST] is used. */
        uint64_t reserved_13_23        : 11;
        uint64_t yellow_disable        : 1;  /**< [ 12: 12](R/W) See PKO_L2_SQ()_SHAPE[YELLOW_DISABLE]. */
        uint64_t red_disable           : 1;  /**< [ 11: 11](R/W) See PKO_L2_SQ()_SHAPE[RED_DISABLE]. */
        uint64_t red_algo              : 2;  /**< [ 10:  9](R/W) See PKO_L2_SQ()_SHAPE[RED_ALGO]. */
        uint64_t adjust                : 9;  /**< [  8:  0](R/W) See PKO_L2_SQ()_SHAPE[ADJUST]. */
#else /* Word 0 - Little Endian */
        uint64_t adjust                : 9;  /**< [  8:  0](R/W) See PKO_L2_SQ()_SHAPE[ADJUST]. */
        uint64_t red_algo              : 2;  /**< [ 10:  9](R/W) See PKO_L2_SQ()_SHAPE[RED_ALGO]. */
        uint64_t red_disable           : 1;  /**< [ 11: 11](R/W) See PKO_L2_SQ()_SHAPE[RED_DISABLE]. */
        uint64_t yellow_disable        : 1;  /**< [ 12: 12](R/W) See PKO_L2_SQ()_SHAPE[YELLOW_DISABLE]. */
        uint64_t reserved_13_23        : 11;
        uint64_t length_disable        : 1;  /**< [ 24: 24](R/W) Length disable. Disables the use of packet lengths in DWRR scheduling
                                                                 and shaping calculations such that only the value of [ADJUST] is used. */
        uint64_t schedule_list         : 2;  /**< [ 26: 25](R/W) Shaper scheduling list. Restricts shaper scheduling to specific lists.
                                                                   0x0 = Normal (selected for nearly all scheduling/shaping applications).
                                                                   0x1 = Green-only.
                                                                   0x2 = Yellow-only.
                                                                   0x3 = Red-only. */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_shape_s cn; */
} bdk_pko_dqx_shape_t;

static inline uint64_t BDK_PKO_DQX_SHAPE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_SHAPE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000280010ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_SHAPE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_SHAPE(a) bdk_pko_dqx_shape_t
#define bustype_BDK_PKO_DQX_SHAPE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_SHAPE(a) "PKO_DQX_SHAPE"
#define device_bar_BDK_PKO_DQX_SHAPE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_SHAPE(a) (a)
#define arguments_BDK_PKO_DQX_SHAPE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_shape_state
 *
 * PKO PSE Descriptor Queue Shaping State Register
 * This register has the same bit fields as PKO_L2_SQ()_SHAPE_STATE.
 * This register must not be written during normal operation.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_shape_state_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t tw_timestamp          : 6;  /**< [ 59: 54](R/W/H) Time-wheel timestamp. Debug access to the live time-wheel timestamp. */
        uint64_t color                 : 2;  /**< [ 53: 52](R/W/H) Shaper connection status. Debug access to the live shaper state.
                                                                 0x0 = Green - shaper is connected into the green list.
                                                                 0x1 = Yellow - shaper is connected into the yellow list.
                                                                 0x2 = Red - shaper is connected into the red list.
                                                                 0x3 = Pruned - shaper is disconnected. */
        uint64_t pir_accum             : 26; /**< [ 51: 26](R/W/H) Peak information rate accumulator. Debug access to the live PIR accumulator. */
        uint64_t cir_accum             : 26; /**< [ 25:  0](R/W/H) Committed information rate accumulator. Debug access to the live CIR accumulator. */
#else /* Word 0 - Little Endian */
        uint64_t cir_accum             : 26; /**< [ 25:  0](R/W/H) Committed information rate accumulator. Debug access to the live CIR accumulator. */
        uint64_t pir_accum             : 26; /**< [ 51: 26](R/W/H) Peak information rate accumulator. Debug access to the live PIR accumulator. */
        uint64_t color                 : 2;  /**< [ 53: 52](R/W/H) Shaper connection status. Debug access to the live shaper state.
                                                                 0x0 = Green - shaper is connected into the green list.
                                                                 0x1 = Yellow - shaper is connected into the yellow list.
                                                                 0x2 = Red - shaper is connected into the red list.
                                                                 0x3 = Pruned - shaper is disconnected. */
        uint64_t tw_timestamp          : 6;  /**< [ 59: 54](R/W/H) Time-wheel timestamp. Debug access to the live time-wheel timestamp. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_shape_state_s cn; */
} bdk_pko_dqx_shape_state_t;

static inline uint64_t BDK_PKO_DQX_SHAPE_STATE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_SHAPE_STATE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000280030ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_SHAPE_STATE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_SHAPE_STATE(a) bdk_pko_dqx_shape_state_t
#define bustype_BDK_PKO_DQX_SHAPE_STATE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_SHAPE_STATE(a) "PKO_DQX_SHAPE_STATE"
#define device_bar_BDK_PKO_DQX_SHAPE_STATE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_SHAPE_STATE(a) (a)
#define arguments_BDK_PKO_DQX_SHAPE_STATE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_topology
 *
 * PKO PSE Descriptor Queue Topology Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_topology_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t parent                : 8;  /**< [ 23: 16](R/W) See PKO_L2_SQ()_TOPOLOGY[PARENT]. */
        uint64_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_15         : 16;
        uint64_t parent                : 8;  /**< [ 23: 16](R/W) See PKO_L2_SQ()_TOPOLOGY[PARENT]. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_topology_s cn; */
} bdk_pko_dqx_topology_t;

static inline uint64_t BDK_PKO_DQX_TOPOLOGY(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_TOPOLOGY(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000300000ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_TOPOLOGY", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_TOPOLOGY(a) bdk_pko_dqx_topology_t
#define bustype_BDK_PKO_DQX_TOPOLOGY(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_TOPOLOGY(a) "PKO_DQX_TOPOLOGY"
#define device_bar_BDK_PKO_DQX_TOPOLOGY(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_TOPOLOGY(a) (a)
#define arguments_BDK_PKO_DQX_TOPOLOGY(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_wm_buf_cnt
 *
 * PKO Descriptor Queue Buffer Watermark Count Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_wm_buf_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t count                 : 36; /**< [ 35:  0](R/W/H) Watermark buffer count. The number of buffers allocated (from
                                                                 FPA aura PKO_DPFI_FPA_AURA[NODE,LAURA]) for this DQ. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 36; /**< [ 35:  0](R/W/H) Watermark buffer count. The number of buffers allocated (from
                                                                 FPA aura PKO_DPFI_FPA_AURA[NODE,LAURA]) for this DQ. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_wm_buf_cnt_s cn; */
} bdk_pko_dqx_wm_buf_cnt_t;

static inline uint64_t BDK_PKO_DQX_WM_BUF_CNT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_WM_BUF_CNT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x8540008000e8ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_WM_BUF_CNT", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_WM_BUF_CNT(a) bdk_pko_dqx_wm_buf_cnt_t
#define bustype_BDK_PKO_DQX_WM_BUF_CNT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_WM_BUF_CNT(a) "PKO_DQX_WM_BUF_CNT"
#define device_bar_BDK_PKO_DQX_WM_BUF_CNT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_WM_BUF_CNT(a) (a)
#define arguments_BDK_PKO_DQX_WM_BUF_CNT(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_wm_buf_ctl
 *
 * PKO Descriptor Queue Buffer Watermark Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_wm_buf_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_51_63        : 13;
        uint64_t enable                : 1;  /**< [ 50: 50](R/W) Watermark interrupt enable for [THRESHOLD] comparison to PKO_DQ()_WM_BUF_CNT[COUNT].
                                                                 See the [INTR] description. */
        uint64_t reserved_49           : 1;
        uint64_t intr                  : 1;  /**< [ 48: 48](R/W/H) Watermark Buffer Interrupt. If [INTR] is clear and [ENABLE] is set, PKO sets
                                                                 [INTR] whenever it modifies PKO_DQ()_WM_BUF_CNT[COUNT] to equal or cross
                                                                 [THRESHOLD]. */
        uint64_t reserved_36_47        : 12;
        uint64_t threshold             : 36; /**< [ 35:  0](R/W) Watermark interrupt buffer threshold for PKO_DQ()_WM_BUF_CNT[COUNT].
                                                                 See the [INTR] description. */
#else /* Word 0 - Little Endian */
        uint64_t threshold             : 36; /**< [ 35:  0](R/W) Watermark interrupt buffer threshold for PKO_DQ()_WM_BUF_CNT[COUNT].
                                                                 See the [INTR] description. */
        uint64_t reserved_36_47        : 12;
        uint64_t intr                  : 1;  /**< [ 48: 48](R/W/H) Watermark Buffer Interrupt. If [INTR] is clear and [ENABLE] is set, PKO sets
                                                                 [INTR] whenever it modifies PKO_DQ()_WM_BUF_CNT[COUNT] to equal or cross
                                                                 [THRESHOLD]. */
        uint64_t reserved_49           : 1;
        uint64_t enable                : 1;  /**< [ 50: 50](R/W) Watermark interrupt enable for [THRESHOLD] comparison to PKO_DQ()_WM_BUF_CNT[COUNT].
                                                                 See the [INTR] description. */
        uint64_t reserved_51_63        : 13;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_wm_buf_ctl_s cn; */
} bdk_pko_dqx_wm_buf_ctl_t;

static inline uint64_t BDK_PKO_DQX_WM_BUF_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_WM_BUF_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x8540008000f0ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_WM_BUF_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_WM_BUF_CTL(a) bdk_pko_dqx_wm_buf_ctl_t
#define bustype_BDK_PKO_DQX_WM_BUF_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_WM_BUF_CTL(a) "PKO_DQX_WM_BUF_CTL"
#define device_bar_BDK_PKO_DQX_WM_BUF_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_WM_BUF_CTL(a) (a)
#define arguments_BDK_PKO_DQX_WM_BUF_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq#_wm_buf_ctl_w1c
 *
 * PKO Descriptor Queue Buffer Watermark Control Write-1 Interrupt Clear Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dqx_wm_buf_ctl_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t intr                  : 1;  /**< [ 48: 48](R/W1C/H) A copy of PKO_DQ()_WM_BUF_CTL[INTR]. When [INTR] is written with a one,
                                                                 PKO_DQ()_WM_BUF_CTL[INTR] is cleared. */
        uint64_t reserved_0_47         : 48;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_47         : 48;
        uint64_t intr                  : 1;  /**< [ 48: 48](R/W1C/H) A copy of PKO_DQ()_WM_BUF_CTL[INTR]. When [INTR] is written with a one,
                                                                 PKO_DQ()_WM_BUF_CTL[INTR] is cleared. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dqx_wm_buf_ctl_w1c_s cn; */
} bdk_pko_dqx_wm_buf_ctl_w1c_t;

static inline uint64_t BDK_PKO_DQX_WM_BUF_CTL_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQX_WM_BUF_CTL_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x8540008000f8ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_DQX_WM_BUF_CTL_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_DQX_WM_BUF_CTL_W1C(a) bdk_pko_dqx_wm_buf_ctl_w1c_t
#define bustype_BDK_PKO_DQX_WM_BUF_CTL_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQX_WM_BUF_CTL_W1C(a) "PKO_DQX_WM_BUF_CTL_W1C"
#define device_bar_BDK_PKO_DQX_WM_BUF_CTL_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQX_WM_BUF_CTL_W1C(a) (a)
#define arguments_BDK_PKO_DQX_WM_BUF_CTL_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_dq_const
 *
 * PKO DQ Constants Register
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dq_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t count                 : 16; /**< [ 15:  0](RO) Number of descriptor queues. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 16; /**< [ 15:  0](RO) Number of descriptor queues. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dq_const_s cn; */
} bdk_pko_dq_const_t;

#define BDK_PKO_DQ_CONST BDK_PKO_DQ_CONST_FUNC()
static inline uint64_t BDK_PKO_DQ_CONST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQ_CONST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000d00138ll;
    __bdk_csr_fatal("PKO_DQ_CONST", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_DQ_CONST bdk_pko_dq_const_t
#define bustype_BDK_PKO_DQ_CONST BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQ_CONST "PKO_DQ_CONST"
#define device_bar_BDK_PKO_DQ_CONST 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQ_CONST 0
#define arguments_BDK_PKO_DQ_CONST -1,-1,-1,-1

/**
 * Register (NCB) pko_dq_debug
 *
 * INTERNAL: PKO PSE DQ Internal Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_dq_debug_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#else /* Word 0 - Little Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_dq_debug_s cn; */
} bdk_pko_dq_debug_t;

#define BDK_PKO_DQ_DEBUG BDK_PKO_DQ_DEBUG_FUNC()
static inline uint64_t BDK_PKO_DQ_DEBUG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_DQ_DEBUG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000300128ll;
    __bdk_csr_fatal("PKO_DQ_DEBUG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_DQ_DEBUG bdk_pko_dq_debug_t
#define bustype_BDK_PKO_DQ_DEBUG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_DQ_DEBUG "PKO_DQ_DEBUG"
#define device_bar_BDK_PKO_DQ_DEBUG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_DQ_DEBUG 0
#define arguments_BDK_PKO_DQ_DEBUG -1,-1,-1,-1

/**
 * Register (NCB) pko_enable
 *
 * PKO Global Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_enable_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enables the PKO.  While the PKO_ENABLE is clear the PKO will neither
                                                                 transmit nor receive signaling to/from the MACs nor will it respond
                                                                 to SEND_PACKET or QUEUE_OPEN/CLOSE commands. Software must only enable
                                                                 the PKO once all configuration and mapping CSRs have been loaded. */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enables the PKO.  While the PKO_ENABLE is clear the PKO will neither
                                                                 transmit nor receive signaling to/from the MACs nor will it respond
                                                                 to SEND_PACKET or QUEUE_OPEN/CLOSE commands. Software must only enable
                                                                 the PKO once all configuration and mapping CSRs have been loaded. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_enable_s cn; */
} bdk_pko_enable_t;

#define BDK_PKO_ENABLE BDK_PKO_ENABLE_FUNC()
static inline uint64_t BDK_PKO_ENABLE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_ENABLE_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000d00008ll;
    __bdk_csr_fatal("PKO_ENABLE", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_ENABLE bdk_pko_enable_t
#define bustype_BDK_PKO_ENABLE BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_ENABLE "PKO_ENABLE"
#define device_bar_BDK_PKO_ENABLE 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_ENABLE 0
#define arguments_BDK_PKO_ENABLE -1,-1,-1,-1

/**
 * Register (NCB) pko_format#_ctl
 *
 * PKO Packet Marking Format Register
 * Describes packet marking calculations for YELLOW and for RED_SEND packets.
 * PKO_SEND_HDR_S[FORMAT] selects the CSR used for the packet descriptor.
 *
 * All the packet marking calculations assume big-endian bits within a byte.
 *
 * For example, if MARKPTR is 3 and [OFFSET] is 5 and the packet is YELLOW,
 * the PKO marking hardware would do this:
 *
 * _  byte[3]<2:0> |=   Y_VAL<3:1>
 * _  byte[3]<2:0> &= ~Y_MASK<3:1>
 * _  byte[4]<7>   |=   Y_VAL<0>
 * _  byte[4]<7>   &= ~Y_MASK<0>
 *
 * where byte[3] is the 3rd byte in the packet, and byte[4] the 4th.
 *
 * For another example, if MARKPTR is 3 and [OFFSET] is 0 and the packet is RED_SEND,
 *
 * _   byte[3]<7:4> |=   R_VAL<3:0>
 * _   byte[3]<7:4> &= ~R_MASK<3:0>
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_formatx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t offset                : 11; /**< [ 26: 16](R/W) Packet marking starts MARKPTR*8 + [OFFSET] bits into the packet.
                                                                 All processing with [Y_MASK,Y_VAL,R_MASK,R_VAL] starts at this offset.
                                                                 MARKPTR is PKO_SEND_HDR_S[MARKPTR]. */
        uint64_t y_mask                : 4;  /**< [ 15: 12](R/W) Yellow mark mask. Corresponding bits in packet's data are cleared when marking a YELLOW
                                                                 packet. [Y_MASK] & [Y_VAL] must be zero. */
        uint64_t y_val                 : 4;  /**< [ 11:  8](R/W) Yellow mark value. Corresponding bits in packet's data are set when marking a YELLOW
                                                                 packet. [Y_MASK] & [Y_VAL] must be zero. */
        uint64_t r_mask                : 4;  /**< [  7:  4](R/W) Red mark mask. Corresponding bits in packet's data are cleared when marking a RED_SEND
                                                                 packet. [R_MASK] & [R_VAL] must be zero. */
        uint64_t r_val                 : 4;  /**< [  3:  0](R/W) Red mark value. Corresponding bits in packet's data are set when marking a RED_SEND
                                                                 packet. [R_MASK] & [R_VAL] must be zero. */
#else /* Word 0 - Little Endian */
        uint64_t r_val                 : 4;  /**< [  3:  0](R/W) Red mark value. Corresponding bits in packet's data are set when marking a RED_SEND
                                                                 packet. [R_MASK] & [R_VAL] must be zero. */
        uint64_t r_mask                : 4;  /**< [  7:  4](R/W) Red mark mask. Corresponding bits in packet's data are cleared when marking a RED_SEND
                                                                 packet. [R_MASK] & [R_VAL] must be zero. */
        uint64_t y_val                 : 4;  /**< [ 11:  8](R/W) Yellow mark value. Corresponding bits in packet's data are set when marking a YELLOW
                                                                 packet. [Y_MASK] & [Y_VAL] must be zero. */
        uint64_t y_mask                : 4;  /**< [ 15: 12](R/W) Yellow mark mask. Corresponding bits in packet's data are cleared when marking a YELLOW
                                                                 packet. [Y_MASK] & [Y_VAL] must be zero. */
        uint64_t offset                : 11; /**< [ 26: 16](R/W) Packet marking starts MARKPTR*8 + [OFFSET] bits into the packet.
                                                                 All processing with [Y_MASK,Y_VAL,R_MASK,R_VAL] starts at this offset.
                                                                 MARKPTR is PKO_SEND_HDR_S[MARKPTR]. */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_formatx_ctl_s cn; */
} bdk_pko_formatx_ctl_t;

static inline uint64_t BDK_PKO_FORMATX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_FORMATX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000900800ll + 8ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_FORMATX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_FORMATX_CTL(a) bdk_pko_formatx_ctl_t
#define bustype_BDK_PKO_FORMATX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_FORMATX_CTL(a) "PKO_FORMATX_CTL"
#define device_bar_BDK_PKO_FORMATX_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_FORMATX_CTL(a) (a)
#define arguments_BDK_PKO_FORMATX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_const
 *
 * PKO Level 1 Constants Register
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t count                 : 16; /**< [ 15:  0](RO) Number of Level-1 shaping queues.
                                                                 Internal:
                                                                 FIXME?  reset_matches_size: "PKO_L1_SQ()_TOPOLOGY,a" */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 16; /**< [ 15:  0](RO) Number of Level-1 shaping queues.
                                                                 Internal:
                                                                 FIXME?  reset_matches_size: "PKO_L1_SQ()_TOPOLOGY,a" */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_const_s cn; */
} bdk_pko_l1_const_t;

#define BDK_PKO_L1_CONST BDK_PKO_L1_CONST_FUNC()
static inline uint64_t BDK_PKO_L1_CONST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_CONST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000d00100ll;
    __bdk_csr_fatal("PKO_L1_CONST", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_CONST bdk_pko_l1_const_t
#define bustype_BDK_PKO_L1_CONST BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_CONST "PKO_L1_CONST"
#define device_bar_BDK_PKO_L1_CONST 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_CONST 0
#define arguments_BDK_PKO_L1_CONST -1,-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_cir
 *
 * PKO PSE Level 1 Shaping Queue Committed Information Rate Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_cir_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_41_63        : 23;
        uint64_t burst_exponent        : 4;  /**< [ 40: 37](R/W) Burst exponent. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t burst_mantissa        : 8;  /**< [ 36: 29](R/W) Burst mantissa. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t reserved_17_28        : 12;
        uint64_t rate_divider_exponent : 4;  /**< [ 16: 13](R/W) Rate divider exponent. This 4-bit base-2 exponent is used to divide the credit rate by
                                                                 specifying the number of time-wheel turns required before the accumulator is increased.
                                                                 [RATE_DIVIDER_EXPONENT] should be used to specify data rates lower than ~10 Kbps and
                                                                 [RATE_EXPONENT] should be set to zero whenever it is used.

                                                                 The rate count = (1 << [RATE_DIVIDER_EXPONENT]). The supported range for
                                                                 [RATE_DIVIDER_EXPONENT] is 0 to 12. Programmed values greater than 12 are treated as 12.

                                                                 Note that for the L1-SQs, a time-wheel turn is 96 clocks (SCLK). For the other levels a
                                                                 time-wheel turn is 768 clocks (SCLK).

                                                                 For L1_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 96) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1
                                                                 <<[RATE_DIVIDER_EXPONENT])

                                                                 For L[5:2]_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 768) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1 <<
                                                                 [RATE_DIVIDER_EXPONENT]) */
        uint64_t rate_exponent         : 4;  /**< [ 12:  9](R/W) Rate exponent. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT].
                                                                 [RATE_EXPONENT] should be used to specify data rates higher than ~10 Kbps and
                                                                 [RATE_DIVIDER_EXPONENT] should be set to zero whenever it is nonzero. */
        uint64_t rate_mantissa         : 8;  /**< [  8:  1](R/W) Rate mantissa. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT]. */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable. Enables CIR shaping. */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable. Enables CIR shaping. */
        uint64_t rate_mantissa         : 8;  /**< [  8:  1](R/W) Rate mantissa. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT]. */
        uint64_t rate_exponent         : 4;  /**< [ 12:  9](R/W) Rate exponent. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT].
                                                                 [RATE_EXPONENT] should be used to specify data rates higher than ~10 Kbps and
                                                                 [RATE_DIVIDER_EXPONENT] should be set to zero whenever it is nonzero. */
        uint64_t rate_divider_exponent : 4;  /**< [ 16: 13](R/W) Rate divider exponent. This 4-bit base-2 exponent is used to divide the credit rate by
                                                                 specifying the number of time-wheel turns required before the accumulator is increased.
                                                                 [RATE_DIVIDER_EXPONENT] should be used to specify data rates lower than ~10 Kbps and
                                                                 [RATE_EXPONENT] should be set to zero whenever it is used.

                                                                 The rate count = (1 << [RATE_DIVIDER_EXPONENT]). The supported range for
                                                                 [RATE_DIVIDER_EXPONENT] is 0 to 12. Programmed values greater than 12 are treated as 12.

                                                                 Note that for the L1-SQs, a time-wheel turn is 96 clocks (SCLK). For the other levels a
                                                                 time-wheel turn is 768 clocks (SCLK).

                                                                 For L1_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 96) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1
                                                                 <<[RATE_DIVIDER_EXPONENT])

                                                                 For L[5:2]_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 768) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1 <<
                                                                 [RATE_DIVIDER_EXPONENT]) */
        uint64_t reserved_17_28        : 12;
        uint64_t burst_mantissa        : 8;  /**< [ 36: 29](R/W) Burst mantissa. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t burst_exponent        : 4;  /**< [ 40: 37](R/W) Burst exponent. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t reserved_41_63        : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_cir_s cn; */
} bdk_pko_l1_sqx_cir_t;

static inline uint64_t BDK_PKO_L1_SQX_CIR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_CIR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000000018ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_CIR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_CIR(a) bdk_pko_l1_sqx_cir_t
#define bustype_BDK_PKO_L1_SQX_CIR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_CIR(a) "PKO_L1_SQX_CIR"
#define device_bar_BDK_PKO_L1_SQX_CIR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_CIR(a) (a)
#define arguments_BDK_PKO_L1_SQX_CIR(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_dropped_bytes
 *
 * PKO PSE Port Queue Dropped Bytes Register
 * This register has the same bit fields as PKO_L1_SQ()_GREEN_BYTES.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_dropped_bytes_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t count                 : 48; /**< [ 47:  0](R/W/H) Count. The running count of bytes. Note that this count wraps. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 48; /**< [ 47:  0](R/W/H) Count. The running count of bytes. Note that this count wraps. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_dropped_bytes_s cn; */
} bdk_pko_l1_sqx_dropped_bytes_t;

static inline uint64_t BDK_PKO_L1_SQX_DROPPED_BYTES(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_DROPPED_BYTES(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000000088ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_DROPPED_BYTES", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_DROPPED_BYTES(a) bdk_pko_l1_sqx_dropped_bytes_t
#define bustype_BDK_PKO_L1_SQX_DROPPED_BYTES(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_DROPPED_BYTES(a) "PKO_L1_SQX_DROPPED_BYTES"
#define device_bar_BDK_PKO_L1_SQX_DROPPED_BYTES(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_DROPPED_BYTES(a) (a)
#define arguments_BDK_PKO_L1_SQX_DROPPED_BYTES(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_dropped_packets
 *
 * PKO PSE Port Queue Dropped Packets Register
 * This register has the same bit fields as PKO_L1_SQ()_GREEN_PACKETS.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_dropped_packets_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t count                 : 40; /**< [ 39:  0](R/W/H) Count. The running count of packets. Note that this count wraps. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 40; /**< [ 39:  0](R/W/H) Count. The running count of packets. Note that this count wraps. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_dropped_packets_s cn; */
} bdk_pko_l1_sqx_dropped_packets_t;

static inline uint64_t BDK_PKO_L1_SQX_DROPPED_PACKETS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_DROPPED_PACKETS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000000080ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_DROPPED_PACKETS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_DROPPED_PACKETS(a) bdk_pko_l1_sqx_dropped_packets_t
#define bustype_BDK_PKO_L1_SQX_DROPPED_PACKETS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_DROPPED_PACKETS(a) "PKO_L1_SQX_DROPPED_PACKETS"
#define device_bar_BDK_PKO_L1_SQX_DROPPED_PACKETS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_DROPPED_PACKETS(a) (a)
#define arguments_BDK_PKO_L1_SQX_DROPPED_PACKETS(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_green
 *
 * INTERNAL: PKO PSE Level 1 Shaping Queue Green State Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_green_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_41_63        : 23;
        uint64_t rr_active             : 1;  /**< [ 40: 40](R/W/H) Round-robin red active. Set when the RED_SEND+RED_DROP DWRR child list is not empty.
                                                                 For internal use only. */
        uint64_t active_vec            : 20; /**< [ 39: 20](R/W/H) Active vector. A 20-bit vector, 2 bits per each of the 10 supported priorities.
                                                                 For the non-RR_PRIO priorities, the 2 bits encode whether the child is active
                                                                 GREEN, active YELLOW, active RED_SEND+RED_DROP, or inactive. At RR_PRIO, one
                                                                 bit is set if the GREEN DWRR child list is not empty, and the other is set if the
                                                                 YELLOW DWRR child list is not empty. For internal use only. */
        uint64_t reserved_19           : 1;
        uint64_t head                  : 9;  /**< [ 18: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_9            : 1;
        uint64_t tail                  : 9;  /**< [  8:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
#else /* Word 0 - Little Endian */
        uint64_t tail                  : 9;  /**< [  8:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
        uint64_t reserved_9            : 1;
        uint64_t head                  : 9;  /**< [ 18: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_19           : 1;
        uint64_t active_vec            : 20; /**< [ 39: 20](R/W/H) Active vector. A 20-bit vector, 2 bits per each of the 10 supported priorities.
                                                                 For the non-RR_PRIO priorities, the 2 bits encode whether the child is active
                                                                 GREEN, active YELLOW, active RED_SEND+RED_DROP, or inactive. At RR_PRIO, one
                                                                 bit is set if the GREEN DWRR child list is not empty, and the other is set if the
                                                                 YELLOW DWRR child list is not empty. For internal use only. */
        uint64_t rr_active             : 1;  /**< [ 40: 40](R/W/H) Round-robin red active. Set when the RED_SEND+RED_DROP DWRR child list is not empty.
                                                                 For internal use only. */
        uint64_t reserved_41_63        : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_green_s cn; */
} bdk_pko_l1_sqx_green_t;

static inline uint64_t BDK_PKO_L1_SQX_GREEN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_GREEN(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000080058ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_GREEN", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_GREEN(a) bdk_pko_l1_sqx_green_t
#define bustype_BDK_PKO_L1_SQX_GREEN(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_GREEN(a) "PKO_L1_SQX_GREEN"
#define device_bar_BDK_PKO_L1_SQX_GREEN(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_GREEN(a) (a)
#define arguments_BDK_PKO_L1_SQX_GREEN(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_green_bytes
 *
 * PKO PSE Port Queue Green Sent Bytes Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_green_bytes_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t count                 : 48; /**< [ 47:  0](R/W/H) Count. The running count of bytes. Note that this count wraps. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 48; /**< [ 47:  0](R/W/H) Count. The running count of bytes. Note that this count wraps. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_green_bytes_s cn; */
} bdk_pko_l1_sqx_green_bytes_t;

static inline uint64_t BDK_PKO_L1_SQX_GREEN_BYTES(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_GREEN_BYTES(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x8540000000b8ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_GREEN_BYTES", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_GREEN_BYTES(a) bdk_pko_l1_sqx_green_bytes_t
#define bustype_BDK_PKO_L1_SQX_GREEN_BYTES(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_GREEN_BYTES(a) "PKO_L1_SQX_GREEN_BYTES"
#define device_bar_BDK_PKO_L1_SQX_GREEN_BYTES(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_GREEN_BYTES(a) (a)
#define arguments_BDK_PKO_L1_SQX_GREEN_BYTES(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_green_packets
 *
 * PKO PSE Port Queue Green Sent Packets Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_green_packets_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t count                 : 40; /**< [ 39:  0](R/W/H) Count. The running count of packets. Note that this count wraps. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 40; /**< [ 39:  0](R/W/H) Count. The running count of packets. Note that this count wraps. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_green_packets_s cn; */
} bdk_pko_l1_sqx_green_packets_t;

static inline uint64_t BDK_PKO_L1_SQX_GREEN_PACKETS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_GREEN_PACKETS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x8540000000b0ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_GREEN_PACKETS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_GREEN_PACKETS(a) bdk_pko_l1_sqx_green_packets_t
#define bustype_BDK_PKO_L1_SQX_GREEN_PACKETS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_GREEN_PACKETS(a) "PKO_L1_SQX_GREEN_PACKETS"
#define device_bar_BDK_PKO_L1_SQX_GREEN_PACKETS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_GREEN_PACKETS(a) (a)
#define arguments_BDK_PKO_L1_SQX_GREEN_PACKETS(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_link
 *
 * PKO PSE Level 1 Link Configuration Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_link_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t link                  : 5;  /**< [ 48: 44](R/W) Link index. Must match PKO_L1_SQ()_TOPOLOGY[LINK]. */
        uint64_t reserved_32_43        : 12;
        uint64_t cc_word_cnt           : 20; /**< [ 31: 12](R/W/H) Channel credit word count. This value, plus 1 MTU, represents the maximum outstanding
                                                                 aggregate word count (words are 16 bytes) for all channels feeding into this PQ. Note that
                                                                 this 20-bit field represents a signed value that decrements towards zero as credits are
                                                                 used. Packets are not allowed to flow when the count is less than zero. As such, the most
                                                                 significant bit should normally be programmed as zero (positive count). This gives a
                                                                 maximum value for this field of 2^19 - 1. */
        uint64_t cc_packet_cnt         : 10; /**< [ 11:  2](R/W/H) Channel credit packet count. This value, plus 1, represents the maximum outstanding
                                                                 aggregate packet count for all channels feeding into this PQ. Note that this 10-bit field
                                                                 represents a signed value that decrements towards zero as credits are used. Packets are
                                                                 not allowed to flow when the count is less than zero. As such the most significant bit
                                                                 should normally be programmed as zero (positive count). This gives a maximum value for
                                                                 this field of 2^9 - 1. */
        uint64_t cc_enable             : 1;  /**< [  1:  1](R/W) Channel credit enable. Enables [CC_WORD_CNT] and [CC_PACKET_CNT] aggregate credit processing. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t cc_enable             : 1;  /**< [  1:  1](R/W) Channel credit enable. Enables [CC_WORD_CNT] and [CC_PACKET_CNT] aggregate credit processing. */
        uint64_t cc_packet_cnt         : 10; /**< [ 11:  2](R/W/H) Channel credit packet count. This value, plus 1, represents the maximum outstanding
                                                                 aggregate packet count for all channels feeding into this PQ. Note that this 10-bit field
                                                                 represents a signed value that decrements towards zero as credits are used. Packets are
                                                                 not allowed to flow when the count is less than zero. As such the most significant bit
                                                                 should normally be programmed as zero (positive count). This gives a maximum value for
                                                                 this field of 2^9 - 1. */
        uint64_t cc_word_cnt           : 20; /**< [ 31: 12](R/W/H) Channel credit word count. This value, plus 1 MTU, represents the maximum outstanding
                                                                 aggregate word count (words are 16 bytes) for all channels feeding into this PQ. Note that
                                                                 this 20-bit field represents a signed value that decrements towards zero as credits are
                                                                 used. Packets are not allowed to flow when the count is less than zero. As such, the most
                                                                 significant bit should normally be programmed as zero (positive count). This gives a
                                                                 maximum value for this field of 2^19 - 1. */
        uint64_t reserved_32_43        : 12;
        uint64_t link                  : 5;  /**< [ 48: 44](R/W) Link index. Must match PKO_L1_SQ()_TOPOLOGY[LINK]. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_link_s cn; */
} bdk_pko_l1_sqx_link_t;

static inline uint64_t BDK_PKO_L1_SQX_LINK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_LINK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000000038ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_LINK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_LINK(a) bdk_pko_l1_sqx_link_t
#define bustype_BDK_PKO_L1_SQX_LINK(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_LINK(a) "PKO_L1_SQX_LINK"
#define device_bar_BDK_PKO_L1_SQX_LINK(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_LINK(a) (a)
#define arguments_BDK_PKO_L1_SQX_LINK(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_pick
 *
 * PKO PSE Level 1 Shaping Queue Packet Pick State Debug Register
 * This CSR contains the meta for the L1 SQ, and is for debug and reconfiguration
 * only and should never be written. See also PKO_META_DESC_S.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_pick_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dq                    : 10; /**< [ 63: 54](R/W/H) Descriptor queue. Index of originating descriptor queue. */
        uint64_t color                 : 2;  /**< [ 53: 52](R/W/H) See PKO_COLORRESULT_E. */
        uint64_t child                 : 10; /**< [ 51: 42](R/W/H) Child index. When the C_CON bit of this result is set, indicating that this result is
                                                                 connected in a flow that extends through the child result, this is the index of that child
                                                                 result. */
        uint64_t bubble                : 1;  /**< [ 41: 41](R/W/H) This metapacket is a fake passed forward after a prune. */
        uint64_t p_con                 : 1;  /**< [ 40: 40](R/W/H) Parent connected flag. This pick has more picks in front of it. */
        uint64_t c_con                 : 1;  /**< [ 39: 39](R/W/H) Child connected flag. This pick has more picks behind it. */
        uint64_t uid                   : 7;  /**< [ 38: 32](R/W/H) Unique ID. 7-bit unique value assigned at the DQ level, increments for each packet. */
        uint64_t jump                  : 1;  /**< [ 31: 31](R/W/H) Set when the corresponding descriptor contains a PKO_SEND_JUMP_S.  See also
                                                                 PKO_META_DESC_S[JUMP]. */
        uint64_t fpd                   : 1;  /**< [ 30: 30](R/W/H) First packet descriptor. Set when corresponding descriptor is the first in a cacheline.
                                                                 See also PKO_META_DESC_S[FPD]. */
        uint64_t ds                    : 1;  /**< [ 29: 29](R/W/H) PKO_SEND_HDR_S[DS] from the corresponding descriptor. Should always be zero.
                                                                 See also PKO_META_DESC_S[DS]. */
        uint64_t adjust                : 9;  /**< [ 28: 20](R/W/H) When [ADJUST] is 0x100, it indicates that this CSR does not contain a valid meta,
                                                                 and all other fields in this CSR are invalid and shouldn't be used.

                                                                 When [ADJUST] is not 0x100, it is the PKO_SEND_HDR_S[SHP_CHG] for the
                                                                 packet. See also PKO_META_DESC_S[ADJUST]. */
        uint64_t pir_dis               : 1;  /**< [ 19: 19](R/W/H) PIR disable. Peak shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or CIR_ONLY
                                                                 (i.e. [PIR_DIS]=PKO_SEND_EXT_S[COL<1>]). Zero if a PKO_SEND_EXT_S is not present in the
                                                                 corresponding descriptor. See PKO_COLORALG_E. [PIR_DIS] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[COL<1>]. */
        uint64_t cir_dis               : 1;  /**< [ 18: 18](R/W/H) CIR disable. Committed shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or
                                                                 PIR_ONLY (i.e. [CIR_DIS]=PKO_SEND_EXT_S[COL<0>]). Zero if a PKO_SEND_EXT_S is not
                                                                 present in the corresponding descriptor. See PKO_COLORALG_E. [CIR_DIS] is used by the
                                                                 DQ through L2 shapers, but not used by the L1 rate limiters. See also
                                                                 PKO_META_DESC_S[COL<0>]. */
        uint64_t red_algo_override     : 2;  /**< [ 17: 16](R/W/H) PKO_SEND_HDR_S[SHP_RA] from the corresponding packet descriptor.
                                                                 [RED_ALGO_OVERRIDE] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[RA]. */
        uint64_t length                : 16; /**< [ 15:  0](R/W/H) Meta packet length. Generally, the size of the outgoing packet
                                                                 including pad, but excluding FCS and preamble.

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] clear:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(PKO_SEND_HDR_S[TOTAL], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               PKO_SEND_HDR_S[TOTAL]

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] set:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(FPS+PKO_SEND_HDR_S[TSO_SB], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               (FPS+PKO_SEND_HDR_S[TSO_SB])

                                                                 d is the DQ that the PKO SEND used. FPS is the number of payload bytes
                                                                 in the TSO segment. See also PKO_META_DESC_S[LENGTH]. */
#else /* Word 0 - Little Endian */
        uint64_t length                : 16; /**< [ 15:  0](R/W/H) Meta packet length. Generally, the size of the outgoing packet
                                                                 including pad, but excluding FCS and preamble.

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] clear:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(PKO_SEND_HDR_S[TOTAL], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               PKO_SEND_HDR_S[TOTAL]

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] set:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(FPS+PKO_SEND_HDR_S[TSO_SB], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               (FPS+PKO_SEND_HDR_S[TSO_SB])

                                                                 d is the DQ that the PKO SEND used. FPS is the number of payload bytes
                                                                 in the TSO segment. See also PKO_META_DESC_S[LENGTH]. */
        uint64_t red_algo_override     : 2;  /**< [ 17: 16](R/W/H) PKO_SEND_HDR_S[SHP_RA] from the corresponding packet descriptor.
                                                                 [RED_ALGO_OVERRIDE] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[RA]. */
        uint64_t cir_dis               : 1;  /**< [ 18: 18](R/W/H) CIR disable. Committed shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or
                                                                 PIR_ONLY (i.e. [CIR_DIS]=PKO_SEND_EXT_S[COL<0>]). Zero if a PKO_SEND_EXT_S is not
                                                                 present in the corresponding descriptor. See PKO_COLORALG_E. [CIR_DIS] is used by the
                                                                 DQ through L2 shapers, but not used by the L1 rate limiters. See also
                                                                 PKO_META_DESC_S[COL<0>]. */
        uint64_t pir_dis               : 1;  /**< [ 19: 19](R/W/H) PIR disable. Peak shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or CIR_ONLY
                                                                 (i.e. [PIR_DIS]=PKO_SEND_EXT_S[COL<1>]). Zero if a PKO_SEND_EXT_S is not present in the
                                                                 corresponding descriptor. See PKO_COLORALG_E. [PIR_DIS] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[COL<1>]. */
        uint64_t adjust                : 9;  /**< [ 28: 20](R/W/H) When [ADJUST] is 0x100, it indicates that this CSR does not contain a valid meta,
                                                                 and all other fields in this CSR are invalid and shouldn't be used.

                                                                 When [ADJUST] is not 0x100, it is the PKO_SEND_HDR_S[SHP_CHG] for the
                                                                 packet. See also PKO_META_DESC_S[ADJUST]. */
        uint64_t ds                    : 1;  /**< [ 29: 29](R/W/H) PKO_SEND_HDR_S[DS] from the corresponding descriptor. Should always be zero.
                                                                 See also PKO_META_DESC_S[DS]. */
        uint64_t fpd                   : 1;  /**< [ 30: 30](R/W/H) First packet descriptor. Set when corresponding descriptor is the first in a cacheline.
                                                                 See also PKO_META_DESC_S[FPD]. */
        uint64_t jump                  : 1;  /**< [ 31: 31](R/W/H) Set when the corresponding descriptor contains a PKO_SEND_JUMP_S.  See also
                                                                 PKO_META_DESC_S[JUMP]. */
        uint64_t uid                   : 7;  /**< [ 38: 32](R/W/H) Unique ID. 7-bit unique value assigned at the DQ level, increments for each packet. */
        uint64_t c_con                 : 1;  /**< [ 39: 39](R/W/H) Child connected flag. This pick has more picks behind it. */
        uint64_t p_con                 : 1;  /**< [ 40: 40](R/W/H) Parent connected flag. This pick has more picks in front of it. */
        uint64_t bubble                : 1;  /**< [ 41: 41](R/W/H) This metapacket is a fake passed forward after a prune. */
        uint64_t child                 : 10; /**< [ 51: 42](R/W/H) Child index. When the C_CON bit of this result is set, indicating that this result is
                                                                 connected in a flow that extends through the child result, this is the index of that child
                                                                 result. */
        uint64_t color                 : 2;  /**< [ 53: 52](R/W/H) See PKO_COLORRESULT_E. */
        uint64_t dq                    : 10; /**< [ 63: 54](R/W/H) Descriptor queue. Index of originating descriptor queue. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_pick_s cn; */
} bdk_pko_l1_sqx_pick_t;

static inline uint64_t BDK_PKO_L1_SQX_PICK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_PICK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000080070ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_PICK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_PICK(a) bdk_pko_l1_sqx_pick_t
#define bustype_BDK_PKO_L1_SQX_PICK(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_PICK(a) "PKO_L1_SQX_PICK"
#define device_bar_BDK_PKO_L1_SQX_PICK(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_PICK(a) (a)
#define arguments_BDK_PKO_L1_SQX_PICK(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_red
 *
 * INTERNAL: PKO PSE Level 1 Shaping Queue Red State Debug Register
 *
 * This register has the same bit fields as PKO_L1_SQ()_YELLOW.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_red_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t head                  : 9;  /**< [ 18: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_9            : 1;
        uint64_t tail                  : 9;  /**< [  8:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
#else /* Word 0 - Little Endian */
        uint64_t tail                  : 9;  /**< [  8:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
        uint64_t reserved_9            : 1;
        uint64_t head                  : 9;  /**< [ 18: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_red_s cn; */
} bdk_pko_l1_sqx_red_t;

static inline uint64_t BDK_PKO_L1_SQX_RED(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_RED(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000080068ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_RED", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_RED(a) bdk_pko_l1_sqx_red_t
#define bustype_BDK_PKO_L1_SQX_RED(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_RED(a) "PKO_L1_SQX_RED"
#define device_bar_BDK_PKO_L1_SQX_RED(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_RED(a) (a)
#define arguments_BDK_PKO_L1_SQX_RED(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_red_bytes
 *
 * PKO PSE Port Queue Red Sent Bytes Register
 * This register has the same bit fields as PKO_L1_SQ()_GREEN_BYTES.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_red_bytes_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t count                 : 48; /**< [ 47:  0](R/W/H) Count. The running count of bytes. Note that this count wraps. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 48; /**< [ 47:  0](R/W/H) Count. The running count of bytes. Note that this count wraps. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_red_bytes_s cn; */
} bdk_pko_l1_sqx_red_bytes_t;

static inline uint64_t BDK_PKO_L1_SQX_RED_BYTES(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_RED_BYTES(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000000098ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_RED_BYTES", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_RED_BYTES(a) bdk_pko_l1_sqx_red_bytes_t
#define bustype_BDK_PKO_L1_SQX_RED_BYTES(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_RED_BYTES(a) "PKO_L1_SQX_RED_BYTES"
#define device_bar_BDK_PKO_L1_SQX_RED_BYTES(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_RED_BYTES(a) (a)
#define arguments_BDK_PKO_L1_SQX_RED_BYTES(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_red_packets
 *
 * PKO PSE Port Queue Red Sent Packets Register
 * This register has the same bit fields as PKO_L1_SQ()_GREEN_PACKETS.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_red_packets_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t count                 : 40; /**< [ 39:  0](R/W/H) Count. The running count of packets. Note that this count wraps. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 40; /**< [ 39:  0](R/W/H) Count. The running count of packets. Note that this count wraps. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_red_packets_s cn; */
} bdk_pko_l1_sqx_red_packets_t;

static inline uint64_t BDK_PKO_L1_SQX_RED_PACKETS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_RED_PACKETS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000000090ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_RED_PACKETS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_RED_PACKETS(a) bdk_pko_l1_sqx_red_packets_t
#define bustype_BDK_PKO_L1_SQX_RED_PACKETS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_RED_PACKETS(a) "PKO_L1_SQX_RED_PACKETS"
#define device_bar_BDK_PKO_L1_SQX_RED_PACKETS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_RED_PACKETS(a) (a)
#define arguments_BDK_PKO_L1_SQX_RED_PACKETS(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_schedule
 *
 * PKO PSE Level 1 Scheduling Control Register
 * PKO_CHANNEL_LEVEL[CC_LEVEL] determines whether this CSR array is associated to
 * the L2 SQ's or the L3 SQ's.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_schedule_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t rr_quantum            : 24; /**< [ 23:  0](R/W) Round-robin (DWRR) quantum. The deficit-weighted round-robin quantum (24-bit unsigned
                                                                 integer).

                                                                 Typically [RR_QUANTUM] should be at or near the MTU or more (to limit or prevent
                                                                 negative accumulations of the deficit count). */
#else /* Word 0 - Little Endian */
        uint64_t rr_quantum            : 24; /**< [ 23:  0](R/W) Round-robin (DWRR) quantum. The deficit-weighted round-robin quantum (24-bit unsigned
                                                                 integer).

                                                                 Typically [RR_QUANTUM] should be at or near the MTU or more (to limit or prevent
                                                                 negative accumulations of the deficit count). */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_schedule_s cn; */
} bdk_pko_l1_sqx_schedule_t;

static inline uint64_t BDK_PKO_L1_SQX_SCHEDULE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_SCHEDULE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000000008ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_SCHEDULE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_SCHEDULE(a) bdk_pko_l1_sqx_schedule_t
#define bustype_BDK_PKO_L1_SQX_SCHEDULE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_SCHEDULE(a) "PKO_L1_SQX_SCHEDULE"
#define device_bar_BDK_PKO_L1_SQX_SCHEDULE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_SCHEDULE(a) (a)
#define arguments_BDK_PKO_L1_SQX_SCHEDULE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_shape
 *
 * PKO PSE Level 1 Shaping Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_shape_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_25_63        : 39;
        uint64_t length_disable        : 1;  /**< [ 24: 24](R/W) Length disable. Disables the use of packet lengths in DWRR scheduling
                                                                 and shaping calculations such that only the value of [ADJUST] is used. */
        uint64_t reserved_18_23        : 6;
        uint64_t link                  : 5;  /**< [ 17: 13](R/W) Link index. Must match PKO_L1_SQ()_TOPOLOGY[LINK]. */
        uint64_t reserved_9_12         : 4;
        uint64_t adjust                : 9;  /**< [  8:  0](R/W) Shaping and scheduling calculation adjustment. This 9-bit signed value
                                                                 allows -255 .. 255 bytes to be added to the packet length for rate
                                                                 limiting and scheduling calculations. [ADJUST] value 0x100 should
                                                                 not be used. */
#else /* Word 0 - Little Endian */
        uint64_t adjust                : 9;  /**< [  8:  0](R/W) Shaping and scheduling calculation adjustment. This 9-bit signed value
                                                                 allows -255 .. 255 bytes to be added to the packet length for rate
                                                                 limiting and scheduling calculations. [ADJUST] value 0x100 should
                                                                 not be used. */
        uint64_t reserved_9_12         : 4;
        uint64_t link                  : 5;  /**< [ 17: 13](R/W) Link index. Must match PKO_L1_SQ()_TOPOLOGY[LINK]. */
        uint64_t reserved_18_23        : 6;
        uint64_t length_disable        : 1;  /**< [ 24: 24](R/W) Length disable. Disables the use of packet lengths in DWRR scheduling
                                                                 and shaping calculations such that only the value of [ADJUST] is used. */
        uint64_t reserved_25_63        : 39;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_shape_s cn; */
} bdk_pko_l1_sqx_shape_t;

static inline uint64_t BDK_PKO_L1_SQX_SHAPE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_SHAPE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000000010ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_SHAPE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_SHAPE(a) bdk_pko_l1_sqx_shape_t
#define bustype_BDK_PKO_L1_SQX_SHAPE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_SHAPE(a) "PKO_L1_SQX_SHAPE"
#define device_bar_BDK_PKO_L1_SQX_SHAPE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_SHAPE(a) (a)
#define arguments_BDK_PKO_L1_SQX_SHAPE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_shape_state
 *
 * PKO PSE Level 1 Shaping Queue Shape State Register
 * This register must not be written during normal operation.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_shape_state_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t tw_timestamp          : 6;  /**< [ 59: 54](R/W/H) Time-wheel timestamp. Debug access to the live time-wheel timestamp. */
        uint64_t reserved_53           : 1;
        uint64_t color                 : 1;  /**< [ 52: 52](R/W/H) Shaper connection status. Debug access to the live shaper state.
                                                                 0 = Connected - shaper is connected.
                                                                 1 = Pruned - shaper is disconnected. */
        uint64_t reserved_26_51        : 26;
        uint64_t cir_accum             : 26; /**< [ 25:  0](R/W/H) Committed information rate accumulator. Debug access to the live CIR accumulator. */
#else /* Word 0 - Little Endian */
        uint64_t cir_accum             : 26; /**< [ 25:  0](R/W/H) Committed information rate accumulator. Debug access to the live CIR accumulator. */
        uint64_t reserved_26_51        : 26;
        uint64_t color                 : 1;  /**< [ 52: 52](R/W/H) Shaper connection status. Debug access to the live shaper state.
                                                                 0 = Connected - shaper is connected.
                                                                 1 = Pruned - shaper is disconnected. */
        uint64_t reserved_53           : 1;
        uint64_t tw_timestamp          : 6;  /**< [ 59: 54](R/W/H) Time-wheel timestamp. Debug access to the live time-wheel timestamp. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_shape_state_s cn; */
} bdk_pko_l1_sqx_shape_state_t;

static inline uint64_t BDK_PKO_L1_SQX_SHAPE_STATE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_SHAPE_STATE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000000030ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_SHAPE_STATE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_SHAPE_STATE(a) bdk_pko_l1_sqx_shape_state_t
#define bustype_BDK_PKO_L1_SQX_SHAPE_STATE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_SHAPE_STATE(a) "PKO_L1_SQX_SHAPE_STATE"
#define device_bar_BDK_PKO_L1_SQX_SHAPE_STATE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_SHAPE_STATE(a) (a)
#define arguments_BDK_PKO_L1_SQX_SHAPE_STATE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_sw_xoff
 *
 * PKO PSE Level 1 Shaping Queue Software Controlled XOFF Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_sw_xoff_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t drain_irq             : 1;  /**< [  3:  3](WO) Drain IRQ. Enables an interrupt that fires when the drain operation has completed.
                                                                 [DRAIN_IRQ] should be set whenever [DRAIN] is, and must not be set
                                                                 when [DRAIN] isn't set. [DRAIN_IRQ] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t drain_null_link       : 1;  /**< [  2:  2](WO) Drain null link. This setting only has effect when the L1 node is
                                                                 mapped to the NULL FIFO.  Conditions the drain path to drain through
                                                                 the NULL FIFO (i.e. link 14). As such, channel credits, HW_XOFF, and
                                                                 shaping are disabled on the draining path until the path has drained.
                                                                 [DRAIN_NULL_LINK] must not be set when [DRAIN] isn't set.
                                                                 [DRAIN_NULL_LINK] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t drain                 : 1;  /**< [  1:  1](WO) Drain. This control activates a drain path through the PSE that starts at this node and
                                                                 ends at the SQ1 level. The drain path is prioritized over other paths through PSE and can
                                                                 be used in combination with [DRAIN_NULL_LINK] and [DRAIN_IRQ]. [DRAIN] need never be
                                                                 set for the SQ1 level, but is useful at all other levels, including the DQ level.
                                                                 PKO_PQ_DRAIN_W1C[INTR] should be clear prior to initiating a [DRAIN]=1 write to this CSR.
                                                                 After [DRAIN] is set for an SQ/DQ, it should not be set again, for this or any other
                                                                 SQ/DQ, until after a 0->1 transition has been observed on PKO_PQ_DRAIN_W1C[INTR]
                                                                 (and/or the PKO_PSE_PQ_DRAIN interrupt has occured) and
                                                                 PKO_PQ_DRAIN_W1C[INTR] has been cleared.  DRAIN has no effect unless XOFF is also set.
                                                                 Only one DRAIN command is allowed to be active at a time. */
        uint64_t xoff                  : 1;  /**< [  0:  0](R/W) XOFF. Stops meta flow out of the SQ/DQ. When [XOFF] is set, the corresponding
                                                                 PKO_*_PICK (i.e. the meta) in the SQ/DQ cannot be transferred to the
                                                                 next level. The corresponding PKO_*_PICK may become valid while [XOFF] is set,
                                                                 but it cannot change from valid to invalid while [XOFF] is set.
                                                                 NOTE: The associated PKO_*_TOPOLOGY[LINK/PARENT] should normally be configured before
                                                                 [XOFF] is set. Setting [XOFF] before the associated PKO_*_TOPOLOGY[LINK/PARENT]
                                                                 value is configured can result in modifying the software [XOFF] state of the wrong SQ. */
#else /* Word 0 - Little Endian */
        uint64_t xoff                  : 1;  /**< [  0:  0](R/W) XOFF. Stops meta flow out of the SQ/DQ. When [XOFF] is set, the corresponding
                                                                 PKO_*_PICK (i.e. the meta) in the SQ/DQ cannot be transferred to the
                                                                 next level. The corresponding PKO_*_PICK may become valid while [XOFF] is set,
                                                                 but it cannot change from valid to invalid while [XOFF] is set.
                                                                 NOTE: The associated PKO_*_TOPOLOGY[LINK/PARENT] should normally be configured before
                                                                 [XOFF] is set. Setting [XOFF] before the associated PKO_*_TOPOLOGY[LINK/PARENT]
                                                                 value is configured can result in modifying the software [XOFF] state of the wrong SQ. */
        uint64_t drain                 : 1;  /**< [  1:  1](WO) Drain. This control activates a drain path through the PSE that starts at this node and
                                                                 ends at the SQ1 level. The drain path is prioritized over other paths through PSE and can
                                                                 be used in combination with [DRAIN_NULL_LINK] and [DRAIN_IRQ]. [DRAIN] need never be
                                                                 set for the SQ1 level, but is useful at all other levels, including the DQ level.
                                                                 PKO_PQ_DRAIN_W1C[INTR] should be clear prior to initiating a [DRAIN]=1 write to this CSR.
                                                                 After [DRAIN] is set for an SQ/DQ, it should not be set again, for this or any other
                                                                 SQ/DQ, until after a 0->1 transition has been observed on PKO_PQ_DRAIN_W1C[INTR]
                                                                 (and/or the PKO_PSE_PQ_DRAIN interrupt has occured) and
                                                                 PKO_PQ_DRAIN_W1C[INTR] has been cleared.  DRAIN has no effect unless XOFF is also set.
                                                                 Only one DRAIN command is allowed to be active at a time. */
        uint64_t drain_null_link       : 1;  /**< [  2:  2](WO) Drain null link. This setting only has effect when the L1 node is
                                                                 mapped to the NULL FIFO.  Conditions the drain path to drain through
                                                                 the NULL FIFO (i.e. link 14). As such, channel credits, HW_XOFF, and
                                                                 shaping are disabled on the draining path until the path has drained.
                                                                 [DRAIN_NULL_LINK] must not be set when [DRAIN] isn't set.
                                                                 [DRAIN_NULL_LINK] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t drain_irq             : 1;  /**< [  3:  3](WO) Drain IRQ. Enables an interrupt that fires when the drain operation has completed.
                                                                 [DRAIN_IRQ] should be set whenever [DRAIN] is, and must not be set
                                                                 when [DRAIN] isn't set. [DRAIN_IRQ] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_sw_xoff_s cn; */
} bdk_pko_l1_sqx_sw_xoff_t;

static inline uint64_t BDK_PKO_L1_SQX_SW_XOFF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_SW_XOFF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x8540000000e0ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_SW_XOFF", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_SW_XOFF(a) bdk_pko_l1_sqx_sw_xoff_t
#define bustype_BDK_PKO_L1_SQX_SW_XOFF(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_SW_XOFF(a) "PKO_L1_SQX_SW_XOFF"
#define device_bar_BDK_PKO_L1_SQX_SW_XOFF(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_SW_XOFF(a) (a)
#define arguments_BDK_PKO_L1_SQX_SW_XOFF(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_topology
 *
 * PKO PSE Level 1 Shaping Queue Topology Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_topology_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t prio_anchor           : 8;  /**< [ 39: 32](R/W) Priority anchor. The base index positioning the static priority child queues of this
                                                                 shaper. A higher-level queue is a child queue of this shaper when its
                                                                 PKO_*_TOPOLOGY[PARENT] selects this shaper, and it further is a static priority child
                                                                 queue when its PKO_*_SQn_SCHEDULE[PRIO] does not equal [RR_PRIO]. A static priority child
                                                                 queue with priority PRIO must be located at n=[PRIO_ANCHOR]+PRIO, where
                                                                 PRIO=PKO_*_SQn_SCHEDULE[PRIO]. There can be at most one static priority child queue at
                                                                 each priority. When there are no static priority child queues attached at any priority, or
                                                                 if this shaper isn't used, the hardware does not use [PRIO_ANCHOR]. In this case, we
                                                                 recommend [PRIO_ANCHOR] be zero. Note that there are 10 available priorities, 0 through 9,
                                                                 with priority 0 being the highest and priority 9 being the lowest. */
        uint64_t reserved_21_31        : 11;
        uint64_t link                  : 5;  /**< [ 20: 16](R/W) Link index. Selects the MAC or NULL FIFO used by the L1 SQ.

                                                                 Legal [LINK] values:

                                                                 <pre>
                                                                    LINK/          Relevant
                                                                  MAC_NUM     PKO_MAC()_CFG CSR    Description
                                                                  -------------------------------------------------
                                                                     0         PKO_MAC0_CFG      LBK loopback
                                                                     1         PKO_MAC1_CFG      LBK loopback
                                                                     2         PKO_MAC2_CFG      DPI packet output
                                                                     3         PKO_MAC3_CFG      BGX0 logical MAC 0
                                                                     4         PKO_MAC4_CFG      BGX0 logical MAC 1
                                                                     5         PKO_MAC5_CFG      BGX0 logical MAC 2
                                                                     6         PKO_MAC6_CFG      BGX0 logical MAC 3
                                                                     7         PKO_MAC7_CFG      BGX1 logical MAC 0
                                                                     8         PKO_MAC8_CFG      BGX1 logical MAC 1
                                                                     9         PKO_MAC9_CFG      BGX1 logical MAC 2
                                                                    10         PKO_MAC10_CFG     BGX1 logical MAC 3
                                                                    11         PKO_MAC11_CFG     BGX2 logical MAC 0
                                                                    12         PKO_MAC12_CFG     BGX2 logical MAC 1
                                                                    13         PKO_MAC13_CFG     BGX2 logical MAC 2
                                                                    14         PKO_MAC14_CFG     BGX2 logical MAC 3
                                                                    15         PKO_MAC15_CFG     BGX3 logical MAC 0
                                                                    16         PKO_MAC16_CFG     BGX3 logical MAC 1
                                                                    17         PKO_MAC17_CFG     BGX3 logical MAC 2
                                                                    18         PKO_MAC18_CFG     BGX3 logical MAC 3
                                                                    19            None           NULL FIFO
                                                                 </pre>

                                                                 When a MAC is used by the L1 SQ, [LINK] must be unique relative to
                                                                 other [LINK]s. [LINK] should be 14 when the L1 SQ is not used. */
        uint64_t reserved_5_15         : 11;
        uint64_t rr_prio               : 4;  /**< [  4:  1](R/W) Round-robin priority. The priority assigned to the round-robin scheduler. A higher-level
                                                                 queue is a child queue of this shaper when its PKO_*_TOPOLOGY[PARENT] selects this shaper,
                                                                 and it further is a round robin child queue when its PKO_*_SQn_SCHEDULE[PRIO] equals
                                                                 [RR_PRIO]. All round-robin queues attached to this shaper must have the same priority. But
                                                                 the number of round-robin child queues attached (at this priority) is limited only by the
                                                                 number of higher-level queues. When this shaper is not used, we recommend [RR_PRIO] be
                                                                 zero.
                                                                 When a shaper is used, [RR_PRIO] should be 0xF when there are no priorities with more than
                                                                 one child queue (i.e. when there are no round-robin child queues), and should otherwise be
                                                                 a legal priority (values 0-9). */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t rr_prio               : 4;  /**< [  4:  1](R/W) Round-robin priority. The priority assigned to the round-robin scheduler. A higher-level
                                                                 queue is a child queue of this shaper when its PKO_*_TOPOLOGY[PARENT] selects this shaper,
                                                                 and it further is a round robin child queue when its PKO_*_SQn_SCHEDULE[PRIO] equals
                                                                 [RR_PRIO]. All round-robin queues attached to this shaper must have the same priority. But
                                                                 the number of round-robin child queues attached (at this priority) is limited only by the
                                                                 number of higher-level queues. When this shaper is not used, we recommend [RR_PRIO] be
                                                                 zero.
                                                                 When a shaper is used, [RR_PRIO] should be 0xF when there are no priorities with more than
                                                                 one child queue (i.e. when there are no round-robin child queues), and should otherwise be
                                                                 a legal priority (values 0-9). */
        uint64_t reserved_5_15         : 11;
        uint64_t link                  : 5;  /**< [ 20: 16](R/W) Link index. Selects the MAC or NULL FIFO used by the L1 SQ.

                                                                 Legal [LINK] values:

                                                                 <pre>
                                                                    LINK/          Relevant
                                                                  MAC_NUM     PKO_MAC()_CFG CSR    Description
                                                                  -------------------------------------------------
                                                                     0         PKO_MAC0_CFG      LBK loopback
                                                                     1         PKO_MAC1_CFG      LBK loopback
                                                                     2         PKO_MAC2_CFG      DPI packet output
                                                                     3         PKO_MAC3_CFG      BGX0 logical MAC 0
                                                                     4         PKO_MAC4_CFG      BGX0 logical MAC 1
                                                                     5         PKO_MAC5_CFG      BGX0 logical MAC 2
                                                                     6         PKO_MAC6_CFG      BGX0 logical MAC 3
                                                                     7         PKO_MAC7_CFG      BGX1 logical MAC 0
                                                                     8         PKO_MAC8_CFG      BGX1 logical MAC 1
                                                                     9         PKO_MAC9_CFG      BGX1 logical MAC 2
                                                                    10         PKO_MAC10_CFG     BGX1 logical MAC 3
                                                                    11         PKO_MAC11_CFG     BGX2 logical MAC 0
                                                                    12         PKO_MAC12_CFG     BGX2 logical MAC 1
                                                                    13         PKO_MAC13_CFG     BGX2 logical MAC 2
                                                                    14         PKO_MAC14_CFG     BGX2 logical MAC 3
                                                                    15         PKO_MAC15_CFG     BGX3 logical MAC 0
                                                                    16         PKO_MAC16_CFG     BGX3 logical MAC 1
                                                                    17         PKO_MAC17_CFG     BGX3 logical MAC 2
                                                                    18         PKO_MAC18_CFG     BGX3 logical MAC 3
                                                                    19            None           NULL FIFO
                                                                 </pre>

                                                                 When a MAC is used by the L1 SQ, [LINK] must be unique relative to
                                                                 other [LINK]s. [LINK] should be 14 when the L1 SQ is not used. */
        uint64_t reserved_21_31        : 11;
        uint64_t prio_anchor           : 8;  /**< [ 39: 32](R/W) Priority anchor. The base index positioning the static priority child queues of this
                                                                 shaper. A higher-level queue is a child queue of this shaper when its
                                                                 PKO_*_TOPOLOGY[PARENT] selects this shaper, and it further is a static priority child
                                                                 queue when its PKO_*_SQn_SCHEDULE[PRIO] does not equal [RR_PRIO]. A static priority child
                                                                 queue with priority PRIO must be located at n=[PRIO_ANCHOR]+PRIO, where
                                                                 PRIO=PKO_*_SQn_SCHEDULE[PRIO]. There can be at most one static priority child queue at
                                                                 each priority. When there are no static priority child queues attached at any priority, or
                                                                 if this shaper isn't used, the hardware does not use [PRIO_ANCHOR]. In this case, we
                                                                 recommend [PRIO_ANCHOR] be zero. Note that there are 10 available priorities, 0 through 9,
                                                                 with priority 0 being the highest and priority 9 being the lowest. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_topology_s cn; */
} bdk_pko_l1_sqx_topology_t;

static inline uint64_t BDK_PKO_L1_SQX_TOPOLOGY(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_TOPOLOGY(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000080000ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_TOPOLOGY", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_TOPOLOGY(a) bdk_pko_l1_sqx_topology_t
#define bustype_BDK_PKO_L1_SQX_TOPOLOGY(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_TOPOLOGY(a) "PKO_L1_SQX_TOPOLOGY"
#define device_bar_BDK_PKO_L1_SQX_TOPOLOGY(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_TOPOLOGY(a) (a)
#define arguments_BDK_PKO_L1_SQX_TOPOLOGY(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_yellow
 *
 * INTERNAL: PKO PSE Level 1 Shaping Queue Yellow State Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_yellow_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t head                  : 9;  /**< [ 18: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_9            : 1;
        uint64_t tail                  : 9;  /**< [  8:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
#else /* Word 0 - Little Endian */
        uint64_t tail                  : 9;  /**< [  8:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
        uint64_t reserved_9            : 1;
        uint64_t head                  : 9;  /**< [ 18: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_yellow_s cn; */
} bdk_pko_l1_sqx_yellow_t;

static inline uint64_t BDK_PKO_L1_SQX_YELLOW(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_YELLOW(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854000080060ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_YELLOW", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_YELLOW(a) bdk_pko_l1_sqx_yellow_t
#define bustype_BDK_PKO_L1_SQX_YELLOW(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_YELLOW(a) "PKO_L1_SQX_YELLOW"
#define device_bar_BDK_PKO_L1_SQX_YELLOW(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_YELLOW(a) (a)
#define arguments_BDK_PKO_L1_SQX_YELLOW(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_yellow_bytes
 *
 * PKO PSE Port Queue Yellow Sent Bytes Register
 * This register has the same bit fields as PKO_L1_SQ()_GREEN_BYTES.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_yellow_bytes_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t count                 : 48; /**< [ 47:  0](R/W/H) Count. The running count of bytes. Note that this count wraps. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 48; /**< [ 47:  0](R/W/H) Count. The running count of bytes. Note that this count wraps. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_yellow_bytes_s cn; */
} bdk_pko_l1_sqx_yellow_bytes_t;

static inline uint64_t BDK_PKO_L1_SQX_YELLOW_BYTES(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_YELLOW_BYTES(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x8540000000a8ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_YELLOW_BYTES", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_YELLOW_BYTES(a) bdk_pko_l1_sqx_yellow_bytes_t
#define bustype_BDK_PKO_L1_SQX_YELLOW_BYTES(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_YELLOW_BYTES(a) "PKO_L1_SQX_YELLOW_BYTES"
#define device_bar_BDK_PKO_L1_SQX_YELLOW_BYTES(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_YELLOW_BYTES(a) (a)
#define arguments_BDK_PKO_L1_SQX_YELLOW_BYTES(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sq#_yellow_packets
 *
 * PKO PSE Port Queue Yellow Sent Packets Register
 * This register has the same bit fields as PKO_L1_SQ()_GREEN_PACKETS.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqx_yellow_packets_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t count                 : 40; /**< [ 39:  0](R/W/H) Count. The running count of packets. Note that this count wraps. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 40; /**< [ 39:  0](R/W/H) Count. The running count of packets. Note that this count wraps. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqx_yellow_packets_s cn; */
} bdk_pko_l1_sqx_yellow_packets_t;

static inline uint64_t BDK_PKO_L1_SQX_YELLOW_PACKETS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQX_YELLOW_PACKETS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x8540000000a0ll + 0x200ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_L1_SQX_YELLOW_PACKETS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQX_YELLOW_PACKETS(a) bdk_pko_l1_sqx_yellow_packets_t
#define bustype_BDK_PKO_L1_SQX_YELLOW_PACKETS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQX_YELLOW_PACKETS(a) "PKO_L1_SQX_YELLOW_PACKETS"
#define device_bar_BDK_PKO_L1_SQX_YELLOW_PACKETS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQX_YELLOW_PACKETS(a) (a)
#define arguments_BDK_PKO_L1_SQX_YELLOW_PACKETS(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l1_sqa_debug
 *
 * INTERNAL: PKO PSE Level 1 SQ-A Internal Debug Register
 *
 * This register has the same bit fields as PKO_PQA_DEBUG.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqa_debug_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#else /* Word 0 - Little Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqa_debug_s cn; */
} bdk_pko_l1_sqa_debug_t;

#define BDK_PKO_L1_SQA_DEBUG BDK_PKO_L1_SQA_DEBUG_FUNC()
static inline uint64_t BDK_PKO_L1_SQA_DEBUG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQA_DEBUG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000080128ll;
    __bdk_csr_fatal("PKO_L1_SQA_DEBUG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQA_DEBUG bdk_pko_l1_sqa_debug_t
#define bustype_BDK_PKO_L1_SQA_DEBUG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQA_DEBUG "PKO_L1_SQA_DEBUG"
#define device_bar_BDK_PKO_L1_SQA_DEBUG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQA_DEBUG 0
#define arguments_BDK_PKO_L1_SQA_DEBUG -1,-1,-1,-1

/**
 * Register (NCB) pko_l1_sqb_debug
 *
 * INTERNAL: PKO PSE Level 1 SQ-B Internal Debug Register
 *
 * This register has the same bit fields as PKO_PQA_DEBUG.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l1_sqb_debug_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#else /* Word 0 - Little Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l1_sqb_debug_s cn; */
} bdk_pko_l1_sqb_debug_t;

#define BDK_PKO_L1_SQB_DEBUG BDK_PKO_L1_SQB_DEBUG_FUNC()
static inline uint64_t BDK_PKO_L1_SQB_DEBUG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L1_SQB_DEBUG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000080130ll;
    __bdk_csr_fatal("PKO_L1_SQB_DEBUG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_L1_SQB_DEBUG bdk_pko_l1_sqb_debug_t
#define bustype_BDK_PKO_L1_SQB_DEBUG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L1_SQB_DEBUG "PKO_L1_SQB_DEBUG"
#define device_bar_BDK_PKO_L1_SQB_DEBUG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L1_SQB_DEBUG 0
#define arguments_BDK_PKO_L1_SQB_DEBUG -1,-1,-1,-1

/**
 * Register (NCB) pko_l2_const
 *
 * PKO Level 2 Constants Register
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t count                 : 16; /**< [ 15:  0](RO) Number of Level-2 shaping queues. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 16; /**< [ 15:  0](RO) Number of Level-2 shaping queues. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_const_s cn; */
} bdk_pko_l2_const_t;

#define BDK_PKO_L2_CONST BDK_PKO_L2_CONST_FUNC()
static inline uint64_t BDK_PKO_L2_CONST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_CONST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000d00108ll;
    __bdk_csr_fatal("PKO_L2_CONST", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_CONST bdk_pko_l2_const_t
#define bustype_BDK_PKO_L2_CONST BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_CONST "PKO_L2_CONST"
#define device_bar_BDK_PKO_L2_CONST 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_CONST 0
#define arguments_BDK_PKO_L2_CONST -1,-1,-1,-1

/**
 * Register (NCB) pko_l2_sq#_cir
 *
 * PKO PSE Level 2 Shaping Queue Committed Information Rate Register
 * This register has the same bit fields as PKO_L1_SQ()_CIR.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqx_cir_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_41_63        : 23;
        uint64_t burst_exponent        : 4;  /**< [ 40: 37](R/W) Burst exponent. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t burst_mantissa        : 8;  /**< [ 36: 29](R/W) Burst mantissa. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t reserved_17_28        : 12;
        uint64_t rate_divider_exponent : 4;  /**< [ 16: 13](R/W) Rate divider exponent. This 4-bit base-2 exponent is used to divide the credit rate by
                                                                 specifying the number of time-wheel turns required before the accumulator is increased.
                                                                 [RATE_DIVIDER_EXPONENT] should be used to specify data rates lower than ~10 Kbps and
                                                                 [RATE_EXPONENT] should be set to zero whenever it is used.

                                                                 The rate count = (1 << [RATE_DIVIDER_EXPONENT]). The supported range for
                                                                 [RATE_DIVIDER_EXPONENT] is 0 to 12. Programmed values greater than 12 are treated as 12.

                                                                 Note that for the L1-SQs, a time-wheel turn is 96 clocks (SCLK). For the other levels a
                                                                 time-wheel turn is 768 clocks (SCLK).

                                                                 For L1_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 96) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1
                                                                 <<[RATE_DIVIDER_EXPONENT])

                                                                 For L[5:2]_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 768) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1 <<
                                                                 [RATE_DIVIDER_EXPONENT]) */
        uint64_t rate_exponent         : 4;  /**< [ 12:  9](R/W) Rate exponent. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT].
                                                                 [RATE_EXPONENT] should be used to specify data rates higher than ~10 Kbps and
                                                                 [RATE_DIVIDER_EXPONENT] should be set to zero whenever it is nonzero. */
        uint64_t rate_mantissa         : 8;  /**< [  8:  1](R/W) Rate mantissa. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT]. */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable. Enables CIR shaping. */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable. Enables CIR shaping. */
        uint64_t rate_mantissa         : 8;  /**< [  8:  1](R/W) Rate mantissa. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT]. */
        uint64_t rate_exponent         : 4;  /**< [ 12:  9](R/W) Rate exponent. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT].
                                                                 [RATE_EXPONENT] should be used to specify data rates higher than ~10 Kbps and
                                                                 [RATE_DIVIDER_EXPONENT] should be set to zero whenever it is nonzero. */
        uint64_t rate_divider_exponent : 4;  /**< [ 16: 13](R/W) Rate divider exponent. This 4-bit base-2 exponent is used to divide the credit rate by
                                                                 specifying the number of time-wheel turns required before the accumulator is increased.
                                                                 [RATE_DIVIDER_EXPONENT] should be used to specify data rates lower than ~10 Kbps and
                                                                 [RATE_EXPONENT] should be set to zero whenever it is used.

                                                                 The rate count = (1 << [RATE_DIVIDER_EXPONENT]). The supported range for
                                                                 [RATE_DIVIDER_EXPONENT] is 0 to 12. Programmed values greater than 12 are treated as 12.

                                                                 Note that for the L1-SQs, a time-wheel turn is 96 clocks (SCLK). For the other levels a
                                                                 time-wheel turn is 768 clocks (SCLK).

                                                                 For L1_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 96) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1
                                                                 <<[RATE_DIVIDER_EXPONENT])

                                                                 For L[5:2]_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 768) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1 <<
                                                                 [RATE_DIVIDER_EXPONENT]) */
        uint64_t reserved_17_28        : 12;
        uint64_t burst_mantissa        : 8;  /**< [ 36: 29](R/W) Burst mantissa. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t burst_exponent        : 4;  /**< [ 40: 37](R/W) Burst exponent. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t reserved_41_63        : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqx_cir_s cn; */
} bdk_pko_l2_sqx_cir_t;

static inline uint64_t BDK_PKO_L2_SQX_CIR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQX_CIR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000080018ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L2_SQX_CIR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQX_CIR(a) bdk_pko_l2_sqx_cir_t
#define bustype_BDK_PKO_L2_SQX_CIR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQX_CIR(a) "PKO_L2_SQX_CIR"
#define device_bar_BDK_PKO_L2_SQX_CIR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQX_CIR(a) (a)
#define arguments_BDK_PKO_L2_SQX_CIR(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l2_sq#_green
 *
 * INTERNAL: PKO PSE Level 2 Shaping Queue Green State Debug Register
 *
 * This register has the same bit fields as PKO_L1_SQ()_GREEN.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqx_green_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_41_63        : 23;
        uint64_t rr_active             : 1;  /**< [ 40: 40](R/W/H) Round-robin red active. Set when the RED_SEND+RED_DROP DWRR child list is not empty.
                                                                 For internal use only. */
        uint64_t active_vec            : 20; /**< [ 39: 20](R/W/H) Active vector. A 20-bit vector, 2 bits per each of the 10 supported priorities.
                                                                 For the non-RR_PRIO priorities, the 2 bits encode whether the child is active
                                                                 GREEN, active YELLOW, active RED_SEND+RED_DROP, or inactive. At RR_PRIO, one
                                                                 bit is set if the GREEN DWRR child list is not empty, and the other is set if the
                                                                 YELLOW DWRR child list is not empty. For internal use only. */
        uint64_t reserved_19           : 1;
        uint64_t head                  : 9;  /**< [ 18: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_9            : 1;
        uint64_t tail                  : 9;  /**< [  8:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
#else /* Word 0 - Little Endian */
        uint64_t tail                  : 9;  /**< [  8:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
        uint64_t reserved_9            : 1;
        uint64_t head                  : 9;  /**< [ 18: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_19           : 1;
        uint64_t active_vec            : 20; /**< [ 39: 20](R/W/H) Active vector. A 20-bit vector, 2 bits per each of the 10 supported priorities.
                                                                 For the non-RR_PRIO priorities, the 2 bits encode whether the child is active
                                                                 GREEN, active YELLOW, active RED_SEND+RED_DROP, or inactive. At RR_PRIO, one
                                                                 bit is set if the GREEN DWRR child list is not empty, and the other is set if the
                                                                 YELLOW DWRR child list is not empty. For internal use only. */
        uint64_t rr_active             : 1;  /**< [ 40: 40](R/W/H) Round-robin red active. Set when the RED_SEND+RED_DROP DWRR child list is not empty.
                                                                 For internal use only. */
        uint64_t reserved_41_63        : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqx_green_s cn; */
} bdk_pko_l2_sqx_green_t;

static inline uint64_t BDK_PKO_L2_SQX_GREEN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQX_GREEN(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000100058ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L2_SQX_GREEN", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQX_GREEN(a) bdk_pko_l2_sqx_green_t
#define bustype_BDK_PKO_L2_SQX_GREEN(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQX_GREEN(a) "PKO_L2_SQX_GREEN"
#define device_bar_BDK_PKO_L2_SQX_GREEN(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQX_GREEN(a) (a)
#define arguments_BDK_PKO_L2_SQX_GREEN(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l2_sq#_pick
 *
 * PKO PSE Level 2 Shaping Queue Packet Pick State Debug Register
 * This CSR contains the meta for the L2 SQ, and is for debug and reconfiguration
 * only and should never be written. See also PKO_META_DESC_S.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqx_pick_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dq                    : 10; /**< [ 63: 54](R/W/H) Descriptor queue. Index of originating descriptor queue. */
        uint64_t color                 : 2;  /**< [ 53: 52](R/W/H) See PKO_COLORRESULT_E. */
        uint64_t child                 : 10; /**< [ 51: 42](R/W/H) Child index. When the C_CON bit of this result is set, indicating that this result is
                                                                 connected in a flow that extends through the child result, this is the index of that child
                                                                 result. */
        uint64_t bubble                : 1;  /**< [ 41: 41](R/W/H) This metapacket is a fake passed forward after a prune. */
        uint64_t p_con                 : 1;  /**< [ 40: 40](R/W/H) Parent connected flag. This pick has more picks in front of it. */
        uint64_t c_con                 : 1;  /**< [ 39: 39](R/W/H) Child connected flag. This pick has more picks behind it. */
        uint64_t uid                   : 7;  /**< [ 38: 32](R/W/H) Unique ID. 7-bit unique value assigned at the DQ level, increments for each packet. */
        uint64_t jump                  : 1;  /**< [ 31: 31](R/W/H) Set when the corresponding descriptor contains a PKO_SEND_JUMP_S.  See also
                                                                 PKO_META_DESC_S[JUMP]. */
        uint64_t fpd                   : 1;  /**< [ 30: 30](R/W/H) First packet descriptor. Set when corresponding descriptor is the first in a cacheline.
                                                                 See also PKO_META_DESC_S[FPD]. */
        uint64_t ds                    : 1;  /**< [ 29: 29](R/W/H) PKO_SEND_HDR_S[DS] from the corresponding descriptor. Should always be zero.
                                                                 See also PKO_META_DESC_S[DS]. */
        uint64_t adjust                : 9;  /**< [ 28: 20](R/W/H) When [ADJUST] is 0x100, it indicates that this CSR does not contain a valid meta,
                                                                 and all other fields in this CSR are invalid and shouldn't be used.

                                                                 When [ADJUST] is not 0x100, it is the PKO_SEND_HDR_S[SHP_CHG] for the
                                                                 packet. See also PKO_META_DESC_S[ADJUST]. */
        uint64_t pir_dis               : 1;  /**< [ 19: 19](R/W/H) PIR disable. Peak shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or CIR_ONLY
                                                                 (i.e. [PIR_DIS]=PKO_SEND_EXT_S[COL<1>]). Zero if a PKO_SEND_EXT_S is not present in the
                                                                 corresponding descriptor. See PKO_COLORALG_E. [PIR_DIS] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[COL<1>]. */
        uint64_t cir_dis               : 1;  /**< [ 18: 18](R/W/H) CIR disable. Committed shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or
                                                                 PIR_ONLY (i.e. [CIR_DIS]=PKO_SEND_EXT_S[COL<0>]). Zero if a PKO_SEND_EXT_S is not
                                                                 present in the corresponding descriptor. See PKO_COLORALG_E. [CIR_DIS] is used by the
                                                                 DQ through L2 shapers, but not used by the L1 rate limiters. See also
                                                                 PKO_META_DESC_S[COL<0>]. */
        uint64_t red_algo_override     : 2;  /**< [ 17: 16](R/W/H) PKO_SEND_HDR_S[SHP_RA] from the corresponding packet descriptor.
                                                                 [RED_ALGO_OVERRIDE] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[RA]. */
        uint64_t length                : 16; /**< [ 15:  0](R/W/H) Meta packet length. Generally, the size of the outgoing packet
                                                                 including pad, but excluding FCS and preamble.

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] clear:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(PKO_SEND_HDR_S[TOTAL], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               PKO_SEND_HDR_S[TOTAL]

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] set:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(FPS+PKO_SEND_HDR_S[TSO_SB], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               (FPS+PKO_SEND_HDR_S[TSO_SB])

                                                                 d is the DQ that the PKO SEND used. FPS is the number of payload bytes
                                                                 in the TSO segment. See also PKO_META_DESC_S[LENGTH]. */
#else /* Word 0 - Little Endian */
        uint64_t length                : 16; /**< [ 15:  0](R/W/H) Meta packet length. Generally, the size of the outgoing packet
                                                                 including pad, but excluding FCS and preamble.

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] clear:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(PKO_SEND_HDR_S[TOTAL], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               PKO_SEND_HDR_S[TOTAL]

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] set:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(FPS+PKO_SEND_HDR_S[TSO_SB], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               (FPS+PKO_SEND_HDR_S[TSO_SB])

                                                                 d is the DQ that the PKO SEND used. FPS is the number of payload bytes
                                                                 in the TSO segment. See also PKO_META_DESC_S[LENGTH]. */
        uint64_t red_algo_override     : 2;  /**< [ 17: 16](R/W/H) PKO_SEND_HDR_S[SHP_RA] from the corresponding packet descriptor.
                                                                 [RED_ALGO_OVERRIDE] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[RA]. */
        uint64_t cir_dis               : 1;  /**< [ 18: 18](R/W/H) CIR disable. Committed shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or
                                                                 PIR_ONLY (i.e. [CIR_DIS]=PKO_SEND_EXT_S[COL<0>]). Zero if a PKO_SEND_EXT_S is not
                                                                 present in the corresponding descriptor. See PKO_COLORALG_E. [CIR_DIS] is used by the
                                                                 DQ through L2 shapers, but not used by the L1 rate limiters. See also
                                                                 PKO_META_DESC_S[COL<0>]. */
        uint64_t pir_dis               : 1;  /**< [ 19: 19](R/W/H) PIR disable. Peak shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or CIR_ONLY
                                                                 (i.e. [PIR_DIS]=PKO_SEND_EXT_S[COL<1>]). Zero if a PKO_SEND_EXT_S is not present in the
                                                                 corresponding descriptor. See PKO_COLORALG_E. [PIR_DIS] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[COL<1>]. */
        uint64_t adjust                : 9;  /**< [ 28: 20](R/W/H) When [ADJUST] is 0x100, it indicates that this CSR does not contain a valid meta,
                                                                 and all other fields in this CSR are invalid and shouldn't be used.

                                                                 When [ADJUST] is not 0x100, it is the PKO_SEND_HDR_S[SHP_CHG] for the
                                                                 packet. See also PKO_META_DESC_S[ADJUST]. */
        uint64_t ds                    : 1;  /**< [ 29: 29](R/W/H) PKO_SEND_HDR_S[DS] from the corresponding descriptor. Should always be zero.
                                                                 See also PKO_META_DESC_S[DS]. */
        uint64_t fpd                   : 1;  /**< [ 30: 30](R/W/H) First packet descriptor. Set when corresponding descriptor is the first in a cacheline.
                                                                 See also PKO_META_DESC_S[FPD]. */
        uint64_t jump                  : 1;  /**< [ 31: 31](R/W/H) Set when the corresponding descriptor contains a PKO_SEND_JUMP_S.  See also
                                                                 PKO_META_DESC_S[JUMP]. */
        uint64_t uid                   : 7;  /**< [ 38: 32](R/W/H) Unique ID. 7-bit unique value assigned at the DQ level, increments for each packet. */
        uint64_t c_con                 : 1;  /**< [ 39: 39](R/W/H) Child connected flag. This pick has more picks behind it. */
        uint64_t p_con                 : 1;  /**< [ 40: 40](R/W/H) Parent connected flag. This pick has more picks in front of it. */
        uint64_t bubble                : 1;  /**< [ 41: 41](R/W/H) This metapacket is a fake passed forward after a prune. */
        uint64_t child                 : 10; /**< [ 51: 42](R/W/H) Child index. When the C_CON bit of this result is set, indicating that this result is
                                                                 connected in a flow that extends through the child result, this is the index of that child
                                                                 result. */
        uint64_t color                 : 2;  /**< [ 53: 52](R/W/H) See PKO_COLORRESULT_E. */
        uint64_t dq                    : 10; /**< [ 63: 54](R/W/H) Descriptor queue. Index of originating descriptor queue. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqx_pick_s cn; */
} bdk_pko_l2_sqx_pick_t;

static inline uint64_t BDK_PKO_L2_SQX_PICK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQX_PICK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000100070ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L2_SQX_PICK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQX_PICK(a) bdk_pko_l2_sqx_pick_t
#define bustype_BDK_PKO_L2_SQX_PICK(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQX_PICK(a) "PKO_L2_SQX_PICK"
#define device_bar_BDK_PKO_L2_SQX_PICK(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQX_PICK(a) (a)
#define arguments_BDK_PKO_L2_SQX_PICK(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l2_sq#_pir
 *
 * PKO PSE Level 2 Shaping Queue Peak Information Rate Register
 * This register has the same bit fields as PKO_L1_SQ()_CIR.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqx_pir_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_41_63        : 23;
        uint64_t burst_exponent        : 4;  /**< [ 40: 37](R/W) Burst exponent. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t burst_mantissa        : 8;  /**< [ 36: 29](R/W) Burst mantissa. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t reserved_17_28        : 12;
        uint64_t rate_divider_exponent : 4;  /**< [ 16: 13](R/W) Rate divider exponent. This 4-bit base-2 exponent is used to divide the credit rate by
                                                                 specifying the number of time-wheel turns required before the accumulator is increased.
                                                                 [RATE_DIVIDER_EXPONENT] should be used to specify data rates lower than ~10 Kbps and
                                                                 [RATE_EXPONENT] should be set to zero whenever it is used.

                                                                 The rate count = (1 << [RATE_DIVIDER_EXPONENT]). The supported range for
                                                                 [RATE_DIVIDER_EXPONENT] is 0 to 12. Programmed values greater than 12 are treated as 12.

                                                                 Note that for the L1-SQs, a time-wheel turn is 96 clocks (SCLK). For the other levels a
                                                                 time-wheel turn is 768 clocks (SCLK).

                                                                 For L1_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 96) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1
                                                                 <<[RATE_DIVIDER_EXPONENT])

                                                                 For L[5:2]_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 768) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1 <<
                                                                 [RATE_DIVIDER_EXPONENT]) */
        uint64_t rate_exponent         : 4;  /**< [ 12:  9](R/W) Rate exponent. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT].
                                                                 [RATE_EXPONENT] should be used to specify data rates higher than ~10 Kbps and
                                                                 [RATE_DIVIDER_EXPONENT] should be set to zero whenever it is nonzero. */
        uint64_t rate_mantissa         : 8;  /**< [  8:  1](R/W) Rate mantissa. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT]. */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable. Enables CIR shaping. */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable. Enables CIR shaping. */
        uint64_t rate_mantissa         : 8;  /**< [  8:  1](R/W) Rate mantissa. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT]. */
        uint64_t rate_exponent         : 4;  /**< [ 12:  9](R/W) Rate exponent. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT].
                                                                 [RATE_EXPONENT] should be used to specify data rates higher than ~10 Kbps and
                                                                 [RATE_DIVIDER_EXPONENT] should be set to zero whenever it is nonzero. */
        uint64_t rate_divider_exponent : 4;  /**< [ 16: 13](R/W) Rate divider exponent. This 4-bit base-2 exponent is used to divide the credit rate by
                                                                 specifying the number of time-wheel turns required before the accumulator is increased.
                                                                 [RATE_DIVIDER_EXPONENT] should be used to specify data rates lower than ~10 Kbps and
                                                                 [RATE_EXPONENT] should be set to zero whenever it is used.

                                                                 The rate count = (1 << [RATE_DIVIDER_EXPONENT]). The supported range for
                                                                 [RATE_DIVIDER_EXPONENT] is 0 to 12. Programmed values greater than 12 are treated as 12.

                                                                 Note that for the L1-SQs, a time-wheel turn is 96 clocks (SCLK). For the other levels a
                                                                 time-wheel turn is 768 clocks (SCLK).

                                                                 For L1_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 96) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1
                                                                 <<[RATE_DIVIDER_EXPONENT])

                                                                 For L[5:2]_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 768) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1 <<
                                                                 [RATE_DIVIDER_EXPONENT]) */
        uint64_t reserved_17_28        : 12;
        uint64_t burst_mantissa        : 8;  /**< [ 36: 29](R/W) Burst mantissa. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t burst_exponent        : 4;  /**< [ 40: 37](R/W) Burst exponent. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t reserved_41_63        : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqx_pir_s cn; */
} bdk_pko_l2_sqx_pir_t;

static inline uint64_t BDK_PKO_L2_SQX_PIR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQX_PIR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000080020ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L2_SQX_PIR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQX_PIR(a) bdk_pko_l2_sqx_pir_t
#define bustype_BDK_PKO_L2_SQX_PIR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQX_PIR(a) "PKO_L2_SQX_PIR"
#define device_bar_BDK_PKO_L2_SQX_PIR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQX_PIR(a) (a)
#define arguments_BDK_PKO_L2_SQX_PIR(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l2_sq#_pointers
 *
 * INTERNAL: PKO PSE Level 2 Shaping Queue Linked List Pointers Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqx_pointers_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t prev                  : 8;  /**< [ 23: 16](R/W/H) Previous pointer. The linked-list previous pointer. */
        uint64_t reserved_8_15         : 8;
        uint64_t next                  : 8;  /**< [  7:  0](R/W/H) Next pointer. The linked-list next pointer. */
#else /* Word 0 - Little Endian */
        uint64_t next                  : 8;  /**< [  7:  0](R/W/H) Next pointer. The linked-list next pointer. */
        uint64_t reserved_8_15         : 8;
        uint64_t prev                  : 8;  /**< [ 23: 16](R/W/H) Previous pointer. The linked-list previous pointer. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqx_pointers_s cn; */
} bdk_pko_l2_sqx_pointers_t;

static inline uint64_t BDK_PKO_L2_SQX_POINTERS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQX_POINTERS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000080078ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L2_SQX_POINTERS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQX_POINTERS(a) bdk_pko_l2_sqx_pointers_t
#define bustype_BDK_PKO_L2_SQX_POINTERS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQX_POINTERS(a) "PKO_L2_SQX_POINTERS"
#define device_bar_BDK_PKO_L2_SQX_POINTERS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQX_POINTERS(a) (a)
#define arguments_BDK_PKO_L2_SQX_POINTERS(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l2_sq#_red
 *
 * INTERNAL: PKO PSE Level 2 Shaping Queue Red State Debug Register
 *
 * This register has the same bit fields as PKO_L1_SQ()_RED.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqx_red_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t head                  : 9;  /**< [ 18: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_9            : 1;
        uint64_t tail                  : 9;  /**< [  8:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
#else /* Word 0 - Little Endian */
        uint64_t tail                  : 9;  /**< [  8:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
        uint64_t reserved_9            : 1;
        uint64_t head                  : 9;  /**< [ 18: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqx_red_s cn; */
} bdk_pko_l2_sqx_red_t;

static inline uint64_t BDK_PKO_L2_SQX_RED(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQX_RED(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000100068ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L2_SQX_RED", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQX_RED(a) bdk_pko_l2_sqx_red_t
#define bustype_BDK_PKO_L2_SQX_RED(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQX_RED(a) "PKO_L2_SQX_RED"
#define device_bar_BDK_PKO_L2_SQX_RED(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQX_RED(a) (a)
#define arguments_BDK_PKO_L2_SQX_RED(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l2_sq#_sched_state
 *
 * PKO PSE Level 2 Shaping Queue Scheduling Control State Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqx_sched_state_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_25_63        : 39;
        uint64_t rr_count              : 25; /**< [ 24:  0](R/W/H) Round-robin (DWRR) deficit counter. A 25-bit signed integer count. For diagnostic use. */
#else /* Word 0 - Little Endian */
        uint64_t rr_count              : 25; /**< [ 24:  0](R/W/H) Round-robin (DWRR) deficit counter. A 25-bit signed integer count. For diagnostic use. */
        uint64_t reserved_25_63        : 39;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqx_sched_state_s cn; */
} bdk_pko_l2_sqx_sched_state_t;

static inline uint64_t BDK_PKO_L2_SQX_SCHED_STATE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQX_SCHED_STATE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000080028ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L2_SQX_SCHED_STATE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQX_SCHED_STATE(a) bdk_pko_l2_sqx_sched_state_t
#define bustype_BDK_PKO_L2_SQX_SCHED_STATE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQX_SCHED_STATE(a) "PKO_L2_SQX_SCHED_STATE"
#define device_bar_BDK_PKO_L2_SQX_SCHED_STATE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQX_SCHED_STATE(a) (a)
#define arguments_BDK_PKO_L2_SQX_SCHED_STATE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l2_sq#_schedule
 *
 * PKO PSE Level 2 Scheduling Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqx_schedule_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t prio                  : 4;  /**< [ 27: 24](R/W) Priority. The priority used for this SQ in the (lower-level) parent's scheduling
                                                                 algorithm. When this SQ is not used, we recommend setting [PRIO] to zero. The legal [PRIO]
                                                                 values are 0-9 when the SQ is used. In addition to priority, [PRIO] determines whether the
                                                                 SQ is a static queue or not: If [PRIO] equals PKO_*_SQn_TOPOLOGY[RR_PRIO], where
                                                                 PKO_*_TOPOLOGY[PARENT] for this SQ equals n, then this is a round-robin child queue into
                                                                 the shaper at the next level. */
        uint64_t rr_quantum            : 24; /**< [ 23:  0](R/W) Round-robin (DWRR) quantum. The deficit-weighted round-robin quantum (24-bit unsigned
                                                                 integer). The packet size used in all DWRR (RR_COUNT) calculations is:

                                                                 _  (PKO_nm_SHAPE[LENGTH_DISABLE] ? 0 : (PKO_nm_PICK[LENGTH] + PKO_nm_PICK[ADJUST]))
                                                                    + PKO_nm_SHAPE[ADJUST]

                                                                 where nm corresponds to this PKO_nm_SCHEDULE CSR.

                                                                 Typically [RR_QUANTUM] should be at or near the MTU or more (to limit or prevent
                                                                 negative accumulations of PKO_*_SCHED_STATE[RR_COUNT] (i.e. the deficit count)). */
#else /* Word 0 - Little Endian */
        uint64_t rr_quantum            : 24; /**< [ 23:  0](R/W) Round-robin (DWRR) quantum. The deficit-weighted round-robin quantum (24-bit unsigned
                                                                 integer). The packet size used in all DWRR (RR_COUNT) calculations is:

                                                                 _  (PKO_nm_SHAPE[LENGTH_DISABLE] ? 0 : (PKO_nm_PICK[LENGTH] + PKO_nm_PICK[ADJUST]))
                                                                    + PKO_nm_SHAPE[ADJUST]

                                                                 where nm corresponds to this PKO_nm_SCHEDULE CSR.

                                                                 Typically [RR_QUANTUM] should be at or near the MTU or more (to limit or prevent
                                                                 negative accumulations of PKO_*_SCHED_STATE[RR_COUNT] (i.e. the deficit count)). */
        uint64_t prio                  : 4;  /**< [ 27: 24](R/W) Priority. The priority used for this SQ in the (lower-level) parent's scheduling
                                                                 algorithm. When this SQ is not used, we recommend setting [PRIO] to zero. The legal [PRIO]
                                                                 values are 0-9 when the SQ is used. In addition to priority, [PRIO] determines whether the
                                                                 SQ is a static queue or not: If [PRIO] equals PKO_*_SQn_TOPOLOGY[RR_PRIO], where
                                                                 PKO_*_TOPOLOGY[PARENT] for this SQ equals n, then this is a round-robin child queue into
                                                                 the shaper at the next level. */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqx_schedule_s cn; */
} bdk_pko_l2_sqx_schedule_t;

static inline uint64_t BDK_PKO_L2_SQX_SCHEDULE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQX_SCHEDULE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000080008ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L2_SQX_SCHEDULE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQX_SCHEDULE(a) bdk_pko_l2_sqx_schedule_t
#define bustype_BDK_PKO_L2_SQX_SCHEDULE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQX_SCHEDULE(a) "PKO_L2_SQX_SCHEDULE"
#define device_bar_BDK_PKO_L2_SQX_SCHEDULE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQX_SCHEDULE(a) (a)
#define arguments_BDK_PKO_L2_SQX_SCHEDULE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l2_sq#_shape
 *
 * PKO PSE Level 2 Shaping Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqx_shape_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t schedule_list         : 2;  /**< [ 26: 25](R/W) Shaper scheduling list. Restricts shaper scheduling to specific lists.
                                                                   0x0 = Normal (selected for nearly all scheduling/shaping applications).
                                                                   0x1 = Green-only.
                                                                   0x2 = Yellow-only.
                                                                   0x3 = Red-only. */
        uint64_t length_disable        : 1;  /**< [ 24: 24](R/W) Length disable. Disables the use of packet lengths in DWRR scheduling
                                                                 and shaping calculations such that only the value of [ADJUST] is used. */
        uint64_t reserved_13_23        : 11;
        uint64_t yellow_disable        : 1;  /**< [ 12: 12](R/W) Disable yellow transitions. Disables green-to-yellow packet color marking transitions when
                                                                 set. Not used by hardware when corresponding PKO_*_CIR[ENABLE] is clear. */
        uint64_t red_disable           : 1;  /**< [ 11: 11](R/W) Disable red transitions. Disables green-to-red and yellow-to-red packet color marking
                                                                 transitions when set. Not used by hardware when
                                                                 [RED_ALGO]/PKO_SEND_HDR_S[SHP_RA]=0x2/STALLi
                                                                 nor when corresponding PKO_*_PIR[ENABLE] is clear. */
        uint64_t red_algo              : 2;  /**< [ 10:  9](R/W) Shaper red state algorithm when not specified by the PKO SEND. Used by hardware
                                                                 only when the shaper is in RED state. (A shaper is in RED state when
                                                                 PKO_*_SHAPE_STATE[PIR_ACCUM] is negative.) When PKO_SEND_HDR_S[SHP_RA]!=STD (!=0) for a
                                                                 packet, this [RED_ALGO] is not used, and PKO_SEND_HDR_S[SHP_RA] instead defines
                                                                 the shaper red state algorithm used for the packet. The
                                                                 encoding for the [RED_ALGO]/PKO_SEND_HDR_S[SHP_RA] that is used:
                                                                 0x0 = STALL. See 0x2.
                                                                 0x1 = SEND. Send packets while the shaper is in RED state. When the shaper is
                                                                       in RED state, packets that traverse the shaper will be downgraded to RED_SEND.
                                                                       (if not already RED_SEND or RED_DROP) unless [RED_DISABLE] is set or
                                                                       PKO_SEND_EXT_S[COL] for the packet is CIR_ONLY or NO_COLOR.
                                                                       See also PKO_REDALG_E::SEND.
                                                                 0x2 = STALL. Stall packets while the shaper is in RED state until the shaper is
                                                                       YELLOW or GREEN state. Packets that traverse the shaper are never
                                                                       downgraded to the RED state in this mode.
                                                                       See also PKO_REDALG_E::STALL.
                                                                 0x3 = DISCARD. Continually discard packets while the shaper is in RED state.
                                                                       When the shaper is in RED state, all packets that traverse the shaper
                                                                       will be downgraded to RED_DROP (if not already RED_DROP), unless
                                                                       [RED_DISABLE] is set or PKO_SEND_EXT_S[COL] for the packet is CIR_ONLY
                                                                       or NO_COLOR. RED_DROP packets traverse all subsequent schedulers/shapers
                                                                       (all the way through L1), but do so as quickly as possible without
                                                                       affecting any RR_COUNT, CIR_ACCUM, or PIR_ACCUM state, and are then
                                                                       discarded by PKO. See also PKO_REDALG_E::DISCARD. */
        uint64_t adjust                : 9;  /**< [  8:  0](R/W) Shaping and scheduling calculation adjustment. This 9-bit signed value allows
                                                                 -255 .. 255 bytes to be added to the packet length for shaping and scheduling
                                                                 calculations. [ADJUST] value 0x100 should not be used. */
#else /* Word 0 - Little Endian */
        uint64_t adjust                : 9;  /**< [  8:  0](R/W) Shaping and scheduling calculation adjustment. This 9-bit signed value allows
                                                                 -255 .. 255 bytes to be added to the packet length for shaping and scheduling
                                                                 calculations. [ADJUST] value 0x100 should not be used. */
        uint64_t red_algo              : 2;  /**< [ 10:  9](R/W) Shaper red state algorithm when not specified by the PKO SEND. Used by hardware
                                                                 only when the shaper is in RED state. (A shaper is in RED state when
                                                                 PKO_*_SHAPE_STATE[PIR_ACCUM] is negative.) When PKO_SEND_HDR_S[SHP_RA]!=STD (!=0) for a
                                                                 packet, this [RED_ALGO] is not used, and PKO_SEND_HDR_S[SHP_RA] instead defines
                                                                 the shaper red state algorithm used for the packet. The
                                                                 encoding for the [RED_ALGO]/PKO_SEND_HDR_S[SHP_RA] that is used:
                                                                 0x0 = STALL. See 0x2.
                                                                 0x1 = SEND. Send packets while the shaper is in RED state. When the shaper is
                                                                       in RED state, packets that traverse the shaper will be downgraded to RED_SEND.
                                                                       (if not already RED_SEND or RED_DROP) unless [RED_DISABLE] is set or
                                                                       PKO_SEND_EXT_S[COL] for the packet is CIR_ONLY or NO_COLOR.
                                                                       See also PKO_REDALG_E::SEND.
                                                                 0x2 = STALL. Stall packets while the shaper is in RED state until the shaper is
                                                                       YELLOW or GREEN state. Packets that traverse the shaper are never
                                                                       downgraded to the RED state in this mode.
                                                                       See also PKO_REDALG_E::STALL.
                                                                 0x3 = DISCARD. Continually discard packets while the shaper is in RED state.
                                                                       When the shaper is in RED state, all packets that traverse the shaper
                                                                       will be downgraded to RED_DROP (if not already RED_DROP), unless
                                                                       [RED_DISABLE] is set or PKO_SEND_EXT_S[COL] for the packet is CIR_ONLY
                                                                       or NO_COLOR. RED_DROP packets traverse all subsequent schedulers/shapers
                                                                       (all the way through L1), but do so as quickly as possible without
                                                                       affecting any RR_COUNT, CIR_ACCUM, or PIR_ACCUM state, and are then
                                                                       discarded by PKO. See also PKO_REDALG_E::DISCARD. */
        uint64_t red_disable           : 1;  /**< [ 11: 11](R/W) Disable red transitions. Disables green-to-red and yellow-to-red packet color marking
                                                                 transitions when set. Not used by hardware when
                                                                 [RED_ALGO]/PKO_SEND_HDR_S[SHP_RA]=0x2/STALLi
                                                                 nor when corresponding PKO_*_PIR[ENABLE] is clear. */
        uint64_t yellow_disable        : 1;  /**< [ 12: 12](R/W) Disable yellow transitions. Disables green-to-yellow packet color marking transitions when
                                                                 set. Not used by hardware when corresponding PKO_*_CIR[ENABLE] is clear. */
        uint64_t reserved_13_23        : 11;
        uint64_t length_disable        : 1;  /**< [ 24: 24](R/W) Length disable. Disables the use of packet lengths in DWRR scheduling
                                                                 and shaping calculations such that only the value of [ADJUST] is used. */
        uint64_t schedule_list         : 2;  /**< [ 26: 25](R/W) Shaper scheduling list. Restricts shaper scheduling to specific lists.
                                                                   0x0 = Normal (selected for nearly all scheduling/shaping applications).
                                                                   0x1 = Green-only.
                                                                   0x2 = Yellow-only.
                                                                   0x3 = Red-only. */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqx_shape_s cn; */
} bdk_pko_l2_sqx_shape_t;

static inline uint64_t BDK_PKO_L2_SQX_SHAPE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQX_SHAPE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000080010ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L2_SQX_SHAPE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQX_SHAPE(a) bdk_pko_l2_sqx_shape_t
#define bustype_BDK_PKO_L2_SQX_SHAPE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQX_SHAPE(a) "PKO_L2_SQX_SHAPE"
#define device_bar_BDK_PKO_L2_SQX_SHAPE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQX_SHAPE(a) (a)
#define arguments_BDK_PKO_L2_SQX_SHAPE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l2_sq#_shape_state
 *
 * PKO PSE Level 2 Shaping Queue Shape State Register
 * This register must not be written during normal operation.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqx_shape_state_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t tw_timestamp          : 6;  /**< [ 59: 54](R/W/H) Time-wheel timestamp. Debug access to the live time-wheel timestamp. */
        uint64_t color                 : 2;  /**< [ 53: 52](R/W/H) Shaper connection status. Debug access to the live shaper state.
                                                                 0x0 = Green - shaper is connected into the green list.
                                                                 0x1 = Yellow - shaper is connected into the yellow list.
                                                                 0x2 = Red - shaper is connected into the red list.
                                                                 0x3 = Pruned - shaper is disconnected. */
        uint64_t pir_accum             : 26; /**< [ 51: 26](R/W/H) Peak information rate accumulator. Debug access to the live PIR accumulator. */
        uint64_t cir_accum             : 26; /**< [ 25:  0](R/W/H) Committed information rate accumulator. Debug access to the live CIR accumulator. */
#else /* Word 0 - Little Endian */
        uint64_t cir_accum             : 26; /**< [ 25:  0](R/W/H) Committed information rate accumulator. Debug access to the live CIR accumulator. */
        uint64_t pir_accum             : 26; /**< [ 51: 26](R/W/H) Peak information rate accumulator. Debug access to the live PIR accumulator. */
        uint64_t color                 : 2;  /**< [ 53: 52](R/W/H) Shaper connection status. Debug access to the live shaper state.
                                                                 0x0 = Green - shaper is connected into the green list.
                                                                 0x1 = Yellow - shaper is connected into the yellow list.
                                                                 0x2 = Red - shaper is connected into the red list.
                                                                 0x3 = Pruned - shaper is disconnected. */
        uint64_t tw_timestamp          : 6;  /**< [ 59: 54](R/W/H) Time-wheel timestamp. Debug access to the live time-wheel timestamp. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqx_shape_state_s cn; */
} bdk_pko_l2_sqx_shape_state_t;

static inline uint64_t BDK_PKO_L2_SQX_SHAPE_STATE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQX_SHAPE_STATE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000080030ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L2_SQX_SHAPE_STATE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQX_SHAPE_STATE(a) bdk_pko_l2_sqx_shape_state_t
#define bustype_BDK_PKO_L2_SQX_SHAPE_STATE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQX_SHAPE_STATE(a) "PKO_L2_SQX_SHAPE_STATE"
#define device_bar_BDK_PKO_L2_SQX_SHAPE_STATE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQX_SHAPE_STATE(a) (a)
#define arguments_BDK_PKO_L2_SQX_SHAPE_STATE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l2_sq#_sw_xoff
 *
 * PKO PSE Level 2 Shaping Queue Software Controlled XOFF Register
 * This register has the same bit fields as PKO_L1_SQ()_SW_XOFF.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqx_sw_xoff_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t drain_irq             : 1;  /**< [  3:  3](WO) Drain IRQ. Enables an interrupt that fires when the drain operation has completed.
                                                                 [DRAIN_IRQ] should be set whenever [DRAIN] is, and must not be set
                                                                 when [DRAIN] isn't set. [DRAIN_IRQ] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t drain_null_link       : 1;  /**< [  2:  2](WO) Drain null link. This setting only has effect when the L1 node is
                                                                 mapped to the NULL FIFO.  Conditions the drain path to drain through
                                                                 the NULL FIFO (i.e. link 14). As such, channel credits, HW_XOFF, and
                                                                 shaping are disabled on the draining path until the path has drained.
                                                                 [DRAIN_NULL_LINK] must not be set when [DRAIN] isn't set.
                                                                 [DRAIN_NULL_LINK] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t drain                 : 1;  /**< [  1:  1](WO) Drain. This control activates a drain path through the PSE that starts at this node and
                                                                 ends at the SQ1 level. The drain path is prioritized over other paths through PSE and can
                                                                 be used in combination with [DRAIN_NULL_LINK] and [DRAIN_IRQ]. [DRAIN] need never be
                                                                 set for the SQ1 level, but is useful at all other levels, including the DQ level.
                                                                 PKO_PQ_DRAIN_W1C[INTR] should be clear prior to initiating a [DRAIN]=1 write to this CSR.
                                                                 After [DRAIN] is set for an SQ/DQ, it should not be set again, for this or any other
                                                                 SQ/DQ, until after a 0->1 transition has been observed on PKO_PQ_DRAIN_W1C[INTR]
                                                                 (and/or the PKO_PSE_PQ_DRAIN interrupt has occured) and
                                                                 PKO_PQ_DRAIN_W1C[INTR] has been cleared.  DRAIN has no effect unless XOFF is also set.
                                                                 Only one DRAIN command is allowed to be active at a time. */
        uint64_t xoff                  : 1;  /**< [  0:  0](R/W) XOFF. Stops meta flow out of the SQ/DQ. When [XOFF] is set, the corresponding
                                                                 PKO_*_PICK (i.e. the meta) in the SQ/DQ cannot be transferred to the
                                                                 next level. The corresponding PKO_*_PICK may become valid while [XOFF] is set,
                                                                 but it cannot change from valid to invalid while [XOFF] is set.
                                                                 NOTE: The associated PKO_*_TOPOLOGY[LINK/PARENT] should normally be configured before
                                                                 [XOFF] is set. Setting [XOFF] before the associated PKO_*_TOPOLOGY[LINK/PARENT]
                                                                 value is configured can result in modifying the software [XOFF] state of the wrong SQ. */
#else /* Word 0 - Little Endian */
        uint64_t xoff                  : 1;  /**< [  0:  0](R/W) XOFF. Stops meta flow out of the SQ/DQ. When [XOFF] is set, the corresponding
                                                                 PKO_*_PICK (i.e. the meta) in the SQ/DQ cannot be transferred to the
                                                                 next level. The corresponding PKO_*_PICK may become valid while [XOFF] is set,
                                                                 but it cannot change from valid to invalid while [XOFF] is set.
                                                                 NOTE: The associated PKO_*_TOPOLOGY[LINK/PARENT] should normally be configured before
                                                                 [XOFF] is set. Setting [XOFF] before the associated PKO_*_TOPOLOGY[LINK/PARENT]
                                                                 value is configured can result in modifying the software [XOFF] state of the wrong SQ. */
        uint64_t drain                 : 1;  /**< [  1:  1](WO) Drain. This control activates a drain path through the PSE that starts at this node and
                                                                 ends at the SQ1 level. The drain path is prioritized over other paths through PSE and can
                                                                 be used in combination with [DRAIN_NULL_LINK] and [DRAIN_IRQ]. [DRAIN] need never be
                                                                 set for the SQ1 level, but is useful at all other levels, including the DQ level.
                                                                 PKO_PQ_DRAIN_W1C[INTR] should be clear prior to initiating a [DRAIN]=1 write to this CSR.
                                                                 After [DRAIN] is set for an SQ/DQ, it should not be set again, for this or any other
                                                                 SQ/DQ, until after a 0->1 transition has been observed on PKO_PQ_DRAIN_W1C[INTR]
                                                                 (and/or the PKO_PSE_PQ_DRAIN interrupt has occured) and
                                                                 PKO_PQ_DRAIN_W1C[INTR] has been cleared.  DRAIN has no effect unless XOFF is also set.
                                                                 Only one DRAIN command is allowed to be active at a time. */
        uint64_t drain_null_link       : 1;  /**< [  2:  2](WO) Drain null link. This setting only has effect when the L1 node is
                                                                 mapped to the NULL FIFO.  Conditions the drain path to drain through
                                                                 the NULL FIFO (i.e. link 14). As such, channel credits, HW_XOFF, and
                                                                 shaping are disabled on the draining path until the path has drained.
                                                                 [DRAIN_NULL_LINK] must not be set when [DRAIN] isn't set.
                                                                 [DRAIN_NULL_LINK] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t drain_irq             : 1;  /**< [  3:  3](WO) Drain IRQ. Enables an interrupt that fires when the drain operation has completed.
                                                                 [DRAIN_IRQ] should be set whenever [DRAIN] is, and must not be set
                                                                 when [DRAIN] isn't set. [DRAIN_IRQ] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqx_sw_xoff_s cn; */
} bdk_pko_l2_sqx_sw_xoff_t;

static inline uint64_t BDK_PKO_L2_SQX_SW_XOFF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQX_SW_XOFF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x8540000800e0ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L2_SQX_SW_XOFF", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQX_SW_XOFF(a) bdk_pko_l2_sqx_sw_xoff_t
#define bustype_BDK_PKO_L2_SQX_SW_XOFF(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQX_SW_XOFF(a) "PKO_L2_SQX_SW_XOFF"
#define device_bar_BDK_PKO_L2_SQX_SW_XOFF(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQX_SW_XOFF(a) (a)
#define arguments_BDK_PKO_L2_SQX_SW_XOFF(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l2_sq#_topology
 *
 * PKO PSE Level 2 Shaping Queue Topology Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqx_topology_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t prio_anchor           : 8;  /**< [ 39: 32](R/W) See PKO_L1_SQ()_TOPOLOGY[PRIO_ANCHOR]. */
        uint64_t reserved_21_31        : 11;
        uint64_t parent                : 5;  /**< [ 20: 16](R/W) Parent queue index. The index of the shaping element at the next lower hierarchical level
                                                                 that accepts this shaping element's outputs. Refer to the PKO_*_SQn_TOPOLOGY
                                                                 [PRIO_ANCHOR,RR_PRIO] descriptions for constraints on which child queues can attach to
                                                                 which shapers at the next lower level. When this shaper is unused, we recommend that
                                                                 PARENT be zero. */
        uint64_t reserved_5_15         : 11;
        uint64_t rr_prio               : 4;  /**< [  4:  1](R/W) See PKO_L1_SQ()_TOPOLOGY[RR_PRIO]. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t rr_prio               : 4;  /**< [  4:  1](R/W) See PKO_L1_SQ()_TOPOLOGY[RR_PRIO]. */
        uint64_t reserved_5_15         : 11;
        uint64_t parent                : 5;  /**< [ 20: 16](R/W) Parent queue index. The index of the shaping element at the next lower hierarchical level
                                                                 that accepts this shaping element's outputs. Refer to the PKO_*_SQn_TOPOLOGY
                                                                 [PRIO_ANCHOR,RR_PRIO] descriptions for constraints on which child queues can attach to
                                                                 which shapers at the next lower level. When this shaper is unused, we recommend that
                                                                 PARENT be zero. */
        uint64_t reserved_21_31        : 11;
        uint64_t prio_anchor           : 8;  /**< [ 39: 32](R/W) See PKO_L1_SQ()_TOPOLOGY[PRIO_ANCHOR]. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqx_topology_s cn; */
} bdk_pko_l2_sqx_topology_t;

static inline uint64_t BDK_PKO_L2_SQX_TOPOLOGY(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQX_TOPOLOGY(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000100000ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L2_SQX_TOPOLOGY", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQX_TOPOLOGY(a) bdk_pko_l2_sqx_topology_t
#define bustype_BDK_PKO_L2_SQX_TOPOLOGY(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQX_TOPOLOGY(a) "PKO_L2_SQX_TOPOLOGY"
#define device_bar_BDK_PKO_L2_SQX_TOPOLOGY(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQX_TOPOLOGY(a) (a)
#define arguments_BDK_PKO_L2_SQX_TOPOLOGY(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l2_sq#_yellow
 *
 * INTERNAL: PKO PSE Level 2 Shaping Queue Yellow State Debug Register
 *
 * This register has the same bit fields as PKO_L1_SQ()_YELLOW.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqx_yellow_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t head                  : 9;  /**< [ 18: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_9            : 1;
        uint64_t tail                  : 9;  /**< [  8:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
#else /* Word 0 - Little Endian */
        uint64_t tail                  : 9;  /**< [  8:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
        uint64_t reserved_9            : 1;
        uint64_t head                  : 9;  /**< [ 18: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqx_yellow_s cn; */
} bdk_pko_l2_sqx_yellow_t;

static inline uint64_t BDK_PKO_L2_SQX_YELLOW(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQX_YELLOW(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000100060ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L2_SQX_YELLOW", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQX_YELLOW(a) bdk_pko_l2_sqx_yellow_t
#define bustype_BDK_PKO_L2_SQX_YELLOW(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQX_YELLOW(a) "PKO_L2_SQX_YELLOW"
#define device_bar_BDK_PKO_L2_SQX_YELLOW(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQX_YELLOW(a) (a)
#define arguments_BDK_PKO_L2_SQX_YELLOW(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l2_sqa_debug
 *
 * INTERNAL: PKO PSE Level 2 SQ-A Internal Debug Register
 *
 * This register has the same bit fields as PKO_PQA_DEBUG.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqa_debug_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#else /* Word 0 - Little Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqa_debug_s cn; */
} bdk_pko_l2_sqa_debug_t;

#define BDK_PKO_L2_SQA_DEBUG BDK_PKO_L2_SQA_DEBUG_FUNC()
static inline uint64_t BDK_PKO_L2_SQA_DEBUG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQA_DEBUG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000100128ll;
    __bdk_csr_fatal("PKO_L2_SQA_DEBUG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQA_DEBUG bdk_pko_l2_sqa_debug_t
#define bustype_BDK_PKO_L2_SQA_DEBUG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQA_DEBUG "PKO_L2_SQA_DEBUG"
#define device_bar_BDK_PKO_L2_SQA_DEBUG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQA_DEBUG 0
#define arguments_BDK_PKO_L2_SQA_DEBUG -1,-1,-1,-1

/**
 * Register (NCB) pko_l2_sqb_debug
 *
 * INTERNAL: PKO PSE Level 2 SQ-B Internal Debug Register
 *
 * This register has the same bit fields as PKO_PQA_DEBUG.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l2_sqb_debug_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#else /* Word 0 - Little Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l2_sqb_debug_s cn; */
} bdk_pko_l2_sqb_debug_t;

#define BDK_PKO_L2_SQB_DEBUG BDK_PKO_L2_SQB_DEBUG_FUNC()
static inline uint64_t BDK_PKO_L2_SQB_DEBUG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L2_SQB_DEBUG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000100130ll;
    __bdk_csr_fatal("PKO_L2_SQB_DEBUG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_L2_SQB_DEBUG bdk_pko_l2_sqb_debug_t
#define bustype_BDK_PKO_L2_SQB_DEBUG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L2_SQB_DEBUG "PKO_L2_SQB_DEBUG"
#define device_bar_BDK_PKO_L2_SQB_DEBUG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L2_SQB_DEBUG 0
#define arguments_BDK_PKO_L2_SQB_DEBUG -1,-1,-1,-1

/**
 * Register (NCB) pko_l3_const
 *
 * PKO Level 3 Constants Register
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t count                 : 16; /**< [ 15:  0](RO) Number of Level-3 shaping queues. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 16; /**< [ 15:  0](RO) Number of Level-3 shaping queues. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_const_s cn; */
} bdk_pko_l3_const_t;

#define BDK_PKO_L3_CONST BDK_PKO_L3_CONST_FUNC()
static inline uint64_t BDK_PKO_L3_CONST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_CONST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000d00110ll;
    __bdk_csr_fatal("PKO_L3_CONST", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_CONST bdk_pko_l3_const_t
#define bustype_BDK_PKO_L3_CONST BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_CONST "PKO_L3_CONST"
#define device_bar_BDK_PKO_L3_CONST 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_CONST 0
#define arguments_BDK_PKO_L3_CONST -1,-1,-1,-1

/**
 * Register (NCB) pko_l3_l2_sq#_channel
 *
 * PKO PSE Level 3/2 Shaping Queue Channel Configuration Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_l2_sqx_channel_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t cc_channel            : 12; /**< [ 43: 32](R/W) Channel ID. See PKI_CHAN_E. */
        uint64_t cc_word_cnt           : 20; /**< [ 31: 12](R/W/H) Channel credit word count. This value, plus 1 MTU, represents the maximum outstanding word
                                                                 count for this channel. (Words are 16 bytes.) Note that this 20-bit field represents a
                                                                 signed value that decrements towards zero as credits are used. Packets are not allowed to
                                                                 flow when the count is less than zero. As such, the most significant bit should normally
                                                                 be programmed as zero (positive count). This gives a maximum value for this field of 2^18
                                                                 - 1. */
        uint64_t cc_packet_cnt         : 10; /**< [ 11:  2](R/W/H) Channel credit packet count. This value, plus 1, represents the maximum outstanding packet
                                                                 count for this channel. Note that this 10-bit field represents a signed value that
                                                                 decrements towards zero as credits are used. Packets are not allowed to flow when the
                                                                 count is less than zero. As such the most significant bit should normally be programmed as
                                                                 zero (positive count). This gives a maximum value for this field of 2^9 - 1. */
        uint64_t cc_enable             : 1;  /**< [  1:  1](R/W) Channel credit enable. Enables CC_WORD_CNT and CC_PACKET_CNT credit processing. */
        uint64_t hw_xoff               : 1;  /**< [  0:  0](R/W/H) Hardware XOFF status. The status of hardware XON/XOFF (i.e. hardware channel
                                                                 backpressure). This is writable to get around LUT issues and for reconfiguration.
                                                                 [HW_XOFF] should only be set when there is a valid PKO_LUT entry pointing to the SQ
                                                                 which is being backpressured. */
#else /* Word 0 - Little Endian */
        uint64_t hw_xoff               : 1;  /**< [  0:  0](R/W/H) Hardware XOFF status. The status of hardware XON/XOFF (i.e. hardware channel
                                                                 backpressure). This is writable to get around LUT issues and for reconfiguration.
                                                                 [HW_XOFF] should only be set when there is a valid PKO_LUT entry pointing to the SQ
                                                                 which is being backpressured. */
        uint64_t cc_enable             : 1;  /**< [  1:  1](R/W) Channel credit enable. Enables CC_WORD_CNT and CC_PACKET_CNT credit processing. */
        uint64_t cc_packet_cnt         : 10; /**< [ 11:  2](R/W/H) Channel credit packet count. This value, plus 1, represents the maximum outstanding packet
                                                                 count for this channel. Note that this 10-bit field represents a signed value that
                                                                 decrements towards zero as credits are used. Packets are not allowed to flow when the
                                                                 count is less than zero. As such the most significant bit should normally be programmed as
                                                                 zero (positive count). This gives a maximum value for this field of 2^9 - 1. */
        uint64_t cc_word_cnt           : 20; /**< [ 31: 12](R/W/H) Channel credit word count. This value, plus 1 MTU, represents the maximum outstanding word
                                                                 count for this channel. (Words are 16 bytes.) Note that this 20-bit field represents a
                                                                 signed value that decrements towards zero as credits are used. Packets are not allowed to
                                                                 flow when the count is less than zero. As such, the most significant bit should normally
                                                                 be programmed as zero (positive count). This gives a maximum value for this field of 2^18
                                                                 - 1. */
        uint64_t cc_channel            : 12; /**< [ 43: 32](R/W) Channel ID. See PKI_CHAN_E. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_l2_sqx_channel_s cn; */
} bdk_pko_l3_l2_sqx_channel_t;

static inline uint64_t BDK_PKO_L3_L2_SQX_CHANNEL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_L2_SQX_CHANNEL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000080038ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L3_L2_SQX_CHANNEL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_L2_SQX_CHANNEL(a) bdk_pko_l3_l2_sqx_channel_t
#define bustype_BDK_PKO_L3_L2_SQX_CHANNEL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_L2_SQX_CHANNEL(a) "PKO_L3_L2_SQX_CHANNEL"
#define device_bar_BDK_PKO_L3_L2_SQX_CHANNEL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_L2_SQX_CHANNEL(a) (a)
#define arguments_BDK_PKO_L3_L2_SQX_CHANNEL(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l3_sq#_cir
 *
 * PKO PSE Level 3 Shaping Queue Committed Information Rate Register
 * This register has the same bit fields as PKO_L1_SQ()_CIR.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqx_cir_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_41_63        : 23;
        uint64_t burst_exponent        : 4;  /**< [ 40: 37](R/W) Burst exponent. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t burst_mantissa        : 8;  /**< [ 36: 29](R/W) Burst mantissa. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t reserved_17_28        : 12;
        uint64_t rate_divider_exponent : 4;  /**< [ 16: 13](R/W) Rate divider exponent. This 4-bit base-2 exponent is used to divide the credit rate by
                                                                 specifying the number of time-wheel turns required before the accumulator is increased.
                                                                 [RATE_DIVIDER_EXPONENT] should be used to specify data rates lower than ~10 Kbps and
                                                                 [RATE_EXPONENT] should be set to zero whenever it is used.

                                                                 The rate count = (1 << [RATE_DIVIDER_EXPONENT]). The supported range for
                                                                 [RATE_DIVIDER_EXPONENT] is 0 to 12. Programmed values greater than 12 are treated as 12.

                                                                 Note that for the L1-SQs, a time-wheel turn is 96 clocks (SCLK). For the other levels a
                                                                 time-wheel turn is 768 clocks (SCLK).

                                                                 For L1_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 96) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1
                                                                 <<[RATE_DIVIDER_EXPONENT])

                                                                 For L[5:2]_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 768) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1 <<
                                                                 [RATE_DIVIDER_EXPONENT]) */
        uint64_t rate_exponent         : 4;  /**< [ 12:  9](R/W) Rate exponent. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT].
                                                                 [RATE_EXPONENT] should be used to specify data rates higher than ~10 Kbps and
                                                                 [RATE_DIVIDER_EXPONENT] should be set to zero whenever it is nonzero. */
        uint64_t rate_mantissa         : 8;  /**< [  8:  1](R/W) Rate mantissa. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT]. */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable. Enables CIR shaping. */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable. Enables CIR shaping. */
        uint64_t rate_mantissa         : 8;  /**< [  8:  1](R/W) Rate mantissa. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT]. */
        uint64_t rate_exponent         : 4;  /**< [ 12:  9](R/W) Rate exponent. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT].
                                                                 [RATE_EXPONENT] should be used to specify data rates higher than ~10 Kbps and
                                                                 [RATE_DIVIDER_EXPONENT] should be set to zero whenever it is nonzero. */
        uint64_t rate_divider_exponent : 4;  /**< [ 16: 13](R/W) Rate divider exponent. This 4-bit base-2 exponent is used to divide the credit rate by
                                                                 specifying the number of time-wheel turns required before the accumulator is increased.
                                                                 [RATE_DIVIDER_EXPONENT] should be used to specify data rates lower than ~10 Kbps and
                                                                 [RATE_EXPONENT] should be set to zero whenever it is used.

                                                                 The rate count = (1 << [RATE_DIVIDER_EXPONENT]). The supported range for
                                                                 [RATE_DIVIDER_EXPONENT] is 0 to 12. Programmed values greater than 12 are treated as 12.

                                                                 Note that for the L1-SQs, a time-wheel turn is 96 clocks (SCLK). For the other levels a
                                                                 time-wheel turn is 768 clocks (SCLK).

                                                                 For L1_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 96) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1
                                                                 <<[RATE_DIVIDER_EXPONENT])

                                                                 For L[5:2]_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 768) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1 <<
                                                                 [RATE_DIVIDER_EXPONENT]) */
        uint64_t reserved_17_28        : 12;
        uint64_t burst_mantissa        : 8;  /**< [ 36: 29](R/W) Burst mantissa. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t burst_exponent        : 4;  /**< [ 40: 37](R/W) Burst exponent. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t reserved_41_63        : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqx_cir_s cn; */
} bdk_pko_l3_sqx_cir_t;

static inline uint64_t BDK_PKO_L3_SQX_CIR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQX_CIR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000100018ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L3_SQX_CIR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQX_CIR(a) bdk_pko_l3_sqx_cir_t
#define bustype_BDK_PKO_L3_SQX_CIR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQX_CIR(a) "PKO_L3_SQX_CIR"
#define device_bar_BDK_PKO_L3_SQX_CIR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQX_CIR(a) (a)
#define arguments_BDK_PKO_L3_SQX_CIR(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l3_sq#_green
 *
 * INTERNAL: PKO PSE Level 3 Shaping Queue Green State Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqx_green_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_41_63        : 23;
        uint64_t rr_active             : 1;  /**< [ 40: 40](R/W/H) Round-robin red active. Indicates that the round-robin input is mapped to RED. */
        uint64_t active_vec            : 20; /**< [ 39: 20](R/W/H) Active vector. A 10-bit vector, ordered by priority, that indicate which inputs to this
                                                                 scheduling queue are active. For internal use only. */
        uint64_t reserved_18_19        : 2;
        uint64_t head                  : 8;  /**< [ 17: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_8_9          : 2;
        uint64_t tail                  : 8;  /**< [  7:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
#else /* Word 0 - Little Endian */
        uint64_t tail                  : 8;  /**< [  7:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
        uint64_t reserved_8_9          : 2;
        uint64_t head                  : 8;  /**< [ 17: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_18_19        : 2;
        uint64_t active_vec            : 20; /**< [ 39: 20](R/W/H) Active vector. A 10-bit vector, ordered by priority, that indicate which inputs to this
                                                                 scheduling queue are active. For internal use only. */
        uint64_t rr_active             : 1;  /**< [ 40: 40](R/W/H) Round-robin red active. Indicates that the round-robin input is mapped to RED. */
        uint64_t reserved_41_63        : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqx_green_s cn; */
} bdk_pko_l3_sqx_green_t;

static inline uint64_t BDK_PKO_L3_SQX_GREEN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQX_GREEN(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000180058ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L3_SQX_GREEN", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQX_GREEN(a) bdk_pko_l3_sqx_green_t
#define bustype_BDK_PKO_L3_SQX_GREEN(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQX_GREEN(a) "PKO_L3_SQX_GREEN"
#define device_bar_BDK_PKO_L3_SQX_GREEN(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQX_GREEN(a) (a)
#define arguments_BDK_PKO_L3_SQX_GREEN(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l3_sq#_pick
 *
 * PKO PSE Level 3 Shaping Queue Packet Pick State Debug Register
 * This CSR contains the meta for the L3 SQ, and is for debug and reconfiguration
 * only and should never be written. See also PKO_META_DESC_S.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqx_pick_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dq                    : 10; /**< [ 63: 54](R/W/H) Descriptor queue. Index of originating descriptor queue. */
        uint64_t color                 : 2;  /**< [ 53: 52](R/W/H) See PKO_COLORRESULT_E. */
        uint64_t child                 : 10; /**< [ 51: 42](R/W/H) Child index. When the C_CON bit of this result is set, indicating that this result is
                                                                 connected in a flow that extends through the child result, this is the index of that child
                                                                 result. */
        uint64_t bubble                : 1;  /**< [ 41: 41](R/W/H) This metapacket is a fake passed forward after a prune. */
        uint64_t p_con                 : 1;  /**< [ 40: 40](R/W/H) Parent connected flag. This pick has more picks in front of it. */
        uint64_t c_con                 : 1;  /**< [ 39: 39](R/W/H) Child connected flag. This pick has more picks behind it. */
        uint64_t uid                   : 7;  /**< [ 38: 32](R/W/H) Unique ID. 7-bit unique value assigned at the DQ level, increments for each packet. */
        uint64_t jump                  : 1;  /**< [ 31: 31](R/W/H) Set when the corresponding descriptor contains a PKO_SEND_JUMP_S.  See also
                                                                 PKO_META_DESC_S[JUMP]. */
        uint64_t fpd                   : 1;  /**< [ 30: 30](R/W/H) First packet descriptor. Set when corresponding descriptor is the first in a cacheline.
                                                                 See also PKO_META_DESC_S[FPD]. */
        uint64_t ds                    : 1;  /**< [ 29: 29](R/W/H) PKO_SEND_HDR_S[DS] from the corresponding descriptor. Should always be zero.
                                                                 See also PKO_META_DESC_S[DS]. */
        uint64_t adjust                : 9;  /**< [ 28: 20](R/W/H) When [ADJUST] is 0x100, it indicates that this CSR does not contain a valid meta,
                                                                 and all other fields in this CSR are invalid and shouldn't be used.

                                                                 When [ADJUST] is not 0x100, it is the PKO_SEND_HDR_S[SHP_CHG] for the
                                                                 packet. See also PKO_META_DESC_S[ADJUST]. */
        uint64_t pir_dis               : 1;  /**< [ 19: 19](R/W/H) PIR disable. Peak shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or CIR_ONLY
                                                                 (i.e. [PIR_DIS]=PKO_SEND_EXT_S[COL<1>]). Zero if a PKO_SEND_EXT_S is not present in the
                                                                 corresponding descriptor. See PKO_COLORALG_E. [PIR_DIS] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[COL<1>]. */
        uint64_t cir_dis               : 1;  /**< [ 18: 18](R/W/H) CIR disable. Committed shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or
                                                                 PIR_ONLY (i.e. [CIR_DIS]=PKO_SEND_EXT_S[COL<0>]). Zero if a PKO_SEND_EXT_S is not
                                                                 present in the corresponding descriptor. See PKO_COLORALG_E. [CIR_DIS] is used by the
                                                                 DQ through L2 shapers, but not used by the L1 rate limiters. See also
                                                                 PKO_META_DESC_S[COL<0>]. */
        uint64_t red_algo_override     : 2;  /**< [ 17: 16](R/W/H) PKO_SEND_HDR_S[SHP_RA] from the corresponding packet descriptor.
                                                                 [RED_ALGO_OVERRIDE] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[RA]. */
        uint64_t length                : 16; /**< [ 15:  0](R/W/H) Meta packet length. Generally, the size of the outgoing packet
                                                                 including pad, but excluding FCS and preamble.

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] clear:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(PKO_SEND_HDR_S[TOTAL], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               PKO_SEND_HDR_S[TOTAL]

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] set:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(FPS+PKO_SEND_HDR_S[TSO_SB], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               (FPS+PKO_SEND_HDR_S[TSO_SB])

                                                                 d is the DQ that the PKO SEND used. FPS is the number of payload bytes
                                                                 in the TSO segment. See also PKO_META_DESC_S[LENGTH]. */
#else /* Word 0 - Little Endian */
        uint64_t length                : 16; /**< [ 15:  0](R/W/H) Meta packet length. Generally, the size of the outgoing packet
                                                                 including pad, but excluding FCS and preamble.

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] clear:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(PKO_SEND_HDR_S[TOTAL], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               PKO_SEND_HDR_S[TOTAL]

                                                                 For metas corresponding to PKO_SEND_HDR_S[TSO] set:

                                                                  [LENGTH] = PKO_PDM_DQd_MINPAD[MINPAD] ?
                                                                               MAX(FPS+PKO_SEND_HDR_S[TSO_SB], PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                               (FPS+PKO_SEND_HDR_S[TSO_SB])

                                                                 d is the DQ that the PKO SEND used. FPS is the number of payload bytes
                                                                 in the TSO segment. See also PKO_META_DESC_S[LENGTH]. */
        uint64_t red_algo_override     : 2;  /**< [ 17: 16](R/W/H) PKO_SEND_HDR_S[SHP_RA] from the corresponding packet descriptor.
                                                                 [RED_ALGO_OVERRIDE] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[RA]. */
        uint64_t cir_dis               : 1;  /**< [ 18: 18](R/W/H) CIR disable. Committed shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or
                                                                 PIR_ONLY (i.e. [CIR_DIS]=PKO_SEND_EXT_S[COL<0>]). Zero if a PKO_SEND_EXT_S is not
                                                                 present in the corresponding descriptor. See PKO_COLORALG_E. [CIR_DIS] is used by the
                                                                 DQ through L2 shapers, but not used by the L1 rate limiters. See also
                                                                 PKO_META_DESC_S[COL<0>]. */
        uint64_t pir_dis               : 1;  /**< [ 19: 19](R/W/H) PIR disable. Peak shaper disabled. Set when PKO_SEND_EXT_S[COL] is NO_COLOR or CIR_ONLY
                                                                 (i.e. [PIR_DIS]=PKO_SEND_EXT_S[COL<1>]). Zero if a PKO_SEND_EXT_S is not present in the
                                                                 corresponding descriptor. See PKO_COLORALG_E. [PIR_DIS] is used by the DQ through L2
                                                                 shapers, but not used by the L1 rate limiters. See also PKO_META_DESC_S[COL<1>]. */
        uint64_t adjust                : 9;  /**< [ 28: 20](R/W/H) When [ADJUST] is 0x100, it indicates that this CSR does not contain a valid meta,
                                                                 and all other fields in this CSR are invalid and shouldn't be used.

                                                                 When [ADJUST] is not 0x100, it is the PKO_SEND_HDR_S[SHP_CHG] for the
                                                                 packet. See also PKO_META_DESC_S[ADJUST]. */
        uint64_t ds                    : 1;  /**< [ 29: 29](R/W/H) PKO_SEND_HDR_S[DS] from the corresponding descriptor. Should always be zero.
                                                                 See also PKO_META_DESC_S[DS]. */
        uint64_t fpd                   : 1;  /**< [ 30: 30](R/W/H) First packet descriptor. Set when corresponding descriptor is the first in a cacheline.
                                                                 See also PKO_META_DESC_S[FPD]. */
        uint64_t jump                  : 1;  /**< [ 31: 31](R/W/H) Set when the corresponding descriptor contains a PKO_SEND_JUMP_S.  See also
                                                                 PKO_META_DESC_S[JUMP]. */
        uint64_t uid                   : 7;  /**< [ 38: 32](R/W/H) Unique ID. 7-bit unique value assigned at the DQ level, increments for each packet. */
        uint64_t c_con                 : 1;  /**< [ 39: 39](R/W/H) Child connected flag. This pick has more picks behind it. */
        uint64_t p_con                 : 1;  /**< [ 40: 40](R/W/H) Parent connected flag. This pick has more picks in front of it. */
        uint64_t bubble                : 1;  /**< [ 41: 41](R/W/H) This metapacket is a fake passed forward after a prune. */
        uint64_t child                 : 10; /**< [ 51: 42](R/W/H) Child index. When the C_CON bit of this result is set, indicating that this result is
                                                                 connected in a flow that extends through the child result, this is the index of that child
                                                                 result. */
        uint64_t color                 : 2;  /**< [ 53: 52](R/W/H) See PKO_COLORRESULT_E. */
        uint64_t dq                    : 10; /**< [ 63: 54](R/W/H) Descriptor queue. Index of originating descriptor queue. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqx_pick_s cn; */
} bdk_pko_l3_sqx_pick_t;

static inline uint64_t BDK_PKO_L3_SQX_PICK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQX_PICK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000180070ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L3_SQX_PICK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQX_PICK(a) bdk_pko_l3_sqx_pick_t
#define bustype_BDK_PKO_L3_SQX_PICK(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQX_PICK(a) "PKO_L3_SQX_PICK"
#define device_bar_BDK_PKO_L3_SQX_PICK(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQX_PICK(a) (a)
#define arguments_BDK_PKO_L3_SQX_PICK(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l3_sq#_pir
 *
 * PKO PSE Level 3 Shaping Queue Peak Information Rate Register
 * This register has the same bit fields as PKO_L1_SQ()_CIR.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqx_pir_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_41_63        : 23;
        uint64_t burst_exponent        : 4;  /**< [ 40: 37](R/W) Burst exponent. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t burst_mantissa        : 8;  /**< [ 36: 29](R/W) Burst mantissa. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t reserved_17_28        : 12;
        uint64_t rate_divider_exponent : 4;  /**< [ 16: 13](R/W) Rate divider exponent. This 4-bit base-2 exponent is used to divide the credit rate by
                                                                 specifying the number of time-wheel turns required before the accumulator is increased.
                                                                 [RATE_DIVIDER_EXPONENT] should be used to specify data rates lower than ~10 Kbps and
                                                                 [RATE_EXPONENT] should be set to zero whenever it is used.

                                                                 The rate count = (1 << [RATE_DIVIDER_EXPONENT]). The supported range for
                                                                 [RATE_DIVIDER_EXPONENT] is 0 to 12. Programmed values greater than 12 are treated as 12.

                                                                 Note that for the L1-SQs, a time-wheel turn is 96 clocks (SCLK). For the other levels a
                                                                 time-wheel turn is 768 clocks (SCLK).

                                                                 For L1_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 96) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1
                                                                 <<[RATE_DIVIDER_EXPONENT])

                                                                 For L[5:2]_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 768) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1 <<
                                                                 [RATE_DIVIDER_EXPONENT]) */
        uint64_t rate_exponent         : 4;  /**< [ 12:  9](R/W) Rate exponent. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT].
                                                                 [RATE_EXPONENT] should be used to specify data rates higher than ~10 Kbps and
                                                                 [RATE_DIVIDER_EXPONENT] should be set to zero whenever it is nonzero. */
        uint64_t rate_mantissa         : 8;  /**< [  8:  1](R/W) Rate mantissa. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT]. */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable. Enables CIR shaping. */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable. Enables CIR shaping. */
        uint64_t rate_mantissa         : 8;  /**< [  8:  1](R/W) Rate mantissa. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT]. */
        uint64_t rate_exponent         : 4;  /**< [ 12:  9](R/W) Rate exponent. The rate is specified as 1.[RATE_MANTISSA] << [RATE_EXPONENT].
                                                                 [RATE_EXPONENT] should be used to specify data rates higher than ~10 Kbps and
                                                                 [RATE_DIVIDER_EXPONENT] should be set to zero whenever it is nonzero. */
        uint64_t rate_divider_exponent : 4;  /**< [ 16: 13](R/W) Rate divider exponent. This 4-bit base-2 exponent is used to divide the credit rate by
                                                                 specifying the number of time-wheel turns required before the accumulator is increased.
                                                                 [RATE_DIVIDER_EXPONENT] should be used to specify data rates lower than ~10 Kbps and
                                                                 [RATE_EXPONENT] should be set to zero whenever it is used.

                                                                 The rate count = (1 << [RATE_DIVIDER_EXPONENT]). The supported range for
                                                                 [RATE_DIVIDER_EXPONENT] is 0 to 12. Programmed values greater than 12 are treated as 12.

                                                                 Note that for the L1-SQs, a time-wheel turn is 96 clocks (SCLK). For the other levels a
                                                                 time-wheel turn is 768 clocks (SCLK).

                                                                 For L1_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 96) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1
                                                                 <<[RATE_DIVIDER_EXPONENT])

                                                                 For L[5:2]_SQ: RATE (bytes/second) =
                                                                   (SCLK_FREQUENCY / 768) * ((1.[RATE_MANTISSA]) << [RATE_EXPONENT]) / (1 <<
                                                                 [RATE_DIVIDER_EXPONENT]) */
        uint64_t reserved_17_28        : 12;
        uint64_t burst_mantissa        : 8;  /**< [ 36: 29](R/W) Burst mantissa. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t burst_exponent        : 4;  /**< [ 40: 37](R/W) Burst exponent. The burst limit is 1.[BURST_MANTISSA] << ([BURST_EXPONENT] + 1).
                                                                 With [BURST_EXPONENT]=0xF and [BURST_MANTISSA]=0xFF, the burst limit is the largest
                                                                 possible value, which is 130,816 (0x1FF00) bytes. */
        uint64_t reserved_41_63        : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqx_pir_s cn; */
} bdk_pko_l3_sqx_pir_t;

static inline uint64_t BDK_PKO_L3_SQX_PIR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQX_PIR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000100020ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L3_SQX_PIR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQX_PIR(a) bdk_pko_l3_sqx_pir_t
#define bustype_BDK_PKO_L3_SQX_PIR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQX_PIR(a) "PKO_L3_SQX_PIR"
#define device_bar_BDK_PKO_L3_SQX_PIR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQX_PIR(a) (a)
#define arguments_BDK_PKO_L3_SQX_PIR(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l3_sq#_pointers
 *
 * INTERNAL: PKO PSE Level 3 Shaping Queue Linked List Pointers Debug Register
 *
 * This register has the same bit fields as PKO_L2_SQ()_POINTERS.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqx_pointers_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t prev                  : 8;  /**< [ 23: 16](R/W/H) Previous pointer. The linked-list previous pointer. */
        uint64_t reserved_8_15         : 8;
        uint64_t next                  : 8;  /**< [  7:  0](R/W/H) Next pointer. The linked-list next pointer. */
#else /* Word 0 - Little Endian */
        uint64_t next                  : 8;  /**< [  7:  0](R/W/H) Next pointer. The linked-list next pointer. */
        uint64_t reserved_8_15         : 8;
        uint64_t prev                  : 8;  /**< [ 23: 16](R/W/H) Previous pointer. The linked-list previous pointer. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqx_pointers_s cn; */
} bdk_pko_l3_sqx_pointers_t;

static inline uint64_t BDK_PKO_L3_SQX_POINTERS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQX_POINTERS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000100078ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L3_SQX_POINTERS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQX_POINTERS(a) bdk_pko_l3_sqx_pointers_t
#define bustype_BDK_PKO_L3_SQX_POINTERS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQX_POINTERS(a) "PKO_L3_SQX_POINTERS"
#define device_bar_BDK_PKO_L3_SQX_POINTERS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQX_POINTERS(a) (a)
#define arguments_BDK_PKO_L3_SQX_POINTERS(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l3_sq#_red
 *
 * INTERNAL: PKO PSE Level 3 Shaping Queue Red State Debug Register
 *
 * This register has the same bit fields as PKO_L3_SQ()_YELLOW.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqx_red_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_18_63        : 46;
        uint64_t head                  : 8;  /**< [ 17: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_8_9          : 2;
        uint64_t tail                  : 8;  /**< [  7:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
#else /* Word 0 - Little Endian */
        uint64_t tail                  : 8;  /**< [  7:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
        uint64_t reserved_8_9          : 2;
        uint64_t head                  : 8;  /**< [ 17: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_18_63        : 46;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqx_red_s cn; */
} bdk_pko_l3_sqx_red_t;

static inline uint64_t BDK_PKO_L3_SQX_RED(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQX_RED(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000180068ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L3_SQX_RED", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQX_RED(a) bdk_pko_l3_sqx_red_t
#define bustype_BDK_PKO_L3_SQX_RED(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQX_RED(a) "PKO_L3_SQX_RED"
#define device_bar_BDK_PKO_L3_SQX_RED(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQX_RED(a) (a)
#define arguments_BDK_PKO_L3_SQX_RED(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l3_sq#_sched_state
 *
 * PKO PSE Level 3 Scheduling Control State Register
 * This register has the same bit fields as PKO_L2_SQ(0..255)_SCHED_STATE.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqx_sched_state_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_25_63        : 39;
        uint64_t rr_count              : 25; /**< [ 24:  0](R/W/H) Round-robin (DWRR) deficit counter. A 25-bit signed integer count. For diagnostic use. */
#else /* Word 0 - Little Endian */
        uint64_t rr_count              : 25; /**< [ 24:  0](R/W/H) Round-robin (DWRR) deficit counter. A 25-bit signed integer count. For diagnostic use. */
        uint64_t reserved_25_63        : 39;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqx_sched_state_s cn; */
} bdk_pko_l3_sqx_sched_state_t;

static inline uint64_t BDK_PKO_L3_SQX_SCHED_STATE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQX_SCHED_STATE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000100028ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L3_SQX_SCHED_STATE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQX_SCHED_STATE(a) bdk_pko_l3_sqx_sched_state_t
#define bustype_BDK_PKO_L3_SQX_SCHED_STATE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQX_SCHED_STATE(a) "PKO_L3_SQX_SCHED_STATE"
#define device_bar_BDK_PKO_L3_SQX_SCHED_STATE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQX_SCHED_STATE(a) (a)
#define arguments_BDK_PKO_L3_SQX_SCHED_STATE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l3_sq#_schedule
 *
 * PKO PSE Level 3 Scheduling Control Register
 * This register has the same bit fields as PKO_L2_SQ()_SCHEDULE.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqx_schedule_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t prio                  : 4;  /**< [ 27: 24](R/W) Priority. The priority used for this SQ in the (lower-level) parent's scheduling
                                                                 algorithm. When this SQ is not used, we recommend setting [PRIO] to zero. The legal [PRIO]
                                                                 values are 0-9 when the SQ is used. In addition to priority, [PRIO] determines whether the
                                                                 SQ is a static queue or not: If [PRIO] equals PKO_*_SQn_TOPOLOGY[RR_PRIO], where
                                                                 PKO_*_TOPOLOGY[PARENT] for this SQ equals n, then this is a round-robin child queue into
                                                                 the shaper at the next level. */
        uint64_t rr_quantum            : 24; /**< [ 23:  0](R/W) Round-robin (DWRR) quantum. The deficit-weighted round-robin quantum (24-bit unsigned
                                                                 integer). The packet size used in all DWRR (RR_COUNT) calculations is:

                                                                 _  (PKO_nm_SHAPE[LENGTH_DISABLE] ? 0 : (PKO_nm_PICK[LENGTH] + PKO_nm_PICK[ADJUST]))
                                                                    + PKO_nm_SHAPE[ADJUST]

                                                                 where nm corresponds to this PKO_nm_SCHEDULE CSR.

                                                                 Typically [RR_QUANTUM] should be at or near the MTU or more (to limit or prevent
                                                                 negative accumulations of PKO_*_SCHED_STATE[RR_COUNT] (i.e. the deficit count)). */
#else /* Word 0 - Little Endian */
        uint64_t rr_quantum            : 24; /**< [ 23:  0](R/W) Round-robin (DWRR) quantum. The deficit-weighted round-robin quantum (24-bit unsigned
                                                                 integer). The packet size used in all DWRR (RR_COUNT) calculations is:

                                                                 _  (PKO_nm_SHAPE[LENGTH_DISABLE] ? 0 : (PKO_nm_PICK[LENGTH] + PKO_nm_PICK[ADJUST]))
                                                                    + PKO_nm_SHAPE[ADJUST]

                                                                 where nm corresponds to this PKO_nm_SCHEDULE CSR.

                                                                 Typically [RR_QUANTUM] should be at or near the MTU or more (to limit or prevent
                                                                 negative accumulations of PKO_*_SCHED_STATE[RR_COUNT] (i.e. the deficit count)). */
        uint64_t prio                  : 4;  /**< [ 27: 24](R/W) Priority. The priority used for this SQ in the (lower-level) parent's scheduling
                                                                 algorithm. When this SQ is not used, we recommend setting [PRIO] to zero. The legal [PRIO]
                                                                 values are 0-9 when the SQ is used. In addition to priority, [PRIO] determines whether the
                                                                 SQ is a static queue or not: If [PRIO] equals PKO_*_SQn_TOPOLOGY[RR_PRIO], where
                                                                 PKO_*_TOPOLOGY[PARENT] for this SQ equals n, then this is a round-robin child queue into
                                                                 the shaper at the next level. */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqx_schedule_s cn; */
} bdk_pko_l3_sqx_schedule_t;

static inline uint64_t BDK_PKO_L3_SQX_SCHEDULE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQX_SCHEDULE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000100008ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L3_SQX_SCHEDULE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQX_SCHEDULE(a) bdk_pko_l3_sqx_schedule_t
#define bustype_BDK_PKO_L3_SQX_SCHEDULE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQX_SCHEDULE(a) "PKO_L3_SQX_SCHEDULE"
#define device_bar_BDK_PKO_L3_SQX_SCHEDULE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQX_SCHEDULE(a) (a)
#define arguments_BDK_PKO_L3_SQX_SCHEDULE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l3_sq#_shape
 *
 * PKO PSE Level 3 Shaping Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqx_shape_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t schedule_list         : 2;  /**< [ 26: 25](R/W) Shaper scheduling list. Restricts shaper scheduling to specific lists.
                                                                   0x0 = Normal (selected for nearly all scheduling/shaping applications).
                                                                   0x1 = Green-only.
                                                                   0x2 = Yellow-only.
                                                                   0x3 = Red-only. */
        uint64_t length_disable        : 1;  /**< [ 24: 24](R/W) Length disable. Disables the use of packet lengths in DWRR scheduling
                                                                 and shaping calculations such that only the value of [ADJUST] is used. */
        uint64_t reserved_13_23        : 11;
        uint64_t yellow_disable        : 1;  /**< [ 12: 12](R/W) See PKO_L2_SQ()_SHAPE[YELLOW_DISABLE]. */
        uint64_t red_disable           : 1;  /**< [ 11: 11](R/W) See PKO_L2_SQ()_SHAPE[RED_DISABLE]. */
        uint64_t red_algo              : 2;  /**< [ 10:  9](R/W) See PKO_L2_SQ()_SHAPE[RED_ALGO]. */
        uint64_t adjust                : 9;  /**< [  8:  0](R/W) See PKO_L2_SQ()_SHAPE[ADJUST]. */
#else /* Word 0 - Little Endian */
        uint64_t adjust                : 9;  /**< [  8:  0](R/W) See PKO_L2_SQ()_SHAPE[ADJUST]. */
        uint64_t red_algo              : 2;  /**< [ 10:  9](R/W) See PKO_L2_SQ()_SHAPE[RED_ALGO]. */
        uint64_t red_disable           : 1;  /**< [ 11: 11](R/W) See PKO_L2_SQ()_SHAPE[RED_DISABLE]. */
        uint64_t yellow_disable        : 1;  /**< [ 12: 12](R/W) See PKO_L2_SQ()_SHAPE[YELLOW_DISABLE]. */
        uint64_t reserved_13_23        : 11;
        uint64_t length_disable        : 1;  /**< [ 24: 24](R/W) Length disable. Disables the use of packet lengths in DWRR scheduling
                                                                 and shaping calculations such that only the value of [ADJUST] is used. */
        uint64_t schedule_list         : 2;  /**< [ 26: 25](R/W) Shaper scheduling list. Restricts shaper scheduling to specific lists.
                                                                   0x0 = Normal (selected for nearly all scheduling/shaping applications).
                                                                   0x1 = Green-only.
                                                                   0x2 = Yellow-only.
                                                                   0x3 = Red-only. */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqx_shape_s cn; */
} bdk_pko_l3_sqx_shape_t;

static inline uint64_t BDK_PKO_L3_SQX_SHAPE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQX_SHAPE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000100010ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L3_SQX_SHAPE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQX_SHAPE(a) bdk_pko_l3_sqx_shape_t
#define bustype_BDK_PKO_L3_SQX_SHAPE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQX_SHAPE(a) "PKO_L3_SQX_SHAPE"
#define device_bar_BDK_PKO_L3_SQX_SHAPE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQX_SHAPE(a) (a)
#define arguments_BDK_PKO_L3_SQX_SHAPE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l3_sq#_shape_state
 *
 * PKO PSE Level 3 Shaping State Register
 * This register has the same bit fields as PKO_L2_SQ()_SHAPE_STATE.
 * This register must not be written during normal operation.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqx_shape_state_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t tw_timestamp          : 6;  /**< [ 59: 54](R/W/H) Time-wheel timestamp. Debug access to the live time-wheel timestamp. */
        uint64_t color                 : 2;  /**< [ 53: 52](R/W/H) Shaper connection status. Debug access to the live shaper state.
                                                                 0x0 = Green - shaper is connected into the green list.
                                                                 0x1 = Yellow - shaper is connected into the yellow list.
                                                                 0x2 = Red - shaper is connected into the red list.
                                                                 0x3 = Pruned - shaper is disconnected. */
        uint64_t pir_accum             : 26; /**< [ 51: 26](R/W/H) Peak information rate accumulator. Debug access to the live PIR accumulator. */
        uint64_t cir_accum             : 26; /**< [ 25:  0](R/W/H) Committed information rate accumulator. Debug access to the live CIR accumulator. */
#else /* Word 0 - Little Endian */
        uint64_t cir_accum             : 26; /**< [ 25:  0](R/W/H) Committed information rate accumulator. Debug access to the live CIR accumulator. */
        uint64_t pir_accum             : 26; /**< [ 51: 26](R/W/H) Peak information rate accumulator. Debug access to the live PIR accumulator. */
        uint64_t color                 : 2;  /**< [ 53: 52](R/W/H) Shaper connection status. Debug access to the live shaper state.
                                                                 0x0 = Green - shaper is connected into the green list.
                                                                 0x1 = Yellow - shaper is connected into the yellow list.
                                                                 0x2 = Red - shaper is connected into the red list.
                                                                 0x3 = Pruned - shaper is disconnected. */
        uint64_t tw_timestamp          : 6;  /**< [ 59: 54](R/W/H) Time-wheel timestamp. Debug access to the live time-wheel timestamp. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqx_shape_state_s cn; */
} bdk_pko_l3_sqx_shape_state_t;

static inline uint64_t BDK_PKO_L3_SQX_SHAPE_STATE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQX_SHAPE_STATE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000100030ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L3_SQX_SHAPE_STATE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQX_SHAPE_STATE(a) bdk_pko_l3_sqx_shape_state_t
#define bustype_BDK_PKO_L3_SQX_SHAPE_STATE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQX_SHAPE_STATE(a) "PKO_L3_SQX_SHAPE_STATE"
#define device_bar_BDK_PKO_L3_SQX_SHAPE_STATE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQX_SHAPE_STATE(a) (a)
#define arguments_BDK_PKO_L3_SQX_SHAPE_STATE(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l3_sq#_sw_xoff
 *
 * PKO PSE Level 3 Software Controlled XOFF Register
 * This register has the same bit fields as PKO_L1_SQ()_SW_XOFF
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqx_sw_xoff_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t drain_irq             : 1;  /**< [  3:  3](WO) Drain IRQ. Enables an interrupt that fires when the drain operation has completed.
                                                                 [DRAIN_IRQ] should be set whenever [DRAIN] is, and must not be set
                                                                 when [DRAIN] isn't set. [DRAIN_IRQ] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t drain_null_link       : 1;  /**< [  2:  2](WO) Drain null link. This setting only has effect when the L1 node is
                                                                 mapped to the NULL FIFO.  Conditions the drain path to drain through
                                                                 the NULL FIFO (i.e. link 14). As such, channel credits, HW_XOFF, and
                                                                 shaping are disabled on the draining path until the path has drained.
                                                                 [DRAIN_NULL_LINK] must not be set when [DRAIN] isn't set.
                                                                 [DRAIN_NULL_LINK] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t drain                 : 1;  /**< [  1:  1](WO) Drain. This control activates a drain path through the PSE that starts at this node and
                                                                 ends at the SQ1 level. The drain path is prioritized over other paths through PSE and can
                                                                 be used in combination with [DRAIN_NULL_LINK] and [DRAIN_IRQ]. [DRAIN] need never be
                                                                 set for the SQ1 level, but is useful at all other levels, including the DQ level.
                                                                 PKO_PQ_DRAIN_W1C[INTR] should be clear prior to initiating a [DRAIN]=1 write to this CSR.
                                                                 After [DRAIN] is set for an SQ/DQ, it should not be set again, for this or any other
                                                                 SQ/DQ, until after a 0->1 transition has been observed on PKO_PQ_DRAIN_W1C[INTR]
                                                                 (and/or the PKO_PSE_PQ_DRAIN interrupt has occured) and
                                                                 PKO_PQ_DRAIN_W1C[INTR] has been cleared.  DRAIN has no effect unless XOFF is also set.
                                                                 Only one DRAIN command is allowed to be active at a time. */
        uint64_t xoff                  : 1;  /**< [  0:  0](R/W) XOFF. Stops meta flow out of the SQ/DQ. When [XOFF] is set, the corresponding
                                                                 PKO_*_PICK (i.e. the meta) in the SQ/DQ cannot be transferred to the
                                                                 next level. The corresponding PKO_*_PICK may become valid while [XOFF] is set,
                                                                 but it cannot change from valid to invalid while [XOFF] is set.
                                                                 NOTE: The associated PKO_*_TOPOLOGY[LINK/PARENT] should normally be configured before
                                                                 [XOFF] is set. Setting [XOFF] before the associated PKO_*_TOPOLOGY[LINK/PARENT]
                                                                 value is configured can result in modifying the software [XOFF] state of the wrong SQ. */
#else /* Word 0 - Little Endian */
        uint64_t xoff                  : 1;  /**< [  0:  0](R/W) XOFF. Stops meta flow out of the SQ/DQ. When [XOFF] is set, the corresponding
                                                                 PKO_*_PICK (i.e. the meta) in the SQ/DQ cannot be transferred to the
                                                                 next level. The corresponding PKO_*_PICK may become valid while [XOFF] is set,
                                                                 but it cannot change from valid to invalid while [XOFF] is set.
                                                                 NOTE: The associated PKO_*_TOPOLOGY[LINK/PARENT] should normally be configured before
                                                                 [XOFF] is set. Setting [XOFF] before the associated PKO_*_TOPOLOGY[LINK/PARENT]
                                                                 value is configured can result in modifying the software [XOFF] state of the wrong SQ. */
        uint64_t drain                 : 1;  /**< [  1:  1](WO) Drain. This control activates a drain path through the PSE that starts at this node and
                                                                 ends at the SQ1 level. The drain path is prioritized over other paths through PSE and can
                                                                 be used in combination with [DRAIN_NULL_LINK] and [DRAIN_IRQ]. [DRAIN] need never be
                                                                 set for the SQ1 level, but is useful at all other levels, including the DQ level.
                                                                 PKO_PQ_DRAIN_W1C[INTR] should be clear prior to initiating a [DRAIN]=1 write to this CSR.
                                                                 After [DRAIN] is set for an SQ/DQ, it should not be set again, for this or any other
                                                                 SQ/DQ, until after a 0->1 transition has been observed on PKO_PQ_DRAIN_W1C[INTR]
                                                                 (and/or the PKO_PSE_PQ_DRAIN interrupt has occured) and
                                                                 PKO_PQ_DRAIN_W1C[INTR] has been cleared.  DRAIN has no effect unless XOFF is also set.
                                                                 Only one DRAIN command is allowed to be active at a time. */
        uint64_t drain_null_link       : 1;  /**< [  2:  2](WO) Drain null link. This setting only has effect when the L1 node is
                                                                 mapped to the NULL FIFO.  Conditions the drain path to drain through
                                                                 the NULL FIFO (i.e. link 14). As such, channel credits, HW_XOFF, and
                                                                 shaping are disabled on the draining path until the path has drained.
                                                                 [DRAIN_NULL_LINK] must not be set when [DRAIN] isn't set.
                                                                 [DRAIN_NULL_LINK] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t drain_irq             : 1;  /**< [  3:  3](WO) Drain IRQ. Enables an interrupt that fires when the drain operation has completed.
                                                                 [DRAIN_IRQ] should be set whenever [DRAIN] is, and must not be set
                                                                 when [DRAIN] isn't set. [DRAIN_IRQ] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqx_sw_xoff_s cn; */
} bdk_pko_l3_sqx_sw_xoff_t;

static inline uint64_t BDK_PKO_L3_SQX_SW_XOFF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQX_SW_XOFF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x8540001000e0ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L3_SQX_SW_XOFF", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQX_SW_XOFF(a) bdk_pko_l3_sqx_sw_xoff_t
#define bustype_BDK_PKO_L3_SQX_SW_XOFF(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQX_SW_XOFF(a) "PKO_L3_SQX_SW_XOFF"
#define device_bar_BDK_PKO_L3_SQX_SW_XOFF(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQX_SW_XOFF(a) (a)
#define arguments_BDK_PKO_L3_SQX_SW_XOFF(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l3_sq#_topology
 *
 * PKO PSE Level 3 Shaping Queue Topology Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqx_topology_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t prio_anchor           : 8;  /**< [ 39: 32](R/W) See PKO_L1_SQ()_TOPOLOGY[PRIO_ANCHOR]. */
        uint64_t reserved_24_31        : 8;
        uint64_t parent                : 8;  /**< [ 23: 16](R/W) See PKO_L2_SQ()_TOPOLOGY[PARENT]. */
        uint64_t reserved_5_15         : 11;
        uint64_t rr_prio               : 4;  /**< [  4:  1](R/W) See PKO_L1_SQ()_TOPOLOGY[RR_PRIO]. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t rr_prio               : 4;  /**< [  4:  1](R/W) See PKO_L1_SQ()_TOPOLOGY[RR_PRIO]. */
        uint64_t reserved_5_15         : 11;
        uint64_t parent                : 8;  /**< [ 23: 16](R/W) See PKO_L2_SQ()_TOPOLOGY[PARENT]. */
        uint64_t reserved_24_31        : 8;
        uint64_t prio_anchor           : 8;  /**< [ 39: 32](R/W) See PKO_L1_SQ()_TOPOLOGY[PRIO_ANCHOR]. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqx_topology_s cn; */
} bdk_pko_l3_sqx_topology_t;

static inline uint64_t BDK_PKO_L3_SQX_TOPOLOGY(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQX_TOPOLOGY(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000180000ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L3_SQX_TOPOLOGY", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQX_TOPOLOGY(a) bdk_pko_l3_sqx_topology_t
#define bustype_BDK_PKO_L3_SQX_TOPOLOGY(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQX_TOPOLOGY(a) "PKO_L3_SQX_TOPOLOGY"
#define device_bar_BDK_PKO_L3_SQX_TOPOLOGY(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQX_TOPOLOGY(a) (a)
#define arguments_BDK_PKO_L3_SQX_TOPOLOGY(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l3_sq#_yellow
 *
 * INTERNAL: PKO PSE Level 3 Shaping Queue Yellow State Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqx_yellow_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_18_63        : 46;
        uint64_t head                  : 8;  /**< [ 17: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_8_9          : 2;
        uint64_t tail                  : 8;  /**< [  7:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
#else /* Word 0 - Little Endian */
        uint64_t tail                  : 8;  /**< [  7:  0](R/W/H) Tail pointer. The index of round-robin linked-list tail. For internal use only. */
        uint64_t reserved_8_9          : 2;
        uint64_t head                  : 8;  /**< [ 17: 10](R/W/H) Head pointer. The index of round-robin linked-list head. For internal use only. */
        uint64_t reserved_18_63        : 46;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqx_yellow_s cn; */
} bdk_pko_l3_sqx_yellow_t;

static inline uint64_t BDK_PKO_L3_SQX_YELLOW(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQX_YELLOW(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x854000180060ll + 0x200ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_L3_SQX_YELLOW", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQX_YELLOW(a) bdk_pko_l3_sqx_yellow_t
#define bustype_BDK_PKO_L3_SQX_YELLOW(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQX_YELLOW(a) "PKO_L3_SQX_YELLOW"
#define device_bar_BDK_PKO_L3_SQX_YELLOW(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQX_YELLOW(a) (a)
#define arguments_BDK_PKO_L3_SQX_YELLOW(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_l3_sqa_debug
 *
 * INTERNAL: PKO PSE Level 3 SQ-A Internal Debug Register
 *
 * This register has the same bit fields as PKO_PQA_DEBUG.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqa_debug_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#else /* Word 0 - Little Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqa_debug_s cn; */
} bdk_pko_l3_sqa_debug_t;

#define BDK_PKO_L3_SQA_DEBUG BDK_PKO_L3_SQA_DEBUG_FUNC()
static inline uint64_t BDK_PKO_L3_SQA_DEBUG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQA_DEBUG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000180128ll;
    __bdk_csr_fatal("PKO_L3_SQA_DEBUG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQA_DEBUG bdk_pko_l3_sqa_debug_t
#define bustype_BDK_PKO_L3_SQA_DEBUG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQA_DEBUG "PKO_L3_SQA_DEBUG"
#define device_bar_BDK_PKO_L3_SQA_DEBUG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQA_DEBUG 0
#define arguments_BDK_PKO_L3_SQA_DEBUG -1,-1,-1,-1

/**
 * Register (NCB) pko_l3_sqb_debug
 *
 * INTERNAL: PKO PSE Level 3 SQ-B Internal Debug Register
 *
 * This register has the same bit fields as PKO_PQA_DEBUG.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l3_sqb_debug_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#else /* Word 0 - Little Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l3_sqb_debug_s cn; */
} bdk_pko_l3_sqb_debug_t;

#define BDK_PKO_L3_SQB_DEBUG BDK_PKO_L3_SQB_DEBUG_FUNC()
static inline uint64_t BDK_PKO_L3_SQB_DEBUG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L3_SQB_DEBUG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000180130ll;
    __bdk_csr_fatal("PKO_L3_SQB_DEBUG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_L3_SQB_DEBUG bdk_pko_l3_sqb_debug_t
#define bustype_BDK_PKO_L3_SQB_DEBUG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L3_SQB_DEBUG "PKO_L3_SQB_DEBUG"
#define device_bar_BDK_PKO_L3_SQB_DEBUG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L3_SQB_DEBUG 0
#define arguments_BDK_PKO_L3_SQB_DEBUG -1,-1,-1,-1

/**
 * Register (NCB) pko_l4_const
 *
 * PKO L4 Constants Register
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l4_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t count                 : 16; /**< [ 15:  0](RO) Number of Level-4 shaping queues. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 16; /**< [ 15:  0](RO) Number of Level-4 shaping queues. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l4_const_s cn; */
} bdk_pko_l4_const_t;

#define BDK_PKO_L4_CONST BDK_PKO_L4_CONST_FUNC()
static inline uint64_t BDK_PKO_L4_CONST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L4_CONST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000d00118ll;
    __bdk_csr_fatal("PKO_L4_CONST", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_L4_CONST bdk_pko_l4_const_t
#define bustype_BDK_PKO_L4_CONST BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L4_CONST "PKO_L4_CONST"
#define device_bar_BDK_PKO_L4_CONST 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L4_CONST 0
#define arguments_BDK_PKO_L4_CONST -1,-1,-1,-1

/**
 * Register (NCB) pko_l5_const
 *
 * PKO L5 Constants Register
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_l5_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t count                 : 16; /**< [ 15:  0](RO) Number of Level-5 shaping queues. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 16; /**< [ 15:  0](RO) Number of Level-5 shaping queues. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_l5_const_s cn; */
} bdk_pko_l5_const_t;

#define BDK_PKO_L5_CONST BDK_PKO_L5_CONST_FUNC()
static inline uint64_t BDK_PKO_L5_CONST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_L5_CONST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000d00120ll;
    __bdk_csr_fatal("PKO_L5_CONST", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_L5_CONST bdk_pko_l5_const_t
#define bustype_BDK_PKO_L5_CONST BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_L5_CONST "PKO_L5_CONST"
#define device_bar_BDK_PKO_L5_CONST 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_L5_CONST 0
#define arguments_BDK_PKO_L5_CONST -1,-1,-1,-1

/**
 * Register (NCB) pko_lut#
 *
 * PKO Channel to Queue Mapping LUT Registers
 * PKO_LUT has a location for each used PKI_CHAN_E. The following table
 * shows the mapping between LINK/MAC_NUM's, PKI_CHAN_E channels, and
 * PKO_LUT indices.
 *
 * <pre>
 *   LINK/   PKI_CHAN_E    Corresponding
 * MAC_NUM   Range         PKO_LUT index   Description
 * -------   -----------   -------------   -----------------
 *     0     0x000-0x03F   0x000-0x03F     LBK0 Loopback
 *     1     0x200-0x23F   0x200-0x23F     LBK1 Loopback
 *     2     0x400-0x47F   0x400-0x47F     DPI packet output
 *     3     0x800-0x80F   0x800-0x80F     BGX0 Logical MAC 0
 *     4     0x810-0x81F   0x810-0x81F     BGX0 Logical MAC 1
 *     5     0x820-0x82F   0x820-0x82F     BGX0 Logical MAC 2
 *     6     0x830-0x83F   0x830-0x83F     BGX0 Logical MAC 3
 *     7     0x900-0x90F   0x900-0x90F     BGX1 Logical MAC 0
 *     8     0x910-0x91F   0x910-0x91F     BGX1 Logical MAC 1
 *     9     0x920-0x92F   0x920-0x92F     BGX1 Logical MAC 2
 *    10     0x930-0x93F   0x930-0x93F     BGX1 Logical MAC 3
 *    11     0xA00-0xA0F   0xA00-0xA0F     BGX2 Logical MAC 0
 *    12     0xA10-0xA1F   0xA10-0xA1F     BGX2 Logical MAC 1
 *    13     0xA20-0xA2F   0xA20-0xA2F     BGX2 Logical MAC 2
 *    14     0xA30-0xA3F   0xA30-0xA3F     BGX2 Logical MAC 3
 *    15     0xB00-0xB0F   0xB00-0xB0F     BGX3 Logical MAC 0
 *    16     0xB10-0xB1F   0xB10-0xB1F     BGX3 Logical MAC 1
 *    17     0xB20-0xB2F   0xB20-0xB2F     BGX3 Logical MAC 2
 *    18     0xB30-0xB3F   0xB30-0xB3F     BGX3 Logical MAC 3
 * </pre>
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_lutx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t valid                 : 1;  /**< [ 15: 15](R/W) Declares if the index in the LUT is valid. */
        uint64_t reserved_14           : 1;
        uint64_t pq_idx                : 5;  /**< [ 13:  9](R/W) When [VALID] is set, [PQ_IDX] must select the L1 SQ that services the L2/L3 SQ that
                                                                 is selected by [QUEUE_NUMBER]. */
        uint64_t reserved_8            : 1;
        uint64_t queue_number          : 8;  /**< [  7:  0](R/W) When [VALID] is set, [QUEUE_NUMBER] selects the PKO_L3_L2_SQ()_CHANNEL CSR array entry
                                                                 for the PKO_LUT entry. This also selects an associated L2/L3 SQ.
                                                                 PKO_CHANNEL_LEVEL[CC_LEVEL]
                                                                 determines whether [QUEUE_NUMBER] selects an L2 SQ or a L3 SQ. */
#else /* Word 0 - Little Endian */
        uint64_t queue_number          : 8;  /**< [  7:  0](R/W) When [VALID] is set, [QUEUE_NUMBER] selects the PKO_L3_L2_SQ()_CHANNEL CSR array entry
                                                                 for the PKO_LUT entry. This also selects an associated L2/L3 SQ.
                                                                 PKO_CHANNEL_LEVEL[CC_LEVEL]
                                                                 determines whether [QUEUE_NUMBER] selects an L2 SQ or a L3 SQ. */
        uint64_t reserved_8            : 1;
        uint64_t pq_idx                : 5;  /**< [ 13:  9](R/W) When [VALID] is set, [PQ_IDX] must select the L1 SQ that services the L2/L3 SQ that
                                                                 is selected by [QUEUE_NUMBER]. */
        uint64_t reserved_14           : 1;
        uint64_t valid                 : 1;  /**< [ 15: 15](R/W) Declares if the index in the LUT is valid. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_lutx_s cn; */
} bdk_pko_lutx_t;

static inline uint64_t BDK_PKO_LUTX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_LUTX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=63) || ((a>=512)&&(a<=575)) || ((a>=1024)&&(a<=1151)) || ((a>=2048)&&(a<=2111)) || ((a>=2304)&&(a<=2367)) || ((a>=2560)&&(a<=2623)) || ((a>=2816)&&(a<=2879))))
        return 0x854000b00000ll + 8ll * ((a) & 0xfff);
    __bdk_csr_fatal("PKO_LUTX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_LUTX(a) bdk_pko_lutx_t
#define bustype_BDK_PKO_LUTX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_LUTX(a) "PKO_LUTX"
#define device_bar_BDK_PKO_LUTX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_LUTX(a) (a)
#define arguments_BDK_PKO_LUTX(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_lut_bist_status
 *
 * PKO LUT BIST Status Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_lut_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t bist_status           : 1;  /**< [  0:  0](RO) C2Q LUT BIST status. */
#else /* Word 0 - Little Endian */
        uint64_t bist_status           : 1;  /**< [  0:  0](RO) C2Q LUT BIST status. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_lut_bist_status_s cn; */
} bdk_pko_lut_bist_status_t;

#define BDK_PKO_LUT_BIST_STATUS BDK_PKO_LUT_BIST_STATUS_FUNC()
static inline uint64_t BDK_PKO_LUT_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_LUT_BIST_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000b08000ll;
    __bdk_csr_fatal("PKO_LUT_BIST_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_LUT_BIST_STATUS bdk_pko_lut_bist_status_t
#define bustype_BDK_PKO_LUT_BIST_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_LUT_BIST_STATUS "PKO_LUT_BIST_STATUS"
#define device_bar_BDK_PKO_LUT_BIST_STATUS 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_LUT_BIST_STATUS 0
#define arguments_BDK_PKO_LUT_BIST_STATUS -1,-1,-1,-1

/**
 * Register (NCB) pko_lut_ecc_ctl0
 *
 * PKO LUT RAM ECC Control Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_lut_ecc_ctl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t c2q_lut_ram_flip      : 2;  /**< [ 63: 62](R/W) C2Q_LUT_RAM flip syndrome bits on write. */
        uint64_t c2q_lut_ram_cdis      : 1;  /**< [ 61: 61](R/W) C2Q_LUT_RAM ECC correction disable. */
        uint64_t reserved_0_60         : 61;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_60         : 61;
        uint64_t c2q_lut_ram_cdis      : 1;  /**< [ 61: 61](R/W) C2Q_LUT_RAM ECC correction disable. */
        uint64_t c2q_lut_ram_flip      : 2;  /**< [ 63: 62](R/W) C2Q_LUT_RAM flip syndrome bits on write. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_lut_ecc_ctl0_s cn; */
} bdk_pko_lut_ecc_ctl0_t;

#define BDK_PKO_LUT_ECC_CTL0 BDK_PKO_LUT_ECC_CTL0_FUNC()
static inline uint64_t BDK_PKO_LUT_ECC_CTL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_LUT_ECC_CTL0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000bfffd0ll;
    __bdk_csr_fatal("PKO_LUT_ECC_CTL0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_LUT_ECC_CTL0 bdk_pko_lut_ecc_ctl0_t
#define bustype_BDK_PKO_LUT_ECC_CTL0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_LUT_ECC_CTL0 "PKO_LUT_ECC_CTL0"
#define device_bar_BDK_PKO_LUT_ECC_CTL0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_LUT_ECC_CTL0 0
#define arguments_BDK_PKO_LUT_ECC_CTL0 -1,-1,-1,-1

/**
 * Register (NCB) pko_mac#_cfg
 *
 * PKO MAC Configuration Register
 * These registers create the links between the MACs and the TxFIFO used to store the data,
 * and hold the per-MAC configuration bits.  These registers must be disabled (FIFO_NUM set
 * to 31) prior to reconfiguration of any of the other bits.
 *
 * <pre>
 *   CSR Name        Associated MAC
 *   ---------------------------------
 *   PKO_MAC0_CFG   LBK0 loopback
 *   PKO_MAC1_CFG   LBK1 loopback
 *   PKO_MAC2_CFG   DPI packet output
 *   PKO_MAC3_CFG   BGX0 logical MAC 0
 *   PKO_MAC4_CFG   BGX0 logical MAC 1
 *   PKO_MAC5_CFG   BGX0 logical MAC 2
 *   PKO_MAC6_CFG   BGX0 logical MAC 3
 *   PKO_MAC7_CFG   BGX1 logical MAC 0
 *   PKO_MAC8_CFG   BGX1 logical MAC 1
 *   PKO_MAC9_CFG   BGX1 logical MAC 2
 *   PKO_MAC10_CFG  BGX1 logical MAC 3
 *   PKO_MAC11_CFG  BGX2 logical MAC 0
 *   PKO_MAC12_CFG  BGX2 logical MAC 1
 *   PKO_MAC13_CFG  BGX2 logical MAC 2
 *   PKO_MAC14_CFG  BGX2 logical MAC 3
 *   PKO_MAC15_CFG  BGX3 logical MAC 0
 *   PKO_MAC16_CFG  BGX3 logical MAC 1
 *   PKO_MAC17_CFG  BGX3 logical MAC 2
 *   PKO_MAC18_CFG  BGX3 logical MAC 3
 * </pre>
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_macx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t min_pad_ena           : 1;  /**< [ 16: 16](R/W) Minimum padding enable. When [MIN_PAD_ENA] is set, PKO pads packets going
                                                                 through the MAC/FIFO (with zeroes) to a minimum of PKO_PDM_CFG[PKO_PAD_MINLEN]
                                                                 bytes. PKO pads prior to optionally generating FCS (see [FCS_ENA]). */
        uint64_t fcs_ena               : 1;  /**< [ 15: 15](R/W) Enable outside FCS generation for this MAC/FIFO. This adds four bytes to the
                                                                 packet, and occurs after minimum padding, if any (see [MIN_PAD_ENA]).

                                                                 [FCS_ENA] may normally not be set for SDP/DPI packet and LBK loopback output packets. */
        uint64_t fcs_sop_off           : 8;  /**< [ 14:  7](R/W) FCS start of packet offset. For this MAC, the number of bytes in the front of each packet
                                                                 to exclude from FCS. */
        uint64_t skid_max_cnt          : 2;  /**< [  6:  5](R/W) Maximum number of SKID credits. 0x0 = 16; 0x1 = 32; 0x2 = 64. */
        uint64_t fifo_num              : 5;  /**< [  4:  0](R/W) The PEB TX FIFO number assigned to the given MAC. A value of 31 means unassigned. Unused
                                                                 MACs must have [FIFO_NUM] = 31. For each active MAC, a unique valid [FIFO_NUM] must
                                                                 be assigned. When all PKO_PTGF(0..4)_CFG[SIZE] are zero, legal [FIFO_NUM] values are
                                                                 0..19 and 31. [FIFO_NUM] can never select the NULL FIFO. At most one
                                                                 used MAC can be simultaneously assigned the same used [FIFO_NUM].
                                                                 [FIFO_NUM] values 20-30 are illegal and must not be used. */
#else /* Word 0 - Little Endian */
        uint64_t fifo_num              : 5;  /**< [  4:  0](R/W) The PEB TX FIFO number assigned to the given MAC. A value of 31 means unassigned. Unused
                                                                 MACs must have [FIFO_NUM] = 31. For each active MAC, a unique valid [FIFO_NUM] must
                                                                 be assigned. When all PKO_PTGF(0..4)_CFG[SIZE] are zero, legal [FIFO_NUM] values are
                                                                 0..19 and 31. [FIFO_NUM] can never select the NULL FIFO. At most one
                                                                 used MAC can be simultaneously assigned the same used [FIFO_NUM].
                                                                 [FIFO_NUM] values 20-30 are illegal and must not be used. */
        uint64_t skid_max_cnt          : 2;  /**< [  6:  5](R/W) Maximum number of SKID credits. 0x0 = 16; 0x1 = 32; 0x2 = 64. */
        uint64_t fcs_sop_off           : 8;  /**< [ 14:  7](R/W) FCS start of packet offset. For this MAC, the number of bytes in the front of each packet
                                                                 to exclude from FCS. */
        uint64_t fcs_ena               : 1;  /**< [ 15: 15](R/W) Enable outside FCS generation for this MAC/FIFO. This adds four bytes to the
                                                                 packet, and occurs after minimum padding, if any (see [MIN_PAD_ENA]).

                                                                 [FCS_ENA] may normally not be set for SDP/DPI packet and LBK loopback output packets. */
        uint64_t min_pad_ena           : 1;  /**< [ 16: 16](R/W) Minimum padding enable. When [MIN_PAD_ENA] is set, PKO pads packets going
                                                                 through the MAC/FIFO (with zeroes) to a minimum of PKO_PDM_CFG[PKO_PAD_MINLEN]
                                                                 bytes. PKO pads prior to optionally generating FCS (see [FCS_ENA]). */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_macx_cfg_s cn; */
} bdk_pko_macx_cfg_t;

static inline uint64_t BDK_PKO_MACX_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_MACX_CFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=18))
        return 0x854000900000ll + 8ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_MACX_CFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_MACX_CFG(a) bdk_pko_macx_cfg_t
#define bustype_BDK_PKO_MACX_CFG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_MACX_CFG(a) "PKO_MACX_CFG"
#define device_bar_BDK_PKO_MACX_CFG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_MACX_CFG(a) (a)
#define arguments_BDK_PKO_MACX_CFG(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_mci1_cred_cnt#
 *
 * PKO MCI1 Credit Count Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_mci1_cred_cntx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t cred_cnt              : 13; /**< [ 12:  0](RO/H) Credit count. */
#else /* Word 0 - Little Endian */
        uint64_t cred_cnt              : 13; /**< [ 12:  0](RO/H) Credit count. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_mci1_cred_cntx_s cn; */
} bdk_pko_mci1_cred_cntx_t;

static inline uint64_t BDK_PKO_MCI1_CRED_CNTX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_MCI1_CRED_CNTX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=18))
        return 0x854000a80100ll + 8ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_MCI1_CRED_CNTX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_MCI1_CRED_CNTX(a) bdk_pko_mci1_cred_cntx_t
#define bustype_BDK_PKO_MCI1_CRED_CNTX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_MCI1_CRED_CNTX(a) "PKO_MCI1_CRED_CNTX"
#define device_bar_BDK_PKO_MCI1_CRED_CNTX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_MCI1_CRED_CNTX(a) (a)
#define arguments_BDK_PKO_MCI1_CRED_CNTX(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_mci1_max_cred#
 *
 * PKO MCI1 Maximum Credit Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_mci1_max_credx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t max_cred_lim          : 12; /**< [ 11:  0](R/W) Max credit limit.  Should be set to (MAC_CREDIT) / 16, where MAC_CREDIT is
                                                                 the size of the MAC FIFO. */
#else /* Word 0 - Little Endian */
        uint64_t max_cred_lim          : 12; /**< [ 11:  0](R/W) Max credit limit.  Should be set to (MAC_CREDIT) / 16, where MAC_CREDIT is
                                                                 the size of the MAC FIFO. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_mci1_max_credx_s cn; */
} bdk_pko_mci1_max_credx_t;

static inline uint64_t BDK_PKO_MCI1_MAX_CREDX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_MCI1_MAX_CREDX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=18))
        return 0x854000a80000ll + 8ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_MCI1_MAX_CREDX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_MCI1_MAX_CREDX(a) bdk_pko_mci1_max_credx_t
#define bustype_BDK_PKO_MCI1_MAX_CREDX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_MCI1_MAX_CREDX(a) "PKO_MCI1_MAX_CREDX"
#define device_bar_BDK_PKO_MCI1_MAX_CREDX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_MCI1_MAX_CREDX(a) (a)
#define arguments_BDK_PKO_MCI1_MAX_CREDX(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_ncb_bist_status
 *
 * PKO NCB RAM BIST Status Register
 * Each bit is the BIST result of an individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_ncb_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbi_l2_out_ram_bist_status : 1;/**< [ 63: 63](RO) BIST status for NCBI_L2_OUT_RAM. */
        uint64_t ncbi_pp_out_ram_bist_status : 1;/**< [ 62: 62](RO) BIST status for NCBI_PP_OUT_RAM. */
        uint64_t ncbo_pdm_cmd_dat_ram_bist_status : 1;/**< [ 61: 61](RO) BIST status for NCBO_PDM_CMD_DAT_RAM. */
        uint64_t ncbi_l2_pdm_pref_ram_bist_status : 1;/**< [ 60: 60](RO) BIST status for NCBI_L2_PDM_PREF_RAM. */
        uint64_t ncbo_pp_fif_ram_bist_status : 1;/**< [ 59: 59](RO) BIST status for NCBO_PP_FIF_RAM. */
        uint64_t ncbo_skid_fif_ram_bist_status : 1;/**< [ 58: 58](RO) BIST status for NCBO_SKID_FIF_RAM. */
        uint64_t reserved_0_57         : 58;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_57         : 58;
        uint64_t ncbo_skid_fif_ram_bist_status : 1;/**< [ 58: 58](RO) BIST status for NCBO_SKID_FIF_RAM. */
        uint64_t ncbo_pp_fif_ram_bist_status : 1;/**< [ 59: 59](RO) BIST status for NCBO_PP_FIF_RAM. */
        uint64_t ncbi_l2_pdm_pref_ram_bist_status : 1;/**< [ 60: 60](RO) BIST status for NCBI_L2_PDM_PREF_RAM. */
        uint64_t ncbo_pdm_cmd_dat_ram_bist_status : 1;/**< [ 61: 61](RO) BIST status for NCBO_PDM_CMD_DAT_RAM. */
        uint64_t ncbi_pp_out_ram_bist_status : 1;/**< [ 62: 62](RO) BIST status for NCBI_PP_OUT_RAM. */
        uint64_t ncbi_l2_out_ram_bist_status : 1;/**< [ 63: 63](RO) BIST status for NCBI_L2_OUT_RAM. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_ncb_bist_status_s cn; */
} bdk_pko_ncb_bist_status_t;

#define BDK_PKO_NCB_BIST_STATUS BDK_PKO_NCB_BIST_STATUS_FUNC()
static inline uint64_t BDK_PKO_NCB_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_NCB_BIST_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000efff00ll;
    __bdk_csr_fatal("PKO_NCB_BIST_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_NCB_BIST_STATUS bdk_pko_ncb_bist_status_t
#define bustype_BDK_PKO_NCB_BIST_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_NCB_BIST_STATUS "PKO_NCB_BIST_STATUS"
#define device_bar_BDK_PKO_NCB_BIST_STATUS 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_NCB_BIST_STATUS 0
#define arguments_BDK_PKO_NCB_BIST_STATUS -1,-1,-1,-1

/**
 * Register (NCB) pko_ncb_ecc_ctl0
 *
 * PKO NCB RAM ECC Control Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_ncb_ecc_ctl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbi_l2_out_ram_flip  : 2;  /**< [ 63: 62](R/W) NCBI_L2_OUT_RAM flip syndrome bits on write. */
        uint64_t ncbi_l2_out_ram_cdis  : 1;  /**< [ 61: 61](R/W) NCBI_L2_OUT_RAM ECC correction disable. */
        uint64_t ncbi_pp_out_ram_flip  : 2;  /**< [ 60: 59](R/W) NCBI_PP_OUT_RAM flip syndrome bits on write. */
        uint64_t ncbi_pp_out_ram_cdis  : 1;  /**< [ 58: 58](R/W) NCBI_PP_OUT_RAM ECC correction disable. */
        uint64_t ncbo_pdm_cmd_dat_ram_flip : 2;/**< [ 57: 56](R/W) NCBO_PDM_CMD_DAT_RAM flip syndrome bits on write. */
        uint64_t ncbo_pdm_cmd_dat_ram_cdis : 1;/**< [ 55: 55](R/W) NCBO_PDM_CMD_DAT_RAM ECC correction disable. */
        uint64_t ncbi_l2_pdm_pref_ram_flip : 2;/**< [ 54: 53](R/W) NCBI_L2_PDM_PREF_RAM flip syndrome bits on write. */
        uint64_t ncbi_l2_pdm_pref_ram_cdis : 1;/**< [ 52: 52](R/W) NCBI_L2_PDM_PREF_RAM ECC correction disable. */
        uint64_t ncbo_pp_fif_ram_flip  : 2;  /**< [ 51: 50](R/W) NCBO_PP_FIF_RAM flip syndrome bits on write. */
        uint64_t ncbo_pp_fif_ram_cdis  : 1;  /**< [ 49: 49](R/W) NCBO_PP_FIF_RAM ECC correction disable. */
        uint64_t ncbo_skid_fif_ram_flip : 2; /**< [ 48: 47](R/W) NCBO_SKID_FIF_RAM flip syndrome bits on write. */
        uint64_t ncbo_skid_fif_ram_cdis : 1; /**< [ 46: 46](R/W) NCBO_SKID_FIF_RAM ECC correction disable. */
        uint64_t reserved_0_45         : 46;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_45         : 46;
        uint64_t ncbo_skid_fif_ram_cdis : 1; /**< [ 46: 46](R/W) NCBO_SKID_FIF_RAM ECC correction disable. */
        uint64_t ncbo_skid_fif_ram_flip : 2; /**< [ 48: 47](R/W) NCBO_SKID_FIF_RAM flip syndrome bits on write. */
        uint64_t ncbo_pp_fif_ram_cdis  : 1;  /**< [ 49: 49](R/W) NCBO_PP_FIF_RAM ECC correction disable. */
        uint64_t ncbo_pp_fif_ram_flip  : 2;  /**< [ 51: 50](R/W) NCBO_PP_FIF_RAM flip syndrome bits on write. */
        uint64_t ncbi_l2_pdm_pref_ram_cdis : 1;/**< [ 52: 52](R/W) NCBI_L2_PDM_PREF_RAM ECC correction disable. */
        uint64_t ncbi_l2_pdm_pref_ram_flip : 2;/**< [ 54: 53](R/W) NCBI_L2_PDM_PREF_RAM flip syndrome bits on write. */
        uint64_t ncbo_pdm_cmd_dat_ram_cdis : 1;/**< [ 55: 55](R/W) NCBO_PDM_CMD_DAT_RAM ECC correction disable. */
        uint64_t ncbo_pdm_cmd_dat_ram_flip : 2;/**< [ 57: 56](R/W) NCBO_PDM_CMD_DAT_RAM flip syndrome bits on write. */
        uint64_t ncbi_pp_out_ram_cdis  : 1;  /**< [ 58: 58](R/W) NCBI_PP_OUT_RAM ECC correction disable. */
        uint64_t ncbi_pp_out_ram_flip  : 2;  /**< [ 60: 59](R/W) NCBI_PP_OUT_RAM flip syndrome bits on write. */
        uint64_t ncbi_l2_out_ram_cdis  : 1;  /**< [ 61: 61](R/W) NCBI_L2_OUT_RAM ECC correction disable. */
        uint64_t ncbi_l2_out_ram_flip  : 2;  /**< [ 63: 62](R/W) NCBI_L2_OUT_RAM flip syndrome bits on write. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_ncb_ecc_ctl0_s cn; */
} bdk_pko_ncb_ecc_ctl0_t;

#define BDK_PKO_NCB_ECC_CTL0 BDK_PKO_NCB_ECC_CTL0_FUNC()
static inline uint64_t BDK_PKO_NCB_ECC_CTL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_NCB_ECC_CTL0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000efffd0ll;
    __bdk_csr_fatal("PKO_NCB_ECC_CTL0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_NCB_ECC_CTL0 bdk_pko_ncb_ecc_ctl0_t
#define bustype_BDK_PKO_NCB_ECC_CTL0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_NCB_ECC_CTL0 "PKO_NCB_ECC_CTL0"
#define device_bar_BDK_PKO_NCB_ECC_CTL0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_NCB_ECC_CTL0 0
#define arguments_BDK_PKO_NCB_ECC_CTL0 -1,-1,-1,-1

/**
 * Register (NCB) pko_ncb_int
 *
 * PKO NCB Interrupt Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_ncb_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t tso_segment_cnt       : 1;  /**< [  1:  1](R/W1C/H) Message segment size is too small to transmit entire packet within the
                                                                 maximum allowed number of segments in TCP segmentation offload. The
                                                                 packet will be transmitted in multiple TSO segments until the maximum
                                                                 number of segments is reached. At this point, the interrupt will be
                                                                 raised, transmission of the packet will cease, and other available
                                                                 packets will be transmitted. This interrupt shares the NCB_TX_ERROR_INFO
                                                                 and NCB_TX_ERROR_WORD registers with the NCB_TX_ERROR interrupt to
                                                                 record information about the erroneous send packet command. Hence,
                                                                 NCB_TX_ERROR_INFO and NCB_TX_ERROR interrupts are onehot; neither
                                                                 will be set until both are cleared. The TSO engine makes no guarantees
                                                                 about the state of memory and pointers allocated for the packet if
                                                                 this interrupt is raised. */
        uint64_t ncb_tx_error          : 1;  /**< [  0:  0](R/W1C/H) NCB transaction error occurred (error/unpredictable/undefined). */
#else /* Word 0 - Little Endian */
        uint64_t ncb_tx_error          : 1;  /**< [  0:  0](R/W1C/H) NCB transaction error occurred (error/unpredictable/undefined). */
        uint64_t tso_segment_cnt       : 1;  /**< [  1:  1](R/W1C/H) Message segment size is too small to transmit entire packet within the
                                                                 maximum allowed number of segments in TCP segmentation offload. The
                                                                 packet will be transmitted in multiple TSO segments until the maximum
                                                                 number of segments is reached. At this point, the interrupt will be
                                                                 raised, transmission of the packet will cease, and other available
                                                                 packets will be transmitted. This interrupt shares the NCB_TX_ERROR_INFO
                                                                 and NCB_TX_ERROR_WORD registers with the NCB_TX_ERROR interrupt to
                                                                 record information about the erroneous send packet command. Hence,
                                                                 NCB_TX_ERROR_INFO and NCB_TX_ERROR interrupts are onehot; neither
                                                                 will be set until both are cleared. The TSO engine makes no guarantees
                                                                 about the state of memory and pointers allocated for the packet if
                                                                 this interrupt is raised. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_ncb_int_s cn; */
} bdk_pko_ncb_int_t;

#define BDK_PKO_NCB_INT BDK_PKO_NCB_INT_FUNC()
static inline uint64_t BDK_PKO_NCB_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_NCB_INT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000e00010ll;
    __bdk_csr_fatal("PKO_NCB_INT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_NCB_INT bdk_pko_ncb_int_t
#define bustype_BDK_PKO_NCB_INT BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_NCB_INT "PKO_NCB_INT"
#define device_bar_BDK_PKO_NCB_INT 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_NCB_INT 0
#define arguments_BDK_PKO_NCB_INT -1,-1,-1,-1

/**
 * Register (NCB) pko_ncb_tx_err_info
 *
 * PKO NCB TX Error Information Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_ncb_tx_err_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t wcnt                  : 5;  /**< [ 31: 27](R/W1C/H) Word count. */
        uint64_t src                   : 12; /**< [ 26: 15](R/W1C/H) Source of the IOI outbound transaction. */
        uint64_t dst                   : 8;  /**< [ 14:  7](R/W1C/H) Destination of the IOI outbound transaction. */
        uint64_t tag                   : 4;  /**< [  6:  3](R/W1C/H) Tag of the IOI outbound transaction. */
        uint64_t eot                   : 1;  /**< [  2:  2](R/W1C/H) EOT bit of the NCBO transaction. */
        uint64_t sot                   : 1;  /**< [  1:  1](R/W1C/H) SOT bit of the NCBO transaction. */
        uint64_t valid                 : 1;  /**< [  0:  0](R/W1C/H) Valid bit for transaction (should always be 1 on capture). */
#else /* Word 0 - Little Endian */
        uint64_t valid                 : 1;  /**< [  0:  0](R/W1C/H) Valid bit for transaction (should always be 1 on capture). */
        uint64_t sot                   : 1;  /**< [  1:  1](R/W1C/H) SOT bit of the NCBO transaction. */
        uint64_t eot                   : 1;  /**< [  2:  2](R/W1C/H) EOT bit of the NCBO transaction. */
        uint64_t tag                   : 4;  /**< [  6:  3](R/W1C/H) Tag of the IOI outbound transaction. */
        uint64_t dst                   : 8;  /**< [ 14:  7](R/W1C/H) Destination of the IOI outbound transaction. */
        uint64_t src                   : 12; /**< [ 26: 15](R/W1C/H) Source of the IOI outbound transaction. */
        uint64_t wcnt                  : 5;  /**< [ 31: 27](R/W1C/H) Word count. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_ncb_tx_err_info_s cn; */
} bdk_pko_ncb_tx_err_info_t;

#define BDK_PKO_NCB_TX_ERR_INFO BDK_PKO_NCB_TX_ERR_INFO_FUNC()
static inline uint64_t BDK_PKO_NCB_TX_ERR_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_NCB_TX_ERR_INFO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000e00008ll;
    __bdk_csr_fatal("PKO_NCB_TX_ERR_INFO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_NCB_TX_ERR_INFO bdk_pko_ncb_tx_err_info_t
#define bustype_BDK_PKO_NCB_TX_ERR_INFO BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_NCB_TX_ERR_INFO "PKO_NCB_TX_ERR_INFO"
#define device_bar_BDK_PKO_NCB_TX_ERR_INFO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_NCB_TX_ERR_INFO 0
#define arguments_BDK_PKO_NCB_TX_ERR_INFO -1,-1,-1,-1

/**
 * Register (NCB) pko_ncb_tx_err_word
 *
 * PKO NCB TX Error Word Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_ncb_tx_err_word_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t err_word              : 64; /**< [ 63:  0](R/W1C/H) PKO NCB error word (first word of erroneous transaction).
                                                                 Note: this is only the 64-bit data word; the NCB info that goes with it is in
                                                                 PKO_NCB_TX_ERR_INFO. */
#else /* Word 0 - Little Endian */
        uint64_t err_word              : 64; /**< [ 63:  0](R/W1C/H) PKO NCB error word (first word of erroneous transaction).
                                                                 Note: this is only the 64-bit data word; the NCB info that goes with it is in
                                                                 PKO_NCB_TX_ERR_INFO. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_ncb_tx_err_word_s cn; */
} bdk_pko_ncb_tx_err_word_t;

#define BDK_PKO_NCB_TX_ERR_WORD BDK_PKO_NCB_TX_ERR_WORD_FUNC()
static inline uint64_t BDK_PKO_NCB_TX_ERR_WORD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_NCB_TX_ERR_WORD_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000e00000ll;
    __bdk_csr_fatal("PKO_NCB_TX_ERR_WORD", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_NCB_TX_ERR_WORD bdk_pko_ncb_tx_err_word_t
#define bustype_BDK_PKO_NCB_TX_ERR_WORD BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_NCB_TX_ERR_WORD "PKO_NCB_TX_ERR_WORD"
#define device_bar_BDK_PKO_NCB_TX_ERR_WORD 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_NCB_TX_ERR_WORD 0
#define arguments_BDK_PKO_NCB_TX_ERR_WORD -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_bist_status
 *
 * PKO PDM RAM ECC SBE Status Register 0
 * Each bit is the BIST result of an individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t flshb_cache_lo_ram_bist_status : 1;/**< [ 63: 63](RO) BIST status for FLSHB_CACHE_LO_RAM. */
        uint64_t flshb_cache_hi_ram_bist_status : 1;/**< [ 62: 62](RO) BIST status for FLSHB_CACHE_HI_RAM. */
        uint64_t isrm_ca_iinst_ram_bist_status : 1;/**< [ 61: 61](RO) BIST status for ISRM_CA_IINST_RAM. */
        uint64_t isrm_ca_cm_ram_bist_status : 1;/**< [ 60: 60](RO) BIST status for ISRM_CA_CM_RAM. */
        uint64_t isrm_st_ram2_bist_status : 1;/**< [ 59: 59](RO) BIST status for ISRM_ST_RAM2. */
        uint64_t isrm_st_ram1_bist_status : 1;/**< [ 58: 58](RO) BIST status for ISRM_ST_RAM1. */
        uint64_t isrm_st_ram0_bist_status : 1;/**< [ 57: 57](RO) BIST status for ISRM_ST_RAM0. */
        uint64_t isrd_st_ram3_bist_status : 1;/**< [ 56: 56](RO) BIST status for ISRD_ST_RAM3. */
        uint64_t isrd_st_ram2_bist_status : 1;/**< [ 55: 55](RO) BIST status for ISRD_ST_RAM2. */
        uint64_t isrd_st_ram1_bist_status : 1;/**< [ 54: 54](RO) BIST status for ISRD_ST_RAM1. */
        uint64_t isrd_st_ram0_bist_status : 1;/**< [ 53: 53](RO) BIST status for ISRD_ST_RAM0. */
        uint64_t drp_hi_ram_bist_status : 1; /**< [ 52: 52](RO) BIST status for DRP_HI_RAM. */
        uint64_t drp_lo_ram_bist_status : 1; /**< [ 51: 51](RO) BIST status for DRP_LO_RAM. */
        uint64_t dwp_hi_ram_bist_status : 1; /**< [ 50: 50](RO) BIST status for DWP_HI_RAM. */
        uint64_t dwp_lo_ram_bist_status : 1; /**< [ 49: 49](RO) BIST status for DWP_LO_RAM. */
        uint64_t mwp_hi_ram_bist_status : 1; /**< [ 48: 48](RO) BIST status for MWP_RAM_MEM2. */
        uint64_t mwp_lo_ram_bist_status : 1; /**< [ 47: 47](RO) BIST status for MWP_RAM_MEM0. */
        uint64_t fillb_m_rsp_ram_hi_bist_status : 1;/**< [ 46: 46](RO) BIST status for FILLB_M_RSP_RAM_HI. */
        uint64_t fillb_m_rsp_ram_lo_bist_status : 1;/**< [ 45: 45](RO) BIST status for FILLB_M_RSP_RAM_LO. */
        uint64_t fillb_d_rsp_ram_hi_bist_status : 1;/**< [ 44: 44](RO) BIST status for FILLB_D_RSP_RAM_HI. */
        uint64_t fillb_d_rsp_ram_lo_bist_status : 1;/**< [ 43: 43](RO) BIST status for FILLB_D_RSP_RAM_LO. */
        uint64_t fillb_d_rsp_dat_fifo_bist_status : 1;/**< [ 42: 42](RO) BIST status for FILLB_FLSHB_M_DAT_RAM. */
        uint64_t fillb_m_rsp_dat_fifo_bist_status : 1;/**< [ 41: 41](RO) BIST status for FILLB_M_DAT_FIFO. */
        uint64_t flshb_m_dat_ram_bist_status : 1;/**< [ 40: 40](RO) BIST status for FLSHB_M_DAT_RAM. */
        uint64_t flshb_d_dat_ram_bist_status : 1;/**< [ 39: 39](RO) BIST status for FLSHB_M_DAT_RAM. */
        uint64_t minpad_ram_bist_status : 1; /**< [ 38: 38](RO) BIST status for MINPAD_RAM. */
        uint64_t mwp_hi_spt_ram_bist_status : 1;/**< [ 37: 37](RO) BIST status for MWP_RAM_MEM3. */
        uint64_t mwp_lo_spt_ram_bist_status : 1;/**< [ 36: 36](RO) BIST status for MWP_RAM_MEM1. */
        uint64_t buf_wm_ram_bist_status : 1; /**< [ 35: 35](RO) BIST status for BUF_WM_RAM. */
        uint64_t reserved_0_34         : 35;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_34         : 35;
        uint64_t buf_wm_ram_bist_status : 1; /**< [ 35: 35](RO) BIST status for BUF_WM_RAM. */
        uint64_t mwp_lo_spt_ram_bist_status : 1;/**< [ 36: 36](RO) BIST status for MWP_RAM_MEM1. */
        uint64_t mwp_hi_spt_ram_bist_status : 1;/**< [ 37: 37](RO) BIST status for MWP_RAM_MEM3. */
        uint64_t minpad_ram_bist_status : 1; /**< [ 38: 38](RO) BIST status for MINPAD_RAM. */
        uint64_t flshb_d_dat_ram_bist_status : 1;/**< [ 39: 39](RO) BIST status for FLSHB_M_DAT_RAM. */
        uint64_t flshb_m_dat_ram_bist_status : 1;/**< [ 40: 40](RO) BIST status for FLSHB_M_DAT_RAM. */
        uint64_t fillb_m_rsp_dat_fifo_bist_status : 1;/**< [ 41: 41](RO) BIST status for FILLB_M_DAT_FIFO. */
        uint64_t fillb_d_rsp_dat_fifo_bist_status : 1;/**< [ 42: 42](RO) BIST status for FILLB_FLSHB_M_DAT_RAM. */
        uint64_t fillb_d_rsp_ram_lo_bist_status : 1;/**< [ 43: 43](RO) BIST status for FILLB_D_RSP_RAM_LO. */
        uint64_t fillb_d_rsp_ram_hi_bist_status : 1;/**< [ 44: 44](RO) BIST status for FILLB_D_RSP_RAM_HI. */
        uint64_t fillb_m_rsp_ram_lo_bist_status : 1;/**< [ 45: 45](RO) BIST status for FILLB_M_RSP_RAM_LO. */
        uint64_t fillb_m_rsp_ram_hi_bist_status : 1;/**< [ 46: 46](RO) BIST status for FILLB_M_RSP_RAM_HI. */
        uint64_t mwp_lo_ram_bist_status : 1; /**< [ 47: 47](RO) BIST status for MWP_RAM_MEM0. */
        uint64_t mwp_hi_ram_bist_status : 1; /**< [ 48: 48](RO) BIST status for MWP_RAM_MEM2. */
        uint64_t dwp_lo_ram_bist_status : 1; /**< [ 49: 49](RO) BIST status for DWP_LO_RAM. */
        uint64_t dwp_hi_ram_bist_status : 1; /**< [ 50: 50](RO) BIST status for DWP_HI_RAM. */
        uint64_t drp_lo_ram_bist_status : 1; /**< [ 51: 51](RO) BIST status for DRP_LO_RAM. */
        uint64_t drp_hi_ram_bist_status : 1; /**< [ 52: 52](RO) BIST status for DRP_HI_RAM. */
        uint64_t isrd_st_ram0_bist_status : 1;/**< [ 53: 53](RO) BIST status for ISRD_ST_RAM0. */
        uint64_t isrd_st_ram1_bist_status : 1;/**< [ 54: 54](RO) BIST status for ISRD_ST_RAM1. */
        uint64_t isrd_st_ram2_bist_status : 1;/**< [ 55: 55](RO) BIST status for ISRD_ST_RAM2. */
        uint64_t isrd_st_ram3_bist_status : 1;/**< [ 56: 56](RO) BIST status for ISRD_ST_RAM3. */
        uint64_t isrm_st_ram0_bist_status : 1;/**< [ 57: 57](RO) BIST status for ISRM_ST_RAM0. */
        uint64_t isrm_st_ram1_bist_status : 1;/**< [ 58: 58](RO) BIST status for ISRM_ST_RAM1. */
        uint64_t isrm_st_ram2_bist_status : 1;/**< [ 59: 59](RO) BIST status for ISRM_ST_RAM2. */
        uint64_t isrm_ca_cm_ram_bist_status : 1;/**< [ 60: 60](RO) BIST status for ISRM_CA_CM_RAM. */
        uint64_t isrm_ca_iinst_ram_bist_status : 1;/**< [ 61: 61](RO) BIST status for ISRM_CA_IINST_RAM. */
        uint64_t flshb_cache_hi_ram_bist_status : 1;/**< [ 62: 62](RO) BIST status for FLSHB_CACHE_HI_RAM. */
        uint64_t flshb_cache_lo_ram_bist_status : 1;/**< [ 63: 63](RO) BIST status for FLSHB_CACHE_LO_RAM. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_bist_status_s cn; */
} bdk_pko_pdm_bist_status_t;

#define BDK_PKO_PDM_BIST_STATUS BDK_PKO_PDM_BIST_STATUS_FUNC()
static inline uint64_t BDK_PKO_PDM_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_BIST_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540008fff00ll;
    __bdk_csr_fatal("PKO_PDM_BIST_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_BIST_STATUS bdk_pko_pdm_bist_status_t
#define bustype_BDK_PKO_PDM_BIST_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_BIST_STATUS "PKO_PDM_BIST_STATUS"
#define device_bar_BDK_PKO_PDM_BIST_STATUS 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_BIST_STATUS 0
#define arguments_BDK_PKO_PDM_BIST_STATUS -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_cfg
 *
 * PKO PDM Configuration Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_26_63        : 38;
        uint64_t dq_fc_skid            : 10; /**< [ 25: 16](R/W) DQ flow control skid. Constant unsigned value that is subtracted from
                                                                 all DQ buffer flow control counts PKO_VF()_DQ()_FC_STATUS[COUNT] prior
                                                                 to thier being stored into L2/DRAM for flow control purposes. */
        uint64_t reserved_14_15        : 2;
        uint64_t dq_fc_sa              : 1;  /**< [ 13: 13](R/W) DQ flow control store allocate. Specifies whether or not
                                                                 DQ flow control stores to NCB are allocated into on-chip cache when
                                                                 PKO_VF()_DQ_FC_CONFIG[STRIDE] is asserted.
                                                                 0 = Allocate (STF).
                                                                 1 = No allocate (STT).

                                                                 See PKO_VF()_DQ_FC_CONFIG[STRIDE] for more details. */
        uint64_t dis_lpd_w2r_fill      : 1;  /**< [ 12: 12](R/W) Set to disable the write to read fill caused by LPD in the PDM. If disabled, must wait for
                                                                 FPD bit from PEB, which is a performance penalty when the time is large for the PEB
                                                                 request to make it back to PDM. For diagnostic use only. */
        uint64_t en_fr_w2r_ptr_swp     : 1;  /**< [ 11: 11](R/W) Set to enable pointer swap on a fill response when we go in-sync (only one cacheline in
                                                                 DQ). For diagnostic use only. */
        uint64_t dis_flsh_cache        : 1;  /**< [ 10: 10](R/W) Set to disable the flush buffer's cache. This makes all fills require full memory latency.
                                                                 For diagnostic use only. */
        uint64_t pko_pad_minlen        : 7;  /**< [  9:  3](R/W) Minimum frame padding min length. Padding is enabled by PKO_MAC()_CFG[MIN_PAD_ENA]. See
                                                                 also PKO_PDM_DQ*_MINPAD[MINPAD].

                                                                 The typical value of 0x3C ensures the pre-FCS packet is at least 60 bytes when
                                                                 PKO_MAC()_CFG[MIN_PAD_ENA]=1. After FCS addition (via PKO_MAC()_CFG[FCS_ENA]=1
                                                                 or via an interface), the packet will be at least 64 bytes when [PKO_PAD_MINLEN]=0x3C
                                                                 and PKO_MAC()_CFG[MIN_PAD_ENA]=1. */
        uint64_t diag_mode             : 1;  /**< [  2:  2](R/W) Set to enable read/write to memories in PDM through CSR interface. For diagnostic use only. */
        uint64_t alloc_lds             : 1;  /**< [  1:  1](R/W) Allocate LDS. This signal prevents the loads to NCB from being allocated in on-chip cache
                                                                 (LDWB vs. LDD). Two modes as follows: 0 = No allocate (LDWB); 1 = Allocate (LDD).
                                                                 PKO PDM refetches DQ metas and descriptors via NCB loads. */
        uint64_t alloc_sts             : 1;  /**< [  0:  0](R/W) Allocate STS. This signal prevents the stores to NCB from being allocated in on-chip cache
                                                                 (STF vs. STT). Two modes as follows: 0 = No allocate (STT); 1 = Allocate (STF).
                                                                 PKO PDM stores DQ meta and descriptor overflow data via NCB. */
#else /* Word 0 - Little Endian */
        uint64_t alloc_sts             : 1;  /**< [  0:  0](R/W) Allocate STS. This signal prevents the stores to NCB from being allocated in on-chip cache
                                                                 (STF vs. STT). Two modes as follows: 0 = No allocate (STT); 1 = Allocate (STF).
                                                                 PKO PDM stores DQ meta and descriptor overflow data via NCB. */
        uint64_t alloc_lds             : 1;  /**< [  1:  1](R/W) Allocate LDS. This signal prevents the loads to NCB from being allocated in on-chip cache
                                                                 (LDWB vs. LDD). Two modes as follows: 0 = No allocate (LDWB); 1 = Allocate (LDD).
                                                                 PKO PDM refetches DQ metas and descriptors via NCB loads. */
        uint64_t diag_mode             : 1;  /**< [  2:  2](R/W) Set to enable read/write to memories in PDM through CSR interface. For diagnostic use only. */
        uint64_t pko_pad_minlen        : 7;  /**< [  9:  3](R/W) Minimum frame padding min length. Padding is enabled by PKO_MAC()_CFG[MIN_PAD_ENA]. See
                                                                 also PKO_PDM_DQ*_MINPAD[MINPAD].

                                                                 The typical value of 0x3C ensures the pre-FCS packet is at least 60 bytes when
                                                                 PKO_MAC()_CFG[MIN_PAD_ENA]=1. After FCS addition (via PKO_MAC()_CFG[FCS_ENA]=1
                                                                 or via an interface), the packet will be at least 64 bytes when [PKO_PAD_MINLEN]=0x3C
                                                                 and PKO_MAC()_CFG[MIN_PAD_ENA]=1. */
        uint64_t dis_flsh_cache        : 1;  /**< [ 10: 10](R/W) Set to disable the flush buffer's cache. This makes all fills require full memory latency.
                                                                 For diagnostic use only. */
        uint64_t en_fr_w2r_ptr_swp     : 1;  /**< [ 11: 11](R/W) Set to enable pointer swap on a fill response when we go in-sync (only one cacheline in
                                                                 DQ). For diagnostic use only. */
        uint64_t dis_lpd_w2r_fill      : 1;  /**< [ 12: 12](R/W) Set to disable the write to read fill caused by LPD in the PDM. If disabled, must wait for
                                                                 FPD bit from PEB, which is a performance penalty when the time is large for the PEB
                                                                 request to make it back to PDM. For diagnostic use only. */
        uint64_t dq_fc_sa              : 1;  /**< [ 13: 13](R/W) DQ flow control store allocate. Specifies whether or not
                                                                 DQ flow control stores to NCB are allocated into on-chip cache when
                                                                 PKO_VF()_DQ_FC_CONFIG[STRIDE] is asserted.
                                                                 0 = Allocate (STF).
                                                                 1 = No allocate (STT).

                                                                 See PKO_VF()_DQ_FC_CONFIG[STRIDE] for more details. */
        uint64_t reserved_14_15        : 2;
        uint64_t dq_fc_skid            : 10; /**< [ 25: 16](R/W) DQ flow control skid. Constant unsigned value that is subtracted from
                                                                 all DQ buffer flow control counts PKO_VF()_DQ()_FC_STATUS[COUNT] prior
                                                                 to thier being stored into L2/DRAM for flow control purposes. */
        uint64_t reserved_26_63        : 38;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_cfg_s cn; */
} bdk_pko_pdm_cfg_t;

#define BDK_PKO_PDM_CFG BDK_PKO_PDM_CFG_FUNC()
static inline uint64_t BDK_PKO_PDM_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000800000ll;
    __bdk_csr_fatal("PKO_PDM_CFG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_CFG bdk_pko_pdm_cfg_t
#define bustype_BDK_PKO_PDM_CFG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_CFG "PKO_PDM_CFG"
#define device_bar_BDK_PKO_PDM_CFG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_CFG 0
#define arguments_BDK_PKO_PDM_CFG -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_cfg_dbg
 *
 * INTERNAL: PKO PDM Configuration Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_cfg_dbg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t cp_stall_thrshld      : 32; /**< [ 31:  0](R/W) Program this register to the 32-bit number of cycles to test for the PDM(CP)
                                                                 stalled on inputs going into the ISRs. PKO_PDM_STS[CP_STALLED_THRSHLD_HIT]
                                                                 indicates the threshold has been hit.  For diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint64_t cp_stall_thrshld      : 32; /**< [ 31:  0](R/W) Program this register to the 32-bit number of cycles to test for the PDM(CP)
                                                                 stalled on inputs going into the ISRs. PKO_PDM_STS[CP_STALLED_THRSHLD_HIT]
                                                                 indicates the threshold has been hit.  For diagnostic use only. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_cfg_dbg_s cn; */
} bdk_pko_pdm_cfg_dbg_t;

#define BDK_PKO_PDM_CFG_DBG BDK_PKO_PDM_CFG_DBG_FUNC()
static inline uint64_t BDK_PKO_PDM_CFG_DBG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_CFG_DBG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000800ff8ll;
    __bdk_csr_fatal("PKO_PDM_CFG_DBG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_CFG_DBG bdk_pko_pdm_cfg_dbg_t
#define bustype_BDK_PKO_PDM_CFG_DBG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_CFG_DBG "PKO_PDM_CFG_DBG"
#define device_bar_BDK_PKO_PDM_CFG_DBG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_CFG_DBG 0
#define arguments_BDK_PKO_PDM_CFG_DBG -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_cp_dbg
 *
 * INTERNAL: PKO PDM CP Internal Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_cp_dbg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t stateless_fif_cnt     : 6;  /**< [ 15: 10](RO/H) Stateless FIFO count. */
        uint64_t reserved_5_9          : 5;
        uint64_t op_fif_not_full       : 5;  /**< [  4:  0](RO/H) Output fifo not full signals. The order of the bits is:
                                                                 0x4 = ISR CMD FIFO not full.
                                                                 0x3 = DESC DAT FIFO HIGH not full.
                                                                 0x2 = DESC DAT FIFO LOW not full.
                                                                 0x1 = MP DAT FIFO not full.
                                                                 0x0 = PSE CMD RESP FIFO has credit. */
#else /* Word 0 - Little Endian */
        uint64_t op_fif_not_full       : 5;  /**< [  4:  0](RO/H) Output fifo not full signals. The order of the bits is:
                                                                 0x4 = ISR CMD FIFO not full.
                                                                 0x3 = DESC DAT FIFO HIGH not full.
                                                                 0x2 = DESC DAT FIFO LOW not full.
                                                                 0x1 = MP DAT FIFO not full.
                                                                 0x0 = PSE CMD RESP FIFO has credit. */
        uint64_t reserved_5_9          : 5;
        uint64_t stateless_fif_cnt     : 6;  /**< [ 15: 10](RO/H) Stateless FIFO count. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_cp_dbg_s cn; */
} bdk_pko_pdm_cp_dbg_t;

#define BDK_PKO_PDM_CP_DBG BDK_PKO_PDM_CP_DBG_FUNC()
static inline uint64_t BDK_PKO_PDM_CP_DBG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_CP_DBG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000800190ll;
    __bdk_csr_fatal("PKO_PDM_CP_DBG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_CP_DBG bdk_pko_pdm_cp_dbg_t
#define bustype_BDK_PKO_PDM_CP_DBG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_CP_DBG "PKO_PDM_CP_DBG"
#define device_bar_BDK_PKO_PDM_CP_DBG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_CP_DBG 0
#define arguments_BDK_PKO_PDM_CP_DBG -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_dq#_minpad
 *
 * PKO PDM Descriptor Queue Minimum Pad Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_dqx_minpad_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t minpad                : 1;  /**< [  0:  0](R/W) MINPAD setting per DQ. Each DQ has a separate CSR address; and bit 0 of the data
                                                                 read/write value is [MINPAD]. [MINPAD] adjusts the meta length field based on
                                                                 the min packet length as follows:

                                                                     Meta[LENGTH] = [MINPAD] ?
                                                                                       MAX(X, PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                                       X

                                                                 where X is the packet/segment length before pad. PKO_META_DESC_S[LENGTH]
                                                                 and PKO_*_PICK[LENGTH] are Meta[LENGTH].

                                                                 In most cases, [MINPAD] should equal the corresponding PKO_MAC()_CFG[MIN_PAD_ENA].
                                                                 But when logic outside PKO pads the packet, it may be appropriate to set [MINPAD]
                                                                 when the corresponding PKO_MAC()_CFG[MIN_PAD_ENA]=0.

                                                                 [MINPAD] doesn't affect whether PKO applies pad to the packet or not,
                                                                 PKO_MAC()_CFG[MIN_PAD_ENA] does. When PKO_MAC()_CFG[MIN_PAD_ENA] is set,
                                                                 PKO pads packets through the MAC to PKO_PDM_CFG[PKO_PAD_MINLEN] bytes. */
#else /* Word 0 - Little Endian */
        uint64_t minpad                : 1;  /**< [  0:  0](R/W) MINPAD setting per DQ. Each DQ has a separate CSR address; and bit 0 of the data
                                                                 read/write value is [MINPAD]. [MINPAD] adjusts the meta length field based on
                                                                 the min packet length as follows:

                                                                     Meta[LENGTH] = [MINPAD] ?
                                                                                       MAX(X, PKO_PDM_CFG[PKO_PAD_MINLEN]) :
                                                                                       X

                                                                 where X is the packet/segment length before pad. PKO_META_DESC_S[LENGTH]
                                                                 and PKO_*_PICK[LENGTH] are Meta[LENGTH].

                                                                 In most cases, [MINPAD] should equal the corresponding PKO_MAC()_CFG[MIN_PAD_ENA].
                                                                 But when logic outside PKO pads the packet, it may be appropriate to set [MINPAD]
                                                                 when the corresponding PKO_MAC()_CFG[MIN_PAD_ENA]=0.

                                                                 [MINPAD] doesn't affect whether PKO applies pad to the packet or not,
                                                                 PKO_MAC()_CFG[MIN_PAD_ENA] does. When PKO_MAC()_CFG[MIN_PAD_ENA] is set,
                                                                 PKO pads packets through the MAC to PKO_PDM_CFG[PKO_PAD_MINLEN] bytes. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_dqx_minpad_s cn; */
} bdk_pko_pdm_dqx_minpad_t;

static inline uint64_t BDK_PKO_PDM_DQX_MINPAD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_DQX_MINPAD(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=255))
        return 0x8540008f0000ll + 8ll * ((a) & 0xff);
    __bdk_csr_fatal("PKO_PDM_DQX_MINPAD", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_DQX_MINPAD(a) bdk_pko_pdm_dqx_minpad_t
#define bustype_BDK_PKO_PDM_DQX_MINPAD(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_DQX_MINPAD(a) "PKO_PDM_DQX_MINPAD"
#define device_bar_BDK_PKO_PDM_DQX_MINPAD(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_DQX_MINPAD(a) (a)
#define arguments_BDK_PKO_PDM_DQX_MINPAD(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_pdm_drpbuf_dbg
 *
 * INTERNAL: PKO PDM DRPBUF Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_drpbuf_dbg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_43_63        : 21;
        uint64_t sel_nxt_ptr           : 1;  /**< [ 42: 42](RO/H) Sel_nxt_ptr signal. */
        uint64_t load_val              : 1;  /**< [ 41: 41](RO/H) Load valid signal. */
        uint64_t rdy                   : 1;  /**< [ 40: 40](RO/H) Ready signal. */
        uint64_t cur_state             : 3;  /**< [ 39: 37](RO/H) Current state from the pbuf controller. */
        uint64_t reserved_33_36        : 4;
        uint64_t track_rd_cnt          : 6;  /**< [ 32: 27](RO/H) Track read count value. */
        uint64_t track_wr_cnt          : 6;  /**< [ 26: 21](RO/H) Track write count value. */
        uint64_t reserved_17_20        : 4;
        uint64_t mem_addr              : 13; /**< [ 16:  4](RO/H) Memory address for pbuf ram. */
        uint64_t mem_en                : 4;  /**< [  3:  0](RO/H) Memory write/chip enable signals. The order of the bits is:
                                                                 0x3 = Low wen.
                                                                 0x2 = Low cen.
                                                                 0x1 = High wen.
                                                                 0x0 = High cen. */
#else /* Word 0 - Little Endian */
        uint64_t mem_en                : 4;  /**< [  3:  0](RO/H) Memory write/chip enable signals. The order of the bits is:
                                                                 0x3 = Low wen.
                                                                 0x2 = Low cen.
                                                                 0x1 = High wen.
                                                                 0x0 = High cen. */
        uint64_t mem_addr              : 13; /**< [ 16:  4](RO/H) Memory address for pbuf ram. */
        uint64_t reserved_17_20        : 4;
        uint64_t track_wr_cnt          : 6;  /**< [ 26: 21](RO/H) Track write count value. */
        uint64_t track_rd_cnt          : 6;  /**< [ 32: 27](RO/H) Track read count value. */
        uint64_t reserved_33_36        : 4;
        uint64_t cur_state             : 3;  /**< [ 39: 37](RO/H) Current state from the pbuf controller. */
        uint64_t rdy                   : 1;  /**< [ 40: 40](RO/H) Ready signal. */
        uint64_t load_val              : 1;  /**< [ 41: 41](RO/H) Load valid signal. */
        uint64_t sel_nxt_ptr           : 1;  /**< [ 42: 42](RO/H) Sel_nxt_ptr signal. */
        uint64_t reserved_43_63        : 21;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_drpbuf_dbg_s cn; */
} bdk_pko_pdm_drpbuf_dbg_t;

#define BDK_PKO_PDM_DRPBUF_DBG BDK_PKO_PDM_DRPBUF_DBG_FUNC()
static inline uint64_t BDK_PKO_PDM_DRPBUF_DBG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_DRPBUF_DBG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540008000b0ll;
    __bdk_csr_fatal("PKO_PDM_DRPBUF_DBG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_DRPBUF_DBG bdk_pko_pdm_drpbuf_dbg_t
#define bustype_BDK_PKO_PDM_DRPBUF_DBG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_DRPBUF_DBG "PKO_PDM_DRPBUF_DBG"
#define device_bar_BDK_PKO_PDM_DRPBUF_DBG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_DRPBUF_DBG 0
#define arguments_BDK_PKO_PDM_DRPBUF_DBG -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_dwpbuf_dbg
 *
 * INTERNAL: PKO PDM DWPBUF Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_dwpbuf_dbg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cmd_proc              : 1;  /**< [ 47: 47](RO/H) Command process signal. */
        uint64_t reserved_46           : 1;
        uint64_t mem_data_val          : 1;  /**< [ 45: 45](RO/H) Memory data valid. */
        uint64_t insert_np             : 1;  /**< [ 44: 44](RO/H) Next pointer insertion signal. */
        uint64_t reserved_43           : 1;
        uint64_t sel_nxt_ptr           : 1;  /**< [ 42: 42](RO/H) Sel_nxt_ptr signal. */
        uint64_t load_val              : 1;  /**< [ 41: 41](RO/H) Load valid signal. */
        uint64_t rdy                   : 1;  /**< [ 40: 40](RO/H) Ready signal. */
        uint64_t reserved_37_39        : 3;
        uint64_t mem_rdy               : 1;  /**< [ 36: 36](RO/H) Memory stage ready signal. */
        uint64_t reserved_19_35        : 17;
        uint64_t insert_dp             : 2;  /**< [ 18: 17](RO/H) Descriptor insertion signals. */
        uint64_t reserved_15_16        : 2;
        uint64_t mem_addr              : 11; /**< [ 14:  4](RO/H) Memory address for pbuf ram. */
        uint64_t mem_en                : 4;  /**< [  3:  0](RO/H) Memory write/chip enable signals. The order of the bits is:
                                                                 0x3 = Low wen.
                                                                 0x2 = Low cen.
                                                                 0x1 = High wen.
                                                                 0x0 = High cen. */
#else /* Word 0 - Little Endian */
        uint64_t mem_en                : 4;  /**< [  3:  0](RO/H) Memory write/chip enable signals. The order of the bits is:
                                                                 0x3 = Low wen.
                                                                 0x2 = Low cen.
                                                                 0x1 = High wen.
                                                                 0x0 = High cen. */
        uint64_t mem_addr              : 11; /**< [ 14:  4](RO/H) Memory address for pbuf ram. */
        uint64_t reserved_15_16        : 2;
        uint64_t insert_dp             : 2;  /**< [ 18: 17](RO/H) Descriptor insertion signals. */
        uint64_t reserved_19_35        : 17;
        uint64_t mem_rdy               : 1;  /**< [ 36: 36](RO/H) Memory stage ready signal. */
        uint64_t reserved_37_39        : 3;
        uint64_t rdy                   : 1;  /**< [ 40: 40](RO/H) Ready signal. */
        uint64_t load_val              : 1;  /**< [ 41: 41](RO/H) Load valid signal. */
        uint64_t sel_nxt_ptr           : 1;  /**< [ 42: 42](RO/H) Sel_nxt_ptr signal. */
        uint64_t reserved_43           : 1;
        uint64_t insert_np             : 1;  /**< [ 44: 44](RO/H) Next pointer insertion signal. */
        uint64_t mem_data_val          : 1;  /**< [ 45: 45](RO/H) Memory data valid. */
        uint64_t reserved_46           : 1;
        uint64_t cmd_proc              : 1;  /**< [ 47: 47](RO/H) Command process signal. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_dwpbuf_dbg_s cn; */
} bdk_pko_pdm_dwpbuf_dbg_t;

#define BDK_PKO_PDM_DWPBUF_DBG BDK_PKO_PDM_DWPBUF_DBG_FUNC()
static inline uint64_t BDK_PKO_PDM_DWPBUF_DBG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_DWPBUF_DBG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540008000a8ll;
    __bdk_csr_fatal("PKO_PDM_DWPBUF_DBG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_DWPBUF_DBG bdk_pko_pdm_dwpbuf_dbg_t
#define bustype_BDK_PKO_PDM_DWPBUF_DBG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_DWPBUF_DBG "PKO_PDM_DWPBUF_DBG"
#define device_bar_BDK_PKO_PDM_DWPBUF_DBG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_DWPBUF_DBG 0
#define arguments_BDK_PKO_PDM_DWPBUF_DBG -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_ecc_ctl0
 *
 * PKO PDM RAM ECC Control Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_ecc_ctl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t flshb_cache_lo_ram_flip : 2;/**< [ 63: 62](R/W) FLSHB_CACHE_LO_RAM flip syndrome bits on write. */
        uint64_t flshb_cache_lo_ram_cdis : 1;/**< [ 61: 61](R/W) FLSHB_CACHE_LO_RAM ECC correction disable. */
        uint64_t flshb_cache_hi_ram_flip : 2;/**< [ 60: 59](R/W) FLSHB_CACHE_HI_RAM flip syndrome bits on write. */
        uint64_t flshb_cache_hi_ram_cdis : 1;/**< [ 58: 58](R/W) FLSHB_CACHE_HI_RAM ECC correction disable. */
        uint64_t isrm_ca_iinst_ram_flip : 2; /**< [ 57: 56](R/W) ISRM_CA_IINST_RAM flip syndrome bits on write. */
        uint64_t isrm_ca_iinst_ram_cdis : 1; /**< [ 55: 55](R/W) ISRM_CA_IINST_RAM ECC correction disable. */
        uint64_t isrm_ca_cm_ram_flip   : 2;  /**< [ 54: 53](R/W) ISRM_CA_CM_RAM flip syndrome bits on write. */
        uint64_t isrm_ca_cm_ram_cdis   : 1;  /**< [ 52: 52](R/W) ISRM_CA_CM_RAM ECC correction disable. */
        uint64_t isrm_st_ram2_flip     : 2;  /**< [ 51: 50](R/W) ISRM_ST_RAM2 flip syndrome bits on write. */
        uint64_t isrm_st_ram2_cdis     : 1;  /**< [ 49: 49](R/W) ISRM_ST_RAM2 ECC correction disable. */
        uint64_t isrm_st_ram1_flip     : 2;  /**< [ 48: 47](R/W) ISRM_ST_RAM1 flip syndrome bits on write. */
        uint64_t isrm_st_ram1_cdis     : 1;  /**< [ 46: 46](R/W) ISRM_ST_RAM1 ECC correction disable. */
        uint64_t isrm_st_ram0_flip     : 2;  /**< [ 45: 44](R/W) ISRM_ST_RAM0 flip syndrome bits on write. */
        uint64_t isrm_st_ram0_cdis     : 1;  /**< [ 43: 43](R/W) ISRM_ST_RAM0 ECC correction disable. */
        uint64_t isrd_st_ram3_flip     : 2;  /**< [ 42: 41](R/W) ISRD_ST_RAM3 flip syndrome bits on write. */
        uint64_t isrd_st_ram3_cdis     : 1;  /**< [ 40: 40](R/W) ISRD_ST_RAM3 ECC correction disable. */
        uint64_t isrd_st_ram2_flip     : 2;  /**< [ 39: 38](R/W) ISRD_ST_RAM2 flip syndrome bits on write. */
        uint64_t isrd_st_ram2_cdis     : 1;  /**< [ 37: 37](R/W) ISRD_ST_RAM2 ECC correction disable. */
        uint64_t isrd_st_ram1_flip     : 2;  /**< [ 36: 35](R/W) ISRD_ST_RAM1 flip syndrome bits on write. */
        uint64_t isrd_st_ram1_cdis     : 1;  /**< [ 34: 34](R/W) ISRD_ST_RAM1 ECC correction disable. */
        uint64_t isrd_st_ram0_flip     : 2;  /**< [ 33: 32](R/W) ISRD_ST_RAM0 flip syndrome bits on write. */
        uint64_t isrd_st_ram0_cdis     : 1;  /**< [ 31: 31](R/W) ISRD_ST_RAM0 ECC correction disable. */
        uint64_t drp_hi_ram_flip       : 2;  /**< [ 30: 29](R/W) DRP_HI_RAM flip syndrome bits on write. */
        uint64_t drp_hi_ram_cdis       : 1;  /**< [ 28: 28](R/W) DRP_HI_RAM ECC correction disable. */
        uint64_t drp_lo_ram_flip       : 2;  /**< [ 27: 26](R/W) DRP_LO_RAM flip syndrome bits on write. */
        uint64_t drp_lo_ram_cdis       : 1;  /**< [ 25: 25](R/W) DRP_LO_RAM ECC correction disable. */
        uint64_t dwp_hi_ram_flip       : 2;  /**< [ 24: 23](R/W) DWP_HI_RAM flip syndrome bits on write. */
        uint64_t dwp_hi_ram_cdis       : 1;  /**< [ 22: 22](R/W) DWP_HI_RAM ECC correction disable. */
        uint64_t dwp_lo_ram_flip       : 2;  /**< [ 21: 20](R/W) DWP_LO_RAM flip syndrome bits on write. */
        uint64_t dwp_lo_ram_cdis       : 1;  /**< [ 19: 19](R/W) DWP_LO_RAM ECC correction disable. */
        uint64_t reserved_13_18        : 6;
        uint64_t fillb_m_rsp_ram_hi_flip : 2;/**< [ 12: 11](R/W) FILLB_M_RSP_RAM_HI flip syndrome bits on write. */
        uint64_t fillb_m_rsp_ram_hi_cdis : 1;/**< [ 10: 10](R/W) FILLB_M_RSP_RAM_HI ECC correction disable. */
        uint64_t fillb_m_rsp_ram_lo_flip : 2;/**< [  9:  8](R/W) FILLB_M_RSP_RAM_LO flip syndrome bits on write. */
        uint64_t fillb_m_rsp_ram_lo_cdis : 1;/**< [  7:  7](R/W) FILLB_M_RSP_RAM_LO ECC correction disable. */
        uint64_t fillb_d_rsp_ram_hi_flip : 2;/**< [  6:  5](R/W) FILLB_D_RSP_RAM_LO flip syndrome bits on write. */
        uint64_t fillb_d_rsp_ram_hi_cdis : 1;/**< [  4:  4](R/W) FILLB_D_RSP_RAM_HI ECC correction disable. */
        uint64_t fillb_d_rsp_ram_lo_flip : 2;/**< [  3:  2](R/W) FILLB_D_DAT_RAM_LO flip syndrome bits on write. */
        uint64_t fillb_d_rsp_ram_lo_cdis : 1;/**< [  1:  1](R/W) FILLB_D_RSP_RAM_LO ECC correction disable. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t fillb_d_rsp_ram_lo_cdis : 1;/**< [  1:  1](R/W) FILLB_D_RSP_RAM_LO ECC correction disable. */
        uint64_t fillb_d_rsp_ram_lo_flip : 2;/**< [  3:  2](R/W) FILLB_D_DAT_RAM_LO flip syndrome bits on write. */
        uint64_t fillb_d_rsp_ram_hi_cdis : 1;/**< [  4:  4](R/W) FILLB_D_RSP_RAM_HI ECC correction disable. */
        uint64_t fillb_d_rsp_ram_hi_flip : 2;/**< [  6:  5](R/W) FILLB_D_RSP_RAM_LO flip syndrome bits on write. */
        uint64_t fillb_m_rsp_ram_lo_cdis : 1;/**< [  7:  7](R/W) FILLB_M_RSP_RAM_LO ECC correction disable. */
        uint64_t fillb_m_rsp_ram_lo_flip : 2;/**< [  9:  8](R/W) FILLB_M_RSP_RAM_LO flip syndrome bits on write. */
        uint64_t fillb_m_rsp_ram_hi_cdis : 1;/**< [ 10: 10](R/W) FILLB_M_RSP_RAM_HI ECC correction disable. */
        uint64_t fillb_m_rsp_ram_hi_flip : 2;/**< [ 12: 11](R/W) FILLB_M_RSP_RAM_HI flip syndrome bits on write. */
        uint64_t reserved_13_18        : 6;
        uint64_t dwp_lo_ram_cdis       : 1;  /**< [ 19: 19](R/W) DWP_LO_RAM ECC correction disable. */
        uint64_t dwp_lo_ram_flip       : 2;  /**< [ 21: 20](R/W) DWP_LO_RAM flip syndrome bits on write. */
        uint64_t dwp_hi_ram_cdis       : 1;  /**< [ 22: 22](R/W) DWP_HI_RAM ECC correction disable. */
        uint64_t dwp_hi_ram_flip       : 2;  /**< [ 24: 23](R/W) DWP_HI_RAM flip syndrome bits on write. */
        uint64_t drp_lo_ram_cdis       : 1;  /**< [ 25: 25](R/W) DRP_LO_RAM ECC correction disable. */
        uint64_t drp_lo_ram_flip       : 2;  /**< [ 27: 26](R/W) DRP_LO_RAM flip syndrome bits on write. */
        uint64_t drp_hi_ram_cdis       : 1;  /**< [ 28: 28](R/W) DRP_HI_RAM ECC correction disable. */
        uint64_t drp_hi_ram_flip       : 2;  /**< [ 30: 29](R/W) DRP_HI_RAM flip syndrome bits on write. */
        uint64_t isrd_st_ram0_cdis     : 1;  /**< [ 31: 31](R/W) ISRD_ST_RAM0 ECC correction disable. */
        uint64_t isrd_st_ram0_flip     : 2;  /**< [ 33: 32](R/W) ISRD_ST_RAM0 flip syndrome bits on write. */
        uint64_t isrd_st_ram1_cdis     : 1;  /**< [ 34: 34](R/W) ISRD_ST_RAM1 ECC correction disable. */
        uint64_t isrd_st_ram1_flip     : 2;  /**< [ 36: 35](R/W) ISRD_ST_RAM1 flip syndrome bits on write. */
        uint64_t isrd_st_ram2_cdis     : 1;  /**< [ 37: 37](R/W) ISRD_ST_RAM2 ECC correction disable. */
        uint64_t isrd_st_ram2_flip     : 2;  /**< [ 39: 38](R/W) ISRD_ST_RAM2 flip syndrome bits on write. */
        uint64_t isrd_st_ram3_cdis     : 1;  /**< [ 40: 40](R/W) ISRD_ST_RAM3 ECC correction disable. */
        uint64_t isrd_st_ram3_flip     : 2;  /**< [ 42: 41](R/W) ISRD_ST_RAM3 flip syndrome bits on write. */
        uint64_t isrm_st_ram0_cdis     : 1;  /**< [ 43: 43](R/W) ISRM_ST_RAM0 ECC correction disable. */
        uint64_t isrm_st_ram0_flip     : 2;  /**< [ 45: 44](R/W) ISRM_ST_RAM0 flip syndrome bits on write. */
        uint64_t isrm_st_ram1_cdis     : 1;  /**< [ 46: 46](R/W) ISRM_ST_RAM1 ECC correction disable. */
        uint64_t isrm_st_ram1_flip     : 2;  /**< [ 48: 47](R/W) ISRM_ST_RAM1 flip syndrome bits on write. */
        uint64_t isrm_st_ram2_cdis     : 1;  /**< [ 49: 49](R/W) ISRM_ST_RAM2 ECC correction disable. */
        uint64_t isrm_st_ram2_flip     : 2;  /**< [ 51: 50](R/W) ISRM_ST_RAM2 flip syndrome bits on write. */
        uint64_t isrm_ca_cm_ram_cdis   : 1;  /**< [ 52: 52](R/W) ISRM_CA_CM_RAM ECC correction disable. */
        uint64_t isrm_ca_cm_ram_flip   : 2;  /**< [ 54: 53](R/W) ISRM_CA_CM_RAM flip syndrome bits on write. */
        uint64_t isrm_ca_iinst_ram_cdis : 1; /**< [ 55: 55](R/W) ISRM_CA_IINST_RAM ECC correction disable. */
        uint64_t isrm_ca_iinst_ram_flip : 2; /**< [ 57: 56](R/W) ISRM_CA_IINST_RAM flip syndrome bits on write. */
        uint64_t flshb_cache_hi_ram_cdis : 1;/**< [ 58: 58](R/W) FLSHB_CACHE_HI_RAM ECC correction disable. */
        uint64_t flshb_cache_hi_ram_flip : 2;/**< [ 60: 59](R/W) FLSHB_CACHE_HI_RAM flip syndrome bits on write. */
        uint64_t flshb_cache_lo_ram_cdis : 1;/**< [ 61: 61](R/W) FLSHB_CACHE_LO_RAM ECC correction disable. */
        uint64_t flshb_cache_lo_ram_flip : 2;/**< [ 63: 62](R/W) FLSHB_CACHE_LO_RAM flip syndrome bits on write. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_ecc_ctl0_s cn; */
} bdk_pko_pdm_ecc_ctl0_t;

#define BDK_PKO_PDM_ECC_CTL0 BDK_PKO_PDM_ECC_CTL0_FUNC()
static inline uint64_t BDK_PKO_PDM_ECC_CTL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_ECC_CTL0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540008fffd0ll;
    __bdk_csr_fatal("PKO_PDM_ECC_CTL0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_ECC_CTL0 bdk_pko_pdm_ecc_ctl0_t
#define bustype_BDK_PKO_PDM_ECC_CTL0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_ECC_CTL0 "PKO_PDM_ECC_CTL0"
#define device_bar_BDK_PKO_PDM_ECC_CTL0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_ECC_CTL0 0
#define arguments_BDK_PKO_PDM_ECC_CTL0 -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_ecc_ctl1
 *
 * PKO PDM RAM ECC Control Register 1
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_ecc_ctl1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_15_63        : 49;
        uint64_t buf_wm_ram_flip       : 2;  /**< [ 14: 13](R/W) BUF_WM_RAM flip syndrome bits on write. */
        uint64_t buf_wm_ram_cdis       : 1;  /**< [ 12: 12](R/W) BUF_WM_RAM ECC correction disable for all four memories. */
        uint64_t mwp_mem0_ram_flip     : 2;  /**< [ 11: 10](R/W) MWP_MEM0_RAM flip syndrome bits on write. */
        uint64_t mwp_mem1_ram_flip     : 2;  /**< [  9:  8](R/W) MWP_MEM1_RAM flip syndrome bits on write. */
        uint64_t mwp_mem2_ram_flip     : 2;  /**< [  7:  6](R/W) MWP_MEM2_RAM flip syndrome bits on write. */
        uint64_t mwp_mem3_ram_flip     : 2;  /**< [  5:  4](R/W) MWP_MEM3_RAM flip syndrome bits on write. */
        uint64_t mwp_ram_cdis          : 1;  /**< [  3:  3](R/W) MWP_RAM ECC correction disable for all four memories. */
        uint64_t minpad_ram_flip       : 2;  /**< [  2:  1](R/W) MINPAD_RAM flip syndrome bits on write. */
        uint64_t minpad_ram_cdis       : 1;  /**< [  0:  0](R/W) MINPAD_RAM ECC correction disable. */
#else /* Word 0 - Little Endian */
        uint64_t minpad_ram_cdis       : 1;  /**< [  0:  0](R/W) MINPAD_RAM ECC correction disable. */
        uint64_t minpad_ram_flip       : 2;  /**< [  2:  1](R/W) MINPAD_RAM flip syndrome bits on write. */
        uint64_t mwp_ram_cdis          : 1;  /**< [  3:  3](R/W) MWP_RAM ECC correction disable for all four memories. */
        uint64_t mwp_mem3_ram_flip     : 2;  /**< [  5:  4](R/W) MWP_MEM3_RAM flip syndrome bits on write. */
        uint64_t mwp_mem2_ram_flip     : 2;  /**< [  7:  6](R/W) MWP_MEM2_RAM flip syndrome bits on write. */
        uint64_t mwp_mem1_ram_flip     : 2;  /**< [  9:  8](R/W) MWP_MEM1_RAM flip syndrome bits on write. */
        uint64_t mwp_mem0_ram_flip     : 2;  /**< [ 11: 10](R/W) MWP_MEM0_RAM flip syndrome bits on write. */
        uint64_t buf_wm_ram_cdis       : 1;  /**< [ 12: 12](R/W) BUF_WM_RAM ECC correction disable for all four memories. */
        uint64_t buf_wm_ram_flip       : 2;  /**< [ 14: 13](R/W) BUF_WM_RAM flip syndrome bits on write. */
        uint64_t reserved_15_63        : 49;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_ecc_ctl1_s cn; */
} bdk_pko_pdm_ecc_ctl1_t;

#define BDK_PKO_PDM_ECC_CTL1 BDK_PKO_PDM_ECC_CTL1_FUNC()
static inline uint64_t BDK_PKO_PDM_ECC_CTL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_ECC_CTL1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540008fffd8ll;
    __bdk_csr_fatal("PKO_PDM_ECC_CTL1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_ECC_CTL1 bdk_pko_pdm_ecc_ctl1_t
#define bustype_BDK_PKO_PDM_ECC_CTL1 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_ECC_CTL1 "PKO_PDM_ECC_CTL1"
#define device_bar_BDK_PKO_PDM_ECC_CTL1 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_ECC_CTL1 0
#define arguments_BDK_PKO_PDM_ECC_CTL1 -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_fillb_dbg0
 *
 * INTERNAL: PKO PDM Fill Buffer Debug Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_fillb_dbg0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_57_63        : 7;
        uint64_t pd_seq                : 5;  /**< [ 56: 52](RO/H) Sequence number for next packet descriptor fill request. */
        uint64_t resp_pd_seq           : 5;  /**< [ 51: 47](RO/H) Sequence number for next response to be written into packet descriptor buffer RAM. */
        uint64_t d_rsp_lo_ram_addr_sel : 2;  /**< [ 46: 45](RO/H) Source of read/write address to low PD fill buffer RAM.
                                                                 0x0 = No access.
                                                                 0x1 = Read access sourced by PD fill buffer response FIFO (feeding DRPBUF).
                                                                 0x2 = Write access sourced by IOBP0.
                                                                 0x3 = Write access sourced by flush buffer. */
        uint64_t d_rsp_hi_ram_addr_sel : 2;  /**< [ 44: 43](RO/H) Source of read/write address to high PD fill buffer RAM.
                                                                 0x0 = No access.
                                                                 0x1 = Read access sourced by PD fill buffer response FIFO (feeding DRPBUF).
                                                                 0x2 = Write access sourced by IOBP0.
                                                                 0x3 = Write access sourced by flush buffer. */
        uint64_t d_rsp_rd_seq          : 5;  /**< [ 42: 38](RO/H) Sequence number for next response to be read from packet descriptor buffer RAM. */
        uint64_t d_rsp_fifo_rd_seq     : 5;  /**< [ 37: 33](RO/H) Sequence number for next PD fill response to be sent to DRPBUF. */
        uint64_t d_fill_req_fifo_val   : 1;  /**< [ 32: 32](RO/H) Fill buffer PD read request FIFO has a valid entry. */
        uint64_t d_rsp_ram_valid       : 32; /**< [ 31:  0](RO/H) Fill buffer packet descriptor RAM valid flags. */
#else /* Word 0 - Little Endian */
        uint64_t d_rsp_ram_valid       : 32; /**< [ 31:  0](RO/H) Fill buffer packet descriptor RAM valid flags. */
        uint64_t d_fill_req_fifo_val   : 1;  /**< [ 32: 32](RO/H) Fill buffer PD read request FIFO has a valid entry. */
        uint64_t d_rsp_fifo_rd_seq     : 5;  /**< [ 37: 33](RO/H) Sequence number for next PD fill response to be sent to DRPBUF. */
        uint64_t d_rsp_rd_seq          : 5;  /**< [ 42: 38](RO/H) Sequence number for next response to be read from packet descriptor buffer RAM. */
        uint64_t d_rsp_hi_ram_addr_sel : 2;  /**< [ 44: 43](RO/H) Source of read/write address to high PD fill buffer RAM.
                                                                 0x0 = No access.
                                                                 0x1 = Read access sourced by PD fill buffer response FIFO (feeding DRPBUF).
                                                                 0x2 = Write access sourced by IOBP0.
                                                                 0x3 = Write access sourced by flush buffer. */
        uint64_t d_rsp_lo_ram_addr_sel : 2;  /**< [ 46: 45](RO/H) Source of read/write address to low PD fill buffer RAM.
                                                                 0x0 = No access.
                                                                 0x1 = Read access sourced by PD fill buffer response FIFO (feeding DRPBUF).
                                                                 0x2 = Write access sourced by IOBP0.
                                                                 0x3 = Write access sourced by flush buffer. */
        uint64_t resp_pd_seq           : 5;  /**< [ 51: 47](RO/H) Sequence number for next response to be written into packet descriptor buffer RAM. */
        uint64_t pd_seq                : 5;  /**< [ 56: 52](RO/H) Sequence number for next packet descriptor fill request. */
        uint64_t reserved_57_63        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_fillb_dbg0_s cn; */
} bdk_pko_pdm_fillb_dbg0_t;

#define BDK_PKO_PDM_FILLB_DBG0 BDK_PKO_PDM_FILLB_DBG0_FUNC()
static inline uint64_t BDK_PKO_PDM_FILLB_DBG0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_FILLB_DBG0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540008002a0ll;
    __bdk_csr_fatal("PKO_PDM_FILLB_DBG0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_FILLB_DBG0 bdk_pko_pdm_fillb_dbg0_t
#define bustype_BDK_PKO_PDM_FILLB_DBG0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_FILLB_DBG0 "PKO_PDM_FILLB_DBG0"
#define device_bar_BDK_PKO_PDM_FILLB_DBG0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_FILLB_DBG0 0
#define arguments_BDK_PKO_PDM_FILLB_DBG0 -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_fillb_dbg1
 *
 * INTERNAL: PKO PDM Fill Buffer Debug Register 1
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_fillb_dbg1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_57_63        : 7;
        uint64_t mp_seq                : 5;  /**< [ 56: 52](RO/H) Sequence number for next meta packet cache line fill request. */
        uint64_t resp_mp_seq           : 5;  /**< [ 51: 47](RO/H) Sequence number for next response to be written into meta packet buffer RAM. */
        uint64_t m_rsp_lo_ram_addr_sel : 2;  /**< [ 46: 45](RO/H) Source of read/write address to low MP fill buffer RAM.
                                                                 0x0 = No access.
                                                                 0x1 = Read access sourced by MP fill buffer response FIFO (feeding DRPBUF).
                                                                 0x2 = Write access sourced by IOBP0.
                                                                 0x3 = Write access sourced by flush buffer. */
        uint64_t m_rsp_hi_ram_addr_sel : 2;  /**< [ 44: 43](RO/H) Source of read/write address to high MP fill buffer RAM.
                                                                 0x0 = No access.
                                                                 0x1 = Read access sourced by MP fill buffer response FIFO (feeding DRPBUF).
                                                                 0x2 = Write access sourced by IOBP0.
                                                                 0x3 = Write access sourced by flush buffer. */
        uint64_t m_rsp_rd_seq          : 5;  /**< [ 42: 38](RO/H) Sequence number for next response to be read from meta packet buffer RAM. */
        uint64_t m_rsp_fifo_rd_seq     : 5;  /**< [ 37: 33](RO/H) Sequence number for next MP fill response to be sent to DRPBUF. */
        uint64_t m_fill_req_fifo_val   : 1;  /**< [ 32: 32](RO/H) Fill buffer MP read request FIFO has a valid entry. */
        uint64_t m_rsp_ram_valid       : 32; /**< [ 31:  0](RO/H) Fill buffer meta packet RAM valid flags. */
#else /* Word 0 - Little Endian */
        uint64_t m_rsp_ram_valid       : 32; /**< [ 31:  0](RO/H) Fill buffer meta packet RAM valid flags. */
        uint64_t m_fill_req_fifo_val   : 1;  /**< [ 32: 32](RO/H) Fill buffer MP read request FIFO has a valid entry. */
        uint64_t m_rsp_fifo_rd_seq     : 5;  /**< [ 37: 33](RO/H) Sequence number for next MP fill response to be sent to DRPBUF. */
        uint64_t m_rsp_rd_seq          : 5;  /**< [ 42: 38](RO/H) Sequence number for next response to be read from meta packet buffer RAM. */
        uint64_t m_rsp_hi_ram_addr_sel : 2;  /**< [ 44: 43](RO/H) Source of read/write address to high MP fill buffer RAM.
                                                                 0x0 = No access.
                                                                 0x1 = Read access sourced by MP fill buffer response FIFO (feeding DRPBUF).
                                                                 0x2 = Write access sourced by IOBP0.
                                                                 0x3 = Write access sourced by flush buffer. */
        uint64_t m_rsp_lo_ram_addr_sel : 2;  /**< [ 46: 45](RO/H) Source of read/write address to low MP fill buffer RAM.
                                                                 0x0 = No access.
                                                                 0x1 = Read access sourced by MP fill buffer response FIFO (feeding DRPBUF).
                                                                 0x2 = Write access sourced by IOBP0.
                                                                 0x3 = Write access sourced by flush buffer. */
        uint64_t resp_mp_seq           : 5;  /**< [ 51: 47](RO/H) Sequence number for next response to be written into meta packet buffer RAM. */
        uint64_t mp_seq                : 5;  /**< [ 56: 52](RO/H) Sequence number for next meta packet cache line fill request. */
        uint64_t reserved_57_63        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_fillb_dbg1_s cn; */
} bdk_pko_pdm_fillb_dbg1_t;

#define BDK_PKO_PDM_FILLB_DBG1 BDK_PKO_PDM_FILLB_DBG1_FUNC()
static inline uint64_t BDK_PKO_PDM_FILLB_DBG1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_FILLB_DBG1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540008002a8ll;
    __bdk_csr_fatal("PKO_PDM_FILLB_DBG1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_FILLB_DBG1 bdk_pko_pdm_fillb_dbg1_t
#define bustype_BDK_PKO_PDM_FILLB_DBG1 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_FILLB_DBG1 "PKO_PDM_FILLB_DBG1"
#define device_bar_BDK_PKO_PDM_FILLB_DBG1 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_FILLB_DBG1 0
#define arguments_BDK_PKO_PDM_FILLB_DBG1 -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_fillb_dbg2
 *
 * INTERNAL: PKO PDM Fill Buffer Debug Register 2
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_fillb_dbg2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t fillb_sm              : 5;  /**< [  8:  4](RO/H) Fill buffer state machine state. */
        uint64_t reserved_3            : 1;
        uint64_t iobp0_credit_cntr     : 3;  /**< [  2:  0](RO/H) IOBP0 read request credit counter. */
#else /* Word 0 - Little Endian */
        uint64_t iobp0_credit_cntr     : 3;  /**< [  2:  0](RO/H) IOBP0 read request credit counter. */
        uint64_t reserved_3            : 1;
        uint64_t fillb_sm              : 5;  /**< [  8:  4](RO/H) Fill buffer state machine state. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_fillb_dbg2_s cn; */
} bdk_pko_pdm_fillb_dbg2_t;

#define BDK_PKO_PDM_FILLB_DBG2 BDK_PKO_PDM_FILLB_DBG2_FUNC()
static inline uint64_t BDK_PKO_PDM_FILLB_DBG2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_FILLB_DBG2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540008002b0ll;
    __bdk_csr_fatal("PKO_PDM_FILLB_DBG2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_FILLB_DBG2 bdk_pko_pdm_fillb_dbg2_t
#define bustype_BDK_PKO_PDM_FILLB_DBG2 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_FILLB_DBG2 "PKO_PDM_FILLB_DBG2"
#define device_bar_BDK_PKO_PDM_FILLB_DBG2 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_FILLB_DBG2 0
#define arguments_BDK_PKO_PDM_FILLB_DBG2 -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_flshb_dbg0
 *
 * INTERNAL: PKO PDM Flush Buffer Debug Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_flshb_dbg0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t flshb_sm              : 7;  /**< [ 43: 37](RO/H) Flush buffer state machine state. */
        uint64_t flshb_ctl_sm          : 9;  /**< [ 36: 28](RO/H) Flush buffer control state machine. */
        uint64_t cam_hptr              : 5;  /**< [ 27: 23](RO/H) Flush buffer CAM head pointer. */
        uint64_t cam_tptr              : 5;  /**< [ 22: 18](RO/H) Flush buffer CAM tail pointer. */
        uint64_t expected_stdns        : 6;  /**< [ 17: 12](RO/H) Number of store done responses still pending. */
        uint64_t d_flshb_eot_cntr      : 3;  /**< [ 11:  9](RO/H) Number of packet descriptor flush requests pending. */
        uint64_t m_flshb_eot_cntr      : 3;  /**< [  8:  6](RO/H) Number of meta packet flush requests pending. */
        uint64_t ncbi_credit_cntr      : 6;  /**< [  5:  0](RO/H) NCBI FIFO credit counter. */
#else /* Word 0 - Little Endian */
        uint64_t ncbi_credit_cntr      : 6;  /**< [  5:  0](RO/H) NCBI FIFO credit counter. */
        uint64_t m_flshb_eot_cntr      : 3;  /**< [  8:  6](RO/H) Number of meta packet flush requests pending. */
        uint64_t d_flshb_eot_cntr      : 3;  /**< [ 11:  9](RO/H) Number of packet descriptor flush requests pending. */
        uint64_t expected_stdns        : 6;  /**< [ 17: 12](RO/H) Number of store done responses still pending. */
        uint64_t cam_tptr              : 5;  /**< [ 22: 18](RO/H) Flush buffer CAM tail pointer. */
        uint64_t cam_hptr              : 5;  /**< [ 27: 23](RO/H) Flush buffer CAM head pointer. */
        uint64_t flshb_ctl_sm          : 9;  /**< [ 36: 28](RO/H) Flush buffer control state machine. */
        uint64_t flshb_sm              : 7;  /**< [ 43: 37](RO/H) Flush buffer state machine state. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_flshb_dbg0_s cn; */
} bdk_pko_pdm_flshb_dbg0_t;

#define BDK_PKO_PDM_FLSHB_DBG0 BDK_PKO_PDM_FLSHB_DBG0_FUNC()
static inline uint64_t BDK_PKO_PDM_FLSHB_DBG0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_FLSHB_DBG0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540008002b8ll;
    __bdk_csr_fatal("PKO_PDM_FLSHB_DBG0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_FLSHB_DBG0 bdk_pko_pdm_flshb_dbg0_t
#define bustype_BDK_PKO_PDM_FLSHB_DBG0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_FLSHB_DBG0 "PKO_PDM_FLSHB_DBG0"
#define device_bar_BDK_PKO_PDM_FLSHB_DBG0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_FLSHB_DBG0 0
#define arguments_BDK_PKO_PDM_FLSHB_DBG0 -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_flshb_dbg1
 *
 * INTERNAL: PKO PDM Flush Buffer Debug Register 1
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_flshb_dbg1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cam_stdn              : 32; /**< [ 63: 32](RO/H) Flush buffer entry store done request flags. */
        uint64_t cam_valid             : 32; /**< [ 31:  0](RO/H) Flush buffer entry valid flags. */
#else /* Word 0 - Little Endian */
        uint64_t cam_valid             : 32; /**< [ 31:  0](RO/H) Flush buffer entry valid flags. */
        uint64_t cam_stdn              : 32; /**< [ 63: 32](RO/H) Flush buffer entry store done request flags. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_flshb_dbg1_s cn; */
} bdk_pko_pdm_flshb_dbg1_t;

#define BDK_PKO_PDM_FLSHB_DBG1 BDK_PKO_PDM_FLSHB_DBG1_FUNC()
static inline uint64_t BDK_PKO_PDM_FLSHB_DBG1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_FLSHB_DBG1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540008002c0ll;
    __bdk_csr_fatal("PKO_PDM_FLSHB_DBG1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_FLSHB_DBG1 bdk_pko_pdm_flshb_dbg1_t
#define bustype_BDK_PKO_PDM_FLSHB_DBG1 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_FLSHB_DBG1 "PKO_PDM_FLSHB_DBG1"
#define device_bar_BDK_PKO_PDM_FLSHB_DBG1 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_FLSHB_DBG1 0
#define arguments_BDK_PKO_PDM_FLSHB_DBG1 -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_intf_dbg_rd
 *
 * INTERNAL: PKO Module Debug Read Register
 *
 * For diagnostic use only.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_intf_dbg_rd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t in_flight             : 8;  /**< [ 47: 40](RO/H) Number of packets in-flight to PDM. */
        uint64_t pdm_req_cred_cnt      : 8;  /**< [ 39: 32](RO/H) PDM req/ack credit counter. */
        uint64_t pse_buf_waddr         : 8;  /**< [ 31: 24](RO/H) PSE buffer write address. */
        uint64_t pse_buf_raddr         : 8;  /**< [ 23: 16](RO/H) PSE buffer read address. */
        uint64_t resp_buf_waddr        : 8;  /**< [ 15:  8](RO/H) Interface buffer write address. */
        uint64_t resp_buf_raddr        : 8;  /**< [  7:  0](RO/H) Interface buffer read address. */
#else /* Word 0 - Little Endian */
        uint64_t resp_buf_raddr        : 8;  /**< [  7:  0](RO/H) Interface buffer read address. */
        uint64_t resp_buf_waddr        : 8;  /**< [ 15:  8](RO/H) Interface buffer write address. */
        uint64_t pse_buf_raddr         : 8;  /**< [ 23: 16](RO/H) PSE buffer read address. */
        uint64_t pse_buf_waddr         : 8;  /**< [ 31: 24](RO/H) PSE buffer write address. */
        uint64_t pdm_req_cred_cnt      : 8;  /**< [ 39: 32](RO/H) PDM req/ack credit counter. */
        uint64_t in_flight             : 8;  /**< [ 47: 40](RO/H) Number of packets in-flight to PDM. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_intf_dbg_rd_s cn; */
} bdk_pko_pdm_intf_dbg_rd_t;

#define BDK_PKO_PDM_INTF_DBG_RD BDK_PKO_PDM_INTF_DBG_RD_FUNC()
static inline uint64_t BDK_PKO_PDM_INTF_DBG_RD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_INTF_DBG_RD_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900f20ll;
    __bdk_csr_fatal("PKO_PDM_INTF_DBG_RD", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_INTF_DBG_RD bdk_pko_pdm_intf_dbg_rd_t
#define bustype_BDK_PKO_PDM_INTF_DBG_RD BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_INTF_DBG_RD "PKO_PDM_INTF_DBG_RD"
#define device_bar_BDK_PKO_PDM_INTF_DBG_RD 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_INTF_DBG_RD 0
#define arguments_BDK_PKO_PDM_INTF_DBG_RD -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_isrd_dbg
 *
 * INTERNAL: PKO PDM ISRD Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_isrd_dbg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t isrd_vals_in          : 4;  /**< [ 63: 60](RO/H) Valid signals for ISRD input stage. Bits and descriptions:
                                                                   <63> = prof__isrdex_peb_fill_req_val.
                                                                   <62> = prof__isrdex_rd_req_val.
                                                                   <61> = cp__isr_cval.
                                                                   <60> = fillb__isrd_d_dval. */
        uint64_t reserved_59           : 1;
        uint64_t req_hptr              : 6;  /**< [ 58: 53](RO/H) Input arbitration request signals. */
        uint64_t rdy_hptr              : 6;  /**< [ 52: 47](RO/H) Input arbitration request signals. */
        uint64_t reserved_44_46        : 3;
        uint64_t in_arb_reqs           : 8;  /**< [ 43: 36](RO/H) Input arbitration request signals. The order of the bits is:
                                                                 0x2B = Fill response - normal path request.
                                                                 0x2A = Fill response - flushb path request.
                                                                 0x29 = CP queue-open request.
                                                                 0x28 = CP queue-closed request.
                                                                 0x27 = CP queue-query request.
                                                                 0x26 = CP send-packet request.
                                                                 0x25 = PEB fill request.
                                                                 0x24 = PEB read request. */
        uint64_t in_arb_gnts           : 7;  /**< [ 35: 29](RO/H) Input arbitration grant signals. The order of the bits is:
                                                                 0x23 = Fill response grant.
                                                                 0x22 = CP - queue-open grant.
                                                                 0x21 = CP - queue-close grant.
                                                                 0x20 = CP - queue-query grant.
                                                                 0x1F = CP - send-packet grant.
                                                                 0x1E = PEB fill grant.
                                                                 0x1D = PEB read grant. */
        uint64_t cmt_arb_reqs          : 7;  /**< [ 28: 22](RO/H) Commit arbitration request signals. The order of the bits is:
                                                                 0x1C = Fill response grant.
                                                                 0x1B = CP - queue-open grant.
                                                                 0x1A = CP - queue-close grant.
                                                                 0x19 = CP - queue-query grant.
                                                                 0x18 = CP - send-packet grant.
                                                                 0x17 = PEB fill grant.
                                                                 0x16 = PEB read grant. */
        uint64_t cmt_arb_gnts          : 7;  /**< [ 21: 15](RO/H) Commit arbitration grant signals. The order of the bits is:
                                                                 0x15 = Fill response grant.
                                                                 0x14 = CP - queue-open grant.
                                                                 0x13 = CP - queue-close grant.
                                                                 0x12 = CP - queue-query grant.
                                                                 0x11 = CP - send-packet grant.
                                                                 0x10 = PEB fill grant.
                                                                 0xF = PEB read grant. */
        uint64_t in_use                : 4;  /**< [ 14: 11](RO/H) In use signals indicate the execution units are in use. The order of the bits is:
                                                                 0xE = PEB fill unit.
                                                                 0xD = PEB read unit.
                                                                 0xC = CP unit.
                                                                 0xB = Fill response unit. */
        uint64_t has_cred              : 4;  /**< [ 10:  7](RO/H) Has credit signals indicate there is sufficient credit to commit. The order of the bits
                                                                 is:
                                                                 0xA = Flush buffer has credit.
                                                                 0x9 = Fill buffer has credit.
                                                                 0x8 = DW command output FIFO has credit.
                                                                 0x7 = DR command output FIFO has credit. */
        uint64_t val_exec              : 7;  /**< [  6:  0](RO/H) Valid bits for the execution units; means the unit can commit if it gets the grant of the
                                                                 commit arb and other conditions are met. The order of the bits is:
                                                                 0x6 = Fill response unit.
                                                                 0x5 = CP unit - queue-open.
                                                                 0x4 = CP unit - queue-close.
                                                                 0x3 = CP unit - queue-probe.
                                                                 0x2 = CP unit - send-packet.
                                                                 0x1 = PEB fill unit.
                                                                 0x0 = PEB read unit. */
#else /* Word 0 - Little Endian */
        uint64_t val_exec              : 7;  /**< [  6:  0](RO/H) Valid bits for the execution units; means the unit can commit if it gets the grant of the
                                                                 commit arb and other conditions are met. The order of the bits is:
                                                                 0x6 = Fill response unit.
                                                                 0x5 = CP unit - queue-open.
                                                                 0x4 = CP unit - queue-close.
                                                                 0x3 = CP unit - queue-probe.
                                                                 0x2 = CP unit - send-packet.
                                                                 0x1 = PEB fill unit.
                                                                 0x0 = PEB read unit. */
        uint64_t has_cred              : 4;  /**< [ 10:  7](RO/H) Has credit signals indicate there is sufficient credit to commit. The order of the bits
                                                                 is:
                                                                 0xA = Flush buffer has credit.
                                                                 0x9 = Fill buffer has credit.
                                                                 0x8 = DW command output FIFO has credit.
                                                                 0x7 = DR command output FIFO has credit. */
        uint64_t in_use                : 4;  /**< [ 14: 11](RO/H) In use signals indicate the execution units are in use. The order of the bits is:
                                                                 0xE = PEB fill unit.
                                                                 0xD = PEB read unit.
                                                                 0xC = CP unit.
                                                                 0xB = Fill response unit. */
        uint64_t cmt_arb_gnts          : 7;  /**< [ 21: 15](RO/H) Commit arbitration grant signals. The order of the bits is:
                                                                 0x15 = Fill response grant.
                                                                 0x14 = CP - queue-open grant.
                                                                 0x13 = CP - queue-close grant.
                                                                 0x12 = CP - queue-query grant.
                                                                 0x11 = CP - send-packet grant.
                                                                 0x10 = PEB fill grant.
                                                                 0xF = PEB read grant. */
        uint64_t cmt_arb_reqs          : 7;  /**< [ 28: 22](RO/H) Commit arbitration request signals. The order of the bits is:
                                                                 0x1C = Fill response grant.
                                                                 0x1B = CP - queue-open grant.
                                                                 0x1A = CP - queue-close grant.
                                                                 0x19 = CP - queue-query grant.
                                                                 0x18 = CP - send-packet grant.
                                                                 0x17 = PEB fill grant.
                                                                 0x16 = PEB read grant. */
        uint64_t in_arb_gnts           : 7;  /**< [ 35: 29](RO/H) Input arbitration grant signals. The order of the bits is:
                                                                 0x23 = Fill response grant.
                                                                 0x22 = CP - queue-open grant.
                                                                 0x21 = CP - queue-close grant.
                                                                 0x20 = CP - queue-query grant.
                                                                 0x1F = CP - send-packet grant.
                                                                 0x1E = PEB fill grant.
                                                                 0x1D = PEB read grant. */
        uint64_t in_arb_reqs           : 8;  /**< [ 43: 36](RO/H) Input arbitration request signals. The order of the bits is:
                                                                 0x2B = Fill response - normal path request.
                                                                 0x2A = Fill response - flushb path request.
                                                                 0x29 = CP queue-open request.
                                                                 0x28 = CP queue-closed request.
                                                                 0x27 = CP queue-query request.
                                                                 0x26 = CP send-packet request.
                                                                 0x25 = PEB fill request.
                                                                 0x24 = PEB read request. */
        uint64_t reserved_44_46        : 3;
        uint64_t rdy_hptr              : 6;  /**< [ 52: 47](RO/H) Input arbitration request signals. */
        uint64_t req_hptr              : 6;  /**< [ 58: 53](RO/H) Input arbitration request signals. */
        uint64_t reserved_59           : 1;
        uint64_t isrd_vals_in          : 4;  /**< [ 63: 60](RO/H) Valid signals for ISRD input stage. Bits and descriptions:
                                                                   <63> = prof__isrdex_peb_fill_req_val.
                                                                   <62> = prof__isrdex_rd_req_val.
                                                                   <61> = cp__isr_cval.
                                                                   <60> = fillb__isrd_d_dval. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_isrd_dbg_s cn; */
} bdk_pko_pdm_isrd_dbg_t;

#define BDK_PKO_PDM_ISRD_DBG BDK_PKO_PDM_ISRD_DBG_FUNC()
static inline uint64_t BDK_PKO_PDM_ISRD_DBG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_ISRD_DBG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000800090ll;
    __bdk_csr_fatal("PKO_PDM_ISRD_DBG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_ISRD_DBG bdk_pko_pdm_isrd_dbg_t
#define bustype_BDK_PKO_PDM_ISRD_DBG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_ISRD_DBG "PKO_PDM_ISRD_DBG"
#define device_bar_BDK_PKO_PDM_ISRD_DBG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_ISRD_DBG 0
#define arguments_BDK_PKO_PDM_ISRD_DBG -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_isrd_dbg_dq
 *
 * INTERNAL: PKO PDM ISRD DQ Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_isrd_dbg_dq_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_46_63        : 18;
        uint64_t pebrd_sic_dq          : 10; /**< [ 45: 36](RO/H) CP SIC's DQ number. */
        uint64_t reserved_34_35        : 2;
        uint64_t pebfill_sic_dq        : 10; /**< [ 33: 24](RO/H) CP SIC's DQ number. */
        uint64_t reserved_22_23        : 2;
        uint64_t fr_sic_dq             : 10; /**< [ 21: 12](RO/H) CP SIC's DQ number. */
        uint64_t reserved_10_11        : 2;
        uint64_t cp_sic_dq             : 10; /**< [  9:  0](RO/H) CP SIC's DQ number. */
#else /* Word 0 - Little Endian */
        uint64_t cp_sic_dq             : 10; /**< [  9:  0](RO/H) CP SIC's DQ number. */
        uint64_t reserved_10_11        : 2;
        uint64_t fr_sic_dq             : 10; /**< [ 21: 12](RO/H) CP SIC's DQ number. */
        uint64_t reserved_22_23        : 2;
        uint64_t pebfill_sic_dq        : 10; /**< [ 33: 24](RO/H) CP SIC's DQ number. */
        uint64_t reserved_34_35        : 2;
        uint64_t pebrd_sic_dq          : 10; /**< [ 45: 36](RO/H) CP SIC's DQ number. */
        uint64_t reserved_46_63        : 18;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_isrd_dbg_dq_s cn; */
} bdk_pko_pdm_isrd_dbg_dq_t;

#define BDK_PKO_PDM_ISRD_DBG_DQ BDK_PKO_PDM_ISRD_DBG_DQ_FUNC()
static inline uint64_t BDK_PKO_PDM_ISRD_DBG_DQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_ISRD_DBG_DQ_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000800290ll;
    __bdk_csr_fatal("PKO_PDM_ISRD_DBG_DQ", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_ISRD_DBG_DQ bdk_pko_pdm_isrd_dbg_dq_t
#define bustype_BDK_PKO_PDM_ISRD_DBG_DQ BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_ISRD_DBG_DQ "PKO_PDM_ISRD_DBG_DQ"
#define device_bar_BDK_PKO_PDM_ISRD_DBG_DQ 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_ISRD_DBG_DQ 0
#define arguments_BDK_PKO_PDM_ISRD_DBG_DQ -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_isrm_dbg
 *
 * INTERNAL: PKO PDM ISRM Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_isrm_dbg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t val_in                : 3;  /**< [ 63: 61](RO/H) Valids into ISRM.
                                                                 <63> = pse_ack_val.
                                                                 <62> = fillb__isrm_mp_dval.
                                                                 <61> = isrd__isrm_cval. */
        uint64_t reserved_34_60        : 27;
        uint64_t in_arb_reqs           : 7;  /**< [ 33: 27](RO/H) Input arbitration request signals. The order of the bits is:
                                                                 0x21 = PSE ACK.
                                                                 0x20 = Fill Response - normal path request.
                                                                 0x1F = Fill Response - flushb path request.
                                                                 0x1E = CP queue-open.
                                                                 0x1D = CP queue-closed.
                                                                 0x1C = CP queue-query.
                                                                 0x1B = CP send-packet. */
        uint64_t in_arb_gnts           : 6;  /**< [ 26: 21](RO/H) Input arbitration grant signals. The order of the bits is:
                                                                 0x1A = PSE ACK.
                                                                 0x19 = Fill Response.
                                                                 0x18 = CP - queue-open.
                                                                 0x17 = CP - queue-close.
                                                                 0x16 = CP - queue-query.
                                                                 0x15 = CP - send-packet. */
        uint64_t cmt_arb_reqs          : 6;  /**< [ 20: 15](RO/H) Commit arbitration request signals. The order of the bits is:
                                                                 0x14 = PSE ACK.
                                                                 0x13 = Fill Response.
                                                                 0x12 = CP - queue-open.
                                                                 0x11 = CP - queue-close.
                                                                 0x10 = CP - queue-query.
                                                                 0xF CP - send-packet. */
        uint64_t cmt_arb_gnts          : 6;  /**< [ 14:  9](RO/H) Commit arbitration grant signals. The order of the bits is:
                                                                 0xE = PSE ACK.
                                                                 0xD = Fill Response.
                                                                 0xC = CP - queue-open.
                                                                 0xB = CP - queue-close.
                                                                 0xA = CP - queue-query.
                                                                 0x9 = CP - send-packet. */
        uint64_t in_use                : 3;  /**< [  8:  6](RO/H) In use signals indicate the execution units are in use. The order of the bits is:
                                                                 0x8 = (PSE) ACK unit.
                                                                 0x7 = Fill response unit.
                                                                 0x6 = CP unit. */
        uint64_t has_cred              : 3;  /**< [  5:  3](RO/H) Has credit signals indicate there is sufficient credit to commit. The order of the bits
                                                                 is:
                                                                 0x5 = Flush buffer has credit.
                                                                 0x4 = Fill buffer has credit.
                                                                 0x3 = MWP command output FIFO has credit. */
        uint64_t val_exec              : 3;  /**< [  2:  0](RO/H) Valid bits for the execution units; means the unit can commit if it gets the grant of the
                                                                 commit arb and other conditions are met. The order of the bits is:
                                                                 0x2 = (PSE) ACK unit.
                                                                 0x1 = Fill response unit.
                                                                 0x0 = CP unit - ALL. */
#else /* Word 0 - Little Endian */
        uint64_t val_exec              : 3;  /**< [  2:  0](RO/H) Valid bits for the execution units; means the unit can commit if it gets the grant of the
                                                                 commit arb and other conditions are met. The order of the bits is:
                                                                 0x2 = (PSE) ACK unit.
                                                                 0x1 = Fill response unit.
                                                                 0x0 = CP unit - ALL. */
        uint64_t has_cred              : 3;  /**< [  5:  3](RO/H) Has credit signals indicate there is sufficient credit to commit. The order of the bits
                                                                 is:
                                                                 0x5 = Flush buffer has credit.
                                                                 0x4 = Fill buffer has credit.
                                                                 0x3 = MWP command output FIFO has credit. */
        uint64_t in_use                : 3;  /**< [  8:  6](RO/H) In use signals indicate the execution units are in use. The order of the bits is:
                                                                 0x8 = (PSE) ACK unit.
                                                                 0x7 = Fill response unit.
                                                                 0x6 = CP unit. */
        uint64_t cmt_arb_gnts          : 6;  /**< [ 14:  9](RO/H) Commit arbitration grant signals. The order of the bits is:
                                                                 0xE = PSE ACK.
                                                                 0xD = Fill Response.
                                                                 0xC = CP - queue-open.
                                                                 0xB = CP - queue-close.
                                                                 0xA = CP - queue-query.
                                                                 0x9 = CP - send-packet. */
        uint64_t cmt_arb_reqs          : 6;  /**< [ 20: 15](RO/H) Commit arbitration request signals. The order of the bits is:
                                                                 0x14 = PSE ACK.
                                                                 0x13 = Fill Response.
                                                                 0x12 = CP - queue-open.
                                                                 0x11 = CP - queue-close.
                                                                 0x10 = CP - queue-query.
                                                                 0xF CP - send-packet. */
        uint64_t in_arb_gnts           : 6;  /**< [ 26: 21](RO/H) Input arbitration grant signals. The order of the bits is:
                                                                 0x1A = PSE ACK.
                                                                 0x19 = Fill Response.
                                                                 0x18 = CP - queue-open.
                                                                 0x17 = CP - queue-close.
                                                                 0x16 = CP - queue-query.
                                                                 0x15 = CP - send-packet. */
        uint64_t in_arb_reqs           : 7;  /**< [ 33: 27](RO/H) Input arbitration request signals. The order of the bits is:
                                                                 0x21 = PSE ACK.
                                                                 0x20 = Fill Response - normal path request.
                                                                 0x1F = Fill Response - flushb path request.
                                                                 0x1E = CP queue-open.
                                                                 0x1D = CP queue-closed.
                                                                 0x1C = CP queue-query.
                                                                 0x1B = CP send-packet. */
        uint64_t reserved_34_60        : 27;
        uint64_t val_in                : 3;  /**< [ 63: 61](RO/H) Valids into ISRM.
                                                                 <63> = pse_ack_val.
                                                                 <62> = fillb__isrm_mp_dval.
                                                                 <61> = isrd__isrm_cval. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_isrm_dbg_s cn; */
} bdk_pko_pdm_isrm_dbg_t;

#define BDK_PKO_PDM_ISRM_DBG BDK_PKO_PDM_ISRM_DBG_FUNC()
static inline uint64_t BDK_PKO_PDM_ISRM_DBG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_ISRM_DBG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000800098ll;
    __bdk_csr_fatal("PKO_PDM_ISRM_DBG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_ISRM_DBG bdk_pko_pdm_isrm_dbg_t
#define bustype_BDK_PKO_PDM_ISRM_DBG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_ISRM_DBG "PKO_PDM_ISRM_DBG"
#define device_bar_BDK_PKO_PDM_ISRM_DBG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_ISRM_DBG 0
#define arguments_BDK_PKO_PDM_ISRM_DBG -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_isrm_dbg_dq
 *
 * INTERNAL: PKO PDM ISRM DQ Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_isrm_dbg_dq_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t ack_sic_dq            : 10; /**< [ 33: 24](RO/H) CP SIC's DQ number. */
        uint64_t reserved_22_23        : 2;
        uint64_t fr_sic_dq             : 10; /**< [ 21: 12](RO/H) CP SIC's DQ number. */
        uint64_t reserved_10_11        : 2;
        uint64_t cp_sic_dq             : 10; /**< [  9:  0](RO/H) CP SIC's DQ number. */
#else /* Word 0 - Little Endian */
        uint64_t cp_sic_dq             : 10; /**< [  9:  0](RO/H) CP SIC's DQ number. */
        uint64_t reserved_10_11        : 2;
        uint64_t fr_sic_dq             : 10; /**< [ 21: 12](RO/H) CP SIC's DQ number. */
        uint64_t reserved_22_23        : 2;
        uint64_t ack_sic_dq            : 10; /**< [ 33: 24](RO/H) CP SIC's DQ number. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_isrm_dbg_dq_s cn; */
} bdk_pko_pdm_isrm_dbg_dq_t;

#define BDK_PKO_PDM_ISRM_DBG_DQ BDK_PKO_PDM_ISRM_DBG_DQ_FUNC()
static inline uint64_t BDK_PKO_PDM_ISRM_DBG_DQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_ISRM_DBG_DQ_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000800298ll;
    __bdk_csr_fatal("PKO_PDM_ISRM_DBG_DQ", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_ISRM_DBG_DQ bdk_pko_pdm_isrm_dbg_dq_t
#define bustype_BDK_PKO_PDM_ISRM_DBG_DQ BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_ISRM_DBG_DQ "PKO_PDM_ISRM_DBG_DQ"
#define device_bar_BDK_PKO_PDM_ISRM_DBG_DQ 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_ISRM_DBG_DQ 0
#define arguments_BDK_PKO_PDM_ISRM_DBG_DQ -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_mem_addr
 *
 * PKO PDM Memory Read/Write Address Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_mem_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t memsel                : 3;  /**< [ 63: 61](R/W/H) Memory select. Selects the RAM to read or write to.
                                                                 0 = Invalid.
                                                                 1 = Reserved.
                                                                 2 = Reserved.
                                                                 3 = DWPBUF.
                                                                 4 = DRPBUF.
                                                                 5 = MWPBUF. */
        uint64_t reserved_17_60        : 44;
        uint64_t memaddr               : 14; /**< [ 16:  3](R/W/H) Memory address for the RAM. */
        uint64_t reserved_2            : 1;
        uint64_t membanksel            : 2;  /**< [  1:  0](R/W/H) Memory bank select. Selects the bank to write to. Note that bit 0 is the only bit used in
                                                                 the PBUF's because there are only 2 banks per each PBUF. In the ISRM bank sel 3 is
                                                                 illegal. */
#else /* Word 0 - Little Endian */
        uint64_t membanksel            : 2;  /**< [  1:  0](R/W/H) Memory bank select. Selects the bank to write to. Note that bit 0 is the only bit used in
                                                                 the PBUF's because there are only 2 banks per each PBUF. In the ISRM bank sel 3 is
                                                                 illegal. */
        uint64_t reserved_2            : 1;
        uint64_t memaddr               : 14; /**< [ 16:  3](R/W/H) Memory address for the RAM. */
        uint64_t reserved_17_60        : 44;
        uint64_t memsel                : 3;  /**< [ 63: 61](R/W/H) Memory select. Selects the RAM to read or write to.
                                                                 0 = Invalid.
                                                                 1 = Reserved.
                                                                 2 = Reserved.
                                                                 3 = DWPBUF.
                                                                 4 = DRPBUF.
                                                                 5 = MWPBUF. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_mem_addr_s cn; */
} bdk_pko_pdm_mem_addr_t;

#define BDK_PKO_PDM_MEM_ADDR BDK_PKO_PDM_MEM_ADDR_FUNC()
static inline uint64_t BDK_PKO_PDM_MEM_ADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_MEM_ADDR_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000800018ll;
    __bdk_csr_fatal("PKO_PDM_MEM_ADDR", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_MEM_ADDR bdk_pko_pdm_mem_addr_t
#define bustype_BDK_PKO_PDM_MEM_ADDR BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_MEM_ADDR "PKO_PDM_MEM_ADDR"
#define device_bar_BDK_PKO_PDM_MEM_ADDR 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_MEM_ADDR 0
#define arguments_BDK_PKO_PDM_MEM_ADDR -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_mem_data
 *
 * PKO PDM Memory Data Word 0 Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_mem_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Raw data to write into the memory, or the raw data read out from the memory. Note that the
                                                                 ISR RAMs are only 57 bits wide, so [56:0] are the only bits that can be read or written to
                                                                 them. The PBUFs are 64 bits wide. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Raw data to write into the memory, or the raw data read out from the memory. Note that the
                                                                 ISR RAMs are only 57 bits wide, so [56:0] are the only bits that can be read or written to
                                                                 them. The PBUFs are 64 bits wide. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_mem_data_s cn; */
} bdk_pko_pdm_mem_data_t;

#define BDK_PKO_PDM_MEM_DATA BDK_PKO_PDM_MEM_DATA_FUNC()
static inline uint64_t BDK_PKO_PDM_MEM_DATA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_MEM_DATA_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000800010ll;
    __bdk_csr_fatal("PKO_PDM_MEM_DATA", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_MEM_DATA bdk_pko_pdm_mem_data_t
#define bustype_BDK_PKO_PDM_MEM_DATA BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_MEM_DATA "PKO_PDM_MEM_DATA"
#define device_bar_BDK_PKO_PDM_MEM_DATA 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_MEM_DATA 0
#define arguments_BDK_PKO_PDM_MEM_DATA -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_mem_rw_ctl
 *
 * PKO PDM Memory Read/Write Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_mem_rw_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t read                  : 1;  /**< [  1:  1](WO/H) Set to 1 to read memory. */
        uint64_t write                 : 1;  /**< [  0:  0](WO/H) Set to 1 to write memory. */
#else /* Word 0 - Little Endian */
        uint64_t write                 : 1;  /**< [  0:  0](WO/H) Set to 1 to write memory. */
        uint64_t read                  : 1;  /**< [  1:  1](WO/H) Set to 1 to read memory. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_mem_rw_ctl_s cn; */
} bdk_pko_pdm_mem_rw_ctl_t;

#define BDK_PKO_PDM_MEM_RW_CTL BDK_PKO_PDM_MEM_RW_CTL_FUNC()
static inline uint64_t BDK_PKO_PDM_MEM_RW_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_MEM_RW_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000800020ll;
    __bdk_csr_fatal("PKO_PDM_MEM_RW_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_MEM_RW_CTL bdk_pko_pdm_mem_rw_ctl_t
#define bustype_BDK_PKO_PDM_MEM_RW_CTL BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_MEM_RW_CTL "PKO_PDM_MEM_RW_CTL"
#define device_bar_BDK_PKO_PDM_MEM_RW_CTL 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_MEM_RW_CTL 0
#define arguments_BDK_PKO_PDM_MEM_RW_CTL -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_mem_rw_sts
 *
 * PKO PDM Memory Read/Write Status Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_mem_rw_sts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t readdone              : 1;  /**< [  0:  0](R/W1C/H) This bit is set to 1 when the read is complete and the data is valid in the data register. */
#else /* Word 0 - Little Endian */
        uint64_t readdone              : 1;  /**< [  0:  0](R/W1C/H) This bit is set to 1 when the read is complete and the data is valid in the data register. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_mem_rw_sts_s cn; */
} bdk_pko_pdm_mem_rw_sts_t;

#define BDK_PKO_PDM_MEM_RW_STS BDK_PKO_PDM_MEM_RW_STS_FUNC()
static inline uint64_t BDK_PKO_PDM_MEM_RW_STS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_MEM_RW_STS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000800028ll;
    __bdk_csr_fatal("PKO_PDM_MEM_RW_STS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_MEM_RW_STS bdk_pko_pdm_mem_rw_sts_t
#define bustype_BDK_PKO_PDM_MEM_RW_STS BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_MEM_RW_STS "PKO_PDM_MEM_RW_STS"
#define device_bar_BDK_PKO_PDM_MEM_RW_STS 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_MEM_RW_STS 0
#define arguments_BDK_PKO_PDM_MEM_RW_STS -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_mwpbuf_dbg
 *
 * INTERNAL: PKO PDM MWPBUF Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_mwpbuf_dbg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t str_proc              : 1;  /**< [ 48: 48](RO/H) Stream process for data streaming. */
        uint64_t cmd_proc              : 1;  /**< [ 47: 47](RO/H) Command process for memory-type instruction. */
        uint64_t str_val               : 1;  /**< [ 46: 46](RO/H) streaming valid. */
        uint64_t mem_data_val          : 1;  /**< [ 45: 45](RO/H) Memory data valid. */
        uint64_t insert_np             : 1;  /**< [ 44: 44](RO/H) Next pointer insertion. */
        uint64_t insert_mp             : 1;  /**< [ 43: 43](RO/H) Meta-packet insertion. */
        uint64_t sel_nxt_ptr           : 1;  /**< [ 42: 42](RO/H) Sel_nxt_ptr signal. */
        uint64_t load_val              : 1;  /**< [ 41: 41](RO/H) Load valid signal. */
        uint64_t rdy                   : 1;  /**< [ 40: 40](RO/H) Ready signal. */
        uint64_t cur_state             : 3;  /**< [ 39: 37](RO/H) Stall count value. */
        uint64_t mem_rdy               : 1;  /**< [ 36: 36](RO/H) Memory stage ready. */
        uint64_t str_rdy               : 1;  /**< [ 35: 35](RO/H) Streaming logic ready. */
        uint64_t contention_type       : 2;  /**< [ 34: 33](RO/H) Contention detected and type mwpbuf__csr_conflict[1:0] bit 0 - a streamFill followed by a
                                                                 flush (same dq, same dst) bit 1 - a flush followed by a stream (same dq, same dst) */
        uint64_t reserved_21_32        : 12;
        uint64_t mem_wen               : 4;  /**< [ 20: 17](RO/H) Memory write enable signals. The order of the bits is:
                                                                 0x3 = wen mem3.
                                                                 0x2 = wen mem2.
                                                                 0x1 = wen mem1.
                                                                 0x0 = wen mem0. */
        uint64_t reserved_15_16        : 2;
        uint64_t mem_addr              : 11; /**< [ 14:  4](RO/H) Memory address for pbuf ram. */
        uint64_t mem_en                : 4;  /**< [  3:  0](RO/H) Memory chip enable signals. The order of the bits is:
                                                                 0x3 = cen mem3.
                                                                 0x2 = cen mem2.
                                                                 0x1 = cen mem1.
                                                                 0x0 = cen mem0. */
#else /* Word 0 - Little Endian */
        uint64_t mem_en                : 4;  /**< [  3:  0](RO/H) Memory chip enable signals. The order of the bits is:
                                                                 0x3 = cen mem3.
                                                                 0x2 = cen mem2.
                                                                 0x1 = cen mem1.
                                                                 0x0 = cen mem0. */
        uint64_t mem_addr              : 11; /**< [ 14:  4](RO/H) Memory address for pbuf ram. */
        uint64_t reserved_15_16        : 2;
        uint64_t mem_wen               : 4;  /**< [ 20: 17](RO/H) Memory write enable signals. The order of the bits is:
                                                                 0x3 = wen mem3.
                                                                 0x2 = wen mem2.
                                                                 0x1 = wen mem1.
                                                                 0x0 = wen mem0. */
        uint64_t reserved_21_32        : 12;
        uint64_t contention_type       : 2;  /**< [ 34: 33](RO/H) Contention detected and type mwpbuf__csr_conflict[1:0] bit 0 - a streamFill followed by a
                                                                 flush (same dq, same dst) bit 1 - a flush followed by a stream (same dq, same dst) */
        uint64_t str_rdy               : 1;  /**< [ 35: 35](RO/H) Streaming logic ready. */
        uint64_t mem_rdy               : 1;  /**< [ 36: 36](RO/H) Memory stage ready. */
        uint64_t cur_state             : 3;  /**< [ 39: 37](RO/H) Stall count value. */
        uint64_t rdy                   : 1;  /**< [ 40: 40](RO/H) Ready signal. */
        uint64_t load_val              : 1;  /**< [ 41: 41](RO/H) Load valid signal. */
        uint64_t sel_nxt_ptr           : 1;  /**< [ 42: 42](RO/H) Sel_nxt_ptr signal. */
        uint64_t insert_mp             : 1;  /**< [ 43: 43](RO/H) Meta-packet insertion. */
        uint64_t insert_np             : 1;  /**< [ 44: 44](RO/H) Next pointer insertion. */
        uint64_t mem_data_val          : 1;  /**< [ 45: 45](RO/H) Memory data valid. */
        uint64_t str_val               : 1;  /**< [ 46: 46](RO/H) streaming valid. */
        uint64_t cmd_proc              : 1;  /**< [ 47: 47](RO/H) Command process for memory-type instruction. */
        uint64_t str_proc              : 1;  /**< [ 48: 48](RO/H) Stream process for data streaming. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_mwpbuf_dbg_s cn; */
} bdk_pko_pdm_mwpbuf_dbg_t;

#define BDK_PKO_PDM_MWPBUF_DBG BDK_PKO_PDM_MWPBUF_DBG_FUNC()
static inline uint64_t BDK_PKO_PDM_MWPBUF_DBG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_MWPBUF_DBG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540008000a0ll;
    __bdk_csr_fatal("PKO_PDM_MWPBUF_DBG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_MWPBUF_DBG bdk_pko_pdm_mwpbuf_dbg_t
#define bustype_BDK_PKO_PDM_MWPBUF_DBG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_MWPBUF_DBG "PKO_PDM_MWPBUF_DBG"
#define device_bar_BDK_PKO_PDM_MWPBUF_DBG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_MWPBUF_DBG 0
#define arguments_BDK_PKO_PDM_MWPBUF_DBG -1,-1,-1,-1

/**
 * Register (NCB) pko_pdm_sts
 *
 * PKO PDM Status Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pdm_sts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t cp_stalled_thrshld_hit : 1; /**< [ 37: 37](R/W1C/H) Reserved.
                                                                 Internal:
                                                                 This register is set to 1 if the PDM stalls the inputs for more than
                                                                 PKO_PDM_CFG_DBG[CP_STALL_THRSHLD]: Do not list field in HRM. For lab debug only. */
        uint64_t reserved_35_36        : 2;
        uint64_t mwpbuf_data_val_err   : 1;  /**< [ 34: 34](R/W1C/H) Received signal that MWPBUF had data valid error. */
        uint64_t drpbuf_data_val_err   : 1;  /**< [ 33: 33](R/W1C/H) Received signal that DRPBUF had data valid error. */
        uint64_t dwpbuf_data_val_err   : 1;  /**< [ 32: 32](R/W1C/H) Received signal that DWPBUF had data valid error. */
        uint64_t reserved_30_31        : 2;
        uint64_t qcmd_iobx_err_sts     : 4;  /**< [ 29: 26](R/W1C/H) When PKO_PDM_STS[QCMD_IOBX_ERR] is set, this contains the queue command response's status
                                                                 field for the response causing the error. Note that if multiple errors occur, only the
                                                                 first error status is captured here until PKO_PDM_STS[QCMD_IOBX_ERR] is cleared.
                                                                 Enumerated by PKO_DQSTATUS_E. */
        uint64_t qcmd_iobx_err         : 1;  /**< [ 25: 25](R/W1C/H) Queue command IOBDMA/IOBLD error status occurred in PKO/PDM.
                                                                 PKO_PDM_STS[QCMD_IOBX_ERR_STS] contains the status code. Note that FPA being out of
                                                                 pointers does not set this bit. (See PKO_FPA_NO_PTRS.) */
        uint64_t sendpkt_lmtdma_err_sts : 4; /**< [ 24: 21](R/W1C/H) This is the status field of the command response on the LMTDMA failure indicated by
                                                                 PKO_PDM_STS[SENDPKT_LMTDMA_ERR] bits being asserted. Note that if multiple errors occur,
                                                                 only the first error status is captured here until PKO_PDM_STS[SENDPKT_LMTDMA_ERR] is
                                                                 cleared. Enumerated by PKO_DQSTATUS_E. */
        uint64_t sendpkt_lmtdma_err    : 1;  /**< [ 20: 20](R/W1C/H) Send-packet of type LMTDMA error status occurred in PKO/PDM.
                                                                 PKO_PDM_STS[SENDPKT_LMTDMA_ERR_STS] contains the status code. Note that FPA being out of
                                                                 pointers does not set this bit. (See PKO_FPA_NO_PTRS.) */
        uint64_t sendpkt_lmtst_err_sts : 4;  /**< [ 19: 16](R/W1C/H) This is the status field of the command response on the LMTST failure indicated by
                                                                 PKO_PDM_STS[SENDPKT_LMTST_ERR] bits being asserted. Note that if multiple errors occur
                                                                 only the first error status will be captured here until PKO_PDM_STS[SENDPKT_LMTST_ERR] is
                                                                 cleared. Enumerated by PKO_DQSTATUS_E. */
        uint64_t sendpkt_lmtst_err     : 1;  /**< [ 15: 15](R/W1C/H) Send-packet of type LMTST error status occurred in PKO/PDM.
                                                                 PKO_PDM_STS[SENDPKT_LMTST_ERR_STS] contains the status code. Note that FPA being out of
                                                                 pointers does not set this bit. (See PKO_FPA_NO_PTRS.) */
        uint64_t fpa_no_ptrs           : 1;  /**< [ 14: 14](R/W1C/H) FPA signaled PKO that FPA can not allocate pointers. This is a fatal error. */
        uint64_t reserved_12_13        : 2;
        uint64_t cp_sendpkt_err_no_drp_code : 2;/**< [ 11: 10](R/W1C/H) This field stores the error code for illegally constructed send-packets that did not drop.
                                                                 Note that if multiple errors occur, only the first error code is captured here until
                                                                 PKO_PDM_STS[CP_SENDPKT_ERR_NO_DRP] is cleared. Codes: 0x0 = NO ERROR CODE. 0x1 = SEND_JUMP
                                                                 not at end of descriptor. */
        uint64_t cp_sendpkt_err_no_drp : 1;  /**< [  9:  9](R/W1C/H) PKO/PDM/CP did not drop a send-packet; however, the SEND_JUMP command is not at end of the
                                                                 descriptor. The error code is captured in PKO_PDM_STS[CP_SENDPKT_ERR_NO_DRP_CODE]. */
        uint64_t reserved_7_8          : 2;
        uint64_t cp_sendpkt_err_drop_code : 3;/**< [  6:  4](R/W1C/H) This field stores the error code for illegally constructed send-packet drops. Note that if
                                                                 multiple errors occur, only the first error code is captured here until
                                                                 PKO_PDM_STS[CP_SENDPKT_ERR_DROP] is cleared. PKO_CPSENDDROP_E enumerates the codes and
                                                                 conditions. */
        uint64_t cp_sendpkt_err_drop   : 1;  /**< [  3:  3](R/W1C/H) Dropped a send-packet in PDM/CP due to a rule violation. The error code is captured in
                                                                 PKO_PDM_STS[CP_SENDPKT_ERR_DROP_CODE]. */
        uint64_t reserved_1_2          : 2;
        uint64_t desc_crc_err          : 1;  /**< [  0:  0](R/W1C/H) CRC error occurred in a descriptor. (State may have been corrupted.) */
#else /* Word 0 - Little Endian */
        uint64_t desc_crc_err          : 1;  /**< [  0:  0](R/W1C/H) CRC error occurred in a descriptor. (State may have been corrupted.) */
        uint64_t reserved_1_2          : 2;
        uint64_t cp_sendpkt_err_drop   : 1;  /**< [  3:  3](R/W1C/H) Dropped a send-packet in PDM/CP due to a rule violation. The error code is captured in
                                                                 PKO_PDM_STS[CP_SENDPKT_ERR_DROP_CODE]. */
        uint64_t cp_sendpkt_err_drop_code : 3;/**< [  6:  4](R/W1C/H) This field stores the error code for illegally constructed send-packet drops. Note that if
                                                                 multiple errors occur, only the first error code is captured here until
                                                                 PKO_PDM_STS[CP_SENDPKT_ERR_DROP] is cleared. PKO_CPSENDDROP_E enumerates the codes and
                                                                 conditions. */
        uint64_t reserved_7_8          : 2;
        uint64_t cp_sendpkt_err_no_drp : 1;  /**< [  9:  9](R/W1C/H) PKO/PDM/CP did not drop a send-packet; however, the SEND_JUMP command is not at end of the
                                                                 descriptor. The error code is captured in PKO_PDM_STS[CP_SENDPKT_ERR_NO_DRP_CODE]. */
        uint64_t cp_sendpkt_err_no_drp_code : 2;/**< [ 11: 10](R/W1C/H) This field stores the error code for illegally constructed send-packets that did not drop.
                                                                 Note that if multiple errors occur, only the first error code is captured here until
                                                                 PKO_PDM_STS[CP_SENDPKT_ERR_NO_DRP] is cleared. Codes: 0x0 = NO ERROR CODE. 0x1 = SEND_JUMP
                                                                 not at end of descriptor. */
        uint64_t reserved_12_13        : 2;
        uint64_t fpa_no_ptrs           : 1;  /**< [ 14: 14](R/W1C/H) FPA signaled PKO that FPA can not allocate pointers. This is a fatal error. */
        uint64_t sendpkt_lmtst_err     : 1;  /**< [ 15: 15](R/W1C/H) Send-packet of type LMTST error status occurred in PKO/PDM.
                                                                 PKO_PDM_STS[SENDPKT_LMTST_ERR_STS] contains the status code. Note that FPA being out of
                                                                 pointers does not set this bit. (See PKO_FPA_NO_PTRS.) */
        uint64_t sendpkt_lmtst_err_sts : 4;  /**< [ 19: 16](R/W1C/H) This is the status field of the command response on the LMTST failure indicated by
                                                                 PKO_PDM_STS[SENDPKT_LMTST_ERR] bits being asserted. Note that if multiple errors occur
                                                                 only the first error status will be captured here until PKO_PDM_STS[SENDPKT_LMTST_ERR] is
                                                                 cleared. Enumerated by PKO_DQSTATUS_E. */
        uint64_t sendpkt_lmtdma_err    : 1;  /**< [ 20: 20](R/W1C/H) Send-packet of type LMTDMA error status occurred in PKO/PDM.
                                                                 PKO_PDM_STS[SENDPKT_LMTDMA_ERR_STS] contains the status code. Note that FPA being out of
                                                                 pointers does not set this bit. (See PKO_FPA_NO_PTRS.) */
        uint64_t sendpkt_lmtdma_err_sts : 4; /**< [ 24: 21](R/W1C/H) This is the status field of the command response on the LMTDMA failure indicated by
                                                                 PKO_PDM_STS[SENDPKT_LMTDMA_ERR] bits being asserted. Note that if multiple errors occur,
                                                                 only the first error status is captured here until PKO_PDM_STS[SENDPKT_LMTDMA_ERR] is
                                                                 cleared. Enumerated by PKO_DQSTATUS_E. */
        uint64_t qcmd_iobx_err         : 1;  /**< [ 25: 25](R/W1C/H) Queue command IOBDMA/IOBLD error status occurred in PKO/PDM.
                                                                 PKO_PDM_STS[QCMD_IOBX_ERR_STS] contains the status code. Note that FPA being out of
                                                                 pointers does not set this bit. (See PKO_FPA_NO_PTRS.) */
        uint64_t qcmd_iobx_err_sts     : 4;  /**< [ 29: 26](R/W1C/H) When PKO_PDM_STS[QCMD_IOBX_ERR] is set, this contains the queue command response's status
                                                                 field for the response causing the error. Note that if multiple errors occur, only the
                                                                 first error status is captured here until PKO_PDM_STS[QCMD_IOBX_ERR] is cleared.
                                                                 Enumerated by PKO_DQSTATUS_E. */
        uint64_t reserved_30_31        : 2;
        uint64_t dwpbuf_data_val_err   : 1;  /**< [ 32: 32](R/W1C/H) Received signal that DWPBUF had data valid error. */
        uint64_t drpbuf_data_val_err   : 1;  /**< [ 33: 33](R/W1C/H) Received signal that DRPBUF had data valid error. */
        uint64_t mwpbuf_data_val_err   : 1;  /**< [ 34: 34](R/W1C/H) Received signal that MWPBUF had data valid error. */
        uint64_t reserved_35_36        : 2;
        uint64_t cp_stalled_thrshld_hit : 1; /**< [ 37: 37](R/W1C/H) Reserved.
                                                                 Internal:
                                                                 This register is set to 1 if the PDM stalls the inputs for more than
                                                                 PKO_PDM_CFG_DBG[CP_STALL_THRSHLD]: Do not list field in HRM. For lab debug only. */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pdm_sts_s cn; */
} bdk_pko_pdm_sts_t;

#define BDK_PKO_PDM_STS BDK_PKO_PDM_STS_FUNC()
static inline uint64_t BDK_PKO_PDM_STS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PDM_STS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000800008ll;
    __bdk_csr_fatal("PKO_PDM_STS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PDM_STS bdk_pko_pdm_sts_t
#define bustype_BDK_PKO_PDM_STS BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PDM_STS "PKO_PDM_STS"
#define device_bar_BDK_PKO_PDM_STS 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PDM_STS 0
#define arguments_BDK_PKO_PDM_STS -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_bist_status
 *
 * PKO PEB BIST Status Information Register
 * Each bit is the BIST result of an individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_26_63        : 38;
        uint64_t add_work_fifo         : 1;  /**< [ 25: 25](RO) ADD_WORK_FIFO RAM BIST status. */
        uint64_t pdm_pse_buf_ram       : 1;  /**< [ 24: 24](RO) PDM_PSE_BUF RAM BIST status. */
        uint64_t iobp0_fifo_ram        : 1;  /**< [ 23: 23](RO) IOBP0_FIFO RAM BIST status. */
        uint64_t iobp1_fifo_ram        : 1;  /**< [ 22: 22](RO) IOBP1_FIFO RAM BIST status. */
        uint64_t state_mem0            : 1;  /**< [ 21: 21](RO) STATE_MEM0 RAM BIST status. */
        uint64_t reserved_19_20        : 2;
        uint64_t state_mem3            : 1;  /**< [ 18: 18](RO) STATE_MEM3 RAM BIST status. */
        uint64_t iobp1_uid_fifo_ram    : 1;  /**< [ 17: 17](RO) IOBP1_UID_FIFO RAM BIST status. */
        uint64_t nxt_link_ptr_ram      : 1;  /**< [ 16: 16](RO) NXT_LINK_PTR RAM BIST status. */
        uint64_t pd_bank0_ram          : 1;  /**< [ 15: 15](RO) PD_BANK0 RAM BIST status. */
        uint64_t reserved_13_14        : 2;
        uint64_t pd_bank3_ram          : 1;  /**< [ 12: 12](RO) PD_BANK3 RAM BIST status. */
        uint64_t pd_var_bank_ram       : 1;  /**< [ 11: 11](RO) PD_VAR_BANK RAM BIST status. */
        uint64_t pdm_resp_buf_ram      : 1;  /**< [ 10: 10](RO) PDM_RESP_BUF RAM BIST status. */
        uint64_t tx_fifo_pkt_ram       : 1;  /**< [  9:  9](RO) TX_FIFO_PKT RAM BIST status. */
        uint64_t tx_fifo_hdr_ram       : 1;  /**< [  8:  8](RO) TX_FIFO_HDR RAM BIST status. */
        uint64_t tx_fifo_crc_ram       : 1;  /**< [  7:  7](RO) TX_FIFO_CRC RAM BIST status. */
        uint64_t ts_addwork_ram        : 1;  /**< [  6:  6](RO) TS_ADDWORK RAM BIST status. */
        uint64_t send_mem_ts_fifo      : 1;  /**< [  5:  5](RO) SEND_MEM_TS_FIFO RAM BIST status. */
        uint64_t send_mem_stdn_fifo    : 1;  /**< [  4:  4](RO) SEND_MEM_STDN_FIFO RAM BIST status. */
        uint64_t send_mem_fifo         : 1;  /**< [  3:  3](RO) SEND_MEM_FIFO RAM BIST status. */
        uint64_t pkt_mrk_ram           : 1;  /**< [  2:  2](RO) PKT_MRK RAM BIST status. */
        uint64_t peb_st_inf_ram        : 1;  /**< [  1:  1](RO) PEB_ST_INF RAM BIST status. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t peb_st_inf_ram        : 1;  /**< [  1:  1](RO) PEB_ST_INF RAM BIST status. */
        uint64_t pkt_mrk_ram           : 1;  /**< [  2:  2](RO) PKT_MRK RAM BIST status. */
        uint64_t send_mem_fifo         : 1;  /**< [  3:  3](RO) SEND_MEM_FIFO RAM BIST status. */
        uint64_t send_mem_stdn_fifo    : 1;  /**< [  4:  4](RO) SEND_MEM_STDN_FIFO RAM BIST status. */
        uint64_t send_mem_ts_fifo      : 1;  /**< [  5:  5](RO) SEND_MEM_TS_FIFO RAM BIST status. */
        uint64_t ts_addwork_ram        : 1;  /**< [  6:  6](RO) TS_ADDWORK RAM BIST status. */
        uint64_t tx_fifo_crc_ram       : 1;  /**< [  7:  7](RO) TX_FIFO_CRC RAM BIST status. */
        uint64_t tx_fifo_hdr_ram       : 1;  /**< [  8:  8](RO) TX_FIFO_HDR RAM BIST status. */
        uint64_t tx_fifo_pkt_ram       : 1;  /**< [  9:  9](RO) TX_FIFO_PKT RAM BIST status. */
        uint64_t pdm_resp_buf_ram      : 1;  /**< [ 10: 10](RO) PDM_RESP_BUF RAM BIST status. */
        uint64_t pd_var_bank_ram       : 1;  /**< [ 11: 11](RO) PD_VAR_BANK RAM BIST status. */
        uint64_t pd_bank3_ram          : 1;  /**< [ 12: 12](RO) PD_BANK3 RAM BIST status. */
        uint64_t reserved_13_14        : 2;
        uint64_t pd_bank0_ram          : 1;  /**< [ 15: 15](RO) PD_BANK0 RAM BIST status. */
        uint64_t nxt_link_ptr_ram      : 1;  /**< [ 16: 16](RO) NXT_LINK_PTR RAM BIST status. */
        uint64_t iobp1_uid_fifo_ram    : 1;  /**< [ 17: 17](RO) IOBP1_UID_FIFO RAM BIST status. */
        uint64_t state_mem3            : 1;  /**< [ 18: 18](RO) STATE_MEM3 RAM BIST status. */
        uint64_t reserved_19_20        : 2;
        uint64_t state_mem0            : 1;  /**< [ 21: 21](RO) STATE_MEM0 RAM BIST status. */
        uint64_t iobp1_fifo_ram        : 1;  /**< [ 22: 22](RO) IOBP1_FIFO RAM BIST status. */
        uint64_t iobp0_fifo_ram        : 1;  /**< [ 23: 23](RO) IOBP0_FIFO RAM BIST status. */
        uint64_t pdm_pse_buf_ram       : 1;  /**< [ 24: 24](RO) PDM_PSE_BUF RAM BIST status. */
        uint64_t add_work_fifo         : 1;  /**< [ 25: 25](RO) ADD_WORK_FIFO RAM BIST status. */
        uint64_t reserved_26_63        : 38;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_bist_status_s cn; */
} bdk_pko_peb_bist_status_t;

#define BDK_PKO_PEB_BIST_STATUS BDK_PKO_PEB_BIST_STATUS_FUNC()
static inline uint64_t BDK_PKO_PEB_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_BIST_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900d00ll;
    __bdk_csr_fatal("PKO_PEB_BIST_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_BIST_STATUS bdk_pko_peb_bist_status_t
#define bustype_BDK_PKO_PEB_BIST_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_BIST_STATUS "PKO_PEB_BIST_STATUS"
#define device_bar_BDK_PKO_PEB_BIST_STATUS 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_BIST_STATUS 0
#define arguments_BDK_PKO_PEB_BIST_STATUS -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_ecc_ctl0
 *
 * PKO PEB RAM ECC Control Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_ecc_ctl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t iobp1_uid_fifo_ram_flip : 2;/**< [ 63: 62](R/W) IOBP1_UID_FIFO_RAM flip syndrome bits on write. */
        uint64_t iobp1_uid_fifo_ram_cdis : 1;/**< [ 61: 61](R/W) IOBP1_UID_FIFO_RAM ECC correction disable. */
        uint64_t iobp0_fifo_ram_flip   : 2;  /**< [ 60: 59](R/W) IOBP0_FIFO_RAM flip syndrome bits on write. */
        uint64_t iobp0_fifo_ram_cdis   : 1;  /**< [ 58: 58](R/W) IOBP0_FIFO_RAM ECC correction disable. */
        uint64_t iobp1_fifo_ram_flip   : 2;  /**< [ 57: 56](R/W) IOBP1_FIFO_RAM flip syndrome bits on write. */
        uint64_t iobp1_fifo_ram_cdis   : 1;  /**< [ 55: 55](R/W) IOBP1_FIFO_RAM ECC correction disable. */
        uint64_t pdm_resp_buf_ram_flip : 2;  /**< [ 54: 53](R/W) PDM_RESP_BUF_RAM flip syndrome bits on write. */
        uint64_t pdm_resp_buf_ram_cdis : 1;  /**< [ 52: 52](R/W) PDM_RESP_BUF_RAM ECC correction disable. */
        uint64_t pdm_pse_buf_ram_flip  : 2;  /**< [ 51: 50](R/W) PDM_PSE_BUF_RAM flip syndrome bits on write. */
        uint64_t pdm_pse_buf_ram_cdis  : 1;  /**< [ 49: 49](R/W) PDM_PSE_BUF_RAM ECC correction disable. */
        uint64_t reserved_46_48        : 3;
        uint64_t peb_st_inf_ram_flip   : 2;  /**< [ 45: 44](R/W) PEB_ST_INF_RAM flip syndrome bits on write. */
        uint64_t peb_st_inf_ram_cdis   : 1;  /**< [ 43: 43](R/W) PEB_ST_INF_RAM ECC correction disable. */
        uint64_t pd_bank3_ram_flip     : 2;  /**< [ 42: 41](R/W) PD_BANK3_RAM flip syndrome bits on write. */
        uint64_t pd_bank3_ram_cdis     : 1;  /**< [ 40: 40](R/W) PD_BANK3_RAM ECC correction disable. */
        uint64_t reserved_34_39        : 6;
        uint64_t pd_bank0_ram_flip     : 2;  /**< [ 33: 32](R/W) PD_BANK0_RAM flip syndrome bits on write. */
        uint64_t pd_bank0_ram_cdis     : 1;  /**< [ 31: 31](R/W) PD_BANK0_RAM ECC correction disable. */
        uint64_t pd_var_bank_ram_flip  : 2;  /**< [ 30: 29](R/W) PD_VAR_BANK_RAM flip syndrome bits on write. */
        uint64_t pd_var_bank_ram_cdis  : 1;  /**< [ 28: 28](R/W) PD_VAR_BANK_RAM ECC correction disable. */
        uint64_t tx_fifo_crc_ram_flip  : 2;  /**< [ 27: 26](R/W) TX_FIFO_CRC_RAM flip syndrome bits on write. */
        uint64_t tx_fifo_crc_ram_cdis  : 1;  /**< [ 25: 25](R/W) TX_FIFO_CRC_RAM ECC correction disable. */
        uint64_t tx_fifo_hdr_ram_flip  : 2;  /**< [ 24: 23](R/W) TX_FIFO_HDR_RAM flip syndrome bits on write. */
        uint64_t tx_fifo_hdr_ram_cdis  : 1;  /**< [ 22: 22](R/W) TX_FIFO_HDR_RAM ECC correction disable. */
        uint64_t tx_fifo_pkt_ram_flip  : 2;  /**< [ 21: 20](R/W) TX_FIFO_PKT_RAM flip syndrome bits on write. */
        uint64_t tx_fifo_pkt_ram_cdis  : 1;  /**< [ 19: 19](R/W) TX_FIFO_PKT_RAM ECC correction disable. */
        uint64_t add_work_fifo_flip    : 2;  /**< [ 18: 17](R/W) ADD_WORK_FIFO flip syndrome bits on write. */
        uint64_t add_work_fifo_cdis    : 1;  /**< [ 16: 16](R/W) ADD_WORK_FIFO ECC correction disable. */
        uint64_t send_mem_fifo_flip    : 2;  /**< [ 15: 14](R/W) SEND_MEM_FIFO flip syndrome bits on write. */
        uint64_t send_mem_fifo_cdis    : 1;  /**< [ 13: 13](R/W) SEND_MEM_FIFO ECC correction disable. */
        uint64_t send_mem_stdn_fifo_flip : 2;/**< [ 12: 11](R/W) SEND_MEM_STDN_FIFO flip syndrome bits on write. */
        uint64_t send_mem_stdn_fifo_cdis : 1;/**< [ 10: 10](R/W) SEND_MEM_STDN_FIFO ECC correction disable. */
        uint64_t send_mem_ts_fifo_flip : 2;  /**< [  9:  8](R/W) SEND_MEM_TS_FIFO flip syndrome bits on write. */
        uint64_t send_mem_ts_fifo_cdis : 1;  /**< [  7:  7](R/W) SEND_MEM_TS_FIFO ECC correction disable. */
        uint64_t nxt_link_ptr_ram_flip : 2;  /**< [  6:  5](R/W) NXT_LINK_PTR_RAM flip syndrome bits on write. */
        uint64_t nxt_link_ptr_ram_cdis : 1;  /**< [  4:  4](R/W) NXT_LINK_PTR_RAM ECC correction disable. */
        uint64_t pkt_mrk_ram_flip      : 2;  /**< [  3:  2](R/W) PKT_MRK_RAM flip syndrome bits on write. */
        uint64_t pkt_mrk_ram_cdis      : 1;  /**< [  1:  1](R/W) PKT_MRK_RAM ECC correction disable. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t pkt_mrk_ram_cdis      : 1;  /**< [  1:  1](R/W) PKT_MRK_RAM ECC correction disable. */
        uint64_t pkt_mrk_ram_flip      : 2;  /**< [  3:  2](R/W) PKT_MRK_RAM flip syndrome bits on write. */
        uint64_t nxt_link_ptr_ram_cdis : 1;  /**< [  4:  4](R/W) NXT_LINK_PTR_RAM ECC correction disable. */
        uint64_t nxt_link_ptr_ram_flip : 2;  /**< [  6:  5](R/W) NXT_LINK_PTR_RAM flip syndrome bits on write. */
        uint64_t send_mem_ts_fifo_cdis : 1;  /**< [  7:  7](R/W) SEND_MEM_TS_FIFO ECC correction disable. */
        uint64_t send_mem_ts_fifo_flip : 2;  /**< [  9:  8](R/W) SEND_MEM_TS_FIFO flip syndrome bits on write. */
        uint64_t send_mem_stdn_fifo_cdis : 1;/**< [ 10: 10](R/W) SEND_MEM_STDN_FIFO ECC correction disable. */
        uint64_t send_mem_stdn_fifo_flip : 2;/**< [ 12: 11](R/W) SEND_MEM_STDN_FIFO flip syndrome bits on write. */
        uint64_t send_mem_fifo_cdis    : 1;  /**< [ 13: 13](R/W) SEND_MEM_FIFO ECC correction disable. */
        uint64_t send_mem_fifo_flip    : 2;  /**< [ 15: 14](R/W) SEND_MEM_FIFO flip syndrome bits on write. */
        uint64_t add_work_fifo_cdis    : 1;  /**< [ 16: 16](R/W) ADD_WORK_FIFO ECC correction disable. */
        uint64_t add_work_fifo_flip    : 2;  /**< [ 18: 17](R/W) ADD_WORK_FIFO flip syndrome bits on write. */
        uint64_t tx_fifo_pkt_ram_cdis  : 1;  /**< [ 19: 19](R/W) TX_FIFO_PKT_RAM ECC correction disable. */
        uint64_t tx_fifo_pkt_ram_flip  : 2;  /**< [ 21: 20](R/W) TX_FIFO_PKT_RAM flip syndrome bits on write. */
        uint64_t tx_fifo_hdr_ram_cdis  : 1;  /**< [ 22: 22](R/W) TX_FIFO_HDR_RAM ECC correction disable. */
        uint64_t tx_fifo_hdr_ram_flip  : 2;  /**< [ 24: 23](R/W) TX_FIFO_HDR_RAM flip syndrome bits on write. */
        uint64_t tx_fifo_crc_ram_cdis  : 1;  /**< [ 25: 25](R/W) TX_FIFO_CRC_RAM ECC correction disable. */
        uint64_t tx_fifo_crc_ram_flip  : 2;  /**< [ 27: 26](R/W) TX_FIFO_CRC_RAM flip syndrome bits on write. */
        uint64_t pd_var_bank_ram_cdis  : 1;  /**< [ 28: 28](R/W) PD_VAR_BANK_RAM ECC correction disable. */
        uint64_t pd_var_bank_ram_flip  : 2;  /**< [ 30: 29](R/W) PD_VAR_BANK_RAM flip syndrome bits on write. */
        uint64_t pd_bank0_ram_cdis     : 1;  /**< [ 31: 31](R/W) PD_BANK0_RAM ECC correction disable. */
        uint64_t pd_bank0_ram_flip     : 2;  /**< [ 33: 32](R/W) PD_BANK0_RAM flip syndrome bits on write. */
        uint64_t reserved_34_39        : 6;
        uint64_t pd_bank3_ram_cdis     : 1;  /**< [ 40: 40](R/W) PD_BANK3_RAM ECC correction disable. */
        uint64_t pd_bank3_ram_flip     : 2;  /**< [ 42: 41](R/W) PD_BANK3_RAM flip syndrome bits on write. */
        uint64_t peb_st_inf_ram_cdis   : 1;  /**< [ 43: 43](R/W) PEB_ST_INF_RAM ECC correction disable. */
        uint64_t peb_st_inf_ram_flip   : 2;  /**< [ 45: 44](R/W) PEB_ST_INF_RAM flip syndrome bits on write. */
        uint64_t reserved_46_48        : 3;
        uint64_t pdm_pse_buf_ram_cdis  : 1;  /**< [ 49: 49](R/W) PDM_PSE_BUF_RAM ECC correction disable. */
        uint64_t pdm_pse_buf_ram_flip  : 2;  /**< [ 51: 50](R/W) PDM_PSE_BUF_RAM flip syndrome bits on write. */
        uint64_t pdm_resp_buf_ram_cdis : 1;  /**< [ 52: 52](R/W) PDM_RESP_BUF_RAM ECC correction disable. */
        uint64_t pdm_resp_buf_ram_flip : 2;  /**< [ 54: 53](R/W) PDM_RESP_BUF_RAM flip syndrome bits on write. */
        uint64_t iobp1_fifo_ram_cdis   : 1;  /**< [ 55: 55](R/W) IOBP1_FIFO_RAM ECC correction disable. */
        uint64_t iobp1_fifo_ram_flip   : 2;  /**< [ 57: 56](R/W) IOBP1_FIFO_RAM flip syndrome bits on write. */
        uint64_t iobp0_fifo_ram_cdis   : 1;  /**< [ 58: 58](R/W) IOBP0_FIFO_RAM ECC correction disable. */
        uint64_t iobp0_fifo_ram_flip   : 2;  /**< [ 60: 59](R/W) IOBP0_FIFO_RAM flip syndrome bits on write. */
        uint64_t iobp1_uid_fifo_ram_cdis : 1;/**< [ 61: 61](R/W) IOBP1_UID_FIFO_RAM ECC correction disable. */
        uint64_t iobp1_uid_fifo_ram_flip : 2;/**< [ 63: 62](R/W) IOBP1_UID_FIFO_RAM flip syndrome bits on write. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_ecc_ctl0_s cn; */
} bdk_pko_peb_ecc_ctl0_t;

#define BDK_PKO_PEB_ECC_CTL0 BDK_PKO_PEB_ECC_CTL0_FUNC()
static inline uint64_t BDK_PKO_PEB_ECC_CTL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_ECC_CTL0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540009fffd0ll;
    __bdk_csr_fatal("PKO_PEB_ECC_CTL0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_ECC_CTL0 bdk_pko_peb_ecc_ctl0_t
#define bustype_BDK_PKO_PEB_ECC_CTL0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_ECC_CTL0 "PKO_PEB_ECC_CTL0"
#define device_bar_BDK_PKO_PEB_ECC_CTL0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_ECC_CTL0 0
#define arguments_BDK_PKO_PEB_ECC_CTL0 -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_ecc_ctl1
 *
 * PKO PEB RAM ECC Control Register 1
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_ecc_ctl1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ts_addwork_ram_flip   : 2;  /**< [ 63: 62](R/W) TS_ADDWORK_RAM flip syndrome bits on write. */
        uint64_t ts_addwork_ram_cdis   : 1;  /**< [ 61: 61](R/W) TS_ADDWORK_RAM ECC correction disable. */
        uint64_t state_mem0_flip       : 2;  /**< [ 60: 59](R/W) STATE_MEM0 flip syndrome bits on write. */
        uint64_t state_mem0_cdis       : 1;  /**< [ 58: 58](R/W) STATE_MEM0 ECC correction disable. */
        uint64_t reserved_52_57        : 6;
        uint64_t state_mem3_flip       : 2;  /**< [ 51: 50](R/W) STATE_MEM3 flip syndrome bits on write. */
        uint64_t state_mem3_cdis       : 1;  /**< [ 49: 49](R/W) STATE_MEM3 ECC correction disable. */
        uint64_t reserved_0_48         : 49;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_48         : 49;
        uint64_t state_mem3_cdis       : 1;  /**< [ 49: 49](R/W) STATE_MEM3 ECC correction disable. */
        uint64_t state_mem3_flip       : 2;  /**< [ 51: 50](R/W) STATE_MEM3 flip syndrome bits on write. */
        uint64_t reserved_52_57        : 6;
        uint64_t state_mem0_cdis       : 1;  /**< [ 58: 58](R/W) STATE_MEM0 ECC correction disable. */
        uint64_t state_mem0_flip       : 2;  /**< [ 60: 59](R/W) STATE_MEM0 flip syndrome bits on write. */
        uint64_t ts_addwork_ram_cdis   : 1;  /**< [ 61: 61](R/W) TS_ADDWORK_RAM ECC correction disable. */
        uint64_t ts_addwork_ram_flip   : 2;  /**< [ 63: 62](R/W) TS_ADDWORK_RAM flip syndrome bits on write. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_ecc_ctl1_s cn; */
} bdk_pko_peb_ecc_ctl1_t;

#define BDK_PKO_PEB_ECC_CTL1 BDK_PKO_PEB_ECC_CTL1_FUNC()
static inline uint64_t BDK_PKO_PEB_ECC_CTL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_ECC_CTL1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540009fffa8ll;
    __bdk_csr_fatal("PKO_PEB_ECC_CTL1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_ECC_CTL1 bdk_pko_peb_ecc_ctl1_t
#define bustype_BDK_PKO_PEB_ECC_CTL1 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_ECC_CTL1 "PKO_PEB_ECC_CTL1"
#define device_bar_BDK_PKO_PEB_ECC_CTL1 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_ECC_CTL1 0
#define arguments_BDK_PKO_PEB_ECC_CTL1 -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_eco
 *
 * INTERNAL: PKO PEB ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_eco_s cn; */
} bdk_pko_peb_eco_t;

#define BDK_PKO_PEB_ECO BDK_PKO_PEB_ECO_FUNC()
static inline uint64_t BDK_PKO_PEB_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000901000ll;
    __bdk_csr_fatal("PKO_PEB_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_ECO bdk_pko_peb_eco_t
#define bustype_BDK_PKO_PEB_ECO BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_ECO "PKO_PEB_ECO"
#define device_bar_BDK_PKO_PEB_ECO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_ECO 0
#define arguments_BDK_PKO_PEB_ECO -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_err_int
 *
 * PKO PEB Error Interrupt Status Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_err_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t peb_macx_cfg_wr_err   : 1;  /**< [  9:  9](R/W1C/H) Asserted when software writes a FIFO number to PKO_MAC()_CFG when that FIFO is
                                                                 already assigned. */
        uint64_t peb_max_link_err      : 1;  /**< [  8:  8](R/W1C/H) Asserted when 200 LINK segments have been followed. Indicates likelihood of infinite loop. */
        uint64_t peb_subd_size_err     : 1;  /**< [  7:  7](R/W1C/H) Asserted when a SEND_LINK/GATHER/IMM/JUMP subD has size=0. */
        uint64_t peb_subd_addr_err     : 1;  /**< [  6:  6](R/W1C/H) Asserted when the address of a FREE/MEM/LINK/LINK segment/JUMP/GATHER subD is 0x0. */
        uint64_t peb_trunc_err         : 1;  /**< [  5:  5](R/W1C/H) Asserted when a PD has truncated data. */
        uint64_t peb_pad_err           : 1;  /**< [  4:  4](R/W1C/H) Asserted when a PD has data padded to it (SEND_HDR[TOTAL] < sum(SEND_DATA[size])). */
        uint64_t peb_pse_fifo_err      : 1;  /**< [  3:  3](R/W1C/H) Asserted when PSE sends PD information for a nonconfigured FIFO. */
        uint64_t peb_fcs_sop_err       : 1;  /**< [  2:  2](R/W1C/H) Asserted when FCS SOP value greater than packet size detected. */
        uint64_t peb_jump_def_err      : 1;  /**< [  1:  1](R/W1C/H) Asserted when JUMP subdescriptor is not last in a PD. */
        uint64_t peb_ext_hdr_def_err   : 1;  /**< [  0:  0](R/W1C/H) Asserted when EXT_HDR is not the second sub-descriptor in a PD. */
#else /* Word 0 - Little Endian */
        uint64_t peb_ext_hdr_def_err   : 1;  /**< [  0:  0](R/W1C/H) Asserted when EXT_HDR is not the second sub-descriptor in a PD. */
        uint64_t peb_jump_def_err      : 1;  /**< [  1:  1](R/W1C/H) Asserted when JUMP subdescriptor is not last in a PD. */
        uint64_t peb_fcs_sop_err       : 1;  /**< [  2:  2](R/W1C/H) Asserted when FCS SOP value greater than packet size detected. */
        uint64_t peb_pse_fifo_err      : 1;  /**< [  3:  3](R/W1C/H) Asserted when PSE sends PD information for a nonconfigured FIFO. */
        uint64_t peb_pad_err           : 1;  /**< [  4:  4](R/W1C/H) Asserted when a PD has data padded to it (SEND_HDR[TOTAL] < sum(SEND_DATA[size])). */
        uint64_t peb_trunc_err         : 1;  /**< [  5:  5](R/W1C/H) Asserted when a PD has truncated data. */
        uint64_t peb_subd_addr_err     : 1;  /**< [  6:  6](R/W1C/H) Asserted when the address of a FREE/MEM/LINK/LINK segment/JUMP/GATHER subD is 0x0. */
        uint64_t peb_subd_size_err     : 1;  /**< [  7:  7](R/W1C/H) Asserted when a SEND_LINK/GATHER/IMM/JUMP subD has size=0. */
        uint64_t peb_max_link_err      : 1;  /**< [  8:  8](R/W1C/H) Asserted when 200 LINK segments have been followed. Indicates likelihood of infinite loop. */
        uint64_t peb_macx_cfg_wr_err   : 1;  /**< [  9:  9](R/W1C/H) Asserted when software writes a FIFO number to PKO_MAC()_CFG when that FIFO is
                                                                 already assigned. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_err_int_s cn; */
} bdk_pko_peb_err_int_t;

#define BDK_PKO_PEB_ERR_INT BDK_PKO_PEB_ERR_INT_FUNC()
static inline uint64_t BDK_PKO_PEB_ERR_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_ERR_INT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900c00ll;
    __bdk_csr_fatal("PKO_PEB_ERR_INT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_ERR_INT bdk_pko_peb_err_int_t
#define bustype_BDK_PKO_PEB_ERR_INT BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_ERR_INT "PKO_PEB_ERR_INT"
#define device_bar_BDK_PKO_PEB_ERR_INT 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_ERR_INT 0
#define arguments_BDK_PKO_PEB_ERR_INT -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_ext_hdr_def_err_info
 *
 * PKO External Error Information Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_ext_hdr_def_err_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t val                   : 1;  /**< [ 19: 19](RO/H) Asserted when PKO_PEB_ERR_INT[PEB_EXT_HDR_DEF_ERR] is set. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_EXT_HDR_DEF_ERR. */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_EXT_HDR_DEF_ERR. */
#else /* Word 0 - Little Endian */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_EXT_HDR_DEF_ERR. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_EXT_HDR_DEF_ERR. */
        uint64_t val                   : 1;  /**< [ 19: 19](RO/H) Asserted when PKO_PEB_ERR_INT[PEB_EXT_HDR_DEF_ERR] is set. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_ext_hdr_def_err_info_s cn; */
} bdk_pko_peb_ext_hdr_def_err_info_t;

#define BDK_PKO_PEB_EXT_HDR_DEF_ERR_INFO BDK_PKO_PEB_EXT_HDR_DEF_ERR_INFO_FUNC()
static inline uint64_t BDK_PKO_PEB_EXT_HDR_DEF_ERR_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_EXT_HDR_DEF_ERR_INFO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900c08ll;
    __bdk_csr_fatal("PKO_PEB_EXT_HDR_DEF_ERR_INFO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_EXT_HDR_DEF_ERR_INFO bdk_pko_peb_ext_hdr_def_err_info_t
#define bustype_BDK_PKO_PEB_EXT_HDR_DEF_ERR_INFO BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_EXT_HDR_DEF_ERR_INFO "PKO_PEB_EXT_HDR_DEF_ERR_INFO"
#define device_bar_BDK_PKO_PEB_EXT_HDR_DEF_ERR_INFO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_EXT_HDR_DEF_ERR_INFO 0
#define arguments_BDK_PKO_PEB_EXT_HDR_DEF_ERR_INFO -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_fcs_sop_err_info
 *
 * PKO FCS Error Information Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_fcs_sop_err_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_FCS_SOP_ERR. */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_FCS_SOP_ERR. */
#else /* Word 0 - Little Endian */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_FCS_SOP_ERR. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_FCS_SOP_ERR. */
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_fcs_sop_err_info_s cn; */
} bdk_pko_peb_fcs_sop_err_info_t;

#define BDK_PKO_PEB_FCS_SOP_ERR_INFO BDK_PKO_PEB_FCS_SOP_ERR_INFO_FUNC()
static inline uint64_t BDK_PKO_PEB_FCS_SOP_ERR_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_FCS_SOP_ERR_INFO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900c18ll;
    __bdk_csr_fatal("PKO_PEB_FCS_SOP_ERR_INFO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_FCS_SOP_ERR_INFO bdk_pko_peb_fcs_sop_err_info_t
#define bustype_BDK_PKO_PEB_FCS_SOP_ERR_INFO BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_FCS_SOP_ERR_INFO "PKO_PEB_FCS_SOP_ERR_INFO"
#define device_bar_BDK_PKO_PEB_FCS_SOP_ERR_INFO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_FCS_SOP_ERR_INFO 0
#define arguments_BDK_PKO_PEB_FCS_SOP_ERR_INFO -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_jump_def_err_info
 *
 * PKO Jump Error Information Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_jump_def_err_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_JUMP_DEF_ERR. */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_JUMP_DEF_ERR. */
#else /* Word 0 - Little Endian */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_JUMP_DEF_ERR. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_JUMP_DEF_ERR. */
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_jump_def_err_info_s cn; */
} bdk_pko_peb_jump_def_err_info_t;

#define BDK_PKO_PEB_JUMP_DEF_ERR_INFO BDK_PKO_PEB_JUMP_DEF_ERR_INFO_FUNC()
static inline uint64_t BDK_PKO_PEB_JUMP_DEF_ERR_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_JUMP_DEF_ERR_INFO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900c10ll;
    __bdk_csr_fatal("PKO_PEB_JUMP_DEF_ERR_INFO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_JUMP_DEF_ERR_INFO bdk_pko_peb_jump_def_err_info_t
#define bustype_BDK_PKO_PEB_JUMP_DEF_ERR_INFO BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_JUMP_DEF_ERR_INFO "PKO_PEB_JUMP_DEF_ERR_INFO"
#define device_bar_BDK_PKO_PEB_JUMP_DEF_ERR_INFO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_JUMP_DEF_ERR_INFO 0
#define arguments_BDK_PKO_PEB_JUMP_DEF_ERR_INFO -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_macx_cfg_wr_err_info
 *
 * PKO MAC Configuration Error Information Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_macx_cfg_wr_err_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t val                   : 1;  /**< [  7:  7](RAZ) Deprecated. */
        uint64_t mac                   : 7;  /**< [  6:  0](RO/H) MAC number associated with the captured PEB_MACX_CFG_WR_ERR. */
#else /* Word 0 - Little Endian */
        uint64_t mac                   : 7;  /**< [  6:  0](RO/H) MAC number associated with the captured PEB_MACX_CFG_WR_ERR. */
        uint64_t val                   : 1;  /**< [  7:  7](RAZ) Deprecated. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_macx_cfg_wr_err_info_s cn; */
} bdk_pko_peb_macx_cfg_wr_err_info_t;

#define BDK_PKO_PEB_MACX_CFG_WR_ERR_INFO BDK_PKO_PEB_MACX_CFG_WR_ERR_INFO_FUNC()
static inline uint64_t BDK_PKO_PEB_MACX_CFG_WR_ERR_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_MACX_CFG_WR_ERR_INFO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900c50ll;
    __bdk_csr_fatal("PKO_PEB_MACX_CFG_WR_ERR_INFO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_MACX_CFG_WR_ERR_INFO bdk_pko_peb_macx_cfg_wr_err_info_t
#define bustype_BDK_PKO_PEB_MACX_CFG_WR_ERR_INFO BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_MACX_CFG_WR_ERR_INFO "PKO_PEB_MACX_CFG_WR_ERR_INFO"
#define device_bar_BDK_PKO_PEB_MACX_CFG_WR_ERR_INFO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_MACX_CFG_WR_ERR_INFO 0
#define arguments_BDK_PKO_PEB_MACX_CFG_WR_ERR_INFO -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_max_link_err_info
 *
 * PKO Max link Error Information Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_max_link_err_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_MAX_LINK_ERR. */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_MAX_LINK_ERR. */
#else /* Word 0 - Little Endian */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_MAX_LINK_ERR. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_MAX_LINK_ERR. */
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_max_link_err_info_s cn; */
} bdk_pko_peb_max_link_err_info_t;

#define BDK_PKO_PEB_MAX_LINK_ERR_INFO BDK_PKO_PEB_MAX_LINK_ERR_INFO_FUNC()
static inline uint64_t BDK_PKO_PEB_MAX_LINK_ERR_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_MAX_LINK_ERR_INFO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900c48ll;
    __bdk_csr_fatal("PKO_PEB_MAX_LINK_ERR_INFO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_MAX_LINK_ERR_INFO bdk_pko_peb_max_link_err_info_t
#define bustype_BDK_PKO_PEB_MAX_LINK_ERR_INFO BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_MAX_LINK_ERR_INFO "PKO_PEB_MAX_LINK_ERR_INFO"
#define device_bar_BDK_PKO_PEB_MAX_LINK_ERR_INFO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_MAX_LINK_ERR_INFO 0
#define arguments_BDK_PKO_PEB_MAX_LINK_ERR_INFO -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_ncb_cfg
 *
 * PKO PEB NCB Interface Configuration Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_ncb_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t rstp                  : 1;  /**< [  0:  0](R/W) Convert STP operations to RSTP. */
#else /* Word 0 - Little Endian */
        uint64_t rstp                  : 1;  /**< [  0:  0](R/W) Convert STP operations to RSTP. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_ncb_cfg_s cn; */
} bdk_pko_peb_ncb_cfg_t;

#define BDK_PKO_PEB_NCB_CFG BDK_PKO_PEB_NCB_CFG_FUNC()
static inline uint64_t BDK_PKO_PEB_NCB_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_NCB_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900308ll;
    __bdk_csr_fatal("PKO_PEB_NCB_CFG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_NCB_CFG bdk_pko_peb_ncb_cfg_t
#define bustype_BDK_PKO_PEB_NCB_CFG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_NCB_CFG "PKO_PEB_NCB_CFG"
#define device_bar_BDK_PKO_PEB_NCB_CFG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_NCB_CFG 0
#define arguments_BDK_PKO_PEB_NCB_CFG -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_pad_err_info
 *
 * PKO PAD Error Information Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_pad_err_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_PAD_ERR. */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_PAD_ERR. */
#else /* Word 0 - Little Endian */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_PAD_ERR. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_PAD_ERR. */
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_pad_err_info_s cn; */
} bdk_pko_peb_pad_err_info_t;

#define BDK_PKO_PEB_PAD_ERR_INFO BDK_PKO_PEB_PAD_ERR_INFO_FUNC()
static inline uint64_t BDK_PKO_PEB_PAD_ERR_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_PAD_ERR_INFO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900c28ll;
    __bdk_csr_fatal("PKO_PEB_PAD_ERR_INFO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_PAD_ERR_INFO bdk_pko_peb_pad_err_info_t
#define bustype_BDK_PKO_PEB_PAD_ERR_INFO BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_PAD_ERR_INFO "PKO_PEB_PAD_ERR_INFO"
#define device_bar_BDK_PKO_PEB_PAD_ERR_INFO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_PAD_ERR_INFO 0
#define arguments_BDK_PKO_PEB_PAD_ERR_INFO -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_pse_fifo_err_info
 *
 * PKO PSE Error Information Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_pse_fifo_err_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_PSE_FIFO_ERR. */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_PSE_FIFO_ERR. */
#else /* Word 0 - Little Endian */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_PSE_FIFO_ERR. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_PSE_FIFO_ERR. */
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_pse_fifo_err_info_s cn; */
} bdk_pko_peb_pse_fifo_err_info_t;

#define BDK_PKO_PEB_PSE_FIFO_ERR_INFO BDK_PKO_PEB_PSE_FIFO_ERR_INFO_FUNC()
static inline uint64_t BDK_PKO_PEB_PSE_FIFO_ERR_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_PSE_FIFO_ERR_INFO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900c20ll;
    __bdk_csr_fatal("PKO_PEB_PSE_FIFO_ERR_INFO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_PSE_FIFO_ERR_INFO bdk_pko_peb_pse_fifo_err_info_t
#define bustype_BDK_PKO_PEB_PSE_FIFO_ERR_INFO BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_PSE_FIFO_ERR_INFO "PKO_PEB_PSE_FIFO_ERR_INFO"
#define device_bar_BDK_PKO_PEB_PSE_FIFO_ERR_INFO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_PSE_FIFO_ERR_INFO 0
#define arguments_BDK_PKO_PEB_PSE_FIFO_ERR_INFO -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_subd_addr_err_info
 *
 * PKO Subdecriptor Error Information Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_subd_addr_err_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_SUBD_ADDR_ERR. */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_SUBD_ADDR_ERR. */
#else /* Word 0 - Little Endian */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_SUBD_ADDR_ERR. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_SUBD_ADDR_ERR. */
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_subd_addr_err_info_s cn; */
} bdk_pko_peb_subd_addr_err_info_t;

#define BDK_PKO_PEB_SUBD_ADDR_ERR_INFO BDK_PKO_PEB_SUBD_ADDR_ERR_INFO_FUNC()
static inline uint64_t BDK_PKO_PEB_SUBD_ADDR_ERR_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_SUBD_ADDR_ERR_INFO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900c38ll;
    __bdk_csr_fatal("PKO_PEB_SUBD_ADDR_ERR_INFO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_SUBD_ADDR_ERR_INFO bdk_pko_peb_subd_addr_err_info_t
#define bustype_BDK_PKO_PEB_SUBD_ADDR_ERR_INFO BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_SUBD_ADDR_ERR_INFO "PKO_PEB_SUBD_ADDR_ERR_INFO"
#define device_bar_BDK_PKO_PEB_SUBD_ADDR_ERR_INFO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_SUBD_ADDR_ERR_INFO 0
#define arguments_BDK_PKO_PEB_SUBD_ADDR_ERR_INFO -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_subd_size_err_info
 *
 * PKO Size_ERR Error Information Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_subd_size_err_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_SUBD_SIZE_ERR. */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_SUBD_SIZE_ERR. */
#else /* Word 0 - Little Endian */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_SUBD_SIZE_ERR. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_SUBD_SIZE_ERR. */
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_subd_size_err_info_s cn; */
} bdk_pko_peb_subd_size_err_info_t;

#define BDK_PKO_PEB_SUBD_SIZE_ERR_INFO BDK_PKO_PEB_SUBD_SIZE_ERR_INFO_FUNC()
static inline uint64_t BDK_PKO_PEB_SUBD_SIZE_ERR_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_SUBD_SIZE_ERR_INFO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900c40ll;
    __bdk_csr_fatal("PKO_PEB_SUBD_SIZE_ERR_INFO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_SUBD_SIZE_ERR_INFO bdk_pko_peb_subd_size_err_info_t
#define bustype_BDK_PKO_PEB_SUBD_SIZE_ERR_INFO BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_SUBD_SIZE_ERR_INFO "PKO_PEB_SUBD_SIZE_ERR_INFO"
#define device_bar_BDK_PKO_PEB_SUBD_SIZE_ERR_INFO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_SUBD_SIZE_ERR_INFO 0
#define arguments_BDK_PKO_PEB_SUBD_SIZE_ERR_INFO -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_trunc_err_info
 *
 * PKO Truncation Error Information Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_trunc_err_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_TRUNC_ERR. */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_TRUNC_ERR. */
#else /* Word 0 - Little Endian */
        uint64_t chan                  : 12; /**< [ 11:  0](RO/H) Channel number associated with the captured PEB_TRUNC_ERR. */
        uint64_t fifo                  : 7;  /**< [ 18: 12](RO/H) FIFO number associated with the captured PEB_TRUNC_ERR. */
        uint64_t val                   : 1;  /**< [ 19: 19](RAZ) Deprecated. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_trunc_err_info_s cn; */
} bdk_pko_peb_trunc_err_info_t;

#define BDK_PKO_PEB_TRUNC_ERR_INFO BDK_PKO_PEB_TRUNC_ERR_INFO_FUNC()
static inline uint64_t BDK_PKO_PEB_TRUNC_ERR_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_TRUNC_ERR_INFO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900c30ll;
    __bdk_csr_fatal("PKO_PEB_TRUNC_ERR_INFO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_TRUNC_ERR_INFO bdk_pko_peb_trunc_err_info_t
#define bustype_BDK_PKO_PEB_TRUNC_ERR_INFO BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_TRUNC_ERR_INFO "PKO_PEB_TRUNC_ERR_INFO"
#define device_bar_BDK_PKO_PEB_TRUNC_ERR_INFO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_TRUNC_ERR_INFO 0
#define arguments_BDK_PKO_PEB_TRUNC_ERR_INFO -1,-1,-1,-1

/**
 * Register (NCB) pko_peb_tso_cfg
 *
 * PKO PEB TSO Segmentation Configuration Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_peb_tso_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t fsf                   : 12; /**< [ 43: 32](R/W) Modify the TCP header flags for the first TSO segmented packet by logical AND
                                                                 with this configuration.

                                                                 _ FLAGS_new = (FLAGS_original) AND [FSF]. */
        uint64_t reserved_28_31        : 4;
        uint64_t msf                   : 12; /**< [ 27: 16](R/W) Modify the TCP header flags for the middle TSO segmented packets by logical AND
                                                                 with this configuration.

                                                                 _ FLAGS_new = (FLAGS_original) AND [MSF]. */
        uint64_t reserved_12_15        : 4;
        uint64_t lsf                   : 12; /**< [ 11:  0](R/W) Modify the TCP header flags for the last TSO segmented packet by logical AND
                                                                 with this configuration.

                                                                 _ FLAGS_new = (FLAGS_original) AND [LSF]. */
#else /* Word 0 - Little Endian */
        uint64_t lsf                   : 12; /**< [ 11:  0](R/W) Modify the TCP header flags for the last TSO segmented packet by logical AND
                                                                 with this configuration.

                                                                 _ FLAGS_new = (FLAGS_original) AND [LSF]. */
        uint64_t reserved_12_15        : 4;
        uint64_t msf                   : 12; /**< [ 27: 16](R/W) Modify the TCP header flags for the middle TSO segmented packets by logical AND
                                                                 with this configuration.

                                                                 _ FLAGS_new = (FLAGS_original) AND [MSF]. */
        uint64_t reserved_28_31        : 4;
        uint64_t fsf                   : 12; /**< [ 43: 32](R/W) Modify the TCP header flags for the first TSO segmented packet by logical AND
                                                                 with this configuration.

                                                                 _ FLAGS_new = (FLAGS_original) AND [FSF]. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_peb_tso_cfg_s cn; */
} bdk_pko_peb_tso_cfg_t;

#define BDK_PKO_PEB_TSO_CFG BDK_PKO_PEB_TSO_CFG_FUNC()
static inline uint64_t BDK_PKO_PEB_TSO_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PEB_TSO_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900310ll;
    __bdk_csr_fatal("PKO_PEB_TSO_CFG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PEB_TSO_CFG bdk_pko_peb_tso_cfg_t
#define bustype_BDK_PKO_PEB_TSO_CFG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PEB_TSO_CFG "PKO_PEB_TSO_CFG"
#define device_bar_BDK_PKO_PEB_TSO_CFG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PEB_TSO_CFG 0
#define arguments_BDK_PKO_PEB_TSO_CFG -1,-1,-1,-1

/**
 * Register (NCB) pko_pf_msix_pba#
 *
 * PKO MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the PKO_PF_INT_VEC_E
 * enumeration.
 *
 * Internal:
 * FIXME, attributes need to be updated when this CSR is implemented.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pf_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated PKO_PF_MSIX_VEC()_CTL, enumerated by
                                                                 PKO_PF_INT_VEC_E. Bits that have no associated PKO_PF_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated PKO_PF_MSIX_VEC()_CTL, enumerated by
                                                                 PKO_PF_INT_VEC_E. Bits that have no associated PKO_PF_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pf_msix_pbax_s cn; */
} bdk_pko_pf_msix_pbax_t;

static inline uint64_t BDK_PKO_PF_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PF_MSIX_PBAX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x8543000f0000ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("PKO_PF_MSIX_PBAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_PF_MSIX_PBAX(a) bdk_pko_pf_msix_pbax_t
#define bustype_BDK_PKO_PF_MSIX_PBAX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PF_MSIX_PBAX(a) "PKO_PF_MSIX_PBAX"
#define device_bar_BDK_PKO_PF_MSIX_PBAX(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_PKO_PF_MSIX_PBAX(a) (a)
#define arguments_BDK_PKO_PF_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_pf_msix_vec#_addr
 *
 * PKO MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the PKO_PF_INT_VEC_E enumeration.
 * Internal:
 * FIXME, attributes need to be updated when this CSR is implemented.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pf_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's PKO_PF_MSIX_VEC()_ADDR, PKO_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of PKO_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_PKO_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's PKO_PF_MSIX_VEC()_ADDR, PKO_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of PKO_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_PKO_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pf_msix_vecx_addr_s cn; */
} bdk_pko_pf_msix_vecx_addr_t;

static inline uint64_t BDK_PKO_PF_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PF_MSIX_VECX_ADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=21))
        return 0x854300000000ll + 0x10ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_PF_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_PF_MSIX_VECX_ADDR(a) bdk_pko_pf_msix_vecx_addr_t
#define bustype_BDK_PKO_PF_MSIX_VECX_ADDR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PF_MSIX_VECX_ADDR(a) "PKO_PF_MSIX_VECX_ADDR"
#define device_bar_BDK_PKO_PF_MSIX_VECX_ADDR(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_PKO_PF_MSIX_VECX_ADDR(a) (a)
#define arguments_BDK_PKO_PF_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_pf_msix_vec#_ctl
 *
 * PKO MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the PKO_PF_INT_VEC_E enumeration.
 * Internal:
 * FIXME, attributes need to be updated when this CSR is implemented.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pf_msix_vecx_ctl_s
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
    /* struct bdk_pko_pf_msix_vecx_ctl_s cn; */
} bdk_pko_pf_msix_vecx_ctl_t;

static inline uint64_t BDK_PKO_PF_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PF_MSIX_VECX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=21))
        return 0x854300000008ll + 0x10ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_PF_MSIX_VECX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_PF_MSIX_VECX_CTL(a) bdk_pko_pf_msix_vecx_ctl_t
#define bustype_BDK_PKO_PF_MSIX_VECX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PF_MSIX_VECX_CTL(a) "PKO_PF_MSIX_VECX_CTL"
#define device_bar_BDK_PKO_PF_MSIX_VECX_CTL(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_PKO_PF_MSIX_VECX_CTL(a) (a)
#define arguments_BDK_PKO_PF_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_pf_vf#_gmctl
 *
 * PKO PF VF Guest Machine Control Register
 * These registers configure the memory management for each VF.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pf_vfx_gmctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_25_63        : 39;
        uint64_t be                    : 1;  /**< [ 24: 24](R/W) VF big-endian select:
                                                                   0 = Little-endian.
                                                                   1 = Big-endian.
                                                                   * Instructions enqueued with LMTST are big-endian.
                                                                   * Instructions pointed to by PKO_SEND_JUMP_S[ADDR] are big-endian.
                                                                   * Next address ponters pointed to PKO_SEND_LINK_S[ADDR] are big-endian.
                                                                   * Buffer depth indications are big-endian.
                                                                   * Packet data either pointed-to or in PKO_SEND_IMM_S are byte-invariant and endian
                                                                 agnostic. */
        uint64_t strm                  : 8;  /**< [ 23: 16](R/W) Low 8 bits of the SMMU stream identifier to use when issuing DQ or data returns
                                                                 related to this VF/DQ set.

                                                                 Stream 0x0 corresponds to the PF, and VFs start at 0x1.

                                                                 Reset such that VF0/index 0 is 0x1, VF1/index 1 is 0x2, etc. */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Guest machine identifier. The GMID to send to FPA for all
                                                                 send buffer frees, or to SSO for all submit work operations initiated by this queue.
                                                                 Must be nonzero or FPA/SSO will drop requests; see FPA_PF_MAP() and SSO_PF_MAP().

                                                                 See also PKI_DPFI_GMCTL[GMID]. */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Guest machine identifier. The GMID to send to FPA for all
                                                                 send buffer frees, or to SSO for all submit work operations initiated by this queue.
                                                                 Must be nonzero or FPA/SSO will drop requests; see FPA_PF_MAP() and SSO_PF_MAP().

                                                                 See also PKI_DPFI_GMCTL[GMID]. */
        uint64_t strm                  : 8;  /**< [ 23: 16](R/W) Low 8 bits of the SMMU stream identifier to use when issuing DQ or data returns
                                                                 related to this VF/DQ set.

                                                                 Stream 0x0 corresponds to the PF, and VFs start at 0x1.

                                                                 Reset such that VF0/index 0 is 0x1, VF1/index 1 is 0x2, etc. */
        uint64_t be                    : 1;  /**< [ 24: 24](R/W) VF big-endian select:
                                                                   0 = Little-endian.
                                                                   1 = Big-endian.
                                                                   * Instructions enqueued with LMTST are big-endian.
                                                                   * Instructions pointed to by PKO_SEND_JUMP_S[ADDR] are big-endian.
                                                                   * Next address ponters pointed to PKO_SEND_LINK_S[ADDR] are big-endian.
                                                                   * Buffer depth indications are big-endian.
                                                                   * Packet data either pointed-to or in PKO_SEND_IMM_S are byte-invariant and endian
                                                                 agnostic. */
        uint64_t reserved_25_63        : 39;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pf_vfx_gmctl_s cn; */
} bdk_pko_pf_vfx_gmctl_t;

static inline uint64_t BDK_PKO_PF_VFX_GMCTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PF_VFX_GMCTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854040001000ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_PF_VFX_GMCTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_PF_VFX_GMCTL(a) bdk_pko_pf_vfx_gmctl_t
#define bustype_BDK_PKO_PF_VFX_GMCTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PF_VFX_GMCTL(a) "PKO_PF_VFX_GMCTL"
#define device_bar_BDK_PKO_PF_VFX_GMCTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PF_VFX_GMCTL(a) (a)
#define arguments_BDK_PKO_PF_VFX_GMCTL(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_pq_debug_green
 *
 * INTERNAL: PKO PSE PQ Level Green Vector Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pq_debug_green_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t g_valid               : 32; /**< [ 63: 32](RO/H) g_valid vector. */
        uint64_t cred_ok_n             : 32; /**< [ 31:  0](RO/H) cred_ok_n vector. */
#else /* Word 0 - Little Endian */
        uint64_t cred_ok_n             : 32; /**< [ 31:  0](RO/H) cred_ok_n vector. */
        uint64_t g_valid               : 32; /**< [ 63: 32](RO/H) g_valid vector. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pq_debug_green_s cn; */
} bdk_pko_pq_debug_green_t;

#define BDK_PKO_PQ_DEBUG_GREEN BDK_PKO_PQ_DEBUG_GREEN_FUNC()
static inline uint64_t BDK_PKO_PQ_DEBUG_GREEN_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PQ_DEBUG_GREEN_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000000058ll;
    __bdk_csr_fatal("PKO_PQ_DEBUG_GREEN", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PQ_DEBUG_GREEN bdk_pko_pq_debug_green_t
#define bustype_BDK_PKO_PQ_DEBUG_GREEN BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PQ_DEBUG_GREEN "PKO_PQ_DEBUG_GREEN"
#define device_bar_BDK_PKO_PQ_DEBUG_GREEN 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PQ_DEBUG_GREEN 0
#define arguments_BDK_PKO_PQ_DEBUG_GREEN -1,-1,-1,-1

/**
 * Register (NCB) pko_pq_debug_links
 *
 * INTERNAL: PKO PSE PQ Level Red Vector Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pq_debug_links_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t links_ready           : 32; /**< [ 63: 32](RO/H) links_ready vector. */
        uint64_t peb_lnk_rdy_ir        : 32; /**< [ 31:  0](RO/H) peb_lnk_rdy_ir vector. */
#else /* Word 0 - Little Endian */
        uint64_t peb_lnk_rdy_ir        : 32; /**< [ 31:  0](RO/H) peb_lnk_rdy_ir vector. */
        uint64_t links_ready           : 32; /**< [ 63: 32](RO/H) links_ready vector. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pq_debug_links_s cn; */
} bdk_pko_pq_debug_links_t;

#define BDK_PKO_PQ_DEBUG_LINKS BDK_PKO_PQ_DEBUG_LINKS_FUNC()
static inline uint64_t BDK_PKO_PQ_DEBUG_LINKS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PQ_DEBUG_LINKS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000000068ll;
    __bdk_csr_fatal("PKO_PQ_DEBUG_LINKS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PQ_DEBUG_LINKS bdk_pko_pq_debug_links_t
#define bustype_BDK_PKO_PQ_DEBUG_LINKS BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PQ_DEBUG_LINKS "PKO_PQ_DEBUG_LINKS"
#define device_bar_BDK_PKO_PQ_DEBUG_LINKS 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PQ_DEBUG_LINKS 0
#define arguments_BDK_PKO_PQ_DEBUG_LINKS -1,-1,-1,-1

/**
 * Register (NCB) pko_pq_debug_yellow
 *
 * INTERNAL: PKO PSE PQ Level Yellow Vector Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pq_debug_yellow_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t y_valid               : 32; /**< [ 63: 32](RO/H) y_valid vector. */
        uint64_t reserved_28_31        : 4;
        uint64_t link_vv               : 28; /**< [ 27:  0](RO/H) link_vv vector. */
#else /* Word 0 - Little Endian */
        uint64_t link_vv               : 28; /**< [ 27:  0](RO/H) link_vv vector. */
        uint64_t reserved_28_31        : 4;
        uint64_t y_valid               : 32; /**< [ 63: 32](RO/H) y_valid vector. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pq_debug_yellow_s cn; */
} bdk_pko_pq_debug_yellow_t;

#define BDK_PKO_PQ_DEBUG_YELLOW BDK_PKO_PQ_DEBUG_YELLOW_FUNC()
static inline uint64_t BDK_PKO_PQ_DEBUG_YELLOW_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PQ_DEBUG_YELLOW_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000000060ll;
    __bdk_csr_fatal("PKO_PQ_DEBUG_YELLOW", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PQ_DEBUG_YELLOW bdk_pko_pq_debug_yellow_t
#define bustype_BDK_PKO_PQ_DEBUG_YELLOW BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PQ_DEBUG_YELLOW "PKO_PQ_DEBUG_YELLOW"
#define device_bar_BDK_PKO_PQ_DEBUG_YELLOW 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PQ_DEBUG_YELLOW 0
#define arguments_BDK_PKO_PQ_DEBUG_YELLOW -1,-1,-1,-1

/**
 * Register (NCB) pko_pq_drain_int_ena_w1c
 *
 * PKO Drain Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pq_drain_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t intr                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PKO_PQ_DRAIN_W1C[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PKO_PQ_DRAIN_W1C[INTR]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pq_drain_int_ena_w1c_s cn; */
} bdk_pko_pq_drain_int_ena_w1c_t;

#define BDK_PKO_PQ_DRAIN_INT_ENA_W1C BDK_PKO_PQ_DRAIN_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_PKO_PQ_DRAIN_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PQ_DRAIN_INT_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000000150ll;
    __bdk_csr_fatal("PKO_PQ_DRAIN_INT_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PQ_DRAIN_INT_ENA_W1C bdk_pko_pq_drain_int_ena_w1c_t
#define bustype_BDK_PKO_PQ_DRAIN_INT_ENA_W1C BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PQ_DRAIN_INT_ENA_W1C "PKO_PQ_DRAIN_INT_ENA_W1C"
#define device_bar_BDK_PKO_PQ_DRAIN_INT_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PQ_DRAIN_INT_ENA_W1C 0
#define arguments_BDK_PKO_PQ_DRAIN_INT_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) pko_pq_drain_int_ena_w1s
 *
 * PKO Drain Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pq_drain_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t intr                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PKO_PQ_DRAIN_W1C[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PKO_PQ_DRAIN_W1C[INTR]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pq_drain_int_ena_w1s_s cn; */
} bdk_pko_pq_drain_int_ena_w1s_t;

#define BDK_PKO_PQ_DRAIN_INT_ENA_W1S BDK_PKO_PQ_DRAIN_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_PKO_PQ_DRAIN_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PQ_DRAIN_INT_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000000158ll;
    __bdk_csr_fatal("PKO_PQ_DRAIN_INT_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PQ_DRAIN_INT_ENA_W1S bdk_pko_pq_drain_int_ena_w1s_t
#define bustype_BDK_PKO_PQ_DRAIN_INT_ENA_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PQ_DRAIN_INT_ENA_W1S "PKO_PQ_DRAIN_INT_ENA_W1S"
#define device_bar_BDK_PKO_PQ_DRAIN_INT_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PQ_DRAIN_INT_ENA_W1S 0
#define arguments_BDK_PKO_PQ_DRAIN_INT_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) pko_pq_drain_w1c
 *
 * PKO Drain Interrupt Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pq_drain_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t intr                  : 1;  /**< [  0:  0](R/W1C/H) Interrupt. The interrupt bit is asserted and an interrupt message to the CIU is generated
                                                                 when the DRAIN command reaches the PQ level. Subsequent interrupt messages are only
                                                                 generated after this bit has been cleared by writing 1. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 1;  /**< [  0:  0](R/W1C/H) Interrupt. The interrupt bit is asserted and an interrupt message to the CIU is generated
                                                                 when the DRAIN command reaches the PQ level. Subsequent interrupt messages are only
                                                                 generated after this bit has been cleared by writing 1. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pq_drain_w1c_s cn; */
} bdk_pko_pq_drain_w1c_t;

#define BDK_PKO_PQ_DRAIN_W1C BDK_PKO_PQ_DRAIN_W1C_FUNC()
static inline uint64_t BDK_PKO_PQ_DRAIN_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PQ_DRAIN_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000000140ll;
    __bdk_csr_fatal("PKO_PQ_DRAIN_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PQ_DRAIN_W1C bdk_pko_pq_drain_w1c_t
#define bustype_BDK_PKO_PQ_DRAIN_W1C BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PQ_DRAIN_W1C "PKO_PQ_DRAIN_W1C"
#define device_bar_BDK_PKO_PQ_DRAIN_W1C 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PQ_DRAIN_W1C 0
#define arguments_BDK_PKO_PQ_DRAIN_W1C -1,-1,-1,-1

/**
 * Register (NCB) pko_pq_drain_w1s
 *
 * PKO Drain Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pq_drain_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t intr                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PKO_PQ_DRAIN_W1C[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PKO_PQ_DRAIN_W1C[INTR]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pq_drain_w1s_s cn; */
} bdk_pko_pq_drain_w1s_t;

#define BDK_PKO_PQ_DRAIN_W1S BDK_PKO_PQ_DRAIN_W1S_FUNC()
static inline uint64_t BDK_PKO_PQ_DRAIN_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PQ_DRAIN_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000000148ll;
    __bdk_csr_fatal("PKO_PQ_DRAIN_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PQ_DRAIN_W1S bdk_pko_pq_drain_w1s_t
#define bustype_BDK_PKO_PQ_DRAIN_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PQ_DRAIN_W1S "PKO_PQ_DRAIN_W1S"
#define device_bar_BDK_PKO_PQ_DRAIN_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PQ_DRAIN_W1S 0
#define arguments_BDK_PKO_PQ_DRAIN_W1S -1,-1,-1,-1

/**
 * Register (NCB) pko_pqa_debug
 *
 * INTERNAL: PKO PSE PQA Internal Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pqa_debug_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#else /* Word 0 - Little Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pqa_debug_s cn; */
} bdk_pko_pqa_debug_t;

#define BDK_PKO_PQA_DEBUG BDK_PKO_PQA_DEBUG_FUNC()
static inline uint64_t BDK_PKO_PQA_DEBUG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PQA_DEBUG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000000128ll;
    __bdk_csr_fatal("PKO_PQA_DEBUG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PQA_DEBUG bdk_pko_pqa_debug_t
#define bustype_BDK_PKO_PQA_DEBUG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PQA_DEBUG "PKO_PQA_DEBUG"
#define device_bar_BDK_PKO_PQA_DEBUG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PQA_DEBUG 0
#define arguments_BDK_PKO_PQA_DEBUG -1,-1,-1,-1

/**
 * Register (NCB) pko_pqb_debug
 *
 * INTERNAL: PKO PSE PQB Internal Debug Register
 *
 * This register has the same bit fields as PKO_PQA_DEBUG.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pqb_debug_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#else /* Word 0 - Little Endian */
        uint64_t dbg_vec               : 64; /**< [ 63:  0](RO/H) Debug Vector. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pqb_debug_s cn; */
} bdk_pko_pqb_debug_t;

#define BDK_PKO_PQB_DEBUG BDK_PKO_PQB_DEBUG_FUNC()
static inline uint64_t BDK_PKO_PQB_DEBUG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PQB_DEBUG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000000130ll;
    __bdk_csr_fatal("PKO_PQB_DEBUG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PQB_DEBUG bdk_pko_pqb_debug_t
#define bustype_BDK_PKO_PQB_DEBUG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PQB_DEBUG "PKO_PQB_DEBUG"
#define device_bar_BDK_PKO_PQB_DEBUG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PQB_DEBUG 0
#define arguments_BDK_PKO_PQB_DEBUG -1,-1,-1,-1

/**
 * Register (NCB) pko_pse_dq_bist_status
 *
 * PKO PSE DQ BIST Status Information Register
 * Each bit is the BIST result of an individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pse_dq_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t wt_sram               : 1;  /**< [  4:  4](RO) Work table. */
        uint64_t reserved_2_3          : 2;
        uint64_t rt1_sram              : 1;  /**< [  1:  1](RO) Result table 1 - DQ FIFO[255:128]. */
        uint64_t rt0_sram              : 1;  /**< [  0:  0](RO) Result table 0 - DQ FIFO[127:0]. */
#else /* Word 0 - Little Endian */
        uint64_t rt0_sram              : 1;  /**< [  0:  0](RO) Result table 0 - DQ FIFO[127:0]. */
        uint64_t rt1_sram              : 1;  /**< [  1:  1](RO) Result table 1 - DQ FIFO[255:128]. */
        uint64_t reserved_2_3          : 2;
        uint64_t wt_sram               : 1;  /**< [  4:  4](RO) Work table. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pse_dq_bist_status_s cn; */
} bdk_pko_pse_dq_bist_status_t;

#define BDK_PKO_PSE_DQ_BIST_STATUS BDK_PKO_PSE_DQ_BIST_STATUS_FUNC()
static inline uint64_t BDK_PKO_PSE_DQ_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PSE_DQ_BIST_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000300138ll;
    __bdk_csr_fatal("PKO_PSE_DQ_BIST_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PSE_DQ_BIST_STATUS bdk_pko_pse_dq_bist_status_t
#define bustype_BDK_PKO_PSE_DQ_BIST_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PSE_DQ_BIST_STATUS "PKO_PSE_DQ_BIST_STATUS"
#define device_bar_BDK_PKO_PSE_DQ_BIST_STATUS 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PSE_DQ_BIST_STATUS 0
#define arguments_BDK_PKO_PSE_DQ_BIST_STATUS -1,-1,-1,-1

/**
 * Register (NCB) pko_pse_dq_ecc_ctl0
 *
 * PKO PSE DQ RAM ECC Control Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pse_dq_ecc_ctl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dq_wt_ram_flip        : 2;  /**< [ 63: 62](R/W) DQ_WT_RAM flip syndrome bits on write. */
        uint64_t dq_wt_ram_cdis        : 1;  /**< [ 61: 61](R/W) DQ_WT_RAM ECC correction disable. */
        uint64_t reserved_43_60        : 18;
        uint64_t dq_rt1_flip           : 2;  /**< [ 42: 41](R/W) DQ_RT1 flip syndrome bits on write. */
        uint64_t dq_rt1_cdis           : 1;  /**< [ 40: 40](R/W) DQ_RT1 ECC correction disable. */
        uint64_t dq_rt0_flip           : 2;  /**< [ 39: 38](R/W) DQ_RT0 flip syndrome bits on write. */
        uint64_t dq_rt0_cdis           : 1;  /**< [ 37: 37](R/W) DQ_RT0 ECC correction disable. */
        uint64_t reserved_0_36         : 37;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_36         : 37;
        uint64_t dq_rt0_cdis           : 1;  /**< [ 37: 37](R/W) DQ_RT0 ECC correction disable. */
        uint64_t dq_rt0_flip           : 2;  /**< [ 39: 38](R/W) DQ_RT0 flip syndrome bits on write. */
        uint64_t dq_rt1_cdis           : 1;  /**< [ 40: 40](R/W) DQ_RT1 ECC correction disable. */
        uint64_t dq_rt1_flip           : 2;  /**< [ 42: 41](R/W) DQ_RT1 flip syndrome bits on write. */
        uint64_t reserved_43_60        : 18;
        uint64_t dq_wt_ram_cdis        : 1;  /**< [ 61: 61](R/W) DQ_WT_RAM ECC correction disable. */
        uint64_t dq_wt_ram_flip        : 2;  /**< [ 63: 62](R/W) DQ_WT_RAM flip syndrome bits on write. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pse_dq_ecc_ctl0_s cn; */
} bdk_pko_pse_dq_ecc_ctl0_t;

#define BDK_PKO_PSE_DQ_ECC_CTL0 BDK_PKO_PSE_DQ_ECC_CTL0_FUNC()
static inline uint64_t BDK_PKO_PSE_DQ_ECC_CTL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PSE_DQ_ECC_CTL0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000300100ll;
    __bdk_csr_fatal("PKO_PSE_DQ_ECC_CTL0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PSE_DQ_ECC_CTL0 bdk_pko_pse_dq_ecc_ctl0_t
#define bustype_BDK_PKO_PSE_DQ_ECC_CTL0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PSE_DQ_ECC_CTL0 "PKO_PSE_DQ_ECC_CTL0"
#define device_bar_BDK_PKO_PSE_DQ_ECC_CTL0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PSE_DQ_ECC_CTL0 0
#define arguments_BDK_PKO_PSE_DQ_ECC_CTL0 -1,-1,-1,-1

/**
 * Register (NCB) pko_pse_pq_bist_status
 *
 * PKO PSE PQ BIST Status Information Register
 * Each bit is the BIST result of an individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pse_pq_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_15_63        : 49;
        uint64_t tp_sram               : 1;  /**< [ 14: 14](RO) Topology parent - pko_pse_pq_srf32x5e. */
        uint64_t reserved_13           : 1;
        uint64_t wmd_sram              : 1;  /**< [ 12: 12](RO) Dynamic watermark state - pko_pse_wmd_srf1024x49e. */
        uint64_t reserved_11           : 1;
        uint64_t cxd_sram              : 1;  /**< [ 10: 10](RO) Dynamic channel state - pko_pse_cxd_srf32x31e. */
        uint64_t dqd_sram              : 1;  /**< [  9:  9](RO) DQ dropped stats - pko_pse_stats_srf1024x88. */
        uint64_t dqs_sram              : 1;  /**< [  8:  8](RO) DQ sent stats - pko_pse_stats_srf1024x88. */
        uint64_t pqd_sram              : 1;  /**< [  7:  7](RO) PQ dropped stats - pko_pse_stats_srf32x88. */
        uint64_t pqr_sram              : 1;  /**< [  6:  6](RO) PQ read stats - pko_pse_stats_srf32x88. */
        uint64_t pqy_sram              : 1;  /**< [  5:  5](RO) PQ yellow stats - pko_pse_stats_srf32x88. */
        uint64_t pqg_sram              : 1;  /**< [  4:  4](RO) PQ green stats - pko_pse_stats_srf32x88. */
        uint64_t std_sram              : 1;  /**< [  3:  3](RO) Dynamic shaping state - pko_pse_std_srf32x105e. */
        uint64_t st_sram               : 1;  /**< [  2:  2](RO) Static shaping configuration - pko_pse_sts_srf32x74e. */
        uint64_t reserved_1            : 1;
        uint64_t cxs_sram              : 1;  /**< [  0:  0](RO) Static channel credit configuration - pko_pse_cx0_srf32x6e. */
#else /* Word 0 - Little Endian */
        uint64_t cxs_sram              : 1;  /**< [  0:  0](RO) Static channel credit configuration - pko_pse_cx0_srf32x6e. */
        uint64_t reserved_1            : 1;
        uint64_t st_sram               : 1;  /**< [  2:  2](RO) Static shaping configuration - pko_pse_sts_srf32x74e. */
        uint64_t std_sram              : 1;  /**< [  3:  3](RO) Dynamic shaping state - pko_pse_std_srf32x105e. */
        uint64_t pqg_sram              : 1;  /**< [  4:  4](RO) PQ green stats - pko_pse_stats_srf32x88. */
        uint64_t pqy_sram              : 1;  /**< [  5:  5](RO) PQ yellow stats - pko_pse_stats_srf32x88. */
        uint64_t pqr_sram              : 1;  /**< [  6:  6](RO) PQ read stats - pko_pse_stats_srf32x88. */
        uint64_t pqd_sram              : 1;  /**< [  7:  7](RO) PQ dropped stats - pko_pse_stats_srf32x88. */
        uint64_t dqs_sram              : 1;  /**< [  8:  8](RO) DQ sent stats - pko_pse_stats_srf1024x88. */
        uint64_t dqd_sram              : 1;  /**< [  9:  9](RO) DQ dropped stats - pko_pse_stats_srf1024x88. */
        uint64_t cxd_sram              : 1;  /**< [ 10: 10](RO) Dynamic channel state - pko_pse_cxd_srf32x31e. */
        uint64_t reserved_11           : 1;
        uint64_t wmd_sram              : 1;  /**< [ 12: 12](RO) Dynamic watermark state - pko_pse_wmd_srf1024x49e. */
        uint64_t reserved_13           : 1;
        uint64_t tp_sram               : 1;  /**< [ 14: 14](RO) Topology parent - pko_pse_pq_srf32x5e. */
        uint64_t reserved_15_63        : 49;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pse_pq_bist_status_s cn; */
} bdk_pko_pse_pq_bist_status_t;

#define BDK_PKO_PSE_PQ_BIST_STATUS BDK_PKO_PSE_PQ_BIST_STATUS_FUNC()
static inline uint64_t BDK_PKO_PSE_PQ_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PSE_PQ_BIST_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000000138ll;
    __bdk_csr_fatal("PKO_PSE_PQ_BIST_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PSE_PQ_BIST_STATUS bdk_pko_pse_pq_bist_status_t
#define bustype_BDK_PKO_PSE_PQ_BIST_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PSE_PQ_BIST_STATUS "PKO_PSE_PQ_BIST_STATUS"
#define device_bar_BDK_PKO_PSE_PQ_BIST_STATUS 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PSE_PQ_BIST_STATUS 0
#define arguments_BDK_PKO_PSE_PQ_BIST_STATUS -1,-1,-1,-1

/**
 * Register (NCB) pko_pse_pq_ecc_ctl0
 *
 * PKO PSE PQ RAM ECC Control Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pse_pq_ecc_ctl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pq_cxs_ram_flip       : 2;  /**< [ 63: 62](R/W) PQ_CXS_RAM flip syndrome bits on write. */
        uint64_t pq_cxs_ram_cdis       : 1;  /**< [ 61: 61](R/W) PQ_CXS_RAM ECC correction disable. */
        uint64_t pq_cxd_ram_flip       : 2;  /**< [ 60: 59](R/W) PQ_CXD_RAM flip syndrome bits on write. */
        uint64_t pq_cxd_ram_cdis       : 1;  /**< [ 58: 58](R/W) PQ_CXD_RAM ECC correction disable. */
        uint64_t reserved_55_57        : 3;
        uint64_t tp_sram_flip          : 2;  /**< [ 54: 53](R/W) TP_SRAM flip syndrome bits on write. */
        uint64_t tp_sram_cdis          : 1;  /**< [ 52: 52](R/W) TP_SRAM ECC correction disable. */
        uint64_t pq_std_ram_flip       : 2;  /**< [ 51: 50](R/W) PQ_STD_RAM flip syndrome bits on write. */
        uint64_t pq_std_ram_cdis       : 1;  /**< [ 49: 49](R/W) PQ_STD_RAM ECC correction disable. */
        uint64_t pq_st_ram_flip        : 2;  /**< [ 48: 47](R/W) PQ_ST_RAM flip syndrome bits on write. */
        uint64_t pq_st_ram_cdis        : 1;  /**< [ 46: 46](R/W) PQ_ST_RAM ECC correction disable. */
        uint64_t pq_wmd_ram_flip       : 2;  /**< [ 45: 44](R/W) PQ_WMD_RAM flip syndrome bits on write. */
        uint64_t pq_wmd_ram_cdis       : 1;  /**< [ 43: 43](R/W) PQ_WMD_RAM ECC correction disable. */
        uint64_t reserved_0_42         : 43;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_42         : 43;
        uint64_t pq_wmd_ram_cdis       : 1;  /**< [ 43: 43](R/W) PQ_WMD_RAM ECC correction disable. */
        uint64_t pq_wmd_ram_flip       : 2;  /**< [ 45: 44](R/W) PQ_WMD_RAM flip syndrome bits on write. */
        uint64_t pq_st_ram_cdis        : 1;  /**< [ 46: 46](R/W) PQ_ST_RAM ECC correction disable. */
        uint64_t pq_st_ram_flip        : 2;  /**< [ 48: 47](R/W) PQ_ST_RAM flip syndrome bits on write. */
        uint64_t pq_std_ram_cdis       : 1;  /**< [ 49: 49](R/W) PQ_STD_RAM ECC correction disable. */
        uint64_t pq_std_ram_flip       : 2;  /**< [ 51: 50](R/W) PQ_STD_RAM flip syndrome bits on write. */
        uint64_t tp_sram_cdis          : 1;  /**< [ 52: 52](R/W) TP_SRAM ECC correction disable. */
        uint64_t tp_sram_flip          : 2;  /**< [ 54: 53](R/W) TP_SRAM flip syndrome bits on write. */
        uint64_t reserved_55_57        : 3;
        uint64_t pq_cxd_ram_cdis       : 1;  /**< [ 58: 58](R/W) PQ_CXD_RAM ECC correction disable. */
        uint64_t pq_cxd_ram_flip       : 2;  /**< [ 60: 59](R/W) PQ_CXD_RAM flip syndrome bits on write. */
        uint64_t pq_cxs_ram_cdis       : 1;  /**< [ 61: 61](R/W) PQ_CXS_RAM ECC correction disable. */
        uint64_t pq_cxs_ram_flip       : 2;  /**< [ 63: 62](R/W) PQ_CXS_RAM flip syndrome bits on write. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pse_pq_ecc_ctl0_s cn; */
} bdk_pko_pse_pq_ecc_ctl0_t;

#define BDK_PKO_PSE_PQ_ECC_CTL0 BDK_PKO_PSE_PQ_ECC_CTL0_FUNC()
static inline uint64_t BDK_PKO_PSE_PQ_ECC_CTL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PSE_PQ_ECC_CTL0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000000100ll;
    __bdk_csr_fatal("PKO_PSE_PQ_ECC_CTL0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PSE_PQ_ECC_CTL0 bdk_pko_pse_pq_ecc_ctl0_t
#define bustype_BDK_PKO_PSE_PQ_ECC_CTL0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PSE_PQ_ECC_CTL0 "PKO_PSE_PQ_ECC_CTL0"
#define device_bar_BDK_PKO_PSE_PQ_ECC_CTL0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PSE_PQ_ECC_CTL0 0
#define arguments_BDK_PKO_PSE_PQ_ECC_CTL0 -1,-1,-1,-1

/**
 * Register (NCB) pko_pse_sq1_bist_status
 *
 * PKO PSE SQ1 BIST Status Information Register
 * Each bit is the BIST result of an individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pse_sq1_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t sc_sram               : 1;  /**< [ 28: 28](RO) SQ[5:1] scheduling configuration. */
        uint64_t pc_sram               : 1;  /**< [ 27: 27](RO) SQ[1] physical channel - pko_pse_pc_srf32x12e. */
        uint64_t xon_sram              : 1;  /**< [ 26: 26](RO) XON SRAM. */
        uint64_t cc_sram               : 1;  /**< [ 25: 25](RO) SQ[1] channel credit OK state array. */
        uint64_t vc1_sram              : 1;  /**< [ 24: 24](RO) SQ[1] virtual channel - pko_pse_sq1_vc_srf256x9e. */
        uint64_t vc0_sram              : 1;  /**< [ 23: 23](RO) SQ[1] virtual channel - pko_pse_sq1_vc_srf256x9e. */
        uint64_t reserved_20_22        : 3;
        uint64_t tp0_sram              : 1;  /**< [ 19: 19](RO) SQ[5:1] topology parent configuration. */
        uint64_t xo_sram               : 1;  /**< [ 18: 18](RO) XOFF SRAM. */
        uint64_t rt_sram               : 1;  /**< [ 17: 17](RO) Result table. */
        uint64_t reserved_9_16         : 8;
        uint64_t tw1_cmd_fifo          : 1;  /**< [  8:  8](RO) SQ[5:1] time wheel 1 command FIFO SRAM. */
        uint64_t std_sram              : 1;  /**< [  7:  7](RO) Dynamic shaping state. */
        uint64_t sts_sram              : 1;  /**< [  6:  6](RO) Static shaping configuration. */
        uint64_t tw0_cmd_fifo          : 1;  /**< [  5:  5](RO) SQ[5:1] time wheel 0 command FIFO SRAM. */
        uint64_t cxd_sram              : 1;  /**< [  4:  4](RO) SQ[1] dynamic channel credit state. */
        uint64_t cxs_sram              : 1;  /**< [  3:  3](RO) SQ[1] static channel credit configuration. */
        uint64_t nt_sram               : 1;  /**< [  2:  2](RO) SQ[5:1] next pointer table. */
        uint64_t pt_sram               : 1;  /**< [  1:  1](RO) SQ[5:1] previous pointer table. */
        uint64_t wt_sram               : 1;  /**< [  0:  0](RO) SQ[5:1] work table. */
#else /* Word 0 - Little Endian */
        uint64_t wt_sram               : 1;  /**< [  0:  0](RO) SQ[5:1] work table. */
        uint64_t pt_sram               : 1;  /**< [  1:  1](RO) SQ[5:1] previous pointer table. */
        uint64_t nt_sram               : 1;  /**< [  2:  2](RO) SQ[5:1] next pointer table. */
        uint64_t cxs_sram              : 1;  /**< [  3:  3](RO) SQ[1] static channel credit configuration. */
        uint64_t cxd_sram              : 1;  /**< [  4:  4](RO) SQ[1] dynamic channel credit state. */
        uint64_t tw0_cmd_fifo          : 1;  /**< [  5:  5](RO) SQ[5:1] time wheel 0 command FIFO SRAM. */
        uint64_t sts_sram              : 1;  /**< [  6:  6](RO) Static shaping configuration. */
        uint64_t std_sram              : 1;  /**< [  7:  7](RO) Dynamic shaping state. */
        uint64_t tw1_cmd_fifo          : 1;  /**< [  8:  8](RO) SQ[5:1] time wheel 1 command FIFO SRAM. */
        uint64_t reserved_9_16         : 8;
        uint64_t rt_sram               : 1;  /**< [ 17: 17](RO) Result table. */
        uint64_t xo_sram               : 1;  /**< [ 18: 18](RO) XOFF SRAM. */
        uint64_t tp0_sram              : 1;  /**< [ 19: 19](RO) SQ[5:1] topology parent configuration. */
        uint64_t reserved_20_22        : 3;
        uint64_t vc0_sram              : 1;  /**< [ 23: 23](RO) SQ[1] virtual channel - pko_pse_sq1_vc_srf256x9e. */
        uint64_t vc1_sram              : 1;  /**< [ 24: 24](RO) SQ[1] virtual channel - pko_pse_sq1_vc_srf256x9e. */
        uint64_t cc_sram               : 1;  /**< [ 25: 25](RO) SQ[1] channel credit OK state array. */
        uint64_t xon_sram              : 1;  /**< [ 26: 26](RO) XON SRAM. */
        uint64_t pc_sram               : 1;  /**< [ 27: 27](RO) SQ[1] physical channel - pko_pse_pc_srf32x12e. */
        uint64_t sc_sram               : 1;  /**< [ 28: 28](RO) SQ[5:1] scheduling configuration. */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } s;
    struct bdk_pko_pse_sq1_bist_status_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t sc_sram               : 1;  /**< [ 28: 28](RO) SQ[5:1] scheduling configuration. */
        uint64_t pc_sram               : 1;  /**< [ 27: 27](RO) SQ[1] physical channel - pko_pse_pc_srf32x12e. */
        uint64_t xon_sram              : 1;  /**< [ 26: 26](RO) XON SRAM. */
        uint64_t cc_sram               : 1;  /**< [ 25: 25](RO) SQ[1] channel credit OK state array. */
        uint64_t vc1_sram              : 1;  /**< [ 24: 24](RO) SQ[1] virtual channel - pko_pse_sq1_vc_srf256x9e. */
        uint64_t vc0_sram              : 1;  /**< [ 23: 23](RO) SQ[1] virtual channel - pko_pse_sq1_vc_srf256x9e. */
        uint64_t reserved_20_22        : 3;
        uint64_t tp0_sram              : 1;  /**< [ 19: 19](RO) SQ[5:1] topology parent configuration. */
        uint64_t xo_sram               : 1;  /**< [ 18: 18](RO) XOFF SRAM. */
        uint64_t rt_sram               : 1;  /**< [ 17: 17](RO) Result table. */
        uint64_t reserved_15_16        : 2;
        uint64_t reserved_9_14         : 6;
        uint64_t tw1_cmd_fifo          : 1;  /**< [  8:  8](RO) SQ[5:1] time wheel 1 command FIFO SRAM. */
        uint64_t std_sram              : 1;  /**< [  7:  7](RO) Dynamic shaping state. */
        uint64_t sts_sram              : 1;  /**< [  6:  6](RO) Static shaping configuration. */
        uint64_t tw0_cmd_fifo          : 1;  /**< [  5:  5](RO) SQ[5:1] time wheel 0 command FIFO SRAM. */
        uint64_t cxd_sram              : 1;  /**< [  4:  4](RO) SQ[1] dynamic channel credit state. */
        uint64_t cxs_sram              : 1;  /**< [  3:  3](RO) SQ[1] static channel credit configuration. */
        uint64_t nt_sram               : 1;  /**< [  2:  2](RO) SQ[5:1] next pointer table. */
        uint64_t pt_sram               : 1;  /**< [  1:  1](RO) SQ[5:1] previous pointer table. */
        uint64_t wt_sram               : 1;  /**< [  0:  0](RO) SQ[5:1] work table. */
#else /* Word 0 - Little Endian */
        uint64_t wt_sram               : 1;  /**< [  0:  0](RO) SQ[5:1] work table. */
        uint64_t pt_sram               : 1;  /**< [  1:  1](RO) SQ[5:1] previous pointer table. */
        uint64_t nt_sram               : 1;  /**< [  2:  2](RO) SQ[5:1] next pointer table. */
        uint64_t cxs_sram              : 1;  /**< [  3:  3](RO) SQ[1] static channel credit configuration. */
        uint64_t cxd_sram              : 1;  /**< [  4:  4](RO) SQ[1] dynamic channel credit state. */
        uint64_t tw0_cmd_fifo          : 1;  /**< [  5:  5](RO) SQ[5:1] time wheel 0 command FIFO SRAM. */
        uint64_t sts_sram              : 1;  /**< [  6:  6](RO) Static shaping configuration. */
        uint64_t std_sram              : 1;  /**< [  7:  7](RO) Dynamic shaping state. */
        uint64_t tw1_cmd_fifo          : 1;  /**< [  8:  8](RO) SQ[5:1] time wheel 1 command FIFO SRAM. */
        uint64_t reserved_9_14         : 6;
        uint64_t reserved_15_16        : 2;
        uint64_t rt_sram               : 1;  /**< [ 17: 17](RO) Result table. */
        uint64_t xo_sram               : 1;  /**< [ 18: 18](RO) XOFF SRAM. */
        uint64_t tp0_sram              : 1;  /**< [ 19: 19](RO) SQ[5:1] topology parent configuration. */
        uint64_t reserved_20_22        : 3;
        uint64_t vc0_sram              : 1;  /**< [ 23: 23](RO) SQ[1] virtual channel - pko_pse_sq1_vc_srf256x9e. */
        uint64_t vc1_sram              : 1;  /**< [ 24: 24](RO) SQ[1] virtual channel - pko_pse_sq1_vc_srf256x9e. */
        uint64_t cc_sram               : 1;  /**< [ 25: 25](RO) SQ[1] channel credit OK state array. */
        uint64_t xon_sram              : 1;  /**< [ 26: 26](RO) XON SRAM. */
        uint64_t pc_sram               : 1;  /**< [ 27: 27](RO) SQ[1] physical channel - pko_pse_pc_srf32x12e. */
        uint64_t sc_sram               : 1;  /**< [ 28: 28](RO) SQ[5:1] scheduling configuration. */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } cn;
} bdk_pko_pse_sq1_bist_status_t;

#define BDK_PKO_PSE_SQ1_BIST_STATUS BDK_PKO_PSE_SQ1_BIST_STATUS_FUNC()
static inline uint64_t BDK_PKO_PSE_SQ1_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PSE_SQ1_BIST_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000080138ll;
    __bdk_csr_fatal("PKO_PSE_SQ1_BIST_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PSE_SQ1_BIST_STATUS bdk_pko_pse_sq1_bist_status_t
#define bustype_BDK_PKO_PSE_SQ1_BIST_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PSE_SQ1_BIST_STATUS "PKO_PSE_SQ1_BIST_STATUS"
#define device_bar_BDK_PKO_PSE_SQ1_BIST_STATUS 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PSE_SQ1_BIST_STATUS 0
#define arguments_BDK_PKO_PSE_SQ1_BIST_STATUS -1,-1,-1,-1

/**
 * Register (NCB) pko_pse_sq1_ecc_ctl0
 *
 * PKO PSE SQ1 RAM ECC Control Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pse_sq1_ecc_ctl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cxs_ram_flip          : 2;  /**< [ 63: 62](R/W) CXS_RAM flip syndrome bits on write. */
        uint64_t cxs_ram_cdis          : 1;  /**< [ 61: 61](R/W) CXS_RAM ECC correction disable. */
        uint64_t cxd_ram_flip          : 2;  /**< [ 60: 59](R/W) CXD_RAM flip syndrome bits on write. */
        uint64_t cxd_ram_cdis          : 1;  /**< [ 58: 58](R/W) CXD_RAM ECC correction disable. */
        uint64_t reserved_55_57        : 3;
        uint64_t vc0_sram_flip         : 2;  /**< [ 54: 53](R/W) VC0_SRAM flip syndrome bits on write. */
        uint64_t vc0_sram_cdis         : 1;  /**< [ 52: 52](R/W) VC0_SRAM ECC correction disable. */
        uint64_t sq_pt_ram_flip        : 2;  /**< [ 51: 50](R/W) SQ_PT_RAM flip syndrome bits on write. */
        uint64_t sq_pt_ram_cdis        : 1;  /**< [ 49: 49](R/W) SQ_PT_RAM ECC correction disable. */
        uint64_t sq_nt_ram_flip        : 2;  /**< [ 48: 47](R/W) SQ_NT_RAM flip syndrome bits on write. */
        uint64_t sq_nt_ram_cdis        : 1;  /**< [ 46: 46](R/W) SQ_NT_RAM ECC correction disable. */
        uint64_t rt_ram_flip           : 2;  /**< [ 45: 44](R/W) RT_RAM flip syndrome bits on write. */
        uint64_t rt_ram_cdis           : 1;  /**< [ 43: 43](R/W) RT_RAM ECC correction disable. */
        uint64_t pc_ram_flip           : 2;  /**< [ 42: 41](R/W) PC_RAM flip syndrome bits on write. */
        uint64_t pc_ram_cdis           : 1;  /**< [ 40: 40](R/W) PC_RAM ECC correction disable. */
        uint64_t reserved_37_39        : 3;
        uint64_t tw0_cmd_fifo_ram_flip : 2;  /**< [ 36: 35](R/W) TW0_CMD_FIFO_RAM flip syndrome bits on write. */
        uint64_t tw0_cmd_fifo_ram_cdis : 1;  /**< [ 34: 34](R/W) TW0_CMD_FIFO_RAM ECC correction disable. */
        uint64_t reserved_31_33        : 3;
        uint64_t tp0_sram_flip         : 2;  /**< [ 30: 29](R/W) TP0_SRAM flip syndrome bits on write. */
        uint64_t tp0_sram_cdis         : 1;  /**< [ 28: 28](R/W) TP0_SRAM ECC correction disable. */
        uint64_t reserved_25_27        : 3;
        uint64_t sts0_ram_flip         : 2;  /**< [ 24: 23](R/W) STS0_RAM flip syndrome bits on write. */
        uint64_t sts0_ram_cdis         : 1;  /**< [ 22: 22](R/W) STS0_RAM ECC correction disable. */
        uint64_t reserved_19_21        : 3;
        uint64_t std0_ram_flip         : 2;  /**< [ 18: 17](R/W) STD0_RAM flip syndrome bits on write. */
        uint64_t std0_ram_cdis         : 1;  /**< [ 16: 16](R/W) STD0_RAM ECC correction disable. */
        uint64_t wt_ram_flip           : 2;  /**< [ 15: 14](R/W) WT_RAM flip syndrome bits on write. */
        uint64_t wt_ram_cdis           : 1;  /**< [ 13: 13](R/W) WT_RAM ECC correction disable. */
        uint64_t sc_ram_flip           : 2;  /**< [ 12: 11](R/W) SC_RAM flip syndrome bits on write. */
        uint64_t sc_ram_cdis           : 1;  /**< [ 10: 10](R/W) SC_RAM ECC correction disable. */
        uint64_t reserved_0_9          : 10;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_9          : 10;
        uint64_t sc_ram_cdis           : 1;  /**< [ 10: 10](R/W) SC_RAM ECC correction disable. */
        uint64_t sc_ram_flip           : 2;  /**< [ 12: 11](R/W) SC_RAM flip syndrome bits on write. */
        uint64_t wt_ram_cdis           : 1;  /**< [ 13: 13](R/W) WT_RAM ECC correction disable. */
        uint64_t wt_ram_flip           : 2;  /**< [ 15: 14](R/W) WT_RAM flip syndrome bits on write. */
        uint64_t std0_ram_cdis         : 1;  /**< [ 16: 16](R/W) STD0_RAM ECC correction disable. */
        uint64_t std0_ram_flip         : 2;  /**< [ 18: 17](R/W) STD0_RAM flip syndrome bits on write. */
        uint64_t reserved_19_21        : 3;
        uint64_t sts0_ram_cdis         : 1;  /**< [ 22: 22](R/W) STS0_RAM ECC correction disable. */
        uint64_t sts0_ram_flip         : 2;  /**< [ 24: 23](R/W) STS0_RAM flip syndrome bits on write. */
        uint64_t reserved_25_27        : 3;
        uint64_t tp0_sram_cdis         : 1;  /**< [ 28: 28](R/W) TP0_SRAM ECC correction disable. */
        uint64_t tp0_sram_flip         : 2;  /**< [ 30: 29](R/W) TP0_SRAM flip syndrome bits on write. */
        uint64_t reserved_31_33        : 3;
        uint64_t tw0_cmd_fifo_ram_cdis : 1;  /**< [ 34: 34](R/W) TW0_CMD_FIFO_RAM ECC correction disable. */
        uint64_t tw0_cmd_fifo_ram_flip : 2;  /**< [ 36: 35](R/W) TW0_CMD_FIFO_RAM flip syndrome bits on write. */
        uint64_t reserved_37_39        : 3;
        uint64_t pc_ram_cdis           : 1;  /**< [ 40: 40](R/W) PC_RAM ECC correction disable. */
        uint64_t pc_ram_flip           : 2;  /**< [ 42: 41](R/W) PC_RAM flip syndrome bits on write. */
        uint64_t rt_ram_cdis           : 1;  /**< [ 43: 43](R/W) RT_RAM ECC correction disable. */
        uint64_t rt_ram_flip           : 2;  /**< [ 45: 44](R/W) RT_RAM flip syndrome bits on write. */
        uint64_t sq_nt_ram_cdis        : 1;  /**< [ 46: 46](R/W) SQ_NT_RAM ECC correction disable. */
        uint64_t sq_nt_ram_flip        : 2;  /**< [ 48: 47](R/W) SQ_NT_RAM flip syndrome bits on write. */
        uint64_t sq_pt_ram_cdis        : 1;  /**< [ 49: 49](R/W) SQ_PT_RAM ECC correction disable. */
        uint64_t sq_pt_ram_flip        : 2;  /**< [ 51: 50](R/W) SQ_PT_RAM flip syndrome bits on write. */
        uint64_t vc0_sram_cdis         : 1;  /**< [ 52: 52](R/W) VC0_SRAM ECC correction disable. */
        uint64_t vc0_sram_flip         : 2;  /**< [ 54: 53](R/W) VC0_SRAM flip syndrome bits on write. */
        uint64_t reserved_55_57        : 3;
        uint64_t cxd_ram_cdis          : 1;  /**< [ 58: 58](R/W) CXD_RAM ECC correction disable. */
        uint64_t cxd_ram_flip          : 2;  /**< [ 60: 59](R/W) CXD_RAM flip syndrome bits on write. */
        uint64_t cxs_ram_cdis          : 1;  /**< [ 61: 61](R/W) CXS_RAM ECC correction disable. */
        uint64_t cxs_ram_flip          : 2;  /**< [ 63: 62](R/W) CXS_RAM flip syndrome bits on write. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pse_sq1_ecc_ctl0_s cn; */
} bdk_pko_pse_sq1_ecc_ctl0_t;

#define BDK_PKO_PSE_SQ1_ECC_CTL0 BDK_PKO_PSE_SQ1_ECC_CTL0_FUNC()
static inline uint64_t BDK_PKO_PSE_SQ1_ECC_CTL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PSE_SQ1_ECC_CTL0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000080100ll;
    __bdk_csr_fatal("PKO_PSE_SQ1_ECC_CTL0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PSE_SQ1_ECC_CTL0 bdk_pko_pse_sq1_ecc_ctl0_t
#define bustype_BDK_PKO_PSE_SQ1_ECC_CTL0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PSE_SQ1_ECC_CTL0 "PKO_PSE_SQ1_ECC_CTL0"
#define device_bar_BDK_PKO_PSE_SQ1_ECC_CTL0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PSE_SQ1_ECC_CTL0 0
#define arguments_BDK_PKO_PSE_SQ1_ECC_CTL0 -1,-1,-1,-1

/**
 * Register (NCB) pko_pse_sq2_bist_status
 *
 * PKO PSE SQ2 BIST Status Information Register
 * Each bit is the BIST result of an individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pse_sq2_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t sc_sram               : 1;  /**< [ 28: 28](RO) Scheduling configuration. */
        uint64_t reserved_20_27        : 8;
        uint64_t tp0_sram              : 1;  /**< [ 19: 19](RO) SQ[5:1] topology parent configuration. */
        uint64_t reserved_18           : 1;
        uint64_t rt_sram               : 1;  /**< [ 17: 17](RO) Result table. */
        uint64_t reserved_8_16         : 9;
        uint64_t std_sram              : 1;  /**< [  7:  7](RO) Dynamic shaping state. */
        uint64_t sts_sram              : 1;  /**< [  6:  6](RO) Static shaping configuration. */
        uint64_t tw0_cmd_fifo          : 1;  /**< [  5:  5](RO) SQ[5:1] time wheel 0 command FIFO SRAM. */
        uint64_t reserved_3_4          : 2;
        uint64_t nt_sram               : 1;  /**< [  2:  2](RO) Next pointer table. */
        uint64_t pt_sram               : 1;  /**< [  1:  1](RO) Previous pointer table. */
        uint64_t wt_sram               : 1;  /**< [  0:  0](RO) Work table. */
#else /* Word 0 - Little Endian */
        uint64_t wt_sram               : 1;  /**< [  0:  0](RO) Work table. */
        uint64_t pt_sram               : 1;  /**< [  1:  1](RO) Previous pointer table. */
        uint64_t nt_sram               : 1;  /**< [  2:  2](RO) Next pointer table. */
        uint64_t reserved_3_4          : 2;
        uint64_t tw0_cmd_fifo          : 1;  /**< [  5:  5](RO) SQ[5:1] time wheel 0 command FIFO SRAM. */
        uint64_t sts_sram              : 1;  /**< [  6:  6](RO) Static shaping configuration. */
        uint64_t std_sram              : 1;  /**< [  7:  7](RO) Dynamic shaping state. */
        uint64_t reserved_8_16         : 9;
        uint64_t rt_sram               : 1;  /**< [ 17: 17](RO) Result table. */
        uint64_t reserved_18           : 1;
        uint64_t tp0_sram              : 1;  /**< [ 19: 19](RO) SQ[5:1] topology parent configuration. */
        uint64_t reserved_20_27        : 8;
        uint64_t sc_sram               : 1;  /**< [ 28: 28](RO) Scheduling configuration. */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pse_sq2_bist_status_s cn; */
} bdk_pko_pse_sq2_bist_status_t;

#define BDK_PKO_PSE_SQ2_BIST_STATUS BDK_PKO_PSE_SQ2_BIST_STATUS_FUNC()
static inline uint64_t BDK_PKO_PSE_SQ2_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PSE_SQ2_BIST_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000100138ll;
    __bdk_csr_fatal("PKO_PSE_SQ2_BIST_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PSE_SQ2_BIST_STATUS bdk_pko_pse_sq2_bist_status_t
#define bustype_BDK_PKO_PSE_SQ2_BIST_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PSE_SQ2_BIST_STATUS "PKO_PSE_SQ2_BIST_STATUS"
#define device_bar_BDK_PKO_PSE_SQ2_BIST_STATUS 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PSE_SQ2_BIST_STATUS 0
#define arguments_BDK_PKO_PSE_SQ2_BIST_STATUS -1,-1,-1,-1

/**
 * Register (NCB) pko_pse_sq2_ecc_ctl0
 *
 * PKO PSE SQ2 RAM ECC Control Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pse_sq2_ecc_ctl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t sq_pt_ram_flip        : 2;  /**< [ 63: 62](R/W) SQ_PT_RAM flip syndrome bits on write. */
        uint64_t sq_pt_ram_cdis        : 1;  /**< [ 61: 61](R/W) SQ_PT_RAM ECC correction disable. */
        uint64_t sq_nt_ram_flip        : 2;  /**< [ 60: 59](R/W) SQ_NT_RAM flip syndrome bits on write. */
        uint64_t sq_nt_ram_cdis        : 1;  /**< [ 58: 58](R/W) SQ_NT_RAM ECC correction disable. */
        uint64_t rt_ram_flip           : 2;  /**< [ 57: 56](R/W) RT_RAM flip syndrome bits on write. */
        uint64_t rt_ram_cdis           : 1;  /**< [ 55: 55](R/W) RT_RAM ECC correction disable. */
        uint64_t reserved_52_54        : 3;
        uint64_t tw0_cmd_fifo_ram_flip : 2;  /**< [ 51: 50](R/W) TW0_CMD_FIFO_RAM flip syndrome bits on write. */
        uint64_t tw0_cmd_fifo_ram_cdis : 1;  /**< [ 49: 49](R/W) TW0_CMD_FIFO_RAM ECC correction disable. */
        uint64_t reserved_46_48        : 3;
        uint64_t tp0_sram_flip         : 2;  /**< [ 45: 44](R/W) TP0_SRAM flip syndrome bits on write. */
        uint64_t tp0_sram_cdis         : 1;  /**< [ 43: 43](R/W) TP0_SRAM ECC correction disable. */
        uint64_t reserved_40_42        : 3;
        uint64_t sts0_ram_flip         : 2;  /**< [ 39: 38](R/W) STS0_RAM flip syndrome bits on write. */
        uint64_t sts0_ram_cdis         : 1;  /**< [ 37: 37](R/W) STS0_RAM ECC correction disable. */
        uint64_t reserved_34_36        : 3;
        uint64_t std0_ram_flip         : 2;  /**< [ 33: 32](R/W) STD0_RAM flip syndrome bits on write. */
        uint64_t std0_ram_cdis         : 1;  /**< [ 31: 31](R/W) STD0_RAM ECC correction disable. */
        uint64_t wt_ram_flip           : 2;  /**< [ 30: 29](R/W) WT_RAM flip syndrome bits on write. */
        uint64_t wt_ram_cdis           : 1;  /**< [ 28: 28](R/W) WT_RAM ECC correction disable. */
        uint64_t sc_ram_flip           : 2;  /**< [ 27: 26](R/W) SC_RAM flip syndrome bits on write. */
        uint64_t sc_ram_cdis           : 1;  /**< [ 25: 25](R/W) SC_RAM ECC correction disable. */
        uint64_t reserved_0_24         : 25;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_24         : 25;
        uint64_t sc_ram_cdis           : 1;  /**< [ 25: 25](R/W) SC_RAM ECC correction disable. */
        uint64_t sc_ram_flip           : 2;  /**< [ 27: 26](R/W) SC_RAM flip syndrome bits on write. */
        uint64_t wt_ram_cdis           : 1;  /**< [ 28: 28](R/W) WT_RAM ECC correction disable. */
        uint64_t wt_ram_flip           : 2;  /**< [ 30: 29](R/W) WT_RAM flip syndrome bits on write. */
        uint64_t std0_ram_cdis         : 1;  /**< [ 31: 31](R/W) STD0_RAM ECC correction disable. */
        uint64_t std0_ram_flip         : 2;  /**< [ 33: 32](R/W) STD0_RAM flip syndrome bits on write. */
        uint64_t reserved_34_36        : 3;
        uint64_t sts0_ram_cdis         : 1;  /**< [ 37: 37](R/W) STS0_RAM ECC correction disable. */
        uint64_t sts0_ram_flip         : 2;  /**< [ 39: 38](R/W) STS0_RAM flip syndrome bits on write. */
        uint64_t reserved_40_42        : 3;
        uint64_t tp0_sram_cdis         : 1;  /**< [ 43: 43](R/W) TP0_SRAM ECC correction disable. */
        uint64_t tp0_sram_flip         : 2;  /**< [ 45: 44](R/W) TP0_SRAM flip syndrome bits on write. */
        uint64_t reserved_46_48        : 3;
        uint64_t tw0_cmd_fifo_ram_cdis : 1;  /**< [ 49: 49](R/W) TW0_CMD_FIFO_RAM ECC correction disable. */
        uint64_t tw0_cmd_fifo_ram_flip : 2;  /**< [ 51: 50](R/W) TW0_CMD_FIFO_RAM flip syndrome bits on write. */
        uint64_t reserved_52_54        : 3;
        uint64_t rt_ram_cdis           : 1;  /**< [ 55: 55](R/W) RT_RAM ECC correction disable. */
        uint64_t rt_ram_flip           : 2;  /**< [ 57: 56](R/W) RT_RAM flip syndrome bits on write. */
        uint64_t sq_nt_ram_cdis        : 1;  /**< [ 58: 58](R/W) SQ_NT_RAM ECC correction disable. */
        uint64_t sq_nt_ram_flip        : 2;  /**< [ 60: 59](R/W) SQ_NT_RAM flip syndrome bits on write. */
        uint64_t sq_pt_ram_cdis        : 1;  /**< [ 61: 61](R/W) SQ_PT_RAM ECC correction disable. */
        uint64_t sq_pt_ram_flip        : 2;  /**< [ 63: 62](R/W) SQ_PT_RAM flip syndrome bits on write. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pse_sq2_ecc_ctl0_s cn; */
} bdk_pko_pse_sq2_ecc_ctl0_t;

#define BDK_PKO_PSE_SQ2_ECC_CTL0 BDK_PKO_PSE_SQ2_ECC_CTL0_FUNC()
static inline uint64_t BDK_PKO_PSE_SQ2_ECC_CTL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PSE_SQ2_ECC_CTL0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000100100ll;
    __bdk_csr_fatal("PKO_PSE_SQ2_ECC_CTL0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PSE_SQ2_ECC_CTL0 bdk_pko_pse_sq2_ecc_ctl0_t
#define bustype_BDK_PKO_PSE_SQ2_ECC_CTL0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PSE_SQ2_ECC_CTL0 "PKO_PSE_SQ2_ECC_CTL0"
#define device_bar_BDK_PKO_PSE_SQ2_ECC_CTL0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PSE_SQ2_ECC_CTL0 0
#define arguments_BDK_PKO_PSE_SQ2_ECC_CTL0 -1,-1,-1,-1

/**
 * Register (NCB) pko_pse_sq3_bist_status
 *
 * PSE SQ3 BIST Status Information Register
 * Each bit is the BIST result of an individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pse_sq3_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t sc_sram               : 1;  /**< [ 28: 28](RO) Scheduling configuration. */
        uint64_t reserved_20_27        : 8;
        uint64_t tp0_sram              : 1;  /**< [ 19: 19](RO) SQ[5:1] topology parent configuration. */
        uint64_t reserved_18           : 1;
        uint64_t rt_sram               : 1;  /**< [ 17: 17](RO) Result table. */
        uint64_t reserved_8_16         : 9;
        uint64_t std_sram              : 1;  /**< [  7:  7](RO) Dynamic shaping state. */
        uint64_t sts_sram              : 1;  /**< [  6:  6](RO) Static shaping configuration. */
        uint64_t tw0_cmd_fifo          : 1;  /**< [  5:  5](RO) SQ[5:1] time wheel 0 command FIFO SRAM. */
        uint64_t reserved_3_4          : 2;
        uint64_t nt_sram               : 1;  /**< [  2:  2](RO) Next pointer table. */
        uint64_t pt_sram               : 1;  /**< [  1:  1](RO) Previous pointer table. */
        uint64_t wt_sram               : 1;  /**< [  0:  0](RO) Work table. */
#else /* Word 0 - Little Endian */
        uint64_t wt_sram               : 1;  /**< [  0:  0](RO) Work table. */
        uint64_t pt_sram               : 1;  /**< [  1:  1](RO) Previous pointer table. */
        uint64_t nt_sram               : 1;  /**< [  2:  2](RO) Next pointer table. */
        uint64_t reserved_3_4          : 2;
        uint64_t tw0_cmd_fifo          : 1;  /**< [  5:  5](RO) SQ[5:1] time wheel 0 command FIFO SRAM. */
        uint64_t sts_sram              : 1;  /**< [  6:  6](RO) Static shaping configuration. */
        uint64_t std_sram              : 1;  /**< [  7:  7](RO) Dynamic shaping state. */
        uint64_t reserved_8_16         : 9;
        uint64_t rt_sram               : 1;  /**< [ 17: 17](RO) Result table. */
        uint64_t reserved_18           : 1;
        uint64_t tp0_sram              : 1;  /**< [ 19: 19](RO) SQ[5:1] topology parent configuration. */
        uint64_t reserved_20_27        : 8;
        uint64_t sc_sram               : 1;  /**< [ 28: 28](RO) Scheduling configuration. */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pse_sq3_bist_status_s cn; */
} bdk_pko_pse_sq3_bist_status_t;

#define BDK_PKO_PSE_SQ3_BIST_STATUS BDK_PKO_PSE_SQ3_BIST_STATUS_FUNC()
static inline uint64_t BDK_PKO_PSE_SQ3_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PSE_SQ3_BIST_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000180138ll;
    __bdk_csr_fatal("PKO_PSE_SQ3_BIST_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PSE_SQ3_BIST_STATUS bdk_pko_pse_sq3_bist_status_t
#define bustype_BDK_PKO_PSE_SQ3_BIST_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PSE_SQ3_BIST_STATUS "PKO_PSE_SQ3_BIST_STATUS"
#define device_bar_BDK_PKO_PSE_SQ3_BIST_STATUS 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PSE_SQ3_BIST_STATUS 0
#define arguments_BDK_PKO_PSE_SQ3_BIST_STATUS -1,-1,-1,-1

/**
 * Register (NCB) pko_pse_sq3_ecc_ctl0
 *
 * PKO PSE SQ3 RAM ECC Control Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_pse_sq3_ecc_ctl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t sq_pt_ram_flip        : 2;  /**< [ 63: 62](R/W) SQ_PT_RAM flip syndrome bits on write. */
        uint64_t sq_pt_ram_cdis        : 1;  /**< [ 61: 61](R/W) SQ_PT_RAM ECC correction disable. */
        uint64_t sq_nt_ram_flip        : 2;  /**< [ 60: 59](R/W) SQ_NT_RAM flip syndrome bits on write. */
        uint64_t sq_nt_ram_cdis        : 1;  /**< [ 58: 58](R/W) SQ_NT_RAM ECC correction disable. */
        uint64_t rt_ram_flip           : 2;  /**< [ 57: 56](R/W) RT_RAM flip syndrome bits on write. */
        uint64_t rt_ram_cdis           : 1;  /**< [ 55: 55](R/W) RT_RAM ECC correction disable. */
        uint64_t reserved_46_54        : 9;
        uint64_t tw0_cmd_fifo_ram_flip : 2;  /**< [ 45: 44](R/W) TW0_CMD_FIFO_RAM flip syndrome bits on write. */
        uint64_t tw0_cmd_fifo_ram_cdis : 1;  /**< [ 43: 43](R/W) TW0_CMD_FIFO_RAM ECC correction disable. */
        uint64_t reserved_34_42        : 9;
        uint64_t tp0_sram_flip         : 2;  /**< [ 33: 32](R/W) TP0_SRAM flip syndrome bits on write. */
        uint64_t tp0_sram_cdis         : 1;  /**< [ 31: 31](R/W) TP0_SRAM ECC correction disable. */
        uint64_t reserved_22_30        : 9;
        uint64_t sts0_ram_flip         : 2;  /**< [ 21: 20](R/W) STS0_RAM flip syndrome bits on write. */
        uint64_t sts0_ram_cdis         : 1;  /**< [ 19: 19](R/W) STS0_RAM ECC correction disable. */
        uint64_t reserved_10_18        : 9;
        uint64_t std0_ram_flip         : 2;  /**< [  9:  8](R/W) STD0_RAM flip syndrome bits on write. */
        uint64_t std0_ram_cdis         : 1;  /**< [  7:  7](R/W) STD0_RAM ECC correction disable. */
        uint64_t wt_ram_flip           : 2;  /**< [  6:  5](R/W) WT_RAM flip syndrome bits on write. */
        uint64_t wt_ram_cdis           : 1;  /**< [  4:  4](R/W) WT_RAM ECC correction disable. */
        uint64_t sc_ram_flip           : 2;  /**< [  3:  2](R/W) SC_RAM flip syndrome bits on write. */
        uint64_t sc_ram_cdis           : 1;  /**< [  1:  1](R/W) SC_RAM ECC correction disable. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t sc_ram_cdis           : 1;  /**< [  1:  1](R/W) SC_RAM ECC correction disable. */
        uint64_t sc_ram_flip           : 2;  /**< [  3:  2](R/W) SC_RAM flip syndrome bits on write. */
        uint64_t wt_ram_cdis           : 1;  /**< [  4:  4](R/W) WT_RAM ECC correction disable. */
        uint64_t wt_ram_flip           : 2;  /**< [  6:  5](R/W) WT_RAM flip syndrome bits on write. */
        uint64_t std0_ram_cdis         : 1;  /**< [  7:  7](R/W) STD0_RAM ECC correction disable. */
        uint64_t std0_ram_flip         : 2;  /**< [  9:  8](R/W) STD0_RAM flip syndrome bits on write. */
        uint64_t reserved_10_18        : 9;
        uint64_t sts0_ram_cdis         : 1;  /**< [ 19: 19](R/W) STS0_RAM ECC correction disable. */
        uint64_t sts0_ram_flip         : 2;  /**< [ 21: 20](R/W) STS0_RAM flip syndrome bits on write. */
        uint64_t reserved_22_30        : 9;
        uint64_t tp0_sram_cdis         : 1;  /**< [ 31: 31](R/W) TP0_SRAM ECC correction disable. */
        uint64_t tp0_sram_flip         : 2;  /**< [ 33: 32](R/W) TP0_SRAM flip syndrome bits on write. */
        uint64_t reserved_34_42        : 9;
        uint64_t tw0_cmd_fifo_ram_cdis : 1;  /**< [ 43: 43](R/W) TW0_CMD_FIFO_RAM ECC correction disable. */
        uint64_t tw0_cmd_fifo_ram_flip : 2;  /**< [ 45: 44](R/W) TW0_CMD_FIFO_RAM flip syndrome bits on write. */
        uint64_t reserved_46_54        : 9;
        uint64_t rt_ram_cdis           : 1;  /**< [ 55: 55](R/W) RT_RAM ECC correction disable. */
        uint64_t rt_ram_flip           : 2;  /**< [ 57: 56](R/W) RT_RAM flip syndrome bits on write. */
        uint64_t sq_nt_ram_cdis        : 1;  /**< [ 58: 58](R/W) SQ_NT_RAM ECC correction disable. */
        uint64_t sq_nt_ram_flip        : 2;  /**< [ 60: 59](R/W) SQ_NT_RAM flip syndrome bits on write. */
        uint64_t sq_pt_ram_cdis        : 1;  /**< [ 61: 61](R/W) SQ_PT_RAM ECC correction disable. */
        uint64_t sq_pt_ram_flip        : 2;  /**< [ 63: 62](R/W) SQ_PT_RAM flip syndrome bits on write. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_pse_sq3_ecc_ctl0_s cn; */
} bdk_pko_pse_sq3_ecc_ctl0_t;

#define BDK_PKO_PSE_SQ3_ECC_CTL0 BDK_PKO_PSE_SQ3_ECC_CTL0_FUNC()
static inline uint64_t BDK_PKO_PSE_SQ3_ECC_CTL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PSE_SQ3_ECC_CTL0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000180100ll;
    __bdk_csr_fatal("PKO_PSE_SQ3_ECC_CTL0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PSE_SQ3_ECC_CTL0 bdk_pko_pse_sq3_ecc_ctl0_t
#define bustype_BDK_PKO_PSE_SQ3_ECC_CTL0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PSE_SQ3_ECC_CTL0 "PKO_PSE_SQ3_ECC_CTL0"
#define device_bar_BDK_PKO_PSE_SQ3_ECC_CTL0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PSE_SQ3_ECC_CTL0 0
#define arguments_BDK_PKO_PSE_SQ3_ECC_CTL0 -1,-1,-1,-1

/**
 * Register (NCB) pko_ptf#_status
 *
 * PKO TX FIFO / MAC Translation Status Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_ptfx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t tx_fifo_pkt_credit_cnt : 10;/**< [ 29: 20](RO/H) The number of used TxFIFO credits. For diagnostic use only. */
        uint64_t total_in_flight_cnt   : 8;  /**< [ 19: 12](RO/H) Total number of packets currently in-flight within PEB. Useful both for reconfiguration
                                                                 (able to disable a FIFO when it is empty) and debugging. */
        uint64_t in_flight_cnt         : 7;  /**< [ 11:  5](RO/H) Number of packets currently in-flight within PEB for this link. Useful both for
                                                                 reconfiguration (able to disable a FIFO when it is empty) and debugging. */
        uint64_t mac_num               : 5;  /**< [  4:  0](RO/H) MAC assigned to the given PKO TX FIFO. A value of 0x1F means unassigned. These register
                                                                 values are derived automatically by the hardware from the PKO_MAC()_CFG[FIFO_NUM]
                                                                 settings. */
#else /* Word 0 - Little Endian */
        uint64_t mac_num               : 5;  /**< [  4:  0](RO/H) MAC assigned to the given PKO TX FIFO. A value of 0x1F means unassigned. These register
                                                                 values are derived automatically by the hardware from the PKO_MAC()_CFG[FIFO_NUM]
                                                                 settings. */
        uint64_t in_flight_cnt         : 7;  /**< [ 11:  5](RO/H) Number of packets currently in-flight within PEB for this link. Useful both for
                                                                 reconfiguration (able to disable a FIFO when it is empty) and debugging. */
        uint64_t total_in_flight_cnt   : 8;  /**< [ 19: 12](RO/H) Total number of packets currently in-flight within PEB. Useful both for reconfiguration
                                                                 (able to disable a FIFO when it is empty) and debugging. */
        uint64_t tx_fifo_pkt_credit_cnt : 10;/**< [ 29: 20](RO/H) The number of used TxFIFO credits. For diagnostic use only. */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_ptfx_status_s cn; */
} bdk_pko_ptfx_status_t;

static inline uint64_t BDK_PKO_PTFX_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PTFX_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=19))
        return 0x854000900100ll + 8ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_PTFX_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_PTFX_STATUS(a) bdk_pko_ptfx_status_t
#define bustype_BDK_PKO_PTFX_STATUS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PTFX_STATUS(a) "PKO_PTFX_STATUS"
#define device_bar_BDK_PKO_PTFX_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PTFX_STATUS(a) (a)
#define arguments_BDK_PKO_PTFX_STATUS(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_ptf_iobp_cfg
 *
 * PKO IOBP Interface Configuration Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_ptf_iobp_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t iobp1_ds_opt          : 1;  /**< [ 63: 63](R/W) Optimize IOBP1 requests when data is to be dropped (NULL, RED, SEND_HDR_S[DS]=1). */
        uint64_t iobp0_l2_allocate     : 1;  /**< [ 62: 62](R/W) Determine L2 allocation (1 = no allocation = LDT, 0 = allocation = LDD) when reading
                                                                 post-PKO_SEND_JUMP_S descriptors via IOBP0 requests. */
        uint64_t reserved_49_61        : 13;
        uint64_t iobp1_magic_addr      : 42; /**< [ 48:  7](R/W) IOBP1 read address to be used for any dummy reads */
        uint64_t max_read_size         : 7;  /**< [  6:  0](R/W) Maximum number of IOBP1 read requests outstanding to be allowed by any given PEB TX FIFO. */
#else /* Word 0 - Little Endian */
        uint64_t max_read_size         : 7;  /**< [  6:  0](R/W) Maximum number of IOBP1 read requests outstanding to be allowed by any given PEB TX FIFO. */
        uint64_t iobp1_magic_addr      : 42; /**< [ 48:  7](R/W) IOBP1 read address to be used for any dummy reads */
        uint64_t reserved_49_61        : 13;
        uint64_t iobp0_l2_allocate     : 1;  /**< [ 62: 62](R/W) Determine L2 allocation (1 = no allocation = LDT, 0 = allocation = LDD) when reading
                                                                 post-PKO_SEND_JUMP_S descriptors via IOBP0 requests. */
        uint64_t iobp1_ds_opt          : 1;  /**< [ 63: 63](R/W) Optimize IOBP1 requests when data is to be dropped (NULL, RED, SEND_HDR_S[DS]=1). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_ptf_iobp_cfg_s cn; */
} bdk_pko_ptf_iobp_cfg_t;

#define BDK_PKO_PTF_IOBP_CFG BDK_PKO_PTF_IOBP_CFG_FUNC()
static inline uint64_t BDK_PKO_PTF_IOBP_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PTF_IOBP_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000900300ll;
    __bdk_csr_fatal("PKO_PTF_IOBP_CFG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_PTF_IOBP_CFG bdk_pko_ptf_iobp_cfg_t
#define bustype_BDK_PKO_PTF_IOBP_CFG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PTF_IOBP_CFG "PKO_PTF_IOBP_CFG"
#define device_bar_BDK_PKO_PTF_IOBP_CFG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PTF_IOBP_CFG 0
#define arguments_BDK_PKO_PTF_IOBP_CFG -1,-1,-1,-1

/**
 * Register (NCB) pko_ptgf#_cfg
 *
 * PKO TX FIFO Groups Configuration Register
 * This register configures a PKO TX FIFO group. PKO supports up to 21 independent
 * TX FIFOs, where 0-19 are physical and 20 is Virtual/NULL. (PKO drops packets
 * targeting the NULL FIFO, returning their buffers to the FPA.) PKO puts each
 * FIFO into one of five groups:
 *
 * <pre>
 *    CSR Name       FIFO's in FIFO Group
 *   ------------------------------------
 *   PKO_PTGF0_CFG      0,  1,  2,  3
 *   PKO_PTGF1_CFG      4,  5,  6,  7
 *   PKO_PTGF2_CFG      8,  9, 10, 11
 *   PKO_PTGF3_CFG     12, 13, 14, 15
 *   PKO_PTGF4_CFG     16, 17, 18, 19
 *   PKO_PTGF5_CFG      Virtual/NULL
 * </pre>
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_ptgfx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t reset                 : 1;  /**< [  6:  6](R/W) This bit resets the address pointers for the FIFOs in this group. This should only be
                                                                 performed when a PTGF is empty and the SIZE field is to be changed. */
        uint64_t reserved_5            : 1;
        uint64_t rate                  : 2;  /**< [  4:  3](R/W) The rate / number of inflight packets allowed for the FIFO's in this group.
                                                                 An individual FIFO can support up to 50 Gbit/sec (i.e. up to 48 inflight packets).
                                                                 The total aggregate rate across all FIFOs (including the NULL) should never exceed
                                                                 125 Gbit/sec (i.e. up to 80 inflight packets). This field represents the rate for
                                                                 each active FIFO in in the group; thus the calculation for throughput is a function
                                                                 of the SIZE field and whether or not the FIFO's in the group are assigned to a MAC
                                                                 in PKO_MAC()_CFG.

                                                                 Encoding:
                                                                 0x0 = up to   6.25 Gbit/sec (i.e. up to  6 inflight packets)
                                                                 0x1 = up to  12.5  Gbit/sec (i.e. up to 12 inflight packets)
                                                                 0x2 = up to  25    Gbit/sec (i.e. up to 24 inflight packets)
                                                                 0x3 = up to  50    Gbit/sec (i.e. up to 48 inflight packets)

                                                                 [RATE] applies to all FIFO groups including the NULL. */
        uint64_t size                  : 3;  /**< [  2:  0](R/W) Determines the size and availability of the FIFOs in the FIFO group.
                                                                 10 KB total storage is available to the FIFO group. Two or
                                                                 four FIFOs can be combined to produce a larger FIFO if desired.

                                                                 The supported SIZE values:

                                                                 <pre>
                                                                           FIFO0    FIFO1    FIFO2    FIFO3
                                                                    SIZE   Size     Size     Size     Size
                                                                   --------------------------------------
                                                                     0     2.5 KB   2.5 KB   2.5 KB   2.5 KB
                                                                     1     5.0 KB    N/A     2.5 KB   2.5 KB
                                                                     2     2.5 KB   2.5 KB   5.0 KB    N/A
                                                                     3     5.0 KB    N/A     5.0 KB    N/A
                                                                     4    10.0 KB    N/A      N/A      N/A
                                                                 </pre>

                                                                 Note: 5-7 are illegal [SIZE] values and should not be used.

                                                                 A FIFO labelled N/A in the above table must not be used, and no
                                                                 PKO_MAC()_CFG[FIFO_NUM] should select it. For example,
                                                                 if PKO_PTGF(2)_CFG[SIZE]=4, FIFO_NUM 8 is available (with
                                                                 10KB), but FIFO_NUMs 9, 10, and 11 are not valid and should
                                                                 not be used.

                                                                 Modifications to this field require two writes. The first
                                                                 write must not modify [SIZE], and must assert [RESET] to
                                                                 reset the address pointers for the FIFOs in this group.
                                                                 The second write has the new [SIZE] value, and should clear
                                                                 [RESET].

                                                                 PKO_PTGF(5)_CFG[SIZE] should not change from its reset value
                                                                 of zero. (The NULL FIFO has no real storage, and the SIZE table
                                                                 above does not apply to the NULL FIFO.)

                                                                 A FIFO of size 2.5 KB cannot be configured to have a [RATE] > 25 GBs.
                                                                 A FIFO of size 5.0 KB cannot be configured to have a [RATE] > 50 GBs. */
#else /* Word 0 - Little Endian */
        uint64_t size                  : 3;  /**< [  2:  0](R/W) Determines the size and availability of the FIFOs in the FIFO group.
                                                                 10 KB total storage is available to the FIFO group. Two or
                                                                 four FIFOs can be combined to produce a larger FIFO if desired.

                                                                 The supported SIZE values:

                                                                 <pre>
                                                                           FIFO0    FIFO1    FIFO2    FIFO3
                                                                    SIZE   Size     Size     Size     Size
                                                                   --------------------------------------
                                                                     0     2.5 KB   2.5 KB   2.5 KB   2.5 KB
                                                                     1     5.0 KB    N/A     2.5 KB   2.5 KB
                                                                     2     2.5 KB   2.5 KB   5.0 KB    N/A
                                                                     3     5.0 KB    N/A     5.0 KB    N/A
                                                                     4    10.0 KB    N/A      N/A      N/A
                                                                 </pre>

                                                                 Note: 5-7 are illegal [SIZE] values and should not be used.

                                                                 A FIFO labelled N/A in the above table must not be used, and no
                                                                 PKO_MAC()_CFG[FIFO_NUM] should select it. For example,
                                                                 if PKO_PTGF(2)_CFG[SIZE]=4, FIFO_NUM 8 is available (with
                                                                 10KB), but FIFO_NUMs 9, 10, and 11 are not valid and should
                                                                 not be used.

                                                                 Modifications to this field require two writes. The first
                                                                 write must not modify [SIZE], and must assert [RESET] to
                                                                 reset the address pointers for the FIFOs in this group.
                                                                 The second write has the new [SIZE] value, and should clear
                                                                 [RESET].

                                                                 PKO_PTGF(5)_CFG[SIZE] should not change from its reset value
                                                                 of zero. (The NULL FIFO has no real storage, and the SIZE table
                                                                 above does not apply to the NULL FIFO.)

                                                                 A FIFO of size 2.5 KB cannot be configured to have a [RATE] > 25 GBs.
                                                                 A FIFO of size 5.0 KB cannot be configured to have a [RATE] > 50 GBs. */
        uint64_t rate                  : 2;  /**< [  4:  3](R/W) The rate / number of inflight packets allowed for the FIFO's in this group.
                                                                 An individual FIFO can support up to 50 Gbit/sec (i.e. up to 48 inflight packets).
                                                                 The total aggregate rate across all FIFOs (including the NULL) should never exceed
                                                                 125 Gbit/sec (i.e. up to 80 inflight packets). This field represents the rate for
                                                                 each active FIFO in in the group; thus the calculation for throughput is a function
                                                                 of the SIZE field and whether or not the FIFO's in the group are assigned to a MAC
                                                                 in PKO_MAC()_CFG.

                                                                 Encoding:
                                                                 0x0 = up to   6.25 Gbit/sec (i.e. up to  6 inflight packets)
                                                                 0x1 = up to  12.5  Gbit/sec (i.e. up to 12 inflight packets)
                                                                 0x2 = up to  25    Gbit/sec (i.e. up to 24 inflight packets)
                                                                 0x3 = up to  50    Gbit/sec (i.e. up to 48 inflight packets)

                                                                 [RATE] applies to all FIFO groups including the NULL. */
        uint64_t reserved_5            : 1;
        uint64_t reset                 : 1;  /**< [  6:  6](R/W) This bit resets the address pointers for the FIFOs in this group. This should only be
                                                                 performed when a PTGF is empty and the SIZE field is to be changed. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_ptgfx_cfg_s cn; */
} bdk_pko_ptgfx_cfg_t;

static inline uint64_t BDK_PKO_PTGFX_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_PTGFX_CFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x854000900200ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("PKO_PTGFX_CFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_PTGFX_CFG(a) bdk_pko_ptgfx_cfg_t
#define bustype_BDK_PKO_PTGFX_CFG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_PTGFX_CFG(a) "PKO_PTGFX_CFG"
#define device_bar_BDK_PKO_PTGFX_CFG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_PTGFX_CFG(a) (a)
#define arguments_BDK_PKO_PTGFX_CFG(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_shaper_cfg
 *
 * PKO PSE Shaper Configuration Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_shaper_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t color_aware           : 1;  /**< [  1:  1](R/W) Color aware. Selects whether or not the PSE shapers take into account
                                                                 the color of the incoming packet.
                                                                 0 = Color blind.
                                                                 1 = Color aware. */
        uint64_t red_send_as_yellow    : 1;  /**< [  0:  0](R/W) RED_SEND as YELLOW. Configures the way packets colored RED_SEND are
                                                                 handled by the DQ through L2 shapers when operating in [COLOR_AWARE] mode.
                                                                 Normally packets colored RED_DROP do not decrement the PIR in DQ through
                                                                 L2 shapers while packets colored YELLOW do.  (Neither RED_DROP nor
                                                                 YELLOW packets decrement the CIR in DQ through L2 shapers.)  Packets colored
                                                                 RED_SEND are treated as either RED_DROP or YELLOW in the DQ through L2 shapers
                                                                 as follows:
                                                                 0 = treat RED_SEND as RED_DROP.
                                                                 1 = treat RED_SEND as YELLOW.

                                                                 In the L1 shapers, RED_DROP packets do not decrement the CIR, while YELLOW do.
                                                                 RED_SEND packets are always treated the same as YELLOW is in the L1 shapers,
                                                                 irrespective of [RED_SEND_AS_YELLOW]. */
#else /* Word 0 - Little Endian */
        uint64_t red_send_as_yellow    : 1;  /**< [  0:  0](R/W) RED_SEND as YELLOW. Configures the way packets colored RED_SEND are
                                                                 handled by the DQ through L2 shapers when operating in [COLOR_AWARE] mode.
                                                                 Normally packets colored RED_DROP do not decrement the PIR in DQ through
                                                                 L2 shapers while packets colored YELLOW do.  (Neither RED_DROP nor
                                                                 YELLOW packets decrement the CIR in DQ through L2 shapers.)  Packets colored
                                                                 RED_SEND are treated as either RED_DROP or YELLOW in the DQ through L2 shapers
                                                                 as follows:
                                                                 0 = treat RED_SEND as RED_DROP.
                                                                 1 = treat RED_SEND as YELLOW.

                                                                 In the L1 shapers, RED_DROP packets do not decrement the CIR, while YELLOW do.
                                                                 RED_SEND packets are always treated the same as YELLOW is in the L1 shapers,
                                                                 irrespective of [RED_SEND_AS_YELLOW]. */
        uint64_t color_aware           : 1;  /**< [  1:  1](R/W) Color aware. Selects whether or not the PSE shapers take into account
                                                                 the color of the incoming packet.
                                                                 0 = Color blind.
                                                                 1 = Color aware. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_shaper_cfg_s cn; */
} bdk_pko_shaper_cfg_t;

#define BDK_PKO_SHAPER_CFG BDK_PKO_SHAPER_CFG_FUNC()
static inline uint64_t BDK_PKO_SHAPER_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_SHAPER_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8540000800f8ll;
    __bdk_csr_fatal("PKO_SHAPER_CFG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_SHAPER_CFG bdk_pko_shaper_cfg_t
#define bustype_BDK_PKO_SHAPER_CFG BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_SHAPER_CFG "PKO_SHAPER_CFG"
#define device_bar_BDK_PKO_SHAPER_CFG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_SHAPER_CFG 0
#define arguments_BDK_PKO_SHAPER_CFG -1,-1,-1,-1

/**
 * Register (NCB) pko_state_uid_in_use#_rd
 *
 * INTERNAL: PKO PEB State Memory Allocation Read Register
 *
 * For diagnostic use only.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_state_uid_in_usex_rd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t in_use                : 64; /**< [ 63:  0](RO/H) When set, a state memory bucket (aka UID) is assigned. */
#else /* Word 0 - Little Endian */
        uint64_t in_use                : 64; /**< [ 63:  0](RO/H) When set, a state memory bucket (aka UID) is assigned. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_state_uid_in_usex_rd_s cn; */
} bdk_pko_state_uid_in_usex_rd_t;

static inline uint64_t BDK_PKO_STATE_UID_IN_USEX_RD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_STATE_UID_IN_USEX_RD(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x854000900f00ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("PKO_STATE_UID_IN_USEX_RD", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_STATE_UID_IN_USEX_RD(a) bdk_pko_state_uid_in_usex_rd_t
#define bustype_BDK_PKO_STATE_UID_IN_USEX_RD(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_STATE_UID_IN_USEX_RD(a) "PKO_STATE_UID_IN_USEX_RD"
#define device_bar_BDK_PKO_STATE_UID_IN_USEX_RD(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_STATE_UID_IN_USEX_RD(a) (a)
#define arguments_BDK_PKO_STATE_UID_IN_USEX_RD(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_status
 *
 * PKO Global Status Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pko_rdy               : 1;  /**< [ 63: 63](RO/H) PKO ready for configuration. */
        uint64_t reserved_24_62        : 39;
        uint64_t c2qlut_rdy            : 1;  /**< [ 23: 23](RO/H) PKO C2Q LUT block ready for configuration. */
        uint64_t ppfi_rdy              : 1;  /**< [ 22: 22](RO/H) PKO PPFI block ready for configuration. */
        uint64_t iobp1_rdy             : 1;  /**< [ 21: 21](RO/H) PKO IOBP1 block ready for configuration. */
        uint64_t ncb_rdy               : 1;  /**< [ 20: 20](RO/H) PKO NCB block ready for configuration. */
        uint64_t pse_rdy               : 1;  /**< [ 19: 19](RO/H) PKO PSE block ready for configuration. */
        uint64_t pdm_rdy               : 1;  /**< [ 18: 18](RO/H) PKO PDM block ready for configuration. */
        uint64_t peb_rdy               : 1;  /**< [ 17: 17](RO/H) PKO PEB block ready for configuration. */
        uint64_t csi_rdy               : 1;  /**< [ 16: 16](RO/H) PKO CSI block ready for configuration. */
        uint64_t reserved_5_15         : 11;
        uint64_t ncb_bist_status       : 1;  /**< [  4:  4](RO) PKO NCB block BIST status. 0 = BIST passed; 1 = BIST failed. */
        uint64_t c2qlut_bist_status    : 1;  /**< [  3:  3](RO) PKO C2QLUT block BIST status. 0 = BIST passed; 1 = BIST failed. */
        uint64_t pdm_bist_status       : 1;  /**< [  2:  2](RO) PKO PDM block BIST status. 0 = BIST passed; 1 = BIST failed. */
        uint64_t peb_bist_status       : 1;  /**< [  1:  1](RO) PKO PEB block BIST status. 0 = BIST passed; 1 = BIST failed. */
        uint64_t pse_bist_status       : 1;  /**< [  0:  0](RO) PKO PSE block BIST status. 0 = BIST passed; 1 = BIST failed. */
#else /* Word 0 - Little Endian */
        uint64_t pse_bist_status       : 1;  /**< [  0:  0](RO) PKO PSE block BIST status. 0 = BIST passed; 1 = BIST failed. */
        uint64_t peb_bist_status       : 1;  /**< [  1:  1](RO) PKO PEB block BIST status. 0 = BIST passed; 1 = BIST failed. */
        uint64_t pdm_bist_status       : 1;  /**< [  2:  2](RO) PKO PDM block BIST status. 0 = BIST passed; 1 = BIST failed. */
        uint64_t c2qlut_bist_status    : 1;  /**< [  3:  3](RO) PKO C2QLUT block BIST status. 0 = BIST passed; 1 = BIST failed. */
        uint64_t ncb_bist_status       : 1;  /**< [  4:  4](RO) PKO NCB block BIST status. 0 = BIST passed; 1 = BIST failed. */
        uint64_t reserved_5_15         : 11;
        uint64_t csi_rdy               : 1;  /**< [ 16: 16](RO/H) PKO CSI block ready for configuration. */
        uint64_t peb_rdy               : 1;  /**< [ 17: 17](RO/H) PKO PEB block ready for configuration. */
        uint64_t pdm_rdy               : 1;  /**< [ 18: 18](RO/H) PKO PDM block ready for configuration. */
        uint64_t pse_rdy               : 1;  /**< [ 19: 19](RO/H) PKO PSE block ready for configuration. */
        uint64_t ncb_rdy               : 1;  /**< [ 20: 20](RO/H) PKO NCB block ready for configuration. */
        uint64_t iobp1_rdy             : 1;  /**< [ 21: 21](RO/H) PKO IOBP1 block ready for configuration. */
        uint64_t ppfi_rdy              : 1;  /**< [ 22: 22](RO/H) PKO PPFI block ready for configuration. */
        uint64_t c2qlut_rdy            : 1;  /**< [ 23: 23](RO/H) PKO C2Q LUT block ready for configuration. */
        uint64_t reserved_24_62        : 39;
        uint64_t pko_rdy               : 1;  /**< [ 63: 63](RO/H) PKO ready for configuration. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_status_s cn; */
} bdk_pko_status_t;

#define BDK_PKO_STATUS BDK_PKO_STATUS_FUNC()
static inline uint64_t BDK_PKO_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x854000d00000ll;
    __bdk_csr_fatal("PKO_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKO_STATUS bdk_pko_status_t
#define bustype_BDK_PKO_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_STATUS "PKO_STATUS"
#define device_bar_BDK_PKO_STATUS 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_STATUS 0
#define arguments_BDK_PKO_STATUS -1,-1,-1,-1

/**
 * Register (NCB) pko_txf#_pkt_cnt_rd
 *
 * PKO TX FIFO Packet Counter Read Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_txfx_pkt_cnt_rd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t cnt                   : 8;  /**< [  7:  0](RO/H) Number of packets currently sitting in the given TX FIFO. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 8;  /**< [  7:  0](RO/H) Number of packets currently sitting in the given TX FIFO. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_txfx_pkt_cnt_rd_s cn; */
} bdk_pko_txfx_pkt_cnt_rd_t;

static inline uint64_t BDK_PKO_TXFX_PKT_CNT_RD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_TXFX_PKT_CNT_RD(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=19))
        return 0x854000900e00ll + 8ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_TXFX_PKT_CNT_RD", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_TXFX_PKT_CNT_RD(a) bdk_pko_txfx_pkt_cnt_rd_t
#define bustype_BDK_PKO_TXFX_PKT_CNT_RD(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_TXFX_PKT_CNT_RD(a) "PKO_TXFX_PKT_CNT_RD"
#define device_bar_BDK_PKO_TXFX_PKT_CNT_RD(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_TXFX_PKT_CNT_RD(a) (a)
#define arguments_BDK_PKO_TXFX_PKT_CNT_RD(a) (a),-1,-1,-1

/**
 * Register (NCB) pko_vf#_dq#_fc_status
 *
 * PKO DQ Flow Control Status Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_vfx_dqx_fc_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t count                 : 36; /**< [ 35:  0](R/W/H) Watermark buffer count. The number of buffers allocated (from
                                                                 FPA aura PKO_DPFI_FPA_AURA[NODE,LAURA]) for this DQ.  When enabled to
                                                                 do so, PKO stores this value minus PKO_PDM_CFG[DQ_FC_SKID] to L2/DRAM
                                                                 for flow control purposes as a signed 64-bit integer.  See
                                                                 PKO_VF()_DQ_FC_CONFIG for more details. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 36; /**< [ 35:  0](R/W/H) Watermark buffer count. The number of buffers allocated (from
                                                                 FPA aura PKO_DPFI_FPA_AURA[NODE,LAURA]) for this DQ.  When enabled to
                                                                 do so, PKO stores this value minus PKO_PDM_CFG[DQ_FC_SKID] to L2/DRAM
                                                                 for flow control purposes as a signed 64-bit integer.  See
                                                                 PKO_VF()_DQ_FC_CONFIG for more details. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_vfx_dqx_fc_status_s cn; */
} bdk_pko_vfx_dqx_fc_status_t;

static inline uint64_t BDK_PKO_VFX_DQX_FC_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_VFX_DQX_FC_STATUS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=7)))
        return 0x854400000168ll + 0x100000ll * ((a) & 0x1f) + 0x20000ll * ((b) & 0x7);
    __bdk_csr_fatal("PKO_VFX_DQX_FC_STATUS", 2, a, b, 0, 0);
}

#define typedef_BDK_PKO_VFX_DQX_FC_STATUS(a,b) bdk_pko_vfx_dqx_fc_status_t
#define bustype_BDK_PKO_VFX_DQX_FC_STATUS(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_VFX_DQX_FC_STATUS(a,b) "PKO_VFX_DQX_FC_STATUS"
#define device_bar_BDK_PKO_VFX_DQX_FC_STATUS(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_PKO_VFX_DQX_FC_STATUS(a,b) (a)
#define arguments_BDK_PKO_VFX_DQX_FC_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pko_vf#_dq#_mp_state#
 *
 * PKO Packet Meta-packet-descriptor State Per DQ Access Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_vfx_dqx_mp_statex_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) This is the internal state for meta-packet per each DQ. It can be accessed for
                                                                 debug or for software to cleanup/clear the state after a memory error.

                                                                 Warning that this will modify internal state. It must not be changed while DQ is
                                                                 active or system will need to be reset. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) This is the internal state for meta-packet per each DQ. It can be accessed for
                                                                 debug or for software to cleanup/clear the state after a memory error.

                                                                 Warning that this will modify internal state. It must not be changed while DQ is
                                                                 active or system will need to be reset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_vfx_dqx_mp_statex_s cn; */
} bdk_pko_vfx_dqx_mp_statex_t;

static inline uint64_t BDK_PKO_VFX_DQX_MP_STATEX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_VFX_DQX_MP_STATEX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=7) && (c<=3)))
        return 0x85407001fe00ll + 0x100000ll * ((a) & 0x1f) + 0x20000ll * ((b) & 0x7) + 8ll * ((c) & 0x3);
    __bdk_csr_fatal("PKO_VFX_DQX_MP_STATEX", 3, a, b, c, 0);
}

#define typedef_BDK_PKO_VFX_DQX_MP_STATEX(a,b,c) bdk_pko_vfx_dqx_mp_statex_t
#define bustype_BDK_PKO_VFX_DQX_MP_STATEX(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_VFX_DQX_MP_STATEX(a,b,c) "PKO_VFX_DQX_MP_STATEX"
#define device_bar_BDK_PKO_VFX_DQX_MP_STATEX(a,b,c) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_VFX_DQX_MP_STATEX(a,b,c) (a)
#define arguments_BDK_PKO_VFX_DQX_MP_STATEX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) pko_vf#_dq#_op_close
 *
 * PKO DQ Close Operation Register
 * Stores or atomic stores of any value initiate a close operation. Reads or atomic reads
 * return status of the operation identical to PKO_DQ()_OP_QUERY.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_vfx_dqx_op_close_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dqstatus              : 4;  /**< [ 63: 60](RO) Indicates the success or failure of the operation, enumerated by PKO_DQSTATUS_E. */
        uint64_t reserved_50_59        : 10;
        uint64_t dqop                  : 2;  /**< [ 49: 48](RO) Indicates the operation that generated the return, enumerated by PKO_DQOP_E. */
        uint64_t depth                 : 48; /**< [ 47:  0](RO) Indicates the depth of the specified DQ in bytes, descriptors, or
                                                                 buffers, as follows:

                                                                 <pre>
                                                                     In PKO_DQ*_WM_CTL
                                                                    /                  \
                                                                   /                    \
                                                                   [KIND] [NCB_QUERY_RSP]  Description of [DEPTH]
                                                                 ------------------------------------------------------------------------------------------
                                                                      X          1         Buffers. [DEPTH] is PKO_DQ()_WM_BUF_CNT[COUNT],
                                                                                           which is the number of buffers consumed by the DQ.

                                                                      0          0         Byte Count. [DEPTH] is PKO_DQ()_WM_CNT[COUNT],
                                                                                           which is the sum of the PKO_META_DESC_S[LENGTH]
                                                                                           stored in the DQ, and of all the PKO_*_PICK[LENGTH]s in
                                                                                           conditioners holding valid metas from the DQ.

                                                                      1          0         Descriptor count. [DEPTH] is PKO_DQ()_WM_CNT[COUNT],
                                                                                           which is the number of descriptors stored in the DQ or from
                                                                                           the DQ and present in a PKO conditioner.
                                                                 </pre> */
#else /* Word 0 - Little Endian */
        uint64_t depth                 : 48; /**< [ 47:  0](RO) Indicates the depth of the specified DQ in bytes, descriptors, or
                                                                 buffers, as follows:

                                                                 <pre>
                                                                     In PKO_DQ*_WM_CTL
                                                                    /                  \
                                                                   /                    \
                                                                   [KIND] [NCB_QUERY_RSP]  Description of [DEPTH]
                                                                 ------------------------------------------------------------------------------------------
                                                                      X          1         Buffers. [DEPTH] is PKO_DQ()_WM_BUF_CNT[COUNT],
                                                                                           which is the number of buffers consumed by the DQ.

                                                                      0          0         Byte Count. [DEPTH] is PKO_DQ()_WM_CNT[COUNT],
                                                                                           which is the sum of the PKO_META_DESC_S[LENGTH]
                                                                                           stored in the DQ, and of all the PKO_*_PICK[LENGTH]s in
                                                                                           conditioners holding valid metas from the DQ.

                                                                      1          0         Descriptor count. [DEPTH] is PKO_DQ()_WM_CNT[COUNT],
                                                                                           which is the number of descriptors stored in the DQ or from
                                                                                           the DQ and present in a PKO conditioner.
                                                                 </pre> */
        uint64_t dqop                  : 2;  /**< [ 49: 48](RO) Indicates the operation that generated the return, enumerated by PKO_DQOP_E. */
        uint64_t reserved_50_59        : 10;
        uint64_t dqstatus              : 4;  /**< [ 63: 60](RO) Indicates the success or failure of the operation, enumerated by PKO_DQSTATUS_E. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_vfx_dqx_op_close_s cn; */
} bdk_pko_vfx_dqx_op_close_t;

static inline uint64_t BDK_PKO_VFX_DQX_OP_CLOSE(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_VFX_DQX_OP_CLOSE(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=7)))
        return 0x854400001200ll + 0x100000ll * ((a) & 0x1f) + 0x20000ll * ((b) & 0x7);
    __bdk_csr_fatal("PKO_VFX_DQX_OP_CLOSE", 2, a, b, 0, 0);
}

#define typedef_BDK_PKO_VFX_DQX_OP_CLOSE(a,b) bdk_pko_vfx_dqx_op_close_t
#define bustype_BDK_PKO_VFX_DQX_OP_CLOSE(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_VFX_DQX_OP_CLOSE(a,b) "PKO_VFX_DQX_OP_CLOSE"
#define device_bar_BDK_PKO_VFX_DQX_OP_CLOSE(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_PKO_VFX_DQX_OP_CLOSE(a,b) (a)
#define arguments_BDK_PKO_VFX_DQX_OP_CLOSE(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pko_vf#_dq#_op_open
 *
 * PKO DQ Open Operation Register
 * Stores or atomic stores of any value initiate an open operation. Reads or atomic reads
 * return status of the operation identical to PKO_DQ()_OP_QUERY.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_vfx_dqx_op_open_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dqstatus              : 4;  /**< [ 63: 60](RO) Indicates the success or failure of the operation, enumerated by PKO_DQSTATUS_E. */
        uint64_t reserved_50_59        : 10;
        uint64_t dqop                  : 2;  /**< [ 49: 48](RO) Indicates the operation that generated the return, enumerated by PKO_DQOP_E. */
        uint64_t depth                 : 48; /**< [ 47:  0](RO) Indicates the depth of the specified DQ in bytes, descriptors, or
                                                                 buffers, as follows:

                                                                 <pre>
                                                                     In PKO_DQ*_WM_CTL
                                                                    /                  \
                                                                   /                    \
                                                                   [KIND] [NCB_QUERY_RSP]  Description of [DEPTH]
                                                                 ------------------------------------------------------------------------------------------
                                                                      X          1         Buffers. [DEPTH] is PKO_DQ()_WM_BUF_CNT[COUNT],
                                                                                           which is the number of buffers consumed by the DQ.

                                                                      0          0         Byte Count. [DEPTH] is PKO_DQ()_WM_CNT[COUNT],
                                                                                           which is the sum of the PKO_META_DESC_S[LENGTH]
                                                                                           stored in the DQ, and of all the PKO_*_PICK[LENGTH]s in
                                                                                           conditioners holding valid metas from the DQ.

                                                                      1          0         Descriptor count. [DEPTH] is PKO_DQ()_WM_CNT[COUNT],
                                                                                           which is the number of descriptors stored in the DQ or from
                                                                                           the DQ and present in a PKO conditioner.
                                                                 </pre> */
#else /* Word 0 - Little Endian */
        uint64_t depth                 : 48; /**< [ 47:  0](RO) Indicates the depth of the specified DQ in bytes, descriptors, or
                                                                 buffers, as follows:

                                                                 <pre>
                                                                     In PKO_DQ*_WM_CTL
                                                                    /                  \
                                                                   /                    \
                                                                   [KIND] [NCB_QUERY_RSP]  Description of [DEPTH]
                                                                 ------------------------------------------------------------------------------------------
                                                                      X          1         Buffers. [DEPTH] is PKO_DQ()_WM_BUF_CNT[COUNT],
                                                                                           which is the number of buffers consumed by the DQ.

                                                                      0          0         Byte Count. [DEPTH] is PKO_DQ()_WM_CNT[COUNT],
                                                                                           which is the sum of the PKO_META_DESC_S[LENGTH]
                                                                                           stored in the DQ, and of all the PKO_*_PICK[LENGTH]s in
                                                                                           conditioners holding valid metas from the DQ.

                                                                      1          0         Descriptor count. [DEPTH] is PKO_DQ()_WM_CNT[COUNT],
                                                                                           which is the number of descriptors stored in the DQ or from
                                                                                           the DQ and present in a PKO conditioner.
                                                                 </pre> */
        uint64_t dqop                  : 2;  /**< [ 49: 48](RO) Indicates the operation that generated the return, enumerated by PKO_DQOP_E. */
        uint64_t reserved_50_59        : 10;
        uint64_t dqstatus              : 4;  /**< [ 63: 60](RO) Indicates the success or failure of the operation, enumerated by PKO_DQSTATUS_E. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_vfx_dqx_op_open_s cn; */
} bdk_pko_vfx_dqx_op_open_t;

static inline uint64_t BDK_PKO_VFX_DQX_OP_OPEN(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_VFX_DQX_OP_OPEN(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=7)))
        return 0x854400001100ll + 0x100000ll * ((a) & 0x1f) + 0x20000ll * ((b) & 0x7);
    __bdk_csr_fatal("PKO_VFX_DQX_OP_OPEN", 2, a, b, 0, 0);
}

#define typedef_BDK_PKO_VFX_DQX_OP_OPEN(a,b) bdk_pko_vfx_dqx_op_open_t
#define bustype_BDK_PKO_VFX_DQX_OP_OPEN(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_VFX_DQX_OP_OPEN(a,b) "PKO_VFX_DQX_OP_OPEN"
#define device_bar_BDK_PKO_VFX_DQX_OP_OPEN(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_PKO_VFX_DQX_OP_OPEN(a,b) (a)
#define arguments_BDK_PKO_VFX_DQX_OP_OPEN(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pko_vf#_dq#_op_query
 *
 * PKO DQ Query Operation Register
 * Reads to this register initiate a query operation.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_vfx_dqx_op_query_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dqstatus              : 4;  /**< [ 63: 60](RO) Indicates the success or failure of the operation, enumerated by PKO_DQSTATUS_E. */
        uint64_t reserved_50_59        : 10;
        uint64_t dqop                  : 2;  /**< [ 49: 48](RO) Indicates the operation that generated the return, enumerated by PKO_DQOP_E. */
        uint64_t depth                 : 48; /**< [ 47:  0](RO) Indicates the depth of the specified DQ in bytes, descriptors, or
                                                                 buffers, as follows:

                                                                 <pre>
                                                                     In PKO_DQ*_WM_CTL
                                                                    /                  \
                                                                   /                    \
                                                                   [KIND] [NCB_QUERY_RSP]  Description of [DEPTH]
                                                                 ------------------------------------------------------------------------------------------
                                                                      X          1         Buffers. [DEPTH] is PKO_DQ()_WM_BUF_CNT[COUNT],
                                                                                           which is the number of buffers consumed by the DQ.

                                                                      0          0         Byte Count. [DEPTH] is PKO_DQ()_WM_CNT[COUNT],
                                                                                           which is the sum of the PKO_META_DESC_S[LENGTH]
                                                                                           stored in the DQ, and of all the PKO_*_PICK[LENGTH]s in
                                                                                           conditioners holding valid metas from the DQ.

                                                                      1          0         Descriptor count. [DEPTH] is PKO_DQ()_WM_CNT[COUNT],
                                                                                           which is the number of descriptors stored in the DQ or from
                                                                                           the DQ and present in a PKO conditioner.
                                                                 </pre> */
#else /* Word 0 - Little Endian */
        uint64_t depth                 : 48; /**< [ 47:  0](RO) Indicates the depth of the specified DQ in bytes, descriptors, or
                                                                 buffers, as follows:

                                                                 <pre>
                                                                     In PKO_DQ*_WM_CTL
                                                                    /                  \
                                                                   /                    \
                                                                   [KIND] [NCB_QUERY_RSP]  Description of [DEPTH]
                                                                 ------------------------------------------------------------------------------------------
                                                                      X          1         Buffers. [DEPTH] is PKO_DQ()_WM_BUF_CNT[COUNT],
                                                                                           which is the number of buffers consumed by the DQ.

                                                                      0          0         Byte Count. [DEPTH] is PKO_DQ()_WM_CNT[COUNT],
                                                                                           which is the sum of the PKO_META_DESC_S[LENGTH]
                                                                                           stored in the DQ, and of all the PKO_*_PICK[LENGTH]s in
                                                                                           conditioners holding valid metas from the DQ.

                                                                      1          0         Descriptor count. [DEPTH] is PKO_DQ()_WM_CNT[COUNT],
                                                                                           which is the number of descriptors stored in the DQ or from
                                                                                           the DQ and present in a PKO conditioner.
                                                                 </pre> */
        uint64_t dqop                  : 2;  /**< [ 49: 48](RO) Indicates the operation that generated the return, enumerated by PKO_DQOP_E. */
        uint64_t reserved_50_59        : 10;
        uint64_t dqstatus              : 4;  /**< [ 63: 60](RO) Indicates the success or failure of the operation, enumerated by PKO_DQSTATUS_E. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_vfx_dqx_op_query_s cn; */
} bdk_pko_vfx_dqx_op_query_t;

static inline uint64_t BDK_PKO_VFX_DQX_OP_QUERY(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_VFX_DQX_OP_QUERY(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=7)))
        return 0x854400001300ll + 0x100000ll * ((a) & 0x1f) + 0x20000ll * ((b) & 0x7);
    __bdk_csr_fatal("PKO_VFX_DQX_OP_QUERY", 2, a, b, 0, 0);
}

#define typedef_BDK_PKO_VFX_DQX_OP_QUERY(a,b) bdk_pko_vfx_dqx_op_query_t
#define bustype_BDK_PKO_VFX_DQX_OP_QUERY(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_VFX_DQX_OP_QUERY(a,b) "PKO_VFX_DQX_OP_QUERY"
#define device_bar_BDK_PKO_VFX_DQX_OP_QUERY(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_PKO_VFX_DQX_OP_QUERY(a,b) (a)
#define arguments_BDK_PKO_VFX_DQX_OP_QUERY(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pko_vf#_dq#_op_send#
 *
 * PKO DQ Send Operation Register
 * A 64-bit, 128-bit or larger atomic store or LMTST is used to this address to
 * initiate a send operation.  All words for a given send command must be written using
 * a single instruction, resulting in up to 16 64-bit words of send descriptor.
 *
 * When a PKO_SEND_JUMP_S is not present in the PKO SEND descriptor, the written data
 * must contain exactly one valid PKO SEND descriptor.
 *
 * When a PKO_SEND_JUMP_S is present in the PKO SEND descriptor, the PKO SEND
 * descriptor must contain exactly the portion of the PKO SEND descriptor up to and
 * including the PKO_SEND_JUMP_S. The remainder of the PKO SEND descriptor must be in
 * L2/DRAM (pointed at by PKO_SEND_JUMP_S[ADDR]) in this case.
 *
 * Software must ensure that all L2/DRAM locations that will be referenced
 * by PKO while processing this descriptor, including all packet data, post-PKO_SEND_JUMP_S
 * subdescriptors, work queue entries, and/or PKO_SEND_MEM_S locations, contain the latest
 * updates before issuing the LMTDMA/LMTST. A DMB instruction may
 * be required prior to the LMTDMA/LMTST to ensure this. A DMB
 * following the LMTDMA/LMTST may be useful if DQ descriptor ordering matters and
 * more than one CPU core is simultaneously enqueueing to the same DQ. For more
 * information on ordering, refer to the HRM "Core Memory Reference Ordering" section
 * in the CPU cores chapter.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_vfx_dqx_op_sendx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](WO) Data that forms the descriptor; see register description. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](WO) Data that forms the descriptor; see register description. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_vfx_dqx_op_sendx_s cn; */
} bdk_pko_vfx_dqx_op_sendx_t;

static inline uint64_t BDK_PKO_VFX_DQX_OP_SENDX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_VFX_DQX_OP_SENDX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=7) && (c<=15)))
        return 0x854400001000ll + 0x100000ll * ((a) & 0x1f) + 0x20000ll * ((b) & 0x7) + 8ll * ((c) & 0xf);
    __bdk_csr_fatal("PKO_VFX_DQX_OP_SENDX", 3, a, b, c, 0);
}

#define typedef_BDK_PKO_VFX_DQX_OP_SENDX(a,b,c) bdk_pko_vfx_dqx_op_sendx_t
#define bustype_BDK_PKO_VFX_DQX_OP_SENDX(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_VFX_DQX_OP_SENDX(a,b,c) "PKO_VFX_DQX_OP_SENDX"
#define device_bar_BDK_PKO_VFX_DQX_OP_SENDX(a,b,c) 0x10 /* VF_BAR0 */
#define busnum_BDK_PKO_VFX_DQX_OP_SENDX(a,b,c) (a)
#define arguments_BDK_PKO_VFX_DQX_OP_SENDX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) pko_vf#_dq#_pd_state#
 *
 * PKO Packet Descriptor State Per DQ Access Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_vfx_dqx_pd_statex_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) This is the internal state for descriptors per each DQ. It can be accessed for
                                                                 debug or for software to cleanup/clear the state after a memory error.

                                                                 Warning that this will modify internal state. It must not be changed while DQ is
                                                                 active or system will need to be reset. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) This is the internal state for descriptors per each DQ. It can be accessed for
                                                                 debug or for software to cleanup/clear the state after a memory error.

                                                                 Warning that this will modify internal state. It must not be changed while DQ is
                                                                 active or system will need to be reset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_vfx_dqx_pd_statex_s cn; */
} bdk_pko_vfx_dqx_pd_statex_t;

static inline uint64_t BDK_PKO_VFX_DQX_PD_STATEX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_VFX_DQX_PD_STATEX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=7) && (c<=3)))
        return 0x85407001ff00ll + 0x100000ll * ((a) & 0x1f) + 0x20000ll * ((b) & 0x7) + 8ll * ((c) & 0x3);
    __bdk_csr_fatal("PKO_VFX_DQX_PD_STATEX", 3, a, b, c, 0);
}

#define typedef_BDK_PKO_VFX_DQX_PD_STATEX(a,b,c) bdk_pko_vfx_dqx_pd_statex_t
#define bustype_BDK_PKO_VFX_DQX_PD_STATEX(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_VFX_DQX_PD_STATEX(a,b,c) "PKO_VFX_DQX_PD_STATEX"
#define device_bar_BDK_PKO_VFX_DQX_PD_STATEX(a,b,c) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKO_VFX_DQX_PD_STATEX(a,b,c) (a)
#define arguments_BDK_PKO_VFX_DQX_PD_STATEX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) pko_vf#_dq#_sw_xoff
 *
 * PKO Descriptor Queue Software Controlled XOFF Register
 * This register has the same bit fields as PKO_L1_SQ()_SW_XOFF.
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_vfx_dqx_sw_xoff_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t drain_irq             : 1;  /**< [  3:  3](WO) Drain IRQ. Enables an interrupt that fires when the drain operation has completed.
                                                                 [DRAIN_IRQ] should be set whenever [DRAIN] is, and must not be set
                                                                 when [DRAIN] isn't set. [DRAIN_IRQ] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t drain_null_link       : 1;  /**< [  2:  2](WO) Drain null link. This setting only has effect when the L1 node is
                                                                 mapped to the NULL FIFO.  Conditions the drain path to drain through
                                                                 the NULL FIFO (i.e. link 14). As such, channel credits, HW_XOFF, and
                                                                 shaping are disabled on the draining path until the path has drained.
                                                                 [DRAIN_NULL_LINK] must not be set when [DRAIN] isn't set.
                                                                 [DRAIN_NULL_LINK] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t drain                 : 1;  /**< [  1:  1](WO) Drain. This control activates a drain path through the PSE that starts at this node and
                                                                 ends at the SQ1 level. The drain path is prioritized over other paths through PSE and can
                                                                 be used in combination with [DRAIN_NULL_LINK] and [DRAIN_IRQ]. [DRAIN] need never be
                                                                 set for the SQ1 level, but is useful at all other levels, including the DQ level.
                                                                 PKO_PQ_DRAIN_W1C[INTR] should be clear prior to initiating a [DRAIN]=1 write to this CSR.
                                                                 After [DRAIN] is set for an SQ/DQ, it should not be set again, for this or any other
                                                                 SQ/DQ, until after a 0->1 transition has been observed on PKO_PQ_DRAIN_W1C[INTR]
                                                                 (and/or the PKO_PSE_PQ_DRAIN interrupt has occured) and
                                                                 PKO_PQ_DRAIN_W1C[INTR] has been cleared.  DRAIN has no effect unless XOFF is also set.
                                                                 Only one DRAIN command is allowed to be active at a time. */
        uint64_t xoff                  : 1;  /**< [  0:  0](R/W) XOFF. Stops meta flow out of the SQ/DQ. When [XOFF] is set, the corresponding
                                                                 PKO_*_PICK (i.e. the meta) in the SQ/DQ cannot be transferred to the
                                                                 next level. The corresponding PKO_*_PICK may become valid while [XOFF] is set,
                                                                 but it cannot change from valid to invalid while [XOFF] is set.
                                                                 NOTE: The associated PKO_*_TOPOLOGY[LINK/PARENT] should normally be configured before
                                                                 [XOFF] is set. Setting [XOFF] before the associated PKO_*_TOPOLOGY[LINK/PARENT]
                                                                 value is configured can result in modifying the software [XOFF] state of the wrong SQ. */
#else /* Word 0 - Little Endian */
        uint64_t xoff                  : 1;  /**< [  0:  0](R/W) XOFF. Stops meta flow out of the SQ/DQ. When [XOFF] is set, the corresponding
                                                                 PKO_*_PICK (i.e. the meta) in the SQ/DQ cannot be transferred to the
                                                                 next level. The corresponding PKO_*_PICK may become valid while [XOFF] is set,
                                                                 but it cannot change from valid to invalid while [XOFF] is set.
                                                                 NOTE: The associated PKO_*_TOPOLOGY[LINK/PARENT] should normally be configured before
                                                                 [XOFF] is set. Setting [XOFF] before the associated PKO_*_TOPOLOGY[LINK/PARENT]
                                                                 value is configured can result in modifying the software [XOFF] state of the wrong SQ. */
        uint64_t drain                 : 1;  /**< [  1:  1](WO) Drain. This control activates a drain path through the PSE that starts at this node and
                                                                 ends at the SQ1 level. The drain path is prioritized over other paths through PSE and can
                                                                 be used in combination with [DRAIN_NULL_LINK] and [DRAIN_IRQ]. [DRAIN] need never be
                                                                 set for the SQ1 level, but is useful at all other levels, including the DQ level.
                                                                 PKO_PQ_DRAIN_W1C[INTR] should be clear prior to initiating a [DRAIN]=1 write to this CSR.
                                                                 After [DRAIN] is set for an SQ/DQ, it should not be set again, for this or any other
                                                                 SQ/DQ, until after a 0->1 transition has been observed on PKO_PQ_DRAIN_W1C[INTR]
                                                                 (and/or the PKO_PSE_PQ_DRAIN interrupt has occured) and
                                                                 PKO_PQ_DRAIN_W1C[INTR] has been cleared.  DRAIN has no effect unless XOFF is also set.
                                                                 Only one DRAIN command is allowed to be active at a time. */
        uint64_t drain_null_link       : 1;  /**< [  2:  2](WO) Drain null link. This setting only has effect when the L1 node is
                                                                 mapped to the NULL FIFO.  Conditions the drain path to drain through
                                                                 the NULL FIFO (i.e. link 14). As such, channel credits, HW_XOFF, and
                                                                 shaping are disabled on the draining path until the path has drained.
                                                                 [DRAIN_NULL_LINK] must not be set when [DRAIN] isn't set.
                                                                 [DRAIN_NULL_LINK] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t drain_irq             : 1;  /**< [  3:  3](WO) Drain IRQ. Enables an interrupt that fires when the drain operation has completed.
                                                                 [DRAIN_IRQ] should be set whenever [DRAIN] is, and must not be set
                                                                 when [DRAIN] isn't set. [DRAIN_IRQ] has no effect unless [DRAIN] and [XOFF] are also set. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_vfx_dqx_sw_xoff_s cn; */
} bdk_pko_vfx_dqx_sw_xoff_t;

static inline uint64_t BDK_PKO_VFX_DQX_SW_XOFF(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_VFX_DQX_SW_XOFF(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=7)))
        return 0x854400000100ll + 0x100000ll * ((a) & 0x1f) + 0x20000ll * ((b) & 0x7);
    __bdk_csr_fatal("PKO_VFX_DQX_SW_XOFF", 2, a, b, 0, 0);
}

#define typedef_BDK_PKO_VFX_DQX_SW_XOFF(a,b) bdk_pko_vfx_dqx_sw_xoff_t
#define bustype_BDK_PKO_VFX_DQX_SW_XOFF(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_VFX_DQX_SW_XOFF(a,b) "PKO_VFX_DQX_SW_XOFF"
#define device_bar_BDK_PKO_VFX_DQX_SW_XOFF(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_PKO_VFX_DQX_SW_XOFF(a,b) (a)
#define arguments_BDK_PKO_VFX_DQX_SW_XOFF(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pko_vf#_dq#_wm_cnt
 *
 * PKO Descriptor Queue Watermark Count Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_vfx_dqx_wm_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t count                 : 48; /**< [ 47:  0](R/W/H) Watermark count. The running value of the watermark counter. This value is a count of
                                                                 bytes or packets as specified by PKO_DQ()_WM_CTL[KIND]. [COUNT] covers all metas
                                                                 for the DQ between when the PKO SEND LMTDMA/LMTST enqueues the descriptor until
                                                                 PKO PEB (i.e. the packet engines and FIFOs) first receives the meta descriptor.
                                                                 It includes all descriptors whose meta's are held in either L2/DRAM for the DQ
                                                                 (i.e. whose metas are held in PKO PDM) or any DQ or SQ (i.e. whose metas are held
                                                                 in PKO PSE). */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 48; /**< [ 47:  0](R/W/H) Watermark count. The running value of the watermark counter. This value is a count of
                                                                 bytes or packets as specified by PKO_DQ()_WM_CTL[KIND]. [COUNT] covers all metas
                                                                 for the DQ between when the PKO SEND LMTDMA/LMTST enqueues the descriptor until
                                                                 PKO PEB (i.e. the packet engines and FIFOs) first receives the meta descriptor.
                                                                 It includes all descriptors whose meta's are held in either L2/DRAM for the DQ
                                                                 (i.e. whose metas are held in PKO PDM) or any DQ or SQ (i.e. whose metas are held
                                                                 in PKO PSE). */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_vfx_dqx_wm_cnt_s cn; */
} bdk_pko_vfx_dqx_wm_cnt_t;

static inline uint64_t BDK_PKO_VFX_DQX_WM_CNT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_VFX_DQX_WM_CNT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=7)))
        return 0x854400000150ll + 0x100000ll * ((a) & 0x1f) + 0x20000ll * ((b) & 0x7);
    __bdk_csr_fatal("PKO_VFX_DQX_WM_CNT", 2, a, b, 0, 0);
}

#define typedef_BDK_PKO_VFX_DQX_WM_CNT(a,b) bdk_pko_vfx_dqx_wm_cnt_t
#define bustype_BDK_PKO_VFX_DQX_WM_CNT(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_VFX_DQX_WM_CNT(a,b) "PKO_VFX_DQX_WM_CNT"
#define device_bar_BDK_PKO_VFX_DQX_WM_CNT(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_PKO_VFX_DQX_WM_CNT(a,b) (a)
#define arguments_BDK_PKO_VFX_DQX_WM_CNT(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pko_vf#_dq#_wm_ctl
 *
 * PKO Descriptor Queue Watermark Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_vfx_dqx_wm_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t ncb_query_rsp         : 1;  /**< [ 51: 51](R/W) NCB query response.  Specifies what value is returned in the
                                                                 PKO_QUERY_RTN_S[DEPTH] field.  When set to '0', the value held in
                                                                 PKO_DQ()_WM_CNT[COUNT] is returned.  When set to '1' the value held
                                                                 in PKO_DQ()_WM_BUF_CNT[COUNT] is returned. */
        uint64_t enable                : 1;  /**< [ 50: 50](RAZ) Reserved. */
        uint64_t kind                  : 1;  /**< [ 49: 49](R/W) Selects the contents of PKO_DQ()_WM_CNT[COUNT].
                                                                 If [KIND] is clear, PKO_DQ()_WM_CNT[COUNT] is a byte count for the DQ - the
                                                                 sum of all PKO_META_DESC_S[LENGTH] and PKO_*_PICK[LENGTH] for the DQ.
                                                                 If [KIND] is set, PKO_DQ()_WM_CNT[COUNT] is a number of descriptors for the DQ.
                                                                 See PKO_DQ()_WM_CNT[COUNT]. */
        uint64_t intr                  : 1;  /**< [ 48: 48](RAZ) Reserved. */
        uint64_t threshold             : 48; /**< [ 47:  0](RAZ) Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t threshold             : 48; /**< [ 47:  0](RAZ) Reserved. */
        uint64_t intr                  : 1;  /**< [ 48: 48](RAZ) Reserved. */
        uint64_t kind                  : 1;  /**< [ 49: 49](R/W) Selects the contents of PKO_DQ()_WM_CNT[COUNT].
                                                                 If [KIND] is clear, PKO_DQ()_WM_CNT[COUNT] is a byte count for the DQ - the
                                                                 sum of all PKO_META_DESC_S[LENGTH] and PKO_*_PICK[LENGTH] for the DQ.
                                                                 If [KIND] is set, PKO_DQ()_WM_CNT[COUNT] is a number of descriptors for the DQ.
                                                                 See PKO_DQ()_WM_CNT[COUNT]. */
        uint64_t enable                : 1;  /**< [ 50: 50](RAZ) Reserved. */
        uint64_t ncb_query_rsp         : 1;  /**< [ 51: 51](R/W) NCB query response.  Specifies what value is returned in the
                                                                 PKO_QUERY_RTN_S[DEPTH] field.  When set to '0', the value held in
                                                                 PKO_DQ()_WM_CNT[COUNT] is returned.  When set to '1' the value held
                                                                 in PKO_DQ()_WM_BUF_CNT[COUNT] is returned. */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_vfx_dqx_wm_ctl_s cn; */
} bdk_pko_vfx_dqx_wm_ctl_t;

static inline uint64_t BDK_PKO_VFX_DQX_WM_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_VFX_DQX_WM_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=7)))
        return 0x854400000130ll + 0x100000ll * ((a) & 0x1f) + 0x20000ll * ((b) & 0x7);
    __bdk_csr_fatal("PKO_VFX_DQX_WM_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_PKO_VFX_DQX_WM_CTL(a,b) bdk_pko_vfx_dqx_wm_ctl_t
#define bustype_BDK_PKO_VFX_DQX_WM_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_VFX_DQX_WM_CTL(a,b) "PKO_VFX_DQX_WM_CTL"
#define device_bar_BDK_PKO_VFX_DQX_WM_CTL(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_PKO_VFX_DQX_WM_CTL(a,b) (a)
#define arguments_BDK_PKO_VFX_DQX_WM_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pko_vf#_dq_fc_config
 *
 * PKO DQ Flow Control Configuration Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pko_vfx_dq_fc_config_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t base                  : 33; /**< [ 39:  7](R/W) The cache-line (128-byte) aligned IOVA for the memory
                                                                 location where the DQ[0] buffer count will be written by PKO for flow
                                                                 control purposes. The locations where the DQ[7:1] buffer counts will
                                                                 be written are calculated according to the [STRIDE]. */
        uint64_t hyst_bits             : 4;  /**< [  6:  3](R/W) Hysteresis bits. Use hysteresis to reduce
                                                                 the number of stores that PKO does to update copies of the adjusted
                                                                 buffer counts in L2/DRAM.  Hysteresis is accomplished by monitoring
                                                                 a range of LSBs (least significant bits) for each adjusted buffer
                                                                 count as specified by HYST_BITS and triggering stores according to
                                                                 the algorithm described below.  When HYST_BITS == 0, no count bits
                                                                 are monitored.  When HYST_BITS = (1, 2 ... 15), count bits <n-1:0> are
                                                                 monitored.

                                                                 For purposes of describing the hysteresis algorithm a "zero-crossing"
                                                                 is defined as any case where a buffer count's specified LSB range
                                                                 transitions between all zeros and all ones; a "down-crossing" is defined as
                                                                 the case where a buffer count decrement causes the specified LSB range
                                                                 to transition from all zeros to all ones and an "up-crossing" is the case
                                                                 where a buffer count increment causes the specified LSB range to
                                                                 transition from all 1s to all zeros.

                                                                 The hysteresis algorithm triggers stores upon down-crossings that
                                                                 follow a down-crossing and upon up-crossings that follow an
                                                                 up-crossing.  Conversely down-crossings that follow an up-crossing
                                                                 and up-crossings that follow a down-crossing do not trigger stores.
                                                                 This prevents the repeated updates that would otherwise occur if a
                                                                 buffer count oscillated around some zero-crossing.  When [HYST_BITS]
                                                                 = 0, there is no hysteresis and all buffer count updates trigger
                                                                 stores. */
        uint64_t stride                : 1;  /**< [  2:  2](R/W) Address stride.
                                                                 0 = Locations are spaced every 128 bytes to give them their own cache line.
                                                                 1 = Locations are a spaced every 16 bytes to pack them into the same cache line.

                                                                 Different NCB store commands are used based upon [STRIDE] and
                                                                 PKO_PDM_CFG[DQ_FC_SA] as follows:

                                                                 <pre>
                                                                   [STRIDE]  PKO_PDM_CFG[DQ_FC_SA]  NCB command
                                                                   --------  ---------------------  -----------
                                                                       0               0            STF
                                                                       0               1            STT
                                                                       1               X            STP
                                                                 </pre> */
        uint64_t reserved_1            : 1;
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable DQ buffer flow control.  When enabled PKO will periodically store
                                                                 PKO_VF()_DQ()_FC_STATUS[COUNT] minus PKO_PDM_CFG[DQ_FC_SKID] to L2/DRAM
                                                                 for flow control purposes as a signed 64-bit integer.  The address to
                                                                 which the value is stored is specified through [BASE] and [STRIDE]; while
                                                                 the frequency of the stores is controlled via [HYST_EXP]. */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enable DQ buffer flow control.  When enabled PKO will periodically store
                                                                 PKO_VF()_DQ()_FC_STATUS[COUNT] minus PKO_PDM_CFG[DQ_FC_SKID] to L2/DRAM
                                                                 for flow control purposes as a signed 64-bit integer.  The address to
                                                                 which the value is stored is specified through [BASE] and [STRIDE]; while
                                                                 the frequency of the stores is controlled via [HYST_EXP]. */
        uint64_t reserved_1            : 1;
        uint64_t stride                : 1;  /**< [  2:  2](R/W) Address stride.
                                                                 0 = Locations are spaced every 128 bytes to give them their own cache line.
                                                                 1 = Locations are a spaced every 16 bytes to pack them into the same cache line.

                                                                 Different NCB store commands are used based upon [STRIDE] and
                                                                 PKO_PDM_CFG[DQ_FC_SA] as follows:

                                                                 <pre>
                                                                   [STRIDE]  PKO_PDM_CFG[DQ_FC_SA]  NCB command
                                                                   --------  ---------------------  -----------
                                                                       0               0            STF
                                                                       0               1            STT
                                                                       1               X            STP
                                                                 </pre> */
        uint64_t hyst_bits             : 4;  /**< [  6:  3](R/W) Hysteresis bits. Use hysteresis to reduce
                                                                 the number of stores that PKO does to update copies of the adjusted
                                                                 buffer counts in L2/DRAM.  Hysteresis is accomplished by monitoring
                                                                 a range of LSBs (least significant bits) for each adjusted buffer
                                                                 count as specified by HYST_BITS and triggering stores according to
                                                                 the algorithm described below.  When HYST_BITS == 0, no count bits
                                                                 are monitored.  When HYST_BITS = (1, 2 ... 15), count bits <n-1:0> are
                                                                 monitored.

                                                                 For purposes of describing the hysteresis algorithm a "zero-crossing"
                                                                 is defined as any case where a buffer count's specified LSB range
                                                                 transitions between all zeros and all ones; a "down-crossing" is defined as
                                                                 the case where a buffer count decrement causes the specified LSB range
                                                                 to transition from all zeros to all ones and an "up-crossing" is the case
                                                                 where a buffer count increment causes the specified LSB range to
                                                                 transition from all 1s to all zeros.

                                                                 The hysteresis algorithm triggers stores upon down-crossings that
                                                                 follow a down-crossing and upon up-crossings that follow an
                                                                 up-crossing.  Conversely down-crossings that follow an up-crossing
                                                                 and up-crossings that follow a down-crossing do not trigger stores.
                                                                 This prevents the repeated updates that would otherwise occur if a
                                                                 buffer count oscillated around some zero-crossing.  When [HYST_BITS]
                                                                 = 0, there is no hysteresis and all buffer count updates trigger
                                                                 stores. */
        uint64_t base                  : 33; /**< [ 39:  7](R/W) The cache-line (128-byte) aligned IOVA for the memory
                                                                 location where the DQ[0] buffer count will be written by PKO for flow
                                                                 control purposes. The locations where the DQ[7:1] buffer counts will
                                                                 be written are calculated according to the [STRIDE]. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pko_vfx_dq_fc_config_s cn; */
} bdk_pko_vfx_dq_fc_config_t;

static inline uint64_t BDK_PKO_VFX_DQ_FC_CONFIG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKO_VFX_DQ_FC_CONFIG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x854400000160ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKO_VFX_DQ_FC_CONFIG", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKO_VFX_DQ_FC_CONFIG(a) bdk_pko_vfx_dq_fc_config_t
#define bustype_BDK_PKO_VFX_DQ_FC_CONFIG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKO_VFX_DQ_FC_CONFIG(a) "PKO_VFX_DQ_FC_CONFIG"
#define device_bar_BDK_PKO_VFX_DQ_FC_CONFIG(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_PKO_VFX_DQ_FC_CONFIG(a) (a)
#define arguments_BDK_PKO_VFX_DQ_FC_CONFIG(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_PKO_H__ */
