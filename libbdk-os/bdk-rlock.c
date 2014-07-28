#include <bdk.h>
#include <assert.h>
#include <sys/lock.h>

/* These locks are in the sys/lock.h header since they are used by the C
    library */

void bdk_rlock_init(bdk_rlock_t *lock)
{
    lock->count = 0;
    lock->owner = NULL;
}

void bdk_rlock_lock(bdk_rlock_t *lock)
{
    void *current = bdk_thread_get_id();

    if (lock->count && (current == lock->owner))
    {
        lock->count++;
        return;
    }
    assert((current != lock->owner) || !current);
    do
    {
        while ((volatile uint32_t)lock->count)
            bdk_thread_yield();
    } while (bdk_atomic_compare_and_store32(&lock->count, 0, 1) == 0);
    lock->owner = current;
}

int bdk_rlock_try_lock(bdk_rlock_t *lock)
{
    void *current = bdk_thread_get_id();
    if (lock->count)
    {
        if (current == lock->owner)
        {
            lock->count++;
            return 0;
        }
        else
            return -1;
    }
    else
    {
        assert((current != lock->owner) || !current);
        if (bdk_atomic_compare_and_store32(&lock->count, 0, 1))
        {
            lock->owner = current;
            return 0;
        }
        else
            return -1;
    }
}

void bdk_rlock_unlock(bdk_rlock_t *lock)
{
    void *current = bdk_thread_get_id();
    assert(current == lock->owner);
    assert(lock->count > 0);
    if (lock->count == 1)
    {
        BDK_WMB;
        lock->owner = NULL;
        lock->count = 0;
        BDK_WMB;
    }
    else
        lock->count--;
}

