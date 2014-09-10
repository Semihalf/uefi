-- BDK SMI/MDIO menu.
-- Displays the GUI interface for configuring and accessing SMI/MDIO.
require("strict")
require("utils")
require("menu")

local node = cavium.MASTER_NODE

local function smi_scan(smi_bus)
    printf("SMI%d: Scanning bus...\n", smi_bus)
    for dev_addr = 0, 31 do
        local data = cavium.c.bdk_mdio_read(node, smi_bus, dev_addr, 0)
        if (data > 0) and (data ~= 0xffff) then
            printf("SMI%d: Address %3d (0x%02x) responded with 0x%04x\n", smi_bus, dev_addr, dev_addr, data)
        end
    end
end

local function smi_read(smi_bus)
    local dev_addr = menu.prompt_number("Device address", nil, 0, 63)
    local reg = menu.prompt_number("Device register")
    local data = cavium.c.bdk_mdio_read(node, smi_bus, dev_addr, reg)
    assert(data ~= -1, "SMI/MDIO read failed")
    printf("SMI%d: Address %3d (0x%02x) reg %d (0x%x) responded with 0x%04x\n",
        smi_bus, dev_addr, dev_addr, reg, reg, data)
end

local function smi_write(smi_bus)
    local dev_addr = menu.prompt_number("Device address", nil, 0, 63)
    local reg = menu.prompt_number("Device register")
    local data = menu.prompt_number("Data")
    assert(cavium.c.bdk_mdio_write(node, smi_bus, dev_addr, reg, data) ~= -1, "SMI/MDIO write failed")
end

local function smi_read45(smi_bus)
    local phy_addr = menu.prompt_number("PHY address")
    local dev_addr = menu.prompt_number("Device address")
    local reg = menu.prompt_number("Device register")
    local data = cavium.c.bdk_mdio_45_read(node, smi_bus, phy_addr, dev_addr, reg)
    assert(data ~= -1, "SMI/MDIO read failed")
    printf("SMI%d: PHY Address %3d (0x%02x) Device Address %3d (0x%02x) reg %d (0x%x) responded with 0x%04x\n",
        smi_bus, phy_addr, phy_addr, dev_addr, dev_addr, reg, reg, data)
end

local function smi_write45(smi_bus)
    local phy_addr = menu.prompt_number("PHY address")
    local dev_addr = menu.prompt_number("Device address")
    local reg = menu.prompt_number("Device register")
    local data = menu.prompt_number("Data")
    assert(cavium.c.bdk_mdio_45_write(node, smi_bus, phy_addr, dev_addr, reg, data) ~= -1, "SMI/MDIO write failed")
end

local function smi_submenu(smi_bus)
    -- Enable the SMI/MDIO bus if it hasn't been enabled yet
    if cavium.csr.SMIX_EN(smi_bus).EN == 0 then
        cavium.csr.SMIX_EN(smi_bus).EN = 1
    end
    local m = menu.new("SMI/MDIO Menu - Bus " .. smi_bus)
    m:item("scan", "Scan bus (Clause 22)", smi_scan, smi_bus)
    m:item("read", "Read a register (Clause 22)", smi_read, smi_bus)
    m:item("write", "Write a register (Clause 22)", smi_write, smi_bus)
    m:item("read45", "Read a register (Clause 45)", smi_read45, smi_bus)
    m:item("write45", "Write a register (Clause 45)", smi_write45, smi_bus)
    m:item("quit", "Main menu")

    while (m:show() ~= "quit") do
    -- Spinning on menu
    end
end


local m = menu.new("SMI/MDIO Menu")

-- Build a list of smi busses
local smi_busses = 2
for bus = 0, smi_busses-1 do
    m:item("bus" .. bus, "SMI/MDIO bus " .. bus, smi_submenu, bus)
end
m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


