#ifndef __BDK_CSRS_RAD__
#define __BDK_CSRS_RAD__
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
 * Cavium RAD.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration RAD_INT_VEC_E
 *
 * RAD PF MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum rad_int_vec_e {
	RAD_INT_VEC_E_INTR = 0x0,
	RAD_INT_VEC_E_ENUM_LAST = 0x1,
};


/**
 * Structure RAD_CWORD_S
 *
 * RAD Control Word Structure
 *
 */
union rad_cword_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t istr                        : 8;  /**< [ 63: 56] When [STREN] is set, the SMMU stream for RAD_IWORD_S[PTR]. */
		uint64_t ostr                        : 8;  /**< [ 55: 48] When [STREN] is set, the SMMU stream for RAD_OWORD_S[PTR]. */
		uint64_t reserved_39_47              : 9;  /**< [ 47: 39] Reserved. */
		uint64_t stren                       : 1;  /**< [ 38: 38] Stream override enable.
                                                                 0 = Use the default SMMU stream identifier of PCC_DEV_CON_E::RAD for all requests.
                                                                 1 = Use [ISTR] for the low 8-bits of the SMMU stream identifier for RAD_IWORD_S[PTR]
                                                                 streams, and likewise [OSTR] for RAD_OWORD_S[PTR] streams, and RAD_RESP_S[STR] for
                                                                 RAD_RESP_S[PTR] streams.  This does not affect the GIC stream ID used for interrupts.
                                                                 This allows software to accomplish hypervisor-to-guest and guest-to-guest DMAs by using
                                                                 multiple streams in a transaction.

                                                                 This bit should only be set by a hypervisor, and any hypervisor code should enforce guest
                                                                 requests have this bit clear. INTERNAL: When RAD is virtualized this will need a per-queue
                                                                 PF enable. */
		uint64_t dn                          : 1;  /**< [ 37: 37] When set, on completing this transaction RAD will increment RAD_DONE_CNT. */
		uint64_t q_cmp                       : 1;  /**< [ 36: 36] Q pipe mode. Must not be set when [QOUT]=0, and must not be set when [Q_XOR] is set.
                                                                 0 = Q pipe is in normal mode.
                                                                 1 = Q pipe is in non-zero byte detect mode. The Q RAD_OWORD_S[PTR] result is the non-zero
                                                                 detect result, which indicates the position of the first non-zero byte in the pipe result
                                                                 bytes. */
		uint64_t p_cmp                       : 1;  /**< [ 35: 35] P pipe mode. Must not be set when [POUT]=0, and must not be set when [P_XOR] is set.
                                                                 0 = P pipe is in normal mode.
                                                                 1 = P pipe is in non-zero byte detect mode. The P RAD_OWORD_S[PTR] result is the non-zero
                                                                 detect result, which indicates the position of the first non-zero byte in the pipe result
                                                                 bytes. */
		uint64_t q_xor                       : 1;  /**< [ 34: 34] Indicates whether the Q output buffer bytes are the normal Q pipe result or the normal Q
                                                                 pipe result exclusive-OR'ed with the P pipe result.

                                                                 When [Q_XOR] = 0 (and [Q_CMP]=0), the Q output buffer bytes are the normal Q pipe result,
                                                                 which does not include the P pipe result in any way.

                                                                 When [Q_XOR] = 1, the Q output buffer bytes are the normal Q pipe result exclusive-OR'ed
                                                                 with the P pipe result, as if the P pipe result were another Q RAD_IWORD_S for the Q pipe
                                                                 with QMULT=1.

                                                                 Must not be set unless both [POUT,QOUT] are set, and must not be set when [Q_CMP] is set. */
		uint64_t p_xor                       : 1;  /**< [ 33: 33] Indicates whether the P output buffer bytes are the normal P pipe result or the normal P
                                                                 pipe result exclusive-OR'ed with the Q pipe result.

                                                                 When [P_XOR]=0 (and [P_CMP] = 0), the P output buffer bytes are the normal P pipe result,
                                                                 which does not include the Q pipe result in any way.

                                                                 When [P_XOR]=1, the P output buffer bytes are the normal P pipe result exclusive-OR'ed
                                                                 with the Q pipe result, as if the Q pipe result were another P RAD_IWORD_S for the P pipe.

                                                                 [P_XOR] must not be set unless both [POUT,QOUT] are set, and must not be set when [P_CMP]
                                                                 is set. */
		uint64_t wqe                         : 1;  /**< [ 32: 32] Reserved. */
		uint64_t qout                        : 1;  /**< [ 31: 31] Q pipe is used by this instruction. If set, RAD_IWORD_S[QEN] must be set for at least one
                                                                 RAD_IWORD_S. At least one of [QOUT,POUT] must be set. */
		uint64_t pout                        : 1;  /**< [ 30: 30] P pipe is used by this instruction. If set, RAD_IWORD_S[PEN] must be set for at least one
                                                                 RAD_IWORD_S. At least one of [QOUT,POUT] must be set. */
		uint64_t iword                       : 6;  /**< [ 29: 24] Number of input buffers used, must be 1 to 32. If one, a copy operation will be performed
                                                                 (i.e. an XOR with zero.) For copy operations, [Q_XOR] = 0, [P_XOR] = 0, [QOUT] = 1,
                                                                 [POUT] = 0, [QMULT] = 1, [QEN] = 1, [PEN] = 0, and [Q_CMP] = 0. */
		uint64_t size                        : 24; /**< [ 23:  0] Indicates the size in bytes of all input buffers. When [Q_CMP,P_CMP]=0, also indicates the
                                                                 size of the Q/P output buffers. Must be a multiple of 8B (i.e. <2:0> must be zero). */
#else
		uint64_t size                        : 24;
		uint64_t iword                       : 6;
		uint64_t pout                        : 1;
		uint64_t qout                        : 1;
		uint64_t wqe                         : 1;
		uint64_t p_xor                       : 1;
		uint64_t q_xor                       : 1;
		uint64_t p_cmp                       : 1;
		uint64_t q_cmp                       : 1;
		uint64_t dn                          : 1;
		uint64_t stren                       : 1;
		uint64_t reserved_39_47              : 9;
		uint64_t ostr                        : 8;
		uint64_t istr                        : 8;
#endif
	} s;
};

/**
 * Structure RAD_IWORD_S
 *
 * RAD Input Pointer Structure
 * RAD_IWORD_S points to where to read the input buffer data from. Each RAD_IWORD_S indicates
 * whether the buffer should be accumulated by the P pipe, the Q pipe, or both. The RAD_IWORD_S
 * also supplies the Q pipe multiplier for the buffer (QMULT).
 */
union rad_iword_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t qmult                       : 8;  /**< [ 63: 56] The Q pipe multiplier for the input buffer. Must must be zero when [QEN] is not set;
                                                                 [QMULT] must be non-zero when [QEN] is set. When [QMULT] is 1, the multiplication
                                                                 simplifies to the identity function, and the Q pipe performs the same XOR function as the
                                                                 P pipe. */
		uint64_t nc                          : 1;  /**< [ 55: 55] When set, indicates that RAD should not allocate L2 cache space for this input buffer data
                                                                 on L2 cache misses. Setting [NC] may improve performance in some circumstances, as the L2
                                                                 cache may not be polluted with input buffer data. */
		uint64_t qen                         : 1;  /**< [ 54: 54] Indicates that this input buffer data should participate in the Q pipe result. The Q pipe
                                                                 hardware multiplies each participating input byte by RAD_IWORD_S[QMULT] before
                                                                 accumulating them
                                                                 by exclusive-OR'ing. Must not be set when RAD_CWORD_S[QOUT] is not set. If
                                                                 RAD_CWORD_S[QOUT] is set, [QEN] must be set for at least one RAD_IWORD_S. */
		uint64_t pen                         : 1;  /**< [ 53: 53] Indicates that this input buffer data should participate in the P pipe result.
                                                                 The P pipe hardware accumulates each participating input byte by bit-wise exclusive-OR'ing
                                                                 it.
                                                                 [PEN] must not be set when RAD_CWORD_S[POUT] is not set.
                                                                 If RAD_CWORD_S[POUT] is set, [PEN] must be set for at least one RAD_IWORD_S. */
		uint64_t reserved_49_52              : 4;  /**< [ 52: 49] Reserved. */
		uint64_t ptr                         : 49; /**< [ 48:  0] The starting address of the input buffer in L2/DRAM. Must be naturally aligned on an
                                                                 eight-byte boundary (i.e. <2:0> must be zero). The SMMU stream used may be overridden with
                                                                 RAD_CWORD_S[ISTR]. */
