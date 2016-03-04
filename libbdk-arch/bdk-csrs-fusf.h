#ifndef __BDK_CSRS_FUSF_H__
#define __BDK_CSRS_FUSF_H__
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
 * Cavium FUSF.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration fusf_bar_e
 *
 * Field Fuse Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_FUSF_BAR_E_FUSF_PF_BAR0 (0x87e004000000ll) /**< Base address for standard registers. */

/**
 * Enumeration fusf_fuse_num_e
 *
 * Field Fuse Fuse Number Enumeration
 * Enumerates the fuse numbers.
 */
#define BDK_FUSF_FUSE_NUM_E_CRYPT_NO_DIS (0xe) /**< FUSF_CTL[CRYPT_NO_DIS]: no-crypt disable. */
#define BDK_FUSF_FUSE_NUM_E_CRYPT_SSK_DIS (0xf) /**< FUSF_CTL[CRYPT_SSK_DIS]: SSK crypt disable. */
#define BDK_FUSF_FUSE_NUM_E_DIS_HUK (0xd) /**< FUSF_CTL[FJ_DIS_HUK]: Flash-jump HUK secret hide. */
#define BDK_FUSF_FUSE_NUM_E_EKX(a) (0x500 + (a)) /**< FUSF_EK(): ECC private endorsement key. */
#define BDK_FUSF_FUSE_NUM_E_FJ_CORE0 (0xc) /**< FUSF_CTL[FJ_CORE0]: Flash-jump core 0 only. */
#define BDK_FUSF_FUSE_NUM_E_FJ_DIS (9) /**< FUSF_CTL[FJ_DIS]: Flash-jump disable. */
#define BDK_FUSF_FUSE_NUM_E_FJ_TIMEOUTX(a) (0xa + (a)) /**< FUSF_CTL[FJ_TIMEOUT]: Flash-jump timeout. */
#define BDK_FUSF_FUSE_NUM_E_FUSF_LCK (0) /**< FUSF_CTL[FUSF_LCK]: Total field fuse lockdown. */
#define BDK_FUSF_FUSE_NUM_E_HUKX(a) (0x480 + (a)) /**< FUSF_HUK(): Hardware unique key. */
#define BDK_FUSF_FUSE_NUM_E_ROM_T_CNTX(a) (0x20 + (a)) /**< FUSF_CTL[ROM_T_CNT]: ROM trusted counter. */
#define BDK_FUSF_FUSE_NUM_E_ROTPKX(a) (0x300 + (a)) /**< FUSF_ROTPK(): Root-of-trust public key. */
#define BDK_FUSF_FUSE_NUM_E_ROT_LCK (2) /**< FUSF_CTL[ROT_LCK]: Root-of-trust fuse lockdown. */
#define BDK_FUSF_FUSE_NUM_E_RSVD128X(a) (0x80 + (a)) /**< Reserved. */
#define BDK_FUSF_FUSE_NUM_E_RSVD16X(a) (0x10 + (a)) /**< Reserved. */
#define BDK_FUSF_FUSE_NUM_E_RSVD256X(a) (0x100 + (a)) /**< Reserved. */
#define BDK_FUSF_FUSE_NUM_E_RSVD4X(a) (4 + (a)) /**< Reserved. */
#define BDK_FUSF_FUSE_NUM_E_RSVD512X(a) (0x200 + (a)) /**< Reserved. */
#define BDK_FUSF_FUSE_NUM_E_RSVD64X(a) (0x40 + (a)) /**< Reserved. */
#define BDK_FUSF_FUSE_NUM_E_SSKX(a) (0x400 + (a)) /**< FUSF_SSK(): Secret symmetric key. */
#define BDK_FUSF_FUSE_NUM_E_SSK_LCK (1) /**< FUSF_CTL[SSK_LCK]: Secret symmetric key fuse lockdown. */
#define BDK_FUSF_FUSE_NUM_E_SWX(a) (0x600 + (a)) /**< FUSF_SW(): Additional secured space. */
#define BDK_FUSF_FUSE_NUM_E_SW_LCK (3) /**< FUSF_CTL[SW_LCK]: Software fuse lockdown. */
#define BDK_FUSF_FUSE_NUM_E_TZ_FORCE2 (8) /**< FUSF_CTL[TZ_FORCE2]: Trustzone force override 2. */

/**
 * Register (RSL) fusf_bnk_dat#
 *
 * Field Fuse Bank Store Register
 * The initial state of FUSF_BNK_DAT() is as if bank15 were just read,
 * i.e. DAT* = fus[2047:1920].
 */
typedef union
{
    uint64_t u;
    struct bdk_fusf_bnk_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SR/W/H) Efuse bank store. For read operations, the DAT gets the fus bank last read. For write
                                                                 operations, the DAT determines which fuses to blow. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SR/W/H) Efuse bank store. For read operations, the DAT gets the fus bank last read. For write
                                                                 operations, the DAT determines which fuses to blow. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_fusf_bnk_datx_s cn; */
} bdk_fusf_bnk_datx_t;

