#ifndef __BDK_CSRS_GTI_H__
#define __BDK_CSRS_GTI_H__
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
 * Cavium GTI.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration gti_bar_e
 *
 * GTI Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_GTI_BAR_E_GTI_PF_BAR0 (0x844000000000ll) /**< Base address for standard registers. */
#define BDK_GTI_BAR_E_GTI_PF_BAR4 (0x84400f000000ll) /**< Base address for MSI-X registers. */

/**
 * Enumeration gti_int_vec_e
 *
 * GTI MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_GTI_INT_VEC_E_CORE_WDOGX_DEL3T(a) (0xa + (a)) /**< (0..47)Note that GTI_CWD_WDOG(<a>) sets the DEL3T too.
                                       See interrupt clears GTI_CWD_DEL3T[CORE<{a}>],
                                       interrupt sets GTI_CWD_DEL3T_SET[CORE<{a}>],
                                       enable clears GTI_CWD_DEL3T_ENA_CLR[CORE<{a}>],
                                       and enable sets GTI_CWD_DEL3T_ENA_SET[CORE<{a}>]. */
#define BDK_GTI_INT_VEC_E_CORE_WDOGX_INT(a) (0x3a + (a)) /**< (0..47)Note that GTI_CWD_WDOG(<a>) sets the INT too.
                                       See interrupt clears GTI_CWD_INT[CORE<{a}>],
                                       interrupt sets GTI_CWD_INT_SET[CORE<{a}>],
                                       enable clears GTI_CWD_INT_ENA_CLR[CORE<{a}>],
                                       and enable sets GTI_CWD_INT_ENA_SET[CORE<{a}>]. */
#define BDK_GTI_INT_VEC_E_ERROR (8) /**< See interrupt clears GTI_ERR_INT, interrupt sets GTI_ERR_INT_SET,
                                       enable clears GTI_ERR_INT_ENA_CLR, and enable sets GTI_ERR_INT_ENA_SET. */
#define BDK_GTI_INT_VEC_E_MAILBOX_RX (7) /**< Timestamp mailbox has been transmitted.
                                       See interrupt clears GTI_CC_CNTMB_INT[MBRX],
                                       interrupt sets GTI_CC_CNTMB_INT_SET[MBRX],
                                       enable clears GTI_CC_CNTMB_INT_ENA_CLR[MBRX],
                                       and enable sets GTI_CC_CNTMB_INT_ENA_SET[MBRX]. */
#define BDK_GTI_INT_VEC_E_SECURE_WATCHDOG (4) /**< Secure watchdog (watchdog 0) interrupt. */
#define BDK_GTI_INT_VEC_E_SECURE_WATCHDOG_CLEAR (5) /**< Level sensitive interrupt clear vector. */
#define BDK_GTI_INT_VEC_E_SPARE (9) /**< Reserved. */
#define BDK_GTI_INT_VEC_E_TX_TIMESTAMP (6) /**< Timestamp mailbox has been transmitted.
                                       See interrupt clears GTI_CC_CNTMB_INT[TXTS],
                                       interrupt sets GTI_CC_CNTMB_INT_SET[TXTS],
                                       enable clears GTI_CC_CNTMB_INT_ENA_CLR[TXTS],
                                       and enable sets GTI_CC_CNTMB_INT_ENA_SET[TXTS]. */
#define BDK_GTI_INT_VEC_E_WAKE (0) /**< Wakeup interrupt. */
#define BDK_GTI_INT_VEC_E_WAKE_CLEAR (1) /**< Level sensitive interrupt clear vector. */
#define BDK_GTI_INT_VEC_E_WATCHDOG (2) /**< Non-secure watchdog (watchdog 1) interrupt. */
#define BDK_GTI_INT_VEC_E_WATCHDOG_CLEAR (3) /**< Level sensitive interrupt clear vector. */

/**
 * Register (NCB32b) gti_bz_cidr0
 *
 * GTI Base Component Identification Register 0
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_bz_cidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_cidr0_s cn; */
} bdk_gti_bz_cidr0_t;

#define BDK_GTI_BZ_CIDR0 BDK_GTI_BZ_CIDR0_FUNC()
static inline uint64_t BDK_GTI_BZ_CIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_CIDR0_FUNC(void)
{
    return 0x844000030ff0ll;
}

#define typedef_BDK_GTI_BZ_CIDR0 bdk_gti_bz_cidr0_t
#define bustype_BDK_GTI_BZ_CIDR0 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_BZ_CIDR0 "GTI_BZ_CIDR0"
#define busnum_BDK_GTI_BZ_CIDR0 0
#define arguments_BDK_GTI_BZ_CIDR0 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_bz_cidr1
 *
 * GTI Base Component Identification Register 1
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_bz_cidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cclass                : 4;  /**< [  7:  4](RO) Component class. */
        uint32_t preamble              : 4;  /**< [  3:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 4;  /**< [  3:  0](RO) Preamble identification value. */
        uint32_t cclass                : 4;  /**< [  7:  4](RO) Component class. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_cidr1_s cn; */
} bdk_gti_bz_cidr1_t;

#define BDK_GTI_BZ_CIDR1 BDK_GTI_BZ_CIDR1_FUNC()
static inline uint64_t BDK_GTI_BZ_CIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_CIDR1_FUNC(void)
{
    return 0x844000030ff4ll;
}

#define typedef_BDK_GTI_BZ_CIDR1 bdk_gti_bz_cidr1_t
#define bustype_BDK_GTI_BZ_CIDR1 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_BZ_CIDR1 "GTI_BZ_CIDR1"
#define busnum_BDK_GTI_BZ_CIDR1 0
#define arguments_BDK_GTI_BZ_CIDR1 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_bz_cidr2
 *
 * GTI Base Component Identification Register 2
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_bz_cidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_cidr2_s cn; */
} bdk_gti_bz_cidr2_t;

#define BDK_GTI_BZ_CIDR2 BDK_GTI_BZ_CIDR2_FUNC()
static inline uint64_t BDK_GTI_BZ_CIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_CIDR2_FUNC(void)
{
    return 0x844000030ff8ll;
}

#define typedef_BDK_GTI_BZ_CIDR2 bdk_gti_bz_cidr2_t
#define bustype_BDK_GTI_BZ_CIDR2 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_BZ_CIDR2 "GTI_BZ_CIDR2"
#define busnum_BDK_GTI_BZ_CIDR2 0
#define arguments_BDK_GTI_BZ_CIDR2 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_bz_cidr3
 *
 * GTI Base Component Identification Register 3
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_bz_cidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_cidr3_s cn; */
} bdk_gti_bz_cidr3_t;

#define BDK_GTI_BZ_CIDR3 BDK_GTI_BZ_CIDR3_FUNC()
static inline uint64_t BDK_GTI_BZ_CIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_CIDR3_FUNC(void)
{
    return 0x844000030ffcll;
}

#define typedef_BDK_GTI_BZ_CIDR3 bdk_gti_bz_cidr3_t
#define bustype_BDK_GTI_BZ_CIDR3 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_BZ_CIDR3 "GTI_BZ_CIDR3"
#define busnum_BDK_GTI_BZ_CIDR3 0
#define arguments_BDK_GTI_BZ_CIDR3 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_bz_cntp_ctl
 *
 * GTI Base Physical Timer Control Register
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_bz_cntp_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_3_31         : 29;
        uint32_t istatus               : 1;  /**< [  2:  2](RO/H) Status. */
        uint32_t imask                 : 1;  /**< [  1:  1](R/W) Mask. */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) Enable. */
#else /* Word 0 - Little Endian */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) Enable. */
        uint32_t imask                 : 1;  /**< [  1:  1](R/W) Mask. */
        uint32_t istatus               : 1;  /**< [  2:  2](RO/H) Status. */
        uint32_t reserved_3_31         : 29;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_cntp_ctl_s cn; */
} bdk_gti_bz_cntp_ctl_t;

#define BDK_GTI_BZ_CNTP_CTL BDK_GTI_BZ_CNTP_CTL_FUNC()
static inline uint64_t BDK_GTI_BZ_CNTP_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_CNTP_CTL_FUNC(void)
{
    return 0x84400003002cll;
}

#define typedef_BDK_GTI_BZ_CNTP_CTL bdk_gti_bz_cntp_ctl_t
#define bustype_BDK_GTI_BZ_CNTP_CTL BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_BZ_CNTP_CTL "GTI_BZ_CNTP_CTL"
#define busnum_BDK_GTI_BZ_CNTP_CTL 0
#define arguments_BDK_GTI_BZ_CNTP_CTL -1,-1,-1,-1

/**
 * Register (NCB) gti_bz_cntp_cval
 *
 * GTI Base Physical Timer Compare Value Register
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_bz_cntp_cval_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Physical Timer compare value. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Physical Timer compare value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_cntp_cval_s cn; */
} bdk_gti_bz_cntp_cval_t;

#define BDK_GTI_BZ_CNTP_CVAL BDK_GTI_BZ_CNTP_CVAL_FUNC()
static inline uint64_t BDK_GTI_BZ_CNTP_CVAL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_CNTP_CVAL_FUNC(void)
{
    return 0x844000030020ll;
}

#define typedef_BDK_GTI_BZ_CNTP_CVAL bdk_gti_bz_cntp_cval_t
#define bustype_BDK_GTI_BZ_CNTP_CVAL BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_BZ_CNTP_CVAL "GTI_BZ_CNTP_CVAL"
#define busnum_BDK_GTI_BZ_CNTP_CVAL 0
#define arguments_BDK_GTI_BZ_CNTP_CVAL -1,-1,-1,-1

/**
 * Register (NCB32b) gti_bz_cntp_tval
 *
 * GTI Base Physical Timer Timer Value Register
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_bz_cntp_tval_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t timervalue            : 32; /**< [ 31:  0](R/W/H) Physical Timer timer value. */
#else /* Word 0 - Little Endian */
        uint32_t timervalue            : 32; /**< [ 31:  0](R/W/H) Physical Timer timer value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_cntp_tval_s cn; */
} bdk_gti_bz_cntp_tval_t;

#define BDK_GTI_BZ_CNTP_TVAL BDK_GTI_BZ_CNTP_TVAL_FUNC()
static inline uint64_t BDK_GTI_BZ_CNTP_TVAL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_CNTP_TVAL_FUNC(void)
{
    return 0x844000030028ll;
}

#define typedef_BDK_GTI_BZ_CNTP_TVAL bdk_gti_bz_cntp_tval_t
#define bustype_BDK_GTI_BZ_CNTP_TVAL BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_BZ_CNTP_TVAL "GTI_BZ_CNTP_TVAL"
#define busnum_BDK_GTI_BZ_CNTP_TVAL 0
#define arguments_BDK_GTI_BZ_CNTP_TVAL -1,-1,-1,-1

/**
 * Register (NCB32b) gti_bz_pidr0
 *
 * GTI Base Peripheral Identification Register 0
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_bz_pidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t partnum0              : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_BZ. */
#else /* Word 0 - Little Endian */
        uint32_t partnum0              : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_BZ. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_pidr0_s cn; */
} bdk_gti_bz_pidr0_t;

#define BDK_GTI_BZ_PIDR0 BDK_GTI_BZ_PIDR0_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR0_FUNC(void)
{
    return 0x844000030fe0ll;
}

#define typedef_BDK_GTI_BZ_PIDR0 bdk_gti_bz_pidr0_t
#define bustype_BDK_GTI_BZ_PIDR0 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_BZ_PIDR0 "GTI_BZ_PIDR0"
#define busnum_BDK_GTI_BZ_PIDR0 0
#define arguments_BDK_GTI_BZ_PIDR0 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_bz_pidr1
 *
 * GTI Base Peripheral Identification Register 1
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_bz_pidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t idcode                : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t partnum1              : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else /* Word 0 - Little Endian */
        uint32_t partnum1              : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
        uint32_t idcode                : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_pidr1_s cn; */
} bdk_gti_bz_pidr1_t;

#define BDK_GTI_BZ_PIDR1 BDK_GTI_BZ_PIDR1_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR1_FUNC(void)
{
    return 0x844000030fe4ll;
}

#define typedef_BDK_GTI_BZ_PIDR1 bdk_gti_bz_pidr1_t
#define bustype_BDK_GTI_BZ_PIDR1 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_BZ_PIDR1 "GTI_BZ_PIDR1"
#define busnum_BDK_GTI_BZ_PIDR1 0
#define arguments_BDK_GTI_BZ_PIDR1 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_bz_pidr2
 *
 * GTI Base Peripheral Identification Register 2
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_bz_pidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revision              : 4;  /**< [  7:  4](RO) Architectural revision, as assigned by ARM. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t idcode                : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else /* Word 0 - Little Endian */
        uint32_t idcode                : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t revision              : 4;  /**< [  7:  4](RO) Architectural revision, as assigned by ARM. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_pidr2_s cn; */
} bdk_gti_bz_pidr2_t;

#define BDK_GTI_BZ_PIDR2 BDK_GTI_BZ_PIDR2_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR2_FUNC(void)
{
    return 0x844000030fe8ll;
}

#define typedef_BDK_GTI_BZ_PIDR2 bdk_gti_bz_pidr2_t
#define bustype_BDK_GTI_BZ_PIDR2 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_BZ_PIDR2 "GTI_BZ_PIDR2"
#define busnum_BDK_GTI_BZ_PIDR2 0
#define arguments_BDK_GTI_BZ_PIDR2 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_bz_pidr3
 *
 * GTI Base Peripheral Identification Register 3
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_bz_pidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t cust                  : 4;  /**< [  3:  0](RO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else /* Word 0 - Little Endian */
        uint32_t cust                  : 4;  /**< [  3:  0](RO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_pidr3_s cn; */
} bdk_gti_bz_pidr3_t;

#define BDK_GTI_BZ_PIDR3 BDK_GTI_BZ_PIDR3_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR3_FUNC(void)
{
    return 0x844000030fecll;
}

#define typedef_BDK_GTI_BZ_PIDR3 bdk_gti_bz_pidr3_t
#define bustype_BDK_GTI_BZ_PIDR3 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_BZ_PIDR3 "GTI_BZ_PIDR3"
#define busnum_BDK_GTI_BZ_PIDR3 0
#define arguments_BDK_GTI_BZ_PIDR3 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_bz_pidr4
 *
 * GTI Base Peripheral Identification Register 4
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_bz_pidr4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t pagecnt               : 4;  /**< [  7:  4](RO) Number of log-2 4 KB blocks occupied. */
        uint32_t jepcont               : 4;  /**< [  3:  0](RO) JEP106 continuation code. Indicates Cavium. */
#else /* Word 0 - Little Endian */
        uint32_t jepcont               : 4;  /**< [  3:  0](RO) JEP106 continuation code. Indicates Cavium. */
        uint32_t pagecnt               : 4;  /**< [  7:  4](RO) Number of log-2 4 KB blocks occupied. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_pidr4_s cn; */
} bdk_gti_bz_pidr4_t;

#define BDK_GTI_BZ_PIDR4 BDK_GTI_BZ_PIDR4_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR4_FUNC(void)
{
    return 0x844000030fd0ll;
}

#define typedef_BDK_GTI_BZ_PIDR4 bdk_gti_bz_pidr4_t
#define bustype_BDK_GTI_BZ_PIDR4 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_BZ_PIDR4 "GTI_BZ_PIDR4"
#define busnum_BDK_GTI_BZ_PIDR4 0
#define arguments_BDK_GTI_BZ_PIDR4 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_bz_pidr5
 *
 * GTI Base Peripheral Identification Register 5
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_bz_pidr5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_pidr5_s cn; */
} bdk_gti_bz_pidr5_t;

#define BDK_GTI_BZ_PIDR5 BDK_GTI_BZ_PIDR5_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR5_FUNC(void)
{
    return 0x844000030fd4ll;
}

#define typedef_BDK_GTI_BZ_PIDR5 bdk_gti_bz_pidr5_t
#define bustype_BDK_GTI_BZ_PIDR5 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_BZ_PIDR5 "GTI_BZ_PIDR5"
#define busnum_BDK_GTI_BZ_PIDR5 0
#define arguments_BDK_GTI_BZ_PIDR5 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_bz_pidr6
 *
 * GTI Base Peripheral Identification Register 6
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_bz_pidr6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_pidr6_s cn; */
} bdk_gti_bz_pidr6_t;

#define BDK_GTI_BZ_PIDR6 BDK_GTI_BZ_PIDR6_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR6_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR6_FUNC(void)
{
    return 0x844000030fd8ll;
}

#define typedef_BDK_GTI_BZ_PIDR6 bdk_gti_bz_pidr6_t
#define bustype_BDK_GTI_BZ_PIDR6 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_BZ_PIDR6 "GTI_BZ_PIDR6"
#define busnum_BDK_GTI_BZ_PIDR6 0
#define arguments_BDK_GTI_BZ_PIDR6 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_bz_pidr7
 *
 * GTI Base Peripheral Identification Register 7
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_bz_pidr7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_bz_pidr7_s cn; */
} bdk_gti_bz_pidr7_t;

