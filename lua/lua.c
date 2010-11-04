#include <bdk.h>

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    extern int bdk_lua_main(int argc, const char **argv);
    const char *argv[] = {
        "lua",
        "-i",
        "/rom/init.lua",
        NULL,
    };
    return bdk_lua_main(3, argv);
}
