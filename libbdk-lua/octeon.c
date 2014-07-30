#include <bdk.h>
#include <unistd.h>
// Module for interfacing with Octeon

/**
 * Called to register the octeon module
 *
 * @param L
 *
 * @return
 */
LUALIB_API int luaopen_octeon(lua_State* L)
{
    #define REGISTER(L, name) \
        extern void register_##name(lua_State* L); \
        register_##name(L)

    /* Create a new table for the module */
    lua_newtable(L);

    /* Add function for opening device files. Used by RPC. This is just
        another way to get to the local io.open */
    lua_getglobal(L, "io");
    lua_getfield (L, -1, "open");
    lua_setfield(L, -3, "devopen");
    lua_pop(L, 1);

    REGISTER(L, octeon_model);
    REGISTER(L, octeon_c);
    REGISTER(L, octeon_config);
    REGISTER(L, octeon_constants);
    //REGISTER(L, octeon_perf);
    REGISTER(L, octeon_mmc);

    if (BDK_IS_REQUIRED(TRAFFIC_GEN))
    {
        extern void register_trafficgen(lua_State* L) BDK_WEAK;
        register_trafficgen(L);
    }

    if (BDK_IS_REQUIRED(CSR_DB))
    {
        extern void register_octeon_csr(lua_State* L) BDK_WEAK;
        register_octeon_csr(L);
    }

    if (BDK_IS_REQUIRED(DRAM_CONFIG))
    {
        extern void register_octeon_dram(lua_State* L) BDK_WEAK;
        register_octeon_dram(L);
    }

    return 1;
}

