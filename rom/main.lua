
-- BDK Main menu

require("menu")

choices = {
    "File operations",
    "DDR memory options",
    "HFA memory options",
    "Interactive Lua prompt",
    "Start remote call server",
    "Reboot",
}

while (true) do
    c = menu.show(choices)
    if (c == 4) then
        dofile("/rom/ilua.lua")
    elseif (c == 5) then
        print("Starting remote call server.")
        print("Reset to exit.")
        rpc = require("rpc")
        rpc.serve("/dev/uart/0")
    elseif (c == 6) then
        octeon.c.bdk_reset_octeon()
    else
        print("Not implemented yet")
    end
end
