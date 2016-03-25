#ifndef __BDK_CSRS_CPT_H__
#define __BDK_CSRS_CPT_H__
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
 * Cavium CPT.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration cpt_bar_e
 *
 * CPT Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_CPT_BAR_E_CPTX_PF_BAR0(a) (0x872000000000ll + 0x1000000000ll * (a))
#define BDK_CPT_BAR_E_CPTX_PF_BAR4(a) (0x872010000000ll + 0x1000000000ll * (a))
#define BDK_CPT_BAR_E_CPTX_VFX_BAR0(a,b) (0x872020000000ll + 0x1000000000ll * (a) + 0x100000ll * (b))
#define BDK_CPT_BAR_E_CPTX_VFX_BAR4(a,b) (0x872030000000ll + 0x1000000000ll * (a) + 0x100000ll * (b))

/**
 * Enumeration cpt_comp_e
 *
 * CPT Completion Enumeration
 * Enumerates the values of CPT_RES_S[COMPCODE].
 */
#define BDK_CPT_COMP_E_FAULT (2)
#define BDK_CPT_COMP_E_GOOD (1)
#define BDK_CPT_COMP_E_NOTDONE (0)
#define BDK_CPT_COMP_E_SWERR (3)

/**
 * Enumeration cpt_engine_err_type_e
 *
 * CPT Engine Error Code Enumeration
 * Enumerates the values of CPT_RES_S[COMPCODE].
 */
#define BDK_CPT_ENGINE_ERR_TYPE_E_BUS (0x20)
#define BDK_CPT_ENGINE_ERR_TYPE_E_GE (8)
#define BDK_CPT_ENGINE_ERR_TYPE_E_GI (0x10)
#define BDK_CPT_ENGINE_ERR_TYPE_E_NOERR (0)
#define BDK_CPT_ENGINE_ERR_TYPE_E_RF (1)
#define BDK_CPT_ENGINE_ERR_TYPE_E_UC (2)
#define BDK_CPT_ENGINE_ERR_TYPE_E_WD (4)

/**
 * Enumeration cpt_eop_e
 *
 * CPT EOP (EPCI Opcodes) Enumeration
 * Opcodes on the epci bus.
 */
#define BDK_CPT_EOP_E_ATM_FAA64 (0x3b)
#define BDK_CPT_EOP_E_DMA_RD_LDD (8)
#define BDK_CPT_EOP_E_DMA_RD_LDE (0xb)
#define BDK_CPT_EOP_E_DMA_RD_LDI (2)
#define BDK_CPT_EOP_E_DMA_RD_LDT (1)
#define BDK_CPT_EOP_E_DMA_RD_LDWB (0xd)
#define BDK_CPT_EOP_E_DMA_RD_LDY (6)
#define BDK_CPT_EOP_E_DMA_WR_STP (0x12)
#define BDK_CPT_EOP_E_DMA_WR_STT (0x11)
#define BDK_CPT_EOP_E_DMA_WR_STY (0xe)
#define BDK_CPT_EOP_E_ERR_REQUEST (0xfb)
#define BDK_CPT_EOP_E_MEMB (0xfd)
#define BDK_CPT_EOP_E_NEW_WORK_REQ (0xff)
#define BDK_CPT_EOP_E_RANDOM1_REQ (0x61)
#define BDK_CPT_EOP_E_RANDOM_REQ (0x60)
#define BDK_CPT_EOP_E_UCODE_REQ (0xfc)

/**
 * Enumeration cpt_pf_int_vec_e
 *
 * CPT PF MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_CPT_PF_INT_VEC_E_ECC0 (0)
#define BDK_CPT_PF_INT_VEC_E_EXEC (1)
#define BDK_CPT_PF_INT_VEC_E_MBOXX(a) (2 + (a))

/**
 * Enumeration cpt_rams_e
 *
 * CPT RAM Field Enumeration
 * Enumerates the relative bit positions within CPT()_PF_ECC0_CTL[CDIS].
 */
#define BDK_CPT_RAMS_E_CDEI_FIFO0 (0x1a)
#define BDK_CPT_RAMS_E_CDEI_FIFO1 (0x1b)
#define BDK_CPT_RAMS_E_CDEI_UCODE (0x12)
#define BDK_CPT_RAMS_E_COMP_ARRAY0 (0x13)
#define BDK_CPT_RAMS_E_COMP_ARRAY1 (0x14)
#define BDK_CPT_RAMS_E_COMP_FIFO (0xf)
#define BDK_CPT_RAMS_E_CQM_BPTR (3)
#define BDK_CPT_RAMS_E_CQM_CTLMEM (2)
#define BDK_CPT_RAMS_E_CQM_DONE_CNT (0xd)
#define BDK_CPT_RAMS_E_CQM_DONE_TIMER (0xe)
#define BDK_CPT_RAMS_E_CQM_GMID (4)
#define BDK_CPT_RAMS_E_CQM_INSTFIF0 (5)
#define BDK_CPT_RAMS_E_CQM_INSTFIF1 (6)
#define BDK_CPT_RAMS_E_CQM_INSTFIF2 (7)
#define BDK_CPT_RAMS_E_CQM_INSTFIF3 (8)
#define BDK_CPT_RAMS_E_CQM_INSTFIF4 (9)
#define BDK_CPT_RAMS_E_CQM_INSTFIF5 (0xa)
#define BDK_CPT_RAMS_E_CQM_INSTFIF6 (0xb)
#define BDK_CPT_RAMS_E_CQM_INSTFIF7 (0xc)
#define BDK_CPT_RAMS_E_CSR_VMEM (0x15)
#define BDK_CPT_RAMS_E_EPCO_FIFO0 (0x1c)
#define BDK_CPT_RAMS_E_EPCO_FIFO1 (0x1d)
#define BDK_CPT_RAMS_E_FPA_MEM (0x11)
#define BDK_CPT_RAMS_E_MBOX_MEM (0x10)
#define BDK_CPT_RAMS_E_NCBI_DATFIF (0)
#define BDK_CPT_RAMS_E_NCBO_MEM0 (1)
#define BDK_CPT_RAMS_E_RSP_INST (0x17)
#define BDK_CPT_RAMS_E_RSP_MAP (0x16)
#define BDK_CPT_RAMS_E_RSP_NCBO (0x18)
#define BDK_CPT_RAMS_E_RSP_RNM (0x19)

/**
 * Enumeration cpt_vf_int_vec_e
 *
 * CPT VF MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_CPT_VF_INT_VEC_E_DONE (1)
#define BDK_CPT_VF_INT_VEC_E_MISC (0)

/**
 * Structure cpt_inst_s
 *
 * CPT Instruction Structure
 * This structure specifies the instruction layout. Instructions are stored in memory
 * as little-endian unless CPT()_PF_Q()_CTL[INST_BE] is set.
 */
union bdk_cpt_inst_s
{
    uint64_t u[8];
    struct bdk_cpt_inst_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt.
                                                                 0 = No interrupts related to this instruction.
                                                                 1 = When the instruction completes, CPT()_VQ()_DONE[DONE] will be incremented,
                                                                 and based on the rules described there an interrupt may occur. */
        uint64_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_15         : 16;
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt.
                                                                 0 = No interrupts related to this instruction.
                                                                 1 = When the instruction completes, CPT()_VQ()_DONE[DONE] will be incremented,
                                                                 and based on the rules described there an interrupt may occur. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t res_addr              : 64; /**< [127: 64] Result IOVA.
                                                                 If nonzero, specifies where to write CPT_RES_S.
                                                                 If zero, no result structure will be written.
                                                                 Address must be 16-byte aligned.

                                                                 Bits <63:49> are ignored by hardware; software should use a sign-extended bit
                                                                 <48> for forward compatibility. */
#else /* Word 1 - Little Endian */
        uint64_t res_addr              : 64; /**< [127: 64] Result IOVA.
                                                                 If nonzero, specifies where to write CPT_RES_S.
                                                                 If zero, no result structure will be written.
                                                                 Address must be 16-byte aligned.

                                                                 Bits <63:49> are ignored by hardware; software should use a sign-extended bit
                                                                 <48> for forward compatibility. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_172_191      : 20;
        uint64_t grp                   : 10; /**< [171:162] If [WQ_PTR] is nonzero, the SSO guest-group to use when CPT submits work to
                                                                 SSO.
                                                                 For the SSO to not discard the add-work request, FPA_PF_MAP() must map
                                                                 [GRP] and CPT()_PF_Q()_GMCTL[GMID] as valid. */
        uint64_t tt                    : 2;  /**< [161:160] If [WQ_PTR] is nonzero, the SSO tag type to use when CPT submits work to SSO. */
        uint64_t tag                   : 32; /**< [159:128] If [WQ_PTR] is nonzero, the SSO tag to use when CPT submits work to SSO. */
#else /* Word 2 - Little Endian */
        uint64_t tag                   : 32; /**< [159:128] If [WQ_PTR] is nonzero, the SSO tag to use when CPT submits work to SSO. */
        uint64_t tt                    : 2;  /**< [161:160] If [WQ_PTR] is nonzero, the SSO tag type to use when CPT submits work to SSO. */
        uint64_t grp                   : 10; /**< [171:162] If [WQ_PTR] is nonzero, the SSO guest-group to use when CPT submits work to
                                                                 SSO.
                                                                 For the SSO to not discard the add-work request, FPA_PF_MAP() must map
                                                                 [GRP] and CPT()_PF_Q()_GMCTL[GMID] as valid. */
        uint64_t reserved_172_191      : 20;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t wq_ptr                : 64; /**< [255:192] If [WQ_PTR] is nonzero, it is a pointer to a work-queue entry that CPT submits
                                                                 work to SSO after all context, output data, and result write operations are
                                                                 visible to other CNXXXX units and the cores.

                                                                 Bits <2:0> must be zero.  Bits <63:49> are ignored by hardware; software should
                                                                 use a sign-extended bit <48> for forward compatibility.

                                                                 Internal:
                                                                 Bits <63:49>, <2:0> are ignored by hardware, treated as always 0x0. */
#else /* Word 3 - Little Endian */
        uint64_t wq_ptr                : 64; /**< [255:192] If [WQ_PTR] is nonzero, it is a pointer to a work-queue entry that CPT submits
                                                                 work to SSO after all context, output data, and result write operations are
                                                                 visible to other CNXXXX units and the cores.

                                                                 Bits <2:0> must be zero.  Bits <63:49> are ignored by hardware; software should
                                                                 use a sign-extended bit <48> for forward compatibility.

                                                                 Internal:
                                                                 Bits <63:49>, <2:0> are ignored by hardware, treated as always 0x0. */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t ei0                   : 64; /**< [319:256] Engine instruction word 0. Passed to the AE/SE. */
#else /* Word 4 - Little Endian */
        uint64_t ei0                   : 64; /**< [319:256] Engine instruction word 0. Passed to the AE/SE. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t ei1                   : 64; /**< [383:320] Engine instruction word 1. Passed to the AE/SE. */
#else /* Word 5 - Little Endian */
        uint64_t ei1                   : 64; /**< [383:320] Engine instruction word 1. Passed to the AE/SE. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t ei2                   : 64; /**< [447:384] Engine instruction word 2. Passed to the AE/SE. */
#else /* Word 6 - Little Endian */
        uint64_t ei2                   : 64; /**< [447:384] Engine instruction word 2. Passed to the AE/SE. */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t ei3                   : 64; /**< [511:448] Engine instruction word 3. Passed to the AE/SE. */
#else /* Word 7 - Little Endian */
        uint64_t ei3                   : 64; /**< [511:448] Engine instruction word 3. Passed to the AE/SE. */
#endif /* Word 7 - End */
    } s;
    struct bdk_cpt_inst_s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt.
                                                                 0 = No interrupts related to this instruction.
                                                                 1 = When the instruction completes, CPT()_VQ()_DONE[DONE] will be incremented,
                                                                 and based on the rules described there an interrupt may occur. */
        uint64_t reserved_8_15         : 8;
        uint64_t reserved_0_7          : 8;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_7          : 8;
        uint64_t reserved_8_15         : 8;
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt.
                                                                 0 = No interrupts related to this instruction.
                                                                 1 = When the instruction completes, CPT()_VQ()_DONE[DONE] will be incremented,
                                                                 and based on the rules described there an interrupt may occur. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t res_addr              : 64; /**< [127: 64] Result IOVA.
                                                                 If nonzero, specifies where to write CPT_RES_S.
                                                                 If zero, no result structure will be written.
                                                                 Address must be 16-byte aligned.

                                                                 Bits <63:49> are ignored by hardware; software should use a sign-extended bit
                                                                 <48> for forward compatibility. */
#else /* Word 1 - Little Endian */
        uint64_t res_addr              : 64; /**< [127: 64] Result IOVA.
                                                                 If nonzero, specifies where to write CPT_RES_S.
                                                                 If zero, no result structure will be written.
                                                                 Address must be 16-byte aligned.

                                                                 Bits <63:49> are ignored by hardware; software should use a sign-extended bit
                                                                 <48> for forward compatibility. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_172_191      : 20;
        uint64_t grp                   : 10; /**< [171:162] If [WQ_PTR] is nonzero, the SSO guest-group to use when CPT submits work to
                                                                 SSO.
                                                                 For the SSO to not discard the add-work request, FPA_PF_MAP() must map
                                                                 [GRP] and CPT()_PF_Q()_GMCTL[GMID] as valid. */
        uint64_t tt                    : 2;  /**< [161:160] If [WQ_PTR] is nonzero, the SSO tag type to use when CPT submits work to SSO. */
        uint64_t tag                   : 32; /**< [159:128] If [WQ_PTR] is nonzero, the SSO tag to use when CPT submits work to SSO. */
#else /* Word 2 - Little Endian */
        uint64_t tag                   : 32; /**< [159:128] If [WQ_PTR] is nonzero, the SSO tag to use when CPT submits work to SSO. */
        uint64_t tt                    : 2;  /**< [161:160] If [WQ_PTR] is nonzero, the SSO tag type to use when CPT submits work to SSO. */
        uint64_t grp                   : 10; /**< [171:162] If [WQ_PTR] is nonzero, the SSO guest-group to use when CPT submits work to
                                                                 SSO.
                                                                 For the SSO to not discard the add-work request, FPA_PF_MAP() must map
                                                                 [GRP] and CPT()_PF_Q()_GMCTL[GMID] as valid. */
        uint64_t reserved_172_191      : 20;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t wq_ptr                : 64; /**< [255:192] If [WQ_PTR] is nonzero, it is a pointer to a work-queue entry that CPT submits
                                                                 work to SSO after all context, output data, and result write operations are
                                                                 visible to other CNXXXX units and the cores.

                                                                 Bits <2:0> must be zero.  Bits <63:49> are ignored by hardware; software should
                                                                 use a sign-extended bit <48> for forward compatibility.

                                                                 Internal:
                                                                 Bits <63:49>, <2:0> are ignored by hardware, treated as always 0x0. */
#else /* Word 3 - Little Endian */
        uint64_t wq_ptr                : 64; /**< [255:192] If [WQ_PTR] is nonzero, it is a pointer to a work-queue entry that CPT submits
                                                                 work to SSO after all context, output data, and result write operations are
                                                                 visible to other CNXXXX units and the cores.

                                                                 Bits <2:0> must be zero.  Bits <63:49> are ignored by hardware; software should
                                                                 use a sign-extended bit <48> for forward compatibility.

                                                                 Internal:
                                                                 Bits <63:49>, <2:0> are ignored by hardware, treated as always 0x0. */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t ei0                   : 64; /**< [319:256] Engine instruction word 0. Passed to the AE/SE. */
#else /* Word 4 - Little Endian */
        uint64_t ei0                   : 64; /**< [319:256] Engine instruction word 0. Passed to the AE/SE. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t ei1                   : 64; /**< [383:320] Engine instruction word 1. Passed to the AE/SE. */
#else /* Word 5 - Little Endian */
        uint64_t ei1                   : 64; /**< [383:320] Engine instruction word 1. Passed to the AE/SE. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t ei2                   : 64; /**< [447:384] Engine instruction word 2. Passed to the AE/SE. */
#else /* Word 6 - Little Endian */
        uint64_t ei2                   : 64; /**< [447:384] Engine instruction word 2. Passed to the AE/SE. */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t ei3                   : 64; /**< [511:448] Engine instruction word 3. Passed to the AE/SE. */
#else /* Word 7 - Little Endian */
        uint64_t ei3                   : 64; /**< [511:448] Engine instruction word 3. Passed to the AE/SE. */
#endif /* Word 7 - End */
    } cn;
};

/**
 * Structure cpt_res_s
 *
 * CPT Result Structure
 * The CPT coprocessor writes the result structure after it completes a CPT_INST_S
 * instruction. The result structure is exactly 16 bytes, and each instruction
 * completion produces exactly one result structure.
 *
 * This structure is stored in memory as little-endian unless CPT()_PF_Q()_CTL[INST_BE]
 * is set.
 */
union bdk_cpt_res_s
{
    uint64_t u[2];
    struct bdk_cpt_res_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt. This bit is copied from the corresponding instruction's
                                                                 CPT_INST_S[DONEINT]. */
        uint64_t reserved_8_15         : 8;
        uint64_t compcode              : 8;  /**< [  7:  0] Indicates completion/error status of the CPT coprocessor for the
                                                                 associated instruction, as enumerated by CPT_COMP_E. Core
                                                                 software may write the memory location containing [COMPCODE] to 0x0
                                                                 before ringing the doorbell, and then poll for completion by
                                                                 checking for a nonzero value.

                                                                 Once the core observes a nonzero [COMPCODE] value in this case, the CPT
                                                                 coprocessor will have also completed L2/DRAM write operations. */
#else /* Word 0 - Little Endian */
        uint64_t compcode              : 8;  /**< [  7:  0] Indicates completion/error status of the CPT coprocessor for the
                                                                 associated instruction, as enumerated by CPT_COMP_E. Core
                                                                 software may write the memory location containing [COMPCODE] to 0x0
                                                                 before ringing the doorbell, and then poll for completion by
                                                                 checking for a nonzero value.

                                                                 Once the core observes a nonzero [COMPCODE] value in this case, the CPT
                                                                 coprocessor will have also completed L2/DRAM write operations. */
        uint64_t reserved_8_15         : 8;
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt. This bit is copied from the corresponding instruction's
                                                                 CPT_INST_S[DONEINT]. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_64_127       : 64;
#else /* Word 1 - Little Endian */
        uint64_t reserved_64_127       : 64;
#endif /* Word 1 - End */
    } s;
    /* struct bdk_cpt_res_s_s cn; */
};