static inline uint64_t BDK_FUSF_BNK_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_BNK_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e004000120ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("FUSF_BNK_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_FUSF_BNK_DATX(a) bdk_fusf_bnk_datx_t
#define bustype_BDK_FUSF_BNK_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_FUSF_BNK_DATX(a) "FUSF_BNK_DATX"
#define device_bar_BDK_FUSF_BNK_DATX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_FUSF_BNK_DATX(a) (a)
#define arguments_BDK_FUSF_BNK_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) fusf_ctl
 *
 * Field Fuse Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_fusf_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t rom_t_cnt             : 32; /**< [ 63: 32](SRO) ROM trusted counter. One-hot encoding of TBL1FW's TrustedFirmwareNvCounter, number of
                                                                 firmware updates. */
        uint64_t reserved_16_31        : 16;
        uint64_t crypt_ssk_dis         : 1;  /**< [ 15: 15](SRO) SSK crypt disable.
                                                                 When set, the SSK method of ROM_CSIB_S[CRYPT] is not allowed.
                                                                 If set, FUSF_CTL[CRYPT_NO_DIS] will typically be set, the device flash
                                                                 is bound to this specific device and a SSK or ROTPK compromise does not
                                                                 unlock this device. The loss of the firmware image without the BSSK
                                                                 stored externally makes this part's secrets inaccessible. */
        uint64_t crypt_no_dis          : 1;  /**< [ 14: 14](SRO) No-crypt disable.
                                                                 When set, the non-encryption method of ROM_CSIB_S[CRYPT] is not allowed. */
        uint64_t fj_dis_huk            : 1;  /**< [ 13: 13](SRO) Flash-jump HUK secret hiding.
                                                                 When set, FUSF_SSK(), FUSF_HUK(), FUSF_EK() and FUSF_SW() cannot be read
                                                                 unless trusted code authenticates.
                                                                 This fuse is typically set when [ROT_LCK] is set. */
        uint64_t fj_core0              : 1;  /**< [ 12: 12](SRO) Flash-jump core 0 only.
                                                                 When set, only core 0 is available unless code authenticates.
                                                                 If set, FUSF_CTL[TZ_FORCE2] must be set. */
        uint64_t fj_timeout            : 2;  /**< [ 11: 10](SRO) Flash-jump timeout. When set, limits non-authenticated chip execution time.
                                                                 0x0 = Chipkill disabled.
                                                                 0x1 = Approximately 256 seconds when the coprocessor clock is 800 MHz.
                                                                 Note that this value is recommended by the TBSA.
                                                                 0x2 = Approximately 1 day when the coprocessor clock is 800 MHz.
                                                                 0x3 = Approximately 4 seconds when the coprocessor clock is 800 MHz.

                                                                 If nonzero, FUSF_CTL[TZ_FORCE2] must be set. */
        uint64_t fj_dis                : 1;  /**< [  9:  9](SRO) Flash-jump disable.
                                                                 When set, does not allow any non-trusted NBL1FW code
                                                                 execution, neither because trusted-mode is not requested, nor
                                                                 after an unsuccessful TBL1FW authorization. Instead the chip
                                                                 hangs waiting for a reset. If set, FUSF_CTL[TZ_FORCE2] must also be set.

                                                                 This is high security as the chip cannot be used without
                                                                 authentication, but does not provide a path for updating the flash
                                                                 image unless external board components are capable of doing so.
                                                                 This also might not allow for the device to be completely tested
                                                                 by Cavium, so returns might not be allowed with this fuse set. */
        uint64_t tz_force2             : 1;  /**< [  8:  8](SRO) Trusted-mode force override 2.
                                                                 When set, overrides the trusted-mode strap (GPIO_STRAP<10>) and always requires
                                                                 trusted boot.  If set, and TBL1FW does not authenticate,
                                                                 the boot still falls back to NBL1FW, therefore FUSF_CTL[FJ_DIS]
                                                                 might also want to be set. */
        uint64_t reserved_4_7          : 4;
        uint64_t sw_lck                : 1;  /**< [  3:  3](SRO) Software fuse lockdown.
                                                                 When set, additional programming of FUSF_SW() is not allowed. */
        uint64_t rot_lck               : 1;  /**< [  2:  2](SRO) Root-of-trust fuse lockdown.
                                                                 When set, additional programming of FUSF_ROTPK(), FUSF_HUK(),
                                                                 FUSF_EK() is not allowed.
                                                                 When set, FUSF_CTL[FJ_DIS_HUK] is typically set. */
        uint64_t ssk_lck               : 1;  /**< [  1:  1](SRO) Secret symmetric key fuse lockdown.
                                                                 When set, additional programming of FUSF_SSK() is not allowed. */
        uint64_t fusf_lck              : 1;  /**< [  0:  0](SRO) When set, further programming of all of FUSF is disabled. */
#else /* Word 0 - Little Endian */
        uint64_t fusf_lck              : 1;  /**< [  0:  0](SRO) When set, further programming of all of FUSF is disabled. */
        uint64_t ssk_lck               : 1;  /**< [  1:  1](SRO) Secret symmetric key fuse lockdown.
                                                                 When set, additional programming of FUSF_SSK() is not allowed. */
        uint64_t rot_lck               : 1;  /**< [  2:  2](SRO) Root-of-trust fuse lockdown.
                                                                 When set, additional programming of FUSF_ROTPK(), FUSF_HUK(),
                                                                 FUSF_EK() is not allowed.
                                                                 When set, FUSF_CTL[FJ_DIS_HUK] is typically set. */
        uint64_t sw_lck                : 1;  /**< [  3:  3](SRO) Software fuse lockdown.
                                                                 When set, additional programming of FUSF_SW() is not allowed. */
        uint64_t reserved_4_7          : 4;
        uint64_t tz_force2             : 1;  /**< [  8:  8](SRO) Trusted-mode force override 2.
                                                                 When set, overrides the trusted-mode strap (GPIO_STRAP<10>) and always requires
                                                                 trusted boot.  If set, and TBL1FW does not authenticate,
                                                                 the boot still falls back to NBL1FW, therefore FUSF_CTL[FJ_DIS]
                                                                 might also want to be set. */
        uint64_t fj_dis                : 1;  /**< [  9:  9](SRO) Flash-jump disable.
                                                                 When set, does not allow any non-trusted NBL1FW code
                                                                 execution, neither because trusted-mode is not requested, nor
                                                                 after an unsuccessful TBL1FW authorization. Instead the chip
                                                                 hangs waiting for a reset. If set, FUSF_CTL[TZ_FORCE2] must also be set.

                                                                 This is high security as the chip cannot be used without
                                                                 authentication, but does not provide a path for updating the flash
                                                                 image unless external board components are capable of doing so.
                                                                 This also might not allow for the device to be completely tested
                                                                 by Cavium, so returns might not be allowed with this fuse set. */
        uint64_t fj_timeout            : 2;  /**< [ 11: 10](SRO) Flash-jump timeout. When set, limits non-authenticated chip execution time.
                                                                 0x0 = Chipkill disabled.
                                                                 0x1 = Approximately 256 seconds when the coprocessor clock is 800 MHz.
                                                                 Note that this value is recommended by the TBSA.
                                                                 0x2 = Approximately 1 day when the coprocessor clock is 800 MHz.
                                                                 0x3 = Approximately 4 seconds when the coprocessor clock is 800 MHz.

                                                                 If nonzero, FUSF_CTL[TZ_FORCE2] must be set. */
        uint64_t fj_core0              : 1;  /**< [ 12: 12](SRO) Flash-jump core 0 only.
                                                                 When set, only core 0 is available unless code authenticates.
                                                                 If set, FUSF_CTL[TZ_FORCE2] must be set. */
        uint64_t fj_dis_huk            : 1;  /**< [ 13: 13](SRO) Flash-jump HUK secret hiding.
                                                                 When set, FUSF_SSK(), FUSF_HUK(), FUSF_EK() and FUSF_SW() cannot be read
                                                                 unless trusted code authenticates.
                                                                 This fuse is typically set when [ROT_LCK] is set. */
        uint64_t crypt_no_dis          : 1;  /**< [ 14: 14](SRO) No-crypt disable.
                                                                 When set, the non-encryption method of ROM_CSIB_S[CRYPT] is not allowed. */
        uint64_t crypt_ssk_dis         : 1;  /**< [ 15: 15](SRO) SSK crypt disable.
                                                                 When set, the SSK method of ROM_CSIB_S[CRYPT] is not allowed.
                                                                 If set, FUSF_CTL[CRYPT_NO_DIS] will typically be set, the device flash
                                                                 is bound to this specific device and a SSK or ROTPK compromise does not
                                                                 unlock this device. The loss of the firmware image without the BSSK
                                                                 stored externally makes this part's secrets inaccessible. */
        uint64_t reserved_16_31        : 16;
        uint64_t rom_t_cnt             : 32; /**< [ 63: 32](SRO) ROM trusted counter. One-hot encoding of TBL1FW's TrustedFirmwareNvCounter, number of
                                                                 firmware updates. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_fusf_ctl_s cn; */
} bdk_fusf_ctl_t;

