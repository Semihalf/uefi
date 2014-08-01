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
    int64_t combined;
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        int32_t ticket;
        int32_t serving;
#else
        int32_t serving;
        int32_t ticket;
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
    lock->s.ticket = 0;
    lock->s.serving = 0;
}

/**
 * Releases lock
 *
 * @param lock   pointer to lock structure
 */
static inline void bdk_spinlock_unlock(bdk_spinlock_t *lock)
{
    BDK_WMB;
    lock->s.serving++;
    BDK_WMB;
}

/**
 * Gets lock, spins until lock is taken
 *
 * @param lock   pointer to lock structure
 */
static inline void bdk_spinlock_lock(bdk_spinlock_t *lock)
{
    BDK_WMB;
    int64_t combined = bdk_atomic_fetch_and_add64_nosync(&lock->combined, 1ull<<32);
    int32_t ticket = combined >> 32;
    int32_t serving = (int32_t)combined;

    while (bdk_unlikely(serving != ticket))
        serving = bdk_atomic_get32(&lock->s.serving);
}

/** @} */