/**
 * Register (NCB) cpt#_bridge_bp_test
 *
 * INTERNAL: CPT PF Backpressure Test Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_bridge_bp_test_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 5;  /**< [ 63: 59](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = EPCO fifo.
                                                                 <62> = CDEI fifo
                                                                 <61> = EPCI outbound arb.
                                                                 <60> = Instruction request.
                                                                 <59> = Completion arb. */
        uint64_t reserved_24_58        : 35;
        uint64_t bp_cfg                : 10; /**< [ 23: 14](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   <23:22> = EPCO_CFG.
                                                                   <21:20> = CDEI_CFG.
                                                                   <19:18> = EPCI_CFG.
                                                                   <17:16> = INST_CFG.
                                                                   <15:14> = COMP_CFG. */
        uint64_t reserved_12_13        : 2;
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
#else /* Word 0 - Little Endian */
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
        uint64_t reserved_12_13        : 2;
        uint64_t bp_cfg                : 10; /**< [ 23: 14](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   <23:22> = EPCO_CFG.
                                                                   <21:20> = CDEI_CFG.
                                                                   <19:18> = EPCI_CFG.
                                                                   <17:16> = INST_CFG.
                                                                   <15:14> = COMP_CFG. */
        uint64_t reserved_24_58        : 35;
        uint64_t enable                : 5;  /**< [ 63: 59](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = EPCO fifo.
                                                                 <62> = CDEI fifo
                                                                 <61> = EPCI outbound arb.
                                                                 <60> = Instruction request.
                                                                 <59> = Completion arb. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_bridge_bp_test_s cn; */
} bdk_cptx_bridge_bp_test_t;

static inline uint64_t BDK_CPTX_BRIDGE_BP_TEST(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_BRIDGE_BP_TEST(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x8720000001c0ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x8720000001c0ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x8720000001c0ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_BRIDGE_BP_TEST", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_BRIDGE_BP_TEST(a) bdk_cptx_bridge_bp_test_t
#define bustype_BDK_CPTX_BRIDGE_BP_TEST(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_BRIDGE_BP_TEST(a) "CPTX_BRIDGE_BP_TEST"
#define device_bar_BDK_CPTX_BRIDGE_BP_TEST(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_BRIDGE_BP_TEST(a) (a)
#define arguments_BDK_CPTX_BRIDGE_BP_TEST(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_cqm_core_obs0
 *
 * INTERNAL: CPT CQM Core Observability Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_cqm_core_obs0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t instfif7_cnt          : 8;  /**< [ 63: 56](RO/H) Number of instruction words prefetched for group 7. */
        uint64_t instfif6_cnt          : 8;  /**< [ 55: 48](RO/H) Number of instruction words prefetched for group 6. */
        uint64_t instfif5_cnt          : 8;  /**< [ 47: 40](RO/H) Number of instruction words prefetched for group 5. */
        uint64_t instfif4_cnt          : 8;  /**< [ 39: 32](RO/H) Number of instruction words prefetched for group 4. */
        uint64_t instfif3_cnt          : 8;  /**< [ 31: 24](RO/H) Number of instruction words prefetched for group 3. */
        uint64_t instfif2_cnt          : 8;  /**< [ 23: 16](RO/H) Number of instruction words prefetched for group 2. */
        uint64_t instfif1_cnt          : 8;  /**< [ 15:  8](RO/H) Number of instruction words prefetched for group 1. */
        uint64_t instfif0_cnt          : 8;  /**< [  7:  0](RO/H) Number of instruction words prefetched for group 0. */
#else /* Word 0 - Little Endian */
        uint64_t instfif0_cnt          : 8;  /**< [  7:  0](RO/H) Number of instruction words prefetched for group 0. */
        uint64_t instfif1_cnt          : 8;  /**< [ 15:  8](RO/H) Number of instruction words prefetched for group 1. */
        uint64_t instfif2_cnt          : 8;  /**< [ 23: 16](RO/H) Number of instruction words prefetched for group 2. */
        uint64_t instfif3_cnt          : 8;  /**< [ 31: 24](RO/H) Number of instruction words prefetched for group 3. */
        uint64_t instfif4_cnt          : 8;  /**< [ 39: 32](RO/H) Number of instruction words prefetched for group 4. */
        uint64_t instfif5_cnt          : 8;  /**< [ 47: 40](RO/H) Number of instruction words prefetched for group 5. */
        uint64_t instfif6_cnt          : 8;  /**< [ 55: 48](RO/H) Number of instruction words prefetched for group 6. */
        uint64_t instfif7_cnt          : 8;  /**< [ 63: 56](RO/H) Number of instruction words prefetched for group 7. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_cqm_core_obs0_s cn; */
} bdk_cptx_cqm_core_obs0_t;

static inline uint64_t BDK_CPTX_CQM_CORE_OBS0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_CQM_CORE_OBS0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x8720000001a0ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x8720000001a0ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x8720000001a0ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_CQM_CORE_OBS0", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_CQM_CORE_OBS0(a) bdk_cptx_cqm_core_obs0_t
#define bustype_BDK_CPTX_CQM_CORE_OBS0(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_CQM_CORE_OBS0(a) "CPTX_CQM_CORE_OBS0"
#define device_bar_BDK_CPTX_CQM_CORE_OBS0(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_CQM_CORE_OBS0(a) (a)
#define arguments_BDK_CPTX_CQM_CORE_OBS0(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_cqm_core_obs1
 *
 * INTERNAL: CPT CQM Core Observability Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_cqm_core_obs1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_50_63        : 14;
        uint64_t ncbi_ptr_req          : 1;  /**< [ 49: 49](RO/H) CQM_CORE is waiting to issue an NCBI Request for instruction pointer fetch */
        uint64_t ncbi_req_rdy          : 1;  /**< [ 48: 48](RO/H) CQM_CORE is waiting to issue an NCBI Request for instruction fetch */
        uint64_t grp_rdy_hi_pri        : 8;  /**< [ 47: 40](RO/H) If set the corresponding group has high priority queues waiting to fetch
                                                                 instructions. */
        uint64_t grp_rdy_lo_pri        : 8;  /**< [ 39: 32](RO/H) If set the corresponding group has low priority queues waiting to fetch */
        uint64_t vqfif7_cnt            : 4;  /**< [ 31: 28](RO/H) Number of instructions getting prefetched for group 7. */
        uint64_t vqfif6_cnt            : 4;  /**< [ 27: 24](RO/H) Number of instructions getting prefetched for group 6. */
        uint64_t vqfif5_cnt            : 4;  /**< [ 23: 20](RO/H) Number of instructions getting prefetched for group 5. */
        uint64_t vqfif4_cnt            : 4;  /**< [ 19: 16](RO/H) Number of instructions getting prefetched for group 4. */
        uint64_t vqfif3_cnt            : 4;  /**< [ 15: 12](RO/H) Number of instructions getting prefetched for group 3. */
        uint64_t vqfif2_cnt            : 4;  /**< [ 11:  8](RO/H) Number of instructions getting prefetched for group 2. */
        uint64_t vqfif1_cnt            : 4;  /**< [  7:  4](RO/H) Number of instructions getting prefetched for group 1. */
        uint64_t vqfif0_cnt            : 4;  /**< [  3:  0](RO/H) Number of instructions getting prefetched for group 0. */
#else /* Word 0 - Little Endian */
        uint64_t vqfif0_cnt            : 4;  /**< [  3:  0](RO/H) Number of instructions getting prefetched for group 0. */
        uint64_t vqfif1_cnt            : 4;  /**< [  7:  4](RO/H) Number of instructions getting prefetched for group 1. */
        uint64_t vqfif2_cnt            : 4;  /**< [ 11:  8](RO/H) Number of instructions getting prefetched for group 2. */
        uint64_t vqfif3_cnt            : 4;  /**< [ 15: 12](RO/H) Number of instructions getting prefetched for group 3. */
        uint64_t vqfif4_cnt            : 4;  /**< [ 19: 16](RO/H) Number of instructions getting prefetched for group 4. */
        uint64_t vqfif5_cnt            : 4;  /**< [ 23: 20](RO/H) Number of instructions getting prefetched for group 5. */
        uint64_t vqfif6_cnt            : 4;  /**< [ 27: 24](RO/H) Number of instructions getting prefetched for group 6. */
        uint64_t vqfif7_cnt            : 4;  /**< [ 31: 28](RO/H) Number of instructions getting prefetched for group 7. */
        uint64_t grp_rdy_lo_pri        : 8;  /**< [ 39: 32](RO/H) If set the corresponding group has low priority queues waiting to fetch */
        uint64_t grp_rdy_hi_pri        : 8;  /**< [ 47: 40](RO/H) If set the corresponding group has high priority queues waiting to fetch
                                                                 instructions. */
        uint64_t ncbi_req_rdy          : 1;  /**< [ 48: 48](RO/H) CQM_CORE is waiting to issue an NCBI Request for instruction fetch */
        uint64_t ncbi_ptr_req          : 1;  /**< [ 49: 49](RO/H) CQM_CORE is waiting to issue an NCBI Request for instruction pointer fetch */
        uint64_t reserved_50_63        : 14;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_cqm_core_obs1_s cn; */
} bdk_cptx_cqm_core_obs1_t;

static inline uint64_t BDK_CPTX_CQM_CORE_OBS1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_CQM_CORE_OBS1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x8720000001a8ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x8720000001a8ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x8720000001a8ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_CQM_CORE_OBS1", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_CQM_CORE_OBS1(a) bdk_cptx_cqm_core_obs1_t
#define bustype_BDK_CPTX_CQM_CORE_OBS1(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_CQM_CORE_OBS1(a) "CPTX_CQM_CORE_OBS1"
#define device_bar_BDK_CPTX_CQM_CORE_OBS1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_CQM_CORE_OBS1(a) (a)
#define arguments_BDK_CPTX_CQM_CORE_OBS1(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_ncbi_obs
 *
 * INTERNAL: CPT NCBI Observability Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_ncbi_obs_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t datfif_cnt            : 8;  /**< [ 39: 32](RO/H) Number of pending data cycles to be sent to NCBI. */
        uint64_t cmdfif_cnt            : 8;  /**< [ 31: 24](RO/H) Number of pending commands to be sent to NCBI. */
        uint64_t reserved_22_23        : 2;
        uint64_t csr_rsp_dat           : 1;  /**< [ 21: 21](RO/H) CSR Response data available to be sent to NCBI.                                            . */
        uint64_t csr_rsp_val           : 1;  /**< [ 20: 20](RO/H) CSR Response available to be sent to NCBI. */
        uint64_t csr_cc_req            : 4;  /**< [ 19: 16](RO/H) Transfer cycles requested for CSR responses. */
        uint64_t res_cc_req            : 4;  /**< [ 15: 12](RO/H) Transfer cycles requested for result structure stores. */
        uint64_t ifc_cc_req            : 4;  /**< [ 11:  8](RO/H) Transfer cycles requested for instruction fetches. */
        uint64_t eng_cc_req            : 4;  /**< [  7:  4](RO/H) Transfer cycles requested from the engines. */
        uint64_t cdei_cc_left          : 4;  /**< [  3:  0](RO/H) Transfer cycles remaining to complete receiving transaction from CPT_NCBI input. */
#else /* Word 0 - Little Endian */
        uint64_t cdei_cc_left          : 4;  /**< [  3:  0](RO/H) Transfer cycles remaining to complete receiving transaction from CPT_NCBI input. */
        uint64_t eng_cc_req            : 4;  /**< [  7:  4](RO/H) Transfer cycles requested from the engines. */
        uint64_t ifc_cc_req            : 4;  /**< [ 11:  8](RO/H) Transfer cycles requested for instruction fetches. */
        uint64_t res_cc_req            : 4;  /**< [ 15: 12](RO/H) Transfer cycles requested for result structure stores. */
        uint64_t csr_cc_req            : 4;  /**< [ 19: 16](RO/H) Transfer cycles requested for CSR responses. */
        uint64_t csr_rsp_val           : 1;  /**< [ 20: 20](RO/H) CSR Response available to be sent to NCBI. */
        uint64_t csr_rsp_dat           : 1;  /**< [ 21: 21](RO/H) CSR Response data available to be sent to NCBI.                                            . */
        uint64_t reserved_22_23        : 2;
        uint64_t cmdfif_cnt            : 8;  /**< [ 31: 24](RO/H) Number of pending commands to be sent to NCBI. */
        uint64_t datfif_cnt            : 8;  /**< [ 39: 32](RO/H) Number of pending data cycles to be sent to NCBI. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_ncbi_obs_s cn; */
} bdk_cptx_ncbi_obs_t;

static inline uint64_t BDK_CPTX_NCBI_OBS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_NCBI_OBS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000190ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000190ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000190ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_NCBI_OBS", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_NCBI_OBS(a) bdk_cptx_ncbi_obs_t
#define bustype_BDK_CPTX_NCBI_OBS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_NCBI_OBS(a) "CPTX_NCBI_OBS"
#define device_bar_BDK_CPTX_NCBI_OBS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_NCBI_OBS(a) (a)
#define arguments_BDK_CPTX_NCBI_OBS(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_active_cycles_pc
 *
 * CPT PF Active Cycles Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_active_cycles_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t act_cyc               : 64; /**< [ 63:  0](RO/H) Counts every coprocessor-clock cycle that the conditional clocks are active.
                                                                 Internal:
                                                                 Includes CDE internal or any engine clock being enabled. */
#else /* Word 0 - Little Endian */
        uint64_t act_cyc               : 64; /**< [ 63:  0](RO/H) Counts every coprocessor-clock cycle that the conditional clocks are active.
                                                                 Internal:
                                                                 Includes CDE internal or any engine clock being enabled. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_active_cycles_pc_s cn; */
} bdk_cptx_pf_active_cycles_pc_t;

static inline uint64_t BDK_CPTX_PF_ACTIVE_CYCLES_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_ACTIVE_CYCLES_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000010100ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000010100ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000010100ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_ACTIVE_CYCLES_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_ACTIVE_CYCLES_PC(a) bdk_cptx_pf_active_cycles_pc_t
#define bustype_BDK_CPTX_PF_ACTIVE_CYCLES_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_ACTIVE_CYCLES_PC(a) "CPTX_PF_ACTIVE_CYCLES_PC"
#define device_bar_BDK_CPTX_PF_ACTIVE_CYCLES_PC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_ACTIVE_CYCLES_PC(a) (a)
#define arguments_BDK_CPTX_PF_ACTIVE_CYCLES_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_bist_status
 *
 * CPT PF Control Bist Status Register
 * This register has the BIST status of memories. Each bit is the BIST result of an
 * individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t bstatus               : 30; /**< [ 29:  0](RO/H) BIST status. One bit per memory, enumerated by CPT_RAMS_E. */
#else /* Word 0 - Little Endian */
        uint64_t bstatus               : 30; /**< [ 29:  0](RO/H) BIST status. One bit per memory, enumerated by CPT_RAMS_E. */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_bist_status_s cn; */
} bdk_cptx_pf_bist_status_t;

static inline uint64_t BDK_CPTX_PF_BIST_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_BIST_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000160ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000160ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000160ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_BIST_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_BIST_STATUS(a) bdk_cptx_pf_bist_status_t
#define bustype_BDK_CPTX_PF_BIST_STATUS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_BIST_STATUS(a) "CPTX_PF_BIST_STATUS"
#define device_bar_BDK_CPTX_PF_BIST_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_BIST_STATUS(a) (a)
#define arguments_BDK_CPTX_PF_BIST_STATUS(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_bp_test
 *
 * INTERNAL: CPT PF Backpressure Test Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_bp_test_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = NCBI requests.
                                                                 <62> = Instruction prefetching.
                                                                 <61> = Reserved.
                                                                 <60> = Reserved. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_12_15        : 4;
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
#else /* Word 0 - Little Endian */
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
        uint64_t reserved_12_15        : 4;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = NCBI requests.
                                                                 <62> = Instruction prefetching.
                                                                 <61> = Reserved.
                                                                 <60> = Reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_bp_test_s cn; */
} bdk_cptx_pf_bp_test_t;

static inline uint64_t BDK_CPTX_PF_BP_TEST(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_BP_TEST(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000180ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000180ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000180ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_BP_TEST", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_BP_TEST(a) bdk_cptx_pf_bp_test_t
#define bustype_BDK_CPTX_PF_BP_TEST(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_BP_TEST(a) "CPTX_PF_BP_TEST"
#define device_bar_BDK_CPTX_PF_BP_TEST(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_BP_TEST(a) (a)
#define arguments_BDK_CPTX_PF_BP_TEST(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_constants
 *
 * CPT PF Constants Register
 * This register contains implementation-related parameters of CPT in CNXXXX.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_constants_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t epcis                 : 8;  /**< [ 39: 32](RO) Number of EPCI busses. */
        uint64_t grps                  : 8;  /**< [ 31: 24](RO) Number of engine groups implemented. */
        uint64_t ae                    : 8;  /**< [ 23: 16](RO/H) Number of AEs. In CNXXXX, for CPT0 returns 0x0, for CPT1 returns 0x18, or less
                                                                 if there are fuse-disables. */
        uint64_t se                    : 8;  /**< [ 15:  8](RO/H) Number of SEs. In CNXXXX, for CPT0 returns 0x30, or less if there are
                                                                 fuse-disables, for CPT1 returns 0x0. */
        uint64_t vq                    : 8;  /**< [  7:  0](RO) Number of VQs. */
#else /* Word 0 - Little Endian */
        uint64_t vq                    : 8;  /**< [  7:  0](RO) Number of VQs. */
        uint64_t se                    : 8;  /**< [ 15:  8](RO/H) Number of SEs. In CNXXXX, for CPT0 returns 0x30, or less if there are
                                                                 fuse-disables, for CPT1 returns 0x0. */
        uint64_t ae                    : 8;  /**< [ 23: 16](RO/H) Number of AEs. In CNXXXX, for CPT0 returns 0x0, for CPT1 returns 0x18, or less
                                                                 if there are fuse-disables. */
        uint64_t grps                  : 8;  /**< [ 31: 24](RO) Number of engine groups implemented. */
        uint64_t epcis                 : 8;  /**< [ 39: 32](RO) Number of EPCI busses. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_pf_constants_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t epcis                 : 8;  /**< [ 39: 32](RO) Number of EPCI busses. */
        uint64_t grps                  : 8;  /**< [ 31: 24](RO) Number of engine groups implemented. */
        uint64_t ae                    : 8;  /**< [ 23: 16](RO/H) Number of AEs. In CNXXXX, returns 0x6 or less if there are fuse-disables. */
        uint64_t se                    : 8;  /**< [ 15:  8](RO/H) Number of SEs. In CNXXXX, returns 0xA, or less if there are fuse-disables. */
        uint64_t vq                    : 8;  /**< [  7:  0](RO) Number of VQs. */
#else /* Word 0 - Little Endian */
        uint64_t vq                    : 8;  /**< [  7:  0](RO) Number of VQs. */
        uint64_t se                    : 8;  /**< [ 15:  8](RO/H) Number of SEs. In CNXXXX, returns 0xA, or less if there are fuse-disables. */
        uint64_t ae                    : 8;  /**< [ 23: 16](RO/H) Number of AEs. In CNXXXX, returns 0x6 or less if there are fuse-disables. */
        uint64_t grps                  : 8;  /**< [ 31: 24](RO) Number of engine groups implemented. */
        uint64_t epcis                 : 8;  /**< [ 39: 32](RO) Number of EPCI busses. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_pf_constants_s cn83xx; */
    /* struct bdk_cptx_pf_constants_s cn9; */
} bdk_cptx_pf_constants_t;

static inline uint64_t BDK_CPTX_PF_CONSTANTS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_CONSTANTS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000000ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000000ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000000ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_CONSTANTS", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_CONSTANTS(a) bdk_cptx_pf_constants_t
#define bustype_BDK_CPTX_PF_CONSTANTS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_CONSTANTS(a) "CPTX_PF_CONSTANTS"
#define device_bar_BDK_CPTX_PF_CONSTANTS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_CONSTANTS(a) (a)
#define arguments_BDK_CPTX_PF_CONSTANTS(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_diag
 *
 * CPT PF Diagnostic Control Register
 * This register controls diagnostic features.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_diag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t forceclk              : 1;  /**< [  8:  8](R/W) When this bit is set to 1, it forces CPT clocks on. For diagnostic use only. */
        uint64_t ld_infl               : 8;  /**< [  7:  0](R/W) Maximum number of in-flight data fetch transactions on the NCB. Larger values
                                                                 may improve CPT performance but may starve other devices on the same NCB. Values
                                                                 > 64 are treated as 64. */
#else /* Word 0 - Little Endian */
        uint64_t ld_infl               : 8;  /**< [  7:  0](R/W) Maximum number of in-flight data fetch transactions on the NCB. Larger values
                                                                 may improve CPT performance but may starve other devices on the same NCB. Values
                                                                 > 64 are treated as 64. */
        uint64_t forceclk              : 1;  /**< [  8:  8](R/W) When this bit is set to 1, it forces CPT clocks on. For diagnostic use only. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_diag_s cn; */
} bdk_cptx_pf_diag_t;

