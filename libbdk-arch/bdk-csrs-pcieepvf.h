#ifndef __BDK_CSRS_PCIEEPVF_H__
#define __BDK_CSRS_PCIEEPVF_H__
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
 * Cavium PCIEEPVF.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg000
 *
 * PCIe VF Vendor and Device Register
 * This register contains the first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg000_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t devid                 : 16; /**< [ 31: 16](RO) Device ID. For SR-IOV VFs always 0xFFFF. */
        uint32_t vendid                : 16; /**< [ 15:  0](RO) Vendor ID. For SR-IOV VFs always 0xFFFF. */
#else /* Word 0 - Little Endian */
        uint32_t vendid                : 16; /**< [ 15:  0](RO) Vendor ID. For SR-IOV VFs always 0xFFFF. */
        uint32_t devid                 : 16; /**< [ 31: 16](RO) Device ID. For SR-IOV VFs always 0xFFFF. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg000_s cn; */
} bdk_pcieepvfx_cfg000_t;

static inline uint64_t BDK_PCIEEPVFX_CFG000(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG000(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000000ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG000", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG000(a) bdk_pcieepvfx_cfg000_t
#define bustype_BDK_PCIEEPVFX_CFG000(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG000(a) "PCIEEPVFX_CFG000"
#define busnum_BDK_PCIEEPVFX_CFG000(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG000(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg001
 *
 * PCIe VF Command/Status Register
 * This register contains the second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg001_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t dpe                   : 1;  /**< [ 31: 31](R/W1C/H) Detected parity error. */
        uint32_t sse                   : 1;  /**< [ 30: 30](R/W1C/H) Signaled system error. */
        uint32_t rma                   : 1;  /**< [ 29: 29](R/W1C/H) Received master abort. */
        uint32_t rta                   : 1;  /**< [ 28: 28](R/W1C/H) Received target abort. */
        uint32_t sta                   : 1;  /**< [ 27: 27](R/W1C/H) Signaled target abort. */
        uint32_t devt                  : 2;  /**< [ 26: 25](RO) DEVSEL timing. Not applicable for PCI Express. Hardwired to 0x0. */
        uint32_t mdpe                  : 1;  /**< [ 24: 24](R/W1C/H) Master data parity error. */
        uint32_t fbb                   : 1;  /**< [ 23: 23](RO) Fast back-to-back capable. Not applicable for PCI Express. Hardwired to 0. */
        uint32_t reserved_22           : 1;
        uint32_t m66                   : 1;  /**< [ 21: 21](RO) 66 MHz capable. Not applicable for PCI Express. Hardwired to 0. */
        uint32_t cl                    : 1;  /**< [ 20: 20](RO) Capabilities list. Indicates presence of an extended capability item. Hardwired to 1. */
        uint32_t i_stat                : 1;  /**< [ 19: 19](RO/H) INTx status. */
        uint32_t reserved_11_18        : 8;
        uint32_t i_dis                 : 1;  /**< [ 10: 10](RO) INTx assertion disable. */
        uint32_t fbbe                  : 1;  /**< [  9:  9](RO) Fast back-to-back transaction enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t see                   : 1;  /**< [  8:  8](RO) SERR# enable. */
        uint32_t ids_wcc               : 1;  /**< [  7:  7](RO) IDSEL stepping/wait cycle control. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t per                   : 1;  /**< [  6:  6](RO) Parity error response. */
        uint32_t vps                   : 1;  /**< [  5:  5](RO) VGA palette snoop. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t mwice                 : 1;  /**< [  4:  4](RO) Memory write and invalidate. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t scse                  : 1;  /**< [  3:  3](RO) Special cycle enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t me                    : 1;  /**< [  2:  2](R/W) Bus master enable. */
        uint32_t msae                  : 1;  /**< [  1:  1](RO) Memory space access enable. */
        uint32_t isae                  : 1;  /**< [  0:  0](RO) I/O space access enable. */
#else /* Word 0 - Little Endian */
        uint32_t isae                  : 1;  /**< [  0:  0](RO) I/O space access enable. */
        uint32_t msae                  : 1;  /**< [  1:  1](RO) Memory space access enable. */
        uint32_t me                    : 1;  /**< [  2:  2](R/W) Bus master enable. */
        uint32_t scse                  : 1;  /**< [  3:  3](RO) Special cycle enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t mwice                 : 1;  /**< [  4:  4](RO) Memory write and invalidate. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t vps                   : 1;  /**< [  5:  5](RO) VGA palette snoop. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t per                   : 1;  /**< [  6:  6](RO) Parity error response. */
        uint32_t ids_wcc               : 1;  /**< [  7:  7](RO) IDSEL stepping/wait cycle control. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t see                   : 1;  /**< [  8:  8](RO) SERR# enable. */
        uint32_t fbbe                  : 1;  /**< [  9:  9](RO) Fast back-to-back transaction enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t i_dis                 : 1;  /**< [ 10: 10](RO) INTx assertion disable. */
        uint32_t reserved_11_18        : 8;
        uint32_t i_stat                : 1;  /**< [ 19: 19](RO/H) INTx status. */
        uint32_t cl                    : 1;  /**< [ 20: 20](RO) Capabilities list. Indicates presence of an extended capability item. Hardwired to 1. */
        uint32_t m66                   : 1;  /**< [ 21: 21](RO) 66 MHz capable. Not applicable for PCI Express. Hardwired to 0. */
        uint32_t reserved_22           : 1;
        uint32_t fbb                   : 1;  /**< [ 23: 23](RO) Fast back-to-back capable. Not applicable for PCI Express. Hardwired to 0. */
        uint32_t mdpe                  : 1;  /**< [ 24: 24](R/W1C/H) Master data parity error. */
        uint32_t devt                  : 2;  /**< [ 26: 25](RO) DEVSEL timing. Not applicable for PCI Express. Hardwired to 0x0. */
        uint32_t sta                   : 1;  /**< [ 27: 27](R/W1C/H) Signaled target abort. */
        uint32_t rta                   : 1;  /**< [ 28: 28](R/W1C/H) Received target abort. */
        uint32_t rma                   : 1;  /**< [ 29: 29](R/W1C/H) Received master abort. */
        uint32_t sse                   : 1;  /**< [ 30: 30](R/W1C/H) Signaled system error. */
        uint32_t dpe                   : 1;  /**< [ 31: 31](R/W1C/H) Detected parity error. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg001_s cn; */
} bdk_pcieepvfx_cfg001_t;

static inline uint64_t BDK_PCIEEPVFX_CFG001(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG001(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000004ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG001", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG001(a) bdk_pcieepvfx_cfg001_t
#define bustype_BDK_PCIEEPVFX_CFG001(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG001(a) "PCIEEPVFX_CFG001"
#define busnum_BDK_PCIEEPVFX_CFG001(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG001(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg002
 *
 * PCIe VF Class Code/Revision ID Register
 * This register contains the third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg002_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO) Base class code. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO) Subclass code. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO) Programming interface. */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/WRSL) Revision ID, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field.
                                                                 0x0 = pass 1.0. */
#else /* Word 0 - Little Endian */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/WRSL) Revision ID, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field.
                                                                 0x0 = pass 1.0. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO) Programming interface. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO) Subclass code. */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO) Base class code. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg002_s cn; */
} bdk_pcieepvfx_cfg002_t;

