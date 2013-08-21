#include <bdk.h>
#include "octeon-remote.h"

// Module for interfacing with a remote Octeon

#define TLB_SIZE 256

/**
 * oremote.open(protocol, debug)
 * protocol = Remote protocol or nil
 * debug = Debug level or nil
 * No return value
 *
 * @param L
 *
 * @return
 */
static int oremote_open(lua_State* L)
{
    const char *remote_spec = luaL_optstring (L, 1, NULL);
    int debug = luaL_optinteger (L, 2, 0);

    if (octeon_remote_open(remote_spec, debug))
        return luaL_error(L, "octeon_remote_open failed");

    octeon_remote_lock();
    return 0;
}

/**
 * oremote.close()
 * No return value
 *
 * @param L
 *
 * @return
 */
static int oremote_close(lua_State* L)
{
    octeon_remote_unlock();
    octeon_remote_close();
    return 0;
}

/**
 * oremote.read_csr(type, busnum, size, address)
 * type = CSR enum type
 * busnum = Bus number
 * size = Read size in bytes
 * address = CSR address
 * Return csr value as a number
 *
 * @param L
 *
 * @return
 */
static int oremote_read_csr(lua_State* L)
{
    int node = luaL_checknumber(L, 1);
    int type = luaL_checknumber(L, 2);
    int busnum = luaL_checknumber(L, 3);
    int size = luaL_checknumber(L, 4);
    uint64_t address = luaL_checknumber(L, 5);
    lua_pushnumber(L, octeon_remote_read_csr(node, type, busnum, size, address));
    return 1;
}

/**
 * oremote.write_csr(type, busnum, size, address, value)
 * type = CSR enum type
 * busnum = Bus number
 * size = Read size in bytes
 * address = CSR address
 * value = Value of CSR as a number
 * No return value
 *
 * @param L
 *
 * @return
 */
static int oremote_write_csr(lua_State* L)
{
    int node = luaL_checknumber(L, 1);
    int type = luaL_checknumber(L, 2);
    int busnum = luaL_checknumber(L, 3);
    int size = luaL_checknumber(L, 4);
    uint64_t address = luaL_checknumber(L, 5);
    uint64_t value = luaL_checknumber(L, 6);
    octeon_remote_write_csr(node, type, busnum, size, address, value);
    return 0;
}

/**
 * oremote.read_mem(address, length)
 * address = Physical address to read
 * length = Number of bytes to read
 * Returns string of length
 *
 * @param L
 *
 * @return
 */
static int oremote_read_mem(lua_State* L)
{
    uint64_t address = luaL_checknumber(L, 1);
    int length = luaL_checkinteger(L, 2);
    luaL_Buffer output;
    char *buffer = luaL_buffinitsize(L, &output, length);

    octeon_remote_read_mem(buffer, address, length);

    luaL_pushresultsize(&output, length);
    return 1;
}

/**
 * oremote.write_mem(address, bytes)
 * address = physical address to write
 * bytes = string of bytes to write
 * No return value
 *
 * @param L
 *
 * @return
 */
static int oremote_write_mem(lua_State* L)
{
    size_t length;
    uint64_t address = luaL_checknumber(L, 1);
    const char *buffer = luaL_checklstring(L, 2, &length);

    octeon_remote_write_mem(address, buffer, length);
    return 0;
}

/**
 * oremote.get_model()
 * Returns Processor ID register as number
 *
 * @param L
 *
 * @return
 */
static int oremote_get_model(lua_State* L)
{
    lua_pushnumber(L, octeon_remote_get_model());
    return 1;
}

/**
 * oremote.start_cores(mask)
 * mask = Bitmask of cores to start
 * No return value
 *
 * @param L
 *
 * @return
 */
static int oremote_start_cores(lua_State* L)
{
    uint64_t mask = luaL_checknumber(L, 1);
    octeon_remote_start_cores(mask);
    return 0;
}

/**
 * oremote.stop_cores(mask)
 * mask = Bitmask of cores to stop
 * No return value
 *
 * @param L
 *
 * @return
 */
static int oremote_stop_cores(lua_State* L)
{
    uint64_t mask = luaL_checknumber(L, 1);
    octeon_remote_stop_cores(mask);
    return 0;
}

/**
 * oremote.get_num_cores()
 * Returns the number of cores as a number
 *
 * @param L
 *
 * @return
 */
static int oremote_get_num_cores(lua_State* L)
{
    lua_pushnumber(L, octeon_remote_get_num_cores());
    return 1;
}

/**
 * oremote.get_running_cores()
 * Returns the bitmask of cores that are running
 *
 * @param L
 *
 * @return
 */
static int oremote_get_running_cores(lua_State* L)
{
    lua_pushnumber(L, octeon_remote_get_running_cores());
    return 1;
}

/**
 * oremote.get_core_state(core)
 * core = Core state to get, starting at 0
 * Returns table
 * table[1][1-256] = Normal registers
 * table[2][1-256] = COP0 reg * 8 + sel
 * table[3][1-TLB_SIZE][1-4] = TLB
 *
 * @param L
 *
 * @return
 */
