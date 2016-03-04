#ifndef __BDK_CSRS_ECAM_H__
#define __BDK_CSRS_ECAM_H__
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
 * Cavium ECAM.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration ecam_bar_e
 *
 * ECAM Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_ECAM_BAR_E_ECAMX_PF_BAR0(a) (0x87e048000000ll + 0x1000000ll * (a)) /**< Base address for standard registers. */
#define BDK_ECAM_BAR_E_ECAMX_PF_BAR2(a) (0x848000000000ll + 0x1000000000ll * (a)) /**< Base address for ECAM access space, using ECAM_CFG_ADDR_S structure. */

/**
 * Structure ecam_cfg_addr_s
 *
 * ECAM Configuration Address Structure
 * ECAM load and store operations form an address with this structure: 8-bit, 16-bit, 32-bit and
 * 64-bit read and write operations are supported to this region.
 */
union bdk_ecam_cfg_addr_s
{
    uint64_t u;
    struct bdk_ecam_cfg_addr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t io                    : 1;  /**< [ 47: 47] Indicates I/O space. */
        uint64_t reserved_46           : 1;
        uint64_t node                  : 2;  /**< [ 45: 44] CCPI node number. */
        uint64_t did                   : 8;  /**< [ 43: 36] ECAM(0..3) DID. 0x48 + ECAM number. */
        uint64_t setup                 : 1;  /**< [ 35: 35] Reserved, MBZ.
                                                                 Internal:
                                                                 Reserved for future use - Setup. Allow certain PCC
                                                                 configuration registers to be written for boot-time initialization. Treated as 0
                                                                 unless in secure mode. */
        uint64_t bcst                  : 1;  /**< [ 34: 34] Reserved, MBZ.
                                                                 Internal:
                                                                 Reserved for future use - Broadcast. Write to all PCC
                                                                 blocks for fast configuration. Treated as 0 unless in secure mode and SETUP is
                                                                 set. */
        uint64_t reserved_28_33        : 6;
        uint64_t bus                   : 8;  /**< [ 27: 20] Bus number. */
        uint64_t func                  : 8;  /**< [ 19: 12] Function number. Note this assumes an ARI device; for external PCI devices that do not
                                                                 support ARI this contains both the device and function number. */
        uint64_t addr                  : 12; /**< [ 11:  0] Register address within the device. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 12; /**< [ 11:  0] Register address within the device. */
        uint64_t func                  : 8;  /**< [ 19: 12] Function number. Note this assumes an ARI device; for external PCI devices that do not
                                                                 support ARI this contains both the device and function number. */
        uint64_t bus                   : 8;  /**< [ 27: 20] Bus number. */
        uint64_t reserved_28_33        : 6;
        uint64_t bcst                  : 1;  /**< [ 34: 34] Reserved, MBZ.
                                                                 Internal:
                                                                 Reserved for future use - Broadcast. Write to all PCC
                                                                 blocks for fast configuration. Treated as 0 unless in secure mode and SETUP is
                                                                 set. */
        uint64_t setup                 : 1;  /**< [ 35: 35] Reserved, MBZ.
                                                                 Internal:
                                                                 Reserved for future use - Setup. Allow certain PCC
                                                                 configuration registers to be written for boot-time initialization. Treated as 0
                                                                 unless in secure mode. */
        uint64_t did                   : 8;  /**< [ 43: 36] ECAM(0..3) DID. 0x48 + ECAM number. */
        uint64_t node                  : 2;  /**< [ 45: 44] CCPI node number. */
        uint64_t reserved_46           : 1;
        uint64_t io                    : 1;  /**< [ 47: 47] Indicates I/O space. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    struct bdk_ecam_cfg_addr_s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t io                    : 1;  /**< [ 47: 47] Indicates I/O space. */
        uint64_t reserved_46           : 1;
        uint64_t node                  : 2;  /**< [ 45: 44] CCPI node number. */
        uint64_t did                   : 8;  /**< [ 43: 36] ECAM(0) DID. 0x48 + ECAM number. */
        uint64_t setup                 : 1;  /**< [ 35: 35] Reserved, MBZ.
                                                                 Internal:
                                                                 Reserved for future use - Setup. Allow certain PCC
                                                                 configuration registers to be written for boot-time initialization. Treated as 0
                                                                 unless in secure mode. */
        uint64_t bcst                  : 1;  /**< [ 34: 34] Reserved, MBZ.
                                                                 Internal:
                                                                 Reserved for future use - Broadcast. Write to all PCC
                                                                 blocks for fast configuration. Treated as 0 unless in secure mode and SETUP is
                                                                 set. */
        uint64_t reserved_28_33        : 6;
        uint64_t bus                   : 8;  /**< [ 27: 20] Bus number. */
        uint64_t func                  : 8;  /**< [ 19: 12] Function number. Note this assumes an ARI device; for external PCI devices that do not
                                                                 support ARI this contains both the device and function number. */
        uint64_t addr                  : 12; /**< [ 11:  0] Register address within the device. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 12; /**< [ 11:  0] Register address within the device. */
        uint64_t func                  : 8;  /**< [ 19: 12] Function number. Note this assumes an ARI device; for external PCI devices that do not
                                                                 support ARI this contains both the device and function number. */
        uint64_t bus                   : 8;  /**< [ 27: 20] Bus number. */
        uint64_t reserved_28_33        : 6;
        uint64_t bcst                  : 1;  /**< [ 34: 34] Reserved, MBZ.
                                                                 Internal:
                                                                 Reserved for future use - Broadcast. Write to all PCC
                                                                 blocks for fast configuration. Treated as 0 unless in secure mode and SETUP is
                                                                 set. */
        uint64_t setup                 : 1;  /**< [ 35: 35] Reserved, MBZ.
                                                                 Internal:
                                                                 Reserved for future use - Setup. Allow certain PCC
                                                                 configuration registers to be written for boot-time initialization. Treated as 0
                                                                 unless in secure mode. */
        uint64_t did                   : 8;  /**< [ 43: 36] ECAM(0) DID. 0x48 + ECAM number. */
        uint64_t node                  : 2;  /**< [ 45: 44] CCPI node number. */
        uint64_t reserved_46           : 1;
        uint64_t io                    : 1;  /**< [ 47: 47] Indicates I/O space. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_ecam_cfg_addr_s_s cn88xx; */
    struct bdk_ecam_cfg_addr_s_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t io                    : 1;  /**< [ 47: 47] Indicates I/O space. */
        uint64_t reserved_46           : 1;
        uint64_t node                  : 2;  /**< [ 45: 44] CCPI node number. */
        uint64_t did                   : 8;  /**< [ 43: 36] ECAM(0..1) DID. 0x48 + ECAM number. */
        uint64_t setup                 : 1;  /**< [ 35: 35] Reserved, MBZ.
                                                                 Internal:
                                                                 Reserved for future use - Setup. Allow certain PCC
                                                                 configuration registers to be written for boot-time initialization. Treated as 0
                                                                 unless in secure mode. */
        uint64_t bcst                  : 1;  /**< [ 34: 34] Reserved, MBZ.
                                                                 Internal:
                                                                 Reserved for future use - Broadcast. Write to all PCC
                                                                 blocks for fast configuration. Treated as 0 unless in secure mode and SETUP is
                                                                 set. */
        uint64_t reserved_28_33        : 6;
        uint64_t bus                   : 8;  /**< [ 27: 20] Bus number. */
        uint64_t func                  : 8;  /**< [ 19: 12] Function number. Note this assumes an ARI device; for external PCI devices that do not
                                                                 support ARI this contains both the device and function number. */
        uint64_t addr                  : 12; /**< [ 11:  0] Register address within the device. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 12; /**< [ 11:  0] Register address within the device. */
        uint64_t func                  : 8;  /**< [ 19: 12] Function number. Note this assumes an ARI device; for external PCI devices that do not
                                                                 support ARI this contains both the device and function number. */
        uint64_t bus                   : 8;  /**< [ 27: 20] Bus number. */
        uint64_t reserved_28_33        : 6;
        uint64_t bcst                  : 1;  /**< [ 34: 34] Reserved, MBZ.
                                                                 Internal:
                                                                 Reserved for future use - Broadcast. Write to all PCC
                                                                 blocks for fast configuration. Treated as 0 unless in secure mode and SETUP is
                                                                 set. */
        uint64_t setup                 : 1;  /**< [ 35: 35] Reserved, MBZ.
                                                                 Internal:
                                                                 Reserved for future use - Setup. Allow certain PCC
                                                                 configuration registers to be written for boot-time initialization. Treated as 0
                                                                 unless in secure mode. */
        uint64_t did                   : 8;  /**< [ 43: 36] ECAM(0..1) DID. 0x48 + ECAM number. */
        uint64_t node                  : 2;  /**< [ 45: 44] CCPI node number. */
        uint64_t reserved_46           : 1;
        uint64_t io                    : 1;  /**< [ 47: 47] Indicates I/O space. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } cn83xx;
};

/**
 * Register (RSL) ecam#_bus#_nsdis
 *
 * ECAM Bus Nonsecure Disable Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_ecamx_busx_nsdis_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t dis                   : 1;  /**< [  0:  0](R/W) Disable ECAM bus in nonsecure mode. If set, the indexed ECAM bus number is RAO/WI
                                                                 when accessed via the ECAM space with nonsecure transactions. Note this affects only ECAM
                                                                 configuration access, not normal I/O mapped memory accesses to the device. ECAM 0, bus 0
                                                                 (corresponding to RSL devices) is not generally disabled, instead  may be used to disable
                                                                 RSL discovery. */
#else /* Word 0 - Little Endian */
        uint64_t dis                   : 1;  /**< [  0:  0](R/W) Disable ECAM bus in nonsecure mode. If set, the indexed ECAM bus number is RAO/WI
                                                                 when accessed via the ECAM space with nonsecure transactions. Note this affects only ECAM
                                                                 configuration access, not normal I/O mapped memory accesses to the device. ECAM 0, bus 0
                                                                 (corresponding to RSL devices) is not generally disabled, instead  may be used to disable
                                                                 RSL discovery. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ecamx_busx_nsdis_s cn; */
} bdk_ecamx_busx_nsdis_t;

