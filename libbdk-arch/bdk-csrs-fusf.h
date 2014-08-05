#ifndef __BDK_CSRS_FUSF__
#define __BDK_CSRS_FUSF__
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
 * Cavium FUSF.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Bar FUSF_BAR_E
 *
 * Field Fuse Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#ifdef __cplusplus
namespace FUSF_BAR_E {
	const uint64_t FUSF_PF_BAR0 = 0x87e004000000;
	const uint64_t FUSF_PF_BAR0_PCC_BAR_SIZE_BITS = 16;
};
#endif



/**
 * RSL - fusf_bnk_dat#
 *
 * The initial state of FUSF_BNK_DAT() is as if bank15 were just read,
 * i.e. DAT* = fus[2047:1920].
 */
typedef union bdk_fusf_bnk_datx {
	uint64_t u;
	struct bdk_fusf_bnk_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dat                         : 64; /**< SR/W/H - Efuse bank store. For read operations, the DAT gets the fus bank last read. For write
                                                                 operations, the DAT determines which fuses to blow. */
#else
		uint64_t dat                         : 64;
#endif
	} s;
	/* struct bdk_fusf_bnk_datx_s         cn85xx; */
	/* struct bdk_fusf_bnk_datx_s         cn88xx; */
} bdk_fusf_bnk_datx_t;

static inline uint64_t BDK_FUSF_BNK_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_BNK_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E004000120ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_FUSF_BNK_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_FUSF_BNK_DATX(...) bdk_fusf_bnk_datx_t
#define bustype_BDK_FUSF_BNK_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_FUSF_BNK_DATX(p1) (p1)
#define arguments_BDK_FUSF_BNK_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_FUSF_BNK_DATX(...) "FUSF_BNK_DATX"


/**
 * RSL - fusf_ctl
 */
