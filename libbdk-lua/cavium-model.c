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
 * Lua wrapper for cavium_is_altpkg
 *
 * @param L
 *
 * @return
 */
static int is_altpkg(lua_State* L)
{
    uint32_t m = luaL_checkinteger(L, 1);
    lua_pushboolean(L, cavium_is_altpkg(m));
    return 1;
}

/**
 * Called to register the chip model module
 *
 * @param L
 *
 * @return
 */
void register_cavium_model(lua_State* L)
{
    lua_pushcfunction(L, is_model);
    lua_setfield(L, -2, "is_model");
    lua_pushcfunction(L, is_altpkg);
    lua_setfield(L, -2, "is_altpkg");

    /* Add constants for the different models that can be used with
        cavium.is_model() */
    lua_pushnumber(L, CAVIUM_CN88XX);
    lua_setfield(L, -2, "CN88XX");
    lua_pushnumber(L, CAVIUM_CN88XX_PASS1_X);
    lua_setfield(L, -2, "CN88XXP1");
    lua_pushnumber(L, CAVIUM_CN88XX_PASS2_X);
    lua_setfield(L, -2, "CN88XXP2");
    lua_pushnumber(L, CAVIUM_CN83XX);
    lua_setfield(L, -2, "CN83XX");
    lua_pushnumber(L, CAVIUM_CN83XX_PASS1_X);
    lua_setfield(L, -2, "CN83XXP1");
    lua_pushnumber(L, CAVIUM_CN81XX);
    lua_setfield(L, -2, "CN81XX");
    lua_pushnumber(L, CAVIUM_CN81XX_PASS1_X);
    lua_setfield(L, -2, "CN81XXP1");
}

