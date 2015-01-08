#ifndef __BDK_CSRS_PCIERC__
#define __BDK_CSRS_PCIERC__
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
 * Cavium PCIERC.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * PCICONFIGRC - pcierc#_cfg000
 *
 * This register contains the first 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg000 {
	uint32_t u;
	struct bdk_pciercx_cfg000_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t devid                       : 16; /**< RO/WRSL - Device ID, writable through PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t vendid                      : 16; /**< RO/WRSL - Vendor ID, writable through PEM()_CFG_WR. However, the application must not change this field. */
#else
		uint32_t vendid                      : 16;
		uint32_t devid                       : 16;
#endif
	} s;
	/* struct bdk_pciercx_cfg000_s        cn88xx; */
	/* struct bdk_pciercx_cfg000_s        cn88xxp1; */
} bdk_pciercx_cfg000_t;

static inline uint64_t BDK_PCIERCX_CFG000(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG000(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000000ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG000", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG000(...) bdk_pciercx_cfg000_t
#define bustype_BDK_PCIERCX_CFG000(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG000(p1) (p1)
#define arguments_BDK_PCIERCX_CFG000(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG000(...) "PCIERCX_CFG000"


/**
 * PCICONFIGRC - pcierc#_cfg001
 *
 * This register contains the second 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg001 {
	uint32_t u;
	struct bdk_pciercx_cfg001_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dpe                         : 1;  /**< R/W1C/H - Detected parity error. */
		uint32_t sse                         : 1;  /**< R/W1C/H - Signaled system error. */
		uint32_t rma                         : 1;  /**< R/W1C/H - Received master abort. */
		uint32_t rta                         : 1;  /**< R/W1C/H - Received target abort. */
		uint32_t sta                         : 1;  /**< R/W1C/H - Signaled target abort. */
		uint32_t devt                        : 2;  /**< RO - DEVSEL timing. Not applicable for PCI Express. Hardwired to 0x0. */
		uint32_t mdpe                        : 1;  /**< R/W1C/H - Master data parity error. */
		uint32_t fbb                         : 1;  /**< RO - Fast back-to-back capable. Not applicable for PCI Express. Hardwired to 0. */
		uint32_t reserved_22_22              : 1;
		uint32_t m66                         : 1;  /**< RO - 66 MHz capable. Not applicable for PCI Express. Hardwired to 0. */
		uint32_t cl                          : 1;  /**< RO - Capabilities list. Indicates presence of an extended capability item. Hardwired to 1. */
		uint32_t i_stat                      : 1;  /**< RO - INTx status. */
		uint32_t reserved_11_18              : 8;
		uint32_t i_dis                       : 1;  /**< R/W - INTx assertion disable. */
		uint32_t fbbe                        : 1;  /**< RO - Fast back-to-back transaction enable. Not applicable for PCI Express. Must be hardwired to 0. */
		uint32_t see                         : 1;  /**< R/W - SERR\# enable. */
		uint32_t ids_wcc                     : 1;  /**< RO - IDSEL stepping/wait cycle control. Not applicable for PCI Express. Must be hardwired to 0. */
		uint32_t per                         : 1;  /**< R/W - Parity error response. */
		uint32_t vps                         : 1;  /**< RO - VGA palette snoop. Not applicable for PCI Express. Must be hardwired to 0. */
		uint32_t mwice                       : 1;  /**< RO - Memory write and invalidate. Not applicable for PCI Express. Must be hardwired to 0. */
		uint32_t scse                        : 1;  /**< RO - Special cycle enable. Not applicable for PCI Express. Must be hardwired to 0. */
		uint32_t me                          : 1;  /**< R/W - Bus master enable. */
		uint32_t msae                        : 1;  /**< R/W - Memory space access enable. */
		uint32_t isae                        : 1;  /**< R/W - I/O space access enable. */
#else
		uint32_t isae                        : 1;
		uint32_t msae                        : 1;
		uint32_t me                          : 1;
		uint32_t scse                        : 1;
		uint32_t mwice                       : 1;
		uint32_t vps                         : 1;
		uint32_t per                         : 1;
		uint32_t ids_wcc                     : 1;
		uint32_t see                         : 1;
		uint32_t fbbe                        : 1;
		uint32_t i_dis                       : 1;
		uint32_t reserved_11_18              : 8;
		uint32_t i_stat                      : 1;
		uint32_t cl                          : 1;
		uint32_t m66                         : 1;
		uint32_t reserved_22_22              : 1;
		uint32_t fbb                         : 1;
		uint32_t mdpe                        : 1;
		uint32_t devt                        : 2;
		uint32_t sta                         : 1;
		uint32_t rta                         : 1;
		uint32_t rma                         : 1;
		uint32_t sse                         : 1;
		uint32_t dpe                         : 1;
#endif
	} s;
	/* struct bdk_pciercx_cfg001_s        cn88xx; */
	/* struct bdk_pciercx_cfg001_s        cn88xxp1; */
} bdk_pciercx_cfg001_t;

static inline uint64_t BDK_PCIERCX_CFG001(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG001(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000004ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG001", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG001(...) bdk_pciercx_cfg001_t
#define bustype_BDK_PCIERCX_CFG001(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG001(p1) (p1)
#define arguments_BDK_PCIERCX_CFG001(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG001(...) "PCIERCX_CFG001"


/**
 * PCICONFIGRC - pcierc#_cfg002
 *
 * This register contains the third 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg002 {
	uint32_t u;
	struct bdk_pciercx_cfg002_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t bcc                         : 8;  /**< RO/WRSL - Base class code, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. */
		uint32_t sc                          : 8;  /**< RO/WRSL - Subclass code, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
		uint32_t pi                          : 8;  /**< RO/WRSL - Programming interface, writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field. */
		uint32_t rid                         : 8;  /**< RO/WRSL - Revision ID, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field.
                                                                 0x0 = pass 1.0.
                                                                 0x1 = pass 1.1.
                                                                 0x2 = pass 1.2.
                                                                 0x8 = pass 2.0. */
#else
		uint32_t rid                         : 8;
		uint32_t pi                          : 8;
		uint32_t sc                          : 8;
		uint32_t bcc                         : 8;
#endif
	} s;
	/* struct bdk_pciercx_cfg002_s        cn88xx; */
	/* struct bdk_pciercx_cfg002_s        cn88xxp1; */
} bdk_pciercx_cfg002_t;

static inline uint64_t BDK_PCIERCX_CFG002(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG002(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000008ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG002", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG002(...) bdk_pciercx_cfg002_t
#define bustype_BDK_PCIERCX_CFG002(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG002(p1) (p1)
#define arguments_BDK_PCIERCX_CFG002(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG002(...) "PCIERCX_CFG002"


/**
 * PCICONFIGRC - pcierc#_cfg003
 *
 * This register contains the fourth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg003 {
	uint32_t u;
	struct bdk_pciercx_cfg003_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t bist                        : 8;  /**< RO - The BIST register functions are not supported. All 8 bits of the BIST register are hardwired to 0. */
		uint32_t mfd                         : 1;  /**< RO/WRSL - Multi function device. The multi function device bit is writable through PEM()_CFG_WR.
                                                                 However, this is a single function device. Therefore, the application must not write a 1
                                                                 to this bit. */
		uint32_t chf                         : 7;  /**< RO - Configuration header format. Hardwired to 0x1. */
		uint32_t lt                          : 8;  /**< RO - Master latency timer. Not applicable for PCI Express, hardwired to 0x0. */
		uint32_t cls                         : 8;  /**< R/W - Cache line size. The cache line size register is R/W for legacy compatibility purposes and
                                                                 is not applicable to PCI Express device functionality. */
#else
		uint32_t cls                         : 8;
		uint32_t lt                          : 8;
		uint32_t chf                         : 7;
		uint32_t mfd                         : 1;
		uint32_t bist                        : 8;
#endif
	} s;
	/* struct bdk_pciercx_cfg003_s        cn88xx; */
	/* struct bdk_pciercx_cfg003_s        cn88xxp1; */
} bdk_pciercx_cfg003_t;

static inline uint64_t BDK_PCIERCX_CFG003(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG003(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000000Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG003", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG003(...) bdk_pciercx_cfg003_t
#define bustype_BDK_PCIERCX_CFG003(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG003(p1) (p1)
#define arguments_BDK_PCIERCX_CFG003(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG003(...) "PCIERCX_CFG003"


/**
 * PCICONFIGRC - pcierc#_cfg004
 *
 * This register contains the fifth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg004 {
	uint32_t u;
	struct bdk_pciercx_cfg004_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg004_s        cn88xx; */
	/* struct bdk_pciercx_cfg004_s        cn88xxp1; */
} bdk_pciercx_cfg004_t;

static inline uint64_t BDK_PCIERCX_CFG004(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG004(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000010ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG004", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG004(...) bdk_pciercx_cfg004_t
#define bustype_BDK_PCIERCX_CFG004(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG004(p1) (p1)
#define arguments_BDK_PCIERCX_CFG004(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG004(...) "PCIERCX_CFG004"


/**
 * PCICONFIGRC - pcierc#_cfg005
 *
 * This register contains the sixth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg005 {
	uint32_t u;
	struct bdk_pciercx_cfg005_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg005_s        cn88xx; */
	/* struct bdk_pciercx_cfg005_s        cn88xxp1; */
} bdk_pciercx_cfg005_t;

static inline uint64_t BDK_PCIERCX_CFG005(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG005(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000014ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG005", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG005(...) bdk_pciercx_cfg005_t
#define bustype_BDK_PCIERCX_CFG005(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG005(p1) (p1)
#define arguments_BDK_PCIERCX_CFG005(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG005(...) "PCIERCX_CFG005"


/**
 * PCICONFIGRC - pcierc#_cfg006
 *
 * This register contains the seventh 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg006 {
	uint32_t u;
	struct bdk_pciercx_cfg006_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t slt                         : 8;  /**< RO - Secondary latency timer. Not applicable to PCI Express, hardwired to 0x0. */
		uint32_t subbnum                     : 8;  /**< R/W - Subordinate bus number.
                                                                 If 0x0 no configuration accesses are forwarded to the secondary bus.
                                                                 INTERNAL: Note IOB/ECAM snoops on writes to this register. */
		uint32_t sbnum                       : 8;  /**< R/W - Secondary bus number.
                                                                 If 0x0 no configuration accesses are forwarded to the secondary bus.
                                                                 INTERNAL: Note IOB/ECAM snoops on writes to this register. */
		uint32_t pbnum                       : 8;  /**< R/W - Primary bus number. */
#else
		uint32_t pbnum                       : 8;
		uint32_t sbnum                       : 8;
		uint32_t subbnum                     : 8;
		uint32_t slt                         : 8;
#endif
	} s;
	/* struct bdk_pciercx_cfg006_s        cn88xx; */
	/* struct bdk_pciercx_cfg006_s        cn88xxp1; */
} bdk_pciercx_cfg006_t;

static inline uint64_t BDK_PCIERCX_CFG006(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG006(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000018ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG006", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG006(...) bdk_pciercx_cfg006_t
#define bustype_BDK_PCIERCX_CFG006(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG006(p1) (p1)
#define arguments_BDK_PCIERCX_CFG006(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG006(...) "PCIERCX_CFG006"


/**
 * PCICONFIGRC - pcierc#_cfg007
 *
 * This register contains the eighth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg007 {
	uint32_t u;
	struct bdk_pciercx_cfg007_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dpe                         : 1;  /**< R/W1C/H - Detected parity error. */
		uint32_t sse                         : 1;  /**< R/W1C/H - Signaled system error. */
		uint32_t rma                         : 1;  /**< R/W1C/H - Received master abort. */
		uint32_t rta                         : 1;  /**< R/W1C/H - Received target abort. */
		uint32_t sta                         : 1;  /**< R/W1C/H - Signaled target abort. */
		uint32_t devt                        : 2;  /**< RO - DEVSEL timing. Not applicable for PCI Express. Hardwired to 0. */
		uint32_t mdpe                        : 1;  /**< R/W1C/H - Master data parity error */
		uint32_t fbb                         : 1;  /**< RO - Fast back-to-back capable. Not applicable for PCI Express. Hardwired to 0. */
		uint32_t reserved_22_22              : 1;
		uint32_t m66                         : 1;  /**< RO - 66 MHz capable. Not applicable for PCI Express. Hardwired to 0. */
		uint32_t reserved_16_20              : 5;
		uint32_t lio_limi                    : 4;  /**< R/W - I/O space limit. */
		uint32_t reserved_9_11               : 3;
		uint32_t io32b                       : 1;  /**< RO/H - 32-bit I/O space. */
		uint32_t lio_base                    : 4;  /**< R/W - I/O space base. */
		uint32_t reserved_1_3                : 3;
		uint32_t io32a                       : 1;  /**< RO/WRSL - 32-bit I/O space.
                                                                 0 = 16-bit I/O addressing
                                                                 1 = 32-bit I/O addressing
                                                                 This bit is writable through PEM()_CFG_WR. When the application writes to this bit
                                                                 through PEM()_CFG_WR, the same value is written to bit 8 of this register. */
#else
		uint32_t io32a                       : 1;
		uint32_t reserved_1_3                : 3;
		uint32_t lio_base                    : 4;
		uint32_t io32b                       : 1;
		uint32_t reserved_9_11               : 3;
		uint32_t lio_limi                    : 4;
		uint32_t reserved_16_20              : 5;
		uint32_t m66                         : 1;
		uint32_t reserved_22_22              : 1;
		uint32_t fbb                         : 1;
		uint32_t mdpe                        : 1;
		uint32_t devt                        : 2;
		uint32_t sta                         : 1;
		uint32_t rta                         : 1;
		uint32_t rma                         : 1;
		uint32_t sse                         : 1;
		uint32_t dpe                         : 1;
#endif
	} s;
	/* struct bdk_pciercx_cfg007_s        cn88xx; */
	/* struct bdk_pciercx_cfg007_s        cn88xxp1; */
} bdk_pciercx_cfg007_t;

static inline uint64_t BDK_PCIERCX_CFG007(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG007(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000001Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG007", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG007(...) bdk_pciercx_cfg007_t
#define bustype_BDK_PCIERCX_CFG007(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG007(p1) (p1)
#define arguments_BDK_PCIERCX_CFG007(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG007(...) "PCIERCX_CFG007"


/**
 * PCICONFIGRC - pcierc#_cfg008
 *
 * This register contains the ninth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg008 {
	uint32_t u;
	struct bdk_pciercx_cfg008_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ml_addr                     : 12; /**< R/W - Memory limit address. */
		uint32_t reserved_16_19              : 4;
		uint32_t mb_addr                     : 12; /**< R/W - Memory base address. */
		uint32_t reserved_0_3                : 4;
#else
		uint32_t reserved_0_3                : 4;
		uint32_t mb_addr                     : 12;
		uint32_t reserved_16_19              : 4;
		uint32_t ml_addr                     : 12;
#endif
	} s;
	struct bdk_pciercx_cfg008_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ml_addr                     : 12; /**< R/W - Memory limit address. */
		uint32_t reserved_19_16              : 4;
		uint32_t mb_addr                     : 12; /**< R/W - Memory base address. */
		uint32_t reserved_3_0                : 4;
#else
		uint32_t reserved_3_0                : 4;
		uint32_t mb_addr                     : 12;
		uint32_t reserved_19_16              : 4;
		uint32_t ml_addr                     : 12;
#endif
	} cn88xx;
	struct bdk_pciercx_cfg008_cn88xx      cn88xxp1;
} bdk_pciercx_cfg008_t;

static inline uint64_t BDK_PCIERCX_CFG008(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG008(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000020ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG008", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG008(...) bdk_pciercx_cfg008_t
#define bustype_BDK_PCIERCX_CFG008(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG008(p1) (p1)
#define arguments_BDK_PCIERCX_CFG008(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG008(...) "PCIERCX_CFG008"


/**
 * PCICONFIGRC - pcierc#_cfg009
 *
 * This register contains the tenth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg009 {
	uint32_t u;
	struct bdk_pciercx_cfg009_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lmem_limit                  : 12; /**< R/W - Upper 12 bits of 32-bit prefetchable memory end address. */
		uint32_t reserved_17_19              : 3;
		uint32_t mem64b                      : 1;  /**< RO/H - 64-Bit memory addressing:
                                                                 0 = 32-bit memory addressing.
                                                                 1 = 64-bit memory addressing. */
		uint32_t lmem_base                   : 12; /**< R/W - Upper 12 bits of 32-bit prefetchable memory start address. */
		uint32_t reserved_1_3                : 3;
		uint32_t mem64a                      : 1;  /**< RO/WRSL - 64-Bit memory addressing:
                                                                 0 = 32-bit memory addressing.
                                                                 1 = 64-bit memory addressing.

                                                                 This bit is writable through PEM()_CFG_WR. When the application writes to this bit
                                                                 through PEM()_CFG_WR, the same value is written to bit 16 of this register. */
#else
		uint32_t mem64a                      : 1;
		uint32_t reserved_1_3                : 3;
		uint32_t lmem_base                   : 12;
		uint32_t mem64b                      : 1;
		uint32_t reserved_17_19              : 3;
		uint32_t lmem_limit                  : 12;
#endif
	} s;
	struct bdk_pciercx_cfg009_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lmem_limit                  : 12; /**< R/W - Upper 12 bits of 32-bit prefetchable memory end address. */
		uint32_t reserved_19_17              : 3;
		uint32_t mem64b                      : 1;  /**< RO/H - 64-Bit memory addressing:
                                                                 0 = 32-bit memory addressing.
                                                                 1 = 64-bit memory addressing. */
		uint32_t lmem_base                   : 12; /**< R/W - Upper 12 bits of 32-bit prefetchable memory start address. */
		uint32_t reserved_3_1                : 3;
		uint32_t mem64a                      : 1;  /**< RO/WRSL - 64-Bit memory addressing:
                                                                 0 = 32-bit memory addressing.
                                                                 1 = 64-bit memory addressing.

                                                                 This bit is writable through PEM()_CFG_WR. When the application writes to this bit
                                                                 through PEM()_CFG_WR, the same value is written to bit 16 of this register. */
#else
		uint32_t mem64a                      : 1;
		uint32_t reserved_3_1                : 3;
		uint32_t lmem_base                   : 12;
		uint32_t mem64b                      : 1;
		uint32_t reserved_19_17              : 3;
		uint32_t lmem_limit                  : 12;
#endif
	} cn88xx;
	struct bdk_pciercx_cfg009_cn88xx      cn88xxp1;
} bdk_pciercx_cfg009_t;