typedef union bdk_fusf_ctl {
	uint64_t u;
	struct bdk_fusf_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rom_t_cnt                   : 32; /**< SRO - ROM trusted counter. One-hot encoding of TBL1FW's TrustedFirmwareNvCounter, number of
                                                                 firmware updates. */
		uint64_t reserved_16_31              : 16;
		uint64_t crypt_ssk_dis               : 1;  /**< SRO - SSK crypt disable.
                                                                 When set, the SSK method of ROM_CSIB_S[CRYPT] is not allowed.
                                                                 If set, FUSF_CTL[CRYPT_NO_DIS] will typically be set, and the device flash
                                                                 is bound to this specific device and a SSK or ROTPK compromise does not
                                                                 unlock this device; however loss of the firmware image without the BSSK
                                                                 stored externally makes this part's secrets inaccessible. */
		uint64_t crypt_no_dis                : 1;  /**< SRO - No-crypt disable.
                                                                 When set, the non-encryption method of ROM_CSIB_S[CRYPT] is not allowed. */
		uint64_t fj_dis_huk                  : 1;  /**< SRO - Flash-jump HUK secret hiding.
                                                                 When set, FUSF_SSK(), FUSF_ROTPK(), FUSF_HUK(), FUSF_EK(),
                                                                 and FUSF_SW() cannot be read unless trusted code authenticates.
                                                                 This fuse is typically set when [ROT_LCK] is set. */
		uint64_t fj_core0                    : 1;  /**< SRO - Flash-jump core 0 only.
                                                                 When set, only core 0 is available unless code authenticates.
                                                                 If set, FUSF_CTL[TZ_FORCE2] must be set. */
		uint64_t fj_timeout                  : 2;  /**< SRO - Flash-jump timeout. When set, limits non-authenticated chip execution time.
                                                                 0x0 = Chipkill disabled.
                                                                 0x1 = Approximately 256 seconds when the coprocessor clock is 800 MHz.
                                                                 Note that this value is recommended by the TBSA.
                                                                 0x2 = Approximately 1 day when the coprocessor clock is 800 MHz.
                                                                 0x3 = Approximately 4 seconds when the coprocessor clock is 800 MHz.

                                                                 If non-zero, FUSF_CTL[TZ_FORCE2] must be set. */
		uint64_t fj_dis                      : 1;  /**< SRO - Flash-jump disable.
                                                                 When set, does not allow any non-trusted NBL1FW code
                                                                 execution, neither because trusted-mode is not requested, nor
                                                                 after an unsuccessful TBL1FW authorization. Instead the chip
                                                                 hangs waiting for a reset. If set, FUSF_CTL[TZ_FORCE2] must also be set.

                                                                 This is high security as the chip cannot be used without
                                                                 authentication, but does not provide a path for updating the flash
                                                                 image unless external board components are capable of doing so.
                                                                 This also might not allow for the device to be completely tested
                                                                 by Cavium, so returns might not be allowed with this fuse set. */
		uint64_t tz_force2                   : 1;  /**< SRO - Trusted-mode force override 2.
                                                                 When set, overrides the trusted-mode strap (GPIO_STRAP<10>) and always requires
                                                                 trusted boot.  If set, and TBL1FW does not authenticate,
                                                                 the boot still falls back to NBL1FW, therefore FUSF_CTL[FJ_DIS]
                                                                 might also want to be set. */
		uint64_t reserved_4_7                : 4;
		uint64_t sw_lck                      : 1;  /**< SRO - Software fuse lockdown.
                                                                 When set, additional programming of FUSF_SW() is not allowed. */
		uint64_t rot_lck                     : 1;  /**< SRO - Root-of-trust fuse lockdown.
                                                                 When set, additional programming of FUSF_ROTPK(), FUSF_HUK(),
                                                                 FUSF_EK() is not allowed.
                                                                 When set, FUSF_CTL[FJ_DIS_HUK] is typically set. */
		uint64_t ssk_lck                     : 1;  /**< SRO - Secret Symmetric Key fuse lockdown.
                                                                 When set, additional programming of FUSF_SSK() is not allowed. */
		uint64_t fusf_lck                    : 1;  /**< SRO - When set, further programming of all of FUSF is disabled. */
#else
		uint64_t fusf_lck                    : 1;
		uint64_t ssk_lck                     : 1;
		uint64_t rot_lck                     : 1;
		uint64_t sw_lck                      : 1;
		uint64_t reserved_4_7                : 4;
		uint64_t tz_force2                   : 1;
		uint64_t fj_dis                      : 1;
		uint64_t fj_timeout                  : 2;
		uint64_t fj_core0                    : 1;
		uint64_t fj_dis_huk                  : 1;
		uint64_t crypt_no_dis                : 1;
		uint64_t crypt_ssk_dis               : 1;
		uint64_t reserved_16_31              : 16;
		uint64_t rom_t_cnt                   : 32;
#endif
	} s;
	/* struct bdk_fusf_ctl_s              cn85xx; */
	/* struct bdk_fusf_ctl_s              cn88xx; */
} bdk_fusf_ctl_t;

#define BDK_FUSF_CTL BDK_FUSF_CTL_FUNC()
static inline uint64_t BDK_FUSF_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_CTL_FUNC(void)
{
	return 0x000087E004000000ull;
}
#define typedef_BDK_FUSF_CTL bdk_fusf_ctl_t
#define bustype_BDK_FUSF_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_FUSF_CTL 0
#define arguments_BDK_FUSF_CTL -1,-1,-1,-1
#define basename_BDK_FUSF_CTL "FUSF_CTL"


/**
 * RSL - fusf_ek#
 */
typedef union bdk_fusf_ekx {
	uint64_t u;
	struct bdk_fusf_ekx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dat                         : 64; /**< SRO - Software assigned EK fuse data, as retrieved from FusesF.

                                                                 EK reads as 0x0 when RST_BOOT[DIS_HUK] is set.
                                                                 EK cannot be reprogrammed when FUSF_CTL[ROT_LCK] is et.

                                                                 This space is opaque to hardware/ROM for use of TBL1FW firmware as required, One
                                                                 such use is as a private endorsement key (EK) or part of such a key.  EK is used
                                                                 by the ROM and later trusted software to prove its trustworthiness to the
                                                                 external world and particularly to the OEM, Enterprise and financial
                                                                 institution.  If so used, EK is only accessible to trusted software, and must be
                                                                 treated as a valuable asset, and the trust-fuse organization should NOT retain a
                                                                 copy of the EK in its device database. */
#else
		uint64_t dat                         : 64;
#endif
	} s;
	/* struct bdk_fusf_ekx_s              cn85xx; */
	/* struct bdk_fusf_ekx_s              cn88xx; */
} bdk_fusf_ekx_t;

