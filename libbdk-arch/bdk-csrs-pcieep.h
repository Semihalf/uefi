#ifndef __BDK_CSRS_PCIEEP_H__
#define __BDK_CSRS_PCIEEP_H__
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
 * Cavium PCIEEP.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (PCICONFIGEP) pcieep#_cfg000
 *
 * PCIe Vendor and Device Register
 * This register contains the first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg000_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t devid                 : 16; /**< [ 31: 16](RO/WRSL) Device ID for CN73XX, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. For EEPROM loads, also see VENDID of this register.
                                                                 SLI PKT (PF0/PF1) DEVID = 0x9700.
                                                                 NQM PKT (PF2)     DEVID = 0x9701. */
        uint32_t vendid                : 16; /**< [ 15:  0](RO/WRSL) Cavium's vendor ID, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. During an EPROM Load, if a value of 0xFFFF is loaded to this field and
                                                                 a value of 0xFFFF is loaded to the DEVID field of this register, the value will not be
                                                                 loaded, EEPROM load will stop, and the FastLinkEnable bit will be set in the
                                                                 PCIEEP()_CFG452 register. */
#else /* Word 0 - Little Endian */
        uint32_t vendid                : 16; /**< [ 15:  0](RO/WRSL) Cavium's vendor ID, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. During an EPROM Load, if a value of 0xFFFF is loaded to this field and
                                                                 a value of 0xFFFF is loaded to the DEVID field of this register, the value will not be
                                                                 loaded, EEPROM load will stop, and the FastLinkEnable bit will be set in the
                                                                 PCIEEP()_CFG452 register. */
        uint32_t devid                 : 16; /**< [ 31: 16](RO/WRSL) Device ID for CN73XX, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. For EEPROM loads, also see VENDID of this register.
                                                                 SLI PKT (PF0/PF1) DEVID = 0x9700.
                                                                 NQM PKT (PF2)     DEVID = 0x9701. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg000_s cn; */
} bdk_pcieepx_cfg000_t;

static inline uint64_t BDK_PCIEEPX_CFG000(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG000(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000000ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG000", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG000(a) bdk_pcieepx_cfg000_t
#define bustype_BDK_PCIEEPX_CFG000(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG000(a) "PCIEEPX_CFG000"
#define busnum_BDK_PCIEEPX_CFG000(a) (a)
#define arguments_BDK_PCIEEPX_CFG000(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg001
 *
 * Command/Status Register
 * This register contains the second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg001_s
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
        uint32_t i_dis                 : 1;  /**< [ 10: 10](R/W) INTx assertion disable. */
        uint32_t fbbe                  : 1;  /**< [  9:  9](RO) Fast back-to-back transaction enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t see                   : 1;  /**< [  8:  8](R/W) SERR# enable. */
        uint32_t ids_wcc               : 1;  /**< [  7:  7](RO) IDSEL stepping/wait cycle control. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t per                   : 1;  /**< [  6:  6](R/W) Parity error response. */
        uint32_t vps                   : 1;  /**< [  5:  5](RO) VGA palette snoop. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t mwice                 : 1;  /**< [  4:  4](RO) Memory write and invalidate. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t scse                  : 1;  /**< [  3:  3](RO) Special cycle enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t me                    : 1;  /**< [  2:  2](R/W) Bus master enable.  If the PF or any of its VF's try to master the bus when this bit is
                                                                 not set,
                                                                 the request is discarded. A interrupt will be generated setting the
                                                                 SPEM()_PF()_DBG_INFO[P()_BMD_E bit.
                                                                 Transactions are dropped in the Client.  Non-posted transactions returns a SWI_RSP_ERROR
                                                                 to SLI/DPI/NQM soon thereafter.
                                                                 Bus master enable mimics the behavor of SPEM()_FLR_PF()_STOPREQ. */
        uint32_t msae                  : 1;  /**< [  1:  1](R/W) Memory space access enable. */
        uint32_t isae                  : 1;  /**< [  0:  0](R/W) I/O space access enable. */
#else /* Word 0 - Little Endian */
        uint32_t isae                  : 1;  /**< [  0:  0](R/W) I/O space access enable. */
        uint32_t msae                  : 1;  /**< [  1:  1](R/W) Memory space access enable. */
        uint32_t me                    : 1;  /**< [  2:  2](R/W) Bus master enable.  If the PF or any of its VF's try to master the bus when this bit is
                                                                 not set,
                                                                 the request is discarded. A interrupt will be generated setting the
                                                                 SPEM()_PF()_DBG_INFO[P()_BMD_E bit.
                                                                 Transactions are dropped in the Client.  Non-posted transactions returns a SWI_RSP_ERROR
                                                                 to SLI/DPI/NQM soon thereafter.
                                                                 Bus master enable mimics the behavor of SPEM()_FLR_PF()_STOPREQ. */
        uint32_t scse                  : 1;  /**< [  3:  3](RO) Special cycle enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t mwice                 : 1;  /**< [  4:  4](RO) Memory write and invalidate. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t vps                   : 1;  /**< [  5:  5](RO) VGA palette snoop. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t per                   : 1;  /**< [  6:  6](R/W) Parity error response. */
        uint32_t ids_wcc               : 1;  /**< [  7:  7](RO) IDSEL stepping/wait cycle control. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t see                   : 1;  /**< [  8:  8](R/W) SERR# enable. */
        uint32_t fbbe                  : 1;  /**< [  9:  9](RO) Fast back-to-back transaction enable. Not applicable for PCI Express. Must be hardwired to 0. */
        uint32_t i_dis                 : 1;  /**< [ 10: 10](R/W) INTx assertion disable. */
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
    /* struct bdk_pcieepx_cfg001_s cn; */
} bdk_pcieepx_cfg001_t;

static inline uint64_t BDK_PCIEEPX_CFG001(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG001(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000004ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG001", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG001(a) bdk_pcieepx_cfg001_t
#define bustype_BDK_PCIEEPX_CFG001(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG001(a) "PCIEEPX_CFG001"
#define busnum_BDK_PCIEEPX_CFG001(a) (a)
#define arguments_BDK_PCIEEPX_CFG001(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg002
 *
 * Class Code/Revision ID Register
 * This register contains the third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg002_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO/WRSL) Base class code,

                                                                 _ PF0:          0x0b  (Processers)
                                                                 _ PF1:          0x0b  (Processors)
                                                                 _ PF2:          0x01  (Mass Storage controller)

                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO/WRSL) Subclass code,

                                                                 _ PF0:          0x30 (MIPS)
                                                                 _ PF1:          0x30 (MIPS)
                                                                 _ PF2:          0x08 (Non-volatile)

                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO/WRSL) Programming interface.

                                                                 _ PF0:          0x0 (386)
                                                                 _ PF1:          0x0 (386)
                                                                 _ PF2:          0x2 (NVMe)

                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/WRSL) Revision ID, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. Possible values:
                                                                 0x0 = Pass 1.0. */
#else /* Word 0 - Little Endian */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/WRSL) Revision ID, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. Possible values:
                                                                 0x0 = Pass 1.0. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO/WRSL) Programming interface.

                                                                 _ PF0:          0x0 (386)
                                                                 _ PF1:          0x0 (386)
                                                                 _ PF2:          0x2 (NVMe)

                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO/WRSL) Subclass code,

                                                                 _ PF0:          0x30 (MIPS)
                                                                 _ PF1:          0x30 (MIPS)
                                                                 _ PF2:          0x08 (Non-volatile)

                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO/WRSL) Base class code,

                                                                 _ PF0:          0x0b  (Processers)
                                                                 _ PF1:          0x0b  (Processors)
                                                                 _ PF2:          0x01  (Mass Storage controller)

                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg002_s cn; */
} bdk_pcieepx_cfg002_t;

static inline uint64_t BDK_PCIEEPX_CFG002(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG002(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000008ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG002", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG002(a) bdk_pcieepx_cfg002_t
#define bustype_BDK_PCIEEPX_CFG002(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG002(a) "PCIEEPX_CFG002"
#define busnum_BDK_PCIEEPX_CFG002(a) (a)
#define arguments_BDK_PCIEEPX_CFG002(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg003
 *
 * BIST, Header Type, Master Latency Timer, Cache Line Size Register
 * This register contains the fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg003_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bist                  : 8;  /**< [ 31: 24](RO) The BIST register functions are not supported. All 8 bits of the BIST register are
                                                                 hardwired to 0x0. */
        uint32_t mfd                   : 1;  /**< [ 23: 23](RO/WRSL) Multi function device. The multi function device bit is writable through PEM()_CFG_WR.
                                                                 However, this is a single function device. Therefore, the application must not write a 1
                                                                 to this bit.

                                                                 _ PCIEEP(0..2): 0x1
                                                                 _ PCIEEP(3..5): 0x0 */
        uint32_t chf                   : 7;  /**< [ 22: 16](RO) Configuration header format. Hardwired to 0x0 for type 0. */
        uint32_t lt                    : 8;  /**< [ 15:  8](RO) Master latency timer. Not applicable for PCI Express, hardwired to 0x0. */
        uint32_t cls                   : 8;  /**< [  7:  0](R/W) Cache line size. The cache line size register is R/W for legacy compatibility purposes and
                                                                 is not applicable to PCI Express device functionality. Writing to the cache line size
                                                                 register does not impact functionality of the PCI Express bus. */
#else /* Word 0 - Little Endian */
        uint32_t cls                   : 8;  /**< [  7:  0](R/W) Cache line size. The cache line size register is R/W for legacy compatibility purposes and
                                                                 is not applicable to PCI Express device functionality. Writing to the cache line size
                                                                 register does not impact functionality of the PCI Express bus. */
        uint32_t lt                    : 8;  /**< [ 15:  8](RO) Master latency timer. Not applicable for PCI Express, hardwired to 0x0. */
        uint32_t chf                   : 7;  /**< [ 22: 16](RO) Configuration header format. Hardwired to 0x0 for type 0. */
        uint32_t mfd                   : 1;  /**< [ 23: 23](RO/WRSL) Multi function device. The multi function device bit is writable through PEM()_CFG_WR.
                                                                 However, this is a single function device. Therefore, the application must not write a 1
                                                                 to this bit.

                                                                 _ PCIEEP(0..2): 0x1
                                                                 _ PCIEEP(3..5): 0x0 */
        uint32_t bist                  : 8;  /**< [ 31: 24](RO) The BIST register functions are not supported. All 8 bits of the BIST register are
                                                                 hardwired to 0x0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg003_s cn; */
} bdk_pcieepx_cfg003_t;

static inline uint64_t BDK_PCIEEPX_CFG003(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG003(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000000cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG003", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG003(a) bdk_pcieepx_cfg003_t
#define bustype_BDK_PCIEEPX_CFG003(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG003(a) "PCIEEPX_CFG003"
#define busnum_BDK_PCIEEPX_CFG003(a) (a)
#define arguments_BDK_PCIEEPX_CFG003(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg004
 *
 * Base Address 0 Low Register
 * This register contains the fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg004_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 9;  /**< [ 31: 23](R/W) Lower bits of the BAR 0 base address. */
        uint32_t reserved_4_22         : 19;
        uint32_t pf                    : 1;  /**< [  3:  3](RO/WRSL) Prefetchable. This field is writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/WRSL) BAR type.
                                                                 0x0 = 32-bit BAR.
                                                                 0x2 = 64-bit BAR.

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO/WRSL) Memory space indicator.
                                                                 0 = BAR 0 is a memory BAR.
                                                                 1 = BAR 0 is an I/O BAR.

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO/WRSL) Memory space indicator.
                                                                 0 = BAR 0 is a memory BAR.
                                                                 1 = BAR 0 is an I/O BAR.

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/WRSL) BAR type.
                                                                 0x0 = 32-bit BAR.
                                                                 0x2 = 64-bit BAR.

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO/WRSL) Prefetchable. This field is writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t reserved_4_22         : 19;
        uint32_t lbab                  : 9;  /**< [ 31: 23](R/W) Lower bits of the BAR 0 base address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg004_s cn; */
} bdk_pcieepx_cfg004_t;

static inline uint64_t BDK_PCIEEPX_CFG004(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG004(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000010ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG004", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG004(a) bdk_pcieepx_cfg004_t
#define bustype_BDK_PCIEEPX_CFG004(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG004(a) "PCIEEPX_CFG004"
#define busnum_BDK_PCIEEPX_CFG004(a) (a)
#define arguments_BDK_PCIEEPX_CFG004(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg004_mask
 *
 * BAR Mask 0 Low Register
 * The BAR 0 Mask register is invisible to host software and not readable from the application.
 * The BAR 0 Mask register is only writable through PEM()_CFG_WR.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg004_mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lmask                 : 31; /**< [ 31:  1](WORSL/H) BAR mask low. */
        uint32_t enb                   : 1;  /**< [  0:  0](WORSL/H) BAR enable. 0: BAR 0 is disabled, 1: BAR 0 is enabled.
                                                                 Bit 0 is interpreted as BAR enable when writing to the BAR mask register rather than as a
                                                                 mask bit because bit 0 of a BAR is always masked from writing by host software. Bit 0 must
                                                                 be written prior to writing the other mask bits. */
#else /* Word 0 - Little Endian */
        uint32_t enb                   : 1;  /**< [  0:  0](WORSL/H) BAR enable. 0: BAR 0 is disabled, 1: BAR 0 is enabled.
                                                                 Bit 0 is interpreted as BAR enable when writing to the BAR mask register rather than as a
                                                                 mask bit because bit 0 of a BAR is always masked from writing by host software. Bit 0 must
                                                                 be written prior to writing the other mask bits. */
        uint32_t lmask                 : 31; /**< [ 31:  1](WORSL/H) BAR mask low. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg004_mask_s cn; */
} bdk_pcieepx_cfg004_mask_t;

static inline uint64_t BDK_PCIEEPX_CFG004_MASK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG004_MASK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30080000010ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG004_MASK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG004_MASK(a) bdk_pcieepx_cfg004_mask_t
#define bustype_BDK_PCIEEPX_CFG004_MASK(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG004_MASK(a) "PCIEEPX_CFG004_MASK"
#define busnum_BDK_PCIEEPX_CFG004_MASK(a) (a)
#define arguments_BDK_PCIEEPX_CFG004_MASK(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg005
 *
 * Base Address 0 High Register
 * This register contains the sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg005_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W) Contains the upper 32 bits of the BAR 0 base address. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W) Contains the upper 32 bits of the BAR 0 base address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg005_s cn; */
} bdk_pcieepx_cfg005_t;

static inline uint64_t BDK_PCIEEPX_CFG005(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG005(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000014ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG005", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG005(a) bdk_pcieepx_cfg005_t
#define bustype_BDK_PCIEEPX_CFG005(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG005(a) "PCIEEPX_CFG005"
#define busnum_BDK_PCIEEPX_CFG005(a) (a)
#define arguments_BDK_PCIEEPX_CFG005(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg005_mask
 *
 * BAR Mask 0 High Register
 * The BAR 0 Mask register is invisible to host software and not readable from the application.
 * The BAR 0 Mask register is only writable through PEM()_CFG_WR.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg005_mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t umask                 : 32; /**< [ 31:  0](WORSL/H) BAR mask high. */
#else /* Word 0 - Little Endian */
        uint32_t umask                 : 32; /**< [ 31:  0](WORSL/H) BAR mask high. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg005_mask_s cn; */
} bdk_pcieepx_cfg005_mask_t;

static inline uint64_t BDK_PCIEEPX_CFG005_MASK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG005_MASK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30080000014ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG005_MASK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG005_MASK(a) bdk_pcieepx_cfg005_mask_t
#define bustype_BDK_PCIEEPX_CFG005_MASK(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG005_MASK(a) "PCIEEPX_CFG005_MASK"
#define busnum_BDK_PCIEEPX_CFG005_MASK(a) (a)
#define arguments_BDK_PCIEEPX_CFG005_MASK(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg006
 *
 * Base Address 1 Low Register
 * This register contains the seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg006_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 6;  /**< [ 31: 26](R/W) Lower bits of the BAR 1 base address. */
        uint32_t reserved_4_25         : 22;
        uint32_t pf                    : 1;  /**< [  3:  3](RO/WRSL) Prefetchable. This field is writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/WRSL) BAR type.
                                                                 0x0 = 32-bit BAR.
                                                                 0x2 = 64-bit BAR.

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO/WRSL) Memory space indicator.
                                                                 0 = BAR 1 is a memory BAR.
                                                                 1 = BAR 1 is an I/O BAR.

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO/WRSL) Memory space indicator.
                                                                 0 = BAR 1 is a memory BAR.
                                                                 1 = BAR 1 is an I/O BAR.

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/WRSL) BAR type.
                                                                 0x0 = 32-bit BAR.
                                                                 0x2 = 64-bit BAR.

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO/WRSL) Prefetchable. This field is writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t reserved_4_25         : 22;
        uint32_t lbab                  : 6;  /**< [ 31: 26](R/W) Lower bits of the BAR 1 base address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg006_s cn; */
} bdk_pcieepx_cfg006_t;

static inline uint64_t BDK_PCIEEPX_CFG006(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG006(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000018ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG006", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG006(a) bdk_pcieepx_cfg006_t
#define bustype_BDK_PCIEEPX_CFG006(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG006(a) "PCIEEPX_CFG006"
#define busnum_BDK_PCIEEPX_CFG006(a) (a)
#define arguments_BDK_PCIEEPX_CFG006(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg006_mask
 *
 * BAR Mask 1 Low Register
 * The BAR 1 Mask register is invisible to host software and not readable from the application.
 * The BAR 1 Mask register is only writable through PEM()_CFG_WR.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg006_mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lmask                 : 31; /**< [ 31:  1](WORSL/H) BAR mask low */
        uint32_t enb                   : 1;  /**< [  0:  0](WORSL/H) BAR enable. 0: BAR 1 is disabled, 1: BAR 1 is enabled.
                                                                 Bit 0 is interpreted as BAR enable when writing to the BAR mask register rather than as a
                                                                 mask bit because bit 0 of a BAR is always masked from writing by host software. Bit 0 must
                                                                 be written prior to writing the other mask bits. */
#else /* Word 0 - Little Endian */
        uint32_t enb                   : 1;  /**< [  0:  0](WORSL/H) BAR enable. 0: BAR 1 is disabled, 1: BAR 1 is enabled.
                                                                 Bit 0 is interpreted as BAR enable when writing to the BAR mask register rather than as a
                                                                 mask bit because bit 0 of a BAR is always masked from writing by host software. Bit 0 must
                                                                 be written prior to writing the other mask bits. */
        uint32_t lmask                 : 31; /**< [ 31:  1](WORSL/H) BAR mask low */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg006_mask_s cn; */
} bdk_pcieepx_cfg006_mask_t;

static inline uint64_t BDK_PCIEEPX_CFG006_MASK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG006_MASK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30080000018ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG006_MASK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG006_MASK(a) bdk_pcieepx_cfg006_mask_t
#define bustype_BDK_PCIEEPX_CFG006_MASK(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG006_MASK(a) "PCIEEPX_CFG006_MASK"
#define busnum_BDK_PCIEEPX_CFG006_MASK(a) (a)
#define arguments_BDK_PCIEEPX_CFG006_MASK(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg007
 *
 * Base Address 1 High Register
 * This register contains the eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg007_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W) Contains the upper 32 bits of the BAR 1 base address. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W) Contains the upper 32 bits of the BAR 1 base address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg007_s cn; */
} bdk_pcieepx_cfg007_t;

static inline uint64_t BDK_PCIEEPX_CFG007(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG007(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000001cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG007", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG007(a) bdk_pcieepx_cfg007_t
#define bustype_BDK_PCIEEPX_CFG007(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG007(a) "PCIEEPX_CFG007"
#define busnum_BDK_PCIEEPX_CFG007(a) (a)
#define arguments_BDK_PCIEEPX_CFG007(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg007_mask
 *
 * BAR Mask 1 High Register
 * The BAR 1 Mask register is invisible to host software and not readable from the application.
 * The BAR 1 Mask register is only writable through PEM()_CFG_WR.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg007_mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t umask                 : 32; /**< [ 31:  0](WORSL/H) BAR mask high. */
#else /* Word 0 - Little Endian */
        uint32_t umask                 : 32; /**< [ 31:  0](WORSL/H) BAR mask high. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg007_mask_s cn; */
} bdk_pcieepx_cfg007_mask_t;

static inline uint64_t BDK_PCIEEPX_CFG007_MASK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG007_MASK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3008000001cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG007_MASK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG007_MASK(a) bdk_pcieepx_cfg007_mask_t
#define bustype_BDK_PCIEEPX_CFG007_MASK(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG007_MASK(a) "PCIEEPX_CFG007_MASK"
#define busnum_BDK_PCIEEPX_CFG007_MASK(a) (a)
#define arguments_BDK_PCIEEPX_CFG007_MASK(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg008
 *
 * Base Address 2 Low Register
 * This register contains the ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg008_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 12; /**< [ 31: 20](R/W) Lower bits of the BAR 2 base address */
        uint32_t reserved_4_19         : 16;
        uint32_t pf                    : 1;  /**< [  3:  3](RO/WRSL) Prefetchable. This field is writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/WRSL) BAR type.
                                                                 0x0 = 32-bit BAR.
                                                                 0x2 = 64-bit BAR.

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO/WRSL) Memory space indicator.
                                                                 0 = BAR 2 is a memory BAR.
                                                                 1 = BAR 2 is an I/O BAR.

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO/WRSL) Memory space indicator.
                                                                 0 = BAR 2 is a memory BAR.
                                                                 1 = BAR 2 is an I/O BAR.

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/WRSL) BAR type.
                                                                 0x0 = 32-bit BAR.
                                                                 0x2 = 64-bit BAR.

                                                                 This field is writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO/WRSL) Prefetchable. This field is writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t reserved_4_19         : 16;
        uint32_t lbab                  : 12; /**< [ 31: 20](R/W) Lower bits of the BAR 2 base address */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg008_s cn; */
} bdk_pcieepx_cfg008_t;

static inline uint64_t BDK_PCIEEPX_CFG008(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG008(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000020ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG008", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG008(a) bdk_pcieepx_cfg008_t
#define bustype_BDK_PCIEEPX_CFG008(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG008(a) "PCIEEPX_CFG008"
#define busnum_BDK_PCIEEPX_CFG008(a) (a)
#define arguments_BDK_PCIEEPX_CFG008(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg008_mask
 *
 * BAR Mask 2 Low Register
 * The BAR 2 Mask register is invisible to host software and not readable from the application.
 * The BAR 2 Mask register is only writable through PEM()_CFG_WR.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg008_mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lmask                 : 31; /**< [ 31:  1](WORSL/H) BAR mask low. */
        uint32_t enb                   : 1;  /**< [  0:  0](WORSL/H) BAR enable. 0: BAR 2 is disabled, 1: BAR 2 is enabled.
                                                                 Bit 0 is interpreted as BAR enable when writing to the BAR mask register rather than as a
                                                                 mask bit because bit 0 of a BAR is always masked from writing by host software. Bit 0 must
                                                                 be written prior to writing the other mask bits. */
#else /* Word 0 - Little Endian */
        uint32_t enb                   : 1;  /**< [  0:  0](WORSL/H) BAR enable. 0: BAR 2 is disabled, 1: BAR 2 is enabled.
                                                                 Bit 0 is interpreted as BAR enable when writing to the BAR mask register rather than as a
                                                                 mask bit because bit 0 of a BAR is always masked from writing by host software. Bit 0 must
                                                                 be written prior to writing the other mask bits. */
        uint32_t lmask                 : 31; /**< [ 31:  1](WORSL/H) BAR mask low. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg008_mask_s cn; */
} bdk_pcieepx_cfg008_mask_t;

static inline uint64_t BDK_PCIEEPX_CFG008_MASK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG008_MASK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30080000020ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG008_MASK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG008_MASK(a) bdk_pcieepx_cfg008_mask_t
#define bustype_BDK_PCIEEPX_CFG008_MASK(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG008_MASK(a) "PCIEEPX_CFG008_MASK"
#define busnum_BDK_PCIEEPX_CFG008_MASK(a) (a)
#define arguments_BDK_PCIEEPX_CFG008_MASK(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg009
 *
 * Base Address 2 High Register
 * This register contains the tenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg009_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W) Contains the upper 32 bits of the BAR 2 base address. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W) Contains the upper 32 bits of the BAR 2 base address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg009_s cn; */
} bdk_pcieepx_cfg009_t;

static inline uint64_t BDK_PCIEEPX_CFG009(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG009(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000024ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG009", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG009(a) bdk_pcieepx_cfg009_t
#define bustype_BDK_PCIEEPX_CFG009(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG009(a) "PCIEEPX_CFG009"
#define busnum_BDK_PCIEEPX_CFG009(a) (a)
#define arguments_BDK_PCIEEPX_CFG009(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg009_mask
 *
 * BAR Mask 2 High Register
 * The BAR 2 Mask register is invisible to host software and not readable from the application.
 * The BAR 2 Mask register is only writable through PEM()_CFG_WR.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg009_mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t umask                 : 32; /**< [ 31:  0](WORSL/H) BAR mask high. */
#else /* Word 0 - Little Endian */
        uint32_t umask                 : 32; /**< [ 31:  0](WORSL/H) BAR mask high. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg009_mask_s cn; */
} bdk_pcieepx_cfg009_mask_t;

static inline uint64_t BDK_PCIEEPX_CFG009_MASK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG009_MASK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30080000024ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG009_MASK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG009_MASK(a) bdk_pcieepx_cfg009_mask_t
#define bustype_BDK_PCIEEPX_CFG009_MASK(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG009_MASK(a) "PCIEEPX_CFG009_MASK"
#define busnum_BDK_PCIEEPX_CFG009_MASK(a) (a)
#define arguments_BDK_PCIEEPX_CFG009_MASK(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg010
 *
 * Card Bus CIS Pointer Register
 * This register contains the eleventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg010_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t cisp                  : 32; /**< [ 31:  0](RO/WRSL) CardBus CIS pointer. Optional, writable through PEM()_CFG_WR. */
#else /* Word 0 - Little Endian */
        uint32_t cisp                  : 32; /**< [ 31:  0](RO/WRSL) CardBus CIS pointer. Optional, writable through PEM()_CFG_WR. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg010_s cn; */
} bdk_pcieepx_cfg010_t;

