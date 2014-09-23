#ifndef __BDK_CSRS_OCLA__
#define __BDK_CSRS_OCLA__
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
 * Cavium OCLA.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration OCLA_INT_VEC_E
 *
 * OCLA MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum ocla_int_vec_e {
	OCLA_INT_VEC_E_INTS = 0x0,
	OCLA_INT_VEC_E_ENUM_LAST = 0x1,
};


/**
 * Structure OCLA_CAP_CTL_S
 *
 * OCLA Capture Control Structure
 * Control packets are indicated by an entry's bit 37 being set, and described by the
 * OCLA_CAP_CTL_S structure:
 */
union ocla_cap_ctl_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_38_63              : 26; /**< [ 63: 38] Reserved */
		uint64_t ctl                         : 1;  /**< [ 37: 37] Indicates a control word. Always set for control structures. */
		uint64_t sinfo                       : 1;  /**< [ 36: 36] Indicates FSM()_STATE()[SINFO_SET] was set for the state that led to the capture state.
                                                                 This allows the FSM to optionally communicate its current state to observing software;
                                                                 SINFO is otherwise opaque to reassembling the trace information. */
		uint64_t eot1                        : 1;  /**< [ 35: 35] End of duplicated capture for high data. Symmetric with EOT0 description; see [EOT0]. */
		uint64_t eot0                        : 1;  /**< [ 34: 34] End of duplicated capture for low data. When set, CYCLE indicates the cycle at which the
                                                                 previous entry of low data stopped being replicated. This may be set along with SOT0 to
                                                                 indicate a repeat followed by new sequence. */
		uint64_t sot1                        : 1;  /**< [ 33: 33] Start transition from no-capture to capture or duplicated data stopped while capturing for
                                                                 high data. When set, CYCLE indicates the cycle number of the next new high data, minus one
                                                                 cycle. */
		uint64_t sot0                        : 1;  /**< [ 32: 32] Start transition from no-capture to capture or duplicated data stopped while capturing for
                                                                 low data. When set, CYCLE indicates the cycle number of the next new low data, minus one
                                                                 cycle. */
		uint64_t cycle                       : 32; /**< [ 31:  0] Cycle at which this control entry was written, from OCLA()_TIME register. */
#else
		uint64_t cycle                       : 32;
		uint64_t sot0                        : 1;
		uint64_t sot1                        : 1;
		uint64_t eot0                        : 1;
		uint64_t eot1                        : 1;
		uint64_t sinfo                       : 1;
		uint64_t ctl                         : 1;
		uint64_t reserved_38_63              : 26;
#endif
	} s;
};

/**
 * Structure OCLA_CAP_DAT_S
 *
 * OCLA Capture Data Structure
 * Data packets are indicated by an entry's bit 37 being clear, and described by the
 * OCLA_CAP_DAT_S structure:
 */
union ocla_cap_dat_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_38_63              : 26; /**< [ 63: 38] Reserved */
		uint64_t ctl                         : 1;  /**< [ 37: 37] Indicates a control word. Always clear for data structures. */
		uint64_t hi                          : 1;  /**< [ 36: 36] Set to indicate a sample of high data, clear for a sample of low data. */
		uint64_t data                        : 36; /**< [ 35:  0] Captured trace data. */
#else
		uint64_t data                        : 36;
		uint64_t hi                          : 1;
		uint64_t ctl                         : 1;
		uint64_t reserved_38_63              : 26;
#endif
	} s;
};


/**
 * RSL - ocla#_bist_result
 *
 * This register provides access to the internal BIST results. Each bit is the BIST result of an
 * individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union bdk_oclax_bist_result {
	uint64_t u;
	struct bdk_oclax_bist_result_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t dat                         : 1;  /**< RO - BIST result of the DAT memory. */
#else
		uint64_t dat                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_oclax_bist_result_s     cn85xx; */
	/* struct bdk_oclax_bist_result_s     cn88xx; */
	/* struct bdk_oclax_bist_result_s     cn88xxp1; */
} bdk_oclax_bist_result_t;

static inline uint64_t BDK_OCLAX_BIST_RESULT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_BIST_RESULT(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000040ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_BIST_RESULT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_BIST_RESULT(...) bdk_oclax_bist_result_t
#define bustype_BDK_OCLAX_BIST_RESULT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_BIST_RESULT(p1) (p1)
#define arguments_BDK_OCLAX_BIST_RESULT(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_BIST_RESULT(...) "OCLAX_BIST_RESULT"


/**
 * RSL - ocla#_cdh#_ctl
 */
typedef union bdk_oclax_cdhx_ctl {
	uint64_t u;
	struct bdk_oclax_cdhx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t dup                         : 1;  /**< R/W - Retain duplicates in the data stream. */
		uint64_t dis_stamp                   : 1;  /**< R/W - Remove time stamps from data stream. */
		uint64_t cap_ctl                     : 4;  /**< R/W - Minterms that will cause data to be captured. These minterms are the four inputs to a 4-1
                                                                 mux selected by PLA1 and 0. The output is thus calculated from the equation:
                                                                   fsmcap0 = OCLA(0..4)_FSM(0)_STATE[state0][CAP].
                                                                   fsmcap1 = OCLA(0..4)_FSM(1)_STATE[state1][CAP].
                                                                   out = (   (\<3\> & fsmcap0 & fsmcap0)

                                                                 _        || (\<2\> & fsmcap1 & !fsmcap0)

                                                                 _        || (\<1\> & !fsmcap1 & fsmcap0)

                                                                 _        || (\<0\> & !fsmcap1 & !fsmcap0)).

                                                                 Common examples:
                                                                 0x0 = No capture.
                                                                 0x2 = Capture when fsmcap0 requests capture.
                                                                 0x4 = Capture when fsmcap1 requests capture.
                                                                 0x6 = Capture on fsmcap0 | fsmcap1.
                                                                 0x8 = Capture on fsmcap0 & fsmcap1.
                                                                 0xF = Always capture. */
#else
		uint64_t cap_ctl                     : 4;
		uint64_t dis_stamp                   : 1;
		uint64_t dup                         : 1;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_oclax_cdhx_ctl_s        cn85xx; */
	/* struct bdk_oclax_cdhx_ctl_s        cn88xx; */
	/* struct bdk_oclax_cdhx_ctl_s        cn88xxp1; */
} bdk_oclax_cdhx_ctl_t;

static inline uint64_t BDK_OCLAX_CDHX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_CDHX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 4)) && ((param2 <= 1)))
		return 0x000087E0A8000600ull + (param1 & 7) * 0x1000000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_OCLAX_CDHX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_CDHX_CTL(...) bdk_oclax_cdhx_ctl_t
#define bustype_BDK_OCLAX_CDHX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_CDHX_CTL(p1,p2) (p1)
#define arguments_BDK_OCLAX_CDHX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCLAX_CDHX_CTL(...) "OCLAX_CDHX_CTL"


/**
 * RSL - ocla#_const
 */
typedef union bdk_oclax_const {
	uint64_t u;
	struct bdk_oclax_const_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t dat_size                    : 16; /**< RO - Size of data RAM in units of 36-bit entries. This value is subject to change between chip
                                                                 passes, and software should thus use this value rather than a hard coded constant.
                                                                 OCLA(0..3) size is 4096, OCLA(4) size is 8192. */
#else
		uint64_t dat_size                    : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_oclax_const_s           cn85xx; */
	/* struct bdk_oclax_const_s           cn88xx; */
	/* struct bdk_oclax_const_s           cn88xxp1; */
} bdk_oclax_const_t;

