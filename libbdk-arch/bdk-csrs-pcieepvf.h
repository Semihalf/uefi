#ifndef __BDK_CSRS_PCIEEPVF_H__
#define __BDK_CSRS_PCIEEPVF_H__
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
 * Cavium PCIEEPVF.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (PCICONFIGEP) pcieepvf#_bar0l
 *
 * PCIe VF Base Address 0 Low Register
 * This register contains the fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_bar0l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_bar0l_s cn; */
} bdk_pcieepvfx_bar0l_t;

static inline uint64_t BDK_PCIEEPVFX_BAR0L(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_BAR0L(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000010ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_BAR0L", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_BAR0L(a) bdk_pcieepvfx_bar0l_t
#define bustype_BDK_PCIEEPVFX_BAR0L(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_BAR0L(a) "PCIEEPVFX_BAR0L"
#define busnum_BDK_PCIEEPVFX_BAR0L(a) (a)
#define arguments_BDK_PCIEEPVFX_BAR0L(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_bar0u
 *
 * PCIe VF Base Address 0 High Register
 * This register contains the sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_bar0u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_bar0u_s cn; */
} bdk_pcieepvfx_bar0u_t;

static inline uint64_t BDK_PCIEEPVFX_BAR0U(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_BAR0U(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000014ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_BAR0U", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_BAR0U(a) bdk_pcieepvfx_bar0u_t
#define bustype_BDK_PCIEEPVFX_BAR0U(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_BAR0U(a) "PCIEEPVFX_BAR0U"
#define busnum_BDK_PCIEEPVFX_BAR0U(a) (a)
#define arguments_BDK_PCIEEPVFX_BAR0U(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_bar2l
 *
 * PCIe VF Base Address 1 Low Register
 * This register contains the seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_bar2l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_bar2l_s cn; */
} bdk_pcieepvfx_bar2l_t;

static inline uint64_t BDK_PCIEEPVFX_BAR2L(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_BAR2L(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000018ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_BAR2L", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_BAR2L(a) bdk_pcieepvfx_bar2l_t
#define bustype_BDK_PCIEEPVFX_BAR2L(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_BAR2L(a) "PCIEEPVFX_BAR2L"
#define busnum_BDK_PCIEEPVFX_BAR2L(a) (a)
#define arguments_BDK_PCIEEPVFX_BAR2L(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_bar2u
 *
 * PCIe VF Base Address 1 High Register
 * This register contains the eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_bar2u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_bar2u_s cn; */
} bdk_pcieepvfx_bar2u_t;

static inline uint64_t BDK_PCIEEPVFX_BAR2U(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_BAR2U(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x5000000001cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_BAR2U", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_BAR2U(a) bdk_pcieepvfx_bar2u_t
#define bustype_BDK_PCIEEPVFX_BAR2U(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_BAR2U(a) "PCIEEPVFX_BAR2U"
#define busnum_BDK_PCIEEPVFX_BAR2U(a) (a)
#define arguments_BDK_PCIEEPVFX_BAR2U(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_bar4l
 *
 * PCIe VF Base Address 2 Low Register
 * This register contains the ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_bar4l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_bar4l_s cn; */
} bdk_pcieepvfx_bar4l_t;

static inline uint64_t BDK_PCIEEPVFX_BAR4L(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_BAR4L(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000020ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_BAR4L", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_BAR4L(a) bdk_pcieepvfx_bar4l_t
#define bustype_BDK_PCIEEPVFX_BAR4L(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_BAR4L(a) "PCIEEPVFX_BAR4L"
#define busnum_BDK_PCIEEPVFX_BAR4L(a) (a)
#define arguments_BDK_PCIEEPVFX_BAR4L(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_bar4u
 *
 * PCIe VF Base Address Register 2 - High Register
 * This register contains the tenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_bar4u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_bar4u_s cn; */
} bdk_pcieepvfx_bar4u_t;

static inline uint64_t BDK_PCIEEPVFX_BAR4U(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_BAR4U(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000024ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_BAR4U", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_BAR4U(a) bdk_pcieepvfx_bar4u_t
#define bustype_BDK_PCIEEPVFX_BAR4U(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_BAR4U(a) "PCIEEPVFX_BAR4U"
#define busnum_BDK_PCIEEPVFX_BAR4U(a) (a)
#define arguments_BDK_PCIEEPVFX_BAR4U(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cap_ptr
 *
 * PCIe VF Capability Pointer Register
 * This register contains the fourteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cap_ptr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cp                    : 8;  /**< [  7:  0](RO) First capability pointer. Points to the PCI Express capability pointer structure (VF's). */
#else /* Word 0 - Little Endian */
        uint32_t cp                    : 8;  /**< [  7:  0](RO) First capability pointer. Points to the PCI Express capability pointer structure (VF's). */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cap_ptr_s cn; */
} bdk_pcieepvfx_cap_ptr_t;

static inline uint64_t BDK_PCIEEPVFX_CAP_PTR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CAP_PTR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000034ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CAP_PTR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CAP_PTR(a) bdk_pcieepvfx_cap_ptr_t
#define bustype_BDK_PCIEEPVFX_CAP_PTR(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CAP_PTR(a) "PCIEEPVFX_CAP_PTR"
#define busnum_BDK_PCIEEPVFX_CAP_PTR(a) (a)
#define arguments_BDK_PCIEEPVFX_CAP_PTR(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cardbus
 *
 * PCIe VF Card Bus CIS Pointer Register
 * This register contains the eleventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cardbus_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t cisp                  : 32; /**< [ 31:  0](RO) Read-only copy of the associated PF's PCIEEP()_CARDBUS[CISP]. */
#else /* Word 0 - Little Endian */
        uint32_t cisp                  : 32; /**< [ 31:  0](RO) Read-only copy of the associated PF's PCIEEP()_CARDBUS[CISP]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_cardbus_s cn; */
} bdk_pcieepvfx_cardbus_t;

static inline uint64_t BDK_PCIEEPVFX_CARDBUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CARDBUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000028ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CARDBUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CARDBUS(a) bdk_pcieepvfx_cardbus_t
#define bustype_BDK_PCIEEPVFX_CARDBUS(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CARDBUS(a) "PCIEEPVFX_CARDBUS"
#define busnum_BDK_PCIEEPVFX_CARDBUS(a) (a)
#define arguments_BDK_PCIEEPVFX_CARDBUS(a) (a),-1,-1,-1

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
        uint32_t i_stat                : 1;  /**< [ 19: 19](RO/H) INTx status. Not applicable for SR-IOV.  Hardwired to 0. */
        uint32_t reserved_11_18        : 8;
        uint32_t i_dis                 : 1;  /**< [ 10: 10](RO) VF read-only zero. */
        uint32_t fbbe                  : 1;  /**< [  9:  9](RO) Fast back-to-back transaction enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t see                   : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t ids_wcc               : 1;  /**< [  7:  7](RO) IDSEL stepping/wait cycle control. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t per                   : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t vps                   : 1;  /**< [  5:  5](RO) VGA palette snoop. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t mwice                 : 1;  /**< [  4:  4](RO) Memory write and invalidate. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t scse                  : 1;  /**< [  3:  3](RO) Special cycle enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t me                    : 1;  /**< [  2:  2](R/W/H) Bus master enable. If the VF tries to master the bus when this bit is not set,
                                                                 the request is discarded. A interrupt will be generated setting
                                                                 PEM()_DBG_INFO[BMD_E].
                                                                 Transactions are dropped in the Client.  Non-posted transactions returns a SWI_RSP_ERROR
                                                                 to SLI/DPI/NQM soon thereafter.
                                                                 Bus master enable mimics the behavior of PEM()_FLR_PF0_VF_STOPREQ. */
        uint32_t msae                  : 1;  /**< [  1:  1](RO) VF read-only zero. */
        uint32_t isae                  : 1;  /**< [  0:  0](RO) VF read-only zero. */
#else /* Word 0 - Little Endian */
        uint32_t isae                  : 1;  /**< [  0:  0](RO) VF read-only zero. */
        uint32_t msae                  : 1;  /**< [  1:  1](RO) VF read-only zero. */
        uint32_t me                    : 1;  /**< [  2:  2](R/W/H) Bus master enable. If the VF tries to master the bus when this bit is not set,
                                                                 the request is discarded. A interrupt will be generated setting
                                                                 PEM()_DBG_INFO[BMD_E].
                                                                 Transactions are dropped in the Client.  Non-posted transactions returns a SWI_RSP_ERROR
                                                                 to SLI/DPI/NQM soon thereafter.
                                                                 Bus master enable mimics the behavior of PEM()_FLR_PF0_VF_STOPREQ. */
        uint32_t scse                  : 1;  /**< [  3:  3](RO) Special cycle enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t mwice                 : 1;  /**< [  4:  4](RO) Memory write and invalidate. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t vps                   : 1;  /**< [  5:  5](RO) VGA palette snoop. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t per                   : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t ids_wcc               : 1;  /**< [  7:  7](RO) IDSEL stepping/wait cycle control. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t see                   : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t fbbe                  : 1;  /**< [  9:  9](RO) Fast back-to-back transaction enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t i_dis                 : 1;  /**< [ 10: 10](RO) VF read-only zero. */
        uint32_t reserved_11_18        : 8;
        uint32_t i_stat                : 1;  /**< [ 19: 19](RO/H) INTx status. Not applicable for SR-IOV.  Hardwired to 0. */
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
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO) Read-only copy of the associated PF's PCIEEP()_CFG002[BCC]. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO) Read-only copy of the associated PF's PCIEEP()_CFG002[SC]. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO) Read-only copy of the associated PF's PCIEEP()_CFG002[PI]. */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/WRSL) Revision ID, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field.
                                                                 See MIO_FUS_DAT2[CHIP_ID] for more information. */
#else /* Word 0 - Little Endian */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/WRSL) Revision ID, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field.
                                                                 See MIO_FUS_DAT2[CHIP_ID] for more information. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO) Read-only copy of the associated PF's PCIEEP()_CFG002[PI]. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO) Read-only copy of the associated PF's PCIEEP()_CFG002[SC]. */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO) Read-only copy of the associated PF's PCIEEP()_CFG002[BCC]. */
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
        uint32_t mfd                   : 1;  /**< [ 23: 23](RO) Read-only copy of the associated PF's PCIEEP()_CFG003[MFD]. */
        uint32_t chf                   : 7;  /**< [ 22: 16](RO) Configuration header format. Hardwired to 0x0 for type 0. */
        uint32_t lt                    : 8;  /**< [ 15:  8](RO) Master latency timer. Not applicable for PCI Express, hardwired to 0x0. */
        uint32_t cls                   : 8;  /**< [  7:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG003[CLS].
                                                                 The cache line size register is R/W for legacy compatibility purposes and
                                                                 is not applicable to PCI Express device functionality. Writing to the cache line size
                                                                 register does not impact functionality of the PCI Express bus. */
#else /* Word 0 - Little Endian */
        uint32_t cls                   : 8;  /**< [  7:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG003[CLS].
                                                                 The cache line size register is R/W for legacy compatibility purposes and
                                                                 is not applicable to PCI Express device functionality. Writing to the cache line size
                                                                 register does not impact functionality of the PCI Express bus. */
        uint32_t lt                    : 8;  /**< [ 15:  8](RO) Master latency timer. Not applicable for PCI Express, hardwired to 0x0. */
        uint32_t chf                   : 7;  /**< [ 22: 16](RO) Configuration header format. Hardwired to 0x0 for type 0. */
        uint32_t mfd                   : 1;  /**< [ 23: 23](RO) Read-only copy of the associated PF's PCIEEP()_CFG003[MFD]. */
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
        uint32_t cisp                  : 32; /**< [ 31:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG010[CISP]. */
#else /* Word 0 - Little Endian */
        uint32_t cisp                  : 32; /**< [ 31:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG010[CISP]. */
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
        uint32_t ssid                  : 16; /**< [ 31: 16](RO) Read-only copy of the associated PF's PCIEEP()_CFG011[SSID]. */
        uint32_t ssvid                 : 16; /**< [ 15:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG011[SSVID]. */
#else /* Word 0 - Little Endian */
        uint32_t ssvid                 : 16; /**< [ 15:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG011[SSVID]. */
        uint32_t ssid                  : 16; /**< [ 31: 16](RO) Read-only copy of the associated PF's PCIEEP()_CFG011[SSID]. */
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
        uint32_t eraddr                : 13; /**< [ 31: 19](RO) Read-only copy of the associated PF's PCIEEP()_CFG012[ERADDR]. */
        uint32_t reserved_1_18         : 18;
        uint32_t er_en                 : 1;  /**< [  0:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG012[ER_EN]. */
#else /* Word 0 - Little Endian */
        uint32_t er_en                 : 1;  /**< [  0:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG012[ER_EN]. */
        uint32_t reserved_1_18         : 18;
        uint32_t eraddr                : 13; /**< [ 31: 19](RO) Read-only copy of the associated PF's PCIEEP()_CFG012[ERADDR]. */
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
        uint32_t cp                    : 8;  /**< [  7:  0](RO) First capability pointer. Points to the PCI Express capability pointer structure (VF's). */
#else /* Word 0 - Little Endian */
        uint32_t cp                    : 8;  /**< [  7:  0](RO) First capability pointer. Points to the PCI Express capability pointer structure (VF's). */
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
        uint32_t ml                    : 8;  /**< [ 31: 24](RO/H) VF's read-only zeros. */
        uint32_t mg                    : 8;  /**< [ 23: 16](RO/H) VF's read-only zeros. */
        uint32_t inta                  : 8;  /**< [ 15:  8](RO) VF's read-only zeros. */
        uint32_t il                    : 8;  /**< [  7:  0](RO) VF's read-only zeros. */
#else /* Word 0 - Little Endian */
        uint32_t il                    : 8;  /**< [  7:  0](RO) VF's read-only zeros. */
        uint32_t inta                  : 8;  /**< [ 15:  8](RO) VF's read-only zeros. */
        uint32_t mg                    : 8;  /**< [ 23: 16](RO/H) VF's read-only zeros. */
        uint32_t ml                    : 8;  /**< [ 31: 24](RO/H) VF's read-only zeros. */
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
        uint32_t imn                   : 5;  /**< [ 29: 25](RO) Read-only copy of the associated PF's PCIEEP()_CFG028[IMN]. */
        uint32_t si                    : 1;  /**< [ 24: 24](RO) Read-only copy of the associated PF's PCIEEP()_CFG028[SI]. */
        uint32_t dpt                   : 4;  /**< [ 23: 20](RO) Read-only copy of the associated PF's PCIEEP()_CFG028[DPT]. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) Read-only copy of the associated PF's PCIEEP()_CFG028[PCIECV]. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. Points to the MSI-X capabilities by default. */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCI Express capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCI Express capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. Points to the MSI-X capabilities by default. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) Read-only copy of the associated PF's PCIEEP()_CFG028[PCIECV]. */
        uint32_t dpt                   : 4;  /**< [ 23: 20](RO) Read-only copy of the associated PF's PCIEEP()_CFG028[DPT]. */
        uint32_t si                    : 1;  /**< [ 24: 24](RO) Read-only copy of the associated PF's PCIEEP()_CFG028[SI]. */
        uint32_t imn                   : 5;  /**< [ 29: 25](RO) Read-only copy of the associated PF's PCIEEP()_CFG028[IMN]. */
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
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO/H) VF undefined. */
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO/H) VF undefined. */
        uint32_t reserved_16_17        : 2;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[RBER]. */
        uint32_t reserved_12_14        : 3;
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[EL1AL]. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[EL0AL]. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[ETFS]. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[PFS]. */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[MPSS]. */
#else /* Word 0 - Little Endian */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[MPSS]. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[PFS]. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[ETFS]. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[EL0AL]. */
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[EL1AL]. */
        uint32_t reserved_12_14        : 3;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[RBER]. */
        uint32_t reserved_16_17        : 2;
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO/H) VF undefined. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO/H) VF undefined. */
        uint32_t flr_cap               : 1;  /**< [ 28: 28](RO) Function level reset capability. Set to 1 for SR-IOV core. */
        uint32_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } s;
    struct bdk_pcieepvfx_cfg029_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_29_31        : 3;
        uint32_t flr_cap               : 1;  /**< [ 28: 28](RO) Function level reset capability. Set to 1 for SR-IOV core. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO/H) VF undefined. */
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO/H) VF undefined. */
        uint32_t reserved_16_17        : 2;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[RBER]. */
        uint32_t reserved_14           : 1;
        uint32_t reserved_13           : 1;
        uint32_t reserved_12           : 1;
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[EL1AL]. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[EL0AL]. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[ETFS]. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[PFS]. */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[MPSS]. */
#else /* Word 0 - Little Endian */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[MPSS]. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[PFS]. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[ETFS]. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[EL0AL]. */
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[EL1AL]. */
        uint32_t reserved_12           : 1;
        uint32_t reserved_13           : 1;
        uint32_t reserved_14           : 1;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO) Read-only copy of the associated PF's PCIEEP()_CFG029[RBER]. */
        uint32_t reserved_16_17        : 2;
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO/H) VF undefined. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO/H) VF undefined. */
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
        uint32_t ap_d                  : 1;  /**< [ 20: 20](RO) VF's read-only zeros. */
        uint32_t ur_d                  : 1;  /**< [ 19: 19](RO/H) Unsupported request detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. [UR_D] occurs when we
                                                                 receive
                                                                 something unsupported. Unsupported requests are nonfatal errors, so [UR_D] should cause
                                                                 [NFE_D]. Receiving a vendor-defined message should cause an unsupported request. */
        uint32_t fe_d                  : 1;  /**< [ 18: 18](RO/H) Fatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in PCIEEPVF()_CFG066 that has a severity set to fatal. Malformed TLPs
                                                                 generally fit into this category. */
        uint32_t nfe_d                 : 1;  /**< [ 17: 17](RO/H) Nonfatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in PCIEEPVF()_CFG066 that has a severity set to nonfatal and does not
                                                                 meet advisory nonfatal criteria, which most poisoned TLPs should. */
        uint32_t ce_d                  : 1;  /**< [ 16: 16](RO/H) Correctable error detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. This field is set if we
                                                                 receive any of the errors in PCIEEPVF()_CFG068, for example a replay-timer timeout.
                                                                 Also, it can be set if we get any of the errors in PCIEEPVF()_CFG066 that has a severity
                                                                 set to Nonfatal and meets the Advisory Nonfatal criteria, which most ECRC errors should. */
        uint32_t i_flr                 : 1;  /**< [ 15: 15](WO) Initiate function level reset when written to one.

                                                                 [I_FLR] must not be written to one via the indirect PEM()_CFG_WR. It should only ever
                                                                 be written to one via a direct PCIe access. */
        uint32_t mrrs                  : 3;  /**< [ 14: 12](RAZ) VF RsvdP. */
        uint32_t ns_en                 : 1;  /**< [ 11: 11](RAZ) VF RsvdP. */
        uint32_t ap_en                 : 1;  /**< [ 10: 10](RAZ) VF RsvdP. */
        uint32_t pf_en                 : 1;  /**< [  9:  9](RAZ) VF RsvdP. */
        uint32_t etf_en                : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t mps                   : 3;  /**< [  7:  5](RAZ) VF RsvdP. */
        uint32_t ro_en                 : 1;  /**< [  4:  4](RAZ) VF RsvdP. */
        uint32_t ur_en                 : 1;  /**< [  3:  3](RAZ) VF RsvdP. */
        uint32_t fe_en                 : 1;  /**< [  2:  2](RAZ) VF RsvdP. */
        uint32_t nfe_en                : 1;  /**< [  1:  1](RAZ) VF RsvdP. */
        uint32_t ce_en                 : 1;  /**< [  0:  0](RAZ) VF RsvdP. */
