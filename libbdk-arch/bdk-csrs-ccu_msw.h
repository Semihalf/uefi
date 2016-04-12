#ifndef __BDK_CSRS_CCU_MSW_H__
#define __BDK_CSRS_CCU_MSW_H__
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
 * Cavium CCU_MSW.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration ccu_msw_bar_e
 *
 * CCU_MSW Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_CCU_MSW_BAR_E_CCUX_MSW_PF_BAR0(a) (0x87e060000000ll + 0x1000000ll * (a))
#define BDK_CCU_MSW_BAR_E_CCUX_MSW_PF_BAR0_SIZE 0x800000ull

/**
 * Register (RSL) ccu#_msw_eco
 *
 * INTERNAL: CCU MSW ECO Register
 *
 * These registers exist to provide CSR flops in case they are needed for ECOs.
 */
typedef union
{
    uint64_t u;
    struct bdk_ccux_msw_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) ECO flops. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) ECO flops. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ccux_msw_eco_s cn; */
} bdk_ccux_msw_eco_t;

static inline uint64_t BDK_CCUX_MSW_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CCUX_MSW_ECO(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=8))
        return 0x87e060100008ll + 0x1000000ll * ((a) & 0xf);
    __bdk_csr_fatal("CCUX_MSW_ECO", 1, a, 0, 0, 0);
}

#define typedef_BDK_CCUX_MSW_ECO(a) bdk_ccux_msw_eco_t
#define bustype_BDK_CCUX_MSW_ECO(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CCUX_MSW_ECO(a) "CCUX_MSW_ECO"
#define device_bar_BDK_CCUX_MSW_ECO(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CCUX_MSW_ECO(a) (a)
#define arguments_BDK_CCUX_MSW_ECO(a) (a),-1,-1,-1

/**
 * Register (RSL) ccu#_msw_scratch
 *
 * INTERNAL: CCU MSW General Purpose Scratch Register
 *
 * These registers are only reset by hardware during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union
{
    uint64_t u;
    struct bdk_ccux_msw_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t scratch               : 8;  /**< [  7:  0](R/W) General purpose scratch register. */
#else /* Word 0 - Little Endian */
        uint64_t scratch               : 8;  /**< [  7:  0](R/W) General purpose scratch register. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ccux_msw_scratch_s cn; */
} bdk_ccux_msw_scratch_t;

static inline uint64_t BDK_CCUX_MSW_SCRATCH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CCUX_MSW_SCRATCH(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=8))
        return 0x87e060100000ll + 0x1000000ll * ((a) & 0xf);
    __bdk_csr_fatal("CCUX_MSW_SCRATCH", 1, a, 0, 0, 0);
}

#define typedef_BDK_CCUX_MSW_SCRATCH(a) bdk_ccux_msw_scratch_t
#define bustype_BDK_CCUX_MSW_SCRATCH(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CCUX_MSW_SCRATCH(a) "CCUX_MSW_SCRATCH"
#define device_bar_BDK_CCUX_MSW_SCRATCH(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CCUX_MSW_SCRATCH(a) (a)
#define arguments_BDK_CCUX_MSW_SCRATCH(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_CCU_MSW_H__ */
