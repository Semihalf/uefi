/**
 * @file
 *
 * Functions for controlling threads.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @defgroup thread Threading library
 * @{
 */

/* Use a larger stack size for main() as it tends to do lots of
    extra stuff. For example, DDR init requires a bigger stack */
#define BDK_THREAD_MAIN_STACK_SIZE 16384

typedef void (*bdk_thread_func_t)(int arg, void *arg1);

extern int bdk_thread_initialize(void);
extern void bdk_thread_yield(void);
extern int bdk_thread_create(bdk_node_t node, uint64_t coremask, bdk_thread_func_t func, int arg0, void *arg1, int stack_size);
extern void bdk_thread_destroy(void) __attribute__ ((noreturn));
extern void bdk_thread_first(bdk_thread_func_t func, int arg0, void *arg1, int stack_size) __attribute__ ((noreturn));

/**
 * Number of the Core on which the program is currently running.
 *
 * @return Number of cores
 */
static inline int bdk_get_core_num(void)
{
    int core_num;
    BDK_RDHWRNV(core_num, 0);
    return core_num;
}

/**
 * Return a mask representing this core in a 64bit bitmask
 *
 * @return
 */
static inline uint64_t bdk_core_to_mask(void)
{
    return 1ull << (bdk_get_core_num() & 0x7f);
}

static inline int bdk_is_boot_core(void)
{
    int coreid = bdk_get_core_num();
    return coreid == (bdk_numa_id(BDK_NODE_MASTER) << 7);
}

static inline void *bdk_thread_get_id(void)
{
    uint64_t current;
    BDK_MF_COP0(current, COP0_USERLOCAL);
    /* If we haven't started threading yet use the core number. Add one
        so the thread id is never zero */
    if (!current)
        current = bdk_get_core_num() + 1;
    return (void*)current;
}

/** @} */