static inline uint64_t BDK_FUSF_EKX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_EKX(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0040000A0ull + (param1 & 3) * 0x8ull;
	csr_fatal("BDK_FUSF_EKX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_FUSF_EKX(...) bdk_fusf_ekx_t
#define bustype_BDK_FUSF_EKX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_FUSF_EKX(p1) (p1)
#define arguments_BDK_FUSF_EKX(p1) (p1),-1,-1,-1
#define basename_BDK_FUSF_EKX(...) "FUSF_EKX"


/**
 * RSL - fusf_huk#
 */
typedef union bdk_fusf_hukx {
	uint64_t u;
	struct bdk_fusf_hukx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dat                         : 64; /**< SRO - Hardware unique key (HUK), as retrieved from FusesF.

                                                                 The HUK is used by the ROM and later trusted software for key derivation;
                                                                 such as those keys used for encrypting external storage with AES.

                                                                 HUK is typically programmed at trust-fuse time with a true-random number.
                                                                 Once programmed, FUSF_CTL[ROT_LCK] must also be set as additional
                                                                 programming of this field is not allowed.

                                                                 HUK reads as 0x0 when RST_BOOT[DIS_HUK] is set.
                                                                 HUK is only accessible to trusted software, and must be treated as a valuable asset.

                                                                 The trust-fuse organization should not retain a copy of the HUK in its
                                                                 device database. */
#else
		uint64_t dat                         : 64;
#endif
	} s;
	/* struct bdk_fusf_hukx_s             cn85xx; */
	/* struct bdk_fusf_hukx_s             cn88xx; */
} bdk_fusf_hukx_t;

static inline uint64_t BDK_FUSF_HUKX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_HUKX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E004000090ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_FUSF_HUKX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_FUSF_HUKX(...) bdk_fusf_hukx_t
#define bustype_BDK_FUSF_HUKX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_FUSF_HUKX(p1) (p1)
#define arguments_BDK_FUSF_HUKX(p1) (p1),-1,-1,-1
#define basename_BDK_FUSF_HUKX(...) "FUSF_HUKX"


/**
 * RSL - fusf_prog
 */
typedef union bdk_fusf_prog {
	uint64_t u;
	struct bdk_fusf_prog_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t volt_en                     : 1;  /**< SWO - Enable programming voltage.  Asserts EFUSE_ENABLE_L opep-drain output pin.
                                                                 Made readable in pass 2. */
		uint64_t prog_pin                    : 1;  /**< SRO - Efuse program voltage (EFUS_PROG) is applied.
                                                                 INTERNAL: Indicates state of pi_efuse_pgm_ext not pi_efuse_pgm_int. */
		uint64_t sft                         : 1;  /**< SR/W/H - When set with [PROG], causes only the local storage to change and will not blow
                                                                 any fuses. Hardware will clear when the program operation is complete. */
		uint64_t prog                        : 1;  /**< SR/W/H - When written to 1 by software, blow the fuse bank. Hardware clears this bit when
                                                                 the program operation is complete.

                                                                 To write a bank of fuses, software must set FUSF_WADR[ADDR] to the bank to be
                                                                 programmed and then set each bit within FUSF_BNK_DATX to indicate which fuses to blow.

                                                                 Once FUSF_WADR[ADDR], and DAT are setup, SW can write to FUSF_PROG[PROG] to start the bank
                                                                 write
                                                                 and poll on [PROG]. Once PROG is clear, the bank write is complete. A soft blow is still
                                                                 subject to lockdown fuses. After a soft/warm reset, the chip behaves as though the
                                                                 fuses were actually blown. A cold reset restores the actual fuse values. */
#else
		uint64_t prog                        : 1;
		uint64_t sft                         : 1;
		uint64_t prog_pin                    : 1;
		uint64_t volt_en                     : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_fusf_prog_s             cn85xx; */
	/* struct bdk_fusf_prog_s             cn88xx; */
} bdk_fusf_prog_t;

#define BDK_FUSF_PROG BDK_FUSF_PROG_FUNC()
static inline uint64_t BDK_FUSF_PROG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_PROG_FUNC(void)
{
	return 0x000087E004000110ull;
}
#define typedef_BDK_FUSF_PROG bdk_fusf_prog_t
#define bustype_BDK_FUSF_PROG BDK_CSR_TYPE_RSL
#define busnum_BDK_FUSF_PROG 0
#define arguments_BDK_FUSF_PROG -1,-1,-1,-1
#define basename_BDK_FUSF_PROG "FUSF_PROG"


/**
 * RSL - fusf_rcmd
 *
 * To read an efuse, software writes FUSF_RCMD[ADDR, PEND] with the byte address of
 * the fuse in
 * question, then software can poll FUSF_RCMD[PEND]. When [PEND] is clear and if the efuse read
 * went to the efuse banks (e.g. EFUSE was set on the read), software can read FUSF_BNK_DATx
 * which contains all 128 fuses in the bank associated in ADDR.
 */
typedef union bdk_fusf_rcmd {
	uint64_t u;
	struct bdk_fusf_rcmd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t pend                        : 1;  /**< SR/W/H - Software sets this bit on a write to start FUSE read operation. Hardware clears when read
                                                                 is complete and the DAT is valid. */
		uint64_t reserved_11_11              : 1;
		uint64_t addr_hi                     : 2;  /**< SR/W - Upper fuse address bits to extend space beyond 2k fuses. Valid range is 0x0. */
		uint64_t efuse                       : 1;  /**< SR/W - When set, return data from the efuse storage rather than the local storage. */
		uint64_t addr                        : 8;  /**< SR/W - The byte address of the fuse to read. */
#else
		uint64_t addr                        : 8;
		uint64_t efuse                       : 1;
		uint64_t addr_hi                     : 2;
		uint64_t reserved_11_11              : 1;
		uint64_t pend                        : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_fusf_rcmd_s             cn85xx; */
	/* struct bdk_fusf_rcmd_s             cn88xx; */
} bdk_fusf_rcmd_t;

#define BDK_FUSF_RCMD BDK_FUSF_RCMD_FUNC()
static inline uint64_t BDK_FUSF_RCMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_RCMD_FUNC(void)
{
	return 0x000087E004000100ull;
}
#define typedef_BDK_FUSF_RCMD bdk_fusf_rcmd_t
#define bustype_BDK_FUSF_RCMD BDK_CSR_TYPE_RSL
#define busnum_BDK_FUSF_RCMD 0
#define arguments_BDK_FUSF_RCMD -1,-1,-1,-1
#define basename_BDK_FUSF_RCMD "FUSF_RCMD"


/**
 * RSL - fusf_rotpk#
 */
typedef union bdk_fusf_rotpkx {
	uint64_t u;
	struct bdk_fusf_rotpkx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dat                         : 64; /**< SRO - Root-of-trust public key (ROTPK), as retrieved from FusesF.

                                                                 ROTPK is a AES256 hash of a secp256r1 public key used by the ROM and later
                                                                 trusted software during signature verification to insure a certificate was
                                                                 issued by an authority derived from the root-of-trust's certificate.

                                                                 It is typically burned at trust-fuse time with root-of-trust key hash.
                                                                 Once burned, FUSF_CTL[ROT_LCK] must also be set, as additional
                                                                 programming of this field is not allowed.

                                                                 ROTPK fuse state does not need to be secret; the ROTPK is visible in
                                                                 certificates so is visible to non-trusted software. */
#else
		uint64_t dat                         : 64;
#endif
	} s;
	/* struct bdk_fusf_rotpkx_s           cn85xx; */
	/* struct bdk_fusf_rotpkx_s           cn88xx; */
} bdk_fusf_rotpkx_t;