static inline uint64_t BDK_ECAMX_BUSX_NSDIS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_BUSX_NSDIS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=255)))
        return 0x87e048030000ll + 0x1000000ll * ((a) & 0x0) + 8ll * ((b) & 0xff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=255)))
        return 0x87e048030000ll + 0x1000000ll * ((a) & 0x1) + 8ll * ((b) & 0xff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=255)))
        return 0x87e048030000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0xff);
    __bdk_csr_fatal("ECAMX_BUSX_NSDIS", 2, a, b, 0, 0);
}

#define typedef_BDK_ECAMX_BUSX_NSDIS(a,b) bdk_ecamx_busx_nsdis_t
#define bustype_BDK_ECAMX_BUSX_NSDIS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_ECAMX_BUSX_NSDIS(a,b) "ECAMX_BUSX_NSDIS"
#define device_bar_BDK_ECAMX_BUSX_NSDIS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_ECAMX_BUSX_NSDIS(a,b) (a)
#define arguments_BDK_ECAMX_BUSX_NSDIS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ecam#_bus#_sdis
 *
 * ECAM Bus Secure Disable Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_ecamx_busx_sdis_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t sec                   : 1;  /**< [  1:  1](SR/W) Secure ECAM bus. If set, the indexed ECAM bus number is secured and RAO/WI when
                                                                 accessed via the ECAM space with nonsecure transactions. This bit overrides
                                                                 ECAM()_BUS()_NSDIS[DIS]. */
        uint64_t dis                   : 1;  /**< [  0:  0](SR/W) Disable ECAM bus in secure mode. If set, the indexed ECAM bus number is RAO/WI when
                                                                 accessed via the ECAM space with secure transactions. This bit is similar to the non-
                                                                 secure ECAM()_BUS()_NSDIS[DIS]. */
