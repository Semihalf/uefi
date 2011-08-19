#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(ENVIRONMENT);

extern char **environ;

void bdk_setenv(const char *name, const char *value)
{
    if (value)
       setenv(name, value, 1);
    else
       unsetenv(name);
}

void bdk_write_env(void)
{
    if (!*environ)
        return;

    /* Write the environment in Uboot's goofy format */
    uint32_t* ptr = bdk_phys_to_ptr(0x1000);
    int max_len = 0x1000 - 4;
    memcpy(ptr+1, *environ, max_len);
    *ptr = bdk_crc32(*environ, max_len, 0);
}

