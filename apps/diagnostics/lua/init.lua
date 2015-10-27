
-- Print out a banner
print("")
print("THUNDERX Diagnostics")
print("Copyright (C) 2010-2015 Cavium Inc.")
print("BDK Version: ".. require("bdk-version"))
print("")

local debug = require("debug")

-- Start the main menu.
while true do
    local main_name = assert(package.searchpath("main", package.path))
    local status, result = xpcall(dofile, debug.traceback, main_name)
    if not status then
        print("ERROR:", result)
    end
end
