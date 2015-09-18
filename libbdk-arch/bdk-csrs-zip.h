#ifndef __BDK_CSRS_ZIP_H__
#define __BDK_CSRS_ZIP_H__
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
 * Cavium ZIP.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration zip_bar_e
 *
 * ZIP Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_ZIP_BAR_E_ZIP_PF_BAR0 (0x838000000000ll) /**< Base address for standard registers. */
#define BDK_ZIP_BAR_E_ZIP_PF_BAR4_CN88XX (0x838000f00000ll) /**< Base address for MSI-X registers. */
#define BDK_ZIP_BAR_E_ZIP_PF_BAR4_CN83XX (0x838010000000ll) /**< Base address for MSI-X registers. */

/**
 * Enumeration zip_comp_e
 *
 * ZIP Completion Enumeration
 * Enumerates the values of ZIP_ZRES_S[COMPCODE].
 */
#define BDK_ZIP_COMP_E_BADCODE (7) /**< Uncompress found a bad code in the main Huffman codes. This is a fatal error and
                                       all other outputs (bytes in the output stream and ZIP_ZRES_S fields excluding
                                       ZIP_ZRES_S[COMPCODE]) from the ZIP coprocessor are unpredictable and should not
                                       be used by software.
                                       
                                       This code is specific to DEFLATE processing and is N/A for compression. */
#define BDK_ZIP_COMP_E_BADCODE2 (8) /**< Uncompress found a bad code in the 19 Huffman codes used to encode lengths. This
                                       is a fatal error and all other outputs (bytes in the output stream and
                                       ZIP_ZRES_S fields excluding ZIP_ZRES_S[COMPCODE]) from the ZIP coprocessor are
                                       unpredictable and should not be used by software.
                                       
                                       This code is specific to DEFLATE processing and is N/A for compression. */
#define BDK_ZIP_COMP_E_DTRUNC (2) /**< Output truncated. This is a fatal error and all other outputs (bytes in the
                                       output stream and ZIP_ZRES_S fields excluding ZIP_ZRES_S[COMPCODE]) from the ZIP
                                       coprocessor are unpredictable and should not be used by software. Refer to the
                                       IWORD0[TOTALOUTPUTLENGTH] description. */
#define BDK_ZIP_COMP_E_FATAL (0xb) /**< Uncompress found a string identifier that precedes the uncompressed data and
                                       decompression history. This is a fatal error and all other outputs (bytes in the
                                       output stream and ZIP_ZRES_S fields excluding ZIP_ZRES_S[COMPCODE]) from the ZIP
                                       coprocessor are unpredictable and should not be used by software.
                                       
                                       This code is N/A for compression. */
#define BDK_ZIP_COMP_E_ITRUNC (4) /**< Uncompress ran out of input data when IWORD0[EF] was set. This is a fatal error
                                       and all other outputs (bytes in the output stream and ZIP_ZRES_S fields
                                       excluding ZIP_ZRES_S[COMPCODE]) from the ZIP coprocessor are unpredictable and
                                       should not be used by software.
                                       
                                       This code is N/A for compression. */
#define BDK_ZIP_COMP_E_NLEN (6) /**< Uncompress found LEN != NLEN in an uncompressed block in the input. This is a
                                       fatal error and all other outputs (bytes in the output stream and ZIP_ZRES_S
                                       fields excluding ZIP_ZRES_S[COMPCODE]) from the ZIP coprocessor are
                                       unpredictable and should not be used by software.
                                       
                                       This code is specific to DEFLATE processing and is N/A for compression. */
#define BDK_ZIP_COMP_E_NOTDONE (0) /**< The COMPCODE value of zero is not written by hardware, but may be used by software to
                                       indicate the ZIP_ZRES_S structure has not yet been updated by hardware. */
#define BDK_ZIP_COMP_E_PARITY (0xa) /**< The compress or decompress encountered an internal parity error. This is a fatal
                                       error and all other outputs (bytes in the output stream and ZIP_ZRES_S fields
                                       excluding ZIP_ZRES_S[COMPCODE]) from the ZIP coprocessor are unpredictable and
                                       should not be used by the software. */
#define BDK_ZIP_COMP_E_RBLOCK (5) /**< Uncompress found the reserved block type 3. This is a fatal error and all other
                                       outputs (bytes in the output stream and ZIP_ZRES_S fields excluding
                                       ZIP_ZRES_S[COMPCODE]) from the ZIP coprocessor are unpredictable and should not
                                       be used by software. This code is specific to DEFLATE processing and is N/A for
                                       compression. */
#define BDK_ZIP_COMP_E_STOP (3) /**< Uncompress dynamically stopped. The ZIP coprocessor saved its state in the
                                       context, and the ZIP coprocessor can be restarted again when more space is
                                       available for output stream bytes. ZIP_ZRES_S[TOTALBYTESREAD] indicates the
                                       number of input bytes processed during this invocation of the ZIP
                                       coprocessor. ZIP_ZRES_S[TOTALBYTESWRITTEN] indicates the number of output stream
                                       bytes written during this invocation of the ZIP coprocessor. ZIP_ZRES_S[EF] is
                                       never set when the ZIP coprocessor returns this completion code.
                                       
                                       This code is N/A for compression. */
#define BDK_ZIP_COMP_E_SUCCESS (1) /**< Successful completion. All input-stream bytes were processed and all necessary output
                                       stream bytes produced. (ZIP_ZRES_S[TOTALBYTESWRITTEN] indicates the number of output bytes
                                       written during this invocation of the ZIP coprocessor.)
                                       
                                       For decompression:
                                       
                                       * If a decompression operation and ZIP_ZRES_S[EF] = 0, the ZIP coprocessor saved state in
                                       the
                                       context and can be restarted.
                                       
                                       * If a decompression operation and ZIP_ZRES_S[EF] = 1, the ZIP coprocessor completed
                                       decompression of all blocks in the file, and ZIP_ZRES_S[TOTALBITSPROCESSED] contains the
                                       total
                                       number of input bits processed to decompress all blocks in the file.
                                       
                                       Normally, an error-free full-file-decompression completion (i.e. one where ZIP_ZRES_S[EF]
                                       = 1
                                       and ZIP_ZRES_S[COMPCODE] = 0x1) means that the file was successfully decompressed by the
                                       hardware. However, when IWORD0[EF] was set for the ZIP invocation, the file may not have
                                       been successfully decompressed. In this case, software must also check the total number of
                                       bits used to decompress the file to guarantee that the hardware correctly found the end of
                                       the compressed input file. If the total number of bits used to decompress the file (the
                                       least-significant 32 bits of the total is specified in ZIP_ZRES_S[TOTALBITSPROCESSED])
                                       exceeds
                                       the total number of bits of the input that were used by all ZIP invocations for the file,
                                       then this invocation should be considered in error, exactly as if ZIP_ZRES_S[COMPCODE]
                                       were
                                       set to 4 (uncompress ran out of data). The total number of bits of input for the file is
                                       the sum of ZIP_ZRES_S[TOTALBYTESREAD] for all prior error-free ZIP decompression
                                       invocations
                                       for the file plus the number of input bytes for this invocation, times 8 (8 bits per
                                       byte). */
#define BDK_ZIP_COMP_E_TIMEOUT_CN88XX (0xc) /**< The compress or decompress operation timed out. All bytes in the output stream
                                       and ZIP_ZRES_S fields excluding ZIP_ZRES_S[COMPCODE] and ZIP_ZRES_S[DONEINT]
                                       from the ZIP coprocessor are unpredictable and must not be used by the
                                       software.
                                       Added in pass 2. */
#define BDK_ZIP_COMP_E_TIMEOUT_CN83XX (0xc) /**< The compress or decompress operation timed out. All bytes in the output stream
                                       and ZIP_ZRES_S fields excluding ZIP_ZRES_S[COMPCODE] and ZIP_ZRES_S[DONEINT]
                                       from the ZIP coprocessor are unpredictable and must not be used by the
                                       software. */
#define BDK_ZIP_COMP_E_ZERO_LEN (9) /**< Compress found a zero-length input. */

/**
 * Enumeration zip_hash_alg_e
 *
 * ZIP Hash Algorithm Enumeration
 * Enumerates ZIP_INST_S[HALG].
 */
#define BDK_ZIP_HASH_ALG_E_NONE (0) /**< No hashing. ZIP_ZRES_S writes 24 bytes. */
#define BDK_ZIP_HASH_ALG_E_SHA1 (1) /**< SHA-1 hashing. ZIP_ZRES_S writes 64 bytes.
                                       
                                       ZIP_INST_S[IV_PTR] if non-zero points to the hash initial value, otherwise if
                                       ZIP_INST_S[IV_PTR] = 0x0 the initial hash value is the SHA-1 standard
                                       0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0.
                                       
                                       INTERNAL: Verify this IVs result in the proper standard hash results. */
#define BDK_ZIP_HASH_ALG_E_SHA256 (2) /**< SHA-256 hashing. ZIP_ZRES_S writes 64 bytes.
                                       
                                       ZIP_INST_S[IV_PTR] if non-zero points to the hash initial value, otherwise if
                                       ZIP_INST_S[IV_PTR] = 0x0 the initial hash value is the SHA-256 standard
                                       0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A, 0x510E527F, 0x9B05688C,
                                       0x1F83D9AB, 0x5BE0CD19.
                                       
                                       INTERNAL: Verify this IVs result in the proper standard hash results. */

/**
 * Enumeration zip_int_vec_e
 *
 * ZIP MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_ZIP_INT_VEC_E_ECCE (0x10) /**< See interrupt clears ZIP_ECCE_INT, interrupt sets ZIP_ECCE_INT_W1S, enable clears
                                       ZIP_ECCE_ENA_W1C, and enable sets ZIP_ECCE_ENA_W1S. */
#define BDK_ZIP_INT_VEC_E_FIFE (0x11) /**< See interrupt clears ZIP_FIFE_INT, interrupt sets ZIP_FIFE_INT_W1S, enable clears
                                       ZIP_FIFE_ENA_W1C, and enable sets ZIP_FIFE_ENA_W1S. */
#define BDK_ZIP_INT_VEC_E_QUEX_DONE(a) (0 + (a)) /**< See interrupt clears ZIP_QUE(0..7)_DONE_ACK, interrupt sets ZIP_QUE(0..7)_DONE and
                                       interrupt coalescing
                                       waits ZIP_QUE(0..7)_DONE_WAIT, enable clears ZIP_QUE(0..7)_DONE_ENA_W1C, and enable sets
                                       ZIP_QUE(0..7)_DONE_ENA_W1S. */
#define BDK_ZIP_INT_VEC_E_QUEX_ERR(a) (8 + (a)) /**< See interrupt clears ZIP_QUE(0..7)_ERR_INT, interrupt sets ZIP_QUE(0..7)_ERR_INT_W1S,
                                       enable clears
                                       ZIP_QUE(0..7)_ERR_ENA_W1C, and enable sets ZIP_QUE(0..7)_ERR_ENA_W1S. */

/**
 * Enumeration zip_op_e
 *
 * ZIP Operation Enumeration
 * Enumerates ZIP_INST_S[OP].
 * INTERNAL: This encoding provides backward compatibility with CN88XX software.
 */
#define BDK_ZIP_OP_E_COMP (2) /**< Compression. */
#define BDK_ZIP_OP_E_DECOMP (0) /**< Decompression. */
#define BDK_ZIP_OP_E_NOCOMP (1) /**< Hash only; no compression nor decompression. */

/**
 * Structure zip_inst_s
 *
 * ZIP Instruction Structure
 * Each ZIP instruction has 16 words (they are called IWORD0 to IWORD15 within the structure).
 */
union bdk_zip_inst_s
{
    uint64_t u[16];
    struct bdk_zip_inst_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t doneint               : 1;  /**< [ 63: 63] Done Interrupt. When DONEINT is set and the instruction completes,
                                                                 ZIP_QUE(0..7)_DONE[DONE] will be incremented. */
        uint64_t reserved_56_62        : 7;
        uint64_t totaloutputlength     : 24; /**< [ 55: 32] Indicates the maximum number of output-stream bytes that can be written.
                                                                 TOTALOUTPUTLENGTH must exactly match the number of bytes indicated by
                                                                 the output pointer (either by ZPTR[LENGTH] directly if
                                                                 [DS] = 0, or indirectly if [DS] = 1). */
        uint64_t reserved_27_31        : 5;
        uint64_t exn                   : 3;  /**< [ 26: 24] EXN is the number of bits produced beyond the last output byte written by
                                                                 the prior ZIP coprocessor invocation. */
        uint64_t reserved_23           : 1;
        uint64_t exbits                : 7;  /**< [ 22: 16] EXN,EXBITS are the previously-generated compressed bits beyond the last
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
        uint64_t reserved_15           : 1;
        uint64_t halg                  : 3;  /**< [ 14: 12] Hash algorithm and enable. Enumerated by ZIP_HASH_ALG_E. */
        uint64_t sf                    : 1;  /**< [ 11: 11] SYNC_FLUSH. When set, enables SYNC_FLUSH functionality.

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
        uint64_t ss                    : 2;  /**< [ 10:  9] Compression speed/storage.
                                                                 Forces the ZIP compression engine to compress faster, at the expense of the compression
                                                                 ratio.

                                                                 For compression:
                                                                 0x0 = best quality, slowest speed.
                                                                 0x2 = lower quality, faster speed.
                                                                 0x1 = medium quality, medium speed.
                                                                 0x3 = lowest quality, best speed.

                                                                 For decompression, SS must be 0x0. */
        uint64_t cc                    : 2;  /**< [  8:  7] Compression coding.

                                                                 For compression:
                                                                 0x0 = hardware selects the better of fixed or dynamic Huffman encoding.
                                                                 0x1 = force dynamic Huffman encoding.
                                                                 0x2 = force fixed Huffman encoding.
                                                                 0x3 = force LZS encoding.

                                                                 For DEFLATE decompression, CC must be 0x0. For LZS decompression, CC must be 0x3. */
        uint64_t ef                    : 1;  /**< [  6:  6] End of input data. Set when the end of the input-data stream ends a file.

                                                                 For compression, if EF = 1, the ZIP engine always marks the last output block to be
                                                                 final. (The extra bits are zero-extended and written out as an output-stream byte.)

                                                                 For decompression, it is an error if EF = 1 and the ZIP coprocessor does not complete
                                                                 decompression of all blocks before it exhausts the input compressed data stream
                                                                 (ZIP_ZRES_S[COMPCODE] = ZIP_COMP_E::ITRUNC in this case.). It is not an error if EF = 0
                                                                 when the ZIP coprocessor completes decompression of all blocks in the file. */
        uint64_t bf                    : 1;  /**< [  5:  5] Beginning of file. Set when the beginning of the (non-history) input stream starts a
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
        uint64_t reserved_3_4          : 2;
        uint64_t ds                    : 1;  /**< [  2:  2] Data scatter:
                                                                 1 = IWORD8/9 (the output pointer) points to a list of scatter pointers that are read
                                                                 by the coprocessor before writing the actual output data.
                                                                 0 = IWORD8/9 points directly at the locations to write the output data.

                                                                 If DS = 1, the IWORD9 LENGTH field, indicating the number of pointers in the
                                                                 output scatter list, must be at least 0x2. */
        uint64_t dg                    : 1;  /**< [  1:  1] Data gather:
                                                                 1 = IWORD6/7 (the input and compression history pointer) points to a gather list of
                                                                 pointers that are read by the coprocessor before reading the actual history/input data.
                                                                 0 = IWORD6/7 points directly at the actual history/input data.

                                                                 If DG = 1, the IWORD7 LENGTH field, indicating the number of pointers in the
                                                                 input and compression history gather list, must be at least 0x2. */
        uint64_t hg                    : 1;  /**< [  0:  0] History gather:
                                                                 1 = IWORD4/5 (the decompression history pointer) points to a gather list of
                                                                 pointers that are read by the coprocessor before reading the actual history data.
                                                                 0 = IWORD4/5 points directly at the actual history data.
                                                                 HG must be zero for a compression operation.

                                                                 If HG = 1, history data must be present for the decompression operation, and the
                                                                 IWORD5 LENGTH field, indicating the number of pointers in the decompression
                                                                 history gather list, must be at least 0x2. */
#else /* Word 0 - Little Endian */
        uint64_t hg                    : 1;  /**< [  0:  0] History gather:
                                                                 1 = IWORD4/5 (the decompression history pointer) points to a gather list of
                                                                 pointers that are read by the coprocessor before reading the actual history data.
                                                                 0 = IWORD4/5 points directly at the actual history data.
                                                                 HG must be zero for a compression operation.

                                                                 If HG = 1, history data must be present for the decompression operation, and the
                                                                 IWORD5 LENGTH field, indicating the number of pointers in the decompression
                                                                 history gather list, must be at least 0x2. */
        uint64_t dg                    : 1;  /**< [  1:  1] Data gather:
                                                                 1 = IWORD6/7 (the input and compression history pointer) points to a gather list of
                                                                 pointers that are read by the coprocessor before reading the actual history/input data.
                                                                 0 = IWORD6/7 points directly at the actual history/input data.

                                                                 If DG = 1, the IWORD7 LENGTH field, indicating the number of pointers in the
                                                                 input and compression history gather list, must be at least 0x2. */
        uint64_t ds                    : 1;  /**< [  2:  2] Data scatter:
                                                                 1 = IWORD8/9 (the output pointer) points to a list of scatter pointers that are read
                                                                 by the coprocessor before writing the actual output data.
                                                                 0 = IWORD8/9 points directly at the locations to write the output data.

                                                                 If DS = 1, the IWORD9 LENGTH field, indicating the number of pointers in the
                                                                 output scatter list, must be at least 0x2. */
        uint64_t reserved_3_4          : 2;
        uint64_t bf                    : 1;  /**< [  5:  5] Beginning of file. Set when the beginning of the (non-history) input stream starts a
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
        uint64_t ef                    : 1;  /**< [  6:  6] End of input data. Set when the end of the input-data stream ends a file.

                                                                 For compression, if EF = 1, the ZIP engine always marks the last output block to be
                                                                 final. (The extra bits are zero-extended and written out as an output-stream byte.)

                                                                 For decompression, it is an error if EF = 1 and the ZIP coprocessor does not complete
                                                                 decompression of all blocks before it exhausts the input compressed data stream
                                                                 (ZIP_ZRES_S[COMPCODE] = ZIP_COMP_E::ITRUNC in this case.). It is not an error if EF = 0
                                                                 when the ZIP coprocessor completes decompression of all blocks in the file. */
        uint64_t cc                    : 2;  /**< [  8:  7] Compression coding.

                                                                 For compression:
                                                                 0x0 = hardware selects the better of fixed or dynamic Huffman encoding.
                                                                 0x1 = force dynamic Huffman encoding.
                                                                 0x2 = force fixed Huffman encoding.
                                                                 0x3 = force LZS encoding.

                                                                 For DEFLATE decompression, CC must be 0x0. For LZS decompression, CC must be 0x3. */
        uint64_t ss                    : 2;  /**< [ 10:  9] Compression speed/storage.
                                                                 Forces the ZIP compression engine to compress faster, at the expense of the compression
                                                                 ratio.

                                                                 For compression:
                                                                 0x0 = best quality, slowest speed.
                                                                 0x2 = lower quality, faster speed.
                                                                 0x1 = medium quality, medium speed.
                                                                 0x3 = lowest quality, best speed.

                                                                 For decompression, SS must be 0x0. */
        uint64_t sf                    : 1;  /**< [ 11: 11] SYNC_FLUSH. When set, enables SYNC_FLUSH functionality.

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
        uint64_t halg                  : 3;  /**< [ 14: 12] Hash algorithm and enable. Enumerated by ZIP_HASH_ALG_E. */
        uint64_t reserved_15           : 1;
        uint64_t exbits                : 7;  /**< [ 22: 16] EXN,EXBITS are the previously-generated compressed bits beyond the last
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
        uint64_t reserved_23           : 1;
        uint64_t exn                   : 3;  /**< [ 26: 24] EXN is the number of bits produced beyond the last output byte written by
                                                                 the prior ZIP coprocessor invocation. */
        uint64_t reserved_27_31        : 5;
        uint64_t totaloutputlength     : 24; /**< [ 55: 32] Indicates the maximum number of output-stream bytes that can be written.
                                                                 TOTALOUTPUTLENGTH must exactly match the number of bytes indicated by
                                                                 the output pointer (either by ZPTR[LENGTH] directly if
                                                                 [DS] = 0, or indirectly if [DS] = 1). */
        uint64_t reserved_56_62        : 7;
        uint64_t doneint               : 1;  /**< [ 63: 63] Done Interrupt. When DONEINT is set and the instruction completes,
                                                                 ZIP_QUE(0..7)_DONE[DONE] will be incremented. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t historylength         : 16; /**< [127:112] With compression, history bytes can be prepended in the input data stream
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
        uint64_t reserved_96_111       : 16;
        uint64_t adlercrc32            : 32; /**< [ 95: 64] This 32-bit field represents the current state of the ADLER32 or CRC32 units. The
                                                                 hardware executes both ADLER32 and CRC32 on the processed uncompressed data
                                                                 bytes using this value as the current checksum. Though the hardware outputs both
                                                                 the ADLER32 and CRC32 results, ADLERCRC32 is the only checksum input, so only
                                                                 one of the two outputs is likely to be useful.

                                                                 The ADLER32 algorithm is defined in RFC1950.

                                                                 CRC32 is defined in ITU-T X.244, Annex D, pp. 144-145 / ISO 8073. */
#else /* Word 1 - Little Endian */
        uint64_t adlercrc32            : 32; /**< [ 95: 64] This 32-bit field represents the current state of the ADLER32 or CRC32 units. The
                                                                 hardware executes both ADLER32 and CRC32 on the processed uncompressed data
                                                                 bytes using this value as the current checksum. Though the hardware outputs both
                                                                 the ADLER32 and CRC32 results, ADLERCRC32 is the only checksum input, so only
                                                                 one of the two outputs is likely to be useful.

                                                                 The ADLER32 algorithm is defined in RFC1950.

                                                                 CRC32 is defined in ITU-T X.244, Annex D, pp. 144-145 / ISO 8073. */
        uint64_t reserved_96_111       : 16;
        uint64_t historylength         : 16; /**< [127:112] With compression, history bytes can be prepended in the input data stream
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
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t ctx_ptr_addr          : 64; /**< [191:128] Decompresion context pointer address (ZIP_ZPTR_S format address word definition).
                                                                 The address must be 8-byte aligned. */
#else /* Word 2 - Little Endian */
        uint64_t ctx_ptr_addr          : 64; /**< [191:128] Decompresion context pointer address (ZIP_ZPTR_S format address word definition).
                                                                 The address must be 8-byte aligned. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t ctx_ptr_ctl           : 64; /**< [255:192] Decompresion context pointer control (ZIP_ZPTR_S format control word definition).
                                                                 DATA_BE = 0 and LENGTH=0 (2048 bytes implied). */
#else /* Word 3 - Little Endian */
        uint64_t ctx_ptr_ctl           : 64; /**< [255:192] Decompresion context pointer control (ZIP_ZPTR_S format control word definition).
                                                                 DATA_BE = 0 and LENGTH=0 (2048 bytes implied). */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t his_ptr_addr          : 64; /**< [319:256] Decompresion history pointer address (ZIP_ZPTR_S format address word definition). */
#else /* Word 4 - Little Endian */
        uint64_t his_ptr_addr          : 64; /**< [319:256] Decompresion history pointer address (ZIP_ZPTR_S format address word definition). */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t his_ptr_ctl           : 64; /**< [383:320] Decompresion history pointer control (ZIP_ZPTR_S format control word definition).
                                                                 FW = 0. ZIP_INST_S[HG] set if gather. */
#else /* Word 5 - Little Endian */
        uint64_t his_ptr_ctl           : 64; /**< [383:320] Decompresion history pointer control (ZIP_ZPTR_S format control word definition).
                                                                 FW = 0. ZIP_INST_S[HG] set if gather. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t inp_ptr_addr          : 64; /**< [447:384] Input and compresion history pointer address (ZIP_ZPTR_S format address word definition). */
#else /* Word 6 - Little Endian */
        uint64_t inp_ptr_addr          : 64; /**< [447:384] Input and compresion history pointer address (ZIP_ZPTR_S format address word definition). */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t inp_ptr_ctl           : 64; /**< [511:448] Input and compresion history pointer control (ZIP_ZPTR_S format control word definition).
                                                                 FW = 0. ZIP_INST_S[DG] set if gather. */
#else /* Word 7 - Little Endian */
        uint64_t inp_ptr_ctl           : 64; /**< [511:448] Input and compresion history pointer control (ZIP_ZPTR_S format control word definition).
                                                                 FW = 0. ZIP_INST_S[DG] set if gather. */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t out_ptr_addr          : 64; /**< [575:512] Output pointer address  (ZIP_ZPTR_S format address word definition).
                                                                 Points to where the output data will be written by the ZIP coprocessor for this
                                                                 invocation. */
#else /* Word 8 - Little Endian */
        uint64_t out_ptr_addr          : 64; /**< [575:512] Output pointer address  (ZIP_ZPTR_S format address word definition).
                                                                 Points to where the output data will be written by the ZIP coprocessor for this
                                                                 invocation. */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t out_ptr_ctl           : 64; /**< [639:576] Output pointer control (ZIP_ZPTR_S format control word definition).
                                                                 [DS] set if scatter. */
#else /* Word 9 - Little Endian */
        uint64_t out_ptr_ctl           : 64; /**< [639:576] Output pointer control (ZIP_ZPTR_S format control word definition).
                                                                 [DS] set if scatter. */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t res_ptr_addr          : 64; /**< [703:640] Result pointer address (ZIP_ZPTR_S format address word definition).
                                                                 Address is 8-byte aligned. */
#else /* Word 10 - Little Endian */
        uint64_t res_ptr_addr          : 64; /**< [703:640] Result pointer address (ZIP_ZPTR_S format address word definition).
                                                                 Address is 8-byte aligned. */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t res_ptr_ctl           : 64; /**< [767:704] Result pointer control (ZIP_ZPTR_S format control word definition).

                                                                 Inside this ZIP_ZPTR_S:
                                                                   * ZIP_ZPTR_S[FW] can be either 0 or 1.
                                                                   * ZIP_ZPTR_S[NC] can be either 0 or 1.
                                                                   * ZIP_ZPTR_S[DATA_BE] must be 0.
                                                                   * ZIP_ZPTR_S[LENGTH] must be 0. (24-bytes is implied).
                                                                   * ZIP_ZPTR_S[ADDR] must be eight-byte aligned. */
#else /* Word 11 - Little Endian */
        uint64_t res_ptr_ctl           : 64; /**< [767:704] Result pointer control (ZIP_ZPTR_S format control word definition).

                                                                 Inside this ZIP_ZPTR_S:
                                                                   * ZIP_ZPTR_S[FW] can be either 0 or 1.
                                                                   * ZIP_ZPTR_S[NC] can be either 0 or 1.
                                                                   * ZIP_ZPTR_S[DATA_BE] must be 0.
                                                                   * ZIP_ZPTR_S[LENGTH] must be 0. (24-bytes is implied).
                                                                   * ZIP_ZPTR_S[ADDR] must be eight-byte aligned. */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t reserved_812_831      : 20;
        uint64_t ggrp                  : 10; /**< [811:802] If [WQ_PTR] is non-zero, the SSO guest-group to use when ZIP submits work to
                                                                 SSO. */
        uint64_t tt                    : 2;  /**< [801:800] If [WQ_PTR] is non-zero, the SSO tag type to use when ZIP submits work to SSO. */
        uint64_t tag                   : 32; /**< [799:768] If [WQ_PTR] is non-zero, the SSO tag to use when ZIP submits work to SSO. */
#else /* Word 12 - Little Endian */
        uint64_t tag                   : 32; /**< [799:768] If [WQ_PTR] is non-zero, the SSO tag to use when ZIP submits work to SSO. */
        uint64_t tt                    : 2;  /**< [801:800] If [WQ_PTR] is non-zero, the SSO tag type to use when ZIP submits work to SSO. */
        uint64_t ggrp                  : 10; /**< [811:802] If [WQ_PTR] is non-zero, the SSO guest-group to use when ZIP submits work to
                                                                 SSO. */
        uint64_t reserved_812_831      : 20;
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t reserved_881_895      : 15;
        uint64_t wq_ptr                : 49; /**< [880:832] If WQ_PTR is non-zero, it is a pointer to a work-queue entry that ZIP submits
                                                                 work to SSO after all context, output data, and result write operations are
                                                                 visible to other CNXXXX units and the cores. */
#else /* Word 13 - Little Endian */
        uint64_t wq_ptr                : 49; /**< [880:832] If WQ_PTR is non-zero, it is a pointer to a work-queue entry that ZIP submits
                                                                 work to SSO after all context, output data, and result write operations are
                                                                 visible to other CNXXXX units and the cores. */
        uint64_t reserved_881_895      : 15;
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t reserved_896_959      : 64;
#else /* Word 14 - Little Endian */
        uint64_t reserved_896_959      : 64;
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t reserved_1009_1023    : 15;
        uint64_t iv_ptr                : 49; /**< [1008:960] Hash initial value pointer.

                                                                 If ZIP_INST_S[HALG] = 0x0 (NONE), must be 0x0.

                                                                 If ZIP_INST_S[HALG] = ZIP_HASH_ALG_E::SHA1/SHA256, and [IV_PTR] != 0x0, points
                                                                 to the address ZIP will read 32 bytes from to obtain the initial hash value.

                                                                 If ZIP_INST_S[HALG] = ZIP_HASH_ALG_E::SHA1/SHA256, and [IV_PTR] = 0x0, the
                                                                 initial hash value is the standard value enumerated by ZIP_HASH_ALG_E. */
#else /* Word 15 - Little Endian */
        uint64_t iv_ptr                : 49; /**< [1008:960] Hash initial value pointer.

                                                                 If ZIP_INST_S[HALG] = 0x0 (NONE), must be 0x0.

                                                                 If ZIP_INST_S[HALG] = ZIP_HASH_ALG_E::SHA1/SHA256, and [IV_PTR] != 0x0, points
                                                                 to the address ZIP will read 32 bytes from to obtain the initial hash value.

                                                                 If ZIP_INST_S[HALG] = ZIP_HASH_ALG_E::SHA1/SHA256, and [IV_PTR] = 0x0, the
                                                                 initial hash value is the standard value enumerated by ZIP_HASH_ALG_E. */
        uint64_t reserved_1009_1023    : 15;
#endif /* Word 15 - End */
    } s;
    struct bdk_zip_inst_s_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t doneint               : 1;  /**< [ 63: 63] Done Interrupt. When DONEINT is set and the instruction completes,
                                                                 ZIP_QUE(0..7)_DONE[DONE] will be incremented. */
        uint64_t reserved_56_62        : 7;
        uint64_t totaloutputlength     : 24; /**< [ 55: 32] Indicates the maximum number of output-stream bytes that can be written.
                                                                 TOTALOUTPUTLENGTH must exactly match the number of bytes indicated by
                                                                 the output pointer (either by ZPTR[LENGTH] directly if
                                                                 [DS] = 0, or indirectly if [DS] = 1). */
        uint64_t reserved_27_31        : 5;
        uint64_t exn                   : 3;  /**< [ 26: 24] EXN is the number of bits produced beyond the last output byte written by
                                                                 the prior ZIP coprocessor invocation. */
        uint64_t reserved_23           : 1;
        uint64_t exbits                : 7;  /**< [ 22: 16] EXN,EXBITS are the previously-generated compressed bits beyond the last
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
        uint64_t reserved_12_15        : 4;
        uint64_t sf                    : 1;  /**< [ 11: 11] SYNC_FLUSH. When set, enables SYNC_FLUSH functionality.

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
        uint64_t ss                    : 2;  /**< [ 10:  9] Compression speed/storage.
                                                                 Forces the ZIP compression engine to compress faster, at the expense of the compression
                                                                 ratio.

                                                                 For compression:
                                                                 0x0 = best quality, slowest speed.
                                                                 0x2 = lower quality, faster speed.
                                                                 0x1 = medium quality, medium speed.
                                                                 0x3 = lowest quality, best speed.

                                                                 For decompression, SS must be 0x0. */
        uint64_t cc                    : 2;  /**< [  8:  7] Compression coding.

                                                                 For compression:
                                                                 0x0 = hardware selects the better of fixed or dynamic Huffman encoding.
                                                                 0x1 = force dynamic Huffman encoding.
                                                                 0x2 = force fixed Huffman encoding.
                                                                 0x3 = force LZS encoding.

                                                                 For DEFLATE decompression, CC must be 0x0. For LZS decompression, CC must be 0x3. */
        uint64_t ef                    : 1;  /**< [  6:  6] End of input data. Set when the end of the input-data stream ends a file.

                                                                 For compression, if EF = 1, the ZIP engine always marks the last output block to be
                                                                 final. (The extra bits are zero-extended and written out as an output-stream byte.)

                                                                 For decompression, it is an error if EF = 1 and the ZIP coprocessor does not complete
                                                                 decompression of all blocks before it exhausts the input compressed data stream
                                                                 (ZIP_ZRES_S[COMPCODE] = ZIP_COMP_E::ITRUNC in this case.). It is not an error if EF = 0
                                                                 when the ZIP coprocessor completes decompression of all blocks in the file. */
        uint64_t bf                    : 1;  /**< [  5:  5] Beginning of file. Set when the beginning of the (non-history) input stream starts a
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
        uint64_t ce                    : 1;  /**< [  4:  4] Compression enable:
                                                                   1 = ZIP operation is a compress.
                                                                   0 = ZIP operation is an uncompress. */
        uint64_t reserved_3            : 1;
        uint64_t ds                    : 1;  /**< [  2:  2] Data scatter:
                                                                 1 = [OUT_PTR_ADDR] points to a list of scatter pointers that are read
                                                                 by the coprocessor before writing the actual output data.
                                                                 0 = [OUT_PTR_ADDR] points directly at the locations to write the output data.

                                                                 If DS = 1, the [OUT_PTR_CTL] LENGTH field, indicating the number of pointers in
                                                                 the output scatter list, must be at least 0x2. */
        uint64_t dg                    : 1;  /**< [  1:  1] Data gather:
                                                                 1 = [INP_PTR_ADDR] (the input and compression history pointer) points to a gather list of
                                                                 pointers that are read by the coprocessor before reading the actual history/input data.
                                                                 0 = [INP_PTR_ADDR] points directly at the actual history/input data.

                                                                 If DG = 1, the [INP_PTR_CTL]'s LENGTH field, indicating the number of pointers in the
                                                                 input and compression history gather list, must be at least 0x2. */
        uint64_t hg                    : 1;  /**< [  0:  0] History gather:
                                                                 1 = [HIS_PTR_ADDR] points to a gather list of
                                                                 pointers that are read by the coprocessor before reading the actual history data.
                                                                 0 = [HIS_PTR_ADDR] points directly at the actual history data.
                                                                 HG must be zero for a compression operation.

                                                                 If HG = 1, history data must be present for the decompression operation, and the
                                                                 [HIST_PTR_ADDR]'s LENGTH field, indicating the number of pointers in the
                                                                 decompression history gather list, must be at least 0x2. */
