/**
 * @file
 *
 * This file provides reader/writer locks.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 *
 */

/* Flags for lock value in rw lock structure */
#define BDK_RWLOCK_WRITE_FLAG     0x1
#define BDK_RWLOCK_READ_INC       0x2


/* Writer preference locks (wp).  Can be starved by writers.  When a writer
 * is waiting, no readers are given the lock until all writers are done.
 */
typedef struct
{
    volatile uint32_t lock;
    volatile uint32_t write_req;
    volatile uint32_t write_comp;
} bdk_rwlock_wp_lock_t;

/**
 * Initialize a reader/writer lock.  This must be done
 * by a single core before used.
 *
 * @param lock   pointer to rwlock structure
 */
static inline void bdk_rwlock_wp_init(bdk_rwlock_wp_lock_t *lock)
{
    lock->lock = 0;
    lock->write_req = 0;
    lock->write_comp = 0;
}

/**
 * Perform a reader lock.  If a writer is pending, this
 * will wait for that writer to complete before locking.
 *
 * NOTE: Each thread/process must only lock any rwlock
 * once, or else a deadlock may result.
 *
 * @param lock   pointer to rwlock structure
 */
static inline void bdk_rwlock_wp_read_lock(bdk_rwlock_wp_lock_t *lock)
{

    /* Wait for outstanding write requests to be serviced */
    while (lock->write_req != lock->write_comp)
        ;
    /* Add ourselves to interested reader count */
    bdk_atomic_add32_nosync((int32_t *)&(lock->lock), BDK_RWLOCK_READ_INC);
    /* Wait for writer to finish.  No writer will start again
    ** until after we are done since we have already incremented
    ** the reader count
    */
    while (lock->lock & BDK_RWLOCK_WRITE_FLAG)
        ;

}

/**
 * Perform a reader unlock.
 *
 * @param lock   pointer to rwlock structure
 */
static inline void bdk_rwlock_wp_read_unlock(bdk_rwlock_wp_lock_t *lock)
{
    /* Remove ourselves to reader count */
    bdk_atomic_add32_nosync((int32_t *)&(lock->lock), -BDK_RWLOCK_READ_INC);
}

/**
 * Perform a writer lock.  Any readers that attempt
 * to get a lock while there are any pending write locks
 * will wait until all writers have completed.  Starvation
 * of readers by writers is possible and must be avoided
 * by the application.
 *
 * @param lock   pointer to rwlock structure
 */
static inline void bdk_rwlock_wp_write_lock(bdk_rwlock_wp_lock_t *lock)
{
    /* Get previous value of write requests */
    uint32_t prev_writers = ((uint32_t)bdk_atomic_fetch_and_add32((int32_t *)&(lock->write_req), 1));
    /* Spin until our turn */
    while (prev_writers != lock->write_comp)
        ;
    /* Spin until no other readers or writers, then set write flag */
    while (!bdk_atomic_compare_and_store32((uint32_t *)&(lock->lock), 0, BDK_RWLOCK_WRITE_FLAG))
        ;

}
/**
 * Perform a writer unlock.
 *
 * @param lock   pointer to rwlock structure
 */
static inline void bdk_rwlock_wp_write_unlock(bdk_rwlock_wp_lock_t *lock)
{
    /* Remove our writer flag */
    BDK_SYNCWS;  /* Make sure all writes in protected region are visible before unlock */
    bdk_atomic_add32_nosync((int32_t *)&(lock->lock), -BDK_RWLOCK_WRITE_FLAG);
    bdk_atomic_add32_nosync((int32_t *)&(lock->write_comp), 1);
    BDK_SYNCWS;  /* push unlock writes out, but don't stall */
}