static inline uint64_t BDK_CPTX_PF_DIAG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_DIAG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000120ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000120ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000120ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_DIAG", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_DIAG(a) bdk_cptx_pf_diag_t
#define bustype_BDK_CPTX_PF_DIAG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_DIAG(a) "CPTX_PF_DIAG"
#define device_bar_BDK_CPTX_PF_DIAG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_DIAG(a) (a)
#define arguments_BDK_CPTX_PF_DIAG(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_ecc0_ctl
 *
 * CPT PF ECC Control Register
 * This register enables ECC for each individual internal memory that requires ECC. For debug
 * purposes, it can also flip one or two bits in the ECC data.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_ecc0_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t cdis                  : 32; /**< [ 31:  0](R/W) Disables ECC correction on each RAM.  Bit positions enumerated with CPT_RAMS_E. */
#else /* Word 0 - Little Endian */
        uint64_t cdis                  : 32; /**< [ 31:  0](R/W) Disables ECC correction on each RAM.  Bit positions enumerated with CPT_RAMS_E. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_ecc0_ctl_s cn; */
} bdk_cptx_pf_ecc0_ctl_t;

static inline uint64_t BDK_CPTX_PF_ECC0_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_ECC0_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000200ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000200ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000200ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_ECC0_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_ECC0_CTL(a) bdk_cptx_pf_ecc0_ctl_t
#define bustype_BDK_CPTX_PF_ECC0_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_ECC0_CTL(a) "CPTX_PF_ECC0_CTL"
#define device_bar_BDK_CPTX_PF_ECC0_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_ECC0_CTL(a) (a)
#define arguments_BDK_CPTX_PF_ECC0_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_ecc0_ena_w1c
 *
 * CPT ECC Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_ecc0_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1C/H) Reads or clears enable for CPT(0..1)_PF_ECC0_INT[DBE]. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1C/H) Reads or clears enable for CPT(0..1)_PF_ECC0_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1C/H) Reads or clears enable for CPT(0..1)_PF_ECC0_INT[SBE]. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1C/H) Reads or clears enable for CPT(0..1)_PF_ECC0_INT[DBE]. */
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_pf_ecc0_ena_w1c_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1C/H) Reads or clears enable for CPT(0)_PF_ECC0_INT[DBE]. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1C/H) Reads or clears enable for CPT(0)_PF_ECC0_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1C/H) Reads or clears enable for CPT(0)_PF_ECC0_INT[SBE]. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1C/H) Reads or clears enable for CPT(0)_PF_ECC0_INT[DBE]. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_pf_ecc0_ena_w1c_s cn83xx; */
    /* struct bdk_cptx_pf_ecc0_ena_w1c_s cn9; */
} bdk_cptx_pf_ecc0_ena_w1c_t;

static inline uint64_t BDK_CPTX_PF_ECC0_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_ECC0_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000250ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000250ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000250ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_ECC0_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_ECC0_ENA_W1C(a) bdk_cptx_pf_ecc0_ena_w1c_t
#define bustype_BDK_CPTX_PF_ECC0_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_ECC0_ENA_W1C(a) "CPTX_PF_ECC0_ENA_W1C"
#define device_bar_BDK_CPTX_PF_ECC0_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_ECC0_ENA_W1C(a) (a)
#define arguments_BDK_CPTX_PF_ECC0_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_ecc0_ena_w1s
 *
 * CPT ECC Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_ecc0_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets enable for CPT(0..1)_PF_ECC0_INT[DBE]. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets enable for CPT(0..1)_PF_ECC0_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets enable for CPT(0..1)_PF_ECC0_INT[SBE]. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets enable for CPT(0..1)_PF_ECC0_INT[DBE]. */
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_pf_ecc0_ena_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets enable for CPT(0)_PF_ECC0_INT[DBE]. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets enable for CPT(0)_PF_ECC0_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets enable for CPT(0)_PF_ECC0_INT[SBE]. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets enable for CPT(0)_PF_ECC0_INT[DBE]. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_pf_ecc0_ena_w1s_s cn83xx; */
    /* struct bdk_cptx_pf_ecc0_ena_w1s_s cn9; */
} bdk_cptx_pf_ecc0_ena_w1s_t;

static inline uint64_t BDK_CPTX_PF_ECC0_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_ECC0_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000240ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000240ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000240ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_ECC0_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_ECC0_ENA_W1S(a) bdk_cptx_pf_ecc0_ena_w1s_t
#define bustype_BDK_CPTX_PF_ECC0_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_ECC0_ENA_W1S(a) "CPTX_PF_ECC0_ENA_W1S"
#define device_bar_BDK_CPTX_PF_ECC0_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_ECC0_ENA_W1S(a) (a)
#define arguments_BDK_CPTX_PF_ECC0_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_ecc0_flip
 *
 * CPT PF ECC Flip Syndrome Register
 * This register enables ECC for each individual internal memory that requires ECC. For debug
 * purposes, it can also flip one or two bits in the ECC data.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_ecc0_flip_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t flip1                 : 32; /**< [ 63: 32](R/W) Flips syndome bit 1 on writes.  Bit positions enumerated with CPT_RAMS_E. */
        uint64_t flip0                 : 32; /**< [ 31:  0](R/W) Flips syndome bit 0 on writes.  Bit positions enumerated with CPT_RAMS_E. */
#else /* Word 0 - Little Endian */
        uint64_t flip0                 : 32; /**< [ 31:  0](R/W) Flips syndome bit 0 on writes.  Bit positions enumerated with CPT_RAMS_E. */
        uint64_t flip1                 : 32; /**< [ 63: 32](R/W) Flips syndome bit 1 on writes.  Bit positions enumerated with CPT_RAMS_E. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_ecc0_flip_s cn; */
} bdk_cptx_pf_ecc0_flip_t;

static inline uint64_t BDK_CPTX_PF_ECC0_FLIP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_ECC0_FLIP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000210ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000210ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000210ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_ECC0_FLIP", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_ECC0_FLIP(a) bdk_cptx_pf_ecc0_flip_t
#define bustype_BDK_CPTX_PF_ECC0_FLIP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_ECC0_FLIP(a) "CPTX_PF_ECC0_FLIP"
#define device_bar_BDK_CPTX_PF_ECC0_FLIP(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_ECC0_FLIP(a) (a)
#define arguments_BDK_CPTX_PF_ECC0_FLIP(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_ecc0_int
 *
 * CPT ECC Interrupt Status Register
 * This register contains the status of the ECC interrupt sources.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_ecc0_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1C/H) Double-bit error detected in internal RAM. One bit per memory, enumerated by
                                                                 CPT_RAMS_E. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1C/H) Single-bit error detected in internal RAM. One bit per memory, enumerated by
                                                                 CPT_RAMS_E. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1C/H) Single-bit error detected in internal RAM. One bit per memory, enumerated by
                                                                 CPT_RAMS_E. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1C/H) Double-bit error detected in internal RAM. One bit per memory, enumerated by
                                                                 CPT_RAMS_E. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_ecc0_int_s cn; */
} bdk_cptx_pf_ecc0_int_t;

static inline uint64_t BDK_CPTX_PF_ECC0_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_ECC0_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000220ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000220ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000220ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_ECC0_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_ECC0_INT(a) bdk_cptx_pf_ecc0_int_t
#define bustype_BDK_CPTX_PF_ECC0_INT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_ECC0_INT(a) "CPTX_PF_ECC0_INT"
#define device_bar_BDK_CPTX_PF_ECC0_INT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_ECC0_INT(a) (a)
#define arguments_BDK_CPTX_PF_ECC0_INT(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_ecc0_int_w1s
 *
 * CPT ECC Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_ecc0_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets CPT(0..1)_PF_ECC0_INT[DBE]. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets CPT(0..1)_PF_ECC0_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets CPT(0..1)_PF_ECC0_INT[SBE]. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets CPT(0..1)_PF_ECC0_INT[DBE]. */
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_pf_ecc0_int_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets CPT(0)_PF_ECC0_INT[DBE]. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets CPT(0)_PF_ECC0_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets CPT(0)_PF_ECC0_INT[SBE]. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets CPT(0)_PF_ECC0_INT[DBE]. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_pf_ecc0_int_w1s_s cn83xx; */
    /* struct bdk_cptx_pf_ecc0_int_w1s_s cn9; */
} bdk_cptx_pf_ecc0_int_w1s_t;

static inline uint64_t BDK_CPTX_PF_ECC0_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_ECC0_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000230ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000230ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000230ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_ECC0_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_ECC0_INT_W1S(a) bdk_cptx_pf_ecc0_int_w1s_t
#define bustype_BDK_CPTX_PF_ECC0_INT_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_ECC0_INT_W1S(a) "CPTX_PF_ECC0_INT_W1S"
#define device_bar_BDK_CPTX_PF_ECC0_INT_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_ECC0_INT_W1S(a) (a)
#define arguments_BDK_CPTX_PF_ECC0_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_eco
 *
 * INTERNAL: CPT PF ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_eco_s cn; */
} bdk_cptx_pf_eco_t;

static inline uint64_t BDK_CPTX_PF_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_ECO(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000140ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000140ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000140ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_ECO", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_ECO(a) bdk_cptx_pf_eco_t
#define bustype_BDK_CPTX_PF_ECO(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_ECO(a) "CPTX_PF_ECO"
#define device_bar_BDK_CPTX_PF_ECO(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_ECO(a) (a)
#define arguments_BDK_CPTX_PF_ECO(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_eng#_ucode_base
 *
 * CPT PF Engine Microcode Base Address Register
 * This register configures engine microcode fetches.
 *
 * Only indicies 0x0 to (CPT(0)_PF_CONSTANTS[AE] + CPT(0)_PF_CONSTANTS[SE] - 1) are
 * supported.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_engx_ucode_base_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 42; /**< [ 48:  7](R/W) Base IOVA for this engine's microcode image. */
        uint64_t reserved_0_6          : 7;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_6          : 7;
        uint64_t addr                  : 42; /**< [ 48:  7](R/W) Base IOVA for this engine's microcode image. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_engx_ucode_base_s cn; */
} bdk_cptx_pf_engx_ucode_base_t;

static inline uint64_t BDK_CPTX_PF_ENGX_UCODE_BASE(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_ENGX_UCODE_BASE(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=47)))
        return 0x872004002000ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=47)))
        return 0x872004002000ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=47)))
        return 0x872004002000ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_PF_ENGX_UCODE_BASE", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_ENGX_UCODE_BASE(a,b) bdk_cptx_pf_engx_ucode_base_t
#define bustype_BDK_CPTX_PF_ENGX_UCODE_BASE(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_ENGX_UCODE_BASE(a,b) "CPTX_PF_ENGX_UCODE_BASE"
#define device_bar_BDK_CPTX_PF_ENGX_UCODE_BASE(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_ENGX_UCODE_BASE(a,b) (a)
#define arguments_BDK_CPTX_PF_ENGX_UCODE_BASE(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_exe_bist_status
 *
 * CPT PF Engine Bist Status Register
 * This register has the BIST status of each engine.  Each bit is the BIST result of an
 * individual engine (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exe_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t bstatus               : 48; /**< [ 47:  0](RO/H) BIST status. One bit per engine. */
#else /* Word 0 - Little Endian */
        uint64_t bstatus               : 48; /**< [ 47:  0](RO/H) BIST status. One bit per engine. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_pf_exe_bist_status_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t bstatus               : 16; /**< [ 15:  0](RO/H) BIST status. One bit per engine. */
#else /* Word 0 - Little Endian */
        uint64_t bstatus               : 16; /**< [ 15:  0](RO/H) BIST status. One bit per engine. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_pf_exe_bist_status_s cn83xx; */
    /* struct bdk_cptx_pf_exe_bist_status_s cn9; */
} bdk_cptx_pf_exe_bist_status_t;

static inline uint64_t BDK_CPTX_PF_EXE_BIST_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXE_BIST_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872004000028ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872004000028ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872004000028ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXE_BIST_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXE_BIST_STATUS(a) bdk_cptx_pf_exe_bist_status_t
#define bustype_BDK_CPTX_PF_EXE_BIST_STATUS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXE_BIST_STATUS(a) "CPTX_PF_EXE_BIST_STATUS"
#define device_bar_BDK_CPTX_PF_EXE_BIST_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXE_BIST_STATUS(a) (a)
#define arguments_BDK_CPTX_PF_EXE_BIST_STATUS(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exe_clk
 *
 * CPT PF Engine Clock Register
 * This register forces engine clocks on.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exe_clk_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t forceclk              : 64; /**< [ 63:  0](R/W) Clock override, one bit per engine. When set, force clocks to always run. When
                                                                 clear, allow automatic powerdown for idle engines. */
#else /* Word 0 - Little Endian */
        uint64_t forceclk              : 64; /**< [ 63:  0](R/W) Clock override, one bit per engine. When set, force clocks to always run. When
                                                                 clear, allow automatic powerdown for idle engines. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exe_clk_s cn; */
} bdk_cptx_pf_exe_clk_t;

static inline uint64_t BDK_CPTX_PF_EXE_CLK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXE_CLK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872004000010ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872004000010ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872004000010ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXE_CLK", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXE_CLK(a) bdk_cptx_pf_exe_clk_t
#define bustype_BDK_CPTX_PF_EXE_CLK(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXE_CLK(a) "CPTX_PF_EXE_CLK"
#define device_bar_BDK_CPTX_PF_EXE_CLK(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXE_CLK(a) (a)
#define arguments_BDK_CPTX_PF_EXE_CLK(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exe_ctl
 *
 * CPT PF Engine Control Register
 * This register enables the engines.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exe_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 64; /**< [ 63:  0](R/W) Individual enables for each of the engines. */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 64; /**< [ 63:  0](R/W) Individual enables for each of the engines. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exe_ctl_s cn; */
} bdk_cptx_pf_exe_ctl_t;

static inline uint64_t BDK_CPTX_PF_EXE_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXE_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872004000000ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872004000000ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872004000000ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXE_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXE_CTL(a) bdk_cptx_pf_exe_ctl_t
#define bustype_BDK_CPTX_PF_EXE_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXE_CTL(a) "CPTX_PF_EXE_CTL"
#define device_bar_BDK_CPTX_PF_EXE_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXE_CTL(a) (a)
#define arguments_BDK_CPTX_PF_EXE_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exe_dbg_cnt#
 *
 * Debug Bus Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exe_dbg_cntx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t counter               : 48; /**< [ 47:  0](R/W1C/H) Counts events on the debug bus. */
#else /* Word 0 - Little Endian */
        uint64_t counter               : 48; /**< [ 47:  0](R/W1C/H) Counts events on the debug bus. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exe_dbg_cntx_s cn; */
} bdk_cptx_pf_exe_dbg_cntx_t;

static inline uint64_t BDK_CPTX_PF_EXE_DBG_CNTX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXE_DBG_CNTX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872004001100ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=15)))
        return 0x872004001100ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=15)))
        return 0x872004001100ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0xf);
    __bdk_csr_fatal("CPTX_PF_EXE_DBG_CNTX", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXE_DBG_CNTX(a,b) bdk_cptx_pf_exe_dbg_cntx_t
#define bustype_BDK_CPTX_PF_EXE_DBG_CNTX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXE_DBG_CNTX(a,b) "CPTX_PF_EXE_DBG_CNTX"
#define device_bar_BDK_CPTX_PF_EXE_DBG_CNTX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXE_DBG_CNTX(a,b) (a)
#define arguments_BDK_CPTX_PF_EXE_DBG_CNTX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_exe_dbg_ctl
 *
 * CPT PF Engine Debug Control Register
 * This register controls engine diagnostic features.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exe_dbg_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t eng_sel               : 8;  /**< [ 23: 16](R/W) Engine select. */
        uint64_t reserved_9_15         : 7;
        uint64_t reg_sel               : 9;  /**< [  8:  0](R/W) Debug register select. Setting to all ones returns 0x0 on the debug bus. */
#else /* Word 0 - Little Endian */
        uint64_t reg_sel               : 9;  /**< [  8:  0](R/W) Debug register select. Setting to all ones returns 0x0 on the debug bus. */
        uint64_t reserved_9_15         : 7;
        uint64_t eng_sel               : 8;  /**< [ 23: 16](R/W) Engine select. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exe_dbg_ctl_s cn; */
} bdk_cptx_pf_exe_dbg_ctl_t;

static inline uint64_t BDK_CPTX_PF_EXE_DBG_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXE_DBG_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872004000018ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872004000018ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872004000018ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXE_DBG_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXE_DBG_CTL(a) bdk_cptx_pf_exe_dbg_ctl_t
#define bustype_BDK_CPTX_PF_EXE_DBG_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXE_DBG_CTL(a) "CPTX_PF_EXE_DBG_CTL"
#define device_bar_BDK_CPTX_PF_EXE_DBG_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXE_DBG_CTL(a) (a)
#define arguments_BDK_CPTX_PF_EXE_DBG_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exe_dbg_data
 *
 * Engine Debug Data Register
 * This register returns engine debug data as selected by CPT()_PF_EXE_DBG_CTL.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exe_dbg_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t data                  : 16; /**< [ 15:  0](RO/H) Debug data. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 16; /**< [ 15:  0](RO/H) Debug data. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exe_dbg_data_s cn; */
} bdk_cptx_pf_exe_dbg_data_t;