#else /* Word 0 - Little Endian */
        uint64_t hg                    : 1;  /**< [  0:  0] History gather:
                                                                 1 = [HIS_PTR_ADDR] points to a gather list of
                                                                 pointers that are read by the coprocessor before reading the actual history data.
                                                                 0 = [HIS_PTR_ADDR] points directly at the actual history data.
                                                                 HG must be zero for a compression operation.

                                                                 If HG = 1, history data must be present for the decompression operation, and the
                                                                 [HIST_PTR_ADDR]'s LENGTH field, indicating the number of pointers in the
                                                                 decompression history gather list, must be at least 0x2. */
        uint64_t dg                    : 1;  /**< [  1:  1] Data gather:
                                                                 1 = [INP_PTR_ADDR] (the input and compression history pointer) points to a gather list of
                                                                 pointers that are read by the coprocessor before reading the actual history/input data.
                                                                 0 = [INP_PTR_ADDR] points directly at the actual history/input data.

                                                                 If DG = 1, the [INP_PTR_CTL]'s LENGTH field, indicating the number of pointers in the
                                                                 input and compression history gather list, must be at least 0x2. */
        uint64_t ds                    : 1;  /**< [  2:  2] Data scatter:
                                                                 1 = [OUT_PTR_ADDR] points to a list of scatter pointers that are read
                                                                 by the coprocessor before writing the actual output data.
                                                                 0 = [OUT_PTR_ADDR] points directly at the locations to write the output data.

                                                                 If DS = 1, the [OUT_PTR_CTL] LENGTH field, indicating the number of pointers in
                                                                 the output scatter list, must be at least 0x2. */
        uint64_t reserved_3            : 1;
        uint64_t ce                    : 1;  /**< [  4:  4] Compression enable:
                                                                   1 = ZIP operation is a compress.
                                                                   0 = ZIP operation is an uncompress. */
        uint64_t bf                    : 1;  /**< [  5:  5] Beginning of file. Set when the beginning of the (non-history) input stream starts a
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
        uint64_t ef                    : 1;  /**< [  6:  6] End of input data. Set when the end of the input-data stream ends a file.

                                                                 For compression, if EF = 1, the ZIP engine always marks the last output block to be
                                                                 final. (The extra bits are zero-extended and written out as an output-stream byte.)

                                                                 For decompression, it is an error if EF = 1 and the ZIP coprocessor does not complete
                                                                 decompression of all blocks before it exhausts the input compressed data stream
                                                                 (ZIP_ZRES_S[COMPCODE] = ZIP_COMP_E::ITRUNC in this case.). It is not an error if EF = 0
                                                                 when the ZIP coprocessor completes decompression of all blocks in the file. */
        uint64_t cc                    : 2;  /**< [  8:  7] Compression coding.

                                                                 For compression:
                                                                 0x0 = hardware selects the better of fixed or dynamic Huffman encoding.
                                                                 0x1 = force dynamic Huffman encoding.
                                                                 0x2 = force fixed Huffman encoding.
                                                                 0x3 = force LZS encoding.

                                                                 For DEFLATE decompression, CC must be 0x0. For LZS decompression, CC must be 0x3. */
        uint64_t ss                    : 2;  /**< [ 10:  9] Compression speed/storage.
                                                                 Forces the ZIP compression engine to compress faster, at the expense of the compression
                                                                 ratio.

                                                                 For compression:
                                                                 0x0 = best quality, slowest speed.
                                                                 0x2 = lower quality, faster speed.
                                                                 0x1 = medium quality, medium speed.
                                                                 0x3 = lowest quality, best speed.

                                                                 For decompression, SS must be 0x0. */
        uint64_t sf                    : 1;  /**< [ 11: 11] SYNC_FLUSH. When set, enables SYNC_FLUSH functionality.

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
        uint64_t reserved_12_15        : 4;
        uint64_t exbits                : 7;  /**< [ 22: 16] EXN,EXBITS are the previously-generated compressed bits beyond the last
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
        uint64_t reserved_23           : 1;
        uint64_t exn                   : 3;  /**< [ 26: 24] EXN is the number of bits produced beyond the last output byte written by
                                                                 the prior ZIP coprocessor invocation. */
        uint64_t reserved_27_31        : 5;
        uint64_t totaloutputlength     : 24; /**< [ 55: 32] Indicates the maximum number of output-stream bytes that can be written.
                                                                 TOTALOUTPUTLENGTH must exactly match the number of bytes indicated by
                                                                 the output pointer (either by ZPTR[LENGTH] directly if
                                                                 [DS] = 0, or indirectly if [DS] = 1). */
        uint64_t reserved_56_62        : 7;
        uint64_t doneint               : 1;  /**< [ 63: 63] Done Interrupt. When DONEINT is set and the instruction completes,
                                                                 ZIP_QUE(0..7)_DONE[DONE] will be incremented. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t historylength         : 16; /**< [127:112] With compression, history bytes can be prepended in the input data stream
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
        uint64_t reserved_96_111       : 16;
        uint64_t adlercrc32            : 32; /**< [ 95: 64] This 32-bit field represents the current state of the ADLER32 or CRC32 units. The
                                                                 hardware executes both ADLER32 and CRC32 on the processed uncompressed data
                                                                 bytes using this value as the current checksum. Though the hardware outputs both
                                                                 the ADLER32 and CRC32 results, ADLERCRC32 is the only checksum input, so only
                                                                 one of the two outputs is likely to be useful.

                                                                 The ADLER32 algorithm is defined in RFC1950.

                                                                 CRC32 is defined in ITU-T X.244, Annex D, pp. 144-145 / ISO 8073. */
#else /* Word 1 - Little Endian */
        uint64_t adlercrc32            : 32; /**< [ 95: 64] This 32-bit field represents the current state of the ADLER32 or CRC32 units. The
                                                                 hardware executes both ADLER32 and CRC32 on the processed uncompressed data
                                                                 bytes using this value as the current checksum. Though the hardware outputs both
                                                                 the ADLER32 and CRC32 results, ADLERCRC32 is the only checksum input, so only
                                                                 one of the two outputs is likely to be useful.

                                                                 The ADLER32 algorithm is defined in RFC1950.

                                                                 CRC32 is defined in ITU-T X.244, Annex D, pp. 144-145 / ISO 8073. */
        uint64_t reserved_96_111       : 16;
        uint64_t historylength         : 16; /**< [127:112] With compression, history bytes can be prepended in the input data stream
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
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t ctx_ptr_addr          : 64; /**< [191:128] Decompresion context pointer address (ZIP_ZPTR_S format address word definition).
                                                                 The address must be 8-byte aligned. */
#else /* Word 2 - Little Endian */
        uint64_t ctx_ptr_addr          : 64; /**< [191:128] Decompresion context pointer address (ZIP_ZPTR_S format address word definition).
                                                                 The address must be 8-byte aligned. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t ctx_ptr_ctl           : 64; /**< [255:192] Decompresion context pointer control (ZIP_ZPTR_S format control word definition).
                                                                 DATA_BE = 0 and LENGTH=0 (2048 bytes implied). */
#else /* Word 3 - Little Endian */
        uint64_t ctx_ptr_ctl           : 64; /**< [255:192] Decompresion context pointer control (ZIP_ZPTR_S format control word definition).
                                                                 DATA_BE = 0 and LENGTH=0 (2048 bytes implied). */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t his_ptr_addr          : 64; /**< [319:256] Decompresion history pointer address (ZIP_ZPTR_S format address word definition). */
#else /* Word 4 - Little Endian */
        uint64_t his_ptr_addr          : 64; /**< [319:256] Decompresion history pointer address (ZIP_ZPTR_S format address word definition). */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t his_ptr_ctl           : 64; /**< [383:320] Decompresion history pointer control (ZIP_ZPTR_S format control word definition).
                                                                 FW = 0. ZIP_INST_S[HG] set if gather. */
#else /* Word 5 - Little Endian */
        uint64_t his_ptr_ctl           : 64; /**< [383:320] Decompresion history pointer control (ZIP_ZPTR_S format control word definition).
                                                                 FW = 0. ZIP_INST_S[HG] set if gather. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t inp_ptr_addr          : 64; /**< [447:384] Input and compresion history pointer address (ZIP_ZPTR_S format address word definition). */
#else /* Word 6 - Little Endian */
        uint64_t inp_ptr_addr          : 64; /**< [447:384] Input and compresion history pointer address (ZIP_ZPTR_S format address word definition). */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t inp_ptr_ctl           : 64; /**< [511:448] Input and compresion history pointer control (ZIP_ZPTR_S format control word definition).
                                                                 FW = 0. ZIP_INST_S[DG] set if gather. */
#else /* Word 7 - Little Endian */
        uint64_t inp_ptr_ctl           : 64; /**< [511:448] Input and compresion history pointer control (ZIP_ZPTR_S format control word definition).
                                                                 FW = 0. ZIP_INST_S[DG] set if gather. */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t out_ptr_addr          : 64; /**< [575:512] Output pointer address  (ZIP_ZPTR_S format address word definition).
                                                                 Points to where the output data will be written by the ZIP coprocessor for this
                                                                 invocation. */
#else /* Word 8 - Little Endian */
        uint64_t out_ptr_addr          : 64; /**< [575:512] Output pointer address  (ZIP_ZPTR_S format address word definition).
                                                                 Points to where the output data will be written by the ZIP coprocessor for this
                                                                 invocation. */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t out_ptr_ctl           : 64; /**< [639:576] Output pointer control (ZIP_ZPTR_S format control word definition).
                                                                 [DS] set if scatter. */
#else /* Word 9 - Little Endian */
        uint64_t out_ptr_ctl           : 64; /**< [639:576] Output pointer control (ZIP_ZPTR_S format control word definition).
                                                                 [DS] set if scatter. */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t res_ptr_addr          : 64; /**< [703:640] Result pointer address (ZIP_ZPTR_S format address word definition).
                                                                 Address is 8-byte aligned. */
#else /* Word 10 - Little Endian */
        uint64_t res_ptr_addr          : 64; /**< [703:640] Result pointer address (ZIP_ZPTR_S format address word definition).
                                                                 Address is 8-byte aligned. */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t res_ptr_ctl           : 64; /**< [767:704] Result pointer control (ZIP_ZPTR_S format control word definition).

                                                                 Inside this ZIP_ZPTR_S:
                                                                   * ZIP_ZPTR_S[FW] can be either 0 or 1.
                                                                   * ZIP_ZPTR_S[NC] can be either 0 or 1.
                                                                   * ZIP_ZPTR_S[DATA_BE] must be 0.
                                                                   * ZIP_ZPTR_S[LENGTH] must be 0. (24-bytes is implied).
                                                                   * ZIP_ZPTR_S[ADDR] must be eight-byte aligned. */
#else /* Word 11 - Little Endian */
        uint64_t res_ptr_ctl           : 64; /**< [767:704] Result pointer control (ZIP_ZPTR_S format control word definition).

                                                                 Inside this ZIP_ZPTR_S:
                                                                   * ZIP_ZPTR_S[FW] can be either 0 or 1.
                                                                   * ZIP_ZPTR_S[NC] can be either 0 or 1.
                                                                   * ZIP_ZPTR_S[DATA_BE] must be 0.
                                                                   * ZIP_ZPTR_S[LENGTH] must be 0. (24-bytes is implied).
                                                                   * ZIP_ZPTR_S[ADDR] must be eight-byte aligned. */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t reserved_812_831      : 20;
        uint64_t ggrp                  : 10; /**< [811:802] Reserved. For CN83XX: If [WQ_PTR] is non-zero, the SSO guest-group to use when
                                                                 ZIP submits work to SSO. */
        uint64_t tt                    : 2;  /**< [801:800] Reserved. For CN83XX: If [WQ_PTR] is non-zero, the SSO tag type to use when ZIP
                                                                 submits work to SSO. */
        uint64_t tag                   : 32; /**< [799:768] Reserved. For CN83XX: If [WQ_PTR] is non-zero, the SSO tag to use when ZIP
                                                                 submits work to SSO. */
#else /* Word 12 - Little Endian */
        uint64_t tag                   : 32; /**< [799:768] Reserved. For CN83XX: If [WQ_PTR] is non-zero, the SSO tag to use when ZIP
                                                                 submits work to SSO. */
        uint64_t tt                    : 2;  /**< [801:800] Reserved. For CN83XX: If [WQ_PTR] is non-zero, the SSO tag type to use when ZIP
                                                                 submits work to SSO. */
        uint64_t ggrp                  : 10; /**< [811:802] Reserved. For CN83XX: If [WQ_PTR] is non-zero, the SSO guest-group to use when
                                                                 ZIP submits work to SSO. */
        uint64_t reserved_812_831      : 20;
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t reserved_881_895      : 15;
        uint64_t wq_ptr                : 49; /**< [880:832] Reserved. For CN83XX: If WQ_PTR is non-zero, it is a pointer to a work-queue
                                                                 entry IOVA that ZIP submits work to SSO after all context, output data, and result
                                                                 write operations are visible to other CNXXXX units and the cores. */
