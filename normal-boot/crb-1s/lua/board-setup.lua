-- Configure the BDK for a crb_1s board.
print("Configuring for the CN88XX-CRB-1S")

local set_config = cavium.c.bdk_config_set

--------------------------------------------------------------
-- Configuring PHY addresses for various BGX interfaces
--------------------------------------------------------------
-- This code sets the default MDIO addresses for SGMII PHYs
-- The number is "(0x100 * bus) + phy".

-- BGX0 (QLM0) is QSFP on MDIO bus 1, address 1
set_config(cavium.CONFIG_PHY_IF0_PORT0, 0x101)
-- BGX1 (QLM1) is SFP on MDIO bus 1, address 0
set_config(cavium.CONFIG_PHY_IF1_PORT0, 0x100)
set_config(cavium.CONFIG_PHY_IF1_PORT1, 0x100)

-- Report boot OK to BMC
cavium.csr.MIO_TWSX_SW_TWSI(5).data = 0x80
cavium.csr.MIO_TWSX_SW_TWSI(5).v = 1
