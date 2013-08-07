/**
 * @file
 *
 * This file provides atomic operations
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * Atomically adds a signed value to a 32 bit (aligned) memory location.
 *
 * This version does not perform 'sync' operations to enforce memory
 * operations.  This should only be used when there are no memory operation
 * ordering constraints.  (This should NOT be used for reference counting -
 * use the standard version instead.)
 *
 * @param ptr    address in memory to add incr to
 * @param incr   amount to increment memory location by (signed)
 */
static inline void bdk_atomic_add32_nosync(int32_t *ptr, int32_t incr)
{
    __asm__ __volatile__(
    "   saa %[inc], (%[base]) \n"
    : "+m" (*ptr)
    : [inc] "r" (incr), [base] "r" (ptr)
    : "memory");
}

/**
 * Atomically adds a signed value to a 32 bit (aligned) memory location.
 *
 * Memory access ordering is enforced before/after the atomic operation,
 * so no additional 'sync' instructions are required.
 *
 *
 * @param ptr    address in memory to add incr to
 * @param incr   amount to increment memory location by (signed)
 */
static inline void bdk_atomic_add32(int32_t *ptr, int32_t incr)
{
    BDK_SYNCW;
    bdk_atomic_add32_nosync(ptr, incr);
    BDK_SYNCW;
}

/**
 * Atomically sets a 32 bit (aligned) memory location to a value
 *
 * @param ptr    address of memory to set
 * @param value  value to set memory location to.
 */
static inline void bdk_atomic_set32(int32_t *ptr, int32_t value)
{
    BDK_SYNCW;
    *ptr = value;
    BDK_SYNCW;
}

/**
 * Returns the current value of a 32 bit (aligned) memory
 * location.
 *
 * @param ptr    Address of memory to get
 * @return Value of the memory
 */
static inline int32_t bdk_atomic_get32(int32_t *ptr)
{
    return *(volatile int32_t *)ptr;
}

/**
 * Atomically adds a signed value to a 64 bit (aligned) memory location.
 *
 * This version does not perform 'sync' operations to enforce memory
 * operations.  This should only be used when there are no memory operation
 * ordering constraints.  (This should NOT be used for reference counting -
 * use the standard version instead.)
 *
 * @param ptr    address in memory to add incr to
 * @param incr   amount to increment memory location by (signed)
 */
static inline void bdk_atomic_add64_nosync(int64_t *ptr, int64_t incr)
{
    __asm__ __volatile__(
    "   saad %[inc], (%[base])  \n"
    : "+m" (*ptr)
    : [inc] "r" (incr), [base] "r" (ptr)
    : "memory");
}

/**
 * Atomically adds a signed value to a 64 bit (aligned) memory location.
 *
 * Memory access ordering is enforced before/after the atomic operation,
 * so no additional 'sync' instructions are required.
 *
 *
 * @param ptr    address in memory to add incr to
 * @param incr   amount to increment memory location by (signed)
 */
static inline void bdk_atomic_add64(int64_t *ptr, int64_t incr)
{
    BDK_SYNCW;
    bdk_atomic_add64_nosync(ptr, incr);
    BDK_SYNCW;
}

/**
 * Atomically sets a 64 bit (aligned) memory location to a value
 *
 * @param ptr    address of memory to set
 * @param value  value to set memory location to.
 */
static inline void bdk_atomic_set64(int64_t *ptr, int64_t value)
{
    BDK_SYNCW;
    *ptr = value;
    BDK_SYNCW;
}

/**
 * Returns the current value of a 64 bit (aligned) memory
 * location.
 *
 * @param ptr    Address of memory to get
 * @return Value of the memory
 */
static inline int64_t bdk_atomic_get64(int64_t *ptr)
{
    return *(volatile int64_t *)ptr;
}

/**
 * Atomically compares the old value with the value at ptr, and if they match,
 * stores new_val to ptr.
 * If *ptr and old don't match, function returns failure immediately.
 * If *ptr and old match, function spins until *ptr updated to new atomically, or
 *  until *ptr and old no longer match
 *
 * Does no memory synchronization.
 *
 * @return 1 on success (match and store)
 *         0 on no match
 */
static inline uint32_t bdk_atomic_compare_and_store32_nosync(uint32_t *ptr, uint32_t old_val, uint32_t new_val)
{
    uint32_t tmp, ret;

    __asm__ __volatile__(
    ".set noreorder         \n"
    "1: ll   %[tmp], %[val] \n"
    "   li   %[ret], 0     \n"
    "   bne  %[tmp], %[old], 2f \n"
    "   move %[tmp], %[new_val] \n"
    "   sc   %[tmp], %[val] \n"
    "   beqz %[tmp], 1b     \n"
    "   li   %[ret], 1      \n"
    "2: nop               \n"
    ".set reorder           \n"
    : [val] "+m" (*ptr), [tmp] "=&r" (tmp), [ret] "=&r" (ret)
    : [old] "r" (old_val), [new_val] "r" (new_val)
    : "memory");

    return(ret);

}

