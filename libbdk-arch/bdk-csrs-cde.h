#ifndef __BDK_CSRS_CDE_H__
#define __BDK_CSRS_CDE_H__
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
 * Cavium CDE.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration cde_bar_e
 *
 * CDE Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_CDE_BAR_E_CDEX_PF_BAR0(a) (0x80c000000000ll + 0x1000000000ll * (a)) /**< (0)Base address for physical function standard registers. */
#define BDK_CDE_BAR_E_CDEX_PF_BAR4(a) (0x80c010000000ll + 0x1000000000ll * (a)) /**< (0)Base address for physical function MSI-X registers. */
#define BDK_CDE_BAR_E_CDEX_VFX_BAR0(a,b) (0x80c020000000ll + 0x1000000000ll * (a) + 0x100000ll * (b)) /**< (0)(0..63)Base address for virtual function standard registers. */
#define BDK_CDE_BAR_E_CDEX_VFX_BAR4(a,b) (0x80c030000000ll + 0x1000000000ll * (a) + 0x100000ll * (b)) /**< (0)(0..63)Base address for virtual function MSI-X registers. */

/**
 * Enumeration cde_vf_int_vec_e
 *
 * CDE VF MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_CDE_VF_INT_VEC_E_DONE (1) /**< See interrupt clears CDE(0)_VQ(0..63)_DONE_INT_W1C,
                                       interrupt sets CDE(0)_VQ(0..63)_DONE_INT_W1S,
                                       enable clears CDE(0)_VQ(0..63)_DONE_ENA_W1C
                                       and enable sets CDE(0)_VQ(0..63)_DONE_ENA_W1S. */
#define BDK_CDE_VF_INT_VEC_E_MISC (0) /**< See interrupt clears CDE(0)_VQ(0..63)_MISC_INT,
                                       interrupt sets CDE(0)_VQ(0..63)_MISC_INT_W1S,
                                       enable clears CDE(0)_VQ(0..63)_MISC_ENA_W1C
                                       and enable sets CDE(0)_VQ(0..63)_MISC_ENA_W1S. */

/**
 * Enumeration cde_rams_e
 *
 * CDE RAM Field Enumeration
 * Enumerates the relative bit positions within CDE()_PF_ECC0_CTL[CDIS].
 */
#define BDK_CDE_RAMS_E_TBD (0) /**< Bit position for TBD. */

/**
 * Enumeration cde_pf_int_vec_e
 *
 * CDE PF MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_CDE_PF_INT_VEC_E_ECC0 (0) /**< See interrupt clears CDE(0)_PF_ECC0_INT,
                                       interrupt sets CDE(0)_PF_ECC0_INT_W1S,
                                       enable clears CDE(0)_PF_ECC0_ENA_W1C,
                                       and enable sets CDE(0)_PF_ECC0_ENA_W1S. */
#define BDK_CDE_PF_INT_VEC_E_MBOXX(a) (1 + (a)) /**< (0)See interrupt clears CDE(0)_PF_MBOX_INT(0),
                                       interrupt sets CDE(0)_PF_MBOX_INT_W1S(0),
                                       enable clears CDE(0)_PF_MBOX_ENA_W1C(0),
                                       and enable sets CDE(0)_PF_MBOX_ENA_W1S(0). */

/**
 * Structure cde_inst_s
 *
 * CDE Instruction Structure
 * Specifies the layout of the instruction.
 */
union bdk_cde_inst_s
{
    uint64_t u[8];
    struct bdk_cde_inst_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt. When DONEINT is set and the instruction completes,
                                                                 CDE()_VQ()_DONE[DONE] will be incremented. */
        uint64_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_15         : 16;
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt. When DONEINT is set and the instruction completes,
                                                                 CDE()_VQ()_DONE[DONE] will be incremented. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_113_127      : 15;
        uint64_t res_addr              : 49; /**< [112: 64] Result address.
                                                                 If non-zero, specifies where to write CDE_RES_S.
                                                                 If zero, no result structure will be written.
                                                                 Address must be 16-byte aligned. */
#else /* Word 1 - Little Endian */
        uint64_t res_addr              : 49; /**< [112: 64] Result address.
                                                                 If non-zero, specifies where to write CDE_RES_S.
                                                                 If zero, no result structure will be written.
                                                                 Address must be 16-byte aligned. */
        uint64_t reserved_113_127      : 15;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_172_191      : 20;
        uint64_t grp                   : 10; /**< [171:162] If [WQ_PTR] is non-zero, the SSO guest-group to use when CDE submits work to
                                                                 SSO. */
        uint64_t tt                    : 2;  /**< [161:160] If [WQ_PTR] is non-zero, the SSO tag type to use when CDE submits work to SSO. */
        uint64_t tag                   : 32; /**< [159:128] If [WQ_PTR] is non-zero, the SSO tag to use when CDE submits work to SSO. */
#else /* Word 2 - Little Endian */
        uint64_t tag                   : 32; /**< [159:128] If [WQ_PTR] is non-zero, the SSO tag to use when CDE submits work to SSO. */
        uint64_t tt                    : 2;  /**< [161:160] If [WQ_PTR] is non-zero, the SSO tag type to use when CDE submits work to SSO. */
        uint64_t grp                   : 10; /**< [171:162] If [WQ_PTR] is non-zero, the SSO guest-group to use when CDE submits work to
                                                                 SSO. */
        uint64_t reserved_172_191      : 20;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_241_255      : 15;
        uint64_t wq_ptr                : 49; /**< [240:192] If WQ_PTR is non-zero, it is a pointer to a work-queue entry that CDE submits
                                                                 work to SSO after all context, output data, and result write operations are
                                                                 visible to other CNXXXX units and the cores. */
#else /* Word 3 - Little Endian */
        uint64_t wq_ptr                : 49; /**< [240:192] If WQ_PTR is non-zero, it is a pointer to a work-queue entry that CDE submits
                                                                 work to SSO after all context, output data, and result write operations are
                                                                 visible to other CNXXXX units and the cores. */
        uint64_t reserved_241_255      : 15;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t ei0                   : 64; /**< [319:256] Defined by engines. */
#else /* Word 4 - Little Endian */
        uint64_t ei0                   : 64; /**< [319:256] Defined by engines. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t ei1                   : 64; /**< [383:320] Defined by engines. */
#else /* Word 5 - Little Endian */
        uint64_t ei1                   : 64; /**< [383:320] Defined by engines. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t ei2                   : 64; /**< [447:384] Defined by engines. */
#else /* Word 6 - Little Endian */
        uint64_t ei2                   : 64; /**< [447:384] Defined by engines. */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t ei3                   : 64; /**< [511:448] Defined by engines. */
#else /* Word 7 - Little Endian */
        uint64_t ei3                   : 64; /**< [511:448] Defined by engines. */
#endif /* Word 7 - End */
    } s;
    struct bdk_cde_inst_s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt. When DONEINT is set and the instruction completes,
                                                                 CDE()_VQ()_DONE[DONE] will be incremented. */
        uint64_t reserved_8_15         : 8;
        uint64_t reserved_0_7          : 8;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_7          : 8;
        uint64_t reserved_8_15         : 8;
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt. When DONEINT is set and the instruction completes,
                                                                 CDE()_VQ()_DONE[DONE] will be incremented. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_113_127      : 15;
        uint64_t res_addr              : 49; /**< [112: 64] Result address.
                                                                 If non-zero, specifies where to write CDE_RES_S.
                                                                 If zero, no result structure will be written.
                                                                 Address must be 16-byte aligned. */
#else /* Word 1 - Little Endian */
        uint64_t res_addr              : 49; /**< [112: 64] Result address.
                                                                 If non-zero, specifies where to write CDE_RES_S.
                                                                 If zero, no result structure will be written.
                                                                 Address must be 16-byte aligned. */
        uint64_t reserved_113_127      : 15;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_172_191      : 20;
        uint64_t grp                   : 10; /**< [171:162] If [WQ_PTR] is non-zero, the SSO guest-group to use when CDE submits work to
                                                                 SSO. */
        uint64_t tt                    : 2;  /**< [161:160] If [WQ_PTR] is non-zero, the SSO tag type to use when CDE submits work to SSO. */
        uint64_t tag                   : 32; /**< [159:128] If [WQ_PTR] is non-zero, the SSO tag to use when CDE submits work to SSO. */
#else /* Word 2 - Little Endian */
        uint64_t tag                   : 32; /**< [159:128] If [WQ_PTR] is non-zero, the SSO tag to use when CDE submits work to SSO. */
        uint64_t tt                    : 2;  /**< [161:160] If [WQ_PTR] is non-zero, the SSO tag type to use when CDE submits work to SSO. */
        uint64_t grp                   : 10; /**< [171:162] If [WQ_PTR] is non-zero, the SSO guest-group to use when CDE submits work to
                                                                 SSO. */
        uint64_t reserved_172_191      : 20;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_241_255      : 15;
        uint64_t wq_ptr                : 49; /**< [240:192] If WQ_PTR is non-zero, it is a pointer to a work-queue entry that CDE submits
                                                                 work to SSO after all context, output data, and result write operations are
                                                                 visible to other CNXXXX units and the cores. */
