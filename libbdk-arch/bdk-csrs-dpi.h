#ifndef __BDK_CSRS_DPI_H__
#define __BDK_CSRS_DPI_H__
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
 * Cavium DPI.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration dpi_bar_e
 *
 * DPI Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_DPI_BAR_E_DPIX_PF_BAR0(a) (0x86e000000000ll + 0x10000000000ll * (a))
#define BDK_DPI_BAR_E_DPIX_PF_BAR4(a) (0x86e001000000ll + 0x10000000000ll * (a))

/**
 * Enumeration dpi_cs_e
 *
 * DPI Completion Status Enumeration
 * Enumerates the completion status return values.
 */
#define BDK_DPI_CS_E_ERRRSP (3)
#define BDK_DPI_CS_E_NOERR (0)
#define BDK_DPI_CS_E_RDRST (1)
#define BDK_DPI_CS_E_WRRST (2)

/**
 * Enumeration dpi_endianswap_e
 *
 * SLI/DPI Endian Swap Mode Enumeration
 * Enumerates the endian swap modes that SLI and DPI support.
 */
#define BDK_DPI_ENDIANSWAP_E_BYTE_SWAP_32B (2)
#define BDK_DPI_ENDIANSWAP_E_BYTE_SWAP_64B (1)
#define BDK_DPI_ENDIANSWAP_E_LW_SWAP_64B (3)
#define BDK_DPI_ENDIANSWAP_E_PASS_THRU (0)

/**
 * Enumeration dpi_hdr_pt_e
 *
 * DPI Header Pointer Type Enumeration
 * Enumerates the pointer type in DPI_DMA_INSTR_HDR_S[PT].
 */
#define BDK_DPI_HDR_PT_E_CNT (3)
#define BDK_DPI_HDR_PT_E_WQP (2)
#define BDK_DPI_HDR_PT_E_ZBW_CA (0)
#define BDK_DPI_HDR_PT_E_ZBW_NC (1)

/**
 * Enumeration dpi_hdr_pt_wqp_e
 *
 * DPI DMA Instruction Header Work Queue Pointer <2:0> Enumeration
 *
 * The DPI_DMA_INSTR_HDR_S[PTR<2:0>] encoding when DPI_DMA_INSTR_HDR_S[PT] is
 * DPI_HDR_PT_E::WQP.
 */
#define BDK_DPI_HDR_PT_WQP_E_NOSTATUS (0)
#define BDK_DPI_HDR_PT_WQP_E_STATUSCA (1)
#define BDK_DPI_HDR_PT_WQP_E_STATUSNC (3)

/**
 * Enumeration dpi_hdr_xtype_e
 *
 * DPI Transfer Type Enumeration
 * Enumerates the pointer type in DPI_DMA_INSTR_HDR_S[XTYPE].
 */
#define BDK_DPI_HDR_XTYPE_E_EXTERNAL_ONLY (3)
#define BDK_DPI_HDR_XTYPE_E_INBOUND (1)
#define BDK_DPI_HDR_XTYPE_E_INTERNAL_ONLY (2)
#define BDK_DPI_HDR_XTYPE_E_OUTBOUND (0)

/**
 * Enumeration dpi_int_vec_e
 *
 * DPI MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_DPI_INT_VEC_E_DPI_CCX_INT(a) (0 + (a))
#define BDK_DPI_INT_VEC_E_DPI_DBE_INT (0x42)
#define BDK_DPI_INT_VEC_E_DPI_INT_REG (0x40)
#define BDK_DPI_INT_VEC_E_DPI_SBE_INT (0x41)

/**
 * Structure dpi_dma_func_sel_s
 *
 * DPI DMA Function Selector Structure
 * DPI DMA function selector for MACs
 */
union bdk_dpi_dma_func_sel_s
{
    uint32_t u;
    struct bdk_dpi_dma_func_sel_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t pf                    : 3;  /**< [ 15: 13] Selects the PCIe physical function within the referenced MAC.

                                                                 [PF] must select a valid physical function in a PCIe MAC.
                                                                 SPEM_EP_FUNCTIONS_E (MAC=0) and PEM_EP_FUNCTIONS_E (MAC=1..3)
                                                                 list possible physical functions.

                                                                 [PF] must be zero for any non-PCIe MAC. */
        uint32_t func                  : 13; /**< [ 12:  0] Selects the function within the physical function [PF]
                                                                 within the referenced MAC.

                                                                 0x0 = The physical function [PF].
                                                                 0x1 = The first virtual function within the physical function [PF].
                                                                 0x2 = The second virtual function within the physical function [PF].
                                                                 0x3 = ...

                                                                 When [FUNC] is nonzero, it must select a valid virtual
                                                                 function. SPEM_EP_FUNCTIONS_E (MAC=0) and PEM_EP_FUNCTIONS_E (MAC=1..3)
                                                                 indicate the possible virtual functions for each [PF], but note
                                                                 that their encodings may not match the [FUNC] encoding.

                                                                 [FUNC] must be zero for any MAC that isn't PCIe, doesn't
                                                                 support the PCIe SR-IOV standard, or doesn't have PCIe SR-IOV
                                                                 enabled. */
#else /* Word 0 - Little Endian */
        uint32_t func                  : 13; /**< [ 12:  0] Selects the function within the physical function [PF]
                                                                 within the referenced MAC.

                                                                 0x0 = The physical function [PF].
                                                                 0x1 = The first virtual function within the physical function [PF].
                                                                 0x2 = The second virtual function within the physical function [PF].
                                                                 0x3 = ...

                                                                 When [FUNC] is nonzero, it must select a valid virtual
                                                                 function. SPEM_EP_FUNCTIONS_E (MAC=0) and PEM_EP_FUNCTIONS_E (MAC=1..3)
                                                                 indicate the possible virtual functions for each [PF], but note
                                                                 that their encodings may not match the [FUNC] encoding.

                                                                 [FUNC] must be zero for any MAC that isn't PCIe, doesn't
                                                                 support the PCIe SR-IOV standard, or doesn't have PCIe SR-IOV
                                                                 enabled. */
        uint32_t pf                    : 3;  /**< [ 15: 13] Selects the PCIe physical function within the referenced MAC.

                                                                 [PF] must select a valid physical function in a PCIe MAC.
                                                                 SPEM_EP_FUNCTIONS_E (MAC=0) and PEM_EP_FUNCTIONS_E (MAC=1..3)
                                                                 list possible physical functions.

                                                                 [PF] must be zero for any non-PCIe MAC. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpi_dma_func_sel_s_s cn; */
};

/**
 * Structure dpi_dma_instr_hdr_s
 *
 * DPI DMA Instruction Header Structure
 * DPI DMA Instruction Header Format
 */
union bdk_dpi_dma_instr_hdr_s
{
    uint64_t u[4];
    struct bdk_dpi_dma_instr_hdr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t nlst                  : 4;  /**< [ 57: 54] The number of pointers in the last-pointers block.

                                                                 With DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::OUTBOUND, and
                                                                 DPI_HDR_XTYPE_E:EXTERNAL_ONLY instructions, the last pointers block
                                                                 contains [NLST] MAC pointers via DPI components, and is

                                                                 _  [NLST] + (([NLST] + 3)/4)

                                                                 64-bit words, where the division removes the fraction.

                                                                 With DPI_HDR_XTYPE_E:INTERNAL_ONLY instructions, the last pointers block
                                                                 includes [NLST] DPI_DMA_LOCAL_PTR_S local pointers, and is
                                                                 [NLST] 64-bit words.

                                                                 Note that the sum of the number of 64-bit words in the last pointers block
                                                                 and first pointers block must never exceed 30. */
        uint64_t reserved_52_53        : 2;
        uint64_t nfst                  : 4;  /**< [ 51: 48] The number of pointers in the first pointers block.

                                                                 With DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::OUTBOUND, and
                                                                 DPI_HDR_XTYPE_E:INTERNAL_ONLY instructions, the first pointers block
                                                                 includes [NFST] DPI_DMA_LOCAL_PTR_S local pointers, and is
                                                                 [NFST] 64-bit words.

                                                                 With DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, the first pointers
                                                                 block includes [NFST] MAC pointers via DPI components, and is

                                                                   _ [NFST] + (([NFST] + 3)/4)

                                                                 64-bit words, where the division removes the fraction.

                                                                 Note that the sum of the number of 64-bit words in the last pointers block
                                                                 and first pointers block must never exceed 30. */
        uint64_t reserved_44_47        : 4;
        uint64_t grp                   : 10; /**< [ 43: 34] SSO guest-group. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.
                                                                 For the SSO to not discard the add-work request, SSO_PF_MAP() must map
                                                                 [GRP] and DPI()_DMA()_IDS[GMID] as valid.

                                                                 [GRP] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t tt                    : 2;  /**< [ 33: 32] SSO tag type. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.

                                                                 [TT] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t tag                   : 32; /**< [ 31:  0] SSO Tag */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0] SSO Tag */
        uint64_t tt                    : 2;  /**< [ 33: 32] SSO tag type. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.

                                                                 [TT] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t grp                   : 10; /**< [ 43: 34] SSO guest-group. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.
                                                                 For the SSO to not discard the add-work request, SSO_PF_MAP() must map
                                                                 [GRP] and DPI()_DMA()_IDS[GMID] as valid.

                                                                 [GRP] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t reserved_44_47        : 4;
        uint64_t nfst                  : 4;  /**< [ 51: 48] The number of pointers in the first pointers block.

                                                                 With DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::OUTBOUND, and
                                                                 DPI_HDR_XTYPE_E:INTERNAL_ONLY instructions, the first pointers block
                                                                 includes [NFST] DPI_DMA_LOCAL_PTR_S local pointers, and is
                                                                 [NFST] 64-bit words.

                                                                 With DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, the first pointers
                                                                 block includes [NFST] MAC pointers via DPI components, and is

                                                                   _ [NFST] + (([NFST] + 3)/4)

                                                                 64-bit words, where the division removes the fraction.

                                                                 Note that the sum of the number of 64-bit words in the last pointers block
                                                                 and first pointers block must never exceed 30. */
        uint64_t reserved_52_53        : 2;
        uint64_t nlst                  : 4;  /**< [ 57: 54] The number of pointers in the last-pointers block.

                                                                 With DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::OUTBOUND, and
                                                                 DPI_HDR_XTYPE_E:EXTERNAL_ONLY instructions, the last pointers block
                                                                 contains [NLST] MAC pointers via DPI components, and is

                                                                 _  [NLST] + (([NLST] + 3)/4)

                                                                 64-bit words, where the division removes the fraction.

                                                                 With DPI_HDR_XTYPE_E:INTERNAL_ONLY instructions, the last pointers block
                                                                 includes [NLST] DPI_DMA_LOCAL_PTR_S local pointers, and is
                                                                 [NLST] 64-bit words.

                                                                 Note that the sum of the number of 64-bit words in the last pointers block
                                                                 and first pointers block must never exceed 30. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_126_127      : 2;
        uint64_t lport                 : 2;  /**< [125:124] Port for the last pointers block.

                                                                 DPI sends MAC memory space reads and writes for the MAC addresses
                                                                 in the last pointers block to the MAC selected by [LPORT]
                                                                 while processing DPI_HDR_XTYPE_E::OUTBOUND, DPI_HDR_XTYPE_E::INBOUND,
                                                                 and DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions.

                                                                 [LPORT<0>] normally determines the IOI/NCB DPI uses for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions.

                                                                 [LPORT<1>] must be zero for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions. */
        uint64_t reserved_122_123      : 2;
        uint64_t fport                 : 2;  /**< [121:120] Port for the first pointers block.

                                                                 DPI sends MAC memory space reads for the MAC addresses in the first
                                                                 pointers block to the MAC selected by [FPORT] while processing
                                                                 a DPI_HDR_XTYPE_E::EXTERNAL_ONLY DPI DMA instruction.

                                                                 [FPORT<0>] normally determines the IOI/NCB DPI uses for
                                                                 DPI_HDR_XTYPE_E::OUTBOUND and DPI_HDR_XTYPE_E::INBOUND instructions.

                                                                 [FPORT<0>] normally determines the IOI/NCB DPI uses for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions.

                                                                 [FPORT<1>] must be zero for DPI_HDR_XTYPE_E::OUTBOUND,
                                                                 DPI_HDR_XTYPE_E::INBOUND, and DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions. */
        uint64_t reserved_114_119      : 6;
        uint64_t xtype                 : 2;  /**< [113:112] Transfer type of the instruction. Enumerated by DPI_HDR_XTYPE_E. Each DPI DMA
                                                                 instruction can be DPI_HDR_XTYPE_E::OUTBOUND (L2/DRAM->MAC),
                                                                 DPI_HDR_XTYPE_E::INBOUND (MAC->L2/DRAM), DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 (L2/DRAM->L2/DRAM), or DPI_HDR_XTYPE_E::EXTERNAL_ONLY (MAC->MAC). */
        uint64_t reserved_109_111      : 3;
        uint64_t csel                  : 1;  /**< [108:108] Counter and interrupt select. See [CA] and [FI]. [CSEL] selects which of two counters
                                                                 (SLI_DMA()_CNT[CNT]) and/or two interrupt bits (SLI_MAC()_PF()_INT_SUM[DMAFI])
                                                                 DPI can modify during DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY
                                                                 instruction execution.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CSEL] must be zero. */
        uint64_t ca                    : 1;  /**< [107:107] Add to a counter that can interrupt a remote host.

                                                                 When [CA] = 1, DPI updates a selected counter after it completes the DMA
                                                                 DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY instruction.

                                                                 _ If [CSEL] = 0, DPI updates SLI_DMA(0)_CNT[CNT].
                                                                 _ If [CSEL] = 1, DPI updates SLI_DMA(1)_CNT[CNT].

                                                                 Note that these updates may indirectly cause
                                                                 SLI_MAC()_PF()_INT_SUM[DCNT,DTIME] to become set for all MACs
                                                                 (depending on the SLI_DMA()_INT_LEVEL settings), so may cause interrupts to
                                                                 be sent to a remote MAC host.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 1, DPI updates the counter by 1.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 0, DPI updates the counter by the total bytes in
                                                                 the transfer.

                                                                 When [CA] = 0, DPI does not update any SLI_DMA()_CNT[CNT].

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CA] must never be set, and DPI never adds to any
                                                                 SLI_DMA()_CNT[CNT]. */
        uint64_t fi                    : 1;  /**< [106:106] Force interrupt to a remote host.

                                                                 When [FI] is set for a (DPI_HDR_XTYPE_E::OUTBOUND or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY) DPI DMA instruction, DPI sets an
                                                                 interrupt bit after completing instruction. If [CSEL] = 0, DPI sets
                                                                 SLI_MAC()_PF()_INT_SUM[DMAFI<0>] for all MACs, else DPI sets
                                                                 SLI_MAC()_PF()_INT_SUM[DMAFI<1>] for all MACs. This may
                                                                 cause an interrupt to be sent to a remote host.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions, [II] must be clear, and DPI never sets DMAFI interrupt bits. */
        uint64_t ii                    : 1;  /**< [105:105] Ignore I. Determines if DPI_DMA_LOCAL_PTR_S[I]'s influence whether
                                                                 DPI frees a DPI_DMA_LOCAL_PTR_S[PTR] during DPI_HDR_XTYPE_E::OUTBOUND
                                                                 instruction processing.

                                                                 If [II] is set, [FL] solely determines whether DPI frees, and
                                                                 all DPI_DMA_LOCAL_PTR_S[PTR]'s in the DPI_HDR_XTYPE_E::OUTBOUND
                                                                 instruction are either freed or not.

                                                                 If [II] is clear, ([FL] XOR DPI_DMA_LOCAL_PTR_S[I]) determines
                                                                 whether DPI frees a given DPI_DMA_LOCAL_PTR_S[PTR] in the
                                                                 DPI_HDR_XTYPE_E::OUTBOUND instruction, and each .

                                                                 For DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::INTERNAL_ONLY, or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, [II] must be clear,
                                                                 and DPI never frees local buffers. */
        uint64_t fl                    : 1;  /**< [104:104] Determines whether DPI frees a DPI_DMA_LOCAL_PTR_S[PTR] during
                                                                 DPI_HDR_XTYPE_E::OUTBOUND instruction processing
                                                                 (along with [II] and DPI_DMA_LOCAL_PTR_S[I]).

                                                                 During DPI_HDR_XTYPE_E::OUTBOUND instruction processing, DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA when:

                                                                 _ [FL] XOR (![II] AND DPI_DMA_LOCAL_PTR_S[I])

                                                                 For DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::INTERNAL_ONLY, or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, [FL] must be clear,
                                                                 and DPI never frees local buffers. */
        uint64_t reserved_102_103      : 2;
        uint64_t pt                    : 2;  /**< [101:100] Pointer type. Enumerated by DPI_HDR_PT_E. Indicates how [PTR] is used
                                                                 upon completion of the DPI DMA instruction: byte write, SSO
                                                                 work add, or counter add.

                                                                 If no completion indication is desired for the DPI DMA instruction,
                                                                 software should set [PT]=DPI_HDR_PT_E::ZBW_CA(0) and [PTR]=0. */
        uint64_t reserved_98_99        : 2;
        uint64_t pvfe                  : 1;  /**< [ 97: 97] Function enable. When [PVFE] is set, DPI directs all MAC reads/writes
                                                                 to the function (physical or virtual) that [DEALLOCV] selects within
                                                                 MAC/port [LPORT]. When [PVFE] is clear, DPI directs all MAC reads/writes
                                                                 to physical function 0 within the MACs/ports [LPORT] or [FPORT]. [PVFE]
                                                                 must not be set when [DEALLOCE] is set. [PVFE] must not be set when
                                                                 [XTYPE] is DPI_HDR_XTYPE_E::INTERNAL_ONLY or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY. [PVFE] can only be set when MAC/PORT
                                                                 [LPORT] is a PCIe MAC that either has multiple physical functions or
                                                                 has SR-IOV enabled. */
        uint64_t dealloce              : 1;  /**< [ 96: 96] Aura count subtract enable. When [DEALLOCE] is set, DPI subtracts
                                                                 [DEALLOCV] from the FPA aura count selected by [AURA]. When [DEALLOCE]
                                                                 is clear, DPI does not subtract [DEALLOCV] from any aura count.
                                                                 [DEALLOCE] can only be set when [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND.
                                                                 [DEALLOCE] must not be set when [PVFE] is set. [DEALLOCV] must not be 0
                                                                 when [DEALLOCE] is set.

                                                                 The [DEALLOCV] aura count subtract is in addition to other
                                                                 aura count activity. When FPA_AURA([AURA])_CFG[PTR_DIS]==0, FPA also
                                                                 decrements the aura count by one for each DPI_DMA_LOCAL_PTR_S local
                                                                 pointer free. */
        uint64_t deallocv              : 16; /**< [ 95: 80] The DEALLOCV/FUNC field.

                                                                 When [DEALLOCE] is set, [DEALLOCV] is the value to decrement the aura count on
                                                                 the instruction's final pointer return.

                                                                 When [PVFE] is set, DPI_DMA_FUNC_SEL_S describes the [DEALLOCV] format.
                                                                 [DEALLOCV] selects the function within the MAC selected by [LPORT]
                                                                 when [PVFE] is set. */
        uint64_t reserved_76_79        : 4;
        uint64_t aura                  : 12; /**< [ 75: 64] FPA guest-aura.  The FPA guest-aura DPI uses for all FPA transactions for the
                                                                 DPI DMA instruction. [AURA] can only be used when
                                                                 [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND, and must be zero otherwise.

                                                                 For the FPA to not discard the request, FPA_PF_MAP() must map
                                                                 [AURA] and DPI()_DMA()_IDS[GMID] as valid.

                                                                 During an DPI_HDR_XTYPE_E::OUTBOUND DPI DMA instruction, [FL], [II],
                                                                 and DPI_DMA_LOCAL_PTR_S[I] determine whether DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA, and [DEALLOCE] determines
                                                                 whether DPI subtracts [DEALLOCV] from [AURA]'s FPA aura counter. */
