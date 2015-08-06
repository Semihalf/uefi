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
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_RXAUI_2X2, 6250, 0)

-- XFI modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_XFI_4X1, 10312, 0)

-- XLAUI modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_XLAUI_1X4, 10312, 0)

-- 10GBASE-KR modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_10G_KR_4X1, 10312, 0)

-- 40GBASE-KR modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_40G_KR4_1X4, 10312, 0)

--------------------------------------------------------------
-- Choosing QLM modes for SATA (QLMs 2-3, 6-7)
--------------------------------------------------------------
-- SATA modes
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_SATA_4X1, 1500, 0)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_SATA_4X1, 3000, 0)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_SATA_4X1, 6000, 0)

--------------------------------------------------------------
-- Choosing QLM modes for PCIe (QLMs 2-7)
--------------------------------------------------------------
-- PCIe x4 modes (QLMs 2-7)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_PCIE_1X4, 2500, 0)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_PCIE_1X4, 5000, 0)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_PCIE_1X4, 8000, 0)

-- PCIe x8 modes (QLMs 2&3, 4&5, 6&7)
-- Only call for the first QLM of the pair
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_PCIE_1X8, 2500, 0)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_PCIE_1X8, 5000, 0)
-- cavium.c.bdk_qlm_set_mode(node, qlm, cavium.QLM_MODE_PCIE_1X8, 8000, 0)

-- End of QLM examples

if not cavium.is_platform(cavium.PLATFORM_EMULATOR) then
    printf("QLM0-1: Using common clock 1 (156.25Mhz)\n")
    printf("QLM2-7: Using common clock 0 (100.00Mhz)\n")
    for qlm=0,7 do
        cavium.csr[cavium.MASTER_NODE].GSERX_REFCLK_SEL(qlm).COM_CLK_SEL = 1
        cavium.csr[cavium.MASTER_NODE].GSERX_REFCLK_SEL(qlm).USE_COM1 = (qlm < 2) and 1 or 0
    end
    cavium.c.bdk_qlm_auto_config(cavium.MASTER_NODE)
end

