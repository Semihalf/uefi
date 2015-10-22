#ifndef __BDK_CSRS_MIO_FUS_H__
#define __BDK_CSRS_MIO_FUS_H__
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
 * Cavium MIO_FUS.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration mio_fus_bar_e
 *
 * MIO FUS Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_MIO_FUS_BAR_E_MIO_FUS_PF_BAR0 (0x87e003000000ll) /**< Base address for standard registers. */

/**
 * Register (RSL) mio_fus_bnk_dat#
 *
 * MIO Fuse Bank Store Register
 * The initial state of MIO_FUS_BNK_DAT(0..1) is as if bank6 were just read,
 * i.e. DAT* = fus[895:768].
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_bnk_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](R/W/H) Efuse bank store. For read operations, the DAT gets the fus bank last read. For write
                                                                 operations, the DAT determines which fuses to blow. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](R/W/H) Efuse bank store. For read operations, the DAT gets the fus bank last read. For write
                                                                 operations, the DAT determines which fuses to blow. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_bnk_datx_s cn; */
} bdk_mio_fus_bnk_datx_t;

static inline uint64_t BDK_MIO_FUS_BNK_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_BNK_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e003001520ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("MIO_FUS_BNK_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_MIO_FUS_BNK_DATX(a) bdk_mio_fus_bnk_datx_t
#define bustype_BDK_MIO_FUS_BNK_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_BNK_DATX(a) "MIO_FUS_BNK_DATX"
#define device_bar_BDK_MIO_FUS_BNK_DATX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_BNK_DATX(a) (a)
#define arguments_BDK_MIO_FUS_BNK_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) mio_fus_dat0
 *
 * MIO Fuse Data Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_dat0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t man_info              : 32; /**< [ 31:  0](RO) Fuse information - manufacturing info [31:0]. */
#else /* Word 0 - Little Endian */
        uint64_t man_info              : 32; /**< [ 31:  0](RO) Fuse information - manufacturing info [31:0]. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_dat0_s cn; */
} bdk_mio_fus_dat0_t;

#define BDK_MIO_FUS_DAT0 BDK_MIO_FUS_DAT0_FUNC()
static inline uint64_t BDK_MIO_FUS_DAT0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_DAT0_FUNC(void)
{
    return 0x87e003001400ll;
}

#define typedef_BDK_MIO_FUS_DAT0 bdk_mio_fus_dat0_t
#define bustype_BDK_MIO_FUS_DAT0 BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_DAT0 "MIO_FUS_DAT0"
#define device_bar_BDK_MIO_FUS_DAT0 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_DAT0 0
#define arguments_BDK_MIO_FUS_DAT0 -1,-1,-1,-1

/**
 * Register (RSL) mio_fus_dat1
 *
 * MIO Fuse Data Register 1
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_dat1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t man_info              : 32; /**< [ 31:  0](RO) Fuse information - manufacturing info [63:32]. */
#else /* Word 0 - Little Endian */
        uint64_t man_info              : 32; /**< [ 31:  0](RO) Fuse information - manufacturing info [63:32]. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_dat1_s cn; */
} bdk_mio_fus_dat1_t;

#define BDK_MIO_FUS_DAT1 BDK_MIO_FUS_DAT1_FUNC()
static inline uint64_t BDK_MIO_FUS_DAT1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_DAT1_FUNC(void)
{
    return 0x87e003001408ll;
}

#define typedef_BDK_MIO_FUS_DAT1 bdk_mio_fus_dat1_t
#define bustype_BDK_MIO_FUS_DAT1 BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_DAT1 "MIO_FUS_DAT1"
#define device_bar_BDK_MIO_FUS_DAT1 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_DAT1 0
#define arguments_BDK_MIO_FUS_DAT1 -1,-1,-1,-1

/**
 * Register (RSL) mio_fus_dat2
 *
 * MIO Fuse Data Register 2
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_dat2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_59_63        : 5;
        uint64_t run_platform          : 3;  /**< [ 58: 56](RO) Fuses to indicate the run platform. Not to be blown in actual hardware.
                                                                 Provides software a means of determining the platform at run time.
                                                                 0x0 = Hardware.
                                                                 0x1 = Emulator.
                                                                 0x2 = RTL simulator.
                                                                 0x3 = ASIM.
                                                                 0x4-0x7 = reserved. */
        uint64_t gbl_pwr_throttle      : 8;  /**< [ 55: 48](RO) Controls global power throttling. MSB is a spare, and lower 7 bits indicate
                                                                 N/128 power reduction. Small values have less throttling and higher
                                                                 performance. 0x0 disables throttling.
                                                                 Added in pass 2. */
        uint64_t fus118                : 1;  /**< [ 47: 47](RO) Fuse information - Ignore trusted-mode disable.
                                                                 Internal:
                                                                 fuse[99]. */
        uint64_t rom_info              : 10; /**< [ 46: 37](RO) Fuse information - ROM info. */
        uint64_t power_limit           : 2;  /**< [ 36: 35](RO) Fuse information - Power limit. */
        uint64_t dorm_crypto           : 1;  /**< [ 34: 34](RO) Fuse information - Dormant encryption enable. See NOCRYPTO. */
        uint64_t fus318                : 1;  /**< [ 33: 33](RO) Reserved.
                                                                 Internal:
                                                                 Tied to 0. */
        uint64_t raid_en               : 1;  /**< [ 32: 32](RO) Fuse information - RAID enabled. */
        uint64_t reserved_29_31        : 3;
        uint64_t nodfa_cp2             : 1;  /**< [ 28: 28](RO) Fuse information - HFA disable (CP2). */
        uint64_t nomul                 : 1;  /**< [ 27: 27](RO) Fuse information - VMUL disable. */
        uint64_t nocrypto              : 1;  /**< [ 26: 26](RO) Fuse information - [DORM_CRYPTO] and [NOCRYPTO] together select the crypto mode:

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 0: AES/SHA/PMULL enabled.

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 1: The AES, SHA, and PMULL 1D/2D instructions will
                                                                 cause undefined exceptions, and AP_ID_AA64ISAR0_EL1[AES, SHA1, SHA2] are zero
                                                                 indicating this behavior.

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 0: Dormant encryption enable.  AES/SHA/PMULL are
                                                                 disabled (as if [NOCRYPTO] = 1) until the appropriate key is written to
                                                                 RNM_EER_KEY, then they are enabled (as if [NOCRYPTO] = 1).

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 1: Reserved. */
        uint64_t trustzone_en          : 1;  /**< [ 25: 25](RO) Fuse information - TrustZone enable. */
        uint64_t reserved_24           : 1;
        uint64_t chip_id               : 8;  /**< [ 23: 16](RO) Fuse information - chip ID. */
        uint64_t ocx_dis               : 1;  /**< [ 15: 15](RO) Fuse information - OCX disable. */
        uint64_t bgx_dis               : 2;  /**< [ 14: 13](RO) Fuse information - BGX disable:
                                                                   <13> = BGX0 disable.
                                                                   <14> = BGX1 disable. */
        uint64_t sata_dis              : 4;  /**< [ 12:  9](RO) Fuse information - SATA disable:
                                                                   <9> = SATA0-3 disable.
                                                                   <10> = SATA4-7 disable.
                                                                   <11> = SATA8-11 disable.
                                                                   <12> = SATA12-15 disable. */
        uint64_t pem_dis               : 3;  /**< [  8:  6](RO) Fuse information - PEM disable:
                                                                   <6> = PEM0-1 disable.
                                                                   <7> = PEM2-3 disable
                                                                   <8> = PEM4-5 disable. */
        uint64_t lmc_half              : 1;  /**< [  5:  5](RO) Fuse information - LMC uses two channels rather than four. */
        uint64_t reserved_0_4          : 5;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_4          : 5;
        uint64_t lmc_half              : 1;  /**< [  5:  5](RO) Fuse information - LMC uses two channels rather than four. */
        uint64_t pem_dis               : 3;  /**< [  8:  6](RO) Fuse information - PEM disable:
                                                                   <6> = PEM0-1 disable.
                                                                   <7> = PEM2-3 disable
                                                                   <8> = PEM4-5 disable. */
        uint64_t sata_dis              : 4;  /**< [ 12:  9](RO) Fuse information - SATA disable:
                                                                   <9> = SATA0-3 disable.
                                                                   <10> = SATA4-7 disable.
                                                                   <11> = SATA8-11 disable.
                                                                   <12> = SATA12-15 disable. */
        uint64_t bgx_dis               : 2;  /**< [ 14: 13](RO) Fuse information - BGX disable:
                                                                   <13> = BGX0 disable.
                                                                   <14> = BGX1 disable. */
        uint64_t ocx_dis               : 1;  /**< [ 15: 15](RO) Fuse information - OCX disable. */
        uint64_t chip_id               : 8;  /**< [ 23: 16](RO) Fuse information - chip ID. */
        uint64_t reserved_24           : 1;
        uint64_t trustzone_en          : 1;  /**< [ 25: 25](RO) Fuse information - TrustZone enable. */
        uint64_t nocrypto              : 1;  /**< [ 26: 26](RO) Fuse information - [DORM_CRYPTO] and [NOCRYPTO] together select the crypto mode:

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 0: AES/SHA/PMULL enabled.

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 1: The AES, SHA, and PMULL 1D/2D instructions will
                                                                 cause undefined exceptions, and AP_ID_AA64ISAR0_EL1[AES, SHA1, SHA2] are zero
                                                                 indicating this behavior.

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 0: Dormant encryption enable.  AES/SHA/PMULL are
                                                                 disabled (as if [NOCRYPTO] = 1) until the appropriate key is written to
                                                                 RNM_EER_KEY, then they are enabled (as if [NOCRYPTO] = 1).

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 1: Reserved. */
        uint64_t nomul                 : 1;  /**< [ 27: 27](RO) Fuse information - VMUL disable. */
        uint64_t nodfa_cp2             : 1;  /**< [ 28: 28](RO) Fuse information - HFA disable (CP2). */
        uint64_t reserved_29_31        : 3;
        uint64_t raid_en               : 1;  /**< [ 32: 32](RO) Fuse information - RAID enabled. */
        uint64_t fus318                : 1;  /**< [ 33: 33](RO) Reserved.
                                                                 Internal:
                                                                 Tied to 0. */
        uint64_t dorm_crypto           : 1;  /**< [ 34: 34](RO) Fuse information - Dormant encryption enable. See NOCRYPTO. */
        uint64_t power_limit           : 2;  /**< [ 36: 35](RO) Fuse information - Power limit. */
        uint64_t rom_info              : 10; /**< [ 46: 37](RO) Fuse information - ROM info. */
        uint64_t fus118                : 1;  /**< [ 47: 47](RO) Fuse information - Ignore trusted-mode disable.
                                                                 Internal:
                                                                 fuse[99]. */
        uint64_t gbl_pwr_throttle      : 8;  /**< [ 55: 48](RO) Controls global power throttling. MSB is a spare, and lower 7 bits indicate
                                                                 N/128 power reduction. Small values have less throttling and higher
                                                                 performance. 0x0 disables throttling.
                                                                 Added in pass 2. */
        uint64_t run_platform          : 3;  /**< [ 58: 56](RO) Fuses to indicate the run platform. Not to be blown in actual hardware.
                                                                 Provides software a means of determining the platform at run time.
                                                                 0x0 = Hardware.
                                                                 0x1 = Emulator.
                                                                 0x2 = RTL simulator.
                                                                 0x3 = ASIM.
                                                                 0x4-0x7 = reserved. */
        uint64_t reserved_59_63        : 5;
