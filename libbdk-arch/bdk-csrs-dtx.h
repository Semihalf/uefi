#ifndef __BDK_CSRS_DTX__
#define __BDK_CSRS_DTX__
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
 * Cavium DTX.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * RSL - dtx_bgx#_bcst_rsp
 */
typedef union bdk_dtx_bgxx_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_bgxx_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_bgxx_bcst_rsp_s     cn85xx; */
	/* struct bdk_dtx_bgxx_bcst_rsp_s     cn88xx; */
} bdk_dtx_bgxx_bcst_rsp_t;

static inline uint64_t BDK_DTX_BGXX_BCST_RSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BGXX_BCST_RSP(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE700080ull + (param1 & 1) * 0x8000ull;
	csr_fatal("BDK_DTX_BGXX_BCST_RSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_BGXX_BCST_RSP(...) bdk_dtx_bgxx_bcst_rsp_t
#define bustype_BDK_DTX_BGXX_BCST_RSP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_BGXX_BCST_RSP(p1) (p1)
#define arguments_BDK_DTX_BGXX_BCST_RSP(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_BGXX_BCST_RSP(...) "DTX_BGXX_BCST_RSP"


/**
 * RSL - dtx_bgx#_ctl
 */
typedef union bdk_dtx_bgxx_ctl {
	uint64_t u;
	struct bdk_dtx_bgxx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_bgxx_ctl_s          cn85xx; */
	/* struct bdk_dtx_bgxx_ctl_s          cn88xx; */
} bdk_dtx_bgxx_ctl_t;

static inline uint64_t BDK_DTX_BGXX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BGXX_CTL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE700060ull + (param1 & 1) * 0x8000ull;
	csr_fatal("BDK_DTX_BGXX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_BGXX_CTL(...) bdk_dtx_bgxx_ctl_t
#define bustype_BDK_DTX_BGXX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_BGXX_CTL(p1) (p1)
#define arguments_BDK_DTX_BGXX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_BGXX_CTL(...) "DTX_BGXX_CTL"


/**
 * RSL - dtx_bgx#_dat#
 */
typedef union bdk_dtx_bgxx_datx {
	uint64_t u;
	struct bdk_dtx_bgxx_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_bgxx_datx_s         cn85xx; */
	/* struct bdk_dtx_bgxx_datx_s         cn88xx; */
} bdk_dtx_bgxx_datx_t;

static inline uint64_t BDK_DTX_BGXX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BGXX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FE700040ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_BGXX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_BGXX_DATX(...) bdk_dtx_bgxx_datx_t
#define bustype_BDK_DTX_BGXX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_BGXX_DATX(p1,p2) (p1)
#define arguments_BDK_DTX_BGXX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_BGXX_DATX(...) "DTX_BGXX_DATX"


/**
 * RSL - dtx_bgx#_ena#
 */
typedef union bdk_dtx_bgxx_enax {
	uint64_t u;
	struct bdk_dtx_bgxx_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_bgxx_enax_s         cn85xx; */
	/* struct bdk_dtx_bgxx_enax_s         cn88xx; */
} bdk_dtx_bgxx_enax_t;

static inline uint64_t BDK_DTX_BGXX_ENAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BGXX_ENAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FE700020ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_BGXX_ENAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_BGXX_ENAX(...) bdk_dtx_bgxx_enax_t
#define bustype_BDK_DTX_BGXX_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_BGXX_ENAX(p1,p2) (p1)
#define arguments_BDK_DTX_BGXX_ENAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_BGXX_ENAX(...) "DTX_BGXX_ENAX"


/**
 * RSL - dtx_bgx#_sel#
 */
typedef union bdk_dtx_bgxx_selx {
	uint64_t u;
	struct bdk_dtx_bgxx_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_bgxx_selx_s         cn85xx; */
	/* struct bdk_dtx_bgxx_selx_s         cn88xx; */
} bdk_dtx_bgxx_selx_t;

static inline uint64_t BDK_DTX_BGXX_SELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BGXX_SELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FE700000ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_BGXX_SELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_BGXX_SELX(...) bdk_dtx_bgxx_selx_t
#define bustype_BDK_DTX_BGXX_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_BGXX_SELX(p1,p2) (p1)
#define arguments_BDK_DTX_BGXX_SELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_BGXX_SELX(...) "DTX_BGXX_SELX"


/**
 * RSL - dtx_broadcast_ctl
 */
typedef union bdk_dtx_broadcast_ctl {
	uint64_t u;
	struct bdk_dtx_broadcast_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_broadcast_ctl_s     cn85xx; */
	/* struct bdk_dtx_broadcast_ctl_s     cn88xx; */
} bdk_dtx_broadcast_ctl_t;

#define BDK_DTX_BROADCAST_CTL BDK_DTX_BROADCAST_CTL_FUNC()
static inline uint64_t BDK_DTX_BROADCAST_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BROADCAST_CTL_FUNC(void)
{
	return 0x000087E0FE7F0060ull;
}
#define typedef_BDK_DTX_BROADCAST_CTL bdk_dtx_broadcast_ctl_t
#define bustype_BDK_DTX_BROADCAST_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_BROADCAST_CTL 0
#define arguments_BDK_DTX_BROADCAST_CTL -1,-1,-1,-1
#define basename_BDK_DTX_BROADCAST_CTL "DTX_BROADCAST_CTL"


/**
 * RSL - dtx_broadcast_ena#
 */
typedef union bdk_dtx_broadcast_enax {
	uint64_t u;
	struct bdk_dtx_broadcast_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_broadcast_enax_s    cn85xx; */
	/* struct bdk_dtx_broadcast_enax_s    cn88xx; */
} bdk_dtx_broadcast_enax_t;

static inline uint64_t BDK_DTX_BROADCAST_ENAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BROADCAST_ENAX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE7F0020ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_BROADCAST_ENAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_BROADCAST_ENAX(...) bdk_dtx_broadcast_enax_t
#define bustype_BDK_DTX_BROADCAST_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_BROADCAST_ENAX(p1) (p1)
#define arguments_BDK_DTX_BROADCAST_ENAX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_BROADCAST_ENAX(...) "DTX_BROADCAST_ENAX"


/**
 * RSL - dtx_broadcast_sel#
 */
typedef union bdk_dtx_broadcast_selx {
	uint64_t u;
	struct bdk_dtx_broadcast_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_broadcast_selx_s    cn85xx; */
	/* struct bdk_dtx_broadcast_selx_s    cn88xx; */
} bdk_dtx_broadcast_selx_t;

static inline uint64_t BDK_DTX_BROADCAST_SELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BROADCAST_SELX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE7F0000ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_BROADCAST_SELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_BROADCAST_SELX(...) bdk_dtx_broadcast_selx_t
#define bustype_BDK_DTX_BROADCAST_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_BROADCAST_SELX(p1) (p1)
#define arguments_BDK_DTX_BROADCAST_SELX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_BROADCAST_SELX(...) "DTX_BROADCAST_SELX"


/**
 * RSL - dtx_dap_bcst_rsp
 */
typedef union bdk_dtx_dap_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_dap_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_dap_bcst_rsp_s      cn85xx; */
	/* struct bdk_dtx_dap_bcst_rsp_s      cn88xx; */
} bdk_dtx_dap_bcst_rsp_t;

#define BDK_DTX_DAP_BCST_RSP BDK_DTX_DAP_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_DAP_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DAP_BCST_RSP_FUNC(void)
{
	return 0x000087E0FE010080ull;
}
#define typedef_BDK_DTX_DAP_BCST_RSP bdk_dtx_dap_bcst_rsp_t
#define bustype_BDK_DTX_DAP_BCST_RSP BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_DAP_BCST_RSP 0
#define arguments_BDK_DTX_DAP_BCST_RSP -1,-1,-1,-1
#define basename_BDK_DTX_DAP_BCST_RSP "DTX_DAP_BCST_RSP"


/**
 * RSL - dtx_dap_ctl
 */
typedef union bdk_dtx_dap_ctl {
	uint64_t u;
	struct bdk_dtx_dap_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_dap_ctl_s           cn85xx; */
	/* struct bdk_dtx_dap_ctl_s           cn88xx; */
} bdk_dtx_dap_ctl_t;

#define BDK_DTX_DAP_CTL BDK_DTX_DAP_CTL_FUNC()
static inline uint64_t BDK_DTX_DAP_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DAP_CTL_FUNC(void)
{
	return 0x000087E0FE010060ull;
}
#define typedef_BDK_DTX_DAP_CTL bdk_dtx_dap_ctl_t
#define bustype_BDK_DTX_DAP_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_DAP_CTL 0
#define arguments_BDK_DTX_DAP_CTL -1,-1,-1,-1
#define basename_BDK_DTX_DAP_CTL "DTX_DAP_CTL"


/**
 * RSL - dtx_dap_dat#
 */
typedef union bdk_dtx_dap_datx {
	uint64_t u;
	struct bdk_dtx_dap_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_dap_datx_s          cn85xx; */
	/* struct bdk_dtx_dap_datx_s          cn88xx; */
} bdk_dtx_dap_datx_t;

static inline uint64_t BDK_DTX_DAP_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DAP_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE010040ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_DAP_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_DAP_DATX(...) bdk_dtx_dap_datx_t
#define bustype_BDK_DTX_DAP_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_DAP_DATX(p1) (p1)
#define arguments_BDK_DTX_DAP_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_DAP_DATX(...) "DTX_DAP_DATX"


/**
 * RSL - dtx_dap_ena#
 */
typedef union bdk_dtx_dap_enax {
	uint64_t u;
	struct bdk_dtx_dap_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_dap_enax_s          cn85xx; */
	/* struct bdk_dtx_dap_enax_s          cn88xx; */
} bdk_dtx_dap_enax_t;

static inline uint64_t BDK_DTX_DAP_ENAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DAP_ENAX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE010020ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_DAP_ENAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_DAP_ENAX(...) bdk_dtx_dap_enax_t
#define bustype_BDK_DTX_DAP_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_DAP_ENAX(p1) (p1)
#define arguments_BDK_DTX_DAP_ENAX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_DAP_ENAX(...) "DTX_DAP_ENAX"


/**
 * RSL - dtx_dap_sel#
 */
typedef union bdk_dtx_dap_selx {
	uint64_t u;
	struct bdk_dtx_dap_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_dap_selx_s          cn85xx; */
	/* struct bdk_dtx_dap_selx_s          cn88xx; */
} bdk_dtx_dap_selx_t;

static inline uint64_t BDK_DTX_DAP_SELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DAP_SELX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE010000ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_DAP_SELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_DAP_SELX(...) bdk_dtx_dap_selx_t
#define bustype_BDK_DTX_DAP_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_DAP_SELX(p1) (p1)
#define arguments_BDK_DTX_DAP_SELX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_DAP_SELX(...) "DTX_DAP_SELX"


/**
 * RSL - dtx_dfa_bcst_rsp
 */
typedef union bdk_dtx_dfa_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_dfa_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_dfa_bcst_rsp_s      cn85xx; */
	/* struct bdk_dtx_dfa_bcst_rsp_s      cn88xx; */
} bdk_dtx_dfa_bcst_rsp_t;

#define BDK_DTX_DFA_BCST_RSP BDK_DTX_DFA_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_DFA_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DFA_BCST_RSP_FUNC(void)
{
	return 0x000087E0FEA30080ull;
}
#define typedef_BDK_DTX_DFA_BCST_RSP bdk_dtx_dfa_bcst_rsp_t
#define bustype_BDK_DTX_DFA_BCST_RSP BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_DFA_BCST_RSP 0
#define arguments_BDK_DTX_DFA_BCST_RSP -1,-1,-1,-1
#define basename_BDK_DTX_DFA_BCST_RSP "DTX_DFA_BCST_RSP"


/**
 * RSL - dtx_dfa_ctl
 */
typedef union bdk_dtx_dfa_ctl {
	uint64_t u;
	struct bdk_dtx_dfa_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_dfa_ctl_s           cn85xx; */
	/* struct bdk_dtx_dfa_ctl_s           cn88xx; */
} bdk_dtx_dfa_ctl_t;

#define BDK_DTX_DFA_CTL BDK_DTX_DFA_CTL_FUNC()
static inline uint64_t BDK_DTX_DFA_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DFA_CTL_FUNC(void)
{
	return 0x000087E0FEA30060ull;
}
#define typedef_BDK_DTX_DFA_CTL bdk_dtx_dfa_ctl_t
#define bustype_BDK_DTX_DFA_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_DFA_CTL 0
#define arguments_BDK_DTX_DFA_CTL -1,-1,-1,-1
#define basename_BDK_DTX_DFA_CTL "DTX_DFA_CTL"


/**
 * RSL - dtx_dfa_dat#
 */
typedef union bdk_dtx_dfa_datx {
	uint64_t u;
	struct bdk_dtx_dfa_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_dfa_datx_s          cn85xx; */
	/* struct bdk_dtx_dfa_datx_s          cn88xx; */
} bdk_dtx_dfa_datx_t;

static inline uint64_t BDK_DTX_DFA_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DFA_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FEA30040ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_DFA_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_DFA_DATX(...) bdk_dtx_dfa_datx_t
#define bustype_BDK_DTX_DFA_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_DFA_DATX(p1) (p1)
#define arguments_BDK_DTX_DFA_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_DFA_DATX(...) "DTX_DFA_DATX"


/**
 * RSL - dtx_dfa_ena#
 */
typedef union bdk_dtx_dfa_enax {
	uint64_t u;
	struct bdk_dtx_dfa_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_dfa_enax_s          cn85xx; */
	/* struct bdk_dtx_dfa_enax_s          cn88xx; */
} bdk_dtx_dfa_enax_t;

static inline uint64_t BDK_DTX_DFA_ENAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DFA_ENAX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FEA30020ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_DFA_ENAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_DFA_ENAX(...) bdk_dtx_dfa_enax_t
#define bustype_BDK_DTX_DFA_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_DFA_ENAX(p1) (p1)
#define arguments_BDK_DTX_DFA_ENAX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_DFA_ENAX(...) "DTX_DFA_ENAX"


/**
 * RSL - dtx_dfa_sel#
 */
typedef union bdk_dtx_dfa_selx {
	uint64_t u;
	struct bdk_dtx_dfa_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_dfa_selx_s          cn85xx; */
	/* struct bdk_dtx_dfa_selx_s          cn88xx; */
} bdk_dtx_dfa_selx_t;

static inline uint64_t BDK_DTX_DFA_SELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DFA_SELX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FEA30000ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_DFA_SELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_DFA_SELX(...) bdk_dtx_dfa_selx_t
#define bustype_BDK_DTX_DFA_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_DFA_SELX(p1) (p1)
#define arguments_BDK_DTX_DFA_SELX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_DFA_SELX(...) "DTX_DFA_SELX"


/**
 * RSL - dtx_gic_bcst_rsp
 */
typedef union bdk_dtx_gic_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_gic_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_gic_bcst_rsp_s      cn85xx; */
	/* struct bdk_dtx_gic_bcst_rsp_s      cn88xx; */
} bdk_dtx_gic_bcst_rsp_t;

