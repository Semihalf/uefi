#ifndef __BDK_CSRS_L2C_TAD__
#define __BDK_CSRS_L2C_TAD__
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
 * Cavium L2C_TAD.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration L2C_TAD_INT_VEC_E
 *
 * L2C_TAD MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum l2c_tad_int_vec_e {
	L2C_TAD_INT_VEC_E_INTS = 0x0,
	L2C_TAD_INT_VEC_E_ENUM_LAST = 0x1,
};



/**
 * RSL - l2c_tad#_dll
 *
 * This register provides the parameters for DLL observability.
 *
 */
typedef union bdk_l2c_tadx_dll {
	uint64_t u;
	struct bdk_l2c_tadx_dll_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t max_dll_setting             : 12; /**< RO/H - Max reported DLL setting. */
		uint64_t min_dll_setting             : 12; /**< RO/H - Min reported DLL setting. */
		uint64_t pd_pos_rclk_refclk          : 1;  /**< RO/H - Phase detector output. */
		uint64_t pdl_rclk_refclk             : 1;  /**< RO/H - Phase detector output. */
		uint64_t pdr_rclk_refclk             : 1;  /**< RO/H - Phase detector output. */
		uint64_t reserved_32_32              : 1;
		uint64_t dly_elem_enable             : 16; /**< RO/H - Delay element enable. */
		uint64_t dll_setting                 : 12; /**< RO/H - DLL setting. */
		uint64_t reserved_1_3                : 3;
		uint64_t dll_lock                    : 1;  /**< RO/H - DLL lock: 1 = locked, 0 = unlocked. */
#else
		uint64_t dll_lock                    : 1;
		uint64_t reserved_1_3                : 3;
		uint64_t dll_setting                 : 12;
		uint64_t dly_elem_enable             : 16;
		uint64_t reserved_32_32              : 1;
		uint64_t pdr_rclk_refclk             : 1;
		uint64_t pdl_rclk_refclk             : 1;
		uint64_t pd_pos_rclk_refclk          : 1;
		uint64_t min_dll_setting             : 12;
		uint64_t max_dll_setting             : 12;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_l2c_tadx_dll_s          cn85xx; */
	/* struct bdk_l2c_tadx_dll_s          cn88xx; */
	/* struct bdk_l2c_tadx_dll_s          cn88xxp1; */
} bdk_l2c_tadx_dll_t;

static inline uint64_t BDK_L2C_TADX_DLL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_DLL(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050030000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_DLL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_DLL(...) bdk_l2c_tadx_dll_t
#define bustype_BDK_L2C_TADX_DLL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_DLL(p1) (p1)
#define arguments_BDK_L2C_TADX_DLL(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_DLL(...) "L2C_TADX_DLL"


/**
 * RSL - l2c_tad#_err
 *
 * This register records error information for *DISOCI and *NXM
 * interrupts. The NXM logic only applies to local addresses. A command for
 * a remote address does not cause a RDNXM/WRNXM on the requesting node, but
 * may on the remote node. Similary RDDISOCI/WRDISOCI is always for a remote
 * address. The first WRDISOCI/WRNXM error will lock the register until the
 * logged error type is cleared; RDDISOCI/RDNXM never locks the register.
 */
typedef union bdk_l2c_tadx_err {
	uint64_t u;
	struct bdk_l2c_tadx_err_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rdnxm                       : 1;  /**< RO/H - Logged information is for a RDNXM error. */
		uint64_t wrnxm                       : 1;  /**< RO/H - Logged information is for a WRNXM error. */
		uint64_t rddisoci                    : 1;  /**< RO/H - Logged information is for a RDDISOCI error. */
		uint64_t wrdisoci                    : 1;  /**< RO/H - Logged information is for a WRDISOCI error. */
		uint64_t nonsec                      : 1;  /**< RO/H - Non-secure (NS) bit of request causing error. */
		uint64_t cmd                         : 8;  /**< RO/H - Encoding of XMC or CCPI command causing error. INTERNAL: If CMD[7]==1, use XMC_CMD_E to
                                                                 decode CMD[6:0]. If CMD[7:5]==0, use OCI_MREQ_CMD_E to decode CMD[4:0]. If CMD[7:5]==1,
                                                                 use OCI_MFWD_CMD_E to decode CMD[4:0]. If CMD[7:5]==2, use OCI_MRSP_CMD_E to decode
                                                                 CMD[4:0]. */
		uint64_t source                      : 7;  /**< RO/H - XMC source of request causing error. If SOURCE\<6\>==0, then SOURCE\<5:0\> is PPID, else
                                                                 SOURCE\<3:0\> is BUSID of the IOB which made the request. If CMD[7]==0, this field is
                                                                 unpredictable. */
		uint64_t reserved_42_43              : 2;
		uint64_t node                        : 2;  /**< RO/H - CCPI node of XMC request causing error. For *NXM errors NODE is always the node that
                                                                 generated request causing the error (*NXM errors are logged at the home node). For *DISOCI
                                                                 errors, is the NODE the request is directed to (DISOCI request is always the current
                                                                 node). */
		uint64_t addr                        : 40; /**< RO/H - XMC address causing the error. This field is the physical address after
                                                                 index aliasing (if enabled). */
#else
		uint64_t addr                        : 40;
		uint64_t node                        : 2;
		uint64_t reserved_42_43              : 2;
		uint64_t source                      : 7;
		uint64_t cmd                         : 8;
		uint64_t nonsec                      : 1;
		uint64_t wrdisoci                    : 1;
		uint64_t rddisoci                    : 1;
		uint64_t wrnxm                       : 1;
		uint64_t rdnxm                       : 1;
#endif
	} s;
	/* struct bdk_l2c_tadx_err_s          cn85xx; */
	/* struct bdk_l2c_tadx_err_s          cn88xx; */
	/* struct bdk_l2c_tadx_err_s          cn88xxp1; */
} bdk_l2c_tadx_err_t;

static inline uint64_t BDK_L2C_TADX_ERR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_ERR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050060000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_ERR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_ERR(...) bdk_l2c_tadx_err_t
#define bustype_BDK_L2C_TADX_ERR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_ERR(p1) (p1)
#define arguments_BDK_L2C_TADX_ERR(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_ERR(...) "L2C_TADX_ERR"


/**
 * RSL - l2c_tad#_int_ena_w1c
 */