/**
 * Atomically compares the old value with the value at ptr, and if they match,
 * stores new_val to ptr.
 * If *ptr and old don't match, function returns failure immediately.
 * If *ptr and old match, function spins until *ptr updated to new atomically, or
 *  until *ptr and old no longer match
 *
 * Does memory synchronization that is required to use this as a locking primitive.
 *
 * @return 1 on success (match and store)
 *         0 on no match
 */
static inline uint32_t bdk_atomic_compare_and_store32(uint32_t *ptr, uint32_t old_val, uint32_t new_val)
{
    uint32_t ret;
    BDK_SYNCW;
    ret = bdk_atomic_compare_and_store32_nosync(ptr, old_val, new_val);
    BDK_SYNCW;
    return ret;


}

/**
 * Atomically compares the old value with the value at ptr, and if they match,
 * stores new_val to ptr.
 * If *ptr and old don't match, function returns failure immediately.
 * If *ptr and old match, function spins until *ptr updated to new atomically, or
 *  until *ptr and old no longer match
 *
 * Does no memory synchronization.
 *
 * @return 1 on success (match and store)
 *         0 on no match
 */
static inline uint64_t bdk_atomic_compare_and_store64_nosync(uint64_t *ptr, uint64_t old_val, uint64_t new_val)
{
    uint64_t tmp, ret;

    __asm__ __volatile__(
    ".set noreorder         \n"
    "1: lld  %[tmp], %[val] \n"
    "   li   %[ret], 0     \n"
    "   bne  %[tmp], %[old], 2f \n"
    "   move %[tmp], %[new_val] \n"
    "   scd  %[tmp], %[val] \n"
    "   beqz %[tmp], 1b     \n"
    "   li   %[ret], 1      \n"
    "2: nop               \n"
    ".set reorder           \n"
    : [val] "+m" (*ptr), [tmp] "=&r" (tmp), [ret] "=&r" (ret)
    : [old] "r" (old_val), [new_val] "r" (new_val)
    : "memory");

    return(ret);

}

/**
 * Atomically compares the old value with the value at ptr, and if they match,
 * stores new_val to ptr.
 * If *ptr and old don't match, function returns failure immediately.
 * If *ptr and old match, function spins until *ptr updated to new atomically, or
 *  until *ptr and old no longer match
 *
 * Does memory synchronization that is required to use this as a locking primitive.
 *
 * @return 1 on success (match and store)
 *         0 on no match
 */
static inline uint64_t bdk_atomic_compare_and_store64(uint64_t *ptr, uint64_t old_val, uint64_t new_val)
{
    uint64_t ret;
    BDK_SYNCW;
    ret = bdk_atomic_compare_and_store64_nosync(ptr, old_val, new_val);
    BDK_SYNCW;
    return ret;
}

/**
 * Atomically adds a signed value to a 64 bit (aligned) memory location,
 * and returns previous value.
 *
 * This version does not perform 'sync' operations to enforce memory
 * operations.  This should only be used when there are no memory operation
 * ordering constraints.  (This should NOT be used for reference counting -
 * use the standard version instead.)
 *
 * @param ptr    address in memory to add incr to
 * @param incr   amount to increment memory location by (signed)
 *
 * @return Value of memory location before increment
 */
static inline int64_t bdk_atomic_fetch_and_add64_nosync(int64_t *ptr, int64_t incr)
{
    uint64_t ret;

    if (__builtin_constant_p(incr) && incr == 1)
    {
        __asm__ __volatile__(
            "laid  %0,(%2)"
            : "=r" (ret), "+m" (*ptr) : "r" (ptr) : "memory");
    }
    else if (__builtin_constant_p(incr) && incr == -1)
    {
        __asm__ __volatile__(
            "ladd  %0,(%2)"
            : "=r" (ret), "+m" (*ptr) : "r" (ptr) : "memory");
    }
    else
    {
        __asm__ __volatile__(
            "laad  %0,(%2),%3"
            : "=r" (ret), "+m" (*ptr) : "r" (ptr), "r" (incr) : "memory");
    }

    return (ret);
}

/**
 * Atomically adds a signed value to a 64 bit (aligned) memory location,
 * and returns previous value.
 *
 * Memory access ordering is enforced before/after the atomic operation,
 * so no additional 'sync' instructions are required.
 *
 * @param ptr    address in memory to add incr to
 * @param incr   amount to increment memory location by (signed)
 *
 * @return Value of memory location before increment
 */
