#include <bdk.h>
#include <stdio.h>

static void __bdk_output(const char *prefix, const char *format, va_list args)
{
#ifndef BDK_BUILD_HOST
static bdk_spinlock_t lock;
    bdk_spinlock_lock(&lock);
#endif
    if (prefix)
    {
        fputs(prefix, stderr);
        vfprintf(stderr, format, args);
    }
    else
        vfprintf(stdout, format, args); /* printf goes to stdout */
    fflush(NULL);
#ifndef BDK_BUILD_HOST
    bdk_spinlock_unlock(&lock);
#endif
}

void bdk_fatal(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    __bdk_output("FATAL: ", format, args);
    va_end(args);
    __bdk_die();
}

void bdk_error(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    __bdk_output("\nERROR: ", format, args);
    va_end(args);
}

void bdk_warn(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    __bdk_output("WARNING: ", format, args);
    va_end(args);
}

int printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    __bdk_output(NULL, format, args);
    va_end(args);
    return 0;
}

void __bdk_die(void)
{
#ifndef BDK_BUILD_HOST
    BDK_MB;
    while (1)
        asm volatile ("wfi" ::: "memory");
#else
    abort();
#endif
}
