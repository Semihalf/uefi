#ifndef __BDK_CSRS_SLI__
#define __BDK_CSRS_SLI__
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
 * Cavium SLI.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration SLI_INT_VEC_E
 *
 * SLI MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum sli_int_vec_e {
	SLI_INT_VEC_E_MAC0 = 0x1,
	SLI_INT_VEC_E_MAC1 = 0x2,
	SLI_INT_VEC_E_MAC2 = 0x3,
	SLI_INT_VEC_E_MBE = 0x0,
	SLI_INT_VEC_E_ENUM_LAST = 0x4,
};


/**
 * Structure SLI_S2M_OP_S
 *
 * SLI to MAC Operation Structure
 * Core initiated load and store operations that are initiating MAC transactions form an address
 * with this structure. 8-bit, 16-bit, 32-bit and 64-bit reads and writes, in addition to atomics
 * are supported to this region.
 */
union sli_s2m_op_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16; /**< [ 63: 48] Reserved */
		uint64_t io                          : 1;  /**< [ 47: 47] Indicates IO space. */
		uint64_t reserved_46_46              : 1;  /**< [ 46: 46] Reserved. */
		uint64_t node                        : 2;  /**< [ 45: 44] CCPI node number. */
		uint64_t did_hi                      : 4;  /**< [ 43: 40] SLI device ID high bits.  Specifies which SLI:
                                                                 0x8 = SLI0.
                                                                 0x9 = SLI1.

                                                                 else = Reserved. */
		uint64_t region                      : 8;  /**< [ 39: 32] SLI region.  Indexes into SLI(0..1)_S2M_REG(0..255)_ACC. */
		uint64_t addr                        : 32; /**< [ 31:  0] Register address within the device. */
#else
		uint64_t addr                        : 32; /**< [ 31:  0] Register address within the device. */
		uint64_t region                      : 8;  /**< [ 39: 32] SLI region.  Indexes into SLI(0..1)_S2M_REG(0..255)_ACC. */
		uint64_t did_hi                      : 4;  /**< [ 43: 40] SLI device ID high bits.  Specifies which SLI:
                                                                 0x8 = SLI0.
                                                                 0x9 = SLI1.

                                                                 else = Reserved. */
		uint64_t node                        : 2;  /**< [ 45: 44] CCPI node number. */
		uint64_t reserved_46_46              : 1;  /**< [ 46: 46] Reserved. */
		uint64_t io                          : 1;  /**< [ 47: 47] Indicates IO space. */
		uint64_t reserved_48_63              : 16; /**< [ 63: 48] Reserved */
#endif
	} s;
};


/**
 * NCB - sli#_bist_status
 *
 * This register contains results from BIST runs of MAC's memories: 0 = pass (or BIST in
 * progress/never run), 1 = fail.
 */
typedef union bdk_slix_bist_status {
	uint64_t u;
	struct bdk_slix_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_23_63              : 41;
		uint64_t status                      : 23; /**< RO - BIST status. INTERNAL:
                                                                 22 = sli_nod_nfif_bstatus.
                                                                 21 = csr_region_mem_bstatus.
                                                                 20 = sncf0_ffifo_bstatus.
                                                                 19 = sndfh0_ffifo_bstatus.
                                                                 18 = sndfl0_ffifo_bstatus.
                                                                 17 = sncf1_ffifo_bstatus.
                                                                 16 = sndfh1_ffifo_bstatus.
                                                                 15 = sndfl1_ffifo_bstatus.
                                                                 14 = sncf2_ffifo_bstatus.
                                                                 13 = sndfh2_ffifo_bstatus.
                                                                 12 = sndfl2_ffifo_bstatus.
                                                                 11 = p2n_port0_tlp_cpl_fifo_bstatus.
                                                                 10 = p2n_port0_tlp_n_fifo_bstatus.
                                                                 9 = p2n_port0_tlp_p_fifo_bstatus.
                                                                 8 = p2n_port1_tlp_cpl_fifo_bstatus.
                                                                 7 = p2n_port1_tlp_n_fifo_bstatus.
                                                                 6 = p2n_port1_tlp_p_fifo_bstatus.
                                                                 5 = p2n_port2_tlp_cpl_fifo_bstatus.
                                                                 4 = p2n_port2_tlp_n_fifo_bstatus.
                                                                 3 = p2n_port2_tlp_p_fifo_bstatus.
                                                                 2 = cpl0_fifo_bstatus.
                                                                 1 = cpl1_fifo_bstatus.
                                                                 0 = cpl2_fifo_bstatus. */
#else
		uint64_t status                      : 23;
		uint64_t reserved_23_63              : 41;
#endif
	} s;
	/* struct bdk_slix_bist_status_s      cn88xx; */
	/* struct bdk_slix_bist_status_s      cn88xxp1; */
} bdk_slix_bist_status_t;

static inline uint64_t BDK_SLIX_BIST_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_BIST_STATUS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000874001002180ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_SLIX_BIST_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_BIST_STATUS(...) bdk_slix_bist_status_t
#define bustype_BDK_SLIX_BIST_STATUS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_BIST_STATUS(p1) (p1)
#define arguments_BDK_SLIX_BIST_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_BIST_STATUS(...) "SLIX_BIST_STATUS"


/**
 * PEXP_NCB - sli#_data_out_cnt#
 *
 * This register contains the EXEC data out FIFO count and the data unload counter.
 *
 */
typedef union bdk_slix_data_out_cntx {
	uint64_t u;
	struct bdk_slix_data_out_cntx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t ucnt                        : 16; /**< RO/H - FIFO unload count. This counter is incremented by 1 every time a word is removed from
                                                                 data out FIFO, whose count is shown in [FCNT]. */
		uint64_t reserved_6_7                : 2;
		uint64_t fcnt                        : 6;  /**< RO/H - FIFO data out count. Number of address data words presently buffered in the FIFO. */
#else
		uint64_t fcnt                        : 6;
		uint64_t reserved_6_7                : 2;
		uint64_t ucnt                        : 16;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_slix_data_out_cntx_s    cn88xx; */
	/* struct bdk_slix_data_out_cntx_s    cn88xxp1; */
} bdk_slix_data_out_cntx_t;

static inline uint64_t BDK_SLIX_DATA_OUT_CNTX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_DATA_OUT_CNTX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 2)))
		return 0x0000874000001080ull + (param1 & 1) * 0x1000000000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_SLIX_DATA_OUT_CNTX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_DATA_OUT_CNTX(...) bdk_slix_data_out_cntx_t
#define bustype_BDK_SLIX_DATA_OUT_CNTX(...) BDK_CSR_TYPE_PEXP_NCB
#define busnum_BDK_SLIX_DATA_OUT_CNTX(p1,p2) (p1)
#define arguments_BDK_SLIX_DATA_OUT_CNTX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SLIX_DATA_OUT_CNTX(...) "SLIX_DATA_OUT_CNTX"


