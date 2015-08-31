#ifndef __BDK_CSRS_MIO_TWS_H__
#define __BDK_CSRS_MIO_TWS_H__
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
 * Cavium MIO_TWS.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration mio_tws_bar_e
 *
 * TWSI Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR0(a) (0x87e0d0000000ll + 0x1000000ll * (a)) /**< (0..5)Base address for standard registers. */
#define BDK_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR4(a) (0x87e0d0f00000ll + 0x1000000ll * (a)) /**< (0..5)Base address for MSI-X registers. */

/**
 * Enumeration mio_tws_int_vec_e
 *
 * TWSI MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_MIO_TWS_INT_VEC_E_INT_ST (0) /**< See interrupt clears MIO_TWS(0..5)_INT[ST_INT], MIO_TWS(0..5)_INT[TS_INT],
                                       MIO_TWS(0..5)_INT[CORE_INT], interrupt sets MIO_TWS(0..5)_INT_W1S, enable clears
                                       MIO_TWS(0..5)_INT_ENA_W1C, and enable sets MIO_TWS(0..5)_INT_ENA_W1S. */

/**
 * Register (RSL) mio_tws#_int
 *
 * TWSI Interrupt Register
 * This register contains the TWSI interrupt-enable mask and the interrupt-source bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_twsx_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t scl                   : 1;  /**< [ 11: 11](RO/H) SCL signal. */
        uint64_t sda                   : 1;  /**< [ 10: 10](RO/H) SDA signal. */
        uint64_t scl_ovr               : 1;  /**< [  9:  9](R/W) SCL testing override:
                                                                 0 = Normal operation, SCL bus controlled by TWSI core.
                                                                 1 = Pull SCL low. */
        uint64_t sda_ovr               : 1;  /**< [  8:  8](R/W) SDA testing override:
                                                                 0 = Normal operation, SDA bus controlled by TWSI core.
                                                                 1 = Pull SDA low. */
        uint64_t reserved_3_7          : 5;
        uint64_t core_int              : 1;  /**< [  2:  2](RO/H) TWSI core interrupt, whenever IFLG is set. Ignored when the HLC is enabled. */
        uint64_t ts_int                : 1;  /**< [  1:  1](R/W1C/H) MIO_TWS()_TWSI_SW register-update interrupt. Ignored when the HLC is disabled. */
        uint64_t st_int                : 1;  /**< [  0:  0](R/W1C/H) MIO_TWS()_SW_TWSI register-update interrupt. Ignored when the HLC is disabled. */
#else /* Word 0 - Little Endian */
        uint64_t st_int                : 1;  /**< [  0:  0](R/W1C/H) MIO_TWS()_SW_TWSI register-update interrupt. Ignored when the HLC is disabled. */
        uint64_t ts_int                : 1;  /**< [  1:  1](R/W1C/H) MIO_TWS()_TWSI_SW register-update interrupt. Ignored when the HLC is disabled. */
        uint64_t core_int              : 1;  /**< [  2:  2](RO/H) TWSI core interrupt, whenever IFLG is set. Ignored when the HLC is enabled. */
        uint64_t reserved_3_7          : 5;
        uint64_t sda_ovr               : 1;  /**< [  8:  8](R/W) SDA testing override:
                                                                 0 = Normal operation, SDA bus controlled by TWSI core.
                                                                 1 = Pull SDA low. */
        uint64_t scl_ovr               : 1;  /**< [  9:  9](R/W) SCL testing override:
                                                                 0 = Normal operation, SCL bus controlled by TWSI core.
                                                                 1 = Pull SCL low. */
        uint64_t sda                   : 1;  /**< [ 10: 10](RO/H) SDA signal. */
        uint64_t scl                   : 1;  /**< [ 11: 11](RO/H) SCL signal. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_twsx_int_s cn; */
} bdk_mio_twsx_int_t;

