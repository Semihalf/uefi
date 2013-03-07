/**
 * @file
 *
 * Interface to the hardware Fetch and Add Unit.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

typedef int bdk_fau_reg_64_t;
typedef int bdk_fau_reg_32_t;
typedef int bdk_fau_reg_16_t;
typedef int bdk_fau_reg_8_t;

/*
 * Octeon Fetch and Add Unit (FAU)
 */

#define BDK_FAU_BITS_SCRADDR       63,56
#define BDK_FAU_BITS_LEN           55,48
#define BDK_FAU_BITS_INEVAL        35,14
#define BDK_FAU_BITS_TAGWAIT       13,13
#define BDK_FAU_BITS_NOADD         13,13
#define BDK_FAU_BITS_SIZE          12,11
#define BDK_FAU_BITS_REGISTER      10,0


typedef enum {
   BDK_FAU_OP_SIZE_8  = 0,
   BDK_FAU_OP_SIZE_16 = 1,
   BDK_FAU_OP_SIZE_32 = 2,
   BDK_FAU_OP_SIZE_64 = 3
} bdk_fau_op_size_t;

/**
 * Tagwait return definition. If a timeout occurs, the error
 * bit will be set. Otherwise the value of the register before
 * the update will be returned.
 */
typedef struct
{
    uint64_t    error   : 1;
    int64_t     value   : 63;
} bdk_fau_tagwait64_t;

/**
 * Tagwait return definition. If a timeout occurs, the error
 * bit will be set. Otherwise the value of the register before
 * the update will be returned.
 */
typedef struct
{
    uint64_t    error   : 1;
    int32_t     value   : 31;
} bdk_fau_tagwait32_t;

/**
 * Tagwait return definition. If a timeout occurs, the error
 * bit will be set. Otherwise the value of the register before
 * the update will be returned.
 */
typedef struct
{
    uint64_t    error   : 1;
    int16_t     value   : 15;
} bdk_fau_tagwait16_t;

/**
 * Tagwait return definition. If a timeout occurs, the error
 * bit will be set. Otherwise the value of the register before
 * the update will be returned.
 */
typedef struct
{
    uint64_t    error   : 1;
    int8_t     value    : 7;
} bdk_fau_tagwait8_t;

/**
 * Asynchronous tagwait return definition. If a timeout occurs,
 * the error bit will be set. Otherwise the value of the
 * register before the update will be returned.
 */
typedef union {
   uint64_t        u64;
   struct {
      uint64_t     invalid: 1;
     uint64_t     data   :63; /* unpredictable if invalid is set */
   } s;
} bdk_fau_async_tagwait_result_t;

/**
 * @INTERNAL
 * Builds a store I/O address for writing to the FAU
 *
 * @param noadd  0 = Store value is atomically added to the current value
 *               1 = Store value is atomically written over the current value
 * @param reg    FAU atomic register to access. 0 <= reg < 2048.
 *               - Step by 2 for 16 bit access.
 *               - Step by 4 for 32 bit access.
 *               - Step by 8 for 64 bit access.
 * @return Address to store for atomic update
 */
static inline uint64_t __bdk_fau_store_address(uint64_t noadd, uint64_t reg)
{
    return ((0x8001f0ull << 40) |
            bdk_build_bits(BDK_FAU_BITS_NOADD, noadd) |
            bdk_build_bits(BDK_FAU_BITS_REGISTER, reg));
}

/**
 * @INTERNAL
 * Builds a I/O address for accessing the FAU
 *
 * @param tagwait Should the atomic add wait for the current tag switch
 *                operation to complete.
 *                - 0 = Don't wait
 *                - 1 = Wait for tag switch to complete
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 2 for 16 bit access.
 *                - Step by 4 for 32 bit access.
 *                - Step by 8 for 64 bit access.
 * @param value   Signed value to add.
 *                Note: When performing 32 and 64 bit access, only the low
 *                22 bits are available.
 * @return Address to read from for atomic update
 */
static inline uint64_t __bdk_fau_atomic_address(uint64_t tagwait, uint64_t reg, int64_t value)
{
    return ((0x8001f0ull << 40) |
            bdk_build_bits(BDK_FAU_BITS_INEVAL, value) |
            bdk_build_bits(BDK_FAU_BITS_TAGWAIT, tagwait) |
            bdk_build_bits(BDK_FAU_BITS_REGISTER, reg));
}

/**
 * Perform an atomic 64 bit add
 *
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 8 for 64 bit access.
 * @param value   Signed value to add.
 *                Note: Only the low 22 bits are available.
 * @return Value of the register before the update
 */
static inline int64_t bdk_fau_fetch_and_add64(bdk_fau_reg_64_t reg, int64_t value)
{
    return bdk_read64_int64(__bdk_fau_atomic_address(0, reg, value));
}

