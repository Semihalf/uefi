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
        extern void _end;
        unsigned int l2_size = bdk_l2c_get_cache_size_bytes();
        /* Convert the _end symbol from the text to the data virtual
            address space */
        void *ptr = &_end - 0x20000000;
        /* Heap starts after the _end symbol and goes until the end of
            the L2 cache */
        uint64_t start_paddr = bdk_ptr_to_phys(ptr);
        next = bdk_phys_to_ptr(start_paddr);
        end = next + l2_size - ((long)&end & 0x0fffffff);
        if (start_paddr > l2_size)
        {
            /* We must have been loaded by uboot into memory. Make the heap
                bigger as memory is already setup */
            end += 16<<20; // FIXME: Need to handle real memory size
        }
    }

    /* Skip 256MB-512MB which is the bootbus. Note that this doesn't affect
        end, so it needs to be set correctly. If end is less that 256MB, this
        code will increment past it and fail all allocations */
    uint64_t paddr = bdk_ptr_to_phys(next);
    if ((paddr < 0x20000000) && ((paddr + incr) > 0x10000000))
        next = bdk_phys_to_ptr(0x20000000);

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

