#ifndef __BDK_CSRS_ROM_H__
#define __BDK_CSRS_ROM_H__
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
 * Cavium ROM.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration rom_crypt_e
 *
 * ROM Crypt Enumeration
 * Enumerates the values of ROM_CSIB_S[CRYPT].
 */
#define BDK_ROM_CRYPT_E_BSSK (2) /**< TBL1FW is encrypted with binding secret symmetric key (BSSK), where BSSK =
                                       AES-D(FUSF_HUK(),
                                       ROM_CSIB_S[FS0..1]).
                                       This allows anti-cloning. */
#define BDK_ROM_CRYPT_E_NONE (0) /**< No encryption of TBL1FW. This is not recommended if ROM_CSIB_S[EXPOSE] is set.
                                       This method is not allowed if FUSF_CTL[CRYPT_NO_DIS] = 1. */
#define BDK_ROM_CRYPT_E_SSK (1) /**< TBL1FW is encrypted with SSK.
                                       This method is not allowed if FUSF_CTL[CRYPT_SSK_DIS] = 1. */

/**
 * Enumeration rom_xfer_msg_e
 *
 * ROM Boot Transfer Message Enumeration
 * Enumerates the messages written to OCX_TLK()_LNK_DATA<15:0> and read from
 * OCX_RLK()_LNK_DATA<15:0> during ROM boot.
 * In these descriptions:
 *   * "Client" refers to the ROM code on the CNXXXX which is booting.
 *   * "Server" refers to the code running on another node which is serving an image
 *     into the client.
 */
#define BDK_ROM_XFER_MSG_E_BOOT_DONE (0x2002) /**< Client is indicating boot process is complete and no additional messages will be sent by
                                       the client ROM code.
                                       Server must respond with SERVER_ACK or SERVER_ERROR. */
#define BDK_ROM_XFER_MSG_E_BOOT_ERROR (0x2001) /**< Client is indicating boot process has an error and no additional messages will be sent by
                                       the client ROM code.
                                       Server must respond with SERVER_ACK or SERVER_ERROR. */
#define BDK_ROM_XFER_MSG_E_BOOT_READX(a) (0x3000 + (a)) /**< Client is requesting boot data block number {a} from the server.
                                       Server must respond with SERVER_ERROR, or:
                                       * Read a 8 KB block corresponding to the specified offset from the flash (or other image).
                                         If the requested block number exceeds the image or flash size, pad with zeros.
                                       * IO write the 8 KB block to the client node address range KEY_MEM(0) ..
                                         KEY_MEM(0)+8KB-1.
                                         Note reads from this IO address are not supported and will return zeros.
                                       * IO write 0xDEDE_DEDE_DEDE_DEDE to the client node address KEY_MEM(0) + 8KB.
                                       * Respond with SERVER_ACK. */
#define BDK_ROM_XFER_MSG_E_BOOT_START (0x2000) /**< Client is requesting boot sequence to start.
                                       Server must respond with SERVER_ACK or SERVER_ERROR. */
#define BDK_ROM_XFER_MSG_E_FAILX(a) (0x4000 + (a)) /**< Client has failed to boot.  The fail code corresponds to RST_BOOT_FAIL_E. */
#define BDK_ROM_XFER_MSG_E_NONE (0) /**< No message. */
#define BDK_ROM_XFER_MSG_E_SERVER_ACK (0x1000) /**< Server response indicating the client's request has been performed successfully. */
#define BDK_ROM_XFER_MSG_E_SERVER_ERROR (0x1001) /**< Server response indicating the client's request had an error and the transfer is aborted.
                                       The client will respond with BOOT_ERROR. */
#define BDK_ROM_XFER_MSG_E_SERVER_RETRY (0x1002) /**< Server response indicating it needs more time.  Client shall reset timeout counters. */

/**
 * Structure rom_clib_s
 *
 * ROM Code Load Information-Block Structure
 * This 256-byte structure is stored in Flash to specify how an image is loaded by the on-chip
 * boot ROM. This structure is neither signed nor encrypted.
 *
 * All fields in this structure are stored in the Flash in little-endian order.
 */
