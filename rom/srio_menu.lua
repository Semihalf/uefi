
-- BDK SRIO menu

require("strict")
require("utils")
require("menu")
require("srio")

local srio_root = {}

local function not_implemented()
    error("Not implemented")
end

local function do_initialize(srio_port)
    assert(srio_root[srio_port] == nil, "SRIO" .. srio_port .. " already initialized")
    srio_root[srio_port] = srio.initialize(srio_port)
end

local function do_scan(srio_port)
    assert(srio_root[srio_port], "SRIO" .. srio_port .. " not initialized")
    srio_root[srio_port]:scan()
end

local function do_enumerate(srio_port)
    assert(srio_root[srio_port], "SRIO" .. srio_port .. " not initialized")
    srio_root[srio_port]:enumerate()
end

local function do_display(srio_port)
    assert(srio_root[srio_port], "SRIO" .. srio_port .. " not initialized")
    srio_root[srio_port]:display()
end


local function srio_submenu(srio_port)
    local prefix = "SRIO" .. srio_port
    local m = menu.new("SRIO Menu - Port " .. srio_port)
    m:item("init", prefix .. ": Initialize", do_initialize, srio_port)
    m:item("scan", prefix .. ": Scan for devices", do_scan, srio_port)
    m:item("enum", prefix .. ": Enumerate devices", do_enumerate, srio_port)
    m:item("show", prefix .. ": Display devices", do_display, srio_port)
    m:item("mread", prefix .. ": Perform a maintenance read", not_implemented, srio_port)
    m:item("mwrite", prefix .. ": Perform a maintenance write", not_implemented, srio_port)
    m:item("sdb", prefix .. ": Send a doorbell", not_implemented, srio_port)
    m:item("rdb", prefix .. ": Receive a doorbell", not_implemented, srio_port)
    m:item("read", prefix .. ": Perform a memory read", not_implemented, srio_port)
    m:item("write", prefix .. ": Perform a memory write", not_implemented, srio_port)
    m:item("quit", "Main menu")

    while (m:show() ~= "quit") do
    -- Spinning on menu
    end
end


local m = menu.new("SRIO Menu")

-- Build a list of SRIO ports
local srio_ports = 0
if octeon.is_model(octeon.CN63XX) then
    srio_ports = 2
elseif octeon.is_model(octeon.CN65XX) then
    srio_ports = 4
end
for port = 0, srio_ports-1 do
    m:item("port" .. port, "SRIO port " .. port, srio_submenu, port)
end
m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


