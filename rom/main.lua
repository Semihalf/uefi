
-- BDK Main menu

require("strict")
require("menu")

-- Do board specific setup
dofile("/rom/board-ebb6300.lua")

local choices = {
    "File operations",
    "DDR memory options",
    "HFA memory options",
    "Interactive Lua prompt",
    "Start remote call server",
    "Reboot",
}

while (true) do
    local c = menu.show(choices)
    if (c == 4) then
        dofile("/rom/ilua.lua")
    elseif (c == 5) then
        print("Starting remote call server.")
        print("Reset to exit.")
        local rpc = require("rpc")
        rpc.serve("/dev/uart/0")
    elseif (c == 6) then
        octeon.c.bdk_reset_octeon()
    else
        print("Not implemented yet")
    end
end
