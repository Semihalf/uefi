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


typedef void (*bdk_thread_func_t)(int arg, void *arg1);

extern int bdk_thread_initialize(void);
extern void bdk_thread_yield(void);
extern int bdk_thread_create(uint64_t coremask, bdk_thread_func_t func, int arg0, void *arg1);
extern void bdk_thread_destroy(void) __attribute__ ((noreturn));

/** @} */