#else /* Word 1 - Little Endian */
        uint64_t aura                  : 12; /**< [ 75: 64] FPA guest-aura.  The FPA guest-aura DPI uses for all FPA transactions for the
                                                                 DPI DMA instruction. [AURA] can only be used when
                                                                 [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND, and must be zero otherwise.

                                                                 For the FPA to not discard the request, FPA_PF_MAP() must map
                                                                 [AURA] and DPI()_DMA()_IDS[GMID] as valid.

                                                                 During an DPI_HDR_XTYPE_E::OUTBOUND DPI DMA instruction, [FL], [II],
                                                                 and DPI_DMA_LOCAL_PTR_S[I] determine whether DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA, and [DEALLOCE] determines
                                                                 whether DPI subtracts [DEALLOCV] from [AURA]'s FPA aura counter. */
        uint64_t reserved_76_79        : 4;
        uint64_t deallocv              : 16; /**< [ 95: 80] The DEALLOCV/FUNC field.

                                                                 When [DEALLOCE] is set, [DEALLOCV] is the value to decrement the aura count on
                                                                 the instruction's final pointer return.

                                                                 When [PVFE] is set, DPI_DMA_FUNC_SEL_S describes the [DEALLOCV] format.
                                                                 [DEALLOCV] selects the function within the MAC selected by [LPORT]
                                                                 when [PVFE] is set. */
        uint64_t dealloce              : 1;  /**< [ 96: 96] Aura count subtract enable. When [DEALLOCE] is set, DPI subtracts
                                                                 [DEALLOCV] from the FPA aura count selected by [AURA]. When [DEALLOCE]
                                                                 is clear, DPI does not subtract [DEALLOCV] from any aura count.
                                                                 [DEALLOCE] can only be set when [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND.
                                                                 [DEALLOCE] must not be set when [PVFE] is set. [DEALLOCV] must not be 0
                                                                 when [DEALLOCE] is set.

                                                                 The [DEALLOCV] aura count subtract is in addition to other
                                                                 aura count activity. When FPA_AURA([AURA])_CFG[PTR_DIS]==0, FPA also
                                                                 decrements the aura count by one for each DPI_DMA_LOCAL_PTR_S local
                                                                 pointer free. */
        uint64_t pvfe                  : 1;  /**< [ 97: 97] Function enable. When [PVFE] is set, DPI directs all MAC reads/writes
                                                                 to the function (physical or virtual) that [DEALLOCV] selects within
                                                                 MAC/port [LPORT]. When [PVFE] is clear, DPI directs all MAC reads/writes
                                                                 to physical function 0 within the MACs/ports [LPORT] or [FPORT]. [PVFE]
                                                                 must not be set when [DEALLOCE] is set. [PVFE] must not be set when
                                                                 [XTYPE] is DPI_HDR_XTYPE_E::INTERNAL_ONLY or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY. [PVFE] can only be set when MAC/PORT
                                                                 [LPORT] is a PCIe MAC that either has multiple physical functions or
                                                                 has SR-IOV enabled. */
        uint64_t reserved_98_99        : 2;
        uint64_t pt                    : 2;  /**< [101:100] Pointer type. Enumerated by DPI_HDR_PT_E. Indicates how [PTR] is used
                                                                 upon completion of the DPI DMA instruction: byte write, SSO
                                                                 work add, or counter add.

                                                                 If no completion indication is desired for the DPI DMA instruction,
                                                                 software should set [PT]=DPI_HDR_PT_E::ZBW_CA(0) and [PTR]=0. */
        uint64_t reserved_102_103      : 2;
        uint64_t fl                    : 1;  /**< [104:104] Determines whether DPI frees a DPI_DMA_LOCAL_PTR_S[PTR] during
                                                                 DPI_HDR_XTYPE_E::OUTBOUND instruction processing
                                                                 (along with [II] and DPI_DMA_LOCAL_PTR_S[I]).

                                                                 During DPI_HDR_XTYPE_E::OUTBOUND instruction processing, DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA when:

                                                                 _ [FL] XOR (![II] AND DPI_DMA_LOCAL_PTR_S[I])

                                                                 For DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::INTERNAL_ONLY, or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, [FL] must be clear,
                                                                 and DPI never frees local buffers. */
        uint64_t ii                    : 1;  /**< [105:105] Ignore I. Determines if DPI_DMA_LOCAL_PTR_S[I]'s influence whether
                                                                 DPI frees a DPI_DMA_LOCAL_PTR_S[PTR] during DPI_HDR_XTYPE_E::OUTBOUND
                                                                 instruction processing.

                                                                 If [II] is set, [FL] solely determines whether DPI frees, and
                                                                 all DPI_DMA_LOCAL_PTR_S[PTR]'s in the DPI_HDR_XTYPE_E::OUTBOUND
                                                                 instruction are either freed or not.

                                                                 If [II] is clear, ([FL] XOR DPI_DMA_LOCAL_PTR_S[I]) determines
                                                                 whether DPI frees a given DPI_DMA_LOCAL_PTR_S[PTR] in the
                                                                 DPI_HDR_XTYPE_E::OUTBOUND instruction, and each .

                                                                 For DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::INTERNAL_ONLY, or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, [II] must be clear,
                                                                 and DPI never frees local buffers. */
        uint64_t fi                    : 1;  /**< [106:106] Force interrupt to a remote host.

                                                                 When [FI] is set for a (DPI_HDR_XTYPE_E::OUTBOUND or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY) DPI DMA instruction, DPI sets an
                                                                 interrupt bit after completing instruction. If [CSEL] = 0, DPI sets
                                                                 SLI_MAC()_PF()_INT_SUM[DMAFI<0>] for all MACs, else DPI sets
                                                                 SLI_MAC()_PF()_INT_SUM[DMAFI<1>] for all MACs. This may
                                                                 cause an interrupt to be sent to a remote host.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions, [II] must be clear, and DPI never sets DMAFI interrupt bits. */
        uint64_t ca                    : 1;  /**< [107:107] Add to a counter that can interrupt a remote host.

                                                                 When [CA] = 1, DPI updates a selected counter after it completes the DMA
                                                                 DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY instruction.

                                                                 _ If [CSEL] = 0, DPI updates SLI_DMA(0)_CNT[CNT].
                                                                 _ If [CSEL] = 1, DPI updates SLI_DMA(1)_CNT[CNT].

                                                                 Note that these updates may indirectly cause
                                                                 SLI_MAC()_PF()_INT_SUM[DCNT,DTIME] to become set for all MACs
                                                                 (depending on the SLI_DMA()_INT_LEVEL settings), so may cause interrupts to
                                                                 be sent to a remote MAC host.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 1, DPI updates the counter by 1.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 0, DPI updates the counter by the total bytes in
                                                                 the transfer.

                                                                 When [CA] = 0, DPI does not update any SLI_DMA()_CNT[CNT].

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CA] must never be set, and DPI never adds to any
                                                                 SLI_DMA()_CNT[CNT]. */
        uint64_t csel                  : 1;  /**< [108:108] Counter and interrupt select. See [CA] and [FI]. [CSEL] selects which of two counters
                                                                 (SLI_DMA()_CNT[CNT]) and/or two interrupt bits (SLI_MAC()_PF()_INT_SUM[DMAFI])
                                                                 DPI can modify during DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY
                                                                 instruction execution.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CSEL] must be zero. */
        uint64_t reserved_109_111      : 3;
        uint64_t xtype                 : 2;  /**< [113:112] Transfer type of the instruction. Enumerated by DPI_HDR_XTYPE_E. Each DPI DMA
                                                                 instruction can be DPI_HDR_XTYPE_E::OUTBOUND (L2/DRAM->MAC),
                                                                 DPI_HDR_XTYPE_E::INBOUND (MAC->L2/DRAM), DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 (L2/DRAM->L2/DRAM), or DPI_HDR_XTYPE_E::EXTERNAL_ONLY (MAC->MAC). */
        uint64_t reserved_114_119      : 6;
        uint64_t fport                 : 2;  /**< [121:120] Port for the first pointers block.

                                                                 DPI sends MAC memory space reads for the MAC addresses in the first
                                                                 pointers block to the MAC selected by [FPORT] while processing
                                                                 a DPI_HDR_XTYPE_E::EXTERNAL_ONLY DPI DMA instruction.

                                                                 [FPORT<0>] normally determines the IOI/NCB DPI uses for
                                                                 DPI_HDR_XTYPE_E::OUTBOUND and DPI_HDR_XTYPE_E::INBOUND instructions.

                                                                 [FPORT<0>] normally determines the IOI/NCB DPI uses for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions.

                                                                 [FPORT<1>] must be zero for DPI_HDR_XTYPE_E::OUTBOUND,
                                                                 DPI_HDR_XTYPE_E::INBOUND, and DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions. */
        uint64_t reserved_122_123      : 2;
        uint64_t lport                 : 2;  /**< [125:124] Port for the last pointers block.

                                                                 DPI sends MAC memory space reads and writes for the MAC addresses
                                                                 in the last pointers block to the MAC selected by [LPORT]
                                                                 while processing DPI_HDR_XTYPE_E::OUTBOUND, DPI_HDR_XTYPE_E::INBOUND,
                                                                 and DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions.

                                                                 [LPORT<0>] normally determines the IOI/NCB DPI uses for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions.

                                                                 [LPORT<1>] must be zero for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions. */
        uint64_t reserved_126_127      : 2;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t ptr                   : 64; /**< [191:128] Completion pointer. Usage determined by [PT] value. The DPI_HDR_PT_E
                                                                 enumeration describes the supported [PT] values and the [PTR] usage
                                                                 and requirements in each case.
                                                                 Bits <63:49> are ignored by hardware; software should use a sign-extended bit
                                                                 <48> for forward compatibility. */
#else /* Word 2 - Little Endian */
        uint64_t ptr                   : 64; /**< [191:128] Completion pointer. Usage determined by [PT] value. The DPI_HDR_PT_E
                                                                 enumeration describes the supported [PT] values and the [PTR] usage
                                                                 and requirements in each case.
                                                                 Bits <63:49> are ignored by hardware; software should use a sign-extended bit
                                                                 <48> for forward compatibility. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_192_255      : 64;
#else /* Word 3 - Little Endian */
        uint64_t reserved_192_255      : 64;
#endif /* Word 3 - End */
    } s;
    struct bdk_dpi_dma_instr_hdr_s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t reserved_58_59        : 2;
        uint64_t nlst                  : 4;  /**< [ 57: 54] The number of pointers in the last-pointers block.

                                                                 With DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::OUTBOUND, and
                                                                 DPI_HDR_XTYPE_E:EXTERNAL_ONLY instructions, the last pointers block
                                                                 contains [NLST] MAC pointers via DPI components, and is

                                                                 _  [NLST] + (([NLST] + 3)/4)

                                                                 64-bit words, where the division removes the fraction.

                                                                 With DPI_HDR_XTYPE_E:INTERNAL_ONLY instructions, the last pointers block
                                                                 includes [NLST] DPI_DMA_LOCAL_PTR_S local pointers, and is
                                                                 [NLST] 64-bit words.

                                                                 Note that the sum of the number of 64-bit words in the last pointers block
                                                                 and first pointers block must never exceed 30. */
        uint64_t reserved_52_53        : 2;
        uint64_t nfst                  : 4;  /**< [ 51: 48] The number of pointers in the first pointers block.

                                                                 With DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::OUTBOUND, and
                                                                 DPI_HDR_XTYPE_E:INTERNAL_ONLY instructions, the first pointers block
                                                                 includes [NFST] DPI_DMA_LOCAL_PTR_S local pointers, and is
                                                                 [NFST] 64-bit words.

                                                                 With DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, the first pointers
                                                                 block includes [NFST] MAC pointers via DPI components, and is

                                                                   _ [NFST] + (([NFST] + 3)/4)

                                                                 64-bit words, where the division removes the fraction.

                                                                 Note that the sum of the number of 64-bit words in the last pointers block
                                                                 and first pointers block must never exceed 30. */
        uint64_t reserved_46_47        : 2;
        uint64_t reserved_44_45        : 2;
        uint64_t grp                   : 10; /**< [ 43: 34] SSO guest-group. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.
                                                                 For the SSO to not discard the add-work request, SSO_PF_MAP() must map
                                                                 [GRP] and DPI()_DMA()_IDS[GMID] as valid.

                                                                 [GRP] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t tt                    : 2;  /**< [ 33: 32] SSO tag type. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.

                                                                 [TT] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t tag                   : 32; /**< [ 31:  0] SSO Tag */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0] SSO Tag */
        uint64_t tt                    : 2;  /**< [ 33: 32] SSO tag type. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.

                                                                 [TT] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t grp                   : 10; /**< [ 43: 34] SSO guest-group. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.
                                                                 For the SSO to not discard the add-work request, SSO_PF_MAP() must map
                                                                 [GRP] and DPI()_DMA()_IDS[GMID] as valid.

                                                                 [GRP] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t reserved_44_45        : 2;
        uint64_t reserved_46_47        : 2;
        uint64_t nfst                  : 4;  /**< [ 51: 48] The number of pointers in the first pointers block.

                                                                 With DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::OUTBOUND, and
                                                                 DPI_HDR_XTYPE_E:INTERNAL_ONLY instructions, the first pointers block
                                                                 includes [NFST] DPI_DMA_LOCAL_PTR_S local pointers, and is
                                                                 [NFST] 64-bit words.

                                                                 With DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, the first pointers
                                                                 block includes [NFST] MAC pointers via DPI components, and is

                                                                   _ [NFST] + (([NFST] + 3)/4)

                                                                 64-bit words, where the division removes the fraction.

                                                                 Note that the sum of the number of 64-bit words in the last pointers block
                                                                 and first pointers block must never exceed 30. */
        uint64_t reserved_52_53        : 2;
        uint64_t nlst                  : 4;  /**< [ 57: 54] The number of pointers in the last-pointers block.

                                                                 With DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::OUTBOUND, and
                                                                 DPI_HDR_XTYPE_E:EXTERNAL_ONLY instructions, the last pointers block
                                                                 contains [NLST] MAC pointers via DPI components, and is

                                                                 _  [NLST] + (([NLST] + 3)/4)

                                                                 64-bit words, where the division removes the fraction.

                                                                 With DPI_HDR_XTYPE_E:INTERNAL_ONLY instructions, the last pointers block
                                                                 includes [NLST] DPI_DMA_LOCAL_PTR_S local pointers, and is
                                                                 [NLST] 64-bit words.

                                                                 Note that the sum of the number of 64-bit words in the last pointers block
                                                                 and first pointers block must never exceed 30. */
        uint64_t reserved_58_59        : 2;
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_126_127      : 2;
        uint64_t lport                 : 2;  /**< [125:124] Port for the last pointers block.

                                                                 DPI sends MAC memory space reads and writes for the MAC addresses
                                                                 in the last pointers block to the MAC selected by [LPORT]
                                                                 while processing DPI_HDR_XTYPE_E::OUTBOUND, DPI_HDR_XTYPE_E::INBOUND,
                                                                 and DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions.

                                                                 [LPORT<0>] normally determines the IOI/NCB DPI uses for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions.

                                                                 [LPORT<1>] must be zero for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions. */
        uint64_t reserved_122_123      : 2;
        uint64_t fport                 : 2;  /**< [121:120] Port for the first pointers block.

                                                                 DPI sends MAC memory space reads for the MAC addresses in the first
                                                                 pointers block to the MAC selected by [FPORT] while processing
                                                                 a DPI_HDR_XTYPE_E::EXTERNAL_ONLY DPI DMA instruction.

                                                                 [FPORT<0>] normally determines the IOI/NCB DPI uses for
                                                                 DPI_HDR_XTYPE_E::OUTBOUND and DPI_HDR_XTYPE_E::INBOUND instructions.

                                                                 [FPORT<0>] normally determines the IOI/NCB DPI uses for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions.

                                                                 [FPORT<1>] must be zero for DPI_HDR_XTYPE_E::OUTBOUND,
                                                                 DPI_HDR_XTYPE_E::INBOUND, and DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions. */
        uint64_t reserved_116_119      : 4;
        uint64_t reserved_114_115      : 2;
        uint64_t xtype                 : 2;  /**< [113:112] Transfer type of the instruction. Enumerated by DPI_HDR_XTYPE_E. Each DPI DMA
                                                                 instruction can be DPI_HDR_XTYPE_E::OUTBOUND (L2/DRAM->MAC),
                                                                 DPI_HDR_XTYPE_E::INBOUND (MAC->L2/DRAM), DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 (L2/DRAM->L2/DRAM), or DPI_HDR_XTYPE_E::EXTERNAL_ONLY (MAC->MAC). */
        uint64_t reserved_109_111      : 3;
        uint64_t csel                  : 1;  /**< [108:108] Counter and interrupt select. See [CA] and [FI]. [CSEL] selects which of two counters
                                                                 (SLI_DMA()_CNT[CNT]) and/or two interrupt bits (SLI_MAC()_PF()_INT_SUM[DMAFI])
                                                                 DPI can modify during DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY
                                                                 instruction execution.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CSEL] must be zero. */
        uint64_t ca                    : 1;  /**< [107:107] Add to a counter that can interrupt a remote host.

                                                                 When [CA] = 1, DPI updates a selected counter after it completes the DMA
                                                                 DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY instruction.

                                                                 _ If [CSEL] = 0, DPI updates SLI_DMA(0)_CNT[CNT].
                                                                 _ If [CSEL] = 1, DPI updates SLI_DMA(1)_CNT[CNT].

                                                                 Note that these updates may indirectly cause
                                                                 SLI_MAC()_PF()_INT_SUM[DCNT,DTIME] to become set for all MACs
                                                                 (depending on the SLI_DMA()_INT_LEVEL settings), so may cause interrupts to
                                                                 be sent to a remote MAC host.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 1, DPI updates the counter by 1.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 0, DPI updates the counter by the total bytes in
                                                                 the transfer.

                                                                 When [CA] = 0, DPI does not update any SLI_DMA()_CNT[CNT].

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CA] must never be set, and DPI never adds to any
                                                                 SLI_DMA()_CNT[CNT]. */
        uint64_t fi                    : 1;  /**< [106:106] Force interrupt to a remote host.

                                                                 When [FI] is set for a (DPI_HDR_XTYPE_E::OUTBOUND or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY) DPI DMA instruction, DPI sets an
                                                                 interrupt bit after completing instruction. If [CSEL] = 0, DPI sets
                                                                 SLI_MAC()_PF()_INT_SUM[DMAFI<0>] for all MACs, else DPI sets
                                                                 SLI_MAC()_PF()_INT_SUM[DMAFI<1>] for all MACs. This may
                                                                 cause an interrupt to be sent to a remote host.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions, [II] must be clear, and DPI never sets DMAFI interrupt bits. */
        uint64_t ii                    : 1;  /**< [105:105] Ignore I. Determines if DPI_DMA_LOCAL_PTR_S[I]'s influence whether
                                                                 DPI frees a DPI_DMA_LOCAL_PTR_S[PTR] during DPI_HDR_XTYPE_E::OUTBOUND
                                                                 instruction processing.

                                                                 If [II] is set, [FL] solely determines whether DPI frees, and
                                                                 all DPI_DMA_LOCAL_PTR_S[PTR]'s in the DPI_HDR_XTYPE_E::OUTBOUND
                                                                 instruction are either freed or not.

                                                                 If [II] is clear, ([FL] XOR DPI_DMA_LOCAL_PTR_S[I]) determines
                                                                 whether DPI frees a given DPI_DMA_LOCAL_PTR_S[PTR] in the
                                                                 DPI_HDR_XTYPE_E::OUTBOUND instruction, and each .

                                                                 For DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::INTERNAL_ONLY, or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, [II] must be clear,
                                                                 and DPI never frees local buffers. */
        uint64_t fl                    : 1;  /**< [104:104] Determines whether DPI frees a DPI_DMA_LOCAL_PTR_S[PTR] during
                                                                 DPI_HDR_XTYPE_E::OUTBOUND instruction processing
                                                                 (along with [II] and DPI_DMA_LOCAL_PTR_S[I]).

                                                                 During DPI_HDR_XTYPE_E::OUTBOUND instruction processing, DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA when:

                                                                 _ [FL] XOR (![II] AND DPI_DMA_LOCAL_PTR_S[I])

                                                                 For DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::INTERNAL_ONLY, or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, [FL] must be clear,
                                                                 and DPI never frees local buffers. */
        uint64_t reserved_102_103      : 2;
        uint64_t pt                    : 2;  /**< [101:100] Pointer type. Enumerated by DPI_HDR_PT_E. Indicates how [PTR] is used
                                                                 upon completion of the DPI DMA instruction: byte write, SSO
                                                                 work add, or counter add.

                                                                 If no completion indication is desired for the DPI DMA instruction,
                                                                 software should set [PT]=DPI_HDR_PT_E::ZBW_CA(0) and [PTR]=0. */
        uint64_t reserved_98_99        : 2;
        uint64_t pvfe                  : 1;  /**< [ 97: 97] Function enable. When [PVFE] is set, DPI directs all MAC reads/writes
                                                                 to the function (physical or virtual) that [DEALLOCV] selects within
                                                                 MAC/port [LPORT]. When [PVFE] is clear, DPI directs all MAC reads/writes
                                                                 to physical function 0 within the MACs/ports [LPORT] or [FPORT]. [PVFE]
                                                                 must not be set when [DEALLOCE] is set. [PVFE] must not be set when
                                                                 [XTYPE] is DPI_HDR_XTYPE_E::INTERNAL_ONLY or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY. [PVFE] can only be set when MAC/PORT
                                                                 [LPORT] is a PCIe MAC that either has multiple physical functions or
                                                                 has SR-IOV enabled. */
        uint64_t dealloce              : 1;  /**< [ 96: 96] Aura count subtract enable. When [DEALLOCE] is set, DPI subtracts
                                                                 [DEALLOCV] from the FPA aura count selected by [AURA]. When [DEALLOCE]
                                                                 is clear, DPI does not subtract [DEALLOCV] from any aura count.
                                                                 [DEALLOCE] can only be set when [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND.
                                                                 [DEALLOCE] must not be set when [PVFE] is set. [DEALLOCV] must not be 0
                                                                 when [DEALLOCE] is set.

                                                                 The [DEALLOCV] aura count subtract is in addition to other
                                                                 aura count activity. When FPA_AURA([AURA])_CFG[PTR_DIS]==0, FPA also
                                                                 decrements the aura count by one for each DPI_DMA_LOCAL_PTR_S local
                                                                 pointer free. */
        uint64_t deallocv              : 16; /**< [ 95: 80] The DEALLOCV/FUNC field.

                                                                 When [DEALLOCE] is set, [DEALLOCV] is the value to decrement the aura count on
                                                                 the instruction's final pointer return.

                                                                 When [PVFE] is set, DPI_DMA_FUNC_SEL_S describes the [DEALLOCV] format.
                                                                 [DEALLOCV] selects the function within the MAC selected by [LPORT]
                                                                 when [PVFE] is set. */
        uint64_t reserved_76_79        : 4;
        uint64_t aura                  : 12; /**< [ 75: 64] FPA guest-aura.  The FPA guest-aura DPI uses for all FPA transactions for the
                                                                 DPI DMA instruction. [AURA] can only be used when
                                                                 [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND, and must be zero otherwise.

                                                                 For the FPA to not discard the request, FPA_PF_MAP() must map
                                                                 [AURA] and DPI()_DMA()_IDS[GMID] as valid.

                                                                 During an DPI_HDR_XTYPE_E::OUTBOUND DPI DMA instruction, [FL], [II],
                                                                 and DPI_DMA_LOCAL_PTR_S[I] determine whether DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA, and [DEALLOCE] determines
                                                                 whether DPI subtracts [DEALLOCV] from [AURA]'s FPA aura counter. */
