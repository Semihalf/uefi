local bit64 = require("bit64")
local node = 0

-- Configure the evb7000 board.
menu.dofile("board-evb7000")

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

-- Setup Vitesse PHYs in loopback
local mdio_bus = 1
for phy_addr=4,11 do
    -- Select main registers
    octeon.c.bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0)
    -- Near end loopback (Octeon side)
    reg0 = octeon.c.bdk_mdio_read(node, mdio_bus, phy_addr, 0)
    reg0 = bit64.binsert(reg0, 1, 14, 14)
    octeon.c.bdk_mdio_write(node, mdio_bus, phy_addr, 0, reg0)
end