#define BDK_GTI_BZ_PIDR7 BDK_GTI_BZ_PIDR7_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR7_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR7_FUNC(void)
{
    return 0x844000030fdcll;
}

#define typedef_BDK_GTI_BZ_PIDR7 bdk_gti_bz_pidr7_t
#define bustype_BDK_GTI_BZ_PIDR7 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_BZ_PIDR7 "GTI_BZ_PIDR7"
#define busnum_BDK_GTI_BZ_PIDR7 0
#define arguments_BDK_GTI_BZ_PIDR7 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_cidr0
 *
 * GTI Counter Control Component Identification Secure Register 0
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_cidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](SRO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](SRO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cidr0_s cn; */
} bdk_gti_cc_cidr0_t;

#define BDK_GTI_CC_CIDR0 BDK_GTI_CC_CIDR0_FUNC()
static inline uint64_t BDK_GTI_CC_CIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CIDR0_FUNC(void)
{
    return 0x844000000ff0ll;
}

#define typedef_BDK_GTI_CC_CIDR0 bdk_gti_cc_cidr0_t
#define bustype_BDK_GTI_CC_CIDR0 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_CIDR0 "GTI_CC_CIDR0"
#define busnum_BDK_GTI_CC_CIDR0 0
#define arguments_BDK_GTI_CC_CIDR0 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_cidr1
 *
 * GTI Counter Control Component Identification Secure Register 1
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_cidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cclass                : 4;  /**< [  7:  4](SRO) Component class. */
        uint32_t preamble              : 4;  /**< [  3:  0](SRO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 4;  /**< [  3:  0](SRO) Preamble identification value. */
        uint32_t cclass                : 4;  /**< [  7:  4](SRO) Component class. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cidr1_s cn; */
} bdk_gti_cc_cidr1_t;

#define BDK_GTI_CC_CIDR1 BDK_GTI_CC_CIDR1_FUNC()
static inline uint64_t BDK_GTI_CC_CIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CIDR1_FUNC(void)
{
    return 0x844000000ff4ll;
}

#define typedef_BDK_GTI_CC_CIDR1 bdk_gti_cc_cidr1_t
#define bustype_BDK_GTI_CC_CIDR1 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_CIDR1 "GTI_CC_CIDR1"
#define busnum_BDK_GTI_CC_CIDR1 0
#define arguments_BDK_GTI_CC_CIDR1 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_cidr2
 *
 * GTI Counter Control Component Identification Secure Register 2
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_cidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](SRO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](SRO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cidr2_s cn; */
} bdk_gti_cc_cidr2_t;

#define BDK_GTI_CC_CIDR2 BDK_GTI_CC_CIDR2_FUNC()
static inline uint64_t BDK_GTI_CC_CIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CIDR2_FUNC(void)
{
    return 0x844000000ff8ll;
}

#define typedef_BDK_GTI_CC_CIDR2 bdk_gti_cc_cidr2_t
#define bustype_BDK_GTI_CC_CIDR2 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_CIDR2 "GTI_CC_CIDR2"
#define busnum_BDK_GTI_CC_CIDR2 0
#define arguments_BDK_GTI_CC_CIDR2 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_cidr3
 *
 * GTI Counter Control Component Identification Secure Register 3
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_cidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](SRO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](SRO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cidr3_s cn; */
} bdk_gti_cc_cidr3_t;

#define BDK_GTI_CC_CIDR3 BDK_GTI_CC_CIDR3_FUNC()
static inline uint64_t BDK_GTI_CC_CIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CIDR3_FUNC(void)
{
    return 0x844000000ffcll;
}

#define typedef_BDK_GTI_CC_CIDR3 bdk_gti_cc_cidr3_t
#define bustype_BDK_GTI_CC_CIDR3 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_CIDR3 "GTI_CC_CIDR3"
#define busnum_BDK_GTI_CC_CIDR3 0
#define arguments_BDK_GTI_CC_CIDR3 -1,-1,-1,-1

/**
 * Register (NCB) gti_cc_cntadd
 *
 * GTI Counter Control Atomic Add Secure Register
 * Implementation defined register.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cc_cntadd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cntadd                : 64; /**< [ 63:  0](SWO) The value written to CNTADD is atomically added to GTI_CC_CNTCV. */
#else /* Word 0 - Little Endian */
        uint64_t cntadd                : 64; /**< [ 63:  0](SWO) The value written to CNTADD is atomically added to GTI_CC_CNTCV. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cntadd_s cn; */
} bdk_gti_cc_cntadd_t;

#define BDK_GTI_CC_CNTADD BDK_GTI_CC_CNTADD_FUNC()
static inline uint64_t BDK_GTI_CC_CNTADD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTADD_FUNC(void)
{
    return 0x8440000000c8ll;
}

#define typedef_BDK_GTI_CC_CNTADD bdk_gti_cc_cntadd_t
#define bustype_BDK_GTI_CC_CNTADD BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CC_CNTADD "GTI_CC_CNTADD"
#define busnum_BDK_GTI_CC_CNTADD 0
#define arguments_BDK_GTI_CC_CNTADD -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_cntcr
 *
 * GTI Counter Control Secure Register
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_cntcr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t fcreq                 : 1;  /**< [  8:  8](SR/W) Frequency change request. Indicates the number of the entry in the frequency
                                                                 table to select. Selecting an unimplemented entry, or an entry that contains
                                                                 0x0, has no effect on the counter.

                                                                 For CNXXXX, which implements a single frequency table entry, must be 0x0. */
        uint32_t reserved_2_7          : 6;
        uint32_t hdbg                  : 1;  /**< [  1:  1](SR/W) System counter halt-on-debug enable.
                                                                 0 = System counter ignores halt-on-debug.
                                                                 1 = Asserted halt-on-debug signal halts system counter update. */
        uint32_t en                    : 1;  /**< [  0:  0](SR/W) Enables the system counter. */
#else /* Word 0 - Little Endian */
        uint32_t en                    : 1;  /**< [  0:  0](SR/W) Enables the system counter. */
        uint32_t hdbg                  : 1;  /**< [  1:  1](SR/W) System counter halt-on-debug enable.
                                                                 0 = System counter ignores halt-on-debug.
                                                                 1 = Asserted halt-on-debug signal halts system counter update. */
        uint32_t reserved_2_7          : 6;
        uint32_t fcreq                 : 1;  /**< [  8:  8](SR/W) Frequency change request. Indicates the number of the entry in the frequency
                                                                 table to select. Selecting an unimplemented entry, or an entry that contains
                                                                 0x0, has no effect on the counter.

                                                                 For CNXXXX, which implements a single frequency table entry, must be 0x0. */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cntcr_s cn; */
} bdk_gti_cc_cntcr_t;

#define BDK_GTI_CC_CNTCR BDK_GTI_CC_CNTCR_FUNC()
static inline uint64_t BDK_GTI_CC_CNTCR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTCR_FUNC(void)
{
    return 0x844000000000ll;
}

#define typedef_BDK_GTI_CC_CNTCR bdk_gti_cc_cntcr_t
#define bustype_BDK_GTI_CC_CNTCR BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_CNTCR "GTI_CC_CNTCR"
#define busnum_BDK_GTI_CC_CNTCR 0
#define arguments_BDK_GTI_CC_CNTCR -1,-1,-1,-1

/**
 * Register (NCB) gti_cc_cntcv
 *
 * GTI Counter Control Count Value Secure Register
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cc_cntcv_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](SR/W/H) System counter count value. The counter is also read-only accessable by the
                                                                 non-secure world with GTI_RD_CNTCV. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](SR/W/H) System counter count value. The counter is also read-only accessable by the
                                                                 non-secure world with GTI_RD_CNTCV. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cntcv_s cn; */
} bdk_gti_cc_cntcv_t;

#define BDK_GTI_CC_CNTCV BDK_GTI_CC_CNTCV_FUNC()
static inline uint64_t BDK_GTI_CC_CNTCV_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTCV_FUNC(void)
{
    return 0x844000000008ll;
}

#define typedef_BDK_GTI_CC_CNTCV bdk_gti_cc_cntcv_t
#define bustype_BDK_GTI_CC_CNTCV BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CC_CNTCV "GTI_CC_CNTCV"
#define busnum_BDK_GTI_CC_CNTCV 0
#define arguments_BDK_GTI_CC_CNTCV -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_cntfid0
 *
 * GTI Counter Control Frequency Mode Table Secure Register 0
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_cntfid0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t data                  : 32; /**< [ 31:  0](SR/W) Generic timer frequency mode table, index 1.
                                                                 Programmed by boot software with the system counter clock frequency in Hertz.
                                                                 See also GTI_CTL_CNTFRQ. */
#else /* Word 0 - Little Endian */
        uint32_t data                  : 32; /**< [ 31:  0](SR/W) Generic timer frequency mode table, index 1.
                                                                 Programmed by boot software with the system counter clock frequency in Hertz.
                                                                 See also GTI_CTL_CNTFRQ. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cntfid0_s cn; */
} bdk_gti_cc_cntfid0_t;

#define BDK_GTI_CC_CNTFID0 BDK_GTI_CC_CNTFID0_FUNC()
static inline uint64_t BDK_GTI_CC_CNTFID0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTFID0_FUNC(void)
{
    return 0x844000000020ll;
}

#define typedef_BDK_GTI_CC_CNTFID0 bdk_gti_cc_cntfid0_t
#define bustype_BDK_GTI_CC_CNTFID0 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_CNTFID0 "GTI_CC_CNTFID0"
#define busnum_BDK_GTI_CC_CNTFID0 0
#define arguments_BDK_GTI_CC_CNTFID0 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_cntfid1
 *
 * GTI Counter Control Frequency Mode Table Secure Register 1
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_cntfid1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t constant              : 32; /**< [ 31:  0](SRO) Generic timer frequency mode table, index 1. Zero to mark the end of the table. */
#else /* Word 0 - Little Endian */
        uint32_t constant              : 32; /**< [ 31:  0](SRO) Generic timer frequency mode table, index 1. Zero to mark the end of the table. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cntfid1_s cn; */
} bdk_gti_cc_cntfid1_t;

#define BDK_GTI_CC_CNTFID1 BDK_GTI_CC_CNTFID1_FUNC()
static inline uint64_t BDK_GTI_CC_CNTFID1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTFID1_FUNC(void)
{
    return 0x844000000024ll;
}

#define typedef_BDK_GTI_CC_CNTFID1 bdk_gti_cc_cntfid1_t
#define bustype_BDK_GTI_CC_CNTFID1 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_CNTFID1 "GTI_CC_CNTFID1"
#define busnum_BDK_GTI_CC_CNTFID1 0
#define arguments_BDK_GTI_CC_CNTFID1 -1,-1,-1,-1

/**
 * Register (NCB) gti_cc_cntmb
 *
 * GTI Counter Control Mailbox Secure Register
 * Implementation defined register.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cc_cntmb_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](SR/W) When written, GTI_CC_CNTCV is saved in GTI_CC_CNTMBTS. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](SR/W) When written, GTI_CC_CNTCV is saved in GTI_CC_CNTMBTS. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cntmb_s cn; */
} bdk_gti_cc_cntmb_t;

#define BDK_GTI_CC_CNTMB BDK_GTI_CC_CNTMB_FUNC()
static inline uint64_t BDK_GTI_CC_CNTMB_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTMB_FUNC(void)
{
    return 0x8440000000d0ll;
}

#define typedef_BDK_GTI_CC_CNTMB bdk_gti_cc_cntmb_t
#define bustype_BDK_GTI_CC_CNTMB BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CC_CNTMB "GTI_CC_CNTMB"
#define busnum_BDK_GTI_CC_CNTMB 0
#define arguments_BDK_GTI_CC_CNTMB -1,-1,-1,-1

/**
 * Register (NCB) gti_cc_cntmb_int
 *
 * GTI Counter Control Mailbox Interrupt Register
 * Implementation defined register.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cc_cntmb_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t mbrx                  : 1;  /**< [  1:  1](SR/W1C/H) Mailbox receive interrupt. */
        uint64_t txts                  : 1;  /**< [  0:  0](SR/W1C/H) Transmit timestamp interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t txts                  : 1;  /**< [  0:  0](SR/W1C/H) Transmit timestamp interrupt. */
        uint64_t mbrx                  : 1;  /**< [  1:  1](SR/W1C/H) Mailbox receive interrupt. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cntmb_int_s cn; */
} bdk_gti_cc_cntmb_int_t;

#define BDK_GTI_CC_CNTMB_INT BDK_GTI_CC_CNTMB_INT_FUNC()
static inline uint64_t BDK_GTI_CC_CNTMB_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTMB_INT_FUNC(void)
{
    return 0x8440000000e0ll;
}

#define typedef_BDK_GTI_CC_CNTMB_INT bdk_gti_cc_cntmb_int_t
#define bustype_BDK_GTI_CC_CNTMB_INT BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CC_CNTMB_INT "GTI_CC_CNTMB_INT"
#define busnum_BDK_GTI_CC_CNTMB_INT 0
#define arguments_BDK_GTI_CC_CNTMB_INT -1,-1,-1,-1

/**
 * Register (NCB) gti_cc_cntmb_int_ena_clr
 *
 * GTI Counter Control Mailbox Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cc_cntmb_int_ena_clr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t mbrx                  : 1;  /**< [  1:  1](SR/W1C/H) Reads or clears enable for GTI_CC_CNTMB_INT[MBRX]. */
        uint64_t txts                  : 1;  /**< [  0:  0](SR/W1C/H) Reads or clears enable for GTI_CC_CNTMB_INT[TXTS]. */
#else /* Word 0 - Little Endian */
        uint64_t txts                  : 1;  /**< [  0:  0](SR/W1C/H) Reads or clears enable for GTI_CC_CNTMB_INT[TXTS]. */
        uint64_t mbrx                  : 1;  /**< [  1:  1](SR/W1C/H) Reads or clears enable for GTI_CC_CNTMB_INT[MBRX]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cntmb_int_ena_clr_s cn; */
} bdk_gti_cc_cntmb_int_ena_clr_t;

#define BDK_GTI_CC_CNTMB_INT_ENA_CLR BDK_GTI_CC_CNTMB_INT_ENA_CLR_FUNC()
static inline uint64_t BDK_GTI_CC_CNTMB_INT_ENA_CLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTMB_INT_ENA_CLR_FUNC(void)
{
    return 0x8440000000f0ll;
}

#define typedef_BDK_GTI_CC_CNTMB_INT_ENA_CLR bdk_gti_cc_cntmb_int_ena_clr_t
#define bustype_BDK_GTI_CC_CNTMB_INT_ENA_CLR BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CC_CNTMB_INT_ENA_CLR "GTI_CC_CNTMB_INT_ENA_CLR"
#define busnum_BDK_GTI_CC_CNTMB_INT_ENA_CLR 0
#define arguments_BDK_GTI_CC_CNTMB_INT_ENA_CLR -1,-1,-1,-1

/**
 * Register (NCB) gti_cc_cntmb_int_ena_set
 *
 * GTI Counter Control Mailbox Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cc_cntmb_int_ena_set_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t mbrx                  : 1;  /**< [  1:  1](SR/W1S/H) Reads or sets enable for GTI_CC_CNTMB_INT[MBRX]. */
        uint64_t txts                  : 1;  /**< [  0:  0](SR/W1S/H) Reads or sets enable for GTI_CC_CNTMB_INT[TXTS]. */
#else /* Word 0 - Little Endian */
        uint64_t txts                  : 1;  /**< [  0:  0](SR/W1S/H) Reads or sets enable for GTI_CC_CNTMB_INT[TXTS]. */
        uint64_t mbrx                  : 1;  /**< [  1:  1](SR/W1S/H) Reads or sets enable for GTI_CC_CNTMB_INT[MBRX]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cntmb_int_ena_set_s cn; */
} bdk_gti_cc_cntmb_int_ena_set_t;

#define BDK_GTI_CC_CNTMB_INT_ENA_SET BDK_GTI_CC_CNTMB_INT_ENA_SET_FUNC()
static inline uint64_t BDK_GTI_CC_CNTMB_INT_ENA_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTMB_INT_ENA_SET_FUNC(void)
{
    return 0x8440000000f8ll;
}

#define typedef_BDK_GTI_CC_CNTMB_INT_ENA_SET bdk_gti_cc_cntmb_int_ena_set_t
#define bustype_BDK_GTI_CC_CNTMB_INT_ENA_SET BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CC_CNTMB_INT_ENA_SET "GTI_CC_CNTMB_INT_ENA_SET"
#define busnum_BDK_GTI_CC_CNTMB_INT_ENA_SET 0
#define arguments_BDK_GTI_CC_CNTMB_INT_ENA_SET -1,-1,-1,-1

