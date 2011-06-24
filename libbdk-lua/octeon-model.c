#ifndef BDK_BUILD_HOST
#include <bdk.h>
#include <unistd.h>
#else
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <libbdk-arch/bdk-model.h>
#endif
// Module for interfacing with Octeon

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

/**
 * Lua wrapper for OCTEON_IS_MODEL
 *
 * @param L
 *
 * @return
 */
static int octeon_is_model(lua_State* L)
{
    uint32_t m = luaL_checkinteger(L, 1);
    lua_pushboolean(L, OCTEON_IS_MODEL(m));
    return 1;
}

/**
 * Called to register the octeon module
 *
 * @param L
 *
 * @return
 */
void register_octeon_model(lua_State* L)
{
    lua_pushcfunction(L, octeon_is_model);
    lua_setfield(L, -2, "is_model");

    /* Add constants for the different models that can be used with
        octeon.is_model() */
    lua_pushnumber(L, OCTEON_CN63XX);
    lua_setfield(L, -2, "CN63XX");
    lua_pushnumber(L, OCTEON_CN63XX_PASS1_X);
    lua_setfield(L, -2, "CN63XXP1");
    lua_pushnumber(L, OCTEON_CN63XX_PASS2_X);
    lua_setfield(L, -2, "CN63XXP2");
    lua_pushnumber(L, OCTEON_CN68XX);
    lua_setfield(L, -2, "CN68XX");
    lua_pushnumber(L, OCTEON_CN68XX_PASS1_X);
    lua_setfield(L, -2, "CN68XXP1");
    lua_pushnumber(L, OCTEON_CN68XX_PASS2_X);
    lua_setfield(L, -2, "CN68XXP2");
    lua_pushnumber(L, OCTEON_CN66XX);
    lua_setfield(L, -2, "CN66XX");
    lua_pushnumber(L, OCTEON_CN66XX_PASS1_X);
    lua_setfield(L, -2, "CN66XXP1");
    lua_pushnumber(L, OCTEON_CN61XX);
    lua_setfield(L, -2, "CN61XX");
    lua_pushnumber(L, OCTEON_CN61XX_PASS1_X);
    lua_setfield(L, -2, "CN61XXP1");
}