static inline uint64_t BDK_OCLAX_CONST(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_CONST(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_CONST", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_CONST(...) bdk_oclax_const_t
#define bustype_BDK_OCLAX_CONST(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_CONST(p1) (p1)
#define arguments_BDK_OCLAX_CONST(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_CONST(...) "OCLAX_CONST"


/**
 * RSL - ocla#_dat#
 */
typedef union bdk_oclax_datx {
	uint64_t u;
	struct bdk_oclax_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_38_63              : 26;
		uint64_t entry                       : 38; /**< RO/H - Captured entry. Data is in the format described by OCLA_CAP_DAT_S or OCLA_CAP_CTL_S. */
#else
		uint64_t entry                       : 38;
		uint64_t reserved_38_63              : 26;
#endif
	} s;
	/* struct bdk_oclax_datx_s            cn85xx; */
	/* struct bdk_oclax_datx_s            cn88xx; */
	/* struct bdk_oclax_datx_s            cn88xxp1; */
} bdk_oclax_datx_t;

static inline uint64_t BDK_OCLAX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 4)) && ((param2 <= 8191)))
		return 0x000087E0A8400000ull + (param1 & 7) * 0x1000000ull + (param2 & 8191) * 0x8ull;
	csr_fatal("BDK_OCLAX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_DATX(...) bdk_oclax_datx_t
#define bustype_BDK_OCLAX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_DATX(p1,p2) (p1)
#define arguments_BDK_OCLAX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCLAX_DATX(...) "OCLAX_DATX"


/**
 * RSL - ocla#_dat_pop
 */
typedef union bdk_oclax_dat_pop {
	uint64_t u;
	struct bdk_oclax_dat_pop_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t valid                       : 1;  /**< RC/H - Valid entry. Indicates the FIFO contains data, and equivalent to OCLA()_FIFO_DEPTH[DEPTH] != 0. */
		uint64_t trig                        : 1;  /**< RO/H - Internal trigger set. Equivalent to OCLA()_STATE_INT[TRIG]. */
		uint64_t wmark                       : 1;  /**< RO/H - Internal buffer watermark reached. Equivalent to OCLA()_STATE_INT[WMARK]. */
		uint64_t reserved_38_60              : 23;
		uint64_t entry                       : 38; /**< RC/H - Captured entry. If VALID is set, has read side effect of unloading data by decrementing
                                                                 OCLA()_FIFO_DEPTH[DEPTH]. Data is in the format described by OCLA_CAP_DAT_S or
                                                                 OCLA_CAP_CTL_S.

                                                                 Note that unloading data will cause that data not to be sent to memory, therefore
                                                                 OCLA()_DAT_POP should not be read when OCLA()_FIFO_LIMIT[DDR] != all-ones. */
#else
		uint64_t entry                       : 38;
		uint64_t reserved_38_60              : 23;
		uint64_t wmark                       : 1;
		uint64_t trig                        : 1;
		uint64_t valid                       : 1;
#endif
	} s;
	/* struct bdk_oclax_dat_pop_s         cn85xx; */
	/* struct bdk_oclax_dat_pop_s         cn88xx; */
	/* struct bdk_oclax_dat_pop_s         cn88xxp1; */
} bdk_oclax_dat_pop_t;

