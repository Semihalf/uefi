-- Configure the BDK for a ebb8800 board.
print("Configuring for the EBB8800")

local set_config = cavium.c.bdk_config_set

--------------------------------------------------------------
-- Configuring PHY addresses for various BGX interfaces
--------------------------------------------------------------
-- This code sets the default MDIO addresses for SGMII PHYs
-- The number is "(0x100 * bus) + phy". For the first etch
-- of the EBB7800, all PHYs are on MDIO bus 0 due to a board
-- workaround.

-- BGX0 (QLM0 or QLM2), we assume QLM0 here
set_config(cavium.CONFIG_PHY_IF0_PORT0, 0)
set_config(cavium.CONFIG_PHY_IF0_PORT1, 1)
set_config(cavium.CONFIG_PHY_IF0_PORT2, 2)
set_config(cavium.CONFIG_PHY_IF0_PORT3, 3)
-- BGX1 (QLM1 or QLM3), we assume QLM1 here
set_config(cavium.CONFIG_PHY_IF1_PORT0, 4)
set_config(cavium.CONFIG_PHY_IF1_PORT1, 5)
set_config(cavium.CONFIG_PHY_IF1_PORT2, 6)
set_config(cavium.CONFIG_PHY_IF1_PORT3, 7)
-- BGX2 (QLM4)
set_config(cavium.CONFIG_PHY_IF2_PORT0, 16)
set_config(cavium.CONFIG_PHY_IF2_PORT1, 17)
set_config(cavium.CONFIG_PHY_IF2_PORT2, 18)
set_config(cavium.CONFIG_PHY_IF2_PORT3, 19)
-- BGX3 (QLM5)
set_config(cavium.CONFIG_PHY_IF3_PORT0, 20)
set_config(cavium.CONFIG_PHY_IF3_PORT1, 21)
set_config(cavium.CONFIG_PHY_IF3_PORT2, 22)
set_config(cavium.CONFIG_PHY_IF3_PORT3, 23)
-- BGX4 (QLM6)
set_config(cavium.CONFIG_PHY_IF4_PORT0, 24)
set_config(cavium.CONFIG_PHY_IF4_PORT1, 25)
set_config(cavium.CONFIG_PHY_IF4_PORT2, 26)
set_config(cavium.CONFIG_PHY_IF4_PORT3, 27)
-- BGX5 (QLM7)
set_config(cavium.CONFIG_PHY_IF5_PORT0, 28)
set_config(cavium.CONFIG_PHY_IF5_PORT1, 29)
set_config(cavium.CONFIG_PHY_IF5_PORT2, 30)
set_config(cavium.CONFIG_PHY_IF5_PORT3, 31)

-- For RXAUI, We're using a Marvel PHY on the plugin modules. The code below
-- programs all BGXs to use "Interleaved running disparity", which is required
-- for these PHYs. This will need to be changed if PHYs are used that expect
-- "Common running disparity".
for bgx=0,5 do
    for i=0,1 do
        -- cavium.csr.BGXX_SPUX_MISC_CONTROL(bgx,i).intlv_rdisp = 1
    end
end

-- printf("Configuring QLMs for a sample setup\n");

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
-- Choosing QLM modes for BGX (QLMs 0-7)
--------------------------------------------------------------
-- SGMII modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_SGMII, 1250, 0)

-- *XAUI modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_XAUI_1X4, 3125, 0)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_XAUI_1X4, 6250, 0)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_RXAUI_2X2, 6250, 0)

-- XFI modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_XFI_4X1, 10321, 0)

-- XLAUI modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_XLAUI_1X4, 10321, 0)

-- 10GBASE-KR modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_10G_KR_4X1, 10321, 0)

-- 40GBASE-KR modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_40G_KR4_1X4, 10321, 0)

--------------------------------------------------------------
-- Choosing QLM modes for Interlaken (QLMs 4-7)
--------------------------------------------------------------
-- Interlaken modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_ILK, 3125, 0)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_ILK, 6250, 0)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_ILK, 10321, 0)

--------------------------------------------------------------
-- Choosing QLM modes for PCIe (QLMs 0-4)
--------------------------------------------------------------
-- PCIe x4 modes (QLMs 0-4)
-- cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X4, 2500, cavium.QLM_MODE_FLAG_GEN1)
-- cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X4, 5000, cavium.QLM_MODE_FLAG_GEN2)
-- cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X4, 8000, cavium.QLM_MODE_FLAG_GEN3)
-- cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X4, 2500, cavium.QLM_MODE_FLAG_GEN1+cavium.QLM_MODE_FLAG_ENDPOINT)
-- cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X4, 5000, cavium.QLM_MODE_FLAG_GEN2+cavium.QLM_MODE_FLAG_ENDPOINT)
-- cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X4, 8000, cavium.QLM_MODE_FLAG_GEN3+cavium.QLM_MODE_FLAG_ENDPOINT)

-- PCIe x8 modes (QLMs 0&1, 2&3, 3&4)
-- Only call for the first QLM of the pair
-- cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X8, 2500, cavium.QLM_MODE_FLAG_GEN1)
-- cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X8, 5000, cavium.QLM_MODE_FLAG_GEN2)
-- cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X8, 8000, cavium.QLM_MODE_FLAG_GEN3)
-- cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X8, 2500, cavium.QLM_MODE_FLAG_GEN1+cavium.QLM_MODE_FLAG_ENDPOINT)
-- cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X8, 5000, cavium.QLM_MODE_FLAG_GEN2+cavium.QLM_MODE_FLAG_ENDPOINT)
-- cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X8, 8000, cavium.QLM_MODE_FLAG_GEN3+cavium.QLM_MODE_FLAG_ENDPOINT)

-- End of QLM examples
