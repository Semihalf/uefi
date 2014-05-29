#include <bdk.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <sys/time.h>
#include <errno.h>
#include <stdio.h>

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
    static caddr_t next = NULL;
    static caddr_t end;

    if (next == NULL)
    {
        extern uint64_t bdk_fs_romfs_get_end(void);
        unsigned int l2_size = bdk_l2c_get_cache_size_bytes(bdk_numa_master());
        /* Heap starts after the _end symbol and goes until the end of
            the L2 cache */
        uint64_t start_paddr = bdk_fs_romfs_get_end();
        next = bdk_phys_to_ptr(start_paddr);
        end = bdk_phys_to_ptr(bdk_numa_get_address(bdk_numa_master(), l2_size));
    }

    /* See of DRAM was setup and we can use more memory */
    uint64_t dram_mbytes = bdk_dram_get_size_mbytes(bdk_numa_master());
    if (dram_mbytes)
    {
        uint64_t dram_top = dram_mbytes << 20;
        /* More than 256MB gets offset by 256MB due to the bootbus hole */
        if (dram_top > 0x10000000)
            dram_top += 0x10000000;
        end = bdk_phys_to_ptr(bdk_numa_get_address(bdk_numa_master(), dram_top));
    }

    /* Skip 256MB-512MB which is the bootbus. Note that this doesn't affect
        end, so it needs to be set correctly. If end is less that 256MB, this
        code will increment past it and fail all allocations */
    uint64_t paddr = bdk_ptr_to_phys(next) & bdk_build_mask(40);
    if ((paddr < 0x20000000) && ((paddr + incr) > 0x10000000))
        next = bdk_phys_to_ptr(bdk_numa_get_address(bdk_numa_master(), 0x20000000));

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
    uint64_t rate = bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE);
    uint64_t count = bdk_clock_get_count(BDK_CLOCK_CORE);
    /* Run the simlator clock much faster */
    if (bdk_is_simulation())
        rate >>= 7;
    tv->tv_sec = count / rate;
    tv->tv_usec = (count / (rate / 1000000)) % 1000000;
    return 0;
}

void _exit(int status)
{
    printf("_exit() was called\n");
    bdk_thread_destroy();
}

