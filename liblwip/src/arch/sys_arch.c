#include <bdk.h>
#include <assert.h>
#include <lwip/sys.h>

static bdk_rlock_t arch_lock;

/**
 * sys_init() must be called before anthing else.
 */
void sys_init(void)
{
    bdk_rlock_init(&arch_lock);
}

/**
 * Create a new mbox of specified size
 *
 * @param mbox   pointer to the mbox to create
 * @param size   (miminum) number of messages in this mbox
 *
 * @return ERR_OK if successful, another err_t otherwise
 */
err_t sys_mbox_new(sys_mbox_t *mbox, int size)
{
    bdk_rlock_init(&mbox->lock);
    mbox->head = 0;
    mbox->count = 0;
    return ERR_OK;
}

/**
 * Post a message to an mbox - may not fail
 * -> blocks if full, only used from tasks not from ISR
 *
 * @param mbox   mbox to posts the message
 * @param msg    message to post (ATTENTION: can be NULL)
 */
void sys_mbox_post(sys_mbox_t *mbox, void *msg)
{
    while (1)
    {
        while (mbox->count >= SYS_MBOX_MAX)
            bdk_thread_yield();
        bdk_rlock_lock(&mbox->lock);
        if (mbox->count < SYS_MBOX_MAX)
        {
            int loc = (mbox->head + mbox->count) % SYS_MBOX_MAX;
            mbox->message[loc] = msg;
            mbox->count++;
            bdk_rlock_unlock(&mbox->lock);
            return;
        }
        bdk_rlock_unlock(&mbox->lock);
    }
}

/**
 * Try to post a message to an mbox - may fail if full or ISR
 *
 * @param mbox   mbox to posts the message
 * @param msg    message to post (ATTENTION: can be NULL)
 *
 * @return
 */
err_t sys_mbox_trypost(sys_mbox_t *mbox, void *msg)
{
    if (bdk_rlock_try_lock(&mbox->lock))
        return ERR_WOULDBLOCK;

    if (mbox->count < SYS_MBOX_MAX)
    {
        int loc = (mbox->head + mbox->count) % SYS_MBOX_MAX;
        mbox->message[loc] = msg;
        mbox->count++;
        bdk_rlock_unlock(&mbox->lock);
        return ERR_OK;
    }

    bdk_rlock_unlock(&mbox->lock);
    return ERR_WOULDBLOCK;
}

/**
 * Wait for a new message to arrive in the mbox
 *
 * @param mbox    mbox to get a message from
 * @param msg     pointer where the message is stored
 * @param timeout maximum time (in milliseconds) to wait for a message
 *
 * @return time (in milliseconds) waited for a message, may be 0 if not waited
 *         or SYS_ARCH_TIMEOUT on timeout
 *         The returned time has to be accurate to prevent timer jitter!
 */
u32_t sys_arch_mbox_fetch(sys_mbox_t *mbox, void **msg, u32_t timeout)
{
    uint64_t start_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    uint64_t cycle_rate = bdk_clock_get_rate(BDK_CLOCK_CORE) / 1000;
    uint64_t timeout_cycle = cycle_rate * timeout + start_cycle;
    if (timeout == 0)
        timeout_cycle = -1;
    while (bdk_clock_get_count(BDK_CLOCK_CORE) < timeout_cycle)
    {
        if (sys_arch_mbox_tryfetch(mbox, msg) != SYS_MBOX_EMPTY)
            return (bdk_clock_get_count(BDK_CLOCK_CORE) - start_cycle) / cycle_rate;
        bdk_wait_usec(1000);
    }
    return SYS_ARCH_TIMEOUT;
}

/**
 * Wait for a new message to arrive in the mbox
 *
 * @param mbox   mbox to get a message from
 * @param msg    pointer where the message is stored
 *
 * @return 0 (milliseconds) if a message has been received
 *         or SYS_MBOX_EMPTY if the mailbox is empty
 */
u32_t sys_arch_mbox_tryfetch(sys_mbox_t *mbox, void **msg)
{
    if (bdk_rlock_try_lock(&mbox->lock) == 0)
    {
        if (mbox->count)
        {
            *msg = mbox->message[mbox->head];
            mbox->head = (mbox->head + 1) % SYS_MBOX_MAX;
            mbox->count--;
            bdk_rlock_unlock(&mbox->lock);
            return 0;
        }
    }
    bdk_rlock_unlock(&mbox->lock);
    return SYS_MBOX_EMPTY;
}

/**
 * Delete an mbox
 *
 * @param mbox   mbox to delete
 */
void sys_mbox_free(sys_mbox_t *mbox)
{
    assert(mbox->count == 0);
    mbox->head = 0;
}

/**
 * Check if an mbox is valid/allocated: return 1 for valid, 0 for invalid
 *
 * @param mbox
 *
 * @return
 */
int sys_mbox_valid(sys_mbox_t *mbox)
{
    return (mbox->head != -1);
}

/**
 * Set an mbox invalid so that sys_mbox_valid returns 0
 *
 * @param mbox
 */
void sys_mbox_set_invalid(sys_mbox_t *mbox)
{
    mbox->head = -1;
}

/**
 * SYS_ARCH_PROTECT
 * Perform a "fast" protect. This could be implemented by
 * disabling interrupts for an embedded system or by using a semaphore or
 * mutex. The implementation should allow calling SYS_ARCH_PROTECT when
 * already protected. The old protection level is returned in the variable
 * "lev". This macro will default to calling the sys_arch_protect() function
 * which should be implemented in sys_arch.c. If a particular port needs a
 * different implementation, then this macro may be defined in sys_arch.h
 *
 * @return
 */
sys_prot_t sys_arch_protect(void)
{
    bdk_rlock_lock(&arch_lock);
    return 0;
}

/**
 * SYS_ARCH_UNPROTECT
 * Perform a "fast" set of the protection level to "lev". This could be
 * implemented by setting the interrupt level to "lev" within the MACRO or by
 * using a semaphore or mutex.  This macro will default to calling the
 * sys_arch_unprotect() function which should be implemented in
 * sys_arch.c. If a particular port needs a different implementation, then
 * this macro may be defined in sys_arch.h
 *
 * @param pval
 */
void sys_arch_unprotect(sys_prot_t pval)
{
    bdk_rlock_unlock(&arch_lock);
}

/**
 * The only thread function:
 * Creates a new thread
 *
 * @param name      human-readable name for the thread (used for debugging purposes)
 * @param thread    thread-function
 * @param arg       parameter passed to 'thread'
 * @param stacksize stack size in bytes for the new thread (may be ignored by ports)
 * @param prio      priority of the new thread (may be ignored by ports)
 *
 * @return
 */
sys_thread_t sys_thread_new(const char *name, lwip_thread_fn thread, void *arg, int stacksize, int prio)
{
    if (bdk_thread_create(0, (bdk_thread_func_t)thread, (long)arg, NULL, stacksize))
        return NULL;
    else
        return (void*)1;
}

