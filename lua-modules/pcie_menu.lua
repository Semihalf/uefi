-- BDK PCIe menu.
-- Displays the GUI interface for accessing PCIe.
require("strict")
require("utils")
require("menu")
require("fileio")
local pcie = require("pcie")
local bit64 = require("bit64")

local pcie_root = {}
local default_node = cavium.MASTER_NODE

--
-- PCIe host mode functions
--

local function do_initialize(pcie_port)
    pcie_root[pcie_port] = pcie.initialize(default_node, pcie_port)
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

--
-- EEPROM Functions
--

local function do_eeprom_dump(pcie_port)
    for offset=0,512-8,8 do
        local data = cavium.c.bdk_pcie_eeprom_read(default_node, pcie_port, offset)
        printf("0x%03x: 0x%016x", offset, data)
        local preamble = bit64.bextract(data, 48, 63)
        if preamble ~= 0x9da1 then
            break
        end
    end
end

local function do_eeprom_edit(pcie_port)
    assert(false, "Not implemented")
end

local function do_eeprom_write(pcie_port)
    local offset = menu.prompt_number("Offset into EEPROM", 0, 0, 512-8)
    local data = menu.prompt_number("EEPROM value")
    assert(cavium.c.bdk_pcie_eeprom_write(default_node, pcie_port, offset, data) == 0, "EEPROM write failed")
end

local function do_eeprom_menu(pcie_port)
    local m = menu.new("PCIe" .. pcie_port .." Menu")
    local prefix = "PCIe" .. pcie_port
    m:item("dump", prefix .. ": Display current EEPROM", do_eeprom_dump, pcie_port)
    m:item("edit", prefix .. ": Change a config register", do_eeprom_edit, pcie_port)
    m:item("write", prefix .. ": Perform a raw write", do_eeprom_write, pcie_port)
    m:item("quit", "Main menu")
    while (m:show() ~= "quit") do
        -- Spinning on menu
    end
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
    m:item("eeprom", prefix .. ": Access EEPROM", do_eeprom_menu, pcie_port)
    m:item("quit", "Main menu")
    while (m:show() ~= "quit") do
        -- Spinning on menu
    end
end

--
-- PCIe main menu
--

local m = menu.new("PCIe Menu")
local max_ports = cavium.c.bdk_pcie_get_num_ports(default_node)
for pcie_port=0,max_ports-1 do
    m:item("p" .. pcie_port, "PCIe port " .. pcie_port, do_port_menu, pcie_port)
end

m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end