#else
		uint64_t ptr                         : 49;
		uint64_t reserved_49_52              : 4;
		uint64_t pen                         : 1;
		uint64_t qen                         : 1;
		uint64_t nc                          : 1;
		uint64_t qmult                       : 8;
#endif
	} s;
};

/**
 * Structure RAD_NZDIST_S
 *
 * RAD Non-Zero Result Structure
 * Data written to RAD_OWORD_S[PTR] with non-zero result.
 */
union rad_nzdist_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40; /**< [ 63: 24] Zero. */
		uint64_t nzdist                      : 24; /**< [ 23:  0] Location of first pipe result byte that is non-zero. If all pipe result bytes are zero for
                                                                 this instruction, NZDIST = RAD_CWORD_S[SIZE]. NZDIST uses the endianness requested in
                                                                 RAD_CWORD_S[FIXME_NEW]. */
#else
		uint64_t nzdist                      : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
};

/**
 * Structure RAD_OWORD_S
 *
 * RAD Output Pointer Structure
 * RAD_OWORD_S points to where to output data to.
 */
union rad_oword_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_58_63              : 6;  /**< [ 63: 58] Reserved. */
		uint64_t fw                          : 1;  /**< [ 57: 57] When set, indicates that RAD can modify any byte in any (128B) cache line touched by
                                                                 L2/DRAM addresses [PTR] through [PTR]+RAD_CWORD_S[SIZE]. Setting [FW] can improve hardware
                                                                 performance, as some DRAM loads can be avoided on L2 cache misses. The Q [FW] must not be
                                                                 set when RAD_CWORD_S[Q_CMP] is set, and the P [FW] must not be set when RAD_CWORD_S[P_CMP]
                                                                 is set. */
		uint64_t nc                          : 1;  /**< [ 56: 56] When set, indicates that RAD should not allocate L2 cache space for the P/Q data on L2
                                                                 cache misses. [NC] should typically be clear, though setting [NC] can improve performance
                                                                 in some circumstances, as the L2 cache will not be polluted by P/Q data. The Q
                                                                 RAD_OWORD_S[NC] must not be set when RAD_CWORD_S[Q_CMP] is set, and the P RAD_OWORD_S[NC]
                                                                 must not be set when RAD_CWORD_S[P_CMP] is set. */
		uint64_t reserved_49_55              : 7;  /**< [ 55: 49] Reserved. */
		uint64_t p_ptr                       : 49; /**< [ 48:  0] When RAD_CWORD_S[P_CMP,Q_CMP]=0, [PTR] indicates the starting address of the L2/DRAM
                                                                 buffer that will receive the P/Q data.  The SMMU stream used may be overridden with
                                                                 RAD_CWORD_S[OSTR].

                                                                 In the non-compare mode, the output buffer receives
                                                                 all of the output buffer bytes.

                                                                 When RAD_CWORD_S[P_CMP,Q_CMP]=1, the corresponding P/Q pipe is in compare mode, and the
                                                                 only output of the pipe is the non-zero detect result. In this case, [PTR] indicates the
                                                                 8-byte location of the non-zero detect result, which is written with RAD_NZDIST_S.

                                                                 [PTR] must be naturally-aligned on an 8-byte boundary (i.e. <2:0> must be zero). */
#else
		uint64_t p_ptr                       : 49;
		uint64_t reserved_49_55              : 7;
		uint64_t nc                          : 1;
		uint64_t fw                          : 1;
		uint64_t reserved_58_63              : 6;
#endif
	} s;
};

/**
 * Structure RAD_RESP_S
 *
 * RAD Response Pointer Structure
 * This structure contains a pointer to the L2/DRAM byte to zero after completing the instruction.
 */
union rad_resp_s {
	uint64_t u[2];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_113_127            : 15; /**< [127:113] Reserved. */
		uint64_t ptr                         : 49; /**< [112: 64] When RAD_CWORD_S[WQE] is clear and [PTR] != 0, RAD writes the L2/DRAM byte indicated by
                                                                 [PTR] to zero after completing the instruction. RAD_REG_CTL[STORE_LE] indicates the
                                                                 endianness of [PTR]. [PTR] must be naturally-aligned on an 8B boundary (i.e. <2:0> must be
                                                                 zero) when RAD_CWORD_S[WQE] is set. The SMMU stream used may be overridden with
                                                                 [STR]. */
		uint64_t istr                        : 8;  /**< [ 63: 56] When RAD_CWORD_S[STREN] is set, the SMMU stream for [PTR]. */
		uint64_t reserved_0_55               : 56; /**< [ 55:  0] Reserved. */
#else
		uint64_t reserved_0_55               : 56;
		uint64_t istr                        : 8;
		uint64_t ptr                         : 49;
		uint64_t reserved_113_127            : 15;
#endif
	} s;
};


/**
 * NCB - rad_done_ack
 */
typedef union bdk_rad_done_ack {
	uint64_t u;
	struct bdk_rad_done_ack_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_21_63              : 43;
		uint64_t done_ack                    : 21; /**< WO - Number of decrements to RAD_DONE_CNT[DONE]. If RAD_DONE_CNT[DONE] is still non-zero the
                                                                 interrupt will be re-sent if the conditions described in RAD_DONE_CNT[DONE] are satified. */
#else
		uint64_t done_ack                    : 21;
		uint64_t reserved_21_63              : 43;
#endif
	} s;
	/* struct bdk_rad_done_ack_s          cn85xx; */
	/* struct bdk_rad_done_ack_s          cn88xx; */
} bdk_rad_done_ack_t;

#define BDK_RAD_DONE_ACK BDK_RAD_DONE_ACK_FUNC()
static inline uint64_t BDK_RAD_DONE_ACK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_DONE_ACK_FUNC(void)
{
	return 0x0000870000000040ull;
}
#define typedef_BDK_RAD_DONE_ACK bdk_rad_done_ack_t
#define bustype_BDK_RAD_DONE_ACK BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_DONE_ACK 0
#define arguments_BDK_RAD_DONE_ACK -1,-1,-1,-1
#define basename_BDK_RAD_DONE_ACK "RAD_DONE_ACK"


/**
 * NCB - rad_done_cnt
 */