#endif /* Word 0 - End */
    } s;
    struct bdk_mio_fus_dat2_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_59_63        : 5;
        uint64_t run_platform          : 3;  /**< [ 58: 56](RO) Fuses to indicate the run platform. Not to be blown in actual hardware.
                                                                 Provides software a means of determining the platform at run time.
                                                                 0x0 = Hardware.
                                                                 0x1 = Emulator.
                                                                 0x2 = RTL simulator.
                                                                 0x3 = ASIM.
                                                                 0x4-0x7 = reserved. */
        uint64_t reserved_48_55        : 8;
        uint64_t fus118                : 1;  /**< [ 47: 47](RO) Fuse information - Ignore trusted-mode disable.
                                                                 Internal:
                                                                 fuse[99]. */
        uint64_t rom_info              : 10; /**< [ 46: 37](RO) Fuse information - ROM info. */
        uint64_t power_limit           : 2;  /**< [ 36: 35](RO) Fuse information - Power limit. */
        uint64_t dorm_crypto           : 1;  /**< [ 34: 34](RO) Fuse information - Dormant encryption enable. See NOCRYPTO. */
        uint64_t fus318                : 1;  /**< [ 33: 33](RO) Reserved.
                                                                 Internal:
                                                                 Tied to 0. */
        uint64_t raid_en               : 1;  /**< [ 32: 32](RO) Fuse information - RAID enabled. */
        uint64_t reserved_29_31        : 3;
        uint64_t nodfa_cp2             : 1;  /**< [ 28: 28](RO) Fuse information - HFA disable (CP2). */
        uint64_t nomul                 : 1;  /**< [ 27: 27](RO) Fuse information - VMUL disable. */
        uint64_t nocrypto              : 1;  /**< [ 26: 26](RO) Fuse information - [DORM_CRYPTO] and [NOCRYPTO] together select the crypto mode:

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 0: AES/SHA/PMULL enabled.

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 1: The AES, SHA, and PMULL 1D/2D instructions will
                                                                 cause undefined exceptions, and AP_ID_AA64ISAR0_EL1[AES, SHA1, SHA2] are zero
                                                                 indicating this behavior.

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 0: Dormant encryption enable.  AES/SHA/PMULL are
                                                                 disabled (as if [NOCRYPTO] = 1) until the appropriate key is written to
                                                                 RNM_EER_KEY, then they are enabled (as if [NOCRYPTO] = 1).

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 1: Reserved. */
        uint64_t trustzone_en          : 1;  /**< [ 25: 25](RO) Fuse information - TrustZone enable. */
        uint64_t reserved_24           : 1;
        uint64_t chip_id               : 8;  /**< [ 23: 16](RO) Fuse information - chip ID. */
        uint64_t ocx_dis               : 1;  /**< [ 15: 15](RO) Fuse information - OCX disable. */
        uint64_t bgx_dis               : 2;  /**< [ 14: 13](RO) Fuse information - BGX disable:
                                                                   <13> = BGX0 disable.
                                                                   <14> = BGX1 disable. */
        uint64_t sata_dis              : 4;  /**< [ 12:  9](RO) Fuse information - SATA disable:
                                                                   <9> = SATA0-3 disable.
                                                                   <10> = SATA4-7 disable.
                                                                   <11> = SATA8-11 disable.
                                                                   <12> = SATA12-15 disable. */
        uint64_t pem_dis               : 3;  /**< [  8:  6](RO) Fuse information - PEM disable:
                                                                   <6> = PEM0-1 disable.
                                                                   <7> = PEM2-3 disable
                                                                   <8> = PEM4-5 disable. */
        uint64_t lmc_half              : 1;  /**< [  5:  5](RO) Fuse information - LMC uses two channels rather than four. */
        uint64_t reserved_0_4          : 5;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_4          : 5;
        uint64_t lmc_half              : 1;  /**< [  5:  5](RO) Fuse information - LMC uses two channels rather than four. */
        uint64_t pem_dis               : 3;  /**< [  8:  6](RO) Fuse information - PEM disable:
                                                                   <6> = PEM0-1 disable.
                                                                   <7> = PEM2-3 disable
                                                                   <8> = PEM4-5 disable. */
        uint64_t sata_dis              : 4;  /**< [ 12:  9](RO) Fuse information - SATA disable:
                                                                   <9> = SATA0-3 disable.
                                                                   <10> = SATA4-7 disable.
                                                                   <11> = SATA8-11 disable.
                                                                   <12> = SATA12-15 disable. */
        uint64_t bgx_dis               : 2;  /**< [ 14: 13](RO) Fuse information - BGX disable:
                                                                   <13> = BGX0 disable.
                                                                   <14> = BGX1 disable. */
        uint64_t ocx_dis               : 1;  /**< [ 15: 15](RO) Fuse information - OCX disable. */
        uint64_t chip_id               : 8;  /**< [ 23: 16](RO) Fuse information - chip ID. */
        uint64_t reserved_24           : 1;
        uint64_t trustzone_en          : 1;  /**< [ 25: 25](RO) Fuse information - TrustZone enable. */
        uint64_t nocrypto              : 1;  /**< [ 26: 26](RO) Fuse information - [DORM_CRYPTO] and [NOCRYPTO] together select the crypto mode:

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 0: AES/SHA/PMULL enabled.

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 1: The AES, SHA, and PMULL 1D/2D instructions will
                                                                 cause undefined exceptions, and AP_ID_AA64ISAR0_EL1[AES, SHA1, SHA2] are zero
                                                                 indicating this behavior.

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 0: Dormant encryption enable.  AES/SHA/PMULL are
                                                                 disabled (as if [NOCRYPTO] = 1) until the appropriate key is written to
                                                                 RNM_EER_KEY, then they are enabled (as if [NOCRYPTO] = 1).

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 1: Reserved. */
        uint64_t nomul                 : 1;  /**< [ 27: 27](RO) Fuse information - VMUL disable. */
        uint64_t nodfa_cp2             : 1;  /**< [ 28: 28](RO) Fuse information - HFA disable (CP2). */
        uint64_t reserved_29_31        : 3;
        uint64_t raid_en               : 1;  /**< [ 32: 32](RO) Fuse information - RAID enabled. */
        uint64_t fus318                : 1;  /**< [ 33: 33](RO) Reserved.
                                                                 Internal:
                                                                 Tied to 0. */
        uint64_t dorm_crypto           : 1;  /**< [ 34: 34](RO) Fuse information - Dormant encryption enable. See NOCRYPTO. */
        uint64_t power_limit           : 2;  /**< [ 36: 35](RO) Fuse information - Power limit. */
        uint64_t rom_info              : 10; /**< [ 46: 37](RO) Fuse information - ROM info. */
        uint64_t fus118                : 1;  /**< [ 47: 47](RO) Fuse information - Ignore trusted-mode disable.
                                                                 Internal:
                                                                 fuse[99]. */
        uint64_t reserved_48_55        : 8;
        uint64_t run_platform          : 3;  /**< [ 58: 56](RO) Fuses to indicate the run platform. Not to be blown in actual hardware.
                                                                 Provides software a means of determining the platform at run time.
                                                                 0x0 = Hardware.
                                                                 0x1 = Emulator.
                                                                 0x2 = RTL simulator.
                                                                 0x3 = ASIM.
                                                                 0x4-0x7 = reserved. */
        uint64_t reserved_59_63        : 5;
#endif /* Word 0 - End */
    } cn88xxp1;
    struct bdk_mio_fus_dat2_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_59_63        : 5;
        uint64_t run_platform          : 3;  /**< [ 58: 56](RO) Fuses to indicate the run platform. Not to be blown in actual hardware.
                                                                 Provides software a means of determining the platform at run time.
                                                                 0x0 = Hardware.
                                                                 0x1 = Emulator.
                                                                 0x2 = RTL simulator.
                                                                 0x3 = ASIM.
                                                                 0x4-0x7 = reserved. */
        uint64_t gbl_pwr_throttle      : 8;  /**< [ 55: 48](RO) Controls global power throttling. MSB is a spare, and lower 7 bits indicate
                                                                 N/128 power reduction. Small values have less throttling and higher
                                                                 performance. 0x0 disables throttling. */
        uint64_t fus118                : 1;  /**< [ 47: 47](RO) Fuse information - Ignore trusted-mode disable.
                                                                 Internal:
                                                                 fuse[99]. */
        uint64_t rom_info              : 10; /**< [ 46: 37](RO) Fuse information - ROM info. */
        uint64_t power_limit           : 2;  /**< [ 36: 35](RO) Fuse information - Power limit. */
        uint64_t dorm_crypto           : 1;  /**< [ 34: 34](RO) Fuse information - Dormant encryption enable. See NOCRYPTO. */
        uint64_t fus318                : 1;  /**< [ 33: 33](RO) Reserved.
                                                                 Internal:
                                                                 Tied to 0. */
        uint64_t raid_en               : 1;  /**< [ 32: 32](RO) Fuse information - RAID enabled. */
        uint64_t reserved_29_31        : 3;
        uint64_t nodfa_cp2             : 1;  /**< [ 28: 28](RO) Fuse information - HFA disable (CP2). */
        uint64_t nomul                 : 1;  /**< [ 27: 27](RO) Fuse information - VMUL disable. */
        uint64_t nocrypto              : 1;  /**< [ 26: 26](RO) Fuse information - [DORM_CRYPTO] and [NOCRYPTO] together select the crypto mode:

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 0: AES/SHA/PMULL enabled.

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 1: The AES, SHA, and PMULL 1D/2D instructions will
                                                                 cause undefined exceptions, and AP_ID_AA64ISAR0_EL1[AES, SHA1, SHA2] are zero
                                                                 indicating this behavior.

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 0: Dormant encryption enable.  AES/SHA/PMULL are
                                                                 disabled (as if [NOCRYPTO] = 1) until the appropriate key is written to
                                                                 RNM_EER_KEY, then they are enabled (as if [NOCRYPTO] = 1).

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 1: Reserved. */
        uint64_t trustzone_en          : 1;  /**< [ 25: 25](RO) Fuse information - TrustZone enable. */
        uint64_t reserved_24           : 1;
        uint64_t chip_id               : 8;  /**< [ 23: 16](RO) Fuse information - chip ID. */
        uint64_t ocx_dis               : 1;  /**< [ 15: 15](RO) Fuse information - OCX disable. */
        uint64_t bgx_dis               : 2;  /**< [ 14: 13](RO) Fuse information - BGX disable:
                                                                   <13> = BGX0 disable.
                                                                   <14> = BGX1 disable. */
        uint64_t sata_dis              : 4;  /**< [ 12:  9](RO) Fuse information - SATA disable:
                                                                   <9> = SATA0 disable.
                                                                   <10> = SATA1 disable.
                                                                   <11> = Reserved.
                                                                   <12> = Reserved. */
        uint64_t pem_dis               : 3;  /**< [  8:  6](RO) Fuse information - PEM disable:
                                                                   <6> = PEM0 disable.
                                                                   <7> = PEM1 disable
                                                                   <8> = PEM2 disable. */
        uint64_t lmc_half              : 1;  /**< [  5:  5](RO) Fuse information - LMC1 disabled. */
        uint64_t reserved_0_4          : 5;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_4          : 5;
        uint64_t lmc_half              : 1;  /**< [  5:  5](RO) Fuse information - LMC1 disabled. */
        uint64_t pem_dis               : 3;  /**< [  8:  6](RO) Fuse information - PEM disable:
                                                                   <6> = PEM0 disable.
                                                                   <7> = PEM1 disable
                                                                   <8> = PEM2 disable. */
        uint64_t sata_dis              : 4;  /**< [ 12:  9](RO) Fuse information - SATA disable:
                                                                   <9> = SATA0 disable.
                                                                   <10> = SATA1 disable.
                                                                   <11> = Reserved.
                                                                   <12> = Reserved. */
        uint64_t bgx_dis               : 2;  /**< [ 14: 13](RO) Fuse information - BGX disable:
                                                                   <13> = BGX0 disable.
                                                                   <14> = BGX1 disable. */
        uint64_t ocx_dis               : 1;  /**< [ 15: 15](RO) Fuse information - OCX disable. */
        uint64_t chip_id               : 8;  /**< [ 23: 16](RO) Fuse information - chip ID. */
        uint64_t reserved_24           : 1;
        uint64_t trustzone_en          : 1;  /**< [ 25: 25](RO) Fuse information - TrustZone enable. */
        uint64_t nocrypto              : 1;  /**< [ 26: 26](RO) Fuse information - [DORM_CRYPTO] and [NOCRYPTO] together select the crypto mode:

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 0: AES/SHA/PMULL enabled.

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 1: The AES, SHA, and PMULL 1D/2D instructions will
                                                                 cause undefined exceptions, and AP_ID_AA64ISAR0_EL1[AES, SHA1, SHA2] are zero
                                                                 indicating this behavior.

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 0: Dormant encryption enable.  AES/SHA/PMULL are
                                                                 disabled (as if [NOCRYPTO] = 1) until the appropriate key is written to
                                                                 RNM_EER_KEY, then they are enabled (as if [NOCRYPTO] = 1).

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 1: Reserved. */
        uint64_t nomul                 : 1;  /**< [ 27: 27](RO) Fuse information - VMUL disable. */
        uint64_t nodfa_cp2             : 1;  /**< [ 28: 28](RO) Fuse information - HFA disable (CP2). */
        uint64_t reserved_29_31        : 3;
        uint64_t raid_en               : 1;  /**< [ 32: 32](RO) Fuse information - RAID enabled. */
        uint64_t fus318                : 1;  /**< [ 33: 33](RO) Reserved.
                                                                 Internal:
                                                                 Tied to 0. */
        uint64_t dorm_crypto           : 1;  /**< [ 34: 34](RO) Fuse information - Dormant encryption enable. See NOCRYPTO. */
        uint64_t power_limit           : 2;  /**< [ 36: 35](RO) Fuse information - Power limit. */
        uint64_t rom_info              : 10; /**< [ 46: 37](RO) Fuse information - ROM info. */
        uint64_t fus118                : 1;  /**< [ 47: 47](RO) Fuse information - Ignore trusted-mode disable.
                                                                 Internal:
                                                                 fuse[99]. */
        uint64_t gbl_pwr_throttle      : 8;  /**< [ 55: 48](RO) Controls global power throttling. MSB is a spare, and lower 7 bits indicate
                                                                 N/128 power reduction. Small values have less throttling and higher
                                                                 performance. 0x0 disables throttling. */
        uint64_t run_platform          : 3;  /**< [ 58: 56](RO) Fuses to indicate the run platform. Not to be blown in actual hardware.
                                                                 Provides software a means of determining the platform at run time.
                                                                 0x0 = Hardware.
                                                                 0x1 = Emulator.
                                                                 0x2 = RTL simulator.
                                                                 0x3 = ASIM.
                                                                 0x4-0x7 = reserved. */
        uint64_t reserved_59_63        : 5;
