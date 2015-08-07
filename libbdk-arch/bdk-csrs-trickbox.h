#ifndef __BDK_CSRS_TRICKBOX_H__
#define __BDK_CSRS_TRICKBOX_H__
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
 * Cavium TRICKBOX.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (NCB32b) tb_abort_rgn64_hi1
 *
 * Trickbox AbortRgn64Hi1_Hi Register
 * First 64bit abort region. Note that writes to ABORT_RGN_HI1 actually
 * change this register and zero ABORT_RGN64_HI1_HI.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_abort_rgn64_hi1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_abort_rgn64_hi1_s cn; */
} bdk_tb_abort_rgn64_hi1_t;

#define BDK_TB_ABORT_RGN64_HI1 BDK_TB_ABORT_RGN64_HI1_FUNC()
static inline uint64_t BDK_TB_ABORT_RGN64_HI1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_ABORT_RGN64_HI1_FUNC(void)
{
    return 0x87e013000108ll;
}

#define typedef_BDK_TB_ABORT_RGN64_HI1 bdk_tb_abort_rgn64_hi1_t
#define bustype_BDK_TB_ABORT_RGN64_HI1 BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_ABORT_RGN64_HI1 "TB_ABORT_RGN64_HI1"
#define busnum_BDK_TB_ABORT_RGN64_HI1 0
#define arguments_BDK_TB_ABORT_RGN64_HI1 -1,-1,-1,-1

/**
 * Register (NCB32b) tb_abort_rgn64_hi1_hi
 *
 * Trickbox AbortRgn64Hi1_Hi Register
 * First 64bit abort region. Note that writes to ABORT_RGN_HI1 actually
 * zero this regsiter.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_abort_rgn64_hi1_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_abort_rgn64_hi1_hi_s cn; */
} bdk_tb_abort_rgn64_hi1_hi_t;

#define BDK_TB_ABORT_RGN64_HI1_HI BDK_TB_ABORT_RGN64_HI1_HI_FUNC()
static inline uint64_t BDK_TB_ABORT_RGN64_HI1_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_ABORT_RGN64_HI1_HI_FUNC(void)
{
    return 0x87e01300010cll;
}

#define typedef_BDK_TB_ABORT_RGN64_HI1_HI bdk_tb_abort_rgn64_hi1_hi_t
#define bustype_BDK_TB_ABORT_RGN64_HI1_HI BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_ABORT_RGN64_HI1_HI "TB_ABORT_RGN64_HI1_HI"
#define busnum_BDK_TB_ABORT_RGN64_HI1_HI 0
#define arguments_BDK_TB_ABORT_RGN64_HI1_HI -1,-1,-1,-1

/**
 * Register (NCB32b) tb_abort_rgn64_hi2
 *
 * Trickbox AbortRgn64Hi2_Hi Register
 * Second 64bit abort region. Note that writes to ABORT_RGN_HI2 actually
 * change this register and zero ABORT_RGN64_HI2_HI.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_abort_rgn64_hi2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_abort_rgn64_hi2_s cn; */
} bdk_tb_abort_rgn64_hi2_t;

#define BDK_TB_ABORT_RGN64_HI2 BDK_TB_ABORT_RGN64_HI2_FUNC()
static inline uint64_t BDK_TB_ABORT_RGN64_HI2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_ABORT_RGN64_HI2_FUNC(void)
{
    return 0x87e013000118ll;
}

#define typedef_BDK_TB_ABORT_RGN64_HI2 bdk_tb_abort_rgn64_hi2_t
#define bustype_BDK_TB_ABORT_RGN64_HI2 BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_ABORT_RGN64_HI2 "TB_ABORT_RGN64_HI2"
#define busnum_BDK_TB_ABORT_RGN64_HI2 0
#define arguments_BDK_TB_ABORT_RGN64_HI2 -1,-1,-1,-1

/**
 * Register (NCB32b) tb_abort_rgn64_hi2_hi
 *
 * Trickbox AbortRgn64Hi2_Hi Register
 * Second 64bit abort region. Note that writes to ABORT_RGN_HI2 actually
 * zero this regsiter.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_abort_rgn64_hi2_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_abort_rgn64_hi2_hi_s cn; */
} bdk_tb_abort_rgn64_hi2_hi_t;

#define BDK_TB_ABORT_RGN64_HI2_HI BDK_TB_ABORT_RGN64_HI2_HI_FUNC()
static inline uint64_t BDK_TB_ABORT_RGN64_HI2_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_ABORT_RGN64_HI2_HI_FUNC(void)
{
    return 0x87e01300011cll;
}

#define typedef_BDK_TB_ABORT_RGN64_HI2_HI bdk_tb_abort_rgn64_hi2_hi_t
#define bustype_BDK_TB_ABORT_RGN64_HI2_HI BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_ABORT_RGN64_HI2_HI "TB_ABORT_RGN64_HI2_HI"
#define busnum_BDK_TB_ABORT_RGN64_HI2_HI 0
#define arguments_BDK_TB_ABORT_RGN64_HI2_HI -1,-1,-1,-1

/**
 * Register (NCB32b) tb_abort_rgn64_lo1
 *
 * Trickbox AbortRgn64Lo1 Register
 * First 64bit abort region. Note that writes to ABORT_RGN_LO1 actually
 * change this register and zero ABORT_RGN64_LO1_HI.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_abort_rgn64_lo1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_abort_rgn64_lo1_s cn; */
} bdk_tb_abort_rgn64_lo1_t;

#define BDK_TB_ABORT_RGN64_LO1 BDK_TB_ABORT_RGN64_LO1_FUNC()
static inline uint64_t BDK_TB_ABORT_RGN64_LO1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_ABORT_RGN64_LO1_FUNC(void)
{
    return 0x87e013000100ll;
}

#define typedef_BDK_TB_ABORT_RGN64_LO1 bdk_tb_abort_rgn64_lo1_t
#define bustype_BDK_TB_ABORT_RGN64_LO1 BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_ABORT_RGN64_LO1 "TB_ABORT_RGN64_LO1"
#define busnum_BDK_TB_ABORT_RGN64_LO1 0
#define arguments_BDK_TB_ABORT_RGN64_LO1 -1,-1,-1,-1

/**
 * Register (NCB32b) tb_abort_rgn64_lo1_hi
 *
 * Trickbox AbortRgn64Lo1_Hi Register
 * First 64bit abort region. Note that writes to ABORT_RGN_LO1 actually
 * zero this regsiter.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_abort_rgn64_lo1_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_abort_rgn64_lo1_hi_s cn; */
} bdk_tb_abort_rgn64_lo1_hi_t;

#define BDK_TB_ABORT_RGN64_LO1_HI BDK_TB_ABORT_RGN64_LO1_HI_FUNC()
static inline uint64_t BDK_TB_ABORT_RGN64_LO1_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_ABORT_RGN64_LO1_HI_FUNC(void)
{
    return 0x87e013000104ll;
}

#define typedef_BDK_TB_ABORT_RGN64_LO1_HI bdk_tb_abort_rgn64_lo1_hi_t
#define bustype_BDK_TB_ABORT_RGN64_LO1_HI BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_ABORT_RGN64_LO1_HI "TB_ABORT_RGN64_LO1_HI"
#define busnum_BDK_TB_ABORT_RGN64_LO1_HI 0
#define arguments_BDK_TB_ABORT_RGN64_LO1_HI -1,-1,-1,-1

/**
 * Register (NCB32b) tb_abort_rgn64_lo2
 *
 * Trickbox AbortRgn64Lo2 Register
 * Second 64bit abort region. Note that writes to ABORT_RGN_LO2 actually
 * change this register and zero ABORT_RGN64_LO2_HI.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_abort_rgn64_lo2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_abort_rgn64_lo2_s cn; */
} bdk_tb_abort_rgn64_lo2_t;

#define BDK_TB_ABORT_RGN64_LO2 BDK_TB_ABORT_RGN64_LO2_FUNC()
static inline uint64_t BDK_TB_ABORT_RGN64_LO2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_ABORT_RGN64_LO2_FUNC(void)
{
    return 0x87e013000110ll;
}

#define typedef_BDK_TB_ABORT_RGN64_LO2 bdk_tb_abort_rgn64_lo2_t
#define bustype_BDK_TB_ABORT_RGN64_LO2 BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_ABORT_RGN64_LO2 "TB_ABORT_RGN64_LO2"
#define busnum_BDK_TB_ABORT_RGN64_LO2 0
#define arguments_BDK_TB_ABORT_RGN64_LO2 -1,-1,-1,-1

/**
 * Register (NCB32b) tb_abort_rgn64_lo2_hi
 *
 * Trickbox AbortRgn64Lo2_Hi Register
 * Second 64bit abort region. Note that writes to ABORT_RGN_LO2 actually
 * zero this regsiter.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_abort_rgn64_lo2_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_abort_rgn64_lo2_hi_s cn; */
} bdk_tb_abort_rgn64_lo2_hi_t;

#define BDK_TB_ABORT_RGN64_LO2_HI BDK_TB_ABORT_RGN64_LO2_HI_FUNC()
static inline uint64_t BDK_TB_ABORT_RGN64_LO2_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_ABORT_RGN64_LO2_HI_FUNC(void)
{
    return 0x87e013000114ll;
}

#define typedef_BDK_TB_ABORT_RGN64_LO2_HI bdk_tb_abort_rgn64_lo2_hi_t
#define bustype_BDK_TB_ABORT_RGN64_LO2_HI BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_ABORT_RGN64_LO2_HI "TB_ABORT_RGN64_LO2_HI"
#define busnum_BDK_TB_ABORT_RGN64_LO2_HI 0
#define arguments_BDK_TB_ABORT_RGN64_LO2_HI -1,-1,-1,-1

/**
 * Register (NCB32b) tb_abort_rgn_hi1
 *
 * Trickbox AbortRgnHi1 Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * First abort region. Updates to this affect ABORT_REG64_HI1
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_abort_rgn_hi1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_abort_rgn_hi1_s cn; */
} bdk_tb_abort_rgn_hi1_t;

#define BDK_TB_ABORT_RGN_HI1 BDK_TB_ABORT_RGN_HI1_FUNC()
static inline uint64_t BDK_TB_ABORT_RGN_HI1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_ABORT_RGN_HI1_FUNC(void)
{
    return 0x87e013000044ll;
}

#define typedef_BDK_TB_ABORT_RGN_HI1 bdk_tb_abort_rgn_hi1_t
#define bustype_BDK_TB_ABORT_RGN_HI1 BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_ABORT_RGN_HI1 "TB_ABORT_RGN_HI1"
#define busnum_BDK_TB_ABORT_RGN_HI1 0
#define arguments_BDK_TB_ABORT_RGN_HI1 -1,-1,-1,-1

/**
 * Register (NCB32b) tb_abort_rgn_hi2
 *
 * Trickbox AbortRgnHi2 Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * Second abort region. Updates to this affect ABORT_REG64_HI2
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_abort_rgn_hi2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_abort_rgn_hi2_s cn; */
} bdk_tb_abort_rgn_hi2_t;

#define BDK_TB_ABORT_RGN_HI2 BDK_TB_ABORT_RGN_HI2_FUNC()
static inline uint64_t BDK_TB_ABORT_RGN_HI2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_ABORT_RGN_HI2_FUNC(void)
{
    return 0x87e01300003cll;
}

#define typedef_BDK_TB_ABORT_RGN_HI2 bdk_tb_abort_rgn_hi2_t
#define bustype_BDK_TB_ABORT_RGN_HI2 BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_ABORT_RGN_HI2 "TB_ABORT_RGN_HI2"
#define busnum_BDK_TB_ABORT_RGN_HI2 0
#define arguments_BDK_TB_ABORT_RGN_HI2 -1,-1,-1,-1

/**
 * Register (NCB32b) tb_abort_rgn_lo1
 *
 * Trickbox AbortRegLo1 Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * First abort region. Updates to this affect ABORT_REG64_LO1
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_abort_rgn_lo1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_abort_rgn_lo1_s cn; */
} bdk_tb_abort_rgn_lo1_t;

#define BDK_TB_ABORT_RGN_LO1 BDK_TB_ABORT_RGN_LO1_FUNC()
static inline uint64_t BDK_TB_ABORT_RGN_LO1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_ABORT_RGN_LO1_FUNC(void)
{
    return 0x87e013000040ll;
}

#define typedef_BDK_TB_ABORT_RGN_LO1 bdk_tb_abort_rgn_lo1_t
#define bustype_BDK_TB_ABORT_RGN_LO1 BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_ABORT_RGN_LO1 "TB_ABORT_RGN_LO1"
#define busnum_BDK_TB_ABORT_RGN_LO1 0
#define arguments_BDK_TB_ABORT_RGN_LO1 -1,-1,-1,-1