#else /* Word 13 - Little Endian */
        uint64_t wq_ptr                : 49; /**< [880:832] Reserved. For CN83XX: If WQ_PTR is non-zero, it is a pointer to a work-queue
                                                                 entry IOVA that ZIP submits work to SSO after all context, output data, and result
                                                                 write operations are visible to other CNXXXX units and the cores. */
        uint64_t reserved_881_895      : 15;
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
    } cn88xx;
    struct bdk_zip_inst_s_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t doneint               : 1;  /**< [ 63: 63] Done Interrupt. When DONEINT is set and the instruction completes,
                                                                 ZIP_QUE(0..7)_DONE[DONE] will be incremented. */
        uint64_t reserved_56_62        : 7;
        uint64_t totaloutputlength     : 24; /**< [ 55: 32] Indicates the maximum number of output-stream bytes that can be written.
                                                                 TOTALOUTPUTLENGTH must exactly match the number of bytes indicated by
                                                                 the output pointer (either by ZPTR[LENGTH] directly if
                                                                 [DS] = 0, or indirectly if [DS] = 1). */
        uint64_t reserved_27_31        : 5;
        uint64_t exn                   : 3;  /**< [ 26: 24] EXN is the number of bits produced beyond the last output byte written by
                                                                 the prior ZIP coprocessor invocation. */
        uint64_t reserved_23           : 1;
        uint64_t exbits                : 7;  /**< [ 22: 16] EXN,EXBITS are the previously-generated compressed bits beyond the last
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
        uint64_t reserved_15           : 1;
        uint64_t halg                  : 3;  /**< [ 14: 12] Hash algorithm and enable. Enumerated by ZIP_HASH_ALG_E. */
        uint64_t sf                    : 1;  /**< [ 11: 11] SYNC_FLUSH. When set, enables SYNC_FLUSH functionality.

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
        uint64_t ss                    : 2;  /**< [ 10:  9] Compression speed/storage.
                                                                 Forces the ZIP compression engine to compress faster, at the expense of the compression
                                                                 ratio.

                                                                 For compression:
                                                                 0x0 = best quality, slowest speed.
                                                                 0x2 = lower quality, faster speed.
                                                                 0x1 = medium quality, medium speed.
                                                                 0x3 = lowest quality, best speed.

                                                                 For decompression, SS must be 0x0. */
        uint64_t cc                    : 2;  /**< [  8:  7] Compression coding.

                                                                 For compression:
                                                                 0x0 = hardware selects the better of fixed or dynamic Huffman encoding.
                                                                 0x1 = force dynamic Huffman encoding.
                                                                 0x2 = force fixed Huffman encoding.
                                                                 0x3 = force LZS encoding.

                                                                 For DEFLATE decompression, CC must be 0x0. For LZS decompression, CC must be 0x3. */
        uint64_t ef                    : 1;  /**< [  6:  6] End of input data. Set when the end of the input-data stream ends a file.

                                                                 For compression, if EF = 1, the ZIP engine always marks the last output block to be
                                                                 final. (The extra bits are zero-extended and written out as an output-stream byte.)

                                                                 For decompression, it is an error if EF = 1 and the ZIP coprocessor does not complete
                                                                 decompression of all blocks before it exhausts the input compressed data stream
                                                                 (ZIP_ZRES_S[COMPCODE] = ZIP_COMP_E::ITRUNC in this case.). It is not an error if EF = 0
                                                                 when the ZIP coprocessor completes decompression of all blocks in the file. */
        uint64_t bf                    : 1;  /**< [  5:  5] Beginning of file. Set when the beginning of the (non-history) input stream starts a
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
        uint64_t op                    : 2;  /**< [  4:  3] Compression/decompression operation. Enumerated by ZIP_OP_E. */
        uint64_t ds                    : 1;  /**< [  2:  2] Data scatter:
                                                                 1 = IWORD8/9 (the output pointer) points to a list of scatter pointers that are read
                                                                 by the coprocessor before writing the actual output data.
                                                                 0 = IWORD8/9 points directly at the locations to write the output data.

                                                                 If DS = 1, the IWORD9 LENGTH field, indicating the number of pointers in the
                                                                 output scatter list, must be at least 0x2. */
        uint64_t dg                    : 1;  /**< [  1:  1] Data gather:
                                                                 1 = IWORD6/7 (the input and compression history pointer) points to a gather list of
                                                                 pointers that are read by the coprocessor before reading the actual history/input data.
                                                                 0 = IWORD6/7 points directly at the actual history/input data.

                                                                 If DG = 1, the IWORD7 LENGTH field, indicating the number of pointers in the
                                                                 input and compression history gather list, must be at least 0x2. */
        uint64_t hg                    : 1;  /**< [  0:  0] History gather:
                                                                 1 = IWORD4/5 (the decompression history pointer) points to a gather list of
                                                                 pointers that are read by the coprocessor before reading the actual history data.
                                                                 0 = IWORD4/5 points directly at the actual history data.
                                                                 HG must be zero for a compression operation.

                                                                 If HG = 1, history data must be present for the decompression operation, and the
                                                                 IWORD5 LENGTH field, indicating the number of pointers in the decompression
                                                                 history gather list, must be at least 0x2. */
#else /* Word 0 - Little Endian */
        uint64_t hg                    : 1;  /**< [  0:  0] History gather:
                                                                 1 = IWORD4/5 (the decompression history pointer) points to a gather list of
                                                                 pointers that are read by the coprocessor before reading the actual history data.
                                                                 0 = IWORD4/5 points directly at the actual history data.
                                                                 HG must be zero for a compression operation.

                                                                 If HG = 1, history data must be present for the decompression operation, and the
                                                                 IWORD5 LENGTH field, indicating the number of pointers in the decompression
                                                                 history gather list, must be at least 0x2. */
        uint64_t dg                    : 1;  /**< [  1:  1] Data gather:
                                                                 1 = IWORD6/7 (the input and compression history pointer) points to a gather list of
                                                                 pointers that are read by the coprocessor before reading the actual history/input data.
                                                                 0 = IWORD6/7 points directly at the actual history/input data.

                                                                 If DG = 1, the IWORD7 LENGTH field, indicating the number of pointers in the
                                                                 input and compression history gather list, must be at least 0x2. */
        uint64_t ds                    : 1;  /**< [  2:  2] Data scatter:
                                                                 1 = IWORD8/9 (the output pointer) points to a list of scatter pointers that are read
                                                                 by the coprocessor before writing the actual output data.
                                                                 0 = IWORD8/9 points directly at the locations to write the output data.

                                                                 If DS = 1, the IWORD9 LENGTH field, indicating the number of pointers in the
                                                                 output scatter list, must be at least 0x2. */
        uint64_t op                    : 2;  /**< [  4:  3] Compression/decompression operation. Enumerated by ZIP_OP_E. */
        uint64_t bf                    : 1;  /**< [  5:  5] Beginning of file. Set when the beginning of the (non-history) input stream starts a
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
        uint64_t ef                    : 1;  /**< [  6:  6] End of input data. Set when the end of the input-data stream ends a file.

                                                                 For compression, if EF = 1, the ZIP engine always marks the last output block to be
                                                                 final. (The extra bits are zero-extended and written out as an output-stream byte.)

                                                                 For decompression, it is an error if EF = 1 and the ZIP coprocessor does not complete
                                                                 decompression of all blocks before it exhausts the input compressed data stream
                                                                 (ZIP_ZRES_S[COMPCODE] = ZIP_COMP_E::ITRUNC in this case.). It is not an error if EF = 0
                                                                 when the ZIP coprocessor completes decompression of all blocks in the file. */
        uint64_t cc                    : 2;  /**< [  8:  7] Compression coding.

                                                                 For compression:
                                                                 0x0 = hardware selects the better of fixed or dynamic Huffman encoding.
                                                                 0x1 = force dynamic Huffman encoding.
                                                                 0x2 = force fixed Huffman encoding.
                                                                 0x3 = force LZS encoding.

                                                                 For DEFLATE decompression, CC must be 0x0. For LZS decompression, CC must be 0x3. */
        uint64_t ss                    : 2;  /**< [ 10:  9] Compression speed/storage.
                                                                 Forces the ZIP compression engine to compress faster, at the expense of the compression
                                                                 ratio.

                                                                 For compression:
                                                                 0x0 = best quality, slowest speed.
                                                                 0x2 = lower quality, faster speed.
                                                                 0x1 = medium quality, medium speed.
                                                                 0x3 = lowest quality, best speed.

                                                                 For decompression, SS must be 0x0. */
        uint64_t sf                    : 1;  /**< [ 11: 11] SYNC_FLUSH. When set, enables SYNC_FLUSH functionality.

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
        uint64_t halg                  : 3;  /**< [ 14: 12] Hash algorithm and enable. Enumerated by ZIP_HASH_ALG_E. */
        uint64_t reserved_15           : 1;
        uint64_t exbits                : 7;  /**< [ 22: 16] EXN,EXBITS are the previously-generated compressed bits beyond the last
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
        uint64_t reserved_23           : 1;
        uint64_t exn                   : 3;  /**< [ 26: 24] EXN is the number of bits produced beyond the last output byte written by
                                                                 the prior ZIP coprocessor invocation. */
        uint64_t reserved_27_31        : 5;
        uint64_t totaloutputlength     : 24; /**< [ 55: 32] Indicates the maximum number of output-stream bytes that can be written.
                                                                 TOTALOUTPUTLENGTH must exactly match the number of bytes indicated by
                                                                 the output pointer (either by ZPTR[LENGTH] directly if
                                                                 [DS] = 0, or indirectly if [DS] = 1). */
        uint64_t reserved_56_62        : 7;
        uint64_t doneint               : 1;  /**< [ 63: 63] Done Interrupt. When DONEINT is set and the instruction completes,
                                                                 ZIP_QUE(0..7)_DONE[DONE] will be incremented. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t historylength         : 16; /**< [127:112] With compression, history bytes can be prepended in the input data stream
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
        uint64_t reserved_96_111       : 16;
        uint64_t adlercrc32            : 32; /**< [ 95: 64] This 32-bit field represents the current state of the ADLER32 or CRC32 units. The
                                                                 hardware executes both ADLER32 and CRC32 on the processed uncompressed data
                                                                 bytes using this value as the current checksum. Though the hardware outputs both
                                                                 the ADLER32 and CRC32 results, ADLERCRC32 is the only checksum input, so only
                                                                 one of the two outputs is likely to be useful.

                                                                 The ADLER32 algorithm is defined in RFC1950.

                                                                 CRC32 is defined in ITU-T X.244, Annex D, pp. 144-145 / ISO 8073. */
#else /* Word 1 - Little Endian */
        uint64_t adlercrc32            : 32; /**< [ 95: 64] This 32-bit field represents the current state of the ADLER32 or CRC32 units. The
                                                                 hardware executes both ADLER32 and CRC32 on the processed uncompressed data
                                                                 bytes using this value as the current checksum. Though the hardware outputs both
                                                                 the ADLER32 and CRC32 results, ADLERCRC32 is the only checksum input, so only
                                                                 one of the two outputs is likely to be useful.

                                                                 The ADLER32 algorithm is defined in RFC1950.

                                                                 CRC32 is defined in ITU-T X.244, Annex D, pp. 144-145 / ISO 8073. */
        uint64_t reserved_96_111       : 16;
        uint64_t historylength         : 16; /**< [127:112] With compression, history bytes can be prepended in the input data stream
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
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t ctx_ptr_addr          : 64; /**< [191:128] Decompresion context pointer address (ZIP_ZPTR_S format address word definition).
                                                                 The address must be 8-byte aligned. */
#else /* Word 2 - Little Endian */
        uint64_t ctx_ptr_addr          : 64; /**< [191:128] Decompresion context pointer address (ZIP_ZPTR_S format address word definition).
                                                                 The address must be 8-byte aligned. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t ctx_ptr_ctl           : 64; /**< [255:192] Decompresion context pointer control (ZIP_ZPTR_S format control word definition).
                                                                 DATA_BE = 0 and LENGTH=0 (2048 bytes implied). */
#else /* Word 3 - Little Endian */
        uint64_t ctx_ptr_ctl           : 64; /**< [255:192] Decompresion context pointer control (ZIP_ZPTR_S format control word definition).
                                                                 DATA_BE = 0 and LENGTH=0 (2048 bytes implied). */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t his_ptr_addr          : 64; /**< [319:256] Decompresion history pointer address (ZIP_ZPTR_S format address word definition). */
#else /* Word 4 - Little Endian */
        uint64_t his_ptr_addr          : 64; /**< [319:256] Decompresion history pointer address (ZIP_ZPTR_S format address word definition). */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t his_ptr_ctl           : 64; /**< [383:320] Decompresion history pointer control (ZIP_ZPTR_S format control word definition).
                                                                 FW = 0. ZIP_INST_S[HG] set if gather. */
#else /* Word 5 - Little Endian */
        uint64_t his_ptr_ctl           : 64; /**< [383:320] Decompresion history pointer control (ZIP_ZPTR_S format control word definition).
                                                                 FW = 0. ZIP_INST_S[HG] set if gather. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t inp_ptr_addr          : 64; /**< [447:384] Input and compresion history pointer address (ZIP_ZPTR_S format address word definition). */
#else /* Word 6 - Little Endian */
        uint64_t inp_ptr_addr          : 64; /**< [447:384] Input and compresion history pointer address (ZIP_ZPTR_S format address word definition). */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t inp_ptr_ctl           : 64; /**< [511:448] Input and compresion history pointer control (ZIP_ZPTR_S format control word definition).
                                                                 FW = 0. ZIP_INST_S[DG] set if gather. */
#else /* Word 7 - Little Endian */
        uint64_t inp_ptr_ctl           : 64; /**< [511:448] Input and compresion history pointer control (ZIP_ZPTR_S format control word definition).
                                                                 FW = 0. ZIP_INST_S[DG] set if gather. */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t out_ptr_addr          : 64; /**< [575:512] Output pointer address  (ZIP_ZPTR_S format address word definition).
                                                                 Points to where the output data will be written by the ZIP coprocessor for this
                                                                 invocation. */
#else /* Word 8 - Little Endian */
        uint64_t out_ptr_addr          : 64; /**< [575:512] Output pointer address  (ZIP_ZPTR_S format address word definition).
                                                                 Points to where the output data will be written by the ZIP coprocessor for this
                                                                 invocation. */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t out_ptr_ctl           : 64; /**< [639:576] Output pointer control (ZIP_ZPTR_S format control word definition).
                                                                 [DS] set if scatter. */
#else /* Word 9 - Little Endian */
        uint64_t out_ptr_ctl           : 64; /**< [639:576] Output pointer control (ZIP_ZPTR_S format control word definition).
                                                                 [DS] set if scatter. */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t res_ptr_addr          : 64; /**< [703:640] Result pointer address (ZIP_ZPTR_S format address word definition).
                                                                 Address is 8-byte aligned. */
#else /* Word 10 - Little Endian */
        uint64_t res_ptr_addr          : 64; /**< [703:640] Result pointer address (ZIP_ZPTR_S format address word definition).
                                                                 Address is 8-byte aligned. */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t res_ptr_ctl           : 64; /**< [767:704] Result pointer control (ZIP_ZPTR_S format control word definition).

                                                                 Inside this ZIP_ZPTR_S:
                                                                   * ZIP_ZPTR_S[FW] can be either 0 or 1.
                                                                   * ZIP_ZPTR_S[NC] can be either 0 or 1.
                                                                   * ZIP_ZPTR_S[DATA_BE] must be 0.
                                                                   * ZIP_ZPTR_S[LENGTH] must be 0. (24-bytes is implied).
                                                                   * ZIP_ZPTR_S[ADDR] must be eight-byte aligned. */
#else /* Word 11 - Little Endian */
        uint64_t res_ptr_ctl           : 64; /**< [767:704] Result pointer control (ZIP_ZPTR_S format control word definition).

                                                                 Inside this ZIP_ZPTR_S:
                                                                   * ZIP_ZPTR_S[FW] can be either 0 or 1.
                                                                   * ZIP_ZPTR_S[NC] can be either 0 or 1.
                                                                   * ZIP_ZPTR_S[DATA_BE] must be 0.
                                                                   * ZIP_ZPTR_S[LENGTH] must be 0. (24-bytes is implied).
                                                                   * ZIP_ZPTR_S[ADDR] must be eight-byte aligned. */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t reserved_812_831      : 20;
        uint64_t ggrp                  : 10; /**< [811:802] If [WQ_PTR] is non-zero, the SSO guest-group to use when ZIP submits work to
                                                                 SSO. */
        uint64_t tt                    : 2;  /**< [801:800] If [WQ_PTR] is non-zero, the SSO tag type to use when ZIP submits work to SSO. */
        uint64_t tag                   : 32; /**< [799:768] If [WQ_PTR] is non-zero, the SSO tag to use when ZIP submits work to SSO. */
#else /* Word 12 - Little Endian */
        uint64_t tag                   : 32; /**< [799:768] If [WQ_PTR] is non-zero, the SSO tag to use when ZIP submits work to SSO. */
        uint64_t tt                    : 2;  /**< [801:800] If [WQ_PTR] is non-zero, the SSO tag type to use when ZIP submits work to SSO. */
        uint64_t ggrp                  : 10; /**< [811:802] If [WQ_PTR] is non-zero, the SSO guest-group to use when ZIP submits work to
                                                                 SSO. */
        uint64_t reserved_812_831      : 20;
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t reserved_881_895      : 15;
        uint64_t wq_ptr                : 49; /**< [880:832] If WQ_PTR is non-zero, it is a pointer to a work-queue entry that ZIP submits
                                                                 work to SSO after all context, output data, and result write operations are
                                                                 visible to other CNXXXX units and the cores. */
#else /* Word 13 - Little Endian */
        uint64_t wq_ptr                : 49; /**< [880:832] If WQ_PTR is non-zero, it is a pointer to a work-queue entry that ZIP submits
                                                                 work to SSO after all context, output data, and result write operations are
                                                                 visible to other CNXXXX units and the cores. */
        uint64_t reserved_881_895      : 15;
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t reserved_896_959      : 64;
#else /* Word 14 - Little Endian */
        uint64_t reserved_896_959      : 64;
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t reserved_1009_1023    : 15;
        uint64_t iv_ptr                : 49; /**< [1008:960] Hash initial value pointer.

                                                                 If ZIP_INST_S[HALG] = 0x0 (NONE), must be 0x0.

                                                                 If ZIP_INST_S[HALG] = ZIP_HASH_ALG_E::SHA1/SHA256, and [IV_PTR] != 0x0, points
                                                                 to the address ZIP will read 32 bytes from to obtain the initial hash value.

                                                                 If ZIP_INST_S[HALG] = ZIP_HASH_ALG_E::SHA1/SHA256, and [IV_PTR] = 0x0, the
                                                                 initial hash value is the standard value enumerated by ZIP_HASH_ALG_E. */
#else /* Word 15 - Little Endian */
        uint64_t iv_ptr                : 49; /**< [1008:960] Hash initial value pointer.

                                                                 If ZIP_INST_S[HALG] = 0x0 (NONE), must be 0x0.

                                                                 If ZIP_INST_S[HALG] = ZIP_HASH_ALG_E::SHA1/SHA256, and [IV_PTR] != 0x0, points
                                                                 to the address ZIP will read 32 bytes from to obtain the initial hash value.

                                                                 If ZIP_INST_S[HALG] = ZIP_HASH_ALG_E::SHA1/SHA256, and [IV_PTR] = 0x0, the
                                                                 initial hash value is the standard value enumerated by ZIP_HASH_ALG_E. */
        uint64_t reserved_1009_1023    : 15;
#endif /* Word 15 - End */
    } cn83xx;
};

/**
 * Structure zip_nptr_s
 *
 * ZIP Instruction Next-Chunk-Buffer Pointer (NPTR) Structure
 * ZIP_NPTR structure is used to chain all the ZIP instruction buffers together. ZIP instruction
 * buffers are managed (allocated and released) by software.
 */
union bdk_zip_nptr_s
{
    uint64_t u;
    struct bdk_zip_nptr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 49; /**< [ 48:  0] Pointer to next instruction's IOVA.
                                                                 ZIP_ZPTR_S[ADDR]<6:0> must be zero. All the ZIP instruction buffers must be aligned on an
                                                                 128 byte boundary. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 49; /**< [ 48:  0] Pointer to next instruction's IOVA.
                                                                 ZIP_ZPTR_S[ADDR]<6:0> must be zero. All the ZIP instruction buffers must be aligned on an
                                                                 128 byte boundary. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_nptr_s_s cn; */
};

/**
 * Structure zip_zptr_s
 *
 * ZIP Generic Pointer Structure
 * This structure is the generic format of pointers in ZIP_INST_S.
 */
union bdk_zip_zptr_s
{
    uint64_t u[2];
    struct bdk_zip_zptr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 49; /**< [ 48:  0] When a ZIP_ZPTR_S is in an instruction word, [ADDR] is either:
                                                                 * (a) A direct IOVA byte pointer into L2C/DDR attached memory, or
                                                                 * (b) An IOVA pointer to a gather/scatter list in memory.

                                                                 When a ZIP_ZPTR_S is in a gather/scatter list, [ADDR] is:
                                                                 * (c) An IOVA direct byte pointer into the attached memory.

                                                                 In case (b) above, and for context and result pointers, [ADDR]<3:0> must be
                                                                 zero. (All these cases must be aligned on an 16 byte boundary.)

                                                                 In cases (a) or (c) above, [ADDR] may be any byte alignment (except for context
                                                                 and result pointers). */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 49; /**< [ 48:  0] When a ZIP_ZPTR_S is in an instruction word, [ADDR] is either:
                                                                 * (a) A direct IOVA byte pointer into L2C/DDR attached memory, or
                                                                 * (b) An IOVA pointer to a gather/scatter list in memory.

                                                                 When a ZIP_ZPTR_S is in a gather/scatter list, [ADDR] is:
                                                                 * (c) An IOVA direct byte pointer into the attached memory.

                                                                 In case (b) above, and for context and result pointers, [ADDR]<3:0> must be
                                                                 zero. (All these cases must be aligned on an 16 byte boundary.)

                                                                 In cases (a) or (c) above, [ADDR] may be any byte alignment (except for context
                                                                 and result pointers). */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_112_127      : 16;
        uint64_t length                : 16; /**< [111: 96] In case (a) and (c) under [ADDR], [LENGTH] is the number of bytes pointed at by [ADDR].
                                                                 [LENGTH] must be nonzero in this case.
                                                                 In case (b) under [ADDR], [LENGTH] is the number of gather/ scatter list pointer entries
                                                                 pointed at by ADDR. ([LENGTH]*16 is the number of bytes.) [LENGTH] must be at least 2 in
                                                                 this case.
                                                                 [LENGTH] must be zero for context and result pointers, because each has an implied fixed-
                                                                 size length (of ZIP_CONSTANTS[CTXSIZE] or fewer bytes and 24 bytes, respectively). */
        uint64_t reserved_67_95        : 29;
        uint64_t fw                    : 1;  /**< [ 66: 66] Full-block write. [FW] may be set in any case (a) or (c) where stores to [ADDR] can be
                                                                 generated to indicate that the hardware may write random values into all bytes of all
                                                                 cache blocks touched by the range [ADDR] ... [ADDR]+[LENGTH]-1.
                                                                 [FW] must not be set in case (b) above, or whenever stores to [ADDR] cannot possibly be
                                                                 generated. */
        uint64_t nc                    : 1;  /**< [ 65: 65] No cache allocation. [NC] may be set in any case to indicate that the read/write
                                                                 operations generated should preferably not load cache blocks into the L2 cache.
                                                                 Note that in case (b) above, [NC] indicates that the gather/scatter list should not be
                                                                 loaded into the cache. In cases (a) and (c) above, [NC] indicates that the data or results
                                                                 should not be loaded into the L2 cache.
                                                                 Note that the ZIP hardware will ignore [NC] for write operations when full cache blocks
                                                                 cannot be written. */
        uint64_t data_be               : 1;  /**< [ 64: 64] Big-endian. [DATA_BE] may be set in case (a) or (c) above, indicating that [ADDR]
                                                                 and the byte stream indicated by it is in big endian format.
                                                                 [DATA_BE] must never be set in case (b) above, and must never be set for context or result
                                                                 pointers. */
#else /* Word 1 - Little Endian */
        uint64_t data_be               : 1;  /**< [ 64: 64] Big-endian. [DATA_BE] may be set in case (a) or (c) above, indicating that [ADDR]
                                                                 and the byte stream indicated by it is in big endian format.
                                                                 [DATA_BE] must never be set in case (b) above, and must never be set for context or result
                                                                 pointers. */
        uint64_t nc                    : 1;  /**< [ 65: 65] No cache allocation. [NC] may be set in any case to indicate that the read/write
                                                                 operations generated should preferably not load cache blocks into the L2 cache.
                                                                 Note that in case (b) above, [NC] indicates that the gather/scatter list should not be
                                                                 loaded into the cache. In cases (a) and (c) above, [NC] indicates that the data or results
                                                                 should not be loaded into the L2 cache.
                                                                 Note that the ZIP hardware will ignore [NC] for write operations when full cache blocks
                                                                 cannot be written. */
        uint64_t fw                    : 1;  /**< [ 66: 66] Full-block write. [FW] may be set in any case (a) or (c) where stores to [ADDR] can be
                                                                 generated to indicate that the hardware may write random values into all bytes of all
                                                                 cache blocks touched by the range [ADDR] ... [ADDR]+[LENGTH]-1.
                                                                 [FW] must not be set in case (b) above, or whenever stores to [ADDR] cannot possibly be
                                                                 generated. */
        uint64_t reserved_67_95        : 29;
        uint64_t length                : 16; /**< [111: 96] In case (a) and (c) under [ADDR], [LENGTH] is the number of bytes pointed at by [ADDR].
                                                                 [LENGTH] must be nonzero in this case.
                                                                 In case (b) under [ADDR], [LENGTH] is the number of gather/ scatter list pointer entries
                                                                 pointed at by ADDR. ([LENGTH]*16 is the number of bytes.) [LENGTH] must be at least 2 in
                                                                 this case.
                                                                 [LENGTH] must be zero for context and result pointers, because each has an implied fixed-
                                                                 size length (of ZIP_CONSTANTS[CTXSIZE] or fewer bytes and 24 bytes, respectively). */
        uint64_t reserved_112_127      : 16;
#endif /* Word 1 - End */
    } s;
    /* struct bdk_zip_zptr_s_s cn; */
};

