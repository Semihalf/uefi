#include <bdk.h>
// Module for interfacing with Octeon

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
    lua_pushnumber(L, OCTEON_CN61XX);
    lua_setfield(L, -2, "CN61XX");
    lua_pushnumber(L, OCTEON_CN61XX_PASS1_X);
    lua_setfield(L, -2, "CN61XXP1");
    lua_pushnumber(L, OCTEON_CN70XX);
    lua_setfield(L, -2, "CN70XX");
    lua_pushnumber(L, OCTEON_CN70XX_PASS1_X);
    lua_setfield(L, -2, "CN70XXP1");
    lua_pushnumber(L, OCTEON_CN78XX);
    lua_setfield(L, -2, "CN78XX");
    lua_pushnumber(L, OCTEON_CN78XX_PASS1_X);
    lua_setfield(L, -2, "CN78XXP1");
}