#else /* Word 1 - Little Endian */
        uint64_t aura                  : 12; /**< [ 75: 64] FPA guest-aura.  The FPA guest-aura DPI uses for all FPA transactions for the
                                                                 DPI DMA instruction. [AURA] can only be used when
                                                                 [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND, and must be zero otherwise.

                                                                 For the FPA to not discard the request, FPA_PF_MAP() must map
                                                                 [AURA] and DPI()_DMA()_IDS[GMID] as valid.

                                                                 During an DPI_HDR_XTYPE_E::OUTBOUND DPI DMA instruction, [FL], [II],
                                                                 and DPI_DMA_LOCAL_PTR_S[I] determine whether DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA, and [DEALLOCE] determines
                                                                 whether DPI subtracts [DEALLOCV] from [AURA]'s FPA aura counter. */
        uint64_t reserved_76_79        : 4;
        uint64_t deallocv              : 16; /**< [ 95: 80] The DEALLOCV/FUNC field.

                                                                 When [DEALLOCE] is set, [DEALLOCV] is the value to decrement the aura count on
                                                                 the instruction's final pointer return.

                                                                 When [PVFE] is set, DPI_DMA_FUNC_SEL_S describes the [DEALLOCV] format.
                                                                 [DEALLOCV] selects the function within the MAC selected by [LPORT]
                                                                 when [PVFE] is set. */
        uint64_t dealloce              : 1;  /**< [ 96: 96] Aura count subtract enable. When [DEALLOCE] is set, DPI subtracts
                                                                 [DEALLOCV] from the FPA aura count selected by [AURA]. When [DEALLOCE]
                                                                 is clear, DPI does not subtract [DEALLOCV] from any aura count.
                                                                 [DEALLOCE] can only be set when [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND.
                                                                 [DEALLOCE] must not be set when [PVFE] is set. [DEALLOCV] must not be 0
                                                                 when [DEALLOCE] is set.

                                                                 The [DEALLOCV] aura count subtract is in addition to other
                                                                 aura count activity. When FPA_AURA([AURA])_CFG[PTR_DIS]==0, FPA also
                                                                 decrements the aura count by one for each DPI_DMA_LOCAL_PTR_S local
                                                                 pointer free. */
        uint64_t pvfe                  : 1;  /**< [ 97: 97] Function enable. When [PVFE] is set, DPI directs all MAC reads/writes
                                                                 to the function (physical or virtual) that [DEALLOCV] selects within
                                                                 MAC/port [LPORT]. When [PVFE] is clear, DPI directs all MAC reads/writes
                                                                 to physical function 0 within the MACs/ports [LPORT] or [FPORT]. [PVFE]
                                                                 must not be set when [DEALLOCE] is set. [PVFE] must not be set when
                                                                 [XTYPE] is DPI_HDR_XTYPE_E::INTERNAL_ONLY or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY. [PVFE] can only be set when MAC/PORT
                                                                 [LPORT] is a PCIe MAC that either has multiple physical functions or
                                                                 has SR-IOV enabled. */
        uint64_t reserved_98_99        : 2;
        uint64_t pt                    : 2;  /**< [101:100] Pointer type. Enumerated by DPI_HDR_PT_E. Indicates how [PTR] is used
                                                                 upon completion of the DPI DMA instruction: byte write, SSO
                                                                 work add, or counter add.

                                                                 If no completion indication is desired for the DPI DMA instruction,
                                                                 software should set [PT]=DPI_HDR_PT_E::ZBW_CA(0) and [PTR]=0. */
        uint64_t reserved_102_103      : 2;
        uint64_t fl                    : 1;  /**< [104:104] Determines whether DPI frees a DPI_DMA_LOCAL_PTR_S[PTR] during
                                                                 DPI_HDR_XTYPE_E::OUTBOUND instruction processing
                                                                 (along with [II] and DPI_DMA_LOCAL_PTR_S[I]).

                                                                 During DPI_HDR_XTYPE_E::OUTBOUND instruction processing, DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA when:

                                                                 _ [FL] XOR (![II] AND DPI_DMA_LOCAL_PTR_S[I])

                                                                 For DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::INTERNAL_ONLY, or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, [FL] must be clear,
                                                                 and DPI never frees local buffers. */
        uint64_t ii                    : 1;  /**< [105:105] Ignore I. Determines if DPI_DMA_LOCAL_PTR_S[I]'s influence whether
                                                                 DPI frees a DPI_DMA_LOCAL_PTR_S[PTR] during DPI_HDR_XTYPE_E::OUTBOUND
                                                                 instruction processing.

                                                                 If [II] is set, [FL] solely determines whether DPI frees, and
                                                                 all DPI_DMA_LOCAL_PTR_S[PTR]'s in the DPI_HDR_XTYPE_E::OUTBOUND
                                                                 instruction are either freed or not.

                                                                 If [II] is clear, ([FL] XOR DPI_DMA_LOCAL_PTR_S[I]) determines
                                                                 whether DPI frees a given DPI_DMA_LOCAL_PTR_S[PTR] in the
                                                                 DPI_HDR_XTYPE_E::OUTBOUND instruction, and each .

                                                                 For DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::INTERNAL_ONLY, or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, [II] must be clear,
                                                                 and DPI never frees local buffers. */
        uint64_t fi                    : 1;  /**< [106:106] Force interrupt to a remote host.

                                                                 When [FI] is set for a (DPI_HDR_XTYPE_E::OUTBOUND or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY) DPI DMA instruction, DPI sets an
                                                                 interrupt bit after completing instruction. If [CSEL] = 0, DPI sets
                                                                 SLI_MAC()_PF()_INT_SUM[DMAFI<0>] for all MACs, else DPI sets
                                                                 SLI_MAC()_PF()_INT_SUM[DMAFI<1>] for all MACs. This may
                                                                 cause an interrupt to be sent to a remote host.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions, [II] must be clear, and DPI never sets DMAFI interrupt bits. */
        uint64_t ca                    : 1;  /**< [107:107] Add to a counter that can interrupt a remote host.

                                                                 When [CA] = 1, DPI updates a selected counter after it completes the DMA
                                                                 DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY instruction.

                                                                 _ If [CSEL] = 0, DPI updates SLI_DMA(0)_CNT[CNT].
                                                                 _ If [CSEL] = 1, DPI updates SLI_DMA(1)_CNT[CNT].

                                                                 Note that these updates may indirectly cause
                                                                 SLI_MAC()_PF()_INT_SUM[DCNT,DTIME] to become set for all MACs
                                                                 (depending on the SLI_DMA()_INT_LEVEL settings), so may cause interrupts to
                                                                 be sent to a remote MAC host.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 1, DPI updates the counter by 1.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 0, DPI updates the counter by the total bytes in
                                                                 the transfer.

                                                                 When [CA] = 0, DPI does not update any SLI_DMA()_CNT[CNT].

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CA] must never be set, and DPI never adds to any
                                                                 SLI_DMA()_CNT[CNT]. */
        uint64_t csel                  : 1;  /**< [108:108] Counter and interrupt select. See [CA] and [FI]. [CSEL] selects which of two counters
                                                                 (SLI_DMA()_CNT[CNT]) and/or two interrupt bits (SLI_MAC()_PF()_INT_SUM[DMAFI])
                                                                 DPI can modify during DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY
                                                                 instruction execution.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CSEL] must be zero. */
        uint64_t reserved_109_111      : 3;
        uint64_t xtype                 : 2;  /**< [113:112] Transfer type of the instruction. Enumerated by DPI_HDR_XTYPE_E. Each DPI DMA
                                                                 instruction can be DPI_HDR_XTYPE_E::OUTBOUND (L2/DRAM->MAC),
                                                                 DPI_HDR_XTYPE_E::INBOUND (MAC->L2/DRAM), DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 (L2/DRAM->L2/DRAM), or DPI_HDR_XTYPE_E::EXTERNAL_ONLY (MAC->MAC). */
        uint64_t reserved_114_115      : 2;
        uint64_t reserved_116_119      : 4;
        uint64_t fport                 : 2;  /**< [121:120] Port for the first pointers block.

                                                                 DPI sends MAC memory space reads for the MAC addresses in the first
                                                                 pointers block to the MAC selected by [FPORT] while processing
                                                                 a DPI_HDR_XTYPE_E::EXTERNAL_ONLY DPI DMA instruction.

                                                                 [FPORT<0>] normally determines the IOI/NCB DPI uses for
                                                                 DPI_HDR_XTYPE_E::OUTBOUND and DPI_HDR_XTYPE_E::INBOUND instructions.

                                                                 [FPORT<0>] normally determines the IOI/NCB DPI uses for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions.

                                                                 [FPORT<1>] must be zero for DPI_HDR_XTYPE_E::OUTBOUND,
                                                                 DPI_HDR_XTYPE_E::INBOUND, and DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions. */
        uint64_t reserved_122_123      : 2;
        uint64_t lport                 : 2;  /**< [125:124] Port for the last pointers block.

                                                                 DPI sends MAC memory space reads and writes for the MAC addresses
                                                                 in the last pointers block to the MAC selected by [LPORT]
                                                                 while processing DPI_HDR_XTYPE_E::OUTBOUND, DPI_HDR_XTYPE_E::INBOUND,
                                                                 and DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions.

                                                                 [LPORT<0>] normally determines the IOI/NCB DPI uses for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions.

                                                                 [LPORT<1>] must be zero for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions. */
        uint64_t reserved_126_127      : 2;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t ptr                   : 64; /**< [191:128] Completion pointer. Usage determined by [PT] value. The DPI_HDR_PT_E
                                                                 enumeration describes the supported [PT] values and the [PTR] usage
                                                                 and requirements in each case.
                                                                 Bits <63:49> are ignored by hardware; software should use a sign-extended bit
                                                                 <48> for forward compatibility. */
#else /* Word 2 - Little Endian */
        uint64_t ptr                   : 64; /**< [191:128] Completion pointer. Usage determined by [PT] value. The DPI_HDR_PT_E
                                                                 enumeration describes the supported [PT] values and the [PTR] usage
                                                                 and requirements in each case.
                                                                 Bits <63:49> are ignored by hardware; software should use a sign-extended bit
                                                                 <48> for forward compatibility. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_192_255      : 64;
#else /* Word 3 - Little Endian */
        uint64_t reserved_192_255      : 64;
#endif /* Word 3 - End */
    } cn;
};

/**
 * Structure dpi_dma_local_ptr_s
 *
 * DPI DMA Local Pointer Structure
 * DPI DMA Local Pointer Format
 */
union bdk_dpi_dma_local_ptr_s
{
    uint64_t u[2];
    struct bdk_dpi_dma_local_ptr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t i                     : 1;  /**< [ 63: 63] Invert free. Only used with L2/DRAM Pointers.

                                                                 This bit gives the software the ability to free buffers
                                                                 independently for a DPI_HDR_XTYPE_E::OUTBOUND DMA transfer when
                                                                 DPI_DMA_INSTR_HDR_S[II] is clear. See DPI_DMA_INSTR_HDR_S[II] and
                                                                 DPI_DMA_INSTR_HDR_S[FL].

                                                                 [I] is not used by DPI when DPI_DMA_INSTR_HDR_S[II] is set. [I] must not be set,
                                                                 and DPI never frees buffers for DPI_HDR_XTYPE_E::INBOUND and
                                                                 DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA instructions. */
        uint64_t f                     : 1;  /**< [ 62: 62] Full-block write operations are allowed.
                                                                 Only used with L2/DRAM Pointers.

                                                                 When set, the hardware is permitted to write all the bytes in the cache blocks
                                                                 covered by [PTR] .. [PTR] + [SIZE] - 1. This can improve memory system performance
                                                                 when the write misses in the L2 cache.

                                                                 [F] can only be set for DPI_DMA_LOCAL_PTR_S's that can be written to:

                                                                 * The DPI_DMA_LOCAL_PTR_S's in the first-pointers area that are write pointers
                                                                   for DPI_HDR_XTYPE_E::INBOUND DPI DMA instructions.

                                                                 * The DPI_DMA_LOCAL_PTR_S's in the last-pointers area that are always write
                                                                   pointers (when present for DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA instructions).

                                                                 [F] must not be set for DPI_DMA_LOCAL_PTR_S's that are not written to:

                                                                 * The DPI_DMA_LOCAL_PTR_S's in the first-pointers area for DPI_HDR_XTYPE_E::OUTBOUND
                                                                   and DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA instructions */
        uint64_t ac                    : 1;  /**< [ 61: 61] Allocate L2.  Only used with L2/DRAM Pointers.
                                                                 This is a hint to DPI that the cache blocks should be allocated in
                                                                 the L2 cache (if they were not already). Should typically be set to allocate the
                                                                 referenced cache blocks into the L2 cache.

                                                                 When the DPI_DMA_LOCAL_PTR_S is a source of data (e.g. a DPI_HDR_XTYPE_E::OUTBOUND
                                                                 DPI DMA instruction), the referenced cache blocks are not allocated into the L2
                                                                 cache as part of completing the DMA (when not already present in the L2) if [AC]
                                                                 is clear.

                                                                 When the DPI_DMA_LOCAL_PTR_S is a destination for data (e.g. a
                                                                 DPI_HDR_XTYPE_E::INBOUND DPI DMA instruction), the referenced cache blocks are
                                                                 not allocated into the cache as part of completing the DMA (when not already
                                                                 present in the L2) if [AC] is clear, and either:

                                                                 * the entire cache block is written by this DPI_DMA_LOCAL_PTR_S, or

                                                                 * [F] is set so that the entire cache block can be written. */
        uint64_t bed                   : 1;  /**< [ 60: 60] Big-endian data.
                                                                 Only used with L2/DRAM Pointers */
        uint64_t reserved_16_59        : 44;
        uint64_t length                : 16; /**< [ 15:  0] For L2/DRAM - only bits 75:64 used. bits 79:76 should be zero.

                                                                 Size in bytes of the contiguous space specified by PTR. A SIZE value of 0x0 is
                                                                 illegal.

                                                                 Note that the sum of the sizes in the first-pointers area must always exactly
                                                                 equal the sum of the sizes/lengths in the last-pointers area:

                                                                 * With DPI_HDR_XTYPE_E::OUTBOUND and DPI_HDR_XTYPE_E::INBOUND DPI DMA
                                                                   instructions, the sum of the [NFST] DPI_DMA_LOCAL_PTR_S[SIZE]'s in the
                                                                   first pointers block must exactly equal the sum of the [NLST] lengths
                                                                   DPI components in the last pointers block.

                                                                 * With DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA instructions, the sum of the
                                                                   [NFST] DPI_DMA_LOCAL_PTR_S[SIZE]'s in the first pointers block must exactly
                                                                   equal the sum of the [NLST] DPI_DMA_LOCAL_PTR_S[SIZE]'s in the last pointers
                                                                   block. */
#else /* Word 0 - Little Endian */
        uint64_t length                : 16; /**< [ 15:  0] For L2/DRAM - only bits 75:64 used. bits 79:76 should be zero.

                                                                 Size in bytes of the contiguous space specified by PTR. A SIZE value of 0x0 is
                                                                 illegal.

                                                                 Note that the sum of the sizes in the first-pointers area must always exactly
                                                                 equal the sum of the sizes/lengths in the last-pointers area:

                                                                 * With DPI_HDR_XTYPE_E::OUTBOUND and DPI_HDR_XTYPE_E::INBOUND DPI DMA
                                                                   instructions, the sum of the [NFST] DPI_DMA_LOCAL_PTR_S[SIZE]'s in the
                                                                   first pointers block must exactly equal the sum of the [NLST] lengths
                                                                   DPI components in the last pointers block.

                                                                 * With DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA instructions, the sum of the
                                                                   [NFST] DPI_DMA_LOCAL_PTR_S[SIZE]'s in the first pointers block must exactly
                                                                   equal the sum of the [NLST] DPI_DMA_LOCAL_PTR_S[SIZE]'s in the last pointers
                                                                   block. */
        uint64_t reserved_16_59        : 44;
        uint64_t bed                   : 1;  /**< [ 60: 60] Big-endian data.
                                                                 Only used with L2/DRAM Pointers */
        uint64_t ac                    : 1;  /**< [ 61: 61] Allocate L2.  Only used with L2/DRAM Pointers.
                                                                 This is a hint to DPI that the cache blocks should be allocated in
                                                                 the L2 cache (if they were not already). Should typically be set to allocate the
                                                                 referenced cache blocks into the L2 cache.

                                                                 When the DPI_DMA_LOCAL_PTR_S is a source of data (e.g. a DPI_HDR_XTYPE_E::OUTBOUND
                                                                 DPI DMA instruction), the referenced cache blocks are not allocated into the L2
                                                                 cache as part of completing the DMA (when not already present in the L2) if [AC]
                                                                 is clear.

                                                                 When the DPI_DMA_LOCAL_PTR_S is a destination for data (e.g. a
                                                                 DPI_HDR_XTYPE_E::INBOUND DPI DMA instruction), the referenced cache blocks are
                                                                 not allocated into the cache as part of completing the DMA (when not already
                                                                 present in the L2) if [AC] is clear, and either:

                                                                 * the entire cache block is written by this DPI_DMA_LOCAL_PTR_S, or

                                                                 * [F] is set so that the entire cache block can be written. */
        uint64_t f                     : 1;  /**< [ 62: 62] Full-block write operations are allowed.
                                                                 Only used with L2/DRAM Pointers.

                                                                 When set, the hardware is permitted to write all the bytes in the cache blocks
                                                                 covered by [PTR] .. [PTR] + [SIZE] - 1. This can improve memory system performance
                                                                 when the write misses in the L2 cache.

                                                                 [F] can only be set for DPI_DMA_LOCAL_PTR_S's that can be written to:

                                                                 * The DPI_DMA_LOCAL_PTR_S's in the first-pointers area that are write pointers
                                                                   for DPI_HDR_XTYPE_E::INBOUND DPI DMA instructions.

                                                                 * The DPI_DMA_LOCAL_PTR_S's in the last-pointers area that are always write
                                                                   pointers (when present for DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA instructions).

                                                                 [F] must not be set for DPI_DMA_LOCAL_PTR_S's that are not written to:

                                                                 * The DPI_DMA_LOCAL_PTR_S's in the first-pointers area for DPI_HDR_XTYPE_E::OUTBOUND
                                                                   and DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA instructions */
        uint64_t i                     : 1;  /**< [ 63: 63] Invert free. Only used with L2/DRAM Pointers.

                                                                 This bit gives the software the ability to free buffers
                                                                 independently for a DPI_HDR_XTYPE_E::OUTBOUND DMA transfer when
                                                                 DPI_DMA_INSTR_HDR_S[II] is clear. See DPI_DMA_INSTR_HDR_S[II] and
                                                                 DPI_DMA_INSTR_HDR_S[FL].

                                                                 [I] is not used by DPI when DPI_DMA_INSTR_HDR_S[II] is set. [I] must not be set,
                                                                 and DPI never frees buffers for DPI_HDR_XTYPE_E::INBOUND and
                                                                 DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA instructions. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t ptr                   : 64; /**< [127: 64] For L2/DRAM - bits [48:0] used for byte pointer. Points to where the packet data starts.
                                                                 PTR can be any
                                                                 byte alignment. Note that PTR is interpreted as a little-endian byte pointer when BED
                                                                 is clear, a big-endian byte pointer when BED is set. Bits [63:49] ignored and should be
                                                                 zero
                                                                 For MAC - 64-bit memory space pointer */
#else /* Word 1 - Little Endian */
        uint64_t ptr                   : 64; /**< [127: 64] For L2/DRAM - bits [48:0] used for byte pointer. Points to where the packet data starts.
                                                                 PTR can be any
                                                                 byte alignment. Note that PTR is interpreted as a little-endian byte pointer when BED
                                                                 is clear, a big-endian byte pointer when BED is set. Bits [63:49] ignored and should be
                                                                 zero
                                                                 For MAC - 64-bit memory space pointer */
#endif /* Word 1 - End */
    } s;
    /* struct bdk_dpi_dma_local_ptr_s_s cn; */
};

