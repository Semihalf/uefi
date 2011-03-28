
print("Configuring for the EBB6800")

local set_config = octeon.c.bdk_config_set

-- Mgmt port PHY address
--set_config(octeon.CONFIG_PHY_MGMT_PORT0, 4)

-- This is SGMII on QLM2
set_config(octeon.CONFIG_PHY_IF2_PORT0, 0x200 + 1)
set_config(octeon.CONFIG_PHY_IF2_PORT1, 0x200 + 2)
set_config(octeon.CONFIG_PHY_IF2_PORT2, 0x200 + 3)
set_config(octeon.CONFIG_PHY_IF2_PORT3, 0x200 + 4)

-- This is SGMII on QLM3
set_config(octeon.CONFIG_PHY_IF3_PORT0, 0x300 + 1)
set_config(octeon.CONFIG_PHY_IF3_PORT1, 0x300 + 2)
set_config(octeon.CONFIG_PHY_IF3_PORT2, 0x300 + 3)
set_config(octeon.CONFIG_PHY_IF3_PORT3, 0x300 + 4)