static int oremote_get_core_state(lua_State* L)
{
    octeon_remote_registers_t registers;
    int core = luaL_checkinteger(L, 1);

    if (octeon_remote_get_core_state(core, &registers))
        return luaL_error(L, "octeon_remote_get_core_state failed");

    /* The table we will return */
    lua_createtable(L, 3, 0);

    /* Index 1 = Regs 0-255. Index 2 = COP0 reg*8+sel */
    for (int set=0; set<2; set++)
    {
        lua_pushinteger(L, set+1);
        lua_createtable(L, 256, 0);
        for (int r=0; r<256; r++)
        {
            lua_pushinteger(L, r+1);
            lua_pushnumber(L, registers.regs[set][r]);
            lua_settable(L, -3);
        }
        lua_settable(L, -3);
    }

    /* Index 3 = TLB table [TLB_SIZE][4] */
    lua_pushinteger(L, 3);
    lua_createtable(L, TLB_SIZE, 0);
    for (int tlb=0; tlb<TLB_SIZE; tlb++)
    {
        lua_pushinteger(L, tlb+1);
        lua_createtable(L, 4, 0);
        for (int r=0; r<4; r++)
        {
            lua_pushinteger(L, r+1);
            lua_pushnumber(L, registers.tlb[tlb][r]);
            lua_settable(L, -3);
        }
        lua_settable(L, -3);
    }
    lua_settable(L, -3);
    return 1;
}

/**
 * oremote.set_core_state(core, state)
 * core = Core state to set, starting at 0
 * state = table of format from get_core_state
 * No return value
 *
 * @param L
 *
 * @return
 */
static int oremote_set_core_state(lua_State* L)
{
    octeon_remote_registers_t registers;
    int core = luaL_checkinteger(L, 1);
    luaL_checktype(L, 2, LUA_TTABLE);

    /* Index 1 = Regs 0-255. Index 2 = COP0 reg*8+sel */
    for (int set=0; set<2; set++)
    {
        lua_pushinteger(L, set+1);
        lua_gettable(L, 2);
        for (int r=0; r<256; r++)
        {
            lua_pushinteger(L, r+1);
            lua_gettable(L, -2);
            registers.regs[set][r] = luaL_checknumber(L, -1);
            lua_pop(L, 1);
        }
        lua_pop(L, 1);
    }

    /* Index 3 = TLB table [TLB_SIZE][4] */
    lua_pushinteger(L, 3);
    lua_gettable(L, 2);
    for (int tlb=0; tlb<TLB_SIZE; tlb++)
    {
        lua_pushinteger(L, tlb+1);
        lua_gettable(L, -2);
        for (int r=0; r<4; r++)
        {
            lua_pushinteger(L, r+1);
            lua_gettable(L, -2);
            registers.tlb[tlb][r] = luaL_checknumber(L, -1);
            lua_pop(L, 1);
        }
        lua_pop(L, 1);
    }
    lua_pop(L, 1);

    if (octeon_remote_set_core_state(core, &registers))
        return luaL_error(L, "octeon_remote_set_core_state failed");
    return 0;
}

/**
 * oremote.read_register(core, register)
 * core = Core starting at 0
 * register = register number to get
 * Return register as number
 *
 * @param L
 *
 * @return
 */
static int oremote_read_register(lua_State* L)
{
    int core = luaL_checkinteger(L, 1);
    int reg = luaL_checkinteger(L, 2);
    lua_pushnumber(L, octeon_remote_read_register(core, reg));
    return 1;
}

/**
 * oremote.write_register(core, register, value)
 * core = Core starting at 0
 * register = register number to set
 * value = Register value
 * No return value
 *
 * @param L
 *
 * @return
 */
static int oremote_write_register(lua_State* L)
{
    int core = luaL_checkinteger(L, 1);
    int reg = luaL_checkinteger(L, 2);
    uint64_t value = luaL_checknumber(L, 3);
    octeon_remote_write_register(core, reg, value);
    return 0;
}

/**
 * oremote.reset(stop_cores)
 * stop_cores = Cores should stop after reset
 * No return value
 *
 * @param L
 *
 * @return
 */
static int oremote_reset(lua_State* L)
{
    int stop_core = luaL_checkinteger(L, 1);
    if (octeon_remote_reset(stop_core))
        return luaL_error(L, "octeon_remote_reset failed");
    return 0;
}

/**
 * oremote.get_sample(mask)
 * mask = Bitmask of cores to get sampels for
 * Return table of PC values indexed by core num+1
 *
 * @param L
 *
 * @return
 */
static int oremote_get_sample(lua_State* L)
{
    uint64_t mask = luaL_checknumber(L, 1);
    octeon_remote_sample_t sample[64];
    if (octeon_remote_get_sample(mask, sample))
        return luaL_error(L, "octeon_remote_get_sample failed");

    /* The table we will return */
    lua_createtable(L, 64, 0);

    /* table[core] = PC */
    for (int core=0; core<64; core++)
    {
        lua_pushinteger(L, core+1);
        lua_pushnumber(L, sample[core].pc);
        lua_settable(L, -3);
    }
    return 1;
}