union bdk_rom_clib_s
{
    uint64_t u[32];
    struct bdk_rom_clib_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t magic                 : 64; /**< [ 63:  0] Magic number.  Contains "CVM_CLIB" in ASCII (0x42494c43_5f4d5643)
                                                                 to indicate a valid ROM_CLIB_S structure. */
#else /* Word 0 - Little Endian */
        uint64_t magic                 : 64; /**< [ 63:  0] Magic number.  Contains "CVM_CLIB" in ASCII (0x42494c43_5f4d5643)
                                                                 to indicate a valid ROM_CLIB_S structure. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t ver                   : 8;  /**< [127:120] Version number.  0x0 to indicate first version of this format.
                                                                 Internal:
                                                                 Opaque to ROM, until we have a second version. */
        uint64_t reserved_64_119       : 56;
#else /* Word 1 - Little Endian */
        uint64_t reserved_64_119       : 56;
        uint64_t ver                   : 8;  /**< [127:120] Version number.  0x0 to indicate first version of this format.
                                                                 Internal:
                                                                 Opaque to ROM, until we have a second version. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t offset                : 64; /**< [191:128] Offset address. The flash address for first byte of image.
                                                                 Must be 0x20000 for NBL1FW, 0x50000 for TBL1FW.

                                                                 In NBL1FW, the first 256 bytes are ignored, should be zeros or random data.

                                                                 In TBL1FW, the first 256 bytes of the image should be
                                                                 random data for cypher security.  The first instruction
                                                                 executed will be at [OFFSET] + 0x100.

                                                                 Internal:
                                                                 Future ROM code may allow this to be more flexible.
                                                                 If so, must be aligned to 1 KB. Must be >= 1 KB (past the
                                                                 ROM_CLIB_S and ROM_CSIB_S headers). */
#else /* Word 2 - Little Endian */
        uint64_t offset                : 64; /**< [191:128] Offset address. The flash address for first byte of image.
                                                                 Must be 0x20000 for NBL1FW, 0x50000 for TBL1FW.

                                                                 In NBL1FW, the first 256 bytes are ignored, should be zeros or random data.

                                                                 In TBL1FW, the first 256 bytes of the image should be
                                                                 random data for cypher security.  The first instruction
                                                                 executed will be at [OFFSET] + 0x100.

                                                                 Internal:
                                                                 Future ROM code may allow this to be more flexible.
                                                                 If so, must be aligned to 1 KB. Must be >= 1 KB (past the
                                                                 ROM_CLIB_S and ROM_CSIB_S headers). */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t size                  : 64; /**< [255:192] Size. The size of the TBL1FW material in bytes.  Must be 192 KB (0x30000).
                                                                 Internal:
                                                                 Future ROM code may allow this to be mode flexible.
                                                                 If so, must be in increments of 1 KB.
                                                                 For simulation purposes if MIO_FUS_DAT2[ROM_INFO<5>] is
                                                                 set, there is only 4 KB of NBL1FW and TBL1FW code, at
                                                                 addresses 0x20000 - 0x20FFFF and 0x21000 - 0x21FFFF. */
#else /* Word 3 - Little Endian */
        uint64_t size                  : 64; /**< [255:192] Size. The size of the TBL1FW material in bytes.  Must be 192 KB (0x30000).
                                                                 Internal:
                                                                 Future ROM code may allow this to be mode flexible.
                                                                 If so, must be in increments of 1 KB.
                                                                 For simulation purposes if MIO_FUS_DAT2[ROM_INFO<5>] is
                                                                 set, there is only 4 KB of NBL1FW and TBL1FW code, at
                                                                 addresses 0x20000 - 0x20FFFF and 0x21000 - 0x21FFFF. */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t reserved_256_319      : 64;
#else /* Word 4 - Little Endian */
        uint64_t reserved_256_319      : 64;
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t reserved_320_383      : 64;
#else /* Word 5 - Little Endian */
        uint64_t reserved_320_383      : 64;
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t reserved_384_447      : 64;
#else /* Word 6 - Little Endian */
        uint64_t reserved_384_447      : 64;
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t reserved_448_511      : 64;
#else /* Word 7 - Little Endian */
        uint64_t reserved_448_511      : 64;
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t csib_sign0            : 64; /**< [575:512] CSIB signature, word 0. If this ROM_CLIB_S corresponds to a trusted image, this
                                                                 contains a EC-DSA signature across the 256 bytes of the ROM_CSIB_S. The
                                                                 signature must authenticate against ROM_CSIB_S[ROTPK*] for trusted boot to proceed.
                                                                 These fields are to be interpreted as a pair (R,S) of 256-bit integers in little-endian
                                                                 format. */
#else /* Word 8 - Little Endian */
        uint64_t csib_sign0            : 64; /**< [575:512] CSIB signature, word 0. If this ROM_CLIB_S corresponds to a trusted image, this
                                                                 contains a EC-DSA signature across the 256 bytes of the ROM_CSIB_S. The
                                                                 signature must authenticate against ROM_CSIB_S[ROTPK*] for trusted boot to proceed.
                                                                 These fields are to be interpreted as a pair (R,S) of 256-bit integers in little-endian
                                                                 format. */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t csib_sign1            : 64; /**< [639:576] CSIB signature, word 1. */
#else /* Word 9 - Little Endian */
        uint64_t csib_sign1            : 64; /**< [639:576] CSIB signature, word 1. */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t csib_sign2            : 64; /**< [703:640] CSIB signature, word 2. */
#else /* Word 10 - Little Endian */
        uint64_t csib_sign2            : 64; /**< [703:640] CSIB signature, word 2. */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t csib_sign3            : 64; /**< [767:704] CSIB signature, word 3. */
#else /* Word 11 - Little Endian */
        uint64_t csib_sign3            : 64; /**< [767:704] CSIB signature, word 3. */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t csib_sign4            : 64; /**< [831:768] CSIB signature, word 4. */
#else /* Word 12 - Little Endian */
        uint64_t csib_sign4            : 64; /**< [831:768] CSIB signature, word 4. */
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t csib_sign5            : 64; /**< [895:832] CSIB signature, word 5. */
#else /* Word 13 - Little Endian */
        uint64_t csib_sign5            : 64; /**< [895:832] CSIB signature, word 5. */
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t csib_sign6            : 64; /**< [959:896] CSIB signature, word 6. */
#else /* Word 14 - Little Endian */
        uint64_t csib_sign6            : 64; /**< [959:896] CSIB signature, word 6. */
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t csib_sign7            : 64; /**< [1023:960] CSIB signature, word 7. */
#else /* Word 15 - Little Endian */
        uint64_t csib_sign7            : 64; /**< [1023:960] CSIB signature, word 7. */
#endif /* Word 15 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 16 - Big Endian */
        uint64_t reserved_1024_1087    : 64;
#else /* Word 16 - Little Endian */
        uint64_t reserved_1024_1087    : 64;
#endif /* Word 16 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 17 - Big Endian */
        uint64_t reserved_1088_1151    : 64;
#else /* Word 17 - Little Endian */
        uint64_t reserved_1088_1151    : 64;
#endif /* Word 17 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 18 - Big Endian */
        uint64_t reserved_1152_1215    : 64;
#else /* Word 18 - Little Endian */
        uint64_t reserved_1152_1215    : 64;
#endif /* Word 18 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 19 - Big Endian */
        uint64_t reserved_1216_1279    : 64;
#else /* Word 19 - Little Endian */
        uint64_t reserved_1216_1279    : 64;
#endif /* Word 19 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 20 - Big Endian */
        uint64_t reserved_1280_1343    : 64;
#else /* Word 20 - Little Endian */
        uint64_t reserved_1280_1343    : 64;
#endif /* Word 20 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 21 - Big Endian */
        uint64_t reserved_1344_1407    : 64;
#else /* Word 21 - Little Endian */
        uint64_t reserved_1344_1407    : 64;
#endif /* Word 21 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 22 - Big Endian */
        uint64_t reserved_1408_1471    : 64;
#else /* Word 22 - Little Endian */
        uint64_t reserved_1408_1471    : 64;
#endif /* Word 22 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 23 - Big Endian */
        uint64_t reserved_1472_1535    : 64;
#else /* Word 23 - Little Endian */
        uint64_t reserved_1472_1535    : 64;
#endif /* Word 23 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 24 - Big Endian */
        uint64_t reserved_1536_1599    : 64;
#else /* Word 24 - Little Endian */
        uint64_t reserved_1536_1599    : 64;
#endif /* Word 24 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 25 - Big Endian */
        uint64_t reserved_1600_1663    : 64;
#else /* Word 25 - Little Endian */
        uint64_t reserved_1600_1663    : 64;
#endif /* Word 25 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 26 - Big Endian */
        uint64_t reserved_1664_1727    : 64;
#else /* Word 26 - Little Endian */
        uint64_t reserved_1664_1727    : 64;
#endif /* Word 26 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 27 - Big Endian */
        uint64_t reserved_1728_1791    : 64;
#else /* Word 27 - Little Endian */
        uint64_t reserved_1728_1791    : 64;
#endif /* Word 27 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 28 - Big Endian */
        uint64_t reserved_1792_1855    : 64;
#else /* Word 28 - Little Endian */
        uint64_t reserved_1792_1855    : 64;
#endif /* Word 28 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 29 - Big Endian */
        uint64_t reserved_1856_1919    : 64;
#else /* Word 29 - Little Endian */
        uint64_t reserved_1856_1919    : 64;
#endif /* Word 29 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 30 - Big Endian */
        uint64_t reserved_1920_1983    : 64;
#else /* Word 30 - Little Endian */
        uint64_t reserved_1920_1983    : 64;
#endif /* Word 30 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 31 - Big Endian */
        uint64_t reserved_1984_2047    : 64;
#else /* Word 31 - Little Endian */
        uint64_t reserved_1984_2047    : 64;
#endif /* Word 31 - End */
    } s;
    /* struct bdk_rom_clib_s_s cn; */
};