/**
 * Register (NCB) gti_cc_cntmb_int_set
 *
 * GTI Counter Control Mailbox Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cc_cntmb_int_set_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t mbrx                  : 1;  /**< [  1:  1](SR/W1S/H) Reads or sets GTI_CC_CNTMB_INT[MBRX]. */
        uint64_t txts                  : 1;  /**< [  0:  0](SR/W1S/H) Reads or sets GTI_CC_CNTMB_INT[TXTS]. */
#else /* Word 0 - Little Endian */
        uint64_t txts                  : 1;  /**< [  0:  0](SR/W1S/H) Reads or sets GTI_CC_CNTMB_INT[TXTS]. */
        uint64_t mbrx                  : 1;  /**< [  1:  1](SR/W1S/H) Reads or sets GTI_CC_CNTMB_INT[MBRX]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cntmb_int_set_s cn; */
} bdk_gti_cc_cntmb_int_set_t;

#define BDK_GTI_CC_CNTMB_INT_SET BDK_GTI_CC_CNTMB_INT_SET_FUNC()
static inline uint64_t BDK_GTI_CC_CNTMB_INT_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTMB_INT_SET_FUNC(void)
{
    return 0x8440000000e8ll;
}

#define typedef_BDK_GTI_CC_CNTMB_INT_SET bdk_gti_cc_cntmb_int_set_t
#define bustype_BDK_GTI_CC_CNTMB_INT_SET BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CC_CNTMB_INT_SET "GTI_CC_CNTMB_INT_SET"
#define busnum_BDK_GTI_CC_CNTMB_INT_SET 0
#define arguments_BDK_GTI_CC_CNTMB_INT_SET -1,-1,-1,-1

/**
 * Register (NCB) gti_cc_cntmbts
 *
 * GTI Counter Control Mailbox Time Stamp Secure Register
 * Implementation defined register.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cc_cntmbts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t timestamp             : 64; /**< [ 63:  0](SRO/H) Mailbox time stamp. When GTI_CC_CNTMB is written, GTI_CC_CNTCV is saved in GTI_CC_CNTMBTS. */
#else /* Word 0 - Little Endian */
        uint64_t timestamp             : 64; /**< [ 63:  0](SRO/H) Mailbox time stamp. When GTI_CC_CNTMB is written, GTI_CC_CNTCV is saved in GTI_CC_CNTMBTS. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cntmbts_s cn; */
} bdk_gti_cc_cntmbts_t;

#define BDK_GTI_CC_CNTMBTS BDK_GTI_CC_CNTMBTS_FUNC()
static inline uint64_t BDK_GTI_CC_CNTMBTS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTMBTS_FUNC(void)
{
    return 0x8440000000d8ll;
}

#define typedef_BDK_GTI_CC_CNTMBTS bdk_gti_cc_cntmbts_t
#define bustype_BDK_GTI_CC_CNTMBTS BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CC_CNTMBTS "GTI_CC_CNTMBTS"
#define busnum_BDK_GTI_CC_CNTMBTS 0
#define arguments_BDK_GTI_CC_CNTMBTS -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_cntracc
 *
 * GTI Counter Control Count Rate Accumulator Secure Register
 * Implementation defined register.
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_cntracc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t cntracc               : 32; /**< [ 31:  0](SRO/H) Fractional bits of the system counter, GTI_RD_CNTCV. */
#else /* Word 0 - Little Endian */
        uint32_t cntracc               : 32; /**< [ 31:  0](SRO/H) Fractional bits of the system counter, GTI_RD_CNTCV. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cntracc_s cn; */
} bdk_gti_cc_cntracc_t;

#define BDK_GTI_CC_CNTRACC BDK_GTI_CC_CNTRACC_FUNC()
static inline uint64_t BDK_GTI_CC_CNTRACC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTRACC_FUNC(void)
{
    return 0x8440000000c4ll;
}

#define typedef_BDK_GTI_CC_CNTRACC bdk_gti_cc_cntracc_t
#define bustype_BDK_GTI_CC_CNTRACC BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_CNTRACC "GTI_CC_CNTRACC"
#define busnum_BDK_GTI_CC_CNTRACC 0
#define arguments_BDK_GTI_CC_CNTRACC -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_cntrate
 *
 * GTI Counter Control Count Rate Secure Register
 * Implementation defined register.
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_cntrate_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t cntrate               : 32; /**< [ 31:  0](SR/W) Sets the system counter count rate.
                                                                 The contents of CNTRATE is a 32-bit fraction that is added to CTI_CC_CNTRACC every source
                                                                 clock. */
#else /* Word 0 - Little Endian */
        uint32_t cntrate               : 32; /**< [ 31:  0](SR/W) Sets the system counter count rate.
                                                                 The contents of CNTRATE is a 32-bit fraction that is added to CTI_CC_CNTRACC every source
                                                                 clock. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cntrate_s cn; */
} bdk_gti_cc_cntrate_t;

#define BDK_GTI_CC_CNTRATE BDK_GTI_CC_CNTRATE_FUNC()
static inline uint64_t BDK_GTI_CC_CNTRATE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTRATE_FUNC(void)
{
    return 0x8440000000c0ll;
}

#define typedef_BDK_GTI_CC_CNTRATE bdk_gti_cc_cntrate_t
#define bustype_BDK_GTI_CC_CNTRATE BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_CNTRATE "GTI_CC_CNTRATE"
#define busnum_BDK_GTI_CC_CNTRATE 0
#define arguments_BDK_GTI_CC_CNTRATE -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_cntsr
 *
 * GTI Counter Control Status Secure Register
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_cntsr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t fcack                 : 1;  /**< [  8:  8](SRO/H) Frequency change acknowledge. Indicates the currently selected entry in the frequency
                                                                 table.

                                                                 For CNXXXX, which implements a single frequency table entry, always 0x0. */
        uint32_t reserved_2_7          : 6;
        uint32_t dbgh                  : 1;  /**< [  1:  1](SRO/H) Indicates whether the counter is halted because the halt-on-debug signal is asserted.
                                                                   0 = Counter is not halted.
                                                                   1 = Counter is halted. */
        uint32_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0            : 1;
        uint32_t dbgh                  : 1;  /**< [  1:  1](SRO/H) Indicates whether the counter is halted because the halt-on-debug signal is asserted.
                                                                   0 = Counter is not halted.
                                                                   1 = Counter is halted. */
        uint32_t reserved_2_7          : 6;
        uint32_t fcack                 : 1;  /**< [  8:  8](SRO/H) Frequency change acknowledge. Indicates the currently selected entry in the frequency
                                                                 table.

                                                                 For CNXXXX, which implements a single frequency table entry, always 0x0. */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_cntsr_s cn; */
} bdk_gti_cc_cntsr_t;

#define BDK_GTI_CC_CNTSR BDK_GTI_CC_CNTSR_FUNC()
static inline uint64_t BDK_GTI_CC_CNTSR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTSR_FUNC(void)
{
    return 0x844000000004ll;
}

#define typedef_BDK_GTI_CC_CNTSR bdk_gti_cc_cntsr_t
#define bustype_BDK_GTI_CC_CNTSR BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_CNTSR "GTI_CC_CNTSR"
#define busnum_BDK_GTI_CC_CNTSR 0
#define arguments_BDK_GTI_CC_CNTSR -1,-1,-1,-1

/**
 * Register (NCB) gti_cc_imp_ctl
 *
 * GTI Counter Control Implementation Control Register
 * Implementation defined register.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cc_imp_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t clk_src               : 1;  /**< [  0:  0](SR/W) Count source clock for GTI_CC_CNTRATE.
                                                                 0 = Coprocessor clock.
                                                                 1 = PTP PPS clock. See MIO_PTP_CLOCK_CFG[PPS]. */
#else /* Word 0 - Little Endian */
        uint64_t clk_src               : 1;  /**< [  0:  0](SR/W) Count source clock for GTI_CC_CNTRATE.
                                                                 0 = Coprocessor clock.
                                                                 1 = PTP PPS clock. See MIO_PTP_CLOCK_CFG[PPS]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_imp_ctl_s cn; */
} bdk_gti_cc_imp_ctl_t;

#define BDK_GTI_CC_IMP_CTL BDK_GTI_CC_IMP_CTL_FUNC()
static inline uint64_t BDK_GTI_CC_IMP_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_IMP_CTL_FUNC(void)
{
    return 0x844000000100ll;
}

#define typedef_BDK_GTI_CC_IMP_CTL bdk_gti_cc_imp_ctl_t
#define bustype_BDK_GTI_CC_IMP_CTL BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CC_IMP_CTL "GTI_CC_IMP_CTL"
#define busnum_BDK_GTI_CC_IMP_CTL 0
#define arguments_BDK_GTI_CC_IMP_CTL -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_pidr0
 *
 * GTI Counter Control Peripheral Identification Secure Register 0
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_pidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t partnum0              : 8;  /**< [  7:  0](SRO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_CC. */
#else /* Word 0 - Little Endian */
        uint32_t partnum0              : 8;  /**< [  7:  0](SRO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_CC. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_pidr0_s cn; */
} bdk_gti_cc_pidr0_t;

#define BDK_GTI_CC_PIDR0 BDK_GTI_CC_PIDR0_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR0_FUNC(void)
{
    return 0x844000000fe0ll;
}

#define typedef_BDK_GTI_CC_PIDR0 bdk_gti_cc_pidr0_t
#define bustype_BDK_GTI_CC_PIDR0 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_PIDR0 "GTI_CC_PIDR0"
#define busnum_BDK_GTI_CC_PIDR0 0
#define arguments_BDK_GTI_CC_PIDR0 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_pidr1
 *
 * GTI Counter Control Peripheral Identification Secure Register 1
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_pidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t idcode                : 4;  /**< [  7:  4](SRO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t partnum1              : 4;  /**< [  3:  0](SRO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else /* Word 0 - Little Endian */
        uint32_t partnum1              : 4;  /**< [  3:  0](SRO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
        uint32_t idcode                : 4;  /**< [  7:  4](SRO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_pidr1_s cn; */
} bdk_gti_cc_pidr1_t;

#define BDK_GTI_CC_PIDR1 BDK_GTI_CC_PIDR1_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR1_FUNC(void)
{
    return 0x844000000fe4ll;
}

#define typedef_BDK_GTI_CC_PIDR1 bdk_gti_cc_pidr1_t
#define bustype_BDK_GTI_CC_PIDR1 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_PIDR1 "GTI_CC_PIDR1"
#define busnum_BDK_GTI_CC_PIDR1 0
#define arguments_BDK_GTI_CC_PIDR1 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_pidr2
 *
 * GTI Counter Control Peripheral Identification Secure Register 2
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_pidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revision              : 4;  /**< [  7:  4](SRO) Architectural revision, as assigned by ARM. */
        uint32_t jedec                 : 1;  /**< [  3:  3](SRO) JEDEC assigned. */
        uint32_t idcode                : 3;  /**< [  2:  0](SRO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else /* Word 0 - Little Endian */
        uint32_t idcode                : 3;  /**< [  2:  0](SRO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
        uint32_t jedec                 : 1;  /**< [  3:  3](SRO) JEDEC assigned. */
        uint32_t revision              : 4;  /**< [  7:  4](SRO) Architectural revision, as assigned by ARM. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_pidr2_s cn; */
} bdk_gti_cc_pidr2_t;

#define BDK_GTI_CC_PIDR2 BDK_GTI_CC_PIDR2_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR2_FUNC(void)
{
    return 0x844000000fe8ll;
}

#define typedef_BDK_GTI_CC_PIDR2 bdk_gti_cc_pidr2_t
#define bustype_BDK_GTI_CC_PIDR2 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_PIDR2 "GTI_CC_PIDR2"
#define busnum_BDK_GTI_CC_PIDR2 0
#define arguments_BDK_GTI_CC_PIDR2 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_pidr3
 *
 * GTI Counter Control Peripheral Identification Secure Register 3
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_pidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revand                : 4;  /**< [  7:  4](SRO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t cust                  : 4;  /**< [  3:  0](SRO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else /* Word 0 - Little Endian */
        uint32_t cust                  : 4;  /**< [  3:  0](SRO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
        uint32_t revand                : 4;  /**< [  7:  4](SRO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_pidr3_s cn; */
} bdk_gti_cc_pidr3_t;

#define BDK_GTI_CC_PIDR3 BDK_GTI_CC_PIDR3_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR3_FUNC(void)
{
    return 0x844000000fecll;
}

#define typedef_BDK_GTI_CC_PIDR3 bdk_gti_cc_pidr3_t
#define bustype_BDK_GTI_CC_PIDR3 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_PIDR3 "GTI_CC_PIDR3"
#define busnum_BDK_GTI_CC_PIDR3 0
#define arguments_BDK_GTI_CC_PIDR3 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_pidr4
 *
 * GTI Counter Control Peripheral Identification Secure Register 4
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_pidr4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t pagecnt               : 4;  /**< [  7:  4](SRO) Number of log-2 4 KB blocks occupied. */
        uint32_t jepcont               : 4;  /**< [  3:  0](SRO) JEP106 continuation code. Indicates Cavium. */
#else /* Word 0 - Little Endian */
        uint32_t jepcont               : 4;  /**< [  3:  0](SRO) JEP106 continuation code. Indicates Cavium. */
        uint32_t pagecnt               : 4;  /**< [  7:  4](SRO) Number of log-2 4 KB blocks occupied. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_pidr4_s cn; */
} bdk_gti_cc_pidr4_t;

#define BDK_GTI_CC_PIDR4 BDK_GTI_CC_PIDR4_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR4_FUNC(void)
{
    return 0x844000000fd0ll;
}

#define typedef_BDK_GTI_CC_PIDR4 bdk_gti_cc_pidr4_t
#define bustype_BDK_GTI_CC_PIDR4 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_PIDR4 "GTI_CC_PIDR4"
#define busnum_BDK_GTI_CC_PIDR4 0
#define arguments_BDK_GTI_CC_PIDR4 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_pidr5
 *
 * GTI Counter Control Peripheral Identification Secure Register 5
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_pidr5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_pidr5_s cn; */
} bdk_gti_cc_pidr5_t;

#define BDK_GTI_CC_PIDR5 BDK_GTI_CC_PIDR5_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR5_FUNC(void)
{
    return 0x844000000fd4ll;
}

#define typedef_BDK_GTI_CC_PIDR5 bdk_gti_cc_pidr5_t
#define bustype_BDK_GTI_CC_PIDR5 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_PIDR5 "GTI_CC_PIDR5"
#define busnum_BDK_GTI_CC_PIDR5 0
#define arguments_BDK_GTI_CC_PIDR5 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_pidr6
 *
 * GTI Counter Control Peripheral Identification Secure Register 6
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_pidr6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_pidr6_s cn; */
} bdk_gti_cc_pidr6_t;

#define BDK_GTI_CC_PIDR6 BDK_GTI_CC_PIDR6_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR6_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR6_FUNC(void)
{
    return 0x844000000fd8ll;
}

#define typedef_BDK_GTI_CC_PIDR6 bdk_gti_cc_pidr6_t
#define bustype_BDK_GTI_CC_PIDR6 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_PIDR6 "GTI_CC_PIDR6"
#define busnum_BDK_GTI_CC_PIDR6 0
#define arguments_BDK_GTI_CC_PIDR6 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_cc_pidr7
 *
 * GTI Counter Control Peripheral Identification Secure Register 7
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_cc_pidr7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cc_pidr7_s cn; */
} bdk_gti_cc_pidr7_t;

#define BDK_GTI_CC_PIDR7 BDK_GTI_CC_PIDR7_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR7_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR7_FUNC(void)
{
    return 0x844000000fdcll;
}

#define typedef_BDK_GTI_CC_PIDR7 bdk_gti_cc_pidr7_t
#define bustype_BDK_GTI_CC_PIDR7 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CC_PIDR7 "GTI_CC_PIDR7"
#define busnum_BDK_GTI_CC_PIDR7 0
#define arguments_BDK_GTI_CC_PIDR7 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_cidr0
 *
 * GTI Control Component Identification Register 0
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_cidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_cidr0_s cn; */
} bdk_gti_ctl_cidr0_t;

#define BDK_GTI_CTL_CIDR0 BDK_GTI_CTL_CIDR0_FUNC()
static inline uint64_t BDK_GTI_CTL_CIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CIDR0_FUNC(void)
{
    return 0x844000020ff0ll;
}

#define typedef_BDK_GTI_CTL_CIDR0 bdk_gti_ctl_cidr0_t
#define bustype_BDK_GTI_CTL_CIDR0 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_CIDR0 "GTI_CTL_CIDR0"
#define busnum_BDK_GTI_CTL_CIDR0 0
#define arguments_BDK_GTI_CTL_CIDR0 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_cidr1
 *
 * GTI Control Component Identification Register 1
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_cidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cclass                : 4;  /**< [  7:  4](RO) Component class. */
        uint32_t preamble              : 4;  /**< [  3:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 4;  /**< [  3:  0](RO) Preamble identification value. */
        uint32_t cclass                : 4;  /**< [  7:  4](RO) Component class. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_cidr1_s cn; */
} bdk_gti_ctl_cidr1_t;

