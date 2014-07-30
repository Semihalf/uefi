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
#if 0
void bdk_write_env(void)
{
    if (!*environ)
        return;

    /* Write the environment in Uboot's goofy format */
    uint32_t* base_ptr = bdk_phys_to_ptr(0x1000);
    memset(base_ptr, 0, 0x1000);
    char **e = environ;
    char *p = (char*)(base_ptr + 1);
    while (*e)
    {
        strcpy(p, *e);
        p += strlen(*e) + 1;
        e++;
    }
    *base_ptr = bdk_crc32(base_ptr+1, 0x1000 - 4, 0);
}
#endif
