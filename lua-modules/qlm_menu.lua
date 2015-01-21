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
    m:item_node() -- Adds option to choose the node number
    if cavium.is_model(cavium.CN88XX) then
        require("qlm_menu_cn88xx")
        m:item("set", "Change QLM/DLM configuration", qlm_setup_cn88xx)
    end
    -- Build a list of QLMs showing the current config. Selecting them
    -- does nothing
    local num_qlms = cavium.c.bdk_qlm_get_num(menu.node)
    for qlm_num = 0, num_qlms-1 do
        local mode = cavium.c.bdk_qlm_get_mode(menu.node, qlm_num)
        local config_mode = cavium.c.bdk_qlm_mode_tostring(mode)
        local config_speed = cavium.c.bdk_qlm_get_gbaud_mhz(menu.node, qlm_num)
        local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm_num)
        local label = (num_lanes == 2) and "DLM" or "QLM"
        local ref_clock = cavium.c.bdk_qlm_measure_clock(menu.node, qlm_num)
        -- Round ref clock to the nearest KHz and change to Khz
        ref_clock = (ref_clock + 500) / 1000
        local option
        if config_speed == 0 then
            option = "%s %d - Disabled, ref %3d.%03d Mhz" % {label, qlm_num, ref_clock / 1000, ref_clock % 1000}
        else
            option = "%s %d - %s @%2d.%03d GBaud, ref %3d.%03d Mhz" % {label, qlm_num, config_mode, config_speed / 1000, config_speed % 1000, ref_clock / 1000, ref_clock % 1000}
        end
        m:item("qlm" .. qlm_num, option)
    end
    m:item("tune", "PRBS and SERDES Tuning", qlm_tuning.run)
    m:item("quit", "Main menu")
until (m:show() == "quit")