#else /* Word 0 - Little Endian */
        uint64_t dis                   : 1;  /**< [  0:  0](SR/W) Disable ECAM bus in secure mode. If set, the indexed ECAM bus number is RAO/WI when
                                                                 accessed via the ECAM space with secure transactions. This bit is similar to the non-
                                                                 secure ECAM()_BUS()_NSDIS[DIS]. */
        uint64_t sec                   : 1;  /**< [  1:  1](SR/W) Secure ECAM bus. If set, the indexed ECAM bus number is secured and RAO/WI when
                                                                 accessed via the ECAM space with nonsecure transactions. This bit overrides
                                                                 ECAM()_BUS()_NSDIS[DIS]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ecamx_busx_sdis_s cn; */
} bdk_ecamx_busx_sdis_t;

static inline uint64_t BDK_ECAMX_BUSX_SDIS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_BUSX_SDIS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=255)))
        return 0x87e048020000ll + 0x1000000ll * ((a) & 0x0) + 8ll * ((b) & 0xff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=255)))
        return 0x87e048020000ll + 0x1000000ll * ((a) & 0x1) + 8ll * ((b) & 0xff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=255)))
        return 0x87e048020000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0xff);
    __bdk_csr_fatal("ECAMX_BUSX_SDIS", 2, a, b, 0, 0);
}

