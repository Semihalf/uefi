#ifndef __BDK_CSRS_GIC__
#define __BDK_CSRS_GIC__
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
 * Cavium GIC.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Bar GIC_BAR_E
 *
 * GIC Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#ifdef __cplusplus
namespace GIC_BAR_E {
	const uint64_t GIC_PF_BAR0 = 0x801000000000;
	const uint64_t GIC_PF_BAR0_PCC_BAR_SIZE_BITS = 17;
	const uint64_t GIC_PF_BAR2 = 0x801000020000;
	const uint64_t GIC_PF_BAR2_PCC_BAR_SIZE_BITS = 17;
	const uint64_t GIC_PF_BAR4 = 0x801080000000;
	const uint64_t GIC_PF_BAR4_PCC_BAR_SIZE_BITS = 24;
};
#endif

/**
 * Enumeration GITS_CMD_ERR_E
 *
 * ITS Command Error Enumeration
 * The actual 24-bit ITS command SEI is defined as [8'h01,
 * GITS_CMD_TYPE(8-bit), GITS_CMD_ERR(8-bit)]
 */
enum gits_cmd_err_e {
	GITS_CMD_ERR_E_CSEI_COLLECTION_OOR = 0x3,
	GITS_CMD_ERR_E_CSEI_DEVICE_OOR = 0x1,
	GITS_CMD_ERR_E_CSEI_ID_OOR = 0x5,
	GITS_CMD_ERR_E_CSEI_ITE_INVALID = 0x10,
	GITS_CMD_ERR_E_CSEI_ITTSIZE_OOR = 0x2,
	GITS_CMD_ERR_E_CSEI_PHYSICALID_OOR = 0x6,
	GITS_CMD_ERR_E_CSEI_TA_INVALID = 0xfe,
	GITS_CMD_ERR_E_CSEI_UNMAPPED_COLLECTION = 0x9,
	GITS_CMD_ERR_E_CSEI_UNMAPPED_DEVICE = 0x4,
	GITS_CMD_ERR_E_CSEI_UNMAPPED_INTERRUPT = 0x7,
	GITS_CMD_ERR_E_CSEI_UNSUPPORTED_CMD = 0xff,
	GITS_CMD_ERR_E_ENUM_LAST = 0x100,
};

/**
 * Enumeration GITS_CMD_TYPE_E
 *
 * ITS Command Type Enumeration
 * Enumerates the ITS commands.
 */
enum gits_cmd_type_e {
	GITS_CMD_TYPE_E_CMD_CLEAR = 0x4,
	GITS_CMD_TYPE_E_CMD_DISCARD = 0xf,
	GITS_CMD_TYPE_E_CMD_INT = 0x3,
	GITS_CMD_TYPE_E_CMD_INV = 0xc,
	GITS_CMD_TYPE_E_CMD_INVALL = 0xd,
	GITS_CMD_TYPE_E_CMD_MAPC = 0x9,
	GITS_CMD_TYPE_E_CMD_MAPD = 0x8,
	GITS_CMD_TYPE_E_CMD_MAPI = 0xb,
	GITS_CMD_TYPE_E_CMD_MAPVI = 0xa,
	GITS_CMD_TYPE_E_CMD_MOVALL = 0xe,
	GITS_CMD_TYPE_E_CMD_MOVI = 0x1,
	GITS_CMD_TYPE_E_CMD_SYNC = 0x5,
	GITS_CMD_TYPE_E_CMD_UDF = 0x0,
	GITS_CMD_TYPE_E_ENUM_LAST = 0x10,
};


/**
 * Structure GITS_CMD_CLEAR_S
 *
 * ITS Clear Command Structure
 *
 */
union gits_cmd_clear_s {
	uint64_t u[4];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_192_255            : 64; /**< [255:192] Reserved. */
		uint64_t reserved_128_191            : 64; /**< [191:128] Reserved. */
		uint64_t reserved_96_127             : 32; /**< [127: 96] Reserved. */
		uint64_t int_id                      : 32; /**< [ 95: 64] Interrupt ID to be translated. */
		uint64_t dev_id                      : 32; /**< [ 63: 32] Interrupt device ID. */
		uint64_t reserved_8_31               : 24; /**< [ 31:  8] Reserved. */
		uint64_t cmd_type                    : 8;  /**< [  7:  0] Command type, indicates GITS_CMD_TYPE_E::CMD_CLEAR. */
#else
		uint64_t cmd_type                    : 8;
		uint64_t reserved_8_31               : 24;
		uint64_t dev_id                      : 32;
		uint64_t int_id                      : 32;
		uint64_t reserved_96_127             : 32;
		uint64_t reserved_128_191            : 64;
		uint64_t reserved_192_255            : 64;
#endif
	} s;
};

/**
 * Structure GITS_CMD_DISCARD_S
 *
 * ITS Discard Command Structure
 *
 */
union gits_cmd_discard_s {
	uint64_t u[4];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_192_255            : 64; /**< [255:192] Reserved. */
		uint64_t reserved_128_191            : 64; /**< [191:128] Reserved. */
		uint64_t reserved_96_127             : 32; /**< [127: 96] Reserved. */
		uint64_t int_id                      : 32; /**< [ 95: 64] Interrupt ID. */
		uint64_t dev_id                      : 32; /**< [ 63: 32] Device ID. */
		uint64_t reserved_8_31               : 24; /**< [ 31:  8] Reserved. */
		uint64_t cmd_type                    : 8;  /**< [  7:  0] Command type, indicates GITS_CMD_TYPE_E::CMD_DISCARD. */
#else
		uint64_t cmd_type                    : 8;
		uint64_t reserved_8_31               : 24;
		uint64_t dev_id                      : 32;
		uint64_t int_id                      : 32;
		uint64_t reserved_96_127             : 32;
		uint64_t reserved_128_191            : 64;
		uint64_t reserved_192_255            : 64;
#endif
	} s;
};

/**
 * Structure GITS_CMD_INT_S
 *
 * ITS INT Command Structure
 *
 */
union gits_cmd_int_s {
	uint64_t u[4];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_192_255            : 64; /**< [255:192] Reserved. */
		uint64_t reserved_128_191            : 64; /**< [191:128] Reserved. */
		uint64_t reserved_96_127             : 32; /**< [127: 96] Reserved. */
		uint64_t int_id                      : 32; /**< [ 95: 64] Interrupt ID to be translated. */
		uint64_t dev_id                      : 32; /**< [ 63: 32] Interrupt device ID. */
		uint64_t reserved_8_31               : 24; /**< [ 31:  8] Reserved. */
		uint64_t cmd_type                    : 8;  /**< [  7:  0] Command type, indicates GITS_CMD_TYPE_E::CMD_INT. */
#else
		uint64_t cmd_type                    : 8;
		uint64_t reserved_8_31               : 24;
		uint64_t dev_id                      : 32;
		uint64_t int_id                      : 32;
		uint64_t reserved_96_127             : 32;
		uint64_t reserved_128_191            : 64;
		uint64_t reserved_192_255            : 64;
#endif
	} s;
};

/**
 * Structure GITS_CMD_INVALL_S
 *
 * ITS INVALL Command Structure
 *
 */
union gits_cmd_invall_s {
	uint64_t u[4];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_192_255            : 64; /**< [255:192] Reserved. */
		uint64_t reserved_144_191            : 48; /**< [191:144] Reserved. */
		uint64_t cid                         : 16; /**< [143:128] Interrupt collection ID. */
		uint64_t reserved_64_127             : 64; /**< [127: 64] Reserved. */
		uint64_t reserved_8_63               : 56; /**< [ 63:  8] Reserved. */
		uint64_t cmd_type                    : 8;  /**< [  7:  0] Command type, indicates GITS_CMD_TYPE_E::CMD_INVALL. */
#else
		uint64_t cmd_type                    : 8;
		uint64_t reserved_8_63               : 56;
		uint64_t reserved_64_127             : 64;
		uint64_t cid                         : 16;
		uint64_t reserved_144_191            : 48;
		uint64_t reserved_192_255            : 64;
#endif
	} s;
};

/**
 * Structure GITS_CMD_INV_S
 *
 * ITS INV Command Structure
 *
 */
union gits_cmd_inv_s {
	uint64_t u[4];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_192_255            : 64; /**< [255:192] Reserved. */
		uint64_t reserved_128_191            : 64; /**< [191:128] Reserved. */
		uint64_t reserved_96_127             : 32; /**< [127: 96] Reserved. */
		uint64_t int_id                      : 32; /**< [ 95: 64] Reserved. */
		uint64_t dev_id                      : 32; /**< [ 63: 32] Interrupt device ID. */
		uint64_t reserved_8_31               : 24; /**< [ 31:  8] Reserved. */
		uint64_t cmd_type                    : 8;  /**< [  7:  0] Command type, indicates GITS_CMD_TYPE_E::CMD_INV. */
#else
		uint64_t cmd_type                    : 8;
		uint64_t reserved_8_31               : 24;
		uint64_t dev_id                      : 32;
		uint64_t int_id                      : 32;
		uint64_t reserved_96_127             : 32;
		uint64_t reserved_128_191            : 64;
		uint64_t reserved_192_255            : 64;
#endif
	} s;
};

/**
 * Structure GITS_CMD_MAPC_S
 *
 * ITS MAPC Command Structure
 *
 */
union gits_cmd_mapc_s {
	uint64_t u[4];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_192_255            : 64; /**< [255:192] Reserved. */
		uint64_t v                           : 1;  /**< [191:191] Valid bit.T specifies whether the ITT address and size are valid. When V is
                                                                 zero, this command un-maps the specified device and translation request from
                                                                 that device will be discarded. */
		uint64_t reserved_176_190            : 15; /**< [190:176] Reserved. */
		uint64_t ta                          : 32; /**< [175:144] Target address. Specifies the physical address of the re-distributor to which
                                                                 interrupts for the collection will be forwarded. */
		uint64_t cid                         : 16; /**< [143:128] Interrupt collection ID. */
		uint64_t reserved_64_127             : 64; /**< [127: 64] Reserved. */
		uint64_t reserved_8_63               : 56; /**< [ 63:  8] Reserved. */
		uint64_t cmd_type                    : 8;  /**< [  7:  0] Command type, indicates GITS_CMD_TYPE_E::CMD_MAPC. */
#else
		uint64_t cmd_type                    : 8;
		uint64_t reserved_8_63               : 56;
		uint64_t reserved_64_127             : 64;
		uint64_t cid                         : 16;
		uint64_t ta                          : 32;
		uint64_t reserved_176_190            : 15;
		uint64_t v                           : 1;
		uint64_t reserved_192_255            : 64;
#endif
	} s;
};

/**
 * Structure GITS_CMD_MAPD_S
 *
 * ITS MAPD Command Structure
 *
 */
union gits_cmd_mapd_s {
	uint64_t u[4];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_192_255            : 64; /**< [255:192] Reserved. */
		uint64_t v                           : 1;  /**< [191:191] Valid bit. Specifies whether the ITT address and size are valid. When V is zero,
                                                                 this command un-maps the specified device and translation request from that
                                                                 device will be discarded. */
		uint64_t reserved_176_190            : 15; /**< [190:176] Reserved. */
		uint64_t itta                        : 40; /**< [175:136] ITT address specifies bits <47:8> of the physical address of the interrupt
                                                                 translation table. Bits <7:0> of the physical address are zero. */
		uint64_t reserved_128_135            : 8;  /**< [135:128] Reserved. */
		uint64_t reserved_69_127             : 59; /**< [127: 69] Reserved. */
		uint64_t size                        : 5;  /**< [ 68: 64] the number of bits of interrupt ID supported for this device, minus one. */
		uint64_t dev_id                      : 32; /**< [ 63: 32] Interrupt device ID. */
		uint64_t reserved_8_31               : 24; /**< [ 31:  8] Reserved. */
		uint64_t cmd_type                    : 8;  /**< [  7:  0] Command type, indicates GITS_CMD_TYPE_E::CMD_MAPD. */
#else
		uint64_t cmd_type                    : 8;
		uint64_t reserved_8_31               : 24;
		uint64_t dev_id                      : 32;
		uint64_t size                        : 5;
		uint64_t reserved_69_127             : 59;
		uint64_t reserved_128_135            : 8;
		uint64_t itta                        : 40;
		uint64_t reserved_176_190            : 15;
		uint64_t v                           : 1;
		uint64_t reserved_192_255            : 64;
#endif
	} s;
};

/**
 * Structure GITS_CMD_MAPI_S
 *
 * ITS MAPI Command Structure
 *
 */
union gits_cmd_mapi_s {
	uint64_t u[4];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_192_255            : 64; /**< [255:192] Reserved. */
		uint64_t reserved_144_191            : 48; /**< [191:144] Reserved. */
		uint64_t cid                         : 16; /**< [143:128] Collection specifies the interrupt collection of which the interrupt with identifier
                                                                 Physical ID is a member. */
		uint64_t reserved_96_127             : 32; /**< [127: 96] Reserved. */
		uint64_t int_id                      : 32; /**< [ 95: 64] Reserved. */
		uint64_t dev_id                      : 32; /**< [ 63: 32] Interrupt device ID. */
		uint64_t reserved_8_31               : 24; /**< [ 31:  8] Reserved. */
		uint64_t cmd_type                    : 8;  /**< [  7:  0] Command type, indicates GITS_CMD_TYPE_E::CMD_MAPI. */
#else
		uint64_t cmd_type                    : 8;
		uint64_t reserved_8_31               : 24;
		uint64_t dev_id                      : 32;
		uint64_t int_id                      : 32;
		uint64_t reserved_96_127             : 32;
		uint64_t cid                         : 16;
		uint64_t reserved_144_191            : 48;
		uint64_t reserved_192_255            : 64;
#endif
	} s;
};

/**
 * Structure GITS_CMD_MAPVI_S
 *
 * ITS MAPVI Command Structure
 *
 */
union gits_cmd_mapvi_s {
	uint64_t u[4];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_192_255            : 64; /**< [255:192] Reserved. */
		uint64_t reserved_144_191            : 48; /**< [191:144] Reserved. */
		uint64_t cid                         : 16; /**< [143:128] Collection specifies the interrupt collection of which the interrupt with identifier
                                                                 Physical ID is a member. */
		uint64_t phy_id                      : 32; /**< [127: 96] Reserved. */
		uint64_t int_id                      : 32; /**< [ 95: 64] Reserved. */
		uint64_t dev_id                      : 32; /**< [ 63: 32] Interrupt device ID. */
		uint64_t reserved_8_31               : 24; /**< [ 31:  8] Reserved. */
		uint64_t cmd_type                    : 8;  /**< [  7:  0] Command type, indicates GITS_CMD_TYPE_E::CMD_MAPVI. */
#else
		uint64_t cmd_type                    : 8;
		uint64_t reserved_8_31               : 24;
		uint64_t dev_id                      : 32;
		uint64_t int_id                      : 32;
		uint64_t phy_id                      : 32;
		uint64_t cid                         : 16;
		uint64_t reserved_144_191            : 48;
		uint64_t reserved_192_255            : 64;
#endif
	} s;
};

/**
 * Structure GITS_CMD_MOVALL_S
 *
 * ITS MOVALL Command Structure
 *
 */
union gits_cmd_movall_s {
	uint64_t u[4];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_240_255            : 16; /**< [255:240] Reserved. */
		uint64_t ta2                         : 32; /**< [239:208] Target address 2. Specifies the new re-distributor. */
		uint64_t reserved_192_207            : 16; /**< [207:192] Reserved. */
		uint64_t reserved_176_191            : 16; /**< [191:176] Reserved. */
		uint64_t ta1                         : 32; /**< [175:144] Target address 1. Specifies the old re-distributor. */
		uint64_t reserved_128_143            : 16; /**< [143:128] Reserved. */
		uint64_t reserved_64_127             : 64; /**< [127: 64] Reserved. */
		uint64_t reserved_8_63               : 56; /**< [ 63:  8] Reserved. */
		uint64_t cmd_type                    : 8;  /**< [  7:  0] Command type, indicates GITS_CMD_TYPE_E::CMD_MOVALL. */
#else
		uint64_t cmd_type                    : 8;
		uint64_t reserved_8_63               : 56;
		uint64_t reserved_64_127             : 64;
		uint64_t reserved_128_143            : 16;
		uint64_t ta1                         : 32;
		uint64_t reserved_176_191            : 16;
		uint64_t reserved_192_207            : 16;
		uint64_t ta2                         : 32;
		uint64_t reserved_240_255            : 16;
#endif
	} s;
};

/**
 * Structure GITS_CMD_MOVI_S
 *
 * ITS MOVI Command Structure
 *
 */
union gits_cmd_movi_s {
	uint64_t u[4];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_192_255            : 64; /**< [255:192] Reserved. */
		uint64_t reserved_144_191            : 48; /**< [191:144] Reserved. */
		uint64_t cid                         : 16; /**< [143:128] Interrupt collection ID. */
		uint64_t reserved_96_127             : 32; /**< [127: 96] Reserved. */
		uint64_t int_id                      : 32; /**< [ 95: 64] Interrupt ID to be translated. */
		uint64_t dev_id                      : 32; /**< [ 63: 32] Interrupt device ID. */
		uint64_t reserved_8_31               : 24; /**< [ 31:  8] Reserved. */
		uint64_t cmd_type                    : 8;  /**< [  7:  0] Command type, indicates GITS_CMD_TYPE_E::CMD_MOVI. */
#else
		uint64_t cmd_type                    : 8;
		uint64_t reserved_8_31               : 24;
		uint64_t dev_id                      : 32;
		uint64_t int_id                      : 32;
		uint64_t reserved_96_127             : 32;
		uint64_t cid                         : 16;
		uint64_t reserved_144_191            : 48;
		uint64_t reserved_192_255            : 64;
#endif
	} s;
};

/**
 * Structure GITS_CMD_SYNC_S
 *
 * ITS SYNC Command Structure
 *
 */
union gits_cmd_sync_s {
	uint64_t u[4];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_192_255            : 64; /**< [255:192] Reserved. */
		uint64_t reserved_176_191            : 16; /**< [191:176] Reserved. */
		uint64_t ta                          : 32; /**< [175:144] Target address of the re-distributor 0. */
		uint64_t reserved_128_143            : 16; /**< [143:128] Reserved. */
		uint64_t reserved_64_127             : 64; /**< [127: 64] Reserved. */
		uint64_t reserved_8_63               : 56; /**< [ 63:  8] Reserved. */
		uint64_t cmd_type                    : 8;  /**< [  7:  0] Command type, indicates GITS_CMD_TYPE_E::CMD_SYNC. */
#else
		uint64_t cmd_type                    : 8;
		uint64_t reserved_8_63               : 56;
		uint64_t reserved_64_127             : 64;
		uint64_t reserved_128_143            : 16;
		uint64_t ta                          : 32;
		uint64_t reserved_176_191            : 16;
		uint64_t reserved_192_255            : 64;
#endif
	} s;
};


/**
 * NCB - gic_bist_statusr
 *
 * This register contains the BIST status for the GIC memories (including ITS and RDB).
 *
 */
typedef union bdk_gic_bist_statusr {
	uint64_t u;
	struct bdk_gic_bist_statusr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t bist                        : 9;  /**< RO/H - Memory BIST status. 0 = Pass, 1 = Fail.
                                                                 INTERNAL: [8:0]= [cic2cic_ig_buf, lpi_cfg_buf, lip_rmw_buf,
                                                                 dtlb_mem,itlb_mem,hct_mem,cqf_mem,rdb_pktf_mem,aprf_mem] in GIC. */
#else
		uint64_t bist                        : 9;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_gic_bist_statusr_s      cn85xx; */
	/* struct bdk_gic_bist_statusr_s      cn88xx; */
} bdk_gic_bist_statusr_t;

#define BDK_GIC_BIST_STATUSR BDK_GIC_BIST_STATUSR_FUNC()
static inline uint64_t BDK_GIC_BIST_STATUSR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GIC_BIST_STATUSR_FUNC(void)
{
	return 0x0000801000010020ull;
}
#define typedef_BDK_GIC_BIST_STATUSR bdk_gic_bist_statusr_t
#define bustype_BDK_GIC_BIST_STATUSR BDK_CSR_TYPE_NCB
#define busnum_BDK_GIC_BIST_STATUSR 0
#define arguments_BDK_GIC_BIST_STATUSR -1,-1,-1,-1
#define basename_BDK_GIC_BIST_STATUSR "GIC_BIST_STATUSR"


/**
 * NCB - gic_cfg_ctlr
 *
 * This register configures GIC features.
 *
 */
