#include <bdk.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <sys/time.h>
#include <errno.h>

#undef errno
extern int errno;

int execve(const char *name, const char **argv, const char **env)
{
    errno = ENOMEM;
    return -1;
}

int fork(void)
{
    errno = EAGAIN;
    return -1;
}

int getpid(void)
{
    return 1;
}

int isatty(int file)
{
    return 1;
}

int kill(int pid, int sig)
{
    errno = EINVAL;
    return -1;
}

int link(const char *old, const char *new)
{
    errno = EMLINK;
    return -1;
}

caddr_t sbrk(int incr)
{
    static caddr_t next;
    static caddr_t end;

    if (next == NULL)
    {
        next = bdk_phys_to_ptr(0x30000000);
        end = next + (10<<20);
    }

    caddr_t result = next;

    if ((incr < 0) || (next + incr > end))
        result = (void*)-1;
    else
        next += incr;
    return result;
}

clock_t times(struct tms *buf)
{
    return -1;
}

int wait(int *status)
{
    errno = ECHILD;
    return -1;
}

int gettimeofday(struct timeval *tv, void *tz)
{
    return -1;
}

void _exit(int status)
{
    while(1) {}
}