static inline uint64_t BDK_CPTX_PF_EXE_DBG_DATA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXE_DBG_DATA(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872004000020ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872004000020ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872004000020ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXE_DBG_DATA", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXE_DBG_DATA(a) bdk_cptx_pf_exe_dbg_data_t
#define bustype_BDK_CPTX_PF_EXE_DBG_DATA(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXE_DBG_DATA(a) "CPTX_PF_EXE_DBG_DATA"
#define device_bar_BDK_CPTX_PF_EXE_DBG_DATA(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXE_DBG_DATA(a) (a)
#define arguments_BDK_CPTX_PF_EXE_DBG_DATA(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exe_epci_inb#_cnt
 *
 * EPCI Inbound Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exe_epci_inbx_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t counter               : 48; /**< [ 47:  0](R/W1C/H) Counts the number of valid inbound cycles in EPCI bus. */
#else /* Word 0 - Little Endian */
        uint64_t counter               : 48; /**< [ 47:  0](R/W1C/H) Counts the number of valid inbound cycles in EPCI bus. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exe_epci_inbx_cnt_s cn; */
} bdk_cptx_pf_exe_epci_inbx_cnt_t;

static inline uint64_t BDK_CPTX_PF_EXE_EPCI_INBX_CNT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXE_EPCI_INBX_CNT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b==0)))
        return 0x872004001200ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=1)))
        return 0x872004001200ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=1)))
        return 0x872004001200ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXE_EPCI_INBX_CNT", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXE_EPCI_INBX_CNT(a,b) bdk_cptx_pf_exe_epci_inbx_cnt_t
#define bustype_BDK_CPTX_PF_EXE_EPCI_INBX_CNT(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXE_EPCI_INBX_CNT(a,b) "CPTX_PF_EXE_EPCI_INBX_CNT"
#define device_bar_BDK_CPTX_PF_EXE_EPCI_INBX_CNT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXE_EPCI_INBX_CNT(a,b) (a)
#define arguments_BDK_CPTX_PF_EXE_EPCI_INBX_CNT(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_exe_epci_outb#_cnt
 *
 * EPCI Outbound Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exe_epci_outbx_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t counter               : 48; /**< [ 47:  0](R/W1C/H) Counts the number of valid outbound cycles in EPCI bus. */
#else /* Word 0 - Little Endian */
        uint64_t counter               : 48; /**< [ 47:  0](R/W1C/H) Counts the number of valid outbound cycles in EPCI bus. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exe_epci_outbx_cnt_s cn; */
} bdk_cptx_pf_exe_epci_outbx_cnt_t;

static inline uint64_t BDK_CPTX_PF_EXE_EPCI_OUTBX_CNT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXE_EPCI_OUTBX_CNT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b==0)))
        return 0x872004001240ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=1)))
        return 0x872004001240ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=1)))
        return 0x872004001240ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXE_EPCI_OUTBX_CNT", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXE_EPCI_OUTBX_CNT(a,b) bdk_cptx_pf_exe_epci_outbx_cnt_t
#define bustype_BDK_CPTX_PF_EXE_EPCI_OUTBX_CNT(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXE_EPCI_OUTBX_CNT(a,b) "CPTX_PF_EXE_EPCI_OUTBX_CNT"
#define device_bar_BDK_CPTX_PF_EXE_EPCI_OUTBX_CNT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXE_EPCI_OUTBX_CNT(a,b) (a)
#define arguments_BDK_CPTX_PF_EXE_EPCI_OUTBX_CNT(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_exe_mem_ctl
 *
 * CPT PF Engine ECC Control Register
 * This register enables per-Engine ECC for each individual internal memory that requires ECC.
 * For debug
 * purposes, it can also flip one or two bits in the ECC data.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exe_mem_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t emu_sel               : 8;  /**< [ 23: 16](R/W) Engine select. */
        uint64_t reserved_4_15         : 12;
        uint64_t pflip                 : 1;  /**< [  3:  3](R/W) Flip the parity bit in the icache memories. */
        uint64_t flip1                 : 1;  /**< [  2:  2](R/W) Flip syndrome bit 1 in register file memories. */
        uint64_t flip0                 : 1;  /**< [  1:  1](R/W) Flip syndrome bit 0 in register file memories. */
        uint64_t cdis                  : 1;  /**< [  0:  0](R/W) Disable correction for register file memories. */
#else /* Word 0 - Little Endian */
        uint64_t cdis                  : 1;  /**< [  0:  0](R/W) Disable correction for register file memories. */
        uint64_t flip0                 : 1;  /**< [  1:  1](R/W) Flip syndrome bit 0 in register file memories. */
        uint64_t flip1                 : 1;  /**< [  2:  2](R/W) Flip syndrome bit 1 in register file memories. */
        uint64_t pflip                 : 1;  /**< [  3:  3](R/W) Flip the parity bit in the icache memories. */
        uint64_t reserved_4_15         : 12;
        uint64_t emu_sel               : 8;  /**< [ 23: 16](R/W) Engine select. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exe_mem_ctl_s cn; */
} bdk_cptx_pf_exe_mem_ctl_t;

static inline uint64_t BDK_CPTX_PF_EXE_MEM_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXE_MEM_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872004000038ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872004000038ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872004000038ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXE_MEM_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXE_MEM_CTL(a) bdk_cptx_pf_exe_mem_ctl_t
#define bustype_BDK_CPTX_PF_EXE_MEM_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXE_MEM_CTL(a) "CPTX_PF_EXE_MEM_CTL"
#define device_bar_BDK_CPTX_PF_EXE_MEM_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXE_MEM_CTL(a) (a)
#define arguments_BDK_CPTX_PF_EXE_MEM_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exe_perf_ctl
 *
 * CPT PF Engine Performance Control Register
 * This register controls engine performance counters.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exe_perf_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_21_63        : 43;
        uint64_t epci_inb_cnt_en       : 2;  /**< [ 20: 19](R/W) Enable EPCI inbound counters. */
        uint64_t epci_outb_cnt_en      : 2;  /**< [ 18: 17](R/W) Enable EPCI outbound counters. */
        uint64_t event_cnt_en          : 1;  /**< [ 16: 16](R/W) Enable single event counter. */
        uint64_t dbg_cnt_en            : 16; /**< [ 15:  0](R/W) Enable counters on debug bus. */
#else /* Word 0 - Little Endian */
        uint64_t dbg_cnt_en            : 16; /**< [ 15:  0](R/W) Enable counters on debug bus. */
        uint64_t event_cnt_en          : 1;  /**< [ 16: 16](R/W) Enable single event counter. */
        uint64_t epci_outb_cnt_en      : 2;  /**< [ 18: 17](R/W) Enable EPCI outbound counters. */
        uint64_t epci_inb_cnt_en       : 2;  /**< [ 20: 19](R/W) Enable EPCI inbound counters. */
        uint64_t reserved_21_63        : 43;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exe_perf_ctl_s cn; */
} bdk_cptx_pf_exe_perf_ctl_t;

static inline uint64_t BDK_CPTX_PF_EXE_PERF_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXE_PERF_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872004001000ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872004001000ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872004001000ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXE_PERF_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXE_PERF_CTL(a) bdk_cptx_pf_exe_perf_ctl_t
#define bustype_BDK_CPTX_PF_EXE_PERF_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXE_PERF_CTL(a) "CPTX_PF_EXE_PERF_CTL"
#define device_bar_BDK_CPTX_PF_EXE_PERF_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXE_PERF_CTL(a) (a)
#define arguments_BDK_CPTX_PF_EXE_PERF_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exe_perf_event_cnt
 *
 * Symmetric and Asymmetric Engine Performance Event Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exe_perf_event_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t counter               : 48; /**< [ 47:  0](R/W1C/H) Counts the performance events in an engine. The event is selected by setting
                                                                 the lower 3 bits of CPT()_PF_EXE_DBG_CTL[REG_SEL].
                                                                 0x0 = Undefined.
                                                                 0x1 = The number of cycles the exec is waiting for the exec is waiting for
                                                                 inbound bus data.
                                                                 0x2 = The number of cycles the execution queue is busy.
                                                                 0x3 = The number of cycles the execution queue cannot issue instructions because
                                                                 of a datapath stall. */
#else /* Word 0 - Little Endian */
        uint64_t counter               : 48; /**< [ 47:  0](R/W1C/H) Counts the performance events in an engine. The event is selected by setting
                                                                 the lower 3 bits of CPT()_PF_EXE_DBG_CTL[REG_SEL].
                                                                 0x0 = Undefined.
                                                                 0x1 = The number of cycles the exec is waiting for the exec is waiting for
                                                                 inbound bus data.
                                                                 0x2 = The number of cycles the execution queue is busy.
                                                                 0x3 = The number of cycles the execution queue cannot issue instructions because
                                                                 of a datapath stall. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exe_perf_event_cnt_s cn; */
} bdk_cptx_pf_exe_perf_event_cnt_t;

static inline uint64_t BDK_CPTX_PF_EXE_PERF_EVENT_CNT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXE_PERF_EVENT_CNT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872004001180ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872004001180ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872004001180ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXE_PERF_EVENT_CNT", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXE_PERF_EVENT_CNT(a) bdk_cptx_pf_exe_perf_event_cnt_t
#define bustype_BDK_CPTX_PF_EXE_PERF_EVENT_CNT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXE_PERF_EVENT_CNT(a) "CPTX_PF_EXE_PERF_EVENT_CNT"
#define device_bar_BDK_CPTX_PF_EXE_PERF_EVENT_CNT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXE_PERF_EVENT_CNT(a) (a)
#define arguments_BDK_CPTX_PF_EXE_PERF_EVENT_CNT(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exe_req_timer
 *
 * CPT PF Engine Arbiter Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exe_req_timer_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t cnt                   : 8;  /**< [  7:  0](R/W) Interval to promote starving low priority requests to high priorty. After
                                                                 between one and two times this interval a pending low priority request will be
                                                                 elevated to high priority status.
                                                                 0x0 = Disabled.
                                                                 0x1 = Timeout between 256 and 511 cycles.
                                                                 0x2 = Timeout between 512 and 1023 cycles.
                                                                 0x3 = Timeout between 768 and 1535 cycles.
                                                                 _ etc. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 8;  /**< [  7:  0](R/W) Interval to promote starving low priority requests to high priorty. After
                                                                 between one and two times this interval a pending low priority request will be
                                                                 elevated to high priority status.
                                                                 0x0 = Disabled.
                                                                 0x1 = Timeout between 256 and 511 cycles.
                                                                 0x2 = Timeout between 512 and 1023 cycles.
                                                                 0x3 = Timeout between 768 and 1535 cycles.
                                                                 _ etc. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exe_req_timer_s cn; */
} bdk_cptx_pf_exe_req_timer_t;

static inline uint64_t BDK_CPTX_PF_EXE_REQ_TIMER(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXE_REQ_TIMER(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872004000030ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872004000030ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872004000030ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXE_REQ_TIMER", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXE_REQ_TIMER(a) bdk_cptx_pf_exe_req_timer_t
#define bustype_BDK_CPTX_PF_EXE_REQ_TIMER(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXE_REQ_TIMER(a) "CPTX_PF_EXE_REQ_TIMER"
#define device_bar_BDK_CPTX_PF_EXE_REQ_TIMER(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXE_REQ_TIMER(a) (a)
#define arguments_BDK_CPTX_PF_EXE_REQ_TIMER(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exe_status
 *
 * CPT PF Engine Control Register
 * This register indicates whether the engine can be shutdown.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exe_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t active                : 64; /**< [ 63:  0](RO/H) Engine is enabled and not idle. */
#else /* Word 0 - Little Endian */
        uint64_t active                : 64; /**< [ 63:  0](RO/H) Engine is enabled and not idle. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exe_status_s cn; */
} bdk_cptx_pf_exe_status_t;

static inline uint64_t BDK_CPTX_PF_EXE_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXE_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872004000008ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872004000008ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872004000008ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXE_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXE_STATUS(a) bdk_cptx_pf_exe_status_t
#define bustype_BDK_CPTX_PF_EXE_STATUS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXE_STATUS(a) "CPTX_PF_EXE_STATUS"
#define device_bar_BDK_CPTX_PF_EXE_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXE_STATUS(a) (a)
#define arguments_BDK_CPTX_PF_EXE_STATUS(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exec_busy
 *
 * CPT Engine Info Register
 * This contains the busy status of the execs.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exec_busy_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t busy                  : 64; /**< [ 63:  0](RO/H) Current state of the engine, one bit per engine.  Before
                                                                 disabling an engine via the PF_EXE_CTL register, the
                                                                 corresponding bit in this register must be clear. */
#else /* Word 0 - Little Endian */
        uint64_t busy                  : 64; /**< [ 63:  0](RO/H) Current state of the engine, one bit per engine.  Before
                                                                 disabling an engine via the PF_EXE_CTL register, the
                                                                 corresponding bit in this register must be clear. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exec_busy_s cn; */
} bdk_cptx_pf_exec_busy_t;

static inline uint64_t BDK_CPTX_PF_EXEC_BUSY(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXEC_BUSY(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000800ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000800ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000800ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXEC_BUSY", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXEC_BUSY(a) bdk_cptx_pf_exec_busy_t
#define bustype_BDK_CPTX_PF_EXEC_BUSY(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXEC_BUSY(a) "CPTX_PF_EXEC_BUSY"
#define device_bar_BDK_CPTX_PF_EXEC_BUSY(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXEC_BUSY(a) (a)
#define arguments_BDK_CPTX_PF_EXEC_BUSY(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exec_ena_w1c
 *
 * CPT PF Mailbox Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exec_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exec                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for CPT(0..1)_PF_EXEC_INT[EXEC]. */
#else /* Word 0 - Little Endian */
        uint64_t exec                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for CPT(0..1)_PF_EXEC_INT[EXEC]. */
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_pf_exec_ena_w1c_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exec                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for CPT(0)_PF_EXEC_INT[EXEC]. */
#else /* Word 0 - Little Endian */
        uint64_t exec                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for CPT(0)_PF_EXEC_INT[EXEC]. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_pf_exec_ena_w1c_s cn83xx; */
    /* struct bdk_cptx_pf_exec_ena_w1c_s cn9; */
} bdk_cptx_pf_exec_ena_w1c_t;

static inline uint64_t BDK_CPTX_PF_EXEC_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXEC_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000540ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000540ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000540ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXEC_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXEC_ENA_W1C(a) bdk_cptx_pf_exec_ena_w1c_t
#define bustype_BDK_CPTX_PF_EXEC_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXEC_ENA_W1C(a) "CPTX_PF_EXEC_ENA_W1C"
#define device_bar_BDK_CPTX_PF_EXEC_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXEC_ENA_W1C(a) (a)
#define arguments_BDK_CPTX_PF_EXEC_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exec_ena_w1s
 *
 * CPT PF Mailbox Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exec_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exec                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for CPT(0..1)_PF_EXEC_INT[EXEC]. */
#else /* Word 0 - Little Endian */
        uint64_t exec                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for CPT(0..1)_PF_EXEC_INT[EXEC]. */
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_pf_exec_ena_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exec                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for CPT(0)_PF_EXEC_INT[EXEC]. */
#else /* Word 0 - Little Endian */
        uint64_t exec                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for CPT(0)_PF_EXEC_INT[EXEC]. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_pf_exec_ena_w1s_s cn83xx; */
    /* struct bdk_cptx_pf_exec_ena_w1s_s cn9; */
} bdk_cptx_pf_exec_ena_w1s_t;

static inline uint64_t BDK_CPTX_PF_EXEC_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXEC_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000560ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000560ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000560ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXEC_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXEC_ENA_W1S(a) bdk_cptx_pf_exec_ena_w1s_t
#define bustype_BDK_CPTX_PF_EXEC_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXEC_ENA_W1S(a) "CPTX_PF_EXEC_ENA_W1S"
#define device_bar_BDK_CPTX_PF_EXEC_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXEC_ENA_W1S(a) (a)
#define arguments_BDK_CPTX_PF_EXEC_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exec_info
 *
 * CPT Engine Info Register
 * This contains the error code and PC for the most recent ERR_REQUEST.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exec_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t errcode               : 8;  /**< [ 31: 24](R/W/H) Error type.  Defined by the CPT_ENGINE_ERR_TYPE_E enum. */
        uint64_t reserved_23           : 1;
        uint64_t errpc                 : 15; /**< [ 22:  8](R/W/H) MicroPC of the instruction that caused the error. */
        uint64_t eid                   : 8;  /**< [  7:  0](R/W/H) Engine number of the most recent engine to issue an
                                                                  ERR_REQUEST. */
#else /* Word 0 - Little Endian */
        uint64_t eid                   : 8;  /**< [  7:  0](R/W/H) Engine number of the most recent engine to issue an
                                                                  ERR_REQUEST. */
        uint64_t errpc                 : 15; /**< [ 22:  8](R/W/H) MicroPC of the instruction that caused the error. */
        uint64_t reserved_23           : 1;
        uint64_t errcode               : 8;  /**< [ 31: 24](R/W/H) Error type.  Defined by the CPT_ENGINE_ERR_TYPE_E enum. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exec_info_s cn; */
} bdk_cptx_pf_exec_info_t;

static inline uint64_t BDK_CPTX_PF_EXEC_INFO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXEC_INFO(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000700ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000700ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000700ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXEC_INFO", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXEC_INFO(a) bdk_cptx_pf_exec_info_t
#define bustype_BDK_CPTX_PF_EXEC_INFO(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXEC_INFO(a) "CPTX_PF_EXEC_INFO"
#define device_bar_BDK_CPTX_PF_EXEC_INFO(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXEC_INFO(a) (a)
#define arguments_BDK_CPTX_PF_EXEC_INFO(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exec_info0
 *
 * CPT RF_SBE Register
 * This register is for diagnostic purposes.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exec_info0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t rf_sbe                : 48; /**< [ 47:  0](R/W1C/H) Set if an engine detects a SBE in the register file. */
#else /* Word 0 - Little Endian */
        uint64_t rf_sbe                : 48; /**< [ 47:  0](R/W1C/H) Set if an engine detects a SBE in the register file. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_pf_exec_info0_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t rf_sbe                : 16; /**< [ 15:  0](R/W1C/H) Set if an engine detects a SBE in the register file. */
#else /* Word 0 - Little Endian */
        uint64_t rf_sbe                : 16; /**< [ 15:  0](R/W1C/H) Set if an engine detects a SBE in the register file. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_pf_exec_info0_s cn83xx; */
    /* struct bdk_cptx_pf_exec_info0_s cn9; */
} bdk_cptx_pf_exec_info0_t;

