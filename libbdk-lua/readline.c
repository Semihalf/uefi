#include <bdk.h>
// Module for interfacing with readline

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static int readline(lua_State* L)
{
    const char *prompt = luaL_checkstring(L, 1);
    luaL_checkany(L, 2);
    uint32_t timeout_us = luaL_checkinteger(L, 3);

    const char *result = bdk_readline(prompt, NULL, timeout_us);

    lua_pushstring(L, result);
    return 1;
}


int luaopen_readline(lua_State *L)
{
    lua_getglobal(L, "octeon");
    lua_pushcfunction(L, readline);
    lua_setfield(L, -2, "readline");
    return 1;
}

