-- Configure the BDK for a ebb7100 board.
print("Configuring for the EBB7100")

local set_config = octeon.c.bdk_config_set

set_config(octeon.CONFIG_PHY_IF0_PORT0, 256 + 1) -- QLM0 SGMII port 0 PHY address
set_config(octeon.CONFIG_PHY_IF0_PORT1, 256 + 2) -- QLM0 SGMII port 1 PHY address