#define BDK_DTX_GIC_BCST_RSP BDK_DTX_GIC_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_GIC_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GIC_BCST_RSP_FUNC(void)
{
	return 0x000087E0FE808080ull;
}
#define typedef_BDK_DTX_GIC_BCST_RSP bdk_dtx_gic_bcst_rsp_t
#define bustype_BDK_DTX_GIC_BCST_RSP BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_GIC_BCST_RSP 0
#define arguments_BDK_DTX_GIC_BCST_RSP -1,-1,-1,-1
#define basename_BDK_DTX_GIC_BCST_RSP "DTX_GIC_BCST_RSP"


/**
 * RSL - dtx_gic_ctl
 */
typedef union bdk_dtx_gic_ctl {
	uint64_t u;
	struct bdk_dtx_gic_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_gic_ctl_s           cn85xx; */
	/* struct bdk_dtx_gic_ctl_s           cn88xx; */
} bdk_dtx_gic_ctl_t;

#define BDK_DTX_GIC_CTL BDK_DTX_GIC_CTL_FUNC()
static inline uint64_t BDK_DTX_GIC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GIC_CTL_FUNC(void)
{
	return 0x000087E0FE808060ull;
}
#define typedef_BDK_DTX_GIC_CTL bdk_dtx_gic_ctl_t
#define bustype_BDK_DTX_GIC_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_GIC_CTL 0
#define arguments_BDK_DTX_GIC_CTL -1,-1,-1,-1
#define basename_BDK_DTX_GIC_CTL "DTX_GIC_CTL"


/**
 * RSL - dtx_gic_dat#
 */
typedef union bdk_dtx_gic_datx {
	uint64_t u;
	struct bdk_dtx_gic_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_gic_datx_s          cn85xx; */
	/* struct bdk_dtx_gic_datx_s          cn88xx; */
} bdk_dtx_gic_datx_t;

static inline uint64_t BDK_DTX_GIC_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GIC_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE808040ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_GIC_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_GIC_DATX(...) bdk_dtx_gic_datx_t
#define bustype_BDK_DTX_GIC_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_GIC_DATX(p1) (p1)
#define arguments_BDK_DTX_GIC_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_GIC_DATX(...) "DTX_GIC_DATX"


/**
 * RSL - dtx_gic_ena#
 */
typedef union bdk_dtx_gic_enax {
	uint64_t u;
	struct bdk_dtx_gic_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_gic_enax_s          cn85xx; */
	/* struct bdk_dtx_gic_enax_s          cn88xx; */
} bdk_dtx_gic_enax_t;

static inline uint64_t BDK_DTX_GIC_ENAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GIC_ENAX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE808020ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_GIC_ENAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_GIC_ENAX(...) bdk_dtx_gic_enax_t
#define bustype_BDK_DTX_GIC_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_GIC_ENAX(p1) (p1)
#define arguments_BDK_DTX_GIC_ENAX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_GIC_ENAX(...) "DTX_GIC_ENAX"


/**
 * RSL - dtx_gic_sel#
 */
typedef union bdk_dtx_gic_selx {
	uint64_t u;
	struct bdk_dtx_gic_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_gic_selx_s          cn85xx; */
	/* struct bdk_dtx_gic_selx_s          cn88xx; */
} bdk_dtx_gic_selx_t;

static inline uint64_t BDK_DTX_GIC_SELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GIC_SELX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE808000ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_GIC_SELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_GIC_SELX(...) bdk_dtx_gic_selx_t
#define bustype_BDK_DTX_GIC_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_GIC_SELX(p1) (p1)
#define arguments_BDK_DTX_GIC_SELX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_GIC_SELX(...) "DTX_GIC_SELX"


/**
 * RSL - dtx_gser#_bcst_rsp
 */
typedef union bdk_dtx_gserx_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_gserx_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_gserx_bcst_rsp_s    cn85xx; */
	/* struct bdk_dtx_gserx_bcst_rsp_s    cn88xx; */
} bdk_dtx_gserx_bcst_rsp_t;

static inline uint64_t BDK_DTX_GSERX_BCST_RSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GSERX_BCST_RSP(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E0FE480080ull + (param1 & 15) * 0x8000ull;
	csr_fatal("BDK_DTX_GSERX_BCST_RSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_GSERX_BCST_RSP(...) bdk_dtx_gserx_bcst_rsp_t
#define bustype_BDK_DTX_GSERX_BCST_RSP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_GSERX_BCST_RSP(p1) (p1)
#define arguments_BDK_DTX_GSERX_BCST_RSP(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_GSERX_BCST_RSP(...) "DTX_GSERX_BCST_RSP"


/**
 * RSL - dtx_gser#_ctl
 */
typedef union bdk_dtx_gserx_ctl {
	uint64_t u;
	struct bdk_dtx_gserx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_gserx_ctl_s         cn85xx; */
	/* struct bdk_dtx_gserx_ctl_s         cn88xx; */
} bdk_dtx_gserx_ctl_t;

static inline uint64_t BDK_DTX_GSERX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GSERX_CTL(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E0FE480060ull + (param1 & 15) * 0x8000ull;
	csr_fatal("BDK_DTX_GSERX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_GSERX_CTL(...) bdk_dtx_gserx_ctl_t
#define bustype_BDK_DTX_GSERX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_GSERX_CTL(p1) (p1)
#define arguments_BDK_DTX_GSERX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_GSERX_CTL(...) "DTX_GSERX_CTL"


/**
 * RSL - dtx_gser#_dat#
 */
typedef union bdk_dtx_gserx_datx {
	uint64_t u;
	struct bdk_dtx_gserx_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_gserx_datx_s        cn85xx; */
	/* struct bdk_dtx_gserx_datx_s        cn88xx; */
} bdk_dtx_gserx_datx_t;

static inline uint64_t BDK_DTX_GSERX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GSERX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 1)))
		return 0x000087E0FE480040ull + (param1 & 15) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_GSERX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_GSERX_DATX(...) bdk_dtx_gserx_datx_t
#define bustype_BDK_DTX_GSERX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_GSERX_DATX(p1,p2) (p1)
#define arguments_BDK_DTX_GSERX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_GSERX_DATX(...) "DTX_GSERX_DATX"


/**
 * RSL - dtx_gser#_ena#
 */
typedef union bdk_dtx_gserx_enax {
	uint64_t u;
	struct bdk_dtx_gserx_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_gserx_enax_s        cn85xx; */
	/* struct bdk_dtx_gserx_enax_s        cn88xx; */
} bdk_dtx_gserx_enax_t;

static inline uint64_t BDK_DTX_GSERX_ENAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GSERX_ENAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 1)))
		return 0x000087E0FE480020ull + (param1 & 15) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_GSERX_ENAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_GSERX_ENAX(...) bdk_dtx_gserx_enax_t
#define bustype_BDK_DTX_GSERX_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_GSERX_ENAX(p1,p2) (p1)
#define arguments_BDK_DTX_GSERX_ENAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_GSERX_ENAX(...) "DTX_GSERX_ENAX"


/**
 * RSL - dtx_gser#_sel#
 */
typedef union bdk_dtx_gserx_selx {
	uint64_t u;
	struct bdk_dtx_gserx_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_gserx_selx_s        cn85xx; */
	/* struct bdk_dtx_gserx_selx_s        cn88xx; */
} bdk_dtx_gserx_selx_t;

static inline uint64_t BDK_DTX_GSERX_SELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GSERX_SELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 1)))
		return 0x000087E0FE480000ull + (param1 & 15) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_GSERX_SELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_GSERX_SELX(...) bdk_dtx_gserx_selx_t
#define bustype_BDK_DTX_GSERX_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_GSERX_SELX(p1,p2) (p1)
#define arguments_BDK_DTX_GSERX_SELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_GSERX_SELX(...) "DTX_GSERX_SELX"


/**
 * RSL - dtx_iobn#_bcst_rsp
 */
typedef union bdk_dtx_iobnx_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_iobnx_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_iobnx_bcst_rsp_s    cn85xx; */
	/* struct bdk_dtx_iobnx_bcst_rsp_s    cn88xx; */
} bdk_dtx_iobnx_bcst_rsp_t;

static inline uint64_t BDK_DTX_IOBNX_BCST_RSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_IOBNX_BCST_RSP(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE780080ull + (param1 & 1) * 0x8000ull;
	csr_fatal("BDK_DTX_IOBNX_BCST_RSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_IOBNX_BCST_RSP(...) bdk_dtx_iobnx_bcst_rsp_t
#define bustype_BDK_DTX_IOBNX_BCST_RSP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_IOBNX_BCST_RSP(p1) (p1)
#define arguments_BDK_DTX_IOBNX_BCST_RSP(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_IOBNX_BCST_RSP(...) "DTX_IOBNX_BCST_RSP"


/**
 * RSL - dtx_iobn#_ctl
 */
typedef union bdk_dtx_iobnx_ctl {
	uint64_t u;
	struct bdk_dtx_iobnx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_iobnx_ctl_s         cn85xx; */
	/* struct bdk_dtx_iobnx_ctl_s         cn88xx; */
} bdk_dtx_iobnx_ctl_t;

static inline uint64_t BDK_DTX_IOBNX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_IOBNX_CTL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE780060ull + (param1 & 1) * 0x8000ull;
	csr_fatal("BDK_DTX_IOBNX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_IOBNX_CTL(...) bdk_dtx_iobnx_ctl_t
#define bustype_BDK_DTX_IOBNX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_IOBNX_CTL(p1) (p1)
#define arguments_BDK_DTX_IOBNX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_IOBNX_CTL(...) "DTX_IOBNX_CTL"


/**
 * RSL - dtx_iobn#_dat#
 */
typedef union bdk_dtx_iobnx_datx {
	uint64_t u;
	struct bdk_dtx_iobnx_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_iobnx_datx_s        cn85xx; */
	/* struct bdk_dtx_iobnx_datx_s        cn88xx; */
} bdk_dtx_iobnx_datx_t;

static inline uint64_t BDK_DTX_IOBNX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_IOBNX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FE780040ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_IOBNX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_IOBNX_DATX(...) bdk_dtx_iobnx_datx_t
#define bustype_BDK_DTX_IOBNX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_IOBNX_DATX(p1,p2) (p1)
#define arguments_BDK_DTX_IOBNX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_IOBNX_DATX(...) "DTX_IOBNX_DATX"


/**
 * RSL - dtx_iobn#_ena#
 */
typedef union bdk_dtx_iobnx_enax {
	uint64_t u;
	struct bdk_dtx_iobnx_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_iobnx_enax_s        cn85xx; */
	/* struct bdk_dtx_iobnx_enax_s        cn88xx; */
} bdk_dtx_iobnx_enax_t;

static inline uint64_t BDK_DTX_IOBNX_ENAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_IOBNX_ENAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FE780020ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_IOBNX_ENAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_IOBNX_ENAX(...) bdk_dtx_iobnx_enax_t
#define bustype_BDK_DTX_IOBNX_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_IOBNX_ENAX(p1,p2) (p1)
#define arguments_BDK_DTX_IOBNX_ENAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_IOBNX_ENAX(...) "DTX_IOBNX_ENAX"


/**
 * RSL - dtx_iobn#_sel#
 */
typedef union bdk_dtx_iobnx_selx {
	uint64_t u;
	struct bdk_dtx_iobnx_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_iobnx_selx_s        cn85xx; */
	/* struct bdk_dtx_iobnx_selx_s        cn88xx; */
} bdk_dtx_iobnx_selx_t;

static inline uint64_t BDK_DTX_IOBNX_SELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_IOBNX_SELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FE780000ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_IOBNX_SELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_IOBNX_SELX(...) bdk_dtx_iobnx_selx_t
#define bustype_BDK_DTX_IOBNX_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_IOBNX_SELX(p1,p2) (p1)
#define arguments_BDK_DTX_IOBNX_SELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_IOBNX_SELX(...) "DTX_IOBNX_SELX"


/**
 * RSL - dtx_l2c_cbc#_bcst_rsp
 */
typedef union bdk_dtx_l2c_cbcx_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_l2c_cbcx_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_l2c_cbcx_bcst_rsp_s cn85xx; */
	/* struct bdk_dtx_l2c_cbcx_bcst_rsp_s cn88xx; */
} bdk_dtx_l2c_cbcx_bcst_rsp_t;

static inline uint64_t BDK_DTX_L2C_CBCX_BCST_RSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_CBCX_BCST_RSP(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0FE2C0080ull + (param1 & 3) * 0x8000ull;
	csr_fatal("BDK_DTX_L2C_CBCX_BCST_RSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_CBCX_BCST_RSP(...) bdk_dtx_l2c_cbcx_bcst_rsp_t
#define bustype_BDK_DTX_L2C_CBCX_BCST_RSP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_CBCX_BCST_RSP(p1) (p1)
#define arguments_BDK_DTX_L2C_CBCX_BCST_RSP(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_L2C_CBCX_BCST_RSP(...) "DTX_L2C_CBCX_BCST_RSP"


/**
 * RSL - dtx_l2c_cbc#_ctl
 */
typedef union bdk_dtx_l2c_cbcx_ctl {
	uint64_t u;
	struct bdk_dtx_l2c_cbcx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_l2c_cbcx_ctl_s      cn85xx; */
	/* struct bdk_dtx_l2c_cbcx_ctl_s      cn88xx; */
} bdk_dtx_l2c_cbcx_ctl_t;

static inline uint64_t BDK_DTX_L2C_CBCX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_CBCX_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0FE2C0060ull + (param1 & 3) * 0x8000ull;
	csr_fatal("BDK_DTX_L2C_CBCX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_CBCX_CTL(...) bdk_dtx_l2c_cbcx_ctl_t
#define bustype_BDK_DTX_L2C_CBCX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_CBCX_CTL(p1) (p1)
#define arguments_BDK_DTX_L2C_CBCX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_L2C_CBCX_CTL(...) "DTX_L2C_CBCX_CTL"


/**
 * RSL - dtx_l2c_cbc#_dat#
 */
typedef union bdk_dtx_l2c_cbcx_datx {
	uint64_t u;
	struct bdk_dtx_l2c_cbcx_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_l2c_cbcx_datx_s     cn85xx; */
	/* struct bdk_dtx_l2c_cbcx_datx_s     cn88xx; */
} bdk_dtx_l2c_cbcx_datx_t;

static inline uint64_t BDK_DTX_L2C_CBCX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_CBCX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 1)))
		return 0x000087E0FE2C0040ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_L2C_CBCX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_CBCX_DATX(...) bdk_dtx_l2c_cbcx_datx_t
#define bustype_BDK_DTX_L2C_CBCX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_CBCX_DATX(p1,p2) (p1)
#define arguments_BDK_DTX_L2C_CBCX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_L2C_CBCX_DATX(...) "DTX_L2C_CBCX_DATX"


/**
 * RSL - dtx_l2c_cbc#_ena#
 */
typedef union bdk_dtx_l2c_cbcx_enax {
	uint64_t u;
	struct bdk_dtx_l2c_cbcx_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_l2c_cbcx_enax_s     cn85xx; */
	/* struct bdk_dtx_l2c_cbcx_enax_s     cn88xx; */
} bdk_dtx_l2c_cbcx_enax_t;

static inline uint64_t BDK_DTX_L2C_CBCX_ENAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_CBCX_ENAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 1)))
		return 0x000087E0FE2C0020ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_L2C_CBCX_ENAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_CBCX_ENAX(...) bdk_dtx_l2c_cbcx_enax_t
