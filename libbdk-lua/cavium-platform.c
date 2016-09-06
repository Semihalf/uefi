/***********************license start***********************************
* Copyright (c) 2003-2016  Cavium Inc. (support@cavium.com). All rights
* reserved.
*
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*
*   * Neither the name of Cavium Inc. nor the names of
*     its contributors may be used to endorse or promote products
*     derived from this software without specific prior written
*     permission.
*
* This Software, including technical data, may be subject to U.S. export
* control laws, including the U.S. Export Administration Act and its
* associated regulations, and may be subject to export or import
* regulations in other countries.
*
* TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
* AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR
* WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT
* TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY
* REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT
* DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES
* OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR
* PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT,
* QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK
* ARISING OUT OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
***********************license end**************************************/
#include <bdk.h>
// Module for determining run platform

/**
 * Lua wrapper for bdk_is_platform
 *
 * @param L
 *
 * @return
 */
static int is_platform(lua_State* L)
{
    uint32_t m = luaL_checkinteger(L, 1);
    lua_pushboolean(L, bdk_is_platform(m));
    return 1;
}

/**
 * Called to register the platform module
 *
 * @param L
 *
 * @return
 */
void register_cavium_platform(lua_State* L)
{
    lua_pushcfunction(L, is_platform);
    lua_setfield(L, -2, "is_platform");

    /* Add constants for the different platform that can be used with
        cavium.is_platform() */
    lua_pushnumber(L, BDK_PLATFORM_HW);
    lua_setfield(L, -2, "PLATFORM_HW");
    lua_pushnumber(L, BDK_PLATFORM_EMULATOR);
    lua_setfield(L, -2, "PLATFORM_EMULATOR");
    lua_pushnumber(L, BDK_PLATFORM_RTL);
    lua_setfield(L, -2, "PLATFORM_RTL");
    lua_pushnumber(L, BDK_PLATFORM_ASIM);
    lua_setfield(L, -2, "PLATFORM_ASIM");
}