static inline uint64_t BDK_CPTX_PF_EXEC_INFO0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXEC_INFO0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000900ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000900ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000900ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXEC_INFO0", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXEC_INFO0(a) bdk_cptx_pf_exec_info0_t
#define bustype_BDK_CPTX_PF_EXEC_INFO0(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXEC_INFO0(a) "CPTX_PF_EXEC_INFO0"
#define device_bar_BDK_CPTX_PF_EXEC_INFO0(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXEC_INFO0(a) (a)
#define arguments_BDK_CPTX_PF_EXEC_INFO0(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exec_info1
 *
 * CPT UC_ERR Register
 * This register is for diagnostic purposes.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exec_info1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t uc_err                : 48; /**< [ 47:  0](R/W1C/H) Microcode cache error detected and corrected by an engine. */
#else /* Word 0 - Little Endian */
        uint64_t uc_err                : 48; /**< [ 47:  0](R/W1C/H) Microcode cache error detected and corrected by an engine. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_pf_exec_info1_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t uc_err                : 16; /**< [ 15:  0](R/W1C/H) Microcode cache error detected and corrected by an engine. */
#else /* Word 0 - Little Endian */
        uint64_t uc_err                : 16; /**< [ 15:  0](R/W1C/H) Microcode cache error detected and corrected by an engine. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_pf_exec_info1_s cn83xx; */
    /* struct bdk_cptx_pf_exec_info1_s cn9; */
} bdk_cptx_pf_exec_info1_t;

static inline uint64_t BDK_CPTX_PF_EXEC_INFO1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXEC_INFO1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000910ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000910ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000910ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXEC_INFO1", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXEC_INFO1(a) bdk_cptx_pf_exec_info1_t
#define bustype_BDK_CPTX_PF_EXEC_INFO1(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXEC_INFO1(a) "CPTX_PF_EXEC_INFO1"
#define device_bar_BDK_CPTX_PF_EXEC_INFO1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXEC_INFO1(a) (a)
#define arguments_BDK_CPTX_PF_EXEC_INFO1(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exec_int
 *
 * CPT Exec Unit Interrupt Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exec_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exec                  : 64; /**< [ 63:  0](R/W1C/H) One interrupt bit per engine. Each bit is set
                                                                  when the associated engine issues an error
                                                                  request.  The most recent error information
                                                                  can be found in CPT()_PF_EXEC_INFO. */
#else /* Word 0 - Little Endian */
        uint64_t exec                  : 64; /**< [ 63:  0](R/W1C/H) One interrupt bit per engine. Each bit is set
                                                                  when the associated engine issues an error
                                                                  request.  The most recent error information
                                                                  can be found in CPT()_PF_EXEC_INFO. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_exec_int_s cn; */
} bdk_cptx_pf_exec_int_t;

static inline uint64_t BDK_CPTX_PF_EXEC_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXEC_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000500ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000500ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000500ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXEC_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXEC_INT(a) bdk_cptx_pf_exec_int_t
#define bustype_BDK_CPTX_PF_EXEC_INT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXEC_INT(a) "CPTX_PF_EXEC_INT"
#define device_bar_BDK_CPTX_PF_EXEC_INT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXEC_INT(a) (a)
#define arguments_BDK_CPTX_PF_EXEC_INT(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_exec_int_w1s
 *
 * CPT PF Mailbox Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_exec_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exec                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets CPT(0..1)_PF_EXEC_INT[EXEC]. */
#else /* Word 0 - Little Endian */
        uint64_t exec                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets CPT(0..1)_PF_EXEC_INT[EXEC]. */
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_pf_exec_int_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exec                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets CPT(0)_PF_EXEC_INT[EXEC]. */
#else /* Word 0 - Little Endian */
        uint64_t exec                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets CPT(0)_PF_EXEC_INT[EXEC]. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_pf_exec_int_w1s_s cn83xx; */
    /* struct bdk_cptx_pf_exec_int_w1s_s cn9; */
} bdk_cptx_pf_exec_int_w1s_t;

static inline uint64_t BDK_CPTX_PF_EXEC_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_EXEC_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000520ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000520ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000520ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_EXEC_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_EXEC_INT_W1S(a) bdk_cptx_pf_exec_int_w1s_t
#define bustype_BDK_CPTX_PF_EXEC_INT_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_EXEC_INT_W1S(a) "CPTX_PF_EXEC_INT_W1S"
#define device_bar_BDK_CPTX_PF_EXEC_INT_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_EXEC_INT_W1S(a) (a)
#define arguments_BDK_CPTX_PF_EXEC_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_g#_en
 *
 * CPT PF Group Control Register
 * This register configures engine groups.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_gx_en_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t en                    : 64; /**< [ 63:  0](R/W/H) Engine group enable. One bit corresponds to each engine, with the bit set to
                                                                 indicate this engine can service this group.

                                                                 Bits corresponding to unimplemented engines read as zero, i.e. only bit numbers
                                                                 less than CPT()_PF_CONSTANTS[AE] + CPT()_PF_CONSTANTS[SE] are writable.  AE
                                                                 engine bits follow SE engine bits. E.g. if CPT()_PF_CONSTANTS[AE] = 0x1, and
                                                                 CPT()_PF_CONSTANTS[SE] = 0x2, then bits <2:0> are read/writable with bit <2>
                                                                 corresponding to AE<0>, and bit <1> to SE<1>, and bit<0> to SE<0>.

                                                                 Before disabling an engine, the corresponding bit in each group must be cleared.
                                                                 CPT()_PF_EXEC_BUSY can then be polled to determing when the engine becomes
                                                                 idle.  At the point, the engine can be disabled. */
#else /* Word 0 - Little Endian */
        uint64_t en                    : 64; /**< [ 63:  0](R/W/H) Engine group enable. One bit corresponds to each engine, with the bit set to
                                                                 indicate this engine can service this group.

                                                                 Bits corresponding to unimplemented engines read as zero, i.e. only bit numbers
                                                                 less than CPT()_PF_CONSTANTS[AE] + CPT()_PF_CONSTANTS[SE] are writable.  AE
                                                                 engine bits follow SE engine bits. E.g. if CPT()_PF_CONSTANTS[AE] = 0x1, and
                                                                 CPT()_PF_CONSTANTS[SE] = 0x2, then bits <2:0> are read/writable with bit <2>
                                                                 corresponding to AE<0>, and bit <1> to SE<1>, and bit<0> to SE<0>.

                                                                 Before disabling an engine, the corresponding bit in each group must be cleared.
                                                                 CPT()_PF_EXEC_BUSY can then be polled to determing when the engine becomes
                                                                 idle.  At the point, the engine can be disabled. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_gx_en_s cn; */
} bdk_cptx_pf_gx_en_t;

static inline uint64_t BDK_CPTX_PF_GX_EN(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_GX_EN(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=7)))
        return 0x872000000600ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=7)))
        return 0x872000000600ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=7)))
        return 0x872000000600ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("CPTX_PF_GX_EN", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_GX_EN(a,b) bdk_cptx_pf_gx_en_t
#define bustype_BDK_CPTX_PF_GX_EN(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_GX_EN(a,b) "CPTX_PF_GX_EN"
#define device_bar_BDK_CPTX_PF_GX_EN(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_GX_EN(a,b) (a)
#define arguments_BDK_CPTX_PF_GX_EN(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_inst_latency_pc
 *
 * CPT PF Instruction Latency Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_inst_latency_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for an instruction to complete (have the store of
                                                                 CPT_RES_S reach the commit point). Incremented every coprocessor-clock by the
                                                                 number of instructions active in that cycle. This may be divided by
                                                                 CPT()_PF_RD_REQ_PC to determine the average hardware instruction latency. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for an instruction to complete (have the store of
                                                                 CPT_RES_S reach the commit point). Incremented every coprocessor-clock by the
                                                                 number of instructions active in that cycle. This may be divided by
                                                                 CPT()_PF_RD_REQ_PC to determine the average hardware instruction latency. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_inst_latency_pc_s cn; */
} bdk_cptx_pf_inst_latency_pc_t;

static inline uint64_t BDK_CPTX_PF_INST_LATENCY_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_INST_LATENCY_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000010020ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000010020ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000010020ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_INST_LATENCY_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_INST_LATENCY_PC(a) bdk_cptx_pf_inst_latency_pc_t
#define bustype_BDK_CPTX_PF_INST_LATENCY_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_INST_LATENCY_PC(a) "CPTX_PF_INST_LATENCY_PC"
#define device_bar_BDK_CPTX_PF_INST_LATENCY_PC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_INST_LATENCY_PC(a) (a)
#define arguments_BDK_CPTX_PF_INST_LATENCY_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_inst_req_pc
 *
 * CPT PF Instruction Request Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_inst_req_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of instructions that have started processing. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of instructions that have started processing. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_inst_req_pc_s cn; */
} bdk_cptx_pf_inst_req_pc_t;

static inline uint64_t BDK_CPTX_PF_INST_REQ_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_INST_REQ_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000010000ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000010000ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000010000ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_INST_REQ_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_INST_REQ_PC(a) bdk_cptx_pf_inst_req_pc_t
#define bustype_BDK_CPTX_PF_INST_REQ_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_INST_REQ_PC(a) "CPTX_PF_INST_REQ_PC"
#define device_bar_BDK_CPTX_PF_INST_REQ_PC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_INST_REQ_PC(a) (a)
#define arguments_BDK_CPTX_PF_INST_REQ_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_mbox_ena_w1c#
 *
 * CPT PF Mailbox Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_mbox_ena_w1cx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for CPT(0..1)_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for CPT(0..1)_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_pf_mbox_ena_w1cx_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for CPT(0)_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for CPT(0)_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_pf_mbox_ena_w1cx_s cn83xx; */
    /* struct bdk_cptx_pf_mbox_ena_w1cx_s cn9; */
} bdk_cptx_pf_mbox_ena_w1cx_t;

static inline uint64_t BDK_CPTX_PF_MBOX_ENA_W1CX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_MBOX_ENA_W1CX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b==0)))
        return 0x872000000440ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x872000000440ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b==0)))
        return 0x872000000440ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("CPTX_PF_MBOX_ENA_W1CX", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_MBOX_ENA_W1CX(a,b) bdk_cptx_pf_mbox_ena_w1cx_t
#define bustype_BDK_CPTX_PF_MBOX_ENA_W1CX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_MBOX_ENA_W1CX(a,b) "CPTX_PF_MBOX_ENA_W1CX"
#define device_bar_BDK_CPTX_PF_MBOX_ENA_W1CX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_MBOX_ENA_W1CX(a,b) (a)
#define arguments_BDK_CPTX_PF_MBOX_ENA_W1CX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_mbox_ena_w1s#
 *
 * CPT PF Mailbox Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_mbox_ena_w1sx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for CPT(0..1)_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for CPT(0..1)_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_pf_mbox_ena_w1sx_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for CPT(0)_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for CPT(0)_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_pf_mbox_ena_w1sx_s cn83xx; */
    /* struct bdk_cptx_pf_mbox_ena_w1sx_s cn9; */
} bdk_cptx_pf_mbox_ena_w1sx_t;

static inline uint64_t BDK_CPTX_PF_MBOX_ENA_W1SX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_MBOX_ENA_W1SX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b==0)))
        return 0x872000000460ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x872000000460ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b==0)))
        return 0x872000000460ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("CPTX_PF_MBOX_ENA_W1SX", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_MBOX_ENA_W1SX(a,b) bdk_cptx_pf_mbox_ena_w1sx_t
#define bustype_BDK_CPTX_PF_MBOX_ENA_W1SX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_MBOX_ENA_W1SX(a,b) "CPTX_PF_MBOX_ENA_W1SX"
#define device_bar_BDK_CPTX_PF_MBOX_ENA_W1SX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_MBOX_ENA_W1SX(a,b) (a)
#define arguments_BDK_CPTX_PF_MBOX_ENA_W1SX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_mbox_int#
 *
 * CPT PF Mailbox Interrupt Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_mbox_intx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) One interrupt bit per VF. Each bit is set when the associated
                                                                 CPT()_VF()_PF_MBOX(1) is written. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) One interrupt bit per VF. Each bit is set when the associated
                                                                 CPT()_VF()_PF_MBOX(1) is written. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_mbox_intx_s cn; */
} bdk_cptx_pf_mbox_intx_t;

static inline uint64_t BDK_CPTX_PF_MBOX_INTX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_MBOX_INTX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b==0)))
        return 0x872000000400ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x872000000400ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b==0)))
        return 0x872000000400ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("CPTX_PF_MBOX_INTX", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_MBOX_INTX(a,b) bdk_cptx_pf_mbox_intx_t
#define bustype_BDK_CPTX_PF_MBOX_INTX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_MBOX_INTX(a,b) "CPTX_PF_MBOX_INTX"
#define device_bar_BDK_CPTX_PF_MBOX_INTX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_MBOX_INTX(a,b) (a)
#define arguments_BDK_CPTX_PF_MBOX_INTX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_mbox_int_w1s#
 *
 * CPT PF Mailbox Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_mbox_int_w1sx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets CPT(0..1)_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets CPT(0..1)_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_pf_mbox_int_w1sx_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets CPT(0)_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets CPT(0)_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_pf_mbox_int_w1sx_s cn83xx; */
    /* struct bdk_cptx_pf_mbox_int_w1sx_s cn9; */
} bdk_cptx_pf_mbox_int_w1sx_t;

static inline uint64_t BDK_CPTX_PF_MBOX_INT_W1SX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_MBOX_INT_W1SX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b==0)))
        return 0x872000000420ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x872000000420ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b==0)))
        return 0x872000000420ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("CPTX_PF_MBOX_INT_W1SX", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_MBOX_INT_W1SX(a,b) bdk_cptx_pf_mbox_int_w1sx_t
#define bustype_BDK_CPTX_PF_MBOX_INT_W1SX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_MBOX_INT_W1SX(a,b) "CPTX_PF_MBOX_INT_W1SX"
#define device_bar_BDK_CPTX_PF_MBOX_INT_W1SX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_MBOX_INT_W1SX(a,b) (a)
#define arguments_BDK_CPTX_PF_MBOX_INT_W1SX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_msix_pba#
 *
 * CPT PF MSI-X Pending-Bit-Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the
 * CPT_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated CPT()_PF_MSIX_VEC()_CTL, enumerated by
                                                                 CPT_PF_INT_VEC_E. Bits that have no associated CPT_PF_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated CPT()_PF_MSIX_VEC()_CTL, enumerated by
                                                                 CPT_PF_INT_VEC_E. Bits that have no associated CPT_PF_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_msix_pbax_s cn; */
} bdk_cptx_pf_msix_pbax_t;

static inline uint64_t BDK_CPTX_PF_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b==0)))
        return 0x8720100f0000ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x8720100f0000ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b==0)))
        return 0x8720100f0000ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("CPTX_PF_MSIX_PBAX", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_MSIX_PBAX(a,b) bdk_cptx_pf_msix_pbax_t
#define bustype_BDK_CPTX_PF_MSIX_PBAX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_MSIX_PBAX(a,b) "CPTX_PF_MSIX_PBAX"
#define device_bar_BDK_CPTX_PF_MSIX_PBAX(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_CPTX_PF_MSIX_PBAX(a,b) (a)
#define arguments_BDK_CPTX_PF_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_msix_vec#_addr
 *
 * CPT PF MSI-X Vector-Table Address Registers
 * This register is the MSI-X vector table, indexed by the CPT_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's CPT()_PF_MSIX_VEC()_ADDR, CPT()_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of CPT()_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_CPT_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's CPT()_PF_MSIX_VEC()_ADDR, CPT()_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of CPT()_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_CPT_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_msix_vecx_addr_s cn; */
} bdk_cptx_pf_msix_vecx_addr_t;

static inline uint64_t BDK_CPTX_PF_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=2)))
        return 0x872010000000ll + 0x1000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=2)))
        return 0x872010000000ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=2)))
        return 0x872010000000ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x3);
    __bdk_csr_fatal("CPTX_PF_MSIX_VECX_ADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_MSIX_VECX_ADDR(a,b) bdk_cptx_pf_msix_vecx_addr_t
#define bustype_BDK_CPTX_PF_MSIX_VECX_ADDR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_MSIX_VECX_ADDR(a,b) "CPTX_PF_MSIX_VECX_ADDR"
#define device_bar_BDK_CPTX_PF_MSIX_VECX_ADDR(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_CPTX_PF_MSIX_VECX_ADDR(a,b) (a)
#define arguments_BDK_CPTX_PF_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_msix_vec#_ctl
 *
 * CPT PF MSI-X Vector-Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the CPT_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_msix_vecx_ctl_s
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
    /* struct bdk_cptx_pf_msix_vecx_ctl_s cn; */
} bdk_cptx_pf_msix_vecx_ctl_t;

