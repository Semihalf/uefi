
local set_config = octeon.c.bdk_config_set

set_config(13, 4) -- Mgmt port 0 PHY address
set_config(14, 5) -- Mgmt port 1 PHY address
set_config(15, 256 + 1) -- SGMII port 0 PHY address
set_config(16, 256 + 2) -- SGMII port 1 PHY address
set_config(17, 256 + 3) -- SGMII port 2 PHY address
set_config(18, 256 + 4) -- SGMII port 3 PHY address