/**
 * Register (NCB32b) tb_abort_rgn_lo2
 *
 * Trickbox AbortRegLo2 Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * Second abort region. Updates to this affect ABORT_REG64_LO2
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_abort_rgn_lo2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_abort_rgn_lo2_s cn; */
} bdk_tb_abort_rgn_lo2_t;

#define BDK_TB_ABORT_RGN_LO2 BDK_TB_ABORT_RGN_LO2_FUNC()
static inline uint64_t BDK_TB_ABORT_RGN_LO2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_ABORT_RGN_LO2_FUNC(void)
{
    return 0x87e013000038ll;
}

#define typedef_BDK_TB_ABORT_RGN_LO2 bdk_tb_abort_rgn_lo2_t
#define bustype_BDK_TB_ABORT_RGN_LO2 BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_ABORT_RGN_LO2 "TB_ABORT_RGN_LO2"
#define busnum_BDK_TB_ABORT_RGN_LO2 0
#define arguments_BDK_TB_ABORT_RGN_LO2 -1,-1,-1,-1

/**
 * Register (NCB) tb_address
 *
 * Trickbox ADDRESS Register
 * 64 bit address of the transaction. (Persistent)
 */
typedef union
{
    uint64_t u;
    struct bdk_tb_address_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t value                 : 64; /**< [ 63:  0](R/W) TBD */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 64; /**< [ 63:  0](R/W) TBD */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_address_s cn; */
} bdk_tb_address_t;

#define BDK_TB_ADDRESS BDK_TB_ADDRESS_FUNC()
static inline uint64_t BDK_TB_ADDRESS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_ADDRESS_FUNC(void)
{
    return 0x87e013000d20ll;
}

#define typedef_BDK_TB_ADDRESS bdk_tb_address_t
#define bustype_BDK_TB_ADDRESS BDK_CSR_TYPE_NCB
#define basename_BDK_TB_ADDRESS "TB_ADDRESS"
#define busnum_BDK_TB_ADDRESS 0
#define arguments_BDK_TB_ADDRESS -1,-1,-1,-1

/**
 * Register (NCB32b) tb_attributes
 *
 * Trickbox ATTRIBUTES Register
 * Attributes of the transaction. (persistent)
 * 32 bit register, to set the Transaction Attributes
 *  bit[3:0] - Cacheability:
 *            bit[0] - Bufferable
 *            bit[1] - Cacheable
 *            bit[2] - Read allocate
 *            bit[3] - Write allocate
 *  bit[7:4] - Res0
 *  bit[10:8]
 *            bit[8] - Privileged (not user)
 *            bit[9] - Normal (not secure)
 *            bit[10] - Instruction
 *  bit[15:11] - Res0
 *  bit[17:16] Shareability domain
 *            0'b00: non shared
 *            0'b01: inner shared
 *            0'b10: outer shared
 *            0'b11: system
 *  bit[23:18] - Res0
 *  bit[25:24] - Transaction word size
 *            0'b00 - 8 bits
 *            0'b01 - 16 bits
 *            0'b10 - 32 bits
 *            0'b11 - 64 bits
 *  bit[31:26] - Res 0
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_attributes_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) TBD */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) TBD */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_attributes_s cn; */
} bdk_tb_attributes_t;

#define BDK_TB_ATTRIBUTES BDK_TB_ATTRIBUTES_FUNC()
static inline uint64_t BDK_TB_ATTRIBUTES_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_ATTRIBUTES_FUNC(void)
{
    return 0x87e013000d10ll;
}

#define typedef_BDK_TB_ATTRIBUTES bdk_tb_attributes_t
#define bustype_BDK_TB_ATTRIBUTES BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_ATTRIBUTES "TB_ATTRIBUTES"
#define busnum_BDK_TB_ATTRIBUTES 0
#define arguments_BDK_TB_ATTRIBUTES -1,-1,-1,-1

/**
 * Register (NCB32b) tb_axi_abort_ctl
 *
 * Trickbox AXI Abort Control Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This Control register is used to inject error as part of AXI bus
 * interface.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_axi_abort_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_28_31        : 4;
        uint32_t abtrgn2errortype      : 2;  /**< [ 27: 26](R/W) Specifies type of error returned when it accesses the region defined by
                                                                 AbortRgnLo2 andAbortRgnHi2 */
        uint32_t abtrgn2wrdisable      : 1;  /**< [ 25: 25](R/W) Disables aborts on writes to the region defined by AbortRgnLo2 and
                                                                 AbortRgnHi2 */
        uint32_t abtrgn2rddisable      : 1;  /**< [ 24: 24](R/W) Disables aborts on reads to region defined by AbortRgnLo2 and AbortRgnHi2 */
        uint32_t abtrgn1errortype      : 2;  /**< [ 23: 22](R/W) Specifies type of error returned when it accesses the region defined by
                                                                 AbortRgnLo1 andAbortRgnHi1 */
        uint32_t abtrgn1wrdisable      : 1;  /**< [ 21: 21](R/W) Disables aborts on writes to the region defined by AbortRgnLo1 and
                                                                 AbortRgnHi1 */
        uint32_t abtrgn1rddisable      : 1;  /**< [ 20: 20](R/W) Disables aborts on reads to region defined by AbortRgnLo1 and AbortRgnHi1 */
        uint32_t abtsingleerrortype    : 2;  /**< [ 19: 18](R/W) Specifies type of error returned by accesses, to AbortSingle specified
                                                                 address */
        uint32_t abtsinglewrdisable    : 1;  /**< [ 17: 17](R/W) Disables aborts on writes from specified AbortSingle address */
        uint32_t abtsinglerddisable    : 1;  /**< [ 16: 16](R/W) Disables aborts on reads from specified AbortSingle address */
        uint32_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_15         : 16;
        uint32_t abtsinglerddisable    : 1;  /**< [ 16: 16](R/W) Disables aborts on reads from specified AbortSingle address */
        uint32_t abtsinglewrdisable    : 1;  /**< [ 17: 17](R/W) Disables aborts on writes from specified AbortSingle address */
        uint32_t abtsingleerrortype    : 2;  /**< [ 19: 18](R/W) Specifies type of error returned by accesses, to AbortSingle specified
                                                                 address */
        uint32_t abtrgn1rddisable      : 1;  /**< [ 20: 20](R/W) Disables aborts on reads to region defined by AbortRgnLo1 and AbortRgnHi1 */
        uint32_t abtrgn1wrdisable      : 1;  /**< [ 21: 21](R/W) Disables aborts on writes to the region defined by AbortRgnLo1 and
                                                                 AbortRgnHi1 */
        uint32_t abtrgn1errortype      : 2;  /**< [ 23: 22](R/W) Specifies type of error returned when it accesses the region defined by
                                                                 AbortRgnLo1 andAbortRgnHi1 */
        uint32_t abtrgn2rddisable      : 1;  /**< [ 24: 24](R/W) Disables aborts on reads to region defined by AbortRgnLo2 and AbortRgnHi2 */
        uint32_t abtrgn2wrdisable      : 1;  /**< [ 25: 25](R/W) Disables aborts on writes to the region defined by AbortRgnLo2 and
                                                                 AbortRgnHi2 */
        uint32_t abtrgn2errortype      : 2;  /**< [ 27: 26](R/W) Specifies type of error returned when it accesses the region defined by
                                                                 AbortRgnLo2 andAbortRgnHi2 */
        uint32_t reserved_28_31        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_axi_abort_ctl_s cn; */
} bdk_tb_axi_abort_ctl_t;

#define BDK_TB_AXI_ABORT_CTL BDK_TB_AXI_ABORT_CTL_FUNC()
static inline uint64_t BDK_TB_AXI_ABORT_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_AXI_ABORT_CTL_FUNC(void)
{
    return 0x87e013000500ll;
}

#define typedef_BDK_TB_AXI_ABORT_CTL bdk_tb_axi_abort_ctl_t
#define bustype_BDK_TB_AXI_ABORT_CTL BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_AXI_ABORT_CTL "TB_AXI_ABORT_CTL"
#define busnum_BDK_TB_AXI_ABORT_CTL 0
#define arguments_BDK_TB_AXI_ABORT_CTL -1,-1,-1,-1

/**
 * Register (NCB32b) tb_clear_fiq
 *
 * Trickbox ClearFIQ Register
 * This register causes the trickbox to de-assert FIQ for processors
 * specified in TargetCPU if currently asserted.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_clear_fiq_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) A write of 0x0000_0000 to this register, deasserts the FIQ. All
                                                                 processors as specified in TargetCPU would get their FIQ signals
                                                                 deasserted. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) A write of 0x0000_0000 to this register, deasserts the FIQ. All
                                                                 processors as specified in TargetCPU would get their FIQ signals
                                                                 deasserted. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_clear_fiq_s cn; */
} bdk_tb_clear_fiq_t;

#define BDK_TB_CLEAR_FIQ BDK_TB_CLEAR_FIQ_FUNC()
static inline uint64_t BDK_TB_CLEAR_FIQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_CLEAR_FIQ_FUNC(void)
{
    return 0x87e013000010ll;
}

#define typedef_BDK_TB_CLEAR_FIQ bdk_tb_clear_fiq_t
#define bustype_BDK_TB_CLEAR_FIQ BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_CLEAR_FIQ "TB_CLEAR_FIQ"
#define busnum_BDK_TB_CLEAR_FIQ 0
#define arguments_BDK_TB_CLEAR_FIQ -1,-1,-1,-1

/**
 * Register (NCB32b) tb_clear_irq
 *
 * Trickbox ClearIRQ Register
 * Write to ClearIRQ register to de-assert IRQ for processor as specified in
 * TargetCPU if currently asserted.  There is no effect on writing to this
 * register if IRQ is not asserted.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_clear_irq_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) A write of 0x0000_0000 to this register, deasserts the IRQ. All
                                                                 processors as specified in TargetCPU would get their IRQ signals
                                                                 deasserted. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) A write of 0x0000_0000 to this register, deasserts the IRQ. All
                                                                 processors as specified in TargetCPU would get their IRQ signals
                                                                 deasserted. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_clear_irq_s cn; */
} bdk_tb_clear_irq_t;

#define BDK_TB_CLEAR_IRQ BDK_TB_CLEAR_IRQ_FUNC()
static inline uint64_t BDK_TB_CLEAR_IRQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_CLEAR_IRQ_FUNC(void)
{
    return 0x87e013000014ll;
}

#define typedef_BDK_TB_CLEAR_IRQ bdk_tb_clear_irq_t
#define bustype_BDK_TB_CLEAR_IRQ BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_CLEAR_IRQ "TB_CLEAR_IRQ"
#define busnum_BDK_TB_CLEAR_IRQ 0
#define arguments_BDK_TB_CLEAR_IRQ -1,-1,-1,-1

/**
 * Register (NCB32b) tb_core_generated_irq_pin_value
 *
 * Trickbox CORE_GENERATED_IRQ_PIN_VALUE Register
 * The processor in some cases is capable of generating interrupt which it
 * drives out in some pins to be handled later.  These interrupt can mean an
 * overflow event which needs to be communicated to the running software.
 * Each processor has a set of pins, which it drives, to indicate an
 * Interrupt or event being generated from processor.  These pins in a system
 * environment could be routed through GIC back into the processor to handle
 * the interrupt generated by processor.  The GIC serves here to prioritize
 * the processor interrupt along with other interrupts of the system.
 *
 * The set of interrupts under this category which needs to be visible to the
 * test are PMUIRQ, CTIIRQ and COMMIRQ.  These interrupts which originates
 * from the processor are to be captured by the trickbox.  The test can later
 * read from the trickbox to know the status of these signals.  Two registers
 * in trickbox are necessary to support this feature.
 *
 * - 1. Extended_TargetCpu to indicate the target processor whose status is to be read.
 * - 2. CORE_GENERATED_IRQ_PIN_VALUE to read the value of the associated pins of the TargetCPU.
 *
 * A logical target processor number is written into Extended_TargetCpu
 * register and a subsequent read from CORE_GENERATED_IRQ_PIN_VALUE should
 * return a value of the corresponding interrupt pins for that logical
 * processor.
 *
 * If the pin is edge triggered it is to be latched such that the processor
 * reading the status of this pin at a later instance in time identifies that
 * the pin was asserted.  If the pin is level triggered then no latching
 * would be required as the status can be read by reading the pin value
 * directly.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_core_generated_irq_pin_value_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t commirq               : 1;  /**< [  8:  8](R/W) Reads: value 1 indicates COMMIRQ asserted, value 0 indicates
                                                                 COMMIRQ de-asserted

                                                                 Writes: if latched, value 1 will clear the latched status of
                                                                 COMMIRQ and not alter the source of the COMMIRQ. if not latched
                                                                 do nothing. value 0 - do nothing */
        uint32_t reserved_5_7          : 3;
        uint32_t ctiirq                : 1;  /**< [  4:  4](R/W) Reads: value 1 indicates CTIIRQ asserted, value 0 indicates
                                                                 CTIIRQ de-asserted

                                                                 Writes: if latched, value 1 will clear the latched status of
                                                                 CTIIRQ and not alter the source of the CTIIRQ. if not latched
                                                                 do nothing. value 0 - do nothing */
        uint32_t reserved_1_3          : 3;
        uint32_t pmuirq                : 1;  /**< [  0:  0](R/W) Reads: value 1 indicates PMUIRQ asserted, value 0 indicates PMUIRQ
                                                                 de-asserted

                                                                 Writes: if latched, value 1 will clear the latched status of
                                                                 PMUIRQ and not alter the source of the PMUIRQ. if not latched
                                                                 do nothing. value 0 - do nothing */