/**
 * Structure rom_csib_s
 *
 * ROM Code Signature Information-Block Structure
 * All fields in this structure are stored in the Flash in little-endian order.
 */
union bdk_rom_csib_s
{
    uint64_t u[32];
    struct bdk_rom_csib_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t magic                 : 64; /**< [ 63:  0] Magic number.  Contains "CVM_CSIB" in ASCII (0x42495343_5f4d5643)
                                                                 to indicate a valid ROM_CSIB_S structure. */
#else /* Word 0 - Little Endian */
        uint64_t magic                 : 64; /**< [ 63:  0] Magic number.  Contains "CVM_CSIB" in ASCII (0x42495343_5f4d5643)
                                                                 to indicate a valid ROM_CSIB_S structure. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t ver                   : 8;  /**< [127:120] Version number.  0x0 to indicate first version of this format.
                                                                 Internal:
                                                                 Opaque to ROM, until we have a second version. */
        uint64_t nvcnt                 : 8;  /**< [119:112] Trusted firmware NV counter to avoid replay attacks.
                                                                 Compared to population_count(FUSF_CTL[ROM_T_CNT]).  Values > 63 are reserved.

                                                                 Internal:
                                                                 In TBSA this is the TrustedFirmwareNVCounter. */
        uint64_t reserved_72_111       : 40;
        uint64_t expose                : 1;  /**< [ 71: 71] Enable HUK/EK exposure to TBL1FW and later.  This would
                                                                 generally be set for a secure boot.  Non-trusted software
                                                                 can be booted in a similar manner to if trusted-mode = 0 by clearing
                                                                 this bit. */
        uint64_t bkpt                  : 1;  /**< [ 70: 70] ROM code will breakpoint immediately before executing TBL1FW.
                                                                 If set, [SIDEN] must be set.
                                                                 Note breakpoints before this point are not possible due to security reasons. */
        uint64_t reserved_69           : 1;
        uint64_t siden                 : 1;  /**< [ 68: 68] Enable secure external invasive debug during boot.
                                                                 This debug mode is intended only for TBL1FW debug and will
                                                                 break the trust model.  Later debug must use a debug
                                                                 certificate authenticated in TBL1FW as specified in the
                                                                 ARM Trusted Boot System Architecture (TBSA). */
        uint64_t crypt                 : 4;  /**< [ 67: 64] Firmware encryption. Enumerated by ROM_CRYPT_E. */
#else /* Word 1 - Little Endian */
        uint64_t crypt                 : 4;  /**< [ 67: 64] Firmware encryption. Enumerated by ROM_CRYPT_E. */
        uint64_t siden                 : 1;  /**< [ 68: 68] Enable secure external invasive debug during boot.
                                                                 This debug mode is intended only for TBL1FW debug and will
                                                                 break the trust model.  Later debug must use a debug
                                                                 certificate authenticated in TBL1FW as specified in the
                                                                 ARM Trusted Boot System Architecture (TBSA). */
        uint64_t reserved_69           : 1;
        uint64_t bkpt                  : 1;  /**< [ 70: 70] ROM code will breakpoint immediately before executing TBL1FW.
                                                                 If set, [SIDEN] must be set.
                                                                 Note breakpoints before this point are not possible due to security reasons. */
        uint64_t expose                : 1;  /**< [ 71: 71] Enable HUK/EK exposure to TBL1FW and later.  This would
                                                                 generally be set for a secure boot.  Non-trusted software
                                                                 can be booted in a similar manner to if trusted-mode = 0 by clearing
                                                                 this bit. */
        uint64_t reserved_72_111       : 40;
        uint64_t nvcnt                 : 8;  /**< [119:112] Trusted firmware NV counter to avoid replay attacks.
                                                                 Compared to population_count(FUSF_CTL[ROM_T_CNT]).  Values > 63 are reserved.

                                                                 Internal:
                                                                 In TBSA this is the TrustedFirmwareNVCounter. */
        uint64_t ver                   : 8;  /**< [127:120] Version number.  0x0 to indicate first version of this format.
                                                                 Internal:
                                                                 Opaque to ROM, until we have a second version. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_128_191      : 64;
#else /* Word 2 - Little Endian */
        uint64_t reserved_128_191      : 64;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t size                  : 64; /**< [255:192] Size. Indicates the size of the TBL1FW material in bytes.  Must match the value in
                                                                 ROM_CLIB_S[SIZE]. */
#else /* Word 3 - Little Endian */
        uint64_t size                  : 64; /**< [255:192] Size. Indicates the size of the TBL1FW material in bytes.  Must match the value in
                                                                 ROM_CLIB_S[SIZE]. */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t fs0                   : 64; /**< [319:256] TBL1FW image's SHA256 hash.  These fields are to be interpreted
                                                                 as 32 consecutive bytes of the hash in canonical order.
                                                                 ROM boot compares this hash to the hash of the loaded image. */
#else /* Word 4 - Little Endian */
        uint64_t fs0                   : 64; /**< [319:256] TBL1FW image's SHA256 hash.  These fields are to be interpreted
                                                                 as 32 consecutive bytes of the hash in canonical order.
                                                                 ROM boot compares this hash to the hash of the loaded image. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t fs1                   : 64; /**< [383:320] TBL1FW image's SHA256 hash, continued. */
#else /* Word 5 - Little Endian */
        uint64_t fs1                   : 64; /**< [383:320] TBL1FW image's SHA256 hash, continued. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t fs2                   : 64; /**< [447:384] TBL1FW image's SHA256 hash, continued. */
#else /* Word 6 - Little Endian */
        uint64_t fs2                   : 64; /**< [447:384] TBL1FW image's SHA256 hash, continued. */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t fs3                   : 64; /**< [511:448] TBL1FW image's SHA256 hash, continued. */
#else /* Word 7 - Little Endian */
        uint64_t fs3                   : 64; /**< [511:448] TBL1FW image's SHA256 hash, continued. */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t rotpk0                : 64; /**< [575:512] Public key, word 0.
                                                                 An ECDSA-with-SHA256 signature used to validate this certificate.
                                                                 ROM boot compares an AES256 hash of ROTPK0..3 with FUSF_ROTPK().
                                                                 These fields are to be interpreted as a coordinate pair (Qx,Qy)
                                                                 of 256-bit integers in little-endian format. */
#else /* Word 8 - Little Endian */
        uint64_t rotpk0                : 64; /**< [575:512] Public key, word 0.
                                                                 An ECDSA-with-SHA256 signature used to validate this certificate.
                                                                 ROM boot compares an AES256 hash of ROTPK0..3 with FUSF_ROTPK().
                                                                 These fields are to be interpreted as a coordinate pair (Qx,Qy)
                                                                 of 256-bit integers in little-endian format. */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t rotpk1                : 64; /**< [639:576] Public key, word 1. */
#else /* Word 9 - Little Endian */
        uint64_t rotpk1                : 64; /**< [639:576] Public key, word 1. */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t rotpk2                : 64; /**< [703:640] Public key, word 2. */
#else /* Word 10 - Little Endian */
        uint64_t rotpk2                : 64; /**< [703:640] Public key, word 2. */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t rotpk3                : 64; /**< [767:704] Public key, word 3. */
#else /* Word 11 - Little Endian */
        uint64_t rotpk3                : 64; /**< [767:704] Public key, word 3. */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t rotpk4                : 64; /**< [831:768] Public key, word 4. */
#else /* Word 12 - Little Endian */
        uint64_t rotpk4                : 64; /**< [831:768] Public key, word 4. */
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t rotpk5                : 64; /**< [895:832] Public key, word 5. */
#else /* Word 13 - Little Endian */
        uint64_t rotpk5                : 64; /**< [895:832] Public key, word 5. */
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t rotpk6                : 64; /**< [959:896] Public key, word 6. */
#else /* Word 14 - Little Endian */
        uint64_t rotpk6                : 64; /**< [959:896] Public key, word 6. */
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t rotpk7                : 64; /**< [1023:960] Public key, word 7. */
#else /* Word 15 - Little Endian */
        uint64_t rotpk7                : 64; /**< [1023:960] Public key, word 7. */
#endif /* Word 15 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 16 - Big Endian */
        uint64_t sw0                   : 64; /**< [1087:1024] Reserved for software, word 0. Opaque to ROM code. */
#else /* Word 16 - Little Endian */
        uint64_t sw0                   : 64; /**< [1087:1024] Reserved for software, word 0. Opaque to ROM code. */
#endif /* Word 16 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 17 - Big Endian */
        uint64_t sw1                   : 64; /**< [1151:1088] Reserved for software, continued. */
#else /* Word 17 - Little Endian */
        uint64_t sw1                   : 64; /**< [1151:1088] Reserved for software, continued. */
#endif /* Word 17 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 18 - Big Endian */
        uint64_t sw2                   : 64; /**< [1215:1152] Reserved for software, continued. */
#else /* Word 18 - Little Endian */
        uint64_t sw2                   : 64; /**< [1215:1152] Reserved for software, continued. */
#endif /* Word 18 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 19 - Big Endian */
        uint64_t sw3                   : 64; /**< [1279:1216] Reserved for software, continued. */
#else /* Word 19 - Little Endian */
        uint64_t sw3                   : 64; /**< [1279:1216] Reserved for software, continued. */
#endif /* Word 19 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 20 - Big Endian */
        uint64_t sw4                   : 64; /**< [1343:1280] Reserved for software, continued. */
#else /* Word 20 - Little Endian */
        uint64_t sw4                   : 64; /**< [1343:1280] Reserved for software, continued. */
#endif /* Word 20 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 21 - Big Endian */
        uint64_t sw5                   : 64; /**< [1407:1344] Reserved for software, continued. */
#else /* Word 21 - Little Endian */
        uint64_t sw5                   : 64; /**< [1407:1344] Reserved for software, continued. */
#endif /* Word 21 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 22 - Big Endian */
        uint64_t sw6                   : 64; /**< [1471:1408] Reserved for software, continued. */
#else /* Word 22 - Little Endian */
        uint64_t sw6                   : 64; /**< [1471:1408] Reserved for software, continued. */
#endif /* Word 22 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 23 - Big Endian */
        uint64_t sw7                   : 64; /**< [1535:1472] Reserved for software, continued. */
#else /* Word 23 - Little Endian */
        uint64_t sw7                   : 64; /**< [1535:1472] Reserved for software, continued. */
#endif /* Word 23 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 24 - Big Endian */
        uint64_t sw8                   : 64; /**< [1599:1536] Reserved for software, continued. */
#else /* Word 24 - Little Endian */
        uint64_t sw8                   : 64; /**< [1599:1536] Reserved for software, continued. */
#endif /* Word 24 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 25 - Big Endian */
        uint64_t sw9                   : 64; /**< [1663:1600] Reserved for software, continued. */
#else /* Word 25 - Little Endian */
        uint64_t sw9                   : 64; /**< [1663:1600] Reserved for software, continued. */
#endif /* Word 25 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 26 - Big Endian */
        uint64_t uuid0                 : 64; /**< [1727:1664] Reserved for software for use as name/UUID. Opaque to ROM code. */
#else /* Word 26 - Little Endian */
        uint64_t uuid0                 : 64; /**< [1727:1664] Reserved for software for use as name/UUID. Opaque to ROM code. */
#endif /* Word 26 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 27 - Big Endian */
        uint64_t uuid1                 : 64; /**< [1791:1728] Reserved for software for use as name/UUID, continued. */
#else /* Word 27 - Little Endian */
        uint64_t uuid1                 : 64; /**< [1791:1728] Reserved for software for use as name/UUID, continued. */
#endif /* Word 27 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 28 - Big Endian */
        uint64_t nonce0                : 64; /**< [1855:1792] Nonce, word 0.  Opaque to ROM code, for hash hardening.
                                                                 The certificate signer assigns this random nonce to the certificate. */
#else /* Word 28 - Little Endian */
        uint64_t nonce0                : 64; /**< [1855:1792] Nonce, word 0.  Opaque to ROM code, for hash hardening.
                                                                 The certificate signer assigns this random nonce to the certificate. */
#endif /* Word 28 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 29 - Big Endian */
        uint64_t nonce1                : 64; /**< [1919:1856] Nonce, continued. */
#else /* Word 29 - Little Endian */
        uint64_t nonce1                : 64; /**< [1919:1856] Nonce, continued. */
#endif /* Word 29 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 30 - Big Endian */
        uint64_t nonce2                : 64; /**< [1983:1920] Nonce, continued. */
#else /* Word 30 - Little Endian */
        uint64_t nonce2                : 64; /**< [1983:1920] Nonce, continued. */
#endif /* Word 30 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 31 - Big Endian */
        uint64_t nonce3                : 64; /**< [2047:1984] Nonce, continued. */
#else /* Word 31 - Little Endian */
        uint64_t nonce3                : 64; /**< [2047:1984] Nonce, continued. */
#endif /* Word 31 - End */
    } s;
    /* struct bdk_rom_csib_s_s cn; */
};

/**
 * Register (NCB) rom_mem#
 *
 * ROM Internal Boot Memory Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_rom_memx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](RO) Boot-rom data. The maximum address accessible is specified with MIO_BOOT_ROM_LIMIT. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](RO) Boot-rom data. The maximum address accessible is specified with MIO_BOOT_ROM_LIMIT. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rom_memx_s cn; */
} bdk_rom_memx_t;

static inline uint64_t BDK_ROM_MEMX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ROM_MEMX(unsigned long a)
{
    if (a<=2047)
        return 0x87d000000000ll + 8ll * ((a) & 0x7ff);
    __bdk_csr_fatal("ROM_MEMX", 1, a, 0, 0, 0);
}

#define typedef_BDK_ROM_MEMX(a) bdk_rom_memx_t
#define bustype_BDK_ROM_MEMX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ROM_MEMX(a) "ROM_MEMX"
#define busnum_BDK_ROM_MEMX(a) (a)
#define arguments_BDK_ROM_MEMX(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_ROM_H__ */