#define BDK_FUSF_CTL BDK_FUSF_CTL_FUNC()
static inline uint64_t BDK_FUSF_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_CTL_FUNC(void)
{
    return 0x87e004000000ll;
}

#define typedef_BDK_FUSF_CTL bdk_fusf_ctl_t
#define bustype_BDK_FUSF_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_FUSF_CTL "FUSF_CTL"
#define device_bar_BDK_FUSF_CTL 0x0 /* PF_BAR0 */
#define busnum_BDK_FUSF_CTL 0
#define arguments_BDK_FUSF_CTL -1,-1,-1,-1

/**
 * Register (RSL) fusf_ek#
 *
 * Field Fuse ECC Private Endorsement Key Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_fusf_ekx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SRO) Software assigned EK fuse data, as retrieved from FusesF.

                                                                 EK reads as 0x0 when RST_BOOT[DIS_HUK] is set.

                                                                 EK cannot be reprogrammed when FUSF_CTL[ROT_LCK] is et.

                                                                 This space is opaque to hardware/ROM for use of TBL1FW firmware as required, One
                                                                 such use is as a private endorsement key (EK) or part of such a key.  EK is used
                                                                 by the ROM and later trusted software to prove its trustworthiness to the
                                                                 external world and particularly to the OEM, Enterprise and financial
                                                                 institution.  If so used, EK is only accessible to trusted software, and must be
                                                                 treated as a valuable asset, and the trust-fuse organization should NOT retain a
                                                                 copy of the EK in its device database. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SRO) Software assigned EK fuse data, as retrieved from FusesF.

                                                                 EK reads as 0x0 when RST_BOOT[DIS_HUK] is set.

                                                                 EK cannot be reprogrammed when FUSF_CTL[ROT_LCK] is et.

                                                                 This space is opaque to hardware/ROM for use of TBL1FW firmware as required, One
                                                                 such use is as a private endorsement key (EK) or part of such a key.  EK is used
                                                                 by the ROM and later trusted software to prove its trustworthiness to the
                                                                 external world and particularly to the OEM, Enterprise and financial
                                                                 institution.  If so used, EK is only accessible to trusted software, and must be
                                                                 treated as a valuable asset, and the trust-fuse organization should NOT retain a
                                                                 copy of the EK in its device database. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_fusf_ekx_s cn; */
} bdk_fusf_ekx_t;