#else /* Word 0 - Little Endian */
        uint32_t pmuirq                : 1;  /**< [  0:  0](R/W) Reads: value 1 indicates PMUIRQ asserted, value 0 indicates PMUIRQ
                                                                 de-asserted

                                                                 Writes: if latched, value 1 will clear the latched status of
                                                                 PMUIRQ and not alter the source of the PMUIRQ. if not latched
                                                                 do nothing. value 0 - do nothing */
        uint32_t reserved_1_3          : 3;
        uint32_t ctiirq                : 1;  /**< [  4:  4](R/W) Reads: value 1 indicates CTIIRQ asserted, value 0 indicates
                                                                 CTIIRQ de-asserted

                                                                 Writes: if latched, value 1 will clear the latched status of
                                                                 CTIIRQ and not alter the source of the CTIIRQ. if not latched
                                                                 do nothing. value 0 - do nothing */
        uint32_t reserved_5_7          : 3;
        uint32_t commirq               : 1;  /**< [  8:  8](R/W) Reads: value 1 indicates COMMIRQ asserted, value 0 indicates
                                                                 COMMIRQ de-asserted

                                                                 Writes: if latched, value 1 will clear the latched status of
                                                                 COMMIRQ and not alter the source of the COMMIRQ. if not latched
                                                                 do nothing. value 0 - do nothing */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_core_generated_irq_pin_value_s cn; */
} bdk_tb_core_generated_irq_pin_value_t;

#define BDK_TB_CORE_GENERATED_IRQ_PIN_VALUE BDK_TB_CORE_GENERATED_IRQ_PIN_VALUE_FUNC()
static inline uint64_t BDK_TB_CORE_GENERATED_IRQ_PIN_VALUE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_CORE_GENERATED_IRQ_PIN_VALUE_FUNC(void)
{
    return 0x87e0130000b0ll;
}

#define typedef_BDK_TB_CORE_GENERATED_IRQ_PIN_VALUE bdk_tb_core_generated_irq_pin_value_t
#define bustype_BDK_TB_CORE_GENERATED_IRQ_PIN_VALUE BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_CORE_GENERATED_IRQ_PIN_VALUE "TB_CORE_GENERATED_IRQ_PIN_VALUE"
#define busnum_BDK_TB_CORE_GENERATED_IRQ_PIN_VALUE 0
#define arguments_BDK_TB_CORE_GENERATED_IRQ_PIN_VALUE -1,-1,-1,-1

/**
 * Register (NCB) tb_data
 *
 * Trickbox DATA Register
 * Data to be read/written.
 * - on read: triggers a read transaction with the configured
 * attributes and returns up to 64 bit of data.
 * - on write: triggers a write of the data written to the address.
 * Returns a transaction acknowledge after the write is complete.
 */
typedef union
{
    uint64_t u;
    struct bdk_tb_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t value                 : 64; /**< [ 63:  0](R/W) TBD */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 64; /**< [ 63:  0](R/W) TBD */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_data_s cn; */
} bdk_tb_data_t;

#define BDK_TB_DATA BDK_TB_DATA_FUNC()
static inline uint64_t BDK_TB_DATA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_DATA_FUNC(void)
{
    return 0x87e013000d40ll;
}

#define typedef_BDK_TB_DATA bdk_tb_data_t
#define bustype_BDK_TB_DATA BDK_CSR_TYPE_NCB
#define basename_BDK_TB_DATA "TB_DATA"
#define busnum_BDK_TB_DATA 0
#define arguments_BDK_TB_DATA -1,-1,-1,-1

/**
 * Register (NCB32b) tb_dbg_control
 *
 * Trickbox DebugControl Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register allows the testing and direct driving of processor
 * debug signals.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_dbg_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t dbgpaddr31            : 1;  /**< [  8:  8](R/W) Drives PADDR31.  When HIGH, debug port accesses the processor debug
                                                                 register as if an external debugger was connected (different memory map
                                                                 rights) */
        uint32_t dbgswen               : 1;  /**< [  7:  7](R/W) This bit drives DBGSWEN
                                                                 - 0 DBGSWEN is deasserted
                                                                 - 1 DBGSWEN is asserted */
        uint32_t reserved_4_6          : 3;
        uint32_t dbgacklow             : 1;  /**< [  3:  3](RO) Indicates whether DBGACK is LOW since last cleared (level detect). Read only bit. */
        uint32_t dbgackhigh            : 1;  /**< [  2:  2](RO) Indicates whether DBGACK is HIGH since last cleared (level detect). Read only bit. */
        uint32_t one_in_avs            : 1;  /**< [  1:  1](RO) Reserved. */
        uint32_t dbgen                 : 1;  /**< [  0:  0](R/W) Drives DBGEN pin. Read Write bit.
                                                                 - 0 DBGEN deasserted
                                                                 - 1 DBGEN asserted */
#else /* Word 0 - Little Endian */
        uint32_t dbgen                 : 1;  /**< [  0:  0](R/W) Drives DBGEN pin. Read Write bit.
                                                                 - 0 DBGEN deasserted
                                                                 - 1 DBGEN asserted */
        uint32_t one_in_avs            : 1;  /**< [  1:  1](RO) Reserved. */
        uint32_t dbgackhigh            : 1;  /**< [  2:  2](RO) Indicates whether DBGACK is HIGH since last cleared (level detect). Read only bit. */
        uint32_t dbgacklow             : 1;  /**< [  3:  3](RO) Indicates whether DBGACK is LOW since last cleared (level detect). Read only bit. */
        uint32_t reserved_4_6          : 3;
        uint32_t dbgswen               : 1;  /**< [  7:  7](R/W) This bit drives DBGSWEN
                                                                 - 0 DBGSWEN is deasserted
                                                                 - 1 DBGSWEN is asserted */
        uint32_t dbgpaddr31            : 1;  /**< [  8:  8](R/W) Drives PADDR31.  When HIGH, debug port accesses the processor debug
                                                                 register as if an external debugger was connected (different memory map
                                                                 rights) */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_dbg_control_s cn; */
} bdk_tb_dbg_control_t;

#define BDK_TB_DBG_CONTROL BDK_TB_DBG_CONTROL_FUNC()
static inline uint64_t BDK_TB_DBG_CONTROL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_DBG_CONTROL_FUNC(void)
{
    return 0x87e013000054ll;
}

#define typedef_BDK_TB_DBG_CONTROL bdk_tb_dbg_control_t
#define bustype_BDK_TB_DBG_CONTROL BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_DBG_CONTROL "TB_DBG_CONTROL"
#define busnum_BDK_TB_DBG_CONTROL 0
#define arguments_BDK_TB_DBG_CONTROL -1,-1,-1,-1

/**
 * Register (NCB32b) tb_device_id
 *
 * Trickbox DEVICE_ID Register
 * Device ID of the generating device to be indicted to the ITS.  32 bit,
 * persistent (does not get reset when a transaction is triggered).
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_device_id_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) 32 bit register, to set the Device ID. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) 32 bit register, to set the Device ID. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_device_id_s cn; */
} bdk_tb_device_id_t;

#define BDK_TB_DEVICE_ID BDK_TB_DEVICE_ID_FUNC()
static inline uint64_t BDK_TB_DEVICE_ID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_DEVICE_ID_FUNC(void)
{
    return 0x87e013000d00ll;
}

#define typedef_BDK_TB_DEVICE_ID bdk_tb_device_id_t
#define bustype_BDK_TB_DEVICE_ID BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_DEVICE_ID "TB_DEVICE_ID"
#define busnum_BDK_TB_DEVICE_ID 0
#define arguments_BDK_TB_DEVICE_ID -1,-1,-1,-1

/**
 * Register (NCB32b) tb_dormant_control
 *
 * Trickbox DormantControl Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register controls the power down features of the processor.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_dormant_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_13_31        : 19;
        uint32_t dbgrstreq             : 1;  /**< [ 12: 12](R/W) When `1` applies cold reset to the TargetCPU */
        uint32_t dbgpwrupreq           : 1;  /**< [ 11: 11](R/W) 1 indicates power up initiated for the TargetCPU */
        uint32_t standbywfe            : 1;  /**< [ 10: 10](R/W) STANDBYWFE signal from processor; indicates when processor is in WFE, 1
                                                                 indicates target processor has entered WFE */
        uint32_t reserved_3_9          : 7;
        uint32_t ndbgpwrdwnreq         : 1;  /**< [  2:  2](R/W) 0 indicates power down initiated for the TargetCPU */
        uint32_t dbgnopwrdwn           : 1;  /**< [  1:  1](R/W) Reflects the DBGNOPWRDWN signal of TargetCPU */
        uint32_t standbywfi            : 1;  /**< [  0:  0](RO) Signal from processor indicating whether it is in stand-by waiting for
                                                                 interrupt.
                                                                 - 1 indicates target processor has entered WFI */
#else /* Word 0 - Little Endian */
        uint32_t standbywfi            : 1;  /**< [  0:  0](RO) Signal from processor indicating whether it is in stand-by waiting for
                                                                 interrupt.
                                                                 - 1 indicates target processor has entered WFI */
        uint32_t dbgnopwrdwn           : 1;  /**< [  1:  1](R/W) Reflects the DBGNOPWRDWN signal of TargetCPU */
        uint32_t ndbgpwrdwnreq         : 1;  /**< [  2:  2](R/W) 0 indicates power down initiated for the TargetCPU */
        uint32_t reserved_3_9          : 7;
        uint32_t standbywfe            : 1;  /**< [ 10: 10](R/W) STANDBYWFE signal from processor; indicates when processor is in WFE, 1
                                                                 indicates target processor has entered WFE */
        uint32_t dbgpwrupreq           : 1;  /**< [ 11: 11](R/W) 1 indicates power up initiated for the TargetCPU */
        uint32_t dbgrstreq             : 1;  /**< [ 12: 12](R/W) When `1` applies cold reset to the TargetCPU */
        uint32_t reserved_13_31        : 19;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_dormant_control_s cn; */
} bdk_tb_dormant_control_t;

#define BDK_TB_DORMANT_CONTROL BDK_TB_DORMANT_CONTROL_FUNC()
static inline uint64_t BDK_TB_DORMANT_CONTROL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_DORMANT_CONTROL_FUNC(void)
{
    return 0x87e0130000a4ll;
}

#define typedef_BDK_TB_DORMANT_CONTROL bdk_tb_dormant_control_t
#define bustype_BDK_TB_DORMANT_CONTROL BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_DORMANT_CONTROL "TB_DORMANT_CONTROL"
#define busnum_BDK_TB_DORMANT_CONTROL 0
#define arguments_BDK_TB_DORMANT_CONTROL -1,-1,-1,-1

/**
 * Register (NCB32b) tb_extended_target_cpu
 *
 * Trickbox EXTENDED_TARGET_CPU Register
 * Logical processor number
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_extended_target_cpu_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_extended_target_cpu_s cn; */
} bdk_tb_extended_target_cpu_t;

#define BDK_TB_EXTENDED_TARGET_CPU BDK_TB_EXTENDED_TARGET_CPU_FUNC()
static inline uint64_t BDK_TB_EXTENDED_TARGET_CPU_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_EXTENDED_TARGET_CPU_FUNC(void)
{
    return 0x87e0130000f0ll;
}

#define typedef_BDK_TB_EXTENDED_TARGET_CPU bdk_tb_extended_target_cpu_t
#define bustype_BDK_TB_EXTENDED_TARGET_CPU BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_EXTENDED_TARGET_CPU "TB_EXTENDED_TARGET_CPU"
#define busnum_BDK_TB_EXTENDED_TARGET_CPU 0
#define arguments_BDK_TB_EXTENDED_TARGET_CPU -1,-1,-1,-1

/**
 * Register (NCB32b) tb_gic_rd_event_status_index
 *
 * Trickbox GIC_RD_EVENT_STATUS_INDEX Register
 * Logical Processor Number Associated with the Redistributor
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_gic_rd_event_status_index_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) This field holds the logical processor number which is associated with the
                                                                 redistributor whose status information is to be read. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) This field holds the logical processor number which is associated with the
                                                                 redistributor whose status information is to be read. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_gic_rd_event_status_index_s cn; */
} bdk_tb_gic_rd_event_status_index_t;

