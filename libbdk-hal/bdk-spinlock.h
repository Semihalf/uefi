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
 * Spinlocks for Octeon
 */
typedef union
{
    int64_t combined;
    struct
    {
        int32_t ticket;
        int32_t serving;
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
    BDK_SYNCW;
    lock->s.serving++;
    BDK_SYNCW;
}

/**
 * Gets lock, spins until lock is taken
 *
 * @param lock   pointer to lock structure
 */
static inline void bdk_spinlock_lock(bdk_spinlock_t *lock)
{
    BDK_SYNCW;
    int64_t combined = bdk_atomic_fetch_and_add64_nosync(&lock->combined, 1ull<<32);
    BDK_PREFETCH(lock, 0); /* Prefetch the lock assuming other data is in it */
    int32_t ticket = combined >> 32;
    int32_t serving = (int32_t)combined;

    while (bdk_unlikely(serving != ticket))
        serving = *(volatile int32_t*)&lock->s.serving;
}

/** @} */