static inline int64_t bdk_atomic_fetch_and_add64(int64_t *ptr, int64_t incr)
{
    uint64_t ret;
    BDK_SYNCW;
    ret = bdk_atomic_fetch_and_add64_nosync(ptr, incr);
    BDK_SYNCW;
    return ret;
}

/**
 * Atomically adds a signed value to a 32 bit (aligned) memory location,
 * and returns previous value.
 *
 * This version does not perform 'sync' operations to enforce memory
 * operations.  This should only be used when there are no memory operation
 * ordering constraints.  (This should NOT be used for reference counting -
 * use the standard version instead.)
 *
 * @param ptr    address in memory to add incr to
 * @param incr   amount to increment memory location by (signed)
 *
 * @return Value of memory location before increment
 */
static inline int32_t bdk_atomic_fetch_and_add32_nosync(int32_t *ptr, int32_t incr)
{
    uint32_t ret;

    if (__builtin_constant_p(incr) && incr == 1)
    {
        __asm__ __volatile__(
            "lai  %0,(%2)"
            : "=r" (ret), "+m" (*ptr) : "r" (ptr) : "memory");
    }
    else if (__builtin_constant_p(incr) && incr == -1)
    {
        __asm__ __volatile__(
            "lad  %0,(%2)"
            : "=r" (ret), "+m" (*ptr) : "r" (ptr) : "memory");
    }
    else
    {
        __asm__ __volatile__(
            "laa  %0,(%2),%3"
            : "=r" (ret), "+m" (*ptr) : "r" (ptr), "r" (incr) : "memory");
    }

    return (ret);
}

/**
 * Atomically adds a signed value to a 32 bit (aligned) memory location,
 * and returns previous value.
 *
 * Memory access ordering is enforced before/after the atomic operation,
 * so no additional 'sync' instructions are required.
 *
 * @param ptr    address in memory to add incr to
 * @param incr   amount to increment memory location by (signed)
 *
 * @return Value of memory location before increment
 */
static inline int32_t bdk_atomic_fetch_and_add32(int32_t *ptr, int32_t incr)
{
    uint32_t ret;
    BDK_SYNCW;
    ret = bdk_atomic_fetch_and_add32_nosync(ptr, incr);
    BDK_SYNCW;
    return ret;
}

/**
 * Atomically set bits in a 64 bit (aligned) memory location,
 * and returns previous value.
 *
 * This version does not perform 'sync' operations to enforce memory
 * operations.  This should only be used when there are no memory operation
 * ordering constraints.
 *
 * @param ptr    address in memory
 * @param mask   mask of bits to set
 *
 * @return Value of memory location before setting bits
 */
static inline uint64_t bdk_atomic_fetch_and_bset64_nosync(uint64_t *ptr, uint64_t mask)
{
    uint64_t tmp, ret;

    __asm__ __volatile__(
    ".set noreorder         \n"
    "1: lld  %[tmp], %[val] \n"
    "   move %[ret], %[tmp] \n"
    "   or   %[tmp], %[msk] \n"
    "   scd  %[tmp], %[val] \n"
    "   beqz %[tmp], 1b     \n"
    "   nop                 \n"
    ".set reorder           \n"
    : [val] "+m" (*ptr), [tmp] "=&r" (tmp), [ret] "=&r" (ret)
    : [msk] "r" (mask)
    : "memory");

    return (ret);
}

/**
 * Atomically set bits in a 32 bit (aligned) memory location,
 * and returns previous value.
 *
 * This version does not perform 'sync' operations to enforce memory
 * operations.  This should only be used when there are no memory operation
 * ordering constraints.
 *
 * @param ptr    address in memory
 * @param mask   mask of bits to set
 *
 * @return Value of memory location before setting bits
 */
static inline uint32_t bdk_atomic_fetch_and_bset32_nosync(uint32_t *ptr, uint32_t mask)
{
    uint32_t tmp, ret;

    __asm__ __volatile__(
    ".set noreorder         \n"
    "1: ll   %[tmp], %[val] \n"
    "   move %[ret], %[tmp] \n"
    "   or   %[tmp], %[msk] \n"
    "   sc   %[tmp], %[val] \n"
    "   beqz %[tmp], 1b     \n"
    "   nop                 \n"
    ".set reorder           \n"
    : [val] "+m" (*ptr), [tmp] "=&r" (tmp), [ret] "=&r" (ret)
    : [msk] "r" (mask)
    : "memory");

    return (ret);
}

