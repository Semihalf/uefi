
-- BDK Main menu

require("strict")
require("utils")
require("menu")
require("rpc")

-- Do board specific setup
if octeon.is_model(octeon.CN63XX) then
    dofile("/rom/board-ebb6300.lua")
elseif octeon.is_model(octeon.CN68XX) then
    dofile("/rom/board-ebb6800.lua")
elseif octeon.is_model(octeon.CN65XX) then
    dofile("/rom/board-ebb6500.lua")
end

-- Start a TFTP server
if octeon.c.bdk_tftp_server_initialize() ~= 0 then
    print("Failed to start TFTP server")
end

-- Start a Telnet server
if octeon.c.bdk_telnet_server_initialize() ~= 0 then
    print("Failed to start Telnet server")
end

local m = menu.new("Main Menu")
m:item("config","Configuration options",    dofile, "/rom/config_menu.lua")
m:item("file",  "File options",             dofile, "/rom/file.lua")
m:item("flash", "Flash options",            dofile, "/rom/flash.lua")
m:item("ddr",   "DDR options",              dofile, "/rom/ddr_menu.lua")
m:item("pcie",  "PCIe options",             dofile, "/rom/pcie_menu.lua")
if octeon.is_model(octeon.CN63XX) or octeon.is_model(octeon.CN65XX) then
    m:item("srio",  "SRIO options",         dofile, "/rom/srio_menu.lua")
end
m:item("twsi",  "TWSI options",             dofile, "/rom/twsi_menu.lua")
m:item("smi",   "SMI/MDIO options",         dofile, "/rom/smi_menu.lua")
m:item("gpio",  "GPIO options",             dofile, "/rom/gpio_menu.lua")
m:item("ilua",  "Interactive Lua prompt",   dofile, "/rom/ilua.lua")
m:item("net",   "TCP/IP networking",        dofile, "/rom/netstack_menu.lua")
m:item("tg",    "Traffic Generator",        dofile, "/rom/trafficgen.lua")
m:item("rbt",   "Reboot",                   octeon.c.bdk_reset_octeon)

while (m:show() ~= "quit") do
    -- Spinning on menu
end