typedef union bdk_rad_done_cnt {
	uint64_t u;
	struct bdk_rad_done_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_21_63              : 43;
		uint64_t done                        : 21; /**< R/W/H - When an instruction with RAD_CWORD_S[DN] completes, [DONE] is incremented. Writes to this
                                                                 field are for diagnostic use only; instead software writes RAD_DONE_ACK[DONE] with the
                                                                 number of decrements for this field.

                                                                 Interrupts are sent as follows:

                                                                 * When RAD_DONE_CNT[DONE] = 0, then no results are pending, the interrupt coalescing
                                                                 timer is held to zero, and an interrupt is not sent.

                                                                 * When RAD_DONE_CNT[DONE] != 0, then the interrupt coalescing timer counts. If the
                                                                 counter is less than RAD_DONE_WAIT[TIME_WAIT]*1024, and RAD_DONE_CNT[DONE]
                                                                 < RAD_DONE_WAIT[NUM_WAIT] , i.e. not enough time has passed or not enough
                                                                 results have arrived, then interrupts are not sent due to coalescing.

                                                                 * When RAD_DONE_ACK is written, the interrupt coalescing timer restarts. Note after
                                                                 decrementing this interrupt equation is recomputed, for example if
                                                                 RAD_DONE_CNT[DONE] >= RAD_DONE_WAIT[NUM_WAIT] and the timer is zero, the
                                                                 interrupt will be resent immediately.  (This covers the race case between software
                                                                 acknowledging an interrupt and a result returning.)

                                                                 * When RAD_INT_ENA_W1S[DONE] = 0, interrupts are not sent, but the counting described
                                                                 above still occurs. */
#else
		uint64_t done                        : 21;
		uint64_t reserved_21_63              : 43;
#endif
	} s;
	/* struct bdk_rad_done_cnt_s          cn85xx; */
	/* struct bdk_rad_done_cnt_s          cn88xx; */
} bdk_rad_done_cnt_t;

#define BDK_RAD_DONE_CNT BDK_RAD_DONE_CNT_FUNC()
static inline uint64_t BDK_RAD_DONE_CNT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_DONE_CNT_FUNC(void)
{
	return 0x0000870000000038ull;
}
#define typedef_BDK_RAD_DONE_CNT bdk_rad_done_cnt_t
#define bustype_BDK_RAD_DONE_CNT BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_DONE_CNT 0
#define arguments_BDK_RAD_DONE_CNT -1,-1,-1,-1
#define basename_BDK_RAD_DONE_CNT "RAD_DONE_CNT"


/**
 * NCB - rad_done_wait
 *
 * Specifies the interrupt coalescing settings.
 *
 */
typedef union bdk_rad_done_wait {
	uint64_t u;
	struct bdk_rad_done_wait_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t time_wait                   : 16; /**< R/W - Time hold-off. When RAD_DONE_CNT[DONE] = 0, or RAD_DONE_ACK is written a timer is
                                                                 cleared. When the timer reaches [TIME_WAIT]*1024 then interrupt coalescing ends; see
                                                                 RAD_DONE_CNT[DONE]. If zero, time coalescing is disabled. */
		uint64_t reserved_20_31              : 12;
		uint64_t num_wait                    : 20; /**< R/W - Number of messages hold-off. When RAD_DONE_CNT[DONE] >= [NUM_WAIT] then interrupt
                                                                 coalescing ends; see RAD_DONE_CNT[DONE]. If zero, message number coalescing is disabled. */
#else
		uint64_t num_wait                    : 20;
		uint64_t reserved_20_31              : 12;
		uint64_t time_wait                   : 16;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_rad_done_wait_s         cn85xx; */
	/* struct bdk_rad_done_wait_s         cn88xx; */
} bdk_rad_done_wait_t;

#define BDK_RAD_DONE_WAIT BDK_RAD_DONE_WAIT_FUNC()
static inline uint64_t BDK_RAD_DONE_WAIT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_DONE_WAIT_FUNC(void)
{
	return 0x0000870000000058ull;
}
#define typedef_BDK_RAD_DONE_WAIT bdk_rad_done_wait_t
#define bustype_BDK_RAD_DONE_WAIT BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_DONE_WAIT 0
#define arguments_BDK_RAD_DONE_WAIT -1,-1,-1,-1
#define basename_BDK_RAD_DONE_WAIT "RAD_DONE_WAIT"


/**
 * NCB - rad_doorbell
 */
typedef union bdk_rad_doorbell {
	uint64_t u;
	struct bdk_rad_doorbell_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t dbell_cnt                   : 20; /**< R/W/H - Number of instruction queue 64-bit words to add to the RAD instruction doorbell count.
                                                                 RAD instructions are from 4 to 36 words. */
#else
		uint64_t dbell_cnt                   : 20;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_rad_doorbell_s          cn85xx; */
	/* struct bdk_rad_doorbell_s          cn88xx; */
} bdk_rad_doorbell_t;

#define BDK_RAD_DOORBELL BDK_RAD_DOORBELL_FUNC()
static inline uint64_t BDK_RAD_DOORBELL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_DOORBELL_FUNC(void)
{
	return 0x0000870000100000ull;
}
#define typedef_BDK_RAD_DOORBELL bdk_rad_doorbell_t
#define bustype_BDK_RAD_DOORBELL BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_DOORBELL 0
#define arguments_BDK_RAD_DOORBELL -1,-1,-1,-1
#define basename_BDK_RAD_DOORBELL "RAD_DOORBELL"


/**
 * NCB - rad_int
 */
typedef union bdk_rad_int {
	uint64_t u;
	struct bdk_rad_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t done                        : 1;  /**< RO/H - Done interrupt. See RAD_DONE_CNT[DONE]. */
		uint64_t doorbell                    : 1;  /**< R/W1C/H - Doorbell interrupt.  Set to indicate error that doorbell count has overflowed. */
#else
		uint64_t doorbell                    : 1;
		uint64_t done                        : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_rad_int_s               cn85xx; */
	/* struct bdk_rad_int_s               cn88xx; */
} bdk_rad_int_t;

#define BDK_RAD_INT BDK_RAD_INT_FUNC()
static inline uint64_t BDK_RAD_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_INT_FUNC(void)
{
	return 0x0000870000000028ull;
}
#define typedef_BDK_RAD_INT bdk_rad_int_t
#define bustype_BDK_RAD_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_INT 0
#define arguments_BDK_RAD_INT -1,-1,-1,-1
#define basename_BDK_RAD_INT "RAD_INT"


/**
 * NCB - rad_int_ena_w1c
 */
typedef union bdk_rad_int_ena_w1c {
	uint64_t u;
	struct bdk_rad_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t done                        : 1;  /**< RO/H - Done interrupt. See RAD_DONE_CNT[DONE]. */
		uint64_t doorbell                    : 1;  /**< R/W1C/H - Doorbell interrupt.  Set to indicate error that doorbell count has overflowed. */
#else
		uint64_t doorbell                    : 1;
		uint64_t done                        : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_rad_int_ena_w1c_s       cn85xx; */
	/* struct bdk_rad_int_ena_w1c_s       cn88xx; */
} bdk_rad_int_ena_w1c_t;

#define BDK_RAD_INT_ENA_W1C BDK_RAD_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_RAD_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_INT_ENA_W1C_FUNC(void)
{
	return 0x0000870000000048ull;
}
#define typedef_BDK_RAD_INT_ENA_W1C bdk_rad_int_ena_w1c_t
#define bustype_BDK_RAD_INT_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_INT_ENA_W1C 0
#define arguments_BDK_RAD_INT_ENA_W1C -1,-1,-1,-1
#define basename_BDK_RAD_INT_ENA_W1C "RAD_INT_ENA_W1C"


/**
 * NCB - rad_int_ena_w1s
 */
typedef union bdk_rad_int_ena_w1s {
	uint64_t u;
	struct bdk_rad_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t done                        : 1;  /**< RO/H - Done interrupt. See RAD_DONE_CNT[DONE]. */
		uint64_t doorbell                    : 1;  /**< R/W1C/H - Doorbell interrupt.  Set to indicate error that doorbell count has overflowed. */
#else
		uint64_t doorbell                    : 1;
		uint64_t done                        : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_rad_int_ena_w1s_s       cn85xx; */
	/* struct bdk_rad_int_ena_w1s_s       cn88xx; */
} bdk_rad_int_ena_w1s_t;

#define BDK_RAD_INT_ENA_W1S BDK_RAD_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_RAD_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_INT_ENA_W1S_FUNC(void)
{
	return 0x0000870000000050ull;
}
#define typedef_BDK_RAD_INT_ENA_W1S bdk_rad_int_ena_w1s_t
#define bustype_BDK_RAD_INT_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_INT_ENA_W1S 0
#define arguments_BDK_RAD_INT_ENA_W1S -1,-1,-1,-1
#define basename_BDK_RAD_INT_ENA_W1S "RAD_INT_ENA_W1S"