/**
 * Structure zip_zres_s
 *
 * ZIP Result Structure
 * The ZIP coprocessor writes the result structure after it completes the invocation.
 * The result structure is exactly 24 bytes, and each invocation of the ZIP coprocessor
 * produces exactly one result structure.
 */
union bdk_zip_zres_s
{
    uint64_t u[8];
    struct bdk_zip_zres_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t crc32                 : 32; /**< [ 63: 32] The CRC32 result corresponding to the bytes processed in the uncompressed stream,
                                                                 seeded with ZIP_INST_S[ADLERCRC32].

                                                                 For an error-free compression, [TOTALBYTESREAD] indicates the
                                                                 number of non-history bytes from the input stream that contributed to the hardware
                                                                 CRC32 calculation. CRC32 is valid for all error-free compression invocations,
                                                                 whether at the beginning, middle, or end of file.

                                                                 For decompression, CRC32 is valid only for error-free invocations that find the end of
                                                                 file (i.e. that have [EF] = 1), where it indicates the ADLER/CRC32 result
                                                                 for the file */
        uint64_t adler32               : 32; /**< [ 31:  0] The ADLER32 result corresponding to the bytes processed in the uncompressed
                                                                 stream, starting with the checksum ZIP_INST_S[ADLERCRC32].

                                                                 For an error-free compression, [TOTALBYTESREAD] indicates the
                                                                 number of non-history bytes from the input stream that contributed to the hardware
                                                                 ADLER32 calculation. ADLER32 is valid for all error-free compression invocations,
                                                                 whether at the beginning, middle, or end of file.

                                                                 For decompression, ADLER32 is valid only for error-free invocations that find the
                                                                 end of file (i.e. that have [EF] = 1), where it indicates the ADLER/CRC32
                                                                 result for the file. */
#else /* Word 0 - Little Endian */
        uint64_t adler32               : 32; /**< [ 31:  0] The ADLER32 result corresponding to the bytes processed in the uncompressed
                                                                 stream, starting with the checksum ZIP_INST_S[ADLERCRC32].

                                                                 For an error-free compression, [TOTALBYTESREAD] indicates the
                                                                 number of non-history bytes from the input stream that contributed to the hardware
                                                                 ADLER32 calculation. ADLER32 is valid for all error-free compression invocations,
                                                                 whether at the beginning, middle, or end of file.

                                                                 For decompression, ADLER32 is valid only for error-free invocations that find the
                                                                 end of file (i.e. that have [EF] = 1), where it indicates the ADLER/CRC32
                                                                 result for the file. */
        uint64_t crc32                 : 32; /**< [ 63: 32] The CRC32 result corresponding to the bytes processed in the uncompressed stream,
                                                                 seeded with ZIP_INST_S[ADLERCRC32].

                                                                 For an error-free compression, [TOTALBYTESREAD] indicates the
                                                                 number of non-history bytes from the input stream that contributed to the hardware
                                                                 CRC32 calculation. CRC32 is valid for all error-free compression invocations,
                                                                 whether at the beginning, middle, or end of file.

                                                                 For decompression, CRC32 is valid only for error-free invocations that find the end of
                                                                 file (i.e. that have [EF] = 1), where it indicates the ADLER/CRC32 result
                                                                 for the file */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t totalbyteswritten     : 32; /**< [127: 96] The total number of bytes produced in the output stream during this coprocessor
                                                                 invocation. TOTALBYTESWRITTEN <= ZIP_INST_S[TOTALOUTPUTLENGTH] in all error-free cases

                                                                 For an error-free compression, TOTALBYTESWRITTEN is the number of
                                                                 compressed output bytes that were written during the compression. This includes
                                                                 any valid [EXN],[EXBITS] when [EF] = 1, and excludes
                                                                 any valid [EXN],[EXBITS] when [EF] = 0.

                                                                 For an error-free decompression, TOTALBYTESWRITTEN is the number of uncompressed
                                                                 output bytes produced by the operation */
        uint64_t totalbytesread        : 32; /**< [ 95: 64] The total number of bytes processed from the input stream during this coprocessor
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
#else /* Word 1 - Little Endian */
        uint64_t totalbytesread        : 32; /**< [ 95: 64] The total number of bytes processed from the input stream during this coprocessor
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
        uint64_t totalbyteswritten     : 32; /**< [127: 96] The total number of bytes produced in the output stream during this coprocessor
                                                                 invocation. TOTALBYTESWRITTEN <= ZIP_INST_S[TOTALOUTPUTLENGTH] in all error-free cases

                                                                 For an error-free compression, TOTALBYTESWRITTEN is the number of
                                                                 compressed output bytes that were written during the compression. This includes
                                                                 any valid [EXN],[EXBITS] when [EF] = 1, and excludes
                                                                 any valid [EXN],[EXBITS] when [EF] = 0.

                                                                 For an error-free decompression, TOTALBYTESWRITTEN is the number of uncompressed
                                                                 output bytes produced by the operation */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t totalbitsprocessed    : 32; /**< [191:160] When [EF] = 1 for an error-free decompression operation,
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
        uint64_t doneint               : 1;  /**< [159:159] Done Interrupt. This bit is copied from the corrresponding ZIP instruction ZIP_INST_S[DONEINT]. */
        uint64_t reserved_155_158      : 4;
        uint64_t exn                   : 3;  /**< [154:152] The number of bits produced beyond the last output byte written.
                                                                 See details in [EXBITS]. */
        uint64_t reserved_151          : 1;
        uint64_t exbits                : 7;  /**< [150:144] [EXN] and [EXBITS] are the compressed bits produced beyond the last compressed byte
                                                                 written. These bits are required context for partial-file processing as the ZIP
                                                                 compression algorithm produces a compressed bit stream, but the output stream of the
                                                                 operation is byte-based. [EXN], [EXBITS] are valid for any error-free compress when
                                                                 ZIP_INST_S[EF] = 0 and ZIP_INST_S[SF] = 0, and are not used and undefined in all other
                                                                 cases.

                                                                 EXBITS contains the extra bits. Bit <0> contains the first extra bit, <1> the
                                                                 second extra bit, etc.

                                                                 For decompression, [EXN] and [EXBITS] are not used and are undefined. */
        uint64_t reserved_137_143      : 7;
        uint64_t ef                    : 1;  /**< [136:136] End of file.

                                                                 For any error-free decompression, EF indicates whether the ZIP
                                                                 coprocessor completed decompression of all blocks in the file during this invocation. If
                                                                 EF = 1 for a decompression operation, the ZIP coprocessor must not be invoked again
                                                                 for further processing on this file.

                                                                 For compression, EF is not used and is undefined. */
        uint64_t compcode              : 8;  /**< [135:128] Indicates completion/error status of the ZIP coprocessor for this invocation,
                                                                 as enumerated by ZIP_COMP_E. Core
                                                                 software may write the memory location containing [COMPCODE] to 0x0
                                                                 before ringing the doorbell, and then poll for completion by checking for a non-zero
                                                                 value.

                                                                 Once the core observes a non-zero [COMPCODE] value in this case, the ZIP
                                                                 coprocessor will have also completed L2/DRAM write operations for all context,
                                                                 output stream, and result data. */
#else /* Word 2 - Little Endian */
        uint64_t compcode              : 8;  /**< [135:128] Indicates completion/error status of the ZIP coprocessor for this invocation,
                                                                 as enumerated by ZIP_COMP_E. Core
                                                                 software may write the memory location containing [COMPCODE] to 0x0
                                                                 before ringing the doorbell, and then poll for completion by checking for a non-zero
                                                                 value.

                                                                 Once the core observes a non-zero [COMPCODE] value in this case, the ZIP
                                                                 coprocessor will have also completed L2/DRAM write operations for all context,
                                                                 output stream, and result data. */
        uint64_t ef                    : 1;  /**< [136:136] End of file.

                                                                 For any error-free decompression, EF indicates whether the ZIP
                                                                 coprocessor completed decompression of all blocks in the file during this invocation. If
                                                                 EF = 1 for a decompression operation, the ZIP coprocessor must not be invoked again
                                                                 for further processing on this file.

                                                                 For compression, EF is not used and is undefined. */
        uint64_t reserved_137_143      : 7;
        uint64_t exbits                : 7;  /**< [150:144] [EXN] and [EXBITS] are the compressed bits produced beyond the last compressed byte
                                                                 written. These bits are required context for partial-file processing as the ZIP
                                                                 compression algorithm produces a compressed bit stream, but the output stream of the
                                                                 operation is byte-based. [EXN], [EXBITS] are valid for any error-free compress when
                                                                 ZIP_INST_S[EF] = 0 and ZIP_INST_S[SF] = 0, and are not used and undefined in all other
                                                                 cases.

                                                                 EXBITS contains the extra bits. Bit <0> contains the first extra bit, <1> the
                                                                 second extra bit, etc.

                                                                 For decompression, [EXN] and [EXBITS] are not used and are undefined. */
        uint64_t reserved_151          : 1;
        uint64_t exn                   : 3;  /**< [154:152] The number of bits produced beyond the last output byte written.
                                                                 See details in [EXBITS]. */
        uint64_t reserved_155_158      : 4;
        uint64_t doneint               : 1;  /**< [159:159] Done Interrupt. This bit is copied from the corrresponding ZIP instruction ZIP_INST_S[DONEINT]. */
        uint64_t totalbitsprocessed    : 32; /**< [191:160] When [EF] = 1 for an error-free decompression operation,
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
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_192_255      : 64;
#else /* Word 3 - Little Endian */
        uint64_t reserved_192_255      : 64;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t hash0                 : 64; /**< [319:256] Word 0 of computed hash. This word is only written when ZIP_INST_S[HALG] !=
                                                                 ZIP_OP_E::NONE. */
#else /* Word 4 - Little Endian */
        uint64_t hash0                 : 64; /**< [319:256] Word 0 of computed hash. This word is only written when ZIP_INST_S[HALG] !=
                                                                 ZIP_OP_E::NONE. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t hash1                 : 64; /**< [383:320] Word 1 of computed hash. Note this word is only written when ZIP_INST_S[HALG] !=
                                                                 ZIP_OP_E::NONE. */
#else /* Word 5 - Little Endian */
        uint64_t hash1                 : 64; /**< [383:320] Word 1 of computed hash. Note this word is only written when ZIP_INST_S[HALG] !=
                                                                 ZIP_OP_E::NONE. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t hash2                 : 64; /**< [447:384] Word 1 of computed hash. Note this word is only written when ZIP_INST_S[HALG] !=
                                                                 ZIP_OP_E::NONE. */
#else /* Word 6 - Little Endian */
        uint64_t hash2                 : 64; /**< [447:384] Word 1 of computed hash. Note this word is only written when ZIP_INST_S[HALG] !=
                                                                 ZIP_OP_E::NONE. */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t hash3                 : 64; /**< [511:448] Word 1 of computed hash. Note this word is only written when ZIP_INST_S[HALG] !=
                                                                 ZIP_OP_E::NONE. */
#else /* Word 7 - Little Endian */
        uint64_t hash3                 : 64; /**< [511:448] Word 1 of computed hash. Note this word is only written when ZIP_INST_S[HALG] !=
                                                                 ZIP_OP_E::NONE. */
#endif /* Word 7 - End */
    } s;
    struct bdk_zip_zres_s_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t crc32                 : 32; /**< [ 63: 32] The CRC32 result corresponding to the bytes processed in the uncompressed stream,
                                                                 seeded with ZIP_INST_S[ADLERCRC32].

                                                                 For an error-free compression, [TOTALBYTESREAD] indicates the
                                                                 number of non-history bytes from the input stream that contributed to the hardware
                                                                 CRC32 calculation. CRC32 is valid for all error-free compression invocations,
                                                                 whether at the beginning, middle, or end of file.

                                                                 For decompression, CRC32 is valid only for error-free invocations that find the end of
                                                                 file (i.e. that have [EF] = 1), where it indicates the ADLER/CRC32 result
                                                                 for the file */
        uint64_t adler32               : 32; /**< [ 31:  0] The ADLER32 result corresponding to the bytes processed in the uncompressed
                                                                 stream, starting with the checksum ZIP_INST_S[ADLERCRC32].

                                                                 For an error-free compression, [TOTALBYTESREAD] indicates the
                                                                 number of non-history bytes from the input stream that contributed to the hardware
                                                                 ADLER32 calculation. ADLER32 is valid for all error-free compression invocations,
                                                                 whether at the beginning, middle, or end of file.

                                                                 For decompression, ADLER32 is valid only for error-free invocations that find the
                                                                 end of file (i.e. that have [EF] = 1), where it indicates the ADLER/CRC32
                                                                 result for the file. */
#else /* Word 0 - Little Endian */
        uint64_t adler32               : 32; /**< [ 31:  0] The ADLER32 result corresponding to the bytes processed in the uncompressed
                                                                 stream, starting with the checksum ZIP_INST_S[ADLERCRC32].

                                                                 For an error-free compression, [TOTALBYTESREAD] indicates the
                                                                 number of non-history bytes from the input stream that contributed to the hardware
                                                                 ADLER32 calculation. ADLER32 is valid for all error-free compression invocations,
                                                                 whether at the beginning, middle, or end of file.

                                                                 For decompression, ADLER32 is valid only for error-free invocations that find the
                                                                 end of file (i.e. that have [EF] = 1), where it indicates the ADLER/CRC32
                                                                 result for the file. */
        uint64_t crc32                 : 32; /**< [ 63: 32] The CRC32 result corresponding to the bytes processed in the uncompressed stream,
                                                                 seeded with ZIP_INST_S[ADLERCRC32].

                                                                 For an error-free compression, [TOTALBYTESREAD] indicates the
                                                                 number of non-history bytes from the input stream that contributed to the hardware
                                                                 CRC32 calculation. CRC32 is valid for all error-free compression invocations,
                                                                 whether at the beginning, middle, or end of file.

                                                                 For decompression, CRC32 is valid only for error-free invocations that find the end of
                                                                 file (i.e. that have [EF] = 1), where it indicates the ADLER/CRC32 result
                                                                 for the file */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t totalbyteswritten     : 32; /**< [127: 96] The total number of bytes produced in the output stream during this coprocessor
                                                                 invocation. TOTALBYTESWRITTEN <= ZIP_INST_S[TOTALOUTPUTLENGTH] in all error-free cases

                                                                 For an error-free compression, TOTALBYTESWRITTEN is the number of
                                                                 compressed output bytes that were written during the compression. This includes
                                                                 any valid [EXN],[EXBITS] when [EF] = 1, and excludes
                                                                 any valid [EXN],[EXBITS] when [EF] = 0.

                                                                 For an error-free decompression, TOTALBYTESWRITTEN is the number of uncompressed
                                                                 output bytes produced by the operation */
        uint64_t totalbytesread        : 32; /**< [ 95: 64] The total number of bytes processed from the input stream during this coprocessor
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
#else /* Word 1 - Little Endian */
        uint64_t totalbytesread        : 32; /**< [ 95: 64] The total number of bytes processed from the input stream during this coprocessor
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
        uint64_t totalbyteswritten     : 32; /**< [127: 96] The total number of bytes produced in the output stream during this coprocessor
                                                                 invocation. TOTALBYTESWRITTEN <= ZIP_INST_S[TOTALOUTPUTLENGTH] in all error-free cases

                                                                 For an error-free compression, TOTALBYTESWRITTEN is the number of
                                                                 compressed output bytes that were written during the compression. This includes
                                                                 any valid [EXN],[EXBITS] when [EF] = 1, and excludes
                                                                 any valid [EXN],[EXBITS] when [EF] = 0.

                                                                 For an error-free decompression, TOTALBYTESWRITTEN is the number of uncompressed
                                                                 output bytes produced by the operation */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t totalbitsprocessed    : 32; /**< [191:160] When [EF] = 1 for an error-free decompression operation,
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
        uint64_t doneint               : 1;  /**< [159:159] Done Interrupt. This bit is copied from the corrresponding ZIP instruction ZIP_INST_S[DONEINT]. */
        uint64_t reserved_155_158      : 4;
        uint64_t exn                   : 3;  /**< [154:152] The number of bits produced beyond the last output byte written.
                                                                 See details in [EXBITS]. */
        uint64_t reserved_151          : 1;
        uint64_t exbits                : 7;  /**< [150:144] [EXN] and [EXBITS] are the compressed bits produced beyond the last compressed byte
                                                                 written. These bits are required context for partial-file processing as the ZIP
                                                                 compression algorithm produces a compressed bit stream, but the output stream of the
                                                                 operation is byte-based. [EXN], [EXBITS] are valid for any error-free compress when
                                                                 ZIP_INST_S[EF] = 0 and ZIP_INST_S[SF] = 0, and are not used and undefined in all other
                                                                 cases.

                                                                 EXBITS contains the extra bits. Bit <0> contains the first extra bit, <1> the
                                                                 second extra bit, etc.

                                                                 For decompression, [EXN] and [EXBITS] are not used and are undefined. */
        uint64_t reserved_137_143      : 7;
        uint64_t ef                    : 1;  /**< [136:136] End of file.

                                                                 For any error-free decompression, EF indicates whether the ZIP
                                                                 coprocessor completed decompression of all blocks in the file during this invocation. If
                                                                 EF = 1 for a decompression operation, the ZIP coprocessor must not be invoked again
                                                                 for further processing on this file.

                                                                 For compression, EF is not used and is undefined. */
        uint64_t compcode              : 8;  /**< [135:128] Indicates completion/error status of the ZIP coprocessor for this invocation,
                                                                 as enumerated by ZIP_COMP_E. Core
                                                                 software may write the memory location containing [COMPCODE] to 0x0
                                                                 before ringing the doorbell, and then poll for completion by checking for a non-zero
                                                                 value.

                                                                 Once the core observes a non-zero [COMPCODE] value in this case, the ZIP
                                                                 coprocessor will have also completed L2/DRAM write operations for all context,
                                                                 output stream, and result data. */
#else /* Word 2 - Little Endian */
        uint64_t compcode              : 8;  /**< [135:128] Indicates completion/error status of the ZIP coprocessor for this invocation,
                                                                 as enumerated by ZIP_COMP_E. Core
                                                                 software may write the memory location containing [COMPCODE] to 0x0
                                                                 before ringing the doorbell, and then poll for completion by checking for a non-zero
                                                                 value.

                                                                 Once the core observes a non-zero [COMPCODE] value in this case, the ZIP
                                                                 coprocessor will have also completed L2/DRAM write operations for all context,
                                                                 output stream, and result data. */
        uint64_t ef                    : 1;  /**< [136:136] End of file.

                                                                 For any error-free decompression, EF indicates whether the ZIP
                                                                 coprocessor completed decompression of all blocks in the file during this invocation. If
                                                                 EF = 1 for a decompression operation, the ZIP coprocessor must not be invoked again
                                                                 for further processing on this file.

                                                                 For compression, EF is not used and is undefined. */
        uint64_t reserved_137_143      : 7;
        uint64_t exbits                : 7;  /**< [150:144] [EXN] and [EXBITS] are the compressed bits produced beyond the last compressed byte
                                                                 written. These bits are required context for partial-file processing as the ZIP
                                                                 compression algorithm produces a compressed bit stream, but the output stream of the
                                                                 operation is byte-based. [EXN], [EXBITS] are valid for any error-free compress when
                                                                 ZIP_INST_S[EF] = 0 and ZIP_INST_S[SF] = 0, and are not used and undefined in all other
                                                                 cases.

                                                                 EXBITS contains the extra bits. Bit <0> contains the first extra bit, <1> the
                                                                 second extra bit, etc.

                                                                 For decompression, [EXN] and [EXBITS] are not used and are undefined. */
        uint64_t reserved_151          : 1;
        uint64_t exn                   : 3;  /**< [154:152] The number of bits produced beyond the last output byte written.
                                                                 See details in [EXBITS]. */
        uint64_t reserved_155_158      : 4;
        uint64_t doneint               : 1;  /**< [159:159] Done Interrupt. This bit is copied from the corrresponding ZIP instruction ZIP_INST_S[DONEINT]. */
        uint64_t totalbitsprocessed    : 32; /**< [191:160] When [EF] = 1 for an error-free decompression operation,
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
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
#else /* Word 3 - Little Endian */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
#else /* Word 4 - Little Endian */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
#else /* Word 5 - Little Endian */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
#else /* Word 6 - Little Endian */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
#else /* Word 7 - Little Endian */
#endif /* Word 7 - End */
    } cn88xx;
    /* struct bdk_zip_zres_s_s cn83xx; */
};

/**
 * Register (NCB) zip_cmd_ctl
 *
 * ZIP Clock/Reset Control Register
 * This register controls clock and reset.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_cmd_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t forceclk              : 1;  /**< [  1:  1](R/W) When this bit is set to 1, it forces ZIP clocks on. */
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1) Reset one-shot pulse to reset ZIP subsystem. */
#else /* Word 0 - Little Endian */
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1) Reset one-shot pulse to reset ZIP subsystem. */
        uint64_t forceclk              : 1;  /**< [  1:  1](R/W) When this bit is set to 1, it forces ZIP clocks on. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_cmd_ctl_s cn; */
} bdk_zip_cmd_ctl_t;

#define BDK_ZIP_CMD_CTL BDK_ZIP_CMD_CTL_FUNC()
static inline uint64_t BDK_ZIP_CMD_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_CMD_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000000ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000000ll;
    __bdk_csr_fatal("ZIP_CMD_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_CMD_CTL bdk_zip_cmd_ctl_t
#define bustype_BDK_ZIP_CMD_CTL BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_CMD_CTL "ZIP_CMD_CTL"
#define device_bar_BDK_ZIP_CMD_CTL 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_CMD_CTL 0
#define arguments_BDK_ZIP_CMD_CTL -1,-1,-1,-1

/**
 * Register (NCB) zip_constants
 *
 * ZIP Constants Register
 * This register contains implementation-related parameters of the ZIP core in this
 * chip.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_constants_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nexec                 : 8;  /**< [ 63: 56](RO) Number of available ZIP executive units. If ZIP is disabled, this field is 0x0. */
        uint64_t reserved_50_55        : 6;
        uint64_t hash                  : 1;  /**< [ 49: 49](RO) Hashing supported: 1 = supported, 0 = not supported. */
        uint64_t syncflush_capable     : 1;  /**< [ 48: 48](RO) Sync flush supported: 1 = supported, 0 = not supported. */
        uint64_t depth                 : 16; /**< [ 47: 32](RO) Maximum search depth for compression. */
        uint64_t onfsize               : 12; /**< [ 31: 20](RO) Output near full threshold, in bytes. */
        uint64_t ctxsize               : 12; /**< [ 19:  8](RO) Decompression context size in bytes. */
        uint64_t reserved_1_7          : 7;
        uint64_t disabled              : 1;  /**< [  0:  0](RO) Disable. 1 = ZIP is disabled, 0 = ZIP is enabled. */
#else /* Word 0 - Little Endian */
        uint64_t disabled              : 1;  /**< [  0:  0](RO) Disable. 1 = ZIP is disabled, 0 = ZIP is enabled. */
        uint64_t reserved_1_7          : 7;
        uint64_t ctxsize               : 12; /**< [ 19:  8](RO) Decompression context size in bytes. */
        uint64_t onfsize               : 12; /**< [ 31: 20](RO) Output near full threshold, in bytes. */
        uint64_t depth                 : 16; /**< [ 47: 32](RO) Maximum search depth for compression. */
        uint64_t syncflush_capable     : 1;  /**< [ 48: 48](RO) Sync flush supported: 1 = supported, 0 = not supported. */
        uint64_t hash                  : 1;  /**< [ 49: 49](RO) Hashing supported: 1 = supported, 0 = not supported. */
        uint64_t reserved_50_55        : 6;
        uint64_t nexec                 : 8;  /**< [ 63: 56](RO) Number of available ZIP executive units. If ZIP is disabled, this field is 0x0. */
#endif /* Word 0 - End */
    } s;
    struct bdk_zip_constants_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nexec                 : 8;  /**< [ 63: 56](RO) Number of available ZIP executive units. If ZIP is disabled, this field is 0x0. */
        uint64_t reserved_49_55        : 7;
        uint64_t syncflush_capable     : 1;  /**< [ 48: 48](RO) Sync flush supported: 1 = supported, 0 = not supported. */
        uint64_t depth                 : 16; /**< [ 47: 32](RO) Maximum search depth for compression. */
        uint64_t onfsize               : 12; /**< [ 31: 20](RO) Output near full threshold, in bytes. */
        uint64_t ctxsize               : 12; /**< [ 19:  8](RO) Decompression context size in bytes. */
        uint64_t reserved_1_7          : 7;
        uint64_t disabled              : 1;  /**< [  0:  0](RO) Disable. 1 = ZIP is disabled, 0 = ZIP is enabled. */