#define BDK_TB_GIC_RD_EVENT_STATUS_INDEX BDK_TB_GIC_RD_EVENT_STATUS_INDEX_FUNC()
static inline uint64_t BDK_TB_GIC_RD_EVENT_STATUS_INDEX_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_GIC_RD_EVENT_STATUS_INDEX_FUNC(void)
{
    return 0x87e013000ca0ll;
}

#define typedef_BDK_TB_GIC_RD_EVENT_STATUS_INDEX bdk_tb_gic_rd_event_status_index_t
#define bustype_BDK_TB_GIC_RD_EVENT_STATUS_INDEX BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_GIC_RD_EVENT_STATUS_INDEX "TB_GIC_RD_EVENT_STATUS_INDEX"
#define busnum_BDK_TB_GIC_RD_EVENT_STATUS_INDEX 0
#define arguments_BDK_TB_GIC_RD_EVENT_STATUS_INDEX -1,-1,-1,-1

/**
 * Register (NCB32b) tb_gic_rd_event_status_value
 *
 * Trickbox GIC_RD_EVENT_STATUS_VALUE Register
 * WakeRequestDrives DBGEN pin. Read Write bit.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_gic_rd_event_status_value_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t wakerequest           : 1;  /**< [  0:  0](R/W) WakeRequestDrives DBGEN pin. Read Write bit.
                                                                 - 0 WakeRequest deasserted
                                                                 - 1 WakeRequest asserted */
#else /* Word 0 - Little Endian */
        uint32_t wakerequest           : 1;  /**< [  0:  0](R/W) WakeRequestDrives DBGEN pin. Read Write bit.
                                                                 - 0 WakeRequest deasserted
                                                                 - 1 WakeRequest asserted */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_gic_rd_event_status_value_s cn; */
} bdk_tb_gic_rd_event_status_value_t;

#define BDK_TB_GIC_RD_EVENT_STATUS_VALUE BDK_TB_GIC_RD_EVENT_STATUS_VALUE_FUNC()
static inline uint64_t BDK_TB_GIC_RD_EVENT_STATUS_VALUE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_GIC_RD_EVENT_STATUS_VALUE_FUNC(void)
{
    return 0x87e013000ca4ll;
}

#define typedef_BDK_TB_GIC_RD_EVENT_STATUS_VALUE bdk_tb_gic_rd_event_status_value_t
#define bustype_BDK_TB_GIC_RD_EVENT_STATUS_VALUE BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_GIC_RD_EVENT_STATUS_VALUE "TB_GIC_RD_EVENT_STATUS_VALUE"
#define busnum_BDK_TB_GIC_RD_EVENT_STATUS_VALUE 0
#define arguments_BDK_TB_GIC_RD_EVENT_STATUS_VALUE -1,-1,-1,-1

/**
 * Register (NCB32b) tb_gte_api
 *
 * Trickbox GTE_API Register
 * Set of functions out of possible group of GTE. Possible groups
 * are external observer, PPU or Access Sensitive Devices.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_gte_api_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_gte_api_s cn; */
} bdk_tb_gte_api_t;

#define BDK_TB_GTE_API BDK_TB_GTE_API_FUNC()
static inline uint64_t BDK_TB_GTE_API_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_GTE_API_FUNC(void)
{
    return 0x87e013000a00ll;
}

#define typedef_BDK_TB_GTE_API bdk_tb_gte_api_t
#define bustype_BDK_TB_GTE_API BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_GTE_API "TB_GTE_API"
#define busnum_BDK_TB_GTE_API 0
#define arguments_BDK_TB_GTE_API -1,-1,-1,-1

/**
 * Register (NCB32b) tb_gte_api_param
 *
 * Trickbox GTE_API_PARAM Register
 * Acts differently based on the groups chosen out of GTE_API.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_gte_api_param_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_gte_api_param_s cn; */
} bdk_tb_gte_api_param_t;

#define BDK_TB_GTE_API_PARAM BDK_TB_GTE_API_PARAM_FUNC()
static inline uint64_t BDK_TB_GTE_API_PARAM_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_GTE_API_PARAM_FUNC(void)
{
    return 0x87e013000a04ll;
}

#define typedef_BDK_TB_GTE_API_PARAM bdk_tb_gte_api_param_t
#define bustype_BDK_TB_GTE_API_PARAM BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_GTE_API_PARAM "TB_GTE_API_PARAM"
#define busnum_BDK_TB_GTE_API_PARAM 0
#define arguments_BDK_TB_GTE_API_PARAM -1,-1,-1,-1

/**
 * Register (NCB32b) tb_gte_api_param_64
 *
 * Trickbox GTE_API_PARAM_64 Register
 * Lower 32 address associated with 64 bit extended parameter.
 * Generally associated with 64 bit functionality
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_gte_api_param_64_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_gte_api_param_64_s cn; */
} bdk_tb_gte_api_param_64_t;

#define BDK_TB_GTE_API_PARAM_64 BDK_TB_GTE_API_PARAM_64_FUNC()
static inline uint64_t BDK_TB_GTE_API_PARAM_64_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_GTE_API_PARAM_64_FUNC(void)
{
    return 0x87e013000a28ll;
}

#define typedef_BDK_TB_GTE_API_PARAM_64 bdk_tb_gte_api_param_64_t
#define bustype_BDK_TB_GTE_API_PARAM_64 BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_GTE_API_PARAM_64 "TB_GTE_API_PARAM_64"
#define busnum_BDK_TB_GTE_API_PARAM_64 0
#define arguments_BDK_TB_GTE_API_PARAM_64 -1,-1,-1,-1

/**
 * Register (NCB32b) tb_gte_api_param_64_hi
 *
 * Trickbox GTE_API_PARAM_64_HI Register
 * Upper 32 addresses associated with 64 bit extended
 * parameter. Generally associated with 64 bit functionality
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_gte_api_param_64_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_gte_api_param_64_hi_s cn; */
} bdk_tb_gte_api_param_64_hi_t;

#define BDK_TB_GTE_API_PARAM_64_HI BDK_TB_GTE_API_PARAM_64_HI_FUNC()
static inline uint64_t BDK_TB_GTE_API_PARAM_64_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_GTE_API_PARAM_64_HI_FUNC(void)
{
    return 0x87e013000a2cll;
}

#define typedef_BDK_TB_GTE_API_PARAM_64_HI bdk_tb_gte_api_param_64_hi_t
#define bustype_BDK_TB_GTE_API_PARAM_64_HI BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_GTE_API_PARAM_64_HI "TB_GTE_API_PARAM_64_HI"
#define busnum_BDK_TB_GTE_API_PARAM_64_HI 0
#define arguments_BDK_TB_GTE_API_PARAM_64_HI -1,-1,-1,-1

/**
 * Register (NCB32b) tb_gte_api_status
 *
 * Trickbox GTE_API_STATUS Register
 * Returns the status or handle of the exercised function.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_gte_api_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_gte_api_status_s cn; */
} bdk_tb_gte_api_status_t;

#define BDK_TB_GTE_API_STATUS BDK_TB_GTE_API_STATUS_FUNC()
static inline uint64_t BDK_TB_GTE_API_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_GTE_API_STATUS_FUNC(void)
{
    return 0x87e013000a08ll;
}

#define typedef_BDK_TB_GTE_API_STATUS bdk_tb_gte_api_status_t
#define bustype_BDK_TB_GTE_API_STATUS BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_GTE_API_STATUS "TB_GTE_API_STATUS"
#define busnum_BDK_TB_GTE_API_STATUS 0
#define arguments_BDK_TB_GTE_API_STATUS -1,-1,-1,-1

/**
 * Register (NCB32b) tb_gte_api_status_64
 *
 * Trickbox GTE_API_STATUS_64 Register
 * Lower 32 address associated with 64 bit extended status
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_gte_api_status_64_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_gte_api_status_64_s cn; */
} bdk_tb_gte_api_status_64_t;

#define BDK_TB_GTE_API_STATUS_64 BDK_TB_GTE_API_STATUS_64_FUNC()
static inline uint64_t BDK_TB_GTE_API_STATUS_64_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_GTE_API_STATUS_64_FUNC(void)
{
    return 0x87e013000a20ll;
}

#define typedef_BDK_TB_GTE_API_STATUS_64 bdk_tb_gte_api_status_64_t
#define bustype_BDK_TB_GTE_API_STATUS_64 BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_GTE_API_STATUS_64 "TB_GTE_API_STATUS_64"
#define busnum_BDK_TB_GTE_API_STATUS_64 0
#define arguments_BDK_TB_GTE_API_STATUS_64 -1,-1,-1,-1

/**
 * Register (NCB32b) tb_gte_api_status_64_hi
 *
 * Trickbox GTE_API_STATUS_64_HI Register
 * Upper 32 address associated with 64 bit extended status
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_gte_api_status_64_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_gte_api_status_64_hi_s cn; */
} bdk_tb_gte_api_status_64_hi_t;

#define BDK_TB_GTE_API_STATUS_64_HI BDK_TB_GTE_API_STATUS_64_HI_FUNC()
static inline uint64_t BDK_TB_GTE_API_STATUS_64_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_GTE_API_STATUS_64_HI_FUNC(void)
{
    return 0x87e013000a24ll;
}

#define typedef_BDK_TB_GTE_API_STATUS_64_HI bdk_tb_gte_api_status_64_hi_t
#define bustype_BDK_TB_GTE_API_STATUS_64_HI BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_GTE_API_STATUS_64_HI "TB_GTE_API_STATUS_64_HI"
#define busnum_BDK_TB_GTE_API_STATUS_64_HI 0
#define arguments_BDK_TB_GTE_API_STATUS_64_HI -1,-1,-1,-1

/**
 * Register (NCB32b) tb_operate
 *
 * Trickbox OPERATE Register
 * Status of the operation
 * Read:
 * - 0: Operation in Progress
 * - 1: Transaction error
 *
 * Valid values for this register bit 1:0 for read:
 * - 0 no operation no error,
 * - 1 operation in progress,
 * - 2 transaction error on last transaction
 *
 * Write:
 * - 0: Write, not read.
 * - A write of 1 triggers a write,
 * - A write of 0 triggers a read.
 * - A write is performed and a transaction is already in progress, the write aborts.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_operate_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_2_31         : 30;
        uint32_t value                 : 2;  /**< [  1:  0](R/W) See above */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 2;  /**< [  1:  0](R/W) See above */
        uint32_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_operate_s cn; */
} bdk_tb_operate_t;

#define BDK_TB_OPERATE BDK_TB_OPERATE_FUNC()
static inline uint64_t BDK_TB_OPERATE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_OPERATE_FUNC(void)
{
    return 0x87e013000d80ll;
}

#define typedef_BDK_TB_OPERATE bdk_tb_operate_t
#define bustype_BDK_TB_OPERATE BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_OPERATE "TB_OPERATE"
#define busnum_BDK_TB_OPERATE 0
#define arguments_BDK_TB_OPERATE -1,-1,-1,-1

/**
 * Register (NCB32b) tb_pin_configuration
 *
 * Trickbox Pin Configuration Register
 * This register is used to drive the associated pins which configure the
 * processor.  All processors are driven with these pin value.  Few of the
 * bits controls behavior of the processor at reset entry (for the subsequent
 * reset).
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_pin_configuration_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_25_31        : 7;
        uint32_t disablenidebug        : 1;  /**< [ 24: 24](R/W) This bit is inverted and wired into NIDEN input of trustzone enabled
                                                                 processor.  This is an R/W bit.
                                                                 - 0 enables NIDEN
                                                                 - 1 disables NIDEN */
        uint32_t cfgnmfi               : 1;  /**< [ 23: 23](R/W) This bit configures the NMFI for the processor. This is an R/W bit.
                                                                 - 0 indicates FIQ is not NMFI
                                                                 - 1 indicates FIQ is Non Mask able Fast Interrupt */
        uint32_t exceptinit            : 1;  /**< [ 22: 22](R/W) This bit indicates ISA state upon exception entry for AArch32.  Equivalent
                                                                 to TE bit.  This is an R/W bit.  This bit takes effect on a reset.
                                                                 - 0 indicates ARM exception entry
                                                                 - 1 indicates Thumb exception entry */
        uint32_t reserved_21           : 1;
        uint32_t cp15disable           : 1;  /**< [ 20: 20](R/W) This bit indicates disabling of CP15 register. This is an R/W bit.
                                                                 - 0 indicates enable CP15 access
                                                                 - 1 indicates disable CP15 access */
        uint32_t disablespnidebug      : 1;  /**< [ 19: 19](R/W) This bit is inverted and wired into SPNIDEN input of trustzone enabled
                                                                 processor.  This is an R/W bit.
                                                                 - 0 indicates enable SPNIDEN
                                                                 - 1 indicates disable SPNIDEN */
        uint32_t disablespidebug       : 1;  /**< [ 18: 18](R/W) This bit is inverted and wired into SPIDEN input of trustzone enabled
                                                                 processor.  This is an R/W bit.
                                                                 - 0 indicates enable SPIDEN input
                                                                 - 1 indicates disable SPIDEN input */
        uint32_t reserved_15_17        : 3;
        uint32_t config64              : 1;  /**< [ 14: 14](R/W) This bit controls the boot into AArch64 on Cold reset. This is an R/W bit.
                                                                 - 0 indicates boot into AArch32
                                                                 - 1 indicates boot into AArch64. */
        uint32_t reserved_3_13         : 11;
        uint32_t cfgend                : 1;  /**< [  2:  2](R/W) This bit controls the CFGEND pin input to the processor under reset. This is an R/W bit.
                                                                 - 0 indicates Little Endian
                                                                 - 1 indicates Big Endian */
        uint32_t rw                    : 1;  /**< [  1:  1](R/W) Register Width bit determines Arch state of the processor after reset.
                                                                 This is a Read Write (R/W) bit.  This bit takes effect only on reset.
                                                                 - 0 indicates AArch32
                                                                 - 1 indicates AArch64. */
        uint32_t hivecs                : 1;  /**< [  0:  0](R/W) This determines whether the processor resets to HIVECS location when reset
                                                                 is applied.  This is a Write Only bit.  This bit takes effect only on
                                                                 reset.
                                                                 - 0 indicates no HIVECS.
                                                                 - 1 indicates HIVECS is enabled when booting into AArch32. */
