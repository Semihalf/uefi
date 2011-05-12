
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

local function do_maintread(srio_port)
    local devid = menu.prompt_number("Device ID")
    assert((devid >= -1) and (devid < 65536), "Illegal device ID")
    local is16bit = menu.prompt_string("Do a 16 bit access(y/n)")
    assert((is16bit == "y") or (is16bit == "n"), "Must specify 'y' or 'n'")
    local hopcount = menu.prompt_number("Hop count")
    assert((hopcount >= 0) and (hopcount < 256), "Illegal hop count")
    local register = menu.prompt_number("Register address")
    assert((register >= 0), "Illegal register")

    if is16bit == "y" then
        is16bit = 1
    else
        is16bit = 0
    end

    local result = octeon.c.bdk_srio_config_read32(srio_port, 0, devid, is16bit, hopcount, register)
    assert(result ~= -1, "Maintenance read failed")
    printf("0x%x\n", result);
end

local function do_maintwrite(srio_port)
    local devid = menu.prompt_number("Device ID")
    assert((devid >= -1) and (devid < 65536), "Illegal device ID")
    local is16bit = menu.prompt_string("Do a 16 bit access(y/n)")
    assert((is16bit == "y") or (is16bit == "n"), "Must specify 'y' or 'n'")
    local hopcount = menu.prompt_number("Hop count")
    assert((hopcount >= 0) and (hopcount < 256), "Illegal hop count")
    local register = menu.prompt_number("Register address")
    assert((register >= 0), "Illegal register")
    local value = menu.prompt_number("Write value")

    if is16bit == "y" then
        is16bit = 1
    else
        is16bit = 0
    end

    local result = octeon.c.bdk_srio_config_write32(srio_port, 0, devid, is16bit, hopcount, register, value)
    assert(result == 0, "Maintenance write failed")
end

local function do_doorbell_tx(srio_port)
    local devid = menu.prompt_number("Device ID")
    assert((devid >= -1) and (devid < 65536), "Illegal device ID")
    local is16bit = menu.prompt_string("Do a 16 bit access(y/n)")
    assert((is16bit == "y") or (is16bit == "n"), "Must specify 'y' or 'n'")
    local priority = menu.prompt_number("Priority(0-3)")
    assert((priority >= 0) and (priority <= 3), "Illegal priority")
    local doorbell = menu.prompt_number("Doorbell Value")

    if is16bit == "y" then
        is16bit = 1
    else
        is16bit = 0
    end

    local result = octeon.c.bdk_srio_send_doorbell(srio_port, 0, devid, is16bit, priority, doorbell)
    assert(result == 0, "Doorbell send failed")
end

local function do_doorbell_rx(srio_port)
    local pending = octeon.csr.SRIOX_RX_BELL_SEQ(srio_port).decode()
    if pending.COUNT == 0 then
        printf("No doorbells received\n")
        return
    end

    while pending.COUNT > 0 do
        local doorbell = octeon.csr.SRIOX_RX_BELL(srio_port).decode()
        printf("Received doorbell:\n")
        printf("   Source ID:      %d\n", doorbell.SRC_ID)
        if doorbell.DEST_ID == 1 then
            printf("   Destination ID: Secondary\n")
        else
            printf("   Destination ID: Primary\n")
        end
        printf("   Data:           0x%x\n", doorbell.DATA)
        printf("   Priority:       %d\n", doorbell.PRIORITY)
        if doorbell.ID16 == 1 then
            printf("   Type:           16 bit\n")
        else
            printf("   Type:           8 bit\n")
        end
        printf("   Sequence #:     %d\n", pending.SEQ)
        pending = octeon.csr.SRIOX_RX_BELL_SEQ(srio_port).decode()
    end
end

local function srio_submenu(srio_port)
    local prefix = "SRIO" .. srio_port
    local m = menu.new("SRIO Menu - Port " .. srio_port)
    m:item("init", prefix .. ": Initialize", do_initialize, srio_port)
    m:item("scan", prefix .. ": Scan for devices", do_scan, srio_port)
    m:item("enum", prefix .. ": Enumerate devices", do_enumerate, srio_port)
    m:item("show", prefix .. ": Display devices", do_display, srio_port)
    m:item("mread", prefix .. ": Perform a maintenance read", do_maintread, srio_port)
    m:item("mwrite", prefix .. ": Perform a maintenance write", do_maintwrite, srio_port)
    m:item("sdb", prefix .. ": Send a doorbell", do_doorbell_tx, srio_port)
    m:item("rdb", prefix .. ": Receive a doorbell", do_doorbell_rx, srio_port)
    m:item("read", prefix .. ": Perform a memory read", not_implemented, srio_port)
    m:item("write", prefix .. ": Perform a memory write", not_implemented, srio_port)
    m:item("quit", "Main menu")

    while (m:show() ~= "quit") do
    -- Spinning on menu
    end
end

local m = menu.new("SRIO Menu")

local function toggle_debug()
    srio.debug = not srio.debug
    m:item("debug", "Toggle extra debug output. Currently %s" % (srio.debug and "ON" or "OFF"), toggle_debug)
end

local function toggle_debug_maint()
    srio.debug_maint = not srio.debug_maint
    m:item("debug_maint", "Toggle logging of maintenance. Currently %s" % (srio.debug_maint and "ON" or "OFF"), toggle_debug_maint)
end

-- Build a list of SRIO ports
local srio_ports = 0
if octeon.is_model(octeon.CN63XX) then
    srio_ports = 2
elseif octeon.is_model(octeon.CN66XX) then
    srio_ports = 4
end
for port = 0, srio_ports-1 do
    m:item("port" .. port, "SRIO port " .. port, srio_submenu, port)
end
m:item("debug", "Toggle extra debug output. Currently %s" % (srio.debug and "ON" or "OFF"), toggle_debug)
m:item("debug_maint", "Toggle logging of maintenance. Currently %s" % (srio.debug_maint and "ON" or "OFF"), toggle_debug_maint)
m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