#else /* Word 0 - Little Endian */
        uint32_t ce_en                 : 1;  /**< [  0:  0](RAZ) VF RsvdP. */
        uint32_t nfe_en                : 1;  /**< [  1:  1](RAZ) VF RsvdP. */
        uint32_t fe_en                 : 1;  /**< [  2:  2](RAZ) VF RsvdP. */
        uint32_t ur_en                 : 1;  /**< [  3:  3](RAZ) VF RsvdP. */
        uint32_t ro_en                 : 1;  /**< [  4:  4](RAZ) VF RsvdP. */
        uint32_t mps                   : 3;  /**< [  7:  5](RAZ) VF RsvdP. */
        uint32_t etf_en                : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t pf_en                 : 1;  /**< [  9:  9](RAZ) VF RsvdP. */
        uint32_t ap_en                 : 1;  /**< [ 10: 10](RAZ) VF RsvdP. */
        uint32_t ns_en                 : 1;  /**< [ 11: 11](RAZ) VF RsvdP. */
        uint32_t mrrs                  : 3;  /**< [ 14: 12](RAZ) VF RsvdP. */
        uint32_t i_flr                 : 1;  /**< [ 15: 15](WO) Initiate function level reset when written to one.

                                                                 [I_FLR] must not be written to one via the indirect PEM()_CFG_WR. It should only ever
                                                                 be written to one via a direct PCIe access. */
        uint32_t ce_d                  : 1;  /**< [ 16: 16](RO/H) Correctable error detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. This field is set if we
                                                                 receive any of the errors in PCIEEPVF()_CFG068, for example a replay-timer timeout.
                                                                 Also, it can be set if we get any of the errors in PCIEEPVF()_CFG066 that has a severity
                                                                 set to Nonfatal and meets the Advisory Nonfatal criteria, which most ECRC errors should. */
        uint32_t nfe_d                 : 1;  /**< [ 17: 17](RO/H) Nonfatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in PCIEEPVF()_CFG066 that has a severity set to nonfatal and does not
                                                                 meet advisory nonfatal criteria, which most poisoned TLPs should. */
        uint32_t fe_d                  : 1;  /**< [ 18: 18](RO/H) Fatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in PCIEEPVF()_CFG066 that has a severity set to fatal. Malformed TLPs
                                                                 generally fit into this category. */
        uint32_t ur_d                  : 1;  /**< [ 19: 19](RO/H) Unsupported request detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. [UR_D] occurs when we
                                                                 receive
                                                                 something unsupported. Unsupported requests are nonfatal errors, so [UR_D] should cause
                                                                 [NFE_D]. Receiving a vendor-defined message should cause an unsupported request. */
        uint32_t ap_d                  : 1;  /**< [ 20: 20](RO) VF's read-only zeros. */
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
        uint32_t pnum                  : 8;  /**< [ 31: 24](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[PNUM]. */
        uint32_t reserved_22_23        : 2;
        uint32_t lbnc                  : 1;  /**< [ 21: 21](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[LBNC]. */
        uint32_t dllarc                : 1;  /**< [ 20: 20](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[DLLARC]. */
        uint32_t sderc                 : 1;  /**< [ 19: 19](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[SDERC]. */
        uint32_t cpm                   : 1;  /**< [ 18: 18](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[CPM]. */
        uint32_t l1el                  : 3;  /**< [ 17: 15](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[L1EL]. */
        uint32_t l0el                  : 3;  /**< [ 14: 12](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[L0EL]. */
        uint32_t aslpms                : 2;  /**< [ 11: 10](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[ASLPMS]. */
        uint32_t mlw                   : 6;  /**< [  9:  4](RO/H) Read-only copy of the associated PF's PCIEEP()_CFG031[MLW]. */
        uint32_t mls                   : 4;  /**< [  3:  0](RO/H) Read-only copy of the associated PF's PCIEEP()_CFG031[MLS]. */