/**
 * oremote.write_mem16(address, data)
 * address = Physical address
 * data = data to write
 * No return value
 *
 * @param L
 *
 * @return
 */
static int oremote_write_mem16(lua_State* L)
{
    uint64_t address = luaL_checknumber(L, 1);
    uint64_t data = luaL_checknumber(L, 2);
    octeon_remote_write_mem16(address, data);
    return 0;
}

/**
 * oremote.write_mem32(address, data)
 * address = Physical address
 * data = data to write
 * No return value
 *
 * @param L
 *
 * @return
 */
static int oremote_write_mem32(lua_State* L)
{
    uint64_t address = luaL_checknumber(L, 1);
    uint64_t data = luaL_checknumber(L, 2);
    octeon_remote_write_mem32(address, data);
    return 0;
}

/**
 * oremote.write_mem64(address, data)
 * address = Physical address
 * data = data to write
 * No return value
 *
 * @param L
 *
 * @return
 */
static int oremote_write_mem64(lua_State* L)
{
    uint64_t address = luaL_checknumber(L, 1);
    uint64_t data = luaL_checknumber(L, 2);
    octeon_remote_write_mem64(address, data);
    return 0;
}

/**
 * oremote.read_mem16(address)
 * address = Physical address
 * Return data
 *
 * @param L
 *
 * @return
 */
static int oremote_read_mem16(lua_State* L)
{
    uint64_t address = luaL_checknumber(L, 1);
    lua_pushnumber(L, octeon_remote_read_mem16(address));
    return 1;
}

/**
 * oremote.read_mem32(address)
 * address = Physical address
 * Return data
 *
 * @param L
 *
 * @return
 */
static int oremote_read_mem32(lua_State* L)
{
    uint64_t address = luaL_checknumber(L, 1);
    lua_pushnumber(L, octeon_remote_read_mem32(address));
    return 1;
}

/**
 * oremote.read_mem64(address)
 * address = Physical address
 * Return data
 *
 * @param L
 *
 * @return
 */
static int oremote_read_mem64(lua_State* L)
{
    uint64_t address = luaL_checknumber(L, 1);
    lua_pushnumber(L, octeon_remote_read_mem64(address));
    return 1;
}

/**
 * Called to register the octeon module
 *
 * @param L
 *
 * @return
 */
LUALIB_API int luaopen_oremote(lua_State* L)
{
    /* Create a new table for the oremote module */
    lua_newtable(L);

    lua_pushcfunction(L, oremote_open);
    lua_setfield(L, -2, "open");
    lua_pushcfunction(L, oremote_close);
    lua_setfield(L, -2, "close");
    lua_pushcfunction(L, oremote_read_csr);
    lua_setfield(L, -2, "read_csr");
    lua_pushcfunction(L, oremote_write_csr);
    lua_setfield(L, -2, "write_csr");
    lua_pushcfunction(L, oremote_read_mem);
    lua_setfield(L, -2, "read_mem");
    lua_pushcfunction(L, oremote_write_mem);
    lua_setfield(L, -2, "write_mem");
    lua_pushcfunction(L, oremote_get_model);
    lua_setfield(L, -2, "get_model");
    lua_pushcfunction(L, oremote_start_cores);
    lua_setfield(L, -2, "start_cores");
    lua_pushcfunction(L, oremote_stop_cores);
    lua_setfield(L, -2, "stop_cores");
    lua_pushcfunction(L, oremote_get_num_cores);
    lua_setfield(L, -2, "get_num_cores");
    lua_pushcfunction(L, oremote_get_running_cores);
    lua_setfield(L, -2, "get_running_cores");
    lua_pushcfunction(L, oremote_get_core_state);
    lua_setfield(L, -2, "get_core_state");
    lua_pushcfunction(L, oremote_set_core_state);
    lua_setfield(L, -2, "set_core_state");
    lua_pushcfunction(L, oremote_read_register);
    lua_setfield(L, -2, "read_register");
    lua_pushcfunction(L, oremote_write_register);
    lua_setfield(L, -2, "write_register");
    lua_pushcfunction(L, oremote_reset);
    lua_setfield(L, -2, "reset");
    lua_pushcfunction(L, oremote_get_sample);
    lua_setfield(L, -2, "get_sample");
    lua_pushcfunction(L, oremote_write_mem16);
    lua_setfield(L, -2, "write_mem16");
    lua_pushcfunction(L, oremote_write_mem32);
    lua_setfield(L, -2, "write_mem32");
    lua_pushcfunction(L, oremote_write_mem64);
    lua_setfield(L, -2, "write_mem64");
    lua_pushcfunction(L, oremote_read_mem16);
    lua_setfield(L, -2, "read_mem16");
    lua_pushcfunction(L, oremote_read_mem32);
    lua_setfield(L, -2, "read_mem32");
    lua_pushcfunction(L, oremote_read_mem64);
    lua_setfield(L, -2, "read_mem64");

    #define REGISTER(L, name) \
        extern void register_##name(lua_State* L); \
        register_##name(L)

    REGISTER(L, octeon_model);
    REGISTER(L, octeon_constants);
    REGISTER(L, octeon_mmc);

    return 1;
}

