-- BDK QLM menu for CN88XX configuration.
require("strict")
require("utils")
require("menu")

-- This is an array indexed by QLM number. Each entry is a list of
-- QLM mode settings that the user can choose. Not all possibilites
-- are here, but this should cover most cases. Note that QLMs that
-- have the same list share the same lists, so take care making
-- modifications.
local qlm_modes = {}
qlm_modes[0] = {
    {"SGMII   @  1 Gbps", cavium.QLM_MODE_SGMII, 1250, 0},
    {"XAUI    @ 10 Gbps", cavium.QLM_MODE_XAUI_1X4, 3125, 0},
    {"DXAUI   @ 20 Gbps", cavium.QLM_MODE_XAUI_1X4, 6250, 0},
    {"RXAUI   @ 10 Gbps", cavium.QLM_MODE_RXAUI_2X2, 6250, 0},
    {"XFI     @ 10 Gbps", cavium.QLM_MODE_XFI_4X1, 10312, 0},
    {"XLAUI   @ 40 Gbps", cavium.QLM_MODE_XLAUI_1X4, 10312, 0},
    {"10G-KR  @ 10 Gbps", cavium.QLM_MODE_10G_KR_4X1, 10312, 0},
    {"40G-KR4 @ 40 Gbps", cavium.QLM_MODE_40G_KR4_1X4, 10312, 0},
    {"Disabled", cavium.QLM_MODE_DISABLED, 0, 0}
}
qlm_modes[1] = qlm_modes[0]
qlm_modes[2] = {
    {"PCIe x4 - GEN 1", cavium.QLM_MODE_PCIE_1X4, 2500, 0},
    {"PCIe x4 - GEN 2", cavium.QLM_MODE_PCIE_1X4, 5000, 0},
    {"PCIe x4 - GEN 3", cavium.QLM_MODE_PCIE_1X4, 8000, 0},
    {"PCIe x8 - GEN 1", cavium.QLM_MODE_PCIE_1X8, 2500, 0},
    {"PCIe x8 - GEN 2", cavium.QLM_MODE_PCIE_1X8, 5000, 0},
    {"PCIe x8 - GEN 3", cavium.QLM_MODE_PCIE_1X8, 8000, 0},
    {"SATA    @ 1.500 Gbps", cavium.QLM_MODE_SATA_4X1, 1500, 0},
    {"SATA    @ 3.000 Gbps", cavium.QLM_MODE_SATA_4X1, 3000, 0},
    {"SATA    @ 6.000 Gbps", cavium.QLM_MODE_SATA_4X1, 6000, 0},
    {"Disabled", cavium.QLM_MODE_DISABLED, 0, 0}
}
qlm_modes[3] = {
    {"PCIe x4 - GEN 1", cavium.QLM_MODE_PCIE_1X4, 2500, 0},
    {"PCIe x4 - GEN 2", cavium.QLM_MODE_PCIE_1X4, 5000, 0},
    {"PCIe x4 - GEN 3", cavium.QLM_MODE_PCIE_1X4, 8000, 0},
    {"SATA    @ 1.500 Gbps", cavium.QLM_MODE_SATA_4X1, 1500, 0},
    {"SATA    @ 3.000 Gbps", cavium.QLM_MODE_SATA_4X1, 3000, 0},
    {"SATA    @ 6.000 Gbps", cavium.QLM_MODE_SATA_4X1, 6000, 0},
    {"Disabled", cavium.QLM_MODE_DISABLED, 0, 0}
}
qlm_modes[4] = {
    {"PCIe x4 - GEN 1", cavium.QLM_MODE_PCIE_1X4, 2500, 0},
    {"PCIe x4 - GEN 2", cavium.QLM_MODE_PCIE_1X4, 5000, 0},
    {"PCIe x4 - GEN 3", cavium.QLM_MODE_PCIE_1X4, 8000, 0},
    {"PCIe x8 - GEN 1", cavium.QLM_MODE_PCIE_1X8, 2500, 0},
    {"PCIe x8 - GEN 2", cavium.QLM_MODE_PCIE_1X8, 5000, 0},
    {"PCIe x8 - GEN 3", cavium.QLM_MODE_PCIE_1X8, 8000, 0},
    {"Disabled", cavium.QLM_MODE_DISABLED, 0, 0}
}
qlm_modes[5] = {
    {"PCIe x4 - GEN 1", cavium.QLM_MODE_PCIE_1X4, 2500, 0},
    {"PCIe x4 - GEN 2", cavium.QLM_MODE_PCIE_1X4, 5000, 0},
    {"PCIe x4 - GEN 3", cavium.QLM_MODE_PCIE_1X4, 8000, 0},
    {"Disabled", cavium.QLM_MODE_DISABLED, 0, 0}
}
qlm_modes[6] = qlm_modes[2]
qlm_modes[7] = qlm_modes[3]
-- GSER 8-13 are OCI only and are normally covered by pin straps
qlm_modes[8] = {
    {"CCPI    @ 1.250 Gbps", cavium.QLM_MODE_OCI, 1250, 0},
    {"CCPI    @ 2.500 Gbps", cavium.QLM_MODE_OCI, 2500, 0},
    {"CCPI    @ 3.125 Gbps", cavium.QLM_MODE_OCI, 3125, 0},
    {"CCPI    @ 5.000 Gbps", cavium.QLM_MODE_OCI, 5000, 0},
    {"CCPI    @ 6.250 Gbps", cavium.QLM_MODE_OCI, 6250, 0},
    {"CCPI    @ 8.000 Gbps", cavium.QLM_MODE_OCI, 8000, 0},
    {"CCPI    @ 10.3125 Gbps", cavium.QLM_MODE_OCI, 10312, 0},
    {"Disabled", cavium.QLM_MODE_DISABLED, 0, 0}
}
qlm_modes[9] = qlm_modes[8]
qlm_modes[10] = qlm_modes[8]
qlm_modes[11] = qlm_modes[8]
qlm_modes[12] = qlm_modes[8]
qlm_modes[13] = qlm_modes[8]