typedef union bdk_l2c_tadx_int_ena_w1c {
	uint64_t u;
	struct bdk_l2c_tadx_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t wrdisoci                    : 1;  /**< R/W1C/H - Illegal write operation to a remote node with L2C_OCI_CTL[ENAOCI][node] clear. See
                                                                 L2C_TAD()_ERR for for logged information. */
		uint64_t rddisoci                    : 1;  /**< R/W1C/H - Illegal read operation to a remote node with L2C_OCI_CTL[ENAOCI][node] clear. Note
                                                                 RDDISOCI interrupts can occur during normal operation as the cores are allowed to prefetch
                                                                 to nonexistent memory locations. Therefore, RDDISOCI is for informational purposes only.
                                                                 See L2C_TAD()_ERR for logged information. */
		uint64_t rtgdbe                      : 1;  /**< R/W1C/H - RTG double-bit error. */
		uint64_t rtgsbe                      : 1;  /**< R/W1C/H - RTG single-bit error. */
		uint64_t reserved_18_31              : 14;
		uint64_t lfbto                       : 1;  /**< R/W1C/H - An LFB entry (or more) has encountered a timeout condition When LFBTO timeout condition
                                                                 occurs L2C_TAD()_TIMEOUT is loaded. L2C_TAD()_TIMEOUT is loaded with info from the
                                                                 first LFB that timed out. if multiple LFB timed out simultaneously, then the it will
                                                                 capture info from the lowest LFB number that timed out. */
		uint64_t wrdislmc                    : 1;  /**< R/W1C/H - Illegal write to disabled LMC error. A DRAM write arrived before LMC was enabled. */
		uint64_t rddislmc                    : 1;  /**< R/W1C/H - Illegal read to disabled LMC error. A DRAM read arrived before LMC was enabled. */
		uint64_t rdnxm                       : 1;  /**< R/W1C/H - Read reference outside all the defined and enabled Address Space
                                                                 Control (ASC) regions, or secure read reference to an ASC region
                                                                 not enabled for secure access, or non-secure read reference to an ASC
                                                                 region not enabled for non-secure access.
                                                                 RDNXM interrupts can occur during normal operation as the cores are
                                                                 allowed to prefetch to nonexistent memory locations.  Therefore,
                                                                 RDNXM is for informational purposes only.
                                                                 See L2C_TAD()_ERR for logged information.
                                                                 See L2C_ASC_REGION()_START, L2C_ASC_REGION()_END, and
                                                                 L2C_ASC_REGION()_ATTR for ASC region specification. */
		uint64_t wrnxm                       : 1;  /**< R/W1C/H - Write reference outside all the defined and enabled Address Space
                                                                 Control (ASC) regions, or secure write reference to an ASC region
                                                                 not enabled for secure access, or non-secure write reference to an
                                                                 ASC region not enabled for non-secure access.
                                                                 See L2C_TAD()_ERR for logged information.
                                                                 See L2C_ASC_REGION()_START, L2C_ASC_REGION()_END, and
                                                                 L2C_ASC_REGION()_ATTR for ASC region specification. */
		uint64_t reserved_11_12              : 2;
		uint64_t noway                       : 1;  /**< R/W1C/H - No way was available for allocation. L2C sets NOWAY during its processing of a transaction
                                                                 whenever it needed/wanted to allocate a WAY in the L2 cache, but was unable to. When this
                                                                 bit = 1, it is (generally) not an indication that L2C failed to complete transactions.
                                                                 Rather, it is a hint of possible performance degradation. (For example, L2C must read-
                                                                 modify-write DRAM for every transaction that updates some, but not all, of the bytes in a
                                                                 cache block, misses in the L2 cache, and cannot allocate a WAY.) There is one 'failure'
                                                                 case where L2C sets NOWAY: when it cannot leave a block locked in the L2 cache as part of
                                                                 a LCKL2 transaction. See L2C_TTG()_ERR for logged information. */
		uint64_t tagdbe                      : 1;  /**< R/W1C/H - TAG double-bit error occurred. See L2C_TTG()_ERR for logged information. */
		uint64_t tagsbe                      : 1;  /**< R/W1C/H - TAG single-bit error occurred. See L2C_TTG()_ERR for logged information. */
		uint64_t reserved_6_7                : 2;
		uint64_t fbfdbe                      : 1;  /**< R/W1C/H - FBF double-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t fbfsbe                      : 1;  /**< R/W1C/H - FBF single-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t sbfdbe                      : 1;  /**< R/W1C/H - SBF double-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t sbfsbe                      : 1;  /**< R/W1C/H - SBF single-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t l2ddbe                      : 1;  /**< R/W1C/H - L2D double-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t l2dsbe                      : 1;  /**< R/W1C/H - L2D single-bit error occurred. See L2C_TQD()_ERR for logged information. */
#else
		uint64_t l2dsbe                      : 1;
		uint64_t l2ddbe                      : 1;
		uint64_t sbfsbe                      : 1;
		uint64_t sbfdbe                      : 1;
		uint64_t fbfsbe                      : 1;
		uint64_t fbfdbe                      : 1;
		uint64_t reserved_6_7                : 2;
		uint64_t tagsbe                      : 1;
		uint64_t tagdbe                      : 1;
		uint64_t noway                       : 1;
		uint64_t reserved_11_12              : 2;
		uint64_t wrnxm                       : 1;
		uint64_t rdnxm                       : 1;
		uint64_t rddislmc                    : 1;
		uint64_t wrdislmc                    : 1;
		uint64_t lfbto                       : 1;
		uint64_t reserved_18_31              : 14;
		uint64_t rtgsbe                      : 1;
		uint64_t rtgdbe                      : 1;
		uint64_t rddisoci                    : 1;
		uint64_t wrdisoci                    : 1;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_l2c_tadx_int_ena_w1c_s  cn85xx; */
	/* struct bdk_l2c_tadx_int_ena_w1c_s  cn88xx; */
	/* struct bdk_l2c_tadx_int_ena_w1c_s  cn88xxp1; */
} bdk_l2c_tadx_int_ena_w1c_t;

static inline uint64_t BDK_L2C_TADX_INT_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_INT_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050040020ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_INT_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_INT_ENA_W1C(...) bdk_l2c_tadx_int_ena_w1c_t
#define bustype_BDK_L2C_TADX_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_INT_ENA_W1C(p1) (p1)
#define arguments_BDK_L2C_TADX_INT_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_INT_ENA_W1C(...) "L2C_TADX_INT_ENA_W1C"


/**
 * RSL - l2c_tad#_int_ena_w1s
 */