/**
 * Register (NCB) dpi#_bist_status
 *
 * DPI BIST Status Register
 * This is the built-in self-test (BIST) status register. Each bit is the BIST result of an
 * individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t bist                  : 56; /**< [ 55:  0](RO/H) BIST results. Hardware sets a bit in BIST for memory that fails.
                                                                 Internal:
                                                                 dpi.dma.csr.spi__csr_bist_status[7:0],     55:48
                                                                 dpi.dma.csr.r_rdb_buff__bist_status[23:0], 47:24
                                                                 dpi.dma.csr.rdb_tmem__bist_status,         23
                                                                 dpi.dma.csr.req_mem__bist_status[1:0],     22:21
                                                                 dpi.dma.csr.req_ctl__bist_status[1:0],     20:19 -- these bits are tied off to zero
                                                                 dpi.dma.csr.dsi1__bist_status[3:0],        18:15
                                                                 dpi.dma.csr.dsi0__bist_status[3:0],        14:11
                                                                 dpi.dma.csr.ncbo__bist_status[2:0],        10:8
                                                                 dpi.dma.csr.ncbib__csr_bist_status[3:0],    7:4
                                                                 dpi.dma.csr.ncbia__csr_bist_status[3:0]     3:0 */
#else /* Word 0 - Little Endian */
        uint64_t bist                  : 56; /**< [ 55:  0](RO/H) BIST results. Hardware sets a bit in BIST for memory that fails.
                                                                 Internal:
                                                                 dpi.dma.csr.spi__csr_bist_status[7:0],     55:48
                                                                 dpi.dma.csr.r_rdb_buff__bist_status[23:0], 47:24
                                                                 dpi.dma.csr.rdb_tmem__bist_status,         23
                                                                 dpi.dma.csr.req_mem__bist_status[1:0],     22:21
                                                                 dpi.dma.csr.req_ctl__bist_status[1:0],     20:19 -- these bits are tied off to zero
                                                                 dpi.dma.csr.dsi1__bist_status[3:0],        18:15
                                                                 dpi.dma.csr.dsi0__bist_status[3:0],        14:11
                                                                 dpi.dma.csr.ncbo__bist_status[2:0],        10:8
                                                                 dpi.dma.csr.ncbib__csr_bist_status[3:0],    7:4
                                                                 dpi.dma.csr.ncbia__csr_bist_status[3:0]     3:0 */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_bist_status_s cn; */
} bdk_dpix_bist_status_t;

static inline uint64_t BDK_DPIX_BIST_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_BIST_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004000ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004000ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_BIST_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_BIST_STATUS(a) bdk_dpix_bist_status_t
#define bustype_BDK_DPIX_BIST_STATUS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_BIST_STATUS(a) "DPIX_BIST_STATUS"
#define device_bar_BDK_DPIX_BIST_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_BIST_STATUS(a) (a)
#define arguments_BDK_DPIX_BIST_STATUS(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_ctl
 *
 * DPI Control Register
 * This register provides the enable bit for the DMA and packet state machines.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t en                    : 1;  /**< [  0:  0](R/W) Turns on the DMA and packet state machines. */
#else /* Word 0 - Little Endian */
        uint64_t en                    : 1;  /**< [  0:  0](R/W) Turns on the DMA and packet state machines. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_ctl_s cn; */
} bdk_dpix_ctl_t;

static inline uint64_t BDK_DPIX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004010ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004010ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_CTL(a) bdk_dpix_ctl_t
#define bustype_BDK_DPIX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_CTL(a) "DPIX_CTL"
#define device_bar_BDK_DPIX_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_CTL(a) (a)
#define arguments_BDK_DPIX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_dbe_int
 *
 * DPI ECC SBE Interrupt Register
 * This register contains ECC Double Bit error interrupt summary bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dbe_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t rdb_dbe               : 1;  /**< [  0:  0](R/W1C/H) Set when a double-bit error is detected in the RDB RAM. */
#else /* Word 0 - Little Endian */
        uint64_t rdb_dbe               : 1;  /**< [  0:  0](R/W1C/H) Set when a double-bit error is detected in the RDB RAM. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dbe_int_s cn; */
} bdk_dpix_dbe_int_t;

static inline uint64_t BDK_DPIX_DBE_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DBE_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e0000041a8ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e0000041a8ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_DBE_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_DBE_INT(a) bdk_dpix_dbe_int_t
#define bustype_BDK_DPIX_DBE_INT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DBE_INT(a) "DPIX_DBE_INT"
#define device_bar_BDK_DPIX_DBE_INT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DBE_INT(a) (a)
#define arguments_BDK_DPIX_DBE_INT(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_dbe_int_ena_w1c
 *
 * DPI DBE Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dbe_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t rdb_dbe               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for DPI(0)_DBE_INT[RDB_DBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rdb_dbe               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for DPI(0)_DBE_INT[RDB_DBE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dbe_int_ena_w1c_s cn; */
} bdk_dpix_dbe_int_ena_w1c_t;

static inline uint64_t BDK_DPIX_DBE_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DBE_INT_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e0000041b8ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e0000041b8ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_DBE_INT_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_DBE_INT_ENA_W1C(a) bdk_dpix_dbe_int_ena_w1c_t
#define bustype_BDK_DPIX_DBE_INT_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DBE_INT_ENA_W1C(a) "DPIX_DBE_INT_ENA_W1C"
#define device_bar_BDK_DPIX_DBE_INT_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DBE_INT_ENA_W1C(a) (a)
#define arguments_BDK_DPIX_DBE_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_dbe_int_ena_w1s
 *
 * DPI DBE Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dbe_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t rdb_dbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for DPI(0)_DBE_INT[RDB_DBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rdb_dbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for DPI(0)_DBE_INT[RDB_DBE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dbe_int_ena_w1s_s cn; */
} bdk_dpix_dbe_int_ena_w1s_t;

static inline uint64_t BDK_DPIX_DBE_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DBE_INT_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e0000041c0ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e0000041c0ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_DBE_INT_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_DBE_INT_ENA_W1S(a) bdk_dpix_dbe_int_ena_w1s_t
#define bustype_BDK_DPIX_DBE_INT_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DBE_INT_ENA_W1S(a) "DPIX_DBE_INT_ENA_W1S"
#define device_bar_BDK_DPIX_DBE_INT_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DBE_INT_ENA_W1S(a) (a)
#define arguments_BDK_DPIX_DBE_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_dbe_int_w1s
 *
 * DPI DBE Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dbe_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t rdb_dbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets DPI(0)_DBE_INT[RDB_DBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rdb_dbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets DPI(0)_DBE_INT[RDB_DBE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dbe_int_w1s_s cn; */
} bdk_dpix_dbe_int_w1s_t;

static inline uint64_t BDK_DPIX_DBE_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DBE_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e0000041b0ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e0000041b0ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_DBE_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_DBE_INT_W1S(a) bdk_dpix_dbe_int_w1s_t
#define bustype_BDK_DPIX_DBE_INT_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DBE_INT_W1S(a) "DPIX_DBE_INT_W1S"
#define device_bar_BDK_DPIX_DBE_INT_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DBE_INT_W1S(a) (a)
#define arguments_BDK_DPIX_DBE_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_dma#_counts
 *
 * DPI DMA Instruction Counts Registers
 * These registers provide values for determining the number of instructions in the local
 * instruction FIFO.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dmax_counts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_39_63        : 25;
        uint64_t fcnt                  : 7;  /**< [ 38: 32](RO/H) FIFO count. Specifies the number of words in the instruction FIFO locally cached within DPI. */
        uint64_t dbell                 : 32; /**< [ 31:  0](RO/H) Doorbell. Specifies the number of available words of instructions to read. */
#else /* Word 0 - Little Endian */
        uint64_t dbell                 : 32; /**< [ 31:  0](RO/H) Doorbell. Specifies the number of available words of instructions to read. */
        uint64_t fcnt                  : 7;  /**< [ 38: 32](RO/H) FIFO count. Specifies the number of words in the instruction FIFO locally cached within DPI. */
        uint64_t reserved_39_63        : 25;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_counts_s cn; */
} bdk_dpix_dmax_counts_t;

static inline uint64_t BDK_DPIX_DMAX_COUNTS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_COUNTS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000018ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=7)))
        return 0x86e000000018ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_COUNTS", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_COUNTS(a,b) bdk_dpix_dmax_counts_t
#define bustype_BDK_DPIX_DMAX_COUNTS(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_COUNTS(a,b) "DPIX_DMAX_COUNTS"
#define device_bar_BDK_DPIX_DMAX_COUNTS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMAX_COUNTS(a,b) (a)
#define arguments_BDK_DPIX_DMAX_COUNTS(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma#_dbell
 *
 * DPI DMA Doorbell Registers
 * This is the door bell register for the eight DMA instruction queues.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dmax_dbell_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t dbell                 : 16; /**< [ 15:  0](WO/H) Doorbell value. The value written to this register is added to the number of eight-byte
                                                                 words to be read and processed for the low-priority DMA queue. */
#else /* Word 0 - Little Endian */
        uint64_t dbell                 : 16; /**< [ 15:  0](WO/H) Doorbell value. The value written to this register is added to the number of eight-byte
                                                                 words to be read and processed for the low-priority DMA queue. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_dbell_s cn; */
} bdk_dpix_dmax_dbell_t;

static inline uint64_t BDK_DPIX_DMAX_DBELL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_DBELL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000008ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=7)))
        return 0x86e000000008ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_DBELL", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_DBELL(a,b) bdk_dpix_dmax_dbell_t
#define bustype_BDK_DPIX_DMAX_DBELL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_DBELL(a,b) "DPIX_DMAX_DBELL"
#define device_bar_BDK_DPIX_DMAX_DBELL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMAX_DBELL(a,b) (a)
#define arguments_BDK_DPIX_DMAX_DBELL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma#_err_rsp_status
 *
 * DPI DMA Error Response Status Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dmax_err_rsp_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t status                : 6;  /**< [  5:  0](R/W1C/H) [STATUS] captures the ErrorResponse status of the last 6 instructions for each
                                                                 instruction queue. [STATUS]<5> represents the status for first instruction in
                                                                 instruction order while [STATUS]<0> represents the last or most recent
                                                                 instruction. If [STATUS]<n> is set, then the Nth instruction in the given queue
                                                                 experienced an ErrorResponse. Otherwise, it completed normally. */
#else /* Word 0 - Little Endian */
        uint64_t status                : 6;  /**< [  5:  0](R/W1C/H) [STATUS] captures the ErrorResponse status of the last 6 instructions for each
                                                                 instruction queue. [STATUS]<5> represents the status for first instruction in
                                                                 instruction order while [STATUS]<0> represents the last or most recent
                                                                 instruction. If [STATUS]<n> is set, then the Nth instruction in the given queue
                                                                 experienced an ErrorResponse. Otherwise, it completed normally. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_err_rsp_status_s cn; */
} bdk_dpix_dmax_err_rsp_status_t;

static inline uint64_t BDK_DPIX_DMAX_ERR_RSP_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_ERR_RSP_STATUS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000428ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=7)))
        return 0x86e000000428ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_ERR_RSP_STATUS", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_ERR_RSP_STATUS(a,b) bdk_dpix_dmax_err_rsp_status_t
#define bustype_BDK_DPIX_DMAX_ERR_RSP_STATUS(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_ERR_RSP_STATUS(a,b) "DPIX_DMAX_ERR_RSP_STATUS"
#define device_bar_BDK_DPIX_DMAX_ERR_RSP_STATUS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMAX_ERR_RSP_STATUS(a,b) (a)
#define arguments_BDK_DPIX_DMAX_ERR_RSP_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma#_ibuff_csize
 *
 * DPI DMA Instruction-Buffer Chunk Size Registers
 * These registers provide the address to start reading instructions for the eight DMA
 * instruction queues. These register should only be written to when the specified queue is
 * disabled (DPI()_REQQ_GBL_EN[QEN]).
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dmax_ibuff_csize_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t idle                  : 1;  /**< [ 63: 63](RO/H) DMA request queue is idle. When asserted, the associated request queue is idle. */
        uint64_t reserved_14_62        : 49;
        uint64_t csize                 : 14; /**< [ 13:  0](R/W) The size in 8-byte words of the DMA instruction chunk. This value should only be written
                                                                 at known times in order to prevent corruption of the instruction queue. */
#else /* Word 0 - Little Endian */
        uint64_t csize                 : 14; /**< [ 13:  0](R/W) The size in 8-byte words of the DMA instruction chunk. This value should only be written
                                                                 at known times in order to prevent corruption of the instruction queue. */
        uint64_t reserved_14_62        : 49;
        uint64_t idle                  : 1;  /**< [ 63: 63](RO/H) DMA request queue is idle. When asserted, the associated request queue is idle. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_ibuff_csize_s cn; */
} bdk_dpix_dmax_ibuff_csize_t;

static inline uint64_t BDK_DPIX_DMAX_IBUFF_CSIZE(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_IBUFF_CSIZE(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000400ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=7)))
        return 0x86e000000400ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_IBUFF_CSIZE", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_IBUFF_CSIZE(a,b) bdk_dpix_dmax_ibuff_csize_t
#define bustype_BDK_DPIX_DMAX_IBUFF_CSIZE(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_IBUFF_CSIZE(a,b) "DPIX_DMAX_IBUFF_CSIZE"
#define device_bar_BDK_DPIX_DMAX_IBUFF_CSIZE(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMAX_IBUFF_CSIZE(a,b) (a)
#define arguments_BDK_DPIX_DMAX_IBUFF_CSIZE(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma#_ibuff_saddr
 *
 * DPI DMA Instruction-Buffer Starting-Address Registers
 * These registers provide the address to start reading instructions for the eight DMA
 * instruction queues. These register should only be written to when the specified queue is
 * disabled (DPI()_REQQ_GBL_EN[QEN]).
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dmax_ibuff_saddr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t saddr                 : 42; /**< [ 48:  7](R/W/H) Starting address. The 128-byte aligned starting or chunk address. SADDR is address bit
                                                                 <48:7> of the starting instructions address. When new chunks are fetched by the hardware,
                                                                 SADDR is updated to reflect the address of the current chunk. A write to SADDR resets both
                                                                 the queue's doorbell (DPI()_DMA()_COUNTS[DBELL]) and its tail pointer
                                                                 (DPI()_DMA()_NADDR[ADDR]). */
        uint64_t reserved_0_6          : 7;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_6          : 7;
        uint64_t saddr                 : 42; /**< [ 48:  7](R/W/H) Starting address. The 128-byte aligned starting or chunk address. SADDR is address bit
                                                                 <48:7> of the starting instructions address. When new chunks are fetched by the hardware,
                                                                 SADDR is updated to reflect the address of the current chunk. A write to SADDR resets both
                                                                 the queue's doorbell (DPI()_DMA()_COUNTS[DBELL]) and its tail pointer
                                                                 (DPI()_DMA()_NADDR[ADDR]). */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_ibuff_saddr_s cn; */
} bdk_dpix_dmax_ibuff_saddr_t;

static inline uint64_t BDK_DPIX_DMAX_IBUFF_SADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_IBUFF_SADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000010ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=7)))
        return 0x86e000000010ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_IBUFF_SADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_IBUFF_SADDR(a,b) bdk_dpix_dmax_ibuff_saddr_t
#define bustype_BDK_DPIX_DMAX_IBUFF_SADDR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_IBUFF_SADDR(a,b) "DPIX_DMAX_IBUFF_SADDR"
#define device_bar_BDK_DPIX_DMAX_IBUFF_SADDR(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMAX_IBUFF_SADDR(a,b) (a)
#define arguments_BDK_DPIX_DMAX_IBUFF_SADDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma#_ids
 *
 * DPI DMA Request ID Registers
 * These registers configure the streamID, GMID and AURA values for each request queue.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dmax_ids_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t inst_aura             : 12; /**< [ 59: 48](R/W) FPA guest-aura instruction chunk. The guest-aura that the instruction chunk for
                                                                 DMA operations page will be returned to when freed. */
        uint64_t inst_strm             : 8;  /**< [ 47: 40](R/W) Stream identifier bits <7:0> for instruction reads. Stream ID <15:8> is from the DPI's
                                                                 PCC bus identifier, PCC_DEV_CON_E::DPI()<15:8>.

                                                                 Internal:
                                                                 Stream ID <15:8> comes from pcc__blk_stream_id. */
        uint64_t dma_strm              : 8;  /**< [ 39: 32](R/W) Stream identifier bits <7:0> for DMA reads and writes. Stream ID <15:8> is from the DPI's
                                                                 PCC bus identifier, PCC_DEV_CON_E::DPI()<15:8>.

                                                                 Internal:
                                                                 Stream ID <15:8> comes from pcc__blk_stream_id. */
        uint64_t reserved_16_31        : 16;
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Guest machine identifier. The GMID this request queue uses for FPA buffer
                                                                 free/allocates, and for SSO add-works.
                                                                 Must be nonzero or FPA/SSO will drop requests; see FPA_PF_MAP() and SSO_PF_MAP(). */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Guest machine identifier. The GMID this request queue uses for FPA buffer
                                                                 free/allocates, and for SSO add-works.
                                                                 Must be nonzero or FPA/SSO will drop requests; see FPA_PF_MAP() and SSO_PF_MAP(). */
        uint64_t reserved_16_31        : 16;
        uint64_t dma_strm              : 8;  /**< [ 39: 32](R/W) Stream identifier bits <7:0> for DMA reads and writes. Stream ID <15:8> is from the DPI's
                                                                 PCC bus identifier, PCC_DEV_CON_E::DPI()<15:8>.

                                                                 Internal:
                                                                 Stream ID <15:8> comes from pcc__blk_stream_id. */
        uint64_t inst_strm             : 8;  /**< [ 47: 40](R/W) Stream identifier bits <7:0> for instruction reads. Stream ID <15:8> is from the DPI's
                                                                 PCC bus identifier, PCC_DEV_CON_E::DPI()<15:8>.

                                                                 Internal:
                                                                 Stream ID <15:8> comes from pcc__blk_stream_id. */
        uint64_t inst_aura             : 12; /**< [ 59: 48](R/W) FPA guest-aura instruction chunk. The guest-aura that the instruction chunk for
                                                                 DMA operations page will be returned to when freed. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_ids_s cn; */
} bdk_dpix_dmax_ids_t;

static inline uint64_t BDK_DPIX_DMAX_IDS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_IDS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000418ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=7)))
        return 0x86e000000418ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_IDS", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_IDS(a,b) bdk_dpix_dmax_ids_t
