#ifndef __BDK_CSRS_L2C_CBC_H__
#define __BDK_CSRS_L2C_CBC_H__
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
 * Cavium L2C_CBC.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration l2c_cbc_int_vec_e
 *
 * L2C_CBC MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_L2C_CBC_INT_VEC_E_INTS_CN88XX (0) /**< See interrupt clears L2C_CBC(0..3)_INT_W1C,
                                       interrupt sets L2C_CBC(0..3)_INT_W1S,
                                       enable clears L2C_CBC(0..3)_INT_ENA_W1C,
                                       and enable sets L2C_CBC(0..3)_INT_ENA_W1S. */
#define BDK_L2C_CBC_INT_VEC_E_INTS_CN83XX (0) /**< See interrupt clears L2C_CBC(0..1)_INT_W1C,
                                       interrupt sets L2C_CBC(0..1)_INT_W1S,
                                       enable clears L2C_CBC(0..1)_INT_ENA_W1C,
                                       and enable sets L2C_CBC(0..1)_INT_ENA_W1S. */

/**
 * Enumeration l2c_cbc_bar_e
 *
 * L2C_CBC Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_L2C_CBC_BAR_E_L2C_CBCX_PF_BAR0_CN88XX(a) (0x87e058000000ll + 0x1000000ll * (a)) /**< (0..3)Base address for standard registers. */
#define BDK_L2C_CBC_BAR_E_L2C_CBCX_PF_BAR0_CN83XX(a) (0x87e058000000ll + 0x1000000ll * (a)) /**< (0..1)Base address for standard registers. */
#define BDK_L2C_CBC_BAR_E_L2C_CBCX_PF_BAR4_CN88XX(a) (0x87e058f00000ll + 0x1000000ll * (a)) /**< (0..3)Base address for MSI-X registers. */
#define BDK_L2C_CBC_BAR_E_L2C_CBCX_PF_BAR4_CN83XX(a) (0x87e058f00000ll + 0x1000000ll * (a)) /**< (0..1)Base address for MSI-X registers. */

/**
 * Register (RSL) l2c_cbc#_inv#_pfc
 *
 * Level 2 Cache IOC Performance Counter Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_invx_pfc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Current counter value. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Current counter value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_l2c_cbcx_invx_pfc_s cn; */
} bdk_l2c_cbcx_invx_pfc_t;

static inline uint64_t BDK_L2C_CBCX_INVX_PFC(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_INVX_PFC(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e058000020ll + 0x1000000ll * ((a) & 0x1) + 0x40ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e058000020ll + 0x1000000ll * ((a) & 0x3) + 0x40ll * ((b) & 0x1);
    __bdk_csr_fatal("L2C_CBCX_INVX_PFC", 2, a, b, 0, 0);
}

#define typedef_BDK_L2C_CBCX_INVX_PFC(a,b) bdk_l2c_cbcx_invx_pfc_t
#define bustype_BDK_L2C_CBCX_INVX_PFC(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_INVX_PFC(a,b) "L2C_CBCX_INVX_PFC"
#define busnum_BDK_L2C_CBCX_INVX_PFC(a,b) (a)
#define arguments_BDK_L2C_CBCX_INVX_PFC(a,b) (a),(b),-1,-1

/**
 * Register (RSL) l2c_cbc#_scratch
 *
 * INTERNAL: L2C CBC General Purpose Scratch Register
 *
 * These registers are only reset by hardware during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t scratch               : 7;  /**< [  7:  1](R/W) General purpose scratch register. */
        uint64_t invdly                : 1;  /**< [  0:  0](R/W) Delays all invalidates for 9 cycles after a broadcast invalidate. */
#else /* Word 0 - Little Endian */
        uint64_t invdly                : 1;  /**< [  0:  0](R/W) Delays all invalidates for 9 cycles after a broadcast invalidate. */
        uint64_t scratch               : 7;  /**< [  7:  1](R/W) General purpose scratch register. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_l2c_cbcx_scratch_s cn; */
} bdk_l2c_cbcx_scratch_t;

static inline uint64_t BDK_L2C_CBCX_SCRATCH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_SCRATCH(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e0580d0000ll + 0x1000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e0580d0000ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("L2C_CBCX_SCRATCH", 1, a, 0, 0, 0);
}