#else /* Word 0 - Little Endian */
        uint32_t hivecs                : 1;  /**< [  0:  0](R/W) This determines whether the processor resets to HIVECS location when reset
                                                                 is applied.  This is a Write Only bit.  This bit takes effect only on
                                                                 reset.
                                                                 - 0 indicates no HIVECS.
                                                                 - 1 indicates HIVECS is enabled when booting into AArch32. */
        uint32_t rw                    : 1;  /**< [  1:  1](R/W) Register Width bit determines Arch state of the processor after reset.
                                                                 This is a Read Write (R/W) bit.  This bit takes effect only on reset.
                                                                 - 0 indicates AArch32
                                                                 - 1 indicates AArch64. */
        uint32_t cfgend                : 1;  /**< [  2:  2](R/W) This bit controls the CFGEND pin input to the processor under reset. This is an R/W bit.
                                                                 - 0 indicates Little Endian
                                                                 - 1 indicates Big Endian */
        uint32_t reserved_3_13         : 11;
        uint32_t config64              : 1;  /**< [ 14: 14](R/W) This bit controls the boot into AArch64 on Cold reset. This is an R/W bit.
                                                                 - 0 indicates boot into AArch32
                                                                 - 1 indicates boot into AArch64. */
        uint32_t reserved_15_17        : 3;
        uint32_t disablespidebug       : 1;  /**< [ 18: 18](R/W) This bit is inverted and wired into SPIDEN input of trustzone enabled
                                                                 processor.  This is an R/W bit.
                                                                 - 0 indicates enable SPIDEN input
                                                                 - 1 indicates disable SPIDEN input */
        uint32_t disablespnidebug      : 1;  /**< [ 19: 19](R/W) This bit is inverted and wired into SPNIDEN input of trustzone enabled
                                                                 processor.  This is an R/W bit.
                                                                 - 0 indicates enable SPNIDEN
                                                                 - 1 indicates disable SPNIDEN */
        uint32_t cp15disable           : 1;  /**< [ 20: 20](R/W) This bit indicates disabling of CP15 register. This is an R/W bit.
                                                                 - 0 indicates enable CP15 access
                                                                 - 1 indicates disable CP15 access */
        uint32_t reserved_21           : 1;
        uint32_t exceptinit            : 1;  /**< [ 22: 22](R/W) This bit indicates ISA state upon exception entry for AArch32.  Equivalent
                                                                 to TE bit.  This is an R/W bit.  This bit takes effect on a reset.
                                                                 - 0 indicates ARM exception entry
                                                                 - 1 indicates Thumb exception entry */
        uint32_t cfgnmfi               : 1;  /**< [ 23: 23](R/W) This bit configures the NMFI for the processor. This is an R/W bit.
                                                                 - 0 indicates FIQ is not NMFI
                                                                 - 1 indicates FIQ is Non Mask able Fast Interrupt */
        uint32_t disablenidebug        : 1;  /**< [ 24: 24](R/W) This bit is inverted and wired into NIDEN input of trustzone enabled
                                                                 processor.  This is an R/W bit.
                                                                 - 0 enables NIDEN
                                                                 - 1 disables NIDEN */
        uint32_t reserved_25_31        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_pin_configuration_s cn; */
} bdk_tb_pin_configuration_t;

#define BDK_TB_PIN_CONFIGURATION BDK_TB_PIN_CONFIGURATION_FUNC()
static inline uint64_t BDK_TB_PIN_CONFIGURATION_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PIN_CONFIGURATION_FUNC(void)
{
    return 0x87e013000004ll;
}

#define typedef_BDK_TB_PIN_CONFIGURATION bdk_tb_pin_configuration_t
#define bustype_BDK_TB_PIN_CONFIGURATION BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PIN_CONFIGURATION "TB_PIN_CONFIGURATION"
#define busnum_BDK_TB_PIN_CONFIGURATION 0
#define arguments_BDK_TB_PIN_CONFIGURATION -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppi_group_target_core
 *
 * Trickbox PPI_GROUP_TARGET_CORE Register
 * This indicates the processor on which the associated value of PPI is to be
 * driven into.  The target processor is the physical target processor
 * number.
 *
 * NOTE: As of the current implementation only 4 processors are supported.
 * VAL uses logical processor numbering scheme based on the resources present
 * in the resource file.  If there is a different mechanism used to indicate
 * the target processor number in this field then VAL needs to convert from
 * logical processor to physical processor which is implementation defined.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppi_group_target_core_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) This field indicates the physical target processor number to which the PPI
                                                                 is to be driven into. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) This field indicates the physical target processor number to which the PPI
                                                                 is to be driven into. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppi_group_target_core_s cn; */
} bdk_tb_ppi_group_target_core_t;

#define BDK_TB_PPI_GROUP_TARGET_CORE BDK_TB_PPI_GROUP_TARGET_CORE_FUNC()
static inline uint64_t BDK_TB_PPI_GROUP_TARGET_CORE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPI_GROUP_TARGET_CORE_FUNC(void)
{
    return 0x87e013000c20ll;
}

#define typedef_BDK_TB_PPI_GROUP_TARGET_CORE bdk_tb_ppi_group_target_core_t
#define bustype_BDK_TB_PPI_GROUP_TARGET_CORE BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPI_GROUP_TARGET_CORE "TB_PPI_GROUP_TARGET_CORE"
#define busnum_BDK_TB_PPI_GROUP_TARGET_CORE 0
#define arguments_BDK_TB_PPI_GROUP_TARGET_CORE -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppi_group_value
 *
 * Trickbox PPI_GROUP_VALUE Register
 * Each bit indicates the associated value of PPI to be driven into the
 * processor.  16 PPI pins are available.
 * - PPI 0, bit[0] associated with PPI pin with Interrupt ID 15
 * - PPI 1, bit[1] associated with PPI pin with Interrupt ID 16
 * - ...
 * - PPI 15, bit[15] associated with PPI pin with Interrupt ID 31
 * - 0 indicates deassertion of associated PPI
 * - 1 indicates assertion of associated PPI
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppi_group_value_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t ppi                   : 16; /**< [ 15:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t ppi                   : 16; /**< [ 15:  0](R/W) Value. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppi_group_value_s cn; */
} bdk_tb_ppi_group_value_t;

#define BDK_TB_PPI_GROUP_VALUE BDK_TB_PPI_GROUP_VALUE_FUNC()
static inline uint64_t BDK_TB_PPI_GROUP_VALUE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPI_GROUP_VALUE_FUNC(void)
{
    return 0x87e013000c24ll;
}

#define typedef_BDK_TB_PPI_GROUP_VALUE bdk_tb_ppi_group_value_t
#define bustype_BDK_TB_PPI_GROUP_VALUE BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPI_GROUP_VALUE "TB_PPI_GROUP_VALUE"
#define busnum_BDK_TB_PPI_GROUP_VALUE 0
#define arguments_BDK_TB_PPI_GROUP_VALUE -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppi_intr_config
 *
 * Trickbox PPI_INTR_CONFIG Register
 * Indicates the LEVEL/EDGE triggered configuration of each pin.
 * 0 = Indicates level configured interrupt.
 * 1 = Indicates edge configured interrupt.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppi_intr_config_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t value                 : 16; /**< [ 15:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 16; /**< [ 15:  0](R/W) Value. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppi_intr_config_s cn; */
} bdk_tb_ppi_intr_config_t;

#define BDK_TB_PPI_INTR_CONFIG BDK_TB_PPI_INTR_CONFIG_FUNC()
static inline uint64_t BDK_TB_PPI_INTR_CONFIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPI_INTR_CONFIG_FUNC(void)
{
    return 0x87e013000c2cll;
}

#define typedef_BDK_TB_PPI_INTR_CONFIG bdk_tb_ppi_intr_config_t
#define bustype_BDK_TB_PPI_INTR_CONFIG BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPI_INTR_CONFIG "TB_PPI_INTR_CONFIG"
#define busnum_BDK_TB_PPI_INTR_CONFIG 0
#define arguments_BDK_TB_PPI_INTR_CONFIG -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppu0addr
 *
 * Trickbox PPU0ADDR Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register indicates the starting address of the PPU region.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppu0addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t address               : 22; /**< [ 31: 10](R/W) Address bits indicating the starting address of programmed PPU region */
        uint32_t reserved_0_9          : 10;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_9          : 10;
        uint32_t address               : 22; /**< [ 31: 10](R/W) Address bits indicating the starting address of programmed PPU region */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppu0addr_s cn; */
} bdk_tb_ppu0addr_t;

#define BDK_TB_PPU0ADDR BDK_TB_PPU0ADDR_FUNC()
static inline uint64_t BDK_TB_PPU0ADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPU0ADDR_FUNC(void)
{
    return 0x87e013000230ll;
}

#define typedef_BDK_TB_PPU0ADDR bdk_tb_ppu0addr_t
#define bustype_BDK_TB_PPU0ADDR BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPU0ADDR "TB_PPU0ADDR"
#define busnum_BDK_TB_PPU0ADDR 0
#define arguments_BDK_TB_PPU0ADDR -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppu0mask
 *
 * Trickbox PPU0MASK Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * The PPU Mask along with PPU address defines the region of memory to be
 * protected by PPU.  For each register pair, an address match is deemed to
 * have occurred when:
 *
 * AddressMatch<n> = Enable<n> & ( ! ( (AddressOnBus[31:10] ^ PPU<n>Addr[31:10] ) &
 * PPU<n>Mask[31:10] ) );
 *
 * In addition, a region abort occurs when:
 *
 * RegionAbort<n> = AddressMatch<n> & ( (AccessNS & !RegionNS<n>) + ( !AccessNS & RegionNS<n> &!
 * PPUMode<n>) );
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppu0mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t address_mask          : 22; /**< [ 31: 10](R/W) Used to define the range over which the PPU is enabled for */
        uint32_t reserved_3_9          : 7;
        uint32_t mode                  : 1;  /**< [  2:  2](R/W) The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
        uint32_t non_secure            : 1;  /**< [  1:  1](R/W) - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
#else /* Word 0 - Little Endian */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
        uint32_t non_secure            : 1;  /**< [  1:  1](R/W) - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
        uint32_t mode                  : 1;  /**< [  2:  2](R/W) The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
        uint32_t reserved_3_9          : 7;
        uint32_t address_mask          : 22; /**< [ 31: 10](R/W) Used to define the range over which the PPU is enabled for */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppu0mask_s cn; */
} bdk_tb_ppu0mask_t;

#define BDK_TB_PPU0MASK BDK_TB_PPU0MASK_FUNC()
static inline uint64_t BDK_TB_PPU0MASK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPU0MASK_FUNC(void)
{
    return 0x87e013000234ll;
}

#define typedef_BDK_TB_PPU0MASK bdk_tb_ppu0mask_t
#define bustype_BDK_TB_PPU0MASK BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPU0MASK "TB_PPU0MASK"
#define busnum_BDK_TB_PPU0MASK 0
#define arguments_BDK_TB_PPU0MASK -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppu1addr
 *
 * Trickbox PPU1ADDR Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register indicates the starting address of the PPU region.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppu1addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t address               : 22; /**< [ 31: 10](R/W) Address bits indicating the starting address of programmed PPU region */
        uint32_t reserved_0_9          : 10;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_9          : 10;
        uint32_t address               : 22; /**< [ 31: 10](R/W) Address bits indicating the starting address of programmed PPU region */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppu1addr_s cn; */
} bdk_tb_ppu1addr_t;