/**
 * Perform an atomic 32 bit add
 *
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 4 for 32 bit access.
 * @param value   Signed value to add.
 *                Note: Only the low 22 bits are available.
 * @return Value of the register before the update
 */
static inline int32_t bdk_fau_fetch_and_add32(bdk_fau_reg_32_t reg, int32_t value)
{
    return bdk_read64_int32(__bdk_fau_atomic_address(0, reg, value));
}

/**
 * Perform an atomic 16 bit add
 *
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 2 for 16 bit access.
 * @param value   Signed value to add.
 * @return Value of the register before the update
 */
static inline int16_t bdk_fau_fetch_and_add16(bdk_fau_reg_16_t reg, int16_t value)
{
    return bdk_read64_int16(__bdk_fau_atomic_address(0, reg, value));
}

/**
 * Perform an atomic 8 bit add
 *
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 * @param value   Signed value to add.
 * @return Value of the register before the update
 */
static inline int8_t bdk_fau_fetch_and_add8(bdk_fau_reg_8_t reg, int8_t value)
{
    return bdk_read64_int8(__bdk_fau_atomic_address(0, reg, value));
}

/**
 * Perform an atomic 64 bit add after the current tag switch
 * completes
 *
 * @param reg    FAU atomic register to access. 0 <= reg < 2048.
 *               - Step by 8 for 64 bit access.
 * @param value  Signed value to add.
 *               Note: Only the low 22 bits are available.
 * @return If a timeout occurs, the error bit will be set. Otherwise
 *         the value of the register before the update will be
 *         returned
 */
static inline bdk_fau_tagwait64_t bdk_fau_tagwait_fetch_and_add64(bdk_fau_reg_64_t reg, int64_t value)
{
    union
    {
        uint64_t i64;
        bdk_fau_tagwait64_t t;
    } result;
    result.i64 = bdk_read64_int64(__bdk_fau_atomic_address(1, reg, value));
    return result.t;
}

/**
 * Perform an atomic 32 bit add after the current tag switch
 * completes
 *
 * @param reg    FAU atomic register to access. 0 <= reg < 2048.
 *               - Step by 4 for 32 bit access.
 * @param value  Signed value to add.
 *               Note: Only the low 22 bits are available.
 * @return If a timeout occurs, the error bit will be set. Otherwise
 *         the value of the register before the update will be
 *         returned
 */
static inline bdk_fau_tagwait32_t bdk_fau_tagwait_fetch_and_add32(bdk_fau_reg_32_t reg, int32_t value)
{
    union
    {
        uint64_t i32;
        bdk_fau_tagwait32_t t;
    } result;
    result.i32 = bdk_read64_int32(__bdk_fau_atomic_address(1, reg, value));
    return result.t;
}

/**
 * Perform an atomic 16 bit add after the current tag switch
 * completes
 *
 * @param reg    FAU atomic register to access. 0 <= reg < 2048.
 *               - Step by 2 for 16 bit access.
 * @param value  Signed value to add.
 * @return If a timeout occurs, the error bit will be set. Otherwise
 *         the value of the register before the update will be
 *         returned
 */
static inline bdk_fau_tagwait16_t bdk_fau_tagwait_fetch_and_add16(bdk_fau_reg_16_t reg, int16_t value)
{
    union
    {
        uint64_t i16;
        bdk_fau_tagwait16_t t;
    } result;
    result.i16 = bdk_read64_int16(__bdk_fau_atomic_address(1, reg, value));
    return result.t;
}

/**
 * Perform an atomic 8 bit add after the current tag switch
 * completes
 *
 * @param reg    FAU atomic register to access. 0 <= reg < 2048.
 * @param value  Signed value to add.
 * @return If a timeout occurs, the error bit will be set. Otherwise
 *         the value of the register before the update will be
 *         returned
 */
static inline bdk_fau_tagwait8_t bdk_fau_tagwait_fetch_and_add8(bdk_fau_reg_8_t reg, int8_t value)
{
    union
    {
        uint64_t i8;
        bdk_fau_tagwait8_t t;
    } result;
    result.i8 = bdk_read64_int8(__bdk_fau_atomic_address(1, reg, value));
    return result.t;
}