#else /* Word 3 - Little Endian */
        uint64_t wq_ptr                : 49; /**< [240:192] If WQ_PTR is non-zero, it is a pointer to a work-queue entry that CDE submits
                                                                 work to SSO after all context, output data, and result write operations are
                                                                 visible to other CNXXXX units and the cores. */
        uint64_t reserved_241_255      : 15;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t ei0                   : 64; /**< [319:256] Defined by engines. */
#else /* Word 4 - Little Endian */
        uint64_t ei0                   : 64; /**< [319:256] Defined by engines. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t ei1                   : 64; /**< [383:320] Defined by engines. */
#else /* Word 5 - Little Endian */
        uint64_t ei1                   : 64; /**< [383:320] Defined by engines. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t ei2                   : 64; /**< [447:384] Defined by engines. */
#else /* Word 6 - Little Endian */
        uint64_t ei2                   : 64; /**< [447:384] Defined by engines. */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t ei3                   : 64; /**< [511:448] Defined by engines. */
#else /* Word 7 - Little Endian */
        uint64_t ei3                   : 64; /**< [511:448] Defined by engines. */
#endif /* Word 7 - End */
    } cn;
};

/**
 * Structure cde_res_s
 *
 * CDE Result Structure
 * The CDE coprocessor writes the result structure after it completes a CDE_INST_S
 * instruction.
 * The result structure is exactly 16 (TBD) bytes, and each instruction completion
 * produces exactly one result structure.
 */
union bdk_cde_res_s
{
    uint64_t u[2];
    struct bdk_cde_res_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt. This bit is copied from the corrresponding instruction's
                                                                 CDE_INST_S[DONEINT]. */
        uint64_t reserved_8_15         : 8;
        uint64_t compcode              : 8;  /**< [  7:  0] Indicates completion/error status of the CDE coprocessor for the
                                                                 associated instruction, as enumerated by CDE_COMP_E. Core
                                                                 software may write the memory location containing [COMPCODE] to 0x0
                                                                 before ringing the doorbell, and then poll for completion by
                                                                 checking for a non-zero value.

                                                                 Once the core observes a non-zero [COMPCODE] value in this case, the CDE
                                                                 coprocessor will have also completed L2/DRAM write operations. */
#else /* Word 0 - Little Endian */
        uint64_t compcode              : 8;  /**< [  7:  0] Indicates completion/error status of the CDE coprocessor for the
                                                                 associated instruction, as enumerated by CDE_COMP_E. Core
                                                                 software may write the memory location containing [COMPCODE] to 0x0
                                                                 before ringing the doorbell, and then poll for completion by
                                                                 checking for a non-zero value.

                                                                 Once the core observes a non-zero [COMPCODE] value in this case, the CDE
                                                                 coprocessor will have also completed L2/DRAM write operations. */
        uint64_t reserved_8_15         : 8;
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt. This bit is copied from the corrresponding instruction's
                                                                 CDE_INST_S[DONEINT]. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_64_127       : 64;
#else /* Word 1 - Little Endian */
        uint64_t reserved_64_127       : 64;
#endif /* Word 1 - End */
    } s;
    /* struct bdk_cde_res_s_s cn; */
};

/**
 * Register (NCB) cde#_vq#_misc_int_w1s
 *
 * CDE Queue Misc Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vqx_misc_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CDE(0)_VQ(0..63)_MISC_INT[NWRP]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CDE(0)_VQ(0..63)_MISC_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CDE(0)_VQ(0..63)_MISC_INT[DOVF]. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CDE(0)_VQ(0..63)_MISC_INT[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CDE(0)_VQ(0..63)_MISC_INT[MBOX]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CDE(0)_VQ(0..63)_MISC_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CDE(0)_VQ(0..63)_MISC_INT[IRDE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CDE(0)_VQ(0..63)_MISC_INT[NWRP]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vqx_misc_int_w1s_s cn; */
} bdk_cdex_vqx_misc_int_w1s_t;

static inline uint64_t BDK_CDEX_VQX_MISC_INT_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VQX_MISC_INT_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020000508ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_VQX_MISC_INT_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_VQX_MISC_INT_W1S(a,b) bdk_cdex_vqx_misc_int_w1s_t
#define bustype_BDK_CDEX_VQX_MISC_INT_W1S(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VQX_MISC_INT_W1S(a,b) "CDEX_VQX_MISC_INT_W1S"
#define busnum_BDK_CDEX_VQX_MISC_INT_W1S(a,b) (a)
#define arguments_BDK_CDEX_VQX_MISC_INT_W1S(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_pf_mbox_ena_w1c#
 *
 * CDE PF Mailbox Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_mbox_ena_w1cx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for CDE(0)_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for CDE(0)_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_mbox_ena_w1cx_s cn; */
} bdk_cdex_pf_mbox_ena_w1cx_t;

static inline uint64_t BDK_CDEX_PF_MBOX_ENA_W1CX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_MBOX_ENA_W1CX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000000440ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("CDEX_PF_MBOX_ENA_W1CX", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_PF_MBOX_ENA_W1CX(a,b) bdk_cdex_pf_mbox_ena_w1cx_t
#define bustype_BDK_CDEX_PF_MBOX_ENA_W1CX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_MBOX_ENA_W1CX(a,b) "CDEX_PF_MBOX_ENA_W1CX"
#define busnum_BDK_CDEX_PF_MBOX_ENA_W1CX(a,b) (a)
#define arguments_BDK_CDEX_PF_MBOX_ENA_W1CX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_vq#_done_wait
 *
 * CDE Queue Done Interrupt Coalescing Wait Registers
 * Specifies the per queue interrupt coalescing settings.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vqx_done_wait_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t time_wait             : 16; /**< [ 47: 32](R/W) Time hold-off. When CDE()_VQ()_DONE[DONE] = 0, or CDE()_VQ()_DONE_ACK is written
                                                                 a timer is cleared. When the timer reaches [TIME_WAIT]*1024 then interrupt
                                                                 coalescing ends; see CDE()_VQ()_DONE[DONE]. If 0x0, time coalescing is disabled. */
        uint64_t reserved_20_31        : 12;
        uint64_t num_wait              : 20; /**< [ 19:  0](R/W) Number of messages hold-off. When CDE()_VQ()_DONE[DONE] >= [NUM_WAIT] then
                                                                 interrupt coalescing ends; see CDE()_VQ()_DONE[DONE]. If 0x0, same behavior as
                                                                 0x1. */
#else /* Word 0 - Little Endian */
        uint64_t num_wait              : 20; /**< [ 19:  0](R/W) Number of messages hold-off. When CDE()_VQ()_DONE[DONE] >= [NUM_WAIT] then
                                                                 interrupt coalescing ends; see CDE()_VQ()_DONE[DONE]. If 0x0, same behavior as
                                                                 0x1. */
        uint64_t reserved_20_31        : 12;
        uint64_t time_wait             : 16; /**< [ 47: 32](R/W) Time hold-off. When CDE()_VQ()_DONE[DONE] = 0, or CDE()_VQ()_DONE_ACK is written
                                                                 a timer is cleared. When the timer reaches [TIME_WAIT]*1024 then interrupt
                                                                 coalescing ends; see CDE()_VQ()_DONE[DONE]. If 0x0, time coalescing is disabled. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vqx_done_wait_s cn; */
} bdk_cdex_vqx_done_wait_t;

static inline uint64_t BDK_CDEX_VQX_DONE_WAIT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VQX_DONE_WAIT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020000400ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_VQX_DONE_WAIT", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_VQX_DONE_WAIT(a,b) bdk_cdex_vqx_done_wait_t
#define bustype_BDK_CDEX_VQX_DONE_WAIT(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VQX_DONE_WAIT(a,b) "CDEX_VQX_DONE_WAIT"
#define busnum_BDK_CDEX_VQX_DONE_WAIT(a,b) (a)
#define arguments_BDK_CDEX_VQX_DONE_WAIT(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_pf_vf#_mbox#
 *
 * CDE PF/VF Mailbox Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_vfx_mboxx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These PF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. Each corresponding VF may access the same storage using
                                                                 CDE()_VF()_PF_MBOX(). MBOX(0) is typically used for PF to VF signaling, MBOX(1)
                                                                 for VF to PF. Writing CDE(0)_PF_VF(0..63)_MBOX(0) (but not
                                                                 CDE(0)_VF(0..63)_PF_MBOX(0)) will set the corresponding
                                                                 CDE()_VF()_MISC_INT[MBOX] which if appropriately enabled will send an interrupt
                                                                 to the VF. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These PF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. Each corresponding VF may access the same storage using
                                                                 CDE()_VF()_PF_MBOX(). MBOX(0) is typically used for PF to VF signaling, MBOX(1)
                                                                 for VF to PF. Writing CDE(0)_PF_VF(0..63)_MBOX(0) (but not
                                                                 CDE(0)_VF(0..63)_PF_MBOX(0)) will set the corresponding
                                                                 CDE()_VF()_MISC_INT[MBOX] which if appropriately enabled will send an interrupt
                                                                 to the VF. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_vfx_mboxx_s cn; */
} bdk_cdex_pf_vfx_mboxx_t;

static inline uint64_t BDK_CDEX_PF_VFX_MBOXX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_VFX_MBOXX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c008001000ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f) + 0x100ll * ((c) & 0x1);
    __bdk_csr_fatal("CDEX_PF_VFX_MBOXX", 3, a, b, c, 0);
}

