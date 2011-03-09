
print("Configuring for the EBB6800")

local set_config = octeon.c.bdk_config_set

-- Mgmt port PHY address
set_config(octeon.CONFIG_PHY_MGMT_PORT0, 4)

-- Figure out the offsets needed for octeon.c.bdk_config_set
local if_base = octeon.CONFIG_PHY_IF0_PORT0
local if_inc = octeon.CONFIG_PHY_IF1_PORT0 - octeon.CONFIG_PHY_IF0_PORT0

-- Loop through the possible GMX interfaces
for gmx = 0,4 do
    -- We're set a PHY address for four ports on every interface
    -- Note that GMX1 can only have one RXAUI, so the extra three
    -- are never used
    for port = 0,3 do
        local phy_address = gmx * 0x100 + port + 1
        set_config(if_base + if_inc*gmx + port, phy_address)
    end
end

