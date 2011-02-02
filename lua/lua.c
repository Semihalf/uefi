#include <bdk.h>

static const char *argv[] = {
    "lua",
    "-i",
    "/rom/init.lua",
    NULL,
};

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    extern int bdk_lua_main(int argc, const char **argv);
    if (bdk_thread_create(0, (bdk_thread_func_t)bdk_lua_main, 3, argv, 16384))
        bdk_fatal("Create of Lua thread failed\n");
    return 0;
}