static inline uint64_t BDK_FUSF_EKX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_EKX(unsigned long a)
{
    if (a<=3)
        return 0x87e0040000a0ll + 8ll * ((a) & 0x3);
    __bdk_csr_fatal("FUSF_EKX", 1, a, 0, 0, 0);
}

#define typedef_BDK_FUSF_EKX(a) bdk_fusf_ekx_t
#define bustype_BDK_FUSF_EKX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_FUSF_EKX(a) "FUSF_EKX"
#define device_bar_BDK_FUSF_EKX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_FUSF_EKX(a) (a)
#define arguments_BDK_FUSF_EKX(a) (a),-1,-1,-1

/**
 * Register (RSL) fusf_huk#
 *
 * Field Fuse Hardware Unique Key Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_fusf_hukx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SRO) Hardware unique key (HUK), as retrieved from FusesF.

                                                                 The HUK is used by the ROM and later trusted software for key derivation;
                                                                 such as those keys used for encrypting external storage with AES.  This register
                                                                 is to be interpreted as 16 consecutive bytes (of an AES key) in canonical order.

                                                                 HUK is typically programmed at trust-fuse time with a true-random number.
                                                                 Once programmed, FUSF_CTL[ROT_LCK] must also be set as additional
                                                                 programming of this field is not allowed.

                                                                 HUK reads as 0x0 when RST_BOOT[DIS_HUK] is set.
                                                                 HUK is only accessible to trusted software, and must be treated as a valuable asset.

                                                                 The trust-fuse organization should not retain a copy of the HUK in its
                                                                 device database. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SRO) Hardware unique key (HUK), as retrieved from FusesF.

                                                                 The HUK is used by the ROM and later trusted software for key derivation;
                                                                 such as those keys used for encrypting external storage with AES.  This register
                                                                 is to be interpreted as 16 consecutive bytes (of an AES key) in canonical order.

                                                                 HUK is typically programmed at trust-fuse time with a true-random number.
                                                                 Once programmed, FUSF_CTL[ROT_LCK] must also be set as additional
                                                                 programming of this field is not allowed.

                                                                 HUK reads as 0x0 when RST_BOOT[DIS_HUK] is set.
                                                                 HUK is only accessible to trusted software, and must be treated as a valuable asset.

                                                                 The trust-fuse organization should not retain a copy of the HUK in its
                                                                 device database. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_fusf_hukx_s cn; */
} bdk_fusf_hukx_t;

static inline uint64_t BDK_FUSF_HUKX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_HUKX(unsigned long a)
{
    if (a<=1)
        return 0x87e004000090ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("FUSF_HUKX", 1, a, 0, 0, 0);
}

#define typedef_BDK_FUSF_HUKX(a) bdk_fusf_hukx_t
#define bustype_BDK_FUSF_HUKX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_FUSF_HUKX(a) "FUSF_HUKX"
#define device_bar_BDK_FUSF_HUKX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_FUSF_HUKX(a) (a)
#define arguments_BDK_FUSF_HUKX(a) (a),-1,-1,-1

/**
 * Register (RSL) fusf_prog
 *
 * Field Fuse Programming Register
 */
