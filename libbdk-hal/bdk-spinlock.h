/**
 * @file
 *
 * Implementation of spinlocks.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * Spinlocks
 */
typedef union
{
    uint64_t combined;
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint32_t ticket;
        uint32_t serving;
#else
        uint32_t serving;
        uint32_t ticket;
#endif
    } s;
} bdk_spinlock_t;

/**
 * Initialize a spinlock
 *
 * @param lock   Lock to initialize
 */
static inline void bdk_spinlock_init(bdk_spinlock_t *lock)
{
    __atomic_store_8(&lock->combined, 0, __ATOMIC_RELAXED);
}

/**
 * Releases lock
 *
 * @param lock   pointer to lock structure
 */
static inline void bdk_spinlock_unlock(bdk_spinlock_t *lock) __attribute__ ((pure, always_inline));
static inline void bdk_spinlock_unlock(bdk_spinlock_t *lock)
{
    __atomic_store_4(&lock->s.serving, lock->s.serving + 1, __ATOMIC_RELEASE);
}

/**
 * Gets lock, spins until lock is taken
 *
 * @param lock   pointer to lock structure
 */
static inline void bdk_spinlock_lock(bdk_spinlock_t *lock) __attribute__ ((pure, always_inline));
static inline void bdk_spinlock_lock(bdk_spinlock_t *lock)
{
    uint64_t combined;
    uint32_t ticket;
    uint32_t serving;

    asm volatile (
        "mov %[serving], 1<<32                      \n"
        "ldadda %[serving], %[combined], [%[ptr]]   \n"
        "and %[serving], %[combined], 0xffffffff    \n"
        "lsr %[ticket], %[combined], 32             \n"
        "cmp %[ticket], %[serving]                  \n"
        "b.eq 1f                                    \n"
     "2: ldxr %w[serving], [%[ptr]]                 \n"
        "cmp %[ticket], %[serving]                  \n"
        "b.ne 2b                                    \n"
     "1:                                            \n"
        : [serving] "=&r" (serving), [ticket] "=&r" (ticket), [combined] "=&r" (combined), "+m" (lock->combined)
        : [ptr] "r" (&lock->combined)
        : "memory"
    );
}

/**
 * Trys to get the lock, failing if we can't get it immediately
 *
 * @param lock   pointer to lock structure
 */
static inline int bdk_spinlock_trylock(bdk_spinlock_t *lock) __attribute__ ((pure, always_inline));
static inline int bdk_spinlock_trylock(bdk_spinlock_t *lock)
{
    uint64_t combined = __atomic_load_8(&lock->combined, __ATOMIC_RELAXED);
    uint32_t ticket = combined >> 32;
    uint32_t serving = (uint32_t)combined;
    if (ticket != serving)
        return -1;
    uint64_t new_combined = combined + (1ull << 32);
    return !__atomic_compare_exchange_8(&lock->combined, &combined, new_combined, 0, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED);
}

/** @} */
