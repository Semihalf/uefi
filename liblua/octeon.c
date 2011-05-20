#ifndef BDK_BUILD_HOST
#include <bdk.h>
#include <unistd.h>
#else
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <libbdk-arch/bdk-model.h>
#include <libbdk-arch/bdk-csr.h>
#endif
// Module for interfacing with Octeon

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static uint64_t build_mask(int bits, int left_shift)
{
    uint64_t mask = ~((~0x0ull) << bits);
    if (bits == 64)
        mask = -1;
    return mask << left_shift;
}

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
 * Called when octeon.csr.NAME.read() is invoked
 *
 * @param L
 *
 * @return
 */
static int octeon_csr_read(lua_State* L)
{
    const char *name = lua_tostring(L, lua_upvalueindex(1));
    luaL_argcheck(L, lua_gettop(L) == 0, 1, "No arguments expected");
    lua_pushnumber(L, bdk_csr_read_by_name(name));
    return 1;
}

/**
 * Called when octeon.csr.NAME.write(value) is invoked
 *
 * @param L
 *
 * @return
 */
static int octeon_csr_write(lua_State* L)
{
    const char *name = lua_tostring(L, lua_upvalueindex(1));
    bdk_csr_write_by_name(name, luaL_checknumber(L, 1));
    return 0;
}

/**
 * Called when octeon.csr.NAME.decode(optional) is invoked
 *
 * @param L
 *
 * @return
 */
static int octeon_csr_decode(lua_State* L)
{
    const char *csr_name = lua_tostring(L, lua_upvalueindex(1));
    uint64_t value;
    if (lua_isnumber(L, 1))
        value = luaL_checknumber(L, 1);
    else
        value = bdk_csr_read_by_name(csr_name);

    const char *fieldn;
    int start_bit = 0;
    int field_width = bdk_csr_field(csr_name, start_bit, &fieldn);

    if (field_width < 0)
        return luaL_error(L, "%s: CSR not found", __FUNCTION__);

    lua_newtable(L);
    while (field_width > 0)
    {
        uint64_t v = value >> start_bit;
        v &= build_mask(field_width, 0);
        lua_pushnumber(L, v);
        lua_setfield(L, -2, fieldn);
        start_bit += field_width;
        field_width = bdk_csr_field(csr_name, start_bit, &fieldn);
    }
    return 1;
}

/**
 * Called when octeon.csr.NAME.encode(table) is invoked
 *
 * @param L
 *
 * @return
 */
static int octeon_csr_encode(lua_State* L)
{
    const char *csr_name = lua_tostring(L, lua_upvalueindex(1));
    luaL_checktype(L, 1, LUA_TTABLE);

    uint64_t value = 0;
    const char *fieldn;
    int start_bit = 0;
    int field_width = bdk_csr_field(csr_name, start_bit, &fieldn);

    if (field_width < 0)
        return luaL_error(L, "%s: CSR not found", __FUNCTION__);

    while (field_width > 0)
    {
        lua_getfield(L, 1, fieldn);
        if (!lua_isnil(L, -1))
        {
            uint64_t fieldv = luaL_checknumber(L, -1);
            value &= ~build_mask(field_width, start_bit);
            fieldv &= build_mask(field_width, 0);
            value |= fieldv << start_bit;
        }
        lua_pop(L, 1);
        start_bit += field_width;
        field_width = bdk_csr_field(csr_name, start_bit, &fieldn);
    }
    bdk_csr_write_by_name(csr_name, value);
    return 0;
}

/**
 * Called when a CSR field is read using octeon.csr.NAME.FIELD
 *
 * @param L
 *
 * @return
 */
static int octeon_csr_field_index(lua_State* L)
{
    const char *csr_name = lua_tostring(L, lua_upvalueindex(1));
    const char *field_name = luaL_checkstring(L, 2);

    const char *fieldn;
    int start_bit = 0;
    int field_width = bdk_csr_field(csr_name, start_bit, &fieldn);
    while (field_width > 0)
    {
        if (strcasecmp(field_name, fieldn) == 0)
        {
            uint64_t value = bdk_csr_read_by_name(csr_name);
            value >>= start_bit;
            value &= build_mask(field_width, 0);
            lua_pushnumber(L, value);
            return 1;
        }
        start_bit += field_width;
        field_width = bdk_csr_field(csr_name, start_bit, &fieldn);
    }
    return luaL_error(L, "%s: Field not found", __FUNCTION__);
}

