/**
 * @file
 *
 * Packet buffer defines.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 */

/**
 * This structure defines a buffer pointer on Octeon
 */
union bdk_buf_ptr {
    void*           ptr;
    uint64_t        u64;
    struct
    {
        uint64_t    i    : 1; /**< if set, invert the "free" pick of the overall packet. HW always sets this bit to 0 on inbound packet */
        uint64_t    back : 4; /**< Indicates the amount to back up to get to the buffer start in cache lines. In most cases
                                this is less than one complete cache line, so the value is zero */
        uint64_t    pool : 3; /**< The pool that the buffer came from / goes to */
        uint64_t    size :16; /**< The size of the segment pointed to by addr (in bytes) */
        uint64_t    addr :40; /**< Pointer to the first byte of the data, NOT buffer */
    } s;
};

typedef union bdk_buf_ptr bdk_buf_ptr_t;

