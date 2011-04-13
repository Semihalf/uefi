
-- BDK Configuration menu

require("strict")
require("utils")
require("menu")

local m = menu.new("Configuration Menu")

local configPrompt -- This is needed so variable is defined in addMenu

-- Add/update an option in the menu. The current value is attached to the
-- menu text
local function addMenu(description, config_item)
    local v = octeon.c.bdk_config_get(config_item)
    local menu_text = "%s (0x%x)" % {description, v}
    m:item("item" .. config_item, menu_text, configPrompt, description, config_item)
end

-- Function that is run when a menu item is selected
configPrompt = function(description, config_item)
    local v = menu.prompt_number(description)
    octeon.c.bdk_config_set(config_item, v)
    addMenu(description, config_item)
end

addMenu("MAC address", octeon.CONFIG_MAC_ADDRESS)

-- Add an item for each MGMT port
for interface = 0,octeon.c.bdk_if_num_interfaces(5)-1 do
    addMenu("RGMII/MII port " .. interface .. " PHY address", octeon.CONFIG_PHY_MGMT_PORT0 + interface)
end

-- Add an item for each SGMII port
for interface = 0,octeon.c.bdk_if_num_interfaces(0)-1 do
    for port = 0, octeon.c.bdk_if_num_ports(0, interface)-1 do
        addMenu("SGMII interface " .. interface .. ", port " .. port .. " PHY address", octeon.CONFIG_PHY_IF0_PORT0 + interface*4 + port)
    end
end

-- Add an item for each ILK port
for interface = 0,octeon.c.bdk_if_num_interfaces(6)-1 do
    addMenu("Interlaken port " .. interface .. " lanes", octeon.CONFIG_ILK0_LANES + interface)
    addMenu("Interlaken port " .. interface .. " channels", octeon.CONFIG_ILK0_PORTS + interface)
end

m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end
