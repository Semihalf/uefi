#ifndef __BDK_CSRS_TNS__
#define __BDK_CSRS_TNS__
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
 * Cavium TNS.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Bar TNS_BAR_E
 *
 * TNS Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#ifdef __cplusplus
namespace TNS_BAR_E {
	const uint64_t TNS_PF_BAR0 = 0x842000000000;
	const uint64_t TNS_PF_BAR0_PCC_BAR_SIZE_BITS = 16;
	const uint64_t TNS_PF_BAR2 = 0x842040000000;
	const uint64_t TNS_PF_BAR2_PCC_BAR_SIZE_BITS = 30;
	const uint64_t TNS_PF_BAR4 = 0x842000f00000;
	const uint64_t TNS_PF_BAR4_PCC_BAR_SIZE_BITS = 20;
};
#endif

/**
 * Enumeration TNS_INT_VEC_E
 *
 * TNS MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum tns_int_vec_e {
	TNS_INT_VEC_E_DP_RDMA = 0x1,
	TNS_INT_VEC_E_DP_RDMA_NB = 0x3,
	TNS_INT_VEC_E_DP_TDMA = 0x0,
	TNS_INT_VEC_E_DP_TDMA_NB = 0x2,
	TNS_INT_VEC_E_SDE_HP0 = 0xa,
	TNS_INT_VEC_E_SDE_HP1 = 0xb,
	TNS_INT_VEC_E_SDE_HP10 = 0x14,
	TNS_INT_VEC_E_SDE_HP11 = 0x15,
	TNS_INT_VEC_E_SDE_HP12 = 0x16,
	TNS_INT_VEC_E_SDE_HP2 = 0xc,
	TNS_INT_VEC_E_SDE_HP3 = 0xd,
	TNS_INT_VEC_E_SDE_HP4 = 0xe,
	TNS_INT_VEC_E_SDE_HP5 = 0xf,
	TNS_INT_VEC_E_SDE_HP6 = 0x10,
	TNS_INT_VEC_E_SDE_HP7 = 0x11,
	TNS_INT_VEC_E_SDE_HP8 = 0x12,
	TNS_INT_VEC_E_SDE_HP9 = 0x13,
	TNS_INT_VEC_E_SDE_LP0 = 0x17,
	TNS_INT_VEC_E_SDE_LP1 = 0x18,
	TNS_INT_VEC_E_SDE_LP10 = 0x21,
	TNS_INT_VEC_E_SDE_LP11 = 0x22,
	TNS_INT_VEC_E_SDE_LP12 = 0x23,
	TNS_INT_VEC_E_SDE_LP2 = 0x19,
	TNS_INT_VEC_E_SDE_LP3 = 0x1a,
	TNS_INT_VEC_E_SDE_LP4 = 0x1b,
	TNS_INT_VEC_E_SDE_LP5 = 0x1c,
	TNS_INT_VEC_E_SDE_LP6 = 0x1d,
	TNS_INT_VEC_E_SDE_LP7 = 0x1e,
	TNS_INT_VEC_E_SDE_LP8 = 0x1f,
	TNS_INT_VEC_E_SDE_LP9 = 0x20,
	TNS_INT_VEC_E_SE_HP0 = 0x4,
	TNS_INT_VEC_E_SE_HP1 = 0x5,
	TNS_INT_VEC_E_SE_HP2 = 0x6,
	TNS_INT_VEC_E_SE_LP0 = 0x7,
	TNS_INT_VEC_E_SE_LP1 = 0x8,
	TNS_INT_VEC_E_SE_LP2 = 0x9,
	TNS_INT_VEC_E_TXQ_HP0 = 0x24,
	TNS_INT_VEC_E_TXQ_HP1 = 0x25,
	TNS_INT_VEC_E_TXQ_HP2 = 0x26,
	TNS_INT_VEC_E_TXQ_HP3 = 0x27,
	TNS_INT_VEC_E_TXQ_HP4 = 0x28,
	TNS_INT_VEC_E_TXQ_HP5 = 0x29,
	TNS_INT_VEC_E_TXQ_LP0 = 0x2a,
	TNS_INT_VEC_E_TXQ_LP1 = 0x2b,
	TNS_INT_VEC_E_TXQ_LP2 = 0x2c,
	TNS_INT_VEC_E_TXQ_LP3 = 0x2d,
	TNS_INT_VEC_E_TXQ_LP4 = 0x2e,
	TNS_INT_VEC_E_TXQ_LP5 = 0x2f,
	TNS_INT_VEC_E_ENUM_LAST = 0x30,
};

/**
 * Enumeration TNS_PHYS_PORT_E
 *
 * TNS Physical Port Enumeration
 * Enumerates the physical port identifier for received and transmitted packets.
 */
enum tns_phys_port_e {
	TNS_PHYS_PORT_E_LMAC0 = 0x0,
	TNS_PHYS_PORT_E_LMAC1 = 0x1,
	TNS_PHYS_PORT_E_LMAC2 = 0x2,
	TNS_PHYS_PORT_E_LMAC3 = 0x3,
	TNS_PHYS_PORT_E_LMAC4 = 0x4,
	TNS_PHYS_PORT_E_LMAC5 = 0x5,
	TNS_PHYS_PORT_E_LMAC6 = 0x6,
	TNS_PHYS_PORT_E_LMAC7 = 0x7,
	TNS_PHYS_PORT_E_LOOPBACK = 0xa,
	TNS_PHYS_PORT_E_NICI0 = 0x8,
	TNS_PHYS_PORT_E_NICI1 = 0x9,
	TNS_PHYS_PORT_E_ENUM_LAST = 0xb,
};

/**
 * Enumeration TNS_RDMA_HDR_SZ_E
 *
 * TNS RDMA Header Size Enumeration
 * Enumerates the header size selection for received packets.
 */
enum tns_rdma_hdr_sz_e {
	TNS_RDMA_HDR_SZ_E_BYTES_128 = 0x1,
	TNS_RDMA_HDR_SZ_E_BYTES_192 = 0x2,
	TNS_RDMA_HDR_SZ_E_BYTES_256 = 0x3,
	TNS_RDMA_HDR_SZ_E_BYTES_64 = 0x0,
	TNS_RDMA_HDR_SZ_E_ENUM_LAST = 0x4,
};



/**
 * NCB - tns_bist_status
 *
 * BIST status.
 * INTERNAL:
 * All memories listed below are TDMA memories used for both bypass and non-bypass operation.
 */
typedef union bdk_tns_bist_status {
	uint64_t u;
	struct bdk_tns_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t vmem                        : 1;  /**< RO/H - BIST failure for the MSIX VMEM RAM. */
		uint64_t nici                        : 2;  /**< RO/H - BIST failure for the NIC Interface RAMs. */
		uint64_t lmac                        : 2;  /**< RO/H - BIST failure for the LMAC RAMs. */
#else
		uint64_t lmac                        : 2;
		uint64_t nici                        : 2;
		uint64_t vmem                        : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_tns_bist_status_s       cn85xx; */
	/* struct bdk_tns_bist_status_s       cn88xx; */
} bdk_tns_bist_status_t;

#define BDK_TNS_BIST_STATUS BDK_TNS_BIST_STATUS_FUNC()
static inline uint64_t BDK_TNS_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_BIST_STATUS_FUNC(void)
{
	return 0x0000842000000000ull;
}
#define typedef_BDK_TNS_BIST_STATUS bdk_tns_bist_status_t
#define bustype_BDK_TNS_BIST_STATUS BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_BIST_STATUS 0
#define arguments_BDK_TNS_BIST_STATUS -1,-1,-1,-1
#define basename_BDK_TNS_BIST_STATUS "TNS_BIST_STATUS"


/**
 * NCB - tns_bist_status1
 *
 * BIST status.
 * INTERNAL:
 * All TDMA memories listed below are used for non-bypass operation only.
 */
typedef union bdk_tns_bist_status1 {
	uint64_t u;
	struct bdk_tns_bist_status1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t prc                         : 1;  /**< RO/H - BIST failure for the PRC RAM. */
		uint64_t ll                          : 1;  /**< RO/H - BIST failure for the LL RAM. */
		uint64_t fpm                         : 1;  /**< RO/H - BIST failure for the FPM RAM. */
		uint64_t pkt_lb                      : 1;  /**< RO/H - BIST failure for the PKT_LB RAM. */
		uint64_t pkt_x2p                     : 1;  /**< RO/H - BIST failure for the PKT_X2P RAM. */
		uint64_t pkt_p2x_data                : 1;  /**< RO/H - BIST failure for the PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn                 : 1;  /**< RO/H - BIST failure for the PKT_P2X_TKN RAM. */
#else
		uint64_t pkt_p2x_tkn                 : 1;
		uint64_t pkt_p2x_data                : 1;
		uint64_t pkt_x2p                     : 1;
		uint64_t pkt_lb                      : 1;
		uint64_t fpm                         : 1;
		uint64_t ll                          : 1;
		uint64_t prc                         : 1;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	/* struct bdk_tns_bist_status1_s      cn85xx; */
	/* struct bdk_tns_bist_status1_s      cn88xx; */
} bdk_tns_bist_status1_t;

#define BDK_TNS_BIST_STATUS1 BDK_TNS_BIST_STATUS1_FUNC()
static inline uint64_t BDK_TNS_BIST_STATUS1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_BIST_STATUS1_FUNC(void)
{
	return 0x0000842000000010ull;
}
#define typedef_BDK_TNS_BIST_STATUS1 bdk_tns_bist_status1_t
#define bustype_BDK_TNS_BIST_STATUS1 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_BIST_STATUS1 0
#define arguments_BDK_TNS_BIST_STATUS1 -1,-1,-1,-1
#define basename_BDK_TNS_BIST_STATUS1 "TNS_BIST_STATUS1"


/**
 * NCB - tns_bist_status10
 *
 * BIST status.
 * INTERNAL:
 * All memories listed below are used only for non-bypass operation.
 */
typedef union bdk_tns_bist_status10 {
	uint64_t u;
	struct bdk_tns_bist_status10_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t se_age                      : 4;  /**< RO/H - BIST failure for the SE AGE RAM. */
		uint64_t se_sram1                    : 16; /**< RO/H - BIST failure for the SE SRAM1 RAM. */
		uint64_t se_sram0                    : 16; /**< RO/H - BIST failure for the SE SRAM0 RAM. */
#else
		uint64_t se_sram0                    : 16;
		uint64_t se_sram1                    : 16;
		uint64_t se_age                      : 4;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_tns_bist_status10_s     cn85xx; */
	/* struct bdk_tns_bist_status10_s     cn88xx; */
} bdk_tns_bist_status10_t;

#define BDK_TNS_BIST_STATUS10 BDK_TNS_BIST_STATUS10_FUNC()
static inline uint64_t BDK_TNS_BIST_STATUS10_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_BIST_STATUS10_FUNC(void)
{
	return 0x00008420000000A0ull;
}
#define typedef_BDK_TNS_BIST_STATUS10 bdk_tns_bist_status10_t
#define bustype_BDK_TNS_BIST_STATUS10 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_BIST_STATUS10 0
#define arguments_BDK_TNS_BIST_STATUS10 -1,-1,-1,-1
#define basename_BDK_TNS_BIST_STATUS10 "TNS_BIST_STATUS10"


/**
 * NCB - tns_bist_status11
 *
 * BIST status.
 * INTERNAL:
 * All memories listed below are used only for non-bypass operation.
 */
typedef union bdk_tns_bist_status11 {
	uint64_t u;
	struct bdk_tns_bist_status11_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_34_63              : 30;
		uint64_t txq_qac                     : 12; /**< RO/H - BIST failure for the TxQ QAC RAM. */
		uint64_t txq_tbc                     : 7;  /**< RO/H - BIST failure for the TxQ TBC RAM. */
		uint64_t txq_eq                      : 1;  /**< RO/H - BIST failure for the TxQ EQ RAM. */
		uint64_t txq_dq                      : 14; /**< RO/H - BIST failure for the TxQ DQ RAM. */
#else
		uint64_t txq_dq                      : 14;
		uint64_t txq_eq                      : 1;
		uint64_t txq_tbc                     : 7;
		uint64_t txq_qac                     : 12;
		uint64_t reserved_34_63              : 30;
#endif
	} s;
	/* struct bdk_tns_bist_status11_s     cn85xx; */
	/* struct bdk_tns_bist_status11_s     cn88xx; */
} bdk_tns_bist_status11_t;

#define BDK_TNS_BIST_STATUS11 BDK_TNS_BIST_STATUS11_FUNC()
static inline uint64_t BDK_TNS_BIST_STATUS11_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_BIST_STATUS11_FUNC(void)
{
	return 0x00008420000000B0ull;
}
#define typedef_BDK_TNS_BIST_STATUS11 bdk_tns_bist_status11_t
#define bustype_BDK_TNS_BIST_STATUS11 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_BIST_STATUS11 0
#define arguments_BDK_TNS_BIST_STATUS11 -1,-1,-1,-1
#define basename_BDK_TNS_BIST_STATUS11 "TNS_BIST_STATUS11"


/**
 * NCB - tns_bist_status2
 *
 * BIST status.
 * INTERNAL:
 * All RDMA memories listed below are used only for non-bypass operation.
 * Bypass will still operate correctly if any of the memories below has a BIST failure.
 */
typedef union bdk_tns_bist_status2 {
	uint64_t u;
	struct bdk_tns_bist_status2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t b_x2p1                      : 1;  /**< RO/H - BIST failure for the B_X2P1 RAM. */
		uint64_t b_x2p0                      : 1;  /**< RO/H - BIST failure for the B_X2P0 RAM. */
		uint64_t b_p2x                       : 1;  /**< RO/H - BIST failure for the B_P2X RAM. */
		uint64_t sdma                        : 1;  /**< RO/H - BIST failure for the SDMA RAM. */
		uint64_t plut_sdma                   : 1;  /**< RO/H - BIST failure for the PLUT_SDMA RAM. */
		uint64_t plut_p2x                    : 1;  /**< RO/H - BIST failure for the PLUT_P2X RAM. */
		uint64_t pkt_lb                      : 2;  /**< RO/H - BIST failure for the PKT_LB RAMs. */
		uint64_t pkt_nici1                   : 2;  /**< RO/H - BIST failure for the PKT_NICI1 RAMs. */
		uint64_t pkt_nici0                   : 2;  /**< RO/H - BIST failure for the PKT_NICI0 RAMs. */
		uint64_t pkt_lmac_ts                 : 8;  /**< RO/H - BIST failure for the PKT_LMAC_TS RAMs. */
		uint64_t pkt_lmac7                   : 2;  /**< RO/H - BIST failure for the PKT_LMAC7 RAMs. */
		uint64_t pkt_lmac6                   : 2;  /**< RO/H - BIST failure for the PKT_LMAC6 RAMs. */
		uint64_t pkt_lmac5                   : 2;  /**< RO/H - BIST failure for the PKT_LMAC5 RAMs. */
		uint64_t pkt_lmac4                   : 2;  /**< RO/H - BIST failure for the PKT_LMAC4 RAMs. */
		uint64_t pkt_lmac3                   : 2;  /**< RO/H - BIST failure for the PKT_LMAC3 RAMs. */
		uint64_t pkt_lmac2                   : 2;  /**< RO/H - BIST failure for the PKT_LMAC2 RAMs. */
		uint64_t pkt_lmac1                   : 2;  /**< RO/H - BIST failure for the PKT_LMAC1 RAMs. */
		uint64_t pkt_lmac0                   : 2;  /**< RO/H - BIST failure for the PKT_LMAC0 RAMs. */
#else
		uint64_t pkt_lmac0                   : 2;
		uint64_t pkt_lmac1                   : 2;
		uint64_t pkt_lmac2                   : 2;
		uint64_t pkt_lmac3                   : 2;
		uint64_t pkt_lmac4                   : 2;
		uint64_t pkt_lmac5                   : 2;
		uint64_t pkt_lmac6                   : 2;
		uint64_t pkt_lmac7                   : 2;
		uint64_t pkt_lmac_ts                 : 8;
		uint64_t pkt_nici0                   : 2;
		uint64_t pkt_nici1                   : 2;
		uint64_t pkt_lb                      : 2;
		uint64_t plut_p2x                    : 1;
		uint64_t plut_sdma                   : 1;
		uint64_t sdma                        : 1;
		uint64_t b_p2x                       : 1;
		uint64_t b_x2p0                      : 1;
		uint64_t b_x2p1                      : 1;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_tns_bist_status2_s      cn85xx; */
	/* struct bdk_tns_bist_status2_s      cn88xx; */
} bdk_tns_bist_status2_t;

#define BDK_TNS_BIST_STATUS2 BDK_TNS_BIST_STATUS2_FUNC()
static inline uint64_t BDK_TNS_BIST_STATUS2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_BIST_STATUS2_FUNC(void)
{
	return 0x0000842000000020ull;
}
#define typedef_BDK_TNS_BIST_STATUS2 bdk_tns_bist_status2_t
#define bustype_BDK_TNS_BIST_STATUS2 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_BIST_STATUS2 0
#define arguments_BDK_TNS_BIST_STATUS2 -1,-1,-1,-1
#define basename_BDK_TNS_BIST_STATUS2 "TNS_BIST_STATUS2"


/**
 * NCB - tns_bist_status3
 *
 * BIST status.
 * INTERNAL:
 * All Packet Memory memories listed below are used only for non-bypass operation.
 * Bypass will still operate correctly if any of the memories below has a BIST failure.
 * Each field is organized as: [8k[3],8k[2],8k[1],8k[0],16k[3],16k[2],16k[1],16k[0]].
 * Each of the PM regions stores one quarter of the word width, with each word being written to
 * and read from all four PM regions simultaneously.
 * Within a PM region, word width is organized as [[1], [0]] and [[3], [2]].
 * Within a PM region, memory depth is organized as:
 *   * rows 0      - 16,383: 16k[1,0]
 *   * rows 16,384 - 32,767: 16k[3,2]
 *   * rows 32,768 - 40,959:  8k[1,0]
 *   * rows 40,960 - 49,151:  8k[3,2]
 */
typedef union bdk_tns_bist_status3 {
	uint64_t u;
	struct bdk_tns_bist_status3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t pm3                         : 8;  /**< RO/H - BIST failure in the PM3 region. */
		uint64_t pm2                         : 8;  /**< RO/H - BIST failure in the PM2 region. */
		uint64_t pm1                         : 8;  /**< RO/H - BIST failure in the PM1 region. */
		uint64_t pm0                         : 8;  /**< RO/H - BIST failure in the PM0 region. */
#else
		uint64_t pm0                         : 8;
		uint64_t pm1                         : 8;
		uint64_t pm2                         : 8;
		uint64_t pm3                         : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_tns_bist_status3_s      cn85xx; */
	/* struct bdk_tns_bist_status3_s      cn88xx; */
} bdk_tns_bist_status3_t;

#define BDK_TNS_BIST_STATUS3 BDK_TNS_BIST_STATUS3_FUNC()
static inline uint64_t BDK_TNS_BIST_STATUS3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_BIST_STATUS3_FUNC(void)
{
	return 0x0000842000000030ull;
}
#define typedef_BDK_TNS_BIST_STATUS3 bdk_tns_bist_status3_t
#define bustype_BDK_TNS_BIST_STATUS3 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_BIST_STATUS3 0
#define arguments_BDK_TNS_BIST_STATUS3 -1,-1,-1,-1
#define basename_BDK_TNS_BIST_STATUS3 "TNS_BIST_STATUS3"


/**
 * NCB - tns_bist_status4
 *
 * BIST status.
 * INTERNAL:
 * All memories listed below are used only for non-bypass operation.
 */
typedef union bdk_tns_bist_status4 {
	uint64_t u;
	struct bdk_tns_bist_status4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_59_63              : 5;
		uint64_t sde_mre                     : 21; /**< RO/H - BIST failure for the SDE MRE RAM. */
		uint64_t sde_hdbf                    : 7;  /**< RO/H - BIST failure for the SDE HDBF RAM. */
		uint64_t sde_parser_cam              : 7;  /**< RO/H - BIST failure for the SDE Parser CAM. */
		uint64_t sde_parser                  : 24; /**< RO/H - BIST failure for the SDE Parser RAM. */
#else
		uint64_t sde_parser                  : 24;
		uint64_t sde_parser_cam              : 7;
		uint64_t sde_hdbf                    : 7;
		uint64_t sde_mre                     : 21;
		uint64_t reserved_59_63              : 5;
#endif
	} s;
	/* struct bdk_tns_bist_status4_s      cn85xx; */
	/* struct bdk_tns_bist_status4_s      cn88xx; */
} bdk_tns_bist_status4_t;

#define BDK_TNS_BIST_STATUS4 BDK_TNS_BIST_STATUS4_FUNC()
static inline uint64_t BDK_TNS_BIST_STATUS4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_BIST_STATUS4_FUNC(void)
{
	return 0x0000842000000040ull;
}
#define typedef_BDK_TNS_BIST_STATUS4 bdk_tns_bist_status4_t
#define bustype_BDK_TNS_BIST_STATUS4 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_BIST_STATUS4 0
#define arguments_BDK_TNS_BIST_STATUS4 -1,-1,-1,-1
#define basename_BDK_TNS_BIST_STATUS4 "TNS_BIST_STATUS4"


/**
 * NCB - tns_bist_status5
 *
 * BIST status.
 * INTERNAL:
 * All memories listed below are used only for non-bypass operation.
 */
typedef union bdk_tns_bist_status5 {
	uint64_t u;
	struct bdk_tns_bist_status5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t sde_isme                    : 6;  /**< RO/H - BIST failure for the SDE ISME RAM. */
		uint64_t sde_ldea1                   : 21; /**< RO/H - BIST failure for the SDE LDEA1 RAM. */
		uint64_t sde_ldea0                   : 21; /**< RO/H - BIST failure for the SDE LDEA0 RAM. */
#else
		uint64_t sde_ldea0                   : 21;
		uint64_t sde_ldea1                   : 21;
		uint64_t sde_isme                    : 6;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_tns_bist_status5_s      cn85xx; */
	/* struct bdk_tns_bist_status5_s      cn88xx; */
} bdk_tns_bist_status5_t;

#define BDK_TNS_BIST_STATUS5 BDK_TNS_BIST_STATUS5_FUNC()
static inline uint64_t BDK_TNS_BIST_STATUS5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_BIST_STATUS5_FUNC(void)
{
	return 0x0000842000000050ull;
}
#define typedef_BDK_TNS_BIST_STATUS5 bdk_tns_bist_status5_t
#define bustype_BDK_TNS_BIST_STATUS5 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_BIST_STATUS5 0
#define arguments_BDK_TNS_BIST_STATUS5 -1,-1,-1,-1
#define basename_BDK_TNS_BIST_STATUS5 "TNS_BIST_STATUS5"


/**
 * NCB - tns_bist_status6
 *
 * BIST status.
 * INTERNAL:
 * All memories listed below are used only for non-bypass operation.
 */
typedef union bdk_tns_bist_status6 {
	uint64_t u;
	struct bdk_tns_bist_status6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t sde_cnt                     : 50; /**< RO/H - BIST failure for the SDE CNT RAM. */
#else
		uint64_t sde_cnt                     : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_tns_bist_status6_s      cn85xx; */
	/* struct bdk_tns_bist_status6_s      cn88xx; */
} bdk_tns_bist_status6_t;

#define BDK_TNS_BIST_STATUS6 BDK_TNS_BIST_STATUS6_FUNC()
static inline uint64_t BDK_TNS_BIST_STATUS6_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_BIST_STATUS6_FUNC(void)
{
	return 0x0000842000000060ull;
}
#define typedef_BDK_TNS_BIST_STATUS6 bdk_tns_bist_status6_t
#define bustype_BDK_TNS_BIST_STATUS6 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_BIST_STATUS6 0
#define arguments_BDK_TNS_BIST_STATUS6 -1,-1,-1,-1
#define basename_BDK_TNS_BIST_STATUS6 "TNS_BIST_STATUS6"


/**
 * NCB - tns_bist_status7
 *
 * BIST status.
 * INTERNAL:
 * All memories listed below are used only for non-bypass operation.
 */
typedef union bdk_tns_bist_status7 {
	uint64_t u;
	struct bdk_tns_bist_status7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t sde_urw3                    : 40; /**< RO/H - BIST failure for the SDE URW3 RAM. */
		uint64_t sde_urw1                    : 24; /**< RO/H - BIST failure for the SDE URW1 RAM. */
#else
		uint64_t sde_urw1                    : 24;
		uint64_t sde_urw3                    : 40;
#endif
	} s;
	/* struct bdk_tns_bist_status7_s      cn85xx; */
	/* struct bdk_tns_bist_status7_s      cn88xx; */
} bdk_tns_bist_status7_t;

#define BDK_TNS_BIST_STATUS7 BDK_TNS_BIST_STATUS7_FUNC()
static inline uint64_t BDK_TNS_BIST_STATUS7_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_BIST_STATUS7_FUNC(void)
{
	return 0x0000842000000070ull;
}
#define typedef_BDK_TNS_BIST_STATUS7 bdk_tns_bist_status7_t
#define bustype_BDK_TNS_BIST_STATUS7 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_BIST_STATUS7 0
#define arguments_BDK_TNS_BIST_STATUS7 -1,-1,-1,-1
#define basename_BDK_TNS_BIST_STATUS7 "TNS_BIST_STATUS7"


/**
 * NCB - tns_bist_status8
 *
 * BIST status.
 * INTERNAL:
 * All memories listed below are used only for non-bypass operation.
 */
typedef union bdk_tns_bist_status8 {
	uint64_t u;
	struct bdk_tns_bist_status8_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t se_tcam_cam                 : 48; /**< RO/H - BIST failure for the SE TCAM CAM.
                                                                 INTERNAL:
                                                                 Due to the late addition of a multi-bank TCAM BIST controller, only a
                                                                 sub-set of the bits in this field will be set. Bug 20606. */
		uint64_t se_tcam                     : 16; /**< RO/H - BIST failure for the SE TCAM RAM. */
#else
		uint64_t se_tcam                     : 16;
		uint64_t se_tcam_cam                 : 48;
#endif
	} s;
	/* struct bdk_tns_bist_status8_s      cn85xx; */
	/* struct bdk_tns_bist_status8_s      cn88xx; */
} bdk_tns_bist_status8_t;

#define BDK_TNS_BIST_STATUS8 BDK_TNS_BIST_STATUS8_FUNC()
static inline uint64_t BDK_TNS_BIST_STATUS8_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_BIST_STATUS8_FUNC(void)
{
	return 0x0000842000000080ull;
}
#define typedef_BDK_TNS_BIST_STATUS8 bdk_tns_bist_status8_t
#define bustype_BDK_TNS_BIST_STATUS8 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_BIST_STATUS8 0
#define arguments_BDK_TNS_BIST_STATUS8 -1,-1,-1,-1
#define basename_BDK_TNS_BIST_STATUS8 "TNS_BIST_STATUS8"


/**
 * NCB - tns_bist_status9
 *
 * BIST status.
 * INTERNAL:
 * All memories listed below are used only for non-bypass operation.
 */
typedef union bdk_tns_bist_status9 {
	uint64_t u;
	struct bdk_tns_bist_status9_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t se_tcam_ecc                 : 48; /**< RO/H - BIST failure for the SE TCAM ECC RAM. */
#else
		uint64_t se_tcam_ecc                 : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_tns_bist_status9_s      cn85xx; */
	/* struct bdk_tns_bist_status9_s      cn88xx; */
} bdk_tns_bist_status9_t;

#define BDK_TNS_BIST_STATUS9 BDK_TNS_BIST_STATUS9_FUNC()
static inline uint64_t BDK_TNS_BIST_STATUS9_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_BIST_STATUS9_FUNC(void)
{
	return 0x0000842000000090ull;
}
#define typedef_BDK_TNS_BIST_STATUS9 bdk_tns_bist_status9_t
#define bustype_BDK_TNS_BIST_STATUS9 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_BIST_STATUS9 0
#define arguments_BDK_TNS_BIST_STATUS9 -1,-1,-1,-1
#define basename_BDK_TNS_BIST_STATUS9 "TNS_BIST_STATUS9"


/**
 * NCB - tns_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the TNS_INT_VEC_E enumeration.
 *
 */
typedef union bdk_tns_msix_pbax {
	uint64_t u;
	struct bdk_tns_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated TNS_MSIX_VEC()_CTL, enumerated by TNS_INT_VEC_E.
                                                                 Bits that have no associated TNS_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_tns_msix_pbax_s         cn85xx; */
	/* struct bdk_tns_msix_pbax_s         cn88xx; */
} bdk_tns_msix_pbax_t;

