-- BDK Configuration menu.
-- Displays the GUI interface for configuring the BDK.
require("strict")
require("utils")
require("menu")

local m = menu.new("Configuration Menu")

local configPrompt -- This is needed so variable is defined in addMenu

-- Add/update an option in the menu. The current value is attached to the
-- menu text
local function addMenu(description, config_item, min_value, max_value)
    local v = octeon.c.bdk_config_get(config_item)
    local menu_text = "%s (0x%x)" % {description, v}
    m:item("item" .. config_item, menu_text, configPrompt, description, config_item, min_value, max_value)
end

-- Function that is run when a menu item is selected
configPrompt = function(description, config_item, min_value, max_value)
    local oldv = octeon.c.bdk_config_get(config_item)
    local v = menu.prompt_number(description, oldv, min_value, max_value)
    octeon.c.bdk_config_set(config_item, v)
    addMenu(description, config_item, min_value, max_value)
end


local promptPhy -- This is needed so variable is defined in addPhyMenu

local function addPhyMenu(port_name, config_item)
    local v = octeon.c.bdk_config_get(config_item)
    local text
    if v == -1 then
        text = "PHY not present"
    elseif v == 0x1000 then
        text = "PHY fixed at 1Gbps, full duplex"
    elseif v == 0x1001 then
        text = "PHY fixed at 100Mbps, full duplex"
    else
        text = "PHY on SMI/MDIO bus %d, address %d" % {v/256, v % 256}
    end
    local menu_text = "%s - %s" % {port_name, text}
    m:item("item" .. config_item, menu_text, promptPhy, port_name, config_item)
end

promptPhy = function(port_name, config_item)
    local phy_addr
    local has_phy = menu.prompt_yes_no("Does %s have a PHY" % port_name)
    if has_phy then
        local has_mdio = menu.prompt_yes_no("Does the PHY connect to OCTEON's SMI/MDIO")
        if has_mdio then
            local bus = menu.prompt_number("SMI/MDIO bus", nil, 0, 3)
            local address = menu.prompt_number("PHY address on bus", nil, 0, 63)
            phy_addr = bus * 256 + address
        else
            local t = menu.prompt_yes_no("Is PHY at 1Gbps")
            if t then
                phy_addr = 0x1000
                print("Setting PHY up for 1Gbps, full duplex")
            else
                phy_addr = 0x1001
                print("Setting PHY up for 100Mbps, full duplex")
            end
        end
    else
        phy_addr = -1
    end
    octeon.c.bdk_config_set(config_item, phy_addr)
    addPhyMenu(port_name, config_item)
end

addMenu("MAC address", octeon.CONFIG_MAC_ADDRESS)

-- Add an item for each MGMT port
local if_mgmt = 6
for port = 0,octeon.c.bdk_if_num_ports(if_mgmt, 0)-1 do
    addPhyMenu("RGMII/MII port " .. port, octeon.CONFIG_PHY_MGMT_PORT0 + port)
end

-- Add an item for each SGMII port
local if_sgmii = 0
for interface = 0,octeon.c.bdk_if_num_interfaces(if_sgmii)-1 do
    for port = 0, octeon.c.bdk_if_num_ports(if_sgmii, interface)-1 do
        addPhyMenu("SGMII interface " .. interface .. ", port " .. port, octeon.CONFIG_PHY_IF0_PORT0 + interface*4 + port)
    end
end

-- Add an item for each XAUI port
local if_xaui = 1
for interface = 0,octeon.c.bdk_if_num_interfaces(if_xaui)-1 do
    if octeon.c.bdk_if_num_ports(if_xaui, interface) > 0 then
        addMenu("XAUI interface " .. interface .. " Higig mode, 0=XAUI,1=Higig(+),2=Higig2", octeon.CONFIG_HIGIG_MODE_IF0 + interface, 0, 2)
    end
end

-- Add an item for each ILK port
local if_ilk = 7
for interface = 0,octeon.c.bdk_if_num_interfaces(if_ilk)-1 do
    addMenu("Interlaken port " .. interface .. " lanes", octeon.CONFIG_ILK0_LANES + interface, 0, 8)
    addMenu("Interlaken port " .. interface .. " channels", octeon.CONFIG_ILK0_PORTS + interface, 1, 64)
end

m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end