typedef union
{
    uint64_t u;
    struct bdk_fusf_prog_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t volt_en               : 1;  /**< [  3:  3](SWO) Enable programming voltage.  Asserts EFUSE_ENABLE_L opep-drain output pin. */
        uint64_t prog_pin              : 1;  /**< [  2:  2](SRO) Efuse program voltage (EFUS_PROG) is applied.
                                                                 Internal:
                                                                 Indicates state of pi_efuse_pgm_ext not pi_efuse_pgm_int. */
        uint64_t sft                   : 1;  /**< [  1:  1](SR/W/H) When set with [PROG], causes only the local storage to change and will not blow
                                                                 any fuses. Hardware will clear when the program operation is complete. */
        uint64_t prog                  : 1;  /**< [  0:  0](SR/W/H) When written to 1 by software, blow the fuse bank. Hardware clears this bit when
                                                                 the program operation is complete.

                                                                 To write a bank of fuses, software must set FUSF_WADR[ADDR] to the bank to be
                                                                 programmed and then set each bit within FUSF_BNK_DATX to indicate which fuses to blow.

                                                                 Once FUSF_WADR[ADDR], and DAT are setup, software can write to FUSF_PROG[PROG]
                                                                 to start the bank write and poll on [PROG]. Once PROG is clear, the bank write
                                                                 is complete.  MIO_FUS_READ_TIMES[WRSTB_WH] set the time for the hardware to
                                                                 clear this bit. A soft blow is still subject to lockdown fuses. After a
                                                                 soft/warm reset, the chip behaves as though the fuses were actually blown. A
                                                                 cold reset restores the actual fuse values. */
#else /* Word 0 - Little Endian */
        uint64_t prog                  : 1;  /**< [  0:  0](SR/W/H) When written to 1 by software, blow the fuse bank. Hardware clears this bit when
                                                                 the program operation is complete.

                                                                 To write a bank of fuses, software must set FUSF_WADR[ADDR] to the bank to be
                                                                 programmed and then set each bit within FUSF_BNK_DATX to indicate which fuses to blow.

                                                                 Once FUSF_WADR[ADDR], and DAT are setup, software can write to FUSF_PROG[PROG]
                                                                 to start the bank write and poll on [PROG]. Once PROG is clear, the bank write
                                                                 is complete.  MIO_FUS_READ_TIMES[WRSTB_WH] set the time for the hardware to
                                                                 clear this bit. A soft blow is still subject to lockdown fuses. After a
                                                                 soft/warm reset, the chip behaves as though the fuses were actually blown. A
                                                                 cold reset restores the actual fuse values. */
        uint64_t sft                   : 1;  /**< [  1:  1](SR/W/H) When set with [PROG], causes only the local storage to change and will not blow
                                                                 any fuses. Hardware will clear when the program operation is complete. */
        uint64_t prog_pin              : 1;  /**< [  2:  2](SRO) Efuse program voltage (EFUS_PROG) is applied.
                                                                 Internal:
                                                                 Indicates state of pi_efuse_pgm_ext not pi_efuse_pgm_int. */
        uint64_t volt_en               : 1;  /**< [  3:  3](SWO) Enable programming voltage.  Asserts EFUSE_ENABLE_L opep-drain output pin. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_fusf_prog_s cn88xxp1; */
    struct bdk_fusf_prog_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t volt_en               : 1;  /**< [  3:  3](SR/W) Enable programming voltage.  Asserts EFUSE_ENABLE_L open-drain output pin. */
        uint64_t prog_pin              : 1;  /**< [  2:  2](SRO) Efuse program voltage (EFUS_PROG) is applied.
                                                                 Internal:
                                                                 Indicates state of pi_efuse_pgm_ext not pi_efuse_pgm_int. */
        uint64_t sft                   : 1;  /**< [  1:  1](SR/W/H) When set with [PROG], causes only the local storage to change and will not blow
                                                                 any fuses. Hardware will clear when the program operation is complete. */
        uint64_t prog                  : 1;  /**< [  0:  0](SR/W/H) When written to 1 by software, blow the fuse bank. Hardware clears this bit when
                                                                 the program operation is complete.

                                                                 To write a bank of fuses, software must set FUSF_WADR[ADDR] to the bank to be
                                                                 programmed and then set each bit within FUSF_BNK_DATX to indicate which fuses to blow.

                                                                 Once FUSF_WADR[ADDR], and DAT are setup, software can write to FUSF_PROG[PROG]
                                                                 to start the bank write and poll on [PROG]. Once PROG is clear, the bank write
                                                                 is complete.  MIO_FUS_READ_TIMES[WRSTB_WH] set the time for the hardware to
                                                                 clear this bit. A soft blow is still subject to lockdown fuses. After a
                                                                 soft/warm reset, the chip behaves as though the fuses were actually blown. A
                                                                 cold reset restores the actual fuse values. */
#else /* Word 0 - Little Endian */
        uint64_t prog                  : 1;  /**< [  0:  0](SR/W/H) When written to 1 by software, blow the fuse bank. Hardware clears this bit when
                                                                 the program operation is complete.

                                                                 To write a bank of fuses, software must set FUSF_WADR[ADDR] to the bank to be
                                                                 programmed and then set each bit within FUSF_BNK_DATX to indicate which fuses to blow.

                                                                 Once FUSF_WADR[ADDR], and DAT are setup, software can write to FUSF_PROG[PROG]
                                                                 to start the bank write and poll on [PROG]. Once PROG is clear, the bank write
                                                                 is complete.  MIO_FUS_READ_TIMES[WRSTB_WH] set the time for the hardware to
                                                                 clear this bit. A soft blow is still subject to lockdown fuses. After a
                                                                 soft/warm reset, the chip behaves as though the fuses were actually blown. A
                                                                 cold reset restores the actual fuse values. */
        uint64_t sft                   : 1;  /**< [  1:  1](SR/W/H) When set with [PROG], causes only the local storage to change and will not blow
                                                                 any fuses. Hardware will clear when the program operation is complete. */
        uint64_t prog_pin              : 1;  /**< [  2:  2](SRO) Efuse program voltage (EFUS_PROG) is applied.
                                                                 Internal:
                                                                 Indicates state of pi_efuse_pgm_ext not pi_efuse_pgm_int. */
        uint64_t volt_en               : 1;  /**< [  3:  3](SR/W) Enable programming voltage.  Asserts EFUSE_ENABLE_L open-drain output pin. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_fusf_prog_cn81xx cn83xx; */
    /* struct bdk_fusf_prog_cn81xx cn88xxp2; */
} bdk_fusf_prog_t;

