#ifndef BDK_BUILD_HOST
#include <bdk.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>
#include <memory.h>
#endif

// Module for interfacing with readline

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

/**
 * getkey()
 * Return a pending input byte if available
 *
 * @param L
 *
 * @return
 */
static int lgetkey(lua_State* L)
{
    extern int bdk_readline_getkey(int timeout_us);
    int key = bdk_readline_getkey(1000);
    if (key != -1)
    {
        char c = key;
        lua_pushlstring(L, &c, 1);
    }
    else
        lua_pushnil(L);
    return 1;
}

static int lreadline(lua_State* L)
{
    const char *prompt = luaL_checkstring(L, 1);
    luaL_checkany(L, 2);
    uint32_t timeout_us = luaL_checkinteger(L, 3);

    const char *result = bdk_readline(prompt, NULL, timeout_us);
    if (result && (result[0] == 3))
        return luaL_error(L, "Control-C Break");
    lua_pushstring(L, result);
    return 1;
}

static lua_State *globalL;
void __bdk_rpc_serve(void)
{
    lua_State *L = globalL;
    lua_getglobal(L, "require");
    lua_pushstring(L, "rpc");
    lua_call(L, 1, 1);
    lua_getfield(L, -1, "serve");
    lua_pushstring(L, "/dev/console");
    lua_pushstring(L, "/dev/console");
    lua_pushboolean(L, 1);
#ifndef BDK_BUILD_HOST
    __bdk_fs_readline_enable(0);
#endif
    lua_call(L, 3, 0);
#ifndef BDK_BUILD_HOST
    __bdk_fs_readline_enable(1);
#endif
    lua_pop(L, 1);
}

LUALIB_API int luaopen_readline(lua_State *L)
{
    globalL = L;
    lua_newtable(L);
    lua_pushcfunction(L, lgetkey);
    lua_setfield(L, -2, "getkey");
    lua_pushcfunction(L, lreadline);
    lua_setfield(L, -2, "readline");
    return 1;
}

