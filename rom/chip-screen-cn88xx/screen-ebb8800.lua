local bit64 = require("bit64")
local node = 0

-- Configure the ebb7800 board.
menu.dofile("board-ebb7800")

--QLM 0
octeon.csr.GSERX_REFCLK_SEL(0).USE_COM1 = 0
octeon.csr.GSERX_REFCLK_SEL(0).COM_CLK_SEL = 0
octeon.c.bdk_qlm_reset(node, 0)
octeon.c.bdk_qlm_set_mode(node, 0, octeon.QLM_MODE_RXAUI_2X2, 6250, 0)

--QLM 1
octeon.csr.GSERX_REFCLK_SEL(1).USE_COM1 = 0
octeon.csr.GSERX_REFCLK_SEL(1).COM_CLK_SEL = 0
octeon.c.bdk_qlm_reset(node, 1)
octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_RXAUI_2X2, 6250, 0)

--QLM 4
octeon.csr.GSERX_REFCLK_SEL(4).USE_COM1 = 0
octeon.csr.GSERX_REFCLK_SEL(4).COM_CLK_SEL = 0
octeon.c.bdk_qlm_reset(node, 4)
octeon.c.bdk_qlm_set_mode(node, 4, octeon.QLM_MODE_10G_KR_4X1, 10312, 0)

--QLM 6
octeon.csr.GSERX_REFCLK_SEL(6).USE_COM1 = 0
octeon.csr.GSERX_REFCLK_SEL(6).COM_CLK_SEL = 0
octeon.c.bdk_qlm_reset(node, 6)
octeon.c.bdk_qlm_set_mode(node, 6, octeon.QLM_MODE_10G_KR_4X1, 10312, 0)


