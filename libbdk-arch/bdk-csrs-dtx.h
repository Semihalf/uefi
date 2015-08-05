#ifndef __BDK_CSRS_DTX_H__
#define __BDK_CSRS_DTX_H__
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
 * Cavium DTX.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (RSL) dtx_mio_dat#
 *
 * DTX MIO Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_mio_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_mio_datx_s cn; */
} bdk_dtx_mio_datx_t;

static inline uint64_t BDK_DTX_MIO_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MIO_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe000040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_MIO_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_MIO_DATX(a) bdk_dtx_mio_datx_t
#define bustype_BDK_DTX_MIO_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_MIO_DATX(a) "DTX_MIO_DATX"
#define busnum_BDK_DTX_MIO_DATX(a) (a)
#define arguments_BDK_DTX_MIO_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_mrml_bcst_rsp
 *
 * DTX MRML Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_mrml_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_mrml_bcst_rsp_s cn; */
} bdk_dtx_mrml_bcst_rsp_t;

#define BDK_DTX_MRML_BCST_RSP BDK_DTX_MRML_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_MRML_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MRML_BCST_RSP_FUNC(void)
{
    return 0x87e0fe7e0080ll;
}

#define typedef_BDK_DTX_MRML_BCST_RSP bdk_dtx_mrml_bcst_rsp_t
#define bustype_BDK_DTX_MRML_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_MRML_BCST_RSP "DTX_MRML_BCST_RSP"
#define busnum_BDK_DTX_MRML_BCST_RSP 0
#define arguments_BDK_DTX_MRML_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_dfa_dat#
 *
 * DTX DFA Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_dfa_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_dfa_datx_s cn; */
} bdk_dtx_dfa_datx_t;

static inline uint64_t BDK_DTX_DFA_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DFA_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fea30040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_DFA_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_DFA_DATX(a) bdk_dtx_dfa_datx_t
#define bustype_BDK_DTX_DFA_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_DFA_DATX(a) "DTX_DFA_DATX"
#define busnum_BDK_DTX_DFA_DATX(a) (a)
#define arguments_BDK_DTX_DFA_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_mio_ctl
 *
 * DTX MIO Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_mio_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_mio_ctl_s cn; */
} bdk_dtx_mio_ctl_t;

#define BDK_DTX_MIO_CTL BDK_DTX_MIO_CTL_FUNC()
static inline uint64_t BDK_DTX_MIO_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MIO_CTL_FUNC(void)
{
    return 0x87e0fe000060ll;
}

#define typedef_BDK_DTX_MIO_CTL bdk_dtx_mio_ctl_t
#define bustype_BDK_DTX_MIO_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_MIO_CTL "DTX_MIO_CTL"
#define busnum_BDK_DTX_MIO_CTL 0
#define arguments_BDK_DTX_MIO_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_rnm_ena#
 *
 * DTX RNM Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rnm_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rnm_enax_s cn; */
} bdk_dtx_rnm_enax_t;

static inline uint64_t BDK_DTX_RNM_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RNM_ENAX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe200020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_RNM_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_RNM_ENAX(a) bdk_dtx_rnm_enax_t
#define bustype_BDK_DTX_RNM_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RNM_ENAX(a) "DTX_RNM_ENAX"
#define busnum_BDK_DTX_RNM_ENAX(a) (a)
#define arguments_BDK_DTX_RNM_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_gic_dat#
 *
 * DTX GIC Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_gic_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_gic_datx_s cn; */
} bdk_dtx_gic_datx_t;

static inline uint64_t BDK_DTX_GIC_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GIC_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe808040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_GIC_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_GIC_DATX(a) bdk_dtx_gic_datx_t
#define bustype_BDK_DTX_GIC_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_GIC_DATX(a) "DTX_GIC_DATX"
#define busnum_BDK_DTX_GIC_DATX(a) (a)
#define arguments_BDK_DTX_GIC_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_sata#_ctl
 *
 * DTX SATA Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_satax_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_satax_ctl_s cn; */
} bdk_dtx_satax_ctl_t;

static inline uint64_t BDK_DTX_SATAX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SATAX_CTL(unsigned long a)
{
    if (a<=15)
        return 0x87e0fe880060ll + 0x8000ll * ((a) & 0xf);
    __bdk_csr_fatal("DTX_SATAX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_SATAX_CTL(a) bdk_dtx_satax_ctl_t
#define bustype_BDK_DTX_SATAX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_SATAX_CTL(a) "DTX_SATAX_CTL"
#define busnum_BDK_DTX_SATAX_CTL(a) (a)
#define arguments_BDK_DTX_SATAX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_tns_ena#
 *
 * DTX TNS Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_tns_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_tns_enax_s cn; */
} bdk_dtx_tns_enax_t;

static inline uint64_t BDK_DTX_TNS_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_TNS_ENAX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fea10020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_TNS_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_TNS_ENAX(a) bdk_dtx_tns_enax_t
#define bustype_BDK_DTX_TNS_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_TNS_ENAX(a) "DTX_TNS_ENAX"
#define busnum_BDK_DTX_TNS_ENAX(a) (a)
#define arguments_BDK_DTX_TNS_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_rad_ctl
 *
 * DTX RAD Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rad_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rad_ctl_s cn; */
} bdk_dtx_rad_ctl_t;

#define BDK_DTX_RAD_CTL BDK_DTX_RAD_CTL_FUNC()
static inline uint64_t BDK_DTX_RAD_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RAD_CTL_FUNC(void)
{
    return 0x87e0feb80060ll;
}

#define typedef_BDK_DTX_RAD_CTL bdk_dtx_rad_ctl_t
#define bustype_BDK_DTX_RAD_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RAD_CTL "DTX_RAD_CTL"
#define busnum_BDK_DTX_RAD_CTL 0
#define arguments_BDK_DTX_RAD_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_rst_sel#
 *
 * DTX RST Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rst_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rst_selx_s cn; */
} bdk_dtx_rst_selx_t;

static inline uint64_t BDK_DTX_RST_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RST_SELX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe030000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_RST_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_RST_SELX(a) bdk_dtx_rst_selx_t
#define bustype_BDK_DTX_RST_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RST_SELX(a) "DTX_RST_SELX"
#define busnum_BDK_DTX_RST_SELX(a) (a)
#define arguments_BDK_DTX_RST_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_ocx_lnk#_ena#
 *
 * DTX OCX_LNK Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_lnkx_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_lnkx_enax_s cn; */
} bdk_dtx_ocx_lnkx_enax_t;

static inline uint64_t BDK_DTX_OCX_LNKX_ENAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_LNKX_ENAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=2) && (b<=1)))
        return 0x87e0fe180020ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_OCX_LNKX_ENAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_OCX_LNKX_ENAX(a,b) bdk_dtx_ocx_lnkx_enax_t
#define bustype_BDK_DTX_OCX_LNKX_ENAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_LNKX_ENAX(a,b) "DTX_OCX_LNKX_ENAX"
#define busnum_BDK_DTX_OCX_LNKX_ENAX(a,b) (a)
#define arguments_BDK_DTX_OCX_LNKX_ENAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_l2c_cbc#_sel#
 *
 * DTX L2C_CBC Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_cbcx_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_cbcx_selx_s cn; */
} bdk_dtx_l2c_cbcx_selx_t;

static inline uint64_t BDK_DTX_L2C_CBCX_SELX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_CBCX_SELX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=1)))
        return 0x87e0fe2c0000ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=1)))
        return 0x87e0fe2c0000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_L2C_CBCX_SELX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_L2C_CBCX_SELX(a,b) bdk_dtx_l2c_cbcx_selx_t
#define bustype_BDK_DTX_L2C_CBCX_SELX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_CBCX_SELX(a,b) "DTX_L2C_CBCX_SELX"
#define busnum_BDK_DTX_L2C_CBCX_SELX(a,b) (a)
#define arguments_BDK_DTX_L2C_CBCX_SELX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_lmc#_ena#
 *
 * DTX LMC Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_lmcx_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_lmcx_enax_s cn; */
} bdk_dtx_lmcx_enax_t;

static inline uint64_t BDK_DTX_LMCX_ENAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_LMCX_ENAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=1)))
        return 0x87e0fe440020ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=1)))
        return 0x87e0fe440020ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_LMCX_ENAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_LMCX_ENAX(a,b) bdk_dtx_lmcx_enax_t
#define bustype_BDK_DTX_LMCX_ENAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_LMCX_ENAX(a,b) "DTX_LMCX_ENAX"
#define busnum_BDK_DTX_LMCX_ENAX(a,b) (a)
#define arguments_BDK_DTX_LMCX_ENAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_l2c_tad#_sel#
 *
 * DTX L2C_TAD Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_tadx_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_tadx_selx_s cn; */
} bdk_dtx_l2c_tadx_selx_t;

static inline uint64_t BDK_DTX_L2C_TADX_SELX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_TADX_SELX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=1)))
        return 0x87e0fe280000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=7) && (b<=1)))
        return 0x87e0fe280000ll + 0x8000ll * ((a) & 0x7) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_L2C_TADX_SELX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_L2C_TADX_SELX(a,b) bdk_dtx_l2c_tadx_selx_t
#define bustype_BDK_DTX_L2C_TADX_SELX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_TADX_SELX(a,b) "DTX_L2C_TADX_SELX"
#define busnum_BDK_DTX_L2C_TADX_SELX(a,b) (a)
#define arguments_BDK_DTX_L2C_TADX_SELX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_ocx_ole#_bcst_rsp
 *
 * DTX OCX_OLE Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_olex_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_olex_bcst_rsp_s cn; */
} bdk_dtx_ocx_olex_bcst_rsp_t;

static inline uint64_t BDK_DTX_OCX_OLEX_BCST_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_OLEX_BCST_RSP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=2))
        return 0x87e0fe1a0080ll + 0x8000ll * ((a) & 0x3);
    __bdk_csr_fatal("DTX_OCX_OLEX_BCST_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_OCX_OLEX_BCST_RSP(a) bdk_dtx_ocx_olex_bcst_rsp_t
#define bustype_BDK_DTX_OCX_OLEX_BCST_RSP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_OLEX_BCST_RSP(a) "DTX_OCX_OLEX_BCST_RSP"
#define busnum_BDK_DTX_OCX_OLEX_BCST_RSP(a) (a)
#define arguments_BDK_DTX_OCX_OLEX_BCST_RSP(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_iobn#_sel#
 *
 * DTX IOBN Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_iobnx_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_iobnx_selx_s cn; */
} bdk_dtx_iobnx_selx_t;

static inline uint64_t BDK_DTX_IOBNX_SELX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_IOBNX_SELX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0fe780000ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_IOBNX_SELX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_IOBNX_SELX(a,b) bdk_dtx_iobnx_selx_t
#define bustype_BDK_DTX_IOBNX_SELX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_IOBNX_SELX(a,b) "DTX_IOBNX_SELX"
#define busnum_BDK_DTX_IOBNX_SELX(a,b) (a)
#define arguments_BDK_DTX_IOBNX_SELX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_key_bcst_rsp
 *
 * DTX KEY Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_key_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_key_bcst_rsp_s cn; */
} bdk_dtx_key_bcst_rsp_t;

#define BDK_DTX_KEY_BCST_RSP BDK_DTX_KEY_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_KEY_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_KEY_BCST_RSP_FUNC(void)
{
    return 0x87e0fe208080ll;
}

#define typedef_BDK_DTX_KEY_BCST_RSP bdk_dtx_key_bcst_rsp_t
#define bustype_BDK_DTX_KEY_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_KEY_BCST_RSP "DTX_KEY_BCST_RSP"
#define busnum_BDK_DTX_KEY_BCST_RSP 0
#define arguments_BDK_DTX_KEY_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_sata#_ena#
 *
 * DTX SATA Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_satax_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_satax_enax_s cn; */
} bdk_dtx_satax_enax_t;

static inline uint64_t BDK_DTX_SATAX_ENAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SATAX_ENAX(unsigned long a, unsigned long b)
{
    if ((a<=15) && (b<=1))
        return 0x87e0fe880020ll + 0x8000ll * ((a) & 0xf) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_SATAX_ENAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_SATAX_ENAX(a,b) bdk_dtx_satax_enax_t
#define bustype_BDK_DTX_SATAX_ENAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_SATAX_ENAX(a,b) "DTX_SATAX_ENAX"
#define busnum_BDK_DTX_SATAX_ENAX(a,b) (a)
#define arguments_BDK_DTX_SATAX_ENAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_key_sel#
 *
 * DTX KEY Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_key_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_key_selx_s cn; */
} bdk_dtx_key_selx_t;

static inline uint64_t BDK_DTX_KEY_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_KEY_SELX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe208000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_KEY_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_KEY_SELX(a) bdk_dtx_key_selx_t
#define bustype_BDK_DTX_KEY_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_KEY_SELX(a) "DTX_KEY_SELX"
#define busnum_BDK_DTX_KEY_SELX(a) (a)
#define arguments_BDK_DTX_KEY_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_uaa#_dat#
 *
 * DTX UAA Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_uaax_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_uaax_datx_s cn; */
} bdk_dtx_uaax_datx_t;

