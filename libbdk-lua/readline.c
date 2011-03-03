#include <bdk.h>
// Module for interfacing with readline

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static lua_State *globalL;

static int readline(lua_State* L)
{
    const char *prompt = luaL_checkstring(L, 1);
    luaL_checkany(L, 2);
    uint32_t timeout_us = luaL_checkinteger(L, 3);

    const char *result = bdk_readline(prompt, NULL, timeout_us);

    lua_pushstring(L, result);
    return 1;
}

void __bdk_rpc_serve(void)
{
    lua_State *L = globalL;
    lua_getglobal(L, "require");
    lua_pushstring(L, "rpc");
    lua_call(L, 1, 1);
    lua_getfield(L, -1, "serve");
    lua_pushstring(L, "/dev/uart/0");
    lua_pushstring(L, "/dev/uart/0");
    lua_pushboolean(L, 1);
    lua_call(L, 3, 0);
    lua_pop(L, 1);
}

int luaopen_readline(lua_State *L)
{
    globalL = L;
    lua_getglobal(L, "octeon");
    lua_pushcfunction(L, readline);
    lua_setfield(L, -2, "readline");
    return 1;
}