#define typedef_BDK_CDEX_PF_VFX_MBOXX(a,b,c) bdk_cdex_pf_vfx_mboxx_t
#define bustype_BDK_CDEX_PF_VFX_MBOXX(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_VFX_MBOXX(a,b,c) "CDEX_PF_VFX_MBOXX"
#define busnum_BDK_CDEX_PF_VFX_MBOXX(a,b,c) (a)
#define arguments_BDK_CDEX_PF_VFX_MBOXX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) cde#_pf_rd_req_pc
 *
 * CDE PF Read Request Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_rd_req_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of L2C read requests. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of L2C read requests. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_rd_req_pc_s cn; */
} bdk_cdex_pf_rd_req_pc_t;

static inline uint64_t BDK_CDEX_PF_RD_REQ_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_RD_REQ_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000010040ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("CDEX_PF_RD_REQ_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_CDEX_PF_RD_REQ_PC(a) bdk_cdex_pf_rd_req_pc_t
#define bustype_BDK_CDEX_PF_RD_REQ_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_RD_REQ_PC(a) "CDEX_PF_RD_REQ_PC"
#define busnum_BDK_CDEX_PF_RD_REQ_PC(a) (a)
#define arguments_BDK_CDEX_PF_RD_REQ_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) cde#_vq#_done
 *
 * CDE Queue Done Count Registers
 * These registers contain the per-queue instruction done count.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vqx_done_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t done                  : 20; /**< [ 19:  0](R/W/H) Done count. When CDE_INST_S[DONEINT] set and that instruction completes,
                                                                 CDE()_VQ()_DONE[DONE] is incremented when the instruction finishes. Write to
                                                                 this field are for diagnostic use only; instead software writes
                                                                 CDE()_VQ()_DONE_ACK with the number of decrements for this field.

                                                                 Interrupts are sent as follows:

                                                                 * When CDE()_VQ()_DONE[DONE] = 0, then no results are pending, the interrupt
                                                                 coalescing timer is held to zero, and an interrupt is not sent.

                                                                 * When CDE()_VQ()_DONE[DONE] != 0, then the interrupt coalescing timer
                                                                 counts. If the counter is >= CDE()_VQ()_DONE_WAIT[TIME_WAIT]*1024, or
                                                                 CDE()_VQ()_DONE[DONE] >= CDE()_VQ()_DONE_WAIT[NUM_WAIT], i.e.enough time has
                                                                 passed or enough results have arrived, then the interrupt is sent.  Otherwise,
                                                                 it is not sent due to coalescing.

                                                                 * When CDE()_VQ()_DONE_ACK is written, the interrupt coalescing timer restarts.
                                                                 Note after decrementing this interrupt equation is recomputed, for example if
                                                                 CDE()_VQ()_DONE[DONE] >= CDE()_VQ()_DONE_WAIT[NUM_WAIT] and the timer is zero,
                                                                 the interrupt will be resent immediately.  (This covers the race case between
                                                                 software acknowledging an interrupt and a result returning.)

                                                                 * When CDE()_VQ()_DONE_ENA_W1S[DONE] = 0, interrupts are not sent, but the
                                                                 counting described above still occurs.

                                                                 Since CDE instructions complete out-of-order, if software is using completion
                                                                 interrupts the suggested scheme is to request a DONEINT on each request, and
                                                                 when an interrupt arrives perform a "greedy" scan for completions; even if a
                                                                 later command is acknowledged first this will not result in missing a
                                                                 completion. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 20; /**< [ 19:  0](R/W/H) Done count. When CDE_INST_S[DONEINT] set and that instruction completes,
                                                                 CDE()_VQ()_DONE[DONE] is incremented when the instruction finishes. Write to
                                                                 this field are for diagnostic use only; instead software writes
                                                                 CDE()_VQ()_DONE_ACK with the number of decrements for this field.

                                                                 Interrupts are sent as follows:

                                                                 * When CDE()_VQ()_DONE[DONE] = 0, then no results are pending, the interrupt
                                                                 coalescing timer is held to zero, and an interrupt is not sent.

                                                                 * When CDE()_VQ()_DONE[DONE] != 0, then the interrupt coalescing timer
                                                                 counts. If the counter is >= CDE()_VQ()_DONE_WAIT[TIME_WAIT]*1024, or
                                                                 CDE()_VQ()_DONE[DONE] >= CDE()_VQ()_DONE_WAIT[NUM_WAIT], i.e.enough time has
                                                                 passed or enough results have arrived, then the interrupt is sent.  Otherwise,
                                                                 it is not sent due to coalescing.

                                                                 * When CDE()_VQ()_DONE_ACK is written, the interrupt coalescing timer restarts.
                                                                 Note after decrementing this interrupt equation is recomputed, for example if
                                                                 CDE()_VQ()_DONE[DONE] >= CDE()_VQ()_DONE_WAIT[NUM_WAIT] and the timer is zero,
                                                                 the interrupt will be resent immediately.  (This covers the race case between
                                                                 software acknowledging an interrupt and a result returning.)

                                                                 * When CDE()_VQ()_DONE_ENA_W1S[DONE] = 0, interrupts are not sent, but the
                                                                 counting described above still occurs.

                                                                 Since CDE instructions complete out-of-order, if software is using completion
                                                                 interrupts the suggested scheme is to request a DONEINT on each request, and
                                                                 when an interrupt arrives perform a "greedy" scan for completions; even if a
                                                                 later command is acknowledged first this will not result in missing a
                                                                 completion. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vqx_done_s cn; */
} bdk_cdex_vqx_done_t;

static inline uint64_t BDK_CDEX_VQX_DONE(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VQX_DONE(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020000420ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_VQX_DONE", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_VQX_DONE(a,b) bdk_cdex_vqx_done_t
#define bustype_BDK_CDEX_VQX_DONE(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VQX_DONE(a,b) "CDEX_VQX_DONE"
#define busnum_BDK_CDEX_VQX_DONE(a,b) (a)
#define arguments_BDK_CDEX_VQX_DONE(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_pf_msix_pba#
 *
 * CDE PF MSI-X Pending-Bit-Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the
 * CDE_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated CDE()_PF_MSIX_VEC()_CTL, enumerated by
                                                                 CDE_PF_INT_VEC_E. Bits that have no associated CDE_PF_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated CDE()_PF_MSIX_VEC()_CTL, enumerated by
                                                                 CDE_PF_INT_VEC_E. Bits that have no associated CDE_PF_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_msix_pbax_s cn; */
} bdk_cdex_pf_msix_pbax_t;

static inline uint64_t BDK_CDEX_PF_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c0100f0000ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("CDEX_PF_MSIX_PBAX", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_PF_MSIX_PBAX(a,b) bdk_cdex_pf_msix_pbax_t
#define bustype_BDK_CDEX_PF_MSIX_PBAX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_MSIX_PBAX(a,b) "CDEX_PF_MSIX_PBAX"
#define busnum_BDK_CDEX_PF_MSIX_PBAX(a,b) (a)
#define arguments_BDK_CDEX_PF_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_pf_diag
 *
 * CDE PF Diagnostic Control Register
 * This register controls diagnostic features.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_diag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t forceclk              : 1;  /**< [  8:  8](R/W) When this bit is set to 1, it forces CDE clocks on. For diagnostic use only. */
        uint64_t ld_infl               : 8;  /**< [  7:  0](R/W) Maximum number of in-flight data fetch transactions on the NCB. Larger values
                                                                 may improve CDE performance but may starve other devices on the same NCB. Values
                                                                 > 32 are treated as 32. */
#else /* Word 0 - Little Endian */
        uint64_t ld_infl               : 8;  /**< [  7:  0](R/W) Maximum number of in-flight data fetch transactions on the NCB. Larger values
                                                                 may improve CDE performance but may starve other devices on the same NCB. Values
                                                                 > 32 are treated as 32. */
        uint64_t forceclk              : 1;  /**< [  8:  8](R/W) When this bit is set to 1, it forces CDE clocks on. For diagnostic use only. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_diag_s cn; */
} bdk_cdex_pf_diag_t;

static inline uint64_t BDK_CDEX_PF_DIAG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_DIAG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000000120ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("CDEX_PF_DIAG", 1, a, 0, 0, 0);
}

#define typedef_BDK_CDEX_PF_DIAG(a) bdk_cdex_pf_diag_t
#define bustype_BDK_CDEX_PF_DIAG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_DIAG(a) "CDEX_PF_DIAG"
#define busnum_BDK_CDEX_PF_DIAG(a) (a)
#define arguments_BDK_CDEX_PF_DIAG(a) (a),-1,-1,-1

/**
 * Register (NCB) cde#_pf_ecc0_ena_w1s
 *
 * CDE ECC Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_ecc0_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets enable for CDE(0)_PF_ECC0_INT[DBE]. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets enable for CDE(0)_PF_ECC0_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets enable for CDE(0)_PF_ECC0_INT[SBE]. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets enable for CDE(0)_PF_ECC0_INT[DBE]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_ecc0_ena_w1s_s cn; */
} bdk_cdex_pf_ecc0_ena_w1s_t;