/**
 * NCB - sli#_end_merge
 *
 * Writing this register will cause a merge to end.
 *
 */
typedef union bdk_slix_end_merge {
	uint64_t u;
	struct bdk_slix_end_merge_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_slix_end_merge_s        cn88xx; */
	/* struct bdk_slix_end_merge_s        cn88xxp1; */
} bdk_slix_end_merge_t;

static inline uint64_t BDK_SLIX_END_MERGE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_END_MERGE(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000874001002300ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_SLIX_END_MERGE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_END_MERGE(...) bdk_slix_end_merge_t
#define bustype_BDK_SLIX_END_MERGE(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_END_MERGE(p1) (p1)
#define arguments_BDK_SLIX_END_MERGE(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_END_MERGE(...) "SLIX_END_MERGE"


/**
 * NCB - sli#_m2s_mac#_ctl
 *
 * This register controls the functionality of the SLI's M2S in regards to a MAC.
 * INTERNAL: In 78xx was SLI(0..1)_CTL_PORT(0..2) and SLI(0..1)_S2M_PORT(0..2)_CTL.
 */
typedef union bdk_slix_m2s_macx_ctl {
	uint64_t u;
	struct bdk_slix_m2s_macx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_19_63              : 45;
		uint64_t wvirt                       : 1;  /**< R/W - Write virtual:
                                                                 1 = Addresses in SLI()_WIN_WR_ADDR and SLI()_WIN_RD_ADDR are virtual addresses.
                                                                 0 = Addresses are physical addresses. */
		uint64_t dis_port                    : 1;  /**< R/W1C/H - When set, the output to the MAC is disabled. This occurs when the MAC reset line
                                                                 transitions from de-asserted to asserted. Writing a 1 to this location clears this
                                                                 condition when the MAC is no longer in reset and the output to the MAC is at the beginning
                                                                 of a transfer. */
		uint64_t waitl_com                   : 1;  /**< R/W - When set, causes the SLI to wait for a store done from the L2C for any previously sent
                                                                 stores,
                                                                 before sending additional completions to the L2C from the MAC.
                                                                 Set this for more conservative behavior. Clear this for more aggressive, higher-
                                                                 performance behavior. */
		uint64_t reserved_7_15               : 9;
		uint64_t ctlp_ro                     : 1;  /**< R/W - Relaxed ordering enable for completion TLPS. This permits the SLI to use the RO bit sent
                                                                 from
                                                                 the MACs. See WAITL_COM. */
		uint64_t ptlp_ro                     : 1;  /**< R/W - Relaxed ordering enable for posted TLPS. This permitsthe SLI to use the RO bit sent from
                                                                 the MACs. See WAIT_COM. */
		uint64_t wind_d                      : 1;  /**< R/W - Window disable. When set, disables access to the window registers from the MAC. */
		uint64_t bar0_d                      : 1;  /**< R/W - BAR0 disable. When set, disables access from the MAC to SLI BAR0 registers. */
		uint64_t ld_cmd                      : 2;  /**< R/W - When SLI issues a load command to the L2C that is to be cached, this field selects the
                                                                 type of load command to use. Un-cached loads will use LDT:
                                                                 0 = LDD.
                                                                 1 = LDI.
                                                                 2 = LDE.
                                                                 3 = LDY. */
		uint64_t wait_com                    : 1;  /**< R/W - Wait for commit. When set, causes the SLI to wait for a store done from the L2C before
                                                                 sending additional stores to the L2C from the MAC. The SLI requests a commit on the last
                                                                 store if more than one STORE operation is required on the NCB. Most applications will not
                                                                 notice a difference, so this bit should not be set. Setting the bit is more conservative
                                                                 on ordering, lower performance. */
#else
		uint64_t wait_com                    : 1;
		uint64_t ld_cmd                      : 2;
		uint64_t bar0_d                      : 1;
		uint64_t wind_d                      : 1;
		uint64_t ptlp_ro                     : 1;
		uint64_t ctlp_ro                     : 1;
		uint64_t reserved_7_15               : 9;
		uint64_t waitl_com                   : 1;
		uint64_t dis_port                    : 1;
		uint64_t wvirt                       : 1;
		uint64_t reserved_19_63              : 45;
#endif
	} s;
	/* struct bdk_slix_m2s_macx_ctl_s     cn88xx; */
	/* struct bdk_slix_m2s_macx_ctl_s     cn88xxp1; */
} bdk_slix_m2s_macx_ctl_t;

static inline uint64_t BDK_SLIX_M2S_MACX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_M2S_MACX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 2)))
		return 0x0000874001002100ull + (param1 & 1) * 0x1000000000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_SLIX_M2S_MACX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_M2S_MACX_CTL(...) bdk_slix_m2s_macx_ctl_t
#define bustype_BDK_SLIX_M2S_MACX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_M2S_MACX_CTL(p1,p2) (p1)
#define arguments_BDK_SLIX_M2S_MACX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SLIX_M2S_MACX_CTL(...) "SLIX_M2S_MACX_CTL"


/**
 * PEXP_NCB - sli#_mac#_int_ena_w1c
 */
typedef union bdk_slix_macx_int_ena_w1c {
	uint64_t u;
	struct bdk_slix_macx_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t un_wi                       : 1;  /**< R/W1C/H - Received unsupported N-TLP for window register from MAC(0..2). This occurs when the window
                                                                 registers are disabled and a window register access occurs. */
		uint64_t un_b0                       : 1;  /**< R/W1C/H - Received unsupported N-TLP for Bar 0 from MAC(0..2). This occurs when the BAR 0 address
                                                                 space is disabled. */
		uint64_t up_wi                       : 1;  /**< R/W1C/H - Received unsupported P-TLP for window register from MAC(0..2). This occurs when the window
                                                                 registers are disabled and a window register access occurs. */
		uint64_t up_b0                       : 1;  /**< R/W1C/H - Received unsupported P-TLP for Bar 0 from MAC(0..2). This occurs when the BAR 0 address
                                                                 space is disabled. */
#else
		uint64_t up_b0                       : 1;
		uint64_t up_wi                       : 1;
		uint64_t un_b0                       : 1;
		uint64_t un_wi                       : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_slix_macx_int_ena_w1c_s cn88xx; */
	/* struct bdk_slix_macx_int_ena_w1c_s cn88xxp1; */
} bdk_slix_macx_int_ena_w1c_t;

static inline uint64_t BDK_SLIX_MACX_INT_ENA_W1C(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_MACX_INT_ENA_W1C(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 2)))
		return 0x0000874000001200ull + (param1 & 1) * 0x1000000000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_SLIX_MACX_INT_ENA_W1C", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_MACX_INT_ENA_W1C(...) bdk_slix_macx_int_ena_w1c_t