#else /* Word 0 - Little Endian */
        uint64_t disabled              : 1;  /**< [  0:  0](RO) Disable. 1 = ZIP is disabled, 0 = ZIP is enabled. */
        uint64_t reserved_1_7          : 7;
        uint64_t ctxsize               : 12; /**< [ 19:  8](RO) Decompression context size in bytes. */
        uint64_t onfsize               : 12; /**< [ 31: 20](RO) Output near full threshold, in bytes. */
        uint64_t depth                 : 16; /**< [ 47: 32](RO) Maximum search depth for compression. */
        uint64_t syncflush_capable     : 1;  /**< [ 48: 48](RO) Sync flush supported: 1 = supported, 0 = not supported. */
        uint64_t reserved_49_55        : 7;
        uint64_t nexec                 : 8;  /**< [ 63: 56](RO) Number of available ZIP executive units. If ZIP is disabled, this field is 0x0. */
#endif /* Word 0 - End */
    } cn88xx;
    struct bdk_zip_constants_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nexec                 : 8;  /**< [ 63: 56](RO) Number of available ZIP executive units (compression-only plus
                                                                 decompression-only plus compression-or-decompression). If ZIP is disabled, this
                                                                 field is 0x0. */
        uint64_t reserved_50_55        : 6;
        uint64_t hash                  : 1;  /**< [ 49: 49](RO) Hashing supported: 1 = supported, 0 = not supported. */
        uint64_t syncflush_capable     : 1;  /**< [ 48: 48](RO) Sync flush supported: 1 = supported, 0 = not supported. */
        uint64_t depth                 : 16; /**< [ 47: 32](RO) Maximum search depth for compression. */
        uint64_t onfsize               : 12; /**< [ 31: 20](RO) Output near full threshold, in bytes. */
        uint64_t ctxsize               : 12; /**< [ 19:  8](RO) Decompression context size in bytes. */
        uint64_t reserved_1_7          : 7;
        uint64_t disabled              : 1;  /**< [  0:  0](RO) Disable. 1 = ZIP is disabled, 0 = ZIP is enabled. */
#else /* Word 0 - Little Endian */
        uint64_t disabled              : 1;  /**< [  0:  0](RO) Disable. 1 = ZIP is disabled, 0 = ZIP is enabled. */
        uint64_t reserved_1_7          : 7;
        uint64_t ctxsize               : 12; /**< [ 19:  8](RO) Decompression context size in bytes. */
        uint64_t onfsize               : 12; /**< [ 31: 20](RO) Output near full threshold, in bytes. */
        uint64_t depth                 : 16; /**< [ 47: 32](RO) Maximum search depth for compression. */
        uint64_t syncflush_capable     : 1;  /**< [ 48: 48](RO) Sync flush supported: 1 = supported, 0 = not supported. */
        uint64_t hash                  : 1;  /**< [ 49: 49](RO) Hashing supported: 1 = supported, 0 = not supported. */
        uint64_t reserved_50_55        : 6;
        uint64_t nexec                 : 8;  /**< [ 63: 56](RO) Number of available ZIP executive units (compression-only plus
                                                                 decompression-only plus compression-or-decompression). If ZIP is disabled, this
                                                                 field is 0x0. */
#endif /* Word 0 - End */
    } cn83xx;
} bdk_zip_constants_t;

#define BDK_ZIP_CONSTANTS BDK_ZIP_CONSTANTS_FUNC()
static inline uint64_t BDK_ZIP_CONSTANTS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_CONSTANTS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8380000000a0ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x8380000000a0ll;
    __bdk_csr_fatal("ZIP_CONSTANTS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_CONSTANTS bdk_zip_constants_t
#define bustype_BDK_ZIP_CONSTANTS BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_CONSTANTS "ZIP_CONSTANTS"
#define device_bar_BDK_ZIP_CONSTANTS 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_CONSTANTS 0
#define arguments_BDK_ZIP_CONSTANTS -1,-1,-1,-1

/**
 * Register (NCB) zip_constants2
 *
 * ZIP Constants 2 Register
 * This register contains additional implementation-related parameters of the ZIP core
 * in this chip.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_constants2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t dexec                 : 8;  /**< [ 15:  8](RO) Number of decompression-only units. If ZIP is disabled, this field is 0x0. */
        uint64_t cexec                 : 8;  /**< [  7:  0](RO) Number of compression-only units. If ZIP is disabled, this field is 0x0. */
#else /* Word 0 - Little Endian */
        uint64_t cexec                 : 8;  /**< [  7:  0](RO) Number of compression-only units. If ZIP is disabled, this field is 0x0. */
        uint64_t dexec                 : 8;  /**< [ 15:  8](RO) Number of decompression-only units. If ZIP is disabled, this field is 0x0. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_constants2_s cn; */
} bdk_zip_constants2_t;

#define BDK_ZIP_CONSTANTS2 BDK_ZIP_CONSTANTS2_FUNC()
static inline uint64_t BDK_ZIP_CONSTANTS2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_CONSTANTS2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8380000000a8ll;
    __bdk_csr_fatal("ZIP_CONSTANTS2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_CONSTANTS2 bdk_zip_constants2_t
#define bustype_BDK_ZIP_CONSTANTS2 BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_CONSTANTS2 "ZIP_CONSTANTS2"
#define device_bar_BDK_ZIP_CONSTANTS2 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_CONSTANTS2 0
#define arguments_BDK_ZIP_CONSTANTS2 -1,-1,-1,-1

/**
 * Register (NCB) zip_core#_bist_status
 *
 * ZIP Core BIST Status Registers
 * These register have the BIST status of memories in ZIP cores. Each bit is the BIST result of
 * an individual memory (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_corex_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t bstatus               : 53; /**< [ 52:  0](RO/H) BIST result of the ZIP_CORE memories. */
#else /* Word 0 - Little Endian */
        uint64_t bstatus               : 53; /**< [ 52:  0](RO/H) BIST result of the ZIP_CORE memories. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_corex_bist_status_s cn; */
} bdk_zip_corex_bist_status_t;

static inline uint64_t BDK_ZIP_COREX_BIST_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_COREX_BIST_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x838000000520ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=1))
        return 0x838000000520ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("ZIP_COREX_BIST_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_COREX_BIST_STATUS(a) bdk_zip_corex_bist_status_t
#define bustype_BDK_ZIP_COREX_BIST_STATUS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_COREX_BIST_STATUS(a) "ZIP_COREX_BIST_STATUS"
#define device_bar_BDK_ZIP_COREX_BIST_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_COREX_BIST_STATUS(a) (a)
#define arguments_BDK_ZIP_COREX_BIST_STATUS(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_core#_to_sta
 *
 * ZIP Core Status Registers
 * These registers reflect the timeout status of ZIP cores.
 * Added in pass 2.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_corex_to_sta_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t cnt                   : 32; /**< [ 31:  0](RO/H) Timeout counter value. The counter is reset to 0x0 whenever there is a output
                                                                 from ZIP engine or there is no output buffer credit for the ZIP
                                                                 engine. Otherwise counts up to compare with ZIP_CORE_TO_CFG[TIMEOUT]. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 32; /**< [ 31:  0](RO/H) Timeout counter value. The counter is reset to 0x0 whenever there is a output
                                                                 from ZIP engine or there is no output buffer credit for the ZIP
                                                                 engine. Otherwise counts up to compare with ZIP_CORE_TO_CFG[TIMEOUT]. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_corex_to_sta_s cn; */
} bdk_zip_corex_to_sta_t;

static inline uint64_t BDK_ZIP_COREX_TO_STA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_COREX_TO_STA(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x838000000780ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && (a<=1))
        return 0x838000000780ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("ZIP_COREX_TO_STA", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_COREX_TO_STA(a) bdk_zip_corex_to_sta_t
#define bustype_BDK_ZIP_COREX_TO_STA(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_COREX_TO_STA(a) "ZIP_COREX_TO_STA"
#define device_bar_BDK_ZIP_COREX_TO_STA(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_COREX_TO_STA(a) (a)
#define arguments_BDK_ZIP_COREX_TO_STA(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_core_reset
 *
 * ZIP Core Reset Register
 * This register resets the ZIP cores. For diagnostic use only. Added in pass 2.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_core_reset_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reac                  : 1;  /**< [ 63: 63](R/W) Reset ZIP engine after completion of each instruction, to limit exposure to
                                                                 corrupt commands and structures affecting subsequent commands. */
        uint64_t reserved_2_62         : 61;
        uint64_t reset                 : 2;  /**< [  1:  0](R/W) When set, the conresponding core will be put into reset. When clear, the core is out of
                                                                 reset.  Bit[<a>] resets ZIP core <a>. */
#else /* Word 0 - Little Endian */
        uint64_t reset                 : 2;  /**< [  1:  0](R/W) When set, the conresponding core will be put into reset. When clear, the core is out of
                                                                 reset.  Bit[<a>] resets ZIP core <a>. */
        uint64_t reserved_2_62         : 61;
        uint64_t reac                  : 1;  /**< [ 63: 63](R/W) Reset ZIP engine after completion of each instruction, to limit exposure to
                                                                 corrupt commands and structures affecting subsequent commands. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_core_reset_s cn; */
} bdk_zip_core_reset_t;

#define BDK_ZIP_CORE_RESET BDK_ZIP_CORE_RESET_FUNC()
static inline uint64_t BDK_ZIP_CORE_RESET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_CORE_RESET_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0x838000000300ll;
    __bdk_csr_fatal("ZIP_CORE_RESET", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_CORE_RESET bdk_zip_core_reset_t
#define bustype_BDK_ZIP_CORE_RESET BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_CORE_RESET "ZIP_CORE_RESET"
#define device_bar_BDK_ZIP_CORE_RESET 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_CORE_RESET 0
#define arguments_BDK_ZIP_CORE_RESET -1,-1,-1,-1

/**
 * Register (NCB) zip_core_to_cfg
 *
 * ZIP Engine Timeout Configure Register
 * Configure the core timeout value in term of clock cycles. Added in pass 2.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_core_to_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t halt                  : 1;  /**< [ 63: 63](R/W) If set, when timeout is detected, control will halt input and output and set the
                                                                 completion code in
                                                                 result buffer to ZIP_COMP_E[TIMEOUT]. If cleared (for diagnostic use only), if ZIP core
                                                                 continues
                                                                 outputing after timeout period the instruction will still be finished by the ZIP core. */
        uint64_t ar                    : 1;  /**< [ 62: 62](R/W) Auto reset. This bit only takes effect when [HALT] is set. When [HALT] is cleared, [AR] is
                                                                 ignored.
                                                                 0 = On a timeout, the timed-out core will hold the timed-out operation and not be auto-
                                                                 reset.
                                                                 1 = On a timeout, the timed-out core will be auto-reset. */
        uint64_t reserved_32_61        : 30;
        uint64_t timeout               : 32; /**< [ 31:  0](R/W) Number of coprocessor-clocks before a ZIP engine is considered hung. When the
                                                                 ZIP_CORE()_TO_STA[CNT] reaches ZIP_CORE_TO_CFG[TIMEOUT], the ZIP engine hang
                                                                 can be reported through interrupt ZIP_QUE()_ERR_INT[CTO] if the interrupt is enabled.
                                                                 If [TIMEOUT] is 0, engine timeout detection is disabled. INTERNAL: Decompression
                                                                 could be very slow if someone created a malicious compressed stream. Compression is
                                                                 much more bounded. The worst case would be .5B/cycle plus the Huffman encoding delay of
                                                                 around 8K cycles. Also note the cripple feature can increase the worst case delay 4x.
                                                                 If hangs are just theoretical and therefore very rare, using a large number say 1M
                                                                 cycles is recommended. Assume 1K cycels to cover the decompressing time plus 8K
                                                                 Huffman encoding delay, the total is 9K cycles. In the worst crippled case, the
                                                                 timeout upper limit is 9K x 4 x4 = 36K x 4 = 0x24000. For skew without cripple, S/W can
                                                                 overwrite this value to 0x2400. */
#else /* Word 0 - Little Endian */
        uint64_t timeout               : 32; /**< [ 31:  0](R/W) Number of coprocessor-clocks before a ZIP engine is considered hung. When the
                                                                 ZIP_CORE()_TO_STA[CNT] reaches ZIP_CORE_TO_CFG[TIMEOUT], the ZIP engine hang
                                                                 can be reported through interrupt ZIP_QUE()_ERR_INT[CTO] if the interrupt is enabled.
                                                                 If [TIMEOUT] is 0, engine timeout detection is disabled. INTERNAL: Decompression
                                                                 could be very slow if someone created a malicious compressed stream. Compression is
                                                                 much more bounded. The worst case would be .5B/cycle plus the Huffman encoding delay of
                                                                 around 8K cycles. Also note the cripple feature can increase the worst case delay 4x.
                                                                 If hangs are just theoretical and therefore very rare, using a large number say 1M
                                                                 cycles is recommended. Assume 1K cycels to cover the decompressing time plus 8K
                                                                 Huffman encoding delay, the total is 9K cycles. In the worst crippled case, the
                                                                 timeout upper limit is 9K x 4 x4 = 36K x 4 = 0x24000. For skew without cripple, S/W can
                                                                 overwrite this value to 0x2400. */
        uint64_t reserved_32_61        : 30;
        uint64_t ar                    : 1;  /**< [ 62: 62](R/W) Auto reset. This bit only takes effect when [HALT] is set. When [HALT] is cleared, [AR] is
                                                                 ignored.
                                                                 0 = On a timeout, the timed-out core will hold the timed-out operation and not be auto-
                                                                 reset.
                                                                 1 = On a timeout, the timed-out core will be auto-reset. */
        uint64_t halt                  : 1;  /**< [ 63: 63](R/W) If set, when timeout is detected, control will halt input and output and set the
                                                                 completion code in
                                                                 result buffer to ZIP_COMP_E[TIMEOUT]. If cleared (for diagnostic use only), if ZIP core
                                                                 continues
                                                                 outputing after timeout period the instruction will still be finished by the ZIP core. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_core_to_cfg_s cn; */
} bdk_zip_core_to_cfg_t;

#define BDK_ZIP_CORE_TO_CFG BDK_ZIP_CORE_TO_CFG_FUNC()
static inline uint64_t BDK_ZIP_CORE_TO_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_CORE_TO_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000700ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0x838000000700ll;
    __bdk_csr_fatal("ZIP_CORE_TO_CFG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_CORE_TO_CFG bdk_zip_core_to_cfg_t
#define bustype_BDK_ZIP_CORE_TO_CFG BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_CORE_TO_CFG "ZIP_CORE_TO_CFG"
#define device_bar_BDK_ZIP_CORE_TO_CFG 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_CORE_TO_CFG 0
#define arguments_BDK_ZIP_CORE_TO_CFG -1,-1,-1,-1

/**
 * Register (NCB) zip_ctl_bist_status
 *
 * ZIP Control Bist Status Register
 * This register has the BIST status of memories in ZIP_CTL (instruction buffer, G/S pointer
 * FIFO, input data buffer, output data buffers). Each bit is the BIST result of an individual
 * memory (per bit, 0 = pass and 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_ctl_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t bstatus               : 9;  /**< [  8:  0](RO/H) BIST result of CTL memories. INTERNAL:BSTATUS = {VMEM, STDF[1:0], OFIF[1:0],
                                                                 IDF[1:0],GSPF, IQF}. */
#else /* Word 0 - Little Endian */
        uint64_t bstatus               : 9;  /**< [  8:  0](RO/H) BIST result of CTL memories. INTERNAL:BSTATUS = {VMEM, STDF[1:0], OFIF[1:0],
                                                                 IDF[1:0],GSPF, IQF}. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_ctl_bist_status_s cn; */
} bdk_zip_ctl_bist_status_t;

#define BDK_ZIP_CTL_BIST_STATUS BDK_ZIP_CTL_BIST_STATUS_FUNC()
static inline uint64_t BDK_ZIP_CTL_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_CTL_BIST_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000510ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000510ll;
    __bdk_csr_fatal("ZIP_CTL_BIST_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_CTL_BIST_STATUS bdk_zip_ctl_bist_status_t
#define bustype_BDK_ZIP_CTL_BIST_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_CTL_BIST_STATUS "ZIP_CTL_BIST_STATUS"
#define device_bar_BDK_ZIP_CTL_BIST_STATUS 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_CTL_BIST_STATUS 0
#define arguments_BDK_ZIP_CTL_BIST_STATUS -1,-1,-1,-1

/**
 * Register (NCB) zip_ctl_cfg
 *
 * ZIP Controller Configuration Register
 * This register controls the behavior of the ZIP DMA engines. It is recommended to keep default
 * values for normal operation. Changing the values of the fields may be useful for diagnostics.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_ctl_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t ildf                  : 4;  /**< [ 51: 48](R/W) Instruction Load Command FIFO credits <= 8. */
        uint64_t reserved_36_47        : 12;
        uint64_t drtf                  : 4;  /**< [ 35: 32](R/W) Data Read Tag FIFOs (per core) credits <= 8. */
        uint64_t reserved_27_31        : 5;
        uint64_t stcf                  : 3;  /**< [ 26: 24](R/W) Store Command FIFO credits <= 4. */
        uint64_t reserved_19_23        : 5;
        uint64_t ldf                   : 3;  /**< [ 18: 16](R/W) Load Command FIFO credits <= 4. */
        uint64_t reserved_2_15         : 14;
        uint64_t busy                  : 1;  /**< [  1:  1](RO/H) 1: ZIP system is busy; 0: ZIP system is idle. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t busy                  : 1;  /**< [  1:  1](RO/H) 1: ZIP system is busy; 0: ZIP system is idle. */
        uint64_t reserved_2_15         : 14;
        uint64_t ldf                   : 3;  /**< [ 18: 16](R/W) Load Command FIFO credits <= 4. */
        uint64_t reserved_19_23        : 5;
        uint64_t stcf                  : 3;  /**< [ 26: 24](R/W) Store Command FIFO credits <= 4. */
        uint64_t reserved_27_31        : 5;
        uint64_t drtf                  : 4;  /**< [ 35: 32](R/W) Data Read Tag FIFOs (per core) credits <= 8. */
        uint64_t reserved_36_47        : 12;
        uint64_t ildf                  : 4;  /**< [ 51: 48](R/W) Instruction Load Command FIFO credits <= 8. */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
    } s;
    struct bdk_zip_ctl_cfg_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t ildf                  : 4;  /**< [ 51: 48](R/W) Instruction Load Command FIFO credits <= 8. */
        uint64_t reserved_36_47        : 12;
        uint64_t drtf                  : 4;  /**< [ 35: 32](R/W) Data Read Tag FIFOs (per core) credits <= 8. */
        uint64_t reserved_27_31        : 5;
        uint64_t stcf                  : 3;  /**< [ 26: 24](R/W) Store Command FIFO credits <= 4. */
        uint64_t reserved_19_23        : 5;
        uint64_t ldf                   : 3;  /**< [ 18: 16](R/W) Load Command FIFO credits <= 4. */
        uint64_t reserved_8_15         : 8;
        uint64_t reserved_2_7          : 6;
        uint64_t busy                  : 1;  /**< [  1:  1](RO/H) 1: ZIP system is busy; 0: ZIP system is idle. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t busy                  : 1;  /**< [  1:  1](RO/H) 1: ZIP system is busy; 0: ZIP system is idle. */
        uint64_t reserved_2_7          : 6;
        uint64_t reserved_8_15         : 8;
        uint64_t ldf                   : 3;  /**< [ 18: 16](R/W) Load Command FIFO credits <= 4. */
        uint64_t reserved_19_23        : 5;
        uint64_t stcf                  : 3;  /**< [ 26: 24](R/W) Store Command FIFO credits <= 4. */
        uint64_t reserved_27_31        : 5;
        uint64_t drtf                  : 4;  /**< [ 35: 32](R/W) Data Read Tag FIFOs (per core) credits <= 8. */
        uint64_t reserved_36_47        : 12;
        uint64_t ildf                  : 4;  /**< [ 51: 48](R/W) Instruction Load Command FIFO credits <= 8. */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
    } cn;
} bdk_zip_ctl_cfg_t;

#define BDK_ZIP_CTL_CFG BDK_ZIP_CTL_CFG_FUNC()
static inline uint64_t BDK_ZIP_CTL_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_CTL_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000560ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000560ll;
    __bdk_csr_fatal("ZIP_CTL_CFG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_CTL_CFG bdk_zip_ctl_cfg_t
#define bustype_BDK_ZIP_CTL_CFG BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_CTL_CFG "ZIP_CTL_CFG"
#define device_bar_BDK_ZIP_CTL_CFG 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_CTL_CFG 0
#define arguments_BDK_ZIP_CTL_CFG -1,-1,-1,-1

/**
 * Register (NCB) zip_dbg_core#_inst
 *
 * ZIP Core Current Instruction Registers
 * These registers reflect the status of the current instruction that the ZIP core is executing
 * or has executed. These registers are only for debug use.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_dbg_corex_inst_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Core state. 0 = core is idle; 1 = core is busy. */
        uint64_t outstanding           : 1;  /**< [ 62: 62](RO/H) When set, core is wait for outstanding L2C transaction(s).
                                                                 Otherwise, there is no outstanding L2C transaction and core can be reset if needed. Added
                                                                 in pass 2. */
        uint64_t cto                   : 1;  /**< [ 61: 61](RO/H) Core timeout detected. When set, it indicated this core is timed out when
                                                                 executig the current instruction with instruction ID [IID] from queue [QID].
                                                                 Added in pass 2. */
        uint64_t reserved_35_60        : 26;
        uint64_t qid                   : 3;  /**< [ 34: 32](RO/H) Queue index of instruction executed (BUSY = 0) or being executed (BUSY = 1) on this core. */
        uint64_t iid                   : 32; /**< [ 31:  0](RO/H) Instruction index executed (BUSY = 0) or being executed (BUSY = 1) on this core. */
#else /* Word 0 - Little Endian */
        uint64_t iid                   : 32; /**< [ 31:  0](RO/H) Instruction index executed (BUSY = 0) or being executed (BUSY = 1) on this core. */
        uint64_t qid                   : 3;  /**< [ 34: 32](RO/H) Queue index of instruction executed (BUSY = 0) or being executed (BUSY = 1) on this core. */
        uint64_t reserved_35_60        : 26;
        uint64_t cto                   : 1;  /**< [ 61: 61](RO/H) Core timeout detected. When set, it indicated this core is timed out when
                                                                 executig the current instruction with instruction ID [IID] from queue [QID].
                                                                 Added in pass 2. */
        uint64_t outstanding           : 1;  /**< [ 62: 62](RO/H) When set, core is wait for outstanding L2C transaction(s).
                                                                 Otherwise, there is no outstanding L2C transaction and core can be reset if needed. Added
                                                                 in pass 2. */
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Core state. 0 = core is idle; 1 = core is busy. */
#endif /* Word 0 - End */
    } s;
    struct bdk_zip_dbg_corex_inst_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Core state. 0 = core is idle; 1 = core is busy. */
        uint64_t reserved_35_62        : 28;
        uint64_t qid                   : 3;  /**< [ 34: 32](RO/H) Queue index of instruction executed (BUSY = 0) or being executed (BUSY = 1) on this core. */
        uint64_t iid                   : 32; /**< [ 31:  0](RO/H) Instruction index executed (BUSY = 0) or being executed (BUSY = 1) on this core. */
#else /* Word 0 - Little Endian */
        uint64_t iid                   : 32; /**< [ 31:  0](RO/H) Instruction index executed (BUSY = 0) or being executed (BUSY = 1) on this core. */
        uint64_t qid                   : 3;  /**< [ 34: 32](RO/H) Queue index of instruction executed (BUSY = 0) or being executed (BUSY = 1) on this core. */
        uint64_t reserved_35_62        : 28;
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Core state. 0 = core is idle; 1 = core is busy. */
#endif /* Word 0 - End */
    } cn83xx;
    /* struct bdk_zip_dbg_corex_inst_s cn88xxp2; */
    struct bdk_zip_dbg_corex_inst_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Core state. 0 = core is idle; 1 = core is busy. */
        uint64_t reserved_61_62        : 2;
        uint64_t reserved_35_60        : 26;
        uint64_t qid                   : 3;  /**< [ 34: 32](RO/H) Queue index of instruction executed (BUSY = 0) or being executed (BUSY = 1) on this core. */
        uint64_t iid                   : 32; /**< [ 31:  0](RO/H) Instruction index executed (BUSY = 0) or being executed (BUSY = 1) on this core. */