/**
 * @INTERNAL
 * Builds I/O data for async operations
 *
 * @param scraddr Scratch pad byte address to write to.  Must be 8 byte aligned
 * @param value   Signed value to add.
 *                Note: When performing 32 and 64 bit access, only the low
 *                22 bits are available.
 * @param tagwait Should the atomic add wait for the current tag switch
 *                operation to complete.
 *                - 0 = Don't wait
 *                - 1 = Wait for tag switch to complete
 * @param size    The size of the operation:
 *                - BDK_FAU_OP_SIZE_8  (0) = 8 bits
 *                - BDK_FAU_OP_SIZE_16 (1) = 16 bits
 *                - BDK_FAU_OP_SIZE_32 (2) = 32 bits
 *                - BDK_FAU_OP_SIZE_64 (3) = 64 bits
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 2 for 16 bit access.
 *                - Step by 4 for 32 bit access.
 *                - Step by 8 for 64 bit access.
 * @return Data to write using bdk_send_single
 */
static inline uint64_t __bdk_fau_iobdma_data(uint64_t scraddr, int64_t value, uint64_t tagwait,
                                          bdk_fau_op_size_t size, uint64_t reg)
{
    return ((0x1f0ull << 40) |
                      bdk_build_bits(BDK_FAU_BITS_SCRADDR, scraddr>>3) |
                      bdk_build_bits(BDK_FAU_BITS_LEN, 1) |
                      bdk_build_bits(BDK_FAU_BITS_INEVAL, value) |
                      bdk_build_bits(BDK_FAU_BITS_TAGWAIT, tagwait) |
                      bdk_build_bits(BDK_FAU_BITS_SIZE, size) |
                      bdk_build_bits(BDK_FAU_BITS_REGISTER, reg));
}

/**
 * Perform an async atomic 64 bit add. The old value is
 * placed in the scratch memory at byte address scraddr.
 *
 * @param scraddr Scratch memory byte address to put response in.
 *                Must be 8 byte aligned.
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 8 for 64 bit access.
 * @param value   Signed value to add.
 *                Note: Only the low 22 bits are available.
 * @return Placed in the scratch pad register
 */
static inline void bdk_fau_async_fetch_and_add64(uint64_t scraddr, bdk_fau_reg_64_t reg, int64_t value)
{
    bdk_send_single(__bdk_fau_iobdma_data(scraddr, value, 0, BDK_FAU_OP_SIZE_64, reg));
}

/**
 * Perform an async atomic 32 bit add. The old value is
 * placed in the scratch memory at byte address scraddr.
 *
 * @param scraddr Scratch memory byte address to put response in.
 *                Must be 8 byte aligned.
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 4 for 32 bit access.
 * @param value   Signed value to add.
 *                Note: Only the low 22 bits are available.
 * @return Placed in the scratch pad register
 */
static inline void bdk_fau_async_fetch_and_add32(uint64_t scraddr, bdk_fau_reg_32_t reg, int32_t value)
{
    bdk_send_single(__bdk_fau_iobdma_data(scraddr, value, 0, BDK_FAU_OP_SIZE_32, reg));
}

/**
 * Perform an async atomic 16 bit add. The old value is
 * placed in the scratch memory at byte address scraddr.
 *
 * @param scraddr Scratch memory byte address to put response in.
 *                Must be 8 byte aligned.
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 2 for 16 bit access.
 * @param value   Signed value to add.
 * @return Placed in the scratch pad register
 */
static inline void bdk_fau_async_fetch_and_add16(uint64_t scraddr, bdk_fau_reg_16_t reg, int16_t value)
{
    bdk_send_single(__bdk_fau_iobdma_data(scraddr, value, 0, BDK_FAU_OP_SIZE_16, reg));
}

/**
 * Perform an async atomic 8 bit add. The old value is
 * placed in the scratch memory at byte address scraddr.
 *
 * @param scraddr Scratch memory byte address to put response in.
 *                Must be 8 byte aligned.
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 * @param value   Signed value to add.
 * @return Placed in the scratch pad register
 */
static inline void bdk_fau_async_fetch_and_add8(uint64_t scraddr, bdk_fau_reg_8_t reg, int8_t value)
{
    bdk_send_single(__bdk_fau_iobdma_data(scraddr, value, 0, BDK_FAU_OP_SIZE_8, reg));
}

/**
 * Perform an async atomic 64 bit add after the current tag
 * switch completes.
 *
 * @param scraddr Scratch memory byte address to put response in.
 *                Must be 8 byte aligned.
 *                If a timeout occurs, the error bit (63) will be set. Otherwise
 *                the value of the register before the update will be
 *                returned
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 8 for 64 bit access.
 * @param value   Signed value to add.
 *                Note: Only the low 22 bits are available.
 * @return Placed in the scratch pad register
 */
static inline void bdk_fau_async_tagwait_fetch_and_add64(uint64_t scraddr, bdk_fau_reg_64_t reg, int64_t value)
{
    bdk_send_single(__bdk_fau_iobdma_data(scraddr, value, 1, BDK_FAU_OP_SIZE_64, reg));
}

