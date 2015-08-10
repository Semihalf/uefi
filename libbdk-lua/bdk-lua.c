#ifndef BDK_BUILD_HOST
#include <bdk.h>
#include <unistd.h>
#include <fcntl.h>
#else
#include <libbdk-lua/bdk-lua.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#endif

/**
 * This is the main enotry point for Lua, defined in liblua. It
 * should not be used directly.
 *
 * @param argc
 * @param argv
 *
 * @return
 */
extern int __bdk_lua_main(int argc, const char **argv);


/**
 * This function is needed to support luasocket
 *
 * @param L
 * @param narg
 * @param tname
 *
 * @return
 */
int luaL_typerror(void *L, int narg, const char *tname)
{
    const char *msg = lua_pushfstring(L, "%s expected, got %s", tname, luaL_typename(L, narg));
    return luaL_argerror(L, narg, msg);
}

#ifndef BDK_BUILD_HOST
static void control_c_check(lua_State *L, lua_Debug *ar)
{
    if (__bdk_fs_check_break())
    {
        luaL_traceback(L,  L, "Interrupted!", 1);
        lua_error(L);
    }
}
#endif

void bdk_lua_init(void *lua_state)
{
    lua_State *L = lua_state;

    luaL_getsubtable(L, LUA_REGISTRYINDEX, "_PRELOAD");

    #define PRELOAD(name, func)         \
        extern int func(lua_State *L);  \
        lua_pushcfunction(L, func);     \
        lua_setfield(L, -2, name)

    PRELOAD("bit64", luaopen_bit64);
    PRELOAD("readline", luaopen_readline);
    PRELOAD("rpc-support", luaopen_rpc_support);

#ifdef BDK_BUILD_HOST

    PRELOAD("socket", luaopen_socket_core);

#else

    PRELOAD("cavium-internal", luaopen_cavium);

    /* Enable Interrupt on uart break signal */
    lua_sethook(L, control_c_check, LUA_MASKCOUNT, 10000);

#endif

    lua_pop(L, 1);  /* remove _PRELOAD table */
}

#ifdef BDK_BUILD_HOST
int main(int argc, const char **argv)
{
    return __bdk_lua_main(argc, argv);
}

#else

/**
 * Create a new Lua interpreter and execute it in another thread.
 * The Lua instance starts in a new thread so the stack size can
 * be adjusted. Lua requires more stacj space than most BDK
 * threads. This means this routine returns immediately and the
 * Lua instance continues. It is expected that this function
 * will be called as the last line of main().
 *
 *     int main(void)
 *     {
 *         return bdk_lua_start();
 *     }
 *
 * @return Zero for use as return value for main()
 */
int bdk_lua_start(void)
{
    static const char *init_paths[] = {
        "/ram/init.lua",
        "/fatfs/lua/init.lua",
        "/rom/init.lua",
        NULL
    };
    static const char *argv[] = {
        "lua",
        "-i",
        NULL,
        NULL,
    };

    /* Read saved environment variables form config file. */
    if (bdk_loadenv(NULL)) /* NULL == default filename */
        bdk_warn("Could not read environment variables from config file. "
                 "Will continue with defaults...\n");

    int init_file = 0;
    while (init_paths[init_file])
    {
        int handle = open(init_paths[init_file], O_RDONLY);
        if (handle >= 0)
        {
            close(handle);
            argv[2] = init_paths[init_file];
            return __bdk_lua_main(3, argv);
        }
        init_file++;
    }
    bdk_error("Unable to find init.lua\n");
    return -1;
}

#endif