static inline uint64_t BDK_DTX_UAAX_DATX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_UAAX_DATX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0fe120040ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_UAAX_DATX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_UAAX_DATX(a,b) bdk_dtx_uaax_datx_t
#define bustype_BDK_DTX_UAAX_DATX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_UAAX_DATX(a,b) "DTX_UAAX_DATX"
#define busnum_BDK_DTX_UAAX_DATX(a,b) (a)
#define arguments_BDK_DTX_UAAX_DATX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_key_dat#
 *
 * DTX KEY Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_key_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_key_datx_s cn; */
} bdk_dtx_key_datx_t;

static inline uint64_t BDK_DTX_KEY_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_KEY_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe208040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_KEY_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_KEY_DATX(a) bdk_dtx_key_datx_t
#define bustype_BDK_DTX_KEY_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_KEY_DATX(a) "DTX_KEY_DATX"
#define busnum_BDK_DTX_KEY_DATX(a) (a)
#define arguments_BDK_DTX_KEY_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_gser#_ena#
 *
 * DTX GSER Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_gserx_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_gserx_enax_s cn; */
} bdk_dtx_gserx_enax_t;

static inline uint64_t BDK_DTX_GSERX_ENAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GSERX_ENAX(unsigned long a, unsigned long b)
{
    if ((a<=13) && (b<=1))
        return 0x87e0fe480020ll + 0x8000ll * ((a) & 0xf) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_GSERX_ENAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_GSERX_ENAX(a,b) bdk_dtx_gserx_enax_t
#define bustype_BDK_DTX_GSERX_ENAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_GSERX_ENAX(a,b) "DTX_GSERX_ENAX"
#define busnum_BDK_DTX_GSERX_ENAX(a,b) (a)
#define arguments_BDK_DTX_GSERX_ENAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_zip_bcst_rsp
 *
 * DTX ZIP Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_zip_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_zip_bcst_rsp_s cn; */
} bdk_dtx_zip_bcst_rsp_t;

#define BDK_DTX_ZIP_BCST_RSP BDK_DTX_ZIP_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_ZIP_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_ZIP_BCST_RSP_FUNC(void)
{
    return 0x87e0fe9c0080ll;
}

#define typedef_BDK_DTX_ZIP_BCST_RSP bdk_dtx_zip_bcst_rsp_t
#define bustype_BDK_DTX_ZIP_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_ZIP_BCST_RSP "DTX_ZIP_BCST_RSP"
#define busnum_BDK_DTX_ZIP_BCST_RSP 0
#define arguments_BDK_DTX_ZIP_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_ocx_bot_dat#
 *
 * INTERNAL: DTX OCX_BOT Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_bot_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_bot_datx_s cn; */
} bdk_dtx_ocx_bot_datx_t;

static inline uint64_t BDK_DTX_OCX_BOT_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_BOT_DATX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=1))
        return 0x87e0fe198040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_OCX_BOT_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_OCX_BOT_DATX(a) bdk_dtx_ocx_bot_datx_t
#define bustype_BDK_DTX_OCX_BOT_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_BOT_DATX(a) "DTX_OCX_BOT_DATX"
#define busnum_BDK_DTX_OCX_BOT_DATX(a) (a)
#define arguments_BDK_DTX_OCX_BOT_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_l2c_mci#_ctl
 *
 * DTX L2C_MCI Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_mcix_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_mcix_ctl_s cn; */
} bdk_dtx_l2c_mcix_ctl_t;

static inline uint64_t BDK_DTX_L2C_MCIX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_MCIX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=2))
        return 0x87e0fe2e0060ll + 0x8000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x87e0fe2e0060ll + 0x8000ll * ((a) & 0x3);
    __bdk_csr_fatal("DTX_L2C_MCIX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_L2C_MCIX_CTL(a) bdk_dtx_l2c_mcix_ctl_t
#define bustype_BDK_DTX_L2C_MCIX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_MCIX_CTL(a) "DTX_L2C_MCIX_CTL"
#define busnum_BDK_DTX_L2C_MCIX_CTL(a) (a)
#define arguments_BDK_DTX_L2C_MCIX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_zip_sel#
 *
 * DTX ZIP Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_zip_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_zip_selx_s cn; */
} bdk_dtx_zip_selx_t;

static inline uint64_t BDK_DTX_ZIP_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_ZIP_SELX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe9c0000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_ZIP_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_ZIP_SELX(a) bdk_dtx_zip_selx_t
#define bustype_BDK_DTX_ZIP_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_ZIP_SELX(a) "DTX_ZIP_SELX"
#define busnum_BDK_DTX_ZIP_SELX(a) (a)
#define arguments_BDK_DTX_ZIP_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_gser#_dat#
 *
 * DTX GSER Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_gserx_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_gserx_datx_s cn; */
} bdk_dtx_gserx_datx_t;

static inline uint64_t BDK_DTX_GSERX_DATX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GSERX_DATX(unsigned long a, unsigned long b)
{
    if ((a<=13) && (b<=1))
        return 0x87e0fe480040ll + 0x8000ll * ((a) & 0xf) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_GSERX_DATX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_GSERX_DATX(a,b) bdk_dtx_gserx_datx_t
#define bustype_BDK_DTX_GSERX_DATX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_GSERX_DATX(a,b) "DTX_GSERX_DATX"
#define busnum_BDK_DTX_GSERX_DATX(a,b) (a)
#define arguments_BDK_DTX_GSERX_DATX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_dap_ctl
 *
 * DTX DAP Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_dap_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_dap_ctl_s cn; */
} bdk_dtx_dap_ctl_t;

#define BDK_DTX_DAP_CTL BDK_DTX_DAP_CTL_FUNC()
static inline uint64_t BDK_DTX_DAP_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DAP_CTL_FUNC(void)
{
    return 0x87e0fe010060ll;
}

#define typedef_BDK_DTX_DAP_CTL bdk_dtx_dap_ctl_t
#define bustype_BDK_DTX_DAP_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_DAP_CTL "DTX_DAP_CTL"
#define busnum_BDK_DTX_DAP_CTL 0
#define arguments_BDK_DTX_DAP_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_zip_ctl
 *
 * DTX ZIP Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_zip_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_zip_ctl_s cn; */
} bdk_dtx_zip_ctl_t;

#define BDK_DTX_ZIP_CTL BDK_DTX_ZIP_CTL_FUNC()
static inline uint64_t BDK_DTX_ZIP_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_ZIP_CTL_FUNC(void)
{
    return 0x87e0fe9c0060ll;
}

#define typedef_BDK_DTX_ZIP_CTL bdk_dtx_zip_ctl_t
#define bustype_BDK_DTX_ZIP_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_ZIP_CTL "DTX_ZIP_CTL"
#define busnum_BDK_DTX_ZIP_CTL 0
#define arguments_BDK_DTX_ZIP_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_ocx_lnk#_dat#
 *
 * DTX OCX_LNK Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_lnkx_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_lnkx_datx_s cn; */
} bdk_dtx_ocx_lnkx_datx_t;

static inline uint64_t BDK_DTX_OCX_LNKX_DATX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_LNKX_DATX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=2) && (b<=1)))
        return 0x87e0fe180040ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_OCX_LNKX_DATX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_OCX_LNKX_DATX(a,b) bdk_dtx_ocx_lnkx_datx_t
#define bustype_BDK_DTX_OCX_LNKX_DATX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_LNKX_DATX(a,b) "DTX_OCX_LNKX_DATX"
#define busnum_BDK_DTX_OCX_LNKX_DATX(a,b) (a)
#define arguments_BDK_DTX_OCX_LNKX_DATX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_l2c_mci#_sel#
 *
 * DTX L2C_MCI Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_mcix_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_mcix_selx_s cn; */
} bdk_dtx_l2c_mcix_selx_t;

static inline uint64_t BDK_DTX_L2C_MCIX_SELX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_MCIX_SELX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=2) && (b<=1)))
        return 0x87e0fe2e0000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=1)))
        return 0x87e0fe2e0000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_L2C_MCIX_SELX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_L2C_MCIX_SELX(a,b) bdk_dtx_l2c_mcix_selx_t
#define bustype_BDK_DTX_L2C_MCIX_SELX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_MCIX_SELX(a,b) "DTX_L2C_MCIX_SELX"
#define busnum_BDK_DTX_L2C_MCIX_SELX(a,b) (a)
#define arguments_BDK_DTX_L2C_MCIX_SELX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_usbh#_ctl
 *
 * DTX USBH Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_usbhx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_usbhx_ctl_s cn; */
} bdk_dtx_usbhx_ctl_t;

static inline uint64_t BDK_DTX_USBHX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_USBHX_CTL(unsigned long a)
{
    if (a<=1)
        return 0x87e0feb40060ll + 0x8000ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_USBHX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_USBHX_CTL(a) bdk_dtx_usbhx_ctl_t
#define bustype_BDK_DTX_USBHX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_USBHX_CTL(a) "DTX_USBHX_CTL"
#define busnum_BDK_DTX_USBHX_CTL(a) (a)
#define arguments_BDK_DTX_USBHX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_ocx_ole#_dat#
 *
 * DTX OCX_OLE Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_olex_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_olex_datx_s cn; */
} bdk_dtx_ocx_olex_datx_t;

static inline uint64_t BDK_DTX_OCX_OLEX_DATX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_OLEX_DATX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=2) && (b<=1)))
        return 0x87e0fe1a0040ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_OCX_OLEX_DATX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_OCX_OLEX_DATX(a,b) bdk_dtx_ocx_olex_datx_t
#define bustype_BDK_DTX_OCX_OLEX_DATX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_OLEX_DATX(a,b) "DTX_OCX_OLEX_DATX"
#define busnum_BDK_DTX_OCX_OLEX_DATX(a,b) (a)
#define arguments_BDK_DTX_OCX_OLEX_DATX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_ocx_top_sel#
 *
 * DTX OCX_TOP Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_top_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_top_selx_s cn; */
} bdk_dtx_ocx_top_selx_t;

static inline uint64_t BDK_DTX_OCX_TOP_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_TOP_SELX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=1))
        return 0x87e0fe088000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_OCX_TOP_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_OCX_TOP_SELX(a) bdk_dtx_ocx_top_selx_t
#define bustype_BDK_DTX_OCX_TOP_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_TOP_SELX(a) "DTX_OCX_TOP_SELX"
#define busnum_BDK_DTX_OCX_TOP_SELX(a) (a)
#define arguments_BDK_DTX_OCX_TOP_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_uaa#_bcst_rsp
 *
 * DTX UAA Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_uaax_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_uaax_bcst_rsp_s cn; */
} bdk_dtx_uaax_bcst_rsp_t;

static inline uint64_t BDK_DTX_UAAX_BCST_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_UAAX_BCST_RSP(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe120080ll + 0x8000ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_UAAX_BCST_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_UAAX_BCST_RSP(a) bdk_dtx_uaax_bcst_rsp_t
#define bustype_BDK_DTX_UAAX_BCST_RSP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_UAAX_BCST_RSP(a) "DTX_UAAX_BCST_RSP"
#define busnum_BDK_DTX_UAAX_BCST_RSP(a) (a)
#define arguments_BDK_DTX_UAAX_BCST_RSP(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_bgx#_ena#
 *
 * DTX BGX Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_bgxx_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_bgxx_enax_s cn; */
} bdk_dtx_bgxx_enax_t;

static inline uint64_t BDK_DTX_BGXX_ENAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BGXX_ENAX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0fe700020ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_BGXX_ENAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_BGXX_ENAX(a,b) bdk_dtx_bgxx_enax_t
#define bustype_BDK_DTX_BGXX_ENAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_BGXX_ENAX(a,b) "DTX_BGXX_ENAX"
#define busnum_BDK_DTX_BGXX_ENAX(a,b) (a)
#define arguments_BDK_DTX_BGXX_ENAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_ocx_bot_bcst_rsp
 *
 * INTERNAL: DTX OCX_BOT Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_bot_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_bot_bcst_rsp_s cn; */
} bdk_dtx_ocx_bot_bcst_rsp_t;

#define BDK_DTX_OCX_BOT_BCST_RSP BDK_DTX_OCX_BOT_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_OCX_BOT_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_BOT_BCST_RSP_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e0fe198080ll;
    __bdk_csr_fatal("DTX_OCX_BOT_BCST_RSP", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DTX_OCX_BOT_BCST_RSP bdk_dtx_ocx_bot_bcst_rsp_t
#define bustype_BDK_DTX_OCX_BOT_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_BOT_BCST_RSP "DTX_OCX_BOT_BCST_RSP"
#define busnum_BDK_DTX_OCX_BOT_BCST_RSP 0
#define arguments_BDK_DTX_OCX_BOT_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_dfa_sel#
 *
 * DTX DFA Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_dfa_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_dfa_selx_s cn; */
} bdk_dtx_dfa_selx_t;