--
-- This is called when the user selects a QLM to change its config
--
local function do_setup(qlm)
    -- Only the first 8 QLMs can select differnet reference clocks
    -- CCPI QLMs 8-13 always use an external reference clock
    if qlm < 8 then
        local m = menu.new("Select a reference clock for QLM%d" % qlm)
        m:item("ext", "External reference (QLM%d_REF_CLK)" % qlm)
        m:item("c0", "Common clock 0 (QLMC_REF_CLK0)")
        m:item("c1", "Common clock 1 (QLMC_REF_CLK1)")
        local index = m:show()
        -- Select the reference clock to use
        if index == "ext" then
            cavium.csr[menu.node].GSERX_REFCLK_SEL(qlm).COM_CLK_SEL = 0
            cavium.csr[menu.node].GSERX_REFCLK_SEL(qlm).USE_COM1 = 0
        elseif index == "c0" then
            cavium.csr[menu.node].GSERX_REFCLK_SEL(qlm).COM_CLK_SEL = 1
            cavium.csr[menu.node].GSERX_REFCLK_SEL(qlm).USE_COM1 = 0
        else
            cavium.csr[menu.node].GSERX_REFCLK_SEL(qlm).COM_CLK_SEL = 1
            cavium.csr[menu.node].GSERX_REFCLK_SEL(qlm).USE_COM1 = 1
        end
        -- Reset the QLM after changing the reference clock
        cavium.c.bdk_qlm_reset(menu.node, qlm)
    end

    -- Select the mode to use
    local m = menu.new("Select a mode for QLM%d" % qlm)
    for i=1,#qlm_modes[qlm] do
        m:item(i, qlm_modes[qlm][i][1])
    end
    local index = m:show()
    local choice = qlm_modes[qlm][index]
    local mode = choice[2]
    local baud_mhz = choice[3]
    local flags = choice[4]
    cavium.c.bdk_qlm_set_mode(menu.node, qlm, mode, baud_mhz, flags)
end

--
-- Chip specific configuration prompting for CN88XX
--
function qlm_setup_cn88xx()
    local qlm_max = 7
    -- Allow changing the CCPI QLMs if they are in software mode
    if cavium.csr.GSERX_SPD(8).SPD == 0xf then
        qlm_max = 13
    end
    local m = menu.new("Select a QLM to Configure")
    repeat
        for qlm_num = 0, qlm_max do
            local mode = cavium.c.bdk_qlm_get_mode(menu.node, qlm_num)
            local config_mode = cavium.c.bdk_qlm_mode_tostring(mode)
            local config_speed = cavium.c.bdk_qlm_get_gbaud_mhz(menu.node, qlm_num)
            local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm_num)
            local label = (num_lanes == 2) and "DLM" or "QLM"
            local ref_clock = cavium.c.bdk_qlm_measure_clock(menu.node, qlm_num)
            local option
            if config_speed == 0 then
                option = "%s %d - Disabled" % {label, qlm_num}
            else
                option = "%s %d - %s @%2d.%03d GBaud, ref %3d.%03d Mhz" % {label, qlm_num, config_mode, config_speed / 1000, config_speed % 1000, ref_clock / 1000000, ref_clock / 1000 % 1000}
            end
            m:item("qlm" .. qlm_num, option, do_setup, qlm_num)
        end
        m:item("quit", "Exit menu")
    until (m:show() == "quit")
end

