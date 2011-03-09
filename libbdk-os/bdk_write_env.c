#include <bdk.h>

extern char **environ;

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

