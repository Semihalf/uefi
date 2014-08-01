local bit64 = require("bit64")
local node = 0

-- Configure the ebb7800 board.
menu.dofile("board-ebb7800")

--QLM 2
cavium.csr.GSERX_REFCLK_SEL(2).USE_COM1 = 0
cavium.csr.GSERX_REFCLK_SEL(2).COM_CLK_SEL = 0
cavium.c.bdk_qlm_reset(node, 2)
cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_XAUI_1X4, 6250, 0)

--QLM 3
cavium.csr.GSERX_REFCLK_SEL(3).USE_COM1 = 0
cavium.csr.GSERX_REFCLK_SEL(3).COM_CLK_SEL = 0
cavium.c.bdk_qlm_reset(node, 3)
cavium.c.bdk_qlm_set_mode(node, 3, cavium.QLM_MODE_XAUI_1X4, 6250, 0)

--QLM 5
cavium.csr.GSERX_REFCLK_SEL(5).USE_COM1 = 0
cavium.csr.GSERX_REFCLK_SEL(5).COM_CLK_SEL = 0
cavium.c.bdk_qlm_reset(node, 5)
cavium.c.bdk_qlm_set_mode(node, 5, cavium.QLM_MODE_10G_KR_4X1, 10312, 0)

--QLM 7
cavium.csr.GSERX_REFCLK_SEL(7).USE_COM1 = 0
cavium.csr.GSERX_REFCLK_SEL(7).COM_CLK_SEL = 0
cavium.c.bdk_qlm_reset(node, 7)
cavium.c.bdk_qlm_set_mode(node, 7, cavium.QLM_MODE_10G_KR_4X1, 10312, 0)