typedef union bdk_l2c_tadx_int_ena_w1s {
	uint64_t u;
	struct bdk_l2c_tadx_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t wrdisoci                    : 1;  /**< R/W1C/H - Illegal write operation to a remote node with L2C_OCI_CTL[ENAOCI][node] clear. See
                                                                 L2C_TAD()_ERR for for logged information. */
		uint64_t rddisoci                    : 1;  /**< R/W1C/H - Illegal read operation to a remote node with L2C_OCI_CTL[ENAOCI][node] clear. Note
                                                                 RDDISOCI interrupts can occur during normal operation as the cores are allowed to prefetch
                                                                 to nonexistent memory locations. Therefore, RDDISOCI is for informational purposes only.
                                                                 See L2C_TAD()_ERR for logged information. */
		uint64_t rtgdbe                      : 1;  /**< R/W1C/H - RTG double-bit error. */
		uint64_t rtgsbe                      : 1;  /**< R/W1C/H - RTG single-bit error. */
		uint64_t reserved_18_31              : 14;
		uint64_t lfbto                       : 1;  /**< R/W1C/H - An LFB entry (or more) has encountered a timeout condition When LFBTO timeout condition
                                                                 occurs L2C_TAD()_TIMEOUT is loaded. L2C_TAD()_TIMEOUT is loaded with info from the
                                                                 first LFB that timed out. if multiple LFB timed out simultaneously, then the it will
                                                                 capture info from the lowest LFB number that timed out. */
		uint64_t wrdislmc                    : 1;  /**< R/W1C/H - Illegal write to disabled LMC error. A DRAM write arrived before LMC was enabled. */
		uint64_t rddislmc                    : 1;  /**< R/W1C/H - Illegal read to disabled LMC error. A DRAM read arrived before LMC was enabled. */
		uint64_t rdnxm                       : 1;  /**< R/W1C/H - Read reference outside all the defined and enabled Address Space
                                                                 Control (ASC) regions, or secure read reference to an ASC region
                                                                 not enabled for secure access, or non-secure read reference to an ASC
                                                                 region not enabled for non-secure access.
                                                                 RDNXM interrupts can occur during normal operation as the cores are
                                                                 allowed to prefetch to nonexistent memory locations.  Therefore,
                                                                 RDNXM is for informational purposes only.
                                                                 See L2C_TAD()_ERR for logged information.
                                                                 See L2C_ASC_REGION()_START, L2C_ASC_REGION()_END, and
                                                                 L2C_ASC_REGION()_ATTR for ASC region specification. */
		uint64_t wrnxm                       : 1;  /**< R/W1C/H - Write reference outside all the defined and enabled Address Space
                                                                 Control (ASC) regions, or secure write reference to an ASC region
                                                                 not enabled for secure access, or non-secure write reference to an
                                                                 ASC region not enabled for non-secure access.
                                                                 See L2C_TAD()_ERR for logged information.
                                                                 See L2C_ASC_REGION()_START, L2C_ASC_REGION()_END, and
                                                                 L2C_ASC_REGION()_ATTR for ASC region specification. */
		uint64_t reserved_11_12              : 2;
		uint64_t noway                       : 1;  /**< R/W1C/H - No way was available for allocation. L2C sets NOWAY during its processing of a transaction
                                                                 whenever it needed/wanted to allocate a WAY in the L2 cache, but was unable to. When this
                                                                 bit = 1, it is (generally) not an indication that L2C failed to complete transactions.
                                                                 Rather, it is a hint of possible performance degradation. (For example, L2C must read-
                                                                 modify-write DRAM for every transaction that updates some, but not all, of the bytes in a
                                                                 cache block, misses in the L2 cache, and cannot allocate a WAY.) There is one 'failure'
                                                                 case where L2C sets NOWAY: when it cannot leave a block locked in the L2 cache as part of
                                                                 a LCKL2 transaction. See L2C_TTG()_ERR for logged information. */
		uint64_t tagdbe                      : 1;  /**< R/W1C/H - TAG double-bit error occurred. See L2C_TTG()_ERR for logged information. */
		uint64_t tagsbe                      : 1;  /**< R/W1C/H - TAG single-bit error occurred. See L2C_TTG()_ERR for logged information. */
		uint64_t reserved_6_7                : 2;
		uint64_t fbfdbe                      : 1;  /**< R/W1C/H - FBF double-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t fbfsbe                      : 1;  /**< R/W1C/H - FBF single-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t sbfdbe                      : 1;  /**< R/W1C/H - SBF double-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t sbfsbe                      : 1;  /**< R/W1C/H - SBF single-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t l2ddbe                      : 1;  /**< R/W1C/H - L2D double-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t l2dsbe                      : 1;  /**< R/W1C/H - L2D single-bit error occurred. See L2C_TQD()_ERR for logged information. */
#else
		uint64_t l2dsbe                      : 1;
		uint64_t l2ddbe                      : 1;
		uint64_t sbfsbe                      : 1;
		uint64_t sbfdbe                      : 1;
		uint64_t fbfsbe                      : 1;
		uint64_t fbfdbe                      : 1;
		uint64_t reserved_6_7                : 2;
		uint64_t tagsbe                      : 1;
		uint64_t tagdbe                      : 1;
		uint64_t noway                       : 1;
		uint64_t reserved_11_12              : 2;
		uint64_t wrnxm                       : 1;
		uint64_t rdnxm                       : 1;
		uint64_t rddislmc                    : 1;
		uint64_t wrdislmc                    : 1;
		uint64_t lfbto                       : 1;
		uint64_t reserved_18_31              : 14;
		uint64_t rtgsbe                      : 1;
		uint64_t rtgdbe                      : 1;
		uint64_t rddisoci                    : 1;
		uint64_t wrdisoci                    : 1;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_l2c_tadx_int_ena_w1s_s  cn85xx; */
	/* struct bdk_l2c_tadx_int_ena_w1s_s  cn88xx; */
	/* struct bdk_l2c_tadx_int_ena_w1s_s  cn88xxp1; */
} bdk_l2c_tadx_int_ena_w1s_t;

static inline uint64_t BDK_L2C_TADX_INT_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_INT_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050040028ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_INT_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_INT_ENA_W1S(...) bdk_l2c_tadx_int_ena_w1s_t
#define bustype_BDK_L2C_TADX_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_INT_ENA_W1S(p1) (p1)
#define arguments_BDK_L2C_TADX_INT_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_INT_ENA_W1S(...) "L2C_TADX_INT_ENA_W1S"


/**
 * RSL - l2c_tad#_int_w1c
 *
 * This register is for TAD-based interrupts.
 *
 */
typedef union bdk_l2c_tadx_int_w1c {
	uint64_t u;
	struct bdk_l2c_tadx_int_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t wrdisoci                    : 1;  /**< R/W1C/H - Illegal write operation to a remote node with L2C_OCI_CTL[ENAOCI][node] clear. See
                                                                 L2C_TAD()_ERR for for logged information. */
		uint64_t rddisoci                    : 1;  /**< R/W1C/H - Illegal read operation to a remote node with L2C_OCI_CTL[ENAOCI][node] clear. Note
                                                                 RDDISOCI interrupts can occur during normal operation as the cores are allowed to prefetch
                                                                 to nonexistent memory locations. Therefore, RDDISOCI is for informational purposes only.
                                                                 See L2C_TAD()_ERR for logged information. */
		uint64_t rtgdbe                      : 1;  /**< R/W1C/H - RTG double-bit error. */
		uint64_t rtgsbe                      : 1;  /**< R/W1C/H - RTG single-bit error. */
		uint64_t reserved_18_31              : 14;
		uint64_t lfbto                       : 1;  /**< R/W1C/H - An LFB entry (or more) has encountered a timeout condition When LFBTO timeout condition
                                                                 occurs L2C_TAD()_TIMEOUT is loaded. L2C_TAD()_TIMEOUT is loaded with info from the
                                                                 first LFB that timed out. if multiple LFB timed out simultaneously, then the it will
                                                                 capture info from the lowest LFB number that timed out. */
		uint64_t wrdislmc                    : 1;  /**< R/W1C/H - Illegal write to disabled LMC error. A DRAM write arrived before LMC was enabled. */
		uint64_t rddislmc                    : 1;  /**< R/W1C/H - Illegal read to disabled LMC error. A DRAM read arrived before LMC was enabled. */
		uint64_t rdnxm                       : 1;  /**< R/W1C/H - Read reference outside all the defined and enabled Address Space
                                                                 Control (ASC) regions, or secure read reference to an ASC region
                                                                 not enabled for secure access, or non-secure read reference to an ASC
                                                                 region not enabled for non-secure access.
                                                                 RDNXM interrupts can occur during normal operation as the cores are
                                                                 allowed to prefetch to nonexistent memory locations.  Therefore,
                                                                 RDNXM is for informational purposes only.
                                                                 See L2C_TAD()_ERR for logged information.
                                                                 See L2C_ASC_REGION()_START, L2C_ASC_REGION()_END, and
                                                                 L2C_ASC_REGION()_ATTR for ASC region specification. */
		uint64_t wrnxm                       : 1;  /**< R/W1C/H - Write reference outside all the defined and enabled Address Space
                                                                 Control (ASC) regions, or secure write reference to an ASC region
                                                                 not enabled for secure access, or non-secure write reference to an
                                                                 ASC region not enabled for non-secure access.
                                                                 See L2C_TAD()_ERR for logged information.
                                                                 See L2C_ASC_REGION()_START, L2C_ASC_REGION()_END, and
                                                                 L2C_ASC_REGION()_ATTR for ASC region specification. */
		uint64_t reserved_11_12              : 2;
		uint64_t noway                       : 1;  /**< R/W1C/H - No way was available for allocation. L2C sets NOWAY during its processing of a transaction
                                                                 whenever it needed/wanted to allocate a WAY in the L2 cache, but was unable to. When this
                                                                 bit = 1, it is (generally) not an indication that L2C failed to complete transactions.
                                                                 Rather, it is a hint of possible performance degradation. (For example, L2C must read-
                                                                 modify-write DRAM for every transaction that updates some, but not all, of the bytes in a
                                                                 cache block, misses in the L2 cache, and cannot allocate a WAY.) There is one 'failure'
                                                                 case where L2C sets NOWAY: when it cannot leave a block locked in the L2 cache as part of
                                                                 a LCKL2 transaction. See L2C_TTG()_ERR for logged information. */
		uint64_t tagdbe                      : 1;  /**< R/W1C/H - TAG double-bit error occurred. See L2C_TTG()_ERR for logged information. */
		uint64_t tagsbe                      : 1;  /**< R/W1C/H - TAG single-bit error occurred. See L2C_TTG()_ERR for logged information. */
		uint64_t reserved_6_7                : 2;
		uint64_t fbfdbe                      : 1;  /**< R/W1C/H - FBF double-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t fbfsbe                      : 1;  /**< R/W1C/H - FBF single-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t sbfdbe                      : 1;  /**< R/W1C/H - SBF double-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t sbfsbe                      : 1;  /**< R/W1C/H - SBF single-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t l2ddbe                      : 1;  /**< R/W1C/H - L2D double-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t l2dsbe                      : 1;  /**< R/W1C/H - L2D single-bit error occurred. See L2C_TQD()_ERR for logged information. */
#else
		uint64_t l2dsbe                      : 1;
		uint64_t l2ddbe                      : 1;
		uint64_t sbfsbe                      : 1;
		uint64_t sbfdbe                      : 1;
		uint64_t fbfsbe                      : 1;
		uint64_t fbfdbe                      : 1;
		uint64_t reserved_6_7                : 2;
		uint64_t tagsbe                      : 1;
		uint64_t tagdbe                      : 1;
		uint64_t noway                       : 1;
		uint64_t reserved_11_12              : 2;
		uint64_t wrnxm                       : 1;
		uint64_t rdnxm                       : 1;
		uint64_t rddislmc                    : 1;
		uint64_t wrdislmc                    : 1;
		uint64_t lfbto                       : 1;
		uint64_t reserved_18_31              : 14;
		uint64_t rtgsbe                      : 1;
		uint64_t rtgdbe                      : 1;
		uint64_t rddisoci                    : 1;
		uint64_t wrdisoci                    : 1;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_l2c_tadx_int_w1c_s      cn85xx; */
	/* struct bdk_l2c_tadx_int_w1c_s      cn88xx; */
	/* struct bdk_l2c_tadx_int_w1c_s      cn88xxp1; */
} bdk_l2c_tadx_int_w1c_t;

