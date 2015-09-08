#ifndef __BDK_CSRS_DPI_H__
#define __BDK_CSRS_DPI_H__
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
 * Cavium DPI.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration dpi_cs_e
 *
 * DPI Completion Status Enumeration
 * Enumerates the completion status return values.
 */
#define BDK_DPI_CS_E_ERRRSP (3) /**< Error response from read source MAC. */
#define BDK_DPI_CS_E_NOERR (0) /**< No error detected on instruction. */
#define BDK_DPI_CS_E_RDRST (1) /**< MAC reset detected on read source MAC. */
#define BDK_DPI_CS_E_WRRST (2) /**< MAC reset detected on write destination MAC. */

/**
 * Enumeration dpi_hdr_pt_e
 *
 * DPI Header Pointer Type Enumeration
 * Enumerates the pointer type in DPI_DMA_INSTR_HDR_S[PT].
 */
#define BDK_DPI_HDR_PT_E_CNT (3) /**< Increment a CSR Counter after completing the DPI DMA instruction.
                                       
                                       DPI_DMA_INSTR_HDR_S[PTR]-1 selects a DPI()_DMA_PP()_CNT[CNT] CSR
                                       that DPI increments by one on completion with CNT, which can cause
                                       an interrupt. DPI_DMA_INSTR_HDR_S[PTR]-1 must select an existing
                                       DPI()_DMA_PP()_CNT[CNT] with CNT. */
#define BDK_DPI_HDR_PT_E_WQP (2) /**< Work-queue Pointer add after completing the DPI DMA instruction.
                                       
                                       DPI_DMA_INSTR_HDR_S[PTR<2:0>] is a DPI_HDR_PT_WQP_E with WQP, selecting
                                       if/how DPI performs a DPI_CS_E completion status byte write before
                                       the WQE add. The remaining DPI_DMA_INSTR_HDR_S[PTR] bits are a (64-bit word,
                                       not byte) work queue entry L2/DRAM pointer for SSO. DPI adds the
                                       WQE with tag type DPI_DMA_INSTR_HDR_S[TT] into SSO group
                                       DPI_DMA_INSTR_HDR_S[GROUP] after completing the DPI DMA instruction
                                       and its completion status byte write (if any). DPI_DMA_INSTR_HDR_S[PTR]
                                       must be >= 128 with WQP. */
#define BDK_DPI_HDR_PT_E_ZBW_CA (0) /**< Byte-write with cache allocate after completing the DPI DMA instruction
                                       (if DPI_DMA_INSTR_HDR_S[PTR] != 0).
                                       
                                       DPI_DMA_INSTR_HDR_S[PTR] indicates the byte in L2/DRAM to write, and
                                       DPI()_DMA_CONTROL[B0_LEND] selects the endianness of DPI_DMA_INSTR_HDR_S[PTR]
                                       with ZBW_CA. DPI_DMA_INSTR_HDR_S[PTR] must be >= 128 or zero with ZBW_CA.
                                       When DPI_DMA_INSTR_HDR_S[PTR] is zero with ZBW_CA, no zero-byte-write occurs.
                                       
                                       When DPI()_DMA_CONTROL[ZBWCSEN] is clear, DPI always writes DPI_CS_E::NOERR
                                       (i.e. zero) to the selected byte, regardless whether the DPI DMA instruction
                                       encounters an error or not. When DPI()_DMA_CONTROL[ZBWCSEN] is set, DPI
                                       writes the appropriate DPI_CS_E status for the instruction to
                                       the selected byte. */
#define BDK_DPI_HDR_PT_E_ZBW_NC (1) /**< Byte-write with no cache allocate after completing the DPI DMA instruction
                                       (if DPI_DMA_INSTR_HDR_S[PTR] != 0).
                                       
                                       DPI_DMA_INSTR_HDR_S[PTR] indicates the byte in L2/DRAM to write, and
                                       DPI()_DMA_CONTROL[B0_LEND] selects the endianness of DPI_DMA_INSTR_HDR_S[PTR]
                                       with ZBW_NC. DPI_DMA_INSTR_HDR_S[PTR] must be >= 128 or zero with ZBW_NC.
                                       When DPI_DMA_INSTR_HDR_S[PTR] is zero with ZBW_NC, no zero-byte-write occurs.
                                       
                                       When DPI()_DMA_CONTROL[ZBWCSEN] is clear, DPI always writes DPI_CS_E::NOERR
                                       (i.e. zero) to the selected byte, regardless whether the DPI DMA instruction
                                       encounters an error or not. When DPI()_DMA_CONTROL[ZBWCSEN] is set, DPI
                                       writes the appropriate DPI_CS_E status for the instruction to the
                                       selected byte. */

/**
 * Enumeration dpi_hdr_pt_wqp_e
 *
 * DPI DMA Instruction Header Work Queue Pointer <2:0> Enumeration
 *
 * The DPI_DMA_INSTR_HDR_S[PTR<2:0>] encoding when DPI_DMA_INSTR_HDR_S[PT] is
 * DPI_HDR_PT_E::WQP.
 */
#define BDK_DPI_HDR_PT_WQP_E_NOSTATUS (0) /**< No status write. DPI will not write the DPI_CS_E status of the instruction into
                                       the WQE before submitting the work. */
#define BDK_DPI_HDR_PT_WQP_E_STATUSCA (1) /**< Status write with cache allocate. If the DPI_CS_E status of the instruction is
                                       other than DPI_CS_E::NOERR (i.e. zero), then DPI will write the DPI_CS_E
                                       status of the instruction into the WQE (at offset DPI()_DMA_CONTROL[WQECSOFF],
                                       with cache allocation on a miss) before submitting the work.
                                       
                                       DPI()_DMA_CONTROL[WQECSDIS]!=0 or DPI()_DMA_CONTROL[WQECSMODE]!=0 can give
                                       other behavior. */
#define BDK_DPI_HDR_PT_WQP_E_STATUSNC (3) /**< Status write with no cache allocate. If the DPI_CS_E status of the instruction
                                       is other than DPI_CS_E::NOERR (i.e. zero), then DPI will write the DPI_CS_E
                                       status of the instruction into the WQE (at offset DPI()_DMA_CONTROL[WQECSOFF],
                                       preferrably without cache allocation on a miss) before submitting the work.
                                       
                                       DPI()_DMA_CONTROL[WQECSDIS]!=0 or DPI()_DMA_CONTROL[WQECSMODE]!=0 can give
                                       other behavior. */

/**
 * Enumeration dpi_hdr_xtype_e
 *
 * DPI Transfer Type Enumeration
 * Enumerates the pointer type in DPI_DMA_INSTR_HDR_S[XTYPE].
 */
#define BDK_DPI_HDR_XTYPE_E_EXTERNAL_ONLY (3) /**< A DPI DMA transfer from MAC addresses in the first pointers block
                                       to MAC addresses in the last pointers block. */
#define BDK_DPI_HDR_XTYPE_E_INBOUND (1) /**< A DPI DMA transfer from MAC addresses in the last pointers block
                                       to DPI_DMA_LOCAL_PTR_S's in the first pointers block. */
#define BDK_DPI_HDR_XTYPE_E_INTERNAL_ONLY (2) /**< A DPI DMA transfer from DPI_DMA_LOCAL_PTR_S's in the first pointers
                                       block to DPI_DMA_LOCAL_PTR_S's in the last pointers block. */
#define BDK_DPI_HDR_XTYPE_E_OUTBOUND (0) /**< A DPI DMA transfer from DPI_DMA_LOCAL_PTR_S's in the first pointers
                                       block to MAC addresses in the last pointers block. The
                                       DPI_DMA_LOCAL_PTR_S[PTR]'s can optionally be freed to FPA,
                                       and an interrupt can optionally be sent to a remote host. */

/**
 * Enumeration dpi_intsn_e
 *
 * DPI Interrupt Source Enumeration
 * Enumerates the different DPI-generated interrupts.
 */
