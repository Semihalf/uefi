--File for EBB7800 Board testing

local bit64 = require("bit64")
local node = 0

-- Configure the ebb7800 board.
menu.dofile("board-ebb7800")

--QLM 0
octeon.csr.GSERX_REFCLK_SEL(0).USE_COM1 = 0
octeon.csr.GSERX_REFCLK_SEL(0).COM_CLK_SEL = 0
octeon.c.bdk_qlm_reset(node, 0)
octeon.c.bdk_qlm_set_mode(node, 0, octeon.QLM_MODE_SGMII, 1250, 0)

--QLM 1
octeon.csr.GSERX_REFCLK_SEL(1).USE_COM1 = 0
octeon.csr.GSERX_REFCLK_SEL(1).COM_CLK_SEL = 0
octeon.c.bdk_qlm_reset(node, 1)
octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_XAUI_1X4, 3125, 0)

--QLM 5
octeon.csr.GSERX_REFCLK_SEL(5).USE_COM1 = 0
octeon.csr.GSERX_REFCLK_SEL(5).COM_CLK_SEL = 0
octeon.c.bdk_qlm_reset(node, 5)
octeon.c.bdk_qlm_set_mode(node, 5, octeon.QLM_MODE_XAUI_1X4, 3125, 0)