#define bustype_BDK_DTX_L2C_CBCX_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_CBCX_ENAX(p1,p2) (p1)
#define arguments_BDK_DTX_L2C_CBCX_ENAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_L2C_CBCX_ENAX(...) "DTX_L2C_CBCX_ENAX"


/**
 * RSL - dtx_l2c_cbc#_sel#
 */
typedef union bdk_dtx_l2c_cbcx_selx {
	uint64_t u;
	struct bdk_dtx_l2c_cbcx_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_l2c_cbcx_selx_s     cn85xx; */
	/* struct bdk_dtx_l2c_cbcx_selx_s     cn88xx; */
} bdk_dtx_l2c_cbcx_selx_t;

static inline uint64_t BDK_DTX_L2C_CBCX_SELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_CBCX_SELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 1)))
		return 0x000087E0FE2C0000ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_L2C_CBCX_SELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_CBCX_SELX(...) bdk_dtx_l2c_cbcx_selx_t
#define bustype_BDK_DTX_L2C_CBCX_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_CBCX_SELX(p1,p2) (p1)
#define arguments_BDK_DTX_L2C_CBCX_SELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_L2C_CBCX_SELX(...) "DTX_L2C_CBCX_SELX"


/**
 * RSL - dtx_l2c_mci#_bcst_rsp
 */
typedef union bdk_dtx_l2c_mcix_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_l2c_mcix_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_l2c_mcix_bcst_rsp_s cn85xx; */
	/* struct bdk_dtx_l2c_mcix_bcst_rsp_s cn88xx; */
} bdk_dtx_l2c_mcix_bcst_rsp_t;

static inline uint64_t BDK_DTX_L2C_MCIX_BCST_RSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_MCIX_BCST_RSP(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0FE2E0080ull + (param1 & 3) * 0x8000ull;
	csr_fatal("BDK_DTX_L2C_MCIX_BCST_RSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_MCIX_BCST_RSP(...) bdk_dtx_l2c_mcix_bcst_rsp_t
#define bustype_BDK_DTX_L2C_MCIX_BCST_RSP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_MCIX_BCST_RSP(p1) (p1)
#define arguments_BDK_DTX_L2C_MCIX_BCST_RSP(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_L2C_MCIX_BCST_RSP(...) "DTX_L2C_MCIX_BCST_RSP"


/**
 * RSL - dtx_l2c_mci#_ctl
 */
typedef union bdk_dtx_l2c_mcix_ctl {
	uint64_t u;
	struct bdk_dtx_l2c_mcix_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_l2c_mcix_ctl_s      cn85xx; */
	/* struct bdk_dtx_l2c_mcix_ctl_s      cn88xx; */
} bdk_dtx_l2c_mcix_ctl_t;

static inline uint64_t BDK_DTX_L2C_MCIX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_MCIX_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0FE2E0060ull + (param1 & 3) * 0x8000ull;
	csr_fatal("BDK_DTX_L2C_MCIX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_MCIX_CTL(...) bdk_dtx_l2c_mcix_ctl_t
#define bustype_BDK_DTX_L2C_MCIX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_MCIX_CTL(p1) (p1)
#define arguments_BDK_DTX_L2C_MCIX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_L2C_MCIX_CTL(...) "DTX_L2C_MCIX_CTL"


/**
 * RSL - dtx_l2c_mci#_dat#
 */
typedef union bdk_dtx_l2c_mcix_datx {
	uint64_t u;
	struct bdk_dtx_l2c_mcix_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_l2c_mcix_datx_s     cn85xx; */
	/* struct bdk_dtx_l2c_mcix_datx_s     cn88xx; */
} bdk_dtx_l2c_mcix_datx_t;

static inline uint64_t BDK_DTX_L2C_MCIX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_MCIX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 1)))
		return 0x000087E0FE2E0040ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_L2C_MCIX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_MCIX_DATX(...) bdk_dtx_l2c_mcix_datx_t
#define bustype_BDK_DTX_L2C_MCIX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_MCIX_DATX(p1,p2) (p1)
#define arguments_BDK_DTX_L2C_MCIX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_L2C_MCIX_DATX(...) "DTX_L2C_MCIX_DATX"


/**
 * RSL - dtx_l2c_mci#_ena#
 */
typedef union bdk_dtx_l2c_mcix_enax {
	uint64_t u;
	struct bdk_dtx_l2c_mcix_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_l2c_mcix_enax_s     cn85xx; */
	/* struct bdk_dtx_l2c_mcix_enax_s     cn88xx; */
} bdk_dtx_l2c_mcix_enax_t;

static inline uint64_t BDK_DTX_L2C_MCIX_ENAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_MCIX_ENAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 1)))
		return 0x000087E0FE2E0020ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_L2C_MCIX_ENAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_MCIX_ENAX(...) bdk_dtx_l2c_mcix_enax_t
#define bustype_BDK_DTX_L2C_MCIX_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_MCIX_ENAX(p1,p2) (p1)
#define arguments_BDK_DTX_L2C_MCIX_ENAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_L2C_MCIX_ENAX(...) "DTX_L2C_MCIX_ENAX"


/**
 * RSL - dtx_l2c_mci#_sel#
 */
typedef union bdk_dtx_l2c_mcix_selx {
	uint64_t u;
	struct bdk_dtx_l2c_mcix_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_l2c_mcix_selx_s     cn85xx; */
	/* struct bdk_dtx_l2c_mcix_selx_s     cn88xx; */
} bdk_dtx_l2c_mcix_selx_t;

static inline uint64_t BDK_DTX_L2C_MCIX_SELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_MCIX_SELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 1)))
		return 0x000087E0FE2E0000ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_L2C_MCIX_SELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_MCIX_SELX(...) bdk_dtx_l2c_mcix_selx_t
#define bustype_BDK_DTX_L2C_MCIX_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_MCIX_SELX(p1,p2) (p1)
#define arguments_BDK_DTX_L2C_MCIX_SELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_L2C_MCIX_SELX(...) "DTX_L2C_MCIX_SELX"


/**
 * RSL - dtx_l2c_tad#_bcst_rsp
 */
typedef union bdk_dtx_l2c_tadx_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_l2c_tadx_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_l2c_tadx_bcst_rsp_s cn85xx; */
	/* struct bdk_dtx_l2c_tadx_bcst_rsp_s cn88xx; */
} bdk_dtx_l2c_tadx_bcst_rsp_t;

static inline uint64_t BDK_DTX_L2C_TADX_BCST_RSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_TADX_BCST_RSP(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E0FE280080ull + (param1 & 7) * 0x8000ull;
	csr_fatal("BDK_DTX_L2C_TADX_BCST_RSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_TADX_BCST_RSP(...) bdk_dtx_l2c_tadx_bcst_rsp_t
#define bustype_BDK_DTX_L2C_TADX_BCST_RSP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_TADX_BCST_RSP(p1) (p1)
#define arguments_BDK_DTX_L2C_TADX_BCST_RSP(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_L2C_TADX_BCST_RSP(...) "DTX_L2C_TADX_BCST_RSP"


/**
 * RSL - dtx_l2c_tad#_ctl
 */
typedef union bdk_dtx_l2c_tadx_ctl {
	uint64_t u;
	struct bdk_dtx_l2c_tadx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_l2c_tadx_ctl_s      cn85xx; */
	/* struct bdk_dtx_l2c_tadx_ctl_s      cn88xx; */
} bdk_dtx_l2c_tadx_ctl_t;

static inline uint64_t BDK_DTX_L2C_TADX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_TADX_CTL(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E0FE280060ull + (param1 & 7) * 0x8000ull;
	csr_fatal("BDK_DTX_L2C_TADX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_TADX_CTL(...) bdk_dtx_l2c_tadx_ctl_t
#define bustype_BDK_DTX_L2C_TADX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_TADX_CTL(p1) (p1)
#define arguments_BDK_DTX_L2C_TADX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_L2C_TADX_CTL(...) "DTX_L2C_TADX_CTL"


/**
 * RSL - dtx_l2c_tad#_dat#
 */
typedef union bdk_dtx_l2c_tadx_datx {
	uint64_t u;
	struct bdk_dtx_l2c_tadx_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_l2c_tadx_datx_s     cn85xx; */
	/* struct bdk_dtx_l2c_tadx_datx_s     cn88xx; */
} bdk_dtx_l2c_tadx_datx_t;

static inline uint64_t BDK_DTX_L2C_TADX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_TADX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 7)) && ((param2 <= 1)))
		return 0x000087E0FE280040ull + (param1 & 7) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_L2C_TADX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_TADX_DATX(...) bdk_dtx_l2c_tadx_datx_t
#define bustype_BDK_DTX_L2C_TADX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_TADX_DATX(p1,p2) (p1)
#define arguments_BDK_DTX_L2C_TADX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_L2C_TADX_DATX(...) "DTX_L2C_TADX_DATX"


/**
 * RSL - dtx_l2c_tad#_ena#
 */
typedef union bdk_dtx_l2c_tadx_enax {
	uint64_t u;
	struct bdk_dtx_l2c_tadx_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_l2c_tadx_enax_s     cn85xx; */
	/* struct bdk_dtx_l2c_tadx_enax_s     cn88xx; */
} bdk_dtx_l2c_tadx_enax_t;

static inline uint64_t BDK_DTX_L2C_TADX_ENAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_TADX_ENAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 7)) && ((param2 <= 1)))
		return 0x000087E0FE280020ull + (param1 & 7) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_L2C_TADX_ENAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_TADX_ENAX(...) bdk_dtx_l2c_tadx_enax_t
#define bustype_BDK_DTX_L2C_TADX_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_TADX_ENAX(p1,p2) (p1)
#define arguments_BDK_DTX_L2C_TADX_ENAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_L2C_TADX_ENAX(...) "DTX_L2C_TADX_ENAX"


/**
 * RSL - dtx_l2c_tad#_sel#
 */
typedef union bdk_dtx_l2c_tadx_selx {
	uint64_t u;
	struct bdk_dtx_l2c_tadx_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_l2c_tadx_selx_s     cn85xx; */
	/* struct bdk_dtx_l2c_tadx_selx_s     cn88xx; */
} bdk_dtx_l2c_tadx_selx_t;

static inline uint64_t BDK_DTX_L2C_TADX_SELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_TADX_SELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 7)) && ((param2 <= 1)))
		return 0x000087E0FE280000ull + (param1 & 7) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_L2C_TADX_SELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_L2C_TADX_SELX(...) bdk_dtx_l2c_tadx_selx_t
#define bustype_BDK_DTX_L2C_TADX_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_L2C_TADX_SELX(p1,p2) (p1)
#define arguments_BDK_DTX_L2C_TADX_SELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_L2C_TADX_SELX(...) "DTX_L2C_TADX_SELX"


/**
 * RSL - dtx_lmc#_bcst_rsp
 */
typedef union bdk_dtx_lmcx_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_lmcx_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_lmcx_bcst_rsp_s     cn85xx; */
	/* struct bdk_dtx_lmcx_bcst_rsp_s     cn88xx; */
} bdk_dtx_lmcx_bcst_rsp_t;

