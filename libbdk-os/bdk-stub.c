#include <bdk.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <sys/time.h>
#include <errno.h>
#include <stdio.h>

#undef errno
extern int errno;

int _execve(const char *name, const char **argv, const char **env)
{
    errno = ENOMEM;
    return -1;
}

int _fork(void)
{
    errno = EAGAIN;
    return -1;
}

int _getpid(void)
{
    return 1;
}

int _isatty(int file)
{
    return 1;
}

int _kill(int pid, int sig)
{
    errno = EINVAL;
    return -1;
}

int _link(const char *old, const char *new)
{
    errno = EMLINK;
    return -1;
}

caddr_t _sbrk(int incr)
{
    static caddr_t next = NULL;
    static caddr_t end;

    if (next == NULL)
    {
        extern uint64_t bdk_fs_romfs_get_end(void);
        unsigned int l2_size = bdk_l2c_get_cache_size_bytes(bdk_numa_master());
        /* Heap starts after the _end symbol and goes until the end of
            the L2 cache */
        uint64_t start_paddr = bdk_fs_romfs_get_end();
        /* Align beginning of heap on 64KB boundary */
        start_paddr = (start_paddr + 65535) & -65536;
        next = bdk_phys_to_ptr(start_paddr);
        end = bdk_phys_to_ptr(bdk_numa_get_address(bdk_numa_master(), l2_size));
    }

    /* See of DRAM was setup and we can use more memory */
    uint64_t dram_mbytes = bdk_dram_get_size_mbytes(bdk_numa_master());
    if (dram_mbytes)
    {
        uint64_t dram_top = dram_mbytes << 20;
        end = bdk_phys_to_ptr(bdk_numa_get_address(bdk_numa_master(), dram_top));
    }

    caddr_t result = next;

    if ((incr < 0) || (next + incr > end))
        result = (void*)-1;
    else
        next += incr;
    return result;
}

clock_t _times(struct tms *buf)
{
    return -1;
}

int _wait(int *status)
{
    errno = ECHILD;
    return -1;
}

int _gettimeofday(struct timeval *tv, void *tz)
{
    uint64_t rate = bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE);
    uint64_t count = bdk_clock_get_count(BDK_CLOCK_CORE);
    tv->tv_sec = count / rate;
    tv->tv_usec = (count / (rate / 1000000)) % 1000000;
    return 0;
}

void _exit(int status)
{
    printf("_exit() was called\n");
    bdk_thread_destroy();
}