#else /* Word 0 - Little Endian */
        uint32_t mls                   : 4;  /**< [  3:  0](RO/H) Read-only copy of the associated PF's PCIEEP()_CFG031[MLS]. */
        uint32_t mlw                   : 6;  /**< [  9:  4](RO/H) Read-only copy of the associated PF's PCIEEP()_CFG031[MLW]. */
        uint32_t aslpms                : 2;  /**< [ 11: 10](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[ASLPMS]. */
        uint32_t l0el                  : 3;  /**< [ 14: 12](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[L0EL]. */
        uint32_t l1el                  : 3;  /**< [ 17: 15](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[L1EL]. */
        uint32_t cpm                   : 1;  /**< [ 18: 18](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[CPM]. */
        uint32_t sderc                 : 1;  /**< [ 19: 19](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[SDERC]. */
        uint32_t dllarc                : 1;  /**< [ 20: 20](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[DLLARC]. */
        uint32_t lbnc                  : 1;  /**< [ 21: 21](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[LBNC]. */
        uint32_t reserved_22_23        : 2;
        uint32_t pnum                  : 8;  /**< [ 31: 24](RO) Read-only copy of the associated PF's PCIEEP()_CFG031[PNUM]. */
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
        uint32_t hawd                  : 1;  /**< [  9:  9](RAZ) VF RsvdP. */
        uint32_t ecpm                  : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t es                    : 1;  /**< [  7:  7](RAZ) VF RsvdP. */
        uint32_t ccc                   : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t rl                    : 1;  /**< [  5:  5](RO) Retrain link. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t ld                    : 1;  /**< [  4:  4](RO) Link disable. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t rcb                   : 1;  /**< [  3:  3](RAZ) VF RsvdP. */
        uint32_t reserved_2            : 1;
        uint32_t aslpc                 : 2;  /**< [  1:  0](RAZ) VF RsvdP. */
#else /* Word 0 - Little Endian */
        uint32_t aslpc                 : 2;  /**< [  1:  0](RAZ) VF RsvdP. */
        uint32_t reserved_2            : 1;
        uint32_t rcb                   : 1;  /**< [  3:  3](RAZ) VF RsvdP. */
        uint32_t ld                    : 1;  /**< [  4:  4](RO) Link disable. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t rl                    : 1;  /**< [  5:  5](RO) Retrain link. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t ccc                   : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t es                    : 1;  /**< [  7:  7](RAZ) VF RsvdP. */
        uint32_t ecpm                  : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t hawd                  : 1;  /**< [  9:  9](RAZ) VF RsvdP. */
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
        uint32_t meetp                 : 2;  /**< [ 23: 22](RO) Read-only copy of the associated PF's PCIEEP()_CFG037[MEETP]. */
        uint32_t eetps                 : 1;  /**< [ 21: 21](RO) End-end TLP prefix supported (not supported). */
        uint32_t effs                  : 1;  /**< [ 20: 20](RO) Extended fmt field supported (not supported). */
        uint32_t obffs                 : 2;  /**< [ 19: 18](RO) Optimized buffer flush fill (OBFF) supported (not supported). */
        uint32_t reserved_14_17        : 4;
        uint32_t tphs                  : 2;  /**< [ 13: 12](RO) TPH completer supported (not supported). */
        uint32_t ltrs                  : 1;  /**< [ 11: 11](RO) Latency tolerance reporting (LTR) mechanism supported (not supported). */
        uint32_t noroprpr              : 1;  /**< [ 10: 10](RO/H) No RO-enabled PR-PR passing. (This bit applies to RCs.) */
        uint32_t atom128s              : 1;  /**< [  9:  9](RO/H) 128-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request.
                                                                 Since VF's are tied to BAR0, all AtomicOp's will be dropped as unsupported requests.
                                                                 ATOM128S is set as an inherited attribute from the PF. */
        uint32_t atom64s               : 1;  /**< [  8:  8](RO) 64-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request.
                                                                 Since VF's are tied to BAR0, all AtomicOp's will be dropped as unsupported requests.
                                                                 ATOM64S is set as an inherited attribute from the PF. */
        uint32_t atom32s               : 1;  /**< [  7:  7](RO/H) 32-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request.
                                                                 Since VF's are tied to BAR0, all AtomicOp's will be dropped as unsupported requests.
                                                                 ATOM64S is set as an inherited attribute from the PF. */
        uint32_t atom_ops              : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t ari                   : 1;  /**< [  5:  5](RO) Alternate routing ID forwarding supported (not applicable for EP). */
        uint32_t ctds                  : 1;  /**< [  4:  4](RO) Completion timeout disable supported. */
        uint32_t ctrs                  : 4;  /**< [  3:  0](RO) Completion timeout ranges supported. */
#else /* Word 0 - Little Endian */
        uint32_t ctrs                  : 4;  /**< [  3:  0](RO) Completion timeout ranges supported. */
        uint32_t ctds                  : 1;  /**< [  4:  4](RO) Completion timeout disable supported. */
        uint32_t ari                   : 1;  /**< [  5:  5](RO) Alternate routing ID forwarding supported (not applicable for EP). */
        uint32_t atom_ops              : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t atom32s               : 1;  /**< [  7:  7](RO/H) 32-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request.
                                                                 Since VF's are tied to BAR0, all AtomicOp's will be dropped as unsupported requests.
                                                                 ATOM64S is set as an inherited attribute from the PF. */
        uint32_t atom64s               : 1;  /**< [  8:  8](RO) 64-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request.
                                                                 Since VF's are tied to BAR0, all AtomicOp's will be dropped as unsupported requests.
                                                                 ATOM64S is set as an inherited attribute from the PF. */
        uint32_t atom128s              : 1;  /**< [  9:  9](RO/H) 128-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request.
                                                                 Since VF's are tied to BAR0, all AtomicOp's will be dropped as unsupported requests.
                                                                 ATOM128S is set as an inherited attribute from the PF. */
        uint32_t noroprpr              : 1;  /**< [ 10: 10](RO/H) No RO-enabled PR-PR passing. (This bit applies to RCs.) */
        uint32_t ltrs                  : 1;  /**< [ 11: 11](RO) Latency tolerance reporting (LTR) mechanism supported (not supported). */
        uint32_t tphs                  : 2;  /**< [ 13: 12](RO) TPH completer supported (not supported). */
        uint32_t reserved_14_17        : 4;
        uint32_t obffs                 : 2;  /**< [ 19: 18](RO) Optimized buffer flush fill (OBFF) supported (not supported). */
        uint32_t effs                  : 1;  /**< [ 20: 20](RO) Extended fmt field supported (not supported). */
        uint32_t eetps                 : 1;  /**< [ 21: 21](RO) End-end TLP prefix supported (not supported). */
        uint32_t meetp                 : 2;  /**< [ 23: 22](RO) Read-only copy of the associated PF's PCIEEP()_CFG037[MEETP]. */
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
        uint32_t id0_cp                : 1;  /**< [  9:  9](RAZ) VF RsvdP. */
        uint32_t id0_rq                : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t reserved_7            : 1;
        uint32_t atom_op               : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t ari                   : 1;  /**< [  5:  5](R/W) Alternate routing ID forwarding supported (not supported). */
        uint32_t ctd                   : 1;  /**< [  4:  4](RAZ) VF RsvdP. */
        uint32_t ctv                   : 4;  /**< [  3:  0](RAZ) VF RsvdP. */
