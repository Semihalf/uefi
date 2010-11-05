#ifndef __SYS_LOCK_H__
#define __SYS_LOCK_H__

#include <_ansi.h>

#ifdef __OCTEON__

typedef struct
{
    void *owner;
    unsigned int count;
} bdk_rlock_t;

typedef bdk_rlock_t _LOCK_T;
typedef bdk_rlock_t _LOCK_RECURSIVE_T;

#define BDK_RLOCK_DEFINE(name) bdk_rlock_t name = {0, 0}
extern void bdk_rlock_lock(bdk_rlock_t *lock);
extern int  bdk_rlock_try_lock(bdk_rlock_t *lock);
extern void bdk_rlock_unlock(bdk_rlock_t *lock);

#define __LOCK_INIT(class,lock)             class BDK_RLOCK_DEFINE(lock);
#define __LOCK_INIT_RECURSIVE(class,lock)   class BDK_RLOCK_DEFINE(lock);
#define __lock_init(lock)                   (_CAST_VOID 0)
#define __lock_init_recursive(lock)         (_CAST_VOID 0)
#define __lock_close(lock)                  (_CAST_VOID 0)
#define __lock_close_recursive(lock)        (_CAST_VOID 0)
#define __lock_acquire(lock)                bdk_rlock_lock(&lock)
#define __lock_acquire_recursive(lock)      bdk_rlock_lock(&lock)
#define __lock_try_acquire(lock)            bdk_rlock_try_lock(&lock)
#define __lock_try_acquire_recursive(lock)  bdk_rlock_try_lock(&lock)
#define __lock_release(lock)                bdk_rlock_unlock(&lock)
#define __lock_release_recursive(lock)      bdk_rlock_unlock(&lock)

#else
#error __OCTEON__ is not defined

/* dummy lock routines for single-threaded aps */

typedef int _LOCK_T;
typedef int _LOCK_RECURSIVE_T;

#define __LOCK_INIT(class,lock) static int lock = 0;
#define __LOCK_INIT_RECURSIVE(class,lock) static int lock = 0;
#define __lock_init(lock) (_CAST_VOID 0)
#define __lock_init_recursive(lock) (_CAST_VOID 0)
#define __lock_close(lock) (_CAST_VOID 0)
#define __lock_close_recursive(lock) (_CAST_VOID 0)
#define __lock_acquire(lock) (_CAST_VOID 0)
#define __lock_acquire_recursive(lock) (_CAST_VOID 0)
#define __lock_try_acquire(lock) (_CAST_VOID 0)
#define __lock_try_acquire_recursive(lock) (_CAST_VOID 0)
#define __lock_release(lock) (_CAST_VOID 0)
#define __lock_release_recursive(lock) (_CAST_VOID 0)

#endif /* __OCTEON__ */

#endif /* __SYS_LOCK_H__ */