static inline uint64_t BDK_FUSF_ROTPKX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_ROTPKX(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E004000060ull + (param1 & 3) * 0x8ull;
	csr_fatal("BDK_FUSF_ROTPKX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_FUSF_ROTPKX(...) bdk_fusf_rotpkx_t
#define bustype_BDK_FUSF_ROTPKX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_FUSF_ROTPKX(p1) (p1)
#define arguments_BDK_FUSF_ROTPKX(p1) (p1),-1,-1,-1
#define basename_BDK_FUSF_ROTPKX(...) "FUSF_ROTPKX"


/**
 * RSL - fusf_ssk#
 */
typedef union bdk_fusf_sskx {
	uint64_t u;
	struct bdk_fusf_sskx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dat                         : 64; /**< SRO - Secret symmetric key (SSK), as retrieved from FusesF.

                                                                 SSK is an AES256 key used by the ROM and optionally TBL1FW
                                                                 bootstrapping for decryption of firmware.

                                                                 It is typically programmed at trust-fuse time or later.
                                                                 Once programmed, FUSF_CTL[SSK_LCK] must also be set. */
#else
		uint64_t dat                         : 64;
#endif
	} s;
	/* struct bdk_fusf_sskx_s             cn85xx; */
	/* struct bdk_fusf_sskx_s             cn88xx; */
} bdk_fusf_sskx_t;

static inline uint64_t BDK_FUSF_SSKX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_SSKX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E004000080ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_FUSF_SSKX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_FUSF_SSKX(...) bdk_fusf_sskx_t
#define bustype_BDK_FUSF_SSKX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_FUSF_SSKX(p1) (p1)
#define arguments_BDK_FUSF_SSKX(p1) (p1),-1,-1,-1
#define basename_BDK_FUSF_SSKX(...) "FUSF_SSKX"


/**
 * RSL - fusf_sw#
 */
typedef union bdk_fusf_swx {
	uint64_t u;
	struct bdk_fusf_swx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dat                         : 64; /**< SRO - Software assigned fuse data, as retrieved from FusesF.

                                                                 This space is opaque to hardware/ROM for use of TBL1FW firmware as required.

                                                                 FUSF_SW() reads as 0x0 when RST_BOOT[DIS_HUK] is set.

                                                                 Some uses for this space include:
                                                                   * One-hot encoding of TrustedFirmwareNvCounter <31:0>,
                                                                   number of firmware updates.
                                                                   * One-hot encoding of NonTrustedFirmwareNvCounter <234:0>,
                                                                   number of firmware updates.
                                                                   * Along with FUSF_EK as a private endorsement key (EK). */
#else
		uint64_t dat                         : 64;
#endif
	} s;
	/* struct bdk_fusf_swx_s              cn85xx; */
	/* struct bdk_fusf_swx_s              cn88xx; */
} bdk_fusf_swx_t;