static inline uint64_t BDK_TNS_MSIX_PBAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_MSIX_PBAX(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x0000842000FF0000ull;
	csr_fatal("BDK_TNS_MSIX_PBAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_MSIX_PBAX(...) bdk_tns_msix_pbax_t
#define bustype_BDK_TNS_MSIX_PBAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_MSIX_PBAX(p1) (p1)
#define arguments_BDK_TNS_MSIX_PBAX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_MSIX_PBAX(...) "TNS_MSIX_PBAX"


/**
 * NCB - tns_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the TNS_INT_VEC_E enumeration.
 *
 */
typedef union bdk_tns_msix_vecx_addr {
	uint64_t u;
	struct bdk_tns_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's TNS_MSIX_VEC()_ADDR, TNS_MSIX_VEC()_CTL, and corresponding
                                                                 bit of TNS_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_TNS_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_tns_msix_vecx_addr_s    cn85xx; */
	/* struct bdk_tns_msix_vecx_addr_s    cn88xx; */
} bdk_tns_msix_vecx_addr_t;

static inline uint64_t BDK_TNS_MSIX_VECX_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_MSIX_VECX_ADDR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000842000F00000ull + (param1 & 63) * 0x10ull;
	csr_fatal("BDK_TNS_MSIX_VECX_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_MSIX_VECX_ADDR(...) bdk_tns_msix_vecx_addr_t
#define bustype_BDK_TNS_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_MSIX_VECX_ADDR(p1) (p1)
#define arguments_BDK_TNS_MSIX_VECX_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_MSIX_VECX_ADDR(...) "TNS_MSIX_VECX_ADDR"


/**
 * NCB - tns_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the TNS_INT_VEC_E enumeration.
 *
 */
typedef union bdk_tns_msix_vecx_ctl {
	uint64_t u;
	struct bdk_tns_msix_vecx_ctl_s {
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
	/* struct bdk_tns_msix_vecx_ctl_s     cn85xx; */
	/* struct bdk_tns_msix_vecx_ctl_s     cn88xx; */
} bdk_tns_msix_vecx_ctl_t;

static inline uint64_t BDK_TNS_MSIX_VECX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_MSIX_VECX_CTL(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000842000F00008ull + (param1 & 63) * 0x10ull;
	csr_fatal("BDK_TNS_MSIX_VECX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_MSIX_VECX_CTL(...) bdk_tns_msix_vecx_ctl_t
#define bustype_BDK_TNS_MSIX_VECX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_MSIX_VECX_CTL(p1) (p1)
#define arguments_BDK_TNS_MSIX_VECX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_MSIX_VECX_CTL(...) "TNS_MSIX_VECX_CTL"


/**
 * NCB - tns_pm_rd_acc#
 *
 * Provides the ability for software to read the network switch packet memory.
 * The packet memory consists of 49,152 512-bit words.
 * Write access of the packet memory is provided elsewhere.
 */
typedef union bdk_tns_pm_rd_accx {
	uint64_t u;
	struct bdk_tns_pm_rd_accx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< RO/H - Packet data. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_tns_pm_rd_accx_s        cn85xx; */
	/* struct bdk_tns_pm_rd_accx_s        cn88xx; */
} bdk_tns_pm_rd_accx_t;

static inline uint64_t BDK_TNS_PM_RD_ACCX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_PM_RD_ACCX(unsigned long param1)
{
	if (((param1 <= 393215)))
		return 0x0000842041800000ull + (param1 & 524287) * 0x10ull;
	csr_fatal("BDK_TNS_PM_RD_ACCX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_PM_RD_ACCX(...) bdk_tns_pm_rd_accx_t
#define bustype_BDK_TNS_PM_RD_ACCX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_PM_RD_ACCX(p1) (p1)
#define arguments_BDK_TNS_PM_RD_ACCX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_PM_RD_ACCX(...) "TNS_PM_RD_ACCX"


/**
 * NCB - tns_pm_wr_acc#
 *
 * Provides the ability for software to write the network switch packet memory.
 * The packet memory consists of 49,152 512-bit words.
 * To write data to a piece of a memory word software must write the entire word, 8 bytes at a
 * time,
 * starting with the least significant bits at 0x...00 and incrementing sequentially up
 * to 0x...80.
 * Read access of the packet memory is provided elsewhere.
 */
typedef union bdk_tns_pm_wr_accx {
	uint64_t u;
	struct bdk_tns_pm_wr_accx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< WO/H - Packet data. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_tns_pm_wr_accx_s        cn85xx; */
	/* struct bdk_tns_pm_wr_accx_s        cn88xx; */
} bdk_tns_pm_wr_accx_t;

static inline uint64_t BDK_TNS_PM_WR_ACCX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_PM_WR_ACCX(unsigned long param1)
{
	if (((param1 <= 393215)))
		return 0x0000842042800000ull + (param1 & 524287) * 0x10ull;
	csr_fatal("BDK_TNS_PM_WR_ACCX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_PM_WR_ACCX(...) bdk_tns_pm_wr_accx_t
#define bustype_BDK_TNS_PM_WR_ACCX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_PM_WR_ACCX(p1) (p1)
#define arguments_BDK_TNS_PM_WR_ACCX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_PM_WR_ACCX(...) "TNS_PM_WR_ACCX"


/**
 * NCB - tns_rdma_cnt#
 *
 * Packets and bytes received by the physical port.
 * All fields have roll over counters.
 * Register number enumerated by TNS_PHYS_PORT_E.
 */
typedef union bdk_tns_rdma_cntx {
	uint64_t u;
	struct bdk_tns_rdma_cntx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t bytes                       : 36; /**< R/W/H - Packet bytes. */
		uint64_t packets                     : 24; /**< R/W/H - Packets. */
#else
		uint64_t packets                     : 24;
		uint64_t bytes                       : 36;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_tns_rdma_cntx_s         cn85xx; */
	/* struct bdk_tns_rdma_cntx_s         cn88xx; */
} bdk_tns_rdma_cntx_t;

static inline uint64_t BDK_TNS_RDMA_CNTX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_CNTX(unsigned long param1)
{
	if (((param1 <= 9)))
		return 0x0000842000001500ull + (param1 & 15) * 0x10ull;
	csr_fatal("BDK_TNS_RDMA_CNTX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_RDMA_CNTX(...) bdk_tns_rdma_cntx_t
#define bustype_BDK_TNS_RDMA_CNTX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_CNTX(p1) (p1)
#define arguments_BDK_TNS_RDMA_CNTX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_RDMA_CNTX(...) "TNS_RDMA_CNTX"


/**
 * NCB - tns_rdma_config
 */
typedef union bdk_tns_rdma_config {
	uint64_t u;
	struct bdk_tns_rdma_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t lmac_bp_enable              : 2;  /**< R/W - Bits correspond to [LMACs7..4, LMACs3..0]. */
		uint64_t nici_bp_enable              : 2;  /**< R/W - Bits correspond to [NICI1, NICI0]. */
#else
		uint64_t nici_bp_enable              : 2;
		uint64_t lmac_bp_enable              : 2;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_tns_rdma_config_s       cn85xx; */
	/* struct bdk_tns_rdma_config_s       cn88xx; */
} bdk_tns_rdma_config_t;

#define BDK_TNS_RDMA_CONFIG BDK_TNS_RDMA_CONFIG_FUNC()
static inline uint64_t BDK_TNS_RDMA_CONFIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_CONFIG_FUNC(void)
{
	return 0x0000842000001200ull;
}
#define typedef_BDK_TNS_RDMA_CONFIG bdk_tns_rdma_config_t
#define bustype_BDK_TNS_RDMA_CONFIG BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_CONFIG 0
#define arguments_BDK_TNS_RDMA_CONFIG -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_CONFIG "TNS_RDMA_CONFIG"


/**
 * NCB - tns_rdma_dbg_cdt_ctl
 *
 * This register provides debug control of packet receipt.
 *
 */
typedef union bdk_tns_rdma_dbg_cdt_ctl {
	uint64_t u;
	struct bdk_tns_rdma_dbg_cdt_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t nbyp_credits_inc            : 2;  /**< WO/H - Each write to this field increments the count of non-bypass credit storage for BGX. */
		uint64_t byp_credits_inc             : 2;  /**< WO/H - Each write to this field increments the count of bypass credit storage for BGX. */
		uint64_t pending_req_inc             : 2;  /**< WO/H - Each write to this field increments the count of pending requests from BGX. */
		uint64_t nbyp_credits_dec            : 2;  /**< WO/H - Each write to this field decrements the count of non-bypass credit storage for BGX. */
		uint64_t byp_credits_dec             : 2;  /**< WO/H - Each write to this field decrements the count of bypass credit storage for BGX. */
		uint64_t pending_req_dec             : 2;  /**< WO/H - Each write to this field decrements the count of pending requests from BGX. */
#else
		uint64_t pending_req_dec             : 2;
		uint64_t byp_credits_dec             : 2;
		uint64_t nbyp_credits_dec            : 2;
		uint64_t pending_req_inc             : 2;
		uint64_t byp_credits_inc             : 2;
		uint64_t nbyp_credits_inc            : 2;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_tns_rdma_dbg_cdt_ctl_s  cn85xx; */
	/* struct bdk_tns_rdma_dbg_cdt_ctl_s  cn88xx; */
} bdk_tns_rdma_dbg_cdt_ctl_t;

#define BDK_TNS_RDMA_DBG_CDT_CTL BDK_TNS_RDMA_DBG_CDT_CTL_FUNC()
static inline uint64_t BDK_TNS_RDMA_DBG_CDT_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_DBG_CDT_CTL_FUNC(void)
{
	return 0x0000842000001A10ull;
}
#define typedef_BDK_TNS_RDMA_DBG_CDT_CTL bdk_tns_rdma_dbg_cdt_ctl_t
#define bustype_BDK_TNS_RDMA_DBG_CDT_CTL BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_DBG_CDT_CTL 0
#define arguments_BDK_TNS_RDMA_DBG_CDT_CTL -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_DBG_CDT_CTL "TNS_RDMA_DBG_CDT_CTL"


/**
 * NCB - tns_rdma_dbg_cx_full
 *
 * This register provides debug control of FIFO full.
 * Async FIFOs assert an early full indication when occupancies reach the values
 * below.
 */
typedef union bdk_tns_rdma_dbg_cx_full {
	uint64_t u;
	struct bdk_tns_rdma_dbg_cx_full_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_37_63              : 27;
		uint64_t lmac_rx_ebp                 : 5;  /**< R/W - EBP received from LMACs. */
		uint64_t reserved_29_31              : 3;
		uint64_t lmac_rx_chan_bp             : 5;  /**< R/W - Channel credit messages received from LMACs. */
		uint64_t reserved_21_23              : 3;
		uint64_t nic_rx_bp                   : 5;  /**< R/W - Back pressure received from NIC. */
		uint64_t reserved_13_15              : 3;
		uint64_t lmac_pkt                    : 5;  /**< R/W - Packets received from LMACs. */
		uint64_t reserved_5_7                : 3;
		uint64_t nic_pkt                     : 5;  /**< R/W - Packets received from NIC. */
#else
		uint64_t nic_pkt                     : 5;
		uint64_t reserved_5_7                : 3;
		uint64_t lmac_pkt                    : 5;
		uint64_t reserved_13_15              : 3;
		uint64_t nic_rx_bp                   : 5;
		uint64_t reserved_21_23              : 3;
		uint64_t lmac_rx_chan_bp             : 5;
		uint64_t reserved_29_31              : 3;
		uint64_t lmac_rx_ebp                 : 5;
		uint64_t reserved_37_63              : 27;
#endif
	} s;
	/* struct bdk_tns_rdma_dbg_cx_full_s  cn85xx; */
	/* struct bdk_tns_rdma_dbg_cx_full_s  cn88xx; */
} bdk_tns_rdma_dbg_cx_full_t;

#define BDK_TNS_RDMA_DBG_CX_FULL BDK_TNS_RDMA_DBG_CX_FULL_FUNC()
static inline uint64_t BDK_TNS_RDMA_DBG_CX_FULL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_DBG_CX_FULL_FUNC(void)
{
	return 0x0000842000001A20ull;
}
#define typedef_BDK_TNS_RDMA_DBG_CX_FULL bdk_tns_rdma_dbg_cx_full_t
#define bustype_BDK_TNS_RDMA_DBG_CX_FULL BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_DBG_CX_FULL 0
#define arguments_BDK_TNS_RDMA_DBG_CX_FULL -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_DBG_CX_FULL "TNS_RDMA_DBG_CX_FULL"


/**
 * NCB - tns_rdma_dbg_cx_occ
 *
 * Async FIFO occupancies.
 *
 */
typedef union bdk_tns_rdma_dbg_cx_occ {
	uint64_t u;
	struct bdk_tns_rdma_dbg_cx_occ_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_61_63              : 3;
		uint64_t lmac7_4_rx_ebp              : 5;  /**< RO/H - EBP received from LMACs 4..7. */
		uint64_t reserved_53_55              : 3;
		uint64_t lmac3_0_rx_ebp              : 5;  /**< RO/H - EBP received from LMACs 0..3. */
		uint64_t reserved_45_47              : 3;
		uint64_t lmac7_4_rx_chan_bp          : 5;  /**< RO/H - Channel credit messages received from LMACs 4..7. */
		uint64_t reserved_37_39              : 3;
		uint64_t lmac3_0_rx_chan_bp          : 5;  /**< RO/H - Channel credit messages received from LMACs 0..3. */
		uint64_t reserved_29_31              : 3;
		uint64_t nici1_rx_bp                 : 5;  /**< RO/H - Back pressure received from NICI1. */
		uint64_t reserved_21_23              : 3;
		uint64_t nici0_rx_bp                 : 5;  /**< RO/H - Back pressure received from NICI0. */
		uint64_t reserved_13_15              : 3;
		uint64_t lmac_pkt                    : 5;  /**< RO/H - Data flits received from LMACs. */
		uint64_t reserved_5_7                : 3;
		uint64_t nic_pkt                     : 5;  /**< RO/H - Data flits received from NIC. */
#else
		uint64_t nic_pkt                     : 5;
		uint64_t reserved_5_7                : 3;
		uint64_t lmac_pkt                    : 5;
		uint64_t reserved_13_15              : 3;
		uint64_t nici0_rx_bp                 : 5;
		uint64_t reserved_21_23              : 3;
		uint64_t nici1_rx_bp                 : 5;
		uint64_t reserved_29_31              : 3;
		uint64_t lmac3_0_rx_chan_bp          : 5;
		uint64_t reserved_37_39              : 3;
		uint64_t lmac7_4_rx_chan_bp          : 5;
		uint64_t reserved_45_47              : 3;
		uint64_t lmac3_0_rx_ebp              : 5;
		uint64_t reserved_53_55              : 3;
		uint64_t lmac7_4_rx_ebp              : 5;
		uint64_t reserved_61_63              : 3;
#endif
	} s;
	/* struct bdk_tns_rdma_dbg_cx_occ_s   cn85xx; */
	/* struct bdk_tns_rdma_dbg_cx_occ_s   cn88xx; */
} bdk_tns_rdma_dbg_cx_occ_t;

#define BDK_TNS_RDMA_DBG_CX_OCC BDK_TNS_RDMA_DBG_CX_OCC_FUNC()
static inline uint64_t BDK_TNS_RDMA_DBG_CX_OCC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_DBG_CX_OCC_FUNC(void)
{
	return 0x0000842000001C20ull;
}
#define typedef_BDK_TNS_RDMA_DBG_CX_OCC bdk_tns_rdma_dbg_cx_occ_t
#define bustype_BDK_TNS_RDMA_DBG_CX_OCC BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_DBG_CX_OCC 0
#define arguments_BDK_TNS_RDMA_DBG_CX_OCC -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_DBG_CX_OCC "TNS_RDMA_DBG_CX_OCC"


/**
 * NCB - tns_rdma_dbg_pkt1_status
 *
 * This register provides debug information of packet receipt status.
 *
 */
typedef union bdk_tns_rdma_dbg_pkt1_status {
	uint64_t u;
	struct bdk_tns_rdma_dbg_pkt1_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_61_63              : 3;
		uint64_t bgx1_x2p_nbyp_credits       : 5;  /**< RO/H - BGX1 X2P non-bypass credits.
                                                                 Non-allocated non-bypass FIFO space.
                                                                 Ranges from 0 through 16. */
		uint64_t bgx1_x2p_byp_credits        : 8;  /**< RO/H - BGX1 X2P bypass credits.
                                                                 Available bypass FIFO space in the TDMA, as determined by credits in RDMA.
                                                                 Ranges from 0 through 96. */
		uint64_t reserved_45_47              : 3;
		uint64_t bgx1_x2p_req_pending        : 5;  /**< RO/H - BGX1 X2P pending requests.
                                                                 X2P requests received that have not yet been granted.
                                                                 Ranges from 0 through 16. */
		uint64_t reserved_37_39              : 3;
		uint64_t bgx1_x2p_fifo_occ           : 5;  /**< RO/H - Non-bypass BGX1 X2P packet FIFO occupancy.
                                                                 Ranges from 0 through 16. */
		uint64_t reserved_29_31              : 3;
		uint64_t bgx0_x2p_nbyp_credits       : 5;  /**< RO/H - BGX0 X2P non-bypass credits.
                                                                 Non-allocated non-bypass FIFO space.
                                                                 Ranges from 0 through 16. */
		uint64_t bgx0_x2p_byp_credits        : 8;  /**< RO/H - BGX0 X2P bypass credits.
                                                                 Available bypass FIFO space in the TDMA, as determined by credits in RDMA.
                                                                 Ranges from 0 through 96. */
		uint64_t reserved_13_15              : 3;
		uint64_t bgx0_x2p_req_pending        : 5;  /**< RO/H - BGX0 X2P pending requests.
                                                                 X2P requests received that have not yet been granted.
                                                                 Ranges from 0 through 16. */
		uint64_t reserved_5_7                : 3;
		uint64_t bgx0_x2p_fifo_occ           : 5;  /**< RO/H - Non-bypass BGX0 X2P packet FIFO occupancy.
                                                                 Ranges from 0 through 16. */
#else
		uint64_t bgx0_x2p_fifo_occ           : 5;
		uint64_t reserved_5_7                : 3;
		uint64_t bgx0_x2p_req_pending        : 5;
		uint64_t reserved_13_15              : 3;
		uint64_t bgx0_x2p_byp_credits        : 8;
		uint64_t bgx0_x2p_nbyp_credits       : 5;
		uint64_t reserved_29_31              : 3;
		uint64_t bgx1_x2p_fifo_occ           : 5;
		uint64_t reserved_37_39              : 3;
		uint64_t bgx1_x2p_req_pending        : 5;
		uint64_t reserved_45_47              : 3;
		uint64_t bgx1_x2p_byp_credits        : 8;
		uint64_t bgx1_x2p_nbyp_credits       : 5;
		uint64_t reserved_61_63              : 3;
#endif
	} s;
	/* struct bdk_tns_rdma_dbg_pkt1_status_s cn85xx; */
	/* struct bdk_tns_rdma_dbg_pkt1_status_s cn88xx; */
} bdk_tns_rdma_dbg_pkt1_status_t;

#define BDK_TNS_RDMA_DBG_PKT1_STATUS BDK_TNS_RDMA_DBG_PKT1_STATUS_FUNC()
static inline uint64_t BDK_TNS_RDMA_DBG_PKT1_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_DBG_PKT1_STATUS_FUNC(void)
{
	return 0x0000842000001C00ull;
}
#define typedef_BDK_TNS_RDMA_DBG_PKT1_STATUS bdk_tns_rdma_dbg_pkt1_status_t
#define bustype_BDK_TNS_RDMA_DBG_PKT1_STATUS BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_DBG_PKT1_STATUS 0
#define arguments_BDK_TNS_RDMA_DBG_PKT1_STATUS -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_DBG_PKT1_STATUS "TNS_RDMA_DBG_PKT1_STATUS"


/**
 * NCB - tns_rdma_dbg_pkt2_status
 *
 * This register provides debug information of packet receipt status.
 *
 */
typedef union bdk_tns_rdma_dbg_pkt2_status {
	uint64_t u;
	struct bdk_tns_rdma_dbg_pkt2_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t nic_p2x_fifo_occ            : 6;  /**< RO/H - Non-bypass NIC P2X packet FIFO occupancy. */
#else
		uint64_t nic_p2x_fifo_occ            : 6;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_tns_rdma_dbg_pkt2_status_s cn85xx; */
	/* struct bdk_tns_rdma_dbg_pkt2_status_s cn88xx; */
} bdk_tns_rdma_dbg_pkt2_status_t;

#define BDK_TNS_RDMA_DBG_PKT2_STATUS BDK_TNS_RDMA_DBG_PKT2_STATUS_FUNC()
static inline uint64_t BDK_TNS_RDMA_DBG_PKT2_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_DBG_PKT2_STATUS_FUNC(void)
{
	return 0x0000842000001C10ull;
}
#define typedef_BDK_TNS_RDMA_DBG_PKT2_STATUS bdk_tns_rdma_dbg_pkt2_status_t
#define bustype_BDK_TNS_RDMA_DBG_PKT2_STATUS BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_DBG_PKT2_STATUS 0
#define arguments_BDK_TNS_RDMA_DBG_PKT2_STATUS -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_DBG_PKT2_STATUS "TNS_RDMA_DBG_PKT2_STATUS"


/**
 * NCB - tns_rdma_dbg_pkt_ctl
 *
 * This register provides debug control of packet receipt.
 *
 */
typedef union bdk_tns_rdma_dbg_pkt_ctl {
	uint64_t u;
	struct bdk_tns_rdma_dbg_pkt_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t rtn_nici_cdt                : 2;  /**< WO/H - Each write to this field returns 1 packet skid credit to [NICI1, NICI0]. */
#else
		uint64_t rtn_nici_cdt                : 2;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_tns_rdma_dbg_pkt_ctl_s  cn85xx; */
	/* struct bdk_tns_rdma_dbg_pkt_ctl_s  cn88xx; */
} bdk_tns_rdma_dbg_pkt_ctl_t;

#define BDK_TNS_RDMA_DBG_PKT_CTL BDK_TNS_RDMA_DBG_PKT_CTL_FUNC()
static inline uint64_t BDK_TNS_RDMA_DBG_PKT_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_DBG_PKT_CTL_FUNC(void)
{
	return 0x0000842000001A00ull;
}
#define typedef_BDK_TNS_RDMA_DBG_PKT_CTL bdk_tns_rdma_dbg_pkt_ctl_t
#define bustype_BDK_TNS_RDMA_DBG_PKT_CTL BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_DBG_PKT_CTL 0
#define arguments_BDK_TNS_RDMA_DBG_PKT_CTL -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_DBG_PKT_CTL "TNS_RDMA_DBG_PKT_CTL"


/**
 * NCB - tns_rdma_dbgb_sel
 *
 * Debug bus select register.
 *
 */
typedef union bdk_tns_rdma_dbgb_sel {
	uint64_t u;
	struct bdk_tns_rdma_dbgb_sel_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t sel1                        : 24; /**< R/W - Select group for upper debug bus bits */
		uint64_t sel0                        : 24; /**< R/W - Select group for lower debug bus bits */
#else
		uint64_t sel0                        : 24;
		uint64_t sel1                        : 24;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_tns_rdma_dbgb_sel_s     cn85xx; */
	/* struct bdk_tns_rdma_dbgb_sel_s     cn88xx; */
} bdk_tns_rdma_dbgb_sel_t;

#define BDK_TNS_RDMA_DBGB_SEL BDK_TNS_RDMA_DBGB_SEL_FUNC()
static inline uint64_t BDK_TNS_RDMA_DBGB_SEL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_DBGB_SEL_FUNC(void)
{
	return 0x0000842000001E00ull;
}
#define typedef_BDK_TNS_RDMA_DBGB_SEL bdk_tns_rdma_dbgb_sel_t
#define bustype_BDK_TNS_RDMA_DBGB_SEL BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_DBGB_SEL 0
#define arguments_BDK_TNS_RDMA_DBGB_SEL -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_DBGB_SEL "TNS_RDMA_DBGB_SEL"


/**
 * NCB - tns_rdma_ecc_ctl
 *
 * This register can be used to disable ECC checks, insert ECC errors.
 * Fields *ECC_DIS disable SBE detection/correction and DBE detection. If ECC_DIS is 0x1, then no
 * errors are detected.
 * Fields *ECC_FLIP_SYND flip the syndrome<1:0> bits to generate 1-bit/2-bit error for testing.
 * * 0x0 = normal operation
 * * 0x1 = SBE on bit<0>
 * * 0x2 = SBE on bit<1>
 * * 0x3 = DBE on bits<1:0>
 */
typedef union bdk_tns_rdma_ecc_ctl {
	uint64_t u;
	struct bdk_tns_rdma_ecc_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_35_63              : 29;
		uint64_t b_x2p_ecc_dis               : 2;  /**< R/W - Disable ECC for B_X2P[1..0] RAM. */
		uint64_t b_p2x_ecc_dis               : 1;  /**< R/W - Disable ECC for B_P2X RAM. */
		uint64_t reserved_6_31               : 26;
		uint64_t b_x2p1_ecc_flip_synd        : 2;  /**< R/W - Flip syndrome for all data written to B_X2P1 RAM. */
		uint64_t b_x2p0_ecc_flip_synd        : 2;  /**< R/W - Flip syndrome for all data written to B_X2P0 RAM. */
		uint64_t b_p2x_ecc_flip_synd         : 2;  /**< R/W - Flip syndrome for all data written to B_P2X RAM. */
#else
		uint64_t b_p2x_ecc_flip_synd         : 2;
		uint64_t b_x2p0_ecc_flip_synd        : 2;
		uint64_t b_x2p1_ecc_flip_synd        : 2;
		uint64_t reserved_6_31               : 26;
		uint64_t b_p2x_ecc_dis               : 1;
		uint64_t b_x2p_ecc_dis               : 2;
		uint64_t reserved_35_63              : 29;
#endif
	} s;
	/* struct bdk_tns_rdma_ecc_ctl_s      cn85xx; */
	/* struct bdk_tns_rdma_ecc_ctl_s      cn88xx; */
} bdk_tns_rdma_ecc_ctl_t;

#define BDK_TNS_RDMA_ECC_CTL BDK_TNS_RDMA_ECC_CTL_FUNC()
static inline uint64_t BDK_TNS_RDMA_ECC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_ECC_CTL_FUNC(void)
{
	return 0x0000842000001800ull;
}
#define typedef_BDK_TNS_RDMA_ECC_CTL bdk_tns_rdma_ecc_ctl_t
#define bustype_BDK_TNS_RDMA_ECC_CTL BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_ECC_CTL 0
#define arguments_BDK_TNS_RDMA_ECC_CTL -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_ECC_CTL "TNS_RDMA_ECC_CTL"


/**
 * NCB - tns_rdma_ecc_err_stat
 *
 * This register logs information to help debug ECC errors.
 *
 */
typedef union bdk_tns_rdma_ecc_err_stat {
	uint64_t u;
	struct bdk_tns_rdma_ecc_err_stat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_17_63              : 47;
		uint64_t syndrome                    : 9;  /**< RO/H - Error syndrome. */
		uint64_t reserved_5_7                : 3;
		uint64_t address                     : 5;  /**< RO/H - Address of ECC error. */
#else
		uint64_t address                     : 5;
		uint64_t reserved_5_7                : 3;
		uint64_t syndrome                    : 9;
		uint64_t reserved_17_63              : 47;
#endif
	} s;
	/* struct bdk_tns_rdma_ecc_err_stat_s cn85xx; */
	/* struct bdk_tns_rdma_ecc_err_stat_s cn88xx; */
} bdk_tns_rdma_ecc_err_stat_t;

#define BDK_TNS_RDMA_ECC_ERR_STAT BDK_TNS_RDMA_ECC_ERR_STAT_FUNC()
static inline uint64_t BDK_TNS_RDMA_ECC_ERR_STAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_ECC_ERR_STAT_FUNC(void)
{
	return 0x0000842000001810ull;
}
#define typedef_BDK_TNS_RDMA_ECC_ERR_STAT bdk_tns_rdma_ecc_err_stat_t
#define bustype_BDK_TNS_RDMA_ECC_ERR_STAT BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_ECC_ERR_STAT 0
#define arguments_BDK_TNS_RDMA_ECC_ERR_STAT -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_ECC_ERR_STAT "TNS_RDMA_ECC_ERR_STAT"


/**
 * NCB - tns_rdma_eco
 *
 * ECO register.
 *
 */
typedef union bdk_tns_rdma_eco {
	uint64_t u;
	struct bdk_tns_rdma_eco_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t rst1                        : 8;  /**< R/W - Reset to 1 spare bits */
		uint64_t rst0                        : 8;  /**< R/W - Reset to 0 spare bits */
#else
		uint64_t rst0                        : 8;
		uint64_t rst1                        : 8;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_tns_rdma_eco_s          cn85xx; */
	/* struct bdk_tns_rdma_eco_s          cn88xx; */
} bdk_tns_rdma_eco_t;

#define BDK_TNS_RDMA_ECO BDK_TNS_RDMA_ECO_FUNC()
static inline uint64_t BDK_TNS_RDMA_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_ECO_FUNC(void)
{
	return 0x0000842000001F00ull;
}
#define typedef_BDK_TNS_RDMA_ECO bdk_tns_rdma_eco_t
#define bustype_BDK_TNS_RDMA_ECO BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_ECO 0
#define arguments_BDK_TNS_RDMA_ECO -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_ECO "TNS_RDMA_ECO"


/**
 * NCB - tns_rdma_hdr_ts_cfg
 *
 * This register is used to indicate that all packets arriving on a LMAC port
 * are prepended with an 8-byte timestamp that must be extracted.
 * Timestamp bytes received from the BGX (if enabled) are not counted as part of the
 * header.
 * The extraction occurs blindly, assuming all packets have a timestamp.
 * Unpredictable behavior may occur if software changes the timestamp configuration
 * for a port while packets are being received.
 * Unpredictable behavior may occur if timestamp extraction is enabled and a packet
 * is received on the port without a prepended timestamp.
 */
typedef union bdk_tns_rdma_hdr_ts_cfg {
	uint64_t u;
	struct bdk_tns_rdma_hdr_ts_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t lmac                        : 8;  /**< R/W - Each bit corresponds to 1 LMAC.
                                                                 For each bit, when set to 0x1, the first 8 bytes of every packet received from the LMAC
                                                                 will be interpreted as timestamp information. */
#else
		uint64_t lmac                        : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_tns_rdma_hdr_ts_cfg_s   cn85xx; */
	/* struct bdk_tns_rdma_hdr_ts_cfg_s   cn88xx; */
} bdk_tns_rdma_hdr_ts_cfg_t;

#define BDK_TNS_RDMA_HDR_TS_CFG BDK_TNS_RDMA_HDR_TS_CFG_FUNC()
static inline uint64_t BDK_TNS_RDMA_HDR_TS_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_HDR_TS_CFG_FUNC(void)
{
	return 0x0000842000001210ull;
}
#define typedef_BDK_TNS_RDMA_HDR_TS_CFG bdk_tns_rdma_hdr_ts_cfg_t
#define bustype_BDK_TNS_RDMA_HDR_TS_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_HDR_TS_CFG 0
#define arguments_BDK_TNS_RDMA_HDR_TS_CFG -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_HDR_TS_CFG "TNS_RDMA_HDR_TS_CFG"


/**
 * NCB - tns_rdma_int_en_w1c
 *
 * RDMA Interrupt Enable Register.
 *
 */
typedef union bdk_tns_rdma_int_en_w1c {
	uint64_t u;
	struct bdk_tns_rdma_int_en_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t lmac_unex_data              : 8;  /**< R/W1C - Unexpected data from LMAC. Data was received before an SOP flag was received. The data was dropped. */
		uint64_t lmac_unex_sop               : 8;  /**< R/W1C - Unexpected SOP from LMAC An SOP was received while a packet is already being received. The
                                                                 in-progress packet and the new packet initiated by the SOP were dropped. */
		uint64_t lmac_srunt                  : 8;  /**< R/W1C - A packet was received from the LMAC which did not meet framing requirements for minimum size. */
		uint64_t reserved_7_7                : 1;
		uint64_t b_x2p_dbe                   : 2;  /**< R/W1C - Double-bit ECC error detected on B_X2P[1..0] RAM */
		uint64_t b_p2x_dbe                   : 1;  /**< R/W1C - Double-bit ECC error detected on B_P2X RAM. */
		uint64_t reserved_3_3                : 1;
		uint64_t b_x2p_sbe                   : 2;  /**< R/W1C - Single-bit ECC error detected on B_X2P[1..0] RAM */
		uint64_t b_p2x_sbe                   : 1;  /**< R/W1C - Single-bit ECC error detected on B_P2X RAM. */
#else
		uint64_t b_p2x_sbe                   : 1;
		uint64_t b_x2p_sbe                   : 2;
		uint64_t reserved_3_3                : 1;
		uint64_t b_p2x_dbe                   : 1;
		uint64_t b_x2p_dbe                   : 2;
		uint64_t reserved_7_7                : 1;
		uint64_t lmac_srunt                  : 8;
		uint64_t lmac_unex_sop               : 8;
		uint64_t lmac_unex_data              : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_tns_rdma_int_en_w1c_s   cn85xx; */
	/* struct bdk_tns_rdma_int_en_w1c_s   cn88xx; */
} bdk_tns_rdma_int_en_w1c_t;

#define BDK_TNS_RDMA_INT_EN_W1C BDK_TNS_RDMA_INT_EN_W1C_FUNC()
static inline uint64_t BDK_TNS_RDMA_INT_EN_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_INT_EN_W1C_FUNC(void)
{
	return 0x0000842000001130ull;
}
#define typedef_BDK_TNS_RDMA_INT_EN_W1C bdk_tns_rdma_int_en_w1c_t
#define bustype_BDK_TNS_RDMA_INT_EN_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_INT_EN_W1C 0
#define arguments_BDK_TNS_RDMA_INT_EN_W1C -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_INT_EN_W1C "TNS_RDMA_INT_EN_W1C"


/**
 * NCB - tns_rdma_int_en_w1s
 *
 * RDMA Interrupt Enable Register.
 *
 */
typedef union bdk_tns_rdma_int_en_w1s {
	uint64_t u;
	struct bdk_tns_rdma_int_en_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t lmac_unex_data              : 8;  /**< R/W1S - Unexpected data from LMAC. Data was received before an SOP flag was received. The data was dropped. */
		uint64_t lmac_unex_sop               : 8;  /**< R/W1S - Unexpected SOP from LMAC An SOP was received while a packet is already being received. The
                                                                 in-progress packet and the new packet initiated by the SOP were dropped. */
		uint64_t lmac_srunt                  : 8;  /**< R/W1S - A packet was received from the LMAC which did not meet framing requirements for minimum size. */
		uint64_t reserved_7_7                : 1;
		uint64_t b_x2p_dbe                   : 2;  /**< R/W1S - Double-bit ECC error detected on B_X2P[1..0] RAM. */
		uint64_t b_p2x_dbe                   : 1;  /**< R/W1S - Double-bit ECC error detected on B_P2X RAM. */
		uint64_t reserved_3_3                : 1;
		uint64_t b_x2p_sbe                   : 2;  /**< R/W1S - Single-bit ECC error detected on B_X2P[1..0] RAM. */
		uint64_t b_p2x_sbe                   : 1;  /**< R/W1S - Single-bit ECC error detected on B_P2X RAM. */
#else
		uint64_t b_p2x_sbe                   : 1;
		uint64_t b_x2p_sbe                   : 2;
		uint64_t reserved_3_3                : 1;
		uint64_t b_p2x_dbe                   : 1;
		uint64_t b_x2p_dbe                   : 2;
		uint64_t reserved_7_7                : 1;
		uint64_t lmac_srunt                  : 8;
		uint64_t lmac_unex_sop               : 8;
		uint64_t lmac_unex_data              : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_tns_rdma_int_en_w1s_s   cn85xx; */
	/* struct bdk_tns_rdma_int_en_w1s_s   cn88xx; */
} bdk_tns_rdma_int_en_w1s_t;

#define BDK_TNS_RDMA_INT_EN_W1S BDK_TNS_RDMA_INT_EN_W1S_FUNC()
static inline uint64_t BDK_TNS_RDMA_INT_EN_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_INT_EN_W1S_FUNC(void)
{
	return 0x0000842000001120ull;
}
#define typedef_BDK_TNS_RDMA_INT_EN_W1S bdk_tns_rdma_int_en_w1s_t
#define bustype_BDK_TNS_RDMA_INT_EN_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_INT_EN_W1S 0
#define arguments_BDK_TNS_RDMA_INT_EN_W1S -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_INT_EN_W1S "TNS_RDMA_INT_EN_W1S"


/**
 * NCB - tns_rdma_int_fen_w1c
 *
 * RDMA Interrupt First Enable Register.
 *
 */
typedef union bdk_tns_rdma_int_fen_w1c {
	uint64_t u;
	struct bdk_tns_rdma_int_fen_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t lmac_unex_data              : 8;  /**< R/W1C - Unexpected data from LMAC. Data was received before an SOP flag was received. The data was dropped. */
		uint64_t lmac_unex_sop               : 8;  /**< R/W1C - Unexpected SOP from LMAC An SOP was received while a packet is already being received. The
                                                                 in-progress packet and the new packet initiated by the SOP were dropped. */
		uint64_t lmac_srunt                  : 8;  /**< R/W1C - A packet was received from the LMAC which did not meet framing requirements for minimum size. */
		uint64_t reserved_7_7                : 1;
		uint64_t b_x2p_dbe                   : 2;  /**< R/W1C - Double-bit ECC error detected on B_X2P[1..0] RAM. */
		uint64_t b_p2x_dbe                   : 1;  /**< R/W1C - Double-bit ECC error detected on B_P2X RAM. */
		uint64_t reserved_3_3                : 1;
		uint64_t b_x2p_sbe                   : 2;  /**< R/W1C - Single-bit ECC error detected on B_X2P[1..0] RAM. */
		uint64_t b_p2x_sbe                   : 1;  /**< R/W1C - Single-bit ECC error detected on B_P2X RAM. */
#else
		uint64_t b_p2x_sbe                   : 1;
		uint64_t b_x2p_sbe                   : 2;
		uint64_t reserved_3_3                : 1;
		uint64_t b_p2x_dbe                   : 1;
		uint64_t b_x2p_dbe                   : 2;
		uint64_t reserved_7_7                : 1;
		uint64_t lmac_srunt                  : 8;
		uint64_t lmac_unex_sop               : 8;
		uint64_t lmac_unex_data              : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_tns_rdma_int_fen_w1c_s  cn85xx; */
	/* struct bdk_tns_rdma_int_fen_w1c_s  cn88xx; */
} bdk_tns_rdma_int_fen_w1c_t;

#define BDK_TNS_RDMA_INT_FEN_W1C BDK_TNS_RDMA_INT_FEN_W1C_FUNC()
static inline uint64_t BDK_TNS_RDMA_INT_FEN_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_INT_FEN_W1C_FUNC(void)
{
	return 0x0000842000001160ull;
}
#define typedef_BDK_TNS_RDMA_INT_FEN_W1C bdk_tns_rdma_int_fen_w1c_t
#define bustype_BDK_TNS_RDMA_INT_FEN_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_INT_FEN_W1C 0
#define arguments_BDK_TNS_RDMA_INT_FEN_W1C -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_INT_FEN_W1C "TNS_RDMA_INT_FEN_W1C"


/**
 * NCB - tns_rdma_int_fen_w1s
 *
 * RDMA Interrupt First Enable Register.
 *
 */
typedef union bdk_tns_rdma_int_fen_w1s {
	uint64_t u;
	struct bdk_tns_rdma_int_fen_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t lmac_unex_data              : 8;  /**< R/W1S - Unexpected data from LMAC. Data was received before an SOP flag was received. The data was dropped. */
		uint64_t lmac_unex_sop               : 8;  /**< R/W1S - Unexpected SOP from LMAC An SOP was received while a packet is already being received. The
                                                                 in-progress packet and the new packet initiated by the SOP were dropped. */
		uint64_t lmac_srunt                  : 8;  /**< R/W1S - A packet was received from the LMAC which did not meet framing requirements for minimum size. */
		uint64_t reserved_7_7                : 1;
		uint64_t b_x2p_dbe                   : 2;  /**< R/W1S - Double-bit ECC error detected on B_X2P[1..0] RAM. */
		uint64_t b_p2x_dbe                   : 1;  /**< R/W1S - Double-bit ECC error detected on B_P2X RAM. */
		uint64_t reserved_3_3                : 1;
		uint64_t b_x2p_sbe                   : 2;  /**< R/W1S - Single-bit ECC error detected on B_X2P[1..0] RAM. */
		uint64_t b_p2x_sbe                   : 1;  /**< R/W1S - Single-bit ECC error detected on B_P2X RAM. */
#else
		uint64_t b_p2x_sbe                   : 1;
		uint64_t b_x2p_sbe                   : 2;
		uint64_t reserved_3_3                : 1;
		uint64_t b_p2x_dbe                   : 1;
		uint64_t b_x2p_dbe                   : 2;
		uint64_t reserved_7_7                : 1;
		uint64_t lmac_srunt                  : 8;
		uint64_t lmac_unex_sop               : 8;
		uint64_t lmac_unex_data              : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_tns_rdma_int_fen_w1s_s  cn85xx; */
	/* struct bdk_tns_rdma_int_fen_w1s_s  cn88xx; */
} bdk_tns_rdma_int_fen_w1s_t;

#define BDK_TNS_RDMA_INT_FEN_W1S BDK_TNS_RDMA_INT_FEN_W1S_FUNC()
static inline uint64_t BDK_TNS_RDMA_INT_FEN_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_INT_FEN_W1S_FUNC(void)
{
	return 0x0000842000001150ull;
}
#define typedef_BDK_TNS_RDMA_INT_FEN_W1S bdk_tns_rdma_int_fen_w1s_t
#define bustype_BDK_TNS_RDMA_INT_FEN_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_INT_FEN_W1S 0
#define arguments_BDK_TNS_RDMA_INT_FEN_W1S -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_INT_FEN_W1S "TNS_RDMA_INT_FEN_W1S"


/**
 * NCB - tns_rdma_int_fstat
 *
 * RDMA Interrupt First Status Register.
 * Indicates which interrupt asserted first.
 * This register holds its non-zero value until all TNS_RDMA_INT_STAT_W1S register bits,
 * as enabled by TNS_RDMA_INT_FIRST_EN_W1S, are cleared to 0x0.
 */
typedef union bdk_tns_rdma_int_fstat {
	uint64_t u;
	struct bdk_tns_rdma_int_fstat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t lmac_unex_data              : 8;  /**< RO/H - Unexpected data from LMAC. Data was received before an SOP flag was received. The data was dropped. */
		uint64_t lmac_unex_sop               : 8;  /**< RO/H - Unexpected SOP from LMAC An SOP was received while a packet is already being received. The
                                                                 in-progress packet and the new packet initiated by the SOP were dropped. */
		uint64_t lmac_srunt                  : 8;  /**< RO/H - A packet was received from the LMAC which did not meet framing requirements for minimum size. */
		uint64_t reserved_7_7                : 1;
		uint64_t b_x2p_dbe                   : 2;  /**< RO/H - Double-bit ECC error detected on B_X2P[1..0] RAM. */
		uint64_t b_p2x_dbe                   : 1;  /**< RO/H - Double-bit ECC error detected on B_P2X RAM. */
		uint64_t reserved_3_3                : 1;
		uint64_t b_x2p_sbe                   : 2;  /**< RO/H - Single-bit ECC error detected on B_X2P[1..0] RAM. */
		uint64_t b_p2x_sbe                   : 1;  /**< RO/H - Single-bit ECC error detected on B_P2X RAM. */
#else
		uint64_t b_p2x_sbe                   : 1;
		uint64_t b_x2p_sbe                   : 2;
		uint64_t reserved_3_3                : 1;
		uint64_t b_p2x_dbe                   : 1;
		uint64_t b_x2p_dbe                   : 2;
		uint64_t reserved_7_7                : 1;
		uint64_t lmac_srunt                  : 8;
		uint64_t lmac_unex_sop               : 8;
		uint64_t lmac_unex_data              : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_tns_rdma_int_fstat_s    cn85xx; */
	/* struct bdk_tns_rdma_int_fstat_s    cn88xx; */
} bdk_tns_rdma_int_fstat_t;

#define BDK_TNS_RDMA_INT_FSTAT BDK_TNS_RDMA_INT_FSTAT_FUNC()
static inline uint64_t BDK_TNS_RDMA_INT_FSTAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_INT_FSTAT_FUNC(void)
{
	return 0x0000842000001140ull;
}
#define typedef_BDK_TNS_RDMA_INT_FSTAT bdk_tns_rdma_int_fstat_t
#define bustype_BDK_TNS_RDMA_INT_FSTAT BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_INT_FSTAT 0
#define arguments_BDK_TNS_RDMA_INT_FSTAT -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_INT_FSTAT "TNS_RDMA_INT_FSTAT"


/**
 * NCB - tns_rdma_int_stat_w1c
 *
 * RDMA Interrupt Status Register.
 *
 */
typedef union bdk_tns_rdma_int_stat_w1c {
	uint64_t u;
	struct bdk_tns_rdma_int_stat_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t lmac_unex_data              : 8;  /**< R/W1C/H - Unexpected data from LMAC. Data was received before an SOP flag was received. The data was dropped. */
		uint64_t lmac_unex_sop               : 8;  /**< R/W1C/H - Unexpected SOP from LMAC An SOP was received while a packet is already being received. The
                                                                 in-progress packet and the new packet initiated by the SOP were dropped. */
		uint64_t lmac_srunt                  : 8;  /**< R/W1C/H - A packet was received from the LMAC which did not meet framing requirements for minimum size. */
		uint64_t reserved_7_7                : 1;
		uint64_t b_x2p_dbe                   : 2;  /**< R/W1C/H - Double-bit ECC error detected on B_X2P[1..0] RAM. */
		uint64_t b_p2x_dbe                   : 1;  /**< R/W1C/H - Double-bit ECC error detected on B_P2X RAM. */
		uint64_t reserved_3_3                : 1;
		uint64_t b_x2p_sbe                   : 2;  /**< R/W1C/H - Single-bit ECC error detected on B_X2P[1..0] RAM. */
		uint64_t b_p2x_sbe                   : 1;  /**< R/W1C/H - Single-bit ECC error detected on B_P2X RAM. */
#else
		uint64_t b_p2x_sbe                   : 1;
		uint64_t b_x2p_sbe                   : 2;
		uint64_t reserved_3_3                : 1;
		uint64_t b_p2x_dbe                   : 1;
		uint64_t b_x2p_dbe                   : 2;
		uint64_t reserved_7_7                : 1;
		uint64_t lmac_srunt                  : 8;
		uint64_t lmac_unex_sop               : 8;
		uint64_t lmac_unex_data              : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_tns_rdma_int_stat_w1c_s cn85xx; */
	/* struct bdk_tns_rdma_int_stat_w1c_s cn88xx; */
} bdk_tns_rdma_int_stat_w1c_t;

#define BDK_TNS_RDMA_INT_STAT_W1C BDK_TNS_RDMA_INT_STAT_W1C_FUNC()
static inline uint64_t BDK_TNS_RDMA_INT_STAT_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_INT_STAT_W1C_FUNC(void)
{
	return 0x0000842000001110ull;
}
#define typedef_BDK_TNS_RDMA_INT_STAT_W1C bdk_tns_rdma_int_stat_w1c_t
#define bustype_BDK_TNS_RDMA_INT_STAT_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_INT_STAT_W1C 0
#define arguments_BDK_TNS_RDMA_INT_STAT_W1C -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_INT_STAT_W1C "TNS_RDMA_INT_STAT_W1C"


/**
 * NCB - tns_rdma_int_stat_w1s
 *
 * RDMA Interrupt Status Register.
 *
 */
typedef union bdk_tns_rdma_int_stat_w1s {
	uint64_t u;
	struct bdk_tns_rdma_int_stat_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t lmac_unex_data              : 8;  /**< R/W1S/H - Unexpected data from LMAC. Data was received before an SOP flag was received. The data was dropped. */
		uint64_t lmac_unex_sop               : 8;  /**< R/W1S/H - Unexpected SOP from LMAC An SOP was received while a packet is already being received. The
                                                                 in-progress packet and the new packet initiated by the SOP were dropped. */
		uint64_t lmac_srunt                  : 8;  /**< R/W1S/H - A packet was received from the LMAC which did not meet framing requirements for minimum size. */
		uint64_t reserved_7_7                : 1;
		uint64_t b_x2p_dbe                   : 2;  /**< R/W1S/H - Double-bit ECC error detected on B_X2P[1..0] RAM. */
		uint64_t b_p2x_dbe                   : 1;  /**< R/W1S/H - Double-bit ECC error detected on B_P2X RAM. */
		uint64_t reserved_3_3                : 1;
		uint64_t b_x2p_sbe                   : 2;  /**< R/W1S/H - Single-bit ECC error detected on B_X2P[1..0] RAM. */
		uint64_t b_p2x_sbe                   : 1;  /**< R/W1S/H - Single-bit ECC error detected on B_P2X RAM. */
#else
		uint64_t b_p2x_sbe                   : 1;
		uint64_t b_x2p_sbe                   : 2;
		uint64_t reserved_3_3                : 1;
		uint64_t b_p2x_dbe                   : 1;
		uint64_t b_x2p_dbe                   : 2;
		uint64_t reserved_7_7                : 1;
		uint64_t lmac_srunt                  : 8;
		uint64_t lmac_unex_sop               : 8;
		uint64_t lmac_unex_data              : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_tns_rdma_int_stat_w1s_s cn85xx; */
	/* struct bdk_tns_rdma_int_stat_w1s_s cn88xx; */
} bdk_tns_rdma_int_stat_w1s_t;

#define BDK_TNS_RDMA_INT_STAT_W1S BDK_TNS_RDMA_INT_STAT_W1S_FUNC()
static inline uint64_t BDK_TNS_RDMA_INT_STAT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_INT_STAT_W1S_FUNC(void)
{
	return 0x0000842000001100ull;
}
#define typedef_BDK_TNS_RDMA_INT_STAT_W1S bdk_tns_rdma_int_stat_w1s_t
#define bustype_BDK_TNS_RDMA_INT_STAT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_INT_STAT_W1S 0
#define arguments_BDK_TNS_RDMA_INT_STAT_W1S -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_INT_STAT_W1S "TNS_RDMA_INT_STAT_W1S"


/**
 * NCB - tns_rdma_lmac#_drop_cnt
 *
 * A packet received from BGX is immediately dropped if timestamp extraction
 * is enabled for the LMAC and the packet arriving at the TNS is not large enough
 * to contain a full 8-byte timestamp and at least 1-byte of packet data.
 * This register counts all packets dropped due to insufficient packet size when
 * timestamp extraction is enabled.
 * This counter rolls over.
 */
typedef union bdk_tns_rdma_lmacx_drop_cnt {
	uint64_t u;
	struct bdk_tns_rdma_lmacx_drop_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t packets                     : 8;  /**< R/W/H - Dropped packets arriving from LMAC. */
#else
		uint64_t packets                     : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_tns_rdma_lmacx_drop_cnt_s cn85xx; */
	/* struct bdk_tns_rdma_lmacx_drop_cnt_s cn88xx; */
} bdk_tns_rdma_lmacx_drop_cnt_t;

static inline uint64_t BDK_TNS_RDMA_LMACX_DROP_CNT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_LMACX_DROP_CNT(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000842000001600ull + (param1 & 7) * 0x10ull;
	csr_fatal("BDK_TNS_RDMA_LMACX_DROP_CNT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_RDMA_LMACX_DROP_CNT(...) bdk_tns_rdma_lmacx_drop_cnt_t
#define bustype_BDK_TNS_RDMA_LMACX_DROP_CNT(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_LMACX_DROP_CNT(p1) (p1)
#define arguments_BDK_TNS_RDMA_LMACX_DROP_CNT(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_RDMA_LMACX_DROP_CNT(...) "TNS_RDMA_LMACX_DROP_CNT"


/**
 * NCB - tns_rdma_nb_cnt_lb
 *
 * Packets and bytes received by the loopback port.
 * All fields have roll over counters.
 */
typedef union bdk_tns_rdma_nb_cnt_lb {
	uint64_t u;
	struct bdk_tns_rdma_nb_cnt_lb_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t bytes                       : 36; /**< R/W/H - Packet bytes. */
		uint64_t packets                     : 24; /**< R/W/H - Packets. */
#else
		uint64_t packets                     : 24;
		uint64_t bytes                       : 36;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_cnt_lb_s    cn85xx; */
	/* struct bdk_tns_rdma_nb_cnt_lb_s    cn88xx; */
} bdk_tns_rdma_nb_cnt_lb_t;

#define BDK_TNS_RDMA_NB_CNT_LB BDK_TNS_RDMA_NB_CNT_LB_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_CNT_LB_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_CNT_LB_FUNC(void)
{
	return 0x0000842042000200ull;
}
#define typedef_BDK_TNS_RDMA_NB_CNT_LB bdk_tns_rdma_nb_cnt_lb_t
#define bustype_BDK_TNS_RDMA_NB_CNT_LB BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_CNT_LB 0
#define arguments_BDK_TNS_RDMA_NB_CNT_LB -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_CNT_LB "TNS_RDMA_NB_CNT_LB"


/**
 * NCB - tns_rdma_nb_config
 *
 * General configuration register.
 *
 */
typedef union bdk_tns_rdma_nb_config {
	uint64_t u;
	struct bdk_tns_rdma_nb_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t master_en                   : 1;  /**< R/W/H - Master RDMA enable.
                                                                 When set to 0x1, allows functional use of the network switch.
                                                                 Usage of hardware auto-initialization will clear this field. */
		uint64_t reserved_0_62               : 63;
#else
		uint64_t reserved_0_62               : 63;
		uint64_t master_en                   : 1;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_config_s    cn85xx; */
	/* struct bdk_tns_rdma_nb_config_s    cn88xx; */
} bdk_tns_rdma_nb_config_t;

#define BDK_TNS_RDMA_NB_CONFIG BDK_TNS_RDMA_NB_CONFIG_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_CONFIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_CONFIG_FUNC(void)
{
	return 0x0000842042004020ull;
}
#define typedef_BDK_TNS_RDMA_NB_CONFIG bdk_tns_rdma_nb_config_t
#define bustype_BDK_TNS_RDMA_NB_CONFIG BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_CONFIG 0
#define arguments_BDK_TNS_RDMA_NB_CONFIG -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_CONFIG "TNS_RDMA_NB_CONFIG"


/**
 * NCB - tns_rdma_nb_dbg_config
 *
 * This register provides debug control of RDMA functionality.
 *
 */
typedef union bdk_tns_rdma_nb_dbg_config {
	uint64_t u;
	struct bdk_tns_rdma_nb_dbg_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_61_63              : 3;
		uint64_t sdma_fifo_bp                : 5;  /**< R/W - Occupancy level at which the SDMA will assert back pressure to the SDE. */
		uint64_t reserved_14_55              : 42;
		uint64_t body_ptr_error_value        : 10; /**< R/W - When SDE Parser is configured to allow a RX port to operate in cut-through mode, the
                                                                 indication of an error for a single-page (header only) packet must be sent along with
                                                                 the packet header because the SDE will ignore the EOP message.
                                                                 In the event a header-only sized packet is received with error or an error is detected
                                                                 in the RDMA (e.g. in the event of runt or ECC error) bits 13:4 of the non-valid packet
                                                                 body pointer will be set to the value indicated by this field, with a 4-bit error code
                                                                 inserted in bits 3:0.
                                                                 The allowable range of values for this field must reflect page pointers that would
                                                                 never be present in the system.
                                                                 14-bit body page values from 0x3000 through 0x3fff are not supported by
                                                                 the 3MB TNS Packet Memory.
                                                                 Therefore, any body pointer value within this range is acceptable to indicate error.
                                                                 This field must be configured to match the corresponding CSR value in the SDE Parser.
                                                                 This field must never be set to a value below 0x300. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t body_ptr_error_value        : 10;
		uint64_t reserved_14_55              : 42;
		uint64_t sdma_fifo_bp                : 5;
		uint64_t reserved_61_63              : 3;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_dbg_config_s cn85xx; */
	/* struct bdk_tns_rdma_nb_dbg_config_s cn88xx; */
} bdk_tns_rdma_nb_dbg_config_t;

#define BDK_TNS_RDMA_NB_DBG_CONFIG BDK_TNS_RDMA_NB_DBG_CONFIG_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_DBG_CONFIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_DBG_CONFIG_FUNC(void)
{
	return 0x0000842042004400ull;
}
#define typedef_BDK_TNS_RDMA_NB_DBG_CONFIG bdk_tns_rdma_nb_dbg_config_t
#define bustype_BDK_TNS_RDMA_NB_DBG_CONFIG BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_DBG_CONFIG 0
#define arguments_BDK_TNS_RDMA_NB_DBG_CONFIG -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_DBG_CONFIG "TNS_RDMA_NB_DBG_CONFIG"


/**
 * NCB - tns_rdma_nb_dbg_cx_full
 *
 * This register provides debug control of FIFO full.
 * Async FIFOs assert an early full indication when occupancies reach the values
 * below.
 */
typedef union bdk_tns_rdma_nb_dbg_cx_full {
	uint64_t u;
	struct bdk_tns_rdma_nb_dbg_cx_full_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_21_63              : 43;
		uint64_t lmac_tx_bp                  : 5;  /**< R/W - Back pressure to LMACs. */
		uint64_t reserved_13_15              : 3;
		uint64_t nic_tx_ebp                  : 5;  /**< R/W - Back pressure to NIC. */
		uint64_t reserved_5_7                : 3;
		uint64_t nic_tx_chan_bp              : 5;  /**< R/W - Channel back pressure to NIC. */
#else
		uint64_t nic_tx_chan_bp              : 5;
		uint64_t reserved_5_7                : 3;
		uint64_t nic_tx_ebp                  : 5;
		uint64_t reserved_13_15              : 3;
		uint64_t lmac_tx_bp                  : 5;
		uint64_t reserved_21_63              : 43;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_dbg_cx_full_s cn85xx; */
	/* struct bdk_tns_rdma_nb_dbg_cx_full_s cn88xx; */
} bdk_tns_rdma_nb_dbg_cx_full_t;

#define BDK_TNS_RDMA_NB_DBG_CX_FULL BDK_TNS_RDMA_NB_DBG_CX_FULL_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_DBG_CX_FULL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_DBG_CX_FULL_FUNC(void)
{
	return 0x0000842042000C40ull;
}
#define typedef_BDK_TNS_RDMA_NB_DBG_CX_FULL bdk_tns_rdma_nb_dbg_cx_full_t
#define bustype_BDK_TNS_RDMA_NB_DBG_CX_FULL BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_DBG_CX_FULL 0
#define arguments_BDK_TNS_RDMA_NB_DBG_CX_FULL -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_DBG_CX_FULL "TNS_RDMA_NB_DBG_CX_FULL"


/**
 * NCB - tns_rdma_nb_dbg_cx_occ
 *
 * Async FIFO occupancies.
 *
 */
typedef union bdk_tns_rdma_nb_dbg_cx_occ {
	uint64_t u;
	struct bdk_tns_rdma_nb_dbg_cx_occ_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_45_63              : 19;
		uint64_t lmac7_4_tx_bp               : 5;  /**< RO/H - Back pressure to LMACs 7..4. */
		uint64_t reserved_37_39              : 3;
		uint64_t lmac3_0_tx_bp               : 5;  /**< RO/H - Back pressure to LMACs 3..0. */
		uint64_t reserved_29_31              : 3;
		uint64_t nici1_tx_ebp                : 5;  /**< RO/H - Back pressure to NICI1. */
		uint64_t reserved_21_23              : 3;
		uint64_t nici0_tx_ebp                : 5;  /**< RO/H - Back pressure to NICI0. */
		uint64_t reserved_13_15              : 3;
		uint64_t nici1_tx_chan_bp            : 5;  /**< RO/H - Channel back pressure to NICI1. */
		uint64_t reserved_5_7                : 3;
		uint64_t nici0_tx_chan_bp            : 5;  /**< RO/H - Channel back pressure to NICI0. */
#else
		uint64_t nici0_tx_chan_bp            : 5;
		uint64_t reserved_5_7                : 3;
		uint64_t nici1_tx_chan_bp            : 5;
		uint64_t reserved_13_15              : 3;
		uint64_t nici0_tx_ebp                : 5;
		uint64_t reserved_21_23              : 3;
		uint64_t nici1_tx_ebp                : 5;
		uint64_t reserved_29_31              : 3;
		uint64_t lmac3_0_tx_bp               : 5;
		uint64_t reserved_37_39              : 3;
		uint64_t lmac7_4_tx_bp               : 5;
		uint64_t reserved_45_63              : 19;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_dbg_cx_occ_s cn85xx; */
	/* struct bdk_tns_rdma_nb_dbg_cx_occ_s cn88xx; */
} bdk_tns_rdma_nb_dbg_cx_occ_t;

#define BDK_TNS_RDMA_NB_DBG_CX_OCC BDK_TNS_RDMA_NB_DBG_CX_OCC_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_DBG_CX_OCC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_DBG_CX_OCC_FUNC(void)
{
	return 0x0000842042000C50ull;
}
#define typedef_BDK_TNS_RDMA_NB_DBG_CX_OCC bdk_tns_rdma_nb_dbg_cx_occ_t
#define bustype_BDK_TNS_RDMA_NB_DBG_CX_OCC BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_DBG_CX_OCC 0
#define arguments_BDK_TNS_RDMA_NB_DBG_CX_OCC -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_DBG_CX_OCC "TNS_RDMA_NB_DBG_CX_OCC"


/**
 * NCB - tns_rdma_nb_dbgb_sel
 *
 * Debug bus select register.
 *
 */
typedef union bdk_tns_rdma_nb_dbgb_sel {
	uint64_t u;
	struct bdk_tns_rdma_nb_dbgb_sel_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t sel1                        : 24; /**< R/W - Select group for upper debug bus bits */
		uint64_t sel0                        : 24; /**< R/W - Select group for lower debug bus bits */
#else
		uint64_t sel0                        : 24;
		uint64_t sel1                        : 24;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_dbgb_sel_s  cn85xx; */
	/* struct bdk_tns_rdma_nb_dbgb_sel_s  cn88xx; */
} bdk_tns_rdma_nb_dbgb_sel_t;

#define BDK_TNS_RDMA_NB_DBGB_SEL BDK_TNS_RDMA_NB_DBGB_SEL_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_DBGB_SEL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_DBGB_SEL_FUNC(void)
{
	return 0x0000842042004700ull;
}
#define typedef_BDK_TNS_RDMA_NB_DBGB_SEL bdk_tns_rdma_nb_dbgb_sel_t
#define bustype_BDK_TNS_RDMA_NB_DBGB_SEL BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_DBGB_SEL 0
#define arguments_BDK_TNS_RDMA_NB_DBGB_SEL -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_DBGB_SEL "TNS_RDMA_NB_DBGB_SEL"


/**
 * NCB - tns_rdma_nb_ecc_ctl
 *
 * This register can be used to disable ECC checks, insert ECC errors.
 * Fields *ECC_DIS disable SBE detection/correction and DBE detection. If ECC_DIS is 0x1, then no
 * errors are detected.
 * Fields *ECC_FLIP_SYND flip the syndrome<1:0> bits to generate 1-bit/2-bit error for testing.
 * * 0x0 = normal operation
 * * 0x1 = SBE on bit<0>
 * * 0x2 = SBE on bit<1>
 * * 0x3 = DBE on bits<1:0>
 */
typedef union bdk_tns_rdma_nb_ecc_ctl {
	uint64_t u;
	struct bdk_tns_rdma_nb_ecc_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t sdma_ecc_dis                : 1;  /**< R/W - Disable ECC for SDMA path. */
		uint64_t plut_sdma_ecc_dis           : 1;  /**< R/W - Disable ECC for SDMA port LUT. */
		uint64_t plut_p2x_ecc_dis            : 1;  /**< R/W - Disable ECC for P2X port LUT. */
		uint64_t pkt_lb_ecc_dis              : 1;  /**< R/W - Disable ECC for loopback packet path FIFOs. */
		uint64_t pkt_lmacts_ecc_dis          : 1;  /**< R/W - Disable ECC for LMAC packet path timestamp FIFOs. */
		uint64_t pkt_lmac_ecc_dis            : 1;  /**< R/W - Disable ECC for LMAC packet path FIFOs. */
		uint64_t pkt_nici_ecc_dis            : 2;  /**< R/W - Disable ECC for NICI[1..0] packet path FIFOs. */
		uint64_t reserved_16_31              : 16;
		uint64_t pm_ecc_flip_synd            : 2;  /**< R/W - Flip syndrome for all data written to the packet memory. */
		uint64_t sdma_ecc_flip_synd          : 2;  /**< R/W - Flip syndrome for all data written to the SDMA FIFOs. */
		uint64_t plut_sdma_ecc_flip_synd     : 2;  /**< R/W - Flip syndrome for all data written to the SDMA port LUT. */
		uint64_t plut_p2x_ecc_flip_synd      : 2;  /**< R/W - Flip syndrome for all data written to the P2X port LUT. */
		uint64_t pkt_lb_ecc_flip_synd        : 2;  /**< R/W - Flip syndrome for all data written to loopback packet path FIFOs. */
		uint64_t pkt_lmacts_ecc_flip_synd    : 2;  /**< R/W - Flip syndrome for all data written to LMAC packet path timestamp FIFOs. */
		uint64_t pkt_lmac_ecc_flip_synd      : 2;  /**< R/W - Flip syndrome for all data written to LMAC packet path FIFOs. */
		uint64_t pkt_nici_ecc_flip_synd      : 2;  /**< R/W - Flip syndrome for all data written to P2X packet path FIFOs. */
#else
		uint64_t pkt_nici_ecc_flip_synd      : 2;
		uint64_t pkt_lmac_ecc_flip_synd      : 2;
		uint64_t pkt_lmacts_ecc_flip_synd    : 2;
		uint64_t pkt_lb_ecc_flip_synd        : 2;
		uint64_t plut_p2x_ecc_flip_synd      : 2;
		uint64_t plut_sdma_ecc_flip_synd     : 2;
		uint64_t sdma_ecc_flip_synd          : 2;
		uint64_t pm_ecc_flip_synd            : 2;
		uint64_t reserved_16_31              : 16;
		uint64_t pkt_nici_ecc_dis            : 2;
		uint64_t pkt_lmac_ecc_dis            : 1;
		uint64_t pkt_lmacts_ecc_dis          : 1;
		uint64_t pkt_lb_ecc_dis              : 1;
		uint64_t plut_p2x_ecc_dis            : 1;
		uint64_t plut_sdma_ecc_dis           : 1;
		uint64_t sdma_ecc_dis                : 1;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_ecc_ctl_s   cn85xx; */
	/* struct bdk_tns_rdma_nb_ecc_ctl_s   cn88xx; */
} bdk_tns_rdma_nb_ecc_ctl_t;

#define BDK_TNS_RDMA_NB_ECC_CTL BDK_TNS_RDMA_NB_ECC_CTL_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_ECC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_ECC_CTL_FUNC(void)
{
	return 0x0000842042004000ull;
}
#define typedef_BDK_TNS_RDMA_NB_ECC_CTL bdk_tns_rdma_nb_ecc_ctl_t
#define bustype_BDK_TNS_RDMA_NB_ECC_CTL BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_ECC_CTL 0
#define arguments_BDK_TNS_RDMA_NB_ECC_CTL -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_ECC_CTL "TNS_RDMA_NB_ECC_CTL"


/**
 * NCB - tns_rdma_nb_ecc_err_stat
 *
 * This register logs information to help debug ECC errors.
 *
 */
typedef union bdk_tns_rdma_nb_ecc_err_stat {
	uint64_t u;
	struct bdk_tns_rdma_nb_ecc_err_stat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_19_63              : 45;
		uint64_t syndrome                    : 11; /**< RO/H - Error syndrome. */
		uint64_t address                     : 8;  /**< RO/H - Address of ECC error. */
#else
		uint64_t address                     : 8;
		uint64_t syndrome                    : 11;
		uint64_t reserved_19_63              : 45;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_ecc_err_stat_s cn85xx; */
	/* struct bdk_tns_rdma_nb_ecc_err_stat_s cn88xx; */
} bdk_tns_rdma_nb_ecc_err_stat_t;

#define BDK_TNS_RDMA_NB_ECC_ERR_STAT BDK_TNS_RDMA_NB_ECC_ERR_STAT_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_ECC_ERR_STAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_ECC_ERR_STAT_FUNC(void)
{
	return 0x0000842042004010ull;
}
#define typedef_BDK_TNS_RDMA_NB_ECC_ERR_STAT bdk_tns_rdma_nb_ecc_err_stat_t
#define bustype_BDK_TNS_RDMA_NB_ECC_ERR_STAT BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_ECC_ERR_STAT 0
#define arguments_BDK_TNS_RDMA_NB_ECC_ERR_STAT -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_ECC_ERR_STAT "TNS_RDMA_NB_ECC_ERR_STAT"


/**
 * NCB - tns_rdma_nb_eco
 *
 * ECO register.
 *
 */
typedef union bdk_tns_rdma_nb_eco {
	uint64_t u;
	struct bdk_tns_rdma_nb_eco_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t rst1                        : 8;  /**< R/W - Reset to 1 spare bits */
		uint64_t rst0                        : 8;  /**< R/W - Reset to 0 spare bits */
#else
		uint64_t rst0                        : 8;
		uint64_t rst1                        : 8;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_eco_s       cn85xx; */
	/* struct bdk_tns_rdma_nb_eco_s       cn88xx; */
} bdk_tns_rdma_nb_eco_t;

#define BDK_TNS_RDMA_NB_ECO BDK_TNS_RDMA_NB_ECO_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_ECO_FUNC(void)
{
	return 0x0000842042004800ull;
}
#define typedef_BDK_TNS_RDMA_NB_ECO bdk_tns_rdma_nb_eco_t
#define bustype_BDK_TNS_RDMA_NB_ECO BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_ECO 0
#define arguments_BDK_TNS_RDMA_NB_ECO -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_ECO "TNS_RDMA_NB_ECO"


/**
 * NCB - tns_rdma_nb_force_lmac#_bp
 *
 * Force XOFF back pressure for specific LMAC priorities as though the
 * LMAC was indicating back pressure.
 */
typedef union bdk_tns_rdma_nb_force_lmacx_bp {
	uint64_t u;
	struct bdk_tns_rdma_nb_force_lmacx_bp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t priorities                  : 16; /**< R/W - For each bit:
                                                                 When 0x1, forces XOFF for LMAC priorities 15..0.
                                                                 When 0x0, passes XON/XOFF information arriving from the LMAC. */
#else
		uint64_t priorities                  : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_force_lmacx_bp_s cn85xx; */
	/* struct bdk_tns_rdma_nb_force_lmacx_bp_s cn88xx; */
} bdk_tns_rdma_nb_force_lmacx_bp_t;

static inline uint64_t BDK_TNS_RDMA_NB_FORCE_LMACX_BP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_FORCE_LMACX_BP(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000842042000900ull + (param1 & 7) * 0x10ull;
	csr_fatal("BDK_TNS_RDMA_NB_FORCE_LMACX_BP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_RDMA_NB_FORCE_LMACX_BP(...) bdk_tns_rdma_nb_force_lmacx_bp_t
#define bustype_BDK_TNS_RDMA_NB_FORCE_LMACX_BP(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_FORCE_LMACX_BP(p1) (p1)
#define arguments_BDK_TNS_RDMA_NB_FORCE_LMACX_BP(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_FORCE_LMACX_BP(...) "TNS_RDMA_NB_FORCE_LMACX_BP"


/**
 * NCB - tns_rdma_nb_force_nic#_bp
 *
 * Force XOFF back pressure for specific NIC channels as though the
 * NIC was indicating back pressure.
 */
typedef union bdk_tns_rdma_nb_force_nicx_bp {
	uint64_t u;
	struct bdk_tns_rdma_nb_force_nicx_bp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t chan                        : 64; /**< R/W - When 0x1, forces XOFF for channels.
                                                                 When 0x0, passes XON/XOFF information arriving from the NIC. */
#else
		uint64_t chan                        : 64;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_force_nicx_bp_s cn85xx; */
	/* struct bdk_tns_rdma_nb_force_nicx_bp_s cn88xx; */
} bdk_tns_rdma_nb_force_nicx_bp_t;

static inline uint64_t BDK_TNS_RDMA_NB_FORCE_NICX_BP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_FORCE_NICX_BP(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000842042000980ull + (param1 & 3) * 0x10ull;
	csr_fatal("BDK_TNS_RDMA_NB_FORCE_NICX_BP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_RDMA_NB_FORCE_NICX_BP(...) bdk_tns_rdma_nb_force_nicx_bp_t
#define bustype_BDK_TNS_RDMA_NB_FORCE_NICX_BP(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_FORCE_NICX_BP(p1) (p1)
#define arguments_BDK_TNS_RDMA_NB_FORCE_NICX_BP(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_FORCE_NICX_BP(...) "TNS_RDMA_NB_FORCE_NICX_BP"


/**
 * NCB - tns_rdma_nb_hdr_sz_cfg
 *
 * This register is used to designate the number of bytes which are considered part
 * of the packet header and will be extracted for processing.
 * Bytes received after the header are considered part of the body.
 * Timestamp bytes received from the BGX (if enabled) are not counted against the
 * header size.
 * Unpredictable behavior will occur if software changes the header size configuration
 * for a port while packets are being received.
 * All fields are enumerated with TNS_RDMA_HDR_SZ_E.
 */
typedef union bdk_tns_rdma_nb_hdr_sz_cfg {
	uint64_t u;
	struct bdk_tns_rdma_nb_hdr_sz_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t lb                          : 2;  /**< R/W - Packet header size for the loopback packet path. */
		uint64_t nici1                       : 2;  /**< R/W - Packet header size for the NICI1 packet path. */
		uint64_t nici0                       : 2;  /**< R/W - Packet header size for the NICI0 packet path. */
		uint64_t lmac7                       : 2;  /**< R/W - Packet header size for the LMAC7 packet path. */
		uint64_t lmac6                       : 2;  /**< R/W - Packet header size for the LMAC6 packet path. */
		uint64_t lmac5                       : 2;  /**< R/W - Packet header size for the LMAC5 packet path. */
		uint64_t lmac4                       : 2;  /**< R/W - Packet header size for the LMAC4 packet path. */
		uint64_t lmac3                       : 2;  /**< R/W - Packet header size for the LMAC3 packet path. */
		uint64_t lmac2                       : 2;  /**< R/W - Packet header size for the LMAC2 packet path. */
		uint64_t lmac1                       : 2;  /**< R/W - Packet header size for the LMAC1 packet path. */
		uint64_t lmac0                       : 2;  /**< R/W - Packet header size for the LMAC0 packet path. */
#else
		uint64_t lmac0                       : 2;
		uint64_t lmac1                       : 2;
		uint64_t lmac2                       : 2;
		uint64_t lmac3                       : 2;
		uint64_t lmac4                       : 2;
		uint64_t lmac5                       : 2;
		uint64_t lmac6                       : 2;
		uint64_t lmac7                       : 2;
		uint64_t nici0                       : 2;
		uint64_t nici1                       : 2;
		uint64_t lb                          : 2;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_hdr_sz_cfg_s cn85xx; */
	/* struct bdk_tns_rdma_nb_hdr_sz_cfg_s cn88xx; */
} bdk_tns_rdma_nb_hdr_sz_cfg_t;

#define BDK_TNS_RDMA_NB_HDR_SZ_CFG BDK_TNS_RDMA_NB_HDR_SZ_CFG_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_HDR_SZ_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_HDR_SZ_CFG_FUNC(void)
{
	return 0x0000842042004030ull;
}
#define typedef_BDK_TNS_RDMA_NB_HDR_SZ_CFG bdk_tns_rdma_nb_hdr_sz_cfg_t
#define bustype_BDK_TNS_RDMA_NB_HDR_SZ_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_HDR_SZ_CFG 0
#define arguments_BDK_TNS_RDMA_NB_HDR_SZ_CFG -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_HDR_SZ_CFG "TNS_RDMA_NB_HDR_SZ_CFG"


/**
 * NCB - tns_rdma_nb_int_en_w1c
 *
 * RDMA Interrupt Enable Register.
 *
 */
typedef union bdk_tns_rdma_nb_int_en_w1c {
	uint64_t u;
	struct bdk_tns_rdma_nb_int_en_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t hts_exists                  : 1;  /**< R/W1C/H - A token received from the SDE had the HTS flag set. */
		uint64_t runt_pkt                    : 1;  /**< R/W1C/H - Runt packet received and captured. */
		uint64_t reserved_46_47              : 2;
		uint64_t sdma_dbe                    : 1;  /**< R/W1C/H - Double-bit ECC error detected on SDMA RAM. */
		uint64_t plut_sdma_dbe               : 1;  /**< R/W1C/H - Double-bit ECC error detected on PLUT_SDMA RAM. */
		uint64_t plut_p2x_dbe                : 1;  /**< R/W1C/H - Double-bit ECC error detected on PLUT_P2X RAM. */
		uint64_t pkt_lb_dbe                  : 1;  /**< R/W1C/H - Double-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_nici_dbe                : 2;  /**< R/W1C/H - Double-bit ECC error detected on PKT_NICI[1..0] RAM. */
		uint64_t pkt_lmacts_dbe              : 8;  /**< R/W1C/H - Double-bit ECC error detected on PKT_LMACTS[7..0] RAM. */
		uint64_t pkt_lmac_dbe                : 8;  /**< R/W1C/H - Double-bit ECC error detected on PKT_LMAC[7..0] RAM. */
		uint64_t reserved_22_23              : 2;
		uint64_t sdma_sbe                    : 1;  /**< R/W1C/H - Single-bit ECC error detected on SDMA RAM. */
		uint64_t plut_sdma_sbe               : 1;  /**< R/W1C/H - Single-bit ECC error detected on PLUT_SDMA RAM. */
		uint64_t plut_p2x_sbe                : 1;  /**< R/W1C/H - Single-bit ECC error detected on PLUT_P2X RAM. */
		uint64_t pkt_lb_sbe                  : 1;  /**< R/W1C/H - Single-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_nici_sbe                : 2;  /**< R/W1C/H - Single-bit ECC error detected on PKT_NICI[1..0] RAM. */
		uint64_t pkt_lmacts_sbe              : 8;  /**< R/W1C/H - Single-bit ECC error detected on PKT_LMACTS[7..0] RAM. */
		uint64_t pkt_lmac_sbe                : 8;  /**< R/W1C/H - Single-bit ECC error detected on PKT_LMAC[7..0] RAM. */
#else
		uint64_t pkt_lmac_sbe                : 8;
		uint64_t pkt_lmacts_sbe              : 8;
		uint64_t pkt_nici_sbe                : 2;
		uint64_t pkt_lb_sbe                  : 1;
		uint64_t plut_p2x_sbe                : 1;
		uint64_t plut_sdma_sbe               : 1;
		uint64_t sdma_sbe                    : 1;
		uint64_t reserved_22_23              : 2;
		uint64_t pkt_lmac_dbe                : 8;
		uint64_t pkt_lmacts_dbe              : 8;
		uint64_t pkt_nici_dbe                : 2;
		uint64_t pkt_lb_dbe                  : 1;
		uint64_t plut_p2x_dbe                : 1;
		uint64_t plut_sdma_dbe               : 1;
		uint64_t sdma_dbe                    : 1;
		uint64_t reserved_46_47              : 2;
		uint64_t runt_pkt                    : 1;
		uint64_t hts_exists                  : 1;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_int_en_w1c_s cn85xx; */
	/* struct bdk_tns_rdma_nb_int_en_w1c_s cn88xx; */
} bdk_tns_rdma_nb_int_en_w1c_t;

#define BDK_TNS_RDMA_NB_INT_EN_W1C BDK_TNS_RDMA_NB_INT_EN_W1C_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_INT_EN_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_INT_EN_W1C_FUNC(void)
{
	return 0x0000842042000130ull;
}
#define typedef_BDK_TNS_RDMA_NB_INT_EN_W1C bdk_tns_rdma_nb_int_en_w1c_t
#define bustype_BDK_TNS_RDMA_NB_INT_EN_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_INT_EN_W1C 0
#define arguments_BDK_TNS_RDMA_NB_INT_EN_W1C -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_INT_EN_W1C "TNS_RDMA_NB_INT_EN_W1C"


/**
 * NCB - tns_rdma_nb_int_en_w1s
 *
 * RDMA Interrupt Enable Register.
 *
 */
typedef union bdk_tns_rdma_nb_int_en_w1s {
	uint64_t u;
	struct bdk_tns_rdma_nb_int_en_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t hts_exists                  : 1;  /**< R/W1S/H - A token received from the SDE had the HTS flag set. */
		uint64_t runt_pkt                    : 1;  /**< R/W1S/H - Runt packet received and captured. */
		uint64_t reserved_46_47              : 2;
		uint64_t sdma_dbe                    : 1;  /**< R/W1S/H - Double-bit ECC error detected on SDMA RAM. */
		uint64_t plut_sdma_dbe               : 1;  /**< R/W1S/H - Double-bit ECC error detected on PLUT_SDMA RAM. */
		uint64_t plut_p2x_dbe                : 1;  /**< R/W1S/H - Double-bit ECC error detected on PLUT_P2X RAM. */
		uint64_t pkt_lb_dbe                  : 1;  /**< R/W1S/H - Double-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_nici_dbe                : 2;  /**< R/W1S/H - Double-bit ECC error detected on PKT_NICI[1..0] RAM. */
		uint64_t pkt_lmacts_dbe              : 8;  /**< R/W1S/H - Double-bit ECC error detected on PKT_LMACTS[7..0] RAM. */
		uint64_t pkt_lmac_dbe                : 8;  /**< R/W1S/H - Double-bit ECC error detected on PKT_LMAC[7..0] RAM */
		uint64_t reserved_22_23              : 2;
		uint64_t sdma_sbe                    : 1;  /**< R/W1S/H - Single-bit ECC error detected on SDMA RAM. */
		uint64_t plut_sdma_sbe               : 1;  /**< R/W1S/H - Single-bit ECC error detected on PLUT_SDMA RAM. */
		uint64_t plut_p2x_sbe                : 1;  /**< R/W1S/H - Single-bit ECC error detected on PLUT_P2X RAM. */
		uint64_t pkt_lb_sbe                  : 1;  /**< R/W1S/H - Single-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_nici_sbe                : 2;  /**< R/W1S/H - Single-bit ECC error detected on PKT_NICI[1..0] RAM. */
		uint64_t pkt_lmacts_sbe              : 8;  /**< R/W1S/H - Single-bit ECC error detected on PKT_LMACTS[7..0] RAM. */
		uint64_t pkt_lmac_sbe                : 8;  /**< R/W1S/H - Single-bit ECC error detected on PKT_LMAC[7..0] RAM. */
#else
		uint64_t pkt_lmac_sbe                : 8;
		uint64_t pkt_lmacts_sbe              : 8;
		uint64_t pkt_nici_sbe                : 2;
		uint64_t pkt_lb_sbe                  : 1;
		uint64_t plut_p2x_sbe                : 1;
		uint64_t plut_sdma_sbe               : 1;
		uint64_t sdma_sbe                    : 1;
		uint64_t reserved_22_23              : 2;
		uint64_t pkt_lmac_dbe                : 8;
		uint64_t pkt_lmacts_dbe              : 8;
		uint64_t pkt_nici_dbe                : 2;
		uint64_t pkt_lb_dbe                  : 1;
		uint64_t plut_p2x_dbe                : 1;
		uint64_t plut_sdma_dbe               : 1;
		uint64_t sdma_dbe                    : 1;
		uint64_t reserved_46_47              : 2;
		uint64_t runt_pkt                    : 1;
		uint64_t hts_exists                  : 1;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_int_en_w1s_s cn85xx; */
	/* struct bdk_tns_rdma_nb_int_en_w1s_s cn88xx; */
} bdk_tns_rdma_nb_int_en_w1s_t;

#define BDK_TNS_RDMA_NB_INT_EN_W1S BDK_TNS_RDMA_NB_INT_EN_W1S_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_INT_EN_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_INT_EN_W1S_FUNC(void)
{
	return 0x0000842042000120ull;
}
#define typedef_BDK_TNS_RDMA_NB_INT_EN_W1S bdk_tns_rdma_nb_int_en_w1s_t
#define bustype_BDK_TNS_RDMA_NB_INT_EN_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_INT_EN_W1S 0
#define arguments_BDK_TNS_RDMA_NB_INT_EN_W1S -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_INT_EN_W1S "TNS_RDMA_NB_INT_EN_W1S"


/**
 * NCB - tns_rdma_nb_int_fen_w1c
 *
 * RDMA Interrupt First Enable Register.
 *
 */
typedef union bdk_tns_rdma_nb_int_fen_w1c {
	uint64_t u;
	struct bdk_tns_rdma_nb_int_fen_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t hts_exists                  : 1;  /**< R/W1C - A token received from the SDE had the HTS flag set. */
		uint64_t runt_pkt                    : 1;  /**< R/W1C - Runt packet received and captured. */
		uint64_t reserved_46_47              : 2;
		uint64_t sdma_dbe                    : 1;  /**< R/W1C - Double-bit ECC error detected on SDMA RAM. */
		uint64_t plut_sdma_dbe               : 1;  /**< R/W1C - Double-bit ECC error detected on PLUT_SDMA RAM. */
		uint64_t plut_p2x_dbe                : 1;  /**< R/W1C - Double-bit ECC error detected on PLUT_P2X RAM. */
		uint64_t pkt_lb_dbe                  : 1;  /**< R/W1C - Double-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_nici_dbe                : 2;  /**< R/W1C - Double-bit ECC error detected on PKT_NICI[1..0] RAM. */
		uint64_t pkt_lmacts_dbe              : 8;  /**< R/W1C - Double-bit ECC error detected on PKT_LMACTS[1..0] RAM. */
		uint64_t pkt_lmac_dbe                : 8;  /**< R/W1C - Double-bit ECC error detected on PKT_LMAC[7..0] RAM. */
		uint64_t reserved_22_23              : 2;
		uint64_t sdma_sbe                    : 1;  /**< R/W1C - Single-bit ECC error detected on SDMA RAM. */
		uint64_t plut_sdma_sbe               : 1;  /**< R/W1C - Single-bit ECC error detected on PLUT_SDMA RAM. */
		uint64_t plut_p2x_sbe                : 1;  /**< R/W1C - Single-bit ECC error detected on PLUT_P2X RAM. */
		uint64_t pkt_lb_sbe                  : 1;  /**< R/W1C - Single-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_nici_sbe                : 2;  /**< R/W1C - Single-bit ECC error detected on PKT_NICI[1..0] RAM. */
		uint64_t pkt_lmacts_sbe              : 8;  /**< R/W1C - Single-bit ECC error detected on PKT_LMACTS[7..0] RAM. */
		uint64_t pkt_lmac_sbe                : 8;  /**< R/W1C - Single-bit ECC error detected on PKT_LMAC[7..0] RAM. */
#else
		uint64_t pkt_lmac_sbe                : 8;
		uint64_t pkt_lmacts_sbe              : 8;
		uint64_t pkt_nici_sbe                : 2;
		uint64_t pkt_lb_sbe                  : 1;
		uint64_t plut_p2x_sbe                : 1;
		uint64_t plut_sdma_sbe               : 1;
		uint64_t sdma_sbe                    : 1;
		uint64_t reserved_22_23              : 2;
		uint64_t pkt_lmac_dbe                : 8;
		uint64_t pkt_lmacts_dbe              : 8;
		uint64_t pkt_nici_dbe                : 2;
		uint64_t pkt_lb_dbe                  : 1;
		uint64_t plut_p2x_dbe                : 1;
		uint64_t plut_sdma_dbe               : 1;
		uint64_t sdma_dbe                    : 1;
		uint64_t reserved_46_47              : 2;
		uint64_t runt_pkt                    : 1;
		uint64_t hts_exists                  : 1;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_int_fen_w1c_s cn85xx; */
	/* struct bdk_tns_rdma_nb_int_fen_w1c_s cn88xx; */
} bdk_tns_rdma_nb_int_fen_w1c_t;

#define BDK_TNS_RDMA_NB_INT_FEN_W1C BDK_TNS_RDMA_NB_INT_FEN_W1C_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_INT_FEN_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_INT_FEN_W1C_FUNC(void)
{
	return 0x0000842042000160ull;
}
#define typedef_BDK_TNS_RDMA_NB_INT_FEN_W1C bdk_tns_rdma_nb_int_fen_w1c_t
#define bustype_BDK_TNS_RDMA_NB_INT_FEN_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_INT_FEN_W1C 0
#define arguments_BDK_TNS_RDMA_NB_INT_FEN_W1C -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_INT_FEN_W1C "TNS_RDMA_NB_INT_FEN_W1C"


/**
 * NCB - tns_rdma_nb_int_fen_w1s
 *
 * RDMA Interrupt First Enable Register.
 *
 */
typedef union bdk_tns_rdma_nb_int_fen_w1s {
	uint64_t u;
	struct bdk_tns_rdma_nb_int_fen_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t hts_exists                  : 1;  /**< R/W1S - A token received from the SDE had the HTS flag set. */
		uint64_t runt_pkt                    : 1;  /**< R/W1S - Runt packet received and captured. */
		uint64_t reserved_46_47              : 2;
		uint64_t sdma_dbe                    : 1;  /**< R/W1S - Double-bit ECC error detected on SDMA RAM. */
		uint64_t plut_sdma_dbe               : 1;  /**< R/W1S - Double-bit ECC error detected on PLUT_SDMA RAM. */
		uint64_t plut_p2x_dbe                : 1;  /**< R/W1S - Double-bit ECC error detected on PLUT_P2X RAM. */
		uint64_t pkt_lb_dbe                  : 1;  /**< R/W1S - Double-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_nici_dbe                : 2;  /**< R/W1S - Double-bit ECC error detected on PKT_NICI[1..0] RAM. */
		uint64_t pkt_lmacts_dbe              : 8;  /**< R/W1S - Double-bit ECC error detected on PKT_LMACTS[7..0] RAM. */
		uint64_t pkt_lmac_dbe                : 8;  /**< R/W1S - Double-bit ECC error detected on PKT_LMAC[7..0] RAM. */
		uint64_t reserved_22_23              : 2;
		uint64_t sdma_sbe                    : 1;  /**< R/W1S - Single-bit ECC error detected on SDMA RAM. */
		uint64_t plut_sdma_sbe               : 1;  /**< R/W1S - Single-bit ECC error detected on PLUT_SDMA RAM. */
		uint64_t plut_p2x_sbe                : 1;  /**< R/W1S - Single-bit ECC error detected on PLUT_P2X RAM. */
		uint64_t pkt_lb_sbe                  : 1;  /**< R/W1S - Single-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_nici_sbe                : 2;  /**< R/W1S - Single-bit ECC error detected on PKT_NICI[1..0] RAM. */
		uint64_t pkt_lmacts_sbe              : 8;  /**< R/W1S - Single-bit ECC error detected on PKT_LMACTS[7..0] RAM. */
		uint64_t pkt_lmac_sbe                : 8;  /**< R/W1S - Single-bit ECC error detected on PKT_LMAC[7..0] RAM. */
#else
		uint64_t pkt_lmac_sbe                : 8;
		uint64_t pkt_lmacts_sbe              : 8;
		uint64_t pkt_nici_sbe                : 2;
		uint64_t pkt_lb_sbe                  : 1;
		uint64_t plut_p2x_sbe                : 1;
		uint64_t plut_sdma_sbe               : 1;
		uint64_t sdma_sbe                    : 1;
		uint64_t reserved_22_23              : 2;
		uint64_t pkt_lmac_dbe                : 8;
		uint64_t pkt_lmacts_dbe              : 8;
		uint64_t pkt_nici_dbe                : 2;
		uint64_t pkt_lb_dbe                  : 1;
		uint64_t plut_p2x_dbe                : 1;
		uint64_t plut_sdma_dbe               : 1;
		uint64_t sdma_dbe                    : 1;
		uint64_t reserved_46_47              : 2;
		uint64_t runt_pkt                    : 1;
		uint64_t hts_exists                  : 1;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_int_fen_w1s_s cn85xx; */
	/* struct bdk_tns_rdma_nb_int_fen_w1s_s cn88xx; */
} bdk_tns_rdma_nb_int_fen_w1s_t;

#define BDK_TNS_RDMA_NB_INT_FEN_W1S BDK_TNS_RDMA_NB_INT_FEN_W1S_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_INT_FEN_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_INT_FEN_W1S_FUNC(void)
{
	return 0x0000842042000150ull;
}
#define typedef_BDK_TNS_RDMA_NB_INT_FEN_W1S bdk_tns_rdma_nb_int_fen_w1s_t
#define bustype_BDK_TNS_RDMA_NB_INT_FEN_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_INT_FEN_W1S 0
#define arguments_BDK_TNS_RDMA_NB_INT_FEN_W1S -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_INT_FEN_W1S "TNS_RDMA_NB_INT_FEN_W1S"


/**
 * NCB - tns_rdma_nb_int_fstat
 *
 * RDMA Interrupt First Status Register.
 *
 */
typedef union bdk_tns_rdma_nb_int_fstat {
	uint64_t u;
	struct bdk_tns_rdma_nb_int_fstat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t hts_exists                  : 1;  /**< RO/H - A token received from the SDE had the HTS flag set. */
		uint64_t runt_pkt                    : 1;  /**< RO/H - Runt packet received and captured. */
		uint64_t reserved_46_47              : 2;
		uint64_t sdma_dbe                    : 1;  /**< RO/H - Double-bit ECC error detected on SDMA RAM. */
		uint64_t plut_sdma_dbe               : 1;  /**< RO/H - Double-bit ECC error detected on PLUT_SDMA RAM. */
		uint64_t plut_p2x_dbe                : 1;  /**< RO/H - Double-bit ECC error detected on PLUT_P2X RAM. */
		uint64_t pkt_lb_dbe                  : 1;  /**< RO/H - Double-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_nici_dbe                : 2;  /**< RO/H - Double-bit ECC error detected on PKT_NICI[1..0] RAM. */
		uint64_t pkt_lmacts_dbe              : 8;  /**< RO/H - Double-bit ECC error detected on PKT_LMACTS[7..0] RAM. */
		uint64_t pkt_lmac_dbe                : 8;  /**< RO/H - Double-bit ECC error detected on PKT_LMAC[7..0] RAM. */
		uint64_t reserved_22_23              : 2;
		uint64_t sdma_sbe                    : 1;  /**< RO/H - Single-bit ECC error detected on SDMA RAM. */
		uint64_t plut_sdma_sbe               : 1;  /**< RO/H - Single-bit ECC error detected on PLUT_SDMA RAM. */
		uint64_t plut_p2x_sbe                : 1;  /**< RO/H - Single-bit ECC error detected on PLUT_P2X RAM. */
		uint64_t pkt_lb_sbe                  : 1;  /**< RO/H - Single-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_nici_sbe                : 2;  /**< RO/H - Single-bit ECC error detected on PKT_NICI[1..0] RAM. */
		uint64_t pkt_lmacts_sbe              : 8;  /**< RO/H - Single-bit ECC error detected on PKT_LMACTS[7..0] RAM. */
		uint64_t pkt_lmac_sbe                : 8;  /**< RO/H - Single-bit ECC error detected on PKT_LMAC[7..0] RAM. */
#else
		uint64_t pkt_lmac_sbe                : 8;
		uint64_t pkt_lmacts_sbe              : 8;
		uint64_t pkt_nici_sbe                : 2;
		uint64_t pkt_lb_sbe                  : 1;
		uint64_t plut_p2x_sbe                : 1;
		uint64_t plut_sdma_sbe               : 1;
		uint64_t sdma_sbe                    : 1;
		uint64_t reserved_22_23              : 2;
		uint64_t pkt_lmac_dbe                : 8;
		uint64_t pkt_lmacts_dbe              : 8;
		uint64_t pkt_nici_dbe                : 2;
		uint64_t pkt_lb_dbe                  : 1;
		uint64_t plut_p2x_dbe                : 1;
		uint64_t plut_sdma_dbe               : 1;
		uint64_t sdma_dbe                    : 1;
		uint64_t reserved_46_47              : 2;
		uint64_t runt_pkt                    : 1;
		uint64_t hts_exists                  : 1;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_int_fstat_s cn85xx; */
	/* struct bdk_tns_rdma_nb_int_fstat_s cn88xx; */
} bdk_tns_rdma_nb_int_fstat_t;

#define BDK_TNS_RDMA_NB_INT_FSTAT BDK_TNS_RDMA_NB_INT_FSTAT_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_INT_FSTAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_INT_FSTAT_FUNC(void)
{
	return 0x0000842042000140ull;
}
#define typedef_BDK_TNS_RDMA_NB_INT_FSTAT bdk_tns_rdma_nb_int_fstat_t
#define bustype_BDK_TNS_RDMA_NB_INT_FSTAT BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_INT_FSTAT 0
#define arguments_BDK_TNS_RDMA_NB_INT_FSTAT -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_INT_FSTAT "TNS_RDMA_NB_INT_FSTAT"


/**
 * NCB - tns_rdma_nb_int_stat_w1c
 *
 * RDMA Interrupt Status Register.
 *
 */
typedef union bdk_tns_rdma_nb_int_stat_w1c {
	uint64_t u;
	struct bdk_tns_rdma_nb_int_stat_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t hts_exists                  : 1;  /**< R/W1C/H - A token received from the SDE had the HTS flag set. */
		uint64_t runt_pkt                    : 1;  /**< R/W1C/H - Runt packet received and captured. */
		uint64_t reserved_46_47              : 2;
		uint64_t sdma_dbe                    : 1;  /**< R/W1C/H - Double-bit ECC error detected on SDMA RAM. */
		uint64_t plut_sdma_dbe               : 1;  /**< R/W1C/H - Double-bit ECC error detected on PLUT_SDMA RAM. */
		uint64_t plut_p2x_dbe                : 1;  /**< R/W1C/H - Double-bit ECC error detected on PLUT_P2X RAM. */
		uint64_t pkt_lb_dbe                  : 1;  /**< R/W1C/H - Double-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_nici_dbe                : 2;  /**< R/W1C/H - Double-bit ECC error detected on PKT_NICI[1..0] RAM. */
		uint64_t pkt_lmacts_dbe              : 8;  /**< R/W1C/H - Double-bit ECC error detected on PKT_LMACTS[7..0] RAM. */
		uint64_t pkt_lmac_dbe                : 8;  /**< R/W1C/H - Double-bit ECC error detected on PKT_LMAC[7..0] RAM */
		uint64_t reserved_22_23              : 2;
		uint64_t sdma_sbe                    : 1;  /**< R/W1C/H - Single-bit ECC error detected on SDMA RAM. */
		uint64_t plut_sdma_sbe               : 1;  /**< R/W1C/H - Single-bit ECC error detected on PLUT_SDMA RAM. */
		uint64_t plut_p2x_sbe                : 1;  /**< R/W1C/H - Single-bit ECC error detected on PLUT_P2X RAM. */
		uint64_t pkt_lb_sbe                  : 1;  /**< R/W1C/H - Single-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_nici_sbe                : 2;  /**< R/W1C/H - Single-bit ECC error detected on PKT_NICI[1..0] RAM. */
		uint64_t pkt_lmacts_sbe              : 8;  /**< R/W1C/H - Single-bit ECC error detected on PKT_LMACTS[7..0] RAM. */
		uint64_t pkt_lmac_sbe                : 8;  /**< R/W1C/H - Single-bit ECC error detected on PKT_LMAC[7..0] RAM. */
#else
		uint64_t pkt_lmac_sbe                : 8;
		uint64_t pkt_lmacts_sbe              : 8;
		uint64_t pkt_nici_sbe                : 2;
		uint64_t pkt_lb_sbe                  : 1;
		uint64_t plut_p2x_sbe                : 1;
		uint64_t plut_sdma_sbe               : 1;
		uint64_t sdma_sbe                    : 1;
		uint64_t reserved_22_23              : 2;
		uint64_t pkt_lmac_dbe                : 8;
		uint64_t pkt_lmacts_dbe              : 8;
		uint64_t pkt_nici_dbe                : 2;
		uint64_t pkt_lb_dbe                  : 1;
		uint64_t plut_p2x_dbe                : 1;
		uint64_t plut_sdma_dbe               : 1;
		uint64_t sdma_dbe                    : 1;
		uint64_t reserved_46_47              : 2;
		uint64_t runt_pkt                    : 1;
		uint64_t hts_exists                  : 1;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_int_stat_w1c_s cn85xx; */
	/* struct bdk_tns_rdma_nb_int_stat_w1c_s cn88xx; */
} bdk_tns_rdma_nb_int_stat_w1c_t;

#define BDK_TNS_RDMA_NB_INT_STAT_W1C BDK_TNS_RDMA_NB_INT_STAT_W1C_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_INT_STAT_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_INT_STAT_W1C_FUNC(void)
{
	return 0x0000842042000110ull;
}
#define typedef_BDK_TNS_RDMA_NB_INT_STAT_W1C bdk_tns_rdma_nb_int_stat_w1c_t
#define bustype_BDK_TNS_RDMA_NB_INT_STAT_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_INT_STAT_W1C 0
#define arguments_BDK_TNS_RDMA_NB_INT_STAT_W1C -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_INT_STAT_W1C "TNS_RDMA_NB_INT_STAT_W1C"


/**
 * NCB - tns_rdma_nb_int_stat_w1s
 *
 * RDMA Interrupt Status Register.
 *
 */
typedef union bdk_tns_rdma_nb_int_stat_w1s {
	uint64_t u;
	struct bdk_tns_rdma_nb_int_stat_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t hts_exists                  : 1;  /**< R/W1S/H - A token received from the SDE had the HTS flag set. */
		uint64_t runt_pkt                    : 1;  /**< R/W1S/H - Runt packet received and captured. */
		uint64_t reserved_46_47              : 2;
		uint64_t sdma_dbe                    : 1;  /**< R/W1S/H - Double-bit ECC error detected on SDMA RAM. */
		uint64_t plut_sdma_dbe               : 1;  /**< R/W1S/H - Double-bit ECC error detected on PLUT_SDMA RAM. */
		uint64_t plut_p2x_dbe                : 1;  /**< R/W1S/H - Double-bit ECC error detected on PLUT_P2X RAM. */
		uint64_t pkt_lb_dbe                  : 1;  /**< R/W1S/H - Double-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_nici_dbe                : 2;  /**< R/W1S/H - Double-bit ECC error detected on PKT_NICI[1..0] RAM. */
		uint64_t pkt_lmacts_dbe              : 8;  /**< R/W1S/H - Double-bit ECC error detected on PKT_LMACTS[7..0] RAM. */
		uint64_t pkt_lmac_dbe                : 8;  /**< R/W1S/H - Double-bit ECC error detected on PKT_LMAC[7..0] RAM. */
		uint64_t reserved_22_23              : 2;
		uint64_t sdma_sbe                    : 1;  /**< R/W1S/H - Single-bit ECC error detected on SDMA RAM. */
		uint64_t plut_sdma_sbe               : 1;  /**< R/W1S/H - Single-bit ECC error detected on PLUT_SDMA RAM. */
		uint64_t plut_p2x_sbe                : 1;  /**< R/W1S/H - Single-bit ECC error detected on PLUT_P2X RAM. */
		uint64_t pkt_lb_sbe                  : 1;  /**< R/W1S/H - Single-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_nici_sbe                : 2;  /**< R/W1S/H - Single-bit ECC error detected on PKT_NICI[1..0] RAM. */
		uint64_t pkt_lmacts_sbe              : 8;  /**< R/W1S/H - Single-bit ECC error detected on PKT_LMACTS[7..0] RAM. */
		uint64_t pkt_lmac_sbe                : 8;  /**< R/W1S/H - Single-bit ECC error detected on PKT_LMAC[7..0] RAM. */
#else
		uint64_t pkt_lmac_sbe                : 8;
		uint64_t pkt_lmacts_sbe              : 8;
		uint64_t pkt_nici_sbe                : 2;
		uint64_t pkt_lb_sbe                  : 1;
		uint64_t plut_p2x_sbe                : 1;
		uint64_t plut_sdma_sbe               : 1;
		uint64_t sdma_sbe                    : 1;
		uint64_t reserved_22_23              : 2;
		uint64_t pkt_lmac_dbe                : 8;
		uint64_t pkt_lmacts_dbe              : 8;
		uint64_t pkt_nici_dbe                : 2;
		uint64_t pkt_lb_dbe                  : 1;
		uint64_t plut_p2x_dbe                : 1;
		uint64_t plut_sdma_dbe               : 1;
		uint64_t sdma_dbe                    : 1;
		uint64_t reserved_46_47              : 2;
		uint64_t runt_pkt                    : 1;
		uint64_t hts_exists                  : 1;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_int_stat_w1s_s cn85xx; */
	/* struct bdk_tns_rdma_nb_int_stat_w1s_s cn88xx; */
} bdk_tns_rdma_nb_int_stat_w1s_t;

#define BDK_TNS_RDMA_NB_INT_STAT_W1S BDK_TNS_RDMA_NB_INT_STAT_W1S_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_INT_STAT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_INT_STAT_W1S_FUNC(void)
{
	return 0x0000842042000100ull;
}
#define typedef_BDK_TNS_RDMA_NB_INT_STAT_W1S bdk_tns_rdma_nb_int_stat_w1s_t
#define bustype_BDK_TNS_RDMA_NB_INT_STAT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_INT_STAT_W1S 0
#define arguments_BDK_TNS_RDMA_NB_INT_STAT_W1S -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_INT_STAT_W1S "TNS_RDMA_NB_INT_STAT_W1S"


/**
 * NCB - tns_rdma_nb_lmac#_rpkt_sz
 *
 * Hardware will drop packets arriving from the LMAC if the size is
 * less than or equal to the programmed value.
 * The prepended timestamp (if present) is not counted when determining the
 * size of an arriving packet.
 * Dropped runt packets are counted.
 */
typedef union bdk_tns_rdma_nb_lmacx_rpkt_sz {
	uint64_t u;
	struct bdk_tns_rdma_nb_lmacx_rpkt_sz_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t bytes                       : 8;  /**< R/W - Packets received from the LMAC with size greater than this will be passed to the
                                                                 network switch for processing.
                                                                 Packets with a size that is equal or less will be marked as runt, dropped, and counted. */
#else
		uint64_t bytes                       : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_lmacx_rpkt_sz_s cn85xx; */
	/* struct bdk_tns_rdma_nb_lmacx_rpkt_sz_s cn88xx; */
} bdk_tns_rdma_nb_lmacx_rpkt_sz_t;

static inline uint64_t BDK_TNS_RDMA_NB_LMACX_RPKT_SZ(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_LMACX_RPKT_SZ(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000842042000A00ull + (param1 & 7) * 0x10ull;
	csr_fatal("BDK_TNS_RDMA_NB_LMACX_RPKT_SZ", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_RDMA_NB_LMACX_RPKT_SZ(...) bdk_tns_rdma_nb_lmacx_rpkt_sz_t
#define bustype_BDK_TNS_RDMA_NB_LMACX_RPKT_SZ(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_LMACX_RPKT_SZ(p1) (p1)
#define arguments_BDK_TNS_RDMA_NB_LMACX_RPKT_SZ(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_LMACX_RPKT_SZ(...) "TNS_RDMA_NB_LMACX_RPKT_SZ"


/**
 * NCB - tns_rdma_nb_lmac_plut#
 *
 * Translates the arriving LMAC physical port number to an 8-bit logical port number.
 * Hardware will initialize this table upon direction by software to perform
 * auto-initialization.
 * Some physical to logical aliasing will occur as there are more physical
 * ports than the 8-bit logical port width allows:
 *   * 256 NIC channels
 *   * 8 LMAC ports
 *   * 1 Loopback port
 */
typedef union bdk_tns_rdma_nb_lmac_plutx {
	uint64_t u;
	struct bdk_tns_rdma_nb_lmac_plutx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t logical_port                : 8;  /**< R/W/H - Logical port number for the specified LMAC physical port number. */
#else
		uint64_t logical_port                : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_lmac_plutx_s cn85xx; */
	/* struct bdk_tns_rdma_nb_lmac_plutx_s cn88xx; */
} bdk_tns_rdma_nb_lmac_plutx_t;

static inline uint64_t BDK_TNS_RDMA_NB_LMAC_PLUTX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_LMAC_PLUTX(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000842042002000ull + (param1 & 7) * 0x10ull;
	csr_fatal("BDK_TNS_RDMA_NB_LMAC_PLUTX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_RDMA_NB_LMAC_PLUTX(...) bdk_tns_rdma_nb_lmac_plutx_t
#define bustype_BDK_TNS_RDMA_NB_LMAC_PLUTX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_LMAC_PLUTX(p1) (p1)
#define arguments_BDK_TNS_RDMA_NB_LMAC_PLUTX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_LMAC_PLUTX(...) "TNS_RDMA_NB_LMAC_PLUTX"


/**
 * NCB - tns_rdma_nb_loopback_plut
 *
 * Translates the arriving loopback physical port number to an 8-bit logical port number.
 * Hardware will initialize this table upon direction by software to perform
 * auto-initialization.
 * Some physical to logical aliasing will occur as there are more physical
 * ports than the 8-bit logical port width allows:
 *   * 256 NIC channels
 *   * 8 LMAC ports
 *   * 1 Loopback port
 */
typedef union bdk_tns_rdma_nb_loopback_plut {
	uint64_t u;
	struct bdk_tns_rdma_nb_loopback_plut_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t logical_port                : 8;  /**< R/W/H - Logical port number for the loopback physical port number. */
#else
		uint64_t logical_port                : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_loopback_plut_s cn85xx; */
	/* struct bdk_tns_rdma_nb_loopback_plut_s cn88xx; */
} bdk_tns_rdma_nb_loopback_plut_t;

#define BDK_TNS_RDMA_NB_LOOPBACK_PLUT BDK_TNS_RDMA_NB_LOOPBACK_PLUT_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_LOOPBACK_PLUT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_LOOPBACK_PLUT_FUNC(void)
{
	return 0x0000842042002080ull;
}
#define typedef_BDK_TNS_RDMA_NB_LOOPBACK_PLUT bdk_tns_rdma_nb_loopback_plut_t
#define bustype_BDK_TNS_RDMA_NB_LOOPBACK_PLUT BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_LOOPBACK_PLUT 0
#define arguments_BDK_TNS_RDMA_NB_LOOPBACK_PLUT -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_LOOPBACK_PLUT "TNS_RDMA_NB_LOOPBACK_PLUT"


/**
 * NCB - tns_rdma_nb_lp_plut#
 *
 * Translates the 8-bit logical port number to a 4-bit physical port, indicating
 * the physical port on which the packet was originally received.
 * This table must be programmed to reverse map the contents of the following Tables:
 *   * TNS_NIC_PLUT(0..255)
 *   * TNS_LMAC_PLUT(0..7)
 *   * TNS_LOOPBACK_PLUT
 * Values have the meaning as defined in TNS_PHYS_PORT_E.
 * Hardware will initialize this table upon direction by software to perform
 * auto-initialization.
 */
typedef union bdk_tns_rdma_nb_lp_plutx {
	uint64_t u;
	struct bdk_tns_rdma_nb_lp_plutx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t physical_port               : 4;  /**< R/W/H - Physical port number associated with the logical port number. */
#else
		uint64_t physical_port               : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_lp_plutx_s  cn85xx; */
	/* struct bdk_tns_rdma_nb_lp_plutx_s  cn88xx; */
} bdk_tns_rdma_nb_lp_plutx_t;

static inline uint64_t BDK_TNS_RDMA_NB_LP_PLUTX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_LP_PLUTX(unsigned long param1)
{
	if (((param1 <= 255)))
		return 0x0000842042003000ull + (param1 & 255) * 0x10ull;
	csr_fatal("BDK_TNS_RDMA_NB_LP_PLUTX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_RDMA_NB_LP_PLUTX(...) bdk_tns_rdma_nb_lp_plutx_t
#define bustype_BDK_TNS_RDMA_NB_LP_PLUTX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_LP_PLUTX(p1) (p1)
#define arguments_BDK_TNS_RDMA_NB_LP_PLUTX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_LP_PLUTX(...) "TNS_RDMA_NB_LP_PLUTX"


/**
 * NCB - tns_rdma_nb_nic_c_cdt_pnd#
 */
typedef union bdk_tns_rdma_nb_nic_c_cdt_pndx {
	uint64_t u;
	struct bdk_tns_rdma_nb_nic_c_cdt_pndx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< RO/H - A credit return message is pending to be sent for the channel. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_nic_c_cdt_pndx_s cn85xx; */
	/* struct bdk_tns_rdma_nb_nic_c_cdt_pndx_s cn88xx; */
} bdk_tns_rdma_nb_nic_c_cdt_pndx_t;

static inline uint64_t BDK_TNS_RDMA_NB_NIC_C_CDT_PNDX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_NIC_C_CDT_PNDX(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000842042004200ull + (param1 & 3) * 0x10ull;
	csr_fatal("BDK_TNS_RDMA_NB_NIC_C_CDT_PNDX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_RDMA_NB_NIC_C_CDT_PNDX(...) bdk_tns_rdma_nb_nic_c_cdt_pndx_t
#define bustype_BDK_TNS_RDMA_NB_NIC_C_CDT_PNDX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_NIC_C_CDT_PNDX(p1) (p1)
#define arguments_BDK_TNS_RDMA_NB_NIC_C_CDT_PNDX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_NIC_C_CDT_PNDX(...) "TNS_RDMA_NB_NIC_C_CDT_PNDX"


/**
 * NCB - tns_rdma_nb_nic_plut#
 *
 * Translates the arriving NIC channel to an 8-bit logical port number.
 * Hardware will initialize this table upon direction by software to perform
 * auto-initialization.
 * Some physical to logical aliasing will occur as there are more physical
 * ports than the 8-bit logical port width allows:
 *   * 256 NIC channels
 *   * 8 LMAC ports
 *   * 1 Loopback port
 */
typedef union bdk_tns_rdma_nb_nic_plutx {
	uint64_t u;
	struct bdk_tns_rdma_nb_nic_plutx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t logical_port                : 8;  /**< R/W/H - Logical port number for the specified NIC channel. */
#else
		uint64_t logical_port                : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_nic_plutx_s cn85xx; */
	/* struct bdk_tns_rdma_nb_nic_plutx_s cn88xx; */
} bdk_tns_rdma_nb_nic_plutx_t;

static inline uint64_t BDK_TNS_RDMA_NB_NIC_PLUTX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_NIC_PLUTX(unsigned long param1)
{
	if (((param1 <= 255)))
		return 0x0000842042001000ull + (param1 & 255) * 0x10ull;
	csr_fatal("BDK_TNS_RDMA_NB_NIC_PLUTX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_RDMA_NB_NIC_PLUTX(...) bdk_tns_rdma_nb_nic_plutx_t
#define bustype_BDK_TNS_RDMA_NB_NIC_PLUTX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_NIC_PLUTX(p1) (p1)
#define arguments_BDK_TNS_RDMA_NB_NIC_PLUTX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_NIC_PLUTX(...) "TNS_RDMA_NB_NIC_PLUTX"


/**
 * NCB - tns_rdma_nb_nici#_rpkt_sz
 *
 * Hardware will flag packets arriving from the NICI if the size is
 * less than or equal to the programmed value.
 * Marked runt packets are counted.
 */
typedef union bdk_tns_rdma_nb_nicix_rpkt_sz {
	uint64_t u;
	struct bdk_tns_rdma_nb_nicix_rpkt_sz_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t bytes                       : 8;  /**< R/W - Packets received from NICI with size greater than this will be passed to the
                                                                 network switch for processing.
                                                                 Packets with a size that is equal or less will be marked as runt and counted. */
#else
		uint64_t bytes                       : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_nicix_rpkt_sz_s cn85xx; */
	/* struct bdk_tns_rdma_nb_nicix_rpkt_sz_s cn88xx; */
} bdk_tns_rdma_nb_nicix_rpkt_sz_t;

static inline uint64_t BDK_TNS_RDMA_NB_NICIX_RPKT_SZ(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_NICIX_RPKT_SZ(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000842042000A80ull + (param1 & 1) * 0x10ull;
	csr_fatal("BDK_TNS_RDMA_NB_NICIX_RPKT_SZ", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_RDMA_NB_NICIX_RPKT_SZ(...) bdk_tns_rdma_nb_nicix_rpkt_sz_t
#define bustype_BDK_TNS_RDMA_NB_NICIX_RPKT_SZ(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_NICIX_RPKT_SZ(p1) (p1)
#define arguments_BDK_TNS_RDMA_NB_NICIX_RPKT_SZ(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_NICIX_RPKT_SZ(...) "TNS_RDMA_NB_NICIX_RPKT_SZ"


/**
 * NCB - tns_rdma_nb_path_enable
 *
 * When 0x1, allows the RDMA to accept packets and return credits;
 * when 0x0, resets state and does not allow receiving of packets from the indicated port.
 */
typedef union bdk_tns_rdma_nb_path_enable {
	uint64_t u;
	struct bdk_tns_rdma_nb_path_enable_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t nici1_bp                    : 1;  /**< R/W - When 0x1, allows back pressure information to be sent to NICI1.
                                                                 When 0x0, resets state and does not send back pressure information to NICI1. */
		uint64_t nici0_bp                    : 1;  /**< R/W - When 0x1, allows back pressure information to be sent to NICI0.
                                                                 When 0x0, resets state and does not send back pressure information to NICI0. */
		uint64_t bgx1_bp                     : 1;  /**< R/W - When 0x1, allows back pressure information to be sent to BGX1.
                                                                 When 0x0, resets state and does not send back pressure information to BGX1. */
		uint64_t bgx0_bp                     : 1;  /**< R/W - When 0x1, allows back pressure information to be sent to BGX0.
                                                                 When 0x0, resets state and does not send back pressure information to BGX0. */
		uint64_t reserved_11_15              : 5;
		uint64_t loopback                    : 1;  /**< R/W - When 0x1, allows packets to be received from loopback and credits to be returned.
                                                                 When 0x0, resets state and does not allow receiving of packets from the port. */
		uint64_t nici1                       : 1;  /**< R/W - When 0x1, allows packets to be received from NICI1 and credits to be returned.
                                                                 When 0x0, resets state and does not allow receiving of packets from the port. */
		uint64_t nici0                       : 1;  /**< R/W - When 0x1, allows packets to be received from NICI0 and credits to be returned.
                                                                 When 0x0, resets state and does not allow receiving of packets from the port. */
		uint64_t lmac                        : 8;  /**< R/W - For each bit:
                                                                 When 0x1, allows packets to be received from the LMAC.
                                                                 When 0x0, resets state and does not allow receiving of packets from the port. */
#else
		uint64_t lmac                        : 8;
		uint64_t nici0                       : 1;
		uint64_t nici1                       : 1;
		uint64_t loopback                    : 1;
		uint64_t reserved_11_15              : 5;
		uint64_t bgx0_bp                     : 1;
		uint64_t bgx1_bp                     : 1;
		uint64_t nici0_bp                    : 1;
		uint64_t nici1_bp                    : 1;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_path_enable_s cn85xx; */
	/* struct bdk_tns_rdma_nb_path_enable_s cn88xx; */
} bdk_tns_rdma_nb_path_enable_t;

#define BDK_TNS_RDMA_NB_PATH_ENABLE BDK_TNS_RDMA_NB_PATH_ENABLE_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_PATH_ENABLE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_PATH_ENABLE_FUNC(void)
{
	return 0x0000842042000AA0ull;
}
#define typedef_BDK_TNS_RDMA_NB_PATH_ENABLE bdk_tns_rdma_nb_path_enable_t
#define bustype_BDK_TNS_RDMA_NB_PATH_ENABLE BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_PATH_ENABLE 0
#define arguments_BDK_TNS_RDMA_NB_PATH_ENABLE -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_PATH_ENABLE "TNS_RDMA_NB_PATH_ENABLE"


/**
 * NCB - tns_rdma_nb_rpkt_data#
 *
 * Stores the first 256 bytes of a runt packet.
 * The first 8 bytes are stored in the DATA0 register in network order.
 * The data in this register is valid only if TNS_RDMA_NB_INT_STAT_W1S[RUNT_PKT] was
 * set by hardware.
 * The data in this register is valid only up to the byte length indicated by
 * TNS_RDMA_NB_RPKT_INFO[SIZE].
 */
typedef union bdk_tns_rdma_nb_rpkt_datax {
	uint64_t u;
	struct bdk_tns_rdma_nb_rpkt_datax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< RO/H - Captured packet data. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_rpkt_datax_s cn85xx; */
	/* struct bdk_tns_rdma_nb_rpkt_datax_s cn88xx; */
} bdk_tns_rdma_nb_rpkt_datax_t;

static inline uint64_t BDK_TNS_RDMA_NB_RPKT_DATAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_RPKT_DATAX(unsigned long param1)
{
	if (((param1 <= 31)))
		return 0x0000842042000600ull + (param1 & 31) * 0x10ull;
	csr_fatal("BDK_TNS_RDMA_NB_RPKT_DATAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_RDMA_NB_RPKT_DATAX(...) bdk_tns_rdma_nb_rpkt_datax_t
#define bustype_BDK_TNS_RDMA_NB_RPKT_DATAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_RPKT_DATAX(p1) (p1)
#define arguments_BDK_TNS_RDMA_NB_RPKT_DATAX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_RPKT_DATAX(...) "TNS_RDMA_NB_RPKT_DATAX"


/**
 * NCB - tns_rdma_nb_rpkt_info
 *
 * Information about the packet captured to the Runt Packet Data Logging Register.
 * The data in this register is valid only if TNS_RDMA_NB_INT_STAT_W1S[RUNT_PKT] was
 * set by hardware.
 */
typedef union bdk_tns_rdma_nb_rpkt_info {
	uint64_t u;
	struct bdk_tns_rdma_nb_rpkt_info_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t logical_port                : 8;  /**< RO/H - Captured packet source logical port. Only valid if PHYSICAL_PORT is NICI0 or NICI1. */
		uint64_t physical_port               : 4;  /**< RO/H - Captured packet source physical port as enumerated by TNS_PHYS_PORT_E. */
		uint64_t size                        : 8;  /**< RO/H - Captured packet byte length. */
#else
		uint64_t size                        : 8;
		uint64_t physical_port               : 4;
		uint64_t logical_port                : 8;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_rpkt_info_s cn85xx; */
	/* struct bdk_tns_rdma_nb_rpkt_info_s cn88xx; */
} bdk_tns_rdma_nb_rpkt_info_t;

#define BDK_TNS_RDMA_NB_RPKT_INFO BDK_TNS_RDMA_NB_RPKT_INFO_FUNC()
static inline uint64_t BDK_TNS_RDMA_NB_RPKT_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_RPKT_INFO_FUNC(void)
{
	return 0x0000842042000800ull;
}
#define typedef_BDK_TNS_RDMA_NB_RPKT_INFO bdk_tns_rdma_nb_rpkt_info_t
#define bustype_BDK_TNS_RDMA_NB_RPKT_INFO BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_RPKT_INFO 0
#define arguments_BDK_TNS_RDMA_NB_RPKT_INFO -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_RPKT_INFO "TNS_RDMA_NB_RPKT_INFO"


/**
 * NCB - tns_rdma_nb_runt_cnt#
 *
 * Runt packets and bytes received by the physical port.
 * All fields have roll over counters.
 */
typedef union bdk_tns_rdma_nb_runt_cntx {
	uint64_t u;
	struct bdk_tns_rdma_nb_runt_cntx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t bytes                       : 16; /**< R/W/H - Runt packet bytes seen. */
		uint64_t packets                     : 8;  /**< R/W/H - Runt packets seen. */
#else
		uint64_t packets                     : 8;
		uint64_t bytes                       : 16;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_tns_rdma_nb_runt_cntx_s cn85xx; */
	/* struct bdk_tns_rdma_nb_runt_cntx_s cn88xx; */
} bdk_tns_rdma_nb_runt_cntx_t;

static inline uint64_t BDK_TNS_RDMA_NB_RUNT_CNTX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NB_RUNT_CNTX(unsigned long param1)
{
	if (((param1 <= 9)))
		return 0x0000842042000400ull + (param1 & 15) * 0x10ull;
	csr_fatal("BDK_TNS_RDMA_NB_RUNT_CNTX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_RDMA_NB_RUNT_CNTX(...) bdk_tns_rdma_nb_runt_cntx_t
#define bustype_BDK_TNS_RDMA_NB_RUNT_CNTX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NB_RUNT_CNTX(p1) (p1)
#define arguments_BDK_TNS_RDMA_NB_RUNT_CNTX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_RDMA_NB_RUNT_CNTX(...) "TNS_RDMA_NB_RUNT_CNTX"


/**
 * NCB - tns_rdma_nic_cdt_rtn
 *
 * Force a credit return message to the NIC.
 *
 */
typedef union bdk_tns_rdma_nic_cdt_rtn {
	uint64_t u;
	struct bdk_tns_rdma_nic_cdt_rtn_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t valid                       : 1;  /**< R/W/H - Valid.
                                                                 Hardware will clear this field upon the successful transmission of a channel
                                                                 credit message to the NIC using this CSR.
                                                                 Software must verify this field is 0 before setting this bit. */
		uint64_t reserved_16_30              : 15;
		uint64_t pages                       : 4;  /**< R/W - Quantity of 256-byte pages. 0 = 16 pages, 1 = 1 page, 2 = 2 pages, etc. */
		uint64_t intf                        : 1;  /**< R/W - NIC interface. */
		uint64_t channel                     : 7;  /**< R/W - NIC channel. */
		uint64_t reserved_1_3                : 3;
		uint64_t eop                         : 1;  /**< R/W - Send EOP flag. */
#else
		uint64_t eop                         : 1;
		uint64_t reserved_1_3                : 3;
		uint64_t channel                     : 7;
		uint64_t intf                        : 1;
		uint64_t pages                       : 4;
		uint64_t reserved_16_30              : 15;
		uint64_t valid                       : 1;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_tns_rdma_nic_cdt_rtn_s  cn85xx; */
	/* struct bdk_tns_rdma_nic_cdt_rtn_s  cn88xx; */
} bdk_tns_rdma_nic_cdt_rtn_t;

#define BDK_TNS_RDMA_NIC_CDT_RTN BDK_TNS_RDMA_NIC_CDT_RTN_FUNC()
static inline uint64_t BDK_TNS_RDMA_NIC_CDT_RTN_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_RDMA_NIC_CDT_RTN_FUNC(void)
{
	return 0x0000842000001A30ull;
}
#define typedef_BDK_TNS_RDMA_NIC_CDT_RTN bdk_tns_rdma_nic_cdt_rtn_t
#define bustype_BDK_TNS_RDMA_NIC_CDT_RTN BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_RDMA_NIC_CDT_RTN 0
#define arguments_BDK_TNS_RDMA_NIC_CDT_RTN -1,-1,-1,-1
#define basename_BDK_TNS_RDMA_NIC_CDT_RTN "TNS_RDMA_NIC_CDT_RTN"


/**
 * NCB32b - tns_sde_parser_cfg_sde_spare_w0
 *
 * Spare register with default signature value 0x10FEDCBA98765432 after reset.
 *
 */
typedef union bdk_tns_sde_parser_cfg_sde_spare_w0 {
	uint32_t u;
	struct bdk_tns_sde_parser_cfg_sde_spare_w0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t spare_x0                    : 32; /**< R/W - Spare field. */
#else
		uint32_t spare_x0                    : 32;
#endif
	} s;
	/* struct bdk_tns_sde_parser_cfg_sde_spare_w0_s cn85xx; */
	/* struct bdk_tns_sde_parser_cfg_sde_spare_w0_s cn88xx; */
} bdk_tns_sde_parser_cfg_sde_spare_w0_t;

#define BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W0 BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W0_FUNC()
static inline uint64_t BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W0_FUNC(void)
{
	return 0x0000842068740000ull;
}
#define typedef_BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W0 bdk_tns_sde_parser_cfg_sde_spare_w0_t
#define bustype_BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W0 0
#define arguments_BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W0 -1,-1,-1,-1
#define basename_BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W0 "TNS_SDE_PARSER_CFG_SDE_SPARE_W0"


/**
 * NCB32b - tns_sde_parser_cfg_sde_spare_w1
 *
 * Continuation of structure defined in TNS_SDE_PARSER_CFG_SDE_SPARE_W0
 *
 */
typedef union bdk_tns_sde_parser_cfg_sde_spare_w1 {
	uint32_t u;
	struct bdk_tns_sde_parser_cfg_sde_spare_w1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t spare_x1                    : 32; /**< R/W - Continuation of field SPARE_X0. */
#else
		uint32_t spare_x1                    : 32;
#endif
	} s;
	/* struct bdk_tns_sde_parser_cfg_sde_spare_w1_s cn85xx; */
	/* struct bdk_tns_sde_parser_cfg_sde_spare_w1_s cn88xx; */
} bdk_tns_sde_parser_cfg_sde_spare_w1_t;

#define BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W1 BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W1_FUNC()
static inline uint64_t BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W1_FUNC(void)
{
	return 0x0000842068740004ull;
}
#define typedef_BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W1 bdk_tns_sde_parser_cfg_sde_spare_w1_t
#define bustype_BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W1 0
#define arguments_BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W1 -1,-1,-1,-1
#define basename_BDK_TNS_SDE_PARSER_CFG_SDE_SPARE_W1 "TNS_SDE_PARSER_CFG_SDE_SPARE_W1"


/**
 * NCB32b - tns_se_tcam_table_spare_w0
 *
 * --
 *
 */
typedef union bdk_tns_se_tcam_table_spare_w0 {
	uint32_t u;
	struct bdk_tns_se_tcam_table_spare_w0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t xp_se_spare_x0              : 32; /**< R/W - Spare register with an SE debug signature 0x0FEDCBA987654321 */
#else
		uint32_t xp_se_spare_x0              : 32;
#endif
	} s;
	/* struct bdk_tns_se_tcam_table_spare_w0_s cn85xx; */
	/* struct bdk_tns_se_tcam_table_spare_w0_s cn88xx; */
} bdk_tns_se_tcam_table_spare_w0_t;

#define BDK_TNS_SE_TCAM_TABLE_SPARE_W0 BDK_TNS_SE_TCAM_TABLE_SPARE_W0_FUNC()
static inline uint64_t BDK_TNS_SE_TCAM_TABLE_SPARE_W0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_SE_TCAM_TABLE_SPARE_W0_FUNC(void)
{
	return 0x0000842052200040ull;
}
#define typedef_BDK_TNS_SE_TCAM_TABLE_SPARE_W0 bdk_tns_se_tcam_table_spare_w0_t
#define bustype_BDK_TNS_SE_TCAM_TABLE_SPARE_W0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_TNS_SE_TCAM_TABLE_SPARE_W0 0
#define arguments_BDK_TNS_SE_TCAM_TABLE_SPARE_W0 -1,-1,-1,-1
#define basename_BDK_TNS_SE_TCAM_TABLE_SPARE_W0 "TNS_SE_TCAM_TABLE_SPARE_W0"


/**
 * NCB32b - tns_se_tcam_table_spare_w1
 *
 * Continuation of structure defined in TNS_SE_TCAM_TABLE_SPARE_W0
 *
 */
typedef union bdk_tns_se_tcam_table_spare_w1 {
	uint32_t u;
	struct bdk_tns_se_tcam_table_spare_w1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t xp_se_spare_x1              : 32; /**< R/W - Continuation of field XP_SE_SPARE_X0. */
#else
		uint32_t xp_se_spare_x1              : 32;
#endif
	} s;
	/* struct bdk_tns_se_tcam_table_spare_w1_s cn85xx; */
	/* struct bdk_tns_se_tcam_table_spare_w1_s cn88xx; */
} bdk_tns_se_tcam_table_spare_w1_t;

#define BDK_TNS_SE_TCAM_TABLE_SPARE_W1 BDK_TNS_SE_TCAM_TABLE_SPARE_W1_FUNC()
static inline uint64_t BDK_TNS_SE_TCAM_TABLE_SPARE_W1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_SE_TCAM_TABLE_SPARE_W1_FUNC(void)
{
	return 0x0000842052200044ull;
}
#define typedef_BDK_TNS_SE_TCAM_TABLE_SPARE_W1 bdk_tns_se_tcam_table_spare_w1_t
#define bustype_BDK_TNS_SE_TCAM_TABLE_SPARE_W1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_TNS_SE_TCAM_TABLE_SPARE_W1 0
#define arguments_BDK_TNS_SE_TCAM_TABLE_SPARE_W1 -1,-1,-1,-1
#define basename_BDK_TNS_SE_TCAM_TABLE_SPARE_W1 "TNS_SE_TCAM_TABLE_SPARE_W1"


/**
 * NCB - tns_tdma_cap
 */
typedef union bdk_tns_tdma_cap {
	uint64_t u;
	struct bdk_tns_tdma_cap_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t switch_capable              : 1;  /**< RO/H - When 1, indicates this device is capable of performing network switching functions.
                                                                 INTERNAL:
                                                                 This field comes from the rst_fus__tns_cripple pin. */
#else
		uint64_t switch_capable              : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_tns_tdma_cap_s          cn85xx; */
	/* struct bdk_tns_tdma_cap_s          cn88xx; */
} bdk_tns_tdma_cap_t;

#define BDK_TNS_TDMA_CAP BDK_TNS_TDMA_CAP_FUNC()
static inline uint64_t BDK_TNS_TDMA_CAP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_CAP_FUNC(void)
{
	return 0x0000842000000400ull;
}
#define typedef_BDK_TNS_TDMA_CAP bdk_tns_tdma_cap_t
#define bustype_BDK_TNS_TDMA_CAP BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_CAP 0
#define arguments_BDK_TNS_TDMA_CAP -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_CAP "TNS_TDMA_CAP"


/**
 * NCB - tns_tdma_cnt#
 *
 * Packets and bytes transmitted by the physical port.
 * All fields have roll over counters.
 * Register number enumerated by TNS_PHYS_PORT_E.
 */
typedef union bdk_tns_tdma_cntx {
	uint64_t u;
	struct bdk_tns_tdma_cntx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t bytes                       : 36; /**< R/W/H - Packet bytes. */
		uint64_t packets                     : 24; /**< R/W/H - Packets. */
#else
		uint64_t packets                     : 24;
		uint64_t bytes                       : 36;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_tns_tdma_cntx_s         cn85xx; */
	/* struct bdk_tns_tdma_cntx_s         cn88xx; */
} bdk_tns_tdma_cntx_t;

static inline uint64_t BDK_TNS_TDMA_CNTX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_CNTX(unsigned long param1)
{
	if (((param1 <= 9)))
		return 0x0000842000000600ull + (param1 & 15) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_CNTX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_CNTX(...) bdk_tns_tdma_cntx_t
#define bustype_BDK_TNS_TDMA_CNTX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_CNTX(p1) (p1)
#define arguments_BDK_TNS_TDMA_CNTX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_CNTX(...) "TNS_TDMA_CNTX"


/**
 * NCB - tns_tdma_config
 */
typedef union bdk_tns_tdma_config {
	uint64_t u;
	struct bdk_tns_tdma_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t bypass1_ena                 : 1;  /**< R/W - BGX1 <-> NICI1 Bypass Enable.
                                                                 Packet and back pressure information are passed directly between NIC Interface 1 and BGX1.
                                                                 Software must guarantee that no packets are in flight from/to BGX1/NICI1 when this bit is
                                                                 flipped.
                                                                 INTERNAL:
                                                                 This field can be set only if TNS_TDMA_CAP[SWITCH_CAPABLE] is set. */
		uint64_t bypass0_ena                 : 1;  /**< R/W - BGX0 <-> NICI0 Bypass Enable.
                                                                 Packet and back pressure information are passed directly between NIC Interface 0 and BGX0.
                                                                 Software must guarantee that no packets are in flight from/to BGX0/NICI0 when this bit is
                                                                 flipped.
                                                                 INTERNAL:
                                                                 This field can be set only if TNS_TDMA_CAP[SWITCH_CAPABLE] is set. */
		uint64_t reserved_5_7                : 3;
		uint64_t csr_access_ena              : 1;  /**< R/W - Enable access to network switch registers.
                                                                 INTERNAL:
                                                                 This field can be set only if TNS_TDMA_CAP[SWITCH_CAPABLE] is set. */
		uint64_t reserved_2_3                : 2;
		uint64_t clk_2x_ena                  : 1;  /**< R/W - Enable fast clock.
                                                                 INTERNAL:
                                                                 Enable conditional clock to non-bypass memories.
                                                                 This field can be set only if TNS_TDMA_CAP[SWITCH_CAPABLE] is set. */
		uint64_t clk_ena                     : 1;  /**< R/W - Enable slow clock.
                                                                 INTERNAL:
                                                                 Enable conditional clock to non-bypass logic.
                                                                 This field can be set only if TNS_TDMA_CAP[SWITCH_CAPABLE] is set. */
#else
		uint64_t clk_ena                     : 1;
		uint64_t clk_2x_ena                  : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t csr_access_ena              : 1;
		uint64_t reserved_5_7                : 3;
		uint64_t bypass0_ena                 : 1;
		uint64_t bypass1_ena                 : 1;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_tns_tdma_config_s       cn85xx; */
	/* struct bdk_tns_tdma_config_s       cn88xx; */
} bdk_tns_tdma_config_t;

#define BDK_TNS_TDMA_CONFIG BDK_TNS_TDMA_CONFIG_FUNC()
static inline uint64_t BDK_TNS_TDMA_CONFIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_CONFIG_FUNC(void)
{
	return 0x0000842000000200ull;
}
#define typedef_BDK_TNS_TDMA_CONFIG bdk_tns_tdma_config_t
#define bustype_BDK_TNS_TDMA_CONFIG BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_CONFIG 0
#define arguments_BDK_TNS_TDMA_CONFIG -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_CONFIG "TNS_TDMA_CONFIG"


/**
 * NCB - tns_tdma_dbg_cdt_ctl
 *
 * This register provides debug control of packet transmission.
 *
 */
typedef union bdk_tns_tdma_dbg_cdt_ctl {
	uint64_t u;
	struct bdk_tns_tdma_dbg_cdt_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t lmac_skid_cdts_inc          : 8;  /**< WO/H - Each write to this field increments the count of skid credits to the LMACs. */
		uint64_t lmac_fifo_cdts_inc          : 8;  /**< WO/H - Each write to this field increments the count of FIFO credits to the LMACs. */
		uint64_t lmac_skid_cdts_dec          : 8;  /**< WO/H - Each write to this field decrements the count of skid credits to the LMACs. */
		uint64_t lmac_fifo_cdts_dec          : 8;  /**< WO/H - Each write to this field decrements the count of FIFO credits to the LMACs. */
#else
		uint64_t lmac_fifo_cdts_dec          : 8;
		uint64_t lmac_skid_cdts_dec          : 8;
		uint64_t lmac_fifo_cdts_inc          : 8;
		uint64_t lmac_skid_cdts_inc          : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_tns_tdma_dbg_cdt_ctl_s  cn85xx; */
	/* struct bdk_tns_tdma_dbg_cdt_ctl_s  cn88xx; */
} bdk_tns_tdma_dbg_cdt_ctl_t;

#define BDK_TNS_TDMA_DBG_CDT_CTL BDK_TNS_TDMA_DBG_CDT_CTL_FUNC()
static inline uint64_t BDK_TNS_TDMA_DBG_CDT_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_DBG_CDT_CTL_FUNC(void)
{
	return 0x0000842000000A10ull;
}
#define typedef_BDK_TNS_TDMA_DBG_CDT_CTL bdk_tns_tdma_dbg_cdt_ctl_t
#define bustype_BDK_TNS_TDMA_DBG_CDT_CTL BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_DBG_CDT_CTL 0
#define arguments_BDK_TNS_TDMA_DBG_CDT_CTL -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_DBG_CDT_CTL "TNS_TDMA_DBG_CDT_CTL"


/**
 * NCB - tns_tdma_dbg_lmac#_config
 *
 * This register provides debug control of TDMA functionality.
 *
 */
typedef union bdk_tns_tdma_dbg_lmacx_config {
	uint64_t u;
	struct bdk_tns_tdma_dbg_lmacx_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t start_occ                   : 8;  /**< R/W - To guarantee outbound packet data can match the line rate of incoming cut-through packets,
                                                                 packet data is stored in the FIFO buffer until either a packet EOP is pushed to the FIFO
                                                                 or the quantity of data in the FIFO reaches this amount.
                                                                 This field must be equal or less than EARLY_FULL_OCC. */
		uint64_t reserved_8_15               : 8;
		uint64_t early_full_occ              : 8;  /**< R/W - When the outbound packet buffer occupancy reaches this point the FIFO will present
                                                                 a full indication to stop the packet pipeline from sending data across the shared async
                                                                 boundary. */
#else
		uint64_t early_full_occ              : 8;
		uint64_t reserved_8_15               : 8;
		uint64_t start_occ                   : 8;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_tns_tdma_dbg_lmacx_config_s cn85xx; */
	/* struct bdk_tns_tdma_dbg_lmacx_config_s cn88xx; */
} bdk_tns_tdma_dbg_lmacx_config_t;

static inline uint64_t BDK_TNS_TDMA_DBG_LMACX_CONFIG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_DBG_LMACX_CONFIG(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000842000000B00ull + (param1 & 7) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_DBG_LMACX_CONFIG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_DBG_LMACX_CONFIG(...) bdk_tns_tdma_dbg_lmacx_config_t
#define bustype_BDK_TNS_TDMA_DBG_LMACX_CONFIG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_DBG_LMACX_CONFIG(p1) (p1)
#define arguments_BDK_TNS_TDMA_DBG_LMACX_CONFIG(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_DBG_LMACX_CONFIG(...) "TNS_TDMA_DBG_LMACX_CONFIG"


/**
 * NCB - tns_tdma_dbg_lmac#_status1
 *
 * This register provides debug status of TDMA functionality.
 *
 */
typedef union bdk_tns_tdma_dbg_lmacx_status1 {
	uint64_t u;
	struct bdk_tns_tdma_dbg_lmacx_status1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t fifo_occ                    : 8;  /**< RO/H - Packet data FIFO occupancy.
                                                                 Each entry in the FIFO represents 1 16-byte flit. */
		uint64_t reserved_21_23              : 3;
		uint64_t skid_cdts                   : 5;  /**< RO/H - Skid credits available towards LMAC.
                                                                 Each credit represents 1 16-byte flit. */
		uint64_t reserved_14_15              : 2;
		uint64_t fifo_cdts                   : 14; /**< RO/H - FIFO credits consumed towards the LMAC.
                                                                 Each credit represents 1 16-byte flit. */
#else
		uint64_t fifo_cdts                   : 14;
		uint64_t reserved_14_15              : 2;
		uint64_t skid_cdts                   : 5;
		uint64_t reserved_21_23              : 3;
		uint64_t fifo_occ                    : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_tns_tdma_dbg_lmacx_status1_s cn85xx; */
	/* struct bdk_tns_tdma_dbg_lmacx_status1_s cn88xx; */
} bdk_tns_tdma_dbg_lmacx_status1_t;

static inline uint64_t BDK_TNS_TDMA_DBG_LMACX_STATUS1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_DBG_LMACX_STATUS1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000842000000C00ull + (param1 & 7) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_DBG_LMACX_STATUS1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_DBG_LMACX_STATUS1(...) bdk_tns_tdma_dbg_lmacx_status1_t
#define bustype_BDK_TNS_TDMA_DBG_LMACX_STATUS1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_DBG_LMACX_STATUS1(p1) (p1)
#define arguments_BDK_TNS_TDMA_DBG_LMACX_STATUS1(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_DBG_LMACX_STATUS1(...) "TNS_TDMA_DBG_LMACX_STATUS1"


/**
 * NCB - tns_tdma_dbg_nici#_config
 *
 * This register provides debug control of TDMA functionality.
 *
 */
typedef union bdk_tns_tdma_dbg_nicix_config {
	uint64_t u;
	struct bdk_tns_tdma_dbg_nicix_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t early_full_occ              : 8;  /**< R/W - When the outbound packet buffer occupancy reaches this point the FIFO will present
                                                                 a full indication to stop the packet pipeline from sending data across the shared async
                                                                 boundary. */
#else
		uint64_t early_full_occ              : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_tns_tdma_dbg_nicix_config_s cn85xx; */
	/* struct bdk_tns_tdma_dbg_nicix_config_s cn88xx; */
} bdk_tns_tdma_dbg_nicix_config_t;

static inline uint64_t BDK_TNS_TDMA_DBG_NICIX_CONFIG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_DBG_NICIX_CONFIG(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000842000000B80ull + (param1 & 1) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_DBG_NICIX_CONFIG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_DBG_NICIX_CONFIG(...) bdk_tns_tdma_dbg_nicix_config_t
#define bustype_BDK_TNS_TDMA_DBG_NICIX_CONFIG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_DBG_NICIX_CONFIG(p1) (p1)
#define arguments_BDK_TNS_TDMA_DBG_NICIX_CONFIG(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_DBG_NICIX_CONFIG(...) "TNS_TDMA_DBG_NICIX_CONFIG"


/**
 * NCB - tns_tdma_ecc_ctl
 *
 * This register can be used to disable ECC checks, insert ECC errors.
 * Fields *ECC_DIS disable SBE detection/correction and DBE detection. If ECC_DIS is 0x1, then no
 * errors are detected.
 * Fields *ECC_FLIP_SYND flip the syndrome<1:0> bits to generate 1-bit/2-bit error for testing.
 * * 0x0 = normal operation
 * * 0x1 = SBE on bit<0>
 * * 0x2 = SBE on bit<1>
 * * 0x3 = DBE on bits<1:0>
 */
typedef union bdk_tns_tdma_ecc_ctl {
	uint64_t u;
	struct bdk_tns_tdma_ecc_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_43_63              : 21;
		uint64_t vmem_ecc_dis                : 1;  /**< R/W - Disable ECC for MSIX VMEM. */
		uint64_t nici_ecc_dis                : 2;  /**< R/W - Disable ECC for NICI FIFOs. */
		uint64_t lmac_ecc_dis                : 8;  /**< R/W - Disable ECC for LMAC FIFOs. */
		uint64_t reserved_22_31              : 10;
		uint64_t vmem_ecc_flip_synd          : 2;  /**< R/W - Flip syndrome for all data written to MSIX VMEM. */
		uint64_t nici1_ecc_flip_synd         : 2;  /**< R/W - Flip syndrome for all data written to NICI1 packet path FIFOs. */
		uint64_t nici0_ecc_flip_synd         : 2;  /**< R/W - Flip syndrome for all data written to NICI0 packet path FIFOs. */
		uint64_t lmac7_ecc_flip_synd         : 2;  /**< R/W - Flip syndrome for all data written to LMAC7 packet path FIFOs. */
		uint64_t lmac6_ecc_flip_synd         : 2;  /**< R/W - Flip syndrome for all data written to LMAC6 packet path FIFOs. */
		uint64_t lmac5_ecc_flip_synd         : 2;  /**< R/W - Flip syndrome for all data written to LMAC5 packet path FIFOs. */
		uint64_t lmac4_ecc_flip_synd         : 2;  /**< R/W - Flip syndrome for all data written to LMAC4 packet path FIFOs. */
		uint64_t lmac3_ecc_flip_synd         : 2;  /**< R/W - Flip syndrome for all data written to LMAC3 packet path FIFOs. */
		uint64_t lmac2_ecc_flip_synd         : 2;  /**< R/W - Flip syndrome for all data written to LMAC2 packet path FIFOs. */
		uint64_t lmac1_ecc_flip_synd         : 2;  /**< R/W - Flip syndrome for all data written to LMAC1 packet path FIFOs. */
		uint64_t lmac0_ecc_flip_synd         : 2;  /**< R/W - Flip syndrome for all data written to LMAC0 packet path FIFOs. */
#else
		uint64_t lmac0_ecc_flip_synd         : 2;
		uint64_t lmac1_ecc_flip_synd         : 2;
		uint64_t lmac2_ecc_flip_synd         : 2;
		uint64_t lmac3_ecc_flip_synd         : 2;
		uint64_t lmac4_ecc_flip_synd         : 2;
		uint64_t lmac5_ecc_flip_synd         : 2;
		uint64_t lmac6_ecc_flip_synd         : 2;
		uint64_t lmac7_ecc_flip_synd         : 2;
		uint64_t nici0_ecc_flip_synd         : 2;
		uint64_t nici1_ecc_flip_synd         : 2;
		uint64_t vmem_ecc_flip_synd          : 2;
		uint64_t reserved_22_31              : 10;
		uint64_t lmac_ecc_dis                : 8;
		uint64_t nici_ecc_dis                : 2;
		uint64_t vmem_ecc_dis                : 1;
		uint64_t reserved_43_63              : 21;
#endif
	} s;
	/* struct bdk_tns_tdma_ecc_ctl_s      cn85xx; */
	/* struct bdk_tns_tdma_ecc_ctl_s      cn88xx; */
} bdk_tns_tdma_ecc_ctl_t;

#define BDK_TNS_TDMA_ECC_CTL BDK_TNS_TDMA_ECC_CTL_FUNC()
static inline uint64_t BDK_TNS_TDMA_ECC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_ECC_CTL_FUNC(void)
{
	return 0x0000842000000800ull;
}
#define typedef_BDK_TNS_TDMA_ECC_CTL bdk_tns_tdma_ecc_ctl_t
#define bustype_BDK_TNS_TDMA_ECC_CTL BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_ECC_CTL 0
#define arguments_BDK_TNS_TDMA_ECC_CTL -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_ECC_CTL "TNS_TDMA_ECC_CTL"


/**
 * NCB - tns_tdma_ecc_err_stat
 *
 * This register logs information to help debug ECC errors.
 *
 */
typedef union bdk_tns_tdma_ecc_err_stat {
	uint64_t u;
	struct bdk_tns_tdma_ecc_err_stat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_17_63              : 47;
		uint64_t syndrome                    : 9;  /**< RO/H - Error syndrome. */
		uint64_t reserved_7_7                : 1;
		uint64_t address                     : 7;  /**< RO/H - Address of ECC error. */
#else
		uint64_t address                     : 7;
		uint64_t reserved_7_7                : 1;
		uint64_t syndrome                    : 9;
		uint64_t reserved_17_63              : 47;
#endif
	} s;
	/* struct bdk_tns_tdma_ecc_err_stat_s cn85xx; */
	/* struct bdk_tns_tdma_ecc_err_stat_s cn88xx; */
} bdk_tns_tdma_ecc_err_stat_t;

#define BDK_TNS_TDMA_ECC_ERR_STAT BDK_TNS_TDMA_ECC_ERR_STAT_FUNC()
static inline uint64_t BDK_TNS_TDMA_ECC_ERR_STAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_ECC_ERR_STAT_FUNC(void)
{
	return 0x0000842000000810ull;
}
#define typedef_BDK_TNS_TDMA_ECC_ERR_STAT bdk_tns_tdma_ecc_err_stat_t
#define bustype_BDK_TNS_TDMA_ECC_ERR_STAT BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_ECC_ERR_STAT 0
#define arguments_BDK_TNS_TDMA_ECC_ERR_STAT -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_ECC_ERR_STAT "TNS_TDMA_ECC_ERR_STAT"


/**
 * NCB - tns_tdma_eco
 *
 * ECO register.
 *
 */
typedef union bdk_tns_tdma_eco {
	uint64_t u;
	struct bdk_tns_tdma_eco_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t rst1                        : 8;  /**< R/W - Reset to 1 spare bits */
		uint64_t rst0                        : 8;  /**< R/W - Reset to 0 spare bits */
#else
		uint64_t rst0                        : 8;
		uint64_t rst1                        : 8;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_tns_tdma_eco_s          cn85xx; */
	/* struct bdk_tns_tdma_eco_s          cn88xx; */
} bdk_tns_tdma_eco_t;

#define BDK_TNS_TDMA_ECO BDK_TNS_TDMA_ECO_FUNC()
static inline uint64_t BDK_TNS_TDMA_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_ECO_FUNC(void)
{
	return 0x0000842000000F00ull;
}
#define typedef_BDK_TNS_TDMA_ECO bdk_tns_tdma_eco_t
#define bustype_BDK_TNS_TDMA_ECO BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_ECO 0
#define arguments_BDK_TNS_TDMA_ECO -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_ECO "TNS_TDMA_ECO"


/**
 * NCB - tns_tdma_int_en_w1c
 *
 * TDMA Interrupt Enable Register.
 *
 */
typedef union bdk_tns_tdma_int_en_w1c {
	uint64_t u;
	struct bdk_tns_tdma_int_en_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_23_63              : 41;
		uint64_t vmem_dbe                    : 1;  /**< R/W1C/H - Double-bit ECC error detected on MSIX VMEM RAM. */
		uint64_t nici_dbe                    : 2;  /**< R/W1C/H - Double-bit ECC error detected on NICI[1..0] RAM. */
		uint64_t lmac_dbe                    : 8;  /**< R/W1C/H - Double-bit ECC error detected on LMAC[7..0] RAM. */
		uint64_t reserved_11_11              : 1;
		uint64_t vmem_sbe                    : 1;  /**< R/W1C/H - Single-bit ECC error detected on MSIX VMEM RAM. */
		uint64_t nici_sbe                    : 2;  /**< R/W1C/H - Single-bit ECC error detected on NICI[1..0] RAM. */
		uint64_t lmac_sbe                    : 8;  /**< R/W1C/H - Single-bit ECC error detected on LMAC[7..0] RAM. */
#else
		uint64_t lmac_sbe                    : 8;
		uint64_t nici_sbe                    : 2;
		uint64_t vmem_sbe                    : 1;
		uint64_t reserved_11_11              : 1;
		uint64_t lmac_dbe                    : 8;
		uint64_t nici_dbe                    : 2;
		uint64_t vmem_dbe                    : 1;
		uint64_t reserved_23_63              : 41;
#endif
	} s;
	/* struct bdk_tns_tdma_int_en_w1c_s   cn85xx; */
	/* struct bdk_tns_tdma_int_en_w1c_s   cn88xx; */
} bdk_tns_tdma_int_en_w1c_t;

#define BDK_TNS_TDMA_INT_EN_W1C BDK_TNS_TDMA_INT_EN_W1C_FUNC()
static inline uint64_t BDK_TNS_TDMA_INT_EN_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_INT_EN_W1C_FUNC(void)
{
	return 0x0000842000000130ull;
}
#define typedef_BDK_TNS_TDMA_INT_EN_W1C bdk_tns_tdma_int_en_w1c_t
#define bustype_BDK_TNS_TDMA_INT_EN_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_INT_EN_W1C 0
#define arguments_BDK_TNS_TDMA_INT_EN_W1C -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_INT_EN_W1C "TNS_TDMA_INT_EN_W1C"


/**
 * NCB - tns_tdma_int_en_w1s
 *
 * TDMA Interrupt Enable Register.
 *
 */
typedef union bdk_tns_tdma_int_en_w1s {
	uint64_t u;
	struct bdk_tns_tdma_int_en_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_23_63              : 41;
		uint64_t vmem_dbe                    : 1;  /**< R/W1S/H - Double-bit ECC error detected on MSIX VMEM RAM. */
		uint64_t nici_dbe                    : 2;  /**< R/W1S/H - Double-bit ECC error detected on NICI[1..0] RAM. */
		uint64_t lmac_dbe                    : 8;  /**< R/W1S/H - Double-bit ECC error detected on LMAC[7..0] RAM. */
		uint64_t reserved_11_11              : 1;
		uint64_t vmem_sbe                    : 1;  /**< R/W1S/H - Single-bit ECC error detected on MSIX VMEM RAM. */
		uint64_t nici_sbe                    : 2;  /**< R/W1S/H - Single-bit ECC error detected on NICI[1..0] RAM. */
		uint64_t lmac_sbe                    : 8;  /**< R/W1S/H - Single-bit ECC error detected on LMAC[7..0] RAM. */
#else
		uint64_t lmac_sbe                    : 8;
		uint64_t nici_sbe                    : 2;
		uint64_t vmem_sbe                    : 1;
		uint64_t reserved_11_11              : 1;
		uint64_t lmac_dbe                    : 8;
		uint64_t nici_dbe                    : 2;
		uint64_t vmem_dbe                    : 1;
		uint64_t reserved_23_63              : 41;
#endif
	} s;
	/* struct bdk_tns_tdma_int_en_w1s_s   cn85xx; */
	/* struct bdk_tns_tdma_int_en_w1s_s   cn88xx; */
} bdk_tns_tdma_int_en_w1s_t;

#define BDK_TNS_TDMA_INT_EN_W1S BDK_TNS_TDMA_INT_EN_W1S_FUNC()
static inline uint64_t BDK_TNS_TDMA_INT_EN_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_INT_EN_W1S_FUNC(void)
{
	return 0x0000842000000120ull;
}
#define typedef_BDK_TNS_TDMA_INT_EN_W1S bdk_tns_tdma_int_en_w1s_t
#define bustype_BDK_TNS_TDMA_INT_EN_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_INT_EN_W1S 0
#define arguments_BDK_TNS_TDMA_INT_EN_W1S -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_INT_EN_W1S "TNS_TDMA_INT_EN_W1S"


/**
 * NCB - tns_tdma_int_fen_w1c
 *
 * TDMA Interrupt First Enable Register.
 *
 */
typedef union bdk_tns_tdma_int_fen_w1c {
	uint64_t u;
	struct bdk_tns_tdma_int_fen_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_23_63              : 41;
		uint64_t vmem_dbe                    : 1;  /**< R/W1C - Double-bit ECC error detected on MSIX VMEM RAM. */
		uint64_t nici_dbe                    : 2;  /**< R/W1C - Double-bit ECC error detected on NICI[1..0] RAM. */
		uint64_t lmac_dbe                    : 8;  /**< R/W1C - Double-bit ECC error detected on LMAC[7..0] RAM. */
		uint64_t reserved_11_11              : 1;
		uint64_t vmem_sbe                    : 1;  /**< R/W1C - Single-bit ECC error detected on MSIX VMEM RAM. */
		uint64_t nici_sbe                    : 2;  /**< R/W1C - Single-bit ECC error detected on NICI[1..0] RAM. */
		uint64_t lmac_sbe                    : 8;  /**< R/W1C - Single-bit ECC error detected on LMAC[7..0] RAM. */
#else
		uint64_t lmac_sbe                    : 8;
		uint64_t nici_sbe                    : 2;
		uint64_t vmem_sbe                    : 1;
		uint64_t reserved_11_11              : 1;
		uint64_t lmac_dbe                    : 8;
		uint64_t nici_dbe                    : 2;
		uint64_t vmem_dbe                    : 1;
		uint64_t reserved_23_63              : 41;
#endif
	} s;
	/* struct bdk_tns_tdma_int_fen_w1c_s  cn85xx; */
	/* struct bdk_tns_tdma_int_fen_w1c_s  cn88xx; */
} bdk_tns_tdma_int_fen_w1c_t;

#define BDK_TNS_TDMA_INT_FEN_W1C BDK_TNS_TDMA_INT_FEN_W1C_FUNC()
static inline uint64_t BDK_TNS_TDMA_INT_FEN_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_INT_FEN_W1C_FUNC(void)
{
	return 0x0000842000000160ull;
}
#define typedef_BDK_TNS_TDMA_INT_FEN_W1C bdk_tns_tdma_int_fen_w1c_t
#define bustype_BDK_TNS_TDMA_INT_FEN_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_INT_FEN_W1C 0
#define arguments_BDK_TNS_TDMA_INT_FEN_W1C -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_INT_FEN_W1C "TNS_TDMA_INT_FEN_W1C"


/**
 * NCB - tns_tdma_int_fen_w1s
 *
 * TDMA Interrupt First Enable Register.
 *
 */
typedef union bdk_tns_tdma_int_fen_w1s {
	uint64_t u;
	struct bdk_tns_tdma_int_fen_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_23_63              : 41;
		uint64_t vmem_dbe                    : 1;  /**< R/W1S - Double-bit ECC error detected on MSIX VMEM RAM. */
		uint64_t nici_dbe                    : 2;  /**< R/W1S - Double-bit ECC error detected on NICI[1..0] RAM. */
		uint64_t lmac_dbe                    : 8;  /**< R/W1S - Double-bit ECC error detected on LMAC[7..0] RAM. */
		uint64_t reserved_11_11              : 1;
		uint64_t vmem_sbe                    : 1;  /**< R/W1S - Single-bit ECC error detected on MSIX VMEM RAM. */
		uint64_t nici_sbe                    : 2;  /**< R/W1S - Single-bit ECC error detected on NICI[1..0] RAM. */
		uint64_t lmac_sbe                    : 8;  /**< R/W1S - Single-bit ECC error detected on LMAC[7..0] RAM. */
#else
		uint64_t lmac_sbe                    : 8;
		uint64_t nici_sbe                    : 2;
		uint64_t vmem_sbe                    : 1;
		uint64_t reserved_11_11              : 1;
		uint64_t lmac_dbe                    : 8;
		uint64_t nici_dbe                    : 2;
		uint64_t vmem_dbe                    : 1;
		uint64_t reserved_23_63              : 41;
#endif
	} s;
	/* struct bdk_tns_tdma_int_fen_w1s_s  cn85xx; */
	/* struct bdk_tns_tdma_int_fen_w1s_s  cn88xx; */
} bdk_tns_tdma_int_fen_w1s_t;

#define BDK_TNS_TDMA_INT_FEN_W1S BDK_TNS_TDMA_INT_FEN_W1S_FUNC()
static inline uint64_t BDK_TNS_TDMA_INT_FEN_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_INT_FEN_W1S_FUNC(void)
{
	return 0x0000842000000150ull;
}
#define typedef_BDK_TNS_TDMA_INT_FEN_W1S bdk_tns_tdma_int_fen_w1s_t
#define bustype_BDK_TNS_TDMA_INT_FEN_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_INT_FEN_W1S 0
#define arguments_BDK_TNS_TDMA_INT_FEN_W1S -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_INT_FEN_W1S "TNS_TDMA_INT_FEN_W1S"


/**
 * NCB - tns_tdma_int_fstat
 *
 * TDMA Interrupt First Status Register.
 *
 */
typedef union bdk_tns_tdma_int_fstat {
	uint64_t u;
	struct bdk_tns_tdma_int_fstat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_23_63              : 41;
		uint64_t vmem_dbe                    : 1;  /**< RO/H - Double-bit ECC error detected on MSIX VMEM RAM. */
		uint64_t nici_dbe                    : 2;  /**< RO/H - Double-bit ECC error detected on NICI[1..0] RAM. */
		uint64_t lmac_dbe                    : 8;  /**< RO/H - Double-bit ECC error detected on LMAC[7..0] RAM. */
		uint64_t reserved_11_11              : 1;
		uint64_t vmem_sbe                    : 1;  /**< RO/H - Single-bit ECC error detected on MSIX VMEM RAM. */
		uint64_t nici_sbe                    : 2;  /**< RO/H - Single-bit ECC error detected on NICI[1..0] RAM. */
		uint64_t lmac_sbe                    : 8;  /**< RO/H - Single-bit ECC error detected on LMAC[7..0] RAM. */
#else
		uint64_t lmac_sbe                    : 8;
		uint64_t nici_sbe                    : 2;
		uint64_t vmem_sbe                    : 1;
		uint64_t reserved_11_11              : 1;
		uint64_t lmac_dbe                    : 8;
		uint64_t nici_dbe                    : 2;
		uint64_t vmem_dbe                    : 1;
		uint64_t reserved_23_63              : 41;
#endif
	} s;
	/* struct bdk_tns_tdma_int_fstat_s    cn85xx; */
	/* struct bdk_tns_tdma_int_fstat_s    cn88xx; */
} bdk_tns_tdma_int_fstat_t;

#define BDK_TNS_TDMA_INT_FSTAT BDK_TNS_TDMA_INT_FSTAT_FUNC()
static inline uint64_t BDK_TNS_TDMA_INT_FSTAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_INT_FSTAT_FUNC(void)
{
	return 0x0000842000000140ull;
}
#define typedef_BDK_TNS_TDMA_INT_FSTAT bdk_tns_tdma_int_fstat_t
#define bustype_BDK_TNS_TDMA_INT_FSTAT BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_INT_FSTAT 0
#define arguments_BDK_TNS_TDMA_INT_FSTAT -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_INT_FSTAT "TNS_TDMA_INT_FSTAT"


/**
 * NCB - tns_tdma_int_stat_w1c
 *
 * TDMA Interrupt Status Register.
 *
 */
typedef union bdk_tns_tdma_int_stat_w1c {
	uint64_t u;
	struct bdk_tns_tdma_int_stat_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_23_63              : 41;
		uint64_t vmem_dbe                    : 1;  /**< R/W1C/H - Double-bit ECC error detected on MSIX VMEM RAM. */
		uint64_t nici_dbe                    : 2;  /**< R/W1C/H - Double-bit ECC error detected on NICI[1..0] RAM. */
		uint64_t lmac_dbe                    : 8;  /**< R/W1C/H - Double-bit ECC error detected on LMAC[7..0] RAM. */
		uint64_t reserved_11_11              : 1;
		uint64_t vmem_sbe                    : 1;  /**< R/W1C/H - Single-bit ECC error detected on MSIX VMEM RAM. */
		uint64_t nici_sbe                    : 2;  /**< R/W1C/H - Single-bit ECC error detected on NICI[1..0] RAM. */
		uint64_t lmac_sbe                    : 8;  /**< R/W1C/H - Single-bit ECC error detected on LMAC[7..0] RAM. */
#else
		uint64_t lmac_sbe                    : 8;
		uint64_t nici_sbe                    : 2;
		uint64_t vmem_sbe                    : 1;
		uint64_t reserved_11_11              : 1;
		uint64_t lmac_dbe                    : 8;
		uint64_t nici_dbe                    : 2;
		uint64_t vmem_dbe                    : 1;
		uint64_t reserved_23_63              : 41;
#endif
	} s;
	/* struct bdk_tns_tdma_int_stat_w1c_s cn85xx; */
	/* struct bdk_tns_tdma_int_stat_w1c_s cn88xx; */
} bdk_tns_tdma_int_stat_w1c_t;

#define BDK_TNS_TDMA_INT_STAT_W1C BDK_TNS_TDMA_INT_STAT_W1C_FUNC()
static inline uint64_t BDK_TNS_TDMA_INT_STAT_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_INT_STAT_W1C_FUNC(void)
{
	return 0x0000842000000110ull;
}
#define typedef_BDK_TNS_TDMA_INT_STAT_W1C bdk_tns_tdma_int_stat_w1c_t
#define bustype_BDK_TNS_TDMA_INT_STAT_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_INT_STAT_W1C 0
#define arguments_BDK_TNS_TDMA_INT_STAT_W1C -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_INT_STAT_W1C "TNS_TDMA_INT_STAT_W1C"


/**
 * NCB - tns_tdma_int_stat_w1s
 *
 * TDMA Interrupt Status Register.
 *
 */
typedef union bdk_tns_tdma_int_stat_w1s {
	uint64_t u;
	struct bdk_tns_tdma_int_stat_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_23_63              : 41;
		uint64_t vmem_dbe                    : 1;  /**< R/W1S/H - Double-bit ECC error detected on MSIX VMEM RAM. */
		uint64_t nici_dbe                    : 2;  /**< R/W1S/H - Double-bit ECC error detected on NICI[1..0] RAM. */
		uint64_t lmac_dbe                    : 8;  /**< R/W1S/H - Double-bit ECC error detected on LMAC[7..0] RAM. */
		uint64_t reserved_11_11              : 1;
		uint64_t vmem_sbe                    : 1;  /**< R/W1S/H - Single-bit ECC error detected on MSIX VMEM RAM. */
		uint64_t nici_sbe                    : 2;  /**< R/W1S/H - Single-bit ECC error detected on NICI[1..0] RAM. */
		uint64_t lmac_sbe                    : 8;  /**< R/W1S/H - Single-bit ECC error detected on LMAC[7..0] RAM. */
#else
		uint64_t lmac_sbe                    : 8;
		uint64_t nici_sbe                    : 2;
		uint64_t vmem_sbe                    : 1;
		uint64_t reserved_11_11              : 1;
		uint64_t lmac_dbe                    : 8;
		uint64_t nici_dbe                    : 2;
		uint64_t vmem_dbe                    : 1;
		uint64_t reserved_23_63              : 41;
#endif
	} s;
	/* struct bdk_tns_tdma_int_stat_w1s_s cn85xx; */
	/* struct bdk_tns_tdma_int_stat_w1s_s cn88xx; */
} bdk_tns_tdma_int_stat_w1s_t;

#define BDK_TNS_TDMA_INT_STAT_W1S BDK_TNS_TDMA_INT_STAT_W1S_FUNC()
static inline uint64_t BDK_TNS_TDMA_INT_STAT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_INT_STAT_W1S_FUNC(void)
{
	return 0x0000842000000100ull;
}
#define typedef_BDK_TNS_TDMA_INT_STAT_W1S bdk_tns_tdma_int_stat_w1s_t
#define bustype_BDK_TNS_TDMA_INT_STAT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_INT_STAT_W1S 0
#define arguments_BDK_TNS_TDMA_INT_STAT_W1S -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_INT_STAT_W1S "TNS_TDMA_INT_STAT_W1S"


/**
 * NCB - tns_tdma_lmac#_config
 *
 * This register provides control of TDMA functionality.
 *
 */
typedef union bdk_tns_tdma_lmacx_config {
	uint64_t u;
	struct bdk_tns_tdma_lmacx_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t fifo_cdts                   : 14; /**< R/W - Initial credits available for sending data to the LMAC.
                                                                 Each credit represents 1 16-byte flit towards the LMAC.
                                                                 This field must be configured to be less than or equal to the configured FIFO
                                                                 size of the destination LMAC.
                                                                 Software may not change this field while packets are flowing towards the LMAC. */
#else
		uint64_t fifo_cdts                   : 14;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_tns_tdma_lmacx_config_s cn85xx; */
	/* struct bdk_tns_tdma_lmacx_config_s cn88xx; */
} bdk_tns_tdma_lmacx_config_t;

static inline uint64_t BDK_TNS_TDMA_LMACX_CONFIG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_LMACX_CONFIG(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000842000000300ull + (param1 & 7) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_LMACX_CONFIG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_LMACX_CONFIG(...) bdk_tns_tdma_lmacx_config_t
#define bustype_BDK_TNS_TDMA_LMACX_CONFIG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_LMACX_CONFIG(p1) (p1)
#define arguments_BDK_TNS_TDMA_LMACX_CONFIG(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_LMACX_CONFIG(...) "TNS_TDMA_LMACX_CONFIG"


/**
 * NCB - tns_tdma_nb_config1
 *
 * General configuration register.
 *
 */
typedef union bdk_tns_tdma_nb_config1 {
	uint64_t u;
	struct bdk_tns_tdma_nb_config1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t master_en                   : 1;  /**< R/W/H - Allows FPM entries to be utilized for storing data to the packet memory.
                                                                 Usage of hardware AUTO_INIT will clear this field. */
		uint64_t drain_pkts                  : 11; /**< R/W - Discard all packets scheduled by the TxQ towards a physical port.
                                                                 Rather than transmit a packet on its physical port the TDMA will drop the packet.
                                                                 The bit positions correspond to the enumeration as defined in TNS_PHYS_PORT_E. */
		uint64_t auto_init                   : 1;  /**< R/W/H - Initiate hardware auto-initialization of TNS.
                                                                 To begin initialization, software writes a 1 to this field.
                                                                 Upon completion of auto-initialization, hardware will clear this field
                                                                 and will also set TNS_TDMA_NB_STATUS[INIT_DONE].
                                                                 INTERNAL:
                                                                 Fills TDMA FPM to desired depth.
                                                                 Clears TDMA PRC counters to 0x0. */
		uint64_t reserved_50_50              : 1;
		uint64_t pm_depth                    : 2;  /**< R/W - Set the usable size of the Packet Memory.
                                                                 0x0 = Use full packet memory.
                                                                 0x1 = Use 1/2 packet memory.
                                                                 0x2 = Use 1/4 packet memory.
                                                                 0x3 = Use 1/8 packet memory.
                                                                 AUTO_INIT must be performed after changing this field.
                                                                 INTERNAL:
                                                                 TNS has a 3MB packet memory.
                                                                 0x0 = 3MB.
                                                                 0x1 = 1.5MB.
                                                                 0x2 = 768kB.
                                                                 0x3 = 384kB. */
		uint64_t reserved_46_47              : 2;
		uint64_t nici1_pknd                  : 6;  /**< R/W - Port kind for packets destined to NICI1. */
		uint64_t reserved_38_39              : 2;
		uint64_t nici0_pknd                  : 6;  /**< R/W - Port kind for packets destined to NICI0. */
		uint64_t txq_qmap_link_up            : 16; /**< R/W - Advertise to the TxQ's QMAP logic that a physical port link is available to
                                                                 transmit packets.
                                                                 The bit positions correspond to the enumeration as defined in TNS_PHYS_PORT_E.
                                                                 Bit positions not enumerated are undefined.
                                                                 When changing the value in this field, software must also at the same time
                                                                 set TXQ_EQ_LINK_UP to match the value being written here. */
		uint64_t txq_eq_link_up              : 16; /**< R/W - Advertise to the TxQ's enqueue logic that a physical port link is available to
                                                                 transmit packets.
                                                                 The bit positions correspond to the enumeration as defined in TNS_PHYS_PORT_E.
                                                                 Bit positions not enumerated are undefined.
                                                                 When changing the value in this field, software must also at the same time
                                                                 set TXQ_QMAP_LINK_UP to match the value being written here. */
#else
		uint64_t txq_eq_link_up              : 16;
		uint64_t txq_qmap_link_up            : 16;
		uint64_t nici0_pknd                  : 6;
		uint64_t reserved_38_39              : 2;
		uint64_t nici1_pknd                  : 6;
		uint64_t reserved_46_47              : 2;
		uint64_t pm_depth                    : 2;
		uint64_t reserved_50_50              : 1;
		uint64_t auto_init                   : 1;
		uint64_t drain_pkts                  : 11;
		uint64_t master_en                   : 1;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_config1_s   cn85xx; */
	/* struct bdk_tns_tdma_nb_config1_s   cn88xx; */
} bdk_tns_tdma_nb_config1_t;

#define BDK_TNS_TDMA_NB_CONFIG1 BDK_TNS_TDMA_NB_CONFIG1_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_CONFIG1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_CONFIG1_FUNC(void)
{
	return 0x0000842041000200ull;
}
#define typedef_BDK_TNS_TDMA_NB_CONFIG1 bdk_tns_tdma_nb_config1_t
#define bustype_BDK_TNS_TDMA_NB_CONFIG1 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_CONFIG1 0
#define arguments_BDK_TNS_TDMA_NB_CONFIG1 -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_CONFIG1 "TNS_TDMA_NB_CONFIG1"


/**
 * NCB - tns_tdma_nb_config2
 *
 * General configuration register.
 *
 */
typedef union bdk_tns_tdma_nb_config2 {
	uint64_t u;
	struct bdk_tns_tdma_nb_config2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t sst_req_inc                 : 1;  /**< R/W - Designated value of the INC field within a SST read or write request. */
		uint64_t reserved_62_62              : 1;
		uint64_t sst_endian                  : 2;  /**< R/W - Select swapping of CSR data when accessing the SST blocks.
                                                                 0x0 = ABCDEFGH (no swap)
                                                                 0x1 = EFGHABCD (swap 32-bit chunk within 64-bit word)
                                                                 0x2 = DCBAHGFE (swap bytes within 32-bit chunk)
                                                                 0x3 = HGFEDCBA (swap 32-bit chunks within 64-bit word and swap bytes within chunk) */
		uint64_t reserved_0_59               : 60;
#else
		uint64_t reserved_0_59               : 60;
		uint64_t sst_endian                  : 2;
		uint64_t reserved_62_62              : 1;
		uint64_t sst_req_inc                 : 1;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_config2_s   cn85xx; */
	/* struct bdk_tns_tdma_nb_config2_s   cn88xx; */
} bdk_tns_tdma_nb_config2_t;

#define BDK_TNS_TDMA_NB_CONFIG2 BDK_TNS_TDMA_NB_CONFIG2_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_CONFIG2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_CONFIG2_FUNC(void)
{
	return 0x0000842041000210ull;
}
#define typedef_BDK_TNS_TDMA_NB_CONFIG2 bdk_tns_tdma_nb_config2_t
#define bustype_BDK_TNS_TDMA_NB_CONFIG2 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_CONFIG2 0
#define arguments_BDK_TNS_TDMA_NB_CONFIG2 -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_CONFIG2 "TNS_TDMA_NB_CONFIG2"


/**
 * NCB - tns_tdma_nb_dbg_config1
 *
 * This register provides debug control of TDMA functionality.
 *
 */
typedef union bdk_tns_tdma_nb_dbg_config1 {
	uint64_t u;
	struct bdk_tns_tdma_nb_dbg_config1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_43_63              : 21;
		uint64_t lb_cutthru_en               : 1;  /**< R/W - Enable cut-thru packet transmission on the internal loopback bus. */
		uint64_t lmac_cutthru_en             : 1;  /**< R/W - Enable cut-thru packet transmission towards the LMAC ports. */
		uint64_t nic_cutthru_en              : 1;  /**< R/W - Enable cut-thru packet transmission towards the NIC. */
		uint64_t reserved_37_39              : 3;
		uint64_t lb_init_cdts                : 5;  /**< R/W - The flow of data from the TDMA to the RDMA along the internal loopback path is
                                                                 metered by credits.
                                                                 Each credit represents the transfer of a 32-byte flit.
                                                                 A maximum of 16 (decimal) credits is allowed.
                                                                 A minimum of 2 credits is required for proper operation. */
		uint64_t reserved_29_31              : 3;
		uint64_t txq_drop_req_thresh         : 5;  /**< R/W - Requests to drop packets are received from the TxQ.
                                                                 Arriving requests can take one of two paths:
                                                                 _ 1) If the packet is a single-copy packet, the packet is pushed to a 16-entry FIFO
                                                                 _    in the Link List walker logic.
                                                                 _ 2) If the packet is a multiple-copy packet the packet is pushed to a 16-entry FIFO
                                                                 _    in the Page Reference Count logic.
                                                                 If the occupancy of either of these FIFOs reaches the value programmed in this field
                                                                 the data path will assert flow control to the TxQ to prevent additional drop messages
                                                                 from arriving. */
		uint64_t reserved_21_23              : 3;
		uint64_t p2x_tkn_sch_thresh          : 5;  /**< R/W - Each of the 8 BGX ports has a FIFO for receiving tokens from the port's per-priority
                                                                 Token FIFOs.
                                                                 Each FIFO can store 8 tokens.
                                                                 This value indicates the number of tokens at which the FIFO will stop pulling tokens
                                                                 from the port's per-priority Token FIFOs. */
		uint64_t reserved_13_15              : 3;
		uint64_t lb_tkn_sch_thresh           : 5;  /**< R/W - The internal loopback path has a FIFO for receiving tokens from the TxQ block.
                                                                 The FIFO can store 8 tokens.
                                                                 This value indicates the number of tokens at which the port available signal to
                                                                 the TxQ is to be de-asserted.
                                                                 The value includes tokens in the FIFO as well as the in-flight tokens
                                                                 (schedule received but token not yet received). */
		uint64_t reserved_5_7                : 3;
		uint64_t x2p_tkn_sch_thresh          : 5;  /**< R/W - Both NIC Interfaces have a FIFO for receiving tokens from the TxQ block.
                                                                 Each FIFO can store 8 tokens.
                                                                 This value indicates the number of tokens at which the port available signal to
                                                                 the TxQ is to be de-asserted.
                                                                 The value includes tokens in the FIFO as well as the in-flight tokens
                                                                 (schedule received but token not yet received). */
#else
		uint64_t x2p_tkn_sch_thresh          : 5;
		uint64_t reserved_5_7                : 3;
		uint64_t lb_tkn_sch_thresh           : 5;
		uint64_t reserved_13_15              : 3;
		uint64_t p2x_tkn_sch_thresh          : 5;
		uint64_t reserved_21_23              : 3;
		uint64_t txq_drop_req_thresh         : 5;
		uint64_t reserved_29_31              : 3;
		uint64_t lb_init_cdts                : 5;
		uint64_t reserved_37_39              : 3;
		uint64_t nic_cutthru_en              : 1;
		uint64_t lmac_cutthru_en             : 1;
		uint64_t lb_cutthru_en               : 1;
		uint64_t reserved_43_63              : 21;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_dbg_config1_s cn85xx; */
	/* struct bdk_tns_tdma_nb_dbg_config1_s cn88xx; */
} bdk_tns_tdma_nb_dbg_config1_t;

#define BDK_TNS_TDMA_NB_DBG_CONFIG1 BDK_TNS_TDMA_NB_DBG_CONFIG1_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_DBG_CONFIG1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_DBG_CONFIG1_FUNC(void)
{
	return 0x0000842041000C00ull;
}
#define typedef_BDK_TNS_TDMA_NB_DBG_CONFIG1 bdk_tns_tdma_nb_dbg_config1_t
#define bustype_BDK_TNS_TDMA_NB_DBG_CONFIG1 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_DBG_CONFIG1 0
#define arguments_BDK_TNS_TDMA_NB_DBG_CONFIG1 -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_DBG_CONFIG1 "TNS_TDMA_NB_DBG_CONFIG1"


/**
 * NCB - tns_tdma_nb_dbg_config2
 *
 * This register provides debug control of TDMA functionality.
 *
 */
typedef union bdk_tns_tdma_nb_dbg_config2 {
	uint64_t u;
	struct bdk_tns_tdma_nb_dbg_config2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t sst_retry_count             : 20; /**< R/W - Read and write requests to the SDE, SE, and TxQ sub-blocks may sometimes timeout due
                                                                 to hardware having priority over software access.
                                                                 The datapath will attempt to retry a timed out request the number of times specified in
                                                                 this field before eventually timing out and setting an error status bit. */
#else
		uint64_t sst_retry_count             : 20;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_dbg_config2_s cn85xx; */
	/* struct bdk_tns_tdma_nb_dbg_config2_s cn88xx; */
} bdk_tns_tdma_nb_dbg_config2_t;

#define BDK_TNS_TDMA_NB_DBG_CONFIG2 BDK_TNS_TDMA_NB_DBG_CONFIG2_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_DBG_CONFIG2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_DBG_CONFIG2_FUNC(void)
{
	return 0x0000842041000C10ull;
}
#define typedef_BDK_TNS_TDMA_NB_DBG_CONFIG2 bdk_tns_tdma_nb_dbg_config2_t
#define bustype_BDK_TNS_TDMA_NB_DBG_CONFIG2 BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_DBG_CONFIG2 0
#define arguments_BDK_TNS_TDMA_NB_DBG_CONFIG2 -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_DBG_CONFIG2 "TNS_TDMA_NB_DBG_CONFIG2"


/**
 * NCB - tns_tdma_nb_dbg_cx_full
 *
 * This register provides debug control of FIFO full.
 * Async FIFOs assert an early full indication when occupancies reach the values
 * below.
 */
typedef union bdk_tns_tdma_nb_dbg_cx_full {
	uint64_t u;
	struct bdk_tns_tdma_nb_dbg_cx_full_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t lmac_pkt                    : 5;  /**< R/W - Packets sent to LMACs. */
		uint64_t reserved_5_7                : 3;
		uint64_t nic_pkt                     : 5;  /**< R/W - Packets sent to NIC. */
#else
		uint64_t nic_pkt                     : 5;
		uint64_t reserved_5_7                : 3;
		uint64_t lmac_pkt                    : 5;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_dbg_cx_full_s cn85xx; */
	/* struct bdk_tns_tdma_nb_dbg_cx_full_s cn88xx; */
} bdk_tns_tdma_nb_dbg_cx_full_t;

#define BDK_TNS_TDMA_NB_DBG_CX_FULL BDK_TNS_TDMA_NB_DBG_CX_FULL_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_DBG_CX_FULL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_DBG_CX_FULL_FUNC(void)
{
	return 0x0000842041000C40ull;
}
#define typedef_BDK_TNS_TDMA_NB_DBG_CX_FULL bdk_tns_tdma_nb_dbg_cx_full_t
#define bustype_BDK_TNS_TDMA_NB_DBG_CX_FULL BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_DBG_CX_FULL 0
#define arguments_BDK_TNS_TDMA_NB_DBG_CX_FULL -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_DBG_CX_FULL "TNS_TDMA_NB_DBG_CX_FULL"


/**
 * NCB - tns_tdma_nb_dbg_cx_occ
 *
 * Async FIFO occupancies.
 *
 */
typedef union bdk_tns_tdma_nb_dbg_cx_occ {
	uint64_t u;
	struct bdk_tns_tdma_nb_dbg_cx_occ_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t lmac_pkt                    : 5;  /**< RO/H - Data sending to LMACs. */
		uint64_t reserved_5_7                : 3;
		uint64_t nic_pkt                     : 5;  /**< RO/H - Data sending to NIC. */
#else
		uint64_t nic_pkt                     : 5;
		uint64_t reserved_5_7                : 3;
		uint64_t lmac_pkt                    : 5;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_dbg_cx_occ_s cn85xx; */
	/* struct bdk_tns_tdma_nb_dbg_cx_occ_s cn88xx; */
} bdk_tns_tdma_nb_dbg_cx_occ_t;

#define BDK_TNS_TDMA_NB_DBG_CX_OCC BDK_TNS_TDMA_NB_DBG_CX_OCC_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_DBG_CX_OCC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_DBG_CX_OCC_FUNC(void)
{
	return 0x0000842041000C50ull;
}
#define typedef_BDK_TNS_TDMA_NB_DBG_CX_OCC bdk_tns_tdma_nb_dbg_cx_occ_t
#define bustype_BDK_TNS_TDMA_NB_DBG_CX_OCC BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_DBG_CX_OCC 0
#define arguments_BDK_TNS_TDMA_NB_DBG_CX_OCC -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_DBG_CX_OCC "TNS_TDMA_NB_DBG_CX_OCC"


/**
 * NCB - tns_tdma_nb_dbg_lmac#_config1
 *
 * This register provides debug control of TDMA functionality.
 * Each LMAC path has 16 FIFOs for receiving tokens from the TxQ block
 * on a per-priority basis.
 * Each LMAC priority FIFO can store 8 tokens.
 * This value indicates the number of tokens at which point EBP XOFF for the priority
 * will be asserted to the TxQ.
 * The value includes tokens in the FIFO as well as the in-flight tokens
 * (schedule received but token not yet received).
 */
typedef union bdk_tns_tdma_nb_dbg_lmacx_config1 {
	uint64_t u;
	struct bdk_tns_tdma_nb_dbg_lmacx_config1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t tkn_sch_thresh              : 5;  /**< R/W - Token threshold for LMAC.
                                                                 A value larger than 8 will be interpreted as 8.
                                                                 A value of 0 will assert XOFF for all priorities of the LMAC. */
#else
		uint64_t tkn_sch_thresh              : 5;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_dbg_lmacx_config1_s cn85xx; */
	/* struct bdk_tns_tdma_nb_dbg_lmacx_config1_s cn88xx; */
} bdk_tns_tdma_nb_dbg_lmacx_config1_t;

static inline uint64_t BDK_TNS_TDMA_NB_DBG_LMACX_CONFIG1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_DBG_LMACX_CONFIG1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000842041000C80ull + (param1 & 7) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_NB_DBG_LMACX_CONFIG1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_NB_DBG_LMACX_CONFIG1(...) bdk_tns_tdma_nb_dbg_lmacx_config1_t
#define bustype_BDK_TNS_TDMA_NB_DBG_LMACX_CONFIG1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_DBG_LMACX_CONFIG1(p1) (p1)
#define arguments_BDK_TNS_TDMA_NB_DBG_LMACX_CONFIG1(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_DBG_LMACX_CONFIG1(...) "TNS_TDMA_NB_DBG_LMACX_CONFIG1"


/**
 * NCB - tns_tdma_nb_ecc_ctl
 *
 * This register can be used to disable ECC checks, insert ECC errors.
 * Fields *ECC_DIS disable SBE detection/correction and DBE detection. If ECC_DIS is 0x1, then no
 * errors are detected.
 * Fields *ECC_FLIP_SYND flip the syndrome<1:0> bits to generate 1-bit/2-bit error for testing.
 * * 0x0 = normal operation
 * * 0x1 = SBE on bit<0>
 * * 0x2 = SBE on bit<1>
 * * 0x3 = DBE on bits<1:0>
 */
typedef union bdk_tns_tdma_nb_ecc_ctl {
	uint64_t u;
	struct bdk_tns_tdma_nb_ecc_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t pm_ecc_dis                  : 1;  /**< R/W - Disable ECC for PM RAM. */
		uint64_t prc_ecc_dis                 : 1;  /**< R/W - Disable ECC for PRC RAM. */
		uint64_t ll_ecc_dis                  : 1;  /**< R/W - Disable ECC for LL RAM. */
		uint64_t fpm_ecc_dis                 : 1;  /**< R/W - Disable ECC for FPM RAM. */
		uint64_t pkt_lb_ecc_dis              : 1;  /**< R/W - Disable ECC for PKT_LB RAM. */
		uint64_t pkt_x2p_ecc_dis             : 1;  /**< R/W - Disable ECC for PKT_X2P RAM. */
		uint64_t pkt_p2x_data_ecc_dis        : 1;  /**< R/W - Disable ECC for PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_ecc_dis         : 1;  /**< R/W - Disable ECC for PKT_P2X_TKN RAM. */
		uint64_t reserved_14_31              : 18;
		uint64_t prc_ecc_flip_synd           : 2;  /**< R/W - Flip syndrome for all data written to PRC RAM. */
		uint64_t ll_ecc_flip_synd            : 2;  /**< R/W - Flip syndrome for all data written to LL RAM. */
		uint64_t fpm_ecc_flip_synd           : 2;  /**< R/W - Flip syndrome for all data written to FPM RAM. */
		uint64_t pkt_lb_ecc_flip_synd        : 2;  /**< R/W - Flip syndrome for all data written to PKT_LB RAM. */
		uint64_t pkt_x2p_ecc_flip_synd       : 2;  /**< R/W - Flip syndrome for all data written to PKT_X2P RAM. */
		uint64_t pkt_p2x_data_ecc_flip_synd  : 2;  /**< R/W - Flip syndrome for all data written to PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_ecc_flip_synd   : 2;  /**< R/W - Flip syndrome for all data written to PKT_P2X_TKN RAM. */
#else
		uint64_t pkt_p2x_tkn_ecc_flip_synd   : 2;
		uint64_t pkt_p2x_data_ecc_flip_synd  : 2;
		uint64_t pkt_x2p_ecc_flip_synd       : 2;
		uint64_t pkt_lb_ecc_flip_synd        : 2;
		uint64_t fpm_ecc_flip_synd           : 2;
		uint64_t ll_ecc_flip_synd            : 2;
		uint64_t prc_ecc_flip_synd           : 2;
		uint64_t reserved_14_31              : 18;
		uint64_t pkt_p2x_tkn_ecc_dis         : 1;
		uint64_t pkt_p2x_data_ecc_dis        : 1;
		uint64_t pkt_x2p_ecc_dis             : 1;
		uint64_t pkt_lb_ecc_dis              : 1;
		uint64_t fpm_ecc_dis                 : 1;
		uint64_t ll_ecc_dis                  : 1;
		uint64_t prc_ecc_dis                 : 1;
		uint64_t pm_ecc_dis                  : 1;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_ecc_ctl_s   cn85xx; */
	/* struct bdk_tns_tdma_nb_ecc_ctl_s   cn88xx; */
} bdk_tns_tdma_nb_ecc_ctl_t;

#define BDK_TNS_TDMA_NB_ECC_CTL BDK_TNS_TDMA_NB_ECC_CTL_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_ECC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_ECC_CTL_FUNC(void)
{
	return 0x0000842041000800ull;
}
#define typedef_BDK_TNS_TDMA_NB_ECC_CTL bdk_tns_tdma_nb_ecc_ctl_t
#define bustype_BDK_TNS_TDMA_NB_ECC_CTL BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_ECC_CTL 0
#define arguments_BDK_TNS_TDMA_NB_ECC_CTL -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_ECC_CTL "TNS_TDMA_NB_ECC_CTL"


/**
 * NCB - tns_tdma_nb_ecc_err_stat
 *
 * This register logs information to help debug ECC errors.
 *
 */
typedef union bdk_tns_tdma_nb_ecc_err_stat {
	uint64_t u;
	struct bdk_tns_tdma_nb_ecc_err_stat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_27_63              : 37;
		uint64_t syndrome                    : 11; /**< RO/H - Error syndrome. */
		uint64_t address                     : 16; /**< RO/H - Address of ECC error. */
#else
		uint64_t address                     : 16;
		uint64_t syndrome                    : 11;
		uint64_t reserved_27_63              : 37;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_ecc_err_stat_s cn85xx; */
	/* struct bdk_tns_tdma_nb_ecc_err_stat_s cn88xx; */
} bdk_tns_tdma_nb_ecc_err_stat_t;

#define BDK_TNS_TDMA_NB_ECC_ERR_STAT BDK_TNS_TDMA_NB_ECC_ERR_STAT_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_ECC_ERR_STAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_ECC_ERR_STAT_FUNC(void)
{
	return 0x0000842041000810ull;
}
#define typedef_BDK_TNS_TDMA_NB_ECC_ERR_STAT bdk_tns_tdma_nb_ecc_err_stat_t
#define bustype_BDK_TNS_TDMA_NB_ECC_ERR_STAT BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_ECC_ERR_STAT 0
#define arguments_BDK_TNS_TDMA_NB_ECC_ERR_STAT -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_ECC_ERR_STAT "TNS_TDMA_NB_ECC_ERR_STAT"


/**
 * NCB - tns_tdma_nb_eco
 *
 * ECO register.
 *
 */
typedef union bdk_tns_tdma_nb_eco {
	uint64_t u;
	struct bdk_tns_tdma_nb_eco_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t rst1                        : 8;  /**< R/W - Reset to 1 spare bits */
		uint64_t rst0                        : 8;  /**< R/W - Reset to 0 spare bits */
#else
		uint64_t rst0                        : 8;
		uint64_t rst1                        : 8;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_eco_s       cn85xx; */
	/* struct bdk_tns_tdma_nb_eco_s       cn88xx; */
} bdk_tns_tdma_nb_eco_t;

#define BDK_TNS_TDMA_NB_ECO BDK_TNS_TDMA_NB_ECO_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_ECO_FUNC(void)
{
	return 0x0000842041002000ull;
}
#define typedef_BDK_TNS_TDMA_NB_ECO bdk_tns_tdma_nb_eco_t
#define bustype_BDK_TNS_TDMA_NB_ECO BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_ECO 0
#define arguments_BDK_TNS_TDMA_NB_ECO -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_ECO "TNS_TDMA_NB_ECO"


/**
 * NCB - tns_tdma_nb_fpm_acc#
 *
 * Provides the ability for software to access the TDMA Free Page Manager FIFO memory.
 * The FPM consists of 1536 120-bit words.
 * Each 120-bit word stores 8 14-bit page pointers.
 *
 * To write data to a piece of a memory word software must write the entire word, 8 bytes at a
 * time,
 * starting with the least significant bits at 0x...00 and incrementing sequentially up
 * to 0x...10.
 */
typedef union bdk_tns_tdma_nb_fpm_accx {
	uint64_t u;
	struct bdk_tns_tdma_nb_fpm_accx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W/H - Data. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_fpm_accx_s  cn85xx; */
	/* struct bdk_tns_tdma_nb_fpm_accx_s  cn88xx; */
} bdk_tns_tdma_nb_fpm_accx_t;

static inline uint64_t BDK_TNS_TDMA_NB_FPM_ACCX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_FPM_ACCX(unsigned long param1)
{
	if (((param1 <= 3071)))
		return 0x0000842041010000ull + (param1 & 4095) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_NB_FPM_ACCX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_NB_FPM_ACCX(...) bdk_tns_tdma_nb_fpm_accx_t
#define bustype_BDK_TNS_TDMA_NB_FPM_ACCX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_FPM_ACCX(p1) (p1)
#define arguments_BDK_TNS_TDMA_NB_FPM_ACCX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_FPM_ACCX(...) "TNS_TDMA_NB_FPM_ACCX"


/**
 * NCB - tns_tdma_nb_fpm_mod
 *
 * Allows software to pop or push a bundle of 8 page pointers from/to the TDMA Free Page
 * Manager FIFO memory.
 * Software may only set the POP or PUSH fields during initialization, before setting
 * TNS_TDMA_NB_CONFIG[MASTER_EN].
 * If performing a PUSH, software must guarantee that all pages in the bundle at the FPM
 * address indicated by the write pointer do not already exist in the FPM.
 */
typedef union bdk_tns_tdma_nb_fpm_mod {
	uint64_t u;
	struct bdk_tns_tdma_nb_fpm_mod_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pop                         : 1;  /**< WO/H - Pop a bundle of 8 page pointers from the FPM FIFO and discard the pointers.
                                                                 Increments TNS_TDMA_NB_FPM_STATUS[RPTR].
                                                                 Hardware guards against popping from an empty FIFO.
                                                                 Hardware will clear this field to 0x0 upon a successful bundle discard. */
		uint64_t push                        : 1;  /**< WO/H - Push a bundle of 8 page pointers to the FPM FIFO by including the data located at
                                                                 TNS_TDMA_NB_FPM_STATUS[WPTR].
                                                                 Increments TNS_TDMA_NB_FPM_STATUS[WPTR].
                                                                 Hardware guards against pushing to a full FIFO.
                                                                 Hardware will clear this field to 0x0 upon a successful bundle discard. */
		uint64_t reserved_0_61               : 62;
#else
		uint64_t reserved_0_61               : 62;
		uint64_t push                        : 1;
		uint64_t pop                         : 1;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_fpm_mod_s   cn85xx; */
	/* struct bdk_tns_tdma_nb_fpm_mod_s   cn88xx; */
} bdk_tns_tdma_nb_fpm_mod_t;

#define BDK_TNS_TDMA_NB_FPM_MOD BDK_TNS_TDMA_NB_FPM_MOD_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_FPM_MOD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_FPM_MOD_FUNC(void)
{
	return 0x0000842041001010ull;
}
#define typedef_BDK_TNS_TDMA_NB_FPM_MOD bdk_tns_tdma_nb_fpm_mod_t
#define bustype_BDK_TNS_TDMA_NB_FPM_MOD BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_FPM_MOD 0
#define arguments_BDK_TNS_TDMA_NB_FPM_MOD -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_FPM_MOD "TNS_TDMA_NB_FPM_MOD"


/**
 * NCB - tns_tdma_nb_fpm_status
 */
typedef union bdk_tns_tdma_nb_fpm_status {
	uint64_t u;
	struct bdk_tns_tdma_nb_fpm_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_35_63              : 29;
		uint64_t rptr                        : 11; /**< RO/H - FPM FIFO read pointer. */
		uint64_t reserved_23_23              : 1;
		uint64_t wptr                        : 11; /**< RO/H - FPM FIFO write pointer. */
		uint64_t reserved_11_11              : 1;
		uint64_t occ                         : 11; /**< RO/H - FPM FIFO bundle occupancy.
                                                                 Indicates the number of 8-page pointer bundles in the FPM FIFO. */
#else
		uint64_t occ                         : 11;
		uint64_t reserved_11_11              : 1;
		uint64_t wptr                        : 11;
		uint64_t reserved_23_23              : 1;
		uint64_t rptr                        : 11;
		uint64_t reserved_35_63              : 29;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_fpm_status_s cn85xx; */
	/* struct bdk_tns_tdma_nb_fpm_status_s cn88xx; */
} bdk_tns_tdma_nb_fpm_status_t;

#define BDK_TNS_TDMA_NB_FPM_STATUS BDK_TNS_TDMA_NB_FPM_STATUS_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_FPM_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_FPM_STATUS_FUNC(void)
{
	return 0x0000842041001000ull;
}
#define typedef_BDK_TNS_TDMA_NB_FPM_STATUS bdk_tns_tdma_nb_fpm_status_t
#define bustype_BDK_TNS_TDMA_NB_FPM_STATUS BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_FPM_STATUS 0
#define arguments_BDK_TNS_TDMA_NB_FPM_STATUS -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_FPM_STATUS "TNS_TDMA_NB_FPM_STATUS"


/**
 * NCB - tns_tdma_nb_int_en_w1c
 *
 * TDMA Interrupt Enable Register.
 *
 */
typedef union bdk_tns_tdma_nb_int_en_w1c {
	uint64_t u;
	struct bdk_tns_tdma_nb_int_en_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t sst_seq_err                 : 1;  /**< R/W1C/H - A CSR request to the SST blocks experienced a fatal protocol sequence error. */
		uint64_t sst_req_timeout             : 1;  /**< R/W1C/H - A CSR request to the SST blocks timed out. */
		uint64_t sst_addr_err                : 1;  /**< R/W1C/H - A CSR request to the SST blocks was directed to an invalid address. */
		uint64_t prc_urw_zero                : 1;  /**< R/W1C/H - A PRC counter was inappropriately decremented to zero by the URW. */
		uint64_t prc_rollunder               : 1;  /**< R/W1C/H - A PRC counter rolled under. */
		uint64_t prc_rollover                : 1;  /**< R/W1C/H - A PRC counter rolled over. */
		uint64_t pm_dbe                      : 1;  /**< R/W1C/H - Double-bit ECC error detected on PM RAM. */
		uint64_t prc_dbe                     : 1;  /**< R/W1C/H - Double-bit ECC error detected on PRC RAM. */
		uint64_t ll_dbe                      : 1;  /**< R/W1C/H - Double-bit ECC error detected on LL RAM. */
		uint64_t fpm_dbe                     : 1;  /**< R/W1C/H - Double-bit ECC error detected on FPM RAM. */
		uint64_t pkt_lb_dbe                  : 1;  /**< R/W1C/H - Double-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_x2p_dbe                 : 1;  /**< R/W1C/H - Double-bit ECC error detected on PKT_X2P RAM. */
		uint64_t pkt_p2x_data_dbe            : 1;  /**< R/W1C/H - Double-bit ECC error detected on PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_dbe             : 1;  /**< R/W1C/H - Double-bit ECC error detected on PKT_P2X_TKN RAM. */
		uint64_t pm_sbe                      : 1;  /**< R/W1C/H - Single-bit ECC error detected on PM RAM. */
		uint64_t prc_sbe                     : 1;  /**< R/W1C/H - Single-bit ECC error detected on PRC RAM. */
		uint64_t ll_sbe                      : 1;  /**< R/W1C/H - Single-bit ECC error detected on LL RAM. */
		uint64_t fpm_sbe                     : 1;  /**< R/W1C/H - Single-bit ECC error detected on FPM RAM. */
		uint64_t pkt_lb_sbe                  : 1;  /**< R/W1C/H - Single-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_x2p_sbe                 : 1;  /**< R/W1C/H - Single-bit ECC error detected on PKT_X2P RAM. */
		uint64_t pkt_p2x_data_sbe            : 1;  /**< R/W1C/H - Single-bit ECC error detected on PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_sbe             : 1;  /**< R/W1C/H - Single-bit ECC error detected on PKT_P2X_TKN RAM. */
#else
		uint64_t pkt_p2x_tkn_sbe             : 1;
		uint64_t pkt_p2x_data_sbe            : 1;
		uint64_t pkt_x2p_sbe                 : 1;
		uint64_t pkt_lb_sbe                  : 1;
		uint64_t fpm_sbe                     : 1;
		uint64_t ll_sbe                      : 1;
		uint64_t prc_sbe                     : 1;
		uint64_t pm_sbe                      : 1;
		uint64_t pkt_p2x_tkn_dbe             : 1;
		uint64_t pkt_p2x_data_dbe            : 1;
		uint64_t pkt_x2p_dbe                 : 1;
		uint64_t pkt_lb_dbe                  : 1;
		uint64_t fpm_dbe                     : 1;
		uint64_t ll_dbe                      : 1;
		uint64_t prc_dbe                     : 1;
		uint64_t pm_dbe                      : 1;
		uint64_t prc_rollover                : 1;
		uint64_t prc_rollunder               : 1;
		uint64_t prc_urw_zero                : 1;
		uint64_t sst_addr_err                : 1;
		uint64_t sst_req_timeout             : 1;
		uint64_t sst_seq_err                 : 1;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_int_en_w1c_s cn85xx; */
	/* struct bdk_tns_tdma_nb_int_en_w1c_s cn88xx; */
} bdk_tns_tdma_nb_int_en_w1c_t;

#define BDK_TNS_TDMA_NB_INT_EN_W1C BDK_TNS_TDMA_NB_INT_EN_W1C_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_INT_EN_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_INT_EN_W1C_FUNC(void)
{
	return 0x0000842041000130ull;
}
#define typedef_BDK_TNS_TDMA_NB_INT_EN_W1C bdk_tns_tdma_nb_int_en_w1c_t
#define bustype_BDK_TNS_TDMA_NB_INT_EN_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_INT_EN_W1C 0
#define arguments_BDK_TNS_TDMA_NB_INT_EN_W1C -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_INT_EN_W1C "TNS_TDMA_NB_INT_EN_W1C"


/**
 * NCB - tns_tdma_nb_int_en_w1s
 *
 * TDMA Interrupt Enable Register.
 *
 */
typedef union bdk_tns_tdma_nb_int_en_w1s {
	uint64_t u;
	struct bdk_tns_tdma_nb_int_en_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t sst_seq_err                 : 1;  /**< R/W1S/H - A CSR request to the SST blocks experienced a fatal protocol sequence error. */
		uint64_t sst_req_timeout             : 1;  /**< R/W1S/H - A CSR request to the SST blocks timed out. */
		uint64_t sst_addr_err                : 1;  /**< R/W1S/H - A CSR request to the SST blocks was directed to an invalid address. */
		uint64_t prc_urw_zero                : 1;  /**< R/W1S/H - A PRC counter was inappropriately decremented to zero by the URW. */
		uint64_t prc_rollunder               : 1;  /**< R/W1S/H - A PRC counter rolled under. */
		uint64_t prc_rollover                : 1;  /**< R/W1S/H - A PRC counter rolled over. */
		uint64_t pm_dbe                      : 1;  /**< R/W1S/H - Double-bit ECC error detected on PM RAM. */
		uint64_t prc_dbe                     : 1;  /**< R/W1S/H - Double-bit ECC error detected on PRC RAM. */
		uint64_t ll_dbe                      : 1;  /**< R/W1S/H - Double-bit ECC error detected on LL RAM. */
		uint64_t fpm_dbe                     : 1;  /**< R/W1S/H - Double-bit ECC error detected on FPM RAM. */
		uint64_t pkt_lb_dbe                  : 1;  /**< R/W1S/H - Double-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_x2p_dbe                 : 1;  /**< R/W1S/H - Double-bit ECC error detected on PKT_X2P RAM. */
		uint64_t pkt_p2x_data_dbe            : 1;  /**< R/W1S/H - Double-bit ECC error detected on PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_dbe             : 1;  /**< R/W1S/H - Double-bit ECC error detected on PKT_P2X_TKN RAM. */
		uint64_t pm_sbe                      : 1;  /**< R/W1S/H - Single-bit ECC error detected on PM RAM. */
		uint64_t prc_sbe                     : 1;  /**< R/W1S/H - Single-bit ECC error detected on PRC RAM. */
		uint64_t ll_sbe                      : 1;  /**< R/W1S/H - Single-bit ECC error detected on LL RAM. */
		uint64_t fpm_sbe                     : 1;  /**< R/W1S/H - Single-bit ECC error detected on FPM RAM. */
		uint64_t pkt_lb_sbe                  : 1;  /**< R/W1S/H - Single-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_x2p_sbe                 : 1;  /**< R/W1S/H - Single-bit ECC error detected on PKT_X2P RAM. */
		uint64_t pkt_p2x_data_sbe            : 1;  /**< R/W1S/H - Single-bit ECC error detected on PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_sbe             : 1;  /**< R/W1S/H - Single-bit ECC error detected on PKT_P2X_TKN RAM. */
#else
		uint64_t pkt_p2x_tkn_sbe             : 1;
		uint64_t pkt_p2x_data_sbe            : 1;
		uint64_t pkt_x2p_sbe                 : 1;
		uint64_t pkt_lb_sbe                  : 1;
		uint64_t fpm_sbe                     : 1;
		uint64_t ll_sbe                      : 1;
		uint64_t prc_sbe                     : 1;
		uint64_t pm_sbe                      : 1;
		uint64_t pkt_p2x_tkn_dbe             : 1;
		uint64_t pkt_p2x_data_dbe            : 1;
		uint64_t pkt_x2p_dbe                 : 1;
		uint64_t pkt_lb_dbe                  : 1;
		uint64_t fpm_dbe                     : 1;
		uint64_t ll_dbe                      : 1;
		uint64_t prc_dbe                     : 1;
		uint64_t pm_dbe                      : 1;
		uint64_t prc_rollover                : 1;
		uint64_t prc_rollunder               : 1;
		uint64_t prc_urw_zero                : 1;
		uint64_t sst_addr_err                : 1;
		uint64_t sst_req_timeout             : 1;
		uint64_t sst_seq_err                 : 1;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_int_en_w1s_s cn85xx; */
	/* struct bdk_tns_tdma_nb_int_en_w1s_s cn88xx; */
} bdk_tns_tdma_nb_int_en_w1s_t;

#define BDK_TNS_TDMA_NB_INT_EN_W1S BDK_TNS_TDMA_NB_INT_EN_W1S_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_INT_EN_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_INT_EN_W1S_FUNC(void)
{
	return 0x0000842041000120ull;
}
#define typedef_BDK_TNS_TDMA_NB_INT_EN_W1S bdk_tns_tdma_nb_int_en_w1s_t
#define bustype_BDK_TNS_TDMA_NB_INT_EN_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_INT_EN_W1S 0
#define arguments_BDK_TNS_TDMA_NB_INT_EN_W1S -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_INT_EN_W1S "TNS_TDMA_NB_INT_EN_W1S"


/**
 * NCB - tns_tdma_nb_int_fen_w1c
 *
 * TDMA Interrupt First Enable Register.
 *
 */
typedef union bdk_tns_tdma_nb_int_fen_w1c {
	uint64_t u;
	struct bdk_tns_tdma_nb_int_fen_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t sst_seq_err                 : 1;  /**< R/W1C - A CSR request to the SST blocks experienced a fatal protocol sequence error. */
		uint64_t sst_req_timeout             : 1;  /**< R/W1C - A CSR request to the SST blocks timed out. */
		uint64_t sst_addr_err                : 1;  /**< R/W1C - A CSR request to the SST blocks was directed to an invalid address. */
		uint64_t prc_urw_zero                : 1;  /**< R/W1C - A PRC counter was inappropriately decremented to zero by the URW. */
		uint64_t prc_rollunder               : 1;  /**< R/W1C - A PRC counter rolled under. */
		uint64_t prc_rollover                : 1;  /**< R/W1C - A PRC counter rolled over. */
		uint64_t pm_dbe                      : 1;  /**< R/W1C - Double-bit ECC error detected on PM RAM. */
		uint64_t prc_dbe                     : 1;  /**< R/W1C - Double-bit ECC error detected on PRC RAM. */
		uint64_t ll_dbe                      : 1;  /**< R/W1C - Double-bit ECC error detected on LL RAM. */
		uint64_t fpm_dbe                     : 1;  /**< R/W1C - Double-bit ECC error detected on FPM RAM. */
		uint64_t pkt_lb_dbe                  : 1;  /**< R/W1C - Double-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_x2p_dbe                 : 1;  /**< R/W1C - Double-bit ECC error detected on PKT_X2P RAM. */
		uint64_t pkt_p2x_data_dbe            : 1;  /**< R/W1C - Double-bit ECC error detected on PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_dbe             : 1;  /**< R/W1C - Double-bit ECC error detected on PKT_P2X_TKN RAM. */
		uint64_t pm_sbe                      : 1;  /**< R/W1C - Single-bit ECC error detected on PM RAM. */
		uint64_t prc_sbe                     : 1;  /**< R/W1C - Single-bit ECC error detected on PRC RAM. */
		uint64_t ll_sbe                      : 1;  /**< R/W1C - Single-bit ECC error detected on LL RAM. */
		uint64_t fpm_sbe                     : 1;  /**< R/W1C - Single-bit ECC error detected on FPM RAM. */
		uint64_t pkt_lb_sbe                  : 1;  /**< R/W1C - Single-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_x2p_sbe                 : 1;  /**< R/W1C - Single-bit ECC error detected on PKT_X2P RAM. */
		uint64_t pkt_p2x_data_sbe            : 1;  /**< R/W1C - Single-bit ECC error detected on PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_sbe             : 1;  /**< R/W1C - Single-bit ECC error detected on PKT_P2X_TKN RAM. */
#else
		uint64_t pkt_p2x_tkn_sbe             : 1;
		uint64_t pkt_p2x_data_sbe            : 1;
		uint64_t pkt_x2p_sbe                 : 1;
		uint64_t pkt_lb_sbe                  : 1;
		uint64_t fpm_sbe                     : 1;
		uint64_t ll_sbe                      : 1;
		uint64_t prc_sbe                     : 1;
		uint64_t pm_sbe                      : 1;
		uint64_t pkt_p2x_tkn_dbe             : 1;
		uint64_t pkt_p2x_data_dbe            : 1;
		uint64_t pkt_x2p_dbe                 : 1;
		uint64_t pkt_lb_dbe                  : 1;
		uint64_t fpm_dbe                     : 1;
		uint64_t ll_dbe                      : 1;
		uint64_t prc_dbe                     : 1;
		uint64_t pm_dbe                      : 1;
		uint64_t prc_rollover                : 1;
		uint64_t prc_rollunder               : 1;
		uint64_t prc_urw_zero                : 1;
		uint64_t sst_addr_err                : 1;
		uint64_t sst_req_timeout             : 1;
		uint64_t sst_seq_err                 : 1;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_int_fen_w1c_s cn85xx; */
	/* struct bdk_tns_tdma_nb_int_fen_w1c_s cn88xx; */
} bdk_tns_tdma_nb_int_fen_w1c_t;

#define BDK_TNS_TDMA_NB_INT_FEN_W1C BDK_TNS_TDMA_NB_INT_FEN_W1C_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_INT_FEN_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_INT_FEN_W1C_FUNC(void)
{
	return 0x0000842041000160ull;
}
#define typedef_BDK_TNS_TDMA_NB_INT_FEN_W1C bdk_tns_tdma_nb_int_fen_w1c_t
#define bustype_BDK_TNS_TDMA_NB_INT_FEN_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_INT_FEN_W1C 0
#define arguments_BDK_TNS_TDMA_NB_INT_FEN_W1C -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_INT_FEN_W1C "TNS_TDMA_NB_INT_FEN_W1C"


/**
 * NCB - tns_tdma_nb_int_fen_w1s
 *
 * TDMA Interrupt First Enable Register.
 *
 */
typedef union bdk_tns_tdma_nb_int_fen_w1s {
	uint64_t u;
	struct bdk_tns_tdma_nb_int_fen_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t sst_seq_err                 : 1;  /**< R/W1S - A CSR request to the SST blocks experienced a fatal protocol sequence error. */
		uint64_t sst_req_timeout             : 1;  /**< R/W1S - A CSR request to the SST blocks timed out. */
		uint64_t sst_addr_err                : 1;  /**< R/W1S - A CSR request to the SST blocks was directed to an invalid address. */
		uint64_t prc_urw_zero                : 1;  /**< R/W1S - A PRC counter was inappropriately decremented to zero by the URW. */
		uint64_t prc_rollunder               : 1;  /**< R/W1S - A PRC counter rolled under. */
		uint64_t prc_rollover                : 1;  /**< R/W1S - A PRC counter rolled over. */
		uint64_t pm_dbe                      : 1;  /**< R/W1S - Double-bit ECC error detected on PM RAM. */
		uint64_t prc_dbe                     : 1;  /**< R/W1S - Double-bit ECC error detected on PRC RAM. */
		uint64_t ll_dbe                      : 1;  /**< R/W1S - Double-bit ECC error detected on LL RAM. */
		uint64_t fpm_dbe                     : 1;  /**< R/W1S - Double-bit ECC error detected on FPM RAM. */
		uint64_t pkt_lb_dbe                  : 1;  /**< R/W1S - Double-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_x2p_dbe                 : 1;  /**< R/W1S - Double-bit ECC error detected on PKT_X2P RAM. */
		uint64_t pkt_p2x_data_dbe            : 1;  /**< R/W1S - Double-bit ECC error detected on PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_dbe             : 1;  /**< R/W1S - Double-bit ECC error detected on PKT_P2X_TKN RAM. */
		uint64_t pm_sbe                      : 1;  /**< R/W1S - Single-bit ECC error detected on PM RAM. */
		uint64_t prc_sbe                     : 1;  /**< R/W1S - Single-bit ECC error detected on PRC RAM. */
		uint64_t ll_sbe                      : 1;  /**< R/W1S - Single-bit ECC error detected on LL RAM. */
		uint64_t fpm_sbe                     : 1;  /**< R/W1S - Single-bit ECC error detected on FPM RAM. */
		uint64_t pkt_lb_sbe                  : 1;  /**< R/W1S - Single-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_x2p_sbe                 : 1;  /**< R/W1S - Single-bit ECC error detected on PKT_X2P RAM. */
		uint64_t pkt_p2x_data_sbe            : 1;  /**< R/W1S - Single-bit ECC error detected on PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_sbe             : 1;  /**< R/W1S - Single-bit ECC error detected on PKT_P2X_TKN RAM. */
#else
		uint64_t pkt_p2x_tkn_sbe             : 1;
		uint64_t pkt_p2x_data_sbe            : 1;
		uint64_t pkt_x2p_sbe                 : 1;
		uint64_t pkt_lb_sbe                  : 1;
		uint64_t fpm_sbe                     : 1;
		uint64_t ll_sbe                      : 1;
		uint64_t prc_sbe                     : 1;
		uint64_t pm_sbe                      : 1;
		uint64_t pkt_p2x_tkn_dbe             : 1;
		uint64_t pkt_p2x_data_dbe            : 1;
		uint64_t pkt_x2p_dbe                 : 1;
		uint64_t pkt_lb_dbe                  : 1;
		uint64_t fpm_dbe                     : 1;
		uint64_t ll_dbe                      : 1;
		uint64_t prc_dbe                     : 1;
		uint64_t pm_dbe                      : 1;
		uint64_t prc_rollover                : 1;
		uint64_t prc_rollunder               : 1;
		uint64_t prc_urw_zero                : 1;
		uint64_t sst_addr_err                : 1;
		uint64_t sst_req_timeout             : 1;
		uint64_t sst_seq_err                 : 1;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_int_fen_w1s_s cn85xx; */
	/* struct bdk_tns_tdma_nb_int_fen_w1s_s cn88xx; */
} bdk_tns_tdma_nb_int_fen_w1s_t;

#define BDK_TNS_TDMA_NB_INT_FEN_W1S BDK_TNS_TDMA_NB_INT_FEN_W1S_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_INT_FEN_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_INT_FEN_W1S_FUNC(void)
{
	return 0x0000842041000150ull;
}
#define typedef_BDK_TNS_TDMA_NB_INT_FEN_W1S bdk_tns_tdma_nb_int_fen_w1s_t
#define bustype_BDK_TNS_TDMA_NB_INT_FEN_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_INT_FEN_W1S 0
#define arguments_BDK_TNS_TDMA_NB_INT_FEN_W1S -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_INT_FEN_W1S "TNS_TDMA_NB_INT_FEN_W1S"


/**
 * NCB - tns_tdma_nb_int_fstat
 *
 * TDMA Interrupt First Status Register.
 *
 */
typedef union bdk_tns_tdma_nb_int_fstat {
	uint64_t u;
	struct bdk_tns_tdma_nb_int_fstat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t sst_seq_err                 : 1;  /**< RO/H - A CSR request to the SST blocks experienced a fatal protocol sequence error. */
		uint64_t sst_req_timeout             : 1;  /**< RO/H - A CSR request to the SST blocks timed out. */
		uint64_t sst_addr_err                : 1;  /**< RO/H - A CSR request to the SST blocks was directed to an invalid address. */
		uint64_t prc_urw_zero                : 1;  /**< RO/H - A PRC counter was inappropriately decremented to zero by the URW. */
		uint64_t prc_rollunder               : 1;  /**< RO/H - A PRC counter rolled under. */
		uint64_t prc_rollover                : 1;  /**< RO/H - A PRC counter rolled over. */
		uint64_t pm_dbe                      : 1;  /**< RO/H - Double-bit ECC error detected on PM RAM. */
		uint64_t prc_dbe                     : 1;  /**< RO/H - Double-bit ECC error detected on PRC RAM. */
		uint64_t ll_dbe                      : 1;  /**< RO/H - Double-bit ECC error detected on LL RAM. */
		uint64_t fpm_dbe                     : 1;  /**< RO/H - Double-bit ECC error detected on FPM RAM. */
		uint64_t pkt_lb_dbe                  : 1;  /**< RO/H - Double-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_x2p_dbe                 : 1;  /**< RO/H - Double-bit ECC error detected on PKT_X2P RAM. */
		uint64_t pkt_p2x_data_dbe            : 1;  /**< RO/H - Double-bit ECC error detected on PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_dbe             : 1;  /**< RO/H - Double-bit ECC error detected on PKT_P2X_TKN RAM. */
		uint64_t pm_sbe                      : 1;  /**< RO/H - Single-bit ECC error detected on PM RAM. */
		uint64_t prc_sbe                     : 1;  /**< RO/H - Single-bit ECC error detected on PRC RAM. */
		uint64_t ll_sbe                      : 1;  /**< RO/H - Single-bit ECC error detected on LL RAM. */
		uint64_t fpm_sbe                     : 1;  /**< RO/H - Single-bit ECC error detected on FPM RAM. */
		uint64_t pkt_lb_sbe                  : 1;  /**< RO/H - Single-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_x2p_sbe                 : 1;  /**< RO/H - Single-bit ECC error detected on PKT_X2P RAM. */
		uint64_t pkt_p2x_data_sbe            : 1;  /**< RO/H - Single-bit ECC error detected on PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_sbe             : 1;  /**< RO/H - Single-bit ECC error detected on PKT_P2X_TKN RAM. */
#else
		uint64_t pkt_p2x_tkn_sbe             : 1;
		uint64_t pkt_p2x_data_sbe            : 1;
		uint64_t pkt_x2p_sbe                 : 1;
		uint64_t pkt_lb_sbe                  : 1;
		uint64_t fpm_sbe                     : 1;
		uint64_t ll_sbe                      : 1;
		uint64_t prc_sbe                     : 1;
		uint64_t pm_sbe                      : 1;
		uint64_t pkt_p2x_tkn_dbe             : 1;
		uint64_t pkt_p2x_data_dbe            : 1;
		uint64_t pkt_x2p_dbe                 : 1;
		uint64_t pkt_lb_dbe                  : 1;
		uint64_t fpm_dbe                     : 1;
		uint64_t ll_dbe                      : 1;
		uint64_t prc_dbe                     : 1;
		uint64_t pm_dbe                      : 1;
		uint64_t prc_rollover                : 1;
		uint64_t prc_rollunder               : 1;
		uint64_t prc_urw_zero                : 1;
		uint64_t sst_addr_err                : 1;
		uint64_t sst_req_timeout             : 1;
		uint64_t sst_seq_err                 : 1;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_int_fstat_s cn85xx; */
	/* struct bdk_tns_tdma_nb_int_fstat_s cn88xx; */
} bdk_tns_tdma_nb_int_fstat_t;

#define BDK_TNS_TDMA_NB_INT_FSTAT BDK_TNS_TDMA_NB_INT_FSTAT_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_INT_FSTAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_INT_FSTAT_FUNC(void)
{
	return 0x0000842041000140ull;
}
#define typedef_BDK_TNS_TDMA_NB_INT_FSTAT bdk_tns_tdma_nb_int_fstat_t
#define bustype_BDK_TNS_TDMA_NB_INT_FSTAT BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_INT_FSTAT 0
#define arguments_BDK_TNS_TDMA_NB_INT_FSTAT -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_INT_FSTAT "TNS_TDMA_NB_INT_FSTAT"


/**
 * NCB - tns_tdma_nb_int_stat_w1c
 *
 * TDMA Interrupt Status Register.
 *
 */
typedef union bdk_tns_tdma_nb_int_stat_w1c {
	uint64_t u;
	struct bdk_tns_tdma_nb_int_stat_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t sst_seq_err                 : 1;  /**< R/W1C/H - A CSR request to the SST blocks experienced a fatal protocol sequence error. */
		uint64_t sst_req_timeout             : 1;  /**< R/W1C/H - A CSR request to the SST blocks timed out. */
		uint64_t sst_addr_err                : 1;  /**< R/W1C/H - A CSR request to the SST blocks was directed to an invalid address. */
		uint64_t prc_urw_zero                : 1;  /**< R/W1C/H - A PRC counter was inappropriately decremented to zero by the URW. */
		uint64_t prc_rollunder               : 1;  /**< R/W1C/H - A PRC counter rolled under. */
		uint64_t prc_rollover                : 1;  /**< R/W1C/H - A PRC counter rolled over. */
		uint64_t pm_dbe                      : 1;  /**< R/W1C/H - Double-bit ECC error detected on PM RAM. */
		uint64_t prc_dbe                     : 1;  /**< R/W1C/H - Double-bit ECC error detected on PRC RAM. */
		uint64_t ll_dbe                      : 1;  /**< R/W1C/H - Double-bit ECC error detected on LL RAM. */
		uint64_t fpm_dbe                     : 1;  /**< R/W1C/H - Double-bit ECC error detected on FPM RAM. */
		uint64_t pkt_lb_dbe                  : 1;  /**< R/W1C/H - Double-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_x2p_dbe                 : 1;  /**< R/W1C/H - Double-bit ECC error detected on PKT_X2P RAM. */
		uint64_t pkt_p2x_data_dbe            : 1;  /**< R/W1C/H - Double-bit ECC error detected on PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_dbe             : 1;  /**< R/W1C/H - Double-bit ECC error detected on PKT_P2X_TKN RAM. */
		uint64_t pm_sbe                      : 1;  /**< R/W1C/H - Single-bit ECC error detected on PM RAM. */
		uint64_t prc_sbe                     : 1;  /**< R/W1C/H - Single-bit ECC error detected on PRC RAM. */
		uint64_t ll_sbe                      : 1;  /**< R/W1C/H - Single-bit ECC error detected on LL RAM. */
		uint64_t fpm_sbe                     : 1;  /**< R/W1C/H - Single-bit ECC error detected on FPM RAM. */
		uint64_t pkt_lb_sbe                  : 1;  /**< R/W1C/H - Single-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_x2p_sbe                 : 1;  /**< R/W1C/H - Single-bit ECC error detected on PKT_X2P RAM. */
		uint64_t pkt_p2x_data_sbe            : 1;  /**< R/W1C/H - Single-bit ECC error detected on PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_sbe             : 1;  /**< R/W1C/H - Single-bit ECC error detected on PKT_P2X_TKN RAM. */
#else
		uint64_t pkt_p2x_tkn_sbe             : 1;
		uint64_t pkt_p2x_data_sbe            : 1;
		uint64_t pkt_x2p_sbe                 : 1;
		uint64_t pkt_lb_sbe                  : 1;
		uint64_t fpm_sbe                     : 1;
		uint64_t ll_sbe                      : 1;
		uint64_t prc_sbe                     : 1;
		uint64_t pm_sbe                      : 1;
		uint64_t pkt_p2x_tkn_dbe             : 1;
		uint64_t pkt_p2x_data_dbe            : 1;
		uint64_t pkt_x2p_dbe                 : 1;
		uint64_t pkt_lb_dbe                  : 1;
		uint64_t fpm_dbe                     : 1;
		uint64_t ll_dbe                      : 1;
		uint64_t prc_dbe                     : 1;
		uint64_t pm_dbe                      : 1;
		uint64_t prc_rollover                : 1;
		uint64_t prc_rollunder               : 1;
		uint64_t prc_urw_zero                : 1;
		uint64_t sst_addr_err                : 1;
		uint64_t sst_req_timeout             : 1;
		uint64_t sst_seq_err                 : 1;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_int_stat_w1c_s cn85xx; */
	/* struct bdk_tns_tdma_nb_int_stat_w1c_s cn88xx; */
} bdk_tns_tdma_nb_int_stat_w1c_t;

#define BDK_TNS_TDMA_NB_INT_STAT_W1C BDK_TNS_TDMA_NB_INT_STAT_W1C_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_INT_STAT_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_INT_STAT_W1C_FUNC(void)
{
	return 0x0000842041000110ull;
}
#define typedef_BDK_TNS_TDMA_NB_INT_STAT_W1C bdk_tns_tdma_nb_int_stat_w1c_t
#define bustype_BDK_TNS_TDMA_NB_INT_STAT_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_INT_STAT_W1C 0
#define arguments_BDK_TNS_TDMA_NB_INT_STAT_W1C -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_INT_STAT_W1C "TNS_TDMA_NB_INT_STAT_W1C"


/**
 * NCB - tns_tdma_nb_int_stat_w1s
 *
 * TDMA Interrupt Status Register.
 *
 */
typedef union bdk_tns_tdma_nb_int_stat_w1s {
	uint64_t u;
	struct bdk_tns_tdma_nb_int_stat_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t sst_seq_err                 : 1;  /**< R/W1S/H - A CSR request to the SST blocks experienced a fatal protocol sequence error. */
		uint64_t sst_req_timeout             : 1;  /**< R/W1S/H - A CSR request to the SST blocks timed out. */
		uint64_t sst_addr_err                : 1;  /**< R/W1S/H - A CSR request to the SST blocks was directed to an invalid address. */
		uint64_t prc_urw_zero                : 1;  /**< R/W1S/H - A PRC counter was inappropriately decremented to zero by the URW. */
		uint64_t prc_rollunder               : 1;  /**< R/W1S/H - A PRC counter rolled under. */
		uint64_t prc_rollover                : 1;  /**< R/W1S/H - A PRC counter rolled over. */
		uint64_t pm_dbe                      : 1;  /**< R/W1S/H - Double-bit ECC error detected on PM RAM. */
		uint64_t prc_dbe                     : 1;  /**< R/W1S/H - Double-bit ECC error detected on PRC RAM. */
		uint64_t ll_dbe                      : 1;  /**< R/W1S/H - Double-bit ECC error detected on LL RAM. */
		uint64_t fpm_dbe                     : 1;  /**< R/W1S/H - Double-bit ECC error detected on FPM RAM. */
		uint64_t pkt_lb_dbe                  : 1;  /**< R/W1S/H - Double-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_x2p_dbe                 : 1;  /**< R/W1S/H - Double-bit ECC error detected on PKT_X2P RAM. */
		uint64_t pkt_p2x_data_dbe            : 1;  /**< R/W1S/H - Double-bit ECC error detected on PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_dbe             : 1;  /**< R/W1S/H - Double-bit ECC error detected on PKT_P2X_TKN RAM. */
		uint64_t pm_sbe                      : 1;  /**< R/W1S/H - Single-bit ECC error detected on PM RAM. */
		uint64_t prc_sbe                     : 1;  /**< R/W1S/H - Single-bit ECC error detected on PRC RAM. */
		uint64_t ll_sbe                      : 1;  /**< R/W1S/H - Single-bit ECC error detected on LL RAM. */
		uint64_t fpm_sbe                     : 1;  /**< R/W1S/H - Single-bit ECC error detected on FPM RAM. */
		uint64_t pkt_lb_sbe                  : 1;  /**< R/W1S/H - Single-bit ECC error detected on PKT_LB RAM. */
		uint64_t pkt_x2p_sbe                 : 1;  /**< R/W1S/H - Single-bit ECC error detected on PKT_X2P RAM. */
		uint64_t pkt_p2x_data_sbe            : 1;  /**< R/W1S/H - Single-bit ECC error detected on PKT_P2X_DATA RAM. */
		uint64_t pkt_p2x_tkn_sbe             : 1;  /**< R/W1S/H - Single-bit ECC error detected on PKT_P2X_TKN RAM. */
#else
		uint64_t pkt_p2x_tkn_sbe             : 1;
		uint64_t pkt_p2x_data_sbe            : 1;
		uint64_t pkt_x2p_sbe                 : 1;
		uint64_t pkt_lb_sbe                  : 1;
		uint64_t fpm_sbe                     : 1;
		uint64_t ll_sbe                      : 1;
		uint64_t prc_sbe                     : 1;
		uint64_t pm_sbe                      : 1;
		uint64_t pkt_p2x_tkn_dbe             : 1;
		uint64_t pkt_p2x_data_dbe            : 1;
		uint64_t pkt_x2p_dbe                 : 1;
		uint64_t pkt_lb_dbe                  : 1;
		uint64_t fpm_dbe                     : 1;
		uint64_t ll_dbe                      : 1;
		uint64_t prc_dbe                     : 1;
		uint64_t pm_dbe                      : 1;
		uint64_t prc_rollover                : 1;
		uint64_t prc_rollunder               : 1;
		uint64_t prc_urw_zero                : 1;
		uint64_t sst_addr_err                : 1;
		uint64_t sst_req_timeout             : 1;
		uint64_t sst_seq_err                 : 1;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_int_stat_w1s_s cn85xx; */
	/* struct bdk_tns_tdma_nb_int_stat_w1s_s cn88xx; */
} bdk_tns_tdma_nb_int_stat_w1s_t;

#define BDK_TNS_TDMA_NB_INT_STAT_W1S BDK_TNS_TDMA_NB_INT_STAT_W1S_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_INT_STAT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_INT_STAT_W1S_FUNC(void)
{
	return 0x0000842041000100ull;
}
#define typedef_BDK_TNS_TDMA_NB_INT_STAT_W1S bdk_tns_tdma_nb_int_stat_w1s_t
#define bustype_BDK_TNS_TDMA_NB_INT_STAT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_INT_STAT_W1S 0
#define arguments_BDK_TNS_TDMA_NB_INT_STAT_W1S -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_INT_STAT_W1S "TNS_TDMA_NB_INT_STAT_W1S"


/**
 * NCB - tns_tdma_nb_ll_acc#
 *
 * Provides the ability for software to access the TDMA Link List memory.
 * The LL consists of 12288 28-bit words.
 * The contents of each word is:
 * _ [27]    = SOP flag. This page contains the packet SOP. This page is a Header page.
 * _ [26]    = EOP flag. This page contains the packet EOP.
 * _ [25:12] = Next page. Only valid if EOP flag not set.
 * _ [11:8]  = Error code.
 * _ [7:0]   = Valid page bytes. 0 = 256 bytes.
 */
typedef union bdk_tns_tdma_nb_ll_accx {
	uint64_t u;
	struct bdk_tns_tdma_nb_ll_accx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_28_63              : 36;
		uint64_t data                        : 28; /**< R/W/H - Data. */
#else
		uint64_t data                        : 28;
		uint64_t reserved_28_63              : 36;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_ll_accx_s   cn85xx; */
	/* struct bdk_tns_tdma_nb_ll_accx_s   cn88xx; */
} bdk_tns_tdma_nb_ll_accx_t;

static inline uint64_t BDK_TNS_TDMA_NB_LL_ACCX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_LL_ACCX(unsigned long param1)
{
	if (((param1 <= 12287)))
		return 0x0000842041040000ull + (param1 & 16383) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_NB_LL_ACCX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_NB_LL_ACCX(...) bdk_tns_tdma_nb_ll_accx_t
#define bustype_BDK_TNS_TDMA_NB_LL_ACCX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_LL_ACCX(p1) (p1)
#define arguments_BDK_TNS_TDMA_NB_LL_ACCX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_LL_ACCX(...) "TNS_TDMA_NB_LL_ACCX"


/**
 * NCB - tns_tdma_nb_lmac#_c_cdt_cfg
 *
 * Control use of channel credits for packet transmission on a per-LMAC basis.
 *
 */
typedef union bdk_tns_tdma_nb_lmacx_c_cdt_cfg {
	uint64_t u;
	struct bdk_tns_tdma_nb_lmacx_c_cdt_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_17_63              : 47;
		uint64_t use_cdts                    : 1;  /**< R/W - 0 = Use EBP Xon/Xoff back pressure for per-priority LMAC scheduling.
                                                                     A packet may be scheduled for transmission as long as the LMAC is not
                                                                     indicating Xoff for the packet's priority.
                                                                 1 = Use channel credits for LMAC scheduling, giving all priorities equal weight.
                                                                     A packet may be scheduled for transmission as long as
                                                                     TNS_TDMA_NB_LMAC(0..7)_C_CDT_STAT[CONSUMED_CDTS] is less than CDT_LIMIT. */
		uint64_t reserved_10_15              : 6;
		uint64_t cdt_limit                   : 10; /**< R/W - Credit consumption limit at which packet transmission to the LMAC will stop. Values above
                                                                 0xA0 are prohibited. */
#else
		uint64_t cdt_limit                   : 10;
		uint64_t reserved_10_15              : 6;
		uint64_t use_cdts                    : 1;
		uint64_t reserved_17_63              : 47;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_lmacx_c_cdt_cfg_s cn85xx; */
	/* struct bdk_tns_tdma_nb_lmacx_c_cdt_cfg_s cn88xx; */
} bdk_tns_tdma_nb_lmacx_c_cdt_cfg_t;

static inline uint64_t BDK_TNS_TDMA_NB_LMACX_C_CDT_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_LMACX_C_CDT_CFG(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000842041000900ull + (param1 & 7) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_NB_LMACX_C_CDT_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_NB_LMACX_C_CDT_CFG(...) bdk_tns_tdma_nb_lmacx_c_cdt_cfg_t
#define bustype_BDK_TNS_TDMA_NB_LMACX_C_CDT_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_LMACX_C_CDT_CFG(p1) (p1)
#define arguments_BDK_TNS_TDMA_NB_LMACX_C_CDT_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_LMACX_C_CDT_CFG(...) "TNS_TDMA_NB_LMACX_C_CDT_CFG"


/**
 * NCB - tns_tdma_nb_lmac#_c_cdt_stat
 */
typedef union bdk_tns_tdma_nb_lmacx_c_cdt_stat {
	uint64_t u;
	struct bdk_tns_tdma_nb_lmacx_c_cdt_stat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t cdts_consumed               : 10; /**< RO/H - Current number of 16-byte credits consumed for packet transmission to the LMAC. */
#else
		uint64_t cdts_consumed               : 10;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_lmacx_c_cdt_stat_s cn85xx; */
	/* struct bdk_tns_tdma_nb_lmacx_c_cdt_stat_s cn88xx; */
} bdk_tns_tdma_nb_lmacx_c_cdt_stat_t;

static inline uint64_t BDK_TNS_TDMA_NB_LMACX_C_CDT_STAT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_LMACX_C_CDT_STAT(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000842041000980ull + (param1 & 7) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_NB_LMACX_C_CDT_STAT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_NB_LMACX_C_CDT_STAT(...) bdk_tns_tdma_nb_lmacx_c_cdt_stat_t
#define bustype_BDK_TNS_TDMA_NB_LMACX_C_CDT_STAT(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_LMACX_C_CDT_STAT(p1) (p1)
#define arguments_BDK_TNS_TDMA_NB_LMACX_C_CDT_STAT(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_LMACX_C_CDT_STAT(...) "TNS_TDMA_NB_LMACX_C_CDT_STAT"


/**
 * NCB - tns_tdma_nb_lmac#_ebp_stat
 */
typedef union bdk_tns_tdma_nb_lmacx_ebp_stat {
	uint64_t u;
	struct bdk_tns_tdma_nb_lmacx_ebp_stat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t bp                          : 16; /**< RO/H - Back pressure status presented to TxQ. XOFF = 1. */
#else
		uint64_t bp                          : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_lmacx_ebp_stat_s cn85xx; */
	/* struct bdk_tns_tdma_nb_lmacx_ebp_stat_s cn88xx; */
} bdk_tns_tdma_nb_lmacx_ebp_stat_t;

static inline uint64_t BDK_TNS_TDMA_NB_LMACX_EBP_STAT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_LMACX_EBP_STAT(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000842041000A00ull + (param1 & 7) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_NB_LMACX_EBP_STAT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_NB_LMACX_EBP_STAT(...) bdk_tns_tdma_nb_lmacx_ebp_stat_t
#define bustype_BDK_TNS_TDMA_NB_LMACX_EBP_STAT(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_LMACX_EBP_STAT(p1) (p1)
#define arguments_BDK_TNS_TDMA_NB_LMACX_EBP_STAT(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_LMACX_EBP_STAT(...) "TNS_TDMA_NB_LMACX_EBP_STAT"


/**
 * NCB - tns_tdma_nb_page_rd_cnt#
 *
 * Packet memory pages accessed by the physical port.
 * All fields have roll over counters.
 * Register number enumerated by TNS_PHYS_PORT_E.
 * Register number 11 corresponds to pages accessed due to drops and multiple copy clearing.
 * Multiple copy clearing is performed for all multiple copy packets to return pages to the free
 * list.
 * Multiple copy packets will be counted by each physical port that transmits the packet, as well
 * as register 11 when the multiple copy is cleared.
 */
typedef union bdk_tns_tdma_nb_page_rd_cntx {
	uint64_t u;
	struct bdk_tns_tdma_nb_page_rd_cntx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t pages                       : 32; /**< R/W/H - Memory Pages. */
#else
		uint64_t pages                       : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_page_rd_cntx_s cn85xx; */
	/* struct bdk_tns_tdma_nb_page_rd_cntx_s cn88xx; */
} bdk_tns_tdma_nb_page_rd_cntx_t;

static inline uint64_t BDK_TNS_TDMA_NB_PAGE_RD_CNTX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_PAGE_RD_CNTX(unsigned long param1)
{
	if (((param1 <= 11)))
		return 0x0000842041000700ull + (param1 & 15) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_NB_PAGE_RD_CNTX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_NB_PAGE_RD_CNTX(...) bdk_tns_tdma_nb_page_rd_cntx_t
#define bustype_BDK_TNS_TDMA_NB_PAGE_RD_CNTX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_PAGE_RD_CNTX(p1) (p1)
#define arguments_BDK_TNS_TDMA_NB_PAGE_RD_CNTX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_PAGE_RD_CNTX(...) "TNS_TDMA_NB_PAGE_RD_CNTX"


/**
 * NCB - tns_tdma_nb_page_src_cnt#
 *
 * This register shows total counts of pages used for storing packet headers and bodies
 * from various different physical source ports, as enumerated by TNS_PHYS_PORT_E.
 * All fields have roll over counters.
 */
typedef union bdk_tns_tdma_nb_page_src_cntx {
	uint64_t u;
	struct bdk_tns_tdma_nb_page_src_cntx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t head                        : 32; /**< R/W/H - Pages used to store packet headers. */
		uint64_t body                        : 32; /**< R/W/H - Pages used to store packet bodies. */
#else
		uint64_t body                        : 32;
		uint64_t head                        : 32;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_page_src_cntx_s cn85xx; */
	/* struct bdk_tns_tdma_nb_page_src_cntx_s cn88xx; */
} bdk_tns_tdma_nb_page_src_cntx_t;

static inline uint64_t BDK_TNS_TDMA_NB_PAGE_SRC_CNTX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_PAGE_SRC_CNTX(unsigned long param1)
{
	if (((param1 <= 10)))
		return 0x0000842041000500ull + (param1 & 15) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_NB_PAGE_SRC_CNTX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_NB_PAGE_SRC_CNTX(...) bdk_tns_tdma_nb_page_src_cntx_t
#define bustype_BDK_TNS_TDMA_NB_PAGE_SRC_CNTX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_PAGE_SRC_CNTX(p1) (p1)
#define arguments_BDK_TNS_TDMA_NB_PAGE_SRC_CNTX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_PAGE_SRC_CNTX(...) "TNS_TDMA_NB_PAGE_SRC_CNTX"


/**
 * NCB - tns_tdma_nb_pages_used
 *
 * This register shows the number of pages currently used to store packet data.
 * Values range from 0 to 0x3000 (12288 decimal).
 */
typedef union bdk_tns_tdma_nb_pages_used {
	uint64_t u;
	struct bdk_tns_tdma_nb_pages_used_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t cnt                         : 14; /**< RO/H - Pages in use. */
#else
		uint64_t cnt                         : 14;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_pages_used_s cn85xx; */
	/* struct bdk_tns_tdma_nb_pages_used_s cn88xx; */
} bdk_tns_tdma_nb_pages_used_t;

#define BDK_TNS_TDMA_NB_PAGES_USED BDK_TNS_TDMA_NB_PAGES_USED_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_PAGES_USED_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_PAGES_USED_FUNC(void)
{
	return 0x00008420410005C0ull;
}
#define typedef_BDK_TNS_TDMA_NB_PAGES_USED bdk_tns_tdma_nb_pages_used_t
#define bustype_BDK_TNS_TDMA_NB_PAGES_USED BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_PAGES_USED 0
#define arguments_BDK_TNS_TDMA_NB_PAGES_USED -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_PAGES_USED "TNS_TDMA_NB_PAGES_USED"


/**
 * NCB - tns_tdma_nb_prc_acc#
 *
 * Provides the ability for software to access the TDMA Page Reference Count memory.
 * The PRC consists of 12288 29-bit words.
 * The contents of each word is:
 * _ [28:25] = Source Port. Enumerated by TNS_PHYS_PORT_E.
 * _ [24:18] = Source Channel/Traffic Class.
 * _           Source Ports 0-7: [3'h0, Traffic Class(4)]
 * _           Source Ports 8-9: Source Channel(7)
 * _           Source Port   10: Unused
 * _ [17]    = Global Multicast Pool used.
 * _ [16]    = Shared Pool used.
 * _ [15:0]  = Page Reference Count. Number of times a page will be sent/dropped before being
 * _           returned to the free list.
 */
typedef union bdk_tns_tdma_nb_prc_accx {
	uint64_t u;
	struct bdk_tns_tdma_nb_prc_accx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_29_63              : 35;
		uint64_t data                        : 29; /**< R/W/H - Data. */
#else
		uint64_t data                        : 29;
		uint64_t reserved_29_63              : 35;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_prc_accx_s  cn85xx; */
	/* struct bdk_tns_tdma_nb_prc_accx_s  cn88xx; */
} bdk_tns_tdma_nb_prc_accx_t;

static inline uint64_t BDK_TNS_TDMA_NB_PRC_ACCX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_PRC_ACCX(unsigned long param1)
{
	if (((param1 <= 12287)))
		return 0x0000842041080000ull + (param1 & 16383) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_NB_PRC_ACCX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_NB_PRC_ACCX(...) bdk_tns_tdma_nb_prc_accx_t
#define bustype_BDK_TNS_TDMA_NB_PRC_ACCX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_PRC_ACCX(p1) (p1)
#define arguments_BDK_TNS_TDMA_NB_PRC_ACCX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_PRC_ACCX(...) "TNS_TDMA_NB_PRC_ACCX"


/**
 * NCB - tns_tdma_nb_prc_err
 */
typedef union bdk_tns_tdma_nb_prc_err {
	uint64_t u;
	struct bdk_tns_tdma_nb_prc_err_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t address                     : 14; /**< RO/H - Captured address for PRC_ROLLOVER, PRC_ROLLUNDER, and PRC_URW_ZERO TNS_TDMA_NB_INT_STAT_W1S errors. */
#else
		uint64_t address                     : 14;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_prc_err_s   cn85xx; */
	/* struct bdk_tns_tdma_nb_prc_err_s   cn88xx; */
} bdk_tns_tdma_nb_prc_err_t;

#define BDK_TNS_TDMA_NB_PRC_ERR BDK_TNS_TDMA_NB_PRC_ERR_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_PRC_ERR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_PRC_ERR_FUNC(void)
{
	return 0x0000842041000820ull;
}
#define typedef_BDK_TNS_TDMA_NB_PRC_ERR bdk_tns_tdma_nb_prc_err_t
#define bustype_BDK_TNS_TDMA_NB_PRC_ERR BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_PRC_ERR 0
#define arguments_BDK_TNS_TDMA_NB_PRC_ERR -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_PRC_ERR "TNS_TDMA_NB_PRC_ERR"


/**
 * NCB - tns_tdma_nb_status
 *
 * General status register.
 *
 */
typedef union bdk_tns_tdma_nb_status {
	uint64_t u;
	struct bdk_tns_tdma_nb_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_52_63              : 12;
		uint64_t init_done                   : 1;  /**< RO/H - Set to 0x1 by hardware upon completion of auto-initialization.
                                                                 Cleared to 0x0 when software initiates hardware auto-initialization
                                                                 by writing to TNS_TDMA_NB_CONFIG[AUTO_INIT]. */
		uint64_t reserved_0_50               : 51;
#else
		uint64_t reserved_0_50               : 51;
		uint64_t init_done                   : 1;
		uint64_t reserved_52_63              : 12;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_status_s    cn85xx; */
	/* struct bdk_tns_tdma_nb_status_s    cn88xx; */
} bdk_tns_tdma_nb_status_t;

#define BDK_TNS_TDMA_NB_STATUS BDK_TNS_TDMA_NB_STATUS_FUNC()
static inline uint64_t BDK_TNS_TDMA_NB_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_STATUS_FUNC(void)
{
	return 0x0000842041000400ull;
}
#define typedef_BDK_TNS_TDMA_NB_STATUS bdk_tns_tdma_nb_status_t
#define bustype_BDK_TNS_TDMA_NB_STATUS BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_STATUS 0
#define arguments_BDK_TNS_TDMA_NB_STATUS -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_STATUS "TNS_TDMA_NB_STATUS"


/**
 * NCB - tns_tdma_nb_strip_lmac#_xph
 *
 * Strip and discard the 24-byte internal XPH packet header (if present) from packets during
 * transmission to the LMAC.
 */
typedef union bdk_tns_tdma_nb_strip_lmacx_xph {
	uint64_t u;
	struct bdk_tns_tdma_nb_strip_lmacx_xph_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t lmac                        : 1;  /**< R/W - Strip and discard the 24-byte internal XPH packet header (if present) from packets during
                                                                 transmission to the LMAC. */
#else
		uint64_t lmac                        : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_strip_lmacx_xph_s cn85xx; */
	/* struct bdk_tns_tdma_nb_strip_lmacx_xph_s cn88xx; */
} bdk_tns_tdma_nb_strip_lmacx_xph_t;

static inline uint64_t BDK_TNS_TDMA_NB_STRIP_LMACX_XPH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_STRIP_LMACX_XPH(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000842041000280ull + (param1 & 7) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_NB_STRIP_LMACX_XPH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_NB_STRIP_LMACX_XPH(...) bdk_tns_tdma_nb_strip_lmacx_xph_t
#define bustype_BDK_TNS_TDMA_NB_STRIP_LMACX_XPH(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_STRIP_LMACX_XPH(p1) (p1)
#define arguments_BDK_TNS_TDMA_NB_STRIP_LMACX_XPH(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_STRIP_LMACX_XPH(...) "TNS_TDMA_NB_STRIP_LMACX_XPH"


/**
 * NCB - tns_tdma_nb_strip_nic_xph#
 *
 * Strip and discard the 24-byte internal XPH packet header (if present) from packets during
 * transmission to the NIC.
 */
typedef union bdk_tns_tdma_nb_strip_nic_xphx {
	uint64_t u;
	struct bdk_tns_tdma_nb_strip_nic_xphx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t chan                        : 64; /**< R/W - Strip XPH packet header (if present) before sending packets to NIC. */
#else
		uint64_t chan                        : 64;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_strip_nic_xphx_s cn85xx; */
	/* struct bdk_tns_tdma_nb_strip_nic_xphx_s cn88xx; */
} bdk_tns_tdma_nb_strip_nic_xphx_t;

static inline uint64_t BDK_TNS_TDMA_NB_STRIP_NIC_XPHX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_STRIP_NIC_XPHX(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000842041000240ull + (param1 & 3) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_NB_STRIP_NIC_XPHX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_NB_STRIP_NIC_XPHX(...) bdk_tns_tdma_nb_strip_nic_xphx_t
#define bustype_BDK_TNS_TDMA_NB_STRIP_NIC_XPHX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_STRIP_NIC_XPHX(p1) (p1)
#define arguments_BDK_TNS_TDMA_NB_STRIP_NIC_XPHX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_STRIP_NIC_XPHX(...) "TNS_TDMA_NB_STRIP_NIC_XPHX"


/**
 * NCB - tns_tdma_nb_truncate#_len
 */
typedef union bdk_tns_tdma_nb_truncatex_len {
	uint64_t u;
	struct bdk_tns_tdma_nb_truncatex_len_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t length                      : 9;  /**< R/W - For designated packets, truncate packet after the specified length.
                                                                 Valid values are 0 through 256 (decimal).
                                                                 No truncate will occur if set to 0x0. */
#else
		uint64_t length                      : 9;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_tns_tdma_nb_truncatex_len_s cn85xx; */
	/* struct bdk_tns_tdma_nb_truncatex_len_s cn88xx; */
} bdk_tns_tdma_nb_truncatex_len_t;

static inline uint64_t BDK_TNS_TDMA_NB_TRUNCATEX_LEN(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_NB_TRUNCATEX_LEN(unsigned long param1)
{
	if (((param1 <= 10)))
		return 0x0000842041000300ull + (param1 & 15) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_NB_TRUNCATEX_LEN", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_NB_TRUNCATEX_LEN(...) bdk_tns_tdma_nb_truncatex_len_t
#define bustype_BDK_TNS_TDMA_NB_TRUNCATEX_LEN(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_NB_TRUNCATEX_LEN(p1) (p1)
#define arguments_BDK_TNS_TDMA_NB_TRUNCATEX_LEN(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_NB_TRUNCATEX_LEN(...) "TNS_TDMA_NB_TRUNCATEX_LEN"


/**
 * NCB - tns_tdma_reset_ctl
 *
 * Allows software to reset individual components of the network switch.
 *
 */
typedef union bdk_tns_tdma_reset_ctl {
	uint64_t u;
	struct bdk_tns_tdma_reset_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t sde_urw3_d                  : 1;  /**< R/W - Reset SDE URW3 (D). */
		uint64_t sde_urw3_c                  : 1;  /**< R/W - Reset SDE URW3 (C). */
		uint64_t sde_urw2_d                  : 1;  /**< R/W - Reset SDE URW2 (D). */
		uint64_t sde_urw2_c                  : 1;  /**< R/W - Reset SDE URW2 (C). */
		uint64_t sde_urw1_d                  : 1;  /**< R/W - Reset SDE URW1 (D). */
		uint64_t sde_urw1_c                  : 1;  /**< R/W - Reset SDE URW1 (C). */
		uint64_t sde_cnt_d                   : 1;  /**< R/W - Reset SDE CNT (D). */
		uint64_t sde_cnt_c                   : 1;  /**< R/W - Reset SDE CNT (C). */
		uint64_t sde_lde1_d                  : 1;  /**< R/W - Reset SDE LDE1 (D). */
		uint64_t sde_lde1_c                  : 1;  /**< R/W - Reset SDE LDE1 (C). */
		uint64_t sde_lde0_d                  : 1;  /**< R/W - Reset SDE LDE0 (D). */
		uint64_t sde_lde0_c                  : 1;  /**< R/W - Reset SDE LDE0 (C). */
		uint64_t sde_isme_d                  : 1;  /**< R/W - Reset SDE ISME (D). */
		uint64_t sde_isme_c                  : 1;  /**< R/W - Reset SDE ISME (C). */
		uint64_t sde_mre_d                   : 1;  /**< R/W - Reset SDE MRE (D). */
		uint64_t sde_mre_c                   : 1;  /**< R/W - Reset SDE MRE (C). */
		uint64_t sde_hdbf_d                  : 1;  /**< R/W - Reset SDE HDBF (D). */
		uint64_t sde_hdbf_c                  : 1;  /**< R/W - Reset SDE HDBF (C). */
		uint64_t sde_parser_d                : 1;  /**< R/W - Reset SDE PARSER (D). */
		uint64_t sde_parser_c                : 1;  /**< R/W - Reset SDE PARSER (C). */
		uint64_t txq_tbc_d                   : 1;  /**< R/W - Reset TXQ TBC (D). */
		uint64_t txq_tbc_c                   : 1;  /**< R/W - Reset TXQ TBC (C). */
		uint64_t txq_qac_d                   : 1;  /**< R/W - Reset TXQ QAC (D). */
		uint64_t txq_qac_c                   : 1;  /**< R/W - Reset TXQ QAC (C). */
		uint64_t txq_dq_d                    : 1;  /**< R/W - Reset TXQ DQ (D). */
		uint64_t txq_dq_c                    : 1;  /**< R/W - Reset TXQ DQ (C). */
		uint64_t txq_eq_d                    : 1;  /**< R/W - Reset TXQ EQ (D). */
		uint64_t txq_eq_c                    : 1;  /**< R/W - Reset TXQ EQ (C). */
		uint64_t se_ctl_d                    : 1;  /**< R/W - Reset SE CTL (D). */
		uint64_t se_ctl_c                    : 1;  /**< R/W - Reset SE CTL (C). */
		uint64_t se_age_d                    : 1;  /**< R/W - Reset SE AGE (D). */
		uint64_t se_age_c                    : 1;  /**< R/W - Reset SE AGE (C). */
		uint64_t se_tcam_d                   : 1;  /**< R/W - Reset SE TCAM (D). */
		uint64_t se_tcam_c                   : 1;  /**< R/W - Reset SE TCAM (C). */
		uint64_t se_sram_d                   : 1;  /**< R/W - Reset SE SRAM (D). */
		uint64_t se_sram_c                   : 1;  /**< R/W - Reset SE SRAM (C). */
		uint64_t reserved_2_3                : 2;
		uint64_t rdma                        : 1;  /**< R/W - Reset RDMA packet path. */
		uint64_t tdma                        : 1;  /**< R/W - Reset TDMA packet path. */
#else
		uint64_t tdma                        : 1;
		uint64_t rdma                        : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t se_sram_c                   : 1;
		uint64_t se_sram_d                   : 1;
		uint64_t se_tcam_c                   : 1;
		uint64_t se_tcam_d                   : 1;
		uint64_t se_age_c                    : 1;
		uint64_t se_age_d                    : 1;
		uint64_t se_ctl_c                    : 1;
		uint64_t se_ctl_d                    : 1;
		uint64_t txq_eq_c                    : 1;
		uint64_t txq_eq_d                    : 1;
		uint64_t txq_dq_c                    : 1;
		uint64_t txq_dq_d                    : 1;
		uint64_t txq_qac_c                   : 1;
		uint64_t txq_qac_d                   : 1;
		uint64_t txq_tbc_c                   : 1;
		uint64_t txq_tbc_d                   : 1;
		uint64_t sde_parser_c                : 1;
		uint64_t sde_parser_d                : 1;
		uint64_t sde_hdbf_c                  : 1;
		uint64_t sde_hdbf_d                  : 1;
		uint64_t sde_mre_c                   : 1;
		uint64_t sde_mre_d                   : 1;
		uint64_t sde_isme_c                  : 1;
		uint64_t sde_isme_d                  : 1;
		uint64_t sde_lde0_c                  : 1;
		uint64_t sde_lde0_d                  : 1;
		uint64_t sde_lde1_c                  : 1;
		uint64_t sde_lde1_d                  : 1;
		uint64_t sde_cnt_c                   : 1;
		uint64_t sde_cnt_d                   : 1;
		uint64_t sde_urw1_c                  : 1;
		uint64_t sde_urw1_d                  : 1;
		uint64_t sde_urw2_c                  : 1;
		uint64_t sde_urw2_d                  : 1;
		uint64_t sde_urw3_c                  : 1;
		uint64_t sde_urw3_d                  : 1;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_tns_tdma_reset_ctl_s    cn85xx; */
	/* struct bdk_tns_tdma_reset_ctl_s    cn88xx; */
} bdk_tns_tdma_reset_ctl_t;

#define BDK_TNS_TDMA_RESET_CTL BDK_TNS_TDMA_RESET_CTL_FUNC()
static inline uint64_t BDK_TNS_TDMA_RESET_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_RESET_CTL_FUNC(void)
{
	return 0x0000842000000210ull;
}
#define typedef_BDK_TNS_TDMA_RESET_CTL bdk_tns_tdma_reset_ctl_t
#define bustype_BDK_TNS_TDMA_RESET_CTL BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_RESET_CTL 0
#define arguments_BDK_TNS_TDMA_RESET_CTL -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_RESET_CTL "TNS_TDMA_RESET_CTL"


/**
 * NCB - tns_tdma_spare
 *
 * Spare register.
 *
 */
typedef union bdk_tns_tdma_spare {
	uint64_t u;
	struct bdk_tns_tdma_spare_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_tns_tdma_spare_s        cn85xx; */
	/* struct bdk_tns_tdma_spare_s        cn88xx; */
} bdk_tns_tdma_spare_t;

#define BDK_TNS_TDMA_SPARE BDK_TNS_TDMA_SPARE_FUNC()
static inline uint64_t BDK_TNS_TDMA_SPARE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_SPARE_FUNC(void)
{
	return 0x0000842000000E00ull;
}
#define typedef_BDK_TNS_TDMA_SPARE bdk_tns_tdma_spare_t
#define bustype_BDK_TNS_TDMA_SPARE BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_SPARE 0
#define arguments_BDK_TNS_TDMA_SPARE -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_SPARE "TNS_TDMA_SPARE"


/**
 * NCB - tns_tdma_sst_acc_cmd
 */
typedef union bdk_tns_tdma_sst_acc_cmd {
	uint64_t u;
	struct bdk_tns_tdma_sst_acc_cmd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_38_63              : 26;
		uint64_t go                          : 1;  /**< R/W/H - Perform read or write command. This bit is self-clearing upon request completion. */
		uint64_t op                          : 1;  /**< R/W - Operation type. 0 = Write. 1 = Read. */
		uint64_t size                        : 4;  /**< R/W - Transaction size, quantities of 32-bit words.
                                                                 0x0 = 16 bytes.
                                                                 0x1 = 1 word.
                                                                 0x2 = 2 words.
                                                                 0x3 = 3 words.
                                                                 0xf = 15 words. */
		uint64_t addr                        : 30; /**< R/W - Address. */
		uint64_t reserved_0_1                : 2;
#else
		uint64_t reserved_0_1                : 2;
		uint64_t addr                        : 30;
		uint64_t size                        : 4;
		uint64_t op                          : 1;
		uint64_t go                          : 1;
		uint64_t reserved_38_63              : 26;
#endif
	} s;
	/* struct bdk_tns_tdma_sst_acc_cmd_s  cn85xx; */
	/* struct bdk_tns_tdma_sst_acc_cmd_s  cn88xx; */
} bdk_tns_tdma_sst_acc_cmd_t;

#define BDK_TNS_TDMA_SST_ACC_CMD BDK_TNS_TDMA_SST_ACC_CMD_FUNC()
static inline uint64_t BDK_TNS_TDMA_SST_ACC_CMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_SST_ACC_CMD_FUNC(void)
{
	return 0x0000842000000270ull;
}
#define typedef_BDK_TNS_TDMA_SST_ACC_CMD bdk_tns_tdma_sst_acc_cmd_t
#define bustype_BDK_TNS_TDMA_SST_ACC_CMD BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_SST_ACC_CMD 0
#define arguments_BDK_TNS_TDMA_SST_ACC_CMD -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_SST_ACC_CMD "TNS_TDMA_SST_ACC_CMD"


/**
 * NCB - tns_tdma_sst_acc_rdat#
 */
typedef union bdk_tns_tdma_sst_acc_rdatx {
	uint64_t u;
	struct bdk_tns_tdma_sst_acc_rdatx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< RO/H - Read data.
                                                                 Valid only if command issued was a read request and TNS_TDMA_SST_ACC_STAT[CMD_DONE] is set
                                                                 and TNS_TDMA_SST_ACC_STAT[ERROR] is clear. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_tns_tdma_sst_acc_rdatx_s cn85xx; */
	/* struct bdk_tns_tdma_sst_acc_rdatx_s cn88xx; */
} bdk_tns_tdma_sst_acc_rdatx_t;

static inline uint64_t BDK_TNS_TDMA_SST_ACC_RDATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_SST_ACC_RDATX(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000842000000480ull + (param1 & 7) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_SST_ACC_RDATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_SST_ACC_RDATX(...) bdk_tns_tdma_sst_acc_rdatx_t
#define bustype_BDK_TNS_TDMA_SST_ACC_RDATX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_SST_ACC_RDATX(p1) (p1)
#define arguments_BDK_TNS_TDMA_SST_ACC_RDATX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_SST_ACC_RDATX(...) "TNS_TDMA_SST_ACC_RDATX"


/**
 * NCB - tns_tdma_sst_acc_stat
 */
typedef union bdk_tns_tdma_sst_acc_stat {
	uint64_t u;
	struct bdk_tns_tdma_sst_acc_stat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t error                       : 1;  /**< RO/H - Command completed with error. */
		uint64_t cmd_done                    : 1;  /**< RO/H - Command issued by TNS_TDMA_SST_ACC_CMD has completed. */
#else
		uint64_t cmd_done                    : 1;
		uint64_t error                       : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_tns_tdma_sst_acc_stat_s cn85xx; */
	/* struct bdk_tns_tdma_sst_acc_stat_s cn88xx; */
} bdk_tns_tdma_sst_acc_stat_t;

#define BDK_TNS_TDMA_SST_ACC_STAT BDK_TNS_TDMA_SST_ACC_STAT_FUNC()
static inline uint64_t BDK_TNS_TDMA_SST_ACC_STAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_SST_ACC_STAT_FUNC(void)
{
	return 0x0000842000000470ull;
}
#define typedef_BDK_TNS_TDMA_SST_ACC_STAT bdk_tns_tdma_sst_acc_stat_t
#define bustype_BDK_TNS_TDMA_SST_ACC_STAT BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_SST_ACC_STAT 0
#define arguments_BDK_TNS_TDMA_SST_ACC_STAT -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_SST_ACC_STAT "TNS_TDMA_SST_ACC_STAT"


/**
 * NCB - tns_tdma_sst_acc_wdat#
 */
typedef union bdk_tns_tdma_sst_acc_wdatx {
	uint64_t u;
	struct bdk_tns_tdma_sst_acc_wdatx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Write data. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_tns_tdma_sst_acc_wdatx_s cn85xx; */
	/* struct bdk_tns_tdma_sst_acc_wdatx_s cn88xx; */
} bdk_tns_tdma_sst_acc_wdatx_t;

static inline uint64_t BDK_TNS_TDMA_SST_ACC_WDATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_SST_ACC_WDATX(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000842000000280ull + (param1 & 7) * 0x10ull;
	csr_fatal("BDK_TNS_TDMA_SST_ACC_WDATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TNS_TDMA_SST_ACC_WDATX(...) bdk_tns_tdma_sst_acc_wdatx_t
#define bustype_BDK_TNS_TDMA_SST_ACC_WDATX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_SST_ACC_WDATX(p1) (p1)
#define arguments_BDK_TNS_TDMA_SST_ACC_WDATX(p1) (p1),-1,-1,-1
#define basename_BDK_TNS_TDMA_SST_ACC_WDATX(...) "TNS_TDMA_SST_ACC_WDATX"


/**
 * NCB - tns_tdma_status
 */
typedef union bdk_tns_tdma_status {
	uint64_t u;
	struct bdk_tns_tdma_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t pcc_busy                    : 1;  /**< RO/H - When 1, indicates the PCC MSI-X table is currently in-use by hardware.
                                                                 CSR and memory transactions are prohibited until this bit becomes 0.
                                                                 Upon power-on this bit will be 1 as the PCC performs auto-initialization. */
#else
		uint64_t pcc_busy                    : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_tns_tdma_status_s       cn85xx; */
	/* struct bdk_tns_tdma_status_s       cn88xx; */
} bdk_tns_tdma_status_t;

#define BDK_TNS_TDMA_STATUS BDK_TNS_TDMA_STATUS_FUNC()
static inline uint64_t BDK_TNS_TDMA_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TDMA_STATUS_FUNC(void)
{
	return 0x0000842000000410ull;
}
#define typedef_BDK_TNS_TDMA_STATUS bdk_tns_tdma_status_t
#define bustype_BDK_TNS_TDMA_STATUS BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TDMA_STATUS 0
#define arguments_BDK_TNS_TDMA_STATUS -1,-1,-1,-1
#define basename_BDK_TNS_TDMA_STATUS "TNS_TDMA_STATUS"


/**
 * NCB - tns_txq_eq_cfg_spare
 *
 * Spare register with default signature value 0x210FEDCBA9876543 after reset.
 *
 */
typedef union bdk_tns_txq_eq_cfg_spare {
	uint64_t u;
	struct bdk_tns_txq_eq_cfg_spare_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t spare_x1                    : 32; /**< R/W - Spare field high. */
		uint64_t spare_x0                    : 32; /**< R/W - Spare field low. */
#else
		uint64_t spare_x0                    : 32;
		uint64_t spare_x1                    : 32;
#endif
	} s;
	/* struct bdk_tns_txq_eq_cfg_spare_s  cn85xx; */
	/* struct bdk_tns_txq_eq_cfg_spare_s  cn88xx; */
} bdk_tns_txq_eq_cfg_spare_t;

#define BDK_TNS_TXQ_EQ_CFG_SPARE BDK_TNS_TXQ_EQ_CFG_SPARE_FUNC()
static inline uint64_t BDK_TNS_TXQ_EQ_CFG_SPARE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TNS_TXQ_EQ_CFG_SPARE_FUNC(void)
{
	return 0x0000842078E84910ull;
}
#define typedef_BDK_TNS_TXQ_EQ_CFG_SPARE bdk_tns_txq_eq_cfg_spare_t
#define bustype_BDK_TNS_TXQ_EQ_CFG_SPARE BDK_CSR_TYPE_NCB
#define busnum_BDK_TNS_TXQ_EQ_CFG_SPARE 0
#define arguments_BDK_TNS_TXQ_EQ_CFG_SPARE -1,-1,-1,-1
#define basename_BDK_TNS_TXQ_EQ_CFG_SPARE "TNS_TXQ_EQ_CFG_SPARE"

#endif /* __BDK_CSRS_TNS__ */
