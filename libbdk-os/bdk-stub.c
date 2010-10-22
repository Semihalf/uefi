#include <bdk.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <errno.h>

#undef errno
extern int errno;

int close(int file)
{
    return -1;
}

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

int fstat(int file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
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

int lseek(int file, int ptr, int dir)
{
    return 0;
}

int open(const char *name, int flags, int mode)
{
    return -1;
}

int read(int file, char *ptr, int len)
{
    return 0;
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

int stat(const char *file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

clock_t times(struct tms *buf)
{
    return -1;
}

int unlink(const char *name)
{
    errno = ENOENT;
    return -1;
}

int wait(int *status)
{
    errno = ECHILD;
    return -1;
}

int write(int file, const char *ptr, int len)
{
    uint64_t lsrval;
    int l = len;
    int id = 0;
    const char *p = ptr;

    while (l--)
    {
        if (*p =='\n')
        {
            /* Spin until there is room */
            do
            {
                lsrval = BDK_CSR_READ(BDK_MIO_UARTX_LSR(id));
            } while ((lsrval & (1<<5)) == 0);
            /* Write the byte */
            BDK_CSR_WRITE(BDK_MIO_UARTX_THR(id), '\r');
        }

        /* Spin until there is room */
        do
        {
            lsrval = BDK_CSR_READ(BDK_MIO_UARTX_LSR(id));
        } while ((lsrval & (1<<5)) == 0);
        /* Write the byte */
        BDK_CSR_WRITE(BDK_MIO_UARTX_THR(id), *p);
        p++;
    }
    return len;
}