#define BDK_GTI_CTL_CIDR1 BDK_GTI_CTL_CIDR1_FUNC()
static inline uint64_t BDK_GTI_CTL_CIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CIDR1_FUNC(void)
{
    return 0x844000020ff4ll;
}

#define typedef_BDK_GTI_CTL_CIDR1 bdk_gti_ctl_cidr1_t
#define bustype_BDK_GTI_CTL_CIDR1 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_CIDR1 "GTI_CTL_CIDR1"
#define busnum_BDK_GTI_CTL_CIDR1 0
#define arguments_BDK_GTI_CTL_CIDR1 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_cidr2
 *
 * GTI Control Component Identification Register 2
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_cidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_cidr2_s cn; */
} bdk_gti_ctl_cidr2_t;

#define BDK_GTI_CTL_CIDR2 BDK_GTI_CTL_CIDR2_FUNC()
static inline uint64_t BDK_GTI_CTL_CIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CIDR2_FUNC(void)
{
    return 0x844000020ff8ll;
}

#define typedef_BDK_GTI_CTL_CIDR2 bdk_gti_ctl_cidr2_t
#define bustype_BDK_GTI_CTL_CIDR2 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_CIDR2 "GTI_CTL_CIDR2"
#define busnum_BDK_GTI_CTL_CIDR2 0
#define arguments_BDK_GTI_CTL_CIDR2 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_cidr3
 *
 * GTI Control Component Identification Register 3
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_cidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_cidr3_s cn; */
} bdk_gti_ctl_cidr3_t;

#define BDK_GTI_CTL_CIDR3 BDK_GTI_CTL_CIDR3_FUNC()
static inline uint64_t BDK_GTI_CTL_CIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CIDR3_FUNC(void)
{
    return 0x844000020ffcll;
}

#define typedef_BDK_GTI_CTL_CIDR3 bdk_gti_ctl_cidr3_t
#define bustype_BDK_GTI_CTL_CIDR3 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_CIDR3 "GTI_CTL_CIDR3"
#define busnum_BDK_GTI_CTL_CIDR3 0
#define arguments_BDK_GTI_CTL_CIDR3 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_cntacr0
 *
 * GTI Control Access Control 0 Register
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_cntacr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t constant              : 32; /**< [ 31:  0](RO) Access Control 0. */
#else /* Word 0 - Little Endian */
        uint32_t constant              : 32; /**< [ 31:  0](RO) Access Control 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_cntacr0_s cn; */
} bdk_gti_ctl_cntacr0_t;

#define BDK_GTI_CTL_CNTACR0 BDK_GTI_CTL_CNTACR0_FUNC()
static inline uint64_t BDK_GTI_CTL_CNTACR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CNTACR0_FUNC(void)
{
    return 0x844000020040ll;
}

#define typedef_BDK_GTI_CTL_CNTACR0 bdk_gti_ctl_cntacr0_t
#define bustype_BDK_GTI_CTL_CNTACR0 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_CNTACR0 "GTI_CTL_CNTACR0"
#define busnum_BDK_GTI_CTL_CNTACR0 0
#define arguments_BDK_GTI_CTL_CNTACR0 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_cntfrq
 *
 * GTI Control Counter Frequency Secure Register
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_cntfrq_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t data                  : 32; /**< [ 31:  0](SR/W) Programmed by boot software with the system counter clock frequency in Hertz.
                                                                 See also GTI_CC_CNTFID0. */
#else /* Word 0 - Little Endian */
        uint32_t data                  : 32; /**< [ 31:  0](SR/W) Programmed by boot software with the system counter clock frequency in Hertz.
                                                                 See also GTI_CC_CNTFID0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_cntfrq_s cn; */
} bdk_gti_ctl_cntfrq_t;

#define BDK_GTI_CTL_CNTFRQ BDK_GTI_CTL_CNTFRQ_FUNC()
static inline uint64_t BDK_GTI_CTL_CNTFRQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CNTFRQ_FUNC(void)
{
    return 0x844000020000ll;
}

#define typedef_BDK_GTI_CTL_CNTFRQ bdk_gti_ctl_cntfrq_t
#define bustype_BDK_GTI_CTL_CNTFRQ BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_CNTFRQ "GTI_CTL_CNTFRQ"
#define busnum_BDK_GTI_CTL_CNTFRQ 0
#define arguments_BDK_GTI_CTL_CNTFRQ -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_cntnsar
 *
 * GTI Control Counter Non-secure Access Secure Register
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_cntnsar_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t constant              : 32; /**< [ 31:  0](SRO) Counter non-secure access. */
#else /* Word 0 - Little Endian */
        uint32_t constant              : 32; /**< [ 31:  0](SRO) Counter non-secure access. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_cntnsar_s cn; */
} bdk_gti_ctl_cntnsar_t;

#define BDK_GTI_CTL_CNTNSAR BDK_GTI_CTL_CNTNSAR_FUNC()
static inline uint64_t BDK_GTI_CTL_CNTNSAR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CNTNSAR_FUNC(void)
{
    return 0x844000020004ll;
}

#define typedef_BDK_GTI_CTL_CNTNSAR bdk_gti_ctl_cntnsar_t
#define bustype_BDK_GTI_CTL_CNTNSAR BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_CNTNSAR "GTI_CTL_CNTNSAR"
#define busnum_BDK_GTI_CTL_CNTNSAR 0
#define arguments_BDK_GTI_CTL_CNTNSAR -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_cnttidr
 *
 * GTI Control Counter Timer ID Register
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_cnttidr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t constant              : 32; /**< [ 31:  0](RO) Counter Timer ID. */
#else /* Word 0 - Little Endian */
        uint32_t constant              : 32; /**< [ 31:  0](RO) Counter Timer ID. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_cnttidr_s cn; */
} bdk_gti_ctl_cnttidr_t;

#define BDK_GTI_CTL_CNTTIDR BDK_GTI_CTL_CNTTIDR_FUNC()
static inline uint64_t BDK_GTI_CTL_CNTTIDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CNTTIDR_FUNC(void)
{
    return 0x844000020008ll;
}

#define typedef_BDK_GTI_CTL_CNTTIDR bdk_gti_ctl_cnttidr_t
#define bustype_BDK_GTI_CTL_CNTTIDR BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_CNTTIDR "GTI_CTL_CNTTIDR"
#define busnum_BDK_GTI_CTL_CNTTIDR 0
#define arguments_BDK_GTI_CTL_CNTTIDR -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_pidr0
 *
 * GTI Control Peripheral Identification Register 0
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_pidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t partnum0              : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_CTL. */
#else /* Word 0 - Little Endian */
        uint32_t partnum0              : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_CTL. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_pidr0_s cn; */
} bdk_gti_ctl_pidr0_t;

#define BDK_GTI_CTL_PIDR0 BDK_GTI_CTL_PIDR0_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR0_FUNC(void)
{
    return 0x844000020fe0ll;
}

#define typedef_BDK_GTI_CTL_PIDR0 bdk_gti_ctl_pidr0_t
#define bustype_BDK_GTI_CTL_PIDR0 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_PIDR0 "GTI_CTL_PIDR0"
#define busnum_BDK_GTI_CTL_PIDR0 0
#define arguments_BDK_GTI_CTL_PIDR0 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_pidr1
 *
 * GTI Control Peripheral Identification Register 1
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_pidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t idcode                : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t partnum1              : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else /* Word 0 - Little Endian */
        uint32_t partnum1              : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
        uint32_t idcode                : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_pidr1_s cn; */
} bdk_gti_ctl_pidr1_t;

#define BDK_GTI_CTL_PIDR1 BDK_GTI_CTL_PIDR1_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR1_FUNC(void)
{
    return 0x844000020fe4ll;
}

#define typedef_BDK_GTI_CTL_PIDR1 bdk_gti_ctl_pidr1_t
#define bustype_BDK_GTI_CTL_PIDR1 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_PIDR1 "GTI_CTL_PIDR1"
#define busnum_BDK_GTI_CTL_PIDR1 0
#define arguments_BDK_GTI_CTL_PIDR1 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_pidr2
 *
 * GTI Control Peripheral Identification Register 2
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_pidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revision              : 4;  /**< [  7:  4](RO) Architectural revision, as assigned by ARM. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t idcode                : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else /* Word 0 - Little Endian */
        uint32_t idcode                : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t revision              : 4;  /**< [  7:  4](RO) Architectural revision, as assigned by ARM. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_pidr2_s cn; */
} bdk_gti_ctl_pidr2_t;

#define BDK_GTI_CTL_PIDR2 BDK_GTI_CTL_PIDR2_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR2_FUNC(void)
{
    return 0x844000020fe8ll;
}

#define typedef_BDK_GTI_CTL_PIDR2 bdk_gti_ctl_pidr2_t
#define bustype_BDK_GTI_CTL_PIDR2 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_PIDR2 "GTI_CTL_PIDR2"
#define busnum_BDK_GTI_CTL_PIDR2 0
#define arguments_BDK_GTI_CTL_PIDR2 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_pidr3
 *
 * GTI Control Peripheral Identification Register 3
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_pidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t cust                  : 4;  /**< [  3:  0](RO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else /* Word 0 - Little Endian */
        uint32_t cust                  : 4;  /**< [  3:  0](RO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_pidr3_s cn; */
} bdk_gti_ctl_pidr3_t;

#define BDK_GTI_CTL_PIDR3 BDK_GTI_CTL_PIDR3_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR3_FUNC(void)
{
    return 0x844000020fecll;
}

#define typedef_BDK_GTI_CTL_PIDR3 bdk_gti_ctl_pidr3_t
#define bustype_BDK_GTI_CTL_PIDR3 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_PIDR3 "GTI_CTL_PIDR3"
#define busnum_BDK_GTI_CTL_PIDR3 0
#define arguments_BDK_GTI_CTL_PIDR3 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_pidr4
 *
 * GTI Control Peripheral Identification Register 4
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_pidr4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t pagecnt               : 4;  /**< [  7:  4](RO) Number of log-2 4 KB blocks occupied. */
        uint32_t jepcont               : 4;  /**< [  3:  0](RO) JEP106 continuation code. Indicates Cavium. */
#else /* Word 0 - Little Endian */
        uint32_t jepcont               : 4;  /**< [  3:  0](RO) JEP106 continuation code. Indicates Cavium. */
        uint32_t pagecnt               : 4;  /**< [  7:  4](RO) Number of log-2 4 KB blocks occupied. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_pidr4_s cn; */
} bdk_gti_ctl_pidr4_t;

#define BDK_GTI_CTL_PIDR4 BDK_GTI_CTL_PIDR4_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR4_FUNC(void)
{
    return 0x844000020fd0ll;
}

#define typedef_BDK_GTI_CTL_PIDR4 bdk_gti_ctl_pidr4_t
#define bustype_BDK_GTI_CTL_PIDR4 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_PIDR4 "GTI_CTL_PIDR4"
#define busnum_BDK_GTI_CTL_PIDR4 0
#define arguments_BDK_GTI_CTL_PIDR4 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_pidr5
 *
 * GTI Control Peripheral Identification Register 5
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_pidr5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_pidr5_s cn; */
} bdk_gti_ctl_pidr5_t;

#define BDK_GTI_CTL_PIDR5 BDK_GTI_CTL_PIDR5_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR5_FUNC(void)
{
    return 0x844000020fd4ll;
}

#define typedef_BDK_GTI_CTL_PIDR5 bdk_gti_ctl_pidr5_t
#define bustype_BDK_GTI_CTL_PIDR5 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_PIDR5 "GTI_CTL_PIDR5"
#define busnum_BDK_GTI_CTL_PIDR5 0
#define arguments_BDK_GTI_CTL_PIDR5 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_pidr6
 *
 * GTI Control Peripheral Identification Register 6
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_pidr6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_pidr6_s cn; */
} bdk_gti_ctl_pidr6_t;

#define BDK_GTI_CTL_PIDR6 BDK_GTI_CTL_PIDR6_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR6_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR6_FUNC(void)
{
    return 0x844000020fd8ll;
}

#define typedef_BDK_GTI_CTL_PIDR6 bdk_gti_ctl_pidr6_t
#define bustype_BDK_GTI_CTL_PIDR6 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_PIDR6 "GTI_CTL_PIDR6"
#define busnum_BDK_GTI_CTL_PIDR6 0
#define arguments_BDK_GTI_CTL_PIDR6 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_ctl_pidr7
 *
 * GTI Control Peripheral Identification Register 7
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_ctl_pidr7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_ctl_pidr7_s cn; */
} bdk_gti_ctl_pidr7_t;

#define BDK_GTI_CTL_PIDR7 BDK_GTI_CTL_PIDR7_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR7_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR7_FUNC(void)
{
    return 0x844000020fdcll;
}

#define typedef_BDK_GTI_CTL_PIDR7 bdk_gti_ctl_pidr7_t
#define bustype_BDK_GTI_CTL_PIDR7 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_CTL_PIDR7 "GTI_CTL_PIDR7"
#define busnum_BDK_GTI_CTL_PIDR7 0
#define arguments_BDK_GTI_CTL_PIDR7 -1,-1,-1,-1

/**
 * Register (NCB) gti_cwd_del3t
 *
 * GTI Per-core Watchdog Non-Maskable Interrupt Register
 * Generic Timer Per-core Watchdog Non-Maskable Interrupts
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cwd_del3t_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t core                  : 48; /**< [ 47:  0](R/W1C/H) Per-core watchdog non-maskable interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t core                  : 48; /**< [ 47:  0](R/W1C/H) Per-core watchdog non-maskable interrupt. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cwd_del3t_s cn; */
} bdk_gti_cwd_del3t_t;

#define BDK_GTI_CWD_DEL3T BDK_GTI_CWD_DEL3T_FUNC()
static inline uint64_t BDK_GTI_CWD_DEL3T_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_DEL3T_FUNC(void)
{
    return 0x844000040220ll;
}

#define typedef_BDK_GTI_CWD_DEL3T bdk_gti_cwd_del3t_t
#define bustype_BDK_GTI_CWD_DEL3T BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CWD_DEL3T "GTI_CWD_DEL3T"
#define busnum_BDK_GTI_CWD_DEL3T 0
#define arguments_BDK_GTI_CWD_DEL3T -1,-1,-1,-1

/**
 * Register (NCB) gti_cwd_del3t_ena_clr
 *
 * GTI Per-core Watchdog Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cwd_del3t_ena_clr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t core                  : 48; /**< [ 47:  0](R/W1C/H) Reads or clears enable for GTI_CWD_DEL3T[CORE]. */
#else /* Word 0 - Little Endian */
        uint64_t core                  : 48; /**< [ 47:  0](R/W1C/H) Reads or clears enable for GTI_CWD_DEL3T[CORE]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cwd_del3t_ena_clr_s cn; */
} bdk_gti_cwd_del3t_ena_clr_t;

#define BDK_GTI_CWD_DEL3T_ENA_CLR BDK_GTI_CWD_DEL3T_ENA_CLR_FUNC()
static inline uint64_t BDK_GTI_CWD_DEL3T_ENA_CLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_DEL3T_ENA_CLR_FUNC(void)
{
    return 0x844000040230ll;
}

#define typedef_BDK_GTI_CWD_DEL3T_ENA_CLR bdk_gti_cwd_del3t_ena_clr_t
#define bustype_BDK_GTI_CWD_DEL3T_ENA_CLR BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CWD_DEL3T_ENA_CLR "GTI_CWD_DEL3T_ENA_CLR"
#define busnum_BDK_GTI_CWD_DEL3T_ENA_CLR 0
#define arguments_BDK_GTI_CWD_DEL3T_ENA_CLR -1,-1,-1,-1

/**
 * Register (NCB) gti_cwd_del3t_ena_set
 *
 * GTI Per-core Watchdog Non-Maskable Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cwd_del3t_ena_set_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t core                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets enable for GTI_CWD_DEL3T[CORE]. */
#else /* Word 0 - Little Endian */
        uint64_t core                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets enable for GTI_CWD_DEL3T[CORE]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cwd_del3t_ena_set_s cn; */
} bdk_gti_cwd_del3t_ena_set_t;

#define BDK_GTI_CWD_DEL3T_ENA_SET BDK_GTI_CWD_DEL3T_ENA_SET_FUNC()
static inline uint64_t BDK_GTI_CWD_DEL3T_ENA_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_DEL3T_ENA_SET_FUNC(void)
{
    return 0x844000040238ll;
}

#define typedef_BDK_GTI_CWD_DEL3T_ENA_SET bdk_gti_cwd_del3t_ena_set_t
#define bustype_BDK_GTI_CWD_DEL3T_ENA_SET BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CWD_DEL3T_ENA_SET "GTI_CWD_DEL3T_ENA_SET"
#define busnum_BDK_GTI_CWD_DEL3T_ENA_SET 0
#define arguments_BDK_GTI_CWD_DEL3T_ENA_SET -1,-1,-1,-1

