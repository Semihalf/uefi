#ifndef __BDK_CSRS_ZIP__
#define __BDK_CSRS_ZIP__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2014  Cavium Networks (support@cavium.com). All rights
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

 *   * Neither the name of Cavium Networks nor the names of
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
 * Cavium ZIP.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration ZIP_COMP_E
 *
 * ZIP Completion Enumeration
 * Enumerates the values of ZIP_ZRES_S[COMPCODE].
 */
enum zip_comp_e {
	ZIP_COMP_E_BADCODE = 0x7,
	ZIP_COMP_E_BADCODE2 = 0x8,
	ZIP_COMP_E_DTRUNC = 0x2,
	ZIP_COMP_E_FATAL = 0xb,
	ZIP_COMP_E_ITRUNC = 0x4,
	ZIP_COMP_E_NLEN = 0x6,
	ZIP_COMP_E_NOTDONE = 0x0,
	ZIP_COMP_E_PARITY = 0xa,
	ZIP_COMP_E_RBLOCK = 0x5,
	ZIP_COMP_E_STOP = 0x3,
	ZIP_COMP_E_SUCCESS = 0x1,
	ZIP_COMP_E_ZERO_LEN = 0x9,
	ZIP_COMP_E_ENUM_LAST = 0xc,
};

/**
 * Enumeration ZIP_INT_VEC_E
 *
 * ZIP MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum zip_int_vec_e {
	ZIP_INT_VEC_E_ECCE = 0x10,
	ZIP_INT_VEC_E_FIFE = 0x11,
	ZIP_INT_VEC_E_QUE0_DONE = 0x0,
	ZIP_INT_VEC_E_QUE0_ERR = 0x8,
	ZIP_INT_VEC_E_QUE1_DONE = 0x1,
	ZIP_INT_VEC_E_QUE1_ERR = 0x9,
	ZIP_INT_VEC_E_QUE2_DONE = 0x2,
	ZIP_INT_VEC_E_QUE2_ERR = 0xa,
	ZIP_INT_VEC_E_QUE3_DONE = 0x3,
	ZIP_INT_VEC_E_QUE3_ERR = 0xb,
	ZIP_INT_VEC_E_QUE4_DONE = 0x4,
	ZIP_INT_VEC_E_QUE4_ERR = 0xc,
	ZIP_INT_VEC_E_QUE5_DONE = 0x5,
	ZIP_INT_VEC_E_QUE5_ERR = 0xd,
	ZIP_INT_VEC_E_QUE6_DONE = 0x6,
	ZIP_INT_VEC_E_QUE6_ERR = 0xe,
	ZIP_INT_VEC_E_QUE7_DONE = 0x7,
	ZIP_INT_VEC_E_QUE7_ERR = 0xf,
	ZIP_INT_VEC_E_ENUM_LAST = 0x12,
};


/**
 * Structure ZIP_INST_S
 *
 * ZIP Instruction Structure
 * Each ZIP instruction has 16 words (they are called IWORD0 to IWORD15 within the structure).
 */
union zip_inst_s {
	uint64_t u[16];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_960_1023           : 64; /**< [1023:960] Reserved. MBZ. */
		uint64_t reserved_896_959            : 64; /**< [959:896] Reserved. MBZ. */
		uint64_t reserved_882_895            : 14; /**< [895:882] Reserved. */
		uint64_t tt                          : 2;  /**< [881:880] Reserved. INTERNAL: For 86xx: If WQ_PTR is non-zero, the SSO tag type to use when the ZIP
                                                                 coprocessor submits to SSO. */
		uint64_t reserved_874_879            : 6;  /**< [879:874] Reserved. */
		uint64_t grp                         : 10; /**< [873:864] Reserved. INTERNAL: For 86xx: If WQ_PTR is non-zero, the SSO group to use when the ZIP
                                                                 coprocessor submits to SSO. */
		uint64_t tag                         : 32; /**< [863:832] Reserved. INTERNAL: For 86xx: If WQ_PTR is non-zero, the SSO tag type to use when the ZIP
                                                                 coprocessor submits to SSO. */
		uint64_t reserved_817_831            : 15; /**< [831:817] Reserved. */
		uint64_t wq_ptr                      : 49; /**< [816:768] Reserved. INTERNAL: For 86xx: If WQ_PTR is non-zero, it is a pointer to a work-queue entry
                                                                 that the ZIP coprocessor submits to SSO after all context, output data, and result write
                                                                 operations are visible to other CNXXXX units and the cores. */
		uint64_t res_ptr_ctl                 : 64; /**< [767:704] Result pointer control (ZIP_ZPTR_S format control word definition).

                                                                 Inside this ZIP_ZPTR_S:
                                                                   * ZIP_ZPTR_S[FW] can be either 0 or 1.
                                                                   * ZIP_ZPTR_S[NC] can be either 0 or 1.
                                                                   * ZIP_ZPTR_S[DATA_BE] must be 0.
                                                                   * ZIP_ZPTR_S[LENGTH] must be 0. (24-bytes is implied).
                                                                   * ZIP_ZPTR_S[ADDR] must be eight-byte aligned. */
		uint64_t res_ptr_addr                : 64; /**< [703:640] Result pointer address (ZIP_ZPTR_S format address word definition).
                                                                 Address is 8-byte aligned. */
		uint64_t out_ptr_ctl                 : 64; /**< [639:576] Output pointer control (ZIP_ZPTR_S format control word definition).
                                                                 [DS] set if scatter. */
		uint64_t out_ptr_addr                : 64; /**< [575:512] Output pointer address  (ZIP_ZPTR_S format address word definition).
                                                                 Points to where the output data will be written by the ZIP coprocessor for this
                                                                 invocation. */
		uint64_t inp_ptr_ctl                 : 64; /**< [511:448] Input and compresion history pointer control (ZIP_ZPTR_S format control word definition).
                                                                 FW = 0. ZIP_INST_S[DG] set if gather. */
		uint64_t inp_ptr_addr                : 64; /**< [447:384] Input and compresion history pointer address (ZIP_ZPTR_S format address word definition). */
		uint64_t his_ptr_ctl                 : 64; /**< [383:320] Decompresion history pointer control (ZIP_ZPTR_S format control word definition).
                                                                 FW = 0. ZIP_INST_S[HG] set if gather. */
		uint64_t his_ptr_addr                : 64; /**< [319:256] Decompresion history pointer address (ZIP_ZPTR_S format address word definition). */
		uint64_t ctx_ptr_ctl                 : 64; /**< [255:192] Decompresion context pointer control (ZIP_ZPTR_S format control word definition).
                                                                 DATA_BE = 0 and LENGTH=0 (2048 bytes implied). */
		uint64_t ctx_ptr_addr                : 64; /**< [191:128] Decompresion context pointer address (ZIP_ZPTR_S format address word definition).
                                                                 The address must be 8-byte aligned. */
		uint64_t historylength               : 16; /**< [127:112] With compression, history bytes can be prepended in the input data stream
                                                                 before the bytes that are actually to be compressed. These history bytes
                                                                 are generally the (uncompressed) file input bytes immediately preceding the file
                                                                 bytes being compressed. However, it is also possible to pass in a preset dictionary at
                                                                 the beginning of the file (which will be followed by the first bytes of the file).
                                                                 HISTORYLENGTH must never exceed ZIP_CONSTANTS[DEPTH].
                                                                 HISTORYLENGTH must never exceed the sum of the preset dictionary size plus the
                                                                 number of bytes previously processed in the (uncompressed) input data stream for
                                                                 the file. The supplied history bytes must exactly match the bytes previously
                                                                 processed in the (uncompressed) input data stream for the file, preceded by the
                                                                 preset dictionary, if necessary.
                                                                 HISTORYLENGTH must never exceed 2048 with LZS. */
		uint64_t reserved_96_111             : 16; /**< [111: 96] Reserved. */
		uint64_t adlercrc32                  : 32; /**< [ 95: 64] This 32-bit field represents the current state of the ADLER32 or CRC32 units. The
                                                                 hardware executes both ADLER32 and CRC32 on the processed uncompressed data
                                                                 bytes using this value as the current checksum. Though the hardware outputs both
                                                                 the ADLER32 and CRC32 results, ADLERCRC32 is the only checksum input, so only
                                                                 one of the two outputs is likely to be useful.

                                                                 The ADLER32 algorithm is defined in RFC1950.

                                                                 CRC32 is defined in ITU-T X.244, Annex D, pp. 144-145 / ISO 8073. */
		uint64_t doneint                     : 1;  /**< [ 63: 63] Done Interrupt. When DONEINT is set and the instruction completes,
                                                                 ZIP_QUE(0..7)_DONE[DONE] will be incremented. */
		uint64_t reserved_56_62              : 7;  /**< [ 62: 56] Reserved. */
		uint64_t totaloutputlength           : 24; /**< [ 55: 32] Indicates the maximum number of output-stream bytes that can be written.
                                                                 TOTALOUTPUTLENGTH must exactly match the number of bytes indicated by
                                                                 the output pointer (either by ZPTR[LENGTH] directly if
                                                                 [DS] = 0, or indirectly if [DS] = 1). */
		uint64_t reserved_27_31              : 5;  /**< [ 31: 27] Reserved. */
		uint64_t exn                         : 3;  /**< [ 26: 24] EXN is the number of bits produced beyond the last output byte written by
                                                                 the prior ZIP coprocessor invocation. */
		uint64_t reserved_23_23              : 1;  /**< [ 23: 23] Reserved. */
		uint64_t exbits                      : 7;  /**< [ 22: 16] EXN,EXBITS are the previously-generated compressed bits beyond the last
                                                                 compressed byte written for the file. These bits are required context for partial-file
                                                                 processing because the ZIP compression algorithm produces a compressed bit
                                                                 stream, but the output stream is in bytes.

                                                                 EXN,EXBITS must be 0x0 when [BF] = 1. If [BF] = 0,
                                                                 EXN, EXBITS typically equal the ZIP_ZRES_S[EXN], ZIP_ZRES_S[EXBITS] from the
                                                                 previous ZIP compression coprocessor invocation for the file. (If software instead
                                                                 inserts its own blocks in the compressed output stream between ZIP compression
                                                                 coprocessor invocations, [EXN], [EXBITS] will instead be the
                                                                 result after the last software insertion.)

                                                                 EXBITS contains the extra bits. Bit <0> contains the first extra bit, <1> the
                                                                 second extra bit, etc. All unused EXBITS bits must be 0x0.

                                                                 For decompression, EXN, EXBITS must be 0x0 */
		uint64_t reserved_12_15              : 4;  /**< [ 15: 12] Reserved. */
		uint64_t sf                          : 1;  /**< [ 11: 11] SYNC_FLUSH. When set, enables SYNC_FLUSH functionality.

                                                                 For DEFLATE compression,
                                                                 SYNC_FLUSH forces ZIP hardware to append a zero-length nocompress
                                                                 block to the end of the partial compressed data stream. This forces the partial
                                                                 compressed stream to be byte-aligned. This grows the output by 35-39 bits.
                                                                 [SF] must not be set when [EF] is set.
                                                                 ZIP_ZRES_S[EXN,EXBITS] will always be 0x0 when [SF] is set.

                                                                 For LZS compression,
                                                                 [SF] must always be set whenever [EF] is clear. ZIP
                                                                 hardware always inserts an end-of-block marker at the end of the partial
                                                                 compressed data stream. This forces the partial compressed stream to be
                                                                 byte-aligned. [SF] must not be set when [EF] is set.
                                                                 ZIP_ZRES_S[EXN,EXBITS] will always be 0x0.

                                                                 For decompression,
                                                                 [SF] should always be set. */
		uint64_t ss                          : 2;  /**< [ 10:  9] Compression speed/storage.
                                                                 Forces the ZIP compression engine to compress faster, at the expense of the compression
                                                                 ratio.

                                                                 For compression:
                                                                 0x0 = best quality, slowest speed.
                                                                 0x2 = lower quality, faster speed.
                                                                 0x1 = medium quality, medium speed.
                                                                 0x3 = lowest quality, best speed.

                                                                 For decompression, SS must be 0x0. */
		uint64_t cc                          : 2;  /**< [  8:  7] Compression coding.

                                                                 For compression:
                                                                 0x0 = hardware selects the better of fixed or dynamic Huffman encoding.
                                                                 0x1 = force dynamic Huffman encoding.
                                                                 0x2 = force fixed Huffman encoding.
                                                                 0x3 = force LZS encoding.

                                                                 For DEFLATE decompression, CC must be 0x0. For LZS decompression, CC must be 0x3. */
		uint64_t ef                          : 1;  /**< [  6:  6] End of input data. Set when the end of the input-data stream ends a file.

                                                                 For compression, if EF = 1, the ZIP engine always marks the last output block to be
                                                                 final. (The extra bits are zero-extended and written out as an output-stream byte.)

                                                                 For decompression, it is an error if EF = 1 and the ZIP coprocessor does not complete
                                                                 decompression of all blocks before it exhausts the input compressed data stream
                                                                 (ZIP_ZRES_S[COMPCODE] = ZIP_COMP_E::ITRUNC in this case.). It is not an error if EF = 0
                                                                 when the ZIP coprocessor completes decompression of all blocks in the file. */
		uint64_t bf                          : 1;  /**< [  5:  5] Beginning of file. Set when the beginning of the (non-history) input stream starts a
                                                                 file.

                                                                 For compression:
                                                                 0 = first byte of input data is not the beginning of the file.
                                                                 1 = first byte of input data (after history data or not) is the beginning of the file.
                                                                 Note that in the compress case when [HISTORYLENGTH] is non-zero, the
                                                                 beginning of the input data stream is history data. Regardless of whether history
                                                                 data is present for a compress, BF should indicate whether the first non-history byte
                                                                 (i.e. the byte at position [HISTORYLENGTH] in the input data stream) is
                                                                 the first byte of the file.

                                                                 For decompression:
                                                                 0 = not the beginning of the file, read context from memory.
                                                                 1 = beginning of the file, create a new context. */
		uint64_t ce                          : 1;  /**< [  4:  4] Compression enable:
                                                                 1 = ZIP operation is a compress.
                                                                 0 = ZIP operation is an uncompress. */
		uint64_t reserved_3_3                : 1;  /**< [  3:  3] Reserved. */
		uint64_t ds                          : 1;  /**< [  2:  2] Data scatter:
                                                                 1 = IWORD8/9 (the output pointer) points to a list of scatter pointers that are read
                                                                 by the coprocessor before writing the actual output data.
                                                                 0 = IWORD8/9 points directly at the locations to write the output data.

                                                                 If DS = 1, the IWORD9 LENGTH field, indicating the number of pointers in the
                                                                 output scatter list, must be at least 0x2. */
		uint64_t dg                          : 1;  /**< [  1:  1] Data gather:
                                                                 1 = IWORD6/7 (the input and compression history pointer) points to a gather list of
                                                                 pointers that are read by the coprocessor before reading the actual history/input data.
                                                                 0 = IWORD6/7 points directly at the actual history/input data.

                                                                 If DG = 1, the IWORD7 LENGTH field, indicating the number of pointers in the
                                                                 input and compression history gather list, must be at least 0x2. */
		uint64_t hg                          : 1;  /**< [  0:  0] History gather:
                                                                 1 = IWORD4/5 (the decompression history pointer) points to a gather list of
                                                                 pointers that are read by the coprocessor before reading the actual history data.
                                                                 0 = IWORD4/5 points directly at the actual history data.
                                                                 HG must be zero for a compression operation.

                                                                 If HG = 1, history data must be present for the decompression operation, and the
                                                                 IWORD5 LENGTH field, indicating the number of pointers in the decompression
                                                                 history gather list, must be at least 0x2. */
#else
		uint64_t hg                          : 1;
		uint64_t dg                          : 1;
		uint64_t ds                          : 1;
		uint64_t reserved_3_3                : 1;
		uint64_t ce                          : 1;
		uint64_t bf                          : 1;
		uint64_t ef                          : 1;
		uint64_t cc                          : 2;
		uint64_t ss                          : 2;
		uint64_t sf                          : 1;
		uint64_t reserved_12_15              : 4;
		uint64_t exbits                      : 7;
		uint64_t reserved_23_23              : 1;
		uint64_t exn                         : 3;
		uint64_t reserved_27_31              : 5;
		uint64_t totaloutputlength           : 24;
		uint64_t reserved_56_62              : 7;
		uint64_t doneint                     : 1;
		uint64_t adlercrc32                  : 32;
		uint64_t reserved_96_111             : 16;
		uint64_t historylength               : 16;
		uint64_t ctx_ptr_addr                : 64;
		uint64_t ctx_ptr_ctl                 : 64;
		uint64_t his_ptr_addr                : 64;
		uint64_t his_ptr_ctl                 : 64;
		uint64_t inp_ptr_addr                : 64;
		uint64_t inp_ptr_ctl                 : 64;
		uint64_t out_ptr_addr                : 64;
		uint64_t out_ptr_ctl                 : 64;
		uint64_t res_ptr_addr                : 64;
		uint64_t res_ptr_ctl                 : 64;
		uint64_t wq_ptr                      : 49;
		uint64_t reserved_817_831            : 15;
		uint64_t tag                         : 32;
		uint64_t grp                         : 10;
		uint64_t reserved_874_879            : 6;
		uint64_t tt                          : 2;
		uint64_t reserved_882_895            : 14;
		uint64_t reserved_896_959            : 64;
		uint64_t reserved_960_1023           : 64;
#endif
	} s;
};