#define BDK_FUSF_PROG BDK_FUSF_PROG_FUNC()
static inline uint64_t BDK_FUSF_PROG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_PROG_FUNC(void)
{
    return 0x87e004000110ll;
}

#define typedef_BDK_FUSF_PROG bdk_fusf_prog_t
#define bustype_BDK_FUSF_PROG BDK_CSR_TYPE_RSL
#define basename_BDK_FUSF_PROG "FUSF_PROG"
#define device_bar_BDK_FUSF_PROG 0x0 /* PF_BAR0 */
#define busnum_BDK_FUSF_PROG 0
#define arguments_BDK_FUSF_PROG -1,-1,-1,-1

/**
 * Register (RSL) fusf_rcmd
 *
 * Field Fuse Read Command Register
 * To read an efuse, software writes FUSF_RCMD[ADDR, PEND] with the byte address of
 * the fuse in
 * question, then software can poll FUSF_RCMD[PEND]. When [PEND] is clear and if the efuse read
 * went to the efuse banks (e.g. EFUSE was set on the read), software can read FUSF_BNK_DATx
 * which contains all 128 fuses in the bank associated in ADDR.
 */
typedef union
{
    uint64_t u;
    struct bdk_fusf_rcmd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t pend                  : 1;  /**< [ 12: 12](SR/W/H) Software sets this bit on a write to start FUSE read operation.
                                                                 Hardware clears the bit when the read is complete and the DAT is
                                                                 valid.  MIO_FUS_READ_TIMES[RDSTB_WH] determines the time for this
                                                                 operation. */
        uint64_t reserved_11           : 1;
        uint64_t addr_hi               : 2;  /**< [ 10:  9](SR/W) Upper fuse address bits to extend space beyond 2k fuses. Valid range is
                                                                 0x0. Enumerated by FUSF_FUSE_NUM_E<9:8>. */
        uint64_t efuse                 : 1;  /**< [  8:  8](SR/W) When set, return data from the efuse storage rather than the local storage.
                                                                 Software should not change this field while the FUSF_RCMD[PEND] is set.
                                                                 It should wait for the hardware to clear the bit first. */
        uint64_t addr                  : 8;  /**< [  7:  0](SR/W) The byte address of the fuse to read.  Enumerated by FUSF_FUSE_NUM_E<7:0>. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 8;  /**< [  7:  0](SR/W) The byte address of the fuse to read.  Enumerated by FUSF_FUSE_NUM_E<7:0>. */
        uint64_t efuse                 : 1;  /**< [  8:  8](SR/W) When set, return data from the efuse storage rather than the local storage.
                                                                 Software should not change this field while the FUSF_RCMD[PEND] is set.
                                                                 It should wait for the hardware to clear the bit first. */
        uint64_t addr_hi               : 2;  /**< [ 10:  9](SR/W) Upper fuse address bits to extend space beyond 2k fuses. Valid range is
                                                                 0x0. Enumerated by FUSF_FUSE_NUM_E<9:8>. */
        uint64_t reserved_11           : 1;
        uint64_t pend                  : 1;  /**< [ 12: 12](SR/W/H) Software sets this bit on a write to start FUSE read operation.
                                                                 Hardware clears the bit when the read is complete and the DAT is
                                                                 valid.  MIO_FUS_READ_TIMES[RDSTB_WH] determines the time for this
                                                                 operation. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    struct bdk_fusf_rcmd_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t reserved_16_23        : 8;
        uint64_t reserved_13_15        : 3;
        uint64_t pend                  : 1;  /**< [ 12: 12](SR/W/H) Software sets this bit on a write to start FUSE read operation.
                                                                 Hardware clears the bit when the read is complete and the DAT is
                                                                 valid.  MIO_FUS_READ_TIMES[RDSTB_WH] determines the time for this
                                                                 operation. */
        uint64_t reserved_11           : 1;
        uint64_t addr_hi               : 2;  /**< [ 10:  9](SR/W) Upper fuse address bits to extend space beyond 2k fuses. Valid range is
                                                                 0x0. Enumerated by FUSF_FUSE_NUM_E<9:8>. */
        uint64_t efuse                 : 1;  /**< [  8:  8](SR/W) When set, return data from the efuse storage rather than the local storage.
                                                                 Software should not change this field while the FUSF_RCMD[PEND] is set.
                                                                 It should wait for the hardware to clear the bit first. */
        uint64_t addr                  : 8;  /**< [  7:  0](SR/W) The byte address of the fuse to read.  Enumerated by FUSF_FUSE_NUM_E<7:0>. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 8;  /**< [  7:  0](SR/W) The byte address of the fuse to read.  Enumerated by FUSF_FUSE_NUM_E<7:0>. */
        uint64_t efuse                 : 1;  /**< [  8:  8](SR/W) When set, return data from the efuse storage rather than the local storage.
                                                                 Software should not change this field while the FUSF_RCMD[PEND] is set.
                                                                 It should wait for the hardware to clear the bit first. */
        uint64_t addr_hi               : 2;  /**< [ 10:  9](SR/W) Upper fuse address bits to extend space beyond 2k fuses. Valid range is
                                                                 0x0. Enumerated by FUSF_FUSE_NUM_E<9:8>. */
        uint64_t reserved_11           : 1;
        uint64_t pend                  : 1;  /**< [ 12: 12](SR/W/H) Software sets this bit on a write to start FUSE read operation.
                                                                 Hardware clears the bit when the read is complete and the DAT is
                                                                 valid.  MIO_FUS_READ_TIMES[RDSTB_WH] determines the time for this
                                                                 operation. */
        uint64_t reserved_13_15        : 3;
        uint64_t reserved_16_23        : 8;
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn;
} bdk_fusf_rcmd_t;