typedef union bdk_gic_cfg_ctlr {
	uint64_t u;
	struct bdk_gic_cfg_ctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_33_63              : 31;
		uint64_t dis_cpu_if_load_balancer    : 1;  /**< SR/W - Disable the CPU interface load balancer. */
		uint64_t reserved_10_31              : 22;
		uint64_t dis_lpi_pend_cache          : 1;  /**< SR/W - Disable the LPI pending table cache. */
		uint64_t dis_lpi_cfg_cache           : 1;  /**< SR/W - Disable the LPI configuration cache. */
		uint64_t dis_inv_hct                 : 1;  /**< SR/W - Disable H/W invalidating ITS HCT during ITS disable process. */
		uint64_t dis_its_cdtc                : 1;  /**< SR/W - Disable 1-entry device table cache in ITS CEU. */
		uint64_t dis_its_itlb                : 1;  /**< SR/W - Disable ITS ITLB (interrupt translation entry lookup buffer). */
		uint64_t dis_its_dtlb                : 1;  /**< SR/W - Disable ITS DTLB (device table entry lookup buffer). */
		uint64_t reserved_3_3                : 1;
		uint64_t root_dist                   : 1;  /**< SR/W - Specifies whether the distributor on this socket is root.
                                                                 0 = Distributor is not root.
                                                                 1 = Distributor is root.

                                                                 Out of reset, this field is set. EL3 firmware will clear this field as required for multi-
                                                                 socket operation. */
		uint64_t om                          : 2;  /**< SR/W - Operation mode.
                                                                 0x0 = Single-socket single-root mode.
                                                                 0x1 = Reserved.
                                                                 0x2 = Multi-socket single-root mode.
                                                                 0x3 = Multi-socket multi-root mode. */
#else
		uint64_t om                          : 2;
		uint64_t root_dist                   : 1;
		uint64_t reserved_3_3                : 1;
		uint64_t dis_its_dtlb                : 1;
		uint64_t dis_its_itlb                : 1;
		uint64_t dis_its_cdtc                : 1;
		uint64_t dis_inv_hct                 : 1;
		uint64_t dis_lpi_cfg_cache           : 1;
		uint64_t dis_lpi_pend_cache          : 1;
		uint64_t reserved_10_31              : 22;
		uint64_t dis_cpu_if_load_balancer    : 1;
		uint64_t reserved_33_63              : 31;
#endif
	} s;
	struct bdk_gic_cfg_ctlr_cn85xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_33_63              : 31;
		uint64_t dis_cpu_if_load_balancer    : 1;  /**< SR/W - Disable the CPU interface load balancer. */
		uint64_t reserved_10_31              : 22;
		uint64_t dis_lpi_pend_cache          : 1;  /**< SR/W - Disable the LPI pending table cache. */
		uint64_t dis_lpi_cfg_cache           : 1;  /**< SR/W - Disable the LPI configuration cache. */
		uint64_t reserved_7_7                : 1;
		uint64_t dis_its_cdtc                : 1;  /**< SR/W - Disable 1-entry device table cache in ITS CEU. */
		uint64_t dis_its_itlb                : 1;  /**< SR/W - Disable ITS ITLB (interrupt translation entry lookup buffer). */
		uint64_t dis_its_dtlb                : 1;  /**< SR/W - Disable ITS DTLB (device table entry lookup buffer). */
		uint64_t reserved_3_3                : 1;
		uint64_t root_dist                   : 1;  /**< SR/W - Specifies whether the distributor on this socket is root.
                                                                 0 = Distributor is not root.
                                                                 1 = Distributor is root.

                                                                 Out of reset, this field is set. EL3 firmware will clear this field as required for multi-
                                                                 socket operation. */
		uint64_t om                          : 2;  /**< SR/W - Operation mode.
                                                                 0x0 = Single-socket single-root mode.
                                                                 0x1 = Reserved.
                                                                 0x2 = Multi-socket single-root mode.
                                                                 0x3 = Multi-socket multi-root mode. */
#else
		uint64_t om                          : 2;
		uint64_t root_dist                   : 1;
		uint64_t reserved_3_3                : 1;
		uint64_t dis_its_dtlb                : 1;
		uint64_t dis_its_itlb                : 1;
		uint64_t dis_its_cdtc                : 1;
		uint64_t reserved_7_7                : 1;
		uint64_t dis_lpi_cfg_cache           : 1;
		uint64_t dis_lpi_pend_cache          : 1;
		uint64_t reserved_10_31              : 22;
		uint64_t dis_cpu_if_load_balancer    : 1;
		uint64_t reserved_33_63              : 31;
#endif
	} cn85xx;
	/* struct bdk_gic_cfg_ctlr_s          cn88xx; */
} bdk_gic_cfg_ctlr_t;

#define BDK_GIC_CFG_CTLR BDK_GIC_CFG_CTLR_FUNC()
static inline uint64_t BDK_GIC_CFG_CTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GIC_CFG_CTLR_FUNC(void)
{
	return 0x0000801000010000ull;
}
#define typedef_BDK_GIC_CFG_CTLR bdk_gic_cfg_ctlr_t
#define bustype_BDK_GIC_CFG_CTLR BDK_CSR_TYPE_NCB
#define busnum_BDK_GIC_CFG_CTLR 0
#define arguments_BDK_GIC_CFG_CTLR -1,-1,-1,-1
#define basename_BDK_GIC_CFG_CTLR "GIC_CFG_CTLR"


/**
 * NCB - gic_ecc_ctlr
 *
 * This register allows inserting ECC errors for testing.
 *
 */
typedef union bdk_gic_ecc_ctlr {
	uint64_t u;
	struct bdk_gic_ecc_ctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t ram_flip1                   : 9;  /**< SR/W - Flip syndrome bits on write. Flip syndrome bits <1> on writes to the corresponding ram to
                                                                 test single-bit or double-bit error handling. See COR_DIS bit definitions. */
		uint64_t reserved_29_39              : 11;
		uint64_t ram_flip0                   : 9;  /**< SR/W - Flip syndrome bits on write. Flip syndrome bits <0> on writes to the corresponding ram to
                                                                 test single-bit or double-bit error handling. See COR_DIS bit definitions. */
		uint64_t reserved_9_19               : 11;
		uint64_t cor_dis                     : 9;  /**< SR/W - RAM ECC correction disable. INTERNAL: for cor_dis[8:0]= [cic2cic_ig_buf, lpi_cfg_buf,
                                                                 lip_rmw_buf,
                                                                 dtlb_mem,itlb_mem,hct_mem,cqf_mem,rdb_pktf_mem,aprf_mem]  in GIC. */
#else
		uint64_t cor_dis                     : 9;
		uint64_t reserved_9_19               : 11;
		uint64_t ram_flip0                   : 9;
		uint64_t reserved_29_39              : 11;
		uint64_t ram_flip1                   : 9;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_gic_ecc_ctlr_s          cn85xx; */
	/* struct bdk_gic_ecc_ctlr_s          cn88xx; */
} bdk_gic_ecc_ctlr_t;

#define BDK_GIC_ECC_CTLR BDK_GIC_ECC_CTLR_FUNC()
static inline uint64_t BDK_GIC_ECC_CTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GIC_ECC_CTLR_FUNC(void)
{
	return 0x0000801000010008ull;
}
#define typedef_BDK_GIC_ECC_CTLR bdk_gic_ecc_ctlr_t
#define bustype_BDK_GIC_ECC_CTLR BDK_CSR_TYPE_NCB
#define busnum_BDK_GIC_ECC_CTLR 0
#define arguments_BDK_GIC_ECC_CTLR -1,-1,-1,-1
#define basename_BDK_GIC_ECC_CTLR "GIC_ECC_CTLR"


/**
 * NCB - gic_ecc_int_statusr
 *
 * This register contains the ECC error status for the GIC memories (including ITS and RDB).
 *
 */
typedef union bdk_gic_ecc_int_statusr {
	uint64_t u;
	struct bdk_gic_ecc_int_statusr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_41_63              : 23;
		uint64_t dbe                         : 9;  /**< R/W1C/H - RAM ECC DBE detected.
                                                                 INTERNAL: [8:0] = [cic2cic_ig_buf, lpi_cfg_buf, lip_rmw_buf,
                                                                 dtlb_mem,itlb_mem,hct_mem,cqf_mem,rdb_pktf_mem,aprf_mem] in GIC. */
		uint64_t reserved_9_31               : 23;
		uint64_t sbe                         : 9;  /**< R/W1C/H - RAM ECC SBE detected.
                                                                 INTERNAL: [8:0] = [cic2cic_ig_buf, lpi_cfg_buf, lip_rmw_buf,
                                                                 dtlb_mem,itlb_mem,hct_mem,cqf_mem,rdb_pktf_mem,aprf_mem] in GIC. */
#else
		uint64_t sbe                         : 9;
		uint64_t reserved_9_31               : 23;
		uint64_t dbe                         : 9;
		uint64_t reserved_41_63              : 23;
#endif
	} s;
	/* struct bdk_gic_ecc_int_statusr_s   cn85xx; */
	/* struct bdk_gic_ecc_int_statusr_s   cn88xx; */
} bdk_gic_ecc_int_statusr_t;

#define BDK_GIC_ECC_INT_STATUSR BDK_GIC_ECC_INT_STATUSR_FUNC()
static inline uint64_t BDK_GIC_ECC_INT_STATUSR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GIC_ECC_INT_STATUSR_FUNC(void)
{
	return 0x0000801000010030ull;
}
#define typedef_BDK_GIC_ECC_INT_STATUSR bdk_gic_ecc_int_statusr_t
#define bustype_BDK_GIC_ECC_INT_STATUSR BDK_CSR_TYPE_NCB
#define busnum_BDK_GIC_ECC_INT_STATUSR 0
#define arguments_BDK_GIC_ECC_INT_STATUSR -1,-1,-1,-1
#define basename_BDK_GIC_ECC_INT_STATUSR "GIC_ECC_INT_STATUSR"


/**
 * NCB - gic_rib_err_adrr
 *
 * This register holds the address of the first RIB error message.
 *
 */
typedef union bdk_gic_rib_err_adrr {
	uint64_t u;
	struct bdk_gic_rib_err_adrr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t addr                        : 34; /**< RO/H - Address of the target CSR. It is meaningful only when GICI_RIB_ERR_STATUSR[V] is set. */
		uint64_t node                        : 2;  /**< RO/H - ID of the target node. It is meaningful only when GICI_RIB_ERR_STATUSR[V] is set. */
#else
		uint64_t node                        : 2;
		uint64_t addr                        : 34;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_gic_rib_err_adrr_s      cn85xx; */
	/* struct bdk_gic_rib_err_adrr_s      cn88xx; */
} bdk_gic_rib_err_adrr_t;

#define BDK_GIC_RIB_ERR_ADRR BDK_GIC_RIB_ERR_ADRR_FUNC()
static inline uint64_t BDK_GIC_RIB_ERR_ADRR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GIC_RIB_ERR_ADRR_FUNC(void)
{
	return 0x0000801000010048ull;
}
#define typedef_BDK_GIC_RIB_ERR_ADRR bdk_gic_rib_err_adrr_t
#define bustype_BDK_GIC_RIB_ERR_ADRR BDK_CSR_TYPE_NCB
#define busnum_BDK_GIC_RIB_ERR_ADRR 0
#define arguments_BDK_GIC_RIB_ERR_ADRR -1,-1,-1,-1
#define basename_BDK_GIC_RIB_ERR_ADRR "GIC_RIB_ERR_ADRR"


/**
 * NCB - gic_rib_err_statusr
 *
 * This register holds the status of the first RIB error message.
 *
 */
typedef union bdk_gic_rib_err_statusr {
	uint64_t u;
	struct bdk_gic_rib_err_statusr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_62_63              : 2;
		uint64_t v                           : 1;  /**< R/W1C/H - When set, the command error is valid. */
		uint64_t m                           : 1;  /**< RO/H - When set, it means multiple errors have happened. It is meaningful only when V=1. */
		uint64_t reserved_53_59              : 7;
		uint64_t dev_id                      : 21; /**< RO/H - Device ID inside the RIB message. */
		uint64_t reserved_29_31              : 3;
		uint64_t secure                      : 1;  /**< RO/H - Secure bit inside the RIB message. It is meaningful only when V=1. */
		uint64_t reserved_20_27              : 8;
		uint64_t int_id                      : 20; /**< RO/H - Interrrupt ID inside the RIB message. It is meaningful only when V=1. */
#else
		uint64_t int_id                      : 20;
		uint64_t reserved_20_27              : 8;
		uint64_t secure                      : 1;
		uint64_t reserved_29_31              : 3;
		uint64_t dev_id                      : 21;
		uint64_t reserved_53_59              : 7;
		uint64_t m                           : 1;
		uint64_t v                           : 1;
		uint64_t reserved_62_63              : 2;
#endif
	} s;
	/* struct bdk_gic_rib_err_statusr_s   cn85xx; */
	/* struct bdk_gic_rib_err_statusr_s   cn88xx; */
} bdk_gic_rib_err_statusr_t;

#define BDK_GIC_RIB_ERR_STATUSR BDK_GIC_RIB_ERR_STATUSR_FUNC()
static inline uint64_t BDK_GIC_RIB_ERR_STATUSR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GIC_RIB_ERR_STATUSR_FUNC(void)
{
	return 0x0000801000010040ull;
}
#define typedef_BDK_GIC_RIB_ERR_STATUSR bdk_gic_rib_err_statusr_t
#define bustype_BDK_GIC_RIB_ERR_STATUSR BDK_CSR_TYPE_NCB
#define busnum_BDK_GIC_RIB_ERR_STATUSR 0
#define arguments_BDK_GIC_RIB_ERR_STATUSR -1,-1,-1,-1
#define basename_BDK_GIC_RIB_ERR_STATUSR "GIC_RIB_ERR_STATUSR"


/**
 * NCB - gic_scratch
 *
 * This is a scratch register.
 *
 */
typedef union bdk_gic_scratch {
	uint64_t u;
	struct bdk_gic_scratch_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - This is a scratch register. Reads and writes of this register have no side effects. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_gic_scratch_s           cn85xx; */
	/* struct bdk_gic_scratch_s           cn88xx; */
} bdk_gic_scratch_t;

#define BDK_GIC_SCRATCH BDK_GIC_SCRATCH_FUNC()
static inline uint64_t BDK_GIC_SCRATCH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GIC_SCRATCH_FUNC(void)
{
	return 0x0000801000010080ull;
}
#define typedef_BDK_GIC_SCRATCH bdk_gic_scratch_t
#define bustype_BDK_GIC_SCRATCH BDK_CSR_TYPE_NCB
#define busnum_BDK_GIC_SCRATCH 0
#define arguments_BDK_GIC_SCRATCH -1,-1,-1,-1
#define basename_BDK_GIC_SCRATCH "GIC_SCRATCH"


/**
 * NCB32b - gicd_cidr0
 */
typedef union bdk_gicd_cidr0 {
	uint32_t u;
	struct bdk_gicd_cidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicd_cidr0_s            cn85xx; */
	/* struct bdk_gicd_cidr0_s            cn88xx; */
} bdk_gicd_cidr0_t;

#define BDK_GICD_CIDR0 BDK_GICD_CIDR0_FUNC()
static inline uint64_t BDK_GICD_CIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_CIDR0_FUNC(void)
{
	return 0x000080100000FFF0ull;
}
#define typedef_BDK_GICD_CIDR0 bdk_gicd_cidr0_t
#define bustype_BDK_GICD_CIDR0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_CIDR0 0
#define arguments_BDK_GICD_CIDR0 -1,-1,-1,-1
#define basename_BDK_GICD_CIDR0 "GICD_CIDR0"


/**
 * NCB32b - gicd_cidr1
 */
typedef union bdk_gicd_cidr1 {
	uint32_t u;
	struct bdk_gicd_cidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicd_cidr1_s            cn85xx; */
	/* struct bdk_gicd_cidr1_s            cn88xx; */
} bdk_gicd_cidr1_t;

#define BDK_GICD_CIDR1 BDK_GICD_CIDR1_FUNC()
static inline uint64_t BDK_GICD_CIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_CIDR1_FUNC(void)
{
	return 0x000080100000FFF4ull;
}
#define typedef_BDK_GICD_CIDR1 bdk_gicd_cidr1_t
#define bustype_BDK_GICD_CIDR1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_CIDR1 0
#define arguments_BDK_GICD_CIDR1 -1,-1,-1,-1
#define basename_BDK_GICD_CIDR1 "GICD_CIDR1"


/**
 * NCB32b - gicd_cidr2
 */
typedef union bdk_gicd_cidr2 {
	uint32_t u;
	struct bdk_gicd_cidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicd_cidr2_s            cn85xx; */
	/* struct bdk_gicd_cidr2_s            cn88xx; */
} bdk_gicd_cidr2_t;

#define BDK_GICD_CIDR2 BDK_GICD_CIDR2_FUNC()
static inline uint64_t BDK_GICD_CIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_CIDR2_FUNC(void)
{
	return 0x000080100000FFF8ull;
}
#define typedef_BDK_GICD_CIDR2 bdk_gicd_cidr2_t
#define bustype_BDK_GICD_CIDR2 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_CIDR2 0
#define arguments_BDK_GICD_CIDR2 -1,-1,-1,-1
#define basename_BDK_GICD_CIDR2 "GICD_CIDR2"


/**
 * NCB32b - gicd_cidr3
 */
typedef union bdk_gicd_cidr3 {
	uint32_t u;
	struct bdk_gicd_cidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicd_cidr3_s            cn85xx; */
	/* struct bdk_gicd_cidr3_s            cn88xx; */
} bdk_gicd_cidr3_t;

#define BDK_GICD_CIDR3 BDK_GICD_CIDR3_FUNC()
static inline uint64_t BDK_GICD_CIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_CIDR3_FUNC(void)
{
	return 0x000080100000FFFCull;
}
#define typedef_BDK_GICD_CIDR3 bdk_gicd_cidr3_t
#define bustype_BDK_GICD_CIDR3 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_CIDR3 0
#define arguments_BDK_GICD_CIDR3 -1,-1,-1,-1
#define basename_BDK_GICD_CIDR3 "GICD_CIDR3"


/**
 * NCB32b - gicd_clrspi_nsr
 */
typedef union bdk_gicd_clrspi_nsr {
	uint32_t u;
	struct bdk_gicd_clrspi_nsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_10_31              : 22;
		uint32_t spi_id                      : 10; /**< WO - Clear an SPI pending state (write-only). If the SPI is not pending, then the write has no
                                                                 effect.
                                                                 If the SPI ID is invalid, then the write has no effect.
                                                                 If the register is written using a non-secure access and the value specifies a secure SPI
                                                                 and the value of the corresponding GICD_NSACR() register is less than 0x2 (ie. does not
                                                                 permit non-secure accesses to clear the interrupt pending state), the write has no effect. */
#else
		uint32_t spi_id                      : 10;
		uint32_t reserved_10_31              : 22;
#endif
	} s;
	/* struct bdk_gicd_clrspi_nsr_s       cn85xx; */
	/* struct bdk_gicd_clrspi_nsr_s       cn88xx; */
} bdk_gicd_clrspi_nsr_t;

#define BDK_GICD_CLRSPI_NSR BDK_GICD_CLRSPI_NSR_FUNC()
static inline uint64_t BDK_GICD_CLRSPI_NSR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_CLRSPI_NSR_FUNC(void)
{
	return 0x0000801000000048ull;
}
#define typedef_BDK_GICD_CLRSPI_NSR bdk_gicd_clrspi_nsr_t
#define bustype_BDK_GICD_CLRSPI_NSR BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_CLRSPI_NSR 0
#define arguments_BDK_GICD_CLRSPI_NSR -1,-1,-1,-1
#define basename_BDK_GICD_CLRSPI_NSR "GICD_CLRSPI_NSR"


/**
 * NCB32b - gicd_clrspi_sr
 */
typedef union bdk_gicd_clrspi_sr {
	uint32_t u;
	struct bdk_gicd_clrspi_sr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_10_31              : 22;
		uint32_t spi_id                      : 10; /**< SWO - Clear an SPI pending state (write-only). If the SPI is not pending, then the write has no
                                                                 effect.
                                                                 If the SPI ID is invalid, then the write has no effect.
                                                                 If the register is written using a non-secure access, the write has no effect. */
#else
		uint32_t spi_id                      : 10;
		uint32_t reserved_10_31              : 22;
#endif
	} s;
	/* struct bdk_gicd_clrspi_sr_s        cn85xx; */
	/* struct bdk_gicd_clrspi_sr_s        cn88xx; */
} bdk_gicd_clrspi_sr_t;

#define BDK_GICD_CLRSPI_SR BDK_GICD_CLRSPI_SR_FUNC()
static inline uint64_t BDK_GICD_CLRSPI_SR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_CLRSPI_SR_FUNC(void)
{
	return 0x0000801000000058ull;
}
#define typedef_BDK_GICD_CLRSPI_SR bdk_gicd_clrspi_sr_t
#define bustype_BDK_GICD_CLRSPI_SR BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_CLRSPI_SR 0
#define arguments_BDK_GICD_CLRSPI_SR -1,-1,-1,-1
#define basename_BDK_GICD_CLRSPI_SR "GICD_CLRSPI_SR"


/**
 * NCB32b - gicd_icactiver#
 *
 * Each bit in GICD_ICACTIVER() provides a clear-active bit for each SPI supported by the GIC.
 * Writing 1 to a clear-active bit clears the active status of the corresponding SPI.
 */