/**
 * Atomically clear bits in a 64 bit (aligned) memory location,
 * and returns previous value.
 *
 * This version does not perform 'sync' operations to enforce memory
 * operations.  This should only be used when there are no memory operation
 * ordering constraints.
 *
 * @param ptr    address in memory
 * @param mask   mask of bits to clear
 *
 * @return Value of memory location before clearing bits
 */
static inline uint64_t bdk_atomic_fetch_and_bclr64_nosync(uint64_t *ptr, uint64_t mask)
{
    uint64_t tmp, ret;

    __asm__ __volatile__(
    ".set noreorder         \n"
    "   nor  %[msk], 0      \n"
    "1: lld  %[tmp], %[val] \n"
    "   move %[ret], %[tmp] \n"
    "   and  %[tmp], %[msk] \n"
    "   scd  %[tmp], %[val] \n"
    "   beqz %[tmp], 1b     \n"
    "   nop                 \n"
    ".set reorder           \n"
    : [val] "+m" (*ptr), [tmp] "=&r" (tmp), [ret] "=&r" (ret), [msk] "+r" (mask)
    : : "memory");

    return (ret);
}

/**
 * Atomically clear bits in a 32 bit (aligned) memory location,
 * and returns previous value.
 *
 * This version does not perform 'sync' operations to enforce memory
 * operations.  This should only be used when there are no memory operation
 * ordering constraints.
 *
 * @param ptr    address in memory
 * @param mask   mask of bits to clear
 *
 * @return Value of memory location before clearing bits
 */
static inline uint32_t bdk_atomic_fetch_and_bclr32_nosync(uint32_t *ptr, uint32_t mask)
{
    uint32_t tmp, ret;

    __asm__ __volatile__(
    ".set noreorder         \n"
    "   nor  %[msk], 0      \n"
    "1: ll   %[tmp], %[val] \n"
    "   move %[ret], %[tmp] \n"
    "   and  %[tmp], %[msk] \n"
    "   sc   %[tmp], %[val] \n"
    "   beqz %[tmp], 1b     \n"
    "   nop                 \n"
    ".set reorder           \n"
    : [val] "+m" (*ptr), [tmp] "=&r" (tmp), [ret] "=&r" (ret), [msk] "+r" (mask)
    : : "memory");

    return (ret);
}

/**
 * Atomically swaps value in 64 bit (aligned) memory location,
 * and returns previous value.
 *
 * This version does not perform 'sync' operations to enforce memory
 * operations.  This should only be used when there are no memory operation
 * ordering constraints.
 *
 * @param ptr       address in memory
 * @param new_val   new value to write
 *
 * @return Value of memory location before swap operation
 */
static inline uint64_t bdk_atomic_swap64_nosync(uint64_t *ptr, uint64_t new_val)
{
    uint64_t ret;

    if (__builtin_constant_p(new_val) && new_val == 0)
    {
        __asm__ __volatile__(
            "lacd  %0,(%2)"
            : "=r" (ret), "+m" (*ptr) : "r" (ptr) : "memory");
    }
    else if (__builtin_constant_p(new_val) && new_val == ~0ull)
    {
        __asm__ __volatile__(
            "lasd  %0,(%2)"
            : "=r" (ret), "+m" (*ptr) : "r" (ptr) : "memory");
    }
    else
    {
        __asm__ __volatile__(
            "lawd  %0,(%2),%3"
            : "=r" (ret), "+m" (*ptr) : "r" (ptr), "r" (new_val) : "memory");
    }

    return (ret);
}

/**
 * Atomically swaps value in 32 bit (aligned) memory location,
 * and returns previous value.
 *
 * This version does not perform 'sync' operations to enforce memory
 * operations.  This should only be used when there are no memory operation
 * ordering constraints.
 *
 * @param ptr       address in memory
 * @param new_val   new value to write
 *
 * @return Value of memory location before swap operation
 */
static inline uint32_t bdk_atomic_swap32_nosync(uint32_t *ptr, uint32_t new_val)
{
    uint32_t ret;

    if (__builtin_constant_p(new_val) && new_val == 0)
    {
        __asm__ __volatile__(
            "lac  %0,(%2)"
            : "=r" (ret), "+m" (*ptr) : "r" (ptr) : "memory");
    }
    else if (__builtin_constant_p(new_val) && new_val == ~0u)
    {
        __asm__ __volatile__(
            "las  %0,(%2)"
            : "=r" (ret), "+m" (*ptr) : "r" (ptr) : "memory");
    }
    else
    {
        __asm__ __volatile__(
            "law  %0,(%2),%3"
            : "=r" (ret), "+m" (*ptr) : "r" (ptr), "r" (new_val) : "memory");
    }

    return (ret);
}

/** @} */