#define typedef_BDK_ECAMX_BUSX_SDIS(a,b) bdk_ecamx_busx_sdis_t
#define bustype_BDK_ECAMX_BUSX_SDIS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_ECAMX_BUSX_SDIS(a,b) "ECAMX_BUSX_SDIS"
#define device_bar_BDK_ECAMX_BUSX_SDIS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_ECAMX_BUSX_SDIS(a,b) (a)
#define arguments_BDK_ECAMX_BUSX_SDIS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ecam#_bus#_skill
 *
 * ECAM Bus Secure Disable Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_ecamx_busx_skill_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t skill                 : 1;  /**< [  0:  0](SR/W1S) ECAM bus kill.
                                                                 Write one to set. Once set, cannot be cleared until soft reset. If set,
                                                                 the indexed ECAM bus/function/device number is RAO/WI when accessed via
                                                                 the ECAM space with any (secure/nonsecure) transactions. */
#else /* Word 0 - Little Endian */
        uint64_t skill                 : 1;  /**< [  0:  0](SR/W1S) ECAM bus kill.
                                                                 Write one to set. Once set, cannot be cleared until soft reset. If set,
                                                                 the indexed ECAM bus/function/device number is RAO/WI when accessed via
                                                                 the ECAM space with any (secure/nonsecure) transactions. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ecamx_busx_skill_s cn; */
} bdk_ecamx_busx_skill_t;

static inline uint64_t BDK_ECAMX_BUSX_SKILL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_BUSX_SKILL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=255)))
        return 0x87e048080000ll + 0x1000000ll * ((a) & 0x0) + 8ll * ((b) & 0xff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=255)))
        return 0x87e048080000ll + 0x1000000ll * ((a) & 0x1) + 8ll * ((b) & 0xff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((a<=3) && (b<=255)))
        return 0x87e048080000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0xff);
    __bdk_csr_fatal("ECAMX_BUSX_SKILL", 2, a, b, 0, 0);
}

#define typedef_BDK_ECAMX_BUSX_SKILL(a,b) bdk_ecamx_busx_skill_t
#define bustype_BDK_ECAMX_BUSX_SKILL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_ECAMX_BUSX_SKILL(a,b) "ECAMX_BUSX_SKILL"
#define device_bar_BDK_ECAMX_BUSX_SKILL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_ECAMX_BUSX_SKILL(a,b) (a)
#define arguments_BDK_ECAMX_BUSX_SKILL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ecam#_const
 *
 * ECAM Constants Register
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_ecamx_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t ecams                 : 8;  /**< [  7:  0](RO) Number of ECAM units. */
#else /* Word 0 - Little Endian */
        uint64_t ecams                 : 8;  /**< [  7:  0](RO) Number of ECAM units. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    struct bdk_ecamx_const_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t ecams                 : 8;  /**< [  7:  0](RO) Number of ECAM units.
                                                                 Internal:
                                                                 FIXME after update unit count, need reset_matches_size: "ECAM()_CONST,a" */
#else /* Word 0 - Little Endian */
        uint64_t ecams                 : 8;  /**< [  7:  0](RO) Number of ECAM units.
                                                                 Internal:
                                                                 FIXME after update unit count, need reset_matches_size: "ECAM()_CONST,a" */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_ecamx_const_s cn83xx; */
} bdk_ecamx_const_t;

static inline uint64_t BDK_ECAMX_CONST(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_CONST(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e048000200ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e048000200ll + 0x1000000ll * ((a) & 0x1);
    __bdk_csr_fatal("ECAMX_CONST", 1, a, 0, 0, 0);
}

#define typedef_BDK_ECAMX_CONST(a) bdk_ecamx_const_t
#define bustype_BDK_ECAMX_CONST(a) BDK_CSR_TYPE_RSL
#define basename_BDK_ECAMX_CONST(a) "ECAMX_CONST"
#define device_bar_BDK_ECAMX_CONST(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ECAMX_CONST(a) (a)
#define arguments_BDK_ECAMX_CONST(a) (a),-1,-1,-1

/**
 * Register (RSL) ecam#_dev#_nsdis
 *
 * ECAM Device Nonsecure Disable Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_ecamx_devx_nsdis_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t dis                   : 1;  /**< [  0:  0](R/W) Disable ECAM device in nonsecure mode. If set, the specified device
                                                                 number on bus 0 are RAO/WI when accessed via the ECAM space with
                                                                 nonsecure transactions. Note this affects only ECAM configuration
                                                                 access, not normal I/O mapped memory accesses to the device. */
#else /* Word 0 - Little Endian */
        uint64_t dis                   : 1;  /**< [  0:  0](R/W) Disable ECAM device in nonsecure mode. If set, the specified device
                                                                 number on bus 0 are RAO/WI when accessed via the ECAM space with
                                                                 nonsecure transactions. Note this affects only ECAM configuration
                                                                 access, not normal I/O mapped memory accesses to the device. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ecamx_devx_nsdis_s cn; */
} bdk_ecamx_devx_nsdis_t;