#define BDK_TB_PPU1ADDR BDK_TB_PPU1ADDR_FUNC()
static inline uint64_t BDK_TB_PPU1ADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPU1ADDR_FUNC(void)
{
    return 0x87e013000238ll;
}

#define typedef_BDK_TB_PPU1ADDR bdk_tb_ppu1addr_t
#define bustype_BDK_TB_PPU1ADDR BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPU1ADDR "TB_PPU1ADDR"
#define busnum_BDK_TB_PPU1ADDR 0
#define arguments_BDK_TB_PPU1ADDR -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppu1mask
 *
 * Trickbox PPU*MASK Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * The PPU Mask along with PPU address defines the region of memory to be
 * protected by PPU.  For each register pair, an address match is deemed to
 * have occurred when:
 *
 * AddressMatch<n> = Enable<n> & ( ! ( (AddressOnBus[31:10] ^ PPU<n>Addr[31:10] ) &
 * PPU<n>Mask[31:10] ) );
 *
 * In addition, a region abort occurs when:
 *
 * RegionAbort<n> = AddressMatch<n> & ( (AccessNS & !RegionNS<n>) + ( !AccessNS & RegionNS<n> &!
 * PPUMode<n>) );
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppu1mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t address_mask          : 22; /**< [ 31: 10](R/W) Used to define the range over which the PPU is enabled for */
        uint32_t reserved_3_9          : 7;
        uint32_t mode                  : 1;  /**< [  2:  2](R/W) The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
        uint32_t non_secure            : 1;  /**< [  1:  1](R/W) - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
#else /* Word 0 - Little Endian */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
        uint32_t non_secure            : 1;  /**< [  1:  1](R/W) - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
        uint32_t mode                  : 1;  /**< [  2:  2](R/W) The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
        uint32_t reserved_3_9          : 7;
        uint32_t address_mask          : 22; /**< [ 31: 10](R/W) Used to define the range over which the PPU is enabled for */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppu1mask_s cn; */
} bdk_tb_ppu1mask_t;

#define BDK_TB_PPU1MASK BDK_TB_PPU1MASK_FUNC()
static inline uint64_t BDK_TB_PPU1MASK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPU1MASK_FUNC(void)
{
    return 0x87e01300023cll;
}

#define typedef_BDK_TB_PPU1MASK bdk_tb_ppu1mask_t
#define bustype_BDK_TB_PPU1MASK BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPU1MASK "TB_PPU1MASK"
#define busnum_BDK_TB_PPU1MASK 0
#define arguments_BDK_TB_PPU1MASK -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppu2addr
 *
 * Trickbox PPU2ADDR Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register indicates the starting address of the PPU region.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppu2addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t address               : 22; /**< [ 31: 10](R/W) Address bits indicating the starting address of programmed PPU region */
        uint32_t reserved_0_9          : 10;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_9          : 10;
        uint32_t address               : 22; /**< [ 31: 10](R/W) Address bits indicating the starting address of programmed PPU region */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppu2addr_s cn; */
} bdk_tb_ppu2addr_t;

#define BDK_TB_PPU2ADDR BDK_TB_PPU2ADDR_FUNC()
static inline uint64_t BDK_TB_PPU2ADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPU2ADDR_FUNC(void)
{
    return 0x87e013000240ll;
}

#define typedef_BDK_TB_PPU2ADDR bdk_tb_ppu2addr_t
#define bustype_BDK_TB_PPU2ADDR BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPU2ADDR "TB_PPU2ADDR"
#define busnum_BDK_TB_PPU2ADDR 0
#define arguments_BDK_TB_PPU2ADDR -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppu2mask
 *
 * Trickbox PPU*MASK Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * The PPU Mask along with PPU address defines the region of memory to be
 * protected by PPU.  For each register pair, an address match is deemed to
 * have occurred when:
 *
 * AddressMatch<n> = Enable<n> & ( ! ( (AddressOnBus[31:10] ^ PPU<n>Addr[31:10] ) &
 * PPU<n>Mask[31:10] ) );
 *
 * In addition, a region abort occurs when:
 *
 * RegionAbort<n> = AddressMatch<n> & ( (AccessNS & !RegionNS<n>) + ( !AccessNS & RegionNS<n> &!
 * PPUMode<n>) );
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppu2mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t address_mask          : 22; /**< [ 31: 10](R/W) Used to define the range over which the PPU is enabled for */
        uint32_t reserved_3_9          : 7;
        uint32_t mode                  : 1;  /**< [  2:  2](R/W) The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
        uint32_t non_secure            : 1;  /**< [  1:  1](R/W) - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
#else /* Word 0 - Little Endian */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
        uint32_t non_secure            : 1;  /**< [  1:  1](R/W) - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
        uint32_t mode                  : 1;  /**< [  2:  2](R/W) The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
        uint32_t reserved_3_9          : 7;
        uint32_t address_mask          : 22; /**< [ 31: 10](R/W) Used to define the range over which the PPU is enabled for */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppu2mask_s cn; */
} bdk_tb_ppu2mask_t;

#define BDK_TB_PPU2MASK BDK_TB_PPU2MASK_FUNC()
static inline uint64_t BDK_TB_PPU2MASK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPU2MASK_FUNC(void)
{
    return 0x87e013000244ll;
}

#define typedef_BDK_TB_PPU2MASK bdk_tb_ppu2mask_t
#define bustype_BDK_TB_PPU2MASK BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPU2MASK "TB_PPU2MASK"
#define busnum_BDK_TB_PPU2MASK 0
#define arguments_BDK_TB_PPU2MASK -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppu3addr
 *
 * Trickbox PPU3ADDR Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register indicates the starting address of the PPU region.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppu3addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t address               : 22; /**< [ 31: 10](R/W) Address bits indicating the starting address of programmed PPU region */
        uint32_t reserved_0_9          : 10;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_9          : 10;
        uint32_t address               : 22; /**< [ 31: 10](R/W) Address bits indicating the starting address of programmed PPU region */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppu3addr_s cn; */
} bdk_tb_ppu3addr_t;

#define BDK_TB_PPU3ADDR BDK_TB_PPU3ADDR_FUNC()
static inline uint64_t BDK_TB_PPU3ADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPU3ADDR_FUNC(void)
{
    return 0x87e013000248ll;
}

#define typedef_BDK_TB_PPU3ADDR bdk_tb_ppu3addr_t
#define bustype_BDK_TB_PPU3ADDR BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPU3ADDR "TB_PPU3ADDR"
#define busnum_BDK_TB_PPU3ADDR 0
#define arguments_BDK_TB_PPU3ADDR -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppu3mask
 *
 * Trickbox PPU*MASK Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * The PPU Mask along with PPU address defines the region of memory to be
 * protected by PPU.  For each register pair, an address match is deemed to
 * have occurred when:
 *
 * AddressMatch<n> = Enable<n> & ( ! ( (AddressOnBus[31:10] ^ PPU<n>Addr[31:10] ) &
 * PPU<n>Mask[31:10] ) );
 *
 * In addition, a region abort occurs when:
 *
 * RegionAbort<n> = AddressMatch<n> & ( (AccessNS & !RegionNS<n>) + ( !AccessNS & RegionNS<n> &!
 * PPUMode<n>) );
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppu3mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t address_mask          : 22; /**< [ 31: 10](R/W) Used to define the range over which the PPU is enabled for */
        uint32_t reserved_3_9          : 7;
        uint32_t mode                  : 1;  /**< [  2:  2](R/W) The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
        uint32_t non_secure            : 1;  /**< [  1:  1](R/W) - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
#else /* Word 0 - Little Endian */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
        uint32_t non_secure            : 1;  /**< [  1:  1](R/W) - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
        uint32_t mode                  : 1;  /**< [  2:  2](R/W) The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
        uint32_t reserved_3_9          : 7;
        uint32_t address_mask          : 22; /**< [ 31: 10](R/W) Used to define the range over which the PPU is enabled for */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppu3mask_s cn; */
} bdk_tb_ppu3mask_t;

#define BDK_TB_PPU3MASK BDK_TB_PPU3MASK_FUNC()
static inline uint64_t BDK_TB_PPU3MASK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPU3MASK_FUNC(void)
{
    return 0x87e01300024cll;
}

#define typedef_BDK_TB_PPU3MASK bdk_tb_ppu3mask_t
#define bustype_BDK_TB_PPU3MASK BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPU3MASK "TB_PPU3MASK"
#define busnum_BDK_TB_PPU3MASK 0
#define arguments_BDK_TB_PPU3MASK -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppu4addr
 *
 * Trickbox PPU4ADDR Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register indicates the starting address of the PPU region.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppu4addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t address               : 22; /**< [ 31: 10](R/W) Address bits indicating the starting address of programmed PPU region */
        uint32_t reserved_0_9          : 10;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_9          : 10;
        uint32_t address               : 22; /**< [ 31: 10](R/W) Address bits indicating the starting address of programmed PPU region */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppu4addr_s cn; */
} bdk_tb_ppu4addr_t;

#define BDK_TB_PPU4ADDR BDK_TB_PPU4ADDR_FUNC()
static inline uint64_t BDK_TB_PPU4ADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPU4ADDR_FUNC(void)
{
    return 0x87e013000250ll;
}

#define typedef_BDK_TB_PPU4ADDR bdk_tb_ppu4addr_t
#define bustype_BDK_TB_PPU4ADDR BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPU4ADDR "TB_PPU4ADDR"
#define busnum_BDK_TB_PPU4ADDR 0
#define arguments_BDK_TB_PPU4ADDR -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppu4mask
 *
 * Trickbox PPU*MASK Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * The PPU Mask along with PPU address defines the region of memory to be
 * protected by PPU.  For each register pair, an address match is deemed to
 * have occurred when:
 *
 * AddressMatch<n> = Enable<n> & ( ! ( (AddressOnBus[31:10] ^ PPU<n>Addr[31:10] ) &
 * PPU<n>Mask[31:10] ) );
 *
 * In addition, a region abort occurs when:
 *
 * RegionAbort<n> = AddressMatch<n> & ( (AccessNS & !RegionNS<n>) + ( !AccessNS & RegionNS<n> &!
 * PPUMode<n>) );
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppu4mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t address_mask          : 22; /**< [ 31: 10](R/W) Used to define the range over which the PPU is enabled for */
        uint32_t reserved_3_9          : 7;
        uint32_t mode                  : 1;  /**< [  2:  2](R/W) The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
        uint32_t non_secure            : 1;  /**< [  1:  1](R/W) - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
#else /* Word 0 - Little Endian */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
        uint32_t non_secure            : 1;  /**< [  1:  1](R/W) - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
        uint32_t mode                  : 1;  /**< [  2:  2](R/W) The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
        uint32_t reserved_3_9          : 7;
        uint32_t address_mask          : 22; /**< [ 31: 10](R/W) Used to define the range over which the PPU is enabled for */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppu4mask_s cn; */
} bdk_tb_ppu4mask_t;

#define BDK_TB_PPU4MASK BDK_TB_PPU4MASK_FUNC()
static inline uint64_t BDK_TB_PPU4MASK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPU4MASK_FUNC(void)
{
    return 0x87e013000254ll;
}

#define typedef_BDK_TB_PPU4MASK bdk_tb_ppu4mask_t
#define bustype_BDK_TB_PPU4MASK BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPU4MASK "TB_PPU4MASK"
#define busnum_BDK_TB_PPU4MASK 0
#define arguments_BDK_TB_PPU4MASK -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppu5addr
 *
 * Trickbox PPU5ADDR Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register indicates the starting address of the PPU region.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppu5addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t address               : 22; /**< [ 31: 10](R/W) Address bits indicating the starting address of programmed PPU region */
        uint32_t reserved_0_9          : 10;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_9          : 10;
        uint32_t address               : 22; /**< [ 31: 10](R/W) Address bits indicating the starting address of programmed PPU region */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppu5addr_s cn; */
} bdk_tb_ppu5addr_t;

#define BDK_TB_PPU5ADDR BDK_TB_PPU5ADDR_FUNC()
static inline uint64_t BDK_TB_PPU5ADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPU5ADDR_FUNC(void)
{
    return 0x87e013000258ll;
}

#define typedef_BDK_TB_PPU5ADDR bdk_tb_ppu5addr_t
#define bustype_BDK_TB_PPU5ADDR BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPU5ADDR "TB_PPU5ADDR"
#define busnum_BDK_TB_PPU5ADDR 0
#define arguments_BDK_TB_PPU5ADDR -1,-1,-1,-1

