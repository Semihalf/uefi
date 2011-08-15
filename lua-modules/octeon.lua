--
-- Lua module supporting remote Octeon connections through
-- RPC. When running on the target, the module "octeon" is
-- already pre-loaded, so this file is never executed. On the
-- host, this will be called when a script does a
-- "require(octeon)". We then use RPC to connect this host
-- "octeon" module with the one on the target.
-- Written by Chad Reese
-- Copyright (C) 2010-2011 Cavium Networks
--

require("strict")
require("utils")
require("rpc")

-- Table for this module
octeon = {}

-- Create a connection to the remote system
local cnx = os.getenv("OCTEON_REMOTE_CONSOLE")
assert(cnx,
[[
Missing environment.

The environment variable OCTEON_REMOTE_CONSOLE must be defined.
OCTEON_REMOTE_CONSOLE should be a serial device (/dev/ttyS0),
an IPv4 address and port number for TCP/IP (10.0.0.2:23), or the
special value "remote". A hostname can also be used for IPv4
address name lookup. The TCP port will default to 23 if omitted.
The special value of "remote" uses the OCTEON_REMOTE_PROTOCOL to
access the remote console.
]])
local remote = rpc.connect(cnx)
octeon = remote.octeon

-- Create a local fake readline as calling the remote one would cause issues
function octeon.readline(prompt, complete, timeout_us)
    printf("%s: ", prompt)
    return io.read("*l")
end

-- Add a global member that has access to the global context on the remote
-- system
octeon.global = remote

return octeon

