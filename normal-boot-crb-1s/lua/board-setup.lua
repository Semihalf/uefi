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

local node = cavium.MASTER_NODE

printf("QLM0-1: Using common clock 1 (156.25Mhz)\n")
printf("QLM2-7: Using common clock 0 (100.00Mhz)\n")
for qlm=0,7 do
    cavium.csr[node].GSERX_REFCLK_SEL(qlm).COM_CLK_SEL = 1
    cavium.csr[node].GSERX_REFCLK_SEL(qlm).USE_COM1 = (qlm < 2) and 1 or 0
end
cavium.c.bdk_qlm_set_mode(node, 0, cavium.QLM_MODE_XLAUI_1X4, 10321, 0)
cavium.c.bdk_qlm_set_mode(node, 1, cavium.QLM_MODE_XFI_4X1, 10321, 0)
cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X4, 8000, cavium.QLM_MODE_FLAG_GEN3)
cavium.c.bdk_qlm_set_mode(node, 3, cavium.QLM_MODE_SATA_4X1, 6000, 0)
cavium.c.bdk_qlm_set_mode(node, 4, cavium.QLM_MODE_PCIE_1X8, 8000, cavium.QLM_MODE_FLAG_GEN3)
cavium.c.bdk_qlm_set_mode(node, 6, cavium.QLM_MODE_PCIE_1X8, 8000, cavium.QLM_MODE_FLAG_GEN3)