static inline uint64_t BDK_OCLAX_DAT_POP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_DAT_POP(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000800ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_DAT_POP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_DAT_POP(...) bdk_oclax_dat_pop_t
#define bustype_BDK_OCLAX_DAT_POP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_DAT_POP(p1) (p1)
#define arguments_BDK_OCLAX_DAT_POP(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_DAT_POP(...) "OCLAX_DAT_POP"


/**
 * RSL - ocla#_fifo_depth
 */
typedef union bdk_oclax_fifo_depth {
	uint64_t u;
	struct bdk_oclax_fifo_depth_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t depth                       : 16; /**< RO/H - Current capture FIFO depth in 36-bit words. */
#else
		uint64_t depth                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_oclax_fifo_depth_s      cn85xx; */
	/* struct bdk_oclax_fifo_depth_s      cn88xx; */
	/* struct bdk_oclax_fifo_depth_s      cn88xxp1; */
} bdk_oclax_fifo_depth_t;

static inline uint64_t BDK_OCLAX_FIFO_DEPTH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_FIFO_DEPTH(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000200ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_FIFO_DEPTH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_FIFO_DEPTH(...) bdk_oclax_fifo_depth_t
#define bustype_BDK_OCLAX_FIFO_DEPTH(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_FIFO_DEPTH(p1) (p1)
#define arguments_BDK_OCLAX_FIFO_DEPTH(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_FIFO_DEPTH(...) "OCLAX_FIFO_DEPTH"


/**
 * RSL - ocla#_fifo_limit
 */
typedef union bdk_oclax_fifo_limit {
	uint64_t u;
	struct bdk_oclax_fifo_limit_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t overfull                    : 16; /**< R/W - Stop level. When OCLA()_FIFO_DEPTH \> [OVERFULL], stop capturing and set
                                                                 OCLA()_STATE_INT[OVERFULL]. This should be set to no more than
                                                                 OCLA()_CONST[DAT_SIZE] minus 26 when using DDR capture to insure that overflow can be
                                                                 detected. */
		uint64_t ddr                         : 16; /**< R/W - DDR level. When OCLA()_FIFO_DEPTH \> [DDR], FIFO entries will be removed, packed into a
                                                                 cache line, and overflowed to DDR/L2. All-ones disables overflow to DDR/L2. If non-zero
                                                                 must be at least 28. */
		uint64_t bp                          : 16; /**< R/W - Backpressure level. When OCLA()_FIFO_DEPTH \> [BP], OCLA will signal backpressure to
                                                                 coprocessors. All-ones disables indicating backpressure. */
		uint64_t wmark                       : 16; /**< R/W - Interrupt watermark level. When OCLA()_FIFO_DEPTH \> [WMARK], OCLA will set
                                                                 OCLA()_STATE_INT[WMARK] interrupt. All-ones disables setting the interrupt. */
#else
		uint64_t wmark                       : 16;
		uint64_t bp                          : 16;
		uint64_t ddr                         : 16;
		uint64_t overfull                    : 16;
#endif
	} s;
	/* struct bdk_oclax_fifo_limit_s      cn85xx; */
	/* struct bdk_oclax_fifo_limit_s      cn88xx; */
	/* struct bdk_oclax_fifo_limit_s      cn88xxp1; */
} bdk_oclax_fifo_limit_t;

static inline uint64_t BDK_OCLAX_FIFO_LIMIT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_FIFO_LIMIT(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000240ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_FIFO_LIMIT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_FIFO_LIMIT(...) bdk_oclax_fifo_limit_t
#define bustype_BDK_OCLAX_FIFO_LIMIT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_FIFO_LIMIT(p1) (p1)
#define arguments_BDK_OCLAX_FIFO_LIMIT(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_FIFO_LIMIT(...) "OCLAX_FIFO_LIMIT"


/**
 * RSL - ocla#_fifo_tail
 */
typedef union bdk_oclax_fifo_tail {
	uint64_t u;
	struct bdk_oclax_fifo_tail_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t tail                        : 16; /**< RO/H - Address last written into entry FIFO. */
#else
		uint64_t tail                        : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_oclax_fifo_tail_s       cn85xx; */
	/* struct bdk_oclax_fifo_tail_s       cn88xx; */
	/* struct bdk_oclax_fifo_tail_s       cn88xxp1; */
} bdk_oclax_fifo_tail_t;

static inline uint64_t BDK_OCLAX_FIFO_TAIL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_FIFO_TAIL(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000260ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_FIFO_TAIL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_FIFO_TAIL(...) bdk_oclax_fifo_tail_t
#define bustype_BDK_OCLAX_FIFO_TAIL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_FIFO_TAIL(p1) (p1)
#define arguments_BDK_OCLAX_FIFO_TAIL(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_FIFO_TAIL(...) "OCLAX_FIFO_TAIL"


/**
 * RSL - ocla#_fifo_trig
 */
typedef union bdk_oclax_fifo_trig {
	uint64_t u;
	struct bdk_oclax_fifo_trig_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t limit                       : 16; /**< R/W - Post-trigger number of entries to collect before stopping collection. If zero, collection
                                                                 will never stop, which may be desirable when overflowing to DDR/L2. Must be \<
                                                                 OCLA()_CONST[DAT_SIZE] - 5. */
		uint64_t cnt                         : 16; /**< R/W/H - Number of entries collected since trigger. Cleared when OCLA()_STATE_INT[TRIG] clear. */
#else
		uint64_t cnt                         : 16;
		uint64_t limit                       : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_oclax_fifo_trig_s       cn85xx; */
	/* struct bdk_oclax_fifo_trig_s       cn88xx; */
	/* struct bdk_oclax_fifo_trig_s       cn88xxp1; */
} bdk_oclax_fifo_trig_t;

static inline uint64_t BDK_OCLAX_FIFO_TRIG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_FIFO_TRIG(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A80002A0ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_FIFO_TRIG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_FIFO_TRIG(...) bdk_oclax_fifo_trig_t
#define bustype_BDK_OCLAX_FIFO_TRIG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_FIFO_TRIG(p1) (p1)
#define arguments_BDK_OCLAX_FIFO_TRIG(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_FIFO_TRIG(...) "OCLAX_FIFO_TRIG"


/**
 * RSL - ocla#_fifo_wrap
 */
typedef union bdk_oclax_fifo_wrap {
	uint64_t u;
	struct bdk_oclax_fifo_wrap_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t wraps                       : 32; /**< R/W/H - Number of times FIFO has wrapped since trigger. Cleared when OCLA()_STATE_INT[TRIG] clear. */
#else
		uint64_t wraps                       : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_oclax_fifo_wrap_s       cn85xx; */
	/* struct bdk_oclax_fifo_wrap_s       cn88xx; */
	/* struct bdk_oclax_fifo_wrap_s       cn88xxp1; */
} bdk_oclax_fifo_wrap_t;

static inline uint64_t BDK_OCLAX_FIFO_WRAP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_FIFO_WRAP(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000280ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_FIFO_WRAP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_FIFO_WRAP(...) bdk_oclax_fifo_wrap_t
#define bustype_BDK_OCLAX_FIFO_WRAP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_FIFO_WRAP(p1) (p1)
#define arguments_BDK_OCLAX_FIFO_WRAP(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_FIFO_WRAP(...) "OCLAX_FIFO_WRAP"


/**
 * RSL - ocla#_fsm#_and#_i#
 *
 * Values for PLA-AND plane. AND(0..15) represents the 15 allowed AND terms. I(0..1) for I=0
 * indicates the term non-inverted, for I=1 indicates the term inverted. Any AND tree may be
 * disabled by setting the same bit in both _I(0) and _I(1), as '((1) & !(1))' is always false.
 */
typedef union bdk_oclax_fsmx_andx_ix {
	uint64_t u;
	struct bdk_oclax_fsmx_andx_ix_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t trig                        : 1;  /**< RAZ - Reserved. */
		uint64_t mcd                         : 3;  /**< R/W - AND plane control for multichip debug (MCD) 0..2 FSM inputs. */
		uint64_t match                       : 4;  /**< R/W - AND plane control for matcher 0..3 FSM inputs. */
		uint64_t fsm1_state                  : 4;  /**< R/W - AND plane control for FSM 1 last state input. */
		uint64_t fsm0_state                  : 4;  /**< R/W - AND plane control for FSM 0 last state input. */
#else
		uint64_t fsm0_state                  : 4;
		uint64_t fsm1_state                  : 4;
		uint64_t match                       : 4;
		uint64_t mcd                         : 3;
		uint64_t trig                        : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	struct bdk_oclax_fsmx_andx_ix_cn85xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t mcd                         : 3;  /**< R/W - Multichip debug (MCD) 0..2 inputs. */
		uint64_t match                       : 4;  /**< R/W - Matcher 0..3 input. */
		uint64_t fsm1_state                  : 4;  /**< R/W - FSM 1 last state. */
		uint64_t fsm0_state                  : 4;  /**< R/W - FSM 0 last state. */
#else
		uint64_t fsm0_state                  : 4;
		uint64_t fsm1_state                  : 4;
		uint64_t match                       : 4;
		uint64_t mcd                         : 3;
		uint64_t reserved_15_63              : 49;
#endif
	} cn85xx;
	/* struct bdk_oclax_fsmx_andx_ix_s    cn88xx; */
	/* struct bdk_oclax_fsmx_andx_ix_s    cn88xxp1; */
} bdk_oclax_fsmx_andx_ix_t;

static inline uint64_t BDK_OCLAX_FSMX_ANDX_IX(unsigned long param1, unsigned long param2, unsigned long param3, unsigned long param4) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_FSMX_ANDX_IX(unsigned long param1, unsigned long param2, unsigned long param3, unsigned long param4)
{
	if (((param1 <= 4)) && ((param2 <= 1)) && ((param3 <= 15)) && ((param4 <= 1)))
		return 0x000087E0A8300000ull + (param1 & 7) * 0x1000000ull + (param2 & 1) * 0x1000ull + (param3 & 15) * 0x10ull + (param4 & 1) * 0x8ull;
	csr_fatal("BDK_OCLAX_FSMX_ANDX_IX", 4, param1, param2, param3, param4); /* No return */
}
#define typedef_BDK_OCLAX_FSMX_ANDX_IX(...) bdk_oclax_fsmx_andx_ix_t
#define bustype_BDK_OCLAX_FSMX_ANDX_IX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_FSMX_ANDX_IX(p1,p2,p3,p4) (p1)
#define arguments_BDK_OCLAX_FSMX_ANDX_IX(p1,p2,p3,p4) (p1),(p2),(p3),(p4)
#define basename_BDK_OCLAX_FSMX_ANDX_IX(...) "OCLAX_FSMX_ANDX_IX"


/**
 * RSL - ocla#_fsm#_or#
 */
typedef union bdk_oclax_fsmx_orx {
	uint64_t u;
	struct bdk_oclax_fsmx_orx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t or_state                    : 16; /**< R/W - Column to drive on PLA OR-plane. */
#else
		uint64_t or_state                    : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_oclax_fsmx_orx_s        cn85xx; */
	/* struct bdk_oclax_fsmx_orx_s        cn88xx; */
	/* struct bdk_oclax_fsmx_orx_s        cn88xxp1; */
} bdk_oclax_fsmx_orx_t;

static inline uint64_t BDK_OCLAX_FSMX_ORX(unsigned long param1, unsigned long param2, unsigned long param3) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_FSMX_ORX(unsigned long param1, unsigned long param2, unsigned long param3)
{
	if (((param1 <= 4)) && ((param2 <= 1)) && ((param3 <= 15)))
		return 0x000087E0A8310000ull + (param1 & 7) * 0x1000000ull + (param2 & 1) * 0x1000ull + (param3 & 15) * 0x8ull;
	csr_fatal("BDK_OCLAX_FSMX_ORX", 3, param1, param2, param3, 0); /* No return */
}
#define typedef_BDK_OCLAX_FSMX_ORX(...) bdk_oclax_fsmx_orx_t
#define bustype_BDK_OCLAX_FSMX_ORX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_FSMX_ORX(p1,p2,p3) (p1)
#define arguments_BDK_OCLAX_FSMX_ORX(p1,p2,p3) (p1),(p2),(p3),-1
#define basename_BDK_OCLAX_FSMX_ORX(...) "OCLAX_FSMX_ORX"


/**
 * RSL - ocla#_fsm#_state#
 *
 * See State Outputs for more details on each of these actions.
 *
 */
typedef union bdk_oclax_fsmx_statex {
	uint64_t u;
	struct bdk_oclax_fsmx_statex_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_31_63              : 33;
		uint64_t sinfo_set                   : 1;  /**< R/W - If a control packet is generated in this state (due to capture starting
                                                                 in the next cycle), set OCLA_CAP_CTL_S[SINFO]. */
		uint64_t set_int                     : 1;  /**< R/W - In this state set interrupt. */
		uint64_t cap                         : 1;  /**< R/W - In this state request capture this cycle. */
		uint64_t set_mcd                     : 3;  /**< R/W - In this state set MCD. */
		uint64_t set_trig                    : 1;  /**< R/W - In this state set internal trigger indication. */
		uint64_t reserved_20_23              : 4;
		uint64_t set_val                     : 4;  /**< R/W - In this state store match value into matcher 0..3. */
		uint64_t reserved_12_15              : 4;
		uint64_t clr_cnt                     : 4;  /**< R/W - In this state clear match counter. */
		uint64_t reserved_4_7                : 4;
		uint64_t inc_cnt                     : 4;  /**< R/W - In this state increment match counter. See State Outputs for more information on this or
                                                                 any of the bits above. */
#else
		uint64_t inc_cnt                     : 4;
		uint64_t reserved_4_7                : 4;
		uint64_t clr_cnt                     : 4;
		uint64_t reserved_12_15              : 4;
		uint64_t set_val                     : 4;
		uint64_t reserved_20_23              : 4;
		uint64_t set_trig                    : 1;
		uint64_t set_mcd                     : 3;
		uint64_t cap                         : 1;
		uint64_t set_int                     : 1;
		uint64_t sinfo_set                   : 1;
		uint64_t reserved_31_63              : 33;
#endif
	} s;
	/* struct bdk_oclax_fsmx_statex_s     cn85xx; */
	/* struct bdk_oclax_fsmx_statex_s     cn88xx; */
	/* struct bdk_oclax_fsmx_statex_s     cn88xxp1; */
} bdk_oclax_fsmx_statex_t;

static inline uint64_t BDK_OCLAX_FSMX_STATEX(unsigned long param1, unsigned long param2, unsigned long param3) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_FSMX_STATEX(unsigned long param1, unsigned long param2, unsigned long param3)
{
	if (((param1 <= 4)) && ((param2 <= 1)) && ((param3 <= 15)))
		return 0x000087E0A8320000ull + (param1 & 7) * 0x1000000ull + (param2 & 1) * 0x1000ull + (param3 & 15) * 0x8ull;
	csr_fatal("BDK_OCLAX_FSMX_STATEX", 3, param1, param2, param3, 0); /* No return */
}
#define typedef_BDK_OCLAX_FSMX_STATEX(...) bdk_oclax_fsmx_statex_t
#define bustype_BDK_OCLAX_FSMX_STATEX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_FSMX_STATEX(p1,p2,p3) (p1)
#define arguments_BDK_OCLAX_FSMX_STATEX(p1,p2,p3) (p1),(p2),(p3),-1
#define basename_BDK_OCLAX_FSMX_STATEX(...) "OCLAX_FSMX_STATEX"


/**
 * RSL - ocla#_gen_ctl
 */
typedef union bdk_oclax_gen_ctl {
	uint64_t u;
	struct bdk_oclax_gen_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t mcdtrig                     : 3;  /**< RAZ - Reserved. */
		uint64_t exten                       : 1;  /**< R/W - Enable external triggering.
                                                                 0 = External triggering ignored.
                                                                 1 = When the external trigger pin selected with GPIO_PIN_SEL_E::OCLA_EXT_TRIGGER
                                                                 is high it will cause
                                                                 triggerring and set OCLA()_STATE_SET[TRIG]. The external device must de-assert the
                                                                 signal (it is not edge sensitive.) */
		uint64_t den                         : 1;  /**< R/W - Enable data bus and counter clocking. When set, the OCLA inbound data bus may be used and
                                                                 counters may increment. When clear, the bus is always zero and internal flops may be clock
                                                                 gated off to save power. Must be set for normal operation. */
		uint64_t stt                         : 1;  /**< R/W - Store to DDR directly, bypassing L2 cache. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t stt                         : 1;
		uint64_t den                         : 1;
		uint64_t exten                       : 1;
		uint64_t mcdtrig                     : 3;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	struct bdk_oclax_gen_ctl_cn85xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t exten                       : 1;  /**< R/W - Enable external triggering.
                                                                 0 = External triggering ignored.
                                                                 1 = When the external trigger pin selected with GPIO_PIN_SEL_E::OCLA_EXT_TRIGGER
                                                                 is high it will cause
                                                                 triggerring and set OCLA()_STATE_SET[TRIG]. The external device must de-assert the
                                                                 signal to release the trigger (it is not edge sensitive.) */
		uint64_t den                         : 1;  /**< R/W - Enable data bus and counter clocking. When set, the OCLA inbound data bus may be used and
                                                                 counters may increment. When clear, the bus is always zero and internal flops may be clock
                                                                 gated off to save power. Must be set for normal operation. */
		uint64_t stt                         : 1;  /**< R/W - Store to DDR directly, bypassing L2 cache. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t stt                         : 1;
		uint64_t den                         : 1;
		uint64_t exten                       : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} cn85xx;
	/* struct bdk_oclax_gen_ctl_s         cn88xx; */
	/* struct bdk_oclax_gen_ctl_s         cn88xxp1; */
} bdk_oclax_gen_ctl_t;

static inline uint64_t BDK_OCLAX_GEN_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_GEN_CTL(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000060ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_GEN_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_GEN_CTL(...) bdk_oclax_gen_ctl_t
#define bustype_BDK_OCLAX_GEN_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_GEN_CTL(p1) (p1)
#define arguments_BDK_OCLAX_GEN_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_GEN_CTL(...) "OCLAX_GEN_CTL"


/**
 * RSL - ocla#_mat#_count
 */
typedef union bdk_oclax_matx_count {
	uint64_t u;
	struct bdk_oclax_matx_count_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t count                       : 32; /**< R/W/H - Current counter value. Note software must reset this to zero (or the appropriate count)
                                                                 before starting capture. */
#else
		uint64_t count                       : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_oclax_matx_count_s      cn85xx; */
	/* struct bdk_oclax_matx_count_s      cn88xx; */
	/* struct bdk_oclax_matx_count_s      cn88xxp1; */
} bdk_oclax_matx_count_t;

static inline uint64_t BDK_OCLAX_MATX_COUNT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_MATX_COUNT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 4)) && ((param2 <= 3)))
		return 0x000087E0A8230000ull + (param1 & 7) * 0x1000000ull + (param2 & 3) * 0x1000ull;
	csr_fatal("BDK_OCLAX_MATX_COUNT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_MATX_COUNT(...) bdk_oclax_matx_count_t
#define bustype_BDK_OCLAX_MATX_COUNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_MATX_COUNT(p1,p2) (p1)
#define arguments_BDK_OCLAX_MATX_COUNT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCLAX_MATX_COUNT(...) "OCLAX_MATX_COUNT"


/**
 * RSL - ocla#_mat#_ctl
 */
typedef union bdk_oclax_matx_ctl {
	uint64_t u;
	struct bdk_oclax_matx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t fsm_ctr                     : 1;  /**< R/W - What output matcher provides to FSM:
                                                                 0 = FSM receives raw match signal, asserting only in those cycles with matches.
                                                                 1 = FSM receives OCLA()_MAT()_COUNT \>= OCLA()_MAT()_THRESH. */
		uint64_t inc_match                   : 1;  /**< R/W - Increment OCLA()_MAT()_COUNT counter automatically on each match. */
		uint64_t shift                       : 6;  /**< R/W - Right rotation amount to apply to data loaded into OCLA()_MAT()_VALUE()
                                                                 register when FSM requests a value load. */
#else
		uint64_t shift                       : 6;
		uint64_t inc_match                   : 1;
		uint64_t fsm_ctr                     : 1;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_oclax_matx_ctl_s        cn85xx; */
	/* struct bdk_oclax_matx_ctl_s        cn88xx; */
	/* struct bdk_oclax_matx_ctl_s        cn88xxp1; */
} bdk_oclax_matx_ctl_t;

static inline uint64_t BDK_OCLAX_MATX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_MATX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 4)) && ((param2 <= 3)))
		return 0x000087E0A8200000ull + (param1 & 7) * 0x1000000ull + (param2 & 3) * 0x1000ull;
	csr_fatal("BDK_OCLAX_MATX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_MATX_CTL(...) bdk_oclax_matx_ctl_t
#define bustype_BDK_OCLAX_MATX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_MATX_CTL(p1,p2) (p1)
#define arguments_BDK_OCLAX_MATX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCLAX_MATX_CTL(...) "OCLAX_MATX_CTL"


/**
 * RSL - ocla#_mat#_mask#
 */
typedef union bdk_oclax_matx_maskx {
	uint64_t u;
	struct bdk_oclax_matx_maskx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t mask                        : 36; /**< R/W - Bitmask of which bits in OCLA()_MAT()_VALUE() are to be compared.

                                                                 Each bit of OCLA()_MAT()_VALUE() and OCLA()_MAT()_MASK() are combined as
                                                                 follows:

                                                                 _ If MASK = 1 and VALUE = 0, matches when data = "0".
                                                                 _ If MASK = 1 and VALUE = 1, matches when data = "1".
                                                                 _ If MASK = 0 and VALUE = 0, matches any data.
                                                                 _ If MASK = 0 and VALUE = 1, reserved in pass 1, matches any data pass 2 and later. */
#else
		uint64_t mask                        : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_oclax_matx_maskx_s      cn85xx; */
	/* struct bdk_oclax_matx_maskx_s      cn88xx; */
	/* struct bdk_oclax_matx_maskx_s      cn88xxp1; */
} bdk_oclax_matx_maskx_t;

static inline uint64_t BDK_OCLAX_MATX_MASKX(unsigned long param1, unsigned long param2, unsigned long param3) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_MATX_MASKX(unsigned long param1, unsigned long param2, unsigned long param3)
{
	if (((param1 <= 4)) && ((param2 <= 3)) && ((param3 <= 1)))
		return 0x000087E0A8220000ull + (param1 & 7) * 0x1000000ull + (param2 & 3) * 0x1000ull + (param3 & 1) * 0x8ull;
	csr_fatal("BDK_OCLAX_MATX_MASKX", 3, param1, param2, param3, 0); /* No return */
}
#define typedef_BDK_OCLAX_MATX_MASKX(...) bdk_oclax_matx_maskx_t
#define bustype_BDK_OCLAX_MATX_MASKX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_MATX_MASKX(p1,p2,p3) (p1)
#define arguments_BDK_OCLAX_MATX_MASKX(p1,p2,p3) (p1),(p2),(p3),-1
#define basename_BDK_OCLAX_MATX_MASKX(...) "OCLAX_MATX_MASKX"


/**
 * RSL - ocla#_mat#_thresh
 */
typedef union bdk_oclax_matx_thresh {
	uint64_t u;
	struct bdk_oclax_matx_thresh_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t thresh                      : 32; /**< R/W - Counter threshold value. Compared against OCLA()_MAT()_COUNT to assert matcher
                                                                 output, and set OCLA()_STATE_INT[OVFL]. */
#else
		uint64_t thresh                      : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_oclax_matx_thresh_s     cn85xx; */
	/* struct bdk_oclax_matx_thresh_s     cn88xx; */
	/* struct bdk_oclax_matx_thresh_s     cn88xxp1; */
} bdk_oclax_matx_thresh_t;

static inline uint64_t BDK_OCLAX_MATX_THRESH(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_MATX_THRESH(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 4)) && ((param2 <= 3)))
		return 0x000087E0A8240000ull + (param1 & 7) * 0x1000000ull + (param2 & 3) * 0x1000ull;
	csr_fatal("BDK_OCLAX_MATX_THRESH", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_MATX_THRESH(...) bdk_oclax_matx_thresh_t
#define bustype_BDK_OCLAX_MATX_THRESH(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_MATX_THRESH(p1,p2) (p1)
#define arguments_BDK_OCLAX_MATX_THRESH(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCLAX_MATX_THRESH(...) "OCLAX_MATX_THRESH"


/**
 * RSL - ocla#_mat#_value#
 */
typedef union bdk_oclax_matx_valuex {
	uint64_t u;
	struct bdk_oclax_matx_valuex_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t mask                        : 36; /**< R/W/H - Data value to compare against when corresponding bits of OCLA()_MAT()_MASK()
                                                                 are set. Value may be updated with OCLA()_FSM()_STATE()[SET_VAL]. */
#else
		uint64_t mask                        : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_oclax_matx_valuex_s     cn85xx; */
	/* struct bdk_oclax_matx_valuex_s     cn88xx; */
	/* struct bdk_oclax_matx_valuex_s     cn88xxp1; */
} bdk_oclax_matx_valuex_t;

static inline uint64_t BDK_OCLAX_MATX_VALUEX(unsigned long param1, unsigned long param2, unsigned long param3) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_MATX_VALUEX(unsigned long param1, unsigned long param2, unsigned long param3)
{
	if (((param1 <= 4)) && ((param2 <= 3)) && ((param3 <= 1)))
		return 0x000087E0A8210000ull + (param1 & 7) * 0x1000000ull + (param2 & 3) * 0x1000ull + (param3 & 1) * 0x8ull;
	csr_fatal("BDK_OCLAX_MATX_VALUEX", 3, param1, param2, param3, 0); /* No return */
}
#define typedef_BDK_OCLAX_MATX_VALUEX(...) bdk_oclax_matx_valuex_t
#define bustype_BDK_OCLAX_MATX_VALUEX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_MATX_VALUEX(p1,p2,p3) (p1)
#define arguments_BDK_OCLAX_MATX_VALUEX(p1,p2,p3) (p1),(p2),(p3),-1
#define basename_BDK_OCLAX_MATX_VALUEX(...) "OCLAX_MATX_VALUEX"


/**
 * RSL - ocla#_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the OCLA_INT_VEC_E enumeration.
 *
 */
typedef union bdk_oclax_msix_pbax {
	uint64_t u;
	struct bdk_oclax_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated OCLA_MSIX_VEC()_CTL, enumerated by OCLA_INT_VEC_E.
                                                                 Bits that have no associated OCLA_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_oclax_msix_pbax_s       cn85xx; */
	/* struct bdk_oclax_msix_pbax_s       cn88xx; */
	/* struct bdk_oclax_msix_pbax_s       cn88xxp1; */
} bdk_oclax_msix_pbax_t;

static inline uint64_t BDK_OCLAX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 4)) && ((param2 == 0)))
		return 0x000087E0A8FF0000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_MSIX_PBAX(...) bdk_oclax_msix_pbax_t