#else /* Word 0 - Little Endian */
        uint64_t iid                   : 32; /**< [ 31:  0](RO/H) Instruction index executed (BUSY = 0) or being executed (BUSY = 1) on this core. */
        uint64_t qid                   : 3;  /**< [ 34: 32](RO/H) Queue index of instruction executed (BUSY = 0) or being executed (BUSY = 1) on this core. */
        uint64_t reserved_35_60        : 26;
        uint64_t reserved_61_62        : 2;
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Core state. 0 = core is idle; 1 = core is busy. */
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_zip_dbg_corex_inst_t;

static inline uint64_t BDK_ZIP_DBG_COREX_INST(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_DBG_COREX_INST(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x838000000640ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=1))
        return 0x838000000640ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("ZIP_DBG_COREX_INST", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_DBG_COREX_INST(a) bdk_zip_dbg_corex_inst_t
#define bustype_BDK_ZIP_DBG_COREX_INST(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_DBG_COREX_INST(a) "ZIP_DBG_COREX_INST"
#define device_bar_BDK_ZIP_DBG_COREX_INST(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_DBG_COREX_INST(a) (a)
#define arguments_BDK_ZIP_DBG_COREX_INST(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_dbg_core#_sta
 *
 * ZIP Core Status Registers
 * These registers reflect the status of the ZIP cores and are for debug use only.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_dbg_corex_sta_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Core state. 0 = core is idle; 1 = core is busy. */
        uint64_t reserved_37_62        : 26;
        uint64_t ist                   : 5;  /**< [ 36: 32](RO/H) State of current instruction that is executing. */
        uint64_t nie                   : 32; /**< [ 31:  0](RO/H) Number of instructions executed on this core. */
#else /* Word 0 - Little Endian */
        uint64_t nie                   : 32; /**< [ 31:  0](RO/H) Number of instructions executed on this core. */
        uint64_t ist                   : 5;  /**< [ 36: 32](RO/H) State of current instruction that is executing. */
        uint64_t reserved_37_62        : 26;
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Core state. 0 = core is idle; 1 = core is busy. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_dbg_corex_sta_s cn; */
} bdk_zip_dbg_corex_sta_t;

static inline uint64_t BDK_ZIP_DBG_COREX_STA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_DBG_COREX_STA(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=5))
        return 0x838000000680ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=1))
        return 0x838000000680ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("ZIP_DBG_COREX_STA", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_DBG_COREX_STA(a) bdk_zip_dbg_corex_sta_t
#define bustype_BDK_ZIP_DBG_COREX_STA(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_DBG_COREX_STA(a) "ZIP_DBG_COREX_STA"
#define device_bar_BDK_ZIP_DBG_COREX_STA(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_DBG_COREX_STA(a) (a)
#define arguments_BDK_ZIP_DBG_COREX_STA(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_dbg_que#_sta
 *
 * ZIP Queue Status Registers
 * These registers reflect status of the ZIP instruction queues and are for debug use only.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_dbg_quex_sta_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Queue state. 0 = queue is idle; 1 = queue is busy. */
        uint64_t outstanding           : 1;  /**< [ 62: 62](RO/H) When set, queue is wait for outstanding L2C transaction(s).
                                                                 Otherwise, there are no outstanding L2C transaction and queue can be reset if
                                                                 needed. Added in pass 2. */
        uint64_t reserved_56_61        : 6;
        uint64_t rqwc                  : 24; /**< [ 55: 32](RO/H) Number of remaining instruction qwords to be fetched. */
        uint64_t nii                   : 32; /**< [ 31:  0](RO/H) Number of instructions issued from this queue. Reset to 0x0 when ZIP_QUE(0..7)_SBUF_ADDR
                                                                 is written. */
#else /* Word 0 - Little Endian */
        uint64_t nii                   : 32; /**< [ 31:  0](RO/H) Number of instructions issued from this queue. Reset to 0x0 when ZIP_QUE(0..7)_SBUF_ADDR
                                                                 is written. */
        uint64_t rqwc                  : 24; /**< [ 55: 32](RO/H) Number of remaining instruction qwords to be fetched. */
        uint64_t reserved_56_61        : 6;
        uint64_t outstanding           : 1;  /**< [ 62: 62](RO/H) When set, queue is wait for outstanding L2C transaction(s).
                                                                 Otherwise, there are no outstanding L2C transaction and queue can be reset if
                                                                 needed. Added in pass 2. */
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Queue state. 0 = queue is idle; 1 = queue is busy. */
#endif /* Word 0 - End */
    } s;
    struct bdk_zip_dbg_quex_sta_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Queue state. 0 = queue is idle; 1 = queue is busy. */
        uint64_t reserved_56_62        : 7;
        uint64_t rqwc                  : 24; /**< [ 55: 32](RO/H) Number of remaining instruction qwords to be fetched. */
        uint64_t nii                   : 32; /**< [ 31:  0](RO/H) Number of instructions issued from this queue. Reset to 0x0 when ZIP_QUE(0..7)_SBUF_ADDR
                                                                 is written. */
#else /* Word 0 - Little Endian */
        uint64_t nii                   : 32; /**< [ 31:  0](RO/H) Number of instructions issued from this queue. Reset to 0x0 when ZIP_QUE(0..7)_SBUF_ADDR
                                                                 is written. */
        uint64_t rqwc                  : 24; /**< [ 55: 32](RO/H) Number of remaining instruction qwords to be fetched. */
        uint64_t reserved_56_62        : 7;
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Queue state. 0 = queue is idle; 1 = queue is busy. */
#endif /* Word 0 - End */
    } cn83xx;
    /* struct bdk_zip_dbg_quex_sta_s cn88xxp2; */
    struct bdk_zip_dbg_quex_sta_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Queue state. 0 = queue is idle; 1 = queue is busy. */
        uint64_t reserved_62           : 1;
        uint64_t reserved_56_61        : 6;
        uint64_t rqwc                  : 24; /**< [ 55: 32](RO/H) Number of remaining instruction qwords to be fetched. */
        uint64_t nii                   : 32; /**< [ 31:  0](RO/H) Number of instructions issued from this queue. Reset to 0x0 when ZIP_QUE(0..7)_SBUF_ADDR
                                                                 is written. */
#else /* Word 0 - Little Endian */
        uint64_t nii                   : 32; /**< [ 31:  0](RO/H) Number of instructions issued from this queue. Reset to 0x0 when ZIP_QUE(0..7)_SBUF_ADDR
                                                                 is written. */
        uint64_t rqwc                  : 24; /**< [ 55: 32](RO/H) Number of remaining instruction qwords to be fetched. */
        uint64_t reserved_56_61        : 6;
        uint64_t reserved_62           : 1;
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Queue state. 0 = queue is idle; 1 = queue is busy. */
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_zip_dbg_quex_sta_t;

static inline uint64_t BDK_ZIP_DBG_QUEX_STA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_DBG_QUEX_STA(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000001800ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000001800ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_DBG_QUEX_STA", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_DBG_QUEX_STA(a) bdk_zip_dbg_quex_sta_t
#define bustype_BDK_ZIP_DBG_QUEX_STA(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_DBG_QUEX_STA(a) "ZIP_DBG_QUEX_STA"
#define device_bar_BDK_ZIP_DBG_QUEX_STA(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_DBG_QUEX_STA(a) (a)
#define arguments_BDK_ZIP_DBG_QUEX_STA(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_ecc_ctl
 *
 * ZIP ECC Control Register
 * This register enables ECC for each individual internal memory that requires ECC. For debug
 * purpose, it can also flip one or two bits in the ECC data.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_ecc_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t vmem_cdis             : 1;  /**< [ 18: 18](R/W) VMEM memory ECC correction disable. */
        uint64_t vmem_fs               : 2;  /**< [ 17: 16](R/W) Controls VMEM memory flip syndrome. */
        uint64_t reserved_15           : 1;
        uint64_t idf1_cdis             : 1;  /**< [ 14: 14](R/W) Input Data FIFO 1 ECC correction disable. */
        uint64_t idf1_fs               : 2;  /**< [ 13: 12](R/W) Controls Input Data FIFO 1 flip syndrome. */
        uint64_t reserved_11           : 1;
        uint64_t idf0_cdis             : 1;  /**< [ 10: 10](R/W) Input Data FIFO 0 ECC correction disable. */
        uint64_t idf0_fs               : 2;  /**< [  9:  8](R/W) Controls Input Data FIFO 0 flip syndrome. */
        uint64_t reserved_7            : 1;
        uint64_t gspf_cdis             : 1;  /**< [  6:  6](R/W) G/S Pointer FIFO ECC correction disable. */
        uint64_t gspf_fs               : 2;  /**< [  5:  4](R/W) Controls G/S Pointer FIFO flip syndrome. */
        uint64_t reserved_3            : 1;
        uint64_t iqf_cdis              : 1;  /**< [  2:  2](R/W) Instruction Queue FIFO ECC correction disable. */
        uint64_t iqf_fs                : 2;  /**< [  1:  0](R/W) Controls Instruction Queue FIFO flip syndrome.
                                                                 0x0 = no error generation.
                                                                 0x1 = flip one bit.
                                                                 0x2 = flip one bit.
                                                                 0x3 = flip two bits. */
#else /* Word 0 - Little Endian */
        uint64_t iqf_fs                : 2;  /**< [  1:  0](R/W) Controls Instruction Queue FIFO flip syndrome.
                                                                 0x0 = no error generation.
                                                                 0x1 = flip one bit.
                                                                 0x2 = flip one bit.
                                                                 0x3 = flip two bits. */
        uint64_t iqf_cdis              : 1;  /**< [  2:  2](R/W) Instruction Queue FIFO ECC correction disable. */
        uint64_t reserved_3            : 1;
        uint64_t gspf_fs               : 2;  /**< [  5:  4](R/W) Controls G/S Pointer FIFO flip syndrome. */
        uint64_t gspf_cdis             : 1;  /**< [  6:  6](R/W) G/S Pointer FIFO ECC correction disable. */
        uint64_t reserved_7            : 1;
        uint64_t idf0_fs               : 2;  /**< [  9:  8](R/W) Controls Input Data FIFO 0 flip syndrome. */
        uint64_t idf0_cdis             : 1;  /**< [ 10: 10](R/W) Input Data FIFO 0 ECC correction disable. */
        uint64_t reserved_11           : 1;
        uint64_t idf1_fs               : 2;  /**< [ 13: 12](R/W) Controls Input Data FIFO 1 flip syndrome. */
        uint64_t idf1_cdis             : 1;  /**< [ 14: 14](R/W) Input Data FIFO 1 ECC correction disable. */
        uint64_t reserved_15           : 1;
        uint64_t vmem_fs               : 2;  /**< [ 17: 16](R/W) Controls VMEM memory flip syndrome. */
        uint64_t vmem_cdis             : 1;  /**< [ 18: 18](R/W) VMEM memory ECC correction disable. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_ecc_ctl_s cn; */
} bdk_zip_ecc_ctl_t;

#define BDK_ZIP_ECC_CTL BDK_ZIP_ECC_CTL_FUNC()
static inline uint64_t BDK_ZIP_ECC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_ECC_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000568ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000568ll;
    __bdk_csr_fatal("ZIP_ECC_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_ECC_CTL bdk_zip_ecc_ctl_t
#define bustype_BDK_ZIP_ECC_CTL BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_ECC_CTL "ZIP_ECC_CTL"
#define device_bar_BDK_ZIP_ECC_CTL 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_ECC_CTL 0
#define arguments_BDK_ZIP_ECC_CTL -1,-1,-1,-1

/**
 * Register (NCB) zip_ecce_ena_w1c
 *
 * ZIP ECC Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_ecce_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_37_63        : 27;
        uint64_t dbe                   : 5;  /**< [ 36: 32](R/W1C/H) Reads or clears enable for ZIP_ECCE_INT[DBE]. */
        uint64_t reserved_5_31         : 27;
        uint64_t sbe                   : 5;  /**< [  4:  0](R/W1C/H) Reads or clears enable for ZIP_ECCE_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 5;  /**< [  4:  0](R/W1C/H) Reads or clears enable for ZIP_ECCE_INT[SBE]. */
        uint64_t reserved_5_31         : 27;
        uint64_t dbe                   : 5;  /**< [ 36: 32](R/W1C/H) Reads or clears enable for ZIP_ECCE_INT[DBE]. */
        uint64_t reserved_37_63        : 27;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_ecce_ena_w1c_s cn; */
} bdk_zip_ecce_ena_w1c_t;

#define BDK_ZIP_ECCE_ENA_W1C BDK_ZIP_ECCE_ENA_W1C_FUNC()
static inline uint64_t BDK_ZIP_ECCE_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_ECCE_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000598ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000598ll;
    __bdk_csr_fatal("ZIP_ECCE_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_ECCE_ENA_W1C bdk_zip_ecce_ena_w1c_t
#define bustype_BDK_ZIP_ECCE_ENA_W1C BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_ECCE_ENA_W1C "ZIP_ECCE_ENA_W1C"
#define device_bar_BDK_ZIP_ECCE_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_ECCE_ENA_W1C 0
#define arguments_BDK_ZIP_ECCE_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) zip_ecce_ena_w1s
 *
 * ZIP ECC Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_ecce_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_37_63        : 27;
        uint64_t dbe                   : 5;  /**< [ 36: 32](R/W1S/H) Reads or sets enable for ZIP_ECCE_INT[DBE]. */
        uint64_t reserved_5_31         : 27;
        uint64_t sbe                   : 5;  /**< [  4:  0](R/W1S/H) Reads or sets enable for ZIP_ECCE_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 5;  /**< [  4:  0](R/W1S/H) Reads or sets enable for ZIP_ECCE_INT[SBE]. */
        uint64_t reserved_5_31         : 27;
        uint64_t dbe                   : 5;  /**< [ 36: 32](R/W1S/H) Reads or sets enable for ZIP_ECCE_INT[DBE]. */
        uint64_t reserved_37_63        : 27;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_ecce_ena_w1s_s cn; */
} bdk_zip_ecce_ena_w1s_t;

#define BDK_ZIP_ECCE_ENA_W1S BDK_ZIP_ECCE_ENA_W1S_FUNC()
static inline uint64_t BDK_ZIP_ECCE_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_ECCE_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000590ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000590ll;
    __bdk_csr_fatal("ZIP_ECCE_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_ECCE_ENA_W1S bdk_zip_ecce_ena_w1s_t
#define bustype_BDK_ZIP_ECCE_ENA_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_ECCE_ENA_W1S "ZIP_ECCE_ENA_W1S"
#define device_bar_BDK_ZIP_ECCE_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_ECCE_ENA_W1S 0
#define arguments_BDK_ZIP_ECCE_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) zip_ecce_int
 *
 * ZIP ECC Interrupt Status Register
 * This register contains the status of the ECC interrupt sources.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_ecce_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_37_63        : 27;
        uint64_t dbe                   : 5;  /**< [ 36: 32](R/W1C/H) Double-bit error detected in internal RAM. 0 = pass, 1 = fail. One bit per memory.
                                                                 INTERNAL: The memories are [VMEM, IDF1, IDF0, GSPF, IQF]. */
        uint64_t reserved_5_31         : 27;
        uint64_t sbe                   : 5;  /**< [  4:  0](R/W1C/H) Single-bit error detected in internal RAM. 0 = pass, 1 = fail. One bit per memory.
                                                                 INTERNAL: The memories are [VMEM, IDF1, IDF0, GSPF,IQF]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 5;  /**< [  4:  0](R/W1C/H) Single-bit error detected in internal RAM. 0 = pass, 1 = fail. One bit per memory.
                                                                 INTERNAL: The memories are [VMEM, IDF1, IDF0, GSPF,IQF]. */
        uint64_t reserved_5_31         : 27;
        uint64_t dbe                   : 5;  /**< [ 36: 32](R/W1C/H) Double-bit error detected in internal RAM. 0 = pass, 1 = fail. One bit per memory.
                                                                 INTERNAL: The memories are [VMEM, IDF1, IDF0, GSPF, IQF]. */
        uint64_t reserved_37_63        : 27;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_ecce_int_s cn; */
} bdk_zip_ecce_int_t;

#define BDK_ZIP_ECCE_INT BDK_ZIP_ECCE_INT_FUNC()
static inline uint64_t BDK_ZIP_ECCE_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_ECCE_INT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000580ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000580ll;
    __bdk_csr_fatal("ZIP_ECCE_INT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_ECCE_INT bdk_zip_ecce_int_t
#define bustype_BDK_ZIP_ECCE_INT BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_ECCE_INT "ZIP_ECCE_INT"
#define device_bar_BDK_ZIP_ECCE_INT 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_ECCE_INT 0
#define arguments_BDK_ZIP_ECCE_INT -1,-1,-1,-1

/**
 * Register (NCB) zip_ecce_int_w1s
 *
 * ZIP ECC Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_ecce_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_37_63        : 27;
        uint64_t dbe                   : 5;  /**< [ 36: 32](R/W1S/H) Reads or sets ZIP_ECCE_INT[DBE]. */
        uint64_t reserved_5_31         : 27;
        uint64_t sbe                   : 5;  /**< [  4:  0](R/W1S/H) Reads or sets ZIP_ECCE_INT[SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t sbe                   : 5;  /**< [  4:  0](R/W1S/H) Reads or sets ZIP_ECCE_INT[SBE]. */
        uint64_t reserved_5_31         : 27;
        uint64_t dbe                   : 5;  /**< [ 36: 32](R/W1S/H) Reads or sets ZIP_ECCE_INT[DBE]. */
        uint64_t reserved_37_63        : 27;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_ecce_int_w1s_s cn; */
} bdk_zip_ecce_int_w1s_t;

#define BDK_ZIP_ECCE_INT_W1S BDK_ZIP_ECCE_INT_W1S_FUNC()
static inline uint64_t BDK_ZIP_ECCE_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_ECCE_INT_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000588ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000588ll;
    __bdk_csr_fatal("ZIP_ECCE_INT_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_ECCE_INT_W1S bdk_zip_ecce_int_w1s_t
#define bustype_BDK_ZIP_ECCE_INT_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_ECCE_INT_W1S "ZIP_ECCE_INT_W1S"
#define device_bar_BDK_ZIP_ECCE_INT_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_ECCE_INT_W1S 0
#define arguments_BDK_ZIP_ECCE_INT_W1S -1,-1,-1,-1

/**
 * Register (NCB) zip_eco
 *
 * INTERNAL: ZIP ECO Register
 *
 * Added in pass 2.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) INTERNAL: Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) INTERNAL: Reserved for ECO usage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_eco_s cn; */
} bdk_zip_eco_t;

#define BDK_ZIP_ECO BDK_ZIP_ECO_FUNC()
static inline uint64_t BDK_ZIP_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8380000005f0ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0x8380000005f0ll;
    __bdk_csr_fatal("ZIP_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_ECO bdk_zip_eco_t
#define bustype_BDK_ZIP_ECO BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_ECO "ZIP_ECO"
#define device_bar_BDK_ZIP_ECO 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_ECO 0
#define arguments_BDK_ZIP_ECO -1,-1,-1,-1

/**
 * Register (NCB) zip_fife_ena_w1c
 *
 * ZIP Error Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_fife_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_42_63        : 22;
        uint64_t asserts               : 42; /**< [ 41:  0](R/W1C/H) Reads or clears enable for ZIP_FIFE_INT[ASSERTS]. */
#else /* Word 0 - Little Endian */
        uint64_t asserts               : 42; /**< [ 41:  0](R/W1C/H) Reads or clears enable for ZIP_FIFE_INT[ASSERTS]. */
        uint64_t reserved_42_63        : 22;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_fife_ena_w1c_s cn; */
} bdk_zip_fife_ena_w1c_t;

#define BDK_ZIP_FIFE_ENA_W1C BDK_ZIP_FIFE_ENA_W1C_FUNC()
static inline uint64_t BDK_ZIP_FIFE_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_FIFE_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000090ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000090ll;
    __bdk_csr_fatal("ZIP_FIFE_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_FIFE_ENA_W1C bdk_zip_fife_ena_w1c_t
#define bustype_BDK_ZIP_FIFE_ENA_W1C BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_FIFE_ENA_W1C "ZIP_FIFE_ENA_W1C"
#define device_bar_BDK_ZIP_FIFE_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_FIFE_ENA_W1C 0
#define arguments_BDK_ZIP_FIFE_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) zip_fife_ena_w1s
 *
 * ZIP Error Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_fife_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_42_63        : 22;
        uint64_t asserts               : 42; /**< [ 41:  0](R/W1S/H) Reads or sets enable for ZIP_FIFE_INT[ASSERTS]. */
#else /* Word 0 - Little Endian */
        uint64_t asserts               : 42; /**< [ 41:  0](R/W1S/H) Reads or sets enable for ZIP_FIFE_INT[ASSERTS]. */
        uint64_t reserved_42_63        : 22;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_fife_ena_w1s_s cn; */
} bdk_zip_fife_ena_w1s_t;

#define BDK_ZIP_FIFE_ENA_W1S BDK_ZIP_FIFE_ENA_W1S_FUNC()
static inline uint64_t BDK_ZIP_FIFE_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_FIFE_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000088ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000088ll;
    __bdk_csr_fatal("ZIP_FIFE_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_FIFE_ENA_W1S bdk_zip_fife_ena_w1s_t
#define bustype_BDK_ZIP_FIFE_ENA_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_FIFE_ENA_W1S "ZIP_FIFE_ENA_W1S"
#define device_bar_BDK_ZIP_FIFE_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_FIFE_ENA_W1S 0
#define arguments_BDK_ZIP_FIFE_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) zip_fife_int
 *
 * ZIP Error Interrupt Register
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_fife_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_42_63        : 22;
        uint64_t asserts               : 42; /**< [ 41:  0](R/W1C/H) FIFO assertion checks. */
#else /* Word 0 - Little Endian */
        uint64_t asserts               : 42; /**< [ 41:  0](R/W1C/H) FIFO assertion checks. */
        uint64_t reserved_42_63        : 22;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_fife_int_s cn; */
} bdk_zip_fife_int_t;

#define BDK_ZIP_FIFE_INT BDK_ZIP_FIFE_INT_FUNC()
static inline uint64_t BDK_ZIP_FIFE_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_FIFE_INT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000078ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000078ll;
    __bdk_csr_fatal("ZIP_FIFE_INT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_FIFE_INT bdk_zip_fife_int_t
#define bustype_BDK_ZIP_FIFE_INT BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_FIFE_INT "ZIP_FIFE_INT"
#define device_bar_BDK_ZIP_FIFE_INT 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_FIFE_INT 0
#define arguments_BDK_ZIP_FIFE_INT -1,-1,-1,-1

/**
 * Register (NCB) zip_fife_int_w1s
 *
 * ZIP Error Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_fife_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_42_63        : 22;
        uint64_t asserts               : 42; /**< [ 41:  0](R/W1S/H) Reads or sets ZIP_FIFE_INT[ASSERTS]. */
#else /* Word 0 - Little Endian */
        uint64_t asserts               : 42; /**< [ 41:  0](R/W1S/H) Reads or sets ZIP_FIFE_INT[ASSERTS]. */
        uint64_t reserved_42_63        : 22;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_fife_int_w1s_s cn; */
} bdk_zip_fife_int_w1s_t;

#define BDK_ZIP_FIFE_INT_W1S BDK_ZIP_FIFE_INT_W1S_FUNC()
static inline uint64_t BDK_ZIP_FIFE_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_FIFE_INT_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000080ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000080ll;
    __bdk_csr_fatal("ZIP_FIFE_INT_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_FIFE_INT_W1S bdk_zip_fife_int_w1s_t
#define bustype_BDK_ZIP_FIFE_INT_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_FIFE_INT_W1S "ZIP_FIFE_INT_W1S"
#define device_bar_BDK_ZIP_FIFE_INT_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_FIFE_INT_W1S 0
#define arguments_BDK_ZIP_FIFE_INT_W1S -1,-1,-1,-1

/**
 * Register (NCB) zip_msix_pba#
 *
 * ZIP MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the ZIP_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated ZIP_MSIX_VEC()_CTL, enumerated by ZIP_INT_VEC_E.
                                                                 Bits that have no associated ZIP_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated ZIP_MSIX_VEC()_CTL, enumerated by ZIP_INT_VEC_E.
                                                                 Bits that have no associated ZIP_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_msix_pbax_s cn; */
} bdk_zip_msix_pbax_t;