static inline uint64_t BDK_MIO_TWSX_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_INT(unsigned long a)
{
    if (a<=5)
        return 0x87e0d0001010ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("MIO_TWSX_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_MIO_TWSX_INT(a) bdk_mio_twsx_int_t
#define bustype_BDK_MIO_TWSX_INT(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_TWSX_INT(a) "MIO_TWSX_INT"
#define busnum_BDK_MIO_TWSX_INT(a) (a)
#define arguments_BDK_MIO_TWSX_INT(a) (a),-1,-1,-1

/**
 * Register (RSL) mio_tws#_int_ena_w1c
 *
 * TWSI Interrupt Enable Clear Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_twsx_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t core_int              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears MIO_TWS()_INT[CORE_INT]. */
        uint64_t ts_int                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears MIO_TWS()_INT[TS_INT]. */
        uint64_t st_int                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears MIO_TWS()_INT[ST_INT]. */
#else /* Word 0 - Little Endian */
        uint64_t st_int                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears MIO_TWS()_INT[ST_INT]. */
        uint64_t ts_int                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears MIO_TWS()_INT[TS_INT]. */
        uint64_t core_int              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears MIO_TWS()_INT[CORE_INT]. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_twsx_int_ena_w1c_s cn; */
} bdk_mio_twsx_int_ena_w1c_t;

static inline uint64_t BDK_MIO_TWSX_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_INT_ENA_W1C(unsigned long a)
{
    if (a<=5)
        return 0x87e0d0001028ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("MIO_TWSX_INT_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_MIO_TWSX_INT_ENA_W1C(a) bdk_mio_twsx_int_ena_w1c_t
#define bustype_BDK_MIO_TWSX_INT_ENA_W1C(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_TWSX_INT_ENA_W1C(a) "MIO_TWSX_INT_ENA_W1C"
#define busnum_BDK_MIO_TWSX_INT_ENA_W1C(a) (a)
#define arguments_BDK_MIO_TWSX_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL) mio_tws#_int_ena_w1s
 *
 * TWSI Interrupt Enable Set Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_twsx_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t core_int              : 1;  /**< [  2:  2](R/W1S/H) Enables reporting of MIO_TWS()_INT[CORE_INT]. */
        uint64_t ts_int                : 1;  /**< [  1:  1](R/W1S/H) Enables reporting of MIO_TWS()_INT[TS_INT]. */
        uint64_t st_int                : 1;  /**< [  0:  0](R/W1S/H) Enables reporting of MIO_TWS()_INT[ST_INT]. */
#else /* Word 0 - Little Endian */
        uint64_t st_int                : 1;  /**< [  0:  0](R/W1S/H) Enables reporting of MIO_TWS()_INT[ST_INT]. */
        uint64_t ts_int                : 1;  /**< [  1:  1](R/W1S/H) Enables reporting of MIO_TWS()_INT[TS_INT]. */
        uint64_t core_int              : 1;  /**< [  2:  2](R/W1S/H) Enables reporting of MIO_TWS()_INT[CORE_INT]. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_twsx_int_ena_w1s_s cn; */
} bdk_mio_twsx_int_ena_w1s_t;

static inline uint64_t BDK_MIO_TWSX_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_INT_ENA_W1S(unsigned long a)
{
    if (a<=5)
        return 0x87e0d0001030ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("MIO_TWSX_INT_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_MIO_TWSX_INT_ENA_W1S(a) bdk_mio_twsx_int_ena_w1s_t
#define bustype_BDK_MIO_TWSX_INT_ENA_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_TWSX_INT_ENA_W1S(a) "MIO_TWSX_INT_ENA_W1S"
#define busnum_BDK_MIO_TWSX_INT_ENA_W1S(a) (a)
#define arguments_BDK_MIO_TWSX_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) mio_tws#_int_w1s
 *
 * TWSI Interrupt Set Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_twsx_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t core_int              : 1;  /**< [  2:  2](RO/H) Reads MIO_TWS()_INT[CORE_INT]. */
        uint64_t ts_int                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MIO_TWS()_INT[TS_INT]. */
        uint64_t st_int                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MIO_TWS()_INT[ST_INT]. */
#else /* Word 0 - Little Endian */
        uint64_t st_int                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MIO_TWS()_INT[ST_INT]. */
        uint64_t ts_int                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MIO_TWS()_INT[TS_INT]. */
        uint64_t core_int              : 1;  /**< [  2:  2](RO/H) Reads MIO_TWS()_INT[CORE_INT]. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_twsx_int_w1s_s cn; */
} bdk_mio_twsx_int_w1s_t;

static inline uint64_t BDK_MIO_TWSX_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_INT_W1S(unsigned long a)
{
    if (a<=5)
        return 0x87e0d0001020ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("MIO_TWSX_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_MIO_TWSX_INT_W1S(a) bdk_mio_twsx_int_w1s_t
#define bustype_BDK_MIO_TWSX_INT_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_TWSX_INT_W1S(a) "MIO_TWSX_INT_W1S"
#define busnum_BDK_MIO_TWSX_INT_W1S(a) (a)
#define arguments_BDK_MIO_TWSX_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) mio_tws#_mode
 *
 * TWSI Mode Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_twsx_mode_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t stretch               : 1;  /**< [  1:  1](R/W) Clock Stretching enable.
                                                                 When enabled and device in Master mode, it allows slave device
                                                                 to extend low period of the clock. During the clock extension period, the SCL output from
                                                                 Master device is disabled. */
        uint64_t hs_mode               : 1;  /**< [  0:  0](R/W) I2C bus high-speed mode.

                                                                 0 = Open drain drive on TWS_SCL. TWS_SCL clock signal high-to-low ratio is 1 to 1.
                                                                 OSCL output frequency divisor is 10.

                                                                 1 = Current source circuit is used to drive TWS_SCL pin when device is in master mode,
                                                                 but disabled after each repeated start condition
                                                                 and after each act or nack to give a slave a chance to stretch the clock.
                                                                 TWS_SCL clock signal high-to-low ratio is 1 to 2.
                                                                 OSCL output frequency divisor is 15. */
#else /* Word 0 - Little Endian */
        uint64_t hs_mode               : 1;  /**< [  0:  0](R/W) I2C bus high-speed mode.

                                                                 0 = Open drain drive on TWS_SCL. TWS_SCL clock signal high-to-low ratio is 1 to 1.
                                                                 OSCL output frequency divisor is 10.

                                                                 1 = Current source circuit is used to drive TWS_SCL pin when device is in master mode,
                                                                 but disabled after each repeated start condition
                                                                 and after each act or nack to give a slave a chance to stretch the clock.
                                                                 TWS_SCL clock signal high-to-low ratio is 1 to 2.
                                                                 OSCL output frequency divisor is 15. */
        uint64_t stretch               : 1;  /**< [  1:  1](R/W) Clock Stretching enable.
                                                                 When enabled and device in Master mode, it allows slave device
                                                                 to extend low period of the clock. During the clock extension period, the SCL output from
                                                                 Master device is disabled. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_twsx_mode_s cn; */
} bdk_mio_twsx_mode_t;

static inline uint64_t BDK_MIO_TWSX_MODE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_MODE(unsigned long a)
{
    if (a<=5)
        return 0x87e0d0001038ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("MIO_TWSX_MODE", 1, a, 0, 0, 0);
}

#define typedef_BDK_MIO_TWSX_MODE(a) bdk_mio_twsx_mode_t
#define bustype_BDK_MIO_TWSX_MODE(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_TWSX_MODE(a) "MIO_TWSX_MODE"
#define busnum_BDK_MIO_TWSX_MODE(a) (a)
#define arguments_BDK_MIO_TWSX_MODE(a) (a),-1,-1,-1

/**
 * Register (RSL) mio_tws#_msix_pba#
 *
 * TWSI MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the MIO_TWS_INT_VEC_E
 * enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_twsx_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated MIO_TWS()_MSIX_VEC()_CTL, enumerated by
                                                                 MIO_TWS_INT_VEC_E. Bits that have no associated MIO_TWS_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated MIO_TWS()_MSIX_VEC()_CTL, enumerated by
                                                                 MIO_TWS_INT_VEC_E. Bits that have no associated MIO_TWS_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_twsx_msix_pbax_s cn; */
} bdk_mio_twsx_msix_pbax_t;

static inline uint64_t BDK_MIO_TWSX_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if ((a<=5) && (b==0))
        return 0x87e0d0ff0000ll + 0x1000000ll * ((a) & 0x7) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("MIO_TWSX_MSIX_PBAX", 2, a, b, 0, 0);
}

#define typedef_BDK_MIO_TWSX_MSIX_PBAX(a,b) bdk_mio_twsx_msix_pbax_t
#define bustype_BDK_MIO_TWSX_MSIX_PBAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_TWSX_MSIX_PBAX(a,b) "MIO_TWSX_MSIX_PBAX"
#define busnum_BDK_MIO_TWSX_MSIX_PBAX(a,b) (a)
#define arguments_BDK_MIO_TWSX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mio_tws#_msix_vec#_addr
 *
 * TWSI MSI-X Vector Table Address Registers
 * This register is the MSI-X vector table, indexed by the MIO_TWS_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_twsx_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's MIO_TWS()_MSIX_VEC()_ADDR, MIO_TWS()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of MIO_TWS()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_MIO_TWS()_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if [SECVEC]
                                                                 was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's MIO_TWS()_MSIX_VEC()_ADDR, MIO_TWS()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of MIO_TWS()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_MIO_TWS()_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if [SECVEC]
                                                                 was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_twsx_msix_vecx_addr_s cn; */
} bdk_mio_twsx_msix_vecx_addr_t;

static inline uint64_t BDK_MIO_TWSX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if ((a<=5) && (b==0))
        return 0x87e0d0f00000ll + 0x1000000ll * ((a) & 0x7) + 0x10ll * ((b) & 0x0);
    __bdk_csr_fatal("MIO_TWSX_MSIX_VECX_ADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_MIO_TWSX_MSIX_VECX_ADDR(a,b) bdk_mio_twsx_msix_vecx_addr_t
#define bustype_BDK_MIO_TWSX_MSIX_VECX_ADDR(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_TWSX_MSIX_VECX_ADDR(a,b) "MIO_TWSX_MSIX_VECX_ADDR"
#define busnum_BDK_MIO_TWSX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_BDK_MIO_TWSX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mio_tws#_msix_vec#_ctl
 *
 * TWSI MSI-X Vector Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the MIO_TWS_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_twsx_msix_vecx_ctl_s
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
    /* struct bdk_mio_twsx_msix_vecx_ctl_s cn; */
} bdk_mio_twsx_msix_vecx_ctl_t;

static inline uint64_t BDK_MIO_TWSX_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if ((a<=5) && (b==0))
        return 0x87e0d0f00008ll + 0x1000000ll * ((a) & 0x7) + 0x10ll * ((b) & 0x0);
    __bdk_csr_fatal("MIO_TWSX_MSIX_VECX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_MIO_TWSX_MSIX_VECX_CTL(a,b) bdk_mio_twsx_msix_vecx_ctl_t
#define bustype_BDK_MIO_TWSX_MSIX_VECX_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_TWSX_MSIX_VECX_CTL(a,b) "MIO_TWSX_MSIX_VECX_CTL"
#define busnum_BDK_MIO_TWSX_MSIX_VECX_CTL(a,b) (a)
#define arguments_BDK_MIO_TWSX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mio_tws#_sw_twsi
 *
 * Software to TWSI Register
 * This register allows software to:
 * * Initiate master-mode operations with a write operation, and read the result with a
 * read operation.
 * * Load four bytes for later retrieval (slave mode) with a write operation and check validity
 * with a read operation.
 * * Launch a configuration read/write operation with a write operation and read the result with
 * a read operation.
 *
 * This register should be read or written by software, and read by the TWSI device. The TWSI
 * device can use either two-byte or five-byte read operations to reference this register.
 * The TWSI device considers this register valid when [V] = 1 and [SLONLY] = 1.
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_twsx_sw_twsi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t v                     : 1;  /**< [ 63: 63](RC/W/H) Valid bit. Set on a write operation (should always be written with a 1). Cleared when a
                                                                 TWSI master-mode operation completes, a TWSI configuration register access completes, or
                                                                 when the TWSI device reads the register if SLONLY = 1. */
        uint64_t slonly                : 1;  /**< [ 62: 62](R/W) Slave-only mode.

                                                                 When this bit is set, no operations are initiated with a write operation. Only the D field
                                                                 is updated in this case.

                                                                 When this bit is clear, a write operation initiates either a master-mode operation or a
                                                                 TWSI configuration register access. */
        uint64_t eia                   : 1;  /**< [ 61: 61](R/W) Extended internal address. Sends an additional internal address byte (the MSB of IA is
                                                                 from MIO_TWS()_SW_TWSI_EXT[IA]). */
        uint64_t op                    : 4;  /**< [ 60: 57](R/W) Opcode field. When the register is written with SLONLY = 0, this field initiates one of
                                                                 the following read or write operations:
                                                                 0x0 = 7-bit byte master-mode operation.
                                                                 0x1 = 7-bit byte combined-read master-mode operation, 7-bit byte write-with-IA master-mode
                                                                 operation.
                                                                 0x2 = 10-bit byte master-mode operation.
                                                                 0x3 = 10-bit byte combined-read master-mode operation, 10-bit byte write-with-IA master-
                                                                 mode operation.
                                                                 0x4 = TWSI master-clock register, TWSI_CLK in TWSI Master Clock Register.
                                                                 0x6 = See EOP_IA field.
                                                                 0x8 = 7-bit 4-byte master-mode operation.
                                                                 0x9 = 7-bit 4-byte combined-read master-mode operation, 7-bit 4-byte write-with-IA master-
                                                                 mode operation.
                                                                 0xA = 10-bit 4-byte master-mode operation.
                                                                 0xB = 10-bit 4-byte combined-read master-mode operation, 10-bit 4-byte write-with-IA
                                                                 master-mode operation. */
        uint64_t r                     : 1;  /**< [ 56: 56](R/W/H) Read bit or result. If this bit is set on a CSR write when SLONLY = 0, the operation is a
                                                                 read operation (if clear, it is a write operation).
                                                                 On a CSR read, this bit returns the result indication for the most recent master-mode
                                                                 operation, 1 = success, 0 = failure. */
        uint64_t sovr                  : 1;  /**< [ 55: 55](R/W) Size override. If this bit is set, use the SIZE field to determine the master-mode
                                                                 operation size rather than what OP specifies. For operations greater than four bytes, the
                                                                 additional data is contained in MIO_TWS()_SW_TWSI_EXT[DATA]. */
        uint64_t size                  : 3;  /**< [ 54: 52](R/W) Size minus one. Specifies the size in bytes of the master-mode operation if SOVR = 1. (0 =
                                                                 1 byte, 1 = 2 bytes, ... 7 = 8 bytes). */
        uint64_t scr                   : 2;  /**< [ 51: 50](R/W) Scratch. Unused, but retain state. */
        uint64_t addr                  : 10; /**< [ 49: 40](R/W) Address field. The address of the remote device for a master-mode operation. ADDR<9:7> are
                                                                 only used for 10-bit addressing.

                                                                 Note that when mastering a 7-bit OP, ADDR<6:0> should not take any of the values 0x78,
                                                                 0x79, 0x7A nor 0x7B. (These 7-bit addresses are reserved to extend to 10-bit addressing). */
        uint64_t ia                    : 5;  /**< [ 39: 35](R/W) Internal Address. Used when launching a combined master-mode operation. The lower 3
                                                                 address bits are contained in EOP_IA. */
        uint64_t eop_ia                : 3;  /**< [ 34: 32](R/W) Extra opcode, used when OP<3:0> = 0x6 and SLONLY = 0.
                                                                 0x0 = TWSI slave address register (TWSI_SLAVE_ADD).
                                                                 0x1 = TWSI data register (TWSI_DATA).
                                                                 0x2 = TWSI control register (TWSI_CTL).
                                                                 0x3 = (when R =  0) TWSI clock control register (TWSI_CLKCTL).
                                                                 0x3 = (when R = 1) TWSI status register (TWSI_STAT).
                                                                 0x4 = TWSI extended slave register (TWSI_SLAVE_ADD_EXT).
                                                                 0x7 = TWSI soft reset register (TWSI_RST).

                                                                 Also provides the lower 3 bits of internal address when launching a combined master-mode
                                                                 operation. */
        uint64_t data                  : 32; /**< [ 31:  0](R/W/H) Data field.
                                                                 Used on a write operation when:
                                                                 * Initiating a master-mode write operation (SLONLY = 0).
                                                                 * Writing a TWSI configuration register (SLONLY = 0).
                                                                 * A slave-mode write operation (SLONLY = 1).

                                                                 The read value is updated by:
                                                                 * A write operation to this register.
                                                                 * Master-mode completion (contains error code).
                                                                 * TWSI configuration-register read (contains result). */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 32; /**< [ 31:  0](R/W/H) Data field.
                                                                 Used on a write operation when:
                                                                 * Initiating a master-mode write operation (SLONLY = 0).
                                                                 * Writing a TWSI configuration register (SLONLY = 0).
                                                                 * A slave-mode write operation (SLONLY = 1).

                                                                 The read value is updated by:
                                                                 * A write operation to this register.
                                                                 * Master-mode completion (contains error code).
                                                                 * TWSI configuration-register read (contains result). */
        uint64_t eop_ia                : 3;  /**< [ 34: 32](R/W) Extra opcode, used when OP<3:0> = 0x6 and SLONLY = 0.
                                                                 0x0 = TWSI slave address register (TWSI_SLAVE_ADD).
                                                                 0x1 = TWSI data register (TWSI_DATA).
                                                                 0x2 = TWSI control register (TWSI_CTL).
                                                                 0x3 = (when R =  0) TWSI clock control register (TWSI_CLKCTL).
                                                                 0x3 = (when R = 1) TWSI status register (TWSI_STAT).
                                                                 0x4 = TWSI extended slave register (TWSI_SLAVE_ADD_EXT).
                                                                 0x7 = TWSI soft reset register (TWSI_RST).

                                                                 Also provides the lower 3 bits of internal address when launching a combined master-mode
                                                                 operation. */
        uint64_t ia                    : 5;  /**< [ 39: 35](R/W) Internal Address. Used when launching a combined master-mode operation. The lower 3
                                                                 address bits are contained in EOP_IA. */
        uint64_t addr                  : 10; /**< [ 49: 40](R/W) Address field. The address of the remote device for a master-mode operation. ADDR<9:7> are
                                                                 only used for 10-bit addressing.

                                                                 Note that when mastering a 7-bit OP, ADDR<6:0> should not take any of the values 0x78,
                                                                 0x79, 0x7A nor 0x7B. (These 7-bit addresses are reserved to extend to 10-bit addressing). */
        uint64_t scr                   : 2;  /**< [ 51: 50](R/W) Scratch. Unused, but retain state. */
        uint64_t size                  : 3;  /**< [ 54: 52](R/W) Size minus one. Specifies the size in bytes of the master-mode operation if SOVR = 1. (0 =
                                                                 1 byte, 1 = 2 bytes, ... 7 = 8 bytes). */
        uint64_t sovr                  : 1;  /**< [ 55: 55](R/W) Size override. If this bit is set, use the SIZE field to determine the master-mode
                                                                 operation size rather than what OP specifies. For operations greater than four bytes, the
                                                                 additional data is contained in MIO_TWS()_SW_TWSI_EXT[DATA]. */
        uint64_t r                     : 1;  /**< [ 56: 56](R/W/H) Read bit or result. If this bit is set on a CSR write when SLONLY = 0, the operation is a
                                                                 read operation (if clear, it is a write operation).
                                                                 On a CSR read, this bit returns the result indication for the most recent master-mode
                                                                 operation, 1 = success, 0 = failure. */
        uint64_t op                    : 4;  /**< [ 60: 57](R/W) Opcode field. When the register is written with SLONLY = 0, this field initiates one of
                                                                 the following read or write operations:
                                                                 0x0 = 7-bit byte master-mode operation.
                                                                 0x1 = 7-bit byte combined-read master-mode operation, 7-bit byte write-with-IA master-mode
                                                                 operation.
                                                                 0x2 = 10-bit byte master-mode operation.
                                                                 0x3 = 10-bit byte combined-read master-mode operation, 10-bit byte write-with-IA master-
                                                                 mode operation.
                                                                 0x4 = TWSI master-clock register, TWSI_CLK in TWSI Master Clock Register.
                                                                 0x6 = See EOP_IA field.
                                                                 0x8 = 7-bit 4-byte master-mode operation.
                                                                 0x9 = 7-bit 4-byte combined-read master-mode operation, 7-bit 4-byte write-with-IA master-
                                                                 mode operation.
                                                                 0xA = 10-bit 4-byte master-mode operation.
                                                                 0xB = 10-bit 4-byte combined-read master-mode operation, 10-bit 4-byte write-with-IA
                                                                 master-mode operation. */
        uint64_t eia                   : 1;  /**< [ 61: 61](R/W) Extended internal address. Sends an additional internal address byte (the MSB of IA is
                                                                 from MIO_TWS()_SW_TWSI_EXT[IA]). */
        uint64_t slonly                : 1;  /**< [ 62: 62](R/W) Slave-only mode.

                                                                 When this bit is set, no operations are initiated with a write operation. Only the D field
                                                                 is updated in this case.

                                                                 When this bit is clear, a write operation initiates either a master-mode operation or a
                                                                 TWSI configuration register access. */
        uint64_t v                     : 1;  /**< [ 63: 63](RC/W/H) Valid bit. Set on a write operation (should always be written with a 1). Cleared when a
                                                                 TWSI master-mode operation completes, a TWSI configuration register access completes, or
                                                                 when the TWSI device reads the register if SLONLY = 1. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_twsx_sw_twsi_s cn; */
} bdk_mio_twsx_sw_twsi_t;

static inline uint64_t BDK_MIO_TWSX_SW_TWSI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_SW_TWSI(unsigned long a)
{
    if (a<=5)
        return 0x87e0d0001000ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("MIO_TWSX_SW_TWSI", 1, a, 0, 0, 0);
}

#define typedef_BDK_MIO_TWSX_SW_TWSI(a) bdk_mio_twsx_sw_twsi_t
#define bustype_BDK_MIO_TWSX_SW_TWSI(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_TWSX_SW_TWSI(a) "MIO_TWSX_SW_TWSI"
#define busnum_BDK_MIO_TWSX_SW_TWSI(a) (a)
#define arguments_BDK_MIO_TWSX_SW_TWSI(a) (a),-1,-1,-1

/**
 * Register (RSL) mio_tws#_sw_twsi_ext
 *
 * Software to TWSI Extension Register
 * This register contains an additional byte of internal address and four additional bytes of
 * data to be used with TWSI master-mode operations.
 *
 * The IA field is sent as the first byte of internal address when performing master-mode
 * combined-read/write-with-IA operations and MIO_TWS()_SW_TWSI[EIA] is set. The D field
 * extends the data field of MIO_TWS()_SW_TWSI for a total of 8 bytes (SOVR must be set to
 * perform operations greater than 4 bytes).
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_twsx_sw_twsi_ext_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t ia                    : 8;  /**< [ 39: 32](R/W) Extended internal address. Sent as the first byte of internal address when performing
                                                                 master-mode combined-read/write-with-IA operations and MIO_TWS()_SW_TWSI[EIA] is set. */
        uint64_t data                  : 32; /**< [ 31:  0](R/W/H) Extended data. Extends the data field of MIO_TWS()_SW_TWSI for a total of eight bytes
                                                                 (MIO_TWS()_SW_TWSI[SOVR] must be set to 1 to perform operations greater than four
                                                                 bytes). */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 32; /**< [ 31:  0](R/W/H) Extended data. Extends the data field of MIO_TWS()_SW_TWSI for a total of eight bytes
                                                                 (MIO_TWS()_SW_TWSI[SOVR] must be set to 1 to perform operations greater than four
                                                                 bytes). */
        uint64_t ia                    : 8;  /**< [ 39: 32](R/W) Extended internal address. Sent as the first byte of internal address when performing
                                                                 master-mode combined-read/write-with-IA operations and MIO_TWS()_SW_TWSI[EIA] is set. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_twsx_sw_twsi_ext_s cn; */
} bdk_mio_twsx_sw_twsi_ext_t;