#define bustype_BDK_SLIX_MACX_INT_ENA_W1C(...) BDK_CSR_TYPE_PEXP_NCB
#define busnum_BDK_SLIX_MACX_INT_ENA_W1C(p1,p2) (p1)
#define arguments_BDK_SLIX_MACX_INT_ENA_W1C(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SLIX_MACX_INT_ENA_W1C(...) "SLIX_MACX_INT_ENA_W1C"


/**
 * PEXP_NCB - sli#_mac#_int_ena_w1s
 */
typedef union bdk_slix_macx_int_ena_w1s {
	uint64_t u;
	struct bdk_slix_macx_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t un_wi                       : 1;  /**< R/W1C/H - Received unsupported N-TLP for window register from MAC(0..2). This occurs when the window
                                                                 registers are disabled and a window register access occurs. */
		uint64_t un_b0                       : 1;  /**< R/W1C/H - Received unsupported N-TLP for Bar 0 from MAC(0..2). This occurs when the BAR 0 address
                                                                 space is disabled. */
		uint64_t up_wi                       : 1;  /**< R/W1C/H - Received unsupported P-TLP for window register from MAC(0..2). This occurs when the window
                                                                 registers are disabled and a window register access occurs. */
		uint64_t up_b0                       : 1;  /**< R/W1C/H - Received unsupported P-TLP for Bar 0 from MAC(0..2). This occurs when the BAR 0 address
                                                                 space is disabled. */
#else
		uint64_t up_b0                       : 1;
		uint64_t up_wi                       : 1;
		uint64_t un_b0                       : 1;
		uint64_t un_wi                       : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_slix_macx_int_ena_w1s_s cn88xx; */
	/* struct bdk_slix_macx_int_ena_w1s_s cn88xxp1; */
} bdk_slix_macx_int_ena_w1s_t;

static inline uint64_t BDK_SLIX_MACX_INT_ENA_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_MACX_INT_ENA_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 2)))
		return 0x0000874000001280ull + (param1 & 1) * 0x1000000000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_SLIX_MACX_INT_ENA_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_MACX_INT_ENA_W1S(...) bdk_slix_macx_int_ena_w1s_t
#define bustype_BDK_SLIX_MACX_INT_ENA_W1S(...) BDK_CSR_TYPE_PEXP_NCB
#define busnum_BDK_SLIX_MACX_INT_ENA_W1S(p1,p2) (p1)
#define arguments_BDK_SLIX_MACX_INT_ENA_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SLIX_MACX_INT_ENA_W1S(...) "SLIX_MACX_INT_ENA_W1S"


/**
 * PEXP_NCB - sli#_mac#_int_sum
 *
 * This register contains the different interrupt-summary bits for one MAC in the SLI.
 *
 */
typedef union bdk_slix_macx_int_sum {
	uint64_t u;
	struct bdk_slix_macx_int_sum_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t un_wi                       : 1;  /**< R/W1C/H - Received unsupported N-TLP for window register from MAC(0..2). This occurs when the window
                                                                 registers are disabled and a window register access occurs. */
		uint64_t un_b0                       : 1;  /**< R/W1C/H - Received unsupported N-TLP for Bar 0 from MAC(0..2). This occurs when the BAR 0 address
                                                                 space is disabled. */
		uint64_t up_wi                       : 1;  /**< R/W1C/H - Received unsupported P-TLP for window register from MAC(0..2). This occurs when the window
                                                                 registers are disabled and a window register access occurs. */
		uint64_t up_b0                       : 1;  /**< R/W1C/H - Received unsupported P-TLP for Bar 0 from MAC(0..2). This occurs when the BAR 0 address
                                                                 space is disabled. */
#else
		uint64_t up_b0                       : 1;
		uint64_t up_wi                       : 1;
		uint64_t un_b0                       : 1;
		uint64_t un_wi                       : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_slix_macx_int_sum_s     cn88xx; */
	/* struct bdk_slix_macx_int_sum_s     cn88xxp1; */
} bdk_slix_macx_int_sum_t;

static inline uint64_t BDK_SLIX_MACX_INT_SUM(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_MACX_INT_SUM(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 2)))
		return 0x0000874000001100ull + (param1 & 1) * 0x1000000000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_SLIX_MACX_INT_SUM", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_MACX_INT_SUM(...) bdk_slix_macx_int_sum_t
#define bustype_BDK_SLIX_MACX_INT_SUM(...) BDK_CSR_TYPE_PEXP_NCB
#define busnum_BDK_SLIX_MACX_INT_SUM(p1,p2) (p1)
#define arguments_BDK_SLIX_MACX_INT_SUM(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SLIX_MACX_INT_SUM(...) "SLIX_MACX_INT_SUM"


/**
 * PEXP_NCB - sli#_mac#_int_sum_w1s
 */
typedef union bdk_slix_macx_int_sum_w1s {
	uint64_t u;
	struct bdk_slix_macx_int_sum_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t un_wi                       : 1;  /**< R/W1C/H - Received unsupported N-TLP for window register from MAC(0..2). This occurs when the window
                                                                 registers are disabled and a window register access occurs. */
		uint64_t un_b0                       : 1;  /**< R/W1C/H - Received unsupported N-TLP for Bar 0 from MAC(0..2). This occurs when the BAR 0 address
                                                                 space is disabled. */
		uint64_t up_wi                       : 1;  /**< R/W1C/H - Received unsupported P-TLP for window register from MAC(0..2). This occurs when the window
                                                                 registers are disabled and a window register access occurs. */
		uint64_t up_b0                       : 1;  /**< R/W1C/H - Received unsupported P-TLP for Bar 0 from MAC(0..2). This occurs when the BAR 0 address
                                                                 space is disabled. */
#else
		uint64_t up_b0                       : 1;
		uint64_t up_wi                       : 1;
		uint64_t un_b0                       : 1;
		uint64_t un_wi                       : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_slix_macx_int_sum_w1s_s cn88xx; */
	/* struct bdk_slix_macx_int_sum_w1s_s cn88xxp1; */
} bdk_slix_macx_int_sum_w1s_t;

static inline uint64_t BDK_SLIX_MACX_INT_SUM_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_MACX_INT_SUM_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 2)))
		return 0x0000874000001180ull + (param1 & 1) * 0x1000000000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_SLIX_MACX_INT_SUM_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_MACX_INT_SUM_W1S(...) bdk_slix_macx_int_sum_w1s_t
#define bustype_BDK_SLIX_MACX_INT_SUM_W1S(...) BDK_CSR_TYPE_PEXP_NCB
#define busnum_BDK_SLIX_MACX_INT_SUM_W1S(p1,p2) (p1)
#define arguments_BDK_SLIX_MACX_INT_SUM_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SLIX_MACX_INT_SUM_W1S(...) "SLIX_MACX_INT_SUM_W1S"