static inline uint64_t BDK_DTX_LMCX_BCST_RSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_LMCX_BCST_RSP(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0FE440080ull + (param1 & 3) * 0x8000ull;
	csr_fatal("BDK_DTX_LMCX_BCST_RSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_LMCX_BCST_RSP(...) bdk_dtx_lmcx_bcst_rsp_t
#define bustype_BDK_DTX_LMCX_BCST_RSP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_LMCX_BCST_RSP(p1) (p1)
#define arguments_BDK_DTX_LMCX_BCST_RSP(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_LMCX_BCST_RSP(...) "DTX_LMCX_BCST_RSP"


/**
 * RSL - dtx_lmc#_ctl
 */
typedef union bdk_dtx_lmcx_ctl {
	uint64_t u;
	struct bdk_dtx_lmcx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_lmcx_ctl_s          cn85xx; */
	/* struct bdk_dtx_lmcx_ctl_s          cn88xx; */
} bdk_dtx_lmcx_ctl_t;

static inline uint64_t BDK_DTX_LMCX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_LMCX_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0FE440060ull + (param1 & 3) * 0x8000ull;
	csr_fatal("BDK_DTX_LMCX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_LMCX_CTL(...) bdk_dtx_lmcx_ctl_t
#define bustype_BDK_DTX_LMCX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_LMCX_CTL(p1) (p1)
#define arguments_BDK_DTX_LMCX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_LMCX_CTL(...) "DTX_LMCX_CTL"


/**
 * RSL - dtx_lmc#_dat#
 */
typedef union bdk_dtx_lmcx_datx {
	uint64_t u;
	struct bdk_dtx_lmcx_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_lmcx_datx_s         cn85xx; */
	/* struct bdk_dtx_lmcx_datx_s         cn88xx; */
} bdk_dtx_lmcx_datx_t;

static inline uint64_t BDK_DTX_LMCX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_LMCX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 1)))
		return 0x000087E0FE440040ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_LMCX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_LMCX_DATX(...) bdk_dtx_lmcx_datx_t
#define bustype_BDK_DTX_LMCX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_LMCX_DATX(p1,p2) (p1)
#define arguments_BDK_DTX_LMCX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_LMCX_DATX(...) "DTX_LMCX_DATX"


/**
 * RSL - dtx_lmc#_ena#
 */
typedef union bdk_dtx_lmcx_enax {
	uint64_t u;
	struct bdk_dtx_lmcx_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_lmcx_enax_s         cn85xx; */
	/* struct bdk_dtx_lmcx_enax_s         cn88xx; */
} bdk_dtx_lmcx_enax_t;

static inline uint64_t BDK_DTX_LMCX_ENAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_LMCX_ENAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 1)))
		return 0x000087E0FE440020ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_LMCX_ENAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_LMCX_ENAX(...) bdk_dtx_lmcx_enax_t
#define bustype_BDK_DTX_LMCX_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_LMCX_ENAX(p1,p2) (p1)
#define arguments_BDK_DTX_LMCX_ENAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_LMCX_ENAX(...) "DTX_LMCX_ENAX"


/**
 * RSL - dtx_lmc#_sel#
 */
typedef union bdk_dtx_lmcx_selx {
	uint64_t u;
	struct bdk_dtx_lmcx_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_lmcx_selx_s         cn85xx; */
	/* struct bdk_dtx_lmcx_selx_s         cn88xx; */
} bdk_dtx_lmcx_selx_t;

static inline uint64_t BDK_DTX_LMCX_SELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_LMCX_SELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 1)))
		return 0x000087E0FE440000ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_LMCX_SELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_LMCX_SELX(...) bdk_dtx_lmcx_selx_t
#define bustype_BDK_DTX_LMCX_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_LMCX_SELX(p1,p2) (p1)
#define arguments_BDK_DTX_LMCX_SELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_LMCX_SELX(...) "DTX_LMCX_SELX"


/**
 * RSL - dtx_mio_bcst_rsp
 */
typedef union bdk_dtx_mio_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_mio_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_mio_bcst_rsp_s      cn85xx; */
	/* struct bdk_dtx_mio_bcst_rsp_s      cn88xx; */
} bdk_dtx_mio_bcst_rsp_t;

#define BDK_DTX_MIO_BCST_RSP BDK_DTX_MIO_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_MIO_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MIO_BCST_RSP_FUNC(void)
{
	return 0x000087E0FE000080ull;
}
#define typedef_BDK_DTX_MIO_BCST_RSP bdk_dtx_mio_bcst_rsp_t
#define bustype_BDK_DTX_MIO_BCST_RSP BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_MIO_BCST_RSP 0
#define arguments_BDK_DTX_MIO_BCST_RSP -1,-1,-1,-1
#define basename_BDK_DTX_MIO_BCST_RSP "DTX_MIO_BCST_RSP"


/**
 * RSL - dtx_mio_ctl
 */
typedef union bdk_dtx_mio_ctl {
	uint64_t u;
	struct bdk_dtx_mio_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_mio_ctl_s           cn85xx; */
	/* struct bdk_dtx_mio_ctl_s           cn88xx; */
} bdk_dtx_mio_ctl_t;

#define BDK_DTX_MIO_CTL BDK_DTX_MIO_CTL_FUNC()
static inline uint64_t BDK_DTX_MIO_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MIO_CTL_FUNC(void)
{
	return 0x000087E0FE000060ull;
}
#define typedef_BDK_DTX_MIO_CTL bdk_dtx_mio_ctl_t
#define bustype_BDK_DTX_MIO_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_MIO_CTL 0
#define arguments_BDK_DTX_MIO_CTL -1,-1,-1,-1
#define basename_BDK_DTX_MIO_CTL "DTX_MIO_CTL"


/**
 * RSL - dtx_mio_dat#
 */
typedef union bdk_dtx_mio_datx {
	uint64_t u;
	struct bdk_dtx_mio_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_mio_datx_s          cn85xx; */
	/* struct bdk_dtx_mio_datx_s          cn88xx; */
} bdk_dtx_mio_datx_t;

static inline uint64_t BDK_DTX_MIO_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MIO_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE000040ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_MIO_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_MIO_DATX(...) bdk_dtx_mio_datx_t
#define bustype_BDK_DTX_MIO_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_MIO_DATX(p1) (p1)
#define arguments_BDK_DTX_MIO_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_MIO_DATX(...) "DTX_MIO_DATX"


/**
 * RSL - dtx_mio_ena#
 */
typedef union bdk_dtx_mio_enax {
	uint64_t u;
	struct bdk_dtx_mio_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_mio_enax_s          cn85xx; */
	/* struct bdk_dtx_mio_enax_s          cn88xx; */
} bdk_dtx_mio_enax_t;

static inline uint64_t BDK_DTX_MIO_ENAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MIO_ENAX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE000020ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_MIO_ENAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_MIO_ENAX(...) bdk_dtx_mio_enax_t
#define bustype_BDK_DTX_MIO_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_MIO_ENAX(p1) (p1)
#define arguments_BDK_DTX_MIO_ENAX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_MIO_ENAX(...) "DTX_MIO_ENAX"


/**
 * RSL - dtx_mio_sel#
 */
typedef union bdk_dtx_mio_selx {
	uint64_t u;
	struct bdk_dtx_mio_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_mio_selx_s          cn85xx; */
	/* struct bdk_dtx_mio_selx_s          cn88xx; */
} bdk_dtx_mio_selx_t;

static inline uint64_t BDK_DTX_MIO_SELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MIO_SELX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE000000ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_MIO_SELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_MIO_SELX(...) bdk_dtx_mio_selx_t
#define bustype_BDK_DTX_MIO_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_MIO_SELX(p1) (p1)
#define arguments_BDK_DTX_MIO_SELX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_MIO_SELX(...) "DTX_MIO_SELX"


/**
 * RSL - dtx_mrml_bcst_rsp
 */
typedef union bdk_dtx_mrml_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_mrml_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_mrml_bcst_rsp_s     cn85xx; */
	/* struct bdk_dtx_mrml_bcst_rsp_s     cn88xx; */
} bdk_dtx_mrml_bcst_rsp_t;

#define BDK_DTX_MRML_BCST_RSP BDK_DTX_MRML_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_MRML_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MRML_BCST_RSP_FUNC(void)
{
	return 0x000087E0FE7E0080ull;
}
#define typedef_BDK_DTX_MRML_BCST_RSP bdk_dtx_mrml_bcst_rsp_t
#define bustype_BDK_DTX_MRML_BCST_RSP BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_MRML_BCST_RSP 0
#define arguments_BDK_DTX_MRML_BCST_RSP -1,-1,-1,-1
#define basename_BDK_DTX_MRML_BCST_RSP "DTX_MRML_BCST_RSP"


/**
 * RSL - dtx_mrml_ctl
 */
typedef union bdk_dtx_mrml_ctl {
	uint64_t u;
	struct bdk_dtx_mrml_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_mrml_ctl_s          cn85xx; */
	/* struct bdk_dtx_mrml_ctl_s          cn88xx; */
} bdk_dtx_mrml_ctl_t;

#define BDK_DTX_MRML_CTL BDK_DTX_MRML_CTL_FUNC()
static inline uint64_t BDK_DTX_MRML_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MRML_CTL_FUNC(void)
{
	return 0x000087E0FE7E0060ull;
}
#define typedef_BDK_DTX_MRML_CTL bdk_dtx_mrml_ctl_t
#define bustype_BDK_DTX_MRML_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_MRML_CTL 0
#define arguments_BDK_DTX_MRML_CTL -1,-1,-1,-1
#define basename_BDK_DTX_MRML_CTL "DTX_MRML_CTL"


/**
 * RSL - dtx_mrml_dat#
 */
typedef union bdk_dtx_mrml_datx {
	uint64_t u;
	struct bdk_dtx_mrml_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_mrml_datx_s         cn85xx; */
	/* struct bdk_dtx_mrml_datx_s         cn88xx; */
} bdk_dtx_mrml_datx_t;

static inline uint64_t BDK_DTX_MRML_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MRML_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE7E0040ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_MRML_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_MRML_DATX(...) bdk_dtx_mrml_datx_t
#define bustype_BDK_DTX_MRML_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_MRML_DATX(p1) (p1)
#define arguments_BDK_DTX_MRML_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_MRML_DATX(...) "DTX_MRML_DATX"


/**
 * RSL - dtx_mrml_ena#
 */
typedef union bdk_dtx_mrml_enax {
	uint64_t u;
	struct bdk_dtx_mrml_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_mrml_enax_s         cn85xx; */
	/* struct bdk_dtx_mrml_enax_s         cn88xx; */
} bdk_dtx_mrml_enax_t;

static inline uint64_t BDK_DTX_MRML_ENAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MRML_ENAX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE7E0020ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_MRML_ENAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_MRML_ENAX(...) bdk_dtx_mrml_enax_t
#define bustype_BDK_DTX_MRML_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_MRML_ENAX(p1) (p1)
#define arguments_BDK_DTX_MRML_ENAX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_MRML_ENAX(...) "DTX_MRML_ENAX"


/**
 * RSL - dtx_mrml_sel#
 */
typedef union bdk_dtx_mrml_selx {
	uint64_t u;
	struct bdk_dtx_mrml_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_mrml_selx_s         cn85xx; */
	/* struct bdk_dtx_mrml_selx_s         cn88xx; */
} bdk_dtx_mrml_selx_t;

static inline uint64_t BDK_DTX_MRML_SELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MRML_SELX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE7E0000ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_MRML_SELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_MRML_SELX(...) bdk_dtx_mrml_selx_t
#define bustype_BDK_DTX_MRML_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_MRML_SELX(p1) (p1)
#define arguments_BDK_DTX_MRML_SELX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_MRML_SELX(...) "DTX_MRML_SELX"


/**
 * RSL - dtx_ncsi_bcst_rsp
 */
typedef union bdk_dtx_ncsi_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_ncsi_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_ncsi_bcst_rsp_s     cn85xx; */
	/* struct bdk_dtx_ncsi_bcst_rsp_s     cn88xx; */
} bdk_dtx_ncsi_bcst_rsp_t;

#define BDK_DTX_NCSI_BCST_RSP BDK_DTX_NCSI_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_NCSI_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NCSI_BCST_RSP_FUNC(void)
{
	return 0x000087E0FE058080ull;
}
#define typedef_BDK_DTX_NCSI_BCST_RSP bdk_dtx_ncsi_bcst_rsp_t
#define bustype_BDK_DTX_NCSI_BCST_RSP BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_NCSI_BCST_RSP 0
#define arguments_BDK_DTX_NCSI_BCST_RSP -1,-1,-1,-1
#define basename_BDK_DTX_NCSI_BCST_RSP "DTX_NCSI_BCST_RSP"


/**
 * RSL - dtx_ncsi_ctl
 */
typedef union bdk_dtx_ncsi_ctl {
	uint64_t u;
	struct bdk_dtx_ncsi_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_ncsi_ctl_s          cn85xx; */
	/* struct bdk_dtx_ncsi_ctl_s          cn88xx; */
} bdk_dtx_ncsi_ctl_t;

#define BDK_DTX_NCSI_CTL BDK_DTX_NCSI_CTL_FUNC()
static inline uint64_t BDK_DTX_NCSI_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NCSI_CTL_FUNC(void)
{
	return 0x000087E0FE058060ull;
}
#define typedef_BDK_DTX_NCSI_CTL bdk_dtx_ncsi_ctl_t
#define bustype_BDK_DTX_NCSI_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_NCSI_CTL 0
#define arguments_BDK_DTX_NCSI_CTL -1,-1,-1,-1
#define basename_BDK_DTX_NCSI_CTL "DTX_NCSI_CTL"


/**
 * RSL - dtx_ncsi_dat#
 */
typedef union bdk_dtx_ncsi_datx {
	uint64_t u;
	struct bdk_dtx_ncsi_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_ncsi_datx_s         cn85xx; */
	/* struct bdk_dtx_ncsi_datx_s         cn88xx; */
} bdk_dtx_ncsi_datx_t;

static inline uint64_t BDK_DTX_NCSI_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NCSI_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE058040ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_NCSI_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_NCSI_DATX(...) bdk_dtx_ncsi_datx_t
#define bustype_BDK_DTX_NCSI_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_NCSI_DATX(p1) (p1)
#define arguments_BDK_DTX_NCSI_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_NCSI_DATX(...) "DTX_NCSI_DATX"


/**
 * RSL - dtx_ncsi_ena#
 */
typedef union bdk_dtx_ncsi_enax {
	uint64_t u;
	struct bdk_dtx_ncsi_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_ncsi_enax_s         cn85xx; */
	/* struct bdk_dtx_ncsi_enax_s         cn88xx; */
} bdk_dtx_ncsi_enax_t;