static inline uint64_t BDK_MIO_TWSX_SW_TWSI_EXT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_SW_TWSI_EXT(unsigned long a)
{
    if (a<=5)
        return 0x87e0d0001018ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("MIO_TWSX_SW_TWSI_EXT", 1, a, 0, 0, 0);
}

#define typedef_BDK_MIO_TWSX_SW_TWSI_EXT(a) bdk_mio_twsx_sw_twsi_ext_t
#define bustype_BDK_MIO_TWSX_SW_TWSI_EXT(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_TWSX_SW_TWSI_EXT(a) "MIO_TWSX_SW_TWSI_EXT"
#define busnum_BDK_MIO_TWSX_SW_TWSI_EXT(a) (a)
#define arguments_BDK_MIO_TWSX_SW_TWSI_EXT(a) (a),-1,-1,-1

/**
 * Register (RSL) mio_tws#_twsi_sw
 *
 * TWSI to Software Register
 * This register allows the TWSI device to transfer data to software and later check that
 * software has received the information.
 *
 * This register should be read or written by the TWSI device, and read by software. The TWSI
 * device can use one-byte or four-byte payload write operations, and two-byte payload read
 * operations. The TWSI device considers this register valid when V = 1.
 */
typedef union
{
    uint64_t u;
    struct bdk_mio_twsx_twsi_sw_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t v                     : 2;  /**< [ 63: 62](RC/W/H) Valid bits. These bits are not directly writable. They are set to 11 on any write
                                                                 operation by the TWSI device. They are cleared to 00 on any read operation by software. */
        uint64_t reserved_32_61        : 30;
        uint64_t data                  : 32; /**< [ 31:  0](RO/H) Data field. Updated on a write operation by the TWSI device. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 32; /**< [ 31:  0](RO/H) Data field. Updated on a write operation by the TWSI device. */
        uint64_t reserved_32_61        : 30;
        uint64_t v                     : 2;  /**< [ 63: 62](RC/W/H) Valid bits. These bits are not directly writable. They are set to 11 on any write
                                                                 operation by the TWSI device. They are cleared to 00 on any read operation by software. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mio_twsx_twsi_sw_s cn; */
} bdk_mio_twsx_twsi_sw_t;

static inline uint64_t BDK_MIO_TWSX_TWSI_SW(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_TWSI_SW(unsigned long a)
{
    if (a<=5)
        return 0x87e0d0001008ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("MIO_TWSX_TWSI_SW", 1, a, 0, 0, 0);
}

#define typedef_BDK_MIO_TWSX_TWSI_SW(a) bdk_mio_twsx_twsi_sw_t
#define bustype_BDK_MIO_TWSX_TWSI_SW(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MIO_TWSX_TWSI_SW(a) "MIO_TWSX_TWSI_SW"
#define busnum_BDK_MIO_TWSX_TWSI_SW(a) (a)
#define arguments_BDK_MIO_TWSX_TWSI_SW(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_MIO_TWS_H__ */
