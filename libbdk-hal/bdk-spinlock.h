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
typedef struct
{
    int32_t lock;
} bdk_spinlock_t;

/**
 * Initialize a spinlock
 *
 * @param lock   Lock to initialize
 */
static inline void bdk_spinlock_init(bdk_spinlock_t *lock)
{
    lock->lock = 0;
}

/**
 * Releases lock
 *
 * @param lock   pointer to lock structure
 */
static inline void bdk_spinlock_unlock(bdk_spinlock_t *lock)
{
    BDK_SYNCW;
    lock->lock = 0;
    BDK_SYNCW;
}

/**
 * Gets lock, spins until lock is taken
 *
 * @param lock   pointer to lock structure
 */
static inline void bdk_spinlock_lock(bdk_spinlock_t *lock)
{
    int32_t tmp;
    BDK_SYNCW;
    __asm__ __volatile__(
    ".set noreorder         \n"
    "1: ll   %[tmp], %[val] \n"
    "   bnez %[tmp], 1b     \n"
    "   li   %[tmp], 1      \n"
    "   sc   %[tmp], %[val] \n"
    "   beqz %[tmp], 1b     \n"
    "    nop                \n"
    ".set reorder           \n"
    : [val] "+m" (lock->lock), [tmp] "=&r" (tmp)
    :
    : "memory");
}

/** @} */