static inline uint64_t BDK_PCIEEPVFX_CFG002(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG002(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000008ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG002", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG002(a) bdk_pcieepvfx_cfg002_t
#define bustype_BDK_PCIEEPVFX_CFG002(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG002(a) "PCIEEPVFX_CFG002"
#define busnum_BDK_PCIEEPVFX_CFG002(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG002(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg003
 *
 * PCIe VF BIST, Header Type, Master Latency Timer, Cache Line Size Register
 * This register contains the fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg003_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bist                  : 8;  /**< [ 31: 24](RO) The BIST register functions are not supported. All 8 bits of the BIST register are
                                                                 hardwired to 0x0. */
        uint32_t mfd                   : 1;  /**< [ 23: 23](RO) Multi function device. */
        uint32_t chf                   : 7;  /**< [ 22: 16](RO) Configuration header format. Hardwired to 0x0 for type 0. */
        uint32_t lt                    : 8;  /**< [ 15:  8](RO) Master latency timer. Not applicable for PCI Express, hardwired to 0x0. */
        uint32_t cls                   : 8;  /**< [  7:  0](RO) Cache line size. The cache line size register is R/W for legacy compatibility purposes and
                                                                 is not applicable to PCI Express device functionality. Writing to the cache line size
                                                                 register does not impact functionality of the PCI Express bus. */
#else /* Word 0 - Little Endian */
        uint32_t cls                   : 8;  /**< [  7:  0](RO) Cache line size. The cache line size register is R/W for legacy compatibility purposes and
                                                                 is not applicable to PCI Express device functionality. Writing to the cache line size
                                                                 register does not impact functionality of the PCI Express bus. */
        uint32_t lt                    : 8;  /**< [ 15:  8](RO) Master latency timer. Not applicable for PCI Express, hardwired to 0x0. */
        uint32_t chf                   : 7;  /**< [ 22: 16](RO) Configuration header format. Hardwired to 0x0 for type 0. */
        uint32_t mfd                   : 1;  /**< [ 23: 23](RO) Multi function device. */
        uint32_t bist                  : 8;  /**< [ 31: 24](RO) The BIST register functions are not supported. All 8 bits of the BIST register are
                                                                 hardwired to 0x0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg003_s cn; */
} bdk_pcieepvfx_cfg003_t;

static inline uint64_t BDK_PCIEEPVFX_CFG003(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG003(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x5000000000cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG003", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG003(a) bdk_pcieepvfx_cfg003_t
#define bustype_BDK_PCIEEPVFX_CFG003(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG003(a) "PCIEEPVFX_CFG003"
#define busnum_BDK_PCIEEPVFX_CFG003(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG003(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg004
 *
 * PCIe VF Base Address 0 Low Register
 * This register contains the fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg004_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg004_s cn; */
} bdk_pcieepvfx_cfg004_t;

static inline uint64_t BDK_PCIEEPVFX_CFG004(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG004(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000010ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG004", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG004(a) bdk_pcieepvfx_cfg004_t
#define bustype_BDK_PCIEEPVFX_CFG004(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG004(a) "PCIEEPVFX_CFG004"
#define busnum_BDK_PCIEEPVFX_CFG004(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG004(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg005
 *
 * PCIe VF Base Address 0 High Register
 * This register contains the sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg005_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg005_s cn; */
} bdk_pcieepvfx_cfg005_t;

static inline uint64_t BDK_PCIEEPVFX_CFG005(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG005(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000014ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG005", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG005(a) bdk_pcieepvfx_cfg005_t
#define bustype_BDK_PCIEEPVFX_CFG005(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG005(a) "PCIEEPVFX_CFG005"
#define busnum_BDK_PCIEEPVFX_CFG005(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG005(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg006
 *
 * PCIe VF Base Address 1 Low Register
 * This register contains the seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg006_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg006_s cn; */
} bdk_pcieepvfx_cfg006_t;

static inline uint64_t BDK_PCIEEPVFX_CFG006(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG006(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000018ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG006", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG006(a) bdk_pcieepvfx_cfg006_t
#define bustype_BDK_PCIEEPVFX_CFG006(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG006(a) "PCIEEPVFX_CFG006"
#define busnum_BDK_PCIEEPVFX_CFG006(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG006(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg007
 *
 * PCIe VF Base Address 1 High Register
 * This register contains the eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg007_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg007_s cn; */
} bdk_pcieepvfx_cfg007_t;

static inline uint64_t BDK_PCIEEPVFX_CFG007(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG007(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x5000000001cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG007", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG007(a) bdk_pcieepvfx_cfg007_t
#define bustype_BDK_PCIEEPVFX_CFG007(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG007(a) "PCIEEPVFX_CFG007"
#define busnum_BDK_PCIEEPVFX_CFG007(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG007(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg008
 *
 * PCIe VF Base Address 2 Low Register
 * This register contains the ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg008_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg008_s cn; */
} bdk_pcieepvfx_cfg008_t;

static inline uint64_t BDK_PCIEEPVFX_CFG008(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG008(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000020ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG008", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG008(a) bdk_pcieepvfx_cfg008_t
#define bustype_BDK_PCIEEPVFX_CFG008(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG008(a) "PCIEEPVFX_CFG008"
#define busnum_BDK_PCIEEPVFX_CFG008(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG008(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg009
 *
 * PCIe VF Base Address Register 2 - High Register
 * This register contains the tenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg009_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg009_s cn; */
} bdk_pcieepvfx_cfg009_t;

static inline uint64_t BDK_PCIEEPVFX_CFG009(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG009(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000024ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG009", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG009(a) bdk_pcieepvfx_cfg009_t
#define bustype_BDK_PCIEEPVFX_CFG009(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG009(a) "PCIEEPVFX_CFG009"
#define busnum_BDK_PCIEEPVFX_CFG009(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG009(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg010
 *
 * PCIe VF Card Bus CIS Pointer Register
 * This register contains the eleventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg010_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t cisp                  : 32; /**< [ 31:  0](RO) CardBus CIS pointer. */
#else /* Word 0 - Little Endian */
        uint32_t cisp                  : 32; /**< [ 31:  0](RO) CardBus CIS pointer. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg010_s cn; */
} bdk_pcieepvfx_cfg010_t;

static inline uint64_t BDK_PCIEEPVFX_CFG010(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG010(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000028ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG010", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG010(a) bdk_pcieepvfx_cfg010_t
#define bustype_BDK_PCIEEPVFX_CFG010(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG010(a) "PCIEEPVFX_CFG010"
#define busnum_BDK_PCIEEPVFX_CFG010(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG010(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg011
 *
 * PCIe VF SubSystem ID/Subsystem Vendor ID Register
 * This register contains the twelfth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg011_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ssid                  : 16; /**< [ 31: 16](RO) Subsystem ID. Assigned by PCI-SIG. */
        uint32_t ssvid                 : 16; /**< [ 15:  0](RO) Subsystem vendor ID. Assigned by PCI-SIG. */
#else /* Word 0 - Little Endian */
        uint32_t ssvid                 : 16; /**< [ 15:  0](RO) Subsystem vendor ID. Assigned by PCI-SIG. */
        uint32_t ssid                  : 16; /**< [ 31: 16](RO) Subsystem ID. Assigned by PCI-SIG. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg011_s cn; */
} bdk_pcieepvfx_cfg011_t;

static inline uint64_t BDK_PCIEEPVFX_CFG011(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG011(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x5000000002cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG011", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG011(a) bdk_pcieepvfx_cfg011_t
#define bustype_BDK_PCIEEPVFX_CFG011(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG011(a) "PCIEEPVFX_CFG011"
#define busnum_BDK_PCIEEPVFX_CFG011(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG011(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg012
 *
 * PCIe VF Expansion ROM Base Address Register
 * This register contains the thirteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg012_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t eraddr                : 16; /**< [ 31: 16](RO) Expansion ROM address. */
        uint32_t reserved_1_15         : 15;
        uint32_t er_en                 : 1;  /**< [  0:  0](RO) Expansion ROM enable. */
#else /* Word 0 - Little Endian */
        uint32_t er_en                 : 1;  /**< [  0:  0](RO) Expansion ROM enable. */
        uint32_t reserved_1_15         : 15;
        uint32_t eraddr                : 16; /**< [ 31: 16](RO) Expansion ROM address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg012_s cn; */
} bdk_pcieepvfx_cfg012_t;

static inline uint64_t BDK_PCIEEPVFX_CFG012(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG012(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000030ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG012", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG012(a) bdk_pcieepvfx_cfg012_t
#define bustype_BDK_PCIEEPVFX_CFG012(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG012(a) "PCIEEPVFX_CFG012"
#define busnum_BDK_PCIEEPVFX_CFG012(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG012(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg013
 *
 * PCIe VF Capability Pointer Register
 * This register contains the fourteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg013_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cp                    : 8;  /**< [  7:  0](RO) First capability pointer. Points to the PCI Express Capability Pointer structure (VF's). */
#else /* Word 0 - Little Endian */
        uint32_t cp                    : 8;  /**< [  7:  0](RO) First capability pointer. Points to the PCI Express Capability Pointer structure (VF's). */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg013_s cn; */
} bdk_pcieepvfx_cfg013_t;

static inline uint64_t BDK_PCIEEPVFX_CFG013(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG013(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000034ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG013", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG013(a) bdk_pcieepvfx_cfg013_t
#define bustype_BDK_PCIEEPVFX_CFG013(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG013(a) "PCIEEPVFX_CFG013"
#define busnum_BDK_PCIEEPVFX_CFG013(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG013(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg015
 *
 * PCIe VF Interrupt Line/Interrupt Pin/Bridge Control Register
 * This register contains the sixteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg015_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ml                    : 8;  /**< [ 31: 24](RO/H) Maximum latency (hardwired to 0x0). */
        uint32_t mg                    : 8;  /**< [ 23: 16](RO/H) Minimum grant (hardwired to 0x0). */
        uint32_t inta                  : 8;  /**< [ 15:  8](RO) Interrupt pin. */
        uint32_t il                    : 8;  /**< [  7:  0](RO) Interrupt line. */
#else /* Word 0 - Little Endian */
        uint32_t il                    : 8;  /**< [  7:  0](RO) Interrupt line. */
        uint32_t inta                  : 8;  /**< [ 15:  8](RO) Interrupt pin. */
        uint32_t mg                    : 8;  /**< [ 23: 16](RO/H) Minimum grant (hardwired to 0x0). */
        uint32_t ml                    : 8;  /**< [ 31: 24](RO/H) Maximum latency (hardwired to 0x0). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg015_s cn; */
} bdk_pcieepvfx_cfg015_t;

static inline uint64_t BDK_PCIEEPVFX_CFG015(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG015(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x5000000003cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG015", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG015(a) bdk_pcieepvfx_cfg015_t
#define bustype_BDK_PCIEEPVFX_CFG015(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG015(a) "PCIEEPVFX_CFG015"
#define busnum_BDK_PCIEEPVFX_CFG015(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG015(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg028
 *
 * PCIe VF PCIe Capabilities/PCIe Capabilities List Register
 * This register contains the twenty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg028_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_30_31        : 2;
        uint32_t imn                   : 5;  /**< [ 29: 25](RO) Interrupt message number. */
        uint32_t si                    : 1;  /**< [ 24: 24](RO) Slot implemented. */
        uint32_t dpt                   : 4;  /**< [ 23: 20](RO) Device port type. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCI Express capability version. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. Points to the MSI-X capabilities by default. */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCI Express capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCI Express capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. Points to the MSI-X capabilities by default. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCI Express capability version. */
        uint32_t dpt                   : 4;  /**< [ 23: 20](RO) Device port type. */
        uint32_t si                    : 1;  /**< [ 24: 24](RO) Slot implemented. */
        uint32_t imn                   : 5;  /**< [ 29: 25](RO) Interrupt message number. */
        uint32_t reserved_30_31        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg028_s cn; */
} bdk_pcieepvfx_cfg028_t;

static inline uint64_t BDK_PCIEEPVFX_CFG028(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG028(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000070ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG028", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG028(a) bdk_pcieepvfx_cfg028_t
#define bustype_BDK_PCIEEPVFX_CFG028(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG028(a) "PCIEEPVFX_CFG028"
#define busnum_BDK_PCIEEPVFX_CFG028(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG028(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg029
 *
 * PCIe VF Device Capabilities Register
 * This register contains the thirtieth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg029_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_29_31        : 3;
        uint32_t flr_cap               : 1;  /**< [ 28: 28](RO) Function level reset capability. Set to 1 for SR-IOV core. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO) Captured slot power limit scale. From message from RC, upstream port only. */
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO) Captured slot power limit value. From message from RC, upstream port only. */
        uint32_t reserved_16_17        : 2;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO) Role-based error reporting. */
        uint32_t reserved_12_14        : 3;
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO) Endpoint L1 acceptable latency. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO) Endpoint L0s acceptable latency. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO) Extended tag field supported. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO) Phantom function supported. */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO) Max_Payload_Size supported. */
#else /* Word 0 - Little Endian */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO) Max_Payload_Size supported. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO) Phantom function supported. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO) Extended tag field supported. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO) Endpoint L0s acceptable latency. */
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO) Endpoint L1 acceptable latency. */
        uint32_t reserved_12_14        : 3;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO) Role-based error reporting. */
        uint32_t reserved_16_17        : 2;
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO) Captured slot power limit value. From message from RC, upstream port only. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO) Captured slot power limit scale. From message from RC, upstream port only. */
        uint32_t flr_cap               : 1;  /**< [ 28: 28](RO) Function level reset capability. Set to 1 for SR-IOV core. */
        uint32_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } s;
    struct bdk_pcieepvfx_cfg029_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_29_31        : 3;
        uint32_t flr_cap               : 1;  /**< [ 28: 28](RO) Function level reset capability. Set to 1 for SR-IOV core. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO) Captured slot power limit scale. From message from RC, upstream port only. */
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO) Captured slot power limit value. From message from RC, upstream port only. */
        uint32_t reserved_16_17        : 2;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO) Role-based error reporting. */
        uint32_t reserved_14           : 1;
        uint32_t reserved_13           : 1;
        uint32_t reserved_12           : 1;
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO) Endpoint L1 acceptable latency. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO) Endpoint L0s acceptable latency. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO) Extended tag field supported. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO) Phantom function supported. */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO) Max_Payload_Size supported. */
#else /* Word 0 - Little Endian */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO) Max_Payload_Size supported. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO) Phantom function supported. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO) Extended tag field supported. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO) Endpoint L0s acceptable latency. */
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO) Endpoint L1 acceptable latency. */
        uint32_t reserved_12           : 1;
        uint32_t reserved_13           : 1;
        uint32_t reserved_14           : 1;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO) Role-based error reporting. */
        uint32_t reserved_16_17        : 2;
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO) Captured slot power limit value. From message from RC, upstream port only. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO) Captured slot power limit scale. From message from RC, upstream port only. */
        uint32_t flr_cap               : 1;  /**< [ 28: 28](RO) Function level reset capability. Set to 1 for SR-IOV core. */
        uint32_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } cn;
} bdk_pcieepvfx_cfg029_t;

