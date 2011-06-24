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
void register_octeon_config(lua_State* L)
{
    /* Add constants for bdk_config */
    for (bdk_config_t c=0; c<__BDK_CONFIG_END; c++)
    {
        lua_pushnumber(L, c);
        lua_setfield(L, -2, bdk_config_get_name(c));
    }
}

