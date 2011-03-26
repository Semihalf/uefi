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

local home = props["SciteDefaultHome"]

-- Add the BDK package path to SciTE's search path
BDK_ROOT = os.getenv("BDK_ROOT")
-- print("BDK is installed at " .. BDK_ROOT)
package.path = package.path .. ";" .. home .. "/?.lua;" .. BDK_ROOT .. "/rom/?.lua"

-- Load the process spawner shared library
local open_fn = assert(package.loadlib(home .. "/unix-spawner-ex.so", "luaopen_spawner"))
open_fn()

-- Load the GUIshared library
local open_fn = assert(package.loadlib(home .. "/gui.so", "luaopen_gui"))
open_fn()

--
-- This function adds a GLOBAL Lua function to the Tools menu
-- caption = String to use as the Tools menu text
-- lua_function = String name of the function to call when chosen
--
local last_command = 0
function add_command(caption, lua_function)
    props["command.name." .. last_command .. ".*.lua"] = caption
    props["command.subsystem." .. last_command .. ".*.lua"] = 3
    props["command." .. last_command .. ".*.lua"] = lua_function .. " $(FileNameExt)"
    last_command = last_command + 1
end

-- Initialize the GUI sidebar
local sidebar = scite.GetSidebarHandle()
gui.InitSidebar(sidebar)
bdk_gui_page_control = PageControl.new(sidebar)

require("bdk_scite_debugger")

print("Loaded BDK customization extensions SciTE")