/**
 * Register (NCB) gti_cwd_del3t_set
 *
 * GTI Per-core Watchdog Non-Maskable Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cwd_del3t_set_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t core                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets GTI_CWD_DEL3T[CORE]. */
#else /* Word 0 - Little Endian */
        uint64_t core                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets GTI_CWD_DEL3T[CORE]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cwd_del3t_set_s cn; */
} bdk_gti_cwd_del3t_set_t;

#define BDK_GTI_CWD_DEL3T_SET BDK_GTI_CWD_DEL3T_SET_FUNC()
static inline uint64_t BDK_GTI_CWD_DEL3T_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_DEL3T_SET_FUNC(void)
{
    return 0x844000040228ll;
}

#define typedef_BDK_GTI_CWD_DEL3T_SET bdk_gti_cwd_del3t_set_t
#define bustype_BDK_GTI_CWD_DEL3T_SET BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CWD_DEL3T_SET "GTI_CWD_DEL3T_SET"
#define busnum_BDK_GTI_CWD_DEL3T_SET 0
#define arguments_BDK_GTI_CWD_DEL3T_SET -1,-1,-1,-1

/**
 * Register (NCB) gti_cwd_int
 *
 * GTI Per-core Watchdog Interrupt Register
 * Generic Timer Per-core Watchdog Interrupts
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cwd_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t core                  : 48; /**< [ 47:  0](R/W1C/H) Per-core Watchdog Interrupt (Write one to clear) */
#else /* Word 0 - Little Endian */
        uint64_t core                  : 48; /**< [ 47:  0](R/W1C/H) Per-core Watchdog Interrupt (Write one to clear) */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cwd_int_s cn; */
} bdk_gti_cwd_int_t;

#define BDK_GTI_CWD_INT BDK_GTI_CWD_INT_FUNC()
static inline uint64_t BDK_GTI_CWD_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_INT_FUNC(void)
{
    return 0x844000040200ll;
}

#define typedef_BDK_GTI_CWD_INT bdk_gti_cwd_int_t
#define bustype_BDK_GTI_CWD_INT BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CWD_INT "GTI_CWD_INT"
#define busnum_BDK_GTI_CWD_INT 0
#define arguments_BDK_GTI_CWD_INT -1,-1,-1,-1

/**
 * Register (NCB) gti_cwd_int_ena_clr
 *
 * GTI Per-core Watchdog Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cwd_int_ena_clr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t core                  : 48; /**< [ 47:  0](R/W1C/H) Reads or clears enable for GTI_CWD_INT[CORE]. */
#else /* Word 0 - Little Endian */
        uint64_t core                  : 48; /**< [ 47:  0](R/W1C/H) Reads or clears enable for GTI_CWD_INT[CORE]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cwd_int_ena_clr_s cn; */
} bdk_gti_cwd_int_ena_clr_t;

#define BDK_GTI_CWD_INT_ENA_CLR BDK_GTI_CWD_INT_ENA_CLR_FUNC()
static inline uint64_t BDK_GTI_CWD_INT_ENA_CLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_INT_ENA_CLR_FUNC(void)
{
    return 0x844000040210ll;
}

#define typedef_BDK_GTI_CWD_INT_ENA_CLR bdk_gti_cwd_int_ena_clr_t
#define bustype_BDK_GTI_CWD_INT_ENA_CLR BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CWD_INT_ENA_CLR "GTI_CWD_INT_ENA_CLR"
#define busnum_BDK_GTI_CWD_INT_ENA_CLR 0
#define arguments_BDK_GTI_CWD_INT_ENA_CLR -1,-1,-1,-1

/**
 * Register (NCB) gti_cwd_int_ena_set
 *
 * GTI Per-core Watchdog Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cwd_int_ena_set_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t core                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets enable for GTI_CWD_INT[CORE]. */
#else /* Word 0 - Little Endian */
        uint64_t core                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets enable for GTI_CWD_INT[CORE]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cwd_int_ena_set_s cn; */
} bdk_gti_cwd_int_ena_set_t;

#define BDK_GTI_CWD_INT_ENA_SET BDK_GTI_CWD_INT_ENA_SET_FUNC()
static inline uint64_t BDK_GTI_CWD_INT_ENA_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_INT_ENA_SET_FUNC(void)
{
    return 0x844000040218ll;
}

#define typedef_BDK_GTI_CWD_INT_ENA_SET bdk_gti_cwd_int_ena_set_t
#define bustype_BDK_GTI_CWD_INT_ENA_SET BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CWD_INT_ENA_SET "GTI_CWD_INT_ENA_SET"
#define busnum_BDK_GTI_CWD_INT_ENA_SET 0
#define arguments_BDK_GTI_CWD_INT_ENA_SET -1,-1,-1,-1

/**
 * Register (NCB) gti_cwd_int_set
 *
 * GTI Per-core Watchdog Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cwd_int_set_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t core                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets GTI_CWD_INT[CORE]. */
#else /* Word 0 - Little Endian */
        uint64_t core                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets GTI_CWD_INT[CORE]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cwd_int_set_s cn; */
} bdk_gti_cwd_int_set_t;

#define BDK_GTI_CWD_INT_SET BDK_GTI_CWD_INT_SET_FUNC()
static inline uint64_t BDK_GTI_CWD_INT_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_INT_SET_FUNC(void)
{
    return 0x844000040208ll;
}

#define typedef_BDK_GTI_CWD_INT_SET bdk_gti_cwd_int_set_t
#define bustype_BDK_GTI_CWD_INT_SET BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CWD_INT_SET "GTI_CWD_INT_SET"
#define busnum_BDK_GTI_CWD_INT_SET 0
#define arguments_BDK_GTI_CWD_INT_SET -1,-1,-1,-1

/**
 * Register (NCB) gti_cwd_poke#
 *
 * GTI Per-core Watchdog Poke Registers
 * Per-core Watchdog poke. Writing any value to this register does the following:
 * * Clears any pending interrupt generated by the associated watchdog.
 * * Resets GTI_CWD_WDOG()[STATE] to 0x0.
 * * Sets GTI_CWD_WDOG()[CNT] to (GTI_CWD_WDOG()[LEN] << 8)..
 *
 * Reading this register returns the associated GTI_CWD_WDOG() register.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cwd_pokex_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t zero                  : 18; /**< [ 63: 46](WO) Reserved. */
        uint64_t gstop                 : 1;  /**< [ 45: 45](RO/H) Global-stop enable. */
        uint64_t dstop                 : 1;  /**< [ 44: 44](RO/H) Debug-stop enable. */
        uint64_t cnt                   : 24; /**< [ 43: 20](RO/H) Number of 1024-cycle intervals until next watchdog expiration. Set on write to
                                                                 associated GTI_CWD_WDOG_POKE(). */
        uint64_t len                   : 16; /**< [ 19:  4](RO/H) Watchdog time-expiration length. The most-significant 16 bits of a 24-bit value to be
                                                                 decremented every 1024 cycles. */
        uint64_t state                 : 2;  /**< [  3:  2](RO/H) Watchdog state. The number of watchdog time expirations since last core poke. Cleared on
                                                                 write to associated GTI_CWD_WDOG_POKE(). */
        uint64_t mode                  : 2;  /**< [  1:  0](RO/H) Watchdog mode:
                                                                 0x0 = Off.
                                                                 0x1 = Interrupt only.
                                                                 0x2 = Interrupt + DEL3T.
                                                                 0x3 = Interrupt + DEL3T + soft reset. */
#else /* Word 0 - Little Endian */
        uint64_t mode                  : 2;  /**< [  1:  0](RO/H) Watchdog mode:
                                                                 0x0 = Off.
                                                                 0x1 = Interrupt only.
                                                                 0x2 = Interrupt + DEL3T.
                                                                 0x3 = Interrupt + DEL3T + soft reset. */
        uint64_t state                 : 2;  /**< [  3:  2](RO/H) Watchdog state. The number of watchdog time expirations since last core poke. Cleared on
                                                                 write to associated GTI_CWD_WDOG_POKE(). */
        uint64_t len                   : 16; /**< [ 19:  4](RO/H) Watchdog time-expiration length. The most-significant 16 bits of a 24-bit value to be
                                                                 decremented every 1024 cycles. */
        uint64_t cnt                   : 24; /**< [ 43: 20](RO/H) Number of 1024-cycle intervals until next watchdog expiration. Set on write to
                                                                 associated GTI_CWD_WDOG_POKE(). */
        uint64_t dstop                 : 1;  /**< [ 44: 44](RO/H) Debug-stop enable. */
        uint64_t gstop                 : 1;  /**< [ 45: 45](RO/H) Global-stop enable. */
        uint64_t zero                  : 18; /**< [ 63: 46](WO) Reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cwd_pokex_s cn; */
} bdk_gti_cwd_pokex_t;

static inline uint64_t BDK_GTI_CWD_POKEX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_POKEX(unsigned long a)
{
    if (a<=47)
        return 0x844000050000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("GTI_CWD_POKEX", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_CWD_POKEX(a) bdk_gti_cwd_pokex_t
#define bustype_BDK_GTI_CWD_POKEX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CWD_POKEX(a) "GTI_CWD_POKEX"
#define busnum_BDK_GTI_CWD_POKEX(a) (a)
#define arguments_BDK_GTI_CWD_POKEX(a) (a),-1,-1,-1

/**
 * Register (NCB) gti_cwd_wdog#
 *
 * GTI Per-core Watchdog Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_cwd_wdogx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_46_63        : 18;
        uint64_t gstop                 : 1;  /**< [ 45: 45](R/W) Global-stop enable. */
        uint64_t dstop                 : 1;  /**< [ 44: 44](R/W) Debug-stop enable. */
        uint64_t cnt                   : 24; /**< [ 43: 20](R/W/H) Number of 1024-cycle intervals until next watchdog expiration. Set on write to
                                                                 associated GTI_CWD_WDOG_POKE().

                                                                 Typically on each write to CTI_CMD_WDOG(), [CNT] should be set to [LEN] * 0x256. */
        uint64_t len                   : 16; /**< [ 19:  4](R/W) Watchdog time-expiration length. The most-significant 16 bits of a 24-bit value to be
                                                                 decremented every 1024 cycles. */
        uint64_t state                 : 2;  /**< [  3:  2](R/W/H) Watchdog state. The number of watchdog time expirations since last core poke. Cleared on
                                                                 write to associated GTI_CWD_WDOG_POKE(). */
        uint64_t mode                  : 2;  /**< [  1:  0](R/W) Watchdog mode:
                                                                 0x0 = Off.
                                                                 0x1 = Interrupt only.
                                                                 0x2 = Interrupt + DEL3T.
                                                                 0x3 = Interrupt + DEL3T + soft reset. */
#else /* Word 0 - Little Endian */
        uint64_t mode                  : 2;  /**< [  1:  0](R/W) Watchdog mode:
                                                                 0x0 = Off.
                                                                 0x1 = Interrupt only.
                                                                 0x2 = Interrupt + DEL3T.
                                                                 0x3 = Interrupt + DEL3T + soft reset. */
        uint64_t state                 : 2;  /**< [  3:  2](R/W/H) Watchdog state. The number of watchdog time expirations since last core poke. Cleared on
                                                                 write to associated GTI_CWD_WDOG_POKE(). */
        uint64_t len                   : 16; /**< [ 19:  4](R/W) Watchdog time-expiration length. The most-significant 16 bits of a 24-bit value to be
                                                                 decremented every 1024 cycles. */
        uint64_t cnt                   : 24; /**< [ 43: 20](R/W/H) Number of 1024-cycle intervals until next watchdog expiration. Set on write to
                                                                 associated GTI_CWD_WDOG_POKE().

                                                                 Typically on each write to CTI_CMD_WDOG(), [CNT] should be set to [LEN] * 0x256. */
        uint64_t dstop                 : 1;  /**< [ 44: 44](R/W) Debug-stop enable. */
        uint64_t gstop                 : 1;  /**< [ 45: 45](R/W) Global-stop enable. */
        uint64_t reserved_46_63        : 18;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_cwd_wdogx_s cn; */
} bdk_gti_cwd_wdogx_t;

static inline uint64_t BDK_GTI_CWD_WDOGX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_WDOGX(unsigned long a)
{
    if (a<=47)
        return 0x844000040000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("GTI_CWD_WDOGX", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_CWD_WDOGX(a) bdk_gti_cwd_wdogx_t
#define bustype_BDK_GTI_CWD_WDOGX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_CWD_WDOGX(a) "GTI_CWD_WDOGX"
#define busnum_BDK_GTI_CWD_WDOGX(a) (a)
#define arguments_BDK_GTI_CWD_WDOGX(a) (a),-1,-1,-1

/**
 * Register (NCB) gti_err_bist_status
 *
 * GTI BIST Status Register
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_err_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t ram                   : 2;  /**< [  1:  0](RO/H) BIST status. */
#else /* Word 0 - Little Endian */
        uint64_t ram                   : 2;  /**< [  1:  0](RO/H) BIST status. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_err_bist_status_s cn; */
} bdk_gti_err_bist_status_t;

#define BDK_GTI_ERR_BIST_STATUS BDK_GTI_ERR_BIST_STATUS_FUNC()
static inline uint64_t BDK_GTI_ERR_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_ERR_BIST_STATUS_FUNC(void)
{
    return 0x8440000f0030ll;
}

#define typedef_BDK_GTI_ERR_BIST_STATUS bdk_gti_err_bist_status_t
#define bustype_BDK_GTI_ERR_BIST_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_ERR_BIST_STATUS "GTI_ERR_BIST_STATUS"
#define busnum_BDK_GTI_ERR_BIST_STATUS 0
#define arguments_BDK_GTI_ERR_BIST_STATUS -1,-1,-1,-1

/**
 * Register (NCB) gti_err_ecc_disable
 *
 * GTI ECC Disable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_err_ecc_disable_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t ram                   : 2;  /**< [  1:  0](R/W) Each bit disables correction of respective RAM. */
#else /* Word 0 - Little Endian */
        uint64_t ram                   : 2;  /**< [  1:  0](R/W) Each bit disables correction of respective RAM. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_err_ecc_disable_s cn; */
} bdk_gti_err_ecc_disable_t;

#define BDK_GTI_ERR_ECC_DISABLE BDK_GTI_ERR_ECC_DISABLE_FUNC()
static inline uint64_t BDK_GTI_ERR_ECC_DISABLE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_ERR_ECC_DISABLE_FUNC(void)
{
    return 0x8440000f0020ll;
}

#define typedef_BDK_GTI_ERR_ECC_DISABLE bdk_gti_err_ecc_disable_t
#define bustype_BDK_GTI_ERR_ECC_DISABLE BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_ERR_ECC_DISABLE "GTI_ERR_ECC_DISABLE"
#define busnum_BDK_GTI_ERR_ECC_DISABLE 0
#define arguments_BDK_GTI_ERR_ECC_DISABLE -1,-1,-1,-1

/**
 * Register (NCB) gti_err_ecc_flip
 *
 * GTI ECC Flip Register
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_err_ecc_flip_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t ramx                  : 2;  /**< [ 33: 32](R/W) Each bit flips a second bit of syndrome in the respective RAM. */
        uint64_t reserved_2_31         : 30;
        uint64_t ram                   : 2;  /**< [  1:  0](R/W) Each bit flips the first bit of syndrome in the respective RAM. */
#else /* Word 0 - Little Endian */
        uint64_t ram                   : 2;  /**< [  1:  0](R/W) Each bit flips the first bit of syndrome in the respective RAM. */
        uint64_t reserved_2_31         : 30;
        uint64_t ramx                  : 2;  /**< [ 33: 32](R/W) Each bit flips a second bit of syndrome in the respective RAM. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_err_ecc_flip_s cn; */
} bdk_gti_err_ecc_flip_t;

#define BDK_GTI_ERR_ECC_FLIP BDK_GTI_ERR_ECC_FLIP_FUNC()
static inline uint64_t BDK_GTI_ERR_ECC_FLIP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_ERR_ECC_FLIP_FUNC(void)
{
    return 0x8440000f0028ll;
}

#define typedef_BDK_GTI_ERR_ECC_FLIP bdk_gti_err_ecc_flip_t
#define bustype_BDK_GTI_ERR_ECC_FLIP BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_ERR_ECC_FLIP "GTI_ERR_ECC_FLIP"
#define busnum_BDK_GTI_ERR_ECC_FLIP 0
#define arguments_BDK_GTI_ERR_ECC_FLIP -1,-1,-1,-1

/**
 * Register (NCB) gti_err_int
 *
 * GTI Error Interrupt Register
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_err_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t dbe                   : 2;  /**< [ 33: 32](R/W1C/H) Double bit error. */
        uint64_t reserved_2_31         : 30;
        uint64_t sbe                   : 2;  /**< [  1:  0](R/W1C/H) Single bit error. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 2;  /**< [  1:  0](R/W1C/H) Single bit error. */
        uint64_t reserved_2_31         : 30;
        uint64_t dbe                   : 2;  /**< [ 33: 32](R/W1C/H) Double bit error. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_err_int_s cn; */
} bdk_gti_err_int_t;

