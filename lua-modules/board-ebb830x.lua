-- Configure the BDK for a ebb830x board.
print("Configuring for the EBB830X")

local set_config = cavium.c.bdk_config_set_int

--------------------------------------------------------------
-- Configuring PHY addresses for various BGX interfaces
--------------------------------------------------------------
-- For MDIO:
--     Bits[31:24]: Node ID, 0xff for node the etherent device is on
--     Bits[23:16]: 0
--     Bits[15:12]: 0=MDIO
--     Bits[11:8]: MDIO bus number
--     Bits[7:0]: MDIO address

-- BGX0 (QLM2)
set_config(0xff000000, cavium.CONFIG_PHY_IF0_PORT0)
set_config(0xff000001, cavium.CONFIG_PHY_IF0_PORT1)
set_config(0xff000002, cavium.CONFIG_PHY_IF0_PORT2)
set_config(0xff000003, cavium.CONFIG_PHY_IF0_PORT3)
-- BGX1 (QLM3)
set_config(0xff000104, cavium.CONFIG_PHY_IF1_PORT0)
set_config(0xff000105, cavium.CONFIG_PHY_IF1_PORT1)
set_config(0xff000106, cavium.CONFIG_PHY_IF1_PORT2)
set_config(0xff000107, cavium.CONFIG_PHY_IF1_PORT3)
-- BGX2 (DLM5-6)
set_config(0xff000204, cavium.CONFIG_PHY_IF2_PORT0)
set_config(0xff000205, cavium.CONFIG_PHY_IF2_PORT1)
set_config(0xff000206, cavium.CONFIG_PHY_IF2_PORT2)
set_config(0xff000207, cavium.CONFIG_PHY_IF2_PORT3)
-- BGX3 (DLM4)
set_config(0xff000304, cavium.CONFIG_PHY_IF3_PORT0)
set_config(0xff000305, cavium.CONFIG_PHY_IF3_PORT1)

