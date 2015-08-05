#ifndef __BDK_CSRS_DDF_H__
#define __BDK_CSRS_DDF_H__
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
 * Cavium DDF.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration ddf_op_e
 *
 * DDF Instruction Operation Enumeration
 * Enumerates the values of DDF_INST_FIND_S[OP]/DDF_INST_MATCH_S[OP].
 */
#define BDK_DDF_OP_E_FABS_SET (0x18) /**< Filter set data at absolute location. */
#define BDK_DDF_OP_E_FEMPTY_INS (0x1f) /**< Filter locate empty location and insert. */
#define BDK_DDF_OP_E_FIND (0x10) /**< Filter find key and return location. */
#define BDK_DDF_OP_E_FIND_DEL (0x13) /**< Filter find key and if found, delete. */
#define BDK_DDF_OP_E_FIND_INS (0x12) /**< Filter find key and if not found, insert. */
#define BDK_DDF_OP_E_FIND_SET (0x11) /**< Filter find key and if found, set data. */
#define BDK_DDF_OP_E_MATCH (0x20) /**< Record match on key and return location. */
#define BDK_DDF_OP_E_MATCH_DEL (0x23) /**< Record match on key and if found, delete. */
#define BDK_DDF_OP_E_MATCH_INS (0x22) /**< Record match on key and if not found, insert. */
#define BDK_DDF_OP_E_MATCH_SET (0x21) /**< Record match on key and if found, set data. */
#define BDK_DDF_OP_E_NOP (0) /**< No operation other then optionally a SYNC. */
#define BDK_DDF_OP_E_RABS_SET (0x28) /**< Record set data at absolute location. */
#define BDK_DDF_OP_E_REMPTY_INS (0x2f) /**< Record locate empty location and insert. */

/**
 * Enumeration ddf_res_type_e
 *
 * DDF Result Type Enumeration
 * Enumerates the values of DDF_RES_MATCH_S[RES_TYPE] and DDF_RES_FIND_S[RES_TYPE].
 */
#define BDK_DDF_RES_TYPE_E_FIND (1) /**< The structure is a DDF_RES_FIND_S. */
#define BDK_DDF_RES_TYPE_E_MATCH (2) /**< The structure is a DDF_RES_MATCH_S. */
#define BDK_DDF_RES_TYPE_E_NOP (0) /**< Reserved. */

/**
 * Enumeration ddf_pf_int_vec_e
 *
 * DDF PF MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_DDF_PF_INT_VEC_E_ECC0 (0) /**< See interrupt clears DDF_PF_ECC0_INT,
                                       interrupt sets DDF_PF_ECC0_INT_W1S,
                                       enable clears DDF_PF_ECC0_ENA_W1C,
                                       and enable sets DDF_PF_ECC0_ENA_W1S. */
#define BDK_DDF_PF_INT_VEC_E_MBOXX(a) (1 + (a)) /**< (0)See interrupt clears DDF_PF_MBOX_INT(0),
                                       interrupt sets DDF_PF_MBOX_INT_W1S(0),
                                       enable clears DDF_PF_MBOX_ENA_W1C(0),
                                       and enable sets DDF_PF_MBOX_ENA_W1S(0). */

/**
 * Enumeration ddf_comp_e
 *
 * DDF Completion Enumeration
 * Enumerates the values of DDF_RES_FIND_S/DDF_RES_MATCH_S[COMPCODE].
 */
#define BDK_DDF_COMP_E_FAULT (2) /**< Memory fault was detected reading/writing data related to this instruction.  The
                                       instruction may have been partially completed, and as such the result and record state is
                                       now undefined. */
#define BDK_DDF_COMP_E_FULL (3) /**< Insert operation not completed due to no space (nests all full, and if [VICTEN]=1 the
                                       victim is full). */
#define BDK_DDF_COMP_E_GOOD (1) /**< Operation completed. */
#define BDK_DDF_COMP_E_NOTDONE (0) /**< The COMPCODE value of zero is not written by hardware, but may be used by
                                       software to indicate the DDF_RES_FIND_S/DDF_RES_MATCH_S has not yet been
                                       updated by hardware. */

/**
 * Enumeration ddf_bar_e
 *
 * DDF Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_DDF_BAR_E_DDF_PF_BAR0 (0x809000000000ll) /**< Base address for physical function standard registers. */
#define BDK_DDF_BAR_E_DDF_PF_BAR4 (0x809010000000ll) /**< Base address for physical function MSI-X registers. */
#define BDK_DDF_BAR_E_DDF_VFX_BAR0(a) (0x809020000000ll + 0x100000ll * (a)) /**< (0..31)Base address for virtual function standard registers. */
#define BDK_DDF_BAR_E_DDF_VFX_BAR4(a) (0x809030000000ll + 0x100000ll * (a)) /**< (0..31)Base address for virtual function MSI-X registers. */

/**
 * Enumeration ddf_rams_e
 *
 * DDF RAM Field Enumeration
 * Enumerates the relative bit positions within DDF_PF_ECC0_CTL[CDIS].
 */
#define BDK_DDF_RAMS_E_TBD (0) /**< Bit position for TBD. */

/**
 * Enumeration ddf_vf_int_vec_e
 *
 * DDF VF MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_DDF_VF_INT_VEC_E_DONE (1) /**< See interrupt clears DDF_VQ(0..31)_DONE_INT_W1C,
                                       interrupt sets DDF_VQ(0..31)_DONE_INT_W1S,
                                       enable clears DDF_VQ(0..31)_DONE_ENA_W1C
                                       and enable sets DDF_VQ(0..31)_DONE_ENA_W1S. */
#define BDK_DDF_VF_INT_VEC_E_MISC (0) /**< See interrupt clears DDF_VQ(0..31)_MISC_INT,
                                       interrupt sets DDF_VQ(0..31)_MISC_INT_W1S,
                                       enable clears DDF_VQ(0..31)_MISC_ENA_W1C
                                       and enable sets DDF_VQ(0..31)_MISC_ENA_W1S. */

/**
 * Structure ddf_res_find_s
 *
 * DDF Result of Filter Find Structure
 * This structure specifies the result structure written by DDF after it completes a
 * DDF_INST_FIND_S. Each instruction completion produces exactly one result structure
 *
 * DDF always writes the first 16 bytes of this structure.  If DDF_INST_MATCH_S[RR] is
 * set DDF will update an entire cache line, but only write valid data to the fields
 * specified depending on the required amount of [RDATA0]..[3] data.
 *
 * INTERNAL: When [RR] is set it can use a full-cacheline write with fewer than
 * a cache-lines worth of NCB data ticks.
 */
union bdk_ddf_res_find_s
{
    uint64_t u[6];
    struct bdk_ddf_res_find_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t hitway                : 8;  /**< [ 31: 24] Hit ways. Bitmask of which ways in which the item was found. For insert/deletes a single
                                                                 bit will be set.

                                                                 Unpredictable for DDF_OP_E::FABS_SET. */
        uint64_t hitvict               : 1;  /**< [ 23: 23] Hit victim. Set if item was found, inserted, or deleted as a victim, else clear.

                                                                 Unpredictable for DDF_OP_E::FABS_SET. */
        uint64_t hits                  : 1;  /**< [ 22: 22] Hit secondary. Set if item was found, inserted, or deleted at the secondary bucket
                                                                 location, else clear.

                                                                 Unpredictable for DDF_OP_E::FABS_SET. */
        uint64_t hitp                  : 1;  /**< [ 21: 21] Hit primary. Set if item was found, inserted, or deleted at the primary bucket location,
                                                                 else clear.

                                                                 Unpredictable for DDF_OP_E::FABS_SET. */
        uint64_t reserved_17_20        : 4;
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt. This bit is copied from the corrresponding instruction's
                                                                 DDF_INST_FIND_S[DONEINT]. */
        uint64_t res_type              : 8;  /**< [ 15:  8] Type of response structure, enumerated by DDF_RES_TYPE_E. */
        uint64_t compcode              : 8;  /**< [  7:  0] Indicates completion/error status of the DDF coprocessor for the
                                                                 associated instruction, as enumerated by DDF_COMP_E. Core
                                                                 software may write the memory location containing [COMPCODE] to 0x0
                                                                 before ringing the doorbell, and then poll for completion by
                                                                 checking for a non-zero value.

                                                                 Once the core observes a non-zero [COMPCODE] value in this case, the DDF
                                                                 coprocessor will have also completed L2/DRAM write operations for all context,
                                                                 output stream, and result data. */
#else /* Word 0 - Little Endian */
        uint64_t compcode              : 8;  /**< [  7:  0] Indicates completion/error status of the DDF coprocessor for the
                                                                 associated instruction, as enumerated by DDF_COMP_E. Core
                                                                 software may write the memory location containing [COMPCODE] to 0x0
                                                                 before ringing the doorbell, and then poll for completion by
                                                                 checking for a non-zero value.

                                                                 Once the core observes a non-zero [COMPCODE] value in this case, the DDF
                                                                 coprocessor will have also completed L2/DRAM write operations for all context,
                                                                 output stream, and result data. */
        uint64_t res_type              : 8;  /**< [ 15:  8] Type of response structure, enumerated by DDF_RES_TYPE_E. */
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt. This bit is copied from the corrresponding instruction's
                                                                 DDF_INST_FIND_S[DONEINT]. */
        uint64_t reserved_17_20        : 4;
        uint64_t hitp                  : 1;  /**< [ 21: 21] Hit primary. Set if item was found, inserted, or deleted at the primary bucket location,
                                                                 else clear.

                                                                 Unpredictable for DDF_OP_E::FABS_SET. */
        uint64_t hits                  : 1;  /**< [ 22: 22] Hit secondary. Set if item was found, inserted, or deleted at the secondary bucket
                                                                 location, else clear.

                                                                 Unpredictable for DDF_OP_E::FABS_SET. */
        uint64_t hitvict               : 1;  /**< [ 23: 23] Hit victim. Set if item was found, inserted, or deleted as a victim, else clear.

                                                                 Unpredictable for DDF_OP_E::FABS_SET. */
        uint64_t hitway                : 8;  /**< [ 31: 24] Hit ways. Bitmask of which ways in which the item was found. For insert/deletes a single
                                                                 bit will be set.

                                                                 Unpredictable for DDF_OP_E::FABS_SET. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_112_127      : 16;
        uint64_t sbkt                  : 8;  /**< [111:104] Calculated secondary bucket number. */
        uint64_t pbkt                  : 8;  /**< [103: 96] Calculated primary bucket number. */
        uint64_t rank                  : 32; /**< [ 95: 64] Calculated rank number. If DDF_INST_FIND_S[RANK_ABS] was set, unpredictable. */
#else /* Word 1 - Little Endian */
        uint64_t rank                  : 32; /**< [ 95: 64] Calculated rank number. If DDF_INST_FIND_S[RANK_ABS] was set, unpredictable. */
        uint64_t pbkt                  : 8;  /**< [103: 96] Calculated primary bucket number. */
        uint64_t sbkt                  : 8;  /**< [111:104] Calculated secondary bucket number. */
        uint64_t reserved_112_127      : 16;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t rdata0                : 64; /**< [191:128] Key or opaque data bytes read from the nest.
                                                                 If multiple hits resulted it is unpredictable which is returned.
                                                                 If [HITP] or [HITS] is set, the data read from the nest before any updates take place.
                                                                 If [HITP] or [HITS] is clear, unpredictable. */
#else /* Word 2 - Little Endian */
        uint64_t rdata0                : 64; /**< [191:128] Key or opaque data bytes read from the nest.
                                                                 If multiple hits resulted it is unpredictable which is returned.
                                                                 If [HITP] or [HITS] is set, the data read from the nest before any updates take place.
                                                                 If [HITP] or [HITS] is clear, unpredictable. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t rdata1                : 64; /**< [255:192] Extension of [RDATA0]. */
#else /* Word 3 - Little Endian */
        uint64_t rdata1                : 64; /**< [255:192] Extension of [RDATA0]. */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t rdata2                : 64; /**< [319:256] Extension of [RDATA0]. */
#else /* Word 4 - Little Endian */
        uint64_t rdata2                : 64; /**< [319:256] Extension of [RDATA0]. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t rdata3                : 64; /**< [383:320] Extension of [RDATA0]. */
#else /* Word 5 - Little Endian */
        uint64_t rdata3                : 64; /**< [383:320] Extension of [RDATA0]. */
#endif /* Word 5 - End */
    } s;
    /* struct bdk_ddf_res_find_s_s cn; */
};

/**
 * Structure ddf_inst_match_s
 *
 * DDF Record Match Instruction Structure
 * This structure specifies the record match instruction.
 */