#define typedef_BDK_L2C_CBCX_SCRATCH(a) bdk_l2c_cbcx_scratch_t
#define bustype_BDK_L2C_CBCX_SCRATCH(a) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_SCRATCH(a) "L2C_CBCX_SCRATCH"
#define busnum_BDK_L2C_CBCX_SCRATCH(a) (a)
#define arguments_BDK_L2C_CBCX_SCRATCH(a) (a),-1,-1,-1

/**
 * Register (RSL) l2c_cbc#_msix_vec#_addr
 *
 * L2C_CBC MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the L2C_CBC_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's L2C_CBC()_MSIX_VEC()_ADDR, L2C_CBC()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of L2C_CBC()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_L2C_CBC_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's L2C_CBC()_MSIX_VEC()_ADDR, L2C_CBC()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of L2C_CBC()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_L2C_CBC_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_l2c_cbcx_msix_vecx_addr_s cn; */
} bdk_l2c_cbcx_msix_vecx_addr_t;

static inline uint64_t BDK_L2C_CBCX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e058f00000ll + 0x1000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e058f00000ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0x0);
    __bdk_csr_fatal("L2C_CBCX_MSIX_VECX_ADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_L2C_CBCX_MSIX_VECX_ADDR(a,b) bdk_l2c_cbcx_msix_vecx_addr_t
#define bustype_BDK_L2C_CBCX_MSIX_VECX_ADDR(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_MSIX_VECX_ADDR(a,b) "L2C_CBCX_MSIX_VECX_ADDR"
#define busnum_BDK_L2C_CBCX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_BDK_L2C_CBCX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (RSL) l2c_cbc#_xmd#_pfc
 *
 * Level 2 Cache STORE bus Performance Counter Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_xmdx_pfc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Current counter value. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Current counter value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_l2c_cbcx_xmdx_pfc_s cn; */
} bdk_l2c_cbcx_xmdx_pfc_t;