/**
 * NCB - rad_int_w1s
 */
typedef union bdk_rad_int_w1s {
	uint64_t u;
	struct bdk_rad_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t done                        : 1;  /**< RO/H - Done interrupt. See RAD_DONE_CNT[DONE]. */
		uint64_t doorbell                    : 1;  /**< R/W1S/H - Doorbell interrupt.  Set to indicate error that doorbell count has overflowed. */
#else
		uint64_t doorbell                    : 1;
		uint64_t done                        : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_rad_int_w1s_s           cn85xx; */
	/* struct bdk_rad_int_w1s_s           cn88xx; */
} bdk_rad_int_w1s_t;

#define BDK_RAD_INT_W1S BDK_RAD_INT_W1S_FUNC()
static inline uint64_t BDK_RAD_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_INT_W1S_FUNC(void)
{
	return 0x0000870000000030ull;
}
#define typedef_BDK_RAD_INT_W1S bdk_rad_int_w1s_t
#define bustype_BDK_RAD_INT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_INT_W1S 0
#define arguments_BDK_RAD_INT_W1S -1,-1,-1,-1
#define basename_BDK_RAD_INT_W1S "RAD_INT_W1S"


/**
 * NCB - rad_mem_debug0
 *
 * This CSR is a memory of 32 entries, and thus, the RAD_REG_READ_IDX CSR must be written before
 * any CSR read operations to this address can be performed. A read of any entry that has not
 * been previously written is illegal and will result in unpredictable CSR read data.
 */
typedef union bdk_rad_mem_debug0 {
	uint64_t u;
	struct bdk_rad_mem_debug0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t iword                       : 64; /**< RO/H - IWord */
#else
		uint64_t iword                       : 64;
#endif
	} s;
	/* struct bdk_rad_mem_debug0_s        cn85xx; */
	/* struct bdk_rad_mem_debug0_s        cn88xx; */
} bdk_rad_mem_debug0_t;

#define BDK_RAD_MEM_DEBUG0 BDK_RAD_MEM_DEBUG0_FUNC()
static inline uint64_t BDK_RAD_MEM_DEBUG0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_MEM_DEBUG0_FUNC(void)
{
	return 0x0000870000001000ull;
}
#define typedef_BDK_RAD_MEM_DEBUG0 bdk_rad_mem_debug0_t
#define bustype_BDK_RAD_MEM_DEBUG0 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_MEM_DEBUG0 0
#define arguments_BDK_RAD_MEM_DEBUG0 -1,-1,-1,-1
#define basename_BDK_RAD_MEM_DEBUG0 "RAD_MEM_DEBUG0"


/**
 * NCB - rad_mem_debug1
 *
 * This CSR is a memory of 256 entries, and thus, the RAD_REG_READ_IDX CSR must be written before
 * any CSR read operations to this address can be performed. A read of any entry that has not
 * been previously written is illegal and will result in unpredictable CSR read data.
 */
typedef union bdk_rad_mem_debug1 {
	uint64_t u;
	struct bdk_rad_mem_debug1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t p_dat                       : 64; /**< RO/H - P data */
#else
		uint64_t p_dat                       : 64;
#endif
	} s;
	/* struct bdk_rad_mem_debug1_s        cn85xx; */
	/* struct bdk_rad_mem_debug1_s        cn88xx; */
} bdk_rad_mem_debug1_t;

#define BDK_RAD_MEM_DEBUG1 BDK_RAD_MEM_DEBUG1_FUNC()
static inline uint64_t BDK_RAD_MEM_DEBUG1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_MEM_DEBUG1_FUNC(void)
{
	return 0x0000870000001008ull;
}
#define typedef_BDK_RAD_MEM_DEBUG1 bdk_rad_mem_debug1_t
#define bustype_BDK_RAD_MEM_DEBUG1 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_MEM_DEBUG1 0
#define arguments_BDK_RAD_MEM_DEBUG1 -1,-1,-1,-1
#define basename_BDK_RAD_MEM_DEBUG1 "RAD_MEM_DEBUG1"


/**
 * NCB - rad_mem_debug2
 *
 * This CSR is a memory of 256 entries, and thus, the RAD_REG_READ_IDX CSR must be written before
 * any CSR read operations to this address can be performed. A read of any entry that has not
 * been previously written is illegal and will result in unpredictable CSR read data.
 */
typedef union bdk_rad_mem_debug2 {
	uint64_t u;
	struct bdk_rad_mem_debug2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t q_dat                       : 64; /**< RO/H - Q data */
#else
		uint64_t q_dat                       : 64;
#endif
	} s;
	/* struct bdk_rad_mem_debug2_s        cn85xx; */
	/* struct bdk_rad_mem_debug2_s        cn88xx; */
} bdk_rad_mem_debug2_t;

#define BDK_RAD_MEM_DEBUG2 BDK_RAD_MEM_DEBUG2_FUNC()
static inline uint64_t BDK_RAD_MEM_DEBUG2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_MEM_DEBUG2_FUNC(void)
{
	return 0x0000870000001010ull;
}
#define typedef_BDK_RAD_MEM_DEBUG2 bdk_rad_mem_debug2_t
#define bustype_BDK_RAD_MEM_DEBUG2 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_MEM_DEBUG2 0
#define arguments_BDK_RAD_MEM_DEBUG2 -1,-1,-1,-1
#define basename_BDK_RAD_MEM_DEBUG2 "RAD_MEM_DEBUG2"


/**
 * NCB - rad_msix_pba#
 *
 * This register is the MSI-X PBA table, the bit number is indexed by the RAD_INT_VEC_E
 * enumeration.
 */
typedef union bdk_rad_msix_pbax {
	uint64_t u;
	struct bdk_rad_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated RAD_MSIX_VEC()_CTL, enumerated by
                                                                 RAD_INT_VEC_E. Bits that have no associated RAD_INT_VEC_E are zero. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_rad_msix_pbax_s         cn85xx; */
	/* struct bdk_rad_msix_pbax_s         cn88xx; */
} bdk_rad_msix_pbax_t;