/**
 * Register (NCB32b) tb_ppu5mask
 *
 * Trickbox PPU*MASK Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * The PPU Mask along with PPU address defines the region of memory to be
 * protected by PPU.  For each register pair, an address match is deemed to
 * have occurred when:
 *
 * AddressMatch<n> = Enable<n> & ( ! ( (AddressOnBus[31:10] ^ PPU<n>Addr[31:10] ) &
 * PPU<n>Mask[31:10] ) );
 *
 * In addition, a region abort occurs when:
 *
 * RegionAbort<n> = AddressMatch<n> & ( (AccessNS & !RegionNS<n>) + ( !AccessNS & RegionNS<n> &!
 * PPUMode<n>) );
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_ppu5mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t address_mask          : 22; /**< [ 31: 10](R/W) Used to define the range over which the PPU is enabled for */
        uint32_t reserved_3_9          : 7;
        uint32_t mode                  : 1;  /**< [  2:  2](R/W) The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
        uint32_t non_secure            : 1;  /**< [  1:  1](R/W) - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
#else /* Word 0 - Little Endian */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
        uint32_t non_secure            : 1;  /**< [  1:  1](R/W) - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
        uint32_t mode                  : 1;  /**< [  2:  2](R/W) The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
        uint32_t reserved_3_9          : 7;
        uint32_t address_mask          : 22; /**< [ 31: 10](R/W) Used to define the range over which the PPU is enabled for */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_ppu5mask_s cn; */
} bdk_tb_ppu5mask_t;

#define BDK_TB_PPU5MASK BDK_TB_PPU5MASK_FUNC()
static inline uint64_t BDK_TB_PPU5MASK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_PPU5MASK_FUNC(void)
{
    return 0x87e01300025cll;
}

#define typedef_BDK_TB_PPU5MASK bdk_tb_ppu5mask_t
#define bustype_BDK_TB_PPU5MASK BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_PPU5MASK "TB_PPU5MASK"
#define busnum_BDK_TB_PPU5MASK 0
#define arguments_BDK_TB_PPU5MASK -1,-1,-1,-1

/**
 * Register (NCB32b) tb_rei_target_core
 *
 * Trickbox REI_TARGET_CORE Register
 * This indicates the processor on which the associated value of REI is to be
 * driven into.  The target processor is the physical target processor
 * number.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_rei_target_core_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) This field indicates the physical target core number to which the REI is
                                                                 to be driven into. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) This field indicates the physical target core number to which the REI is
                                                                 to be driven into. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_rei_target_core_s cn; */
} bdk_tb_rei_target_core_t;

#define BDK_TB_REI_TARGET_CORE BDK_TB_REI_TARGET_CORE_FUNC()
static inline uint64_t BDK_TB_REI_TARGET_CORE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_REI_TARGET_CORE_FUNC(void)
{
    return 0x87e013000c40ll;
}

#define typedef_BDK_TB_REI_TARGET_CORE bdk_tb_rei_target_core_t
#define bustype_BDK_TB_REI_TARGET_CORE BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_REI_TARGET_CORE "TB_REI_TARGET_CORE"
#define busnum_BDK_TB_REI_TARGET_CORE 0
#define arguments_BDK_TB_REI_TARGET_CORE -1,-1,-1,-1

/**
 * Register (NCB32b) tb_rei_value
 *
 * Trickbox REI_VALUE Register
 * REI value
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_rei_value_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t value                 : 1;  /**< [  0:  0](R/W) - 0 indicates deassertion of associated REI
                                                                 - 1 indicates assertion of associated REI */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 1;  /**< [  0:  0](R/W) - 0 indicates deassertion of associated REI
                                                                 - 1 indicates assertion of associated REI */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_rei_value_s cn; */
} bdk_tb_rei_value_t;

#define BDK_TB_REI_VALUE BDK_TB_REI_VALUE_FUNC()
static inline uint64_t BDK_TB_REI_VALUE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_REI_VALUE_FUNC(void)
{
    return 0x87e013000c44ll;
}

#define typedef_BDK_TB_REI_VALUE bdk_tb_rei_value_t
#define bustype_BDK_TB_REI_VALUE BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_REI_VALUE "TB_REI_VALUE"
#define busnum_BDK_TB_REI_VALUE 0
#define arguments_BDK_TB_REI_VALUE -1,-1,-1,-1

/**
 * Register (NCB32b) tb_schedule_fiq
 *
 * Trickbox ScheduleFIQ Register
 * Write to ScheduleFIQ causes a trickbox to generate an FIQ into the
 * processor after the programmed number of cycles.  FIQ is asserted to
 * processors in TargetCPU.  The tests making use of the delay count does not
 * assume any significance of the programmed delay value.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_schedule_fiq_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) - Write is number of cycles to wait
                                                                 - Read is a bitmask where each bit is the status of FIQ for a core
                                                                 - NOTE: Current Implementation of AEM trickbox returns ORed FIQ Status for all cores in
                                                                 bit[0]. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) - Write is number of cycles to wait
                                                                 - Read is a bitmask where each bit is the status of FIQ for a core
                                                                 - NOTE: Current Implementation of AEM trickbox returns ORed FIQ Status for all cores in
                                                                 bit[0]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_schedule_fiq_s cn; */
} bdk_tb_schedule_fiq_t;

#define BDK_TB_SCHEDULE_FIQ BDK_TB_SCHEDULE_FIQ_FUNC()
static inline uint64_t BDK_TB_SCHEDULE_FIQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_SCHEDULE_FIQ_FUNC(void)
{
    return 0x87e013000008ll;
}

#define typedef_BDK_TB_SCHEDULE_FIQ bdk_tb_schedule_fiq_t
#define bustype_BDK_TB_SCHEDULE_FIQ BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_SCHEDULE_FIQ "TB_SCHEDULE_FIQ"
#define busnum_BDK_TB_SCHEDULE_FIQ 0
#define arguments_BDK_TB_SCHEDULE_FIQ -1,-1,-1,-1

/**
 * Register (NCB32b) tb_schedule_irq
 *
 * Trickbox ScheduleIRQ Register
 * A value of delay count is to be written into ScheduleIRQ register.  After
 * the specified delay count had elapsed, an IRQ will be asserted to
 * processors as specified in TargetCPU.  The tests making use of the delay
 * count does not assume any significance of the programmed delay value.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_schedule_irq_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) - Write is number of cycles to wait
                                                                 - Read is a bitmask where each bit is the status of FIQ for a core
                                                                 - NOTE: Current Implementation of AEM trickbox returns ORed FIQ Status for all cores in
                                                                 bit[0]. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) - Write is number of cycles to wait
                                                                 - Read is a bitmask where each bit is the status of FIQ for a core
                                                                 - NOTE: Current Implementation of AEM trickbox returns ORed FIQ Status for all cores in
                                                                 bit[0]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_schedule_irq_s cn; */
} bdk_tb_schedule_irq_t;

#define BDK_TB_SCHEDULE_IRQ BDK_TB_SCHEDULE_IRQ_FUNC()
static inline uint64_t BDK_TB_SCHEDULE_IRQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_SCHEDULE_IRQ_FUNC(void)
{
    return 0x87e01300000cll;
}

#define typedef_BDK_TB_SCHEDULE_IRQ bdk_tb_schedule_irq_t
#define bustype_BDK_TB_SCHEDULE_IRQ BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_SCHEDULE_IRQ "TB_SCHEDULE_IRQ"
#define busnum_BDK_TB_SCHEDULE_IRQ 0
#define arguments_BDK_TB_SCHEDULE_IRQ -1,-1,-1,-1

/**
 * Register (NCB32b) tb_schedule_rst
 *
 * Trickbox ScheduleRST Register
 * This register indicates the specified number of cycles after which an
 * associated reset as specified in SWResetCtl is applied on the processors
 * as defined by TargetCPU.
 *
 * Writing a value to ScheduleRST Value indicates number of cycles after
 * which RESET is generated to the associated processor.  If value is 0,
 * RESET is driven into immediately.  Drives RESET into the processors as
 * specified in the TargetCPU register.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_schedule_rst_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_schedule_rst_s cn; */
} bdk_tb_schedule_rst_t;

#define BDK_TB_SCHEDULE_RST BDK_TB_SCHEDULE_RST_FUNC()
static inline uint64_t BDK_TB_SCHEDULE_RST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_SCHEDULE_RST_FUNC(void)
{
    return 0x87e013000018ll;
}

#define typedef_BDK_TB_SCHEDULE_RST bdk_tb_schedule_rst_t
#define bustype_BDK_TB_SCHEDULE_RST BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_SCHEDULE_RST "TB_SCHEDULE_RST"
#define busnum_BDK_TB_SCHEDULE_RST 0
#define arguments_BDK_TB_SCHEDULE_RST -1,-1,-1,-1

/**
 * Register (NCB32b) tb_sei_ppi_rei_control
 *
 * Trickbox SEI_PPI_REI_CONTROL Register
 * TBD
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_sei_ppi_rei_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_5_31         : 27;
        uint32_t rei_en                : 1;  /**< [  4:  4](R/W) - 0 does not affect driving of REI interrupts
                                                                 - 1 drives REI interrupts */
        uint32_t sei_en                : 1;  /**< [  3:  3](R/W) - 0 does not affect driving of SEI interrupt
                                                                 - 1 drives SEI interrupt */
        uint32_t ppi_en                : 1;  /**< [  2:  2](R/W) - 0 does not affect driving of PPI interrupts
                                                                 - 1 drives PPI interrupts */
        uint32_t spi_en                : 1;  /**< [  1:  1](R/W) - 0 does not affect driving of SPI interrupts
                                                                 - 1 drives SPI interrupts */
        uint32_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0            : 1;
        uint32_t spi_en                : 1;  /**< [  1:  1](R/W) - 0 does not affect driving of SPI interrupts
                                                                 - 1 drives SPI interrupts */
        uint32_t ppi_en                : 1;  /**< [  2:  2](R/W) - 0 does not affect driving of PPI interrupts
                                                                 - 1 drives PPI interrupts */
        uint32_t sei_en                : 1;  /**< [  3:  3](R/W) - 0 does not affect driving of SEI interrupt
                                                                 - 1 drives SEI interrupt */
        uint32_t rei_en                : 1;  /**< [  4:  4](R/W) - 0 does not affect driving of REI interrupts
                                                                 - 1 drives REI interrupts */
        uint32_t reserved_5_31         : 27;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_sei_ppi_rei_control_s cn; */
} bdk_tb_sei_ppi_rei_control_t;

#define BDK_TB_SEI_PPI_REI_CONTROL BDK_TB_SEI_PPI_REI_CONTROL_FUNC()
static inline uint64_t BDK_TB_SEI_PPI_REI_CONTROL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_SEI_PPI_REI_CONTROL_FUNC(void)
{
    return 0x87e013000c80ll;
}

#define typedef_BDK_TB_SEI_PPI_REI_CONTROL bdk_tb_sei_ppi_rei_control_t
#define bustype_BDK_TB_SEI_PPI_REI_CONTROL BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_SEI_PPI_REI_CONTROL "TB_SEI_PPI_REI_CONTROL"
#define busnum_BDK_TB_SEI_PPI_REI_CONTROL 0
#define arguments_BDK_TB_SEI_PPI_REI_CONTROL -1,-1,-1,-1

/**
 * Register (NCB32b) tb_sei_target_core
 *
 * Trickbox SEI_TARGET_CORE Register
 * This indicates the processor on which the associated value of SEI is to be
 * driven into.  The target processor is the physical target processor
 * number.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_sei_target_core_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) This field indicates the physical target processor number to which the SEI
                                                                 is to be driven into. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) This field indicates the physical target processor number to which the SEI
                                                                 is to be driven into. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_sei_target_core_s cn; */
} bdk_tb_sei_target_core_t;

#define BDK_TB_SEI_TARGET_CORE BDK_TB_SEI_TARGET_CORE_FUNC()
static inline uint64_t BDK_TB_SEI_TARGET_CORE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_SEI_TARGET_CORE_FUNC(void)
{
    return 0x87e013000c60ll;
}

#define typedef_BDK_TB_SEI_TARGET_CORE bdk_tb_sei_target_core_t
#define bustype_BDK_TB_SEI_TARGET_CORE BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_SEI_TARGET_CORE "TB_SEI_TARGET_CORE"
#define busnum_BDK_TB_SEI_TARGET_CORE 0
#define arguments_BDK_TB_SEI_TARGET_CORE -1,-1,-1,-1

/**
 * Register (NCB32b) tb_sei_value
 *
 * Trickbox SEI_VALUE Register
 * SEI value
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_sei_value_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t value                 : 1;  /**< [  0:  0](R/W) - 0 indicates deassertion of associated SEI
                                                                 - 1 indicates assertion of associated SEI */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 1;  /**< [  0:  0](R/W) - 0 indicates deassertion of associated SEI
                                                                 - 1 indicates assertion of associated SEI */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_sei_value_s cn; */
} bdk_tb_sei_value_t;