/**
 * Structure ZIP_NPTR_S
 *
 * ZIP Instruction Next-Chunk-Buffer Pointer (NPTR) Structure
 * ZIP_NPTR structure is used to chain all the zip instruction buffers together. ZIP instruction
 * buffers are managed (allocated and released) by software.
 */
union zip_nptr_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15; /**< [ 63: 49] Reserved. MBZ. */
		uint64_t addr                        : 49; /**< [ 48:  0] ZIP_ZPTR_S[ADDR]<6:0> must be zero. All the ZIP instruction buffers must be aligned on an
                                                                 128 byte boundary. */
#else
		uint64_t addr                        : 49;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
};

/**
 * Structure ZIP_ZPTR_S
 *
 * ZIP Generic Pointer Structure
 * This structure is the generic format of pointers in ZIP_INST_S.
 */
union zip_zptr_s {
	uint64_t u[2];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_112_127            : 16; /**< [127:112] Reserved. */
		uint64_t length                      : 16; /**< [111: 96] In case (a) and (c) under [ADDR], [LENGTH] is the number of bytes pointed at by [ADDR].
                                                                 [LENGTH] must be nonzero in this case.
                                                                 In case (b) under [ADDR], [LENGTH] is the number of gather/ scatter list pointer entries
                                                                 pointed at by ADDR. ([LENGTH]*16 is the number of bytes.) [LENGTH] must be at least 2 in
                                                                 this case.
                                                                 [LENGTH] must be zero for context and result pointers, because each has an implied fixed-
                                                                 size length (of ZIP_CONSTANTS[CTXSIZE] or fewer bytes and 24 bytes, respectively). */
		uint64_t reserved_67_95              : 29; /**< [ 95: 67] Reserved. */
		uint64_t fw                          : 1;  /**< [ 66: 66] Full-block write. [FW] may be set in any case (a) or (c) where stores to [ADDR] can be
                                                                 generated to indicate that the hardware may write random values into all bytes of all
                                                                 cache blocks touched by the range [ADDR] ... [ADDR]+[LENGTH]-1.
                                                                 [FW] must not be set in case (b) above, or whenever stores to [ADDR] cannot possibly be
                                                                 generated. */
		uint64_t nc                          : 1;  /**< [ 65: 65] No cache allocation. [NC] may be set in any case to indicate that the read/write
                                                                 operations generated should preferably not load cache blocks into the L2 cache.
                                                                 Note that in case (b) above, [NC] indicates that the gather/scatter list should not be
                                                                 loaded into the cache. In cases (a) and (c) above, [NC] indicates that the data or results
                                                                 should not be loaded into the L2 cache.
                                                                 Note that the ZIP hardware will ignore [NC] for write operations when full cache blocks
                                                                 cannot be written. */
		uint64_t data_be                     : 1;  /**< [ 64: 64] Big-endian. [DATA_BE] may be set in case (a) or (c) above, indicating that [ADDR]
                                                                 and the byte stream indicated by it is in big endian format.
                                                                 [DATA_BE] must never be set in case (b) above, and must never be set for context or result
                                                                 pointers. */
		uint64_t reserved_49_63              : 15; /**< [ 63: 49] Reserved. */
		uint64_t addr                        : 49; /**< [ 48:  0] When a ZIP_ZPTR_S is in an instruction word, [ADDR] is either:
                                                                 A direct byte pointer into L2C/DDR attached memory, or
                                                                 A pointer to a gather/scatter list in memory.
                                                                 When a ZIP_ZPTR_S is in a gather/scatter list, [ADDR] is:
                                                                 A direct byte pointer into the attached memory.
                                                                 In case (b) above, and for context and result pointers, [ADDR]<3:0> must be zero. (All
                                                                 these cases must be aligned on an 16 byte boundary.)
                                                                 In cases (a) or (c) above, [ADDR] may be any byte alignment (except for context and result
                                                                 pointers). */
#else
		uint64_t addr                        : 49;
		uint64_t reserved_49_63              : 15;
		uint64_t data_be                     : 1;
		uint64_t nc                          : 1;
		uint64_t fw                          : 1;
		uint64_t reserved_67_95              : 29;
		uint64_t length                      : 16;
		uint64_t reserved_112_127            : 16;
#endif
	} s;
};

/**
 * Structure ZIP_ZRES_S
 *
 * ZIP Result Structure
 * The ZIP coprocessor writes the result structure after it completes the invocation.
 * The result structure is exactly 24 bytes, and each invocation of the ZIP coprocessor
 * produces exactly one result structure.
 */
