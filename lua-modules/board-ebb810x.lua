-- Configure the BDK for a ebb810x board.
print("Configuring for the EBB810X")

local set_config = cavium.c.bdk_config_set

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
set_config(cavium.CONFIG_PHY_IF0_PORT0, 0xff000000)
set_config(cavium.CONFIG_PHY_IF0_PORT1, 0xff000001)
set_config(cavium.CONFIG_PHY_IF0_PORT2, 0xff000002)
set_config(cavium.CONFIG_PHY_IF0_PORT3, 0xff000003)
-- RGMII
set_config(cavium.CONFIG_PHY_IF1_PORT0, 0xff000104)

cavium.c.bdk_qlm_auto_config(cavium.MASTER_NODE)

