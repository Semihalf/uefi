#include <bdk.h>
#include <stdio.h>

static void __bdk_output(const char *prefix, const char *format, va_list args)
{
    if (prefix)
        fputs(prefix, stderr);
    vfprintf(stderr, format, args);
    fflush(NULL);
}

void bdk_fatal(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    __bdk_output("FATAL: ", format, args);
    va_end(args);
    BDK_SYNC;
    while (1)
        asm volatile ("break" ::: "memory");
}

void bdk_error(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    __bdk_output("ERROR: ", format, args);
    va_end(args);
}

void bdk_warn(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    __bdk_output("WARNING: ", format, args);
    va_end(args);
}

void bdk_dprintf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    __bdk_output(NULL, format, args);
    va_end(args);
}

