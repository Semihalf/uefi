-- BDK Configuration menu.
-- Displays the GUI interface for configuring the BDK.
require("strict")
require("utils")
require("menu")

local m = menu.new("Configuration Menu")

local configPrompt -- This is needed so variable is defined in addMenu

-- Add/update an option in the menu. The current value is attached to the
-- menu text
local function addMenuKey(key, description, config_item, min_value, max_value)
    local v = cavium.c.bdk_config_get(config_item)
    local menu_text = "%s (0x%x)" % {description, v}
    m:item(key, menu_text, configPrompt, key, description, config_item, min_value, max_value)
end

local function addMenu(description, config_item, min_value, max_value)
    local key = "item" .. config_item
    addMenuKey(key, description, config_item, min_value, max_value)
end

-- Function that is run when a menu item is selected
configPrompt = function(key, description, config_item, min_value, max_value)
    local oldv = cavium.c.bdk_config_get(config_item)
    local v = menu.prompt_number(description, oldv, min_value, max_value)
    cavium.c.bdk_config_set(config_item, v)
    addMenuKey(key, description, config_item, min_value, max_value)
end


local promptPhy -- This is needed so variable is defined in addPhyMenu

local function addPhyMenu(port_name, config_item)
    local v = cavium.c.bdk_config_get(config_item)
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
        local has_mdio = menu.prompt_yes_no("Does the PHY connect to THUNDERX's SMI/MDIO")
        if has_mdio then
            local bus = menu.prompt_number("SMI/MDIO bus", nil, 0, 1)
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
    cavium.c.bdk_config_set(config_item, phy_addr)
    addPhyMenu(port_name, config_item)
end

addMenu("MAC address", cavium.CONFIG_MAC_ADDRESS)
addMenuKey("coremask", "Good Coremask", cavium.CONFIG_COREMASK)

local node = cavium.MASTER_NODE

-- Add an item for each BGX port
local if_bgx = cavium.IF_BGX
for interface = 0,cavium.c.bdk_if_num_interfaces(node, if_bgx)-1 do
    local num_ports = cavium.c.bdk_if_num_ports(node, if_bgx, interface)
    for port = 0, num_ports-1 do
        addPhyMenu("BGX interface " .. interface .. ", port " .. port, cavium.CONFIG_PHY_IF0_PORT0 + interface*4 + port)
    end
end

-- Allow the user to enable/disable link status message
addMenu("Show link status messages", cavium.CONFIG_SHOW_LINK_STATUS, 0, 1)

m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end
