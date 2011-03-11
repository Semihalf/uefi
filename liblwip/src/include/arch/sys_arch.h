#ifndef __ARCH_SYS_ARCH_H__
#define __ARCH_SYS_ARCH_H__

/* BDK description of the system environment for lwip */

typedef struct
{
    int32_t count;
} sys_sem_t;

#define SYS_MBOX_MAX 16
typedef struct
{
    bdk_rlock_t lock;
    int count;
    int head;
    void *message[SYS_MBOX_MAX];
} sys_mbox_t;

typedef void *sys_thread_t;
typedef int sys_prot_t;

#define SYS_MBOX_NULL NULL
#define SYS_SEM_NULL NULL

#endif