union zip_zres_s {
	uint64_t u[3];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t totalbitsprocessed          : 32; /**< [191:160] When [EF] = 1 for an error-free decompression operation,
                                                                 TOTALBITSPROCESSED indicates the number of compressed input bits consumed
                                                                 to decompress all blocks in the file. (TOTALBITSPROCESSED + 7)/8 is the total
                                                                 number of bytes in the entire compressed input stream from the file in that case. (For
                                                                 example, this can be used to find the location of the ADLER32/CRC32 codes that
                                                                 follow the compressed data.) Note that TOTALBITSPROCESSED refers to the total
                                                                 number of bits processed during all invocations of the ZIP decompression coprocessor
                                                                 for the entire file.

                                                                 For any decompress with an error or with [EF] = 0, TOTALBITSPROCESSED is unused
                                                                 and undefined.

                                                                 For any compress, TOTALBITSPROCESSED is unused and undefined.

                                                                 If the true total bits processed by the ZIP coprocessor equals or exceeds 2^32 for a file,
                                                                 TOTALBITSPROCESSED contains the low-order 32-bits of the actual value for the
                                                                 file. If necessary, in this large file decompression case, software can calculate the true
                                                                 total bits processed by the ZIP coprocessor using the TOTALBITSPROCESSED
                                                                 value returned by the hardware, together with the total number of input bytes in the
                                                                 compressed file. */
		uint64_t doneint                     : 1;  /**< [159:159] Done Interrupt. This bit is copied from the corrresponding ZIP instruction ZIP_INST_S[DONEINT]. */
		uint64_t reserved_155_158            : 4;  /**< [158:155] Reserved. */
		uint64_t exn                         : 3;  /**< [154:152] The number of bits produced beyond the last output byte written.
                                                                 See details in [EXBITS]. */
		uint64_t reserved_151_151            : 1;  /**< [151:151] Reserved. */
		uint64_t exbits                      : 7;  /**< [150:144] [EXN] and [EXBITS] are the compressed bits produced beyond the last compressed byte
                                                                 written. These bits are required context for partial-file processing as the ZIP
                                                                 compression algorithm produces a compressed bit stream, but the output stream of the
                                                                 operation is byte-based. [EXN], [EXBITS] are valid for any error-free compress when
                                                                 ZIP_INST_S[EF] = 0 and ZIP_INST_S[SF] = 0, and are not used and undefined in all other
                                                                 cases.

                                                                 EXBITS contains the extra bits. Bit <0> contains the first extra bit, <1> the
                                                                 second extra bit, etc.

                                                                 For decompression, [EXN] and [EXBITS] are not used and are undefined. */
		uint64_t reserved_137_143            : 7;  /**< [143:137] Reserved. */
		uint64_t ef                          : 1;  /**< [136:136] End of file.

                                                                 For any error-free decompression, EF indicates whether the ZIP
                                                                 coprocessor completed decompression of all blocks in the file during this invocation. If
                                                                 EF = 1 for a decompression operation, the ZIP coprocessor must not be invoked again
                                                                 for further processing on this file.

                                                                 For compression, EF is not used and is undefined. */
		uint64_t compcode                    : 8;  /**< [135:128] Indicates completion/error status of the ZIP coprocessor for this invocation,
                                                                 as enumerated in ZIP_COMP_E. Core
                                                                 software may write the memory location containing [COMPCODE] to 0x0
                                                                 before ringing the doorbell, and then poll for completion by checking for a non-zero
                                                                 value.

                                                                 Once the core observes a non-zero [COMPCODE] value in this case, the ZIP
                                                                 coprocessor will have also completed L2/DRAM write operations for all context,
                                                                 output stream, and result data. */
		uint64_t totalbyteswritten           : 32; /**< [127: 96] The total number of bytes produced in the output stream during this coprocessor
                                                                 invocation. TOTALBYTESWRITTEN <= ZIP_INST_S[TOTALOUTPUTLENGTH] in all error-free cases

                                                                 For an error-free compression, TOTALBYTESWRITTEN is the number of
                                                                 compressed output bytes that were written during the compression. This includes
                                                                 any valid [EXN],[EXBITS] when [EF] = 1, and excludes
                                                                 any valid [EXN],[EXBITS] when [EF] = 0.

                                                                 For an error-free decompression, TOTALBYTESWRITTEN is the number of uncompressed
                                                                 output bytes produced by the operation */
		uint64_t totalbytesread              : 32; /**< [ 95: 64] The total number of bytes processed from the input stream during this coprocessor
                                                                 invocation. Note that for a compression operation, TOTALBYTESREAD does count
                                                                 the history bytes read in (when ZIP_INST_S[HISTORYLENGTH] != 0x0).

                                                                 For an error-free compression, [TOTALBYTESREAD] ZIP_INST_S[HISTORYLENGTH] is
                                                                 the number of uncompressed input bytes which, when compressed and concatenated after
                                                                 ZIP_INST_S[EXN], ZIP_INST_S[EXBITS], produces the compressed byte-output stream
                                                                 (and [EXN],[EXBITS] when valid). In all error-free compression
                                                                 invocations, TOTALBYTESREAD equals the total number of input bytes supplied
                                                                 via INP_PTR (input and compression history bytes).

                                                                 For an error-free decompression, TOTALBYTESREAD is the number of compressed
                                                                 input bytes which were read during the decompression. */
		uint64_t crc32                       : 32; /**< [ 63: 32] The CRC32 result corresponding to the bytes processed in the uncompressed stream,
                                                                 seeded with ZIP_INST_S[ADLERCRC32].

                                                                 For an error-free compression, [TOTALBYTESREAD] indicates the
                                                                 number of non-history bytes from the input stream that contributed to the hardware
                                                                 CRC32 calculation. CRC32 is valid for all error-free compression invocations,
                                                                 whether at the beginning, middle, or end of file.

                                                                 For decompression, CRC32 is valid only for error-free invocations that find the end of
                                                                 file (i.e. that have [EF] = 1), where it indicates the ADLER/CRC32 result
                                                                 for the file */
		uint64_t adler32                     : 32; /**< [ 31:  0] The ADLER32 result corresponding to the bytes processed in the uncompressed
                                                                 stream, starting with the checksum ZIP_INST_S[ADLERCRC32].

                                                                 For an error-free compression, [TOTALBYTESREAD] indicates the
                                                                 number of non-history bytes from the input stream that contributed to the hardware
                                                                 ADLER32 calculation. ADLER32 is valid for all error-free compression invocations,
                                                                 whether at the beginning, middle, or end of file.

                                                                 For decompression, ADLER32 is valid only for error-free invocations that find the
                                                                 end of file (i.e. that have [EF] = 1), where it indicates the ADLER/CRC32
                                                                 result for the file. */
#else
		uint64_t adler32                     : 32;
		uint64_t crc32                       : 32;
		uint64_t totalbytesread              : 32;
		uint64_t totalbyteswritten           : 32;
		uint64_t compcode                    : 8;
		uint64_t ef                          : 1;
		uint64_t reserved_137_143            : 7;
		uint64_t exbits                      : 7;
		uint64_t reserved_151_151            : 1;
		uint64_t exn                         : 3;
		uint64_t reserved_155_158            : 4;
		uint64_t doneint                     : 1;
		uint64_t totalbitsprocessed          : 32;
#endif
	} s;
};


/**
 * NCB - zip_cmd_ctl
 *
 * This register controls clock and reset.
 *
 */
typedef union bdk_zip_cmd_ctl {
	uint64_t u;
	struct bdk_zip_cmd_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t forceclk                    : 1;  /**< R/W - When this bit is set to 1, it forces ZIP clocks on. */
		uint64_t reset                       : 1;  /**< R/W1 - Reset one-shot pulse to reset ZIP subsystem. */
#else
		uint64_t reset                       : 1;
		uint64_t forceclk                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_zip_cmd_ctl_s           cn85xx; */
	/* struct bdk_zip_cmd_ctl_s           cn88xx; */
} bdk_zip_cmd_ctl_t;

#define BDK_ZIP_CMD_CTL BDK_ZIP_CMD_CTL_FUNC()
static inline uint64_t BDK_ZIP_CMD_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_CMD_CTL_FUNC(void)
{
	return 0x0000838000000000ull;
}
#define typedef_BDK_ZIP_CMD_CTL bdk_zip_cmd_ctl_t
#define bustype_BDK_ZIP_CMD_CTL BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_CMD_CTL 0
#define arguments_BDK_ZIP_CMD_CTL -1,-1,-1,-1
#define basename_BDK_ZIP_CMD_CTL "ZIP_CMD_CTL"


/**
 * NCB - zip_constants
 *
 * This register contains all of the current implementation-related parameters of the zip core in
 * this chip.
 */
typedef union bdk_zip_constants {
	uint64_t u;
	struct bdk_zip_constants_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t nexec                       : 8;  /**< RO - Number of available ZIP executive units. If zip is disabled, this field is 0. */
		uint64_t reserved_49_55              : 7;
		uint64_t syncflush_capable           : 1;  /**< RO - Sync flush supported: 1 = supported, 0 = not supported. */
		uint64_t depth                       : 16; /**< RO - Maximum search depth for compression. */
		uint64_t onfsize                     : 12; /**< RO - Output near full threshold, in bytes. */
		uint64_t ctxsize                     : 12; /**< RO - Decompression context size in bytes. */
		uint64_t reserved_1_7                : 7;
		uint64_t disabled                    : 1;  /**< RO - Disable. 1 = ZIP is disabled, 0 = ZIP is enabled. */
#else
		uint64_t disabled                    : 1;
		uint64_t reserved_1_7                : 7;
		uint64_t ctxsize                     : 12;
		uint64_t onfsize                     : 12;
		uint64_t depth                       : 16;
		uint64_t syncflush_capable           : 1;
		uint64_t reserved_49_55              : 7;
		uint64_t nexec                       : 8;
#endif
	} s;
	/* struct bdk_zip_constants_s         cn85xx; */
	/* struct bdk_zip_constants_s         cn88xx; */
} bdk_zip_constants_t;

#define BDK_ZIP_CONSTANTS BDK_ZIP_CONSTANTS_FUNC()
static inline uint64_t BDK_ZIP_CONSTANTS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_CONSTANTS_FUNC(void)
{
	return 0x00008380000000A0ull;
}
#define typedef_BDK_ZIP_CONSTANTS bdk_zip_constants_t
#define bustype_BDK_ZIP_CONSTANTS BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_CONSTANTS 0
#define arguments_BDK_ZIP_CONSTANTS -1,-1,-1,-1
#define basename_BDK_ZIP_CONSTANTS "ZIP_CONSTANTS"


/**
 * NCB - zip_core#_bist_status
 *
 * These register have the BIST status of memories in zip cores. Each bit is the BIST result of
 * an individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union bdk_zip_corex_bist_status {
	uint64_t u;
	struct bdk_zip_corex_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_53_63              : 11;
		uint64_t bstatus                     : 53; /**< RO/H - BIST result of the ZIP_CORE memories. */
#else
		uint64_t bstatus                     : 53;
		uint64_t reserved_53_63              : 11;
#endif
	} s;
	/* struct bdk_zip_corex_bist_status_s cn85xx; */
	/* struct bdk_zip_corex_bist_status_s cn88xx; */
} bdk_zip_corex_bist_status_t;