static inline uint64_t BDK_L2C_TADX_INT_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_INT_W1C(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050040000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_INT_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_INT_W1C(...) bdk_l2c_tadx_int_w1c_t
#define bustype_BDK_L2C_TADX_INT_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_INT_W1C(p1) (p1)
#define arguments_BDK_L2C_TADX_INT_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_INT_W1C(...) "L2C_TADX_INT_W1C"


/**
 * RSL - l2c_tad#_int_w1s
 */
typedef union bdk_l2c_tadx_int_w1s {
	uint64_t u;
	struct bdk_l2c_tadx_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t wrdisoci                    : 1;  /**< R/W1C/H - Illegal write operation to a remote node with L2C_OCI_CTL[ENAOCI][node] clear. See
                                                                 L2C_TAD()_ERR for for logged information. */
		uint64_t rddisoci                    : 1;  /**< R/W1C/H - Illegal read operation to a remote node with L2C_OCI_CTL[ENAOCI][node] clear. Note
                                                                 RDDISOCI interrupts can occur during normal operation as the cores are allowed to prefetch
                                                                 to nonexistent memory locations. Therefore, RDDISOCI is for informational purposes only.
                                                                 See L2C_TAD()_ERR for logged information. */
		uint64_t rtgdbe                      : 1;  /**< R/W1C/H - RTG double-bit error. */
		uint64_t rtgsbe                      : 1;  /**< R/W1C/H - RTG single-bit error. */
		uint64_t reserved_18_31              : 14;
		uint64_t lfbto                       : 1;  /**< R/W1C/H - An LFB entry (or more) has encountered a timeout condition When LFBTO timeout condition
                                                                 occurs L2C_TAD()_TIMEOUT is loaded. L2C_TAD()_TIMEOUT is loaded with info from the
                                                                 first LFB that timed out. if multiple LFB timed out simultaneously, then the it will
                                                                 capture info from the lowest LFB number that timed out. */
		uint64_t wrdislmc                    : 1;  /**< R/W1C/H - Illegal write to disabled LMC error. A DRAM write arrived before LMC was enabled. */
		uint64_t rddislmc                    : 1;  /**< R/W1C/H - Illegal read to disabled LMC error. A DRAM read arrived before LMC was enabled. */
		uint64_t rdnxm                       : 1;  /**< R/W1C/H - Read reference outside all the defined and enabled Address Space
                                                                 Control (ASC) regions, or secure read reference to an ASC region
                                                                 not enabled for secure access, or non-secure read reference to an ASC
                                                                 region not enabled for non-secure access.
                                                                 RDNXM interrupts can occur during normal operation as the cores are
                                                                 allowed to prefetch to nonexistent memory locations.  Therefore,
                                                                 RDNXM is for informational purposes only.
                                                                 See L2C_TAD()_ERR for logged information.
                                                                 See L2C_ASC_REGION()_START, L2C_ASC_REGION()_END, and
                                                                 L2C_ASC_REGION()_ATTR for ASC region specification. */
		uint64_t wrnxm                       : 1;  /**< R/W1C/H - Write reference outside all the defined and enabled Address Space
                                                                 Control (ASC) regions, or secure write reference to an ASC region
                                                                 not enabled for secure access, or non-secure write reference to an
                                                                 ASC region not enabled for non-secure access.
                                                                 See L2C_TAD()_ERR for logged information.
                                                                 See L2C_ASC_REGION()_START, L2C_ASC_REGION()_END, and
                                                                 L2C_ASC_REGION()_ATTR for ASC region specification. */
		uint64_t reserved_11_12              : 2;
		uint64_t noway                       : 1;  /**< R/W1C/H - No way was available for allocation. L2C sets NOWAY during its processing of a transaction
                                                                 whenever it needed/wanted to allocate a WAY in the L2 cache, but was unable to. When this
                                                                 bit = 1, it is (generally) not an indication that L2C failed to complete transactions.
                                                                 Rather, it is a hint of possible performance degradation. (For example, L2C must read-
                                                                 modify-write DRAM for every transaction that updates some, but not all, of the bytes in a
                                                                 cache block, misses in the L2 cache, and cannot allocate a WAY.) There is one 'failure'
                                                                 case where L2C sets NOWAY: when it cannot leave a block locked in the L2 cache as part of
                                                                 a LCKL2 transaction. See L2C_TTG()_ERR for logged information. */
		uint64_t tagdbe                      : 1;  /**< R/W1C/H - TAG double-bit error occurred. See L2C_TTG()_ERR for logged information. */
		uint64_t tagsbe                      : 1;  /**< R/W1C/H - TAG single-bit error occurred. See L2C_TTG()_ERR for logged information. */
		uint64_t reserved_6_7                : 2;
		uint64_t fbfdbe                      : 1;  /**< R/W1C/H - FBF double-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t fbfsbe                      : 1;  /**< R/W1C/H - FBF single-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t sbfdbe                      : 1;  /**< R/W1C/H - SBF double-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t sbfsbe                      : 1;  /**< R/W1C/H - SBF single-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t l2ddbe                      : 1;  /**< R/W1C/H - L2D double-bit error occurred. See L2C_TQD()_ERR for logged information. */
		uint64_t l2dsbe                      : 1;  /**< R/W1C/H - L2D single-bit error occurred. See L2C_TQD()_ERR for logged information. */
#else
		uint64_t l2dsbe                      : 1;
		uint64_t l2ddbe                      : 1;
		uint64_t sbfsbe                      : 1;
		uint64_t sbfdbe                      : 1;
		uint64_t fbfsbe                      : 1;
		uint64_t fbfdbe                      : 1;
		uint64_t reserved_6_7                : 2;
		uint64_t tagsbe                      : 1;
		uint64_t tagdbe                      : 1;
		uint64_t noway                       : 1;
		uint64_t reserved_11_12              : 2;
		uint64_t wrnxm                       : 1;
		uint64_t rdnxm                       : 1;
		uint64_t rddislmc                    : 1;
		uint64_t wrdislmc                    : 1;
		uint64_t lfbto                       : 1;
		uint64_t reserved_18_31              : 14;
		uint64_t rtgsbe                      : 1;
		uint64_t rtgdbe                      : 1;
		uint64_t rddisoci                    : 1;
		uint64_t wrdisoci                    : 1;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_l2c_tadx_int_w1s_s      cn85xx; */
	/* struct bdk_l2c_tadx_int_w1s_s      cn88xx; */
	/* struct bdk_l2c_tadx_int_w1s_s      cn88xxp1; */
} bdk_l2c_tadx_int_w1s_t;

static inline uint64_t BDK_L2C_TADX_INT_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_INT_W1S(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050040008ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_INT_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_INT_W1S(...) bdk_l2c_tadx_int_w1s_t
#define bustype_BDK_L2C_TADX_INT_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_INT_W1S(p1) (p1)
#define arguments_BDK_L2C_TADX_INT_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_INT_W1S(...) "L2C_TADX_INT_W1S"


/**
 * RSL - l2c_tad#_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the L2C_TAD_INT_VEC_E
 * enumeration.
 */
typedef union bdk_l2c_tadx_msix_pbax {
	uint64_t u;
	struct bdk_l2c_tadx_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO - Pending message for the associated L2C_TAD()_MSIX_VEC()_CTL, enumerated by
                                                                 L2C_TAD_INT_VEC_E. Bits
                                                                 that have no associated L2C_TAD_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_l2c_tadx_msix_pbax_s    cn85xx; */
	/* struct bdk_l2c_tadx_msix_pbax_s    cn88xx; */
	/* struct bdk_l2c_tadx_msix_pbax_s    cn88xxp1; */
} bdk_l2c_tadx_msix_pbax_t;

static inline uint64_t BDK_L2C_TADX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 7)) && ((param2 == 0)))
		return 0x000087E050FF0000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_MSIX_PBAX(...) bdk_l2c_tadx_msix_pbax_t