static inline uint64_t BDK_PCIEEPX_CFG010(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG010(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000028ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG010", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG010(a) bdk_pcieepx_cfg010_t
#define bustype_BDK_PCIEEPX_CFG010(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG010(a) "PCIEEPX_CFG010"
#define busnum_BDK_PCIEEPX_CFG010(a) (a)
#define arguments_BDK_PCIEEPX_CFG010(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg011
 *
 * SubSystem ID/Subsystem Vendor ID Register
 * This register contains the twelfth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg011_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ssid                  : 16; /**< [ 31: 16](RO/WRSL) Subsystem ID.
                                                                 Assigned by PCI-SIG, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. */
        uint32_t ssvid                 : 16; /**< [ 15:  0](RO/WRSL) Subsystem vendor ID.
                                                                 Assigned by PCI-SIG, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. */
#else /* Word 0 - Little Endian */
        uint32_t ssvid                 : 16; /**< [ 15:  0](RO/WRSL) Subsystem vendor ID.
                                                                 Assigned by PCI-SIG, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. */
        uint32_t ssid                  : 16; /**< [ 31: 16](RO/WRSL) Subsystem ID.
                                                                 Assigned by PCI-SIG, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg011_s cn; */
} bdk_pcieepx_cfg011_t;

static inline uint64_t BDK_PCIEEPX_CFG011(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG011(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000002cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG011", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG011(a) bdk_pcieepx_cfg011_t
#define bustype_BDK_PCIEEPX_CFG011(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG011(a) "PCIEEPX_CFG011"
#define busnum_BDK_PCIEEPX_CFG011(a) (a)
#define arguments_BDK_PCIEEPX_CFG011(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg012
 *
 * Expansion ROM Base Address Register
 * This register contains the thirteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg012_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t eraddr                : 16; /**< [ 31: 16](R/W) Expansion ROM address. */
        uint32_t reserved_1_15         : 15;
        uint32_t er_en                 : 1;  /**< [  0:  0](R/W) Expansion ROM enable.

                                                                 _ PF0:          Supported.
                                                                 _ PF1:          Supported.
                                                                 _ PF2:          Not Supported. */
#else /* Word 0 - Little Endian */
        uint32_t er_en                 : 1;  /**< [  0:  0](R/W) Expansion ROM enable.

                                                                 _ PF0:          Supported.
                                                                 _ PF1:          Supported.
                                                                 _ PF2:          Not Supported. */
        uint32_t reserved_1_15         : 15;
        uint32_t eraddr                : 16; /**< [ 31: 16](R/W) Expansion ROM address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg012_s cn; */
} bdk_pcieepx_cfg012_t;

static inline uint64_t BDK_PCIEEPX_CFG012(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG012(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000030ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG012", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG012(a) bdk_pcieepx_cfg012_t
#define bustype_BDK_PCIEEPX_CFG012(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG012(a) "PCIEEPX_CFG012"
#define busnum_BDK_PCIEEPX_CFG012(a) (a)
#define arguments_BDK_PCIEEPX_CFG012(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg012_mask
 *
 * Expansion ROM BAR Mask Register
 * The ROM Mask register is invisible to host software and not readable from the application. The
 * ROM Mask register is only writable through PEM()_CFG_WR.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg012_mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t mask                  : 31; /**< [ 31:  1](WORSL/H) BAR mask low */
        uint32_t enb                   : 1;  /**< [  0:  0](WORSL/H) BAR enable. 0 = BAR ROM is disabled; 1 = BAR ROM is enabled. Bit 0 is interpreted as BAR
                                                                 enable when writing to the BAR mask register rather than as a mask bit because bit 0 of a
                                                                 BAR is always masked from writing by host software. Bit 0 must be written prior to writing
                                                                 the other mask bits. */
#else /* Word 0 - Little Endian */
        uint32_t enb                   : 1;  /**< [  0:  0](WORSL/H) BAR enable. 0 = BAR ROM is disabled; 1 = BAR ROM is enabled. Bit 0 is interpreted as BAR
                                                                 enable when writing to the BAR mask register rather than as a mask bit because bit 0 of a
                                                                 BAR is always masked from writing by host software. Bit 0 must be written prior to writing
                                                                 the other mask bits. */
        uint32_t mask                  : 31; /**< [ 31:  1](WORSL/H) BAR mask low */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg012_mask_s cn; */
} bdk_pcieepx_cfg012_mask_t;

static inline uint64_t BDK_PCIEEPX_CFG012_MASK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG012_MASK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30080000030ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG012_MASK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG012_MASK(a) bdk_pcieepx_cfg012_mask_t
#define bustype_BDK_PCIEEPX_CFG012_MASK(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG012_MASK(a) "PCIEEPX_CFG012_MASK"
#define busnum_BDK_PCIEEPX_CFG012_MASK(a) (a)
#define arguments_BDK_PCIEEPX_CFG012_MASK(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg013
 *
 * Capability Pointer Register
 * This register contains the fourteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg013_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cp                    : 8;  /**< [  7:  0](RO/WRSL) First capability pointer. Points to power management capability structure by default,
                                                                 writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t cp                    : 8;  /**< [  7:  0](RO/WRSL) First capability pointer. Points to power management capability structure by default,
                                                                 writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg013_s cn; */
} bdk_pcieepx_cfg013_t;

static inline uint64_t BDK_PCIEEPX_CFG013(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG013(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000034ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG013", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG013(a) bdk_pcieepx_cfg013_t
#define bustype_BDK_PCIEEPX_CFG013(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG013(a) "PCIEEPX_CFG013"
#define busnum_BDK_PCIEEPX_CFG013(a) (a)
#define arguments_BDK_PCIEEPX_CFG013(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg015
 *
 * Interrupt Line/Interrupt Pin/Bridge Control Register
 * This register contains the sixteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg015_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ml                    : 8;  /**< [ 31: 24](RO) Maximum latency (hardwired to 0x0). */
        uint32_t mg                    : 8;  /**< [ 23: 16](RO) Minimum grant (hardwired to 0x0). */
        uint32_t inta                  : 8;  /**< [ 15:  8](RO/WRSL) Interrupt pin. Identifies the legacy interrupt message that the device (or device
                                                                 function) uses. The interrupt pin register is writable through PEM()_CFG_WR. In a
                                                                 single-function configuration, only INTA is used. Therefore, the application must not
                                                                 change this field. */
        uint32_t il                    : 8;  /**< [  7:  0](R/W) Interrupt line. */
#else /* Word 0 - Little Endian */
        uint32_t il                    : 8;  /**< [  7:  0](R/W) Interrupt line. */
        uint32_t inta                  : 8;  /**< [ 15:  8](RO/WRSL) Interrupt pin. Identifies the legacy interrupt message that the device (or device
                                                                 function) uses. The interrupt pin register is writable through PEM()_CFG_WR. In a
                                                                 single-function configuration, only INTA is used. Therefore, the application must not
                                                                 change this field. */
        uint32_t mg                    : 8;  /**< [ 23: 16](RO) Minimum grant (hardwired to 0x0). */
        uint32_t ml                    : 8;  /**< [ 31: 24](RO) Maximum latency (hardwired to 0x0). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg015_s cn; */
} bdk_pcieepx_cfg015_t;

static inline uint64_t BDK_PCIEEPX_CFG015(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG015(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000003cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG015", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG015(a) bdk_pcieepx_cfg015_t
#define bustype_BDK_PCIEEPX_CFG015(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG015(a) "PCIEEPX_CFG015"
#define busnum_BDK_PCIEEPX_CFG015(a) (a)
#define arguments_BDK_PCIEEPX_CFG015(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg016
 *
 * PCIe EP Power Management Capability ID Register
 * This register contains the seventeenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg016_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t pmes                  : 5;  /**< [ 31: 27](RO/WRSL) PME_Support.

                                                                 _ Bit 11: If set, PME Messages can be generated from D0.

                                                                 _ Bit 12: If set, PME Messages can be generated from D1.

                                                                 _ Bit 13: If set, PME Messages can be generated from D2.

                                                                 _ Bit 14: If set, PME Messages can be generated from D3hot.

                                                                 _ Bit 15: If set, PME Messages can be generated from D3cold.

                                                                 The PME_Support field is writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field. */
        uint32_t d2s                   : 1;  /**< [ 26: 26](RO/WRSL) D2 support, writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t d1s                   : 1;  /**< [ 25: 25](RO/WRSL) D1 support, writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t auxc                  : 3;  /**< [ 24: 22](RO/WRSL) AUX current, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t dsi                   : 1;  /**< [ 21: 21](RO/WRSL) Device specific initialization (DSI), writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t reserved_20           : 1;
        uint32_t pme_clock             : 1;  /**< [ 19: 19](RO) PME clock, hardwired to 0. */
        uint32_t pmsv                  : 3;  /**< [ 18: 16](RO/WRSL) Power management specification version, writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO/WRSL) Next capability pointer. Points to the MSI capabilities (PF0, PF1) or
                                                                 PCIe capabilities list (PF2) by default, writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t pmcid                 : 8;  /**< [  7:  0](RO) Power management capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pmcid                 : 8;  /**< [  7:  0](RO) Power management capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO/WRSL) Next capability pointer. Points to the MSI capabilities (PF0, PF1) or
                                                                 PCIe capabilities list (PF2) by default, writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t pmsv                  : 3;  /**< [ 18: 16](RO/WRSL) Power management specification version, writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t pme_clock             : 1;  /**< [ 19: 19](RO) PME clock, hardwired to 0. */
        uint32_t reserved_20           : 1;
        uint32_t dsi                   : 1;  /**< [ 21: 21](RO/WRSL) Device specific initialization (DSI), writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t auxc                  : 3;  /**< [ 24: 22](RO/WRSL) AUX current, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t d1s                   : 1;  /**< [ 25: 25](RO/WRSL) D1 support, writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t d2s                   : 1;  /**< [ 26: 26](RO/WRSL) D2 support, writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t pmes                  : 5;  /**< [ 31: 27](RO/WRSL) PME_Support.

                                                                 _ Bit 11: If set, PME Messages can be generated from D0.

                                                                 _ Bit 12: If set, PME Messages can be generated from D1.

                                                                 _ Bit 13: If set, PME Messages can be generated from D2.

                                                                 _ Bit 14: If set, PME Messages can be generated from D3hot.

                                                                 _ Bit 15: If set, PME Messages can be generated from D3cold.

                                                                 The PME_Support field is writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg016_s cn; */
} bdk_pcieepx_cfg016_t;

static inline uint64_t BDK_PCIEEPX_CFG016(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG016(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000040ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG016", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG016(a) bdk_pcieepx_cfg016_t
#define bustype_BDK_PCIEEPX_CFG016(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG016(a) "PCIEEPX_CFG016"
#define busnum_BDK_PCIEEPX_CFG016(a) (a)
#define arguments_BDK_PCIEEPX_CFG016(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg017
 *
 * Power Management Control and Status Register
 * This register contains the eighteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg017_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t pmdia                 : 8;  /**< [ 31: 24](RO) Data register for additional information (not supported). */
        uint32_t bpccee                : 1;  /**< [ 23: 23](RO) Bus power/clock control enable, hardwired to 0. */
        uint32_t bd3h                  : 1;  /**< [ 22: 22](RO) B2/B3 support, hardwired to 0. */
        uint32_t reserved_16_21        : 6;
        uint32_t pmess                 : 1;  /**< [ 15: 15](R/W1C/H) PME status. Indicates whether or not a previously enabled PME event occurred. */
        uint32_t pmedsia               : 2;  /**< [ 14: 13](RO) Data scale (not supported). */
        uint32_t pmds                  : 4;  /**< [ 12:  9](RO) Data select (not supported). */
        uint32_t pmeens                : 1;  /**< [  8:  8](R/W) PME enable. A value of 1 indicates that the device is enabled to generate PME. */
        uint32_t reserved_4_7          : 4;
        uint32_t nsr                   : 1;  /**< [  3:  3](RO/WRSL) No soft reset, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t reserved_2            : 1;
        uint32_t ps                    : 2;  /**< [  1:  0](R/W) Power state. Controls the device power state:
                                                                 0x0 = D0.
                                                                 0x1 = D1.
                                                                 0x2 = D2.
                                                                 0x3 = D3.

                                                                 The written value is ignored if the specific state is not supported. */
#else /* Word 0 - Little Endian */
        uint32_t ps                    : 2;  /**< [  1:  0](R/W) Power state. Controls the device power state:
                                                                 0x0 = D0.
                                                                 0x1 = D1.
                                                                 0x2 = D2.
                                                                 0x3 = D3.

                                                                 The written value is ignored if the specific state is not supported. */
        uint32_t reserved_2            : 1;
        uint32_t nsr                   : 1;  /**< [  3:  3](RO/WRSL) No soft reset, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t reserved_4_7          : 4;
        uint32_t pmeens                : 1;  /**< [  8:  8](R/W) PME enable. A value of 1 indicates that the device is enabled to generate PME. */
        uint32_t pmds                  : 4;  /**< [ 12:  9](RO) Data select (not supported). */
        uint32_t pmedsia               : 2;  /**< [ 14: 13](RO) Data scale (not supported). */
        uint32_t pmess                 : 1;  /**< [ 15: 15](R/W1C/H) PME status. Indicates whether or not a previously enabled PME event occurred. */
        uint32_t reserved_16_21        : 6;
        uint32_t bd3h                  : 1;  /**< [ 22: 22](RO) B2/B3 support, hardwired to 0. */
        uint32_t bpccee                : 1;  /**< [ 23: 23](RO) Bus power/clock control enable, hardwired to 0. */
        uint32_t pmdia                 : 8;  /**< [ 31: 24](RO) Data register for additional information (not supported). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg017_s cn; */
} bdk_pcieepx_cfg017_t;

static inline uint64_t BDK_PCIEEPX_CFG017(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG017(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000044ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG017", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG017(a) bdk_pcieepx_cfg017_t
#define bustype_BDK_PCIEEPX_CFG017(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG017(a) "PCIEEPX_CFG017"
#define busnum_BDK_PCIEEPX_CFG017(a) (a)
#define arguments_BDK_PCIEEPX_CFG017(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg020
 *
 * MSI Capability ID/MSI Next Item Pointer/MSI Control Register
 * This register contains the twenty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg020_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_25_31        : 7;
        uint32_t pvm                   : 1;  /**< [ 24: 24](RO) Per-vector masking capable. */
        uint32_t m64                   : 1;  /**< [ 23: 23](RO/WRSL) 64-bit address capable, writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field. */
        uint32_t mme                   : 3;  /**< [ 22: 20](R/W) Multiple message enabled. Indicates that multiple message mode is enabled by system
                                                                 software. The number of messages enabled must be less than or equal to the multiple
                                                                 message capable (MMC) value. */
        uint32_t mmc                   : 3;  /**< [ 19: 17](RO/WRSL) Multiple message capable, writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field. */
        uint32_t msien                 : 1;  /**< [ 16: 16](R/W) MSI enabled. When set, INTx must be disabled. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO/WRSL) Next capability pointer. Points to PCI Express capabilities by default, writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t msicid                : 8;  /**< [  7:  0](RO) MSI capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t msicid                : 8;  /**< [  7:  0](RO) MSI capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO/WRSL) Next capability pointer. Points to PCI Express capabilities by default, writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t msien                 : 1;  /**< [ 16: 16](R/W) MSI enabled. When set, INTx must be disabled. */
        uint32_t mmc                   : 3;  /**< [ 19: 17](RO/WRSL) Multiple message capable, writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field. */
        uint32_t mme                   : 3;  /**< [ 22: 20](R/W) Multiple message enabled. Indicates that multiple message mode is enabled by system
                                                                 software. The number of messages enabled must be less than or equal to the multiple
                                                                 message capable (MMC) value. */
        uint32_t m64                   : 1;  /**< [ 23: 23](RO/WRSL) 64-bit address capable, writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field. */
        uint32_t pvm                   : 1;  /**< [ 24: 24](RO) Per-vector masking capable. */
        uint32_t reserved_25_31        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg020_s cn; */
} bdk_pcieepx_cfg020_t;

static inline uint64_t BDK_PCIEEPX_CFG020(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG020(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000050ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG020", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG020(a) bdk_pcieepx_cfg020_t
#define bustype_BDK_PCIEEPX_CFG020(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG020(a) "PCIEEPX_CFG020"
#define busnum_BDK_PCIEEPX_CFG020(a) (a)
#define arguments_BDK_PCIEEPX_CFG020(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg021
 *
 * MSI Lower 32 Bits Address Register
 * This register contains the twenty-second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg021_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lmsi                  : 30; /**< [ 31:  2](R/W) Lower 32-bit address. */
        uint32_t reserved_0_1          : 2;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_1          : 2;
        uint32_t lmsi                  : 30; /**< [ 31:  2](R/W) Lower 32-bit address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg021_s cn; */
} bdk_pcieepx_cfg021_t;

static inline uint64_t BDK_PCIEEPX_CFG021(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG021(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000054ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG021", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG021(a) bdk_pcieepx_cfg021_t
#define bustype_BDK_PCIEEPX_CFG021(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG021(a) "PCIEEPX_CFG021"
#define busnum_BDK_PCIEEPX_CFG021(a) (a)
#define arguments_BDK_PCIEEPX_CFG021(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg022
 *
 * MSI Upper 32 Bits Address Register
 * This register contains the twenty-third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg022_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t umsi                  : 32; /**< [ 31:  0](R/W) Upper 32-bit address. */
#else /* Word 0 - Little Endian */
        uint32_t umsi                  : 32; /**< [ 31:  0](R/W) Upper 32-bit address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg022_s cn; */
} bdk_pcieepx_cfg022_t;

static inline uint64_t BDK_PCIEEPX_CFG022(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG022(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000058ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG022", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG022(a) bdk_pcieepx_cfg022_t
#define bustype_BDK_PCIEEPX_CFG022(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG022(a) "PCIEEPX_CFG022"
#define busnum_BDK_PCIEEPX_CFG022(a) (a)
#define arguments_BDK_PCIEEPX_CFG022(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg023
 *
 * MSI Data Register
 * This register contains the twenty-fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg023_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t msimd                 : 16; /**< [ 15:  0](R/W) MSI data. Pattern assigned by system software. Bits [4:0] are ORed with MSI_VECTOR to
                                                                 generate 32 MSI messages per function. */
#else /* Word 0 - Little Endian */
        uint32_t msimd                 : 16; /**< [ 15:  0](R/W) MSI data. Pattern assigned by system software. Bits [4:0] are ORed with MSI_VECTOR to
                                                                 generate 32 MSI messages per function. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg023_s cn; */
} bdk_pcieepx_cfg023_t;

static inline uint64_t BDK_PCIEEPX_CFG023(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG023(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000005cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG023", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG023(a) bdk_pcieepx_cfg023_t
#define bustype_BDK_PCIEEPX_CFG023(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG023(a) "PCIEEPX_CFG023"
#define busnum_BDK_PCIEEPX_CFG023(a) (a)
#define arguments_BDK_PCIEEPX_CFG023(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg024
 *
 * MSI Mask Bits Register
 * This register contains the twenty-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg024_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msimm                 : 32; /**< [ 31:  0](R/W) MSI mask bits. For each mask bit that is set, the function is prohibited from sending the
                                                                 associated message. */
#else /* Word 0 - Little Endian */
        uint32_t msimm                 : 32; /**< [ 31:  0](R/W) MSI mask bits. For each mask bit that is set, the function is prohibited from sending the
                                                                 associated message. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg024_s cn; */
} bdk_pcieepx_cfg024_t;

static inline uint64_t BDK_PCIEEPX_CFG024(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG024(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000060ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG024", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG024(a) bdk_pcieepx_cfg024_t
#define bustype_BDK_PCIEEPX_CFG024(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG024(a) "PCIEEPX_CFG024"
#define busnum_BDK_PCIEEPX_CFG024(a) (a)
#define arguments_BDK_PCIEEPX_CFG024(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg025
 *
 * MSI Pending Bits Register
 * This register contains the twenty-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg025_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msimp                 : 32; /**< [ 31:  0](RO) MSI pending bits. For each pending bit that is set, the function has a pending associated message. */
#else /* Word 0 - Little Endian */
        uint32_t msimp                 : 32; /**< [ 31:  0](RO) MSI pending bits. For each pending bit that is set, the function has a pending associated message. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg025_s cn; */
} bdk_pcieepx_cfg025_t;

static inline uint64_t BDK_PCIEEPX_CFG025(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG025(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000064ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG025", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG025(a) bdk_pcieepx_cfg025_t
#define bustype_BDK_PCIEEPX_CFG025(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG025(a) "PCIEEPX_CFG025"
#define busnum_BDK_PCIEEPX_CFG025(a) (a)
#define arguments_BDK_PCIEEPX_CFG025(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg028
 *
 * PCIe Capabilities/PCIe Capabilities List Register
 * This register contains the twenty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg028_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_30_31        : 2;
        uint32_t imn                   : 5;  /**< [ 29: 25](RO/WRSL) Interrupt message number. Updated by hardware, writable through PEM()_CFG_WR. However,
                                                                 the application must not change this field. */
        uint32_t si                    : 1;  /**< [ 24: 24](RO/WRSL) Slot implemented. This bit is writable through PEM()_CFG_WR. However, it must be 0 for
                                                                 an endpoint device. Therefore, the application must not write a 1 to this bit. */
        uint32_t dpt                   : 4;  /**< [ 23: 20](RO) Device port type.
                                                                 0000 = PCI Express endpoint.
                                                                 0001 = Legacy PCI Express endpoint.

                                                                 All other encodings are not supported */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCI Express capability version. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO/WRSL) Next capability pointer. Points to the MSI-X Capabilities by default, writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCI Express capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCI Express capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO/WRSL) Next capability pointer. Points to the MSI-X Capabilities by default, writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCI Express capability version. */
        uint32_t dpt                   : 4;  /**< [ 23: 20](RO) Device port type.
                                                                 0000 = PCI Express endpoint.
                                                                 0001 = Legacy PCI Express endpoint.

                                                                 All other encodings are not supported */
        uint32_t si                    : 1;  /**< [ 24: 24](RO/WRSL) Slot implemented. This bit is writable through PEM()_CFG_WR. However, it must be 0 for
                                                                 an endpoint device. Therefore, the application must not write a 1 to this bit. */
        uint32_t imn                   : 5;  /**< [ 29: 25](RO/WRSL) Interrupt message number. Updated by hardware, writable through PEM()_CFG_WR. However,
                                                                 the application must not change this field. */
        uint32_t reserved_30_31        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg028_s cn; */
} bdk_pcieepx_cfg028_t;

static inline uint64_t BDK_PCIEEPX_CFG028(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG028(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000070ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG028", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG028(a) bdk_pcieepx_cfg028_t
#define bustype_BDK_PCIEEPX_CFG028(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG028(a) "PCIEEPX_CFG028"
#define busnum_BDK_PCIEEPX_CFG028(a) (a)
#define arguments_BDK_PCIEEPX_CFG028(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg029
 *
 * Device Capabilities Register
 * This register contains the thirtieth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg029_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_29_31        : 3;
        uint32_t flr_cap               : 1;  /**< [ 28: 28](RO) Function level reset capability. Set to 1 for SR-IOV core. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO) Captured slot power limit scale. From message from RC, upstream port only. */
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO) Captured slot power limit value. From message from RC, upstream port only. */
        uint32_t reserved_16_17        : 2;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO/WRSL) Role-based error reporting, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t reserved_12_14        : 3;
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO/WRSL) Endpoint L1 acceptable latency, writable through PEM()_CFG_WR. However, the
                                                                 application must not change this field. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO/WRSL) Endpoint L0s acceptable latency, writable through PEM()_CFG_WR. However, the
                                                                 application must not change this field. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO/WRSL) Extended tag field supported. This bit is writable through
                                                                 PEM()_CFG_WR. However, the application must not write a 1 to this bit. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO/WRSL) Phantom function supported. This field is writable through
                                                                 PEM()_CFG_WR. However, phantom function is not supported. Therefore, the application
                                                                 must not write any value other than 0x0 to this field. */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO/WRSL) Max_Payload_Size supported, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO/WRSL) Max_Payload_Size supported, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO/WRSL) Phantom function supported. This field is writable through
                                                                 PEM()_CFG_WR. However, phantom function is not supported. Therefore, the application
                                                                 must not write any value other than 0x0 to this field. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO/WRSL) Extended tag field supported. This bit is writable through
                                                                 PEM()_CFG_WR. However, the application must not write a 1 to this bit. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO/WRSL) Endpoint L0s acceptable latency, writable through PEM()_CFG_WR. However, the
                                                                 application must not change this field. */
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO/WRSL) Endpoint L1 acceptable latency, writable through PEM()_CFG_WR. However, the
                                                                 application must not change this field. */
        uint32_t reserved_12_14        : 3;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO/WRSL) Role-based error reporting, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t reserved_16_17        : 2;
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO) Captured slot power limit value. From message from RC, upstream port only. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO) Captured slot power limit scale. From message from RC, upstream port only. */
        uint32_t flr_cap               : 1;  /**< [ 28: 28](RO) Function level reset capability. Set to 1 for SR-IOV core. */
        uint32_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } s;
    struct bdk_pcieepx_cfg029_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_29_31        : 3;
        uint32_t flr_cap               : 1;  /**< [ 28: 28](RO) Function level reset capability. Set to 1 for SR-IOV core. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO) Captured slot power limit scale. From message from RC, upstream port only. */
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO) Captured slot power limit value. From message from RC, upstream port only. */
        uint32_t reserved_16_17        : 2;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO/WRSL) Role-based error reporting, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t reserved_14           : 1;
        uint32_t reserved_13           : 1;
        uint32_t reserved_12           : 1;
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO/WRSL) Endpoint L1 acceptable latency, writable through PEM()_CFG_WR. However, the
                                                                 application must not change this field. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO/WRSL) Endpoint L0s acceptable latency, writable through PEM()_CFG_WR. However, the
                                                                 application must not change this field. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO/WRSL) Extended tag field supported. This bit is writable through
                                                                 PEM()_CFG_WR. However, the application must not write a 1 to this bit. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO/WRSL) Phantom function supported. This field is writable through
                                                                 PEM()_CFG_WR. However, phantom function is not supported. Therefore, the application
                                                                 must not write any value other than 0x0 to this field. */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO/WRSL) Max_Payload_Size supported, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t mpss                  : 3;  /**< [  2:  0](RO/WRSL) Max_Payload_Size supported, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t pfs                   : 2;  /**< [  4:  3](RO/WRSL) Phantom function supported. This field is writable through
                                                                 PEM()_CFG_WR. However, phantom function is not supported. Therefore, the application
                                                                 must not write any value other than 0x0 to this field. */
        uint32_t etfs                  : 1;  /**< [  5:  5](RO/WRSL) Extended tag field supported. This bit is writable through
                                                                 PEM()_CFG_WR. However, the application must not write a 1 to this bit. */
        uint32_t el0al                 : 3;  /**< [  8:  6](RO/WRSL) Endpoint L0s acceptable latency, writable through PEM()_CFG_WR. However, the
                                                                 application must not change this field. */
        uint32_t el1al                 : 3;  /**< [ 11:  9](RO/WRSL) Endpoint L1 acceptable latency, writable through PEM()_CFG_WR. However, the
                                                                 application must not change this field. */
        uint32_t reserved_12           : 1;
        uint32_t reserved_13           : 1;
        uint32_t reserved_14           : 1;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO/WRSL) Role-based error reporting, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t reserved_16_17        : 2;
        uint32_t csplv                 : 8;  /**< [ 25: 18](RO) Captured slot power limit value. From message from RC, upstream port only. */
        uint32_t cspls                 : 2;  /**< [ 27: 26](RO) Captured slot power limit scale. From message from RC, upstream port only. */
        uint32_t flr_cap               : 1;  /**< [ 28: 28](RO) Function level reset capability. Set to 1 for SR-IOV core. */
        uint32_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } cn;
} bdk_pcieepx_cfg029_t;