static inline uint64_t BDK_ECAMX_DEVX_NSDIS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_DEVX_NSDIS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=31)))
        return 0x87e048070000ll + 0x1000000ll * ((a) & 0x0) + 8ll * ((b) & 0x1f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=31)))
        return 0x87e048070000ll + 0x1000000ll * ((a) & 0x1) + 8ll * ((b) & 0x1f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=31)))
        return 0x87e048070000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x1f);
    __bdk_csr_fatal("ECAMX_DEVX_NSDIS", 2, a, b, 0, 0);
}

#define typedef_BDK_ECAMX_DEVX_NSDIS(a,b) bdk_ecamx_devx_nsdis_t
#define bustype_BDK_ECAMX_DEVX_NSDIS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_ECAMX_DEVX_NSDIS(a,b) "ECAMX_DEVX_NSDIS"
#define device_bar_BDK_ECAMX_DEVX_NSDIS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_ECAMX_DEVX_NSDIS(a,b) (a)
#define arguments_BDK_ECAMX_DEVX_NSDIS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ecam#_dev#_sdis
 *
 * ECAM Device Secure Disable Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_ecamx_devx_sdis_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t sec                   : 1;  /**< [  1:  1](SR/W) Secure ECAM device. If set, the indexed device number on bus 0 are
                                                                 secured and RAO/WI when accessed via the ECAM space with nonsecure
                                                                 transactions. This bit overrides ECAM()_DEV()_NSDIS[DIS]. */
        uint64_t dis                   : 1;  /**< [  0:  0](SR/W) Disable ECAM device in secure mode. If set, ECAM secure
                                                                 read/write operations to the indexed device number on bus 0
                                                                 are RAO/WI when accessed via the ECAM space. This bit is
                                                                 similar to the nonsecure ECAM()_DEV()_NSDIS[DIS]. */
#else /* Word 0 - Little Endian */
        uint64_t dis                   : 1;  /**< [  0:  0](SR/W) Disable ECAM device in secure mode. If set, ECAM secure
                                                                 read/write operations to the indexed device number on bus 0
                                                                 are RAO/WI when accessed via the ECAM space. This bit is
                                                                 similar to the nonsecure ECAM()_DEV()_NSDIS[DIS]. */
        uint64_t sec                   : 1;  /**< [  1:  1](SR/W) Secure ECAM device. If set, the indexed device number on bus 0 are
                                                                 secured and RAO/WI when accessed via the ECAM space with nonsecure
                                                                 transactions. This bit overrides ECAM()_DEV()_NSDIS[DIS]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ecamx_devx_sdis_s cn; */
} bdk_ecamx_devx_sdis_t;

static inline uint64_t BDK_ECAMX_DEVX_SDIS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_DEVX_SDIS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=31)))
        return 0x87e048060000ll + 0x1000000ll * ((a) & 0x0) + 8ll * ((b) & 0x1f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=31)))
        return 0x87e048060000ll + 0x1000000ll * ((a) & 0x1) + 8ll * ((b) & 0x1f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=31)))
        return 0x87e048060000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x1f);
    __bdk_csr_fatal("ECAMX_DEVX_SDIS", 2, a, b, 0, 0);
}

#define typedef_BDK_ECAMX_DEVX_SDIS(a,b) bdk_ecamx_devx_sdis_t
#define bustype_BDK_ECAMX_DEVX_SDIS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_ECAMX_DEVX_SDIS(a,b) "ECAMX_DEVX_SDIS"
#define device_bar_BDK_ECAMX_DEVX_SDIS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_ECAMX_DEVX_SDIS(a,b) (a)
#define arguments_BDK_ECAMX_DEVX_SDIS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ecam#_dev#_skill
 *
 * ECAM Device Secure Disable Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_ecamx_devx_skill_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t skill                 : 1;  /**< [  0:  0](SR/W1S) ECAM device kill.
                                                                 Write one to set. Once set, cannot be cleared until soft reset. If set,
                                                                 the indexed ECAM bus/function/device number is RAO/WI when accessed via
                                                                 the ECAM space with any (secure/nonsecure) transactions. */