static inline uint64_t BDK_DTX_DFA_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DFA_SELX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fea30000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_DFA_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_DFA_SELX(a) bdk_dtx_dfa_selx_t
#define bustype_BDK_DTX_DFA_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_DFA_SELX(a) "DTX_DFA_SELX"
#define busnum_BDK_DTX_DFA_SELX(a) (a)
#define arguments_BDK_DTX_DFA_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_sli#_ctl
 *
 * DTX SLI Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_slix_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_slix_ctl_s cn; */
} bdk_dtx_slix_ctl_t;

static inline uint64_t BDK_DTX_SLIX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SLIX_CTL(unsigned long a)
{
    if (a<=1)
        return 0x87e0feba0060ll + 0x8000ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_SLIX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_SLIX_CTL(a) bdk_dtx_slix_ctl_t
#define bustype_BDK_DTX_SLIX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_SLIX_CTL(a) "DTX_SLIX_CTL"
#define busnum_BDK_DTX_SLIX_CTL(a) (a)
#define arguments_BDK_DTX_SLIX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_rad_bcst_rsp
 *
 * DTX RAD Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rad_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rad_bcst_rsp_s cn; */
} bdk_dtx_rad_bcst_rsp_t;

#define BDK_DTX_RAD_BCST_RSP BDK_DTX_RAD_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_RAD_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RAD_BCST_RSP_FUNC(void)
{
    return 0x87e0feb80080ll;
}

#define typedef_BDK_DTX_RAD_BCST_RSP bdk_dtx_rad_bcst_rsp_t
#define bustype_BDK_DTX_RAD_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RAD_BCST_RSP "DTX_RAD_BCST_RSP"
#define busnum_BDK_DTX_RAD_BCST_RSP 0
#define arguments_BDK_DTX_RAD_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_lmc#_ctl
 *
 * DTX LMC Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_lmcx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_lmcx_ctl_s cn; */
} bdk_dtx_lmcx_ctl_t;

static inline uint64_t BDK_DTX_LMCX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_LMCX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e0fe440060ll + 0x8000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x87e0fe440060ll + 0x8000ll * ((a) & 0x3);
    __bdk_csr_fatal("DTX_LMCX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_LMCX_CTL(a) bdk_dtx_lmcx_ctl_t
#define bustype_BDK_DTX_LMCX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_LMCX_CTL(a) "DTX_LMCX_CTL"
#define busnum_BDK_DTX_LMCX_CTL(a) (a)
#define arguments_BDK_DTX_LMCX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_rnm_sel#
 *
 * DTX RNM Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rnm_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rnm_selx_s cn; */
} bdk_dtx_rnm_selx_t;

static inline uint64_t BDK_DTX_RNM_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RNM_SELX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe200000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_RNM_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_RNM_SELX(a) bdk_dtx_rnm_selx_t
#define bustype_BDK_DTX_RNM_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RNM_SELX(a) "DTX_RNM_SELX"
#define busnum_BDK_DTX_RNM_SELX(a) (a)
#define arguments_BDK_DTX_RNM_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_sli#_ena#
 *
 * DTX SLI Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_slix_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_slix_enax_s cn; */
} bdk_dtx_slix_enax_t;

static inline uint64_t BDK_DTX_SLIX_ENAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SLIX_ENAX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0feba0020ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_SLIX_ENAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_SLIX_ENAX(a,b) bdk_dtx_slix_enax_t
#define bustype_BDK_DTX_SLIX_ENAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_SLIX_ENAX(a,b) "DTX_SLIX_ENAX"
#define busnum_BDK_DTX_SLIX_ENAX(a,b) (a)
#define arguments_BDK_DTX_SLIX_ENAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_sli#_sel#
 *
 * DTX SLI Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_slix_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_slix_selx_s cn; */
} bdk_dtx_slix_selx_t;

static inline uint64_t BDK_DTX_SLIX_SELX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SLIX_SELX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0feba0000ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_SLIX_SELX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_SLIX_SELX(a,b) bdk_dtx_slix_selx_t
#define bustype_BDK_DTX_SLIX_SELX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_SLIX_SELX(a,b) "DTX_SLIX_SELX"
#define busnum_BDK_DTX_SLIX_SELX(a,b) (a)
#define arguments_BDK_DTX_SLIX_SELX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_ncsi_ena#
 *
 * DTX NCSI Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ncsi_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ncsi_enax_s cn; */
} bdk_dtx_ncsi_enax_t;

static inline uint64_t BDK_DTX_NCSI_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NCSI_ENAX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe058020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_NCSI_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_NCSI_ENAX(a) bdk_dtx_ncsi_enax_t
#define bustype_BDK_DTX_NCSI_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_NCSI_ENAX(a) "DTX_NCSI_ENAX"
#define busnum_BDK_DTX_NCSI_ENAX(a) (a)
#define arguments_BDK_DTX_NCSI_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_pem#_bcst_rsp
 *
 * DTX PEM Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_pemx_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_pemx_bcst_rsp_s cn; */
} bdk_dtx_pemx_bcst_rsp_t;

static inline uint64_t BDK_DTX_PEMX_BCST_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_PEMX_BCST_RSP(unsigned long a)
{
    if (a<=5)
        return 0x87e0fe600080ll + 0x8000ll * ((a) & 0x7);
    __bdk_csr_fatal("DTX_PEMX_BCST_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_PEMX_BCST_RSP(a) bdk_dtx_pemx_bcst_rsp_t
#define bustype_BDK_DTX_PEMX_BCST_RSP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_PEMX_BCST_RSP(a) "DTX_PEMX_BCST_RSP"
#define busnum_BDK_DTX_PEMX_BCST_RSP(a) (a)
#define arguments_BDK_DTX_PEMX_BCST_RSP(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_lmc#_bcst_rsp
 *
 * DTX LMC Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_lmcx_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_lmcx_bcst_rsp_s cn; */
} bdk_dtx_lmcx_bcst_rsp_t;

static inline uint64_t BDK_DTX_LMCX_BCST_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_LMCX_BCST_RSP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e0fe440080ll + 0x8000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x87e0fe440080ll + 0x8000ll * ((a) & 0x3);
    __bdk_csr_fatal("DTX_LMCX_BCST_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_LMCX_BCST_RSP(a) bdk_dtx_lmcx_bcst_rsp_t
#define bustype_BDK_DTX_LMCX_BCST_RSP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_LMCX_BCST_RSP(a) "DTX_LMCX_BCST_RSP"
#define busnum_BDK_DTX_LMCX_BCST_RSP(a) (a)
#define arguments_BDK_DTX_LMCX_BCST_RSP(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_ocx_ole#_ena#
 *
 * DTX OCX_OLE Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_olex_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_olex_enax_s cn; */
} bdk_dtx_ocx_olex_enax_t;

static inline uint64_t BDK_DTX_OCX_OLEX_ENAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_OLEX_ENAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=2) && (b<=1)))
        return 0x87e0fe1a0020ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_OCX_OLEX_ENAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_OCX_OLEX_ENAX(a,b) bdk_dtx_ocx_olex_enax_t
#define bustype_BDK_DTX_OCX_OLEX_ENAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_OLEX_ENAX(a,b) "DTX_OCX_OLEX_ENAX"
#define busnum_BDK_DTX_OCX_OLEX_ENAX(a,b) (a)
#define arguments_BDK_DTX_OCX_OLEX_ENAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_nic_dat#
 *
 * DTX NIC Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_nic_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_nic_datx_s cn; */
} bdk_dtx_nic_datx_t;

static inline uint64_t BDK_DTX_NIC_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NIC_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fea18040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_NIC_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_NIC_DATX(a) bdk_dtx_nic_datx_t
#define bustype_BDK_DTX_NIC_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_NIC_DATX(a) "DTX_NIC_DATX"
#define busnum_BDK_DTX_NIC_DATX(a) (a)
#define arguments_BDK_DTX_NIC_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_dfa_ctl
 *
 * DTX DFA Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_dfa_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_dfa_ctl_s cn; */
} bdk_dtx_dfa_ctl_t;

#define BDK_DTX_DFA_CTL BDK_DTX_DFA_CTL_FUNC()
static inline uint64_t BDK_DTX_DFA_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DFA_CTL_FUNC(void)
{
    return 0x87e0fea30060ll;
}

#define typedef_BDK_DTX_DFA_CTL bdk_dtx_dfa_ctl_t
#define bustype_BDK_DTX_DFA_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_DFA_CTL "DTX_DFA_CTL"
#define busnum_BDK_DTX_DFA_CTL 0
#define arguments_BDK_DTX_DFA_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_nic_sel#
 *
 * DTX NIC Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_nic_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_nic_selx_s cn; */
} bdk_dtx_nic_selx_t;

static inline uint64_t BDK_DTX_NIC_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NIC_SELX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fea18000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_NIC_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_NIC_SELX(a) bdk_dtx_nic_selx_t
#define bustype_BDK_DTX_NIC_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_NIC_SELX(a) "DTX_NIC_SELX"
#define busnum_BDK_DTX_NIC_SELX(a) (a)
#define arguments_BDK_DTX_NIC_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_broadcast_ena#
 *
 * DTX BROADCAST Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_broadcast_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_broadcast_enax_s cn; */
} bdk_dtx_broadcast_enax_t;

static inline uint64_t BDK_DTX_BROADCAST_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BROADCAST_ENAX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe7f0020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_BROADCAST_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_BROADCAST_ENAX(a) bdk_dtx_broadcast_enax_t
#define bustype_BDK_DTX_BROADCAST_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_BROADCAST_ENAX(a) "DTX_BROADCAST_ENAX"
#define busnum_BDK_DTX_BROADCAST_ENAX(a) (a)
#define arguments_BDK_DTX_BROADCAST_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_usbh#_sel#
 *
 * DTX USBH Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_usbhx_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_usbhx_selx_s cn; */
} bdk_dtx_usbhx_selx_t;

static inline uint64_t BDK_DTX_USBHX_SELX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_USBHX_SELX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0feb40000ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_USBHX_SELX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_USBHX_SELX(a,b) bdk_dtx_usbhx_selx_t
#define bustype_BDK_DTX_USBHX_SELX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_USBHX_SELX(a,b) "DTX_USBHX_SELX"
#define busnum_BDK_DTX_USBHX_SELX(a,b) (a)
#define arguments_BDK_DTX_USBHX_SELX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_nic_bcst_rsp
 *
 * DTX NIC Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_nic_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_nic_bcst_rsp_s cn; */
} bdk_dtx_nic_bcst_rsp_t;

#define BDK_DTX_NIC_BCST_RSP BDK_DTX_NIC_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_NIC_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NIC_BCST_RSP_FUNC(void)
{
    return 0x87e0fea18080ll;
}

#define typedef_BDK_DTX_NIC_BCST_RSP bdk_dtx_nic_bcst_rsp_t
#define bustype_BDK_DTX_NIC_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_NIC_BCST_RSP "DTX_NIC_BCST_RSP"
#define busnum_BDK_DTX_NIC_BCST_RSP 0
#define arguments_BDK_DTX_NIC_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_sata#_sel#
 *
 * DTX SATA Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_satax_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_satax_selx_s cn; */
} bdk_dtx_satax_selx_t;

static inline uint64_t BDK_DTX_SATAX_SELX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SATAX_SELX(unsigned long a, unsigned long b)
{
    if ((a<=15) && (b<=1))
        return 0x87e0fe880000ll + 0x8000ll * ((a) & 0xf) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_SATAX_SELX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_SATAX_SELX(a,b) bdk_dtx_satax_selx_t
#define bustype_BDK_DTX_SATAX_SELX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_SATAX_SELX(a,b) "DTX_SATAX_SELX"
#define busnum_BDK_DTX_SATAX_SELX(a,b) (a)
#define arguments_BDK_DTX_SATAX_SELX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_rad_ena#
 *
 * DTX RAD Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rad_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rad_enax_s cn; */
} bdk_dtx_rad_enax_t;

static inline uint64_t BDK_DTX_RAD_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RAD_ENAX(unsigned long a)
{
    if (a<=1)
        return 0x87e0feb80020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_RAD_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_RAD_ENAX(a) bdk_dtx_rad_enax_t
#define bustype_BDK_DTX_RAD_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RAD_ENAX(a) "DTX_RAD_ENAX"
#define busnum_BDK_DTX_RAD_ENAX(a) (a)
#define arguments_BDK_DTX_RAD_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_dap_dat#
 *
 * DTX DAP Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_dap_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_dap_datx_s cn; */
} bdk_dtx_dap_datx_t;

static inline uint64_t BDK_DTX_DAP_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DAP_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe010040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_DAP_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_DAP_DATX(a) bdk_dtx_dap_datx_t
#define bustype_BDK_DTX_DAP_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_DAP_DATX(a) "DTX_DAP_DATX"
#define busnum_BDK_DTX_DAP_DATX(a) (a)
#define arguments_BDK_DTX_DAP_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_bgx#_sel#
 *
 * DTX BGX Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_bgxx_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_bgxx_selx_s cn; */
} bdk_dtx_bgxx_selx_t;