static inline uint64_t BDK_RAD_MSIX_PBAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_MSIX_PBAX(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x0000870000FF0000ull;
	csr_fatal("BDK_RAD_MSIX_PBAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_RAD_MSIX_PBAX(...) bdk_rad_msix_pbax_t
#define bustype_BDK_RAD_MSIX_PBAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_MSIX_PBAX(p1) (p1)
#define arguments_BDK_RAD_MSIX_PBAX(p1) (p1),-1,-1,-1
#define basename_BDK_RAD_MSIX_PBAX(...) "RAD_MSIX_PBAX"


/**
 * NCB - rad_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the RAD_INT_VEC_E enumeration.
 *
 */
typedef union bdk_rad_msix_vecx_addr {
	uint64_t u;
	struct bdk_rad_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's RAD_MSIX_VEC()_ADDR, RAD_MSIX_VEC()_CTL, and corresponding
                                                                 bit of RAD_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_RAD_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_rad_msix_vecx_addr_s    cn85xx; */
	/* struct bdk_rad_msix_vecx_addr_s    cn88xx; */
} bdk_rad_msix_vecx_addr_t;

static inline uint64_t BDK_RAD_MSIX_VECX_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_MSIX_VECX_ADDR(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x0000870000F00000ull;
	csr_fatal("BDK_RAD_MSIX_VECX_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_RAD_MSIX_VECX_ADDR(...) bdk_rad_msix_vecx_addr_t
#define bustype_BDK_RAD_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_MSIX_VECX_ADDR(p1) (p1)
#define arguments_BDK_RAD_MSIX_VECX_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_RAD_MSIX_VECX_ADDR(...) "RAD_MSIX_VECX_ADDR"


/**
 * NCB - rad_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the RAD_INT_VEC_E enumeration.
 *
 */
typedef union bdk_rad_msix_vecx_ctl {
	uint64_t u;
	struct bdk_rad_msix_vecx_ctl_s {
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
	/* struct bdk_rad_msix_vecx_ctl_s     cn85xx; */
	/* struct bdk_rad_msix_vecx_ctl_s     cn88xx; */
} bdk_rad_msix_vecx_ctl_t;

static inline uint64_t BDK_RAD_MSIX_VECX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_MSIX_VECX_CTL(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x0000870000F00008ull;
	csr_fatal("BDK_RAD_MSIX_VECX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_RAD_MSIX_VECX_CTL(...) bdk_rad_msix_vecx_ctl_t
#define bustype_BDK_RAD_MSIX_VECX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_MSIX_VECX_CTL(p1) (p1)
#define arguments_BDK_RAD_MSIX_VECX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_RAD_MSIX_VECX_CTL(...) "RAD_MSIX_VECX_CTL"


/**
 * NCB - rad_reg_bist_result
 *
 * This register provides access to internal BIST results. Each bit is the BIST result of an
 * individual memory (per bit, 0 = pass, 1 = fail).
 */
typedef union bdk_rad_reg_bist_result {
	uint64_t u;
	struct bdk_rad_reg_bist_result_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t csr_msix                    : 1;  /**< RO - BIST result of the CSR_MSIX memory. INTERNAL: csr.msix_mem. */
		uint64_t csr_fifo                    : 1;  /**< RO - BIST result of the CSR_FIFO memory. INTERNAL: csr.csr_fifo. */
		uint64_t sta                         : 1;  /**< RO - BIST result of the STA memories */
		uint64_t ncb_oub                     : 1;  /**< RO - BIST result of the NCB_OUB memories */
		uint64_t ncb_inb                     : 2;  /**< RO - BIST result of the NCB_INB memories */
		uint64_t dat                         : 2;  /**< RO - BIST result of the DAT memories */
#else
		uint64_t dat                         : 2;
		uint64_t ncb_inb                     : 2;
		uint64_t ncb_oub                     : 1;
		uint64_t sta                         : 1;
		uint64_t csr_fifo                    : 1;
		uint64_t csr_msix                    : 1;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_rad_reg_bist_result_s   cn85xx; */
	/* struct bdk_rad_reg_bist_result_s   cn88xx; */
} bdk_rad_reg_bist_result_t;

#define BDK_RAD_REG_BIST_RESULT BDK_RAD_REG_BIST_RESULT_FUNC()
static inline uint64_t BDK_RAD_REG_BIST_RESULT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_BIST_RESULT_FUNC(void)
{
	return 0x0000870000000080ull;
}
#define typedef_BDK_RAD_REG_BIST_RESULT bdk_rad_reg_bist_result_t
#define bustype_BDK_RAD_REG_BIST_RESULT BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_BIST_RESULT 0
#define arguments_BDK_RAD_REG_BIST_RESULT -1,-1,-1,-1
#define basename_BDK_RAD_REG_BIST_RESULT "RAD_REG_BIST_RESULT"


/**
 * NCB - rad_reg_cmd_buf
 *
 * This register sets the command-buffer parameters.
 *
 */
typedef union bdk_rad_reg_cmd_buf {
	uint64_t u;
	struct bdk_rad_reg_cmd_buf_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t aura                        : 12; /**< RAZ - Reserved. */
		uint64_t ldwb                        : 1;  /**< R/W - When reading commands that end on cache line boundaries, use load-and-don't write back commands. */
		uint64_t dfb                         : 1;  /**< RO - Reserved. For forward compatibility, software should always write as one.  INTERNAL: In
                                                                 Octeon, if set, disables aura frees, which is the required mode without an FPA. */
		uint64_t size                        : 13; /**< R/W - Number of uint64 words per command buffer segment. */
		uint64_t reserved_0_32               : 33;
#else
		uint64_t reserved_0_32               : 33;
		uint64_t size                        : 13;
		uint64_t dfb                         : 1;
		uint64_t ldwb                        : 1;
		uint64_t aura                        : 12;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_rad_reg_cmd_buf_s       cn85xx; */
	/* struct bdk_rad_reg_cmd_buf_s       cn88xx; */
} bdk_rad_reg_cmd_buf_t;

#define BDK_RAD_REG_CMD_BUF BDK_RAD_REG_CMD_BUF_FUNC()
static inline uint64_t BDK_RAD_REG_CMD_BUF_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_CMD_BUF_FUNC(void)
{
	return 0x0000870000000008ull;
}
#define typedef_BDK_RAD_REG_CMD_BUF bdk_rad_reg_cmd_buf_t
#define bustype_BDK_RAD_REG_CMD_BUF BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_CMD_BUF 0
#define arguments_BDK_RAD_REG_CMD_BUF -1,-1,-1,-1
#define basename_BDK_RAD_REG_CMD_BUF "RAD_REG_CMD_BUF"


/**
 * NCB - rad_reg_cmd_ptr
 *
 * This register sets the command-buffer parameters.
 *
 */
typedef union bdk_rad_reg_cmd_ptr {
	uint64_t u;
	struct bdk_rad_reg_cmd_ptr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t ptr                         : 42; /**< R/W - Initial command-buffer pointer (128-byte aligned). Overwritten each time the
                                                                 command-buffer segment is exhausted. */
		uint64_t reserved_0_6                : 7;
#else
		uint64_t reserved_0_6                : 7;
		uint64_t ptr                         : 42;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_rad_reg_cmd_ptr_s       cn85xx; */
	/* struct bdk_rad_reg_cmd_ptr_s       cn88xx; */
} bdk_rad_reg_cmd_ptr_t;

#define BDK_RAD_REG_CMD_PTR BDK_RAD_REG_CMD_PTR_FUNC()
static inline uint64_t BDK_RAD_REG_CMD_PTR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_CMD_PTR_FUNC(void)
{
	return 0x0000870000000020ull;
}
#define typedef_BDK_RAD_REG_CMD_PTR bdk_rad_reg_cmd_ptr_t
#define bustype_BDK_RAD_REG_CMD_PTR BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_CMD_PTR 0
#define arguments_BDK_RAD_REG_CMD_PTR -1,-1,-1,-1
#define basename_BDK_RAD_REG_CMD_PTR "RAD_REG_CMD_PTR"


/**
 * NCB - rad_reg_ctl
 */
typedef union bdk_rad_reg_ctl {
	uint64_t u;
	struct bdk_rad_reg_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t inst_be                     : 1;  /**< R/W - Instruction/response structures (RAD_CWORD_S, RAD_IWORD_S, RAD_OWORD_S, RAD_RESP_S,
                                                                 RAD_NZDIST_S) are big endian. */
		uint64_t wc_dis                      : 1;  /**< R/W/H - Reserved. INTERNAL: Bug 17188 diagnostic disable. */
		uint64_t max_read                    : 4;  /**< R/W - Maximum number of outstanding data read commands. MAX_READ is a throttle to control IOB
                                                                 usage. Values greater than 0x8 are illegal. */
		uint64_t store_be                    : 1;  /**< R/W - Force STORE0 byte write address to big endian. Generaly this is not changed as data is
                                                                 byte invariant. */
		uint64_t reset                       : 1;  /**< R/W1 - Reset one-shot pulse (lasts for 4 cycles). */
#else
		uint64_t reset                       : 1;
		uint64_t store_be                    : 1;
		uint64_t max_read                    : 4;
		uint64_t wc_dis                      : 1;
		uint64_t inst_be                     : 1;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_rad_reg_ctl_s           cn85xx; */
	/* struct bdk_rad_reg_ctl_s           cn88xx; */
} bdk_rad_reg_ctl_t;

#define BDK_RAD_REG_CTL BDK_RAD_REG_CTL_FUNC()
static inline uint64_t BDK_RAD_REG_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_CTL_FUNC(void)
{
	return 0x0000870000000000ull;
}
#define typedef_BDK_RAD_REG_CTL bdk_rad_reg_ctl_t
#define bustype_BDK_RAD_REG_CTL BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_CTL 0
#define arguments_BDK_RAD_REG_CTL -1,-1,-1,-1
#define basename_BDK_RAD_REG_CTL "RAD_REG_CTL"


/**
 * NCB - rad_reg_debug0
 */
typedef union bdk_rad_reg_debug0 {
	uint64_t u;
	struct bdk_rad_reg_debug0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_57_63              : 7;
		uint64_t loop                        : 25; /**< RO/H - Loop offset */
		uint64_t reserved_22_31              : 10;
		uint64_t iridx                       : 6;  /**< RO/H - IWords read index */
		uint64_t reserved_14_15              : 2;
		uint64_t iwidx                       : 6;  /**< RO/H - IWords write index */
		uint64_t owordqv                     : 1;  /**< RO/H - Valid for OWORDQ */
		uint64_t owordpv                     : 1;  /**< RO/H - Valid for OWORDP */
		uint64_t commit                      : 1;  /**< RO/H - Waiting for write commit */
		uint64_t state                       : 5;  /**< RO/H - Main state */
#else
		uint64_t state                       : 5;
		uint64_t commit                      : 1;
		uint64_t owordpv                     : 1;
		uint64_t owordqv                     : 1;
		uint64_t iwidx                       : 6;
		uint64_t reserved_14_15              : 2;
		uint64_t iridx                       : 6;
		uint64_t reserved_22_31              : 10;
		uint64_t loop                        : 25;
		uint64_t reserved_57_63              : 7;
#endif
	} s;
	/* struct bdk_rad_reg_debug0_s        cn85xx; */
	/* struct bdk_rad_reg_debug0_s        cn88xx; */
} bdk_rad_reg_debug0_t;

#define BDK_RAD_REG_DEBUG0 BDK_RAD_REG_DEBUG0_FUNC()
static inline uint64_t BDK_RAD_REG_DEBUG0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_DEBUG0_FUNC(void)
{
	return 0x0000870000000100ull;
}
#define typedef_BDK_RAD_REG_DEBUG0 bdk_rad_reg_debug0_t
#define bustype_BDK_RAD_REG_DEBUG0 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_DEBUG0 0
#define arguments_BDK_RAD_REG_DEBUG0 -1,-1,-1,-1
#define basename_BDK_RAD_REG_DEBUG0 "RAD_REG_DEBUG0"


/**
 * NCB - rad_reg_debug1
 */
typedef union bdk_rad_reg_debug1 {
	uint64_t u;
	struct bdk_rad_reg_debug1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cword                       : 64; /**< RO/H - CWord */
#else
		uint64_t cword                       : 64;
#endif
	} s;
	/* struct bdk_rad_reg_debug1_s        cn85xx; */
	/* struct bdk_rad_reg_debug1_s        cn88xx; */
} bdk_rad_reg_debug1_t;

#define BDK_RAD_REG_DEBUG1 BDK_RAD_REG_DEBUG1_FUNC()
static inline uint64_t BDK_RAD_REG_DEBUG1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_DEBUG1_FUNC(void)
{
	return 0x0000870000000108ull;
}
#define typedef_BDK_RAD_REG_DEBUG1 bdk_rad_reg_debug1_t
#define bustype_BDK_RAD_REG_DEBUG1 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_DEBUG1 0
#define arguments_BDK_RAD_REG_DEBUG1 -1,-1,-1,-1
#define basename_BDK_RAD_REG_DEBUG1 "RAD_REG_DEBUG1"


/**
 * NCB - rad_reg_debug10
 */
typedef union bdk_rad_reg_debug10 {
	uint64_t u;
	struct bdk_rad_reg_debug10_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t flags                       : 8;  /**< RO/H - OCTL flags */
		uint64_t size                        : 16; /**< RO/H - OCTL size in bytes */
		uint64_t ptr                         : 40; /**< RO/H - OCTL pointer (address [41:40] not included) */
#else
		uint64_t ptr                         : 40;
		uint64_t size                        : 16;
		uint64_t flags                       : 8;
#endif
	} s;
	/* struct bdk_rad_reg_debug10_s       cn85xx; */
	/* struct bdk_rad_reg_debug10_s       cn88xx; */
} bdk_rad_reg_debug10_t;

#define BDK_RAD_REG_DEBUG10 BDK_RAD_REG_DEBUG10_FUNC()
static inline uint64_t BDK_RAD_REG_DEBUG10_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_DEBUG10_FUNC(void)
{
	return 0x0000870000000150ull;
}
#define typedef_BDK_RAD_REG_DEBUG10 bdk_rad_reg_debug10_t
#define bustype_BDK_RAD_REG_DEBUG10 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_DEBUG10 0
#define arguments_BDK_RAD_REG_DEBUG10 -1,-1,-1,-1
#define basename_BDK_RAD_REG_DEBUG10 "RAD_REG_DEBUG10"


/**
 * NCB - rad_reg_debug11
 */
typedef union bdk_rad_reg_debug11 {
	uint64_t u;
	struct bdk_rad_reg_debug11_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t q                           : 1;  /**< RO/H - OCTL Q flag */
		uint64_t p                           : 1;  /**< RO/H - OCTL P flag */
		uint64_t wc                          : 1;  /**< RO/H - OCTL write commit flag */
		uint64_t eod                         : 1;  /**< RO/H - OCTL EOD flag */
		uint64_t sod                         : 1;  /**< RO/H - OCTL SOD flag */
		uint64_t idx                         : 8;  /**< RO/H - OCTL index */
#else
		uint64_t idx                         : 8;
		uint64_t sod                         : 1;
		uint64_t eod                         : 1;
		uint64_t wc                          : 1;
		uint64_t p                           : 1;
		uint64_t q                           : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_rad_reg_debug11_s       cn85xx; */
	/* struct bdk_rad_reg_debug11_s       cn88xx; */
} bdk_rad_reg_debug11_t;

#define BDK_RAD_REG_DEBUG11 BDK_RAD_REG_DEBUG11_FUNC()
static inline uint64_t BDK_RAD_REG_DEBUG11_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_DEBUG11_FUNC(void)
{
	return 0x0000870000000158ull;
}
#define typedef_BDK_RAD_REG_DEBUG11 bdk_rad_reg_debug11_t
#define bustype_BDK_RAD_REG_DEBUG11 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_DEBUG11 0
#define arguments_BDK_RAD_REG_DEBUG11 -1,-1,-1,-1
#define basename_BDK_RAD_REG_DEBUG11 "RAD_REG_DEBUG11"


/**
 * NCB - rad_reg_debug12
 */
typedef union bdk_rad_reg_debug12 {
	uint64_t u;
	struct bdk_rad_reg_debug12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t asserts                     : 15; /**< RO/H - Various assertion checks */
#else
		uint64_t asserts                     : 15;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_rad_reg_debug12_s       cn85xx; */
	/* struct bdk_rad_reg_debug12_s       cn88xx; */
} bdk_rad_reg_debug12_t;

#define BDK_RAD_REG_DEBUG12 BDK_RAD_REG_DEBUG12_FUNC()
static inline uint64_t BDK_RAD_REG_DEBUG12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_DEBUG12_FUNC(void)
{
	return 0x0000870000000160ull;
}
#define typedef_BDK_RAD_REG_DEBUG12 bdk_rad_reg_debug12_t
#define bustype_BDK_RAD_REG_DEBUG12 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_DEBUG12 0
#define arguments_BDK_RAD_REG_DEBUG12 -1,-1,-1,-1
#define basename_BDK_RAD_REG_DEBUG12 "RAD_REG_DEBUG12"


/**
 * NCB - rad_reg_debug2
 */
typedef union bdk_rad_reg_debug2 {
	uint64_t u;
	struct bdk_rad_reg_debug2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t owordp                      : 64; /**< RO/H - OWordP */
#else
		uint64_t owordp                      : 64;
#endif
	} s;
	/* struct bdk_rad_reg_debug2_s        cn85xx; */
	/* struct bdk_rad_reg_debug2_s        cn88xx; */
} bdk_rad_reg_debug2_t;

#define BDK_RAD_REG_DEBUG2 BDK_RAD_REG_DEBUG2_FUNC()
static inline uint64_t BDK_RAD_REG_DEBUG2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_DEBUG2_FUNC(void)
{
	return 0x0000870000000110ull;
}
#define typedef_BDK_RAD_REG_DEBUG2 bdk_rad_reg_debug2_t
#define bustype_BDK_RAD_REG_DEBUG2 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_DEBUG2 0
#define arguments_BDK_RAD_REG_DEBUG2 -1,-1,-1,-1
#define basename_BDK_RAD_REG_DEBUG2 "RAD_REG_DEBUG2"


/**
 * NCB - rad_reg_debug3
 */
typedef union bdk_rad_reg_debug3 {
	uint64_t u;
	struct bdk_rad_reg_debug3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t owordq                      : 64; /**< RO/H - OWordQ */
#else
		uint64_t owordq                      : 64;
#endif
	} s;
	/* struct bdk_rad_reg_debug3_s        cn85xx; */
	/* struct bdk_rad_reg_debug3_s        cn88xx; */
} bdk_rad_reg_debug3_t;

#define BDK_RAD_REG_DEBUG3 BDK_RAD_REG_DEBUG3_FUNC()
static inline uint64_t BDK_RAD_REG_DEBUG3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_DEBUG3_FUNC(void)
{
	return 0x0000870000000118ull;
}
#define typedef_BDK_RAD_REG_DEBUG3 bdk_rad_reg_debug3_t
#define bustype_BDK_RAD_REG_DEBUG3 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_DEBUG3 0
#define arguments_BDK_RAD_REG_DEBUG3 -1,-1,-1,-1
#define basename_BDK_RAD_REG_DEBUG3 "RAD_REG_DEBUG3"


/**
 * NCB - rad_reg_debug4
 */
typedef union bdk_rad_reg_debug4 {
	uint64_t u;
	struct bdk_rad_reg_debug4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rword                       : 64; /**< RO/H - RWord */
#else
		uint64_t rword                       : 64;
#endif
	} s;
	/* struct bdk_rad_reg_debug4_s        cn85xx; */
	/* struct bdk_rad_reg_debug4_s        cn88xx; */
} bdk_rad_reg_debug4_t;

#define BDK_RAD_REG_DEBUG4 BDK_RAD_REG_DEBUG4_FUNC()
static inline uint64_t BDK_RAD_REG_DEBUG4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_DEBUG4_FUNC(void)
{
	return 0x0000870000000120ull;
}
#define typedef_BDK_RAD_REG_DEBUG4 bdk_rad_reg_debug4_t
#define bustype_BDK_RAD_REG_DEBUG4 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_DEBUG4 0
#define arguments_BDK_RAD_REG_DEBUG4 -1,-1,-1,-1
#define basename_BDK_RAD_REG_DEBUG4 "RAD_REG_DEBUG4"


/**
 * NCB - rad_reg_debug5
 */
typedef union bdk_rad_reg_debug5 {
	uint64_t u;
	struct bdk_rad_reg_debug5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_53_63              : 11;
		uint64_t niropc7                     : 3;  /**< RO/H - IOBI ropc (stage7 grant) */
		uint64_t nirque7                     : 2;  /**< RO/H - IOBI rque (stage7 grant) */
		uint64_t nirval7                     : 5;  /**< RO/H - IOBI rval (stage7 grant) */
		uint64_t niropc6                     : 3;  /**< RO/H - IOBI ropc (stage6 arb) */
		uint64_t nirque6                     : 2;  /**< RO/H - IOBI rque (stage6 arb) */
		uint64_t nirarb6                     : 1;  /**< RO/H - IOBI rarb (stage6 arb) */
		uint64_t nirval6                     : 5;  /**< RO/H - IOBI rval (stage6 arb) */
		uint64_t niridx1                     : 4;  /**< RO/H - IOBI ridx1 */
		uint64_t niwidx1                     : 4;  /**< RO/H - IOBI widx1 */
		uint64_t niridx0                     : 4;  /**< RO/H - IOBI ridx0 */
		uint64_t niwidx0                     : 4;  /**< RO/H - IOBI widx0 */
		uint64_t wccreds                     : 2;  /**< RO/H - WC credits */
		uint64_t fpacreds                    : 2;  /**< RO/H - FPA credits */
		uint64_t reserved_10_11              : 2;
		uint64_t ssocreds                    : 2;  /**< RO/H - SSO credits */
		uint64_t n1creds                     : 4;  /**< RO/H - IOBI1 credits */
		uint64_t n0creds                     : 4;  /**< RO/H - IOBI0 credits */
#else
		uint64_t n0creds                     : 4;
		uint64_t n1creds                     : 4;
		uint64_t ssocreds                    : 2;
		uint64_t reserved_10_11              : 2;
		uint64_t fpacreds                    : 2;
		uint64_t wccreds                     : 2;
		uint64_t niwidx0                     : 4;
		uint64_t niridx0                     : 4;
		uint64_t niwidx1                     : 4;
		uint64_t niridx1                     : 4;
		uint64_t nirval6                     : 5;
		uint64_t nirarb6                     : 1;
		uint64_t nirque6                     : 2;
		uint64_t niropc6                     : 3;
		uint64_t nirval7                     : 5;
		uint64_t nirque7                     : 2;
		uint64_t niropc7                     : 3;
		uint64_t reserved_53_63              : 11;
#endif
	} s;
	/* struct bdk_rad_reg_debug5_s        cn85xx; */
	/* struct bdk_rad_reg_debug5_s        cn88xx; */
} bdk_rad_reg_debug5_t;

