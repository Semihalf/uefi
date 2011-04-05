
-- BDK DDR menu

require("strict")
require("utils")
require("menu")

local function smi_scan(smi_bus)
    printf("SMI%d: Scanning bus...\n", smi_bus)
    for dev_addr = 0, 31 do
        local data = octeon.c.bdk_mdio_read(smi_bus, dev_addr, 0)
        if (data > 0) and (data ~= 0xffff) then
            printf("SMI%d: Address %3d (0x%02x) responded with 0x%04x\n", smi_bus, dev_addr, dev_addr, data)
        end
    end
end

local function smi_read(smi_bus)
    local dev_addr = menu.prompt_number("Device address")
    local reg = menu.prompt_number("Device register")
    local data = octeon.c.bdk_mdio_read(smi_bus, dev_addr, reg)
    printf("SMI%d: Address %3d (0x%02x) reg %d (0x%x) responded with 0x%04x\n",
        smi_bus, dev_addr, dev_addr, reg, reg, data)
end

local function smi_write(smi_bus)
    local dev_addr = menu.prompt_number("Device address")
    local reg = menu.prompt_number("Device register")
    local data = menu.prompt_number("Data")
    octeon.c.bdk_mdio_write(smi_bus, dev_addr, reg, data)
end

local function smi_submenu(smi_bus)
    local m = menu.new("SMI/MDIO Menu - Bus " .. smi_bus)
    m:item("scan", "Scan bus", smi_scan, smi_bus)
    m:item("read", "Read a register", smi_read, smi_bus)
    m:item("write", "Write a register", smi_write, smi_bus)
    m:item("quit", "Main menu")

    while (m:show() ~= "quit") do
    -- Spinning on menu
    end
end


local m = menu.new("SMI/MDIO Menu")

-- Build a list of smi busses
local smi_busses = 2
if octeon.is_model(octeon.CN68XX) then
    smi_busses = 4
end
for bus = 0, smi_busses-1 do
    m:item("bus" .. bus, "SMI/MDIO bus " .. bus, smi_submenu, bus)
end
m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