typedef union bdk_gicd_icactiverx {
	uint32_t u;
	struct bdk_gicd_icactiverx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W1C - Each bit corresponds to an SPI for SPI IDs in the range 95..32. If read as 0, then the SPI
                                                                 is not active. If read as 1, the SPI is in active state.
                                                                 Clear-active bits corresponding to secure interrupts (either group0 or group1) may only be
                                                                 set by secure accesses.
                                                                 A clear-active bit for a secure SPI is RAZ/WI to non-secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicd_icactiverx_s       cn85xx; */
	/* struct bdk_gicd_icactiverx_s       cn88xx; */
} bdk_gicd_icactiverx_t;

static inline uint64_t BDK_GICD_ICACTIVERX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_ICACTIVERX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 4))))
		return 0x0000801000000380ull + (param1 & 7) * 0x4ull;
	csr_fatal("BDK_GICD_ICACTIVERX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICD_ICACTIVERX(...) bdk_gicd_icactiverx_t
#define bustype_BDK_GICD_ICACTIVERX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_ICACTIVERX(p1) (p1)
#define arguments_BDK_GICD_ICACTIVERX(p1) (p1),-1,-1,-1
#define basename_BDK_GICD_ICACTIVERX(...) "GICD_ICACTIVERX"


/**
 * NCB32b - gicd_icenabler#
 *
 * Each bit in GICD_ICENABLER() provides a clear-enable bit for each SPI supported by the GIC.
 * Writing 1 to a clear-enable bit disables forwarding of the corresponding SPI from the
 * Distributor to the CPU interfaces. Reading a bit identifies whether the SPI is enabled.
 */
typedef union bdk_gicd_icenablerx {
	uint32_t u;
	struct bdk_gicd_icenablerx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W1C - Each bit corresponds to an SPI for SPI IDs in the range 95..32. Upon reading, if a bit is
                                                                 0, then the SPI is not enabled to be forwarded to the CPU interface. Upon reading, if a
                                                                 bit is 1, the SPI is enabled to be forwarded to the CPU interface. Clear-enable bits
                                                                 corresponding to secure interrupts (either group0 or group1) may only be set by secure
                                                                 accesses.

                                                                 Writes to the register cannot be considered complete until the effects of the write are
                                                                 visible throughout the affinity hierarchy. To ensure that an enable has been cleared,
                                                                 software must write to this register with bits set to clear the required enables. Software
                                                                 must then poll GICD_CTLR[RWP] (register writes pending) until it has the value zero. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicd_icenablerx_s       cn85xx; */
	/* struct bdk_gicd_icenablerx_s       cn88xx; */
} bdk_gicd_icenablerx_t;

static inline uint64_t BDK_GICD_ICENABLERX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_ICENABLERX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 4))))
		return 0x0000801000000180ull + (param1 & 7) * 0x4ull;
	csr_fatal("BDK_GICD_ICENABLERX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICD_ICENABLERX(...) bdk_gicd_icenablerx_t
#define bustype_BDK_GICD_ICENABLERX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_ICENABLERX(p1) (p1)
#define arguments_BDK_GICD_ICENABLERX(p1) (p1),-1,-1,-1
#define basename_BDK_GICD_ICENABLERX(...) "GICD_ICENABLERX"


/**
 * NCB32b - gicd_icfgr#
 */
typedef union bdk_gicd_icfgrx {
	uint32_t u;
	struct bdk_gicd_icfgrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W - Two bits per SPI. Defines whether an SPI is level-sensitive or edge-triggered.
                                                                 Bit[1] is 0, the SPI is level-sensitive.
                                                                 Bit[1] is 1, the SPI is edge-triggered.
                                                                 Bit[0] Reserved.

                                                                 If SPI is a secure interrupt, then its corresponding field is RAZ/WI to non-secure
                                                                 accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicd_icfgrx_s           cn85xx; */
	/* struct bdk_gicd_icfgrx_s           cn88xx; */
} bdk_gicd_icfgrx_t;

static inline uint64_t BDK_GICD_ICFGRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_ICFGRX(unsigned long param1)
{
	if ((((param1 >= 2) && (param1 <= 9))))
		return 0x0000801000000C00ull + (param1 & 15) * 0x4ull;
	csr_fatal("BDK_GICD_ICFGRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICD_ICFGRX(...) bdk_gicd_icfgrx_t
#define bustype_BDK_GICD_ICFGRX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_ICFGRX(p1) (p1)
#define arguments_BDK_GICD_ICFGRX(p1) (p1),-1,-1,-1
#define basename_BDK_GICD_ICFGRX(...) "GICD_ICFGRX"


/**
 * NCB32b - gicd_icpendr#
 *
 * Each bit in GICD_ICPENDR() provides a clear-pending bit for each SPI supported by the GIC.
 * Writing 1 to a Clear-pending bit clears the pending status of the corresponding SPI.
 */
typedef union bdk_gicd_icpendrx {
	uint32_t u;
	struct bdk_gicd_icpendrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W1C - Each bit corresponds to an SPI for SPI IDs in the range 95..32. If read as 0, then the SPI
                                                                 is not pending. If read as 1, the SPI is in pending state.
                                                                 Clear-pending bits corresponding to secure interrupts (either group0 or group1) may only
                                                                 be set by secure accesses.
                                                                 A clear-pending bit for a secure SPI is RAZ/WI to non-secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicd_icpendrx_s         cn85xx; */
	/* struct bdk_gicd_icpendrx_s         cn88xx; */
} bdk_gicd_icpendrx_t;

static inline uint64_t BDK_GICD_ICPENDRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_ICPENDRX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 4))))
		return 0x0000801000000280ull + (param1 & 7) * 0x4ull;
	csr_fatal("BDK_GICD_ICPENDRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICD_ICPENDRX(...) bdk_gicd_icpendrx_t
#define bustype_BDK_GICD_ICPENDRX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_ICPENDRX(p1) (p1)
#define arguments_BDK_GICD_ICPENDRX(p1) (p1),-1,-1,-1
#define basename_BDK_GICD_ICPENDRX(...) "GICD_ICPENDRX"


/**
 * NCB32b - gicd_igroupr#
 *
 * The bit in GICD_IGROUPR() for a particular SPI is concatenated with the corresponding bit for
 * that SPI in GICD_IGRPMODR() to form a 2-bit field that defines the interrupt group (G0S, G1S,
 * G1NS) for that SPI.
 */
typedef union bdk_gicd_igrouprx {
	uint32_t u;
	struct bdk_gicd_igrouprx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< SR/W - Each bit corresponds to an SPI for SPI IDs in the range 95..32. If 0, then the SPI is
                                                                 secure. If 1, the SPI is non-secure. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicd_igrouprx_s         cn85xx; */
	/* struct bdk_gicd_igrouprx_s         cn88xx; */
} bdk_gicd_igrouprx_t;

static inline uint64_t BDK_GICD_IGROUPRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_IGROUPRX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 4))))
		return 0x0000801000000080ull + (param1 & 7) * 0x4ull;
	csr_fatal("BDK_GICD_IGROUPRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICD_IGROUPRX(...) bdk_gicd_igrouprx_t
#define bustype_BDK_GICD_IGROUPRX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_IGROUPRX(p1) (p1)
#define arguments_BDK_GICD_IGROUPRX(p1) (p1),-1,-1,-1
#define basename_BDK_GICD_IGROUPRX(...) "GICD_IGROUPRX"


/**
 * NCB32b - gicd_igrpmodr#
 *
 * The bit in GICD_IGRPMODR() for a particular SPI is concatenated with the
 * corresponding bit for that SPI in GICD_IGROUPR() to form a 2-bit field that defines
 * the interrupt group (G0S, G1S, G1NS) for that SPI.
 */
typedef union bdk_gicd_igrpmodrx {
	uint32_t u;
	struct bdk_gicd_igrpmodrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< SR/W - Each bit corresponds to an SPI for SPI IDs in the range 95..32. If 0, then the SPI group
                                                                 is not modified. If 1, then the SPI group is modified from group0 to secure group1. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicd_igrpmodrx_s        cn85xx; */
	/* struct bdk_gicd_igrpmodrx_s        cn88xx; */
} bdk_gicd_igrpmodrx_t;

static inline uint64_t BDK_GICD_IGRPMODRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_IGRPMODRX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 4))))
		return 0x0000801000000D00ull + (param1 & 7) * 0x4ull;
	csr_fatal("BDK_GICD_IGRPMODRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICD_IGRPMODRX(...) bdk_gicd_igrpmodrx_t
#define bustype_BDK_GICD_IGRPMODRX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_IGRPMODRX(p1) (p1)
#define arguments_BDK_GICD_IGRPMODRX(p1) (p1),-1,-1,-1
#define basename_BDK_GICD_IGRPMODRX(...) "GICD_IGRPMODRX"


/**
 * NCB32b - gicd_iidr
 *
 * This 32-bit register is read-only and specifies the version and features supported by the
 * Distributor.
 */
typedef union bdk_gicd_iidr {
	uint32_t u;
	struct bdk_gicd_iidr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t productid                   : 8;  /**< RO - An implementation defined product number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN88XX. */
		uint32_t reserved_20_23              : 4;
		uint32_t variant                     : 4;  /**< RO - Indicates the major revision or variant of the product.
                                                                 In CNXXXX, the major pass number. */
		uint32_t revision                    : 4;  /**< RO - Indicates the minor revision of the product.
                                                                 In CNXXXX, the minor pass number. */
		uint32_t implementer                 : 12; /**< RO - Indicates the implementer:
                                                                 0x34C = Cavium. */
#else
		uint32_t implementer                 : 12;
		uint32_t revision                    : 4;
		uint32_t variant                     : 4;
		uint32_t reserved_20_23              : 4;
		uint32_t productid                   : 8;
#endif
	} s;
	/* struct bdk_gicd_iidr_s             cn85xx; */
	/* struct bdk_gicd_iidr_s             cn88xx; */
} bdk_gicd_iidr_t;

#define BDK_GICD_IIDR BDK_GICD_IIDR_FUNC()
static inline uint64_t BDK_GICD_IIDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_IIDR_FUNC(void)
{
	return 0x0000801000000008ull;
}
#define typedef_BDK_GICD_IIDR bdk_gicd_iidr_t
#define bustype_BDK_GICD_IIDR BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_IIDR 0
#define arguments_BDK_GICD_IIDR -1,-1,-1,-1
#define basename_BDK_GICD_IIDR "GICD_IIDR"


/**
 * NCB32b - gicd_ipriorityr#
 *
 * Each byte in GICD_IPRIORITYR() provides a priority field for each SPI supported by the GIC.
 *
 */
typedef union bdk_gicd_ipriorityrx {
	uint32_t u;
	struct bdk_gicd_ipriorityrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W - Each byte corresponds to an SPI for SPI IDs in the range 95..32.
                                                                 Priority fields corresponding to secure interrupts (either group0 or group1) may only be
                                                                 set by secure accesses, or when GICD_CTLR[DS] is one.
                                                                 Byte accesses are permitted to these registers.
                                                                 A priority field for a secure SPI is RAZ/WI to non-secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicd_ipriorityrx_s      cn85xx; */
	/* struct bdk_gicd_ipriorityrx_s      cn88xx; */
} bdk_gicd_ipriorityrx_t;

