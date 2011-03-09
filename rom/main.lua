
-- BDK Main menu

require("strict")
require("utils")
require("menu")
declareGlobal("rpc", require("rpc"))

-- Do board specific setup
if octeon.is_model(octeon.CN63XX) then
    dofile("/rom/board-ebb6300.lua")
else
    dofile("/rom/board-ebb6800.lua")
end
print()

local choices = {
    "File operations",
    "Flash operations",
    "DDR memory options",
    "HFA memory options",
    "PCIe options",
    "Interactive Lua prompt",
    "Start remote call server",
    "Traffic Gen",
    "Reboot",
}

while (true) do
    local c = menu.show(choices)
    if (c == 1) then
        dofile("/rom/file.lua")
    elseif (c == 2) then
        dofile("/rom/flash.lua")
    elseif (c == 3) then
        dofile("/rom/ddr_menu.lua")
    elseif (c == 4) then
        print("Not implemented yet")
    elseif (c == 5) then
        dofile("/rom/pcie_menu.lua")
    elseif (c == 6) then
        dofile("/rom/ilua.lua")
    elseif (c == 7) then
        print("Starting remote call server.")
        print("Reset to exit.")
        rpc.serve("/dev/uart/0")
    elseif (c == 8) then
        dofile("/rom/trafficgen.lua")
    elseif (c == 9) then
        octeon.c.bdk_reset_octeon()
    end
end