#define bustype_BDK_OCLAX_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_OCLAX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCLAX_MSIX_PBAX(...) "OCLAX_MSIX_PBAX"


/**
 * RSL - ocla#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the OCLA_INT_VEC_E enumeration.
 *
 */
typedef union bdk_oclax_msix_vecx_addr {
	uint64_t u;
	struct bdk_oclax_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's OCLA()_MSIX_VEC()_ADDR, OCLA()_MSIX_VEC()_CTL, and
                                                                 corresponding bit of OCLA()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_OCLA()_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if [SECVEC]
                                                                 was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_oclax_msix_vecx_addr_s  cn85xx; */
	/* struct bdk_oclax_msix_vecx_addr_s  cn88xx; */
	/* struct bdk_oclax_msix_vecx_addr_s  cn88xxp1; */
} bdk_oclax_msix_vecx_addr_t;

static inline uint64_t BDK_OCLAX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 4)) && ((param2 == 0)))
		return 0x000087E0A8F00000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_MSIX_VECX_ADDR(...) bdk_oclax_msix_vecx_addr_t
#define bustype_BDK_OCLAX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_OCLAX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCLAX_MSIX_VECX_ADDR(...) "OCLAX_MSIX_VECX_ADDR"


/**
 * RSL - ocla#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the OCLA_INT_VEC_E enumeration.
 *
 */
