#ifndef BDK_BUILD_HOST
#include <bdk.h>
#include <unistd.h>
#else
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#endif
// Module for interfacing with Octeon

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

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

    REGISTER(L, octeon_model);
    REGISTER(L, octeon_c);
    REGISTER(L, octeon_config);
    REGISTER(L, octeon_constants);
    REGISTER(L, readline);
    REGISTER(L, trafficgen);
    REGISTER(L, octeon_perf);
#ifndef BDK_DISABLE_CSR_DB
    REGISTER(L, octeon_csr);
#endif

    extern int luaopen_bdk_board_table_entry(lua_State *L);
    luaopen_bdk_board_table_entry(L);

    lua_setglobal(L, "octeon");
    lua_getglobal(L, "octeon");
    return 1;
}