static inline uint64_t BDK_DTX_BGXX_SELX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BGXX_SELX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0fe700000ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_BGXX_SELX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_BGXX_SELX(a,b) bdk_dtx_bgxx_selx_t
#define bustype_BDK_DTX_BGXX_SELX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_BGXX_SELX(a,b) "DTX_BGXX_SELX"
#define busnum_BDK_DTX_BGXX_SELX(a,b) (a)
#define arguments_BDK_DTX_BGXX_SELX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_mrml_sel#
 *
 * DTX MRML Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_mrml_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_mrml_selx_s cn; */
} bdk_dtx_mrml_selx_t;

static inline uint64_t BDK_DTX_MRML_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MRML_SELX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe7e0000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_MRML_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_MRML_SELX(a) bdk_dtx_mrml_selx_t
#define bustype_BDK_DTX_MRML_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_MRML_SELX(a) "DTX_MRML_SELX"
#define busnum_BDK_DTX_MRML_SELX(a) (a)
#define arguments_BDK_DTX_MRML_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_sata#_bcst_rsp
 *
 * DTX SATA Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_satax_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_satax_bcst_rsp_s cn; */
} bdk_dtx_satax_bcst_rsp_t;

static inline uint64_t BDK_DTX_SATAX_BCST_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SATAX_BCST_RSP(unsigned long a)
{
    if (a<=15)
        return 0x87e0fe880080ll + 0x8000ll * ((a) & 0xf);
    __bdk_csr_fatal("DTX_SATAX_BCST_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_SATAX_BCST_RSP(a) bdk_dtx_satax_bcst_rsp_t
#define bustype_BDK_DTX_SATAX_BCST_RSP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_SATAX_BCST_RSP(a) "DTX_SATAX_BCST_RSP"
#define busnum_BDK_DTX_SATAX_BCST_RSP(a) (a)
#define arguments_BDK_DTX_SATAX_BCST_RSP(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_broadcast_ctl
 *
 * DTX BROADCAST Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_broadcast_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_broadcast_ctl_s cn; */
} bdk_dtx_broadcast_ctl_t;

#define BDK_DTX_BROADCAST_CTL BDK_DTX_BROADCAST_CTL_FUNC()
static inline uint64_t BDK_DTX_BROADCAST_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BROADCAST_CTL_FUNC(void)
{
    return 0x87e0fe7f0060ll;
}

#define typedef_BDK_DTX_BROADCAST_CTL bdk_dtx_broadcast_ctl_t
#define bustype_BDK_DTX_BROADCAST_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_BROADCAST_CTL "DTX_BROADCAST_CTL"
#define busnum_BDK_DTX_BROADCAST_CTL 0
#define arguments_BDK_DTX_BROADCAST_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_ocx_bot_ena#
 *
 * INTERNAL: DTX OCX_BOT Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_bot_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_bot_enax_s cn; */
} bdk_dtx_ocx_bot_enax_t;

static inline uint64_t BDK_DTX_OCX_BOT_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_BOT_ENAX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=1))
        return 0x87e0fe198020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_OCX_BOT_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_OCX_BOT_ENAX(a) bdk_dtx_ocx_bot_enax_t
#define bustype_BDK_DTX_OCX_BOT_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_BOT_ENAX(a) "DTX_OCX_BOT_ENAX"
#define busnum_BDK_DTX_OCX_BOT_ENAX(a) (a)
#define arguments_BDK_DTX_OCX_BOT_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_dap_ena#
 *
 * DTX DAP Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_dap_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_dap_enax_s cn; */
} bdk_dtx_dap_enax_t;

static inline uint64_t BDK_DTX_DAP_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DAP_ENAX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe010020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_DAP_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_DAP_ENAX(a) bdk_dtx_dap_enax_t
#define bustype_BDK_DTX_DAP_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_DAP_ENAX(a) "DTX_DAP_ENAX"
#define busnum_BDK_DTX_DAP_ENAX(a) (a)
#define arguments_BDK_DTX_DAP_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_ocx_bot_ctl
 *
 * INTERNAL: DTX OCX_BOT Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_bot_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_bot_ctl_s cn; */
} bdk_dtx_ocx_bot_ctl_t;

#define BDK_DTX_OCX_BOT_CTL BDK_DTX_OCX_BOT_CTL_FUNC()
static inline uint64_t BDK_DTX_OCX_BOT_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_BOT_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e0fe198060ll;
    __bdk_csr_fatal("DTX_OCX_BOT_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DTX_OCX_BOT_CTL bdk_dtx_ocx_bot_ctl_t
#define bustype_BDK_DTX_OCX_BOT_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_BOT_CTL "DTX_OCX_BOT_CTL"
#define busnum_BDK_DTX_OCX_BOT_CTL 0
#define arguments_BDK_DTX_OCX_BOT_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_lmc#_sel#
 *
 * DTX LMC Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_lmcx_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_lmcx_selx_s cn; */
} bdk_dtx_lmcx_selx_t;

static inline uint64_t BDK_DTX_LMCX_SELX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_LMCX_SELX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=1)))
        return 0x87e0fe440000ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=1)))
        return 0x87e0fe440000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_LMCX_SELX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_LMCX_SELX(a,b) bdk_dtx_lmcx_selx_t
#define bustype_BDK_DTX_LMCX_SELX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_LMCX_SELX(a,b) "DTX_LMCX_SELX"
#define busnum_BDK_DTX_LMCX_SELX(a,b) (a)
#define arguments_BDK_DTX_LMCX_SELX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_rst_ctl
 *
 * DTX RST Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rst_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rst_ctl_s cn; */
} bdk_dtx_rst_ctl_t;

#define BDK_DTX_RST_CTL BDK_DTX_RST_CTL_FUNC()
static inline uint64_t BDK_DTX_RST_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RST_CTL_FUNC(void)
{
    return 0x87e0fe030060ll;
}

#define typedef_BDK_DTX_RST_CTL bdk_dtx_rst_ctl_t
#define bustype_BDK_DTX_RST_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RST_CTL "DTX_RST_CTL"
#define busnum_BDK_DTX_RST_CTL 0
#define arguments_BDK_DTX_RST_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_rst_dat#
 *
 * DTX RST Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rst_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rst_datx_s cn; */
} bdk_dtx_rst_datx_t;

static inline uint64_t BDK_DTX_RST_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RST_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe030040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_RST_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_RST_DATX(a) bdk_dtx_rst_datx_t
#define bustype_BDK_DTX_RST_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RST_DATX(a) "DTX_RST_DATX"
#define busnum_BDK_DTX_RST_DATX(a) (a)
#define arguments_BDK_DTX_RST_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_dap_sel#
 *
 * DTX DAP Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_dap_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_dap_selx_s cn; */
} bdk_dtx_dap_selx_t;

static inline uint64_t BDK_DTX_DAP_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DAP_SELX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe010000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_DAP_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_DAP_SELX(a) bdk_dtx_dap_selx_t
#define bustype_BDK_DTX_DAP_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_DAP_SELX(a) "DTX_DAP_SELX"
#define busnum_BDK_DTX_DAP_SELX(a) (a)
#define arguments_BDK_DTX_DAP_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_uaa#_ena#
 *
 * DTX UAA Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_uaax_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_uaax_enax_s cn; */
} bdk_dtx_uaax_enax_t;

static inline uint64_t BDK_DTX_UAAX_ENAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_UAAX_ENAX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0fe120020ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_UAAX_ENAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_UAAX_ENAX(a,b) bdk_dtx_uaax_enax_t
#define bustype_BDK_DTX_UAAX_ENAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_UAAX_ENAX(a,b) "DTX_UAAX_ENAX"
#define busnum_BDK_DTX_UAAX_ENAX(a,b) (a)
#define arguments_BDK_DTX_UAAX_ENAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_ocx_bot_sel#
 *
 * INTERNAL: DTX OCX_BOT Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_bot_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_bot_selx_s cn; */
} bdk_dtx_ocx_bot_selx_t;

static inline uint64_t BDK_DTX_OCX_BOT_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_BOT_SELX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=1))
        return 0x87e0fe198000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_OCX_BOT_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_OCX_BOT_SELX(a) bdk_dtx_ocx_bot_selx_t
#define bustype_BDK_DTX_OCX_BOT_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_BOT_SELX(a) "DTX_OCX_BOT_SELX"
#define busnum_BDK_DTX_OCX_BOT_SELX(a) (a)
#define arguments_BDK_DTX_OCX_BOT_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_ocx_ole#_ctl
 *
 * DTX OCX_OLE Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_olex_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_olex_ctl_s cn; */
} bdk_dtx_ocx_olex_ctl_t;

static inline uint64_t BDK_DTX_OCX_OLEX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_OLEX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=2))
        return 0x87e0fe1a0060ll + 0x8000ll * ((a) & 0x3);
    __bdk_csr_fatal("DTX_OCX_OLEX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_OCX_OLEX_CTL(a) bdk_dtx_ocx_olex_ctl_t
#define bustype_BDK_DTX_OCX_OLEX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_OLEX_CTL(a) "DTX_OCX_OLEX_CTL"
#define busnum_BDK_DTX_OCX_OLEX_CTL(a) (a)
#define arguments_BDK_DTX_OCX_OLEX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_dfa_ena#
 *
 * DTX DFA Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_dfa_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_dfa_enax_s cn; */
} bdk_dtx_dfa_enax_t;

static inline uint64_t BDK_DTX_DFA_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DFA_ENAX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fea30020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_DFA_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_DFA_ENAX(a) bdk_dtx_dfa_enax_t
#define bustype_BDK_DTX_DFA_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_DFA_ENAX(a) "DTX_DFA_ENAX"
#define busnum_BDK_DTX_DFA_ENAX(a) (a)
#define arguments_BDK_DTX_DFA_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_usbh#_dat#
 *
 * DTX USBH Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_usbhx_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_usbhx_datx_s cn; */
} bdk_dtx_usbhx_datx_t;

static inline uint64_t BDK_DTX_USBHX_DATX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_USBHX_DATX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0feb40040ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_USBHX_DATX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_USBHX_DATX(a,b) bdk_dtx_usbhx_datx_t
#define bustype_BDK_DTX_USBHX_DATX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_USBHX_DATX(a,b) "DTX_USBHX_DATX"
#define busnum_BDK_DTX_USBHX_DATX(a,b) (a)
#define arguments_BDK_DTX_USBHX_DATX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_mrml_dat#
 *
 * DTX MRML Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_mrml_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_mrml_datx_s cn; */
} bdk_dtx_mrml_datx_t;

static inline uint64_t BDK_DTX_MRML_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MRML_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe7e0040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_MRML_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_MRML_DATX(a) bdk_dtx_mrml_datx_t
#define bustype_BDK_DTX_MRML_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_MRML_DATX(a) "DTX_MRML_DATX"
#define busnum_BDK_DTX_MRML_DATX(a) (a)
#define arguments_BDK_DTX_MRML_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_ocx_lnk#_ctl
 *
 * DTX OCX_LNK Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_lnkx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_lnkx_ctl_s cn; */
} bdk_dtx_ocx_lnkx_ctl_t;

static inline uint64_t BDK_DTX_OCX_LNKX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_LNKX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=2))
        return 0x87e0fe180060ll + 0x8000ll * ((a) & 0x3);
    __bdk_csr_fatal("DTX_OCX_LNKX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_OCX_LNKX_CTL(a) bdk_dtx_ocx_lnkx_ctl_t
#define bustype_BDK_DTX_OCX_LNKX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_LNKX_CTL(a) "DTX_OCX_LNKX_CTL"
#define busnum_BDK_DTX_OCX_LNKX_CTL(a) (a)
#define arguments_BDK_DTX_OCX_LNKX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_mio_ena#
 *
 * DTX MIO Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_mio_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_mio_enax_s cn; */
} bdk_dtx_mio_enax_t;

static inline uint64_t BDK_DTX_MIO_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MIO_ENAX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe000020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_MIO_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_MIO_ENAX(a) bdk_dtx_mio_enax_t
#define bustype_BDK_DTX_MIO_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_MIO_ENAX(a) "DTX_MIO_ENAX"
#define busnum_BDK_DTX_MIO_ENAX(a) (a)
#define arguments_BDK_DTX_MIO_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_pem#_dat#
 *
 * DTX PEM Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_pemx_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_pemx_datx_s cn; */
} bdk_dtx_pemx_datx_t;

static inline uint64_t BDK_DTX_PEMX_DATX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_PEMX_DATX(unsigned long a, unsigned long b)
{
    if ((a<=5) && (b<=1))
        return 0x87e0fe600040ll + 0x8000ll * ((a) & 0x7) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_PEMX_DATX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_PEMX_DATX(a,b) bdk_dtx_pemx_datx_t
#define bustype_BDK_DTX_PEMX_DATX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_PEMX_DATX(a,b) "DTX_PEMX_DATX"
#define busnum_BDK_DTX_PEMX_DATX(a,b) (a)
#define arguments_BDK_DTX_PEMX_DATX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_gser#_ctl
 *
 * DTX GSER Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_gserx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_gserx_ctl_s cn; */
} bdk_dtx_gserx_ctl_t;