#else /* Word 0 - Little Endian */
        uint32_t ctv                   : 4;  /**< [  3:  0](RAZ) VF RsvdP. */
        uint32_t ctd                   : 1;  /**< [  4:  4](RAZ) VF RsvdP. */
        uint32_t ari                   : 1;  /**< [  5:  5](R/W) Alternate routing ID forwarding supported (not supported). */
        uint32_t atom_op               : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t reserved_7            : 1;
        uint32_t id0_rq                : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t id0_cp                : 1;  /**< [  9:  9](RAZ) VF RsvdP. */
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
        uint32_t slsv                  : 7;  /**< [  7:  1](RO) Read-only copy of the associated PF's PCIEEP()_CFG039[SLSV]. */
        uint32_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0            : 1;
        uint32_t slsv                  : 7;  /**< [  7:  1](RO) Read-only copy of the associated PF's PCIEEP()_CFG039[SLSV]. */
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
        uint32_t cdl                   : 1;  /**< [ 16: 16](RO/H) Read-only copy of the associated PF's PCIEEP()_CFG040[CDL]. */
        uint32_t reserved_13_15        : 3;
        uint32_t cde                   : 1;  /**< [ 12: 12](RO) VF's read-only zeros. */
        uint32_t csos                  : 1;  /**< [ 11: 11](RO) VF's read-only zeros. */
        uint32_t emc                   : 1;  /**< [ 10: 10](RO) VF's read-only zeros. */
        uint32_t tm                    : 3;  /**< [  9:  7](RO/H) VF's read-only zeros. */
        uint32_t sde                   : 1;  /**< [  6:  6](RO) VF's read-only zeros. */
        uint32_t hasd                  : 1;  /**< [  5:  5](RO/H) VF's read-only zeros. */
        uint32_t ec                    : 1;  /**< [  4:  4](RO) VF's read-only zeros. */
        uint32_t tls                   : 4;  /**< [  3:  0](RO/H) VF's read-only zeros. */
#else /* Word 0 - Little Endian */
        uint32_t tls                   : 4;  /**< [  3:  0](RO/H) VF's read-only zeros. */
        uint32_t ec                    : 1;  /**< [  4:  4](RO) VF's read-only zeros. */
        uint32_t hasd                  : 1;  /**< [  5:  5](RO/H) VF's read-only zeros. */
        uint32_t sde                   : 1;  /**< [  6:  6](RO) VF's read-only zeros. */
        uint32_t tm                    : 3;  /**< [  9:  7](RO/H) VF's read-only zeros. */
        uint32_t emc                   : 1;  /**< [ 10: 10](RO) VF's read-only zeros. */
        uint32_t csos                  : 1;  /**< [ 11: 11](RO) VF's read-only zeros. */
        uint32_t cde                   : 1;  /**< [ 12: 12](RO) VF's read-only zeros. */
        uint32_t reserved_13_15        : 3;
        uint32_t cdl                   : 1;  /**< [ 16: 16](RO/H) Read-only copy of the associated PF's PCIEEP()_CFG040[CDL]. */
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
        uint32_t msixen                : 1;  /**< [ 31: 31](R/W) MSI-X enable. */
        uint32_t funm                  : 1;  /**< [ 30: 30](R/W) Function mask.
                                                                 0 = Each vectors mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits. */
        uint32_t reserved_27_29        : 3;
        uint32_t msixts                : 11; /**< [ 26: 16](RO/WRSL) MSI-X table size encoded as (table size - 1).

                                                                 This field is writable through PEM()_CFG_WR when PEM()_CFG_WR[ADDR[31]] is set. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. */
        uint32_t msixts                : 11; /**< [ 26: 16](RO/WRSL) MSI-X table size encoded as (table size - 1).

                                                                 This field is writable through PEM()_CFG_WR when PEM()_CFG_WR[ADDR[31]] is set. */
        uint32_t reserved_27_29        : 3;
        uint32_t funm                  : 1;  /**< [ 30: 30](R/W) Function mask.
                                                                 0 = Each vectors mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits. */
        uint32_t msixen                : 1;  /**< [ 31: 31](R/W) MSI-X enable. */
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
        uint32_t msixtoffs             : 29; /**< [ 31:  3](RO) Read-only copy of the associated PF's PCIEEP()_CFG045[MSIXTS]. */
        uint32_t msixtbir              : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG045[MSIXTBIR]. */
#else /* Word 0 - Little Endian */
        uint32_t msixtbir              : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG045[MSIXTBIR]. */
        uint32_t msixtoffs             : 29; /**< [ 31:  3](RO) Read-only copy of the associated PF's PCIEEP()_CFG045[MSIXTS]. */
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
        uint32_t msixpbir              : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG046[MSIXPBIR]. */
#else /* Word 0 - Little Endian */
        uint32_t msixpbir              : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_CFG046[MSIXPBIR]. */
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
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t ariid                 : 16; /**< [ 15:  0](RO/WRSL) PCIE Express extended capability */
#else /* Word 0 - Little Endian */
        uint32_t ariid                 : 16; /**< [ 15:  0](RO/WRSL) PCIE Express extended capability */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. */
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

/**
 * Register (PCICONFIGEP) pcieepvf#_clsize
 *
 * PCIe VF BIST, Header Type, Master Latency Timer, Cache Line Size Register
 * This register contains the fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_clsize_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bist                  : 8;  /**< [ 31: 24](RO) The BIST register functions are not supported. All 8 bits of the BIST register are
                                                                 hardwired to 0x0. */
        uint32_t mfd                   : 1;  /**< [ 23: 23](RO) Read-only copy of the associated PF's PCIEEP()_CLSIZE[MFD]. */
        uint32_t chf                   : 7;  /**< [ 22: 16](RO) Configuration header format. Hardwired to 0x0 for type 0. */
        uint32_t lt                    : 8;  /**< [ 15:  8](RO) Master latency timer. Not applicable for PCI Express, hardwired to 0x0. */
        uint32_t cls                   : 8;  /**< [  7:  0](RO) Read-only copy of the associated PF's PCIEEP()_CLSIZE[CLS].
                                                                 The cache line size register is R/W for legacy compatibility purposes and
                                                                 is not applicable to PCI Express device functionality. Writing to the cache line size
                                                                 register does not impact functionality of the PCI Express bus. */
#else /* Word 0 - Little Endian */
        uint32_t cls                   : 8;  /**< [  7:  0](RO) Read-only copy of the associated PF's PCIEEP()_CLSIZE[CLS].
                                                                 The cache line size register is R/W for legacy compatibility purposes and
                                                                 is not applicable to PCI Express device functionality. Writing to the cache line size
                                                                 register does not impact functionality of the PCI Express bus. */
        uint32_t lt                    : 8;  /**< [ 15:  8](RO) Master latency timer. Not applicable for PCI Express, hardwired to 0x0. */
        uint32_t chf                   : 7;  /**< [ 22: 16](RO) Configuration header format. Hardwired to 0x0 for type 0. */
        uint32_t mfd                   : 1;  /**< [ 23: 23](RO) Read-only copy of the associated PF's PCIEEP()_CLSIZE[MFD]. */
        uint32_t bist                  : 8;  /**< [ 31: 24](RO) The BIST register functions are not supported. All 8 bits of the BIST register are
                                                                 hardwired to 0x0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_clsize_s cn; */
} bdk_pcieepvfx_clsize_t;

static inline uint64_t BDK_PCIEEPVFX_CLSIZE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CLSIZE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x5000000000cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CLSIZE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CLSIZE(a) bdk_pcieepvfx_clsize_t
#define bustype_BDK_PCIEEPVFX_CLSIZE(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CLSIZE(a) "PCIEEPVFX_CLSIZE"
#define busnum_BDK_PCIEEPVFX_CLSIZE(a) (a)
#define arguments_BDK_PCIEEPVFX_CLSIZE(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_cmd
 *
 * PCIe VF Command/Status Register
 * This register contains the second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_cmd_s
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
        uint32_t i_stat                : 1;  /**< [ 19: 19](RO/H) INTx status. Not applicable for SR-IOV.  Hardwired to 0. */
        uint32_t reserved_11_18        : 8;
        uint32_t i_dis                 : 1;  /**< [ 10: 10](RO) VF read-only zero. */
        uint32_t fbbe                  : 1;  /**< [  9:  9](RO) Fast back-to-back transaction enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t see                   : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t ids_wcc               : 1;  /**< [  7:  7](RO) IDSEL stepping/wait cycle control. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t per                   : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t vps                   : 1;  /**< [  5:  5](RO) VGA palette snoop. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t mwice                 : 1;  /**< [  4:  4](RO) Memory write and invalidate. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t scse                  : 1;  /**< [  3:  3](RO) Special cycle enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t me                    : 1;  /**< [  2:  2](R/W/H) Bus master enable. If the VF tries to master the bus when this bit is not set,
                                                                 the request is discarded. A interrupt will be generated setting
                                                                 PEM()_DBG_INFO[BMD_E].
                                                                 Transactions are dropped in the Client.  Non-posted transactions returns a SWI_RSP_ERROR
                                                                 to SLI/DPI/NQM soon thereafter.
                                                                 Bus master enable mimics the behavior of PEM()_FLR_PF0_VF_STOPREQ. */
        uint32_t msae                  : 1;  /**< [  1:  1](RO) VF read-only zero. */
        uint32_t isae                  : 1;  /**< [  0:  0](RO) VF read-only zero. */
#else /* Word 0 - Little Endian */
        uint32_t isae                  : 1;  /**< [  0:  0](RO) VF read-only zero. */
        uint32_t msae                  : 1;  /**< [  1:  1](RO) VF read-only zero. */
        uint32_t me                    : 1;  /**< [  2:  2](R/W/H) Bus master enable. If the VF tries to master the bus when this bit is not set,
                                                                 the request is discarded. A interrupt will be generated setting
                                                                 PEM()_DBG_INFO[BMD_E].
                                                                 Transactions are dropped in the Client.  Non-posted transactions returns a SWI_RSP_ERROR
                                                                 to SLI/DPI/NQM soon thereafter.
                                                                 Bus master enable mimics the behavior of PEM()_FLR_PF0_VF_STOPREQ. */
        uint32_t scse                  : 1;  /**< [  3:  3](RO) Special cycle enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t mwice                 : 1;  /**< [  4:  4](RO) Memory write and invalidate. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t vps                   : 1;  /**< [  5:  5](RO) VGA palette snoop. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t per                   : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t ids_wcc               : 1;  /**< [  7:  7](RO) IDSEL stepping/wait cycle control. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t see                   : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t fbbe                  : 1;  /**< [  9:  9](RO) Fast back-to-back transaction enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t i_dis                 : 1;  /**< [ 10: 10](RO) VF read-only zero. */
        uint32_t reserved_11_18        : 8;
        uint32_t i_stat                : 1;  /**< [ 19: 19](RO/H) INTx status. Not applicable for SR-IOV.  Hardwired to 0. */
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
    /* struct bdk_pcieepvfx_cmd_s cn; */
} bdk_pcieepvfx_cmd_t;