#endif /* Word 0 - End */
    } cn81xx;
    struct bdk_mio_fus_dat2_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_59_63        : 5;
        uint64_t run_platform          : 3;  /**< [ 58: 56](RO) Fuses to indicate the run platform. Not to be blown in actual hardware.
                                                                 Provides software a means of determining the platform at run time.
                                                                 0x0 = Hardware.
                                                                 0x1 = Emulator.
                                                                 0x2 = RTL simulator.
                                                                 0x3 = ASIM.
                                                                 0x4-0x7 = reserved. */
        uint64_t gbl_pwr_throttle      : 8;  /**< [ 55: 48](RO) Controls global power throttling. MSB is a spare, and lower 7 bits indicate
                                                                 N/128 power reduction. Small values have less throttling and higher
                                                                 performance. 0x0 disables throttling. */
        uint64_t fus118                : 1;  /**< [ 47: 47](RO) Fuse information - Ignore trusted-mode disable.
                                                                 Internal:
                                                                 fuse[99]. */
        uint64_t rom_info              : 10; /**< [ 46: 37](RO) Fuse information - ROM info. */
        uint64_t power_limit           : 2;  /**< [ 36: 35](RO) Fuse information - Power limit. */
        uint64_t dorm_crypto           : 1;  /**< [ 34: 34](RO) Fuse information - Dormant encryption enable. See NOCRYPTO. */
        uint64_t fus318                : 1;  /**< [ 33: 33](RO) Reserved.
                                                                 Internal:
                                                                 Tied to 0. */
        uint64_t raid_en               : 1;  /**< [ 32: 32](RO) Fuse information - RAID enabled. */
        uint64_t reserved_29_31        : 3;
        uint64_t nodfa_cp2             : 1;  /**< [ 28: 28](RO) Fuse information - HFA disable (CP2). */
        uint64_t nomul                 : 1;  /**< [ 27: 27](RO) Fuse information - VMUL disable. */
        uint64_t nocrypto              : 1;  /**< [ 26: 26](RO) Fuse information - [DORM_CRYPTO] and [NOCRYPTO] together select the crypto mode:

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 0: AES/SHA/PMULL enabled.

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 1: The AES, SHA, and PMULL 1D/2D instructions will
                                                                 cause undefined exceptions, and AP_ID_AA64ISAR0_EL1[AES, SHA1, SHA2] are zero
                                                                 indicating this behavior.

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 0: Dormant encryption enable.  AES/SHA/PMULL are
                                                                 disabled (as if [NOCRYPTO] = 1) until the appropriate key is written to
                                                                 RNM_EER_KEY, then they are enabled (as if [NOCRYPTO] = 1).

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 1: Reserved. */
        uint64_t trustzone_en          : 1;  /**< [ 25: 25](RO) Fuse information - TrustZone enable. */
        uint64_t reserved_24           : 1;
        uint64_t chip_id               : 8;  /**< [ 23: 16](RO) Fuse information - chip ID. */
        uint64_t ocx_dis               : 1;  /**< [ 15: 15](RO) Fuse information - OCX disable. */
        uint64_t bgx_dis               : 2;  /**< [ 14: 13](RO) Fuse information - BGX disable:
                                                                   <13> = BGX0 disable.
                                                                   <14> = BGX1 disable. */
        uint64_t sata_dis              : 4;  /**< [ 12:  9](RO) Fuse information - SATA disable:
                                                                   <9> = SATA0-1 disable.
                                                                   <10> = SATA2-3 disable.
                                                                   <11> = SATA4-5 disable.
                                                                   <12> = Reserved. */
        uint64_t pem_dis               : 3;  /**< [  8:  6](RO) Fuse information - PEM disable:
                                                                   <6> = PEM0 disable.
                                                                   <7> = PEM1 disable
                                                                   <8> = PEM2-3 disable. */
        uint64_t lmc_half              : 1;  /**< [  5:  5](RO) Fuse information - LMC1 disabled. */
        uint64_t reserved_0_4          : 5;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_4          : 5;
        uint64_t lmc_half              : 1;  /**< [  5:  5](RO) Fuse information - LMC1 disabled. */
        uint64_t pem_dis               : 3;  /**< [  8:  6](RO) Fuse information - PEM disable:
                                                                   <6> = PEM0 disable.
                                                                   <7> = PEM1 disable
                                                                   <8> = PEM2-3 disable. */
        uint64_t sata_dis              : 4;  /**< [ 12:  9](RO) Fuse information - SATA disable:
                                                                   <9> = SATA0-1 disable.
                                                                   <10> = SATA2-3 disable.
                                                                   <11> = SATA4-5 disable.
                                                                   <12> = Reserved. */
        uint64_t bgx_dis               : 2;  /**< [ 14: 13](RO) Fuse information - BGX disable:
                                                                   <13> = BGX0 disable.
                                                                   <14> = BGX1 disable. */
        uint64_t ocx_dis               : 1;  /**< [ 15: 15](RO) Fuse information - OCX disable. */
        uint64_t chip_id               : 8;  /**< [ 23: 16](RO) Fuse information - chip ID. */
        uint64_t reserved_24           : 1;
        uint64_t trustzone_en          : 1;  /**< [ 25: 25](RO) Fuse information - TrustZone enable. */
        uint64_t nocrypto              : 1;  /**< [ 26: 26](RO) Fuse information - [DORM_CRYPTO] and [NOCRYPTO] together select the crypto mode:

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 0: AES/SHA/PMULL enabled.

                                                                 _ [DORM_CRYPTO] = 0, [NOCRYPTO] = 1: The AES, SHA, and PMULL 1D/2D instructions will
                                                                 cause undefined exceptions, and AP_ID_AA64ISAR0_EL1[AES, SHA1, SHA2] are zero
                                                                 indicating this behavior.

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 0: Dormant encryption enable.  AES/SHA/PMULL are
                                                                 disabled (as if [NOCRYPTO] = 1) until the appropriate key is written to
                                                                 RNM_EER_KEY, then they are enabled (as if [NOCRYPTO] = 1).

                                                                 _ [DORM_CRYPTO] = 1, [NOCRYPTO] = 1: Reserved. */
        uint64_t nomul                 : 1;  /**< [ 27: 27](RO) Fuse information - VMUL disable. */
        uint64_t nodfa_cp2             : 1;  /**< [ 28: 28](RO) Fuse information - HFA disable (CP2). */
        uint64_t reserved_29_31        : 3;
        uint64_t raid_en               : 1;  /**< [ 32: 32](RO) Fuse information - RAID enabled. */
        uint64_t fus318                : 1;  /**< [ 33: 33](RO) Reserved.
                                                                 Internal:
                                                                 Tied to 0. */
        uint64_t dorm_crypto           : 1;  /**< [ 34: 34](RO) Fuse information - Dormant encryption enable. See NOCRYPTO. */
        uint64_t power_limit           : 2;  /**< [ 36: 35](RO) Fuse information - Power limit. */
        uint64_t rom_info              : 10; /**< [ 46: 37](RO) Fuse information - ROM info. */
        uint64_t fus118                : 1;  /**< [ 47: 47](RO) Fuse information - Ignore trusted-mode disable.
                                                                 Internal:
                                                                 fuse[99]. */
        uint64_t gbl_pwr_throttle      : 8;  /**< [ 55: 48](RO) Controls global power throttling. MSB is a spare, and lower 7 bits indicate
                                                                 N/128 power reduction. Small values have less throttling and higher
                                                                 performance. 0x0 disables throttling. */
        uint64_t run_platform          : 3;  /**< [ 58: 56](RO) Fuses to indicate the run platform. Not to be blown in actual hardware.
                                                                 Provides software a means of determining the platform at run time.
                                                                 0x0 = Hardware.
                                                                 0x1 = Emulator.
                                                                 0x2 = RTL simulator.
                                                                 0x3 = ASIM.
                                                                 0x4-0x7 = reserved. */
        uint64_t reserved_59_63        : 5;
#endif /* Word 0 - End */
    } cn83xx;
    /* struct bdk_mio_fus_dat2_s cn88xxp2; */
} bdk_mio_fus_dat2_t;

#define BDK_MIO_FUS_DAT2 BDK_MIO_FUS_DAT2_FUNC()
static inline uint64_t BDK_MIO_FUS_DAT2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_DAT2_FUNC(void)
{
    return 0x87e003001410ll;
}

#define typedef_BDK_MIO_FUS_DAT2 bdk_mio_fus_dat2_t
#define bustype_BDK_MIO_FUS_DAT2 BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_DAT2 "MIO_FUS_DAT2"
#define device_bar_BDK_MIO_FUS_DAT2 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_DAT2 0
#define arguments_BDK_MIO_FUS_DAT2 -1,-1,-1,-1

