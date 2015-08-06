-- Configure the BDK for a ebb880x board.
print("Configuring for the EBB880X")

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
-- BGX1 (QLM3)
set_config(cavium.CONFIG_PHY_IF1_PORT0, 0xff000104)
set_config(cavium.CONFIG_PHY_IF1_PORT1, 0xff000105)
set_config(cavium.CONFIG_PHY_IF1_PORT2, 0xff000106)
set_config(cavium.CONFIG_PHY_IF1_PORT3, 0xff000107)
-- BGX2 (DLM5-6)
set_config(cavium.CONFIG_PHY_IF2_PORT0, 0xff000204)
set_config(cavium.CONFIG_PHY_IF2_PORT1, 0xff000205)
set_config(cavium.CONFIG_PHY_IF2_PORT2, 0xff000206)
set_config(cavium.CONFIG_PHY_IF2_PORT3, 0xff000207)
-- BGX3 (DLM4)
set_config(cavium.CONFIG_PHY_IF3_PORT0, 0xff000304)
set_config(cavium.CONFIG_PHY_IF3_PORT1, 0xff000305)

if not cavium.is_platform(cavium.PLATFORM_EMULATOR) then
    cavium.c.bdk_qlm_auto_config(cavium.MASTER_NODE)
end

