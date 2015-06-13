
-- Print out a banner
print("")
print("THUNDERX Diagnostics")
print("Copyright (C) 2010-2015 Cavium Inc.")
print("Version ".. require("bdk-version"))
print("")

local debug = require("debug")

-- Start the main menu.
while true do
    local status, result = xpcall(dofile, debug.traceback, "/rom/main.lua")
    if not status then
        print("ERROR:", result)
    end
end