static inline uint64_t BDK_CDEX_PF_ECC0_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_ECC0_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000000240ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("CDEX_PF_ECC0_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_CDEX_PF_ECC0_ENA_W1S(a) bdk_cdex_pf_ecc0_ena_w1s_t
#define bustype_BDK_CDEX_PF_ECC0_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_ECC0_ENA_W1S(a) "CDEX_PF_ECC0_ENA_W1S"
#define busnum_BDK_CDEX_PF_ECC0_ENA_W1S(a) (a)
#define arguments_BDK_CDEX_PF_ECC0_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) cde#_pf_ecc0_ena_w1c
 *
 * CDE ECC Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_ecc0_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1C/H) Reads or clears enable for CDE(0)_PF_ECC0_INT[DBE]. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1C/H) Reads or clears enable for CDE(0)_PF_ECC0_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1C/H) Reads or clears enable for CDE(0)_PF_ECC0_INT[SBE]. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1C/H) Reads or clears enable for CDE(0)_PF_ECC0_INT[DBE]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_ecc0_ena_w1c_s cn; */
} bdk_cdex_pf_ecc0_ena_w1c_t;

static inline uint64_t BDK_CDEX_PF_ECC0_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_ECC0_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000000250ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("CDEX_PF_ECC0_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_CDEX_PF_ECC0_ENA_W1C(a) bdk_cdex_pf_ecc0_ena_w1c_t
#define bustype_BDK_CDEX_PF_ECC0_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_ECC0_ENA_W1C(a) "CDEX_PF_ECC0_ENA_W1C"
#define busnum_BDK_CDEX_PF_ECC0_ENA_W1C(a) (a)
#define arguments_BDK_CDEX_PF_ECC0_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) cde#_vf#_pf_mbox#
 *
 * CDE VF/PF Mailbox Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vfx_pf_mboxx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These VF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. The PF may access the same storage using CDE()_PF_VF()_MBOX(). MBOX(0) is
                                                                 typically used for PF to VF signaling, MBOX(1) for VF to PF. Writing
                                                                 CDE(0)_VF(0..63)_PF_MBOX(1) (but not CDE(0)_PF_VF(0..63)_MBOX(1)) will set the
                                                                 corresponding CDE()_PF_MBOX_INT() bit, which if appropriately enabled will send an
                                                                 interrupt to the PF. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These VF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. The PF may access the same storage using CDE()_PF_VF()_MBOX(). MBOX(0) is
                                                                 typically used for PF to VF signaling, MBOX(1) for VF to PF. Writing
                                                                 CDE(0)_VF(0..63)_PF_MBOX(1) (but not CDE(0)_PF_VF(0..63)_MBOX(1)) will set the
                                                                 corresponding CDE()_PF_MBOX_INT() bit, which if appropriately enabled will send an
                                                                 interrupt to the PF. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vfx_pf_mboxx_s cn; */
} bdk_cdex_vfx_pf_mboxx_t;

static inline uint64_t BDK_CDEX_VFX_PF_MBOXX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VFX_PF_MBOXX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020001000ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f) + 8ll * ((c) & 0x1);
    __bdk_csr_fatal("CDEX_VFX_PF_MBOXX", 3, a, b, c, 0);
}

#define typedef_BDK_CDEX_VFX_PF_MBOXX(a,b,c) bdk_cdex_vfx_pf_mboxx_t
#define bustype_BDK_CDEX_VFX_PF_MBOXX(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VFX_PF_MBOXX(a,b,c) "CDEX_VFX_PF_MBOXX"
#define busnum_BDK_CDEX_VFX_PF_MBOXX(a,b,c) (a)
#define arguments_BDK_CDEX_VFX_PF_MBOXX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) cde#_pf_mbox_ena_w1s#
 *
 * CDE PF Mailbox Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_mbox_ena_w1sx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for CDE(0)_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for CDE(0)_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_mbox_ena_w1sx_s cn; */
} bdk_cdex_pf_mbox_ena_w1sx_t;

static inline uint64_t BDK_CDEX_PF_MBOX_ENA_W1SX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_MBOX_ENA_W1SX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000000460ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("CDEX_PF_MBOX_ENA_W1SX", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_PF_MBOX_ENA_W1SX(a,b) bdk_cdex_pf_mbox_ena_w1sx_t
#define bustype_BDK_CDEX_PF_MBOX_ENA_W1SX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_MBOX_ENA_W1SX(a,b) "CDEX_PF_MBOX_ENA_W1SX"
#define busnum_BDK_CDEX_PF_MBOX_ENA_W1SX(a,b) (a)
#define arguments_BDK_CDEX_PF_MBOX_ENA_W1SX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_pf_mbox_int_w1s#
 *
 * CDE PF Mailbox Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_mbox_int_w1sx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets CDE(0)_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets CDE(0)_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_mbox_int_w1sx_s cn; */
} bdk_cdex_pf_mbox_int_w1sx_t;

static inline uint64_t BDK_CDEX_PF_MBOX_INT_W1SX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_MBOX_INT_W1SX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000000420ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("CDEX_PF_MBOX_INT_W1SX", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_PF_MBOX_INT_W1SX(a,b) bdk_cdex_pf_mbox_int_w1sx_t
#define bustype_BDK_CDEX_PF_MBOX_INT_W1SX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_MBOX_INT_W1SX(a,b) "CDEX_PF_MBOX_INT_W1SX"
#define busnum_BDK_CDEX_PF_MBOX_INT_W1SX(a,b) (a)
#define arguments_BDK_CDEX_PF_MBOX_INT_W1SX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_pf_ecc0_flip
 *
 * CDE PF ECC Flip Syndrome Register
 * This register enables ECC for each individual internal memory that requires ECC. For debug
 * purposes, it can also flip one or two bits in the ECC data.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_ecc0_flip_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t flip1                 : 32; /**< [ 63: 32](R/W) Flips syndome bit 1 on writes.  Bit positions enumerated with CDE_RAMS_E. */
        uint64_t flip0                 : 32; /**< [ 31:  0](R/W) Flips syndome bit 0 on writes.  Bit positions enumerated with CDE_RAMS_E. */
#else /* Word 0 - Little Endian */
        uint64_t flip0                 : 32; /**< [ 31:  0](R/W) Flips syndome bit 0 on writes.  Bit positions enumerated with CDE_RAMS_E. */
        uint64_t flip1                 : 32; /**< [ 63: 32](R/W) Flips syndome bit 1 on writes.  Bit positions enumerated with CDE_RAMS_E. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_ecc0_flip_s cn; */
} bdk_cdex_pf_ecc0_flip_t;

static inline uint64_t BDK_CDEX_PF_ECC0_FLIP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_ECC0_FLIP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000000210ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("CDEX_PF_ECC0_FLIP", 1, a, 0, 0, 0);
}

#define typedef_BDK_CDEX_PF_ECC0_FLIP(a) bdk_cdex_pf_ecc0_flip_t
#define bustype_BDK_CDEX_PF_ECC0_FLIP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_ECC0_FLIP(a) "CDEX_PF_ECC0_FLIP"
#define busnum_BDK_CDEX_PF_ECC0_FLIP(a) (a)
#define arguments_BDK_CDEX_PF_ECC0_FLIP(a) (a),-1,-1,-1

/**
 * Register (NCB) cde#_pf_mbox_int#
 *
 * CDE PF Mailbox Interrupt Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_mbox_intx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) One interrupt bit per VF. Each bit is set when the associated
                                                                 CDE_VF(0..63)_PF_MBOX(1) is written. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) One interrupt bit per VF. Each bit is set when the associated
                                                                 CDE_VF(0..63)_PF_MBOX(1) is written. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_mbox_intx_s cn; */
} bdk_cdex_pf_mbox_intx_t;

static inline uint64_t BDK_CDEX_PF_MBOX_INTX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_MBOX_INTX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000000400ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("CDEX_PF_MBOX_INTX", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_PF_MBOX_INTX(a,b) bdk_cdex_pf_mbox_intx_t
#define bustype_BDK_CDEX_PF_MBOX_INTX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_MBOX_INTX(a,b) "CDEX_PF_MBOX_INTX"
#define busnum_BDK_CDEX_PF_MBOX_INTX(a,b) (a)
#define arguments_BDK_CDEX_PF_MBOX_INTX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_pf_eco
 *
 * INTERNAL: CDE PF ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) INTERNAL: Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) INTERNAL: Reserved for ECO usage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_eco_s cn; */
} bdk_cdex_pf_eco_t;

static inline uint64_t BDK_CDEX_PF_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_ECO(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000000140ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("CDEX_PF_ECO", 1, a, 0, 0, 0);
}

#define typedef_BDK_CDEX_PF_ECO(a) bdk_cdex_pf_eco_t
#define bustype_BDK_CDEX_PF_ECO(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_ECO(a) "CDEX_PF_ECO"
#define busnum_BDK_CDEX_PF_ECO(a) (a)
#define arguments_BDK_CDEX_PF_ECO(a) (a),-1,-1,-1

/**
 * Register (NCB) cde#_pf_ecc0_int_w1s
 *
 * CDE ECC Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_ecc0_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets CDE(0)_PF_ECC0_INT[DBE]. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets CDE(0)_PF_ECC0_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets CDE(0)_PF_ECC0_INT[SBE]. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets CDE(0)_PF_ECC0_INT[DBE]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_ecc0_int_w1s_s cn; */
} bdk_cdex_pf_ecc0_int_w1s_t;