static inline uint64_t BDK_ZIP_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_MSIX_PBAX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x8380100f0000ll + 8ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a==0))
        return 0x838000ff0000ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("ZIP_MSIX_PBAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_MSIX_PBAX(a) bdk_zip_msix_pbax_t
#define bustype_BDK_ZIP_MSIX_PBAX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_MSIX_PBAX(a) "ZIP_MSIX_PBAX"
#define device_bar_BDK_ZIP_MSIX_PBAX(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_ZIP_MSIX_PBAX(a) (a)
#define arguments_BDK_ZIP_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_msix_vec#_addr
 *
 * ZIP MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the ZIP_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's ZIP_MSIX_VEC()_ADDR, ZIP_MSIX_VEC()_CTL, and corresponding
                                                                 bit of ZIP_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_ZIP_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's ZIP_MSIX_VEC()_ADDR, ZIP_MSIX_VEC()_CTL, and corresponding
                                                                 bit of ZIP_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_ZIP_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_msix_vecx_addr_s cn; */
} bdk_zip_msix_vecx_addr_t;

static inline uint64_t BDK_ZIP_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_MSIX_VECX_ADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=17))
        return 0x838010000000ll + 0x10ll * ((a) & 0x1f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=17))
        return 0x838000f00000ll + 0x10ll * ((a) & 0x1f);
    __bdk_csr_fatal("ZIP_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_MSIX_VECX_ADDR(a) bdk_zip_msix_vecx_addr_t
#define bustype_BDK_ZIP_MSIX_VECX_ADDR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_MSIX_VECX_ADDR(a) "ZIP_MSIX_VECX_ADDR"
#define device_bar_BDK_ZIP_MSIX_VECX_ADDR(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_ZIP_MSIX_VECX_ADDR(a) (a)
#define arguments_BDK_ZIP_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_msix_vec#_ctl
 *
 * ZIP MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the ZIP_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_msix_vecx_ctl_s
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
    /* struct bdk_zip_msix_vecx_ctl_s cn; */
} bdk_zip_msix_vecx_ctl_t;

static inline uint64_t BDK_ZIP_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_MSIX_VECX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=17))
        return 0x838010000008ll + 0x10ll * ((a) & 0x1f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=17))
        return 0x838000f00008ll + 0x10ll * ((a) & 0x1f);
    __bdk_csr_fatal("ZIP_MSIX_VECX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_MSIX_VECX_CTL(a) bdk_zip_msix_vecx_ctl_t
#define bustype_BDK_ZIP_MSIX_VECX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_MSIX_VECX_CTL(a) "ZIP_MSIX_VECX_CTL"
#define device_bar_BDK_ZIP_MSIX_VECX_CTL(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_ZIP_MSIX_VECX_CTL(a) (a)
#define arguments_BDK_ZIP_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_pf_inst_latency_pc
 *
 * ZIP PF Instruction Latency Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_pf_inst_latency_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for an instruction to complete (have the store of
                                                                 ZIP_ZRES_S reach the commit point). Incremented every coprocessor-clock by the
                                                                 number of instructions active in that cycle. This may be divided by
                                                                 ZIP_PF_RD_REQ_PC to determine the average hardware instruction latency. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for an instruction to complete (have the store of
                                                                 ZIP_ZRES_S reach the commit point). Incremented every coprocessor-clock by the
                                                                 number of instructions active in that cycle. This may be divided by
                                                                 ZIP_PF_RD_REQ_PC to determine the average hardware instruction latency. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_pf_inst_latency_pc_s cn; */
} bdk_zip_pf_inst_latency_pc_t;

#define BDK_ZIP_PF_INST_LATENCY_PC BDK_ZIP_PF_INST_LATENCY_PC_FUNC()
static inline uint64_t BDK_ZIP_PF_INST_LATENCY_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_PF_INST_LATENCY_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000410ll;
    __bdk_csr_fatal("ZIP_PF_INST_LATENCY_PC", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_PF_INST_LATENCY_PC bdk_zip_pf_inst_latency_pc_t
#define bustype_BDK_ZIP_PF_INST_LATENCY_PC BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_PF_INST_LATENCY_PC "ZIP_PF_INST_LATENCY_PC"
#define device_bar_BDK_ZIP_PF_INST_LATENCY_PC 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_PF_INST_LATENCY_PC 0
#define arguments_BDK_ZIP_PF_INST_LATENCY_PC -1,-1,-1,-1

/**
 * Register (NCB) zip_pf_inst_req_pc
 *
 * ZIP PF Instruction Request Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_pf_inst_req_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of instructions (ZIP_INST_S) that have started processing. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of instructions (ZIP_INST_S) that have started processing. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_pf_inst_req_pc_s cn; */
} bdk_zip_pf_inst_req_pc_t;

#define BDK_ZIP_PF_INST_REQ_PC BDK_ZIP_PF_INST_REQ_PC_FUNC()
static inline uint64_t BDK_ZIP_PF_INST_REQ_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_PF_INST_REQ_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000400ll;
    __bdk_csr_fatal("ZIP_PF_INST_REQ_PC", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_PF_INST_REQ_PC bdk_zip_pf_inst_req_pc_t
#define bustype_BDK_ZIP_PF_INST_REQ_PC BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_PF_INST_REQ_PC "ZIP_PF_INST_REQ_PC"
#define device_bar_BDK_ZIP_PF_INST_REQ_PC 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_PF_INST_REQ_PC 0
#define arguments_BDK_ZIP_PF_INST_REQ_PC -1,-1,-1,-1

/**
 * Register (NCB) zip_pf_que#_gmctl
 *
 * ZIP Queue Guest Machine Control Register
 * This register configures queues.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_pf_quex_gmctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t gmid                  : 16; /**< [ 15:  0](RO) Reserved. INTERNAL: Guest machine identifier. The GMID to send to FPA for all
                                                                 buffer free, or to SSO for all submit work operations initiated by this queue.
                                                                 Must be non-zero or requests will be dropped. */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](RO) Reserved. INTERNAL: Guest machine identifier. The GMID to send to FPA for all
                                                                 buffer free, or to SSO for all submit work operations initiated by this queue.
                                                                 Must be non-zero or requests will be dropped. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_pf_quex_gmctl_s cn; */
} bdk_zip_pf_quex_gmctl_t;

static inline uint64_t BDK_ZIP_PF_QUEX_GMCTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_PF_QUEX_GMCTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838008000010ll + 0x100000ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_PF_QUEX_GMCTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_PF_QUEX_GMCTL(a) bdk_zip_pf_quex_gmctl_t
#define bustype_BDK_ZIP_PF_QUEX_GMCTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_PF_QUEX_GMCTL(a) "ZIP_PF_QUEX_GMCTL"
#define device_bar_BDK_ZIP_PF_QUEX_GMCTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_PF_QUEX_GMCTL(a) (a)
#define arguments_BDK_ZIP_PF_QUEX_GMCTL(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_pf_rd_latency_pc
 *
 * ZIP PF Read Latency Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_pf_rd_latency_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for L2C read returns. Incremented every
                                                                 coprocessor-clock by the number of transactions outstanding in that cycle. This
                                                                 may be divided by ZIP_PF_RD_REQ_PC to determine the average read latency. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for L2C read returns. Incremented every
                                                                 coprocessor-clock by the number of transactions outstanding in that cycle. This
                                                                 may be divided by ZIP_PF_RD_REQ_PC to determine the average read latency. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_pf_rd_latency_pc_s cn; */
} bdk_zip_pf_rd_latency_pc_t;

#define BDK_ZIP_PF_RD_LATENCY_PC BDK_ZIP_PF_RD_LATENCY_PC_FUNC()
static inline uint64_t BDK_ZIP_PF_RD_LATENCY_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_PF_RD_LATENCY_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000430ll;
    __bdk_csr_fatal("ZIP_PF_RD_LATENCY_PC", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_PF_RD_LATENCY_PC bdk_zip_pf_rd_latency_pc_t
#define bustype_BDK_ZIP_PF_RD_LATENCY_PC BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_PF_RD_LATENCY_PC "ZIP_PF_RD_LATENCY_PC"
#define device_bar_BDK_ZIP_PF_RD_LATENCY_PC 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_PF_RD_LATENCY_PC 0
#define arguments_BDK_ZIP_PF_RD_LATENCY_PC -1,-1,-1,-1

/**
 * Register (NCB) zip_pf_rd_req_pc
 *
 * ZIP PF Read Request Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_pf_rd_req_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of L2C read requests. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of L2C read requests. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_pf_rd_req_pc_s cn; */
} bdk_zip_pf_rd_req_pc_t;

#define BDK_ZIP_PF_RD_REQ_PC BDK_ZIP_PF_RD_REQ_PC_FUNC()
static inline uint64_t BDK_ZIP_PF_RD_REQ_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_PF_RD_REQ_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000420ll;
    __bdk_csr_fatal("ZIP_PF_RD_REQ_PC", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_PF_RD_REQ_PC bdk_zip_pf_rd_req_pc_t
#define bustype_BDK_ZIP_PF_RD_REQ_PC BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_PF_RD_REQ_PC "ZIP_PF_RD_REQ_PC"
#define device_bar_BDK_ZIP_PF_RD_REQ_PC 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_PF_RD_REQ_PC 0
#define arguments_BDK_ZIP_PF_RD_REQ_PC -1,-1,-1,-1

/**
 * Register (NCB) zip_que#_done
 *
 * ZIP Queue Done Count Registers
 * These registers contain the per-queue instruction done count.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_quex_done_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t done                  : 20; /**< [ 19:  0](R/W/H) Done count. When ZIP_INST_S[DONEINT] set and that instruction completes,
                                                                 ZIP_QUE()_DONE[DONE] is incremented when the instruction finishes. Write to this
                                                                 field are for diagnostic use only; instead software writes ZIP_QUE()_DONE_ACK[DONE]
                                                                 with the number of decrements for this field.

                                                                 Interrupts are sent as follows:

                                                                 * When ZIP_QUE()_DONE[DONE] = 0, then no results are pending, the interrupt coalescing
                                                                 timer is held to zero, and an interrupt is not sent.

                                                                 * When ZIP_QUE()_DONE[DONE] != 0, then the interrupt coalescing timer counts. If
                                                                 the counter is >= ZIP_QUE()_DONE_WAIT[TIME_WAIT]*1024, or ZIP_QUE()_DONE[DONE]
                                                                 >= ZIP_QUE()_DONE_WAIT[NUM_WAIT], i.e.enough time has passed or enough results
                                                                 have arrived, then the interrupt is sent.  Otherwise, it is not sent due to
                                                                 coalescing.

                                                                 * When ZIP_QUE()_DONE_ACK is written, the interrupt coalescing timer restarts.
                                                                 Note after decrementing this interrupt equation is recomputed, for example if
                                                                 ZIP_QUE()_DONE[DONE] >= ZIP_QUE()_DONE_WAIT[NUM_WAIT] and the timer is zero, the
                                                                 interrupt will be resent immediately.  (This covers the race case between
                                                                 software acknowledging an interrupt and a result returning.)

                                                                 * When ZIP_QUE()_DONE_ENA_W1S[DONE_ENA] = 0, interrupts are not sent, but the counting
                                                                 described above still occurs.

                                                                 Since ZIP instructions within a queue can complete out-of-order when the queue is mapped
                                                                 to both ZIP engines, if software is using completion interrupts the suggested scheme is to
                                                                 request a DONEINT on each request, and when an interrupt arrives perform a "greedy" scan
                                                                 for completions; even if a later command is acknowledged first this will not result in
                                                                 missing a completion. Software could also use ZIP_ZRES_S[DONEINT] to check when
                                                                 instruction needs to be counted into ZIP_QUE()_DONE/ZIP_QUE()_DONE_ACK. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 20; /**< [ 19:  0](R/W/H) Done count. When ZIP_INST_S[DONEINT] set and that instruction completes,
                                                                 ZIP_QUE()_DONE[DONE] is incremented when the instruction finishes. Write to this
                                                                 field are for diagnostic use only; instead software writes ZIP_QUE()_DONE_ACK[DONE]
                                                                 with the number of decrements for this field.

                                                                 Interrupts are sent as follows:

                                                                 * When ZIP_QUE()_DONE[DONE] = 0, then no results are pending, the interrupt coalescing
                                                                 timer is held to zero, and an interrupt is not sent.

                                                                 * When ZIP_QUE()_DONE[DONE] != 0, then the interrupt coalescing timer counts. If
                                                                 the counter is >= ZIP_QUE()_DONE_WAIT[TIME_WAIT]*1024, or ZIP_QUE()_DONE[DONE]
                                                                 >= ZIP_QUE()_DONE_WAIT[NUM_WAIT], i.e.enough time has passed or enough results
                                                                 have arrived, then the interrupt is sent.  Otherwise, it is not sent due to
                                                                 coalescing.

                                                                 * When ZIP_QUE()_DONE_ACK is written, the interrupt coalescing timer restarts.
                                                                 Note after decrementing this interrupt equation is recomputed, for example if
                                                                 ZIP_QUE()_DONE[DONE] >= ZIP_QUE()_DONE_WAIT[NUM_WAIT] and the timer is zero, the
                                                                 interrupt will be resent immediately.  (This covers the race case between
                                                                 software acknowledging an interrupt and a result returning.)

                                                                 * When ZIP_QUE()_DONE_ENA_W1S[DONE_ENA] = 0, interrupts are not sent, but the counting
                                                                 described above still occurs.

                                                                 Since ZIP instructions within a queue can complete out-of-order when the queue is mapped
                                                                 to both ZIP engines, if software is using completion interrupts the suggested scheme is to
                                                                 request a DONEINT on each request, and when an interrupt arrives perform a "greedy" scan
                                                                 for completions; even if a later command is acknowledged first this will not result in
                                                                 missing a completion. Software could also use ZIP_ZRES_S[DONEINT] to check when
                                                                 instruction needs to be counted into ZIP_QUE()_DONE/ZIP_QUE()_DONE_ACK. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_quex_done_s cn; */
} bdk_zip_quex_done_t;

static inline uint64_t BDK_ZIP_QUEX_DONE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_DONE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000002000ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000002000ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_QUEX_DONE", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUEX_DONE(a) bdk_zip_quex_done_t
#define bustype_BDK_ZIP_QUEX_DONE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUEX_DONE(a) "ZIP_QUEX_DONE"
#define device_bar_BDK_ZIP_QUEX_DONE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUEX_DONE(a) (a)
#define arguments_BDK_ZIP_QUEX_DONE(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_que#_done_ack
 *
 * ZIP Queue Done Count Ack Registers
 * This register is written by software to acknowledge interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_quex_done_ack_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t done_ack              : 20; /**< [ 19:  0](R/W/H) Number of decrements to ZIP_QUE()_DONE[DONE]. Reads ZIP_QUE()_DONE[DONE].

                                                                 Written by software to acknowledge interrupts. If ZIP_QUE()_DONE[DONE] is still
                                                                 non-zero the interrupt will be re-sent if the conditions described in
                                                                 ZIP_QUE()_DONE[DONE] are satified. */
#else /* Word 0 - Little Endian */
        uint64_t done_ack              : 20; /**< [ 19:  0](R/W/H) Number of decrements to ZIP_QUE()_DONE[DONE]. Reads ZIP_QUE()_DONE[DONE].

                                                                 Written by software to acknowledge interrupts. If ZIP_QUE()_DONE[DONE] is still
                                                                 non-zero the interrupt will be re-sent if the conditions described in
                                                                 ZIP_QUE()_DONE[DONE] are satified. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_quex_done_ack_s cn; */
} bdk_zip_quex_done_ack_t;

static inline uint64_t BDK_ZIP_QUEX_DONE_ACK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_DONE_ACK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000002200ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000002200ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_QUEX_DONE_ACK", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUEX_DONE_ACK(a) bdk_zip_quex_done_ack_t
#define bustype_BDK_ZIP_QUEX_DONE_ACK(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUEX_DONE_ACK(a) "ZIP_QUEX_DONE_ACK"
#define device_bar_BDK_ZIP_QUEX_DONE_ACK(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUEX_DONE_ACK(a) (a)
#define arguments_BDK_ZIP_QUEX_DONE_ACK(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_que#_done_ena_w1c
 *
 * ZIP Queue Done Interrupt Enable Clear Registers
 * Write 1 to these registers will disable the DONEINT interrupt for the queue.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_quex_done_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done_ena              : 1;  /**< [  0:  0](R/W1C/H) Write 1 will disable DONEINT for this queue. Write 0 has no effect.
                                                                 Read will return the DONEINT enable bit. */
#else /* Word 0 - Little Endian */
        uint64_t done_ena              : 1;  /**< [  0:  0](R/W1C/H) Write 1 will disable DONEINT for this queue. Write 0 has no effect.
                                                                 Read will return the DONEINT enable bit. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_quex_done_ena_w1c_s cn; */
} bdk_zip_quex_done_ena_w1c_t;

static inline uint64_t BDK_ZIP_QUEX_DONE_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_DONE_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000002600ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000002600ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_QUEX_DONE_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUEX_DONE_ENA_W1C(a) bdk_zip_quex_done_ena_w1c_t
#define bustype_BDK_ZIP_QUEX_DONE_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUEX_DONE_ENA_W1C(a) "ZIP_QUEX_DONE_ENA_W1C"
#define device_bar_BDK_ZIP_QUEX_DONE_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUEX_DONE_ENA_W1C(a) (a)
#define arguments_BDK_ZIP_QUEX_DONE_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_que#_done_ena_w1s
 *
 * ZIP Queue Done Interrupt Enable Set Registers
 * Write 1 to these registers will enable the DONEINT interrupt for the queue.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_quex_done_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done_ena              : 1;  /**< [  0:  0](R/W1S/H) Write 1 will enable DONEINT for this queue. Write 0 has no effect.
                                                                 Read will return the enable bit. */
#else /* Word 0 - Little Endian */
        uint64_t done_ena              : 1;  /**< [  0:  0](R/W1S/H) Write 1 will enable DONEINT for this queue. Write 0 has no effect.
                                                                 Read will return the enable bit. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_quex_done_ena_w1s_s cn; */
} bdk_zip_quex_done_ena_w1s_t;

static inline uint64_t BDK_ZIP_QUEX_DONE_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_DONE_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000002400ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000002400ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_QUEX_DONE_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUEX_DONE_ENA_W1S(a) bdk_zip_quex_done_ena_w1s_t
#define bustype_BDK_ZIP_QUEX_DONE_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUEX_DONE_ENA_W1S(a) "ZIP_QUEX_DONE_ENA_W1S"
#define device_bar_BDK_ZIP_QUEX_DONE_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUEX_DONE_ENA_W1S(a) (a)
#define arguments_BDK_ZIP_QUEX_DONE_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_que#_done_wait
 *
 * ZIP Queue Done Interrupt Coalescing Wait Registers
 * Specifies the per queue interrupt coalescing settings.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_quex_done_wait_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t time_wait             : 16; /**< [ 47: 32](R/W) Time hold-off.  When ZIP_QUE(0..7)_DONE[DONE] = 0, or ZIP_QUE(0..7)_DONE_ACK is written a
                                                                 timer
                                                                 is cleared.  When the timer reaches [TIME_WAIT]*1024 then interrupt coalescing ends;
                                                                 see ZIP_QUE(0..7)_DONE[DONE]. If zero, time coalescing is disabled. */
        uint64_t reserved_20_31        : 12;
        uint64_t num_wait              : 20; /**< [ 19:  0](R/W) Number of messages hold-off.  When ZIP_QUE(0..7)_DONE[DONE] >= [NUM_WAIT] then interrupt
                                                                 coalescing
                                                                 ends; see ZIP_QUE(0..7)_DONE[DONE]. If zero, message number coalescing is
                                                                 disabled. */
#else /* Word 0 - Little Endian */
        uint64_t num_wait              : 20; /**< [ 19:  0](R/W) Number of messages hold-off.  When ZIP_QUE(0..7)_DONE[DONE] >= [NUM_WAIT] then interrupt
                                                                 coalescing
                                                                 ends; see ZIP_QUE(0..7)_DONE[DONE]. If zero, message number coalescing is
                                                                 disabled. */
        uint64_t reserved_20_31        : 12;
        uint64_t time_wait             : 16; /**< [ 47: 32](R/W) Time hold-off.  When ZIP_QUE(0..7)_DONE[DONE] = 0, or ZIP_QUE(0..7)_DONE_ACK is written a
                                                                 timer
                                                                 is cleared.  When the timer reaches [TIME_WAIT]*1024 then interrupt coalescing ends;
                                                                 see ZIP_QUE(0..7)_DONE[DONE]. If zero, time coalescing is disabled. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_quex_done_wait_s cn; */
} bdk_zip_quex_done_wait_t;

static inline uint64_t BDK_ZIP_QUEX_DONE_WAIT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_DONE_WAIT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000002800ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000002800ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_QUEX_DONE_WAIT", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUEX_DONE_WAIT(a) bdk_zip_quex_done_wait_t
#define bustype_BDK_ZIP_QUEX_DONE_WAIT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUEX_DONE_WAIT(a) "ZIP_QUEX_DONE_WAIT"
#define device_bar_BDK_ZIP_QUEX_DONE_WAIT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUEX_DONE_WAIT(a) (a)
#define arguments_BDK_ZIP_QUEX_DONE_WAIT(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_que#_doorbell
 *
 * ZIP Queue Doorbell Registers
 * Doorbells for the ZIP instruction queues.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_quex_doorbell_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t dbell_cnt             : 20; /**< [ 19:  0](R/W/H) Number of instructions to add to the ZIP instruction doorbell count. */
#else /* Word 0 - Little Endian */
        uint64_t dbell_cnt             : 20; /**< [ 19:  0](R/W/H) Number of instructions to add to the ZIP instruction doorbell count. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_quex_doorbell_s cn; */
} bdk_zip_quex_doorbell_t;

static inline uint64_t BDK_ZIP_QUEX_DOORBELL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_DOORBELL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000004000ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000004000ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_QUEX_DOORBELL", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUEX_DOORBELL(a) bdk_zip_quex_doorbell_t
#define bustype_BDK_ZIP_QUEX_DOORBELL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUEX_DOORBELL(a) "ZIP_QUEX_DOORBELL"
#define device_bar_BDK_ZIP_QUEX_DOORBELL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUEX_DOORBELL(a) (a)
#define arguments_BDK_ZIP_QUEX_DOORBELL(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_que#_err_ena_w1c
 *
 * ZIP Queue Error Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_quex_err_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t cto                   : 1;  /**< [ 16: 16](R/W1C/H) Added in pass 2.0. Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[CTO]. */
        uint64_t reserved_5_15         : 11;
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[DOVF]. */
#else /* Word 0 - Little Endian */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t reserved_5_15         : 11;
        uint64_t cto                   : 1;  /**< [ 16: 16](R/W1C/H) Added in pass 2.0. Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[CTO]. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    struct bdk_zip_quex_err_ena_w1c_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[DOVF]. */
#else /* Word 0 - Little Endian */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } cn83xx;
    /* struct bdk_zip_quex_err_ena_w1c_s cn88xxp2; */
    struct bdk_zip_quex_err_ena_w1c_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t reserved_16           : 1;
        uint64_t reserved_5_15         : 11;
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[DOVF]. */
#else /* Word 0 - Little Endian */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t reserved_5_15         : 11;
        uint64_t reserved_16           : 1;
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_zip_quex_err_ena_w1c_t;

static inline uint64_t BDK_ZIP_QUEX_ERR_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_ERR_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000003600ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000003600ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_QUEX_ERR_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUEX_ERR_ENA_W1C(a) bdk_zip_quex_err_ena_w1c_t
#define bustype_BDK_ZIP_QUEX_ERR_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUEX_ERR_ENA_W1C(a) "ZIP_QUEX_ERR_ENA_W1C"
#define device_bar_BDK_ZIP_QUEX_ERR_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUEX_ERR_ENA_W1C(a) (a)
#define arguments_BDK_ZIP_QUEX_ERR_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_que#_err_ena_w1s
 *
 * ZIP Queue Error Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_quex_err_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t cto                   : 1;  /**< [ 16: 16](R/W1S/H) Added in pass 2.0. Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[CTO]. */
        uint64_t reserved_5_15         : 11;
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[DOVF]. */
#else /* Word 0 - Little Endian */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t reserved_5_15         : 11;
        uint64_t cto                   : 1;  /**< [ 16: 16](R/W1S/H) Added in pass 2.0. Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[CTO]. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    struct bdk_zip_quex_err_ena_w1s_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[DOVF]. */
#else /* Word 0 - Little Endian */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } cn83xx;
    /* struct bdk_zip_quex_err_ena_w1s_s cn88xxp2; */
    struct bdk_zip_quex_err_ena_w1s_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t reserved_16           : 1;
        uint64_t reserved_5_15         : 11;
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[DOVF]. */
#else /* Word 0 - Little Endian */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t reserved_5_15         : 11;
        uint64_t reserved_16           : 1;
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_zip_quex_err_ena_w1s_t;