#define bustype_BDK_DPIX_DMAX_IDS(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_IDS(a,b) "DPIX_DMAX_IDS"
#define device_bar_BDK_DPIX_DMAX_IDS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMAX_IDS(a,b) (a)
#define arguments_BDK_DPIX_DMAX_IDS(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma#_iflight
 *
 * DPI DMA In-Flight Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dmax_iflight_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t cnt                   : 3;  /**< [  2:  0](R/W) The number of instructions from a given queue that can be in flight to the DMA engines at
                                                                 a time. Reset value matches the number of DMA engines. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 3;  /**< [  2:  0](R/W) The number of instructions from a given queue that can be in flight to the DMA engines at
                                                                 a time. Reset value matches the number of DMA engines. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_iflight_s cn; */
} bdk_dpix_dmax_iflight_t;

static inline uint64_t BDK_DPIX_DMAX_IFLIGHT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_IFLIGHT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000420ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=7)))
        return 0x86e000000420ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_IFLIGHT", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_IFLIGHT(a,b) bdk_dpix_dmax_iflight_t
#define bustype_BDK_DPIX_DMAX_IFLIGHT(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_IFLIGHT(a,b) "DPIX_DMAX_IFLIGHT"
#define device_bar_BDK_DPIX_DMAX_IFLIGHT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMAX_IFLIGHT(a,b) (a)
#define arguments_BDK_DPIX_DMAX_IFLIGHT(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma#_naddr
 *
 * DPI DMA Next Ichunk Address Registers
 * These registers provide the L2C addresses to read the next Ichunk data.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dmax_naddr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 49; /**< [ 48:  0](RO/H) Address. Provides the next L2C address to read instructions.  For diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 49; /**< [ 48:  0](RO/H) Address. Provides the next L2C address to read instructions.  For diagnostic use only. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_naddr_s cn; */
} bdk_dpix_dmax_naddr_t;

static inline uint64_t BDK_DPIX_DMAX_NADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_NADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000020ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=7)))
        return 0x86e000000020ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_NADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_NADDR(a,b) bdk_dpix_dmax_naddr_t
#define bustype_BDK_DPIX_DMAX_NADDR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_NADDR(a,b) "DPIX_DMAX_NADDR"
#define device_bar_BDK_DPIX_DMAX_NADDR(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMAX_NADDR(a,b) (a)
#define arguments_BDK_DPIX_DMAX_NADDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma#_reqbnk0
 *
 * DPI DMA Request State Bank 0 Registers
 * These registers provide the current contents of the request state machine, bank 0.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dmax_reqbnk0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t state                 : 64; /**< [ 63:  0](RO/H) State. Provides the current contents of the request state machine. */
#else /* Word 0 - Little Endian */
        uint64_t state                 : 64; /**< [ 63:  0](RO/H) State. Provides the current contents of the request state machine. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_reqbnk0_s cn; */
} bdk_dpix_dmax_reqbnk0_t;

static inline uint64_t BDK_DPIX_DMAX_REQBNK0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_REQBNK0(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000408ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=7)))
        return 0x86e000000408ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_REQBNK0", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_REQBNK0(a,b) bdk_dpix_dmax_reqbnk0_t
#define bustype_BDK_DPIX_DMAX_REQBNK0(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_REQBNK0(a,b) "DPIX_DMAX_REQBNK0"
#define device_bar_BDK_DPIX_DMAX_REQBNK0(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMAX_REQBNK0(a,b) (a)
#define arguments_BDK_DPIX_DMAX_REQBNK0(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma#_reqbnk1
 *
 * DPI DMA Request State Bank 1 Registers
 * These registers provide the current contents of the request state machine, bank 1.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dmax_reqbnk1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t state                 : 64; /**< [ 63:  0](RO/H) State. Provides the current contents of the request state machine. */
#else /* Word 0 - Little Endian */
        uint64_t state                 : 64; /**< [ 63:  0](RO/H) State. Provides the current contents of the request state machine. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_reqbnk1_s cn; */
} bdk_dpix_dmax_reqbnk1_t;

static inline uint64_t BDK_DPIX_DMAX_REQBNK1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_REQBNK1(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000410ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=7)))
        return 0x86e000000410ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_REQBNK1", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_REQBNK1(a,b) bdk_dpix_dmax_reqbnk1_t
#define bustype_BDK_DPIX_DMAX_REQBNK1(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_REQBNK1(a,b) "DPIX_DMAX_REQBNK1"
#define device_bar_BDK_DPIX_DMAX_REQBNK1(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMAX_REQBNK1(a,b) (a)
#define arguments_BDK_DPIX_DMAX_REQBNK1(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma#_reqq_ctl
 *
 * DPI DMA Request Queue Control Register
 * This register contains the control bits for transactions on the eight request queues.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dmax_reqq_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t des_be                : 1;  /**< [ 12: 12](R/W) Instruction Descriptor Big Endian mode. When set, Instructions data will come from memory
                                                                 in Big Endian format and the bytes will be reversed before being used in DPI. */
        uint64_t reserved_9_11         : 3;
        uint64_t st_cmd                : 1;  /**< [  8:  8](R/W) When DPI issues a store full line command to the L2C that is to be cached, this field
                                                                 select the type of store command to use:
                                                                 0 = STF.
                                                                 1 = STY. */
        uint64_t reserved_2_7          : 6;
        uint64_t ld_cmd                : 2;  /**< [  1:  0](R/W) When DPI issues a load command to the L2C that is to be cached, this field select the type
                                                                 of load command to use:
                                                                 0x0 = LDD.
                                                                 0x1 = LDI.
                                                                 0x2 = LDE.
                                                                 0x3 = LDY. */
#else /* Word 0 - Little Endian */
        uint64_t ld_cmd                : 2;  /**< [  1:  0](R/W) When DPI issues a load command to the L2C that is to be cached, this field select the type
                                                                 of load command to use:
                                                                 0x0 = LDD.
                                                                 0x1 = LDI.
                                                                 0x2 = LDE.
                                                                 0x3 = LDY. */
        uint64_t reserved_2_7          : 6;
        uint64_t st_cmd                : 1;  /**< [  8:  8](R/W) When DPI issues a store full line command to the L2C that is to be cached, this field
                                                                 select the type of store command to use:
                                                                 0 = STF.
                                                                 1 = STY. */
        uint64_t reserved_9_11         : 3;
        uint64_t des_be                : 1;  /**< [ 12: 12](R/W) Instruction Descriptor Big Endian mode. When set, Instructions data will come from memory
                                                                 in Big Endian format and the bytes will be reversed before being used in DPI. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_reqq_ctl_s cn; */
} bdk_dpix_dmax_reqq_ctl_t;

static inline uint64_t BDK_DPIX_DMAX_REQQ_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_REQQ_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000000ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=7)))
        return 0x86e000000000ll + 0x10000000000ll * ((a) & 0x0) + 0x800ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_REQQ_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_REQQ_CTL(a,b) bdk_dpix_dmax_reqq_ctl_t
#define bustype_BDK_DPIX_DMAX_REQQ_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_REQQ_CTL(a,b) "DPIX_DMAX_REQQ_CTL"
#define device_bar_BDK_DPIX_DMAX_REQQ_CTL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMAX_REQQ_CTL(a,b) (a)
#define arguments_BDK_DPIX_DMAX_REQQ_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma_cc#_cnt
 *
 * DPI DMA Per-Process Instruction Completion Counter Register
 * These registers provide a per-process instruction completion counter.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dma_ccx_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t cnt                   : 16; /**< [ 15:  0](R/W/H) DPI DMA per-process instruction completion counter. DPI can increment a counter upon
                                                                 completion of a DPI DMA instruction. DPI subtracts the value written
                                                                 from [CNT] on a software write. A nonzero [CNT] asserts the corresponding
                                                                 DPI()_DMA_CC_INT bit.

                                                                 DPI increments the [CNT] selected by DPI_DMA_INSTR_HDR_S[PTR] by one after completing
                                                                 a DPI_DMA_INSTR_HDR_S[PT]=DPI_HDR_PT_E::CNT DPI DMA instruction. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 16; /**< [ 15:  0](R/W/H) DPI DMA per-process instruction completion counter. DPI can increment a counter upon
                                                                 completion of a DPI DMA instruction. DPI subtracts the value written
                                                                 from [CNT] on a software write. A nonzero [CNT] asserts the corresponding
                                                                 DPI()_DMA_CC_INT bit.

                                                                 DPI increments the [CNT] selected by DPI_DMA_INSTR_HDR_S[PTR] by one after completing
                                                                 a DPI_DMA_INSTR_HDR_S[PT]=DPI_HDR_PT_E::CNT DPI DMA instruction. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dma_ccx_cnt_s cn; */
} bdk_dpix_dma_ccx_cnt_t;

static inline uint64_t BDK_DPIX_DMA_CCX_CNT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMA_CCX_CNT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=63)))
        return 0x86e000006000ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=63)))
        return 0x86e000006000ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3f);
    __bdk_csr_fatal("DPIX_DMA_CCX_CNT", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMA_CCX_CNT(a,b) bdk_dpix_dma_ccx_cnt_t
#define bustype_BDK_DPIX_DMA_CCX_CNT(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMA_CCX_CNT(a,b) "DPIX_DMA_CCX_CNT"
#define device_bar_BDK_DPIX_DMA_CCX_CNT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMA_CCX_CNT(a,b) (a)
#define arguments_BDK_DPIX_DMA_CCX_CNT(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma_cc#_int
 *
 * DPI DMA Per-Process Instruction Completion Interrupt Register
 * This register contains per-process completion interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dma_ccx_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t complete              : 1;  /**< [  0:  0](R/W1C/H) DPI DMA per-process instruction completion interrupt. See DPI()_DMA_CC()_CNT. */
#else /* Word 0 - Little Endian */
        uint64_t complete              : 1;  /**< [  0:  0](R/W1C/H) DPI DMA per-process instruction completion interrupt. See DPI()_DMA_CC()_CNT. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dma_ccx_int_s cn; */
} bdk_dpix_dma_ccx_int_t;

static inline uint64_t BDK_DPIX_DMA_CCX_INT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMA_CCX_INT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=63)))
        return 0x86e000005000ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=63)))
        return 0x86e000005000ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3f);
    __bdk_csr_fatal("DPIX_DMA_CCX_INT", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMA_CCX_INT(a,b) bdk_dpix_dma_ccx_int_t
#define bustype_BDK_DPIX_DMA_CCX_INT(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMA_CCX_INT(a,b) "DPIX_DMA_CCX_INT"
#define device_bar_BDK_DPIX_DMA_CCX_INT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMA_CCX_INT(a,b) (a)
#define arguments_BDK_DPIX_DMA_CCX_INT(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma_cc#_int_ena_w1c
 *
 * DPI DMA Per-Process Instruction Completion Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dma_ccx_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t complete              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for DPI(0)_DMA_CC(0..63)_INT[COMPLETE]. */
#else /* Word 0 - Little Endian */
        uint64_t complete              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for DPI(0)_DMA_CC(0..63)_INT[COMPLETE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dma_ccx_int_ena_w1c_s cn; */
} bdk_dpix_dma_ccx_int_ena_w1c_t;

static inline uint64_t BDK_DPIX_DMA_CCX_INT_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMA_CCX_INT_ENA_W1C(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=63)))
        return 0x86e000005800ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=63)))
        return 0x86e000005800ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3f);
    __bdk_csr_fatal("DPIX_DMA_CCX_INT_ENA_W1C", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMA_CCX_INT_ENA_W1C(a,b) bdk_dpix_dma_ccx_int_ena_w1c_t
#define bustype_BDK_DPIX_DMA_CCX_INT_ENA_W1C(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMA_CCX_INT_ENA_W1C(a,b) "DPIX_DMA_CCX_INT_ENA_W1C"
#define device_bar_BDK_DPIX_DMA_CCX_INT_ENA_W1C(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMA_CCX_INT_ENA_W1C(a,b) (a)
#define arguments_BDK_DPIX_DMA_CCX_INT_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma_cc#_int_ena_w1s
 *
 * DPI DMA Per-Process Instruction Completion Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dma_ccx_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t complete              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for DPI(0)_DMA_CC(0..63)_INT[COMPLETE]. */
#else /* Word 0 - Little Endian */
        uint64_t complete              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for DPI(0)_DMA_CC(0..63)_INT[COMPLETE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dma_ccx_int_ena_w1s_s cn; */
} bdk_dpix_dma_ccx_int_ena_w1s_t;

static inline uint64_t BDK_DPIX_DMA_CCX_INT_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMA_CCX_INT_ENA_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=63)))
        return 0x86e000005c00ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=63)))
        return 0x86e000005c00ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3f);
    __bdk_csr_fatal("DPIX_DMA_CCX_INT_ENA_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMA_CCX_INT_ENA_W1S(a,b) bdk_dpix_dma_ccx_int_ena_w1s_t
#define bustype_BDK_DPIX_DMA_CCX_INT_ENA_W1S(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMA_CCX_INT_ENA_W1S(a,b) "DPIX_DMA_CCX_INT_ENA_W1S"
#define device_bar_BDK_DPIX_DMA_CCX_INT_ENA_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMA_CCX_INT_ENA_W1S(a,b) (a)
#define arguments_BDK_DPIX_DMA_CCX_INT_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma_cc#_int_w1s
 *
 * DPI DMA Per-Process Instruction Completion Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dma_ccx_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t complete              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets DPI(0)_DMA_CC(0..63)_INT[COMPLETE]. */
#else /* Word 0 - Little Endian */
        uint64_t complete              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets DPI(0)_DMA_CC(0..63)_INT[COMPLETE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dma_ccx_int_w1s_s cn; */
} bdk_dpix_dma_ccx_int_w1s_t;

static inline uint64_t BDK_DPIX_DMA_CCX_INT_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMA_CCX_INT_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=63)))
        return 0x86e000005400ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=63)))
        return 0x86e000005400ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3f);
    __bdk_csr_fatal("DPIX_DMA_CCX_INT_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMA_CCX_INT_W1S(a,b) bdk_dpix_dma_ccx_int_w1s_t
#define bustype_BDK_DPIX_DMA_CCX_INT_W1S(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMA_CCX_INT_W1S(a,b) "DPIX_DMA_CCX_INT_W1S"
#define device_bar_BDK_DPIX_DMA_CCX_INT_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMA_CCX_INT_W1S(a,b) (a)
#define arguments_BDK_DPIX_DMA_CCX_INT_W1S(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma_control
 *
 * DPI DMA Control Register
 * This register controls the operation of DMA input and output.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dma_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t ffp_dis               : 1;  /**< [ 59: 59](R/W) Force forward progress disable. The DMA engines will compete for shared resources. If the
                                                                 hardware detects that particular engines are not able to make requests to an interface,
                                                                 the hardware will periodically trade-off throughput for fairness. */
        uint64_t commit_mode           : 1;  /**< [ 58: 58](R/W) DMA engine commit mode.
                                                                 When COMMIT_MODE=1, DPI considers an instruction complete when the hardware internally
                                                                 generates the final write for the current instruction.

                                                                 When COMMIT_MODE=0, DPI additionally waits for the final write to reach the interface
                                                                 coherency point to declare the instructions complete.

                                                                 When COMMIT_MODE=1, DPI may not follow the HRM ordering rules. DPI
                                                                 hardware performance may be better with COMMIT_MODE=1 than with COMMIT_MODE=0 due to
                                                                 the relaxed ordering rules. If the HRM ordering rules are required, set COMMIT_MODE=0. */
        uint64_t reserved_57           : 1;
        uint64_t pkt_en                : 1;  /**< [ 56: 56](R/W) Enables the packet interface. When the packet interface is enabled, engines 4 and 5 are
                                                                 used for packets and are not available for DMA. When PKT_EN=1, then DMA_ENB<5>=0 and
                                                                 DMA_ENB<4>=0. */
        uint64_t reserved_54_55        : 2;
        uint64_t dma_enb               : 6;  /**< [ 53: 48](R/W) DMA engine enable. Enables the operation of the DMA engine. After being enabled an engine
                                                                 should not be disabled while processing instructions.
                                                                 When PKT_EN=1, then DMA_ENB<5>=0 and DMA_ENB<4>=0. */
        uint64_t wqecsdis              : 1;  /**< [ 47: 47](R/W) Work queue completion status disable. See DPI_HDR_PT_WQP_E.

                                                                 When [WQECSDIS] is set, DPI never writes completion status into a work queue entry. */
        uint64_t wqecsoff              : 7;  /**< [ 46: 40](R/W) Work queue completion status byte offset. For a DPI_HDR_PT_WQP_E::STATUSCA
                                                                 or DPI_HDR_PT_WQP_E::STATUSNC DPI DMA instruction, DPI writes a
                                                                 non-DPI_CS_E::NOERR (i.e. nonzero) completion status byte to (big-endian
                                                                 byte address) L2/DRAM address
                                                                    (DPI_DMA_INSTR_HDR_S[PTR] & 0xFFFFFFFFFFFFFFF8) + [WQECSOFF]

                                                                 With the reset value 0x7, DPI will write WORD0<7:0> of the WQE. */
        uint64_t zbwcsen               : 1;  /**< [ 39: 39](R/W) Zero-byte-write completion status enable.
                                                                 See DPI_HDR_PT_E::ZBC_CA and DPI_HDR_PT_E::ZBC_NC. */
        uint64_t wqecsmode             : 2;  /**< [ 38: 37](R/W) WQE completion status mode. Relevant for DPI DMA instructions with
                                                                 DPI_DMA_INSTR_HDR_S[PT]=DPI_HDR_PT_E::WQP when [WQECSDIS]=0.
                                                                 0x0 = Normal behavior. DPI will not write the completion status byte for
                                                                       DPI_HDR_PT_E::WQP DPI DMA instructions with DPI_CS_E::NOERR (i.e. zero)
                                                                       completion status, regardless of the DPI_HDR_PT_WQP_E selection of
                                                                       DPI_DMA_INSTR_HDR_S[PTR<2:0>]. DPI will write the completion
                                                                       status byte for all other DPI_CS_E (i.e. nonzero) values
                                                                       when DPI_DMA_INSTR_HDR_S[PTR<2:0>] is DPI_HDR_PT_WQP_E::STATUSCA
                                                                       or DPI_HDR_PT_WQP_E::STATUSNC and [WQECSDIS] is clear.
                                                                 0x1 = DPI will perform the completion status byte write for all
                                                                       DPI_HDR_PT_E::WQP DPI DMA instructions when DPI_DMA_INSTR_HDR_S[PTR<2:0>]
                                                                       is DPI_HDR_PT_WQP_E::STATUSCA or DPI_HDR_PT_WQP_E::STATUSNC
                                                                       and [WQECSDIS] is clear, regardless of the DPI_CS_E completion
                                                                       status value for the instruction.
                                                                 0x2 = DPI will not wait for the completion status write commit before issuing
                                                                       SSO work queue add.
                                                                 0x3 = Both debug modes specified above (under 0x1 and 0x2) are enabled. */
        uint64_t reserved_35_36        : 2;
        uint64_t ncb_tag_dis           : 1;  /**< [ 34: 34](R/W) NCB tag disable. DMA read/write transactions over NCB are mapped to individual
                                                                 request queues by using tags. If this bit is set, all NCB DMA transactions will
                                                                 use a tag of 0x0, reducing performance. */
        uint64_t reserved_33           : 1;
        uint64_t ldwb                  : 1;  /**< [ 32: 32](R/W) Load don't write back. When set, the hardware is able to issue LDWB commands for pointers
                                                                 that are being freed. As a result, the line will not be written back when replaced.
                                                                 When clear, the hardware issues regular load commands to the cache which cause the
                                                                 line to be written back before being replaced. */
        uint64_t reserved_20_31        : 12;
        uint64_t o_add1                : 1;  /**< [ 19: 19](R/W) Add one.
                                                                 0 = The number of bytes in the DMA transfer is added to SLI_DMA()_CNT.
                                                                 1 = Add 1 to the SLI_DMA()_CNT DMA counters. */
        uint64_t o_ro                  : 1;  /**< [ 18: 18](R/W) If [O_MODE]=1 (DPTR format 0), [O_RO] is the relaxed ordering mode attribute
                                                                 for PCIe DMA transactions.

                                                                 If [O_MODE]=0 (DPTR format 1), [O_RO] is MACADD<60> in the PCIE MAC address and
                                                                 the relaxed ordering mode attribute comes from DPTR<60> in the DMA MAC pointer. */
        uint64_t o_ns                  : 1;  /**< [ 17: 17](R/W) If [O_MODE]=1 (DPTR format 0), [O_NS] is the no snoop attribute for PCIe DMA
                                                                 transactions.

                                                                 If [O_MODE]=0 (DPTR format 1), [O_NS] is MACADD<61> in the PCIE MAC Address and
                                                                 the no snoop mode attribute comes from DPTR<61> in the DMA MAC pointer. */
        uint64_t o_es                  : 2;  /**< [ 16: 15](R/W) If [O_MODE]=1 (DPTR format 0), [O_ES] is the endian swap mode for PCIe DMA
                                                                 transactions.

                                                                 If [O_MODE]=0 (DPTR format 1), [O_ES] is MACADD<63:62> in the PCIE MAC address
                                                                 and the endian swap mode comes from DPTR<63:62> in the DMA MAC pointer.

                                                                 See DPI_ENDIANSWAP_E. */
        uint64_t o_mode                : 1;  /**< [ 14: 14](R/W) Select PCI_POINTER mode.
                                                                 0 = DPTR format 1 is used. Use register values for address; use pointer values for ES, NS,
                                                                 RO.
                                                                 1 = DPTR format 0 is used. Use pointer values for address; use register values for ES, NS,
                                                                 RO. */
        uint64_t reserved_0_13         : 14;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_13         : 14;
        uint64_t o_mode                : 1;  /**< [ 14: 14](R/W) Select PCI_POINTER mode.
                                                                 0 = DPTR format 1 is used. Use register values for address; use pointer values for ES, NS,
                                                                 RO.
                                                                 1 = DPTR format 0 is used. Use pointer values for address; use register values for ES, NS,
                                                                 RO. */
        uint64_t o_es                  : 2;  /**< [ 16: 15](R/W) If [O_MODE]=1 (DPTR format 0), [O_ES] is the endian swap mode for PCIe DMA
                                                                 transactions.

                                                                 If [O_MODE]=0 (DPTR format 1), [O_ES] is MACADD<63:62> in the PCIE MAC address
                                                                 and the endian swap mode comes from DPTR<63:62> in the DMA MAC pointer.

                                                                 See DPI_ENDIANSWAP_E. */
        uint64_t o_ns                  : 1;  /**< [ 17: 17](R/W) If [O_MODE]=1 (DPTR format 0), [O_NS] is the no snoop attribute for PCIe DMA
                                                                 transactions.

                                                                 If [O_MODE]=0 (DPTR format 1), [O_NS] is MACADD<61> in the PCIE MAC Address and
                                                                 the no snoop mode attribute comes from DPTR<61> in the DMA MAC pointer. */
        uint64_t o_ro                  : 1;  /**< [ 18: 18](R/W) If [O_MODE]=1 (DPTR format 0), [O_RO] is the relaxed ordering mode attribute
                                                                 for PCIe DMA transactions.

                                                                 If [O_MODE]=0 (DPTR format 1), [O_RO] is MACADD<60> in the PCIE MAC address and
                                                                 the relaxed ordering mode attribute comes from DPTR<60> in the DMA MAC pointer. */
        uint64_t o_add1                : 1;  /**< [ 19: 19](R/W) Add one.
                                                                 0 = The number of bytes in the DMA transfer is added to SLI_DMA()_CNT.
                                                                 1 = Add 1 to the SLI_DMA()_CNT DMA counters. */
        uint64_t reserved_20_31        : 12;
        uint64_t ldwb                  : 1;  /**< [ 32: 32](R/W) Load don't write back. When set, the hardware is able to issue LDWB commands for pointers
                                                                 that are being freed. As a result, the line will not be written back when replaced.
                                                                 When clear, the hardware issues regular load commands to the cache which cause the
                                                                 line to be written back before being replaced. */
        uint64_t reserved_33           : 1;
        uint64_t ncb_tag_dis           : 1;  /**< [ 34: 34](R/W) NCB tag disable. DMA read/write transactions over NCB are mapped to individual
                                                                 request queues by using tags. If this bit is set, all NCB DMA transactions will
                                                                 use a tag of 0x0, reducing performance. */
        uint64_t reserved_35_36        : 2;
        uint64_t wqecsmode             : 2;  /**< [ 38: 37](R/W) WQE completion status mode. Relevant for DPI DMA instructions with
                                                                 DPI_DMA_INSTR_HDR_S[PT]=DPI_HDR_PT_E::WQP when [WQECSDIS]=0.
                                                                 0x0 = Normal behavior. DPI will not write the completion status byte for
                                                                       DPI_HDR_PT_E::WQP DPI DMA instructions with DPI_CS_E::NOERR (i.e. zero)
                                                                       completion status, regardless of the DPI_HDR_PT_WQP_E selection of
                                                                       DPI_DMA_INSTR_HDR_S[PTR<2:0>]. DPI will write the completion
                                                                       status byte for all other DPI_CS_E (i.e. nonzero) values
                                                                       when DPI_DMA_INSTR_HDR_S[PTR<2:0>] is DPI_HDR_PT_WQP_E::STATUSCA
                                                                       or DPI_HDR_PT_WQP_E::STATUSNC and [WQECSDIS] is clear.
                                                                 0x1 = DPI will perform the completion status byte write for all
                                                                       DPI_HDR_PT_E::WQP DPI DMA instructions when DPI_DMA_INSTR_HDR_S[PTR<2:0>]
                                                                       is DPI_HDR_PT_WQP_E::STATUSCA or DPI_HDR_PT_WQP_E::STATUSNC
                                                                       and [WQECSDIS] is clear, regardless of the DPI_CS_E completion
                                                                       status value for the instruction.
                                                                 0x2 = DPI will not wait for the completion status write commit before issuing
                                                                       SSO work queue add.
                                                                 0x3 = Both debug modes specified above (under 0x1 and 0x2) are enabled. */
        uint64_t zbwcsen               : 1;  /**< [ 39: 39](R/W) Zero-byte-write completion status enable.
                                                                 See DPI_HDR_PT_E::ZBC_CA and DPI_HDR_PT_E::ZBC_NC. */
        uint64_t wqecsoff              : 7;  /**< [ 46: 40](R/W) Work queue completion status byte offset. For a DPI_HDR_PT_WQP_E::STATUSCA
                                                                 or DPI_HDR_PT_WQP_E::STATUSNC DPI DMA instruction, DPI writes a
                                                                 non-DPI_CS_E::NOERR (i.e. nonzero) completion status byte to (big-endian
                                                                 byte address) L2/DRAM address
                                                                    (DPI_DMA_INSTR_HDR_S[PTR] & 0xFFFFFFFFFFFFFFF8) + [WQECSOFF]

                                                                 With the reset value 0x7, DPI will write WORD0<7:0> of the WQE. */
        uint64_t wqecsdis              : 1;  /**< [ 47: 47](R/W) Work queue completion status disable. See DPI_HDR_PT_WQP_E.

                                                                 When [WQECSDIS] is set, DPI never writes completion status into a work queue entry. */
        uint64_t dma_enb               : 6;  /**< [ 53: 48](R/W) DMA engine enable. Enables the operation of the DMA engine. After being enabled an engine
                                                                 should not be disabled while processing instructions.
                                                                 When PKT_EN=1, then DMA_ENB<5>=0 and DMA_ENB<4>=0. */
        uint64_t reserved_54_55        : 2;
        uint64_t pkt_en                : 1;  /**< [ 56: 56](R/W) Enables the packet interface. When the packet interface is enabled, engines 4 and 5 are
                                                                 used for packets and are not available for DMA. When PKT_EN=1, then DMA_ENB<5>=0 and
                                                                 DMA_ENB<4>=0. */
        uint64_t reserved_57           : 1;
        uint64_t commit_mode           : 1;  /**< [ 58: 58](R/W) DMA engine commit mode.
                                                                 When COMMIT_MODE=1, DPI considers an instruction complete when the hardware internally
                                                                 generates the final write for the current instruction.

                                                                 When COMMIT_MODE=0, DPI additionally waits for the final write to reach the interface
                                                                 coherency point to declare the instructions complete.

                                                                 When COMMIT_MODE=1, DPI may not follow the HRM ordering rules. DPI
                                                                 hardware performance may be better with COMMIT_MODE=1 than with COMMIT_MODE=0 due to
                                                                 the relaxed ordering rules. If the HRM ordering rules are required, set COMMIT_MODE=0. */
        uint64_t ffp_dis               : 1;  /**< [ 59: 59](R/W) Force forward progress disable. The DMA engines will compete for shared resources. If the
                                                                 hardware detects that particular engines are not able to make requests to an interface,
                                                                 the hardware will periodically trade-off throughput for fairness. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dma_control_s cn; */
} bdk_dpix_dma_control_t;

