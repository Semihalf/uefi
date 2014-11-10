-- Configure the BDK for a ebb8800 board.
print("Configuring for the EBB8800")

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
set_config(cavium.CONFIG_PHY_IF1_PORT0, 0x104)
set_config(cavium.CONFIG_PHY_IF1_PORT1, 0x105)
set_config(cavium.CONFIG_PHY_IF1_PORT2, 0x106)
set_config(cavium.CONFIG_PHY_IF1_PORT3, 0x107)

--------------------------------------------------------------
-- Configuring QLMs in Lua code
--------------------------------------------------------------
-- The QLMs can be configured here to make the BDK automatically
-- setup a configuration on boot. The comments below list the
-- possibilities. Remember to specify which reference clock is
-- configured for the QLM on the board.

-- local node = cavium.MASTER_NODE
-- local qlm = 0

--------------------------------------------------------------
-- Choosing reference clocks (QLMs 0-7)
--------------------------------------------------------------
-- External reference clock
-- cavium.csr.GSERX_REFCLK_SEL(qlm).COM_CLK_SEL = 0
-- cavium.csr.GSERX_REFCLK_SEL(qlm).USE_COM1 = 0

-- Common clock 0
-- cavium.csr.GSERX_REFCLK_SEL(qlm).COM_CLK_SEL = 1
-- cavium.csr.GSERX_REFCLK_SEL(qlm).USE_COM1 = 0

-- Common clock 1
-- cavium.csr.GSERX_REFCLK_SEL(qlm).COM_CLK_SEL = 1
-- cavium.csr.GSERX_REFCLK_SEL(qlm).USE_COM1 = 1

--------------------------------------------------------------
-- Choosing QLM modes for BGX (QLMs 0-1)
--------------------------------------------------------------
-- SGMII modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_SGMII, 1250, 0)

-- *XAUI modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_XAUI_1X4, 3125, 0)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_XAUI_1X4, 6250, 0)

-- XFI modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_XFI_4X1, 10321, 0)

-- XLAUI modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_XLAUI_1X4, 10321, 0)

-- 10GBASE-KR modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_10G_KR_4X1, 10321, 0)

-- 40GBASE-KR modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_40G_KR4_1X4, 10321, 0)

--------------------------------------------------------------
-- Choosing QLM modes for SATA (QLMs 2-3, 6-7)
--------------------------------------------------------------
-- SATA modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_SATA_4X1, 5000, 0)

--------------------------------------------------------------
-- Choosing QLM modes for PCIe (QLMs 2-7)
--------------------------------------------------------------
-- PCIe x4 modes (QLMs 2-7)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_PCIE_1X4, 2500, cavium.QLM_MODE_FLAG_GEN1)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_PCIE_1X4, 5000, cavium.QLM_MODE_FLAG_GEN2)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_PCIE_1X4, 8000, cavium.QLM_MODE_FLAG_GEN3)

-- PCIe x8 modes (QLMs 2&3, 4&5, 6&7)
-- Only call for the first QLM of the pair
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_PCIE_1X8, 2500, cavium.QLM_MODE_FLAG_GEN1)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_PCIE_1X8, 5000, cavium.QLM_MODE_FLAG_GEN2)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_PCIE_1X8, 8000, cavium.QLM_MODE_FLAG_GEN3)

-- End of QLM examples

local node = cavium.MASTER_NODE
if false then
--if cavium.c.bdk_qlm_get_mode(node, 0) == cavium.QLM_MODE_DISABLED then
    -- Only apply the sample config if QLM0 isn't already setup
    printf("Configuring QLMs for a sample setup\n");
    cavium.c.bdk_qlm_set_mode(node, 0, cavium.QLM_MODE_SGMII, 1250, 0)
    cavium.c.bdk_qlm_set_mode(node, 1, cavium.QLM_MODE_XAUI_1X4, 6250, 0)
    cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X8, 8000, cavium.QLM_MODE_FLAG_GEN3)
    cavium.c.bdk_qlm_set_mode(node, 4, cavium.QLM_MODE_PCIE_1X4, 5000, cavium.QLM_MODE_FLAG_GEN2)
    cavium.c.bdk_qlm_set_mode(node, 5, cavium.QLM_MODE_PCIE_1X4, 2500, cavium.QLM_MODE_FLAG_GEN1)
    cavium.c.bdk_qlm_set_mode(node, 6, cavium.QLM_MODE_SATA_4X1, 5000, 0)
    cavium.c.bdk_qlm_set_mode(node, 7, cavium.QLM_MODE_SATA_4X1, 2500, 0)
end

