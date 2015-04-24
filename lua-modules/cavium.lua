--
-- Lua module supporting remote connections through
-- RPC or locally on the target. When running on the target,
-- the module "cavium-internal" is already pre-loaded, so
-- this file use it as a base. On the host, this will be
-- called when a script does a "require(cavium)". We then
-- use RPC to connect this host "cavium" module with the
-- one on the target.
--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2014 Cavium Inc.
--
if rawget(_G, "cavium") then
    return cavium
end

require("utils")

local status, base = pcall(require, "cavium-internal")

if not status then
    -- Create a connection to the remote system
    local cnx = os.getenv("CAVIUM_REMOTE_CONSOLE")
    assert(cnx,
[[
Missing environment.

The environment variable CAVIUM_REMOTE_CONSOLE must be defined.
CAVIUM_REMOTE_CONSOLE should be a serial device (/dev/ttyS0),
an IPv4 address and port number for TCP/IP (10.0.0.2:23), or the
special value "remote". A hostname can also be used for IPv4
address name lookup. The TCP port will default to 23 if omitted.
The special value of "remote" uses the CAVIUM_REMOTE_PROTOCOL to
access the remote console.
]])
    require("rpc")
    local remote = rpc.connect(cnx)
    base = remote.cavium

    -- Add a global member that has access to the global context on the remote
    -- system
    base.global = remote
else
    base.global = false
end

-- Make the cavium module global by default
cavium = base

-- Create the CSR table
local status, lookup = pcall(require, "csr")
if status then
    base.csr = lookup(base, base.c.bdk_csr_read, base.c.bdk_csr_write)
end

return base