union bdk_ddf_inst_match_s
{
    uint64_t u[16];
    struct bdk_ddf_inst_match_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nrec                  : 16; /**< [ 63: 48] Number of records to compare.
                                                                 Typically the same as the number of records in a record block.
                                                                 If 0x0, compare nothing. */
        uint64_t recszm1               : 8;  /**< [ 47: 40] Record size in bytes minus one.  Number of bytes must be multiple of 4
                                                                 and are not required to be powers of 2.
                                                                 0x3 = 4 bytes.
                                                                 0x7 = 8 bytes.
                                                                 0xF = 16 bytes.
                                                                 0x13 = 20 bytes.
                                                                 0x3F = 64 bytes.

                                                                 INTERNAL: Must support non-power-of-2. */
        uint64_t reserved_22_39        : 18;
        uint64_t rr                    : 1;  /**< [ 21: 21] Return result. If set, include key data in DDF_RES_MATCH_S. */
        uint64_t cacs                  : 1;  /**< [ 20: 20] L2 cache filter data. If set, when reading the header allocate into L2 cache. If
                                                                 clear, do not allocate if not already in L2 cache. */
        uint64_t cach                  : 1;  /**< [ 19: 19] L2 cache header. If set, when reading the header allocate into L2 cache.
                                                                 If clear, do not allocate if not already in L2 cache. */
        uint64_t sync                  : 1;  /**< [ 18: 18] See DDF_INST_FIND_S[SYNC]. */
        uint64_t gang                  : 1;  /**< [ 17: 17] See DDF_INST_FIND_S[GANG]. */
        uint64_t doneint               : 1;  /**< [ 16: 16] See DDF_INST_FIND_S[DONEINT]. */
        uint64_t qwords                : 8;  /**< [ 15:  8] See DDF_INST_FIND_S[QWORDS]. */
        uint64_t op                    : 8;  /**< [  7:  0] See DDF_INST_FIND_S[OP]. */
#else /* Word 0 - Little Endian */
        uint64_t op                    : 8;  /**< [  7:  0] See DDF_INST_FIND_S[OP]. */
        uint64_t qwords                : 8;  /**< [ 15:  8] See DDF_INST_FIND_S[QWORDS]. */
        uint64_t doneint               : 1;  /**< [ 16: 16] See DDF_INST_FIND_S[DONEINT]. */
        uint64_t gang                  : 1;  /**< [ 17: 17] See DDF_INST_FIND_S[GANG]. */
        uint64_t sync                  : 1;  /**< [ 18: 18] See DDF_INST_FIND_S[SYNC]. */
        uint64_t cach                  : 1;  /**< [ 19: 19] L2 cache header. If set, when reading the header allocate into L2 cache.
                                                                 If clear, do not allocate if not already in L2 cache. */
        uint64_t cacs                  : 1;  /**< [ 20: 20] L2 cache filter data. If set, when reading the header allocate into L2 cache. If
                                                                 clear, do not allocate if not already in L2 cache. */
        uint64_t rr                    : 1;  /**< [ 21: 21] Return result. If set, include key data in DDF_RES_MATCH_S. */
        uint64_t reserved_22_39        : 18;
        uint64_t recszm1               : 8;  /**< [ 47: 40] Record size in bytes minus one.  Number of bytes must be multiple of 4
                                                                 and are not required to be powers of 2.
                                                                 0x3 = 4 bytes.
                                                                 0x7 = 8 bytes.
                                                                 0xF = 16 bytes.
                                                                 0x13 = 20 bytes.
                                                                 0x3F = 64 bytes.

                                                                 INTERNAL: Must support non-power-of-2. */
        uint64_t nrec                  : 16; /**< [ 63: 48] Number of records to compare.
                                                                 Typically the same as the number of records in a record block.
                                                                 If 0x0, compare nothing. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_113_127      : 15;
        uint64_t res_addr              : 49; /**< [112: 64] Result address.
                                                                 If non-zero, specifies where to write DDF_RES_MATCH_S.
                                                                 If zero, no result structure will be written.

                                                                 If [RR] is clear, address must be 16-byte aligned.
                                                                 If [RR] is set, address must be 128-byte aligned. */
#else /* Word 1 - Little Endian */
        uint64_t res_addr              : 49; /**< [112: 64] Result address.
                                                                 If non-zero, specifies where to write DDF_RES_MATCH_S.
                                                                 If zero, no result structure will be written.

                                                                 If [RR] is clear, address must be 16-byte aligned.
                                                                 If [RR] is set, address must be 128-byte aligned. */
        uint64_t reserved_113_127      : 15;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_172_191      : 20;
        uint64_t grp                   : 10; /**< [171:162] See DDF_INST_FIND_S[GRP]. */
        uint64_t tt                    : 2;  /**< [161:160] See DDF_INST_FIND_S[TT]. */
        uint64_t tag                   : 32; /**< [159:128] See DDF_INST_FIND_S[TAG]. */
#else /* Word 2 - Little Endian */
        uint64_t tag                   : 32; /**< [159:128] See DDF_INST_FIND_S[TAG]. */
        uint64_t tt                    : 2;  /**< [161:160] See DDF_INST_FIND_S[TT]. */
        uint64_t grp                   : 10; /**< [171:162] See DDF_INST_FIND_S[GRP]. */
        uint64_t reserved_172_191      : 20;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_241_255      : 15;
        uint64_t wq_ptr                : 49; /**< [240:192] See DDF_INST_FIND_S[WQ_PTR]. */
#else /* Word 3 - Little Endian */
        uint64_t wq_ptr                : 49; /**< [240:192] See DDF_INST_FIND_S[WQ_PTR]. */
        uint64_t reserved_241_255      : 15;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t reserved_305_319      : 15;
        uint64_t rb_addr               : 49; /**< [304:256] Record block pointer.
                                                                 For RABS_SET instruction, pointer to data to change.
                                                                 Must be aligned to DDF_INST_MATCH_S[RECSZM1]+1 bytes.
                                                                 If 0x0, this way is not used, and will never match. */
#else /* Word 4 - Little Endian */
        uint64_t rb_addr               : 49; /**< [304:256] Record block pointer.
                                                                 For RABS_SET instruction, pointer to data to change.
                                                                 Must be aligned to DDF_INST_MATCH_S[RECSZM1]+1 bytes.
                                                                 If 0x0, this way is not used, and will never match. */
        uint64_t reserved_305_319      : 15;
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t reserved_320_383      : 64;
#else /* Word 5 - Little Endian */
        uint64_t reserved_320_383      : 64;
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t set_bdis              : 64; /**< [447:384] Set byte disables. One bit corresponds to each [KEYDATA0]..[KEYDATA7] byte. If
                                                                 that bit is clear the corresponding byte will be set in the record. Only bits
                                                                 SET_BDIS<RECSZM1:0> have an effect. */
#else /* Word 6 - Little Endian */
        uint64_t set_bdis              : 64; /**< [447:384] Set byte disables. One bit corresponds to each [KEYDATA0]..[KEYDATA7] byte. If
                                                                 that bit is clear the corresponding byte will be set in the record. Only bits
                                                                 SET_BDIS<RECSZM1:0> have an effect. */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t cmp_bdis              : 64; /**< [511:448] Compare byte disables. One bit corresponds to each [KEYDATA0]..[KEYDATA7]
                                                                 byte. If that clear is set the corresponding byte must be identical to that byte
                                                                 in the record to be considered a match. Only bits CMP_BDIS<RECSZM1:0> have an
                                                                 effect. */
#else /* Word 7 - Little Endian */
        uint64_t cmp_bdis              : 64; /**< [511:448] Compare byte disables. One bit corresponds to each [KEYDATA0]..[KEYDATA7]
                                                                 byte. If that clear is set the corresponding byte must be identical to that byte
                                                                 in the record to be considered a match. Only bits CMP_BDIS<RECSZM1:0> have an
                                                                 effect. */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t keydata0              : 64; /**< [575:512] Key or opaque data bytes. */
#else /* Word 8 - Little Endian */
        uint64_t keydata0              : 64; /**< [575:512] Key or opaque data bytes. */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t keydata1              : 64; /**< [639:576] Extension of [KEYDATA0]. */
#else /* Word 9 - Little Endian */
        uint64_t keydata1              : 64; /**< [639:576] Extension of [KEYDATA0]. */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t keydata2              : 64; /**< [703:640] Extension of [KEYDATA0]. */
#else /* Word 10 - Little Endian */
        uint64_t keydata2              : 64; /**< [703:640] Extension of [KEYDATA0]. */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t keydata3              : 64; /**< [767:704] Extension of [KEYDATA0]. */
#else /* Word 11 - Little Endian */
        uint64_t keydata3              : 64; /**< [767:704] Extension of [KEYDATA0]. */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t keydata4              : 64; /**< [831:768] Extension of [KEYDATA0]. */
#else /* Word 12 - Little Endian */
        uint64_t keydata4              : 64; /**< [831:768] Extension of [KEYDATA0]. */
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t keydata5              : 64; /**< [895:832] Extension of [KEYDATA0]. */
#else /* Word 13 - Little Endian */
        uint64_t keydata5              : 64; /**< [895:832] Extension of [KEYDATA0]. */
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t keydata6              : 64; /**< [959:896] Extension of [KEYDATA0]. */
#else /* Word 14 - Little Endian */
        uint64_t keydata6              : 64; /**< [959:896] Extension of [KEYDATA0]. */
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t keydata7              : 64; /**< [1023:960] Extension of [KEYDATA0]. */
#else /* Word 15 - Little Endian */
        uint64_t keydata7              : 64; /**< [1023:960] Extension of [KEYDATA0]. */
#endif /* Word 15 - End */
    } s;
    struct bdk_ddf_inst_match_s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nrec                  : 16; /**< [ 63: 48] Number of records to compare.
                                                                 Typically the same as the number of records in a record block.
                                                                 If 0x0, compare nothing. */
        uint64_t recszm1               : 8;  /**< [ 47: 40] Record size in bytes minus one.  Number of bytes must be multiple of 4
                                                                 and are not required to be powers of 2.
                                                                 0x3 = 4 bytes.
                                                                 0x7 = 8 bytes.
                                                                 0xF = 16 bytes.
                                                                 0x13 = 20 bytes.
                                                                 0x3F = 64 bytes.

                                                                 INTERNAL: Must support non-power-of-2. */
        uint64_t reserved_32_39        : 8;
        uint64_t reserved_22_31        : 10;
        uint64_t rr                    : 1;  /**< [ 21: 21] Return result. If set, include key data in DDF_RES_MATCH_S. */
        uint64_t cacs                  : 1;  /**< [ 20: 20] L2 cache filter data. If set, when reading the header allocate into L2 cache. If
                                                                 clear, do not allocate if not already in L2 cache. */
        uint64_t cach                  : 1;  /**< [ 19: 19] L2 cache header. If set, when reading the header allocate into L2 cache.
                                                                 If clear, do not allocate if not already in L2 cache. */
        uint64_t sync                  : 1;  /**< [ 18: 18] See DDF_INST_FIND_S[SYNC]. */
        uint64_t gang                  : 1;  /**< [ 17: 17] See DDF_INST_FIND_S[GANG]. */
        uint64_t doneint               : 1;  /**< [ 16: 16] See DDF_INST_FIND_S[DONEINT]. */
        uint64_t qwords                : 8;  /**< [ 15:  8] See DDF_INST_FIND_S[QWORDS]. */
        uint64_t op                    : 8;  /**< [  7:  0] See DDF_INST_FIND_S[OP]. */
#else /* Word 0 - Little Endian */
        uint64_t op                    : 8;  /**< [  7:  0] See DDF_INST_FIND_S[OP]. */
        uint64_t qwords                : 8;  /**< [ 15:  8] See DDF_INST_FIND_S[QWORDS]. */
        uint64_t doneint               : 1;  /**< [ 16: 16] See DDF_INST_FIND_S[DONEINT]. */
        uint64_t gang                  : 1;  /**< [ 17: 17] See DDF_INST_FIND_S[GANG]. */
        uint64_t sync                  : 1;  /**< [ 18: 18] See DDF_INST_FIND_S[SYNC]. */
        uint64_t cach                  : 1;  /**< [ 19: 19] L2 cache header. If set, when reading the header allocate into L2 cache.
                                                                 If clear, do not allocate if not already in L2 cache. */
        uint64_t cacs                  : 1;  /**< [ 20: 20] L2 cache filter data. If set, when reading the header allocate into L2 cache. If
                                                                 clear, do not allocate if not already in L2 cache. */
        uint64_t rr                    : 1;  /**< [ 21: 21] Return result. If set, include key data in DDF_RES_MATCH_S. */
        uint64_t reserved_22_31        : 10;
        uint64_t reserved_32_39        : 8;
        uint64_t recszm1               : 8;  /**< [ 47: 40] Record size in bytes minus one.  Number of bytes must be multiple of 4
                                                                 and are not required to be powers of 2.
                                                                 0x3 = 4 bytes.
                                                                 0x7 = 8 bytes.
                                                                 0xF = 16 bytes.
                                                                 0x13 = 20 bytes.
                                                                 0x3F = 64 bytes.

                                                                 INTERNAL: Must support non-power-of-2. */
        uint64_t nrec                  : 16; /**< [ 63: 48] Number of records to compare.
                                                                 Typically the same as the number of records in a record block.
                                                                 If 0x0, compare nothing. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_113_127      : 15;
        uint64_t res_addr              : 49; /**< [112: 64] Result address.
                                                                 If non-zero, specifies where to write DDF_RES_MATCH_S.
                                                                 If zero, no result structure will be written.

                                                                 If [RR] is clear, address must be 16-byte aligned.
                                                                 If [RR] is set, address must be 128-byte aligned. */
#else /* Word 1 - Little Endian */
        uint64_t res_addr              : 49; /**< [112: 64] Result address.
                                                                 If non-zero, specifies where to write DDF_RES_MATCH_S.
                                                                 If zero, no result structure will be written.

                                                                 If [RR] is clear, address must be 16-byte aligned.
                                                                 If [RR] is set, address must be 128-byte aligned. */
        uint64_t reserved_113_127      : 15;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_172_191      : 20;
        uint64_t grp                   : 10; /**< [171:162] See DDF_INST_FIND_S[GRP]. */
        uint64_t tt                    : 2;  /**< [161:160] See DDF_INST_FIND_S[TT]. */
        uint64_t tag                   : 32; /**< [159:128] See DDF_INST_FIND_S[TAG]. */
#else /* Word 2 - Little Endian */
        uint64_t tag                   : 32; /**< [159:128] See DDF_INST_FIND_S[TAG]. */
        uint64_t tt                    : 2;  /**< [161:160] See DDF_INST_FIND_S[TT]. */
        uint64_t grp                   : 10; /**< [171:162] See DDF_INST_FIND_S[GRP]. */
        uint64_t reserved_172_191      : 20;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_241_255      : 15;
        uint64_t wq_ptr                : 49; /**< [240:192] See DDF_INST_FIND_S[WQ_PTR]. */
#else /* Word 3 - Little Endian */
        uint64_t wq_ptr                : 49; /**< [240:192] See DDF_INST_FIND_S[WQ_PTR]. */
        uint64_t reserved_241_255      : 15;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t reserved_305_319      : 15;
        uint64_t rb_addr               : 49; /**< [304:256] Record block pointer.
                                                                 For RABS_SET instruction, pointer to data to change.
                                                                 Must be aligned to DDF_INST_MATCH_S[RECSZM1]+1 bytes.
                                                                 If 0x0, this way is not used, and will never match. */
#else /* Word 4 - Little Endian */
        uint64_t rb_addr               : 49; /**< [304:256] Record block pointer.
                                                                 For RABS_SET instruction, pointer to data to change.
                                                                 Must be aligned to DDF_INST_MATCH_S[RECSZM1]+1 bytes.
                                                                 If 0x0, this way is not used, and will never match. */
        uint64_t reserved_305_319      : 15;
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t reserved_320_383      : 64;
#else /* Word 5 - Little Endian */
        uint64_t reserved_320_383      : 64;
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t set_bdis              : 64; /**< [447:384] Set byte disables. One bit corresponds to each [KEYDATA0]..[KEYDATA7] byte. If
                                                                 that bit is clear the corresponding byte will be set in the record. Only bits
                                                                 SET_BDIS<RECSZM1:0> have an effect. */
#else /* Word 6 - Little Endian */
        uint64_t set_bdis              : 64; /**< [447:384] Set byte disables. One bit corresponds to each [KEYDATA0]..[KEYDATA7] byte. If
                                                                 that bit is clear the corresponding byte will be set in the record. Only bits
                                                                 SET_BDIS<RECSZM1:0> have an effect. */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t cmp_bdis              : 64; /**< [511:448] Compare byte disables. One bit corresponds to each [KEYDATA0]..[KEYDATA7]
                                                                 byte. If that clear is set the corresponding byte must be identical to that byte
                                                                 in the record to be considered a match. Only bits CMP_BDIS<RECSZM1:0> have an
                                                                 effect. */
#else /* Word 7 - Little Endian */
        uint64_t cmp_bdis              : 64; /**< [511:448] Compare byte disables. One bit corresponds to each [KEYDATA0]..[KEYDATA7]
                                                                 byte. If that clear is set the corresponding byte must be identical to that byte
                                                                 in the record to be considered a match. Only bits CMP_BDIS<RECSZM1:0> have an
                                                                 effect. */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t keydata0              : 64; /**< [575:512] Key or opaque data bytes. */
#else /* Word 8 - Little Endian */
        uint64_t keydata0              : 64; /**< [575:512] Key or opaque data bytes. */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t keydata1              : 64; /**< [639:576] Extension of [KEYDATA0]. */
#else /* Word 9 - Little Endian */
        uint64_t keydata1              : 64; /**< [639:576] Extension of [KEYDATA0]. */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t keydata2              : 64; /**< [703:640] Extension of [KEYDATA0]. */
#else /* Word 10 - Little Endian */
        uint64_t keydata2              : 64; /**< [703:640] Extension of [KEYDATA0]. */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t keydata3              : 64; /**< [767:704] Extension of [KEYDATA0]. */
