#include <bdk.h>
#include <lwip/sys.h>

/**
 * Create a new semaphore
 *
 * @param sem    pointer to the semaphore to create
 * @param count  initial count of the semaphore
 *
 * @return ERR_OK if successful, another err_t otherwise
 */
err_t sys_sem_new(sys_sem_t *sem, u8_t count)
{
    sem->count = count;
    return ERR_OK;
}

/**
 * Signals a semaphore
 *
 * @param sem    the semaphore to signal
 */
void sys_sem_signal(sys_sem_t *sem)
{
    bdk_atomic_add32(&sem->count, 1);
}

/**
 * Wait for a semaphore for the specified timeout
 *
 * @param sem     the semaphore to wait for
 * @param timeout timeout in milliseconds to wait (0 = wait forever)
 *
 * @return time (in milliseconds) waited for the semaphore
 *         or SYS_ARCH_TIMEOUT on timeout
 */
u32_t sys_arch_sem_wait(sys_sem_t *sem, u32_t timeout)
{
    uint64_t start_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    uint64_t cycle_rate = bdk_clock_get_rate(BDK_CLOCK_CORE) / 1000;
    uint64_t timeout_cycle = cycle_rate * timeout + start_cycle;
    if (timeout == 0)
        timeout_cycle = -1;
    while (bdk_clock_get_count(BDK_CLOCK_CORE) < timeout_cycle)
    {
        if (bdk_atomic_fetch_and_add32(&sem->count, -1) > 0)
            return (bdk_clock_get_count(BDK_CLOCK_CORE) - start_cycle) / cycle_rate;
        else
            bdk_atomic_add32(&sem->count, 1);
        bdk_thread_yield();
    }
    return SYS_ARCH_TIMEOUT;
}

/**
 * Delete a semaphore
 *
 * @param sem    semaphore to delete
 */
void sys_sem_free(sys_sem_t *sem)
{
    /* Nothing to do */
}

/**
 * Check if a sempahore is valid/allocated: return 1 for valid, 0 for invalid
 *
 * @param sem
 *
 * @return
 */
int sys_sem_valid(sys_sem_t *sem)
{
    return (sem->count != -9999);
}

/**
 * Set a semaphore invalid so that sys_sem_valid returns 0
 *
 * @param sem
 */
void sys_sem_set_invalid(sys_sem_t *sem)
{
    sem->count = -9999;
}