#define BDK_RAD_REG_DEBUG5 BDK_RAD_REG_DEBUG5_FUNC()
static inline uint64_t BDK_RAD_REG_DEBUG5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_DEBUG5_FUNC(void)
{
	return 0x0000870000000128ull;
}
#define typedef_BDK_RAD_REG_DEBUG5 bdk_rad_reg_debug5_t
#define bustype_BDK_RAD_REG_DEBUG5 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_DEBUG5 0
#define arguments_BDK_RAD_REG_DEBUG5 -1,-1,-1,-1
#define basename_BDK_RAD_REG_DEBUG5 "RAD_REG_DEBUG5"


/**
 * NCB - rad_reg_debug6
 */
typedef union bdk_rad_reg_debug6 {
	uint64_t u;
	struct bdk_rad_reg_debug6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cnt                         : 8;  /**< RO/H - CCTL count [7:0] in bytes */
		uint64_t size                        : 16; /**< RO/H - CCTL size in bytes */
		uint64_t ptr                         : 40; /**< RO/H - CCTL pointer (address [41:40] not included) */
#else
		uint64_t ptr                         : 40;
		uint64_t size                        : 16;
		uint64_t cnt                         : 8;
#endif
	} s;
	/* struct bdk_rad_reg_debug6_s        cn85xx; */
	/* struct bdk_rad_reg_debug6_s        cn88xx; */
} bdk_rad_reg_debug6_t;