/**
 * Register (RSL) mio_fus_dat3
 *
 * MIO Fuse Data3 Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_dat3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ema0                  : 6;  /**< [ 63: 58](RO) Fuse information - EMA0.
                                                                 Internal:
                                                                 dflt value is 0x11. Soft or hard blow of these fuses
                                                                 will XOR with this value. */
        uint64_t pll_ctl               : 10; /**< [ 57: 48](RO) Reserved. */
        uint64_t dfa_info_dte          : 3;  /**< [ 47: 45](RO) Fuse information - HFA information (HTE). */
        uint64_t dfa_info_clm          : 4;  /**< [ 44: 41](RO) Fuse information - HFA information (cluster mask). */
        uint64_t pll_alt_matrix        : 1;  /**< [ 40: 40](RO) Select alternate PLL matrix. */
        uint64_t pll_bwadj_denom       : 2;  /**< [ 39: 38](RO) Select CLKF denominator for BWADJ value.
                                                                    0x0 = Selects CLKF/4.
                                                                    0x1 = Selects CLKF/2.
                                                                    0x2 = Selects CLKF/8. */
        uint64_t efus_lck_rsv          : 1;  /**< [ 37: 37](RO) Fuse information - efuse lockdown. */
        uint64_t efus_lck_man          : 1;  /**< [ 36: 36](RO) Fuse information - efuse lockdown. */
        uint64_t pll_half_dis          : 1;  /**< [ 35: 35](RO/H) Fuse information - Coprocessor-clock PLL control. */
        uint64_t l2c_crip              : 3;  /**< [ 34: 32](RO) Fuse information - L2C cripple:
                                                                 0x0 = Full cache (16-way, 2 MB).
                                                                 0x1 = 3/4 ways (12-way, 1.5 MB).
                                                                 0x2 = 1/2 ways (8-way, 1 MB).
                                                                 0x3 = 1/4 ways (4-way, 512 KB).
                                                                 0x4-0x7 = Reserved. */
        uint64_t use_int_refclk        : 1;  /**< [ 31: 31](RO) If set, use the PLL output as the low-jitter reference clock to the rclk DLLs. Default is
                                                                 to use the internal input reference clock. */
        uint64_t zip_info              : 2;  /**< [ 30: 29](RO) Fuse information - Zip information. */
        uint64_t bar2_sz_conf          : 1;  /**< [ 28: 28](RO) Fuse information - When 0, BAR2 size conforms to PCIe specification. */
        uint64_t efus_lck              : 1;  /**< [ 27: 27](RO) Fuse information - efuse lockdown. */
        uint64_t efus_ign              : 1;  /**< [ 26: 26](RO) Fuse information - efuse ignore. */
        uint64_t nozip                 : 1;  /**< [ 25: 25](RO) Fuse information - ZIP disable. */
        uint64_t nodfa_dte             : 1;  /**< [ 24: 24](RO) Fuse information - HFA disable (HTE). */
        uint64_t ema1                  : 6;  /**< [ 23: 18](RO) Fuse information - EMA1.
                                                                 Internal:
                                                                 Default value is 0x02. Soft or hard blow of these fuses
                                                                 will XOR with this value. */
        uint64_t nohna_dte             : 1;  /**< [ 17: 17](RO) Fuse information - HNA disable (DTE). */
        uint64_t hna_info_dte          : 3;  /**< [ 16: 14](RO) Fuse information - HNA information (DTE). */
        uint64_t hna_info_clm          : 4;  /**< [ 13: 10](RO) Fuse information - HNA information (cluster mask). */
        uint64_t tns_cripple           : 1;  /**< [  9:  9](RO) When set to 1, TNS switching functionality is permanently disabled. */
        uint64_t core_pll_mul          : 5;  /**< [  8:  4](RO) Core-clock PLL multiplier hardware limit. Indicates maximum
                                                                 value for PLL_MUL[5:1] straps.  Any strap setting above this
                                                                 value will be ignored.  A value of 0 indicates no hardware limit. */
        uint64_t pnr_pll_mul           : 4;  /**< [  3:  0](RO) Coprocessor-clock PLL multiplier hardware limit.  Indicates maximum
                                                                 value for PNR_MUL[5:1] straps.  Any strap setting above this
                                                                 value will be ignored.  A value of 0 indicates no hardware limit. */
#else /* Word 0 - Little Endian */
        uint64_t pnr_pll_mul           : 4;  /**< [  3:  0](RO) Coprocessor-clock PLL multiplier hardware limit.  Indicates maximum
                                                                 value for PNR_MUL[5:1] straps.  Any strap setting above this
                                                                 value will be ignored.  A value of 0 indicates no hardware limit. */
        uint64_t core_pll_mul          : 5;  /**< [  8:  4](RO) Core-clock PLL multiplier hardware limit. Indicates maximum
                                                                 value for PLL_MUL[5:1] straps.  Any strap setting above this
                                                                 value will be ignored.  A value of 0 indicates no hardware limit. */
        uint64_t tns_cripple           : 1;  /**< [  9:  9](RO) When set to 1, TNS switching functionality is permanently disabled. */
        uint64_t hna_info_clm          : 4;  /**< [ 13: 10](RO) Fuse information - HNA information (cluster mask). */
        uint64_t hna_info_dte          : 3;  /**< [ 16: 14](RO) Fuse information - HNA information (DTE). */
        uint64_t nohna_dte             : 1;  /**< [ 17: 17](RO) Fuse information - HNA disable (DTE). */
        uint64_t ema1                  : 6;  /**< [ 23: 18](RO) Fuse information - EMA1.
                                                                 Internal:
                                                                 Default value is 0x02. Soft or hard blow of these fuses
                                                                 will XOR with this value. */
        uint64_t nodfa_dte             : 1;  /**< [ 24: 24](RO) Fuse information - HFA disable (HTE). */
        uint64_t nozip                 : 1;  /**< [ 25: 25](RO) Fuse information - ZIP disable. */
        uint64_t efus_ign              : 1;  /**< [ 26: 26](RO) Fuse information - efuse ignore. */
        uint64_t efus_lck              : 1;  /**< [ 27: 27](RO) Fuse information - efuse lockdown. */
        uint64_t bar2_sz_conf          : 1;  /**< [ 28: 28](RO) Fuse information - When 0, BAR2 size conforms to PCIe specification. */
        uint64_t zip_info              : 2;  /**< [ 30: 29](RO) Fuse information - Zip information. */
        uint64_t use_int_refclk        : 1;  /**< [ 31: 31](RO) If set, use the PLL output as the low-jitter reference clock to the rclk DLLs. Default is
                                                                 to use the internal input reference clock. */
        uint64_t l2c_crip              : 3;  /**< [ 34: 32](RO) Fuse information - L2C cripple:
                                                                 0x0 = Full cache (16-way, 2 MB).
                                                                 0x1 = 3/4 ways (12-way, 1.5 MB).
                                                                 0x2 = 1/2 ways (8-way, 1 MB).
                                                                 0x3 = 1/4 ways (4-way, 512 KB).
                                                                 0x4-0x7 = Reserved. */
        uint64_t pll_half_dis          : 1;  /**< [ 35: 35](RO/H) Fuse information - Coprocessor-clock PLL control. */
        uint64_t efus_lck_man          : 1;  /**< [ 36: 36](RO) Fuse information - efuse lockdown. */
        uint64_t efus_lck_rsv          : 1;  /**< [ 37: 37](RO) Fuse information - efuse lockdown. */
        uint64_t pll_bwadj_denom       : 2;  /**< [ 39: 38](RO) Select CLKF denominator for BWADJ value.
                                                                    0x0 = Selects CLKF/4.
                                                                    0x1 = Selects CLKF/2.
                                                                    0x2 = Selects CLKF/8. */
        uint64_t pll_alt_matrix        : 1;  /**< [ 40: 40](RO) Select alternate PLL matrix. */
        uint64_t dfa_info_clm          : 4;  /**< [ 44: 41](RO) Fuse information - HFA information (cluster mask). */
        uint64_t dfa_info_dte          : 3;  /**< [ 47: 45](RO) Fuse information - HFA information (HTE). */
        uint64_t pll_ctl               : 10; /**< [ 57: 48](RO) Reserved. */
        uint64_t ema0                  : 6;  /**< [ 63: 58](RO) Fuse information - EMA0.
                                                                 Internal:
                                                                 dflt value is 0x11. Soft or hard blow of these fuses
                                                                 will XOR with this value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_dat3_s cn81xx; */
    struct bdk_mio_fus_dat3_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ema0                  : 6;  /**< [ 63: 58](RO) Fuse information - EMA0.
                                                                 Internal:
                                                                 dflt value is 0x11. Soft or hard blow of these fuses
                                                                 will XOR with this value. */
        uint64_t pll_ctl               : 10; /**< [ 57: 48](RO) Reserved. */
        uint64_t dfa_info_dte          : 3;  /**< [ 47: 45](RO) Fuse information - HFA information (HTE). */
        uint64_t dfa_info_clm          : 4;  /**< [ 44: 41](RO) Fuse information - HFA information (cluster mask). */
        uint64_t pll_alt_matrix        : 1;  /**< [ 40: 40](RO) Select alternate PLL matrix. */
        uint64_t pll_bwadj_denom       : 2;  /**< [ 39: 38](RO) Select CLKF denominator for BWADJ value.
                                                                    0x0 = Selects CLKF/4.
                                                                    0x1 = Selects CLKF/2.
                                                                    0x2 = Selects CLKF/8. */
        uint64_t efus_lck_rsv          : 1;  /**< [ 37: 37](RO) Fuse information - efuse lockdown. */
        uint64_t efus_lck_man          : 1;  /**< [ 36: 36](RO) Fuse information - efuse lockdown. */
        uint64_t pll_half_dis          : 1;  /**< [ 35: 35](RO/H) Fuse information - Coprocessor-clock PLL control. */
        uint64_t l2c_crip              : 3;  /**< [ 34: 32](RO) Fuse information - L2C cripple:
                                                                 0x0 = Full cache (16-way, 16 MB).
                                                                 0x1 = 3/4 ways (12-way, 12 MB).
                                                                 0x2 = 1/2 ways (8-way, 8 MB).
                                                                 0x3 = 1/4 ways (4-way, 4MB).
                                                                 0x4-0x7 = Reserved. */
        uint64_t use_int_refclk        : 1;  /**< [ 31: 31](RO) If set, use the PLL output as the low-jitter reference clock to the rclk DLLs. Default is
                                                                 to use the internal input reference clock. */
        uint64_t zip_info              : 2;  /**< [ 30: 29](RO) Fuse information - Zip information. */
        uint64_t bar2_sz_conf          : 1;  /**< [ 28: 28](RO) Fuse information - When 0, BAR2 size conforms to PCIe specification. */
        uint64_t efus_lck              : 1;  /**< [ 27: 27](RO) Fuse information - efuse lockdown. */
        uint64_t efus_ign              : 1;  /**< [ 26: 26](RO) Fuse information - efuse ignore. */
        uint64_t nozip                 : 1;  /**< [ 25: 25](RO) Fuse information - ZIP disable. */
        uint64_t nodfa_dte             : 1;  /**< [ 24: 24](RO) Fuse information - HFA disable (HTE). */
        uint64_t ema1                  : 6;  /**< [ 23: 18](RO) Fuse information - EMA1.
                                                                 Internal:
                                                                 Default value is 0x02. Soft or hard blow of these fuses
                                                                 will XOR with this value. */
        uint64_t nohna_dte             : 1;  /**< [ 17: 17](RO) Fuse information - HNA disable (DTE). */
        uint64_t hna_info_dte          : 3;  /**< [ 16: 14](RO) Fuse information - HNA information (DTE). */
        uint64_t hna_info_clm          : 4;  /**< [ 13: 10](RO) Fuse information - HNA information (cluster mask). */
        uint64_t tns_cripple           : 1;  /**< [  9:  9](RO) When set to 1, TNS switching functionality is permanently disabled. */
        uint64_t core_pll_mul          : 5;  /**< [  8:  4](RO) Core-clock PLL multiplier hardware limit. Indicates maximum
                                                                 value for PLL_MUL[5:1] straps.  Any strap setting above this
                                                                 value will be ignored.  A value of 0 indicates no hardware limit. */
        uint64_t pnr_pll_mul           : 4;  /**< [  3:  0](RO) Coprocessor-clock PLL multiplier hardware limit.  Indicates maximum
                                                                 value for PNR_MUL[5:1] straps.  Any strap setting above this
                                                                 value will be ignored.  A value of 0 indicates no hardware limit. */
