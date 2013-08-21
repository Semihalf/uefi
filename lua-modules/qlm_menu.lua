-- BDK QLM menu.
-- Displays the GUI interface for accessing QLM settings.
require("strict")
require("utils")
require("menu")
local qlm_tuning = require("qlm_tuning")

--
-- Build the main QLM/DLM menu
--
local m = menu.new("QLM/DLM Menu")
repeat
    -- Add a configuration option for chips that support it
    if octeon.is_model(octeon.CN70XX) then
        require("qlm_menu_cn70xx")
        m:item("set", "Change QLM/DLM configuration", qlm_setup_cn70xx)
    elseif octeon.is_model(octeon.CN78XX) then
        require("qlm_menu_cn78xx")
        m:item("set", "Change QLM/DLM configuration", qlm_setup_cn78xx)
    end
    -- Build a list of QLMs showing the current config. Selecting them
    -- does nothing
    local node = 0
    local num_qlms = octeon.c.bdk_qlm_get_num(node)
    for qlm_num = 0, num_qlms-1 do
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
        m:item("qlm" .. qlm_num, option)
    end
    m:item("tune", "PRBS and SERDES Tuning", qlm_tuning.run)
    m:item("quit", "Main menu")
until (m:show() == "quit")