#else /* Word 11 - Little Endian */
        uint64_t keydata3              : 64; /**< [767:704] Extension of [KEYDATA0]. */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t keydata4              : 64; /**< [831:768] Extension of [KEYDATA0]. */
#else /* Word 12 - Little Endian */
        uint64_t keydata4              : 64; /**< [831:768] Extension of [KEYDATA0]. */
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t keydata5              : 64; /**< [895:832] Extension of [KEYDATA0]. */
#else /* Word 13 - Little Endian */
        uint64_t keydata5              : 64; /**< [895:832] Extension of [KEYDATA0]. */
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t keydata6              : 64; /**< [959:896] Extension of [KEYDATA0]. */
#else /* Word 14 - Little Endian */
        uint64_t keydata6              : 64; /**< [959:896] Extension of [KEYDATA0]. */
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t keydata7              : 64; /**< [1023:960] Extension of [KEYDATA0]. */
#else /* Word 15 - Little Endian */
        uint64_t keydata7              : 64; /**< [1023:960] Extension of [KEYDATA0]. */
#endif /* Word 15 - End */
    } cn;
};

/**
 * Structure ddf_inst_find_s
 *
 * DDF Find Instruction Structure
 * This structure specifies the find instruction.
 */
union bdk_ddf_inst_find_s
{
    uint64_t u[16];
    struct bdk_ddf_inst_find_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t rank_abs              : 1;  /**< [ 55: 55] Absolute rank.
                                                                 0 = [HDR_ADDR] and [RANK_ADDR] point to rank 0, and the rank used is calculated using rank
                                                                 bits from the key.
                                                                 1 = [HDR_ADDR] and [RANK_ADDR] point to an absolute rank. */
        uint64_t victen                : 1;  /**< [ 54: 54] Victim enable.
                                                                 _ 0: No victim present in header, or do not operate on the victim.
                                                                 _ 1 and [OP]!=FABS_SET: Check for victim in filter header and put in to header
                                                                 on add for overflow.
                                                                 _ 1 and [OP]=FABS_SET: Modify the victim. */
        uint64_t nest                  : 2;  /**< [ 53: 52] Nest location. If [OP] = FABS_SET, which nest number in the bucket, otherwise
                                                                 reserved. */
        uint64_t way_abs               : 1;  /**< [ 51: 51] Way is absolute.
                                                                 0 = Search/delete from any way, insert into [WAY].
                                                                 1 = Search/insert/delete only in the way provided in [WAY]. */
        uint64_t way                   : 3;  /**< [ 50: 48] Which way number. If [OP] = FIND_INS or FEMPTY_INS or FABS_SET, or [WAY_ABS] is
                                                                 set, which way number, otherwise ignored. */
        uint64_t reserved_40_47        : 8;
        uint64_t pbkt                  : 8;  /**< [ 39: 32] Primary bucket number.
                                                                 For [OP] = FABS_SET, which bucket number, otherwise reserved. */
        uint64_t reserved_22_31        : 10;
        uint64_t rr                    : 1;  /**< [ 21: 21] Return result. If set, include key data in DDF_RES_FIND_S. */
        uint64_t cacs                  : 1;  /**< [ 20: 20] L2 cache filter data. If set, when reading the header allocate into L2 cache. If
                                                                 clear, do not allocate if not already in L2 cache. */
        uint64_t cach                  : 1;  /**< [ 19: 19] L2 cache header. If set, when reading the header allocate into L2 cache.
                                                                 If clear, do not allocate if not already in L2 cache. */
        uint64_t sync                  : 1;  /**< [ 18: 18] Synchronize. If set, insure all structures
                                                                 are written to memory before completing this instruction. */
        uint64_t gang                  : 1;  /**< [ 17: 17] Gang with next instruction. If set, a hint to hardware that this instruction's
                                                                 filter or match data need not be immediately written to memory, in the hope that
                                                                 the next instruction will access the same data. */
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt. When DONEINT is set and the instruction completes,
                                                                 DDF_VQ()_DONE[DONE] will be incremented. */
        uint64_t qwords                : 8;  /**< [ 15:  8] Number of 16-byte quadwords in request. Must be 1-16. If less than the size of
                                                                 this structure then structure elements described here are not read from memory
                                                                 and behave as if zero.

                                                                 INTERNAL: In hardware, push/pop zeros for (QWORDS..15) into the
                                                                 instruction queue.  As VQs are virtualized, DDF must not hang on invalid instructions. */
        uint64_t op                    : 8;  /**< [  7:  0] Operation to perform. Enumerated by DDF_OP_E. */
#else /* Word 0 - Little Endian */
        uint64_t op                    : 8;  /**< [  7:  0] Operation to perform. Enumerated by DDF_OP_E. */
        uint64_t qwords                : 8;  /**< [ 15:  8] Number of 16-byte quadwords in request. Must be 1-16. If less than the size of
                                                                 this structure then structure elements described here are not read from memory
                                                                 and behave as if zero.

                                                                 INTERNAL: In hardware, push/pop zeros for (QWORDS..15) into the
                                                                 instruction queue.  As VQs are virtualized, DDF must not hang on invalid instructions. */
        uint64_t doneint               : 1;  /**< [ 16: 16] Done interrupt. When DONEINT is set and the instruction completes,
                                                                 DDF_VQ()_DONE[DONE] will be incremented. */
        uint64_t gang                  : 1;  /**< [ 17: 17] Gang with next instruction. If set, a hint to hardware that this instruction's
                                                                 filter or match data need not be immediately written to memory, in the hope that
                                                                 the next instruction will access the same data. */
        uint64_t sync                  : 1;  /**< [ 18: 18] Synchronize. If set, insure all structures
                                                                 are written to memory before completing this instruction. */
        uint64_t cach                  : 1;  /**< [ 19: 19] L2 cache header. If set, when reading the header allocate into L2 cache.
                                                                 If clear, do not allocate if not already in L2 cache. */
        uint64_t cacs                  : 1;  /**< [ 20: 20] L2 cache filter data. If set, when reading the header allocate into L2 cache. If
                                                                 clear, do not allocate if not already in L2 cache. */
        uint64_t rr                    : 1;  /**< [ 21: 21] Return result. If set, include key data in DDF_RES_FIND_S. */
        uint64_t reserved_22_31        : 10;
        uint64_t pbkt                  : 8;  /**< [ 39: 32] Primary bucket number.
                                                                 For [OP] = FABS_SET, which bucket number, otherwise reserved. */
        uint64_t reserved_40_47        : 8;
        uint64_t way                   : 3;  /**< [ 50: 48] Which way number. If [OP] = FIND_INS or FEMPTY_INS or FABS_SET, or [WAY_ABS] is
                                                                 set, which way number, otherwise ignored. */
        uint64_t way_abs               : 1;  /**< [ 51: 51] Way is absolute.
                                                                 0 = Search/delete from any way, insert into [WAY].
                                                                 1 = Search/insert/delete only in the way provided in [WAY]. */
        uint64_t nest                  : 2;  /**< [ 53: 52] Nest location. If [OP] = FABS_SET, which nest number in the bucket, otherwise
                                                                 reserved. */
        uint64_t victen                : 1;  /**< [ 54: 54] Victim enable.
                                                                 _ 0: No victim present in header, or do not operate on the victim.
                                                                 _ 1 and [OP]!=FABS_SET: Check for victim in filter header and put in to header
                                                                 on add for overflow.
                                                                 _ 1 and [OP]=FABS_SET: Modify the victim. */
        uint64_t rank_abs              : 1;  /**< [ 55: 55] Absolute rank.
                                                                 0 = [HDR_ADDR] and [RANK_ADDR] point to rank 0, and the rank used is calculated using rank
                                                                 bits from the key.
                                                                 1 = [HDR_ADDR] and [RANK_ADDR] point to an absolute rank. */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_113_127      : 15;
        uint64_t res_addr              : 49; /**< [112: 64] Result address.
                                                                 If non-zero, specifies where to write DDF_RES_FIND_S.
                                                                 If zero, no result structure will be written.

                                                                 If [RR] is clear, address must be 16-byte aligned.
                                                                 If [RR] is set, address must be 128-byte aligned. */
#else /* Word 1 - Little Endian */
        uint64_t res_addr              : 49; /**< [112: 64] Result address.
                                                                 If non-zero, specifies where to write DDF_RES_FIND_S.
                                                                 If zero, no result structure will be written.

                                                                 If [RR] is clear, address must be 16-byte aligned.
                                                                 If [RR] is set, address must be 128-byte aligned. */
        uint64_t reserved_113_127      : 15;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t tag_rank              : 5;  /**< [191:187] If set, extract TAG_RANK number of bits from the computed nest number and
                                                                 exclusive-or into the SSO TAG.
                                                                    0x00: SSO tag = [TAG] ^ {0x0}.
                                                                    0x01: SSO tag = [TAG] ^ {DDF_RES_FIND_S[RANK]<0>}.
                                                                    ...
                                                                    0x1F: SSO tag = [TAG] ^ {DDF_RES_FIND_S[RANK]<30:0>}. */
        uint64_t reserved_172_186      : 15;
        uint64_t grp                   : 10; /**< [171:162] If [WQ_PTR] is non-zero, the SSO guest-group to use when DDF submits work to
                                                                 SSO. */
        uint64_t tt                    : 2;  /**< [161:160] If [WQ_PTR] is non-zero, the SSO tag type to use when DDF submits work to SSO. */
        uint64_t tag                   : 32; /**< [159:128] If [WQ_PTR] is non-zero, the SSO tag to use when DDF submits work to SSO. */
#else /* Word 2 - Little Endian */
        uint64_t tag                   : 32; /**< [159:128] If [WQ_PTR] is non-zero, the SSO tag to use when DDF submits work to SSO. */
        uint64_t tt                    : 2;  /**< [161:160] If [WQ_PTR] is non-zero, the SSO tag type to use when DDF submits work to SSO. */
        uint64_t grp                   : 10; /**< [171:162] If [WQ_PTR] is non-zero, the SSO guest-group to use when DDF submits work to
                                                                 SSO. */
        uint64_t reserved_172_186      : 15;
        uint64_t tag_rank              : 5;  /**< [191:187] If set, extract TAG_RANK number of bits from the computed nest number and
                                                                 exclusive-or into the SSO TAG.
                                                                    0x00: SSO tag = [TAG] ^ {0x0}.
                                                                    0x01: SSO tag = [TAG] ^ {DDF_RES_FIND_S[RANK]<0>}.
                                                                    ...
                                                                    0x1F: SSO tag = [TAG] ^ {DDF_RES_FIND_S[RANK]<30:0>}. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_241_255      : 15;
        uint64_t wq_ptr                : 49; /**< [240:192] If WQ_PTR is non-zero, it is a pointer to a work-queue entry that DDF submits
                                                                 work to SSO after all context, output data, and result write operations are
                                                                 visible to other CNXXXX units and the cores. */
#else /* Word 3 - Little Endian */
        uint64_t wq_ptr                : 49; /**< [240:192] If WQ_PTR is non-zero, it is a pointer to a work-queue entry that DDF submits
                                                                 work to SSO after all context, output data, and result write operations are
                                                                 visible to other CNXXXX units and the cores. */
        uint64_t reserved_241_255      : 15;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t reserved_288_319      : 32;
        uint64_t set_bdis              : 32; /**< [287:256] Set byte disables. One bit corresponds to each [KEYDATA0]..[KEYDATA3] byte. If
                                                                 that bit is clear the corresponding byte will be set in the record. Only bits
                                                                 SET_BDIS<NESTSZM1:0> have an effect. */
#else /* Word 4 - Little Endian */
        uint64_t set_bdis              : 32; /**< [287:256] Set byte disables. One bit corresponds to each [KEYDATA0]..[KEYDATA3] byte. If
                                                                 that bit is clear the corresponding byte will be set in the record. Only bits
                                                                 SET_BDIS<NESTSZM1:0> have an effect. */
        uint64_t reserved_288_319      : 32;
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t reserved_380_383      : 4;
        uint64_t nwayp2                : 2;  /**< [379:378] Number of ways as power-of-2.
                                                                 0x0 = 1 way.
                                                                 0x1 = 2 ways.
                                                                 0x2 = 4 ways.
                                                                 0x3 = 8 ways. */
        uint64_t hdrszp2               : 3;  /**< [377:375] Size of a filter header as power-of-2.
                                                                    0x1 = 1 byte.
                                                                    0x2 = 2 bytes.
                                                                    0x3 = 4 bytes.
                                                                    0x4 = 8 bytes.
                                                                    0x5 = 16 bytes.
                                                                    0x6 = 32 bytes. (See note - must have 1, 2 or 4 ways.)
                                                                    0x7 = 64 bytes. (See note - must have 1 or 2 ways.)
                                                                    0x8 = 128 bytes. (See note - must have 1 way.)

                                                                 The size of a header for all ways, e.g. (2^NWAYP2)*(2^HDRSZP2) cannot be larger than
                                                                 128 bytes.

                                                                 If [VICTEN] is set the header must be large enough to fit the victim. */
        uint64_t nestszp2              : 3;  /**< [374:372] Size of a nest entry as power-of-2.
                                                                    0x1 = 1 byte.
                                                                    0x2 = 2 bytes.
                                                                    0x3 = 4 bytes.
                                                                    0x4 = 8 bytes.
                                                                    0x5 = 16 bytes.
                                                                    0x6 = 32 bytes.

                                                                 The total size of a filter, e.g. (2^NBUCKP2) * 4 * 2^NESTSZP2) cannot be larger than
                                                                 512 bytes.
                                                                 The size of a bucket, e.g. 4 * (2^NESTSZP2) cannot be larger than 128 bytes.

                                                                 INTERNAL: This means a 32-byte SHA256 cannot have any payload (SW must use separate
                                                                 table). Limiting to 32 byte nests means all 4 nests fit in a cache line. */
        uint64_t nbuckp2               : 4;  /**< [371:368] Number of buckets per filter as a power-of-2.
                                                                   0x0 = 1 bucket/filter.
                                                                   0x1 = 2^1 = 2 buckets/filter.
                                                                   0x2 = 2^2 = 4 buckets/filter.
                                                                   0x3 = 2^3 = 8 buckets/filter.
                                                                   0x4 = 2^4 = 16 buckets/filter.
                                                                   0x5 = 2^5 = 32 buckets/filter.
                                                                   0x6 = 2^6 = 64 buckets/filter.
                                                                   0x7 = 2^7 = 128 buckets/filter.

                                                                 The total size of a filter, e.g. (2^NBUCKP2)*4*2^NESTSZP2) cannot be larger than 512
                                                                 bytes. */
        uint64_t tagbitsm1             : 8;  /**< [367:360] Number of tag bits minus one. Maximum of 0xFF corresponds to a complete 256 bit key. */
        uint64_t reserved_359          : 1;
        uint64_t cuckoo                : 7;  /**< [358:352] Cuckoo retries.
                                                                 For [OP] = ADD, the the number of times to perform cuckoo replacements.
                                                                 0x0 disables retrying.  For a filter of 64 buckets, 64 would be a typical maximum. */
        uint64_t nrankm1               : 32; /**< [351:320] Number of ranks minus one. Does not need to be a power-of-2. */
#else /* Word 5 - Little Endian */
        uint64_t nrankm1               : 32; /**< [351:320] Number of ranks minus one. Does not need to be a power-of-2. */
        uint64_t cuckoo                : 7;  /**< [358:352] Cuckoo retries.
                                                                 For [OP] = ADD, the the number of times to perform cuckoo replacements.
                                                                 0x0 disables retrying.  For a filter of 64 buckets, 64 would be a typical maximum. */
        uint64_t reserved_359          : 1;
        uint64_t tagbitsm1             : 8;  /**< [367:360] Number of tag bits minus one. Maximum of 0xFF corresponds to a complete 256 bit key. */
        uint64_t nbuckp2               : 4;  /**< [371:368] Number of buckets per filter as a power-of-2.
                                                                   0x0 = 1 bucket/filter.
                                                                   0x1 = 2^1 = 2 buckets/filter.
                                                                   0x2 = 2^2 = 4 buckets/filter.
                                                                   0x3 = 2^3 = 8 buckets/filter.
                                                                   0x4 = 2^4 = 16 buckets/filter.
                                                                   0x5 = 2^5 = 32 buckets/filter.
                                                                   0x6 = 2^6 = 64 buckets/filter.
                                                                   0x7 = 2^7 = 128 buckets/filter.

                                                                 The total size of a filter, e.g. (2^NBUCKP2)*4*2^NESTSZP2) cannot be larger than 512
                                                                 bytes. */
        uint64_t nestszp2              : 3;  /**< [374:372] Size of a nest entry as power-of-2.
                                                                    0x1 = 1 byte.
                                                                    0x2 = 2 bytes.
                                                                    0x3 = 4 bytes.
                                                                    0x4 = 8 bytes.
                                                                    0x5 = 16 bytes.
                                                                    0x6 = 32 bytes.

                                                                 The total size of a filter, e.g. (2^NBUCKP2) * 4 * 2^NESTSZP2) cannot be larger than
                                                                 512 bytes.
                                                                 The size of a bucket, e.g. 4 * (2^NESTSZP2) cannot be larger than 128 bytes.

                                                                 INTERNAL: This means a 32-byte SHA256 cannot have any payload (SW must use separate
                                                                 table). Limiting to 32 byte nests means all 4 nests fit in a cache line. */
        uint64_t hdrszp2               : 3;  /**< [377:375] Size of a filter header as power-of-2.
                                                                    0x1 = 1 byte.
                                                                    0x2 = 2 bytes.
                                                                    0x3 = 4 bytes.
                                                                    0x4 = 8 bytes.
                                                                    0x5 = 16 bytes.
                                                                    0x6 = 32 bytes. (See note - must have 1, 2 or 4 ways.)
                                                                    0x7 = 64 bytes. (See note - must have 1 or 2 ways.)
                                                                    0x8 = 128 bytes. (See note - must have 1 way.)

                                                                 The size of a header for all ways, e.g. (2^NWAYP2)*(2^HDRSZP2) cannot be larger than
                                                                 128 bytes.

                                                                 If [VICTEN] is set the header must be large enough to fit the victim. */
        uint64_t nwayp2                : 2;  /**< [379:378] Number of ways as power-of-2.
                                                                 0x0 = 1 way.
                                                                 0x1 = 2 ways.
                                                                 0x2 = 4 ways.
                                                                 0x3 = 8 ways. */
        uint64_t reserved_380_383      : 4;
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t reserved_433_447      : 15;
        uint64_t hdr_addr              : 49; /**< [432:384] Header address. Must be non-zero when [VICTEN] is set, otherwise
                                                                 reserved.

                                                                 If [RANK_ABS]=0, points to rank 0 way 0's header. Hardware accesses the way 0
                                                                 header at address [HDR_ADDR] + computed_rank * (2^[NWAYP2]) * (2^[HDRSZP2]).

                                                                 If [RANK_ABS]=1, points to the desired rank's way 0 header. Hardware accesses
                                                                 the way 0 header at address [HDR_ADDR]. */
#else /* Word 6 - Little Endian */
        uint64_t hdr_addr              : 49; /**< [432:384] Header address. Must be non-zero when [VICTEN] is set, otherwise
                                                                 reserved.

                                                                 If [RANK_ABS]=0, points to rank 0 way 0's header. Hardware accesses the way 0
                                                                 header at address [HDR_ADDR] + computed_rank * (2^[NWAYP2]) * (2^[HDRSZP2]).

                                                                 If [RANK_ABS]=1, points to the desired rank's way 0 header. Hardware accesses
                                                                 the way 0 header at address [HDR_ADDR]. */
        uint64_t reserved_433_447      : 15;
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t reserved_497_511      : 15;
        uint64_t rank_addr             : 49; /**< [496:448] Must be non-zero.

                                                                 If [RANK_ABS]=0, points to rank 0, bucket 0, way 0, nest 0.

                                                                 If [RANK_ABS]=1, points to precise rank, bucket 0, way 0, nest 0. */
#else /* Word 7 - Little Endian */
        uint64_t rank_addr             : 49; /**< [496:448] Must be non-zero.

                                                                 If [RANK_ABS]=0, points to rank 0, bucket 0, way 0, nest 0.

                                                                 If [RANK_ABS]=1, points to precise rank, bucket 0, way 0, nest 0. */
        uint64_t reserved_497_511      : 15;
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t keydata0              : 64; /**< [575:512] Key or opaque data bytes. */
#else /* Word 8 - Little Endian */
        uint64_t keydata0              : 64; /**< [575:512] Key or opaque data bytes. */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t keydata1              : 64; /**< [639:576] Extension of [KEYDATA0]. */
#else /* Word 9 - Little Endian */
        uint64_t keydata1              : 64; /**< [639:576] Extension of [KEYDATA0]. */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t keydata2              : 64; /**< [703:640] Extension of [KEYDATA0]. */
#else /* Word 10 - Little Endian */
        uint64_t keydata2              : 64; /**< [703:640] Extension of [KEYDATA0]. */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t keydata3              : 64; /**< [767:704] Extension of [KEYDATA0]. */
#else /* Word 11 - Little Endian */
        uint64_t keydata3              : 64; /**< [767:704] Extension of [KEYDATA0]. */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t reserved_768_831      : 64;
#else /* Word 12 - Little Endian */
        uint64_t reserved_768_831      : 64;
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t reserved_832_895      : 64;
#else /* Word 13 - Little Endian */
        uint64_t reserved_832_895      : 64;
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t reserved_896_959      : 64;
#else /* Word 14 - Little Endian */
        uint64_t reserved_896_959      : 64;
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t reserved_960_1023     : 64;
#else /* Word 15 - Little Endian */
        uint64_t reserved_960_1023     : 64;
#endif /* Word 15 - End */
    } s;
    /* struct bdk_ddf_inst_find_s_s cn; */
};