static inline uint64_t BDK_DTX_NCSI_ENAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NCSI_ENAX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE058020ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_NCSI_ENAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_NCSI_ENAX(...) bdk_dtx_ncsi_enax_t
#define bustype_BDK_DTX_NCSI_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_NCSI_ENAX(p1) (p1)
#define arguments_BDK_DTX_NCSI_ENAX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_NCSI_ENAX(...) "DTX_NCSI_ENAX"


/**
 * RSL - dtx_ncsi_sel#
 */
typedef union bdk_dtx_ncsi_selx {
	uint64_t u;
	struct bdk_dtx_ncsi_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_ncsi_selx_s         cn85xx; */
	/* struct bdk_dtx_ncsi_selx_s         cn88xx; */
} bdk_dtx_ncsi_selx_t;

static inline uint64_t BDK_DTX_NCSI_SELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NCSI_SELX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE058000ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_NCSI_SELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_NCSI_SELX(...) bdk_dtx_ncsi_selx_t
#define bustype_BDK_DTX_NCSI_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_NCSI_SELX(p1) (p1)
#define arguments_BDK_DTX_NCSI_SELX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_NCSI_SELX(...) "DTX_NCSI_SELX"


/**
 * RSL - dtx_nic_bcst_rsp
 */
typedef union bdk_dtx_nic_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_nic_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_nic_bcst_rsp_s      cn85xx; */
	/* struct bdk_dtx_nic_bcst_rsp_s      cn88xx; */
} bdk_dtx_nic_bcst_rsp_t;

#define BDK_DTX_NIC_BCST_RSP BDK_DTX_NIC_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_NIC_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NIC_BCST_RSP_FUNC(void)
{
	return 0x000087E0FEA18080ull;
}
#define typedef_BDK_DTX_NIC_BCST_RSP bdk_dtx_nic_bcst_rsp_t
#define bustype_BDK_DTX_NIC_BCST_RSP BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_NIC_BCST_RSP 0
#define arguments_BDK_DTX_NIC_BCST_RSP -1,-1,-1,-1
#define basename_BDK_DTX_NIC_BCST_RSP "DTX_NIC_BCST_RSP"


/**
 * RSL - dtx_nic_ctl
 */
typedef union bdk_dtx_nic_ctl {
	uint64_t u;
	struct bdk_dtx_nic_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_nic_ctl_s           cn85xx; */
	/* struct bdk_dtx_nic_ctl_s           cn88xx; */
} bdk_dtx_nic_ctl_t;

#define BDK_DTX_NIC_CTL BDK_DTX_NIC_CTL_FUNC()
static inline uint64_t BDK_DTX_NIC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NIC_CTL_FUNC(void)
{
	return 0x000087E0FEA18060ull;
}
#define typedef_BDK_DTX_NIC_CTL bdk_dtx_nic_ctl_t
#define bustype_BDK_DTX_NIC_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_NIC_CTL 0
#define arguments_BDK_DTX_NIC_CTL -1,-1,-1,-1
#define basename_BDK_DTX_NIC_CTL "DTX_NIC_CTL"


/**
 * RSL - dtx_nic_dat#
 */
typedef union bdk_dtx_nic_datx {
	uint64_t u;
	struct bdk_dtx_nic_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_nic_datx_s          cn85xx; */
	/* struct bdk_dtx_nic_datx_s          cn88xx; */
} bdk_dtx_nic_datx_t;

static inline uint64_t BDK_DTX_NIC_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NIC_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FEA18040ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_NIC_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_NIC_DATX(...) bdk_dtx_nic_datx_t
#define bustype_BDK_DTX_NIC_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_NIC_DATX(p1) (p1)
#define arguments_BDK_DTX_NIC_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_NIC_DATX(...) "DTX_NIC_DATX"


/**
 * RSL - dtx_nic_ena#
 */
typedef union bdk_dtx_nic_enax {
	uint64_t u;
	struct bdk_dtx_nic_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_nic_enax_s          cn85xx; */
	/* struct bdk_dtx_nic_enax_s          cn88xx; */
} bdk_dtx_nic_enax_t;

static inline uint64_t BDK_DTX_NIC_ENAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NIC_ENAX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FEA18020ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_NIC_ENAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_NIC_ENAX(...) bdk_dtx_nic_enax_t
#define bustype_BDK_DTX_NIC_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_NIC_ENAX(p1) (p1)
#define arguments_BDK_DTX_NIC_ENAX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_NIC_ENAX(...) "DTX_NIC_ENAX"


/**
 * RSL - dtx_nic_sel#
 */
typedef union bdk_dtx_nic_selx {
	uint64_t u;
	struct bdk_dtx_nic_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_nic_selx_s          cn85xx; */
	/* struct bdk_dtx_nic_selx_s          cn88xx; */
} bdk_dtx_nic_selx_t;

static inline uint64_t BDK_DTX_NIC_SELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NIC_SELX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FEA18000ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_NIC_SELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_NIC_SELX(...) bdk_dtx_nic_selx_t
#define bustype_BDK_DTX_NIC_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_NIC_SELX(p1) (p1)
#define arguments_BDK_DTX_NIC_SELX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_NIC_SELX(...) "DTX_NIC_SELX"


/**
 * RSL - dtx_ocx_lnk#_bcst_rsp
 */
typedef union bdk_dtx_ocx_lnkx_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_ocx_lnkx_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_ocx_lnkx_bcst_rsp_s cn85xx; */
	/* struct bdk_dtx_ocx_lnkx_bcst_rsp_s cn88xx; */
} bdk_dtx_ocx_lnkx_bcst_rsp_t;

static inline uint64_t BDK_DTX_OCX_LNKX_BCST_RSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_LNKX_BCST_RSP(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E0FE180080ull + (param1 & 3) * 0x8000ull;
	csr_fatal("BDK_DTX_OCX_LNKX_BCST_RSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_OCX_LNKX_BCST_RSP(...) bdk_dtx_ocx_lnkx_bcst_rsp_t
#define bustype_BDK_DTX_OCX_LNKX_BCST_RSP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_LNKX_BCST_RSP(p1) (p1)
#define arguments_BDK_DTX_OCX_LNKX_BCST_RSP(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_OCX_LNKX_BCST_RSP(...) "DTX_OCX_LNKX_BCST_RSP"


/**
 * RSL - dtx_ocx_lnk#_ctl
 */
typedef union bdk_dtx_ocx_lnkx_ctl {
	uint64_t u;
	struct bdk_dtx_ocx_lnkx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_ocx_lnkx_ctl_s      cn85xx; */
	/* struct bdk_dtx_ocx_lnkx_ctl_s      cn88xx; */
} bdk_dtx_ocx_lnkx_ctl_t;

static inline uint64_t BDK_DTX_OCX_LNKX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_LNKX_CTL(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E0FE180060ull + (param1 & 3) * 0x8000ull;
	csr_fatal("BDK_DTX_OCX_LNKX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_OCX_LNKX_CTL(...) bdk_dtx_ocx_lnkx_ctl_t
#define bustype_BDK_DTX_OCX_LNKX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_LNKX_CTL(p1) (p1)
#define arguments_BDK_DTX_OCX_LNKX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_OCX_LNKX_CTL(...) "DTX_OCX_LNKX_CTL"


/**
 * RSL - dtx_ocx_lnk#_dat#
 */
typedef union bdk_dtx_ocx_lnkx_datx {
	uint64_t u;
	struct bdk_dtx_ocx_lnkx_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_ocx_lnkx_datx_s     cn85xx; */
	/* struct bdk_dtx_ocx_lnkx_datx_s     cn88xx; */
} bdk_dtx_ocx_lnkx_datx_t;

static inline uint64_t BDK_DTX_OCX_LNKX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_LNKX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 1)))
		return 0x000087E0FE180040ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_OCX_LNKX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_OCX_LNKX_DATX(...) bdk_dtx_ocx_lnkx_datx_t
#define bustype_BDK_DTX_OCX_LNKX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_LNKX_DATX(p1,p2) (p1)
#define arguments_BDK_DTX_OCX_LNKX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_OCX_LNKX_DATX(...) "DTX_OCX_LNKX_DATX"


/**
 * RSL - dtx_ocx_lnk#_ena#
 */
typedef union bdk_dtx_ocx_lnkx_enax {
	uint64_t u;
	struct bdk_dtx_ocx_lnkx_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_ocx_lnkx_enax_s     cn85xx; */
	/* struct bdk_dtx_ocx_lnkx_enax_s     cn88xx; */
} bdk_dtx_ocx_lnkx_enax_t;

static inline uint64_t BDK_DTX_OCX_LNKX_ENAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_LNKX_ENAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 1)))
		return 0x000087E0FE180020ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_OCX_LNKX_ENAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_OCX_LNKX_ENAX(...) bdk_dtx_ocx_lnkx_enax_t
#define bustype_BDK_DTX_OCX_LNKX_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_LNKX_ENAX(p1,p2) (p1)
#define arguments_BDK_DTX_OCX_LNKX_ENAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_OCX_LNKX_ENAX(...) "DTX_OCX_LNKX_ENAX"


/**
 * RSL - dtx_ocx_lnk#_sel#
 */
typedef union bdk_dtx_ocx_lnkx_selx {
	uint64_t u;
	struct bdk_dtx_ocx_lnkx_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_ocx_lnkx_selx_s     cn85xx; */
	/* struct bdk_dtx_ocx_lnkx_selx_s     cn88xx; */
} bdk_dtx_ocx_lnkx_selx_t;

static inline uint64_t BDK_DTX_OCX_LNKX_SELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_LNKX_SELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 1)))
		return 0x000087E0FE180000ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_OCX_LNKX_SELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_OCX_LNKX_SELX(...) bdk_dtx_ocx_lnkx_selx_t
#define bustype_BDK_DTX_OCX_LNKX_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_LNKX_SELX(p1,p2) (p1)
#define arguments_BDK_DTX_OCX_LNKX_SELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_OCX_LNKX_SELX(...) "DTX_OCX_LNKX_SELX"


/**
 * RSL - dtx_ocx_ole#_bcst_rsp
 */
typedef union bdk_dtx_ocx_olex_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_ocx_olex_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_ocx_olex_bcst_rsp_s cn85xx; */
	/* struct bdk_dtx_ocx_olex_bcst_rsp_s cn88xx; */
} bdk_dtx_ocx_olex_bcst_rsp_t;

static inline uint64_t BDK_DTX_OCX_OLEX_BCST_RSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_OLEX_BCST_RSP(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E0FE1A0080ull + (param1 & 3) * 0x8000ull;
	csr_fatal("BDK_DTX_OCX_OLEX_BCST_RSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_OCX_OLEX_BCST_RSP(...) bdk_dtx_ocx_olex_bcst_rsp_t
#define bustype_BDK_DTX_OCX_OLEX_BCST_RSP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_OLEX_BCST_RSP(p1) (p1)
#define arguments_BDK_DTX_OCX_OLEX_BCST_RSP(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_OCX_OLEX_BCST_RSP(...) "DTX_OCX_OLEX_BCST_RSP"


/**
 * RSL - dtx_ocx_ole#_ctl
 */
typedef union bdk_dtx_ocx_olex_ctl {
	uint64_t u;
	struct bdk_dtx_ocx_olex_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_ocx_olex_ctl_s      cn85xx; */
	/* struct bdk_dtx_ocx_olex_ctl_s      cn88xx; */
} bdk_dtx_ocx_olex_ctl_t;

static inline uint64_t BDK_DTX_OCX_OLEX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_OLEX_CTL(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E0FE1A0060ull + (param1 & 3) * 0x8000ull;
	csr_fatal("BDK_DTX_OCX_OLEX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_OCX_OLEX_CTL(...) bdk_dtx_ocx_olex_ctl_t
#define bustype_BDK_DTX_OCX_OLEX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_OLEX_CTL(p1) (p1)
#define arguments_BDK_DTX_OCX_OLEX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_OCX_OLEX_CTL(...) "DTX_OCX_OLEX_CTL"


/**
 * RSL - dtx_ocx_ole#_dat#
 */
typedef union bdk_dtx_ocx_olex_datx {
	uint64_t u;
	struct bdk_dtx_ocx_olex_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_ocx_olex_datx_s     cn85xx; */
	/* struct bdk_dtx_ocx_olex_datx_s     cn88xx; */
} bdk_dtx_ocx_olex_datx_t;

static inline uint64_t BDK_DTX_OCX_OLEX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_OLEX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 1)))
		return 0x000087E0FE1A0040ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_OCX_OLEX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_OCX_OLEX_DATX(...) bdk_dtx_ocx_olex_datx_t
#define bustype_BDK_DTX_OCX_OLEX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_OLEX_DATX(p1,p2) (p1)
#define arguments_BDK_DTX_OCX_OLEX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_OCX_OLEX_DATX(...) "DTX_OCX_OLEX_DATX"


/**
 * RSL - dtx_ocx_ole#_ena#
 */
typedef union bdk_dtx_ocx_olex_enax {
	uint64_t u;
	struct bdk_dtx_ocx_olex_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_ocx_olex_enax_s     cn85xx; */
	/* struct bdk_dtx_ocx_olex_enax_s     cn88xx; */
} bdk_dtx_ocx_olex_enax_t;

static inline uint64_t BDK_DTX_OCX_OLEX_ENAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_OLEX_ENAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 1)))
		return 0x000087E0FE1A0020ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_OCX_OLEX_ENAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_OCX_OLEX_ENAX(...) bdk_dtx_ocx_olex_enax_t
#define bustype_BDK_DTX_OCX_OLEX_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_OLEX_ENAX(p1,p2) (p1)
#define arguments_BDK_DTX_OCX_OLEX_ENAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_OCX_OLEX_ENAX(...) "DTX_OCX_OLEX_ENAX"


/**
 * RSL - dtx_ocx_ole#_sel#
 */
typedef union bdk_dtx_ocx_olex_selx {
	uint64_t u;
	struct bdk_dtx_ocx_olex_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_ocx_olex_selx_s     cn85xx; */
	/* struct bdk_dtx_ocx_olex_selx_s     cn88xx; */
} bdk_dtx_ocx_olex_selx_t;

