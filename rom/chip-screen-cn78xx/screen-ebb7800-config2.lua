local bit64 = require("bit64")
local node = 0

-- Configure the ebb7800 board.
menu.dofile("board-ebb7800")

--QLM 2
octeon.csr.GSERX_REFCLK_SEL(2).USE_COM1 = 0
octeon.csr.GSERX_REFCLK_SEL(2).COM_CLK_SEL = 0
octeon.c.bdk_qlm_reset(node, 2)
octeon.c.bdk_qlm_set_mode(node, 2, octeon.QLM_MODE_XAUI_1X4, 6250, 0)

--QLM 3
octeon.csr.GSERX_REFCLK_SEL(3).USE_COM1 = 0
octeon.csr.GSERX_REFCLK_SEL(3).COM_CLK_SEL = 0
octeon.c.bdk_qlm_reset(node, 3)
octeon.c.bdk_qlm_set_mode(node, 3, octeon.QLM_MODE_XAUI_1X4, 6250, 0)

--QLM 5
octeon.csr.GSERX_REFCLK_SEL(5).USE_COM1 = 0
octeon.csr.GSERX_REFCLK_SEL(5).COM_CLK_SEL = 0
octeon.c.bdk_qlm_reset(node, 5)
octeon.c.bdk_qlm_set_mode(node, 5, octeon.QLM_MODE_10GR_4X1, 10312, 0)

--QLM 7
octeon.csr.GSERX_REFCLK_SEL(7).USE_COM1 = 0
octeon.csr.GSERX_REFCLK_SEL(7).COM_CLK_SEL = 0
octeon.c.bdk_qlm_reset(node, 7)
octeon.c.bdk_qlm_set_mode(node, 7, octeon.QLM_MODE_10GR_4X1, 10312, 0)