static inline uint64_t BDK_CPTX_PF_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=2)))
        return 0x872010000008ll + 0x1000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=2)))
        return 0x872010000008ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=2)))
        return 0x872010000008ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x3);
    __bdk_csr_fatal("CPTX_PF_MSIX_VECX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_MSIX_VECX_CTL(a,b) bdk_cptx_pf_msix_vecx_ctl_t
#define bustype_BDK_CPTX_PF_MSIX_VECX_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_MSIX_VECX_CTL(a,b) "CPTX_PF_MSIX_VECX_CTL"
#define device_bar_BDK_CPTX_PF_MSIX_VECX_CTL(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_CPTX_PF_MSIX_VECX_CTL(a,b) (a)
#define arguments_BDK_CPTX_PF_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_q#_ctl
 *
 * CPT Queue Control Register
 * This register configures queues. This register should be changed only when quiescent
 * (see CPT()_VQ()_INPROG[INFLIGHT]).
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_qx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t aura                  : 12; /**< [ 59: 48](R/W) Guest-aura for returning this queue's instruction-chunk buffers to FPA.
                                                                 Only used when [INST_FREE] is set.
                                                                 For the FPA to not discard the request, FPA_PF_MAP() must map
                                                                 [AURA] and CPT()_PF_Q()_GMCTL[GMID] as valid. */
        uint64_t reserved_45_47        : 3;
        uint64_t size                  : 13; /**< [ 44: 32](R/W) Command-buffer size, in number of 64-bit words per command buffer segment.
                                                                 Must be 8*n + 1, where n is the number of instructions per buffer segment. */
        uint64_t reserved_11_31        : 21;
        uint64_t cont_err              : 1;  /**< [ 10: 10](R/W) Continue on error.

                                                                 0 = When CPT()_VQ()_MISC_INT[NWRP], CPT()_VQ()_MISC_INT[IRDE] or
                                                                 CPT()_VQ()_MISC_INT[DOVF] are set by hardware or software via
                                                                 CPT()_VQ()_MISC_INT_W1S, then CPT()_VQ()_CTL[ENA] is cleared.  Due to
                                                                 pipelining, additional instructions may have been processed between the
                                                                 instruction causing the error and the next instruction in the disabled queue
                                                                 (the instruction at CPT()_VQ()_SADDR).

                                                                 1 = Ignore errors and continue processing instructions. For diagnostic use only. */
        uint64_t inst_free             : 1;  /**< [  9:  9](R/W) Instruction FPA free. When set, when CPT reaches the end of an instruction
                                                                 chunk, that chunk will be freed to the FPA. */
        uint64_t inst_be               : 1;  /**< [  8:  8](R/W) Instruction big-endian control. When set, instructions, instruction next chunk
                                                                 pointers, and result structures are stored in big-endian format in memory. */
        uint64_t iqb_ldwb              : 1;  /**< [  7:  7](R/W) Instruction load don't write back.

                                                                 0 = The hardware issues NCB transient load (LDT) towards the cache, which if the
                                                                 line hits and is is dirty will cause the line to be written back before being
                                                                 replaced.

                                                                 1 = The hardware issues NCB LDWB read-and-invalidate command towards the cache
                                                                 when fetching the last word of instructions; as a result the line will not be
                                                                 written back when replaced.  This improves performance, but software must not
                                                                 read the instructions after they are posted to the hardware.

                                                                 Reads that do not consume the last word of a cache line always use LDI. */
        uint64_t reserved_4_6          : 3;
        uint64_t grp                   : 3;  /**< [  3:  1](R/W) Engine group. */
        uint64_t pri                   : 1;  /**< [  0:  0](R/W) Queue priority.
                                                                 1 = This queue has higher priority. Round-robin between higher priority queues.
                                                                 0 = This queue has lower priority. Round-robin between lower priority queues. */
#else /* Word 0 - Little Endian */
        uint64_t pri                   : 1;  /**< [  0:  0](R/W) Queue priority.
                                                                 1 = This queue has higher priority. Round-robin between higher priority queues.
                                                                 0 = This queue has lower priority. Round-robin between lower priority queues. */
        uint64_t grp                   : 3;  /**< [  3:  1](R/W) Engine group. */
        uint64_t reserved_4_6          : 3;
        uint64_t iqb_ldwb              : 1;  /**< [  7:  7](R/W) Instruction load don't write back.

                                                                 0 = The hardware issues NCB transient load (LDT) towards the cache, which if the
                                                                 line hits and is is dirty will cause the line to be written back before being
                                                                 replaced.

                                                                 1 = The hardware issues NCB LDWB read-and-invalidate command towards the cache
                                                                 when fetching the last word of instructions; as a result the line will not be
                                                                 written back when replaced.  This improves performance, but software must not
                                                                 read the instructions after they are posted to the hardware.

                                                                 Reads that do not consume the last word of a cache line always use LDI. */
        uint64_t inst_be               : 1;  /**< [  8:  8](R/W) Instruction big-endian control. When set, instructions, instruction next chunk
                                                                 pointers, and result structures are stored in big-endian format in memory. */
        uint64_t inst_free             : 1;  /**< [  9:  9](R/W) Instruction FPA free. When set, when CPT reaches the end of an instruction
                                                                 chunk, that chunk will be freed to the FPA. */
        uint64_t cont_err              : 1;  /**< [ 10: 10](R/W) Continue on error.

                                                                 0 = When CPT()_VQ()_MISC_INT[NWRP], CPT()_VQ()_MISC_INT[IRDE] or
                                                                 CPT()_VQ()_MISC_INT[DOVF] are set by hardware or software via
                                                                 CPT()_VQ()_MISC_INT_W1S, then CPT()_VQ()_CTL[ENA] is cleared.  Due to
                                                                 pipelining, additional instructions may have been processed between the
                                                                 instruction causing the error and the next instruction in the disabled queue
                                                                 (the instruction at CPT()_VQ()_SADDR).

                                                                 1 = Ignore errors and continue processing instructions. For diagnostic use only. */
        uint64_t reserved_11_31        : 21;
        uint64_t size                  : 13; /**< [ 44: 32](R/W) Command-buffer size, in number of 64-bit words per command buffer segment.
                                                                 Must be 8*n + 1, where n is the number of instructions per buffer segment. */
        uint64_t reserved_45_47        : 3;
        uint64_t aura                  : 12; /**< [ 59: 48](R/W) Guest-aura for returning this queue's instruction-chunk buffers to FPA.
                                                                 Only used when [INST_FREE] is set.
                                                                 For the FPA to not discard the request, FPA_PF_MAP() must map
                                                                 [AURA] and CPT()_PF_Q()_GMCTL[GMID] as valid. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_qx_ctl_s cn; */
} bdk_cptx_pf_qx_ctl_t;

static inline uint64_t BDK_CPTX_PF_QX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_QX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872008000000ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872008000000ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872008000000ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_PF_QX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_QX_CTL(a,b) bdk_cptx_pf_qx_ctl_t
#define bustype_BDK_CPTX_PF_QX_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_QX_CTL(a,b) "CPTX_PF_QX_CTL"
#define device_bar_BDK_CPTX_PF_QX_CTL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_QX_CTL(a,b) (a)
#define arguments_BDK_CPTX_PF_QX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_q#_ctl2
 *
 * CPT Queue Control 2 Register
 * This register configures queues. This register should be changed only when quiescent
 * (see CPT()_VQ()_INPROG[INFLIGHT]).
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_qx_ctl2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t exe_ldwb              : 1;  /**< [  1:  1](R/W) Execution engine load-don't-write-back.

                                                                 0 = An execution engine request to LDWB will be converted to NCB transient
                                                                 loads (LDT) towards the cache, which if the line hits and is is dirty will cause
                                                                 the line to be written back before being replaced.

                                                                 1 = An execution engine may request a NCB LDWB read-and-invalidate command
                                                                 towards the cache; as a result the line will not be written back when replaced.
                                                                 This improves performance, but software must not read the instructions after
                                                                 they are posted to the hardware. */
        uint64_t exe_no_swap           : 1;  /**< [  0:  0](R/W) Execution units no byte swap. See the HRM endian section.
                                                                 0 = Execution unit read/writes have a byte-swap applied when accessing NCB.
                                                                 1 = Execution unit read/writes do not byte-swap. */
#else /* Word 0 - Little Endian */
        uint64_t exe_no_swap           : 1;  /**< [  0:  0](R/W) Execution units no byte swap. See the HRM endian section.
                                                                 0 = Execution unit read/writes have a byte-swap applied when accessing NCB.
                                                                 1 = Execution unit read/writes do not byte-swap. */
        uint64_t exe_ldwb              : 1;  /**< [  1:  1](R/W) Execution engine load-don't-write-back.

                                                                 0 = An execution engine request to LDWB will be converted to NCB transient
                                                                 loads (LDT) towards the cache, which if the line hits and is is dirty will cause
                                                                 the line to be written back before being replaced.

                                                                 1 = An execution engine may request a NCB LDWB read-and-invalidate command
                                                                 towards the cache; as a result the line will not be written back when replaced.
                                                                 This improves performance, but software must not read the instructions after
                                                                 they are posted to the hardware. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_qx_ctl2_s cn; */
} bdk_cptx_pf_qx_ctl2_t;

static inline uint64_t BDK_CPTX_PF_QX_CTL2(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_QX_CTL2(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872008000100ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872008000100ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872008000100ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_PF_QX_CTL2", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_QX_CTL2(a,b) bdk_cptx_pf_qx_ctl2_t
#define bustype_BDK_CPTX_PF_QX_CTL2(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_QX_CTL2(a,b) "CPTX_PF_QX_CTL2"
#define device_bar_BDK_CPTX_PF_QX_CTL2(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_QX_CTL2(a,b) (a)
#define arguments_BDK_CPTX_PF_QX_CTL2(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_q#_gmctl
 *
 * CPT Queue Guest Machine Control Register
 * This register configures queues. This register should be changed only when quiescent
 * (see CPT()_VQ()_INPROG[INFLIGHT]).
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_qx_gmctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t strm                  : 8;  /**< [ 23: 16](R/W) Low 8 bits of the SMMU stream identifier to use when issuing requests.

                                                                 Stream 0x0 corresponds to the PF, and VFs start at 0x1.

                                                                 Reset such that VF0/index 0 is 0x1, VF1/index 1 is 0x2, etc.

                                                                 Maximum legal value is 64. */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Reserved.
                                                                 Internal:
                                                                 Guest machine identifier. The GMID to send to FPA for all
                                                                 buffer free, or to SSO for all submit work operations initiated by this queue.
                                                                 Must be nonzero or FPA/SSO will drop requests; see FPA_PF_MAP() and SSO_PF_MAP(). */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Reserved.
                                                                 Internal:
                                                                 Guest machine identifier. The GMID to send to FPA for all
                                                                 buffer free, or to SSO for all submit work operations initiated by this queue.
                                                                 Must be nonzero or FPA/SSO will drop requests; see FPA_PF_MAP() and SSO_PF_MAP(). */
        uint64_t strm                  : 8;  /**< [ 23: 16](R/W) Low 8 bits of the SMMU stream identifier to use when issuing requests.

                                                                 Stream 0x0 corresponds to the PF, and VFs start at 0x1.

                                                                 Reset such that VF0/index 0 is 0x1, VF1/index 1 is 0x2, etc.

                                                                 Maximum legal value is 64. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_pf_qx_gmctl_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t strm                  : 8;  /**< [ 23: 16](R/W) Low 8 bits of the SMMU stream identifier to use when issuing requests.

                                                                 Stream 0x0 corresponds to the PF, and VFs start at 0x1.

                                                                 Reset such that VF0/index 0 is 0x1, VF1/index 1 is 0x2, etc. */
        uint64_t gmid                  : 16; /**< [ 15:  0](RO) Reserved.
                                                                 Internal:
                                                                 Guest machine identifier. The GMID to send to FPA for all
                                                                 buffer free, or to SSO for all submit work operations initiated by this queue.
                                                                 Must be nonzero or FPA/SSO will drop requests; see FPA_PF_MAP() and SSO_PF_MAP(). */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](RO) Reserved.
                                                                 Internal:
                                                                 Guest machine identifier. The GMID to send to FPA for all
                                                                 buffer free, or to SSO for all submit work operations initiated by this queue.
                                                                 Must be nonzero or FPA/SSO will drop requests; see FPA_PF_MAP() and SSO_PF_MAP(). */
        uint64_t strm                  : 8;  /**< [ 23: 16](R/W) Low 8 bits of the SMMU stream identifier to use when issuing requests.

                                                                 Stream 0x0 corresponds to the PF, and VFs start at 0x1.

                                                                 Reset such that VF0/index 0 is 0x1, VF1/index 1 is 0x2, etc. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_pf_qx_gmctl_s cn83xx; */
    struct bdk_cptx_pf_qx_gmctl_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t strm                  : 8;  /**< [ 23: 16](R/W) Low 8 bits of the SMMU stream identifier to use when issuing requests.

                                                                 Stream 0x0 corresponds to the PF, and VFs start at 0x1.

                                                                 Reset such that VF0/index 0 is 0x1, VF1/index 1 is 0x2, etc. */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Reserved.
                                                                 Internal:
                                                                 Guest machine identifier. The GMID to send to FPA for all
                                                                 buffer free, or to SSO for all submit work operations initiated by this queue.
                                                                 Must be nonzero or FPA/SSO will drop requests; see FPA_PF_MAP() and SSO_PF_MAP(). */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Reserved.
                                                                 Internal:
                                                                 Guest machine identifier. The GMID to send to FPA for all
                                                                 buffer free, or to SSO for all submit work operations initiated by this queue.
                                                                 Must be nonzero or FPA/SSO will drop requests; see FPA_PF_MAP() and SSO_PF_MAP(). */
        uint64_t strm                  : 8;  /**< [ 23: 16](R/W) Low 8 bits of the SMMU stream identifier to use when issuing requests.

                                                                 Stream 0x0 corresponds to the PF, and VFs start at 0x1.

                                                                 Reset such that VF0/index 0 is 0x1, VF1/index 1 is 0x2, etc. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn9;
} bdk_cptx_pf_qx_gmctl_t;

static inline uint64_t BDK_CPTX_PF_QX_GMCTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_QX_GMCTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872008000020ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872008000020ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872008000020ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_PF_QX_GMCTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_PF_QX_GMCTL(a,b) bdk_cptx_pf_qx_gmctl_t
#define bustype_BDK_CPTX_PF_QX_GMCTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_QX_GMCTL(a,b) "CPTX_PF_QX_GMCTL"
#define device_bar_BDK_CPTX_PF_QX_GMCTL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_QX_GMCTL(a,b) (a)
#define arguments_BDK_CPTX_PF_QX_GMCTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_pf_rd_latency_pc
 *
 * CPT PF Read Latency Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_rd_latency_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for L2C read returns. Incremented every
                                                                 coprocessor-clock by the number of transactions outstanding in that cycle. This
                                                                 may be divided by CPT()_PF_RD_REQ_PC to determine the average read latency. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for L2C read returns. Incremented every
                                                                 coprocessor-clock by the number of transactions outstanding in that cycle. This
                                                                 may be divided by CPT()_PF_RD_REQ_PC to determine the average read latency. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_rd_latency_pc_s cn; */
} bdk_cptx_pf_rd_latency_pc_t;

static inline uint64_t BDK_CPTX_PF_RD_LATENCY_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_RD_LATENCY_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000010060ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000010060ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000010060ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_RD_LATENCY_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_RD_LATENCY_PC(a) bdk_cptx_pf_rd_latency_pc_t
#define bustype_BDK_CPTX_PF_RD_LATENCY_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_RD_LATENCY_PC(a) "CPTX_PF_RD_LATENCY_PC"
#define device_bar_BDK_CPTX_PF_RD_LATENCY_PC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_RD_LATENCY_PC(a) (a)
#define arguments_BDK_CPTX_PF_RD_LATENCY_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_rd_req_pc
 *
 * CPT PF Read Request Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_rd_req_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of L2C read requests. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of L2C read requests. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_rd_req_pc_s cn; */
} bdk_cptx_pf_rd_req_pc_t;

static inline uint64_t BDK_CPTX_PF_RD_REQ_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_RD_REQ_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000010040ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000010040ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000010040ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_RD_REQ_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_RD_REQ_PC(a) bdk_cptx_pf_rd_req_pc_t
#define bustype_BDK_CPTX_PF_RD_REQ_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_RD_REQ_PC(a) "CPTX_PF_RD_REQ_PC"
#define device_bar_BDK_CPTX_PF_RD_REQ_PC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_RD_REQ_PC(a) (a)
#define arguments_BDK_CPTX_PF_RD_REQ_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_rd_uc_pc
 *
 * CPT PF Read Microcode Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_rd_uc_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of L2C read requests caused by are microcode fills. Microcode fills also
                                                                 increment CPT()_PF_RD_REQ_PC and CPT()_PF_RD_LATENCY_PC. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of L2C read requests caused by are microcode fills. Microcode fills also
                                                                 increment CPT()_PF_RD_REQ_PC and CPT()_PF_RD_LATENCY_PC. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_rd_uc_pc_s cn; */
} bdk_cptx_pf_rd_uc_pc_t;

static inline uint64_t BDK_CPTX_PF_RD_UC_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_RD_UC_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000010080ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000010080ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000010080ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_RD_UC_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_RD_UC_PC(a) bdk_cptx_pf_rd_uc_pc_t
#define bustype_BDK_CPTX_PF_RD_UC_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_RD_UC_PC(a) "CPTX_PF_RD_UC_PC"
#define device_bar_BDK_CPTX_PF_RD_UC_PC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_RD_UC_PC(a) (a)
#define arguments_BDK_CPTX_PF_RD_UC_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_reset
 *
 * CPT PF Reset Register
 * This register controls clock and reset.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_reset_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1) Reset one-shot pulse to reset CPT subsystem. */
#else /* Word 0 - Little Endian */
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1) Reset one-shot pulse to reset CPT subsystem. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_reset_s cn; */
} bdk_cptx_pf_reset_t;

static inline uint64_t BDK_CPTX_PF_RESET(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_RESET(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x872000000100ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x872000000100ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x872000000100ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("CPTX_PF_RESET", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPTX_PF_RESET(a) bdk_cptx_pf_reset_t
#define bustype_BDK_CPTX_PF_RESET(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_RESET(a) "CPTX_PF_RESET"
#define device_bar_BDK_CPTX_PF_RESET(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_RESET(a) (a)
#define arguments_BDK_CPTX_PF_RESET(a) (a),-1,-1,-1

/**
 * Register (NCB) cpt#_pf_vf#_mbox#
 *
 * CPT PF/VF Mailbox Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_pf_vfx_mboxx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These PF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. Each corresponding VF may access the same storage using
                                                                 CPT()_VF()_PF_MBOX(). MBOX(0) is typically used for PF to VF signaling, MBOX(1)
                                                                 for VF to PF. Writing CPT()_PF_VF()_MBOX(0) (but not
                                                                 CPT()_VF()_PF_MBOX(0)) will set the corresponding
                                                                 CPT()_VQ()_MISC_INT[MBOX] which if appropriately enabled will send an interrupt
                                                                 to the VF. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These PF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. Each corresponding VF may access the same storage using
                                                                 CPT()_VF()_PF_MBOX(). MBOX(0) is typically used for PF to VF signaling, MBOX(1)
                                                                 for VF to PF. Writing CPT()_PF_VF()_MBOX(0) (but not
                                                                 CPT()_VF()_PF_MBOX(0)) will set the corresponding
                                                                 CPT()_VQ()_MISC_INT[MBOX] which if appropriately enabled will send an interrupt
                                                                 to the VF. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_pf_vfx_mboxx_s cn; */
} bdk_cptx_pf_vfx_mboxx_t;

static inline uint64_t BDK_CPTX_PF_VFX_MBOXX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_PF_VFX_MBOXX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15) && (c<=1)))
        return 0x872008001000ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf) + 0x100ll * ((c) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63) && (c<=1)))
        return 0x872008001000ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f) + 0x100ll * ((c) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63) && (c<=1)))
        return 0x872008001000ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f) + 0x100ll * ((c) & 0x1);
    __bdk_csr_fatal("CPTX_PF_VFX_MBOXX", 3, a, b, c, 0);
}

#define typedef_BDK_CPTX_PF_VFX_MBOXX(a,b,c) bdk_cptx_pf_vfx_mboxx_t
#define bustype_BDK_CPTX_PF_VFX_MBOXX(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_PF_VFX_MBOXX(a,b,c) "CPTX_PF_VFX_MBOXX"
#define device_bar_BDK_CPTX_PF_VFX_MBOXX(a,b,c) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPTX_PF_VFX_MBOXX(a,b,c) (a)
#define arguments_BDK_CPTX_PF_VFX_MBOXX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) cpt#_vf#_msix_pba#
 *
 * CPT VF MSI-X Pending-Bit-Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the CPT_VF_INT_VEC_E
 * enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vfx_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated CPT()_PF_MSIX_VEC()_CTL, enumerated by
                                                                 CPT_PF_INT_VEC_E. Bits that have no associated CPT_PF_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated CPT()_PF_MSIX_VEC()_CTL, enumerated by
                                                                 CPT_PF_INT_VEC_E. Bits that have no associated CPT_PF_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_vfx_msix_pbax_s cn; */
} bdk_cptx_vfx_msix_pbax_t;