#define BDK_DPI_INTSN_E_DPIX_DMA_PPX_INT(a,b) (0xdf040 + 0 * (a) + (b)) /**< See DPI(0)_DMA_PP_INT[COMPLETE<{b}>]. */
#define BDK_DPI_INTSN_E_DPIX_ERR_RAM_DBEX(a,b) (0xdf080 + 0 * (a) + (b)) /**< See DPI(0)_ECC_INT[RAM_DBE<{b}>]. */
#define BDK_DPI_INTSN_E_DPIX_ERR_RAM_SBEX(a,b) (0xdf0a0 + 0 * (a) + (b)) /**< See DPI(0)_ECC_INT[RAM_SBE<{b}>]. */
#define BDK_DPI_INTSN_E_DPIX_INT_DMADBOX(a,b) (0xdf008 + 0 * (a) + (b)) /**< See DPI(0)_INT_REG[DMADBO<{b}>]. */
#define BDK_DPI_INTSN_E_DPIX_INT_NDERR(a) (0xdf000 + 0 * (a)) /**< See DPI(0)_INT_REG[NDERR]. */
#define BDK_DPI_INTSN_E_DPIX_INT_NFOVR(a) (0xdf001 + 0 * (a)) /**< See DPI(0)_INT_REG[NFOVR]. */
#define BDK_DPI_INTSN_E_DPIX_INT_REQ_ANULL(a) (0xdf014 + 0 * (a)) /**< See DPI(0)_INT_REG[REQ_ANULL]. */
#define BDK_DPI_INTSN_E_DPIX_INT_REQ_BADADR(a) (0xdf010 + 0 * (a)) /**< See DPI(0)_INT_REG[REQ_BADADR]. */
#define BDK_DPI_INTSN_E_DPIX_INT_REQ_BADFIL(a) (0xdf016 + 0 * (a)) /**< See DPI(0)_INT_REG[REQ_BADFIL]. */
#define BDK_DPI_INTSN_E_DPIX_INT_REQ_BADLEN(a) (0xdf011 + 0 * (a)) /**< See DPI(0)_INT_REG[REQ_BADLEN]. */
#define BDK_DPI_INTSN_E_DPIX_INT_REQ_INULL(a) (0xdf015 + 0 * (a)) /**< See DPI(0)_INT_REG[REQ_INULL]. */
#define BDK_DPI_INTSN_E_DPIX_INT_REQ_OVRFLW(a) (0xdf012 + 0 * (a)) /**< See DPI(0)_INT_REG[REQ_OVRFLW]. */
#define BDK_DPI_INTSN_E_DPIX_INT_REQ_UNDFLW(a) (0xdf013 + 0 * (a)) /**< See DPI(0)_INT_REG[REQ_UNDFLW]. */

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

                                                                 When [FUNC] is non-zero, it must select a valid virtual
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

                                                                 When [FUNC] is non-zero, it must select a valid virtual
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
    uint64_t u[2];
    struct bdk_dpi_dma_instr_hdr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t lport                 : 2;  /**< [ 61: 60] Port for the last pointers block.

                                                                 DPI sends MAC memory space reads and writes for the MAC addresses
                                                                 in the last pointers block to the MAC selected by [LPORT]
                                                                 while processing DPI_HDR_XTYPE_E::OUTBOUND, DPI_HDR_XTYPE_E::INBOUND,
                                                                 and DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions.

                                                                 [LPORT<0>] normally determines the IOI/NCB DPI uses for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions.

                                                                 [LPORT<1>] must be zero for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions. */
        uint64_t reserved_58_59        : 2;
        uint64_t fport                 : 2;  /**< [ 57: 56] Port for the first pointers block.

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
        uint64_t reserved_54_55        : 2;
        uint64_t xtype                 : 2;  /**< [ 53: 52] Transfer type of the instruction. Enumerated by DPI_HDR_XTYPE_E. Each DPI DMA
                                                                 instruction can be DPI_HDR_XTYPE_E::OUTBOUND (L2/DRAM->MAC),
                                                                 DPI_HDR_XTYPE_E::INBOUND (MAC->L2/DRAM), DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 (L2/DRAM->L2/DRAM), or DPI_HDR_XTYPE_E::EXTERNAL_ONLY (MAC->MAC). */
        uint64_t csel                  : 1;  /**< [ 51: 51] Counter and interrupt select. See [CA] and [FI]. [CSEL] selects which of two counters
                                                                 (SLI_DMA()_CNT[CNT]) and/or two interrupt bits (SLI_MAC(0..3)_PF(0..1)_INT_SUM[DMAFI])
                                                                 DPI can modify during DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY
                                                                 instruction execution.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CSEL] must be zero. */
        uint64_t ca                    : 1;  /**< [ 50: 50] Add to a counter that can interrupt a remote host.

                                                                 When [CA] = 1, DPI updates a selected counter after it completes the DMA
                                                                 DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY instruction.

                                                                 _ If [CSEL] = 0, DPI updates SLI_DMA(0)_CNT[CNT].
                                                                 _ If [CSEL] = 1, DPI updates SLI_DMA(1)_CNT[CNT].

                                                                 Note that these updates may indirectly cause
                                                                 SLI_MAC(0..3)_PF(0..1)_INT_SUM[DCNT,DTIME] to become set for all MACs
                                                                 (depending on the SLI_DMA()_INT_LEVEL settings), so may cause interrupts to
                                                                 be sent to a remote MAC host.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 1, DPI updates the counter by 1.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 0, DPI updates the counter by the total bytes in
                                                                 the transfer.

                                                                 When [CA] = 0, DPI does not update any SLI_DMA()_CNT[CNT].

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CA] must never be set, and DPI never adds to any
                                                                 SLI_DMA()_CNT[CNT]. */
        uint64_t fi                    : 1;  /**< [ 49: 49] Force interrupt to a remote host.

                                                                 When [FI] is set for a (DPI_HDR_XTYPE_E::OUTBOUND or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY) DPI DMA instruction, DPI sets an
                                                                 interrupt bit after completing instruction. If [CSEL] = 0, DPI sets
                                                                 SLI_MAC(0..3)_PF(0..1)_INT_SUM[DMAFI<0>] for all MACs, else DPI sets
                                                                 SLI_MAC(0..3)_PF(0..1)_INT_SUM[DMAFI<1>] for all MACs. This may
                                                                 cause an interrupt to be sent to a remote host.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions, [II] must be clear, and DPI never sets DMAFI interrupt bits. */
        uint64_t ii                    : 1;  /**< [ 48: 48] Ignore I. Determines if DPI_DMA_LOCAL_PTR_S[I]'s influence whether
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
        uint64_t fl                    : 1;  /**< [ 47: 47] Determines whether DPI frees a DPI_DMA_LOCAL_PTR_S[PTR] during
                                                                 DPI_HDR_XTYPE_E::OUTBOUND instruction processing
                                                                 (along with [II] and DPI_DMA_LOCAL_PTR_S[I]).

                                                                 During DPI_HDR_XTYPE_E::OUTBOUND instruction processing, DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA when:

                                                                 _ [FL] XOR (![II] AND DPI_DMA_LOCAL_PTR_S[I])

                                                                 For DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::INTERNAL_ONLY, or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, [FL] must be clear,
                                                                 and DPI never frees local buffers. */
        uint64_t reserved_46           : 1;
        uint64_t pt                    : 2;  /**< [ 45: 44] Pointer Type. Enumerated by DPI_HDR_PT_E. Indicates how [PTR] is used
                                                                 upon completion of the DPI DMA instruction: byte write, SSO
                                                                 work add, or counter add.

                                                                 If no completion indication is desired for the DPI DMA instruction,
                                                                 software should set [PT]=DPI_HDR_PT_E::ZBW_CA (0) and [PTR]=0. */
        uint64_t dealloce              : 1;  /**< [ 43: 43] Aura count subtract enable. When [DEALLOCE] is set, DPI subtracts
                                                                 [DEALLOCV] from the FPA aura count selected by [AURA]. When [DEALLOCE]
                                                                 is clear, DPI does not subtract [DEALLOCV] from any aura count.
                                                                 [DEALLOCE] can only be set when [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND.
                                                                 [DEALLOCE] must not be set when [PVFE] is set. [DEALLOCV] must not be 0
                                                                 when [DEALLOCE] is set.

                                                                 The [DEALLOCV] aura count subtract is in addition to other
                                                                 aura count activity. When FPA_AURA([AURA])_CFG[PTR_DIS]==0, FPA also
                                                                 decrements the aura count by one for each DPI_DMA_LOCAL_PTR_S local
                                                                 pointer free. */
        uint64_t reserved_42           : 1;
        uint64_t nlst                  : 4;  /**< [ 41: 38] The number of pointers in the last-pointers block.

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
        uint64_t reserved_36_37        : 2;
        uint64_t nfst                  : 4;  /**< [ 35: 32] The number of pointers in the first pointers block.

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
        uint64_t pvfe                  : 1;  /**< [ 31: 31] Function Enable. When [PVFE] is set, DPI directs all MAC reads/writes
                                                                 to the function (physical or virtual) that [DEALLOCV] selects within
                                                                 MAC/port [LPORT]. When [PVFE] is clear, DPI directs all MAC reads/writes
                                                                 to physical function 0 within the MACs/ports [LPORT] or [FPORT]. [PVFE]
                                                                 must not be set when [DEALLOCE] is set. [PVFE] must not be set when
                                                                 [XTYPE] is DPI_HDR_XTYPE_E::INTERNAL_ONLY or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY. [PVFE] can only be set when MAC/PORT
                                                                 [LPORT] is a PCIe MAC that either has multiple physical functions or
                                                                 has SR-IOV enabled. */
        uint64_t reserved_28_30        : 3;
        uint64_t grp                   : 10; /**< [ 27: 18] SSO Group. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.

                                                                 [GRP] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t tt                    : 2;  /**< [ 17: 16] SSO Tag Type. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.

                                                                 [TT] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t reserved_12_15        : 4;
        uint64_t aura                  : 12; /**< [ 11:  0] FPA Aura.  The FPA AURA DPI uses for all FPA transactions for the
                                                                 DPI DMA instruction. [AURA] can only be used when
                                                                 [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND, and must be zero otherwise.

                                                                 During an DPI_HDR_XTYPE_E::OUTBOUND DPI DMA instruction, [FL], [II],
                                                                 and DPI_DMA_LOCAL_PTR_S[I] determine whether DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA, and [DEALLOCE] determines
                                                                 whether DPI subtracts [DEALLOCV] from [AURA]'s FPA aura counter. */
