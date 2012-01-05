#include <bdk.h>

// Module for supporting RPC by supplying common used building
// blocks that are slow in pure Lua.

static int string_pack(lua_State* L)
{
    /* One extra byte ofr the \0 which isn't used */
    static char hex_digits[16] = "0123456789abcdef";
    size_t input_len;
    const char *input = luaL_checklstring(L, 1, &input_len);
    luaL_Buffer output;
    luaL_buffinitsize(L, &output, input_len+2);

    luaL_addchar(&output, '"');
    while (input_len--)
    {
        int b = 0xff & *input;
        /* Escape control chars (<32), high characters (>126), double
            quote (34), and backslash (92) */
        if ((b < 32) || (b > 126) || (b == 34) || (b == 92))
        {
            luaL_addchar(&output, '\\');
            luaL_addchar(&output, hex_digits[b>>4]);
            luaL_addchar(&output, hex_digits[b&0xf]);
        }
        else
            luaL_addchar(&output, b);
        input++;
    }
    luaL_addchar(&output, '"');
    luaL_pushresult(&output);
    return 1;
}

static int string_unpack(lua_State* L)
{
    size_t loc = luaL_checkinteger(L, 1);
    size_t input_len;
    const char *input = luaL_checklstring(L, 2, &input_len);
    luaL_Buffer output;
    luaL_buffinit(L, &output);

    while (loc <= input_len)
    {
        char c = input[loc-1];
        if (c == '\\')
        {
            int i;
            int status = sscanf(input + loc, "%02x", &i);
            if (status != 1)
                return luaL_error(L, "String format error");
            luaL_addchar(&output, i);
            loc += 2;
        }
        else if (c == '"')
        {
            lua_pushnumber(L, loc + 1);
            luaL_pushresult(&output);
            return 2;
        }
        else
            luaL_addchar(&output, c);
        loc++;
    }
    return luaL_error(L, "Ran out of data processing string");
}

static int server_do_pack(lua_State* L)
{
    //local function server_do_pack(objects, ...)
    int num_args = lua_gettop(L);
    luaL_Buffer output;
    luaL_buffinit(L, &output);
    /* Note that num_args can change while the loop is running. Tables
        are inserted into the argument list */
    for (int arg=2; arg<=num_args; arg++)
    {
        switch (lua_type(L, arg))
        {
            case LUA_TNIL:
                luaL_addchar(&output, 'n');
                break;

            case LUA_TBOOLEAN:
                luaL_addchar(&output, (lua_toboolean(L, arg)) ? 't' : 'f');
                break;

            case LUA_TNUMBER:
                luaL_addchar(&output, '#');
                lua_pushvalue(L, arg);
                luaL_addvalue(&output);
                break;

            case LUA_TSTRING:
                lua_pushcfunction(L, string_pack);
                lua_pushvalue(L, arg);
                lua_call(L, 1, 1);
                luaL_addvalue(&output);
                break;

            case LUA_TTABLE:
                if (lua_getmetatable(L, arg) == 0)
                {
                    luaL_addchar(&output, '{');
                    lua_pushnil(L);  /* first key */
                    int insert_loc = arg + 1;
                    while (lua_next(L, arg) != 0)
                    {
                        luaL_checkstack(L, 3, NULL);
                        /* key, value on stack */
                        /* Copy key */
                        lua_pushvalue(L, -2);
                        /* Insert key into args list */
                        lua_insert(L, insert_loc++);
                        /* Insert value into args list */
                        lua_insert(L, insert_loc++);
                        num_args += 2;
                        /* key left on stack for next iteration */
                    }
                    /* The following special user data is used to tell the
                        code below that we need to insert the ending '}' */
                    lua_pushlightuserdata(L, server_do_pack);
                    lua_insert(L, insert_loc++);
                    num_args++;
                    break;
                }
                /* Pop the meta table off the stack */
                lua_pop(L, 1);
                /* Fall through */

            default:
            {
                /* Special marker for the end of a table */
                if (lua_touserdata(L, arg) == server_do_pack)
                {
                    luaL_addchar(&output, '}');
                    break;
                }

                /* Try and treat any other types as generic remote objects
                    All accesses to them will cause RPC calls */
                int id;
                lua_pushvalue(L, arg);
                lua_gettable(L, 1);
                if (!lua_isnil(L, -1))
                {
                    // obj_info = objects[arg] is top of the stack
                    // Get id, which is obj_info[1]
                    lua_pushinteger(L, 1);
                    lua_gettable(L, -2);
                    id = luaL_checkint(L, -1);
                    lua_pop(L, 1);
                    // Update ref count, which is obj_info[2]
                    lua_pushinteger(L, 2);
                    lua_gettable(L, -2);
                    int ref = luaL_checkint(L, -1) + 1;
                    lua_pop(L, 1);
                    lua_pushinteger(L, 2);
                    lua_pushinteger(L, ref);
                    lua_settable(L, -3);
                }
                else
                {
                    // Pop objects[arg], which was nil
                    lua_pop(L, 1);
                    // id = #objects + 1
                    id = luaL_len(L, 1) + 1;
                    // objects[id] = arg
                    lua_pushinteger(L, id);
                    lua_pushvalue(L,  arg);
                    lua_settable(L, 1);
                    // objects[arg] = {id, 1}
                    lua_pushvalue(L,  arg);
                    lua_createtable(L, 2, 0);
                    lua_pushinteger(L, 1);
                    lua_pushinteger(L, id);
                    lua_settable(L, -3);
                    lua_pushinteger(L, 2);
                    lua_pushinteger(L, 1);
                    lua_settable(L, -3);
                    lua_settable(L, 1);
                }
                luaL_addchar(&output, '@');
                lua_pushinteger(L, id);
                luaL_addvalue(&output);
                break;
            }
        }
    }
    luaL_pushresult(&output);
    return 1;
}

static int newproxy(lua_State* L)
{
    luaL_checkany(L, 1);
    lua_newuserdata(L, 0);
    if (lua_isboolean(L, 1))
    {
        if (lua_toboolean(L, 1))
        {
            lua_newtable(L);
            lua_setmetatable(L, -2);
        }
    }
    else
    {
        lua_getmetatable(L, 1);
        lua_setmetatable(L, -2);
    }
    return 1;
}

LUALIB_API int luaopen_rpc_support(lua_State *L)
{
    lua_newtable(L);
    lua_pushcfunction(L, string_pack);
    lua_setfield(L, -2, "string_pack");
    lua_pushcfunction(L, string_unpack);
    lua_setfield(L, -2, "string_unpack");
    lua_pushcfunction(L, server_do_pack);
    lua_setfield(L, -2, "server_do_pack");
    lua_pushcfunction(L, newproxy);
    lua_setfield(L, -2, "newproxy");
    return 1;
}

