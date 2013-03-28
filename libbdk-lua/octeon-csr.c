#include <bdk.h>
#include <unistd.h>
// Module for interfacing with Octeon

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(CSR_DB);

static uint64_t build_mask(int bits, int left_shift)
{
    uint64_t mask = ~((~0x0ull) << bits);
    if (bits == 64)
        mask = -1;
    return mask << left_shift;
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
    bdk_node_t node = lua_tointeger(L, lua_upvalueindex(2));
    luaL_argcheck(L, lua_gettop(L) == 0, 1, "No arguments expected");
    lua_pushnumber(L, bdk_csr_read_by_name(node, name));
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
    bdk_node_t node = lua_tointeger(L, lua_upvalueindex(2));
    bdk_csr_write_by_name(node, name, luaL_checknumber(L, 1));
    return 0;
}

/**
 * Called when octeon.csr.NAME.display(optional) is invoked
 *
 * @param L
 *
 * @return
 */
static int octeon_csr_display(lua_State* L)
{
    const char *csr_name = lua_tostring(L, lua_upvalueindex(1));
    bdk_node_t node = lua_tointeger(L, lua_upvalueindex(2));
    uint64_t value;
    if (lua_isnumber(L, 1))
        value = luaL_checknumber(L, 1);
    else
        value = bdk_csr_read_by_name(node, csr_name);
    if (bdk_csr_decode(csr_name, value))
        return luaL_error(L, "%s: CSR not found", __FUNCTION__);
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
    bdk_node_t node = lua_tointeger(L, lua_upvalueindex(2));
    uint64_t value;
    if (lua_isnumber(L, 1))
        value = luaL_checknumber(L, 1);
    else
        value = bdk_csr_read_by_name(node, csr_name);

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
    bdk_node_t node = lua_tointeger(L, lua_upvalueindex(2));
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
    bdk_csr_write_by_name(node, csr_name, value);
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
    bdk_node_t node = lua_tointeger(L, lua_upvalueindex(2));
    const char *field_name = luaL_checkstring(L, 2);

    const char *fieldn;
    int start_bit = 0;
    int field_width = bdk_csr_field(csr_name, start_bit, &fieldn);
    while (field_width > 0)
    {
        if (strcasecmp(field_name, fieldn) == 0)
        {
            uint64_t value = bdk_csr_read_by_name(node, csr_name);
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
    bdk_node_t node = lua_tointeger(L, lua_upvalueindex(2));
    const char *field_name = luaL_checkstring(L, 2);
    uint64_t new_value = luaL_checknumber(L, 3);


    const char *fieldn;
    int start_bit = 0;
    int field_width = bdk_csr_field(csr_name, start_bit, &fieldn);
    while (field_width > 0)
    {
        if (strcasecmp(field_name, fieldn) == 0)
        {
            uint64_t value = bdk_csr_read_by_name(node, csr_name);
            value &= ~build_mask(field_width, start_bit);
            new_value &= build_mask(field_width, 0);
            value |= new_value << start_bit;
            bdk_csr_write_by_name(node, csr_name, value);
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
    bdk_node_t node = bdk_numa_local();

    if(bdk_csr_get_name(name, NULL))
        luaL_error(L, "Invalid CSR");

    lua_newtable(L);
    lua_pushstring(L, name);
    lua_pushinteger(L, node);
    lua_pushcclosure(L, octeon_csr_read, 2);
    lua_setfield(L, -2, "read");
    lua_pushstring(L, name);
    lua_pushinteger(L, node);
    lua_pushcclosure(L, octeon_csr_write, 2);
    lua_setfield(L, -2, "write");
    lua_pushstring(L, name);
    lua_pushinteger(L, node);
    lua_pushcclosure(L, octeon_csr_display, 2);
    lua_setfield(L, -2, "display");
    lua_pushstring(L, name);
    lua_pushinteger(L, node);
    lua_pushcclosure(L, octeon_csr_decode, 2);
    lua_setfield(L, -2, "decode");
    lua_pushstring(L, name);
    lua_pushinteger(L, node);
    lua_pushcclosure(L, octeon_csr_encode, 2);
    lua_setfield(L, -2, "encode");

    lua_newtable(L);
    lua_pushstring(L, name);
    lua_pushinteger(L, node);
    lua_pushcclosure(L, octeon_csr_field_index, 2);
    lua_setfield(L, -2, "__index");
    lua_pushstring(L, name);
    lua_pushinteger(L, node);
    lua_pushcclosure(L, octeon_csr_field_newindex, 2);
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
        /* Use our argument as the first upvalue for the function */
        /* Put the node in as the second upvalue */
        lua_pushinteger(L, bdk_numa_local());
        lua_pushcclosure(L, octeon_csr_namecall, 2);
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

/**
 * Called to register the octeon module
 *
 * @param L
 *
 * @return
 */
void register_octeon_csr(lua_State* L)
{
    /* Add octeon.csr, magic table access to Octeon CSRs */
    lua_newtable(L); /* csr table */
    lua_pushcfunction(L, octeon_csr_lookup);
    lua_setfield(L, -2, "lookup");
    lua_newtable(L); /* csr metatable */
    lua_pushcfunction(L, octeon_csr_index);
    lua_setfield(L, -2, "__index");
    lua_pushcfunction(L, octeon_csr_newindex);
    lua_setfield(L, -2, "__newindex");
    lua_pushcfunction(L, octeon_csr_call);
    lua_setfield(L, -2, "__call");
    lua_setmetatable(L, -2);
    lua_setfield(L, -2, "csr");
}