/**
 * Structure ddf_res_match_s
 *
 * DDF Result of Record Match Structure
 * This structure specifies the result structure written by DDF after it completes a
 * DDF_INST_MATCH_S. Each instruction completion produces exactly one result structure
 *
 * DDF always writes the first 16 bytes of this structure.  If DDF_INST_MATCH_S[RR] is
 * set DDF will update an entire cache line, but only write valid data to the fields
 * specified depending on the required amount of [RDATA0]..[7] data.
 *
 * INTERNAL: When [RR] is set it can use a full-cacheline write with fewer than
 * a cache-lines worth of NCB data ticks.
 */
union bdk_ddf_res_match_s
{
    uint64_t u[10];
    struct bdk_ddf_res_match_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t hitrec                : 16; /**< [ 63: 48] Hit record. Record number in which the key was found or inserted into. If
                                                                 multiple record blocks hit (more than one bit set in [HITRB]), then unspecified
                                                                 which record block this hit refers to.

                                                                 For DDF_OP_E::RABS_SET, unpredictable. */
        uint64_t hitrb                 : 8;  /**< [ 47: 40] Hit record block. Bitmask of which record blocks contain the key or were
                                                                 inserted into, e.g. bit 0 of this field corresponds to a match found in
                                                                 DDF_INST_MATCH_S[RB0_ADDR]. */
        uint64_t reserved_23_39        : 17;
        uint64_t hit                   : 1;  /**< [ 22: 22] Hit. Set if item was found before any change was applied, i.e. for MATCH_INS,
                                                                 will be set if the record hit an existing record and clear if inserted into a
                                                                 previously empty location.

                                                                 For DDF_OP_E::REMPTY_INS, always clear.  For DDF_OP_E::RABS_SET, always set. */
        uint64_t reserved_18_21        : 4;
        uint64_t lkres                 : 1;  /**< [ 17: 17] See DDF_RES_FIND_S[LKRES]. */
        uint64_t doneint               : 1;  /**< [ 16: 16] See DDF_RES_FIND_S[DONEINT]. */
        uint64_t res_type              : 8;  /**< [ 15:  8] See DDF_RES_FIND_S[RES_TYPE]. */
        uint64_t compcode              : 8;  /**< [  7:  0] See DDF_RES_FIND_S[COMPCODE]. */
#else /* Word 0 - Little Endian */
        uint64_t compcode              : 8;  /**< [  7:  0] See DDF_RES_FIND_S[COMPCODE]. */
        uint64_t res_type              : 8;  /**< [ 15:  8] See DDF_RES_FIND_S[RES_TYPE]. */
        uint64_t doneint               : 1;  /**< [ 16: 16] See DDF_RES_FIND_S[DONEINT]. */
        uint64_t lkres                 : 1;  /**< [ 17: 17] See DDF_RES_FIND_S[LKRES]. */
        uint64_t reserved_18_21        : 4;
        uint64_t hit                   : 1;  /**< [ 22: 22] Hit. Set if item was found before any change was applied, i.e. for MATCH_INS,
                                                                 will be set if the record hit an existing record and clear if inserted into a
                                                                 previously empty location.

                                                                 For DDF_OP_E::REMPTY_INS, always clear.  For DDF_OP_E::RABS_SET, always set. */
        uint64_t reserved_23_39        : 17;
        uint64_t hitrb                 : 8;  /**< [ 47: 40] Hit record block. Bitmask of which record blocks contain the key or were
                                                                 inserted into, e.g. bit 0 of this field corresponds to a match found in
                                                                 DDF_INST_MATCH_S[RB0_ADDR]. */
        uint64_t hitrec                : 16; /**< [ 63: 48] Hit record. Record number in which the key was found or inserted into. If
                                                                 multiple record blocks hit (more than one bit set in [HITRB]), then unspecified
                                                                 which record block this hit refers to.

                                                                 For DDF_OP_E::RABS_SET, unpredictable. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_64_127       : 64;
#else /* Word 1 - Little Endian */
        uint64_t reserved_64_127       : 64;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t rdata0                : 64; /**< [191:128] Key or opaque data bytes read.
                                                                 If [HIT] is set, the data read from the nest before any updates take place.
                                                                 If [HIT] is clear, unpredictable. */
#else /* Word 2 - Little Endian */
        uint64_t rdata0                : 64; /**< [191:128] Key or opaque data bytes read.
                                                                 If [HIT] is set, the data read from the nest before any updates take place.
                                                                 If [HIT] is clear, unpredictable. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t rdata1                : 64; /**< [255:192] Extension of [RDATA0]. */
#else /* Word 3 - Little Endian */
        uint64_t rdata1                : 64; /**< [255:192] Extension of [RDATA0]. */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t rdata2                : 64; /**< [319:256] Extension of [RDATA0]. */
#else /* Word 4 - Little Endian */
        uint64_t rdata2                : 64; /**< [319:256] Extension of [RDATA0]. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t rdata3                : 64; /**< [383:320] Extension of [RDATA0]. */
#else /* Word 5 - Little Endian */
        uint64_t rdata3                : 64; /**< [383:320] Extension of [RDATA0]. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t rdata4                : 64; /**< [447:384] Extension of [RDATA0]. */
#else /* Word 6 - Little Endian */
        uint64_t rdata4                : 64; /**< [447:384] Extension of [RDATA0]. */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t rdata5                : 64; /**< [511:448] Extension of [RDATA0]. */
#else /* Word 7 - Little Endian */
        uint64_t rdata5                : 64; /**< [511:448] Extension of [RDATA0]. */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t rdata6                : 64; /**< [575:512] Extension of [RDATA0]. */
#else /* Word 8 - Little Endian */
        uint64_t rdata6                : 64; /**< [575:512] Extension of [RDATA0]. */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t rdata7                : 64; /**< [639:576] Extension of [RDATA0]. */
#else /* Word 9 - Little Endian */
        uint64_t rdata7                : 64; /**< [639:576] Extension of [RDATA0]. */
#endif /* Word 9 - End */
    } s;
    struct bdk_ddf_res_match_s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t hitrec                : 16; /**< [ 63: 48] Hit record. Record number in which the key was found or inserted into. If
                                                                 multiple record blocks hit (more than one bit set in [HITRB]), then unspecified
                                                                 which record block this hit refers to.

                                                                 For DDF_OP_E::RABS_SET, unpredictable. */
        uint64_t hitrb                 : 8;  /**< [ 47: 40] Hit record block. Bitmask of which record blocks contain the key or were
                                                                 inserted into, e.g. bit 0 of this field corresponds to a match found in
                                                                 DDF_INST_MATCH_S[RB0_ADDR]. */
        uint64_t reserved_24_39        : 16;
        uint64_t reserved_23           : 1;
        uint64_t hit                   : 1;  /**< [ 22: 22] Hit. Set if item was found before any change was applied, i.e. for MATCH_INS,
                                                                 will be set if the record hit an existing record and clear if inserted into a
                                                                 previously empty location.

                                                                 For DDF_OP_E::REMPTY_INS, always clear.  For DDF_OP_E::RABS_SET, always set. */
        uint64_t reserved_18_21        : 4;
        uint64_t lkres                 : 1;  /**< [ 17: 17] See DDF_RES_FIND_S[LKRES]. */
        uint64_t doneint               : 1;  /**< [ 16: 16] See DDF_RES_FIND_S[DONEINT]. */
        uint64_t res_type              : 8;  /**< [ 15:  8] See DDF_RES_FIND_S[RES_TYPE]. */
        uint64_t compcode              : 8;  /**< [  7:  0] See DDF_RES_FIND_S[COMPCODE]. */
#else /* Word 0 - Little Endian */
        uint64_t compcode              : 8;  /**< [  7:  0] See DDF_RES_FIND_S[COMPCODE]. */
        uint64_t res_type              : 8;  /**< [ 15:  8] See DDF_RES_FIND_S[RES_TYPE]. */
        uint64_t doneint               : 1;  /**< [ 16: 16] See DDF_RES_FIND_S[DONEINT]. */
        uint64_t lkres                 : 1;  /**< [ 17: 17] See DDF_RES_FIND_S[LKRES]. */
        uint64_t reserved_18_21        : 4;
        uint64_t hit                   : 1;  /**< [ 22: 22] Hit. Set if item was found before any change was applied, i.e. for MATCH_INS,
                                                                 will be set if the record hit an existing record and clear if inserted into a
                                                                 previously empty location.

                                                                 For DDF_OP_E::REMPTY_INS, always clear.  For DDF_OP_E::RABS_SET, always set. */
        uint64_t reserved_23           : 1;
        uint64_t reserved_24_39        : 16;
        uint64_t hitrb                 : 8;  /**< [ 47: 40] Hit record block. Bitmask of which record blocks contain the key or were
                                                                 inserted into, e.g. bit 0 of this field corresponds to a match found in
                                                                 DDF_INST_MATCH_S[RB0_ADDR]. */
        uint64_t hitrec                : 16; /**< [ 63: 48] Hit record. Record number in which the key was found or inserted into. If
                                                                 multiple record blocks hit (more than one bit set in [HITRB]), then unspecified
                                                                 which record block this hit refers to.

                                                                 For DDF_OP_E::RABS_SET, unpredictable. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_64_127       : 64;
#else /* Word 1 - Little Endian */
        uint64_t reserved_64_127       : 64;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t rdata0                : 64; /**< [191:128] Key or opaque data bytes read.
                                                                 If [HIT] is set, the data read from the nest before any updates take place.
                                                                 If [HIT] is clear, unpredictable. */