static inline uint64_t BDK_PCIEEPVFX_CMD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_CMD(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000004ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_CMD", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_CMD(a) bdk_pcieepvfx_cmd_t
#define bustype_BDK_PCIEEPVFX_CMD(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_CMD(a) "PCIEEPVFX_CMD"
#define busnum_BDK_PCIEEPVFX_CMD(a) (a)
#define arguments_BDK_PCIEEPVFX_CMD(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_dev_cap
 *
 * PCIe VF Device Capabilities Register
 * This register contains the thirtieth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_dev_cap_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_29_31        : 3;
        uint32_t flr_cap               : 1;  /**< [ 28: 28](RO) Function level reset capability. Set to 1 for SR-IOV core. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO/H) VF undefined. */
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO/H) VF undefined. */
        uint32_t reserved_16_17        : 2;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[RBER]. */
        uint32_t reserved_12_14        : 3;
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[EL1AL]. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[EL0AL]. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[ETFS]. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[PFS]. */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[MPSS]. */
#else /* Word 0 - Little Endian */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[MPSS]. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[PFS]. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[ETFS]. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[EL0AL]. */
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[EL1AL]. */
        uint32_t reserved_12_14        : 3;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[RBER]. */
        uint32_t reserved_16_17        : 2;
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO/H) VF undefined. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO/H) VF undefined. */
        uint32_t flr_cap               : 1;  /**< [ 28: 28](RO) Function level reset capability. Set to 1 for SR-IOV core. */
        uint32_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } s;
    struct bdk_pcieepvfx_dev_cap_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_29_31        : 3;
        uint32_t flr_cap               : 1;  /**< [ 28: 28](RO) Function level reset capability. Set to 1 for SR-IOV core. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO/H) VF undefined. */
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO/H) VF undefined. */
        uint32_t reserved_16_17        : 2;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[RBER]. */
        uint32_t reserved_14           : 1;
        uint32_t reserved_13           : 1;
        uint32_t reserved_12           : 1;
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[EL1AL]. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[EL0AL]. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[ETFS]. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[PFS]. */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[MPSS]. */
#else /* Word 0 - Little Endian */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[MPSS]. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[PFS]. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[ETFS]. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[EL0AL]. */
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[EL1AL]. */
        uint32_t reserved_12           : 1;
        uint32_t reserved_13           : 1;
        uint32_t reserved_14           : 1;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP[RBER]. */
        uint32_t reserved_16_17        : 2;
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO/H) VF undefined. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO/H) VF undefined. */
        uint32_t flr_cap               : 1;  /**< [ 28: 28](RO) Function level reset capability. Set to 1 for SR-IOV core. */
        uint32_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } cn;
} bdk_pcieepvfx_dev_cap_t;

static inline uint64_t BDK_PCIEEPVFX_DEV_CAP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_DEV_CAP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000074ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_DEV_CAP", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_DEV_CAP(a) bdk_pcieepvfx_dev_cap_t
#define bustype_BDK_PCIEEPVFX_DEV_CAP(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_DEV_CAP(a) "PCIEEPVFX_DEV_CAP"
#define busnum_BDK_PCIEEPVFX_DEV_CAP(a) (a)
#define arguments_BDK_PCIEEPVFX_DEV_CAP(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_dev_cap2
 *
 * PCIe VF Device Capabilities 2 Register
 * This register contains the thirty-eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_dev_cap2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t meetp                 : 2;  /**< [ 23: 22](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP2[MEETP]. */
        uint32_t eetps                 : 1;  /**< [ 21: 21](RO) End-end TLP prefix supported (not supported). */
        uint32_t effs                  : 1;  /**< [ 20: 20](RO) Extended fmt field supported (not supported). */
        uint32_t obffs                 : 2;  /**< [ 19: 18](RO) Optimized buffer flush fill (OBFF) supported (not supported). */
        uint32_t reserved_14_17        : 4;
        uint32_t tphs                  : 2;  /**< [ 13: 12](RO) TPH completer supported (not supported). */
        uint32_t ltrs                  : 1;  /**< [ 11: 11](RO) Latency tolerance reporting (LTR) mechanism supported (not supported). */
        uint32_t noroprpr              : 1;  /**< [ 10: 10](RO/H) No RO-enabled PR-PR passing. (This bit applies to RCs.) */
        uint32_t atom128s              : 1;  /**< [  9:  9](RO/H) 128-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request.
                                                                 Since VF's are tied to BAR0, all AtomicOp's will be dropped as unsupported requests.
                                                                 ATOM128S is set as an inherited attribute from the PF. */
        uint32_t atom64s               : 1;  /**< [  8:  8](RO) 64-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request.
                                                                 Since VF's are tied to BAR0, all AtomicOp's will be dropped as unsupported requests.
                                                                 ATOM64S is set as an inherited attribute from the PF. */
        uint32_t atom32s               : 1;  /**< [  7:  7](RO/H) 32-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request.
                                                                 Since VF's are tied to BAR0, all AtomicOp's will be dropped as unsupported requests.
                                                                 ATOM64S is set as an inherited attribute from the PF. */
        uint32_t atom_ops              : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t ari                   : 1;  /**< [  5:  5](RO) Alternate routing ID forwarding supported (not applicable for EP). */
        uint32_t ctds                  : 1;  /**< [  4:  4](RO) Completion timeout disable supported. */
        uint32_t ctrs                  : 4;  /**< [  3:  0](RO) Completion timeout ranges supported. */
#else /* Word 0 - Little Endian */
        uint32_t ctrs                  : 4;  /**< [  3:  0](RO) Completion timeout ranges supported. */
        uint32_t ctds                  : 1;  /**< [  4:  4](RO) Completion timeout disable supported. */
        uint32_t ari                   : 1;  /**< [  5:  5](RO) Alternate routing ID forwarding supported (not applicable for EP). */
        uint32_t atom_ops              : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t atom32s               : 1;  /**< [  7:  7](RO/H) 32-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request.
                                                                 Since VF's are tied to BAR0, all AtomicOp's will be dropped as unsupported requests.
                                                                 ATOM64S is set as an inherited attribute from the PF. */
        uint32_t atom64s               : 1;  /**< [  8:  8](RO) 64-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request.
                                                                 Since VF's are tied to BAR0, all AtomicOp's will be dropped as unsupported requests.
                                                                 ATOM64S is set as an inherited attribute from the PF. */
        uint32_t atom128s              : 1;  /**< [  9:  9](RO/H) 128-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request.
                                                                 Since VF's are tied to BAR0, all AtomicOp's will be dropped as unsupported requests.
                                                                 ATOM128S is set as an inherited attribute from the PF. */
        uint32_t noroprpr              : 1;  /**< [ 10: 10](RO/H) No RO-enabled PR-PR passing. (This bit applies to RCs.) */
        uint32_t ltrs                  : 1;  /**< [ 11: 11](RO) Latency tolerance reporting (LTR) mechanism supported (not supported). */
        uint32_t tphs                  : 2;  /**< [ 13: 12](RO) TPH completer supported (not supported). */
        uint32_t reserved_14_17        : 4;
        uint32_t obffs                 : 2;  /**< [ 19: 18](RO) Optimized buffer flush fill (OBFF) supported (not supported). */
        uint32_t effs                  : 1;  /**< [ 20: 20](RO) Extended fmt field supported (not supported). */
        uint32_t eetps                 : 1;  /**< [ 21: 21](RO) End-end TLP prefix supported (not supported). */
        uint32_t meetp                 : 2;  /**< [ 23: 22](RO) Read-only copy of the associated PF's PCIEEP()_DEV_CAP2[MEETP]. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_dev_cap2_s cn; */
} bdk_pcieepvfx_dev_cap2_t;

static inline uint64_t BDK_PCIEEPVFX_DEV_CAP2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_DEV_CAP2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000094ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_DEV_CAP2", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_DEV_CAP2(a) bdk_pcieepvfx_dev_cap2_t
#define bustype_BDK_PCIEEPVFX_DEV_CAP2(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_DEV_CAP2(a) "PCIEEPVFX_DEV_CAP2"
#define busnum_BDK_PCIEEPVFX_DEV_CAP2(a) (a)
#define arguments_BDK_PCIEEPVFX_DEV_CAP2(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_dev_ctl
 *
 * PCIe VF Device Control/Device Status Register
 * This register contains the thirty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_dev_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_22_31        : 10;
        uint32_t tp                    : 1;  /**< [ 21: 21](RO/H) Transaction pending. Set to 1 when nonposted requests are not yet completed and set to 0
                                                                 when they are completed. */
        uint32_t ap_d                  : 1;  /**< [ 20: 20](RO) VF's read-only zeros. */
        uint32_t ur_d                  : 1;  /**< [ 19: 19](RO/H) Unsupported request detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. [UR_D] occurs when we
                                                                 receive
                                                                 something unsupported. Unsupported requests are nonfatal errors, so [UR_D] should cause
                                                                 [NFE_D]. Receiving a vendor-defined message should cause an unsupported request. */
        uint32_t fe_d                  : 1;  /**< [ 18: 18](RO/H) Fatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in PCIEEPVF()_UCOR_ERR_MSK that has a severity set to fatal. Malformed
                                                                 TLPs
                                                                 generally fit into this category. */
        uint32_t nfe_d                 : 1;  /**< [ 17: 17](RO/H) Nonfatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in PCIEEPVF()_UCOR_ERR_MSK that has a severity set to nonfatal and does
                                                                 not
                                                                 meet advisory nonfatal criteria, which most poisoned TLPs should. */
        uint32_t ce_d                  : 1;  /**< [ 16: 16](RO/H) Correctable error detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. This field is set if we
                                                                 receive any of the errors in PCIEEPVF()_COR_ERR_STAT, for example a replay-timer timeout.
                                                                 Also, it can be set if we get any of the errors in PCIEEPVF()_UCOR_ERR_MSK that has a
                                                                 severity
                                                                 set to Nonfatal and meets the Advisory Nonfatal criteria, which most ECRC errors should. */
        uint32_t i_flr                 : 1;  /**< [ 15: 15](WO) Initiate function level reset when written to one.

                                                                 [I_FLR] must not be written to one via the indirect PEM()_CFG_WR. It should only ever
                                                                 be written to one via a direct PCIe access. */
        uint32_t mrrs                  : 3;  /**< [ 14: 12](RAZ) VF RsvdP. */
        uint32_t ns_en                 : 1;  /**< [ 11: 11](RAZ) VF RsvdP. */
        uint32_t ap_en                 : 1;  /**< [ 10: 10](RAZ) VF RsvdP. */
        uint32_t pf_en                 : 1;  /**< [  9:  9](RAZ) VF RsvdP. */
        uint32_t etf_en                : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t mps                   : 3;  /**< [  7:  5](RAZ) VF RsvdP. */
        uint32_t ro_en                 : 1;  /**< [  4:  4](RAZ) VF RsvdP. */
        uint32_t ur_en                 : 1;  /**< [  3:  3](RAZ) VF RsvdP. */
        uint32_t fe_en                 : 1;  /**< [  2:  2](RAZ) VF RsvdP. */
        uint32_t nfe_en                : 1;  /**< [  1:  1](RAZ) VF RsvdP. */
        uint32_t ce_en                 : 1;  /**< [  0:  0](RAZ) VF RsvdP. */