static inline uint64_t BDK_GICD_IPRIORITYRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_IPRIORITYRX(unsigned long param1)
{
	if ((((param1 >= 8) && (param1 <= 39))))
		return 0x0000801000000400ull + (param1 & 63) * 0x4ull;
	csr_fatal("BDK_GICD_IPRIORITYRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICD_IPRIORITYRX(...) bdk_gicd_ipriorityrx_t
#define bustype_BDK_GICD_IPRIORITYRX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_IPRIORITYRX(p1) (p1)
#define arguments_BDK_GICD_IPRIORITYRX(p1) (p1),-1,-1,-1
#define basename_BDK_GICD_IPRIORITYRX(...) "GICD_IPRIORITYRX"


/**
 * NCB - gicd_irouter#
 *
 * These registers provide the routing information for the security state of the associated SPIs.
 * Up to 64 bits of state to control the routing.
 */
typedef union bdk_gicd_irouterx {
	uint64_t u;
	struct bdk_gicd_irouterx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t a3                          : 8;  /**< RO - Specifies the affinity 3 level for the SPI. In CNXXXX implementation, 0x0. */
		uint64_t irm                         : 1;  /**< R/W - Specifies the interrupt routing mode for the SPI.
                                                                 0 = Route to the processor specified by the affinity levels A3.A2.A1.A0.
                                                                 1 = Route to any one processor in the system (one-of-N). */
		uint64_t reserved_24_30              : 7;
		uint64_t a2                          : 8;  /**< R/W - Specifies the affinity 2 level for the SPI. */
		uint64_t a1                          : 8;  /**< R/W - Specifies the affinity 1 level for the SPI. */
		uint64_t a0                          : 8;  /**< R/W - Specifies the affinity 0 level for the SPI. */
#else
		uint64_t a0                          : 8;
		uint64_t a1                          : 8;
		uint64_t a2                          : 8;
		uint64_t reserved_24_30              : 7;
		uint64_t irm                         : 1;
		uint64_t a3                          : 8;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_gicd_irouterx_s         cn85xx; */
	/* struct bdk_gicd_irouterx_s         cn88xx; */
} bdk_gicd_irouterx_t;

static inline uint64_t BDK_GICD_IROUTERX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_IROUTERX(unsigned long param1)
{
	if ((((param1 >= 32) && (param1 <= 159))))
		return 0x0000801000006000ull + (param1 & 255) * 0x8ull;
	csr_fatal("BDK_GICD_IROUTERX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICD_IROUTERX(...) bdk_gicd_irouterx_t
#define bustype_BDK_GICD_IROUTERX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GICD_IROUTERX(p1) (p1)
#define arguments_BDK_GICD_IROUTERX(p1) (p1),-1,-1,-1
#define basename_BDK_GICD_IROUTERX(...) "GICD_IROUTERX"


/**
 * NCB32b - gicd_isactiver#
 *
 * Each bit in GICD_ISACTIVERn provides a set-active bit for each SPI supported by the GIC.
 * Writing 1 to a set-active bit sets the status of the corresponding SPI to active.
 */
typedef union bdk_gicd_isactiverx {
	uint32_t u;
	struct bdk_gicd_isactiverx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W1S - Each bit corresponds to an SPI for SPI IDs in the range 95..32. If read as 0, then the SPI
                                                                 is not active. If read as 1, the SPI is in active state.
                                                                 Set-active bits corresponding to secure interrupts (either group0 or group1) may only be
                                                                 set by secure accesses.
                                                                 A Set-active bit for a secure SPI is RAZ/WI to non-secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicd_isactiverx_s       cn85xx; */
	/* struct bdk_gicd_isactiverx_s       cn88xx; */
} bdk_gicd_isactiverx_t;

static inline uint64_t BDK_GICD_ISACTIVERX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_ISACTIVERX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 4))))
		return 0x0000801000000300ull + (param1 & 7) * 0x4ull;
	csr_fatal("BDK_GICD_ISACTIVERX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICD_ISACTIVERX(...) bdk_gicd_isactiverx_t
#define bustype_BDK_GICD_ISACTIVERX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_ISACTIVERX(p1) (p1)
#define arguments_BDK_GICD_ISACTIVERX(p1) (p1),-1,-1,-1
#define basename_BDK_GICD_ISACTIVERX(...) "GICD_ISACTIVERX"


/**
 * NCB32b - gicd_isenabler#
 *
 * Each bit in GICD_ISENABLER() provides a set-enable bit for each SPI supported by the GIC.
 * Writing 1 to a set-enable bit enables forwarding of the corresponding SPI from the distributor
 * to the CPU interfaces.
 */
typedef union bdk_gicd_isenablerx {
	uint32_t u;
	struct bdk_gicd_isenablerx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W1S - Each bit corresponds to an SPI for SPI IDs in the range 95..32. If 0, then the SPI is not
                                                                 enabled to be forwarded to the CPU interface. If 1, the SPI is enabled to be forwarded to
                                                                 the CPU interface. Set-enable bits corresponding to secure interrupts (either group0 or
                                                                 Group1) may only be set by secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicd_isenablerx_s       cn85xx; */
	/* struct bdk_gicd_isenablerx_s       cn88xx; */
} bdk_gicd_isenablerx_t;

static inline uint64_t BDK_GICD_ISENABLERX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_ISENABLERX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 4))))
		return 0x0000801000000100ull + (param1 & 7) * 0x4ull;
	csr_fatal("BDK_GICD_ISENABLERX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICD_ISENABLERX(...) bdk_gicd_isenablerx_t
#define bustype_BDK_GICD_ISENABLERX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_ISENABLERX(p1) (p1)
#define arguments_BDK_GICD_ISENABLERX(p1) (p1),-1,-1,-1
#define basename_BDK_GICD_ISENABLERX(...) "GICD_ISENABLERX"


/**
 * NCB32b - gicd_ispendr#
 *
 * Each bit in GICD_ISPENDR() provides a set-pending bit for each SPI supported by the GIC.
 * Writing 1 to a set-pending bit sets the status of the corresponding SPI to pending.
 */
typedef union bdk_gicd_ispendrx {
	uint32_t u;
	struct bdk_gicd_ispendrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W1S - Each bit corresponds to an SPI for SPI IDs in the range 95..32. If read as 0, then the SPI
                                                                 is not pending. If read as 1, the SPI is in pending state.
                                                                 Set-pending bits corresponding to secure interrupts (either group0 or group1) may only be
                                                                 set by secure accesses.
                                                                 A set-pending bit for a secure SPI is RAZ/WI to non-secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicd_ispendrx_s         cn85xx; */
	/* struct bdk_gicd_ispendrx_s         cn88xx; */
} bdk_gicd_ispendrx_t;

static inline uint64_t BDK_GICD_ISPENDRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_ISPENDRX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 4))))
		return 0x0000801000000200ull + (param1 & 7) * 0x4ull;
	csr_fatal("BDK_GICD_ISPENDRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICD_ISPENDRX(...) bdk_gicd_ispendrx_t
#define bustype_BDK_GICD_ISPENDRX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_ISPENDRX(p1) (p1)
#define arguments_BDK_GICD_ISPENDRX(p1) (p1),-1,-1,-1
#define basename_BDK_GICD_ISPENDRX(...) "GICD_ISPENDRX"


/**
 * NCB32b - gicd_nsacr#
 */
typedef union bdk_gicd_nsacrx {
	uint32_t u;
	struct bdk_gicd_nsacrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< SR/W - Two bits per SPI. Defines whether non-secure access is permitted to secure SPI resources.
                                                                 0x0 = No non-secure access is permitted to fields associated with the corresponding SPI.
                                                                 0x1 = Non-secure read and write access is permitted to fields associated with the SPI in
                                                                 GICD_ISPENDR(). A non-secure write access to GICD_SETSPI_NSR is permitted to
                                                                 set the pending state of the corresponding SPI.
                                                                 0x2 = Adds non-secure read and write access permissions to fields associated with the
                                                                 corresponding SPI in GICD_ICPENDR(). A non-secure write access to
                                                                 GICD_CLRSPI_NSR is permitted to clear the pending state of the corresponding SPI. Also
                                                                 adds non-secure read access permission to fields associated with the corresponding SPI in
                                                                 the GICD_ISACTIVER() and GICD_ICACTIVER().
                                                                 0x3 = Adds non-secure read and write access permission to fields associated with the
                                                                 corresponding SPI in GICD_ITARGETSR() and GICD_IROUTER().

                                                                 This register is RAZ/WI for non-secure accesses.
                                                                 When GICD_CTLR[DS] is one, this register is RAZ/WI. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicd_nsacrx_s           cn85xx; */
	/* struct bdk_gicd_nsacrx_s           cn88xx; */
} bdk_gicd_nsacrx_t;

static inline uint64_t BDK_GICD_NSACRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_NSACRX(unsigned long param1)
{
	if ((((param1 >= 2) && (param1 <= 9))))
		return 0x0000801000000E00ull + (param1 & 15) * 0x4ull;
	csr_fatal("BDK_GICD_NSACRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICD_NSACRX(...) bdk_gicd_nsacrx_t
#define bustype_BDK_GICD_NSACRX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_NSACRX(p1) (p1)
#define arguments_BDK_GICD_NSACRX(p1) (p1),-1,-1,-1
#define basename_BDK_GICD_NSACRX(...) "GICD_NSACRX"


/**
 * NCB32b - gicd_pidr0
 */
typedef union bdk_gicd_pidr0 {
	uint32_t u;
	struct bdk_gicd_pidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t partnum0                    : 8;  /**< RO - Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GICD. */
#else
		uint32_t partnum0                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicd_pidr0_s            cn85xx; */
	/* struct bdk_gicd_pidr0_s            cn88xx; */
} bdk_gicd_pidr0_t;

#define BDK_GICD_PIDR0 BDK_GICD_PIDR0_FUNC()
static inline uint64_t BDK_GICD_PIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_PIDR0_FUNC(void)
{
	return 0x000080100000FFE0ull;
}
#define typedef_BDK_GICD_PIDR0 bdk_gicd_pidr0_t
#define bustype_BDK_GICD_PIDR0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_PIDR0 0
#define arguments_BDK_GICD_PIDR0 -1,-1,-1,-1
#define basename_BDK_GICD_PIDR0 "GICD_PIDR0"


/**
 * NCB32b - gicd_pidr1
 */
typedef union bdk_gicd_pidr1 {
	uint32_t u;
	struct bdk_gicd_pidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t idcode                      : 4;  /**< RO - JEP106 identification code <3:0>. Cavium code is 0x4C. */
		uint32_t partnum1                    : 4;  /**< RO - Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else
		uint32_t partnum1                    : 4;
		uint32_t idcode                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicd_pidr1_s            cn85xx; */
	/* struct bdk_gicd_pidr1_s            cn88xx; */
} bdk_gicd_pidr1_t;

#define BDK_GICD_PIDR1 BDK_GICD_PIDR1_FUNC()
static inline uint64_t BDK_GICD_PIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_PIDR1_FUNC(void)
{
	return 0x000080100000FFE4ull;
}
#define typedef_BDK_GICD_PIDR1 bdk_gicd_pidr1_t
#define bustype_BDK_GICD_PIDR1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_PIDR1 0
#define arguments_BDK_GICD_PIDR1 -1,-1,-1,-1
#define basename_BDK_GICD_PIDR1 "GICD_PIDR1"


/**
 * NCB32b - gicd_pidr2
 */
typedef union bdk_gicd_pidr2 {
	uint32_t u;
	struct bdk_gicd_pidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t archrev                     : 4;  /**< RO - Architectural revision. 0x1 = GICv1; 0x2 = GICV2; 0x3 = GICv3; 0x4 = GICv4; 0x5-0xF = Reserved. */
		uint32_t usesjepcode                 : 1;  /**< RO - JEDEC assigned. */
		uint32_t jepid                       : 3;  /**< RO - JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else
		uint32_t jepid                       : 3;
		uint32_t usesjepcode                 : 1;
		uint32_t archrev                     : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicd_pidr2_s            cn85xx; */
	/* struct bdk_gicd_pidr2_s            cn88xx; */
} bdk_gicd_pidr2_t;

#define BDK_GICD_PIDR2 BDK_GICD_PIDR2_FUNC()
static inline uint64_t BDK_GICD_PIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_PIDR2_FUNC(void)
{
	return 0x000080100000FFE8ull;
}
#define typedef_BDK_GICD_PIDR2 bdk_gicd_pidr2_t
#define bustype_BDK_GICD_PIDR2 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_PIDR2 0
#define arguments_BDK_GICD_PIDR2 -1,-1,-1,-1
#define basename_BDK_GICD_PIDR2 "GICD_PIDR2"


/**
 * NCB32b - gicd_pidr3
 */
typedef union bdk_gicd_pidr3 {
	uint32_t u;
	struct bdk_gicd_pidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revand                      : 4;  /**< RO - Manufacturer revision number. For CNXXXX always 0x0. */
		uint32_t cmod                        : 4;  /**< RO - Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else
		uint32_t cmod                        : 4;
		uint32_t revand                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicd_pidr3_s            cn85xx; */
	/* struct bdk_gicd_pidr3_s            cn88xx; */
} bdk_gicd_pidr3_t;

#define BDK_GICD_PIDR3 BDK_GICD_PIDR3_FUNC()
static inline uint64_t BDK_GICD_PIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_PIDR3_FUNC(void)
{
	return 0x000080100000FFECull;
}
#define typedef_BDK_GICD_PIDR3 bdk_gicd_pidr3_t
#define bustype_BDK_GICD_PIDR3 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_PIDR3 0
#define arguments_BDK_GICD_PIDR3 -1,-1,-1,-1
#define basename_BDK_GICD_PIDR3 "GICD_PIDR3"


/**
 * NCB32b - gicd_pidr4
 */
typedef union bdk_gicd_pidr4 {
	uint32_t u;
	struct bdk_gicd_pidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t cnt_4k                      : 4;  /**< RO - This field is 0x4, indicating a 64KB software-visible page. */
		uint32_t continuation_code           : 4;  /**< RO - JEP106 continuation code, least significant nibble. Indicates Cavium. */
#else
		uint32_t continuation_code           : 4;
		uint32_t cnt_4k                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicd_pidr4_s            cn85xx; */
	/* struct bdk_gicd_pidr4_s            cn88xx; */
} bdk_gicd_pidr4_t;

#define BDK_GICD_PIDR4 BDK_GICD_PIDR4_FUNC()
static inline uint64_t BDK_GICD_PIDR4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_PIDR4_FUNC(void)
{
	return 0x000080100000FFD0ull;
}
#define typedef_BDK_GICD_PIDR4 bdk_gicd_pidr4_t
#define bustype_BDK_GICD_PIDR4 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_PIDR4 0
#define arguments_BDK_GICD_PIDR4 -1,-1,-1,-1
#define basename_BDK_GICD_PIDR4 "GICD_PIDR4"


/**
 * NCB32b - gicd_pidr5
 */
typedef union bdk_gicd_pidr5 {
	uint32_t u;
	struct bdk_gicd_pidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gicd_pidr5_s            cn85xx; */
	/* struct bdk_gicd_pidr5_s            cn88xx; */
} bdk_gicd_pidr5_t;

#define BDK_GICD_PIDR5 BDK_GICD_PIDR5_FUNC()
static inline uint64_t BDK_GICD_PIDR5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_PIDR5_FUNC(void)
{
	return 0x000080100000FFD4ull;
}
#define typedef_BDK_GICD_PIDR5 bdk_gicd_pidr5_t
#define bustype_BDK_GICD_PIDR5 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_PIDR5 0
#define arguments_BDK_GICD_PIDR5 -1,-1,-1,-1
#define basename_BDK_GICD_PIDR5 "GICD_PIDR5"


/**
 * NCB32b - gicd_pidr6
 */
typedef union bdk_gicd_pidr6 {
	uint32_t u;
	struct bdk_gicd_pidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gicd_pidr6_s            cn85xx; */
	/* struct bdk_gicd_pidr6_s            cn88xx; */
} bdk_gicd_pidr6_t;

#define BDK_GICD_PIDR6 BDK_GICD_PIDR6_FUNC()
static inline uint64_t BDK_GICD_PIDR6_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_PIDR6_FUNC(void)
{
	return 0x000080100000FFD8ull;
}
#define typedef_BDK_GICD_PIDR6 bdk_gicd_pidr6_t
#define bustype_BDK_GICD_PIDR6 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_PIDR6 0
#define arguments_BDK_GICD_PIDR6 -1,-1,-1,-1
#define basename_BDK_GICD_PIDR6 "GICD_PIDR6"


/**
 * NCB32b - gicd_pidr7
 */
typedef union bdk_gicd_pidr7 {
	uint32_t u;
	struct bdk_gicd_pidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gicd_pidr7_s            cn85xx; */
	/* struct bdk_gicd_pidr7_s            cn88xx; */
} bdk_gicd_pidr7_t;

#define BDK_GICD_PIDR7 BDK_GICD_PIDR7_FUNC()
static inline uint64_t BDK_GICD_PIDR7_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_PIDR7_FUNC(void)
{
	return 0x000080100000FFDCull;
}
#define typedef_BDK_GICD_PIDR7 bdk_gicd_pidr7_t
#define bustype_BDK_GICD_PIDR7 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_PIDR7 0
#define arguments_BDK_GICD_PIDR7 -1,-1,-1,-1
#define basename_BDK_GICD_PIDR7 "GICD_PIDR7"


/**
 * NCB32b - gicd_sctlr
 *
 * Controls the behavior of the distributor.
 *
 */
typedef union bdk_gicd_sctlr {
	uint32_t u;
	struct bdk_gicd_sctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t rwp                         : 1;  /**< RO/H - Register write pending.
                                                                 Indicates whether a register write is in progress.
                                                                 0 = The effects of all register writes are visible to all descendants of the top-level re-
                                                                 distributor, including processors.
                                                                 1 = The effects of all register writes are not visible to all descendants of the top-level
                                                                 re-distributor.

                                                                 Note: this field tracks completion of writes to GICD_(S)CTLR that change the state of an
                                                                 interrupt group enable or an affinity routing setting and writes to GICD_ICENABLER() that
                                                                 clear the enable of one or more SPIs. */
		uint32_t reserved_7_30               : 24;
		uint32_t ds                          : 1;  /**< SR/W - Disable security.
                                                                 When set, non-secure accesses are permitted to access and modify registers that control
                                                                 Group 0 interrupts. Resets to zero.

                                                                 Note if DS becomes one when ARE_S is one, then ARE for the single security state is
                                                                 RAO/WI.

                                                                 Note this bit is RAO/WI if the distributor only supports a single security state (see
                                                                 below).

                                                                 Note when DS is set, all accesses to GICD_CTLR access the single security state view
                                                                 (below) and all bits are accessible

                                                                 Note once set, DS may only be clear by a hardware reset. */
		uint32_t are_ns                      : 1;  /**< SRO - Enable affinity routing for the non-secure state when set.
                                                                 In CNXXXX this bit is always 1 as only affinity routing is supported.
                                                                 Note: this bit is RAO/WI when ARE is one for the secure state. */
		uint32_t are_sns                     : 1;  /**< RO - Enables affinity routing for the non-secure state.
                                                                 This field is fixed as RAO/WI for CNXXXX for both secure and non secure state. */
		uint32_t reserved_3_3                : 1;
		uint32_t enable_g1s                  : 1;  /**< SR/W - Enables secure group 1 interrupts.
                                                                 0 = Disable G1S Interrupts.
                                                                 1 = Enable G1S Interrupts. */
		uint32_t enable_g1ns                 : 1;  /**< R/W - S - Enables non-secure group 1 interrupts. Behaves as defined for GICv2. This
                                                                 enable also controls whether LPIs are forwarded to processors. When written
                                                                 to zero, the RWP bit indicates whether the effects of this enable on LPIs
                                                                 have been made visible.

                                                                 NS - This field is called ENABLE_G1A. It enables non-secure group 1 interrupts. */
		uint32_t enable_g0                   : 1;  /**< SR/W - Secure view or DS field is set -- Enable/disable group 0 interrupts.
                                                                 0 = Disable G0 interrupts.
                                                                 1 = Enable G0 interrupts.

                                                                 Non-Secure view -- RES0 for CNXXXX since ARE_NS is RAO. */
#else
		uint32_t enable_g0                   : 1;
		uint32_t enable_g1ns                 : 1;
		uint32_t enable_g1s                  : 1;
		uint32_t reserved_3_3                : 1;
		uint32_t are_sns                     : 1;
		uint32_t are_ns                      : 1;
		uint32_t ds                          : 1;
		uint32_t reserved_7_30               : 24;
		uint32_t rwp                         : 1;
#endif
	} s;
	/* struct bdk_gicd_sctlr_s            cn85xx; */
	/* struct bdk_gicd_sctlr_s            cn88xx; */
} bdk_gicd_sctlr_t;

#define BDK_GICD_SCTLR BDK_GICD_SCTLR_FUNC()
static inline uint64_t BDK_GICD_SCTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_SCTLR_FUNC(void)
{
	return 0x0000801000000000ull;
}
#define typedef_BDK_GICD_SCTLR bdk_gicd_sctlr_t
#define bustype_BDK_GICD_SCTLR BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_SCTLR 0
#define arguments_BDK_GICD_SCTLR -1,-1,-1,-1
#define basename_BDK_GICD_SCTLR "GICD_SCTLR"


/**
 * NCB32b - gicd_setspi_nsr
 */
typedef union bdk_gicd_setspi_nsr {
	uint32_t u;
	struct bdk_gicd_setspi_nsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_10_31              : 22;
		uint32_t spi_id                      : 10; /**< WO - Set an SPI to pending (write-only). If the SPI is already pending, then the write has no
                                                                 effect.
                                                                 If the SPI ID is invalid, then the write has no effect.
                                                                 If the register is written using a non-secure access and the value specifies a secure SPI
                                                                 and the value of the corresponding GICD_NSACR() register is zero (ie. does not permit non-
                                                                 secure accesses to set the interrupt as pending), the write has no effect. */
#else
		uint32_t spi_id                      : 10;
		uint32_t reserved_10_31              : 22;
#endif
	} s;
	/* struct bdk_gicd_setspi_nsr_s       cn85xx; */
	/* struct bdk_gicd_setspi_nsr_s       cn88xx; */
} bdk_gicd_setspi_nsr_t;

#define BDK_GICD_SETSPI_NSR BDK_GICD_SETSPI_NSR_FUNC()
static inline uint64_t BDK_GICD_SETSPI_NSR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_SETSPI_NSR_FUNC(void)
{
	return 0x0000801000000040ull;
}
#define typedef_BDK_GICD_SETSPI_NSR bdk_gicd_setspi_nsr_t
#define bustype_BDK_GICD_SETSPI_NSR BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_SETSPI_NSR 0
#define arguments_BDK_GICD_SETSPI_NSR -1,-1,-1,-1
#define basename_BDK_GICD_SETSPI_NSR "GICD_SETSPI_NSR"


/**
 * NCB32b - gicd_setspi_sr
 */
typedef union bdk_gicd_setspi_sr {
	uint32_t u;
	struct bdk_gicd_setspi_sr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_10_31              : 22;
		uint32_t spi_id                      : 10; /**< SWO - Set an SPI to pending (write-only). If the SPI is already pending, then the write has no
                                                                 effect.
                                                                 If the SPI ID is invalid, then the write has no effect.
                                                                 If the register is written using a non-secure access, the write has no effect. */
#else
		uint32_t spi_id                      : 10;
		uint32_t reserved_10_31              : 22;
#endif
	} s;
	/* struct bdk_gicd_setspi_sr_s        cn85xx; */
	/* struct bdk_gicd_setspi_sr_s        cn88xx; */
} bdk_gicd_setspi_sr_t;

#define BDK_GICD_SETSPI_SR BDK_GICD_SETSPI_SR_FUNC()
static inline uint64_t BDK_GICD_SETSPI_SR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_SETSPI_SR_FUNC(void)
{
	return 0x0000801000000050ull;
}
#define typedef_BDK_GICD_SETSPI_SR bdk_gicd_setspi_sr_t
#define bustype_BDK_GICD_SETSPI_SR BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_SETSPI_SR 0
#define arguments_BDK_GICD_SETSPI_SR -1,-1,-1,-1
#define basename_BDK_GICD_SETSPI_SR "GICD_SETSPI_SR"


/**
 * NCB32b - gicd_sstatusr
 */
typedef union bdk_gicd_sstatusr {
	uint32_t u;
	struct bdk_gicd_sstatusr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_4_31               : 28;
		uint32_t wrod                        : 1;  /**< R/W - This bit is set if a write to a read-only location is detected. Software must write a one
                                                                 to this bit to clear it. */
		uint32_t rwod                        : 1;  /**< R/W - This bit is set if a read to a write-only location is detected. Software must write a one
                                                                 to this bit to clear it. */
		uint32_t wrd                         : 1;  /**< R/W - This bit is set if a write to a reserved location is detected. Software must write a one
                                                                 to this bit to clear it. */
		uint32_t rrd                         : 1;  /**< R/W - This bit is set if a read to a reserved location is detected. Software must write a one to
                                                                 this bit to clear it. */
#else
		uint32_t rrd                         : 1;
		uint32_t wrd                         : 1;
		uint32_t rwod                        : 1;
		uint32_t wrod                        : 1;
		uint32_t reserved_4_31               : 28;
#endif
	} s;
	/* struct bdk_gicd_sstatusr_s         cn85xx; */
	/* struct bdk_gicd_sstatusr_s         cn88xx; */
} bdk_gicd_sstatusr_t;

#define BDK_GICD_SSTATUSR BDK_GICD_SSTATUSR_FUNC()
static inline uint64_t BDK_GICD_SSTATUSR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_SSTATUSR_FUNC(void)
{
	return 0x0000801000000010ull;
}
#define typedef_BDK_GICD_SSTATUSR bdk_gicd_sstatusr_t
#define bustype_BDK_GICD_SSTATUSR BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_SSTATUSR 0
#define arguments_BDK_GICD_SSTATUSR -1,-1,-1,-1
#define basename_BDK_GICD_SSTATUSR "GICD_SSTATUSR"


/**
 * NCB32b - gicd_typer
 *
 * Describes features supported by the distributor.
 *
 */
typedef union bdk_gicd_typer {
	uint32_t u;
	struct bdk_gicd_typer_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_25_31              : 7;
		uint32_t a3v                         : 1;  /**< RO - Indicates whether the distributor supports non-zero values of affinity 3. */
		uint32_t idbits                      : 5;  /**< RO - The number of interrupt identifier bits supported by the GIC Stream protocol interface minus one. */
		uint32_t dvis                        : 1;  /**< RO - Direct virtual LPI injection supported. */
		uint32_t lpis                        : 1;  /**< RO - Locality-specific peripheral interrupt supported. */
		uint32_t mbis                        : 1;  /**< RO - Message based interrupt supported. */
		uint32_t lspi                        : 5;  /**< RO - The number of lockable SPI interrupts. This is not supported in GICv3 and is RES0. */
		uint32_t securityextn                : 1;  /**< RO - Security extension supported. When GICD_CTLR[DS] is
                                                                 set, this field is RAZ. */
		uint32_t reserved_8_9                : 2;
		uint32_t cpunumber                   : 3;  /**< RO - Reserved. In CNXXXX implementation, not used. */
		uint32_t itlinesnumber               : 5;  /**< RO - The value derived from this specifies the maximum numer of SPIs. */
#else
		uint32_t itlinesnumber               : 5;
		uint32_t cpunumber                   : 3;
		uint32_t reserved_8_9                : 2;
		uint32_t securityextn                : 1;
		uint32_t lspi                        : 5;
		uint32_t mbis                        : 1;
		uint32_t lpis                        : 1;
		uint32_t dvis                        : 1;
		uint32_t idbits                      : 5;
		uint32_t a3v                         : 1;
		uint32_t reserved_25_31              : 7;
#endif
	} s;
	/* struct bdk_gicd_typer_s            cn85xx; */
	/* struct bdk_gicd_typer_s            cn88xx; */
} bdk_gicd_typer_t;

#define BDK_GICD_TYPER BDK_GICD_TYPER_FUNC()
static inline uint64_t BDK_GICD_TYPER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICD_TYPER_FUNC(void)
{
	return 0x0000801000000004ull;
}
#define typedef_BDK_GICD_TYPER bdk_gicd_typer_t
#define bustype_BDK_GICD_TYPER BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICD_TYPER 0
#define arguments_BDK_GICD_TYPER -1,-1,-1,-1
#define basename_BDK_GICD_TYPER "GICD_TYPER"


/**
 * NCB32b - gicr#_cidr0
 */
typedef union bdk_gicrx_cidr0 {
	uint32_t u;
	struct bdk_gicrx_cidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicrx_cidr0_s           cn85xx; */
	/* struct bdk_gicrx_cidr0_s           cn88xx; */
} bdk_gicrx_cidr0_t;

static inline uint64_t BDK_GICRX_CIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_CIDR0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000080108000FFF0ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_CIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_CIDR0(...) bdk_gicrx_cidr0_t
#define bustype_BDK_GICRX_CIDR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_CIDR0(p1) (p1)
#define arguments_BDK_GICRX_CIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_CIDR0(...) "GICRX_CIDR0"


/**
 * NCB32b - gicr#_cidr1
 */
typedef union bdk_gicrx_cidr1 {
	uint32_t u;
	struct bdk_gicrx_cidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicrx_cidr1_s           cn85xx; */
	/* struct bdk_gicrx_cidr1_s           cn88xx; */
} bdk_gicrx_cidr1_t;

static inline uint64_t BDK_GICRX_CIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_CIDR1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000080108000FFF4ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_CIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_CIDR1(...) bdk_gicrx_cidr1_t
#define bustype_BDK_GICRX_CIDR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_CIDR1(p1) (p1)
#define arguments_BDK_GICRX_CIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_CIDR1(...) "GICRX_CIDR1"


/**
 * NCB32b - gicr#_cidr2
 */
typedef union bdk_gicrx_cidr2 {
	uint32_t u;
	struct bdk_gicrx_cidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicrx_cidr2_s           cn85xx; */
	/* struct bdk_gicrx_cidr2_s           cn88xx; */
} bdk_gicrx_cidr2_t;

static inline uint64_t BDK_GICRX_CIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_CIDR2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000080108000FFF8ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_CIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_CIDR2(...) bdk_gicrx_cidr2_t
#define bustype_BDK_GICRX_CIDR2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_CIDR2(p1) (p1)
#define arguments_BDK_GICRX_CIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_CIDR2(...) "GICRX_CIDR2"


/**
 * NCB32b - gicr#_cidr3
 */
typedef union bdk_gicrx_cidr3 {
	uint32_t u;
	struct bdk_gicrx_cidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicrx_cidr3_s           cn85xx; */
	/* struct bdk_gicrx_cidr3_s           cn88xx; */
} bdk_gicrx_cidr3_t;