static inline uint64_t BDK_L2C_CBCX_XMDX_PFC(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_XMDX_PFC(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e058000008ll + 0x1000000ll * ((a) & 0x1) + 0x40ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e058000008ll + 0x1000000ll * ((a) & 0x3) + 0x40ll * ((b) & 0x3);
    __bdk_csr_fatal("L2C_CBCX_XMDX_PFC", 2, a, b, 0, 0);
}

#define typedef_BDK_L2C_CBCX_XMDX_PFC(a,b) bdk_l2c_cbcx_xmdx_pfc_t
#define bustype_BDK_L2C_CBCX_XMDX_PFC(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_XMDX_PFC(a,b) "L2C_CBCX_XMDX_PFC"
#define busnum_BDK_L2C_CBCX_XMDX_PFC(a,b) (a)
#define arguments_BDK_L2C_CBCX_XMDX_PFC(a,b) (a),(b),-1,-1

/**
 * Register (RSL) l2c_cbc#_int_w1s
 *
 * Level 2 Cache CBC Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[IOWRDISOCI]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[IORDDISOCI]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[MIBDBE]. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[MIBSBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[RSDDBE]. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[RSDSBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[RSDSBE]. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[RSDDBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[MIBSBE]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[MIBDBE]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[IORDDISOCI]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[IOWRDISOCI]. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    struct bdk_l2c_cbcx_int_w1s_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t gsyncto               : 1;  /**< [  8:  8](R/W1S/H) Added in pass 2.0. Reads or sets L2C_CBC(0..1)_INT_W1C[GSYNCTO]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[IOWRDISOCI]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[IORDDISOCI]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[MIBDBE]. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[MIBSBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[RSDDBE]. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[RSDSBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[RSDSBE]. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[RSDDBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[MIBSBE]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[MIBDBE]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[IORDDISOCI]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets L2C_CBC(0..1)_INT_W1C[IOWRDISOCI]. */
        uint64_t gsyncto               : 1;  /**< [  8:  8](R/W1S/H) Added in pass 2.0. Reads or sets L2C_CBC(0..1)_INT_W1C[GSYNCTO]. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } cn83xx;
    struct bdk_l2c_cbcx_int_w1s_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t gsyncto               : 1;  /**< [  8:  8](R/W1S/H) Added in pass 2.0. Reads or sets L2C_CBC(0..3)_INT_W1C[GSYNCTO]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[IOWRDISOCI]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[IORDDISOCI]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[MIBDBE]. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[MIBSBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[RSDDBE]. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[RSDSBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[RSDSBE]. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[RSDDBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[MIBSBE]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[MIBDBE]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[IORDDISOCI]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[IOWRDISOCI]. */
        uint64_t gsyncto               : 1;  /**< [  8:  8](R/W1S/H) Added in pass 2.0. Reads or sets L2C_CBC(0..3)_INT_W1C[GSYNCTO]. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } cn88xxp2;
    struct bdk_l2c_cbcx_int_w1s_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t reserved_8            : 1;
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[IOWRDISOCI]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[IORDDISOCI]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[MIBDBE]. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[MIBSBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[RSDDBE]. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[RSDSBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[RSDSBE]. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[RSDDBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[MIBSBE]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[MIBDBE]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[IORDDISOCI]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets L2C_CBC(0..3)_INT_W1C[IOWRDISOCI]. */
        uint64_t reserved_8            : 1;
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_l2c_cbcx_int_w1s_t;

static inline uint64_t BDK_L2C_CBCX_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e058060008ll + 0x1000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e058060008ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("L2C_CBCX_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_L2C_CBCX_INT_W1S(a) bdk_l2c_cbcx_int_w1s_t
#define bustype_BDK_L2C_CBCX_INT_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_INT_W1S(a) "L2C_CBCX_INT_W1S"
#define busnum_BDK_L2C_CBCX_INT_W1S(a) (a)
#define arguments_BDK_L2C_CBCX_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) l2c_cbc#_int_w1c
 *
 * Level 2 Cache CBC Interrupt Registers
 * This register is for CBC-based interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_int_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1C/H) Illegal I/O write operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBST, IOBSTP, IOBADDR, IASET, IACLR, IAADD, IASWP, IACAS, and LMTST XMC
                                                                 commands. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1C/H) Illegal I/O read operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBLD, IASET, IACLR, IAADD, IASWP, and IACAS XMC commands. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1C/H) MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1C/H) MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1C/H) RSD double-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1C/H) RSD single-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1C/H) RSD single-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1C/H) RSD double-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1C/H) MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1C/H) MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1C/H) Illegal I/O read operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBLD, IASET, IACLR, IAADD, IASWP, and IACAS XMC commands. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1C/H) Illegal I/O write operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBST, IOBSTP, IOBADDR, IASET, IACLR, IAADD, IASWP, IACAS, and LMTST XMC
                                                                 commands. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    struct bdk_l2c_cbcx_int_w1c_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t gsyncto               : 1;  /**< [  8:  8](R/W1C/H) Global sync timeout.
                                                                 Added in pass 2.
                                                                 INTERNAL: The CBC global sync timeout only, so not an OCI timeout. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1C/H) Illegal I/O write operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBST, IOBSTP, IOBADDR, IASET, IACLR, IAADD, IASWP, IACAS, and LMTST XMC
                                                                 commands. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1C/H) Illegal I/O read operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBLD, IASET, IACLR, IAADD, IASWP, and IACAS XMC commands. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1C/H) MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1C/H) MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1C/H) RSD double-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1C/H) RSD single-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1C/H) RSD single-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1C/H) RSD double-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1C/H) MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1C/H) MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1C/H) Illegal I/O read operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBLD, IASET, IACLR, IAADD, IASWP, and IACAS XMC commands. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1C/H) Illegal I/O write operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBST, IOBSTP, IOBADDR, IASET, IACLR, IAADD, IASWP, IACAS, and LMTST XMC
                                                                 commands. */
        uint64_t gsyncto               : 1;  /**< [  8:  8](R/W1C/H) Global sync timeout.
                                                                 Added in pass 2.
                                                                 INTERNAL: The CBC global sync timeout only, so not an OCI timeout. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } cn83xx;
    /* struct bdk_l2c_cbcx_int_w1c_cn83xx cn88xxp2; */
    struct bdk_l2c_cbcx_int_w1c_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t reserved_8            : 1;
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1C/H) Illegal I/O write operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBST, IOBSTP, IOBADDR, IASET, IACLR, IAADD, IASWP, IACAS, and LMTST XMC
                                                                 commands. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1C/H) Illegal I/O read operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBLD, IASET, IACLR, IAADD, IASWP, and IACAS XMC commands. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1C/H) MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1C/H) MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1C/H) RSD double-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1C/H) RSD single-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1C/H) RSD single-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1C/H) RSD double-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1C/H) MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1C/H) MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1C/H) Illegal I/O read operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBLD, IASET, IACLR, IAADD, IASWP, and IACAS XMC commands. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1C/H) Illegal I/O write operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBST, IOBSTP, IOBADDR, IASET, IACLR, IAADD, IASWP, IACAS, and LMTST XMC
                                                                 commands. */
        uint64_t reserved_8            : 1;
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_l2c_cbcx_int_w1c_t;