static inline uint64_t BDK_PCIERCX_CFG009(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG009(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000024ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG009", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG009(...) bdk_pciercx_cfg009_t
#define bustype_BDK_PCIERCX_CFG009(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG009(p1) (p1)
#define arguments_BDK_PCIERCX_CFG009(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG009(...) "PCIERCX_CFG009"


/**
 * PCICONFIGRC - pcierc#_cfg010
 *
 * This register contains the eleventh 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg010 {
	uint32_t u;
	struct bdk_pciercx_cfg010_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t umem_base                   : 32; /**< R/W - Upper 32 bits of base address of prefetchable memory space. Used only when 64-bit
                                                                 prefetchable memory addressing is enabled. */
#else
		uint32_t umem_base                   : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg010_s        cn88xx; */
	/* struct bdk_pciercx_cfg010_s        cn88xxp1; */
} bdk_pciercx_cfg010_t;

static inline uint64_t BDK_PCIERCX_CFG010(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG010(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000028ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG010", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG010(...) bdk_pciercx_cfg010_t
#define bustype_BDK_PCIERCX_CFG010(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG010(p1) (p1)
#define arguments_BDK_PCIERCX_CFG010(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG010(...) "PCIERCX_CFG010"


/**
 * PCICONFIGRC - pcierc#_cfg011
 *
 * This register contains the twelfth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg011 {
	uint32_t u;
	struct bdk_pciercx_cfg011_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t umem_limit                  : 32; /**< R/W - Upper 32 bits of limit address of prefetchable memory space. Used only when 64-bit
                                                                 prefetchable memory addressing is enabled. */
#else
		uint32_t umem_limit                  : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg011_s        cn88xx; */
	/* struct bdk_pciercx_cfg011_s        cn88xxp1; */
} bdk_pciercx_cfg011_t;

static inline uint64_t BDK_PCIERCX_CFG011(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG011(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000002Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG011", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG011(...) bdk_pciercx_cfg011_t
#define bustype_BDK_PCIERCX_CFG011(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG011(p1) (p1)
#define arguments_BDK_PCIERCX_CFG011(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG011(...) "PCIERCX_CFG011"


/**
 * PCICONFIGRC - pcierc#_cfg012
 *
 * This register contains the thirteenth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg012 {
	uint32_t u;
	struct bdk_pciercx_cfg012_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t uio_limit                   : 16; /**< R/W - Upper 16 bits of I/O limit (if 32-bit I/O decoding is supported for devices on the secondary side). */
		uint32_t uio_base                    : 16; /**< R/W - Upper 16 bits of I/O base (if 32-bit I/O decoding is supported for devices on the secondary side). */
#else
		uint32_t uio_base                    : 16;
		uint32_t uio_limit                   : 16;
#endif
	} s;
	/* struct bdk_pciercx_cfg012_s        cn88xx; */
	/* struct bdk_pciercx_cfg012_s        cn88xxp1; */
} bdk_pciercx_cfg012_t;

static inline uint64_t BDK_PCIERCX_CFG012(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG012(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000030ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG012", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG012(...) bdk_pciercx_cfg012_t
#define bustype_BDK_PCIERCX_CFG012(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG012(p1) (p1)
#define arguments_BDK_PCIERCX_CFG012(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG012(...) "PCIERCX_CFG012"


/**
 * PCICONFIGRC - pcierc#_cfg013
 *
 * This register contains the fourteenth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg013 {
	uint32_t u;
	struct bdk_pciercx_cfg013_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t cp                          : 8;  /**< RO/WRSL - First capability pointer. Points to power management capability structure by default,
                                                                 writable through PEM()_CFG_WR. However, the application must not change this field. */
#else
		uint32_t cp                          : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_pciercx_cfg013_s        cn88xx; */
	/* struct bdk_pciercx_cfg013_s        cn88xxp1; */
} bdk_pciercx_cfg013_t;

static inline uint64_t BDK_PCIERCX_CFG013(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG013(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000034ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG013", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG013(...) bdk_pciercx_cfg013_t
#define bustype_BDK_PCIERCX_CFG013(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG013(p1) (p1)
#define arguments_BDK_PCIERCX_CFG013(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG013(...) "PCIERCX_CFG013"


/**
 * PCICONFIGRC - pcierc#_cfg014
 *
 * This register contains the fifteenth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg014 {
	uint32_t u;
	struct bdk_pciercx_cfg014_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg014_s        cn88xx; */
	/* struct bdk_pciercx_cfg014_s        cn88xxp1; */
} bdk_pciercx_cfg014_t;

static inline uint64_t BDK_PCIERCX_CFG014(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG014(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000038ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG014", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG014(...) bdk_pciercx_cfg014_t
#define bustype_BDK_PCIERCX_CFG014(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG014(p1) (p1)
#define arguments_BDK_PCIERCX_CFG014(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG014(...) "PCIERCX_CFG014"


/**
 * PCICONFIGRC - pcierc#_cfg015
 *
 * This register contains the sixteenth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg015 {
	uint32_t u;
	struct bdk_pciercx_cfg015_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_28_31              : 4;
		uint32_t dtsees                      : 1;  /**< RO - Discard timer SERR enable status. Not applicable to PCI Express, hardwired to 0. */
		uint32_t dts                         : 1;  /**< RO - Discard timer status. Not applicable to PCI Express, hardwired to 0. */
		uint32_t sdt                         : 1;  /**< RO - Secondary discard timer. Not applicable to PCI Express, hardwired to 0. */
		uint32_t pdt                         : 1;  /**< RO - Primary discard timer. Not applicable to PCI Express, hardwired to 0. */
		uint32_t fbbe                        : 1;  /**< RO - Fast back-to-back transactions enable. Not applicable to PCI Express, hardwired to 0. */
		uint32_t sbrst                       : 1;  /**< R/W - Secondary bus reset. Hot reset. Causes TS1s with the hot reset bit to be sent to the link
                                                                 partner. When set, software should wait 2ms before clearing. The link partner normally
                                                                 responds by sending TS1s with the hot reset bit set, which will cause a link down event.
                                                                 Refer to 'PCIe Link-Down Reset in RC Mode' section. */
		uint32_t mam                         : 1;  /**< RO - Master abort mode. Not applicable to PCI Express, hardwired to 0. */
		uint32_t vga16d                      : 1;  /**< RO - VGA 16-bit decode. */
		uint32_t vgae                        : 1;  /**< RO - VGA enable. */
		uint32_t isae                        : 1;  /**< R/W - ISA enable. */
		uint32_t see                         : 1;  /**< R/W - SERR enable. */
		uint32_t pere                        : 1;  /**< R/W - Parity error response enable. */
		uint32_t inta                        : 8;  /**< RO/WRSL - Interrupt pin. Identifies the legacy interrupt message that the device (or device
                                                                 function) uses. The interrupt pin register is writable through
                                                                 PEM()_CFG_WR. In a single-function configuration, only INTA is used. Therefore, the
                                                                 application must not change this field. */
		uint32_t il                          : 8;  /**< R/W - Interrupt line. */
#else
		uint32_t il                          : 8;
		uint32_t inta                        : 8;
		uint32_t pere                        : 1;
		uint32_t see                         : 1;
		uint32_t isae                        : 1;
		uint32_t vgae                        : 1;
		uint32_t vga16d                      : 1;
		uint32_t mam                         : 1;
		uint32_t sbrst                       : 1;
		uint32_t fbbe                        : 1;
		uint32_t pdt                         : 1;
		uint32_t sdt                         : 1;
		uint32_t dts                         : 1;
		uint32_t dtsees                      : 1;
		uint32_t reserved_28_31              : 4;
#endif
	} s;
	struct bdk_pciercx_cfg015_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_28              : 4;
		uint32_t dtsees                      : 1;  /**< RO - Discard timer SERR enable status. Not applicable to PCI Express, hardwired to 0. */
		uint32_t dts                         : 1;  /**< RO - Discard timer status. Not applicable to PCI Express, hardwired to 0. */
		uint32_t sdt                         : 1;  /**< RO - Secondary discard timer. Not applicable to PCI Express, hardwired to 0. */
		uint32_t pdt                         : 1;  /**< RO - Primary discard timer. Not applicable to PCI Express, hardwired to 0. */
		uint32_t fbbe                        : 1;  /**< RO - Fast back-to-back transactions enable. Not applicable to PCI Express, hardwired to 0. */
		uint32_t sbrst                       : 1;  /**< R/W - Secondary bus reset. Hot reset. Causes TS1s with the hot reset bit to be sent to the link
                                                                 partner. When set, software should wait 2ms before clearing. The link partner normally
                                                                 responds by sending TS1s with the hot reset bit set, which will cause a link down event.
                                                                 Refer to 'PCIe Link-Down Reset in RC Mode' section. */
		uint32_t mam                         : 1;  /**< RO - Master abort mode. Not applicable to PCI Express, hardwired to 0. */
		uint32_t vga16d                      : 1;  /**< RO - VGA 16-bit decode. */
		uint32_t vgae                        : 1;  /**< RO - VGA enable. */
		uint32_t isae                        : 1;  /**< R/W - ISA enable. */
		uint32_t see                         : 1;  /**< R/W - SERR enable. */
		uint32_t pere                        : 1;  /**< R/W - Parity error response enable. */
		uint32_t inta                        : 8;  /**< RO/WRSL - Interrupt pin. Identifies the legacy interrupt message that the device (or device
                                                                 function) uses. The interrupt pin register is writable through
                                                                 PEM()_CFG_WR. In a single-function configuration, only INTA is used. Therefore, the
                                                                 application must not change this field. */
		uint32_t il                          : 8;  /**< R/W - Interrupt line. */
#else
		uint32_t il                          : 8;
		uint32_t inta                        : 8;
		uint32_t pere                        : 1;
		uint32_t see                         : 1;
		uint32_t isae                        : 1;
		uint32_t vgae                        : 1;
		uint32_t vga16d                      : 1;
		uint32_t mam                         : 1;
		uint32_t sbrst                       : 1;
		uint32_t fbbe                        : 1;
		uint32_t pdt                         : 1;
		uint32_t sdt                         : 1;
		uint32_t dts                         : 1;
		uint32_t dtsees                      : 1;
		uint32_t reserved_31_28              : 4;
#endif
	} cn88xx;
	struct bdk_pciercx_cfg015_cn88xx      cn88xxp1;
} bdk_pciercx_cfg015_t;

static inline uint64_t BDK_PCIERCX_CFG015(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG015(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000003Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG015", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG015(...) bdk_pciercx_cfg015_t
#define bustype_BDK_PCIERCX_CFG015(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG015(p1) (p1)
#define arguments_BDK_PCIERCX_CFG015(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG015(...) "PCIERCX_CFG015"


/**
 * PCICONFIGRC - pcierc#_cfg016
 *
 * This register contains the seventeenth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg016 {
	uint32_t u;
	struct bdk_pciercx_cfg016_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t pmes                        : 5;  /**< RO/WRSL/H - PME_Support. A value of 0x0 for any bit indicates that the device (or function) is not
                                                                 capable of generating PME messages while in that power state:

                                                                 _ Bit 11: If set, PME Messages can be generated from D0.

                                                                 _ Bit 12: If set, PME Messages can be generated from D1.

                                                                 _ Bit 13: If set, PME Messages can be generated from D2.

                                                                 _ Bit 14: If set, PME Messages can be generated from D3hot.

                                                                 _ Bit 15: If set, PME Messages can be generated from D3cold.

                                                                 The PME_Support field is writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field. */
		uint32_t d2s                         : 1;  /**< RO/WRSL - D2 support, writable through PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t d1s                         : 1;  /**< RO/WRSL - D1 support, writable through PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t auxc                        : 3;  /**< RO/WRSL - AUX current, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
		uint32_t dsi                         : 1;  /**< RO/WRSL - Device specific initialization (DSI), writable through PEM()_CFG_WR. However, the
                                                                 application must not change this field. */
		uint32_t reserved_20_20              : 1;
		uint32_t pme_clock                   : 1;  /**< RO - PME clock, hardwired to 0. */
		uint32_t pmsv                        : 3;  /**< RO/WRSL - Power management specification version, writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t ncp                         : 8;  /**< RO/WRSL - Next capability pointer. Points to the MSI capabilities by default, writable through
                                                                 PEM()_CFG_WR. */
		uint32_t pmcid                       : 8;  /**< RO - Power management capability ID. */
#else
		uint32_t pmcid                       : 8;
		uint32_t ncp                         : 8;
		uint32_t pmsv                        : 3;
		uint32_t pme_clock                   : 1;
		uint32_t reserved_20_20              : 1;
		uint32_t dsi                         : 1;
		uint32_t auxc                        : 3;
		uint32_t d1s                         : 1;
		uint32_t d2s                         : 1;
		uint32_t pmes                        : 5;
#endif
	} s;
	/* struct bdk_pciercx_cfg016_s        cn88xx; */
	/* struct bdk_pciercx_cfg016_s        cn88xxp1; */
} bdk_pciercx_cfg016_t;

static inline uint64_t BDK_PCIERCX_CFG016(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG016(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000040ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG016", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG016(...) bdk_pciercx_cfg016_t
#define bustype_BDK_PCIERCX_CFG016(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG016(p1) (p1)
#define arguments_BDK_PCIERCX_CFG016(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG016(...) "PCIERCX_CFG016"


/**
 * PCICONFIGRC - pcierc#_cfg017
 *
 * This register contains the eighteenth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg017 {
	uint32_t u;
	struct bdk_pciercx_cfg017_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t pmdia                       : 8;  /**< RO - Data register for additional information (not supported). */
		uint32_t bpccee                      : 1;  /**< RO - Bus power/clock control enable, hardwired to 0. */
		uint32_t bd3h                        : 1;  /**< RO - B2/B3 support, hardwired to 0. */
		uint32_t reserved_16_21              : 6;
		uint32_t pmess                       : 1;  /**< R/W1C/H - PME status. Indicates whether or not a previously enabled PME event occurred. */
		uint32_t pmedsia                     : 2;  /**< RO - Data scale (not supported). */
		uint32_t pmds                        : 4;  /**< RO - Data select (not supported). */
		uint32_t pmeens                      : 1;  /**< R/W - PME enable. A value of 1 indicates that the device is enabled to generate PME. */
		uint32_t reserved_4_7                : 4;
		uint32_t nsr                         : 1;  /**< RO/WRSL - No soft reset, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
		uint32_t reserved_2_2                : 1;
		uint32_t ps                          : 2;  /**< R/W/H - Power state. Controls the device power state:
                                                                 0x0 = D0.
                                                                 0x1 = D1.
                                                                 0x2 = D2.
                                                                 0x3 = D3.

                                                                 The written value is ignored if the specific state is not supported. */
#else
		uint32_t ps                          : 2;
		uint32_t reserved_2_2                : 1;
		uint32_t nsr                         : 1;
		uint32_t reserved_4_7                : 4;
		uint32_t pmeens                      : 1;
		uint32_t pmds                        : 4;
		uint32_t pmedsia                     : 2;
		uint32_t pmess                       : 1;
		uint32_t reserved_16_21              : 6;
		uint32_t bd3h                        : 1;
		uint32_t bpccee                      : 1;
		uint32_t pmdia                       : 8;
#endif
	} s;
	/* struct bdk_pciercx_cfg017_s        cn88xx; */
	/* struct bdk_pciercx_cfg017_s        cn88xxp1; */
} bdk_pciercx_cfg017_t;

static inline uint64_t BDK_PCIERCX_CFG017(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG017(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000044ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG017", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG017(...) bdk_pciercx_cfg017_t
#define bustype_BDK_PCIERCX_CFG017(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG017(p1) (p1)
#define arguments_BDK_PCIERCX_CFG017(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG017(...) "PCIERCX_CFG017"


/**
 * PCICONFIGRC - pcierc#_cfg020
 *
 * This register contains the twenty-first 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg020 {
	uint32_t u;
	struct bdk_pciercx_cfg020_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_25_31              : 7;
		uint32_t pvms                        : 1;  /**< RO - Per-vector masking capable. */
		uint32_t m64                         : 1;  /**< RO/WRSL - 64-bit address capable, writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field. */
		uint32_t mme                         : 3;  /**< R/W - Multiple message enabled. Indicates that multiple message mode is enabled by system
                                                                 software. The number of messages enabled must be less than or equal to the multiple
                                                                 message capable (MMC) value. */
		uint32_t mmc                         : 3;  /**< RO/WRSL - Multiple message capable, writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field. */
		uint32_t msien                       : 1;  /**< R/W - MSI enabled. When set, INTx must be disabled. This bit must never be set, as internal-MSI
                                                                 is not supported in RC mode. (Note that this has no effect on external MSI, which is
                                                                 commonly used in RC mode.) */
		uint32_t ncp                         : 8;  /**< RO/WRSL - Next capability pointer. Points to PCI Express capabilities by default, writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t msicid                      : 8;  /**< RO - MSI capability ID. */
#else
		uint32_t msicid                      : 8;
		uint32_t ncp                         : 8;
		uint32_t msien                       : 1;
		uint32_t mmc                         : 3;
		uint32_t mme                         : 3;
		uint32_t m64                         : 1;
		uint32_t pvms                        : 1;
		uint32_t reserved_25_31              : 7;
#endif
	} s;
	/* struct bdk_pciercx_cfg020_s        cn88xx; */
	/* struct bdk_pciercx_cfg020_s        cn88xxp1; */
} bdk_pciercx_cfg020_t;

static inline uint64_t BDK_PCIERCX_CFG020(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG020(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000050ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG020", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG020(...) bdk_pciercx_cfg020_t
#define bustype_BDK_PCIERCX_CFG020(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG020(p1) (p1)
#define arguments_BDK_PCIERCX_CFG020(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG020(...) "PCIERCX_CFG020"


/**
 * PCICONFIGRC - pcierc#_cfg021
 *
 * This register contains the twenty-second 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg021 {
	uint32_t u;
	struct bdk_pciercx_cfg021_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lmsi                        : 30; /**< R/W - Lower 32-bit address. */
		uint32_t reserved_0_1                : 2;
#else
		uint32_t reserved_0_1                : 2;
		uint32_t lmsi                        : 30;
#endif
	} s;
	/* struct bdk_pciercx_cfg021_s        cn88xx; */
	/* struct bdk_pciercx_cfg021_s        cn88xxp1; */
} bdk_pciercx_cfg021_t;

static inline uint64_t BDK_PCIERCX_CFG021(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG021(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000054ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG021", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG021(...) bdk_pciercx_cfg021_t
#define bustype_BDK_PCIERCX_CFG021(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG021(p1) (p1)
#define arguments_BDK_PCIERCX_CFG021(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG021(...) "PCIERCX_CFG021"


/**
 * PCICONFIGRC - pcierc#_cfg022
 *
 * This register contains the twenty-third 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg022 {
	uint32_t u;
	struct bdk_pciercx_cfg022_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t umsi                        : 32; /**< R/W - Upper 32-bit address. */
#else
		uint32_t umsi                        : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg022_s        cn88xx; */
	/* struct bdk_pciercx_cfg022_s        cn88xxp1; */
} bdk_pciercx_cfg022_t;

static inline uint64_t BDK_PCIERCX_CFG022(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG022(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000058ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG022", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG022(...) bdk_pciercx_cfg022_t
#define bustype_BDK_PCIERCX_CFG022(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG022(p1) (p1)
#define arguments_BDK_PCIERCX_CFG022(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG022(...) "PCIERCX_CFG022"


/**
 * PCICONFIGRC - pcierc#_cfg023
 *
 * This register contains the twenty-fourth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg023 {
	uint32_t u;
	struct bdk_pciercx_cfg023_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t msimd                       : 16; /**< R/W - MSI data. Pattern assigned by system software. Bits [4:0] are ORed with MSI_VECTOR to
                                                                 generate 32 MSI messages per function. */
#else
		uint32_t msimd                       : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_pciercx_cfg023_s        cn88xx; */
	/* struct bdk_pciercx_cfg023_s        cn88xxp1; */
} bdk_pciercx_cfg023_t;

static inline uint64_t BDK_PCIERCX_CFG023(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG023(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000005Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG023", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG023(...) bdk_pciercx_cfg023_t
#define bustype_BDK_PCIERCX_CFG023(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG023(p1) (p1)
#define arguments_BDK_PCIERCX_CFG023(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG023(...) "PCIERCX_CFG023"


/**
 * PCICONFIGRC - pcierc#_cfg028
 *
 * This register contains the twenty-ninth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg028 {
	uint32_t u;
	struct bdk_pciercx_cfg028_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_30_31              : 2;
		uint32_t imn                         : 5;  /**< RO/WRSL - Interrupt message number. Updated by hardware, writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t si                          : 1;  /**< RO/WRSL - Slot implemented. This bit is writable through PEM()_CFG_WR. However, it must 0 for an
                                                                 endpoint device. Therefore, the application must not write a 1 to this bit. */
		uint32_t dpt                         : 4;  /**< RO - Device port type. */
		uint32_t pciecv                      : 4;  /**< RO - PCI Express capability version. */
		uint32_t ncp                         : 8;  /**< RO/WRSL - Next capability pointer. Points to the MSI-X capability by default, writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t pcieid                      : 8;  /**< RO - PCI Express capability ID. */
#else
		uint32_t pcieid                      : 8;
		uint32_t ncp                         : 8;
		uint32_t pciecv                      : 4;
		uint32_t dpt                         : 4;
		uint32_t si                          : 1;
		uint32_t imn                         : 5;
		uint32_t reserved_30_31              : 2;
#endif
	} s;
	/* struct bdk_pciercx_cfg028_s        cn88xx; */
	/* struct bdk_pciercx_cfg028_s        cn88xxp1; */
} bdk_pciercx_cfg028_t;

static inline uint64_t BDK_PCIERCX_CFG028(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG028(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000070ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG028", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG028(...) bdk_pciercx_cfg028_t
#define bustype_BDK_PCIERCX_CFG028(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG028(p1) (p1)
#define arguments_BDK_PCIERCX_CFG028(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG028(...) "PCIERCX_CFG028"


/**
 * PCICONFIGRC - pcierc#_cfg029
 *
 * This register contains the thirtieth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg029 {
	uint32_t u;
	struct bdk_pciercx_cfg029_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_28_31              : 4;
		uint32_t cspls                       : 2;  /**< RO - Captured slot power limit scale. Not applicable for RC port, upstream port only */
		uint32_t csplv                       : 8;  /**< RO - Captured slot power limit value. Not applicable for RC port, upstream port only. */
		uint32_t reserved_16_17              : 2;
		uint32_t rber                        : 1;  /**< RO/WRSL - Role-based error reporting, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
		uint32_t reserved_12_14              : 3;
		uint32_t el1al                       : 3;  /**< RO - Endpoint L1 acceptable latency, writable through PEM()_CFG_WR. Must be 0x0 for non-
                                                                 endpoint devices. */
		uint32_t el0al                       : 3;  /**< RO - Endpoint L0s acceptable latency, writable through PEM()_CFG_WR. Must be 0x0 for non-
                                                                 endpoint devices. */
		uint32_t etfs                        : 1;  /**< RO/WRSL - Extended tag field supported. This bit is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t pfs                         : 2;  /**< RO/WRSL - Phantom function supported. This field is writable through
                                                                 PEM()_CFG_WR. However, phantom function is not supported. Therefore, the application
                                                                 must not write any value other than 0x0 to this field. */
		uint32_t mpss                        : 3;  /**< RO/WRSL - Max_Payload_Size supported, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
#else
		uint32_t mpss                        : 3;
		uint32_t pfs                         : 2;
		uint32_t etfs                        : 1;
		uint32_t el0al                       : 3;
		uint32_t el1al                       : 3;
		uint32_t reserved_12_14              : 3;
		uint32_t rber                        : 1;
		uint32_t reserved_16_17              : 2;
		uint32_t csplv                       : 8;
		uint32_t cspls                       : 2;
		uint32_t reserved_28_31              : 4;
#endif
	} s;
	/* struct bdk_pciercx_cfg029_s        cn88xx; */
	/* struct bdk_pciercx_cfg029_s        cn88xxp1; */
} bdk_pciercx_cfg029_t;

static inline uint64_t BDK_PCIERCX_CFG029(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG029(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000074ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG029", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG029(...) bdk_pciercx_cfg029_t
#define bustype_BDK_PCIERCX_CFG029(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG029(p1) (p1)
#define arguments_BDK_PCIERCX_CFG029(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG029(...) "PCIERCX_CFG029"


/**
 * PCICONFIGRC - pcierc#_cfg030
 *
 * This register contains the thirty-first 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg030 {
	uint32_t u;
	struct bdk_pciercx_cfg030_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_22_31              : 10;
		uint32_t tp                          : 1;  /**< RO - Transaction pending. Hard-wired to 0. */
		uint32_t ap_d                        : 1;  /**< RO - Aux power detected. Set to 1 if Aux power detected. */
		uint32_t ur_d                        : 1;  /**< R/W1C/H - Unsupported request detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. UR_D occurs when we receive
                                                                 something unsupported. Unsupported requests are nonfatal errors, so UR_D should cause
                                                                 NFE_D. Receiving a vendor-defined message should cause an unsupported request. */
		uint32_t fe_d                        : 1;  /**< R/W1C/H - Fatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in PCIERC()_CFG066 that has a severity set to fatal. Malformed TLPs
                                                                 generally fit into this category. */
		uint32_t nfe_d                       : 1;  /**< R/W1C/H - Nonfatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in PCIERC()_CFG066 that has a severity set to Nonfatal and does NOT
                                                                 meet Advisory Nonfatal criteria, which most poisoned TLPs should. */
		uint32_t ce_d                        : 1;  /**< R/W1C/H - Correctable error detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. This field is set if we
                                                                 receive any of the errors in PCIERC()_CFG068, for example, a Replay Timer Timeout.
                                                                 Also, it can be set if we get any of the errors in PCIERC()_CFG066 that has a severity
                                                                 set to nonfatal and meets the advisory nonfatal criteria, which most ECRC errors should. */
		uint32_t reserved_15_15              : 1;
		uint32_t mrrs                        : 3;  /**< R/W - Max read request size.
                                                                 0x0 =128 bytes.
                                                                 0x1 = 256 bytes.
                                                                 0x2 = 512 bytes.
                                                                 0x3 = 1024 bytes.
                                                                 0x4 = 2048 bytes.
                                                                 0x5 = 4096 bytes. */
		uint32_t ns_en                       : 1;  /**< R/W - Enable no snoop. */
		uint32_t ap_en                       : 1;  /**< R/W/H - AUX power PM enable. */
		uint32_t pf_en                       : 1;  /**< R/W/H - Phantom function enable. This bit should never be set; phantom functions not used in this device. */
		uint32_t etf_en                      : 1;  /**< R/W - Extended tag field enable. Set this bit to enable extended tags. */
		uint32_t mps                         : 3;  /**< R/W - Max payload size. Legal values: 0x0 = 128 B, 0x1 = 256 B.
                                                                 Larger sizes are not supported.
                                                                 The payload size is the actual number of double-words transferred as indicated
                                                                 in the TLP length field and does not take byte enables into account. */
		uint32_t ro_en                       : 1;  /**< R/W - Enable relaxed ordering. */
		uint32_t ur_en                       : 1;  /**< R/W - Unsupported request reporting enable. */
		uint32_t fe_en                       : 1;  /**< R/W - Fatal error reporting enable. */
		uint32_t nfe_en                      : 1;  /**< R/W - Nonfatal error reporting enable. */
		uint32_t ce_en                       : 1;  /**< R/W - Correctable error reporting enable. */
#else
		uint32_t ce_en                       : 1;
		uint32_t nfe_en                      : 1;
		uint32_t fe_en                       : 1;
		uint32_t ur_en                       : 1;
		uint32_t ro_en                       : 1;
		uint32_t mps                         : 3;
		uint32_t etf_en                      : 1;
		uint32_t pf_en                       : 1;
		uint32_t ap_en                       : 1;
		uint32_t ns_en                       : 1;
		uint32_t mrrs                        : 3;
		uint32_t reserved_15_15              : 1;
		uint32_t ce_d                        : 1;
		uint32_t nfe_d                       : 1;
		uint32_t fe_d                        : 1;
		uint32_t ur_d                        : 1;
		uint32_t ap_d                        : 1;
		uint32_t tp                          : 1;
		uint32_t reserved_22_31              : 10;
#endif
	} s;
	/* struct bdk_pciercx_cfg030_s        cn88xx; */
	/* struct bdk_pciercx_cfg030_s        cn88xxp1; */
} bdk_pciercx_cfg030_t;

static inline uint64_t BDK_PCIERCX_CFG030(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG030(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000078ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG030", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG030(...) bdk_pciercx_cfg030_t
#define bustype_BDK_PCIERCX_CFG030(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG030(p1) (p1)
#define arguments_BDK_PCIERCX_CFG030(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG030(...) "PCIERCX_CFG030"


/**
 * PCICONFIGRC - pcierc#_cfg031
 *
 * This register contains the thirty-second 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg031 {
	uint32_t u;
	struct bdk_pciercx_cfg031_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t pnum                        : 8;  /**< RO/WRSL - Port number, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
		uint32_t reserved_23_23              : 1;
		uint32_t aspm                        : 1;  /**< RO/WRSL - ASPM optionality compliance. */
		uint32_t lbnc                        : 1;  /**< RO/WRSL - Link bandwidth notification capability. */
		uint32_t dllarc                      : 1;  /**< RO - Data link layer active reporting capable. Set to 1 for root complex devices and 0 for
                                                                 endpoint devices. */
		uint32_t sderc                       : 1;  /**< RO - Surprise down error reporting capable. Not supported; hardwired to 0. */
		uint32_t cpm                         : 1;  /**< RO - Clock power management. The default value is the value that software specifies during
                                                                 hardware configuration, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. */
		uint32_t l1el                        : 3;  /**< RO/WRSL - L1 exit latency. The default value is the value that software specifies during hardware
                                                                 configuration, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
		uint32_t l0el                        : 3;  /**< RO/WRSL - L0s exit latency. The default value is the value that software specifies during hardware
                                                                 configuration, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
		uint32_t aslpms                      : 2;  /**< RO/WRSL - Active state link PM support. The default value is the value that software specifies
                                                                 during hardware configuration, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
		uint32_t mlw                         : 6;  /**< RO/WRSL/H - Maximum link width.
                                                                 The reset value of this field is determined by the value read from the PEM
                                                                 csr PEM()_CFG[LANES8]. If LANES8 is set the reset value is 0x4, otherwise 0x8.

                                                                 This field is writable through PEM()_CFG_WR. */
		uint32_t mls                         : 4;  /**< RO/WRSL - Maximum link speed. The reset value of this field is controlled by the value read from
                                                                 PEM()_CFG[MD].

                                                                 _ MD is 0x0, reset to 0x1: 2.5 GHz supported.

                                                                 _ MD is 0x1, reset to 0x2: 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x2, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x3, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported (RC Mode).

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
#else
		uint32_t mls                         : 4;
		uint32_t mlw                         : 6;
		uint32_t aslpms                      : 2;
		uint32_t l0el                        : 3;
		uint32_t l1el                        : 3;
		uint32_t cpm                         : 1;
		uint32_t sderc                       : 1;
		uint32_t dllarc                      : 1;
		uint32_t lbnc                        : 1;
		uint32_t aspm                        : 1;
		uint32_t reserved_23_23              : 1;
		uint32_t pnum                        : 8;
#endif
	} s;
	/* struct bdk_pciercx_cfg031_s        cn88xx; */
	/* struct bdk_pciercx_cfg031_s        cn88xxp1; */
} bdk_pciercx_cfg031_t;

static inline uint64_t BDK_PCIERCX_CFG031(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG031(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000007Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG031", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG031(...) bdk_pciercx_cfg031_t
#define bustype_BDK_PCIERCX_CFG031(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG031(p1) (p1)
#define arguments_BDK_PCIERCX_CFG031(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG031(...) "PCIERCX_CFG031"


/**
 * PCICONFIGRC - pcierc#_cfg032
 *
 * This register contains the thirty-third 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg032 {
	uint32_t u;
	struct bdk_pciercx_cfg032_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lab                         : 1;  /**< R/W1C - Link autonomous bandwidth status. This bit is set to indicate that hardware has
                                                                 autonomously changed link speed or width, without the port transitioning through DL_Down
                                                                 status, for reasons other than to attempt to correct unreliable link operation. */
		uint32_t lbm                         : 1;  /**< R/W1C - Link bandwidth management status. This bit is set to indicate either of the following has
                                                                 occurred without the port transitioning through DL_DOWN status:

                                                                 * A link retraining has completed following a write of 1b to the retrain link bit

                                                                 * Hardware has changed the Link speed or width to attempt to correct unreliable link
                                                                 operation, either through a LTSSM timeout of higher level process. This bit must be set if
                                                                 the physical layer reports a speed or width change was initiated by the downstream
                                                                 component that was not indicated as an autonomous change. */
		uint32_t dlla                        : 1;  /**< RO/H - Data link layer active. */
		uint32_t scc                         : 1;  /**< RO/WRSL - Slot clock configuration. Indicates that the component uses the same physical reference
                                                                 clock that the platform provides on the connector. The default value is the value you
                                                                 select during hardware configuration, writable through PEM()_CFG_WR. However, the
                                                                 application must not change this field. */
		uint32_t lt                          : 1;  /**< RO/H - Link training. */
		uint32_t reserved_26_26              : 1;
		uint32_t nlw                         : 6;  /**< RO/H - Negotiated link width. Set automatically by hardware after link initialization. Value is
                                                                 undefined when link is not up. */
		uint32_t ls                          : 4;  /**< RO/H - Current link speed. The encoded value specifies a bit location in the supported link
                                                                 speeds vector (in the link capabilities 2 register) that corresponds to the current link
                                                                 speed.
                                                                 0x1 = Supported link speeds vector field bit 0.
                                                                 0x2 = Supported link speeds vector field bit 1.
                                                                 0x3 = Supported link speeds vector field bit 2. */
		uint32_t reserved_12_15              : 4;
		uint32_t lab_int_enb                 : 1;  /**< R/W - Link autonomous bandwidth interrupt enable. When set, enables the generation of an
                                                                 interrupt to indicate that the link autonomous bandwidth status bit has been set. */
		uint32_t lbm_int_enb                 : 1;  /**< R/W - Link bandwidth management interrupt enable. When set, enables the generation of an
                                                                 interrupt to indicate that the link bandwidth management status bit has been set. */
		uint32_t hawd                        : 1;  /**< RO - Hardware autonomous width disable (not supported). */
		uint32_t ecpm                        : 1;  /**< R/W/H - Enable clock power management. Hardwired to 0 if clock power management is disabled in the
                                                                 link capabilities register. */
		uint32_t es                          : 1;  /**< R/W - Extended synch. */
		uint32_t ccc                         : 1;  /**< R/W - Common clock configuration. */
		uint32_t rl                          : 1;  /**< RO - Retrain link (always 0 for RC). */
		uint32_t ld                          : 1;  /**< R/W - Link disable. */
		uint32_t rcb                         : 1;  /**< RO/WRSL - Read completion boundary (RCB), writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field because an RCB of 64
                                                                 bytes is not supported. */
		uint32_t reserved_2_2                : 1;
		uint32_t aslpc                       : 2;  /**< R/W - Active state link PM control. */
#else
		uint32_t aslpc                       : 2;
		uint32_t reserved_2_2                : 1;
		uint32_t rcb                         : 1;
		uint32_t ld                          : 1;
		uint32_t rl                          : 1;
		uint32_t ccc                         : 1;
		uint32_t es                          : 1;
		uint32_t ecpm                        : 1;
		uint32_t hawd                        : 1;
		uint32_t lbm_int_enb                 : 1;
		uint32_t lab_int_enb                 : 1;
		uint32_t reserved_12_15              : 4;
		uint32_t ls                          : 4;
		uint32_t nlw                         : 6;
		uint32_t reserved_26_26              : 1;
		uint32_t lt                          : 1;
		uint32_t scc                         : 1;
		uint32_t dlla                        : 1;
		uint32_t lbm                         : 1;
		uint32_t lab                         : 1;
#endif
	} s;
	/* struct bdk_pciercx_cfg032_s        cn88xx; */
	/* struct bdk_pciercx_cfg032_s        cn88xxp1; */
} bdk_pciercx_cfg032_t;

static inline uint64_t BDK_PCIERCX_CFG032(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG032(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000080ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG032", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG032(...) bdk_pciercx_cfg032_t
#define bustype_BDK_PCIERCX_CFG032(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG032(p1) (p1)
#define arguments_BDK_PCIERCX_CFG032(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG032(...) "PCIERCX_CFG032"


/**
 * PCICONFIGRC - pcierc#_cfg033
 *
 * This register contains the thirty-fourth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg033 {
	uint32_t u;
	struct bdk_pciercx_cfg033_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ps_num                      : 13; /**< RO/WRSL - Physical slot number, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. */
		uint32_t nccs                        : 1;  /**< RO/WRSL - No command complete support, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
		uint32_t emip                        : 1;  /**< RO/WRSL - Electromechanical interlock present, writable through PEM()_CFG_WR. However, the
                                                                 application must not change this field. */
		uint32_t sp_ls                       : 2;  /**< RO/WRSL - Slot power limit scale, writable through PEM()_CFG_WR. */
		uint32_t sp_lv                       : 8;  /**< RO/WRSL - Slot power limit value, writable through PEM()_CFG_WR. */
		uint32_t hp_c                        : 1;  /**< RO/WRSL - Hot-plug capable, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. */
		uint32_t hp_s                        : 1;  /**< RO/WRSL - Hot-plug surprise, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. */
		uint32_t pip                         : 1;  /**< RO/WRSL - Power indicator present, writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field. */
		uint32_t aip                         : 1;  /**< RO/WRSL - Attention indicator present, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
		uint32_t mrlsp                       : 1;  /**< RO/WRSL - MRL sensor present, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. */
		uint32_t pcp                         : 1;  /**< RO/WRSL - Power controller present, writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field. */
		uint32_t abp                         : 1;  /**< RO/WRSL - Attention button present, writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field. */
#else
		uint32_t abp                         : 1;
		uint32_t pcp                         : 1;
		uint32_t mrlsp                       : 1;
		uint32_t aip                         : 1;
		uint32_t pip                         : 1;
		uint32_t hp_s                        : 1;
		uint32_t hp_c                        : 1;
		uint32_t sp_lv                       : 8;
		uint32_t sp_ls                       : 2;
		uint32_t emip                        : 1;
		uint32_t nccs                        : 1;
		uint32_t ps_num                      : 13;
#endif
	} s;
	/* struct bdk_pciercx_cfg033_s        cn88xx; */
	/* struct bdk_pciercx_cfg033_s        cn88xxp1; */
} bdk_pciercx_cfg033_t;

static inline uint64_t BDK_PCIERCX_CFG033(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG033(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000084ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG033", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG033(...) bdk_pciercx_cfg033_t
#define bustype_BDK_PCIERCX_CFG033(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG033(p1) (p1)
#define arguments_BDK_PCIERCX_CFG033(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG033(...) "PCIERCX_CFG033"


/**
 * PCICONFIGRC - pcierc#_cfg034
 *
 * This register contains the thirty-fifth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg034 {
	uint32_t u;
	struct bdk_pciercx_cfg034_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_25_31              : 7;
		uint32_t dlls_c                      : 1;  /**< R/W1C/H - Data link layer state changed. */
		uint32_t emis                        : 1;  /**< RO - Electromechanical interlock status. */
		uint32_t pds                         : 1;  /**< RO - Presence detect state. */
		uint32_t mrlss                       : 1;  /**< RO - MRL sensor state. */
		uint32_t ccint_d                     : 1;  /**< R/W1C/H - Command completed. */
		uint32_t pd_c                        : 1;  /**< R/W1C/H - Presence detect changed. */
		uint32_t mrls_c                      : 1;  /**< R/W1C/H - MRL sensor changed. */
		uint32_t pf_d                        : 1;  /**< R/W1C/H - Power fault detected. */
		uint32_t abp_d                       : 1;  /**< R/W1C/H - Attention button pressed. */
		uint32_t reserved_13_15              : 3;
		uint32_t dlls_en                     : 1;  /**< R/W - Data link layer state changed enable. */
		uint32_t emic                        : 1;  /**< WO - Electromechanical interlock control. */
		uint32_t pcc                         : 1;  /**< R/W - Power controller control. */
		uint32_t pic                         : 2;  /**< R/W - Power indicator control. */
		uint32_t aic                         : 2;  /**< R/W - Attention indicator control. */
		uint32_t hpint_en                    : 1;  /**< R/W - Hot-plug interrupt enable. */
		uint32_t ccint_en                    : 1;  /**< R/W - Command completed interrupt enable. */
		uint32_t pd_en                       : 1;  /**< R/W - Presence detect changed enable. */
		uint32_t mrls_en                     : 1;  /**< R/W - MRL sensor changed enable. */
		uint32_t pf_en                       : 1;  /**< R/W - Power fault detected enable. */
		uint32_t abp_en                      : 1;  /**< R/W - Attention button pressed enable. */
#else
		uint32_t abp_en                      : 1;
		uint32_t pf_en                       : 1;
		uint32_t mrls_en                     : 1;
		uint32_t pd_en                       : 1;
		uint32_t ccint_en                    : 1;
		uint32_t hpint_en                    : 1;
		uint32_t aic                         : 2;
		uint32_t pic                         : 2;
		uint32_t pcc                         : 1;
		uint32_t emic                        : 1;
		uint32_t dlls_en                     : 1;
		uint32_t reserved_13_15              : 3;
		uint32_t abp_d                       : 1;
		uint32_t pf_d                        : 1;
		uint32_t mrls_c                      : 1;
		uint32_t pd_c                        : 1;
		uint32_t ccint_d                     : 1;
		uint32_t mrlss                       : 1;
		uint32_t pds                         : 1;
		uint32_t emis                        : 1;
		uint32_t dlls_c                      : 1;
		uint32_t reserved_25_31              : 7;
#endif
	} s;
	/* struct bdk_pciercx_cfg034_s        cn88xx; */
	/* struct bdk_pciercx_cfg034_s        cn88xxp1; */
} bdk_pciercx_cfg034_t;

static inline uint64_t BDK_PCIERCX_CFG034(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG034(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000088ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG034", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG034(...) bdk_pciercx_cfg034_t
#define bustype_BDK_PCIERCX_CFG034(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG034(p1) (p1)
#define arguments_BDK_PCIERCX_CFG034(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG034(...) "PCIERCX_CFG034"


/**
 * PCICONFIGRC - pcierc#_cfg035
 *
 * This register contains the thirty-sixth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg035 {
	uint32_t u;
	struct bdk_pciercx_cfg035_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_17_31              : 15;
		uint32_t crssv                       : 1;  /**< RO - CRS software visibility. Not supported, hardwired to 0. */
		uint32_t reserved_5_15               : 11;
		uint32_t crssve                      : 1;  /**< RO - CRS software visibility enable. Not supported, hardwired to 0. */
		uint32_t pmeie                       : 1;  /**< R/W - PME interrupt enable. */
		uint32_t sefee                       : 1;  /**< R/W - System error on fatal error enable. */
		uint32_t senfee                      : 1;  /**< R/W - System error on nonfatal error enable. */
		uint32_t secee                       : 1;  /**< R/W - System error on correctable error enable. */
#else
		uint32_t secee                       : 1;
		uint32_t senfee                      : 1;
		uint32_t sefee                       : 1;
		uint32_t pmeie                       : 1;
		uint32_t crssve                      : 1;
		uint32_t reserved_5_15               : 11;
		uint32_t crssv                       : 1;
		uint32_t reserved_17_31              : 15;
#endif
	} s;
	/* struct bdk_pciercx_cfg035_s        cn88xx; */
	/* struct bdk_pciercx_cfg035_s        cn88xxp1; */
} bdk_pciercx_cfg035_t;

static inline uint64_t BDK_PCIERCX_CFG035(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG035(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000008Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG035", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG035(...) bdk_pciercx_cfg035_t
#define bustype_BDK_PCIERCX_CFG035(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG035(p1) (p1)
#define arguments_BDK_PCIERCX_CFG035(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG035(...) "PCIERCX_CFG035"


/**
 * PCICONFIGRC - pcierc#_cfg036
 *
 * This register contains the thirty-seventh 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg036 {
	uint32_t u;
	struct bdk_pciercx_cfg036_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_18_31              : 14;
		uint32_t pme_pend                    : 1;  /**< RO - PME pending. */
		uint32_t pme_stat                    : 1;  /**< R/W1C/H - PME status. */
		uint32_t pme_rid                     : 16; /**< RO - PME requester ID. */
#else
		uint32_t pme_rid                     : 16;
		uint32_t pme_stat                    : 1;
		uint32_t pme_pend                    : 1;
		uint32_t reserved_18_31              : 14;
#endif
	} s;
	/* struct bdk_pciercx_cfg036_s        cn88xx; */
	/* struct bdk_pciercx_cfg036_s        cn88xxp1; */
} bdk_pciercx_cfg036_t;

static inline uint64_t BDK_PCIERCX_CFG036(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG036(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000090ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG036", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG036(...) bdk_pciercx_cfg036_t
#define bustype_BDK_PCIERCX_CFG036(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG036(p1) (p1)
#define arguments_BDK_PCIERCX_CFG036(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG036(...) "PCIERCX_CFG036"


/**
 * PCICONFIGRC - pcierc#_cfg037
 *
 * This register contains the thirty-eighth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg037 {
	uint32_t u;
	struct bdk_pciercx_cfg037_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t meetp                       : 2;  /**< RO - Max end-end TLP prefixes.
                                                                 0x1 = 1.
                                                                 0x2 = 2.
                                                                 0x3 = 3.
                                                                 0x0 = 4. */
		uint32_t eetps                       : 1;  /**< RO - End-end TLP prefix supported (not supported). */
		uint32_t effs                        : 1;  /**< RO - Extended fmt field supported (not supported). */
		uint32_t obffs                       : 2;  /**< RO - Optimized buffer flush fill (OBFF) supported (not supported). */
		uint32_t reserved_14_17              : 4;
		uint32_t tph                         : 2;  /**< RO - TPH completer supported (not supported). */
		uint32_t ltrs                        : 1;  /**< RO - Latency tolerance reporting (LTR) mechanism supported (not supported). */
		uint32_t noroprpr                    : 1;  /**< RO/H - No RO-enabled PR-PR passing. When set, the routing element never carries out the passing
                                                                 permitted in the relaxed ordering model. */
		uint32_t atom128s                    : 1;  /**< RO - 128-bit AtomicOp supported (not supported). */
		uint32_t atom64s                     : 1;  /**< RO - 64-bit AtomicOp supported. */
		uint32_t atom32s                     : 1;  /**< RO - 32-bit AtomicOp supported. */
		uint32_t atom_ops                    : 1;  /**< RO - AtomicOp routing supported. */
		uint32_t ari_fw                      : 1;  /**< RO - Alternate routing ID forwarding supported. */
		uint32_t ctds                        : 1;  /**< RO - Completion timeout disable supported. */
		uint32_t ctrs                        : 4;  /**< RO/H - Completion timeout ranges supported. */
#else
		uint32_t ctrs                        : 4;
		uint32_t ctds                        : 1;
		uint32_t ari_fw                      : 1;
		uint32_t atom_ops                    : 1;
		uint32_t atom32s                     : 1;
		uint32_t atom64s                     : 1;
		uint32_t atom128s                    : 1;
		uint32_t noroprpr                    : 1;
		uint32_t ltrs                        : 1;
		uint32_t tph                         : 2;
		uint32_t reserved_14_17              : 4;
		uint32_t obffs                       : 2;
		uint32_t effs                        : 1;
		uint32_t eetps                       : 1;
		uint32_t meetp                       : 2;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_pciercx_cfg037_s        cn88xx; */
	/* struct bdk_pciercx_cfg037_s        cn88xxp1; */
} bdk_pciercx_cfg037_t;

static inline uint64_t BDK_PCIERCX_CFG037(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG037(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000094ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG037", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG037(...) bdk_pciercx_cfg037_t
#define bustype_BDK_PCIERCX_CFG037(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG037(p1) (p1)
#define arguments_BDK_PCIERCX_CFG037(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG037(...) "PCIERCX_CFG037"


/**
 * PCICONFIGRC - pcierc#_cfg038
 *
 * This register contains the thirty-ninth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg038 {
	uint32_t u;
	struct bdk_pciercx_cfg038_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t eetpb                       : 1;  /**< RO - Unsupported end-end TLP prefix blocking. */
		uint32_t obffe                       : 2;  /**< RO - Optimized buffer flush fill (OBFF) enable (not supported). */
		uint32_t reserved_11_12              : 2;
		uint32_t ltre                        : 1;  /**< RO - Latency tolerance reporting (LTR) mechanism enable. (not supported). */
		uint32_t id0_cp                      : 1;  /**< RO - ID based ordering completion enable (not supported). */
		uint32_t id0_rq                      : 1;  /**< RO - ID based ordering request enable (not supported). */
		uint32_t atom_op_eb                  : 1;  /**< RO - AtomicOp egress blocking (not supported). */
		uint32_t atom_op                     : 1;  /**< R/W - AtomicOp requester enable. */
		uint32_t ari                         : 1;  /**< R/W - Alternate routing ID forwarding supported. */
		uint32_t ctd                         : 1;  /**< R/W - Completion timeout disable. */
		uint32_t ctv                         : 4;  /**< RO/H - Completion timeout value.
                                                                 0x0 = Default range: 16 ms to 55 ms.
                                                                 0x1 = 50 us to 100 us.
                                                                 0x2 = 1 ms to 10 ms.
                                                                 0x3 = 16 ms to 55 ms.
                                                                 0x6 = 65 ms to 210 ms.
                                                                 0x9 = 260 ms to 900 ms.
                                                                 0xA = 1 s to 3.5 s.
                                                                 0xD = 4 s to 13 s.
                                                                 0xE = 17 s to 64 s.

                                                                 Values not defined are reserved. */
#else
		uint32_t ctv                         : 4;
		uint32_t ctd                         : 1;
		uint32_t ari                         : 1;
		uint32_t atom_op                     : 1;
		uint32_t atom_op_eb                  : 1;
		uint32_t id0_rq                      : 1;
		uint32_t id0_cp                      : 1;
		uint32_t ltre                        : 1;
		uint32_t reserved_11_12              : 2;
		uint32_t obffe                       : 2;
		uint32_t eetpb                       : 1;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_pciercx_cfg038_s        cn88xx; */
	/* struct bdk_pciercx_cfg038_s        cn88xxp1; */
} bdk_pciercx_cfg038_t;

static inline uint64_t BDK_PCIERCX_CFG038(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG038(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000098ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG038", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG038(...) bdk_pciercx_cfg038_t
#define bustype_BDK_PCIERCX_CFG038(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG038(p1) (p1)
#define arguments_BDK_PCIERCX_CFG038(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG038(...) "PCIERCX_CFG038"


/**
 * PCICONFIGRC - pcierc#_cfg039
 *
 * This register contains the fortieth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg039 {
	uint32_t u;
	struct bdk_pciercx_cfg039_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_9_31               : 23;
		uint32_t cls                         : 1;  /**< RO - Crosslink supported. */
		uint32_t slsv                        : 7;  /**< RO/WRSL - Supported link speeds vector. Indicates the supported link speeds of the associated port.
                                                                 For each bit, a value of 1b indicates that the corresponding link speed is supported;
                                                                 otherwise, the link speed is not supported. Bit definitions are:
                                                                 _ Bit \<1\> = 2.5 GT/s.

                                                                 _ Bit \<2\> = 5.0 GT/s.

                                                                 _ Bit \<3\> = 8.0 GT/s (not supported).

                                                                 _ Bits \<7:4\> are reserved.

                                                                 The reset value of this field is controlled by the value read from PEM()_CFG[MD].

                                                                 _ MD is 0x0, reset to 0x1: 2.5 GHz supported.

                                                                 _ MD is 0x1, reset to 0x3: 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x2, reset to 0x7: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x3, reset to 0x7: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported (RC Mode). */
		uint32_t reserved_0_0                : 1;
#else
		uint32_t reserved_0_0                : 1;
		uint32_t slsv                        : 7;
		uint32_t cls                         : 1;
		uint32_t reserved_9_31               : 23;
#endif
	} s;
	/* struct bdk_pciercx_cfg039_s        cn88xx; */
	/* struct bdk_pciercx_cfg039_s        cn88xxp1; */
} bdk_pciercx_cfg039_t;

static inline uint64_t BDK_PCIERCX_CFG039(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG039(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000009Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG039", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG039(...) bdk_pciercx_cfg039_t
#define bustype_BDK_PCIERCX_CFG039(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG039(p1) (p1)
#define arguments_BDK_PCIERCX_CFG039(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG039(...) "PCIERCX_CFG039"


/**
 * PCICONFIGRC - pcierc#_cfg040
 *
 * This register contains the forty-first 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg040 {
	uint32_t u;
	struct bdk_pciercx_cfg040_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_22_31              : 10;
		uint32_t ler                         : 1;  /**< R/W1C/H - Link equalization request */
		uint32_t ep3s                        : 1;  /**< RO/H - Equalization phase 3 successful */
		uint32_t ep2s                        : 1;  /**< RO/H - Equalization phase 2 successful */
		uint32_t ep1s                        : 1;  /**< RO/H - Equalization phase 1 successful */
		uint32_t eqc                         : 1;  /**< RO/H - Equalization complete */
		uint32_t cdl                         : 1;  /**< RO/H - Current deemphasis level. When the link is operating at 5 GT/s speed, this bit reflects
                                                                 the level of deemphasis. Encodings:
                                                                 1: -3.5 dB.
                                                                 0: -6 dB.

                                                                 The value in this bit is undefined when the link is operating at 2.5 GT/s speed. */
		uint32_t cde                         : 4;  /**< R/W - Compliance deemphasis. This bit sets the deemphasis level in Polling.Compliance state if
                                                                 the entry occurred due to the Tx compliance receive bit being 1. Encodings:
                                                                 0x1: -3.5 dB.
                                                                 0x0: -6 dB.

                                                                 When the Link is operating at 2.5 GT/s, the setting of this bit has no effect. */
		uint32_t csos                        : 1;  /**< R/W - Compliance SOS. When set to 1, the LTSSM is required to send SKP ordered sets periodically
                                                                 in between the (modified) compliance patterns.
                                                                 When the link is operating at 2.5 GT/s, the setting of this bit has no effect. */
		uint32_t emc                         : 1;  /**< R/W - Enter modified compliance. When this bit is set to 1, the device transmits a modified
                                                                 compliance pattern if the LTSSM enters Polling.Compliance state. */
		uint32_t tm                          : 3;  /**< R/W/H - Transmit margin. This field controls the value of the non-deemphasized voltage level at
                                                                 the transmitter signals:
                                                                 0x0:  800-1200 mV for full swing 400-600 mV for half-swing
                                                                 0x1-0x2: Values must be monotonic with a nonzero slope
                                                                 0x3: 200-400 mV for full-swing and 100-200 mV for half-swing
                                                                 0x4-0x7: Reserved
                                                                 This field is reset to 0x0 on entry to the LTSSM Polling.Compliance substate. When
                                                                 operating in 5.0 GT/s mode with full swing, the deemphasis ratio must be maintained within
                                                                 +/- 1 dB from the specification-defined operational value either -3.5 or -6 dB. */
		uint32_t sde                         : 1;  /**< RO/WRSL - Selectable deemphasis. When the link is operating at 5.0 GT/s speed, selects the level of
                                                                 deemphasis:
                                                                 1: -3.5 dB.
                                                                 0: -6 dB.

                                                                 When the link is operating at 2.5 GT/s speed, the setting of this bit has no effect. */
		uint32_t hasd                        : 1;  /**< R/W - Hardware autonomous speed disable. When asserted, the application must disable hardware
                                                                 from changing the link speed for device-specific reasons other than attempting to correct
                                                                 unreliable link operation by reducing link speed. Initial transition to the highest
                                                                 supported common link speed is not blocked by this signal. */
		uint32_t ec                          : 1;  /**< R/W - Enter compliance. Software is permitted to force a link to enter compliance mode at the
                                                                 speed indicated in the target link speed field by setting this bit to 1 in both components
                                                                 on a link and then initiating a hot reset on the link. */
		uint32_t tls                         : 4;  /**< R/W - Target link speed. For downstream ports, this field sets an upper limit on link
                                                                 operational speed by restricting the values advertised by the upstream component in its
                                                                 training sequences:

                                                                 0x1 = 2.5 Gb/s target link speed.
                                                                 0x2 = 5 Gb/s target link speed.
                                                                 0x4 = 8 Gb/s target link speed (not supported).

                                                                 All other encodings are reserved.

                                                                 If a value is written to this field that does not correspond to a speed included in the
                                                                 supported link speeds field, the result is undefined. For both upstream and downstream
                                                                 ports, this field is used to set the target compliance mode speed when software is using
                                                                 the enter compliance bit to force a link into compliance mode.
                                                                 The reset value of this field is controlled by the value read from PEM()_CFG[MD].

                                                                 _ MD is 0x0, reset to 0x1: 2.5 GHz supported.

                                                                 _ MD is 0x1, reset to 0x2: 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x2, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x3, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported (RC Mode). */
#else
		uint32_t tls                         : 4;
		uint32_t ec                          : 1;
		uint32_t hasd                        : 1;
		uint32_t sde                         : 1;
		uint32_t tm                          : 3;
		uint32_t emc                         : 1;
		uint32_t csos                        : 1;
		uint32_t cde                         : 4;
		uint32_t cdl                         : 1;
		uint32_t eqc                         : 1;
		uint32_t ep1s                        : 1;
		uint32_t ep2s                        : 1;
		uint32_t ep3s                        : 1;
		uint32_t ler                         : 1;
		uint32_t reserved_22_31              : 10;
#endif
	} s;
	/* struct bdk_pciercx_cfg040_s        cn88xx; */
	/* struct bdk_pciercx_cfg040_s        cn88xxp1; */
} bdk_pciercx_cfg040_t;

static inline uint64_t BDK_PCIERCX_CFG040(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG040(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x00000200000000A0ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG040", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG040(...) bdk_pciercx_cfg040_t
#define bustype_BDK_PCIERCX_CFG040(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG040(p1) (p1)
#define arguments_BDK_PCIERCX_CFG040(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG040(...) "PCIERCX_CFG040"


/**
 * PCICONFIGRC - pcierc#_cfg041
 *
 * This register contains the forty-second 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg041 {
	uint32_t u;
	struct bdk_pciercx_cfg041_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg041_s        cn88xx; */
	/* struct bdk_pciercx_cfg041_s        cn88xxp1; */
} bdk_pciercx_cfg041_t;

static inline uint64_t BDK_PCIERCX_CFG041(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG041(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x00000200000000A4ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG041", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG041(...) bdk_pciercx_cfg041_t
#define bustype_BDK_PCIERCX_CFG041(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG041(p1) (p1)
#define arguments_BDK_PCIERCX_CFG041(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG041(...) "PCIERCX_CFG041"


/**
 * PCICONFIGRC - pcierc#_cfg042
 *
 * This register contains the forty-third 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg042 {
	uint32_t u;
	struct bdk_pciercx_cfg042_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg042_s        cn88xx; */
	/* struct bdk_pciercx_cfg042_s        cn88xxp1; */
} bdk_pciercx_cfg042_t;

static inline uint64_t BDK_PCIERCX_CFG042(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG042(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x00000200000000A8ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG042", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG042(...) bdk_pciercx_cfg042_t
#define bustype_BDK_PCIERCX_CFG042(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG042(p1) (p1)
#define arguments_BDK_PCIERCX_CFG042(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG042(...) "PCIERCX_CFG042"


/**
 * PCICONFIGRC - pcierc#_cfg044
 *
 * This register contains the forty-fifth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg044 {
	uint32_t u;
	struct bdk_pciercx_cfg044_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t msixen                      : 1;  /**< RO/WRSL - MSI-X enable. If MSI-X is enabled, MSI and INTx must be disabled. */
		uint32_t funm                        : 1;  /**< RO/WRSL - Function mask.
                                                                 0 = Each vectors mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits. */
		uint32_t reserved_27_29              : 3;
		uint32_t msixts                      : 11; /**< RO/WRSL/H - MSI-X table size encoded as (table size - 1). */
		uint32_t ncp                         : 8;  /**< RO/WRSL - "Next capability pointer. Writable through PEM\#_CFG_WR. However, the application must not
                                                                 change this field." */
		uint32_t msixcid                     : 8;  /**< RO/H - MSI-X capability ID. */
#else
		uint32_t msixcid                     : 8;
		uint32_t ncp                         : 8;
		uint32_t msixts                      : 11;
		uint32_t reserved_27_29              : 3;
		uint32_t funm                        : 1;
		uint32_t msixen                      : 1;
#endif
	} s;
	/* struct bdk_pciercx_cfg044_s        cn88xx; */
	/* struct bdk_pciercx_cfg044_s        cn88xxp1; */
} bdk_pciercx_cfg044_t;

static inline uint64_t BDK_PCIERCX_CFG044(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG044(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x00000200000000B0ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG044", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG044(...) bdk_pciercx_cfg044_t
#define bustype_BDK_PCIERCX_CFG044(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG044(p1) (p1)
#define arguments_BDK_PCIERCX_CFG044(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG044(...) "PCIERCX_CFG044"


/**
 * PCICONFIGRC - pcierc#_cfg045
 *
 * This register contains the forty-sixth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg045 {
	uint32_t u;
	struct bdk_pciercx_cfg045_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t msixtoffs                   : 29; /**< RO/WRSL/H - MSI-X table offset register. Base address of the MSI-X Table, as an offset from the base
                                                                 address of the BAR indicated by the table BIR bits. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t msixtbir                    : 3;  /**< RO/WRSL - "MSI-X table BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 table into memory space.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field." */
#else
		uint32_t msixtbir                    : 3;
		uint32_t msixtoffs                   : 29;
#endif
	} s;
	/* struct bdk_pciercx_cfg045_s        cn88xx; */
	/* struct bdk_pciercx_cfg045_s        cn88xxp1; */
} bdk_pciercx_cfg045_t;

static inline uint64_t BDK_PCIERCX_CFG045(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG045(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x00000200000000B4ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG045", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG045(...) bdk_pciercx_cfg045_t
#define bustype_BDK_PCIERCX_CFG045(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG045(p1) (p1)
#define arguments_BDK_PCIERCX_CFG045(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG045(...) "PCIERCX_CFG045"


/**
 * PCICONFIGRC - pcierc#_cfg046
 *
 * This register contains the forty-seventh 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg046 {
	uint32_t u;
	struct bdk_pciercx_cfg046_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t msixpoffs                   : 29; /**< RO/WRSL/H - MSI-X table offset register. Base address of the MSI-X PBA, as an offset from the base
                                                                 address of the BAR indicated by the table PBA bits. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t msixpbir                    : 3;  /**< RO/WRSL - "MSI-X PBA BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 pending bit array into memory space.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field." */
#else
		uint32_t msixpbir                    : 3;
		uint32_t msixpoffs                   : 29;
#endif
	} s;
	/* struct bdk_pciercx_cfg046_s        cn88xx; */
	/* struct bdk_pciercx_cfg046_s        cn88xxp1; */
} bdk_pciercx_cfg046_t;

static inline uint64_t BDK_PCIERCX_CFG046(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG046(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x00000200000000B8ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG046", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG046(...) bdk_pciercx_cfg046_t
#define bustype_BDK_PCIERCX_CFG046(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG046(p1) (p1)
#define arguments_BDK_PCIERCX_CFG046(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG046(...) "PCIERCX_CFG046"


/**
 * PCICONFIGRC - pcierc#_cfg064
 *
 * This register contains the sixty-fifth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg064 {
	uint32_t u;
	struct bdk_pciercx_cfg064_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t nco                         : 12; /**< RO/WRSL - Next capability offset. Points to the secondary PCI Express capabilities by default.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t cv                          : 4;  /**< RO/WRSL - Capability version.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t pcieec                      : 16; /**< RO/WRSL - PCI Express extended capability.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else
		uint32_t pcieec                      : 16;
		uint32_t cv                          : 4;
		uint32_t nco                         : 12;
#endif
	} s;
	/* struct bdk_pciercx_cfg064_s        cn88xx; */
	/* struct bdk_pciercx_cfg064_s        cn88xxp1; */
} bdk_pciercx_cfg064_t;

static inline uint64_t BDK_PCIERCX_CFG064(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG064(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000100ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG064", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG064(...) bdk_pciercx_cfg064_t
#define bustype_BDK_PCIERCX_CFG064(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG064(p1) (p1)
#define arguments_BDK_PCIERCX_CFG064(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG064(...) "PCIERCX_CFG064"


/**
 * PCICONFIGRC - pcierc#_cfg065
 *
 * This register contains the sixty-sixth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg065 {
	uint32_t u;
	struct bdk_pciercx_cfg065_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_26_31              : 6;
		uint32_t tpbes                       : 1;  /**< RO - Unsupported TLP prefix blocked error status. */
		uint32_t uatombs                     : 1;  /**< RO - Unsupported AtomicOp egress blocked status. */
		uint32_t reserved_23_23              : 1;
		uint32_t ucies                       : 1;  /**< R/W1C/H - Uncorrectable internal error status. */
		uint32_t reserved_21_21              : 1;
		uint32_t ures                        : 1;  /**< R/W1C/H - Unsupported request error status. */
		uint32_t ecrces                      : 1;  /**< R/W1C/H - ECRC error status. */
		uint32_t mtlps                       : 1;  /**< R/W1C/H - Malformed TLP status. */
		uint32_t ros                         : 1;  /**< R/W1C/H - Receiver overflow status. */
		uint32_t ucs                         : 1;  /**< R/W1C/H - Unexpected completion status */
		uint32_t cas                         : 1;  /**< R/W1C/H - Completer abort status. */
		uint32_t cts                         : 1;  /**< R/W1C/H - Completion timeout status. */
		uint32_t fcpes                       : 1;  /**< R/W1C/H - Flow control protocol error status. */
		uint32_t ptlps                       : 1;  /**< R/W1C/H - Poisoned TLP status. */
		uint32_t reserved_6_11               : 6;
		uint32_t sdes                        : 1;  /**< RO - Surprise down error status (not supported). */
		uint32_t dlpes                       : 1;  /**< R/W1C/H - Data link protocol error status. */
		uint32_t reserved_0_3                : 4;
#else
		uint32_t reserved_0_3                : 4;
		uint32_t dlpes                       : 1;
		uint32_t sdes                        : 1;
		uint32_t reserved_6_11               : 6;
		uint32_t ptlps                       : 1;
		uint32_t fcpes                       : 1;
		uint32_t cts                         : 1;
		uint32_t cas                         : 1;
		uint32_t ucs                         : 1;
		uint32_t ros                         : 1;
		uint32_t mtlps                       : 1;
		uint32_t ecrces                      : 1;
		uint32_t ures                        : 1;
		uint32_t reserved_21_21              : 1;
		uint32_t ucies                       : 1;
		uint32_t reserved_23_23              : 1;
		uint32_t uatombs                     : 1;
		uint32_t tpbes                       : 1;
		uint32_t reserved_26_31              : 6;
#endif
	} s;
	/* struct bdk_pciercx_cfg065_s        cn88xx; */
	/* struct bdk_pciercx_cfg065_s        cn88xxp1; */
} bdk_pciercx_cfg065_t;

static inline uint64_t BDK_PCIERCX_CFG065(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG065(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000104ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG065", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG065(...) bdk_pciercx_cfg065_t
#define bustype_BDK_PCIERCX_CFG065(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG065(p1) (p1)
#define arguments_BDK_PCIERCX_CFG065(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG065(...) "PCIERCX_CFG065"


/**
 * PCICONFIGRC - pcierc#_cfg066
 *
 * This register contains the sixty-seventh 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg066 {
	uint32_t u;
	struct bdk_pciercx_cfg066_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_26_31              : 6;
		uint32_t tpbem                       : 1;  /**< RO - Unsupported TLP prefix blocked error mask. */
		uint32_t uatombm                     : 1;  /**< RO/H - Unsupported AtomicOp egress blocked status. */
		uint32_t reserved_23_23              : 1;
		uint32_t uciem                       : 1;  /**< R/W - Uncorrectable internal error mask. */
		uint32_t reserved_21_21              : 1;
		uint32_t urem                        : 1;  /**< R/W - Unsupported request error mask. */
		uint32_t ecrcem                      : 1;  /**< R/W - ECRC error mask. */
		uint32_t mtlpm                       : 1;  /**< R/W - Malformed TLP mask. */
		uint32_t rom                         : 1;  /**< R/W - Receiver overflow mask. */
		uint32_t ucm                         : 1;  /**< R/W - Unexpected completion mask. */
		uint32_t cam                         : 1;  /**< R/W - Completer abort mask. */
		uint32_t ctm                         : 1;  /**< R/W - Completion timeout mask. */
		uint32_t fcpem                       : 1;  /**< R/W - Flow control protocol error mask. */
		uint32_t ptlpm                       : 1;  /**< R/W - Poisoned TLP mask. */
		uint32_t reserved_6_11               : 6;
		uint32_t sdem                        : 1;  /**< RO - Surprise down error mask (not supported). */
		uint32_t dlpem                       : 1;  /**< R/W - Data link protocol error mask. */
		uint32_t reserved_0_3                : 4;
#else
		uint32_t reserved_0_3                : 4;
		uint32_t dlpem                       : 1;
		uint32_t sdem                        : 1;
		uint32_t reserved_6_11               : 6;
		uint32_t ptlpm                       : 1;
		uint32_t fcpem                       : 1;
		uint32_t ctm                         : 1;
		uint32_t cam                         : 1;
		uint32_t ucm                         : 1;
		uint32_t rom                         : 1;
		uint32_t mtlpm                       : 1;
		uint32_t ecrcem                      : 1;
		uint32_t urem                        : 1;
		uint32_t reserved_21_21              : 1;
		uint32_t uciem                       : 1;
		uint32_t reserved_23_23              : 1;
		uint32_t uatombm                     : 1;
		uint32_t tpbem                       : 1;
		uint32_t reserved_26_31              : 6;
#endif
	} s;
	/* struct bdk_pciercx_cfg066_s        cn88xx; */
	/* struct bdk_pciercx_cfg066_s        cn88xxp1; */
} bdk_pciercx_cfg066_t;

static inline uint64_t BDK_PCIERCX_CFG066(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG066(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000108ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG066", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG066(...) bdk_pciercx_cfg066_t
#define bustype_BDK_PCIERCX_CFG066(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG066(p1) (p1)
#define arguments_BDK_PCIERCX_CFG066(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG066(...) "PCIERCX_CFG066"


/**
 * PCICONFIGRC - pcierc#_cfg067
 *
 * This register contains the sixty-eighth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg067 {
	uint32_t u;
	struct bdk_pciercx_cfg067_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_26_31              : 6;
		uint32_t tpbes                       : 1;  /**< RO - Unsupported TLP prefix blocked error severity. */
		uint32_t uatombs                     : 1;  /**< RO/H - Unsupported AtomicOp egress blocked severity. */
		uint32_t unsuperr                    : 3;  /**< RO/H - Reserved. */
		uint32_t ures                        : 1;  /**< R/W - Unsupported request error severity. */
		uint32_t ecrces                      : 1;  /**< R/W - ECRC error severity. */
		uint32_t mtlps                       : 1;  /**< R/W - Malformed TLP severity. */
		uint32_t ros                         : 1;  /**< R/W - Receiver overflow severity. */
		uint32_t ucs                         : 1;  /**< R/W - Unexpected completion severity. */
		uint32_t cas                         : 1;  /**< R/W - Completer abort severity. */
		uint32_t cts                         : 1;  /**< R/W - Completion timeout severity. */
		uint32_t fcpes                       : 1;  /**< R/W - Flow control protocol error severity. */
		uint32_t ptlps                       : 1;  /**< R/W - Poisoned TLP severity. */
		uint32_t reserved_6_11               : 6;
		uint32_t sdes                        : 1;  /**< RO - Surprise down error severity (not supported). */
		uint32_t dlpes                       : 1;  /**< R/W - Data link protocol error severity. */
		uint32_t reserved_0_3                : 4;
#else
		uint32_t reserved_0_3                : 4;
		uint32_t dlpes                       : 1;
		uint32_t sdes                        : 1;
		uint32_t reserved_6_11               : 6;
		uint32_t ptlps                       : 1;
		uint32_t fcpes                       : 1;
		uint32_t cts                         : 1;
		uint32_t cas                         : 1;
		uint32_t ucs                         : 1;
		uint32_t ros                         : 1;
		uint32_t mtlps                       : 1;
		uint32_t ecrces                      : 1;
		uint32_t ures                        : 1;
		uint32_t unsuperr                    : 3;
		uint32_t uatombs                     : 1;
		uint32_t tpbes                       : 1;
		uint32_t reserved_26_31              : 6;
#endif
	} s;
	/* struct bdk_pciercx_cfg067_s        cn88xx; */
	/* struct bdk_pciercx_cfg067_s        cn88xxp1; */
} bdk_pciercx_cfg067_t;

static inline uint64_t BDK_PCIERCX_CFG067(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG067(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000010Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG067", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG067(...) bdk_pciercx_cfg067_t
#define bustype_BDK_PCIERCX_CFG067(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG067(p1) (p1)
#define arguments_BDK_PCIERCX_CFG067(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG067(...) "PCIERCX_CFG067"


/**
 * PCICONFIGRC - pcierc#_cfg068
 *
 * This register contains the sixty-ninth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg068 {
	uint32_t u;
	struct bdk_pciercx_cfg068_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_15_31              : 17;
		uint32_t cies                        : 1;  /**< R/W1C - Corrected internal error status. */
		uint32_t anfes                       : 1;  /**< R/W1C/H - Advisory nonfatal error status. */
		uint32_t rtts                        : 1;  /**< R/W1C/H - Replay timer timeout status. */
		uint32_t reserved_9_11               : 3;
		uint32_t rnrs                        : 1;  /**< R/W1C/H - REPLAY_NUM rollover status. */
		uint32_t bdllps                      : 1;  /**< R/W1C/H - Bad DLLP status. */
		uint32_t btlps                       : 1;  /**< R/W1C/H - Bad TLP status. */
		uint32_t reserved_1_5                : 5;
		uint32_t res                         : 1;  /**< R/W1C/H - Receiver error status. */
#else
		uint32_t res                         : 1;
		uint32_t reserved_1_5                : 5;
		uint32_t btlps                       : 1;
		uint32_t bdllps                      : 1;
		uint32_t rnrs                        : 1;
		uint32_t reserved_9_11               : 3;
		uint32_t rtts                        : 1;
		uint32_t anfes                       : 1;
		uint32_t cies                        : 1;
		uint32_t reserved_15_31              : 17;
#endif
	} s;
	/* struct bdk_pciercx_cfg068_s        cn88xx; */
	/* struct bdk_pciercx_cfg068_s        cn88xxp1; */
} bdk_pciercx_cfg068_t;

static inline uint64_t BDK_PCIERCX_CFG068(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG068(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000110ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG068", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG068(...) bdk_pciercx_cfg068_t
#define bustype_BDK_PCIERCX_CFG068(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG068(p1) (p1)
#define arguments_BDK_PCIERCX_CFG068(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG068(...) "PCIERCX_CFG068"


/**
 * PCICONFIGRC - pcierc#_cfg069
 *
 * This register contains the seventieth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg069 {
	uint32_t u;
	struct bdk_pciercx_cfg069_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_15_31              : 17;
		uint32_t ciem                        : 1;  /**< R/W - Corrected internal error mask. */
		uint32_t anfem                       : 1;  /**< R/W - Advisory nonfatal error mask. */
		uint32_t rttm                        : 1;  /**< R/W - Replay timer timeout mask. */
		uint32_t reserved_9_11               : 3;
		uint32_t rnrm                        : 1;  /**< R/W - REPLAY_NUM rollover mask. */
		uint32_t bdllpm                      : 1;  /**< R/W - Bad DLLP mask. */
		uint32_t btlpm                       : 1;  /**< R/W - Bad TLP mask. */
		uint32_t reserved_1_5                : 5;
		uint32_t rem                         : 1;  /**< R/W - Receiver error mask. */
#else
		uint32_t rem                         : 1;
		uint32_t reserved_1_5                : 5;
		uint32_t btlpm                       : 1;
		uint32_t bdllpm                      : 1;
		uint32_t rnrm                        : 1;
		uint32_t reserved_9_11               : 3;
		uint32_t rttm                        : 1;
		uint32_t anfem                       : 1;
		uint32_t ciem                        : 1;
		uint32_t reserved_15_31              : 17;
#endif
	} s;
	/* struct bdk_pciercx_cfg069_s        cn88xx; */
	/* struct bdk_pciercx_cfg069_s        cn88xxp1; */
} bdk_pciercx_cfg069_t;

static inline uint64_t BDK_PCIERCX_CFG069(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG069(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000114ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG069", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG069(...) bdk_pciercx_cfg069_t
#define bustype_BDK_PCIERCX_CFG069(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG069(p1) (p1)
#define arguments_BDK_PCIERCX_CFG069(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG069(...) "PCIERCX_CFG069"


/**
 * PCICONFIGRC - pcierc#_cfg070
 *
 * This register contains the seventy-first 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg070 {
	uint32_t u;
	struct bdk_pciercx_cfg070_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_12_31              : 20;
		uint32_t tplp                        : 1;  /**< RO - TLP prefix log present. */
		uint32_t reserved_9_10               : 2;
		uint32_t ce                          : 1;  /**< R/W - ECRC check enable. */
		uint32_t cc                          : 1;  /**< RO - ECRC check capable. */
		uint32_t ge                          : 1;  /**< R/W - ECRC generation enable. */
		uint32_t gc                          : 1;  /**< RO - ECRC generation capability. */
		uint32_t fep                         : 5;  /**< RO - First error pointer. */
#else
		uint32_t fep                         : 5;
		uint32_t gc                          : 1;
		uint32_t ge                          : 1;
		uint32_t cc                          : 1;
		uint32_t ce                          : 1;
		uint32_t reserved_9_10               : 2;
		uint32_t tplp                        : 1;
		uint32_t reserved_12_31              : 20;
#endif
	} s;
	/* struct bdk_pciercx_cfg070_s        cn88xx; */
	/* struct bdk_pciercx_cfg070_s        cn88xxp1; */
} bdk_pciercx_cfg070_t;

static inline uint64_t BDK_PCIERCX_CFG070(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG070(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000118ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG070", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG070(...) bdk_pciercx_cfg070_t
#define bustype_BDK_PCIERCX_CFG070(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG070(p1) (p1)
#define arguments_BDK_PCIERCX_CFG070(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG070(...) "PCIERCX_CFG070"


/**
 * PCICONFIGRC - pcierc#_cfg071
 *
 * This register contains the seventy-second 32-bits of PCIe type 1 configuration space.  The
 * header log registers collect the header for the TLP corresponding to a detected error.
 */
typedef union bdk_pciercx_cfg071 {
	uint32_t u;
	struct bdk_pciercx_cfg071_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dword1                      : 32; /**< RO - Header log register (first DWORD). */
#else
		uint32_t dword1                      : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg071_s        cn88xx; */
	/* struct bdk_pciercx_cfg071_s        cn88xxp1; */
} bdk_pciercx_cfg071_t;

static inline uint64_t BDK_PCIERCX_CFG071(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG071(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000011Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG071", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG071(...) bdk_pciercx_cfg071_t
#define bustype_BDK_PCIERCX_CFG071(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG071(p1) (p1)
#define arguments_BDK_PCIERCX_CFG071(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG071(...) "PCIERCX_CFG071"


/**
 * PCICONFIGRC - pcierc#_cfg072
 *
 * This register contains the seventy-third 32-bits of PCIe type 1 configuration space.  The
 * header log registers collect the header for the TLP corresponding to a detected error.
 */
typedef union bdk_pciercx_cfg072 {
	uint32_t u;
	struct bdk_pciercx_cfg072_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dword2                      : 32; /**< RO - Header log register (second DWORD). */
#else
		uint32_t dword2                      : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg072_s        cn88xx; */
	/* struct bdk_pciercx_cfg072_s        cn88xxp1; */
} bdk_pciercx_cfg072_t;

static inline uint64_t BDK_PCIERCX_CFG072(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG072(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000120ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG072", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG072(...) bdk_pciercx_cfg072_t
#define bustype_BDK_PCIERCX_CFG072(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG072(p1) (p1)
#define arguments_BDK_PCIERCX_CFG072(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG072(...) "PCIERCX_CFG072"


/**
 * PCICONFIGRC - pcierc#_cfg073
 *
 * This register contains the seventy-fourth 32-bits of PCIe type 1 configuration space.  The
 * header log registers collect the header for the TLP corresponding to a detected error.
 */
typedef union bdk_pciercx_cfg073 {
	uint32_t u;
	struct bdk_pciercx_cfg073_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dword3                      : 32; /**< RO - Header log register (third DWORD). */
#else
		uint32_t dword3                      : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg073_s        cn88xx; */
	/* struct bdk_pciercx_cfg073_s        cn88xxp1; */
} bdk_pciercx_cfg073_t;

static inline uint64_t BDK_PCIERCX_CFG073(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG073(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000124ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG073", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG073(...) bdk_pciercx_cfg073_t
#define bustype_BDK_PCIERCX_CFG073(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG073(p1) (p1)
#define arguments_BDK_PCIERCX_CFG073(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG073(...) "PCIERCX_CFG073"


/**
 * PCICONFIGRC - pcierc#_cfg074
 *
 * This register contains the seventy-fifth 32-bits of PCIe type 1 configuration space.  The
 * header log registers collect the header for the TLP corresponding to a detected error.
 */
typedef union bdk_pciercx_cfg074 {
	uint32_t u;
	struct bdk_pciercx_cfg074_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dword4                      : 32; /**< RO - Header log register (fourth DWORD). */
#else
		uint32_t dword4                      : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg074_s        cn88xx; */
	/* struct bdk_pciercx_cfg074_s        cn88xxp1; */
} bdk_pciercx_cfg074_t;

static inline uint64_t BDK_PCIERCX_CFG074(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG074(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000128ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG074", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG074(...) bdk_pciercx_cfg074_t
#define bustype_BDK_PCIERCX_CFG074(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG074(p1) (p1)
#define arguments_BDK_PCIERCX_CFG074(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG074(...) "PCIERCX_CFG074"


/**
 * PCICONFIGRC - pcierc#_cfg075
 *
 * This register contains the seventy-sixth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg075 {
	uint32_t u;
	struct bdk_pciercx_cfg075_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t fere                        : 1;  /**< R/W - Fatal error reporting enable. */
		uint32_t nfere                       : 1;  /**< R/W - Nonfatal error reporting enable. */
		uint32_t cere                        : 1;  /**< R/W - Correctable error reporting enable. */
#else
		uint32_t cere                        : 1;
		uint32_t nfere                       : 1;
		uint32_t fere                        : 1;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_pciercx_cfg075_s        cn88xx; */
	/* struct bdk_pciercx_cfg075_s        cn88xxp1; */
} bdk_pciercx_cfg075_t;

static inline uint64_t BDK_PCIERCX_CFG075(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG075(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000012Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG075", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG075(...) bdk_pciercx_cfg075_t
#define bustype_BDK_PCIERCX_CFG075(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG075(p1) (p1)
#define arguments_BDK_PCIERCX_CFG075(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG075(...) "PCIERCX_CFG075"


/**
 * PCICONFIGRC - pcierc#_cfg076
 *
 * This register contains the seventy-seventh 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg076 {
	uint32_t u;
	struct bdk_pciercx_cfg076_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t aeimn                       : 5;  /**< RO/WRSL - Advanced error interrupt message number, writable through
                                                                 PEM()_CFG_WR. */
		uint32_t reserved_7_26               : 20;
		uint32_t femr                        : 1;  /**< R/W1C/H - Fatal error messages received. */
		uint32_t nfemr                       : 1;  /**< R/W1C/H - Nonfatal error messages received. */
		uint32_t fuf                         : 1;  /**< R/W1C/H - First uncorrectable fatal. */
		uint32_t multi_efnfr                 : 1;  /**< R/W1C/H - Multiple ERR_FATAL/NONFATAL received. */
		uint32_t efnfr                       : 1;  /**< R/W1C/H - ERR_FATAL/NONFATAL received. */
		uint32_t multi_ecr                   : 1;  /**< R/W1C/H - Multiple ERR_COR received. */
		uint32_t ecr                         : 1;  /**< R/W1C/H - ERR_COR received. */
#else
		uint32_t ecr                         : 1;
		uint32_t multi_ecr                   : 1;
		uint32_t efnfr                       : 1;
		uint32_t multi_efnfr                 : 1;
		uint32_t fuf                         : 1;
		uint32_t nfemr                       : 1;
		uint32_t femr                        : 1;
		uint32_t reserved_7_26               : 20;
		uint32_t aeimn                       : 5;
#endif
	} s;
	/* struct bdk_pciercx_cfg076_s        cn88xx; */
	/* struct bdk_pciercx_cfg076_s        cn88xxp1; */
} bdk_pciercx_cfg076_t;

static inline uint64_t BDK_PCIERCX_CFG076(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG076(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000130ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG076", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG076(...) bdk_pciercx_cfg076_t
#define bustype_BDK_PCIERCX_CFG076(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG076(p1) (p1)
#define arguments_BDK_PCIERCX_CFG076(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG076(...) "PCIERCX_CFG076"


/**
 * PCICONFIGRC - pcierc#_cfg077
 *
 * This register contains the seventy-eighth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg077 {
	uint32_t u;
	struct bdk_pciercx_cfg077_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t efnfsi                      : 16; /**< RO - ERR_FATAL/NONFATAL source identification. */
		uint32_t ecsi                        : 16; /**< RO - ERR_COR source identification. */
#else
		uint32_t ecsi                        : 16;
		uint32_t efnfsi                      : 16;
#endif
	} s;
	/* struct bdk_pciercx_cfg077_s        cn88xx; */
	/* struct bdk_pciercx_cfg077_s        cn88xxp1; */
} bdk_pciercx_cfg077_t;

static inline uint64_t BDK_PCIERCX_CFG077(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG077(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000134ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG077", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG077(...) bdk_pciercx_cfg077_t
#define bustype_BDK_PCIERCX_CFG077(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG077(p1) (p1)
#define arguments_BDK_PCIERCX_CFG077(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG077(...) "PCIERCX_CFG077"


/**
 * PCICONFIGRC - pcierc#_cfg086
 *
 * This register contains the eighty-ninth 32-bits of type 0 PCIe configuration space.
 *
 */
typedef union bdk_pciercx_cfg086 {
	uint32_t u;
	struct bdk_pciercx_cfg086_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t nco                         : 12; /**< RO/WRSL/H - Next capability offset.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t cv                          : 4;  /**< RO/WRSL - Capability version.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t pcieec                      : 16; /**< RO/WRSL - PCIE Express extended capability.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else
		uint32_t pcieec                      : 16;
		uint32_t cv                          : 4;
		uint32_t nco                         : 12;
#endif
	} s;
	/* struct bdk_pciercx_cfg086_s        cn88xx; */
	/* struct bdk_pciercx_cfg086_s        cn88xxp1; */
} bdk_pciercx_cfg086_t;

static inline uint64_t BDK_PCIERCX_CFG086(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG086(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000158ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG086", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG086(...) bdk_pciercx_cfg086_t
#define bustype_BDK_PCIERCX_CFG086(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG086(p1) (p1)
#define arguments_BDK_PCIERCX_CFG086(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG086(...) "PCIERCX_CFG086"


/**
 * PCICONFIGRC - pcierc#_cfg087
 *
 * This register contains the eighty-eighth 32-bits of type 0 PCIe configuration space.
 *
 */
typedef union bdk_pciercx_cfg087 {
	uint32_t u;
	struct bdk_pciercx_cfg087_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_2_31               : 30;
		uint32_t ler                         : 1;  /**< RO/WRSL - Link equalization request interrupt enable. */
		uint32_t pe                          : 1;  /**< RO/WRSL - Perform equalization. */
#else
		uint32_t pe                          : 1;
		uint32_t ler                         : 1;
		uint32_t reserved_2_31               : 30;
#endif
	} s;
	/* struct bdk_pciercx_cfg087_s        cn88xx; */
	/* struct bdk_pciercx_cfg087_s        cn88xxp1; */
} bdk_pciercx_cfg087_t;

static inline uint64_t BDK_PCIERCX_CFG087(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG087(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000015Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG087", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG087(...) bdk_pciercx_cfg087_t
#define bustype_BDK_PCIERCX_CFG087(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG087(p1) (p1)
#define arguments_BDK_PCIERCX_CFG087(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG087(...) "PCIERCX_CFG087"


/**
 * PCICONFIGRC - pcierc#_cfg088
 *
 * This register contains the eighty-ninth 32-bits of type 0 PCIe configuration space.
 *
 */
typedef union bdk_pciercx_cfg088 {
	uint32_t u;
	struct bdk_pciercx_cfg088_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t les                         : 8;  /**< R/W1C - Lane error status bits. */
#else
		uint32_t les                         : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_pciercx_cfg088_s        cn88xx; */
	/* struct bdk_pciercx_cfg088_s        cn88xxp1; */
} bdk_pciercx_cfg088_t;

static inline uint64_t BDK_PCIERCX_CFG088(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG088(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000160ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG088", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG088(...) bdk_pciercx_cfg088_t
#define bustype_BDK_PCIERCX_CFG088(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG088(p1) (p1)
#define arguments_BDK_PCIERCX_CFG088(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG088(...) "PCIERCX_CFG088"


/**
 * PCICONFIGRC - pcierc#_cfg089
 *
 * This register contains the ninetieth 32-bits of type 0 PCIe configuration space.
 *
 */
typedef union bdk_pciercx_cfg089 {
	uint32_t u;
	struct bdk_pciercx_cfg089_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t l1urph                      : 3;  /**< RO/WRSL/H - Lane 1 upstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l1utp                       : 4;  /**< RO/WRSL/H - Lane 1 upstream component transmitter preset. Writable through PEM()_CFG_WR. However,
                                                                 the application must not change this field. */
		uint32_t reserved_23_23              : 1;
		uint32_t l1drph                      : 3;  /**< RO/WRSL/H - Lane 1 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l1ddtp                      : 4;  /**< RO/WRSL/H - Lane 1 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t reserved_15_15              : 1;
		uint32_t l0urph                      : 3;  /**< RO/WRSL/H - Lane 0 upstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l0utp                       : 4;  /**< RO/WRSL/H - Lane 0 upstream component transmitter preset. Writable through PEM()_CFG_WR. However,
                                                                 the application must not change this field. */
		uint32_t reserved_7_7                : 1;
		uint32_t l0drph                      : 3;  /**< RO/WRSL/H - Lane 0 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l0dtp                       : 4;  /**< RO/WRSL/H - Lane 0 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
#else
		uint32_t l0dtp                       : 4;
		uint32_t l0drph                      : 3;
		uint32_t reserved_7_7                : 1;
		uint32_t l0utp                       : 4;
		uint32_t l0urph                      : 3;
		uint32_t reserved_15_15              : 1;
		uint32_t l1ddtp                      : 4;
		uint32_t l1drph                      : 3;
		uint32_t reserved_23_23              : 1;
		uint32_t l1utp                       : 4;
		uint32_t l1urph                      : 3;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_pciercx_cfg089_s        cn88xx; */
	/* struct bdk_pciercx_cfg089_s        cn88xxp1; */
} bdk_pciercx_cfg089_t;

static inline uint64_t BDK_PCIERCX_CFG089(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG089(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000164ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG089", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG089(...) bdk_pciercx_cfg089_t
#define bustype_BDK_PCIERCX_CFG089(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG089(p1) (p1)
#define arguments_BDK_PCIERCX_CFG089(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG089(...) "PCIERCX_CFG089"


/**
 * PCICONFIGRC - pcierc#_cfg090
 *
 * This register contains the ninety-first 32-bits of type 0 PCIe configuration space.
 *
 */
typedef union bdk_pciercx_cfg090 {
	uint32_t u;
	struct bdk_pciercx_cfg090_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t l3urph                      : 3;  /**< RO/WRSL/H - Lane 3 upstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l3utp                       : 4;  /**< RO/WRSL/H - Lane 3 upstream component transmitter preset. Writable through PEM()_CFG_WR. However,
                                                                 the application must not change this field. */
		uint32_t reserved_23_23              : 1;
		uint32_t l3drph                      : 3;  /**< RO/WRSL/H - Lane 3 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l3dtp                       : 4;  /**< RO/WRSL/H - Lane 3 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t reserved_15_15              : 1;
		uint32_t l2urph                      : 3;  /**< RO/WRSL/H - Lane 2 upstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l2utp                       : 4;  /**< RO/WRSL/H - Lane 2 upstream component transmitter preset. Writable through PEM()_CFG_WR. However,
                                                                 the application must not change this field. */
		uint32_t reserved_7_7                : 1;
		uint32_t l2drph                      : 3;  /**< RO/WRSL/H - Lane 2 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l2dtp                       : 4;  /**< RO/WRSL/H - Lane 2 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
#else
		uint32_t l2dtp                       : 4;
		uint32_t l2drph                      : 3;
		uint32_t reserved_7_7                : 1;
		uint32_t l2utp                       : 4;
		uint32_t l2urph                      : 3;
		uint32_t reserved_15_15              : 1;
		uint32_t l3dtp                       : 4;
		uint32_t l3drph                      : 3;
		uint32_t reserved_23_23              : 1;
		uint32_t l3utp                       : 4;
		uint32_t l3urph                      : 3;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_pciercx_cfg090_s        cn88xx; */
	/* struct bdk_pciercx_cfg090_s        cn88xxp1; */
} bdk_pciercx_cfg090_t;

static inline uint64_t BDK_PCIERCX_CFG090(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG090(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000168ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG090", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG090(...) bdk_pciercx_cfg090_t
#define bustype_BDK_PCIERCX_CFG090(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG090(p1) (p1)
#define arguments_BDK_PCIERCX_CFG090(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG090(...) "PCIERCX_CFG090"


/**
 * PCICONFIGRC - pcierc#_cfg091
 *
 * This register contains the ninety-second 32-bits of type 0 PCIe configuration space.
 *
 */
typedef union bdk_pciercx_cfg091 {
	uint32_t u;
	struct bdk_pciercx_cfg091_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t l5urph                      : 3;  /**< RO/WRSL/H - Lane 5 upstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l5utp                       : 4;  /**< RO/WRSL/H - Lane 5 upstream component transmitter preset. Writable through PEM()_CFG_WR. However,
                                                                 the application must not change this field. */
		uint32_t reserved_23_23              : 1;
		uint32_t l5drph                      : 3;  /**< RO/WRSL/H - Lane 5 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l5dtp                       : 4;  /**< RO/WRSL/H - Lane 5 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t reserved_15_15              : 1;
		uint32_t l4urph                      : 3;  /**< RO/WRSL/H - Lane 4 upstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l4utp                       : 4;  /**< RO/WRSL/H - Lane 4 upstream component transmitter preset. Writable through PEM()_CFG_WR. However,
                                                                 the application must not change this field. */
		uint32_t reserved_7_7                : 1;
		uint32_t l4drph                      : 3;  /**< RO/WRSL/H - Lane 4 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l4dtp                       : 4;  /**< RO/WRSL/H - Lane 4 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
#else
		uint32_t l4dtp                       : 4;
		uint32_t l4drph                      : 3;
		uint32_t reserved_7_7                : 1;
		uint32_t l4utp                       : 4;
		uint32_t l4urph                      : 3;
		uint32_t reserved_15_15              : 1;
		uint32_t l5dtp                       : 4;
		uint32_t l5drph                      : 3;
		uint32_t reserved_23_23              : 1;
		uint32_t l5utp                       : 4;
		uint32_t l5urph                      : 3;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_pciercx_cfg091_s        cn88xx; */
	/* struct bdk_pciercx_cfg091_s        cn88xxp1; */
} bdk_pciercx_cfg091_t;

static inline uint64_t BDK_PCIERCX_CFG091(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG091(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000016Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG091", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG091(...) bdk_pciercx_cfg091_t
#define bustype_BDK_PCIERCX_CFG091(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG091(p1) (p1)
#define arguments_BDK_PCIERCX_CFG091(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG091(...) "PCIERCX_CFG091"


/**
 * PCICONFIGRC - pcierc#_cfg092
 *
 * This register contains the ninety-third 32-bits of type 0 PCIe configuration space.
 *
 */
typedef union bdk_pciercx_cfg092 {
	uint32_t u;
	struct bdk_pciercx_cfg092_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t l7urph                      : 3;  /**< RO/WRSL/H - Lane 7 upstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l7utp                       : 4;  /**< RO/WRSL/H - Lane 7 upstream component transmitter preset. Writable through PEM()_CFG_WR. However,
                                                                 the application must not change this field. */
		uint32_t reserved_23_23              : 1;
		uint32_t l7drph                      : 3;  /**< RO/WRSL/H - Lane 7 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l7dtp                       : 4;  /**< RO/WRSL/H - Lane 7 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t reserved_15_15              : 1;
		uint32_t l6urph                      : 3;  /**< RO/WRSL/H - Lane 6 upstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l6utp                       : 4;  /**< RO/WRSL/H - Lane 6 upstream component transmitter preset. Writable through PEM()_CFG_WR. However,
                                                                 the application must not change this field. */
		uint32_t reserved_7_7                : 1;
		uint32_t l6drph                      : 3;  /**< RO/WRSL/H - Lane 6 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t l6dtp                       : 4;  /**< RO/WRSL/H - Lane 6 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
#else
		uint32_t l6dtp                       : 4;
		uint32_t l6drph                      : 3;
		uint32_t reserved_7_7                : 1;
		uint32_t l6utp                       : 4;
		uint32_t l6urph                      : 3;
		uint32_t reserved_15_15              : 1;
		uint32_t l7dtp                       : 4;
		uint32_t l7drph                      : 3;
		uint32_t reserved_23_23              : 1;
		uint32_t l7utp                       : 4;
		uint32_t l7urph                      : 3;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_pciercx_cfg092_s        cn88xx; */
	/* struct bdk_pciercx_cfg092_s        cn88xxp1; */
} bdk_pciercx_cfg092_t;

static inline uint64_t BDK_PCIERCX_CFG092(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG092(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000170ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG092", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG092(...) bdk_pciercx_cfg092_t
#define bustype_BDK_PCIERCX_CFG092(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG092(p1) (p1)
#define arguments_BDK_PCIERCX_CFG092(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG092(...) "PCIERCX_CFG092"


/**
 * PCICONFIGRC - pcierc#_cfg448
 *
 * This register contains the four hundred forty-ninth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg448 {
	uint32_t u;
	struct bdk_pciercx_cfg448_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t rtl                         : 16; /**< R/W/H - Replay time limit. The replay timer expires when it reaches this limit. The PCI Express
                                                                 bus initiates a replay upon reception of a nak or when the replay timer expires. This
                                                                 value is set correctly by the hardware out of reset or when the negotiated link width or
                                                                 payload size changes. If the user changes this value through a CSR write or by an EEPROM
                                                                 load then they should refer to the PCIe specification for the correct value. */
		uint32_t rtltl                       : 16; /**< R/W/H - Round trip latency time limit. The ack/nak latency timer expires when it reaches this
                                                                 limit. This value is set correctly by the hardware out of reset or when the negotiated
                                                                 link width or payload size changes. If the user changes this value through a CSR write or
                                                                 by an EEPROM load, they should refer to the PCIe specification for the correct value. */
#else
		uint32_t rtltl                       : 16;
		uint32_t rtl                         : 16;
#endif
	} s;
	/* struct bdk_pciercx_cfg448_s        cn88xx; */
	/* struct bdk_pciercx_cfg448_s        cn88xxp1; */
} bdk_pciercx_cfg448_t;

static inline uint64_t BDK_PCIERCX_CFG448(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG448(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000700ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG448", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG448(...) bdk_pciercx_cfg448_t
#define bustype_BDK_PCIERCX_CFG448(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG448(p1) (p1)
#define arguments_BDK_PCIERCX_CFG448(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG448(...) "PCIERCX_CFG448"


/**
 * PCICONFIGRC - pcierc#_cfg449
 *
 * This register contains the four hundred fiftieth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg449 {
	uint32_t u;
	struct bdk_pciercx_cfg449_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t omr                         : 32; /**< R/W - Other message register. This register can be used for either of the following purposes:
                                                                 * To send a specific PCI Express message, the application writes the payload of the
                                                                 message into this register, then sets bit 0 of the port link control register to send the
                                                                 message.
                                                                 * To store a corruption pattern for corrupting the LCRC on all TLPs, the application
                                                                 places a 32-bit corruption pattern into this register and enables this function by setting
                                                                 bit 25 of the port link control register. When enabled, the transmit LCRC result is XORed
                                                                 with this pattern before inserting it into the packet. */
#else
		uint32_t omr                         : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg449_s        cn88xx; */
	/* struct bdk_pciercx_cfg449_s        cn88xxp1; */
} bdk_pciercx_cfg449_t;

static inline uint64_t BDK_PCIERCX_CFG449(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG449(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000704ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG449", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG449(...) bdk_pciercx_cfg449_t
#define bustype_BDK_PCIERCX_CFG449(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG449(p1) (p1)
#define arguments_BDK_PCIERCX_CFG449(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG449(...) "PCIERCX_CFG449"


/**
 * PCICONFIGRC - pcierc#_cfg450
 *
 * This register contains the four hundred fifty-first 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg450 {
	uint32_t u;
	struct bdk_pciercx_cfg450_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lpec                        : 8;  /**< R/W - Low power entrance count. The power management state waits this many clock cycles for the
                                                                 associated completion of a CfgWr to PCIEEP()_CFG017 register, power state (PS) field
                                                                 register
                                                                 to go low-power. This register is intended for applications that do not let the PCI
                                                                 Express bus handle a completion for configuration request to the power management control
                                                                 and status (PCIEP()_CFG017) register. */
		uint32_t reserved_22_23              : 2;
		uint32_t link_state                  : 6;  /**< R/W - Link state. The link state that the PCI Express bus is forced to when bit 15 (force link)
                                                                 is set. State encoding:
                                                                 0x0 = DETECT_QUIET.
                                                                 0x1 = DETECT_ACT.
                                                                 0x2 = POLL_ACTIVE.
                                                                 0x3 = POLL_COMPLIANCE.
                                                                 0x4 = POLL_CONFIG.
                                                                 0x5 = PRE_DETECT_QUIET.
                                                                 0x6 = DETECT_WAIT.
                                                                 0x7 = CFG_LINKWD_START.
                                                                 0x8 = CFG_LINKWD_ACEPT.
                                                                 0x9 = CFG_LANENUM_WAIT.
                                                                 0xA = CFG_LANENUM_ACEPT.
                                                                 0xB = CFG_COMPLETE.
                                                                 0xC = CFG_IDLE.
                                                                 0xD = RCVRY_LOCK.
                                                                 0xE = RCVRY_SPEED.
                                                                 0xF = RCVRY_RCVRCFG.
                                                                 0x10 = RCVRY_IDLE.
                                                                 0x11 = L0.
                                                                 0x12 = L0S.
                                                                 0x13 = L123_SEND_EIDLE.
                                                                 0x14 = L1_IDLE.
                                                                 0x15 = L2_IDLE.
                                                                 0x16 = L2_WAKE.
                                                                 0x17 = DISABLED_ENTRY.
                                                                 0x18 = DISABLED_IDLE.
                                                                 0x19 = DISABLED.
                                                                 0x1A = LPBK_ENTRY.
                                                                 0x1B = LPBK_ACTIVE.
                                                                 0x1C = LPBK_EXIT.
                                                                 0x1D = LPBK_EXIT_TIMEOUT.
                                                                 0x1E = HOT_RESET_ENTRY.
                                                                 0x1F = HOT_RESET. */
		uint32_t force_link                  : 1;  /**< WO/H - Force link. Forces the link to the state specified by the LINK_STATE field. The force link
                                                                 pulse triggers link renegotiation.
                                                                 As the force link is a pulse, writing a 1 to it does trigger the forced link state event,
                                                                 even though reading it always returns a 0. */
		uint32_t reserved_12_14              : 3;
		uint32_t forced_ltssm                : 4;  /**< R/W - Forced link command. */
		uint32_t link_num                    : 8;  /**< R/W - Link number. */
#else
		uint32_t link_num                    : 8;
		uint32_t forced_ltssm                : 4;
		uint32_t reserved_12_14              : 3;
		uint32_t force_link                  : 1;
		uint32_t link_state                  : 6;
		uint32_t reserved_22_23              : 2;
		uint32_t lpec                        : 8;
#endif
	} s;
	/* struct bdk_pciercx_cfg450_s        cn88xx; */
	/* struct bdk_pciercx_cfg450_s        cn88xxp1; */
} bdk_pciercx_cfg450_t;

static inline uint64_t BDK_PCIERCX_CFG450(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG450(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000708ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG450", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG450(...) bdk_pciercx_cfg450_t
#define bustype_BDK_PCIERCX_CFG450(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG450(p1) (p1)
#define arguments_BDK_PCIERCX_CFG450(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG450(...) "PCIERCX_CFG450"


/**
 * PCICONFIGRC - pcierc#_cfg451
 *
 * This register contains the four hundred fifty-second 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg451 {
	uint32_t u;
	struct bdk_pciercx_cfg451_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t easpml1                     : 1;  /**< R/W/H - Enter ASPM L1 without receive in L0s. Allow core to enter ASPM L1 even when link partner
                                                                 did not go to L0s (receive is not in L0s). When not set, core goes to ASPM L1 only after
                                                                 idle period, during which both receive and transmit are in L0s. */
		uint32_t l1el                        : 3;  /**< R/W - L1 entrance latency. Values correspond to:
                                                                 0x0 = 1 ms.
                                                                 0x1 = 2 ms.
                                                                 0x2 = 4 ms.
                                                                 0x3 = 8 ms.
                                                                 0x4 = 16 ms.
                                                                 0x5 = 32 ms.
                                                                 0x6 or 0x7 = 64 ms. */
		uint32_t l0el                        : 3;  /**< R/W - L0s entrance latency. Values correspond to:
                                                                 0x0 = 1 ms.
                                                                 0x1 = 2 ms.
                                                                 0x2 = 3 ms.
                                                                 0x3 = 4 ms.
                                                                 0x4 = 5 ms.
                                                                 0x5 = 6 ms.
                                                                 0x6 or 0x7 = 7 ms. */
		uint32_t n_fts_cc                    : 8;  /**< RO - N_FTS when common clock is used.
                                                                 The number of fast training sequence (FTS) ordered sets to be transmitted when
                                                                 transitioning from L0s to L0. The maximum number of FTS ordered sets that a component can
                                                                 request is 255.
                                                                 A value of zero is not supported; a value of zero can cause the LTSSM to go into the
                                                                 recovery state when exiting from L0s. */
		uint32_t n_fts                       : 8;  /**< R/W - N_FTS. The number of fast training sequence (FTS) ordered sets to be transmitted when
                                                                 transitioning from L0s to L0. The maximum number of FTS ordered sets that a component can
                                                                 request is 255.
                                                                 A value of zero is not supported; a value of zero can cause the LTSSM to go into the
                                                                 recovery state when exiting from L0s. */
		uint32_t ack_freq                    : 8;  /**< R/W - Ack frequency. The number of pending Acks specified here (up to 255) before sending an Ack. */
#else
		uint32_t ack_freq                    : 8;
		uint32_t n_fts                       : 8;
		uint32_t n_fts_cc                    : 8;
		uint32_t l0el                        : 3;
		uint32_t l1el                        : 3;
		uint32_t easpml1                     : 1;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_pciercx_cfg451_s        cn88xx; */
	/* struct bdk_pciercx_cfg451_s        cn88xxp1; */
} bdk_pciercx_cfg451_t;

static inline uint64_t BDK_PCIERCX_CFG451(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG451(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000070Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG451", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG451(...) bdk_pciercx_cfg451_t
#define bustype_BDK_PCIERCX_CFG451(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG451(p1) (p1)
#define arguments_BDK_PCIERCX_CFG451(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG451(...) "PCIERCX_CFG451"


/**
 * PCICONFIGRC - pcierc#_cfg452
 *
 * This register contains the four hundred fifty-third 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg452 {
	uint32_t u;
	struct bdk_pciercx_cfg452_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_22_31              : 10;
		uint32_t lme                         : 6;  /**< R/W - Link mode enable set as follows:
                                                                 0x1 = x1.
                                                                 0x3 = x2.
                                                                 0x7 = x4.
                                                                 0xF = x8.
                                                                 0x1F = x16 (not supported).
                                                                 0x3F = x32 (not supported).

                                                                 This field indicates the maximum number of lanes supported by the PCIe port. The value can
                                                                 be set less than 0xF to limit the number of lanes the PCIe will attempt to use. The
                                                                 programming of this field needs to be done by software before enabling the link. See also
                                                                 PCIERC()_CFG031[MLW].
                                                                 The value of this field does not indicate the number of lanes in use by the PCIe. This
                                                                 field sets the maximum number of lanes in the PCIe core that could be used. As per the
                                                                 PCIe specification, the PCIe core can negotiate a smaller link width, so all of x8, x4,
                                                                 x2, and x1 are supported when
                                                                 LME = 0xF, for example. */
		uint32_t reserved_12_15              : 4;
		uint32_t link_rate                   : 4;  /**< RO/H - Reserved. */
		uint32_t flm                         : 1;  /**< R/W/H - Fast link mode. Sets all internal timers to fast mode for simulation purposes. */
		uint32_t reserved_6_6                : 1;
		uint32_t dllle                       : 1;  /**< R/W - DLL link enable. Enables link initialization. If DLL link enable = 0, the PCI Express bus
                                                                 does not transmit InitFC DLLPs and does not establish a link. */
		uint32_t reserved_4_4                : 1;
		uint32_t ra                          : 1;  /**< R/W - Reset assert. Triggers a recovery and forces the LTSSM to the hot reset state (downstream
                                                                 port only). */
		uint32_t le                          : 1;  /**< R/W - Loopback enable. Initiate loopback mode as a master. On a 0-\>1 transition, the PCIe core
                                                                 sends TS ordered sets with the loopback bit set to cause the link partner to enter into
                                                                 loopback mode as a slave. Normal transmission is not possible when LE=1. To exit loopback
                                                                 mode, take the link through a reset sequence. */
		uint32_t sd                          : 1;  /**< R/W - Scramble disable. Setting this bit turns off data scrambling. */
		uint32_t omr                         : 1;  /**< WO/H - Other message request. When software writes a 1 to this bit, the PCI Express bus transmits
                                                                 the message contained in the other message register. */
#else
		uint32_t omr                         : 1;
		uint32_t sd                          : 1;
		uint32_t le                          : 1;
		uint32_t ra                          : 1;
		uint32_t reserved_4_4                : 1;
		uint32_t dllle                       : 1;
		uint32_t reserved_6_6                : 1;
		uint32_t flm                         : 1;
		uint32_t link_rate                   : 4;
		uint32_t reserved_12_15              : 4;
		uint32_t lme                         : 6;
		uint32_t reserved_22_31              : 10;
#endif
	} s;
	/* struct bdk_pciercx_cfg452_s        cn88xx; */
	/* struct bdk_pciercx_cfg452_s        cn88xxp1; */
} bdk_pciercx_cfg452_t;

static inline uint64_t BDK_PCIERCX_CFG452(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG452(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000710ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG452", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG452(...) bdk_pciercx_cfg452_t
#define bustype_BDK_PCIERCX_CFG452(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG452(p1) (p1)
#define arguments_BDK_PCIERCX_CFG452(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG452(...) "PCIERCX_CFG452"


/**
 * PCICONFIGRC - pcierc#_cfg453
 *
 * This register contains the four hundred fifty-fourth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg453 {
	uint32_t u;
	struct bdk_pciercx_cfg453_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dlld                        : 1;  /**< R/W - Disable lane-to-lane deskew. Disables the internal lane-to-lane deskew logic. */
		uint32_t reserved_26_30              : 5;
		uint32_t ack_nak                     : 1;  /**< R/W - Ack/Nak disable. Prevents the PCI Express bus from sending Ack and Nak DLLPs. */
		uint32_t fcd                         : 1;  /**< R/W - Flow control disable. Prevents the PCI Express bus from sending FC DLLPs. */
		uint32_t ilst                        : 24; /**< R/W - Insert lane skew for transmit (not supported for *16). Causes skew between lanes for test
                                                                 purposes. There are three bits per lane. The value is in units of one symbol time. For
                                                                 example, the value 0x2 for a lane forces a skew of two symbol times for that lane. The
                                                                 maximum skew value for any lane is 5 symbol times. */
#else
		uint32_t ilst                        : 24;
		uint32_t fcd                         : 1;
		uint32_t ack_nak                     : 1;
		uint32_t reserved_26_30              : 5;
		uint32_t dlld                        : 1;
#endif
	} s;
	/* struct bdk_pciercx_cfg453_s        cn88xx; */
	/* struct bdk_pciercx_cfg453_s        cn88xxp1; */
} bdk_pciercx_cfg453_t;

static inline uint64_t BDK_PCIERCX_CFG453(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG453(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000714ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG453", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG453(...) bdk_pciercx_cfg453_t
#define bustype_BDK_PCIERCX_CFG453(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG453(p1) (p1)
#define arguments_BDK_PCIERCX_CFG453(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG453(...) "PCIERCX_CFG453"


/**
 * PCICONFIGRC - pcierc#_cfg454
 *
 * This register contains the four hundred fifty-fifth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg454 {
	uint32_t u;
	struct bdk_pciercx_cfg454_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_29_31              : 3;
		uint32_t tmfcwt                      : 5;  /**< R/W - Used to be 'timer modifier for flow control watchdog timer.' This field is no longer used.
                                                                 and has moved to the queue status register -- PCIEEP()_CFG463. This field remains to
                                                                 prevent software from breaking. */
		uint32_t tmanlt                      : 5;  /**< R/W - Timer modifier for Ack/Nak latency timer. Increases the timer value for the Ack/Nak
                                                                 latency timer, in increments of 64 clock cycles. */
		uint32_t tmrt                        : 5;  /**< R/W/H - Timer modifier for replay timer. Increases the timer value for the replay timer, in
                                                                 increments of 64 clock cycles. */
		uint32_t reserved_8_13               : 6;
		uint32_t mfuncn                      : 8;  /**< R/W - Max number of functions supported. */
#else
		uint32_t mfuncn                      : 8;
		uint32_t reserved_8_13               : 6;
		uint32_t tmrt                        : 5;
		uint32_t tmanlt                      : 5;
		uint32_t tmfcwt                      : 5;
		uint32_t reserved_29_31              : 3;
#endif
	} s;
	/* struct bdk_pciercx_cfg454_s        cn88xx; */
	/* struct bdk_pciercx_cfg454_s        cn88xxp1; */
} bdk_pciercx_cfg454_t;

static inline uint64_t BDK_PCIERCX_CFG454(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG454(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000718ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG454", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG454(...) bdk_pciercx_cfg454_t
#define bustype_BDK_PCIERCX_CFG454(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG454(p1) (p1)
#define arguments_BDK_PCIERCX_CFG454(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG454(...) "PCIERCX_CFG454"


/**
 * PCICONFIGRC - pcierc#_cfg455
 *
 * This register contains the four hundred fifty-sixth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg455 {
	uint32_t u;
	struct bdk_pciercx_cfg455_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t m_cfg0_filt                 : 1;  /**< R/W - Mask filtering of received configuration requests (RC mode only). */
		uint32_t m_io_filt                   : 1;  /**< R/W - Mask filtering of received I/O requests (RC mode only). */
		uint32_t msg_ctrl                    : 1;  /**< R/W - Message control. The application must not change this field. */
		uint32_t m_cpl_ecrc_filt             : 1;  /**< R/W - Mask ECRC error filtering for completions. */
		uint32_t m_ecrc_filt                 : 1;  /**< R/W - Mask ECRC error filtering. */
		uint32_t m_cpl_len_err               : 1;  /**< R/W - Mask length mismatch error for received completions. */
		uint32_t m_cpl_attr_err              : 1;  /**< R/W - Mask attributes mismatch error for received completions. */
		uint32_t m_cpl_tc_err                : 1;  /**< R/W - Mask traffic class mismatch error for received completions. */
		uint32_t m_cpl_fun_err               : 1;  /**< R/W - Mask function mismatch error for received completions. */
		uint32_t m_cpl_rid_err               : 1;  /**< R/W - Mask requester ID mismatch error for received completions. */
		uint32_t m_cpl_tag_err               : 1;  /**< R/W - Mask tag error rules for received completions. */
		uint32_t m_lk_filt                   : 1;  /**< R/W - Mask locked request filtering. */
		uint32_t m_cfg1_filt                 : 1;  /**< R/W - Mask type 1 configuration request filtering. */
		uint32_t m_bar_match                 : 1;  /**< R/W - Mask BAR match filtering. */
		uint32_t m_pois_filt                 : 1;  /**< R/W - Mask poisoned TLP filtering. */
		uint32_t m_fun                       : 1;  /**< R/W - Mask function. */
		uint32_t dfcwt                       : 1;  /**< R/W - Disable FC watchdog timer. */
		uint32_t reserved_11_14              : 4;
		uint32_t skpiv                       : 11; /**< R/W - SKP interval value. */
#else
		uint32_t skpiv                       : 11;
		uint32_t reserved_11_14              : 4;
		uint32_t dfcwt                       : 1;
		uint32_t m_fun                       : 1;
		uint32_t m_pois_filt                 : 1;
		uint32_t m_bar_match                 : 1;
		uint32_t m_cfg1_filt                 : 1;
		uint32_t m_lk_filt                   : 1;
		uint32_t m_cpl_tag_err               : 1;
		uint32_t m_cpl_rid_err               : 1;
		uint32_t m_cpl_fun_err               : 1;
		uint32_t m_cpl_tc_err                : 1;
		uint32_t m_cpl_attr_err              : 1;
		uint32_t m_cpl_len_err               : 1;
		uint32_t m_ecrc_filt                 : 1;
		uint32_t m_cpl_ecrc_filt             : 1;
		uint32_t msg_ctrl                    : 1;
		uint32_t m_io_filt                   : 1;
		uint32_t m_cfg0_filt                 : 1;
#endif
	} s;
	struct bdk_pciercx_cfg455_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t m_cfg0_filt                 : 1;  /**< R/W - Mask filtering of received configuration requests (RC mode only). */
		uint32_t m_io_filt                   : 1;  /**< R/W - Mask filtering of received I/O requests (RC mode only). */
		uint32_t msg_ctrl                    : 1;  /**< R/W - Message control. The application must not change this field. */
		uint32_t m_cpl_ecrc_filt             : 1;  /**< R/W - Mask ECRC error filtering for completions. */
		uint32_t m_ecrc_filt                 : 1;  /**< R/W - Mask ECRC error filtering. */
		uint32_t m_cpl_len_err               : 1;  /**< R/W - Mask length mismatch error for received completions. */
		uint32_t m_cpl_attr_err              : 1;  /**< R/W - Mask attributes mismatch error for received completions. */
		uint32_t m_cpl_tc_err                : 1;  /**< R/W - Mask traffic class mismatch error for received completions. */
		uint32_t m_cpl_fun_err               : 1;  /**< R/W - Mask function mismatch error for received completions. */
		uint32_t m_cpl_rid_err               : 1;  /**< R/W - Mask requester ID mismatch error for received completions. */
		uint32_t m_cpl_tag_err               : 1;  /**< R/W - Mask tag error rules for received completions. */
		uint32_t m_lk_filt                   : 1;  /**< R/W - Mask locked request filtering. */
		uint32_t m_cfg1_filt                 : 1;  /**< R/W - Mask type 1 configuration request filtering. */
		uint32_t m_bar_match                 : 1;  /**< R/W - Mask BAR match filtering. */
		uint32_t m_pois_filt                 : 1;  /**< R/W - Mask poisoned TLP filtering. */
		uint32_t m_fun                       : 1;  /**< R/W - Mask function. */
		uint32_t dfcwt                       : 1;  /**< R/W - Disable FC watchdog timer. */
		uint32_t reserved14_11               : 4;
		uint32_t skpiv                       : 11; /**< R/W - SKP interval value. */
#else
		uint32_t skpiv                       : 11;
		uint32_t reserved14_11               : 4;
		uint32_t dfcwt                       : 1;
		uint32_t m_fun                       : 1;
		uint32_t m_pois_filt                 : 1;
		uint32_t m_bar_match                 : 1;
		uint32_t m_cfg1_filt                 : 1;
		uint32_t m_lk_filt                   : 1;
		uint32_t m_cpl_tag_err               : 1;
		uint32_t m_cpl_rid_err               : 1;
		uint32_t m_cpl_fun_err               : 1;
		uint32_t m_cpl_tc_err                : 1;
		uint32_t m_cpl_attr_err              : 1;
		uint32_t m_cpl_len_err               : 1;
		uint32_t m_ecrc_filt                 : 1;
		uint32_t m_cpl_ecrc_filt             : 1;
		uint32_t msg_ctrl                    : 1;
		uint32_t m_io_filt                   : 1;
		uint32_t m_cfg0_filt                 : 1;
#endif
	} cn88xx;
	struct bdk_pciercx_cfg455_cn88xx      cn88xxp1;
} bdk_pciercx_cfg455_t;

static inline uint64_t BDK_PCIERCX_CFG455(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG455(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000071Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG455", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG455(...) bdk_pciercx_cfg455_t
#define bustype_BDK_PCIERCX_CFG455(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG455(p1) (p1)
#define arguments_BDK_PCIERCX_CFG455(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG455(...) "PCIERCX_CFG455"


/**
 * PCICONFIGRC - pcierc#_cfg456
 *
 * This register contains the four hundred fifty-seventh 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg456 {
	uint32_t u;
	struct bdk_pciercx_cfg456_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_4_31               : 28;
		uint32_t m_handle_flush              : 1;  /**< R/W - Mask core filter to handle flush request. */
		uint32_t m_dabort_4ucpl              : 1;  /**< R/W - Mask DLLP abort for unexpected CPL. */
		uint32_t m_vend1_drp                 : 1;  /**< R/W - Mask vendor MSG type 1 dropped silently. */
		uint32_t m_vend0_drp                 : 1;  /**< R/W - Mask vendor MSG type 0 dropped with UR error reporting. */
#else
		uint32_t m_vend0_drp                 : 1;
		uint32_t m_vend1_drp                 : 1;
		uint32_t m_dabort_4ucpl              : 1;
		uint32_t m_handle_flush              : 1;
		uint32_t reserved_4_31               : 28;
#endif
	} s;
	struct bdk_pciercx_cfg456_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved31_4                : 28;
		uint32_t m_handle_flush              : 1;  /**< R/W - Mask core filter to handle flush request. */
		uint32_t m_dabort_4ucpl              : 1;  /**< R/W - Mask DLLP abort for unexpected CPL. */
		uint32_t m_vend1_drp                 : 1;  /**< R/W - Mask vendor MSG type 1 dropped silently. */
		uint32_t m_vend0_drp                 : 1;  /**< R/W - Mask vendor MSG type 0 dropped with UR error reporting. */
#else
		uint32_t m_vend0_drp                 : 1;
		uint32_t m_vend1_drp                 : 1;
		uint32_t m_dabort_4ucpl              : 1;
		uint32_t m_handle_flush              : 1;
		uint32_t reserved31_4                : 28;
#endif
	} cn88xx;
	struct bdk_pciercx_cfg456_cn88xx      cn88xxp1;
} bdk_pciercx_cfg456_t;

static inline uint64_t BDK_PCIERCX_CFG456(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG456(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000720ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG456", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG456(...) bdk_pciercx_cfg456_t
#define bustype_BDK_PCIERCX_CFG456(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG456(p1) (p1)
#define arguments_BDK_PCIERCX_CFG456(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG456(...) "PCIERCX_CFG456"


/**
 * PCICONFIGRC - pcierc#_cfg458
 *
 * This register contains the four hundred fifty-ninth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg458 {
	uint32_t u;
	struct bdk_pciercx_cfg458_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dbg_info_l32                : 32; /**< RO/H - Debug info lower 32 bits. */
#else
		uint32_t dbg_info_l32                : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg458_s        cn88xx; */
	/* struct bdk_pciercx_cfg458_s        cn88xxp1; */
} bdk_pciercx_cfg458_t;

static inline uint64_t BDK_PCIERCX_CFG458(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG458(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000728ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG458", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG458(...) bdk_pciercx_cfg458_t
#define bustype_BDK_PCIERCX_CFG458(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG458(p1) (p1)
#define arguments_BDK_PCIERCX_CFG458(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG458(...) "PCIERCX_CFG458"


/**
 * PCICONFIGRC - pcierc#_cfg459
 *
 * This register contains the four hundred sixtieth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg459 {
	uint32_t u;
	struct bdk_pciercx_cfg459_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dbg_info_u32                : 32; /**< RO/H - Debug info upper 32 bits. */
#else
		uint32_t dbg_info_u32                : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg459_s        cn88xx; */
	/* struct bdk_pciercx_cfg459_s        cn88xxp1; */
} bdk_pciercx_cfg459_t;

static inline uint64_t BDK_PCIERCX_CFG459(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG459(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000072Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG459", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG459(...) bdk_pciercx_cfg459_t
#define bustype_BDK_PCIERCX_CFG459(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG459(p1) (p1)
#define arguments_BDK_PCIERCX_CFG459(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG459(...) "PCIERCX_CFG459"


/**
 * PCICONFIGRC - pcierc#_cfg460
 *
 * This register contains the four hundred sixty-first 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg460 {
	uint32_t u;
	struct bdk_pciercx_cfg460_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_20_31              : 12;
		uint32_t tphfcc                      : 8;  /**< RO/H - Transmit posted header FC Credits. The posted header credits advertised by the receiver at
                                                                 the other end of the link, updated with each UpdateFC DLLP. */
		uint32_t tpdfcc                      : 12; /**< RO/H - Transmit posted data FC credits. The posted data credits advertised by the receiver at the
                                                                 other end of the link, updated with each UpdateFC DLLP. */
#else
		uint32_t tpdfcc                      : 12;
		uint32_t tphfcc                      : 8;
		uint32_t reserved_20_31              : 12;
#endif
	} s;
	/* struct bdk_pciercx_cfg460_s        cn88xx; */
	/* struct bdk_pciercx_cfg460_s        cn88xxp1; */
} bdk_pciercx_cfg460_t;

static inline uint64_t BDK_PCIERCX_CFG460(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG460(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000730ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG460", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG460(...) bdk_pciercx_cfg460_t
#define bustype_BDK_PCIERCX_CFG460(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG460(p1) (p1)
#define arguments_BDK_PCIERCX_CFG460(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG460(...) "PCIERCX_CFG460"


/**
 * PCICONFIGRC - pcierc#_cfg461
 *
 * This register contains the four hundred sixty-second 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg461 {
	uint32_t u;
	struct bdk_pciercx_cfg461_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_20_31              : 12;
		uint32_t tchfcc                      : 8;  /**< RO/H - Transmit nonposted header FC credits. The nonposted header credits advertised by the
                                                                 receiver at the other end of the link, updated with each UpdateFC DLLP. */
		uint32_t tcdfcc                      : 12; /**< RO/H - Transmit nonposted data FC credits. The nonposted data credits advertised by the receiver
                                                                 at the other end of the link, updated with each UpdateFC DLLP. */
#else
		uint32_t tcdfcc                      : 12;
		uint32_t tchfcc                      : 8;
		uint32_t reserved_20_31              : 12;
#endif
	} s;
	/* struct bdk_pciercx_cfg461_s        cn88xx; */
	/* struct bdk_pciercx_cfg461_s        cn88xxp1; */
} bdk_pciercx_cfg461_t;

static inline uint64_t BDK_PCIERCX_CFG461(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG461(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000734ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG461", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG461(...) bdk_pciercx_cfg461_t
#define bustype_BDK_PCIERCX_CFG461(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG461(p1) (p1)
#define arguments_BDK_PCIERCX_CFG461(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG461(...) "PCIERCX_CFG461"


/**
 * PCICONFIGRC - pcierc#_cfg462
 *
 * This register contains the four hundred sixty-third 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg462 {
	uint32_t u;
	struct bdk_pciercx_cfg462_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_20_31              : 12;
		uint32_t tchfcc                      : 8;  /**< RO/H - Transmit completion header FC credits. The completion header credits advertised by the
                                                                 receiver at the other end of the link, updated with each UpdateFC DLLP. */
		uint32_t tcdfcc                      : 12; /**< RO/H - Transmit completion data FC credits. The completion data credits advertised by the
                                                                 receiver at the other end of the link, updated with each UpdateFC DLLP. */
#else
		uint32_t tcdfcc                      : 12;
		uint32_t tchfcc                      : 8;
		uint32_t reserved_20_31              : 12;
#endif
	} s;
	/* struct bdk_pciercx_cfg462_s        cn88xx; */
	/* struct bdk_pciercx_cfg462_s        cn88xxp1; */
} bdk_pciercx_cfg462_t;

static inline uint64_t BDK_PCIERCX_CFG462(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG462(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000738ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG462", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG462(...) bdk_pciercx_cfg462_t
#define bustype_BDK_PCIERCX_CFG462(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG462(p1) (p1)
#define arguments_BDK_PCIERCX_CFG462(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG462(...) "PCIERCX_CFG462"


/**
 * PCICONFIGRC - pcierc#_cfg463
 *
 * This register contains the four hundred sixty-fourth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg463 {
	uint32_t u;
	struct bdk_pciercx_cfg463_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t fcltoe                      : 1;  /**< R/W - FC latency timer override enable. When this bit is set, the value in
                                                                 PCIERC()_CFG453[FCLTOV] will override the FC latency timer value that the core
                                                                 calculates according to the PCIe specification. */
		uint32_t reserved_29_30              : 2;
		uint32_t fcltov                      : 13; /**< R/W - FC latency timer override value. When you set PCIERC()_CFG453[FCLTOE], the value in
                                                                 this field will override the FC latency timer value that the core calculates according to
                                                                 the PCIe specification. */
		uint32_t reserved_3_15               : 13;
		uint32_t rqne                        : 1;  /**< RO/H - Received queue not empty. Indicates there is data in one or more of the receive buffers. */
		uint32_t trbne                       : 1;  /**< RO/H - Transmit retry buffer not empty. Indicates that there is data in the transmit retry buffer. */
		uint32_t rtlpfccnr                   : 1;  /**< RO/H - Received TLP FC credits not returned. Indicates that the PCI Express bus has sent a TLP
                                                                 but has not yet received an UpdateFC DLLP indicating that the credits for that TLP have
                                                                 been restored by the receiver at the other end of the link. */
#else
		uint32_t rtlpfccnr                   : 1;
		uint32_t trbne                       : 1;
		uint32_t rqne                        : 1;
		uint32_t reserved_3_15               : 13;
		uint32_t fcltov                      : 13;
		uint32_t reserved_29_30              : 2;
		uint32_t fcltoe                      : 1;
#endif
	} s;
	struct bdk_pciercx_cfg463_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t fcltoe                      : 1;  /**< R/W - FC latency timer override enable. When this bit is set, the value in
                                                                 PCIERC()_CFG453[FCLTOV] will override the FC latency timer value that the core
                                                                 calculates according to the PCIe specification. */
		uint32_t reserved30_29               : 2;
		uint32_t fcltov                      : 13; /**< R/W - FC latency timer override value. When you set PCIERC()_CFG453[FCLTOE], the value in
                                                                 this field will override the FC latency timer value that the core calculates according to
                                                                 the PCIe specification. */
		uint32_t reserved15_3                : 13;
		uint32_t rqne                        : 1;  /**< RO/H - Received queue not empty. Indicates there is data in one or more of the receive buffers. */
		uint32_t trbne                       : 1;  /**< RO/H - Transmit retry buffer not empty. Indicates that there is data in the transmit retry buffer. */
		uint32_t rtlpfccnr                   : 1;  /**< RO/H - Received TLP FC credits not returned. Indicates that the PCI Express bus has sent a TLP
                                                                 but has not yet received an UpdateFC DLLP indicating that the credits for that TLP have
                                                                 been restored by the receiver at the other end of the link. */
#else
		uint32_t rtlpfccnr                   : 1;
		uint32_t trbne                       : 1;
		uint32_t rqne                        : 1;
		uint32_t reserved15_3                : 13;
		uint32_t fcltov                      : 13;
		uint32_t reserved30_29               : 2;
		uint32_t fcltoe                      : 1;
#endif
	} cn88xx;
	struct bdk_pciercx_cfg463_cn88xx      cn88xxp1;
} bdk_pciercx_cfg463_t;

static inline uint64_t BDK_PCIERCX_CFG463(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG463(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000073Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG463", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG463(...) bdk_pciercx_cfg463_t
#define bustype_BDK_PCIERCX_CFG463(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG463(p1) (p1)
#define arguments_BDK_PCIERCX_CFG463(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG463(...) "PCIERCX_CFG463"


/**
 * PCICONFIGRC - pcierc#_cfg464
 *
 * This register contains the four hundred sixty-fifth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg464 {
	uint32_t u;
	struct bdk_pciercx_cfg464_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t wrr_vc3                     : 8;  /**< RO/H - WRR Weight for VC3. */
		uint32_t wrr_vc2                     : 8;  /**< RO/H - WRR Weight for VC2. */
		uint32_t wrr_vc1                     : 8;  /**< RO/H - WRR Weight for VC1. */
		uint32_t wrr_vc0                     : 8;  /**< RO/H - WRR Weight for VC0. */
#else
		uint32_t wrr_vc0                     : 8;
		uint32_t wrr_vc1                     : 8;
		uint32_t wrr_vc2                     : 8;
		uint32_t wrr_vc3                     : 8;
#endif
	} s;
	/* struct bdk_pciercx_cfg464_s        cn88xx; */
	/* struct bdk_pciercx_cfg464_s        cn88xxp1; */
} bdk_pciercx_cfg464_t;

static inline uint64_t BDK_PCIERCX_CFG464(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG464(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000740ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG464", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG464(...) bdk_pciercx_cfg464_t
#define bustype_BDK_PCIERCX_CFG464(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG464(p1) (p1)
#define arguments_BDK_PCIERCX_CFG464(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG464(...) "PCIERCX_CFG464"


/**
 * PCICONFIGRC - pcierc#_cfg465
 *
 * This register contains the four hundred sixty-sixth 32-bits of configuration space.
 *
 */
typedef union bdk_pciercx_cfg465 {
	uint32_t u;
	struct bdk_pciercx_cfg465_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t wrr_vc7                     : 8;  /**< RO/H - WRR Weight for VC7. */
		uint32_t wrr_vc6                     : 8;  /**< RO/H - WRR Weight for VC6. */
		uint32_t wrr_vc5                     : 8;  /**< RO/H - WRR Weight for VC5. */
		uint32_t wrr_vc4                     : 8;  /**< RO/H - WRR Weight for VC4. */
#else
		uint32_t wrr_vc4                     : 8;
		uint32_t wrr_vc5                     : 8;
		uint32_t wrr_vc6                     : 8;
		uint32_t wrr_vc7                     : 8;
#endif
	} s;
	/* struct bdk_pciercx_cfg465_s        cn88xx; */
	/* struct bdk_pciercx_cfg465_s        cn88xxp1; */
} bdk_pciercx_cfg465_t;

static inline uint64_t BDK_PCIERCX_CFG465(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG465(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000744ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG465", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG465(...) bdk_pciercx_cfg465_t
#define bustype_BDK_PCIERCX_CFG465(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG465(p1) (p1)
#define arguments_BDK_PCIERCX_CFG465(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG465(...) "PCIERCX_CFG465"


/**
 * PCICONFIGRC - pcierc#_cfg466
 *
 * This register contains the four hundred sixty-seventh 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg466 {
	uint32_t u;
	struct bdk_pciercx_cfg466_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t rx_queue_order              : 1;  /**< R/W - VC ordering for receive queues. Determines the VC ordering rule for the receive queues,
                                                                 used only in the segmented-buffer configuration, writable through PEM()_CFG_WR:
                                                                 0 = Round robin.
                                                                 1 = Strict ordering, higher numbered VCs have higher priority.

                                                                 However, the application must not change this field. */
		uint32_t type_ordering               : 1;  /**< RO/WRSL - TLP type ordering for VC0. Determines the TLP type ordering rule for VC0 receive queues,
                                                                 used only in the segmented-buffer configuration, writable through
                                                                 PEM()_CFG_WR:
                                                                 0 = Strict ordering for received TLPs: Posted, then completion, then NonPosted.
                                                                 1 = Ordering of received TLPs follows the rules in PCI Express Base Specification

                                                                 The application must not change this field. */
		uint32_t reserved_24_29              : 6;
		uint32_t queue_mode                  : 3;  /**< RO/WRSL - VC0 posted TLP queue mode. The operating mode of the posted receive queue for VC0, used
                                                                 only in the segmented-buffer configuration, writable through PEM()_CFG_WR. However,
                                                                 the application must not change this field.
                                                                 Only one bit can be set at a time:

                                                                 _ Bit 23 = Bypass.

                                                                 _ Bit 22 = Cut-through.

                                                                 _ Bit 21 = Store-and-forward. */
		uint32_t reserved_20_20              : 1;
		uint32_t header_credits              : 8;  /**< RO/WRSL - VC0 posted header credits. The number of initial posted header credits for VC0, used for
                                                                 all receive queue buffer configurations. This field is writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t data_credits                : 12; /**< RO/WRSL - VC0 posted data credits. The number of initial posted data credits for VC0, used for all
                                                                 receive queue buffer configurations. This field is writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
#else
		uint32_t data_credits                : 12;
		uint32_t header_credits              : 8;
		uint32_t reserved_20_20              : 1;
		uint32_t queue_mode                  : 3;
		uint32_t reserved_24_29              : 6;
		uint32_t type_ordering               : 1;
		uint32_t rx_queue_order              : 1;
#endif
	} s;
	struct bdk_pciercx_cfg466_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t rx_queue_order              : 1;  /**< R/W - VC ordering for receive queues. Determines the VC ordering rule for the receive queues,
                                                                 used only in the segmented-buffer configuration, writable through PEM()_CFG_WR:
                                                                 0 = Round robin.
                                                                 1 = Strict ordering, higher numbered VCs have higher priority.

                                                                 However, the application must not change this field. */
		uint32_t type_ordering               : 1;  /**< RO/WRSL - TLP type ordering for VC0. Determines the TLP type ordering rule for VC0 receive queues,
                                                                 used only in the segmented-buffer configuration, writable through
                                                                 PEM()_CFG_WR:
                                                                 0 = Strict ordering for received TLPs: Posted, then completion, then NonPosted.
                                                                 1 = Ordering of received TLPs follows the rules in PCI Express Base Specification

                                                                 The application must not change this field. */
		uint32_t reserved29_24               : 6;
		uint32_t queue_mode                  : 3;  /**< RO/WRSL - VC0 posted TLP queue mode. The operating mode of the posted receive queue for VC0, used
                                                                 only in the segmented-buffer configuration, writable through PEM()_CFG_WR. However,
                                                                 the application must not change this field.
                                                                 Only one bit can be set at a time:

                                                                 _ Bit 23 = Bypass.

                                                                 _ Bit 22 = Cut-through.

                                                                 _ Bit 21 = Store-and-forward. */
		uint32_t reserved_20_20              : 1;
		uint32_t header_credits              : 8;  /**< RO/WRSL - VC0 posted header credits. The number of initial posted header credits for VC0, used for
                                                                 all receive queue buffer configurations. This field is writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
		uint32_t data_credits                : 12; /**< RO/WRSL - VC0 posted data credits. The number of initial posted data credits for VC0, used for all
                                                                 receive queue buffer configurations. This field is writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
#else
		uint32_t data_credits                : 12;
		uint32_t header_credits              : 8;
		uint32_t reserved_20_20              : 1;
		uint32_t queue_mode                  : 3;
		uint32_t reserved29_24               : 6;
		uint32_t type_ordering               : 1;
		uint32_t rx_queue_order              : 1;
#endif
	} cn88xx;
	struct bdk_pciercx_cfg466_cn88xx      cn88xxp1;
} bdk_pciercx_cfg466_t;

static inline uint64_t BDK_PCIERCX_CFG466(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG466(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000748ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG466", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG466(...) bdk_pciercx_cfg466_t
#define bustype_BDK_PCIERCX_CFG466(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG466(p1) (p1)
#define arguments_BDK_PCIERCX_CFG466(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG466(...) "PCIERCX_CFG466"


/**
 * PCICONFIGRC - pcierc#_cfg467
 *
 * This register contains the four hundred sixty-eighth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg467 {
	uint32_t u;
	struct bdk_pciercx_cfg467_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t queue_mode                  : 3;  /**< RO/WRSL - VC0 nonposted TLP queue mode. The operating mode of the nonposted receive queue for VC0,
                                                                 used only in the segmented-buffer configuration, writable through PEM()_CFG_WR.
                                                                 Only one bit can be set at a time:

                                                                 _ Bit 23 = Bypass.

                                                                 _ Bit 22 = Cut-through.

                                                                 _ Bit 21 = Store-and-forward.

                                                                 The application must not change this field. */
		uint32_t reserved_20_20              : 1;
		uint32_t header_credits              : 8;  /**< RO/WRSL - VC0 nonposted header credits. The number of initial nonposted header credits for VC0, used
                                                                 for all receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t data_credits                : 12; /**< RO/WRSL - VC0 nonposted data credits. The number of initial nonposted data credits for VC0, used for
                                                                 all receive queue buffer configurations. This field is writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
#else
		uint32_t data_credits                : 12;
		uint32_t header_credits              : 8;
		uint32_t reserved_20_20              : 1;
		uint32_t queue_mode                  : 3;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	struct bdk_pciercx_cfg467_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved31_24               : 8;
		uint32_t queue_mode                  : 3;  /**< RO/WRSL - VC0 nonposted TLP queue mode. The operating mode of the nonposted receive queue for VC0,
                                                                 used only in the segmented-buffer configuration, writable through PEM()_CFG_WR.
                                                                 Only one bit can be set at a time:

                                                                 _ Bit 23 = Bypass.

                                                                 _ Bit 22 = Cut-through.

                                                                 _ Bit 21 = Store-and-forward.

                                                                 The application must not change this field. */
		uint32_t reserved_20_20              : 1;
		uint32_t header_credits              : 8;  /**< RO/WRSL - VC0 nonposted header credits. The number of initial nonposted header credits for VC0, used
                                                                 for all receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t data_credits                : 12; /**< RO/WRSL - VC0 nonposted data credits. The number of initial nonposted data credits for VC0, used for
                                                                 all receive queue buffer configurations. This field is writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
#else
		uint32_t data_credits                : 12;
		uint32_t header_credits              : 8;
		uint32_t reserved_20_20              : 1;
		uint32_t queue_mode                  : 3;
		uint32_t reserved31_24               : 8;
#endif
	} cn88xx;
	struct bdk_pciercx_cfg467_cn88xx      cn88xxp1;
} bdk_pciercx_cfg467_t;

static inline uint64_t BDK_PCIERCX_CFG467(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG467(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000074Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG467", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG467(...) bdk_pciercx_cfg467_t
#define bustype_BDK_PCIERCX_CFG467(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG467(p1) (p1)
#define arguments_BDK_PCIERCX_CFG467(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG467(...) "PCIERCX_CFG467"


/**
 * PCICONFIGRC - pcierc#_cfg468
 *
 * This register contains the four hundred sixty-ninth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg468 {
	uint32_t u;
	struct bdk_pciercx_cfg468_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t queue_mode                  : 3;  /**< RO/WRSL - VC0 completion TLP queue mode. The operating mode of the completion receive queue for VC0,
                                                                 used only in the segmented-buffer configuration, writable through
                                                                 PEM()_CFG_WR.
                                                                 Only one bit can be set at a time:

                                                                 _ Bit 23 = Bypass.

                                                                 _ Bit 22 = Cut-through.

                                                                 _ Bit 21 = Store-and-forward.

                                                                 The application must not change this field. */
		uint32_t reserved_20_20              : 1;
		uint32_t header_credits              : 8;  /**< RO/WRSL - VC0 completion header credits. The number of initial completion header credits for VC0,
                                                                 used for all receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t data_credits                : 12; /**< RO/WRSL - VC0 completion data credits. The number of initial completion data credits for VC0, used
                                                                 for all receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
#else
		uint32_t data_credits                : 12;
		uint32_t header_credits              : 8;
		uint32_t reserved_20_20              : 1;
		uint32_t queue_mode                  : 3;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	struct bdk_pciercx_cfg468_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved31_24               : 8;
		uint32_t queue_mode                  : 3;  /**< RO/WRSL - VC0 completion TLP queue mode. The operating mode of the completion receive queue for VC0,
                                                                 used only in the segmented-buffer configuration, writable through
                                                                 PEM()_CFG_WR.
                                                                 Only one bit can be set at a time:

                                                                 _ Bit 23 = Bypass.

                                                                 _ Bit 22 = Cut-through.

                                                                 _ Bit 21 = Store-and-forward.

                                                                 The application must not change this field. */
		uint32_t reserved_20_20              : 1;
		uint32_t header_credits              : 8;  /**< RO/WRSL - VC0 completion header credits. The number of initial completion header credits for VC0,
                                                                 used for all receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
		uint32_t data_credits                : 12; /**< RO/WRSL - VC0 completion data credits. The number of initial completion data credits for VC0, used
                                                                 for all receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
#else
		uint32_t data_credits                : 12;
		uint32_t header_credits              : 8;
		uint32_t reserved_20_20              : 1;
		uint32_t queue_mode                  : 3;
		uint32_t reserved31_24               : 8;
#endif
	} cn88xx;
	struct bdk_pciercx_cfg468_cn88xx      cn88xxp1;
} bdk_pciercx_cfg468_t;

static inline uint64_t BDK_PCIERCX_CFG468(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG468(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000750ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG468", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG468(...) bdk_pciercx_cfg468_t
#define bustype_BDK_PCIERCX_CFG468(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG468(p1) (p1)
#define arguments_BDK_PCIERCX_CFG468(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG468(...) "PCIERCX_CFG468"


/**
 * PCICONFIGRC - pcierc#_cfg515
 *
 * This register contains the five hundred sixteenth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg515 {
	uint32_t u;
	struct bdk_pciercx_cfg515_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_21_31              : 11;
		uint32_t s_d_e                       : 1;  /**< R/W - SEL_DE_EMPHASIS. Used to set the deemphasis level for upstream ports. */
		uint32_t ctcrb                       : 1;  /**< R/W - Config Tx compliance receive bit. When set to 1, signals LTSSM to transmit TS ordered sets
                                                                 with the compliance receive bit assert (equal to 1). */
		uint32_t cpyts                       : 1;  /**< R/W - Config PHY Tx swing. Indicates the voltage level that the PHY should drive. When set to 1,
                                                                 indicates full swing. When set to 0, indicates low swing. */
		uint32_t dsc                         : 1;  /**< R/W/H - Directed speed change. A write of 1 initiates a speed change; always reads as zero. */
		uint32_t le                          : 9;  /**< R/W - Lane enable. Indicates the number of lanes to check for exit from electrical idle in
                                                                 Polling.Active and Polling.Compliance. 0x1 = x1, 0x2 = x2, etc. Used to limit the maximum
                                                                 link width to ignore broken lanes that detect a receiver, but will not exit electrical
                                                                 idle and would otherwise prevent a valid link from being configured. */
		uint32_t n_fts                       : 8;  /**< R/W - N_FTS. Sets the number of fast training sequences (N_FTS) that the core advertises as its
                                                                 N_FTS during GEN2 Link training. This value is used to inform the link partner about the
                                                                 PHY's ability to recover synchronization after a low power state.

                                                                 Do not set N_FTS to zero; doing so can cause the LTSSM to go into the recovery state when
                                                                 exiting from L0s. */
#else
		uint32_t n_fts                       : 8;
		uint32_t le                          : 9;
		uint32_t dsc                         : 1;
		uint32_t cpyts                       : 1;
		uint32_t ctcrb                       : 1;
		uint32_t s_d_e                       : 1;
		uint32_t reserved_21_31              : 11;
#endif
	} s;
	/* struct bdk_pciercx_cfg515_s        cn88xx; */
	/* struct bdk_pciercx_cfg515_s        cn88xxp1; */
} bdk_pciercx_cfg515_t;

static inline uint64_t BDK_PCIERCX_CFG515(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG515(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000002000000080Cull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG515", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG515(...) bdk_pciercx_cfg515_t
#define bustype_BDK_PCIERCX_CFG515(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG515(p1) (p1)
#define arguments_BDK_PCIERCX_CFG515(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG515(...) "PCIERCX_CFG515"


/**
 * PCICONFIGRC - pcierc#_cfg516
 *
 * This register contains the five hundred seventeenth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg516 {
	uint32_t u;
	struct bdk_pciercx_cfg516_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t phy_stat                    : 32; /**< RO/H - PHY status. */
#else
		uint32_t phy_stat                    : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg516_s        cn88xx; */
	/* struct bdk_pciercx_cfg516_s        cn88xxp1; */
} bdk_pciercx_cfg516_t;

static inline uint64_t BDK_PCIERCX_CFG516(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG516(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000810ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG516", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG516(...) bdk_pciercx_cfg516_t
#define bustype_BDK_PCIERCX_CFG516(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG516(p1) (p1)
#define arguments_BDK_PCIERCX_CFG516(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG516(...) "PCIERCX_CFG516"


/**
 * PCICONFIGRC - pcierc#_cfg517
 *
 * This register contains the five hundred eighteenth 32-bits of PCIe type 1 configuration space.
 *
 */
typedef union bdk_pciercx_cfg517 {
	uint32_t u;
	struct bdk_pciercx_cfg517_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t phy_ctrl                    : 32; /**< R/W - PHY control. */
#else
		uint32_t phy_ctrl                    : 32;
#endif
	} s;
	/* struct bdk_pciercx_cfg517_s        cn88xx; */
	/* struct bdk_pciercx_cfg517_s        cn88xxp1; */
} bdk_pciercx_cfg517_t;

static inline uint64_t BDK_PCIERCX_CFG517(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG517(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000814ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG517", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG517(...) bdk_pciercx_cfg517_t
#define bustype_BDK_PCIERCX_CFG517(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG517(p1) (p1)
#define arguments_BDK_PCIERCX_CFG517(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG517(...) "PCIERCX_CFG517"


/**
 * PCICONFIGRC - pcierc#_cfg548
 *
 * This register contains the five hundred forty-ninth 32-bits of type 0 PCIe configuration space.
 *
 */
typedef union bdk_pciercx_cfg548 {
	uint32_t u;
	struct bdk_pciercx_cfg548_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_19_31              : 13;
		uint32_t dcbd                        : 1;  /**< R/W - Disable balance disable. Disable DC balance feature. */
		uint32_t dtdd                        : 1;  /**< R/W - DLLP transmission delay disable. Disable delay transmission of DLLPs before equalization. */
		uint32_t ed                          : 1;  /**< R/W - Equalization disable. Disable equalization feature. */
		uint32_t reserved_12_15              : 4;
		uint32_t erd                         : 1;  /**< R/W - Equalization redo disable. Disable requesting reset of EIEOS count during equalization. */
		uint32_t ecrd                        : 1;  /**< R/W - Equalization EIEOS count reset disable. Disable requesting reset of EIEOS count during
                                                                 equalization. */
		uint32_t ep2p3d                      : 1;  /**< R/W - Equalization phase 2 and phase 3 disable. This applies to downstream ports only. */
		uint32_t dsg3                        : 1;  /**< R/W - Disable scrambler for Gen3 data rate. The Gen3 scrambler/descrambler within the core needs
                                                                 to be disabled when the scrambling function is implemented outside of the core (within the
                                                                 PHY). */
		uint32_t reserved_1_7                : 7;
		uint32_t grizdnc                     : 1;  /**< R/W - Gen3 receiver impedance ZRX-DC not compliant. */
#else
		uint32_t grizdnc                     : 1;
		uint32_t reserved_1_7                : 7;
		uint32_t dsg3                        : 1;
		uint32_t ep2p3d                      : 1;
		uint32_t ecrd                        : 1;
		uint32_t erd                         : 1;
		uint32_t reserved_12_15              : 4;
		uint32_t ed                          : 1;
		uint32_t dtdd                        : 1;
		uint32_t dcbd                        : 1;
		uint32_t reserved_19_31              : 13;
#endif
	} s;
	/* struct bdk_pciercx_cfg548_s        cn88xx; */
	/* struct bdk_pciercx_cfg548_s        cn88xxp1; */
} bdk_pciercx_cfg548_t;

static inline uint64_t BDK_PCIERCX_CFG548(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG548(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000020000000890ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG548", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG548(...) bdk_pciercx_cfg548_t
#define bustype_BDK_PCIERCX_CFG548(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG548(p1) (p1)
#define arguments_BDK_PCIERCX_CFG548(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG548(...) "PCIERCX_CFG548"


/**
 * PCICONFIGRC - pcierc#_cfg554
 *
 * This register contains the five hundred fifty-fifth 32-bits of type 0 PCIe configuration space.
 *
 */
typedef union bdk_pciercx_cfg554 {
	uint32_t u;
	struct bdk_pciercx_cfg554_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_25_31              : 7;
		uint32_t iif                         : 1;  /**< R/W - Include initial FOM. Include, or not, the FOM feedback from the initial preset evaluation
                                                                 performed in the EQ Master, when finding the highest FOM among all preset evaluations. */
		uint32_t prv                         : 16; /**< R/W - Preset request vector. Requesting of presets during the initial part of the EQ master
                                                                 phase. Encoding scheme as follows:

                                                                 Bit [15:0] = 0x0: No preset is requested and evaluated in the EQ master phase.

                                                                 Bit [i] = 1: Preset=i is requested and evaluated in the EQ master phase.

                                                                 _ 0000000000000000: No preset req/evaluated in EQ master phase

                                                                 _ 00000xxxxxxxxxx1: Preset 0 req/evaluated in EQ master phase

                                                                 _ 00000xxxxxxxxx1x: Preset 1 req/evaluated in EQ master phase

                                                                 _ 00000xxxxxxxx1xx: Preset 2 req/evaluated in EQ master phase

                                                                 _ 00000xxxxxxx1xxx: Preset 3 req/evaluated in EQ master phase

                                                                 _ 00000xxxxxx1xxxx: Preset 4 req/evaluated in EQ master phase

                                                                 _ 00000xxxxx1xxxxx: Preset 5 req/evaluated in EQ master phase

                                                                 _ 00000xxxx1xxxxxx: Preset 6 req/evaluated in EQ master phase

                                                                 _ 00000xxx1xxxxxxx: Preset 7 req/evaluated in EQ master phase

                                                                 _ 00000xx1xxxxxxxx: Preset 8 req/evaluated in EQ master phase

                                                                 _ 00000x1xxxxxxxxx: Preset 9 req/evaluated in EQ master phase

                                                                 _ 000001xxxxxxxxxx: Preset 10 req/evaluated in EQ master phase

                                                                 _ All other encodings: Reserved */
		uint32_t reserved_6_7                : 2;
		uint32_t p23td                       : 1;  /**< R/W - Phase2_3 2 ms timeout disable. Determine behavior in Phase2 for USP (Phase3 if DSP) when
                                                                 the PHY does not respond within 2 ms to the assertion of RxEqEval:
                                                                 0 = Abort the current evaluation; stop any attempt to modify the remote transmitter
                                                                 settings. Phase2 will be terminated by the 24 ms timeout.
                                                                 1 = Ignore the 2 ms timeout and continue as normal. This is used to support PHYs that
                                                                 require more than 2 ms to respond to the assertion of RxEqEval. */
		uint32_t bt                          : 1;  /**< R/W - Behavior after 24 ms timeout (when optimal settings are not found).

                                                                 For a USP: determine the next LTSSM state from Phase2:
                                                                 0 = Recovery.Speed.
                                                                 1 = Recovry.Equalization.Phase3.

                                                                 For a DSP: determine the next LTSSM state from Phase3:
                                                                 0 = Recovery.Speed.
                                                                 1 = Recovry.Equalization.RcrLock.

                                                                 When optimal settings are not found:
                                                                 * Equalization phase 3 successful status bit is not set in the Link Status Register
                                                                 * Equalization phase 3 complete status bit is set in the Link Status Register */
		uint32_t fm                          : 4;  /**< R/W - Feedback mode.
                                                                 0 = Direction of change (not supported).
                                                                 1 = Figure of merit.
                                                                 2-15 = Reserved. */
#else
		uint32_t fm                          : 4;
		uint32_t bt                          : 1;
		uint32_t p23td                       : 1;
		uint32_t reserved_6_7                : 2;
		uint32_t prv                         : 16;
		uint32_t iif                         : 1;
		uint32_t reserved_25_31              : 7;
#endif
	} s;
	/* struct bdk_pciercx_cfg554_s        cn88xx; */
	/* struct bdk_pciercx_cfg554_s        cn88xxp1; */
} bdk_pciercx_cfg554_t;

static inline uint64_t BDK_PCIERCX_CFG554(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG554(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x00000200000008A8ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG554", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG554(...) bdk_pciercx_cfg554_t
#define bustype_BDK_PCIERCX_CFG554(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG554(p1) (p1)
#define arguments_BDK_PCIERCX_CFG554(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG554(...) "PCIERCX_CFG554"


/**
 * PCICONFIGRC - pcierc#_cfg558
 *
 * This register contains the five hundred fifty-ninth 32-bits of type 0 PCIe configuration space.
 *
 */
typedef union bdk_pciercx_cfg558 {
	uint32_t u;
	struct bdk_pciercx_cfg558_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ple                         : 1;  /**< R/W - Pipe loopback enable. */
		uint32_t rxstatus                    : 31; /**< RO/H - Reserved. */
#else
		uint32_t rxstatus                    : 31;
		uint32_t ple                         : 1;
#endif
	} s;
	/* struct bdk_pciercx_cfg558_s        cn88xx; */
	/* struct bdk_pciercx_cfg558_s        cn88xxp1; */
} bdk_pciercx_cfg558_t;

static inline uint64_t BDK_PCIERCX_CFG558(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIERCX_CFG558(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x00000200000008B8ull + (param1 & 7) * 0x100000000ull;
	csr_fatal("BDK_PCIERCX_CFG558", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PCIERCX_CFG558(...) bdk_pciercx_cfg558_t
#define bustype_BDK_PCIERCX_CFG558(...) BDK_CSR_TYPE_PCICONFIGRC
#define busnum_BDK_PCIERCX_CFG558(p1) (p1)
#define arguments_BDK_PCIERCX_CFG558(p1) (p1),-1,-1,-1
#define basename_BDK_PCIERCX_CFG558(...) "PCIERCX_CFG558"

#endif /* __BDK_CSRS_PCIERC__ */
