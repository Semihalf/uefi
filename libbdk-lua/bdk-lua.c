#ifndef BDK_BUILD_HOST
#include <bdk.h>
#include <unistd.h>
#else
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#endif

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#ifndef BDK_BUILD_HOST
static void control_c_check(lua_State *L, lua_Debug *ar)
{
    if (__bdk_fs_check_break())
    {
        luaL_traceback(L,  L, "Interrupted!", 1);
        lua_error(L);
    }
    lua_gc(L, LUA_GCCOLLECT, 0);
}
#endif

void bdk_lua_init(void *lua_state)
{
    lua_State *L = lua_state;

    luaL_findtable(L, LUA_REGISTRYINDEX, "_PRELOAD");

    #define PRELOAD(name, func)         \
        extern int func(lua_State *L);  \
        lua_pushcfunction(L, func);     \
        lua_setfield(L, -2, name)

    PRELOAD("bit64", luaopen_bit64);

#ifdef BDK_BUILD_HOST

    PRELOAD("socket", luaopen_socket_core);
    PRELOAD("oremote", luaopen_oremote);

#else

    PRELOAD("octeon", luaopen_octeon);

    /* Enable Interrupt on uart break signal */
    lua_sethook(L, control_c_check, LUA_MASKCOUNT, 10000);

#endif

    lua_pop(L, 1);  /* remove _PRELOAD table */
}

#ifdef BDK_BUILD_HOST
int main(int argc, const char **argv)
{
    extern int bdk_lua_main(int argc, const char **argv);
    return bdk_lua_main(argc, argv);
}
#endif


