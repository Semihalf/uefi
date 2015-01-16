#include <bdk.h>
#include <unistd.h>
// Module for interfacing with the chip

/**
 * Called to register the cavium module
 *
 * @param L
 *
 * @return
 */
LUALIB_API int luaopen_cavium(lua_State* L)
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

    REGISTER(L, cavium_model);
    REGISTER(L, cavium_platform);
    REGISTER(L, cavium_c);
    REGISTER(L, cavium_config);
    REGISTER(L, cavium_constants);
    REGISTER(L, cavium_perf);
    REGISTER(L, cavium_mmc);

    if (BDK_IS_REQUIRED(TRAFFIC_GEN))
    {
        extern void register_trafficgen(lua_State* L) BDK_WEAK;
        register_trafficgen(L);
    }

    if (BDK_IS_REQUIRED(CSR_DB))
    {
        extern void register_cavium_csr(lua_State* L) BDK_WEAK;
        register_cavium_csr(L);
    }

    return 1;
}