static inline uint64_t BDK_ZIP_COREX_BIST_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_COREX_BIST_STATUS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000838000000520ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_ZIP_COREX_BIST_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_COREX_BIST_STATUS(...) bdk_zip_corex_bist_status_t
#define bustype_BDK_ZIP_COREX_BIST_STATUS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_COREX_BIST_STATUS(p1) (p1)
#define arguments_BDK_ZIP_COREX_BIST_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_COREX_BIST_STATUS(...) "ZIP_COREX_BIST_STATUS"


/**
 * NCB - zip_ctl_bist_status
 *
 * This register has the BIST status of memories in ZIP_CTL (instruction buffer, G/S pointer
 * FIFO, input data buffer, output data buffers). Each bit is the BIST result of an individual
 * memory (per bit, 0 = pass and 1 = fail).
 */
typedef union bdk_zip_ctl_bist_status {
	uint64_t u;
	struct bdk_zip_ctl_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t bstatus                     : 9;  /**< RO/H - BIST result of CTL memories. INTERNAL:BSTATUS = [VMEM, STDF[1:0], OFIF[1:0],
                                                                 IDF[1:0],GSPF, IQF]. */
#else
		uint64_t bstatus                     : 9;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_zip_ctl_bist_status_s   cn85xx; */
	/* struct bdk_zip_ctl_bist_status_s   cn88xx; */
} bdk_zip_ctl_bist_status_t;

#define BDK_ZIP_CTL_BIST_STATUS BDK_ZIP_CTL_BIST_STATUS_FUNC()
static inline uint64_t BDK_ZIP_CTL_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_CTL_BIST_STATUS_FUNC(void)
{
	return 0x0000838000000510ull;
}
#define typedef_BDK_ZIP_CTL_BIST_STATUS bdk_zip_ctl_bist_status_t
#define bustype_BDK_ZIP_CTL_BIST_STATUS BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_CTL_BIST_STATUS 0
#define arguments_BDK_ZIP_CTL_BIST_STATUS -1,-1,-1,-1
#define basename_BDK_ZIP_CTL_BIST_STATUS "ZIP_CTL_BIST_STATUS"


/**
 * NCB - zip_ctl_cfg
 *
 * This register controls the behavior of the ZIP DMA engines. It is recommended to keep default
 * values for normal operation. Changing the values of the fields may be useful for diagnostics.
 */
typedef union bdk_zip_ctl_cfg {
	uint64_t u;
	struct bdk_zip_ctl_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_52_63              : 12;
		uint64_t ildf                        : 4;  /**< R/W - Instruction Load Command FIFO credits <= 8. */
		uint64_t reserved_36_47              : 12;
		uint64_t drtf                        : 4;  /**< R/W - Data Read Tag FIFOs (per core) credits <= 8. */
		uint64_t reserved_27_31              : 5;
		uint64_t stcf                        : 3;  /**< R/W - Store Command FIFO credits <= 4. */
		uint64_t reserved_19_23              : 5;
		uint64_t ldf                         : 3;  /**< R/W - Load Command FIFO credits <= 4. */
		uint64_t reserved_2_15               : 14;
		uint64_t busy                        : 1;  /**< RO/H - 1: ZIP system is busy; 0: ZIP system is idle. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t busy                        : 1;
		uint64_t reserved_2_15               : 14;
		uint64_t ldf                         : 3;
		uint64_t reserved_19_23              : 5;
		uint64_t stcf                        : 3;
		uint64_t reserved_27_31              : 5;
		uint64_t drtf                        : 4;
		uint64_t reserved_36_47              : 12;
		uint64_t ildf                        : 4;
		uint64_t reserved_52_63              : 12;
#endif
	} s;
	/* struct bdk_zip_ctl_cfg_s           cn85xx; */
	/* struct bdk_zip_ctl_cfg_s           cn88xx; */
} bdk_zip_ctl_cfg_t;

#define BDK_ZIP_CTL_CFG BDK_ZIP_CTL_CFG_FUNC()
static inline uint64_t BDK_ZIP_CTL_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_CTL_CFG_FUNC(void)
{
	return 0x0000838000000560ull;
}
#define typedef_BDK_ZIP_CTL_CFG bdk_zip_ctl_cfg_t
#define bustype_BDK_ZIP_CTL_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_CTL_CFG 0
#define arguments_BDK_ZIP_CTL_CFG -1,-1,-1,-1
#define basename_BDK_ZIP_CTL_CFG "ZIP_CTL_CFG"


/**
 * NCB - zip_dbg_core#_inst
 *
 * These registers reflect the status of the current instruction that the ZIP core is executing
 * or has executed. These registers are only for debug use.
 */
typedef union bdk_zip_dbg_corex_inst {
	uint64_t u;
	struct bdk_zip_dbg_corex_inst_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t busy                        : 1;  /**< RO/H - Core state. 0 = core is idle; 1 = core is busy. */
		uint64_t reserved_35_62              : 28;
		uint64_t qid                         : 3;  /**< RO/H - Queue index of instruction executed (BUSY = 0) or being executed (BUSY = 1) on this core. */
		uint64_t iid                         : 32; /**< RO/H - Instruction index executed (BUSY = 0) or being executed (BUSY = 1) on this core. */
#else
		uint64_t iid                         : 32;
		uint64_t qid                         : 3;
		uint64_t reserved_35_62              : 28;
		uint64_t busy                        : 1;
#endif
	} s;
	/* struct bdk_zip_dbg_corex_inst_s    cn85xx; */
	/* struct bdk_zip_dbg_corex_inst_s    cn88xx; */
} bdk_zip_dbg_corex_inst_t;

