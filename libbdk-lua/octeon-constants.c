#include <bdk.h>
#include <unistd.h>

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
void register_octeon_constants(lua_State* L)
{
    lua_pushnumber(L, BDK_CSR_TYPE_RSL);
    lua_setfield(L, -2, "CSR_TYPE_RSL");
    lua_pushnumber(L, BDK_CSR_TYPE_NCB);
    lua_setfield(L, -2, "CSR_TYPE_NCB");
    lua_pushnumber(L, BDK_CSR_TYPE_PEXP);
    lua_setfield(L, -2, "CSR_TYPE_PEXP");
    lua_pushnumber(L, BDK_CSR_TYPE_PEXP_NCB);
    lua_setfield(L, -2, "CSR_TYPE_PEXP_NCB");
    lua_pushnumber(L, BDK_CSR_TYPE_PCICONFIGEP);
    lua_setfield(L, -2, "CSR_TYPE_PCICONFIGEP");
    lua_pushnumber(L, BDK_CSR_TYPE_PCICONFIGRC);
    lua_setfield(L, -2, "CSR_TYPE_PCICONFIGRC");
    lua_pushnumber(L, BDK_CSR_TYPE_SRIOMAINT);
    lua_setfield(L, -2, "CSR_TYPE_SRIOMAINT");
}

