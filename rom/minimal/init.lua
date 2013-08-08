-- Print out a banner
print("")
print("Octeon Bringup and Diagnostic Kit")
print("Copyright (C) 2010-2013 Cavium Networks")
print("Version ".. require("bdk-version"))
print("")

local debug = require("debug")
require("octeon")
require("rpc")

-- Set the baudrate. Many messages have already been printed, but we needed
-- to wait for the octeon module.
-- The first argument is the uart number (0-1)
-- The second argument is the baud rate (9600, 19200, 115200, etc).
-- The third argument is whether flow control is enabled.
-- octeon.c.bdk_set_baudrate(0, 115200, true)
-- octeon.c.bdk_set_baudrate(1, 115200, true)

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