static inline uint64_t BDK_CDEX_PF_ECC0_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_ECC0_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000000230ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("CDEX_PF_ECC0_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_CDEX_PF_ECC0_INT_W1S(a) bdk_cdex_pf_ecc0_int_w1s_t
#define bustype_BDK_CDEX_PF_ECC0_INT_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_ECC0_INT_W1S(a) "CDEX_PF_ECC0_INT_W1S"
#define busnum_BDK_CDEX_PF_ECC0_INT_W1S(a) (a)
#define arguments_BDK_CDEX_PF_ECC0_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) cde#_vq#_done_ack
 *
 * CDE Queue Done Count Ack Registers
 * This register is written by software to acknowledge interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vqx_done_ack_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t done_ack              : 20; /**< [ 19:  0](R/W/H) Number of decrements to CDE()_VQ()_DONE[DONE]. Reads CDE()_VQ()_DONE[DONE].

                                                                 Written by software to acknowledge interrupts. If CDE()_VQ()_DONE[DONE] is still
                                                                 non-zero the interrupt will be re-sent if the conditions described in
                                                                 CDE()_VQ()_DONE[DONE] are satisfied. */
#else /* Word 0 - Little Endian */
        uint64_t done_ack              : 20; /**< [ 19:  0](R/W/H) Number of decrements to CDE()_VQ()_DONE[DONE]. Reads CDE()_VQ()_DONE[DONE].

                                                                 Written by software to acknowledge interrupts. If CDE()_VQ()_DONE[DONE] is still
                                                                 non-zero the interrupt will be re-sent if the conditions described in
                                                                 CDE()_VQ()_DONE[DONE] are satisfied. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vqx_done_ack_s cn; */
} bdk_cdex_vqx_done_ack_t;

static inline uint64_t BDK_CDEX_VQX_DONE_ACK(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VQX_DONE_ACK(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020000440ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_VQX_DONE_ACK", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_VQX_DONE_ACK(a,b) bdk_cdex_vqx_done_ack_t
#define bustype_BDK_CDEX_VQX_DONE_ACK(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VQX_DONE_ACK(a,b) "CDEX_VQX_DONE_ACK"
#define busnum_BDK_CDEX_VQX_DONE_ACK(a,b) (a)
#define arguments_BDK_CDEX_VQX_DONE_ACK(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_vq#_saddr
 *
 * CDE Queue Starting Buffer Address Registers
 * These registers set the instruction buffer starting address.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vqx_saddr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t ptr                   : 43; /**< [ 48:  6](R/W/H) Instruction buffer pointer bits <48:6> (64-byte aligned). When written, it is the initial
                                                                 buffer starting address; when read, it is the next read pointer to be requested from L2C.
                                                                 The PTR field is overwritten with the next pointer each time that the command buffer
                                                                 segment is exhausted. New commands will then be read from the newly specified command
                                                                 buffer pointer.

                                                                 CPT: 64-byte aligned.

                                                                 DDF: 128-byte aligned. */
        uint64_t reserved_0_5          : 6;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_5          : 6;
        uint64_t ptr                   : 43; /**< [ 48:  6](R/W/H) Instruction buffer pointer bits <48:6> (64-byte aligned). When written, it is the initial
                                                                 buffer starting address; when read, it is the next read pointer to be requested from L2C.
                                                                 The PTR field is overwritten with the next pointer each time that the command buffer
                                                                 segment is exhausted. New commands will then be read from the newly specified command
                                                                 buffer pointer.

                                                                 CPT: 64-byte aligned.

                                                                 DDF: 128-byte aligned. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vqx_saddr_s cn; */
} bdk_cdex_vqx_saddr_t;

static inline uint64_t BDK_CDEX_VQX_SADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VQX_SADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020000200ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_VQX_SADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_VQX_SADDR(a,b) bdk_cdex_vqx_saddr_t
#define bustype_BDK_CDEX_VQX_SADDR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VQX_SADDR(a,b) "CDEX_VQX_SADDR"
#define busnum_BDK_CDEX_VQX_SADDR(a,b) (a)
#define arguments_BDK_CDEX_VQX_SADDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_pf_msix_vec#_ctl
 *
 * CDE PF MSI-X Vector-Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the CDE_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_msix_vecx_ctl_s
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
    /* struct bdk_cdex_pf_msix_vecx_ctl_s cn; */
} bdk_cdex_pf_msix_vecx_ctl_t;

static inline uint64_t BDK_CDEX_PF_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c010000008ll + 0x1000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x1);
    __bdk_csr_fatal("CDEX_PF_MSIX_VECX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_PF_MSIX_VECX_CTL(a,b) bdk_cdex_pf_msix_vecx_ctl_t
#define bustype_BDK_CDEX_PF_MSIX_VECX_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_MSIX_VECX_CTL(a,b) "CDEX_PF_MSIX_VECX_CTL"
#define busnum_BDK_CDEX_PF_MSIX_VECX_CTL(a,b) (a)
#define arguments_BDK_CDEX_PF_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_pf_msix_vec#_addr
 *
 * CDE PF MSI-X Vector-Table Address Registers
 * This register is the MSI-X vector table, indexed by the CDE_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's CDE()_PF_MSIX_VEC()_ADDR, CDE()_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of CDE()_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_CDE_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's CDE()_PF_MSIX_VEC()_ADDR, CDE()_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of CDE()_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_CDE_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_msix_vecx_addr_s cn; */
} bdk_cdex_pf_msix_vecx_addr_t;

static inline uint64_t BDK_CDEX_PF_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c010000000ll + 0x1000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x1);
    __bdk_csr_fatal("CDEX_PF_MSIX_VECX_ADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_PF_MSIX_VECX_ADDR(a,b) bdk_cdex_pf_msix_vecx_addr_t
#define bustype_BDK_CDEX_PF_MSIX_VECX_ADDR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_MSIX_VECX_ADDR(a,b) "CDEX_PF_MSIX_VECX_ADDR"
#define busnum_BDK_CDEX_PF_MSIX_VECX_ADDR(a,b) (a)
#define arguments_BDK_CDEX_PF_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_pf_bist_status
 *
 * CDE PF Control Bist Status Register
 * This register has the BIST status of memories. Each bit is the BIST result of an
 * individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t bstatus               : 32; /**< [ 31:  0](RO/H) BIST status. One bit per memory, enumerated by CDE_RAMS_E. */
#else /* Word 0 - Little Endian */
        uint64_t bstatus               : 32; /**< [ 31:  0](RO/H) BIST status. One bit per memory, enumerated by CDE_RAMS_E. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_bist_status_s cn; */
} bdk_cdex_pf_bist_status_t;

static inline uint64_t BDK_CDEX_PF_BIST_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_BIST_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000000160ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("CDEX_PF_BIST_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_CDEX_PF_BIST_STATUS(a) bdk_cdex_pf_bist_status_t
#define bustype_BDK_CDEX_PF_BIST_STATUS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_BIST_STATUS(a) "CDEX_PF_BIST_STATUS"
#define busnum_BDK_CDEX_PF_BIST_STATUS(a) (a)
#define arguments_BDK_CDEX_PF_BIST_STATUS(a) (a),-1,-1,-1

/**
 * Register (NCB) cde#_pf_inst_req_pc
 *
 * CDE PF Instruction Request Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_inst_req_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of instructions that have started processing. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of instructions that have started processing. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_inst_req_pc_s cn; */
} bdk_cdex_pf_inst_req_pc_t;

static inline uint64_t BDK_CDEX_PF_INST_REQ_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_INST_REQ_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000010000ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("CDEX_PF_INST_REQ_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_CDEX_PF_INST_REQ_PC(a) bdk_cdex_pf_inst_req_pc_t
#define bustype_BDK_CDEX_PF_INST_REQ_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_INST_REQ_PC(a) "CDEX_PF_INST_REQ_PC"
#define busnum_BDK_CDEX_PF_INST_REQ_PC(a) (a)
#define arguments_BDK_CDEX_PF_INST_REQ_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) cde#_pf_rd_latency_pc
 *
 * CDE PF Read Latency Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_rd_latency_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for L2C read returns. Incremented every
                                                                 coprocessor-clock by the number of transactions outstanding in that cycle. This
                                                                 may be divided by CDE()_PF_RD_REQ_PC to determine the average read latency. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for L2C read returns. Incremented every
                                                                 coprocessor-clock by the number of transactions outstanding in that cycle. This
                                                                 may be divided by CDE()_PF_RD_REQ_PC to determine the average read latency. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_rd_latency_pc_s cn; */
} bdk_cdex_pf_rd_latency_pc_t;

