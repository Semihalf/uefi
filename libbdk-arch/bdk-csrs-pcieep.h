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
 * PCIe EP PF Vendor and Device Register
 * This register contains the first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg000_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t devid                 : 16; /**< [ 31: 16](RO/WRSL) Device ID for CNXXXX, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. For EEPROM loads, also see VENDID of this register.
                                                                 _ <15:8> resets to PCC_PROD_E::CNXXXX.
                                                                 _ <7:0> resets to PCC_DEV_IDL_E::CHIP. */
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
        uint32_t devid                 : 16; /**< [ 31: 16](RO/WRSL) Device ID for CNXXXX, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field. For EEPROM loads, also see VENDID of this register.
                                                                 _ <15:8> resets to PCC_PROD_E::CNXXXX.
                                                                 _ <7:0> resets to PCC_DEV_IDL_E::CHIP. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg000_s cn; */
} bdk_pcieepx_cfg000_t;

static inline uint64_t BDK_PCIEEPX_CFG000(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG000(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000000ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Command/Status Register
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
                                                                 to SLI/DPI soon thereafter.
                                                                 Bus master enable mimics the behavor of PEM()_FLR_PF_STOPREQ. */
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
                                                                 to SLI/DPI soon thereafter.
                                                                 Bus master enable mimics the behavor of PEM()_FLR_PF_STOPREQ. */
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000004ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Class Code/Revision ID Register
 * This register contains the third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg002_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO/WRSL) Base class code, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field.
                                                                 0xB = Processor. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO/WRSL) Subclass code, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field.
                                                                 0x80 = Other processors (no encoding exists for ARM.) */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO/WRSL) Programming interface, writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field.
                                                                 0x0 = No standard interface. */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/WRSL) Revision ID, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field.
                                                                 0x0 = pass 1.0. */
#else /* Word 0 - Little Endian */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/WRSL) Revision ID, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field.
                                                                 0x0 = pass 1.0. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO/WRSL) Programming interface, writable through PEM()_CFG_WR. However, the application must
                                                                 not change this field.
                                                                 0x0 = No standard interface. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO/WRSL) Subclass code, writable through PEM()_CFG_WR. However, the application must not change
                                                                 this field.
                                                                 0x80 = Other processors (no encoding exists for ARM.) */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO/WRSL) Base class code, writable through PEM()_CFG_WR. However, the application must not
                                                                 change this field.
                                                                 0xB = Processor. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg002_s cn; */
} bdk_pcieepx_cfg002_t;