static inline uint64_t BDK_DTX_GSERX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GSERX_CTL(unsigned long a)
{
    if (a<=13)
        return 0x87e0fe480060ll + 0x8000ll * ((a) & 0xf);
    __bdk_csr_fatal("DTX_GSERX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_GSERX_CTL(a) bdk_dtx_gserx_ctl_t
#define bustype_BDK_DTX_GSERX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_GSERX_CTL(a) "DTX_GSERX_CTL"
#define busnum_BDK_DTX_GSERX_CTL(a) (a)
#define arguments_BDK_DTX_GSERX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_l2c_mci#_bcst_rsp
 *
 * DTX L2C_MCI Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_mcix_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_mcix_bcst_rsp_s cn; */
} bdk_dtx_l2c_mcix_bcst_rsp_t;

static inline uint64_t BDK_DTX_L2C_MCIX_BCST_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_MCIX_BCST_RSP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=2))
        return 0x87e0fe2e0080ll + 0x8000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x87e0fe2e0080ll + 0x8000ll * ((a) & 0x3);
    __bdk_csr_fatal("DTX_L2C_MCIX_BCST_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_L2C_MCIX_BCST_RSP(a) bdk_dtx_l2c_mcix_bcst_rsp_t
#define bustype_BDK_DTX_L2C_MCIX_BCST_RSP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_MCIX_BCST_RSP(a) "DTX_L2C_MCIX_BCST_RSP"
#define busnum_BDK_DTX_L2C_MCIX_BCST_RSP(a) (a)
#define arguments_BDK_DTX_L2C_MCIX_BCST_RSP(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_rst_ena#
 *
 * DTX RST Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rst_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rst_enax_s cn; */
} bdk_dtx_rst_enax_t;

static inline uint64_t BDK_DTX_RST_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RST_ENAX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe030020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_RST_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_RST_ENAX(a) bdk_dtx_rst_enax_t
#define bustype_BDK_DTX_RST_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RST_ENAX(a) "DTX_RST_ENAX"
#define busnum_BDK_DTX_RST_ENAX(a) (a)
#define arguments_BDK_DTX_RST_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_pem#_ena#
 *
 * DTX PEM Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_pemx_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_pemx_enax_s cn; */
} bdk_dtx_pemx_enax_t;

static inline uint64_t BDK_DTX_PEMX_ENAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_PEMX_ENAX(unsigned long a, unsigned long b)
{
    if ((a<=5) && (b<=1))
        return 0x87e0fe600020ll + 0x8000ll * ((a) & 0x7) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_PEMX_ENAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_PEMX_ENAX(a,b) bdk_dtx_pemx_enax_t
#define bustype_BDK_DTX_PEMX_ENAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_PEMX_ENAX(a,b) "DTX_PEMX_ENAX"
#define busnum_BDK_DTX_PEMX_ENAX(a,b) (a)
#define arguments_BDK_DTX_PEMX_ENAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_ocx_lnk#_sel#
 *
 * DTX OCX_LNK Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_lnkx_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_lnkx_selx_s cn; */
} bdk_dtx_ocx_lnkx_selx_t;

static inline uint64_t BDK_DTX_OCX_LNKX_SELX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_LNKX_SELX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=2) && (b<=1)))
        return 0x87e0fe180000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_OCX_LNKX_SELX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_OCX_LNKX_SELX(a,b) bdk_dtx_ocx_lnkx_selx_t
#define bustype_BDK_DTX_OCX_LNKX_SELX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_LNKX_SELX(a,b) "DTX_OCX_LNKX_SELX"
#define busnum_BDK_DTX_OCX_LNKX_SELX(a,b) (a)
#define arguments_BDK_DTX_OCX_LNKX_SELX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_iobn#_bcst_rsp
 *
 * DTX IOBN Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_iobnx_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_iobnx_bcst_rsp_s cn; */
} bdk_dtx_iobnx_bcst_rsp_t;

static inline uint64_t BDK_DTX_IOBNX_BCST_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_IOBNX_BCST_RSP(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe780080ll + 0x8000ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_IOBNX_BCST_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_IOBNX_BCST_RSP(a) bdk_dtx_iobnx_bcst_rsp_t
#define bustype_BDK_DTX_IOBNX_BCST_RSP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_IOBNX_BCST_RSP(a) "DTX_IOBNX_BCST_RSP"
#define busnum_BDK_DTX_IOBNX_BCST_RSP(a) (a)
#define arguments_BDK_DTX_IOBNX_BCST_RSP(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_sata#_dat#
 *
 * DTX SATA Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_satax_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_satax_datx_s cn; */
} bdk_dtx_satax_datx_t;

static inline uint64_t BDK_DTX_SATAX_DATX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SATAX_DATX(unsigned long a, unsigned long b)
{
    if ((a<=15) && (b<=1))
        return 0x87e0fe880040ll + 0x8000ll * ((a) & 0xf) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_SATAX_DATX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_SATAX_DATX(a,b) bdk_dtx_satax_datx_t
#define bustype_BDK_DTX_SATAX_DATX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_SATAX_DATX(a,b) "DTX_SATAX_DATX"
#define busnum_BDK_DTX_SATAX_DATX(a,b) (a)
#define arguments_BDK_DTX_SATAX_DATX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_rad_dat#
 *
 * DTX RAD Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rad_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rad_datx_s cn; */
} bdk_dtx_rad_datx_t;

static inline uint64_t BDK_DTX_RAD_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RAD_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e0feb80040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_RAD_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_RAD_DATX(a) bdk_dtx_rad_datx_t
#define bustype_BDK_DTX_RAD_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RAD_DATX(a) "DTX_RAD_DATX"
#define busnum_BDK_DTX_RAD_DATX(a) (a)
#define arguments_BDK_DTX_RAD_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_gic_ctl
 *
 * DTX GIC Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_gic_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_gic_ctl_s cn; */
} bdk_dtx_gic_ctl_t;

#define BDK_DTX_GIC_CTL BDK_DTX_GIC_CTL_FUNC()
static inline uint64_t BDK_DTX_GIC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GIC_CTL_FUNC(void)
{
    return 0x87e0fe808060ll;
}

#define typedef_BDK_DTX_GIC_CTL bdk_dtx_gic_ctl_t
#define bustype_BDK_DTX_GIC_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_GIC_CTL "DTX_GIC_CTL"
#define busnum_BDK_DTX_GIC_CTL 0
#define arguments_BDK_DTX_GIC_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_l2c_tad#_dat#
 *
 * DTX L2C_TAD Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_tadx_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_tadx_datx_s cn; */
} bdk_dtx_l2c_tadx_datx_t;

static inline uint64_t BDK_DTX_L2C_TADX_DATX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_TADX_DATX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=1)))
        return 0x87e0fe280040ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=7) && (b<=1)))
        return 0x87e0fe280040ll + 0x8000ll * ((a) & 0x7) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_L2C_TADX_DATX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_L2C_TADX_DATX(a,b) bdk_dtx_l2c_tadx_datx_t
#define bustype_BDK_DTX_L2C_TADX_DATX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_TADX_DATX(a,b) "DTX_L2C_TADX_DATX"
#define busnum_BDK_DTX_L2C_TADX_DATX(a,b) (a)
#define arguments_BDK_DTX_L2C_TADX_DATX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_iobn#_dat#
 *
 * DTX IOBN Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_iobnx_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_iobnx_datx_s cn; */
} bdk_dtx_iobnx_datx_t;

static inline uint64_t BDK_DTX_IOBNX_DATX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_IOBNX_DATX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0fe780040ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_IOBNX_DATX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_IOBNX_DATX(a,b) bdk_dtx_iobnx_datx_t
#define bustype_BDK_DTX_IOBNX_DATX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_IOBNX_DATX(a,b) "DTX_IOBNX_DATX"
#define busnum_BDK_DTX_IOBNX_DATX(a,b) (a)
#define arguments_BDK_DTX_IOBNX_DATX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_bgx#_bcst_rsp
 *
 * DTX BGX Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_bgxx_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_bgxx_bcst_rsp_s cn; */
} bdk_dtx_bgxx_bcst_rsp_t;

static inline uint64_t BDK_DTX_BGXX_BCST_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BGXX_BCST_RSP(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe700080ll + 0x8000ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_BGXX_BCST_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_BGXX_BCST_RSP(a) bdk_dtx_bgxx_bcst_rsp_t
#define bustype_BDK_DTX_BGXX_BCST_RSP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_BGXX_BCST_RSP(a) "DTX_BGXX_BCST_RSP"
#define busnum_BDK_DTX_BGXX_BCST_RSP(a) (a)
#define arguments_BDK_DTX_BGXX_BCST_RSP(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_gic_ena#
 *
 * DTX GIC Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_gic_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_gic_enax_s cn; */
} bdk_dtx_gic_enax_t;

static inline uint64_t BDK_DTX_GIC_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GIC_ENAX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe808020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_GIC_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_GIC_ENAX(a) bdk_dtx_gic_enax_t
#define bustype_BDK_DTX_GIC_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_GIC_ENAX(a) "DTX_GIC_ENAX"
#define busnum_BDK_DTX_GIC_ENAX(a) (a)
#define arguments_BDK_DTX_GIC_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_iobn#_ena#
 *
 * DTX IOBN Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_iobnx_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_iobnx_enax_s cn; */
} bdk_dtx_iobnx_enax_t;

static inline uint64_t BDK_DTX_IOBNX_ENAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_IOBNX_ENAX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0fe780020ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_IOBNX_ENAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_IOBNX_ENAX(a,b) bdk_dtx_iobnx_enax_t
#define bustype_BDK_DTX_IOBNX_ENAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_IOBNX_ENAX(a,b) "DTX_IOBNX_ENAX"
#define busnum_BDK_DTX_IOBNX_ENAX(a,b) (a)
#define arguments_BDK_DTX_IOBNX_ENAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_uaa#_sel#
 *
 * DTX UAA Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_uaax_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_uaax_selx_s cn; */
} bdk_dtx_uaax_selx_t;

static inline uint64_t BDK_DTX_UAAX_SELX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_UAAX_SELX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0fe120000ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_UAAX_SELX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_UAAX_SELX(a,b) bdk_dtx_uaax_selx_t
#define bustype_BDK_DTX_UAAX_SELX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_UAAX_SELX(a,b) "DTX_UAAX_SELX"
#define busnum_BDK_DTX_UAAX_SELX(a,b) (a)
#define arguments_BDK_DTX_UAAX_SELX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_ocx_top_ctl
 *
 * DTX OCX_TOP Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_top_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_top_ctl_s cn; */
} bdk_dtx_ocx_top_ctl_t;

#define BDK_DTX_OCX_TOP_CTL BDK_DTX_OCX_TOP_CTL_FUNC()
static inline uint64_t BDK_DTX_OCX_TOP_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_TOP_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e0fe088060ll;
    __bdk_csr_fatal("DTX_OCX_TOP_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DTX_OCX_TOP_CTL bdk_dtx_ocx_top_ctl_t
#define bustype_BDK_DTX_OCX_TOP_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_TOP_CTL "DTX_OCX_TOP_CTL"
#define busnum_BDK_DTX_OCX_TOP_CTL 0
#define arguments_BDK_DTX_OCX_TOP_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_uaa#_ctl
 *
 * DTX UAA Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_uaax_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_uaax_ctl_s cn; */
} bdk_dtx_uaax_ctl_t;

static inline uint64_t BDK_DTX_UAAX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_UAAX_CTL(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe120060ll + 0x8000ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_UAAX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_UAAX_CTL(a) bdk_dtx_uaax_ctl_t
#define bustype_BDK_DTX_UAAX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_UAAX_CTL(a) "DTX_UAAX_CTL"
#define busnum_BDK_DTX_UAAX_CTL(a) (a)
#define arguments_BDK_DTX_UAAX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_bgx#_ctl
 *
 * DTX BGX Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_bgxx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_bgxx_ctl_s cn; */
} bdk_dtx_bgxx_ctl_t;

static inline uint64_t BDK_DTX_BGXX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BGXX_CTL(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe700060ll + 0x8000ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_BGXX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_BGXX_CTL(a) bdk_dtx_bgxx_ctl_t
#define bustype_BDK_DTX_BGXX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_BGXX_CTL(a) "DTX_BGXX_CTL"
#define busnum_BDK_DTX_BGXX_CTL(a) (a)
#define arguments_BDK_DTX_BGXX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_tns_dat#
 *
 * DTX TNS Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_tns_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_tns_datx_s cn; */
} bdk_dtx_tns_datx_t;