static inline uint64_t BDK_CDEX_PF_RD_LATENCY_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_RD_LATENCY_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000010060ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("CDEX_PF_RD_LATENCY_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_CDEX_PF_RD_LATENCY_PC(a) bdk_cdex_pf_rd_latency_pc_t
#define bustype_BDK_CDEX_PF_RD_LATENCY_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_RD_LATENCY_PC(a) "CDEX_PF_RD_LATENCY_PC"
#define busnum_BDK_CDEX_PF_RD_LATENCY_PC(a) (a)
#define arguments_BDK_CDEX_PF_RD_LATENCY_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) cde#_pf_ecc0_ctl
 *
 * CDE PF ECC Control Register
 * This register enables ECC for each individual internal memory that requires ECC. For debug
 * purposes, it can also flip one or two bits in the ECC data.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_ecc0_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t cdis                  : 32; /**< [ 31:  0](R/W) Disables ECC correction on each RAM.  Bit positions enumerated with CDE_RAMS_E. */
#else /* Word 0 - Little Endian */
        uint64_t cdis                  : 32; /**< [ 31:  0](R/W) Disables ECC correction on each RAM.  Bit positions enumerated with CDE_RAMS_E. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_ecc0_ctl_s cn; */
} bdk_cdex_pf_ecc0_ctl_t;

static inline uint64_t BDK_CDEX_PF_ECC0_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_ECC0_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000000200ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("CDEX_PF_ECC0_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_CDEX_PF_ECC0_CTL(a) bdk_cdex_pf_ecc0_ctl_t
#define bustype_BDK_CDEX_PF_ECC0_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_ECC0_CTL(a) "CDEX_PF_ECC0_CTL"
#define busnum_BDK_CDEX_PF_ECC0_CTL(a) (a)
#define arguments_BDK_CDEX_PF_ECC0_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) cde#_vq#_ctl
 *
 * CDE VF Queue Control Registers
 * These registers set the buffer parameters for the instruction queues. When quiescent
 * (i.e. outstanding doorbell count is 0), it is safe to rewrite this register to
 * effectively reset the command buffer state machine. These registers must be
 * programmed before software programs the corresponding CDE()_VQ()_SADDR.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vqx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_45_63        : 19;
        uint64_t size                  : 13; /**< [ 44: 32](R/W) Command-buffer size, in number of 64-bit words per command buffer segment.
                                                                 Must be even. */
        uint64_t reserved_23_31        : 9;
        uint64_t inst_free             : 1;  /**< [ 22: 22](R/W) Instruction FPA free. When set, when CDE reaches the end of an instruction
                                                                 chunk, that chunk will be freed to the FPA. */
        uint64_t inst_be               : 1;  /**< [ 21: 21](R/W) Instruction big endian control. When set, instructions are storaged in big
                                                                 endian format in memory. */
        uint64_t iqb_ldwb              : 1;  /**< [ 20: 20](R/W) When set, reading a CDE instruction full cache lines will use NCB LDWB
                                                                 read-and-invalidate to improve performance. If clear, use NCB LDI for
                                                                 debugability. Partial cache line reads always use LDI. */
        uint64_t cbw_sty               : 1;  /**< [ 19: 19](R/W) When set, a context cache block write will use STY. When clear, a context write
                                                                 will use STF. */
        uint64_t l2ld_cmd              : 2;  /**< [ 18: 17](R/W) Which NCB load command to use for reading gather pointers, context, history and input
                                                                 data.
                                                                 0x0 = LDD.
                                                                 0x1 = LDI.
                                                                 0x2 = LDE.
                                                                 0x3 = LDY. */
        uint64_t ena                   : 1;  /**< [ 16: 16](R/W) Enables the logical instruction queue.
                                                                 1 = Queue is enabled.
                                                                 0 = Queue is disabled. */
        uint64_t reserved_12_15        : 4;
        uint64_t aura                  : 12; /**< [ 11:  0](R/W) Aura for returning this queue's instruction-chunk buffers to FPA.
                                                                 Only used when [INST_FREE] is set. */
#else /* Word 0 - Little Endian */
        uint64_t aura                  : 12; /**< [ 11:  0](R/W) Aura for returning this queue's instruction-chunk buffers to FPA.
                                                                 Only used when [INST_FREE] is set. */
        uint64_t reserved_12_15        : 4;
        uint64_t ena                   : 1;  /**< [ 16: 16](R/W) Enables the logical instruction queue.
                                                                 1 = Queue is enabled.
                                                                 0 = Queue is disabled. */
        uint64_t l2ld_cmd              : 2;  /**< [ 18: 17](R/W) Which NCB load command to use for reading gather pointers, context, history and input
                                                                 data.
                                                                 0x0 = LDD.
                                                                 0x1 = LDI.
                                                                 0x2 = LDE.
                                                                 0x3 = LDY. */
        uint64_t cbw_sty               : 1;  /**< [ 19: 19](R/W) When set, a context cache block write will use STY. When clear, a context write
                                                                 will use STF. */
        uint64_t iqb_ldwb              : 1;  /**< [ 20: 20](R/W) When set, reading a CDE instruction full cache lines will use NCB LDWB
                                                                 read-and-invalidate to improve performance. If clear, use NCB LDI for
                                                                 debugability. Partial cache line reads always use LDI. */
        uint64_t inst_be               : 1;  /**< [ 21: 21](R/W) Instruction big endian control. When set, instructions are storaged in big
                                                                 endian format in memory. */
        uint64_t inst_free             : 1;  /**< [ 22: 22](R/W) Instruction FPA free. When set, when CDE reaches the end of an instruction
                                                                 chunk, that chunk will be freed to the FPA. */
        uint64_t reserved_23_31        : 9;
        uint64_t size                  : 13; /**< [ 44: 32](R/W) Command-buffer size, in number of 64-bit words per command buffer segment.
                                                                 Must be even. */
        uint64_t reserved_45_63        : 19;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vqx_ctl_s cn; */
} bdk_cdex_vqx_ctl_t;

static inline uint64_t BDK_CDEX_VQX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VQX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020000100ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_VQX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_VQX_CTL(a,b) bdk_cdex_vqx_ctl_t
#define bustype_BDK_CDEX_VQX_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VQX_CTL(a,b) "CDEX_VQX_CTL"
#define busnum_BDK_CDEX_VQX_CTL(a,b) (a)
#define arguments_BDK_CDEX_VQX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_vf#_msix_vec#_addr
 *
 * CDE VF MSI-X Vector-Table Address Registers
 * This register is the MSI-X vector table, indexed by the CDE_VF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vfx_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](RAZ) Secure vector. Zero as not supported on a per-vector basis for VFs; use
                                                                 PCCPF_CDE_VSEC_SCTL[MSIX_SEC] instead (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]). */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](RAZ) Secure vector. Zero as not supported on a per-vector basis for VFs; use
                                                                 PCCPF_CDE_VSEC_SCTL[MSIX_SEC] instead (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]). */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vfx_msix_vecx_addr_s cn; */
} bdk_cdex_vfx_msix_vecx_addr_t;

static inline uint64_t BDK_CDEX_VFX_MSIX_VECX_ADDR(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VFX_MSIX_VECX_ADDR(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c030000000ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f) + 0x10ll * ((c) & 0x1);
    __bdk_csr_fatal("CDEX_VFX_MSIX_VECX_ADDR", 3, a, b, c, 0);
}

#define typedef_BDK_CDEX_VFX_MSIX_VECX_ADDR(a,b,c) bdk_cdex_vfx_msix_vecx_addr_t
#define bustype_BDK_CDEX_VFX_MSIX_VECX_ADDR(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VFX_MSIX_VECX_ADDR(a,b,c) "CDEX_VFX_MSIX_VECX_ADDR"
#define busnum_BDK_CDEX_VFX_MSIX_VECX_ADDR(a,b,c) (a)
#define arguments_BDK_CDEX_VFX_MSIX_VECX_ADDR(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) cde#_vq#_done_int_w1c
 *
 * CDE Queue Done Interrupt Clear Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vqx_done_int_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done                  : 1;  /**< [  0:  0](RO/H) Done interrupt. See CDE()_VQ()_DONE[DONE].  Note this bit is read-only, to acknowledge
                                                                 interrupts use CDE()_VQ()_DONE_ACK. To test interrupts, write non-zero to
                                                                 CDE()_VQ()_DONE[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](RO/H) Done interrupt. See CDE()_VQ()_DONE[DONE].  Note this bit is read-only, to acknowledge
                                                                 interrupts use CDE()_VQ()_DONE_ACK. To test interrupts, write non-zero to
                                                                 CDE()_VQ()_DONE[DONE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vqx_done_int_w1c_s cn; */
} bdk_cdex_vqx_done_int_w1c_t;

static inline uint64_t BDK_CDEX_VQX_DONE_INT_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VQX_DONE_INT_W1C(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020000468ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_VQX_DONE_INT_W1C", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_VQX_DONE_INT_W1C(a,b) bdk_cdex_vqx_done_int_w1c_t
#define bustype_BDK_CDEX_VQX_DONE_INT_W1C(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VQX_DONE_INT_W1C(a,b) "CDEX_VQX_DONE_INT_W1C"
#define busnum_BDK_CDEX_VQX_DONE_INT_W1C(a,b) (a)
#define arguments_BDK_CDEX_VQX_DONE_INT_W1C(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_vq#_done_int_w1s
 *
 * CDE Queue Done Interrupt Set Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vqx_done_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done                  : 1;  /**< [  0:  0](RO/H) Done interrupt. See CDE()_VQ()_DONE[DONE].  Note this bit is read-only, to acknowledge
                                                                 interrupts use CDE()_VQ()_DONE_ACK. To test interrupts, write non-zero to
                                                                 CDE()_VQ()_DONE[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](RO/H) Done interrupt. See CDE()_VQ()_DONE[DONE].  Note this bit is read-only, to acknowledge
                                                                 interrupts use CDE()_VQ()_DONE_ACK. To test interrupts, write non-zero to
                                                                 CDE()_VQ()_DONE[DONE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vqx_done_int_w1s_s cn; */
} bdk_cdex_vqx_done_int_w1s_t;

