local bit64 = require("bit64")
local node = 0

-- Configure the ebb7800 board.
menu.dofile("board-ebb7800")

--QLM 0
cavium.csr.GSERX_REFCLK_SEL(0).USE_COM1 = 0
cavium.csr.GSERX_REFCLK_SEL(0).COM_CLK_SEL = 0
cavium.c.bdk_qlm_reset(node, 0)
cavium.c.bdk_qlm_set_mode(node, 0, cavium.QLM_MODE_RXAUI_2X2, 6250, 0)

--QLM 1
cavium.csr.GSERX_REFCLK_SEL(1).USE_COM1 = 0
cavium.csr.GSERX_REFCLK_SEL(1).COM_CLK_SEL = 0
cavium.c.bdk_qlm_reset(node, 1)
cavium.c.bdk_qlm_set_mode(node, 1, cavium.QLM_MODE_RXAUI_2X2, 6250, 0)

--QLM 4
cavium.csr.GSERX_REFCLK_SEL(4).USE_COM1 = 0
cavium.csr.GSERX_REFCLK_SEL(4).COM_CLK_SEL = 0
cavium.c.bdk_qlm_reset(node, 4)
cavium.c.bdk_qlm_set_mode(node, 4, cavium.QLM_MODE_10G_KR_4X1, 10312, 0)

--QLM 6
cavium.csr.GSERX_REFCLK_SEL(6).USE_COM1 = 0
cavium.csr.GSERX_REFCLK_SEL(6).COM_CLK_SEL = 0
cavium.c.bdk_qlm_reset(node, 6)
cavium.c.bdk_qlm_set_mode(node, 6, cavium.QLM_MODE_10G_KR_4X1, 10312, 0)