static inline uint64_t BDK_ZIP_QUEX_ERR_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_ERR_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000003400ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000003400ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_QUEX_ERR_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUEX_ERR_ENA_W1S(a) bdk_zip_quex_err_ena_w1s_t
#define bustype_BDK_ZIP_QUEX_ERR_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUEX_ERR_ENA_W1S(a) "ZIP_QUEX_ERR_ENA_W1S"
#define device_bar_BDK_ZIP_QUEX_ERR_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUEX_ERR_ENA_W1S(a) (a)
#define arguments_BDK_ZIP_QUEX_ERR_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_que#_err_int
 *
 * ZIP Queue Error Interrupt Register
 * These registers contain the per-queue error interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_quex_err_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t cto                   : 1;  /**< [ 16: 16](R/W1C/H) Core time out detected. Added pass 2. */
        uint64_t reserved_5_15         : 11;
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1C/H) SRAM ECC double-bit error. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) NCB write response error. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1C/H) NCB read response error. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1C/H) Instruction NCB read response error. */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1C/H) Doorbell overflow. */
#else /* Word 0 - Little Endian */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1C/H) Doorbell overflow. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1C/H) Instruction NCB read response error. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1C/H) NCB read response error. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) NCB write response error. */
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1C/H) SRAM ECC double-bit error. */
        uint64_t reserved_5_15         : 11;
        uint64_t cto                   : 1;  /**< [ 16: 16](R/W1C/H) Core time out detected. Added pass 2. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    struct bdk_zip_quex_err_int_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1C/H) SRAM ECC double-bit error. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) NCB write response error. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1C/H) NCB read response error. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1C/H) Instruction NCB read response error. */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1C/H) Doorbell overflow. */
#else /* Word 0 - Little Endian */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1C/H) Doorbell overflow. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1C/H) Instruction NCB read response error. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1C/H) NCB read response error. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) NCB write response error. */
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1C/H) SRAM ECC double-bit error. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } cn83xx;
    /* struct bdk_zip_quex_err_int_s cn88xxp2; */
    struct bdk_zip_quex_err_int_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t reserved_16           : 1;
        uint64_t reserved_5_15         : 11;
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1C/H) SRAM ECC double-bit error. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) NCB write response error. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1C/H) NCB read response error. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1C/H) Instruction NCB read response error. */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1C/H) Doorbell overflow. */
#else /* Word 0 - Little Endian */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1C/H) Doorbell overflow. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1C/H) Instruction NCB read response error. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1C/H) NCB read response error. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1C/H) NCB write response error. */
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1C/H) SRAM ECC double-bit error. */
        uint64_t reserved_5_15         : 11;
        uint64_t reserved_16           : 1;
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_zip_quex_err_int_t;

static inline uint64_t BDK_ZIP_QUEX_ERR_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_ERR_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000003000ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000003000ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_QUEX_ERR_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUEX_ERR_INT(a) bdk_zip_quex_err_int_t
#define bustype_BDK_ZIP_QUEX_ERR_INT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUEX_ERR_INT(a) "ZIP_QUEX_ERR_INT"
#define device_bar_BDK_ZIP_QUEX_ERR_INT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUEX_ERR_INT(a) (a)
#define arguments_BDK_ZIP_QUEX_ERR_INT(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_que#_err_int_w1s
 *
 * ZIP Queue Error Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_quex_err_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t cto                   : 1;  /**< [ 16: 16](R/W1S/H) Added in pass 2.0. Reads or sets ZIP_QUE(0..7)_ERR_INT[CTO]. */
        uint64_t reserved_5_15         : 11;
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[DOVF]. */
#else /* Word 0 - Little Endian */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t reserved_5_15         : 11;
        uint64_t cto                   : 1;  /**< [ 16: 16](R/W1S/H) Added in pass 2.0. Reads or sets ZIP_QUE(0..7)_ERR_INT[CTO]. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    struct bdk_zip_quex_err_int_w1s_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[DOVF]. */
#else /* Word 0 - Little Endian */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } cn83xx;
    /* struct bdk_zip_quex_err_int_w1s_s cn88xxp2; */
    struct bdk_zip_quex_err_int_w1s_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t reserved_16           : 1;
        uint64_t reserved_5_15         : 11;
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[DOVF]. */
#else /* Word 0 - Little Endian */
        uint64_t dovf                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[DOVF]. */
        uint64_t irde                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[IRDE]. */
        uint64_t nrrp                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[NRRP]. */
        uint64_t nwrp                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[NWRP]. */
        uint64_t mdbe                  : 1;  /**< [  4:  4](R/W1S/H) Reads or sets ZIP_QUE(0..7)_ERR_INT[MDBE]. */
        uint64_t reserved_5_15         : 11;
        uint64_t reserved_16           : 1;
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_zip_quex_err_int_w1s_t;

static inline uint64_t BDK_ZIP_QUEX_ERR_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_ERR_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000003200ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000003200ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_QUEX_ERR_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUEX_ERR_INT_W1S(a) bdk_zip_quex_err_int_w1s_t
#define bustype_BDK_ZIP_QUEX_ERR_INT_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUEX_ERR_INT_W1S(a) "ZIP_QUEX_ERR_INT_W1S"
#define device_bar_BDK_ZIP_QUEX_ERR_INT_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUEX_ERR_INT_W1S(a) (a)
#define arguments_BDK_ZIP_QUEX_ERR_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_que#_gcfg
 *
 * ZIP Queue Generation Configuration Registers
 * These registers reflect status of the ZIP instruction queues and are for debug use only.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_quex_gcfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t iqb_ldwb              : 1;  /**< [  3:  3](R/W) Load don't write back.

                                                                 0 = The hardware issues NCB regular load towards the cache, which will cause the
                                                                 line to be written back before being replaced.

                                                                 1 = The hardware issues NCB LDWB read-and-invalidate command towards the cache
                                                                 when fetching the last word of instructions; as a result the line will not be
                                                                 written back when replaced.  This improves performance, but software must not
                                                                 read the instructions after they are posted to the hardware.

                                                                 Partial cache line reads always use LDI. */
        uint64_t cbw_sty               : 1;  /**< [  2:  2](R/W) When set, a context cache block write will use STY. When clear, a context write will use STF. */
        uint64_t l2ld_cmd              : 2;  /**< [  1:  0](R/W) Which NCB load command to use for reading gather pointers, context, history and input
                                                                 data.
                                                                 0x0 = LDD.
                                                                 0x1 = LDI.
                                                                 0x2 = LDE.
                                                                 0x3 = LDY. */
#else /* Word 0 - Little Endian */
        uint64_t l2ld_cmd              : 2;  /**< [  1:  0](R/W) Which NCB load command to use for reading gather pointers, context, history and input
                                                                 data.
                                                                 0x0 = LDD.
                                                                 0x1 = LDI.
                                                                 0x2 = LDE.
                                                                 0x3 = LDY. */
        uint64_t cbw_sty               : 1;  /**< [  2:  2](R/W) When set, a context cache block write will use STY. When clear, a context write will use STF. */
        uint64_t iqb_ldwb              : 1;  /**< [  3:  3](R/W) Load don't write back.

                                                                 0 = The hardware issues NCB regular load towards the cache, which will cause the
                                                                 line to be written back before being replaced.

                                                                 1 = The hardware issues NCB LDWB read-and-invalidate command towards the cache
                                                                 when fetching the last word of instructions; as a result the line will not be
                                                                 written back when replaced.  This improves performance, but software must not
                                                                 read the instructions after they are posted to the hardware.

                                                                 Partial cache line reads always use LDI. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_quex_gcfg_s cn; */
} bdk_zip_quex_gcfg_t;

static inline uint64_t BDK_ZIP_QUEX_GCFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_GCFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000001a00ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000001a00ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_QUEX_GCFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUEX_GCFG(a) bdk_zip_quex_gcfg_t
#define bustype_BDK_ZIP_QUEX_GCFG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUEX_GCFG(a) "ZIP_QUEX_GCFG"
#define device_bar_BDK_ZIP_QUEX_GCFG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUEX_GCFG(a) (a)
#define arguments_BDK_ZIP_QUEX_GCFG(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_que#_map
 *
 * ZIP Queue Mapping Registers
 * These registers control how each instruction queue maps to ZIP cores.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_quex_map_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t zce                   : 6;  /**< [  5:  0](R/W) ZIP core enable. Controls the logical instruction queue can be serviced by which ZIP core.
                                                                 Setting ZCE to 0 effectively disables the queue from being served (however the instruction
                                                                 can still be fetched).
                                                                 _ ZCE<1> = 1: ZIP core 1 can serve the queue.
                                                                 _ ZCE<0> = 1: ZIP core 0 can serve the queue. */
#else /* Word 0 - Little Endian */
        uint64_t zce                   : 6;  /**< [  5:  0](R/W) ZIP core enable. Controls the logical instruction queue can be serviced by which ZIP core.
                                                                 Setting ZCE to 0 effectively disables the queue from being served (however the instruction
                                                                 can still be fetched).
                                                                 _ ZCE<1> = 1: ZIP core 1 can serve the queue.
                                                                 _ ZCE<0> = 1: ZIP core 0 can serve the queue. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    struct bdk_zip_quex_map_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t zce                   : 2;  /**< [  1:  0](R/W) ZIP core enable. Controls the logical instruction queue can be serviced by which ZIP core.
                                                                 Setting ZCE to 0 effectively disables the queue from being served (however the instruction
                                                                 can still be fetched).
                                                                 _ ZCE<1> = 1: ZIP core 1 can serve the queue.
                                                                 _ ZCE<0> = 1: ZIP core 0 can serve the queue. */
#else /* Word 0 - Little Endian */
        uint64_t zce                   : 2;  /**< [  1:  0](R/W) ZIP core enable. Controls the logical instruction queue can be serviced by which ZIP core.
                                                                 Setting ZCE to 0 effectively disables the queue from being served (however the instruction
                                                                 can still be fetched).
                                                                 _ ZCE<1> = 1: ZIP core 1 can serve the queue.
                                                                 _ ZCE<0> = 1: ZIP core 0 can serve the queue. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } cn88xx;
    struct bdk_zip_quex_map_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t zce                   : 6;  /**< [  5:  0](R/W) ZIP core enable. Controls the logical instruction queue can be serviced by which ZIP core.
                                                                 Setting ZCE to 0 effectively disables the queue from being served (however the instruction
                                                                 can still be fetched). Hardware automatically selects decompression cores for
                                                                 decompression, and compression cores for compression.
                                                                 _ ZCE<5> = 1: ZIP core 5 can serve the queue.
                                                                 _ ZCE<4> = 1: ZIP core 4 can serve the queue.
                                                                 _ ZCE<3> = 1: ZIP core 3 can serve the queue.
                                                                 _ ZCE<2> = 1: ZIP core 2 can serve the queue.
                                                                 _ ZCE<1> = 1: ZIP core 1 can serve the queue.
                                                                 _ ZCE<0> = 1: ZIP core 0 can serve the queue. */
#else /* Word 0 - Little Endian */
        uint64_t zce                   : 6;  /**< [  5:  0](R/W) ZIP core enable. Controls the logical instruction queue can be serviced by which ZIP core.
                                                                 Setting ZCE to 0 effectively disables the queue from being served (however the instruction
                                                                 can still be fetched). Hardware automatically selects decompression cores for
                                                                 decompression, and compression cores for compression.
                                                                 _ ZCE<5> = 1: ZIP core 5 can serve the queue.
                                                                 _ ZCE<4> = 1: ZIP core 4 can serve the queue.
                                                                 _ ZCE<3> = 1: ZIP core 3 can serve the queue.
                                                                 _ ZCE<2> = 1: ZIP core 2 can serve the queue.
                                                                 _ ZCE<1> = 1: ZIP core 1 can serve the queue.
                                                                 _ ZCE<0> = 1: ZIP core 0 can serve the queue. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } cn83xx;
} bdk_zip_quex_map_t;

static inline uint64_t BDK_ZIP_QUEX_MAP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_MAP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000001400ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000001400ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_QUEX_MAP", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUEX_MAP(a) bdk_zip_quex_map_t
#define bustype_BDK_ZIP_QUEX_MAP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUEX_MAP(a) "ZIP_QUEX_MAP"
#define device_bar_BDK_ZIP_QUEX_MAP(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUEX_MAP(a) (a)
#define arguments_BDK_ZIP_QUEX_MAP(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_que#_sbuf_addr
 *
 * ZIP Queue Starting Buffer Address Registers
 * These registers set the buffer parameters for the instruction queues. When quiescent (i.e.
 * outstanding doorbell count is 0), it is safe to rewrite this register to effectively reset the
 * command buffer state machine. These registers must be programmed after SW programms the
 * corresponding ZIP_QUE(0..7)_SBUF_CTL.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_quex_sbuf_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) Instruction buffer pointer bits <41:7> (128-byte aligned). When written, it is the initial
                                                                 buffer starting IOVA; when read, it is the next read pointer IOVA to be requested from
                                                                 L2C.
                                                                 The PTR field is overwritten with the next pointer each time that the command buffer
                                                                 segment is exhausted. New commands will then be read from the newly specified command
                                                                 buffer pointer. */
        uint64_t off                   : 7;  /**< [  6:  0](RO/H) When write, the value is ignored. When read, the returned value is the offset of the next
                                                                 read pointer. */
#else /* Word 0 - Little Endian */
        uint64_t off                   : 7;  /**< [  6:  0](RO/H) When write, the value is ignored. When read, the returned value is the offset of the next
                                                                 read pointer. */
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) Instruction buffer pointer bits <41:7> (128-byte aligned). When written, it is the initial
                                                                 buffer starting IOVA; when read, it is the next read pointer IOVA to be requested from
                                                                 L2C.
                                                                 The PTR field is overwritten with the next pointer each time that the command buffer
                                                                 segment is exhausted. New commands will then be read from the newly specified command
                                                                 buffer pointer. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_quex_sbuf_addr_s cn; */
} bdk_zip_quex_sbuf_addr_t;

static inline uint64_t BDK_ZIP_QUEX_SBUF_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_SBUF_ADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000001000ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000001000ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_QUEX_SBUF_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUEX_SBUF_ADDR(a) bdk_zip_quex_sbuf_addr_t
#define bustype_BDK_ZIP_QUEX_SBUF_ADDR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUEX_SBUF_ADDR(a) "ZIP_QUEX_SBUF_ADDR"
#define device_bar_BDK_ZIP_QUEX_SBUF_ADDR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUEX_SBUF_ADDR(a) (a)
#define arguments_BDK_ZIP_QUEX_SBUF_ADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_que#_sbuf_ctl
 *
 * ZIP Queue Buffer Parameter Registers
 * These registers set the buffer parameters for the instruction queues. When quiescent (i.e.
 * outstanding doorbell count is 0), it is safe to rewrite this register to effectively reset the
 * command buffer state machine. These registers must be programmed before SW programms the
 * corresponding ZIP_QUE(0..7)_SBUF_ADDR.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_quex_sbuf_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_45_63        : 19;
        uint64_t size                  : 13; /**< [ 44: 32](R/W) Command-buffer size, in number of 64-bit words per command buffer segment. */
        uint64_t inst_be               : 1;  /**< [ 31: 31](R/W) Instruction big endian control. When set, instructions are storaged in big endian format
                                                                 in
                                                                 memory. */
        uint64_t inst_free             : 1;  /**< [ 30: 30](R/W) Instruction FPA free. When set, when CPT reaches the end of an instruction
                                                                 chunk, that chunk will be freed to the FPA. */
        uint64_t reserved_24_29        : 6;
        uint64_t stream_id             : 8;  /**< [ 23: 16](R/W) STREAM_ID is the lower 8-bits of stream ID for the queue. */
        uint64_t reserved_12_15        : 4;
        uint64_t aura                  : 12; /**< [ 11:  0](R/W) Guest-aura for returning this queue's instruction-chunk buffers to FPA.
                                                                 Only used when [INST_FREE] is set. */
#else /* Word 0 - Little Endian */
        uint64_t aura                  : 12; /**< [ 11:  0](R/W) Guest-aura for returning this queue's instruction-chunk buffers to FPA.
                                                                 Only used when [INST_FREE] is set. */
        uint64_t reserved_12_15        : 4;
        uint64_t stream_id             : 8;  /**< [ 23: 16](R/W) STREAM_ID is the lower 8-bits of stream ID for the queue. */
        uint64_t reserved_24_29        : 6;
        uint64_t inst_free             : 1;  /**< [ 30: 30](R/W) Instruction FPA free. When set, when CPT reaches the end of an instruction
                                                                 chunk, that chunk will be freed to the FPA. */
        uint64_t inst_be               : 1;  /**< [ 31: 31](R/W) Instruction big endian control. When set, instructions are storaged in big endian format
                                                                 in
                                                                 memory. */
        uint64_t size                  : 13; /**< [ 44: 32](R/W) Command-buffer size, in number of 64-bit words per command buffer segment. */
        uint64_t reserved_45_63        : 19;
#endif /* Word 0 - End */
    } s;
    struct bdk_zip_quex_sbuf_ctl_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_45_63        : 19;
        uint64_t size                  : 13; /**< [ 44: 32](R/W) Command-buffer size, in number of 64-bit words per command buffer segment. */
        uint64_t inst_be               : 1;  /**< [ 31: 31](R/W) Instruction big endian control. When set, instructions are storaged in big endian format
                                                                 in
                                                                 memory. */
        uint64_t reserved_24_30        : 7;
        uint64_t stream_id             : 8;  /**< [ 23: 16](R/W) STREAM_ID is the lower 8-bits of stream ID for the queue. */
        uint64_t reserved_12_15        : 4;
        uint64_t aura                  : 12; /**< [ 11:  0](RAZ) Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t aura                  : 12; /**< [ 11:  0](RAZ) Reserved. */
        uint64_t reserved_12_15        : 4;
        uint64_t stream_id             : 8;  /**< [ 23: 16](R/W) STREAM_ID is the lower 8-bits of stream ID for the queue. */
        uint64_t reserved_24_30        : 7;
        uint64_t inst_be               : 1;  /**< [ 31: 31](R/W) Instruction big endian control. When set, instructions are storaged in big endian format
                                                                 in
                                                                 memory. */
        uint64_t size                  : 13; /**< [ 44: 32](R/W) Command-buffer size, in number of 64-bit words per command buffer segment. */
        uint64_t reserved_45_63        : 19;
#endif /* Word 0 - End */
    } cn88xx;
    /* struct bdk_zip_quex_sbuf_ctl_s cn83xx; */
} bdk_zip_quex_sbuf_ctl_t;

static inline uint64_t BDK_ZIP_QUEX_SBUF_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUEX_SBUF_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x838000001200ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=7))
        return 0x838000001200ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("ZIP_QUEX_SBUF_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUEX_SBUF_CTL(a) bdk_zip_quex_sbuf_ctl_t
#define bustype_BDK_ZIP_QUEX_SBUF_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUEX_SBUF_CTL(a) "ZIP_QUEX_SBUF_CTL"
#define device_bar_BDK_ZIP_QUEX_SBUF_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUEX_SBUF_CTL(a) (a)
#define arguments_BDK_ZIP_QUEX_SBUF_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) zip_que_ena
 *
 * ZIP Queue Enable Register
 * If a queue is disabled, ZIP_CTL stops fetching instructions from the queue.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_que_ena_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t ena                   : 8;  /**< [  7:  0](R/W) Enables the logical instruction queues. Each bit corresponds to a queue:
                                                                 1 = queue is enabled.
                                                                 0 = queue is disabled. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 8;  /**< [  7:  0](R/W) Enables the logical instruction queues. Each bit corresponds to a queue:
                                                                 1 = queue is enabled.
                                                                 0 = queue is disabled. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_que_ena_s cn; */
} bdk_zip_que_ena_t;

#define BDK_ZIP_QUE_ENA BDK_ZIP_QUE_ENA_FUNC()
static inline uint64_t BDK_ZIP_QUE_ENA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUE_ENA_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000500ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000500ll;
    __bdk_csr_fatal("ZIP_QUE_ENA", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUE_ENA bdk_zip_que_ena_t
#define bustype_BDK_ZIP_QUE_ENA BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUE_ENA "ZIP_QUE_ENA"
#define device_bar_BDK_ZIP_QUE_ENA 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUE_ENA 0
#define arguments_BDK_ZIP_QUE_ENA -1,-1,-1,-1

/**
 * Register (NCB) zip_que_pri
 *
 * ZIP Queue Priority Register
 * This registers defines the priority between instruction queues.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_que_pri_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t pri                   : 8;  /**< [  7:  0](R/W) Queue priority. Each bit corresponds to a queue:
                                                                 PRI[n]=1: Queue n has higher priority. Round-Robin between higher priority queues.
                                                                 PRI[n]=0: Queue n has lower priority. Round-Robin between lower priority queues. */
#else /* Word 0 - Little Endian */
        uint64_t pri                   : 8;  /**< [  7:  0](R/W) Queue priority. Each bit corresponds to a queue:
                                                                 PRI[n]=1: Queue n has higher priority. Round-Robin between higher priority queues.
                                                                 PRI[n]=0: Queue n has lower priority. Round-Robin between lower priority queues. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_que_pri_s cn; */
} bdk_zip_que_pri_t;

#define BDK_ZIP_QUE_PRI BDK_ZIP_QUE_PRI_FUNC()
static inline uint64_t BDK_ZIP_QUE_PRI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUE_PRI_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000508ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000508ll;
    __bdk_csr_fatal("ZIP_QUE_PRI", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUE_PRI bdk_zip_que_pri_t
#define bustype_BDK_ZIP_QUE_PRI BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUE_PRI "ZIP_QUE_PRI"
#define device_bar_BDK_ZIP_QUE_PRI 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUE_PRI 0
#define arguments_BDK_ZIP_QUE_PRI -1,-1,-1,-1

/**
 * Register (NCB) zip_que_reset
 *
 * INERNAL: ZIP Queue Reset Register
 *
 * This register resets the ZIP instruction queues. Added in pass 2.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_que_reset_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t reset                 : 8;  /**< [  7:  0](R/W) When set, the conresponding queue will be put into reset. When clear, the queue is out of
                                                                 reset. Bit[<a>] resets queue <a>. */
#else /* Word 0 - Little Endian */
        uint64_t reset                 : 8;  /**< [  7:  0](R/W) When set, the conresponding queue will be put into reset. When clear, the queue is out of
                                                                 reset. Bit[<a>] resets queue <a>. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_que_reset_s cn; */
} bdk_zip_que_reset_t;

#define BDK_ZIP_QUE_RESET BDK_ZIP_QUE_RESET_FUNC()
static inline uint64_t BDK_ZIP_QUE_RESET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_QUE_RESET_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0x838000000400ll;
    __bdk_csr_fatal("ZIP_QUE_RESET", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_QUE_RESET bdk_zip_que_reset_t
#define bustype_BDK_ZIP_QUE_RESET BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_QUE_RESET "ZIP_QUE_RESET"
#define device_bar_BDK_ZIP_QUE_RESET 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_QUE_RESET 0
#define arguments_BDK_ZIP_QUE_RESET -1,-1,-1,-1

/**
 * Register (NCB) zip_throttle
 *
 * ZIP Throttle Register
 * This register controls the maximum number of in-flight X2I data fetch transactions. Writing 0
 * to this register causes the ZIP module to temporarily suspend NCB accesses; it is not
 * recommended for normal operation, but may be useful for diagnostics.
 */
typedef union
{
    uint64_t u;
    struct bdk_zip_throttle_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t ld_infl               : 6;  /**< [  5:  0](R/W) Maximum number of in-flight data fetch transactions on the NCB. Larger values may improve
                                                                 ZIP performance but may starve other devices on the same NCB. Values > 32 are illegal. */
#else /* Word 0 - Little Endian */
        uint64_t ld_infl               : 6;  /**< [  5:  0](R/W) Maximum number of in-flight data fetch transactions on the NCB. Larger values may improve
                                                                 ZIP performance but may starve other devices on the same NCB. Values > 32 are illegal. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_zip_throttle_s cn; */
} bdk_zip_throttle_t;

#define BDK_ZIP_THROTTLE BDK_ZIP_THROTTLE_FUNC()
static inline uint64_t BDK_ZIP_THROTTLE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ZIP_THROTTLE_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x838000000010ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x838000000010ll;
    __bdk_csr_fatal("ZIP_THROTTLE", 0, 0, 0, 0, 0);
}

#define typedef_BDK_ZIP_THROTTLE bdk_zip_throttle_t
#define bustype_BDK_ZIP_THROTTLE BDK_CSR_TYPE_NCB
#define basename_BDK_ZIP_THROTTLE "ZIP_THROTTLE"
#define device_bar_BDK_ZIP_THROTTLE 0x0 /* PF_BAR0 */
#define busnum_BDK_ZIP_THROTTLE 0
#define arguments_BDK_ZIP_THROTTLE -1,-1,-1,-1

#endif /* __BDK_CSRS_ZIP_H__ */
