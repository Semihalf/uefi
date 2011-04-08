#include <bdk.h>
#include <stdio.h>

#define STACK_CANARY 0x0BADBADBADBADBADull

typedef struct bdk_thread
{
    struct bdk_thread *next;
    uint64_t    regs[31];   /* Reg 0 not stored */
    uint64_t    coremask;
    uint64_t    pc;
    uint64_t    lo;
    uint64_t    hi;
    struct _reent lib_state;
    uint64_t    stack_canary;
    uint64_t    stack[0];
} bdk_thread_t;

static bdk_thread_t*    bdk_thread_head;
static bdk_thread_t*    bdk_thread_tail;
static bdk_spinlock_t   bdk_thread_lock;


/**
 * Main thread body for all threads
 *
 * @param func   User function to call
 * @param arg0   First argument to the user function
 * @param arg1   Second argument to the user function
 */
static void __bdk_thread_body(bdk_thread_func_t func, int arg0, void *arg1)
{
    func(arg0, arg1);
    bdk_thread_destroy();
}


/**
 * Initialize the BDK thread library
 *
 * @return Zero on success, negative on failure
 */
int bdk_thread_initialize(void)
{
    bdk_thread_head = NULL;
    bdk_thread_tail = NULL;
    bdk_spinlock_init(&bdk_thread_lock);
    return 0;
}

static bdk_thread_t *__bdk_thread_next(void)
{
    uint64_t coremask = 1ull << bdk_get_core_num();

    bdk_thread_t *prev = NULL;
    bdk_thread_t *next = bdk_thread_head;
    while (next && !(next->coremask & coremask))
    {
        prev = next;
        next = next->next;
    }

    if (next)
    {
        if (bdk_thread_tail == next)
            bdk_thread_tail = prev;
        if (prev)
            prev->next = next->next;
        else
            bdk_thread_head = next->next;
        next->next = NULL;
    }
    return next;
}

/**
 * Yield the current thread and run a new one
 */
void bdk_thread_yield(void)
{
    bdk_thread_t *current;
    BDK_MF_COP0(current, COP0_USERLOCAL);

    if (bdk_unlikely(!current))
        return;

    if (bdk_unlikely(current->stack_canary != STACK_CANARY))
        bdk_fatal("bdk_thread_yield() detected a stack overflow\n");

    if (bdk_thread_head == NULL)
        return;

    bdk_spinlock_lock(&bdk_thread_lock);

    /* Find the first thread that can run on this core */
    bdk_thread_t *next = __bdk_thread_next();

    /* If next is NULL then there are no other threads ready to run and we
        will continue without doing anything */
    if (next)
    {
        __bdk_thread_switch(next, 0);
        /* Unlock performed in __bdk_thread_switch_complete */
        return;
    }
    bdk_spinlock_unlock(&bdk_thread_lock);
}


/**
 * Create a new thread and return it. The thread will not be scheduled
 * as it isn't put in the thread list.
 *
 * @param coremask   Mask of cores the thread can run on. Each set bit is an allowed
 *                   core. Zero and -1 are both shortcuts for all cores.
 * @param func       Function to run as a thread
 * @param arg0       First argument to the function
 * @param arg1       Second argument to the function
 * @param stack_size Stack size for the new thread. Set to zero for the system default.
 *
 * @return Thread or NULL on failure
 */
void *__bdk_thread_create(uint64_t coremask, bdk_thread_func_t func, int arg0, void *arg1, int stack_size)
{
    extern void _gp;
    bdk_thread_t *thread;
    if (!stack_size)
        stack_size = bdk_config_get(BDK_CONFIG_THREAD_STACK_SIZE);

    thread = calloc(1, sizeof(bdk_thread_t) + stack_size);
    if (thread == NULL)
    {
        bdk_error("Unable to allocate memory for new thread\n");
        return NULL;
    }
    if (coremask == 0)
        coremask = -1;
    thread->coremask = coremask;
    thread->regs[4-1] = (uint64_t)func;
    thread->regs[5-1] = arg0;
    thread->regs[6-1] = (uint64_t)arg1;
    thread->regs[28-1] = (uint64_t)&_gp;
    thread->regs[29-1] = (uint64_t)thread->stack + stack_size;
    thread->pc = (uint64_t)__bdk_thread_body;
    _REENT_INIT_PTR(&thread->lib_state);
    thread->stack_canary = STACK_CANARY;
    thread->next = NULL;
    return thread;
}


/**
 * Create a new thread. The thread may be scheduled to any of the
 * cores supplied in the coremask. Note that a single thread is
 * created and may only run on one core at a time. The thread may
 * not start executing until the next yield call if all cores in
 * the coremask are currently busy.
 *
 * @param coremask   Mask of cores the thread can run on. Each set bit is an allowed
 *                   core. Zero and -1 are both shortcuts for all cores.
 * @param func       Function to run as a thread
 * @param arg0       First argument to the function
 * @param arg1       Second argument to the function
 * @param stack_size Stack size for the new thread. Set to zero for the system default.
 *
 * @return Zero on success, negative on failure
 */
int bdk_thread_create(uint64_t coremask, bdk_thread_func_t func, int arg0, void *arg1, int stack_size)
{
    bdk_thread_t *thread = __bdk_thread_create(coremask, func, arg0, arg1, stack_size);
    if (thread == NULL)
        return -1;

    bdk_spinlock_lock(&bdk_thread_lock);
    if (bdk_thread_tail)
        bdk_thread_tail->next = thread;
    else
        bdk_thread_head = thread;
    bdk_thread_tail = thread;
    bdk_spinlock_unlock(&bdk_thread_lock);
    return 0;
}


/**
 * Destroy the currently running thread. This never returns.
 */
void bdk_thread_destroy(void)
{
    static int dead_cores = 0;
    bdk_thread_t *current;
    BDK_MF_COP0(current, COP0_USERLOCAL);

    if (current)
        fflush(NULL);

    bdk_atomic_add32(&dead_cores, 1);
    while (1)
    {
        if (bdk_thread_head)
        {
            bdk_spinlock_lock(&bdk_thread_lock);
            /* Find the first thread that can run on this core */
            bdk_thread_t *next = __bdk_thread_next();

            /* If next is NULL then there are no other threads ready to run and we
                will continue without doing anything */
            if (next)
            {
                bdk_atomic_add32(&dead_cores, -1);
                __bdk_thread_switch(next, !!current);
                bdk_fatal("bdk_thread_destroy() should never get here\n");
            }
            bdk_spinlock_unlock(&bdk_thread_lock);
        }
        BDK_ASM_PAUSE;
        if (bdk_atomic_get32(&dead_cores) == bdk_octeon_num_cores())
            __bdk_die();
    }
}

struct _reent *__bdk_thread_getreent(void)
{
    bdk_thread_t *current;
    BDK_MF_COP0(current, COP0_USERLOCAL);
    if (current)
        return &current->lib_state;
    else
        return _global_impure_ptr;
}

void __bdk_thread_switch_complete(bdk_thread_t* old_context, int delete_old)
{
    if (bdk_unlikely(delete_old))
    {
        bdk_spinlock_unlock(&bdk_thread_lock);
        free(old_context);
    }
    else
    {
        if (bdk_likely(old_context))
        {
            if (bdk_thread_tail)
                bdk_thread_tail->next = old_context;
            else
                bdk_thread_head = old_context;
            bdk_thread_tail = old_context;
        }
        bdk_spinlock_unlock(&bdk_thread_lock);
    }
}