#define bustype_BDK_L2C_TADX_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_L2C_TADX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_TADX_MSIX_PBAX(...) "L2C_TADX_MSIX_PBAX"


/**
 * RSL - l2c_tad#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the L2C_TAD_INT_VEC_E enumeration.
 *
 */
typedef union bdk_l2c_tadx_msix_vecx_addr {
	uint64_t u;
	struct bdk_l2c_tadx_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's L2C_TAD()_MSIX_VEC()_ADDR, L2C_TAD()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of L2C_TAD()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_L2C_TAD_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_l2c_tadx_msix_vecx_addr_s cn85xx; */
	/* struct bdk_l2c_tadx_msix_vecx_addr_s cn88xx; */
	/* struct bdk_l2c_tadx_msix_vecx_addr_s cn88xxp1; */
} bdk_l2c_tadx_msix_vecx_addr_t;

static inline uint64_t BDK_L2C_TADX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 7)) && ((param2 == 0)))
		return 0x000087E050F00000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_MSIX_VECX_ADDR(...) bdk_l2c_tadx_msix_vecx_addr_t
#define bustype_BDK_L2C_TADX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_L2C_TADX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_TADX_MSIX_VECX_ADDR(...) "L2C_TADX_MSIX_VECX_ADDR"


/**
 * RSL - l2c_tad#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the L2C_TAD_INT_VEC_E enumeration.
 *
 */
typedef union bdk_l2c_tadx_msix_vecx_ctl {
	uint64_t u;
	struct bdk_l2c_tadx_msix_vecx_ctl_s {
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
	/* struct bdk_l2c_tadx_msix_vecx_ctl_s cn85xx; */
	/* struct bdk_l2c_tadx_msix_vecx_ctl_s cn88xx; */
	/* struct bdk_l2c_tadx_msix_vecx_ctl_s cn88xxp1; */
} bdk_l2c_tadx_msix_vecx_ctl_t;

static inline uint64_t BDK_L2C_TADX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 7)) && ((param2 == 0)))
		return 0x000087E050F00008ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_MSIX_VECX_CTL(...) bdk_l2c_tadx_msix_vecx_ctl_t
#define bustype_BDK_L2C_TADX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_L2C_TADX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_TADX_MSIX_VECX_CTL(...) "L2C_TADX_MSIX_VECX_CTL"


/**
 * RSL - l2c_tad#_pfc#
 */
typedef union bdk_l2c_tadx_pfcx {
	uint64_t u;
	struct bdk_l2c_tadx_pfcx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W/H - Current counter value. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_l2c_tadx_pfcx_s         cn85xx; */
	/* struct bdk_l2c_tadx_pfcx_s         cn88xx; */
	/* struct bdk_l2c_tadx_pfcx_s         cn88xxp1; */
} bdk_l2c_tadx_pfcx_t;