#else /* Word 0 - Little Endian */
        uint64_t aura                  : 12; /**< [ 11:  0] FPA Aura.  The FPA AURA DPI uses for all FPA transactions for the
                                                                 DPI DMA instruction. [AURA] can only be used when
                                                                 [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND, and must be zero otherwise.

                                                                 During an DPI_HDR_XTYPE_E::OUTBOUND DPI DMA instruction, [FL], [II],
                                                                 and DPI_DMA_LOCAL_PTR_S[I] determine whether DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA, and [DEALLOCE] determines
                                                                 whether DPI subtracts [DEALLOCV] from [AURA]'s FPA aura counter. */
        uint64_t reserved_12_15        : 4;
        uint64_t tt                    : 2;  /**< [ 17: 16] SSO Tag Type. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.

                                                                 [TT] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t grp                   : 10; /**< [ 27: 18] SSO Group. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.

                                                                 [GRP] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t reserved_28_30        : 3;
        uint64_t pvfe                  : 1;  /**< [ 31: 31] Function Enable. When [PVFE] is set, DPI directs all MAC reads/writes
                                                                 to the function (physical or virtual) that [DEALLOCV] selects within
                                                                 MAC/port [LPORT]. When [PVFE] is clear, DPI directs all MAC reads/writes
                                                                 to physical function 0 within the MACs/ports [LPORT] or [FPORT]. [PVFE]
                                                                 must not be set when [DEALLOCE] is set. [PVFE] must not be set when
                                                                 [XTYPE] is DPI_HDR_XTYPE_E::INTERNAL_ONLY or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY. [PVFE] can only be set when MAC/PORT
                                                                 [LPORT] is a PCIe MAC that either has multiple physical functions or
                                                                 has SR-IOV enabled. */
        uint64_t nfst                  : 4;  /**< [ 35: 32] The number of pointers in the first pointers block.

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
        uint64_t reserved_36_37        : 2;
        uint64_t nlst                  : 4;  /**< [ 41: 38] The number of pointers in the last-pointers block.

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
        uint64_t reserved_42           : 1;
        uint64_t dealloce              : 1;  /**< [ 43: 43] Aura count subtract enable. When [DEALLOCE] is set, DPI subtracts
                                                                 [DEALLOCV] from the FPA aura count selected by [AURA]. When [DEALLOCE]
                                                                 is clear, DPI does not subtract [DEALLOCV] from any aura count.
                                                                 [DEALLOCE] can only be set when [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND.
                                                                 [DEALLOCE] must not be set when [PVFE] is set. [DEALLOCV] must not be 0
                                                                 when [DEALLOCE] is set.

                                                                 The [DEALLOCV] aura count subtract is in addition to other
                                                                 aura count activity. When FPA_AURA([AURA])_CFG[PTR_DIS]==0, FPA also
                                                                 decrements the aura count by one for each DPI_DMA_LOCAL_PTR_S local
                                                                 pointer free. */
        uint64_t pt                    : 2;  /**< [ 45: 44] Pointer Type. Enumerated by DPI_HDR_PT_E. Indicates how [PTR] is used
                                                                 upon completion of the DPI DMA instruction: byte write, SSO
                                                                 work add, or counter add.

                                                                 If no completion indication is desired for the DPI DMA instruction,
                                                                 software should set [PT]=DPI_HDR_PT_E::ZBW_CA (0) and [PTR]=0. */
        uint64_t reserved_46           : 1;
        uint64_t fl                    : 1;  /**< [ 47: 47] Determines whether DPI frees a DPI_DMA_LOCAL_PTR_S[PTR] during
                                                                 DPI_HDR_XTYPE_E::OUTBOUND instruction processing
                                                                 (along with [II] and DPI_DMA_LOCAL_PTR_S[I]).

                                                                 During DPI_HDR_XTYPE_E::OUTBOUND instruction processing, DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA when:

                                                                 _ [FL] XOR (![II] AND DPI_DMA_LOCAL_PTR_S[I])

                                                                 For DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::INTERNAL_ONLY, or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, [FL] must be clear,
                                                                 and DPI never frees local buffers. */
        uint64_t ii                    : 1;  /**< [ 48: 48] Ignore I. Determines if DPI_DMA_LOCAL_PTR_S[I]'s influence whether
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
        uint64_t fi                    : 1;  /**< [ 49: 49] Force interrupt to a remote host.

                                                                 When [FI] is set for a (DPI_HDR_XTYPE_E::OUTBOUND or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY) DPI DMA instruction, DPI sets an
                                                                 interrupt bit after completing instruction. If [CSEL] = 0, DPI sets
                                                                 SLI_MAC(0..3)_PF(0..1)_INT_SUM[DMAFI<0>] for all MACs, else DPI sets
                                                                 SLI_MAC(0..3)_PF(0..1)_INT_SUM[DMAFI<1>] for all MACs. This may
                                                                 cause an interrupt to be sent to a remote host.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions, [II] must be clear, and DPI never sets DMAFI interrupt bits. */
        uint64_t ca                    : 1;  /**< [ 50: 50] Add to a counter that can interrupt a remote host.

                                                                 When [CA] = 1, DPI updates a selected counter after it completes the DMA
                                                                 DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY instruction.

                                                                 _ If [CSEL] = 0, DPI updates SLI_DMA(0)_CNT[CNT].
                                                                 _ If [CSEL] = 1, DPI updates SLI_DMA(1)_CNT[CNT].

                                                                 Note that these updates may indirectly cause
                                                                 SLI_MAC(0..3)_PF(0..1)_INT_SUM[DCNT,DTIME] to become set for all MACs
                                                                 (depending on the SLI_DMA()_INT_LEVEL settings), so may cause interrupts to
                                                                 be sent to a remote MAC host.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 1, DPI updates the counter by 1.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 0, DPI updates the counter by the total bytes in
                                                                 the transfer.

                                                                 When [CA] = 0, DPI does not update any SLI_DMA()_CNT[CNT].

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CA] must never be set, and DPI never adds to any
                                                                 SLI_DMA()_CNT[CNT]. */
        uint64_t csel                  : 1;  /**< [ 51: 51] Counter and interrupt select. See [CA] and [FI]. [CSEL] selects which of two counters
                                                                 (SLI_DMA()_CNT[CNT]) and/or two interrupt bits (SLI_MAC(0..3)_PF(0..1)_INT_SUM[DMAFI])
                                                                 DPI can modify during DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY
                                                                 instruction execution.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CSEL] must be zero. */
        uint64_t xtype                 : 2;  /**< [ 53: 52] Transfer type of the instruction. Enumerated by DPI_HDR_XTYPE_E. Each DPI DMA
                                                                 instruction can be DPI_HDR_XTYPE_E::OUTBOUND (L2/DRAM->MAC),
                                                                 DPI_HDR_XTYPE_E::INBOUND (MAC->L2/DRAM), DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 (L2/DRAM->L2/DRAM), or DPI_HDR_XTYPE_E::EXTERNAL_ONLY (MAC->MAC). */
        uint64_t reserved_54_55        : 2;
        uint64_t fport                 : 2;  /**< [ 57: 56] Port for the first pointers block.

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
        uint64_t reserved_58_59        : 2;
        uint64_t lport                 : 2;  /**< [ 61: 60] Port for the last pointers block.

                                                                 DPI sends MAC memory space reads and writes for the MAC addresses
                                                                 in the last pointers block to the MAC selected by [LPORT]
                                                                 while processing DPI_HDR_XTYPE_E::OUTBOUND, DPI_HDR_XTYPE_E::INBOUND,
                                                                 and DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions.

                                                                 [LPORT<0>] normally determines the IOI/NCB DPI uses for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions.

                                                                 [LPORT<1>] must be zero for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t deallocv              : 16; /**< [127:112] The DEALLOCV/FUNC field.

                                                                 When [DEALLOCE] is set, [DEALLOCV] is the value to decrement the aura count on
                                                                 the instruction's final pointer return.

                                                                 When [PVFE] is set, DPI_DMA_FUNC_SEL_S describes the [DEALLOCV] format.
                                                                 [DEALLOCV] selects the function within the MAC selected by [LPORT]
                                                                 when [PVFE] is set. */
        uint64_t reserved_106_111      : 6;
        uint64_t ptr                   : 42; /**< [105: 64] Completion pointer. Usage determined by [PT] value. The DPI_HDR_PT_E
                                                                 enumeration describes the supported [PT] values and the [PTR] usage
                                                                 and requirements in each case. */
#else /* Word 1 - Little Endian */
        uint64_t ptr                   : 42; /**< [105: 64] Completion pointer. Usage determined by [PT] value. The DPI_HDR_PT_E
                                                                 enumeration describes the supported [PT] values and the [PTR] usage
                                                                 and requirements in each case. */
        uint64_t reserved_106_111      : 6;
        uint64_t deallocv              : 16; /**< [127:112] The DEALLOCV/FUNC field.

                                                                 When [DEALLOCE] is set, [DEALLOCV] is the value to decrement the aura count on
                                                                 the instruction's final pointer return.

                                                                 When [PVFE] is set, DPI_DMA_FUNC_SEL_S describes the [DEALLOCV] format.
                                                                 [DEALLOCV] selects the function within the MAC selected by [LPORT]
                                                                 when [PVFE] is set. */
#endif /* Word 1 - End */
    } s;
    struct bdk_dpi_dma_instr_hdr_s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t lport                 : 2;  /**< [ 61: 60] Port for the last pointers block.

                                                                 DPI sends MAC memory space reads and writes for the MAC addresses
                                                                 in the last pointers block to the MAC selected by [LPORT]
                                                                 while processing DPI_HDR_XTYPE_E::OUTBOUND, DPI_HDR_XTYPE_E::INBOUND,
                                                                 and DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions.

                                                                 [LPORT<0>] normally determines the IOI/NCB DPI uses for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions.

                                                                 [LPORT<1>] must be zero for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions. */
        uint64_t reserved_58_59        : 2;
        uint64_t fport                 : 2;  /**< [ 57: 56] Port for the first pointers block.

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
        uint64_t reserved_54_55        : 2;
        uint64_t xtype                 : 2;  /**< [ 53: 52] Transfer type of the instruction. Enumerated by DPI_HDR_XTYPE_E. Each DPI DMA
                                                                 instruction can be DPI_HDR_XTYPE_E::OUTBOUND (L2/DRAM->MAC),
                                                                 DPI_HDR_XTYPE_E::INBOUND (MAC->L2/DRAM), DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 (L2/DRAM->L2/DRAM), or DPI_HDR_XTYPE_E::EXTERNAL_ONLY (MAC->MAC). */
        uint64_t csel                  : 1;  /**< [ 51: 51] Counter and interrupt select. See [CA] and [FI]. [CSEL] selects which of two counters
                                                                 (SLI_DMA()_CNT[CNT]) and/or two interrupt bits (SLI_MAC(0..3)_PF(0..1)_INT_SUM[DMAFI])
                                                                 DPI can modify during DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY
                                                                 instruction execution.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CSEL] must be zero. */
        uint64_t ca                    : 1;  /**< [ 50: 50] Add to a counter that can interrupt a remote host.

                                                                 When [CA] = 1, DPI updates a selected counter after it completes the DMA
                                                                 DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY instruction.

                                                                 _ If [CSEL] = 0, DPI updates SLI_DMA(0)_CNT[CNT].
                                                                 _ If [CSEL] = 1, DPI updates SLI_DMA(1)_CNT[CNT].

                                                                 Note that these updates may indirectly cause
                                                                 SLI_MAC(0..3)_PF(0..1)_INT_SUM[DCNT,DTIME] to become set for all MACs
                                                                 (depending on the SLI_DMA()_INT_LEVEL settings), so may cause interrupts to
                                                                 be sent to a remote MAC host.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 1, DPI updates the counter by 1.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 0, DPI updates the counter by the total bytes in
                                                                 the transfer.

                                                                 When [CA] = 0, DPI does not update any SLI_DMA()_CNT[CNT].

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CA] must never be set, and DPI never adds to any
                                                                 SLI_DMA()_CNT[CNT]. */
        uint64_t fi                    : 1;  /**< [ 49: 49] Force interrupt to a remote host.

                                                                 When [FI] is set for a (DPI_HDR_XTYPE_E::OUTBOUND or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY) DPI DMA instruction, DPI sets an
                                                                 interrupt bit after completing instruction. If [CSEL] = 0, DPI sets
                                                                 SLI_MAC(0..3)_PF(0..1)_INT_SUM[DMAFI<0>] for all MACs, else DPI sets
                                                                 SLI_MAC(0..3)_PF(0..1)_INT_SUM[DMAFI<1>] for all MACs. This may
                                                                 cause an interrupt to be sent to a remote host.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions, [II] must be clear, and DPI never sets DMAFI interrupt bits. */
        uint64_t ii                    : 1;  /**< [ 48: 48] Ignore I. Determines if DPI_DMA_LOCAL_PTR_S[I]'s influence whether
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
        uint64_t fl                    : 1;  /**< [ 47: 47] Determines whether DPI frees a DPI_DMA_LOCAL_PTR_S[PTR] during
                                                                 DPI_HDR_XTYPE_E::OUTBOUND instruction processing
                                                                 (along with [II] and DPI_DMA_LOCAL_PTR_S[I]).

                                                                 During DPI_HDR_XTYPE_E::OUTBOUND instruction processing, DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA when:

                                                                 _ [FL] XOR (![II] AND DPI_DMA_LOCAL_PTR_S[I])

                                                                 For DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::INTERNAL_ONLY, or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, [FL] must be clear,
                                                                 and DPI never frees local buffers. */
        uint64_t reserved_46           : 1;
        uint64_t pt                    : 2;  /**< [ 45: 44] Pointer Type. Enumerated by DPI_HDR_PT_E. Indicates how [PTR] is used
                                                                 upon completion of the DPI DMA instruction: byte write, SSO
                                                                 work add, or counter add.

                                                                 If no completion indication is desired for the DPI DMA instruction,
                                                                 software should set [PT]=DPI_HDR_PT_E::ZBW_CA (0) and [PTR]=0. */
        uint64_t dealloce              : 1;  /**< [ 43: 43] Aura count subtract enable. When [DEALLOCE] is set, DPI subtracts
                                                                 [DEALLOCV] from the FPA aura count selected by [AURA]. When [DEALLOCE]
                                                                 is clear, DPI does not subtract [DEALLOCV] from any aura count.
                                                                 [DEALLOCE] can only be set when [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND.
                                                                 [DEALLOCE] must not be set when [PVFE] is set. [DEALLOCV] must not be 0
                                                                 when [DEALLOCE] is set.

                                                                 The [DEALLOCV] aura count subtract is in addition to other
                                                                 aura count activity. When FPA_AURA([AURA])_CFG[PTR_DIS]==0, FPA also
                                                                 decrements the aura count by one for each DPI_DMA_LOCAL_PTR_S local
                                                                 pointer free. */
        uint64_t reserved_42           : 1;
        uint64_t nlst                  : 4;  /**< [ 41: 38] The number of pointers in the last-pointers block.

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
        uint64_t reserved_37           : 1;
        uint64_t reserved_36           : 1;
        uint64_t nfst                  : 4;  /**< [ 35: 32] The number of pointers in the first pointers block.

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
        uint64_t pvfe                  : 1;  /**< [ 31: 31] Function Enable. When [PVFE] is set, DPI directs all MAC reads/writes
                                                                 to the function (physical or virtual) that [DEALLOCV] selects within
                                                                 MAC/port [LPORT]. When [PVFE] is clear, DPI directs all MAC reads/writes
                                                                 to physical function 0 within the MACs/ports [LPORT] or [FPORT]. [PVFE]
                                                                 must not be set when [DEALLOCE] is set. [PVFE] must not be set when
                                                                 [XTYPE] is DPI_HDR_XTYPE_E::INTERNAL_ONLY or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY. [PVFE] can only be set when MAC/PORT
                                                                 [LPORT] is a PCIe MAC that either has multiple physical functions or
                                                                 has SR-IOV enabled. */
        uint64_t reserved_30           : 1;
        uint64_t reserved_28_29        : 2;
        uint64_t grp                   : 10; /**< [ 27: 18] SSO Group. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.

                                                                 [GRP] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t tt                    : 2;  /**< [ 17: 16] SSO Tag Type. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.

                                                                 [TT] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t reserved_12_15        : 4;
        uint64_t aura                  : 12; /**< [ 11:  0] FPA Aura.  The FPA AURA DPI uses for all FPA transactions for the
                                                                 DPI DMA instruction. [AURA] can only be used when
                                                                 [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND, and must be zero otherwise.

                                                                 During an DPI_HDR_XTYPE_E::OUTBOUND DPI DMA instruction, [FL], [II],
                                                                 and DPI_DMA_LOCAL_PTR_S[I] determine whether DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA, and [DEALLOCE] determines
                                                                 whether DPI subtracts [DEALLOCV] from [AURA]'s FPA aura counter. */