#define BDK_GTI_ERR_INT BDK_GTI_ERR_INT_FUNC()
static inline uint64_t BDK_GTI_ERR_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_ERR_INT_FUNC(void)
{
    return 0x8440000f0000ll;
}

#define typedef_BDK_GTI_ERR_INT bdk_gti_err_int_t
#define bustype_BDK_GTI_ERR_INT BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_ERR_INT "GTI_ERR_INT"
#define busnum_BDK_GTI_ERR_INT 0
#define arguments_BDK_GTI_ERR_INT -1,-1,-1,-1

/**
 * Register (NCB) gti_err_int_ena_clr
 *
 * GTI Error Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_err_int_ena_clr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t dbe                   : 2;  /**< [ 33: 32](R/W1C/H) Reads or clears enable for GTI_ERR_INT[DBE]. */
        uint64_t reserved_2_31         : 30;
        uint64_t sbe                   : 2;  /**< [  1:  0](R/W1C/H) Reads or clears enable for GTI_ERR_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 2;  /**< [  1:  0](R/W1C/H) Reads or clears enable for GTI_ERR_INT[SBE]. */
        uint64_t reserved_2_31         : 30;
        uint64_t dbe                   : 2;  /**< [ 33: 32](R/W1C/H) Reads or clears enable for GTI_ERR_INT[DBE]. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_err_int_ena_clr_s cn; */
} bdk_gti_err_int_ena_clr_t;

#define BDK_GTI_ERR_INT_ENA_CLR BDK_GTI_ERR_INT_ENA_CLR_FUNC()
static inline uint64_t BDK_GTI_ERR_INT_ENA_CLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_ERR_INT_ENA_CLR_FUNC(void)
{
    return 0x8440000f0010ll;
}

#define typedef_BDK_GTI_ERR_INT_ENA_CLR bdk_gti_err_int_ena_clr_t
#define bustype_BDK_GTI_ERR_INT_ENA_CLR BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_ERR_INT_ENA_CLR "GTI_ERR_INT_ENA_CLR"
#define busnum_BDK_GTI_ERR_INT_ENA_CLR 0
#define arguments_BDK_GTI_ERR_INT_ENA_CLR -1,-1,-1,-1

/**
 * Register (NCB) gti_err_int_ena_set
 *
 * GTI Error Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_err_int_ena_set_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t dbe                   : 2;  /**< [ 33: 32](R/W1S/H) Reads or sets enable for GTI_ERR_INT[DBE]. */
        uint64_t reserved_2_31         : 30;
        uint64_t sbe                   : 2;  /**< [  1:  0](R/W1S/H) Reads or sets enable for GTI_ERR_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 2;  /**< [  1:  0](R/W1S/H) Reads or sets enable for GTI_ERR_INT[SBE]. */
        uint64_t reserved_2_31         : 30;
        uint64_t dbe                   : 2;  /**< [ 33: 32](R/W1S/H) Reads or sets enable for GTI_ERR_INT[DBE]. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_err_int_ena_set_s cn; */
} bdk_gti_err_int_ena_set_t;

#define BDK_GTI_ERR_INT_ENA_SET BDK_GTI_ERR_INT_ENA_SET_FUNC()
static inline uint64_t BDK_GTI_ERR_INT_ENA_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_ERR_INT_ENA_SET_FUNC(void)
{
    return 0x8440000f0018ll;
}

#define typedef_BDK_GTI_ERR_INT_ENA_SET bdk_gti_err_int_ena_set_t
#define bustype_BDK_GTI_ERR_INT_ENA_SET BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_ERR_INT_ENA_SET "GTI_ERR_INT_ENA_SET"
#define busnum_BDK_GTI_ERR_INT_ENA_SET 0
#define arguments_BDK_GTI_ERR_INT_ENA_SET -1,-1,-1,-1

/**
 * Register (NCB) gti_err_int_set
 *
 * GTI Error Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_err_int_set_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t dbe                   : 2;  /**< [ 33: 32](R/W1S/H) Reads or sets GTI_ERR_INT[DBE]. */
        uint64_t reserved_2_31         : 30;
        uint64_t sbe                   : 2;  /**< [  1:  0](R/W1S/H) Reads or sets GTI_ERR_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 2;  /**< [  1:  0](R/W1S/H) Reads or sets GTI_ERR_INT[SBE]. */
        uint64_t reserved_2_31         : 30;
        uint64_t dbe                   : 2;  /**< [ 33: 32](R/W1S/H) Reads or sets GTI_ERR_INT[DBE]. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_err_int_set_s cn; */
} bdk_gti_err_int_set_t;

#define BDK_GTI_ERR_INT_SET BDK_GTI_ERR_INT_SET_FUNC()
static inline uint64_t BDK_GTI_ERR_INT_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_ERR_INT_SET_FUNC(void)
{
    return 0x8440000f0008ll;
}

#define typedef_BDK_GTI_ERR_INT_SET bdk_gti_err_int_set_t
#define bustype_BDK_GTI_ERR_INT_SET BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_ERR_INT_SET "GTI_ERR_INT_SET"
#define busnum_BDK_GTI_ERR_INT_SET 0
#define arguments_BDK_GTI_ERR_INT_SET -1,-1,-1,-1

/**
 * Register (NCB) gti_msix_pba#
 *
 * GTI MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the GTI_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for each interrupt, enumerated by GTI_INT_VEC_E.
                                                                 Bits that have no associated GTI_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for each interrupt, enumerated by GTI_INT_VEC_E.
                                                                 Bits that have no associated GTI_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_msix_pbax_s cn; */
} bdk_gti_msix_pbax_t;

static inline uint64_t BDK_GTI_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_MSIX_PBAX(unsigned long a)
{
    if (a<=1)
        return 0x84400f0f0000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_MSIX_PBAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_MSIX_PBAX(a) bdk_gti_msix_pbax_t
#define bustype_BDK_GTI_MSIX_PBAX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_MSIX_PBAX(a) "GTI_MSIX_PBAX"
#define busnum_BDK_GTI_MSIX_PBAX(a) (a)
#define arguments_BDK_GTI_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (NCB) gti_msix_vec#_addr
 *
 * GTI MSI-X Vector Table Address Registers
 * This register is the MSI-X vector table, indexed by the GTI_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's GTI_MSIX_VEC()_ADDR, GTI_MSIX_VEC()_CTL, and corresponding
                                                                 bit of GTI_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_GTI_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's GTI_MSIX_VEC()_ADDR, GTI_MSIX_VEC()_CTL, and corresponding
                                                                 bit of GTI_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_GTI_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_msix_vecx_addr_s cn; */
} bdk_gti_msix_vecx_addr_t;

static inline uint64_t BDK_GTI_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_MSIX_VECX_ADDR(unsigned long a)
{
    if (a<=105)
        return 0x84400f000000ll + 0x10ll * ((a) & 0x7f);
    __bdk_csr_fatal("GTI_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_MSIX_VECX_ADDR(a) bdk_gti_msix_vecx_addr_t
#define bustype_BDK_GTI_MSIX_VECX_ADDR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_MSIX_VECX_ADDR(a) "GTI_MSIX_VECX_ADDR"
#define busnum_BDK_GTI_MSIX_VECX_ADDR(a) (a)
#define arguments_BDK_GTI_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) gti_msix_vec#_ctl
 *
 * GTI MSI-X Vector Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the GTI_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_msix_vecx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts will be sent to this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts will be sent to this vector. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_msix_vecx_ctl_s cn; */
} bdk_gti_msix_vecx_ctl_t;

static inline uint64_t BDK_GTI_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_MSIX_VECX_CTL(unsigned long a)
{
    if (a<=105)
        return 0x84400f000008ll + 0x10ll * ((a) & 0x7f);
    __bdk_csr_fatal("GTI_MSIX_VECX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_MSIX_VECX_CTL(a) bdk_gti_msix_vecx_ctl_t
#define bustype_BDK_GTI_MSIX_VECX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_MSIX_VECX_CTL(a) "GTI_MSIX_VECX_CTL"
#define busnum_BDK_GTI_MSIX_VECX_CTL(a) (a)
#define arguments_BDK_GTI_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_rd_cidr0
 *
 * GTI Counter Read Component Identification Register 0
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_rd_cidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_rd_cidr0_s cn; */
} bdk_gti_rd_cidr0_t;

#define BDK_GTI_RD_CIDR0 BDK_GTI_RD_CIDR0_FUNC()
static inline uint64_t BDK_GTI_RD_CIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_CIDR0_FUNC(void)
{
    return 0x844000010ff0ll;
}

#define typedef_BDK_GTI_RD_CIDR0 bdk_gti_rd_cidr0_t
#define bustype_BDK_GTI_RD_CIDR0 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_RD_CIDR0 "GTI_RD_CIDR0"
#define busnum_BDK_GTI_RD_CIDR0 0
#define arguments_BDK_GTI_RD_CIDR0 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_rd_cidr1
 *
 * GTI Counter Read Component Identification Register 1
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_rd_cidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cclass                : 4;  /**< [  7:  4](RO) Component class. */
        uint32_t preamble              : 4;  /**< [  3:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 4;  /**< [  3:  0](RO) Preamble identification value. */
        uint32_t cclass                : 4;  /**< [  7:  4](RO) Component class. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_rd_cidr1_s cn; */
} bdk_gti_rd_cidr1_t;

#define BDK_GTI_RD_CIDR1 BDK_GTI_RD_CIDR1_FUNC()
static inline uint64_t BDK_GTI_RD_CIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_CIDR1_FUNC(void)
{
    return 0x844000010ff4ll;
}

#define typedef_BDK_GTI_RD_CIDR1 bdk_gti_rd_cidr1_t
#define bustype_BDK_GTI_RD_CIDR1 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_RD_CIDR1 "GTI_RD_CIDR1"
#define busnum_BDK_GTI_RD_CIDR1 0
#define arguments_BDK_GTI_RD_CIDR1 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_rd_cidr2
 *
 * GTI Counter Read Component Identification Register 2
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_rd_cidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_rd_cidr2_s cn; */
} bdk_gti_rd_cidr2_t;

#define BDK_GTI_RD_CIDR2 BDK_GTI_RD_CIDR2_FUNC()
static inline uint64_t BDK_GTI_RD_CIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_CIDR2_FUNC(void)
{
    return 0x844000010ff8ll;
}

#define typedef_BDK_GTI_RD_CIDR2 bdk_gti_rd_cidr2_t
#define bustype_BDK_GTI_RD_CIDR2 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_RD_CIDR2 "GTI_RD_CIDR2"
#define busnum_BDK_GTI_RD_CIDR2 0
#define arguments_BDK_GTI_RD_CIDR2 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_rd_cidr3
 *
 * GTI Counter Read Component Identification Register 3
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_rd_cidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_rd_cidr3_s cn; */
} bdk_gti_rd_cidr3_t;

#define BDK_GTI_RD_CIDR3 BDK_GTI_RD_CIDR3_FUNC()
static inline uint64_t BDK_GTI_RD_CIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_CIDR3_FUNC(void)
{
    return 0x844000010ffcll;
}

#define typedef_BDK_GTI_RD_CIDR3 bdk_gti_rd_cidr3_t
#define bustype_BDK_GTI_RD_CIDR3 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_RD_CIDR3 "GTI_RD_CIDR3"
#define busnum_BDK_GTI_RD_CIDR3 0
#define arguments_BDK_GTI_RD_CIDR3 -1,-1,-1,-1

/**
 * Register (NCB) gti_rd_cntcv
 *
 * GTI Counter Read Value Register
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_rd_cntcv_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](RO/H) System counter count value.  The counter is writable with GTI_CC_CNTCV. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](RO/H) System counter count value.  The counter is writable with GTI_CC_CNTCV. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_rd_cntcv_s cn; */
} bdk_gti_rd_cntcv_t;

#define BDK_GTI_RD_CNTCV BDK_GTI_RD_CNTCV_FUNC()
static inline uint64_t BDK_GTI_RD_CNTCV_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_CNTCV_FUNC(void)
{
    return 0x844000010000ll;
}

#define typedef_BDK_GTI_RD_CNTCV bdk_gti_rd_cntcv_t
#define bustype_BDK_GTI_RD_CNTCV BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_RD_CNTCV "GTI_RD_CNTCV"
#define busnum_BDK_GTI_RD_CNTCV 0
#define arguments_BDK_GTI_RD_CNTCV -1,-1,-1,-1

/**
 * Register (NCB32b) gti_rd_pidr0
 *
 * GTI Counter Read Peripheral Identification Register 0
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_rd_pidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t partnum0              : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_RD. */
#else /* Word 0 - Little Endian */
        uint32_t partnum0              : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_RD. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_rd_pidr0_s cn; */
} bdk_gti_rd_pidr0_t;

#define BDK_GTI_RD_PIDR0 BDK_GTI_RD_PIDR0_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR0_FUNC(void)
{
    return 0x844000010fe0ll;
}

#define typedef_BDK_GTI_RD_PIDR0 bdk_gti_rd_pidr0_t
#define bustype_BDK_GTI_RD_PIDR0 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_RD_PIDR0 "GTI_RD_PIDR0"
#define busnum_BDK_GTI_RD_PIDR0 0
#define arguments_BDK_GTI_RD_PIDR0 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_rd_pidr1
 *
 * GTI Counter Read Peripheral Identification Register 1
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_rd_pidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t idcode                : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t partnum1              : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else /* Word 0 - Little Endian */
        uint32_t partnum1              : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
        uint32_t idcode                : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_rd_pidr1_s cn; */
} bdk_gti_rd_pidr1_t;

#define BDK_GTI_RD_PIDR1 BDK_GTI_RD_PIDR1_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR1_FUNC(void)
{
    return 0x844000010fe4ll;
}

#define typedef_BDK_GTI_RD_PIDR1 bdk_gti_rd_pidr1_t
#define bustype_BDK_GTI_RD_PIDR1 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_RD_PIDR1 "GTI_RD_PIDR1"
#define busnum_BDK_GTI_RD_PIDR1 0
#define arguments_BDK_GTI_RD_PIDR1 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_rd_pidr2
 *
 * GTI Counter Read Peripheral Identification Register 2
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_rd_pidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revision              : 4;  /**< [  7:  4](RO) Architectural revision, as assigned by ARM. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t idcode                : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else /* Word 0 - Little Endian */
        uint32_t idcode                : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t revision              : 4;  /**< [  7:  4](RO) Architectural revision, as assigned by ARM. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_rd_pidr2_s cn; */
} bdk_gti_rd_pidr2_t;

#define BDK_GTI_RD_PIDR2 BDK_GTI_RD_PIDR2_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR2_FUNC(void)
{
    return 0x844000010fe8ll;
}

#define typedef_BDK_GTI_RD_PIDR2 bdk_gti_rd_pidr2_t
#define bustype_BDK_GTI_RD_PIDR2 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_RD_PIDR2 "GTI_RD_PIDR2"
#define busnum_BDK_GTI_RD_PIDR2 0
#define arguments_BDK_GTI_RD_PIDR2 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_rd_pidr3
 *
 * GTI Counter Read Peripheral Identification Register 3
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_rd_pidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t cust                  : 4;  /**< [  3:  0](RO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else /* Word 0 - Little Endian */
        uint32_t cust                  : 4;  /**< [  3:  0](RO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_rd_pidr3_s cn; */
} bdk_gti_rd_pidr3_t;

#define BDK_GTI_RD_PIDR3 BDK_GTI_RD_PIDR3_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR3_FUNC(void)
{
    return 0x844000010fecll;
}

#define typedef_BDK_GTI_RD_PIDR3 bdk_gti_rd_pidr3_t
#define bustype_BDK_GTI_RD_PIDR3 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_RD_PIDR3 "GTI_RD_PIDR3"
#define busnum_BDK_GTI_RD_PIDR3 0
#define arguments_BDK_GTI_RD_PIDR3 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_rd_pidr4
 *
 * GTI Counter Read Peripheral Identification Register 4
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_rd_pidr4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t pagecnt               : 4;  /**< [  7:  4](RO) Number of log-2 4 KB blocks occupied. */
        uint32_t jepcont               : 4;  /**< [  3:  0](RO) JEP106 continuation code. Indicates Cavium. */
#else /* Word 0 - Little Endian */
        uint32_t jepcont               : 4;  /**< [  3:  0](RO) JEP106 continuation code. Indicates Cavium. */
        uint32_t pagecnt               : 4;  /**< [  7:  4](RO) Number of log-2 4 KB blocks occupied. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_rd_pidr4_s cn; */
} bdk_gti_rd_pidr4_t;

#define BDK_GTI_RD_PIDR4 BDK_GTI_RD_PIDR4_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR4_FUNC(void)
{
    return 0x844000010fd0ll;
}