/**
 * Called when a CSR field is set using octeon.csr.NAME.FIELD
 *
 * @param L
 *
 * @return
 */
static int octeon_csr_field_newindex(lua_State* L)
{
    const char *csr_name = lua_tostring(L, lua_upvalueindex(1));
    const char *field_name = luaL_checkstring(L, 2);
    uint64_t new_value = luaL_checknumber(L, 3);


    const char *fieldn;
    int start_bit = 0;
    int field_width = bdk_csr_field(csr_name, start_bit, &fieldn);
    while (field_width > 0)
    {
        if (strcasecmp(field_name, fieldn) == 0)
        {
            uint64_t value = bdk_csr_read_by_name(csr_name);
            value &= ~build_mask(field_width, start_bit);
            new_value &= build_mask(field_width, 0);
            value |= new_value << start_bit;
            bdk_csr_write_by_name(csr_name, value);
            return 0;
        }
        start_bit += field_width;
        field_width = bdk_csr_field(csr_name, start_bit, &fieldn);
    }
    return luaL_error(L, "%s: Field not found", __FUNCTION__);
}

/**
 * Returns a table representing a CSR. One argument is expected, the
 * CSR name to lookup. The name contains "()" for indexed CSRs
 *
 * @param L
 *
 * @return
 */
static int octeon_csr_lookup(lua_State* L)
{
    const char *name = luaL_checkstring(L, -1);

    if(bdk_csr_get_name(name, NULL))
        luaL_error(L, "Invalid CSR");

    lua_newtable(L);
    lua_pushstring(L, name);
    lua_pushcclosure(L, octeon_csr_read, 1);
    lua_setfield(L, -2, "read");
    lua_pushstring(L, name);
    lua_pushcclosure(L, octeon_csr_write, 1);
    lua_setfield(L, -2, "write");
    lua_pushstring(L, name);
    lua_pushcclosure(L, octeon_csr_decode, 1);
    lua_setfield(L, -2, "decode");
    lua_pushstring(L, name);
    lua_pushcclosure(L, octeon_csr_encode, 1);
    lua_setfield(L, -2, "encode");

    lua_newtable(L);
    lua_pushstring(L, name);
    lua_pushcclosure(L, octeon_csr_field_index, 1);
    lua_setfield(L, -2, "__index");
    lua_pushstring(L, name);
    lua_pushcclosure(L, octeon_csr_field_newindex, 1);
    lua_setfield(L, -2, "__newindex");
    lua_setmetatable(L, -2);
    return 1;
}

/**
 * This function is called for CSRs that need indexed arguments.
 * It is given to Lua as the response to octeon.csr.NAME, which Lua
 * calls as a function when the () is added.
 *
 * @param L
 *
 * @return
 */
static int octeon_csr_namecall(lua_State* L)
{
    char fullname[32];
    const char *basename = lua_tostring(L, lua_upvalueindex(1));
    int num_args = lua_gettop(L);

    if(num_args == 2)
    {
        int arg1 = luaL_checkinteger(L, 1);
        int arg2 = luaL_checkinteger(L, 2);
        snprintf(fullname, sizeof(fullname), "%s(%d,%d)", basename, arg1, arg2);
    }
    else if(num_args == 1)
    {
        int arg1 = luaL_checkinteger(L, 1);
        snprintf(fullname, sizeof(fullname), "%s(%d)", basename, arg1);
    }
    else
        luaL_error(L, "Invalid number of arguments to CSR");

    fullname[sizeof(fullname)-1] = 0;
    lua_pushstring(L, fullname);
    return octeon_csr_lookup(L);
}

/**
 * Called when octeon.csr.NAME needs to be resolved to a CSR table
 * or function.
 *
 * @param L
 *
 * @return
 */
static int octeon_csr_index(lua_State* L)
{
    const char *name = luaL_checkstring(L, 2);

    if(bdk_csr_get_name(name, NULL))
    {
        /* Can't find CSR, assume it is an indexed function */
        /* Use our argument as the upvalue for the function */
        lua_pushcclosure(L, octeon_csr_namecall, 1);
        return 1;
    }
    else
    {
        /* We found it, so do the function call directly */
        return octeon_csr_lookup(L);
    }
}

/**
 * Called when someone attempts to add something to the octeon.csr
 * table. This is not allowed.
 *
 * @param L
 *
 * @return
 */
static int octeon_csr_newindex(lua_State* L)
{
    luaL_error(L, "CSR table doesn't allow new indexes");
    return 0;
}