#else /* Word 0 - Little Endian */
        uint64_t aura                  : 12; /**< [ 11:  0] FPA Aura.  The FPA AURA DPI uses for all FPA transactions for the
                                                                 DPI DMA instruction. [AURA] can only be used when
                                                                 [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND, and must be zero otherwise.

                                                                 During an DPI_HDR_XTYPE_E::OUTBOUND DPI DMA instruction, [FL], [II],
                                                                 and DPI_DMA_LOCAL_PTR_S[I] determine whether DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA, and [DEALLOCE] determines
                                                                 whether DPI subtracts [DEALLOCV] from [AURA]'s FPA aura counter. */
        uint64_t reserved_12_15        : 4;
        uint64_t tt                    : 2;  /**< [ 17: 16] SSO Tag Type. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.

                                                                 [TT] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t grp                   : 10; /**< [ 27: 18] SSO Group. Sent to SSO upon instruction completion when [PT] = DPI_HDR_PT_E::WQP.

                                                                 [GRP] must be zero when [PT] != DPI_HDR_PT_E::WQP. */
        uint64_t reserved_28_29        : 2;
        uint64_t reserved_30           : 1;
        uint64_t pvfe                  : 1;  /**< [ 31: 31] Function Enable. When [PVFE] is set, DPI directs all MAC reads/writes
                                                                 to the function (physical or virtual) that [DEALLOCV] selects within
                                                                 MAC/port [LPORT]. When [PVFE] is clear, DPI directs all MAC reads/writes
                                                                 to physical function 0 within the MACs/ports [LPORT] or [FPORT]. [PVFE]
                                                                 must not be set when [DEALLOCE] is set. [PVFE] must not be set when
                                                                 [XTYPE] is DPI_HDR_XTYPE_E::INTERNAL_ONLY or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY. [PVFE] can only be set when MAC/PORT
                                                                 [LPORT] is a PCIe MAC that either has multiple physical functions or
                                                                 has SR-IOV enabled. */
        uint64_t nfst                  : 4;  /**< [ 35: 32] The number of pointers in the first pointers block.

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
        uint64_t reserved_36           : 1;
        uint64_t reserved_37           : 1;
        uint64_t nlst                  : 4;  /**< [ 41: 38] The number of pointers in the last-pointers block.

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
        uint64_t reserved_42           : 1;
        uint64_t dealloce              : 1;  /**< [ 43: 43] Aura count subtract enable. When [DEALLOCE] is set, DPI subtracts
                                                                 [DEALLOCV] from the FPA aura count selected by [AURA]. When [DEALLOCE]
                                                                 is clear, DPI does not subtract [DEALLOCV] from any aura count.
                                                                 [DEALLOCE] can only be set when [XTYPE]=DPI_HDR_XTYPE_E::OUTBOUND.
                                                                 [DEALLOCE] must not be set when [PVFE] is set. [DEALLOCV] must not be 0
                                                                 when [DEALLOCE] is set.

                                                                 The [DEALLOCV] aura count subtract is in addition to other
                                                                 aura count activity. When FPA_AURA([AURA])_CFG[PTR_DIS]==0, FPA also
                                                                 decrements the aura count by one for each DPI_DMA_LOCAL_PTR_S local
                                                                 pointer free. */
        uint64_t pt                    : 2;  /**< [ 45: 44] Pointer Type. Enumerated by DPI_HDR_PT_E. Indicates how [PTR] is used
                                                                 upon completion of the DPI DMA instruction: byte write, SSO
                                                                 work add, or counter add.

                                                                 If no completion indication is desired for the DPI DMA instruction,
                                                                 software should set [PT]=DPI_HDR_PT_E::ZBW_CA (0) and [PTR]=0. */
        uint64_t reserved_46           : 1;
        uint64_t fl                    : 1;  /**< [ 47: 47] Determines whether DPI frees a DPI_DMA_LOCAL_PTR_S[PTR] during
                                                                 DPI_HDR_XTYPE_E::OUTBOUND instruction processing
                                                                 (along with [II] and DPI_DMA_LOCAL_PTR_S[I]).

                                                                 During DPI_HDR_XTYPE_E::OUTBOUND instruction processing, DPI frees a
                                                                 DPI_DMA_LOCAL_PTR_S[PTR] to [AURA] in FPA when:

                                                                 _ [FL] XOR (![II] AND DPI_DMA_LOCAL_PTR_S[I])

                                                                 For DPI_HDR_XTYPE_E::INBOUND, DPI_HDR_XTYPE_E::INTERNAL_ONLY, or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions, [FL] must be clear,
                                                                 and DPI never frees local buffers. */
        uint64_t ii                    : 1;  /**< [ 48: 48] Ignore I. Determines if DPI_DMA_LOCAL_PTR_S[I]'s influence whether
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
        uint64_t fi                    : 1;  /**< [ 49: 49] Force interrupt to a remote host.

                                                                 When [FI] is set for a (DPI_HDR_XTYPE_E::OUTBOUND or
                                                                 DPI_HDR_XTYPE_E::EXTERNAL_ONLY) DPI DMA instruction, DPI sets an
                                                                 interrupt bit after completing instruction. If [CSEL] = 0, DPI sets
                                                                 SLI_MAC(0..3)_PF(0..1)_INT_SUM[DMAFI<0>] for all MACs, else DPI sets
                                                                 SLI_MAC(0..3)_PF(0..1)_INT_SUM[DMAFI<1>] for all MACs. This may
                                                                 cause an interrupt to be sent to a remote host.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions, [II] must be clear, and DPI never sets DMAFI interrupt bits. */
        uint64_t ca                    : 1;  /**< [ 50: 50] Add to a counter that can interrupt a remote host.

                                                                 When [CA] = 1, DPI updates a selected counter after it completes the DMA
                                                                 DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY instruction.

                                                                 _ If [CSEL] = 0, DPI updates SLI_DMA(0)_CNT[CNT].
                                                                 _ If [CSEL] = 1, DPI updates SLI_DMA(1)_CNT[CNT].

                                                                 Note that these updates may indirectly cause
                                                                 SLI_MAC(0..3)_PF(0..1)_INT_SUM[DCNT,DTIME] to become set for all MACs
                                                                 (depending on the SLI_DMA()_INT_LEVEL settings), so may cause interrupts to
                                                                 be sent to a remote MAC host.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 1, DPI updates the counter by 1.

                                                                 If DPI()_DMA_CONTROL[O_ADD1] = 0, DPI updates the counter by the total bytes in
                                                                 the transfer.

                                                                 When [CA] = 0, DPI does not update any SLI_DMA()_CNT[CNT].

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CA] must never be set, and DPI never adds to any
                                                                 SLI_DMA()_CNT[CNT]. */
        uint64_t csel                  : 1;  /**< [ 51: 51] Counter and interrupt select. See [CA] and [FI]. [CSEL] selects which of two counters
                                                                 (SLI_DMA()_CNT[CNT]) and/or two interrupt bits (SLI_MAC(0..3)_PF(0..1)_INT_SUM[DMAFI])
                                                                 DPI can modify during DPI_HDR_XTYPE_E::OUTBOUND or DPI_HDR_XTYPE_E::EXTERNAL_ONLY
                                                                 instruction execution.

                                                                 For DPI_HDR_XTYPE_E::INBOUND or DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA
                                                                 instructions, [CSEL] must be zero. */
        uint64_t xtype                 : 2;  /**< [ 53: 52] Transfer type of the instruction. Enumerated by DPI_HDR_XTYPE_E. Each DPI DMA
                                                                 instruction can be DPI_HDR_XTYPE_E::OUTBOUND (L2/DRAM->MAC),
                                                                 DPI_HDR_XTYPE_E::INBOUND (MAC->L2/DRAM), DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 (L2/DRAM->L2/DRAM), or DPI_HDR_XTYPE_E::EXTERNAL_ONLY (MAC->MAC). */
        uint64_t reserved_54_55        : 2;
        uint64_t fport                 : 2;  /**< [ 57: 56] Port for the first pointers block.

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
        uint64_t reserved_58_59        : 2;
        uint64_t lport                 : 2;  /**< [ 61: 60] Port for the last pointers block.

                                                                 DPI sends MAC memory space reads and writes for the MAC addresses
                                                                 in the last pointers block to the MAC selected by [LPORT]
                                                                 while processing DPI_HDR_XTYPE_E::OUTBOUND, DPI_HDR_XTYPE_E::INBOUND,
                                                                 and DPI_HDR_XTYPE_E::EXTERNAL_ONLY instructions.

                                                                 [LPORT<0>] normally determines the IOI/NCB DPI uses for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions.

                                                                 [LPORT<1>] must be zero for DPI_HDR_XTYPE_E::INTERNAL_ONLY
                                                                 instructions. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t deallocv              : 16; /**< [127:112] The DEALLOCV/FUNC field.

                                                                 When [DEALLOCE] is set, [DEALLOCV] is the value to decrement the aura count on
                                                                 the instruction's final pointer return.

                                                                 When [PVFE] is set, DPI_DMA_FUNC_SEL_S describes the [DEALLOCV] format.
                                                                 [DEALLOCV] selects the function within the MAC selected by [LPORT]
                                                                 when [PVFE] is set. */
        uint64_t reserved_106_111      : 6;
        uint64_t ptr                   : 42; /**< [105: 64] Completion pointer. Usage determined by [PT] value. The DPI_HDR_PT_E
                                                                 enumeration describes the supported [PT] values and the [PTR] usage
                                                                 and requirements in each case. */