#define typedef_BDK_GTI_RD_PIDR4 bdk_gti_rd_pidr4_t
#define bustype_BDK_GTI_RD_PIDR4 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_RD_PIDR4 "GTI_RD_PIDR4"
#define busnum_BDK_GTI_RD_PIDR4 0
#define arguments_BDK_GTI_RD_PIDR4 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_rd_pidr5
 *
 * GTI Counter Read Peripheral Identification Register 5
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_rd_pidr5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_rd_pidr5_s cn; */
} bdk_gti_rd_pidr5_t;

#define BDK_GTI_RD_PIDR5 BDK_GTI_RD_PIDR5_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR5_FUNC(void)
{
    return 0x844000010fd4ll;
}

#define typedef_BDK_GTI_RD_PIDR5 bdk_gti_rd_pidr5_t
#define bustype_BDK_GTI_RD_PIDR5 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_RD_PIDR5 "GTI_RD_PIDR5"
#define busnum_BDK_GTI_RD_PIDR5 0
#define arguments_BDK_GTI_RD_PIDR5 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_rd_pidr6
 *
 * GTI Counter Read Peripheral Identification Register 6
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_rd_pidr6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_rd_pidr6_s cn; */
} bdk_gti_rd_pidr6_t;

#define BDK_GTI_RD_PIDR6 BDK_GTI_RD_PIDR6_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR6_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR6_FUNC(void)
{
    return 0x844000010fd8ll;
}

#define typedef_BDK_GTI_RD_PIDR6 bdk_gti_rd_pidr6_t
#define bustype_BDK_GTI_RD_PIDR6 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_RD_PIDR6 "GTI_RD_PIDR6"
#define busnum_BDK_GTI_RD_PIDR6 0
#define arguments_BDK_GTI_RD_PIDR6 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_rd_pidr7
 *
 * GTI Counter Read Peripheral Identification Register 7
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_rd_pidr7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_rd_pidr7_s cn; */
} bdk_gti_rd_pidr7_t;

#define BDK_GTI_RD_PIDR7 BDK_GTI_RD_PIDR7_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR7_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR7_FUNC(void)
{
    return 0x844000010fdcll;
}

#define typedef_BDK_GTI_RD_PIDR7 bdk_gti_rd_pidr7_t
#define bustype_BDK_GTI_RD_PIDR7 BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_RD_PIDR7 "GTI_RD_PIDR7"
#define busnum_BDK_GTI_RD_PIDR7 0
#define arguments_BDK_GTI_RD_PIDR7 -1,-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_cidr0
 *
 * GTI Watchdog Control Component Identification Register 0
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_cidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_cidr0_s cn; */
} bdk_gti_wcx_cidr0_t;

static inline uint64_t BDK_GTI_WCX_CIDR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_CIDR0(unsigned long a)
{
    if (a<=1)
        return 0x844000080ff0ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_CIDR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_CIDR0(a) bdk_gti_wcx_cidr0_t
#define bustype_BDK_GTI_WCX_CIDR0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_CIDR0(a) "GTI_WCX_CIDR0"
#define busnum_BDK_GTI_WCX_CIDR0(a) (a)
#define arguments_BDK_GTI_WCX_CIDR0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_cidr1
 *
 * GTI Watchdog Control Component Identification Register 1
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_cidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cclass                : 4;  /**< [  7:  4](RO) Component class. */
        uint32_t preamble              : 4;  /**< [  3:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 4;  /**< [  3:  0](RO) Preamble identification value. */
        uint32_t cclass                : 4;  /**< [  7:  4](RO) Component class. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_cidr1_s cn; */
} bdk_gti_wcx_cidr1_t;

static inline uint64_t BDK_GTI_WCX_CIDR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_CIDR1(unsigned long a)
{
    if (a<=1)
        return 0x844000080ff4ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_CIDR1", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_CIDR1(a) bdk_gti_wcx_cidr1_t
#define bustype_BDK_GTI_WCX_CIDR1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_CIDR1(a) "GTI_WCX_CIDR1"
#define busnum_BDK_GTI_WCX_CIDR1(a) (a)
#define arguments_BDK_GTI_WCX_CIDR1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_cidr2
 *
 * GTI Watchdog Control Component Identification Register 2
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_cidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_cidr2_s cn; */
} bdk_gti_wcx_cidr2_t;

static inline uint64_t BDK_GTI_WCX_CIDR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_CIDR2(unsigned long a)
{
    if (a<=1)
        return 0x844000080ff8ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_CIDR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_CIDR2(a) bdk_gti_wcx_cidr2_t
#define bustype_BDK_GTI_WCX_CIDR2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_CIDR2(a) "GTI_WCX_CIDR2"
#define busnum_BDK_GTI_WCX_CIDR2(a) (a)
#define arguments_BDK_GTI_WCX_CIDR2(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_cidr3
 *
 * GTI Watchdog Control Component Identification Register 3
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_cidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_cidr3_s cn; */
} bdk_gti_wcx_cidr3_t;

static inline uint64_t BDK_GTI_WCX_CIDR3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_CIDR3(unsigned long a)
{
    if (a<=1)
        return 0x844000080ffcll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_CIDR3", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_CIDR3(a) bdk_gti_wcx_cidr3_t
#define bustype_BDK_GTI_WCX_CIDR3(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_CIDR3(a) "GTI_WCX_CIDR3"
#define busnum_BDK_GTI_WCX_CIDR3(a) (a)
#define arguments_BDK_GTI_WCX_CIDR3(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_pidr0
 *
 * GTI Watchdog Control Peripheral Identification Register 0
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_pidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t partnum0              : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_WC. */
#else /* Word 0 - Little Endian */
        uint32_t partnum0              : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_WC. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_pidr0_s cn; */
} bdk_gti_wcx_pidr0_t;

static inline uint64_t BDK_GTI_WCX_PIDR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR0(unsigned long a)
{
    if (a<=1)
        return 0x844000080fe0ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_PIDR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_PIDR0(a) bdk_gti_wcx_pidr0_t
#define bustype_BDK_GTI_WCX_PIDR0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_PIDR0(a) "GTI_WCX_PIDR0"
#define busnum_BDK_GTI_WCX_PIDR0(a) (a)
#define arguments_BDK_GTI_WCX_PIDR0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_pidr1
 *
 * GTI Watchdog Control Peripheral Identification Register 1
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_pidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t idcode                : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t partnum1              : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else /* Word 0 - Little Endian */
        uint32_t partnum1              : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
        uint32_t idcode                : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_pidr1_s cn; */
} bdk_gti_wcx_pidr1_t;

static inline uint64_t BDK_GTI_WCX_PIDR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR1(unsigned long a)
{
    if (a<=1)
        return 0x844000080fe4ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_PIDR1", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_PIDR1(a) bdk_gti_wcx_pidr1_t
#define bustype_BDK_GTI_WCX_PIDR1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_PIDR1(a) "GTI_WCX_PIDR1"
#define busnum_BDK_GTI_WCX_PIDR1(a) (a)
#define arguments_BDK_GTI_WCX_PIDR1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_pidr2
 *
 * GTI Watchdog Control Peripheral Identification Register 2
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_pidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revision              : 4;  /**< [  7:  4](RO) Architectural revision, as assigned by ARM. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t idcode                : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else /* Word 0 - Little Endian */
        uint32_t idcode                : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t revision              : 4;  /**< [  7:  4](RO) Architectural revision, as assigned by ARM. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_pidr2_s cn; */
} bdk_gti_wcx_pidr2_t;

static inline uint64_t BDK_GTI_WCX_PIDR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR2(unsigned long a)
{
    if (a<=1)
        return 0x844000080fe8ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_PIDR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_PIDR2(a) bdk_gti_wcx_pidr2_t
#define bustype_BDK_GTI_WCX_PIDR2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_PIDR2(a) "GTI_WCX_PIDR2"
#define busnum_BDK_GTI_WCX_PIDR2(a) (a)
#define arguments_BDK_GTI_WCX_PIDR2(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_pidr3
 *
 * GTI Watchdog Control Peripheral Identification Register 3
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_pidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t cust                  : 4;  /**< [  3:  0](RO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else /* Word 0 - Little Endian */
        uint32_t cust                  : 4;  /**< [  3:  0](RO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_pidr3_s cn; */
} bdk_gti_wcx_pidr3_t;

static inline uint64_t BDK_GTI_WCX_PIDR3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR3(unsigned long a)
{
    if (a<=1)
        return 0x844000080fecll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_PIDR3", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_PIDR3(a) bdk_gti_wcx_pidr3_t
#define bustype_BDK_GTI_WCX_PIDR3(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_PIDR3(a) "GTI_WCX_PIDR3"
#define busnum_BDK_GTI_WCX_PIDR3(a) (a)
#define arguments_BDK_GTI_WCX_PIDR3(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_pidr4
 *
 * GTI Watchdog Control Peripheral Identification Register 4
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_pidr4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t pagecnt               : 4;  /**< [  7:  4](RO) Number of log-2 4 KB blocks occupied. */
        uint32_t jepcont               : 4;  /**< [  3:  0](RO) JEP106 continuation code. Indicates Cavium. */
#else /* Word 0 - Little Endian */
        uint32_t jepcont               : 4;  /**< [  3:  0](RO) JEP106 continuation code. Indicates Cavium. */
        uint32_t pagecnt               : 4;  /**< [  7:  4](RO) Number of log-2 4 KB blocks occupied. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_pidr4_s cn; */
} bdk_gti_wcx_pidr4_t;

static inline uint64_t BDK_GTI_WCX_PIDR4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR4(unsigned long a)
{
    if (a<=1)
        return 0x844000080fd0ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_PIDR4", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_PIDR4(a) bdk_gti_wcx_pidr4_t
#define bustype_BDK_GTI_WCX_PIDR4(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_PIDR4(a) "GTI_WCX_PIDR4"
#define busnum_BDK_GTI_WCX_PIDR4(a) (a)
#define arguments_BDK_GTI_WCX_PIDR4(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_pidr5
 *
 * GTI Watchdog Control Peripheral Identification Register 5
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_pidr5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_pidr5_s cn; */
} bdk_gti_wcx_pidr5_t;

static inline uint64_t BDK_GTI_WCX_PIDR5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR5(unsigned long a)
{
    if (a<=1)
        return 0x844000080fd4ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_PIDR5", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_PIDR5(a) bdk_gti_wcx_pidr5_t
#define bustype_BDK_GTI_WCX_PIDR5(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_PIDR5(a) "GTI_WCX_PIDR5"
#define busnum_BDK_GTI_WCX_PIDR5(a) (a)
#define arguments_BDK_GTI_WCX_PIDR5(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_pidr6
 *
 * GTI Watchdog Control Peripheral Identification Register 6
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_pidr6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_pidr6_s cn; */
} bdk_gti_wcx_pidr6_t;

static inline uint64_t BDK_GTI_WCX_PIDR6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR6(unsigned long a)
{
    if (a<=1)
        return 0x844000080fd8ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_PIDR6", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_PIDR6(a) bdk_gti_wcx_pidr6_t
#define bustype_BDK_GTI_WCX_PIDR6(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_PIDR6(a) "GTI_WCX_PIDR6"
#define busnum_BDK_GTI_WCX_PIDR6(a) (a)
#define arguments_BDK_GTI_WCX_PIDR6(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_pidr7
 *
 * GTI Watchdog Control Peripheral Identification Register 7
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_pidr7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_pidr7_s cn; */
} bdk_gti_wcx_pidr7_t;

static inline uint64_t BDK_GTI_WCX_PIDR7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR7(unsigned long a)
{
    if (a<=1)
        return 0x844000080fdcll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_PIDR7", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_PIDR7(a) bdk_gti_wcx_pidr7_t
#define bustype_BDK_GTI_WCX_PIDR7(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_PIDR7(a) "GTI_WCX_PIDR7"
#define busnum_BDK_GTI_WCX_PIDR7(a) (a)
#define arguments_BDK_GTI_WCX_PIDR7(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_w_iidr
 *
 * GTI Watchdog Control Interface Identification Register
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_w_iidr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t productid             : 8;  /**< [ 31: 24](RO) An implementation defined product number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN83XX. */
        uint32_t variant               : 4;  /**< [ 23: 20](RO) Variant field.
                                                                 Note in the SBSA this is defined as part of the product identification.
                                                                 In CNXXXX, the major pass number. */
        uint32_t arch                  : 4;  /**< [ 19: 16](RO) Architecture revision. 0x0 = SBSA 1.0 watchdogs. */
        uint32_t revision              : 4;  /**< [ 15: 12](RO) Indicates the minor revision of the product.
                                                                 In CNXXXX, the minor pass number. */
        uint32_t implementer           : 12; /**< [ 11:  0](RO) Indicates the implementer: 0x34C = Cavium. */
#else /* Word 0 - Little Endian */
        uint32_t implementer           : 12; /**< [ 11:  0](RO) Indicates the implementer: 0x34C = Cavium. */
        uint32_t revision              : 4;  /**< [ 15: 12](RO) Indicates the minor revision of the product.
                                                                 In CNXXXX, the minor pass number. */
        uint32_t arch                  : 4;  /**< [ 19: 16](RO) Architecture revision. 0x0 = SBSA 1.0 watchdogs. */
        uint32_t variant               : 4;  /**< [ 23: 20](RO) Variant field.
                                                                 Note in the SBSA this is defined as part of the product identification.
                                                                 In CNXXXX, the major pass number. */
        uint32_t productid             : 8;  /**< [ 31: 24](RO) An implementation defined product number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN83XX. */
#endif /* Word 0 - End */
    } s;
    struct bdk_gti_wcx_w_iidr_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t productid             : 8;  /**< [ 31: 24](RO) An implementation defined product number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN88XX. */
        uint32_t variant               : 4;  /**< [ 23: 20](RO) Variant field.
                                                                 Note in the SBSA this is defined as part of the product identification.
                                                                 In CNXXXX, the major pass number. */
        uint32_t arch                  : 4;  /**< [ 19: 16](RO) Architecture revision. 0x0 = SBSA 1.0 watchdogs. */
        uint32_t revision              : 4;  /**< [ 15: 12](RO) Indicates the minor revision of the product.
                                                                 In CNXXXX, the minor pass number. */
        uint32_t implementer           : 12; /**< [ 11:  0](RO) Indicates the implementer: 0x34C = Cavium. */
#else /* Word 0 - Little Endian */
        uint32_t implementer           : 12; /**< [ 11:  0](RO) Indicates the implementer: 0x34C = Cavium. */
        uint32_t revision              : 4;  /**< [ 15: 12](RO) Indicates the minor revision of the product.
                                                                 In CNXXXX, the minor pass number. */
        uint32_t arch                  : 4;  /**< [ 19: 16](RO) Architecture revision. 0x0 = SBSA 1.0 watchdogs. */
        uint32_t variant               : 4;  /**< [ 23: 20](RO) Variant field.
                                                                 Note in the SBSA this is defined as part of the product identification.
                                                                 In CNXXXX, the major pass number. */
        uint32_t productid             : 8;  /**< [ 31: 24](RO) An implementation defined product number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN88XX. */
#endif /* Word 0 - End */
    } cn88xx;
    /* struct bdk_gti_wcx_w_iidr_s cn83xx; */
} bdk_gti_wcx_w_iidr_t;

static inline uint64_t BDK_GTI_WCX_W_IIDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_W_IIDR(unsigned long a)
{
    if (a<=1)
        return 0x844000080fccll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_W_IIDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_W_IIDR(a) bdk_gti_wcx_w_iidr_t
#define bustype_BDK_GTI_WCX_W_IIDR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_W_IIDR(a) "GTI_WCX_W_IIDR"
#define busnum_BDK_GTI_WCX_W_IIDR(a) (a)
#define arguments_BDK_GTI_WCX_W_IIDR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_wcs
 *
 * GTI Watchdog Control and Status Register
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_wcs_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_3_31         : 29;
        uint32_t ws1                   : 1;  /**< [  2:  2](RO/H) WS1 */
        uint32_t ws0                   : 1;  /**< [  1:  1](RO/H) WS0 */
        uint32_t en                    : 1;  /**< [  0:  0](R/W) Enable. */
#else /* Word 0 - Little Endian */
        uint32_t en                    : 1;  /**< [  0:  0](R/W) Enable. */
        uint32_t ws0                   : 1;  /**< [  1:  1](RO/H) WS0 */
        uint32_t ws1                   : 1;  /**< [  2:  2](RO/H) WS1 */
        uint32_t reserved_3_31         : 29;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_wcs_s cn; */
} bdk_gti_wcx_wcs_t;

static inline uint64_t BDK_GTI_WCX_WCS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_WCS(unsigned long a)
{
    if (a<=1)
        return 0x844000080000ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_WCS", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_WCS(a) bdk_gti_wcx_wcs_t
#define bustype_BDK_GTI_WCX_WCS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_WCS(a) "GTI_WCX_WCS"
#define busnum_BDK_GTI_WCX_WCS(a) (a)
#define arguments_BDK_GTI_WCX_WCS(a) (a),-1,-1,-1

/**
 * Register (NCB) gti_wc#_wcv
 *
 * GTI Watchdog Control Compare Value Register
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union
{
    uint64_t u;
    struct bdk_gti_wcx_wcv_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t wdcv                  : 64; /**< [ 63:  0](R/W/H) Watchdog compare value. */
#else /* Word 0 - Little Endian */
        uint64_t wdcv                  : 64; /**< [ 63:  0](R/W/H) Watchdog compare value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_wcv_s cn; */
} bdk_gti_wcx_wcv_t;

