#include <bdk.h>
#include <unistd.h>
// Module for interfacing with Octeon

/**
 * Wrapper to call a generic C function from Lua. A maximum
 * of 8 arguments are supported. Each argument can either be a
 * number or string. Function can only return numbers.
 *
 * @param L
 *
 * @return
 */
static int octeon_c_call(lua_State* L)
{
    long (*func)(long arg1, long arg2, long arg3, long arg4, long arg5, long arg6, long arg7, long arg8);
    long args[8];
    int num_args = lua_gettop(L);
    func = lua_topointer(L, lua_upvalueindex(1));

    int i;
    for(i=0; i<num_args; i++)
    {
        if(lua_isnumber(L, i+1))
        {
            args[i] = lua_tonumber(L, i+1);
        }
        else if(lua_isstring(L, i+1))
        {
            const char *str = lua_tostring(L, i+1);
            args[i] = (long)str;
        }
        else if(lua_isnil(L, i+1))
        {
            args[i] = 0;
        }
        else if(lua_isboolean(L, i+1))
        {
            args[i] = lua_toboolean(L, i+1);
        }
        else
        {
            luaL_error(L, "Invalid argument type");
            return 0;
        }
    }

    long result = func(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7]);
    if (func == (void*)bdk_qlm_get_mode)
        lua_pushstring(L, (const char*)result);
    else
        lua_pushnumber(L, result);

    return 1;
}

static int get_sbrk(lua_State* L)
{
    lua_pushnumber(L, bdk_ptr_to_phys(sbrk(0)));
    return 1;
}

/**
 * Called to register the octeon module
 *
 * @param L
 *
 * @return
 */
void register_octeon_c(lua_State* L)
{
    /* Create a new table of all C functions that can be called */
    lua_newtable(L);
    int i = 0;
    while(bdk_functions[i].name)
    {
        if (bdk_functions[i].func)
        {
            lua_pushlightuserdata(L, bdk_functions[i].func);
            lua_pushcclosure(L, octeon_c_call, 1);
            lua_setfield(L, -2, bdk_functions[i].name);
        }
        else
        {
            //bdk_warn("Symbol %s is not defined\n", bdk_functions[i].name);
        }
        i++;
    }

    /* Manually add CSR read and write as these are inline functions
        that are missed by bdk_functions */
    lua_pushlightuserdata(L, bdk_csr_read);
    lua_pushcclosure(L, octeon_c_call, 1);
    lua_setfield(L, -2, "bdk_csr_read");
    lua_pushlightuserdata(L, bdk_csr_write);
    lua_pushcclosure(L, octeon_c_call, 1);
    lua_setfield(L, -2, "bdk_csr_write");

    /* Add function for seeing the size of the heap */
    lua_pushcfunction(L, get_sbrk);
    lua_setfield(L, -2, "get_sbrk");

    lua_setfield(L, -2, "c");
}

/**
 * This function should be called inside bdk_lua_callback() to add
 * custom functions to the octeon.c table. This allows applications
 * to add functions without modifying bdk-function.
 *
 * @param L      Lua state
 * @param name   Name of the function to use in octeon.c.NAME
 * @param func   Function to register. The function can take a maximum of eight
 *               arguments where each argument must be a type compatable with a
 *               int64_t or a constant string pointer. The return value of the
 *               function can be void or a type compatable with a int64_t.
 */
void bdk_lua_register_cfunc(lua_State* L, const char *name, void *func)
{
    lua_getglobal(L, "require");
    lua_pushstring(L, "octeon-internal");
    lua_call(L, 1, 1);
    /* Only "octeon-internal" on stack */
    lua_getfield(L, -1, "c");
    lua_pushlightuserdata(L, func);
    lua_pushcclosure(L, octeon_c_call, 1);
    lua_setfield(L, -2, name);
    lua_pop(L, 1); /* Pop the "c" table */
    lua_pop(L, 1); /* Pop the "octeon-internal" table */
}