#define BDK_RAD_REG_DEBUG6 BDK_RAD_REG_DEBUG6_FUNC()
static inline uint64_t BDK_RAD_REG_DEBUG6_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_DEBUG6_FUNC(void)
{
	return 0x0000870000000130ull;
}
#define typedef_BDK_RAD_REG_DEBUG6 bdk_rad_reg_debug6_t
#define bustype_BDK_RAD_REG_DEBUG6 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_DEBUG6 0
#define arguments_BDK_RAD_REG_DEBUG6 -1,-1,-1,-1
#define basename_BDK_RAD_REG_DEBUG6 "RAD_REG_DEBUG6"


/**
 * NCB - rad_reg_debug7
 */
typedef union bdk_rad_reg_debug7 {
	uint64_t u;
	struct bdk_rad_reg_debug7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t cnt                         : 15; /**< RO/H - CCTL count [22:8] in bytes */
#else
		uint64_t cnt                         : 15;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_rad_reg_debug7_s        cn85xx; */
	/* struct bdk_rad_reg_debug7_s        cn88xx; */
} bdk_rad_reg_debug7_t;

#define BDK_RAD_REG_DEBUG7 BDK_RAD_REG_DEBUG7_FUNC()
static inline uint64_t BDK_RAD_REG_DEBUG7_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_DEBUG7_FUNC(void)
{
	return 0x0000870000000138ull;
}
#define typedef_BDK_RAD_REG_DEBUG7 bdk_rad_reg_debug7_t
#define bustype_BDK_RAD_REG_DEBUG7 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_DEBUG7 0
#define arguments_BDK_RAD_REG_DEBUG7 -1,-1,-1,-1
#define basename_BDK_RAD_REG_DEBUG7 "RAD_REG_DEBUG7"