#else /* Word 0 - Little Endian */
        uint32_t ce_en                 : 1;  /**< [  0:  0](RAZ) VF RsvdP. */
        uint32_t nfe_en                : 1;  /**< [  1:  1](RAZ) VF RsvdP. */
        uint32_t fe_en                 : 1;  /**< [  2:  2](RAZ) VF RsvdP. */
        uint32_t ur_en                 : 1;  /**< [  3:  3](RAZ) VF RsvdP. */
        uint32_t ro_en                 : 1;  /**< [  4:  4](RAZ) VF RsvdP. */
        uint32_t mps                   : 3;  /**< [  7:  5](RAZ) VF RsvdP. */
        uint32_t etf_en                : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t pf_en                 : 1;  /**< [  9:  9](RAZ) VF RsvdP. */
        uint32_t ap_en                 : 1;  /**< [ 10: 10](RAZ) VF RsvdP. */
        uint32_t ns_en                 : 1;  /**< [ 11: 11](RAZ) VF RsvdP. */
        uint32_t mrrs                  : 3;  /**< [ 14: 12](RAZ) VF RsvdP. */
        uint32_t i_flr                 : 1;  /**< [ 15: 15](WO) Initiate function level reset when written to one.

                                                                 [I_FLR] must not be written to one via the indirect PEM()_CFG_WR. It should only ever
                                                                 be written to one via a direct PCIe access. */
        uint32_t ce_d                  : 1;  /**< [ 16: 16](RO/H) Correctable error detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. This field is set if we
                                                                 receive any of the errors in PCIEEPVF()_COR_ERR_STAT, for example a replay-timer timeout.
                                                                 Also, it can be set if we get any of the errors in PCIEEPVF()_UCOR_ERR_MSK that has a
                                                                 severity
                                                                 set to Nonfatal and meets the Advisory Nonfatal criteria, which most ECRC errors should. */
        uint32_t nfe_d                 : 1;  /**< [ 17: 17](RO/H) Nonfatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in PCIEEPVF()_UCOR_ERR_MSK that has a severity set to nonfatal and does
                                                                 not
                                                                 meet advisory nonfatal criteria, which most poisoned TLPs should. */
        uint32_t fe_d                  : 1;  /**< [ 18: 18](RO/H) Fatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in PCIEEPVF()_UCOR_ERR_MSK that has a severity set to fatal. Malformed
                                                                 TLPs
                                                                 generally fit into this category. */
        uint32_t ur_d                  : 1;  /**< [ 19: 19](RO/H) Unsupported request detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. [UR_D] occurs when we
                                                                 receive
                                                                 something unsupported. Unsupported requests are nonfatal errors, so [UR_D] should cause
                                                                 [NFE_D]. Receiving a vendor-defined message should cause an unsupported request. */
        uint32_t ap_d                  : 1;  /**< [ 20: 20](RO) VF's read-only zeros. */
        uint32_t tp                    : 1;  /**< [ 21: 21](RO/H) Transaction pending. Set to 1 when nonposted requests are not yet completed and set to 0
                                                                 when they are completed. */
        uint32_t reserved_22_31        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_dev_ctl_s cn; */
} bdk_pcieepvfx_dev_ctl_t;

static inline uint64_t BDK_PCIEEPVFX_DEV_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_DEV_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000078ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_DEV_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_DEV_CTL(a) bdk_pcieepvfx_dev_ctl_t
#define bustype_BDK_PCIEEPVFX_DEV_CTL(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_DEV_CTL(a) "PCIEEPVFX_DEV_CTL"
#define busnum_BDK_PCIEEPVFX_DEV_CTL(a) (a)
#define arguments_BDK_PCIEEPVFX_DEV_CTL(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_dev_ctl2
 *
 * PCIe VF Device Control 2 Register/Device Status 2 Register
 * This register contains the thirty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_dev_ctl2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t eetpb                 : 1;  /**< [ 15: 15](RO) Unsupported end-end TLP prefix blocking. */
        uint32_t obffe                 : 2;  /**< [ 14: 13](RO) Optimized buffer flush fill (OBFF) enable (not supported). */
        uint32_t reserved_10_12        : 3;
        uint32_t id0_cp                : 1;  /**< [  9:  9](RAZ) VF RsvdP. */
        uint32_t id0_rq                : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t reserved_7            : 1;
        uint32_t atom_op               : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t ari                   : 1;  /**< [  5:  5](R/W) Alternate routing ID forwarding supported (not supported). */
        uint32_t ctd                   : 1;  /**< [  4:  4](RAZ) VF RsvdP. */
        uint32_t ctv                   : 4;  /**< [  3:  0](RAZ) VF RsvdP. */
#else /* Word 0 - Little Endian */
        uint32_t ctv                   : 4;  /**< [  3:  0](RAZ) VF RsvdP. */
        uint32_t ctd                   : 1;  /**< [  4:  4](RAZ) VF RsvdP. */
        uint32_t ari                   : 1;  /**< [  5:  5](R/W) Alternate routing ID forwarding supported (not supported). */
        uint32_t atom_op               : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t reserved_7            : 1;
        uint32_t id0_rq                : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t id0_cp                : 1;  /**< [  9:  9](RAZ) VF RsvdP. */
        uint32_t reserved_10_12        : 3;
        uint32_t obffe                 : 2;  /**< [ 14: 13](RO) Optimized buffer flush fill (OBFF) enable (not supported). */
        uint32_t eetpb                 : 1;  /**< [ 15: 15](RO) Unsupported end-end TLP prefix blocking. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_dev_ctl2_s cn; */
} bdk_pcieepvfx_dev_ctl2_t;

static inline uint64_t BDK_PCIEEPVFX_DEV_CTL2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_DEV_CTL2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000098ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_DEV_CTL2", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_DEV_CTL2(a) bdk_pcieepvfx_dev_ctl2_t
#define bustype_BDK_PCIEEPVFX_DEV_CTL2(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_DEV_CTL2(a) "PCIEEPVFX_DEV_CTL2"
#define busnum_BDK_PCIEEPVFX_DEV_CTL2(a) (a)
#define arguments_BDK_PCIEEPVFX_DEV_CTL2(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_e_cap_list
 *
 * PCIe VF PCIe Capabilities/PCIe Capabilities List Register
 * This register contains the twenty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_e_cap_list_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_30_31        : 2;
        uint32_t imn                   : 5;  /**< [ 29: 25](RO) Read-only copy of the associated PF's PCIEEP()_E_CAP_LIST[IMN]. */
        uint32_t si                    : 1;  /**< [ 24: 24](RO) Read-only copy of the associated PF's PCIEEP()_E_CAP_LIST[SI]. */
        uint32_t dpt                   : 4;  /**< [ 23: 20](RO) Read-only copy of the associated PF's PCIEEP()_E_CAP_LIST[DPT]. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) Read-only copy of the associated PF's PCIEEP()_E_CAP_LIST[PCIECV]. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. Points to the MSI-X capabilities by default. */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCI Express capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCI Express capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. Points to the MSI-X capabilities by default. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) Read-only copy of the associated PF's PCIEEP()_E_CAP_LIST[PCIECV]. */
        uint32_t dpt                   : 4;  /**< [ 23: 20](RO) Read-only copy of the associated PF's PCIEEP()_E_CAP_LIST[DPT]. */
        uint32_t si                    : 1;  /**< [ 24: 24](RO) Read-only copy of the associated PF's PCIEEP()_E_CAP_LIST[SI]. */
        uint32_t imn                   : 5;  /**< [ 29: 25](RO) Read-only copy of the associated PF's PCIEEP()_E_CAP_LIST[IMN]. */
        uint32_t reserved_30_31        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_e_cap_list_s cn; */
} bdk_pcieepvfx_e_cap_list_t;

static inline uint64_t BDK_PCIEEPVFX_E_CAP_LIST(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_E_CAP_LIST(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000070ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_E_CAP_LIST", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_E_CAP_LIST(a) bdk_pcieepvfx_e_cap_list_t
#define bustype_BDK_PCIEEPVFX_E_CAP_LIST(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_E_CAP_LIST(a) "PCIEEPVFX_E_CAP_LIST"
#define busnum_BDK_PCIEEPVFX_E_CAP_LIST(a) (a)
#define arguments_BDK_PCIEEPVFX_E_CAP_LIST(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_ebar
 *
 * PCIe VF Expansion ROM Base Address Register
 * This register contains the thirteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_ebar_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t eraddr                : 13; /**< [ 31: 19](RO) Read-only copy of the associated PF's PCIEEP()_EBAR[ERADDR]. */
        uint32_t reserved_1_18         : 18;
        uint32_t er_en                 : 1;  /**< [  0:  0](RO) Read-only copy of the associated PF's PCIEEP()_EBAR[ER_EN]. */
#else /* Word 0 - Little Endian */
        uint32_t er_en                 : 1;  /**< [  0:  0](RO) Read-only copy of the associated PF's PCIEEP()_EBAR[ER_EN]. */
        uint32_t reserved_1_18         : 18;
        uint32_t eraddr                : 13; /**< [ 31: 19](RO) Read-only copy of the associated PF's PCIEEP()_EBAR[ERADDR]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_ebar_s cn; */
} bdk_pcieepvfx_ebar_t;

static inline uint64_t BDK_PCIEEPVFX_EBAR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_EBAR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000030ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_EBAR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_EBAR(a) bdk_pcieepvfx_ebar_t
#define bustype_BDK_PCIEEPVFX_EBAR(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_EBAR(a) "PCIEEPVFX_EBAR"
#define busnum_BDK_PCIEEPVFX_EBAR(a) (a)
#define arguments_BDK_PCIEEPVFX_EBAR(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_ext_cap
 *
 * PCIe VF PCI Express ARI Extended Capability
 * This register contains the sixty-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_ext_cap_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t ariid                 : 16; /**< [ 15:  0](RO/WRSL) PCIE Express extended capability */
#else /* Word 0 - Little Endian */
        uint32_t ariid                 : 16; /**< [ 15:  0](RO/WRSL) PCIE Express extended capability */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_ext_cap_s cn; */
} bdk_pcieepvfx_ext_cap_t;