#else /* Word 0 - Little Endian */
        uint64_t skill                 : 1;  /**< [  0:  0](SR/W1S) ECAM device kill.
                                                                 Write one to set. Once set, cannot be cleared until soft reset. If set,
                                                                 the indexed ECAM bus/function/device number is RAO/WI when accessed via
                                                                 the ECAM space with any (secure/nonsecure) transactions. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ecamx_devx_skill_s cn; */
} bdk_ecamx_devx_skill_t;

static inline uint64_t BDK_ECAMX_DEVX_SKILL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_DEVX_SKILL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=31)))
        return 0x87e0480a0000ll + 0x1000000ll * ((a) & 0x0) + 8ll * ((b) & 0x1f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=31)))
        return 0x87e0480a0000ll + 0x1000000ll * ((a) & 0x1) + 8ll * ((b) & 0x1f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((a<=3) && (b<=31)))
        return 0x87e0480a0000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x1f);
    __bdk_csr_fatal("ECAMX_DEVX_SKILL", 2, a, b, 0, 0);
}

#define typedef_BDK_ECAMX_DEVX_SKILL(a,b) bdk_ecamx_devx_skill_t
#define bustype_BDK_ECAMX_DEVX_SKILL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_ECAMX_DEVX_SKILL(a,b) "ECAMX_DEVX_SKILL"
#define device_bar_BDK_ECAMX_DEVX_SKILL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_ECAMX_DEVX_SKILL(a,b) (a)
#define arguments_BDK_ECAMX_DEVX_SKILL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ecam#_nop_of
 *
 * ECAM No-Operation Ones Faulting Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ecamx_nop_of_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ones                  : 64; /**< [ 63:  0](RO) Used internally to handle disabled read/write transactions. */
#else /* Word 0 - Little Endian */
        uint64_t ones                  : 64; /**< [ 63:  0](RO) Used internally to handle disabled read/write transactions. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ecamx_nop_of_s cn; */
} bdk_ecamx_nop_of_t;

static inline uint64_t BDK_ECAMX_NOP_OF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_NOP_OF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e048000000ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e048000000ll + 0x1000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x87e048000000ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("ECAMX_NOP_OF", 1, a, 0, 0, 0);
}

#define typedef_BDK_ECAMX_NOP_OF(a) bdk_ecamx_nop_of_t
#define bustype_BDK_ECAMX_NOP_OF(a) BDK_CSR_TYPE_RSL
#define basename_BDK_ECAMX_NOP_OF(a) "ECAMX_NOP_OF"
#define device_bar_BDK_ECAMX_NOP_OF(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ECAMX_NOP_OF(a) (a)
#define arguments_BDK_ECAMX_NOP_OF(a) (a),-1,-1,-1

/**
 * Register (RSL) ecam#_nop_onf
 *
 * ECAM No-Operation Ones Non-Faulting Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ecamx_nop_onf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ones                  : 64; /**< [ 63:  0](RO) Used internally to handle disabled read/write transactions. */
#else /* Word 0 - Little Endian */
        uint64_t ones                  : 64; /**< [ 63:  0](RO) Used internally to handle disabled read/write transactions. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ecamx_nop_onf_s cn; */
} bdk_ecamx_nop_onf_t;

static inline uint64_t BDK_ECAMX_NOP_ONF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_NOP_ONF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e048000080ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e048000080ll + 0x1000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x87e048000080ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("ECAMX_NOP_ONF", 1, a, 0, 0, 0);
}

#define typedef_BDK_ECAMX_NOP_ONF(a) bdk_ecamx_nop_onf_t
#define bustype_BDK_ECAMX_NOP_ONF(a) BDK_CSR_TYPE_RSL
#define basename_BDK_ECAMX_NOP_ONF(a) "ECAMX_NOP_ONF"
#define device_bar_BDK_ECAMX_NOP_ONF(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ECAMX_NOP_ONF(a) (a)
#define arguments_BDK_ECAMX_NOP_ONF(a) (a),-1,-1,-1

/**
 * Register (RSL) ecam#_nop_zf
 *
 * ECAM No-Operation Zero Faulting Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ecamx_nop_zf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t zeros                 : 64; /**< [ 63:  0](RO) Used internally to handle disabled read/write transactions. */
#else /* Word 0 - Little Endian */
        uint64_t zeros                 : 64; /**< [ 63:  0](RO) Used internally to handle disabled read/write transactions. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ecamx_nop_zf_s cn; */
} bdk_ecamx_nop_zf_t;

static inline uint64_t BDK_ECAMX_NOP_ZF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_NOP_ZF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e048000100ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e048000100ll + 0x1000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x87e048000100ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("ECAMX_NOP_ZF", 1, a, 0, 0, 0);
}