typedef union bdk_oclax_msix_vecx_ctl {
	uint64_t u;
	struct bdk_oclax_msix_vecx_ctl_s {
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
	/* struct bdk_oclax_msix_vecx_ctl_s   cn85xx; */
	/* struct bdk_oclax_msix_vecx_ctl_s   cn88xx; */
	/* struct bdk_oclax_msix_vecx_ctl_s   cn88xxp1; */
} bdk_oclax_msix_vecx_ctl_t;

static inline uint64_t BDK_OCLAX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 4)) && ((param2 == 0)))
		return 0x000087E0A8F00008ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_MSIX_VECX_CTL(...) bdk_oclax_msix_vecx_ctl_t
#define bustype_BDK_OCLAX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_OCLAX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCLAX_MSIX_VECX_CTL(...) "OCLAX_MSIX_VECX_CTL"


/**
 * RSL - ocla#_raw#
 */
typedef union bdk_oclax_rawx {
	uint64_t u;
	struct bdk_oclax_rawx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw value of debug bus input signals into OCLA. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_oclax_rawx_s            cn85xx; */
	/* struct bdk_oclax_rawx_s            cn88xx; */
	/* struct bdk_oclax_rawx_s            cn88xxp1; */
} bdk_oclax_rawx_t;

static inline uint64_t BDK_OCLAX_RAWX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_RAWX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 4)) && ((param2 <= 1)))
		return 0x000087E0A8000100ull + (param1 & 7) * 0x1000000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_OCLAX_RAWX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_RAWX(...) bdk_oclax_rawx_t
#define bustype_BDK_OCLAX_RAWX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_RAWX(p1,p2) (p1)
#define arguments_BDK_OCLAX_RAWX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCLAX_RAWX(...) "OCLAX_RAWX"


