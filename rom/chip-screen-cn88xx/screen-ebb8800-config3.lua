--File for EBB7800 Board testing

local bit64 = require("bit64")
local node = 0

-- Configure the ebb7800 board.
menu.dofile("board-ebb7800")

--QLM 0
cavium.csr.GSERX_REFCLK_SEL(0).USE_COM1 = 0
cavium.csr.GSERX_REFCLK_SEL(0).COM_CLK_SEL = 0
cavium.c.bdk_qlm_reset(node, 0)
cavium.c.bdk_qlm_set_mode(node, 0, cavium.QLM_MODE_SGMII, 1250, 0)

--QLM 1
cavium.csr.GSERX_REFCLK_SEL(1).USE_COM1 = 0
cavium.csr.GSERX_REFCLK_SEL(1).COM_CLK_SEL = 0
cavium.c.bdk_qlm_reset(node, 1)
cavium.c.bdk_qlm_set_mode(node, 1, cavium.QLM_MODE_XAUI_1X4, 3125, 0)

--QLM 5
cavium.csr.GSERX_REFCLK_SEL(5).USE_COM1 = 0
cavium.csr.GSERX_REFCLK_SEL(5).COM_CLK_SEL = 0
cavium.c.bdk_qlm_reset(node, 5)
cavium.c.bdk_qlm_set_mode(node, 5, cavium.QLM_MODE_XAUI_1X4, 3125, 0)



