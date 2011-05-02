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

-- Do nothing if octeon is already defined
if isglobal("octeon") then
    return octeon
end

-- Table for this module
octeon = {}

-- Create a connection to the remote system
local cnx = os.getenv("OCTEON_REMOTE_CONSOLE")
assert(cnx, "The environment variable OCTEON_REMOTE_CONSOLE msut be defined")
local remote = rpc.connect(cnx)
local remote_octeon = remote.octeon

-- When we are iterating tables we really want to iterate on the remote table,
-- so we need a pointer to the remote pairs() function so we can call it.
local remote_pairs = remote.pairs

-- Copy a remote table into a local table by making each local field
-- Point to the remote field
local function shallow_copy(remote_table)
    local result = {}
    for name, value in remote_pairs(remote_table) do
        result[name] = value
    end
    return result
end

-- Perform a shallow copy so the local octeon module
-- points to all the members of the remote octeon module.
octeon = shallow_copy(remote_octeon)

-- Delete readline as it would cause problems if someone
-- called it
octeon.readline = nil

-- Add a global member that has access to the global context on the remote
-- system
octeon.global = remote

-- C functions are used often, so copy their table so we avoid an extra
-- RPC call to lookup the function names later
octeon.c = shallow_copy(remote_octeon.c)

--- Make a local copy of the trafficgen member
octeon.trafficgen = shallow_copy(remote_octeon.trafficgen)

--- Make a local copy of the perf member
octeon.perf = shallow_copy(remote_octeon.perf)

return octeon

