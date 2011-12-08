-- Configure the BDK for a ebb6100 board.
print("Configuring for the EBB6100")

local set_config = octeon.c.bdk_config_set

set_config(octeon.CONFIG_PHY_MGMT_PORT0, 4) -- Mgmt port 0 PHY address
set_config(octeon.CONFIG_PHY_MGMT_PORT1, 5) -- Mgmt port 1 PHY address

-- SGMII PHYs are behind a MDIO switch controlled by GPIO 3
-- Configure GPIO 3 as an output high, using QLM2
octeon.c.bdk_gpio_initialize(3, true, 1)

-- GPIO 3 high selects the PHYs on QLM2, which is GMX0
set_config(octeon.CONFIG_PHY_IF0_PORT0, 256 + 1) -- QLM2 SGMII port 0 PHY address
set_config(octeon.CONFIG_PHY_IF0_PORT1, 256 + 2) -- QLM2 SGMII port 1 PHY address
set_config(octeon.CONFIG_PHY_IF0_PORT2, 256 + 3) -- QLM2 SGMII port 2 PHY address
set_config(octeon.CONFIG_PHY_IF0_PORT3, 256 + 4) -- QLM2 SGMII port 3 PHY address

-- GPIO 3 low selects the PHYs on QLM0, which is GMX1
set_config(octeon.CONFIG_PHY_IF1_PORT0, 256 + 1) -- QLM0 SGMII port 0 PHY address
set_config(octeon.CONFIG_PHY_IF1_PORT1, 256 + 2) -- QLM0 SGMII port 1 PHY address
set_config(octeon.CONFIG_PHY_IF1_PORT2, 256 + 3) -- QLM0 SGMII port 2 PHY address
set_config(octeon.CONFIG_PHY_IF1_PORT3, 256 + 4) -- QLM0 SGMII port 3 PHY address

