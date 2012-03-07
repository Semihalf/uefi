-- BDK QLM menu.
-- Displays the GUI interface for accessing QLM settings.
require("strict")
require("utils")
require("menu")
require("qlm")
local readline = require("readline")

local qlm_tuning = {}
qlm_tuning.qlm = 0

-- Prompt for which QLM/DLM to edit
local function select_qlm()
    local num_qlms = octeon.c.bdk_qlm_get_num()
    qlm_tuning.qlm = menu.prompt_number("QLM/DLM (0-%d)" % (num_qlms-1), qlm_tuning.qlm, 0, num_qlms-1)
    return qlm_tuning.qlm
end

-- Prompt for which lane to edit
local function select_lane(qlm_num, allow_all)
    local num_lanes = octeon.c.bdk_qlm_get_lanes(qlm_num)
    local default = allow_all and -1 or 0
    local lane
    if allow_all then
        lane = menu.prompt_number("Lane (0-%d, -1 for all)" % (num_lanes-1), default, -1, num_lanes-1)
    else
        lane = menu.prompt_number("Lane (0-%d)" % (num_lanes-1), default, 0, num_lanes-1)
    end
    return lane
end

-- Read a value from the JTAG chain
local function read_jtag(qlm_num)
    local lane = select_lane(qlm_num, false)
    local field = menu.prompt_string("Field")
    local value = octeon.c.bdk_qlm_jtag_get(qlm_num, lane, field)
    if value ~= -1 then
        printf("QLM%d %s[%d]: %d (0x%04x)\n", qlm_num, field, lane, value, value)
    end
end

-- Write a value to the JTAG chain
local function write_jtag(qlm_num)
    local lane = select_lane(qlm_num, true)
    local field = menu.prompt_string("Field")
    local value = menu.prompt_number("Value")
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane, field, value)
end

-- Prompt for TX QLM parameters and change them
local function change_tx(qlm_num)
    local default_biasdrv
    local default_tcoeff
    local lane_num = select_lane(qlm_num, true)

    -- Get current values as the default
    if lane_num == -1 then
        default_biasdrv = octeon.c.bdk_qlm_jtag_get(qlm_num, 0, "biasdrv_hs_ls_byp")
        default_tcoeff = octeon.c.bdk_qlm_jtag_get(qlm_num, 0, "tcoeff_hf_ls_byp")
    else
        default_biasdrv = octeon.c.bdk_qlm_jtag_get(qlm_num, lane_num, "biasdrv_hs_ls_byp")
        default_tcoeff = octeon.c.bdk_qlm_jtag_get(qlm_num, lane_num, "tcoeff_hf_ls_byp")
    end
    local biasdrv = menu.prompt_number("TX amplitude(biasdrv)", default_biasdrv, 0, 31)
    local tcoeff = menu.prompt_number("TX demphasis(tcoeff)", default_tcoeff, 0, 15)

    -- Write ALL the biasdrvsel fields:
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "biasdrv_hs_ls_byp", biasdrv)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "biasdrv_hf_byp", biasdrv)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "biasdrv_lf_ls_byp", biasdrv)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "biasdrv_lf_byp", biasdrv)
    -- Write ALL the tcoeff fields:
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "tcoeff_hf_ls_byp", tcoeff)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "tcoeff_hf_byp", tcoeff)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "tcoeff_lf_ls_byp", tcoeff)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "tcoeff_lf_byp", tcoeff)
    -- Assert serdes_tx_byp to force the new settings to override the QLM default.
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "serdes_tx_byp", 1)
end

-- Prompt for RX QLM parameters and change them
local function change_rx(qlm_num)
    local default_rx_cap
    local default_rx_eq
    local lane_num = select_lane(qlm_num, true)

    -- Get current values as the default
    if lane_num == -1 then
        default_rx_cap = octeon.c.bdk_qlm_jtag_get(qlm_num, 0, "rx_cap_gen2")
        default_rx_eq = octeon.c.bdk_qlm_jtag_get(qlm_num, 0, "rx_eq_gen2")
    else
        default_rx_cap = octeon.c.bdk_qlm_jtag_get(qlm_num, lane_num, "rx_cap_gen2")
        default_rx_eq = octeon.c.bdk_qlm_jtag_get(qlm_num, lane_num, "rx_eq_gen2")
    end
    local rx_cap = menu.prompt_number("RX cap(rx_cap)", default_rx_cap, 0, 15)
    local rx_eq = menu.prompt_number("RX eq(rx_eq)", default_rx_eq, 0, 15)

    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "rx_cap_gen2", rx_cap)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "rx_cap_gen1", rx_cap)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "rx_eq_gen2", rx_eq)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "rx_eq_gen1", rx_eq)
end