static inline uint64_t BDK_DPIX_DMA_CONTROL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMA_CONTROL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004018ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004018ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_DMA_CONTROL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_DMA_CONTROL(a) bdk_dpix_dma_control_t
#define bustype_BDK_DPIX_DMA_CONTROL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMA_CONTROL(a) "DPIX_DMA_CONTROL"
#define device_bar_BDK_DPIX_DMA_CONTROL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMA_CONTROL(a) (a)
#define arguments_BDK_DPIX_DMA_CONTROL(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_dma_eng#_en
 *
 * DPI DMA-Engine Queue Enable Registers
 * These registers provide control for the DMA engines.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dma_engx_en_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_39_63        : 25;
        uint64_t eng_molr              : 7;  /**< [ 38: 32](R/W) Per-engine maximum outstanding read request. 0x0 means no maximum per engine
                                                                 (although it will be still limited by the per port MOLR value.) */
        uint64_t reserved_8_31         : 24;
        uint64_t qen                   : 8;  /**< [  7:  0](R/W) Instruction queue enable. This field specifies which of eight logical instruction queues
                                                                 can be serviced by the DMA engine.
                                                                   0 = Prevent service.
                                                                   1 = Allow service.

                                                                 Setting [QEN] = 0x0 effectively disables the engine. When
                                                                 DPI()_DMA_CONTROL[PKT_EN] = 1, then DPI()_DMA_ENG()_EN[QEN] must be zero. */
#else /* Word 0 - Little Endian */
        uint64_t qen                   : 8;  /**< [  7:  0](R/W) Instruction queue enable. This field specifies which of eight logical instruction queues
                                                                 can be serviced by the DMA engine.
                                                                   0 = Prevent service.
                                                                   1 = Allow service.

                                                                 Setting [QEN] = 0x0 effectively disables the engine. When
                                                                 DPI()_DMA_CONTROL[PKT_EN] = 1, then DPI()_DMA_ENG()_EN[QEN] must be zero. */
        uint64_t reserved_8_31         : 24;
        uint64_t eng_molr              : 7;  /**< [ 38: 32](R/W) Per-engine maximum outstanding read request. 0x0 means no maximum per engine
                                                                 (although it will be still limited by the per port MOLR value.) */
        uint64_t reserved_39_63        : 25;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dma_engx_en_s cn; */
} bdk_dpix_dma_engx_en_t;

static inline uint64_t BDK_DPIX_DMA_ENGX_EN(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMA_ENGX_EN(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=5)))
        return 0x86e000004040ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=5)))
        return 0x86e000004040ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMA_ENGX_EN", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMA_ENGX_EN(a,b) bdk_dpix_dma_engx_en_t
#define bustype_BDK_DPIX_DMA_ENGX_EN(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMA_ENGX_EN(a,b) "DPIX_DMA_ENGX_EN"
#define device_bar_BDK_DPIX_DMA_ENGX_EN(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_DMA_ENGX_EN(a,b) (a)
#define arguments_BDK_DPIX_DMA_ENGX_EN(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_ecc_ctl
 *
 * DPI ECC Control Register
 * This register allows inserting ECC errors for testing.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_ecc_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t ram_cdis              : 1;  /**< [ 32: 32](R/W) RDB RAM ECC correction disable. Each bit corresponds to a different RAM. */
        uint64_t reserved_17_31        : 15;
        uint64_t ram_flip1             : 1;  /**< [ 16: 16](R/W) Flip syndrome bits on write. Flip syndrome bits <1> on writes to the corresponding RDB RAM
                                                                 to test single-bit or double-bit error handling. */
        uint64_t reserved_1_15         : 15;
        uint64_t ram_flip0             : 1;  /**< [  0:  0](R/W) Flip syndrome bits on write. Flip syndrome bits <0> on writes to the corresponding RDB RAM
                                                                 to test single-bit or double-bit error handling. */
#else /* Word 0 - Little Endian */
        uint64_t ram_flip0             : 1;  /**< [  0:  0](R/W) Flip syndrome bits on write. Flip syndrome bits <0> on writes to the corresponding RDB RAM
                                                                 to test single-bit or double-bit error handling. */
        uint64_t reserved_1_15         : 15;
        uint64_t ram_flip1             : 1;  /**< [ 16: 16](R/W) Flip syndrome bits on write. Flip syndrome bits <1> on writes to the corresponding RDB RAM
                                                                 to test single-bit or double-bit error handling. */
        uint64_t reserved_17_31        : 15;
        uint64_t ram_cdis              : 1;  /**< [ 32: 32](R/W) RDB RAM ECC correction disable. Each bit corresponds to a different RAM. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_ecc_ctl_s cn; */
} bdk_dpix_ecc_ctl_t;

static inline uint64_t BDK_DPIX_ECC_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_ECC_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004008ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004008ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_ECC_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_ECC_CTL(a) bdk_dpix_ecc_ctl_t
#define bustype_BDK_DPIX_ECC_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_ECC_CTL(a) "DPIX_ECC_CTL"
#define device_bar_BDK_DPIX_ECC_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_ECC_CTL(a) (a)
#define arguments_BDK_DPIX_ECC_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_eng#_buf
 *
 * DPI DMA Engine Buffer Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_engx_buf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_22_63        : 42;
        uint64_t base                  : 6;  /**< [ 21: 16](RO/H) The base address in 512-byte blocks of the DMA engine FIFO. */
        uint64_t reserved_5_15         : 11;
        uint64_t blks                  : 5;  /**< [  4:  0](R/W) The size of the DMA engine FIFO. The sum of the allocated FIFOs across all six
                                                                 DPI()_ENG()_BUF[BLKS] registers must not exceed the overall RDB memory size of
                                                                 32 KB. If the value of 0 is used, the corresponding engine enable in
                                                                 DPI()_DMA_CONTROL[DMA_ENB]
                                                                 must also be cleared.

                                                                 0x00 = Engine disabled.
                                                                 0x01 = 1 KB FIFO.
                                                                 0x02 = 2 KB FIFO.
                                                                 0x03 = 3 KB FIFO.
                                                                 0x04 = 4 KB FIFO.
                                                                 0x05 = 5 KB FIFO.
                                                                 0x06 = 6 KB FIFO.
                                                                 0x07 = 7 KB FIFO.
                                                                 0x08 = 8 KB FIFO.
                                                                 0x09 = 9 KB FIFO.
                                                                 0x0A = 10 KB FIFO.
                                                                 0x0B = 11 KB FIFO.
                                                                 0x0C = 12 KB FIFO.
                                                                 0x0D = 13 KB FIFO.
                                                                 0x0E = 14 KB FIFO.
                                                                 0x0F = 15 KB FIFO.
                                                                 0x10 = 16 KB FIFO. */
#else /* Word 0 - Little Endian */
        uint64_t blks                  : 5;  /**< [  4:  0](R/W) The size of the DMA engine FIFO. The sum of the allocated FIFOs across all six
                                                                 DPI()_ENG()_BUF[BLKS] registers must not exceed the overall RDB memory size of
                                                                 32 KB. If the value of 0 is used, the corresponding engine enable in
                                                                 DPI()_DMA_CONTROL[DMA_ENB]
                                                                 must also be cleared.

                                                                 0x00 = Engine disabled.
                                                                 0x01 = 1 KB FIFO.
                                                                 0x02 = 2 KB FIFO.
                                                                 0x03 = 3 KB FIFO.
                                                                 0x04 = 4 KB FIFO.
                                                                 0x05 = 5 KB FIFO.
                                                                 0x06 = 6 KB FIFO.
                                                                 0x07 = 7 KB FIFO.
                                                                 0x08 = 8 KB FIFO.
                                                                 0x09 = 9 KB FIFO.
                                                                 0x0A = 10 KB FIFO.
                                                                 0x0B = 11 KB FIFO.
                                                                 0x0C = 12 KB FIFO.
                                                                 0x0D = 13 KB FIFO.
                                                                 0x0E = 14 KB FIFO.
                                                                 0x0F = 15 KB FIFO.
                                                                 0x10 = 16 KB FIFO. */
        uint64_t reserved_5_15         : 11;
        uint64_t base                  : 6;  /**< [ 21: 16](RO/H) The base address in 512-byte blocks of the DMA engine FIFO. */
        uint64_t reserved_22_63        : 42;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_engx_buf_s cn; */
} bdk_dpix_engx_buf_t;

static inline uint64_t BDK_DPIX_ENGX_BUF(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_ENGX_BUF(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=5)))
        return 0x86e0000040c0ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=5)))
        return 0x86e0000040c0ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_ENGX_BUF", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_ENGX_BUF(a,b) bdk_dpix_engx_buf_t
#define bustype_BDK_DPIX_ENGX_BUF(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_ENGX_BUF(a,b) "DPIX_ENGX_BUF"
#define device_bar_BDK_DPIX_ENGX_BUF(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_ENGX_BUF(a,b) (a)
#define arguments_BDK_DPIX_ENGX_BUF(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_info_reg
 *
 * DPI Information Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_info_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t ffp                   : 4;  /**< [  7:  4](R/W1C/H) Force forward progress indicator. */
        uint64_t reserved_2_3          : 2;
        uint64_t ncb                   : 1;  /**< [  1:  1](R/W1C/H) NCB register access. This bit gets set in normal operation when software reads a DPI
                                                                 register through the IOI interface. */
        uint64_t rsl                   : 1;  /**< [  0:  0](R/W1C/H) RSL register access. This bit is set in normal operation when software reads a DPI
                                                                 register through the RSL interface. */
#else /* Word 0 - Little Endian */
        uint64_t rsl                   : 1;  /**< [  0:  0](R/W1C/H) RSL register access. This bit is set in normal operation when software reads a DPI
                                                                 register through the RSL interface. */
        uint64_t ncb                   : 1;  /**< [  1:  1](R/W1C/H) NCB register access. This bit gets set in normal operation when software reads a DPI
                                                                 register through the IOI interface. */
        uint64_t reserved_2_3          : 2;
        uint64_t ffp                   : 4;  /**< [  7:  4](R/W1C/H) Force forward progress indicator. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_info_reg_s cn; */
} bdk_dpix_info_reg_t;

static inline uint64_t BDK_DPIX_INFO_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_INFO_REG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004160ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004160ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_INFO_REG", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_INFO_REG(a) bdk_dpix_info_reg_t
#define bustype_BDK_DPIX_INFO_REG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_INFO_REG(a) "DPIX_INFO_REG"
#define device_bar_BDK_DPIX_INFO_REG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_INFO_REG(a) (a)
#define arguments_BDK_DPIX_INFO_REG(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_int_ena_w1c
 *
 * DPI Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_23_63        : 41;
        uint64_t req_badfil            : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[REQ_BADFIL]. */
        uint64_t req_inull             : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[REQ_INULL].
                                                                 Internal:
                                                                 The interrupt means that the DPI unit
                                                                 received fill data in which one or more or the 64-bit instruction words was all
                                                                 0's. In previous DPI implementations, there was never a case in which a valid
                                                                 instruction stream would have all 0's. In the new dual-instruction word scheme,
                                                                 the 2nd word could be zero. For example, if no completion operation is requested
                                                                 on the instruction and both PTR and DEALLOCV are zero. */
        uint64_t req_anull             : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[REQ_ANULL]. */
        uint64_t req_undflw            : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[REQ_UNDFLW]. */
        uint64_t req_ovrflw            : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[REQ_OVRFLW]. */
        uint64_t req_badlen            : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[REQ_BADLEN]. */
        uint64_t req_badadr            : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[REQ_BADADR]. */
        uint64_t dmadbo                : 8;  /**< [ 15:  8](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[DMADBO]. */
        uint64_t reserved_2_7          : 6;
        uint64_t nfovr                 : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[NFOVR]. */
        uint64_t nderr                 : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[NDERR]. */
#else /* Word 0 - Little Endian */
        uint64_t nderr                 : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[NDERR]. */
        uint64_t nfovr                 : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[NFOVR]. */
        uint64_t reserved_2_7          : 6;
        uint64_t dmadbo                : 8;  /**< [ 15:  8](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[DMADBO]. */
        uint64_t req_badadr            : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[REQ_BADADR]. */
        uint64_t req_badlen            : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[REQ_BADLEN]. */
        uint64_t req_ovrflw            : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[REQ_OVRFLW]. */
        uint64_t req_undflw            : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[REQ_UNDFLW]. */
        uint64_t req_anull             : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[REQ_ANULL]. */
        uint64_t req_inull             : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[REQ_INULL].
                                                                 Internal:
                                                                 The interrupt means that the DPI unit
                                                                 received fill data in which one or more or the 64-bit instruction words was all
                                                                 0's. In previous DPI implementations, there was never a case in which a valid
                                                                 instruction stream would have all 0's. In the new dual-instruction word scheme,
                                                                 the 2nd word could be zero. For example, if no completion operation is requested
                                                                 on the instruction and both PTR and DEALLOCV are zero. */
        uint64_t req_badfil            : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for DPI(0)_INT_REG[REQ_BADFIL]. */
        uint64_t reserved_23_63        : 41;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_int_ena_w1c_s cn; */
} bdk_dpix_int_ena_w1c_t;

