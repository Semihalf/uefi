-- BDK QLM menu for CN61XX configuration.
require("strict")
require("utils")
require("menu")

local node = 0

local function setup_dlmx_ref(qlm, default_option)
    local m = menu.new("DLM%d Reference clock" % qlm)
    m:item("c0", "Common reference clock 0 (DLMC_REF_CLK0_P/N)")
    m:item("c1", "Common reference clock 1 (DLMC_REF_CLK1_P/N)")
    m:item("e0", "External reference clock 0 (DLM0_REF_CLK_P/N)")
    local ref = m:show(default_option)
    if ref == "c0" then
        octeon.csr.GSERX_DLMX_REF_USE_PAD(0,qlm).ref_use_pad = 0
        octeon.csr.GSERX_DLMX_REFCLK_SEL(0,qlm).refclk_sel = 0
    elseif ref == "c1" then
        octeon.csr.GSERX_DLMX_REF_USE_PAD(0,qlm).ref_use_pad = 0
        octeon.csr.GSERX_DLMX_REFCLK_SEL(0,qlm).refclk_sel = 1
    else
        octeon.csr.GSERX_DLMX_REF_USE_PAD(0,qlm).ref_use_pad = 1
        octeon.csr.GSERX_DLMX_REFCLK_SEL(0,qlm).refclk_sel = 0
    end
end

local function setup_dlm0(mode, speed, flags)
    assert(0 == octeon.c.bdk_qlm_set_mode(node, 0, mode, speed, flags), "Setting DLM0 mode failed")
end

-- Chip specific configuration prompting for CN70XX
function qlm_setup_cn70xx()
    if ((octeon.c.bdk_qlm_get_mode(node, 0) ~= octeon.QLM_MODE_DISABLED) or
        (octeon.c.bdk_qlm_get_mode(node, 1) ~= octeon.QLM_MODE_DISABLED) or
        (octeon.c.bdk_qlm_get_mode(node, 2) ~= octeon.QLM_MODE_DISABLED)) then
        assert(false, "DLMs already configured once. You must reset before reconfig")
    end

    setup_dlmx_ref(0, "e0")
    setup_dlmx_ref(1, "c0")
    setup_dlmx_ref(2, "c0")

    local m = menu.new("DLM0 Mode")
    m:item("xa", "RXAUI   lanes 0-1",              setup_dlm0, octeon.QLM_MODE_RXAUI_1X2,       6250, 0)
    m:item("ss", "SGMII   lane 0, SGMII   lane 1", setup_dlm0, octeon.QLM_MODE_SGMII_SQMII,     1250, 0)
    m:item("sq", "SGMII   lane 0, QSGMII  lane 1", setup_dlm0, octeon.QLM_MODE_SGMII_QSGMII,    5000, 0)
    m:item("sd", "SGMII   lane 0, Disable lane 1", setup_dlm0, octeon.QLM_MODE_SGMII_DISABLED,  1250, 0)
    m:item("qs", "QSGMII  lane 0, SGMII   lane 1", setup_dlm0, octeon.QLM_MODE_QSGMII_SGMII,    5000, 0)
    m:item("qq", "QSGMII  lane 0, QSGMII  lane 1", setup_dlm0, octeon.QLM_MODE_QSGMII_QSGMII,   5000, 0)
    m:item("qd", "QSGMII  lane 0, Disable lane 1", setup_dlm0, octeon.QLM_MODE_QSGMII_DISABLED, 5000, 0)
    m:item("ds", "Disable lane 0, SGMII   lane 1", setup_dlm0, octeon.QLM_MODE_DISABLED_SGMII,  1250, 0)
    m:item("dq", "Disable lane 0, QSGMII  lane 1", setup_dlm0, octeon.QLM_MODE_DISABLED_QSGMII, 5000, 0)
    m:item("dd", "Disable both lanes",             setup_dlm0, octeon.QLM_MODE_DISABLED,        0,    0)
    local net_mode = m:show("qq")

    local m = menu.new("DLM1-2 Mode")
    m:item("1x4", "PCIe x4 lanes 2-5")
    m:item("2x2", "PCIe x2 lanes 2-3, PCIe x2 lanes 4-5")
    m:item("3x1", "PCIe x1 lane  2,   PCIe x1 lane  4,  PCIe x1 lane  5")
    m:item("1x2", "PCIe x2 lanes 2-3, SATA    lanes 4,5")
    m:item("2x1", "PCIe x1 lane  2,   PCIe x1 lane  3,  SATA    lanes 4,5")
    m:item("dis", "Disable lanes 2-5")
    local pcie_mode = m:show("2x1")

    local pcie_gen2
    local pcie1_root
    local flags = 0
    if pcie_mode ~= "dis" then
        pcie_gen2 = menu.prompt_yes_no("Configure PCIe for gen2", "y")
        pcie1_root = menu.prompt_yes_no("Configure PCIe port 1 as a root complex", "y")
        flags = pcie_gen2 and octeon.QLM_MODE_FLAG_GEN2 or octeon.QLM_MODE_FLAG_GEN1
        flags = flags + (pcie1_root and 0 or octeon.QLM_MODE_FLAG_ENDPOINT)
    end

    if pcie_mode == "1x4" then
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_PCIE_1X4, 5000, flags), "Setting DLM1 mode failed")
    elseif pcie_mode == "2x2" then
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_PCIE_1X2, 5000, flags), "Setting DLM1 mode failed")
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 2, octeon.QLM_MODE_PCIE_1X2, 5000, flags), "Setting DLM2 mode failed")
    elseif pcie_mode == "3x1" then
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_PCIE_1X1, 5000, flags), "Setting DLM1 mode failed")
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 2, octeon.QLM_MODE_PCIE_2X1, 5000, flags), "Setting DLM2 mode failed")
    elseif pcie_mode == "1x2" then
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_PCIE_1X2, 5000, flags), "Setting DLM1 mode failed")
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 2, octeon.QLM_MODE_SATA_2X1, 3125, flags), "Setting DLM2 mode failed")
    elseif pcie_mode == "2x1" then
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_PCIE_2X1, 5000, flags), "Setting DLM1 mode failed")
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 2, octeon.QLM_MODE_SATA_2X1, 3125, flags), "Setting DLM2 mode failed")
    else
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_DISABLED, 0, 0), "Setting DLM1 mode failed")
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 2, octeon.QLM_MODE_DISABLED, 0, 0), "Setting DLM2 mode failed")
    end
end