static inline uint64_t BDK_DTX_TNS_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_TNS_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fea10040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_TNS_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_TNS_DATX(a) bdk_dtx_tns_datx_t
#define bustype_BDK_DTX_TNS_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_TNS_DATX(a) "DTX_TNS_DATX"
#define busnum_BDK_DTX_TNS_DATX(a) (a)
#define arguments_BDK_DTX_TNS_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_broadcast_sel#
 *
 * DTX BROADCAST Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_broadcast_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_broadcast_selx_s cn; */
} bdk_dtx_broadcast_selx_t;

static inline uint64_t BDK_DTX_BROADCAST_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BROADCAST_SELX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe7f0000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_BROADCAST_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_BROADCAST_SELX(a) bdk_dtx_broadcast_selx_t
#define bustype_BDK_DTX_BROADCAST_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_BROADCAST_SELX(a) "DTX_BROADCAST_SELX"
#define busnum_BDK_DTX_BROADCAST_SELX(a) (a)
#define arguments_BDK_DTX_BROADCAST_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_mrml_ena#
 *
 * DTX MRML Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_mrml_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_mrml_enax_s cn; */
} bdk_dtx_mrml_enax_t;

static inline uint64_t BDK_DTX_MRML_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MRML_ENAX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe7e0020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_MRML_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_MRML_ENAX(a) bdk_dtx_mrml_enax_t
#define bustype_BDK_DTX_MRML_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_MRML_ENAX(a) "DTX_MRML_ENAX"
#define busnum_BDK_DTX_MRML_ENAX(a) (a)
#define arguments_BDK_DTX_MRML_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_tns_bcst_rsp
 *
 * DTX TNS Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_tns_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_tns_bcst_rsp_s cn; */
} bdk_dtx_tns_bcst_rsp_t;

#define BDK_DTX_TNS_BCST_RSP BDK_DTX_TNS_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_TNS_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_TNS_BCST_RSP_FUNC(void)
{
    return 0x87e0fea10080ll;
}

#define typedef_BDK_DTX_TNS_BCST_RSP bdk_dtx_tns_bcst_rsp_t
#define bustype_BDK_DTX_TNS_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_TNS_BCST_RSP "DTX_TNS_BCST_RSP"
#define busnum_BDK_DTX_TNS_BCST_RSP 0
#define arguments_BDK_DTX_TNS_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_usbh#_ena#
 *
 * DTX USBH Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_usbhx_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_usbhx_enax_s cn; */
} bdk_dtx_usbhx_enax_t;

static inline uint64_t BDK_DTX_USBHX_ENAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_USBHX_ENAX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0feb40020ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_USBHX_ENAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_USBHX_ENAX(a,b) bdk_dtx_usbhx_enax_t
#define bustype_BDK_DTX_USBHX_ENAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_USBHX_ENAX(a,b) "DTX_USBHX_ENAX"
#define busnum_BDK_DTX_USBHX_ENAX(a,b) (a)
#define arguments_BDK_DTX_USBHX_ENAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_dap_bcst_rsp
 *
 * DTX DAP Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_dap_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_dap_bcst_rsp_s cn; */
} bdk_dtx_dap_bcst_rsp_t;

#define BDK_DTX_DAP_BCST_RSP BDK_DTX_DAP_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_DAP_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DAP_BCST_RSP_FUNC(void)
{
    return 0x87e0fe010080ll;
}

#define typedef_BDK_DTX_DAP_BCST_RSP bdk_dtx_dap_bcst_rsp_t
#define bustype_BDK_DTX_DAP_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_DAP_BCST_RSP "DTX_DAP_BCST_RSP"
#define busnum_BDK_DTX_DAP_BCST_RSP 0
#define arguments_BDK_DTX_DAP_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_gser#_bcst_rsp
 *
 * DTX GSER Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_gserx_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_gserx_bcst_rsp_s cn; */
} bdk_dtx_gserx_bcst_rsp_t;

static inline uint64_t BDK_DTX_GSERX_BCST_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GSERX_BCST_RSP(unsigned long a)
{
    if (a<=13)
        return 0x87e0fe480080ll + 0x8000ll * ((a) & 0xf);
    __bdk_csr_fatal("DTX_GSERX_BCST_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_GSERX_BCST_RSP(a) bdk_dtx_gserx_bcst_rsp_t
#define bustype_BDK_DTX_GSERX_BCST_RSP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_GSERX_BCST_RSP(a) "DTX_GSERX_BCST_RSP"
#define busnum_BDK_DTX_GSERX_BCST_RSP(a) (a)
#define arguments_BDK_DTX_GSERX_BCST_RSP(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_l2c_cbc#_bcst_rsp
 *
 * DTX L2C_CBC Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_cbcx_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_cbcx_bcst_rsp_s cn; */
} bdk_dtx_l2c_cbcx_bcst_rsp_t;

static inline uint64_t BDK_DTX_L2C_CBCX_BCST_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_CBCX_BCST_RSP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e0fe2c0080ll + 0x8000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x87e0fe2c0080ll + 0x8000ll * ((a) & 0x3);
    __bdk_csr_fatal("DTX_L2C_CBCX_BCST_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_L2C_CBCX_BCST_RSP(a) bdk_dtx_l2c_cbcx_bcst_rsp_t
#define bustype_BDK_DTX_L2C_CBCX_BCST_RSP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_CBCX_BCST_RSP(a) "DTX_L2C_CBCX_BCST_RSP"
#define busnum_BDK_DTX_L2C_CBCX_BCST_RSP(a) (a)
#define arguments_BDK_DTX_L2C_CBCX_BCST_RSP(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_tns_sel#
 *
 * DTX TNS Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_tns_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_tns_selx_s cn; */
} bdk_dtx_tns_selx_t;

static inline uint64_t BDK_DTX_TNS_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_TNS_SELX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fea10000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_TNS_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_TNS_SELX(a) bdk_dtx_tns_selx_t
#define bustype_BDK_DTX_TNS_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_TNS_SELX(a) "DTX_TNS_SELX"
#define busnum_BDK_DTX_TNS_SELX(a) (a)
#define arguments_BDK_DTX_TNS_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_dfa_bcst_rsp
 *
 * DTX DFA Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_dfa_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_dfa_bcst_rsp_s cn; */
} bdk_dtx_dfa_bcst_rsp_t;

#define BDK_DTX_DFA_BCST_RSP BDK_DTX_DFA_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_DFA_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_DFA_BCST_RSP_FUNC(void)
{
    return 0x87e0fea30080ll;
}

#define typedef_BDK_DTX_DFA_BCST_RSP bdk_dtx_dfa_bcst_rsp_t
#define bustype_BDK_DTX_DFA_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_DFA_BCST_RSP "DTX_DFA_BCST_RSP"
#define busnum_BDK_DTX_DFA_BCST_RSP 0
#define arguments_BDK_DTX_DFA_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_gser#_sel#
 *
 * DTX GSER Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_gserx_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_gserx_selx_s cn; */
} bdk_dtx_gserx_selx_t;

static inline uint64_t BDK_DTX_GSERX_SELX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GSERX_SELX(unsigned long a, unsigned long b)
{
    if ((a<=13) && (b<=1))
        return 0x87e0fe480000ll + 0x8000ll * ((a) & 0xf) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_GSERX_SELX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_GSERX_SELX(a,b) bdk_dtx_gserx_selx_t
#define bustype_BDK_DTX_GSERX_SELX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_GSERX_SELX(a,b) "DTX_GSERX_SELX"
#define busnum_BDK_DTX_GSERX_SELX(a,b) (a)
#define arguments_BDK_DTX_GSERX_SELX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_ocx_top_dat#
 *
 * DTX OCX_TOP Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_top_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_top_datx_s cn; */
} bdk_dtx_ocx_top_datx_t;

static inline uint64_t BDK_DTX_OCX_TOP_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_TOP_DATX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=1))
        return 0x87e0fe088040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_OCX_TOP_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_OCX_TOP_DATX(a) bdk_dtx_ocx_top_datx_t
#define bustype_BDK_DTX_OCX_TOP_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_TOP_DATX(a) "DTX_OCX_TOP_DATX"
#define busnum_BDK_DTX_OCX_TOP_DATX(a) (a)
#define arguments_BDK_DTX_OCX_TOP_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_key_ena#
 *
 * DTX KEY Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_key_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_key_enax_s cn; */
} bdk_dtx_key_enax_t;

static inline uint64_t BDK_DTX_KEY_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_KEY_ENAX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe208020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_KEY_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_KEY_ENAX(a) bdk_dtx_key_enax_t
#define bustype_BDK_DTX_KEY_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_KEY_ENAX(a) "DTX_KEY_ENAX"
#define busnum_BDK_DTX_KEY_ENAX(a) (a)
#define arguments_BDK_DTX_KEY_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_ncsi_sel#
 *
 * DTX NCSI Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ncsi_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ncsi_selx_s cn; */
} bdk_dtx_ncsi_selx_t;

static inline uint64_t BDK_DTX_NCSI_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NCSI_SELX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe058000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_NCSI_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_NCSI_SELX(a) bdk_dtx_ncsi_selx_t
#define bustype_BDK_DTX_NCSI_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_NCSI_SELX(a) "DTX_NCSI_SELX"
#define busnum_BDK_DTX_NCSI_SELX(a) (a)
#define arguments_BDK_DTX_NCSI_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_l2c_mci#_dat#
 *
 * DTX L2C_MCI Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_mcix_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_mcix_datx_s cn; */
} bdk_dtx_l2c_mcix_datx_t;

static inline uint64_t BDK_DTX_L2C_MCIX_DATX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_MCIX_DATX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=2) && (b<=1)))
        return 0x87e0fe2e0040ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=1)))
        return 0x87e0fe2e0040ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_L2C_MCIX_DATX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_L2C_MCIX_DATX(a,b) bdk_dtx_l2c_mcix_datx_t
#define bustype_BDK_DTX_L2C_MCIX_DATX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_MCIX_DATX(a,b) "DTX_L2C_MCIX_DATX"
#define busnum_BDK_DTX_L2C_MCIX_DATX(a,b) (a)
#define arguments_BDK_DTX_L2C_MCIX_DATX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_mio_bcst_rsp
 *
 * DTX MIO Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_mio_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_mio_bcst_rsp_s cn; */
} bdk_dtx_mio_bcst_rsp_t;

#define BDK_DTX_MIO_BCST_RSP BDK_DTX_MIO_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_MIO_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MIO_BCST_RSP_FUNC(void)
{
    return 0x87e0fe000080ll;
}

#define typedef_BDK_DTX_MIO_BCST_RSP bdk_dtx_mio_bcst_rsp_t
#define bustype_BDK_DTX_MIO_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_MIO_BCST_RSP "DTX_MIO_BCST_RSP"
#define busnum_BDK_DTX_MIO_BCST_RSP 0
#define arguments_BDK_DTX_MIO_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_mrml_ctl
 *
 * DTX MRML Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_mrml_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_mrml_ctl_s cn; */
} bdk_dtx_mrml_ctl_t;

#define BDK_DTX_MRML_CTL BDK_DTX_MRML_CTL_FUNC()
static inline uint64_t BDK_DTX_MRML_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MRML_CTL_FUNC(void)
{
    return 0x87e0fe7e0060ll;
}

#define typedef_BDK_DTX_MRML_CTL bdk_dtx_mrml_ctl_t
#define bustype_BDK_DTX_MRML_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_MRML_CTL "DTX_MRML_CTL"
#define busnum_BDK_DTX_MRML_CTL 0
#define arguments_BDK_DTX_MRML_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_zip_dat#
 *
 * DTX ZIP Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_zip_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_zip_datx_s cn; */
} bdk_dtx_zip_datx_t;

static inline uint64_t BDK_DTX_ZIP_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_ZIP_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe9c0040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_ZIP_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_ZIP_DATX(a) bdk_dtx_zip_datx_t
#define bustype_BDK_DTX_ZIP_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_ZIP_DATX(a) "DTX_ZIP_DATX"
#define busnum_BDK_DTX_ZIP_DATX(a) (a)
#define arguments_BDK_DTX_ZIP_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_l2c_mci#_ena#
 *
 * DTX L2C_MCI Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_mcix_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_mcix_enax_s cn; */
} bdk_dtx_l2c_mcix_enax_t;

static inline uint64_t BDK_DTX_L2C_MCIX_ENAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_MCIX_ENAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=2) && (b<=1)))
        return 0x87e0fe2e0020ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=1)))
        return 0x87e0fe2e0020ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_L2C_MCIX_ENAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_L2C_MCIX_ENAX(a,b) bdk_dtx_l2c_mcix_enax_t
#define bustype_BDK_DTX_L2C_MCIX_ENAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_MCIX_ENAX(a,b) "DTX_L2C_MCIX_ENAX"
#define busnum_BDK_DTX_L2C_MCIX_ENAX(a,b) (a)
#define arguments_BDK_DTX_L2C_MCIX_ENAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_pem#_sel#
 *
 * DTX PEM Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_pemx_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_pemx_selx_s cn; */
} bdk_dtx_pemx_selx_t;