static inline uint64_t BDK_GICRX_CIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_CIDR3(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000080108000FFFCull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_CIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_CIDR3(...) bdk_gicrx_cidr3_t
#define bustype_BDK_GICRX_CIDR3(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_CIDR3(p1) (p1)
#define arguments_BDK_GICRX_CIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_CIDR3(...) "GICRX_CIDR3"


/**
 * NCB - gicr#_clrlpir
 */
typedef union bdk_gicrx_clrlpir {
	uint64_t u;
	struct bdk_gicrx_clrlpir_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t pid                         : 32; /**< WO - Physical ID of the LPI to be set as not pending. If the LPI is already not pending, the
                                                                 write has no effect.
                                                                 If the LPI with the physical ID is not implemented, the write has no effect.
                                                                 If GICR_CTLR[ENABLE_LPI]s is zero, the write has no effect. */
#else
		uint64_t pid                         : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_gicrx_clrlpir_s         cn85xx; */
	/* struct bdk_gicrx_clrlpir_s         cn88xx; */
} bdk_gicrx_clrlpir_t;

static inline uint64_t BDK_GICRX_CLRLPIR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_CLRLPIR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080000048ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_CLRLPIR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_CLRLPIR(...) bdk_gicrx_clrlpir_t
#define bustype_BDK_GICRX_CLRLPIR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GICRX_CLRLPIR(p1) (p1)
#define arguments_BDK_GICRX_CLRLPIR(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_CLRLPIR(...) "GICRX_CLRLPIR"


/**
 * NCB32b - gicr#_icactiver0
 *
 * Each bit in GICR_ICACTIVER0 provides a clear-active bit for an SGI or a PPI. Writing 1 to a
 * Clear-active bit clears the active status of the corresponding interrupt.
 */
typedef union bdk_gicrx_icactiver0 {
	uint32_t u;
	struct bdk_gicrx_icactiver0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W1C - Each bit corresponds to an SGI or a PPI for interrupt IDs in the range 31..0. If read as
                                                                 0, then the interrupt is not active. If read as 1, the interrupt is in active state.
                                                                 Clear-active bits corresponding to secure interrupts (either group0 or group1) may only be
                                                                 set by secure accesses.
                                                                 A clear-active bit for a secure interrupt is RAZ/WI to non-secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicrx_icactiver0_s      cn85xx; */
	/* struct bdk_gicrx_icactiver0_s      cn88xx; */
} bdk_gicrx_icactiver0_t;

static inline uint64_t BDK_GICRX_ICACTIVER0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_ICACTIVER0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080010380ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_ICACTIVER0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_ICACTIVER0(...) bdk_gicrx_icactiver0_t
#define bustype_BDK_GICRX_ICACTIVER0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_ICACTIVER0(p1) (p1)
#define arguments_BDK_GICRX_ICACTIVER0(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_ICACTIVER0(...) "GICRX_ICACTIVER0"


/**
 * NCB32b - gicr#_icenabler0
 *
 * Each bit in GICR_ICENABLER0 provides a clear-enable bit for an SGI or a PPI. Writing 1 to a
 * clear-enable bit disables forwarding of the corresponding SGI or PPI from the redistributor
 * to the CPU interfaces. Reading a bit identifies whether the interrupt is enabled.
 */
typedef union bdk_gicrx_icenabler0 {
	uint32_t u;
	struct bdk_gicrx_icenabler0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W1C - Each bit corresponds to an SGI or PPI for interrupt IDs in the range 31..0. Upon reading,
                                                                 if a bit is 0, then the interrupt is not enabled to be forwarded to the CPU interface.
                                                                 Upon reading, if a bit is 1, the SPI is enabled to be forwarded to the CPU interface.
                                                                 Clear-enable bits corresponding to secure interrupts (either group0 or group1) may only be
                                                                 set by secure accesses.

                                                                 Writes to the register cannot be considered complete until the effects of the write are
                                                                 visible throughout the affinity hierarchy. To ensure that an enable has been cleared,
                                                                 software must write to this register with bits set to clear the required enables. Software
                                                                 must then poll GICR_CTLR[RWP] (register writes pending) until it has the value zero. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicrx_icenabler0_s      cn85xx; */
	/* struct bdk_gicrx_icenabler0_s      cn88xx; */
} bdk_gicrx_icenabler0_t;

static inline uint64_t BDK_GICRX_ICENABLER0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_ICENABLER0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080010180ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_ICENABLER0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_ICENABLER0(...) bdk_gicrx_icenabler0_t
#define bustype_BDK_GICRX_ICENABLER0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_ICENABLER0(p1) (p1)
#define arguments_BDK_GICRX_ICENABLER0(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_ICENABLER0(...) "GICRX_ICENABLER0"


/**
 * NCB32b - gicr#_icfgr0
 */
typedef union bdk_gicrx_icfgr0 {
	uint32_t u;
	struct bdk_gicrx_icfgr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< RO - Two bits per SGI. Defines whether an SGI is level-sensitive or edge-triggered.
                                                                 Note SGIs are always edge-triggered, so Bit[1] for an SGI is RAO and read-only.

                                                                 Bit[1] is 0, the interrupt is level-sensitive.

                                                                 Bit[1] is 1, the interrupt is edge-triggered.

                                                                 Bit[0] Reserved.

                                                                 If a secure interrupt, then its corresponding field is RAZ/WI to non-secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicrx_icfgr0_s          cn85xx; */
	/* struct bdk_gicrx_icfgr0_s          cn88xx; */
} bdk_gicrx_icfgr0_t;

static inline uint64_t BDK_GICRX_ICFGR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_ICFGR0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080010C00ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_ICFGR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_ICFGR0(...) bdk_gicrx_icfgr0_t
#define bustype_BDK_GICRX_ICFGR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_ICFGR0(p1) (p1)
#define arguments_BDK_GICRX_ICFGR0(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_ICFGR0(...) "GICRX_ICFGR0"


/**
 * NCB32b - gicr#_icfgr1
 *
 * Redistributor Interrupt Configuration Register 1.
 *
 */
typedef union bdk_gicrx_icfgr1 {
	uint32_t u;
	struct bdk_gicrx_icfgr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< RO - Two bits per PPI. Defines whether an PPI is level-sensitive or edge-triggered.

                                                                 Bit[1] is 0, the interrupt is level-sensitive.

                                                                 Bit[1] is 1, the interrupt is edge-triggered.

                                                                 Bit[0] Reserved.

                                                                 If a secure interrupt, then its corresponding field is RAZ/WI to non-secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicrx_icfgr1_s          cn85xx; */
	/* struct bdk_gicrx_icfgr1_s          cn88xx; */
} bdk_gicrx_icfgr1_t;

static inline uint64_t BDK_GICRX_ICFGR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_ICFGR1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080010C04ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_ICFGR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_ICFGR1(...) bdk_gicrx_icfgr1_t
#define bustype_BDK_GICRX_ICFGR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_ICFGR1(p1) (p1)
#define arguments_BDK_GICRX_ICFGR1(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_ICFGR1(...) "GICRX_ICFGR1"


/**
 * NCB32b - gicr#_icpendr0
 *
 * Each bit in GICR_ICPENDR0 provides a clear-pending bit for an SGI or a PPI. Writing 1 to a
 * Clear-pending bit clears the pending status of the corresponding interrupt.
 */
typedef union bdk_gicrx_icpendr0 {
	uint32_t u;
	struct bdk_gicrx_icpendr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W1C - Each bit corresponds to an SGI or a PPI for interrupt IDs in the range 31..0. If read as
                                                                 0, then the interrupt is not pending. If read as 1, the interrupt is in pending state.
                                                                 Clear-pending bits corresponding to secure interrupts (either group0 or group1) may only
                                                                 be set by secure accesses.
                                                                 A clear-pending bit for a secure interrupt is RAZ/WI to non-secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicrx_icpendr0_s        cn85xx; */
	/* struct bdk_gicrx_icpendr0_s        cn88xx; */
} bdk_gicrx_icpendr0_t;

static inline uint64_t BDK_GICRX_ICPENDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_ICPENDR0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080010280ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_ICPENDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_ICPENDR0(...) bdk_gicrx_icpendr0_t
#define bustype_BDK_GICRX_ICPENDR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_ICPENDR0(p1) (p1)
#define arguments_BDK_GICRX_ICPENDR0(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_ICPENDR0(...) "GICRX_ICPENDR0"


/**
 * NCB32b - gicr#_igroupr0
 */
typedef union bdk_gicrx_igroupr0 {
	uint32_t u;
	struct bdk_gicrx_igroupr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ppi                         : 16; /**< SR/W - Groups for PPIs.
                                                                 0 = Group 0.
                                                                 1 = Group 1. */
		uint32_t sgi                         : 16; /**< SR/W - Groups for SGIs.
                                                                 0 = Group 0.
                                                                 1 = Group 1. */
#else
		uint32_t sgi                         : 16;
		uint32_t ppi                         : 16;
#endif
	} s;
	/* struct bdk_gicrx_igroupr0_s        cn85xx; */
	/* struct bdk_gicrx_igroupr0_s        cn88xx; */
} bdk_gicrx_igroupr0_t;

static inline uint64_t BDK_GICRX_IGROUPR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_IGROUPR0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080010080ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_IGROUPR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_IGROUPR0(...) bdk_gicrx_igroupr0_t
#define bustype_BDK_GICRX_IGROUPR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_IGROUPR0(p1) (p1)
#define arguments_BDK_GICRX_IGROUPR0(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_IGROUPR0(...) "GICRX_IGROUPR0"


/**
 * NCB32b - gicr#_igrpmodr0
 *
 * Control the group modifier for PPIs and SGIs, similar to GICD_IGRPMODR() for SPIs.
 *
 */
typedef union bdk_gicrx_igrpmodr0 {
	uint32_t u;
	struct bdk_gicrx_igrpmodr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ppi                         : 16; /**< SR/W - Group modifiers for PPIs.
                                                                 0 = No group modification.
                                                                 1 = Modify to group 1. */
		uint32_t sgi                         : 16; /**< SR/W - Group modifiers for SGIs.
                                                                 0 = No group modification.
                                                                 1 = Modify to group 1. */
#else
		uint32_t sgi                         : 16;
		uint32_t ppi                         : 16;
#endif
	} s;
	/* struct bdk_gicrx_igrpmodr0_s       cn85xx; */
	/* struct bdk_gicrx_igrpmodr0_s       cn88xx; */
} bdk_gicrx_igrpmodr0_t;

static inline uint64_t BDK_GICRX_IGRPMODR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_IGRPMODR0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080010D00ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_IGRPMODR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_IGRPMODR0(...) bdk_gicrx_igrpmodr0_t
#define bustype_BDK_GICRX_IGRPMODR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_IGRPMODR0(p1) (p1)
#define arguments_BDK_GICRX_IGRPMODR0(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_IGRPMODR0(...) "GICRX_IGRPMODR0"


/**
 * NCB32b - gicr#_iidr
 *
 * This 32-bit register is read-only and specifies the version and features supported by the
 * Redistributor.
 */
typedef union bdk_gicrx_iidr {
	uint32_t u;
	struct bdk_gicrx_iidr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t productid                   : 8;  /**< RO - An implementation defined product number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN88XX. */
		uint32_t reserved_20_23              : 4;
		uint32_t variant                     : 4;  /**< RO - Indicates the major revision or variant of the product.
                                                                 In CNXXXX, the major pass number. */
		uint32_t revision                    : 4;  /**< RO - Indicates the minor revision of the product.
                                                                 In CNXXXX, the minor pass number. */
		uint32_t implementer                 : 12; /**< RO - Indicates the implementer:
                                                                 0x34C = Cavium. */
#else
		uint32_t implementer                 : 12;
		uint32_t revision                    : 4;
		uint32_t variant                     : 4;
		uint32_t reserved_20_23              : 4;
		uint32_t productid                   : 8;
#endif
	} s;
	/* struct bdk_gicrx_iidr_s            cn85xx; */
	/* struct bdk_gicrx_iidr_s            cn88xx; */
} bdk_gicrx_iidr_t;

static inline uint64_t BDK_GICRX_IIDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_IIDR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080000004ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_IIDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_IIDR(...) bdk_gicrx_iidr_t
#define bustype_BDK_GICRX_IIDR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_IIDR(p1) (p1)
#define arguments_BDK_GICRX_IIDR(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_IIDR(...) "GICRX_IIDR"


/**
 * NCB - gicr#_invallr
 *
 * this register is write-only and causes the LPI configuration to be reloaded from the table in
 * memory.
 */
typedef union bdk_gicrx_invallr {
	uint64_t u;
	struct bdk_gicrx_invallr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_gicrx_invallr_s         cn85xx; */
	/* struct bdk_gicrx_invallr_s         cn88xx; */
} bdk_gicrx_invallr_t;

static inline uint64_t BDK_GICRX_INVALLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_INVALLR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x00008010800000B0ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_INVALLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_INVALLR(...) bdk_gicrx_invallr_t
#define bustype_BDK_GICRX_INVALLR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GICRX_INVALLR(p1) (p1)
#define arguments_BDK_GICRX_INVALLR(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_INVALLR(...) "GICRX_INVALLR"


/**
 * NCB - gicr#_invlpir
 */
typedef union bdk_gicrx_invlpir {
	uint64_t u;
	struct bdk_gicrx_invlpir_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t pid                         : 32; /**< WO - Physical LPI ID to be cleaned. The invalidate in the register name and the ITS command is
                                                                 a misnomer. This actually results in a clean operation wherein the cached (in the
                                                                 redistributor) pending state of the LPI is updated to the pending table held in memory and
                                                                 its cached configuration is invalidated in the cache. */
#else
		uint64_t pid                         : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_gicrx_invlpir_s         cn85xx; */
	/* struct bdk_gicrx_invlpir_s         cn88xx; */
} bdk_gicrx_invlpir_t;

static inline uint64_t BDK_GICRX_INVLPIR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_INVLPIR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x00008010800000A0ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_INVLPIR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_INVLPIR(...) bdk_gicrx_invlpir_t
#define bustype_BDK_GICRX_INVLPIR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GICRX_INVLPIR(p1) (p1)
#define arguments_BDK_GICRX_INVLPIR(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_INVLPIR(...) "GICRX_INVLPIR"


/**
 * NCB32b - gicr#_ipriorityr#
 *
 * Each byte in GICR_IPRIORITYR0 provides a priority field for each SGI or PPI supported by the
 * GIC.
 */
typedef union bdk_gicrx_ipriorityrx {
	uint32_t u;
	struct bdk_gicrx_ipriorityrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W - Each byte corresponds to an SGI or PPI for interrupt IDs in the range 31..0.
                                                                 Priority fields corresponding to secure interrupts (either group0 or group1) may only be
                                                                 set by secure accesses, or when GICD_CTLR[DS] is one.
                                                                 Byte accesses are permitted to these registers.
                                                                 A priority field for a secure interrupt is RAZ/WI to non-secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicrx_ipriorityrx_s     cn85xx; */
	/* struct bdk_gicrx_ipriorityrx_s     cn88xx; */
} bdk_gicrx_ipriorityrx_t;

static inline uint64_t BDK_GICRX_IPRIORITYRX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_IPRIORITYRX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 47)) && ((param2 <= 7)))
		return 0x0000801080010400ull + (param1 & 63) * 0x20000ull + (param2 & 7) * 0x4ull;
	csr_fatal("BDK_GICRX_IPRIORITYRX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_IPRIORITYRX(...) bdk_gicrx_ipriorityrx_t
#define bustype_BDK_GICRX_IPRIORITYRX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_IPRIORITYRX(p1,p2) (p1)
#define arguments_BDK_GICRX_IPRIORITYRX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GICRX_IPRIORITYRX(...) "GICRX_IPRIORITYRX"


/**
 * NCB32b - gicr#_isactiver0
 *
 * Each bit in GICR_ISACTIVER0 provides a set-active bit for an SGI or a PPI. Writing 1 to a
 * set-active bit sets the status of the corresponding interrupt to active.
 */
typedef union bdk_gicrx_isactiver0 {
	uint32_t u;
	struct bdk_gicrx_isactiver0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W1S - Each bit corresponds to an SGI or PPI for interrupt IDs in the range 31..0. If read as 0,
                                                                 then the interrupt is not active. If read as 1, the interrupt is in active state.
                                                                 Set-active bits corresponding to secure interrupts (either group0 or group1) may only be
                                                                 set by secure accesses.
                                                                 A set-active bit for a secure interrupt is RAZ/WI to non-secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicrx_isactiver0_s      cn85xx; */
	/* struct bdk_gicrx_isactiver0_s      cn88xx; */
} bdk_gicrx_isactiver0_t;

static inline uint64_t BDK_GICRX_ISACTIVER0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_ISACTIVER0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080010300ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_ISACTIVER0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_ISACTIVER0(...) bdk_gicrx_isactiver0_t
#define bustype_BDK_GICRX_ISACTIVER0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_ISACTIVER0(p1) (p1)
#define arguments_BDK_GICRX_ISACTIVER0(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_ISACTIVER0(...) "GICRX_ISACTIVER0"


/**
 * NCB32b - gicr#_isenabler0
 *
 * Each bit in GICR_ISENABLER0 provides a set-enable bit for an SGI or a PPI. Writing 1
 * to a set-enable bit enables forwarding of the corresponding SGI or PPI from the
 * redistributor to the CPU interfaces.
 */
typedef union bdk_gicrx_isenabler0 {
	uint32_t u;
	struct bdk_gicrx_isenabler0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W1S - Each bit corresponds to an SGI or PPI for interrupt IDs in the range 31..0. If 0, then the
                                                                 interrupt is not enabled to be forwarded to the CPU interface. If 1, the interrupt is
                                                                 enabled to be forwarded to the CPU interface. Set-enable bits corresponding to secure
                                                                 interrupts (either group0 or group1) may only be set by secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicrx_isenabler0_s      cn85xx; */
	/* struct bdk_gicrx_isenabler0_s      cn88xx; */
} bdk_gicrx_isenabler0_t;

static inline uint64_t BDK_GICRX_ISENABLER0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_ISENABLER0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080010100ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_ISENABLER0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_ISENABLER0(...) bdk_gicrx_isenabler0_t
#define bustype_BDK_GICRX_ISENABLER0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_ISENABLER0(p1) (p1)
#define arguments_BDK_GICRX_ISENABLER0(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_ISENABLER0(...) "GICRX_ISENABLER0"


/**
 * NCB32b - gicr#_ispendr0
 *
 * Each bit in GICR_ISPENDR0 provides a set-pending bit for an SGI or a PPI. Writing 1
 * to a set-pending bit sets the status of the corresponding interrupt to pending.
 */
typedef union bdk_gicrx_ispendr0 {
	uint32_t u;
	struct bdk_gicrx_ispendr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< R/W1S - Each bit corresponds to an SGI or PPI for interrupt IDs in the range 31..0. If read as 0,
                                                                 then the interrupt is not pending. If read as 1, the interrupt is in pending state.
                                                                 Set-pending bits corresponding to secure interrupts (either group0 or group1) may only be
                                                                 set by secure accesses.
                                                                 A set-pending bit for a secure interrupt is RAZ/WI to non-secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicrx_ispendr0_s        cn85xx; */
	/* struct bdk_gicrx_ispendr0_s        cn88xx; */
} bdk_gicrx_ispendr0_t;

static inline uint64_t BDK_GICRX_ISPENDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_ISPENDR0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080010200ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_ISPENDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_ISPENDR0(...) bdk_gicrx_ispendr0_t
#define bustype_BDK_GICRX_ISPENDR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_ISPENDR0(p1) (p1)
#define arguments_BDK_GICRX_ISPENDR0(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_ISPENDR0(...) "GICRX_ISPENDR0"


/**
 * NCB - gicr#_movallr
 *
 * This register is write-only and causes the LPI configuration to be reloaded from the table in
 * memory.
 */
typedef union bdk_gicrx_movallr {
	uint64_t u;
	struct bdk_gicrx_movallr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pa                          : 32; /**< WO - Target address <47:16>. Base address of the redistributor to which pending LPIs are to be
                                                                 moved.
                                                                 If GICR_CTLR[ENABLE_LPIS] is zero, the write has no effect. */
		uint64_t reserved_0_31               : 32;
#else
		uint64_t reserved_0_31               : 32;
		uint64_t pa                          : 32;
#endif
	} s;
	/* struct bdk_gicrx_movallr_s         cn85xx; */
	/* struct bdk_gicrx_movallr_s         cn88xx; */
} bdk_gicrx_movallr_t;

static inline uint64_t BDK_GICRX_MOVALLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_MOVALLR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080000110ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_MOVALLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_MOVALLR(...) bdk_gicrx_movallr_t
#define bustype_BDK_GICRX_MOVALLR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GICRX_MOVALLR(p1) (p1)
#define arguments_BDK_GICRX_MOVALLR(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_MOVALLR(...) "GICRX_MOVALLR"


/**
 * NCB - gicr#_movlpir
 */