static inline uint64_t BDK_ZIP_DBG_COREX_INST(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_DBG_COREX_INST(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000838000000640ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_ZIP_DBG_COREX_INST", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_DBG_COREX_INST(...) bdk_zip_dbg_corex_inst_t
#define bustype_BDK_ZIP_DBG_COREX_INST(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_DBG_COREX_INST(p1) (p1)
#define arguments_BDK_ZIP_DBG_COREX_INST(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_DBG_COREX_INST(...) "ZIP_DBG_COREX_INST"


/**
 * NCB - zip_dbg_core#_sta
 *
 * These registers reflect the status of the zip cores and are for debug use only.
 *
 */
typedef union bdk_zip_dbg_corex_sta {
	uint64_t u;
	struct bdk_zip_dbg_corex_sta_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t busy                        : 1;  /**< RO/H - Core state. 0 = core is idle; 1 = core is busy. */
		uint64_t reserved_37_62              : 26;
		uint64_t ist                         : 5;  /**< RO/H - State of current instruction that is executing. */
		uint64_t nie                         : 32; /**< RO/H - Number of instructions executed on this core. */
#else
		uint64_t nie                         : 32;
		uint64_t ist                         : 5;
		uint64_t reserved_37_62              : 26;
		uint64_t busy                        : 1;
#endif
	} s;
	/* struct bdk_zip_dbg_corex_sta_s     cn85xx; */
	/* struct bdk_zip_dbg_corex_sta_s     cn88xx; */
} bdk_zip_dbg_corex_sta_t;

static inline uint64_t BDK_ZIP_DBG_COREX_STA(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_DBG_COREX_STA(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000838000000680ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_ZIP_DBG_COREX_STA", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_DBG_COREX_STA(...) bdk_zip_dbg_corex_sta_t
#define bustype_BDK_ZIP_DBG_COREX_STA(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_DBG_COREX_STA(p1) (p1)
#define arguments_BDK_ZIP_DBG_COREX_STA(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_DBG_COREX_STA(...) "ZIP_DBG_COREX_STA"


/**
 * NCB - zip_dbg_que#_sta
 *
 * These registers reflect status of the zip instruction queues and are for debug use only.
 *
 */
typedef union bdk_zip_dbg_quex_sta {
	uint64_t u;
	struct bdk_zip_dbg_quex_sta_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t busy                        : 1;  /**< RO/H - Queue state. 0 = queue is idle; 1 = queue is busy. */
		uint64_t reserved_56_62              : 7;
		uint64_t rqwc                        : 24; /**< RO/H - Number of remaining instruction qwords to be fetched. */
		uint64_t nii                         : 32; /**< RO/H - Number of instructions issued from this queue. Reset to 0x0 when ZIP_QUE(0..7)_SBUF_ADDR
                                                                 is written. */
#else
		uint64_t nii                         : 32;
		uint64_t rqwc                        : 24;
		uint64_t reserved_56_62              : 7;
		uint64_t busy                        : 1;
#endif
	} s;
	/* struct bdk_zip_dbg_quex_sta_s      cn85xx; */
	/* struct bdk_zip_dbg_quex_sta_s      cn88xx; */
} bdk_zip_dbg_quex_sta_t;

static inline uint64_t BDK_ZIP_DBG_QUEX_STA(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_DBG_QUEX_STA(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000001800ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_DBG_QUEX_STA", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_DBG_QUEX_STA(...) bdk_zip_dbg_quex_sta_t
#define bustype_BDK_ZIP_DBG_QUEX_STA(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_DBG_QUEX_STA(p1) (p1)
#define arguments_BDK_ZIP_DBG_QUEX_STA(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_DBG_QUEX_STA(...) "ZIP_DBG_QUEX_STA"


/**
 * NCB - zip_ecc_ctl
 *
 * This register enables ECC for each individual internal memory that requires ECC. For debug
 * purpose, it can also flip one or two bits in the ECC data.
 */
typedef union bdk_zip_ecc_ctl {
	uint64_t u;
	struct bdk_zip_ecc_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_19_63              : 45;
		uint64_t vmem_cdis                   : 1;  /**< R/W - VMEM memory ECC correction disable. */
		uint64_t vmem_fs                     : 2;  /**< R/W - Controls VMEM memory flip syndrome. */
		uint64_t reserved_15_15              : 1;
		uint64_t idf1_cdis                   : 1;  /**< R/W - Input Data FIFO 1 ECC correction disable. */
		uint64_t idf1_fs                     : 2;  /**< R/W - Controls Input Data FIFO 1 flip syndrome. */
		uint64_t reserved_11_11              : 1;
		uint64_t idf0_cdis                   : 1;  /**< R/W - Input Data FIFO 0 ECC correction disable. */
		uint64_t idf0_fs                     : 2;  /**< R/W - Controls Input Data FIFO 0 flip syndrome. */
		uint64_t reserved_7_7                : 1;
		uint64_t gspf_cdis                   : 1;  /**< R/W - G/S Pointer FIFO ECC correction disable. */
		uint64_t gspf_fs                     : 2;  /**< R/W - Controls G/S Pointer FIFO flip syndrome. */
		uint64_t reserved_3_3                : 1;
		uint64_t iqf_cdis                    : 1;  /**< R/W - Instruction Queue FIFO ECC correction disable. */
		uint64_t iqf_fs                      : 2;  /**< R/W - Controls Instruction Queue FIFO flip syndrome.
                                                                 0x0 = no error generation.
                                                                 0x1 = flip one bit.
                                                                 0x2 = flip one bit.
                                                                 0x3 = flip two bits. */
#else
		uint64_t iqf_fs                      : 2;
		uint64_t iqf_cdis                    : 1;
		uint64_t reserved_3_3                : 1;
		uint64_t gspf_fs                     : 2;
		uint64_t gspf_cdis                   : 1;
		uint64_t reserved_7_7                : 1;
		uint64_t idf0_fs                     : 2;
		uint64_t idf0_cdis                   : 1;
		uint64_t reserved_11_11              : 1;
		uint64_t idf1_fs                     : 2;
		uint64_t idf1_cdis                   : 1;
		uint64_t reserved_15_15              : 1;
		uint64_t vmem_fs                     : 2;
		uint64_t vmem_cdis                   : 1;
		uint64_t reserved_19_63              : 45;
#endif
	} s;
	/* struct bdk_zip_ecc_ctl_s           cn85xx; */
	/* struct bdk_zip_ecc_ctl_s           cn88xx; */
} bdk_zip_ecc_ctl_t;

#define BDK_ZIP_ECC_CTL BDK_ZIP_ECC_CTL_FUNC()
static inline uint64_t BDK_ZIP_ECC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_ECC_CTL_FUNC(void)
{
	return 0x0000838000000568ull;
}
#define typedef_BDK_ZIP_ECC_CTL bdk_zip_ecc_ctl_t
#define bustype_BDK_ZIP_ECC_CTL BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_ECC_CTL 0
#define arguments_BDK_ZIP_ECC_CTL -1,-1,-1,-1
#define basename_BDK_ZIP_ECC_CTL "ZIP_ECC_CTL"


/**
 * NCB - zip_ecce_ena_w1c
 */
typedef union bdk_zip_ecce_ena_w1c {
	uint64_t u;
	struct bdk_zip_ecce_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_37_63              : 27;
		uint64_t dbe                         : 5;  /**< R/W1C/H - Double-bit error detected in internal RAM. 0 = pass, 1 = fail. One bit per memory.
                                                                 INTERNAL: The memories are [VMEM, IDF1, IDF0, GSPF, IQF]. */
		uint64_t reserved_5_31               : 27;
		uint64_t sbe                         : 5;  /**< R/W1C/H - Single-bit error detected in internal RAM. 0 = pass, 1 = fail. One bit per memory.
                                                                 INTERNAL: The memories are [VMEM, IDF1, IDF0, GSPF,IQF]. */
#else
		uint64_t sbe                         : 5;
		uint64_t reserved_5_31               : 27;
		uint64_t dbe                         : 5;
		uint64_t reserved_37_63              : 27;
#endif
	} s;
	/* struct bdk_zip_ecce_ena_w1c_s      cn85xx; */
	/* struct bdk_zip_ecce_ena_w1c_s      cn88xx; */
} bdk_zip_ecce_ena_w1c_t;

#define BDK_ZIP_ECCE_ENA_W1C BDK_ZIP_ECCE_ENA_W1C_FUNC()
static inline uint64_t BDK_ZIP_ECCE_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_ECCE_ENA_W1C_FUNC(void)
{
	return 0x0000838000000598ull;
}
#define typedef_BDK_ZIP_ECCE_ENA_W1C bdk_zip_ecce_ena_w1c_t
#define bustype_BDK_ZIP_ECCE_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_ECCE_ENA_W1C 0
#define arguments_BDK_ZIP_ECCE_ENA_W1C -1,-1,-1,-1
#define basename_BDK_ZIP_ECCE_ENA_W1C "ZIP_ECCE_ENA_W1C"


/**
 * NCB - zip_ecce_ena_w1s
 */
typedef union bdk_zip_ecce_ena_w1s {
	uint64_t u;
	struct bdk_zip_ecce_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_37_63              : 27;
		uint64_t dbe                         : 5;  /**< R/W1C/H - Double-bit error detected in internal RAM. 0 = pass, 1 = fail. One bit per memory.
                                                                 INTERNAL: The memories are [VMEM, IDF1, IDF0, GSPF, IQF]. */
		uint64_t reserved_5_31               : 27;
		uint64_t sbe                         : 5;  /**< R/W1C/H - Single-bit error detected in internal RAM. 0 = pass, 1 = fail. One bit per memory.
                                                                 INTERNAL: The memories are [VMEM, IDF1, IDF0, GSPF,IQF]. */
#else
		uint64_t sbe                         : 5;
		uint64_t reserved_5_31               : 27;
		uint64_t dbe                         : 5;
		uint64_t reserved_37_63              : 27;
#endif
	} s;
	/* struct bdk_zip_ecce_ena_w1s_s      cn85xx; */
	/* struct bdk_zip_ecce_ena_w1s_s      cn88xx; */
} bdk_zip_ecce_ena_w1s_t;

#define BDK_ZIP_ECCE_ENA_W1S BDK_ZIP_ECCE_ENA_W1S_FUNC()
static inline uint64_t BDK_ZIP_ECCE_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_ECCE_ENA_W1S_FUNC(void)
{
	return 0x0000838000000590ull;
}
#define typedef_BDK_ZIP_ECCE_ENA_W1S bdk_zip_ecce_ena_w1s_t
#define bustype_BDK_ZIP_ECCE_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_ECCE_ENA_W1S 0
#define arguments_BDK_ZIP_ECCE_ENA_W1S -1,-1,-1,-1
#define basename_BDK_ZIP_ECCE_ENA_W1S "ZIP_ECCE_ENA_W1S"


/**
 * NCB - zip_ecce_int
 *
 * This register contains the status of the ECC interrupt sources.
 *
 */
typedef union bdk_zip_ecce_int {
	uint64_t u;
	struct bdk_zip_ecce_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_37_63              : 27;
		uint64_t dbe                         : 5;  /**< R/W1C/H - Double-bit error detected in internal RAM. 0 = pass, 1 = fail. One bit per memory.
                                                                 INTERNAL: The memories are [VMEM, IDF1, IDF0, GSPF, IQF]. */
		uint64_t reserved_5_31               : 27;
		uint64_t sbe                         : 5;  /**< R/W1C/H - Single-bit error detected in internal RAM. 0 = pass, 1 = fail. One bit per memory.
                                                                 INTERNAL: The memories are [VMEM, IDF1, IDF0, GSPF,IQF]. */
#else
		uint64_t sbe                         : 5;
		uint64_t reserved_5_31               : 27;
		uint64_t dbe                         : 5;
		uint64_t reserved_37_63              : 27;
#endif
	} s;
	/* struct bdk_zip_ecce_int_s          cn85xx; */
	/* struct bdk_zip_ecce_int_s          cn88xx; */
} bdk_zip_ecce_int_t;

#define BDK_ZIP_ECCE_INT BDK_ZIP_ECCE_INT_FUNC()
static inline uint64_t BDK_ZIP_ECCE_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_ECCE_INT_FUNC(void)
{
	return 0x0000838000000580ull;
}
#define typedef_BDK_ZIP_ECCE_INT bdk_zip_ecce_int_t
#define bustype_BDK_ZIP_ECCE_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_ECCE_INT 0
#define arguments_BDK_ZIP_ECCE_INT -1,-1,-1,-1
#define basename_BDK_ZIP_ECCE_INT "ZIP_ECCE_INT"


/**
 * NCB - zip_ecce_int_w1s
 */
typedef union bdk_zip_ecce_int_w1s {
	uint64_t u;
	struct bdk_zip_ecce_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_37_63              : 27;
		uint64_t dbe                         : 5;  /**< R/W1C/H - Double-bit error detected in internal RAM. 0 = pass, 1 = fail. One bit per memory.
                                                                 INTERNAL: The memories are [VMEM, IDF1, IDF0, GSPF, IQF]. */
		uint64_t reserved_5_31               : 27;
		uint64_t sbe                         : 5;  /**< R/W1C/H - Single-bit error detected in internal RAM. 0 = pass, 1 = fail. One bit per memory.
                                                                 INTERNAL: The memories are [VMEM, IDF1, IDF0, GSPF,IQF]. */
#else
		uint64_t sbe                         : 5;
		uint64_t reserved_5_31               : 27;
		uint64_t dbe                         : 5;
		uint64_t reserved_37_63              : 27;
#endif
	} s;
	/* struct bdk_zip_ecce_int_w1s_s      cn85xx; */
	/* struct bdk_zip_ecce_int_w1s_s      cn88xx; */
} bdk_zip_ecce_int_w1s_t;

#define BDK_ZIP_ECCE_INT_W1S BDK_ZIP_ECCE_INT_W1S_FUNC()
static inline uint64_t BDK_ZIP_ECCE_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_ECCE_INT_W1S_FUNC(void)
{
	return 0x0000838000000588ull;
}
#define typedef_BDK_ZIP_ECCE_INT_W1S bdk_zip_ecce_int_w1s_t
#define bustype_BDK_ZIP_ECCE_INT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_ECCE_INT_W1S 0
#define arguments_BDK_ZIP_ECCE_INT_W1S -1,-1,-1,-1
#define basename_BDK_ZIP_ECCE_INT_W1S "ZIP_ECCE_INT_W1S"


/**
 * NCB - zip_fife_ena_w1c
 */
typedef union bdk_zip_fife_ena_w1c {
	uint64_t u;
	struct bdk_zip_fife_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_42_63              : 22;
		uint64_t asserts                     : 42; /**< R/W1C/H - FIFO assertion checks. */
#else
		uint64_t asserts                     : 42;
		uint64_t reserved_42_63              : 22;
#endif
	} s;
	/* struct bdk_zip_fife_ena_w1c_s      cn85xx; */
	/* struct bdk_zip_fife_ena_w1c_s      cn88xx; */
} bdk_zip_fife_ena_w1c_t;

#define BDK_ZIP_FIFE_ENA_W1C BDK_ZIP_FIFE_ENA_W1C_FUNC()
static inline uint64_t BDK_ZIP_FIFE_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_FIFE_ENA_W1C_FUNC(void)
{
	return 0x0000838000000090ull;
}
#define typedef_BDK_ZIP_FIFE_ENA_W1C bdk_zip_fife_ena_w1c_t
#define bustype_BDK_ZIP_FIFE_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_FIFE_ENA_W1C 0
#define arguments_BDK_ZIP_FIFE_ENA_W1C -1,-1,-1,-1
#define basename_BDK_ZIP_FIFE_ENA_W1C "ZIP_FIFE_ENA_W1C"


/**
 * NCB - zip_fife_ena_w1s
 */
typedef union bdk_zip_fife_ena_w1s {
	uint64_t u;
	struct bdk_zip_fife_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_42_63              : 22;
		uint64_t asserts                     : 42; /**< R/W1C/H - FIFO assertion checks. */
#else
		uint64_t asserts                     : 42;
		uint64_t reserved_42_63              : 22;
#endif
	} s;
	/* struct bdk_zip_fife_ena_w1s_s      cn85xx; */
	/* struct bdk_zip_fife_ena_w1s_s      cn88xx; */
} bdk_zip_fife_ena_w1s_t;

#define BDK_ZIP_FIFE_ENA_W1S BDK_ZIP_FIFE_ENA_W1S_FUNC()
static inline uint64_t BDK_ZIP_FIFE_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_FIFE_ENA_W1S_FUNC(void)
{
	return 0x0000838000000088ull;
}
#define typedef_BDK_ZIP_FIFE_ENA_W1S bdk_zip_fife_ena_w1s_t
#define bustype_BDK_ZIP_FIFE_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_FIFE_ENA_W1S 0
#define arguments_BDK_ZIP_FIFE_ENA_W1S -1,-1,-1,-1
#define basename_BDK_ZIP_FIFE_ENA_W1S "ZIP_FIFE_ENA_W1S"