/**
 * PEXP - sli#_mac_number
 *
 * When read from a MAC, this register returns the MAC's port number, otherwise returns zero.
 *
 */
typedef union bdk_slix_mac_number {
	uint64_t u;
	struct bdk_slix_mac_number_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t chip_rev                    : 8;  /**< RO/H - Chip revision level. */
		uint64_t reserved_20_23              : 4;
		uint64_t oci_id                      : 4;  /**< RO - The CCPI node ID. */
		uint64_t reserved_9_15               : 7;
		uint64_t a_mode                      : 1;  /**< RO/H - Trusted mode.  See RST_BOOT[TRUSTED_MODE]. */
		uint64_t num                         : 8;  /**< RO/H - MAC number. */
#else
		uint64_t num                         : 8;
		uint64_t a_mode                      : 1;
		uint64_t reserved_9_15               : 7;
		uint64_t oci_id                      : 4;
		uint64_t reserved_20_23              : 4;
		uint64_t chip_rev                    : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_slix_mac_number_s       cn88xx; */
	/* struct bdk_slix_mac_number_s       cn88xxp1; */
} bdk_slix_mac_number_t;

static inline uint64_t BDK_SLIX_MAC_NUMBER(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_MAC_NUMBER(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000000000000080ull + (param1 & 1) * 0x10000000000ull;
	csr_fatal("BDK_SLIX_MAC_NUMBER", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_MAC_NUMBER(...) bdk_slix_mac_number_t
#define bustype_BDK_SLIX_MAC_NUMBER(...) BDK_CSR_TYPE_PEXP
#define busnum_BDK_SLIX_MAC_NUMBER(p1) (p1)
#define arguments_BDK_SLIX_MAC_NUMBER(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_MAC_NUMBER(...) "SLIX_MAC_NUMBER"


/**
 * NCB - sli#_mbe_int_ena_w1c
 */
typedef union bdk_slix_mbe_int_ena_w1c {
	uint64_t u;
	struct bdk_slix_mbe_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_54_63              : 10;
		uint64_t sed0_dbe                    : 22; /**< R/W1C/H - SED0 double-bit error. When set, a SED0 double-bit error has occurred. */
		uint64_t reserved_22_31              : 10;
		uint64_t sed0_sbe                    : 22; /**< R/W1C/H - SED0 single-bit error. When set, a SED0 single-bit error has occurred. */
#else
		uint64_t sed0_sbe                    : 22;
		uint64_t reserved_22_31              : 10;
		uint64_t sed0_dbe                    : 22;
		uint64_t reserved_54_63              : 10;
#endif
	} s;
	/* struct bdk_slix_mbe_int_ena_w1c_s  cn88xx; */
	/* struct bdk_slix_mbe_int_ena_w1c_s  cn88xxp1; */
} bdk_slix_mbe_int_ena_w1c_t;

static inline uint64_t BDK_SLIX_MBE_INT_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_MBE_INT_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000874001002260ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_SLIX_MBE_INT_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_MBE_INT_ENA_W1C(...) bdk_slix_mbe_int_ena_w1c_t
#define bustype_BDK_SLIX_MBE_INT_ENA_W1C(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_MBE_INT_ENA_W1C(p1) (p1)
#define arguments_BDK_SLIX_MBE_INT_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_MBE_INT_ENA_W1C(...) "SLIX_MBE_INT_ENA_W1C"


/**
 * NCB - sli#_mbe_int_ena_w1s
 */
typedef union bdk_slix_mbe_int_ena_w1s {
	uint64_t u;
	struct bdk_slix_mbe_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_54_63              : 10;
		uint64_t sed0_dbe                    : 22; /**< R/W1C/H - SED0 double-bit error. When set, a SED0 double-bit error has occurred. */
		uint64_t reserved_22_31              : 10;
		uint64_t sed0_sbe                    : 22; /**< R/W1C/H - SED0 single-bit error. When set, a SED0 single-bit error has occurred. */
#else
		uint64_t sed0_sbe                    : 22;
		uint64_t reserved_22_31              : 10;
		uint64_t sed0_dbe                    : 22;
		uint64_t reserved_54_63              : 10;
#endif
	} s;
	/* struct bdk_slix_mbe_int_ena_w1s_s  cn88xx; */
	/* struct bdk_slix_mbe_int_ena_w1s_s  cn88xxp1; */
} bdk_slix_mbe_int_ena_w1s_t;

static inline uint64_t BDK_SLIX_MBE_INT_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_MBE_INT_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000874001002280ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_SLIX_MBE_INT_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_MBE_INT_ENA_W1S(...) bdk_slix_mbe_int_ena_w1s_t
#define bustype_BDK_SLIX_MBE_INT_ENA_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_MBE_INT_ENA_W1S(p1) (p1)
#define arguments_BDK_SLIX_MBE_INT_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_MBE_INT_ENA_W1S(...) "SLIX_MBE_INT_ENA_W1S"


/**
 * NCB - sli#_mbe_int_sum
 *
 * This register contains the MBE interrupt-summary bits of the SLI.
 *
 */
typedef union bdk_slix_mbe_int_sum {
	uint64_t u;
	struct bdk_slix_mbe_int_sum_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_54_63              : 10;
		uint64_t sed0_dbe                    : 22; /**< R/W1C/H - SED0 double-bit error. When set, a SED0 double-bit error has occurred. */
		uint64_t reserved_22_31              : 10;
		uint64_t sed0_sbe                    : 22; /**< R/W1C/H - SED0 single-bit error. When set, a SED0 single-bit error has occurred. */
#else
		uint64_t sed0_sbe                    : 22;
		uint64_t reserved_22_31              : 10;
		uint64_t sed0_dbe                    : 22;
		uint64_t reserved_54_63              : 10;
#endif
	} s;
	/* struct bdk_slix_mbe_int_sum_s      cn88xx; */
	/* struct bdk_slix_mbe_int_sum_s      cn88xxp1; */
} bdk_slix_mbe_int_sum_t;

