#include <bdk.h>

#define STACK_CANARY 0x0BADBADBADBADBADull

typedef struct bdk_thread
{
    struct bdk_thread *next;
    uint64_t    regs[31];   /* Reg 0 not stored */
    uint64_t    coremask;
    uint64_t    pc;
    uint64_t    lo;
    uint64_t    hi;
    uint64_t    stack_canary;
    uint64_t    stack[0];
} bdk_thread_t;

static bdk_thread_t*    bdk_thread_head;
static bdk_thread_t*    bdk_thread_tail;
static bdk_spinlock_t   bdk_thread_lock;
extern void __bdk_thread_switch(bdk_thread_t* next_context);


/**
 * Main thread body for all threads
 *
 * @param func   User function to call
 * @param arg0   First argument to the user function
 * @param arg1   Second argument to the user function
 */
static void __bdk_thread_body(bdk_thread_func_t func, int arg0, void *arg1)
{
    /* As an artifact of how a thread initially start, the thread lock
        will be left locked by yield() since we never return switch() */
    bdk_spinlock_unlock(&bdk_thread_lock);
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
    return 0;
}


/**
 * Yield the current thread and run a new one
 */
void bdk_thread_yield(void)
{
    bdk_thread_t *current;
    uint64_t coremask = 1ull << bdk_get_core_num();
    BDK_MF_COP0(current, COP0_USERLOCAL);

    if (!current)
        return;

    /* Make sure the current context points nowhere as it is going on the end of the list */
    current->next = NULL;
    if (current->stack_canary != STACK_CANARY)
        bdk_fatal("bdk_thread_yield() detected a stack overflow\n");

    bdk_spinlock_lock(&bdk_thread_lock);

    /* Find the first thread that can run on this core */
    bdk_thread_t *next = bdk_thread_head;
    while (next && !(next->coremask & coremask))
        next = next->next;

    /* If next is NULL then there are no other threads ready to run and we
        will continue without doing anything */
    if (next)
    {
        /* Put the current context on the end of the list */
        bdk_thread_tail->next = current;
        bdk_thread_tail = current;
        bdk_thread_head = bdk_thread_head->next;

        /* Do the context switch */
        __bdk_thread_switch(next);
    }

    bdk_spinlock_unlock(&bdk_thread_lock);
}


/**
 * Create a new thread. It won't run until the next yield call.
 *
 * @param coremask Mask of cores the thread can run on. Each set bit is an allowed
 *                 core. Zero and -1 are both shortcuts for all cores.
 * @param func     Function to run as a thread
 * @param arg0     First argument to the function
 * @param arg1     Second argument to the function
 *
 * @return Zero on success, negative on failure
 */
int bdk_thread_create(uint64_t coremask, bdk_thread_func_t func, int arg0, void *arg1)
{
    extern void _gp;
    bdk_thread_t *thread;
    int stack_size = bdk_config_get(BDK_CONFIG_THREAD_STACK_SIZE);

    thread = calloc(1, sizeof(bdk_thread_t) + stack_size);
    if (thread == NULL)
    {
        bdk_error("Unable to allocate memory for new thread\n");
        return -1;
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
    thread->stack_canary = STACK_CANARY;

    bdk_spinlock_lock(&bdk_thread_lock);
    if (bdk_thread_tail)
    {
        bdk_thread_tail->next = thread;
        bdk_thread_tail = thread;
    }
    else
    {
        bdk_thread_head = thread;
        bdk_thread_tail = thread;
    }
    bdk_spinlock_unlock(&bdk_thread_lock);
    return 0;
}


/**
 * Destroy the currently running thread. This never returns.
 */
void bdk_thread_destroy(void)
{
    bdk_thread_t *current;
    uint64_t coremask = 1ull << bdk_get_core_num();
    BDK_MF_COP0(current, COP0_USERLOCAL);

    if (current)
    {
        // FIXME
        bdk_fatal("bdk_thread_destroy() not implemented\n");
    }

    while (1)
    {
        bdk_spinlock_lock(&bdk_thread_lock);

        /* Find the first thread that can run on this core */
        bdk_thread_t *next = bdk_thread_head;
        while (next && !(next->coremask & coremask))
            next = next->next;

        /* If next is NULL then there are no other threads ready to run and we
            will continue without doing anything */
        if (next)
        {
            if (next == bdk_thread_tail)
                bdk_thread_tail = NULL;
            bdk_thread_head = bdk_thread_head->next;

            /* Do the context switch */
            __bdk_thread_switch(next);
            bdk_fatal("bdk_thread_destroy() should never get here\n");
        }

        bdk_spinlock_unlock(&bdk_thread_lock);
        BDK_ASM_PAUSE;
    }
}


