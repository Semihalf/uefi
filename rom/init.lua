
-- Print out a banner
print("")
print("Octeon Bringup and Diagnostic Kit")
print("Copyright (C) 2010-2011 Cavium Networks")
print("")

local debug = require("debug")
require("octeon")
require("rpc")

print("Connect to this server by setting the OCTEON_REMOTE_CONSOLE")
print("environment variable to a serial device (/dev/ttyS0), a")
print("TCP/IP port for a terminal server (tserver:23), or use")
print("a virtual console through the OCTEON_REMOTE_PROTOCOL (remote).")

-- Start the RPC server
while true do
    print("")
    print("Starting RPC server listening for connections...")
    local status, result = xpcall(rpc.serve, debug.traceback)
    if not status then
        print("ERROR:", result)
    end
end