#else /* Word 0 - Little Endian */
        uint64_t pnr_pll_mul           : 4;  /**< [  3:  0](RO) Coprocessor-clock PLL multiplier hardware limit.  Indicates maximum
                                                                 value for PNR_MUL[5:1] straps.  Any strap setting above this
                                                                 value will be ignored.  A value of 0 indicates no hardware limit. */
        uint64_t core_pll_mul          : 5;  /**< [  8:  4](RO) Core-clock PLL multiplier hardware limit. Indicates maximum
                                                                 value for PLL_MUL[5:1] straps.  Any strap setting above this
                                                                 value will be ignored.  A value of 0 indicates no hardware limit. */
        uint64_t tns_cripple           : 1;  /**< [  9:  9](RO) When set to 1, TNS switching functionality is permanently disabled. */
        uint64_t hna_info_clm          : 4;  /**< [ 13: 10](RO) Fuse information - HNA information (cluster mask). */
        uint64_t hna_info_dte          : 3;  /**< [ 16: 14](RO) Fuse information - HNA information (DTE). */
        uint64_t nohna_dte             : 1;  /**< [ 17: 17](RO) Fuse information - HNA disable (DTE). */
        uint64_t ema1                  : 6;  /**< [ 23: 18](RO) Fuse information - EMA1.
                                                                 Internal:
                                                                 Default value is 0x02. Soft or hard blow of these fuses
                                                                 will XOR with this value. */
        uint64_t nodfa_dte             : 1;  /**< [ 24: 24](RO) Fuse information - HFA disable (HTE). */
        uint64_t nozip                 : 1;  /**< [ 25: 25](RO) Fuse information - ZIP disable. */
        uint64_t efus_ign              : 1;  /**< [ 26: 26](RO) Fuse information - efuse ignore. */
        uint64_t efus_lck              : 1;  /**< [ 27: 27](RO) Fuse information - efuse lockdown. */
        uint64_t bar2_sz_conf          : 1;  /**< [ 28: 28](RO) Fuse information - When 0, BAR2 size conforms to PCIe specification. */
        uint64_t zip_info              : 2;  /**< [ 30: 29](RO) Fuse information - Zip information. */
        uint64_t use_int_refclk        : 1;  /**< [ 31: 31](RO) If set, use the PLL output as the low-jitter reference clock to the rclk DLLs. Default is
                                                                 to use the internal input reference clock. */
        uint64_t l2c_crip              : 3;  /**< [ 34: 32](RO) Fuse information - L2C cripple:
                                                                 0x0 = Full cache (16-way, 16 MB).
                                                                 0x1 = 3/4 ways (12-way, 12 MB).
                                                                 0x2 = 1/2 ways (8-way, 8 MB).
                                                                 0x3 = 1/4 ways (4-way, 4MB).
                                                                 0x4-0x7 = Reserved. */
        uint64_t pll_half_dis          : 1;  /**< [ 35: 35](RO/H) Fuse information - Coprocessor-clock PLL control. */
        uint64_t efus_lck_man          : 1;  /**< [ 36: 36](RO) Fuse information - efuse lockdown. */
        uint64_t efus_lck_rsv          : 1;  /**< [ 37: 37](RO) Fuse information - efuse lockdown. */
        uint64_t pll_bwadj_denom       : 2;  /**< [ 39: 38](RO) Select CLKF denominator for BWADJ value.
                                                                    0x0 = Selects CLKF/4.
                                                                    0x1 = Selects CLKF/2.
                                                                    0x2 = Selects CLKF/8. */
        uint64_t pll_alt_matrix        : 1;  /**< [ 40: 40](RO) Select alternate PLL matrix. */
        uint64_t dfa_info_clm          : 4;  /**< [ 44: 41](RO) Fuse information - HFA information (cluster mask). */
        uint64_t dfa_info_dte          : 3;  /**< [ 47: 45](RO) Fuse information - HFA information (HTE). */
        uint64_t pll_ctl               : 10; /**< [ 57: 48](RO) Reserved. */
        uint64_t ema0                  : 6;  /**< [ 63: 58](RO) Fuse information - EMA0.
                                                                 Internal:
                                                                 dflt value is 0x11. Soft or hard blow of these fuses
                                                                 will XOR with this value. */
#endif /* Word 0 - End */
    } cn88xx;
    struct bdk_mio_fus_dat3_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ema0                  : 6;  /**< [ 63: 58](RO) Fuse information - EMA0.
                                                                 Internal:
                                                                 dflt value is 0x11. Soft or hard blow of these fuses
                                                                 will XOR with this value. */
        uint64_t pll_ctl               : 10; /**< [ 57: 48](RO) Reserved. */
        uint64_t dfa_info_dte          : 3;  /**< [ 47: 45](RO) Fuse information - HFA information (HTE). */
        uint64_t dfa_info_clm          : 4;  /**< [ 44: 41](RO) Fuse information - HFA information (cluster mask). */
        uint64_t pll_alt_matrix        : 1;  /**< [ 40: 40](RO) Select alternate PLL matrix. */
        uint64_t pll_bwadj_denom       : 2;  /**< [ 39: 38](RO) Select CLKF denominator for BWADJ value.
                                                                    0x0 = Selects CLKF/4.
                                                                    0x1 = Selects CLKF/2.
                                                                    0x2 = Selects CLKF/8. */
        uint64_t efus_lck_rsv          : 1;  /**< [ 37: 37](RO) Fuse information - efuse lockdown. */
        uint64_t efus_lck_man          : 1;  /**< [ 36: 36](RO) Fuse information - efuse lockdown. */
        uint64_t pll_half_dis          : 1;  /**< [ 35: 35](RO/H) Fuse information - Coprocessor-clock PLL control. */
        uint64_t l2c_crip              : 3;  /**< [ 34: 32](RO) Fuse information - L2C cripple:
                                                                 0x0 = Full cache (16-way, 8 MB).
                                                                 0x1 = 3/4 ways (12-way, 6 MB).
                                                                 0x2 = 1/2 ways (8-way, 4 MB).
                                                                 0x3 = 1/4 ways (4-way, 2 MB).
                                                                 0x4-0x7 = Reserved. */
        uint64_t use_int_refclk        : 1;  /**< [ 31: 31](RO) If set, use the PLL output as the low-jitter reference clock to the rclk DLLs. Default is
                                                                 to use the internal input reference clock. */
        uint64_t zip_info              : 2;  /**< [ 30: 29](RO) Fuse information - Zip information. */
        uint64_t bar2_sz_conf          : 1;  /**< [ 28: 28](RO) Fuse information - When 0, BAR2 size conforms to PCIe specification. */
        uint64_t efus_lck              : 1;  /**< [ 27: 27](RO) Fuse information - efuse lockdown. */
        uint64_t efus_ign              : 1;  /**< [ 26: 26](RO) Fuse information - efuse ignore. */
        uint64_t nozip                 : 1;  /**< [ 25: 25](RO) Fuse information - ZIP disable. */
        uint64_t nodfa_dte             : 1;  /**< [ 24: 24](RO) Fuse information - HFA disable (HTE). */
        uint64_t ema1                  : 6;  /**< [ 23: 18](RO) Fuse information - EMA1.
                                                                 Internal:
                                                                 Default value is 0x02. Soft or hard blow of these fuses
                                                                 will XOR with this value. */
        uint64_t nohna_dte             : 1;  /**< [ 17: 17](RO) Fuse information - HNA disable (DTE). */
        uint64_t hna_info_dte          : 3;  /**< [ 16: 14](RO) Fuse information - HNA information (DTE). */
        uint64_t hna_info_clm          : 4;  /**< [ 13: 10](RO) Fuse information - HNA information (cluster mask). */
        uint64_t tns_cripple           : 1;  /**< [  9:  9](RO) When set to 1, TNS switching functionality is permanently disabled. */
        uint64_t core_pll_mul          : 5;  /**< [  8:  4](RO) Core-clock PLL multiplier hardware limit. Indicates maximum
                                                                 value for PLL_MUL[5:1] straps.  Any strap setting above this
                                                                 value will be ignored.  A value of 0 indicates no hardware limit. */
        uint64_t pnr_pll_mul           : 4;  /**< [  3:  0](RO) Coprocessor-clock PLL multiplier hardware limit.  Indicates maximum
                                                                 value for PNR_MUL[5:1] straps.  Any strap setting above this
                                                                 value will be ignored.  A value of 0 indicates no hardware limit. */
#else /* Word 0 - Little Endian */
        uint64_t pnr_pll_mul           : 4;  /**< [  3:  0](RO) Coprocessor-clock PLL multiplier hardware limit.  Indicates maximum
                                                                 value for PNR_MUL[5:1] straps.  Any strap setting above this
                                                                 value will be ignored.  A value of 0 indicates no hardware limit. */
        uint64_t core_pll_mul          : 5;  /**< [  8:  4](RO) Core-clock PLL multiplier hardware limit. Indicates maximum
                                                                 value for PLL_MUL[5:1] straps.  Any strap setting above this
                                                                 value will be ignored.  A value of 0 indicates no hardware limit. */
        uint64_t tns_cripple           : 1;  /**< [  9:  9](RO) When set to 1, TNS switching functionality is permanently disabled. */
        uint64_t hna_info_clm          : 4;  /**< [ 13: 10](RO) Fuse information - HNA information (cluster mask). */
        uint64_t hna_info_dte          : 3;  /**< [ 16: 14](RO) Fuse information - HNA information (DTE). */
        uint64_t nohna_dte             : 1;  /**< [ 17: 17](RO) Fuse information - HNA disable (DTE). */
        uint64_t ema1                  : 6;  /**< [ 23: 18](RO) Fuse information - EMA1.
                                                                 Internal:
                                                                 Default value is 0x02. Soft or hard blow of these fuses
                                                                 will XOR with this value. */
        uint64_t nodfa_dte             : 1;  /**< [ 24: 24](RO) Fuse information - HFA disable (HTE). */
        uint64_t nozip                 : 1;  /**< [ 25: 25](RO) Fuse information - ZIP disable. */
        uint64_t efus_ign              : 1;  /**< [ 26: 26](RO) Fuse information - efuse ignore. */
        uint64_t efus_lck              : 1;  /**< [ 27: 27](RO) Fuse information - efuse lockdown. */
        uint64_t bar2_sz_conf          : 1;  /**< [ 28: 28](RO) Fuse information - When 0, BAR2 size conforms to PCIe specification. */
        uint64_t zip_info              : 2;  /**< [ 30: 29](RO) Fuse information - Zip information. */
        uint64_t use_int_refclk        : 1;  /**< [ 31: 31](RO) If set, use the PLL output as the low-jitter reference clock to the rclk DLLs. Default is
                                                                 to use the internal input reference clock. */
        uint64_t l2c_crip              : 3;  /**< [ 34: 32](RO) Fuse information - L2C cripple:
                                                                 0x0 = Full cache (16-way, 8 MB).
                                                                 0x1 = 3/4 ways (12-way, 6 MB).
                                                                 0x2 = 1/2 ways (8-way, 4 MB).
                                                                 0x3 = 1/4 ways (4-way, 2 MB).
                                                                 0x4-0x7 = Reserved. */
        uint64_t pll_half_dis          : 1;  /**< [ 35: 35](RO/H) Fuse information - Coprocessor-clock PLL control. */
        uint64_t efus_lck_man          : 1;  /**< [ 36: 36](RO) Fuse information - efuse lockdown. */
        uint64_t efus_lck_rsv          : 1;  /**< [ 37: 37](RO) Fuse information - efuse lockdown. */
        uint64_t pll_bwadj_denom       : 2;  /**< [ 39: 38](RO) Select CLKF denominator for BWADJ value.
                                                                    0x0 = Selects CLKF/4.
                                                                    0x1 = Selects CLKF/2.
                                                                    0x2 = Selects CLKF/8. */
        uint64_t pll_alt_matrix        : 1;  /**< [ 40: 40](RO) Select alternate PLL matrix. */
        uint64_t dfa_info_clm          : 4;  /**< [ 44: 41](RO) Fuse information - HFA information (cluster mask). */
        uint64_t dfa_info_dte          : 3;  /**< [ 47: 45](RO) Fuse information - HFA information (HTE). */
        uint64_t pll_ctl               : 10; /**< [ 57: 48](RO) Reserved. */
        uint64_t ema0                  : 6;  /**< [ 63: 58](RO) Fuse information - EMA0.
                                                                 Internal:
                                                                 dflt value is 0x11. Soft or hard blow of these fuses
                                                                 will XOR with this value. */