#define typedef_BDK_ECAMX_NOP_ZF(a) bdk_ecamx_nop_zf_t
#define bustype_BDK_ECAMX_NOP_ZF(a) BDK_CSR_TYPE_RSL
#define basename_BDK_ECAMX_NOP_ZF(a) "ECAMX_NOP_ZF"
#define device_bar_BDK_ECAMX_NOP_ZF(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ECAMX_NOP_ZF(a) (a)
#define arguments_BDK_ECAMX_NOP_ZF(a) (a),-1,-1,-1

/**
 * Register (RSL) ecam#_nop_znf
 *
 * ECAM No-Operation Zero Non-Faulting Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ecamx_nop_znf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t zeros                 : 64; /**< [ 63:  0](RO) Used internally to handle disabled read/write transactions. */
#else /* Word 0 - Little Endian */
        uint64_t zeros                 : 64; /**< [ 63:  0](RO) Used internally to handle disabled read/write transactions. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ecamx_nop_znf_s cn; */
} bdk_ecamx_nop_znf_t;

static inline uint64_t BDK_ECAMX_NOP_ZNF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_NOP_ZNF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e048000180ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e048000180ll + 0x1000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x87e048000180ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("ECAMX_NOP_ZNF", 1, a, 0, 0, 0);
}

#define typedef_BDK_ECAMX_NOP_ZNF(a) bdk_ecamx_nop_znf_t
#define bustype_BDK_ECAMX_NOP_ZNF(a) BDK_CSR_TYPE_RSL
#define basename_BDK_ECAMX_NOP_ZNF(a) "ECAMX_NOP_ZNF"
#define device_bar_BDK_ECAMX_NOP_ZNF(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ECAMX_NOP_ZNF(a) (a)
#define arguments_BDK_ECAMX_NOP_ZNF(a) (a),-1,-1,-1

/**
 * Register (RSL) ecam#_rsl#_nsdis
 *
 * ECAM RSL Function Nonsecure Disable Registers
 * This register is only implemented for ECAM0 which sources RSL.
 */
typedef union
{
    uint64_t u;
    struct bdk_ecamx_rslx_nsdis_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t dis                   : 1;  /**< [  0:  0](R/W) Disable ECAM RSL function in nonsecure mode. If set, the specified RSL function number
                                                                 (under ECAM 0 bus 1) is RAO/WI when accessed via the ECAM space with nonsecure
                                                                 transactions. Note this affects only ECAM configuration access, not normal I/O mapped
                                                                 memory accesses to the device. */
#else /* Word 0 - Little Endian */
        uint64_t dis                   : 1;  /**< [  0:  0](R/W) Disable ECAM RSL function in nonsecure mode. If set, the specified RSL function number
                                                                 (under ECAM 0 bus 1) is RAO/WI when accessed via the ECAM space with nonsecure
                                                                 transactions. Note this affects only ECAM configuration access, not normal I/O mapped
                                                                 memory accesses to the device. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ecamx_rslx_nsdis_s cn; */
} bdk_ecamx_rslx_nsdis_t;

static inline uint64_t BDK_ECAMX_RSLX_NSDIS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_RSLX_NSDIS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=255)))
        return 0x87e048050000ll + 0x1000000ll * ((a) & 0x0) + 8ll * ((b) & 0xff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=255)))
        return 0x87e048050000ll + 0x1000000ll * ((a) & 0x1) + 8ll * ((b) & 0xff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=255)))
        return 0x87e048050000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0xff);
    __bdk_csr_fatal("ECAMX_RSLX_NSDIS", 2, a, b, 0, 0);
}

#define typedef_BDK_ECAMX_RSLX_NSDIS(a,b) bdk_ecamx_rslx_nsdis_t
#define bustype_BDK_ECAMX_RSLX_NSDIS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_ECAMX_RSLX_NSDIS(a,b) "ECAMX_RSLX_NSDIS"
#define device_bar_BDK_ECAMX_RSLX_NSDIS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_ECAMX_RSLX_NSDIS(a,b) (a)
#define arguments_BDK_ECAMX_RSLX_NSDIS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ecam#_rsl#_sdis
 *
 * ECAM RSL Function Secure Disable Registers
 * This register is only implemented for ECAM0 which sources RSL.
 */