static inline uint64_t BDK_DTX_PEMX_SELX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_PEMX_SELX(unsigned long a, unsigned long b)
{
    if ((a<=5) && (b<=1))
        return 0x87e0fe600000ll + 0x8000ll * ((a) & 0x7) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_PEMX_SELX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_PEMX_SELX(a,b) bdk_dtx_pemx_selx_t
#define bustype_BDK_DTX_PEMX_SELX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_PEMX_SELX(a,b) "DTX_PEMX_SELX"
#define busnum_BDK_DTX_PEMX_SELX(a,b) (a)
#define arguments_BDK_DTX_PEMX_SELX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_mio_sel#
 *
 * DTX MIO Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_mio_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_mio_selx_s cn; */
} bdk_dtx_mio_selx_t;

static inline uint64_t BDK_DTX_MIO_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_MIO_SELX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe000000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_MIO_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_MIO_SELX(a) bdk_dtx_mio_selx_t
#define bustype_BDK_DTX_MIO_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_MIO_SELX(a) "DTX_MIO_SELX"
#define busnum_BDK_DTX_MIO_SELX(a) (a)
#define arguments_BDK_DTX_MIO_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_ocx_top_ena#
 *
 * DTX OCX_TOP Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_top_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_top_enax_s cn; */
} bdk_dtx_ocx_top_enax_t;

static inline uint64_t BDK_DTX_OCX_TOP_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_TOP_ENAX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=1))
        return 0x87e0fe088020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_OCX_TOP_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_OCX_TOP_ENAX(a) bdk_dtx_ocx_top_enax_t
#define bustype_BDK_DTX_OCX_TOP_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_TOP_ENAX(a) "DTX_OCX_TOP_ENAX"
#define busnum_BDK_DTX_OCX_TOP_ENAX(a) (a)
#define arguments_BDK_DTX_OCX_TOP_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_gic_sel#
 *
 * DTX GIC Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_gic_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_gic_selx_s cn; */
} bdk_dtx_gic_selx_t;

static inline uint64_t BDK_DTX_GIC_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GIC_SELX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe808000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_GIC_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_GIC_SELX(a) bdk_dtx_gic_selx_t
#define bustype_BDK_DTX_GIC_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_GIC_SELX(a) "DTX_GIC_SELX"
#define busnum_BDK_DTX_GIC_SELX(a) (a)
#define arguments_BDK_DTX_GIC_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_ncsi_dat#
 *
 * DTX NCSI Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ncsi_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ncsi_datx_s cn; */
} bdk_dtx_ncsi_datx_t;

static inline uint64_t BDK_DTX_NCSI_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NCSI_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe058040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_NCSI_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_NCSI_DATX(a) bdk_dtx_ncsi_datx_t
#define bustype_BDK_DTX_NCSI_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_NCSI_DATX(a) "DTX_NCSI_DATX"
#define busnum_BDK_DTX_NCSI_DATX(a) (a)
#define arguments_BDK_DTX_NCSI_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_lmc#_dat#
 *
 * DTX LMC Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_lmcx_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_lmcx_datx_s cn; */
} bdk_dtx_lmcx_datx_t;

static inline uint64_t BDK_DTX_LMCX_DATX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_LMCX_DATX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=1)))
        return 0x87e0fe440040ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=1)))
        return 0x87e0fe440040ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_LMCX_DATX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_LMCX_DATX(a,b) bdk_dtx_lmcx_datx_t
#define bustype_BDK_DTX_LMCX_DATX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_LMCX_DATX(a,b) "DTX_LMCX_DATX"
#define busnum_BDK_DTX_LMCX_DATX(a,b) (a)
#define arguments_BDK_DTX_LMCX_DATX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_ncsi_bcst_rsp
 *
 * DTX NCSI Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ncsi_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ncsi_bcst_rsp_s cn; */
} bdk_dtx_ncsi_bcst_rsp_t;

#define BDK_DTX_NCSI_BCST_RSP BDK_DTX_NCSI_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_NCSI_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NCSI_BCST_RSP_FUNC(void)
{
    return 0x87e0fe058080ll;
}

#define typedef_BDK_DTX_NCSI_BCST_RSP bdk_dtx_ncsi_bcst_rsp_t
#define bustype_BDK_DTX_NCSI_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_NCSI_BCST_RSP "DTX_NCSI_BCST_RSP"
#define busnum_BDK_DTX_NCSI_BCST_RSP 0
#define arguments_BDK_DTX_NCSI_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_l2c_cbc#_dat#
 *
 * DTX L2C_CBC Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_cbcx_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_cbcx_datx_s cn; */
} bdk_dtx_l2c_cbcx_datx_t;

static inline uint64_t BDK_DTX_L2C_CBCX_DATX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_CBCX_DATX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=1)))
        return 0x87e0fe2c0040ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=1)))
        return 0x87e0fe2c0040ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_L2C_CBCX_DATX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_L2C_CBCX_DATX(a,b) bdk_dtx_l2c_cbcx_datx_t
#define bustype_BDK_DTX_L2C_CBCX_DATX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_CBCX_DATX(a,b) "DTX_L2C_CBCX_DATX"
#define busnum_BDK_DTX_L2C_CBCX_DATX(a,b) (a)
#define arguments_BDK_DTX_L2C_CBCX_DATX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_sli#_dat#
 *
 * DTX SLI Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_slix_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_slix_datx_s cn; */
} bdk_dtx_slix_datx_t;

static inline uint64_t BDK_DTX_SLIX_DATX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SLIX_DATX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0feba0040ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_SLIX_DATX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_SLIX_DATX(a,b) bdk_dtx_slix_datx_t
#define bustype_BDK_DTX_SLIX_DATX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_SLIX_DATX(a,b) "DTX_SLIX_DATX"
#define busnum_BDK_DTX_SLIX_DATX(a,b) (a)
#define arguments_BDK_DTX_SLIX_DATX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_l2c_cbc#_ena#
 *
 * DTX L2C_CBC Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_cbcx_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_cbcx_enax_s cn; */
} bdk_dtx_l2c_cbcx_enax_t;

static inline uint64_t BDK_DTX_L2C_CBCX_ENAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_CBCX_ENAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=1)))
        return 0x87e0fe2c0020ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=1)))
        return 0x87e0fe2c0020ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_L2C_CBCX_ENAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_L2C_CBCX_ENAX(a,b) bdk_dtx_l2c_cbcx_enax_t
#define bustype_BDK_DTX_L2C_CBCX_ENAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_CBCX_ENAX(a,b) "DTX_L2C_CBCX_ENAX"
#define busnum_BDK_DTX_L2C_CBCX_ENAX(a,b) (a)
#define arguments_BDK_DTX_L2C_CBCX_ENAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_bgx#_dat#
 *
 * DTX BGX Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_bgxx_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_bgxx_datx_s cn; */
} bdk_dtx_bgxx_datx_t;

static inline uint64_t BDK_DTX_BGXX_DATX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_BGXX_DATX(unsigned long a, unsigned long b)
{
    if ((a<=1) && (b<=1))
        return 0x87e0fe700040ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_BGXX_DATX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_BGXX_DATX(a,b) bdk_dtx_bgxx_datx_t
#define bustype_BDK_DTX_BGXX_DATX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_BGXX_DATX(a,b) "DTX_BGXX_DATX"
#define busnum_BDK_DTX_BGXX_DATX(a,b) (a)
#define arguments_BDK_DTX_BGXX_DATX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_tns_ctl
 *
 * DTX TNS Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_tns_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_tns_ctl_s cn; */
} bdk_dtx_tns_ctl_t;

#define BDK_DTX_TNS_CTL BDK_DTX_TNS_CTL_FUNC()
static inline uint64_t BDK_DTX_TNS_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_TNS_CTL_FUNC(void)
{
    return 0x87e0fea10060ll;
}

#define typedef_BDK_DTX_TNS_CTL bdk_dtx_tns_ctl_t
#define bustype_BDK_DTX_TNS_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_TNS_CTL "DTX_TNS_CTL"
#define busnum_BDK_DTX_TNS_CTL 0
#define arguments_BDK_DTX_TNS_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_sli#_bcst_rsp
 *
 * DTX SLI Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_slix_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_slix_bcst_rsp_s cn; */
} bdk_dtx_slix_bcst_rsp_t;

static inline uint64_t BDK_DTX_SLIX_BCST_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_SLIX_BCST_RSP(unsigned long a)
{
    if (a<=1)
        return 0x87e0feba0080ll + 0x8000ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_SLIX_BCST_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_SLIX_BCST_RSP(a) bdk_dtx_slix_bcst_rsp_t
#define bustype_BDK_DTX_SLIX_BCST_RSP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_SLIX_BCST_RSP(a) "DTX_SLIX_BCST_RSP"
#define busnum_BDK_DTX_SLIX_BCST_RSP(a) (a)
#define arguments_BDK_DTX_SLIX_BCST_RSP(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_iobn#_ctl
 *
 * DTX IOBN Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_iobnx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_iobnx_ctl_s cn; */
} bdk_dtx_iobnx_ctl_t;

static inline uint64_t BDK_DTX_IOBNX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_IOBNX_CTL(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe780060ll + 0x8000ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_IOBNX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_IOBNX_CTL(a) bdk_dtx_iobnx_ctl_t
#define bustype_BDK_DTX_IOBNX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_IOBNX_CTL(a) "DTX_IOBNX_CTL"
#define busnum_BDK_DTX_IOBNX_CTL(a) (a)
#define arguments_BDK_DTX_IOBNX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_l2c_tad#_ctl
 *
 * DTX L2C_TAD Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_tadx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_tadx_ctl_s cn; */
} bdk_dtx_l2c_tadx_ctl_t;

static inline uint64_t BDK_DTX_L2C_TADX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_TADX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0fe280060ll + 0x8000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x87e0fe280060ll + 0x8000ll * ((a) & 0x7);
    __bdk_csr_fatal("DTX_L2C_TADX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_L2C_TADX_CTL(a) bdk_dtx_l2c_tadx_ctl_t
#define bustype_BDK_DTX_L2C_TADX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_TADX_CTL(a) "DTX_L2C_TADX_CTL"
#define busnum_BDK_DTX_L2C_TADX_CTL(a) (a)
#define arguments_BDK_DTX_L2C_TADX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_ncsi_ctl
 *
 * DTX NCSI Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ncsi_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ncsi_ctl_s cn; */
} bdk_dtx_ncsi_ctl_t;

#define BDK_DTX_NCSI_CTL BDK_DTX_NCSI_CTL_FUNC()
static inline uint64_t BDK_DTX_NCSI_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NCSI_CTL_FUNC(void)
{
    return 0x87e0fe058060ll;
}

#define typedef_BDK_DTX_NCSI_CTL bdk_dtx_ncsi_ctl_t
#define bustype_BDK_DTX_NCSI_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_NCSI_CTL "DTX_NCSI_CTL"
#define busnum_BDK_DTX_NCSI_CTL 0
#define arguments_BDK_DTX_NCSI_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_ocx_top_bcst_rsp
 *
 * DTX OCX_TOP Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_top_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_top_bcst_rsp_s cn; */
} bdk_dtx_ocx_top_bcst_rsp_t;

#define BDK_DTX_OCX_TOP_BCST_RSP BDK_DTX_OCX_TOP_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_OCX_TOP_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_TOP_BCST_RSP_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e0fe088080ll;
    __bdk_csr_fatal("DTX_OCX_TOP_BCST_RSP", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DTX_OCX_TOP_BCST_RSP bdk_dtx_ocx_top_bcst_rsp_t
#define bustype_BDK_DTX_OCX_TOP_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_TOP_BCST_RSP "DTX_OCX_TOP_BCST_RSP"
#define busnum_BDK_DTX_OCX_TOP_BCST_RSP 0
#define arguments_BDK_DTX_OCX_TOP_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_usbh#_bcst_rsp
 *
 * DTX USBH Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_usbhx_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_usbhx_bcst_rsp_s cn; */
} bdk_dtx_usbhx_bcst_rsp_t;

static inline uint64_t BDK_DTX_USBHX_BCST_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_USBHX_BCST_RSP(unsigned long a)
{
    if (a<=1)
        return 0x87e0feb40080ll + 0x8000ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_USBHX_BCST_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_USBHX_BCST_RSP(a) bdk_dtx_usbhx_bcst_rsp_t
#define bustype_BDK_DTX_USBHX_BCST_RSP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_USBHX_BCST_RSP(a) "DTX_USBHX_BCST_RSP"
#define busnum_BDK_DTX_USBHX_BCST_RSP(a) (a)
#define arguments_BDK_DTX_USBHX_BCST_RSP(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_l2c_tad#_ena#
 *
 * DTX L2C_TAD Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_tadx_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_tadx_enax_s cn; */
} bdk_dtx_l2c_tadx_enax_t;

static inline uint64_t BDK_DTX_L2C_TADX_ENAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_TADX_ENAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=1)))
        return 0x87e0fe280020ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=7) && (b<=1)))
        return 0x87e0fe280020ll + 0x8000ll * ((a) & 0x7) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_L2C_TADX_ENAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_L2C_TADX_ENAX(a,b) bdk_dtx_l2c_tadx_enax_t
