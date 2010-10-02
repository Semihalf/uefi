/**
 * @file
 *
 * Header file for the zip (deflate) block
 *
 * <hr>$Revision: 49448 $<hr>
 */

typedef union {
   uint64_t u64;
   struct {
#if __BYTE_ORDER == __BIG_ENDIAN
      uint64_t unused              :  5;
      uint64_t full_block_write    :  1;
      uint64_t no_l2_alloc         :  1;
      uint64_t little_endian       :  1;
      uint64_t length              : 16;
      uint64_t ptr                 : 40;
#else
      uint64_t ptr                 : 40;
      uint64_t length              : 16;
      uint64_t little_endian       :  1;
      uint64_t no_l2_alloc         :  1;
      uint64_t full_block_write    :  1;
      uint64_t unused              :  5;
#endif
   } s;
} bdk_zip_ptr_t;
#define BDK_ZIP_PTR_MAX_LEN    ((1 << 16) - 1)


typedef enum {
   BDK_ZIP_COMPLETION_NOTDONE  = 0,
   BDK_ZIP_COMPLETION_SUCCESS  = 1,
   BDK_ZIP_COMPLETION_OTRUNC   = 2,
   BDK_ZIP_COMPLETION_STOP     = 3,
   BDK_ZIP_COMPLETION_ITRUNC   = 4,
   BDK_ZIP_COMPLETION_RBLOCK   = 5,
   BDK_ZIP_COMPLETION_NLEN     = 6,
   BDK_ZIP_COMPLETION_BADCODE  = 7,
   BDK_ZIP_COMPLETION_BADCODE2 = 8,
   BDK_ZIP_COMPLETION_ZERO_LEN = 9,
   BDK_ZIP_COMPLETION_PARITY   = 10,
   BDK_ZIP_COMPLETION_FATAL    = 11
} bdk_zip_completion_code_t;

typedef union {
   uint64_t u64[3];
   struct {

      // WORD 0
#if __BYTE_ORDER == __BIG_ENDIAN
      uint64_t crc32               : 32;
      uint64_t adler               : 32;
#else
      uint64_t adler               : 32;
      uint64_t crc32               : 32;
#endif

      // WORD 1
#if __BYTE_ORDER == __BIG_ENDIAN
      uint64_t totalbyteswritten   : 32;
      uint64_t totalbytesread      : 32;
#else
      uint64_t totalbytesread      : 32;
      uint64_t totalbyteswritten   : 32;
#endif

      // WORD 2
#if __BYTE_ORDER == __BIG_ENDIAN
      uint64_t                      totalbitsprocessed  : 32; // decompression only
      uint64_t                      unused20            :  5;
      uint64_t                      exnum               :  3; // compression only
      uint64_t                      unused21            :  1;
      uint64_t                      exbits              :  7; // compression only
      uint64_t                      unused22            :  7;
      uint64_t                      eof                 :  1; // decompression only
      bdk_zip_completion_code_t    completioncode      :  8; // If polling, SW should set this to zero and wait for non-zero
#else
      bdk_zip_completion_code_t    completioncode      :  8; // If polling, SW should set this to zero and wait for non-zero
      uint64_t                      eof                 :  1; // decompression only
      uint64_t                      unused22            :  7;
      uint64_t                      exbits              :  7; // compression only
      uint64_t                      unused21            :  1;
      uint64_t                      exnum               :  3; // compression only
      uint64_t                      unused20            :  5;
      uint64_t                      totalbitsprocessed  : 32; // decompression only
#endif
   } s;
} bdk_zip_result_t;

typedef union {
   uint64_t u64[8];
   struct {

      // WORD 0
#if __BYTE_ORDER == __BIG_ENDIAN
      uint64_t unused00            :  8;
      uint64_t totaloutputlength   : 24;
      uint64_t unused01            :  5;
      uint64_t exnum               :  3;
      uint64_t unused02            :  1;
      uint64_t exbits              :  7;
      uint64_t unused03            :  6;
      uint64_t speed               :  1;
      uint64_t forcefixed          :  1;
      uint64_t forcedynamic        :  1;
      uint64_t eof                 :  1;
      uint64_t bof                 :  1;
      uint64_t compress            :  1;
      uint64_t unused04            :  1;
      uint64_t dscatter            :  1;
      uint64_t dgather             :  1;
      uint64_t hgather             :  1;
#else
      uint64_t hgather             :  1;
      uint64_t dgather             :  1;
      uint64_t dscatter            :  1;
      uint64_t unused04            :  1;
      uint64_t compress            :  1;
      uint64_t bof                 :  1;
      uint64_t eof                 :  1;
      uint64_t forcedynamic        :  1;
      uint64_t forcefixed          :  1;
      uint64_t speed               :  1;
      uint64_t unused03            :  6;
      uint64_t exbits              :  7;
      uint64_t unused02            :  1;
      uint64_t exnum               :  3;
      uint64_t unused01            :  5;
      uint64_t totaloutputlength   : 24;
      uint64_t unused00            :  8;
#endif

      // WORD 1
#if __BYTE_ORDER == __BIG_ENDIAN
      uint64_t historylength       : 16;
      uint64_t unused10            : 16;
      uint64_t adler32             : 32;
#else
      uint64_t adler32             : 32;
      uint64_t unused10            : 16;
      uint64_t historylength       : 16;
#endif

      // WORD 2
      bdk_zip_ptr_t ctx_ptr;

      // WORD 3
      bdk_zip_ptr_t hist_ptr;

      // WORD 4
      bdk_zip_ptr_t in_ptr;

      // WORD 5
      bdk_zip_ptr_t out_ptr;

      // WORD 6
      bdk_zip_ptr_t result_ptr;

      // WORD 7
      bdk_zip_ptr_t wq_ptr;

   } s;
} bdk_zip_command_t;


/**
 * Initialize the ZIP block
 *
 * @return Zero on success, negative on failure
 */
int bdk_zip_initialize(void);

/**
 * Shutdown the ZIP block. ZIP must be idle when
 * this function is called.
 *
 * @return Zero on success, negative on failure
 */
int bdk_zip_shutdown(void);

/**
 * Submit a command to the ZIP block
 *
 * @param command Zip command to submit
 *
 * @return Zero on success, negative on failure
 */
int bdk_zip_submit(bdk_zip_command_t *command);