static inline uint64_t BDK_L2C_TADX_PFCX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_PFCX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 7)) && ((param2 <= 3)))
		return 0x000087E050010100ull + (param1 & 7) * 0x1000000ull + (param2 & 3) * 0x8ull;
	csr_fatal("BDK_L2C_TADX_PFCX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_PFCX(...) bdk_l2c_tadx_pfcx_t
#define bustype_BDK_L2C_TADX_PFCX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_PFCX(p1,p2) (p1)
#define arguments_BDK_L2C_TADX_PFCX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_TADX_PFCX(...) "L2C_TADX_PFCX"


/**
 * RSL - l2c_tad#_prf
 *
 * All four counters are equivalent and can use any of the defined selects.
 *
 */
typedef union bdk_l2c_tadx_prf {
	uint64_t u;
	struct bdk_l2c_tadx_prf_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t cnt3sel                     : 8;  /**< R/W - Selects event to count for L2C_TAD(0..7)_PFC(3). Enumerated by L2C_TAD_PRF_SEL_E. */
		uint64_t cnt2sel                     : 8;  /**< R/W - Selects event to count for L2C_TAD(0..7)_PFC(2). Enumerated by L2C_TAD_PRF_SEL_E. */
		uint64_t cnt1sel                     : 8;  /**< R/W - Selects event to count for L2C_TAD(0..7)_PFC(1). Enumerated by L2C_TAD_PRF_SEL_E. */
		uint64_t cnt0sel                     : 8;  /**< R/W - Selects event to count for L2C_TAD(0..7)_PFC(0). Enumerated by L2C_TAD_PRF_SEL_E. */
#else
		uint64_t cnt0sel                     : 8;
		uint64_t cnt1sel                     : 8;
		uint64_t cnt2sel                     : 8;
		uint64_t cnt3sel                     : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_l2c_tadx_prf_s          cn85xx; */
	/* struct bdk_l2c_tadx_prf_s          cn88xx; */
	/* struct bdk_l2c_tadx_prf_s          cn88xxp1; */
} bdk_l2c_tadx_prf_t;

static inline uint64_t BDK_L2C_TADX_PRF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_PRF(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050010000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_PRF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_PRF(...) bdk_l2c_tadx_prf_t
#define bustype_BDK_L2C_TADX_PRF(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_PRF(p1) (p1)
#define arguments_BDK_L2C_TADX_PRF(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_PRF(...) "L2C_TADX_PRF"


/**
 * RSL - l2c_tad#_stat
 *
 * This register holds information about the instantaneous state of the TAD
 *
 */
typedef union bdk_l2c_tadx_stat {
	uint64_t u;
	struct bdk_l2c_tadx_stat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t lfb_valid_cnt               : 6;  /**< RO/H - The number of LFBs in use. */
		uint64_t reserved_5_7                : 3;
		uint64_t vbf_inuse_cnt               : 5;  /**< RO/H - The number of MCI VBFs in use. */
#else
		uint64_t vbf_inuse_cnt               : 5;
		uint64_t reserved_5_7                : 3;
		uint64_t lfb_valid_cnt               : 6;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_l2c_tadx_stat_s         cn85xx; */
	/* struct bdk_l2c_tadx_stat_s         cn88xx; */
	/* struct bdk_l2c_tadx_stat_s         cn88xxp1; */
} bdk_l2c_tadx_stat_t;

static inline uint64_t BDK_L2C_TADX_STAT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_STAT(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050020008ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_STAT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_STAT(...) bdk_l2c_tadx_stat_t
#define bustype_BDK_L2C_TADX_STAT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_STAT(p1) (p1)
#define arguments_BDK_L2C_TADX_STAT(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_STAT(...) "L2C_TADX_STAT"


/**
 * RSL - l2c_tad#_tag
 *
 * This register holds the tag information for LTGL2I and STGL2I commands.
 *
 */
typedef union bdk_l2c_tadx_tag {
	uint64_t u;
	struct bdk_l2c_tadx_tag_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t sblkdty                     : 4;  /**< R/W/H - Sub-block dirty bits. Ignored/loaded with 0 for RTG accesses. If TS is Invalid (0) SBLKDTY
                                                                 must be 0 or operation is undefined. */
		uint64_t reserved_59_59              : 1;
		uint64_t nonsec                      : 1;  /**< R/W/H - Nonsecure bit. */
		uint64_t businfo                     : 9;  /**< R/W/H - The bus information bits. Ignored/loaded with 0 for RTG accesses. */
		uint64_t ecc                         : 7;  /**< R/W/H - The tag ECC. This field is undefined if L2C_CTL[DISECC] is not 1 when the LTGL2I reads the tags. */
		uint64_t tag                         : 22; /**< R/W/H - The tag. TAG\<39:20\> is the corresponding bits from the L2C+LMC internal L2/DRAM byte
                                                                 address. TAG\<41:40\> is the CCPI node of the address. The RTG must always have the
                                                                 TAG\<41:40\> equal to the current node or operation is undefined. */
		uint64_t reserved_6_19               : 14;
		uint64_t node                        : 2;  /**< R/W/H - The node ID for the remote node which holds this block. Ignored/loaded with 0 for TAG accesses. */
		uint64_t ts                          : 2;  /**< R/W/H - The tag state.
                                                                 0x0 = Invalid.
                                                                 0x1 = Shared.
                                                                 0x2 = Exclusive.

                                                                 Note that a local address will never have the value of exclusive as that state is encoded
                                                                 as shared in the TAG and invalid in the RTG. */
		uint64_t used                        : 1;  /**< R/W/H - The LRU use bit. If setting the LOCK bit, the USE bit should also be set or the operation
                                                                 is undefined.  Ignored/loaded with 0 for RTG accesses. */
		uint64_t lock                        : 1;  /**< R/W/H - The lock bit. If setting the LOCK bit, the USE bit should also be set or the operation is
                                                                 undefined.  Ignored/loaded with 0 for RTG accesses. */
#else
		uint64_t lock                        : 1;
		uint64_t used                        : 1;
		uint64_t ts                          : 2;
		uint64_t node                        : 2;
		uint64_t reserved_6_19               : 14;
		uint64_t tag                         : 22;
		uint64_t ecc                         : 7;
		uint64_t businfo                     : 9;
		uint64_t nonsec                      : 1;
		uint64_t reserved_59_59              : 1;
		uint64_t sblkdty                     : 4;
#endif
	} s;
	/* struct bdk_l2c_tadx_tag_s          cn85xx; */
	/* struct bdk_l2c_tadx_tag_s          cn88xx; */
	/* struct bdk_l2c_tadx_tag_s          cn88xxp1; */
} bdk_l2c_tadx_tag_t;

static inline uint64_t BDK_L2C_TADX_TAG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_TAG(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050020000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_TAG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_TAG(...) bdk_l2c_tadx_tag_t
#define bustype_BDK_L2C_TADX_TAG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_TAG(p1) (p1)
#define arguments_BDK_L2C_TADX_TAG(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_TAG(...) "L2C_TADX_TAG"


/**
 * RSL - l2c_tad#_tbf_bist_status
 */
typedef union bdk_l2c_tadx_tbf_bist_status {
	uint64_t u;
	struct bdk_l2c_tadx_tbf_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t vbffl                       : 16; /**< RO/H - BIST failure status for VBF ({QD7H1,QD7H0, ... , QD0H1, QD0H0}) */
		uint64_t sbffl                       : 16; /**< RO/H - BIST failure status for SBF ({QD7H1,QD7H0, ... , QD0H1, QD0H0}) */
		uint64_t fbfrspfl                    : 16; /**< RO/H - BIST failure status for FBF RSP port ({QD7H1,QD7H0, ... , QD0H1, QD0H0}) */
		uint64_t fbfwrpfl                    : 16; /**< RO/H - BIST failure status for FBF WRP port ({QD7H1,QD7H0, ... , QD0H1, QD0H0}) */
#else
		uint64_t fbfwrpfl                    : 16;
		uint64_t fbfrspfl                    : 16;
		uint64_t sbffl                       : 16;
		uint64_t vbffl                       : 16;
#endif
	} s;
	/* struct bdk_l2c_tadx_tbf_bist_status_s cn85xx; */
	/* struct bdk_l2c_tadx_tbf_bist_status_s cn88xx; */
	/* struct bdk_l2c_tadx_tbf_bist_status_s cn88xxp1; */
} bdk_l2c_tadx_tbf_bist_status_t;

static inline uint64_t BDK_L2C_TADX_TBF_BIST_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_TBF_BIST_STATUS(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050070000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_TBF_BIST_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_TBF_BIST_STATUS(...) bdk_l2c_tadx_tbf_bist_status_t
#define bustype_BDK_L2C_TADX_TBF_BIST_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_TBF_BIST_STATUS(p1) (p1)
#define arguments_BDK_L2C_TADX_TBF_BIST_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_TBF_BIST_STATUS(...) "L2C_TADX_TBF_BIST_STATUS"


/**
 * RSL - l2c_tad#_tdt_bist_status
 */
typedef union bdk_l2c_tadx_tdt_bist_status {
	uint64_t u;
	struct bdk_l2c_tadx_tdt_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t l2dfl                       : 16; /**< RO/H - BIST failure status for L2D ({QD7H1,QD7H0, ... , QD0H1, QD0H0}) */
#else
		uint64_t l2dfl                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_l2c_tadx_tdt_bist_status_s cn85xx; */
	/* struct bdk_l2c_tadx_tdt_bist_status_s cn88xx; */
	/* struct bdk_l2c_tadx_tdt_bist_status_s cn88xxp1; */
} bdk_l2c_tadx_tdt_bist_status_t;

static inline uint64_t BDK_L2C_TADX_TDT_BIST_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_TDT_BIST_STATUS(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050070100ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_TDT_BIST_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_TDT_BIST_STATUS(...) bdk_l2c_tadx_tdt_bist_status_t
#define bustype_BDK_L2C_TADX_TDT_BIST_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_TDT_BIST_STATUS(p1) (p1)
#define arguments_BDK_L2C_TADX_TDT_BIST_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_TDT_BIST_STATUS(...) "L2C_TADX_TDT_BIST_STATUS"


/**
 * RSL - l2c_tad#_timeout
 *
 * This register records error information for an LFBTO (LFB TimeOut). The first LFBTO error will
 * lock the register until the logged error type s cleared. If multiple LFBs timed out
 * simultaneously, then this will contain the information form the lowest LFB number that has
 * timed-out. The address can be for the original transaction address or the replacement address
 * (if both could have timed out, then the transaction address will be here).
 */
typedef union bdk_l2c_tadx_timeout {
	uint64_t u;
	struct bdk_l2c_tadx_timeout_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t infolfb                     : 1;  /**< RO/H - Logged address information is for the LFB original transation. */
		uint64_t infovab                     : 1;  /**< RO/H - Logged address information is for the VAB (replacement). If both this and INFOLFB is set,
                                                                 then both could have timed out, but info captured is from the original LFB. */
		uint64_t reserved_57_61              : 5;
		uint64_t lfbnum                      : 5;  /**< RO/H - The LFB number of the entry that timed out, and have its info captures in this register. */
		uint64_t cmd                         : 8;  /**< RO/H - Encoding of XMC or CCPI command causing error.
                                                                 INTERNAL: If CMD[7]==1, use XMC_CMD_E to decode CMD[6:0]. If CMD[7:5]==0, use
                                                                 OCI_MREQ_CMD_E to
                                                                 decode CMD[4:0]. If CMD[7:5]==1, use OCI_MFWD_CMD_E to decode CMD[4:0]. If CMD[7:5]==2,
                                                                 use OCI_MRSP_CMD_E to decode CMD[4:0]. */
		uint64_t reserved_42_43              : 2;
		uint64_t node                        : 2;  /**< RO/H - Home node of the address causing the error. Similar the ADDR below, this can be the
                                                                 request address (if INFOLFB is set), else it is the replacement address (if INFOLFB is
                                                                 clear & INFOVAB is set). */
		uint64_t addr                        : 33; /**< RO/H - Cache line address causing the error. This can be either the request address or the
                                                                 replacement (if INFOLFB is set), else it is the replacement address (if INFOLFB is clear &
                                                                 INFOVAB is set). This address is a physical address. L2C performs index
                                                                 aliasing (if enabled) on the written address and uses that for the command. This
                                                                 index-aliased address is what is returned on a read of L2C_XMC_CMD. */
		uint64_t reserved_0_6                : 7;
#else
		uint64_t reserved_0_6                : 7;
		uint64_t addr                        : 33;
		uint64_t node                        : 2;
		uint64_t reserved_42_43              : 2;
		uint64_t cmd                         : 8;
		uint64_t lfbnum                      : 5;
		uint64_t reserved_57_61              : 5;
		uint64_t infovab                     : 1;
		uint64_t infolfb                     : 1;
#endif
	} s;
	/* struct bdk_l2c_tadx_timeout_s      cn85xx; */
	/* struct bdk_l2c_tadx_timeout_s      cn88xx; */
	/* struct bdk_l2c_tadx_timeout_s      cn88xxp1; */
} bdk_l2c_tadx_timeout_t;

static inline uint64_t BDK_L2C_TADX_TIMEOUT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_TIMEOUT(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050050100ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_TIMEOUT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_TIMEOUT(...) bdk_l2c_tadx_timeout_t
#define bustype_BDK_L2C_TADX_TIMEOUT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_TIMEOUT(p1) (p1)
#define arguments_BDK_L2C_TADX_TIMEOUT(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_TIMEOUT(...) "L2C_TADX_TIMEOUT"


/**
 * RSL - l2c_tad#_timetwo
 *
 * This register records the number of LFB entries that have timed out.
 *
 */
typedef union bdk_l2c_tadx_timetwo {
	uint64_t u;
	struct bdk_l2c_tadx_timetwo_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_33_63              : 31;
		uint64_t sid                         : 4;  /**< RO/H - Source id of the original request, that is 'source' of request. This is only valid if the
                                                                 request is a local request (valid if L2C_TAD()_TIMEOUT[CMD] is an XMC request and not
                                                                 relevant if it is an CCPI request). */
		uint64_t busid                       : 4;  /**< RO/H - Busid of the original request, that is 'source' of request. */
		uint64_t vabst                       : 3;  /**< RO/H - This is the LFB internal state if INFOLFB is set, else will contain VAB internal state if
                                                                 INFOVAB is set. */
		uint64_t lfbst                       : 14; /**< RO/H - This is the LFB internal state if INFOLFB is set, else will contain VAB internal state if
                                                                 INFOVAB is set. */
		uint64_t tocnt                       : 8;  /**< RO/H - This is a running count of the LFB that has timed out ... the count will saturate at 0xFF.
                                                                 Will clear when the LFBTO interrupt is cleared. */
#else
		uint64_t tocnt                       : 8;
		uint64_t lfbst                       : 14;
		uint64_t vabst                       : 3;
		uint64_t busid                       : 4;
		uint64_t sid                         : 4;
		uint64_t reserved_33_63              : 31;
#endif
	} s;
	/* struct bdk_l2c_tadx_timetwo_s      cn85xx; */
	/* struct bdk_l2c_tadx_timetwo_s      cn88xx; */
	/* struct bdk_l2c_tadx_timetwo_s      cn88xxp1; */
} bdk_l2c_tadx_timetwo_t;

static inline uint64_t BDK_L2C_TADX_TIMETWO(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_TIMETWO(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050050000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_TIMETWO", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_TIMETWO(...) bdk_l2c_tadx_timetwo_t
#define bustype_BDK_L2C_TADX_TIMETWO(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_TIMETWO(p1) (p1)
#define arguments_BDK_L2C_TADX_TIMETWO(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_TIMETWO(...) "L2C_TADX_TIMETWO"


/**
 * RSL - l2c_tad#_tqd_err
 *
 * This register records error information for all L2D/SBF/FBF errors.
 * An error locks the L2DIDX, and SYN fields and set the bit corresponding to the error received.
 * DBE errors take priority and overwrite an earlier logged SBE error. Only one of SBE/DBE is set
 * at any given time and serves to document which error the L2DIDX/SYN is associated with.
 * The syndrome is recorded for DBE errors, though the utility of the value is not clear.
 */
typedef union bdk_l2c_tadx_tqd_err {
	uint64_t u;
	struct bdk_l2c_tadx_tqd_err_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t l2ddbe                      : 1;  /**< RO/H - L2DIDX/SYN corresponds to a double-bit L2D ECC error. */
		uint64_t sbfdbe                      : 1;  /**< RO/H - L2DIDX/SYN corresponds to a double-bit SBF ECC error. */
		uint64_t fbfdbe                      : 1;  /**< RO/H - L2DIDX/SYN corresponds to a double-bit FBF ECC error. */
		uint64_t l2dsbe                      : 1;  /**< RO/H - L2DIDX/SYN corresponds to a single-bit L2D ECC error. */
		uint64_t sbfsbe                      : 1;  /**< RO/H - L2DIDX/SYN corresponds to a single-bit SBF ECC error. */
		uint64_t fbfsbe                      : 1;  /**< RO/H - L2DIDX/SYN corresponds to a single-bit FBF ECC error. */
		uint64_t reserved_40_57              : 18;
		uint64_t syn                         : 8;  /**< RO/H - Error syndrome. */
		uint64_t reserved_18_31              : 14;
		uint64_t qdnum                       : 3;  /**< RO/H - Quad containing the error. */
		uint64_t qdhlf                       : 1;  /**< RO/H - Quad half of the containing the error. */
		uint64_t l2didx                      : 14; /**< RO/H - For L2D errors, index within the quad-half containing the error. For SBF and FBF errors
                                                                 [13:5] is 0x0 and [4:0] is the index of the error ([4:1] is lfbnum[3:0], [0] is addr[5]). */
#else
		uint64_t l2didx                      : 14;
		uint64_t qdhlf                       : 1;
		uint64_t qdnum                       : 3;
		uint64_t reserved_18_31              : 14;
		uint64_t syn                         : 8;
		uint64_t reserved_40_57              : 18;
		uint64_t fbfsbe                      : 1;
		uint64_t sbfsbe                      : 1;
		uint64_t l2dsbe                      : 1;
		uint64_t fbfdbe                      : 1;
		uint64_t sbfdbe                      : 1;
		uint64_t l2ddbe                      : 1;
#endif
	} s;
	/* struct bdk_l2c_tadx_tqd_err_s      cn85xx; */
	/* struct bdk_l2c_tadx_tqd_err_s      cn88xx; */
	/* struct bdk_l2c_tadx_tqd_err_s      cn88xxp1; */
} bdk_l2c_tadx_tqd_err_t;

static inline uint64_t BDK_L2C_TADX_TQD_ERR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_TQD_ERR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050060100ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_TQD_ERR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_TQD_ERR(...) bdk_l2c_tadx_tqd_err_t
#define bustype_BDK_L2C_TADX_TQD_ERR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_TQD_ERR(p1) (p1)
#define arguments_BDK_L2C_TADX_TQD_ERR(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_TQD_ERR(...) "L2C_TADX_TQD_ERR"


/**
 * RSL - l2c_tad#_ttg_bist_status
 */
typedef union bdk_l2c_tadx_ttg_bist_status {
	uint64_t u;
	struct bdk_l2c_tadx_ttg_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t xmdmskfl                    : 2;  /**< RO/H - BIST failure status for RSTP XMDMSK memories. */
		uint64_t rtgfl                       : 16; /**< RO/H - BIST failure status for RTG ways. */
		uint64_t reserved_18_31              : 14;
		uint64_t lrulfbfl                    : 1;  /**< RO - Reserved, always zero. */
		uint64_t lrufl                       : 1;  /**< RO/H - BIST failure status for tag LRU. */
		uint64_t tagfl                       : 16; /**< RO/H - BIST failure status for TAG ways. */
#else
		uint64_t tagfl                       : 16;
		uint64_t lrufl                       : 1;
		uint64_t lrulfbfl                    : 1;
		uint64_t reserved_18_31              : 14;
		uint64_t rtgfl                       : 16;
		uint64_t xmdmskfl                    : 2;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_l2c_tadx_ttg_bist_status_s cn85xx; */
	/* struct bdk_l2c_tadx_ttg_bist_status_s cn88xx; */
	/* struct bdk_l2c_tadx_ttg_bist_status_s cn88xxp1; */
} bdk_l2c_tadx_ttg_bist_status_t;

static inline uint64_t BDK_L2C_TADX_TTG_BIST_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_TTG_BIST_STATUS(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050070200ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_TTG_BIST_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_TTG_BIST_STATUS(...) bdk_l2c_tadx_ttg_bist_status_t
#define bustype_BDK_L2C_TADX_TTG_BIST_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_TTG_BIST_STATUS(p1) (p1)
#define arguments_BDK_L2C_TADX_TTG_BIST_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_TTG_BIST_STATUS(...) "L2C_TADX_TTG_BIST_STATUS"


/**
 * RSL - l2c_tad#_ttg_err
 *
 * This register records error information for all TAG SBE/DBE/NOWAY errors.
 * The priority of errors (lowest to highest) is NOWAY, SBE, DBE. An error locks the SYN, WAY,
 * and L2IDX fields for equal or lower priority errors until cleared by software.
 * The syndrome is recorded for DBE errors, though the utility of the value is not clear.
 * A NOWAY error does not change the value of the SYN field, and leaves WAY unpredictable.
 * L2IDX[19:7] is the L2 block index associated with the command which had no way to allocate.
 */
typedef union bdk_l2c_tadx_ttg_err {
	uint64_t u;
	struct bdk_l2c_tadx_ttg_err_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t tagdbe                      : 1;  /**< RO/H - Information refers to a double-bit TAG ECC error. */
		uint64_t tagsbe                      : 1;  /**< RO/H - Information refers to a single-bit TAG ECC error. */
		uint64_t noway                       : 1;  /**< RO/H - Information refers to a NOWAY error. */
		uint64_t reserved_39_60              : 22;
		uint64_t syn                         : 7;  /**< RO/H - Syndrome for the single-bit error. */
		uint64_t reserved_24_31              : 8;
		uint64_t way                         : 4;  /**< RO/H - Way of the L2 block containing the error */
		uint64_t l2idx                       : 13; /**< RO/H - Index of the L2 block containing the error */
		uint64_t reserved_0_6                : 7;
#else
		uint64_t reserved_0_6                : 7;
		uint64_t l2idx                       : 13;
		uint64_t way                         : 4;
		uint64_t reserved_24_31              : 8;
		uint64_t syn                         : 7;
		uint64_t reserved_39_60              : 22;
		uint64_t noway                       : 1;
		uint64_t tagsbe                      : 1;
		uint64_t tagdbe                      : 1;
#endif
	} s;
	/* struct bdk_l2c_tadx_ttg_err_s      cn85xx; */
	/* struct bdk_l2c_tadx_ttg_err_s      cn88xx; */
	/* struct bdk_l2c_tadx_ttg_err_s      cn88xxp1; */
} bdk_l2c_tadx_ttg_err_t;

static inline uint64_t BDK_L2C_TADX_TTG_ERR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TADX_TTG_ERR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E050060200ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_L2C_TADX_TTG_ERR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_TADX_TTG_ERR(...) bdk_l2c_tadx_ttg_err_t
#define bustype_BDK_L2C_TADX_TTG_ERR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TADX_TTG_ERR(p1) (p1)
#define arguments_BDK_L2C_TADX_TTG_ERR(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_TADX_TTG_ERR(...) "L2C_TADX_TTG_ERR"

#endif /* __BDK_CSRS_L2C_TAD__ */