static inline uint64_t BDK_CDEX_VQX_DONE_INT_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VQX_DONE_INT_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020000460ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_VQX_DONE_INT_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_VQX_DONE_INT_W1S(a,b) bdk_cdex_vqx_done_int_w1s_t
#define bustype_BDK_CDEX_VQX_DONE_INT_W1S(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VQX_DONE_INT_W1S(a,b) "CDEX_VQX_DONE_INT_W1S"
#define busnum_BDK_CDEX_VQX_DONE_INT_W1S(a,b) (a)
#define arguments_BDK_CDEX_VQX_DONE_INT_W1S(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_vq#_misc_ena_w1c
 *
 * CDE Queue Misc Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vqx_misc_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CDE(0)_VQ(0..63)_MISC_INT[NWRP]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CDE(0)_VQ(0..63)_MISC_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CDE(0)_VQ(0..63)_MISC_INT[DOVF]. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CDE(0)_VQ(0..63)_MISC_INT[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CDE(0)_VQ(0..63)_MISC_INT[MBOX]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CDE(0)_VQ(0..63)_MISC_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CDE(0)_VQ(0..63)_MISC_INT[IRDE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CDE(0)_VQ(0..63)_MISC_INT[NWRP]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vqx_misc_ena_w1c_s cn; */
} bdk_cdex_vqx_misc_ena_w1c_t;

static inline uint64_t BDK_CDEX_VQX_MISC_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VQX_MISC_ENA_W1C(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020000518ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_VQX_MISC_ENA_W1C", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_VQX_MISC_ENA_W1C(a,b) bdk_cdex_vqx_misc_ena_w1c_t
#define bustype_BDK_CDEX_VQX_MISC_ENA_W1C(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VQX_MISC_ENA_W1C(a,b) "CDEX_VQX_MISC_ENA_W1C"
#define busnum_BDK_CDEX_VQX_MISC_ENA_W1C(a,b) (a)
#define arguments_BDK_CDEX_VQX_MISC_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_vq#_misc_ena_w1s
 *
 * CDE Queue Misc Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vqx_misc_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CDE(0)_VQ(0..63)_MISC_INT[NWRP]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CDE(0)_VQ(0..63)_MISC_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CDE(0)_VQ(0..63)_MISC_INT[DOVF]. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CDE(0)_VQ(0..63)_MISC_INT[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CDE(0)_VQ(0..63)_MISC_INT[MBOX]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CDE(0)_VQ(0..63)_MISC_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CDE(0)_VQ(0..63)_MISC_INT[IRDE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CDE(0)_VQ(0..63)_MISC_INT[NWRP]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vqx_misc_ena_w1s_s cn; */
} bdk_cdex_vqx_misc_ena_w1s_t;

static inline uint64_t BDK_CDEX_VQX_MISC_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VQX_MISC_ENA_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020000510ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_VQX_MISC_ENA_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_VQX_MISC_ENA_W1S(a,b) bdk_cdex_vqx_misc_ena_w1s_t
#define bustype_BDK_CDEX_VQX_MISC_ENA_W1S(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VQX_MISC_ENA_W1S(a,b) "CDEX_VQX_MISC_ENA_W1S"
#define busnum_BDK_CDEX_VQX_MISC_ENA_W1S(a,b) (a)
#define arguments_BDK_CDEX_VQX_MISC_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_vq#_doorbell
 *
 * CDE Queue Doorbell Registers
 * Doorbells for the CDE instruction queues.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vqx_doorbell_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t dbell_cnt             : 20; /**< [ 19:  0](R/W/H) Number of instruction queue 64-bit words to add to the CDE instruction doorbell
                                                                 count.

                                                                 CPT: Must be a multiple of 8. All CPT instructions are 8 words and require a
                                                                 doorbell count of multiple of 8.

                                                                 DDF: Must be a multiple of 16. All DDF instructions are 16 words and require a
                                                                 doorbell count of multiple of 16. */
#else /* Word 0 - Little Endian */
        uint64_t dbell_cnt             : 20; /**< [ 19:  0](R/W/H) Number of instruction queue 64-bit words to add to the CDE instruction doorbell
                                                                 count.

                                                                 CPT: Must be a multiple of 8. All CPT instructions are 8 words and require a
                                                                 doorbell count of multiple of 8.

                                                                 DDF: Must be a multiple of 16. All DDF instructions are 16 words and require a
                                                                 doorbell count of multiple of 16. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vqx_doorbell_s cn; */
} bdk_cdex_vqx_doorbell_t;

static inline uint64_t BDK_CDEX_VQX_DOORBELL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VQX_DOORBELL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020000600ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_VQX_DOORBELL", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_VQX_DOORBELL(a,b) bdk_cdex_vqx_doorbell_t
#define bustype_BDK_CDEX_VQX_DOORBELL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VQX_DOORBELL(a,b) "CDEX_VQX_DOORBELL"
#define busnum_BDK_CDEX_VQX_DOORBELL(a,b) (a)
#define arguments_BDK_CDEX_VQX_DOORBELL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_pf_q#_ctl
 *
 * CDE Queue Control Register
 * This register configures queues.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_qx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t grp                   : 3;  /**< [  3:  1](R/W) Engine group. */
        uint64_t pri                   : 1;  /**< [  0:  0](R/W) Queue priority.
                                                                 1 = This queue has higher priority. Round-robin between higher priority queues.
                                                                 0 = This queue has lower priority. Round-robin between lower priority queues. */
#else /* Word 0 - Little Endian */
        uint64_t pri                   : 1;  /**< [  0:  0](R/W) Queue priority.
                                                                 1 = This queue has higher priority. Round-robin between higher priority queues.
                                                                 0 = This queue has lower priority. Round-robin between lower priority queues. */
        uint64_t grp                   : 3;  /**< [  3:  1](R/W) Engine group. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_qx_ctl_s cn; */
} bdk_cdex_pf_qx_ctl_t;

static inline uint64_t BDK_CDEX_PF_QX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_QX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c008000000ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_PF_QX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_PF_QX_CTL(a,b) bdk_cdex_pf_qx_ctl_t
#define bustype_BDK_CDEX_PF_QX_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_QX_CTL(a,b) "CDEX_PF_QX_CTL"
#define busnum_BDK_CDEX_PF_QX_CTL(a,b) (a)
#define arguments_BDK_CDEX_PF_QX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_pf_reset
 *
 * CDE PF Reset Register
 * This register controls clock and reset.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_reset_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1) Reset one-shot pulse to reset CDE subsystem. */
#else /* Word 0 - Little Endian */
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1) Reset one-shot pulse to reset CDE subsystem. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_reset_s cn; */
} bdk_cdex_pf_reset_t;

static inline uint64_t BDK_CDEX_PF_RESET(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_RESET(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000000100ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("CDEX_PF_RESET", 1, a, 0, 0, 0);
}

#define typedef_BDK_CDEX_PF_RESET(a) bdk_cdex_pf_reset_t
#define bustype_BDK_CDEX_PF_RESET(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_RESET(a) "CDEX_PF_RESET"
#define busnum_BDK_CDEX_PF_RESET(a) (a)
#define arguments_BDK_CDEX_PF_RESET(a) (a),-1,-1,-1

/**
 * Register (NCB) cde#_vf#_msix_pba#
 *
 * CDE VF MSI-X Pending-Bit-Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the CDE_VF_INT_VEC_E
 * enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vfx_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated CDE()_PF_MSIX_VEC()_CTL, enumerated by
                                                                 CDE_PF_INT_VEC_E. Bits that have no associated CDE_PF_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated CDE()_PF_MSIX_VEC()_CTL, enumerated by
                                                                 CDE_PF_INT_VEC_E. Bits that have no associated CDE_PF_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vfx_msix_pbax_s cn; */
} bdk_cdex_vfx_msix_pbax_t;

static inline uint64_t BDK_CDEX_VFX_MSIX_PBAX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VFX_MSIX_PBAX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c0300f0000ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f) + 8ll * ((c) & 0x0);
    __bdk_csr_fatal("CDEX_VFX_MSIX_PBAX", 3, a, b, c, 0);
}

#define typedef_BDK_CDEX_VFX_MSIX_PBAX(a,b,c) bdk_cdex_vfx_msix_pbax_t
#define bustype_BDK_CDEX_VFX_MSIX_PBAX(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VFX_MSIX_PBAX(a,b,c) "CDEX_VFX_MSIX_PBAX"
#define busnum_BDK_CDEX_VFX_MSIX_PBAX(a,b,c) (a)
#define arguments_BDK_CDEX_VFX_MSIX_PBAX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) cde#_pf_inst_latency_pc
 *
 * CDE PF Instruction Latency Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_inst_latency_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for an instruction to complete (have the store of
                                                                 CDE_RES_S reach the commit point). Incremented every coprocessor-clock by the
                                                                 number of instructions active in that cycle. This may be divided by
                                                                 CDE()_PF_RD_REQ_PC to determine the average hardware instruction latency. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for an instruction to complete (have the store of
                                                                 CDE_RES_S reach the commit point). Incremented every coprocessor-clock by the
                                                                 number of instructions active in that cycle. This may be divided by
                                                                 CDE()_PF_RD_REQ_PC to determine the average hardware instruction latency. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_inst_latency_pc_s cn; */
} bdk_cdex_pf_inst_latency_pc_t;

