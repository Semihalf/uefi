#include <bdk.h>
#include <unistd.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(DRAM_CONFIG);

/**
 * Called to register the cavium module
 *
 * @param L
 *
 * @return
 */
void register_cavium_dram(lua_State* L)
{
    //extern int luaopen_bdk_board_table_entry(lua_State *L);
    //luaopen_bdk_board_table_entry(L);
}

