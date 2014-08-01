--
-- Lua module supporting remote connections through
-- RPC or locally on the target. When running on the target,
-- the module "octeon-internal" is already pre-loaded, so
-- this file use it as a base. On the host, this will be
-- called when a script does a "require(octeon)". We then
-- use RPC to connect this host "octeon" module with the
-- one on the target.
--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2013 Cavium Networks
--
require("utils")

local status, base = pcall(require, "octeon-internal")

if not status then
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
    require("rpc")
    local remote = rpc.connect(cnx)
    base = remote.octeon

    -- Add a global member that has access to the global context on the remote
    -- system
    base.global = remote
else
    base.global = false
end

-- Create the CSR table
local status, lookup = pcall(require, "csr")
if status then
    base.csr = lookup(base, base.c.bdk_csr_read, base.c.bdk_csr_write)
end

-- Make the octeon module global by default
octeon = base

return base