static inline uint64_t BDK_DTX_OCX_OLEX_SELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_OLEX_SELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 1)))
		return 0x000087E0FE1A0000ull + (param1 & 3) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_OCX_OLEX_SELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_OCX_OLEX_SELX(...) bdk_dtx_ocx_olex_selx_t
#define bustype_BDK_DTX_OCX_OLEX_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_OLEX_SELX(p1,p2) (p1)
#define arguments_BDK_DTX_OCX_OLEX_SELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_OCX_OLEX_SELX(...) "DTX_OCX_OLEX_SELX"


/**
 * RSL - dtx_ocx_top_bcst_rsp
 */
typedef union bdk_dtx_ocx_top_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_ocx_top_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_ocx_top_bcst_rsp_s  cn85xx; */
	/* struct bdk_dtx_ocx_top_bcst_rsp_s  cn88xx; */
} bdk_dtx_ocx_top_bcst_rsp_t;

#define BDK_DTX_OCX_TOP_BCST_RSP BDK_DTX_OCX_TOP_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_OCX_TOP_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_TOP_BCST_RSP_FUNC(void)
{
	return 0x000087E0FE088080ull;
}
#define typedef_BDK_DTX_OCX_TOP_BCST_RSP bdk_dtx_ocx_top_bcst_rsp_t
#define bustype_BDK_DTX_OCX_TOP_BCST_RSP BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_TOP_BCST_RSP 0
#define arguments_BDK_DTX_OCX_TOP_BCST_RSP -1,-1,-1,-1
#define basename_BDK_DTX_OCX_TOP_BCST_RSP "DTX_OCX_TOP_BCST_RSP"


/**
 * RSL - dtx_ocx_top_ctl
 */
typedef union bdk_dtx_ocx_top_ctl {
	uint64_t u;
	struct bdk_dtx_ocx_top_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_ocx_top_ctl_s       cn85xx; */
	/* struct bdk_dtx_ocx_top_ctl_s       cn88xx; */
} bdk_dtx_ocx_top_ctl_t;

#define BDK_DTX_OCX_TOP_CTL BDK_DTX_OCX_TOP_CTL_FUNC()
static inline uint64_t BDK_DTX_OCX_TOP_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_TOP_CTL_FUNC(void)
{
	return 0x000087E0FE088060ull;
}
#define typedef_BDK_DTX_OCX_TOP_CTL bdk_dtx_ocx_top_ctl_t
#define bustype_BDK_DTX_OCX_TOP_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_TOP_CTL 0
#define arguments_BDK_DTX_OCX_TOP_CTL -1,-1,-1,-1
#define basename_BDK_DTX_OCX_TOP_CTL "DTX_OCX_TOP_CTL"


/**
 * RSL - dtx_ocx_top_dat#
 */
typedef union bdk_dtx_ocx_top_datx {
	uint64_t u;
	struct bdk_dtx_ocx_top_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_ocx_top_datx_s      cn85xx; */
	/* struct bdk_dtx_ocx_top_datx_s      cn88xx; */
} bdk_dtx_ocx_top_datx_t;

static inline uint64_t BDK_DTX_OCX_TOP_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_TOP_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE088040ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_OCX_TOP_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_OCX_TOP_DATX(...) bdk_dtx_ocx_top_datx_t
#define bustype_BDK_DTX_OCX_TOP_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_TOP_DATX(p1) (p1)
#define arguments_BDK_DTX_OCX_TOP_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_OCX_TOP_DATX(...) "DTX_OCX_TOP_DATX"


/**
 * RSL - dtx_ocx_top_ena#
 */
typedef union bdk_dtx_ocx_top_enax {
	uint64_t u;
	struct bdk_dtx_ocx_top_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_ocx_top_enax_s      cn85xx; */
	/* struct bdk_dtx_ocx_top_enax_s      cn88xx; */
} bdk_dtx_ocx_top_enax_t;

static inline uint64_t BDK_DTX_OCX_TOP_ENAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_TOP_ENAX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE088020ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_OCX_TOP_ENAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_OCX_TOP_ENAX(...) bdk_dtx_ocx_top_enax_t
#define bustype_BDK_DTX_OCX_TOP_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_TOP_ENAX(p1) (p1)
#define arguments_BDK_DTX_OCX_TOP_ENAX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_OCX_TOP_ENAX(...) "DTX_OCX_TOP_ENAX"


/**
 * RSL - dtx_ocx_top_sel#
 */
typedef union bdk_dtx_ocx_top_selx {
	uint64_t u;
	struct bdk_dtx_ocx_top_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_ocx_top_selx_s      cn85xx; */
	/* struct bdk_dtx_ocx_top_selx_s      cn88xx; */
} bdk_dtx_ocx_top_selx_t;

static inline uint64_t BDK_DTX_OCX_TOP_SELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_TOP_SELX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE088000ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_OCX_TOP_SELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_OCX_TOP_SELX(...) bdk_dtx_ocx_top_selx_t
#define bustype_BDK_DTX_OCX_TOP_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_OCX_TOP_SELX(p1) (p1)
#define arguments_BDK_DTX_OCX_TOP_SELX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_OCX_TOP_SELX(...) "DTX_OCX_TOP_SELX"


/**
 * RSL - dtx_pem#_bcst_rsp
 */
typedef union bdk_dtx_pemx_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_pemx_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_pemx_bcst_rsp_s     cn85xx; */
	/* struct bdk_dtx_pemx_bcst_rsp_s     cn88xx; */
} bdk_dtx_pemx_bcst_rsp_t;

static inline uint64_t BDK_DTX_PEMX_BCST_RSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_PEMX_BCST_RSP(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0FE600080ull + (param1 & 7) * 0x8000ull;
	csr_fatal("BDK_DTX_PEMX_BCST_RSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_PEMX_BCST_RSP(...) bdk_dtx_pemx_bcst_rsp_t
#define bustype_BDK_DTX_PEMX_BCST_RSP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_PEMX_BCST_RSP(p1) (p1)
#define arguments_BDK_DTX_PEMX_BCST_RSP(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_PEMX_BCST_RSP(...) "DTX_PEMX_BCST_RSP"


/**
 * RSL - dtx_pem#_ctl
 */
typedef union bdk_dtx_pemx_ctl {
	uint64_t u;
	struct bdk_dtx_pemx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_pemx_ctl_s          cn85xx; */
	/* struct bdk_dtx_pemx_ctl_s          cn88xx; */
} bdk_dtx_pemx_ctl_t;

static inline uint64_t BDK_DTX_PEMX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_PEMX_CTL(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0FE600060ull + (param1 & 7) * 0x8000ull;
	csr_fatal("BDK_DTX_PEMX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_PEMX_CTL(...) bdk_dtx_pemx_ctl_t
#define bustype_BDK_DTX_PEMX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_PEMX_CTL(p1) (p1)
#define arguments_BDK_DTX_PEMX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_PEMX_CTL(...) "DTX_PEMX_CTL"


/**
 * RSL - dtx_pem#_dat#
 */
typedef union bdk_dtx_pemx_datx {
	uint64_t u;
	struct bdk_dtx_pemx_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_pemx_datx_s         cn85xx; */
	/* struct bdk_dtx_pemx_datx_s         cn88xx; */
} bdk_dtx_pemx_datx_t;

static inline uint64_t BDK_DTX_PEMX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_PEMX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 5)) && ((param2 <= 1)))
		return 0x000087E0FE600040ull + (param1 & 7) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_PEMX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_PEMX_DATX(...) bdk_dtx_pemx_datx_t
#define bustype_BDK_DTX_PEMX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_PEMX_DATX(p1,p2) (p1)
#define arguments_BDK_DTX_PEMX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_PEMX_DATX(...) "DTX_PEMX_DATX"


/**
 * RSL - dtx_pem#_ena#
 */
typedef union bdk_dtx_pemx_enax {
	uint64_t u;
	struct bdk_dtx_pemx_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_pemx_enax_s         cn85xx; */
	/* struct bdk_dtx_pemx_enax_s         cn88xx; */
} bdk_dtx_pemx_enax_t;

static inline uint64_t BDK_DTX_PEMX_ENAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_PEMX_ENAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 5)) && ((param2 <= 1)))
		return 0x000087E0FE600020ull + (param1 & 7) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_PEMX_ENAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_PEMX_ENAX(...) bdk_dtx_pemx_enax_t
#define bustype_BDK_DTX_PEMX_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_PEMX_ENAX(p1,p2) (p1)
#define arguments_BDK_DTX_PEMX_ENAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_PEMX_ENAX(...) "DTX_PEMX_ENAX"


/**
 * RSL - dtx_pem#_sel#
 */
typedef union bdk_dtx_pemx_selx {
	uint64_t u;
	struct bdk_dtx_pemx_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_pemx_selx_s         cn85xx; */
	/* struct bdk_dtx_pemx_selx_s         cn88xx; */
} bdk_dtx_pemx_selx_t;

static inline uint64_t BDK_DTX_PEMX_SELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_PEMX_SELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 5)) && ((param2 <= 1)))
		return 0x000087E0FE600000ull + (param1 & 7) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_PEMX_SELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_PEMX_SELX(...) bdk_dtx_pemx_selx_t
#define bustype_BDK_DTX_PEMX_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_PEMX_SELX(p1,p2) (p1)
#define arguments_BDK_DTX_PEMX_SELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_PEMX_SELX(...) "DTX_PEMX_SELX"


/**
 * RSL - dtx_rad_bcst_rsp
 */
typedef union bdk_dtx_rad_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_rad_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_rad_bcst_rsp_s      cn85xx; */
	/* struct bdk_dtx_rad_bcst_rsp_s      cn88xx; */
} bdk_dtx_rad_bcst_rsp_t;

#define BDK_DTX_RAD_BCST_RSP BDK_DTX_RAD_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_RAD_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RAD_BCST_RSP_FUNC(void)
{
	return 0x000087E0FE380080ull;
}
#define typedef_BDK_DTX_RAD_BCST_RSP bdk_dtx_rad_bcst_rsp_t
#define bustype_BDK_DTX_RAD_BCST_RSP BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RAD_BCST_RSP 0
#define arguments_BDK_DTX_RAD_BCST_RSP -1,-1,-1,-1
#define basename_BDK_DTX_RAD_BCST_RSP "DTX_RAD_BCST_RSP"


/**
 * RSL - dtx_rad_ctl
 */
typedef union bdk_dtx_rad_ctl {
	uint64_t u;
	struct bdk_dtx_rad_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_rad_ctl_s           cn85xx; */
	/* struct bdk_dtx_rad_ctl_s           cn88xx; */
} bdk_dtx_rad_ctl_t;

#define BDK_DTX_RAD_CTL BDK_DTX_RAD_CTL_FUNC()
static inline uint64_t BDK_DTX_RAD_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RAD_CTL_FUNC(void)
{
	return 0x000087E0FE380060ull;
}
#define typedef_BDK_DTX_RAD_CTL bdk_dtx_rad_ctl_t
#define bustype_BDK_DTX_RAD_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RAD_CTL 0
#define arguments_BDK_DTX_RAD_CTL -1,-1,-1,-1
#define basename_BDK_DTX_RAD_CTL "DTX_RAD_CTL"


/**
 * RSL - dtx_rad_dat#
 */
typedef union bdk_dtx_rad_datx {
	uint64_t u;
	struct bdk_dtx_rad_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_rad_datx_s          cn85xx; */
	/* struct bdk_dtx_rad_datx_s          cn88xx; */
} bdk_dtx_rad_datx_t;

static inline uint64_t BDK_DTX_RAD_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RAD_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE380040ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_RAD_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_RAD_DATX(...) bdk_dtx_rad_datx_t
#define bustype_BDK_DTX_RAD_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RAD_DATX(p1) (p1)
#define arguments_BDK_DTX_RAD_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_RAD_DATX(...) "DTX_RAD_DATX"


/**
 * RSL - dtx_rad_ena#
 */
typedef union bdk_dtx_rad_enax {
	uint64_t u;
	struct bdk_dtx_rad_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_rad_enax_s          cn85xx; */
	/* struct bdk_dtx_rad_enax_s          cn88xx; */
} bdk_dtx_rad_enax_t;

static inline uint64_t BDK_DTX_RAD_ENAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RAD_ENAX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE380020ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_RAD_ENAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_RAD_ENAX(...) bdk_dtx_rad_enax_t
#define bustype_BDK_DTX_RAD_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RAD_ENAX(p1) (p1)
#define arguments_BDK_DTX_RAD_ENAX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_RAD_ENAX(...) "DTX_RAD_ENAX"


/**
 * RSL - dtx_rad_sel#
 */
typedef union bdk_dtx_rad_selx {
	uint64_t u;
	struct bdk_dtx_rad_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_rad_selx_s          cn85xx; */
	/* struct bdk_dtx_rad_selx_s          cn88xx; */
} bdk_dtx_rad_selx_t;

static inline uint64_t BDK_DTX_RAD_SELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RAD_SELX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE380000ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_RAD_SELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_RAD_SELX(...) bdk_dtx_rad_selx_t
#define bustype_BDK_DTX_RAD_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RAD_SELX(p1) (p1)
#define arguments_BDK_DTX_RAD_SELX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_RAD_SELX(...) "DTX_RAD_SELX"


/**
 * RSL - dtx_rnm_bcst_rsp
 */
typedef union bdk_dtx_rnm_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_rnm_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_rnm_bcst_rsp_s      cn85xx; */
	/* struct bdk_dtx_rnm_bcst_rsp_s      cn88xx; */
} bdk_dtx_rnm_bcst_rsp_t;

#define BDK_DTX_RNM_BCST_RSP BDK_DTX_RNM_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_RNM_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RNM_BCST_RSP_FUNC(void)
{
	return 0x000087E0FE200080ull;
}
#define typedef_BDK_DTX_RNM_BCST_RSP bdk_dtx_rnm_bcst_rsp_t
#define bustype_BDK_DTX_RNM_BCST_RSP BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RNM_BCST_RSP 0
#define arguments_BDK_DTX_RNM_BCST_RSP -1,-1,-1,-1
#define basename_BDK_DTX_RNM_BCST_RSP "DTX_RNM_BCST_RSP"