/**
 * NCB - rad_reg_debug8
 */
typedef union bdk_rad_reg_debug8 {
	uint64_t u;
	struct bdk_rad_reg_debug8_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t flags                       : 8;  /**< RO/H - ICTL flags */
		uint64_t size                        : 16; /**< RO/H - ICTL size in bytes */
		uint64_t ptr                         : 40; /**< RO/H - ICTL pointer (address [41:40] not included) */
#else
		uint64_t ptr                         : 40;
		uint64_t size                        : 16;
		uint64_t flags                       : 8;
#endif
	} s;
	/* struct bdk_rad_reg_debug8_s        cn85xx; */
	/* struct bdk_rad_reg_debug8_s        cn88xx; */
} bdk_rad_reg_debug8_t;

#define BDK_RAD_REG_DEBUG8 BDK_RAD_REG_DEBUG8_FUNC()
static inline uint64_t BDK_RAD_REG_DEBUG8_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_DEBUG8_FUNC(void)
{
	return 0x0000870000000140ull;
}
#define typedef_BDK_RAD_REG_DEBUG8 bdk_rad_reg_debug8_t
#define bustype_BDK_RAD_REG_DEBUG8 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_DEBUG8 0
#define arguments_BDK_RAD_REG_DEBUG8 -1,-1,-1,-1
#define basename_BDK_RAD_REG_DEBUG8 "RAD_REG_DEBUG8"


/**
 * NCB - rad_reg_debug9
 */
typedef union bdk_rad_reg_debug9 {
	uint64_t u;
	struct bdk_rad_reg_debug9_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t eod                         : 1;  /**< RO/H - ICTL eod flag */
		uint64_t ini                         : 1;  /**< RO/H - ICTL init flag */
		uint64_t q                           : 1;  /**< RO/H - ICTL q enable */
		uint64_t p                           : 1;  /**< RO/H - ICTL p enable */
		uint64_t mul                         : 8;  /**< RO/H - ICTL multiplier */
		uint64_t idx                         : 8;  /**< RO/H - ICTL index */
#else
		uint64_t idx                         : 8;
		uint64_t mul                         : 8;
		uint64_t p                           : 1;
		uint64_t q                           : 1;
		uint64_t ini                         : 1;
		uint64_t eod                         : 1;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_rad_reg_debug9_s        cn85xx; */
	/* struct bdk_rad_reg_debug9_s        cn88xx; */
} bdk_rad_reg_debug9_t;

#define BDK_RAD_REG_DEBUG9 BDK_RAD_REG_DEBUG9_FUNC()
static inline uint64_t BDK_RAD_REG_DEBUG9_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_DEBUG9_FUNC(void)
{
	return 0x0000870000000148ull;
}
#define typedef_BDK_RAD_REG_DEBUG9 bdk_rad_reg_debug9_t
#define bustype_BDK_RAD_REG_DEBUG9 BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_DEBUG9 0
#define arguments_BDK_RAD_REG_DEBUG9 -1,-1,-1,-1
#define basename_BDK_RAD_REG_DEBUG9 "RAD_REG_DEBUG9"


/**
 * NCB - rad_reg_polynomial
 *
 * The polynomial is x^8 + C7*x^7 + C6*x^6 + C5*x^5 + C4*x^4 + C3*x^3 + C2*x^2 + C1*x^1 + C0.
 *
 */
typedef union bdk_rad_reg_polynomial {
	uint64_t u;
	struct bdk_rad_reg_polynomial_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t coeffs                      : 8;  /**< R/W - Coefficients of GF(2^8) irreducible polynomial */
#else
		uint64_t coeffs                      : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_rad_reg_polynomial_s    cn85xx; */
	/* struct bdk_rad_reg_polynomial_s    cn88xx; */
} bdk_rad_reg_polynomial_t;

#define BDK_RAD_REG_POLYNOMIAL BDK_RAD_REG_POLYNOMIAL_FUNC()
static inline uint64_t BDK_RAD_REG_POLYNOMIAL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_POLYNOMIAL_FUNC(void)
{
	return 0x0000870000000010ull;
}
#define typedef_BDK_RAD_REG_POLYNOMIAL bdk_rad_reg_polynomial_t
#define bustype_BDK_RAD_REG_POLYNOMIAL BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_POLYNOMIAL 0
#define arguments_BDK_RAD_REG_POLYNOMIAL -1,-1,-1,-1
#define basename_BDK_RAD_REG_POLYNOMIAL "RAD_REG_POLYNOMIAL"


/**
 * NCB - rad_reg_read_idx
 *
 * This register is for debug purposes only. It provides the read index during a CSR read
 * operation to any of the CSRs that are physically stored as memories. The mnemonics for these
 * CSRs begin with the prefix RAD_MEM_.
 * IDX[7:0] is the read index. INC[7:0] is an increment that is added to IDX[7:0] after any
 * CSR read. The intended use is to initially write this CSR such that IDX = 0 and INC = 1. Then,
 * the entire contents of a CSR memory can be read with consecutive CSR read commands.
 */
typedef union bdk_rad_reg_read_idx {
	uint64_t u;
	struct bdk_rad_reg_read_idx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t inc                         : 8;  /**< R/W - Increment to add to the current index for the next index. */
		uint64_t idx                         : 8;  /**< R/W - Index to use for next memory CSR read operation. */
#else
		uint64_t idx                         : 8;
		uint64_t inc                         : 8;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_rad_reg_read_idx_s      cn85xx; */
	/* struct bdk_rad_reg_read_idx_s      cn88xx; */
} bdk_rad_reg_read_idx_t;

#define BDK_RAD_REG_READ_IDX BDK_RAD_REG_READ_IDX_FUNC()
static inline uint64_t BDK_RAD_REG_READ_IDX_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RAD_REG_READ_IDX_FUNC(void)
{
	return 0x0000870000000018ull;
}
#define typedef_BDK_RAD_REG_READ_IDX bdk_rad_reg_read_idx_t
#define bustype_BDK_RAD_REG_READ_IDX BDK_CSR_TYPE_NCB
#define busnum_BDK_RAD_REG_READ_IDX 0
#define arguments_BDK_RAD_REG_READ_IDX -1,-1,-1,-1
#define basename_BDK_RAD_REG_READ_IDX "RAD_REG_READ_IDX"

#endif /* __BDK_CSRS_RAD__ */