#define BDK_FUSF_RCMD BDK_FUSF_RCMD_FUNC()
static inline uint64_t BDK_FUSF_RCMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_RCMD_FUNC(void)
{
    return 0x87e004000100ll;
}

#define typedef_BDK_FUSF_RCMD bdk_fusf_rcmd_t
#define bustype_BDK_FUSF_RCMD BDK_CSR_TYPE_RSL
#define basename_BDK_FUSF_RCMD "FUSF_RCMD"
#define device_bar_BDK_FUSF_RCMD 0x0 /* PF_BAR0 */
#define busnum_BDK_FUSF_RCMD 0
#define arguments_BDK_FUSF_RCMD -1,-1,-1,-1

/**
 * Register (RSL) fusf_rotpk#
 *
 * Field Fuse Root-of-Trust Public Key Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_fusf_rotpkx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SRO) Root-of-trust public key (ROTPK), as retrieved from FusesF.

                                                                 ROTPK is the SHA256 hash of the secp256r1 public key used by the ROM (see
                                                                 ROM_CSIB_S[ROTPK0-7])
                                                                 and later trusted software during signature verification to insure a certificate was
                                                                 issued by an authority derived from the root-of-trust's certificate.  This register
                                                                 is to interpreted as the 32 consecutive bytes of the hash in canonical order.

                                                                 It is typically burned at trust-fuse time with root-of-trust key hash.
                                                                 Once burned, FUSF_CTL[ROT_LCK] must also be set, as additional
                                                                 programming of this field is not allowed.

                                                                 ROTPK fuse state does not need to be secret; the ROTPK is visible in
                                                                 certificates so is visible to non-trusted software. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SRO) Root-of-trust public key (ROTPK), as retrieved from FusesF.

                                                                 ROTPK is the SHA256 hash of the secp256r1 public key used by the ROM (see
                                                                 ROM_CSIB_S[ROTPK0-7])
                                                                 and later trusted software during signature verification to insure a certificate was
                                                                 issued by an authority derived from the root-of-trust's certificate.  This register
                                                                 is to interpreted as the 32 consecutive bytes of the hash in canonical order.

                                                                 It is typically burned at trust-fuse time with root-of-trust key hash.
                                                                 Once burned, FUSF_CTL[ROT_LCK] must also be set, as additional
                                                                 programming of this field is not allowed.

                                                                 ROTPK fuse state does not need to be secret; the ROTPK is visible in
                                                                 certificates so is visible to non-trusted software. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_fusf_rotpkx_s cn; */
} bdk_fusf_rotpkx_t;

static inline uint64_t BDK_FUSF_ROTPKX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_ROTPKX(unsigned long a)
{
    if (a<=3)
        return 0x87e004000060ll + 8ll * ((a) & 0x3);
    __bdk_csr_fatal("FUSF_ROTPKX", 1, a, 0, 0, 0);
}

#define typedef_BDK_FUSF_ROTPKX(a) bdk_fusf_rotpkx_t
#define bustype_BDK_FUSF_ROTPKX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_FUSF_ROTPKX(a) "FUSF_ROTPKX"
#define device_bar_BDK_FUSF_ROTPKX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_FUSF_ROTPKX(a) (a)
#define arguments_BDK_FUSF_ROTPKX(a) (a),-1,-1,-1