/**
 * NCB - zip_fife_int
 */
typedef union bdk_zip_fife_int {
	uint64_t u;
	struct bdk_zip_fife_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_42_63              : 22;
		uint64_t asserts                     : 42; /**< R/W1C/H - FIFO assertion checks. */
#else
		uint64_t asserts                     : 42;
		uint64_t reserved_42_63              : 22;
#endif
	} s;
	/* struct bdk_zip_fife_int_s          cn85xx; */
	/* struct bdk_zip_fife_int_s          cn88xx; */
} bdk_zip_fife_int_t;

#define BDK_ZIP_FIFE_INT BDK_ZIP_FIFE_INT_FUNC()
static inline uint64_t BDK_ZIP_FIFE_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_FIFE_INT_FUNC(void)
{
	return 0x0000838000000078ull;
}
#define typedef_BDK_ZIP_FIFE_INT bdk_zip_fife_int_t
#define bustype_BDK_ZIP_FIFE_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_FIFE_INT 0
#define arguments_BDK_ZIP_FIFE_INT -1,-1,-1,-1
#define basename_BDK_ZIP_FIFE_INT "ZIP_FIFE_INT"


/**
 * NCB - zip_fife_int_w1s
 */
typedef union bdk_zip_fife_int_w1s {
	uint64_t u;
	struct bdk_zip_fife_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_42_63              : 22;
		uint64_t asserts                     : 42; /**< R/W1C/H - FIFO assertion checks. */
#else
		uint64_t asserts                     : 42;
		uint64_t reserved_42_63              : 22;
#endif
	} s;
	/* struct bdk_zip_fife_int_w1s_s      cn85xx; */
	/* struct bdk_zip_fife_int_w1s_s      cn88xx; */
} bdk_zip_fife_int_w1s_t;

#define BDK_ZIP_FIFE_INT_W1S BDK_ZIP_FIFE_INT_W1S_FUNC()
static inline uint64_t BDK_ZIP_FIFE_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_FIFE_INT_W1S_FUNC(void)
{
	return 0x0000838000000080ull;
}
#define typedef_BDK_ZIP_FIFE_INT_W1S bdk_zip_fife_int_w1s_t
#define bustype_BDK_ZIP_FIFE_INT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_FIFE_INT_W1S 0
#define arguments_BDK_ZIP_FIFE_INT_W1S -1,-1,-1,-1
#define basename_BDK_ZIP_FIFE_INT_W1S "ZIP_FIFE_INT_W1S"


/**
 * NCB - zip_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the ZIP_INT_VEC_E enumeration.
 *
 */
typedef union bdk_zip_msix_pbax {
	uint64_t u;
	struct bdk_zip_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated ZIP_MSIX_VEC()_CTL, enumerated by ZIP_INT_VEC_E.
                                                                 Bits that have no associated ZIP_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_zip_msix_pbax_s         cn85xx; */
	/* struct bdk_zip_msix_pbax_s         cn88xx; */
} bdk_zip_msix_pbax_t;