typedef union
{
    uint64_t u;
    struct bdk_ecamx_rslx_sdis_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t sec                   : 1;  /**< [  1:  1](SR/W) Secure ECAM RSL function. If set, the indexed RSL function number (under ECAM 0
                                                                 bus 1) is secured and RAO/WI when accessed via the ECAM space with nonsecure
                                                                 transactions. This bit overrides ECAM()_RSL()_NSDIS[DIS]. */
        uint64_t dis                   : 1;  /**< [  0:  0](SR/W) Disable ECAM RSL function in secure mode. If set, ECAM secure read/write operations to the
                                                                 indexed
                                                                 RSL function number (under ECAM 0 bus 1) are RAO/WI when accessed via the ECAM
                                                                 space. This bit is similar to the nonsecure ECAM()_RSL()_NSDIS[DIS]. */
#else /* Word 0 - Little Endian */
        uint64_t dis                   : 1;  /**< [  0:  0](SR/W) Disable ECAM RSL function in secure mode. If set, ECAM secure read/write operations to the
                                                                 indexed
                                                                 RSL function number (under ECAM 0 bus 1) are RAO/WI when accessed via the ECAM
                                                                 space. This bit is similar to the nonsecure ECAM()_RSL()_NSDIS[DIS]. */
        uint64_t sec                   : 1;  /**< [  1:  1](SR/W) Secure ECAM RSL function. If set, the indexed RSL function number (under ECAM 0
                                                                 bus 1) is secured and RAO/WI when accessed via the ECAM space with nonsecure
                                                                 transactions. This bit overrides ECAM()_RSL()_NSDIS[DIS]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ecamx_rslx_sdis_s cn; */
} bdk_ecamx_rslx_sdis_t;

static inline uint64_t BDK_ECAMX_RSLX_SDIS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_RSLX_SDIS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=255)))
        return 0x87e048040000ll + 0x1000000ll * ((a) & 0x0) + 8ll * ((b) & 0xff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=255)))
        return 0x87e048040000ll + 0x1000000ll * ((a) & 0x1) + 8ll * ((b) & 0xff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=255)))
        return 0x87e048040000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0xff);
    __bdk_csr_fatal("ECAMX_RSLX_SDIS", 2, a, b, 0, 0);
}

#define typedef_BDK_ECAMX_RSLX_SDIS(a,b) bdk_ecamx_rslx_sdis_t
#define bustype_BDK_ECAMX_RSLX_SDIS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_ECAMX_RSLX_SDIS(a,b) "ECAMX_RSLX_SDIS"
#define device_bar_BDK_ECAMX_RSLX_SDIS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_ECAMX_RSLX_SDIS(a,b) (a)
#define arguments_BDK_ECAMX_RSLX_SDIS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ecam#_rsl#_skill
 *
 * ECAM RSL Function Secure Disable Registers
 * This register is only implemented for ECAM0 which sources RSL.
 */
typedef union
{
    uint64_t u;
    struct bdk_ecamx_rslx_skill_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t skill                 : 1;  /**< [  0:  0](SR/W1S) ECAM function kill.
                                                                 Write one to set. Once set, cannot be cleared until soft reset. If set,
                                                                 the indexed ECAM bus/function/device number is RAO/WI when accessed via
                                                                 the ECAM space with any (secure/nonsecure) transactions. */
#else /* Word 0 - Little Endian */
        uint64_t skill                 : 1;  /**< [  0:  0](SR/W1S) ECAM function kill.
                                                                 Write one to set. Once set, cannot be cleared until soft reset. If set,
                                                                 the indexed ECAM bus/function/device number is RAO/WI when accessed via
                                                                 the ECAM space with any (secure/nonsecure) transactions. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ecamx_rslx_skill_s cn; */
} bdk_ecamx_rslx_skill_t;

static inline uint64_t BDK_ECAMX_RSLX_SKILL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_RSLX_SKILL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=255)))
        return 0x87e048090000ll + 0x1000000ll * ((a) & 0x0) + 8ll * ((b) & 0xff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=255)))
        return 0x87e048090000ll + 0x1000000ll * ((a) & 0x1) + 8ll * ((b) & 0xff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((a<=3) && (b<=255)))
        return 0x87e048090000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0xff);
    __bdk_csr_fatal("ECAMX_RSLX_SKILL", 2, a, b, 0, 0);
}

#define typedef_BDK_ECAMX_RSLX_SKILL(a,b) bdk_ecamx_rslx_skill_t
#define bustype_BDK_ECAMX_RSLX_SKILL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_ECAMX_RSLX_SKILL(a,b) "ECAMX_RSLX_SKILL"
#define device_bar_BDK_ECAMX_RSLX_SKILL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_ECAMX_RSLX_SKILL(a,b) (a)
#define arguments_BDK_ECAMX_RSLX_SKILL(a,b) (a),(b),-1,-1

#endif /* __BDK_CSRS_ECAM_H__ */