static inline uint64_t BDK_PCIEEPVFX_CFG029(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG029(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000074ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG029", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG029(a) bdk_pcieepvfx_cfg029_t
#define bustype_BDK_PCIEEPVFX_CFG029(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG029(a) "PCIEEPVFX_CFG029"
#define busnum_BDK_PCIEEPVFX_CFG029(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG029(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg030
 *
 * PCIe VF Device Control/Device Status Register
 * This register contains the thirty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg030_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_22_31        : 10;
        uint32_t tp                    : 1;  /**< [ 21: 21](RO/H) Transaction pending. Set to 1 when nonposted requests are not yet completed and set to 0
                                                                 when they are completed. */
        uint32_t ap_d                  : 1;  /**< [ 20: 20](RO) Aux power detected. Set to 1 if Aux power detected. */
        uint32_t ur_d                  : 1;  /**< [ 19: 19](RO/H) Unsupported request detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. UR_D occurs when we receive
                                                                 something unsupported. Unsupported requests are nonfatal errors, so UR_D should cause
                                                                 NFE_D. Receiving a vendor-defined message should cause an unsupported request. */
        uint32_t fe_d                  : 1;  /**< [ 18: 18](RO/H) Fatal error detected. All fatal errors are non-function specific and get reported only in the PF. */
        uint32_t nfe_d                 : 1;  /**< [ 17: 17](RO/H) Nonfatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in
                                                                 PCIEEP()_CFG066 that has a severity set to nonfatal and does not meet advisory
                                                                 nonfatal criteria, which most poisoned TLPs should. */
        uint32_t ce_d                  : 1;  /**< [ 16: 16](RO/H) Correctable error detected. All correctable errors are non-function specific and get
                                                                 reported only in the PF. */
        uint32_t i_flr                 : 1;  /**< [ 15: 15](WO) Initiate function level reset. */
        uint32_t mrrs                  : 3;  /**< [ 14: 12](RO) Max read request size.
                                                                 0x0 = 128 bytes.
                                                                 0x1 = 256 bytes.
                                                                 0x2 = 512 bytes.
                                                                 0x3 = 1024 bytes.
                                                                 0x4 = 2048 bytes.
                                                                 0x5 = 4096 bytes. */
        uint32_t ns_en                 : 1;  /**< [ 11: 11](RO) Enable no snoop. */
        uint32_t ap_en                 : 1;  /**< [ 10: 10](RO) AUX power PM enable. */
        uint32_t pf_en                 : 1;  /**< [  9:  9](RO) Phantom function enable. */
        uint32_t etf_en                : 1;  /**< [  8:  8](RO) Extended tag field enable. */
        uint32_t mps                   : 3;  /**< [  7:  5](RO) Max payload size. Legal values: 0x0 = 128 B, 0x1 = 256 B.
                                                                 Larger sizes are not supported by CNXXXX.
                                                                 DPI_SLI_PRT()_CFG[MPS] must be set to the same value as this field for proper
                                                                 functionality. */
        uint32_t ro_en                 : 1;  /**< [  4:  4](RO) Enable relaxed ordering. */
        uint32_t ur_en                 : 1;  /**< [  3:  3](RO) Unsupported request reporting enable. */
        uint32_t fe_en                 : 1;  /**< [  2:  2](RO) Fatal error reporting enable. */
        uint32_t nfe_en                : 1;  /**< [  1:  1](RO) Nonfatal error reporting enable. */
        uint32_t ce_en                 : 1;  /**< [  0:  0](RO) Correctable error reporting enable. */
#else /* Word 0 - Little Endian */
        uint32_t ce_en                 : 1;  /**< [  0:  0](RO) Correctable error reporting enable. */
        uint32_t nfe_en                : 1;  /**< [  1:  1](RO) Nonfatal error reporting enable. */
        uint32_t fe_en                 : 1;  /**< [  2:  2](RO) Fatal error reporting enable. */
        uint32_t ur_en                 : 1;  /**< [  3:  3](RO) Unsupported request reporting enable. */
        uint32_t ro_en                 : 1;  /**< [  4:  4](RO) Enable relaxed ordering. */
        uint32_t mps                   : 3;  /**< [  7:  5](RO) Max payload size. Legal values: 0x0 = 128 B, 0x1 = 256 B.
                                                                 Larger sizes are not supported by CNXXXX.
                                                                 DPI_SLI_PRT()_CFG[MPS] must be set to the same value as this field for proper
                                                                 functionality. */
        uint32_t etf_en                : 1;  /**< [  8:  8](RO) Extended tag field enable. */
        uint32_t pf_en                 : 1;  /**< [  9:  9](RO) Phantom function enable. */
        uint32_t ap_en                 : 1;  /**< [ 10: 10](RO) AUX power PM enable. */
        uint32_t ns_en                 : 1;  /**< [ 11: 11](RO) Enable no snoop. */
        uint32_t mrrs                  : 3;  /**< [ 14: 12](RO) Max read request size.
                                                                 0x0 = 128 bytes.
                                                                 0x1 = 256 bytes.
                                                                 0x2 = 512 bytes.
                                                                 0x3 = 1024 bytes.
                                                                 0x4 = 2048 bytes.
                                                                 0x5 = 4096 bytes. */
        uint32_t i_flr                 : 1;  /**< [ 15: 15](WO) Initiate function level reset. */
        uint32_t ce_d                  : 1;  /**< [ 16: 16](RO/H) Correctable error detected. All correctable errors are non-function specific and get
                                                                 reported only in the PF. */
        uint32_t nfe_d                 : 1;  /**< [ 17: 17](RO/H) Nonfatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in
                                                                 PCIEEP()_CFG066 that has a severity set to nonfatal and does not meet advisory
                                                                 nonfatal criteria, which most poisoned TLPs should. */
        uint32_t fe_d                  : 1;  /**< [ 18: 18](RO/H) Fatal error detected. All fatal errors are non-function specific and get reported only in the PF. */
        uint32_t ur_d                  : 1;  /**< [ 19: 19](RO/H) Unsupported request detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. UR_D occurs when we receive
                                                                 something unsupported. Unsupported requests are nonfatal errors, so UR_D should cause
                                                                 NFE_D. Receiving a vendor-defined message should cause an unsupported request. */
        uint32_t ap_d                  : 1;  /**< [ 20: 20](RO) Aux power detected. Set to 1 if Aux power detected. */
        uint32_t tp                    : 1;  /**< [ 21: 21](RO/H) Transaction pending. Set to 1 when nonposted requests are not yet completed and set to 0
                                                                 when they are completed. */
        uint32_t reserved_22_31        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg030_s cn; */
} bdk_pcieepvfx_cfg030_t;

static inline uint64_t BDK_PCIEEPVFX_CFG030(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG030(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000078ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG030", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG030(a) bdk_pcieepvfx_cfg030_t
#define bustype_BDK_PCIEEPVFX_CFG030(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG030(a) "PCIEEPVFX_CFG030"
#define busnum_BDK_PCIEEPVFX_CFG030(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG030(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg031
 *
 * PCIe VF Link Capabilities Register
 * This register contains the thirty-second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg031_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t pnum                  : 8;  /**< [ 31: 24](RO) Port number. */
        uint32_t reserved_22_23        : 2;
        uint32_t lbnc                  : 1;  /**< [ 21: 21](RO) Link bandwidth notification capability. Set to 0 for endpoint devices. */
        uint32_t dllarc                : 1;  /**< [ 20: 20](RO) Data link layer active reporting capable. */
        uint32_t sderc                 : 1;  /**< [ 19: 19](RO) Surprise down error reporting capable. Not supported; hardwired to 0. */
        uint32_t cpm                   : 1;  /**< [ 18: 18](RO) Clock power management. The default value is the value that software specifies during
                                                                 hardware configuration. */
        uint32_t l1el                  : 3;  /**< [ 17: 15](RO) L1 exit latency. The default value is the value that software specifies during hardware
                                                                 configuration. */
        uint32_t l0el                  : 3;  /**< [ 14: 12](RO) L0s exit latency. The default value is the value that software specifies during hardware
                                                                 configuration. */
        uint32_t aslpms                : 2;  /**< [ 11: 10](RO) Active state link PM support. The default value is the value that software specifies
                                                                 during hardware configuration. */
        uint32_t mlw                   : 6;  /**< [  9:  4](RO) Maximum link width.
                                                                 The reset value of this field is determined by the value read from the PEM
                                                                 csr PEM()_CFG[LANES8]. If LANES8 is set the reset value is 0x8, otherwise 0x4.

                                                                 This field is writable through PEM()_CFG_WR. */
        uint32_t mls                   : 4;  /**< [  3:  0](RO/WRSL/H) Maximum link speed. The reset value of this field is controlled by the value read from
                                                                 PEM()_CFG[MD].

                                                                 _ MD is 0x0, reset to 0x1: 2.5 GHz supported.

                                                                 _ MD is 0x1, reset to 0x2: 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x2, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x3, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported (RC Mode).

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
#else /* Word 0 - Little Endian */
        uint32_t mls                   : 4;  /**< [  3:  0](RO/WRSL/H) Maximum link speed. The reset value of this field is controlled by the value read from
                                                                 PEM()_CFG[MD].

                                                                 _ MD is 0x0, reset to 0x1: 2.5 GHz supported.

                                                                 _ MD is 0x1, reset to 0x2: 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x2, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x3, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported (RC Mode).

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t mlw                   : 6;  /**< [  9:  4](RO) Maximum link width.
                                                                 The reset value of this field is determined by the value read from the PEM
                                                                 csr PEM()_CFG[LANES8]. If LANES8 is set the reset value is 0x8, otherwise 0x4.

                                                                 This field is writable through PEM()_CFG_WR. */
        uint32_t aslpms                : 2;  /**< [ 11: 10](RO) Active state link PM support. The default value is the value that software specifies
                                                                 during hardware configuration. */
        uint32_t l0el                  : 3;  /**< [ 14: 12](RO) L0s exit latency. The default value is the value that software specifies during hardware
                                                                 configuration. */
        uint32_t l1el                  : 3;  /**< [ 17: 15](RO) L1 exit latency. The default value is the value that software specifies during hardware
                                                                 configuration. */
        uint32_t cpm                   : 1;  /**< [ 18: 18](RO) Clock power management. The default value is the value that software specifies during
                                                                 hardware configuration. */
        uint32_t sderc                 : 1;  /**< [ 19: 19](RO) Surprise down error reporting capable. Not supported; hardwired to 0. */
        uint32_t dllarc                : 1;  /**< [ 20: 20](RO) Data link layer active reporting capable. */
        uint32_t lbnc                  : 1;  /**< [ 21: 21](RO) Link bandwidth notification capability. Set to 0 for endpoint devices. */
        uint32_t reserved_22_23        : 2;
        uint32_t pnum                  : 8;  /**< [ 31: 24](RO) Port number. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg031_s cn; */
} bdk_pcieepvfx_cfg031_t;

static inline uint64_t BDK_PCIEEPVFX_CFG031(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG031(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x5000000007cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG031", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG031(a) bdk_pcieepvfx_cfg031_t
#define bustype_BDK_PCIEEPVFX_CFG031(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG031(a) "PCIEEPVFX_CFG031"
#define busnum_BDK_PCIEEPVFX_CFG031(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG031(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg032
 *
 * PCIe VF Link Control/Link Status Register
 * This register contains the thirty-third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg032_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_12_31        : 20;
        uint32_t lab_int_enb           : 1;  /**< [ 11: 11](RO) Link autonomous bandwidth interrupt enable. This bit is not applicable and is reserved for
                                                                 endpoints. */
        uint32_t lbm_int_enb           : 1;  /**< [ 10: 10](RO) Link bandwidth management interrupt enable. This bit is not applicable and is reserved for
                                                                 endpoints. */
        uint32_t hawd                  : 1;  /**< [  9:  9](RO) Hardware autonomous width disable (not supported). */
        uint32_t ecpm                  : 1;  /**< [  8:  8](RO) Enable clock power management. Hardwired to 0 if clock power management is disabled in the
                                                                 link capabilities register. */
        uint32_t es                    : 1;  /**< [  7:  7](RO) Extended synch. */
        uint32_t ccc                   : 1;  /**< [  6:  6](RO) Common clock configuration. */
        uint32_t rl                    : 1;  /**< [  5:  5](RO) Retrain link. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t ld                    : 1;  /**< [  4:  4](RO) Link disable. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t rcb                   : 1;  /**< [  3:  3](RO) Read completion boundary (RCB). */
        uint32_t reserved_2            : 1;
        uint32_t aslpc                 : 2;  /**< [  1:  0](RO) Active state link PM control. */
#else /* Word 0 - Little Endian */
        uint32_t aslpc                 : 2;  /**< [  1:  0](RO) Active state link PM control. */
        uint32_t reserved_2            : 1;
        uint32_t rcb                   : 1;  /**< [  3:  3](RO) Read completion boundary (RCB). */
        uint32_t ld                    : 1;  /**< [  4:  4](RO) Link disable. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t rl                    : 1;  /**< [  5:  5](RO) Retrain link. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t ccc                   : 1;  /**< [  6:  6](RO) Common clock configuration. */
        uint32_t es                    : 1;  /**< [  7:  7](RO) Extended synch. */
        uint32_t ecpm                  : 1;  /**< [  8:  8](RO) Enable clock power management. Hardwired to 0 if clock power management is disabled in the
                                                                 link capabilities register. */
        uint32_t hawd                  : 1;  /**< [  9:  9](RO) Hardware autonomous width disable (not supported). */
        uint32_t lbm_int_enb           : 1;  /**< [ 10: 10](RO) Link bandwidth management interrupt enable. This bit is not applicable and is reserved for
                                                                 endpoints. */
        uint32_t lab_int_enb           : 1;  /**< [ 11: 11](RO) Link autonomous bandwidth interrupt enable. This bit is not applicable and is reserved for
                                                                 endpoints. */
        uint32_t reserved_12_31        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg032_s cn; */
} bdk_pcieepvfx_cfg032_t;

static inline uint64_t BDK_PCIEEPVFX_CFG032(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG032(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000080ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG032", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG032(a) bdk_pcieepvfx_cfg032_t
#define bustype_BDK_PCIEEPVFX_CFG032(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG032(a) "PCIEEPVFX_CFG032"
#define busnum_BDK_PCIEEPVFX_CFG032(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG032(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg037
 *
 * PCIe VF Device Capabilities 2 Register
 * This register contains the thirty-eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg037_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t meetp                 : 2;  /**< [ 23: 22](RO/WRSL) Max end-end TLP prefixes.
                                                                 0x1 = 1.
                                                                 0x2 = 2.
                                                                 0x3 = 3.
                                                                 0x0 = 4. */
        uint32_t eetps                 : 1;  /**< [ 21: 21](RO) End-end TLP prefix supported (not supported). */
        uint32_t effs                  : 1;  /**< [ 20: 20](RO) Extended fmt field supported (not supported). */
        uint32_t obffs                 : 2;  /**< [ 19: 18](RO) Optimized buffer flush fill (OBFF) supported (not supported). */
        uint32_t reserved_14_17        : 4;
        uint32_t tphs                  : 2;  /**< [ 13: 12](RO) TPH completer supported (not supported). */
        uint32_t ltrs                  : 1;  /**< [ 11: 11](RO) Latency tolerance reporting (LTR) mechanism supported (not supported). */
        uint32_t noroprpr              : 1;  /**< [ 10: 10](RO/H) No RO-enabled PR-PR passing. (This bit applies to RCs.) */
        uint32_t atom128s              : 1;  /**< [  9:  9](RO) 128-bit AtomicOp supported (not supported). */
        uint32_t atom64s               : 1;  /**< [  8:  8](RO) 64-bit AtomicOp supported (not supported). */
        uint32_t atom32s               : 1;  /**< [  7:  7](RO) 32-bit AtomicOp supported (not supported). */
        uint32_t atom_ops              : 1;  /**< [  6:  6](RO) AtomicOp routing supported (not applicable for EP). */
        uint32_t ari                   : 1;  /**< [  5:  5](RO) Alternate routing ID forwarding supported (not applicable for EP). */
        uint32_t ctds                  : 1;  /**< [  4:  4](RO) Completion timeout disable supported. */
        uint32_t ctrs                  : 4;  /**< [  3:  0](RO/H) Completion timeout ranges supported. */
#else /* Word 0 - Little Endian */
        uint32_t ctrs                  : 4;  /**< [  3:  0](RO/H) Completion timeout ranges supported. */
        uint32_t ctds                  : 1;  /**< [  4:  4](RO) Completion timeout disable supported. */
        uint32_t ari                   : 1;  /**< [  5:  5](RO) Alternate routing ID forwarding supported (not applicable for EP). */
        uint32_t atom_ops              : 1;  /**< [  6:  6](RO) AtomicOp routing supported (not applicable for EP). */
        uint32_t atom32s               : 1;  /**< [  7:  7](RO) 32-bit AtomicOp supported (not supported). */
        uint32_t atom64s               : 1;  /**< [  8:  8](RO) 64-bit AtomicOp supported (not supported). */
        uint32_t atom128s              : 1;  /**< [  9:  9](RO) 128-bit AtomicOp supported (not supported). */
        uint32_t noroprpr              : 1;  /**< [ 10: 10](RO/H) No RO-enabled PR-PR passing. (This bit applies to RCs.) */
        uint32_t ltrs                  : 1;  /**< [ 11: 11](RO) Latency tolerance reporting (LTR) mechanism supported (not supported). */
        uint32_t tphs                  : 2;  /**< [ 13: 12](RO) TPH completer supported (not supported). */
        uint32_t reserved_14_17        : 4;
        uint32_t obffs                 : 2;  /**< [ 19: 18](RO) Optimized buffer flush fill (OBFF) supported (not supported). */
        uint32_t effs                  : 1;  /**< [ 20: 20](RO) Extended fmt field supported (not supported). */
        uint32_t eetps                 : 1;  /**< [ 21: 21](RO) End-end TLP prefix supported (not supported). */
        uint32_t meetp                 : 2;  /**< [ 23: 22](RO/WRSL) Max end-end TLP prefixes.
                                                                 0x1 = 1.
                                                                 0x2 = 2.
                                                                 0x3 = 3.
                                                                 0x0 = 4. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg037_s cn; */
} bdk_pcieepvfx_cfg037_t;

static inline uint64_t BDK_PCIEEPVFX_CFG037(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG037(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000094ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG037", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG037(a) bdk_pcieepvfx_cfg037_t
#define bustype_BDK_PCIEEPVFX_CFG037(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG037(a) "PCIEEPVFX_CFG037"
#define busnum_BDK_PCIEEPVFX_CFG037(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG037(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg038
 *
 * PCIe VF Device Control 2 Register/Device Status 2 Register
 * This register contains the thirty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg038_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t eetpb                 : 1;  /**< [ 15: 15](RO) Unsupported end-end TLP prefix blocking. */
        uint32_t obffe                 : 2;  /**< [ 14: 13](RO) Optimized buffer flush fill (OBFF) enable (not supported). */
        uint32_t reserved_10_12        : 3;
        uint32_t id0_cp                : 1;  /**< [  9:  9](RO) ID based ordering completion enable (not supported). */
        uint32_t id0_rq                : 1;  /**< [  8:  8](RO) ID based ordering request enable (not supported). */
        uint32_t atom_op_eb            : 1;  /**< [  7:  7](RO) AtomicOp egress blocking (not supported). */
        uint32_t atom_op               : 1;  /**< [  6:  6](RO) AtomicOp requester enable (not applicable for EP). */
        uint32_t ari                   : 1;  /**< [  5:  5](R/W) Alternate routing ID forwarding supported (not supported). */
        uint32_t ctd                   : 1;  /**< [  4:  4](RO) Completion timeout disable. */
        uint32_t ctv                   : 4;  /**< [  3:  0](RO/H) Completion timeout value. Completion timeout programming is not supported. Completion
                                                                 timeout is the range of 16 ms to 55 ms. */
#else /* Word 0 - Little Endian */
        uint32_t ctv                   : 4;  /**< [  3:  0](RO/H) Completion timeout value. Completion timeout programming is not supported. Completion
                                                                 timeout is the range of 16 ms to 55 ms. */
        uint32_t ctd                   : 1;  /**< [  4:  4](RO) Completion timeout disable. */
        uint32_t ari                   : 1;  /**< [  5:  5](R/W) Alternate routing ID forwarding supported (not supported). */
        uint32_t atom_op               : 1;  /**< [  6:  6](RO) AtomicOp requester enable (not applicable for EP). */
        uint32_t atom_op_eb            : 1;  /**< [  7:  7](RO) AtomicOp egress blocking (not supported). */
        uint32_t id0_rq                : 1;  /**< [  8:  8](RO) ID based ordering request enable (not supported). */
        uint32_t id0_cp                : 1;  /**< [  9:  9](RO) ID based ordering completion enable (not supported). */
        uint32_t reserved_10_12        : 3;
        uint32_t obffe                 : 2;  /**< [ 14: 13](RO) Optimized buffer flush fill (OBFF) enable (not supported). */
        uint32_t eetpb                 : 1;  /**< [ 15: 15](RO) Unsupported end-end TLP prefix blocking. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg038_s cn; */
} bdk_pcieepvfx_cfg038_t;

static inline uint64_t BDK_PCIEEPVFX_CFG038(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG038(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000098ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG038", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG038(a) bdk_pcieepvfx_cfg038_t
#define bustype_BDK_PCIEEPVFX_CFG038(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG038(a) "PCIEEPVFX_CFG038"
#define busnum_BDK_PCIEEPVFX_CFG038(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG038(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg039
 *
 * PCIe VF Link Capabilities 2 Register
 * This register contains the fortieth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg039_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t cls                   : 1;  /**< [  8:  8](RO) Crosslink supported. */
        uint32_t slsv                  : 7;  /**< [  7:  1](RO) Supported link speeds vector. Indicates the supported link speeds of the associated port.
                                                                 For each bit, a value of 1b indicates that the corresponding link speed is supported;
                                                                 otherwise, the link speed is not supported. Bit definitions are:

                                                                 _ Bit <1> =  2.5 GT/s.

                                                                 _ Bit <2> = 5.0 GT/s.

                                                                 _ Bit <3> = 8.0 GT/s.

                                                                 _ Bits <7:4> are reserved.

                                                                 The reset value of this field is controlled by the value read from PEM()_CFG[MD].

                                                                 _ MD is 0x0, reset to 0x1: 2.5 GHz supported.

                                                                 _ MD is 0x1, reset to 0x3: 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x2, reset to 0x7: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x3, reset to 0x7: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported (RC Mode). */
        uint32_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0            : 1;
        uint32_t slsv                  : 7;  /**< [  7:  1](RO) Supported link speeds vector. Indicates the supported link speeds of the associated port.
                                                                 For each bit, a value of 1b indicates that the corresponding link speed is supported;
                                                                 otherwise, the link speed is not supported. Bit definitions are:

                                                                 _ Bit <1> =  2.5 GT/s.

                                                                 _ Bit <2> = 5.0 GT/s.

                                                                 _ Bit <3> = 8.0 GT/s.

                                                                 _ Bits <7:4> are reserved.

                                                                 The reset value of this field is controlled by the value read from PEM()_CFG[MD].

                                                                 _ MD is 0x0, reset to 0x1: 2.5 GHz supported.

                                                                 _ MD is 0x1, reset to 0x3: 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x2, reset to 0x7: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x3, reset to 0x7: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported (RC Mode). */
        uint32_t cls                   : 1;  /**< [  8:  8](RO) Crosslink supported. */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg039_s cn; */
} bdk_pcieepvfx_cfg039_t;

static inline uint64_t BDK_PCIEEPVFX_CFG039(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG039(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x5000000009cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG039", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG039(a) bdk_pcieepvfx_cfg039_t
#define bustype_BDK_PCIEEPVFX_CFG039(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG039(a) "PCIEEPVFX_CFG039"
#define busnum_BDK_PCIEEPVFX_CFG039(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG039(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg040
 *
 * PCIe VF Link Control 2 Register/Link Status 2 Register
 * This register contains the forty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg040_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_17_31        : 15;
        uint32_t cdl                   : 1;  /**< [ 16: 16](RO/H) Current deemphasis level. When the link is operating at 5 GT/s speed, this bit reflects
                                                                 the level of deemphasis. Encodings:
                                                                 1 = -3.5 dB.
                                                                 0 = -6 dB.

                                                                 The value in this bit is undefined when the link is operating at 2.5 GT/s speed. */
        uint32_t reserved_13_15        : 3;
        uint32_t cde                   : 1;  /**< [ 12: 12](RO) Compliance deemphasis. This bit sets the deemphasis level in polling. Compliance state if
                                                                 the entry occurred due to the Tx compliance receive bit being 1. Encodings:
                                                                 1 = -3.5 dB.
                                                                 0 = -6 dB.

                                                                 When the link is operating at 2.5 GT/s, the setting of this bit has no effect. */
        uint32_t csos                  : 1;  /**< [ 11: 11](RO) Compliance SOS. When set to 1, the LTSSM is required to send SKP ordered sets periodically
                                                                 in between the (modified) compliance patterns.
                                                                 When the link is operating at 2.5 GT/s, the setting of this bit has no effect. */
        uint32_t emc                   : 1;  /**< [ 10: 10](RO) Enter modified compliance. When this bit is set to 1, the device transmits a modified
                                                                 compliance pattern if the LTSSM enters polling compliance state. */
        uint32_t tm                    : 3;  /**< [  9:  7](RO/H) Transmit margin. This field controls the value of the non-deemphasized voltage level at
                                                                 the transmitter pins:
                                                                 0x0 =  800-1200 mV for full swing 400-600 mV for half-swing.
                                                                 0x1-0x2 = Values must be monotonic with a nonzero slope.
                                                                 0x3 = 200-400 mV for full-swing and 100-200 mV for halfswing.
                                                                 0x4-0x7 = Reserved.

                                                                 This field is reset to 0x0 on entry to the LTSSM polling compliance substate. When
                                                                 operating in 5.0 GT/s mode with full swing, the deemphasis ratio must be maintained within
                                                                 +/- 1 dB from the specification-defined operational value either -3.5 or -6 dB. */
        uint32_t sde                   : 1;  /**< [  6:  6](RO) Selectable deemphasis. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t hasd                  : 1;  /**< [  5:  5](RO/H) Hardware autonomous speed disable. When asserted, the application must disable hardware
                                                                 from changing the link speed for device-specific reasons other than attempting to correct
                                                                 unreliable link operation by reducing link speed. Initial transition to the highest
                                                                 supported common link speed is not blocked by this signal. */
        uint32_t ec                    : 1;  /**< [  4:  4](RO) Enter compliance. Software is permitted to force a link to enter compliance mode at the
                                                                 speed indicated in the target link speed field by setting this bit to 1 in both components
                                                                 on a link and then initiating a hot reset on the link. */
        uint32_t tls                   : 4;  /**< [  3:  0](RO/H) Target link speed. For downstream ports, this field sets an upper limit on link
                                                                 operational speed by restricting the values advertised by the upstream component in its
                                                                 training sequences:

                                                                 0x1 = 2.5 Gb/s target link speed.
                                                                 0x2 = 5 Gb/s target link speed.
                                                                 0x4 = 8 Gb/s target link speed (not supported).

                                                                 All other encodings are reserved.

                                                                 If a value is written to this field that does not correspond to a speed included in the
                                                                 supported link speeds field, the result is undefined.
                                                                 For both upstream and downstream ports, this field is used to set the target compliance
                                                                 mode speed when software is using the enter compliance bit to force a link into compliance
                                                                 mode.
                                                                 The reset value of this field is controlled by the value read from PEM()_CFG[MD].

                                                                 _ MD is 0x0, reset to 0x1: 2.5 GHz supported.

                                                                 _ MD is 0x1, reset to 0x2: 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x2, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x3, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported (RC Mode). */
#else /* Word 0 - Little Endian */
        uint32_t tls                   : 4;  /**< [  3:  0](RO/H) Target link speed. For downstream ports, this field sets an upper limit on link
                                                                 operational speed by restricting the values advertised by the upstream component in its
                                                                 training sequences:

                                                                 0x1 = 2.5 Gb/s target link speed.
                                                                 0x2 = 5 Gb/s target link speed.
                                                                 0x4 = 8 Gb/s target link speed (not supported).

                                                                 All other encodings are reserved.

                                                                 If a value is written to this field that does not correspond to a speed included in the
                                                                 supported link speeds field, the result is undefined.
                                                                 For both upstream and downstream ports, this field is used to set the target compliance
                                                                 mode speed when software is using the enter compliance bit to force a link into compliance
                                                                 mode.
                                                                 The reset value of this field is controlled by the value read from PEM()_CFG[MD].

                                                                 _ MD is 0x0, reset to 0x1: 2.5 GHz supported.

                                                                 _ MD is 0x1, reset to 0x2: 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x2, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x3, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported (RC Mode). */
        uint32_t ec                    : 1;  /**< [  4:  4](RO) Enter compliance. Software is permitted to force a link to enter compliance mode at the
                                                                 speed indicated in the target link speed field by setting this bit to 1 in both components
                                                                 on a link and then initiating a hot reset on the link. */
        uint32_t hasd                  : 1;  /**< [  5:  5](RO/H) Hardware autonomous speed disable. When asserted, the application must disable hardware
                                                                 from changing the link speed for device-specific reasons other than attempting to correct
                                                                 unreliable link operation by reducing link speed. Initial transition to the highest
                                                                 supported common link speed is not blocked by this signal. */
        uint32_t sde                   : 1;  /**< [  6:  6](RO) Selectable deemphasis. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t tm                    : 3;  /**< [  9:  7](RO/H) Transmit margin. This field controls the value of the non-deemphasized voltage level at
                                                                 the transmitter pins:
                                                                 0x0 =  800-1200 mV for full swing 400-600 mV for half-swing.
                                                                 0x1-0x2 = Values must be monotonic with a nonzero slope.
                                                                 0x3 = 200-400 mV for full-swing and 100-200 mV for halfswing.
                                                                 0x4-0x7 = Reserved.

                                                                 This field is reset to 0x0 on entry to the LTSSM polling compliance substate. When
                                                                 operating in 5.0 GT/s mode with full swing, the deemphasis ratio must be maintained within
                                                                 +/- 1 dB from the specification-defined operational value either -3.5 or -6 dB. */
        uint32_t emc                   : 1;  /**< [ 10: 10](RO) Enter modified compliance. When this bit is set to 1, the device transmits a modified
                                                                 compliance pattern if the LTSSM enters polling compliance state. */
        uint32_t csos                  : 1;  /**< [ 11: 11](RO) Compliance SOS. When set to 1, the LTSSM is required to send SKP ordered sets periodically
                                                                 in between the (modified) compliance patterns.
                                                                 When the link is operating at 2.5 GT/s, the setting of this bit has no effect. */
        uint32_t cde                   : 1;  /**< [ 12: 12](RO) Compliance deemphasis. This bit sets the deemphasis level in polling. Compliance state if
                                                                 the entry occurred due to the Tx compliance receive bit being 1. Encodings:
                                                                 1 = -3.5 dB.
                                                                 0 = -6 dB.

                                                                 When the link is operating at 2.5 GT/s, the setting of this bit has no effect. */
        uint32_t reserved_13_15        : 3;
        uint32_t cdl                   : 1;  /**< [ 16: 16](RO/H) Current deemphasis level. When the link is operating at 5 GT/s speed, this bit reflects
                                                                 the level of deemphasis. Encodings:
                                                                 1 = -3.5 dB.
                                                                 0 = -6 dB.

                                                                 The value in this bit is undefined when the link is operating at 2.5 GT/s speed. */
        uint32_t reserved_17_31        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg040_s cn; */
} bdk_pcieepvfx_cfg040_t;

static inline uint64_t BDK_PCIEEPVFX_CFG040(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG040(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x500000000a0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG040", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG040(a) bdk_pcieepvfx_cfg040_t
#define bustype_BDK_PCIEEPVFX_CFG040(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG040(a) "PCIEEPVFX_CFG040"
#define busnum_BDK_PCIEEPVFX_CFG040(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG040(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg044
 *
 * PCIe VF PCI Express MSI-X Capability ID/MSI-X Next Item Pointer/MSI-X Control Register
 * This register contains the forty-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg044_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixen                : 1;  /**< [ 31: 31](R/W) MSI-X enable. If MSI-X is enabled, MSI and INTx must be disabled. */
        uint32_t funm                  : 1;  /**< [ 30: 30](R/W) Function mask.
                                                                 0 = Each vectors mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits. */
        uint32_t reserved_27_29        : 3;
        uint32_t msixts                : 11; /**< [ 26: 16](RO/WRSL) MSI-X table size encoded as (table size - 1).

                                                                 This field is writable by issueing a PEM()_CFG_WR to PCIEEP(0)_CFG044
                                                                 when PEM()_CFG_WR[ADDR[31]] is set. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. Points to the PCI power management capability registers. */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X Capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X Capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. Points to the PCI power management capability registers. */
        uint32_t msixts                : 11; /**< [ 26: 16](RO/WRSL) MSI-X table size encoded as (table size - 1).

                                                                 This field is writable by issueing a PEM()_CFG_WR to PCIEEP(0)_CFG044
                                                                 when PEM()_CFG_WR[ADDR[31]] is set. */
        uint32_t reserved_27_29        : 3;
        uint32_t funm                  : 1;  /**< [ 30: 30](R/W) Function mask.
                                                                 0 = Each vectors mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits. */
        uint32_t msixen                : 1;  /**< [ 31: 31](R/W) MSI-X enable. If MSI-X is enabled, MSI and INTx must be disabled. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg044_s cn; */
} bdk_pcieepvfx_cfg044_t;

static inline uint64_t BDK_PCIEEPVFX_CFG044(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG044(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x500000000b0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG044", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG044(a) bdk_pcieepvfx_cfg044_t
#define bustype_BDK_PCIEEPVFX_CFG044(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG044(a) "PCIEEPVFX_CFG044"
#define busnum_BDK_PCIEEPVFX_CFG044(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG044(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg045
 *
 * PCIe VF PCI Express MSI-X Table Offset and BIR Register
 * This register contains the forty-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg045_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixtoffs             : 29; /**< [ 31:  3](RO) MSI-X table offset register. Base address of the MSI-X Table, as an offset from the base
                                                                 address of the BAR indicated by the Table BIR bits. */
        uint32_t msixtbir              : 3;  /**< [  2:  0](RO) MSI-X table BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 table into memory space. */
#else /* Word 0 - Little Endian */
        uint32_t msixtbir              : 3;  /**< [  2:  0](RO) MSI-X table BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 table into memory space. */
        uint32_t msixtoffs             : 29; /**< [ 31:  3](RO) MSI-X table offset register. Base address of the MSI-X Table, as an offset from the base
                                                                 address of the BAR indicated by the Table BIR bits. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg045_s cn; */
} bdk_pcieepvfx_cfg045_t;

static inline uint64_t BDK_PCIEEPVFX_CFG045(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG045(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x500000000b4ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG045", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG045(a) bdk_pcieepvfx_cfg045_t
#define bustype_BDK_PCIEEPVFX_CFG045(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG045(a) "PCIEEPVFX_CFG045"
#define busnum_BDK_PCIEEPVFX_CFG045(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG045(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg046
 *
 * PCIe VF PCI Express MSI-X PBA Offset and BIR Register
 * This register contains the forty-seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg046_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixpoffs             : 29; /**< [ 31:  3](RO) MSI-X table offset register. Base address of the MSI-X PBA, as an offset from the base
                                                                 address of the BAR indicated by the table PBA bits. */
        uint32_t msixpbir              : 3;  /**< [  2:  0](RO) MSI-X PBA BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 pending bit array into memory space.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t msixpbir              : 3;  /**< [  2:  0](RO) MSI-X PBA BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 pending bit array into memory space.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t msixpoffs             : 29; /**< [ 31:  3](RO) MSI-X table offset register. Base address of the MSI-X PBA, as an offset from the base
                                                                 address of the BAR indicated by the table PBA bits. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg046_s cn; */
} bdk_pcieepvfx_cfg046_t;

static inline uint64_t BDK_PCIEEPVFX_CFG046(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG046(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x500000000b8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG046", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG046(a) bdk_pcieepvfx_cfg046_t
#define bustype_BDK_PCIEEPVFX_CFG046(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG046(a) "PCIEEPVFX_CFG046"
#define busnum_BDK_PCIEEPVFX_CFG046(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG046(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg064
 *
 * PCIe VF PCI Express ARI Extended Capability
 * This register contains the sixty-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg064_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. Points to the ARI capabilities by default. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCI Express extended capability */
#else /* Word 0 - Little Endian */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCI Express extended capability */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. Points to the ARI capabilities by default. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg064_s cn; */
} bdk_pcieepvfx_cfg064_t;

static inline uint64_t BDK_PCIEEPVFX_CFG064(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG064(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000100ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG064", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG064(a) bdk_pcieepvfx_cfg064_t
#define bustype_BDK_PCIEEPVFX_CFG064(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG064(a) "PCIEEPVFX_CFG064"
#define busnum_BDK_PCIEEPVFX_CFG064(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG064(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cfg065
 *
 * PCIe VF PCI Express ARI Capability Register/PCI Express ARI Control Register
 * This register contains the sixty-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cfg065_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t fg                    : 4;  /**< [ 23: 20](RO) Function group. */
        uint32_t reserved_18_19        : 2;
        uint32_t acsfge                : 1;  /**< [ 17: 17](RO) ACS function groups enable (A). */
        uint32_t mfvcfge               : 1;  /**< [ 16: 16](RO) MFVC function groups enable (M). */
        uint32_t reserved_2_15         : 14;
        uint32_t acsfgc                : 1;  /**< [  1:  1](RO) ACS function groups capability. */
        uint32_t mfvcfgc               : 1;  /**< [  0:  0](RO) MFVC function groups capability. */
#else /* Word 0 - Little Endian */
        uint32_t mfvcfgc               : 1;  /**< [  0:  0](RO) MFVC function groups capability. */
        uint32_t acsfgc                : 1;  /**< [  1:  1](RO) ACS function groups capability. */
        uint32_t reserved_2_15         : 14;
        uint32_t mfvcfge               : 1;  /**< [ 16: 16](RO) MFVC function groups enable (M). */
        uint32_t acsfge                : 1;  /**< [ 17: 17](RO) ACS function groups enable (A). */
        uint32_t reserved_18_19        : 2;
        uint32_t fg                    : 4;  /**< [ 23: 20](RO) Function group. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cfg065_s cn; */
} bdk_pcieepvfx_cfg065_t;

static inline uint64_t BDK_PCIEEPVFX_CFG065(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CFG065(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x50000000104ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CFG065", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CFG065(a) bdk_pcieepvfx_cfg065_t
#define bustype_BDK_PCIEEPVFX_CFG065(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CFG065(a) "PCIEEPVFX_CFG065"
#define busnum_BDK_PCIEEPVFX_CFG065(a) (a)
#define arguments_BDK_PCIEEPVFX_CFG065(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_PCIEEPVF_H__ */