#define bustype_BDK_DTX_L2C_TADX_ENAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_TADX_ENAX(a,b) "DTX_L2C_TADX_ENAX"
#define busnum_BDK_DTX_L2C_TADX_ENAX(a,b) (a)
#define arguments_BDK_DTX_L2C_TADX_ENAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_rad_sel#
 *
 * DTX RAD Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rad_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rad_selx_s cn; */
} bdk_dtx_rad_selx_t;

static inline uint64_t BDK_DTX_RAD_SELX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RAD_SELX(unsigned long a)
{
    if (a<=1)
        return 0x87e0feb80000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_RAD_SELX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_RAD_SELX(a) bdk_dtx_rad_selx_t
#define bustype_BDK_DTX_RAD_SELX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RAD_SELX(a) "DTX_RAD_SELX"
#define busnum_BDK_DTX_RAD_SELX(a) (a)
#define arguments_BDK_DTX_RAD_SELX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_zip_ena#
 *
 * DTX ZIP Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_zip_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_zip_enax_s cn; */
} bdk_dtx_zip_enax_t;

static inline uint64_t BDK_DTX_ZIP_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_ZIP_ENAX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe9c0020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_ZIP_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_ZIP_ENAX(a) bdk_dtx_zip_enax_t
#define bustype_BDK_DTX_ZIP_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_ZIP_ENAX(a) "DTX_ZIP_ENAX"
#define busnum_BDK_DTX_ZIP_ENAX(a) (a)
#define arguments_BDK_DTX_ZIP_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_l2c_cbc#_ctl
 *
 * DTX L2C_CBC Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_cbcx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_cbcx_ctl_s cn; */
} bdk_dtx_l2c_cbcx_ctl_t;

static inline uint64_t BDK_DTX_L2C_CBCX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_CBCX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e0fe2c0060ll + 0x8000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x87e0fe2c0060ll + 0x8000ll * ((a) & 0x3);
    __bdk_csr_fatal("DTX_L2C_CBCX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_L2C_CBCX_CTL(a) bdk_dtx_l2c_cbcx_ctl_t
#define bustype_BDK_DTX_L2C_CBCX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_CBCX_CTL(a) "DTX_L2C_CBCX_CTL"
#define busnum_BDK_DTX_L2C_CBCX_CTL(a) (a)
#define arguments_BDK_DTX_L2C_CBCX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_nic_ena#
 *
 * DTX NIC Data Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_nic_enax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 36; /**< [ 35:  0](R/W) Output enable vector of which bits to drive onto the low/high 36-bit debug buses. Normally
                                                                 only one block will drive each bit. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_nic_enax_s cn; */
} bdk_dtx_nic_enax_t;

static inline uint64_t BDK_DTX_NIC_ENAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NIC_ENAX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fea18020ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_NIC_ENAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_NIC_ENAX(a) bdk_dtx_nic_enax_t
#define bustype_BDK_DTX_NIC_ENAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_NIC_ENAX(a) "DTX_NIC_ENAX"
#define busnum_BDK_DTX_NIC_ENAX(a) (a)
#define arguments_BDK_DTX_NIC_ENAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_gic_bcst_rsp
 *
 * DTX GIC Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_gic_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_gic_bcst_rsp_s cn; */
} bdk_dtx_gic_bcst_rsp_t;

#define BDK_DTX_GIC_BCST_RSP BDK_DTX_GIC_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_GIC_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_GIC_BCST_RSP_FUNC(void)
{
    return 0x87e0fe808080ll;
}

#define typedef_BDK_DTX_GIC_BCST_RSP bdk_dtx_gic_bcst_rsp_t
#define bustype_BDK_DTX_GIC_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_GIC_BCST_RSP "DTX_GIC_BCST_RSP"
#define busnum_BDK_DTX_GIC_BCST_RSP 0
#define arguments_BDK_DTX_GIC_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_key_ctl
 *
 * DTX KEY Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_key_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_key_ctl_s cn; */
} bdk_dtx_key_ctl_t;

#define BDK_DTX_KEY_CTL BDK_DTX_KEY_CTL_FUNC()
static inline uint64_t BDK_DTX_KEY_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_KEY_CTL_FUNC(void)
{
    return 0x87e0fe208060ll;
}

#define typedef_BDK_DTX_KEY_CTL bdk_dtx_key_ctl_t
#define bustype_BDK_DTX_KEY_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_KEY_CTL "DTX_KEY_CTL"
#define busnum_BDK_DTX_KEY_CTL 0
#define arguments_BDK_DTX_KEY_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_rst_bcst_rsp
 *
 * DTX RST Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rst_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rst_bcst_rsp_s cn; */
} bdk_dtx_rst_bcst_rsp_t;

#define BDK_DTX_RST_BCST_RSP BDK_DTX_RST_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_RST_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RST_BCST_RSP_FUNC(void)
{
    return 0x87e0fe030080ll;
}

#define typedef_BDK_DTX_RST_BCST_RSP bdk_dtx_rst_bcst_rsp_t
#define bustype_BDK_DTX_RST_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RST_BCST_RSP "DTX_RST_BCST_RSP"
#define busnum_BDK_DTX_RST_BCST_RSP 0
#define arguments_BDK_DTX_RST_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_nic_ctl
 *
 * DTX NIC Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_nic_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_nic_ctl_s cn; */
} bdk_dtx_nic_ctl_t;

#define BDK_DTX_NIC_CTL BDK_DTX_NIC_CTL_FUNC()
static inline uint64_t BDK_DTX_NIC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_NIC_CTL_FUNC(void)
{
    return 0x87e0fea18060ll;
}

#define typedef_BDK_DTX_NIC_CTL bdk_dtx_nic_ctl_t
#define bustype_BDK_DTX_NIC_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_NIC_CTL "DTX_NIC_CTL"
#define busnum_BDK_DTX_NIC_CTL 0
#define arguments_BDK_DTX_NIC_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_rnm_ctl
 *
 * DTX RNM Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rnm_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rnm_ctl_s cn; */
} bdk_dtx_rnm_ctl_t;

#define BDK_DTX_RNM_CTL BDK_DTX_RNM_CTL_FUNC()
static inline uint64_t BDK_DTX_RNM_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RNM_CTL_FUNC(void)
{
    return 0x87e0fe200060ll;
}

#define typedef_BDK_DTX_RNM_CTL bdk_dtx_rnm_ctl_t
#define bustype_BDK_DTX_RNM_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RNM_CTL "DTX_RNM_CTL"
#define busnum_BDK_DTX_RNM_CTL 0
#define arguments_BDK_DTX_RNM_CTL -1,-1,-1,-1

/**
 * Register (RSL) dtx_l2c_tad#_bcst_rsp
 *
 * DTX L2C_TAD Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_l2c_tadx_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_l2c_tadx_bcst_rsp_s cn; */
} bdk_dtx_l2c_tadx_bcst_rsp_t;

static inline uint64_t BDK_DTX_L2C_TADX_BCST_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_L2C_TADX_BCST_RSP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0fe280080ll + 0x8000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x87e0fe280080ll + 0x8000ll * ((a) & 0x7);
    __bdk_csr_fatal("DTX_L2C_TADX_BCST_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_L2C_TADX_BCST_RSP(a) bdk_dtx_l2c_tadx_bcst_rsp_t
#define bustype_BDK_DTX_L2C_TADX_BCST_RSP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_L2C_TADX_BCST_RSP(a) "DTX_L2C_TADX_BCST_RSP"
#define busnum_BDK_DTX_L2C_TADX_BCST_RSP(a) (a)
#define arguments_BDK_DTX_L2C_TADX_BCST_RSP(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_ocx_ole#_sel#
 *
 * DTX OCX_OLE Select Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_olex_selx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
#else /* Word 0 - Little Endian */
        uint64_t value                 : 24; /**< [ 23:  0](R/W) Debug select. Selects which signals to drive onto low/high 36-bit debug buses. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_olex_selx_s cn; */
} bdk_dtx_ocx_olex_selx_t;

static inline uint64_t BDK_DTX_OCX_OLEX_SELX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_OLEX_SELX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=2) && (b<=1)))
        return 0x87e0fe1a0000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DTX_OCX_OLEX_SELX", 2, a, b, 0, 0);
}

#define typedef_BDK_DTX_OCX_OLEX_SELX(a,b) bdk_dtx_ocx_olex_selx_t
#define bustype_BDK_DTX_OCX_OLEX_SELX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_OLEX_SELX(a,b) "DTX_OCX_OLEX_SELX"
#define busnum_BDK_DTX_OCX_OLEX_SELX(a,b) (a)
#define arguments_BDK_DTX_OCX_OLEX_SELX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dtx_rnm_bcst_rsp
 *
 * DTX RNM Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rnm_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rnm_bcst_rsp_s cn; */
} bdk_dtx_rnm_bcst_rsp_t;

#define BDK_DTX_RNM_BCST_RSP BDK_DTX_RNM_BCST_RSP_FUNC()
static inline uint64_t BDK_DTX_RNM_BCST_RSP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RNM_BCST_RSP_FUNC(void)
{
    return 0x87e0fe200080ll;
}

#define typedef_BDK_DTX_RNM_BCST_RSP bdk_dtx_rnm_bcst_rsp_t
#define bustype_BDK_DTX_RNM_BCST_RSP BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RNM_BCST_RSP "DTX_RNM_BCST_RSP"
#define busnum_BDK_DTX_RNM_BCST_RSP 0
#define arguments_BDK_DTX_RNM_BCST_RSP -1,-1,-1,-1

/**
 * Register (RSL) dtx_rnm_dat#
 *
 * DTX RNM Raw Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_rnm_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 36; /**< [ 35:  0](RO/H) Raw debug data captured by the DTX before the ENA is applied. This gives the ability to
                                                                 peek into blocks during an OCLA capture without OCLA reconfiguration. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_rnm_datx_s cn; */
} bdk_dtx_rnm_datx_t;

static inline uint64_t BDK_DTX_RNM_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_RNM_DATX(unsigned long a)
{
    if (a<=1)
        return 0x87e0fe200040ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("DTX_RNM_DATX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_RNM_DATX(a) bdk_dtx_rnm_datx_t
#define bustype_BDK_DTX_RNM_DATX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_RNM_DATX(a) "DTX_RNM_DATX"
#define busnum_BDK_DTX_RNM_DATX(a) (a)
#define arguments_BDK_DTX_RNM_DATX(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_pem#_ctl
 *
 * DTX PEM Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_pemx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_2_3          : 2;
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
#else /* Word 0 - Little Endian */
        uint64_t swap                  : 1;  /**< [  0:  0](R/W) Swap the high and low 36-bit debug bus outputs. */
        uint64_t echoen                : 1;  /**< [  1:  1](R/W) Drive debug bus with the value in DTX_MIO_ENA(0..1) instead of normal block debug data.
                                                                 Not applicable when software directly reads the DAT(0..1) registers.  For diagnostic use
                                                                 only. */
        uint64_t reserved_2_3          : 2;
        uint64_t active                : 1;  /**< [  4:  4](R/W) Force block's gated clocks on, so that the state of idle signals may be captured. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_pemx_ctl_s cn; */
} bdk_dtx_pemx_ctl_t;

static inline uint64_t BDK_DTX_PEMX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_PEMX_CTL(unsigned long a)
{
    if (a<=5)
        return 0x87e0fe600060ll + 0x8000ll * ((a) & 0x7);
    __bdk_csr_fatal("DTX_PEMX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_PEMX_CTL(a) bdk_dtx_pemx_ctl_t
#define bustype_BDK_DTX_PEMX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_PEMX_CTL(a) "DTX_PEMX_CTL"
#define busnum_BDK_DTX_PEMX_CTL(a) (a)
#define arguments_BDK_DTX_PEMX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) dtx_ocx_lnk#_bcst_rsp
 *
 * DTX OCX_LNK Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dtx_ocx_lnkx_bcst_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable this DTX instance as the responder to DTX broadcast read/write operations. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dtx_ocx_lnkx_bcst_rsp_s cn; */
} bdk_dtx_ocx_lnkx_bcst_rsp_t;

static inline uint64_t BDK_DTX_OCX_LNKX_BCST_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DTX_OCX_LNKX_BCST_RSP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=2))
        return 0x87e0fe180080ll + 0x8000ll * ((a) & 0x3);
    __bdk_csr_fatal("DTX_OCX_LNKX_BCST_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DTX_OCX_LNKX_BCST_RSP(a) bdk_dtx_ocx_lnkx_bcst_rsp_t
#define bustype_BDK_DTX_OCX_LNKX_BCST_RSP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_DTX_OCX_LNKX_BCST_RSP(a) "DTX_OCX_LNKX_BCST_RSP"
#define busnum_BDK_DTX_OCX_LNKX_BCST_RSP(a) (a)
#define arguments_BDK_DTX_OCX_LNKX_BCST_RSP(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_DTX_H__ */
