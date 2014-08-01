#include <bdk.h>
// Module for determining chips models

/**
 * Lua wrapper for CAVIUM_IS_MODEL
 *
 * @param L
 *
 * @return
 */
static int is_model(lua_State* L)
{
    uint32_t m = luaL_checkinteger(L, 1);
    lua_pushboolean(L, CAVIUM_IS_MODEL(m));
    return 1;
}

/**
 * Called to register the chip model module
 *
 * @param L
 *
 * @return
 */
void register_octeon_model(lua_State* L)
{
    lua_pushcfunction(L, is_model);
    lua_setfield(L, -2, "is_model");

    /* Add constants for the different models that can be used with
        octeon.is_model() */
    lua_pushnumber(L, CAVIUM_CN88XX);
    lua_setfield(L, -2, "CN88XX");
    lua_pushnumber(L, CAVIUM_CN88XX_PASS1_X);
    lua_setfield(L, -2, "CN88XXP1");
    lua_pushnumber(L, CAVIUM_CN85XX);
    lua_setfield(L, -2, "CN85XX");
    lua_pushnumber(L, CAVIUM_CN85XX_PASS1_X);
    lua_setfield(L, -2, "CN85XXP1");
}