static inline uint64_t BDK_L2C_CBCX_INT_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_INT_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e058060000ll + 0x1000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e058060000ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("L2C_CBCX_INT_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_L2C_CBCX_INT_W1C(a) bdk_l2c_cbcx_int_w1c_t
#define bustype_BDK_L2C_CBCX_INT_W1C(a) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_INT_W1C(a) "L2C_CBCX_INT_W1C"
#define busnum_BDK_L2C_CBCX_INT_W1C(a) (a)
#define arguments_BDK_L2C_CBCX_INT_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL) l2c_cbc#_rsc#_pfc
 *
 * Level 2 Cache COMMIT Bus Performance Counter Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_rscx_pfc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Current counter value. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Current counter value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_l2c_cbcx_rscx_pfc_s cn; */
} bdk_l2c_cbcx_rscx_pfc_t;

static inline uint64_t BDK_L2C_CBCX_RSCX_PFC(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_RSCX_PFC(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e058000010ll + 0x1000000ll * ((a) & 0x1) + 0x40ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e058000010ll + 0x1000000ll * ((a) & 0x3) + 0x40ll * ((b) & 0x3);
    __bdk_csr_fatal("L2C_CBCX_RSCX_PFC", 2, a, b, 0, 0);
}

#define typedef_BDK_L2C_CBCX_RSCX_PFC(a,b) bdk_l2c_cbcx_rscx_pfc_t
#define bustype_BDK_L2C_CBCX_RSCX_PFC(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_RSCX_PFC(a,b) "L2C_CBCX_RSCX_PFC"
#define busnum_BDK_L2C_CBCX_RSCX_PFC(a,b) (a)
#define arguments_BDK_L2C_CBCX_RSCX_PFC(a,b) (a),(b),-1,-1

/**
 * Register (RSL) l2c_cbc#_xmc_cmd
 *
 * Level 2 Cache ADD Bus Command Register
 * Note the following:
 *
 * The ADD bus command chosen must not be a IOB-destined command or operation is UNDEFINED.
 *
 * The ADD bus command will have SID forced to IOB, DID forced to L2C, no virtualization checks
 * performed (always pass), and xmdmsk forced to 0. Note that this implies that commands that
 * REQUIRE a STORE cycle (STP, STC, SAA, FAA, FAS) should not be used or the results are
 * unpredictable. The sid = IOB means that the way partitioning used for the command is
 * L2C_WPAR_IOB(). L2C_QOS_PP() are not used for these commands.
 *
 * Any FILL responses generated by the ADD bus command are ignored. Generated STINs, however,
 * will correctly invalidate the required cores.
 *
 * Any L2D read generated by the ADD bus command records the syndrome information in
 * L2C_TAD(0..3)_ECC0/1. If ECC is disabled prior to the CSR write, this provides the ability to
 * read the ECC bits directly. If ECC is not disabled, this should log zeros (assuming no ECC
 * errors were found in the block).
 *
 * A write that arrives while the INUSE bit is set will block until the INUSE bit clears. This
 * gives software two options when needing to issue a stream of write operations to L2C_XMC_CMD:
 * polling on the INUSE bit, or allowing hardware to handle the interlock -- at the expense of
 * locking up the RSL bus for potentially tens of cycles at a time while waiting for an available
 * LFB/VAB entry. Note that when the INUSE bit clears, the only ordering it implies is that
 * software can send another ADD bus command. Subsequent commands may complete out of order
 * relative to earlier commands.
 *
 * The address written to L2C_XMC_CMD is a physical address. L2C performs index
 * aliasing (if enabled) on the written address and uses that for the command. This
 * index-aliased address is what is returned on a read of the L2C_XMC_CMD register.
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_xmc_cmd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t inuse                 : 1;  /**< [ 63: 63](RO/H) Set to 1 by hardware upon receiving a write; cleared when command has issued (not
                                                                 necessarily completed, but ordered relative to other traffic) and hardware can accept
                                                                 another command. */
        uint64_t cmd                   : 7;  /**< [ 62: 56](R/W) Command to use for simulated ADD bus request. A new request can be accepted. */
        uint64_t reserved_49_55        : 7;
        uint64_t nonsec                : 1;  /**< [ 48: 48](R/W) Nonsecure bit to use for simulated ADD bus request. */
        uint64_t reserved_47           : 1;
        uint64_t qos                   : 3;  /**< [ 46: 44](R/W) QOS level to use for simulated ADD bus request. */
        uint64_t reserved_42_43        : 2;
        uint64_t node                  : 2;  /**< [ 41: 40](R/W) CCPI node to use for simulated ADD bus request. */
        uint64_t addr                  : 40; /**< [ 39:  0](R/W) Address to use for simulated ADD bus request. (The address written to L2C_XMC_CMD is a
                                                                 physical address. L2C performs index aliasing (if enabled) on the written
                                                                 address and uses that for the command. This index-aliased address is what is
                                                                 returned on a read of L2C_XMC_CMD.) */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 40; /**< [ 39:  0](R/W) Address to use for simulated ADD bus request. (The address written to L2C_XMC_CMD is a
                                                                 physical address. L2C performs index aliasing (if enabled) on the written
                                                                 address and uses that for the command. This index-aliased address is what is
                                                                 returned on a read of L2C_XMC_CMD.) */
        uint64_t node                  : 2;  /**< [ 41: 40](R/W) CCPI node to use for simulated ADD bus request. */
        uint64_t reserved_42_43        : 2;
        uint64_t qos                   : 3;  /**< [ 46: 44](R/W) QOS level to use for simulated ADD bus request. */
        uint64_t reserved_47           : 1;
        uint64_t nonsec                : 1;  /**< [ 48: 48](R/W) Nonsecure bit to use for simulated ADD bus request. */
        uint64_t reserved_49_55        : 7;
        uint64_t cmd                   : 7;  /**< [ 62: 56](R/W) Command to use for simulated ADD bus request. A new request can be accepted. */
        uint64_t inuse                 : 1;  /**< [ 63: 63](RO/H) Set to 1 by hardware upon receiving a write; cleared when command has issued (not
                                                                 necessarily completed, but ordered relative to other traffic) and hardware can accept
                                                                 another command. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_l2c_cbcx_xmc_cmd_s cn; */
} bdk_l2c_cbcx_xmc_cmd_t;