static inline uint64_t BDK_DPIX_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_INT_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004178ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004178ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_INT_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_INT_ENA_W1C(a) bdk_dpix_int_ena_w1c_t
#define bustype_BDK_DPIX_INT_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_INT_ENA_W1C(a) "DPIX_INT_ENA_W1C"
#define device_bar_BDK_DPIX_INT_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_INT_ENA_W1C(a) (a)
#define arguments_BDK_DPIX_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_int_ena_w1s
 *
 * DPI Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_23_63        : 41;
        uint64_t req_badfil            : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[REQ_BADFIL]. */
        uint64_t req_inull             : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[REQ_INULL].
                                                                 Internal:
                                                                 The interrupt means that the DPI unit
                                                                 received fill data in which one or more or the 64-bit instruction words was all
                                                                 0's. In previous DPI implementations, there was never a case in which a valid
                                                                 instruction stream would have all 0's. In the new dual-instruction word scheme,
                                                                 the 2nd word could be zero. For example, if no completion operation is requested
                                                                 on the instruction and both PTR and DEALLOCV are zero. */
        uint64_t req_anull             : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[REQ_ANULL]. */
        uint64_t req_undflw            : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[REQ_UNDFLW]. */
        uint64_t req_ovrflw            : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[REQ_OVRFLW]. */
        uint64_t req_badlen            : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[REQ_BADLEN]. */
        uint64_t req_badadr            : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[REQ_BADADR]. */
        uint64_t dmadbo                : 8;  /**< [ 15:  8](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[DMADBO]. */
        uint64_t reserved_2_7          : 6;
        uint64_t nfovr                 : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[NFOVR]. */
        uint64_t nderr                 : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[NDERR]. */
#else /* Word 0 - Little Endian */
        uint64_t nderr                 : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[NDERR]. */
        uint64_t nfovr                 : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[NFOVR]. */
        uint64_t reserved_2_7          : 6;
        uint64_t dmadbo                : 8;  /**< [ 15:  8](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[DMADBO]. */
        uint64_t req_badadr            : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[REQ_BADADR]. */
        uint64_t req_badlen            : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[REQ_BADLEN]. */
        uint64_t req_ovrflw            : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[REQ_OVRFLW]. */
        uint64_t req_undflw            : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[REQ_UNDFLW]. */
        uint64_t req_anull             : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[REQ_ANULL]. */
        uint64_t req_inull             : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[REQ_INULL].
                                                                 Internal:
                                                                 The interrupt means that the DPI unit
                                                                 received fill data in which one or more or the 64-bit instruction words was all
                                                                 0's. In previous DPI implementations, there was never a case in which a valid
                                                                 instruction stream would have all 0's. In the new dual-instruction word scheme,
                                                                 the 2nd word could be zero. For example, if no completion operation is requested
                                                                 on the instruction and both PTR and DEALLOCV are zero. */
        uint64_t req_badfil            : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for DPI(0)_INT_REG[REQ_BADFIL]. */
        uint64_t reserved_23_63        : 41;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_int_ena_w1s_s cn; */
} bdk_dpix_int_ena_w1s_t;

static inline uint64_t BDK_DPIX_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_INT_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004180ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004180ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_INT_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_INT_ENA_W1S(a) bdk_dpix_int_ena_w1s_t
#define bustype_BDK_DPIX_INT_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_INT_ENA_W1S(a) "DPIX_INT_ENA_W1S"
#define device_bar_BDK_DPIX_INT_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_INT_ENA_W1S(a) (a)
#define arguments_BDK_DPIX_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_int_reg
 *
 * DPI Interrupt Summary Register
 * This register contains error flags for DPI.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_int_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_23_63        : 41;
        uint64_t req_badfil            : 1;  /**< [ 22: 22](R/W1C/H) Unexpected fill error. This bit is set when an instruction fill is received when there is
                                                                 no outstanding request. */
        uint64_t req_inull             : 1;  /**< [ 21: 21](R/W1C/H) Interrupt should be ignored.
                                                                 Internal:
                                                                 The interrupt means that the DPI unit
                                                                 received fill data in which one or more or the 64-bit instruction words was all
                                                                 0's. In previous DPI implementations, there was never a case in which a valid
                                                                 instruction stream would have all 0's. In the new dual-instruction word scheme,
                                                                 the 2nd word could be zero. For example, if no completion operation is requested
                                                                 on the instruction and both PTR and DEALLOCV are zero. */
        uint64_t req_anull             : 1;  /**< [ 20: 20](R/W1C/H) Instruction bad error. This bit is set when a fetched instruction word was 0x0. */
        uint64_t req_undflw            : 1;  /**< [ 19: 19](R/W1C/H) Instruction FIFO underflow error. This bit is set when the instruction FIFO underflows. */
        uint64_t req_ovrflw            : 1;  /**< [ 18: 18](R/W1C/H) Instruction FIFO overflow error. This bit is set when the instruction FIFO overflows. */
        uint64_t req_badlen            : 1;  /**< [ 17: 17](R/W1C/H) Fetch with length zero error. This bit is set when DPI forms an instruction fetch with
                                                                 length of zero. */
        uint64_t req_badadr            : 1;  /**< [ 16: 16](R/W1C/H) Fetch with bad pointer error. This bit is set when DPI forms an instruction fetch to the
                                                                 NULL pointer. */
        uint64_t dmadbo                : 8;  /**< [ 15:  8](R/W1C/H) Doorbell overflow error. DPI has a 32-bit counter for each request queue's outstanding
                                                                 doorbell counts. A bit is set when the corresponding doorbell count overflows. */
        uint64_t reserved_2_7          : 6;
        uint64_t nfovr                 : 1;  /**< [  1:  1](R/W1C/H) CSR FIFO overflow error. DPI can store up to 16 CSR requests, and the FIFO overflows if
                                                                 that number is exceeded. */
        uint64_t nderr                 : 1;  /**< [  0:  0](R/W1C/H) IOI decode error. This bit is set when the DPI received an IOI transaction on the outbound
                                                                 bus to the DPI device ID, but the command was not recognized. */
#else /* Word 0 - Little Endian */
        uint64_t nderr                 : 1;  /**< [  0:  0](R/W1C/H) IOI decode error. This bit is set when the DPI received an IOI transaction on the outbound
                                                                 bus to the DPI device ID, but the command was not recognized. */
        uint64_t nfovr                 : 1;  /**< [  1:  1](R/W1C/H) CSR FIFO overflow error. DPI can store up to 16 CSR requests, and the FIFO overflows if
                                                                 that number is exceeded. */
        uint64_t reserved_2_7          : 6;
        uint64_t dmadbo                : 8;  /**< [ 15:  8](R/W1C/H) Doorbell overflow error. DPI has a 32-bit counter for each request queue's outstanding
                                                                 doorbell counts. A bit is set when the corresponding doorbell count overflows. */
        uint64_t req_badadr            : 1;  /**< [ 16: 16](R/W1C/H) Fetch with bad pointer error. This bit is set when DPI forms an instruction fetch to the
                                                                 NULL pointer. */
        uint64_t req_badlen            : 1;  /**< [ 17: 17](R/W1C/H) Fetch with length zero error. This bit is set when DPI forms an instruction fetch with
                                                                 length of zero. */
        uint64_t req_ovrflw            : 1;  /**< [ 18: 18](R/W1C/H) Instruction FIFO overflow error. This bit is set when the instruction FIFO overflows. */
        uint64_t req_undflw            : 1;  /**< [ 19: 19](R/W1C/H) Instruction FIFO underflow error. This bit is set when the instruction FIFO underflows. */
        uint64_t req_anull             : 1;  /**< [ 20: 20](R/W1C/H) Instruction bad error. This bit is set when a fetched instruction word was 0x0. */
        uint64_t req_inull             : 1;  /**< [ 21: 21](R/W1C/H) Interrupt should be ignored.
                                                                 Internal:
                                                                 The interrupt means that the DPI unit
                                                                 received fill data in which one or more or the 64-bit instruction words was all
                                                                 0's. In previous DPI implementations, there was never a case in which a valid
                                                                 instruction stream would have all 0's. In the new dual-instruction word scheme,
                                                                 the 2nd word could be zero. For example, if no completion operation is requested
                                                                 on the instruction and both PTR and DEALLOCV are zero. */
        uint64_t req_badfil            : 1;  /**< [ 22: 22](R/W1C/H) Unexpected fill error. This bit is set when an instruction fill is received when there is
                                                                 no outstanding request. */
        uint64_t reserved_23_63        : 41;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_int_reg_s cn; */
} bdk_dpix_int_reg_t;

static inline uint64_t BDK_DPIX_INT_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_INT_REG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004168ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004168ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_INT_REG", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_INT_REG(a) bdk_dpix_int_reg_t
#define bustype_BDK_DPIX_INT_REG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_INT_REG(a) "DPIX_INT_REG"
#define device_bar_BDK_DPIX_INT_REG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_INT_REG(a) (a)
#define arguments_BDK_DPIX_INT_REG(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_int_reg_w1s
 *
 * DPI Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_int_reg_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_23_63        : 41;
        uint64_t req_badfil            : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets DPI(0)_INT_REG[REQ_BADFIL]. */
        uint64_t req_inull             : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets DPI(0)_INT_REG[REQ_INULL].
                                                                 Internal:
                                                                 The interrupt means that the DPI unit
                                                                 received fill data in which one or more or the 64-bit instruction words was all
                                                                 0's. In previous DPI implementations, there was never a case in which a valid
                                                                 instruction stream would have all 0's. In the new dual-instruction word scheme,
                                                                 the 2nd word could be zero. For example, if no completion operation is requested
                                                                 on the instruction and both PTR and DEALLOCV are zero. */
        uint64_t req_anull             : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets DPI(0)_INT_REG[REQ_ANULL]. */
        uint64_t req_undflw            : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets DPI(0)_INT_REG[REQ_UNDFLW]. */
        uint64_t req_ovrflw            : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets DPI(0)_INT_REG[REQ_OVRFLW]. */
        uint64_t req_badlen            : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets DPI(0)_INT_REG[REQ_BADLEN]. */
        uint64_t req_badadr            : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets DPI(0)_INT_REG[REQ_BADADR]. */
        uint64_t dmadbo                : 8;  /**< [ 15:  8](R/W1S/H) Reads or sets DPI(0)_INT_REG[DMADBO]. */
        uint64_t reserved_2_7          : 6;
        uint64_t nfovr                 : 1;  /**< [  1:  1](R/W1S/H) Reads or sets DPI(0)_INT_REG[NFOVR]. */
        uint64_t nderr                 : 1;  /**< [  0:  0](R/W1S/H) Reads or sets DPI(0)_INT_REG[NDERR]. */
#else /* Word 0 - Little Endian */
        uint64_t nderr                 : 1;  /**< [  0:  0](R/W1S/H) Reads or sets DPI(0)_INT_REG[NDERR]. */
        uint64_t nfovr                 : 1;  /**< [  1:  1](R/W1S/H) Reads or sets DPI(0)_INT_REG[NFOVR]. */
        uint64_t reserved_2_7          : 6;
        uint64_t dmadbo                : 8;  /**< [ 15:  8](R/W1S/H) Reads or sets DPI(0)_INT_REG[DMADBO]. */
        uint64_t req_badadr            : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets DPI(0)_INT_REG[REQ_BADADR]. */
        uint64_t req_badlen            : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets DPI(0)_INT_REG[REQ_BADLEN]. */
        uint64_t req_ovrflw            : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets DPI(0)_INT_REG[REQ_OVRFLW]. */
        uint64_t req_undflw            : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets DPI(0)_INT_REG[REQ_UNDFLW]. */
        uint64_t req_anull             : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets DPI(0)_INT_REG[REQ_ANULL]. */
        uint64_t req_inull             : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets DPI(0)_INT_REG[REQ_INULL].
                                                                 Internal:
                                                                 The interrupt means that the DPI unit
                                                                 received fill data in which one or more or the 64-bit instruction words was all
                                                                 0's. In previous DPI implementations, there was never a case in which a valid
                                                                 instruction stream would have all 0's. In the new dual-instruction word scheme,
                                                                 the 2nd word could be zero. For example, if no completion operation is requested
                                                                 on the instruction and both PTR and DEALLOCV are zero. */
        uint64_t req_badfil            : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets DPI(0)_INT_REG[REQ_BADFIL]. */
        uint64_t reserved_23_63        : 41;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_int_reg_w1s_s cn; */
} bdk_dpix_int_reg_w1s_t;

static inline uint64_t BDK_DPIX_INT_REG_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_INT_REG_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004170ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004170ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_INT_REG_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_INT_REG_W1S(a) bdk_dpix_int_reg_w1s_t
#define bustype_BDK_DPIX_INT_REG_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_INT_REG_W1S(a) "DPIX_INT_REG_W1S"
#define device_bar_BDK_DPIX_INT_REG_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_INT_REG_W1S(a) (a)
#define arguments_BDK_DPIX_INT_REG_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_msix_pba#
 *
 * PKI MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the DPI_INT_VEC_E
 * enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated DPI_MSIX_VEC()_CTL, enumerated by
                                                                 DPI_INT_VEC_E. Bits that have no associated DPI_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated DPI_MSIX_VEC()_CTL, enumerated by
                                                                 DPI_INT_VEC_E. Bits that have no associated DPI_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_msix_pbax_s cn; */
} bdk_dpix_msix_pbax_t;

static inline uint64_t BDK_DPIX_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=1)))
        return 0x86e0010f0000ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=1)))
        return 0x86e0010f0000ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DPIX_MSIX_PBAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_MSIX_PBAX(a,b) bdk_dpix_msix_pbax_t
#define bustype_BDK_DPIX_MSIX_PBAX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_MSIX_PBAX(a,b) "DPIX_MSIX_PBAX"
#define device_bar_BDK_DPIX_MSIX_PBAX(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_DPIX_MSIX_PBAX(a,b) (a)
#define arguments_BDK_DPIX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_msix_vec#_addr
 *
 * DPI MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the DPI_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 =  This vector's DPI_MSIX_VEC()_ADDR, DPI_MSIX_VEC()_CTL, and corresponding
                                                                 bit of DPI_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_PKI_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 =  This vector's DPI_MSIX_VEC()_ADDR, DPI_MSIX_VEC()_CTL, and corresponding
                                                                 bit of DPI_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_PKI_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_msix_vecx_addr_s cn; */
} bdk_dpix_msix_vecx_addr_t;

static inline uint64_t BDK_DPIX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=66)))
        return 0x86e001000000ll + 0x10000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=66)))
        return 0x86e001000000ll + 0x10000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x7f);
    __bdk_csr_fatal("DPIX_MSIX_VECX_ADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_MSIX_VECX_ADDR(a,b) bdk_dpix_msix_vecx_addr_t
#define bustype_BDK_DPIX_MSIX_VECX_ADDR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_MSIX_VECX_ADDR(a,b) "DPIX_MSIX_VECX_ADDR"
#define device_bar_BDK_DPIX_MSIX_VECX_ADDR(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_DPIX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_BDK_DPIX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_msix_vec#_ctl
 *
 * DPI MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the DPI_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_msix_vecx_ctl_s
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
    /* struct bdk_dpix_msix_vecx_ctl_s cn; */
} bdk_dpix_msix_vecx_ctl_t;

static inline uint64_t BDK_DPIX_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=66)))
        return 0x86e001000008ll + 0x10000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=66)))
        return 0x86e001000008ll + 0x10000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x7f);
    __bdk_csr_fatal("DPIX_MSIX_VECX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_MSIX_VECX_CTL(a,b) bdk_dpix_msix_vecx_ctl_t
#define bustype_BDK_DPIX_MSIX_VECX_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_MSIX_VECX_CTL(a,b) "DPIX_MSIX_VECX_CTL"
#define device_bar_BDK_DPIX_MSIX_VECX_CTL(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_DPIX_MSIX_VECX_CTL(a,b) (a)
#define arguments_BDK_DPIX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_ncb#_cfg
 *
 * DPI IOI Configuration Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_ncbx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t molr                  : 6;  /**< [  5:  0](R/W) Max outstanding load requests. Limits the number of outstanding load requests on the I/O
                                                                 Interconnect. This value can range from 1 to 32. Setting a value of 0 halts all read
                                                                 traffic to the I/O Interconnect. There are no restrictions on when this value can be
                                                                 changed. */
#else /* Word 0 - Little Endian */
        uint64_t molr                  : 6;  /**< [  5:  0](R/W) Max outstanding load requests. Limits the number of outstanding load requests on the I/O
                                                                 Interconnect. This value can range from 1 to 32. Setting a value of 0 halts all read
                                                                 traffic to the I/O Interconnect. There are no restrictions on when this value can be
                                                                 changed. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_ncbx_cfg_s cn; */
} bdk_dpix_ncbx_cfg_t;

static inline uint64_t BDK_DPIX_NCBX_CFG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_NCBX_CFG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b==0)))
        return 0x86e0000040a0ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b==0)))
        return 0x86e0000040a0ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("DPIX_NCBX_CFG", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_NCBX_CFG(a,b) bdk_dpix_ncbx_cfg_t
#define bustype_BDK_DPIX_NCBX_CFG(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_NCBX_CFG(a,b) "DPIX_NCBX_CFG"
#define device_bar_BDK_DPIX_NCBX_CFG(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_NCBX_CFG(a,b) (a)
#define arguments_BDK_DPIX_NCBX_CFG(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_pkt_err_rsp
 *
 * DPI Packet Error Response Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_pkt_err_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t pkterr                : 1;  /**< [  0:  0](R/W1C/H) Indicates that an ErrorResponse was received from the I/O subsystem. */
#else /* Word 0 - Little Endian */
        uint64_t pkterr                : 1;  /**< [  0:  0](R/W1C/H) Indicates that an ErrorResponse was received from the I/O subsystem. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_pkt_err_rsp_s cn; */
} bdk_dpix_pkt_err_rsp_t;

static inline uint64_t BDK_DPIX_PKT_ERR_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_PKT_ERR_RSP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004098ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004098ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_PKT_ERR_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_PKT_ERR_RSP(a) bdk_dpix_pkt_err_rsp_t
#define bustype_BDK_DPIX_PKT_ERR_RSP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_PKT_ERR_RSP(a) "DPIX_PKT_ERR_RSP"
#define device_bar_BDK_DPIX_PKT_ERR_RSP(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_PKT_ERR_RSP(a) (a)
#define arguments_BDK_DPIX_PKT_ERR_RSP(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_req_err_rsp
 *
 * DPI Instruction Queue ErrorResponse Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_req_err_rsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t qerr                  : 8;  /**< [  7:  0](R/W1C/H) Indicates which instruction queue received an ErrorResponse from the I/O subsystem.
                                                                 Software must clear the bit before the corresponding instruction queue will continue
                                                                 processing instructions if DPI()_REQ_ERR_RSP_EN[EN] is set. */
#else /* Word 0 - Little Endian */
        uint64_t qerr                  : 8;  /**< [  7:  0](R/W1C/H) Indicates which instruction queue received an ErrorResponse from the I/O subsystem.
                                                                 Software must clear the bit before the corresponding instruction queue will continue
                                                                 processing instructions if DPI()_REQ_ERR_RSP_EN[EN] is set. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_req_err_rsp_s cn; */
} bdk_dpix_req_err_rsp_t;

static inline uint64_t BDK_DPIX_REQ_ERR_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_REQ_ERR_RSP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004078ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004078ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_REQ_ERR_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_REQ_ERR_RSP(a) bdk_dpix_req_err_rsp_t
#define bustype_BDK_DPIX_REQ_ERR_RSP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_REQ_ERR_RSP(a) "DPIX_REQ_ERR_RSP"
#define device_bar_BDK_DPIX_REQ_ERR_RSP(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_REQ_ERR_RSP(a) (a)
#define arguments_BDK_DPIX_REQ_ERR_RSP(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_req_err_rsp_en
 *
 * DPI Instruction Queue ErrorResponse Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_req_err_rsp_en_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t en                    : 8;  /**< [  7:  0](R/W) Indicates which instruction queues should stop dispatching instructions when an
                                                                 ErrorResponse is received from the I/O subsystem. */