#else /* Word 1 - Little Endian */
        uint64_t ptr                   : 42; /**< [105: 64] Completion pointer. Usage determined by [PT] value. The DPI_HDR_PT_E
                                                                 enumeration describes the supported [PT] values and the [PTR] usage
                                                                 and requirements in each case. */
        uint64_t reserved_106_111      : 6;
        uint64_t deallocv              : 16; /**< [127:112] The DEALLOCV/FUNC field.

                                                                 When [DEALLOCE] is set, [DEALLOCV] is the value to decrement the aura count on
                                                                 the instruction's final pointer return.

                                                                 When [PVFE] is set, DPI_DMA_FUNC_SEL_S describes the [DEALLOCV] format.
                                                                 [DEALLOCV] selects the function within the MAC selected by [LPORT]
                                                                 when [PVFE] is set. */
#endif /* Word 1 - End */
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
    uint64_t u;
    struct bdk_dpi_dma_local_ptr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t i                     : 1;  /**< [ 63: 63] Invert free. This bit gives the software the ability to free buffers
                                                                 independently for a DPI_HDR_XTYPE_E::OUTBOUND DMA transfer when
                                                                 DPI_DMA_INSTR_HDR_S[II] is clear. See DPI_DMA_INSTR_HDR_S[II] and
                                                                 DPI_DMA_INSTR_HDR_S[FL].

                                                                 [I] is not used by DPI when DPI_DMA_INSTR_HDR_S[II] is set. [I] must not be set,
                                                                 and DPI never frees buffers for DPI_HDR_XTYPE_E::INBOUND and
                                                                 DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA instructions. */
        uint64_t f                     : 1;  /**< [ 62: 62] Full-block write operations are allowed.

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
        uint64_t ac                    : 1;  /**< [ 61: 61] Allocate L2. This is a hint to DPI that the cache blocks should be allocated in
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
        uint64_t size                  : 13; /**< [ 60: 48] Size in bytes of the contiguous space specified by PTR. A SIZE value of 0x0 is
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
        uint64_t l                     : 1;  /**< [ 47: 47] Little-endian.
                                                                 When L is set, the data at PTR is in little-endian format rather than big-endian. */
        uint64_t reserved_42_46        : 5;
        uint64_t ptr                   : 42; /**< [ 41:  0] L2/DRAM byte pointer. Points to where the packet data starts. PTR can be any
                                                                 byte alignment. Note that PTR is interpreted as a big-endian byte pointer when L
                                                                 is clear, a little-endian byte pointer when L is set. */
#else /* Word 0 - Little Endian */
        uint64_t ptr                   : 42; /**< [ 41:  0] L2/DRAM byte pointer. Points to where the packet data starts. PTR can be any
                                                                 byte alignment. Note that PTR is interpreted as a big-endian byte pointer when L
                                                                 is clear, a little-endian byte pointer when L is set. */
        uint64_t reserved_42_46        : 5;
        uint64_t l                     : 1;  /**< [ 47: 47] Little-endian.
                                                                 When L is set, the data at PTR is in little-endian format rather than big-endian. */
        uint64_t size                  : 13; /**< [ 60: 48] Size in bytes of the contiguous space specified by PTR. A SIZE value of 0x0 is
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
        uint64_t ac                    : 1;  /**< [ 61: 61] Allocate L2. This is a hint to DPI that the cache blocks should be allocated in
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
        uint64_t i                     : 1;  /**< [ 63: 63] Invert free. This bit gives the software the ability to free buffers
                                                                 independently for a DPI_HDR_XTYPE_E::OUTBOUND DMA transfer when
                                                                 DPI_DMA_INSTR_HDR_S[II] is clear. See DPI_DMA_INSTR_HDR_S[II] and
                                                                 DPI_DMA_INSTR_HDR_S[FL].

                                                                 [I] is not used by DPI when DPI_DMA_INSTR_HDR_S[II] is set. [I] must not be set,
                                                                 and DPI never frees buffers for DPI_HDR_XTYPE_E::INBOUND and
                                                                 DPI_HDR_XTYPE_E::INTERNAL_ONLY DPI DMA instructions. */
#endif /* Word 0 - End */
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
        uint64_t reserved_57_63        : 7;
        uint64_t bist                  : 57; /**< [ 56:  0](RO/H) BIST results. Hardware sets a bit in BIST for memory that fails.
                                                                 INTERNAL:
                                                                   dpi.dma.csr.r_pkt__csr_bstatus_summary,    56    -- from the packet logic
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
        uint64_t bist                  : 57; /**< [ 56:  0](RO/H) BIST results. Hardware sets a bit in BIST for memory that fails.
                                                                 INTERNAL:
                                                                   dpi.dma.csr.r_pkt__csr_bstatus_summary,    56    -- from the packet logic
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
        uint64_t reserved_57_63        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_bist_status_s cn; */
} bdk_dpix_bist_status_t;

static inline uint64_t BDK_DPIX_BIST_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_BIST_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000000000ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_BIST_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_BIST_STATUS(a) bdk_dpix_bist_status_t
#define bustype_BDK_DPIX_BIST_STATUS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_BIST_STATUS(a) "DPIX_BIST_STATUS"
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
        return 0x86e000000040ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_CTL(a) bdk_dpix_ctl_t
#define bustype_BDK_DPIX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_CTL(a) "DPIX_CTL"
#define busnum_BDK_DPIX_CTL(a) (a)
#define arguments_BDK_DPIX_CTL(a) (a),-1,-1,-1

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
        return 0x86e000000300ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_COUNTS", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_COUNTS(a,b) bdk_dpix_dmax_counts_t
#define bustype_BDK_DPIX_DMAX_COUNTS(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_COUNTS(a,b) "DPIX_DMAX_COUNTS"
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
        return 0x86e000000200ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_DBELL", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_DBELL(a,b) bdk_dpix_dmax_dbell_t
#define bustype_BDK_DPIX_DMAX_DBELL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_DBELL(a,b) "DPIX_DMAX_DBELL"
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
        uint64_t status                : 6;  /**< [  5:  0](R/W1C/H) STATUS captures the ErrorResponse status of the last 6 instructions for each instruction
                                                                 queue. STATUS<5> represents the status for first instruction in instruction order while
                                                                 STATUS<0> represents the last or most recent instruction. If STATUS<n> is set, then the
                                                                 Nth instruction in the given queue experienced an ErrorResponse. Otherwise, it completed
                                                                 normally. */
#else /* Word 0 - Little Endian */
        uint64_t status                : 6;  /**< [  5:  0](R/W1C/H) STATUS captures the ErrorResponse status of the last 6 instructions for each instruction
                                                                 queue. STATUS<5> represents the status for first instruction in instruction order while
                                                                 STATUS<0> represents the last or most recent instruction. If STATUS<n> is set, then the
                                                                 Nth instruction in the given queue experienced an ErrorResponse. Otherwise, it completed
                                                                 normally. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_err_rsp_status_s cn; */
} bdk_dpix_dmax_err_rsp_status_t;

static inline uint64_t BDK_DPIX_DMAX_ERR_RSP_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_ERR_RSP_STATUS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000a80ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_ERR_RSP_STATUS", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_ERR_RSP_STATUS(a,b) bdk_dpix_dmax_err_rsp_status_t
#define bustype_BDK_DPIX_DMAX_ERR_RSP_STATUS(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_ERR_RSP_STATUS(a,b) "DPIX_DMAX_ERR_RSP_STATUS"
#define busnum_BDK_DPIX_DMAX_ERR_RSP_STATUS(a,b) (a)
#define arguments_BDK_DPIX_DMAX_ERR_RSP_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma#_ibuff_saddr
 *
 * DPI DMA Instruction-Buffer Starting-Address Registers
 * These registers provide the address to start reading instructions for the eight DMA
 * instruction queues.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dmax_ibuff_saddr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t idle                  : 1;  /**< [ 63: 63](RO/H) DMA request queue is idle. When asserted, the associated request queue is idle. */
        uint64_t reserved_62           : 1;
        uint64_t csize                 : 14; /**< [ 61: 48](R/W) The size in 8-byte words of the DMA instruction chunk. This value should only be written
                                                                 at known times in order to prevent corruption of the instruction queue. The minimum CSIZE
                                                                 is 16 (one cache block). */
        uint64_t reserved_42_47        : 6;
        uint64_t saddr                 : 35; /**< [ 41:  7](R/W/H) Starting address. The 128-byte aligned starting or chunk address. SADDR is address bit
                                                                 <41:7> of the starting instructions address. When new chunks are fetched by the hardware,
                                                                 SADDR is updated to reflect the address of the current chunk. A write to SADDR resets both
                                                                 the queue's doorbell (DPI(0)_DMA()_COUNTS[DBELL) and its tail pointer
                                                                 (DPI(0)_DMA()_NADDR[ADDR]). */
        uint64_t reserved_0_6          : 7;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_6          : 7;
        uint64_t saddr                 : 35; /**< [ 41:  7](R/W/H) Starting address. The 128-byte aligned starting or chunk address. SADDR is address bit
                                                                 <41:7> of the starting instructions address. When new chunks are fetched by the hardware,
                                                                 SADDR is updated to reflect the address of the current chunk. A write to SADDR resets both
                                                                 the queue's doorbell (DPI(0)_DMA()_COUNTS[DBELL) and its tail pointer
                                                                 (DPI(0)_DMA()_NADDR[ADDR]). */
        uint64_t reserved_42_47        : 6;
        uint64_t csize                 : 14; /**< [ 61: 48](R/W) The size in 8-byte words of the DMA instruction chunk. This value should only be written
                                                                 at known times in order to prevent corruption of the instruction queue. The minimum CSIZE
                                                                 is 16 (one cache block). */
        uint64_t reserved_62           : 1;
        uint64_t idle                  : 1;  /**< [ 63: 63](RO/H) DMA request queue is idle. When asserted, the associated request queue is idle. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_ibuff_saddr_s cn; */
} bdk_dpix_dmax_ibuff_saddr_t;

static inline uint64_t BDK_DPIX_DMAX_IBUFF_SADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_IBUFF_SADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000280ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_IBUFF_SADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_IBUFF_SADDR(a,b) bdk_dpix_dmax_ibuff_saddr_t
#define bustype_BDK_DPIX_DMAX_IBUFF_SADDR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_IBUFF_SADDR(a,b) "DPIX_DMAX_IBUFF_SADDR"
#define busnum_BDK_DPIX_DMAX_IBUFF_SADDR(a,b) (a)
#define arguments_BDK_DPIX_DMAX_IBUFF_SADDR(a,b) (a),(b),-1,-1

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
        uint64_t cnt                   : 3;  /**< [  2:  0](R/W/H) The number of instructions from a given queue that can be in flight to the DMA engines at
                                                                 a time. Reset value matches the number of DMA engines. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 3;  /**< [  2:  0](R/W/H) The number of instructions from a given queue that can be in flight to the DMA engines at
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
        return 0x86e000000a00ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_IFLIGHT", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_IFLIGHT(a,b) bdk_dpix_dmax_iflight_t
#define bustype_BDK_DPIX_DMAX_IFLIGHT(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_IFLIGHT(a,b) "DPIX_DMAX_IFLIGHT"
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
        uint64_t reserved_42_63        : 22;
        uint64_t addr                  : 42; /**< [ 41:  0](RO/H) Address. Provides the next L2C address to read instructions. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 42; /**< [ 41:  0](RO/H) Address. Provides the next L2C address to read instructions. */
        uint64_t reserved_42_63        : 22;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_naddr_s cn; */
} bdk_dpix_dmax_naddr_t;