typedef union bdk_gicrx_movlpir {
	uint64_t u;
	struct bdk_gicrx_movlpir_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pa                          : 32; /**< WO - Target address <47:16>. Base address of the redistributor to which the physical LPI is to
                                                                 be moved. */
		uint64_t pid                         : 32; /**< WO - Physical LPI ID to be moved to the redistributor at [PA]. If the LPI with this
                                                                 PID is unimplemented, the write has no effect.
                                                                 If GICR_CTLR[ENABLE_LPIS] is zero, the write has no effect. */
#else
		uint64_t pid                         : 32;
		uint64_t pa                          : 32;
#endif
	} s;
	/* struct bdk_gicrx_movlpir_s         cn85xx; */
	/* struct bdk_gicrx_movlpir_s         cn88xx; */
} bdk_gicrx_movlpir_t;

static inline uint64_t BDK_GICRX_MOVLPIR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_MOVLPIR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080000100ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_MOVLPIR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_MOVLPIR(...) bdk_gicrx_movlpir_t
#define bustype_BDK_GICRX_MOVLPIR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GICRX_MOVLPIR(p1) (p1)
#define arguments_BDK_GICRX_MOVLPIR(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_MOVLPIR(...) "GICRX_MOVLPIR"


/**
 * NCB32b - gicr#_nsacr
 */
typedef union bdk_gicrx_nsacr {
	uint32_t u;
	struct bdk_gicrx_nsacr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< SR/W - Two bits per SGI or PPI. Defines whether non-secure access is permitted to secure
                                                                 interrupt resources.
                                                                 0x0 = No non-secure access is permitted to fields associated with the corresponding
                                                                 interrupt.
                                                                 0x1 = Non-secure write access is permitted to generate secure group0 interrupts.
                                                                 0x2 = Adds non-secure write access permissions to generate secure group1 interrupts.
                                                                 0x3 = Reserved. Treated as 0x1.

                                                                 This register is RAZ/WI for non-secure accesses.
                                                                 When GICD_CTLR[DS] is one, this register is RAZ/WI. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicrx_nsacr_s           cn85xx; */
	/* struct bdk_gicrx_nsacr_s           cn88xx; */
} bdk_gicrx_nsacr_t;

static inline uint64_t BDK_GICRX_NSACR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_NSACR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080010E00ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_NSACR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_NSACR(...) bdk_gicrx_nsacr_t
#define bustype_BDK_GICRX_NSACR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_NSACR(p1) (p1)
#define arguments_BDK_GICRX_NSACR(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_NSACR(...) "GICRX_NSACR"


/**
 * NCB - gicr#_pendbaser
 */
typedef union bdk_gicrx_pendbaser {
	uint64_t u;
	struct bdk_gicrx_pendbaser_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_63_63              : 1;
		uint64_t pending_table_zero          : 1;  /**< WO - 0 = The coarse-grained map for the LPI pending table is valid.
                                                                 1 = The pending table has been zeroed out. */
		uint64_t reserved_48_61              : 14;
		uint64_t pa                          : 32; /**< R/W - Physical address bits <46:16> for the LPI pending table. */
		uint64_t reserved_0_15               : 16;
#else
		uint64_t reserved_0_15               : 16;
		uint64_t pa                          : 32;
		uint64_t reserved_48_61              : 14;
		uint64_t pending_table_zero          : 1;
		uint64_t reserved_63_63              : 1;
#endif
	} s;
	/* struct bdk_gicrx_pendbaser_s       cn85xx; */
	/* struct bdk_gicrx_pendbaser_s       cn88xx; */
} bdk_gicrx_pendbaser_t;