static inline uint64_t BDK_CPTX_VFX_MSIX_PBAX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VFX_MSIX_PBAX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15) && (c==0)))
        return 0x8720300f0000ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf) + 8ll * ((c) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63) && (c==0)))
        return 0x8720300f0000ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f) + 8ll * ((c) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63) && (c==0)))
        return 0x8720300f0000ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f) + 8ll * ((c) & 0x0);
    __bdk_csr_fatal("CPTX_VFX_MSIX_PBAX", 3, a, b, c, 0);
}

#define typedef_BDK_CPTX_VFX_MSIX_PBAX(a,b,c) bdk_cptx_vfx_msix_pbax_t
#define bustype_BDK_CPTX_VFX_MSIX_PBAX(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VFX_MSIX_PBAX(a,b,c) "CPTX_VFX_MSIX_PBAX"
#define device_bar_BDK_CPTX_VFX_MSIX_PBAX(a,b,c) 0x14 /* VF_BAR4 */
#define busnum_BDK_CPTX_VFX_MSIX_PBAX(a,b,c) (a)
#define arguments_BDK_CPTX_VFX_MSIX_PBAX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) cpt#_vf#_msix_vec#_addr
 *
 * CPT VF MSI-X Vector-Table Address Registers
 * This register is the MSI-X vector table, indexed by the CPT_VF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vfx_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](RAZ) Secure vector. Zero as not supported on a per-vector basis for VFs; use
                                                                 PCCPF_CPT_VSEC_SCTL[MSIX_SEC] instead (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]). */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](RAZ) Secure vector. Zero as not supported on a per-vector basis for VFs; use
                                                                 PCCPF_CPT_VSEC_SCTL[MSIX_SEC] instead (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]). */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_vfx_msix_vecx_addr_s cn; */
} bdk_cptx_vfx_msix_vecx_addr_t;

static inline uint64_t BDK_CPTX_VFX_MSIX_VECX_ADDR(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VFX_MSIX_VECX_ADDR(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15) && (c<=1)))
        return 0x872030000000ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf) + 0x10ll * ((c) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63) && (c<=1)))
        return 0x872030000000ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f) + 0x10ll * ((c) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63) && (c<=1)))
        return 0x872030000000ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f) + 0x10ll * ((c) & 0x1);
    __bdk_csr_fatal("CPTX_VFX_MSIX_VECX_ADDR", 3, a, b, c, 0);
}

#define typedef_BDK_CPTX_VFX_MSIX_VECX_ADDR(a,b,c) bdk_cptx_vfx_msix_vecx_addr_t
#define bustype_BDK_CPTX_VFX_MSIX_VECX_ADDR(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VFX_MSIX_VECX_ADDR(a,b,c) "CPTX_VFX_MSIX_VECX_ADDR"
#define device_bar_BDK_CPTX_VFX_MSIX_VECX_ADDR(a,b,c) 0x14 /* VF_BAR4 */
#define busnum_BDK_CPTX_VFX_MSIX_VECX_ADDR(a,b,c) (a)
#define arguments_BDK_CPTX_VFX_MSIX_VECX_ADDR(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) cpt#_vf#_msix_vec#_ctl
 *
 * CPT VF MSI-X Vector-Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the CPT_VF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vfx_msix_vecx_ctl_s
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
    /* struct bdk_cptx_vfx_msix_vecx_ctl_s cn; */
} bdk_cptx_vfx_msix_vecx_ctl_t;

static inline uint64_t BDK_CPTX_VFX_MSIX_VECX_CTL(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VFX_MSIX_VECX_CTL(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15) && (c<=1)))
        return 0x872030000008ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf) + 0x10ll * ((c) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63) && (c<=1)))
        return 0x872030000008ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f) + 0x10ll * ((c) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63) && (c<=1)))
        return 0x872030000008ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f) + 0x10ll * ((c) & 0x1);
    __bdk_csr_fatal("CPTX_VFX_MSIX_VECX_CTL", 3, a, b, c, 0);
}

#define typedef_BDK_CPTX_VFX_MSIX_VECX_CTL(a,b,c) bdk_cptx_vfx_msix_vecx_ctl_t
#define bustype_BDK_CPTX_VFX_MSIX_VECX_CTL(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VFX_MSIX_VECX_CTL(a,b,c) "CPTX_VFX_MSIX_VECX_CTL"
#define device_bar_BDK_CPTX_VFX_MSIX_VECX_CTL(a,b,c) 0x14 /* VF_BAR4 */
#define busnum_BDK_CPTX_VFX_MSIX_VECX_CTL(a,b,c) (a)
#define arguments_BDK_CPTX_VFX_MSIX_VECX_CTL(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) cpt#_vf#_pf_mbox#
 *
 * CPT VF/PF Mailbox Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vfx_pf_mboxx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These VF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. The PF may access the same storage using CPT()_PF_VF()_MBOX(). MBOX(0) is
                                                                 typically used for PF to VF signaling, MBOX(1) for VF to PF. Writing
                                                                 CPT()_VF()_PF_MBOX(1) (but not CPT()_PF_VF()_MBOX(1)) will set the
                                                                 corresponding CPT()_PF_MBOX_INT() bit, which if appropriately enabled will send an
                                                                 interrupt to the PF. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These VF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. The PF may access the same storage using CPT()_PF_VF()_MBOX(). MBOX(0) is
                                                                 typically used for PF to VF signaling, MBOX(1) for VF to PF. Writing
                                                                 CPT()_VF()_PF_MBOX(1) (but not CPT()_PF_VF()_MBOX(1)) will set the
                                                                 corresponding CPT()_PF_MBOX_INT() bit, which if appropriately enabled will send an
                                                                 interrupt to the PF. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_vfx_pf_mboxx_s cn; */
} bdk_cptx_vfx_pf_mboxx_t;

static inline uint64_t BDK_CPTX_VFX_PF_MBOXX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VFX_PF_MBOXX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15) && (c<=1)))
        return 0x872020001000ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf) + 8ll * ((c) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63) && (c<=1)))
        return 0x872020001000ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f) + 8ll * ((c) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63) && (c<=1)))
        return 0x872020001000ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f) + 8ll * ((c) & 0x1);
    __bdk_csr_fatal("CPTX_VFX_PF_MBOXX", 3, a, b, c, 0);
}

#define typedef_BDK_CPTX_VFX_PF_MBOXX(a,b,c) bdk_cptx_vfx_pf_mboxx_t
#define bustype_BDK_CPTX_VFX_PF_MBOXX(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VFX_PF_MBOXX(a,b,c) "CPTX_VFX_PF_MBOXX"
#define device_bar_BDK_CPTX_VFX_PF_MBOXX(a,b,c) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VFX_PF_MBOXX(a,b,c) (a)
#define arguments_BDK_CPTX_VFX_PF_MBOXX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) cpt#_vq#_ctl
 *
 * CPT VF Queue Control Registers
 * This register configures queues. This register should be changed (other than
 * clearing [ENA]) only when quiescent (see CPT()_VQ()_INPROG[INFLIGHT]).
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W/H) Enables the logical instruction queue. See also CPT()_PF_Q()_CTL[CONT_ERR] and
                                                                 CPT()_VQ()_INPROG[INFLIGHT].
                                                                 1 = Queue is enabled.
                                                                 0 = Queue is disabled. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W/H) Enables the logical instruction queue. See also CPT()_PF_Q()_CTL[CONT_ERR] and
                                                                 CPT()_VQ()_INPROG[INFLIGHT].
                                                                 1 = Queue is enabled.
                                                                 0 = Queue is disabled. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_vqx_ctl_s cn; */
} bdk_cptx_vqx_ctl_t;

static inline uint64_t BDK_CPTX_VQX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000100ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000100ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000100ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_CTL(a,b) bdk_cptx_vqx_ctl_t
#define bustype_BDK_CPTX_VQX_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_CTL(a,b) "CPTX_VQX_CTL"
#define device_bar_BDK_CPTX_VQX_CTL(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_CTL(a,b) (a)
#define arguments_BDK_CPTX_VQX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_vq#_done
 *
 * CPT Queue Done Count Registers
 * These registers contain the per-queue instruction done count.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_done_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t done                  : 20; /**< [ 19:  0](R/W/H) Done count. When CPT_INST_S[DONEINT] set and that instruction completes,
                                                                 CPT()_VQ()_DONE[DONE] is incremented when the instruction finishes. Write to
                                                                 this field are for diagnostic use only; instead software writes
                                                                 CPT()_VQ()_DONE_ACK with the number of decrements for this field.

                                                                 Interrupts are sent as follows:

                                                                 * When CPT()_VQ()_DONE[DONE] = 0, then no results are pending, the interrupt
                                                                 coalescing timer is held to zero, and an interrupt is not sent.

                                                                 * When CPT()_VQ()_DONE[DONE] != 0, then the interrupt coalescing timer
                                                                 counts. If the counter is >= CPT()_VQ()_DONE_WAIT[TIME_WAIT]*1024, or
                                                                 CPT()_VQ()_DONE[DONE] >= CPT()_VQ()_DONE_WAIT[NUM_WAIT], i.e. enough time has
                                                                 passed or enough results have arrived, then the interrupt is sent.  Otherwise,
                                                                 it is not sent due to coalescing.

                                                                 * When CPT()_VQ()_DONE_ACK is written (or CPT()_VQ()_DONE is written but this is
                                                                 not typical), the interrupt coalescing timer restarts.  Note after decrementing
                                                                 this interrupt equation is recomputed, for example if CPT()_VQ()_DONE[DONE] >=
                                                                 CPT()_VQ()_DONE_WAIT[NUM_WAIT] and because the timer is zero, the interrupt will
                                                                 be resent immediately.  (This covers the race case between software
                                                                 acknowledging an interrupt and a result returning.)

                                                                 * When CPT()_VQ()_DONE_ENA_W1S[DONE] = 0, interrupts are not sent, but the
                                                                 counting described above still occurs.

                                                                 Since CPT instructions complete out-of-order, if software is using completion
                                                                 interrupts the suggested scheme is to request a DONEINT on each request, and
                                                                 when an interrupt arrives perform a "greedy" scan for completions; even if a
                                                                 later command is acknowledged first this will not result in missing a
                                                                 completion.

                                                                 Software is responsible for making sure [DONE] does not overflow; for example by
                                                                 insuring there are not more than 2^20-1 instructions in flight that may request
                                                                 interrupts. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 20; /**< [ 19:  0](R/W/H) Done count. When CPT_INST_S[DONEINT] set and that instruction completes,
                                                                 CPT()_VQ()_DONE[DONE] is incremented when the instruction finishes. Write to
                                                                 this field are for diagnostic use only; instead software writes
                                                                 CPT()_VQ()_DONE_ACK with the number of decrements for this field.

                                                                 Interrupts are sent as follows:

                                                                 * When CPT()_VQ()_DONE[DONE] = 0, then no results are pending, the interrupt
                                                                 coalescing timer is held to zero, and an interrupt is not sent.

                                                                 * When CPT()_VQ()_DONE[DONE] != 0, then the interrupt coalescing timer
                                                                 counts. If the counter is >= CPT()_VQ()_DONE_WAIT[TIME_WAIT]*1024, or
                                                                 CPT()_VQ()_DONE[DONE] >= CPT()_VQ()_DONE_WAIT[NUM_WAIT], i.e. enough time has
                                                                 passed or enough results have arrived, then the interrupt is sent.  Otherwise,
                                                                 it is not sent due to coalescing.

                                                                 * When CPT()_VQ()_DONE_ACK is written (or CPT()_VQ()_DONE is written but this is
                                                                 not typical), the interrupt coalescing timer restarts.  Note after decrementing
                                                                 this interrupt equation is recomputed, for example if CPT()_VQ()_DONE[DONE] >=
                                                                 CPT()_VQ()_DONE_WAIT[NUM_WAIT] and because the timer is zero, the interrupt will
                                                                 be resent immediately.  (This covers the race case between software
                                                                 acknowledging an interrupt and a result returning.)

                                                                 * When CPT()_VQ()_DONE_ENA_W1S[DONE] = 0, interrupts are not sent, but the
                                                                 counting described above still occurs.

                                                                 Since CPT instructions complete out-of-order, if software is using completion
                                                                 interrupts the suggested scheme is to request a DONEINT on each request, and
                                                                 when an interrupt arrives perform a "greedy" scan for completions; even if a
                                                                 later command is acknowledged first this will not result in missing a
                                                                 completion.

                                                                 Software is responsible for making sure [DONE] does not overflow; for example by
                                                                 insuring there are not more than 2^20-1 instructions in flight that may request
                                                                 interrupts. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_vqx_done_s cn; */
} bdk_cptx_vqx_done_t;

static inline uint64_t BDK_CPTX_VQX_DONE(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_DONE(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000420ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000420ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000420ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_DONE", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_DONE(a,b) bdk_cptx_vqx_done_t
#define bustype_BDK_CPTX_VQX_DONE(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_DONE(a,b) "CPTX_VQX_DONE"
#define device_bar_BDK_CPTX_VQX_DONE(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_DONE(a,b) (a)
#define arguments_BDK_CPTX_VQX_DONE(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_vq#_done_ack
 *
 * CPT Queue Done Count Ack Registers
 * This register is written by software to acknowledge interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_done_ack_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t done_ack              : 20; /**< [ 19:  0](R/W/H) Number of decrements to CPT()_VQ()_DONE[DONE]. Reads CPT()_VQ()_DONE[DONE].

                                                                 Written by software to acknowledge interrupts. If CPT()_VQ()_DONE[DONE] is still
                                                                 nonzero the interrupt will be re-sent if the conditions described in
                                                                 CPT()_VQ()_DONE[DONE] are satisfied. */
#else /* Word 0 - Little Endian */
        uint64_t done_ack              : 20; /**< [ 19:  0](R/W/H) Number of decrements to CPT()_VQ()_DONE[DONE]. Reads CPT()_VQ()_DONE[DONE].

                                                                 Written by software to acknowledge interrupts. If CPT()_VQ()_DONE[DONE] is still
                                                                 nonzero the interrupt will be re-sent if the conditions described in
                                                                 CPT()_VQ()_DONE[DONE] are satisfied. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_vqx_done_ack_s cn; */
} bdk_cptx_vqx_done_ack_t;

static inline uint64_t BDK_CPTX_VQX_DONE_ACK(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_DONE_ACK(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000440ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000440ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000440ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_DONE_ACK", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_DONE_ACK(a,b) bdk_cptx_vqx_done_ack_t
#define bustype_BDK_CPTX_VQX_DONE_ACK(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_DONE_ACK(a,b) "CPTX_VQX_DONE_ACK"
#define device_bar_BDK_CPTX_VQX_DONE_ACK(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_DONE_ACK(a,b) (a)
#define arguments_BDK_CPTX_VQX_DONE_ACK(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_vq#_done_ena_w1c
 *
 * CPT Queue Done Interrupt Enable Clear Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_done_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done                  : 1;  /**< [  0:  0](R/W1C/H) Read or clears CPT()_VQ()_DONE_ENA_W1S[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1C/H) Read or clears CPT()_VQ()_DONE_ENA_W1S[DONE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_vqx_done_ena_w1c_s cn; */
} bdk_cptx_vqx_done_ena_w1c_t;

static inline uint64_t BDK_CPTX_VQX_DONE_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_DONE_ENA_W1C(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000478ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000478ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000478ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_DONE_ENA_W1C", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_DONE_ENA_W1C(a,b) bdk_cptx_vqx_done_ena_w1c_t
#define bustype_BDK_CPTX_VQX_DONE_ENA_W1C(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_DONE_ENA_W1C(a,b) "CPTX_VQX_DONE_ENA_W1C"
#define device_bar_BDK_CPTX_VQX_DONE_ENA_W1C(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_DONE_ENA_W1C(a,b) (a)
#define arguments_BDK_CPTX_VQX_DONE_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_vq#_done_ena_w1s
 *
 * CPT Queue Done Interrupt Enable Set Registers
 * Write 1 to these registers will enable the DONEINT interrupt for the queue.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_done_ena_w1s_s
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
    /* struct bdk_cptx_vqx_done_ena_w1s_s cn; */
} bdk_cptx_vqx_done_ena_w1s_t;

static inline uint64_t BDK_CPTX_VQX_DONE_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_DONE_ENA_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000470ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000470ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000470ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_DONE_ENA_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_DONE_ENA_W1S(a,b) bdk_cptx_vqx_done_ena_w1s_t
#define bustype_BDK_CPTX_VQX_DONE_ENA_W1S(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_DONE_ENA_W1S(a,b) "CPTX_VQX_DONE_ENA_W1S"
#define device_bar_BDK_CPTX_VQX_DONE_ENA_W1S(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_DONE_ENA_W1S(a,b) (a)
#define arguments_BDK_CPTX_VQX_DONE_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_vq#_done_int_w1c
 *
 * CPT Queue Done Interrupt Clear Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_done_int_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done                  : 1;  /**< [  0:  0](RO/H) Done interrupt. See CPT()_VQ()_DONE[DONE].  Note this bit is read-only, to acknowledge
                                                                 interrupts use CPT()_VQ()_DONE_ACK. To test interrupts, write nonzero to
                                                                 CPT()_VQ()_DONE[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](RO/H) Done interrupt. See CPT()_VQ()_DONE[DONE].  Note this bit is read-only, to acknowledge
                                                                 interrupts use CPT()_VQ()_DONE_ACK. To test interrupts, write nonzero to
                                                                 CPT()_VQ()_DONE[DONE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_vqx_done_int_w1c_s cn; */
} bdk_cptx_vqx_done_int_w1c_t;

static inline uint64_t BDK_CPTX_VQX_DONE_INT_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_DONE_INT_W1C(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000468ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000468ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000468ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_DONE_INT_W1C", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_DONE_INT_W1C(a,b) bdk_cptx_vqx_done_int_w1c_t
#define bustype_BDK_CPTX_VQX_DONE_INT_W1C(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_DONE_INT_W1C(a,b) "CPTX_VQX_DONE_INT_W1C"
#define device_bar_BDK_CPTX_VQX_DONE_INT_W1C(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_DONE_INT_W1C(a,b) (a)
#define arguments_BDK_CPTX_VQX_DONE_INT_W1C(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_vq#_done_int_w1s
 *
 * CPT Queue Done Interrupt Set Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_done_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done                  : 1;  /**< [  0:  0](RO/H) Done interrupt. See CPT()_VQ()_DONE[DONE].  Note this bit is read-only, to acknowledge
                                                                 interrupts use CPT()_VQ()_DONE_ACK. To test interrupts, write nonzero to
                                                                 CPT()_VQ()_DONE[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](RO/H) Done interrupt. See CPT()_VQ()_DONE[DONE].  Note this bit is read-only, to acknowledge
                                                                 interrupts use CPT()_VQ()_DONE_ACK. To test interrupts, write nonzero to
                                                                 CPT()_VQ()_DONE[DONE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_vqx_done_int_w1s_s cn; */
} bdk_cptx_vqx_done_int_w1s_t;

static inline uint64_t BDK_CPTX_VQX_DONE_INT_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_DONE_INT_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000460ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000460ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000460ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_DONE_INT_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_DONE_INT_W1S(a,b) bdk_cptx_vqx_done_int_w1s_t
#define bustype_BDK_CPTX_VQX_DONE_INT_W1S(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_DONE_INT_W1S(a,b) "CPTX_VQX_DONE_INT_W1S"
#define device_bar_BDK_CPTX_VQX_DONE_INT_W1S(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_DONE_INT_W1S(a,b) (a)
#define arguments_BDK_CPTX_VQX_DONE_INT_W1S(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_vq#_done_wait
 *
 * CPT Queue Done Interrupt Coalescing Wait Registers
 * Specifies the per queue interrupt coalescing settings.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_done_wait_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t time_wait             : 16; /**< [ 47: 32](R/W) Time hold-off. When CPT()_VQ()_DONE[DONE] = 0, or CPT()_VQ()_DONE_ACK is written
                                                                 a timer is cleared. When the timer reaches [TIME_WAIT]*1024 then interrupt
                                                                 coalescing ends; see CPT()_VQ()_DONE[DONE]. If 0x0, time coalescing is disabled. */
        uint64_t reserved_20_31        : 12;
        uint64_t num_wait              : 20; /**< [ 19:  0](R/W) Number of messages hold-off. When CPT()_VQ()_DONE[DONE] >= [NUM_WAIT] then
                                                                 interrupt coalescing ends; see CPT()_VQ()_DONE[DONE]. If 0x0, same behavior as
                                                                 0x1. */
#else /* Word 0 - Little Endian */
        uint64_t num_wait              : 20; /**< [ 19:  0](R/W) Number of messages hold-off. When CPT()_VQ()_DONE[DONE] >= [NUM_WAIT] then
                                                                 interrupt coalescing ends; see CPT()_VQ()_DONE[DONE]. If 0x0, same behavior as
                                                                 0x1. */
        uint64_t reserved_20_31        : 12;
        uint64_t time_wait             : 16; /**< [ 47: 32](R/W) Time hold-off. When CPT()_VQ()_DONE[DONE] = 0, or CPT()_VQ()_DONE_ACK is written
                                                                 a timer is cleared. When the timer reaches [TIME_WAIT]*1024 then interrupt
                                                                 coalescing ends; see CPT()_VQ()_DONE[DONE]. If 0x0, time coalescing is disabled. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_vqx_done_wait_s cn; */
} bdk_cptx_vqx_done_wait_t;