static inline uint64_t BDK_CDEX_PF_INST_LATENCY_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_INST_LATENCY_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000010020ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("CDEX_PF_INST_LATENCY_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_CDEX_PF_INST_LATENCY_PC(a) bdk_cdex_pf_inst_latency_pc_t
#define bustype_BDK_CDEX_PF_INST_LATENCY_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_INST_LATENCY_PC(a) "CDEX_PF_INST_LATENCY_PC"
#define busnum_BDK_CDEX_PF_INST_LATENCY_PC(a) (a)
#define arguments_BDK_CDEX_PF_INST_LATENCY_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) cde#_vq#_misc_int
 *
 * CDE Queue Misc Interrupt Register
 * These registers contain the per-queue miscellaneous interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vqx_misc_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) NCB result write response error. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1C/H) Instruction NCB read response error. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1C/H) Doorbell overflow. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1C/H) PF to VF mailbox interrupt. Set when CDE(0)_VF(0..63)_MBOX(0)
                                                                 is written. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1C/H) PF to VF mailbox interrupt. Set when CDE(0)_VF(0..63)_MBOX(0)
                                                                 is written. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1C/H) Doorbell overflow. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1C/H) Instruction NCB read response error. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) NCB result write response error. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vqx_misc_int_s cn; */
} bdk_cdex_vqx_misc_int_t;

static inline uint64_t BDK_CDEX_VQX_MISC_INT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VQX_MISC_INT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020000500ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_VQX_MISC_INT", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_VQX_MISC_INT(a,b) bdk_cdex_vqx_misc_int_t
#define bustype_BDK_CDEX_VQX_MISC_INT(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VQX_MISC_INT(a,b) "CDEX_VQX_MISC_INT"
#define busnum_BDK_CDEX_VQX_MISC_INT(a,b) (a)
#define arguments_BDK_CDEX_VQX_MISC_INT(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_vq#_done_ena_w1c
 *
 * CDE Queue Done Interrupt Enable Clear Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vqx_done_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done                  : 1;  /**< [  0:  0](R/W1C/H) Read or clears CDE()_VQ()_DONE_ENA_W1S[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1C/H) Read or clears CDE()_VQ()_DONE_ENA_W1S[DONE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vqx_done_ena_w1c_s cn; */
} bdk_cdex_vqx_done_ena_w1c_t;

static inline uint64_t BDK_CDEX_VQX_DONE_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VQX_DONE_ENA_W1C(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020000478ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_VQX_DONE_ENA_W1C", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_VQX_DONE_ENA_W1C(a,b) bdk_cdex_vqx_done_ena_w1c_t
#define bustype_BDK_CDEX_VQX_DONE_ENA_W1C(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VQX_DONE_ENA_W1C(a,b) "CDEX_VQX_DONE_ENA_W1C"
#define busnum_BDK_CDEX_VQX_DONE_ENA_W1C(a,b) (a)
#define arguments_BDK_CDEX_VQX_DONE_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_pf_ecc0_int
 *
 * CDE ECC Interrupt Status Register
 * This register contains the status of the ECC interrupt sources.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_ecc0_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1C/H) Double-bit error detected in internal RAM. One bit per memory, enumerated by
                                                                 CDE_RAMS_E. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1C/H) Single-bit error detected in internal RAM. One bit per memory, enumerated by
                                                                 CDE_RAMS_E. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1C/H) Single-bit error detected in internal RAM. One bit per memory, enumerated by
                                                                 CDE_RAMS_E. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1C/H) Double-bit error detected in internal RAM. One bit per memory, enumerated by
                                                                 CDE_RAMS_E. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_ecc0_int_s cn; */
} bdk_cdex_pf_ecc0_int_t;

static inline uint64_t BDK_CDEX_PF_ECC0_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_ECC0_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c000000220ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("CDEX_PF_ECC0_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_CDEX_PF_ECC0_INT(a) bdk_cdex_pf_ecc0_int_t
#define bustype_BDK_CDEX_PF_ECC0_INT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_ECC0_INT(a) "CDEX_PF_ECC0_INT"
#define busnum_BDK_CDEX_PF_ECC0_INT(a) (a)
#define arguments_BDK_CDEX_PF_ECC0_INT(a) (a),-1,-1,-1

/**
 * Register (NCB) cde#_vq#_done_ena_w1s
 *
 * CDE Queue Done Interrupt Enable Set Registers
 * Write 1 to these registers will enable the DONEINT interrupt for the queue.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vqx_done_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done                  : 1;  /**< [  0:  0](R/W1S/H) Write 1 will enable DONEINT for this queue. Write 0 has no effect.
                                                                 Read will return the enable bit. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1S/H) Write 1 will enable DONEINT for this queue. Write 0 has no effect.
                                                                 Read will return the enable bit. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_vqx_done_ena_w1s_s cn; */
} bdk_cdex_vqx_done_ena_w1s_t;

static inline uint64_t BDK_CDEX_VQX_DONE_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VQX_DONE_ENA_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c020000470ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_VQX_DONE_ENA_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_VQX_DONE_ENA_W1S(a,b) bdk_cdex_vqx_done_ena_w1s_t
#define bustype_BDK_CDEX_VQX_DONE_ENA_W1S(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VQX_DONE_ENA_W1S(a,b) "CDEX_VQX_DONE_ENA_W1S"
#define busnum_BDK_CDEX_VQX_DONE_ENA_W1S(a,b) (a)
#define arguments_BDK_CDEX_VQX_DONE_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cde#_vf#_msix_vec#_ctl
 *
 * CDE VF MSI-X Vector-Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the CDE_VF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_vfx_msix_vecx_ctl_s
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
    /* struct bdk_cdex_vfx_msix_vecx_ctl_s cn; */
} bdk_cdex_vfx_msix_vecx_ctl_t;

static inline uint64_t BDK_CDEX_VFX_MSIX_VECX_CTL(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_VFX_MSIX_VECX_CTL(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c030000008ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f) + 0x10ll * ((c) & 0x1);
    __bdk_csr_fatal("CDEX_VFX_MSIX_VECX_CTL", 3, a, b, c, 0);
}

#define typedef_BDK_CDEX_VFX_MSIX_VECX_CTL(a,b,c) bdk_cdex_vfx_msix_vecx_ctl_t
#define bustype_BDK_CDEX_VFX_MSIX_VECX_CTL(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_VFX_MSIX_VECX_CTL(a,b,c) "CDEX_VFX_MSIX_VECX_CTL"
#define busnum_BDK_CDEX_VFX_MSIX_VECX_CTL(a,b,c) (a)
#define arguments_BDK_CDEX_VFX_MSIX_VECX_CTL(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) cde#_pf_q#_gmctl
 *
 * CDE Queue Guest Machine Control Register
 * This register configures queues.
 */
typedef union
{
    uint64_t u;
    struct bdk_cdex_pf_qx_gmctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t strm                  : 8;  /**< [ 23: 16](R/W) Low 8 bits of the SMMU stream identifier to use when issuing requests.

                                                                 Stream 0x0 corresponds to the PF, and VFs start at 0x1.

                                                                 Reset such that VF0/index 0 is 0x1, VF1/index 1 is 0x2, etc. */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Reserved. INTERNAL: Guest machine identifier. The GMID to send to FPA for all
                                                                 buffer free, or to SSO for all submit work operations initiated by this queue.
                                                                 Must be non-zero or FPA/SSO will drop requests. */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Reserved. INTERNAL: Guest machine identifier. The GMID to send to FPA for all
                                                                 buffer free, or to SSO for all submit work operations initiated by this queue.
                                                                 Must be non-zero or FPA/SSO will drop requests. */
        uint64_t strm                  : 8;  /**< [ 23: 16](R/W) Low 8 bits of the SMMU stream identifier to use when issuing requests.

                                                                 Stream 0x0 corresponds to the PF, and VFs start at 0x1.

                                                                 Reset such that VF0/index 0 is 0x1, VF1/index 1 is 0x2, etc. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cdex_pf_qx_gmctl_s cn; */
} bdk_cdex_pf_qx_gmctl_t;

static inline uint64_t BDK_CDEX_PF_QX_GMCTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CDEX_PF_QX_GMCTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80c008000020ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CDEX_PF_QX_GMCTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CDEX_PF_QX_GMCTL(a,b) bdk_cdex_pf_qx_gmctl_t
#define bustype_BDK_CDEX_PF_QX_GMCTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CDEX_PF_QX_GMCTL(a,b) "CDEX_PF_QX_GMCTL"
#define busnum_BDK_CDEX_PF_QX_GMCTL(a,b) (a)
#define arguments_BDK_CDEX_PF_QX_GMCTL(a,b) (a),(b),-1,-1

#endif /* __BDK_CSRS_CDE_H__ */
