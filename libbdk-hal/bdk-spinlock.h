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
    uint64_t combined = __atomic_fetch_add(&lock->combined, 1ull<<32, __ATOMIC_ACQUIRE);
    uint32_t ticket = combined >> 32;
    uint32_t serving = (uint32_t)combined;

    while (bdk_unlikely(serving != ticket))
        serving = __atomic_load_4(&lock->s.serving, __ATOMIC_RELAXED);
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