-- Run PRBS on all QLMs
local function do_prbs(mode)
    local function output_line(qlm_base, label, get_value)
        printf("%21s", label)
        local qlm_max = qlm_base + 2
        if qlm_max >= octeon.c.bdk_qlm_get_num() then
            qlm_max = octeon.c.bdk_qlm_get_num()-1
        end
        for qlm_num=qlm_base,qlm_max do
            local num_lanes = octeon.c.bdk_qlm_get_lanes(qlm_num)
            for lane=0, num_lanes-1 do
                local v = get_value(qlm_num, lane)
                if lane == 0 then
                    printf("|%10s", tostring(v))
                else
                    printf(" %10s", tostring(v))
                end
            end
        end
        printf("|\n")
    end
    for qlm_num=0,octeon.c.bdk_qlm_get_num()-1 do
        qlm.do_prbs(qlm_num, mode)
    end
    printf("PRBS-%d running. Statistics shown every 5 seconds\n", mode)

    -- Periodically show the PRBS error counter and other status fields.
    local start_time = os.time()
    local next_print = start_time
    while readline.getkey() ~= '\r' do
        local t = os.time()
        if t >= next_print then
            next_print = next_print + 5
            printf("\n\n");
            printf("PRBS-%d time: %d seconds (Press return to exit)\n", mode, t - start_time)
            for qlm_base=0,octeon.c.bdk_qlm_get_num()-1,3 do
                output_line(qlm_base, "", function(qlm, lane)
                    return (lane == 0) and ("--- QLM " .. qlm) or "----------"
                end)
                output_line(qlm_base, "", function(qlm, lane)
                    return "Lane " .. lane
                end)
                output_line(qlm_base, "TX amplitude(biasdrv)", function(qlm, lane)
                    return octeon.c.bdk_qlm_jtag_get(qlm, lane, "biasdrv_hs_ls_byp")
                end)
                output_line(qlm_base, "TX demphasis(tcoeff)", function(qlm, lane)
                    return octeon.c.bdk_qlm_jtag_get(qlm, lane, "tcoeff_hf_ls_byp")
                end)
                output_line(qlm_base, "RX cap", function(qlm, lane)
                    return octeon.c.bdk_qlm_jtag_get(qlm, lane, "rx_cap_gen2")
                end)
                output_line(qlm_base, "RX eq", function(qlm, lane)
                    return octeon.c.bdk_qlm_jtag_get(qlm, lane, "rx_eq_gen2")
                end)
                output_line(qlm_base, "PRBS Errors", function(qlm, lane)
                    local v = octeon.c.bdk_qlm_jtag_get(qlm, lane, "prbs_lock")
                    if v == 0 then
                        return "No Lock"
                    else
                        v = octeon.c.bdk_qlm_jtag_get(qlm, lane, "prbs_err_cnt")
                        if v == 0 then
                            return "-"
                        elseif v < 1000000 then
                            return v
                        elseif v < 1000000000 then
                            return tostring(v / 1000000) .. "M"
                        else
                            return tostring(v / 1000000000) .. "B"
                        end
                    end
                end)
                output_line(qlm_base, "PRBS Error Rate", function(qlm, lane)
                    local v = octeon.c.bdk_qlm_jtag_get(qlm, lane, "prbs_lock")
                    if (v == 0) or (t == start_time) then
                        return "-"
                    else
                        v = octeon.c.bdk_qlm_jtag_get(qlm, lane, "prbs_err_cnt")
                        v = v / (t - start_time)
                        if v == 0 then
                            return "-"
                        elseif v < 1000000 then
                            return tostring(v) .. "/s"
                        elseif v < 1000000000 then
                            return tostring(v / 1000000) .. "M/s"
                        else
                            return tostring(v / 1000000000) .. "B/s"
                        end
                    end
                end)
                output_line(qlm_base, "", function(qlm, lane)
                    return "----------"
                end)
                printf("\n")
            end
        end
    end
end

-- Main menu
function qlm_tuning.run()
    local m = menu.new("PRBS and SERDES Tuning Menu")
    repeat
        local num_lanes = octeon.c.bdk_qlm_get_lanes(qlm_tuning.qlm)
        local current_qlm = (num_lanes == 2) and "DLM" or "QLM"
        current_qlm = current_qlm .. qlm_tuning.qlm
        m:item("qlm",    "Select active QLM/DLM (Currently %s)" % current_qlm, select_qlm)
        m:item("txparm", "Change TX parameters", change_tx, qlm_tuning.qlm)
        m:item("rxparm", "Change RX parameters", change_rx, qlm_tuning.qlm)
        m:item("down",   "Reset and power down", qlm.do_reset, qlm_tuning.qlm)
        if not octeon.is_model(octeon.CN63XX) then
            m:item("loop1", "Shallow loopback lane 0 and 3", qlm.do_loop, qlm_tuning.qlm, 1)
            m:item("loop3", "Shallow loopback lane 1 and 2", qlm.do_loop, qlm_tuning.qlm, 3)
        else
            m:item("loop", "Shallow loopback",  qlm.do_loop, qlm_tuning.qlm, 1)
        end
        m:item("prbs7",  "PRBS7",               do_prbs, 7)
        if not octeon.is_model(octeon.CN63XX) then
            m:item("prbs15", "PRBS15",          do_prbs, 15)
            m:item("prbs23", "PRBS23",          do_prbs, 23)
        end
        m:item("prbs31", "PRBS31",              do_prbs, 31)
        m:item("read",   "Read JTAG field",     read_jtag, qlm_tuning.qlm)
        m:item("write",  "Write JTAG field",    write_jtag, qlm_tuning.qlm)
        m:item("dump",   "Dump JTAG chain",     octeon.c.bdk_qlm_dump_jtag, qlm_tuning.qlm)
        m:item("quit",   "Main menu")
    until (m:show() == "quit")
end

return qlm_tuning