static inline uint64_t BDK_PCIEEPX_CFG002(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG002(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000008ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF BIST, Header Type, Master Latency Timer, Cache Line Size Register
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
                                                                 to this bit. */
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
                                                                 to this bit. */
        uint32_t bist                  : 8;  /**< [ 31: 24](RO) The BIST register functions are not supported. All 8 bits of the BIST register are
                                                                 hardwired to 0x0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg003_s cn; */
} bdk_pcieepx_cfg003_t;

static inline uint64_t BDK_PCIEEPX_CFG003(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG003(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000000cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Base Address 0 Low Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000010ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF BAR Mask 0 Low Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30080000010ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Base Address 0 High Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000014ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF BAR Mask 0 High Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30080000014ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Base Address 1 Low Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000018ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF BAR Mask 1 Low Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30080000018ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Base Address 1 High Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000001cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF BAR Mask 1 High Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3008000001cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Base Address 2 Low Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000020ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF BAR Mask 2 Low Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30080000020ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Base Address 2 High Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000024ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF BAR Mask 2 High Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30080000024ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Card Bus CIS Pointer Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000028ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SubSystem ID/Subsystem Vendor ID Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000002cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Expansion ROM Base Address Register
 * This register contains the thirteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg012_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t eraddr                : 13; /**< [ 31: 19](R/W) Expansion ROM address. */
        uint32_t reserved_1_18         : 18;
        uint32_t er_en                 : 1;  /**< [  0:  0](R/W) Expansion ROM enable (Not supported). */
#else /* Word 0 - Little Endian */
        uint32_t er_en                 : 1;  /**< [  0:  0](R/W) Expansion ROM enable (Not supported). */
        uint32_t reserved_1_18         : 18;
        uint32_t eraddr                : 13; /**< [ 31: 19](R/W) Expansion ROM address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg012_s cn; */
} bdk_pcieepx_cfg012_t;

static inline uint64_t BDK_PCIEEPX_CFG012(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG012(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000030ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Expansion ROM BAR Mask Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30080000030ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Capability Pointer Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000034ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Interrupt Line/Interrupt Pin/Bridge Control Register
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
        uint32_t inta                  : 8;  /**< [ 15:  8](RO/WRSL) Interrupt pin (not supported). */
        uint32_t il                    : 8;  /**< [  7:  0](R/W) Interrupt line. */
#else /* Word 0 - Little Endian */
        uint32_t il                    : 8;  /**< [  7:  0](R/W) Interrupt line. */
        uint32_t inta                  : 8;  /**< [ 15:  8](RO/WRSL) Interrupt pin (not supported). */
        uint32_t mg                    : 8;  /**< [ 23: 16](RO) Minimum grant (hardwired to 0x0). */
        uint32_t ml                    : 8;  /**< [ 31: 24](RO) Maximum latency (hardwired to 0x0). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg015_s cn; */
} bdk_pcieepx_cfg015_t;

static inline uint64_t BDK_PCIEEPX_CFG015(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG015(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000003cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Power Management Capability ID Register
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
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO/WRSL) Next capability pointer. Points to PCI Express capabilities by default, writable through
                                                                 PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t pmcid                 : 8;  /**< [  7:  0](RO) Power management capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pmcid                 : 8;  /**< [  7:  0](RO) Power management capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO/WRSL) Next capability pointer. Points to PCI Express capabilities by default, writable through
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000040ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Power Management Control and Status Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000044ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG017", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG017(a) bdk_pcieepx_cfg017_t
#define bustype_BDK_PCIEEPX_CFG017(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG017(a) "PCIEEPX_CFG017"
#define busnum_BDK_PCIEEPX_CFG017(a) (a)
#define arguments_BDK_PCIEEPX_CFG017(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg028
 *
 * PCIe EP PF PCIe Capabilities/PCIe Capabilities List Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000070ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Device Capabilities Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000074ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Device Control/Device Status Register
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
        uint32_t i_flr                 : 1;  /**< [ 15: 15](R/W) Initiate function level reset.

                                                                 [I_FLR] must not be written to one via the indirect PEM()_CFG_WR. It should only ever
                                                                 be written to one via a direct PCIe access. */
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
        uint32_t mps                   : 3;  /**< [  7:  5](R/W) Max payload size. Legal values:
                                                                 0x0 = 128 bytes.
                                                                 0x1 = 256 bytes.
                                                                 0x2 = 512 bytes.
                                                                 0x3 = 1024 bytes.
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
        uint32_t mps                   : 3;  /**< [  7:  5](R/W) Max payload size. Legal values:
                                                                 0x0 = 128 bytes.
                                                                 0x1 = 256 bytes.
                                                                 0x2 = 512 bytes.
                                                                 0x3 = 1024 bytes.
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
        uint32_t i_flr                 : 1;  /**< [ 15: 15](R/W) Initiate function level reset.

                                                                 [I_FLR] must not be written to one via the indirect PEM()_CFG_WR. It should only ever
                                                                 be written to one via a direct PCIe access. */
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000078ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Link Capabilities Register
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
                                                                 csr PEM()_CFG[LANES8]. If LANES8 is set the reset value is 0x8, otherwise 0x4.

                                                                 This field is writable through PEM()_CFG_WR.

                                                                 Note that zeroing both the MLW and MLS out of reset, using the EEPROM, will prevent
                                                                 the ltssm from advancing past CONFIG.  This can be useful to allow software to locally
                                                                 boot and perform preconfiguration and bug fixes.  Setting MLW and MLS to valid values
                                                                 will then allow the lttsm to advance and the link to come up. */
        uint32_t mls                   : 4;  /**< [  3:  0](RO/WRSL/H) Maximum link speed. The reset value of this field is controlled by the value read from
                                                                 PEM()_CFG[MD].

                                                                 _ MD is 0x0, reset to 0x1: 2.5 GHz supported.

                                                                 _ MD is 0x1, reset to 0x2: 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x2, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x3, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported (RC Mode).

                                                                 This field is writable through PEM()_CFG_WR.

                                                                 Note that zeroing both the MLW and MLS out of reset, using the EEPROM, will prevent
                                                                 the ltssm from advancing past CONFIG.  This can be useful to allow software to locally
                                                                 boot and perform preconfiguration and bug fixes.  Setting MLW and MLS to valid values
                                                                 will then allow the lttsm to advance and the link to come up. */
#else /* Word 0 - Little Endian */
        uint32_t mls                   : 4;  /**< [  3:  0](RO/WRSL/H) Maximum link speed. The reset value of this field is controlled by the value read from
                                                                 PEM()_CFG[MD].

                                                                 _ MD is 0x0, reset to 0x1: 2.5 GHz supported.

                                                                 _ MD is 0x1, reset to 0x2: 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x2, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported.

                                                                 _ MD is 0x3, reset to 0x3: 8.0 Ghz, 5.0 GHz and 2.5 GHz supported (RC Mode).

                                                                 This field is writable through PEM()_CFG_WR.

                                                                 Note that zeroing both the MLW and MLS out of reset, using the EEPROM, will prevent
                                                                 the ltssm from advancing past CONFIG.  This can be useful to allow software to locally
                                                                 boot and perform preconfiguration and bug fixes.  Setting MLW and MLS to valid values
                                                                 will then allow the lttsm to advance and the link to come up. */
        uint32_t mlw                   : 6;  /**< [  9:  4](RO/WRSL/H) Maximum link width.
                                                                 The reset value of this field is determined by the value read from the PEM
                                                                 csr PEM()_CFG[LANES8]. If LANES8 is set the reset value is 0x8, otherwise 0x4.

                                                                 This field is writable through PEM()_CFG_WR.

                                                                 Note that zeroing both the MLW and MLS out of reset, using the EEPROM, will prevent
                                                                 the ltssm from advancing past CONFIG.  This can be useful to allow software to locally
                                                                 boot and perform preconfiguration and bug fixes.  Setting MLW and MLS to valid values
                                                                 will then allow the lttsm to advance and the link to come up. */
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000007cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Link Control/Link Status Register
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
        uint32_t hawd                  : 1;  /**< [  9:  9](R/W) Hardware autonomous width disable (not supported). */
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
        uint32_t hawd                  : 1;  /**< [  9:  9](R/W) Hardware autonomous width disable (not supported). */
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000080ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Device Capabilities 2 Register
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
        uint32_t effs                  : 1;  /**< [ 20: 20](RO/WRSL) Extended fmt field supported.  Writable through PEM()_CFG_WR.  However,
                                                                 the application must not change this field. */
        uint32_t obffs                 : 2;  /**< [ 19: 18](RO) Optimized buffer flush fill (OBFF) supported (not supported). */
        uint32_t reserved_14_17        : 4;
        uint32_t tphs                  : 2;  /**< [ 13: 12](RO) TPH completer supported (not supported). */
        uint32_t ltrs                  : 1;  /**< [ 11: 11](RO) Latency tolerance reporting (LTR) mechanism supported (not supported). */
        uint32_t noroprpr              : 1;  /**< [ 10: 10](RO/H) No RO-enabled PR-PR passing. (This bit applies to RCs.) */
        uint32_t atom128s              : 1;  /**< [  9:  9](RO) 128-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request. */
        uint32_t atom64s               : 1;  /**< [  8:  8](RO) 64-bit AtomicOp supported. Note that inbound AtomicOps targeting BAR0 are not supported
                                                                 and are dropped as an unsupported request. */
        uint32_t atom32s               : 1;  /**< [  7:  7](RO) 32-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request. */
        uint32_t atom_ops              : 1;  /**< [  6:  6](RO) AtomicOp routing supported (not applicable for EP). */
        uint32_t ari                   : 1;  /**< [  5:  5](RO) Alternate routing ID forwarding supported (not applicable for EP). */
        uint32_t ctds                  : 1;  /**< [  4:  4](RO) Completion timeout disable supported. */
        uint32_t ctrs                  : 4;  /**< [  3:  0](RO/H) Completion timeout ranges supported. */
#else /* Word 0 - Little Endian */
        uint32_t ctrs                  : 4;  /**< [  3:  0](RO/H) Completion timeout ranges supported. */
        uint32_t ctds                  : 1;  /**< [  4:  4](RO) Completion timeout disable supported. */
        uint32_t ari                   : 1;  /**< [  5:  5](RO) Alternate routing ID forwarding supported (not applicable for EP). */
        uint32_t atom_ops              : 1;  /**< [  6:  6](RO) AtomicOp routing supported (not applicable for EP). */
        uint32_t atom32s               : 1;  /**< [  7:  7](RO) 32-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request. */
        uint32_t atom64s               : 1;  /**< [  8:  8](RO) 64-bit AtomicOp supported. Note that inbound AtomicOps targeting BAR0 are not supported
                                                                 and are dropped as an unsupported request. */
        uint32_t atom128s              : 1;  /**< [  9:  9](RO) 128-bit AtomicOp supported.
                                                                 Note that inbound AtomicOps targeting BAR0 are not supported and are dropped as an
                                                                 unsupported request. */
        uint32_t noroprpr              : 1;  /**< [ 10: 10](RO/H) No RO-enabled PR-PR passing. (This bit applies to RCs.) */
        uint32_t ltrs                  : 1;  /**< [ 11: 11](RO) Latency tolerance reporting (LTR) mechanism supported (not supported). */
        uint32_t tphs                  : 2;  /**< [ 13: 12](RO) TPH completer supported (not supported). */
        uint32_t reserved_14_17        : 4;
        uint32_t obffs                 : 2;  /**< [ 19: 18](RO) Optimized buffer flush fill (OBFF) supported (not supported). */
        uint32_t effs                  : 1;  /**< [ 20: 20](RO/WRSL) Extended fmt field supported.  Writable through PEM()_CFG_WR.  However,
                                                                 the application must not change this field. */
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000094ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Device Control 2 Register/Device Status 2 Register
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
        uint32_t atom_op_eb            : 1;  /**< [  7:  7](R/W) AtomicOp egress blocking (not supported). */
        uint32_t atom_op               : 1;  /**< [  6:  6](R/W) AtomicOp requester enable. */
        uint32_t ari                   : 1;  /**< [  5:  5](RO) Alternate routing ID forwarding supported (not applicable for EP). */
        uint32_t ctd                   : 1;  /**< [  4:  4](R/W) Completion timeout disable. */
        uint32_t ctv                   : 4;  /**< [  3:  0](R/W/H) Completion timeout value.
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
#else /* Word 0 - Little Endian */
        uint32_t ctv                   : 4;  /**< [  3:  0](R/W/H) Completion timeout value.
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
        uint32_t ctd                   : 1;  /**< [  4:  4](R/W) Completion timeout disable. */
        uint32_t ari                   : 1;  /**< [  5:  5](RO) Alternate routing ID forwarding supported (not applicable for EP). */
        uint32_t atom_op               : 1;  /**< [  6:  6](R/W) AtomicOp requester enable. */
        uint32_t atom_op_eb            : 1;  /**< [  7:  7](R/W) AtomicOp egress blocking (not supported). */
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000098ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Link Capabilities 2 Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000009cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Link Control 2 Register/Link Status 2 Register
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
        uint32_t tls                   : 4;  /**< [  3:  0](R/W) Target link speed. For downstream ports, this field sets an upper limit on link
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
        uint32_t tls                   : 4;  /**< [  3:  0](R/W) Target link speed. For downstream ports, this field sets an upper limit on link
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000a0ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF MSI-X Capability ID/MSI-X Next Item Pointer/MSI-X Control Register
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
        uint32_t msixts                : 11; /**< [ 26: 16](RO/WRSL) MSI-X table size encoded as (table size - 1). Writable through PEM()_CFG_WR.

                                                                 This field is writable by issueing a PEM()_CFG_WR to PCIEEP(0)_CFG044
                                                                 when PEM()_CFG_WR[ADDR[31]] is set. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X Capability ID */
#else /* Word 0 - Little Endian */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X Capability ID */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer */
        uint32_t msixts                : 11; /**< [ 26: 16](RO/WRSL) MSI-X table size encoded as (table size - 1). Writable through PEM()_CFG_WR.

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
    /* struct bdk_pcieepx_cfg044_s cn; */
} bdk_pcieepx_cfg044_t;

static inline uint64_t BDK_PCIEEPX_CFG044(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG044(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000b0ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF MSI-X Table Offset and BIR Register
 * This register contains the forty-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg045_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixtoffs             : 29; /**< [ 31:  3](RO/WRSL) "MSI-X table offset register. Base address of the MSI-X Table, as an offset from the base
                                                                 address of the BAR indicated by the Table BIR bits. Writable through PEM()_CFG_WR.
                                                                 However,
                                                                 the application must not change this field." */
        uint32_t msixtbir              : 3;  /**< [  2:  0](RO/WRSL) MSI-X table BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 table into memory space.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t msixtbir              : 3;  /**< [  2:  0](RO/WRSL) MSI-X table BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 table into memory space.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t msixtoffs             : 29; /**< [ 31:  3](RO/WRSL) "MSI-X table offset register. Base address of the MSI-X Table, as an offset from the base
                                                                 address of the BAR indicated by the Table BIR bits. Writable through PEM()_CFG_WR.
                                                                 However,
                                                                 the application must not change this field." */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg045_s cn; */
} bdk_pcieepx_cfg045_t;

static inline uint64_t BDK_PCIEEPX_CFG045(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG045(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000b4ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF MSI-X PBA Offset and BIR Register
 * This register contains the forty-seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg046_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixpoffs             : 29; /**< [ 31:  3](RO/WRSL) MSI-X table offset register. Base address of the MSI-X PBA, as an offset from the base
                                                                 address of the BAR indicated by the table PBA bits. Writable through PEM()_CFG_WR.
                                                                 However,
                                                                 the application must not change this field. */
        uint32_t msixpbir              : 3;  /**< [  2:  0](RO/WRSL) MSI-X PBA BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 pending bit array into memory space.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t msixpbir              : 3;  /**< [  2:  0](RO/WRSL) MSI-X PBA BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 pending bit array into memory space.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
        uint32_t msixpoffs             : 29; /**< [ 31:  3](RO/WRSL) MSI-X table offset register. Base address of the MSI-X PBA, as an offset from the base
                                                                 address of the BAR indicated by the table PBA bits. Writable through PEM()_CFG_WR.
                                                                 However,
                                                                 the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg046_s cn; */
} bdk_pcieepx_cfg046_t;

static inline uint64_t BDK_PCIEEPX_CFG046(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG046(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000b8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG046", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG046(a) bdk_pcieepx_cfg046_t
#define bustype_BDK_PCIEEPX_CFG046(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG046(a) "PCIEEPX_CFG046"
#define busnum_BDK_PCIEEPX_CFG046(a) (a)
#define arguments_BDK_PCIEEPX_CFG046(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg047
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg047_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg047_s cn; */
} bdk_pcieepx_cfg047_t;

static inline uint64_t BDK_PCIEEPX_CFG047(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG047(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000bcll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG047", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG047(a) bdk_pcieepx_cfg047_t
#define bustype_BDK_PCIEEPX_CFG047(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG047(a) "PCIEEPX_CFG047"
#define busnum_BDK_PCIEEPX_CFG047(a) (a)
#define arguments_BDK_PCIEEPX_CFG047(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg048
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg048_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg048_s cn; */
} bdk_pcieepx_cfg048_t;

static inline uint64_t BDK_PCIEEPX_CFG048(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG048(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000c0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG048", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG048(a) bdk_pcieepx_cfg048_t
#define bustype_BDK_PCIEEPX_CFG048(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG048(a) "PCIEEPX_CFG048"
#define busnum_BDK_PCIEEPX_CFG048(a) (a)
#define arguments_BDK_PCIEEPX_CFG048(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg049
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg049_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg049_s cn; */
} bdk_pcieepx_cfg049_t;

static inline uint64_t BDK_PCIEEPX_CFG049(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG049(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000c4ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG049", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG049(a) bdk_pcieepx_cfg049_t
#define bustype_BDK_PCIEEPX_CFG049(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG049(a) "PCIEEPX_CFG049"
#define busnum_BDK_PCIEEPX_CFG049(a) (a)
#define arguments_BDK_PCIEEPX_CFG049(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg050
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg050_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg050_s cn; */
} bdk_pcieepx_cfg050_t;

static inline uint64_t BDK_PCIEEPX_CFG050(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG050(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000c8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG050", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG050(a) bdk_pcieepx_cfg050_t
#define bustype_BDK_PCIEEPX_CFG050(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG050(a) "PCIEEPX_CFG050"
#define busnum_BDK_PCIEEPX_CFG050(a) (a)
#define arguments_BDK_PCIEEPX_CFG050(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg051
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg051_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg051_s cn; */
} bdk_pcieepx_cfg051_t;

static inline uint64_t BDK_PCIEEPX_CFG051(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG051(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000ccll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG051", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG051(a) bdk_pcieepx_cfg051_t
#define bustype_BDK_PCIEEPX_CFG051(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG051(a) "PCIEEPX_CFG051"
#define busnum_BDK_PCIEEPX_CFG051(a) (a)
#define arguments_BDK_PCIEEPX_CFG051(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg052
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg052_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg052_s cn; */
} bdk_pcieepx_cfg052_t;

static inline uint64_t BDK_PCIEEPX_CFG052(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG052(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000d0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG052", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG052(a) bdk_pcieepx_cfg052_t
#define bustype_BDK_PCIEEPX_CFG052(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG052(a) "PCIEEPX_CFG052"
#define busnum_BDK_PCIEEPX_CFG052(a) (a)
#define arguments_BDK_PCIEEPX_CFG052(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg053
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg053_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg053_s cn; */
} bdk_pcieepx_cfg053_t;

static inline uint64_t BDK_PCIEEPX_CFG053(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG053(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000d4ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG053", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG053(a) bdk_pcieepx_cfg053_t
#define bustype_BDK_PCIEEPX_CFG053(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG053(a) "PCIEEPX_CFG053"
#define busnum_BDK_PCIEEPX_CFG053(a) (a)
#define arguments_BDK_PCIEEPX_CFG053(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg054
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg054_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg054_s cn; */
} bdk_pcieepx_cfg054_t;

static inline uint64_t BDK_PCIEEPX_CFG054(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG054(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000d8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG054", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG054(a) bdk_pcieepx_cfg054_t
#define bustype_BDK_PCIEEPX_CFG054(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG054(a) "PCIEEPX_CFG054"
#define busnum_BDK_PCIEEPX_CFG054(a) (a)
#define arguments_BDK_PCIEEPX_CFG054(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg055
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg055_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg055_s cn; */
} bdk_pcieepx_cfg055_t;

static inline uint64_t BDK_PCIEEPX_CFG055(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG055(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000dcll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG055", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG055(a) bdk_pcieepx_cfg055_t
#define bustype_BDK_PCIEEPX_CFG055(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG055(a) "PCIEEPX_CFG055"
#define busnum_BDK_PCIEEPX_CFG055(a) (a)
#define arguments_BDK_PCIEEPX_CFG055(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg056
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg056_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg056_s cn; */
} bdk_pcieepx_cfg056_t;

static inline uint64_t BDK_PCIEEPX_CFG056(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG056(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000e0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG056", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG056(a) bdk_pcieepx_cfg056_t
#define bustype_BDK_PCIEEPX_CFG056(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG056(a) "PCIEEPX_CFG056"
#define busnum_BDK_PCIEEPX_CFG056(a) (a)
#define arguments_BDK_PCIEEPX_CFG056(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg057
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg057_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg057_s cn; */
} bdk_pcieepx_cfg057_t;

static inline uint64_t BDK_PCIEEPX_CFG057(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG057(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000e4ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG057", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG057(a) bdk_pcieepx_cfg057_t
#define bustype_BDK_PCIEEPX_CFG057(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG057(a) "PCIEEPX_CFG057"
#define busnum_BDK_PCIEEPX_CFG057(a) (a)
#define arguments_BDK_PCIEEPX_CFG057(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg058
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg058_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg058_s cn; */
} bdk_pcieepx_cfg058_t;

static inline uint64_t BDK_PCIEEPX_CFG058(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG058(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000e8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG058", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG058(a) bdk_pcieepx_cfg058_t
#define bustype_BDK_PCIEEPX_CFG058(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG058(a) "PCIEEPX_CFG058"
#define busnum_BDK_PCIEEPX_CFG058(a) (a)
#define arguments_BDK_PCIEEPX_CFG058(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg059
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg059_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg059_s cn; */
} bdk_pcieepx_cfg059_t;

static inline uint64_t BDK_PCIEEPX_CFG059(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG059(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000ecll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG059", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG059(a) bdk_pcieepx_cfg059_t
#define bustype_BDK_PCIEEPX_CFG059(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG059(a) "PCIEEPX_CFG059"
#define busnum_BDK_PCIEEPX_CFG059(a) (a)
#define arguments_BDK_PCIEEPX_CFG059(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg060
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg060_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg060_s cn; */
} bdk_pcieepx_cfg060_t;

static inline uint64_t BDK_PCIEEPX_CFG060(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG060(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000f0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG060", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG060(a) bdk_pcieepx_cfg060_t
#define bustype_BDK_PCIEEPX_CFG060(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG060(a) "PCIEEPX_CFG060"
#define busnum_BDK_PCIEEPX_CFG060(a) (a)
#define arguments_BDK_PCIEEPX_CFG060(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg061
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg061_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg061_s cn; */
} bdk_pcieepx_cfg061_t;

static inline uint64_t BDK_PCIEEPX_CFG061(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG061(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000f4ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG061", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG061(a) bdk_pcieepx_cfg061_t
#define bustype_BDK_PCIEEPX_CFG061(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG061(a) "PCIEEPX_CFG061"
#define busnum_BDK_PCIEEPX_CFG061(a) (a)
#define arguments_BDK_PCIEEPX_CFG061(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg062
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg062_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg062_s cn; */
} bdk_pcieepx_cfg062_t;

static inline uint64_t BDK_PCIEEPX_CFG062(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG062(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000f8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG062", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG062(a) bdk_pcieepx_cfg062_t
#define bustype_BDK_PCIEEPX_CFG062(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG062(a) "PCIEEPX_CFG062"
#define busnum_BDK_PCIEEPX_CFG062(a) (a)
#define arguments_BDK_PCIEEPX_CFG062(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg063
 *
 * PCIe EP Unused Capability Registers
 * This register contains 32-bits of PCIe type 1 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg063_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#else /* Word 0 - Little Endian */
        uint32_t sw_hdr                : 32; /**< [ 31:  0](RO/WRSL) Software headers. This configuration area is opaque to PCIEEP() hardware. It is available
                                                                 for software to add additional configuration capabilities.
                                                                 Writable through PEM()_CFG_WR. However, the application must not change this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg063_s cn; */
} bdk_pcieepx_cfg063_t;

static inline uint64_t BDK_PCIEEPX_CFG063(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG063(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000000fcll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG063", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG063(a) bdk_pcieepx_cfg063_t
#define bustype_BDK_PCIEEPX_CFG063(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG063(a) "PCIEEPX_CFG063"
#define busnum_BDK_PCIEEPX_CFG063(a) (a)
#define arguments_BDK_PCIEEPX_CFG063(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg064
 *
 * PCIe EP PF Extended Capability Header Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000100ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Uncorrectable Error Status Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000104ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Uncorrectable Error Mask Register
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
        uint32_t uatombm               : 1;  /**< [ 24: 24](RO) Unsupported AtomicOp egress blocked mask. */
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
        uint32_t uatombm               : 1;  /**< [ 24: 24](RO) Unsupported AtomicOp egress blocked mask. */
        uint32_t tpbem                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error mask. */
        uint32_t reserved_26_31        : 6;
#endif /* Word 0 - End */
    } s;
    struct bdk_pcieepx_cfg066_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_26_31        : 6;
        uint32_t tpbem                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error mask. */
        uint32_t uatombm               : 1;  /**< [ 24: 24](RO) Unsupported AtomicOp egress blocked mask. */
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
        uint32_t uatombm               : 1;  /**< [ 24: 24](RO) Unsupported AtomicOp egress blocked mask. */
        uint32_t tpbem                 : 1;  /**< [ 25: 25](RO) Unsupported TLP prefix blocked error mask. */
        uint32_t reserved_26_31        : 6;
#endif /* Word 0 - End */
    } cn;
} bdk_pcieepx_cfg066_t;

static inline uint64_t BDK_PCIEEPX_CFG066(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG066(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000108ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Uncorrectable Error Severity Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000010cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Correctable Error Status Register
 * This register contains the sixty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg068_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t chlo                  : 1;  /**< [ 15: 15](R/W1C) Corrected header log overflow status. */
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
        uint32_t chlo                  : 1;  /**< [ 15: 15](R/W1C) Corrected header log overflow status. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg068_s cn; */
} bdk_pcieepx_cfg068_t;

static inline uint64_t BDK_PCIEEPX_CFG068(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG068(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000110ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Correctable Error Mask Register
 * This register contains the seventieth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg069_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t chlom                 : 1;  /**< [ 15: 15](R/W) Corrected header log overflow error mask. */
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
        uint32_t chlom                 : 1;  /**< [ 15: 15](R/W) Corrected header log overflow error mask. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg069_s cn; */
} bdk_pcieepx_cfg069_t;

static inline uint64_t BDK_PCIEEPX_CFG069(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG069(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000114ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Advanced Error Capabilities and Control Register
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
        uint32_t mult_hdr_en           : 1;  /**< [ 10: 10](R/W) Multiple Header Recording Enable. */
        uint32_t mult_hdr_cap          : 1;  /**< [  9:  9](RO/WRSL) Multiple Header Recording Capability. */
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
        uint32_t mult_hdr_cap          : 1;  /**< [  9:  9](RO/WRSL) Multiple Header Recording Capability. */
        uint32_t mult_hdr_en           : 1;  /**< [ 10: 10](R/W) Multiple Header Recording Enable. */
        uint32_t tlp_plp               : 1;  /**< [ 11: 11](RO) TLP prefix log present (not supported). */
        uint32_t reserved_12_31        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg070_s cn; */
} bdk_pcieepx_cfg070_t;

static inline uint64_t BDK_PCIEEPX_CFG070(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG070(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000118ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Header Log Register 1
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000011cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Header Log Register 2
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000120ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Header Log Register 3
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000124ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Header Log Register 4
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000128ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF TLP Prefix Log Register 4
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000138ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF ARI Capability Header Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000148ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF ARI Capability Register/PCI Express ARI Control Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000014cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Secondary Capability (Gen3) Header Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000158ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Link Control 3 Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000015cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Lane Error Status Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000160ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Equalization Control Lane 0/1 Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000164ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Equalization Control Lane 2/3 Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000168ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Equalization Control Lane 4/5 Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000016cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Equalization Control Lane 6/7 Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000170ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV Capability Header Register
 * This register contains the ninety-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg094_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO/H) Next capability offset. Points to the RAS DES capability header by default. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCIE Express extended capability. */
#else /* Word 0 - Little Endian */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCIE Express extended capability. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO/H) Next capability offset. Points to the RAS DES capability header by default. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg094_s cn; */
} bdk_pcieepx_cfg094_t;

static inline uint64_t BDK_PCIEEPX_CFG094(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG094(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000178ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV Capability Register
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
        uint32_t vfmc                  : 1;  /**< [  0:  0](RO/H) VF migration capable. */
#else /* Word 0 - Little Endian */
        uint32_t vfmc                  : 1;  /**< [  0:  0](RO/H) VF migration capable. */
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000017cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV Control/Status Register
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
        uint32_t mie                   : 1;  /**< [  2:  2](RO/H) VF migration interrupt enable. */
        uint32_t me                    : 1;  /**< [  1:  1](RO/H) VF migration enable. */
        uint32_t vfe                   : 1;  /**< [  0:  0](R/W) VF enable. */
#else /* Word 0 - Little Endian */
        uint32_t vfe                   : 1;  /**< [  0:  0](R/W) VF enable. */
        uint32_t me                    : 1;  /**< [  1:  1](RO/H) VF migration enable. */
        uint32_t mie                   : 1;  /**< [  2:  2](RO/H) VF migration interrupt enable. */
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000180ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV Initial VFs/Total VFs Register
 * This register contains the ninety-eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg097_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t tvf                   : 16; /**< [ 31: 16](RO) Total VFs.  Read-only copy of PCIEP()_CFG097[IVF]. */
        uint32_t ivf                   : 16; /**< [ 15:  0](RO/WRSL) Initial VFs.

                                                                 There are two InitialVFs registers; one for each ARI Capable
                                                                 and non-ARI Capable Hierarchies.  The PCIEP()_CFG096[ARI] determines which one is
                                                                 being used for SR-IOV, and which one is accessed by a read request.

                                                                 This field is writable through PEM()_CFG_WR, PEM()_CFG_WR[ADDR[31]] determines
                                                                 which IVF register is updated.
                                                                 0 = accesses non-ARI Capable Hieracrhy copy of IVF.
                                                                 1 = accesses ARI Capable Hieracrhy copy of IVF. */
#else /* Word 0 - Little Endian */
        uint32_t ivf                   : 16; /**< [ 15:  0](RO/WRSL) Initial VFs.

                                                                 There are two InitialVFs registers; one for each ARI Capable
                                                                 and non-ARI Capable Hierarchies.  The PCIEP()_CFG096[ARI] determines which one is
                                                                 being used for SR-IOV, and which one is accessed by a read request.

                                                                 This field is writable through PEM()_CFG_WR, PEM()_CFG_WR[ADDR[31]] determines
                                                                 which IVF register is updated.
                                                                 0 = accesses non-ARI Capable Hieracrhy copy of IVF.
                                                                 1 = accesses ARI Capable Hieracrhy copy of IVF. */
        uint32_t tvf                   : 16; /**< [ 31: 16](RO) Total VFs.  Read-only copy of PCIEP()_CFG097[IVF]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg097_s cn; */
} bdk_pcieepx_cfg097_t;

static inline uint64_t BDK_PCIEEPX_CFG097(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG097(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000184ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV Number of VFs Register/SR-IOV Function Dependency Link Register
 * This register contains the ninety-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg098_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t fdl                   : 8;  /**< [ 23: 16](RO/H) Function dependency link. Enables support for VF dependency link. */
        uint32_t nvf                   : 16; /**< [ 15:  0](R/W) Number of VFs that are visible. */
#else /* Word 0 - Little Endian */
        uint32_t nvf                   : 16; /**< [ 15:  0](R/W) Number of VFs that are visible. */
        uint32_t fdl                   : 8;  /**< [ 23: 16](RO/H) Function dependency link. Enables support for VF dependency link. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg098_s cn; */
} bdk_pcieepx_cfg098_t;

static inline uint64_t BDK_PCIEEPX_CFG098(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG098(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000188ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV Initial VFs/Total VFs Register
 * This register contains the one hundredth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg099_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vfs                   : 16; /**< [ 31: 16](RO/H) There are two VF Stride registers;  one for each ARI Capable
                                                                 and non-ARI Capable Hierarchies.  The PCIEP()_CFG096[ARI] determines which one is
                                                                 being used for SR-IOV, and which one is accessed by a read request.

                                                                 This field is writable through PEM()_CFG_WR, PEM()_CFG_WR[ADDR[31]] determines
                                                                 which VFS register is updated.
                                                                 0 = accesses non-ARI Capable Hieracrhy copy of VFS.
                                                                 1 = accesses ARI Capable Hieracrhy copy of VFS. */
        uint32_t fo                    : 16; /**< [ 15:  0](RO/H) First VF offset.

                                                                 There are two First VF Offset registers;  one for each ARI Capable
                                                                 and non-ARI Capable Hierarchies.  The PCIEP()_CFG096[ARI] determines which one is
                                                                 being used for SR-IOV, and which one is accessed by a read request.

                                                                 This field is writable through PEM()_CFG_WR, PEM()_CFG_WR[ADDR[31]] determines
                                                                 which FO register is updated.
                                                                 0 = accesses non-ARI Capable Hieracrhy copy of FO.
                                                                 1 = accesses ARI Capable Hieracrhy copy of FO. */
#else /* Word 0 - Little Endian */
        uint32_t fo                    : 16; /**< [ 15:  0](RO/H) First VF offset.

                                                                 There are two First VF Offset registers;  one for each ARI Capable
                                                                 and non-ARI Capable Hierarchies.  The PCIEP()_CFG096[ARI] determines which one is
                                                                 being used for SR-IOV, and which one is accessed by a read request.

                                                                 This field is writable through PEM()_CFG_WR, PEM()_CFG_WR[ADDR[31]] determines
                                                                 which FO register is updated.
                                                                 0 = accesses non-ARI Capable Hieracrhy copy of FO.
                                                                 1 = accesses ARI Capable Hieracrhy copy of FO. */
        uint32_t vfs                   : 16; /**< [ 31: 16](RO/H) There are two VF Stride registers;  one for each ARI Capable
                                                                 and non-ARI Capable Hierarchies.  The PCIEP()_CFG096[ARI] determines which one is
                                                                 being used for SR-IOV, and which one is accessed by a read request.

                                                                 This field is writable through PEM()_CFG_WR, PEM()_CFG_WR[ADDR[31]] determines
                                                                 which VFS register is updated.
                                                                 0 = accesses non-ARI Capable Hieracrhy copy of VFS.
                                                                 1 = accesses ARI Capable Hieracrhy copy of VFS. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg099_s cn; */
} bdk_pcieepx_cfg099_t;

static inline uint64_t BDK_PCIEEPX_CFG099(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG099(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000018cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV Number of VFs/Function Dependency Link Register
 * This register contains the one hundred first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg100_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vfdev                 : 16; /**< [ 31: 16](RO/H) VF device ID.
                                                                 _ <15:8> resets to PCC_PROD_E::CNXXXX.
                                                                 _ <7:0> resets to PCC_DEV_IDL_E::CHIP_VF. */
        uint32_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_15         : 16;
        uint32_t vfdev                 : 16; /**< [ 31: 16](RO/H) VF device ID.
                                                                 _ <15:8> resets to PCC_PROD_E::CNXXXX.
                                                                 _ <7:0> resets to PCC_DEV_IDL_E::CHIP_VF. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg100_s cn; */
} bdk_pcieepx_cfg100_t;

static inline uint64_t BDK_PCIEEPX_CFG100(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG100(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000190ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV Supported Page Sizes Register
 * This register contains the one hundred second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg101_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t supps                 : 32; /**< [ 31:  0](RO/H) Supported page sizes. */
#else /* Word 0 - Little Endian */
        uint32_t supps                 : 32; /**< [ 31:  0](RO/H) Supported page sizes. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg101_s cn; */
} bdk_pcieepx_cfg101_t;

static inline uint64_t BDK_PCIEEPX_CFG101(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG101(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000194ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV System Page Sizes Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000198ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV BAR 0 Register
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
        uint32_t pf                    : 1;  /**< [  3:  3](RO/H) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type:
                                                                 0x0 = 32-bit BAR.
                                                                 0x2 = 64-bit BAR. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO/H) Memory space indicator:
                                                                 0 = BAR 0 is a memory BAR.
                                                                 1 = BAR 0 is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO/H) Memory space indicator:
                                                                 0 = BAR 0 is a memory BAR.
                                                                 1 = BAR 0 is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type:
                                                                 0x0 = 32-bit BAR.
                                                                 0x2 = 64-bit BAR. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO/H) Prefetchable. */
        uint32_t reserved_4_19         : 16;
        uint32_t lbab                  : 12; /**< [ 31: 20](R/W) Lower bits of the VF BAR 0 base address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg103_s cn; */
} bdk_pcieepx_cfg103_t;

static inline uint64_t BDK_PCIEEPX_CFG103(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG103(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000019cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV BAR 1 Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001a0ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV BAR 2 Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001a4ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV BAR 3 Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001a8ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV BAR 4 Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001acll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV BAR 5 Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001b0ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF SR-IOV Migration State Array Offset Register
 * This register contains the one hundred tenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg109_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t mso                   : 29; /**< [ 31:  3](RO/H) VF migration state offset. */
        uint32_t msbir                 : 3;  /**< [  2:  0](RO/H) VF migration state BIR. */
#else /* Word 0 - Little Endian */
        uint32_t msbir                 : 3;  /**< [  2:  0](RO/H) VF migration state BIR. */
        uint32_t mso                   : 29; /**< [ 31:  3](RO/H) VF migration state offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg109_s cn; */
} bdk_pcieepx_cfg109_t;

static inline uint64_t BDK_PCIEEPX_CFG109(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG109(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001b4ll + 0x100000000ll * ((a) & 0x3);
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
 * PCI Express Vendor Specific RAS DES Capability Header Register
 * This register contains the one hundred eleventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg110_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset.  Points to the Vendor Specific RAS Data Path Protection capabilities. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCI Express extended capability. */
#else /* Word 0 - Little Endian */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCI Express extended capability. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset.  Points to the Vendor Specific RAS Data Path Protection capabilities. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg110_s cn; */
} bdk_pcieepx_cfg110_t;

static inline uint64_t BDK_PCIEEPX_CFG110(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG110(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001b8ll + 0x100000000ll * ((a) & 0x3);
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
 * PCI Express Vendor RAS DES Header Register
 * This register contains the one hundred twelfth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg111_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vsec_length           : 12; /**< [ 31: 20](RO) VSEC length. */
        uint32_t vsec_rev              : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t vsec_id               : 16; /**< [ 15:  0](RO) VSED ID. */
#else /* Word 0 - Little Endian */
        uint32_t vsec_id               : 16; /**< [ 15:  0](RO) VSED ID. */
        uint32_t vsec_rev              : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t vsec_length           : 12; /**< [ 31: 20](RO) VSEC length. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg111_s cn; */
} bdk_pcieepx_cfg111_t;

static inline uint64_t BDK_PCIEEPX_CFG111(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG111(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001bcll + 0x100000000ll * ((a) & 0x3);
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
 * PCI Express Vendor RAS DES Event Counter Control Register
 * This register contains the one hundred thirteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg112_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_28_31        : 4;
        uint32_t ev_cntr_data_sel      : 12; /**< [ 27: 16](R/W) Event counter data select.  This field in conjuction with [EV_CNTR_LANE_SEL]
                                                                 selects PCIEEP()_CFG113[EV_CNTR_DATA].
                                                                 _ <27:24> = Group number (0..0x7).
                                                                 _ <23:16> = Event number (0..0x13). */
        uint32_t reserved_12_15        : 4;
        uint32_t ev_cntr_lane_sel      : 4;  /**< [ 11:  8](R/W) Event counter lane select.  This field in conjuction with [EV_CNTR_DATA_SEL]
                                                                 indexes the event counter data returned in the PCIEEP()_CFG113[EV_CNTR_DATA].

                                                                 0x0-0x7 = Lane number.
                                                                 0x8-0xf = Reserved. */
        uint32_t ev_cntr_stat          : 1;  /**< [  7:  7](RO) Event counter status.  Returns the Enable status of the event counter
                                                                 selected by [EV_CNTR_DATA_SEL] and [EV_CNTR_LANE_SEL]. */
        uint32_t reserved_5_6          : 2;
        uint32_t ev_cntr_en            : 3;  /**< [  4:  2](WO) Event counter enable.  Enables/disables the event counter
                                                                 selected by [EV_CNTR_DATA_SEL] and [EV_CNTR_LANE_SEL].
                                                                 By default, all event counters are disabled.  This field
                                                                 always reads zeros.

                                                                 0x0 = No change.
                                                                 0x1 = Per event off.
                                                                 0x2 = No change.
                                                                 0x3 = Per event on.
                                                                 0x4 = No change.
                                                                 0x5 = All off.
                                                                 0x6 = No change.
                                                                 0x7 = All on. */
        uint32_t ev_cntr_clr           : 2;  /**< [  1:  0](WO) Event counter clear. Clears the event counters
                                                                 selected by [EV_CNTR_DATA_SEL] and [EV_CNTR_LANE_SEL].
                                                                 By default, all event counters are disabled.  This field
                                                                 always reads zeros.

                                                                 0x0 = No change.
                                                                 0x1 = Per clear.
                                                                 0x2 = No change.
                                                                 0x3 = All clear. */
#else /* Word 0 - Little Endian */
        uint32_t ev_cntr_clr           : 2;  /**< [  1:  0](WO) Event counter clear. Clears the event counters
                                                                 selected by [EV_CNTR_DATA_SEL] and [EV_CNTR_LANE_SEL].
                                                                 By default, all event counters are disabled.  This field
                                                                 always reads zeros.

                                                                 0x0 = No change.
                                                                 0x1 = Per clear.
                                                                 0x2 = No change.
                                                                 0x3 = All clear. */
        uint32_t ev_cntr_en            : 3;  /**< [  4:  2](WO) Event counter enable.  Enables/disables the event counter
                                                                 selected by [EV_CNTR_DATA_SEL] and [EV_CNTR_LANE_SEL].
                                                                 By default, all event counters are disabled.  This field
                                                                 always reads zeros.

                                                                 0x0 = No change.
                                                                 0x1 = Per event off.
                                                                 0x2 = No change.
                                                                 0x3 = Per event on.
                                                                 0x4 = No change.
                                                                 0x5 = All off.
                                                                 0x6 = No change.
                                                                 0x7 = All on. */
        uint32_t reserved_5_6          : 2;
        uint32_t ev_cntr_stat          : 1;  /**< [  7:  7](RO) Event counter status.  Returns the Enable status of the event counter
                                                                 selected by [EV_CNTR_DATA_SEL] and [EV_CNTR_LANE_SEL]. */
        uint32_t ev_cntr_lane_sel      : 4;  /**< [ 11:  8](R/W) Event counter lane select.  This field in conjuction with [EV_CNTR_DATA_SEL]
                                                                 indexes the event counter data returned in the PCIEEP()_CFG113[EV_CNTR_DATA].

                                                                 0x0-0x7 = Lane number.
                                                                 0x8-0xf = Reserved. */
        uint32_t reserved_12_15        : 4;
        uint32_t ev_cntr_data_sel      : 12; /**< [ 27: 16](R/W) Event counter data select.  This field in conjuction with [EV_CNTR_LANE_SEL]
                                                                 selects PCIEEP()_CFG113[EV_CNTR_DATA].
                                                                 _ <27:24> = Group number (0..0x7).
                                                                 _ <23:16> = Event number (0..0x13). */
        uint32_t reserved_28_31        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg112_s cn; */
} bdk_pcieepx_cfg112_t;

static inline uint64_t BDK_PCIEEPX_CFG112(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG112(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001c0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG112", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG112(a) bdk_pcieepx_cfg112_t
#define bustype_BDK_PCIEEPX_CFG112(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG112(a) "PCIEEPX_CFG112"
#define busnum_BDK_PCIEEPX_CFG112(a) (a)
#define arguments_BDK_PCIEEPX_CFG112(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg113
 *
 * PCI Express Vendor RAS DES Data Register
 * This register contains the one hundred fourteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg113_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ev_cntr_data          : 32; /**< [ 31:  0](RO) Event counter data.  This field returns data selected by PCIEEP()_CFG113[EV_CNTR_DATA_SEL]
                                                                 and PCIEEP()_CFG113[EV_CNTR_LANE_SEL]. */
#else /* Word 0 - Little Endian */
        uint32_t ev_cntr_data          : 32; /**< [ 31:  0](RO) Event counter data.  This field returns data selected by PCIEEP()_CFG113[EV_CNTR_DATA_SEL]
                                                                 and PCIEEP()_CFG113[EV_CNTR_LANE_SEL]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg113_s cn; */
} bdk_pcieepx_cfg113_t;

static inline uint64_t BDK_PCIEEPX_CFG113(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG113(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001c4ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG113", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG113(a) bdk_pcieepx_cfg113_t
#define bustype_BDK_PCIEEPX_CFG113(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG113(a) "PCIEEPX_CFG113"
#define busnum_BDK_PCIEEPX_CFG113(a) (a)
#define arguments_BDK_PCIEEPX_CFG113(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg114
 *
 * PCI Express Vendor RAS DES Time Based Analysis Control Register
 * This register contains the one hundred fifteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg114_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t tbase_rpt_sel         : 8;  /**< [ 31: 24](R/W) Time-based report select.  Selects what type of data is measured for the selected
                                                                 duration.
                                                                 TBASE_DUR_SEL.  Data is returned in PCIEEP()_CFG115[TBASE_DATA].

                                                                 Each type of data is measured using one of three types of units.

                                                                 Core clock cycles.
                                                                 0x0 = Duration of 1 cycle.
                                                                 0x1 = TxL0s.
                                                                 0x2 = RxL0s.
                                                                 0x3 = L0.
                                                                 0x4 = L1.
                                                                 0x7 = Configuration/Recovery.

                                                                 Aux_clk cycles.
                                                                 0x5 = L1.1.
                                                                 0x6 = L1.2.

                                                                 Data bytes.  Actual amount is 16x value.
                                                                 0x20 = Tx TLP Bytes.
                                                                 0x21 = Rx TLP Bytes. */
        uint32_t reserved_16_23        : 8;
        uint32_t tbase_dur_sel         : 8;  /**< [ 15:  8](R/W) Time-based duration select.  Selects the duration of time-based
                                                                 anaylysis.

                                                                 0x0 = Manual control.  Analysis controlled by [TIMER_START].
                                                                 0x1 = 1ms.
                                                                 0x2 = 10ms.
                                                                 0x3 = 100ms.
                                                                 0x4 = 1s.
                                                                 0x5 = 2s.
                                                                 0x6 = 4s.
                                                                 0x7 - 0xf = Reserved. */
        uint32_t reserved_1_7          : 7;
        uint32_t timer_start           : 1;  /**< [  0:  0](R/W) Timer Start.

                                                                 0x0 = Start/Restart
                                                                 0x1 = Stop.

                                                                 This bit will be cleared automatically when the measurement is finished. */
#else /* Word 0 - Little Endian */
        uint32_t timer_start           : 1;  /**< [  0:  0](R/W) Timer Start.

                                                                 0x0 = Start/Restart
                                                                 0x1 = Stop.

                                                                 This bit will be cleared automatically when the measurement is finished. */
        uint32_t reserved_1_7          : 7;
        uint32_t tbase_dur_sel         : 8;  /**< [ 15:  8](R/W) Time-based duration select.  Selects the duration of time-based
                                                                 anaylysis.

                                                                 0x0 = Manual control.  Analysis controlled by [TIMER_START].
                                                                 0x1 = 1ms.
                                                                 0x2 = 10ms.
                                                                 0x3 = 100ms.
                                                                 0x4 = 1s.
                                                                 0x5 = 2s.
                                                                 0x6 = 4s.
                                                                 0x7 - 0xf = Reserved. */
        uint32_t reserved_16_23        : 8;
        uint32_t tbase_rpt_sel         : 8;  /**< [ 31: 24](R/W) Time-based report select.  Selects what type of data is measured for the selected
                                                                 duration.
                                                                 TBASE_DUR_SEL.  Data is returned in PCIEEP()_CFG115[TBASE_DATA].

                                                                 Each type of data is measured using one of three types of units.

                                                                 Core clock cycles.
                                                                 0x0 = Duration of 1 cycle.
                                                                 0x1 = TxL0s.
                                                                 0x2 = RxL0s.
                                                                 0x3 = L0.
                                                                 0x4 = L1.
                                                                 0x7 = Configuration/Recovery.

                                                                 Aux_clk cycles.
                                                                 0x5 = L1.1.
                                                                 0x6 = L1.2.

                                                                 Data bytes.  Actual amount is 16x value.
                                                                 0x20 = Tx TLP Bytes.
                                                                 0x21 = Rx TLP Bytes. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg114_s cn; */
} bdk_pcieepx_cfg114_t;

static inline uint64_t BDK_PCIEEPX_CFG114(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG114(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001c8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG114", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG114(a) bdk_pcieepx_cfg114_t
#define bustype_BDK_PCIEEPX_CFG114(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG114(a) "PCIEEPX_CFG114"
#define busnum_BDK_PCIEEPX_CFG114(a) (a)
#define arguments_BDK_PCIEEPX_CFG114(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg115
 *
 * PCI Express Vendor RAS DES Time Based Analysis Data Register
 * This register contains the one hundred sixteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg115_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t tbase_data            : 32; /**< [ 31:  0](RO/H) Time-based analysis data.  This register returns data selected in the
                                                                 PCIEEP()_CFG114[TBASE_RPT_SEL] field.  The results are cleared when
                                                                 the next measurement starts. */
#else /* Word 0 - Little Endian */
        uint32_t tbase_data            : 32; /**< [ 31:  0](RO/H) Time-based analysis data.  This register returns data selected in the
                                                                 PCIEEP()_CFG114[TBASE_RPT_SEL] field.  The results are cleared when
                                                                 the next measurement starts. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg115_s cn; */
} bdk_pcieepx_cfg115_t;

static inline uint64_t BDK_PCIEEPX_CFG115(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG115(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001ccll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG115", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG115(a) bdk_pcieepx_cfg115_t
#define bustype_BDK_PCIEEPX_CFG115(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG115(a) "PCIEEPX_CFG115"
#define busnum_BDK_PCIEEPX_CFG115(a) (a)
#define arguments_BDK_PCIEEPX_CFG115(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg116
 *
 * PCI Express Vendor RAS DES Error Injection Enable Register
 * This register contains the one hundred seventeenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg116_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_7_31         : 25;
        uint32_t einj6_en              : 1;  /**< [  6:  6](R/W) Specific TLP error injection enable.  Enables insertion of errors into the
                                                                 packet selected.  For more details, refer to PCIEEP()_CFG123. */
        uint32_t einj5_en              : 1;  /**< [  5:  5](R/W) TLP Duplicate/nullify error injection enable.  Enables insertion of duplicate/nullified
                                                                 TLPs.  For more details, refer to PCIEEP()_CFG122. */
        uint32_t einj4_en              : 1;  /**< [  4:  4](R/W) FC Credit update error injection enable.  Enables insertion of errors into
                                                                 Updated FCs. See PCIEEP()_CFG121. */
        uint32_t einj3_en              : 1;  /**< [  3:  3](R/W) Symbol datak mask or sync header error enable.  Enables data masking of special
                                                                 symbols or the breaking of the sync header.  See PCIEEP()_CFG120. */
        uint32_t einj2_en              : 1;  /**< [  2:  2](R/W) DLLP error injection enable.  enables insertion of DLLP errors.
                                                                 See PCIEEP()_CFG119. */
        uint32_t einj1_en              : 1;  /**< [  1:  1](R/W) Sequence number error injection enable.  Enables insertion of errors into
                                                                 sequence numbers.
                                                                 See PCIEEP()_CFG118. */
        uint32_t einj0_en              : 1;  /**< [  0:  0](R/W) CRC error injection enable.  Enables insertion of errors into various CRC.
                                                                 See PCIEEP()_CFG117. */
#else /* Word 0 - Little Endian */
        uint32_t einj0_en              : 1;  /**< [  0:  0](R/W) CRC error injection enable.  Enables insertion of errors into various CRC.
                                                                 See PCIEEP()_CFG117. */
        uint32_t einj1_en              : 1;  /**< [  1:  1](R/W) Sequence number error injection enable.  Enables insertion of errors into
                                                                 sequence numbers.
                                                                 See PCIEEP()_CFG118. */
        uint32_t einj2_en              : 1;  /**< [  2:  2](R/W) DLLP error injection enable.  enables insertion of DLLP errors.
                                                                 See PCIEEP()_CFG119. */
        uint32_t einj3_en              : 1;  /**< [  3:  3](R/W) Symbol datak mask or sync header error enable.  Enables data masking of special
                                                                 symbols or the breaking of the sync header.  See PCIEEP()_CFG120. */
        uint32_t einj4_en              : 1;  /**< [  4:  4](R/W) FC Credit update error injection enable.  Enables insertion of errors into
                                                                 Updated FCs. See PCIEEP()_CFG121. */
        uint32_t einj5_en              : 1;  /**< [  5:  5](R/W) TLP Duplicate/nullify error injection enable.  Enables insertion of duplicate/nullified
                                                                 TLPs.  For more details, refer to PCIEEP()_CFG122. */
        uint32_t einj6_en              : 1;  /**< [  6:  6](R/W) Specific TLP error injection enable.  Enables insertion of errors into the
                                                                 packet selected.  For more details, refer to PCIEEP()_CFG123. */
        uint32_t reserved_7_31         : 25;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg116_s cn; */
} bdk_pcieepx_cfg116_t;

static inline uint64_t BDK_PCIEEPX_CFG116(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG116(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001d0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG116", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG116(a) bdk_pcieepx_cfg116_t
#define bustype_BDK_PCIEEPX_CFG116(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG116(a) "PCIEEPX_CFG116"
#define busnum_BDK_PCIEEPX_CFG116(a) (a)
#define arguments_BDK_PCIEEPX_CFG116(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg117
 *
 * PCI Express Vendor RAS DES Error Injection Control 0 (CRC) Register
 * This register contains the one hundred eighteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg117_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_12_31        : 20;
        uint32_t einj0_crc_type        : 4;  /**< [ 11:  8](R/W) Error injection type.  Selects the type of CRC error tp in inserted.

                                                                 TX Path:
                                                                 0x0 = New TLP's LCRC error injestion.
                                                                 0x1 = 16bCRC error injection of ACK/NAK DLLP.
                                                                 0x2 = 16bCRC error injection of Update-FC DLLP.
                                                                 0x3 = New TLP's ECRC error injection.
                                                                 0x4 = New TLP's FCRC error injection (128b/130b).
                                                                 0x5 = Parity error of TSOS (128b/130b).
                                                                 0x6 = Parity error of SKPOS (128b/130b).
                                                                 0x7 = Reserved.

                                                                 RX Path:
                                                                 0x8 = LCRC error injection.
                                                                 0x9 = ECRC error injection.
                                                                 0xa - 0xf = Reserved. */
        uint32_t einj0_cnt             : 8;  /**< [  7:  0](R/W) Error injection count.  Indicates the number of errors.
                                                                 This register is decremented when errors are inserted.

                                                                 If the counter value is 0x1 and error is inserted,
                                                                 PCIEEP()_CFG116[EINJ0_EN] returns zero.

                                                                 If the counter value is 0x0 and PCIEEP()_CFG116[EINJ0_EN] is set,
                                                                 errors are inserted until PCIEEP()_CFG116[EINJ0_EN] is cleared. */
#else /* Word 0 - Little Endian */
        uint32_t einj0_cnt             : 8;  /**< [  7:  0](R/W) Error injection count.  Indicates the number of errors.
                                                                 This register is decremented when errors are inserted.

                                                                 If the counter value is 0x1 and error is inserted,
                                                                 PCIEEP()_CFG116[EINJ0_EN] returns zero.

                                                                 If the counter value is 0x0 and PCIEEP()_CFG116[EINJ0_EN] is set,
                                                                 errors are inserted until PCIEEP()_CFG116[EINJ0_EN] is cleared. */
        uint32_t einj0_crc_type        : 4;  /**< [ 11:  8](R/W) Error injection type.  Selects the type of CRC error tp in inserted.

                                                                 TX Path:
                                                                 0x0 = New TLP's LCRC error injestion.
                                                                 0x1 = 16bCRC error injection of ACK/NAK DLLP.
                                                                 0x2 = 16bCRC error injection of Update-FC DLLP.
                                                                 0x3 = New TLP's ECRC error injection.
                                                                 0x4 = New TLP's FCRC error injection (128b/130b).
                                                                 0x5 = Parity error of TSOS (128b/130b).
                                                                 0x6 = Parity error of SKPOS (128b/130b).
                                                                 0x7 = Reserved.

                                                                 RX Path:
                                                                 0x8 = LCRC error injection.
                                                                 0x9 = ECRC error injection.
                                                                 0xa - 0xf = Reserved. */
        uint32_t reserved_12_31        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg117_s cn; */
} bdk_pcieepx_cfg117_t;

static inline uint64_t BDK_PCIEEPX_CFG117(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG117(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001d4ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG117", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG117(a) bdk_pcieepx_cfg117_t
#define bustype_BDK_PCIEEPX_CFG117(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG117(a) "PCIEEPX_CFG117"
#define busnum_BDK_PCIEEPX_CFG117(a) (a)
#define arguments_BDK_PCIEEPX_CFG117(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg118
 *
 * PCI Express Vendor RAS DES Error Injection Control 1 (SEQNUM) Register
 * This register contains the one hundred nineteenth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg118_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_29_31        : 3;
        uint32_t einj1_bad_seqnum      : 13; /**< [ 28: 16](R/W) Bad sequence number. Indicates the value to add/subtract
                                                                 from the naturally-assigned sequence numbers. This value is
                                                                 represented by two's complement.

                                                                 0x0fff = +4095.

                                                                 0x0002 = +2.
                                                                 0x0001 = +1.
                                                                 0x0000 = 0.
                                                                 0x1fff = -1.
                                                                 0x1ffe = -2.

                                                                 0x1001 = -4095. */
        uint32_t reserved_12_15        : 4;
        uint32_t einj1_seqnum_type     : 4;  /**< [ 11:  8](R/W) Sequence Number Type.  Selects the type of sequence number.

                                                                 0x0 = Insertion of New TLP's SEQ error.
                                                                 0x1 = Insertion of ACK/NAK DLLP's SEQ error. */
        uint32_t einj1_cnt             : 8;  /**< [  7:  0](R/W) Error injection count.  Indicates the number of errors.
                                                                 This register is decremented when errors are inserted.

                                                                 If the counter value is 0x1 and error is inserted,
                                                                 PCIEEP()_CFG116[EINJ1_EN] returns zero.

                                                                 If the counter value is 0x0 and PCIEEP()_CFG116[EINJ1_EN] is set,
                                                                 errors are inserted until PCIEEP()_CFG116[EINJ1_EN] is cleared. */
#else /* Word 0 - Little Endian */
        uint32_t einj1_cnt             : 8;  /**< [  7:  0](R/W) Error injection count.  Indicates the number of errors.
                                                                 This register is decremented when errors are inserted.

                                                                 If the counter value is 0x1 and error is inserted,
                                                                 PCIEEP()_CFG116[EINJ1_EN] returns zero.

                                                                 If the counter value is 0x0 and PCIEEP()_CFG116[EINJ1_EN] is set,
                                                                 errors are inserted until PCIEEP()_CFG116[EINJ1_EN] is cleared. */
        uint32_t einj1_seqnum_type     : 4;  /**< [ 11:  8](R/W) Sequence Number Type.  Selects the type of sequence number.

                                                                 0x0 = Insertion of New TLP's SEQ error.
                                                                 0x1 = Insertion of ACK/NAK DLLP's SEQ error. */
        uint32_t reserved_12_15        : 4;
        uint32_t einj1_bad_seqnum      : 13; /**< [ 28: 16](R/W) Bad sequence number. Indicates the value to add/subtract
                                                                 from the naturally-assigned sequence numbers. This value is
                                                                 represented by two's complement.

                                                                 0x0fff = +4095.

                                                                 0x0002 = +2.
                                                                 0x0001 = +1.
                                                                 0x0000 = 0.
                                                                 0x1fff = -1.
                                                                 0x1ffe = -2.

                                                                 0x1001 = -4095. */
        uint32_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg118_s cn; */
} bdk_pcieepx_cfg118_t;

static inline uint64_t BDK_PCIEEPX_CFG118(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG118(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001d8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG118", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG118(a) bdk_pcieepx_cfg118_t
#define bustype_BDK_PCIEEPX_CFG118(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG118(a) "PCIEEPX_CFG118"
#define busnum_BDK_PCIEEPX_CFG118(a) (a)
#define arguments_BDK_PCIEEPX_CFG118(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg119
 *
 * PCI Express Vendor RAS DES Error Injection Control 2 (DLLP) Register
 * This register contains the one hundred twentyith 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg119_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_10_31        : 22;
        uint32_t einj2_dllp_type       : 2;  /**< [  9:  8](R/W) DLLP type.  Selects the type of DLLP errors to be inserted.

                                                                 0x0 = ACK/NAK DLLP transmission block.
                                                                 0x1 = Update FC DLLP's transmission block.
                                                                 0x2 = Always transmission for NAK DLLP.
                                                                 0x3 = Reserved. */
        uint32_t einj2_cnt             : 8;  /**< [  7:  0](R/W) Error injection count.  Indicates the number of errors.
                                                                 This register is decremented when errors are inserted.

                                                                 If the counter value is 0x1 and error is inserted,
                                                                 PCIEEP()_CFG116[EINJ2_EN] returns zero.

                                                                 If the counter value is 0x0 and PCIEEP()_CFG116[EINJ2_EN] is set,
                                                                 errors are inserted until PCIEEP()_CFG116[EINJ2_EN] is cleared. */
#else /* Word 0 - Little Endian */
        uint32_t einj2_cnt             : 8;  /**< [  7:  0](R/W) Error injection count.  Indicates the number of errors.
                                                                 This register is decremented when errors are inserted.

                                                                 If the counter value is 0x1 and error is inserted,
                                                                 PCIEEP()_CFG116[EINJ2_EN] returns zero.

                                                                 If the counter value is 0x0 and PCIEEP()_CFG116[EINJ2_EN] is set,
                                                                 errors are inserted until PCIEEP()_CFG116[EINJ2_EN] is cleared. */
        uint32_t einj2_dllp_type       : 2;  /**< [  9:  8](R/W) DLLP type.  Selects the type of DLLP errors to be inserted.

                                                                 0x0 = ACK/NAK DLLP transmission block.
                                                                 0x1 = Update FC DLLP's transmission block.
                                                                 0x2 = Always transmission for NAK DLLP.
                                                                 0x3 = Reserved. */
        uint32_t reserved_10_31        : 22;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg119_s cn; */
} bdk_pcieepx_cfg119_t;

static inline uint64_t BDK_PCIEEPX_CFG119(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG119(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001dcll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG119", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG119(a) bdk_pcieepx_cfg119_t
#define bustype_BDK_PCIEEPX_CFG119(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG119(a) "PCIEEPX_CFG119"
#define busnum_BDK_PCIEEPX_CFG119(a) (a)
#define arguments_BDK_PCIEEPX_CFG119(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg120
 *
 * PCI Express Vendor RAS DES Error Injection Control 3 (Symbol) Register
 * This register contains the one hundred twenty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg120_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_11_31        : 21;
        uint32_t einj3_symbol_type     : 3;  /**< [ 10:  8](R/W) Error type, 8b/10b encoding - Mask K symbol.

                                                                 0x0 = Reserved.
                                                                 0x1 = COM/PAD(TS1 Order Set).
                                                                 0x2 = COM/PAD(TS2 Order Set).
                                                                 0x3 = COM/FTS(FTS Order Set).
                                                                 0x4 = COM/IDLE(E-Idle Order Set).
                                                                 0x5 = END/EDB Symbol.
                                                                 0x6 = STP/SDP Symbol.
                                                                 0x7 = COM/SKP(SKP Order set). */
        uint32_t einj3_cnt             : 8;  /**< [  7:  0](R/W) Error injection count.  Indicates the number of errors.
                                                                 This register is decremented when errors are inserted.

                                                                 If the counter value is 0x1 and error is inserted,
                                                                 PCIEEP()_CFG116[EINJ3_EN] returns zero.

                                                                 If the counter value is 0x0 and PCIEEP()_CFG116[EINJ3_EN] is set,
                                                                 errors are inserted until PCIEEP()_CFG116[EINJ3_EN] is cleared. */
#else /* Word 0 - Little Endian */
        uint32_t einj3_cnt             : 8;  /**< [  7:  0](R/W) Error injection count.  Indicates the number of errors.
                                                                 This register is decremented when errors are inserted.

                                                                 If the counter value is 0x1 and error is inserted,
                                                                 PCIEEP()_CFG116[EINJ3_EN] returns zero.

                                                                 If the counter value is 0x0 and PCIEEP()_CFG116[EINJ3_EN] is set,
                                                                 errors are inserted until PCIEEP()_CFG116[EINJ3_EN] is cleared. */
        uint32_t einj3_symbol_type     : 3;  /**< [ 10:  8](R/W) Error type, 8b/10b encoding - Mask K symbol.

                                                                 0x0 = Reserved.
                                                                 0x1 = COM/PAD(TS1 Order Set).
                                                                 0x2 = COM/PAD(TS2 Order Set).
                                                                 0x3 = COM/FTS(FTS Order Set).
                                                                 0x4 = COM/IDLE(E-Idle Order Set).
                                                                 0x5 = END/EDB Symbol.
                                                                 0x6 = STP/SDP Symbol.
                                                                 0x7 = COM/SKP(SKP Order set). */
        uint32_t reserved_11_31        : 21;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg120_s cn; */
} bdk_pcieepx_cfg120_t;

static inline uint64_t BDK_PCIEEPX_CFG120(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG120(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001e0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG120", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG120(a) bdk_pcieepx_cfg120_t
#define bustype_BDK_PCIEEPX_CFG120(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG120(a) "PCIEEPX_CFG120"
#define busnum_BDK_PCIEEPX_CFG120(a) (a)
#define arguments_BDK_PCIEEPX_CFG120(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg121
 *
 * PCI Express Vendor RAS DES Error Injection Control 4 (FC Credit) Register
 * This register contains the one hundred twenty-second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg121_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_29_31        : 3;
        uint32_t einj4_bad_updfc_val   : 13; /**< [ 28: 16](R/W) Bad update-FC credit value.  Indicates the value to add/subtract
                                                                 from the UpdateFC credit.  The value is represented by two's
                                                                 compliment.

                                                                 0x0fff = +4095.

                                                                 0x0002 = +2.
                                                                 0x0001 = +1.
                                                                 0x0000 = 0.
                                                                 0x1fff = -1.
                                                                 0x1ffe = -2.

                                                                 0x1001 = -4095. */
        uint32_t reserved_15           : 1;
        uint32_t einj4_vc_num          : 3;  /**< [ 14: 12](R/W) VC Number.  Indicates the target VC Number. */
        uint32_t reserved_11           : 1;
        uint32_t einj4_vc_type         : 3;  /**< [ 10:  8](R/W) Update-FC type.  Selects the credit type.

                                                                 0x0 = Posted TLP Header Credit value control.
                                                                 0x1 = Non-Posted TLP Header Credit value control.
                                                                 0x2 = Completion TLP Header Credit value control.
                                                                 0x3 = Reserved.
                                                                 0x4 = Posted TLP Data Credit value control.
                                                                 0x5 = Non-Posted TLP Data Credit value control.
                                                                 0x6 = Completion TLP Data Credit value control.
                                                                 0x7 = Reserved. */
        uint32_t einj4_cnt             : 8;  /**< [  7:  0](R/W) Error injection count.  Indicates the number of errors.
                                                                 This register is decremented when errors are inserted.

                                                                 If the counter value is 0x1 and error is inserted,
                                                                 PCIEEP()_CFG116[EINJ4_EN] returns zero.

                                                                 If the counter value is 0x0 and PCIEEP()_CFG116[EINJ4_EN] is set,
                                                                 errors are inserted until PCIEEP()_CFG116[EINJ4_EN] is cleared. */
#else /* Word 0 - Little Endian */
        uint32_t einj4_cnt             : 8;  /**< [  7:  0](R/W) Error injection count.  Indicates the number of errors.
                                                                 This register is decremented when errors are inserted.

                                                                 If the counter value is 0x1 and error is inserted,
                                                                 PCIEEP()_CFG116[EINJ4_EN] returns zero.

                                                                 If the counter value is 0x0 and PCIEEP()_CFG116[EINJ4_EN] is set,
                                                                 errors are inserted until PCIEEP()_CFG116[EINJ4_EN] is cleared. */
        uint32_t einj4_vc_type         : 3;  /**< [ 10:  8](R/W) Update-FC type.  Selects the credit type.

                                                                 0x0 = Posted TLP Header Credit value control.
                                                                 0x1 = Non-Posted TLP Header Credit value control.
                                                                 0x2 = Completion TLP Header Credit value control.
                                                                 0x3 = Reserved.
                                                                 0x4 = Posted TLP Data Credit value control.
                                                                 0x5 = Non-Posted TLP Data Credit value control.
                                                                 0x6 = Completion TLP Data Credit value control.
                                                                 0x7 = Reserved. */
        uint32_t reserved_11           : 1;
        uint32_t einj4_vc_num          : 3;  /**< [ 14: 12](R/W) VC Number.  Indicates the target VC Number. */
        uint32_t reserved_15           : 1;
        uint32_t einj4_bad_updfc_val   : 13; /**< [ 28: 16](R/W) Bad update-FC credit value.  Indicates the value to add/subtract
                                                                 from the UpdateFC credit.  The value is represented by two's
                                                                 compliment.

                                                                 0x0fff = +4095.

                                                                 0x0002 = +2.
                                                                 0x0001 = +1.
                                                                 0x0000 = 0.
                                                                 0x1fff = -1.
                                                                 0x1ffe = -2.

                                                                 0x1001 = -4095. */
        uint32_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg121_s cn; */
} bdk_pcieepx_cfg121_t;

static inline uint64_t BDK_PCIEEPX_CFG121(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG121(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001e4ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG121", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG121(a) bdk_pcieepx_cfg121_t
#define bustype_BDK_PCIEEPX_CFG121(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG121(a) "PCIEEPX_CFG121"
#define busnum_BDK_PCIEEPX_CFG121(a) (a)
#define arguments_BDK_PCIEEPX_CFG121(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg122
 *
 * PCI Express Vendor RAS DES Error Injection Control 5 (Specific TLP) Register
 * This register contains the one hundred twenty-third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg122_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t einj5_sp_tlp          : 1;  /**< [  8:  8](R/W) Specified TLP.  Selects the specified TLP to be inserted.

                                                                 0x0 = Generates duplicate TLPs by handling ACK DLLP as NAK DLLP
                                                                 0x1 = Generates Nullified TLP (Original TLP will be stored in retry buffer). */
        uint32_t einj5_cnt             : 8;  /**< [  7:  0](R/W) Error injection count.  Indicates the number of errors.
                                                                 This register is decremented when errors are inserted.

                                                                 If the counter value is 0x1 and error is inserted,
                                                                 PCIEEP()_CFG116[EINJ5_EN] returns zero.

                                                                 If the counter value is 0x0 and PCIEEP()_CFG116[EINJ5_EN] is set,
                                                                 errors are inserted until PCIEEP()_CFG116[EINJ5_EN] is cleared. */
#else /* Word 0 - Little Endian */
        uint32_t einj5_cnt             : 8;  /**< [  7:  0](R/W) Error injection count.  Indicates the number of errors.
                                                                 This register is decremented when errors are inserted.

                                                                 If the counter value is 0x1 and error is inserted,
                                                                 PCIEEP()_CFG116[EINJ5_EN] returns zero.

                                                                 If the counter value is 0x0 and PCIEEP()_CFG116[EINJ5_EN] is set,
                                                                 errors are inserted until PCIEEP()_CFG116[EINJ5_EN] is cleared. */
        uint32_t einj5_sp_tlp          : 1;  /**< [  8:  8](R/W) Specified TLP.  Selects the specified TLP to be inserted.

                                                                 0x0 = Generates duplicate TLPs by handling ACK DLLP as NAK DLLP
                                                                 0x1 = Generates Nullified TLP (Original TLP will be stored in retry buffer). */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg122_s cn; */
} bdk_pcieepx_cfg122_t;

static inline uint64_t BDK_PCIEEPX_CFG122(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG122(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001e8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG122", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG122(a) bdk_pcieepx_cfg122_t
#define bustype_BDK_PCIEEPX_CFG122(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG122(a) "PCIEEPX_CFG122"
#define busnum_BDK_PCIEEPX_CFG122(a) (a)
#define arguments_BDK_PCIEEPX_CFG122(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg123
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Compare Point H0) Register
 * This register contains the one hundred twenty-fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg123_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_com_pt_h0       : 32; /**< [ 31:  0](R/W) Packet compare point 1st DWORD.
                                                                 Specifies which Tx TLP header DWORD0 bits to compare
                                                                 with the corresponding bits in PCIEEP()_CFG127[EIN6_COM_VAL_H0].
                                                                 When all specified bits (in the Tx TLP header and
                                                                 PCIEEP()_CFG127[EIN6_COM_VAL_H0] match, an error is inserted into the TLP. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_com_pt_h0       : 32; /**< [ 31:  0](R/W) Packet compare point 1st DWORD.
                                                                 Specifies which Tx TLP header DWORD0 bits to compare
                                                                 with the corresponding bits in PCIEEP()_CFG127[EIN6_COM_VAL_H0].
                                                                 When all specified bits (in the Tx TLP header and
                                                                 PCIEEP()_CFG127[EIN6_COM_VAL_H0] match, an error is inserted into the TLP. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg123_s cn; */
} bdk_pcieepx_cfg123_t;

static inline uint64_t BDK_PCIEEPX_CFG123(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG123(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001ecll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG123", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG123(a) bdk_pcieepx_cfg123_t
#define bustype_BDK_PCIEEPX_CFG123(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG123(a) "PCIEEPX_CFG123"
#define busnum_BDK_PCIEEPX_CFG123(a) (a)
#define arguments_BDK_PCIEEPX_CFG123(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg124
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Compare Point H1) Register
 * This register contains the one hundred twenty-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg124_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_com_pt_h1       : 32; /**< [ 31:  0](R/W) Packet compare point 2nd DWORD.
                                                                 Specifies which Tx TLP header DWORD1 bits to compare
                                                                 with the corresponding bits in PCIEEP()_CFG128[EIN6_COM_VAL_H1].
                                                                 When all specified bits (in the Tx TLP header and
                                                                 PCIEEP()_CFG128[EIN6_COM_VAL_H1] match, an error is inserted into the TLP. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_com_pt_h1       : 32; /**< [ 31:  0](R/W) Packet compare point 2nd DWORD.
                                                                 Specifies which Tx TLP header DWORD1 bits to compare
                                                                 with the corresponding bits in PCIEEP()_CFG128[EIN6_COM_VAL_H1].
                                                                 When all specified bits (in the Tx TLP header and
                                                                 PCIEEP()_CFG128[EIN6_COM_VAL_H1] match, an error is inserted into the TLP. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg124_s cn; */
} bdk_pcieepx_cfg124_t;

static inline uint64_t BDK_PCIEEPX_CFG124(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG124(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001f0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG124", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG124(a) bdk_pcieepx_cfg124_t
#define bustype_BDK_PCIEEPX_CFG124(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG124(a) "PCIEEPX_CFG124"
#define busnum_BDK_PCIEEPX_CFG124(a) (a)
#define arguments_BDK_PCIEEPX_CFG124(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg125
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Compare Point H2) Register
 * This register contains the one hundred twenty-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg125_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_com_pt_h2       : 32; /**< [ 31:  0](R/W) Packet compare point 3rd DWORD.
                                                                 Specifies which Tx TLP header DWORD2 bits to compare
                                                                 with the corresponding bits in PCIEEP()_CFG129[EIN6_COM_VAL_H2].
                                                                 When all specified bits (in the Tx TLP header and
                                                                 PCIEEP()_CFG129[EIN6_COM_VAL_H2] match, an error is inserted into the TLP. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_com_pt_h2       : 32; /**< [ 31:  0](R/W) Packet compare point 3rd DWORD.
                                                                 Specifies which Tx TLP header DWORD2 bits to compare
                                                                 with the corresponding bits in PCIEEP()_CFG129[EIN6_COM_VAL_H2].
                                                                 When all specified bits (in the Tx TLP header and
                                                                 PCIEEP()_CFG129[EIN6_COM_VAL_H2] match, an error is inserted into the TLP. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg125_s cn; */
} bdk_pcieepx_cfg125_t;

static inline uint64_t BDK_PCIEEPX_CFG125(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG125(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001f8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG125", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG125(a) bdk_pcieepx_cfg125_t
#define bustype_BDK_PCIEEPX_CFG125(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG125(a) "PCIEEPX_CFG125"
#define busnum_BDK_PCIEEPX_CFG125(a) (a)
#define arguments_BDK_PCIEEPX_CFG125(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg126
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Compare Point H3) Register
 * This register contains the one hundred twenty-seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg126_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_com_pt_h3       : 32; /**< [ 31:  0](R/W) Packet compare point 4th DWORD.
                                                                 Specifies which Tx TLP header DWORD3 bits to compare
                                                                 with the corresponding bits in PCIEEP()_CFG130[EIN6_COM_VAL_H3].
                                                                 When all specified bits (in the Tx TLP header and
                                                                 PCIEEP()_CFG130[EIN6_COM_VAL_H3] match, an error is inserted into the TLP. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_com_pt_h3       : 32; /**< [ 31:  0](R/W) Packet compare point 4th DWORD.
                                                                 Specifies which Tx TLP header DWORD3 bits to compare
                                                                 with the corresponding bits in PCIEEP()_CFG130[EIN6_COM_VAL_H3].
                                                                 When all specified bits (in the Tx TLP header and
                                                                 PCIEEP()_CFG130[EIN6_COM_VAL_H3] match, an error is inserted into the TLP. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg126_s cn; */
} bdk_pcieepx_cfg126_t;

static inline uint64_t BDK_PCIEEPX_CFG126(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG126(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000001fcll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG126", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG126(a) bdk_pcieepx_cfg126_t
#define bustype_BDK_PCIEEPX_CFG126(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG126(a) "PCIEEPX_CFG126"
#define busnum_BDK_PCIEEPX_CFG126(a) (a)
#define arguments_BDK_PCIEEPX_CFG126(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg127
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Compare Value H0) Register
 * This register contains the one hundred twenty-eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg127_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_com_val_h0      : 32; /**< [ 31:  0](R/W) Packet compare value 1st DWORD.
                                                                 Specifies the value to compare against Tx the TLP header
                                                                 DWORD0 bits specified in PCIEEP()_CFG123[EINJ_COM_PT_H0]. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_com_val_h0      : 32; /**< [ 31:  0](R/W) Packet compare value 1st DWORD.
                                                                 Specifies the value to compare against Tx the TLP header
                                                                 DWORD0 bits specified in PCIEEP()_CFG123[EINJ_COM_PT_H0]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg127_s cn; */
} bdk_pcieepx_cfg127_t;

static inline uint64_t BDK_PCIEEPX_CFG127(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG127(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000200ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG127", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG127(a) bdk_pcieepx_cfg127_t
#define bustype_BDK_PCIEEPX_CFG127(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG127(a) "PCIEEPX_CFG127"
#define busnum_BDK_PCIEEPX_CFG127(a) (a)
#define arguments_BDK_PCIEEPX_CFG127(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg128
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Compare Value H0) Register
 * This register contains the one hundred twenty-nineth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg128_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_com_val_h0      : 32; /**< [ 31:  0](R/W) Packet compare value 1st DWORD.
                                                                 Specifies the value to compare against Tx the TLP header
                                                                 DWORD0 bits specified in PCIEEP()_CFG123[EINJ_COM_PT_H0]. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_com_val_h0      : 32; /**< [ 31:  0](R/W) Packet compare value 1st DWORD.
                                                                 Specifies the value to compare against Tx the TLP header
                                                                 DWORD0 bits specified in PCIEEP()_CFG123[EINJ_COM_PT_H0]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg128_s cn; */
} bdk_pcieepx_cfg128_t;

static inline uint64_t BDK_PCIEEPX_CFG128(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG128(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000204ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG128", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG128(a) bdk_pcieepx_cfg128_t
#define bustype_BDK_PCIEEPX_CFG128(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG128(a) "PCIEEPX_CFG128"
#define busnum_BDK_PCIEEPX_CFG128(a) (a)
#define arguments_BDK_PCIEEPX_CFG128(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg129
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Compare Value H1) Register
 * This register contains the one hundred thirtyith 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg129_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_com_val_h1      : 32; /**< [ 31:  0](R/W) Packet compare value 2nd DWORD.
                                                                 Specifies the value to compare against Tx the TLP header
                                                                 DWORD1 bits specified in PCIEEP()_CFG124[EINJ_COM_PT_H1]. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_com_val_h1      : 32; /**< [ 31:  0](R/W) Packet compare value 2nd DWORD.
                                                                 Specifies the value to compare against Tx the TLP header
                                                                 DWORD1 bits specified in PCIEEP()_CFG124[EINJ_COM_PT_H1]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg129_s cn; */
} bdk_pcieepx_cfg129_t;

static inline uint64_t BDK_PCIEEPX_CFG129(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG129(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000208ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG129", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG129(a) bdk_pcieepx_cfg129_t
#define bustype_BDK_PCIEEPX_CFG129(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG129(a) "PCIEEPX_CFG129"
#define busnum_BDK_PCIEEPX_CFG129(a) (a)
#define arguments_BDK_PCIEEPX_CFG129(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg130
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Compare Value H2) Register
 * This register contains the one hundred thirty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg130_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_com_val_h2      : 32; /**< [ 31:  0](R/W) Packet compare value 3rd DWORD.
                                                                 Specifies the value to compare against Tx the TLP header
                                                                 DWORD2 bits specified in the PCIEEP()_CFG125[EINJ_COM_PT_H3]. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_com_val_h2      : 32; /**< [ 31:  0](R/W) Packet compare value 3rd DWORD.
                                                                 Specifies the value to compare against Tx the TLP header
                                                                 DWORD2 bits specified in the PCIEEP()_CFG125[EINJ_COM_PT_H3]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg130_s cn; */
} bdk_pcieepx_cfg130_t;

static inline uint64_t BDK_PCIEEPX_CFG130(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG130(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000020cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG130", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG130(a) bdk_pcieepx_cfg130_t
#define bustype_BDK_PCIEEPX_CFG130(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG130(a) "PCIEEPX_CFG130"
#define busnum_BDK_PCIEEPX_CFG130(a) (a)
#define arguments_BDK_PCIEEPX_CFG130(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg131
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Compare Value H3) Register
 * This register contains the one hundred thirty-second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg131_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_com_val_h3      : 32; /**< [ 31:  0](R/W) Packet compare value 4th DWORD.
                                                                 Specifies the value to compare against Tx the TLP header
                                                                 DWORD3 bits specified in the PCIEEP()_CFG126[EINJ_COM_PT_H4]. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_com_val_h3      : 32; /**< [ 31:  0](R/W) Packet compare value 4th DWORD.
                                                                 Specifies the value to compare against Tx the TLP header
                                                                 DWORD3 bits specified in the PCIEEP()_CFG126[EINJ_COM_PT_H4]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg131_s cn; */
} bdk_pcieepx_cfg131_t;

static inline uint64_t BDK_PCIEEPX_CFG131(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG131(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000210ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG131", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG131(a) bdk_pcieepx_cfg131_t
#define bustype_BDK_PCIEEPX_CFG131(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG131(a) "PCIEEPX_CFG131"
#define busnum_BDK_PCIEEPX_CFG131(a) (a)
#define arguments_BDK_PCIEEPX_CFG131(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg132
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Change Point H0) Register
 * This register contains the one hundred thirty-third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg132_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_chg_pt_h0       : 32; /**< [ 31:  0](R/W) Packet change point 1st DWORD.
                                                                 Specifies which Tx TLP header DWORD0 bits to replace
                                                                 with the corresponding bits in PCIEEP()_CFG135[EINJ6_CHG_VAL_H0]. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_chg_pt_h0       : 32; /**< [ 31:  0](R/W) Packet change point 1st DWORD.
                                                                 Specifies which Tx TLP header DWORD0 bits to replace
                                                                 with the corresponding bits in PCIEEP()_CFG135[EINJ6_CHG_VAL_H0]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg132_s cn; */
} bdk_pcieepx_cfg132_t;

static inline uint64_t BDK_PCIEEPX_CFG132(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG132(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000214ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG132", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG132(a) bdk_pcieepx_cfg132_t
#define bustype_BDK_PCIEEPX_CFG132(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG132(a) "PCIEEPX_CFG132"
#define busnum_BDK_PCIEEPX_CFG132(a) (a)
#define arguments_BDK_PCIEEPX_CFG132(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg133
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Change Point H1) Register
 * This register contains the one hundred thirty-fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg133_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_chg_pt_h1       : 32; /**< [ 31:  0](R/W) Packet change point 2nd DWORD.
                                                                 Specifies which Tx TLP header DWORD0 bits to replace
                                                                 with the corresponding bits in PCIEEP()_CFG136[EINJ6_CHG_VAL_H1]. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_chg_pt_h1       : 32; /**< [ 31:  0](R/W) Packet change point 2nd DWORD.
                                                                 Specifies which Tx TLP header DWORD0 bits to replace
                                                                 with the corresponding bits in PCIEEP()_CFG136[EINJ6_CHG_VAL_H1]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg133_s cn; */
} bdk_pcieepx_cfg133_t;

static inline uint64_t BDK_PCIEEPX_CFG133(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG133(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000218ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG133", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG133(a) bdk_pcieepx_cfg133_t
#define bustype_BDK_PCIEEPX_CFG133(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG133(a) "PCIEEPX_CFG133"
#define busnum_BDK_PCIEEPX_CFG133(a) (a)
#define arguments_BDK_PCIEEPX_CFG133(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg134
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Change Point H2) Register
 * This register contains the one hundred thirty-fifith 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg134_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_chg_pt_h2       : 32; /**< [ 31:  0](R/W) Packet change point 3rd DWORD.
                                                                 Specifies which Tx TLP header DWORD2 bits to replace
                                                                 with the corresponding bits in PCIEEP()_CFG137[EINJ6_CHG_VAL_H2]. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_chg_pt_h2       : 32; /**< [ 31:  0](R/W) Packet change point 3rd DWORD.
                                                                 Specifies which Tx TLP header DWORD2 bits to replace
                                                                 with the corresponding bits in PCIEEP()_CFG137[EINJ6_CHG_VAL_H2]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg134_s cn; */
} bdk_pcieepx_cfg134_t;

static inline uint64_t BDK_PCIEEPX_CFG134(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG134(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000021cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG134", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG134(a) bdk_pcieepx_cfg134_t
#define bustype_BDK_PCIEEPX_CFG134(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG134(a) "PCIEEPX_CFG134"
#define busnum_BDK_PCIEEPX_CFG134(a) (a)
#define arguments_BDK_PCIEEPX_CFG134(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg135
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Change Point H3) Register
 * This register contains the one hundred thirty-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg135_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_chg_pt_h3       : 32; /**< [ 31:  0](R/W) Packet change point 1st DWORD.
                                                                 Specifies which Tx TLP header DWORD3 bits to replace
                                                                 with the corresponding bits in PCIEEP()_CFG138[EINJ6_CHG_VAL_H3]. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_chg_pt_h3       : 32; /**< [ 31:  0](R/W) Packet change point 1st DWORD.
                                                                 Specifies which Tx TLP header DWORD3 bits to replace
                                                                 with the corresponding bits in PCIEEP()_CFG138[EINJ6_CHG_VAL_H3]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg135_s cn; */
} bdk_pcieepx_cfg135_t;

static inline uint64_t BDK_PCIEEPX_CFG135(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG135(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000220ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG135", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG135(a) bdk_pcieepx_cfg135_t
#define bustype_BDK_PCIEEPX_CFG135(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG135(a) "PCIEEPX_CFG135"
#define busnum_BDK_PCIEEPX_CFG135(a) (a)
#define arguments_BDK_PCIEEPX_CFG135(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg136
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Change Value H0) Register
 * This register contains the one hundred thirty-seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg136_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_chg_val_h0      : 32; /**< [ 31:  0](R/W) Packet change value 1st DWORD.
                                                                 Specifies replacement values for the Tx TLP header
                                                                 DWORD0 bits defined in the PCIEEP()_CFG131[EINJ6_CHG_PT_H0].
                                                                 Only applies when PCIEEP()_CFG139[EINJ6_INV_CNTL] is not set. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_chg_val_h0      : 32; /**< [ 31:  0](R/W) Packet change value 1st DWORD.
                                                                 Specifies replacement values for the Tx TLP header
                                                                 DWORD0 bits defined in the PCIEEP()_CFG131[EINJ6_CHG_PT_H0].
                                                                 Only applies when PCIEEP()_CFG139[EINJ6_INV_CNTL] is not set. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg136_s cn; */
} bdk_pcieepx_cfg136_t;

static inline uint64_t BDK_PCIEEPX_CFG136(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG136(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000224ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG136", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG136(a) bdk_pcieepx_cfg136_t
#define bustype_BDK_PCIEEPX_CFG136(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG136(a) "PCIEEPX_CFG136"
#define busnum_BDK_PCIEEPX_CFG136(a) (a)
#define arguments_BDK_PCIEEPX_CFG136(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg137
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Change Value H1) Register
 * This register contains the one hundred thirty-eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg137_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_chg_val_h1      : 32; /**< [ 31:  0](R/W) Packet change value 2nd DWORD.
                                                                 Specifies replacement values for the Tx TLP header
                                                                 DWORD1 bits defined in the PCIEEP()_CFG132[EINJ6_CHG_PT_H1].
                                                                 Only applies when PCIEEP()_CFG139[EINJ6_INV_CNTL] is not set. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_chg_val_h1      : 32; /**< [ 31:  0](R/W) Packet change value 2nd DWORD.
                                                                 Specifies replacement values for the Tx TLP header
                                                                 DWORD1 bits defined in the PCIEEP()_CFG132[EINJ6_CHG_PT_H1].
                                                                 Only applies when PCIEEP()_CFG139[EINJ6_INV_CNTL] is not set. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg137_s cn; */
} bdk_pcieepx_cfg137_t;

static inline uint64_t BDK_PCIEEPX_CFG137(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG137(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000228ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG137", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG137(a) bdk_pcieepx_cfg137_t
#define bustype_BDK_PCIEEPX_CFG137(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG137(a) "PCIEEPX_CFG137"
#define busnum_BDK_PCIEEPX_CFG137(a) (a)
#define arguments_BDK_PCIEEPX_CFG137(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg138
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Change Value H2) Register
 * This register contains the one hundred thirty-nineth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg138_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_chg_val_h2      : 32; /**< [ 31:  0](R/W) Packet change value 3rd DWORD.
                                                                 Specifies replacement values for the Tx TLP header
                                                                 DWORD2 bits defined in the PCIEEP()_CFG133[EINJ6_CHG_PT_H2].
                                                                 Only applies when PCIEEP()_CFG139[EINJ6_INV_CNTL] is not set." */
#else /* Word 0 - Little Endian */
        uint32_t einj6_chg_val_h2      : 32; /**< [ 31:  0](R/W) Packet change value 3rd DWORD.
                                                                 Specifies replacement values for the Tx TLP header
                                                                 DWORD2 bits defined in the PCIEEP()_CFG133[EINJ6_CHG_PT_H2].
                                                                 Only applies when PCIEEP()_CFG139[EINJ6_INV_CNTL] is not set." */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg138_s cn; */
} bdk_pcieepx_cfg138_t;

static inline uint64_t BDK_PCIEEPX_CFG138(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG138(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000022cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG138", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG138(a) bdk_pcieepx_cfg138_t
#define bustype_BDK_PCIEEPX_CFG138(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG138(a) "PCIEEPX_CFG138"
#define busnum_BDK_PCIEEPX_CFG138(a) (a)
#define arguments_BDK_PCIEEPX_CFG138(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg139
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Change Value H3) Register
 * This register contains the one hundred fourtyith 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg139_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t einj6_chg_val_h3      : 32; /**< [ 31:  0](R/W) Packet change value 4th DWORD.
                                                                 Specifies replacement values for the Tx TLP header
                                                                 DWORD3 bits defined in the PCIEEP()_CFG134[EINJ6_CHG_PT_H3].
                                                                 Only applies when PCIEEP()_CFG139[EINJ6_INV_CNTL] is not set. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_chg_val_h3      : 32; /**< [ 31:  0](R/W) Packet change value 4th DWORD.
                                                                 Specifies replacement values for the Tx TLP header
                                                                 DWORD3 bits defined in the PCIEEP()_CFG134[EINJ6_CHG_PT_H3].
                                                                 Only applies when PCIEEP()_CFG139[EINJ6_INV_CNTL] is not set. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg139_s cn; */
} bdk_pcieepx_cfg139_t;

static inline uint64_t BDK_PCIEEPX_CFG139(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG139(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000230ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG139", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG139(a) bdk_pcieepx_cfg139_t
#define bustype_BDK_PCIEEPX_CFG139(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG139(a) "PCIEEPX_CFG139"
#define busnum_BDK_PCIEEPX_CFG139(a) (a)
#define arguments_BDK_PCIEEPX_CFG139(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg140
 *
 * PCI Express Vendor RAS DES Error Injection Control 6 (Packet Error) Register
 * This register contains the one hundred fourty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg140_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_12_31        : 20;
        uint32_t einj6_pkt_typ         : 3;  /**< [ 11:  9](R/W) Packet type.  Selects the TLP packets to inject errors into.

                                                                 0x0 = TLP Header.
                                                                 0x1 = TLP Prefix 1st 4-DWORDs.
                                                                 0x2 = TLP Prefix 2nd 4-DWORDs.
                                                                 0x3 - 0x7 = Reserved. */
        uint32_t einj6_inv_cntrl       : 1;  /**< [  8:  8](R/W) Inverted error injection control.

                                                                 0x0 = EINJ6_CHG_VAL_H[0/1/2/3] is used to replace bits specified by
                                                                 EINJ6_CHG_PT_H[0/1/2/3].
                                                                 0x1 = EINJ6_CHG_VAL_H[0/1/2/3] is ignored and inverts bits specified by
                                                                 EINJ6_CHG_PT_H[0/1/2/3]. */
        uint32_t einj6_cnt             : 8;  /**< [  7:  0](R/W) Error injection count.  Indicates the number of errors.
                                                                 This register is decremented when errors are inserted.

                                                                 If the counter value is 0x1 and error is inserted,
                                                                 PCIEEP()_CFG117[EINJ6_EN] returns zero.

                                                                 If the counter value is 0x0 and PCIEEP()_CFG117[EINJ6_EN] is set,
                                                                 errors are inserted until PCIEEP()_CFG117[EINJ6_EN] is cleared. */
#else /* Word 0 - Little Endian */
        uint32_t einj6_cnt             : 8;  /**< [  7:  0](R/W) Error injection count.  Indicates the number of errors.
                                                                 This register is decremented when errors are inserted.

                                                                 If the counter value is 0x1 and error is inserted,
                                                                 PCIEEP()_CFG117[EINJ6_EN] returns zero.

                                                                 If the counter value is 0x0 and PCIEEP()_CFG117[EINJ6_EN] is set,
                                                                 errors are inserted until PCIEEP()_CFG117[EINJ6_EN] is cleared. */
        uint32_t einj6_inv_cntrl       : 1;  /**< [  8:  8](R/W) Inverted error injection control.

                                                                 0x0 = EINJ6_CHG_VAL_H[0/1/2/3] is used to replace bits specified by
                                                                 EINJ6_CHG_PT_H[0/1/2/3].
                                                                 0x1 = EINJ6_CHG_VAL_H[0/1/2/3] is ignored and inverts bits specified by
                                                                 EINJ6_CHG_PT_H[0/1/2/3]. */
        uint32_t einj6_pkt_typ         : 3;  /**< [ 11:  9](R/W) Packet type.  Selects the TLP packets to inject errors into.

                                                                 0x0 = TLP Header.
                                                                 0x1 = TLP Prefix 1st 4-DWORDs.
                                                                 0x2 = TLP Prefix 2nd 4-DWORDs.
                                                                 0x3 - 0x7 = Reserved. */
        uint32_t reserved_12_31        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg140_s cn; */
} bdk_pcieepx_cfg140_t;

static inline uint64_t BDK_PCIEEPX_CFG140(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG140(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000234ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG140", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG140(a) bdk_pcieepx_cfg140_t
#define bustype_BDK_PCIEEPX_CFG140(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG140(a) "PCIEEPX_CFG140"
#define busnum_BDK_PCIEEPX_CFG140(a) (a)
#define arguments_BDK_PCIEEPX_CFG140(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg141
 *
 * PCI Express Vendor RAS DES Silicon Debug Control 1 Register
 * This register contains the one hundred fourty-second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg141_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t lp_intv               : 2;  /**< [ 23: 22](R/W) Low power entry interval time.
                                                                 Interval time that the core starts monitoring RXELECIDLE
                                                                 signal after L0s/L1/L2 entry. You should set the value
                                                                 according to the latency from receiving EIOS to,
                                                                 RXELECIDLE assertion at the PHY

                                                                 0x0 = 40ns.
                                                                 0x1 = 160ns.
                                                                 0x2 = 320ns.
                                                                 0x3 - 640ns. */
        uint32_t tx_eios_num           : 2;  /**< [ 21: 20](R/W) Number of TX EIOS.
                                                                 This register sets the number of transmit EIOS for L0s/L1
                                                                 entry and Disable/Loopback/Hot-reset exit. The core selects
                                                                 the greater value between this register and the value defined
                                                                 by the PCI-SIG specification.

                                                                 Gen1 or Gen3
                                                                 0x0 = 1.
                                                                 0x1 = 4.
                                                                 0x2 = 8.
                                                                 0x3 - 16.

                                                                 Gen2
                                                                 0x0 = 2.
                                                                 0x1 = 8.
                                                                 0x2 = 16.
                                                                 0x3 - 32. */
        uint32_t reserved_17_19        : 3;
        uint32_t force_detect_lane_en  : 1;  /**< [ 16: 16](R/W) Force Detect Lane Enable.
                                                                 When this bit is set, the core ignores receiver detection from
                                                                 PHY during LTSSM Detect state and uses
                                                                 [FORCE_DETECT_LANE]. */
        uint32_t force_detect_lane     : 16; /**< [ 15:  0](R/W) Force Detect lane.
                                                                 When set, the core
                                                                 ignores receiver detection from PHY during LTSSM Detect
                                                                 state and uses this value instead.
                                                                 0x0 = Lane0.
                                                                 0x1 = Lane1.
                                                                 0x2 = Lane2.

                                                                 0x7 = Lane7. */
#else /* Word 0 - Little Endian */
        uint32_t force_detect_lane     : 16; /**< [ 15:  0](R/W) Force Detect lane.
                                                                 When set, the core
                                                                 ignores receiver detection from PHY during LTSSM Detect
                                                                 state and uses this value instead.
                                                                 0x0 = Lane0.
                                                                 0x1 = Lane1.
                                                                 0x2 = Lane2.

                                                                 0x7 = Lane7. */
        uint32_t force_detect_lane_en  : 1;  /**< [ 16: 16](R/W) Force Detect Lane Enable.
                                                                 When this bit is set, the core ignores receiver detection from
                                                                 PHY during LTSSM Detect state and uses
                                                                 [FORCE_DETECT_LANE]. */
        uint32_t reserved_17_19        : 3;
        uint32_t tx_eios_num           : 2;  /**< [ 21: 20](R/W) Number of TX EIOS.
                                                                 This register sets the number of transmit EIOS for L0s/L1
                                                                 entry and Disable/Loopback/Hot-reset exit. The core selects
                                                                 the greater value between this register and the value defined
                                                                 by the PCI-SIG specification.

                                                                 Gen1 or Gen3
                                                                 0x0 = 1.
                                                                 0x1 = 4.
                                                                 0x2 = 8.
                                                                 0x3 - 16.

                                                                 Gen2
                                                                 0x0 = 2.
                                                                 0x1 = 8.
                                                                 0x2 = 16.
                                                                 0x3 - 32. */
        uint32_t lp_intv               : 2;  /**< [ 23: 22](R/W) Low power entry interval time.
                                                                 Interval time that the core starts monitoring RXELECIDLE
                                                                 signal after L0s/L1/L2 entry. You should set the value
                                                                 according to the latency from receiving EIOS to,
                                                                 RXELECIDLE assertion at the PHY

                                                                 0x0 = 40ns.
                                                                 0x1 = 160ns.
                                                                 0x2 = 320ns.
                                                                 0x3 - 640ns. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg141_s cn; */
} bdk_pcieepx_cfg141_t;

static inline uint64_t BDK_PCIEEPX_CFG141(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG141(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000238ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG141", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG141(a) bdk_pcieepx_cfg141_t
#define bustype_BDK_PCIEEPX_CFG141(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG141(a) "PCIEEPX_CFG141"
#define busnum_BDK_PCIEEPX_CFG141(a) (a)
#define arguments_BDK_PCIEEPX_CFG141(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg142
 *
 * PCI Express Vendor RAS DES Silicon Debug Control 2 Register
 * This register contains the one hundred fourty-third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg142_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_17_31        : 15;
        uint32_t fr_err_rcvy_dis       : 1;  /**< [ 16: 16](R/W) Framing error recovery disable.
                                                                 This bit forces a transition to Recovery state when a Framing
                                                                 Error has occurred. */
        uint32_t reserved_11_15        : 5;
        uint32_t det_lpbslv_to_exit    : 1;  /**< [ 10: 10](R/W) Detect loopback slave to exit.
                                                                 When set and the LTSSM is in Loopback Slave Active State,
                                                                 the LTSSM transitions to the Loopback Slave Exit state. */
        uint32_t dir_polcmp_to_det     : 1;  /**< [  9:  9](R/W) Direct Polling.Compliance to detect.
                                                                 When this bit is set and the LTSSM is in Polling Compliance
                                                                 State, the LTSSM transitions to Detect state. */
        uint32_t dir_recidle_config    : 1;  /**< [  8:  8](R/W) Direct Recovery.Idle to configuration.
                                                                 When this bit is set and the LTSSM is in Recovery Idle State,
                                                                 the LTSSM transitions to Configuration state. */
        uint32_t reserved_3_7          : 5;
        uint32_t noack_force_lnkdn     : 1;  /**< [  2:  2](R/W) Force link down.
                                                                 When this bit is set and the core detects REPLY_NUM rolling
                                                                 over 4 times, the LTSSM transitions to Detect State. */
        uint32_t rcry_req              : 1;  /**< [  1:  1](R/W) Recovery request.
                                                                 When this bit is set in L0 or L0s, the LTSSM starts
                                                                 transitioning to Recovery State. This request does not cause
                                                                 a speed change or re-equalization. */
        uint32_t hold_ltssm            : 1;  /**< [  0:  0](R/W) Hold and Release LTSSM.
                                                                 For as long as this is set, the core stays in the current
                                                                 LTSSM. */
#else /* Word 0 - Little Endian */
        uint32_t hold_ltssm            : 1;  /**< [  0:  0](R/W) Hold and Release LTSSM.
                                                                 For as long as this is set, the core stays in the current
                                                                 LTSSM. */
        uint32_t rcry_req              : 1;  /**< [  1:  1](R/W) Recovery request.
                                                                 When this bit is set in L0 or L0s, the LTSSM starts
                                                                 transitioning to Recovery State. This request does not cause
                                                                 a speed change or re-equalization. */
        uint32_t noack_force_lnkdn     : 1;  /**< [  2:  2](R/W) Force link down.
                                                                 When this bit is set and the core detects REPLY_NUM rolling
                                                                 over 4 times, the LTSSM transitions to Detect State. */
        uint32_t reserved_3_7          : 5;
        uint32_t dir_recidle_config    : 1;  /**< [  8:  8](R/W) Direct Recovery.Idle to configuration.
                                                                 When this bit is set and the LTSSM is in Recovery Idle State,
                                                                 the LTSSM transitions to Configuration state. */
        uint32_t dir_polcmp_to_det     : 1;  /**< [  9:  9](R/W) Direct Polling.Compliance to detect.
                                                                 When this bit is set and the LTSSM is in Polling Compliance
                                                                 State, the LTSSM transitions to Detect state. */
        uint32_t det_lpbslv_to_exit    : 1;  /**< [ 10: 10](R/W) Detect loopback slave to exit.
                                                                 When set and the LTSSM is in Loopback Slave Active State,
                                                                 the LTSSM transitions to the Loopback Slave Exit state. */
        uint32_t reserved_11_15        : 5;
        uint32_t fr_err_rcvy_dis       : 1;  /**< [ 16: 16](R/W) Framing error recovery disable.
                                                                 This bit forces a transition to Recovery state when a Framing
                                                                 Error has occurred. */
        uint32_t reserved_17_31        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg142_s cn; */
} bdk_pcieepx_cfg142_t;

static inline uint64_t BDK_PCIEEPX_CFG142(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG142(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000023cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG142", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG142(a) bdk_pcieepx_cfg142_t
#define bustype_BDK_PCIEEPX_CFG142(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG142(a) "PCIEEPX_CFG142"
#define busnum_BDK_PCIEEPX_CFG142(a) (a)
#define arguments_BDK_PCIEEPX_CFG142(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg143
 *
 * PCI Express Vendor RAS DES Silicon Debug Status L1Lane Register
 * This register contains the one hundred fourty-fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg143_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t deskew_ptr            : 8;  /**< [ 31: 24](RO) Deskew pointer.
                                                                 Indicates deskew pointer of internal Deskew buffer of
                                                                 selected lane number (LANE_SELECT). */
        uint32_t reserved_21_23        : 3;
        uint32_t pipe_txelecidle       : 1;  /**< [ 20: 20](RO) PIPE:TxElecIdle.
                                                                 Indicates PIPE TXELECIDLE signal of selected lane
                                                                 number ([LANE_SELECT]). */
        uint32_t pipe_rxelecidle       : 1;  /**< [ 19: 19](RO) PIPE:RxElecIdle.
                                                                 Indicates PIPE RXELECIDLE signal of selected lane
                                                                 number ([LANE_SELECT]). */
        uint32_t pipe_rxvalid          : 1;  /**< [ 18: 18](RO) PIPE:RxValid.
                                                                 Indicates PIPE RXVALID signal of selected lane
                                                                 number ([LANE_SELECT]). */
        uint32_t pipe_det_lane         : 1;  /**< [ 17: 17](RO) PIPE:Detect Lane.
                                                                 Indicates whether PHY indicates receiver detection or not on
                                                                 selected lane number ([LANE_SELECT]). */
        uint32_t pipe_rxpol            : 1;  /**< [ 16: 16](RO) PIPE:RxPolarity.
                                                                 Indicates PIPE RXPOLARITY signal of selected lane
                                                                 number ([LANE_SELECT]). */
        uint32_t reserved_4_15         : 12;
        uint32_t lane_select           : 4;  /**< [  3:  0](RO) Lane Select.
                                                                 Lane Select register for Silicon Debug Status Register of
                                                                 Layer1-PerLane.
                                                                 0x0 = Lane0.
                                                                 0x1 = Lane1.
                                                                 0x2 = Lane2.

                                                                 0x7 = Lane7.
                                                                 0x8-0xf = Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t lane_select           : 4;  /**< [  3:  0](RO) Lane Select.
                                                                 Lane Select register for Silicon Debug Status Register of
                                                                 Layer1-PerLane.
                                                                 0x0 = Lane0.
                                                                 0x1 = Lane1.
                                                                 0x2 = Lane2.

                                                                 0x7 = Lane7.
                                                                 0x8-0xf = Reserved. */
        uint32_t reserved_4_15         : 12;
        uint32_t pipe_rxpol            : 1;  /**< [ 16: 16](RO) PIPE:RxPolarity.
                                                                 Indicates PIPE RXPOLARITY signal of selected lane
                                                                 number ([LANE_SELECT]). */
        uint32_t pipe_det_lane         : 1;  /**< [ 17: 17](RO) PIPE:Detect Lane.
                                                                 Indicates whether PHY indicates receiver detection or not on
                                                                 selected lane number ([LANE_SELECT]). */
        uint32_t pipe_rxvalid          : 1;  /**< [ 18: 18](RO) PIPE:RxValid.
                                                                 Indicates PIPE RXVALID signal of selected lane
                                                                 number ([LANE_SELECT]). */
        uint32_t pipe_rxelecidle       : 1;  /**< [ 19: 19](RO) PIPE:RxElecIdle.
                                                                 Indicates PIPE RXELECIDLE signal of selected lane
                                                                 number ([LANE_SELECT]). */
        uint32_t pipe_txelecidle       : 1;  /**< [ 20: 20](RO) PIPE:TxElecIdle.
                                                                 Indicates PIPE TXELECIDLE signal of selected lane
                                                                 number ([LANE_SELECT]). */
        uint32_t reserved_21_23        : 3;
        uint32_t deskew_ptr            : 8;  /**< [ 31: 24](RO) Deskew pointer.
                                                                 Indicates deskew pointer of internal Deskew buffer of
                                                                 selected lane number (LANE_SELECT). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg143_s cn; */
} bdk_pcieepx_cfg143_t;

static inline uint64_t BDK_PCIEEPX_CFG143(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG143(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000240ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG143", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG143(a) bdk_pcieepx_cfg143_t
#define bustype_BDK_PCIEEPX_CFG143(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG143(a) "PCIEEPX_CFG143"
#define busnum_BDK_PCIEEPX_CFG143(a) (a)
#define arguments_BDK_PCIEEPX_CFG143(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg144
 *
 * PCI Express Vendor RAS DES Silicon Debug Status L1LTSSM Register
 * This register contains the one hundred fourty-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg144_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ltssm_var             : 16; /**< [ 31: 16](RO) LTSSM Variable.
                                                                 Indicates internal LTSSM variables defined in the PCI
                                                                 Express base specification.
                                                                 0x0 = directed_speed change.
                                                                 0x1 = changed_speed_recovery.
                                                                 0x2 =  successful_speed_negotiation.
                                                                 0x3 =  upconfigure_capable; Set to '1' if both ports advertised
                                                                 the UpConfigure capability in the last Config.Complete.
                                                                 0x4 = select_deemphasis
                                                                 0x5 = start_equalization_w_preset.
                                                                 0x6 = equalization_done_8GT_data_rate.
                                                                 0x7 = equalization_done_16GT_data_rate.
                                                                 0x8-0xf = idle_to_rlock_transitioned. */
        uint32_t lane_rev              : 1;  /**< [ 15: 15](RO) Lane reversal operation.
                                                                 Receiver detected lane reversal. */
        uint32_t reserved_11_14        : 4;
        uint32_t pipe_pwr_dwn          : 3;  /**< [ 10:  8](RO) PIPE:PowerDown.
                                                                 Indicates PIPE PowerDown signal. */
        uint32_t framing_err           : 1;  /**< [  7:  7](R/W1C) Framing Error.
                                                                 Indicates Framing Error detection status. */
        uint32_t framing_err_ptr       : 7;  /**< [  6:  0](RO) First framing error pointer.
                                                                 Identifies the first Framing Error using the following
                                                                 encoding. The field contents are only valid value when
                                                                 FRAMING_ERR =1.

                                                                 Received Unexpected Framing Token
                                                                 0x1 = When non- STP/SDP/IDL Token was received and it
                                                                 was not in TLP/DLLP reception
                                                                 0x02 = When current token was not a valid EDB token and
                                                                 previous token was an EDB. (128/256 bit core only)
                                                                 0x03 = When SDP token was received but not expected.
                                                                 0x04 = When STP token was received but not expected.
                                                                 0x05 = When EDS token was expected but not received or
                                                                 whenever an EDS token was received but not expected.
                                                                 0x06 = When a framing error was detected in the deskew
                                                                 block while a packet has been in progress in token_finder.
                                                                 Received Unexpected STP Token
                                                                 0x11 = When Framing CRC in STP token did not match.
                                                                 0x12 = When Framing Parity in STP token did not match.
                                                                 0x13 = When Framing TLP Length in STP token was
                                                                 smaller than 5 DWORDs.

                                                                 Received Unexpected Block
                                                                 0x21 = When Receiving an OS Block following SDS in Datastream state.n
                                                                 0x22 = When Data Block followed by OS Block different
                                                                 from SKP, EI, EIE in Datastream state
                                                                 0x23 = When Block with an undefined Block Type in Datastream state.
                                                                 0x24 = When Data Stream without data over three cycles in Datastream state.
                                                                 0x25 = When OS Block during Data Stream in Datastream state.
                                                                 0x26 = When RxStatus Error was detected in Datastream state.
                                                                 0x27 = When Not all active lanes receiving SKP OS starting
                                                                 at same cycle time in SKPOS state.
                                                                 0x28 = When a 2-Block timeout occurs for SKP OS in SKPOS state.
                                                                 0x29 = When Receiving consecutive OS Blocks within a Data Stream in SKPOS state.n
                                                                 0x2A = When Phy status error was detected in SKPOS state.
                                                                 0x2B = When Not all active lanes receiving EIOS starting at
                                                                 same cycle time in EIOS state.
                                                                 0x2C = When At least one Symbol from the first 4 Symbols
                                                                 is not EIOS Symbol in EIOS state (CX_NB=2 only)
                                                                 0x2D = When Not all active lanes receiving EIEOS starting
                                                                 at same cycle time in EIEOS state.
                                                                 0x2E = When Not full 16 eieos symbols are received in EIEOS state.

                                                                 All other values not listed above are Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t framing_err_ptr       : 7;  /**< [  6:  0](RO) First framing error pointer.
                                                                 Identifies the first Framing Error using the following
                                                                 encoding. The field contents are only valid value when
                                                                 FRAMING_ERR =1.

                                                                 Received Unexpected Framing Token
                                                                 0x1 = When non- STP/SDP/IDL Token was received and it
                                                                 was not in TLP/DLLP reception
                                                                 0x02 = When current token was not a valid EDB token and
                                                                 previous token was an EDB. (128/256 bit core only)
                                                                 0x03 = When SDP token was received but not expected.
                                                                 0x04 = When STP token was received but not expected.
                                                                 0x05 = When EDS token was expected but not received or
                                                                 whenever an EDS token was received but not expected.
                                                                 0x06 = When a framing error was detected in the deskew
                                                                 block while a packet has been in progress in token_finder.
                                                                 Received Unexpected STP Token
                                                                 0x11 = When Framing CRC in STP token did not match.
                                                                 0x12 = When Framing Parity in STP token did not match.
                                                                 0x13 = When Framing TLP Length in STP token was
                                                                 smaller than 5 DWORDs.

                                                                 Received Unexpected Block
                                                                 0x21 = When Receiving an OS Block following SDS in Datastream state.n
                                                                 0x22 = When Data Block followed by OS Block different
                                                                 from SKP, EI, EIE in Datastream state
                                                                 0x23 = When Block with an undefined Block Type in Datastream state.
                                                                 0x24 = When Data Stream without data over three cycles in Datastream state.
                                                                 0x25 = When OS Block during Data Stream in Datastream state.
                                                                 0x26 = When RxStatus Error was detected in Datastream state.
                                                                 0x27 = When Not all active lanes receiving SKP OS starting
                                                                 at same cycle time in SKPOS state.
                                                                 0x28 = When a 2-Block timeout occurs for SKP OS in SKPOS state.
                                                                 0x29 = When Receiving consecutive OS Blocks within a Data Stream in SKPOS state.n
                                                                 0x2A = When Phy status error was detected in SKPOS state.
                                                                 0x2B = When Not all active lanes receiving EIOS starting at
                                                                 same cycle time in EIOS state.
                                                                 0x2C = When At least one Symbol from the first 4 Symbols
                                                                 is not EIOS Symbol in EIOS state (CX_NB=2 only)
                                                                 0x2D = When Not all active lanes receiving EIEOS starting
                                                                 at same cycle time in EIEOS state.
                                                                 0x2E = When Not full 16 eieos symbols are received in EIEOS state.

                                                                 All other values not listed above are Reserved. */
        uint32_t framing_err           : 1;  /**< [  7:  7](R/W1C) Framing Error.
                                                                 Indicates Framing Error detection status. */
        uint32_t pipe_pwr_dwn          : 3;  /**< [ 10:  8](RO) PIPE:PowerDown.
                                                                 Indicates PIPE PowerDown signal. */
        uint32_t reserved_11_14        : 4;
        uint32_t lane_rev              : 1;  /**< [ 15: 15](RO) Lane reversal operation.
                                                                 Receiver detected lane reversal. */
        uint32_t ltssm_var             : 16; /**< [ 31: 16](RO) LTSSM Variable.
                                                                 Indicates internal LTSSM variables defined in the PCI
                                                                 Express base specification.
                                                                 0x0 = directed_speed change.
                                                                 0x1 = changed_speed_recovery.
                                                                 0x2 =  successful_speed_negotiation.
                                                                 0x3 =  upconfigure_capable; Set to '1' if both ports advertised
                                                                 the UpConfigure capability in the last Config.Complete.
                                                                 0x4 = select_deemphasis
                                                                 0x5 = start_equalization_w_preset.
                                                                 0x6 = equalization_done_8GT_data_rate.
                                                                 0x7 = equalization_done_16GT_data_rate.
                                                                 0x8-0xf = idle_to_rlock_transitioned. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg144_s cn; */
} bdk_pcieepx_cfg144_t;

static inline uint64_t BDK_PCIEEPX_CFG144(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG144(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000244ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG144", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG144(a) bdk_pcieepx_cfg144_t
#define bustype_BDK_PCIEEPX_CFG144(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG144(a) "PCIEEPX_CFG144"
#define busnum_BDK_PCIEEPX_CFG144(a) (a)
#define arguments_BDK_PCIEEPX_CFG144(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg145
 *
 * PCI Express Vendor RAS DES Silicon Debug Status PM Register
 * This register contains the one hundred fourty-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg145_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t latched_nfts          : 8;  /**< [ 23: 16](RO) Latched N_FTS.
                                                                 Indicates the value of N_FTS in the received TS Ordered
                                                                 Sets from the link partner. */
        uint32_t reserved_13_15        : 3;
        uint32_t pme_rsnd_flag         : 1;  /**< [ 12: 12](RO) PME re-send flag.
                                                                 When the DUT sends a PM_PME message TLP, the DUT
                                                                 sets PME_Status bit. If host software does not clear
                                                                 PME_Status bit for 100ms (+50%/-5%), the DUT resends the
                                                                 PM_PME Message. This bit indicates that a PM_PME was
                                                                 resent. */
        uint32_t int_pm_sstate         : 4;  /**< [ 11:  8](RO) Internal PM state (slave).
                                                                 Indicates internal state machine of power management
                                                                 slave controller.
                                                                 0x00 = IDLE.
                                                                 0x01 = L0.
                                                                 0x02 = L0S.
                                                                 0x03 = ENTER_L0S.
                                                                 0x04 = L0S_EXIT.
                                                                 0x08 = L1.
                                                                 0x09 = L1_BLOCK_TLP.
                                                                 0x0A = L1_WAIT_LAST_TLP_ACK.
                                                                 0x0B = L1_WAIT_PMDLLP_ACK.
                                                                 0x0C = L1_LINK_ENTR_L1.
                                                                 0x0D = L1_EXIT.
                                                                 0x0F = PREP_4L1.
                                                                 0x10 = L23_BLOCK_TLP.
                                                                 0x11 = L23_WAIT_LAST_TLP_ACK.
                                                                 0x12 = L23_WAIT_PMDLLP_ACK.
                                                                 0x13 = L23_ENTR_L23.
                                                                 0x14 = L23RDY.
                                                                 0x15 = PREP_4L23.
                                                                 0x16 = L23RDY_WAIT4ALIVE.
                                                                 0x17 = L0S_BLOCK_TLP.
                                                                 0x18-0x1F = Reserved. */
        uint32_t reserved_5_7          : 3;
        uint32_t int_pm_mstate         : 5;  /**< [  4:  0](RO) Internal PM state (master).
                                                                 Indicates internal state machine of power management
                                                                 master controller.
                                                                 0x0 = S_IDLE.
                                                                 0x1 = S_RESPOND_NAK.
                                                                 0x2 = S_BLOCK_TLP.
                                                                 0x3 = S_WAIT_LAST_TLP_ACK.
                                                                 0x4 = S_WAIT_EIDLE.
                                                                 0x5 = S_LINK_ENTR_L1.
                                                                 0x6 = S_L1.
                                                                 0x7 = S_L1_EXIT.
                                                                 0x8 = S_L23RDY.
                                                                 0x9 = S_LINK_ENTR_L23.
                                                                 0xA = S_L23RDY_WAIT4ALIVE.
                                                                 0xB = S_ACK_WAIT4IDLE.
                                                                 0xC-0x1F = Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t int_pm_mstate         : 5;  /**< [  4:  0](RO) Internal PM state (master).
                                                                 Indicates internal state machine of power management
                                                                 master controller.
                                                                 0x0 = S_IDLE.
                                                                 0x1 = S_RESPOND_NAK.
                                                                 0x2 = S_BLOCK_TLP.
                                                                 0x3 = S_WAIT_LAST_TLP_ACK.
                                                                 0x4 = S_WAIT_EIDLE.
                                                                 0x5 = S_LINK_ENTR_L1.
                                                                 0x6 = S_L1.
                                                                 0x7 = S_L1_EXIT.
                                                                 0x8 = S_L23RDY.
                                                                 0x9 = S_LINK_ENTR_L23.
                                                                 0xA = S_L23RDY_WAIT4ALIVE.
                                                                 0xB = S_ACK_WAIT4IDLE.
                                                                 0xC-0x1F = Reserved. */
        uint32_t reserved_5_7          : 3;
        uint32_t int_pm_sstate         : 4;  /**< [ 11:  8](RO) Internal PM state (slave).
                                                                 Indicates internal state machine of power management
                                                                 slave controller.
                                                                 0x00 = IDLE.
                                                                 0x01 = L0.
                                                                 0x02 = L0S.
                                                                 0x03 = ENTER_L0S.
                                                                 0x04 = L0S_EXIT.
                                                                 0x08 = L1.
                                                                 0x09 = L1_BLOCK_TLP.
                                                                 0x0A = L1_WAIT_LAST_TLP_ACK.
                                                                 0x0B = L1_WAIT_PMDLLP_ACK.
                                                                 0x0C = L1_LINK_ENTR_L1.
                                                                 0x0D = L1_EXIT.
                                                                 0x0F = PREP_4L1.
                                                                 0x10 = L23_BLOCK_TLP.
                                                                 0x11 = L23_WAIT_LAST_TLP_ACK.
                                                                 0x12 = L23_WAIT_PMDLLP_ACK.
                                                                 0x13 = L23_ENTR_L23.
                                                                 0x14 = L23RDY.
                                                                 0x15 = PREP_4L23.
                                                                 0x16 = L23RDY_WAIT4ALIVE.
                                                                 0x17 = L0S_BLOCK_TLP.
                                                                 0x18-0x1F = Reserved. */
        uint32_t pme_rsnd_flag         : 1;  /**< [ 12: 12](RO) PME re-send flag.
                                                                 When the DUT sends a PM_PME message TLP, the DUT
                                                                 sets PME_Status bit. If host software does not clear
                                                                 PME_Status bit for 100ms (+50%/-5%), the DUT resends the
                                                                 PM_PME Message. This bit indicates that a PM_PME was
                                                                 resent. */
        uint32_t reserved_13_15        : 3;
        uint32_t latched_nfts          : 8;  /**< [ 23: 16](RO) Latched N_FTS.
                                                                 Indicates the value of N_FTS in the received TS Ordered
                                                                 Sets from the link partner. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg145_s cn; */
} bdk_pcieepx_cfg145_t;

static inline uint64_t BDK_PCIEEPX_CFG145(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG145(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000248ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG145", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG145(a) bdk_pcieepx_cfg145_t
#define bustype_BDK_PCIEEPX_CFG145(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG145(a) "PCIEEPX_CFG145"
#define busnum_BDK_PCIEEPX_CFG145(a) (a)
#define arguments_BDK_PCIEEPX_CFG145(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg146
 *
 * PCI Express Vendor RAS DES Silicon Debug Status L2 Register
 * This register contains the one hundred fourty-seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg146_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_28_31        : 4;
        uint32_t fc_init2              : 1;  /**< [ 27: 27](RO) FC_INIT2. Indicates the core is in FC_INIT2(VC0) state. */
        uint32_t fc_init1              : 1;  /**< [ 26: 26](RO) FC_INIT1. Indicates the core is in FC_INIT1(VC0) state. */
        uint32_t dlcmsm                : 2;  /**< [ 25: 24](RO) DLCMSM.
                                                                 Indicates the current DLCMSM.
                                                                 0x0 = DL_INACTIVE.
                                                                 0x1 = DL_FC_INIT.
                                                                 0x2 = Reserved.
                                                                 0x3 = DL_ACTIVE. */
        uint32_t rx_ack_seq_no         : 12; /**< [ 23: 12](RO) Rx Ack Sequence Number.
                                                                 Indicates ACKD_SEQ which is updated by receiving
                                                                 ACK/NAK DLLP. */
        uint32_t tx_ack_seq_no         : 12; /**< [ 11:  0](RO) Tx Ack Sequence Number.
                                                                 Indicates next transmit sequence number for transmit TLP. */
#else /* Word 0 - Little Endian */
        uint32_t tx_ack_seq_no         : 12; /**< [ 11:  0](RO) Tx Ack Sequence Number.
                                                                 Indicates next transmit sequence number for transmit TLP. */
        uint32_t rx_ack_seq_no         : 12; /**< [ 23: 12](RO) Rx Ack Sequence Number.
                                                                 Indicates ACKD_SEQ which is updated by receiving
                                                                 ACK/NAK DLLP. */
        uint32_t dlcmsm                : 2;  /**< [ 25: 24](RO) DLCMSM.
                                                                 Indicates the current DLCMSM.
                                                                 0x0 = DL_INACTIVE.
                                                                 0x1 = DL_FC_INIT.
                                                                 0x2 = Reserved.
                                                                 0x3 = DL_ACTIVE. */
        uint32_t fc_init1              : 1;  /**< [ 26: 26](RO) FC_INIT1. Indicates the core is in FC_INIT1(VC0) state. */
        uint32_t fc_init2              : 1;  /**< [ 27: 27](RO) FC_INIT2. Indicates the core is in FC_INIT2(VC0) state. */
        uint32_t reserved_28_31        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg146_s cn; */
} bdk_pcieepx_cfg146_t;

static inline uint64_t BDK_PCIEEPX_CFG146(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG146(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000024cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG146", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG146(a) bdk_pcieepx_cfg146_t
#define bustype_BDK_PCIEEPX_CFG146(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG146(a) "PCIEEPX_CFG146"
#define busnum_BDK_PCIEEPX_CFG146(a) (a)
#define arguments_BDK_PCIEEPX_CFG146(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg147
 *
 * PCI Express Vendor RAS DES Silicon Debug Status L2 Register
 * This register contains the one hundred fourty-eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg147_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t credit_data1          : 12; /**< [ 31: 20](RO) Credit data 1.
                                                                 Current FC credit data selected by the CREDIT_SEL_VC,
                                                                 CREDIT_SEL_CREDIT_TYPE, CREDIT_SEL_TLP_TYPE,
                                                                 and CREDIT_SEL_HD viewport-select fields.
                                                                 Rx = Credit allocated value.
                                                                 Tx = Credit limit value. This value is valid when DLCMSM=0x3(DL_ACTIVE). */
        uint32_t credit_data0          : 12; /**< [ 19:  8](RO) Credit data 0.
                                                                 Current FC credit data selected by the CREDIT_SEL_VC,
                                                                 CREDIT_SEL_CREDIT_TYPE, CREDIT_SEL_TLP_TYPE,
                                                                 and CREDIT_SEL_HD viewport-select fields.
                                                                 Rx = Credit received value.
                                                                 Tx = Credit consumed value. */
        uint32_t reserved_7            : 1;
        uint32_t credit_sel_hd         : 1;  /**< [  6:  6](R/W) Credit select (HeaderData).
                                                                 This field in conjunction with the CREDIT_SEL_VC,
                                                                 CREDIT_SEL_CREDIT_TYPE, and
                                                                 CREDIT_SEL_TLP_TYPE viewport-select fields determines
                                                                 that data that is returned by the CREDIT_DATA0 and
                                                                 CREDIT_DATA1 data fields.
                                                                 0x0 = Header credit.
                                                                 0x1 = Data credit. */
        uint32_t credit_sel_tlp_type   : 2;  /**< [  5:  4](R/W) Credit select (TLP Type).
                                                                 This field in conjunction with the CREDIT_SEL_VC,
                                                                 CREDIT_SEL_CREDIT_TYPE, and CREDIT_SEL_HD
                                                                 viewport-select fields determines that data that is returned
                                                                 by the CREDIT_DATA0 and CREDIT_DATA1 data fields.
                                                                 0x0 = Posted.
                                                                 0x1 = Non-Posted.
                                                                 0x2 = Completion.
                                                                 0x3 = Reserved. */
        uint32_t credit_sel_credit_type : 1; /**< [  3:  3](R/W) Credit select (credit type).
                                                                 This field in conjunction with the CREDIT_SEL_VC,
                                                                 CREDIT_SEL_TLP_TYPE, and CREDIT_SEL_HD viewportselect
                                                                 fields determines that data that is returned by the
                                                                 CREDIT_DATA0 and CREDIT_DATA1 data fields.
                                                                 0x0 = Rx.
                                                                 0x1 = Tx. */
        uint32_t credit_sel_vc         : 3;  /**< [  2:  0](R/W) Credit select (VC).
                                                                 This field in conjunction with the
                                                                 CREDIT_SEL_CREDIT_TYPE, CREDIT_SEL_TLP_TYPE,
                                                                 and CREDIT_SEL_HD viewport-select fields determines that
                                                                 data that is returned by the CREDIT_DATA0 and
                                                                 CREDIT_DATA1 data fields.
                                                                 0x0 = VC0.
                                                                 0x1 = VC1.
                                                                 0x2 = VC2.
                                                                 ..
                                                                 0x7 = VC7. */
#else /* Word 0 - Little Endian */
        uint32_t credit_sel_vc         : 3;  /**< [  2:  0](R/W) Credit select (VC).
                                                                 This field in conjunction with the
                                                                 CREDIT_SEL_CREDIT_TYPE, CREDIT_SEL_TLP_TYPE,
                                                                 and CREDIT_SEL_HD viewport-select fields determines that
                                                                 data that is returned by the CREDIT_DATA0 and
                                                                 CREDIT_DATA1 data fields.
                                                                 0x0 = VC0.
                                                                 0x1 = VC1.
                                                                 0x2 = VC2.
                                                                 ..
                                                                 0x7 = VC7. */
        uint32_t credit_sel_credit_type : 1; /**< [  3:  3](R/W) Credit select (credit type).
                                                                 This field in conjunction with the CREDIT_SEL_VC,
                                                                 CREDIT_SEL_TLP_TYPE, and CREDIT_SEL_HD viewportselect
                                                                 fields determines that data that is returned by the
                                                                 CREDIT_DATA0 and CREDIT_DATA1 data fields.
                                                                 0x0 = Rx.
                                                                 0x1 = Tx. */
        uint32_t credit_sel_tlp_type   : 2;  /**< [  5:  4](R/W) Credit select (TLP Type).
                                                                 This field in conjunction with the CREDIT_SEL_VC,
                                                                 CREDIT_SEL_CREDIT_TYPE, and CREDIT_SEL_HD
                                                                 viewport-select fields determines that data that is returned
                                                                 by the CREDIT_DATA0 and CREDIT_DATA1 data fields.
                                                                 0x0 = Posted.
                                                                 0x1 = Non-Posted.
                                                                 0x2 = Completion.
                                                                 0x3 = Reserved. */
        uint32_t credit_sel_hd         : 1;  /**< [  6:  6](R/W) Credit select (HeaderData).
                                                                 This field in conjunction with the CREDIT_SEL_VC,
                                                                 CREDIT_SEL_CREDIT_TYPE, and
                                                                 CREDIT_SEL_TLP_TYPE viewport-select fields determines
                                                                 that data that is returned by the CREDIT_DATA0 and
                                                                 CREDIT_DATA1 data fields.
                                                                 0x0 = Header credit.
                                                                 0x1 = Data credit. */
        uint32_t reserved_7            : 1;
        uint32_t credit_data0          : 12; /**< [ 19:  8](RO) Credit data 0.
                                                                 Current FC credit data selected by the CREDIT_SEL_VC,
                                                                 CREDIT_SEL_CREDIT_TYPE, CREDIT_SEL_TLP_TYPE,
                                                                 and CREDIT_SEL_HD viewport-select fields.
                                                                 Rx = Credit received value.
                                                                 Tx = Credit consumed value. */
        uint32_t credit_data1          : 12; /**< [ 31: 20](RO) Credit data 1.
                                                                 Current FC credit data selected by the CREDIT_SEL_VC,
                                                                 CREDIT_SEL_CREDIT_TYPE, CREDIT_SEL_TLP_TYPE,
                                                                 and CREDIT_SEL_HD viewport-select fields.
                                                                 Rx = Credit allocated value.
                                                                 Tx = Credit limit value. This value is valid when DLCMSM=0x3(DL_ACTIVE). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg147_s cn; */
} bdk_pcieepx_cfg147_t;

static inline uint64_t BDK_PCIEEPX_CFG147(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG147(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000250ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG147", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG147(a) bdk_pcieepx_cfg147_t
#define bustype_BDK_PCIEEPX_CFG147(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG147(a) "PCIEEPX_CFG147"
#define busnum_BDK_PCIEEPX_CFG147(a) (a)
#define arguments_BDK_PCIEEPX_CFG147(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg148
 *
 * PCI Express Vendor RAS DES Silicon Debug Status L3 Register
 * This register contains the one hundred fourty-nineth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg148_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t mftlp_status          : 1;  /**< [  7:  7](R/W1C) Malformed TLP status.
                                                                 Indicates malformed TLP has occurred. */
        uint32_t mftlp_ptr             : 7;  /**< [  6:  0](RO) First malformed TLP error pointer.
                                                                 Indicates the element of the received first malformed TLP.
                                                                 This pointer is validated by MFTLP_STATUS.
                                                                 0x01 = AtomicOp address alignment.
                                                                 0x02 = AtomicOp operand.
                                                                 0x03 = AtomicOp byte enable.
                                                                 0x04 = TLP length miss match.
                                                                 0x05 = Max payload size.
                                                                 0x06 = Message TLP without TC0.
                                                                 0x07 = Invalid TC.
                                                                 0x08 = Unexpected route bit in Message TLP.
                                                                 0x09 = Unexpected CRS status in Completion TLP.
                                                                 0x0A = Byte enable.
                                                                 0x0B = Memory Address 4KB boundary.
                                                                 0x0C = TLP prefix rules.
                                                                 0x0D = Translation request rules.
                                                                 0x0E = Invalid TLP type.
                                                                 0x0F = Completion rules.
                                                                 0x10-0x7E = Reserved.
                                                                 0x7F = Application. */
#else /* Word 0 - Little Endian */
        uint32_t mftlp_ptr             : 7;  /**< [  6:  0](RO) First malformed TLP error pointer.
                                                                 Indicates the element of the received first malformed TLP.
                                                                 This pointer is validated by MFTLP_STATUS.
                                                                 0x01 = AtomicOp address alignment.
                                                                 0x02 = AtomicOp operand.
                                                                 0x03 = AtomicOp byte enable.
                                                                 0x04 = TLP length miss match.
                                                                 0x05 = Max payload size.
                                                                 0x06 = Message TLP without TC0.
                                                                 0x07 = Invalid TC.
                                                                 0x08 = Unexpected route bit in Message TLP.
                                                                 0x09 = Unexpected CRS status in Completion TLP.
                                                                 0x0A = Byte enable.
                                                                 0x0B = Memory Address 4KB boundary.
                                                                 0x0C = TLP prefix rules.
                                                                 0x0D = Translation request rules.
                                                                 0x0E = Invalid TLP type.
                                                                 0x0F = Completion rules.
                                                                 0x10-0x7E = Reserved.
                                                                 0x7F = Application. */
        uint32_t mftlp_status          : 1;  /**< [  7:  7](R/W1C) Malformed TLP status.
                                                                 Indicates malformed TLP has occurred. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg148_s cn; */
} bdk_pcieepx_cfg148_t;

static inline uint64_t BDK_PCIEEPX_CFG148(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG148(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000254ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG148", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG148(a) bdk_pcieepx_cfg148_t
#define bustype_BDK_PCIEEPX_CFG148(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG148(a) "PCIEEPX_CFG148"
#define busnum_BDK_PCIEEPX_CFG148(a) (a)
#define arguments_BDK_PCIEEPX_CFG148(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg149
 *
 * PCI Express Vendor RAS DES Silicon Debug EQ Control 1 Register
 * This register contains the one hundred fiftyith 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg149_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t fom_target            : 8;  /**< [ 31: 24](R/W) FOM target.
                                                                 Indicates figure of merit target criteria value of EQ
                                                                 Master (DSP in EQ Phase3/USP in EQ Phase2).
                                                                 This field is only valid when [GEN3_EQ_FB_MODE] is
                                                                 0x1 (Figure Of Merit). */
        uint32_t fom_target_en         : 1;  /**< [ 23: 23](R/W) FOM target enable.
                                                                 Enables the FOM_TARGET fields. */
        uint32_t reserved_18_22        : 5;
        uint32_t eval_interval_time    : 2;  /**< [ 17: 16](R/W) Eval interval time.
                                                                 Indicates interval time of RxEqEval assertion.
                                                                 0x0 = 500ns.
                                                                 0x1 = 1us.
                                                                 0x2 = 2us.
                                                                 0x3 = 4us.

                                                                 This field is used for EQ Master (DSP in EQ Phase3/USP in
                                                                 EQ Phase2). */
        uint32_t reserved_5_15         : 11;
        uint32_t eq_rate_sel           : 1;  /**< [  4:  4](R/W) EQ status rate select.
                                                                 Setting this field in conjunction with the EQ_LANE_SEL field
                                                                 determines the per-lane Silicon Debug EQ Status data
                                                                 returned by the SD_EQ_CONTROL[2/3] and
                                                                 SD_EQ_STATUS[1/2/3] viewport registers.
                                                                 0x0 = 8.0GT/s Speed
                                                                 0x1 = 16.0GT/s Speed (Not supported). */
        uint32_t eq_lane_sel           : 4;  /**< [  3:  0](R/W) EQ status lane select.
                                                                 Setting this field in conjunction with the EQ_RATE_SEL field
                                                                 determines the per-lane Silicon Debug EQ Status data
                                                                 returned by the SD_EQ_CONTROL[2/3] and
                                                                 SD_EQ_STATUS[1/2/3] viewport registers.
                                                                 0x0 = Lane0.
                                                                 0x1 = Lane1.
                                                                 0x2 = Lane2.
                                                                 ..
                                                                 0x7 = Lane7.
                                                                 0x8-0xF =Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t eq_lane_sel           : 4;  /**< [  3:  0](R/W) EQ status lane select.
                                                                 Setting this field in conjunction with the EQ_RATE_SEL field
                                                                 determines the per-lane Silicon Debug EQ Status data
                                                                 returned by the SD_EQ_CONTROL[2/3] and
                                                                 SD_EQ_STATUS[1/2/3] viewport registers.
                                                                 0x0 = Lane0.
                                                                 0x1 = Lane1.
                                                                 0x2 = Lane2.
                                                                 ..
                                                                 0x7 = Lane7.
                                                                 0x8-0xF =Reserved. */
        uint32_t eq_rate_sel           : 1;  /**< [  4:  4](R/W) EQ status rate select.
                                                                 Setting this field in conjunction with the EQ_LANE_SEL field
                                                                 determines the per-lane Silicon Debug EQ Status data
                                                                 returned by the SD_EQ_CONTROL[2/3] and
                                                                 SD_EQ_STATUS[1/2/3] viewport registers.
                                                                 0x0 = 8.0GT/s Speed
                                                                 0x1 = 16.0GT/s Speed (Not supported). */
        uint32_t reserved_5_15         : 11;
        uint32_t eval_interval_time    : 2;  /**< [ 17: 16](R/W) Eval interval time.
                                                                 Indicates interval time of RxEqEval assertion.
                                                                 0x0 = 500ns.
                                                                 0x1 = 1us.
                                                                 0x2 = 2us.
                                                                 0x3 = 4us.

                                                                 This field is used for EQ Master (DSP in EQ Phase3/USP in
                                                                 EQ Phase2). */
        uint32_t reserved_18_22        : 5;
        uint32_t fom_target_en         : 1;  /**< [ 23: 23](R/W) FOM target enable.
                                                                 Enables the FOM_TARGET fields. */
        uint32_t fom_target            : 8;  /**< [ 31: 24](R/W) FOM target.
                                                                 Indicates figure of merit target criteria value of EQ
                                                                 Master (DSP in EQ Phase3/USP in EQ Phase2).
                                                                 This field is only valid when [GEN3_EQ_FB_MODE] is
                                                                 0x1 (Figure Of Merit). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg149_s cn; */
} bdk_pcieepx_cfg149_t;

static inline uint64_t BDK_PCIEEPX_CFG149(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG149(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000258ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG149", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG149(a) bdk_pcieepx_cfg149_t
#define bustype_BDK_PCIEEPX_CFG149(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG149(a) "PCIEEPX_CFG149"
#define busnum_BDK_PCIEEPX_CFG149(a) (a)
#define arguments_BDK_PCIEEPX_CFG149(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg150
 *
 * PCI Express Vendor RAS DES Silicon Debug EQ Control 2 Register
 * This register contains the one hundred fifty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg150_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t force_loc_txpre_en    : 1;  /**< [ 30: 30](R/W) Force local transmitter preset enable.
                                                                 Enables the FORCE_LOCAL_TX_PRESET field. */
        uint32_t force_loc_rxhint_en   : 1;  /**< [ 29: 29](R/W) Force local receiver preset hint enable.
                                                                 Enables the FORCE_LOCAL_RX_HINT field. */
        uint32_t force_loc_txcoef_en   : 1;  /**< [ 28: 28](R/W) Force local transmitter coefficient enable.
                                                                 Enables the following fields:
                                                                 FORCE_LOCAL_TX_PRE_CURSOR.
                                                                 FORCE_LOCAL_TX_CURSOR.
                                                                 FORCE_LOCAL_TX_POST_CURSOR. */
        uint32_t force_loc_txpre       : 4;  /**< [ 27: 24](R/W) Force local transmitter preset.
                                                                 Indicates initial preset value of USP in EQ slave (EQ Phase2)
                                                                 instead of receiving EQ TS2. */
        uint32_t reserved_21_23        : 3;
        uint32_t force_loc_rxhint      : 3;  /**< [ 20: 18](R/W) Force local receiver preset hint.
                                                                 Indicates the RxPresetHint value of EQ slave (DSP in EQ
                                                                 Phase2/USP in EQ Phase3), instead of received or set value. */
        uint32_t force_loc_txpost_cur  : 6;  /**< [ 17: 12](R/W) Force local transmitter post-cursor.
                                                                 Indicates the coefficient value of EQ slave (DSP in EQ
                                                                 Phase2/USP in EQ Phase3), instead of the value instructed
                                                                 from link partner. */
        uint32_t force_loc_tx_cur      : 6;  /**< [ 11:  6](R/W) Force local transmitter cursor.
                                                                 Indicates the coefficient value of EQ slave (DSP in EQ
                                                                 Phase2/USP in EQ Phase3), instead of the value instructed
                                                                 from link partner. */
        uint32_t force_loc_txpre_cur   : 6;  /**< [  5:  0](R/W) Force local transmitter pre-cursor.
                                                                 Indicates the coefficient value of EQ slave (DSP in EQ
                                                                 Phase2/USP in EQ Phase3), instead of the value instructed
                                                                 from link partner. */
#else /* Word 0 - Little Endian */
        uint32_t force_loc_txpre_cur   : 6;  /**< [  5:  0](R/W) Force local transmitter pre-cursor.
                                                                 Indicates the coefficient value of EQ slave (DSP in EQ
                                                                 Phase2/USP in EQ Phase3), instead of the value instructed
                                                                 from link partner. */
        uint32_t force_loc_tx_cur      : 6;  /**< [ 11:  6](R/W) Force local transmitter cursor.
                                                                 Indicates the coefficient value of EQ slave (DSP in EQ
                                                                 Phase2/USP in EQ Phase3), instead of the value instructed
                                                                 from link partner. */
        uint32_t force_loc_txpost_cur  : 6;  /**< [ 17: 12](R/W) Force local transmitter post-cursor.
                                                                 Indicates the coefficient value of EQ slave (DSP in EQ
                                                                 Phase2/USP in EQ Phase3), instead of the value instructed
                                                                 from link partner. */
        uint32_t force_loc_rxhint      : 3;  /**< [ 20: 18](R/W) Force local receiver preset hint.
                                                                 Indicates the RxPresetHint value of EQ slave (DSP in EQ
                                                                 Phase2/USP in EQ Phase3), instead of received or set value. */
        uint32_t reserved_21_23        : 3;
        uint32_t force_loc_txpre       : 4;  /**< [ 27: 24](R/W) Force local transmitter preset.
                                                                 Indicates initial preset value of USP in EQ slave (EQ Phase2)
                                                                 instead of receiving EQ TS2. */
        uint32_t force_loc_txcoef_en   : 1;  /**< [ 28: 28](R/W) Force local transmitter coefficient enable.
                                                                 Enables the following fields:
                                                                 FORCE_LOCAL_TX_PRE_CURSOR.
                                                                 FORCE_LOCAL_TX_CURSOR.
                                                                 FORCE_LOCAL_TX_POST_CURSOR. */
        uint32_t force_loc_rxhint_en   : 1;  /**< [ 29: 29](R/W) Force local receiver preset hint enable.
                                                                 Enables the FORCE_LOCAL_RX_HINT field. */
        uint32_t force_loc_txpre_en    : 1;  /**< [ 30: 30](R/W) Force local transmitter preset enable.
                                                                 Enables the FORCE_LOCAL_TX_PRESET field. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg150_s cn; */
} bdk_pcieepx_cfg150_t;

static inline uint64_t BDK_PCIEEPX_CFG150(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG150(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000025cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG150", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG150(a) bdk_pcieepx_cfg150_t
#define bustype_BDK_PCIEEPX_CFG150(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG150(a) "PCIEEPX_CFG150"
#define busnum_BDK_PCIEEPX_CFG150(a) (a)
#define arguments_BDK_PCIEEPX_CFG150(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg151
 *
 * PCI Express Vendor RAS DES Silicon Debug EQ Control 3 Register
 * This register contains the one hundred fifty-second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg151_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_29_31        : 3;
        uint32_t force_rem_txcoef_en   : 1;  /**< [ 28: 28](R/W) Force remote transmitter coefficient enable.
                                                                 Enables the following fields:
                                                                 FORCE_REMOTE_TX_PRE_CURSOR
                                                                 FORCE_REMOTE_TX_CURSOR
                                                                 FORCE_REMOTE_TX_POST_CURSOR */
        uint32_t reserved_18_27        : 10;
        uint32_t force_rem_txpost_cur  : 6;  /**< [ 17: 12](R/W) Force remote transmitter post-cursor.
                                                                 Indicates the coefficient value of EQ master (DSP in EQ
                                                                 Phase3/USP in EQ Phase2), instead of the value instructed
                                                                 from link partner. */
        uint32_t force_rem_tx_cur      : 6;  /**< [ 11:  6](R/W) Force remote transmitter cursor.
                                                                 Indicates the coefficient value of EQ master (DSP in EQ
                                                                 Phase3/USP in EQ Phase2), instead of the value instructed
                                                                 from link partner. */
        uint32_t force_rem_txpre_cur   : 6;  /**< [  5:  0](RAZ) Force Remote Transmitter Pre-Cursor.
                                                                 Indicates the coefficient value of EQ master (DSP in EQ
                                                                 Phase3/USP in EQ Phase2), instead of the value instructed
                                                                 from link partner. */
#else /* Word 0 - Little Endian */
        uint32_t force_rem_txpre_cur   : 6;  /**< [  5:  0](RAZ) Force Remote Transmitter Pre-Cursor.
                                                                 Indicates the coefficient value of EQ master (DSP in EQ
                                                                 Phase3/USP in EQ Phase2), instead of the value instructed
                                                                 from link partner. */
        uint32_t force_rem_tx_cur      : 6;  /**< [ 11:  6](R/W) Force remote transmitter cursor.
                                                                 Indicates the coefficient value of EQ master (DSP in EQ
                                                                 Phase3/USP in EQ Phase2), instead of the value instructed
                                                                 from link partner. */
        uint32_t force_rem_txpost_cur  : 6;  /**< [ 17: 12](R/W) Force remote transmitter post-cursor.
                                                                 Indicates the coefficient value of EQ master (DSP in EQ
                                                                 Phase3/USP in EQ Phase2), instead of the value instructed
                                                                 from link partner. */
        uint32_t reserved_18_27        : 10;
        uint32_t force_rem_txcoef_en   : 1;  /**< [ 28: 28](R/W) Force remote transmitter coefficient enable.
                                                                 Enables the following fields:
                                                                 FORCE_REMOTE_TX_PRE_CURSOR
                                                                 FORCE_REMOTE_TX_CURSOR
                                                                 FORCE_REMOTE_TX_POST_CURSOR */
        uint32_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg151_s cn; */
} bdk_pcieepx_cfg151_t;

static inline uint64_t BDK_PCIEEPX_CFG151(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG151(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000260ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG151", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG151(a) bdk_pcieepx_cfg151_t
#define bustype_BDK_PCIEEPX_CFG151(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG151(a) "PCIEEPX_CFG151"
#define busnum_BDK_PCIEEPX_CFG151(a) (a)
#define arguments_BDK_PCIEEPX_CFG151(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg152
 *
 * PCI Express Vendor RAS DES Silicon Debug EQ Status 1 Register
 * This register contains the one hundred fifty-third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg152_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t eq_reject_event       : 1;  /**< [  7:  7](RO) EQ reject event.
                                                                 Indicates that the core receives two consecutive TS1 OS
                                                                 w/Reject=1b during EQ Master phase (DSP in EQ
                                                                 Phase3/USP in EQ Phase2). This bit is automatically cleared
                                                                 when the core starts EQ Master phase again. */
        uint32_t eq_rulec_viol         : 1;  /**< [  6:  6](RO) EQ rule C violation.
                                                                 Indicates that coefficient rule C violation is detected in the
                                                                 values provided by PHY using direction change method
                                                                 during EQ Master phase (DSP in EQ Phase3/USP in EQ
                                                                 Phase2). */
        uint32_t eq_ruleb_viol         : 1;  /**< [  5:  5](RO) EQ rule B violation.
                                                                 Indicates that coefficient rule B violation is detected in the
                                                                 values provided by PHY using direction change method
                                                                 during EQ Master phase (DSP in EQ Phase3/USP in EQ
                                                                 Phase2). */
        uint32_t eq_rulea_viol         : 1;  /**< [  4:  4](RO) EQ rule A violation.
                                                                 Indicates that coefficient rule A violation is detected in the
                                                                 values provided by PHY using direction change method
                                                                 during EQ Master phase (DSP in EQ Phase3/USP in EQ
                                                                 Phase2). */
        uint32_t reserved_3            : 1;
        uint32_t eq_conv_info          : 2;  /**< [  2:  1](RO) EQ convergence info.
                                                                 Indicates equalization convergence information.
                                                                 0x0 = Equalization is not attempted.
                                                                 0x1 = Equalization finished successfully.
                                                                 0x2 = Equalization finished unsuccessfully.
                                                                 0x3 = Reserved.
                                                                 This bit is automatically cleared when the core starts EQ
                                                                 Master phase again. */
        uint32_t eq_sequence           : 1;  /**< [  0:  0](RO) EQ sequence.
                                                                 Indicates that the core is starting the equalization sequence. */
#else /* Word 0 - Little Endian */
        uint32_t eq_sequence           : 1;  /**< [  0:  0](RO) EQ sequence.
                                                                 Indicates that the core is starting the equalization sequence. */
        uint32_t eq_conv_info          : 2;  /**< [  2:  1](RO) EQ convergence info.
                                                                 Indicates equalization convergence information.
                                                                 0x0 = Equalization is not attempted.
                                                                 0x1 = Equalization finished successfully.
                                                                 0x2 = Equalization finished unsuccessfully.
                                                                 0x3 = Reserved.
                                                                 This bit is automatically cleared when the core starts EQ
                                                                 Master phase again. */
        uint32_t reserved_3            : 1;
        uint32_t eq_rulea_viol         : 1;  /**< [  4:  4](RO) EQ rule A violation.
                                                                 Indicates that coefficient rule A violation is detected in the
                                                                 values provided by PHY using direction change method
                                                                 during EQ Master phase (DSP in EQ Phase3/USP in EQ
                                                                 Phase2). */
        uint32_t eq_ruleb_viol         : 1;  /**< [  5:  5](RO) EQ rule B violation.
                                                                 Indicates that coefficient rule B violation is detected in the
                                                                 values provided by PHY using direction change method
                                                                 during EQ Master phase (DSP in EQ Phase3/USP in EQ
                                                                 Phase2). */
        uint32_t eq_rulec_viol         : 1;  /**< [  6:  6](RO) EQ rule C violation.
                                                                 Indicates that coefficient rule C violation is detected in the
                                                                 values provided by PHY using direction change method
                                                                 during EQ Master phase (DSP in EQ Phase3/USP in EQ
                                                                 Phase2). */
        uint32_t eq_reject_event       : 1;  /**< [  7:  7](RO) EQ reject event.
                                                                 Indicates that the core receives two consecutive TS1 OS
                                                                 w/Reject=1b during EQ Master phase (DSP in EQ
                                                                 Phase3/USP in EQ Phase2). This bit is automatically cleared
                                                                 when the core starts EQ Master phase again. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg152_s cn; */
} bdk_pcieepx_cfg152_t;

static inline uint64_t BDK_PCIEEPX_CFG152(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG152(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000264ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG152", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG152(a) bdk_pcieepx_cfg152_t
#define bustype_BDK_PCIEEPX_CFG152(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG152(a) "PCIEEPX_CFG152"
#define busnum_BDK_PCIEEPX_CFG152(a) (a)
#define arguments_BDK_PCIEEPX_CFG152(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg153
 *
 * PCI Express Vendor RAS DES Silicon Debug EQ Status 2 Register
 * This register contains the one hundred fifty-fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg153_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t eq_loc_fom_val        : 8;  /**< [ 31: 24](RO/H) EQ local figure of merit.
                                                                 Indicates local maximum figure of merit value. */
        uint32_t reserved_21_23        : 3;
        uint32_t eq_loc_rxhint         : 3;  /**< [ 20: 18](RO/H) EQ local receiver preset hint.
                                                                 Indicates local receiver preset hint value. */
        uint32_t eq_loc_post_cur       : 6;  /**< [ 17: 12](RO/H) EQ local post-cursor.
                                                                 Indicates local post cursor coefficient value. */
        uint32_t eq_loc_cur            : 6;  /**< [ 11:  6](RO) EQ local cursor.
                                                                 Indicates local cursor coefficient value. */
        uint32_t eq_loc_pre_cur        : 6;  /**< [  5:  0](RO) EQ local pre-cursor.
                                                                 Indicates local pre cursor coefficient value. */
#else /* Word 0 - Little Endian */
        uint32_t eq_loc_pre_cur        : 6;  /**< [  5:  0](RO) EQ local pre-cursor.
                                                                 Indicates local pre cursor coefficient value. */
        uint32_t eq_loc_cur            : 6;  /**< [ 11:  6](RO) EQ local cursor.
                                                                 Indicates local cursor coefficient value. */
        uint32_t eq_loc_post_cur       : 6;  /**< [ 17: 12](RO/H) EQ local post-cursor.
                                                                 Indicates local post cursor coefficient value. */
        uint32_t eq_loc_rxhint         : 3;  /**< [ 20: 18](RO/H) EQ local receiver preset hint.
                                                                 Indicates local receiver preset hint value. */
        uint32_t reserved_21_23        : 3;
        uint32_t eq_loc_fom_val        : 8;  /**< [ 31: 24](RO/H) EQ local figure of merit.
                                                                 Indicates local maximum figure of merit value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg153_s cn; */
} bdk_pcieepx_cfg153_t;

static inline uint64_t BDK_PCIEEPX_CFG153(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG153(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000268ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG153", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG153(a) bdk_pcieepx_cfg153_t
#define bustype_BDK_PCIEEPX_CFG153(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG153(a) "PCIEEPX_CFG153"
#define busnum_BDK_PCIEEPX_CFG153(a) (a)
#define arguments_BDK_PCIEEPX_CFG153(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg154
 *
 * PCI Express Vendor RAS DES Silicon Debug EQ Status 3 Register
 * This register contains the one hundred fifty-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg154_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_30_31        : 2;
        uint32_t eq_rem_fs             : 6;  /**< [ 29: 24](RO) EQ remote FS.
                                                                 Indicates remote FS value. */
        uint32_t eq_rem_lf             : 6;  /**< [ 23: 18](RO/H) EQ remote LF.
                                                                 Indicates remote LF value. */
        uint32_t eq_rem_post_cur       : 6;  /**< [ 17: 12](RO/H) EQ remote post-cursor.
                                                                 Indicates remote post cursor coefficient value. */
        uint32_t eq_rem_cur            : 6;  /**< [ 11:  6](RO) EQ remote cursor.
                                                                 Indicates remote cursor coefficient value. */
        uint32_t eq_rem_pre_cur        : 6;  /**< [  5:  0](RO) EQ remote pre-cursor.
                                                                 Indicates remote post cursor coefficient value. */
#else /* Word 0 - Little Endian */
        uint32_t eq_rem_pre_cur        : 6;  /**< [  5:  0](RO) EQ remote pre-cursor.
                                                                 Indicates remote post cursor coefficient value. */
        uint32_t eq_rem_cur            : 6;  /**< [ 11:  6](RO) EQ remote cursor.
                                                                 Indicates remote cursor coefficient value. */
        uint32_t eq_rem_post_cur       : 6;  /**< [ 17: 12](RO/H) EQ remote post-cursor.
                                                                 Indicates remote post cursor coefficient value. */
        uint32_t eq_rem_lf             : 6;  /**< [ 23: 18](RO/H) EQ remote LF.
                                                                 Indicates remote LF value. */
        uint32_t eq_rem_fs             : 6;  /**< [ 29: 24](RO) EQ remote FS.
                                                                 Indicates remote FS value. */
        uint32_t reserved_30_31        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg154_s cn; */
} bdk_pcieepx_cfg154_t;

static inline uint64_t BDK_PCIEEPX_CFG154(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG154(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000026cll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG154", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG154(a) bdk_pcieepx_cfg154_t
#define bustype_BDK_PCIEEPX_CFG154(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG154(a) "PCIEEPX_CFG154"
#define busnum_BDK_PCIEEPX_CFG154(a) (a)
#define arguments_BDK_PCIEEPX_CFG154(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg174
 *
 * PCI Express Vendor RAS Data Path Protection Header Register
 * This register contains the one hundred seventy-fifth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg174_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset.  Points to the Resizable BAR capabilities by default. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCI Express extended capability. */
#else /* Word 0 - Little Endian */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCI Express extended capability. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset.  Points to the Resizable BAR capabilities by default. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg174_s cn; */
} bdk_pcieepx_cfg174_t;

static inline uint64_t BDK_PCIEEPX_CFG174(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG174(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002b8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG174", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG174(a) bdk_pcieepx_cfg174_t
#define bustype_BDK_PCIEEPX_CFG174(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG174(a) "PCIEEPX_CFG174"
#define busnum_BDK_PCIEEPX_CFG174(a) (a)
#define arguments_BDK_PCIEEPX_CFG174(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg175
 *
 * PCI Express RAS Data Path Extended Capability Register
 * This register contains the one hundred seventy-sixth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg175_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vsec_length           : 12; /**< [ 31: 20](RO) VSEC Length. */
        uint32_t vsec_rev              : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t vsec_id               : 16; /**< [ 15:  0](RO) VSEC ID. */
#else /* Word 0 - Little Endian */
        uint32_t vsec_id               : 16; /**< [ 15:  0](RO) VSEC ID. */
        uint32_t vsec_rev              : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t vsec_length           : 12; /**< [ 31: 20](RO) VSEC Length. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg175_s cn; */
} bdk_pcieepx_cfg175_t;

static inline uint64_t BDK_PCIEEPX_CFG175(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG175(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002bcll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG175", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG175(a) bdk_pcieepx_cfg175_t
#define bustype_BDK_PCIEEPX_CFG175(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG175(a) "PCIEEPX_CFG175"
#define busnum_BDK_PCIEEPX_CFG175(a) (a)
#define arguments_BDK_PCIEEPX_CFG175(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg176
 *
 * PCI Express RAS Data Path Error Protection Control Register
 * This register contains the one hundred seventy-seventh 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg176_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_23_31        : 9;
        uint32_t ep_dis_adm_rx         : 1;  /**< [ 22: 22](R/W) Error correction disable for ADM Rx path. */
        uint32_t ep_dis_l3_rx          : 1;  /**< [ 21: 21](R/W) Error correction disable for Layer 3 Rx path. */
        uint32_t ep_dis_l2_rx          : 1;  /**< [ 20: 20](R/W) Error correction disable for Layer 2 Rx path. */
        uint32_t ep_dis_dma_rd         : 1;  /**< [ 19: 19](R/W) Error correction disable for DMA Read (Not supported). */
        uint32_t ep_dis_axib_inbr      : 1;  /**< [ 18: 18](R/W) Error correction disable for AXI Bridge inbound request path (Not supported). */
        uint32_t ep_dis_axib_inbc      : 1;  /**< [ 17: 17](R/W) Error correction disable for AXI Bridge inbound completion composer (Not supported). */
        uint32_t ep_dis_rx             : 1;  /**< [ 16: 16](R/W) Global error correction disable for all RX Layers. */
        uint32_t reserved_7_15         : 9;
        uint32_t ep_dis_adm_tx         : 1;  /**< [  6:  6](R/W) Error correction disable for ADM TX path. */
        uint32_t ep_dis_l3_tx          : 1;  /**< [  5:  5](R/W) Error correction disable for Layer 3 TX path. */
        uint32_t ep_dis_l2_tx          : 1;  /**< [  4:  4](R/W) Error correction disable for Layer 2 TX path. */
        uint32_t ep_dis_dma_wr         : 1;  /**< [  3:  3](R/W) Error correction disable for DMA Write (Not supported). */
        uint32_t ep_dis_axib_outb      : 1;  /**< [  2:  2](R/W) Error correction disable for AXI Bridge outbound request path (Not supported). */
        uint32_t ep_dis_axib_masc      : 1;  /**< [  1:  1](R/W) Error correction disable for AXI Bridge master completion buffer (Not supported). */
        uint32_t ep_dis_tx             : 1;  /**< [  0:  0](R/W) Global error correction disable for all TX Layers. */
#else /* Word 0 - Little Endian */
        uint32_t ep_dis_tx             : 1;  /**< [  0:  0](R/W) Global error correction disable for all TX Layers. */
        uint32_t ep_dis_axib_masc      : 1;  /**< [  1:  1](R/W) Error correction disable for AXI Bridge master completion buffer (Not supported). */
        uint32_t ep_dis_axib_outb      : 1;  /**< [  2:  2](R/W) Error correction disable for AXI Bridge outbound request path (Not supported). */
        uint32_t ep_dis_dma_wr         : 1;  /**< [  3:  3](R/W) Error correction disable for DMA Write (Not supported). */
        uint32_t ep_dis_l2_tx          : 1;  /**< [  4:  4](R/W) Error correction disable for Layer 2 TX path. */
        uint32_t ep_dis_l3_tx          : 1;  /**< [  5:  5](R/W) Error correction disable for Layer 3 TX path. */
        uint32_t ep_dis_adm_tx         : 1;  /**< [  6:  6](R/W) Error correction disable for ADM TX path. */
        uint32_t reserved_7_15         : 9;
        uint32_t ep_dis_rx             : 1;  /**< [ 16: 16](R/W) Global error correction disable for all RX Layers. */
        uint32_t ep_dis_axib_inbc      : 1;  /**< [ 17: 17](R/W) Error correction disable for AXI Bridge inbound completion composer (Not supported). */
        uint32_t ep_dis_axib_inbr      : 1;  /**< [ 18: 18](R/W) Error correction disable for AXI Bridge inbound request path (Not supported). */
        uint32_t ep_dis_dma_rd         : 1;  /**< [ 19: 19](R/W) Error correction disable for DMA Read (Not supported). */
        uint32_t ep_dis_l2_rx          : 1;  /**< [ 20: 20](R/W) Error correction disable for Layer 2 Rx path. */
        uint32_t ep_dis_l3_rx          : 1;  /**< [ 21: 21](R/W) Error correction disable for Layer 3 Rx path. */
        uint32_t ep_dis_adm_rx         : 1;  /**< [ 22: 22](R/W) Error correction disable for ADM Rx path. */
        uint32_t reserved_23_31        : 9;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg176_s cn; */
} bdk_pcieepx_cfg176_t;

static inline uint64_t BDK_PCIEEPX_CFG176(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG176(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002c0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG176", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG176(a) bdk_pcieepx_cfg176_t
#define bustype_BDK_PCIEEPX_CFG176(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG176(a) "PCIEEPX_CFG176"
#define busnum_BDK_PCIEEPX_CFG176(a) (a)
#define arguments_BDK_PCIEEPX_CFG176(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg177
 *
 * PCI Express RAS Data Path Correctable Error Control Register
 * This register contains the one hundred seventy-eighth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg177_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t corr_cnt_sel          : 8;  /**< [ 31: 24](RO) Counter Selection.  This field selects the counter ID (within
                                                                 the region defined by CORR_CNT_SEL_REG) whose contents
                                                                 can be read from the CFG114 register.  You can
                                                                 cycle this field value from 0 to 255 to access all counters. */
        uint32_t corr_cnt_sel_reg      : 4;  /**< [ 23: 20](R/W) Selected correctable counter region.
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t reserved_5_19         : 15;
        uint32_t corr_en_cntrs         : 1;  /**< [  4:  4](R/W) Error correction disable for ADM Rx path. */
        uint32_t reserved_1_3          : 3;
        uint32_t ep_dis_l3_rx          : 1;  /**< [  0:  0](R/W1C) Clears all correctable error counters. */
#else /* Word 0 - Little Endian */
        uint32_t ep_dis_l3_rx          : 1;  /**< [  0:  0](R/W1C) Clears all correctable error counters. */
        uint32_t reserved_1_3          : 3;
        uint32_t corr_en_cntrs         : 1;  /**< [  4:  4](R/W) Error correction disable for ADM Rx path. */
        uint32_t reserved_5_19         : 15;
        uint32_t corr_cnt_sel_reg      : 4;  /**< [ 23: 20](R/W) Selected correctable counter region.
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t corr_cnt_sel          : 8;  /**< [ 31: 24](RO) Counter Selection.  This field selects the counter ID (within
                                                                 the region defined by CORR_CNT_SEL_REG) whose contents
                                                                 can be read from the CFG114 register.  You can
                                                                 cycle this field value from 0 to 255 to access all counters. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg177_s cn; */
} bdk_pcieepx_cfg177_t;

static inline uint64_t BDK_PCIEEPX_CFG177(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG177(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002c4ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG177", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG177(a) bdk_pcieepx_cfg177_t
#define bustype_BDK_PCIEEPX_CFG177(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG177(a) "PCIEEPX_CFG177"
#define busnum_BDK_PCIEEPX_CFG177(a) (a)
#define arguments_BDK_PCIEEPX_CFG177(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg178
 *
 * PCI Express RAS Data Path Correctable Error Report Register
 * This register contains the one hundred seventy-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg178_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t corr_cnt_sel          : 8;  /**< [ 31: 24](RO) Counter Selection.  Returns the value set in the CFG113CORR_CNT_SEL] register. */
        uint32_t corr_cnt_sel_reg      : 4;  /**< [ 23: 20](RO) Selected correctable counter region.
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t reserved_8_19         : 12;
        uint32_t corr_count            : 8;  /**< [  7:  0](R/W) Current corrected count for the selected counter. */
#else /* Word 0 - Little Endian */
        uint32_t corr_count            : 8;  /**< [  7:  0](R/W) Current corrected count for the selected counter. */
        uint32_t reserved_8_19         : 12;
        uint32_t corr_cnt_sel_reg      : 4;  /**< [ 23: 20](RO) Selected correctable counter region.
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t corr_cnt_sel          : 8;  /**< [ 31: 24](RO) Counter Selection.  Returns the value set in the CFG113CORR_CNT_SEL] register. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg178_s cn; */
} bdk_pcieepx_cfg178_t;

static inline uint64_t BDK_PCIEEPX_CFG178(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG178(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002c8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG178", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG178(a) bdk_pcieepx_cfg178_t
#define bustype_BDK_PCIEEPX_CFG178(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG178(a) "PCIEEPX_CFG178"
#define busnum_BDK_PCIEEPX_CFG178(a) (a)
#define arguments_BDK_PCIEEPX_CFG178(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg179
 *
 * PCI Express RAS Data Path Uncorrectable Error Control Register
 * This register contains the one hundred eighty 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg179_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ucorr_cnt_sel         : 8;  /**< [ 31: 24](RO) Counter Selection.  This field selects the counter ID (within
                                                                 the region defined by UCORR_CNT_SEL_REG) whose contents
                                                                 can be read from the CFG114 register.  You can
                                                                 cycle this field value from 0 to 255 to access all counters. */
        uint32_t ucorr_cnt_sel_reg     : 4;  /**< [ 23: 20](R/W) Selected correctable counter region.
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t reserved_5_19         : 15;
        uint32_t ucorr_en_cntrs        : 1;  /**< [  4:  4](R/W) Error correction disable for ADM Rx path. */
        uint32_t reserved_1_3          : 3;
        uint32_t ep_dis_l3_rx          : 1;  /**< [  0:  0](R/W1C) Clears all uncorrectable error counters. */
#else /* Word 0 - Little Endian */
        uint32_t ep_dis_l3_rx          : 1;  /**< [  0:  0](R/W1C) Clears all uncorrectable error counters. */
        uint32_t reserved_1_3          : 3;
        uint32_t ucorr_en_cntrs        : 1;  /**< [  4:  4](R/W) Error correction disable for ADM Rx path. */
        uint32_t reserved_5_19         : 15;
        uint32_t ucorr_cnt_sel_reg     : 4;  /**< [ 23: 20](R/W) Selected correctable counter region.
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t ucorr_cnt_sel         : 8;  /**< [ 31: 24](RO) Counter Selection.  This field selects the counter ID (within
                                                                 the region defined by UCORR_CNT_SEL_REG) whose contents
                                                                 can be read from the CFG114 register.  You can
                                                                 cycle this field value from 0 to 255 to access all counters. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg179_s cn; */
} bdk_pcieepx_cfg179_t;

static inline uint64_t BDK_PCIEEPX_CFG179(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG179(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002ccll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG179", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG179(a) bdk_pcieepx_cfg179_t
#define bustype_BDK_PCIEEPX_CFG179(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG179(a) "PCIEEPX_CFG179"
#define busnum_BDK_PCIEEPX_CFG179(a) (a)
#define arguments_BDK_PCIEEPX_CFG179(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg180
 *
 * PCI Express RAS Data Path Uncorrectable Error Report Register
 * This register contains the one hundred eighty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg180_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ucorr_cnt_sel         : 8;  /**< [ 31: 24](RO) Counter Selection.  Returns the value set in the CFG113CORR_CNT_SEL] register. */
        uint32_t ucorr_cnt_sel_reg     : 4;  /**< [ 23: 20](RO) Selected correctable counter region.
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t reserved_8_19         : 12;
        uint32_t ucorr_count           : 8;  /**< [  7:  0](R/W) Current uncorrected count for the selected counter. */
#else /* Word 0 - Little Endian */
        uint32_t ucorr_count           : 8;  /**< [  7:  0](R/W) Current uncorrected count for the selected counter. */
        uint32_t reserved_8_19         : 12;
        uint32_t ucorr_cnt_sel_reg     : 4;  /**< [ 23: 20](RO) Selected correctable counter region.
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t ucorr_cnt_sel         : 8;  /**< [ 31: 24](RO) Counter Selection.  Returns the value set in the CFG113CORR_CNT_SEL] register. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg180_s cn; */
} bdk_pcieepx_cfg180_t;

static inline uint64_t BDK_PCIEEPX_CFG180(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG180(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002d0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG180", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG180(a) bdk_pcieepx_cfg180_t
#define bustype_BDK_PCIEEPX_CFG180(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG180(a) "PCIEEPX_CFG180"
#define busnum_BDK_PCIEEPX_CFG180(a) (a)
#define arguments_BDK_PCIEEPX_CFG180(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg181
 *
 * PCI Express RAS Data Correctable Error Injection Control Register
 * This register contains the one hundred eighty-second 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg181_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t err_inj_loc           : 8;  /**< [ 23: 16](R/W) Error injection location.  Selects where error injection takes place.  You
                                                                 can cycle this field value from 0 to 255 to access all locations. */
        uint32_t err_inj_cnt           : 8;  /**< [ 15:  8](R/W) Error injection count.
                                                                 0x0 = errors are injected in every TLP until ERR_INJ_EN is cleared.
                                                                 0x1 - 0xff = number of errors injected. */
        uint32_t reserved_6_7          : 2;
        uint32_t err_inj_type          : 2;  /**< [  5:  4](R/W) Error injection type.
                                                                 0x0 = none.
                                                                 0x1 = 1-bit.
                                                                 0x2 = 2-bit.
                                                                 0x3 = reserved. */
        uint32_t reserved_1_3          : 3;
        uint32_t err_inj_en            : 1;  /**< [  0:  0](R/W) Error injection global enable.  When set, enables the error
                                                                 insertion logic. */
#else /* Word 0 - Little Endian */
        uint32_t err_inj_en            : 1;  /**< [  0:  0](R/W) Error injection global enable.  When set, enables the error
                                                                 insertion logic. */
        uint32_t reserved_1_3          : 3;
        uint32_t err_inj_type          : 2;  /**< [  5:  4](R/W) Error injection type.
                                                                 0x0 = none.
                                                                 0x1 = 1-bit.
                                                                 0x2 = 2-bit.
                                                                 0x3 = reserved. */
        uint32_t reserved_6_7          : 2;
        uint32_t err_inj_cnt           : 8;  /**< [ 15:  8](R/W) Error injection count.
                                                                 0x0 = errors are injected in every TLP until ERR_INJ_EN is cleared.
                                                                 0x1 - 0xff = number of errors injected. */
        uint32_t err_inj_loc           : 8;  /**< [ 23: 16](R/W) Error injection location.  Selects where error injection takes place.  You
                                                                 can cycle this field value from 0 to 255 to access all locations. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg181_s cn; */
} bdk_pcieepx_cfg181_t;

static inline uint64_t BDK_PCIEEPX_CFG181(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG181(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002d4ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG181", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG181(a) bdk_pcieepx_cfg181_t
#define bustype_BDK_PCIEEPX_CFG181(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG181(a) "PCIEEPX_CFG181"
#define busnum_BDK_PCIEEPX_CFG181(a) (a)
#define arguments_BDK_PCIEEPX_CFG181(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg182
 *
 * PCI Express RAS Data Correctable Error Location Register
 * This register contains the one hundred eighty-third 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg182_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t loc_last_corr_err     : 8;  /**< [ 31: 24](RO) Location/ID of the last corrected error within the region defined by
                                                                 REG_LAST_CORR_ERR. */
        uint32_t reg_last_corr_err     : 4;  /**< [ 23: 20](RO) Region of last corrected error
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t reserved_16_19        : 4;
        uint32_t loc_first_corr_err    : 8;  /**< [ 15:  8](RO) Location/ID of the first corrected error within the region defined by
                                                                 REG_FIRST_CORR_ERR. */
        uint32_t reg_first_corr_err    : 4;  /**< [  7:  4](RO) Region of first corrected error
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t reg_first_corr_err    : 4;  /**< [  7:  4](RO) Region of first corrected error
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t loc_first_corr_err    : 8;  /**< [ 15:  8](RO) Location/ID of the first corrected error within the region defined by
                                                                 REG_FIRST_CORR_ERR. */
        uint32_t reserved_16_19        : 4;
        uint32_t reg_last_corr_err     : 4;  /**< [ 23: 20](RO) Region of last corrected error
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t loc_last_corr_err     : 8;  /**< [ 31: 24](RO) Location/ID of the last corrected error within the region defined by
                                                                 REG_LAST_CORR_ERR. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg182_s cn; */
} bdk_pcieepx_cfg182_t;

static inline uint64_t BDK_PCIEEPX_CFG182(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG182(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002d8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG182", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG182(a) bdk_pcieepx_cfg182_t
#define bustype_BDK_PCIEEPX_CFG182(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG182(a) "PCIEEPX_CFG182"
#define busnum_BDK_PCIEEPX_CFG182(a) (a)
#define arguments_BDK_PCIEEPX_CFG182(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg183
 *
 * PCI Express RAS Data Uncorrectable Error Location Register
 * This register contains the one hundred eighty-fourth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg183_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t loc_last_ucorr_err    : 8;  /**< [ 31: 24](RO) Location/ID of the last uncorrected error within the region defined by
                                                                 REG_LAST_CORR_ERR. */
        uint32_t reg_last_ucorr_err    : 4;  /**< [ 23: 20](RO) Region of last uncorrected error
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t reserved_16_19        : 4;
        uint32_t loc_first_ucorr_err   : 8;  /**< [ 15:  8](RO) Location/ID of the first uncorrected error within the region defined by
                                                                 REG_FIRST_CORR_ERR. */
        uint32_t reg_first_ucorr_err   : 4;  /**< [  7:  4](RO) Region of first uncorrected error
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t reg_first_ucorr_err   : 4;  /**< [  7:  4](RO) Region of first uncorrected error
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t loc_first_ucorr_err   : 8;  /**< [ 15:  8](RO) Location/ID of the first uncorrected error within the region defined by
                                                                 REG_FIRST_CORR_ERR. */
        uint32_t reserved_16_19        : 4;
        uint32_t reg_last_ucorr_err    : 4;  /**< [ 23: 20](RO) Region of last uncorrected error
                                                                 0x0 = ADM RX path.
                                                                 0x1 = Layer 3 RX path.
                                                                 0x2 = Layer 2 RX path.
                                                                 0x3 = DMA read engine (not supported).
                                                                 0x4 = AXI bridge inbound request path (not supported).
                                                                 0x5 = AXI bridge inbound completion composer (not supported).
                                                                 0x6 = ADM TX path.
                                                                 0x7 = Layer 3 TX path.
                                                                 0x8 = Layer 2 TX path.
                                                                 0x9 = DMA write engine (not supported).
                                                                 0xa = AXI bridge outbound request path (not supported).
                                                                 0xb = AXI bridge outbound master completion (not supported).
                                                                 0xc - 0xf = Reserved. */
        uint32_t loc_last_ucorr_err    : 8;  /**< [ 31: 24](RO) Location/ID of the last uncorrected error within the region defined by
                                                                 REG_LAST_CORR_ERR. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg183_s cn; */
} bdk_pcieepx_cfg183_t;

static inline uint64_t BDK_PCIEEPX_CFG183(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG183(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002dcll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG183", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG183(a) bdk_pcieepx_cfg183_t
#define bustype_BDK_PCIEEPX_CFG183(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG183(a) "PCIEEPX_CFG183"
#define busnum_BDK_PCIEEPX_CFG183(a) (a)
#define arguments_BDK_PCIEEPX_CFG183(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg184
 *
 * PCI Express RAS Data Error Mode Enable Register
 * This register contains the one hundred eighty-fifth  32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg184_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_2_31         : 30;
        uint32_t auto_lnk_dn_en        : 1;  /**< [  1:  1](R/W) Set this bit to enablea the core to bring the link down when RASDP error mode is entered.
                                                                 REG_LAST_CORR_ERR. */
        uint32_t err_mode_en           : 1;  /**< [  0:  0](R/W) Set this bit to enable the core to enter RASDP error mode when it detects an uncorrectable error. */
#else /* Word 0 - Little Endian */
        uint32_t err_mode_en           : 1;  /**< [  0:  0](R/W) Set this bit to enable the core to enter RASDP error mode when it detects an uncorrectable error. */
        uint32_t auto_lnk_dn_en        : 1;  /**< [  1:  1](R/W) Set this bit to enablea the core to bring the link down when RASDP error mode is entered.
                                                                 REG_LAST_CORR_ERR. */
        uint32_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg184_s cn; */
} bdk_pcieepx_cfg184_t;

static inline uint64_t BDK_PCIEEPX_CFG184(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG184(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002e0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG184", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG184(a) bdk_pcieepx_cfg184_t
#define bustype_BDK_PCIEEPX_CFG184(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG184(a) "PCIEEPX_CFG184"
#define busnum_BDK_PCIEEPX_CFG184(a) (a)
#define arguments_BDK_PCIEEPX_CFG184(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg185
 *
 * PCI Express RAS Data Error Mode Clear Register
 * This register contains the one hundred eighty-sixth  32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg185_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t err_mode_clr          : 1;  /**< [  0:  0](R/W) Set this bit to take the core out of RASDP error mode.  The core will then report
                                                                 uncorrectable
                                                                 errors (through AER internal error reporting) and also stop nullifying/discarding TLPs. */
#else /* Word 0 - Little Endian */
        uint32_t err_mode_clr          : 1;  /**< [  0:  0](R/W) Set this bit to take the core out of RASDP error mode.  The core will then report
                                                                 uncorrectable
                                                                 errors (through AER internal error reporting) and also stop nullifying/discarding TLPs. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg185_s cn; */
} bdk_pcieepx_cfg185_t;

static inline uint64_t BDK_PCIEEPX_CFG185(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG185(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002e4ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG185", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG185(a) bdk_pcieepx_cfg185_t
#define bustype_BDK_PCIEEPX_CFG185(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG185(a) "PCIEEPX_CFG185"
#define busnum_BDK_PCIEEPX_CFG185(a) (a)
#define arguments_BDK_PCIEEPX_CFG185(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg186
 *
 * PCI Express RAS RAM Address Corrected Error Register
 * This register contains the one hundred eigth-seventh  32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg186_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ram_idx_corr_err      : 4;  /**< [ 31: 28](RO) RAM index where a corrected error has been detected. */
        uint32_t reserved_27           : 1;
        uint32_t ram_addr_corr_err     : 27; /**< [ 26:  0](R/W) RAM address where a corrected error has been detected. */
#else /* Word 0 - Little Endian */
        uint32_t ram_addr_corr_err     : 27; /**< [ 26:  0](R/W) RAM address where a corrected error has been detected. */
        uint32_t reserved_27           : 1;
        uint32_t ram_idx_corr_err      : 4;  /**< [ 31: 28](RO) RAM index where a corrected error has been detected. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg186_s cn; */
} bdk_pcieepx_cfg186_t;

static inline uint64_t BDK_PCIEEPX_CFG186(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG186(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002e8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG186", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG186(a) bdk_pcieepx_cfg186_t
#define bustype_BDK_PCIEEPX_CFG186(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG186(a) "PCIEEPX_CFG186"
#define busnum_BDK_PCIEEPX_CFG186(a) (a)
#define arguments_BDK_PCIEEPX_CFG186(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg187
 *
 * PCI Express RAS RAM Address Uncorrected Error Register
 * This register contains the one hundred eighty-eighth  32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg187_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ram_idx_ucorr_err     : 4;  /**< [ 31: 28](RO) RAM index where a uncorrected error has been detected. */
        uint32_t reserved_27           : 1;
        uint32_t ram_addr_ucorr_err    : 27; /**< [ 26:  0](R/W) RAM address where a uncorrected error has been detected. */
#else /* Word 0 - Little Endian */
        uint32_t ram_addr_ucorr_err    : 27; /**< [ 26:  0](R/W) RAM address where a uncorrected error has been detected. */
        uint32_t reserved_27           : 1;
        uint32_t ram_idx_ucorr_err     : 4;  /**< [ 31: 28](RO) RAM index where a uncorrected error has been detected. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg187_s cn; */
} bdk_pcieepx_cfg187_t;

static inline uint64_t BDK_PCIEEPX_CFG187(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG187(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002ecll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG187", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG187(a) bdk_pcieepx_cfg187_t
#define bustype_BDK_PCIEEPX_CFG187(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG187(a) "PCIEEPX_CFG187"
#define busnum_BDK_PCIEEPX_CFG187(a) (a)
#define arguments_BDK_PCIEEPX_CFG187(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg188
 *
 * PCI Express Resizable BAR (RBAR) Capability Header Register
 * This register contains the one hundred eighty-ninth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg188_s
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
    /* struct bdk_pcieepx_cfg188_s cn; */
} bdk_pcieepx_cfg188_t;

static inline uint64_t BDK_PCIEEPX_CFG188(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG188(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002f0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG188", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG188(a) bdk_pcieepx_cfg188_t
#define bustype_BDK_PCIEEPX_CFG188(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG188(a) "PCIEEPX_CFG188"
#define busnum_BDK_PCIEEPX_CFG188(a) (a)
#define arguments_BDK_PCIEEPX_CFG188(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg189
 *
 * PCI Express Resizable BAR (RBAR) Capability Register
 * This register contains the one hundred ninety 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg189_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t srs                   : 28; /**< [ 31:  4](RO/WRSL) Supported resource sizes. PEM advertises the maximum allowable BAR size (512 GB -
                                                                 0xF_FFFF) when the fus__bar2_size_conf is intact. When the fuse is blown, the CNXXXX
                                                                 advertises a BAR size of 512TB (0xFFF_FFFF and PCIEEP)_CFG190[ESRS] = 0x3).
                                                                 The BAR is disabled at runtime by writing all zeros through PEM()_CFG_WR to this field. */
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t srs                   : 28; /**< [ 31:  4](RO/WRSL) Supported resource sizes. PEM advertises the maximum allowable BAR size (512 GB -
                                                                 0xF_FFFF) when the fus__bar2_size_conf is intact. When the fuse is blown, the CNXXXX
                                                                 advertises a BAR size of 512TB (0xFFF_FFFF and PCIEEP)_CFG190[ESRS] = 0x3).
                                                                 The BAR is disabled at runtime by writing all zeros through PEM()_CFG_WR to this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg189_s cn; */
} bdk_pcieepx_cfg189_t;

static inline uint64_t BDK_PCIEEPX_CFG189(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG189(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002f4ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG189", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG189(a) bdk_pcieepx_cfg189_t
#define bustype_BDK_PCIEEPX_CFG189(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG189(a) "PCIEEPX_CFG189"
#define busnum_BDK_PCIEEPX_CFG189(a) (a)
#define arguments_BDK_PCIEEPX_CFG189(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg190
 *
 * PCI Express Resizable BAR (RBAR) Control Register
 * This register contains the one hundred ninety-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg190_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t esrs                  : 16; /**< [ 31: 16](RO/WRSL) Extended Supported resource sizes. PEM advertises the maximum allowable BAR size (512 GB)
                                                                 when the fus__bar2_size_conf is intact. When the fuse is blown, the CNXXXX
                                                                 advertises a BAR size of 512TB (PCIEEP)_CFG190[SRS] = 0xFFF_FFFF and ESRS = 0x3).
                                                                 The BAR is disabled at runtime by writing all zeros through PEM()_CFG_WR to this field. */
        uint32_t reserved_14_15        : 2;
        uint32_t rbars                 : 6;  /**< [ 13:  8](R/W) BAR Size. PEM advertises the minimum allowable BAR size of 0x0 (1MB) but will accept
                                                                 values as large as 0x1D (512TB). */
        uint32_t nrbar                 : 3;  /**< [  7:  5](RO) Number of resizable BARs */
        uint32_t reserved_3_4          : 2;
        uint32_t rbari                 : 3;  /**< [  2:  0](RO) BAR Index. Points to BAR2. */
#else /* Word 0 - Little Endian */
        uint32_t rbari                 : 3;  /**< [  2:  0](RO) BAR Index. Points to BAR2. */
        uint32_t reserved_3_4          : 2;
        uint32_t nrbar                 : 3;  /**< [  7:  5](RO) Number of resizable BARs */
        uint32_t rbars                 : 6;  /**< [ 13:  8](R/W) BAR Size. PEM advertises the minimum allowable BAR size of 0x0 (1MB) but will accept
                                                                 values as large as 0x1D (512TB). */
        uint32_t reserved_14_15        : 2;
        uint32_t esrs                  : 16; /**< [ 31: 16](RO/WRSL) Extended Supported resource sizes. PEM advertises the maximum allowable BAR size (512 GB)
                                                                 when the fus__bar2_size_conf is intact. When the fuse is blown, the CNXXXX
                                                                 advertises a BAR size of 512TB (PCIEEP)_CFG190[SRS] = 0xFFF_FFFF and ESRS = 0x3).
                                                                 The BAR is disabled at runtime by writing all zeros through PEM()_CFG_WR to this field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg190_s cn; */
} bdk_pcieepx_cfg190_t;

static inline uint64_t BDK_PCIEEPX_CFG190(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG190(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000002f8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG190", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG190(a) bdk_pcieepx_cfg190_t
#define bustype_BDK_PCIEEPX_CFG190(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG190(a) "PCIEEPX_CFG190"
#define busnum_BDK_PCIEEPX_CFG190(a) (a)
#define arguments_BDK_PCIEEPX_CFG190(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg448
 *
 * PCIe EP PF Ack Latency Timer/Replay Timer Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000700ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Other Message Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000704ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Port Force Link Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000708ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Ack Frequency Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000070cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Port Link Control Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000710ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Lane Skew Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000714ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Symbol Number Register
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
        uint32_t tmrt                  : 5;  /**< [ 18: 14](R/W/H) Timer modifier for replay timer. Increases the timer value for the replay timer, in
                                                                 increments of 64 clock cycles. */
        uint32_t reserved_8_13         : 6;
        uint32_t mfuncn                : 8;  /**< [  7:  0](R/W) Max number of functions supported. Used for SR-IOV. */
#else /* Word 0 - Little Endian */
        uint32_t mfuncn                : 8;  /**< [  7:  0](R/W) Max number of functions supported. Used for SR-IOV. */
        uint32_t reserved_8_13         : 6;
        uint32_t tmrt                  : 5;  /**< [ 18: 14](R/W/H) Timer modifier for replay timer. Increases the timer value for the replay timer, in
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000718ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Symbol Timer/Filter Mask Register 1
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000071cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Filter Mask Register 2
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000720ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Debug Register 0
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000728ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Debug Register 1
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000072cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Transmit Posted FC Credit Status Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000730ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Transmit Nonposted FC Credit Status Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000734ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Transmit Completion FC Credit Status Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000738ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Queue Status Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000073cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF VC Transmit Arbitration Register 1
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000740ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF VC Transmit Arbitration Register 2
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000744ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF VC0 Posted Receive Queue Control Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000748ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF VC0 Nonposted Receive Queue Control Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000074cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF VC0 Completion Receive Queue Control Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000750ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Gen2 Port Logic Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x3000000080cll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF PHY Status Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000810ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF PHY Control Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000814ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Gen3 Control Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x30000000890ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Gen3 EQ Control Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000008a8ll + 0x100000000ll * ((a) & 0x3);
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
 * PCIe EP PF Gen3 PIPE Loopback Register
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000008b8ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG558", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG558(a) bdk_pcieepx_cfg558_t
#define bustype_BDK_PCIEEPX_CFG558(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG558(a) "PCIEEPX_CFG558"
#define busnum_BDK_PCIEEPX_CFG558(a) (a)
#define arguments_BDK_PCIEEPX_CFG558(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg559
 *
 * PCIe EP DBI Read-Only Write Enable Register
 * This register contains the five hundred sixtieth 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg559_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t dbi_ro_wr_en          : 1;  /**< [  0:  0](R/W) Write to RO Registers using DBI.  When you set this bit, then some
                                                                 RO bits are writeable from the DBI. */
#else /* Word 0 - Little Endian */
        uint32_t dbi_ro_wr_en          : 1;  /**< [  0:  0](R/W) Write to RO Registers using DBI.  When you set this bit, then some
                                                                 RO bits are writeable from the DBI. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg559_s cn; */
} bdk_pcieepx_cfg559_t;

static inline uint64_t BDK_PCIEEPX_CFG559(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG559(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000008bcll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG559", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG559(a) bdk_pcieepx_cfg559_t
#define bustype_BDK_PCIEEPX_CFG559(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG559(a) "PCIEEPX_CFG559"
#define busnum_BDK_PCIEEPX_CFG559(a) (a)
#define arguments_BDK_PCIEEPX_CFG559(a) (a),-1,-1,-1

/**
 * Register (PCICONFIGEP) pcieep#_cfg560
 *
 * PCIe EP UpConfigure Multi-lane Control Register
 * This register contains the five hundred sixty-first 32-bits of PCIe type 0 configuration space.
 */
typedef union
{
    uint32_t u;
    struct bdk_pcieepx_cfg560_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t upc_supp              : 1;  /**< [  7:  7](R/W) Upconfigure support.
                                                                 The core sends this value to the Link Upconfigure Capability in TS2 Ordered
                                                                 Sets in Configuration.Complete state. */
        uint32_t dir_lnk_wdth_chg      : 1;  /**< [  6:  6](R/W) Directed Link Width Change.
                                                                 The core always moves to Configuration state through Recovery state
                                                                 when this bit is set.

                                                                 If PCIEEP()_CFG144[LTSSM_VAR] is set and PCIEEP(0)_CFG040[HASD]
                                                                 is '0', the core starts upconfigure or autonomous width
                                                                 downsizing (to the TRGT_LNK_WDTH value) in the Configuration
                                                                 state.

                                                                 If TRGT_LNK_WDTH value is 0x0, the core does not
                                                                 start upconfigure or autonomous width downsizing in the
                                                                 Configuration state.

                                                                 The core self-clears this field when the core accepts this
                                                                 request. */
        uint32_t trgt_lnk_wdth         : 6;  /**< [  5:  0](R/W/H) Target Link Width.
                                                                 0x0  = Core does not start upconfigure or autonomous width downsizing in Configuration
                                                                 state.
                                                                 0x1  = x1.
                                                                 0x2  = x2.
                                                                 0x4  = x4.
                                                                 0x8  = x8.
                                                                 0x10 = x16 (Not supported).
                                                                 0x20 = x32 (Not supported). */
#else /* Word 0 - Little Endian */
        uint32_t trgt_lnk_wdth         : 6;  /**< [  5:  0](R/W/H) Target Link Width.
                                                                 0x0  = Core does not start upconfigure or autonomous width downsizing in Configuration
                                                                 state.
                                                                 0x1  = x1.
                                                                 0x2  = x2.
                                                                 0x4  = x4.
                                                                 0x8  = x8.
                                                                 0x10 = x16 (Not supported).
                                                                 0x20 = x32 (Not supported). */
        uint32_t dir_lnk_wdth_chg      : 1;  /**< [  6:  6](R/W) Directed Link Width Change.
                                                                 The core always moves to Configuration state through Recovery state
                                                                 when this bit is set.

                                                                 If PCIEEP()_CFG144[LTSSM_VAR] is set and PCIEEP(0)_CFG040[HASD]
                                                                 is '0', the core starts upconfigure or autonomous width
                                                                 downsizing (to the TRGT_LNK_WDTH value) in the Configuration
                                                                 state.

                                                                 If TRGT_LNK_WDTH value is 0x0, the core does not
                                                                 start upconfigure or autonomous width downsizing in the
                                                                 Configuration state.

                                                                 The core self-clears this field when the core accepts this
                                                                 request. */
        uint32_t upc_supp              : 1;  /**< [  7:  7](R/W) Upconfigure support.
                                                                 The core sends this value to the Link Upconfigure Capability in TS2 Ordered
                                                                 Sets in Configuration.Complete state. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcieepx_cfg560_s cn; */
} bdk_pcieepx_cfg560_t;

static inline uint64_t BDK_PCIEEPX_CFG560(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCIEEPX_CFG560(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x300000008c0ll + 0x100000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PCIEEPX_CFG560", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCIEEPX_CFG560(a) bdk_pcieepx_cfg560_t
#define bustype_BDK_PCIEEPX_CFG560(a) BDK_CSR_TYPE_PCICONFIGEP
#define basename_BDK_PCIEEPX_CFG560(a) "PCIEEPX_CFG560"
#define busnum_BDK_PCIEEPX_CFG560(a) (a)
#define arguments_BDK_PCIEEPX_CFG560(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_PCIEEP_H__ */
