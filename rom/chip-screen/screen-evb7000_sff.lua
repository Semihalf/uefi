local bit64 = require("bit64")
local node = 0

-- Configure the evb7000 board.
menu.dofile("board-evb7000_sff")

-- DLM0 uses external reference clock
octeon.csr.GSERX_DLMX_REF_USE_PAD(0,0).ref_use_pad = 1
octeon.csr.GSERX_DLMX_REFCLK_SEL(0,0).refclk_sel = 0
-- DLM1 uses C0 reference clock
octeon.csr.GSERX_DLMX_REF_USE_PAD(0,1).ref_use_pad = 0
octeon.csr.GSERX_DLMX_REFCLK_SEL(0,1).refclk_sel = 0
-- DLM2 uses C1 reference clock
octeon.csr.GSERX_DLMX_REF_USE_PAD(0,2).ref_use_pad = 0
octeon.csr.GSERX_DLMX_REFCLK_SEL(0,2).refclk_sel = 1

-- DLM0 in QSGMII
assert(0 == octeon.c.bdk_qlm_set_mode(node, 0, octeon.QLM_MODE_QSGMII_QSGMII,
    2500, 0), "Setting DLM0 mode failed")
setup_dlm0_hook(octeon.QLM_MODE_QSGMII_QSGMII, 2500, 0)
-- DLM1 & DLM2 in PCIe x4 host gen2
assert(0 == octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_PCIE_1X4,
    5000, octeon.QLM_MODE_FLAG_GEN2), "Setting DLM1&2 mode failed")