/**
 * RSL - ocla#_sft_rst
 */
typedef union bdk_oclax_sft_rst {
	uint64_t u;
	struct bdk_oclax_sft_rst_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t reset                       : 1;  /**< R/W - Reset. When set, causes a block reset, except RSL. */
#else
		uint64_t reset                       : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_oclax_sft_rst_s         cn85xx; */
	/* struct bdk_oclax_sft_rst_s         cn88xx; */
	/* struct bdk_oclax_sft_rst_s         cn88xxp1; */
} bdk_oclax_sft_rst_t;

static inline uint64_t BDK_OCLAX_SFT_RST(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_SFT_RST(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000020ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_SFT_RST", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_SFT_RST(...) bdk_oclax_sft_rst_t
#define bustype_BDK_OCLAX_SFT_RST(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_SFT_RST(p1) (p1)
#define arguments_BDK_OCLAX_SFT_RST(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_SFT_RST(...) "OCLAX_SFT_RST"


/**
 * RSL - ocla#_stack_base
 */
typedef union bdk_oclax_stack_base {
	uint64_t u;
	struct bdk_oclax_stack_base_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t ptr                         : 42; /**< R/W - Memory address for base of overflow stack. This address must be on the local node in a
                                                                 CCPI system.
                                                                 This may be a virtual or physical address; see [PA]. */
		uint64_t reserved_2_6                : 5;
		uint64_t sec                         : 1;  /**< SR/W - If set, and physical addressing is used as described under [PA], the physical address
                                                                 is in the secure world. */
		uint64_t pa                          : 1;  /**< R/W - When set, [PTR] and all DMA addresses are physical addresses and will not be translated by
                                                                 the SMMU.  When clear, is a virtual address which is subject to SMMU translation.

                                                                 Only used for OCLA(4) in the coprocessor-clock domain; for OCLA(0..3) in the core-clock
                                                                 domains this bit is ignored, addresses are always physical. */
#else
		uint64_t pa                          : 1;
		uint64_t sec                         : 1;
		uint64_t reserved_2_6                : 5;
		uint64_t ptr                         : 42;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_oclax_stack_base_s      cn85xx; */
	/* struct bdk_oclax_stack_base_s      cn88xx; */
	/* struct bdk_oclax_stack_base_s      cn88xxp1; */
} bdk_oclax_stack_base_t;

static inline uint64_t BDK_OCLAX_STACK_BASE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_STACK_BASE(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000400ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_STACK_BASE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_STACK_BASE(...) bdk_oclax_stack_base_t
#define bustype_BDK_OCLAX_STACK_BASE(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_STACK_BASE(p1) (p1)
#define arguments_BDK_OCLAX_STACK_BASE(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_STACK_BASE(...) "OCLAX_STACK_BASE"


/**
 * RSL - ocla#_stack_cur
 */
typedef union bdk_oclax_stack_cur {
	uint64_t u;
	struct bdk_oclax_stack_cur_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t ptr                         : 42; /**< R/W/H - Next address to write for overflow stack. This address must be on the local node in a
                                                                 CCPI system. During initialization this must be between OCLA()_STACK_BASE and
                                                                 OCLA()_STACK_TOP.
                                                                 This may be a virtual or physical address; see OCLA()_STACK_BASE[PA]. */
		uint64_t reserved_0_6                : 7;
#else
		uint64_t reserved_0_6                : 7;
		uint64_t ptr                         : 42;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_oclax_stack_cur_s       cn85xx; */
	/* struct bdk_oclax_stack_cur_s       cn88xx; */
	/* struct bdk_oclax_stack_cur_s       cn88xxp1; */
} bdk_oclax_stack_cur_t;

static inline uint64_t BDK_OCLAX_STACK_CUR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_STACK_CUR(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000480ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_STACK_CUR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_STACK_CUR(...) bdk_oclax_stack_cur_t
#define bustype_BDK_OCLAX_STACK_CUR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_STACK_CUR(p1) (p1)
#define arguments_BDK_OCLAX_STACK_CUR(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_STACK_CUR(...) "OCLAX_STACK_CUR"


/**
 * RSL - ocla#_stack_store_cnt
 */
typedef union bdk_oclax_stack_store_cnt {
	uint64_t u;
	struct bdk_oclax_stack_store_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t stores                      : 32; /**< R/W/H - Number of cache line stores sent to memory subsystem. Not cleared by hardware. */
#else
		uint64_t stores                      : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_oclax_stack_store_cnt_s cn85xx; */
	/* struct bdk_oclax_stack_store_cnt_s cn88xx; */
	/* struct bdk_oclax_stack_store_cnt_s cn88xxp1; */
} bdk_oclax_stack_store_cnt_t;

static inline uint64_t BDK_OCLAX_STACK_STORE_CNT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_STACK_STORE_CNT(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000460ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_STACK_STORE_CNT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_STACK_STORE_CNT(...) bdk_oclax_stack_store_cnt_t
#define bustype_BDK_OCLAX_STACK_STORE_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_STACK_STORE_CNT(p1) (p1)
#define arguments_BDK_OCLAX_STACK_STORE_CNT(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_STACK_STORE_CNT(...) "OCLAX_STACK_STORE_CNT"


/**
 * RSL - ocla#_stack_top
 */
typedef union bdk_oclax_stack_top {
	uint64_t u;
	struct bdk_oclax_stack_top_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t ptr                         : 42; /**< R/W - Memory address for top of overflow stack plus one. This address must be on the local node
                                                                 in a CCPI system.
                                                                 This may be a virtual or physical address; see OCLA()_STACK_BASE[PA]. */
		uint64_t reserved_0_6                : 7;
#else
		uint64_t reserved_0_6                : 7;
		uint64_t ptr                         : 42;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_oclax_stack_top_s       cn85xx; */
	/* struct bdk_oclax_stack_top_s       cn88xx; */
	/* struct bdk_oclax_stack_top_s       cn88xxp1; */
} bdk_oclax_stack_top_t;

static inline uint64_t BDK_OCLAX_STACK_TOP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_STACK_TOP(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000420ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_STACK_TOP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_STACK_TOP(...) bdk_oclax_stack_top_t
#define bustype_BDK_OCLAX_STACK_TOP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_STACK_TOP(p1) (p1)
#define arguments_BDK_OCLAX_STACK_TOP(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_STACK_TOP(...) "OCLAX_STACK_TOP"


/**
 * RSL - ocla#_stack_wrap
 */
typedef union bdk_oclax_stack_wrap {
	uint64_t u;
	struct bdk_oclax_stack_wrap_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t wraps                       : 32; /**< R/W/H - Number of times stack has been reset to OCLA()_STACK_BASE since trigger. Cleared when
                                                                 OCLA()_STATE_INT[TRIG] clear. */
#else
		uint64_t wraps                       : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_oclax_stack_wrap_s      cn85xx; */
	/* struct bdk_oclax_stack_wrap_s      cn88xx; */
	/* struct bdk_oclax_stack_wrap_s      cn88xxp1; */
} bdk_oclax_stack_wrap_t;

static inline uint64_t BDK_OCLAX_STACK_WRAP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_STACK_WRAP(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000440ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_STACK_WRAP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_STACK_WRAP(...) bdk_oclax_stack_wrap_t
#define bustype_BDK_OCLAX_STACK_WRAP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_STACK_WRAP(p1) (p1)
#define arguments_BDK_OCLAX_STACK_WRAP(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_STACK_WRAP(...) "OCLAX_STACK_WRAP"


/**
 * RSL - ocla#_stage#
 */
typedef union bdk_oclax_stagex {
	uint64_t u;
	struct bdk_oclax_stagex_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t dly                         : 3;  /**< R/W - Cycles of delay staging to apply to corresponding input bit. */
#else
		uint64_t dly                         : 3;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_oclax_stagex_s          cn85xx; */
	/* struct bdk_oclax_stagex_s          cn88xx; */
	/* struct bdk_oclax_stagex_s          cn88xxp1; */
} bdk_oclax_stagex_t;

static inline uint64_t BDK_OCLAX_STAGEX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_STAGEX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 4)) && ((param2 <= 71)))
		return 0x000087E0A8100000ull + (param1 & 7) * 0x1000000ull + (param2 & 127) * 0x8ull;
	csr_fatal("BDK_OCLAX_STAGEX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_STAGEX(...) bdk_oclax_stagex_t
#define bustype_BDK_OCLAX_STAGEX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_STAGEX(p1,p2) (p1)
#define arguments_BDK_OCLAX_STAGEX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCLAX_STAGEX(...) "OCLAX_STAGEX"


/**
 * RSL - ocla#_state_ena_w1c
 *
 * This register clears interrupt enable bits.
 *
 */
typedef union bdk_oclax_state_ena_w1c {
	uint64_t u;
	struct bdk_oclax_state_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_19_63              : 45;
		uint64_t ddrfull                     : 1;  /**< R/W1C/H - Reads or clears OCLA()_STATE_ENA_W1S[DDRFULL]. */
		uint64_t wmark                       : 1;  /**< R/W1C/H - Reads or clears OCLA()_STATE_ENA_W1S[WMARK]. */
		uint64_t overfull                    : 1;  /**< R/W1C/H - Reads or clears OCLA()_STATE_ENA_W1S[OVERFULL]. */
		uint64_t trigfull                    : 1;  /**< R/W1C/H - Reads or clears OCLA()_STATE_ENA_W1S[TRIGFULL]. */
		uint64_t captured                    : 1;  /**< R/W1C/H - Reads or clears OCLA()_STATE_ENA_W1S[CAPTURED]. */
		uint64_t fsm1_int                    : 1;  /**< R/W1C/H - Reads or clears OCLA()_STATE_ENA_W1S[FSM1_INT]. */
		uint64_t fsm0_int                    : 1;  /**< R/W1C/H - Reads or clears OCLA()_STATE_ENA_W1S[FSM0_INT]. */
		uint64_t mcd                         : 3;  /**< R/W1C/H - Reads or clears OCLA()_STATE_ENA_W1S[MCD]. */
		uint64_t trig                        : 1;  /**< R/W1C/H - Reads or clears OCLA()_STATE_ENA_W1S[TRIG]. */
		uint64_t reserved_4_7                : 4;
		uint64_t ovfl                        : 4;  /**< R/W1C/H - Reads or clears OCLA()_STATE_ENA_W1S[OVFL]. */
#else
		uint64_t ovfl                        : 4;
		uint64_t reserved_4_7                : 4;
		uint64_t trig                        : 1;
		uint64_t mcd                         : 3;
		uint64_t fsm0_int                    : 1;
		uint64_t fsm1_int                    : 1;
		uint64_t captured                    : 1;
		uint64_t trigfull                    : 1;
		uint64_t overfull                    : 1;
		uint64_t wmark                       : 1;
		uint64_t ddrfull                     : 1;
		uint64_t reserved_19_63              : 45;
#endif
	} s;
	/* struct bdk_oclax_state_ena_w1c_s   cn85xx; */
	/* struct bdk_oclax_state_ena_w1c_s   cn88xx; */
	/* struct bdk_oclax_state_ena_w1c_s   cn88xxp1; */
} bdk_oclax_state_ena_w1c_t;

static inline uint64_t BDK_OCLAX_STATE_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_STATE_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A80000B8ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_STATE_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_STATE_ENA_W1C(...) bdk_oclax_state_ena_w1c_t
#define bustype_BDK_OCLAX_STATE_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_STATE_ENA_W1C(p1) (p1)
#define arguments_BDK_OCLAX_STATE_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_STATE_ENA_W1C(...) "OCLAX_STATE_ENA_W1C"


/**
 * RSL - ocla#_state_ena_w1s
 *
 * This register sets interrupt enable bits.
 *
 */
typedef union bdk_oclax_state_ena_w1s {
	uint64_t u;
	struct bdk_oclax_state_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_19_63              : 45;
		uint64_t ddrfull                     : 1;  /**< R/W1S/H - Enables reporting of OCLA()_STATE_INT[DDRFULL]. */
		uint64_t wmark                       : 1;  /**< R/W1S/H - Enables reporting of OCLA()_STATE_INT[WMARK]. */
		uint64_t overfull                    : 1;  /**< R/W1S/H - Enables reporting of OCLA()_STATE_INT[OVERFULL]. */
		uint64_t trigfull                    : 1;  /**< R/W1S/H - Enables reporting of OCLA()_STATE_INT[TRIGFULL]. */
		uint64_t captured                    : 1;  /**< R/W1S/H - Enables reporting of OCLA()_STATE_INT[CAPTURED]. */
		uint64_t fsm1_int                    : 1;  /**< R/W1S/H - Enables reporting of OCLA()_STATE_INT[FSM1_INT]. */
		uint64_t fsm0_int                    : 1;  /**< R/W1S/H - Enables reporting of OCLA()_STATE_INT[FSM0_INT]. */
		uint64_t mcd                         : 3;  /**< R/W1S/H - Enables reporting of OCLA()_STATE_INT[MCD]. */
		uint64_t trig                        : 1;  /**< R/W1S/H - Enables reporting of OCLA()_STATE_INT[TRIG]. */
		uint64_t reserved_4_7                : 4;
		uint64_t ovfl                        : 4;  /**< R/W1S/H - Enables reporting of OCLA()_STATE_INT[OVFL]. */
#else
		uint64_t ovfl                        : 4;
		uint64_t reserved_4_7                : 4;
		uint64_t trig                        : 1;
		uint64_t mcd                         : 3;
		uint64_t fsm0_int                    : 1;
		uint64_t fsm1_int                    : 1;
		uint64_t captured                    : 1;
		uint64_t trigfull                    : 1;
		uint64_t overfull                    : 1;
		uint64_t wmark                       : 1;
		uint64_t ddrfull                     : 1;
		uint64_t reserved_19_63              : 45;
#endif
	} s;
	/* struct bdk_oclax_state_ena_w1s_s   cn85xx; */
	/* struct bdk_oclax_state_ena_w1s_s   cn88xx; */
	/* struct bdk_oclax_state_ena_w1s_s   cn88xxp1; */
} bdk_oclax_state_ena_w1s_t;

static inline uint64_t BDK_OCLAX_STATE_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_STATE_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A80000B0ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_STATE_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_STATE_ENA_W1S(...) bdk_oclax_state_ena_w1s_t
#define bustype_BDK_OCLAX_STATE_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_STATE_ENA_W1S(p1) (p1)
#define arguments_BDK_OCLAX_STATE_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_STATE_ENA_W1S(...) "OCLAX_STATE_ENA_W1S"


/**
 * RSL - ocla#_state_int
 */
typedef union bdk_oclax_state_int {
	uint64_t u;
	struct bdk_oclax_state_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t fsm1_state                  : 4;  /**< RO/H - FSM1 current state. */
		uint64_t fsm0_state                  : 4;  /**< RO/H - FSM0 current state. */
		uint64_t reserved_36_55              : 20;
		uint64_t fsm1_rst                    : 1;  /**< R/W1C - FSM1 hold in state zero. Writing one to OCLA()_STATE_SET[FSM1_RST] sets this bit and
                                                                 holds FSM1 in state zero, writing one to OCLA()_STATE_INT[FSM1_RST] removes the hold. */
		uint64_t fsm0_rst                    : 1;  /**< R/W1C - FSM0 hold in state zero. Writing one to OCLA()_STATE_SET[FSM0_RST] sets this bit and
                                                                 holds FSM0 in state zero, writing one to OCLA()_STATE_INT[FSM0_RST] removes the hold. */
		uint64_t fsm1_ena                    : 1;  /**< R/W1C/H - FSM1 sequencing enabled. */
		uint64_t fsm0_ena                    : 1;  /**< R/W1C/H - FSM0 sequencing enabled. */
		uint64_t reserved_19_31              : 13;
		uint64_t ddrfull                     : 1;  /**< R/W1C/H - DDR buffer wrapped. Asserted when OCLA()_STACK_CUR has wrapped and been re-initialized
                                                                 to OCLA()_STACK_BASE. */
		uint64_t wmark                       : 1;  /**< R/W1C/H - Internal buffer watermark reached. Asserted when OCLA()_FIFO_DEPTH \>
                                                                 OCLA()_FIFO_LIMIT[WMARK]. */
		uint64_t overfull                    : 1;  /**< R/W1C/H - Capture ended due to FIFO overflow. Asserted when OCLA()_FIFO_DEPTH \>
                                                                 OCLA()_FIFO_LIMIT[OVERFULL]. */
		uint64_t trigfull                    : 1;  /**< R/W1C/H - Capture ended due to buffer full. Asserted when OCLA()_FIFO_TRIG[LIMIT] \>=
                                                                 OCLA()_FIFO_TRIG[CNT]. */
		uint64_t captured                    : 1;  /**< R/W1C/H - Capture started. Asserted when the first capture is made. Informational only; often masked. */
		uint64_t fsm1_int                    : 1;  /**< R/W1C/H - FSM1 interrupt requested. */
		uint64_t fsm0_int                    : 1;  /**< R/W1C/H - FSM0 interrupt requested. */
		uint64_t mcd                         : 3;  /**< R/W1C/H - Multichip debug (MCD0..2) set. Asserted on MCD received from another coprocessor or code,
                                                                 or FSM MCD request or W1S to OCLA()_STATE_SET[MCD]. */
		uint64_t trig                        : 1;  /**< R/W1C/H - Internal trigger set. Asserted on FSM internal trigger request or W1S to OCLA()_STATE_SET[TRIG]. */
		uint64_t reserved_4_7                : 4;
		uint64_t ovfl                        : 4;  /**< R/W1C/H - Match counter has overflowed. Asserted when OCLA()_MAT()_COUNT \>=
                                                                 OCLA()_MAT()_THRESH. Informational only; often masked. Writing 1 clears the
                                                                 counter, not just the interrupt. */
#else
		uint64_t ovfl                        : 4;
		uint64_t reserved_4_7                : 4;
		uint64_t trig                        : 1;
		uint64_t mcd                         : 3;
		uint64_t fsm0_int                    : 1;
		uint64_t fsm1_int                    : 1;
		uint64_t captured                    : 1;
		uint64_t trigfull                    : 1;
		uint64_t overfull                    : 1;
		uint64_t wmark                       : 1;
		uint64_t ddrfull                     : 1;
		uint64_t reserved_19_31              : 13;
		uint64_t fsm0_ena                    : 1;
		uint64_t fsm1_ena                    : 1;
		uint64_t fsm0_rst                    : 1;
		uint64_t fsm1_rst                    : 1;
		uint64_t reserved_36_55              : 20;
		uint64_t fsm0_state                  : 4;
		uint64_t fsm1_state                  : 4;
#endif
	} s;
	/* struct bdk_oclax_state_int_s       cn85xx; */
	/* struct bdk_oclax_state_int_s       cn88xx; */
	/* struct bdk_oclax_state_int_s       cn88xxp1; */
} bdk_oclax_state_int_t;

static inline uint64_t BDK_OCLAX_STATE_INT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_STATE_INT(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A8000080ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_STATE_INT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_STATE_INT(...) bdk_oclax_state_int_t
#define bustype_BDK_OCLAX_STATE_INT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_STATE_INT(p1) (p1)
#define arguments_BDK_OCLAX_STATE_INT(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_STATE_INT(...) "OCLAX_STATE_INT"


/**
 * RSL - ocla#_state_set
 *
 * This register reads identically to OCLA()_STATE_INT, but allows R/W1S instead of R/W1C access.
 *
 */
typedef union bdk_oclax_state_set {
	uint64_t u;
	struct bdk_oclax_state_set_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t fsm1_state                  : 4;  /**< RO/H - See OCLA()_STATE_INT[FSM1_STATE]. */
		uint64_t fsm0_state                  : 4;  /**< RO/H - See OCLA()_STATE_INT[FSM0_STATE]. */
		uint64_t reserved_36_55              : 20;
		uint64_t fsm1_rst                    : 1;  /**< R/W1S - See OCLA()_STATE_INT[FSM1_RST]. */
		uint64_t fsm0_rst                    : 1;  /**< R/W1S - See OCLA()_STATE_INT[FSM0_RST]. */
		uint64_t fsm1_ena                    : 1;  /**< R/W1S/H - See OCLA()_STATE_INT[FSM1_ENA]. */
		uint64_t fsm0_ena                    : 1;  /**< R/W1S/H - See OCLA()_STATE_INT[FSM0_ENA]. */
		uint64_t reserved_19_31              : 13;
		uint64_t ddrfull                     : 1;  /**< R/W1S/H - See OCLA()_STATE_INT[DDRFULL]. */
		uint64_t wmark                       : 1;  /**< R/W1S/H - See OCLA()_STATE_INT[WMARK]. */
		uint64_t overfull                    : 1;  /**< R/W1S/H - See OCLA()_STATE_INT[OVERFULL]. */
		uint64_t trigfull                    : 1;  /**< R/W1S/H - See OCLA()_STATE_INT[TRIGFULL]. */
		uint64_t captured                    : 1;  /**< R/W1S/H - See OCLA()_STATE_INT[CAPTURED]. */
		uint64_t fsm1_int                    : 1;  /**< R/W1S/H - See OCLA()_STATE_INT[FSM1_INT]. */
		uint64_t fsm0_int                    : 1;  /**< R/W1S/H - See OCLA()_STATE_INT[FSM0_INT]. */
		uint64_t mcd                         : 3;  /**< R/W1S/H - See OCLA()_STATE_INT[MCD]. */
		uint64_t trig                        : 1;  /**< R/W1S/H - See OCLA()_STATE_INT[TRIG]. */
		uint64_t reserved_4_7                : 4;
		uint64_t ovfl                        : 4;  /**< R/W1S/H - See OCLA()_STATE_INT[OVFL]. */
#else
		uint64_t ovfl                        : 4;
		uint64_t reserved_4_7                : 4;
		uint64_t trig                        : 1;
		uint64_t mcd                         : 3;
		uint64_t fsm0_int                    : 1;
		uint64_t fsm1_int                    : 1;
		uint64_t captured                    : 1;
		uint64_t trigfull                    : 1;
		uint64_t overfull                    : 1;
		uint64_t wmark                       : 1;
		uint64_t ddrfull                     : 1;
		uint64_t reserved_19_31              : 13;
		uint64_t fsm0_ena                    : 1;
		uint64_t fsm1_ena                    : 1;
		uint64_t fsm0_rst                    : 1;
		uint64_t fsm1_rst                    : 1;
		uint64_t reserved_36_55              : 20;
		uint64_t fsm0_state                  : 4;
		uint64_t fsm1_state                  : 4;
#endif
	} s;
	/* struct bdk_oclax_state_set_s       cn85xx; */
	/* struct bdk_oclax_state_set_s       cn88xx; */
	/* struct bdk_oclax_state_set_s       cn88xxp1; */
} bdk_oclax_state_set_t;

static inline uint64_t BDK_OCLAX_STATE_SET(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_STATE_SET(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A80000A0ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_STATE_SET", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_STATE_SET(...) bdk_oclax_state_set_t
#define bustype_BDK_OCLAX_STATE_SET(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_STATE_SET(p1) (p1)
#define arguments_BDK_OCLAX_STATE_SET(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_STATE_SET(...) "OCLAX_STATE_SET"


/**
 * RSL - ocla#_time
 */
typedef union bdk_oclax_time {
	uint64_t u;
	struct bdk_oclax_time_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t cycle                       : 32; /**< R/W/H - Current time as free running counter. Loaded into captured control packets.
                                                                 Unconditionally clocked, independent of OCLA()_SFT_RST. */
#else
		uint64_t cycle                       : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_oclax_time_s            cn85xx; */
	/* struct bdk_oclax_time_s            cn88xx; */
	/* struct bdk_oclax_time_s            cn88xxp1; */
} bdk_oclax_time_t;

static inline uint64_t BDK_OCLAX_TIME(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCLAX_TIME(unsigned long param1)
{
	if (((param1 <= 4)))
		return 0x000087E0A80000C0ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_OCLAX_TIME", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCLAX_TIME(...) bdk_oclax_time_t
#define bustype_BDK_OCLAX_TIME(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCLAX_TIME(p1) (p1)
#define arguments_BDK_OCLAX_TIME(p1) (p1),-1,-1,-1
#define basename_BDK_OCLAX_TIME(...) "OCLAX_TIME"

#endif /* __BDK_CSRS_OCLA__ */