static inline uint64_t BDK_L2C_CBCX_XMC_CMD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_XMC_CMD(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e0580c0000ll + 0x1000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e0580c0000ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("L2C_CBCX_XMC_CMD", 1, a, 0, 0, 0);
}

#define typedef_BDK_L2C_CBCX_XMC_CMD(a) bdk_l2c_cbcx_xmc_cmd_t
#define bustype_BDK_L2C_CBCX_XMC_CMD(a) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_XMC_CMD(a) "L2C_CBCX_XMC_CMD"
#define busnum_BDK_L2C_CBCX_XMC_CMD(a) (a)
#define arguments_BDK_L2C_CBCX_XMC_CMD(a) (a),-1,-1,-1

/**
 * Register (RSL) l2c_cbc#_int_ena_w1s
 *
 * Level 2 Cache CBC Interrupt Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[IOWRDISOCI]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[IORDDISOCI]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[MIBDBE]. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[MIBSBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[RSDDBE]. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[RSDSBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[RSDSBE]. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[RSDDBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[MIBSBE]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[MIBDBE]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[IORDDISOCI]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[IOWRDISOCI]. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    struct bdk_l2c_cbcx_int_ena_w1s_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t gsyncto               : 1;  /**< [  8:  8](R/W1S/H) Added in pass 2.0. Reads or sets enable for L2C_CBC(0..1)_INT_W1C[GSYNCTO]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[IOWRDISOCI]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[IORDDISOCI]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[MIBDBE]. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[MIBSBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[RSDDBE]. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[RSDSBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[RSDSBE]. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[RSDDBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[MIBSBE]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[MIBDBE]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[IORDDISOCI]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for L2C_CBC(0..1)_INT_W1C[IOWRDISOCI]. */
        uint64_t gsyncto               : 1;  /**< [  8:  8](R/W1S/H) Added in pass 2.0. Reads or sets enable for L2C_CBC(0..1)_INT_W1C[GSYNCTO]. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } cn83xx;
    struct bdk_l2c_cbcx_int_ena_w1s_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t gsyncto               : 1;  /**< [  8:  8](R/W1S/H) Added in pass 2.0. Reads or sets enable for L2C_CBC(0..3)_INT_W1C[GSYNCTO]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[IOWRDISOCI]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[IORDDISOCI]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[MIBDBE]. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[MIBSBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[RSDDBE]. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[RSDSBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[RSDSBE]. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[RSDDBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[MIBSBE]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[MIBDBE]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[IORDDISOCI]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[IOWRDISOCI]. */
        uint64_t gsyncto               : 1;  /**< [  8:  8](R/W1S/H) Added in pass 2.0. Reads or sets enable for L2C_CBC(0..3)_INT_W1C[GSYNCTO]. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } cn88xxp2;
    struct bdk_l2c_cbcx_int_ena_w1s_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t reserved_8            : 1;
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[IOWRDISOCI]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[IORDDISOCI]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[MIBDBE]. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[MIBSBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[RSDDBE]. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[RSDSBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[RSDSBE]. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[RSDDBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[MIBSBE]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[MIBDBE]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[IORDDISOCI]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for L2C_CBC(0..3)_INT_W1C[IOWRDISOCI]. */
        uint64_t reserved_8            : 1;
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_l2c_cbcx_int_ena_w1s_t;

