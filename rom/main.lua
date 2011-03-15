
-- BDK Main menu

require("strict")
require("utils")
require("menu")
require("rpc")

-- Do board specific setup
if octeon.is_model(octeon.CN63XX) then
    dofile("/rom/board-ebb6300.lua")
else
    dofile("/rom/board-ebb6800.lua")
end

local function do_rpc()
    print("Starting remote call server.")
    print("Reset to exit.")
    rpc.serve("/dev/uart/0")
end

-- Connect the internals of the TCP/IP stack
octeon.c.bdk_netstack_if_add_all(0)

-- Start a TFTP server
if octeon.c.bdk_tftp_server_initialize() ~= 0 then
    print("Failed to start TFTP server")
end

local m = menu.new("Main Menu")
m:item("file",  "File options",             dofile, "/rom/file.lua")
m:item("flash", "Flash options",            dofile, "/rom/flash.lua")
m:item("ddr",   "DDR options",              dofile, "/rom/ddr_menu.lua")
m:item("pcie",  "PCIe options",             dofile, "/rom/pcie_menu.lua")
m:item("ilua",  "Interactive Lua prompt",   dofile, "/rom/ilua.lua")
m:item("rpc",   "Start remote call server", do_rpc)
m:item("net",   "TCP/IP networking",        dofile, "/rom/netstack_menu.lua")
m:item("tg",    "Traffic Generator",        dofile, "/rom/trafficgen.lua")
m:item("rbt",   "Reboot",                   octeon.c.bdk_reset_octeon)

while (m:show() ~= "quit") do
    -- Spinning on menu
end