#endif /* Word 0 - End */
    } cn83xx;
} bdk_mio_fus_dat3_t;

#define BDK_MIO_FUS_DAT3 BDK_MIO_FUS_DAT3_FUNC()
static inline uint64_t BDK_MIO_FUS_DAT3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_DAT3_FUNC(void)
{
    return 0x87e003001418ll;
}

#define typedef_BDK_MIO_FUS_DAT3 bdk_mio_fus_dat3_t
#define bustype_BDK_MIO_FUS_DAT3 BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_DAT3 "MIO_FUS_DAT3"
#define device_bar_BDK_MIO_FUS_DAT3 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_DAT3 0
#define arguments_BDK_MIO_FUS_DAT3 -1,-1,-1,-1

/**
 * Register (RSL) mio_fus_dat4
 *
 * MIO Fuse Data4 Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_dat4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t global_rclk_byp_select : 1; /**< [ 63: 63](RO) Reserved. */
        uint64_t global_rclk_byp_setting : 11;/**< [ 62: 52](RO) Bits<11:1>. Reserved. */
        uint64_t east_rclk_byp_select  : 1;  /**< [ 51: 51](RO) Reserved. */
        uint64_t east_rclk_byp_setting : 12; /**< [ 50: 39](RO) Reserved. */
        uint64_t cmb_rclk_byp_select   : 1;  /**< [ 38: 38](RO) Reserved. */
        uint64_t cmb_rclk_byp_setting  : 12; /**< [ 37: 26](RO) Reserved. */
        uint64_t pp_rclk_byp_select    : 1;  /**< [ 25: 25](RO) Reserved. */
        uint64_t pp_rclk_byp_setting   : 12; /**< [ 24: 13](RO) Reserved. */
        uint64_t tad_rclk_byp_select   : 1;  /**< [ 12: 12](RO) Reserved. */
        uint64_t tad_rclk_byp_setting  : 12; /**< [ 11:  0](RO) Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t tad_rclk_byp_setting  : 12; /**< [ 11:  0](RO) Reserved. */
        uint64_t tad_rclk_byp_select   : 1;  /**< [ 12: 12](RO) Reserved. */
        uint64_t pp_rclk_byp_setting   : 12; /**< [ 24: 13](RO) Reserved. */
        uint64_t pp_rclk_byp_select    : 1;  /**< [ 25: 25](RO) Reserved. */
        uint64_t cmb_rclk_byp_setting  : 12; /**< [ 37: 26](RO) Reserved. */
        uint64_t cmb_rclk_byp_select   : 1;  /**< [ 38: 38](RO) Reserved. */
        uint64_t east_rclk_byp_setting : 12; /**< [ 50: 39](RO) Reserved. */
        uint64_t east_rclk_byp_select  : 1;  /**< [ 51: 51](RO) Reserved. */
        uint64_t global_rclk_byp_setting : 11;/**< [ 62: 52](RO) Bits<11:1>. Reserved. */
        uint64_t global_rclk_byp_select : 1; /**< [ 63: 63](RO) Reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_dat4_s cn; */
} bdk_mio_fus_dat4_t;

#define BDK_MIO_FUS_DAT4 BDK_MIO_FUS_DAT4_FUNC()
static inline uint64_t BDK_MIO_FUS_DAT4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_DAT4_FUNC(void)
{
    return 0x87e003001420ll;
}

#define typedef_BDK_MIO_FUS_DAT4 bdk_mio_fus_dat4_t
#define bustype_BDK_MIO_FUS_DAT4 BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_DAT4 "MIO_FUS_DAT4"
#define device_bar_BDK_MIO_FUS_DAT4 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_DAT4 0
#define arguments_BDK_MIO_FUS_DAT4 -1,-1,-1,-1

/**
 * Register (RSL) mio_fus_int
 *
 * INTERNAL: MIO Fuse Repair Interrupt Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t rpr_dbe               : 1;  /**< [  1:  1](R/W1C/H) Internal:
                                                                 Indicates an uncorrectable double-bit-error occurred to RPR_MEM. */
        uint64_t rpr_sbe               : 1;  /**< [  0:  0](R/W1C/H) Internal:
                                                                 Indicates a corrected single-bit-error occurred to RPR_MEM. */
#else /* Word 0 - Little Endian */
        uint64_t rpr_sbe               : 1;  /**< [  0:  0](R/W1C/H) Internal:
                                                                 Indicates a corrected single-bit-error occurred to RPR_MEM. */
        uint64_t rpr_dbe               : 1;  /**< [  1:  1](R/W1C/H) Internal:
                                                                 Indicates an uncorrectable double-bit-error occurred to RPR_MEM. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_int_s cn; */
} bdk_mio_fus_int_t;

#define BDK_MIO_FUS_INT BDK_MIO_FUS_INT_FUNC()
static inline uint64_t BDK_MIO_FUS_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_INT_FUNC(void)
{
    return 0x87e003001548ll;
}

#define typedef_BDK_MIO_FUS_INT bdk_mio_fus_int_t
#define bustype_BDK_MIO_FUS_INT BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_INT "MIO_FUS_INT"
#define device_bar_BDK_MIO_FUS_INT 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_INT 0
#define arguments_BDK_MIO_FUS_INT -1,-1,-1,-1

/**
 * Register (RSL) mio_fus_pdf
 *
 * MIO Fuse Product Definition Field Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_pdf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pdf                   : 64; /**< [ 63:  0](RO) Fuse information--product definition field. */
#else /* Word 0 - Little Endian */
        uint64_t pdf                   : 64; /**< [ 63:  0](RO) Fuse information--product definition field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_pdf_s cn; */
} bdk_mio_fus_pdf_t;

#define BDK_MIO_FUS_PDF BDK_MIO_FUS_PDF_FUNC()
static inline uint64_t BDK_MIO_FUS_PDF_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_PDF_FUNC(void)
{
    return 0x87e003001428ll;
}

#define typedef_BDK_MIO_FUS_PDF bdk_mio_fus_pdf_t
#define bustype_BDK_MIO_FUS_PDF BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_PDF "MIO_FUS_PDF"
#define device_bar_BDK_MIO_FUS_PDF 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_PDF 0
#define arguments_BDK_MIO_FUS_PDF -1,-1,-1,-1

/**
 * Register (RSL) mio_fus_pll
 *
 * MIO Fuse PLL Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_pll_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_15_63        : 49;
        uint64_t core_status           : 3;  /**< [ 14: 12](RO) Core-clock PLL status information. */
        uint64_t reserved_11           : 1;
        uint64_t pnr_status            : 3;  /**< [ 10:  8](RO) Coprocessor-clock PLL status information. */
        uint64_t c_cout_rst            : 1;  /**< [  7:  7](R/W) Core clockout postscaler reset. The core clockout postscaler should be placed in reset at
                                                                 least 10 reference-clock cycles prior to changing C_COUT_SEL. The core clockout postscaler
                                                                 should remain under reset for at least 10 reference-clock cycles after C_COUT_SEL changes. */
        uint64_t c_cout_sel            : 2;  /**< [  6:  5](R/W) Core-clock output select:
                                                                 0x0 = Core clock.
                                                                 0x1 = PS output.
                                                                 0x2 = PLL output.
                                                                 0x3 = Undivided core clock. */
        uint64_t pnr_cout_rst          : 1;  /**< [  4:  4](R/W) SYS clockout postscaler reset. The PNR clockout postscaler should be placed in reset at
                                                                 least 10 reference-clock cycles prior to changing PNR_COUT_SEL. The SYS clockout
                                                                 postscaler
                                                                 should remain under reset for at least 10 reference-clock cycles after PNR_COUT_SEL
                                                                 changes. */
        uint64_t pnr_cout_sel          : 2;  /**< [  3:  2](R/W) Coprocessor-clock output select:
                                                                 0x0 = Coprocessor clock.
                                                                 0x1 = PS output.
                                                                 0x2 = PLL output.
                                                                 0x3 = Undivided core clock. */
        uint64_t reserved_0_1          : 2;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_1          : 2;
        uint64_t pnr_cout_sel          : 2;  /**< [  3:  2](R/W) Coprocessor-clock output select:
                                                                 0x0 = Coprocessor clock.
                                                                 0x1 = PS output.
                                                                 0x2 = PLL output.
                                                                 0x3 = Undivided core clock. */
        uint64_t pnr_cout_rst          : 1;  /**< [  4:  4](R/W) SYS clockout postscaler reset. The PNR clockout postscaler should be placed in reset at
                                                                 least 10 reference-clock cycles prior to changing PNR_COUT_SEL. The SYS clockout
                                                                 postscaler
                                                                 should remain under reset for at least 10 reference-clock cycles after PNR_COUT_SEL
                                                                 changes. */
        uint64_t c_cout_sel            : 2;  /**< [  6:  5](R/W) Core-clock output select:
                                                                 0x0 = Core clock.
                                                                 0x1 = PS output.
                                                                 0x2 = PLL output.
                                                                 0x3 = Undivided core clock. */
        uint64_t c_cout_rst            : 1;  /**< [  7:  7](R/W) Core clockout postscaler reset. The core clockout postscaler should be placed in reset at
                                                                 least 10 reference-clock cycles prior to changing C_COUT_SEL. The core clockout postscaler
                                                                 should remain under reset for at least 10 reference-clock cycles after C_COUT_SEL changes. */
        uint64_t pnr_status            : 3;  /**< [ 10:  8](RO) Coprocessor-clock PLL status information. */
        uint64_t reserved_11           : 1;
        uint64_t core_status           : 3;  /**< [ 14: 12](RO) Core-clock PLL status information. */
        uint64_t reserved_15_63        : 49;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_pll_s cn; */
} bdk_mio_fus_pll_t;

#define BDK_MIO_FUS_PLL BDK_MIO_FUS_PLL_FUNC()
static inline uint64_t BDK_MIO_FUS_PLL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_PLL_FUNC(void)
{
    return 0x87e003001580ll;
}

#define typedef_BDK_MIO_FUS_PLL bdk_mio_fus_pll_t
#define bustype_BDK_MIO_FUS_PLL BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_PLL "MIO_FUS_PLL"
#define device_bar_BDK_MIO_FUS_PLL 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_PLL 0
#define arguments_BDK_MIO_FUS_PLL -1,-1,-1,-1

/**
 * Register (RSL) mio_fus_pname#
 *
 * MIO Fuse Product Name Register
 * ""These registers contain a 24-character string representing the part number,
 * e.g. "CN8800-2000BG2601-CPT-PR".
 *
 * The string is represented in a RAD-40-like encoding, padded with trailing spaces
 * that must be removed.  If the resulting string is empty, the product has not been
 * fused programmed and the name should be constructed from e.g. the core's device
 * number.
 *
 * This register was added in pass 2.
 *
 * Pseudocode for the decoding:
 * <pre>
 * datap = data_from_fuses;
 * //      where bit 0 of byte 0 array is fuse 1408;
 * //      i.e. bit 0 of MIO_FUS_PNAME(0)
 * void rad50_decode(const uint8_t* datap, char* bufferp) {
 *    // Psudocode only - assumes datap sized to at least 16 bytes,
 *    // and bufferp to at least 26 characters.
 *    const char* CHAR_MAP = " ABCDEFGHIJKLMNOPQRSTUVWXYZ#.-0123456789";
 *    char* cp = bufferp;
 *    for (int i=0; i<FUSE_BYTES; i+=2) {
 *       // Data is stored little endian
 *       uint16_t data = ((const uint16_t*)datap)[i/2];
 *       ifndef MACHINE_LITTLE_ENDIAN
 *          data = __swab16(data);
 *       endif
 *       *cp++ = CHAR_MAP[(data/40/40) % 40];
 *       *cp++ = CHAR_MAP[(data/40) % 40];
 *       *cp++ = CHAR_MAP[(data) % 40];
 *    }
 *    *cp++ = '\0';
 *    for (cp = bufferp+strlen(bufferp)-1; cp>=bufferp && isspace(*cp); --cp) *cp='\0';
 * }
 * </pre>"
 *
 * Internal:
 * Fuse[1535:1408]."
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_pnamex_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](RO/H) Product name information. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](RO/H) Product name information. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_pnamex_s cn; */
} bdk_mio_fus_pnamex_t;