static inline uint64_t BDK_PCIEEPVFX_EXT_CAP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_EXT_CAP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000100ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_EXT_CAP", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_EXT_CAP(a) bdk_pcieepvfx_ext_cap_t
#define bustype_BDK_PCIEEPVFX_EXT_CAP(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_EXT_CAP(a) "PCIEEPVFX_EXT_CAP"
#define busnum_BDK_PCIEEPVFX_EXT_CAP(a) (a)
#define arguments_BDK_PCIEEPVFX_EXT_CAP(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_id
 *
 * PCIe VF Vendor and Device Register
 * This register contains the first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_id_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t devid                 : 16; /**< [ 31: 16](RO) Device ID. For SR-IOV VFs always 0xFFFF. */
        uint32_t vendid                : 16; /**< [ 15:  0](RO) Vendor ID. For SR-IOV VFs always 0xFFFF. */
#else /* Word 0 - Little Endian */
        uint32_t vendid                : 16; /**< [ 15:  0](RO) Vendor ID. For SR-IOV VFs always 0xFFFF. */
        uint32_t devid                 : 16; /**< [ 31: 16](RO) Device ID. For SR-IOV VFs always 0xFFFF. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_id_s cn; */
} bdk_pcieepvfx_id_t;

static inline uint64_t BDK_PCIEEPVFX_ID(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_ID(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000000ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_ID", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_ID(a) bdk_pcieepvfx_id_t
#define bustype_BDK_PCIEEPVFX_ID(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_ID(a) "PCIEEPVFX_ID"
#define busnum_BDK_PCIEEPVFX_ID(a) (a)
#define arguments_BDK_PCIEEPVFX_ID(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_int
 *
 * PCIe VF Interrupt Line/Interrupt Pin/Bridge Control Register
 * This register contains the sixteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ml                    : 8;  /**< [ 31: 24](RO/H) VF's read-only zeros. */
        uint32_t mg                    : 8;  /**< [ 23: 16](RO/H) VF's read-only zeros. */
        uint32_t inta                  : 8;  /**< [ 15:  8](RO) VF's read-only zeros. */
        uint32_t il                    : 8;  /**< [  7:  0](RO) VF's read-only zeros. */
#else /* Word 0 - Little Endian */
        uint32_t il                    : 8;  /**< [  7:  0](RO) VF's read-only zeros. */
        uint32_t inta                  : 8;  /**< [ 15:  8](RO) VF's read-only zeros. */
        uint32_t mg                    : 8;  /**< [ 23: 16](RO/H) VF's read-only zeros. */
        uint32_t ml                    : 8;  /**< [ 31: 24](RO/H) VF's read-only zeros. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_int_s cn; */
} bdk_pcieepvfx_int_t;

static inline uint64_t BDK_PCIEEPVFX_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x5000000003cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_INT(a) bdk_pcieepvfx_int_t
#define bustype_BDK_PCIEEPVFX_INT(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_INT(a) "PCIEEPVFX_INT"
#define busnum_BDK_PCIEEPVFX_INT(a) (a)
#define arguments_BDK_PCIEEPVFX_INT(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_link_cap
 *
 * PCIe VF Link Capabilities Register
 * This register contains the thirty-second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_link_cap_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t pnum                  : 8;  /**< [ 31: 24](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[PNUM]. */
        uint32_t reserved_22_23        : 2;
        uint32_t lbnc                  : 1;  /**< [ 21: 21](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[LBNC]. */
        uint32_t dllarc                : 1;  /**< [ 20: 20](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[DLLARC]. */
        uint32_t sderc                 : 1;  /**< [ 19: 19](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[SDERC]. */
        uint32_t cpm                   : 1;  /**< [ 18: 18](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[CPM]. */
        uint32_t l1el                  : 3;  /**< [ 17: 15](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[L1EL]. */
        uint32_t l0el                  : 3;  /**< [ 14: 12](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[L0EL]. */
        uint32_t aslpms                : 2;  /**< [ 11: 10](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[ASLPMS]. */
        uint32_t mlw                   : 6;  /**< [  9:  4](RO/H) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[MLW]. */
        uint32_t mls                   : 4;  /**< [  3:  0](RO/H) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[MLS]. */
#else /* Word 0 - Little Endian */
        uint32_t mls                   : 4;  /**< [  3:  0](RO/H) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[MLS]. */
        uint32_t mlw                   : 6;  /**< [  9:  4](RO/H) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[MLW]. */
        uint32_t aslpms                : 2;  /**< [ 11: 10](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[ASLPMS]. */
        uint32_t l0el                  : 3;  /**< [ 14: 12](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[L0EL]. */
        uint32_t l1el                  : 3;  /**< [ 17: 15](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[L1EL]. */
        uint32_t cpm                   : 1;  /**< [ 18: 18](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[CPM]. */
        uint32_t sderc                 : 1;  /**< [ 19: 19](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[SDERC]. */
        uint32_t dllarc                : 1;  /**< [ 20: 20](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[DLLARC]. */
        uint32_t lbnc                  : 1;  /**< [ 21: 21](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[LBNC]. */
        uint32_t reserved_22_23        : 2;
        uint32_t pnum                  : 8;  /**< [ 31: 24](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP[PNUM]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_link_cap_s cn; */
} bdk_pcieepvfx_link_cap_t;

static inline uint64_t BDK_PCIEEPVFX_LINK_CAP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_LINK_CAP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x5000000007cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_LINK_CAP", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_LINK_CAP(a) bdk_pcieepvfx_link_cap_t
#define bustype_BDK_PCIEEPVFX_LINK_CAP(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_LINK_CAP(a) "PCIEEPVFX_LINK_CAP"
#define busnum_BDK_PCIEEPVFX_LINK_CAP(a) (a)
#define arguments_BDK_PCIEEPVFX_LINK_CAP(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_link_cap2
 *
 * PCIe VF Link Capabilities 2 Register
 * This register contains the fortieth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_link_cap2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t cls                   : 1;  /**< [  8:  8](RO) Crosslink supported. */
        uint32_t slsv                  : 7;  /**< [  7:  1](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP2[SLSV]. */
        uint32_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0            : 1;
        uint32_t slsv                  : 7;  /**< [  7:  1](RO) Read-only copy of the associated PF's PCIEEP()_LINK_CAP2[SLSV]. */
        uint32_t cls                   : 1;  /**< [  8:  8](RO) Crosslink supported. */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_link_cap2_s cn; */
} bdk_pcieepvfx_link_cap2_t;

static inline uint64_t BDK_PCIEEPVFX_LINK_CAP2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_LINK_CAP2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x5000000009cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_LINK_CAP2", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_LINK_CAP2(a) bdk_pcieepvfx_link_cap2_t
#define bustype_BDK_PCIEEPVFX_LINK_CAP2(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_LINK_CAP2(a) "PCIEEPVFX_LINK_CAP2"
#define busnum_BDK_PCIEEPVFX_LINK_CAP2(a) (a)
#define arguments_BDK_PCIEEPVFX_LINK_CAP2(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_link_ctl
 *
 * PCIe VF Link Control/Link Status Register
 * This register contains the thirty-third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_link_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_12_31        : 20;
        uint32_t lab_int_enb           : 1;  /**< [ 11: 11](RO) Link autonomous bandwidth interrupt enable. This bit is not applicable and is reserved for
                                                                 endpoints. */
        uint32_t lbm_int_enb           : 1;  /**< [ 10: 10](RO) Link bandwidth management interrupt enable. This bit is not applicable and is reserved for
                                                                 endpoints. */
        uint32_t hawd                  : 1;  /**< [  9:  9](RAZ) VF RsvdP. */
        uint32_t ecpm                  : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t es                    : 1;  /**< [  7:  7](RAZ) VF RsvdP. */
        uint32_t ccc                   : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t rl                    : 1;  /**< [  5:  5](RO) Retrain link. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t ld                    : 1;  /**< [  4:  4](RO) Link disable. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t rcb                   : 1;  /**< [  3:  3](RAZ) VF RsvdP. */
        uint32_t reserved_2            : 1;
        uint32_t aslpc                 : 2;  /**< [  1:  0](RAZ) VF RsvdP. */
#else /* Word 0 - Little Endian */
        uint32_t aslpc                 : 2;  /**< [  1:  0](RAZ) VF RsvdP. */
        uint32_t reserved_2            : 1;
        uint32_t rcb                   : 1;  /**< [  3:  3](RAZ) VF RsvdP. */
        uint32_t ld                    : 1;  /**< [  4:  4](RO) Link disable. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t rl                    : 1;  /**< [  5:  5](RO) Retrain link. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t ccc                   : 1;  /**< [  6:  6](RAZ) VF RsvdP. */
        uint32_t es                    : 1;  /**< [  7:  7](RAZ) VF RsvdP. */
        uint32_t ecpm                  : 1;  /**< [  8:  8](RAZ) VF RsvdP. */
        uint32_t hawd                  : 1;  /**< [  9:  9](RAZ) VF RsvdP. */
        uint32_t lbm_int_enb           : 1;  /**< [ 10: 10](RO) Link bandwidth management interrupt enable. This bit is not applicable and is reserved for
                                                                 endpoints. */
        uint32_t lab_int_enb           : 1;  /**< [ 11: 11](RO) Link autonomous bandwidth interrupt enable. This bit is not applicable and is reserved for
                                                                 endpoints. */
        uint32_t reserved_12_31        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_link_ctl_s cn; */
} bdk_pcieepvfx_link_ctl_t;

static inline uint64_t BDK_PCIEEPVFX_LINK_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_LINK_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000080ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_LINK_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_LINK_CTL(a) bdk_pcieepvfx_link_ctl_t
#define bustype_BDK_PCIEEPVFX_LINK_CTL(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_LINK_CTL(a) "PCIEEPVFX_LINK_CTL"
#define busnum_BDK_PCIEEPVFX_LINK_CTL(a) (a)
#define arguments_BDK_PCIEEPVFX_LINK_CTL(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_link_ctl2
 *
 * PCIe VF Link Control 2 Register/Link Status 2 Register
 * This register contains the forty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_link_ctl2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_17_31        : 15;
        uint32_t cdl                   : 1;  /**< [ 16: 16](RO/H) Read-only copy of the associated PF's PCIEEP()_LINK_CTL2[CDL]. */
        uint32_t reserved_13_15        : 3;
        uint32_t cde                   : 1;  /**< [ 12: 12](RO) VF's read-only zeros. */
        uint32_t csos                  : 1;  /**< [ 11: 11](RO) VF's read-only zeros. */
        uint32_t emc                   : 1;  /**< [ 10: 10](RO) VF's read-only zeros. */
        uint32_t tm                    : 3;  /**< [  9:  7](RO/H) VF's read-only zeros. */
        uint32_t sde                   : 1;  /**< [  6:  6](RO) VF's read-only zeros. */
        uint32_t hasd                  : 1;  /**< [  5:  5](RO/H) VF's read-only zeros. */
        uint32_t ec                    : 1;  /**< [  4:  4](RO) VF's read-only zeros. */
        uint32_t tls                   : 4;  /**< [  3:  0](RO/H) VF's read-only zeros. */
