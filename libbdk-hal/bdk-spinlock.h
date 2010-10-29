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
    volatile uint32_t value;
} bdk_spinlock_t;

/**
 * Initialize a spinlock
 *
 * @param lock   Lock to initialize
 */
static inline void bdk_spinlock_init(bdk_spinlock_t *lock)
{
    lock->value = 0;
}


/**
 * Return non-zero if the spinlock is currently locked
 *
 * @param lock   Lock to check
 * @return Non-zero if locked
 */
static inline int bdk_spinlock_locked(bdk_spinlock_t *lock)
{
    return (lock->value != 0);
}


/**
 * Releases lock
 *
 * @param lock   pointer to lock structure
 */
static inline void bdk_spinlock_unlock(bdk_spinlock_t *lock)
{
    BDK_SYNCW;
    lock->value = 0;
    BDK_SYNCW;
}


/**
 * Attempts to take the lock, but does not spin if lock is not available.
 * May take some time to acquire the lock even if it is available
 * due to the ll/sc not succeeding.
 *
 * @param lock   pointer to lock structure
 *
 * @return 0: lock successfully taken
 *         1: lock not taken, held by someone else
 * These return values match the Linux semantics.
 */

static inline unsigned int bdk_spinlock_trylock(bdk_spinlock_t *lock)
{
    unsigned int tmp;

    __asm__ __volatile__(
    ".set noreorder         \n"
    "1: ll   %[tmp], %[val] \n"
    "   bnez %[tmp], 2f     \n"  // if lock held, fail immediately
    "   li   %[tmp], 1      \n"
    "   sc   %[tmp], %[val] \n"
    "   beqz %[tmp], 1b     \n"
    "   li   %[tmp], 0      \n"
    "2:                     \n"
    ".set reorder           \n"
    : [val] "+m" (lock->value), [tmp] "=&r" (tmp)
    :
    : "memory");

    return (!!tmp);  /* normalize to 0 or 1 */
}

/**
 * Gets lock, spins until lock is taken
 *
 * @param lock   pointer to lock structure
 */
static inline void bdk_spinlock_lock(bdk_spinlock_t *lock)
{
    unsigned int tmp;

    __asm__ __volatile__(
    ".set noreorder         \n"
    "1: ll   %[tmp], %[val]  \n"
    "   bnez %[tmp], 1b     \n"
    "   li   %[tmp], 1      \n"
    "   sc   %[tmp], %[val] \n"
    "   beqz %[tmp], 1b     \n"
    "   nop                \n"
    ".set reorder           \n"
    : [val] "+m" (lock->value), [tmp] "=&r" (tmp)
    :
    : "memory");

}

/** @} */
