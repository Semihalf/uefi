#include <bdk.h>
// Module for interfacing with Octeon

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "platform.h"
#include "lrotable.h"

static int octeon_is_model( lua_State* L )
{
    uint32_t m = luaL_checkinteger( L, 1 );
  lua_pushinteger( L, OCTEON_IS_MODEL(m) );
  return 1;
}

static int octeon_c_call( lua_State* L )
{
    long (*func)(long arg1, long arg2, long arg3, long arg4, long arg5, long arg6, long arg7, long arg8);
    long args[8];
    int num_args = lua_gettop(L);
    func = lua_topointer(L, lua_upvalueindex(1));

    printf("c call %p(", func);

    int i;
    for (i=0; i<num_args; i++)
    {
        if (lua_isnumber(L, i+1))
        {
            args[i] = lua_tonumber(L, i+1);
            printf(" %lu", args[i]);
        }
        else if (lua_isstring(L, i+1))
        {
            const char *str = lua_tostring(L, i+1);
            args[i] = (long)str;
            printf(" \"%s\"", str);
        }
        else
        {
            printf(") ERROR: Invalid argument type\n");
            lua_pop(L, num_args);
            return 1;
        }
    }
    printf(")\n");

    long result = func(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7]);
    lua_pop(L, num_args);
    lua_pushnumber(L, result);

    return 1;
}


// Module function map
#define MIN_OPT_LEVEL 2
#include "lrodefs.h"
const LUA_REG_TYPE octeon_map[] =
{
  { LSTRKEY( "is_model" ), LFUNCVAL( octeon_is_model ) },
  { LNILKEY, LNILVAL }
};

LUALIB_API int luaopen_octeon( lua_State* L )
{
    luaL_register(L, "octeon", octeon_map );

    /* Create a new table of all C functions that can be called */
    lua_newtable(L);
    int i = 0;
    while (bdk_functions[i].name)
    {
        lua_pushlightuserdata(L, bdk_functions[i].func);
        lua_pushcclosure(L, octeon_c_call, 1);
        lua_setfield(L, -2, bdk_functions[i].name);
        i++;
    }
    lua_setfield(L, -2, "c");

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

#if 0
    lua_newtable(L);
    char buffer[32];
    buffer[0] = 0;
    while (bdk_csr_get_name(buffer[0] ? buffer : NULL, buffer) == 0)
    {
        lua_pushstring(L, buffer);
        lua_setfield(L, -2, buffer);
    }
    lua_setfield(L, -2, "csr");
#endif

    return 1;
}