static inline uint64_t BDK_L2C_CBCX_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_INT_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e058060028ll + 0x1000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e058060028ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("L2C_CBCX_INT_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_L2C_CBCX_INT_ENA_W1S(a) bdk_l2c_cbcx_int_ena_w1s_t
#define bustype_BDK_L2C_CBCX_INT_ENA_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_INT_ENA_W1S(a) "L2C_CBCX_INT_ENA_W1S"
#define busnum_BDK_L2C_CBCX_INT_ENA_W1S(a) (a)
#define arguments_BDK_L2C_CBCX_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) l2c_cbc#_int_ena_w1c
 *
 * Level 2 Cache CBC Interrupt Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[IOWRDISOCI]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[IORDDISOCI]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[MIBDBE]. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[MIBSBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[RSDDBE]. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[RSDSBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[RSDSBE]. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[RSDDBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[MIBSBE]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[MIBDBE]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[IORDDISOCI]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[IOWRDISOCI]. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    struct bdk_l2c_cbcx_int_ena_w1c_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t gsyncto               : 1;  /**< [  8:  8](R/W1C/H) Added in pass 2.0. Reads or clears enable for L2C_CBC(0..1)_INT_W1C[GSYNCTO]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[IOWRDISOCI]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[IORDDISOCI]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[MIBDBE]. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[MIBSBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[RSDDBE]. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[RSDSBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[RSDSBE]. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[RSDDBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[MIBSBE]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[MIBDBE]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[IORDDISOCI]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for L2C_CBC(0..1)_INT_W1C[IOWRDISOCI]. */
        uint64_t gsyncto               : 1;  /**< [  8:  8](R/W1C/H) Added in pass 2.0. Reads or clears enable for L2C_CBC(0..1)_INT_W1C[GSYNCTO]. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } cn83xx;
    struct bdk_l2c_cbcx_int_ena_w1c_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t gsyncto               : 1;  /**< [  8:  8](R/W1C/H) Added in pass 2.0. Reads or clears enable for L2C_CBC(0..3)_INT_W1C[GSYNCTO]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[IOWRDISOCI]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[IORDDISOCI]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[MIBDBE]. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[MIBSBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[RSDDBE]. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[RSDSBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[RSDSBE]. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[RSDDBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[MIBSBE]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[MIBDBE]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[IORDDISOCI]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[IOWRDISOCI]. */
        uint64_t gsyncto               : 1;  /**< [  8:  8](R/W1C/H) Added in pass 2.0. Reads or clears enable for L2C_CBC(0..3)_INT_W1C[GSYNCTO]. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } cn88xxp2;
    struct bdk_l2c_cbcx_int_ena_w1c_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t reserved_8            : 1;
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[IOWRDISOCI]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[IORDDISOCI]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[MIBDBE]. */
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[MIBSBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[RSDDBE]. */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[RSDSBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rsdsbe                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[RSDSBE]. */
        uint64_t rsddbe                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[RSDDBE]. */
        uint64_t reserved_2_3          : 2;
        uint64_t mibsbe                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[MIBSBE]. */
        uint64_t mibdbe                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[MIBDBE]. */
        uint64_t iorddisoci            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[IORDDISOCI]. */
        uint64_t iowrdisoci            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for L2C_CBC(0..3)_INT_W1C[IOWRDISOCI]. */
        uint64_t reserved_8            : 1;
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_l2c_cbcx_int_ena_w1c_t;

static inline uint64_t BDK_L2C_CBCX_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_INT_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e058060020ll + 0x1000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e058060020ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("L2C_CBCX_INT_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_L2C_CBCX_INT_ENA_W1C(a) bdk_l2c_cbcx_int_ena_w1c_t
#define bustype_BDK_L2C_CBCX_INT_ENA_W1C(a) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_INT_ENA_W1C(a) "L2C_CBCX_INT_ENA_W1C"
#define busnum_BDK_L2C_CBCX_INT_ENA_W1C(a) (a)
#define arguments_BDK_L2C_CBCX_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL) l2c_cbc#_msix_vec#_ctl
 *
 * L2C_CBC MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the L2C_CBC_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_msix_vecx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_l2c_cbcx_msix_vecx_ctl_s cn; */
} bdk_l2c_cbcx_msix_vecx_ctl_t;

static inline uint64_t BDK_L2C_CBCX_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e058f00008ll + 0x1000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e058f00008ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0x0);
    __bdk_csr_fatal("L2C_CBCX_MSIX_VECX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_L2C_CBCX_MSIX_VECX_CTL(a,b) bdk_l2c_cbcx_msix_vecx_ctl_t
#define bustype_BDK_L2C_CBCX_MSIX_VECX_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_MSIX_VECX_CTL(a,b) "L2C_CBCX_MSIX_VECX_CTL"
#define busnum_BDK_L2C_CBCX_MSIX_VECX_CTL(a,b) (a)
#define arguments_BDK_L2C_CBCX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) l2c_cbc#_msix_pba#
 *
 * L2C_CBC MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the L2C_CBC_INT_VEC_E
 * enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO) Pending message for the associated L2C_CBC()_MSIX_VEC()_CTL, enumerated by
                                                                 L2C_CBC_INT_VEC_E. Bits
                                                                 that have no associated L2C_CBC_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO) Pending message for the associated L2C_CBC()_MSIX_VEC()_CTL, enumerated by
                                                                 L2C_CBC_INT_VEC_E. Bits
                                                                 that have no associated L2C_CBC_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_l2c_cbcx_msix_pbax_s cn; */
} bdk_l2c_cbcx_msix_pbax_t;

static inline uint64_t BDK_L2C_CBCX_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e058ff0000ll + 0x1000000ll * ((a) & 0x1) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e058ff0000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("L2C_CBCX_MSIX_PBAX", 2, a, b, 0, 0);
}

#define typedef_BDK_L2C_CBCX_MSIX_PBAX(a,b) bdk_l2c_cbcx_msix_pbax_t
#define bustype_BDK_L2C_CBCX_MSIX_PBAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_MSIX_PBAX(a,b) "L2C_CBCX_MSIX_PBAX"
#define busnum_BDK_L2C_CBCX_MSIX_PBAX(a,b) (a)
#define arguments_BDK_L2C_CBCX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) l2c_cbc#_xmc#_pfc
 *
 * Level 2 Cache ADD bus Performance Counter Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_xmcx_pfc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Current counter value. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Current counter value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_l2c_cbcx_xmcx_pfc_s cn; */
} bdk_l2c_cbcx_xmcx_pfc_t;

static inline uint64_t BDK_L2C_CBCX_XMCX_PFC(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_XMCX_PFC(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e058000000ll + 0x1000000ll * ((a) & 0x1) + 0x40ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e058000000ll + 0x1000000ll * ((a) & 0x3) + 0x40ll * ((b) & 0x3);
    __bdk_csr_fatal("L2C_CBCX_XMCX_PFC", 2, a, b, 0, 0);
}

#define typedef_BDK_L2C_CBCX_XMCX_PFC(a,b) bdk_l2c_cbcx_xmcx_pfc_t
#define bustype_BDK_L2C_CBCX_XMCX_PFC(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_XMCX_PFC(a,b) "L2C_CBCX_XMCX_PFC"
#define busnum_BDK_L2C_CBCX_XMCX_PFC(a,b) (a)
#define arguments_BDK_L2C_CBCX_XMCX_PFC(a,b) (a),(b),-1,-1

/**
 * Register (RSL) l2c_cbc#_ioc#_pfc
 *
 * Level 2 Cache IOC Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_iocx_pfc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Current counter value. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Current counter value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_l2c_cbcx_iocx_pfc_s cn; */
} bdk_l2c_cbcx_iocx_pfc_t;

static inline uint64_t BDK_L2C_CBCX_IOCX_PFC(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_IOCX_PFC(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e058000028ll + 0x1000000ll * ((a) & 0x1) + 0x40ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e058000028ll + 0x1000000ll * ((a) & 0x3) + 0x40ll * ((b) & 0x0);
    __bdk_csr_fatal("L2C_CBCX_IOCX_PFC", 2, a, b, 0, 0);
}

#define typedef_BDK_L2C_CBCX_IOCX_PFC(a,b) bdk_l2c_cbcx_iocx_pfc_t
#define bustype_BDK_L2C_CBCX_IOCX_PFC(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_IOCX_PFC(a,b) "L2C_CBCX_IOCX_PFC"
#define busnum_BDK_L2C_CBCX_IOCX_PFC(a,b) (a)
#define arguments_BDK_L2C_CBCX_IOCX_PFC(a,b) (a),(b),-1,-1

/**
 * Register (RSL) l2c_cbc#_ior#_pfc
 *
 * Level 2 Cache IOR Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_iorx_pfc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Current counter value. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Current counter value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_l2c_cbcx_iorx_pfc_s cn; */
} bdk_l2c_cbcx_iorx_pfc_t;

static inline uint64_t BDK_L2C_CBCX_IORX_PFC(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_IORX_PFC(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e058000030ll + 0x1000000ll * ((a) & 0x1) + 0x40ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e058000030ll + 0x1000000ll * ((a) & 0x3) + 0x40ll * ((b) & 0x0);
    __bdk_csr_fatal("L2C_CBCX_IORX_PFC", 2, a, b, 0, 0);
}

#define typedef_BDK_L2C_CBCX_IORX_PFC(a,b) bdk_l2c_cbcx_iorx_pfc_t
#define bustype_BDK_L2C_CBCX_IORX_PFC(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_IORX_PFC(a,b) "L2C_CBCX_IORX_PFC"
#define busnum_BDK_L2C_CBCX_IORX_PFC(a,b) (a)
#define arguments_BDK_L2C_CBCX_IORX_PFC(a,b) (a),(b),-1,-1

/**
 * Register (RSL) l2c_cbc#_rsd#_pfc
 *
 * Level 2 Cache FILL Bus Performance Counter Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_l2c_cbcx_rsdx_pfc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Current counter value. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Current counter value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_l2c_cbcx_rsdx_pfc_s cn; */
} bdk_l2c_cbcx_rsdx_pfc_t;

static inline uint64_t BDK_L2C_CBCX_RSDX_PFC(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_RSDX_PFC(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e058000018ll + 0x1000000ll * ((a) & 0x1) + 0x40ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e058000018ll + 0x1000000ll * ((a) & 0x3) + 0x40ll * ((b) & 0x3);
    __bdk_csr_fatal("L2C_CBCX_RSDX_PFC", 2, a, b, 0, 0);
}

#define typedef_BDK_L2C_CBCX_RSDX_PFC(a,b) bdk_l2c_cbcx_rsdx_pfc_t
#define bustype_BDK_L2C_CBCX_RSDX_PFC(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_L2C_CBCX_RSDX_PFC(a,b) "L2C_CBCX_RSDX_PFC"
#define busnum_BDK_L2C_CBCX_RSDX_PFC(a,b) (a)
#define arguments_BDK_L2C_CBCX_RSDX_PFC(a,b) (a),(b),-1,-1

#endif /* __BDK_CSRS_L2C_CBC_H__ */