static inline uint64_t BDK_GICRX_PENDBASER(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_PENDBASER(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080000078ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_PENDBASER", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_PENDBASER(...) bdk_gicrx_pendbaser_t
#define bustype_BDK_GICRX_PENDBASER(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GICRX_PENDBASER(p1) (p1)
#define arguments_BDK_GICRX_PENDBASER(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_PENDBASER(...) "GICRX_PENDBASER"


/**
 * NCB32b - gicr#_pidr0
 */
typedef union bdk_gicrx_pidr0 {
	uint32_t u;
	struct bdk_gicrx_pidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t partnum0                    : 8;  /**< RO - Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GICR. */
#else
		uint32_t partnum0                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicrx_pidr0_s           cn85xx; */
	/* struct bdk_gicrx_pidr0_s           cn88xx; */
} bdk_gicrx_pidr0_t;

static inline uint64_t BDK_GICRX_PIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_PIDR0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000080108000FFE0ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_PIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_PIDR0(...) bdk_gicrx_pidr0_t
#define bustype_BDK_GICRX_PIDR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_PIDR0(p1) (p1)
#define arguments_BDK_GICRX_PIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_PIDR0(...) "GICRX_PIDR0"


/**
 * NCB32b - gicr#_pidr1
 */
typedef union bdk_gicrx_pidr1 {
	uint32_t u;
	struct bdk_gicrx_pidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t idcode                      : 4;  /**< RO - JEP106 identification code <3:0>. Cavium code is 0x4C. */
		uint32_t partnum1                    : 4;  /**< RO - Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else
		uint32_t partnum1                    : 4;
		uint32_t idcode                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicrx_pidr1_s           cn85xx; */
	/* struct bdk_gicrx_pidr1_s           cn88xx; */
} bdk_gicrx_pidr1_t;

static inline uint64_t BDK_GICRX_PIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_PIDR1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000080108000FFE4ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_PIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_PIDR1(...) bdk_gicrx_pidr1_t
#define bustype_BDK_GICRX_PIDR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_PIDR1(p1) (p1)
#define arguments_BDK_GICRX_PIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_PIDR1(...) "GICRX_PIDR1"


/**
 * NCB32b - gicr#_pidr2
 */
typedef union bdk_gicrx_pidr2 {
	uint32_t u;
	struct bdk_gicrx_pidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t archrev                     : 4;  /**< RO - Architectural revision. 0x1 = GICv1; 0x2 = GICV2; 0x3 = GICv3; 0x4 = GICv4; 0x5-0xF = Reserved. */
		uint32_t usesjepcode                 : 1;  /**< RO - JEDEC assigned. */
		uint32_t jepid                       : 3;  /**< RO - JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else
		uint32_t jepid                       : 3;
		uint32_t usesjepcode                 : 1;
		uint32_t archrev                     : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicrx_pidr2_s           cn85xx; */
	/* struct bdk_gicrx_pidr2_s           cn88xx; */
} bdk_gicrx_pidr2_t;

static inline uint64_t BDK_GICRX_PIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_PIDR2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000080108000FFE8ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_PIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_PIDR2(...) bdk_gicrx_pidr2_t
#define bustype_BDK_GICRX_PIDR2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_PIDR2(p1) (p1)
#define arguments_BDK_GICRX_PIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_PIDR2(...) "GICRX_PIDR2"


/**
 * NCB32b - gicr#_pidr3
 */
typedef union bdk_gicrx_pidr3 {
	uint32_t u;
	struct bdk_gicrx_pidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revand                      : 4;  /**< RO - Manufacturer revision number. For CNXXXX always 0x0. */
		uint32_t cmod                        : 4;  /**< RO - Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else
		uint32_t cmod                        : 4;
		uint32_t revand                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicrx_pidr3_s           cn85xx; */
	/* struct bdk_gicrx_pidr3_s           cn88xx; */
} bdk_gicrx_pidr3_t;

static inline uint64_t BDK_GICRX_PIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_PIDR3(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000080108000FFECull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_PIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_PIDR3(...) bdk_gicrx_pidr3_t
#define bustype_BDK_GICRX_PIDR3(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_PIDR3(p1) (p1)
#define arguments_BDK_GICRX_PIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_PIDR3(...) "GICRX_PIDR3"


/**
 * NCB32b - gicr#_pidr4
 */
typedef union bdk_gicrx_pidr4 {
	uint32_t u;
	struct bdk_gicrx_pidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t cnt_4k                      : 4;  /**< RO - This field is 0x4, indicating a 64KB software-visible page. */
		uint32_t continuation_code           : 4;  /**< RO - 0x3 = Cavium JEP106 continuation code. */
#else
		uint32_t continuation_code           : 4;
		uint32_t cnt_4k                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gicrx_pidr4_s           cn85xx; */
	/* struct bdk_gicrx_pidr4_s           cn88xx; */
} bdk_gicrx_pidr4_t;

static inline uint64_t BDK_GICRX_PIDR4(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_PIDR4(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000080108000FFD0ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_PIDR4", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_PIDR4(...) bdk_gicrx_pidr4_t
#define bustype_BDK_GICRX_PIDR4(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_PIDR4(p1) (p1)
#define arguments_BDK_GICRX_PIDR4(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_PIDR4(...) "GICRX_PIDR4"


/**
 * NCB32b - gicr#_pidr5
 */
typedef union bdk_gicrx_pidr5 {
	uint32_t u;
	struct bdk_gicrx_pidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gicrx_pidr5_s           cn85xx; */
	/* struct bdk_gicrx_pidr5_s           cn88xx; */
} bdk_gicrx_pidr5_t;

static inline uint64_t BDK_GICRX_PIDR5(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_PIDR5(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000080108000FFD4ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_PIDR5", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_PIDR5(...) bdk_gicrx_pidr5_t
#define bustype_BDK_GICRX_PIDR5(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_PIDR5(p1) (p1)
#define arguments_BDK_GICRX_PIDR5(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_PIDR5(...) "GICRX_PIDR5"


/**
 * NCB32b - gicr#_pidr6
 */
typedef union bdk_gicrx_pidr6 {
	uint32_t u;
	struct bdk_gicrx_pidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gicrx_pidr6_s           cn85xx; */
	/* struct bdk_gicrx_pidr6_s           cn88xx; */
} bdk_gicrx_pidr6_t;

static inline uint64_t BDK_GICRX_PIDR6(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_PIDR6(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000080108000FFD8ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_PIDR6", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_PIDR6(...) bdk_gicrx_pidr6_t
#define bustype_BDK_GICRX_PIDR6(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_PIDR6(p1) (p1)
#define arguments_BDK_GICRX_PIDR6(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_PIDR6(...) "GICRX_PIDR6"


/**
 * NCB32b - gicr#_pidr7
 */
typedef union bdk_gicrx_pidr7 {
	uint32_t u;
	struct bdk_gicrx_pidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gicrx_pidr7_s           cn85xx; */
	/* struct bdk_gicrx_pidr7_s           cn88xx; */
} bdk_gicrx_pidr7_t;

static inline uint64_t BDK_GICRX_PIDR7(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_PIDR7(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000080108000FFDCull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_PIDR7", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_PIDR7(...) bdk_gicrx_pidr7_t
#define bustype_BDK_GICRX_PIDR7(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_PIDR7(p1) (p1)
#define arguments_BDK_GICRX_PIDR7(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_PIDR7(...) "GICRX_PIDR7"


/**
 * NCB - gicr#_propbaser
 */
typedef union bdk_gicrx_propbaser {
	uint64_t u;
	struct bdk_gicrx_propbaser_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t pa                          : 36; /**< R/W - Physical address bits <46:12> for the LPI configuration table. */
		uint64_t reserved_5_11               : 7;
		uint64_t num_bits                    : 5;  /**< R/W - The number of bits of LPI ID supported, minus one. If this value exceeds the value of
                                                                 GICD_TYPER[IDBITS], then the number of bits must be treated as the value defined by
                                                                 GICD_TYPER[IDBITS]. */
#else
		uint64_t num_bits                    : 5;
		uint64_t reserved_5_11               : 7;
		uint64_t pa                          : 36;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_gicrx_propbaser_s       cn85xx; */
	/* struct bdk_gicrx_propbaser_s       cn88xx; */
} bdk_gicrx_propbaser_t;

static inline uint64_t BDK_GICRX_PROPBASER(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_PROPBASER(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080000070ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_PROPBASER", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_PROPBASER(...) bdk_gicrx_propbaser_t
#define bustype_BDK_GICRX_PROPBASER(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GICRX_PROPBASER(p1) (p1)
#define arguments_BDK_GICRX_PROPBASER(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_PROPBASER(...) "GICRX_PROPBASER"


/**
 * NCB32b - gicr#_sctlr
 *
 * This register controls the behavior of the non-secure re-distributor.
 *
 */
typedef union bdk_gicrx_sctlr {
	uint32_t u;
	struct bdk_gicrx_sctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t uwp                         : 1;  /**< RO - Upstream write pending. Common to both security states. Read-only.
                                                                    0 = The effects of all upstream writes have been communicated to the parent re-
                                                                 distributor, including any generate SGI packets.
                                                                    1 = The effects of all upstream writes have not been communicated to the parent re-
                                                                 distributor, including any generate SGI packets. */
		uint32_t reserved_4_30               : 27;
		uint32_t rwp                         : 1;  /**< RO - Register write pending. This bit indicates whether a register write for the current
                                                                 security state (banked) is in progress or not.
                                                                  0 = The effect of all register writes are visible to all descendants of the re-
                                                                 distributor, including processors.
                                                                  1 = The effects of all register writes are not visible to all descendants of the re-
                                                                 distributor.

                                                                  Note: this field tracks completion of writes to GICR_ICENABLER() that clear the enable of
                                                                 one or more interrupts. */
		uint32_t reserved_1_2                : 2;
		uint32_t enable_lpis                 : 1;  /**< R/W - Enable LPIs. Resets to zero. Common to both security states. When this bit is clear,
                                                                 writes to generate physical LPIs to GICR_SETLPIR will be ignored.
                                                                 When a write changes this bit from zero to one, this bit becomes RAO/WI and the re-
                                                                 distributor must load the pending table from memory to check for any pending interrupts. */
#else
		uint32_t enable_lpis                 : 1;
		uint32_t reserved_1_2                : 2;
		uint32_t rwp                         : 1;
		uint32_t reserved_4_30               : 27;
		uint32_t uwp                         : 1;
#endif
	} s;
	/* struct bdk_gicrx_sctlr_s           cn85xx; */
	/* struct bdk_gicrx_sctlr_s           cn88xx; */
} bdk_gicrx_sctlr_t;

static inline uint64_t BDK_GICRX_SCTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_SCTLR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080000000ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_SCTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_SCTLR(...) bdk_gicrx_sctlr_t
#define bustype_BDK_GICRX_SCTLR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_SCTLR(p1) (p1)
#define arguments_BDK_GICRX_SCTLR(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_SCTLR(...) "GICRX_SCTLR"


/**
 * NCB32b - gicr#_seir
 */
typedef union bdk_gicrx_seir {
	uint32_t u;
	struct bdk_gicrx_seir_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t syndrome                    : 16; /**< WO - Syndrome value for the SEI to be generated. If another write to this register occurs
                                                                 before the previous has been forwarded to its receipients, the new value is ORed with the
                                                                 existing value. The SYNDROME field is sticky and indicates that at least one error of a
                                                                 class has occurred. */
#else
		uint32_t syndrome                    : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_gicrx_seir_s            cn85xx; */
	/* struct bdk_gicrx_seir_s            cn88xx; */
} bdk_gicrx_seir_t;

static inline uint64_t BDK_GICRX_SEIR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_SEIR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080000068ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_SEIR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_SEIR(...) bdk_gicrx_seir_t
#define bustype_BDK_GICRX_SEIR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_SEIR(p1) (p1)
#define arguments_BDK_GICRX_SEIR(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_SEIR(...) "GICRX_SEIR"


/**
 * NCB - gicr#_setlpir
 */
typedef union bdk_gicrx_setlpir {
	uint64_t u;
	struct bdk_gicrx_setlpir_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t pid                         : 32; /**< WO - Physical ID of the LPI to be generated. If the LPI is already pending, the write has no
                                                                 effect.
                                                                 If the LPI with the physical ID is not implemented, the write has no effect.
                                                                 If GICR_CTLR[ENABLE_LPI] is zero, the write has no effect. */
#else
		uint64_t pid                         : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_gicrx_setlpir_s         cn85xx; */
	/* struct bdk_gicrx_setlpir_s         cn88xx; */
} bdk_gicrx_setlpir_t;

static inline uint64_t BDK_GICRX_SETLPIR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_SETLPIR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080000040ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_SETLPIR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_SETLPIR(...) bdk_gicrx_setlpir_t
#define bustype_BDK_GICRX_SETLPIR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GICRX_SETLPIR(p1) (p1)
#define arguments_BDK_GICRX_SETLPIR(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_SETLPIR(...) "GICRX_SETLPIR"


/**
 * NCB32b - gicr#_setnmir_el1s
 */
typedef union bdk_gicrx_setnmir_el1s {
	uint32_t u;
	struct bdk_gicrx_setnmir_el1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vec                         : 32; /**< SWO - These write-only secure registers are used to generate non-maskable interrupts to the APs.
                                                                 The value written into these registers is not used. There is no interrupt ID for NMIs.
                                                                 Whenever a register in this set is written, the NMI signal of the AP being managed by that
                                                                 register is asserted.
                                                                 Each register in this set is RAZ/WI for non-secure accesses. */
#else
		uint32_t vec                         : 32;
#endif
	} s;
	/* struct bdk_gicrx_setnmir_el1s_s    cn85xx; */
	/* struct bdk_gicrx_setnmir_el1s_s    cn88xx; */
} bdk_gicrx_setnmir_el1s_t;

static inline uint64_t BDK_GICRX_SETNMIR_EL1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_SETNMIR_EL1S(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000080108000C000ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_SETNMIR_EL1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_SETNMIR_EL1S(...) bdk_gicrx_setnmir_el1s_t
#define bustype_BDK_GICRX_SETNMIR_EL1S(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_SETNMIR_EL1S(p1) (p1)
#define arguments_BDK_GICRX_SETNMIR_EL1S(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_SETNMIR_EL1S(...) "GICRX_SETNMIR_EL1S"


/**
 * NCB32b - gicr#_sstatusr
 */
typedef union bdk_gicrx_sstatusr {
	uint32_t u;
	struct bdk_gicrx_sstatusr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_4_31               : 28;
		uint32_t wrod                        : 1;  /**< R/W1C/H - This bit is set if a write to a read-only location is detected. Software must write a one
                                                                 to this bit to clear it. */
		uint32_t rwod                        : 1;  /**< R/W1C/H - This bit is set if a read to a write-only location is detected. Software must write a one
                                                                 to this bit to clear it. */
		uint32_t wrd                         : 1;  /**< R/W1C/H - This bit is set if a write to a reserved location is detected. Software must write a one
                                                                 to this bit to clear it. */
		uint32_t rrd                         : 1;  /**< R/W1C/H - This bit is set if a read to a reserved location is detected. Software must write a one to
                                                                 this bit to clear it. */
#else
		uint32_t rrd                         : 1;
		uint32_t wrd                         : 1;
		uint32_t rwod                        : 1;
		uint32_t wrod                        : 1;
		uint32_t reserved_4_31               : 28;
#endif
	} s;
	/* struct bdk_gicrx_sstatusr_s        cn85xx; */
	/* struct bdk_gicrx_sstatusr_s        cn88xx; */
} bdk_gicrx_sstatusr_t;

static inline uint64_t BDK_GICRX_SSTATUSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_SSTATUSR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080000010ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_SSTATUSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_SSTATUSR(...) bdk_gicrx_sstatusr_t
#define bustype_BDK_GICRX_SSTATUSR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_SSTATUSR(p1) (p1)
#define arguments_BDK_GICRX_SSTATUSR(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_SSTATUSR(...) "GICRX_SSTATUSR"


/**
 * NCB32b - gicr#_syncr
 */
typedef union bdk_gicrx_syncr {
	uint32_t u;
	struct bdk_gicrx_syncr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t busy                        : 1;  /**< RO - Reserved. When this register is read, it will only return read-data with BUSY as zero when
                                                                 none of the following operations are in progress:
                                                                 * Any writes to GICR_CLRLPIR within the redistributor.
                                                                 * Any writes to GICR_MOVLPIR within the redistributor.
                                                                 * Any writes to GICR_MOVALLR within the redistributor.
                                                                 * Any writes to GICR_INVLPIR within the redistributor.
                                                                 * Any writes to GICR_INVALLR within the redistributor.
                                                                 * Any writes to another redistributor performed as a result of a previous write to
                                                                 GICR_MOVLPIR or GICR_MOVALLR have completed and arrived at the target redistributor.
                                                                 Including operations initiated by writing to GICR_PENDBASER or GICR_PROPBASER. */
#else
		uint32_t busy                        : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_gicrx_syncr_s           cn85xx; */
	/* struct bdk_gicrx_syncr_s           cn88xx; */
} bdk_gicrx_syncr_t;

static inline uint64_t BDK_GICRX_SYNCR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_SYNCR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x00008010800000C0ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_SYNCR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_SYNCR(...) bdk_gicrx_syncr_t
#define bustype_BDK_GICRX_SYNCR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_SYNCR(p1) (p1)
#define arguments_BDK_GICRX_SYNCR(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_SYNCR(...) "GICRX_SYNCR"


/**
 * NCB - gicr#_typer
 *
 * This 64-bit read-only register is used to discover the properties of the redistributor and is
 * always accessible regardless of the ARE setting for a security state.
 */
typedef union bdk_gicrx_typer {
	uint64_t u;
	struct bdk_gicrx_typer_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t a3                          : 8;  /**< RO - The affinity level 3 value for the redistributor. */
		uint64_t a2                          : 8;  /**< RO/H - The affinity level 2 value for the redistributor. */
		uint64_t a1                          : 8;  /**< RO/H - The affinity level 1 value for the redistributor. */
		uint64_t a0                          : 8;  /**< RO/H - The affinity level 0 value for the redistributor. */
		uint64_t reserved_24_31              : 8;
		uint64_t pn                          : 16; /**< RO/H - The processor number, a unique identifier for the processor understood by the ITS. Should
                                                                 be the logical processor number supported by the redistributor, which is the redistributor
                                                                 ID, ie. the variable a. */
		uint64_t reserved_6_7                : 2;
		uint64_t dpgs                        : 1;  /**< RAZ - GICR_CTLR[DPG*] bits are NOT supported. */
		uint64_t last                        : 1;  /**< RO/H - Last. This bit is only set for the last redistributor in a set of contiguous redistributor
                                                                 register pages. Needs to be determined from fuse signals or SKU. */
		uint64_t distributed                 : 1;  /**< RO - 0 = Monolithic implementation.
                                                                 1 = Distributed implementation registers supported. */
		uint64_t reserved_1_2                : 2;
		uint64_t plpis                       : 1;  /**< RO - 0 = Physical LPIs not supported.
                                                                 1 = Physical LPIs supported. */
#else
		uint64_t plpis                       : 1;
		uint64_t reserved_1_2                : 2;
		uint64_t distributed                 : 1;
		uint64_t last                        : 1;
		uint64_t dpgs                        : 1;
		uint64_t reserved_6_7                : 2;
		uint64_t pn                          : 16;
		uint64_t reserved_24_31              : 8;
		uint64_t a0                          : 8;
		uint64_t a1                          : 8;
		uint64_t a2                          : 8;
		uint64_t a3                          : 8;
#endif
	} s;
	/* struct bdk_gicrx_typer_s           cn85xx; */
	/* struct bdk_gicrx_typer_s           cn88xx; */
} bdk_gicrx_typer_t;

static inline uint64_t BDK_GICRX_TYPER(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_TYPER(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080000008ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_TYPER", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_TYPER(...) bdk_gicrx_typer_t
#define bustype_BDK_GICRX_TYPER(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GICRX_TYPER(p1) (p1)
#define arguments_BDK_GICRX_TYPER(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_TYPER(...) "GICRX_TYPER"


/**
 * NCB32b - gicr#_waker
 */
typedef union bdk_gicrx_waker {
	uint32_t u;
	struct bdk_gicrx_waker_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t quiescent                   : 1;  /**< SRO - Indicates that redistributor is quiescent and can be powered off. */
		uint32_t reserved_3_30               : 28;
		uint32_t ca                          : 1;  /**< SRO - Children asleep.
                                                                 When [PS] is one, the redistributor treats the interrupt group enables as zero
                                                                 until a subsequent update to the enables is received. */
		uint32_t ps                          : 1;  /**< SR/W - Processor sleep.
                                                                 0 = The redistributor never asserts WakeRequest.
                                                                 1 = The redistributor must assert WakeRequest and hold interrupts as pending if an enable
                                                                 bit is zero for an interrupt group and there is a pending interrupt for that group. */
		uint32_t sleep                       : 1;  /**< SR/W - Sleep.
                                                                 0 = The parent never asserts WakeRequest.
                                                                 1 = The parent must assert WakeRequest and hold interrupts as pending. */
#else
		uint32_t sleep                       : 1;
		uint32_t ps                          : 1;
		uint32_t ca                          : 1;
		uint32_t reserved_3_30               : 28;
		uint32_t quiescent                   : 1;
#endif
	} s;
	/* struct bdk_gicrx_waker_s           cn85xx; */
	/* struct bdk_gicrx_waker_s           cn88xx; */
} bdk_gicrx_waker_t;

static inline uint64_t BDK_GICRX_WAKER(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GICRX_WAKER(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000801080000014ull + (param1 & 63) * 0x20000ull;
	csr_fatal("BDK_GICRX_WAKER", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GICRX_WAKER(...) bdk_gicrx_waker_t
#define bustype_BDK_GICRX_WAKER(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GICRX_WAKER(p1) (p1)
#define arguments_BDK_GICRX_WAKER(p1) (p1),-1,-1,-1
#define basename_BDK_GICRX_WAKER(...) "GICRX_WAKER"


/**
 * NCB - gits_baser#
 *
 * This set of 64-bit registers specify the base address and size of a number of implementation
 * defined tables required by the ITS:
 * An implementation can provide up to eight such registers.
 * Where a register is not implemented, it is RES0.
 */
typedef union bdk_gits_baserx {
	uint64_t u;
	struct bdk_gits_baserx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t valid                       : 1;  /**< R/W - 0 = No memory has been allocated to the table and if the type field is non-zero, the ITS
                                                                 discards any writes to the interrupt translation page.
                                                                 1 = Memory has been allocated to the table  by software. */
		uint64_t indirect                    : 1;  /**< RO - 0 = Direct.   The size field indicates a number of pages used by the ITS to store data
                                                                 associated with each table entry.
                                                                 1 = Indirect.  The size field indicates a number of pages which contain an array 64-bit
                                                                 pointers to pages that are used to
                                                                     store the data associated with each table entry.  Each 64-bit pointer has the
                                                                 following format:
                                                                       * Bits<63>    = Valid.
                                                                       * Bits<62:48> = Reserved.
                                                                       * Bits<47:N>  = Physical address.
                                                                       * Bits<N-1:0> = Reserved.

                                                                 Note: The value of N and the size of all these pages is determined from the
                                                                 page size field. */
		uint64_t cacheability                : 3;  /**< RO - Cacheability attribute:
                                                                 0x0 = Non-cacheable, non-bufferable
                                                                 0x1 = Non-cacheable.
                                                                 0x2 = Read-allocate, write-through.
                                                                 0x3 = Read-allocate, write-back.
                                                                 0x4 = Write-allocate, write-through.
                                                                 0x5 = Write-allocate, write-back.
                                                                 0x6 = Read-allocate, write-allocate, write-through.
                                                                 0x7 = Read-allocate, write-allocate, write-back.

                                                                 In CNXXXX not implemented, ignored. */
		uint64_t tbl_type                    : 3;  /**< RO - Type of entity that requires entries in the associated table.
                                                                 0x0 = Unimplemented.
                                                                 0x1 = Devices.
                                                                 0x2 = Virtual processors.
                                                                 0x3 = Physical processors.
                                                                 0x4 = Interrupt collections.
                                                                 0x5 = Reserved (treated as 0x0).
                                                                 0x6 = Reserved (treated as 0x0).
                                                                 0x7 = Reserved (treated as 0x0). */
		uint64_t entry_size                  : 8;  /**< RO - This field is read-only and specifies the number of bytes per entry, minus one. */
		uint64_t arsvd                       : 6;  /**< R/W - Reserved and must be zero. This field will be ignored if not zero. */
		uint64_t physical_address            : 30; /**< R/W - Physical address of the table. If the type field is zero this field is RAZ/WI. This field
                                                                 provided bits <47:12> of the base physical address of the table.
                                                                 Bits <11:0> of the base physical address are zero when page size is 4KB. Bits <15:12> of
                                                                 the base physical address are also zero when page size is 64KB. */
		uint64_t shareability                : 2;  /**< RO - Shareability attribute:
                                                                 0x0 = Accesses are non-shareable.
                                                                 0x1 = Accesses are inner-shareable.
                                                                 0x2 = Accesses are outer-shareable.
                                                                 0x3 = Reserved.  Treated as 0x0.
                                                                 Note: This field is not implemented in T88. */
		uint64_t pagesize                    : 2;  /**< R/W - 0x0 = 4 KB pages.
                                                                 0x1 = 16 KB pages (not supported, reserved).
                                                                 0x2 = 64 KB pages.
                                                                 0x3 = Reserved. Treated as 64kB pages. */
		uint64_t size                        : 8;  /**< R/W - Size. The number of pages of memory allocated to the table, minus one. If the type
                                                                 field is zero this field is RAZ/WI. */
#else
		uint64_t size                        : 8;
		uint64_t pagesize                    : 2;
		uint64_t shareability                : 2;
		uint64_t physical_address            : 30;
		uint64_t arsvd                       : 6;
		uint64_t entry_size                  : 8;
		uint64_t tbl_type                    : 3;
		uint64_t cacheability                : 3;
		uint64_t indirect                    : 1;
		uint64_t valid                       : 1;
#endif
	} s;
	/* struct bdk_gits_baserx_s           cn85xx; */
	/* struct bdk_gits_baserx_s           cn88xx; */
} bdk_gits_baserx_t;

static inline uint64_t BDK_GITS_BASERX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_BASERX(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x0000801000020100ull;
	csr_fatal("BDK_GITS_BASERX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GITS_BASERX(...) bdk_gits_baserx_t
#define bustype_BDK_GITS_BASERX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GITS_BASERX(p1) (p1)
#define arguments_BDK_GITS_BASERX(p1) (p1),-1,-1,-1
#define basename_BDK_GITS_BASERX(...) "GITS_BASERX"


/**
 * NCB - gits_baser#_rowi
 *
 * This set of 64-bit registers specify the base address and size of a number of implementation
 * defined tables required by the ITS:
 * An implementation can provide up to eight such registers.
 * Where a register is not implemented, it is RES0.
 */
typedef union bdk_gits_baserx_rowi {
	uint64_t u;
	struct bdk_gits_baserx_rowi_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_gits_baserx_rowi_s      cn85xx; */
	/* struct bdk_gits_baserx_rowi_s      cn88xx; */
} bdk_gits_baserx_rowi_t;

static inline uint64_t BDK_GITS_BASERX_ROWI(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_BASERX_ROWI(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 7))))
		return 0x0000801000020100ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_GITS_BASERX_ROWI", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GITS_BASERX_ROWI(...) bdk_gits_baserx_rowi_t
#define bustype_BDK_GITS_BASERX_ROWI(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GITS_BASERX_ROWI(p1) (p1)
#define arguments_BDK_GITS_BASERX_ROWI(p1) (p1),-1,-1,-1
#define basename_BDK_GITS_BASERX_ROWI(...) "GITS_BASERX_ROWI"


/**
 * NCB - gits_cbaser
 *
 * This register holds the physical memory address of the ITS command queue.
 *
 */
typedef union bdk_gits_cbaser {
	uint64_t u;
	struct bdk_gits_cbaser_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t valid                       : 1;  /**< R/W - 0 = No memory has been allocated to the command queue and the ITS discards any writes to
                                                                 the interrupt translation page.
                                                                 1 = Memory has been allocated by software for the command queue. */
		uint64_t reserved_62_62              : 1;
		uint64_t cacheability                : 3;  /**< RO - Cacheability attribute:
                                                                 0x0 = Non-cacheable, non-bufferable
                                                                 0x1 = Non-cacheable.
                                                                 0x2 = Read-allocate, write-through.
                                                                 0x3 = Read-allocate, write-back.
                                                                 0x4 = Write-allocate, write-through.
                                                                 0x5 = Write-allocate, write-back.
                                                                 0x6 = Read-allocate, write-allocate, write-through.
                                                                 0x7 = Read-allocate, write-allocate, write-back.

                                                                 In CNXXXX not implemented, ignored. */
		uint64_t reserved_48_58              : 11;
		uint64_t arsvd                       : 6;  /**< R/W - Reserved and must be zero. This field will be ignored if not zero. */
		uint64_t physical_address            : 30; /**< R/W - Physical address. Provides bits <47:12> of the physical address of the memory
                                                                 containing the command queue. Bits <11:0> of the base address of the queue are
                                                                 zero. */
		uint64_t shareability                : 2;  /**< RO - Shareability attribute:
                                                                 0x0 = Accesses are non-shareable.
                                                                 0x1 = Accesses are inner-shareable.
                                                                 0x2 = Accesses are outer-shareable.
                                                                 0x3 = Reserved.  Treated as 0x0.

                                                                 In CNXXXX not implemented, ignored. */
		uint64_t reserved_8_9                : 2;
		uint64_t size                        : 8;  /**< R/W - The number of 4kB pages of physical memory provided for the command queue, minus one.
                                                                 The command queue is a circular buffer and wraps at physical address <47:0> + (4096 *
                                                                 (SIZE+1)).
                                                                 Note: when GITS_CBASER is written, the value of GITS_CREADR is set to zero. See GIC
                                                                 spec for details on the ITS initialization sequence. */
#else
		uint64_t size                        : 8;
		uint64_t reserved_8_9                : 2;
		uint64_t shareability                : 2;
		uint64_t physical_address            : 30;
		uint64_t arsvd                       : 6;
		uint64_t reserved_48_58              : 11;
		uint64_t cacheability                : 3;
		uint64_t reserved_62_62              : 1;
		uint64_t valid                       : 1;
#endif
	} s;
	/* struct bdk_gits_cbaser_s           cn85xx; */
	/* struct bdk_gits_cbaser_s           cn88xx; */
} bdk_gits_cbaser_t;

#define BDK_GITS_CBASER BDK_GITS_CBASER_FUNC()
static inline uint64_t BDK_GITS_CBASER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_CBASER_FUNC(void)
{
	return 0x0000801000020080ull;
}
#define typedef_BDK_GITS_CBASER bdk_gits_cbaser_t
#define bustype_BDK_GITS_CBASER BDK_CSR_TYPE_NCB
#define busnum_BDK_GITS_CBASER 0
#define arguments_BDK_GITS_CBASER -1,-1,-1,-1
#define basename_BDK_GITS_CBASER "GITS_CBASER"


/**
 * NCB32b - gits_cidr0
 */
typedef union bdk_gits_cidr0 {
	uint32_t u;
	struct bdk_gits_cidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gits_cidr0_s            cn85xx; */
	/* struct bdk_gits_cidr0_s            cn88xx; */
} bdk_gits_cidr0_t;

#define BDK_GITS_CIDR0 BDK_GITS_CIDR0_FUNC()
static inline uint64_t BDK_GITS_CIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_CIDR0_FUNC(void)
{
	return 0x000080100002FFF0ull;
}
#define typedef_BDK_GITS_CIDR0 bdk_gits_cidr0_t
#define bustype_BDK_GITS_CIDR0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_CIDR0 0
#define arguments_BDK_GITS_CIDR0 -1,-1,-1,-1
#define basename_BDK_GITS_CIDR0 "GITS_CIDR0"


/**
 * NCB32b - gits_cidr1
 */
typedef union bdk_gits_cidr1 {
	uint32_t u;
	struct bdk_gits_cidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gits_cidr1_s            cn85xx; */
	/* struct bdk_gits_cidr1_s            cn88xx; */
} bdk_gits_cidr1_t;

#define BDK_GITS_CIDR1 BDK_GITS_CIDR1_FUNC()
static inline uint64_t BDK_GITS_CIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_CIDR1_FUNC(void)
{
	return 0x000080100002FFF4ull;
}
#define typedef_BDK_GITS_CIDR1 bdk_gits_cidr1_t
#define bustype_BDK_GITS_CIDR1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_CIDR1 0
#define arguments_BDK_GITS_CIDR1 -1,-1,-1,-1
#define basename_BDK_GITS_CIDR1 "GITS_CIDR1"


/**
 * NCB32b - gits_cidr2
 */
typedef union bdk_gits_cidr2 {
	uint32_t u;
	struct bdk_gits_cidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gits_cidr2_s            cn85xx; */
	/* struct bdk_gits_cidr2_s            cn88xx; */
} bdk_gits_cidr2_t;

#define BDK_GITS_CIDR2 BDK_GITS_CIDR2_FUNC()
static inline uint64_t BDK_GITS_CIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_CIDR2_FUNC(void)
{
	return 0x000080100002FFF8ull;
}
#define typedef_BDK_GITS_CIDR2 bdk_gits_cidr2_t
#define bustype_BDK_GITS_CIDR2 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_CIDR2 0
#define arguments_BDK_GITS_CIDR2 -1,-1,-1,-1
#define basename_BDK_GITS_CIDR2 "GITS_CIDR2"


/**
 * NCB32b - gits_cidr3
 */
typedef union bdk_gits_cidr3 {
	uint32_t u;
	struct bdk_gits_cidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gits_cidr3_s            cn85xx; */
	/* struct bdk_gits_cidr3_s            cn88xx; */
} bdk_gits_cidr3_t;

#define BDK_GITS_CIDR3 BDK_GITS_CIDR3_FUNC()
static inline uint64_t BDK_GITS_CIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_CIDR3_FUNC(void)
{
	return 0x000080100002FFFCull;
}
#define typedef_BDK_GITS_CIDR3 bdk_gits_cidr3_t
#define bustype_BDK_GITS_CIDR3 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_CIDR3 0
#define arguments_BDK_GITS_CIDR3 -1,-1,-1,-1
#define basename_BDK_GITS_CIDR3 "GITS_CIDR3"


/**
 * NCB - gits_creadr
 *
 * Offset in the ITS command queue from GITS_CBASER where the next command will be read by the
 * ITS.
 * The command queue is considered to be empty when GITS_CWRITER is equal to GITS_CREADR.
 * The command queue is considered to be full when GITS_CWRITER is equal to (GITS_CREADR minus
 * 32), taking wrapping into account.
 * Note: when GITS_CBASER is written, the value of GITS_CREADR is set to zero
 */
typedef union bdk_gits_creadr {
	uint64_t u;
	struct bdk_gits_creadr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t offset                      : 15; /**< RO/H - Offset. Provides bits <19:5> of the offset from GITS_CBASER where the ITS will
                                                                 read the next command. Bits <4:0> of the offset are zero. */
		uint64_t reserved_0_4                : 5;
#else
		uint64_t reserved_0_4                : 5;
		uint64_t offset                      : 15;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_gits_creadr_s           cn85xx; */
	/* struct bdk_gits_creadr_s           cn88xx; */
} bdk_gits_creadr_t;

#define BDK_GITS_CREADR BDK_GITS_CREADR_FUNC()
static inline uint64_t BDK_GITS_CREADR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_CREADR_FUNC(void)
{
	return 0x0000801000020090ull;
}
#define typedef_BDK_GITS_CREADR bdk_gits_creadr_t
#define bustype_BDK_GITS_CREADR BDK_CSR_TYPE_NCB
#define busnum_BDK_GITS_CREADR 0
#define arguments_BDK_GITS_CREADR -1,-1,-1,-1
#define basename_BDK_GITS_CREADR "GITS_CREADR"


/**
 * NCB32b - gits_ctlr
 *
 * This register controls the behavior of the interrupt translation service.
 *
 */
typedef union bdk_gits_ctlr {
	uint32_t u;
	struct bdk_gits_ctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t quiescent                   : 1;  /**< RO/H - This bit indicates whether the ITS has completed all operations following a write of
                                                                 Enable to zero.
                                                                 0 = The ITS is not quiescent.
                                                                 1 = The ITS is quiescent, has completed all operations required to make any mapping data
                                                                     consistent with external memory and may be powered off. Note: in CCPI
                                                                     implementations,
                                                                     the ITS must also have forwarded any required operations to the re-distributors and
                                                                     received confirmation that they have reached the appropriate re-distributor. */
		uint32_t reserved_1_30               : 30;
		uint32_t enabled                     : 1;  /**< R/W - 0 = ITS is disabled. Writes to the interrupt translation space will be ignored and no
                                                                 further command queue entries will be processed.
                                                                 1 = ITS is enabled. Writes to the interrupt translation space will result in interrupt
                                                                 translations and the command queue will be processed.
                                                                 If a write to this register changes enabled from one to zero, the ITS must ensure that any
                                                                 caches containing mapping data must be made
                                                                 consistent with external memory and "QUIESCENT" must read as one until this has been
                                                                 completed. */
#else
		uint32_t enabled                     : 1;
		uint32_t reserved_1_30               : 30;
		uint32_t quiescent                   : 1;
#endif
	} s;
	/* struct bdk_gits_ctlr_s             cn85xx; */
	/* struct bdk_gits_ctlr_s             cn88xx; */
} bdk_gits_ctlr_t;

#define BDK_GITS_CTLR BDK_GITS_CTLR_FUNC()
static inline uint64_t BDK_GITS_CTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_CTLR_FUNC(void)
{
	return 0x0000801000020000ull;
}
#define typedef_BDK_GITS_CTLR bdk_gits_ctlr_t
#define bustype_BDK_GITS_CTLR BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_CTLR 0
#define arguments_BDK_GITS_CTLR -1,-1,-1,-1
#define basename_BDK_GITS_CTLR "GITS_CTLR"


/**
 * NCB - gits_cwriter
 *
 * Offset in the ITS command queue from GITS_CBASER where the next command will be written by
 * software.
 * The command queue is considered to be empty when GITS_CWRITER is equal to GITS_CREADR.
 * The command queue is considered to be full when GITS_CWRITER is equal to (GITS_CREADR minus
 * 32), taking wrapping into account.
 * Each command in the queue comprises 32 bytes. See section 5.13 for details of the commands
 * supported and the format of each command.
 */
typedef union bdk_gits_cwriter {
	uint64_t u;
	struct bdk_gits_cwriter_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t offset                      : 15; /**< R/W - Offset. Provides bits <19:5> of the offset from GITS_CBASER where software will
                                                                 write the next command. Bits <4:0> of the offset are zero. */
		uint64_t reserved_0_4                : 5;
#else
		uint64_t reserved_0_4                : 5;
		uint64_t offset                      : 15;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_gits_cwriter_s          cn85xx; */
	/* struct bdk_gits_cwriter_s          cn88xx; */
} bdk_gits_cwriter_t;

#define BDK_GITS_CWRITER BDK_GITS_CWRITER_FUNC()
static inline uint64_t BDK_GITS_CWRITER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_CWRITER_FUNC(void)
{
	return 0x0000801000020088ull;
}
#define typedef_BDK_GITS_CWRITER bdk_gits_cwriter_t
#define bustype_BDK_GITS_CWRITER BDK_CSR_TYPE_NCB
#define busnum_BDK_GITS_CWRITER 0
#define arguments_BDK_GITS_CWRITER -1,-1,-1,-1
#define basename_BDK_GITS_CWRITER "GITS_CWRITER"


/**
 * NCB32b - gits_iidr
 *
 * This 32-bit register is read-only and specifies the version and features supported by the ITS.
 *
 */
typedef union bdk_gits_iidr {
	uint32_t u;
	struct bdk_gits_iidr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t productid                   : 8;  /**< RO - An implementation defined product number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN88XX. */
		uint32_t reserved_20_23              : 4;
		uint32_t variant                     : 4;  /**< RO - Indicates the major revision or variant of the product.
                                                                 In CNXXXX, the major pass number. */
		uint32_t revision                    : 4;  /**< RO - Indicates the minor revision of the product.
                                                                 In CNXXXX, the minor pass number. */
		uint32_t implementer                 : 12; /**< RO - Indicates the implementer:
                                                                 0x34C = Cavium. */
#else
		uint32_t implementer                 : 12;
		uint32_t revision                    : 4;
		uint32_t variant                     : 4;
		uint32_t reserved_20_23              : 4;
		uint32_t productid                   : 8;
#endif
	} s;
	/* struct bdk_gits_iidr_s             cn85xx; */
	/* struct bdk_gits_iidr_s             cn88xx; */
} bdk_gits_iidr_t;

#define BDK_GITS_IIDR BDK_GITS_IIDR_FUNC()
static inline uint64_t BDK_GITS_IIDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_IIDR_FUNC(void)
{
	return 0x0000801000020004ull;
}
#define typedef_BDK_GITS_IIDR bdk_gits_iidr_t
#define bustype_BDK_GITS_IIDR BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_IIDR 0
#define arguments_BDK_GITS_IIDR -1,-1,-1,-1
#define basename_BDK_GITS_IIDR "GITS_IIDR"


/**
 * NCB - gits_imp_cseir
 *
 * This register holds the SEI status of the ITS command error.
 *
 */
typedef union bdk_gits_imp_cseir {
	uint64_t u;
	struct bdk_gits_imp_cseir_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_52_63              : 12;
		uint64_t creadr                      : 15; /**< RO/H - The read pointer of the first command with error. */
		uint64_t reserved_26_36              : 11;
		uint64_t cwriter_oor                 : 1;  /**< RO/H - When set, it means command write pointer is out of range. */
		uint64_t m                           : 1;  /**< RO/H - When set, it means multiple command errors have happened. */
		uint64_t reserved_17_23              : 7;
		uint64_t v                           : 1;  /**< R/W1C/H - When set, the command error is valid. For meaning/encoding of [7'b0, V, CMD,
                                                                 ERROR], please see ITS Command error encodings in the GIC specfication. Writing
                                                                 1 to this field, will clear the whole register. */
		uint64_t cmd                         : 8;  /**< RO/H - Type field of first ITS command that has the error. */
		uint64_t error                       : 8;  /**< RO/H - Error code for the first error. */
#else
		uint64_t error                       : 8;
		uint64_t cmd                         : 8;
		uint64_t v                           : 1;
		uint64_t reserved_17_23              : 7;
		uint64_t m                           : 1;
		uint64_t cwriter_oor                 : 1;
		uint64_t reserved_26_36              : 11;
		uint64_t creadr                      : 15;
		uint64_t reserved_52_63              : 12;
#endif
	} s;
	/* struct bdk_gits_imp_cseir_s        cn85xx; */
	/* struct bdk_gits_imp_cseir_s        cn88xx; */
} bdk_gits_imp_cseir_t;

#define BDK_GITS_IMP_CSEIR BDK_GITS_IMP_CSEIR_FUNC()
static inline uint64_t BDK_GITS_IMP_CSEIR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_IMP_CSEIR_FUNC(void)
{
	return 0x0000801000020020ull;
}
#define typedef_BDK_GITS_IMP_CSEIR bdk_gits_imp_cseir_t
#define bustype_BDK_GITS_IMP_CSEIR BDK_CSR_TYPE_NCB
#define busnum_BDK_GITS_IMP_CSEIR 0
#define arguments_BDK_GITS_IMP_CSEIR -1,-1,-1,-1
#define basename_BDK_GITS_IMP_CSEIR "GITS_IMP_CSEIR"


/**
 * NCB - gits_imp_tseir
 *
 * This register holds the SEI status of the ITS translator error.
 *
 */
typedef union bdk_gits_imp_tseir {
	uint64_t u;
	struct bdk_gits_imp_tseir_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t v                           : 1;  /**< R/W1C/H - When set, the translator error is valid. Write 1 to this field will clear fields [V, M,
                                                                 DEV_ID, INT_ID, ERROR]. */
		uint64_t m                           : 1;  /**< RO/H - When set, it means multiple errors have happened. */
		uint64_t reserved_53_61              : 9;
		uint64_t dev_id                      : 21; /**< RO/H - Input device ID to the interrupt translator. */
		uint64_t reserved_28_31              : 4;
		uint64_t int_id                      : 20; /**< RO/H - Input interrupt ID to the interrupt translator. */
		uint64_t error                       : 8;  /**< RO/H - Error code for the first error. Valid encoding is one of [CSEI_UNMAPPED_DEVICE,
                                                                 CSEI_ID_OOR,
                                                                 CSEI_UNMAPPED_INTERRUPT,CSEI_UNMAPPED_COLLECTION] (as defined in GITS_CMD_ERR_E). */
#else
		uint64_t error                       : 8;
		uint64_t int_id                      : 20;
		uint64_t reserved_28_31              : 4;
		uint64_t dev_id                      : 21;
		uint64_t reserved_53_61              : 9;
		uint64_t m                           : 1;
		uint64_t v                           : 1;
#endif
	} s;
	/* struct bdk_gits_imp_tseir_s        cn85xx; */
	/* struct bdk_gits_imp_tseir_s        cn88xx; */
} bdk_gits_imp_tseir_t;

#define BDK_GITS_IMP_TSEIR BDK_GITS_IMP_TSEIR_FUNC()
static inline uint64_t BDK_GITS_IMP_TSEIR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_IMP_TSEIR_FUNC(void)
{
	return 0x0000801000020028ull;
}
#define typedef_BDK_GITS_IMP_TSEIR bdk_gits_imp_tseir_t
#define bustype_BDK_GITS_IMP_TSEIR BDK_CSR_TYPE_NCB
#define busnum_BDK_GITS_IMP_TSEIR 0
#define arguments_BDK_GITS_IMP_TSEIR -1,-1,-1,-1
#define basename_BDK_GITS_IMP_TSEIR "GITS_IMP_TSEIR"


/**
 * NCB32b - gits_pidr0
 */
typedef union bdk_gits_pidr0 {
	uint32_t u;
	struct bdk_gits_pidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t partnum0                    : 8;  /**< RO - Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GITS. */
#else
		uint32_t partnum0                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gits_pidr0_s            cn85xx; */
	/* struct bdk_gits_pidr0_s            cn88xx; */
} bdk_gits_pidr0_t;

#define BDK_GITS_PIDR0 BDK_GITS_PIDR0_FUNC()
static inline uint64_t BDK_GITS_PIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_PIDR0_FUNC(void)
{
	return 0x000080100002FFE0ull;
}
#define typedef_BDK_GITS_PIDR0 bdk_gits_pidr0_t
#define bustype_BDK_GITS_PIDR0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_PIDR0 0
#define arguments_BDK_GITS_PIDR0 -1,-1,-1,-1
#define basename_BDK_GITS_PIDR0 "GITS_PIDR0"


/**
 * NCB32b - gits_pidr1
 */
typedef union bdk_gits_pidr1 {
	uint32_t u;
	struct bdk_gits_pidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t idcode                      : 4;  /**< RO - JEP106 identification code <3:0>. Cavium code is 0x4C. */
		uint32_t partnum1                    : 4;  /**< RO - Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else
		uint32_t partnum1                    : 4;
		uint32_t idcode                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gits_pidr1_s            cn85xx; */
	/* struct bdk_gits_pidr1_s            cn88xx; */
} bdk_gits_pidr1_t;

#define BDK_GITS_PIDR1 BDK_GITS_PIDR1_FUNC()
static inline uint64_t BDK_GITS_PIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_PIDR1_FUNC(void)
{
	return 0x000080100002FFE4ull;
}
#define typedef_BDK_GITS_PIDR1 bdk_gits_pidr1_t
#define bustype_BDK_GITS_PIDR1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_PIDR1 0
#define arguments_BDK_GITS_PIDR1 -1,-1,-1,-1
#define basename_BDK_GITS_PIDR1 "GITS_PIDR1"


/**
 * NCB32b - gits_pidr2
 */
typedef union bdk_gits_pidr2 {
	uint32_t u;
	struct bdk_gits_pidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t archrev                     : 4;  /**< RO - Architectural revision. 0x1 = GICv1; 0x2 = GICV2; 0x3 = GICv3; 0x4 = GICv4; 0x5-0xF = Reserved. */
		uint32_t usesjepcode                 : 1;  /**< RO - JEDEC assigned. */
		uint32_t jepid                       : 3;  /**< RO - JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else
		uint32_t jepid                       : 3;
		uint32_t usesjepcode                 : 1;
		uint32_t archrev                     : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gits_pidr2_s            cn85xx; */
	/* struct bdk_gits_pidr2_s            cn88xx; */
} bdk_gits_pidr2_t;

#define BDK_GITS_PIDR2 BDK_GITS_PIDR2_FUNC()
static inline uint64_t BDK_GITS_PIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_PIDR2_FUNC(void)
{
	return 0x000080100002FFE8ull;
}
#define typedef_BDK_GITS_PIDR2 bdk_gits_pidr2_t
#define bustype_BDK_GITS_PIDR2 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_PIDR2 0
#define arguments_BDK_GITS_PIDR2 -1,-1,-1,-1
#define basename_BDK_GITS_PIDR2 "GITS_PIDR2"


/**
 * NCB32b - gits_pidr3
 */
typedef union bdk_gits_pidr3 {
	uint32_t u;
	struct bdk_gits_pidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revand                      : 4;  /**< RO - Manufacturer revision number. For CNXXXX always 0x0. */
		uint32_t cmod                        : 4;  /**< RO - Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else
		uint32_t cmod                        : 4;
		uint32_t revand                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gits_pidr3_s            cn85xx; */
	/* struct bdk_gits_pidr3_s            cn88xx; */
} bdk_gits_pidr3_t;

#define BDK_GITS_PIDR3 BDK_GITS_PIDR3_FUNC()
static inline uint64_t BDK_GITS_PIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_PIDR3_FUNC(void)
{
	return 0x000080100002FFECull;
}
#define typedef_BDK_GITS_PIDR3 bdk_gits_pidr3_t
#define bustype_BDK_GITS_PIDR3 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_PIDR3 0
#define arguments_BDK_GITS_PIDR3 -1,-1,-1,-1
#define basename_BDK_GITS_PIDR3 "GITS_PIDR3"


/**
 * NCB32b - gits_pidr4
 */
typedef union bdk_gits_pidr4 {
	uint32_t u;
	struct bdk_gits_pidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t cnt_4k                      : 4;  /**< RO - 4KB Count. This field is 0x4, indicating this is a 64KB software-visible page. */
		uint32_t continuation_code           : 4;  /**< RO - JEP106 continuation code, least significant nibble. Indicates Cavium. */
#else
		uint32_t continuation_code           : 4;
		uint32_t cnt_4k                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gits_pidr4_s            cn85xx; */
	/* struct bdk_gits_pidr4_s            cn88xx; */
} bdk_gits_pidr4_t;

#define BDK_GITS_PIDR4 BDK_GITS_PIDR4_FUNC()
static inline uint64_t BDK_GITS_PIDR4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_PIDR4_FUNC(void)
{
	return 0x000080100002FFD0ull;
}
#define typedef_BDK_GITS_PIDR4 bdk_gits_pidr4_t
#define bustype_BDK_GITS_PIDR4 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_PIDR4 0
#define arguments_BDK_GITS_PIDR4 -1,-1,-1,-1
#define basename_BDK_GITS_PIDR4 "GITS_PIDR4"


/**
 * NCB32b - gits_pidr5
 */
typedef union bdk_gits_pidr5 {
	uint32_t u;
	struct bdk_gits_pidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gits_pidr5_s            cn85xx; */
	/* struct bdk_gits_pidr5_s            cn88xx; */
} bdk_gits_pidr5_t;

#define BDK_GITS_PIDR5 BDK_GITS_PIDR5_FUNC()
static inline uint64_t BDK_GITS_PIDR5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_PIDR5_FUNC(void)
{
	return 0x000080100002FFD4ull;
}
#define typedef_BDK_GITS_PIDR5 bdk_gits_pidr5_t
#define bustype_BDK_GITS_PIDR5 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_PIDR5 0
#define arguments_BDK_GITS_PIDR5 -1,-1,-1,-1
#define basename_BDK_GITS_PIDR5 "GITS_PIDR5"


/**
 * NCB32b - gits_pidr6
 */
typedef union bdk_gits_pidr6 {
	uint32_t u;
	struct bdk_gits_pidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gits_pidr6_s            cn85xx; */
	/* struct bdk_gits_pidr6_s            cn88xx; */
} bdk_gits_pidr6_t;

#define BDK_GITS_PIDR6 BDK_GITS_PIDR6_FUNC()
static inline uint64_t BDK_GITS_PIDR6_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_PIDR6_FUNC(void)
{
	return 0x000080100002FFD8ull;
}
#define typedef_BDK_GITS_PIDR6 bdk_gits_pidr6_t
#define bustype_BDK_GITS_PIDR6 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_PIDR6 0
#define arguments_BDK_GITS_PIDR6 -1,-1,-1,-1
#define basename_BDK_GITS_PIDR6 "GITS_PIDR6"


/**
 * NCB32b - gits_pidr7
 */
typedef union bdk_gits_pidr7 {
	uint32_t u;
	struct bdk_gits_pidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gits_pidr7_s            cn85xx; */
	/* struct bdk_gits_pidr7_s            cn88xx; */
} bdk_gits_pidr7_t;

#define BDK_GITS_PIDR7 BDK_GITS_PIDR7_FUNC()
static inline uint64_t BDK_GITS_PIDR7_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_PIDR7_FUNC(void)
{
	return 0x000080100002FFDCull;
}
#define typedef_BDK_GITS_PIDR7 bdk_gits_pidr7_t
#define bustype_BDK_GITS_PIDR7 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_PIDR7 0
#define arguments_BDK_GITS_PIDR7 -1,-1,-1,-1
#define basename_BDK_GITS_PIDR7 "GITS_PIDR7"


/**
 * NCB32b - gits_translater
 *
 * This 32-bit register is write-only. The value written to this register specifies an interrupt
 * identifier to be translated for the requesting device.
 * A unique device identifier is provided for each requesting device and this is presented to the
 * ITS on writes to this register. This device identifier
 * is used to index a device table that maps the incoming device identifier to an interrupt
 * translation table for that device.
 *
 * Note that writes to this register with a device identifier that has not been mapped will be
 * ignored.
 *
 * Note that writes to this register with a device identifier that exceed the supported device
 * identifier size will be ignored.
 *
 * Note that this register is provided to enable the generation (and translation) of message-
 * based interrupts from devices (e.g. MSI or MSI-X writes from PCIe devices).
 *
 * The register is at the same offset as GICD_SETSPI_NSR in the distributor and GICR_SETLPIR in
 * the re-distributor to allow virtualization of guest operating systems
 * that directly program devices simply by ensuring the address programmed by the guest can be
 * translated by an SMMU to target GITS_TRANSLATER.
 */
typedef union bdk_gits_translater {
	uint32_t u;
	struct bdk_gits_translater_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t int_id                      : 32; /**< WO/H - Interrupt ID. The ID of interrupt to be translated for the requesting device. Note: the
                                                                 number of interrupt identifier bits is defined by GITS_TYPER[IDBITS]. Non-zero identifier
                                                                 bits outside this range are ignored.
                                                                 Note: 16 bit access to bits <15:0> of this register must be supported. When written by a
                                                                 16 bit transaction, bits <31:16> are written as zero. This register can not be accessed by
                                                                 CPU. */
#else
		uint32_t int_id                      : 32;
#endif
	} s;
	/* struct bdk_gits_translater_s       cn85xx; */
	/* struct bdk_gits_translater_s       cn88xx; */
} bdk_gits_translater_t;

#define BDK_GITS_TRANSLATER BDK_GITS_TRANSLATER_FUNC()
static inline uint64_t BDK_GITS_TRANSLATER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_TRANSLATER_FUNC(void)
{
	return 0x0000801000030040ull;
}
#define typedef_BDK_GITS_TRANSLATER bdk_gits_translater_t
#define bustype_BDK_GITS_TRANSLATER BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_TRANSLATER 0
#define arguments_BDK_GITS_TRANSLATER -1,-1,-1,-1
#define basename_BDK_GITS_TRANSLATER "GITS_TRANSLATER"


/**
 * NCB32b - gits_typer
 *
 * This register describes features supported by the ITS.
 *
 */
typedef union bdk_gits_typer {
	uint32_t u;
	struct bdk_gits_typer_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t hcc                         : 8;  /**< RO - Hardware collection count. The number of collections supported by the ITS without
                                                                 provisioning of external memory. If this field is non-zero,
                                                                 collections in the range zero to (HCC minus one) are solely maintained in storage within
                                                                 the ITS.
                                                                 Note when this field is non-zero and an ITS is dynamically powered-off and back on,
                                                                 software must ensure that any hardware collections
                                                                 are re-mapped following power-on. */
		uint32_t reserved_20_23              : 4;
		uint32_t pta                         : 1;  /**< RO - Physical target addresses supported. See section 4.9.16.
                                                                 0 = Target addresses correspond to linear processor numbers. See section 5.4.6.
                                                                 1 = Target addresses correspond to the base physical address of re-distributors. */
		uint32_t seis                        : 1;  /**< RO - Locally generated system error interrupts supported. */
		uint32_t devbits                     : 5;  /**< RO - The number of device identifier bits supported, minus one. The 21-its device ID is defined
                                                                 as [node_id[1:0], iob_id[2:0], stream_id[15:0]]. */
		uint32_t idbits                      : 5;  /**< RO - The number of interrupt identifier bits supported, minus one. */
		uint32_t itte_size                   : 4;  /**< RO - ITT entry size.  Number of bytes per entry, minus one. The ITT entry size implemented is 4
                                                                 bytes (32-bit). */
		uint32_t distributed                 : 1;  /**< RO - Distributed ITS implementation supported. */
		uint32_t reserved_1_2                : 2;
		uint32_t physical                    : 1;  /**< RO - Reserved 1. */
#else
		uint32_t physical                    : 1;
		uint32_t reserved_1_2                : 2;
		uint32_t distributed                 : 1;
		uint32_t itte_size                   : 4;
		uint32_t idbits                      : 5;
		uint32_t devbits                     : 5;
		uint32_t seis                        : 1;
		uint32_t pta                         : 1;
		uint32_t reserved_20_23              : 4;
		uint32_t hcc                         : 8;
#endif
	} s;
	/* struct bdk_gits_typer_s            cn85xx; */
	/* struct bdk_gits_typer_s            cn88xx; */
} bdk_gits_typer_t;

#define BDK_GITS_TYPER BDK_GITS_TYPER_FUNC()
static inline uint64_t BDK_GITS_TYPER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GITS_TYPER_FUNC(void)
{
	return 0x0000801000020008ull;
}
#define typedef_BDK_GITS_TYPER bdk_gits_typer_t
#define bustype_BDK_GITS_TYPER BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GITS_TYPER 0
#define arguments_BDK_GITS_TYPER -1,-1,-1,-1
#define basename_BDK_GITS_TYPER "GITS_TYPER"

#endif /* __BDK_CSRS_GIC__ */