#else /* Word 2 - Little Endian */
        uint64_t rdata0                : 64; /**< [191:128] Key or opaque data bytes read.
                                                                 If [HIT] is set, the data read from the nest before any updates take place.
                                                                 If [HIT] is clear, unpredictable. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t rdata1                : 64; /**< [255:192] Extension of [RDATA0]. */
#else /* Word 3 - Little Endian */
        uint64_t rdata1                : 64; /**< [255:192] Extension of [RDATA0]. */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t rdata2                : 64; /**< [319:256] Extension of [RDATA0]. */
#else /* Word 4 - Little Endian */
        uint64_t rdata2                : 64; /**< [319:256] Extension of [RDATA0]. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t rdata3                : 64; /**< [383:320] Extension of [RDATA0]. */
#else /* Word 5 - Little Endian */
        uint64_t rdata3                : 64; /**< [383:320] Extension of [RDATA0]. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t rdata4                : 64; /**< [447:384] Extension of [RDATA0]. */
#else /* Word 6 - Little Endian */
        uint64_t rdata4                : 64; /**< [447:384] Extension of [RDATA0]. */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t rdata5                : 64; /**< [511:448] Extension of [RDATA0]. */
#else /* Word 7 - Little Endian */
        uint64_t rdata5                : 64; /**< [511:448] Extension of [RDATA0]. */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t rdata6                : 64; /**< [575:512] Extension of [RDATA0]. */
#else /* Word 8 - Little Endian */
        uint64_t rdata6                : 64; /**< [575:512] Extension of [RDATA0]. */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t rdata7                : 64; /**< [639:576] Extension of [RDATA0]. */
#else /* Word 9 - Little Endian */
        uint64_t rdata7                : 64; /**< [639:576] Extension of [RDATA0]. */
#endif /* Word 9 - End */
    } cn;
};

/**
 * Register (NCB) ddf_pf_ecc0_flip
 *
 * DDF PF ECC Flip Syndrome Register
 * This register enables ECC for each individual internal memory that requires ECC. For debug
 * purposes, it can also flip one or two bits in the ECC data.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_ecc0_flip_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t flip1                 : 32; /**< [ 63: 32](R/W) Flips syndome bit 1 on writes.  Bit positions enumerated with DDF_RAMS_E. */
        uint64_t flip0                 : 32; /**< [ 31:  0](R/W) Flips syndome bit 0 on writes.  Bit positions enumerated with DDF_RAMS_E. */
#else /* Word 0 - Little Endian */
        uint64_t flip0                 : 32; /**< [ 31:  0](R/W) Flips syndome bit 0 on writes.  Bit positions enumerated with DDF_RAMS_E. */
        uint64_t flip1                 : 32; /**< [ 63: 32](R/W) Flips syndome bit 1 on writes.  Bit positions enumerated with DDF_RAMS_E. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_ecc0_flip_s cn; */
} bdk_ddf_pf_ecc0_flip_t;

#define BDK_DDF_PF_ECC0_FLIP BDK_DDF_PF_ECC0_FLIP_FUNC()
static inline uint64_t BDK_DDF_PF_ECC0_FLIP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_ECC0_FLIP_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000000210ll;
    __bdk_csr_fatal("DDF_PF_ECC0_FLIP", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_ECC0_FLIP bdk_ddf_pf_ecc0_flip_t
#define bustype_BDK_DDF_PF_ECC0_FLIP BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_ECC0_FLIP "DDF_PF_ECC0_FLIP"
#define busnum_BDK_DDF_PF_ECC0_FLIP 0
#define arguments_BDK_DDF_PF_ECC0_FLIP -1,-1,-1,-1

/**
 * Register (NCB) ddf_pf_msix_pba#
 *
 * DDF PF MSI-X Pending-Bit-Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the
 * DDF_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated DDF_PF_MSIX_VEC()_CTL, enumerated by
                                                                 DDF_PF_INT_VEC_E. Bits that have no associated DDF_PF_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated DDF_PF_MSIX_VEC()_CTL, enumerated by
                                                                 DDF_PF_INT_VEC_E. Bits that have no associated DDF_PF_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_msix_pbax_s cn; */
} bdk_ddf_pf_msix_pbax_t;

static inline uint64_t BDK_DDF_PF_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_MSIX_PBAX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x8090100f0000ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("DDF_PF_MSIX_PBAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_MSIX_PBAX(a) bdk_ddf_pf_msix_pbax_t
#define bustype_BDK_DDF_PF_MSIX_PBAX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_MSIX_PBAX(a) "DDF_PF_MSIX_PBAX"
#define busnum_BDK_DDF_PF_MSIX_PBAX(a) (a)
#define arguments_BDK_DDF_PF_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_vf#_pf_mbox#
 *
 * DDF VF/PF Mailbox Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vfx_pf_mboxx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These VF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. The PF may access the same storage using DDF_PF_VF()_MBOX(). MBOX(0) is
                                                                 typically used for PF to VF signaling, MBOX(1) for VF to PF. Writing
                                                                 DDF_VF(0..31)_PF_MBOX(1) (but not DDF_PF_VF(0..31)_MBOX(1)) will set the
                                                                 corresponding DDF_PF_MBOX_INT() bit, which if appropriately enabled will send an
                                                                 interrupt to the PF. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These VF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. The PF may access the same storage using DDF_PF_VF()_MBOX(). MBOX(0) is
                                                                 typically used for PF to VF signaling, MBOX(1) for VF to PF. Writing
                                                                 DDF_VF(0..31)_PF_MBOX(1) (but not DDF_PF_VF(0..31)_MBOX(1)) will set the
                                                                 corresponding DDF_PF_MBOX_INT() bit, which if appropriately enabled will send an
                                                                 interrupt to the PF. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vfx_pf_mboxx_s cn; */
} bdk_ddf_vfx_pf_mboxx_t;

static inline uint64_t BDK_DDF_VFX_PF_MBOXX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VFX_PF_MBOXX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=1)))
        return 0x809020001000ll + 0x100000ll * ((a) & 0x1f) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("DDF_VFX_PF_MBOXX", 2, a, b, 0, 0);
}

#define typedef_BDK_DDF_VFX_PF_MBOXX(a,b) bdk_ddf_vfx_pf_mboxx_t
#define bustype_BDK_DDF_VFX_PF_MBOXX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VFX_PF_MBOXX(a,b) "DDF_VFX_PF_MBOXX"
#define busnum_BDK_DDF_VFX_PF_MBOXX(a,b) (a)
#define arguments_BDK_DDF_VFX_PF_MBOXX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) ddf_vq#_done_ack
 *
 * DDF Queue Done Count Ack Registers
 * This register is written by software to acknowledge interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vqx_done_ack_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t done_ack              : 20; /**< [ 19:  0](R/W/H) Number of decrements to DDF_VQ()_DONE[DONE]. Reads DDF_VQ()_DONE[DONE].

                                                                 Written by software to acknowledge interrupts. If DDF_VQ()_DONE[DONE] is still
                                                                 non-zero the interrupt will be re-sent if the conditions described in
                                                                 DDF_VQ()_DONE[DONE] are satisfied. */
#else /* Word 0 - Little Endian */
        uint64_t done_ack              : 20; /**< [ 19:  0](R/W/H) Number of decrements to DDF_VQ()_DONE[DONE]. Reads DDF_VQ()_DONE[DONE].

                                                                 Written by software to acknowledge interrupts. If DDF_VQ()_DONE[DONE] is still
                                                                 non-zero the interrupt will be re-sent if the conditions described in
                                                                 DDF_VQ()_DONE[DONE] are satisfied. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vqx_done_ack_s cn; */
} bdk_ddf_vqx_done_ack_t;

static inline uint64_t BDK_DDF_VQX_DONE_ACK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VQX_DONE_ACK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809020000440ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_VQX_DONE_ACK", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_VQX_DONE_ACK(a) bdk_ddf_vqx_done_ack_t
#define bustype_BDK_DDF_VQX_DONE_ACK(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VQX_DONE_ACK(a) "DDF_VQX_DONE_ACK"
#define busnum_BDK_DDF_VQX_DONE_ACK(a) (a)
#define arguments_BDK_DDF_VQX_DONE_ACK(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_vq#_misc_int
 *
 * DDF Queue Misc Interrupt Register
 * These registers contain the per-queue miscellaneous interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vqx_misc_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) NCB result write response error. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1C/H) Instruction NCB read response error. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1C/H) Doorbell overflow. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1C/H) PF to VF mailbox interrupt. Set when DDF_VF(0..31)_MBOX(0)
                                                                 is written. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1C/H) PF to VF mailbox interrupt. Set when DDF_VF(0..31)_MBOX(0)
                                                                 is written. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1C/H) Doorbell overflow. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1C/H) Instruction NCB read response error. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) NCB result write response error. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vqx_misc_int_s cn; */
} bdk_ddf_vqx_misc_int_t;

static inline uint64_t BDK_DDF_VQX_MISC_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VQX_MISC_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809020000500ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_VQX_MISC_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_VQX_MISC_INT(a) bdk_ddf_vqx_misc_int_t
#define bustype_BDK_DDF_VQX_MISC_INT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VQX_MISC_INT(a) "DDF_VQX_MISC_INT"
#define busnum_BDK_DDF_VQX_MISC_INT(a) (a)
#define arguments_BDK_DDF_VQX_MISC_INT(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_vq#_ctl
 *
 * DDF VF Queue Control Registers
 * These registers set the buffer parameters for the instruction queues. When quiescent
 * (i.e. outstanding doorbell count is 0), it is safe to rewrite this register to
 * effectively reset the command buffer state machine. These registers must be
 * programmed before software programs the corresponding DDF()_VQ()_SADDR.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vqx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_45_63        : 19;
        uint64_t size                  : 13; /**< [ 44: 32](R/W) Command-buffer size, in number of 64-bit words per command buffer segment.
                                                                 Must be even. */
        uint64_t reserved_23_31        : 9;
        uint64_t inst_free             : 1;  /**< [ 22: 22](R/W) Instruction FPA free. When set, when DDF reaches the end of an instruction
                                                                 chunk, that chunk will be freed to the FPA. */
        uint64_t inst_be               : 1;  /**< [ 21: 21](R/W) Instruction big endian control. When set, instructions are storaged in big
                                                                 endian format in memory. */
        uint64_t iqb_ldwb              : 1;  /**< [ 20: 20](R/W) When set, reading a DDF instruction full cache lines will use NCB LDWB
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
        uint64_t iqb_ldwb              : 1;  /**< [ 20: 20](R/W) When set, reading a DDF instruction full cache lines will use NCB LDWB
                                                                 read-and-invalidate to improve performance. If clear, use NCB LDI for
                                                                 debugability. Partial cache line reads always use LDI. */
        uint64_t inst_be               : 1;  /**< [ 21: 21](R/W) Instruction big endian control. When set, instructions are storaged in big
                                                                 endian format in memory. */
        uint64_t inst_free             : 1;  /**< [ 22: 22](R/W) Instruction FPA free. When set, when DDF reaches the end of an instruction
                                                                 chunk, that chunk will be freed to the FPA. */
        uint64_t reserved_23_31        : 9;
        uint64_t size                  : 13; /**< [ 44: 32](R/W) Command-buffer size, in number of 64-bit words per command buffer segment.
                                                                 Must be even. */
        uint64_t reserved_45_63        : 19;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vqx_ctl_s cn; */
} bdk_ddf_vqx_ctl_t;

static inline uint64_t BDK_DDF_VQX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VQX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809020000100ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_VQX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_VQX_CTL(a) bdk_ddf_vqx_ctl_t
#define bustype_BDK_DDF_VQX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VQX_CTL(a) "DDF_VQX_CTL"
#define busnum_BDK_DDF_VQX_CTL(a) (a)
#define arguments_BDK_DDF_VQX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_pf_msix_vec#_ctl
 *
 * DDF PF MSI-X Vector-Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the DDF_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_msix_vecx_ctl_s
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
    /* struct bdk_ddf_pf_msix_vecx_ctl_s cn; */
} bdk_ddf_pf_msix_vecx_ctl_t;

static inline uint64_t BDK_DDF_PF_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_MSIX_VECX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x809010000008ll + 0x10ll * ((a) & 0x1);
    __bdk_csr_fatal("DDF_PF_MSIX_VECX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_MSIX_VECX_CTL(a) bdk_ddf_pf_msix_vecx_ctl_t
#define bustype_BDK_DDF_PF_MSIX_VECX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_MSIX_VECX_CTL(a) "DDF_PF_MSIX_VECX_CTL"
#define busnum_BDK_DDF_PF_MSIX_VECX_CTL(a) (a)
#define arguments_BDK_DDF_PF_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_pf_mbox_int#
 *
 * DDF PF Mailbox Interrupt Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_mbox_intx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) One interrupt bit per VF. Each bit is set when the associated
                                                                 DDF_VF(0..31)_PF_MBOX(1) is written. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) One interrupt bit per VF. Each bit is set when the associated
                                                                 DDF_VF(0..31)_PF_MBOX(1) is written. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_mbox_intx_s cn; */
} bdk_ddf_pf_mbox_intx_t;

static inline uint64_t BDK_DDF_PF_MBOX_INTX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_MBOX_INTX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x809000000400ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("DDF_PF_MBOX_INTX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_MBOX_INTX(a) bdk_ddf_pf_mbox_intx_t
#define bustype_BDK_DDF_PF_MBOX_INTX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_MBOX_INTX(a) "DDF_PF_MBOX_INTX"
#define busnum_BDK_DDF_PF_MBOX_INTX(a) (a)
#define arguments_BDK_DDF_PF_MBOX_INTX(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_pf_rd_req_pc
 *
 * DDF PF Read Request Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_rd_req_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of L2C read requests. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of L2C read requests. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_rd_req_pc_s cn; */
} bdk_ddf_pf_rd_req_pc_t;

#define BDK_DDF_PF_RD_REQ_PC BDK_DDF_PF_RD_REQ_PC_FUNC()
static inline uint64_t BDK_DDF_PF_RD_REQ_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_RD_REQ_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000010040ll;
    __bdk_csr_fatal("DDF_PF_RD_REQ_PC", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_RD_REQ_PC bdk_ddf_pf_rd_req_pc_t
#define bustype_BDK_DDF_PF_RD_REQ_PC BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_RD_REQ_PC "DDF_PF_RD_REQ_PC"
#define busnum_BDK_DDF_PF_RD_REQ_PC 0
#define arguments_BDK_DDF_PF_RD_REQ_PC -1,-1,-1,-1

/**
 * Register (NCB) ddf_pf_reset
 *
 * DDF PF Reset Register
 * This register controls clock and reset.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_reset_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1) Reset one-shot pulse to reset DDF subsystem. */
#else /* Word 0 - Little Endian */
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1) Reset one-shot pulse to reset DDF subsystem. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_reset_s cn; */
} bdk_ddf_pf_reset_t;

