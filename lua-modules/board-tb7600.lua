-- Configure the BDK for a TB7600 board.
print("Configuring for the TB7600")

local set_config = octeon.c.bdk_config_set

--------------------------------------------------------------
-- Configuring PHY addresses for various BGX interfaces
--------------------------------------------------------------
-- This code sets the default MDIO addresses for SGMII PHYs. There are four such PHYs
-- per BGX interface. The three BGX interfaces connect to QLMs 2, 3, and 4. A single
-- SMI/MDIO bus (bus #1) covers all three QLMs. The PHY addresses on the MDIO bus
-- cover the range 8 through 19.
--
-- The number is "(0x100 * bus) + phy".

-- BGX0 (QLM2, covered by SMI/MDIO bus #1)
print("Configuring BGX0 (SMI1)")
set_config(octeon.CONFIG_PHY_IF0_PORT0, 0x100 + 8)
set_config(octeon.CONFIG_PHY_IF0_PORT1, 0x100 + 9)
set_config(octeon.CONFIG_PHY_IF0_PORT2, 0x100 + 10)
set_config(octeon.CONFIG_PHY_IF0_PORT3, 0x100 + 11)

-- BGX1 (QLM3, covered by SMI/MDIO bus #1))
print("Configuring BGX1 (SMI1)")
set_config(octeon.CONFIG_PHY_IF1_PORT0, 0x100 + 12)
set_config(octeon.CONFIG_PHY_IF1_PORT1, 0x100 + 13)
set_config(octeon.CONFIG_PHY_IF1_PORT2, 0x100 + 14)
set_config(octeon.CONFIG_PHY_IF1_PORT3, 0x100 + 15)

-- BGX2 (QLM4, covered by SMI/MDIO bus #1))
print("Configuring BGX2 (SMI1)")
set_config(octeon.CONFIG_PHY_IF2_PORT0, 0x100 + 16)
set_config(octeon.CONFIG_PHY_IF2_PORT1, 0x100 + 17)
set_config(octeon.CONFIG_PHY_IF2_PORT2, 0x100 + 18)
set_config(octeon.CONFIG_PHY_IF2_PORT3, 0x100 + 19)

-- For RXAUI, We're using a Marvel PHY on the plugin modules. The code below
-- programs all BGXs to use "Interleaved running disparity", which is required
-- for these PHYs. This will need to be changed if PHYs are used that expect
-- "Common running disparity".
for bgx=0,2 do
    for i=0,1 do
        octeon.csr.BGXX_SPUX_MISC_CONTROL(bgx,i).intlv_rdisp = 1
    end
end