#else /* Word 0 - Little Endian */
        uint32_t tls                   : 4;  /**< [  3:  0](RO/H) VF's read-only zeros. */
        uint32_t ec                    : 1;  /**< [  4:  4](RO) VF's read-only zeros. */
        uint32_t hasd                  : 1;  /**< [  5:  5](RO/H) VF's read-only zeros. */
        uint32_t sde                   : 1;  /**< [  6:  6](RO) VF's read-only zeros. */
        uint32_t tm                    : 3;  /**< [  9:  7](RO/H) VF's read-only zeros. */
        uint32_t emc                   : 1;  /**< [ 10: 10](RO) VF's read-only zeros. */
        uint32_t csos                  : 1;  /**< [ 11: 11](RO) VF's read-only zeros. */
        uint32_t cde                   : 1;  /**< [ 12: 12](RO) VF's read-only zeros. */
        uint32_t reserved_13_15        : 3;
        uint32_t cdl                   : 1;  /**< [ 16: 16](RO/H) Read-only copy of the associated PF's PCIEEP()_LINK_CTL2[CDL]. */
        uint32_t reserved_17_31        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_link_ctl2_s cn; */
} bdk_pcieepvfx_link_ctl2_t;

static inline uint64_t BDK_PCIEEPVFX_LINK_CTL2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_LINK_CTL2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x500000000a0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_LINK_CTL2", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_LINK_CTL2(a) bdk_pcieepvfx_link_ctl2_t
#define bustype_BDK_PCIEEPVFX_LINK_CTL2(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_LINK_CTL2(a) "PCIEEPVFX_LINK_CTL2"
#define busnum_BDK_PCIEEPVFX_LINK_CTL2(a) (a)
#define arguments_BDK_PCIEEPVFX_LINK_CTL2(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_msix_cap_cntrl
 *
 * PCIe VF PCI Express MSI-X Capability ID/MSI-X Next Item Pointer/MSI-X Control Register
 * This register contains the forty-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_msix_cap_cntrl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixen                : 1;  /**< [ 31: 31](R/W) MSI-X enable. */
        uint32_t funm                  : 1;  /**< [ 30: 30](R/W) Function mask.
                                                                 0 = Each vectors mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits. */
        uint32_t reserved_27_29        : 3;
        uint32_t msixts                : 11; /**< [ 26: 16](RO/WRSL) MSI-X table size encoded as (table size - 1).

                                                                 This field is writable through PEM()_CFG_WR when PEM()_CFG_WR[ADDR[31]] is set. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. */
        uint32_t msixts                : 11; /**< [ 26: 16](RO/WRSL) MSI-X table size encoded as (table size - 1).

                                                                 This field is writable through PEM()_CFG_WR when PEM()_CFG_WR[ADDR[31]] is set. */
        uint32_t reserved_27_29        : 3;
        uint32_t funm                  : 1;  /**< [ 30: 30](R/W) Function mask.
                                                                 0 = Each vectors mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits. */
        uint32_t msixen                : 1;  /**< [ 31: 31](R/W) MSI-X enable. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_msix_cap_cntrl_s cn; */
} bdk_pcieepvfx_msix_cap_cntrl_t;

static inline uint64_t BDK_PCIEEPVFX_MSIX_CAP_CNTRL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_MSIX_CAP_CNTRL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x500000000b0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_MSIX_CAP_CNTRL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_MSIX_CAP_CNTRL(a) bdk_pcieepvfx_msix_cap_cntrl_t
#define bustype_BDK_PCIEEPVFX_MSIX_CAP_CNTRL(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_MSIX_CAP_CNTRL(a) "PCIEEPVFX_MSIX_CAP_CNTRL"
#define busnum_BDK_PCIEEPVFX_MSIX_CAP_CNTRL(a) (a)
#define arguments_BDK_PCIEEPVFX_MSIX_CAP_CNTRL(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_msix_pba
 *
 * PCIe VF PCI Express MSI-X PBA Offset and BIR Register
 * This register contains the forty-seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_msix_pba_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixpoffs             : 29; /**< [ 31:  3](RO) MSI-X table offset register. Base address of the MSI-X PBA, as an offset from the base
                                                                 address of the BAR indicated by the table PBA bits. */
        uint32_t msixpbir              : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_MSIX_PBA[MSIXPBIR]. */
#else /* Word 0 - Little Endian */
        uint32_t msixpbir              : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_MSIX_PBA[MSIXPBIR]. */
        uint32_t msixpoffs             : 29; /**< [ 31:  3](RO) MSI-X table offset register. Base address of the MSI-X PBA, as an offset from the base
                                                                 address of the BAR indicated by the table PBA bits. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_msix_pba_s cn; */
} bdk_pcieepvfx_msix_pba_t;

static inline uint64_t BDK_PCIEEPVFX_MSIX_PBA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_MSIX_PBA(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x500000000b8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_MSIX_PBA", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_MSIX_PBA(a) bdk_pcieepvfx_msix_pba_t
#define bustype_BDK_PCIEEPVFX_MSIX_PBA(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_MSIX_PBA(a) "PCIEEPVFX_MSIX_PBA"
#define busnum_BDK_PCIEEPVFX_MSIX_PBA(a) (a)
#define arguments_BDK_PCIEEPVFX_MSIX_PBA(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_msix_table
 *
 * PCIe VF PCI Express MSI-X Table Offset and BIR Register
 * This register contains the forty-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_msix_table_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixtoffs             : 29; /**< [ 31:  3](RO) Read-only copy of the associated PF's PCIEEP()_MSIX_TABLE[MSIXTS]. */
        uint32_t msixtbir              : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_MSIX_TABLE[MSIXTBIR]. */
#else /* Word 0 - Little Endian */
        uint32_t msixtbir              : 3;  /**< [  2:  0](RO) Read-only copy of the associated PF's PCIEEP()_MSIX_TABLE[MSIXTBIR]. */
        uint32_t msixtoffs             : 29; /**< [ 31:  3](RO) Read-only copy of the associated PF's PCIEEP()_MSIX_TABLE[MSIXTS]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_msix_table_s cn; */
} bdk_pcieepvfx_msix_table_t;

static inline uint64_t BDK_PCIEEPVFX_MSIX_TABLE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_MSIX_TABLE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x500000000b4ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_MSIX_TABLE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_MSIX_TABLE(a) bdk_pcieepvfx_msix_table_t
#define bustype_BDK_PCIEEPVFX_MSIX_TABLE(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_MSIX_TABLE(a) "PCIEEPVFX_MSIX_TABLE"
#define busnum_BDK_PCIEEPVFX_MSIX_TABLE(a) (a)
#define arguments_BDK_PCIEEPVFX_MSIX_TABLE(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_rev
 *
 * PCIe VF Class Code/Revision ID Register
 * This register contains the third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_rev_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO) Read-only copy of the associated PF's PCIEEP()_REV[BCC]. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO) Read-only copy of the associated PF's PCIEEP()_REV[SC]. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO) Read-only copy of the associated PF's PCIEEP()_REV[PI]. */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/WRSL) Revision ID, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field.
                                                                 See MIO_FUS_DAT2[CHIP_ID] for more information. */
#else /* Word 0 - Little Endian */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/WRSL) Revision ID, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field.
                                                                 See MIO_FUS_DAT2[CHIP_ID] for more information. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO) Read-only copy of the associated PF's PCIEEP()_REV[PI]. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO) Read-only copy of the associated PF's PCIEEP()_REV[SC]. */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO) Read-only copy of the associated PF's PCIEEP()_REV[BCC]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_rev_s cn; */
} bdk_pcieepvfx_rev_t;

static inline uint64_t BDK_PCIEEPVFX_REV(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_REV(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000008ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_REV", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_REV(a) bdk_pcieepvfx_rev_t
#define bustype_BDK_PCIEEPVFX_REV(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_REV(a) "PCIEEPVFX_REV"
#define busnum_BDK_PCIEEPVFX_REV(a) (a)
#define arguments_BDK_PCIEEPVFX_REV(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_subsys
 *
 * PCIe VF SubSystem ID/Subsystem Vendor ID Register
 * This register contains the twelfth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_subsys_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ssid                  : 16; /**< [ 31: 16](RO) Read-only copy of the associated PF's PCIEEP()_SUBSYS[SSID]. */
        uint32_t ssvid                 : 16; /**< [ 15:  0](RO) Read-only copy of the associated PF's PCIEEP()_SUBSYS[SSVID]. */
#else /* Word 0 - Little Endian */
        uint32_t ssvid                 : 16; /**< [ 15:  0](RO) Read-only copy of the associated PF's PCIEEP()_SUBSYS[SSVID]. */
        uint32_t ssid                  : 16; /**< [ 31: 16](RO) Read-only copy of the associated PF's PCIEEP()_SUBSYS[SSID]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepvfx_subsys_s cn; */
} bdk_pcieepvfx_subsys_t;

static inline uint64_t BDK_PCIEEPVFX_SUBSYS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_SUBSYS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x5000000002cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_SUBSYS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_SUBSYS(a) bdk_pcieepvfx_subsys_t
#define bustype_BDK_PCIEEPVFX_SUBSYS(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_SUBSYS(a) "PCIEEPVFX_SUBSYS"
#define busnum_BDK_PCIEEPVFX_SUBSYS(a) (a)
#define arguments_BDK_PCIEEPVFX_SUBSYS(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieepvf#_ucor_err_stat
 *
 * PCIe VF PCI Express ARI Capability Register/PCI Express ARI Control Register
 * This register contains the sixty-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepvfx_ucor_err_stat_s
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
    /* struct bdk_pcieepvfx_ucor_err_stat_s cn; */
} bdk_pcieepvfx_ucor_err_stat_t;

static inline uint64_t BDK_PCIEEPVFX_UCOR_ERR_STAT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPVFX_UCOR_ERR_STAT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x50000000104ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPVFX_UCOR_ERR_STAT", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPVFX_UCOR_ERR_STAT(a) bdk_pcieepvfx_ucor_err_stat_t
#define bustype_BDK_PCIEEPVFX_UCOR_ERR_STAT(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPVFX_UCOR_ERR_STAT(a) "PCIEEPVFX_UCOR_ERR_STAT"
#define busnum_BDK_PCIEEPVFX_UCOR_ERR_STAT(a) (a)
#define arguments_BDK_PCIEEPVFX_UCOR_ERR_STAT(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_PCIEEPVF_H__ */