static inline uint64_t BDK_PCIEEPX_CFG029(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG029(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000074ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG029", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG029(a) bdk_pcieepx_cfg029_t
#define bustype_BDK_PCIEEPX_CFG029(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG029(a) "PCIEEPX_CFG029"
#define busnum_BDK_PCIEEPX_CFG029(a) (a)
#define arguments_BDK_PCIEEPX_CFG029(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg030
 *
 * Device Control/Device Status Register
 * This register contains the thirty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg030_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_22_31        : 10;
        uint32_t tp                    : 1;  /**< [ 21: 21](RO/H) Transaction pending. Set to 1 when nonposted requests are not yet completed and set to 0
                                                                 when they are completed. */
        uint32_t ap_d                  : 1;  /**< [ 20: 20](RO) Aux power detected. Set to 1 if Aux power detected. */
        uint32_t ur_d                  : 1;  /**< [ 19: 19](R/W1C/H) Unsupported request detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. UR_D occurs when we receive
                                                                 something unsupported. Unsupported requests are nonfatal errors, so UR_D should cause
                                                                 NFE_D. Receiving a vendor-defined message should cause an unsupported request. */
        uint32_t fe_d                  : 1;  /**< [ 18: 18](R/W1C/H) Fatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in PCIEEP()_CFG066 that has a severity set to fatal. Malformed TLPs
                                                                 generally fit into this category. */
        uint32_t nfe_d                 : 1;  /**< [ 17: 17](R/W1C/H) Nonfatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in PCIEEP()_CFG066 that has a severity set to nonfatal and does not
                                                                 meet advisory nonfatal criteria, which most poisoned TLPs should. */
        uint32_t ce_d                  : 1;  /**< [ 16: 16](R/W1C/H) Correctable error detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. This field is set if we
                                                                 receive any of the errors in PCIEEP()_CFG068, for example a replay-timer timeout.
                                                                 Also, it can be set if we get any of the errors in PCIEEP()_CFG066 that has a severity
                                                                 set to Nonfatal and meets the Advisory Nonfatal criteria, which most ECRC errors should. */
        uint32_t i_flr                 : 1;  /**< [ 15: 15](R/W) Initiate function level reset. */
        uint32_t mrrs                  : 3;  /**< [ 14: 12](R/W) Max read request size.
                                                                 0x0 =128 bytes.
                                                                 0x1 = 256 bytes.
                                                                 0x2 = 512 bytes.
                                                                 0x3 = 1024 bytes.
                                                                 0x4 = 2048 bytes.
                                                                 0x5 = 4096 bytes.

                                                                 SLI_S2M_PORT()_CTL[MRRS] and DPI_SLI_PRT()_CFG[MRRS] must also be set properly.
                                                                 SLI_S2M_PORT()_CTL[MRRS] and DPI_SLI_PRT()_CFG[MRRS] must not exceed the desired
                                                                 max read request size. */
        uint32_t ns_en                 : 1;  /**< [ 11: 11](R/W) Enable no snoop. */
        uint32_t ap_en                 : 1;  /**< [ 10: 10](RO) AUX power PM enable (not suppported). */
        uint32_t pf_en                 : 1;  /**< [  9:  9](R/W) Phantom function enable. This bit should never be set; PEM requests never use phantom functions. */
        uint32_t etf_en                : 1;  /**< [  8:  8](R/W) Extended tag field enable. */
        uint32_t mps                   : 3;  /**< [  7:  5](R/W) Max payload size. Legal values: 0x0 = 128 B, 0x1 = 256 B.
                                                                 Larger sizes are not supported by CNXXXX.
                                                                 DPI_SLI_PRT()_CFG[MPS] must be set to the same value as this field for proper
                                                                 functionality. */
        uint32_t ro_en                 : 1;  /**< [  4:  4](R/W) Enable relaxed ordering. */
        uint32_t ur_en                 : 1;  /**< [  3:  3](R/W) Unsupported request reporting enable. */
        uint32_t fe_en                 : 1;  /**< [  2:  2](R/W) Fatal error reporting enable. */
        uint32_t nfe_en                : 1;  /**< [  1:  1](R/W) Nonfatal error reporting enable. */
        uint32_t ce_en                 : 1;  /**< [  0:  0](R/W) Correctable error reporting enable. */
#else /* Word 0 - Little Endian */
        uint32_t ce_en                 : 1;  /**< [  0:  0](R/W) Correctable error reporting enable. */
        uint32_t nfe_en                : 1;  /**< [  1:  1](R/W) Nonfatal error reporting enable. */
        uint32_t fe_en                 : 1;  /**< [  2:  2](R/W) Fatal error reporting enable. */
        uint32_t ur_en                 : 1;  /**< [  3:  3](R/W) Unsupported request reporting enable. */
        uint32_t ro_en                 : 1;  /**< [  4:  4](R/W) Enable relaxed ordering. */
        uint32_t mps                   : 3;  /**< [  7:  5](R/W) Max payload size. Legal values: 0x0 = 128 B, 0x1 = 256 B.
                                                                 Larger sizes are not supported by CNXXXX.
                                                                 DPI_SLI_PRT()_CFG[MPS] must be set to the same value as this field for proper
                                                                 functionality. */
        uint32_t etf_en                : 1;  /**< [  8:  8](R/W) Extended tag field enable. */
        uint32_t pf_en                 : 1;  /**< [  9:  9](R/W) Phantom function enable. This bit should never be set; PEM requests never use phantom functions. */
        uint32_t ap_en                 : 1;  /**< [ 10: 10](RO) AUX power PM enable (not suppported). */
        uint32_t ns_en                 : 1;  /**< [ 11: 11](R/W) Enable no snoop. */
        uint32_t mrrs                  : 3;  /**< [ 14: 12](R/W) Max read request size.
                                                                 0x0 =128 bytes.
                                                                 0x1 = 256 bytes.
                                                                 0x2 = 512 bytes.
                                                                 0x3 = 1024 bytes.
                                                                 0x4 = 2048 bytes.
                                                                 0x5 = 4096 bytes.

                                                                 SLI_S2M_PORT()_CTL[MRRS] and DPI_SLI_PRT()_CFG[MRRS] must also be set properly.
                                                                 SLI_S2M_PORT()_CTL[MRRS] and DPI_SLI_PRT()_CFG[MRRS] must not exceed the desired
                                                                 max read request size. */
        uint32_t i_flr                 : 1;  /**< [ 15: 15](R/W) Initiate function level reset. */
        uint32_t ce_d                  : 1;  /**< [ 16: 16](R/W1C/H) Correctable error detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. This field is set if we
                                                                 receive any of the errors in PCIEEP()_CFG068, for example a replay-timer timeout.
                                                                 Also, it can be set if we get any of the errors in PCIEEP()_CFG066 that has a severity
                                                                 set to Nonfatal and meets the Advisory Nonfatal criteria, which most ECRC errors should. */
        uint32_t nfe_d                 : 1;  /**< [ 17: 17](R/W1C/H) Nonfatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in PCIEEP()_CFG066 that has a severity set to nonfatal and does not
                                                                 meet advisory nonfatal criteria, which most poisoned TLPs should. */
        uint32_t fe_d                  : 1;  /**< [ 18: 18](R/W1C/H) Fatal error detected. Errors are logged in this register regardless of whether or not
                                                                 error reporting is enabled in the device control register. This field is set if we receive
                                                                 any of the errors in PCIEEP()_CFG066 that has a severity set to fatal. Malformed TLPs
                                                                 generally fit into this category. */
        uint32_t ur_d                  : 1;  /**< [ 19: 19](R/W1C/H) Unsupported request detected. Errors are logged in this register regardless of whether or
                                                                 not error reporting is enabled in the device control register. UR_D occurs when we receive
                                                                 something unsupported. Unsupported requests are nonfatal errors, so UR_D should cause
                                                                 NFE_D. Receiving a vendor-defined message should cause an unsupported request. */
        uint32_t ap_d                  : 1;  /**< [ 20: 20](RO) Aux power detected. Set to 1 if Aux power detected. */
        uint32_t tp                    : 1;  /**< [ 21: 21](RO/H) Transaction pending. Set to 1 when nonposted requests are not yet completed and set to 0
                                                                 when they are completed. */
        uint32_t reserved_22_31        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg030_s cn; */
} bdk_pcieepx_cfg030_t;

static inline uint64_t BDK_PCIEEPX_CFG030(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG030(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000078ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG030", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG030(a) bdk_pcieepx_cfg030_t
#define bustype_BDK_PCIEEPX_CFG030(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG030(a) "PCIEEPX_CFG030"
#define busnum_BDK_PCIEEPX_CFG030(a) (a)
#define arguments_BDK_PCIEEPX_CFG030(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg031
 *
 * Link Capabilities Register
 * This register contains the thirty-second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg031_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t pnum                  : 8;  /**< [ 31: 24](RO/WRSL) Port number, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t reserved_23           : 1;
        uint32_t aspm                  : 1;  /**< [ 22: 22](RO/WRSL) ASPM optionality compliance. */
        uint32_t lbnc                  : 1;  /**< [ 21: 21](RO) Link bandwidth notification capability. Set to 0 for endpoint devices. */
        uint32_t dllarc                : 1;  /**< [ 20: 20](RO) Data link layer active reporting capable. */
        uint32_t sderc                 : 1;  /**< [ 19: 19](RO) Surprise down error reporting capable. Not supported; hardwired to 0. */
        uint32_t cpm                   : 1;  /**< [ 18: 18](RO/WRSL) Clock power management. The default value is the value that software specifies during
                                                                 hardware configuration, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. */
        uint32_t l1el                  : 3;  /**< [ 17: 15](RO/WRSL) L1 exit latency. The default value is the value that software specifies during hardware
                                                                 configuration, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t l0el                  : 3;  /**< [ 14: 12](RO/WRSL) L0s exit latency. The default value is the value that software specifies during hardware
                                                                 configuration, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t aslpms                : 2;  /**< [ 11: 10](RO/WRSL) Active state link PM support. The default value is the value that software specifies
                                                                 during hardware configuration, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t mlw                   : 6;  /**< [  9:  4](RO/WRSL/H) Maximum link width.
                                                                 The reset value of this field is determined by the value read from the PEM
                                                                 csr PEM()_CFG[LANES8] and PEM()_QLM[PEMDLMSEL]. If PEMDLMSEL is set, the reset
                                                                 value is 0x2.  If PEMDLMSEL is set and LANES8 is set the reset value is 0x4, otherwise
                                                                 0x8.

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
        uint32_t mlw                   : 6;  /**< [  9:  4](RO/WRSL/H) Maximum link width.
                                                                 The reset value of this field is determined by the value read from the PEM
                                                                 csr PEM()_CFG[LANES8] and PEM()_QLM[PEMDLMSEL]. If PEMDLMSEL is set, the reset
                                                                 value is 0x2.  If PEMDLMSEL is set and LANES8 is set the reset value is 0x4, otherwise
                                                                 0x8.

                                                                 This field is writable through PEM()_CFG_WR. */
        uint32_t aslpms                : 2;  /**< [ 11: 10](RO/WRSL) Active state link PM support. The default value is the value that software specifies
                                                                 during hardware configuration, writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t l0el                  : 3;  /**< [ 14: 12](RO/WRSL) L0s exit latency. The default value is the value that software specifies during hardware
                                                                 configuration, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t l1el                  : 3;  /**< [ 17: 15](RO/WRSL) L1 exit latency. The default value is the value that software specifies during hardware
                                                                 configuration, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
        uint32_t cpm                   : 1;  /**< [ 18: 18](RO/WRSL) Clock power management. The default value is the value that software specifies during
                                                                 hardware configuration, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. */
        uint32_t sderc                 : 1;  /**< [ 19: 19](RO) Surprise down error reporting capable. Not supported; hardwired to 0. */
        uint32_t dllarc                : 1;  /**< [ 20: 20](RO) Data link layer active reporting capable. */
        uint32_t lbnc                  : 1;  /**< [ 21: 21](RO) Link bandwidth notification capability. Set to 0 for endpoint devices. */
        uint32_t aspm                  : 1;  /**< [ 22: 22](RO/WRSL) ASPM optionality compliance. */
        uint32_t reserved_23           : 1;
        uint32_t pnum                  : 8;  /**< [ 31: 24](RO/WRSL) Port number, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg031_s cn; */
} bdk_pcieepx_cfg031_t;

static inline uint64_t BDK_PCIEEPX_CFG031(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG031(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000007cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG031", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG031(a) bdk_pcieepx_cfg031_t
#define bustype_BDK_PCIEEPX_CFG031(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG031(a) "PCIEEPX_CFG031"
#define busnum_BDK_PCIEEPX_CFG031(a) (a)
#define arguments_BDK_PCIEEPX_CFG031(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg032
 *
 * Link Control/Link Status Register
 * This register contains the thirty-third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg032_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lab                   : 1;  /**< [ 31: 31](RO/H) Link autonomous bandwidth status. */
        uint32_t lbm                   : 1;  /**< [ 30: 30](RO/H) Link bandwidth management status. */
        uint32_t dlla                  : 1;  /**< [ 29: 29](RO) Data link layer active. Not applicable for an upstream port or endpoint device, hardwired to 0. */
        uint32_t scc                   : 1;  /**< [ 28: 28](RO/WRSL) Slot clock configuration. Indicates that the component uses the same physical reference
                                                                 clock that the platform provides on the connector. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t lt                    : 1;  /**< [ 27: 27](RO) Link training. Not applicable for an upstream port or endpoint device, hardwired to 0. */
        uint32_t reserved_26           : 1;
        uint32_t nlw                   : 6;  /**< [ 25: 20](RO/H) Negotiated link width. Set automatically by hardware after link initialization. Value is
                                                                 undefined when link is not up. */
        uint32_t ls                    : 4;  /**< [ 19: 16](RO/H) Current link speed. The encoded value specifies a bit location in the supported link
                                                                 speeds vector (in the link capabilities 2 register) that corresponds to the current link
                                                                 speed.
                                                                 0x1 = Supported link speeds vector field bit 0.
                                                                 0x2 = Supported link speeds vector field bit 1.
                                                                 0x3 = Supported link speeds vector field bit 2. */
        uint32_t reserved_12_15        : 4;
        uint32_t lab_int_enb           : 1;  /**< [ 11: 11](RO) Link autonomous bandwidth interrupt enable. This bit is not applicable and is reserved for
                                                                 endpoints. */
        uint32_t lbm_int_enb           : 1;  /**< [ 10: 10](RO) Link bandwidth management interrupt enable. This bit is not applicable and is reserved for
                                                                 endpoints. */
        uint32_t hawd                  : 1;  /**< [  9:  9](RO) Hardware autonomous width disable (not supported). */
        uint32_t ecpm                  : 1;  /**< [  8:  8](R/W) Enable clock power management. Hardwired to 0 if clock power management is disabled in the
                                                                 link capabilities register. */
        uint32_t es                    : 1;  /**< [  7:  7](R/W) Extended synch. */
        uint32_t ccc                   : 1;  /**< [  6:  6](R/W) Common clock configuration. */
        uint32_t rl                    : 1;  /**< [  5:  5](RO) Retrain link. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t ld                    : 1;  /**< [  4:  4](RO) Link disable. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t rcb                   : 1;  /**< [  3:  3](RO) Read completion boundary (RCB). */
        uint32_t reserved_2            : 1;
        uint32_t aslpc                 : 2;  /**< [  1:  0](R/W) Active state link PM control. */
#else /* Word 0 - Little Endian */
        uint32_t aslpc                 : 2;  /**< [  1:  0](R/W) Active state link PM control. */
        uint32_t reserved_2            : 1;
        uint32_t rcb                   : 1;  /**< [  3:  3](RO) Read completion boundary (RCB). */
        uint32_t ld                    : 1;  /**< [  4:  4](RO) Link disable. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t rl                    : 1;  /**< [  5:  5](RO) Retrain link. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t ccc                   : 1;  /**< [  6:  6](R/W) Common clock configuration. */
        uint32_t es                    : 1;  /**< [  7:  7](R/W) Extended synch. */
        uint32_t ecpm                  : 1;  /**< [  8:  8](R/W) Enable clock power management. Hardwired to 0 if clock power management is disabled in the
                                                                 link capabilities register. */
        uint32_t hawd                  : 1;  /**< [  9:  9](RO) Hardware autonomous width disable (not supported). */
        uint32_t lbm_int_enb           : 1;  /**< [ 10: 10](RO) Link bandwidth management interrupt enable. This bit is not applicable and is reserved for
                                                                 endpoints. */
        uint32_t lab_int_enb           : 1;  /**< [ 11: 11](RO) Link autonomous bandwidth interrupt enable. This bit is not applicable and is reserved for
                                                                 endpoints. */
        uint32_t reserved_12_15        : 4;
        uint32_t ls                    : 4;  /**< [ 19: 16](RO/H) Current link speed. The encoded value specifies a bit location in the supported link
                                                                 speeds vector (in the link capabilities 2 register) that corresponds to the current link
                                                                 speed.
                                                                 0x1 = Supported link speeds vector field bit 0.
                                                                 0x2 = Supported link speeds vector field bit 1.
                                                                 0x3 = Supported link speeds vector field bit 2. */
        uint32_t nlw                   : 6;  /**< [ 25: 20](RO/H) Negotiated link width. Set automatically by hardware after link initialization. Value is
                                                                 undefined when link is not up. */
        uint32_t reserved_26           : 1;
        uint32_t lt                    : 1;  /**< [ 27: 27](RO) Link training. Not applicable for an upstream port or endpoint device, hardwired to 0. */
        uint32_t scc                   : 1;  /**< [ 28: 28](RO/WRSL) Slot clock configuration. Indicates that the component uses the same physical reference
                                                                 clock that the platform provides on the connector. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t dlla                  : 1;  /**< [ 29: 29](RO) Data link layer active. Not applicable for an upstream port or endpoint device, hardwired to 0. */
        uint32_t lbm                   : 1;  /**< [ 30: 30](RO/H) Link bandwidth management status. */
        uint32_t lab                   : 1;  /**< [ 31: 31](RO/H) Link autonomous bandwidth status. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg032_s cn; */
} bdk_pcieepx_cfg032_t;

static inline uint64_t BDK_PCIEEPX_CFG032(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG032(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000080ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG032", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG032(a) bdk_pcieepx_cfg032_t
#define bustype_BDK_PCIEEPX_CFG032(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG032(a) "PCIEEPX_CFG032"
#define busnum_BDK_PCIEEPX_CFG032(a) (a)
#define arguments_BDK_PCIEEPX_CFG032(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg037
 *
 * Device Capabilities 2 Register
 * This register contains the thirty-eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg037_s
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
        uint32_t atom64s               : 1;  /**< [  8:  8](RO) 64-bit AtomicOp supported.

                                                                 _ PF0:          0x1
                                                                 _ PF1:          0x1
                                                                 _ PF2:          0x0

                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request. */
        uint32_t atom32s               : 1;  /**< [  7:  7](RO) 32-bit AtomicOp supported.

                                                                 _ PF0:          0x1
                                                                 _ PF1:          0x1
                                                                 _ PF2:          0x0

                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request. */
        uint32_t atom_ops              : 1;  /**< [  6:  6](RO) AtomicOp routing supported (not applicable for EP). */
        uint32_t ari                   : 1;  /**< [  5:  5](RO) Alternate routing ID forwarding supported (not applicable for EP). */
        uint32_t ctds                  : 1;  /**< [  4:  4](RO) Completion timeout disable supported. */
        uint32_t ctrs                  : 4;  /**< [  3:  0](RO) Completion timeout ranges supported. */
#else /* Word 0 - Little Endian */
        uint32_t ctrs                  : 4;  /**< [  3:  0](RO) Completion timeout ranges supported. */
        uint32_t ctds                  : 1;  /**< [  4:  4](RO) Completion timeout disable supported. */
        uint32_t ari                   : 1;  /**< [  5:  5](RO) Alternate routing ID forwarding supported (not applicable for EP). */
        uint32_t atom_ops              : 1;  /**< [  6:  6](RO) AtomicOp routing supported (not applicable for EP). */
        uint32_t atom32s               : 1;  /**< [  7:  7](RO) 32-bit AtomicOp supported.

                                                                 _ PF0:          0x1
                                                                 _ PF1:          0x1
                                                                 _ PF2:          0x0

                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request. */
        uint32_t atom64s               : 1;  /**< [  8:  8](RO) 64-bit AtomicOp supported.

                                                                 _ PF0:          0x1
                                                                 _ PF1:          0x1
                                                                 _ PF2:          0x0

                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request. */
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
    /* struct bdk_pcieepx_cfg037_s cn; */
} bdk_pcieepx_cfg037_t;

static inline uint64_t BDK_PCIEEPX_CFG037(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG037(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000094ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG037", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG037(a) bdk_pcieepx_cfg037_t
#define bustype_BDK_PCIEEPX_CFG037(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG037(a) "PCIEEPX_CFG037"
#define busnum_BDK_PCIEEPX_CFG037(a) (a)
#define arguments_BDK_PCIEEPX_CFG037(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg038
 *
 * Device Control 2 Register/Device Status 2 Register
 * This register contains the thirty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg038_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t eetpb                 : 1;  /**< [ 15: 15](RO) Unsupported end-end TLP prefix blocking. */
        uint32_t obffe                 : 2;  /**< [ 14: 13](RO) Optimized buffer flush fill (OBFF) enable (not supported). */
        uint32_t reserved_11_12        : 2;
        uint32_t ltre                  : 1;  /**< [ 10: 10](RO) Latency tolerance reporting (LTR) mechanism enable (not supported). */
        uint32_t id0_cp                : 1;  /**< [  9:  9](RO) ID based ordering completion enable (not supported). */
        uint32_t id0_rq                : 1;  /**< [  8:  8](RO) ID based ordering request enable (not supported). */
        uint32_t atom_op_eb            : 1;  /**< [  7:  7](R/W) AtomicOp egress blocking. */
        uint32_t atom_op               : 1;  /**< [  6:  6](R/W) AtomicOp requester enable. */
        uint32_t ari                   : 1;  /**< [  5:  5](RO) Alternate routing ID forwarding supported. */
        uint32_t ctd                   : 1;  /**< [  4:  4](R/W) Completion timeout disable. */
        uint32_t ctv                   : 4;  /**< [  3:  0](RO) Completion timeout value. Completion timeout programming is not supported. Completion
                                                                 timeout is the range of 16 ms to 55 ms. */
#else /* Word 0 - Little Endian */
        uint32_t ctv                   : 4;  /**< [  3:  0](RO) Completion timeout value. Completion timeout programming is not supported. Completion
                                                                 timeout is the range of 16 ms to 55 ms. */
        uint32_t ctd                   : 1;  /**< [  4:  4](R/W) Completion timeout disable. */
        uint32_t ari                   : 1;  /**< [  5:  5](RO) Alternate routing ID forwarding supported. */
        uint32_t atom_op               : 1;  /**< [  6:  6](R/W) AtomicOp requester enable. */
        uint32_t atom_op_eb            : 1;  /**< [  7:  7](R/W) AtomicOp egress blocking. */
        uint32_t id0_rq                : 1;  /**< [  8:  8](RO) ID based ordering request enable (not supported). */
        uint32_t id0_cp                : 1;  /**< [  9:  9](RO) ID based ordering completion enable (not supported). */
        uint32_t ltre                  : 1;  /**< [ 10: 10](RO) Latency tolerance reporting (LTR) mechanism enable (not supported). */
        uint32_t reserved_11_12        : 2;
        uint32_t obffe                 : 2;  /**< [ 14: 13](RO) Optimized buffer flush fill (OBFF) enable (not supported). */
        uint32_t eetpb                 : 1;  /**< [ 15: 15](RO) Unsupported end-end TLP prefix blocking. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg038_s cn; */
} bdk_pcieepx_cfg038_t;

static inline uint64_t BDK_PCIEEPX_CFG038(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG038(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000098ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG038", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG038(a) bdk_pcieepx_cfg038_t
#define bustype_BDK_PCIEEPX_CFG038(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG038(a) "PCIEEPX_CFG038"
#define busnum_BDK_PCIEEPX_CFG038(a) (a)
#define arguments_BDK_PCIEEPX_CFG038(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg039
 *
 * Link Capabilities 2 Register
 * This register contains the fortieth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg039_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t cls                   : 1;  /**< [  8:  8](RO) Crosslink supported. */
        uint32_t slsv                  : 7;  /**< [  7:  1](RO/WRSL) Supported link speeds vector. Indicates the supported link speeds of the associated port.
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
        uint32_t slsv                  : 7;  /**< [  7:  1](RO/WRSL) Supported link speeds vector. Indicates the supported link speeds of the associated port.
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
    /* struct bdk_pcieepx_cfg039_s cn; */
} bdk_pcieepx_cfg039_t;

static inline uint64_t BDK_PCIEEPX_CFG039(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG039(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000009cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG039", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG039(a) bdk_pcieepx_cfg039_t
#define bustype_BDK_PCIEEPX_CFG039(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG039(a) "PCIEEPX_CFG039"
#define busnum_BDK_PCIEEPX_CFG039(a) (a)
#define arguments_BDK_PCIEEPX_CFG039(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg040
 *
 * Link Control 2 Register/Link Status 2 Register
 * This register contains the forty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg040_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_22_31        : 10;
        uint32_t ler                   : 1;  /**< [ 21: 21](R/W1C) Link equalization request */
        uint32_t ep3s                  : 1;  /**< [ 20: 20](RO/H) Equalization phase 3 successful */
        uint32_t ep2s                  : 1;  /**< [ 19: 19](RO/H) Equalization phase 2 successful */
        uint32_t ep1s                  : 1;  /**< [ 18: 18](RO/H) Equalization phase 1 successful */
        uint32_t eqc                   : 1;  /**< [ 17: 17](RO/H) Equalization complete */
        uint32_t cdl                   : 1;  /**< [ 16: 16](RO/H) Current deemphasis level. When the link is operating at 5 GT/s speed, this bit reflects
                                                                 the level of deemphasis. Encodings:
                                                                 1 = -3.5 dB.
                                                                 0 = -6 dB.

                                                                 The value in this bit is undefined when the link is operating at 2.5 GT/s speed. */
        uint32_t cde                   : 4;  /**< [ 15: 12](R/W) Compliance deemphasis. This bit sets the deemphasis level in polling. Compliance state if
                                                                 the entry occurred due to the Tx compliance receive bit being 1. Encodings:
                                                                 1 = -3.5 dB.
                                                                 0 = -6 dB.

                                                                 When the link is operating at 2.5 GT/s, the setting of this bit has no effect. */
        uint32_t csos                  : 1;  /**< [ 11: 11](R/W) Compliance SOS. When set to 1, the LTSSM is required to send SKP ordered sets periodically
                                                                 in between the (modified) compliance patterns.

                                                                 When the link is operating at 2.5 GT/s, the setting of this bit has no effect. */
        uint32_t emc                   : 1;  /**< [ 10: 10](R/W) Enter modified compliance. When this bit is set to 1, the device transmits a modified
                                                                 compliance pattern if the LTSSM enters polling compliance state. */
        uint32_t tm                    : 3;  /**< [  9:  7](R/W/H) Transmit margin. This field controls the value of the non-deemphasized voltage level at
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
        uint32_t ec                    : 1;  /**< [  4:  4](R/W) Enter compliance. Software is permitted to force a link to enter compliance mode at the
                                                                 speed indicated in the target link speed field by setting this bit to 1 in both components
                                                                 on a link and then initiating a hot reset on the link. */
        uint32_t tls                   : 4;  /**< [  3:  0](R/W/H) Target link speed. For downstream ports, this field sets an upper limit on link
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
#else /* Word 0 - Little Endian */
        uint32_t tls                   : 4;  /**< [  3:  0](R/W/H) Target link speed. For downstream ports, this field sets an upper limit on link
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
        uint32_t ec                    : 1;  /**< [  4:  4](R/W) Enter compliance. Software is permitted to force a link to enter compliance mode at the
                                                                 speed indicated in the target link speed field by setting this bit to 1 in both components
                                                                 on a link and then initiating a hot reset on the link. */
        uint32_t hasd                  : 1;  /**< [  5:  5](RO/H) Hardware autonomous speed disable. When asserted, the application must disable hardware
                                                                 from changing the link speed for device-specific reasons other than attempting to correct
                                                                 unreliable link operation by reducing link speed. Initial transition to the highest
                                                                 supported common link speed is not blocked by this signal. */
        uint32_t sde                   : 1;  /**< [  6:  6](RO) Selectable deemphasis. Not applicable for an upstream port or endpoint device. Hardwired to 0. */
        uint32_t tm                    : 3;  /**< [  9:  7](R/W/H) Transmit margin. This field controls the value of the non-deemphasized voltage level at
                                                                 the transmitter pins:
                                                                 0x0 =  800-1200 mV for full swing 400-600 mV for half-swing.
                                                                 0x1-0x2 = Values must be monotonic with a nonzero slope.
                                                                 0x3 = 200-400 mV for full-swing and 100-200 mV for halfswing.
                                                                 0x4-0x7 = Reserved.

                                                                 This field is reset to 0x0 on entry to the LTSSM polling compliance substate. When
                                                                 operating in 5.0 GT/s mode with full swing, the deemphasis ratio must be maintained within
                                                                 +/- 1 dB from the specification-defined operational value either -3.5 or -6 dB. */
        uint32_t emc                   : 1;  /**< [ 10: 10](R/W) Enter modified compliance. When this bit is set to 1, the device transmits a modified
                                                                 compliance pattern if the LTSSM enters polling compliance state. */
        uint32_t csos                  : 1;  /**< [ 11: 11](R/W) Compliance SOS. When set to 1, the LTSSM is required to send SKP ordered sets periodically
                                                                 in between the (modified) compliance patterns.

                                                                 When the link is operating at 2.5 GT/s, the setting of this bit has no effect. */
        uint32_t cde                   : 4;  /**< [ 15: 12](R/W) Compliance deemphasis. This bit sets the deemphasis level in polling. Compliance state if
                                                                 the entry occurred due to the Tx compliance receive bit being 1. Encodings:
                                                                 1 = -3.5 dB.
                                                                 0 = -6 dB.

                                                                 When the link is operating at 2.5 GT/s, the setting of this bit has no effect. */
        uint32_t cdl                   : 1;  /**< [ 16: 16](RO/H) Current deemphasis level. When the link is operating at 5 GT/s speed, this bit reflects
                                                                 the level of deemphasis. Encodings:
                                                                 1 = -3.5 dB.
                                                                 0 = -6 dB.

                                                                 The value in this bit is undefined when the link is operating at 2.5 GT/s speed. */
        uint32_t eqc                   : 1;  /**< [ 17: 17](RO/H) Equalization complete */
        uint32_t ep1s                  : 1;  /**< [ 18: 18](RO/H) Equalization phase 1 successful */
        uint32_t ep2s                  : 1;  /**< [ 19: 19](RO/H) Equalization phase 2 successful */
        uint32_t ep3s                  : 1;  /**< [ 20: 20](RO/H) Equalization phase 3 successful */
        uint32_t ler                   : 1;  /**< [ 21: 21](R/W1C) Link equalization request */
        uint32_t reserved_22_31        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg040_s cn; */
} bdk_pcieepx_cfg040_t;

static inline uint64_t BDK_PCIEEPX_CFG040(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG040(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000000a0ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG040", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG040(a) bdk_pcieepx_cfg040_t
#define bustype_BDK_PCIEEPX_CFG040(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG040(a) "PCIEEPX_CFG040"
#define busnum_BDK_PCIEEPX_CFG040(a) (a)
#define arguments_BDK_PCIEEPX_CFG040(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg044
 *
 * PCI Express MSI-X Capability ID/MSI-X Next Item Pointer/MSI-X Control Register
 * This register contains the forty-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg044_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixen                : 1;  /**< [ 31: 31](R/W) MSI-X enable. If MSI-X is enabled, MSI and INTx must be disabled. */
        uint32_t funm                  : 1;  /**< [ 30: 30](R/W) Function mask.
                                                                 0 = Each vectors mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits. */
        uint32_t reserved_27_29        : 3;
        uint32_t msixts                : 11; /**< [ 26: 16](RO/WRSL) MSI-X table size encoded as (table size - 1).

                                                                 _ PF0:          0x40
                                                                 _ PF1:          0x40
                                                                 _ PF2:          0x10

                                                                 Writable through PEM()_CFG_WR.

                                                                 SPEM_CFG_WR[ADDR[25:24] determines the physical function accessed by the write.
                                                                 0..2 are legal values in EP mode. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X Capability ID */
#else /* Word 0 - Little Endian */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X Capability ID */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer */
        uint32_t msixts                : 11; /**< [ 26: 16](RO/WRSL) MSI-X table size encoded as (table size - 1).

                                                                 _ PF0:          0x40
                                                                 _ PF1:          0x40
                                                                 _ PF2:          0x10

                                                                 Writable through PEM()_CFG_WR.

                                                                 SPEM_CFG_WR[ADDR[25:24] determines the physical function accessed by the write.
                                                                 0..2 are legal values in EP mode. */
        uint32_t reserved_27_29        : 3;
        uint32_t funm                  : 1;  /**< [ 30: 30](R/W) Function mask.
                                                                 0 = Each vectors mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits. */
        uint32_t msixen                : 1;  /**< [ 31: 31](R/W) MSI-X enable. If MSI-X is enabled, MSI and INTx must be disabled. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg044_s cn; */
} bdk_pcieepx_cfg044_t;

static inline uint64_t BDK_PCIEEPX_CFG044(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG044(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000000b0ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG044", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG044(a) bdk_pcieepx_cfg044_t
#define bustype_BDK_PCIEEPX_CFG044(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG044(a) "PCIEEPX_CFG044"
#define busnum_BDK_PCIEEPX_CFG044(a) (a)
#define arguments_BDK_PCIEEPX_CFG044(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg045
 *
 * PCI Express MSI-X Table Offset and BIR Register
 * This register contains the forty-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg045_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixtoffs             : 29; /**< [ 31:  3](RO/WRSL) MSI-X table offset register. Base address of the MSI-X Table, as an offset from the base
                                                                 address of the BAR indicated by the Table BIR bits.
                                                                 _ PF0:          0x0
                                                                 _ PF1:          0x0
                                                                 _ PF2:          0x2000

                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t msixtbir              : 3;  /**< [  2:  0](RO/WRSL) MSI-X table BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 table into memory space.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t msixtbir              : 3;  /**< [  2:  0](RO/WRSL) MSI-X table BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 table into memory space.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t msixtoffs             : 29; /**< [ 31:  3](RO/WRSL) MSI-X table offset register. Base address of the MSI-X Table, as an offset from the base
                                                                 address of the BAR indicated by the Table BIR bits.
                                                                 _ PF0:          0x0
                                                                 _ PF1:          0x0
                                                                 _ PF2:          0x2000

                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg045_s cn; */
} bdk_pcieepx_cfg045_t;

static inline uint64_t BDK_PCIEEPX_CFG045(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG045(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000000b4ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG045", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG045(a) bdk_pcieepx_cfg045_t
#define bustype_BDK_PCIEEPX_CFG045(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG045(a) "PCIEEPX_CFG045"
#define busnum_BDK_PCIEEPX_CFG045(a) (a)
#define arguments_BDK_PCIEEPX_CFG045(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg046
 *
 * PCI Express MSI-X PBA Offset and BIR Register
 * This register contains the forty-seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg046_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixpoffs             : 29; /**< [ 31:  3](RO/WRSL) MSI-X table offset register. Base address of the MSI-X PBA, as an offset from the base
                                                                 address of the BAR indicated by the table PBA bits.

                                                                 _ PF0:          0x200
                                                                 _ PF1:          0x200
                                                                 _ PF2:          0x2040

                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t msixpbir              : 3;  /**< [  2:  0](RO/WRSL) MSI-X PBA BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 pending bit array into memory space.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t msixpbir              : 3;  /**< [  2:  0](RO/WRSL) MSI-X PBA BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 pending bit array into memory space.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t msixpoffs             : 29; /**< [ 31:  3](RO/WRSL) MSI-X table offset register. Base address of the MSI-X PBA, as an offset from the base
                                                                 address of the BAR indicated by the table PBA bits.

                                                                 _ PF0:          0x200
                                                                 _ PF1:          0x200
                                                                 _ PF2:          0x2040

                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg046_s cn; */
} bdk_pcieepx_cfg046_t;

static inline uint64_t BDK_PCIEEPX_CFG046(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG046(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000000b8ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG046", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG046(a) bdk_pcieepx_cfg046_t
#define bustype_BDK_PCIEEPX_CFG046(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG046(a) "PCIEEPX_CFG046"
#define busnum_BDK_PCIEEPX_CFG046(a) (a)
#define arguments_BDK_PCIEEPX_CFG046(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg064
 *
 * PCI Express Extended Capability Header Register
 * This register contains the sixty-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg064_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. Points to the ARI capabilities by default. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCI Express extended capability. */
#else /* Word 0 - Little Endian */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCI Express extended capability. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. Points to the ARI capabilities by default. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg064_s cn; */
} bdk_pcieepx_cfg064_t;

static inline uint64_t BDK_PCIEEPX_CFG064(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG064(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000100ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG064", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG064(a) bdk_pcieepx_cfg064_t
#define bustype_BDK_PCIEEPX_CFG064(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG064(a) "PCIEEPX_CFG064"
#define busnum_BDK_PCIEEPX_CFG064(a) (a)
#define arguments_BDK_PCIEEPX_CFG064(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg065
 *
 * Uncorrectable Error Status Register
 * This register contains the sixty-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg065_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_26_31        : 6;
        uint32_t tpbes                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error status. */
        uint32_t uatombs               : 1;  /**< [ 24: 24](RO) Unsupported AtomicOp egress blocked status. */
        uint32_t reserved_23           : 1;
        uint32_t ucies                 : 1;  /**< [ 22: 22](R/W1C/H) Uncorrectable internal error status. */
        uint32_t reserved_21           : 1;
        uint32_t ures                  : 1;  /**< [ 20: 20](R/W1C/H) Unsupported request error status. */
        uint32_t ecrces                : 1;  /**< [ 19: 19](R/W1C/H) ECRC error status. */
        uint32_t mtlps                 : 1;  /**< [ 18: 18](R/W1C/H) Malformed TLP status. */
        uint32_t ros                   : 1;  /**< [ 17: 17](R/W1C/H) Receiver overflow status. */
        uint32_t ucs                   : 1;  /**< [ 16: 16](R/W1C/H) Unexpected completion status. */
        uint32_t cas                   : 1;  /**< [ 15: 15](R/W1C/H) Completer abort status. */
        uint32_t cts                   : 1;  /**< [ 14: 14](R/W1C/H) Completion timeout status. */
        uint32_t fcpes                 : 1;  /**< [ 13: 13](R/W1C/H) Flow control protocol error status. */
        uint32_t ptlps                 : 1;  /**< [ 12: 12](R/W1C/H) Poisoned TLP status. */
        uint32_t reserved_5_11         : 7;
        uint32_t dlpes                 : 1;  /**< [  4:  4](R/W1C/H) Data link protocol error status. */
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t dlpes                 : 1;  /**< [  4:  4](R/W1C/H) Data link protocol error status. */
        uint32_t reserved_5_11         : 7;
        uint32_t ptlps                 : 1;  /**< [ 12: 12](R/W1C/H) Poisoned TLP status. */
        uint32_t fcpes                 : 1;  /**< [ 13: 13](R/W1C/H) Flow control protocol error status. */
        uint32_t cts                   : 1;  /**< [ 14: 14](R/W1C/H) Completion timeout status. */
        uint32_t cas                   : 1;  /**< [ 15: 15](R/W1C/H) Completer abort status. */
        uint32_t ucs                   : 1;  /**< [ 16: 16](R/W1C/H) Unexpected completion status. */
        uint32_t ros                   : 1;  /**< [ 17: 17](R/W1C/H) Receiver overflow status. */
        uint32_t mtlps                 : 1;  /**< [ 18: 18](R/W1C/H) Malformed TLP status. */
        uint32_t ecrces                : 1;  /**< [ 19: 19](R/W1C/H) ECRC error status. */
        uint32_t ures                  : 1;  /**< [ 20: 20](R/W1C/H) Unsupported request error status. */
        uint32_t reserved_21           : 1;
        uint32_t ucies                 : 1;  /**< [ 22: 22](R/W1C/H) Uncorrectable internal error status. */
        uint32_t reserved_23           : 1;
        uint32_t uatombs               : 1;  /**< [ 24: 24](RO) Unsupported AtomicOp egress blocked status. */
        uint32_t tpbes                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error status. */
        uint32_t reserved_26_31        : 6;
#endif /* Word 0 - End */
    } s;
    struct bdk_pcieepx_cfg065_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_26_31        : 6;
        uint32_t tpbes                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error status. */
        uint32_t uatombs               : 1;  /**< [ 24: 24](RO) Unsupported AtomicOp egress blocked status. */
        uint32_t reserved_23           : 1;
        uint32_t ucies                 : 1;  /**< [ 22: 22](R/W1C/H) Uncorrectable internal error status. */
        uint32_t reserved_21           : 1;
        uint32_t ures                  : 1;  /**< [ 20: 20](R/W1C/H) Unsupported request error status. */
        uint32_t ecrces                : 1;  /**< [ 19: 19](R/W1C/H) ECRC error status. */
        uint32_t mtlps                 : 1;  /**< [ 18: 18](R/W1C/H) Malformed TLP status. */
        uint32_t ros                   : 1;  /**< [ 17: 17](R/W1C/H) Receiver overflow status. */
        uint32_t ucs                   : 1;  /**< [ 16: 16](R/W1C/H) Unexpected completion status. */
        uint32_t cas                   : 1;  /**< [ 15: 15](R/W1C/H) Completer abort status. */
        uint32_t cts                   : 1;  /**< [ 14: 14](R/W1C/H) Completion timeout status. */
        uint32_t fcpes                 : 1;  /**< [ 13: 13](R/W1C/H) Flow control protocol error status. */
        uint32_t ptlps                 : 1;  /**< [ 12: 12](R/W1C/H) Poisoned TLP status. */
        uint32_t reserved_5_11         : 7;
        uint32_t dlpes                 : 1;  /**< [  4:  4](R/W1C/H) Data link protocol error status. */
        uint32_t reserved_1_3          : 3;
        uint32_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0            : 1;
        uint32_t reserved_1_3          : 3;
        uint32_t dlpes                 : 1;  /**< [  4:  4](R/W1C/H) Data link protocol error status. */
        uint32_t reserved_5_11         : 7;
        uint32_t ptlps                 : 1;  /**< [ 12: 12](R/W1C/H) Poisoned TLP status. */
        uint32_t fcpes                 : 1;  /**< [ 13: 13](R/W1C/H) Flow control protocol error status. */
        uint32_t cts                   : 1;  /**< [ 14: 14](R/W1C/H) Completion timeout status. */
        uint32_t cas                   : 1;  /**< [ 15: 15](R/W1C/H) Completer abort status. */
        uint32_t ucs                   : 1;  /**< [ 16: 16](R/W1C/H) Unexpected completion status. */
        uint32_t ros                   : 1;  /**< [ 17: 17](R/W1C/H) Receiver overflow status. */
        uint32_t mtlps                 : 1;  /**< [ 18: 18](R/W1C/H) Malformed TLP status. */
        uint32_t ecrces                : 1;  /**< [ 19: 19](R/W1C/H) ECRC error status. */
        uint32_t ures                  : 1;  /**< [ 20: 20](R/W1C/H) Unsupported request error status. */
        uint32_t reserved_21           : 1;
        uint32_t ucies                 : 1;  /**< [ 22: 22](R/W1C/H) Uncorrectable internal error status. */
        uint32_t reserved_23           : 1;
        uint32_t uatombs               : 1;  /**< [ 24: 24](RO) Unsupported AtomicOp egress blocked status. */
        uint32_t tpbes                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error status. */
        uint32_t reserved_26_31        : 6;
#endif /* Word 0 - End */
    } cn;
} bdk_pcieepx_cfg065_t;

static inline uint64_t BDK_PCIEEPX_CFG065(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG065(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000104ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG065", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG065(a) bdk_pcieepx_cfg065_t
#define bustype_BDK_PCIEEPX_CFG065(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG065(a) "PCIEEPX_CFG065"
#define busnum_BDK_PCIEEPX_CFG065(a) (a)
#define arguments_BDK_PCIEEPX_CFG065(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg066
 *
 * Uncorrectable Error Mask Register
 * This register contains the sixty-seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg066_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_26_31        : 6;
        uint32_t tpbem                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error mask. */
        uint32_t uatombm               : 1;  /**< [ 24: 24](R/W) Unsupported AtomicOp egress blocked mask. */
        uint32_t reserved_23           : 1;
        uint32_t uciem                 : 1;  /**< [ 22: 22](R/W) Uncorrectable internal error mask. */
        uint32_t reserved_21           : 1;
        uint32_t urem                  : 1;  /**< [ 20: 20](R/W) Unsupported request error mask. */
        uint32_t ecrcem                : 1;  /**< [ 19: 19](R/W) ECRC error mask. */
        uint32_t mtlpm                 : 1;  /**< [ 18: 18](R/W) Malformed TLP mask. */
        uint32_t rom                   : 1;  /**< [ 17: 17](R/W) Receiver overflow mask. */
        uint32_t ucm                   : 1;  /**< [ 16: 16](R/W) Unexpected completion mask. */
        uint32_t cam                   : 1;  /**< [ 15: 15](R/W) Completer abort mask. */
        uint32_t ctm                   : 1;  /**< [ 14: 14](R/W) Completion timeout mask. */
        uint32_t fcpem                 : 1;  /**< [ 13: 13](R/W) Flow control protocol error mask. */
        uint32_t ptlpm                 : 1;  /**< [ 12: 12](R/W) Poisoned TLP mask. */
        uint32_t reserved_5_11         : 7;
        uint32_t dlpem                 : 1;  /**< [  4:  4](R/W) Data link protocol error mask. */
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t dlpem                 : 1;  /**< [  4:  4](R/W) Data link protocol error mask. */
        uint32_t reserved_5_11         : 7;
        uint32_t ptlpm                 : 1;  /**< [ 12: 12](R/W) Poisoned TLP mask. */
        uint32_t fcpem                 : 1;  /**< [ 13: 13](R/W) Flow control protocol error mask. */
        uint32_t ctm                   : 1;  /**< [ 14: 14](R/W) Completion timeout mask. */
        uint32_t cam                   : 1;  /**< [ 15: 15](R/W) Completer abort mask. */
        uint32_t ucm                   : 1;  /**< [ 16: 16](R/W) Unexpected completion mask. */
        uint32_t rom                   : 1;  /**< [ 17: 17](R/W) Receiver overflow mask. */
        uint32_t mtlpm                 : 1;  /**< [ 18: 18](R/W) Malformed TLP mask. */
        uint32_t ecrcem                : 1;  /**< [ 19: 19](R/W) ECRC error mask. */
        uint32_t urem                  : 1;  /**< [ 20: 20](R/W) Unsupported request error mask. */
        uint32_t reserved_21           : 1;
        uint32_t uciem                 : 1;  /**< [ 22: 22](R/W) Uncorrectable internal error mask. */
        uint32_t reserved_23           : 1;
        uint32_t uatombm               : 1;  /**< [ 24: 24](R/W) Unsupported AtomicOp egress blocked mask. */
        uint32_t tpbem                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error mask. */
        uint32_t reserved_26_31        : 6;
#endif /* Word 0 - End */
    } s;
    struct bdk_pcieepx_cfg066_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_26_31        : 6;
        uint32_t tpbem                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error mask. */
        uint32_t uatombm               : 1;  /**< [ 24: 24](R/W) Unsupported AtomicOp egress blocked mask. */
        uint32_t reserved_23           : 1;
        uint32_t uciem                 : 1;  /**< [ 22: 22](R/W) Uncorrectable internal error mask. */
        uint32_t reserved_21           : 1;
        uint32_t urem                  : 1;  /**< [ 20: 20](R/W) Unsupported request error mask. */
        uint32_t ecrcem                : 1;  /**< [ 19: 19](R/W) ECRC error mask. */
        uint32_t mtlpm                 : 1;  /**< [ 18: 18](R/W) Malformed TLP mask. */
        uint32_t rom                   : 1;  /**< [ 17: 17](R/W) Receiver overflow mask. */
        uint32_t ucm                   : 1;  /**< [ 16: 16](R/W) Unexpected completion mask. */
        uint32_t cam                   : 1;  /**< [ 15: 15](R/W) Completer abort mask. */
        uint32_t ctm                   : 1;  /**< [ 14: 14](R/W) Completion timeout mask. */
        uint32_t fcpem                 : 1;  /**< [ 13: 13](R/W) Flow control protocol error mask. */
        uint32_t ptlpm                 : 1;  /**< [ 12: 12](R/W) Poisoned TLP mask. */
        uint32_t reserved_5_11         : 7;
        uint32_t dlpem                 : 1;  /**< [  4:  4](R/W) Data link protocol error mask. */
        uint32_t reserved_1_3          : 3;
        uint32_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0            : 1;
        uint32_t reserved_1_3          : 3;
        uint32_t dlpem                 : 1;  /**< [  4:  4](R/W) Data link protocol error mask. */
        uint32_t reserved_5_11         : 7;
        uint32_t ptlpm                 : 1;  /**< [ 12: 12](R/W) Poisoned TLP mask. */
        uint32_t fcpem                 : 1;  /**< [ 13: 13](R/W) Flow control protocol error mask. */
        uint32_t ctm                   : 1;  /**< [ 14: 14](R/W) Completion timeout mask. */
        uint32_t cam                   : 1;  /**< [ 15: 15](R/W) Completer abort mask. */
        uint32_t ucm                   : 1;  /**< [ 16: 16](R/W) Unexpected completion mask. */
        uint32_t rom                   : 1;  /**< [ 17: 17](R/W) Receiver overflow mask. */
        uint32_t mtlpm                 : 1;  /**< [ 18: 18](R/W) Malformed TLP mask. */
        uint32_t ecrcem                : 1;  /**< [ 19: 19](R/W) ECRC error mask. */
        uint32_t urem                  : 1;  /**< [ 20: 20](R/W) Unsupported request error mask. */
        uint32_t reserved_21           : 1;
        uint32_t uciem                 : 1;  /**< [ 22: 22](R/W) Uncorrectable internal error mask. */
        uint32_t reserved_23           : 1;
        uint32_t uatombm               : 1;  /**< [ 24: 24](R/W) Unsupported AtomicOp egress blocked mask. */
        uint32_t tpbem                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error mask. */
        uint32_t reserved_26_31        : 6;
#endif /* Word 0 - End */
    } cn;
} bdk_pcieepx_cfg066_t;

static inline uint64_t BDK_PCIEEPX_CFG066(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG066(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000108ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG066", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG066(a) bdk_pcieepx_cfg066_t
#define bustype_BDK_PCIEEPX_CFG066(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG066(a) "PCIEEPX_CFG066"
#define busnum_BDK_PCIEEPX_CFG066(a) (a)
#define arguments_BDK_PCIEEPX_CFG066(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg067
 *
 * Uncorrectable Error Severity Register
 * This register contains the sixty-eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg067_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_26_31        : 6;
        uint32_t tpbes                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error severity. */
        uint32_t uatombs               : 1;  /**< [ 24: 24](R/W) Unsupported AtomicOp egress blocked severity. */
        uint32_t reserved_23           : 1;
        uint32_t ucies                 : 1;  /**< [ 22: 22](R/W) Uncorrectable internal error severity. */
        uint32_t reserved_21           : 1;
        uint32_t ures                  : 1;  /**< [ 20: 20](R/W) Unsupported request error severity. */
        uint32_t ecrces                : 1;  /**< [ 19: 19](R/W) ECRC error severity. */
        uint32_t mtlps                 : 1;  /**< [ 18: 18](R/W) Malformed TLP severity. */
        uint32_t ros                   : 1;  /**< [ 17: 17](R/W) Receiver overflow severity. */
        uint32_t ucs                   : 1;  /**< [ 16: 16](R/W) Unexpected completion severity. */
        uint32_t cas                   : 1;  /**< [ 15: 15](R/W) Completer abort severity. */
        uint32_t cts                   : 1;  /**< [ 14: 14](R/W) Completion timeout severity. */
        uint32_t fcpes                 : 1;  /**< [ 13: 13](R/W) Flow control protocol error severity. */
        uint32_t ptlps                 : 1;  /**< [ 12: 12](R/W) Poisoned TLP severity. */
        uint32_t reserved_5_11         : 7;
        uint32_t dlpes                 : 1;  /**< [  4:  4](R/W) Data link protocol error severity. */
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t dlpes                 : 1;  /**< [  4:  4](R/W) Data link protocol error severity. */
        uint32_t reserved_5_11         : 7;
        uint32_t ptlps                 : 1;  /**< [ 12: 12](R/W) Poisoned TLP severity. */
        uint32_t fcpes                 : 1;  /**< [ 13: 13](R/W) Flow control protocol error severity. */
        uint32_t cts                   : 1;  /**< [ 14: 14](R/W) Completion timeout severity. */
        uint32_t cas                   : 1;  /**< [ 15: 15](R/W) Completer abort severity. */
        uint32_t ucs                   : 1;  /**< [ 16: 16](R/W) Unexpected completion severity. */
        uint32_t ros                   : 1;  /**< [ 17: 17](R/W) Receiver overflow severity. */
        uint32_t mtlps                 : 1;  /**< [ 18: 18](R/W) Malformed TLP severity. */
        uint32_t ecrces                : 1;  /**< [ 19: 19](R/W) ECRC error severity. */
        uint32_t ures                  : 1;  /**< [ 20: 20](R/W) Unsupported request error severity. */
        uint32_t reserved_21           : 1;
        uint32_t ucies                 : 1;  /**< [ 22: 22](R/W) Uncorrectable internal error severity. */
        uint32_t reserved_23           : 1;
        uint32_t uatombs               : 1;  /**< [ 24: 24](R/W) Unsupported AtomicOp egress blocked severity. */
        uint32_t tpbes                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error severity. */
        uint32_t reserved_26_31        : 6;
#endif /* Word 0 - End */
    } s;
    struct bdk_pcieepx_cfg067_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_26_31        : 6;
        uint32_t tpbes                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error severity. */
        uint32_t uatombs               : 1;  /**< [ 24: 24](R/W) Unsupported AtomicOp egress blocked severity. */
        uint32_t reserved_23           : 1;
        uint32_t ucies                 : 1;  /**< [ 22: 22](R/W) Uncorrectable internal error severity. */
        uint32_t reserved_21           : 1;
        uint32_t ures                  : 1;  /**< [ 20: 20](R/W) Unsupported request error severity. */
        uint32_t ecrces                : 1;  /**< [ 19: 19](R/W) ECRC error severity. */
        uint32_t mtlps                 : 1;  /**< [ 18: 18](R/W) Malformed TLP severity. */
        uint32_t ros                   : 1;  /**< [ 17: 17](R/W) Receiver overflow severity. */
        uint32_t ucs                   : 1;  /**< [ 16: 16](R/W) Unexpected completion severity. */
        uint32_t cas                   : 1;  /**< [ 15: 15](R/W) Completer abort severity. */
        uint32_t cts                   : 1;  /**< [ 14: 14](R/W) Completion timeout severity. */
        uint32_t fcpes                 : 1;  /**< [ 13: 13](R/W) Flow control protocol error severity. */
        uint32_t ptlps                 : 1;  /**< [ 12: 12](R/W) Poisoned TLP severity. */
        uint32_t reserved_5_11         : 7;
        uint32_t dlpes                 : 1;  /**< [  4:  4](R/W) Data link protocol error severity. */
        uint32_t reserved_1_3          : 3;
        uint32_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0            : 1;
        uint32_t reserved_1_3          : 3;
        uint32_t dlpes                 : 1;  /**< [  4:  4](R/W) Data link protocol error severity. */
        uint32_t reserved_5_11         : 7;
        uint32_t ptlps                 : 1;  /**< [ 12: 12](R/W) Poisoned TLP severity. */
        uint32_t fcpes                 : 1;  /**< [ 13: 13](R/W) Flow control protocol error severity. */
        uint32_t cts                   : 1;  /**< [ 14: 14](R/W) Completion timeout severity. */
        uint32_t cas                   : 1;  /**< [ 15: 15](R/W) Completer abort severity. */
        uint32_t ucs                   : 1;  /**< [ 16: 16](R/W) Unexpected completion severity. */
        uint32_t ros                   : 1;  /**< [ 17: 17](R/W) Receiver overflow severity. */
        uint32_t mtlps                 : 1;  /**< [ 18: 18](R/W) Malformed TLP severity. */
        uint32_t ecrces                : 1;  /**< [ 19: 19](R/W) ECRC error severity. */
        uint32_t ures                  : 1;  /**< [ 20: 20](R/W) Unsupported request error severity. */
        uint32_t reserved_21           : 1;
        uint32_t ucies                 : 1;  /**< [ 22: 22](R/W) Uncorrectable internal error severity. */
        uint32_t reserved_23           : 1;
        uint32_t uatombs               : 1;  /**< [ 24: 24](R/W) Unsupported AtomicOp egress blocked severity. */
        uint32_t tpbes                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error severity. */
        uint32_t reserved_26_31        : 6;
#endif /* Word 0 - End */
    } cn;
} bdk_pcieepx_cfg067_t;

static inline uint64_t BDK_PCIEEPX_CFG067(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG067(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000010cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG067", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG067(a) bdk_pcieepx_cfg067_t
#define bustype_BDK_PCIEEPX_CFG067(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG067(a) "PCIEEPX_CFG067"
#define busnum_BDK_PCIEEPX_CFG067(a) (a)
#define arguments_BDK_PCIEEPX_CFG067(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg068
 *
 * Correctable Error Status Register
 * This register contains the sixty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg068_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_15_31        : 17;
        uint32_t cies                  : 1;  /**< [ 14: 14](R/W1C) Corrected internal error status. */
        uint32_t anfes                 : 1;  /**< [ 13: 13](R/W1C/H) Advisory nonfatal error status. */
        uint32_t rtts                  : 1;  /**< [ 12: 12](R/W1C/H) Replay timer timeout status. */
        uint32_t reserved_9_11         : 3;
        uint32_t rnrs                  : 1;  /**< [  8:  8](R/W1C/H) REPLAY_NUM rollover status. */
        uint32_t bdllps                : 1;  /**< [  7:  7](R/W1C/H) Bad DLLP status. */
        uint32_t btlps                 : 1;  /**< [  6:  6](R/W1C/H) Bad TLP status. */
        uint32_t reserved_1_5          : 5;
        uint32_t res                   : 1;  /**< [  0:  0](R/W1C/H) Receiver error status. */
#else /* Word 0 - Little Endian */
        uint32_t res                   : 1;  /**< [  0:  0](R/W1C/H) Receiver error status. */
        uint32_t reserved_1_5          : 5;
        uint32_t btlps                 : 1;  /**< [  6:  6](R/W1C/H) Bad TLP status. */
        uint32_t bdllps                : 1;  /**< [  7:  7](R/W1C/H) Bad DLLP status. */
        uint32_t rnrs                  : 1;  /**< [  8:  8](R/W1C/H) REPLAY_NUM rollover status. */
        uint32_t reserved_9_11         : 3;
        uint32_t rtts                  : 1;  /**< [ 12: 12](R/W1C/H) Replay timer timeout status. */
        uint32_t anfes                 : 1;  /**< [ 13: 13](R/W1C/H) Advisory nonfatal error status. */
        uint32_t cies                  : 1;  /**< [ 14: 14](R/W1C) Corrected internal error status. */
        uint32_t reserved_15_31        : 17;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg068_s cn; */
} bdk_pcieepx_cfg068_t;

static inline uint64_t BDK_PCIEEPX_CFG068(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG068(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000110ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG068", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG068(a) bdk_pcieepx_cfg068_t
#define bustype_BDK_PCIEEPX_CFG068(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG068(a) "PCIEEPX_CFG068"
#define busnum_BDK_PCIEEPX_CFG068(a) (a)
#define arguments_BDK_PCIEEPX_CFG068(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg069
 *
 * Correctable Error Mask Register
 * This register contains the seventieth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg069_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_15_31        : 17;
        uint32_t ciem                  : 1;  /**< [ 14: 14](R/W) Corrected internal error mask. */
        uint32_t anfem                 : 1;  /**< [ 13: 13](R/W) Advisory nonfatal error mask. */
        uint32_t rttm                  : 1;  /**< [ 12: 12](R/W) Replay timer timeout mask. */
        uint32_t reserved_9_11         : 3;
        uint32_t rnrm                  : 1;  /**< [  8:  8](R/W) REPLAY_NUM rollover mask. */
        uint32_t bdllpm                : 1;  /**< [  7:  7](R/W) Bad DLLP mask. */
        uint32_t btlpm                 : 1;  /**< [  6:  6](R/W) Bad TLP mask. */
        uint32_t reserved_1_5          : 5;
        uint32_t rem                   : 1;  /**< [  0:  0](R/W) Receiver error mask. */
#else /* Word 0 - Little Endian */
        uint32_t rem                   : 1;  /**< [  0:  0](R/W) Receiver error mask. */
        uint32_t reserved_1_5          : 5;
        uint32_t btlpm                 : 1;  /**< [  6:  6](R/W) Bad TLP mask. */
        uint32_t bdllpm                : 1;  /**< [  7:  7](R/W) Bad DLLP mask. */
        uint32_t rnrm                  : 1;  /**< [  8:  8](R/W) REPLAY_NUM rollover mask. */
        uint32_t reserved_9_11         : 3;
        uint32_t rttm                  : 1;  /**< [ 12: 12](R/W) Replay timer timeout mask. */
        uint32_t anfem                 : 1;  /**< [ 13: 13](R/W) Advisory nonfatal error mask. */
        uint32_t ciem                  : 1;  /**< [ 14: 14](R/W) Corrected internal error mask. */
        uint32_t reserved_15_31        : 17;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg069_s cn; */
} bdk_pcieepx_cfg069_t;

static inline uint64_t BDK_PCIEEPX_CFG069(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG069(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000114ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG069", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG069(a) bdk_pcieepx_cfg069_t
#define bustype_BDK_PCIEEPX_CFG069(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG069(a) "PCIEEPX_CFG069"
#define busnum_BDK_PCIEEPX_CFG069(a) (a)
#define arguments_BDK_PCIEEPX_CFG069(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg070
 *
 * Advanced Error Capabilities and Control Register
 * This register contains the seventy-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg070_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_12_31        : 20;
        uint32_t tlp_plp               : 1;  /**< [ 11: 11](RO) TLP prefix log present (not supported). */
        uint32_t reserved_9_10         : 2;
        uint32_t ce                    : 1;  /**< [  8:  8](R/W) ECRC check enable. */
        uint32_t cc                    : 1;  /**< [  7:  7](RO) ECRC check capable. */
        uint32_t ge                    : 1;  /**< [  6:  6](R/W) ECRC generation enable. */
        uint32_t gc                    : 1;  /**< [  5:  5](RO) ECRC generation capability. */
        uint32_t fep                   : 5;  /**< [  4:  0](RO/H) First error pointer. */
#else /* Word 0 - Little Endian */
        uint32_t fep                   : 5;  /**< [  4:  0](RO/H) First error pointer. */
        uint32_t gc                    : 1;  /**< [  5:  5](RO) ECRC generation capability. */
        uint32_t ge                    : 1;  /**< [  6:  6](R/W) ECRC generation enable. */
        uint32_t cc                    : 1;  /**< [  7:  7](RO) ECRC check capable. */
        uint32_t ce                    : 1;  /**< [  8:  8](R/W) ECRC check enable. */
        uint32_t reserved_9_10         : 2;
        uint32_t tlp_plp               : 1;  /**< [ 11: 11](RO) TLP prefix log present (not supported). */
        uint32_t reserved_12_31        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg070_s cn; */
} bdk_pcieepx_cfg070_t;

static inline uint64_t BDK_PCIEEPX_CFG070(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG070(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000118ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG070", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG070(a) bdk_pcieepx_cfg070_t
#define bustype_BDK_PCIEEPX_CFG070(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG070(a) "PCIEEPX_CFG070"
#define busnum_BDK_PCIEEPX_CFG070(a) (a)
#define arguments_BDK_PCIEEPX_CFG070(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg071
 *
 * Header Log Register 1
 * This register contains the seventy-second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg071_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t dword1                : 32; /**< [ 31:  0](RO/H) Header log register (first DWORD). */
#else /* Word 0 - Little Endian */
        uint32_t dword1                : 32; /**< [ 31:  0](RO/H) Header log register (first DWORD). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg071_s cn; */
} bdk_pcieepx_cfg071_t;

static inline uint64_t BDK_PCIEEPX_CFG071(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG071(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000011cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG071", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG071(a) bdk_pcieepx_cfg071_t
#define bustype_BDK_PCIEEPX_CFG071(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG071(a) "PCIEEPX_CFG071"
#define busnum_BDK_PCIEEPX_CFG071(a) (a)
#define arguments_BDK_PCIEEPX_CFG071(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg072
 *
 * Header Log Register 2
 * This register contains the seventy-third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg072_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t dword2                : 32; /**< [ 31:  0](RO/H) Header log register (second DWORD). */
#else /* Word 0 - Little Endian */
        uint32_t dword2                : 32; /**< [ 31:  0](RO/H) Header log register (second DWORD). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg072_s cn; */
} bdk_pcieepx_cfg072_t;

static inline uint64_t BDK_PCIEEPX_CFG072(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG072(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000120ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG072", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG072(a) bdk_pcieepx_cfg072_t
#define bustype_BDK_PCIEEPX_CFG072(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG072(a) "PCIEEPX_CFG072"
#define busnum_BDK_PCIEEPX_CFG072(a) (a)
#define arguments_BDK_PCIEEPX_CFG072(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg073
 *
 * Header Log Register 3
 * This register contains the seventy-fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg073_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t dword3                : 32; /**< [ 31:  0](RO/H) Header log register (third DWORD). */
#else /* Word 0 - Little Endian */
        uint32_t dword3                : 32; /**< [ 31:  0](RO/H) Header log register (third DWORD). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg073_s cn; */
} bdk_pcieepx_cfg073_t;

static inline uint64_t BDK_PCIEEPX_CFG073(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG073(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000124ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG073", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG073(a) bdk_pcieepx_cfg073_t
#define bustype_BDK_PCIEEPX_CFG073(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG073(a) "PCIEEPX_CFG073"
#define busnum_BDK_PCIEEPX_CFG073(a) (a)
#define arguments_BDK_PCIEEPX_CFG073(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg074
 *
 * Header Log Register 4
 * This register contains the seventy-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg074_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t dword4                : 32; /**< [ 31:  0](RO/H) Header log register (fourth DWORD). */
#else /* Word 0 - Little Endian */
        uint32_t dword4                : 32; /**< [ 31:  0](RO/H) Header log register (fourth DWORD). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg074_s cn; */
} bdk_pcieepx_cfg074_t;

static inline uint64_t BDK_PCIEEPX_CFG074(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG074(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000128ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG074", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG074(a) bdk_pcieepx_cfg074_t
#define bustype_BDK_PCIEEPX_CFG074(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG074(a) "PCIEEPX_CFG074"
#define busnum_BDK_PCIEEPX_CFG074(a) (a)
#define arguments_BDK_PCIEEPX_CFG074(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg078
 *
 * TLP Prefix Log Register 4
 * This register contains the seventy-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg078_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t tlp_pfx_log           : 32; /**< [ 31:  0](RO/H) TLP prefix log register. */
#else /* Word 0 - Little Endian */
        uint32_t tlp_pfx_log           : 32; /**< [ 31:  0](RO/H) TLP prefix log register. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg078_s cn; */
} bdk_pcieepx_cfg078_t;

static inline uint64_t BDK_PCIEEPX_CFG078(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG078(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000138ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG078", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG078(a) bdk_pcieepx_cfg078_t
#define bustype_BDK_PCIEEPX_CFG078(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG078(a) "PCIEEPX_CFG078"
#define busnum_BDK_PCIEEPX_CFG078(a) (a)
#define arguments_BDK_PCIEEPX_CFG078(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg082
 *
 * PCI Express ARI Capability Header Register
 * This register contains the eighty-third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg082_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. Points to the secondary PCI Express capabilities by default. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t ariid                 : 16; /**< [ 15:  0](RO) PCI Express extended capability. */
#else /* Word 0 - Little Endian */
        uint32_t ariid                 : 16; /**< [ 15:  0](RO) PCI Express extended capability. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. Points to the secondary PCI Express capabilities by default. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg082_s cn; */
} bdk_pcieepx_cfg082_t;

static inline uint64_t BDK_PCIEEPX_CFG082(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG082(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000148ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG082", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG082(a) bdk_pcieepx_cfg082_t
#define bustype_BDK_PCIEEPX_CFG082(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG082(a) "PCIEEPX_CFG082"
#define busnum_BDK_PCIEEPX_CFG082(a) (a)
#define arguments_BDK_PCIEEPX_CFG082(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg083
 *
 * PCI Express ARI Capability Register/PCI Express ARI Control Register
 * This register contains the eighty-fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg083_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_23_31        : 9;
        uint32_t fg                    : 3;  /**< [ 22: 20](RO) Function group. */
        uint32_t reserved_18_19        : 2;
        uint32_t acsfge                : 1;  /**< [ 17: 17](RO) ACS function groups enable (A). */
        uint32_t mfvcfge               : 1;  /**< [ 16: 16](RO) MFVC function groups enable (M). */
        uint32_t nfn                   : 8;  /**< [ 15:  8](RO/H) Next function number. */
        uint32_t reserved_2_7          : 6;
        uint32_t acsfgc                : 1;  /**< [  1:  1](RO) ACS function groups capability. */
        uint32_t mfvcfgc               : 1;  /**< [  0:  0](RO) MFVC function groups capability. */
#else /* Word 0 - Little Endian */
        uint32_t mfvcfgc               : 1;  /**< [  0:  0](RO) MFVC function groups capability. */
        uint32_t acsfgc                : 1;  /**< [  1:  1](RO) ACS function groups capability. */
        uint32_t reserved_2_7          : 6;
        uint32_t nfn                   : 8;  /**< [ 15:  8](RO/H) Next function number. */
        uint32_t mfvcfge               : 1;  /**< [ 16: 16](RO) MFVC function groups enable (M). */
        uint32_t acsfge                : 1;  /**< [ 17: 17](RO) ACS function groups enable (A). */
        uint32_t reserved_18_19        : 2;
        uint32_t fg                    : 3;  /**< [ 22: 20](RO) Function group. */
        uint32_t reserved_23_31        : 9;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg083_s cn; */
} bdk_pcieepx_cfg083_t;

static inline uint64_t BDK_PCIEEPX_CFG083(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG083(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000014cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG083", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG083(a) bdk_pcieepx_cfg083_t
#define bustype_BDK_PCIEEPX_CFG083(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG083(a) "PCIEEPX_CFG083"
#define busnum_BDK_PCIEEPX_CFG083(a) (a)
#define arguments_BDK_PCIEEPX_CFG083(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg086
 *
 * PCI Express Secondary Capability (Gen3) Header Register
 * This register contains the eighty-seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg086_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. Points to the PCI Express SR-IOV capability header by default. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCIE Express extended capability */
#else /* Word 0 - Little Endian */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCIE Express extended capability */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. Points to the PCI Express SR-IOV capability header by default. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg086_s cn; */
} bdk_pcieepx_cfg086_t;

static inline uint64_t BDK_PCIEEPX_CFG086(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG086(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000158ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG086", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG086(a) bdk_pcieepx_cfg086_t
#define bustype_BDK_PCIEEPX_CFG086(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG086(a) "PCIEEPX_CFG086"
#define busnum_BDK_PCIEEPX_CFG086(a) (a)
#define arguments_BDK_PCIEEPX_CFG086(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg087
 *
 * Link Control 3 Register
 * This register contains the eighty-eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg087_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_2_31         : 30;
        uint32_t ler                   : 1;  /**< [  1:  1](RO) Link equalization request interrupt enable. */
        uint32_t pe                    : 1;  /**< [  0:  0](RO) Perform equalization. */
#else /* Word 0 - Little Endian */
        uint32_t pe                    : 1;  /**< [  0:  0](RO) Perform equalization. */
        uint32_t ler                   : 1;  /**< [  1:  1](RO) Link equalization request interrupt enable. */
        uint32_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg087_s cn; */
} bdk_pcieepx_cfg087_t;

static inline uint64_t BDK_PCIEEPX_CFG087(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG087(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000015cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG087", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG087(a) bdk_pcieepx_cfg087_t
#define bustype_BDK_PCIEEPX_CFG087(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG087(a) "PCIEEPX_CFG087"
#define busnum_BDK_PCIEEPX_CFG087(a) (a)
#define arguments_BDK_PCIEEPX_CFG087(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg088
 *
 * Lane Error Status Register
 * This register contains the eighty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg088_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t les                   : 8;  /**< [  7:  0](R/W1C) Lane error status bits. */
#else /* Word 0 - Little Endian */
        uint32_t les                   : 8;  /**< [  7:  0](R/W1C) Lane error status bits. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg088_s cn; */
} bdk_pcieepx_cfg088_t;

static inline uint64_t BDK_PCIEEPX_CFG088(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG088(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000160ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG088", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG088(a) bdk_pcieepx_cfg088_t
#define bustype_BDK_PCIEEPX_CFG088(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG088(a) "PCIEEPX_CFG088"
#define busnum_BDK_PCIEEPX_CFG088(a) (a)
#define arguments_BDK_PCIEEPX_CFG088(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg089
 *
 * Equalization Control Lane 0/1 Register
 * This register contains the ninetieth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg089_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t l1dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 1 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l1dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 1 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_15_23        : 9;
        uint32_t l0dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 0 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l0dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 0 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_0_7          : 8;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_7          : 8;
        uint32_t l0dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 0 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l0dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 0 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_15_23        : 9;
        uint32_t l1dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 1 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l1dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 1 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    struct bdk_pcieepx_cfg089_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t l1dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 1 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l1dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 1 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_23           : 1;
        uint32_t reserved_20_22        : 3;
        uint32_t reserved_16_19        : 4;
        uint32_t reserved_15           : 1;
        uint32_t l0dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 0 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l0dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 0 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_7            : 1;
        uint32_t reserved_4_6          : 3;
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t reserved_4_6          : 3;
        uint32_t reserved_7            : 1;
        uint32_t l0dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 0 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l0dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 0 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_15           : 1;
        uint32_t reserved_16_19        : 4;
        uint32_t reserved_20_22        : 3;
        uint32_t reserved_23           : 1;
        uint32_t l1dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 1 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l1dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 1 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } cn;
} bdk_pcieepx_cfg089_t;

static inline uint64_t BDK_PCIEEPX_CFG089(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG089(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000164ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG089", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG089(a) bdk_pcieepx_cfg089_t
#define bustype_BDK_PCIEEPX_CFG089(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG089(a) "PCIEEPX_CFG089"
#define busnum_BDK_PCIEEPX_CFG089(a) (a)
#define arguments_BDK_PCIEEPX_CFG089(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg090
 *
 * Equalization Control Lane 2/3 Register
 * This register contains the ninety-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg090_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t l3dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 3 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l3dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 3 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_15_23        : 9;
        uint32_t l2dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 2 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l2dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 2 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_0_7          : 8;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_7          : 8;
        uint32_t l2dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 2 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l2dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 2 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_15_23        : 9;
        uint32_t l3dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 3 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l3dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 3 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    struct bdk_pcieepx_cfg090_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t l3dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 3 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l3dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 3 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_23           : 1;
        uint32_t reserved_20_22        : 3;
        uint32_t reserved_16_19        : 4;
        uint32_t reserved_15           : 1;
        uint32_t l2dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 2 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l2dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 2 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_7            : 1;
        uint32_t reserved_4_6          : 3;
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t reserved_4_6          : 3;
        uint32_t reserved_7            : 1;
        uint32_t l2dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 2 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l2dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 2 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_15           : 1;
        uint32_t reserved_16_19        : 4;
        uint32_t reserved_20_22        : 3;
        uint32_t reserved_23           : 1;
        uint32_t l3dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 3 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l3dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 3 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } cn;
} bdk_pcieepx_cfg090_t;

static inline uint64_t BDK_PCIEEPX_CFG090(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG090(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000168ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG090", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG090(a) bdk_pcieepx_cfg090_t
#define bustype_BDK_PCIEEPX_CFG090(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG090(a) "PCIEEPX_CFG090"
#define busnum_BDK_PCIEEPX_CFG090(a) (a)
#define arguments_BDK_PCIEEPX_CFG090(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg091
 *
 * Equalization Control Lane 4/5 Register
 * This register contains the ninety-second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg091_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t l5dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 5 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l5dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 5 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_15_23        : 9;
        uint32_t l4dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 4 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l4dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 4 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_0_7          : 8;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_7          : 8;
        uint32_t l4dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 4 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l4dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 4 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_15_23        : 9;
        uint32_t l5dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 5 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l5dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 5 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    struct bdk_pcieepx_cfg091_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t l5dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 5 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l5dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 5 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_23           : 1;
        uint32_t reserved_20_22        : 3;
        uint32_t reserved_16_19        : 4;
        uint32_t reserved_15           : 1;
        uint32_t l4dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 4 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l4dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 4 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_7            : 1;
        uint32_t reserved_4_6          : 3;
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t reserved_4_6          : 3;
        uint32_t reserved_7            : 1;
        uint32_t l4dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 4 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l4dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 4 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_15           : 1;
        uint32_t reserved_16_19        : 4;
        uint32_t reserved_20_22        : 3;
        uint32_t reserved_23           : 1;
        uint32_t l5dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 5 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l5dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 5 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } cn;
} bdk_pcieepx_cfg091_t;

static inline uint64_t BDK_PCIEEPX_CFG091(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG091(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000016cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG091", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG091(a) bdk_pcieepx_cfg091_t
#define bustype_BDK_PCIEEPX_CFG091(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG091(a) "PCIEEPX_CFG091"
#define busnum_BDK_PCIEEPX_CFG091(a) (a)
#define arguments_BDK_PCIEEPX_CFG091(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg092
 *
 * Equalization Control Lane 6/7 Register
 * This register contains the ninety-fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg092_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t l7dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 7 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l7dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 7 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_15_23        : 9;
        uint32_t l6dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 6 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l6dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 6 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_0_7          : 8;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_7          : 8;
        uint32_t l6dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 6 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l6dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 6 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_15_23        : 9;
        uint32_t l7dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 7 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l7dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 7 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    struct bdk_pcieepx_cfg092_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t l7dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 7 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l7dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 7 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_23           : 1;
        uint32_t reserved_20_22        : 3;
        uint32_t reserved_16_19        : 4;
        uint32_t reserved_15           : 1;
        uint32_t l6dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 6 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l6dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 6 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_7            : 1;
        uint32_t reserved_4_6          : 3;
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t reserved_4_6          : 3;
        uint32_t reserved_7            : 1;
        uint32_t l6dtp                 : 4;  /**< [ 11:  8](RO/WRSL/H) Lane 6 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l6dph                 : 3;  /**< [ 14: 12](RO/WRSL/H) Lane 6 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_15           : 1;
        uint32_t reserved_16_19        : 4;
        uint32_t reserved_20_22        : 3;
        uint32_t reserved_23           : 1;
        uint32_t l7dtp                 : 4;  /**< [ 27: 24](RO/WRSL/H) Lane 7 downstream component transmitter preset. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t l7dph                 : 3;  /**< [ 30: 28](RO/WRSL/H) Lane 7 downstream component receiver preset hint. Writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } cn;
} bdk_pcieepx_cfg092_t;

static inline uint64_t BDK_PCIEEPX_CFG092(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG092(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000170ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG092", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG092(a) bdk_pcieepx_cfg092_t
#define bustype_BDK_PCIEEPX_CFG092(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG092(a) "PCIEEPX_CFG092"
#define busnum_BDK_PCIEEPX_CFG092(a) (a)
#define arguments_BDK_PCIEEPX_CFG092(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg094
 *
 * PCI Express SR-IOV Capability Header Register
 * This register contains the ninety-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg094_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. Points to the resizable BAR capabilities by default */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCIE Express extended capability. */
#else /* Word 0 - Little Endian */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCIE Express extended capability. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. Points to the resizable BAR capabilities by default */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg094_s cn; */
} bdk_pcieepx_cfg094_t;

static inline uint64_t BDK_PCIEEPX_CFG094(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG094(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000178ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG094", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG094(a) bdk_pcieepx_cfg094_t
#define bustype_BDK_PCIEEPX_CFG094(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG094(a) "PCIEEPX_CFG094"
#define busnum_BDK_PCIEEPX_CFG094(a) (a)
#define arguments_BDK_PCIEEPX_CFG094(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg095
 *
 * PCI Express SR-IOV Capability Register
 * This register contains the ninety-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg095_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vfmimn                : 11; /**< [ 31: 21](RO/H) VF migration interrupt message number. */
        uint32_t reserved_2_20         : 19;
        uint32_t arichp                : 1;  /**< [  1:  1](R/W) ARI capable hierarchy preserved. Writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t vfmc                  : 1;  /**< [  0:  0](RO) VF migration capable. */
#else /* Word 0 - Little Endian */
        uint32_t vfmc                  : 1;  /**< [  0:  0](RO) VF migration capable. */
        uint32_t arichp                : 1;  /**< [  1:  1](R/W) ARI capable hierarchy preserved. Writable through PEM()_CFG_WR. However, the application
                                                                 must not change this field. */
        uint32_t reserved_2_20         : 19;
        uint32_t vfmimn                : 11; /**< [ 31: 21](RO/H) VF migration interrupt message number. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg095_s cn; */
} bdk_pcieepx_cfg095_t;

static inline uint64_t BDK_PCIEEPX_CFG095(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG095(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000017cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG095", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG095(a) bdk_pcieepx_cfg095_t
#define bustype_BDK_PCIEEPX_CFG095(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG095(a) "PCIEEPX_CFG095"
#define busnum_BDK_PCIEEPX_CFG095(a) (a)
#define arguments_BDK_PCIEEPX_CFG095(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg096
 *
 * PCI Express SR-IOV Control/Status Register
 * This register contains the ninety-seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg096_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_17_31        : 15;
        uint32_t ms                    : 1;  /**< [ 16: 16](RO/H) VF migration status. */
        uint32_t reserved_5_15         : 11;
        uint32_t ach                   : 1;  /**< [  4:  4](R/W) ARI capable hierarchy.
                                                                 0 = All PFs have non-ARI capable hierarchy.
                                                                 1 = All PFs have ARI capable hierarchy.

                                                                 The value in this field in PF0 is used for all other physical functions. */
        uint32_t mse                   : 1;  /**< [  3:  3](R/W) VF MSE. */
        uint32_t mie                   : 1;  /**< [  2:  2](RO) VF migration interrupt enable. */
        uint32_t me                    : 1;  /**< [  1:  1](RO) VF migration enable. */
        uint32_t vfe                   : 1;  /**< [  0:  0](R/W) VF enable. */
#else /* Word 0 - Little Endian */
        uint32_t vfe                   : 1;  /**< [  0:  0](R/W) VF enable. */
        uint32_t me                    : 1;  /**< [  1:  1](RO) VF migration enable. */
        uint32_t mie                   : 1;  /**< [  2:  2](RO) VF migration interrupt enable. */
        uint32_t mse                   : 1;  /**< [  3:  3](R/W) VF MSE. */
        uint32_t ach                   : 1;  /**< [  4:  4](R/W) ARI capable hierarchy.
                                                                 0 = All PFs have non-ARI capable hierarchy.
                                                                 1 = All PFs have ARI capable hierarchy.

                                                                 The value in this field in PF0 is used for all other physical functions. */
        uint32_t reserved_5_15         : 11;
        uint32_t ms                    : 1;  /**< [ 16: 16](RO/H) VF migration status. */
        uint32_t reserved_17_31        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg096_s cn; */
} bdk_pcieepx_cfg096_t;

static inline uint64_t BDK_PCIEEPX_CFG096(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG096(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000180ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG096", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG096(a) bdk_pcieepx_cfg096_t
#define bustype_BDK_PCIEEPX_CFG096(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG096(a) "PCIEEPX_CFG096"
#define busnum_BDK_PCIEEPX_CFG096(a) (a)
#define arguments_BDK_PCIEEPX_CFG096(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg097
 *
 * PCI Express SR-IOV Initial VFs/Total VFs Register
 * This register contains the ninety-eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg097_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t tvf                   : 16; /**< [ 31: 16](RO/H) Total VFs.  Read-only copy of PCIEP()_CFG097[IVF].

                                                                 _ PF0:          0x40
                                                                 _ PF1:          0x40
                                                                 _ PF2:          0x403 */
        uint32_t ivf                   : 16; /**< [ 15:  0](RO/WRSL/H) Initial VFs.

                                                                 _ PF0:          0x40
                                                                 _ PF1:          0x40
                                                                 _ PF2:          0x403

                                                                 There are two InitialVFs registers per PF; one for each ARI Capable
                                                                 and non-ARI Capable Hierarchies.  The PCIEP()_CFG096[ARI] determines which one is
                                                                 being used for SR-IOV, and which one is accessed by a read request.

                                                                 This field is writable through PEM()_CFG_WR, PEM()_CFG_WR[ADDR[31]] determines
                                                                 which IVF register is updated.
                                                                 0 = accesses non-ARI Capable Hieracrhy copy of IVF.
                                                                 1 = accesses ARI Capable Hieracrhy copy of IVF.

                                                                 SPEM_CFG_WR[ADDR[25:24] determines the physical function accessed by the write.
                                                                 0..2 are legal values in EP mode. */
#else /* Word 0 - Little Endian */
        uint32_t ivf                   : 16; /**< [ 15:  0](RO/WRSL/H) Initial VFs.

                                                                 _ PF0:          0x40
                                                                 _ PF1:          0x40
                                                                 _ PF2:          0x403

                                                                 There are two InitialVFs registers per PF; one for each ARI Capable
                                                                 and non-ARI Capable Hierarchies.  The PCIEP()_CFG096[ARI] determines which one is
                                                                 being used for SR-IOV, and which one is accessed by a read request.

                                                                 This field is writable through PEM()_CFG_WR, PEM()_CFG_WR[ADDR[31]] determines
                                                                 which IVF register is updated.
                                                                 0 = accesses non-ARI Capable Hieracrhy copy of IVF.
                                                                 1 = accesses ARI Capable Hieracrhy copy of IVF.

                                                                 SPEM_CFG_WR[ADDR[25:24] determines the physical function accessed by the write.
                                                                 0..2 are legal values in EP mode. */
        uint32_t tvf                   : 16; /**< [ 31: 16](RO/H) Total VFs.  Read-only copy of PCIEP()_CFG097[IVF].

                                                                 _ PF0:          0x40
                                                                 _ PF1:          0x40
                                                                 _ PF2:          0x403 */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg097_s cn; */
} bdk_pcieepx_cfg097_t;

static inline uint64_t BDK_PCIEEPX_CFG097(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG097(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000184ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG097", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG097(a) bdk_pcieepx_cfg097_t
#define bustype_BDK_PCIEEPX_CFG097(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG097(a) "PCIEEPX_CFG097"
#define busnum_BDK_PCIEEPX_CFG097(a) (a)
#define arguments_BDK_PCIEEPX_CFG097(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg098
 *
 * PCI Express SR-IOV Number of VFs Register/SR-IOV Function Dependency Link Register
 * This register contains the ninety-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg098_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t fdl                   : 8;  /**< [ 23: 16](RO/H) Function dependency link.

                                                                 _ PF0:          0x0
                                                                 _ PF1:          0x1
                                                                 _ PF2:          0x2 */
        uint32_t nvf                   : 16; /**< [ 15:  0](R/W) Number of VFs that are visible. */
#else /* Word 0 - Little Endian */
        uint32_t nvf                   : 16; /**< [ 15:  0](R/W) Number of VFs that are visible. */
        uint32_t fdl                   : 8;  /**< [ 23: 16](RO/H) Function dependency link.

                                                                 _ PF0:          0x0
                                                                 _ PF1:          0x1
                                                                 _ PF2:          0x2 */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg098_s cn; */
} bdk_pcieepx_cfg098_t;

static inline uint64_t BDK_PCIEEPX_CFG098(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG098(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000188ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG098", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG098(a) bdk_pcieepx_cfg098_t
#define bustype_BDK_PCIEEPX_CFG098(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG098(a) "PCIEEPX_CFG098"
#define busnum_BDK_PCIEEPX_CFG098(a) (a)
#define arguments_BDK_PCIEEPX_CFG098(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg099
 *
 * PCI Express SR-IOV Initial VFs/Total VFs Register
 * This register contains the one hundredth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg099_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vfs                   : 16; /**< [ 31: 16](RO/WRSL) VF stride.

                                                                 There are two VF Stride registers per PF; one for each ARI Capable
                                                                 and non-ARI Capable Hierarchies.  The PCIEP()_CFG096[ARI] determines which one is
                                                                 being used for SR-IOV, and which one is accessed by a read request.

                                                                 This field is writable through PEM()_CFG_WR, PEM()_CFG_WR[ADDR[31]] determines
                                                                 which VFS register is updated.
                                                                 0 = accesses non-ARI Capable Hieracrhy copy of VFS.
                                                                 1 = accesses ARI Capable Hieracrhy copy of VFS.

                                                                 SPEM_CFG_WR[ADDR[25:24] determines the physical function accessed by the write.
                                                                 0..2 are legal values in EP mode. */
        uint32_t fo                    : 16; /**< [ 15:  0](RO/WRSL/H) First VF offset.

                                                                 _ PF0 (SPEM):   0x3
                                                                 _ PF0 (PEM):    0x1
                                                                 _ PF1:          0x43
                                                                 _ PF2:          0x83

                                                                 There are two First VF Offset registers per PF; one for each ARI Capable
                                                                 and non-ARI Capable Hierarchies.  The PCIEP()_CFG096[ARI] determines which one is
                                                                 being used for SR-IOV, and which one is accessed by a read request.

                                                                 This field is writable through PEM()_CFG_WR, PEM()_CFG_WR[ADDR[31]] determines
                                                                 which FO register is updated.
                                                                 0 = accesses non-ARI Capable Hieracrhy copy of FO.
                                                                 1 = accesses ARI Capable Hieracrhy copy of FO.

                                                                 SPEM_CFG_WR[ADDR[25:24] determines the physical function accessed by the write.
                                                                 0..2 are legal values in EP mode. */
#else /* Word 0 - Little Endian */
        uint32_t fo                    : 16; /**< [ 15:  0](RO/WRSL/H) First VF offset.

                                                                 _ PF0 (SPEM):   0x3
                                                                 _ PF0 (PEM):    0x1
                                                                 _ PF1:          0x43
                                                                 _ PF2:          0x83

                                                                 There are two First VF Offset registers per PF; one for each ARI Capable
                                                                 and non-ARI Capable Hierarchies.  The PCIEP()_CFG096[ARI] determines which one is
                                                                 being used for SR-IOV, and which one is accessed by a read request.

                                                                 This field is writable through PEM()_CFG_WR, PEM()_CFG_WR[ADDR[31]] determines
                                                                 which FO register is updated.
                                                                 0 = accesses non-ARI Capable Hieracrhy copy of FO.
                                                                 1 = accesses ARI Capable Hieracrhy copy of FO.

                                                                 SPEM_CFG_WR[ADDR[25:24] determines the physical function accessed by the write.
                                                                 0..2 are legal values in EP mode. */
        uint32_t vfs                   : 16; /**< [ 31: 16](RO/WRSL) VF stride.

                                                                 There are two VF Stride registers per PF; one for each ARI Capable
                                                                 and non-ARI Capable Hierarchies.  The PCIEP()_CFG096[ARI] determines which one is
                                                                 being used for SR-IOV, and which one is accessed by a read request.

                                                                 This field is writable through PEM()_CFG_WR, PEM()_CFG_WR[ADDR[31]] determines
                                                                 which VFS register is updated.
                                                                 0 = accesses non-ARI Capable Hieracrhy copy of VFS.
                                                                 1 = accesses ARI Capable Hieracrhy copy of VFS.

                                                                 SPEM_CFG_WR[ADDR[25:24] determines the physical function accessed by the write.
                                                                 0..2 are legal values in EP mode. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg099_s cn; */
} bdk_pcieepx_cfg099_t;

static inline uint64_t BDK_PCIEEPX_CFG099(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG099(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000018cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG099", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG099(a) bdk_pcieepx_cfg099_t
#define bustype_BDK_PCIEEPX_CFG099(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG099(a) "PCIEEPX_CFG099"
#define busnum_BDK_PCIEEPX_CFG099(a) (a)
#define arguments_BDK_PCIEEPX_CFG099(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg100
 *
 * PCI Express SR-IOV Number of VFs/Function Dependency Link Register
 * This register contains the one hundred first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg100_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vfdev                 : 16; /**< [ 31: 16](RO) VF device ID.

                                                                 _ PF0:          0x9710
                                                                 _ PF1:          0x9710
                                                                 _ PF2:          0x9711 */
        uint32_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_15         : 16;
        uint32_t vfdev                 : 16; /**< [ 31: 16](RO) VF device ID.

                                                                 _ PF0:          0x9710
                                                                 _ PF1:          0x9710
                                                                 _ PF2:          0x9711 */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg100_s cn; */
} bdk_pcieepx_cfg100_t;

static inline uint64_t BDK_PCIEEPX_CFG100(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG100(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000190ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG100", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG100(a) bdk_pcieepx_cfg100_t
#define bustype_BDK_PCIEEPX_CFG100(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG100(a) "PCIEEPX_CFG100"
#define busnum_BDK_PCIEEPX_CFG100(a) (a)
#define arguments_BDK_PCIEEPX_CFG100(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg101
 *
 * PCI Express SR-IOV Supported Page Sizes Register
 * This register contains the one hundred second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg101_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t supps                 : 32; /**< [ 31:  0](RO) Supported page sizes. */
#else /* Word 0 - Little Endian */
        uint32_t supps                 : 32; /**< [ 31:  0](RO) Supported page sizes. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg101_s cn; */
} bdk_pcieepx_cfg101_t;

static inline uint64_t BDK_PCIEEPX_CFG101(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG101(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000194ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG101", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG101(a) bdk_pcieepx_cfg101_t
#define bustype_BDK_PCIEEPX_CFG101(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG101(a) "PCIEEPX_CFG101"
#define busnum_BDK_PCIEEPX_CFG101(a) (a)
#define arguments_BDK_PCIEEPX_CFG101(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg102
 *
 * PCI Express SR-IOV System Page Sizes Register
 * This register contains the one hundred third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg102_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ps                    : 32; /**< [ 31:  0](R/W) System page size. */
#else /* Word 0 - Little Endian */
        uint32_t ps                    : 32; /**< [ 31:  0](R/W) System page size. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg102_s cn; */
} bdk_pcieepx_cfg102_t;

static inline uint64_t BDK_PCIEEPX_CFG102(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG102(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000198ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG102", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG102(a) bdk_pcieepx_cfg102_t
#define bustype_BDK_PCIEEPX_CFG102(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG102(a) "PCIEEPX_CFG102"
#define busnum_BDK_PCIEEPX_CFG102(a) (a)
#define arguments_BDK_PCIEEPX_CFG102(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg103
 *
 * PCI Express SR-IOV BAR 0 Register
 * This register contains the one hundred fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg103_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 12; /**< [ 31: 20](R/W) Lower bits of the VF BAR 0 base address. */
        uint32_t reserved_4_19         : 16;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO) BAR type:
                                                                 0x0 = 32-bit BAR.
                                                                 0x2 = 64-bit BAR. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator:
                                                                 0 = BAR 0 is a memory BAR.
                                                                 1 = BAR 0 is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator:
                                                                 0 = BAR 0 is a memory BAR.
                                                                 1 = BAR 0 is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO) BAR type:
                                                                 0x0 = 32-bit BAR.
                                                                 0x2 = 64-bit BAR. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_19         : 16;
        uint32_t lbab                  : 12; /**< [ 31: 20](R/W) Lower bits of the VF BAR 0 base address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg103_s cn; */
} bdk_pcieepx_cfg103_t;

static inline uint64_t BDK_PCIEEPX_CFG103(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG103(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000019cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG103", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG103(a) bdk_pcieepx_cfg103_t
#define bustype_BDK_PCIEEPX_CFG103(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG103(a) "PCIEEPX_CFG103"
#define busnum_BDK_PCIEEPX_CFG103(a) (a)
#define arguments_BDK_PCIEEPX_CFG103(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg104
 *
 * PCI Express SR-IOV BAR 1 Register
 * This register contains the one hundred seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg104_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W) Upper bits of the VF BAR 0 base address. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W) Upper bits of the VF BAR 0 base address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg104_s cn; */
} bdk_pcieepx_cfg104_t;

static inline uint64_t BDK_PCIEEPX_CFG104(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG104(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000001a0ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG104", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG104(a) bdk_pcieepx_cfg104_t
#define bustype_BDK_PCIEEPX_CFG104(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG104(a) "PCIEEPX_CFG104"
#define busnum_BDK_PCIEEPX_CFG104(a) (a)
#define arguments_BDK_PCIEEPX_CFG104(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg105
 *
 * PCI Express SR-IOV BAR 2 Register
 * This register contains the one hundred sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg105_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg105_s cn; */
} bdk_pcieepx_cfg105_t;

static inline uint64_t BDK_PCIEEPX_CFG105(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG105(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000001a4ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG105", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG105(a) bdk_pcieepx_cfg105_t
#define bustype_BDK_PCIEEPX_CFG105(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG105(a) "PCIEEPX_CFG105"
#define busnum_BDK_PCIEEPX_CFG105(a) (a)
#define arguments_BDK_PCIEEPX_CFG105(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg106
 *
 * PCI Express SR-IOV BAR 3 Register
 * This register contains the one hundred seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg106_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg106_s cn; */
} bdk_pcieepx_cfg106_t;

static inline uint64_t BDK_PCIEEPX_CFG106(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG106(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000001a8ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG106", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG106(a) bdk_pcieepx_cfg106_t
#define bustype_BDK_PCIEEPX_CFG106(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG106(a) "PCIEEPX_CFG106"
#define busnum_BDK_PCIEEPX_CFG106(a) (a)
#define arguments_BDK_PCIEEPX_CFG106(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg107
 *
 * PCI Express SR-IOV BAR 4 Register
 * This register contains the one hundred eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg107_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg107_s cn; */
} bdk_pcieepx_cfg107_t;

static inline uint64_t BDK_PCIEEPX_CFG107(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG107(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000001acll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG107", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG107(a) bdk_pcieepx_cfg107_t
#define bustype_BDK_PCIEEPX_CFG107(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG107(a) "PCIEEPX_CFG107"
#define busnum_BDK_PCIEEPX_CFG107(a) (a)
#define arguments_BDK_PCIEEPX_CFG107(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg108
 *
 * PCI Express SR-IOV BAR 5 Register
 * This register contains the one hundred ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg108_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg108_s cn; */
} bdk_pcieepx_cfg108_t;

static inline uint64_t BDK_PCIEEPX_CFG108(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG108(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000001b0ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG108", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG108(a) bdk_pcieepx_cfg108_t
#define bustype_BDK_PCIEEPX_CFG108(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG108(a) "PCIEEPX_CFG108"
#define busnum_BDK_PCIEEPX_CFG108(a) (a)
#define arguments_BDK_PCIEEPX_CFG108(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg109
 *
 * PCI Express SR-IOV Migration State Array Offset Register
 * This register contains the one hundred tenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg109_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t mso                   : 29; /**< [ 31:  3](RO) VF migration state offset. */
        uint32_t msbir                 : 3;  /**< [  2:  0](RO) VF migration state BIR. */
#else /* Word 0 - Little Endian */
        uint32_t msbir                 : 3;  /**< [  2:  0](RO) VF migration state BIR. */
        uint32_t mso                   : 29; /**< [ 31:  3](RO) VF migration state offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg109_s cn; */
} bdk_pcieepx_cfg109_t;

static inline uint64_t BDK_PCIEEPX_CFG109(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG109(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000001b4ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG109", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG109(a) bdk_pcieepx_cfg109_t
#define bustype_BDK_PCIEEPX_CFG109(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG109(a) "PCIEEPX_CFG109"
#define busnum_BDK_PCIEEPX_CFG109(a) (a)
#define arguments_BDK_PCIEEPX_CFG109(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg110
 *
 * PCI Express Resizable BAR (RBAR) Capability Header Register
 * This register contains the one hundred eleventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg110_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCI Express extended capability. */
#else /* Word 0 - Little Endian */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCI Express extended capability. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg110_s cn; */
} bdk_pcieepx_cfg110_t;

static inline uint64_t BDK_PCIEEPX_CFG110(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG110(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000001b8ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG110", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG110(a) bdk_pcieepx_cfg110_t
#define bustype_BDK_PCIEEPX_CFG110(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG110(a) "PCIEEPX_CFG110"
#define busnum_BDK_PCIEEPX_CFG110(a) (a)
#define arguments_BDK_PCIEEPX_CFG110(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg111
 *
 * PCI Express Resizable BAR (RBAR) Capability Register
 * This register contains the one hundred twelfth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg111_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_30_31        : 2;
        uint32_t srs                   : 26; /**< [ 29:  4](RO/WRSL) "Supported resource sizes. PEM advertises the maximum allowable BAR size (512 GB -
                                                                 0xF_FFFF) when the fus__bar2_size_conf is in tact. When the fuse is blown, the CNXXXX
                                                                 advertises a BAR size of 32TB (0x3FF_FFFF). The BAR is disabled at runtime by writing all
                                                                 zeros through PEM()_CFG_WR to this field." */
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t srs                   : 26; /**< [ 29:  4](RO/WRSL) "Supported resource sizes. PEM advertises the maximum allowable BAR size (512 GB -
                                                                 0xF_FFFF) when the fus__bar2_size_conf is in tact. When the fuse is blown, the CNXXXX
                                                                 advertises a BAR size of 32TB (0x3FF_FFFF). The BAR is disabled at runtime by writing all
                                                                 zeros through PEM()_CFG_WR to this field." */
        uint32_t reserved_30_31        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg111_s cn; */
} bdk_pcieepx_cfg111_t;

static inline uint64_t BDK_PCIEEPX_CFG111(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG111(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000001bcll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG111", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG111(a) bdk_pcieepx_cfg111_t
#define bustype_BDK_PCIEEPX_CFG111(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG111(a) "PCIEEPX_CFG111"
#define busnum_BDK_PCIEEPX_CFG111(a) (a)
#define arguments_BDK_PCIEEPX_CFG111(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg112
 *
 * PCI Express Resizable BAR (RBAR) Control Register
 * This register contains the one hundred thirteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg112_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_13_31        : 19;
        uint32_t rbars                 : 5;  /**< [ 12:  8](R/W) BAR Size. PEM advertises the minimum allowable BAR size of 0x0 (1MB) but will accept
                                                                 values as large as 0x19 (32TB). */
        uint32_t nrbar                 : 3;  /**< [  7:  5](RO) Number of resizable BARs */
        uint32_t reserved_3_4          : 2;
        uint32_t rbari                 : 3;  /**< [  2:  0](RO) BAR Index. Points to BAR2. */
#else /* Word 0 - Little Endian */
        uint32_t rbari                 : 3;  /**< [  2:  0](RO) BAR Index. Points to BAR2. */
        uint32_t reserved_3_4          : 2;
        uint32_t nrbar                 : 3;  /**< [  7:  5](RO) Number of resizable BARs */
        uint32_t rbars                 : 5;  /**< [ 12:  8](R/W) BAR Size. PEM advertises the minimum allowable BAR size of 0x0 (1MB) but will accept
                                                                 values as large as 0x19 (32TB). */
        uint32_t reserved_13_31        : 19;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg112_s cn; */
} bdk_pcieepx_cfg112_t;

static inline uint64_t BDK_PCIEEPX_CFG112(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG112(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000001c0ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG112", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG112(a) bdk_pcieepx_cfg112_t
#define bustype_BDK_PCIEEPX_CFG112(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG112(a) "PCIEEPX_CFG112"
#define busnum_BDK_PCIEEPX_CFG112(a) (a)
#define arguments_BDK_PCIEEPX_CFG112(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg448
 *
 * Ack Latency Timer/Replay Timer Register
 * This register contains the four hundred forty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg448_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t rtl                   : 16; /**< [ 31: 16](R/W/H) Replay time limit. The replay timer expires when it reaches this limit. The PCI Express
                                                                 bus initiates a replay upon reception of a nak or when the replay timer expires. This
                                                                 value is set correctly by the hardware out of reset or when the negotiated link width or
                                                                 payload size changes. If the user changes this value through a CSR write or by an EEPROM
                                                                 load, they should refer to the PCIe specification for the correct value. */
        uint32_t rtltl                 : 16; /**< [ 15:  0](R/W/H) Round trip latency time limit. The ack/nak latency timer expires when it reaches this
                                                                 limit. This value is set correctly by the hardware out of reset or when the negotiated
                                                                 link width or payload size changes. If the user changes this value through a CSR write or
                                                                 by an EEPROM load, they should refer to the PCIe specification for the correct value. */
#else /* Word 0 - Little Endian */
        uint32_t rtltl                 : 16; /**< [ 15:  0](R/W/H) Round trip latency time limit. The ack/nak latency timer expires when it reaches this
                                                                 limit. This value is set correctly by the hardware out of reset or when the negotiated
                                                                 link width or payload size changes. If the user changes this value through a CSR write or
                                                                 by an EEPROM load, they should refer to the PCIe specification for the correct value. */
        uint32_t rtl                   : 16; /**< [ 31: 16](R/W/H) Replay time limit. The replay timer expires when it reaches this limit. The PCI Express
                                                                 bus initiates a replay upon reception of a nak or when the replay timer expires. This
                                                                 value is set correctly by the hardware out of reset or when the negotiated link width or
                                                                 payload size changes. If the user changes this value through a CSR write or by an EEPROM
                                                                 load, they should refer to the PCIe specification for the correct value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg448_s cn; */
} bdk_pcieepx_cfg448_t;

static inline uint64_t BDK_PCIEEPX_CFG448(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG448(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000700ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG448", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG448(a) bdk_pcieepx_cfg448_t
#define bustype_BDK_PCIEEPX_CFG448(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG448(a) "PCIEEPX_CFG448"
#define busnum_BDK_PCIEEPX_CFG448(a) (a)
#define arguments_BDK_PCIEEPX_CFG448(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg449
 *
 * Other Message Register
 * This register contains the four hundred fiftieth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg449_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t omr                   : 32; /**< [ 31:  0](R/W) Other message register. This register can be used for either of the following purposes:

                                                                 * To send a specific PCI Express message, the application writes the payload of the
                                                                 message into this register, then sets bit 0 of the port link control register to send the
                                                                 message.

                                                                 * To store a corruption pattern for corrupting the LCRC on all TLPs, the application
                                                                 places a 32-bit corruption pattern into this register and enables this function by setting
                                                                 bit 25 of the port link control register. When enabled, the transmit LCRC result is XORed
                                                                 with this pattern before inserting it into the packet. */
#else /* Word 0 - Little Endian */
        uint32_t omr                   : 32; /**< [ 31:  0](R/W) Other message register. This register can be used for either of the following purposes:

                                                                 * To send a specific PCI Express message, the application writes the payload of the
                                                                 message into this register, then sets bit 0 of the port link control register to send the
                                                                 message.

                                                                 * To store a corruption pattern for corrupting the LCRC on all TLPs, the application
                                                                 places a 32-bit corruption pattern into this register and enables this function by setting
                                                                 bit 25 of the port link control register. When enabled, the transmit LCRC result is XORed
                                                                 with this pattern before inserting it into the packet. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg449_s cn; */
} bdk_pcieepx_cfg449_t;

static inline uint64_t BDK_PCIEEPX_CFG449(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG449(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000704ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG449", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG449(a) bdk_pcieepx_cfg449_t
#define bustype_BDK_PCIEEPX_CFG449(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG449(a) "PCIEEPX_CFG449"
#define busnum_BDK_PCIEEPX_CFG449(a) (a)
#define arguments_BDK_PCIEEPX_CFG449(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg450
 *
 * Port Force Link Register
 * This register contains the four hundred fifty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg450_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lpec                  : 8;  /**< [ 31: 24](R/W) Low power entrance count. The power management state waits this many clock cycles for the
                                                                 associated completion of a CfgWr to PCIEEP()_CFG017 register, power state (PS) field
                                                                 register
                                                                 to go low-power. This register is intended for applications that do not let the PCI
                                                                 Express bus handle a completion for configuration request to the power management control
                                                                 and status (PCIEP()_CFG017) register. */
        uint32_t reserved_22_23        : 2;
        uint32_t link_state            : 6;  /**< [ 21: 16](R/W) Link state. The link state that the PCI Express bus is forced to when bit 15 (force link)
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
        uint32_t force_link            : 1;  /**< [ 15: 15](WO/H) Force link. Forces the link to the state specified by the LINK_STATE field. The force link
                                                                 pulse triggers link renegotiation.
                                                                 As the force link is a pulse, writing a 1 to it does trigger the forced link state event,
                                                                 even though reading it always returns a 0. */
        uint32_t reserved_8_14         : 7;
        uint32_t link_num              : 8;  /**< [  7:  0](RO/H) Link number. Not used for endpoint. */
#else /* Word 0 - Little Endian */
        uint32_t link_num              : 8;  /**< [  7:  0](RO/H) Link number. Not used for endpoint. */
        uint32_t reserved_8_14         : 7;
        uint32_t force_link            : 1;  /**< [ 15: 15](WO/H) Force link. Forces the link to the state specified by the LINK_STATE field. The force link
                                                                 pulse triggers link renegotiation.
                                                                 As the force link is a pulse, writing a 1 to it does trigger the forced link state event,
                                                                 even though reading it always returns a 0. */
        uint32_t link_state            : 6;  /**< [ 21: 16](R/W) Link state. The link state that the PCI Express bus is forced to when bit 15 (force link)
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
        uint32_t reserved_22_23        : 2;
        uint32_t lpec                  : 8;  /**< [ 31: 24](R/W) Low power entrance count. The power management state waits this many clock cycles for the
                                                                 associated completion of a CfgWr to PCIEEP()_CFG017 register, power state (PS) field
                                                                 register
                                                                 to go low-power. This register is intended for applications that do not let the PCI
                                                                 Express bus handle a completion for configuration request to the power management control
                                                                 and status (PCIEP()_CFG017) register. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg450_s cn; */
} bdk_pcieepx_cfg450_t;

static inline uint64_t BDK_PCIEEPX_CFG450(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG450(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000708ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG450", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG450(a) bdk_pcieepx_cfg450_t
#define bustype_BDK_PCIEEPX_CFG450(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG450(a) "PCIEEPX_CFG450"
#define busnum_BDK_PCIEEPX_CFG450(a) (a)
#define arguments_BDK_PCIEEPX_CFG450(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg451
 *
 * Ack Frequency Register
 * This register contains the four hundred fifty-second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg451_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t easpml1               : 1;  /**< [ 30: 30](R/W/H) Enter ASPM L1 without receive in L0s. Allow core to enter ASPM L1 even when link partner
                                                                 did not go to L0s (receive is not in L0s). When not set, core goes to ASPM L1 only after
                                                                 idle period, during which both receive and transmit are in L0s. */
        uint32_t l1el                  : 3;  /**< [ 29: 27](R/W) L1 entrance latency. Values correspond to:
                                                                 0x0 = 1 ms.
                                                                 0x1 = 2 ms.
                                                                 0x2 = 4 ms.
                                                                 0x3 = 8 ms.
                                                                 0x4 = 16 ms.
                                                                 0x5 = 32 ms.
                                                                 0x6 or 0x7 = 64 ms. */
        uint32_t l0el                  : 3;  /**< [ 26: 24](R/W) L0s entrance latency. Values correspond to:
                                                                 0x0 = 1 ms.
                                                                 0x1 = 2 ms.
                                                                 0x2 = 3 ms.
                                                                 0x3 = 4 ms.
                                                                 0x4 = 5 ms.
                                                                 0x5 = 6 ms.
                                                                 0x6 or 0x7 = 7 ms. */
        uint32_t n_fts_cc              : 8;  /**< [ 23: 16](R/W) N_FTS when common clock is used.
                                                                 The number of fast training sequence (FTS) ordered sets to be transmitted when
                                                                 transitioning from L0s to L0. The maximum number of FTS ordered sets that a component can
                                                                 request is 255.
                                                                 A value of zero is not supported; a value of zero can cause the LTSSM to go into the
                                                                 recovery state when exiting from L0s. */
        uint32_t n_fts                 : 8;  /**< [ 15:  8](R/W) N_FTS. The number of fast training sequence (FTS) ordered sets to be transmitted when
                                                                 transitioning from L0s to L0. The maximum number of FTS ordered sets that a component can
                                                                 request is 255.
                                                                 A value of zero is not supported; a value of zero can cause the LTSSM to go into the
                                                                 recovery state when exiting from L0s. */
        uint32_t ack_freq              : 8;  /**< [  7:  0](R/W) Ack frequency. The number of pending Acks specified here (up to 255) before sending an Ack. */
#else /* Word 0 - Little Endian */
        uint32_t ack_freq              : 8;  /**< [  7:  0](R/W) Ack frequency. The number of pending Acks specified here (up to 255) before sending an Ack. */
        uint32_t n_fts                 : 8;  /**< [ 15:  8](R/W) N_FTS. The number of fast training sequence (FTS) ordered sets to be transmitted when
                                                                 transitioning from L0s to L0. The maximum number of FTS ordered sets that a component can
                                                                 request is 255.
                                                                 A value of zero is not supported; a value of zero can cause the LTSSM to go into the
                                                                 recovery state when exiting from L0s. */
        uint32_t n_fts_cc              : 8;  /**< [ 23: 16](R/W) N_FTS when common clock is used.
                                                                 The number of fast training sequence (FTS) ordered sets to be transmitted when
                                                                 transitioning from L0s to L0. The maximum number of FTS ordered sets that a component can
                                                                 request is 255.
                                                                 A value of zero is not supported; a value of zero can cause the LTSSM to go into the
                                                                 recovery state when exiting from L0s. */
        uint32_t l0el                  : 3;  /**< [ 26: 24](R/W) L0s entrance latency. Values correspond to:
                                                                 0x0 = 1 ms.
                                                                 0x1 = 2 ms.
                                                                 0x2 = 3 ms.
                                                                 0x3 = 4 ms.
                                                                 0x4 = 5 ms.
                                                                 0x5 = 6 ms.
                                                                 0x6 or 0x7 = 7 ms. */
        uint32_t l1el                  : 3;  /**< [ 29: 27](R/W) L1 entrance latency. Values correspond to:
                                                                 0x0 = 1 ms.
                                                                 0x1 = 2 ms.
                                                                 0x2 = 4 ms.
                                                                 0x3 = 8 ms.
                                                                 0x4 = 16 ms.
                                                                 0x5 = 32 ms.
                                                                 0x6 or 0x7 = 64 ms. */
        uint32_t easpml1               : 1;  /**< [ 30: 30](R/W/H) Enter ASPM L1 without receive in L0s. Allow core to enter ASPM L1 even when link partner
                                                                 did not go to L0s (receive is not in L0s). When not set, core goes to ASPM L1 only after
                                                                 idle period, during which both receive and transmit are in L0s. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg451_s cn; */
} bdk_pcieepx_cfg451_t;

static inline uint64_t BDK_PCIEEPX_CFG451(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG451(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000070cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG451", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG451(a) bdk_pcieepx_cfg451_t
#define bustype_BDK_PCIEEPX_CFG451(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG451(a) "PCIEEPX_CFG451"
#define busnum_BDK_PCIEEPX_CFG451(a) (a)
#define arguments_BDK_PCIEEPX_CFG451(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg452
 *
 * Port Link Control Register
 * This register contains the four hundred fifty-third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg452_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_22_31        : 10;
        uint32_t lme                   : 6;  /**< [ 21: 16](R/W) Link mode enable set as follows:
                                                                 0x1 = x1.
                                                                 0x3 = x2.
                                                                 0x7 = x4.
                                                                 0xF = x8.
                                                                 0x1F = x16 (not supported).
                                                                 0x3F = x32 (not supported).

                                                                 This field indicates the maximum number of lanes supported by the PCIe port. The value can
                                                                 be set less than 0xF to limit the number of lanes that the PCIe will attempt to use. If
                                                                 the value of 0xF set by the hardware is not desired, this field can be programmed to a
                                                                 smaller value (i.e. EEPROM). See also PCIEEP()_CFG031[MLW].
                                                                 The value of this field does not indicate the number of lanes in use by the PCIe. This
                                                                 field sets the maximum number of lanes in the PCIe core that could be used. As per the
                                                                 PCIe specification, the PCIe core can negotiate a smaller link width, so all of x8, x4,
                                                                 x2, and x1 are supported when
                                                                 LME = 0xF, for example. */
        uint32_t reserved_12_15        : 4;
        uint32_t link_rate             : 4;  /**< [ 11:  8](RO/H) Reserved. */
        uint32_t flm                   : 1;  /**< [  7:  7](R/W/H) Fast link mode. Sets all internal timers to fast mode for simulation purposes. If during
                                                                 an EEPROM load, the first word loaded is 0xFFFFFFFF, the EEPROM load is terminated and
                                                                 this bit is set. */
        uint32_t reserved_6            : 1;
        uint32_t dllle                 : 1;  /**< [  5:  5](R/W) DLL link enable. Enables link initialization. If DLL link enable = 0, the PCI Express bus
                                                                 does not transmit InitFC DLLPs and does not establish a link. */
        uint32_t reserved_4            : 1;
        uint32_t ra                    : 1;  /**< [  3:  3](R/W) Reset assert. Triggers a recovery and forces the LTSSM to the hot reset state (downstream
                                                                 port only). */
        uint32_t le                    : 1;  /**< [  2:  2](R/W) Loopback enable. Initiate loopback mode as a master. On a 0->1 transition, the PCIe core
                                                                 sends TS ordered sets with the loopback bit set to cause the link partner to enter into
                                                                 loopback mode as a slave. Normal transmission is not possible when LE=1. To exit loopback
                                                                 mode, take the link through a reset sequence. */
        uint32_t sd                    : 1;  /**< [  1:  1](R/W) Scramble disable. Setting this bit turns off data scrambling. */
        uint32_t omr                   : 1;  /**< [  0:  0](WO/H) Other message request. When software writes a 1 to this bit, the PCI Express bus transmits
                                                                 the message contained in the other message register. */
#else /* Word 0 - Little Endian */
        uint32_t omr                   : 1;  /**< [  0:  0](WO/H) Other message request. When software writes a 1 to this bit, the PCI Express bus transmits
                                                                 the message contained in the other message register. */
        uint32_t sd                    : 1;  /**< [  1:  1](R/W) Scramble disable. Setting this bit turns off data scrambling. */
        uint32_t le                    : 1;  /**< [  2:  2](R/W) Loopback enable. Initiate loopback mode as a master. On a 0->1 transition, the PCIe core
                                                                 sends TS ordered sets with the loopback bit set to cause the link partner to enter into
                                                                 loopback mode as a slave. Normal transmission is not possible when LE=1. To exit loopback
                                                                 mode, take the link through a reset sequence. */
        uint32_t ra                    : 1;  /**< [  3:  3](R/W) Reset assert. Triggers a recovery and forces the LTSSM to the hot reset state (downstream
                                                                 port only). */
        uint32_t reserved_4            : 1;
        uint32_t dllle                 : 1;  /**< [  5:  5](R/W) DLL link enable. Enables link initialization. If DLL link enable = 0, the PCI Express bus
                                                                 does not transmit InitFC DLLPs and does not establish a link. */
        uint32_t reserved_6            : 1;
        uint32_t flm                   : 1;  /**< [  7:  7](R/W/H) Fast link mode. Sets all internal timers to fast mode for simulation purposes. If during
                                                                 an EEPROM load, the first word loaded is 0xFFFFFFFF, the EEPROM load is terminated and
                                                                 this bit is set. */
        uint32_t link_rate             : 4;  /**< [ 11:  8](RO/H) Reserved. */
        uint32_t reserved_12_15        : 4;
        uint32_t lme                   : 6;  /**< [ 21: 16](R/W) Link mode enable set as follows:
                                                                 0x1 = x1.
                                                                 0x3 = x2.
                                                                 0x7 = x4.
                                                                 0xF = x8.
                                                                 0x1F = x16 (not supported).
                                                                 0x3F = x32 (not supported).

                                                                 This field indicates the maximum number of lanes supported by the PCIe port. The value can
                                                                 be set less than 0xF to limit the number of lanes that the PCIe will attempt to use. If
                                                                 the value of 0xF set by the hardware is not desired, this field can be programmed to a
                                                                 smaller value (i.e. EEPROM). See also PCIEEP()_CFG031[MLW].
                                                                 The value of this field does not indicate the number of lanes in use by the PCIe. This
                                                                 field sets the maximum number of lanes in the PCIe core that could be used. As per the
                                                                 PCIe specification, the PCIe core can negotiate a smaller link width, so all of x8, x4,
                                                                 x2, and x1 are supported when
                                                                 LME = 0xF, for example. */
        uint32_t reserved_22_31        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg452_s cn; */
} bdk_pcieepx_cfg452_t;

static inline uint64_t BDK_PCIEEPX_CFG452(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG452(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000710ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG452", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG452(a) bdk_pcieepx_cfg452_t
#define bustype_BDK_PCIEEPX_CFG452(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG452(a) "PCIEEPX_CFG452"
#define busnum_BDK_PCIEEPX_CFG452(a) (a)
#define arguments_BDK_PCIEEPX_CFG452(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg453
 *
 * Lane Skew Register
 * This register contains the four hundred fifty-fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg453_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t dlld                  : 1;  /**< [ 31: 31](R/W) Disable lane-to-lane deskew. Disables the internal lane-to-lane deskew logic. */
        uint32_t reserved_26_30        : 5;
        uint32_t ack_nak               : 1;  /**< [ 25: 25](R/W) Ack/Nak disable. Prevents the PCI Express bus from sending Ack and Nak DLLPs. */
        uint32_t fcd                   : 1;  /**< [ 24: 24](R/W) Flow control disable. Prevents the PCI Express bus from sending FC DLLPs. */
        uint32_t ilst                  : 24; /**< [ 23:  0](R/W) Insert lane skew for transmit. Causes skew between lanes for test purposes. There are
                                                                 three bits per lane. The value is in units of one symbol time. For example, the value 010b
                                                                 for a lane forces a skew of two symbol times for that lane. The maximum skew value for any
                                                                 lane is 5 symbol times. */
#else /* Word 0 - Little Endian */
        uint32_t ilst                  : 24; /**< [ 23:  0](R/W) Insert lane skew for transmit. Causes skew between lanes for test purposes. There are
                                                                 three bits per lane. The value is in units of one symbol time. For example, the value 010b
                                                                 for a lane forces a skew of two symbol times for that lane. The maximum skew value for any
                                                                 lane is 5 symbol times. */
        uint32_t fcd                   : 1;  /**< [ 24: 24](R/W) Flow control disable. Prevents the PCI Express bus from sending FC DLLPs. */
        uint32_t ack_nak               : 1;  /**< [ 25: 25](R/W) Ack/Nak disable. Prevents the PCI Express bus from sending Ack and Nak DLLPs. */
        uint32_t reserved_26_30        : 5;
        uint32_t dlld                  : 1;  /**< [ 31: 31](R/W) Disable lane-to-lane deskew. Disables the internal lane-to-lane deskew logic. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg453_s cn; */
} bdk_pcieepx_cfg453_t;

static inline uint64_t BDK_PCIEEPX_CFG453(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG453(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000714ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG453", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG453(a) bdk_pcieepx_cfg453_t
#define bustype_BDK_PCIEEPX_CFG453(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG453(a) "PCIEEPX_CFG453"
#define busnum_BDK_PCIEEPX_CFG453(a) (a)
#define arguments_BDK_PCIEEPX_CFG453(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg454
 *
 * Symbol Number Register
 * This register contains the four hundred fifty-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg454_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_29_31        : 3;
        uint32_t tmfcwt                : 5;  /**< [ 28: 24](R/W) Used to be 'timer modifier for flow control watchdog timer.' This field is no longer used.
                                                                 and has moved to the queue status register -- PCIEEP()_CFG463. This field remains to
                                                                 prevent software from breaking. */
        uint32_t tmanlt                : 5;  /**< [ 23: 19](R/W) Timer modifier for Ack/Nak latency timer. Increases the timer value for the Ack/Nak
                                                                 latency timer, in increments of 64 clock cycles. */
        uint32_t tmrt                  : 5;  /**< [ 18: 14](R/W) Timer modifier for replay timer. Increases the timer value for the replay timer, in
                                                                 increments of 64 clock cycles. */
        uint32_t reserved_8_13         : 6;
        uint32_t mfuncn                : 8;  /**< [  7:  0](R/W) Max number of functions supported. Used for SR-IOV. */
#else /* Word 0 - Little Endian */
        uint32_t mfuncn                : 8;  /**< [  7:  0](R/W) Max number of functions supported. Used for SR-IOV. */
        uint32_t reserved_8_13         : 6;
        uint32_t tmrt                  : 5;  /**< [ 18: 14](R/W) Timer modifier for replay timer. Increases the timer value for the replay timer, in
                                                                 increments of 64 clock cycles. */
        uint32_t tmanlt                : 5;  /**< [ 23: 19](R/W) Timer modifier for Ack/Nak latency timer. Increases the timer value for the Ack/Nak
                                                                 latency timer, in increments of 64 clock cycles. */
        uint32_t tmfcwt                : 5;  /**< [ 28: 24](R/W) Used to be 'timer modifier for flow control watchdog timer.' This field is no longer used.
                                                                 and has moved to the queue status register -- PCIEEP()_CFG463. This field remains to
                                                                 prevent software from breaking. */
        uint32_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg454_s cn; */
} bdk_pcieepx_cfg454_t;

static inline uint64_t BDK_PCIEEPX_CFG454(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG454(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000718ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG454", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG454(a) bdk_pcieepx_cfg454_t
#define bustype_BDK_PCIEEPX_CFG454(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG454(a) "PCIEEPX_CFG454"
#define busnum_BDK_PCIEEPX_CFG454(a) (a)
#define arguments_BDK_PCIEEPX_CFG454(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg455
 *
 * Symbol Timer/Filter Mask Register 1
 * This register contains the four hundred fifty-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg455_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t m_cfg0_filt           : 1;  /**< [ 31: 31](R/W) Mask filtering of received configuration requests (RC mode only). */
        uint32_t m_io_filt             : 1;  /**< [ 30: 30](R/W) Mask filtering of received I/O requests (RC mode only). */
        uint32_t msg_ctrl              : 1;  /**< [ 29: 29](R/W) Message control. The application must not change this field. */
        uint32_t m_cpl_ecrc_filt       : 1;  /**< [ 28: 28](R/W) Mask ECRC error filtering for completions. */
        uint32_t m_ecrc_filt           : 1;  /**< [ 27: 27](R/W) Mask ECRC error filtering. */
        uint32_t m_cpl_len_err         : 1;  /**< [ 26: 26](R/W) Mask length mismatch error for received completions. */
        uint32_t m_cpl_attr_err        : 1;  /**< [ 25: 25](R/W) Mask attributes mismatch error for received completions. */
        uint32_t m_cpl_tc_err          : 1;  /**< [ 24: 24](R/W) Mask traffic class mismatch error for received completions. */
        uint32_t m_cpl_fun_err         : 1;  /**< [ 23: 23](R/W) Mask function mismatch error for received completions. */
        uint32_t m_cpl_rid_err         : 1;  /**< [ 22: 22](R/W) Mask requester ID mismatch error for received completions. */
        uint32_t m_cpl_tag_err         : 1;  /**< [ 21: 21](R/W) Mask tag error rules for received completions. */
        uint32_t m_lk_filt             : 1;  /**< [ 20: 20](R/W) Mask locked request filtering. */
        uint32_t m_cfg1_filt           : 1;  /**< [ 19: 19](R/W) Mask type 1 configuration request filtering. */
        uint32_t m_bar_match           : 1;  /**< [ 18: 18](R/W) Mask BAR match filtering. */
        uint32_t m_pois_filt           : 1;  /**< [ 17: 17](R/W) Mask poisoned TLP filtering. */
        uint32_t m_fun                 : 1;  /**< [ 16: 16](R/W) Mask function. */
        uint32_t dfcwt                 : 1;  /**< [ 15: 15](R/W) Disable FC watchdog timer. */
        uint32_t reserved_11_14        : 4;
        uint32_t skpiv                 : 11; /**< [ 10:  0](R/W) SKP interval value. */
#else /* Word 0 - Little Endian */
        uint32_t skpiv                 : 11; /**< [ 10:  0](R/W) SKP interval value. */
        uint32_t reserved_11_14        : 4;
        uint32_t dfcwt                 : 1;  /**< [ 15: 15](R/W) Disable FC watchdog timer. */
        uint32_t m_fun                 : 1;  /**< [ 16: 16](R/W) Mask function. */
        uint32_t m_pois_filt           : 1;  /**< [ 17: 17](R/W) Mask poisoned TLP filtering. */
        uint32_t m_bar_match           : 1;  /**< [ 18: 18](R/W) Mask BAR match filtering. */
        uint32_t m_cfg1_filt           : 1;  /**< [ 19: 19](R/W) Mask type 1 configuration request filtering. */
        uint32_t m_lk_filt             : 1;  /**< [ 20: 20](R/W) Mask locked request filtering. */
        uint32_t m_cpl_tag_err         : 1;  /**< [ 21: 21](R/W) Mask tag error rules for received completions. */
        uint32_t m_cpl_rid_err         : 1;  /**< [ 22: 22](R/W) Mask requester ID mismatch error for received completions. */
        uint32_t m_cpl_fun_err         : 1;  /**< [ 23: 23](R/W) Mask function mismatch error for received completions. */
        uint32_t m_cpl_tc_err          : 1;  /**< [ 24: 24](R/W) Mask traffic class mismatch error for received completions. */
        uint32_t m_cpl_attr_err        : 1;  /**< [ 25: 25](R/W) Mask attributes mismatch error for received completions. */
        uint32_t m_cpl_len_err         : 1;  /**< [ 26: 26](R/W) Mask length mismatch error for received completions. */
        uint32_t m_ecrc_filt           : 1;  /**< [ 27: 27](R/W) Mask ECRC error filtering. */
        uint32_t m_cpl_ecrc_filt       : 1;  /**< [ 28: 28](R/W) Mask ECRC error filtering for completions. */
        uint32_t msg_ctrl              : 1;  /**< [ 29: 29](R/W) Message control. The application must not change this field. */
        uint32_t m_io_filt             : 1;  /**< [ 30: 30](R/W) Mask filtering of received I/O requests (RC mode only). */
        uint32_t m_cfg0_filt           : 1;  /**< [ 31: 31](R/W) Mask filtering of received configuration requests (RC mode only). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg455_s cn; */
} bdk_pcieepx_cfg455_t;

static inline uint64_t BDK_PCIEEPX_CFG455(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG455(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000071cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG455", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG455(a) bdk_pcieepx_cfg455_t
#define bustype_BDK_PCIEEPX_CFG455(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG455(a) "PCIEEPX_CFG455"
#define busnum_BDK_PCIEEPX_CFG455(a) (a)
#define arguments_BDK_PCIEEPX_CFG455(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg456
 *
 * Filter Mask Register 2
 * This register contains the four hundred fifty-seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg456_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_4_31         : 28;
        uint32_t m_handle_flush        : 1;  /**< [  3:  3](R/W) Mask core filter to handle flush request. */
        uint32_t m_dabort_4ucpl        : 1;  /**< [  2:  2](R/W) Mask DLLP abort for unexpected CPL. */
        uint32_t m_vend1_drp           : 1;  /**< [  1:  1](R/W) Mask vendor MSG type 1 dropped silently. */
        uint32_t m_vend0_drp           : 1;  /**< [  0:  0](R/W) Mask vendor MSG type 0 dropped with UR error reporting. */
#else /* Word 0 - Little Endian */
        uint32_t m_vend0_drp           : 1;  /**< [  0:  0](R/W) Mask vendor MSG type 0 dropped with UR error reporting. */
        uint32_t m_vend1_drp           : 1;  /**< [  1:  1](R/W) Mask vendor MSG type 1 dropped silently. */
        uint32_t m_dabort_4ucpl        : 1;  /**< [  2:  2](R/W) Mask DLLP abort for unexpected CPL. */
        uint32_t m_handle_flush        : 1;  /**< [  3:  3](R/W) Mask core filter to handle flush request. */
        uint32_t reserved_4_31         : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg456_s cn; */
} bdk_pcieepx_cfg456_t;

static inline uint64_t BDK_PCIEEPX_CFG456(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG456(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000720ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG456", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG456(a) bdk_pcieepx_cfg456_t
#define bustype_BDK_PCIEEPX_CFG456(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG456(a) "PCIEEPX_CFG456"
#define busnum_BDK_PCIEEPX_CFG456(a) (a)
#define arguments_BDK_PCIEEPX_CFG456(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg458
 *
 * Debug Register 0
 * This register contains the four hundred fifty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg458_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t dbg_info_l32          : 32; /**< [ 31:  0](RO/H) Debug info lower 32 bits. */
#else /* Word 0 - Little Endian */
        uint32_t dbg_info_l32          : 32; /**< [ 31:  0](RO/H) Debug info lower 32 bits. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg458_s cn; */
} bdk_pcieepx_cfg458_t;

static inline uint64_t BDK_PCIEEPX_CFG458(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG458(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000728ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG458", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG458(a) bdk_pcieepx_cfg458_t
#define bustype_BDK_PCIEEPX_CFG458(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG458(a) "PCIEEPX_CFG458"
#define busnum_BDK_PCIEEPX_CFG458(a) (a)
#define arguments_BDK_PCIEEPX_CFG458(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg459
 *
 * Debug Register 1
 * This register contains the four hundred sixtieth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg459_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t dbg_info_u32          : 32; /**< [ 31:  0](RO/H) Debug info upper 32 bits. */
#else /* Word 0 - Little Endian */
        uint32_t dbg_info_u32          : 32; /**< [ 31:  0](RO/H) Debug info upper 32 bits. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg459_s cn; */
} bdk_pcieepx_cfg459_t;

static inline uint64_t BDK_PCIEEPX_CFG459(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG459(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000072cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG459", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG459(a) bdk_pcieepx_cfg459_t
#define bustype_BDK_PCIEEPX_CFG459(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG459(a) "PCIEEPX_CFG459"
#define busnum_BDK_PCIEEPX_CFG459(a) (a)
#define arguments_BDK_PCIEEPX_CFG459(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg460
 *
 * Transmit Posted FC Credit Status Register
 * This register contains the four hundred sixty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg460_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_20_31        : 12;
        uint32_t tphfcc                : 8;  /**< [ 19: 12](RO/H) Transmit posted header FC Credits. The posted header credits advertised by the receiver at
                                                                 the other end of the link, updated with each UpdateFC DLLP. */
        uint32_t tpdfcc                : 12; /**< [ 11:  0](RO/H) Transmit posted data FC credits. The posted data credits advertised by the receiver at the
                                                                 other end of the link, updated with each UpdateFC DLLP. */
#else /* Word 0 - Little Endian */
        uint32_t tpdfcc                : 12; /**< [ 11:  0](RO/H) Transmit posted data FC credits. The posted data credits advertised by the receiver at the
                                                                 other end of the link, updated with each UpdateFC DLLP. */
        uint32_t tphfcc                : 8;  /**< [ 19: 12](RO/H) Transmit posted header FC Credits. The posted header credits advertised by the receiver at
                                                                 the other end of the link, updated with each UpdateFC DLLP. */
        uint32_t reserved_20_31        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg460_s cn; */
} bdk_pcieepx_cfg460_t;

static inline uint64_t BDK_PCIEEPX_CFG460(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG460(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000730ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG460", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG460(a) bdk_pcieepx_cfg460_t
#define bustype_BDK_PCIEEPX_CFG460(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG460(a) "PCIEEPX_CFG460"
#define busnum_BDK_PCIEEPX_CFG460(a) (a)
#define arguments_BDK_PCIEEPX_CFG460(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg461
 *
 * Transmit Nonposted FC Credit Status Register
 * This register contains the four hundred sixty-second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg461_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_20_31        : 12;
        uint32_t tchfcc                : 8;  /**< [ 19: 12](RO/H) Transmit nonposted header FC credits. The nonposted header credits advertised by the
                                                                 receiver at the other end of the link, updated with each UpdateFC DLLP. */
        uint32_t tcdfcc                : 12; /**< [ 11:  0](RO/H) Transmit nonposted data FC credits. The nonposted data credits advertised by the receiver
                                                                 at the other end of the link, updated with each UpdateFC DLLP. */
#else /* Word 0 - Little Endian */
        uint32_t tcdfcc                : 12; /**< [ 11:  0](RO/H) Transmit nonposted data FC credits. The nonposted data credits advertised by the receiver
                                                                 at the other end of the link, updated with each UpdateFC DLLP. */
        uint32_t tchfcc                : 8;  /**< [ 19: 12](RO/H) Transmit nonposted header FC credits. The nonposted header credits advertised by the
                                                                 receiver at the other end of the link, updated with each UpdateFC DLLP. */
        uint32_t reserved_20_31        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg461_s cn; */
} bdk_pcieepx_cfg461_t;

static inline uint64_t BDK_PCIEEPX_CFG461(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG461(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000734ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG461", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG461(a) bdk_pcieepx_cfg461_t
#define bustype_BDK_PCIEEPX_CFG461(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG461(a) "PCIEEPX_CFG461"
#define busnum_BDK_PCIEEPX_CFG461(a) (a)
#define arguments_BDK_PCIEEPX_CFG461(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg462
 *
 * Transmit Completion FC Credit Status Register
 * This register contains the four hundred sixty-third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg462_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_20_31        : 12;
        uint32_t tchfcc                : 8;  /**< [ 19: 12](RO/H) Transmit completion header FC credits. The completion header credits advertised by the
                                                                 receiver at the other end of the link, updated with each UpdateFC DLLP. */
        uint32_t tcdfcc                : 12; /**< [ 11:  0](RO/H) Transmit completion data FC credits. The completion data credits advertised by the
                                                                 receiver at the other end of the link, updated with each UpdateFC DLLP. */
#else /* Word 0 - Little Endian */
        uint32_t tcdfcc                : 12; /**< [ 11:  0](RO/H) Transmit completion data FC credits. The completion data credits advertised by the
                                                                 receiver at the other end of the link, updated with each UpdateFC DLLP. */
        uint32_t tchfcc                : 8;  /**< [ 19: 12](RO/H) Transmit completion header FC credits. The completion header credits advertised by the
                                                                 receiver at the other end of the link, updated with each UpdateFC DLLP. */
        uint32_t reserved_20_31        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg462_s cn; */
} bdk_pcieepx_cfg462_t;

static inline uint64_t BDK_PCIEEPX_CFG462(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG462(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000738ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG462", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG462(a) bdk_pcieepx_cfg462_t
#define bustype_BDK_PCIEEPX_CFG462(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG462(a) "PCIEEPX_CFG462"
#define busnum_BDK_PCIEEPX_CFG462(a) (a)
#define arguments_BDK_PCIEEPX_CFG462(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg463
 *
 * Queue Status Register
 * This register contains the four hundred sixty-fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg463_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t fcltoe                : 1;  /**< [ 31: 31](R/W) FC latency timer override enable. When this bit is set, the value in
                                                                 PCIEEP()_CFG463[FCLTOV] will override the FC latency timer value that the core calculates
                                                                 according to the PCIe specification. */
        uint32_t reserved_29_30        : 2;
        uint32_t fcltov                : 13; /**< [ 28: 16](R/W) FC latency timer override value. When you set PCIEEP()_CFG463[FCLTOE], the value in this
                                                                 field will override the FC latency timer value that the core calculates according to the
                                                                 PCIe specification. */
        uint32_t reserved_3_15         : 13;
        uint32_t rqne                  : 1;  /**< [  2:  2](RO/H) Received queue not empty. Indicates there is data in one or more of the receive buffers. */
        uint32_t trbne                 : 1;  /**< [  1:  1](RO/H) Transmit retry buffer not empty. Indicates that there is data in the transmit retry buffer. */
        uint32_t rtlpfccnr             : 1;  /**< [  0:  0](RO/H) Received TLP FC credits not returned. Indicates that the PCI Express bus has sent a TLP
                                                                 but has not yet received an UpdateFC DLLP indicating that the credits for that TLP have
                                                                 been restored by the receiver at the other end of the link. */
#else /* Word 0 - Little Endian */
        uint32_t rtlpfccnr             : 1;  /**< [  0:  0](RO/H) Received TLP FC credits not returned. Indicates that the PCI Express bus has sent a TLP
                                                                 but has not yet received an UpdateFC DLLP indicating that the credits for that TLP have
                                                                 been restored by the receiver at the other end of the link. */
        uint32_t trbne                 : 1;  /**< [  1:  1](RO/H) Transmit retry buffer not empty. Indicates that there is data in the transmit retry buffer. */
        uint32_t rqne                  : 1;  /**< [  2:  2](RO/H) Received queue not empty. Indicates there is data in one or more of the receive buffers. */
        uint32_t reserved_3_15         : 13;
        uint32_t fcltov                : 13; /**< [ 28: 16](R/W) FC latency timer override value. When you set PCIEEP()_CFG463[FCLTOE], the value in this
                                                                 field will override the FC latency timer value that the core calculates according to the
                                                                 PCIe specification. */
        uint32_t reserved_29_30        : 2;
        uint32_t fcltoe                : 1;  /**< [ 31: 31](R/W) FC latency timer override enable. When this bit is set, the value in
                                                                 PCIEEP()_CFG463[FCLTOV] will override the FC latency timer value that the core calculates
                                                                 according to the PCIe specification. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg463_s cn; */
} bdk_pcieepx_cfg463_t;

static inline uint64_t BDK_PCIEEPX_CFG463(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG463(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000073cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG463", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG463(a) bdk_pcieepx_cfg463_t
#define bustype_BDK_PCIEEPX_CFG463(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG463(a) "PCIEEPX_CFG463"
#define busnum_BDK_PCIEEPX_CFG463(a) (a)
#define arguments_BDK_PCIEEPX_CFG463(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg464
 *
 * VC Transmit Arbitration Register 1
 * This register contains the four hundred sixty-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg464_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t wrr_vc3               : 8;  /**< [ 31: 24](RO) WRR Weight for VC3. */
        uint32_t wrr_vc2               : 8;  /**< [ 23: 16](RO) WRR Weight for VC2. */
        uint32_t wrr_vc1               : 8;  /**< [ 15:  8](RO) WRR Weight for VC1. */
        uint32_t wrr_vc0               : 8;  /**< [  7:  0](RO) WRR Weight for VC0. */
#else /* Word 0 - Little Endian */
        uint32_t wrr_vc0               : 8;  /**< [  7:  0](RO) WRR Weight for VC0. */
        uint32_t wrr_vc1               : 8;  /**< [ 15:  8](RO) WRR Weight for VC1. */
        uint32_t wrr_vc2               : 8;  /**< [ 23: 16](RO) WRR Weight for VC2. */
        uint32_t wrr_vc3               : 8;  /**< [ 31: 24](RO) WRR Weight for VC3. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg464_s cn; */
} bdk_pcieepx_cfg464_t;

static inline uint64_t BDK_PCIEEPX_CFG464(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG464(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000740ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG464", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG464(a) bdk_pcieepx_cfg464_t
#define bustype_BDK_PCIEEPX_CFG464(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG464(a) "PCIEEPX_CFG464"
#define busnum_BDK_PCIEEPX_CFG464(a) (a)
#define arguments_BDK_PCIEEPX_CFG464(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg465
 *
 * VC Transmit Arbitration Register 2
 * This register contains the four hundred sixty-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg465_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t wrr_vc7               : 8;  /**< [ 31: 24](RO) WRR Weight for VC7. */
        uint32_t wrr_vc6               : 8;  /**< [ 23: 16](RO) WRR Weight for VC6. */
        uint32_t wrr_vc5               : 8;  /**< [ 15:  8](RO) WRR Weight for VC5. */
        uint32_t wrr_vc4               : 8;  /**< [  7:  0](RO) WRR Weight for VC4. */
#else /* Word 0 - Little Endian */
        uint32_t wrr_vc4               : 8;  /**< [  7:  0](RO) WRR Weight for VC4. */
        uint32_t wrr_vc5               : 8;  /**< [ 15:  8](RO) WRR Weight for VC5. */
        uint32_t wrr_vc6               : 8;  /**< [ 23: 16](RO) WRR Weight for VC6. */
        uint32_t wrr_vc7               : 8;  /**< [ 31: 24](RO) WRR Weight for VC7. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg465_s cn; */
} bdk_pcieepx_cfg465_t;

static inline uint64_t BDK_PCIEEPX_CFG465(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG465(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000744ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG465", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG465(a) bdk_pcieepx_cfg465_t
#define bustype_BDK_PCIEEPX_CFG465(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG465(a) "PCIEEPX_CFG465"
#define busnum_BDK_PCIEEPX_CFG465(a) (a)
#define arguments_BDK_PCIEEPX_CFG465(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg466
 *
 * VC0 Posted Receive Queue Control Register
 * This register contains the four hundred sixty-seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg466_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t rx_queue_order        : 1;  /**< [ 31: 31](RO/WRSL) VC ordering for receive queues. Determines the VC ordering rule for the receive queues,
                                                                 used only in the segmented-buffer configuration, writable through
                                                                 PEM()_CFG_WR:
                                                                 0 = Round robin.
                                                                 1 = Strict ordering, higher numbered VCs have higher priority.

                                                                 The application must not change this field. */
        uint32_t type_ordering         : 1;  /**< [ 30: 30](RO/WRSL) TLP type ordering for VC0. Determines the TLP type ordering rule for VC0 receive queues,
                                                                 used only in the segmented-buffer configuration, writable through
                                                                 PEM()_CFG_WR:
                                                                 0 = Strict ordering for received TLPs: Posted, then completion, then NonPosted.
                                                                 1 = Ordering of received TLPs follows the rules in PCI Express Base Specification

                                                                 The application must not change this field. */
        uint32_t reserved_24_29        : 6;
        uint32_t queue_mode            : 3;  /**< [ 23: 21](RO/WRSL) VC0 posted TLP queue mode. The operating mode of the posted receive queue for VC0, used
                                                                 only in the segmented-buffer configuration, writable through PEM()_CFG_WR. However,
                                                                 the application must not change this field.
                                                                 Only one bit can be set at a time:

                                                                 _ Bit 23 = Bypass.

                                                                 _ Bit 22 = Cut-through.

                                                                 _ Bit 21 = Store-and-forward. */
        uint32_t reserved_20           : 1;
        uint32_t header_credits        : 8;  /**< [ 19: 12](RO/WRSL) VC0 posted header credits. The number of initial posted header credits for VC0, used for
                                                                 all receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t data_credits          : 12; /**< [ 11:  0](RO/WRSL) VC0 posted data credits. The number of initial posted data credits for VC0, used for all
                                                                 receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t data_credits          : 12; /**< [ 11:  0](RO/WRSL) VC0 posted data credits. The number of initial posted data credits for VC0, used for all
                                                                 receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t header_credits        : 8;  /**< [ 19: 12](RO/WRSL) VC0 posted header credits. The number of initial posted header credits for VC0, used for
                                                                 all receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t reserved_20           : 1;
        uint32_t queue_mode            : 3;  /**< [ 23: 21](RO/WRSL) VC0 posted TLP queue mode. The operating mode of the posted receive queue for VC0, used
                                                                 only in the segmented-buffer configuration, writable through PEM()_CFG_WR. However,
                                                                 the application must not change this field.
                                                                 Only one bit can be set at a time:

                                                                 _ Bit 23 = Bypass.

                                                                 _ Bit 22 = Cut-through.

                                                                 _ Bit 21 = Store-and-forward. */
        uint32_t reserved_24_29        : 6;
        uint32_t type_ordering         : 1;  /**< [ 30: 30](RO/WRSL) TLP type ordering for VC0. Determines the TLP type ordering rule for VC0 receive queues,
                                                                 used only in the segmented-buffer configuration, writable through
                                                                 PEM()_CFG_WR:
                                                                 0 = Strict ordering for received TLPs: Posted, then completion, then NonPosted.
                                                                 1 = Ordering of received TLPs follows the rules in PCI Express Base Specification

                                                                 The application must not change this field. */
        uint32_t rx_queue_order        : 1;  /**< [ 31: 31](RO/WRSL) VC ordering for receive queues. Determines the VC ordering rule for the receive queues,
                                                                 used only in the segmented-buffer configuration, writable through
                                                                 PEM()_CFG_WR:
                                                                 0 = Round robin.
                                                                 1 = Strict ordering, higher numbered VCs have higher priority.

                                                                 The application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg466_s cn; */
} bdk_pcieepx_cfg466_t;

static inline uint64_t BDK_PCIEEPX_CFG466(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG466(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000748ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG466", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG466(a) bdk_pcieepx_cfg466_t
#define bustype_BDK_PCIEEPX_CFG466(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG466(a) "PCIEEPX_CFG466"
#define busnum_BDK_PCIEEPX_CFG466(a) (a)
#define arguments_BDK_PCIEEPX_CFG466(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg467
 *
 * VC0 Nonposted Receive Queue Control Register
 * This register contains the four hundred sixty-eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg467_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t queue_mode            : 3;  /**< [ 23: 21](RO/WRSL) VC0 nonposted TLP queue mode. The operating mode of the nonposted receive queue for VC0,
                                                                 used only in the segmented-buffer configuration, writable through
                                                                 PEM()_CFG_WR.
                                                                 Only one bit can be set at a time:

                                                                 _ Bit 23 = Bypass.

                                                                 _ Bit 22 = Cut-through.

                                                                 _ Bit 21 = Store-and-forward.

                                                                 The application must not change this field. */
        uint32_t reserved_20           : 1;
        uint32_t header_credits        : 8;  /**< [ 19: 12](RO/WRSL) VC0 nonposted header credits. The number of initial nonposted header credits for VC0, used
                                                                 for all receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t data_credits          : 12; /**< [ 11:  0](RO/WRSL) VC0 nonposted data credits. The number of initial nonposted data credits for VC0, used for
                                                                 all receive queue buffer configurations. This field is writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t data_credits          : 12; /**< [ 11:  0](RO/WRSL) VC0 nonposted data credits. The number of initial nonposted data credits for VC0, used for
                                                                 all receive queue buffer configurations. This field is writable through PEM()_CFG_WR.
                                                                 However, the application must not change this field. */
        uint32_t header_credits        : 8;  /**< [ 19: 12](RO/WRSL) VC0 nonposted header credits. The number of initial nonposted header credits for VC0, used
                                                                 for all receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t reserved_20           : 1;
        uint32_t queue_mode            : 3;  /**< [ 23: 21](RO/WRSL) VC0 nonposted TLP queue mode. The operating mode of the nonposted receive queue for VC0,
                                                                 used only in the segmented-buffer configuration, writable through
                                                                 PEM()_CFG_WR.
                                                                 Only one bit can be set at a time:

                                                                 _ Bit 23 = Bypass.

                                                                 _ Bit 22 = Cut-through.

                                                                 _ Bit 21 = Store-and-forward.

                                                                 The application must not change this field. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg467_s cn; */
} bdk_pcieepx_cfg467_t;

static inline uint64_t BDK_PCIEEPX_CFG467(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG467(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000074cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG467", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG467(a) bdk_pcieepx_cfg467_t
#define bustype_BDK_PCIEEPX_CFG467(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG467(a) "PCIEEPX_CFG467"
#define busnum_BDK_PCIEEPX_CFG467(a) (a)
#define arguments_BDK_PCIEEPX_CFG467(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg468
 *
 * VC0 Completion Receive Queue Control Register
 * This register contains the four hundred sixty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg468_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t queue_mode            : 3;  /**< [ 23: 21](RO/WRSL) VC0 completion TLP queue mode. The operating mode of the completion receive queue for VC0,
                                                                 used only in the segmented-buffer configuration, writable through
                                                                 PEM()_CFG_WR.
                                                                 Only one bit can be set at a time:

                                                                 _ Bit 23 = Bypass.

                                                                 _ Bit 22 = Cut-through.

                                                                 _ Bit 21 = Store-and-forward.

                                                                 The application must not change this field. */
        uint32_t reserved_20           : 1;
        uint32_t header_credits        : 8;  /**< [ 19: 12](RO/WRSL) VC0 completion header credits. The number of initial completion header credits for VC0,
                                                                 used for all receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t data_credits          : 12; /**< [ 11:  0](RO/WRSL) VC0 completion data credits. The number of initial completion data credits for VC0, used
                                                                 for all receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t data_credits          : 12; /**< [ 11:  0](RO/WRSL) VC0 completion data credits. The number of initial completion data credits for VC0, used
                                                                 for all receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t header_credits        : 8;  /**< [ 19: 12](RO/WRSL) VC0 completion header credits. The number of initial completion header credits for VC0,
                                                                 used for all receive queue buffer configurations. This field is writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t reserved_20           : 1;
        uint32_t queue_mode            : 3;  /**< [ 23: 21](RO/WRSL) VC0 completion TLP queue mode. The operating mode of the completion receive queue for VC0,
                                                                 used only in the segmented-buffer configuration, writable through
                                                                 PEM()_CFG_WR.
                                                                 Only one bit can be set at a time:

                                                                 _ Bit 23 = Bypass.

                                                                 _ Bit 22 = Cut-through.

                                                                 _ Bit 21 = Store-and-forward.

                                                                 The application must not change this field. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg468_s cn; */
} bdk_pcieepx_cfg468_t;

static inline uint64_t BDK_PCIEEPX_CFG468(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG468(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000750ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG468", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG468(a) bdk_pcieepx_cfg468_t
#define bustype_BDK_PCIEEPX_CFG468(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG468(a) "PCIEEPX_CFG468"
#define busnum_BDK_PCIEEPX_CFG468(a) (a)
#define arguments_BDK_PCIEEPX_CFG468(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg515
 *
 * Gen2 Port Logic Register
 * This register contains the five hundred sixteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg515_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_21_31        : 11;
        uint32_t s_d_e                 : 1;  /**< [ 20: 20](R/W) SEL_DE_EMPHASIS. Used to set the deemphasis level for upstream ports. */
        uint32_t ctcrb                 : 1;  /**< [ 19: 19](R/W) Config Tx compliance receive bit. When set to 1, signals LTSSM to transmit TS ordered sets
                                                                 with the compliance receive bit assert (equal to 1). */
        uint32_t cpyts                 : 1;  /**< [ 18: 18](R/W) Config PHY Tx swing. Indicates the voltage level that the PHY should drive. When set to 1,
                                                                 indicates full swing. When set to 0, indicates low swing. */
        uint32_t dsc                   : 1;  /**< [ 17: 17](R/W/H) Directed speed change. A write of 1 initiates a speed change; always reads as zero. */
        uint32_t le                    : 9;  /**< [ 16:  8](R/W) Lane enable. Indicates the number of lanes to check for exit from electrical idle in
                                                                 Polling.Active and Polling.Compliance. 0x1 = x1, 0x2 = x2, etc. Used to limit the maximum
                                                                 link width to ignore broken lanes that detect a receiver, but will not exit electrical
                                                                 idle and would otherwise prevent a valid link from being configured. */
        uint32_t n_fts                 : 8;  /**< [  7:  0](R/W) N_FTS. Sets the number of fast training sequences (N_FTS) that the core advertises as its
                                                                 N_FTS during GEN2 Link training. This value is used to inform the link partner about the
                                                                 PHY's ability to recover synchronization after a low power state.

                                                                 Do not set N_FTS to zero; doing so can cause the LTSSM to go into the recovery state when
                                                                 exiting from L0s. */
#else /* Word 0 - Little Endian */
        uint32_t n_fts                 : 8;  /**< [  7:  0](R/W) N_FTS. Sets the number of fast training sequences (N_FTS) that the core advertises as its
                                                                 N_FTS during GEN2 Link training. This value is used to inform the link partner about the
                                                                 PHY's ability to recover synchronization after a low power state.

                                                                 Do not set N_FTS to zero; doing so can cause the LTSSM to go into the recovery state when
                                                                 exiting from L0s. */
        uint32_t le                    : 9;  /**< [ 16:  8](R/W) Lane enable. Indicates the number of lanes to check for exit from electrical idle in
                                                                 Polling.Active and Polling.Compliance. 0x1 = x1, 0x2 = x2, etc. Used to limit the maximum
                                                                 link width to ignore broken lanes that detect a receiver, but will not exit electrical
                                                                 idle and would otherwise prevent a valid link from being configured. */
        uint32_t dsc                   : 1;  /**< [ 17: 17](R/W/H) Directed speed change. A write of 1 initiates a speed change; always reads as zero. */
        uint32_t cpyts                 : 1;  /**< [ 18: 18](R/W) Config PHY Tx swing. Indicates the voltage level that the PHY should drive. When set to 1,
                                                                 indicates full swing. When set to 0, indicates low swing. */
        uint32_t ctcrb                 : 1;  /**< [ 19: 19](R/W) Config Tx compliance receive bit. When set to 1, signals LTSSM to transmit TS ordered sets
                                                                 with the compliance receive bit assert (equal to 1). */
        uint32_t s_d_e                 : 1;  /**< [ 20: 20](R/W) SEL_DE_EMPHASIS. Used to set the deemphasis level for upstream ports. */
        uint32_t reserved_21_31        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg515_s cn; */
} bdk_pcieepx_cfg515_t;

static inline uint64_t BDK_PCIEEPX_CFG515(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG515(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x3000000080cll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG515", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG515(a) bdk_pcieepx_cfg515_t
#define bustype_BDK_PCIEEPX_CFG515(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG515(a) "PCIEEPX_CFG515"
#define busnum_BDK_PCIEEPX_CFG515(a) (a)
#define arguments_BDK_PCIEEPX_CFG515(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg516
 *
 * PHY Status Register
 * This register contains the five hundred seventeenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg516_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t phy_stat              : 32; /**< [ 31:  0](RO/H) PHY status. */
#else /* Word 0 - Little Endian */
        uint32_t phy_stat              : 32; /**< [ 31:  0](RO/H) PHY status. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg516_s cn; */
} bdk_pcieepx_cfg516_t;

static inline uint64_t BDK_PCIEEPX_CFG516(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG516(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000810ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG516", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG516(a) bdk_pcieepx_cfg516_t
#define bustype_BDK_PCIEEPX_CFG516(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG516(a) "PCIEEPX_CFG516"
#define busnum_BDK_PCIEEPX_CFG516(a) (a)
#define arguments_BDK_PCIEEPX_CFG516(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg517
 *
 * PHY Control Register
 * This register contains the five hundred eighteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg517_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t phy_ctrl              : 32; /**< [ 31:  0](R/W) PHY control. */
#else /* Word 0 - Little Endian */
        uint32_t phy_ctrl              : 32; /**< [ 31:  0](R/W) PHY control. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg517_s cn; */
} bdk_pcieepx_cfg517_t;

static inline uint64_t BDK_PCIEEPX_CFG517(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG517(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000814ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG517", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG517(a) bdk_pcieepx_cfg517_t
#define bustype_BDK_PCIEEPX_CFG517(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG517(a) "PCIEEPX_CFG517"
#define busnum_BDK_PCIEEPX_CFG517(a) (a)
#define arguments_BDK_PCIEEPX_CFG517(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg548
 *
 * Gen3 Control Register
 * This register contains the five hundred forty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg548_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_19_31        : 13;
        uint32_t dcbd                  : 1;  /**< [ 18: 18](R/W) Disable balance disable. Disable DC balance feature. */
        uint32_t dtdd                  : 1;  /**< [ 17: 17](R/W) DLLP transmission delay disable. Disable delay transmission of DLLPs before equalization. */
        uint32_t ed                    : 1;  /**< [ 16: 16](R/W) Equalization disable. Disable equalization feature. */
        uint32_t reserved_12_15        : 4;
        uint32_t erd                   : 1;  /**< [ 11: 11](R/W) Equalization redo disable. Disable requesting reset of EIEOS count during equalization. */
        uint32_t ecrd                  : 1;  /**< [ 10: 10](R/W) Equalization EIEOS count reset disable. Disable requesting reset of EIEOS count during
                                                                 equalization. */
        uint32_t ep2p3d                : 1;  /**< [  9:  9](R/W) Equalization phase 2 and phase 3 disable. This applies to downstream ports only. */
        uint32_t dsg3                  : 1;  /**< [  8:  8](R/W) Disable scrambler for Gen3 data rate. The Gen3 scrambler/descrambler within the core needs
                                                                 to be disabled when the scrambling function is implemented outside of the core (within the
                                                                 PHY). */
        uint32_t reserved_1_7          : 7;
        uint32_t grizdnc               : 1;  /**< [  0:  0](R/W) Gen3 receiver impedance ZRX-DC not compliant. */
#else /* Word 0 - Little Endian */
        uint32_t grizdnc               : 1;  /**< [  0:  0](R/W) Gen3 receiver impedance ZRX-DC not compliant. */
        uint32_t reserved_1_7          : 7;
        uint32_t dsg3                  : 1;  /**< [  8:  8](R/W) Disable scrambler for Gen3 data rate. The Gen3 scrambler/descrambler within the core needs
                                                                 to be disabled when the scrambling function is implemented outside of the core (within the
                                                                 PHY). */
        uint32_t ep2p3d                : 1;  /**< [  9:  9](R/W) Equalization phase 2 and phase 3 disable. This applies to downstream ports only. */
        uint32_t ecrd                  : 1;  /**< [ 10: 10](R/W) Equalization EIEOS count reset disable. Disable requesting reset of EIEOS count during
                                                                 equalization. */
        uint32_t erd                   : 1;  /**< [ 11: 11](R/W) Equalization redo disable. Disable requesting reset of EIEOS count during equalization. */
        uint32_t reserved_12_15        : 4;
        uint32_t ed                    : 1;  /**< [ 16: 16](R/W) Equalization disable. Disable equalization feature. */
        uint32_t dtdd                  : 1;  /**< [ 17: 17](R/W) DLLP transmission delay disable. Disable delay transmission of DLLPs before equalization. */
        uint32_t dcbd                  : 1;  /**< [ 18: 18](R/W) Disable balance disable. Disable DC balance feature. */
        uint32_t reserved_19_31        : 13;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg548_s cn; */
} bdk_pcieepx_cfg548_t;

static inline uint64_t BDK_PCIEEPX_CFG548(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG548(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x30000000890ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG548", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG548(a) bdk_pcieepx_cfg548_t
#define bustype_BDK_PCIEEPX_CFG548(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG548(a) "PCIEEPX_CFG548"
#define busnum_BDK_PCIEEPX_CFG548(a) (a)
#define arguments_BDK_PCIEEPX_CFG548(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg554
 *
 * Gen3 EQ Control Register
 * This register contains the five hundred fifty-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg554_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_25_31        : 7;
        uint32_t iif                   : 1;  /**< [ 24: 24](R/W) Include initial FOM. Include, or not, the FOM feedback from the initial preset evaluation
                                                                 performed in the EQ Master, when finding the highest FOM among all preset evaluations. */
        uint32_t prv                   : 16; /**< [ 23:  8](R/W) Preset request vector. Requesting of presets during the initial part of the EQ master
                                                                 phase. Encoding scheme as follows:

                                                                 Bit [15:0] = 0x0: No preset is requested and evaluated in the EQ master phase.

                                                                 Bit [i] = 1: Preset=i is requested and evaluated in the EQ master phase.

                                                                 _ 0b0000000000000000 = No preset req/evaluated in EQ master phase.

                                                                 _ 0b00000xxxxxxxxxx1 = Preset 0 req/evaluated in EQ master phase.

                                                                 _ 0b00000xxxxxxxxx1x = Preset 1 req/evaluated in EQ master phase.

                                                                 _ 0b00000xxxxxxxx1xx = Preset 2 req/evaluated in EQ master phase.

                                                                 _ 0b00000xxxxxxx1xxx = Preset 3 req/evaluated in EQ master phase.

                                                                 _ 0b00000xxxxxx1xxxx = Preset 4 req/evaluated in EQ master phase.

                                                                 _ 0b00000xxxxx1xxxxx = Preset 5 req/evaluated in EQ master phase.

                                                                 _ 0b00000xxxx1xxxxxx = Preset 6 req/evaluated in EQ master phase.

                                                                 _ 0b00000xxx1xxxxxxx = Preset 7 req/evaluated in EQ master phase.

                                                                 _ 0b00000xx1xxxxxxxx = Preset 8 req/evaluated in EQ master phase.

                                                                 _ 0b00000x1xxxxxxxxx = Preset 9 req/evaluated in EQ master phase.

                                                                 _ 0b000001xxxxxxxxxx = Preset 10 req/evaluated in EQ master phase.

                                                                 _ All other encodings = Reserved. */
        uint32_t reserved_6_7          : 2;
        uint32_t p23td                 : 1;  /**< [  5:  5](R/W) Phase2_3 2 ms timeout disable. Determine behavior in Phase2 for USP (Phase3 if DSP) when
                                                                 the PHY does not respond within 2 ms to the assertion of RxEqEval:
                                                                 0 = Abort the current evaluation; stop any attempt to modify the remote transmitter
                                                                 settings. Phase2 will be terminated by the 24 ms timeout.
                                                                 1 = Ignore the 2 ms timeout and continue as normal. This is used to support PHYs that
                                                                 require more than 2 ms to respond to the assertion of RxEqEval. */
        uint32_t bt                    : 1;  /**< [  4:  4](R/W) Behavior after 24 ms timeout (when optimal settings are not found).

                                                                 For a USP: determine the next LTSSM state from Phase2:
                                                                 0 = Recovery.Speed.
                                                                 1 = Recovry.Equalization.Phase3.

                                                                 For a DSP: determine the next LTSSM state from Phase3:
                                                                 0 = Recovery.Speed.
                                                                 1 = Recovry.Equalization.RcrLock.

                                                                 When optimal settings are not found:
                                                                 * Equalization phase 3 successful status bit is not set in the Link Status Register
                                                                 * Equalization phase 3 complete status bit is set in the Link Status Register */
        uint32_t fm                    : 4;  /**< [  3:  0](R/W) Feedback mode.
                                                                 0 = Direction of change (not supported).
                                                                 1 = Figure of merit.
                                                                 2-15 = Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t fm                    : 4;  /**< [  3:  0](R/W) Feedback mode.
                                                                 0 = Direction of change (not supported).
                                                                 1 = Figure of merit.
                                                                 2-15 = Reserved. */
        uint32_t bt                    : 1;  /**< [  4:  4](R/W) Behavior after 24 ms timeout (when optimal settings are not found).

                                                                 For a USP: determine the next LTSSM state from Phase2:
                                                                 0 = Recovery.Speed.
                                                                 1 = Recovry.Equalization.Phase3.

                                                                 For a DSP: determine the next LTSSM state from Phase3:
                                                                 0 = Recovery.Speed.
                                                                 1 = Recovry.Equalization.RcrLock.

                                                                 When optimal settings are not found:
                                                                 * Equalization phase 3 successful status bit is not set in the Link Status Register
                                                                 * Equalization phase 3 complete status bit is set in the Link Status Register */
        uint32_t p23td                 : 1;  /**< [  5:  5](R/W) Phase2_3 2 ms timeout disable. Determine behavior in Phase2 for USP (Phase3 if DSP) when
                                                                 the PHY does not respond within 2 ms to the assertion of RxEqEval:
                                                                 0 = Abort the current evaluation; stop any attempt to modify the remote transmitter
                                                                 settings. Phase2 will be terminated by the 24 ms timeout.
                                                                 1 = Ignore the 2 ms timeout and continue as normal. This is used to support PHYs that
                                                                 require more than 2 ms to respond to the assertion of RxEqEval. */
        uint32_t reserved_6_7          : 2;
        uint32_t prv                   : 16; /**< [ 23:  8](R/W) Preset request vector. Requesting of presets during the initial part of the EQ master
                                                                 phase. Encoding scheme as follows:

                                                                 Bit [15:0] = 0x0: No preset is requested and evaluated in the EQ master phase.

                                                                 Bit [i] = 1: Preset=i is requested and evaluated in the EQ master phase.

                                                                 _ 0b0000000000000000 = No preset req/evaluated in EQ master phase.

                                                                 _ 0b00000xxxxxxxxxx1 = Preset 0 req/evaluated in EQ master phase.

                                                                 _ 0b00000xxxxxxxxx1x = Preset 1 req/evaluated in EQ master phase.

                                                                 _ 0b00000xxxxxxxx1xx = Preset 2 req/evaluated in EQ master phase.

                                                                 _ 0b00000xxxxxxx1xxx = Preset 3 req/evaluated in EQ master phase.

                                                                 _ 0b00000xxxxxx1xxxx = Preset 4 req/evaluated in EQ master phase.

                                                                 _ 0b00000xxxxx1xxxxx = Preset 5 req/evaluated in EQ master phase.

                                                                 _ 0b00000xxxx1xxxxxx = Preset 6 req/evaluated in EQ master phase.

                                                                 _ 0b00000xxx1xxxxxxx = Preset 7 req/evaluated in EQ master phase.

                                                                 _ 0b00000xx1xxxxxxxx = Preset 8 req/evaluated in EQ master phase.

                                                                 _ 0b00000x1xxxxxxxxx = Preset 9 req/evaluated in EQ master phase.

                                                                 _ 0b000001xxxxxxxxxx = Preset 10 req/evaluated in EQ master phase.

                                                                 _ All other encodings = Reserved. */
        uint32_t iif                   : 1;  /**< [ 24: 24](R/W) Include initial FOM. Include, or not, the FOM feedback from the initial preset evaluation
                                                                 performed in the EQ Master, when finding the highest FOM among all preset evaluations. */
        uint32_t reserved_25_31        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg554_s cn; */
} bdk_pcieepx_cfg554_t;

static inline uint64_t BDK_PCIEEPX_CFG554(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG554(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000008a8ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG554", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG554(a) bdk_pcieepx_cfg554_t
#define bustype_BDK_PCIEEPX_CFG554(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG554(a) "PCIEEPX_CFG554"
#define busnum_BDK_PCIEEPX_CFG554(a) (a)
#define arguments_BDK_PCIEEPX_CFG554(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg558
 *
 * Gen3 PIPE Loopback Register
 * This register contains the five hundred fifty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg558_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ple                   : 1;  /**< [ 31: 31](R/W) Pipe loopback enable. */
        uint32_t rxstatus              : 31; /**< [ 30:  0](R/W) Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t rxstatus              : 31; /**< [ 30:  0](R/W) Reserved. */
        uint32_t ple                   : 1;  /**< [ 31: 31](R/W) Pipe loopback enable. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg558_s cn; */
} bdk_pcieepx_cfg558_t;

static inline uint64_t BDK_PCIEEPX_CFG558(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG558(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x300000008b8ll + 0x100000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PCIEEPX_CFG558", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG558(a) bdk_pcieepx_cfg558_t
#define bustype_BDK_PCIEEPX_CFG558(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG558(a) "PCIEEPX_CFG558"
#define busnum_BDK_PCIEEPX_CFG558(a) (a)
#define arguments_BDK_PCIEEPX_CFG558(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_PCIEEP_H__ */
