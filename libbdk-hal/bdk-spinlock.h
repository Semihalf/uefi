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
typedef struct {
    int32_t ticket;
    int32_t serving;
} bdk_spinlock_t;

/**
 * Initialize a spinlock
 *
 * @param lock   Lock to initialize
 */
static inline void bdk_spinlock_init(bdk_spinlock_t *lock)
{
    lock->ticket = 0;
    lock->serving = 0;
}

/**
 * Releases lock
 *
 * @param lock   pointer to lock structure
 */
static inline void bdk_spinlock_unlock(bdk_spinlock_t *lock)
{
    bdk_atomic_add32(&lock->serving, 1);
}

/**
 * Gets lock, spins until lock is taken
 *
 * @param lock   pointer to lock structure
 */
static inline void bdk_spinlock_lock(bdk_spinlock_t *lock)
{
    int32_t ticket = bdk_atomic_fetch_and_add32_nosync(&lock->ticket, 1);
    BDK_SYNCW;
    while ((volatile int32_t)lock->serving != ticket)
    {
        BDK_ASM_PAUSE;
    }
}

/** @} */