#define BDK_DDF_PF_RESET BDK_DDF_PF_RESET_FUNC()
static inline uint64_t BDK_DDF_PF_RESET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_RESET_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000000100ll;
    __bdk_csr_fatal("DDF_PF_RESET", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_RESET bdk_ddf_pf_reset_t
#define bustype_BDK_DDF_PF_RESET BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_RESET "DDF_PF_RESET"
#define busnum_BDK_DDF_PF_RESET 0
#define arguments_BDK_DDF_PF_RESET -1,-1,-1,-1

/**
 * Register (NCB) ddf_vq#_done_wait
 *
 * DDF Queue Done Interrupt Coalescing Wait Registers
 * Specifies the per queue interrupt coalescing settings.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vqx_done_wait_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t time_wait             : 16; /**< [ 47: 32](R/W) Time hold-off. When DDF_VQ()_DONE[DONE] = 0, or DDF_VQ()_DONE_ACK is written
                                                                 a timer is cleared. When the timer reaches [TIME_WAIT]*1024 then interrupt
                                                                 coalescing ends; see DDF_VQ()_DONE[DONE]. If 0x0, time coalescing is disabled. */
        uint64_t reserved_20_31        : 12;
        uint64_t num_wait              : 20; /**< [ 19:  0](R/W) Number of messages hold-off. When DDF_VQ()_DONE[DONE] >= [NUM_WAIT] then
                                                                 interrupt coalescing ends; see DDF_VQ()_DONE[DONE]. If 0x0, same behavior as
                                                                 0x1. */
#else /* Word 0 - Little Endian */
        uint64_t num_wait              : 20; /**< [ 19:  0](R/W) Number of messages hold-off. When DDF_VQ()_DONE[DONE] >= [NUM_WAIT] then
                                                                 interrupt coalescing ends; see DDF_VQ()_DONE[DONE]. If 0x0, same behavior as
                                                                 0x1. */
        uint64_t reserved_20_31        : 12;
        uint64_t time_wait             : 16; /**< [ 47: 32](R/W) Time hold-off. When DDF_VQ()_DONE[DONE] = 0, or DDF_VQ()_DONE_ACK is written
                                                                 a timer is cleared. When the timer reaches [TIME_WAIT]*1024 then interrupt
                                                                 coalescing ends; see DDF_VQ()_DONE[DONE]. If 0x0, time coalescing is disabled. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vqx_done_wait_s cn; */
} bdk_ddf_vqx_done_wait_t;

static inline uint64_t BDK_DDF_VQX_DONE_WAIT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VQX_DONE_WAIT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809020000400ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_VQX_DONE_WAIT", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_VQX_DONE_WAIT(a) bdk_ddf_vqx_done_wait_t
#define bustype_BDK_DDF_VQX_DONE_WAIT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VQX_DONE_WAIT(a) "DDF_VQX_DONE_WAIT"
#define busnum_BDK_DDF_VQX_DONE_WAIT(a) (a)
#define arguments_BDK_DDF_VQX_DONE_WAIT(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_vf#_msix_pba#
 *
 * DDF VF MSI-X Pending-Bit-Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the DDF_VF_INT_VEC_E
 * enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vfx_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated DDF_PF_MSIX_VEC()_CTL, enumerated by
                                                                 DDF_PF_INT_VEC_E. Bits that have no associated DDF_PF_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated DDF_PF_MSIX_VEC()_CTL, enumerated by
                                                                 DDF_PF_INT_VEC_E. Bits that have no associated DDF_PF_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vfx_msix_pbax_s cn; */
} bdk_ddf_vfx_msix_pbax_t;

static inline uint64_t BDK_DDF_VFX_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VFX_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b==0)))
        return 0x8090300f0000ll + 0x100000ll * ((a) & 0x1f) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("DDF_VFX_MSIX_PBAX", 2, a, b, 0, 0);
}

#define typedef_BDK_DDF_VFX_MSIX_PBAX(a,b) bdk_ddf_vfx_msix_pbax_t
#define bustype_BDK_DDF_VFX_MSIX_PBAX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VFX_MSIX_PBAX(a,b) "DDF_VFX_MSIX_PBAX"
#define busnum_BDK_DDF_VFX_MSIX_PBAX(a,b) (a)
#define arguments_BDK_DDF_VFX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) ddf_pf_diag
 *
 * DDF PF Diagnostic Control Register
 * This register controls diagnostic features.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_diag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t forceclk              : 1;  /**< [  8:  8](R/W) When this bit is set to 1, it forces DDF clocks on. For diagnostic use only. */
        uint64_t ld_infl               : 8;  /**< [  7:  0](R/W) Maximum number of in-flight data fetch transactions on the NCB. Larger values
                                                                 may improve DDF performance but may starve other devices on the same NCB. Values
                                                                 > 32 are treated as 32. */
#else /* Word 0 - Little Endian */
        uint64_t ld_infl               : 8;  /**< [  7:  0](R/W) Maximum number of in-flight data fetch transactions on the NCB. Larger values
                                                                 may improve DDF performance but may starve other devices on the same NCB. Values
                                                                 > 32 are treated as 32. */
        uint64_t forceclk              : 1;  /**< [  8:  8](R/W) When this bit is set to 1, it forces DDF clocks on. For diagnostic use only. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_diag_s cn; */
} bdk_ddf_pf_diag_t;

#define BDK_DDF_PF_DIAG BDK_DDF_PF_DIAG_FUNC()
static inline uint64_t BDK_DDF_PF_DIAG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_DIAG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000000120ll;
    __bdk_csr_fatal("DDF_PF_DIAG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_DIAG bdk_ddf_pf_diag_t
#define bustype_BDK_DDF_PF_DIAG BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_DIAG "DDF_PF_DIAG"
#define busnum_BDK_DDF_PF_DIAG 0
#define arguments_BDK_DDF_PF_DIAG -1,-1,-1,-1

/**
 * Register (NCB) ddf_vq#_doorbell
 *
 * DDF Queue Doorbell Registers
 * Doorbells for the DDF instruction queues.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vqx_doorbell_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t dbell_cnt             : 20; /**< [ 19:  0](R/W/H) Number of instruction queue 64-bit words to add to the DDF instruction doorbell
                                                                 count. Must be a multiple of 16. All DDF instructions are 16 words and require a
                                                                 doorbell count of multiple of 16. */
#else /* Word 0 - Little Endian */
        uint64_t dbell_cnt             : 20; /**< [ 19:  0](R/W/H) Number of instruction queue 64-bit words to add to the DDF instruction doorbell
                                                                 count. Must be a multiple of 16. All DDF instructions are 16 words and require a
                                                                 doorbell count of multiple of 16. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vqx_doorbell_s cn; */
} bdk_ddf_vqx_doorbell_t;

static inline uint64_t BDK_DDF_VQX_DOORBELL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VQX_DOORBELL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809020000600ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_VQX_DOORBELL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_VQX_DOORBELL(a) bdk_ddf_vqx_doorbell_t
#define bustype_BDK_DDF_VQX_DOORBELL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VQX_DOORBELL(a) "DDF_VQX_DOORBELL"
#define busnum_BDK_DDF_VQX_DOORBELL(a) (a)
#define arguments_BDK_DDF_VQX_DOORBELL(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_vq#_done_int_w1c
 *
 * DDF Queue Done Interrupt Clear Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vqx_done_int_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done                  : 1;  /**< [  0:  0](RO/H) Done interrupt. See DDF_VQ()_DONE[DONE].  Note this bit is read-only, to acknowledge
                                                                 interrupts use DDF_VQ()_DONE_ACK. To test interrupts, write non-zero to
                                                                 DDF_VQ()_DONE[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](RO/H) Done interrupt. See DDF_VQ()_DONE[DONE].  Note this bit is read-only, to acknowledge
                                                                 interrupts use DDF_VQ()_DONE_ACK. To test interrupts, write non-zero to
                                                                 DDF_VQ()_DONE[DONE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vqx_done_int_w1c_s cn; */
} bdk_ddf_vqx_done_int_w1c_t;

static inline uint64_t BDK_DDF_VQX_DONE_INT_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VQX_DONE_INT_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809020000468ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_VQX_DONE_INT_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_VQX_DONE_INT_W1C(a) bdk_ddf_vqx_done_int_w1c_t
#define bustype_BDK_DDF_VQX_DONE_INT_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VQX_DONE_INT_W1C(a) "DDF_VQX_DONE_INT_W1C"
#define busnum_BDK_DDF_VQX_DONE_INT_W1C(a) (a)
#define arguments_BDK_DDF_VQX_DONE_INT_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_vq#_done_int_w1s
 *
 * DDF Queue Done Interrupt Set Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vqx_done_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done                  : 1;  /**< [  0:  0](RO/H) Done interrupt. See DDF_VQ()_DONE[DONE].  Note this bit is read-only, to acknowledge
                                                                 interrupts use DDF_VQ()_DONE_ACK. To test interrupts, write non-zero to
                                                                 DDF_VQ()_DONE[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](RO/H) Done interrupt. See DDF_VQ()_DONE[DONE].  Note this bit is read-only, to acknowledge
                                                                 interrupts use DDF_VQ()_DONE_ACK. To test interrupts, write non-zero to
                                                                 DDF_VQ()_DONE[DONE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vqx_done_int_w1s_s cn; */
} bdk_ddf_vqx_done_int_w1s_t;

static inline uint64_t BDK_DDF_VQX_DONE_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VQX_DONE_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809020000460ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_VQX_DONE_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_VQX_DONE_INT_W1S(a) bdk_ddf_vqx_done_int_w1s_t
#define bustype_BDK_DDF_VQX_DONE_INT_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VQX_DONE_INT_W1S(a) "DDF_VQX_DONE_INT_W1S"
#define busnum_BDK_DDF_VQX_DONE_INT_W1S(a) (a)
#define arguments_BDK_DDF_VQX_DONE_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_vf#_msix_vec#_addr
 *
 * DDF VF MSI-X Vector-Table Address Registers
 * This register is the MSI-X vector table, indexed by the DDF_VF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vfx_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](RAZ) Secure vector. Zero as not supported on a per-vector basis for VFs; use
                                                                 PCCPF_DDF_VSEC_SCTL[MSIX_SEC] instead (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]). */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](RAZ) Secure vector. Zero as not supported on a per-vector basis for VFs; use
                                                                 PCCPF_DDF_VSEC_SCTL[MSIX_SEC] instead (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]). */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vfx_msix_vecx_addr_s cn; */
} bdk_ddf_vfx_msix_vecx_addr_t;

static inline uint64_t BDK_DDF_VFX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VFX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=1)))
        return 0x809030000000ll + 0x100000ll * ((a) & 0x1f) + 0x10ll * ((b) & 0x1);
    __bdk_csr_fatal("DDF_VFX_MSIX_VECX_ADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_DDF_VFX_MSIX_VECX_ADDR(a,b) bdk_ddf_vfx_msix_vecx_addr_t
#define bustype_BDK_DDF_VFX_MSIX_VECX_ADDR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VFX_MSIX_VECX_ADDR(a,b) "DDF_VFX_MSIX_VECX_ADDR"
#define busnum_BDK_DDF_VFX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_BDK_DDF_VFX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) ddf_pf_mbox_ena_w1s#
 *
 * DDF PF Mailbox Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_mbox_ena_w1sx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for DDF_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for DDF_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_mbox_ena_w1sx_s cn; */
} bdk_ddf_pf_mbox_ena_w1sx_t;

static inline uint64_t BDK_DDF_PF_MBOX_ENA_W1SX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_MBOX_ENA_W1SX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x809000000460ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("DDF_PF_MBOX_ENA_W1SX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_MBOX_ENA_W1SX(a) bdk_ddf_pf_mbox_ena_w1sx_t
#define bustype_BDK_DDF_PF_MBOX_ENA_W1SX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_MBOX_ENA_W1SX(a) "DDF_PF_MBOX_ENA_W1SX"
#define busnum_BDK_DDF_PF_MBOX_ENA_W1SX(a) (a)
#define arguments_BDK_DDF_PF_MBOX_ENA_W1SX(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_pf_inst_latency_pc
 *
 * DDF PF Instruction Latency Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_inst_latency_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for an instruction to complete (have the store of
                                                                 DDF_RES_S reach the commit point). Incremented every coprocessor-clock by the
                                                                 number of instructions active in that cycle. This may be divided by
                                                                 DDF_PF_RD_REQ_PC to determine the average hardware instruction latency. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for an instruction to complete (have the store of
                                                                 DDF_RES_S reach the commit point). Incremented every coprocessor-clock by the
                                                                 number of instructions active in that cycle. This may be divided by
                                                                 DDF_PF_RD_REQ_PC to determine the average hardware instruction latency. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_inst_latency_pc_s cn; */
} bdk_ddf_pf_inst_latency_pc_t;

#define BDK_DDF_PF_INST_LATENCY_PC BDK_DDF_PF_INST_LATENCY_PC_FUNC()
static inline uint64_t BDK_DDF_PF_INST_LATENCY_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_INST_LATENCY_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000010020ll;
    __bdk_csr_fatal("DDF_PF_INST_LATENCY_PC", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_INST_LATENCY_PC bdk_ddf_pf_inst_latency_pc_t
#define bustype_BDK_DDF_PF_INST_LATENCY_PC BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_INST_LATENCY_PC "DDF_PF_INST_LATENCY_PC"
#define busnum_BDK_DDF_PF_INST_LATENCY_PC 0
#define arguments_BDK_DDF_PF_INST_LATENCY_PC -1,-1,-1,-1

/**
 * Register (NCB) ddf_pf_mbox_int_w1s#
 *
 * DDF PF Mailbox Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_mbox_int_w1sx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets DDF_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets DDF_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_mbox_int_w1sx_s cn; */
} bdk_ddf_pf_mbox_int_w1sx_t;

static inline uint64_t BDK_DDF_PF_MBOX_INT_W1SX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_MBOX_INT_W1SX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x809000000420ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("DDF_PF_MBOX_INT_W1SX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_MBOX_INT_W1SX(a) bdk_ddf_pf_mbox_int_w1sx_t
#define bustype_BDK_DDF_PF_MBOX_INT_W1SX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_MBOX_INT_W1SX(a) "DDF_PF_MBOX_INT_W1SX"
#define busnum_BDK_DDF_PF_MBOX_INT_W1SX(a) (a)
#define arguments_BDK_DDF_PF_MBOX_INT_W1SX(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_pf_rd_latency_pc
 *
 * DDF PF Read Latency Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_rd_latency_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for L2C read returns. Incremented every
                                                                 coprocessor-clock by the number of transactions outstanding in that cycle. This
                                                                 may be divided by DDF_PF_RD_REQ_PC to determine the average read latency. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for L2C read returns. Incremented every
                                                                 coprocessor-clock by the number of transactions outstanding in that cycle. This
                                                                 may be divided by DDF_PF_RD_REQ_PC to determine the average read latency. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_rd_latency_pc_s cn; */
} bdk_ddf_pf_rd_latency_pc_t;

