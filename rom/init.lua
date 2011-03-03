
-- Print out a banner
print("")
print("Octeon Bringup and Diagnostic Kit")
print("Copyright (C) 2010-2011 Cavium Networks")
print("")

local debug = require("debug")

-- Start the main menu.
while true do
    status, result = xpcall(dofile, debug.traceback, "/rom/main.lua")
    if not status then
        print("ERROR:", result)
    end
end