static inline uint64_t BDK_GTI_WCX_WCV(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_WCV(unsigned long a)
{
    if (a<=1)
        return 0x844000080010ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_WCV", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_WCV(a) bdk_gti_wcx_wcv_t
#define bustype_BDK_GTI_WCX_WCV(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GTI_WCX_WCV(a) "GTI_WCX_WCV"
#define busnum_BDK_GTI_WCX_WCV(a) (a)
#define arguments_BDK_GTI_WCX_WCV(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wc#_wor
 *
 * GTI Watchdog Control Offset Register
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wcx_wor_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t offset                : 32; /**< [ 31:  0](R/W/H) Watchdog offset. */
#else /* Word 0 - Little Endian */
        uint32_t offset                : 32; /**< [ 31:  0](R/W/H) Watchdog offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wcx_wor_s cn; */
} bdk_gti_wcx_wor_t;

static inline uint64_t BDK_GTI_WCX_WOR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_WOR(unsigned long a)
{
    if (a<=1)
        return 0x844000080008ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WCX_WOR", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WCX_WOR(a) bdk_gti_wcx_wor_t
#define bustype_BDK_GTI_WCX_WOR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WCX_WOR(a) "GTI_WCX_WOR"
#define busnum_BDK_GTI_WCX_WOR(a) (a)
#define arguments_BDK_GTI_WCX_WOR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wr#_cidr0
 *
 * GTI Watchdog Refresh Component Identification Register 0
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wrx_cidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wrx_cidr0_s cn; */
} bdk_gti_wrx_cidr0_t;

static inline uint64_t BDK_GTI_WRX_CIDR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_CIDR0(unsigned long a)
{
    if (a<=1)
        return 0x844000090ff0ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WRX_CIDR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WRX_CIDR0(a) bdk_gti_wrx_cidr0_t
#define bustype_BDK_GTI_WRX_CIDR0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WRX_CIDR0(a) "GTI_WRX_CIDR0"
#define busnum_BDK_GTI_WRX_CIDR0(a) (a)
#define arguments_BDK_GTI_WRX_CIDR0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wr#_cidr1
 *
 * GTI Watchdog Refresh Component Identification Register 1
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wrx_cidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cclass                : 4;  /**< [  7:  4](RO) Component class. */
        uint32_t preamble              : 4;  /**< [  3:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 4;  /**< [  3:  0](RO) Preamble identification value. */
        uint32_t cclass                : 4;  /**< [  7:  4](RO) Component class. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wrx_cidr1_s cn; */
} bdk_gti_wrx_cidr1_t;

static inline uint64_t BDK_GTI_WRX_CIDR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_CIDR1(unsigned long a)
{
    if (a<=1)
        return 0x844000090ff4ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WRX_CIDR1", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WRX_CIDR1(a) bdk_gti_wrx_cidr1_t
#define bustype_BDK_GTI_WRX_CIDR1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WRX_CIDR1(a) "GTI_WRX_CIDR1"
#define busnum_BDK_GTI_WRX_CIDR1(a) (a)
#define arguments_BDK_GTI_WRX_CIDR1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wr#_cidr2
 *
 * GTI Watchdog Refresh Component Identification Register 2
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wrx_cidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wrx_cidr2_s cn; */
} bdk_gti_wrx_cidr2_t;

static inline uint64_t BDK_GTI_WRX_CIDR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_CIDR2(unsigned long a)
{
    if (a<=1)
        return 0x844000090ff8ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WRX_CIDR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WRX_CIDR2(a) bdk_gti_wrx_cidr2_t
#define bustype_BDK_GTI_WRX_CIDR2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WRX_CIDR2(a) "GTI_WRX_CIDR2"
#define busnum_BDK_GTI_WRX_CIDR2(a) (a)
#define arguments_BDK_GTI_WRX_CIDR2(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wr#_cidr3
 *
 * GTI Watchdog Refresh Component Identification Register 3
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wrx_cidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wrx_cidr3_s cn; */
} bdk_gti_wrx_cidr3_t;

static inline uint64_t BDK_GTI_WRX_CIDR3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_CIDR3(unsigned long a)
{
    if (a<=1)
        return 0x844000090ffcll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WRX_CIDR3", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WRX_CIDR3(a) bdk_gti_wrx_cidr3_t
#define bustype_BDK_GTI_WRX_CIDR3(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WRX_CIDR3(a) "GTI_WRX_CIDR3"
#define busnum_BDK_GTI_WRX_CIDR3(a) (a)
#define arguments_BDK_GTI_WRX_CIDR3(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wr#_pidr0
 *
 * GTI Watchdog Refresh Peripheral Identification Register 0
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wrx_pidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t partnum0              : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_WR. */
#else /* Word 0 - Little Endian */
        uint32_t partnum0              : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_WR. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wrx_pidr0_s cn; */
} bdk_gti_wrx_pidr0_t;

static inline uint64_t BDK_GTI_WRX_PIDR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR0(unsigned long a)
{
    if (a<=1)
        return 0x844000090fe0ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WRX_PIDR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WRX_PIDR0(a) bdk_gti_wrx_pidr0_t
#define bustype_BDK_GTI_WRX_PIDR0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WRX_PIDR0(a) "GTI_WRX_PIDR0"
#define busnum_BDK_GTI_WRX_PIDR0(a) (a)
#define arguments_BDK_GTI_WRX_PIDR0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wr#_pidr1
 *
 * GTI Watchdog Refresh Peripheral Identification Register 1
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wrx_pidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t idcode                : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t partnum1              : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else /* Word 0 - Little Endian */
        uint32_t partnum1              : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
        uint32_t idcode                : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wrx_pidr1_s cn; */
} bdk_gti_wrx_pidr1_t;

static inline uint64_t BDK_GTI_WRX_PIDR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR1(unsigned long a)
{
    if (a<=1)
        return 0x844000090fe4ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WRX_PIDR1", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WRX_PIDR1(a) bdk_gti_wrx_pidr1_t
#define bustype_BDK_GTI_WRX_PIDR1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WRX_PIDR1(a) "GTI_WRX_PIDR1"
#define busnum_BDK_GTI_WRX_PIDR1(a) (a)
#define arguments_BDK_GTI_WRX_PIDR1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wr#_pidr2
 *
 * GTI Watchdog Refresh Peripheral Identification Register 2
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wrx_pidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revision              : 4;  /**< [  7:  4](RO) Architectural revision, as assigned by ARM. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t idcode                : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else /* Word 0 - Little Endian */
        uint32_t idcode                : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t revision              : 4;  /**< [  7:  4](RO) Architectural revision, as assigned by ARM. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wrx_pidr2_s cn; */
} bdk_gti_wrx_pidr2_t;

static inline uint64_t BDK_GTI_WRX_PIDR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR2(unsigned long a)
{
    if (a<=1)
        return 0x844000090fe8ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WRX_PIDR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WRX_PIDR2(a) bdk_gti_wrx_pidr2_t
#define bustype_BDK_GTI_WRX_PIDR2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WRX_PIDR2(a) "GTI_WRX_PIDR2"
#define busnum_BDK_GTI_WRX_PIDR2(a) (a)
#define arguments_BDK_GTI_WRX_PIDR2(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wr#_pidr3
 *
 * GTI Watchdog Refresh Peripheral Identification Register 3
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wrx_pidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t cust                  : 4;  /**< [  3:  0](RO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else /* Word 0 - Little Endian */
        uint32_t cust                  : 4;  /**< [  3:  0](RO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wrx_pidr3_s cn; */
} bdk_gti_wrx_pidr3_t;

static inline uint64_t BDK_GTI_WRX_PIDR3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR3(unsigned long a)
{
    if (a<=1)
        return 0x844000090fecll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WRX_PIDR3", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WRX_PIDR3(a) bdk_gti_wrx_pidr3_t
#define bustype_BDK_GTI_WRX_PIDR3(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WRX_PIDR3(a) "GTI_WRX_PIDR3"
#define busnum_BDK_GTI_WRX_PIDR3(a) (a)
#define arguments_BDK_GTI_WRX_PIDR3(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wr#_pidr4
 *
 * GTI Watchdog Refresh Peripheral Identification Register 4
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wrx_pidr4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t pagecnt               : 4;  /**< [  7:  4](RO) Number of log-2 4 KB blocks occupied. */
        uint32_t jepcont               : 4;  /**< [  3:  0](RO) JEP106 continuation code. Indicates Cavium. */
#else /* Word 0 - Little Endian */
        uint32_t jepcont               : 4;  /**< [  3:  0](RO) JEP106 continuation code. Indicates Cavium. */
        uint32_t pagecnt               : 4;  /**< [  7:  4](RO) Number of log-2 4 KB blocks occupied. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wrx_pidr4_s cn; */
} bdk_gti_wrx_pidr4_t;

static inline uint64_t BDK_GTI_WRX_PIDR4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR4(unsigned long a)
{
    if (a<=1)
        return 0x844000090fd0ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WRX_PIDR4", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WRX_PIDR4(a) bdk_gti_wrx_pidr4_t
#define bustype_BDK_GTI_WRX_PIDR4(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WRX_PIDR4(a) "GTI_WRX_PIDR4"
#define busnum_BDK_GTI_WRX_PIDR4(a) (a)
#define arguments_BDK_GTI_WRX_PIDR4(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wr#_pidr5
 *
 * GTI Watchdog Refresh Peripheral Identification Register 5
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wrx_pidr5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wrx_pidr5_s cn; */
} bdk_gti_wrx_pidr5_t;

static inline uint64_t BDK_GTI_WRX_PIDR5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR5(unsigned long a)
{
    if (a<=1)
        return 0x844000090fd4ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WRX_PIDR5", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WRX_PIDR5(a) bdk_gti_wrx_pidr5_t
#define bustype_BDK_GTI_WRX_PIDR5(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WRX_PIDR5(a) "GTI_WRX_PIDR5"
#define busnum_BDK_GTI_WRX_PIDR5(a) (a)
#define arguments_BDK_GTI_WRX_PIDR5(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wr#_pidr6
 *
 * GTI Watchdog Refresh Peripheral Identification Register 6
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wrx_pidr6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wrx_pidr6_s cn; */
} bdk_gti_wrx_pidr6_t;

static inline uint64_t BDK_GTI_WRX_PIDR6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR6(unsigned long a)
{
    if (a<=1)
        return 0x844000090fd8ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WRX_PIDR6", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WRX_PIDR6(a) bdk_gti_wrx_pidr6_t
#define bustype_BDK_GTI_WRX_PIDR6(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WRX_PIDR6(a) "GTI_WRX_PIDR6"
#define busnum_BDK_GTI_WRX_PIDR6(a) (a)
#define arguments_BDK_GTI_WRX_PIDR6(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wr#_pidr7
 *
 * GTI Watchdog Refresh Peripheral Identification Register 7
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wrx_pidr7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wrx_pidr7_s cn; */
} bdk_gti_wrx_pidr7_t;

static inline uint64_t BDK_GTI_WRX_PIDR7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR7(unsigned long a)
{
    if (a<=1)
        return 0x844000090fdcll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WRX_PIDR7", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WRX_PIDR7(a) bdk_gti_wrx_pidr7_t
#define bustype_BDK_GTI_WRX_PIDR7(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WRX_PIDR7(a) "GTI_WRX_PIDR7"
#define busnum_BDK_GTI_WRX_PIDR7(a) (a)
#define arguments_BDK_GTI_WRX_PIDR7(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wr#_w_iidr
 *
 * GTI Watchdog Refresh Interface Identification Register
 * GTI_WR(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WR(1) accesses the non-secure watchdog.
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wrx_w_iidr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t productid             : 8;  /**< [ 31: 24](RO) An implementation defined product number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN83XX. */
        uint32_t variant               : 4;  /**< [ 23: 20](RO) Variant field.
                                                                 Note in the SBSA this is defined as part of the product identification.
                                                                 In CNXXXX, the major pass number. */
        uint32_t arch                  : 4;  /**< [ 19: 16](RO) Architecture revision. 0x0 = SBSA 1.0 watchdogs. */
        uint32_t revision              : 4;  /**< [ 15: 12](RO) Indicates the minor revision of the product.
                                                                 In CNXXXX, the minor pass number. */
        uint32_t implementer           : 12; /**< [ 11:  0](RO) Indicates the implementer: 0x34C = Cavium. */
#else /* Word 0 - Little Endian */
        uint32_t implementer           : 12; /**< [ 11:  0](RO) Indicates the implementer: 0x34C = Cavium. */
        uint32_t revision              : 4;  /**< [ 15: 12](RO) Indicates the minor revision of the product.
                                                                 In CNXXXX, the minor pass number. */
        uint32_t arch                  : 4;  /**< [ 19: 16](RO) Architecture revision. 0x0 = SBSA 1.0 watchdogs. */
        uint32_t variant               : 4;  /**< [ 23: 20](RO) Variant field.
                                                                 Note in the SBSA this is defined as part of the product identification.
                                                                 In CNXXXX, the major pass number. */
        uint32_t productid             : 8;  /**< [ 31: 24](RO) An implementation defined product number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN83XX. */
#endif /* Word 0 - End */
    } s;
    struct bdk_gti_wrx_w_iidr_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t productid             : 8;  /**< [ 31: 24](RO) An implementation defined product number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN88XX. */
        uint32_t variant               : 4;  /**< [ 23: 20](RO) Variant field.
                                                                 Note in the SBSA this is defined as part of the product identification.
                                                                 In CNXXXX, the major pass number. */
        uint32_t arch                  : 4;  /**< [ 19: 16](RO) Architecture revision. 0x0 = SBSA 1.0 watchdogs. */
        uint32_t revision              : 4;  /**< [ 15: 12](RO) Indicates the minor revision of the product.
                                                                 In CNXXXX, the minor pass number. */
        uint32_t implementer           : 12; /**< [ 11:  0](RO) Indicates the implementer: 0x34C = Cavium. */
#else /* Word 0 - Little Endian */
        uint32_t implementer           : 12; /**< [ 11:  0](RO) Indicates the implementer: 0x34C = Cavium. */
        uint32_t revision              : 4;  /**< [ 15: 12](RO) Indicates the minor revision of the product.
                                                                 In CNXXXX, the minor pass number. */
        uint32_t arch                  : 4;  /**< [ 19: 16](RO) Architecture revision. 0x0 = SBSA 1.0 watchdogs. */
        uint32_t variant               : 4;  /**< [ 23: 20](RO) Variant field.
                                                                 Note in the SBSA this is defined as part of the product identification.
                                                                 In CNXXXX, the major pass number. */
        uint32_t productid             : 8;  /**< [ 31: 24](RO) An implementation defined product number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN88XX. */
#endif /* Word 0 - End */
    } cn88xx;
    /* struct bdk_gti_wrx_w_iidr_s cn83xx; */
} bdk_gti_wrx_w_iidr_t;

static inline uint64_t BDK_GTI_WRX_W_IIDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_W_IIDR(unsigned long a)
{
    if (a<=1)
        return 0x844000090fccll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WRX_W_IIDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WRX_W_IIDR(a) bdk_gti_wrx_w_iidr_t
#define bustype_BDK_GTI_WRX_W_IIDR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WRX_W_IIDR(a) "GTI_WRX_W_IIDR"
#define busnum_BDK_GTI_WRX_W_IIDR(a) (a)
#define arguments_BDK_GTI_WRX_W_IIDR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) gti_wr#_wrr
 *
 * GTI Watchdog Refresh Register
 * GTI_WR(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WR(1) accesses the non-secure watchdog.
 */
typedef union
{
    uint32_t u;
    struct bdk_gti_wrx_wrr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t zero                  : 32; /**< [ 31:  0](WO) Watchdog refresh. */
#else /* Word 0 - Little Endian */
        uint32_t zero                  : 32; /**< [ 31:  0](WO) Watchdog refresh. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gti_wrx_wrr_s cn; */
} bdk_gti_wrx_wrr_t;

static inline uint64_t BDK_GTI_WRX_WRR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_WRR(unsigned long a)
{
    if (a<=1)
        return 0x844000090000ll + 0x20000ll * ((a) & 0x1);
    __bdk_csr_fatal("GTI_WRX_WRR", 1, a, 0, 0, 0);
}

#define typedef_BDK_GTI_WRX_WRR(a) bdk_gti_wrx_wrr_t
#define bustype_BDK_GTI_WRX_WRR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_GTI_WRX_WRR(a) "GTI_WRX_WRR"
#define busnum_BDK_GTI_WRX_WRR(a) (a)
#define arguments_BDK_GTI_WRX_WRR(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_GTI_H__ */