static inline uint64_t BDK_DPIX_DMAX_NADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_NADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000380ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_NADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_NADDR(a,b) bdk_dpix_dmax_naddr_t
#define bustype_BDK_DPIX_DMAX_NADDR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_NADDR(a,b) "DPIX_DMAX_NADDR"
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
        return 0x86e000000400ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_REQBNK0", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_REQBNK0(a,b) bdk_dpix_dmax_reqbnk0_t
#define bustype_BDK_DPIX_DMAX_REQBNK0(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_REQBNK0(a,b) "DPIX_DMAX_REQBNK0"
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
        return 0x86e000000480ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_REQBNK1", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_REQBNK1(a,b) bdk_dpix_dmax_reqbnk1_t
#define bustype_BDK_DPIX_DMAX_REQBNK1(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_REQBNK1(a,b) "DPIX_DMAX_REQBNK1"
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
        uint64_t reserved_9_63         : 55;
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
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dmax_reqq_ctl_s cn; */
} bdk_dpix_dmax_reqq_ctl_t;

static inline uint64_t BDK_DPIX_DMAX_REQQ_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMAX_REQQ_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=7)))
        return 0x86e000000180ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMAX_REQQ_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMAX_REQQ_CTL(a,b) bdk_dpix_dmax_reqq_ctl_t
#define bustype_BDK_DPIX_DMAX_REQQ_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMAX_REQQ_CTL(a,b) "DPIX_DMAX_REQQ_CTL"
#define busnum_BDK_DPIX_DMAX_REQQ_CTL(a,b) (a)
#define arguments_BDK_DPIX_DMAX_REQQ_CTL(a,b) (a),(b),-1,-1

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
                                                                 non-DPI_CS_E::NOERR (i.e. non-zero) completion status byte to (big-endian
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
                                                                       status byte for all other DPI_CS_E (i.e. non-zero) values
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
        uint64_t ncb_tag               : 1;  /**< [ 34: 34](R/W) NCB tag enable. It allows DMA Read/Write transactions over NCB to be mapped to
                                                                 individual request queues by using tags. This enables more parallelism, giving a
                                                                 performance boost. */
        uint64_t b0_lend               : 1;  /**< [ 33: 33](R/W) Endian-ness for DPI_HDR_PT_E::ZBC_CA and DPI_HDR_PT_E::ZBC_NC DPI DMA
                                                                 instructions. When clear, DPI_DMA_INSTR_HDR_S[PTR] is big-endian for
                                                                 these instructions. When set, DPI_DMA_INSTR_HDR_S[PTR] is little-endian
                                                                 for these instructions. */
        uint64_t ldwb                  : 1;  /**< [ 32: 32](R/W) Load don't write back. When set, the hardware is able to issue LDWB commands for pointers
                                                                 that are being freed. As a result, the line will not be written back when replaced.
                                                                 When clear, the hardware issues regular load commands to the cache which cause the
                                                                 line to be written back before being replaced. */
        uint64_t aura_ichk             : 12; /**< [ 31: 20](R/W) AURA instruction chunk. The AURA that the instruction chunk for DMA operations page will
                                                                 be returned to when freed. */
        uint64_t o_add1                : 1;  /**< [ 19: 19](R/W) Add one.
                                                                 0 = The number of bytes in the DMA transfer is added to SLI_DMA()_CNT.
                                                                 1 = Add 1 to the SLI_DMA()_CNT DMA counters. */
        uint64_t o_ro                  : 1;  /**< [ 18: 18](R/W) Relaxed ordering mode for DMA transactions */
        uint64_t o_ns                  : 1;  /**< [ 17: 17](R/W) No snoop. */
        uint64_t o_es                  : 2;  /**< [ 16: 15](R/W) Endian swap mode for DMA.

                                                                 See SLI_ENDIANSWAP_E. */
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
        uint64_t o_es                  : 2;  /**< [ 16: 15](R/W) Endian swap mode for DMA.

                                                                 See SLI_ENDIANSWAP_E. */
        uint64_t o_ns                  : 1;  /**< [ 17: 17](R/W) No snoop. */
        uint64_t o_ro                  : 1;  /**< [ 18: 18](R/W) Relaxed ordering mode for DMA transactions */
        uint64_t o_add1                : 1;  /**< [ 19: 19](R/W) Add one.
                                                                 0 = The number of bytes in the DMA transfer is added to SLI_DMA()_CNT.
                                                                 1 = Add 1 to the SLI_DMA()_CNT DMA counters. */
        uint64_t aura_ichk             : 12; /**< [ 31: 20](R/W) AURA instruction chunk. The AURA that the instruction chunk for DMA operations page will
                                                                 be returned to when freed. */
        uint64_t ldwb                  : 1;  /**< [ 32: 32](R/W) Load don't write back. When set, the hardware is able to issue LDWB commands for pointers
                                                                 that are being freed. As a result, the line will not be written back when replaced.
                                                                 When clear, the hardware issues regular load commands to the cache which cause the
                                                                 line to be written back before being replaced. */
        uint64_t b0_lend               : 1;  /**< [ 33: 33](R/W) Endian-ness for DPI_HDR_PT_E::ZBC_CA and DPI_HDR_PT_E::ZBC_NC DPI DMA
                                                                 instructions. When clear, DPI_DMA_INSTR_HDR_S[PTR] is big-endian for
                                                                 these instructions. When set, DPI_DMA_INSTR_HDR_S[PTR] is little-endian
                                                                 for these instructions. */
        uint64_t ncb_tag               : 1;  /**< [ 34: 34](R/W) NCB tag enable. It allows DMA Read/Write transactions over NCB to be mapped to
                                                                 individual request queues by using tags. This enables more parallelism, giving a
                                                                 performance boost. */
        uint64_t reserved_35_36        : 2;
        uint64_t wqecsmode             : 2;  /**< [ 38: 37](R/W) WQE completion status mode. Relevant for DPI DMA instructions with
                                                                 DPI_DMA_INSTR_HDR_S[PT]=DPI_HDR_PT_E::WQP when [WQECSDIS]=0.
                                                                 0x0 = Normal behavior. DPI will not write the completion status byte for
                                                                       DPI_HDR_PT_E::WQP DPI DMA instructions with DPI_CS_E::NOERR (i.e. zero)
                                                                       completion status, regardless of the DPI_HDR_PT_WQP_E selection of
                                                                       DPI_DMA_INSTR_HDR_S[PTR<2:0>]. DPI will write the completion
                                                                       status byte for all other DPI_CS_E (i.e. non-zero) values
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
                                                                 non-DPI_CS_E::NOERR (i.e. non-zero) completion status byte to (big-endian
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
        return 0x86e000000048ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_DMA_CONTROL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_DMA_CONTROL(a) bdk_dpix_dma_control_t
#define bustype_BDK_DPIX_DMA_CONTROL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMA_CONTROL(a) "DPIX_DMA_CONTROL"
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

                                                                 Setting QEN = 0x0 effectively disables the engine. When DPI(0)_DMA_CONTROL[PKT_EN] = 1,
                                                                 then
                                                                 DPI(0)_DMA_ENG4/5_EN [QEN] must be zero. */
#else /* Word 0 - Little Endian */
        uint64_t qen                   : 8;  /**< [  7:  0](R/W) Instruction queue enable. This field specifies which of eight logical instruction queues
                                                                 can be serviced by the DMA engine.
                                                                   0 = Prevent service.
                                                                   1 = Allow service.

                                                                 Setting QEN = 0x0 effectively disables the engine. When DPI(0)_DMA_CONTROL[PKT_EN] = 1,
                                                                 then
                                                                 DPI(0)_DMA_ENG4/5_EN [QEN] must be zero. */
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
        return 0x86e000000080ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_DMA_ENGX_EN", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMA_ENGX_EN(a,b) bdk_dpix_dma_engx_en_t
#define bustype_BDK_DPIX_DMA_ENGX_EN(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMA_ENGX_EN(a,b) "DPIX_DMA_ENGX_EN"
#define busnum_BDK_DPIX_DMA_ENGX_EN(a,b) (a)
#define arguments_BDK_DPIX_DMA_ENGX_EN(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma_pp#_cnt
 *
 * DPI DMA Per-Core Instruction Completion Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dma_ppx_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t cnt                   : 16; /**< [ 15:  0](R/W/H) DPI DMA per-core instruction completion counter. DPI can increment a counter upon
                                                                 completion of a DPI DMA instruction. DPI subtracts the value written
                                                                 from [CNT] on a software write. A nonzero [CNT] asserts the corresponding
                                                                 DPI()_DMA_PP_INT bit and a 0->1 [CNT] transition clears the corresponding
                                                                 DPI()_DMA_PP_INT bit.

                                                                 DPI increments the [CNT] selected by DPI_DMA_INSTR_HDR_S[PTR] by one after completing
                                                                 a DPI_DMA_INSTR_HDR_S[PT]=DPI_HDR_PT_E::CNT DPI DMA instruction. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 16; /**< [ 15:  0](R/W/H) DPI DMA per-core instruction completion counter. DPI can increment a counter upon
                                                                 completion of a DPI DMA instruction. DPI subtracts the value written
                                                                 from [CNT] on a software write. A nonzero [CNT] asserts the corresponding
                                                                 DPI()_DMA_PP_INT bit and a 0->1 [CNT] transition clears the corresponding
                                                                 DPI()_DMA_PP_INT bit.

                                                                 DPI increments the [CNT] selected by DPI_DMA_INSTR_HDR_S[PTR] by one after completing
                                                                 a DPI_DMA_INSTR_HDR_S[PT]=DPI_HDR_PT_E::CNT DPI DMA instruction. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dma_ppx_cnt_s cn; */
} bdk_dpix_dma_ppx_cnt_t;

static inline uint64_t BDK_DPIX_DMA_PPX_CNT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMA_PPX_CNT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=15)))
        return 0x86e000000c00ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0xf);
    __bdk_csr_fatal("DPIX_DMA_PPX_CNT", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_DMA_PPX_CNT(a,b) bdk_dpix_dma_ppx_cnt_t
#define bustype_BDK_DPIX_DMA_PPX_CNT(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMA_PPX_CNT(a,b) "DPIX_DMA_PPX_CNT"
#define busnum_BDK_DPIX_DMA_PPX_CNT(a,b) (a)
#define arguments_BDK_DPIX_DMA_PPX_CNT(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_dma_pp_int
 *
 * DPI DMA Per-Core Instruction Completion Interrupt Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_dma_pp_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t complete              : 16; /**< [ 15:  0](RO/H) DPI DMA per-core instruction completion interrupt. See DPI(0)_DMA_PP()_CNT
                                                                 and DPI_INTSN_E::DPI()_DMA_PP()_INT. */
#else /* Word 0 - Little Endian */
        uint64_t complete              : 16; /**< [ 15:  0](RO/H) DPI DMA per-core instruction completion interrupt. See DPI(0)_DMA_PP()_CNT
                                                                 and DPI_INTSN_E::DPI()_DMA_PP()_INT. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_dma_pp_int_s cn; */
} bdk_dpix_dma_pp_int_t;

