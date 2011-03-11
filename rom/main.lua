
-- BDK Main menu

require("strict")
require("utils")
require("menu")
declareGlobal("rpc", require("rpc"))

local function do_rpc()
    print("Starting remote call server.")
    print("Reset to exit.")
    rpc.serve("/dev/uart/0")
end

local m = menu.new("Main Menu")
m:item("file",  "File options",             dofile, "/rom/file.lua")
m:item("flash", "Flash options",            dofile, "/rom/flash.lua")
m:item("ddr",   "DDR options",              dofile, "/rom/ddr_menu.lua")
m:item("hfa",   "HFA options",              print,  "HFA operations are not implemented")
m:item("pcie",  "PCIe options",             dofile, "/rom/pcie_menu.lua")
m:item("ilua",  "Interactive Lua prompt",   dofile, "/rom/ilua.lua")
m:item("rpc",   "Start remote call server", do_rpc)
m:item("tg",    "Traffic Generator",        dofile, "/rom/trafficgen.lua")
m:item("rbt",   "Reboot",                   octeon.c.bdk_reset_octeon)

while (m:show() ~= "quit") do
    -- Spinning on menu
end