static inline uint64_t BDK_SLIX_MBE_INT_SUM(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_MBE_INT_SUM(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000874001002220ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_SLIX_MBE_INT_SUM", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_MBE_INT_SUM(...) bdk_slix_mbe_int_sum_t
#define bustype_BDK_SLIX_MBE_INT_SUM(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_MBE_INT_SUM(p1) (p1)
#define arguments_BDK_SLIX_MBE_INT_SUM(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_MBE_INT_SUM(...) "SLIX_MBE_INT_SUM"


/**
 * NCB - sli#_mbe_int_sum_w1s
 */
typedef union bdk_slix_mbe_int_sum_w1s {
	uint64_t u;
	struct bdk_slix_mbe_int_sum_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_54_63              : 10;
		uint64_t sed0_dbe                    : 22; /**< R/W1C/H - SED0 double-bit error. When set, a SED0 double-bit error has occurred. */
		uint64_t reserved_22_31              : 10;
		uint64_t sed0_sbe                    : 22; /**< R/W1C/H - SED0 single-bit error. When set, a SED0 single-bit error has occurred. */
#else
		uint64_t sed0_sbe                    : 22;
		uint64_t reserved_22_31              : 10;
		uint64_t sed0_dbe                    : 22;
		uint64_t reserved_54_63              : 10;
#endif
	} s;
	/* struct bdk_slix_mbe_int_sum_w1s_s  cn88xx; */
	/* struct bdk_slix_mbe_int_sum_w1s_s  cn88xxp1; */
} bdk_slix_mbe_int_sum_w1s_t;

static inline uint64_t BDK_SLIX_MBE_INT_SUM_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_MBE_INT_SUM_W1S(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000874001002240ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_SLIX_MBE_INT_SUM_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_MBE_INT_SUM_W1S(...) bdk_slix_mbe_int_sum_w1s_t
#define bustype_BDK_SLIX_MBE_INT_SUM_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_MBE_INT_SUM_W1S(p1) (p1)
#define arguments_BDK_SLIX_MBE_INT_SUM_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_MBE_INT_SUM_W1S(...) "SLIX_MBE_INT_SUM_W1S"


/**
 * NCB - sli#_mem_ctl
 *
 * This register controls the ECC of the SLI memories.
 *
 */
typedef union bdk_slix_mem_ctl {
	uint64_t u;
	struct bdk_slix_mem_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_30_63              : 34;
		uint64_t ctl                         : 30; /**< R/W - Control memory ECC functionality.
                                                                 \<29\>    = Correction Disable for csr_region_mem_csr_cor_dis.
                                                                 \<28:29\> = Flip Syndrome for csr_region_mem_csr_flip_synd.

                                                                 \<26\>    = Correction Disable for sndf\<h,l\>2_ffifo, sncf2_ffifo_csr_cor_dis.
                                                                 \<25:24\> = Flip Syndrome for sndf\<h,l\>2_ffifo, sncf2_ffifo_csr_flip_synd.
                                                                 \<23\>    = Correction Disable for sndf\<h,l\>2_ffifo, sncf2_ffifo_csr_cor_dis.
                                                                 \<22:21\> = Flip Syndrome for sndf\<h,l\>2_ffifo, sncf2_ffifo_csr_flip_synd.
                                                                 \<20\>    = Correction Disable for sndf\<h,l\>2_ffifo, sncf2_ffifo_csr_cor_dis.
                                                                 \<19:18\> = Flip Syndrome for sndf\<h,l\>2_ffifo, sncf2_ffifo_csr_flip_synd.

                                                                 \<17\>    = Correction Disable for cpl0_fifo_csr_cor_dis.
                                                                 \<16:15\> = Flip Syndrome for cpl0_fifo_csr_flip_synd.
                                                                 \<14\>    = Correction Disable for cpl1_fifo_csr_cor_dis.
                                                                 \<13:12\> = Flip Syndrome for cpl1_fifo_csr_flip_synd.
                                                                 \<11\>    = Correction Disable for cpl2_fifo_csr_cor_dis.
                                                                 \<10:9\>  = Flip Syndrome for cpl2_fifo_csr_flip_synd.

                                                                 \<8\>   = Correction Disable for p2n0_tlp_\<p, n, cpl\>_fifo.
                                                                 \<7:6\> = Flip Syndrome for p2n0_tlp_\<p,n,cpl\>_fifo.
                                                                 \<5\>   = Correction Disable for p2n1_tlp_\<p, n, cpl\>_fifo.
                                                                 \<4:3\> = Flip Syndrome for p2n1_tlp_\<p,n,cpl\>_fifo.
                                                                 \<2\>   = Correction Disable for p2n2_tlp_\<p, n, cpl\>_fifo.
                                                                 \<1:0\> = Flip Syndrome for p2n2_tlp_\<p,n,cpl\>_fifo. */
#else
		uint64_t ctl                         : 30;
		uint64_t reserved_30_63              : 34;
#endif
	} s;
	/* struct bdk_slix_mem_ctl_s          cn88xx; */
	/* struct bdk_slix_mem_ctl_s          cn88xxp1; */
} bdk_slix_mem_ctl_t;

static inline uint64_t BDK_SLIX_MEM_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_MEM_CTL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000874001002200ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_SLIX_MEM_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_MEM_CTL(...) bdk_slix_mem_ctl_t
#define bustype_BDK_SLIX_MEM_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_MEM_CTL(p1) (p1)
#define arguments_BDK_SLIX_MEM_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_MEM_CTL(...) "SLIX_MEM_CTL"


/**
 * NCB - sli#_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the SLI_INT_VEC_E enumeration.
 *
 */
typedef union bdk_slix_msix_pbax {
	uint64_t u;
	struct bdk_slix_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated SLI_MSIX_VEC()_CTL, enumerated by SLI_INT_VEC_E. Bits
                                                                 that have no associated SLI_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_slix_msix_pbax_s        cn88xx; */
	/* struct bdk_slix_msix_pbax_s        cn88xxp1; */
} bdk_slix_msix_pbax_t;

static inline uint64_t BDK_SLIX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x00008740100F0000ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_SLIX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_MSIX_PBAX(...) bdk_slix_msix_pbax_t
#define bustype_BDK_SLIX_MSIX_PBAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_SLIX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SLIX_MSIX_PBAX(...) "SLIX_MSIX_PBAX"


/**
 * NCB - sli#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the SLI_INT_VEC_E enumeration.
 *
 */
typedef union bdk_slix_msix_vecx_addr {
	uint64_t u;
	struct bdk_slix_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's SLI_MSIX_VEC()_ADDR, SLI_MSIX_VEC()_CTL, and corresponding
                                                                 bit of SLI_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_SLI_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_slix_msix_vecx_addr_s   cn88xx; */
	/* struct bdk_slix_msix_vecx_addr_s   cn88xxp1; */
} bdk_slix_msix_vecx_addr_t;

static inline uint64_t BDK_SLIX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x0000874010000000ull + (param1 & 1) * 0x1000000000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_SLIX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_MSIX_VECX_ADDR(...) bdk_slix_msix_vecx_addr_t
#define bustype_BDK_SLIX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_SLIX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SLIX_MSIX_VECX_ADDR(...) "SLIX_MSIX_VECX_ADDR"


/**
 * NCB - sli#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the SLI_INT_VEC_E enumeration.
 *
 */
typedef union bdk_slix_msix_vecx_ctl {
	uint64_t u;
	struct bdk_slix_msix_vecx_ctl_s {
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
	/* struct bdk_slix_msix_vecx_ctl_s    cn88xx; */
	/* struct bdk_slix_msix_vecx_ctl_s    cn88xxp1; */
} bdk_slix_msix_vecx_ctl_t;

static inline uint64_t BDK_SLIX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x0000874010000008ull + (param1 & 1) * 0x1000000000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_SLIX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_MSIX_VECX_CTL(...) bdk_slix_msix_vecx_ctl_t
#define bustype_BDK_SLIX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_SLIX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SLIX_MSIX_VECX_CTL(...) "SLIX_MSIX_VECX_CTL"


/**
 * NCB - sli#_s2m_ctl
 *
 * This register contains control functionality of the S2M attached to the SLI. This register
 * impacts all MACs attached to the S2M.
 */
typedef union bdk_slix_s2m_ctl {
	uint64_t u;
	struct bdk_slix_s2m_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t max_word                    : 4;  /**< R/W - Maximum number of words. Specifies the maximum number of 8-byte words to merge into a
                                                                 single write operation from the cores to the MAC. Legal values are 1 to 8, with 0 treated
                                                                 as 16. */
		uint64_t timer                       : 10; /**< R/W - Merge timer. When the SLI starts a core-to-MAC write, TIMER specifies the maximum wait, in
                                                                 coprocessor-clock cycles, to merge additional write operations from the cores into one
                                                                 large write. The values for this field range from 1 to 1024, with 0 treated as 1024. */
#else
		uint64_t timer                       : 10;
		uint64_t max_word                    : 4;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_slix_s2m_ctl_s          cn88xx; */
	/* struct bdk_slix_s2m_ctl_s          cn88xxp1; */
} bdk_slix_s2m_ctl_t;

static inline uint64_t BDK_SLIX_S2M_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_S2M_CTL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000874001002000ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_SLIX_S2M_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_S2M_CTL(...) bdk_slix_s2m_ctl_t
#define bustype_BDK_SLIX_S2M_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_S2M_CTL(p1) (p1)
#define arguments_BDK_SLIX_S2M_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_S2M_CTL(...) "SLIX_S2M_CTL"


/**
 * NCB - sli#_s2m_mac#_ctl
 *
 * This register controls the functionality of the SLI's S2M in regards to a MAC.
 * INTERNAL: In 78xx was SLI(0..1)_CTL_STATUS and SLI(0..1)_MAC_CREDIT_CNT.
 */
typedef union bdk_slix_s2m_macx_ctl {
	uint64_t u;
	struct bdk_slix_s2m_macx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t ccnt                        : 8;  /**< R/W/H - CPL-TLP FIFO credits. Legal values are 0x25 to 0x80. For diagnostic use only. */
		uint64_t ncnt                        : 8;  /**< R/W/H - NP-TLP FIFO credits. Legal values are 0x5 to 0x10. For diagnostic use only. */
		uint64_t pcnt                        : 8;  /**< R/W/H - P-TLP FIFO credits. Legal values are 0x25 to 0x80. For diagnostic use only. */
		uint64_t tags                        : 8;  /**< R/W/H - Number of tags available for MAC.
                                                                 One tag is needed for each outbound TLP that requires a CPL TLP.
                                                                 This field should only be written as part of a reset sequence and before issuing any read
                                                                 operations, CFGs, or I/O transactions from the core(s). For diagnostic use only.
                                                                 Legal values are 1 to 32. */
#else
		uint64_t tags                        : 8;
		uint64_t pcnt                        : 8;
		uint64_t ncnt                        : 8;
		uint64_t ccnt                        : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_slix_s2m_macx_ctl_s     cn88xx; */
	/* struct bdk_slix_s2m_macx_ctl_s     cn88xxp1; */
} bdk_slix_s2m_macx_ctl_t;

static inline uint64_t BDK_SLIX_S2M_MACX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_S2M_MACX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 2)))
		return 0x0000874001002080ull + (param1 & 1) * 0x1000000000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_SLIX_S2M_MACX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_S2M_MACX_CTL(...) bdk_slix_s2m_macx_ctl_t