#define BDK_DDF_PF_RD_LATENCY_PC BDK_DDF_PF_RD_LATENCY_PC_FUNC()
static inline uint64_t BDK_DDF_PF_RD_LATENCY_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_RD_LATENCY_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000010060ll;
    __bdk_csr_fatal("DDF_PF_RD_LATENCY_PC", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_RD_LATENCY_PC bdk_ddf_pf_rd_latency_pc_t
#define bustype_BDK_DDF_PF_RD_LATENCY_PC BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_RD_LATENCY_PC "DDF_PF_RD_LATENCY_PC"
#define busnum_BDK_DDF_PF_RD_LATENCY_PC 0
#define arguments_BDK_DDF_PF_RD_LATENCY_PC -1,-1,-1,-1

/**
 * Register (NCB) ddf_pf_q#_gmctl
 *
 * DDF Queue Guest Machine Control Register
 * This register configures queues.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_qx_gmctl_s
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
    /* struct bdk_ddf_pf_qx_gmctl_s cn; */
} bdk_ddf_pf_qx_gmctl_t;

static inline uint64_t BDK_DDF_PF_QX_GMCTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_QX_GMCTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809008000020ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_PF_QX_GMCTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_QX_GMCTL(a) bdk_ddf_pf_qx_gmctl_t
#define bustype_BDK_DDF_PF_QX_GMCTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_QX_GMCTL(a) "DDF_PF_QX_GMCTL"
#define busnum_BDK_DDF_PF_QX_GMCTL(a) (a)
#define arguments_BDK_DDF_PF_QX_GMCTL(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_pf_ecc0_int_w1s
 *
 * DDF ECC Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_ecc0_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets DDF_PF_ECC0_INT[DBE]. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets DDF_PF_ECC0_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets DDF_PF_ECC0_INT[SBE]. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets DDF_PF_ECC0_INT[DBE]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_ecc0_int_w1s_s cn; */
} bdk_ddf_pf_ecc0_int_w1s_t;

#define BDK_DDF_PF_ECC0_INT_W1S BDK_DDF_PF_ECC0_INT_W1S_FUNC()
static inline uint64_t BDK_DDF_PF_ECC0_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_ECC0_INT_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000000230ll;
    __bdk_csr_fatal("DDF_PF_ECC0_INT_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_ECC0_INT_W1S bdk_ddf_pf_ecc0_int_w1s_t
#define bustype_BDK_DDF_PF_ECC0_INT_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_ECC0_INT_W1S "DDF_PF_ECC0_INT_W1S"
#define busnum_BDK_DDF_PF_ECC0_INT_W1S 0
#define arguments_BDK_DDF_PF_ECC0_INT_W1S -1,-1,-1,-1

/**
 * Register (NCB) ddf_pf_vf#_mbox#
 *
 * DDF PF/VF Mailbox Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_vfx_mboxx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These PF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. Each corresponding VF may access the same storage using
                                                                 DDF_VF()_PF_MBOX(). MBOX(0) is typically used for PF to VF signaling, MBOX(1)
                                                                 for VF to PF. Writing DDF_PF_VF(0..31)_MBOX(0) (but not
                                                                 DDF_VF(0..31)_PF_MBOX(0)) will set the corresponding
                                                                 DDF_VF()_MISC_INT[MBOX] which if appropriately enabled will send an interrupt
                                                                 to the VF. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These PF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. Each corresponding VF may access the same storage using
                                                                 DDF_VF()_PF_MBOX(). MBOX(0) is typically used for PF to VF signaling, MBOX(1)
                                                                 for VF to PF. Writing DDF_PF_VF(0..31)_MBOX(0) (but not
                                                                 DDF_VF(0..31)_PF_MBOX(0)) will set the corresponding
                                                                 DDF_VF()_MISC_INT[MBOX] which if appropriately enabled will send an interrupt
                                                                 to the VF. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_vfx_mboxx_s cn; */
} bdk_ddf_pf_vfx_mboxx_t;

static inline uint64_t BDK_DDF_PF_VFX_MBOXX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_VFX_MBOXX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=1)))
        return 0x809008001000ll + 0x100000ll * ((a) & 0x1f) + 0x100ll * ((b) & 0x1);
    __bdk_csr_fatal("DDF_PF_VFX_MBOXX", 2, a, b, 0, 0);
}

#define typedef_BDK_DDF_PF_VFX_MBOXX(a,b) bdk_ddf_pf_vfx_mboxx_t
#define bustype_BDK_DDF_PF_VFX_MBOXX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_VFX_MBOXX(a,b) "DDF_PF_VFX_MBOXX"
#define busnum_BDK_DDF_PF_VFX_MBOXX(a,b) (a)
#define arguments_BDK_DDF_PF_VFX_MBOXX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) ddf_vq#_misc_ena_w1c
 *
 * DDF Queue Misc Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vqx_misc_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for DDF_VQ(0..31)_MISC_INT[NWRP]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for DDF_VQ(0..31)_MISC_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for DDF_VQ(0..31)_MISC_INT[DOVF]. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for DDF_VQ(0..31)_MISC_INT[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for DDF_VQ(0..31)_MISC_INT[MBOX]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for DDF_VQ(0..31)_MISC_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for DDF_VQ(0..31)_MISC_INT[IRDE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for DDF_VQ(0..31)_MISC_INT[NWRP]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vqx_misc_ena_w1c_s cn; */
} bdk_ddf_vqx_misc_ena_w1c_t;

static inline uint64_t BDK_DDF_VQX_MISC_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VQX_MISC_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809020000518ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_VQX_MISC_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_VQX_MISC_ENA_W1C(a) bdk_ddf_vqx_misc_ena_w1c_t
#define bustype_BDK_DDF_VQX_MISC_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VQX_MISC_ENA_W1C(a) "DDF_VQX_MISC_ENA_W1C"
#define busnum_BDK_DDF_VQX_MISC_ENA_W1C(a) (a)
#define arguments_BDK_DDF_VQX_MISC_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_vq#_misc_ena_w1s
 *
 * DDF Queue Misc Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vqx_misc_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for DDF_VQ(0..31)_MISC_INT[NWRP]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for DDF_VQ(0..31)_MISC_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for DDF_VQ(0..31)_MISC_INT[DOVF]. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for DDF_VQ(0..31)_MISC_INT[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for DDF_VQ(0..31)_MISC_INT[MBOX]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for DDF_VQ(0..31)_MISC_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for DDF_VQ(0..31)_MISC_INT[IRDE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for DDF_VQ(0..31)_MISC_INT[NWRP]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vqx_misc_ena_w1s_s cn; */
} bdk_ddf_vqx_misc_ena_w1s_t;

static inline uint64_t BDK_DDF_VQX_MISC_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VQX_MISC_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809020000510ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_VQX_MISC_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_VQX_MISC_ENA_W1S(a) bdk_ddf_vqx_misc_ena_w1s_t
#define bustype_BDK_DDF_VQX_MISC_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VQX_MISC_ENA_W1S(a) "DDF_VQX_MISC_ENA_W1S"
#define busnum_BDK_DDF_VQX_MISC_ENA_W1S(a) (a)
#define arguments_BDK_DDF_VQX_MISC_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_pf_ecc0_ena_w1c
 *
 * DDF ECC Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_ecc0_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1C/H) Reads or clears enable for DDF_PF_ECC0_INT[DBE]. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1C/H) Reads or clears enable for DDF_PF_ECC0_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1C/H) Reads or clears enable for DDF_PF_ECC0_INT[SBE]. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1C/H) Reads or clears enable for DDF_PF_ECC0_INT[DBE]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_ecc0_ena_w1c_s cn; */
} bdk_ddf_pf_ecc0_ena_w1c_t;

#define BDK_DDF_PF_ECC0_ENA_W1C BDK_DDF_PF_ECC0_ENA_W1C_FUNC()
static inline uint64_t BDK_DDF_PF_ECC0_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_ECC0_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000000250ll;
    __bdk_csr_fatal("DDF_PF_ECC0_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_ECC0_ENA_W1C bdk_ddf_pf_ecc0_ena_w1c_t
#define bustype_BDK_DDF_PF_ECC0_ENA_W1C BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_ECC0_ENA_W1C "DDF_PF_ECC0_ENA_W1C"
#define busnum_BDK_DDF_PF_ECC0_ENA_W1C 0
#define arguments_BDK_DDF_PF_ECC0_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) ddf_pf_ecc0_ena_w1s
 *
 * DDF ECC Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_ecc0_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets enable for DDF_PF_ECC0_INT[DBE]. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets enable for DDF_PF_ECC0_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1S/H) Reads or sets enable for DDF_PF_ECC0_INT[SBE]. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1S/H) Reads or sets enable for DDF_PF_ECC0_INT[DBE]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_ecc0_ena_w1s_s cn; */
} bdk_ddf_pf_ecc0_ena_w1s_t;

#define BDK_DDF_PF_ECC0_ENA_W1S BDK_DDF_PF_ECC0_ENA_W1S_FUNC()
static inline uint64_t BDK_DDF_PF_ECC0_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_ECC0_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000000240ll;
    __bdk_csr_fatal("DDF_PF_ECC0_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_ECC0_ENA_W1S bdk_ddf_pf_ecc0_ena_w1s_t
#define bustype_BDK_DDF_PF_ECC0_ENA_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_ECC0_ENA_W1S "DDF_PF_ECC0_ENA_W1S"
#define busnum_BDK_DDF_PF_ECC0_ENA_W1S 0
#define arguments_BDK_DDF_PF_ECC0_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) ddf_vq#_misc_int_w1s
 *
 * DDF Queue Misc Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vqx_misc_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets DDF_VQ(0..31)_MISC_INT[NWRP]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets DDF_VQ(0..31)_MISC_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets DDF_VQ(0..31)_MISC_INT[DOVF]. */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets DDF_VQ(0..31)_MISC_INT[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets DDF_VQ(0..31)_MISC_INT[MBOX]. */
        uint64_t dovf                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets DDF_VQ(0..31)_MISC_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets DDF_VQ(0..31)_MISC_INT[IRDE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets DDF_VQ(0..31)_MISC_INT[NWRP]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vqx_misc_int_w1s_s cn; */
} bdk_ddf_vqx_misc_int_w1s_t;

static inline uint64_t BDK_DDF_VQX_MISC_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VQX_MISC_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809020000508ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_VQX_MISC_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_VQX_MISC_INT_W1S(a) bdk_ddf_vqx_misc_int_w1s_t
#define bustype_BDK_DDF_VQX_MISC_INT_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VQX_MISC_INT_W1S(a) "DDF_VQX_MISC_INT_W1S"
#define busnum_BDK_DDF_VQX_MISC_INT_W1S(a) (a)
#define arguments_BDK_DDF_VQX_MISC_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_pf_ecc0_int
 *
 * DDF ECC Interrupt Status Register
 * This register contains the status of the ECC interrupt sources.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_ecc0_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1C/H) Double-bit error detected in internal RAM. One bit per memory, enumerated by
                                                                 DDF_RAMS_E. */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1C/H) Single-bit error detected in internal RAM. One bit per memory, enumerated by
                                                                 DDF_RAMS_E. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 32; /**< [ 31:  0](R/W1C/H) Single-bit error detected in internal RAM. One bit per memory, enumerated by
                                                                 DDF_RAMS_E. */
        uint64_t dbe                   : 32; /**< [ 63: 32](R/W1C/H) Double-bit error detected in internal RAM. One bit per memory, enumerated by
                                                                 DDF_RAMS_E. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_ecc0_int_s cn; */
} bdk_ddf_pf_ecc0_int_t;

#define BDK_DDF_PF_ECC0_INT BDK_DDF_PF_ECC0_INT_FUNC()
static inline uint64_t BDK_DDF_PF_ECC0_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_ECC0_INT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000000220ll;
    __bdk_csr_fatal("DDF_PF_ECC0_INT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_ECC0_INT bdk_ddf_pf_ecc0_int_t
#define bustype_BDK_DDF_PF_ECC0_INT BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_ECC0_INT "DDF_PF_ECC0_INT"
#define busnum_BDK_DDF_PF_ECC0_INT 0
#define arguments_BDK_DDF_PF_ECC0_INT -1,-1,-1,-1

/**
 * Register (NCB) ddf_pf_q#_ctl
 *
 * DDF Queue Control Register
 * This register configures queues.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_qx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t grp                   : 3;  /**< [  3:  1](RO) Reserved. */
        uint64_t pri                   : 1;  /**< [  0:  0](R/W) Queue priority.
                                                                 1 = This queue has higher priority. Round-robin between higher priority queues.
                                                                 0 = This queue has lower priority. Round-robin between lower priority queues. */
#else /* Word 0 - Little Endian */
        uint64_t pri                   : 1;  /**< [  0:  0](R/W) Queue priority.
                                                                 1 = This queue has higher priority. Round-robin between higher priority queues.
                                                                 0 = This queue has lower priority. Round-robin between lower priority queues. */
        uint64_t grp                   : 3;  /**< [  3:  1](RO) Reserved. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_qx_ctl_s cn; */
} bdk_ddf_pf_qx_ctl_t;

static inline uint64_t BDK_DDF_PF_QX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_QX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809008000000ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_PF_QX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_QX_CTL(a) bdk_ddf_pf_qx_ctl_t
#define bustype_BDK_DDF_PF_QX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_QX_CTL(a) "DDF_PF_QX_CTL"
#define busnum_BDK_DDF_PF_QX_CTL(a) (a)
#define arguments_BDK_DDF_PF_QX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_pf_msix_vec#_addr
 *
 * DDF PF MSI-X Vector-Table Address Registers
 * This register is the MSI-X vector table, indexed by the DDF_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's DDF_PF_MSIX_VEC()_ADDR, DDF_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of DDF_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_DDF_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's DDF_PF_MSIX_VEC()_ADDR, DDF_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of DDF_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_DDF_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_msix_vecx_addr_s cn; */
} bdk_ddf_pf_msix_vecx_addr_t;

static inline uint64_t BDK_DDF_PF_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_MSIX_VECX_ADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x809010000000ll + 0x10ll * ((a) & 0x1);
    __bdk_csr_fatal("DDF_PF_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_MSIX_VECX_ADDR(a) bdk_ddf_pf_msix_vecx_addr_t
#define bustype_BDK_DDF_PF_MSIX_VECX_ADDR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_MSIX_VECX_ADDR(a) "DDF_PF_MSIX_VECX_ADDR"
#define busnum_BDK_DDF_PF_MSIX_VECX_ADDR(a) (a)
#define arguments_BDK_DDF_PF_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_pf_mbox_ena_w1c#
 *
 * DDF PF Mailbox Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_mbox_ena_w1cx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for DDF_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for DDF_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_mbox_ena_w1cx_s cn; */
} bdk_ddf_pf_mbox_ena_w1cx_t;

static inline uint64_t BDK_DDF_PF_MBOX_ENA_W1CX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_MBOX_ENA_W1CX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x809000000440ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("DDF_PF_MBOX_ENA_W1CX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_MBOX_ENA_W1CX(a) bdk_ddf_pf_mbox_ena_w1cx_t
#define bustype_BDK_DDF_PF_MBOX_ENA_W1CX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_MBOX_ENA_W1CX(a) "DDF_PF_MBOX_ENA_W1CX"
#define busnum_BDK_DDF_PF_MBOX_ENA_W1CX(a) (a)
#define arguments_BDK_DDF_PF_MBOX_ENA_W1CX(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_pf_constants
 *
 * DDF PF Constants Register
 * This register contains implementation-related parameters of DDF in CNXXXX.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_constants_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t vq                    : 8;  /**< [  7:  0](RO) Number of VQs. */
#else /* Word 0 - Little Endian */
        uint64_t vq                    : 8;  /**< [  7:  0](RO) Number of VQs. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_constants_s cn; */
} bdk_ddf_pf_constants_t;