#define BDK_TB_SEI_VALUE BDK_TB_SEI_VALUE_FUNC()
static inline uint64_t BDK_TB_SEI_VALUE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_SEI_VALUE_FUNC(void)
{
    return 0x87e013000c64ll;
}

#define typedef_BDK_TB_SEI_VALUE bdk_tb_sei_value_t
#define bustype_BDK_TB_SEI_VALUE BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_SEI_VALUE "TB_SEI_VALUE"
#define busnum_BDK_TB_SEI_VALUE 0
#define arguments_BDK_TB_SEI_VALUE -1,-1,-1,-1

/**
 * Register (NCB32b) tb_spi_group_index
 *
 * Trickbox SPI_GROUP_INDEX Register
 * This is a 32 bit register.  The possible values are based on the number of
 * registers present in the trick box.  The number of registers depends on
 * the number of SPI pins implemented by trickbox.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_spi_group_index_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Valid values are 1 to maximum number of 31. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Valid values are 1 to maximum number of 31. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_spi_group_index_s cn; */
} bdk_tb_spi_group_index_t;

#define BDK_TB_SPI_GROUP_INDEX BDK_TB_SPI_GROUP_INDEX_FUNC()
static inline uint64_t BDK_TB_SPI_GROUP_INDEX_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_SPI_GROUP_INDEX_FUNC(void)
{
    return 0x87e013000c00ll;
}

#define typedef_BDK_TB_SPI_GROUP_INDEX bdk_tb_spi_group_index_t
#define bustype_BDK_TB_SPI_GROUP_INDEX BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_SPI_GROUP_INDEX "TB_SPI_GROUP_INDEX"
#define busnum_BDK_TB_SPI_GROUP_INDEX 0
#define arguments_BDK_TB_SPI_GROUP_INDEX -1,-1,-1,-1

/**
 * Register (NCB32b) tb_spi_group_value
 *
 * Trickbox SPI_GROUP_VALUE Register
 * Each bit indicates the associated value of indexed SPI to be driven into
 * the processor.  996 SPI pins are to be implemented.
 * - For SPI_GROUP_INDEX = 0
 *     - bit[31:0] are reserved
 * - For SPI_GROUP_INDEX = 1
 *     - bit[0] is associated with SPI pin 0 with Interrupt ID 32
 *     - ...
 *     - bit[31] is associated with SPI pin 31 with Interrupt ID 63
 * - ...
 * - For SPI_GROUP_INDEX = 31
 *     - bit[0] is associated with SPI pin 960 with Interrupt ID 992
 *     - ...
 *     - bit[27] is associated with SPI pin 987 with Interrupt ID 1019
 *     - bit[31:27] is reserved
 * - 0 indicates assertion of associated SPI pin
 * - 1 indicates deassertion of associated SPI pin
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_spi_group_value_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_spi_group_value_s cn; */
} bdk_tb_spi_group_value_t;

#define BDK_TB_SPI_GROUP_VALUE BDK_TB_SPI_GROUP_VALUE_FUNC()
static inline uint64_t BDK_TB_SPI_GROUP_VALUE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_SPI_GROUP_VALUE_FUNC(void)
{
    return 0x87e013000c04ll;
}

#define typedef_BDK_TB_SPI_GROUP_VALUE bdk_tb_spi_group_value_t
#define bustype_BDK_TB_SPI_GROUP_VALUE BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_SPI_GROUP_VALUE "TB_SPI_GROUP_VALUE"
#define busnum_BDK_TB_SPI_GROUP_VALUE 0
#define arguments_BDK_TB_SPI_GROUP_VALUE -1,-1,-1,-1

/**
 * Register (NCB32b) tb_sw_reset_ctl
 *
 * Trickbox SW_RESET_CTL Register
 * Controls the type of reset sent to the processor as result of
 * write to ScheduleRST.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_sw_reset_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) - 0x0000_0001 Assert reset using nRESET.  This reset is applied to reset
                                                                 the warm reset domain of the specified processor excluding the auxiliary
                                                                 processor
                                                                 - 0x0000_0005 Assert reset using nRESET.  This reset is applied to reset
                                                                 the warm reset domain of the specified processor excluding the auxiliary
                                                                 processor
                                                                 - 0x2000_0005 Assert reset using nCOREPORESET.  This reset is applied to
                                                                 reset the cold reset domain of the specified processor excluding the
                                                                 auxiliary processor.
                                                                 - 0x0000_0011 Assert reset using nDBGRESET.  This reset is applied to
                                                                 reset the external debug reset domain of the processor, excluding the
                                                                 auxiliary processor
                                                                 - 0x0000_0015 Assert reset using nSYSPORESET.  Reset entire system,
                                                                 excluding auxiliary processor.
                                                                 - 0x0000_0004 Trace unit reset.  Resets all trace unit Trace registers and
                                                                 some management registers TRCOSLSR, TRCPDSR
                                                                 - 0x0000_0014 External trace reset.  Resets some trace unit management
                                                                 registers.
                                                                 - Any other value Reserved.
                                                                 - NOTE:
                                                                     - 1.  ScheduleRST will not have any effect if SWResetCtl contains a
                                                                     reserved value.
                                                                     - 2.  AXI reset is asserted on the first nSYSPORESET.  AXI reset is only
                                                                     asserted on subsequent assertions of nSYSPORESET, and assertion of nRESET,
                                                                     if the auxiliary processor is in reset.
                                                                     - 3.  Assertion and deassertion of nRESET and nSYSPORESET does not change
                                                                     the number of processors that are not in reset.  For example, initially,
                                                                     if one processor is not in reset and nCOREPORESET is used to bring another
                                                                     processor out of reset before nRESET is asserted, then both processors are
                                                                     out of reset when nRESET is deasserted. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) - 0x0000_0001 Assert reset using nRESET.  This reset is applied to reset
                                                                 the warm reset domain of the specified processor excluding the auxiliary
                                                                 processor
                                                                 - 0x0000_0005 Assert reset using nRESET.  This reset is applied to reset
                                                                 the warm reset domain of the specified processor excluding the auxiliary
                                                                 processor
                                                                 - 0x2000_0005 Assert reset using nCOREPORESET.  This reset is applied to
                                                                 reset the cold reset domain of the specified processor excluding the
                                                                 auxiliary processor.
                                                                 - 0x0000_0011 Assert reset using nDBGRESET.  This reset is applied to
                                                                 reset the external debug reset domain of the processor, excluding the
                                                                 auxiliary processor
                                                                 - 0x0000_0015 Assert reset using nSYSPORESET.  Reset entire system,
                                                                 excluding auxiliary processor.
                                                                 - 0x0000_0004 Trace unit reset.  Resets all trace unit Trace registers and
                                                                 some management registers TRCOSLSR, TRCPDSR
                                                                 - 0x0000_0014 External trace reset.  Resets some trace unit management
                                                                 registers.
                                                                 - Any other value Reserved.
                                                                 - NOTE:
                                                                     - 1.  ScheduleRST will not have any effect if SWResetCtl contains a
                                                                     reserved value.
                                                                     - 2.  AXI reset is asserted on the first nSYSPORESET.  AXI reset is only
                                                                     asserted on subsequent assertions of nSYSPORESET, and assertion of nRESET,
                                                                     if the auxiliary processor is in reset.
                                                                     - 3.  Assertion and deassertion of nRESET and nSYSPORESET does not change
                                                                     the number of processors that are not in reset.  For example, initially,
                                                                     if one processor is not in reset and nCOREPORESET is used to bring another
                                                                     processor out of reset before nRESET is asserted, then both processors are
                                                                     out of reset when nRESET is deasserted. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_sw_reset_ctl_s cn; */
} bdk_tb_sw_reset_ctl_t;

#define BDK_TB_SW_RESET_CTL BDK_TB_SW_RESET_CTL_FUNC()
static inline uint64_t BDK_TB_SW_RESET_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_SW_RESET_CTL_FUNC(void)
{
    return 0x87e013000520ll;
}

#define typedef_BDK_TB_SW_RESET_CTL bdk_tb_sw_reset_ctl_t
#define bustype_BDK_TB_SW_RESET_CTL BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_SW_RESET_CTL "TB_SW_RESET_CTL"
#define busnum_BDK_TB_SW_RESET_CTL 0
#define arguments_BDK_TB_SW_RESET_CTL -1,-1,-1,-1

/**
 * Register (NCB32b) tb_target_cpu
 *
 * Trickbox TargetCPU Register
 * This register specifies the processor on which an associated event is to
 * be generated.  It indicates the processor to which the pins IRQ, FIQ or
 * debug controls are associated.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_target_cpu_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t mask                  : 32; /**< [ 31:  0](R/W) - 0 - associated processor is not participating in the control operation.
                                                                 - 1 - Associated processor participates in the control operation. */
#else /* Word 0 - Little Endian */
        uint32_t mask                  : 32; /**< [ 31:  0](R/W) - 0 - associated processor is not participating in the control operation.
                                                                 - 1 - Associated processor participates in the control operation. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_target_cpu_s cn; */
} bdk_tb_target_cpu_t;

#define BDK_TB_TARGET_CPU BDK_TB_TARGET_CPU_FUNC()
static inline uint64_t BDK_TB_TARGET_CPU_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_TARGET_CPU_FUNC(void)
{
    return 0x87e0130000fcll;
}

#define typedef_BDK_TB_TARGET_CPU bdk_tb_target_cpu_t
#define bustype_BDK_TB_TARGET_CPU BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_TARGET_CPU "TB_TARGET_CPU"
#define busnum_BDK_TB_TARGET_CPU 0
#define arguments_BDK_TB_TARGET_CPU -1,-1,-1,-1

/**
 * Register (NCB32b) tb_tube
 *
 * Trickbox Tube Register
 * Tube is used to display any characters being output by the test.  The tube
 * output is later used for post processing by validation script.  The data
 * should be written as a byte and not of any other size.  Any printable
 * ASCII character can be passed to the tube.  If character Ctrl+D (ASCII
 * value of 4) is passed to tube, then this indicates to the environment to
 * stop the test and terminate the simulation.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_tube_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t value                 : 8;  /**< [  7:  0](R/W) Denotes the ASCII character to be printed. CTRL+D ends the simulation. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 8;  /**< [  7:  0](R/W) Denotes the ASCII character to be printed. CTRL+D ends the simulation. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_tube_s cn; */
} bdk_tb_tube_t;

#define BDK_TB_TUBE BDK_TB_TUBE_FUNC()
static inline uint64_t BDK_TB_TUBE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_TUBE_FUNC(void)
{
    return 0x87e013000000ll;
}

#define typedef_BDK_TB_TUBE bdk_tb_tube_t
#define bustype_BDK_TB_TUBE BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_TUBE "TB_TUBE"
#define busnum_BDK_TB_TUBE 0
#define arguments_BDK_TB_TUBE -1,-1,-1,-1

/**
 * Register (NCB32b) tb_watchdog
 *
 * Trickbox Watchdog Register
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * System watchdog implements a mechanism in which the simulation is forced
 * to end on reaching 0.  The system watchdog counter is a countdown counter.
 */
typedef union
{
    uint32_t u;
    struct bdk_tb_watchdog_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t breakvalue            : 32; /**< [ 31:  0](R/W) A read from this register returns the current countdown value of the
                                                                 watchdog timer

                                                                 A write of 0xffff_ffff disables the watch dog time.  Any another value
                                                                 written to this register enables the watchdog timer and starts the timer.
                                                                 Simulation is to be terminated on reaching a count value of 0. */
#else /* Word 0 - Little Endian */
        uint32_t breakvalue            : 32; /**< [ 31:  0](R/W) A read from this register returns the current countdown value of the
                                                                 watchdog timer

                                                                 A write of 0xffff_ffff disables the watch dog time.  Any another value
                                                                 written to this register enables the watchdog timer and starts the timer.
                                                                 Simulation is to be terminated on reaching a count value of 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_tb_watchdog_s cn; */
} bdk_tb_watchdog_t;

#define BDK_TB_WATCHDOG BDK_TB_WATCHDOG_FUNC()
static inline uint64_t BDK_TB_WATCHDOG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TB_WATCHDOG_FUNC(void)
{
    return 0x87e013000284ll;
}

#define typedef_BDK_TB_WATCHDOG bdk_tb_watchdog_t
#define bustype_BDK_TB_WATCHDOG BDK_CSR_TYPE_NCB32b
#define basename_BDK_TB_WATCHDOG "TB_WATCHDOG"
#define busnum_BDK_TB_WATCHDOG 0
#define arguments_BDK_TB_WATCHDOG -1,-1,-1,-1

#endif /* __BDK_CSRS_TRICKBOX_H__ */
