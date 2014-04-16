-- BDK QLM menu for CN78XX configuration.
require("strict")
require("utils")
require("menu")

local node = octeon.MASTER_NODE

-- This is an array indexed by QLM number. Each entry is a list of
-- QLM mode settings that the user can choose. Not all possibilites
-- are here, but this should cover most cases. Note that QLMs that
-- have the same list share the same lists, so take care making
-- modifications.
local qlm_modes = {}
qlm_modes[0] = {
    {"PCIe x4 - GEN 1", octeon.QLM_MODE_PCIE_1X4, 2500, octeon.QLM_MODE_FLAG_GEN1},
    {"PCIe x4 - GEN 2", octeon.QLM_MODE_PCIE_1X4, 5000, octeon.QLM_MODE_FLAG_GEN2},
    {"PCIe x4 - GEN 3", octeon.QLM_MODE_PCIE_1X4, 8000, octeon.QLM_MODE_FLAG_GEN3},
    {"PCIe x4 - GEN 3 Endpoint", octeon.QLM_MODE_PCIE_1X4, 8000, octeon.QLM_MODE_FLAG_GEN3+octeon.QLM_MODE_FLAG_ENDPOINT},
    {"PCIe x8 - GEN 1", octeon.QLM_MODE_PCIE_1X8, 2500, octeon.QLM_MODE_FLAG_GEN1},
    {"PCIe x8 - GEN 2", octeon.QLM_MODE_PCIE_1X8, 5000, octeon.QLM_MODE_FLAG_GEN2},
    {"PCIe x8 - GEN 3", octeon.QLM_MODE_PCIE_1X8, 8000, octeon.QLM_MODE_FLAG_GEN3},
    {"PCIe x8 - GEN 3 Endpoint", octeon.QLM_MODE_PCIE_1X8, 8000, octeon.QLM_MODE_FLAG_GEN3+octeon.QLM_MODE_FLAG_ENDPOINT},
    {"SGMII   @  1 Gbps", octeon.QLM_MODE_SGMII, 1250, 0},
    {"SGMII   @  2 Gbps", octeon.QLM_MODE_SGMII, 2500, 0},
    {"SGMII   @  4 Gbps", octeon.QLM_MODE_SGMII, 5000, 0},
    {"XAUI    @ 10 Gbps", octeon.QLM_MODE_XAUI_1X4, 3125, 0},
    {"XAUI    @ 20 Gbps", octeon.QLM_MODE_XAUI_1X4, 6250, 0},
    {"RXAUI   @ 10 Gbps", octeon.QLM_MODE_RXAUI_2X2, 6250, 0},
    {"10G-R   @ 10 Gbps", octeon.QLM_MODE_10GR_4X1, 10312, 0},
    {"40G-R   @ 40 Gbps", octeon.QLM_MODE_40GR4_1X4, 10312, 0},
    {"Disabled", octeon.QLM_MODE_DISABLED, 0, 0}
}
qlm_modes[1] = {
    {"PCIe x4 - GEN 1", octeon.QLM_MODE_PCIE_1X4, 2500, octeon.QLM_MODE_FLAG_GEN1},
    {"PCIe x4 - GEN 2", octeon.QLM_MODE_PCIE_1X4, 5000, octeon.QLM_MODE_FLAG_GEN2},
    {"PCIe x4 - GEN 3", octeon.QLM_MODE_PCIE_1X4, 8000, octeon.QLM_MODE_FLAG_GEN3},
    {"PCIe x4 - GEN 3 Endpoint", octeon.QLM_MODE_PCIE_1X4, 8000, octeon.QLM_MODE_FLAG_GEN3+octeon.QLM_MODE_FLAG_ENDPOINT},
    {"SGMII   @  1 Gbps", octeon.QLM_MODE_SGMII, 1250, 0},
    {"SGMII   @  2 Gbps", octeon.QLM_MODE_SGMII, 2500, 0},
    {"SGMII   @  4 Gbps", octeon.QLM_MODE_SGMII, 5000, 0},
    {"XAUI    @ 10 Gbps", octeon.QLM_MODE_XAUI_1X4, 3125, 0},
    {"XAUI    @ 20 Gbps", octeon.QLM_MODE_XAUI_1X4, 6250, 0},
    {"RXAUI   @ 10 Gbps", octeon.QLM_MODE_RXAUI_2X2, 6250, 0},
    {"10G-R   @ 10 Gbps", octeon.QLM_MODE_10GR_4X1, 10312, 0},
    {"40G-R   @ 40 Gbps", octeon.QLM_MODE_40GR4_1X4, 10312, 0},
    {"Disabled", octeon.QLM_MODE_DISABLED, 0, 0}
}
qlm_modes[2] = {
    {"PCIe x4 - GEN 1", octeon.QLM_MODE_PCIE_1X4, 2500, octeon.QLM_MODE_FLAG_GEN1},
    {"PCIe x4 - GEN 2", octeon.QLM_MODE_PCIE_1X4, 5000, octeon.QLM_MODE_FLAG_GEN2},
    {"PCIe x4 - GEN 3", octeon.QLM_MODE_PCIE_1X4, 8000, octeon.QLM_MODE_FLAG_GEN3},
    {"PCIe x4 - GEN 3 Endpoint", octeon.QLM_MODE_PCIE_1X4, 8000, octeon.QLM_MODE_FLAG_GEN3+octeon.QLM_MODE_FLAG_ENDPOINT},
    {"PCIe x8 - GEN 1", octeon.QLM_MODE_PCIE_1X8, 2500, octeon.QLM_MODE_FLAG_GEN1},
    {"PCIe x8 - GEN 2", octeon.QLM_MODE_PCIE_1X8, 5000, octeon.QLM_MODE_FLAG_GEN2},
    {"PCIe x8 - GEN 3", octeon.QLM_MODE_PCIE_1X8, 8000, octeon.QLM_MODE_FLAG_GEN3},
    {"PCIe x8 - GEN 3 Endpoint", octeon.QLM_MODE_PCIE_1X8, 8000, octeon.QLM_MODE_FLAG_GEN3+octeon.QLM_MODE_FLAG_ENDPOINT},
    {"ILK  x4 @  3.125  GBaud", octeon.QLM_MODE_ILK, 3125, 0},
    {"ILK  x4 @  6.250  GBaud", octeon.QLM_MODE_ILK, 6250, 0},
    {"ILK  x4 @ 10.3125 GBaud", octeon.QLM_MODE_ILK, 10312, 0},
    {"SGMII   @  1 Gbps", octeon.QLM_MODE_SGMII, 1250, 0},
    {"SGMII   @  2 Gbps", octeon.QLM_MODE_SGMII, 2500, 0},
    {"SGMII   @  4 Gbps", octeon.QLM_MODE_SGMII, 5000, 0},
    {"XAUI    @ 10 Gbps", octeon.QLM_MODE_XAUI_1X4, 3125, 0},
    {"XAUI    @ 20 Gbps", octeon.QLM_MODE_XAUI_1X4, 6250, 0},
    {"RXAUI   @ 10 Gbps", octeon.QLM_MODE_RXAUI_2X2, 6250, 0},
    {"10G-R   @ 10 Gbps", octeon.QLM_MODE_10GR_4X1, 10312, 0},
    {"40G-R   @ 40 Gbps", octeon.QLM_MODE_40GR4_1X4, 10312, 0},
    {"Disabled", octeon.QLM_MODE_DISABLED, 0, 0}
}
qlm_modes[3] = qlm_modes[2]
qlm_modes[4] = {
    {"PCIe x4 - GEN 1", octeon.QLM_MODE_PCIE_1X4, 2500, octeon.QLM_MODE_FLAG_GEN1},
    {"PCIe x4 - GEN 2", octeon.QLM_MODE_PCIE_1X4, 5000, octeon.QLM_MODE_FLAG_GEN2},
    {"PCIe x4 - GEN 3", octeon.QLM_MODE_PCIE_1X4, 8000, octeon.QLM_MODE_FLAG_GEN3},
    {"PCIe x4 - GEN 3 Endpoint", octeon.QLM_MODE_PCIE_1X4, 8000, octeon.QLM_MODE_FLAG_GEN3+octeon.QLM_MODE_FLAG_ENDPOINT},
    {"ILK  x4 @  3.125  GBaud", octeon.QLM_MODE_ILK, 3125, 0},
    {"ILK  x4 @  6.250  GBaud", octeon.QLM_MODE_ILK, 6250, 0},
    {"ILK  x4 @ 10.3125 GBaud", octeon.QLM_MODE_ILK, 10312, 0},
    {"SGMII   @  1 Gbps", octeon.QLM_MODE_SGMII, 1250, 0},
    {"SGMII   @  2 Gbps", octeon.QLM_MODE_SGMII, 2500, 0},
    {"SGMII   @  4 Gbps", octeon.QLM_MODE_SGMII, 5000, 0},
    {"XAUI    @ 10 Gbps", octeon.QLM_MODE_XAUI_1X4, 3125, 0},
    {"XAUI    @ 20 Gbps", octeon.QLM_MODE_XAUI_1X4, 6250, 0},
    {"RXAUI   @ 10 Gbps", octeon.QLM_MODE_RXAUI_2X2, 6250, 0},
    {"10G-R   @ 10 Gbps", octeon.QLM_MODE_10GR_4X1, 10312, 0},
    {"40G-R   @ 40 Gbps", octeon.QLM_MODE_40GR4_1X4, 10312, 0},
    {"Disabled", octeon.QLM_MODE_DISABLED, 0, 0}
}
qlm_modes[5] = {
    {"ILK  x4 @  3.125  GBaud", octeon.QLM_MODE_ILK, 3125, 0},
    {"ILK  x4 @  6.250  GBaud", octeon.QLM_MODE_ILK, 6250, 0},
    {"ILK  x4 @ 10.3125 GBaud", octeon.QLM_MODE_ILK, 10312, 0},
    {"SGMII   @  1 Gbps", octeon.QLM_MODE_SGMII, 1250, 0},
    {"SGMII   @  2 Gbps", octeon.QLM_MODE_SGMII, 2500, 0},
    {"SGMII   @  4 Gbps", octeon.QLM_MODE_SGMII, 5000, 0},
    {"XAUI    @ 10 Gbps", octeon.QLM_MODE_XAUI_1X4, 3125, 0},
    {"XAUI    @ 20 Gbps", octeon.QLM_MODE_XAUI_1X4, 6250, 0},
    {"RXAUI   @ 10 Gbps", octeon.QLM_MODE_RXAUI_2X2, 6250, 0},
    {"10G-R   @ 10 Gbps", octeon.QLM_MODE_10GR_4X1, 10312, 0},
    {"40G-R   @ 40 Gbps", octeon.QLM_MODE_40GR4_1X4, 10312, 0},
    {"Disabled", octeon.QLM_MODE_DISABLED, 0, 0}
}
qlm_modes[6] = qlm_modes[5]
qlm_modes[7] = qlm_modes[5]
-- GSER 8-13 are OCI only and are covered by pin straps

--
-- This is called when the user selects a QLM to change its config
--
local function do_setup(qlm)
    local m = menu.new("Select a mode for QLM%d" % qlm)
    for i=1,#qlm_modes[qlm] do
        m:item(i, qlm_modes[qlm][i][1])
    end
    local index = m:show()
    local choice = qlm_modes[qlm][index]
    local mode = choice[2]
    local baud_mhz = choice[3]
    local flags = choice[4]
    octeon.c.bdk_qlm_set_mode(node, qlm, mode, baud_mhz, flags)
end

--
-- Chip specific configuration prompting for CN78XX
--
function qlm_setup_cn78xx()
    local m = menu.new("Select a QLM to Configure")
    repeat
        for qlm_num = 0, 7 do
            local mode = octeon.c.bdk_qlm_get_mode(node, qlm_num)
            local config_mode = octeon.c.bdk_qlm_mode_tostring(mode)
            local config_speed = octeon.c.bdk_qlm_get_gbaud_mhz(node, qlm_num)
            local num_lanes = octeon.c.bdk_qlm_get_lanes(node, qlm_num)
            local label = (num_lanes == 2) and "DLM" or "QLM"
            local ref_clock = octeon.c.bdk_qlm_measure_clock(node, qlm_num)
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