static inline uint64_t BDK_ZIP_MSIX_PBAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_MSIX_PBAX(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x0000838000FF0000ull;
	csr_fatal("BDK_ZIP_MSIX_PBAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_MSIX_PBAX(...) bdk_zip_msix_pbax_t
#define bustype_BDK_ZIP_MSIX_PBAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_MSIX_PBAX(p1) (p1)
#define arguments_BDK_ZIP_MSIX_PBAX(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_MSIX_PBAX(...) "ZIP_MSIX_PBAX"


/**
 * NCB - zip_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the ZIP_INT_VEC_E enumeration.
 *
 */
typedef union bdk_zip_msix_vecx_addr {
	uint64_t u;
	struct bdk_zip_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's ZIP_MSIX_VEC()_ADDR, ZIP_MSIX_VEC()_CTL, and corresponding
                                                                 bit of ZIP_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_ZIP_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_zip_msix_vecx_addr_s    cn85xx; */
	/* struct bdk_zip_msix_vecx_addr_s    cn88xx; */
} bdk_zip_msix_vecx_addr_t;

static inline uint64_t BDK_ZIP_MSIX_VECX_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_MSIX_VECX_ADDR(unsigned long param1)
{
	if (((param1 <= 17)))
		return 0x0000838000F00000ull + (param1 & 31) * 0x10ull;
	csr_fatal("BDK_ZIP_MSIX_VECX_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_MSIX_VECX_ADDR(...) bdk_zip_msix_vecx_addr_t
#define bustype_BDK_ZIP_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_MSIX_VECX_ADDR(p1) (p1)
#define arguments_BDK_ZIP_MSIX_VECX_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_MSIX_VECX_ADDR(...) "ZIP_MSIX_VECX_ADDR"


/**
 * NCB - zip_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the ZIP_INT_VEC_E enumeration.
 *
 */
typedef union bdk_zip_msix_vecx_ctl {
	uint64_t u;
	struct bdk_zip_msix_vecx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_33_63              : 31;
		uint64_t mask                        : 1;  /**< R/W - When set, no MSI-X interrupts are sent to this vector. */
		uint64_t reserved_20_31              : 12;
		uint64_t data                        : 20; /**< R/W - Data to use for MSI-X delivery of this vector. */
#else
		uint64_t data                        : 20;
		uint64_t reserved_20_31              : 12;
		uint64_t mask                        : 1;
		uint64_t reserved_33_63              : 31;
#endif
	} s;
	/* struct bdk_zip_msix_vecx_ctl_s     cn85xx; */
	/* struct bdk_zip_msix_vecx_ctl_s     cn88xx; */
} bdk_zip_msix_vecx_ctl_t;

static inline uint64_t BDK_ZIP_MSIX_VECX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_MSIX_VECX_CTL(unsigned long param1)
{
	if (((param1 <= 17)))
		return 0x0000838000F00008ull + (param1 & 31) * 0x10ull;
	csr_fatal("BDK_ZIP_MSIX_VECX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_MSIX_VECX_CTL(...) bdk_zip_msix_vecx_ctl_t
#define bustype_BDK_ZIP_MSIX_VECX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_MSIX_VECX_CTL(p1) (p1)
#define arguments_BDK_ZIP_MSIX_VECX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_MSIX_VECX_CTL(...) "ZIP_MSIX_VECX_CTL"


/**
 * NCB - zip_que#_done
 *
 * These registers contain the per-queue instruction done count.
 *
 */
typedef union bdk_zip_quex_done {
	uint64_t u;
	struct bdk_zip_quex_done_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t done                        : 20; /**< R/W/H - Done count. When ZIP_INST_S[DONEINT] set and that instruction completes,
                                                                 ZIP_QUE(0..7)_DONE[DONE] is incremented when the instruction finisihes. Write to this
                                                                 field are for diagnostic use only; instead software writes ZIP_QUE(0..7)_DONE_ACK[DONE]
                                                                 with the number of decrements for this field.

                                                                 Interrupts are sent as follows:

                                                                 * When ZIP_QUE(0..7)_DONE[DONE] = 0, then no results are pending, the interrupt coalescing
                                                                 timer is held to zero, and an interrupt is not sent.

                                                                 * When ZIP_QUE(0..7)_DONE[DONE] != 0, then the interrupt coalescing timer counts. If the
                                                                 counter is less than ZIP_QUE(0..7)_DONE_WAIT[TIME_WAIT]*1024, and ZIP_QUE(0..7)_DONE[DONE]
                                                                 < ZIP_QUE(0..7)_DONE_WAIT[NUM_WAIT] , i.e. not enough time has passed or not enough
                                                                 results have arrived, then interrupts are not sent due to coalescing.

                                                                 * When ZIP_QUE(0..7)_DONE_ACK is written, the interrupt coalescing timer restarts.
                                                                 Note after decrementing this interrupt equation is recomputed, for example if
                                                                 ZIP_QUE(0..7)_DONE[DONE] >= ZIP_QUE(0..7)_DONE_WAIT[NUM_WAIT] and the timer is zero, the
                                                                 interrupt will be resent immediately.  (This covers the race case between software
                                                                 acknowledging an interrupt and a result returning.)

                                                                 * When ZIP_QUE(0..7)_DONE_ENA_W1S[DONE_ENA] = 0, interrupts are not sent, but the counting
                                                                 described above still occurs.

                                                                 Since ZIP instructions within a queue can complete out-of-order when the queue is mapped
                                                                 to both zip engines, if software is using completion interrupts the suggested scheme is to
                                                                 request a DONEINT on each request, and when an interrupt arrives perform a "greedy" scan
                                                                 for completions; even if a later command is acknowledged first this will not result in
                                                                 missing a completion. Software could also use ZIP_ZRES_S[DONEINT] to check when
                                                                 instruction needs to be counted into ZIP_QUE(0..7)_DONE/ZIP_QUE(0..7)_DONE_ACK. */
#else
		uint64_t done                        : 20;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_zip_quex_done_s         cn85xx; */
	/* struct bdk_zip_quex_done_s         cn88xx; */
} bdk_zip_quex_done_t;

static inline uint64_t BDK_ZIP_QUEX_DONE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_DONE(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000002000ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_QUEX_DONE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_QUEX_DONE(...) bdk_zip_quex_done_t
#define bustype_BDK_ZIP_QUEX_DONE(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUEX_DONE(p1) (p1)
#define arguments_BDK_ZIP_QUEX_DONE(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_QUEX_DONE(...) "ZIP_QUEX_DONE"


/**
 * NCB - zip_que#_done_ack
 *
 * Write to these registers will decreament the per-queue instruction done count.
 *
 */
typedef union bdk_zip_quex_done_ack {
	uint64_t u;
	struct bdk_zip_quex_done_ack_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t done_ack                    : 20; /**< R/W/H - Number of decrements to ZIP_QUE(0..7)_DONE[DONE]. If ZIP_QUE(0..7)_DONE[DONE] is still
                                                                 non-zero the interrupt will be re-sent if the conditions described in
                                                                 ZIP_QUE(0..7)_DONE[DONE] are satified. */
#else
		uint64_t done_ack                    : 20;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_zip_quex_done_ack_s     cn85xx; */
	/* struct bdk_zip_quex_done_ack_s     cn88xx; */
} bdk_zip_quex_done_ack_t;

static inline uint64_t BDK_ZIP_QUEX_DONE_ACK(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_DONE_ACK(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000002200ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_QUEX_DONE_ACK", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_QUEX_DONE_ACK(...) bdk_zip_quex_done_ack_t
#define bustype_BDK_ZIP_QUEX_DONE_ACK(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUEX_DONE_ACK(p1) (p1)
#define arguments_BDK_ZIP_QUEX_DONE_ACK(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_QUEX_DONE_ACK(...) "ZIP_QUEX_DONE_ACK"


/**
 * NCB - zip_que#_done_ena_w1c
 *
 * Write 1 to these registers will disable the DONEINT interrupt for the queue.
 *
 */
typedef union bdk_zip_quex_done_ena_w1c {
	uint64_t u;
	struct bdk_zip_quex_done_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t done_ena                    : 1;  /**< R/W1C/H - Write 1 will disable DONEINT for this queue. Write 0 has no effect.
                                                                 Read will return the DONEINT enable bit. */
#else
		uint64_t done_ena                    : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_zip_quex_done_ena_w1c_s cn85xx; */
	/* struct bdk_zip_quex_done_ena_w1c_s cn88xx; */
} bdk_zip_quex_done_ena_w1c_t;

static inline uint64_t BDK_ZIP_QUEX_DONE_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_DONE_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000002600ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_QUEX_DONE_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_QUEX_DONE_ENA_W1C(...) bdk_zip_quex_done_ena_w1c_t
#define bustype_BDK_ZIP_QUEX_DONE_ENA_W1C(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUEX_DONE_ENA_W1C(p1) (p1)
#define arguments_BDK_ZIP_QUEX_DONE_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_QUEX_DONE_ENA_W1C(...) "ZIP_QUEX_DONE_ENA_W1C"


/**
 * NCB - zip_que#_done_ena_w1s
 *
 * Write 1 to these registers will enable the DONEINT interrupt for the queue.
 *
 */
typedef union bdk_zip_quex_done_ena_w1s {
	uint64_t u;
	struct bdk_zip_quex_done_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t done_ena                    : 1;  /**< R/W1S/H - Write 1 will enable DONEINT for this queue. Write 0 has no effect.
                                                                 Read will return the enable bit. */
#else
		uint64_t done_ena                    : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_zip_quex_done_ena_w1s_s cn85xx; */
	/* struct bdk_zip_quex_done_ena_w1s_s cn88xx; */
} bdk_zip_quex_done_ena_w1s_t;

static inline uint64_t BDK_ZIP_QUEX_DONE_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_DONE_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000002400ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_QUEX_DONE_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_QUEX_DONE_ENA_W1S(...) bdk_zip_quex_done_ena_w1s_t
#define bustype_BDK_ZIP_QUEX_DONE_ENA_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUEX_DONE_ENA_W1S(p1) (p1)
#define arguments_BDK_ZIP_QUEX_DONE_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_QUEX_DONE_ENA_W1S(...) "ZIP_QUEX_DONE_ENA_W1S"


/**
 * NCB - zip_que#_done_wait
 *
 * Specifies the per queue interrupt coalescing settings.
 *
 */
typedef union bdk_zip_quex_done_wait {
	uint64_t u;
	struct bdk_zip_quex_done_wait_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t time_wait                   : 16; /**< R/W - Time hold-off.  When ZIP_QUE(0..7)_DONE[DONE] = 0, or ZIP_QUE(0..7)_DONE_ACK is written a
                                                                 timer
                                                                 is cleared.  When the timer reaches [TIME_WAIT]*1024 then interrupt coalescing ends;
                                                                 see ZIP_QUE(0..7)_DONE[DONE]. If zero, time coalescing is disabled. */
		uint64_t reserved_20_31              : 12;
		uint64_t num_wait                    : 20; /**< R/W - Number of messages hold-off.  When ZIP_QUE(0..7)_DONE[DONE] >= [NUM_WAIT] then interrupt
                                                                 coalescing
                                                                 ends; see ZIP_QUE(0..7)_DONE[DONE]. If zero, message number coalescing is
                                                                 disabled. */
#else
		uint64_t num_wait                    : 20;
		uint64_t reserved_20_31              : 12;
		uint64_t time_wait                   : 16;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_zip_quex_done_wait_s    cn85xx; */
	/* struct bdk_zip_quex_done_wait_s    cn88xx; */
} bdk_zip_quex_done_wait_t;

static inline uint64_t BDK_ZIP_QUEX_DONE_WAIT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_DONE_WAIT(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000002800ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_QUEX_DONE_WAIT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_QUEX_DONE_WAIT(...) bdk_zip_quex_done_wait_t
#define bustype_BDK_ZIP_QUEX_DONE_WAIT(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUEX_DONE_WAIT(p1) (p1)
#define arguments_BDK_ZIP_QUEX_DONE_WAIT(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_QUEX_DONE_WAIT(...) "ZIP_QUEX_DONE_WAIT"


/**
 * NCB - zip_que#_doorbell
 *
 * Doorbells for the ZIP instruction queues.
 *
 */
typedef union bdk_zip_quex_doorbell {
	uint64_t u;
	struct bdk_zip_quex_doorbell_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t dbell_cnt                   : 20; /**< R/W/H - Number of instruction queue 64-bit words to add to the ZIP instruction doorbell count.
                                                                 Must be a multiple of 16. All ZIP instructions are 16 words and require a doorbell count
                                                                 of multiple of 16. */
#else
		uint64_t dbell_cnt                   : 20;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_zip_quex_doorbell_s     cn85xx; */
	/* struct bdk_zip_quex_doorbell_s     cn88xx; */
} bdk_zip_quex_doorbell_t;

static inline uint64_t BDK_ZIP_QUEX_DOORBELL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_DOORBELL(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000004000ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_QUEX_DOORBELL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_QUEX_DOORBELL(...) bdk_zip_quex_doorbell_t
#define bustype_BDK_ZIP_QUEX_DOORBELL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUEX_DOORBELL(p1) (p1)
#define arguments_BDK_ZIP_QUEX_DOORBELL(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_QUEX_DOORBELL(...) "ZIP_QUEX_DOORBELL"


/**
 * NCB - zip_que#_err_ena_w1c
 */
typedef union bdk_zip_quex_err_ena_w1c {
	uint64_t u;
	struct bdk_zip_quex_err_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t mdbe                        : 1;  /**< R/W1C/H - SRAM ECC double-bit error. */
		uint64_t nwrp                        : 1;  /**< R/W1C/H - NCB write response error. */
		uint64_t nrrp                        : 1;  /**< R/W1C/H - NCB read response error. */
		uint64_t irde                        : 1;  /**< R/W1C/H - Instruction NCB read response error. */
		uint64_t dovf                        : 1;  /**< R/W1C/H - Doorbell overflow. */
#else
		uint64_t dovf                        : 1;
		uint64_t irde                        : 1;
		uint64_t nrrp                        : 1;
		uint64_t nwrp                        : 1;
		uint64_t mdbe                        : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_zip_quex_err_ena_w1c_s  cn85xx; */
	/* struct bdk_zip_quex_err_ena_w1c_s  cn88xx; */
} bdk_zip_quex_err_ena_w1c_t;

static inline uint64_t BDK_ZIP_QUEX_ERR_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_ERR_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000003600ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_QUEX_ERR_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_QUEX_ERR_ENA_W1C(...) bdk_zip_quex_err_ena_w1c_t
#define bustype_BDK_ZIP_QUEX_ERR_ENA_W1C(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUEX_ERR_ENA_W1C(p1) (p1)
#define arguments_BDK_ZIP_QUEX_ERR_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_QUEX_ERR_ENA_W1C(...) "ZIP_QUEX_ERR_ENA_W1C"


/**
 * NCB - zip_que#_err_ena_w1s
 */
typedef union bdk_zip_quex_err_ena_w1s {
	uint64_t u;
	struct bdk_zip_quex_err_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t mdbe                        : 1;  /**< R/W1C/H - SRAM ECC double-bit error. */
		uint64_t nwrp                        : 1;  /**< R/W1C/H - NCB write response error. */
		uint64_t nrrp                        : 1;  /**< R/W1C/H - NCB read response error. */
		uint64_t irde                        : 1;  /**< R/W1C/H - Instruction NCB read response error. */
		uint64_t dovf                        : 1;  /**< R/W1C/H - Doorbell overflow. */
#else
		uint64_t dovf                        : 1;
		uint64_t irde                        : 1;
		uint64_t nrrp                        : 1;
		uint64_t nwrp                        : 1;
		uint64_t mdbe                        : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_zip_quex_err_ena_w1s_s  cn85xx; */
	/* struct bdk_zip_quex_err_ena_w1s_s  cn88xx; */
} bdk_zip_quex_err_ena_w1s_t;

static inline uint64_t BDK_ZIP_QUEX_ERR_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_ERR_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000003400ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_QUEX_ERR_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_QUEX_ERR_ENA_W1S(...) bdk_zip_quex_err_ena_w1s_t
#define bustype_BDK_ZIP_QUEX_ERR_ENA_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUEX_ERR_ENA_W1S(p1) (p1)
#define arguments_BDK_ZIP_QUEX_ERR_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_QUEX_ERR_ENA_W1S(...) "ZIP_QUEX_ERR_ENA_W1S"


/**
 * NCB - zip_que#_err_int
 *
 * These registers contain the per-queue error interrupts.
 *
 */
typedef union bdk_zip_quex_err_int {
	uint64_t u;
	struct bdk_zip_quex_err_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t mdbe                        : 1;  /**< R/W1C/H - SRAM ECC double-bit error. */
		uint64_t nwrp                        : 1;  /**< R/W1C/H - NCB write response error. */
		uint64_t nrrp                        : 1;  /**< R/W1C/H - NCB read response error. */
		uint64_t irde                        : 1;  /**< R/W1C/H - Instruction NCB read response error. */
		uint64_t dovf                        : 1;  /**< R/W1C/H - Doorbell overflow. */
#else
		uint64_t dovf                        : 1;
		uint64_t irde                        : 1;
		uint64_t nrrp                        : 1;
		uint64_t nwrp                        : 1;
		uint64_t mdbe                        : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_zip_quex_err_int_s      cn85xx; */
	/* struct bdk_zip_quex_err_int_s      cn88xx; */
} bdk_zip_quex_err_int_t;

static inline uint64_t BDK_ZIP_QUEX_ERR_INT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_ERR_INT(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000003000ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_QUEX_ERR_INT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_QUEX_ERR_INT(...) bdk_zip_quex_err_int_t
#define bustype_BDK_ZIP_QUEX_ERR_INT(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUEX_ERR_INT(p1) (p1)
#define arguments_BDK_ZIP_QUEX_ERR_INT(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_QUEX_ERR_INT(...) "ZIP_QUEX_ERR_INT"


/**
 * NCB - zip_que#_err_int_w1s
 */
typedef union bdk_zip_quex_err_int_w1s {
	uint64_t u;
	struct bdk_zip_quex_err_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t mdbe                        : 1;  /**< R/W1C/H - SRAM ECC double-bit error. */
		uint64_t nwrp                        : 1;  /**< R/W1C/H - NCB write response error. */
		uint64_t nrrp                        : 1;  /**< R/W1C/H - NCB read response error. */
		uint64_t irde                        : 1;  /**< R/W1C/H - Instruction NCB read response error. */
		uint64_t dovf                        : 1;  /**< R/W1C/H - Doorbell overflow. */
#else
		uint64_t dovf                        : 1;
		uint64_t irde                        : 1;
		uint64_t nrrp                        : 1;
		uint64_t nwrp                        : 1;
		uint64_t mdbe                        : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_zip_quex_err_int_w1s_s  cn85xx; */
	/* struct bdk_zip_quex_err_int_w1s_s  cn88xx; */
} bdk_zip_quex_err_int_w1s_t;

static inline uint64_t BDK_ZIP_QUEX_ERR_INT_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_ERR_INT_W1S(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000003200ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_QUEX_ERR_INT_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_QUEX_ERR_INT_W1S(...) bdk_zip_quex_err_int_w1s_t
#define bustype_BDK_ZIP_QUEX_ERR_INT_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUEX_ERR_INT_W1S(p1) (p1)
#define arguments_BDK_ZIP_QUEX_ERR_INT_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_QUEX_ERR_INT_W1S(...) "ZIP_QUEX_ERR_INT_W1S"


/**
 * NCB - zip_que#_gcfg
 *
 * These registers reflect status of the zip instruction queues and are for debug use only.
 *
 */
typedef union bdk_zip_quex_gcfg {
	uint64_t u;
	struct bdk_zip_quex_gcfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t iqb_ldwb                    : 1;  /**< R/W - When set, reading a ZIP instruction full cache line will use NCB LDWB read-and-invalidate
                                                                 to improve performance. If clear, use NCB LDI for debugability. Partial cache line reads
                                                                 always use LDI. */
		uint64_t cbw_sty                     : 1;  /**< R/W - When set, a context cache block write will use STY. When clear, a context write will use STF. */
		uint64_t l2ld_cmd                    : 2;  /**< R/W - Which NCB load command to use for reading gather pointers, context, history and input
                                                                 data.
                                                                 0x0 = LDD.
                                                                 0x1 = LDI.
                                                                 0x2 = LDE.
                                                                 0x3 = LDY. */
#else
		uint64_t l2ld_cmd                    : 2;
		uint64_t cbw_sty                     : 1;
		uint64_t iqb_ldwb                    : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_zip_quex_gcfg_s         cn85xx; */
	/* struct bdk_zip_quex_gcfg_s         cn88xx; */
} bdk_zip_quex_gcfg_t;

static inline uint64_t BDK_ZIP_QUEX_GCFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_GCFG(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000001A00ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_QUEX_GCFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_QUEX_GCFG(...) bdk_zip_quex_gcfg_t
#define bustype_BDK_ZIP_QUEX_GCFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUEX_GCFG(p1) (p1)
#define arguments_BDK_ZIP_QUEX_GCFG(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_QUEX_GCFG(...) "ZIP_QUEX_GCFG"


/**
 * NCB - zip_que#_map
 *
 * These registers control how each instruction queue maps to zip cores.
 *
 */
typedef union bdk_zip_quex_map {
	uint64_t u;
	struct bdk_zip_quex_map_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t zce                         : 2;  /**< R/W - Zip core enable. Controls the logical instruction queue can be serviced by which zip core.
                                                                 Setting ZCE to 0 effectively disables the queue from being served (however the instruction
                                                                 can still be fetched).
                                                                 ZCE<1> = 1: Zip core 1 can serve the queue.
                                                                 ZCE<0> = 1: Zip core 0 can serve the queue. */
#else
		uint64_t zce                         : 2;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_zip_quex_map_s          cn85xx; */
	/* struct bdk_zip_quex_map_s          cn88xx; */
} bdk_zip_quex_map_t;

static inline uint64_t BDK_ZIP_QUEX_MAP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_MAP(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000001400ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_QUEX_MAP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_QUEX_MAP(...) bdk_zip_quex_map_t
#define bustype_BDK_ZIP_QUEX_MAP(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUEX_MAP(p1) (p1)
#define arguments_BDK_ZIP_QUEX_MAP(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_QUEX_MAP(...) "ZIP_QUEX_MAP"


/**
 * NCB - zip_que#_sbuf_addr
 *
 * These registers set the buffer parameters for the instruction queues. When quiescent (i.e.
 * outstanding doorbell count is 0), it is safe to rewrite this register to effectively reset the
 * command buffer state machine. These registers must be programmed after SW programms the
 * corresponding ZIP_QUE(0..7)_SBUF_CTL.
 */
typedef union bdk_zip_quex_sbuf_addr {
	uint64_t u;
	struct bdk_zip_quex_sbuf_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t ptr                         : 42; /**< R/W/H - Instruction buffer pointer bits <41:7> (128-byte aligned). When written, it is the initial
                                                                 buffer starting address; when read, it is the next read pointer to be requested from L2C.
                                                                 The PTR field is overwritten with the next pointer each time that the command buffer
                                                                 segment is exhausted. New commands will then be read from the newly specified command
                                                                 buffer pointer. */
		uint64_t off                         : 7;  /**< RO/H - When write, the value is ignored. When read, the returned value is the offset of the next
                                                                 read pointer. */
#else
		uint64_t off                         : 7;
		uint64_t ptr                         : 42;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_zip_quex_sbuf_addr_s    cn85xx; */
	/* struct bdk_zip_quex_sbuf_addr_s    cn88xx; */
} bdk_zip_quex_sbuf_addr_t;

static inline uint64_t BDK_ZIP_QUEX_SBUF_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_SBUF_ADDR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000001000ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_QUEX_SBUF_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_QUEX_SBUF_ADDR(...) bdk_zip_quex_sbuf_addr_t
#define bustype_BDK_ZIP_QUEX_SBUF_ADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUEX_SBUF_ADDR(p1) (p1)
#define arguments_BDK_ZIP_QUEX_SBUF_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_QUEX_SBUF_ADDR(...) "ZIP_QUEX_SBUF_ADDR"


/**
 * NCB - zip_que#_sbuf_ctl
 *
 * These registers set the buffer parameters for the instruction queues. When quiescent (i.e.
 * outstanding doorbell count is 0), it is safe to rewrite this register to effectively reset the
 * command buffer state machine. These registers must be programmed before SW programms the
 * corresponding ZIP_QUE(0..7)_SBUF_ADDR.
 */
typedef union bdk_zip_quex_sbuf_ctl {
	uint64_t u;
	struct bdk_zip_quex_sbuf_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_45_63              : 19;
		uint64_t size                        : 13; /**< R/W - Command-buffer size, in number of 64-bit words per command buffer segment. */
		uint64_t inst_be                     : 1;  /**< R/W - Instruction big endian control. When set, instructions are storaged in big endian format
                                                                 in
                                                                 memory. */
		uint64_t reserved_24_30              : 7;
		uint64_t stream_id                   : 8;  /**< R/W - STREAM_ID is the lower 8-bits of stream ID for the queue. */
		uint64_t reserved_12_15              : 4;
		uint64_t aura                        : 12; /**< RAZ - Reserved. */
#else
		uint64_t aura                        : 12;
		uint64_t reserved_12_15              : 4;
		uint64_t stream_id                   : 8;
		uint64_t reserved_24_30              : 7;
		uint64_t inst_be                     : 1;
		uint64_t size                        : 13;
		uint64_t reserved_45_63              : 19;
#endif
	} s;
	/* struct bdk_zip_quex_sbuf_ctl_s     cn85xx; */
	/* struct bdk_zip_quex_sbuf_ctl_s     cn88xx; */
} bdk_zip_quex_sbuf_ctl_t;

static inline uint64_t BDK_ZIP_QUEX_SBUF_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_SBUF_CTL(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000838000001200ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_ZIP_QUEX_SBUF_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ZIP_QUEX_SBUF_CTL(...) bdk_zip_quex_sbuf_ctl_t
#define bustype_BDK_ZIP_QUEX_SBUF_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUEX_SBUF_CTL(p1) (p1)
#define arguments_BDK_ZIP_QUEX_SBUF_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_ZIP_QUEX_SBUF_CTL(...) "ZIP_QUEX_SBUF_CTL"


/**
 * NCB - zip_que_ena
 *
 * If a queue is disabled, ZIP_CTL stops fetching instructions from the queue.
 *
 */
typedef union bdk_zip_que_ena {
	uint64_t u;
	struct bdk_zip_que_ena_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t ena                         : 8;  /**< R/W - Enables the logical instruction queues. Each bit corresponds to a queue:
                                                                 1 = queue is enabled.
                                                                 0 = queue is disabled. */
#else
		uint64_t ena                         : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_zip_que_ena_s           cn85xx; */
	/* struct bdk_zip_que_ena_s           cn88xx; */
} bdk_zip_que_ena_t;

#define BDK_ZIP_QUE_ENA BDK_ZIP_QUE_ENA_FUNC()
static inline uint64_t BDK_ZIP_QUE_ENA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUE_ENA_FUNC(void)
{
	return 0x0000838000000500ull;
}
#define typedef_BDK_ZIP_QUE_ENA bdk_zip_que_ena_t
#define bustype_BDK_ZIP_QUE_ENA BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUE_ENA 0
#define arguments_BDK_ZIP_QUE_ENA -1,-1,-1,-1
#define basename_BDK_ZIP_QUE_ENA "ZIP_QUE_ENA"


/**
 * NCB - zip_que_pri
 *
 * This registers defines the priority between instruction queues.
 *
 */
typedef union bdk_zip_que_pri {
	uint64_t u;
	struct bdk_zip_que_pri_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t pri                         : 8;  /**< R/W - Queue priority. Each bit corresponds to a queue:
                                                                 PRI[n]=1: Queue n has higher priority. Round-Robin between higher priority queues.
                                                                 PRI[n]=0: Queue n has lower priority. Round-Robin between lower priority queues. */
#else
		uint64_t pri                         : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_zip_que_pri_s           cn85xx; */
	/* struct bdk_zip_que_pri_s           cn88xx; */
} bdk_zip_que_pri_t;

#define BDK_ZIP_QUE_PRI BDK_ZIP_QUE_PRI_FUNC()
static inline uint64_t BDK_ZIP_QUE_PRI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUE_PRI_FUNC(void)
{
	return 0x0000838000000508ull;
}
#define typedef_BDK_ZIP_QUE_PRI bdk_zip_que_pri_t
#define bustype_BDK_ZIP_QUE_PRI BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_QUE_PRI 0
#define arguments_BDK_ZIP_QUE_PRI -1,-1,-1,-1
#define basename_BDK_ZIP_QUE_PRI "ZIP_QUE_PRI"


/**
 * NCB - zip_throttle
 *
 * This register controls the maximum number of in-flight X2I data fetch transactions. Writing 0
 * to this register causes the ZIP module to temporarily suspend NCB accesses; it is not
 * recommended for normal operation, but may be useful for diagnostics.
 */
typedef union bdk_zip_throttle {
	uint64_t u;
	struct bdk_zip_throttle_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t ld_infl                     : 6;  /**< R/W - Maximum number of in-flight data fetch transactions on the NCB. Larger values may improve
                                                                 ZIP performance but may starve other devices on the same NCB. Values > 32 are illegal. */
#else
		uint64_t ld_infl                     : 6;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_zip_throttle_s          cn85xx; */
	/* struct bdk_zip_throttle_s          cn88xx; */
} bdk_zip_throttle_t;

#define BDK_ZIP_THROTTLE BDK_ZIP_THROTTLE_FUNC()
static inline uint64_t BDK_ZIP_THROTTLE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_THROTTLE_FUNC(void)
{
	return 0x0000838000000010ull;
}
#define typedef_BDK_ZIP_THROTTLE bdk_zip_throttle_t
#define bustype_BDK_ZIP_THROTTLE BDK_CSR_TYPE_NCB
#define busnum_BDK_ZIP_THROTTLE 0
#define arguments_BDK_ZIP_THROTTLE -1,-1,-1,-1
#define basename_BDK_ZIP_THROTTLE "ZIP_THROTTLE"

#endif /* __BDK_CSRS_ZIP__ */
