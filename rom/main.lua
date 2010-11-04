
-- BDK Main menu

require("menu")

choices = {
    "File operations",
    "DDR memory options",
    "HFA memory options",
    "Interactive Lua prompt",
    "Reboot",
}

while (true) do
    c = menu.show(choices)
    if (c == 4) then
        dofile("/rom/ilua.lua")
    elseif (c == 5) then
        octeon.c.bdk_reset_octeon()
    else
        print("Not implemented yet")
    end
end