#else /* Word 0 - Little Endian */
        uint64_t en                    : 8;  /**< [  7:  0](R/W) Indicates which instruction queues should stop dispatching instructions when an
                                                                 ErrorResponse is received from the I/O subsystem. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_req_err_rsp_en_s cn; */
} bdk_dpix_req_err_rsp_en_t;

static inline uint64_t BDK_DPIX_REQ_ERR_RSP_EN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_REQ_ERR_RSP_EN(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004088ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004088ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_REQ_ERR_RSP_EN", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_REQ_ERR_RSP_EN(a) bdk_dpix_req_err_rsp_en_t
#define bustype_BDK_DPIX_REQ_ERR_RSP_EN(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_REQ_ERR_RSP_EN(a) "DPIX_REQ_ERR_RSP_EN"
#define device_bar_BDK_DPIX_REQ_ERR_RSP_EN(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_REQ_ERR_RSP_EN(a) (a)
#define arguments_BDK_DPIX_REQ_ERR_RSP_EN(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_req_err_rst
 *
 * INTERNAL: DPI Instruction Queue Reset Error Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_req_err_rst_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t qerr                  : 8;  /**< [  7:  0](RAZ) Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t qerr                  : 8;  /**< [  7:  0](RAZ) Reserved. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_req_err_rst_s cn; */
} bdk_dpix_req_err_rst_t;

static inline uint64_t BDK_DPIX_REQ_ERR_RST(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_REQ_ERR_RST(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004080ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004080ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_REQ_ERR_RST", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_REQ_ERR_RST(a) bdk_dpix_req_err_rst_t
#define bustype_BDK_DPIX_REQ_ERR_RST(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_REQ_ERR_RST(a) "DPIX_REQ_ERR_RST"
#define device_bar_BDK_DPIX_REQ_ERR_RST(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_REQ_ERR_RST(a) (a)
#define arguments_BDK_DPIX_REQ_ERR_RST(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_req_err_rst_en
 *
 * INTERNAL: DPI Instruction Queue Reset Error Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_req_err_rst_en_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t en                    : 8;  /**< [  7:  0](RAZ) Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t en                    : 8;  /**< [  7:  0](RAZ) Reserved. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_req_err_rst_en_s cn; */
} bdk_dpix_req_err_rst_en_t;

static inline uint64_t BDK_DPIX_REQ_ERR_RST_EN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_REQ_ERR_RST_EN(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004090ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004090ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_REQ_ERR_RST_EN", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_REQ_ERR_RST_EN(a) bdk_dpix_req_err_rst_en_t
#define bustype_BDK_DPIX_REQ_ERR_RST_EN(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_REQ_ERR_RST_EN(a) "DPIX_REQ_ERR_RST_EN"
#define device_bar_BDK_DPIX_REQ_ERR_RST_EN(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_REQ_ERR_RST_EN(a) (a)
#define arguments_BDK_DPIX_REQ_ERR_RST_EN(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_req_gbl_en
 *
 * DPI Request Global Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_req_gbl_en_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t qen                   : 8;  /**< [  7:  0](R/W) Indicates which instruction queues are enabled, and can dispatch instructions to a
                                                                 requesting engine. */
#else /* Word 0 - Little Endian */
        uint64_t qen                   : 8;  /**< [  7:  0](R/W) Indicates which instruction queues are enabled, and can dispatch instructions to a
                                                                 requesting engine. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_req_gbl_en_s cn; */
} bdk_dpix_req_gbl_en_t;

static inline uint64_t BDK_DPIX_REQ_GBL_EN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_REQ_GBL_EN(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004070ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004070ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_REQ_GBL_EN", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_REQ_GBL_EN(a) bdk_dpix_req_gbl_en_t
#define bustype_BDK_DPIX_REQ_GBL_EN(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_REQ_GBL_EN(a) "DPIX_REQ_GBL_EN"
#define device_bar_BDK_DPIX_REQ_GBL_EN(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_REQ_GBL_EN(a) (a)
#define arguments_BDK_DPIX_REQ_GBL_EN(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_sbe_int
 *
 * DPI ECC SBE Interrupt Register
 * This register contains ECC Single Bit error interrupt summary bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_sbe_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t rdb_sbe               : 1;  /**< [  0:  0](R/W1C/H) Set when a single-bit error is detected in the RDB RAM. */
#else /* Word 0 - Little Endian */
        uint64_t rdb_sbe               : 1;  /**< [  0:  0](R/W1C/H) Set when a single-bit error is detected in the RDB RAM. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_sbe_int_s cn; */
} bdk_dpix_sbe_int_t;

static inline uint64_t BDK_DPIX_SBE_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_SBE_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004188ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004188ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_SBE_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_SBE_INT(a) bdk_dpix_sbe_int_t
#define bustype_BDK_DPIX_SBE_INT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_SBE_INT(a) "DPIX_SBE_INT"
#define device_bar_BDK_DPIX_SBE_INT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_SBE_INT(a) (a)
#define arguments_BDK_DPIX_SBE_INT(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_sbe_int_ena_w1c
 *
 * DPI SBE Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_sbe_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t rdb_sbe               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for DPI(0)_SBE_INT[RDB_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rdb_sbe               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for DPI(0)_SBE_INT[RDB_SBE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_sbe_int_ena_w1c_s cn; */
} bdk_dpix_sbe_int_ena_w1c_t;

static inline uint64_t BDK_DPIX_SBE_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_SBE_INT_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004198ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004198ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_SBE_INT_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_SBE_INT_ENA_W1C(a) bdk_dpix_sbe_int_ena_w1c_t
#define bustype_BDK_DPIX_SBE_INT_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_SBE_INT_ENA_W1C(a) "DPIX_SBE_INT_ENA_W1C"
#define device_bar_BDK_DPIX_SBE_INT_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_SBE_INT_ENA_W1C(a) (a)
#define arguments_BDK_DPIX_SBE_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_sbe_int_ena_w1s
 *
 * DPI SBE Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_sbe_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t rdb_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for DPI(0)_SBE_INT[RDB_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rdb_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for DPI(0)_SBE_INT[RDB_SBE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_sbe_int_ena_w1s_s cn; */
} bdk_dpix_sbe_int_ena_w1s_t;

static inline uint64_t BDK_DPIX_SBE_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_SBE_INT_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e0000041a0ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e0000041a0ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_SBE_INT_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_SBE_INT_ENA_W1S(a) bdk_dpix_sbe_int_ena_w1s_t
#define bustype_BDK_DPIX_SBE_INT_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_SBE_INT_ENA_W1S(a) "DPIX_SBE_INT_ENA_W1S"
#define device_bar_BDK_DPIX_SBE_INT_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_SBE_INT_ENA_W1S(a) (a)
#define arguments_BDK_DPIX_SBE_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_sbe_int_w1s
 *
 * DPI SBE Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_sbe_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t rdb_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets DPI(0)_SBE_INT[RDB_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rdb_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets DPI(0)_SBE_INT[RDB_SBE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_sbe_int_w1s_s cn; */
} bdk_dpix_sbe_int_w1s_t;

static inline uint64_t BDK_DPIX_SBE_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_SBE_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000004190ll + 0x10000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x86e000004190ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_SBE_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_SBE_INT_W1S(a) bdk_dpix_sbe_int_w1s_t
#define bustype_BDK_DPIX_SBE_INT_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_SBE_INT_W1S(a) "DPIX_SBE_INT_W1S"
#define device_bar_BDK_DPIX_SBE_INT_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_SBE_INT_W1S(a) (a)
#define arguments_BDK_DPIX_SBE_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_sli_prt#_cfg
 *
 * DPI SLI Port Configuration Register
 * This register configures the max read request size, max payload size, and max number of SLI
 * tags in use.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_sli_prtx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_25_63        : 39;
        uint64_t halt                  : 1;  /**< [ 24: 24](RO/H) When set, HALT indicates that the MAC has detected a reset condition. No further
                                                                 instructions that reference the MAC from any instruction queue will be issued until the
                                                                 MAC comes out of reset and HALT is cleared in SLI_CTL_PORT()[DIS_PORT]. */
        uint64_t reserved_21_23        : 3;
        uint64_t qlm_cfg               : 1;  /**< [ 20: 20](RO/H) Read only copy of the QLM CFG pin.
                                                                 0 = MAC is DPI.
                                                                 1 = Reserved.

                                                                 Since QLM_CFG is simply a copy of the QLM CFG pins, it could reflect values that are not
                                                                 normal for DMA or packet operations. QLM_CFG does not indicate if a port is disabled.
                                                                 GSER()_CFG can be used for more complete QLM configuration information. */
        uint64_t reserved_15_19        : 5;
        uint64_t molr                  : 7;  /**< [ 14:  8](R/W) Maximum outstanding load requests. Limits the number of outstanding load requests on the
                                                                 port by restricting the number of tags used by the SLI to track load responses. This value
                                                                 can range from 1 to 64 (maximum of 32 if port not configured for 8 lanes). Setting MOLR
                                                                 to a value of 0 halts all read traffic to the port. There are no restrictions on when this
                                                                 value can be changed. */
        uint64_t mps_lim               : 1;  /**< [  7:  7](R/W) MAC memory space write requests cannot cross the (naturally-aligned) MPS boundary.
                                                                 When clear, DPI is allowed to issue a MAC memory- space read that crosses the naturally-
                                                                 aligned boundary of size defined by MPS. (DPI will still only cross the boundary when it
                                                                 would eliminate a write by doing so.)

                                                                 When set, DPI will never issue a MAC memory space write that crosses the naturally-aligned
                                                                 boundary of size defined by MPS. */
        uint64_t mps                   : 3;  /**< [  6:  4](R/W) Maximum payload size.
                                                                 0x0 = 128B.
                                                                 0x1 = 256B.

                                                                 Larger sizes are not supported.

                                                                 The MPS size must not exceed the size selected by PCIE*_CFG030[MPS]. */
        uint64_t mrrs_lim              : 1;  /**< [  3:  3](R/W) MAC memory space read requests cannot cross the (naturally-aligned) MRRS boundary.

                                                                 When clear, DPI is allowed to issue a MAC memory-space read that crosses the naturally-
                                                                 aligned boundary of size defined by MRRS. (DPI will still only cross the boundary when it
                                                                 would eliminate a read by doing so.)

                                                                 When set, DPI will never issue a MAC memory space read that crosses the naturally-aligned
                                                                 boundary of size defined by MRRS. */
        uint64_t mrrs                  : 3;  /**< [  2:  0](R/W) Maximum read-request size.
                                                                 0x0 = 128B.
                                                                 0x1 = 256B.
                                                                 0x2 = 512B.
                                                                 0x3 = 1024B.

                                                                 Larger sizes are not supported.

                                                                 The MRRS size must not exceed the size selected by PCIE*_CFG030[MRRS]. */
#else /* Word 0 - Little Endian */
        uint64_t mrrs                  : 3;  /**< [  2:  0](R/W) Maximum read-request size.
                                                                 0x0 = 128B.
                                                                 0x1 = 256B.
                                                                 0x2 = 512B.
                                                                 0x3 = 1024B.

                                                                 Larger sizes are not supported.

                                                                 The MRRS size must not exceed the size selected by PCIE*_CFG030[MRRS]. */
        uint64_t mrrs_lim              : 1;  /**< [  3:  3](R/W) MAC memory space read requests cannot cross the (naturally-aligned) MRRS boundary.

                                                                 When clear, DPI is allowed to issue a MAC memory-space read that crosses the naturally-
                                                                 aligned boundary of size defined by MRRS. (DPI will still only cross the boundary when it
                                                                 would eliminate a read by doing so.)

                                                                 When set, DPI will never issue a MAC memory space read that crosses the naturally-aligned
                                                                 boundary of size defined by MRRS. */
        uint64_t mps                   : 3;  /**< [  6:  4](R/W) Maximum payload size.
                                                                 0x0 = 128B.
                                                                 0x1 = 256B.

                                                                 Larger sizes are not supported.

                                                                 The MPS size must not exceed the size selected by PCIE*_CFG030[MPS]. */
        uint64_t mps_lim               : 1;  /**< [  7:  7](R/W) MAC memory space write requests cannot cross the (naturally-aligned) MPS boundary.
                                                                 When clear, DPI is allowed to issue a MAC memory- space read that crosses the naturally-
                                                                 aligned boundary of size defined by MPS. (DPI will still only cross the boundary when it
                                                                 would eliminate a write by doing so.)

                                                                 When set, DPI will never issue a MAC memory space write that crosses the naturally-aligned
                                                                 boundary of size defined by MPS. */
        uint64_t molr                  : 7;  /**< [ 14:  8](R/W) Maximum outstanding load requests. Limits the number of outstanding load requests on the
                                                                 port by restricting the number of tags used by the SLI to track load responses. This value
                                                                 can range from 1 to 64 (maximum of 32 if port not configured for 8 lanes). Setting MOLR
                                                                 to a value of 0 halts all read traffic to the port. There are no restrictions on when this
                                                                 value can be changed. */
        uint64_t reserved_15_19        : 5;
        uint64_t qlm_cfg               : 1;  /**< [ 20: 20](RO/H) Read only copy of the QLM CFG pin.
                                                                 0 = MAC is DPI.
                                                                 1 = Reserved.

                                                                 Since QLM_CFG is simply a copy of the QLM CFG pins, it could reflect values that are not
                                                                 normal for DMA or packet operations. QLM_CFG does not indicate if a port is disabled.
                                                                 GSER()_CFG can be used for more complete QLM configuration information. */
        uint64_t reserved_21_23        : 3;
        uint64_t halt                  : 1;  /**< [ 24: 24](RO/H) When set, HALT indicates that the MAC has detected a reset condition. No further
                                                                 instructions that reference the MAC from any instruction queue will be issued until the
                                                                 MAC comes out of reset and HALT is cleared in SLI_CTL_PORT()[DIS_PORT]. */
        uint64_t reserved_25_63        : 39;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_sli_prtx_cfg_s cn; */
} bdk_dpix_sli_prtx_cfg_t;

static inline uint64_t BDK_DPIX_SLI_PRTX_CFG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_SLI_PRTX_CFG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=3)))
        return 0x86e000004100ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=3)))
        return 0x86e000004100ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3);
    __bdk_csr_fatal("DPIX_SLI_PRTX_CFG", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_SLI_PRTX_CFG(a,b) bdk_dpix_sli_prtx_cfg_t
#define bustype_BDK_DPIX_SLI_PRTX_CFG(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_SLI_PRTX_CFG(a,b) "DPIX_SLI_PRTX_CFG"
#define device_bar_BDK_DPIX_SLI_PRTX_CFG(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_SLI_PRTX_CFG(a,b) (a)
#define arguments_BDK_DPIX_SLI_PRTX_CFG(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_sli_prt#_err
 *
 * DPI SLI Port Error Address Registers
 * This register logs the address associated with the reported SLI error response.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_sli_prtx_err_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t addr                  : 61; /**< [ 63:  3](RO/H) Address of the failed load request. Address is locked along with the
                                                                 DPI()_SLI_PRT()_ERR_INFO register. See the
                                                                 DPI()_SLI_PRT()_ERR_INFO[LOCK] description for further information. */
        uint64_t reserved_0_2          : 3;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_2          : 3;
        uint64_t addr                  : 61; /**< [ 63:  3](RO/H) Address of the failed load request. Address is locked along with the
                                                                 DPI()_SLI_PRT()_ERR_INFO register. See the
                                                                 DPI()_SLI_PRT()_ERR_INFO[LOCK] description for further information. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_sli_prtx_err_s cn; */
} bdk_dpix_sli_prtx_err_t;

static inline uint64_t BDK_DPIX_SLI_PRTX_ERR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_SLI_PRTX_ERR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=3)))
        return 0x86e000004120ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=3)))
        return 0x86e000004120ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3);
    __bdk_csr_fatal("DPIX_SLI_PRTX_ERR", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_SLI_PRTX_ERR(a,b) bdk_dpix_sli_prtx_err_t
#define bustype_BDK_DPIX_SLI_PRTX_ERR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_SLI_PRTX_ERR(a,b) "DPIX_SLI_PRTX_ERR"
#define device_bar_BDK_DPIX_SLI_PRTX_ERR(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_SLI_PRTX_ERR(a,b) (a)
#define arguments_BDK_DPIX_SLI_PRTX_ERR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_sli_prt#_err_info
 *
 * DPI SLI MAC Port Error Info Registers
 * This register logs information associated with the reported SLI error response.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_sli_prtx_err_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t pvf                   : 16; /**< [ 31: 16](RO/H) Physical/virtual function that caused the ErrorResponse. DPI_DMA_FUNC_SEL_S format. */
        uint64_t reserved_9_15         : 7;
        uint64_t lock                  : 1;  /**< [  8:  8](RO/H) DPI()_SLI_PRT()_ERR and DPI()_SLI_PRT()_ERR_INFO have captured and locked contents.
                                                                 When CNXXXX first detects an ErrorResponse, the TYPE, REQQ, and ADDR of the error is saved
                                                                 and an internal lock state is set so the data associated with the initial error is
                                                                 preserved.

                                                                 Subsequent ErrorResponses will optionally raise an interrupt, but will not modify
                                                                 [TYPE], [REQQ], nor [ADDR] until the internal lock state is cleared.

                                                                 Software can clear the internal lock state by writing a 1 to the appropriate bit in either
                                                                 DPI()_REQ_ERR_RSP or DPI()_PKT_ERR_RSP depending on [TYPE]. Once the internal lock
                                                                 state is cleared, the next ErrorResponse will set [TYPE], [REQQ], nor [ADDR] for the new
                                                                 transaction. */
        uint64_t reserved_5_7          : 3;
        uint64_t type                  : 1;  /**< [  4:  4](RO/H) Type of transaction that caused the ErrorResponse.
                                                                 0 = DMA Instruction.
                                                                 1 = PKT Instruction. */
        uint64_t reserved_3            : 1;
        uint64_t reqq                  : 3;  /**< [  2:  0](RO/H) Request queue that made the failed load request. */
#else /* Word 0 - Little Endian */
        uint64_t reqq                  : 3;  /**< [  2:  0](RO/H) Request queue that made the failed load request. */
        uint64_t reserved_3            : 1;
        uint64_t type                  : 1;  /**< [  4:  4](RO/H) Type of transaction that caused the ErrorResponse.
                                                                 0 = DMA Instruction.
                                                                 1 = PKT Instruction. */
        uint64_t reserved_5_7          : 3;
        uint64_t lock                  : 1;  /**< [  8:  8](RO/H) DPI()_SLI_PRT()_ERR and DPI()_SLI_PRT()_ERR_INFO have captured and locked contents.
                                                                 When CNXXXX first detects an ErrorResponse, the TYPE, REQQ, and ADDR of the error is saved
                                                                 and an internal lock state is set so the data associated with the initial error is
                                                                 preserved.

                                                                 Subsequent ErrorResponses will optionally raise an interrupt, but will not modify
                                                                 [TYPE], [REQQ], nor [ADDR] until the internal lock state is cleared.

                                                                 Software can clear the internal lock state by writing a 1 to the appropriate bit in either
                                                                 DPI()_REQ_ERR_RSP or DPI()_PKT_ERR_RSP depending on [TYPE]. Once the internal lock
                                                                 state is cleared, the next ErrorResponse will set [TYPE], [REQQ], nor [ADDR] for the new
                                                                 transaction. */
        uint64_t reserved_9_15         : 7;
        uint64_t pvf                   : 16; /**< [ 31: 16](RO/H) Physical/virtual function that caused the ErrorResponse. DPI_DMA_FUNC_SEL_S format. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_sli_prtx_err_info_s cn; */
} bdk_dpix_sli_prtx_err_info_t;

static inline uint64_t BDK_DPIX_SLI_PRTX_ERR_INFO(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_SLI_PRTX_ERR_INFO(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=3)))
        return 0x86e000004140ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=3)))
        return 0x86e000004140ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3);
    __bdk_csr_fatal("DPIX_SLI_PRTX_ERR_INFO", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_SLI_PRTX_ERR_INFO(a,b) bdk_dpix_sli_prtx_err_info_t
#define bustype_BDK_DPIX_SLI_PRTX_ERR_INFO(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_SLI_PRTX_ERR_INFO(a,b) "DPIX_SLI_PRTX_ERR_INFO"
#define device_bar_BDK_DPIX_SLI_PRTX_ERR_INFO(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_DPIX_SLI_PRTX_ERR_INFO(a,b) (a)
#define arguments_BDK_DPIX_SLI_PRTX_ERR_INFO(a,b) (a),(b),-1,-1

#endif /* __BDK_CSRS_DPI_H__ */