static inline uint64_t BDK_CPTX_VQX_DONE_WAIT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_DONE_WAIT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000400ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000400ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000400ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_DONE_WAIT", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_DONE_WAIT(a,b) bdk_cptx_vqx_done_wait_t
#define bustype_BDK_CPTX_VQX_DONE_WAIT(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_DONE_WAIT(a,b) "CPTX_VQX_DONE_WAIT"
#define device_bar_BDK_CPTX_VQX_DONE_WAIT(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_DONE_WAIT(a,b) (a)
#define arguments_BDK_CPTX_VQX_DONE_WAIT(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_vq#_doorbell
 *
 * CPT Queue Doorbell Registers
 * Doorbells for the CPT instruction queues.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_doorbell_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t dbell_cnt             : 20; /**< [ 19:  0](R/W/H) Number of instruction queue 64-bit words to add to the CPT instruction doorbell
                                                                 count. Readback value is the the current number of pending doorbell requests.

                                                                 If counter overflows CPT()_VQ()_MISC_INT[DBELL_DOVF] is set.

                                                                 To reset the count back to zero, write one to clear
                                                                 CPT()_VQ()_MISC_INT_ENA_W1C[DBELL_DOVF], then write a value of 2^20 minus the
                                                                 read [DBELL_CNT], then write one to CPT()_VQ()_MISC_INT_W1C[DBELL_DOVF] and
                                                                 CPT()_VQ()_MISC_INT_ENA_W1S[DBELL_DOVF].

                                                                 Must be a multiple of 8.  All CPT instructions are 8 words and require a
                                                                 doorbell count of multiple of 8. */
#else /* Word 0 - Little Endian */
        uint64_t dbell_cnt             : 20; /**< [ 19:  0](R/W/H) Number of instruction queue 64-bit words to add to the CPT instruction doorbell
                                                                 count. Readback value is the the current number of pending doorbell requests.

                                                                 If counter overflows CPT()_VQ()_MISC_INT[DBELL_DOVF] is set.

                                                                 To reset the count back to zero, write one to clear
                                                                 CPT()_VQ()_MISC_INT_ENA_W1C[DBELL_DOVF], then write a value of 2^20 minus the
                                                                 read [DBELL_CNT], then write one to CPT()_VQ()_MISC_INT_W1C[DBELL_DOVF] and
                                                                 CPT()_VQ()_MISC_INT_ENA_W1S[DBELL_DOVF].

                                                                 Must be a multiple of 8.  All CPT instructions are 8 words and require a
                                                                 doorbell count of multiple of 8. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_vqx_doorbell_s cn; */
} bdk_cptx_vqx_doorbell_t;

static inline uint64_t BDK_CPTX_VQX_DOORBELL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_DOORBELL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000600ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000600ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000600ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_DOORBELL", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_DOORBELL(a,b) bdk_cptx_vqx_doorbell_t
#define bustype_BDK_CPTX_VQX_DOORBELL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_DOORBELL(a,b) "CPTX_VQX_DOORBELL"
#define device_bar_BDK_CPTX_VQX_DOORBELL(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_DOORBELL(a,b) (a)
#define arguments_BDK_CPTX_VQX_DOORBELL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_vq#_inprog
 *
 * CPT Queue In Progress Count Registers
 * These registers contain the per-queue instruction in flight registers.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_inprog_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t inflight              : 8;  /**< [  7:  0](RO/H) Inflight count. Counts the number of instructions for the VF for which CPT is
                                                                 fetching, executing or responding to instructions. However this does not include
                                                                 any interrupts that are awaiting software handling (CPT()_VQ()_DONE[DONE] !=
                                                                 0x0).

                                                                 A queue may not be reconfigured until:
                                                                   1. CPT()_VQ()_CTL[ENA] is cleared by software.
                                                                   2. [INFLIGHT] is polled until equals to zero. */
#else /* Word 0 - Little Endian */
        uint64_t inflight              : 8;  /**< [  7:  0](RO/H) Inflight count. Counts the number of instructions for the VF for which CPT is
                                                                 fetching, executing or responding to instructions. However this does not include
                                                                 any interrupts that are awaiting software handling (CPT()_VQ()_DONE[DONE] !=
                                                                 0x0).

                                                                 A queue may not be reconfigured until:
                                                                   1. CPT()_VQ()_CTL[ENA] is cleared by software.
                                                                   2. [INFLIGHT] is polled until equals to zero. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_vqx_inprog_s cn; */
} bdk_cptx_vqx_inprog_t;

static inline uint64_t BDK_CPTX_VQX_INPROG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_INPROG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000410ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000410ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000410ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_INPROG", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_INPROG(a,b) bdk_cptx_vqx_inprog_t
#define bustype_BDK_CPTX_VQX_INPROG(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_INPROG(a,b) "CPTX_VQX_INPROG"
#define device_bar_BDK_CPTX_VQX_INPROG(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_INPROG(a,b) (a)
#define arguments_BDK_CPTX_VQX_INPROG(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_vq#_misc_ena_w1c
 *
 * CPT Queue Misc Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_misc_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t swerr                 : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CPT(0..1)_VQ(0..63)_MISC_INT[SWERR]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CPT(0..1)_VQ(0..63)_MISC_INT[NWRP]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CPT(0..1)_VQ(0..63)_MISC_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CPT(0..1)_VQ(0..63)_MISC_INT[DOVF]. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CPT(0..1)_VQ(0..63)_MISC_INT[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CPT(0..1)_VQ(0..63)_MISC_INT[MBOX]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CPT(0..1)_VQ(0..63)_MISC_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CPT(0..1)_VQ(0..63)_MISC_INT[IRDE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CPT(0..1)_VQ(0..63)_MISC_INT[NWRP]. */
        uint64_t swerr                 : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CPT(0..1)_VQ(0..63)_MISC_INT[SWERR]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_vqx_misc_ena_w1c_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t swerr                 : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CPT(0)_VQ(0..15)_MISC_INT[SWERR]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CPT(0)_VQ(0..15)_MISC_INT[NWRP]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CPT(0)_VQ(0..15)_MISC_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CPT(0)_VQ(0..15)_MISC_INT[DOVF]. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CPT(0)_VQ(0..15)_MISC_INT[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CPT(0)_VQ(0..15)_MISC_INT[MBOX]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CPT(0)_VQ(0..15)_MISC_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CPT(0)_VQ(0..15)_MISC_INT[IRDE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CPT(0)_VQ(0..15)_MISC_INT[NWRP]. */
        uint64_t swerr                 : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CPT(0)_VQ(0..15)_MISC_INT[SWERR]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_vqx_misc_ena_w1c_s cn83xx; */
    /* struct bdk_cptx_vqx_misc_ena_w1c_s cn9; */
} bdk_cptx_vqx_misc_ena_w1c_t;

static inline uint64_t BDK_CPTX_VQX_MISC_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_MISC_ENA_W1C(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000518ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000518ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000518ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_MISC_ENA_W1C", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_MISC_ENA_W1C(a,b) bdk_cptx_vqx_misc_ena_w1c_t
#define bustype_BDK_CPTX_VQX_MISC_ENA_W1C(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_MISC_ENA_W1C(a,b) "CPTX_VQX_MISC_ENA_W1C"
#define device_bar_BDK_CPTX_VQX_MISC_ENA_W1C(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_MISC_ENA_W1C(a,b) (a)
#define arguments_BDK_CPTX_VQX_MISC_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_vq#_misc_ena_w1s
 *
 * CPT Queue Misc Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_misc_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t swerr                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CPT(0..1)_VQ(0..63)_MISC_INT[SWERR]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CPT(0..1)_VQ(0..63)_MISC_INT[NWRP]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CPT(0..1)_VQ(0..63)_MISC_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CPT(0..1)_VQ(0..63)_MISC_INT[DOVF]. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CPT(0..1)_VQ(0..63)_MISC_INT[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CPT(0..1)_VQ(0..63)_MISC_INT[MBOX]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CPT(0..1)_VQ(0..63)_MISC_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CPT(0..1)_VQ(0..63)_MISC_INT[IRDE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CPT(0..1)_VQ(0..63)_MISC_INT[NWRP]. */
        uint64_t swerr                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CPT(0..1)_VQ(0..63)_MISC_INT[SWERR]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_vqx_misc_ena_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t swerr                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CPT(0)_VQ(0..15)_MISC_INT[SWERR]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CPT(0)_VQ(0..15)_MISC_INT[NWRP]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CPT(0)_VQ(0..15)_MISC_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CPT(0)_VQ(0..15)_MISC_INT[DOVF]. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CPT(0)_VQ(0..15)_MISC_INT[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CPT(0)_VQ(0..15)_MISC_INT[MBOX]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CPT(0)_VQ(0..15)_MISC_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CPT(0)_VQ(0..15)_MISC_INT[IRDE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CPT(0)_VQ(0..15)_MISC_INT[NWRP]. */
        uint64_t swerr                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CPT(0)_VQ(0..15)_MISC_INT[SWERR]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_vqx_misc_ena_w1s_s cn83xx; */
    /* struct bdk_cptx_vqx_misc_ena_w1s_s cn9; */
} bdk_cptx_vqx_misc_ena_w1s_t;

static inline uint64_t BDK_CPTX_VQX_MISC_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_MISC_ENA_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000510ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000510ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000510ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_MISC_ENA_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_MISC_ENA_W1S(a,b) bdk_cptx_vqx_misc_ena_w1s_t
#define bustype_BDK_CPTX_VQX_MISC_ENA_W1S(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_MISC_ENA_W1S(a,b) "CPTX_VQX_MISC_ENA_W1S"
#define device_bar_BDK_CPTX_VQX_MISC_ENA_W1S(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_MISC_ENA_W1S(a,b) (a)
#define arguments_BDK_CPTX_VQX_MISC_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_vq#_misc_int
 *
 * CPT Queue Misc Interrupt Register
 * These registers contain the per-queue miscellaneous interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_misc_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t swerr                 : 1;  /**< [  4:  4](R/W1C/H) Software error from engines. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) NCB result write response error. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1C/H) Instruction NCB read response error. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1C/H) Doorbell overflow. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1C/H) PF to VF mailbox interrupt. Set when CPT()_VF()_PF_MBOX(0)
                                                                 is written. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1C/H) PF to VF mailbox interrupt. Set when CPT()_VF()_PF_MBOX(0)
                                                                 is written. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1C/H) Doorbell overflow. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1C/H) Instruction NCB read response error. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) NCB result write response error. */
        uint64_t swerr                 : 1;  /**< [  4:  4](R/W1C/H) Software error from engines. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_vqx_misc_int_s cn; */
} bdk_cptx_vqx_misc_int_t;

static inline uint64_t BDK_CPTX_VQX_MISC_INT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_MISC_INT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000500ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000500ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000500ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_MISC_INT", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_MISC_INT(a,b) bdk_cptx_vqx_misc_int_t
#define bustype_BDK_CPTX_VQX_MISC_INT(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_MISC_INT(a,b) "CPTX_VQX_MISC_INT"
#define device_bar_BDK_CPTX_VQX_MISC_INT(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_MISC_INT(a,b) (a)
#define arguments_BDK_CPTX_VQX_MISC_INT(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_vq#_misc_int_w1s
 *
 * CPT Queue Misc Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_misc_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t swerr                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CPT(0..1)_VQ(0..63)_MISC_INT[SWERR]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CPT(0..1)_VQ(0..63)_MISC_INT[NWRP]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CPT(0..1)_VQ(0..63)_MISC_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CPT(0..1)_VQ(0..63)_MISC_INT[DOVF]. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CPT(0..1)_VQ(0..63)_MISC_INT[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CPT(0..1)_VQ(0..63)_MISC_INT[MBOX]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CPT(0..1)_VQ(0..63)_MISC_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CPT(0..1)_VQ(0..63)_MISC_INT[IRDE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CPT(0..1)_VQ(0..63)_MISC_INT[NWRP]. */
        uint64_t swerr                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CPT(0..1)_VQ(0..63)_MISC_INT[SWERR]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    struct bdk_cptx_vqx_misc_int_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t swerr                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CPT(0)_VQ(0..15)_MISC_INT[SWERR]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CPT(0)_VQ(0..15)_MISC_INT[NWRP]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CPT(0)_VQ(0..15)_MISC_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CPT(0)_VQ(0..15)_MISC_INT[DOVF]. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CPT(0)_VQ(0..15)_MISC_INT[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CPT(0)_VQ(0..15)_MISC_INT[MBOX]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CPT(0)_VQ(0..15)_MISC_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CPT(0)_VQ(0..15)_MISC_INT[IRDE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CPT(0)_VQ(0..15)_MISC_INT[NWRP]. */
        uint64_t swerr                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CPT(0)_VQ(0..15)_MISC_INT[SWERR]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_cptx_vqx_misc_int_w1s_s cn83xx; */
    /* struct bdk_cptx_vqx_misc_int_w1s_s cn9; */
} bdk_cptx_vqx_misc_int_w1s_t;

static inline uint64_t BDK_CPTX_VQX_MISC_INT_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_MISC_INT_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000508ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000508ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000508ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_MISC_INT_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_MISC_INT_W1S(a,b) bdk_cptx_vqx_misc_int_w1s_t
#define bustype_BDK_CPTX_VQX_MISC_INT_W1S(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_MISC_INT_W1S(a,b) "CPTX_VQX_MISC_INT_W1S"
#define device_bar_BDK_CPTX_VQX_MISC_INT_W1S(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_MISC_INT_W1S(a,b) (a)
#define arguments_BDK_CPTX_VQX_MISC_INT_W1S(a,b) (a),(b),-1,-1

/**
 * Register (NCB) cpt#_vq#_saddr
 *
 * CPT Queue Starting Buffer Address Registers
 * These registers set the instruction buffer starting address.
 */
typedef union
{
    uint64_t u;
    struct bdk_cptx_vqx_saddr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t ptr                   : 43; /**< [ 48:  6](R/W/H) Instruction buffer IOVA <48:6> (64-byte aligned). When written, it is the initial
                                                                 buffer starting address; when read, it is the next read pointer to be requested from L2C.
                                                                 The PTR field is overwritten with the next pointer each time that the command buffer
                                                                 segment is exhausted. New commands will then be read from the newly specified command
                                                                 buffer pointer. */
        uint64_t reserved_0_5          : 6;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_5          : 6;
        uint64_t ptr                   : 43; /**< [ 48:  6](R/W/H) Instruction buffer IOVA <48:6> (64-byte aligned). When written, it is the initial
                                                                 buffer starting address; when read, it is the next read pointer to be requested from L2C.
                                                                 The PTR field is overwritten with the next pointer each time that the command buffer
                                                                 segment is exhausted. New commands will then be read from the newly specified command
                                                                 buffer pointer. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cptx_vqx_saddr_s cn; */
} bdk_cptx_vqx_saddr_t;

static inline uint64_t BDK_CPTX_VQX_SADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPTX_VQX_SADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=15)))
        return 0x872020000200ll + 0x1000000000ll * ((a) & 0x0) + 0x100000ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x872020000200ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=1) && (b<=63)))
        return 0x872020000200ll + 0x1000000000ll * ((a) & 0x1) + 0x100000ll * ((b) & 0x3f);
    __bdk_csr_fatal("CPTX_VQX_SADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_CPTX_VQX_SADDR(a,b) bdk_cptx_vqx_saddr_t
#define bustype_BDK_CPTX_VQX_SADDR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_CPTX_VQX_SADDR(a,b) "CPTX_VQX_SADDR"
#define device_bar_BDK_CPTX_VQX_SADDR(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_CPTX_VQX_SADDR(a,b) (a)
#define arguments_BDK_CPTX_VQX_SADDR(a,b) (a),(b),-1,-1

#endif /* __BDK_CSRS_CPT_H__ */