/**
 * RSL - dtx_rnm_ctl
 */
typedef union bdk_dtx_rnm_ctl {
	uint64_t u;
	struct bdk_dtx_rnm_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_rnm_ctl_s           cn85xx; */
	/* struct bdk_dtx_rnm_ctl_s           cn88xx; */
} bdk_dtx_rnm_ctl_t;

#define BDK_DTX_RNM_CTL BDK_DTX_RNM_CTL_FUNC()
static inline uint64_t BDK_DTX_RNM_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RNM_CTL_FUNC(void)
{
	return 0x000087E0FE200060ull;
}
#define typedef_BDK_DTX_RNM_CTL bdk_dtx_rnm_ctl_t
#define bustype_BDK_DTX_RNM_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RNM_CTL 0
#define arguments_BDK_DTX_RNM_CTL -1,-1,-1,-1
#define basename_BDK_DTX_RNM_CTL "DTX_RNM_CTL"


/**
 * RSL - dtx_rnm_dat#
 */
typedef union bdk_dtx_rnm_datx {
	uint64_t u;
	struct bdk_dtx_rnm_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_rnm_datx_s          cn85xx; */
	/* struct bdk_dtx_rnm_datx_s          cn88xx; */
} bdk_dtx_rnm_datx_t;

static inline uint64_t BDK_DTX_RNM_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RNM_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE200040ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_RNM_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_RNM_DATX(...) bdk_dtx_rnm_datx_t
#define bustype_BDK_DTX_RNM_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RNM_DATX(p1) (p1)
#define arguments_BDK_DTX_RNM_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_RNM_DATX(...) "DTX_RNM_DATX"


/**
 * RSL - dtx_rnm_ena#
 */
typedef union bdk_dtx_rnm_enax {
	uint64_t u;
	struct bdk_dtx_rnm_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_rnm_enax_s          cn85xx; */
	/* struct bdk_dtx_rnm_enax_s          cn88xx; */
} bdk_dtx_rnm_enax_t;

static inline uint64_t BDK_DTX_RNM_ENAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RNM_ENAX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE200020ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_RNM_ENAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_RNM_ENAX(...) bdk_dtx_rnm_enax_t
#define bustype_BDK_DTX_RNM_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RNM_ENAX(p1) (p1)
#define arguments_BDK_DTX_RNM_ENAX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_RNM_ENAX(...) "DTX_RNM_ENAX"


/**
 * RSL - dtx_rnm_sel#
 */
typedef union bdk_dtx_rnm_selx {
	uint64_t u;
	struct bdk_dtx_rnm_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_rnm_selx_s          cn85xx; */
	/* struct bdk_dtx_rnm_selx_s          cn88xx; */
} bdk_dtx_rnm_selx_t;

static inline uint64_t BDK_DTX_RNM_SELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RNM_SELX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE200000ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_RNM_SELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_RNM_SELX(...) bdk_dtx_rnm_selx_t
#define bustype_BDK_DTX_RNM_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RNM_SELX(p1) (p1)
#define arguments_BDK_DTX_RNM_SELX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_RNM_SELX(...) "DTX_RNM_SELX"


/**
 * RSL - dtx_rst_bcst_rsp
 */
typedef union bdk_dtx_rst_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_rst_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_rst_bcst_rsp_s      cn85xx; */
	/* struct bdk_dtx_rst_bcst_rsp_s      cn88xx; */
} bdk_dtx_rst_bcst_rsp_t;

#define BDK_DTX_RST_BCST_RSP BDK_DTX_RST_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_RST_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RST_BCST_RSP_FUNC(void)
{
	return 0x000087E0FE030080ull;
}
#define typedef_BDK_DTX_RST_BCST_RSP bdk_dtx_rst_bcst_rsp_t
#define bustype_BDK_DTX_RST_BCST_RSP BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RST_BCST_RSP 0
#define arguments_BDK_DTX_RST_BCST_RSP -1,-1,-1,-1
#define basename_BDK_DTX_RST_BCST_RSP "DTX_RST_BCST_RSP"


/**
 * RSL - dtx_rst_ctl
 */
typedef union bdk_dtx_rst_ctl {
	uint64_t u;
	struct bdk_dtx_rst_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_rst_ctl_s           cn85xx; */
	/* struct bdk_dtx_rst_ctl_s           cn88xx; */
} bdk_dtx_rst_ctl_t;

#define BDK_DTX_RST_CTL BDK_DTX_RST_CTL_FUNC()
static inline uint64_t BDK_DTX_RST_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RST_CTL_FUNC(void)
{
	return 0x000087E0FE030060ull;
}
#define typedef_BDK_DTX_RST_CTL bdk_dtx_rst_ctl_t
#define bustype_BDK_DTX_RST_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RST_CTL 0
#define arguments_BDK_DTX_RST_CTL -1,-1,-1,-1
#define basename_BDK_DTX_RST_CTL "DTX_RST_CTL"


/**
 * RSL - dtx_rst_dat#
 */
typedef union bdk_dtx_rst_datx {
	uint64_t u;
	struct bdk_dtx_rst_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_rst_datx_s          cn85xx; */
	/* struct bdk_dtx_rst_datx_s          cn88xx; */
} bdk_dtx_rst_datx_t;

static inline uint64_t BDK_DTX_RST_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RST_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE030040ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_RST_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_RST_DATX(...) bdk_dtx_rst_datx_t
#define bustype_BDK_DTX_RST_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RST_DATX(p1) (p1)
#define arguments_BDK_DTX_RST_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_RST_DATX(...) "DTX_RST_DATX"


/**
 * RSL - dtx_rst_ena#
 */
typedef union bdk_dtx_rst_enax {
	uint64_t u;
	struct bdk_dtx_rst_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_rst_enax_s          cn85xx; */
	/* struct bdk_dtx_rst_enax_s          cn88xx; */
} bdk_dtx_rst_enax_t;

static inline uint64_t BDK_DTX_RST_ENAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RST_ENAX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE030020ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_RST_ENAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_RST_ENAX(...) bdk_dtx_rst_enax_t
#define bustype_BDK_DTX_RST_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RST_ENAX(p1) (p1)
#define arguments_BDK_DTX_RST_ENAX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_RST_ENAX(...) "DTX_RST_ENAX"


/**
 * RSL - dtx_rst_sel#
 */
typedef union bdk_dtx_rst_selx {
	uint64_t u;
	struct bdk_dtx_rst_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_rst_selx_s          cn85xx; */
	/* struct bdk_dtx_rst_selx_s          cn88xx; */
} bdk_dtx_rst_selx_t;

static inline uint64_t BDK_DTX_RST_SELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RST_SELX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE030000ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_RST_SELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_RST_SELX(...) bdk_dtx_rst_selx_t
#define bustype_BDK_DTX_RST_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_RST_SELX(p1) (p1)
#define arguments_BDK_DTX_RST_SELX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_RST_SELX(...) "DTX_RST_SELX"


/**
 * RSL - dtx_sata#_bcst_rsp
 */
typedef union bdk_dtx_satax_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_satax_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_satax_bcst_rsp_s    cn85xx; */
	/* struct bdk_dtx_satax_bcst_rsp_s    cn88xx; */
} bdk_dtx_satax_bcst_rsp_t;

static inline uint64_t BDK_DTX_SATAX_BCST_RSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SATAX_BCST_RSP(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x000087E0FE880080ull + (param1 & 15) * 0x8000ull;
	csr_fatal("BDK_DTX_SATAX_BCST_RSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_SATAX_BCST_RSP(...) bdk_dtx_satax_bcst_rsp_t
#define bustype_BDK_DTX_SATAX_BCST_RSP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_SATAX_BCST_RSP(p1) (p1)
#define arguments_BDK_DTX_SATAX_BCST_RSP(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_SATAX_BCST_RSP(...) "DTX_SATAX_BCST_RSP"


/**
 * RSL - dtx_sata#_ctl
 */
typedef union bdk_dtx_satax_ctl {
	uint64_t u;
	struct bdk_dtx_satax_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_satax_ctl_s         cn85xx; */
	/* struct bdk_dtx_satax_ctl_s         cn88xx; */
} bdk_dtx_satax_ctl_t;

static inline uint64_t BDK_DTX_SATAX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SATAX_CTL(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x000087E0FE880060ull + (param1 & 15) * 0x8000ull;
	csr_fatal("BDK_DTX_SATAX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_SATAX_CTL(...) bdk_dtx_satax_ctl_t
#define bustype_BDK_DTX_SATAX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_SATAX_CTL(p1) (p1)
#define arguments_BDK_DTX_SATAX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_SATAX_CTL(...) "DTX_SATAX_CTL"


/**
 * RSL - dtx_sata#_dat#
 */
typedef union bdk_dtx_satax_datx {
	uint64_t u;
	struct bdk_dtx_satax_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_satax_datx_s        cn85xx; */
	/* struct bdk_dtx_satax_datx_s        cn88xx; */
} bdk_dtx_satax_datx_t;

static inline uint64_t BDK_DTX_SATAX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SATAX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 15)) && ((param2 <= 1)))
		return 0x000087E0FE880040ull + (param1 & 15) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_SATAX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_SATAX_DATX(...) bdk_dtx_satax_datx_t
#define bustype_BDK_DTX_SATAX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_SATAX_DATX(p1,p2) (p1)
#define arguments_BDK_DTX_SATAX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_SATAX_DATX(...) "DTX_SATAX_DATX"


/**
 * RSL - dtx_sata#_ena#
 */
typedef union bdk_dtx_satax_enax {
	uint64_t u;
	struct bdk_dtx_satax_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_satax_enax_s        cn85xx; */
	/* struct bdk_dtx_satax_enax_s        cn88xx; */
} bdk_dtx_satax_enax_t;

static inline uint64_t BDK_DTX_SATAX_ENAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SATAX_ENAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 15)) && ((param2 <= 1)))
		return 0x000087E0FE880020ull + (param1 & 15) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_SATAX_ENAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_SATAX_ENAX(...) bdk_dtx_satax_enax_t
#define bustype_BDK_DTX_SATAX_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_SATAX_ENAX(p1,p2) (p1)
#define arguments_BDK_DTX_SATAX_ENAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_SATAX_ENAX(...) "DTX_SATAX_ENAX"


/**
 * RSL - dtx_sata#_sel#
 */
typedef union bdk_dtx_satax_selx {
	uint64_t u;
	struct bdk_dtx_satax_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_satax_selx_s        cn85xx; */
	/* struct bdk_dtx_satax_selx_s        cn88xx; */
} bdk_dtx_satax_selx_t;

static inline uint64_t BDK_DTX_SATAX_SELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SATAX_SELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 15)) && ((param2 <= 1)))
		return 0x000087E0FE880000ull + (param1 & 15) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_SATAX_SELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_SATAX_SELX(...) bdk_dtx_satax_selx_t
#define bustype_BDK_DTX_SATAX_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_SATAX_SELX(p1,p2) (p1)
#define arguments_BDK_DTX_SATAX_SELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_SATAX_SELX(...) "DTX_SATAX_SELX"


/**
 * RSL - dtx_sli#_bcst_rsp
 */
typedef union bdk_dtx_slix_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_slix_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_slix_bcst_rsp_s     cn85xx; */
	/* struct bdk_dtx_slix_bcst_rsp_s     cn88xx; */
} bdk_dtx_slix_bcst_rsp_t;