#define bustype_BDK_SLIX_S2M_MACX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_S2M_MACX_CTL(p1,p2) (p1)
#define arguments_BDK_SLIX_S2M_MACX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SLIX_S2M_MACX_CTL(...) "SLIX_S2M_MACX_CTL"


/**
 * NCB - sli#_s2m_reg#_acc
 *
 * These registers contains address index and control bits for access to memory from cores.
 * Indexed using {NCBO DST[3:0], NCBO Address[35:32]}.
 */
typedef union bdk_slix_s2m_regx_acc {
	uint64_t u;
	struct bdk_slix_s2m_regx_acc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_55_63              : 9;
		uint64_t ctype                       : 2;  /**< R/W - The command type to be genereated:
                                                                 0x0 = PCI memory.
                                                                 0x1 = PCI configuration (only 8, 16, 32-bit loads are supported). Note normally the ECAM
                                                                 would be used in place of this CTYPE.
                                                                 0x2 = PCI I/O (Only 8, 16, 32-bit loads are supported).
                                                                 0x3 = Reserved. */
		uint64_t zero                        : 1;  /**< R/W - Causes all byte read operations to be zero-length read operations. Returns zeros to the
                                                                 EXEC for all read data. */
		uint64_t mac                         : 3;  /**< R/W - The MAC that reads/writes to this subid are sent. */
		uint64_t nmerge                      : 1;  /**< R/W - When set, no write merging is allowed in this window. */
		uint64_t esr                         : 2;  /**< RO - Reserved. */
		uint64_t esw                         : 2;  /**< RO - Reserved. */
		uint64_t wtype                       : 2;  /**< R/W - Write type. ADDRTYPE\<1:0\> for write operations to this region.
                                                                 ADDRTYPE\<0\> is the relaxed-order attribute.
                                                                 ADDRTYPE\<1\> is the no-snoop attribute. */
		uint64_t rtype                       : 2;  /**< R/W - Read type. ADDRTYPE\<1:0\> for read operations to this region.
                                                                 ADDRTYPE\<0\> is the relaxed-order attribute.
                                                                 ADDRTYPE\<1\> is the no-snoop attribute. */
		uint64_t reserved_32_39              : 8;
		uint64_t ba                          : 32; /**< R/W - Bus address. Address bits\<63:32\> for read/write operations that use this region. */
#else
		uint64_t ba                          : 32;
		uint64_t reserved_32_39              : 8;
		uint64_t rtype                       : 2;
		uint64_t wtype                       : 2;
		uint64_t esw                         : 2;
		uint64_t esr                         : 2;
		uint64_t nmerge                      : 1;
		uint64_t mac                         : 3;
		uint64_t zero                        : 1;
		uint64_t ctype                       : 2;
		uint64_t reserved_55_63              : 9;
#endif
	} s;
	/* struct bdk_slix_s2m_regx_acc_s     cn88xx; */
	/* struct bdk_slix_s2m_regx_acc_s     cn88xxp1; */
} bdk_slix_s2m_regx_acc_t;