static inline uint64_t BDK_MIO_FUS_PNAMEX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_PNAMEX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x87e003001440ll + 8ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e003001440ll + 8ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && (a<=1))
        return 0x87e003001440ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("MIO_FUS_PNAMEX", 1, a, 0, 0, 0);
}

#define typedef_BDK_MIO_FUS_PNAMEX(a) bdk_mio_fus_pnamex_t
#define bustype_BDK_MIO_FUS_PNAMEX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_PNAMEX(a) "MIO_FUS_PNAMEX"
#define device_bar_BDK_MIO_FUS_PNAMEX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_PNAMEX(a) (a)
#define arguments_BDK_MIO_FUS_PNAMEX(a) (a),-1,-1,-1

/**
 * Register (RSL) mio_fus_prog
 *
 * INTERNAL: MIO Fuse Programming Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_prog_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t sft                   : 1;  /**< [  1:  1](R/W/H) Internal:
                                                                 When set with PROG, causes only the local storage to change and will not blow
                                                                 any fuses. Hardware will clear when the program operation is complete. */
        uint64_t prog                  : 1;  /**< [  0:  0](R/W/H) Internal:
                                                                 When written to one by software, blow the fuse bank. Hardware will clear when
                                                                 the program operation is complete.
                                                                 To write a bank of fuses, software must set MIO_FUS_WADR[ADDR] to the bank to be
                                                                 programmed and then set each bit within MIO_FUS_BNK_DAT() to indicate which fuses to blow.
                                                                 Once ADDR, and DAT are setup, SW can write to MIO_FUS_PROG[PROG] to start the bank write
                                                                 and poll on PROG. Once PROG is clear, the bank write is complete. A soft blow is still
                                                                 subject to lockdown fuses. After a soft/warm reset, the chip will behave as though the
                                                                 fuses were actually blown. A cold reset restores the actual fuse values. */
#else /* Word 0 - Little Endian */
        uint64_t prog                  : 1;  /**< [  0:  0](R/W/H) Internal:
                                                                 When written to one by software, blow the fuse bank. Hardware will clear when
                                                                 the program operation is complete.
                                                                 To write a bank of fuses, software must set MIO_FUS_WADR[ADDR] to the bank to be
                                                                 programmed and then set each bit within MIO_FUS_BNK_DAT() to indicate which fuses to blow.
                                                                 Once ADDR, and DAT are setup, SW can write to MIO_FUS_PROG[PROG] to start the bank write
                                                                 and poll on PROG. Once PROG is clear, the bank write is complete. A soft blow is still
                                                                 subject to lockdown fuses. After a soft/warm reset, the chip will behave as though the
                                                                 fuses were actually blown. A cold reset restores the actual fuse values. */
        uint64_t sft                   : 1;  /**< [  1:  1](R/W/H) Internal:
                                                                 When set with PROG, causes only the local storage to change and will not blow
                                                                 any fuses. Hardware will clear when the program operation is complete. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_prog_s cn; */
} bdk_mio_fus_prog_t;

#define BDK_MIO_FUS_PROG BDK_MIO_FUS_PROG_FUNC()
static inline uint64_t BDK_MIO_FUS_PROG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_PROG_FUNC(void)
{
    return 0x87e003001510ll;
}

#define typedef_BDK_MIO_FUS_PROG bdk_mio_fus_prog_t
#define bustype_BDK_MIO_FUS_PROG BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_PROG "MIO_FUS_PROG"
#define device_bar_BDK_MIO_FUS_PROG 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_PROG 0
#define arguments_BDK_MIO_FUS_PROG -1,-1,-1,-1

/**
 * Register (RSL) mio_fus_prog_times
 *
 * INTERNAL: MIO Fuse Program Times Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_prog_times_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_35_63        : 29;
        uint64_t vgate_pin             : 1;  /**< [ 34: 34](RO) Internal:
                                                                 Efuse vgate pin (L6G). */
        uint64_t fsrc_pin              : 1;  /**< [ 33: 33](RO) Internal:
                                                                 Efuse fsource pin (L6G). */
        uint64_t prog_pin              : 1;  /**< [ 32: 32](RO) Internal:
                                                                 Efuse program pin (IFB). */
        uint64_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_31         : 32;
        uint64_t prog_pin              : 1;  /**< [ 32: 32](RO) Internal:
                                                                 Efuse program pin (IFB). */
        uint64_t fsrc_pin              : 1;  /**< [ 33: 33](RO) Internal:
                                                                 Efuse fsource pin (L6G). */
        uint64_t vgate_pin             : 1;  /**< [ 34: 34](RO) Internal:
                                                                 Efuse vgate pin (L6G). */
        uint64_t reserved_35_63        : 29;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_prog_times_s cn; */
} bdk_mio_fus_prog_times_t;

#define BDK_MIO_FUS_PROG_TIMES BDK_MIO_FUS_PROG_TIMES_FUNC()
static inline uint64_t BDK_MIO_FUS_PROG_TIMES_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_PROG_TIMES_FUNC(void)
{
    return 0x87e003001518ll;
}

#define typedef_BDK_MIO_FUS_PROG_TIMES bdk_mio_fus_prog_times_t
#define bustype_BDK_MIO_FUS_PROG_TIMES BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_PROG_TIMES "MIO_FUS_PROG_TIMES"
#define device_bar_BDK_MIO_FUS_PROG_TIMES 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_PROG_TIMES 0
#define arguments_BDK_MIO_FUS_PROG_TIMES -1,-1,-1,-1

/**
 * Register (RSL) mio_fus_rcmd
 *
 * MIO Fuse Read Command Register
 * To read an efuse, software writes MIO_FUS_RCMD[ADDR,PEND] with the byte address of the fuse in
 * question, then software can poll MIO_FUS_RCMD[PEND]. When [PEND] = 0, then
 * MIO_FUS_RCMD[DAT] is valid. In addition, if the efuse read went to the efuse banks,
 * software can read MIO_FUS_BNK_DAT() which contains all 128 fuses in the bank associated in
 * ADDR.  Fuses 1023..960 are never accessable on pass 1 parts.
 * In addition, fuses 1023..960 are not accessable if MIO_FUS_DAT2[DORM_CRYPTO] is enabled.
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_rcmd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t dat                   : 8;  /**< [ 23: 16](RO/H) Eight bits of fuse data. */
        uint64_t reserved_13_15        : 3;
        uint64_t pend                  : 1;  /**< [ 12: 12](R/W/H) Software sets this bit to 1 on a write operation that starts FUSE read operation. Hardware
                                                                 clears this bit when the read operation
                                                                 is complete and the DAT is valid. */
        uint64_t reserved_11           : 1;
        uint64_t addr_hi               : 2;  /**< [ 10:  9](R/W) Upper fuse address bits to extend space beyond 2k fuses. Valid range is 0x0-0x3. */
        uint64_t efuse                 : 1;  /**< [  8:  8](R/W) Efuse storage. When set to 1, the return data is from the efuse storage rather than the
                                                                 local storage. */
        uint64_t addr                  : 8;  /**< [  7:  0](R/W) Address. Specifies the byte address of the fuse to read. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 8;  /**< [  7:  0](R/W) Address. Specifies the byte address of the fuse to read. */
        uint64_t efuse                 : 1;  /**< [  8:  8](R/W) Efuse storage. When set to 1, the return data is from the efuse storage rather than the
                                                                 local storage. */
        uint64_t addr_hi               : 2;  /**< [ 10:  9](R/W) Upper fuse address bits to extend space beyond 2k fuses. Valid range is 0x0-0x3. */
        uint64_t reserved_11           : 1;
        uint64_t pend                  : 1;  /**< [ 12: 12](R/W/H) Software sets this bit to 1 on a write operation that starts FUSE read operation. Hardware
                                                                 clears this bit when the read operation
                                                                 is complete and the DAT is valid. */
        uint64_t reserved_13_15        : 3;
        uint64_t dat                   : 8;  /**< [ 23: 16](RO/H) Eight bits of fuse data. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_rcmd_s cn; */
} bdk_mio_fus_rcmd_t;

#define BDK_MIO_FUS_RCMD BDK_MIO_FUS_RCMD_FUNC()
static inline uint64_t BDK_MIO_FUS_RCMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_RCMD_FUNC(void)
{
    return 0x87e003001500ll;
}

#define typedef_BDK_MIO_FUS_RCMD bdk_mio_fus_rcmd_t
#define bustype_BDK_MIO_FUS_RCMD BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_RCMD "MIO_FUS_RCMD"
#define device_bar_BDK_MIO_FUS_RCMD 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_RCMD 0
#define arguments_BDK_MIO_FUS_RCMD -1,-1,-1,-1

/**
 * Register (RSL) mio_fus_read_times
 *
 * MIO Fuse Read Times Register
 * IFB fuses are 0 to 1791. The reset values are for IFB fuses for PLL_REF_CLK up to 100MHz when
 * the core PLL is engaged. If any of the formulas below result in a value less than 0x0, the
 * corresponding timing parameter should be set to 0.
 *
 * Prior to issuing a read operation to the fuse banks (via MIO_FUS_RCMD), this register should
 * be written with the timing parameters that will be read.
 * This register should not be written while MIO_FUS_RCMD[PEND] = 1.
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_read_times_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t done                  : 4;  /**< [ 31: 28](R/W) Hold time of CSB, PGENB, and LOAD with respect to falling edge of STROBE for read and
                                                                 write mode in PLL_REF_CLK + 1 cycles. Timing specs are th_CS = 6ns, th_PG = 10ns, th_LD_p
                                                                 = 7ns. Default of 0x0 yields 20ns for a PLL_REF_CLK of 50 MHz, 10ns at 100MHz. */
        uint64_t ahd                   : 4;  /**< [ 27: 24](R/W) Hold time of A with respect to falling edge of STROBE for read and write modes in
                                                                 PLL_REF_CLK + 2 cycles. Timing spec of tsu_A_r and tsu_A_p is 3ns min. Default of 0x0
                                                                 yields 40ns for a PLL_REF_CLK of 50 MHz, 20ns at 100MHz. */
        uint64_t wrstb_wh              : 12; /**< [ 23: 12](R/W) Pulse width high of STROBE in write mode in PLL_REF_CLK + 1 cycles. Timing spec of
                                                                 twh_SB_p is 9.8us max. Default of 0x1F3 yields 10 us at PLL_REF_CLK of 50 MHz. */
        uint64_t rdstb_wh              : 4;  /**< [ 11:  8](R/W) Pulse width high of STROBE in read mode in PLL_REF_CLK + 1 cycles. Timing spec of twh_SB_p
                                                                 is 20ns min. Default of 0x1 yields 40 ns at PLL_REF_CLK of 50 MHz, 20ns at 100MHz. */
        uint64_t asu                   : 4;  /**< [  7:  4](R/W) Setup time of A to rising edge of STROBE for read and write modes in PLL_REF_CLK cycles.
                                                                 Timing spec of tsu_A_r and tsu_A_p is 12 ns min. Default of 0x1 yields 40 ns at
                                                                 PLL_REF_CLK of 50 MHz, 20ns at 100MHz. */
        uint64_t setup                 : 4;  /**< [  3:  0](R/W) Setup time of CSB, PGENB, LOAD to rising edge of STROBE in read and write modes in
                                                                 PLL_REF_CLK + 1 cycles. tsu_CS = 16ns, tsu_PG = 14ns, tsu_LD_r = 10ns. Default of 0x0
                                                                 yields 20 ns plus ASU cycles at PLL_REF_CLK of 50 MHz, 10ns + ASU at 100MHz. */