/**
 * Register (RSL) fusf_ssk#
 *
 * Field Fuse Secret Symmetric Key Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_fusf_sskx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SRO) Secret symmetric key (SSK), as retrieved from FusesF.

                                                                 SSK is the AES256 key used by the ROM and optionally TBL1FW
                                                                 bootstrapping for decryption of firmware.  This register is to be
                                                                 interpreted as 16 consecutive bytes of the key in canonical order.

                                                                 SSK is typically programmed at trust-fuse time or later.
                                                                 Once programmed, FUSF_CTL[SSK_LCK] must also be set.

                                                                 SSK reads as 0x0 when RST_BOOT[DIS_HUK] is set. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SRO) Secret symmetric key (SSK), as retrieved from FusesF.

                                                                 SSK is the AES256 key used by the ROM and optionally TBL1FW
                                                                 bootstrapping for decryption of firmware.  This register is to be
                                                                 interpreted as 16 consecutive bytes of the key in canonical order.

                                                                 SSK is typically programmed at trust-fuse time or later.
                                                                 Once programmed, FUSF_CTL[SSK_LCK] must also be set.

                                                                 SSK reads as 0x0 when RST_BOOT[DIS_HUK] is set. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_fusf_sskx_s cn; */
} bdk_fusf_sskx_t;

static inline uint64_t BDK_FUSF_SSKX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_SSKX(unsigned long a)
{
    if (a<=1)
        return 0x87e004000080ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("FUSF_SSKX", 1, a, 0, 0, 0);
}

#define typedef_BDK_FUSF_SSKX(a) bdk_fusf_sskx_t
#define bustype_BDK_FUSF_SSKX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_FUSF_SSKX(a) "FUSF_SSKX"
#define device_bar_BDK_FUSF_SSKX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_FUSF_SSKX(a) (a)
#define arguments_BDK_FUSF_SSKX(a) (a),-1,-1,-1

/**
 * Register (RSL) fusf_sw#
 *
 * Field Fuse Software Fuses Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_fusf_swx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SRO) Software assigned fuse data, as retrieved from FusesF.

                                                                 This space is opaque to hardware/ROM for use of TBL1FW firmware as required.

                                                                 FUSF_SW() reads as 0x0 when RST_BOOT[DIS_HUK] is set.

                                                                 Some uses for this space include:
                                                                   * One-hot encoding of TrustedFirmwareNvCounter <31:0>,
                                                                   number of firmware updates.
                                                                   * One-hot encoding of NonTrustedFirmwareNvCounter <234:0>,
                                                                   number of firmware updates.
                                                                   * Along with FUSF_EK as a private endorsement key (EK). */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SRO) Software assigned fuse data, as retrieved from FusesF.

                                                                 This space is opaque to hardware/ROM for use of TBL1FW firmware as required.

                                                                 FUSF_SW() reads as 0x0 when RST_BOOT[DIS_HUK] is set.

                                                                 Some uses for this space include:
                                                                   * One-hot encoding of TrustedFirmwareNvCounter <31:0>,
                                                                   number of firmware updates.
                                                                   * One-hot encoding of NonTrustedFirmwareNvCounter <234:0>,
                                                                   number of firmware updates.
                                                                   * Along with FUSF_EK as a private endorsement key (EK). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_fusf_swx_s cn; */
} bdk_fusf_swx_t;

static inline uint64_t BDK_FUSF_SWX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_SWX(unsigned long a)
{
    if (a<=7)
        return 0x87e0040000c0ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("FUSF_SWX", 1, a, 0, 0, 0);
}

#define typedef_BDK_FUSF_SWX(a) bdk_fusf_swx_t
#define bustype_BDK_FUSF_SWX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_FUSF_SWX(a) "FUSF_SWX"
#define device_bar_BDK_FUSF_SWX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_FUSF_SWX(a) (a)
#define arguments_BDK_FUSF_SWX(a) (a),-1,-1,-1

/**
 * Register (RSL) fusf_wadr
 *
 * Field Fuse Write Address Register
 */
typedef union
{
    uint64_t u;
    struct bdk_fusf_wadr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t addr                  : 4;  /**< [  3:  0](SR/W) Indicates which of the banks of 128 fuses to blow.  Enumerated by FUSF_FUSE_NUM_E<10:7>. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 4;  /**< [  3:  0](SR/W) Indicates which of the banks of 128 fuses to blow.  Enumerated by FUSF_FUSE_NUM_E<10:7>. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_fusf_wadr_s cn; */
} bdk_fusf_wadr_t;

#define BDK_FUSF_WADR BDK_FUSF_WADR_FUNC()
static inline uint64_t BDK_FUSF_WADR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_WADR_FUNC(void)
{
    return 0x87e004000108ll;
}

#define typedef_BDK_FUSF_WADR bdk_fusf_wadr_t
#define bustype_BDK_FUSF_WADR BDK_CSR_TYPE_RSL
#define basename_BDK_FUSF_WADR "FUSF_WADR"
#define device_bar_BDK_FUSF_WADR 0x0 /* PF_BAR0 */
#define busnum_BDK_FUSF_WADR 0
#define arguments_BDK_FUSF_WADR -1,-1,-1,-1

#endif /* __BDK_CSRS_FUSF_H__ */