/**
 * Iterator function returned by octeon.csr(). It is used by
 * for loops to show all possible CSR strings.
 *
 * @param L
 *
 * @return
 */
static int octeon_csr_iter(lua_State* L)
{
    char buffer[64];
    const char *last = NULL;
    if (lua_gettop(L) >= 2)
    {
        if(!lua_isnil(L, 2))
            last = luaL_checkstring(L, 2);
    }
    int status = bdk_csr_get_name(last, buffer);
    if(status)
    {
        lua_pushnil(L);
        lua_pushnil(L);
    }
    else
    {
        lua_pushstring(L, buffer);
        lua_pushnil(L);
    }
    return 2;
}

/**
 * Called when octeon.csr() is invoked. It returns an interator
 * used in for loops.
 *
 * @param L
 *
 * @return
 */
static int octeon_csr_call(lua_State* L)
{
    lua_pushcfunction(L, octeon_csr_iter);
    lua_pushnil(L);
    return 2;
}

#ifndef BDK_BUILD_HOST
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


static void control_c_check(lua_State *L, lua_Debug *ar)
{
    if (__bdk_fs_check_break())
    {
        luaL_traceback(L,  L, "Interrupted!", 1);
        lua_error(L);
    }
    lua_gc(L, LUA_GCCOLLECT, 0);
}

static int get_sbrk(lua_State* L)
{
    lua_pushnumber(L, bdk_ptr_to_phys(sbrk(0)));
    return 1;
}
#endif

/**
 * Called to register the octeon module
 *
 * @param L
 *
 * @return
 */
LUALIB_API int luaopen_octeon(lua_State* L)
{
#ifndef BDK_BUILD_HOST
    /* Create a new table for the module */
    lua_newtable(L);
#else
    LUALIB_API int luaopen_oremote(lua_State* L);
    if (luaopen_oremote(L) != 1)
        return 0;
    lua_getglobal(L, "oremote");
#endif

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

    /* Add octeon.csr, magic table access to Octeon CSRs */
    lua_newtable(L); /* csr table */
    lua_newtable(L); /* csr metatable */
    lua_pushcfunction(L, octeon_csr_index);
    lua_setfield(L, -2, "__index");
    lua_pushcfunction(L, octeon_csr_newindex);
    lua_setfield(L, -2, "__newindex");
    lua_pushcfunction(L, octeon_csr_call);
    lua_setfield(L, -2, "__call");
    lua_setmetatable(L, -2);
    lua_setfield(L, -2, "csr");

#ifndef BDK_BUILD_HOST
    /* Create a new table of all C functions that can be called */
    lua_newtable(L);
    int i = 0;
    while(bdk_functions[i].name)
    {
        lua_pushlightuserdata(L, bdk_functions[i].func);
        lua_pushcclosure(L, octeon_c_call, 1);
        lua_setfield(L, -2, bdk_functions[i].name);
        i++;
    }
    lua_setfield(L, -2, "c");

    /* Add constants for bdk_config */
    for (bdk_config_t c=0; c<__BDK_CONFIG_END; c++)
    {
        lua_pushnumber(L, c);
        lua_setfield(L, -2, bdk_config_get_name(c));
    }

    /* Add function for seeing the size of the heap */
    lua_pushcfunction(L, get_sbrk);
    lua_setfield(L, -2, "get_sbrk");

    lua_setglobal(L, "octeon");

    extern int luaopen_bdk_board_table_entry(lua_State *L);
    luaopen_bdk_board_table_entry(L);

    extern int luaopen_readline(lua_State *L);
    luaopen_readline(L);

    extern int luaopen_trafficgen(lua_State *L);
    luaopen_trafficgen(L);

    extern int luaopen_octeon_perf(lua_State *L);
    luaopen_octeon_perf(L);

    /* Enable Interrupt on uart break signal */
    lua_sethook(L, control_c_check, LUA_MASKCOUNT, 10000);
#else
    extern int luaopen_socket_core(lua_State *L);
    luaL_findtable(L, LUA_REGISTRYINDEX, "_PRELOAD");
    lua_pushcfunction(L, luaopen_socket_core);
    lua_setfield(L, -2, "socket");
    lua_pop(L, 1);  /* remove _PRELOAD table */
#endif
    return 1;
}

#ifdef BDK_BUILD_HOST
int main(int argc, const char **argv)
{
    extern int bdk_lua_main(int argc, const char **argv);
    return bdk_lua_main(argc, argv);
}
#endif


