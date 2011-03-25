--
-- SciTE startup script for use with the BDK
--
-- This script defines some extensions for SciTE to make it easier
-- to develop Lua scripts using the BDK. Some of the extend features
-- are:
--
-- 1) Load the "spawner" module from scite-debug. This module
--	gives  scripts process control.
-- X) FIXME
--

-- Add the BDK package path to SciTE's search path
BDK_ROOT = os.getenv("BDK_ROOT")
-- print("BDK is installed at " .. BDK_ROOT)
package.path = package.path .. ";" .. BDK_ROOT .. "/rom/?.lua"

-- Load modules that make programing easier
require("strict")
require("utils")

-- Load the process spawner shared library
local home = props["SciteDefaultHome"]
local open_fn = assert(package.loadlib(home.. "/unix-spawner-ex.so", "luaopen_spawner"))
open_fn()

--
-- This function adds a GLOBAL Lua function to the Tools menu
-- caption = String to use as the Tools menu text
-- lua_function = String name of the function to call when chosen
--
local last_command = 0
local function add_command(caption, lua_function)
    props["command.name.%d.*.lua" % last_command] = caption
    props["command.subsystem.%d.*.lua" % last_command] = 3
    props["command.%d.*.lua" % last_command] = lua_function .. " $(FileNameExt)"
    last_command = last_command + 1
end

function command_debug(filename)
    print("Sorry, not implemented yet")
end
add_command("Debug", "command_debug")

--pprint(_G)

print("Loaded BDK customization extensions SciTE")