-- BDK PCIe menu.
-- Displays the GUI interface for accessing PCIe.
require("strict")
require("utils")
require("menu")
require("fileio")
local pcie = require("pcie")

local pcie_root = {}

local function do_initialize(pcie_port)
    local node = 0
    pcie_root[pcie_port] = pcie.initialize(node, pcie_port)
end

local function do_scan(pcie_port)
    assert(pcie_root[pcie_port], "PCIe" .. pcie_port .. " not initialized")
    pcie_root[pcie_port]:scan()
end

local function do_enumerate(pcie_port)
    assert(pcie_root[pcie_port], "PCIe" .. pcie_port .. " not initialized")
    pcie_root[pcie_port]:enumerate()
end

local function do_display(pcie_port)
    assert(pcie_root[pcie_port], "PCIe" .. pcie_port .. " not initialized")
    pcie_root[pcie_port]:display()
end

local function do_read(pcie_port)
    assert(pcie_root[pcie_port], "PCIe" .. pcie_port .. " not initialized")
    local address = menu.prompt_number("PCIe bus address")
    local length = menu.prompt_number("Number of bytes to read", nil, 1, 65536)
    local f = fileio.open("/dev/pcie/" .. pcie_port, "r", address)
    f:setvbuf("full", length)
    local data = f:read(length)
    f:close()
    printf("Data: ")
    for i=1, #data do
        printf("%02x", data:byte(i))
    end
    printf("\n")
end

local function do_write(pcie_port)
    assert(pcie_root[pcie_port], "PCIe" .. pcie_port .. " not initialized")
    local address = menu.prompt_number("PCIe bus address")
    local hex_data = menu.prompt_string("Data to write in hex")
    local data = ""
    for i=1,#hex_data,2 do
        local c = tonumber(hex_data:sub(i,i+1), 16)
        data = data .. string.char(c)
    end

    local f = fileio.open("/dev/pcie/" .. pcie_port, "w", address)
    f:setvbuf("full", #data)
    f:write(data)
    f:close()
end

local function do_shutdown(pcie_port)
    assert(pcie_root[pcie_port], "PCIe" .. pcie_port .. " not initialized")
    pcie_root[pcie_port]:shutdown()
    pcie_root[pcie_port] = nil
end

local function do_port_menu(pcie_port)
    local m = menu.new("PCIe" .. pcie_port .." Menu")
    local prefix = "PCIe" .. pcie_port
    m:item("init", prefix .. ": Initialize", do_initialize, pcie_port)
    m:item("scan", prefix .. ": Scan for devices", do_scan, pcie_port)
    m:item("enum", prefix .. ": Enumerate devices", do_enumerate, pcie_port)
    m:item("disp", prefix .. ": Display devices", do_display, pcie_port)
    m:item("read", prefix .. ": Perform a memory read", do_read, pcie_port)
    m:item("write", prefix .. ": Perform a memory write", do_write, pcie_port)
    m:item("shut", prefix .. ": Shutdown", do_shutdown, pcie_port)
    m:item("quit", "Main menu")
    while (m:show() ~= "quit") do
        -- Spinning on menu
    end
end

local m = menu.new("PCIe Menu")
local max_ports = 2
if octeon.is_model(octeon.CN78XX) then
    max_ports = 4
elseif octeon.is_model(octeon.CN70XX) then
    max_ports = 3
end

for pcie_port=0,max_ports-1 do
    m:item("p" .. pcie_port, "PCIe port " .. pcie_port, do_port_menu, pcie_port)
end

m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end
