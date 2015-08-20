-- Configure the BDK for a ebb8800 board.
print("Configuring for the EBB8800")

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

if cavium.is_altpkg(cavium.CN88XX) then
    -- BGX0 (QLM0)
    set_config(cavium.CONFIG_PHY_IF0_PORT0, 0xff000108)
    set_config(cavium.CONFIG_PHY_IF0_PORT1, 0xff000109)
    set_config(cavium.CONFIG_PHY_IF0_PORT2, 0xff00010a)
    set_config(cavium.CONFIG_PHY_IF0_PORT3, 0xff00010b)
    -- BGX1 (QLM1)
    set_config(cavium.CONFIG_PHY_IF1_PORT0, 0xff00010c)
    set_config(cavium.CONFIG_PHY_IF1_PORT1, 0xff00010d)
    set_config(cavium.CONFIG_PHY_IF1_PORT2, 0xff00010e)
    set_config(cavium.CONFIG_PHY_IF1_PORT3, 0xff00010f)
else
    -- BGX0 (QLM0)
    set_config(cavium.CONFIG_PHY_IF0_PORT0, 0xff000000)
    set_config(cavium.CONFIG_PHY_IF0_PORT1, 0xff000001)
    set_config(cavium.CONFIG_PHY_IF0_PORT2, 0xff000002)
    set_config(cavium.CONFIG_PHY_IF0_PORT3, 0xff000003)
    -- BGX1 (QLM1)
    set_config(cavium.CONFIG_PHY_IF1_PORT0, 0xff000104)
    set_config(cavium.CONFIG_PHY_IF1_PORT1, 0xff000105)
    set_config(cavium.CONFIG_PHY_IF1_PORT2, 0xff000106)
    set_config(cavium.CONFIG_PHY_IF1_PORT3, 0xff000107)
end

cavium.c.bdk_qlm_auto_config(cavium.MASTER_NODE)