static inline uint64_t BDK_FUSF_SWX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_SWX(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087E0040000C0ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_FUSF_SWX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_FUSF_SWX(...) bdk_fusf_swx_t
#define bustype_BDK_FUSF_SWX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_FUSF_SWX(p1) (p1)
#define arguments_BDK_FUSF_SWX(p1) (p1),-1,-1,-1
#define basename_BDK_FUSF_SWX(...) "FUSF_SWX"


/**
 * RSL - fusf_wadr
 */
typedef union bdk_fusf_wadr {
	uint64_t u;
	struct bdk_fusf_wadr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t addr                        : 4;  /**< SR/W - Indicates which of the banks of 128 fuses to blow. */
#else
		uint64_t addr                        : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_fusf_wadr_s             cn85xx; */
	/* struct bdk_fusf_wadr_s             cn88xx; */
} bdk_fusf_wadr_t;

#define BDK_FUSF_WADR BDK_FUSF_WADR_FUNC()
static inline uint64_t BDK_FUSF_WADR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_FUSF_WADR_FUNC(void)
{
	return 0x000087E004000108ull;
}
#define typedef_BDK_FUSF_WADR bdk_fusf_wadr_t
#define bustype_BDK_FUSF_WADR BDK_CSR_TYPE_RSL
#define busnum_BDK_FUSF_WADR 0
#define arguments_BDK_FUSF_WADR -1,-1,-1,-1
#define basename_BDK_FUSF_WADR "FUSF_WADR"

#endif /* __BDK_CSRS_FUSF__ */
