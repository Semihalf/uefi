-- Configure the BDK for a crb_1s board.
print("Configuring for the CN88XX-CRB-1S")

local set_config = cavium.c.bdk_config_set

--------------------------------------------------------------
-- Configuring PHY addresses for various BGX interfaces
--------------------------------------------------------------
-- This code sets the default MDIO addresses for SGMII PHYs
-- The number is "(0x100 * bus) + phy".

-- BGX0 (QLM0)
set_config(cavium.CONFIG_PHY_IF0_PORT0, 0)
set_config(cavium.CONFIG_PHY_IF0_PORT1, 1)
set_config(cavium.CONFIG_PHY_IF0_PORT2, 2)
set_config(cavium.CONFIG_PHY_IF0_PORT3, 3)
-- BGX1 (QLM1)
set_config(cavium.CONFIG_PHY_IF1_PORT0, 4)
set_config(cavium.CONFIG_PHY_IF1_PORT1, 5)
set_config(cavium.CONFIG_PHY_IF1_PORT2, 6)
set_config(cavium.CONFIG_PHY_IF1_PORT3, 7)

