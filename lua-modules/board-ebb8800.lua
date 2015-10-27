-- Configure the BDK for a ebb8800 board.
print("Configuring for the EBB8800")

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

if cavium.is_altpkg(cavium.CN88XX) then
    -- BGX0 (QLM0)
    set_config(0xff000108, cavium.CONFIG_PHY_IF0_PORT0)
    set_config(0xff000109, cavium.CONFIG_PHY_IF0_PORT1)
    set_config(0xff00010a, cavium.CONFIG_PHY_IF0_PORT2)
    set_config(0xff00010b, cavium.CONFIG_PHY_IF0_PORT3)
    -- BGX1 (QLM1)
    set_config(0xff00010c, cavium.CONFIG_PHY_IF1_PORT0)
    set_config(0xff00010d, cavium.CONFIG_PHY_IF1_PORT1)
    set_config(0xff00010e, cavium.CONFIG_PHY_IF1_PORT2)
    set_config(0xff00010f, cavium.CONFIG_PHY_IF1_PORT3)
else
    -- BGX0 (QLM0)
    set_config(0xff000000, cavium.CONFIG_PHY_IF0_PORT0)
    set_config(0xff000001, cavium.CONFIG_PHY_IF0_PORT1)
    set_config(0xff000002, cavium.CONFIG_PHY_IF0_PORT2)
    set_config(0xff000003, cavium.CONFIG_PHY_IF0_PORT3)
    -- BGX1 (QLM1)
    set_config(0xff000104, cavium.CONFIG_PHY_IF1_PORT0)
    set_config(0xff000105, cavium.CONFIG_PHY_IF1_PORT1)
    set_config(0xff000106, cavium.CONFIG_PHY_IF1_PORT2)
    set_config(0xff000107, cavium.CONFIG_PHY_IF1_PORT3)
end