static inline uint64_t BDK_DTX_SLIX_BCST_RSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SLIX_BCST_RSP(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FEBA0080ull + (param1 & 1) * 0x8000ull;
	csr_fatal("BDK_DTX_SLIX_BCST_RSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_SLIX_BCST_RSP(...) bdk_dtx_slix_bcst_rsp_t
#define bustype_BDK_DTX_SLIX_BCST_RSP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_SLIX_BCST_RSP(p1) (p1)
#define arguments_BDK_DTX_SLIX_BCST_RSP(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_SLIX_BCST_RSP(...) "DTX_SLIX_BCST_RSP"


/**
 * RSL - dtx_sli#_ctl
 */
typedef union bdk_dtx_slix_ctl {
	uint64_t u;
	struct bdk_dtx_slix_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_slix_ctl_s          cn85xx; */
	/* struct bdk_dtx_slix_ctl_s          cn88xx; */
} bdk_dtx_slix_ctl_t;

static inline uint64_t BDK_DTX_SLIX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SLIX_CTL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FEBA0060ull + (param1 & 1) * 0x8000ull;
	csr_fatal("BDK_DTX_SLIX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_SLIX_CTL(...) bdk_dtx_slix_ctl_t
#define bustype_BDK_DTX_SLIX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_SLIX_CTL(p1) (p1)
#define arguments_BDK_DTX_SLIX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_SLIX_CTL(...) "DTX_SLIX_CTL"


/**
 * RSL - dtx_sli#_dat#
 */
typedef union bdk_dtx_slix_datx {
	uint64_t u;
	struct bdk_dtx_slix_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_slix_datx_s         cn85xx; */
	/* struct bdk_dtx_slix_datx_s         cn88xx; */
} bdk_dtx_slix_datx_t;

static inline uint64_t BDK_DTX_SLIX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SLIX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FEBA0040ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_SLIX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_SLIX_DATX(...) bdk_dtx_slix_datx_t
#define bustype_BDK_DTX_SLIX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_SLIX_DATX(p1,p2) (p1)
#define arguments_BDK_DTX_SLIX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_SLIX_DATX(...) "DTX_SLIX_DATX"


/**
 * RSL - dtx_sli#_ena#
 */
typedef union bdk_dtx_slix_enax {
	uint64_t u;
	struct bdk_dtx_slix_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_slix_enax_s         cn85xx; */
	/* struct bdk_dtx_slix_enax_s         cn88xx; */
} bdk_dtx_slix_enax_t;

static inline uint64_t BDK_DTX_SLIX_ENAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SLIX_ENAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FEBA0020ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_SLIX_ENAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_SLIX_ENAX(...) bdk_dtx_slix_enax_t
#define bustype_BDK_DTX_SLIX_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_SLIX_ENAX(p1,p2) (p1)
#define arguments_BDK_DTX_SLIX_ENAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_SLIX_ENAX(...) "DTX_SLIX_ENAX"


/**
 * RSL - dtx_sli#_sel#
 */
typedef union bdk_dtx_slix_selx {
	uint64_t u;
	struct bdk_dtx_slix_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_slix_selx_s         cn85xx; */
	/* struct bdk_dtx_slix_selx_s         cn88xx; */
} bdk_dtx_slix_selx_t;

static inline uint64_t BDK_DTX_SLIX_SELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SLIX_SELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FEBA0000ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_SLIX_SELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_SLIX_SELX(...) bdk_dtx_slix_selx_t
#define bustype_BDK_DTX_SLIX_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_SLIX_SELX(p1,p2) (p1)
#define arguments_BDK_DTX_SLIX_SELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_SLIX_SELX(...) "DTX_SLIX_SELX"


/**
 * RSL - dtx_uaa#_bcst_rsp
 */
typedef union bdk_dtx_uaax_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_uaax_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_uaax_bcst_rsp_s     cn85xx; */
	/* struct bdk_dtx_uaax_bcst_rsp_s     cn88xx; */
} bdk_dtx_uaax_bcst_rsp_t;

static inline uint64_t BDK_DTX_UAAX_BCST_RSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_UAAX_BCST_RSP(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE120080ull + (param1 & 1) * 0x8000ull;
	csr_fatal("BDK_DTX_UAAX_BCST_RSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_UAAX_BCST_RSP(...) bdk_dtx_uaax_bcst_rsp_t
#define bustype_BDK_DTX_UAAX_BCST_RSP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_UAAX_BCST_RSP(p1) (p1)
#define arguments_BDK_DTX_UAAX_BCST_RSP(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_UAAX_BCST_RSP(...) "DTX_UAAX_BCST_RSP"


/**
 * RSL - dtx_uaa#_ctl
 */
typedef union bdk_dtx_uaax_ctl {
	uint64_t u;
	struct bdk_dtx_uaax_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_uaax_ctl_s          cn85xx; */
	/* struct bdk_dtx_uaax_ctl_s          cn88xx; */
} bdk_dtx_uaax_ctl_t;

static inline uint64_t BDK_DTX_UAAX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_UAAX_CTL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE120060ull + (param1 & 1) * 0x8000ull;
	csr_fatal("BDK_DTX_UAAX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_UAAX_CTL(...) bdk_dtx_uaax_ctl_t
#define bustype_BDK_DTX_UAAX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_UAAX_CTL(p1) (p1)
#define arguments_BDK_DTX_UAAX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_UAAX_CTL(...) "DTX_UAAX_CTL"


/**
 * RSL - dtx_uaa#_dat#
 */
typedef union bdk_dtx_uaax_datx {
	uint64_t u;
	struct bdk_dtx_uaax_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_uaax_datx_s         cn85xx; */
	/* struct bdk_dtx_uaax_datx_s         cn88xx; */
} bdk_dtx_uaax_datx_t;

static inline uint64_t BDK_DTX_UAAX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_UAAX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FE120040ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_UAAX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_UAAX_DATX(...) bdk_dtx_uaax_datx_t
#define bustype_BDK_DTX_UAAX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_UAAX_DATX(p1,p2) (p1)
#define arguments_BDK_DTX_UAAX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_UAAX_DATX(...) "DTX_UAAX_DATX"


/**
 * RSL - dtx_uaa#_ena#
 */
typedef union bdk_dtx_uaax_enax {
	uint64_t u;
	struct bdk_dtx_uaax_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_uaax_enax_s         cn85xx; */
	/* struct bdk_dtx_uaax_enax_s         cn88xx; */
} bdk_dtx_uaax_enax_t;

static inline uint64_t BDK_DTX_UAAX_ENAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_UAAX_ENAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FE120020ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_UAAX_ENAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_UAAX_ENAX(...) bdk_dtx_uaax_enax_t
#define bustype_BDK_DTX_UAAX_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_UAAX_ENAX(p1,p2) (p1)
#define arguments_BDK_DTX_UAAX_ENAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_UAAX_ENAX(...) "DTX_UAAX_ENAX"


/**
 * RSL - dtx_uaa#_sel#
 */
typedef union bdk_dtx_uaax_selx {
	uint64_t u;
	struct bdk_dtx_uaax_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_uaax_selx_s         cn85xx; */
	/* struct bdk_dtx_uaax_selx_s         cn88xx; */
} bdk_dtx_uaax_selx_t;

static inline uint64_t BDK_DTX_UAAX_SELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_UAAX_SELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FE120000ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_UAAX_SELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_UAAX_SELX(...) bdk_dtx_uaax_selx_t
#define bustype_BDK_DTX_UAAX_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_UAAX_SELX(p1,p2) (p1)
#define arguments_BDK_DTX_UAAX_SELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_UAAX_SELX(...) "DTX_UAAX_SELX"


/**
 * RSL - dtx_usbh#_bcst_rsp
 */
typedef union bdk_dtx_usbhx_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_usbhx_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_usbhx_bcst_rsp_s    cn85xx; */
	/* struct bdk_dtx_usbhx_bcst_rsp_s    cn88xx; */
} bdk_dtx_usbhx_bcst_rsp_t;

static inline uint64_t BDK_DTX_USBHX_BCST_RSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_USBHX_BCST_RSP(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FEB40080ull + (param1 & 1) * 0x8000ull;
	csr_fatal("BDK_DTX_USBHX_BCST_RSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_USBHX_BCST_RSP(...) bdk_dtx_usbhx_bcst_rsp_t
#define bustype_BDK_DTX_USBHX_BCST_RSP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_USBHX_BCST_RSP(p1) (p1)
#define arguments_BDK_DTX_USBHX_BCST_RSP(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_USBHX_BCST_RSP(...) "DTX_USBHX_BCST_RSP"


/**
 * RSL - dtx_usbh#_ctl
 */
typedef union bdk_dtx_usbhx_ctl {
	uint64_t u;
	struct bdk_dtx_usbhx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_usbhx_ctl_s         cn85xx; */
	/* struct bdk_dtx_usbhx_ctl_s         cn88xx; */
} bdk_dtx_usbhx_ctl_t;

static inline uint64_t BDK_DTX_USBHX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_USBHX_CTL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FEB40060ull + (param1 & 1) * 0x8000ull;
	csr_fatal("BDK_DTX_USBHX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_USBHX_CTL(...) bdk_dtx_usbhx_ctl_t
#define bustype_BDK_DTX_USBHX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_USBHX_CTL(p1) (p1)
#define arguments_BDK_DTX_USBHX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_USBHX_CTL(...) "DTX_USBHX_CTL"


/**
 * RSL - dtx_usbh#_dat#
 */
typedef union bdk_dtx_usbhx_datx {
	uint64_t u;
	struct bdk_dtx_usbhx_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_usbhx_datx_s        cn85xx; */
	/* struct bdk_dtx_usbhx_datx_s        cn88xx; */
} bdk_dtx_usbhx_datx_t;

static inline uint64_t BDK_DTX_USBHX_DATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_USBHX_DATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FEB40040ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_USBHX_DATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_USBHX_DATX(...) bdk_dtx_usbhx_datx_t
#define bustype_BDK_DTX_USBHX_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_USBHX_DATX(p1,p2) (p1)
#define arguments_BDK_DTX_USBHX_DATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_USBHX_DATX(...) "DTX_USBHX_DATX"


/**
 * RSL - dtx_usbh#_ena#
 */
typedef union bdk_dtx_usbhx_enax {
	uint64_t u;
	struct bdk_dtx_usbhx_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_usbhx_enax_s        cn85xx; */
	/* struct bdk_dtx_usbhx_enax_s        cn88xx; */
} bdk_dtx_usbhx_enax_t;

static inline uint64_t BDK_DTX_USBHX_ENAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_USBHX_ENAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FEB40020ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_USBHX_ENAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_USBHX_ENAX(...) bdk_dtx_usbhx_enax_t
#define bustype_BDK_DTX_USBHX_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_USBHX_ENAX(p1,p2) (p1)
#define arguments_BDK_DTX_USBHX_ENAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_USBHX_ENAX(...) "DTX_USBHX_ENAX"


/**
 * RSL - dtx_usbh#_sel#
 */
typedef union bdk_dtx_usbhx_selx {
	uint64_t u;
	struct bdk_dtx_usbhx_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_usbhx_selx_s        cn85xx; */
	/* struct bdk_dtx_usbhx_selx_s        cn88xx; */
} bdk_dtx_usbhx_selx_t;

static inline uint64_t BDK_DTX_USBHX_SELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_USBHX_SELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0FEB40000ull + (param1 & 1) * 0x8000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_USBHX_SELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DTX_USBHX_SELX(...) bdk_dtx_usbhx_selx_t
#define bustype_BDK_DTX_USBHX_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_USBHX_SELX(p1,p2) (p1)
#define arguments_BDK_DTX_USBHX_SELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DTX_USBHX_SELX(...) "DTX_USBHX_SELX"


/**
 * RSL - dtx_zip_bcst_rsp
 */
typedef union bdk_dtx_zip_bcst_rsp {
	uint64_t u;
	struct bdk_dtx_zip_bcst_rsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t ena                         : 1;  /**< R/W - Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else
		uint64_t ena                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_dtx_zip_bcst_rsp_s      cn85xx; */
	/* struct bdk_dtx_zip_bcst_rsp_s      cn88xx; */
} bdk_dtx_zip_bcst_rsp_t;

#define BDK_DTX_ZIP_BCST_RSP BDK_DTX_ZIP_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_ZIP_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_ZIP_BCST_RSP_FUNC(void)
{
	return 0x000087E0FE9C0080ull;
}
#define typedef_BDK_DTX_ZIP_BCST_RSP bdk_dtx_zip_bcst_rsp_t
#define bustype_BDK_DTX_ZIP_BCST_RSP BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_ZIP_BCST_RSP 0
#define arguments_BDK_DTX_ZIP_BCST_RSP -1,-1,-1,-1
#define basename_BDK_DTX_ZIP_BCST_RSP "DTX_ZIP_BCST_RSP"


/**
 * RSL - dtx_zip_ctl
 */
typedef union bdk_dtx_zip_ctl {
	uint64_t u;
	struct bdk_dtx_zip_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t active                      : 1;  /**< R/W - Force block's gated clocks on, so that the state of idle signals may be captured. */
		uint64_t reserved_2_3                : 2;
		uint64_t echoen                      : 1;  /**< R/W - Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
		uint64_t swap                        : 1;  /**< R/W - Swap the high and low 36-bit debug bus outputs. */
#else
		uint64_t swap                        : 1;
		uint64_t echoen                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t active                      : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_dtx_zip_ctl_s           cn85xx; */
	/* struct bdk_dtx_zip_ctl_s           cn88xx; */
} bdk_dtx_zip_ctl_t;

#define BDK_DTX_ZIP_CTL BDK_DTX_ZIP_CTL_FUNC()
static inline uint64_t BDK_DTX_ZIP_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_ZIP_CTL_FUNC(void)
{
	return 0x000087E0FE9C0060ull;
}
#define typedef_BDK_DTX_ZIP_CTL bdk_dtx_zip_ctl_t
#define bustype_BDK_DTX_ZIP_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_ZIP_CTL 0
#define arguments_BDK_DTX_ZIP_CTL -1,-1,-1,-1
#define basename_BDK_DTX_ZIP_CTL "DTX_ZIP_CTL"


/**
 * RSL - dtx_zip_dat#
 */
typedef union bdk_dtx_zip_datx {
	uint64_t u;
	struct bdk_dtx_zip_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t raw                         : 36; /**< RO/H - Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else
		uint64_t raw                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_zip_datx_s          cn85xx; */
	/* struct bdk_dtx_zip_datx_s          cn88xx; */
} bdk_dtx_zip_datx_t;

static inline uint64_t BDK_DTX_ZIP_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_ZIP_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE9C0040ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_ZIP_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_ZIP_DATX(...) bdk_dtx_zip_datx_t
#define bustype_BDK_DTX_ZIP_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_ZIP_DATX(p1) (p1)
#define arguments_BDK_DTX_ZIP_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_ZIP_DATX(...) "DTX_ZIP_DATX"


/**
 * RSL - dtx_zip_ena#
 */
typedef union bdk_dtx_zip_enax {
	uint64_t u;
	struct bdk_dtx_zip_enax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t ena                         : 36; /**< R/W - Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else
		uint64_t ena                         : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_dtx_zip_enax_s          cn85xx; */
	/* struct bdk_dtx_zip_enax_s          cn88xx; */
} bdk_dtx_zip_enax_t;

static inline uint64_t BDK_DTX_ZIP_ENAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_ZIP_ENAX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE9C0020ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_ZIP_ENAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_ZIP_ENAX(...) bdk_dtx_zip_enax_t
#define bustype_BDK_DTX_ZIP_ENAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_ZIP_ENAX(p1) (p1)
#define arguments_BDK_DTX_ZIP_ENAX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_ZIP_ENAX(...) "DTX_ZIP_ENAX"


/**
 * RSL - dtx_zip_sel#
 */
typedef union bdk_dtx_zip_selx {
	uint64_t u;
	struct bdk_dtx_zip_selx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t value                       : 24; /**< R/W - Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else
		uint64_t value                       : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_dtx_zip_selx_s          cn85xx; */
	/* struct bdk_dtx_zip_selx_s          cn88xx; */
} bdk_dtx_zip_selx_t;

static inline uint64_t BDK_DTX_ZIP_SELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_ZIP_SELX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0FE9C0000ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_DTX_ZIP_SELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DTX_ZIP_SELX(...) bdk_dtx_zip_selx_t
#define bustype_BDK_DTX_ZIP_SELX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_DTX_ZIP_SELX(p1) (p1)
#define arguments_BDK_DTX_ZIP_SELX(p1) (p1),-1,-1,-1
#define basename_BDK_DTX_ZIP_SELX(...) "DTX_ZIP_SELX"

#endif /* __BDK_CSRS_DTX__ */