#else /* Word 0 - Little Endian */
        uint64_t setup                 : 4;  /**< [  3:  0](R/W) Setup time of CSB, PGENB, LOAD to rising edge of STROBE in read and write modes in
                                                                 PLL_REF_CLK + 1 cycles. tsu_CS = 16ns, tsu_PG = 14ns, tsu_LD_r = 10ns. Default of 0x0
                                                                 yields 20 ns plus ASU cycles at PLL_REF_CLK of 50 MHz, 10ns + ASU at 100MHz. */
        uint64_t asu                   : 4;  /**< [  7:  4](R/W) Setup time of A to rising edge of STROBE for read and write modes in PLL_REF_CLK cycles.
                                                                 Timing spec of tsu_A_r and tsu_A_p is 12 ns min. Default of 0x1 yields 40 ns at
                                                                 PLL_REF_CLK of 50 MHz, 20ns at 100MHz. */
        uint64_t rdstb_wh              : 4;  /**< [ 11:  8](R/W) Pulse width high of STROBE in read mode in PLL_REF_CLK + 1 cycles. Timing spec of twh_SB_p
                                                                 is 20ns min. Default of 0x1 yields 40 ns at PLL_REF_CLK of 50 MHz, 20ns at 100MHz. */
        uint64_t wrstb_wh              : 12; /**< [ 23: 12](R/W) Pulse width high of STROBE in write mode in PLL_REF_CLK + 1 cycles. Timing spec of
                                                                 twh_SB_p is 9.8us max. Default of 0x1F3 yields 10 us at PLL_REF_CLK of 50 MHz. */
        uint64_t ahd                   : 4;  /**< [ 27: 24](R/W) Hold time of A with respect to falling edge of STROBE for read and write modes in
                                                                 PLL_REF_CLK + 2 cycles. Timing spec of tsu_A_r and tsu_A_p is 3ns min. Default of 0x0
                                                                 yields 40ns for a PLL_REF_CLK of 50 MHz, 20ns at 100MHz. */
        uint64_t done                  : 4;  /**< [ 31: 28](R/W) Hold time of CSB, PGENB, and LOAD with respect to falling edge of STROBE for read and
                                                                 write mode in PLL_REF_CLK + 1 cycles. Timing specs are th_CS = 6ns, th_PG = 10ns, th_LD_p
                                                                 = 7ns. Default of 0x0 yields 20ns for a PLL_REF_CLK of 50 MHz, 10ns at 100MHz. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_read_times_s cn; */
} bdk_mio_fus_read_times_t;

#define BDK_MIO_FUS_READ_TIMES BDK_MIO_FUS_READ_TIMES_FUNC()
static inline uint64_t BDK_MIO_FUS_READ_TIMES_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_READ_TIMES_FUNC(void)
{
    return 0x87e003001570ll;
}

#define typedef_BDK_MIO_FUS_READ_TIMES bdk_mio_fus_read_times_t
#define bustype_BDK_MIO_FUS_READ_TIMES BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_READ_TIMES "MIO_FUS_READ_TIMES"
#define device_bar_BDK_MIO_FUS_READ_TIMES 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_READ_TIMES 0
#define arguments_BDK_MIO_FUS_READ_TIMES -1,-1,-1,-1

/**
 * Register (RSL) mio_fus_rpr_dat#
 *
 * INTERNAL: MIO Fuse Repair Memory Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_rpr_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](R/W) Internal:
                                                                 Repair memory store (RPR_MEM). Data for read and write. A write to
                                                                 MIO_FUS_RPR_DAT(1) writes all 128 bits from both registers to RPR_MEM. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](R/W) Internal:
                                                                 Repair memory store (RPR_MEM). Data for read and write. A write to
                                                                 MIO_FUS_RPR_DAT(1) writes all 128 bits from both registers to RPR_MEM. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_rpr_datx_s cn; */
} bdk_mio_fus_rpr_datx_t;

static inline uint64_t BDK_MIO_FUS_RPR_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_RPR_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e003001530ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("MIO_FUS_RPR_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_MIO_FUS_RPR_DATX(a) bdk_mio_fus_rpr_datx_t
#define bustype_BDK_MIO_FUS_RPR_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_RPR_DATX(a) "MIO_FUS_RPR_DATX"
#define device_bar_BDK_MIO_FUS_RPR_DATX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_RPR_DATX(a) (a)
#define arguments_BDK_MIO_FUS_RPR_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) mio_fus_soft_repair
 *
 * INTERNAL: MIO Fuse Soft Repair Register
 *
 * Internal:
 * INTERNAL: Aka `Soft Blow'. Upon reset fuse repairs are loaded into REPAIR_MEM as they are
 * loaded into the memories. Any new defects are loaded in afterwards, leaving END_PTR at the
 * last defect.
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_soft_repair_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t rpr_flip_synd         : 2;  /**< [ 19: 18](R/W/H) Internal:
                                                                 Flip syndrome bits on RPR_MEM writes. For diagnostic use only. */
        uint64_t autoblow              : 1;  /**< [ 17: 17](R/W/H) Internal:
                                                                 Set to initiate burning of defect fuses to fuse macro. Clears when fuses are
                                                                 blown. */
        uint64_t too_many              : 1;  /**< [ 16: 16](RO/H) Internal:
                                                                 Set if the sum of fuse repairs and memory defects exceeds 195. */
        uint64_t numdefects            : 8;  /**< [ 15:  8](RO/H) Internal:
                                                                 After reset/BIST indicates the number of memory defects reported. Defects are
                                                                 stored in REPAIR_MEM from bit address NUMREPAIRS*21 to (NUMREPAIRS*21 + NUMDEFECTS*21 -
                                                                 1). */
        uint64_t numrepairs            : 8;  /**< [  7:  0](R/W) Internal:
                                                                 Indicates the number of soft repairs to load from repair mem to the memories on
                                                                 a soft/warm reset. Indicates the number of repairs loaded from efuses to repair mem on a
                                                                 cold reset. */
#else /* Word 0 - Little Endian */
        uint64_t numrepairs            : 8;  /**< [  7:  0](R/W) Internal:
                                                                 Indicates the number of soft repairs to load from repair mem to the memories on
                                                                 a soft/warm reset. Indicates the number of repairs loaded from efuses to repair mem on a
                                                                 cold reset. */
        uint64_t numdefects            : 8;  /**< [ 15:  8](RO/H) Internal:
                                                                 After reset/BIST indicates the number of memory defects reported. Defects are
                                                                 stored in REPAIR_MEM from bit address NUMREPAIRS*21 to (NUMREPAIRS*21 + NUMDEFECTS*21 -
                                                                 1). */
        uint64_t too_many              : 1;  /**< [ 16: 16](RO/H) Internal:
                                                                 Set if the sum of fuse repairs and memory defects exceeds 195. */
        uint64_t autoblow              : 1;  /**< [ 17: 17](R/W/H) Internal:
                                                                 Set to initiate burning of defect fuses to fuse macro. Clears when fuses are
                                                                 blown. */
        uint64_t rpr_flip_synd         : 2;  /**< [ 19: 18](R/W/H) Internal:
                                                                 Flip syndrome bits on RPR_MEM writes. For diagnostic use only. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_soft_repair_s cn; */
} bdk_mio_fus_soft_repair_t;

#define BDK_MIO_FUS_SOFT_REPAIR BDK_MIO_FUS_SOFT_REPAIR_FUNC()
static inline uint64_t BDK_MIO_FUS_SOFT_REPAIR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_SOFT_REPAIR_FUNC(void)
{
    return 0x87e003001540ll;
}

#define typedef_BDK_MIO_FUS_SOFT_REPAIR bdk_mio_fus_soft_repair_t
#define bustype_BDK_MIO_FUS_SOFT_REPAIR BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_SOFT_REPAIR "MIO_FUS_SOFT_REPAIR"
#define device_bar_BDK_MIO_FUS_SOFT_REPAIR 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_SOFT_REPAIR 0
#define arguments_BDK_MIO_FUS_SOFT_REPAIR -1,-1,-1,-1

/**
 * Register (RSL) mio_fus_tgg
 *
 * MIO Fuse TGG Register
 * This register exists to support Authentik. Authentik code should read this register, then
 * clear VAL to prevent other software from observing the value of the TGG fuses.
 *
 * Internal:
 * INTERNAL: It is never possible to read the TGG fuses via MIO_FUS_RCMD. Whenever the fuse
 * corresponding to VAL (TGG<63>) is blown, it is not possible to blow any of TGG<62:0>. The fuse
 * corresponding to VAL must be the one and only lock down bit for TGG<62:0> - no other fuse
 * lockdown bit can prevent blowing TGG<62:0>. It must always be possible to blow the fuse
 * corresponding to VAL when it is not already blown. If an Authentik part may be converted to a
 * non-Authentik part (via some JTAG mechanism or any other mechanism), it must not be possible
 * to read the TGG fuse values from the Authentik part by performing this conversion -> the reset
 * value of VAL should be zero in this converted case.
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_tgg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t val                   : 1;  /**< [ 63: 63](R/W/H) Software can write VAL to 0, but cannot write VAL to a 1. When VAL = 1, DAT reads
                                                                 the corresponding TGG fuses. When VAL = 0, DAT reads as 0s. The reset value of
                                                                 this VAL bit is normally its fuse setting (i.e. TGG<63>). */
        uint64_t dat                   : 63; /**< [ 62:  0](RO/H) When VAL = 0, DAT always reads as 0x0, regardless of the value of the TGG<62:0>
                                                                 fuses. When VAL = 1, DAT returns the value of the TGG<62:0> fuses. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 63; /**< [ 62:  0](RO/H) When VAL = 0, DAT always reads as 0x0, regardless of the value of the TGG<62:0>
                                                                 fuses. When VAL = 1, DAT returns the value of the TGG<62:0> fuses. */
        uint64_t val                   : 1;  /**< [ 63: 63](R/W/H) Software can write VAL to 0, but cannot write VAL to a 1. When VAL = 1, DAT reads
                                                                 the corresponding TGG fuses. When VAL = 0, DAT reads as 0s. The reset value of
                                                                 this VAL bit is normally its fuse setting (i.e. TGG<63>). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_tgg_s cn; */
} bdk_mio_fus_tgg_t;

#define BDK_MIO_FUS_TGG BDK_MIO_FUS_TGG_FUNC()
static inline uint64_t BDK_MIO_FUS_TGG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_TGG_FUNC(void)
{
    return 0x87e003001430ll;
}

#define typedef_BDK_MIO_FUS_TGG bdk_mio_fus_tgg_t
#define bustype_BDK_MIO_FUS_TGG BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_TGG "MIO_FUS_TGG"
#define device_bar_BDK_MIO_FUS_TGG 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_TGG 0
#define arguments_BDK_MIO_FUS_TGG -1,-1,-1,-1

/**
 * Register (RSL) mio_fus_wadr
 *
 * MIO Fuse Write Address Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_fus_wadr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t addr                  : 6;  /**< [  5:  0](R/W) Indicates which of the banks of 128 fuses to blow. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 6;  /**< [  5:  0](R/W) Indicates which of the banks of 128 fuses to blow. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_fus_wadr_s cn; */
} bdk_mio_fus_wadr_t;

#define BDK_MIO_FUS_WADR BDK_MIO_FUS_WADR_FUNC()
static inline uint64_t BDK_MIO_FUS_WADR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_WADR_FUNC(void)
{
    return 0x87e003001508ll;
}

#define typedef_BDK_MIO_FUS_WADR bdk_mio_fus_wadr_t
#define bustype_BDK_MIO_FUS_WADR BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_FUS_WADR "MIO_FUS_WADR"
#define device_bar_BDK_MIO_FUS_WADR 0x0 /* PF_BAR0 */
#define busnum_BDK_MIO_FUS_WADR 0
#define arguments_BDK_MIO_FUS_WADR -1,-1,-1,-1

#endif /* __BDK_CSRS_MIO_FUS_H__ */