#define BDK_DDF_PF_CONSTANTS BDK_DDF_PF_CONSTANTS_FUNC()
static inline uint64_t BDK_DDF_PF_CONSTANTS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_CONSTANTS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000000000ll;
    __bdk_csr_fatal("DDF_PF_CONSTANTS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_CONSTANTS bdk_ddf_pf_constants_t
#define bustype_BDK_DDF_PF_CONSTANTS BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_CONSTANTS "DDF_PF_CONSTANTS"
#define busnum_BDK_DDF_PF_CONSTANTS 0
#define arguments_BDK_DDF_PF_CONSTANTS -1,-1,-1,-1

/**
 * Register (NCB) ddf_pf_diag2
 *
 * DDF PF Diagnostic Control Register 2
 * This register controls diagnostic features.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_diag2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t cacdis                : 1;  /**< [  0:  0](R/W) Disable caching between transactions. For diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint64_t cacdis                : 1;  /**< [  0:  0](R/W) Disable caching between transactions. For diagnostic use only. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_diag2_s cn; */
} bdk_ddf_pf_diag2_t;

#define BDK_DDF_PF_DIAG2 BDK_DDF_PF_DIAG2_FUNC()
static inline uint64_t BDK_DDF_PF_DIAG2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_DIAG2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000000600ll;
    __bdk_csr_fatal("DDF_PF_DIAG2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_DIAG2 bdk_ddf_pf_diag2_t
#define bustype_BDK_DDF_PF_DIAG2 BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_DIAG2 "DDF_PF_DIAG2"
#define busnum_BDK_DDF_PF_DIAG2 0
#define arguments_BDK_DDF_PF_DIAG2 -1,-1,-1,-1

/**
 * Register (NCB) ddf_pf_ecc0_ctl
 *
 * DDF PF ECC Control Register
 * This register enables ECC for each individual internal memory that requires ECC. For debug
 * purposes, it can also flip one or two bits in the ECC data.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_ecc0_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t cdis                  : 32; /**< [ 31:  0](R/W) Disables ECC correction on each RAM.  Bit positions enumerated with DDF_RAMS_E. */
#else /* Word 0 - Little Endian */
        uint64_t cdis                  : 32; /**< [ 31:  0](R/W) Disables ECC correction on each RAM.  Bit positions enumerated with DDF_RAMS_E. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_ecc0_ctl_s cn; */
} bdk_ddf_pf_ecc0_ctl_t;

#define BDK_DDF_PF_ECC0_CTL BDK_DDF_PF_ECC0_CTL_FUNC()
static inline uint64_t BDK_DDF_PF_ECC0_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_ECC0_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000000200ll;
    __bdk_csr_fatal("DDF_PF_ECC0_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_ECC0_CTL bdk_ddf_pf_ecc0_ctl_t
#define bustype_BDK_DDF_PF_ECC0_CTL BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_ECC0_CTL "DDF_PF_ECC0_CTL"
#define busnum_BDK_DDF_PF_ECC0_CTL 0
#define arguments_BDK_DDF_PF_ECC0_CTL -1,-1,-1,-1

/**
 * Register (NCB) ddf_pf_inst_req_pc
 *
 * DDF PF Instruction Request Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_inst_req_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of instructions that have started processing. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of instructions that have started processing. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_inst_req_pc_s cn; */
} bdk_ddf_pf_inst_req_pc_t;

#define BDK_DDF_PF_INST_REQ_PC BDK_DDF_PF_INST_REQ_PC_FUNC()
static inline uint64_t BDK_DDF_PF_INST_REQ_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_INST_REQ_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000010000ll;
    __bdk_csr_fatal("DDF_PF_INST_REQ_PC", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_INST_REQ_PC bdk_ddf_pf_inst_req_pc_t
#define bustype_BDK_DDF_PF_INST_REQ_PC BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_INST_REQ_PC "DDF_PF_INST_REQ_PC"
#define busnum_BDK_DDF_PF_INST_REQ_PC 0
#define arguments_BDK_DDF_PF_INST_REQ_PC -1,-1,-1,-1

/**
 * Register (NCB) ddf_pf_bist_status
 *
 * DDF PF Control Bist Status Register
 * This register has the BIST status of memories. Each bit is the BIST result of an
 * individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t bstatus               : 32; /**< [ 31:  0](RO/H) BIST status. One bit per memory, enumerated by DDF_RAMS_E. */
#else /* Word 0 - Little Endian */
        uint64_t bstatus               : 32; /**< [ 31:  0](RO/H) BIST status. One bit per memory, enumerated by DDF_RAMS_E. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_bist_status_s cn; */
} bdk_ddf_pf_bist_status_t;

#define BDK_DDF_PF_BIST_STATUS BDK_DDF_PF_BIST_STATUS_FUNC()
static inline uint64_t BDK_DDF_PF_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_BIST_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000000160ll;
    __bdk_csr_fatal("DDF_PF_BIST_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_BIST_STATUS bdk_ddf_pf_bist_status_t
#define bustype_BDK_DDF_PF_BIST_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_BIST_STATUS "DDF_PF_BIST_STATUS"
#define busnum_BDK_DDF_PF_BIST_STATUS 0
#define arguments_BDK_DDF_PF_BIST_STATUS -1,-1,-1,-1

/**
 * Register (NCB) ddf_vq#_done_ena_w1c
 *
 * DDF Queue Done Interrupt Enable Clear Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vqx_done_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done                  : 1;  /**< [  0:  0](R/W1C/H) Read or clears DDF_VQ()_DONE_ENA_W1S[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1C/H) Read or clears DDF_VQ()_DONE_ENA_W1S[DONE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vqx_done_ena_w1c_s cn; */
} bdk_ddf_vqx_done_ena_w1c_t;

static inline uint64_t BDK_DDF_VQX_DONE_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VQX_DONE_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809020000478ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_VQX_DONE_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_VQX_DONE_ENA_W1C(a) bdk_ddf_vqx_done_ena_w1c_t
#define bustype_BDK_DDF_VQX_DONE_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VQX_DONE_ENA_W1C(a) "DDF_VQX_DONE_ENA_W1C"
#define busnum_BDK_DDF_VQX_DONE_ENA_W1C(a) (a)
#define arguments_BDK_DDF_VQX_DONE_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_vq#_done_ena_w1s
 *
 * DDF Queue Done Interrupt Enable Set Registers
 * Write 1 to these registers will enable the DONEINT interrupt for the queue.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vqx_done_ena_w1s_s
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
    /* struct bdk_ddf_vqx_done_ena_w1s_s cn; */
} bdk_ddf_vqx_done_ena_w1s_t;

static inline uint64_t BDK_DDF_VQX_DONE_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VQX_DONE_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809020000470ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_VQX_DONE_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_VQX_DONE_ENA_W1S(a) bdk_ddf_vqx_done_ena_w1s_t
#define bustype_BDK_DDF_VQX_DONE_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VQX_DONE_ENA_W1S(a) "DDF_VQX_DONE_ENA_W1S"
#define busnum_BDK_DDF_VQX_DONE_ENA_W1S(a) (a)
#define arguments_BDK_DDF_VQX_DONE_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_vf#_msix_vec#_ctl
 *
 * DDF VF MSI-X Vector-Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the DDF_VF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vfx_msix_vecx_ctl_s
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
    /* struct bdk_ddf_vfx_msix_vecx_ctl_s cn; */
} bdk_ddf_vfx_msix_vecx_ctl_t;

static inline uint64_t BDK_DDF_VFX_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VFX_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=1)))
        return 0x809030000008ll + 0x100000ll * ((a) & 0x1f) + 0x10ll * ((b) & 0x1);
    __bdk_csr_fatal("DDF_VFX_MSIX_VECX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_DDF_VFX_MSIX_VECX_CTL(a,b) bdk_ddf_vfx_msix_vecx_ctl_t
#define bustype_BDK_DDF_VFX_MSIX_VECX_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VFX_MSIX_VECX_CTL(a,b) "DDF_VFX_MSIX_VECX_CTL"
#define busnum_BDK_DDF_VFX_MSIX_VECX_CTL(a,b) (a)
#define arguments_BDK_DDF_VFX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) ddf_pf_eco
 *
 * INTERNAL: DDF PF ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_pf_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) INTERNAL: Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) INTERNAL: Reserved for ECO usage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_pf_eco_s cn; */
} bdk_ddf_pf_eco_t;

#define BDK_DDF_PF_ECO BDK_DDF_PF_ECO_FUNC()
static inline uint64_t BDK_DDF_PF_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_PF_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x809000000140ll;
    __bdk_csr_fatal("DDF_PF_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_DDF_PF_ECO bdk_ddf_pf_eco_t
#define bustype_BDK_DDF_PF_ECO BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_PF_ECO "DDF_PF_ECO"
#define busnum_BDK_DDF_PF_ECO 0
#define arguments_BDK_DDF_PF_ECO -1,-1,-1,-1

/**
 * Register (NCB) ddf_vq#_saddr
 *
 * DDF Queue Starting Buffer Address Registers
 * These registers set the instruction buffer starting address.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vqx_saddr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t ptr                   : 43; /**< [ 48:  6](R/W/H) Instruction buffer pointer bits <48:7> (128-byte aligned). When written, it is the initial
                                                                 buffer starting address; when read, it is the next read pointer to be requested from L2C.
                                                                 The PTR field is overwritten with the next pointer each time that the command buffer
                                                                 segment is exhausted. New commands will then be read from the newly specified command
                                                                 buffer pointer.

                                                                 Bit<6> must be zero. */
        uint64_t off                   : 6;  /**< [  5:  0](RAZ) Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t off                   : 6;  /**< [  5:  0](RAZ) Reserved. */
        uint64_t ptr                   : 43; /**< [ 48:  6](R/W/H) Instruction buffer pointer bits <48:7> (128-byte aligned). When written, it is the initial
                                                                 buffer starting address; when read, it is the next read pointer to be requested from L2C.
                                                                 The PTR field is overwritten with the next pointer each time that the command buffer
                                                                 segment is exhausted. New commands will then be read from the newly specified command
                                                                 buffer pointer.

                                                                 Bit<6> must be zero. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vqx_saddr_s cn; */
} bdk_ddf_vqx_saddr_t;

static inline uint64_t BDK_DDF_VQX_SADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VQX_SADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809020000200ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_VQX_SADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_VQX_SADDR(a) bdk_ddf_vqx_saddr_t
#define bustype_BDK_DDF_VQX_SADDR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VQX_SADDR(a) "DDF_VQX_SADDR"
#define busnum_BDK_DDF_VQX_SADDR(a) (a)
#define arguments_BDK_DDF_VQX_SADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) ddf_vq#_done
 *
 * DDF Queue Done Count Registers
 * These registers contain the per-queue instruction done count.
 */
typedef union
{
    uint64_t u;
    struct bdk_ddf_vqx_done_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t done                  : 20; /**< [ 19:  0](R/W/H) Done count. When DDF_INST_FIND_S/DDF_INST_MATCH_S[DONEINT] set and that
                                                                 instruction completes, DDF_VQ()_DONE[DONE] is incremented when the instruction
                                                                 finishes. Write to this field are for diagnostic use only; instead software
                                                                 writes DDF_VQ()_DONE_ACK with the number of decrements for this field.

                                                                 Interrupts are sent as follows:

                                                                 * When DDF_VQ()_DONE[DONE] = 0, then no results are pending, the interrupt
                                                                 coalescing timer is held to zero, and an interrupt is not sent.

                                                                 * When DDF_VQ()_DONE[DONE] != 0, then the interrupt coalescing timer
                                                                 counts. If the counter is >= DDF_VQ()_DONE_WAIT[TIME_WAIT]*1024, or
                                                                 DDF_VQ()_DONE[DONE] >= DDF_VQ()_DONE_WAIT[NUM_WAIT], i.e.enough time has
                                                                 passed or enough results have arrived, then the interrupt is sent.  Otherwise,
                                                                 it is not sent due to coalescing.

                                                                 * When DDF_VQ()_DONE_ACK is written, the interrupt coalescing timer restarts.
                                                                 Note after decrementing this interrupt equation is recomputed, for example if
                                                                 DDF_VQ()_DONE[DONE] >= DDF_VQ()_DONE_WAIT[NUM_WAIT] and the timer is zero,
                                                                 the interrupt will be resent immediately.  (This covers the race case between
                                                                 software acknowledging an interrupt and a result returning.)

                                                                 * When DDF_VQ()_DONE_ENA_W1S[DONE] = 0, interrupts are not sent, but the
                                                                 counting described above still occurs.

                                                                 Since DDF instructions complete out-of-order, if software is using completion
                                                                 interrupts the suggested scheme is to request a DONEINT on each request, and
                                                                 when an interrupt arrives perform a "greedy" scan for completions; even if a
                                                                 later command is acknowledged first this will not result in missing a
                                                                 completion. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 20; /**< [ 19:  0](R/W/H) Done count. When DDF_INST_FIND_S/DDF_INST_MATCH_S[DONEINT] set and that
                                                                 instruction completes, DDF_VQ()_DONE[DONE] is incremented when the instruction
                                                                 finishes. Write to this field are for diagnostic use only; instead software
                                                                 writes DDF_VQ()_DONE_ACK with the number of decrements for this field.

                                                                 Interrupts are sent as follows:

                                                                 * When DDF_VQ()_DONE[DONE] = 0, then no results are pending, the interrupt
                                                                 coalescing timer is held to zero, and an interrupt is not sent.

                                                                 * When DDF_VQ()_DONE[DONE] != 0, then the interrupt coalescing timer
                                                                 counts. If the counter is >= DDF_VQ()_DONE_WAIT[TIME_WAIT]*1024, or
                                                                 DDF_VQ()_DONE[DONE] >= DDF_VQ()_DONE_WAIT[NUM_WAIT], i.e.enough time has
                                                                 passed or enough results have arrived, then the interrupt is sent.  Otherwise,
                                                                 it is not sent due to coalescing.

                                                                 * When DDF_VQ()_DONE_ACK is written, the interrupt coalescing timer restarts.
                                                                 Note after decrementing this interrupt equation is recomputed, for example if
                                                                 DDF_VQ()_DONE[DONE] >= DDF_VQ()_DONE_WAIT[NUM_WAIT] and the timer is zero,
                                                                 the interrupt will be resent immediately.  (This covers the race case between
                                                                 software acknowledging an interrupt and a result returning.)

                                                                 * When DDF_VQ()_DONE_ENA_W1S[DONE] = 0, interrupts are not sent, but the
                                                                 counting described above still occurs.

                                                                 Since DDF instructions complete out-of-order, if software is using completion
                                                                 interrupts the suggested scheme is to request a DONEINT on each request, and
                                                                 when an interrupt arrives perform a "greedy" scan for completions; even if a
                                                                 later command is acknowledged first this will not result in missing a
                                                                 completion. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ddf_vqx_done_s cn; */
} bdk_ddf_vqx_done_t;

static inline uint64_t BDK_DDF_VQX_DONE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DDF_VQX_DONE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x809020000420ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("DDF_VQX_DONE", 1, a, 0, 0, 0);
}

#define typedef_BDK_DDF_VQX_DONE(a) bdk_ddf_vqx_done_t
#define bustype_BDK_DDF_VQX_DONE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_DDF_VQX_DONE(a) "DDF_VQX_DONE"
#define busnum_BDK_DDF_VQX_DONE(a) (a)
#define arguments_BDK_DDF_VQX_DONE(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_DDF_H__ */