/**
 * Perform an async atomic 32 bit add after the current tag
 * switch completes.
 *
 * @param scraddr Scratch memory byte address to put response in.
 *                Must be 8 byte aligned.
 *                If a timeout occurs, the error bit (63) will be set. Otherwise
 *                the value of the register before the update will be
 *                returned
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 4 for 32 bit access.
 * @param value   Signed value to add.
 *                Note: Only the low 22 bits are available.
 * @return Placed in the scratch pad register
 */
static inline void bdk_fau_async_tagwait_fetch_and_add32(uint64_t scraddr, bdk_fau_reg_32_t reg, int32_t value)
{
    bdk_send_single(__bdk_fau_iobdma_data(scraddr, value, 1, BDK_FAU_OP_SIZE_32, reg));
}

/**
 * Perform an async atomic 16 bit add after the current tag
 * switch completes.
 *
 * @param scraddr Scratch memory byte address to put response in.
 *                Must be 8 byte aligned.
 *                If a timeout occurs, the error bit (63) will be set. Otherwise
 *                the value of the register before the update will be
 *                returned
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 2 for 16 bit access.
 * @param value   Signed value to add.
 * @return Placed in the scratch pad register
 */
static inline void bdk_fau_async_tagwait_fetch_and_add16(uint64_t scraddr, bdk_fau_reg_16_t reg, int16_t value)
{
    bdk_send_single(__bdk_fau_iobdma_data(scraddr, value, 1, BDK_FAU_OP_SIZE_16, reg));
}

/**
 * Perform an async atomic 8 bit add after the current tag
 * switch completes.
 *
 * @param scraddr Scratch memory byte address to put response in.
 *                Must be 8 byte aligned.
 *                If a timeout occurs, the error bit (63) will be set. Otherwise
 *                the value of the register before the update will be
 *                returned
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 * @param value   Signed value to add.
 * @return Placed in the scratch pad register
 */
static inline void bdk_fau_async_tagwait_fetch_and_add8(uint64_t scraddr, bdk_fau_reg_8_t reg, int8_t value)
{
    bdk_send_single(__bdk_fau_iobdma_data(scraddr, value, 1, BDK_FAU_OP_SIZE_8, reg));
}

/**
 * Perform an atomic 64 bit add
 *
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 8 for 64 bit access.
 * @param value   Signed value to add.
 */
static inline void bdk_fau_atomic_add64(bdk_fau_reg_64_t reg, int64_t value)
{
    bdk_write64_int64(__bdk_fau_store_address(0, reg), value);
}

/**
 * Perform an atomic 32 bit add
 *
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 4 for 32 bit access.
 * @param value   Signed value to add.
 */
static inline void bdk_fau_atomic_add32(bdk_fau_reg_32_t reg, int32_t value)
{
    bdk_write64_int32(__bdk_fau_store_address(0, reg), value);
}

/**
 * Perform an atomic 16 bit add
 *
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 2 for 16 bit access.
 * @param value   Signed value to add.
 */
static inline void bdk_fau_atomic_add16(bdk_fau_reg_16_t reg, int16_t value)
{
    bdk_write64_int16(__bdk_fau_store_address(0, reg), value);
}

/**
 * Perform an atomic 8 bit add
 *
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 * @param value   Signed value to add.
 */
static inline void bdk_fau_atomic_add8(bdk_fau_reg_8_t reg, int8_t value)
{
    bdk_write64_int8(__bdk_fau_store_address(0, reg), value);
}

/**
 * Perform an atomic 64 bit write
 *
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 8 for 64 bit access.
 * @param value   Signed value to write.
 */
static inline void bdk_fau_atomic_write64(bdk_fau_reg_64_t reg, int64_t value)
{
    bdk_write64_int64(__bdk_fau_store_address(1, reg), value);
}

/**
 * Perform an atomic 32 bit write
 *
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 4 for 32 bit access.
 * @param value   Signed value to write.
 */
static inline void bdk_fau_atomic_write32(bdk_fau_reg_32_t reg, int32_t value)
{
    bdk_write64_int32(__bdk_fau_store_address(1, reg), value);
}

/**
 * Perform an atomic 16 bit write
 *
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 *                - Step by 2 for 16 bit access.
 * @param value   Signed value to write.
 */
static inline void bdk_fau_atomic_write16(bdk_fau_reg_16_t reg, int16_t value)
{
    bdk_write64_int16(__bdk_fau_store_address(1, reg), value);
}

/**
 * Perform an atomic 8 bit write
 *
 * @param reg     FAU atomic register to access. 0 <= reg < 2048.
 * @param value   Signed value to write.
 */
static inline void bdk_fau_atomic_write8(bdk_fau_reg_8_t reg, int8_t value)
{
    bdk_write64_int8(__bdk_fau_store_address(1, reg), value);
}

/** @} */