static inline uint64_t BDK_SLIX_S2M_REGX_ACC(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_S2M_REGX_ACC(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 255)))
		return 0x0000874001000000ull + (param1 & 1) * 0x1000000000ull + (param2 & 255) * 0x10ull;
	csr_fatal("BDK_SLIX_S2M_REGX_ACC", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_S2M_REGX_ACC(...) bdk_slix_s2m_regx_acc_t
#define bustype_BDK_SLIX_S2M_REGX_ACC(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_S2M_REGX_ACC(p1,p2) (p1)
#define arguments_BDK_SLIX_S2M_REGX_ACC(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SLIX_S2M_REGX_ACC(...) "SLIX_S2M_REGX_ACC"


/**
 * PEXP_NCB - sli#_scratch_1
 *
 * These registers are general purpose 64-bit scratch registers for software use.
 *
 */
typedef union bdk_slix_scratch_1 {
	uint64_t u;
	struct bdk_slix_scratch_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - The value in this register is totally software defined. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_slix_scratch_1_s        cn88xx; */
	/* struct bdk_slix_scratch_1_s        cn88xxp1; */
} bdk_slix_scratch_1_t;

static inline uint64_t BDK_SLIX_SCRATCH_1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_SCRATCH_1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000874000001000ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_SLIX_SCRATCH_1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_SCRATCH_1(...) bdk_slix_scratch_1_t
#define bustype_BDK_SLIX_SCRATCH_1(...) BDK_CSR_TYPE_PEXP_NCB
#define busnum_BDK_SLIX_SCRATCH_1(p1) (p1)
#define arguments_BDK_SLIX_SCRATCH_1(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_SCRATCH_1(...) "SLIX_SCRATCH_1"


/**
 * PEXP_NCB - sli#_scratch_2
 *
 * These registers are general purpose 64-bit scratch registers for software use.
 *
 */
typedef union bdk_slix_scratch_2 {
	uint64_t u;
	struct bdk_slix_scratch_2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - The value in this register is totally software defined. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_slix_scratch_2_s        cn88xx; */
	/* struct bdk_slix_scratch_2_s        cn88xxp1; */
} bdk_slix_scratch_2_t;

static inline uint64_t BDK_SLIX_SCRATCH_2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_SCRATCH_2(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000874000001010ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_SLIX_SCRATCH_2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_SCRATCH_2(...) bdk_slix_scratch_2_t
#define bustype_BDK_SLIX_SCRATCH_2(...) BDK_CSR_TYPE_PEXP_NCB
#define busnum_BDK_SLIX_SCRATCH_2(p1) (p1)
#define arguments_BDK_SLIX_SCRATCH_2(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_SCRATCH_2(...) "SLIX_SCRATCH_2"


/**
 * NCB - sli#_sctl
 *
 * Added in pass 2.
 *
 */
typedef union bdk_slix_sctl {
	uint64_t u;
	struct bdk_slix_sctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t scen                        : 1;  /**< SR/W - Allow SLI window transactions to request secure-world accesses.

                                                                 0 = SLI()_WIN_RD_ADDR[RD_SEC], SLI()_WIN_WR_ADDR[WR_SEC] are ignored and treated
                                                                 as if zero. Window transactions onto NCB are non-secure, though the SMMU may
                                                                 later promote them to secure.

                                                                 1 = SLI()_WIN_RD_ADDR[RD_SEC], SLI()_WIN_WR_ADDR[WR_SEC] are honored. Window
                                                                 transactions may request non-secure or secure world. This bit should not be set
                                                                 in trusted-mode.

                                                                 Resets to 0 when in trusted-mode (RST_BOOT[TRUSTED_MODE]), else resets to 1. */
#else
		uint64_t scen                        : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_slix_sctl_s             cn88xx; */
} bdk_slix_sctl_t;

static inline uint64_t BDK_SLIX_SCTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_SCTL(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((param1 <= 1)))
		return 0x0000874001002010ull + (param1 & 1) * 0x1000000000ull;
	else 		csr_fatal("BDK_SLIX_SCTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_SCTL(...) bdk_slix_sctl_t
#define bustype_BDK_SLIX_SCTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SLIX_SCTL(p1) (p1)
#define arguments_BDK_SLIX_SCTL(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_SCTL(...) "SLIX_SCTL"


/**
 * PEXP - sli#_win_rd_addr
 *
 * This register contains the address to be read when SLI()_WIN_RD_DATA is read.
 * Writing this register causes a read operation to take place.
 * This register should not be used to read SLI_* registers.
 */
typedef union bdk_slix_win_rd_addr {
	uint64_t u;
	struct bdk_slix_win_rd_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t secen                       : 1;  /**< R/W - Changed in pass 2.
                                                                 This request is a secure-world transaction. This is intended to be set only for
                                                                 transactions during early boot when the SMMU is in bypass mode; after SMMU
                                                                 initialization SMMU()_SDDR() may be used to control which SLI streams are secure.

                                                                 If SLI()_SCTL[SECEN] = 0, this bit is ignored and transactions are always non-secure
                                                                 onto the NCB, though the SMMU may later promote them to secure. */
		uint64_t reserved_51_62              : 12;
		uint64_t ld_cmd                      : 2;  /**< R/W - The load command size.
                                                                 0x3 = Load 8 bytes.
                                                                 0x2 = Load 4 bytes.
                                                                 0x1 = Load 2 bytes.
                                                                 0x0 = Load 1 bytes. */
		uint64_t rd_addr                     : 49; /**< R/W - The address sent to the NCB for this load request. */
#else
		uint64_t rd_addr                     : 49;
		uint64_t ld_cmd                      : 2;
		uint64_t reserved_51_62              : 12;
		uint64_t secen                       : 1;
#endif
	} s;
	/* struct bdk_slix_win_rd_addr_s      cn88xx; */
	struct bdk_slix_win_rd_addr_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_51_63              : 13;
		uint64_t ld_cmd                      : 2;  /**< R/W - The load command size.
                                                                 0x3 = Load 8 bytes.
                                                                 0x2 = Load 4 bytes.
                                                                 0x1 = Load 2 bytes.
                                                                 0x0 = Load 1 bytes. */
		uint64_t rd_addr                     : 49; /**< R/W - The address sent to the NCB for this load request. */
#else
		uint64_t rd_addr                     : 49;
		uint64_t ld_cmd                      : 2;
		uint64_t reserved_51_63              : 13;
#endif
	} cn88xxp1;
} bdk_slix_win_rd_addr_t;

static inline uint64_t BDK_SLIX_WIN_RD_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_WIN_RD_ADDR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000000000000010ull + (param1 & 1) * 0x10000000000ull;
	csr_fatal("BDK_SLIX_WIN_RD_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_WIN_RD_ADDR(...) bdk_slix_win_rd_addr_t
#define bustype_BDK_SLIX_WIN_RD_ADDR(...) BDK_CSR_TYPE_PEXP
#define busnum_BDK_SLIX_WIN_RD_ADDR(p1) (p1)
#define arguments_BDK_SLIX_WIN_RD_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_WIN_RD_ADDR(...) "SLIX_WIN_RD_ADDR"


/**
 * PEXP - sli#_win_rd_data
 *
 * This register contains the address to be read when SLI()_WIN_RD_DATA is read.
 *
 */
typedef union bdk_slix_win_rd_data {
	uint64_t u;
	struct bdk_slix_win_rd_data_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rd_data                     : 64; /**< RO/H - The read data. */
#else
		uint64_t rd_data                     : 64;
#endif
	} s;
	/* struct bdk_slix_win_rd_data_s      cn88xx; */
	/* struct bdk_slix_win_rd_data_s      cn88xxp1; */
} bdk_slix_win_rd_data_t;

static inline uint64_t BDK_SLIX_WIN_RD_DATA(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_WIN_RD_DATA(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000000000000040ull + (param1 & 1) * 0x10000000000ull;
	csr_fatal("BDK_SLIX_WIN_RD_DATA", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_WIN_RD_DATA(...) bdk_slix_win_rd_data_t
#define bustype_BDK_SLIX_WIN_RD_DATA(...) BDK_CSR_TYPE_PEXP
#define busnum_BDK_SLIX_WIN_RD_DATA(p1) (p1)
#define arguments_BDK_SLIX_WIN_RD_DATA(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_WIN_RD_DATA(...) "SLIX_WIN_RD_DATA"


/**
 * PEXP - sli#_win_wr_addr
 *
 * Contains the address to be writen to when a write operation is started by writing
 * SLI(0..1)_WIN_WR_DATA.
 * This register should not be used to write SLI_* registers.
 */
typedef union bdk_slix_win_wr_addr {
	uint64_t u;
	struct bdk_slix_win_wr_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t secen                       : 1;  /**< R/W - Changed in pass 2.
                                                                 This request is a secure-world transaction. This is intended to be set only for
                                                                 transactions during early boot when the SMMU is in bypass mode; after SMMU
                                                                 initialization SMMU()_SDDR() may be used to control which SLI streams are secure.

                                                                 If SLI()_SCTL[SECEN] = 0, this bit is ignored and transactions are always non-secure
                                                                 onto the NCB, though the SMMU may later promote them to secure. */
		uint64_t reserved_49_62              : 14;
		uint64_t wr_addr                     : 46; /**< R/W - The address sent to the NCB for this store request. */
		uint64_t reserved_0_2                : 3;
#else
		uint64_t reserved_0_2                : 3;
		uint64_t wr_addr                     : 46;
		uint64_t reserved_49_62              : 14;
		uint64_t secen                       : 1;
#endif
	} s;
	/* struct bdk_slix_win_wr_addr_s      cn88xx; */
	struct bdk_slix_win_wr_addr_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t wr_addr                     : 46; /**< R/W - The address sent to the NCB for this store request. */
		uint64_t reserved_0_2                : 3;
#else
		uint64_t reserved_0_2                : 3;
		uint64_t wr_addr                     : 46;
		uint64_t reserved_49_63              : 15;
#endif
	} cn88xxp1;
} bdk_slix_win_wr_addr_t;

static inline uint64_t BDK_SLIX_WIN_WR_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_WIN_WR_ADDR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000000000000000ull + (param1 & 1) * 0x10000000000ull;
	csr_fatal("BDK_SLIX_WIN_WR_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_WIN_WR_ADDR(...) bdk_slix_win_wr_addr_t
#define bustype_BDK_SLIX_WIN_WR_ADDR(...) BDK_CSR_TYPE_PEXP
#define busnum_BDK_SLIX_WIN_WR_ADDR(p1) (p1)
#define arguments_BDK_SLIX_WIN_WR_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_WIN_WR_ADDR(...) "SLIX_WIN_WR_ADDR"


/**
 * PEXP - sli#_win_wr_data
 *
 * This register contains the data to write to the address located in SLI()_WIN_WR_ADDR.
 * Writing this register causes a write operation to take place.
 */
typedef union bdk_slix_win_wr_data {
	uint64_t u;
	struct bdk_slix_win_wr_data_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t wr_data                     : 64; /**< R/W - The data to be written. */
#else
		uint64_t wr_data                     : 64;
#endif
	} s;
	/* struct bdk_slix_win_wr_data_s      cn88xx; */
	/* struct bdk_slix_win_wr_data_s      cn88xxp1; */
} bdk_slix_win_wr_data_t;

static inline uint64_t BDK_SLIX_WIN_WR_DATA(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_WIN_WR_DATA(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000000000000020ull + (param1 & 1) * 0x10000000000ull;
	csr_fatal("BDK_SLIX_WIN_WR_DATA", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_WIN_WR_DATA(...) bdk_slix_win_wr_data_t
#define bustype_BDK_SLIX_WIN_WR_DATA(...) BDK_CSR_TYPE_PEXP
#define busnum_BDK_SLIX_WIN_WR_DATA(p1) (p1)
#define arguments_BDK_SLIX_WIN_WR_DATA(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_WIN_WR_DATA(...) "SLIX_WIN_WR_DATA"


/**
 * PEXP - sli#_win_wr_mask
 *
 * This register contains the mask for the data in SLI()_WIN_WR_DATA.
 *
 */
typedef union bdk_slix_win_wr_mask {
	uint64_t u;
	struct bdk_slix_win_wr_mask_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t wr_mask                     : 8;  /**< R/W - The byte enables sent to the NCB for this store request. */
#else
		uint64_t wr_mask                     : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_slix_win_wr_mask_s      cn88xx; */
	/* struct bdk_slix_win_wr_mask_s      cn88xxp1; */
} bdk_slix_win_wr_mask_t;

static inline uint64_t BDK_SLIX_WIN_WR_MASK(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SLIX_WIN_WR_MASK(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000000000000030ull + (param1 & 1) * 0x10000000000ull;
	csr_fatal("BDK_SLIX_WIN_WR_MASK", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SLIX_WIN_WR_MASK(...) bdk_slix_win_wr_mask_t
#define bustype_BDK_SLIX_WIN_WR_MASK(...) BDK_CSR_TYPE_PEXP
#define busnum_BDK_SLIX_WIN_WR_MASK(p1) (p1)
#define arguments_BDK_SLIX_WIN_WR_MASK(p1) (p1),-1,-1,-1
#define basename_BDK_SLIX_WIN_WR_MASK(...) "SLIX_WIN_WR_MASK"

#endif /* __BDK_CSRS_SLI__ */
