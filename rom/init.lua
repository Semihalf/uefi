
-- Print out a banner
print("")
print("Octeon Bringup and Diagnostic Kit")
print("Copyright (C) 2010-2011 Cavium Networks")
print("")

-- Make GC very aggressive so we don't leak memory
collectgarbage("setpause", 0)
collectgarbage("setstepmul", 100000)

-- Start the main menu.
while true do
    status, result = pcall(dofile, "/rom/main.lua")
    if not status then
        printf("ERROR: %s\n", result)
    end
end