static inline uint64_t BDK_DPIX_DMA_PP_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_DMA_PP_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000000038ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_DMA_PP_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_DMA_PP_INT(a) bdk_dpix_dma_pp_int_t
#define bustype_BDK_DPIX_DMA_PP_INT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_DMA_PP_INT(a) "DPIX_DMA_PP_INT"
#define busnum_BDK_DPIX_DMA_PP_INT(a) (a)
#define arguments_BDK_DPIX_DMA_PP_INT(a) (a),-1,-1,-1

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
        return 0x86e000000018ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_ECC_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_ECC_CTL(a) bdk_dpix_ecc_ctl_t
#define bustype_BDK_DPIX_ECC_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_ECC_CTL(a) "DPIX_ECC_CTL"
#define busnum_BDK_DPIX_ECC_CTL(a) (a)
#define arguments_BDK_DPIX_ECC_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_ecc_int
 *
 * DPI ECC Interrupt Register
 * This register contains ECC error interrupt summary bits.
 * INTERNAL:
 * RAM[14] = dpi.pnl.pkt.sli_pkt_msix.msix_vfaddr
 * RAM[13] = dpi.pnl.pkt.sli_pkt_msix.msix_vfdata
 * RAM[12] = dpi.pnl.pkt.sli_pkt_csr.pcsr_in_done
 * RAM[11] = dpi.pnl.pkt.sli_pkt_csr.pcsr_instr_mem
 * RAM[10] = dpi.pnl.pkt.sli_pkt_csr.pcsr_pout_size
 * RAM[ 9] = dpi.pnl.pkt.sli_pkt_csr.pcsr_slist
 * RAM[ 8] = dpi.pnl.pkt.sli_pkt_csr.pout_int
 * RAM[ 7] = dpi.pnl.pkt.sli_pkt_msix.msix_mailbox
 * RAM[ 6] = dpi.pnl.pkt.sli_pkt_pof.sli_pkt_poi.poi_fifo
 * RAM[ 5] = dpi.pnl.pkt.sli_pkt_pof.sli_pkt_psf.psf_fifo
 * RAM[ 4] = dpi.pnl.pkt.sli_pkt_pof.sli_pkt_pdf.pdf_fifo
 * RAM[ 3] = dpi.pnl.pkt.sli_pkt_pop.sli_pkt_pbn.pbn_fifo
 * RAM[ 2] = dpi.pnl.pkt.sli_pkt_pop.sli_pkt_pfp.pfp_fifo
 * RAM[ 1] = dpi.pnl.pkt.sli_pkt_pop.pop_fifos.pop_mem1
 * RAM[ 1] = dpi.pnl.pkt.sli_pkt_pop.pop_fifos.pop_mem0
 * RAM[ 0] = dpi.dma.rdb.buff.bnk0a
 * RAM[ 0] = dpi.dma.rdb.buff.bnk0b
 * RAM[ 0] = dpi.dma.rdb.buff.bnk1a
 * RAM[ 0] = dpi.dma.rdb.buff.bnk1b
 * RAM[ 0] = dpi.dma.rdb.buff.bnk3a
 * RAM[ 0] = dpi.dma.rdb.buff.bnk3b
 * RAM[ 0] = dpi.dma.rdb.buff.bnk4a
 * RAM[ 0] = dpi.dma.rdb.buff.bnk4b
 * RAM[ 0] = dpi.dma.rdb.buff.bnk6a
 * RAM[ 0] = dpi.dma.rdb.buff.bnk6b
 * RAM[ 0] = dpi.dma.rdb.buff.bnk7a
 * RAM[ 0] = dpi.dma.rdb.buff.bnk7b
 * RAM[ 0] = dpi.dma.rdb.buff.bnk9a
 * RAM[ 0] = dpi.dma.rdb.buff.bnk9b
 * RAM[ 0] = dpi.dma.rdb.buff.bnk10a
 * RAM[ 0] = dpi.dma.rdb.buff.bnk10b
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_ecc_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_47_63        : 17;
        uint64_t ram_sbe               : 15; /**< [ 46: 32](R/W1C/H) Set when a single-bit error is detected in the corresponding RAM. */
        uint64_t reserved_15_31        : 17;
        uint64_t ram_dbe               : 15; /**< [ 14:  0](R/W1C/H) Set when a double-bit error is detected in the corresponding RAM. */
#else /* Word 0 - Little Endian */
        uint64_t ram_dbe               : 15; /**< [ 14:  0](R/W1C/H) Set when a double-bit error is detected in the corresponding RAM. */
        uint64_t reserved_15_31        : 17;
        uint64_t ram_sbe               : 15; /**< [ 46: 32](R/W1C/H) Set when a single-bit error is detected in the corresponding RAM. */
        uint64_t reserved_47_63        : 17;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_ecc_int_s cn; */
} bdk_dpix_ecc_int_t;

static inline uint64_t BDK_DPIX_ECC_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_ECC_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000000020ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_ECC_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_ECC_INT(a) bdk_dpix_ecc_int_t
#define bustype_BDK_DPIX_ECC_INT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_ECC_INT(a) "DPIX_ECC_INT"
#define busnum_BDK_DPIX_ECC_INT(a) (a)
#define arguments_BDK_DPIX_ECC_INT(a) (a),-1,-1,-1

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
        uint64_t reserved_38_63        : 26;
        uint64_t compblks              : 6;  /**< [ 37: 32](RO/H) Computed engine block size */
        uint64_t reserved_10_31        : 22;
        uint64_t base                  : 6;  /**< [  9:  4](RO/H) The base address in 512-byte blocks of the DMA engine FIFO. */
        uint64_t blks                  : 4;  /**< [  3:  0](R/W) The size of the DMA engine FIFO. The sum of the allocated FIFOs across all six
                                                                 DPI()_ENG()_BUF[BLKS] registers must not exceed the overall RDB memory size of
                                                                 32 KB.
                                                                 0x0 = Engine disabled.
                                                                 0x1 = 0.5 KB FIFO.
                                                                 0x2 = 1.0 KB FIFO.
                                                                 0x3 = 1.5 KB FIFO.
                                                                 0x4 = 2.0 KB FIFO.
                                                                 0x5 = 2.5 KB FIFO.
                                                                 0x6 = 3.0 KB FIFO.
                                                                 0x7 = 3.5 KB FIFO.
                                                                 0x8 = 4.0 KB FIFO.
                                                                 0x9 = 6.0 KB FIFO.
                                                                 0xA = 8.0 KB FIFO.
                                                                 0xB = 16.0 KB FIFO. */
#else /* Word 0 - Little Endian */
        uint64_t blks                  : 4;  /**< [  3:  0](R/W) The size of the DMA engine FIFO. The sum of the allocated FIFOs across all six
                                                                 DPI()_ENG()_BUF[BLKS] registers must not exceed the overall RDB memory size of
                                                                 32 KB.
                                                                 0x0 = Engine disabled.
                                                                 0x1 = 0.5 KB FIFO.
                                                                 0x2 = 1.0 KB FIFO.
                                                                 0x3 = 1.5 KB FIFO.
                                                                 0x4 = 2.0 KB FIFO.
                                                                 0x5 = 2.5 KB FIFO.
                                                                 0x6 = 3.0 KB FIFO.
                                                                 0x7 = 3.5 KB FIFO.
                                                                 0x8 = 4.0 KB FIFO.
                                                                 0x9 = 6.0 KB FIFO.
                                                                 0xA = 8.0 KB FIFO.
                                                                 0xB = 16.0 KB FIFO. */
        uint64_t base                  : 6;  /**< [  9:  4](RO/H) The base address in 512-byte blocks of the DMA engine FIFO. */
        uint64_t reserved_10_31        : 22;
        uint64_t compblks              : 6;  /**< [ 37: 32](RO/H) Computed engine block size */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_engx_buf_s cn; */
} bdk_dpix_engx_buf_t;

static inline uint64_t BDK_DPIX_ENGX_BUF(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_ENGX_BUF(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=5)))
        return 0x86e000000880ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("DPIX_ENGX_BUF", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_ENGX_BUF(a,b) bdk_dpix_engx_buf_t
#define bustype_BDK_DPIX_ENGX_BUF(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_ENGX_BUF(a,b) "DPIX_ENGX_BUF"
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
        return 0x86e000000980ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_INFO_REG", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_INFO_REG(a) bdk_dpix_info_reg_t
#define bustype_BDK_DPIX_INFO_REG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_INFO_REG(a) "DPIX_INFO_REG"
#define busnum_BDK_DPIX_INFO_REG(a) (a)
#define arguments_BDK_DPIX_INFO_REG(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_int_reg
 *
 * DPI Interrupt Register
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
        uint64_t req_inull             : 1;  /**< [ 21: 21](R/W1C/H) Interrupt should be ignored. INTERNAL: The interrupt means that the DPI unit
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
        uint64_t req_inull             : 1;  /**< [ 21: 21](R/W1C/H) Interrupt should be ignored. INTERNAL: The interrupt means that the DPI unit
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
        return 0x86e000000008ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_INT_REG", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_INT_REG(a) bdk_dpix_int_reg_t
#define bustype_BDK_DPIX_INT_REG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_INT_REG(a) "DPIX_INT_REG"
#define busnum_BDK_DPIX_INT_REG(a) (a)
#define arguments_BDK_DPIX_INT_REG(a) (a),-1,-1,-1

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
        return 0x86e000000800ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("DPIX_NCBX_CFG", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_NCBX_CFG(a,b) bdk_dpix_ncbx_cfg_t
#define bustype_BDK_DPIX_NCBX_CFG(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_NCBX_CFG(a,b) "DPIX_NCBX_CFG"
#define busnum_BDK_DPIX_NCBX_CFG(a,b) (a)
#define arguments_BDK_DPIX_NCBX_CFG(a,b) (a),(b),-1,-1

/**
 * Register (NCB) dpi#_pint_info
 *
 * DPI Packet Interrupt Information Register
 * This register provides DPI packet interrupt information.
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_pint_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t iinfo                 : 6;  /**< [ 13:  8](RO/H) Packet instruction doorbell count overflow information. */
        uint64_t reserved_6_7          : 2;
        uint64_t sinfo                 : 6;  /**< [  5:  0](RO/H) Packet scatter list doorbell count overflow information. */
#else /* Word 0 - Little Endian */
        uint64_t sinfo                 : 6;  /**< [  5:  0](RO/H) Packet scatter list doorbell count overflow information. */
        uint64_t reserved_6_7          : 2;
        uint64_t iinfo                 : 6;  /**< [ 13:  8](RO/H) Packet instruction doorbell count overflow information. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_pint_info_s cn; */
} bdk_dpix_pint_info_t;

static inline uint64_t BDK_DPIX_PINT_INFO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_PINT_INFO(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000000830ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_PINT_INFO", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_PINT_INFO(a) bdk_dpix_pint_info_t
#define bustype_BDK_DPIX_PINT_INFO(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_PINT_INFO(a) "DPIX_PINT_INFO"
#define busnum_BDK_DPIX_PINT_INFO(a) (a)
#define arguments_BDK_DPIX_PINT_INFO(a) (a),-1,-1,-1

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
        return 0x86e000000078ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_PKT_ERR_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_PKT_ERR_RSP(a) bdk_dpix_pkt_err_rsp_t
#define bustype_BDK_DPIX_PKT_ERR_RSP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_PKT_ERR_RSP(a) "DPIX_PKT_ERR_RSP"
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
                                                                 processing instructions if DPI(0)_REQ_ERR_RSP_EN[EN] is set. */
#else /* Word 0 - Little Endian */
        uint64_t qerr                  : 8;  /**< [  7:  0](R/W1C/H) Indicates which instruction queue received an ErrorResponse from the I/O subsystem.
                                                                 Software must clear the bit before the corresponding instruction queue will continue
                                                                 processing instructions if DPI(0)_REQ_ERR_RSP_EN[EN] is set. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_req_err_rsp_s cn; */
} bdk_dpix_req_err_rsp_t;

