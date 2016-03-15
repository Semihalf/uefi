#ifndef __BDK_CSRS_CCU_H__
#define __BDK_CSRS_CCU_H__
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
 * Cavium CCU.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration ccu_bar_e
 *
 * CCU Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_CCU_BAR_E_CCU_PF_BAR0 (0x87e087000000ll) /**< Base address for standard registers. */

/**
 * Register (RSL) ccu_scratch
 *
 * INTERNAL: CCU General Purpose Scratch Register
 *
 * These registers are only reset by hardware during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union
{
    uint64_t u;
    struct bdk_ccu_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t scratch               : 8;  /**< [  7:  0](R/W) General purpose scratch register. */
#else /* Word 0 - Little Endian */
        uint64_t scratch               : 8;  /**< [  7:  0](R/W) General purpose scratch register. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ccu_scratch_s cn; */
} bdk_ccu_scratch_t;

#define BDK_CCU_SCRATCH BDK_CCU_SCRATCH_FUNC()
static inline uint64_t BDK_CCU_SCRATCH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CCU_SCRATCH_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e087100000ll;
    __bdk_csr_fatal("CCU_SCRATCH", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CCU_SCRATCH bdk_ccu_scratch_t
#define bustype_BDK_CCU_SCRATCH BDK_CSR_TYPE_RSL
#define basename_BDK_CCU_SCRATCH "CCU_SCRATCH"
#define device_bar_BDK_CCU_SCRATCH 0x0 /* PF_BAR0 */
#define busnum_BDK_CCU_SCRATCH 0
#define arguments_BDK_CCU_SCRATCH -1,-1,-1,-1

#endif /* __BDK_CSRS_CCU_H__ */