static inline uint64_t BDK_DPIX_REQ_ERR_RSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_REQ_ERR_RSP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000000058ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_REQ_ERR_RSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_REQ_ERR_RSP(a) bdk_dpix_req_err_rsp_t
#define bustype_BDK_DPIX_REQ_ERR_RSP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_REQ_ERR_RSP(a) "DPIX_REQ_ERR_RSP"
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
        return 0x86e000000068ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_REQ_ERR_RSP_EN", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_REQ_ERR_RSP_EN(a) bdk_dpix_req_err_rsp_en_t
#define bustype_BDK_DPIX_REQ_ERR_RSP_EN(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_REQ_ERR_RSP_EN(a) "DPIX_REQ_ERR_RSP_EN"
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
        return 0x86e000000060ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_REQ_ERR_RST", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_REQ_ERR_RST(a) bdk_dpix_req_err_rst_t
#define bustype_BDK_DPIX_REQ_ERR_RST(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_REQ_ERR_RST(a) "DPIX_REQ_ERR_RST"
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
        return 0x86e000000070ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_REQ_ERR_RST_EN", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_REQ_ERR_RST_EN(a) bdk_dpix_req_err_rst_en_t
#define bustype_BDK_DPIX_REQ_ERR_RST_EN(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_REQ_ERR_RST_EN(a) "DPIX_REQ_ERR_RST_EN"
#define busnum_BDK_DPIX_REQ_ERR_RST_EN(a) (a)
#define arguments_BDK_DPIX_REQ_ERR_RST_EN(a) (a),-1,-1,-1

/**
 * Register (NCB) dpi#_req_err_skip_comp
 *
 * INTERNAL: DPI Instruction Queue Skip Completion Register
 */
typedef union
{
    uint64_t u;
    struct bdk_dpix_req_err_skip_comp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t en_rst                : 8;  /**< [ 23: 16](RAZ) Reserved. */
        uint64_t reserved_8_15         : 8;
        uint64_t en_rsp                : 8;  /**< [  7:  0](R/W/H) Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t en_rsp                : 8;  /**< [  7:  0](R/W/H) Reserved. */
        uint64_t reserved_8_15         : 8;
        uint64_t en_rst                : 8;  /**< [ 23: 16](RAZ) Reserved. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_req_err_skip_comp_s cn; */
} bdk_dpix_req_err_skip_comp_t;

static inline uint64_t BDK_DPIX_REQ_ERR_SKIP_COMP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_REQ_ERR_SKIP_COMP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86e000000838ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_REQ_ERR_SKIP_COMP", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_REQ_ERR_SKIP_COMP(a) bdk_dpix_req_err_skip_comp_t
#define bustype_BDK_DPIX_REQ_ERR_SKIP_COMP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_REQ_ERR_SKIP_COMP(a) "DPIX_REQ_ERR_SKIP_COMP"
#define busnum_BDK_DPIX_REQ_ERR_SKIP_COMP(a) (a)
#define arguments_BDK_DPIX_REQ_ERR_SKIP_COMP(a) (a),-1,-1,-1

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
        return 0x86e000000050ll + 0x10000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("DPIX_REQ_GBL_EN", 1, a, 0, 0, 0);
}

#define typedef_BDK_DPIX_REQ_GBL_EN(a) bdk_dpix_req_gbl_en_t
#define bustype_BDK_DPIX_REQ_GBL_EN(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_REQ_GBL_EN(a) "DPIX_REQ_GBL_EN"
#define busnum_BDK_DPIX_REQ_GBL_EN(a) (a)
#define arguments_BDK_DPIX_REQ_GBL_EN(a) (a),-1,-1,-1

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
        uint64_t reserved_17_19        : 3;
        uint64_t rd_mode               : 1;  /**< [ 16: 16](R/W) Read mode.
                                                                 0 = Exact read mode. The hardware reads on a four-byte granularity. In this mode, the
                                                                 hardware may break a given read into 3 operations to satisfy DPI rules.
                                                                 1 = Block mode. The hardware reads more data than requested in order to minimize the
                                                                 number of operations necessary to complete the operation. The memory region must be memory
                                                                 like. */
        uint64_t reserved_15           : 1;
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
        uint64_t reserved_5_6          : 2;
        uint64_t mps                   : 1;  /**< [  4:  4](R/W) Maximum payload size.
                                                                 0 = 128B.
                                                                 1 = 256B.

                                                                 The MPS size must not exceed the size selected by PCIE*_CFG030[MPS]. */
        uint64_t mrrs_lim              : 1;  /**< [  3:  3](R/W) MAC memory space read requests cannot cross the (naturally-aligned) MRRS boundary.

                                                                 When clear, DPI is allowed to issue a MAC memory-space read that crosses the naturally-
                                                                 aligned boundary of size defined by MRRS. (DPI will still only cross the boundary when it
                                                                 would eliminate a read by doing so.)

                                                                 When set, DPI will never issue a MAC memory space read that crosses the naturally-aligned
                                                                 boundary of size defined by MRRS. */
        uint64_t reserved_2            : 1;
        uint64_t mrrs                  : 2;  /**< [  1:  0](R/W) Maximum read-request size.
                                                                 0x0 = 128B.
                                                                 0x1 = 256B.
                                                                 0x2 = 512B.
                                                                 0x3 = 1024B.

                                                                 The MRRS size must not exceed the size selected by PCIE*_CFG030[MRRS]. */
#else /* Word 0 - Little Endian */
        uint64_t mrrs                  : 2;  /**< [  1:  0](R/W) Maximum read-request size.
                                                                 0x0 = 128B.
                                                                 0x1 = 256B.
                                                                 0x2 = 512B.
                                                                 0x3 = 1024B.

                                                                 The MRRS size must not exceed the size selected by PCIE*_CFG030[MRRS]. */
        uint64_t reserved_2            : 1;
        uint64_t mrrs_lim              : 1;  /**< [  3:  3](R/W) MAC memory space read requests cannot cross the (naturally-aligned) MRRS boundary.

                                                                 When clear, DPI is allowed to issue a MAC memory-space read that crosses the naturally-
                                                                 aligned boundary of size defined by MRRS. (DPI will still only cross the boundary when it
                                                                 would eliminate a read by doing so.)

                                                                 When set, DPI will never issue a MAC memory space read that crosses the naturally-aligned
                                                                 boundary of size defined by MRRS. */
        uint64_t mps                   : 1;  /**< [  4:  4](R/W) Maximum payload size.
                                                                 0 = 128B.
                                                                 1 = 256B.

                                                                 The MPS size must not exceed the size selected by PCIE*_CFG030[MPS]. */
        uint64_t reserved_5_6          : 2;
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
        uint64_t reserved_15           : 1;
        uint64_t rd_mode               : 1;  /**< [ 16: 16](R/W) Read mode.
                                                                 0 = Exact read mode. The hardware reads on a four-byte granularity. In this mode, the
                                                                 hardware may break a given read into 3 operations to satisfy DPI rules.
                                                                 1 = Block mode. The hardware reads more data than requested in order to minimize the
                                                                 number of operations necessary to complete the operation. The memory region must be memory
                                                                 like. */
        uint64_t reserved_17_19        : 3;
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
        return 0x86e000000900ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3);
    __bdk_csr_fatal("DPIX_SLI_PRTX_CFG", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_SLI_PRTX_CFG(a,b) bdk_dpix_sli_prtx_cfg_t
#define bustype_BDK_DPIX_SLI_PRTX_CFG(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_SLI_PRTX_CFG(a,b) "DPIX_SLI_PRTX_CFG"
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
        return 0x86e000000920ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3);
    __bdk_csr_fatal("DPIX_SLI_PRTX_ERR", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_SLI_PRTX_ERR(a,b) bdk_dpix_sli_prtx_err_t
#define bustype_BDK_DPIX_SLI_PRTX_ERR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_SLI_PRTX_ERR(a,b) "DPIX_SLI_PRTX_ERR"
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
        uint64_t pvf                   : 16; /**< [ 31: 16](RO/H) Physical/Virtual function that caused the ErrorResponse. DPI_DMA_FUNC_SEL_S format. */
        uint64_t reserved_9_15         : 7;
        uint64_t lock                  : 1;  /**< [  8:  8](RO/H) DPI()_SLI_PRT()_ERR and DPI()_SLI_PRT()_ERR_INFO have captured and locked contents.
                                                                 When CNXXXX first detects an ErrorResponse, the TYPE, REQQ, and ADDR of the error is saved
                                                                 and an internal lock state is set so the data associated with the initial error is
                                                                 preserved.

                                                                 Subsequent ErrorResponses will optionally raise an interrupt, but will not modify the
                                                                 TYPE, REQQ, or ADDR fields until the internal lock state is cleared.

                                                                 Software can clear the internal lock state by writing a 1 to the appropriate bit in either
                                                                 DPI()_REQ_ERR_RSP or DPI()_PKT_ERR_RSP depending on the TYPE field. Once the internal lock
                                                                 state is cleared, the next ErrorResponse will set the TYPE, REQQ, and ADDR for the new
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

                                                                 Subsequent ErrorResponses will optionally raise an interrupt, but will not modify the
                                                                 TYPE, REQQ, or ADDR fields until the internal lock state is cleared.

                                                                 Software can clear the internal lock state by writing a 1 to the appropriate bit in either
                                                                 DPI()_REQ_ERR_RSP or DPI()_PKT_ERR_RSP depending on the TYPE field. Once the internal lock
                                                                 state is cleared, the next ErrorResponse will set the TYPE, REQQ, and ADDR for the new
                                                                 transaction. */
        uint64_t reserved_9_15         : 7;
        uint64_t pvf                   : 16; /**< [ 31: 16](RO/H) Physical/Virtual function that caused the ErrorResponse. DPI_DMA_FUNC_SEL_S format. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dpix_sli_prtx_err_info_s cn; */
} bdk_dpix_sli_prtx_err_info_t;

static inline uint64_t BDK_DPIX_SLI_PRTX_ERR_INFO(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DPIX_SLI_PRTX_ERR_INFO(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a==0) && (b<=3)))
        return 0x86e000000940ll + 0x10000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3);
    __bdk_csr_fatal("DPIX_SLI_PRTX_ERR_INFO", 2, a, b, 0, 0);
}

#define typedef_BDK_DPIX_SLI_PRTX_ERR_INFO(a,b) bdk_dpix_sli_prtx_err_info_t
#define bustype_BDK_DPIX_SLI_PRTX_ERR_INFO(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DPIX_SLI_PRTX_ERR_INFO(a,b) "DPIX_SLI_PRTX_ERR_INFO"
#define busnum_BDK_DPIX_SLI_PRTX_ERR_INFO(a,b) (a)
#define arguments_BDK_DPIX_SLI_PRTX_ERR_INFO(a,b) (a),(b),-1,-1

#endif /* __BDK_CSRS_DPI_H__ */
