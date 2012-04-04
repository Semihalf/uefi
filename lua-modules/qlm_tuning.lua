-- BDK QLM menu.
-- Displays the GUI interface for accessing QLM settings.
require("strict")
require("utils")
require("menu")
require("qlm")
local readline = require("readline")

local qlm_tuning = {}
qlm_tuning.qlm = 0

-- Table of TX biasdrvsel to Amplitude in millivolts
qlm_tuning.biasdrv = {
    [4] = 150,
    [6] = 250,
    [7] = 300,
    [8] = 350,
    [12] = 500,
    [15] = 600,
    [17] = 700,
    [18] = 750,
    [26] = 1000,
    [29] = 1100,
    [31] = 1200,
}

-- Table of TX tcoeff to demphasis in DB*10
qlm_tuning.tcoeff = {
    [0] = 0,
    [1] = -1,
    [2] = -4,
    [3] = -7,
    [4] = -11,
    [5] = -14,
    [6] = -17,
    [7] = -21,
    [8] = -25,
    [9] = -29,
    [10] = -33,
    [11] = -37,
    [12] = -43,
    [13] = -48,
    [14] = -52,
    [15] = -59,
    [16] = -65,
    [17] = -72,
    [18] = -79,
    [19] = -88,
    [20] = -96,
}


-- Prompt for which QLM/DLM to edit
local function select_qlm()
    local num_qlms = octeon.c.bdk_qlm_get_num()
    qlm_tuning.qlm = menu.prompt_number("QLM/DLM", qlm_tuning.qlm, 0, num_qlms-1)
    return qlm_tuning.qlm
end

-- Prompt for which lane to edit
local function select_lane(qlm_num, allow_all)
    local num_lanes = octeon.c.bdk_qlm_get_lanes(qlm_num)
    local default = allow_all and -1 or 0
    local lane
    if allow_all then
        lane = menu.prompt_number("QLM/DLM Lane, or -1 for all", default, -1, num_lanes-1)
    else
        lane = menu.prompt_number("QLM/DLM Lane", default, 0, num_lanes-1)
    end
    return lane
end

-- Select a list of QLMs to perform operations on
local function select_qlm_list(qlm_list)
    local num_qlms = octeon.c.bdk_qlm_get_num()
    -- Default to all QLMs if the list wasn't supplied
    if not qlm_list then
        qlm_list = {}
        for qlm_num=0,num_qlms-1 do
            table.insert(qlm_list, qlm_num)
        end
    end
    -- Convert the default list to a string
    local s = ""
    for _,qlm_num in ipairs(qlm_list) do
        assert((qlm_num >= 0) and (qlm_num < num_qlms), "Invalid QLM/DLM number")
        s = s .. tostring(qlm_num)
    end
    -- Ask the user
    s = menu.prompt_string("List of QLM/DLM to use", s)
    qlm_list = {}
    for i=1,#s do
        local qlm_num = tonumber(s:sub(i,i))
        assert((qlm_num >= 0) and (qlm_num < num_qlms), "Invalid QLM/DLM number")
        table.insert(qlm_list, qlm_num)
    end
    return qlm_list
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
local function change_tx(qlm_num, settings, lane_num)
    local biasdrv
    local tcoeff

    if not lane_num then
        lane_num = select_lane(qlm_num, true)
    end

    if settings then
        biasdrv = settings["biasdrv"]
        tcoeff = settings["tcoeff"]
    else
        local default_biasdrv
        local default_tcoeff
        -- Get current values as the default
        if lane_num == -1 then
            default_biasdrv = octeon.c.bdk_qlm_jtag_get(qlm_num, 0, "biasdrv_hs_ls_byp")
            default_tcoeff = octeon.c.bdk_qlm_jtag_get(qlm_num, 0, "tcoeff_hf_ls_byp")
        else
            default_biasdrv = octeon.c.bdk_qlm_jtag_get(qlm_num, lane_num, "biasdrv_hs_ls_byp")
            default_tcoeff = octeon.c.bdk_qlm_jtag_get(qlm_num, lane_num, "tcoeff_hf_ls_byp")
        end

        printf("   biasdrv\tTX Amplitude\n")
        for _,b in ipairs(table.sorted_keys(qlm_tuning.biasdrv)) do
            printf("\t%2d\t%4d mV\n", b, qlm_tuning.biasdrv[b])
        end
        biasdrv = menu.prompt_number("TX Amplitude(biasdrv)", default_biasdrv, 0, 31)

        printf("    tcoeff\tTX Demphasis\n")
        for _,t in ipairs(table.sorted_keys(qlm_tuning.tcoeff)) do
            local db = -qlm_tuning.tcoeff[t]
            printf("\t%2d\t-%d.%d db\n", t, db/10, db%10)
        end
        tcoeff = menu.prompt_number("TX Demphasis(tcoeff)", default_tcoeff, 0, 15)
    end

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
local function change_rx(qlm_num, settings, lane_num)
    local rx_cap
    local rx_eq

    if not lane_num then
        lane_num = select_lane(qlm_num, true)
    end

    if settings then
        rx_cap = settings["rx_cap"]
        rx_eq = settings["rx_eq"]
    else
        local default_rx_cap
        local default_rx_eq
        -- Get current values as the default
        if lane_num == -1 then
            default_rx_cap = octeon.c.bdk_qlm_jtag_get(qlm_num, 0, "rx_cap_gen2")
            default_rx_eq = octeon.c.bdk_qlm_jtag_get(qlm_num, 0, "rx_eq_gen2")
        else
            default_rx_cap = octeon.c.bdk_qlm_jtag_get(qlm_num, lane_num, "rx_cap_gen2")
            default_rx_eq = octeon.c.bdk_qlm_jtag_get(qlm_num, lane_num, "rx_eq_gen2")
        end
        rx_cap = menu.prompt_number("RX cap(rx_cap)", default_rx_cap, 0, 15)
        rx_eq = menu.prompt_number("RX eq(rx_eq)", default_rx_eq, 0, 15)
    end

    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "rx_cap_gen2", rx_cap)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "rx_cap_gen1", rx_cap)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "rx_eq_gen2", rx_eq)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "rx_eq_gen1", rx_eq)
end

-- Start PRBS on a list of QLMs
local function start_prbs(mode, qlm_list)
    -- Reset the QLMs. Do this independently from PRBS so that all
    -- resets are complete before we start PRBS
    for _,qlm_num in ipairs(qlm_list) do
        qlm.do_reset(qlm_num)
    end
    -- Start PRBS on the QLMs in reverse order. For some reason
    -- this help CN68XX pass 2.0 QLM1 start better.
    for _,qlm_num in ipairs(qlm_list) do
        qlm.do_prbs(qlm_num, mode)
    end
end

-- Run PRBS on all QLMs
local function do_prbs(mode)
    local qlm_list = select_qlm_list()
    local function output_line(qlm_base, label, get_value)
        printf("%21s", label)
        local qlm_max = qlm_base + 2
        if qlm_max >= #qlm_list then
            qlm_max = #qlm_list
        end
        for qlm_index = qlm_base,qlm_max do
            local qlm_num = qlm_list[qlm_index]
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
    -- Display PRBS status on the console
    local function display_status(run_time)
        printf("\n\n");
        printf("PRBS-%d time: %d seconds (Press return to exit)\n", mode, run_time)
        for qlm_base=1,#qlm_list,3 do
            output_line(qlm_base, "", function(qlm, lane)
                return (lane == 0) and ("--- QLM " .. qlm) or "----------"
            end)
            output_line(qlm_base, "", function(qlm, lane)
                return "Lane " .. lane
            end)
            output_line(qlm_base, "TX amplitude(biasdrv)", function(qlm, lane)
                if octeon.c.bdk_qlm_jtag_get(qlm, lane, "serdes_tx_byp") == 1 then
                    return octeon.c.bdk_qlm_jtag_get(qlm, lane, "biasdrv_hs_ls_byp")
                else
                    return ""
                end
            end)
            output_line(qlm_base, "TX demphasis(tcoeff)", function(qlm, lane)
                if octeon.c.bdk_qlm_jtag_get(qlm, lane, "serdes_tx_byp") == 1 then
                    return octeon.c.bdk_qlm_jtag_get(qlm, lane, "tcoeff_hf_ls_byp")
                else
                    return ""
                end
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
                local qlm_speed = octeon.c.bdk_qlm_get_gbaud_mhz(qlm)
                local v = octeon.c.bdk_qlm_jtag_get(qlm, lane, "prbs_lock")
                if (v == 0) or (run_time == 0) then
                    return "-"
                else
                    -- Calculate the error rate as a fraction of the bits
                    -- transmitted
                    v = octeon.c.bdk_qlm_jtag_get(qlm, lane, "prbs_err_cnt")
                    local total_bits = qlm_speed * run_time
                    local rate_exponent = -6 -- Since qlm_speed is in Mbps
                    local rate
                    -- If no errors then act like the next bit is an error
                    -- This way we always can calulate an error rate
                    if v == 0 then
                        v = 1
                    end
                    -- Scale v such that integer division will give decent results
                    while v < total_bits * 100 do
                        rate_exponent = rate_exponent - 1
                        v = v * 10
                    end
                    -- Calculate the error rate
                    rate = v / total_bits
                    -- Scale the error rate to be three digits
                    while rate >= 1000 do
                        rate_exponent = rate_exponent + 1
                        rate = rate / 10
                    end
                    while rate < 100 do
                        rate_exponent = rate_exponent - 1
                        rate = rate * 10
                    end
                    -- Convert the three digit error rate into scientific notation
                    return "%d.%02dE%d" % {rate/100, rate%100, rate_exponent + 2}
                end
            end)
            output_line(qlm_base, "", function(qlm, lane)
                return "----------"
            end)
            printf("\n")
        end
    end

    printf("PRBS-%d running. Statistics shown every 5 seconds\n", mode)
    start_prbs(mode, qlm_list)

    local start_time = os.time()
    local next_print = start_time + 5
    repeat
        local t = os.time()
        -- Periodically show the PRBS error counter and other status fields.
        if t >= next_print then
            display_status(t - start_time)
            next_print = next_print + 5
        end
    until readline.getkey() == '\r'
end

-- Automatically tune the QLMs
local function auto_tune()
    local prbs_mode = menu.prompt_number("PRBS mode", 31, 7, 31)
    local qlm_list = select_qlm_list()
    local function auto_done_check(run_time)
        -- Abort auto tune if the user presses return
        if readline.getkey() == '\r' then
            return "abort"
        end
        -- "results" will be a table with all the PRBS error counts
        -- for each QLM and lane (results[qlm][lane] = errors)
        local results = {}
        -- We keep testing this setup as long as at least one QLM is
        -- working. Working is defined as all lanes having an error
        -- count below a threshold.
        local qlm_good = false
        for _,qlm in ipairs(qlm_list) do
            local qlm_lanes_good = true
            results[qlm] = {}
            for lane=0, octeon.c.bdk_qlm_get_lanes(qlm)-1 do
                local v = octeon.c.bdk_qlm_jtag_get(qlm, lane, "prbs_lock")
                if v == 1 then
                    -- We have PRBS lock
                    v = octeon.c.bdk_qlm_jtag_get(qlm, lane, "prbs_err_cnt")
                    if v >= 10 then
                        -- Too many errors on this lane
                        qlm_lanes_good = false
                    end
                    results[qlm][lane] = v
                else
                    -- Lane never reach lock
                    qlm_lanes_good = false
                    results[qlm][lane] = "No lock"
                end
            end
            qlm_good = qlm_good or qlm_lanes_good
        end
        -- Run until all QLMs are bad or a max time occurs
        if qlm_good and (run_time < 10) then
            return false -- Keep running
        end
        -- Done, so return the results
        return results
    end

    printf("\n")
    printf("Automatic tuning sweeps the QLMs through a number of TX\n")
    printf("and RX parameters. For each setup, PRBS-%d tests for errors.\n", prbs_mode)
    printf("All parameters that result in error free PRBS-%d are\n", prbs_mode)
    printf("recorded and displayed in a final summary.\n")
    printf("\n")

    -- Prompt the user for the settings ranges we should try
    local min_rx_cap = menu.prompt_number("Minimum RX cap(rx_cap)", 0, 0, 15)
    local max_rx_cap = menu.prompt_number("Maximum RX cap(rx_cap)", 2, 0, 15)
    local min_rx_eq = menu.prompt_number("Minimum RX eq(rx_eq)", 8, 0, 15)
    local max_rx_eq = menu.prompt_number("Maximum RX eq(rx_eq)", 15, 0, 15)
    local min_biasdrv = menu.prompt_number("Minimum TX Amplitude(biasdrv)", 8, 0, 31)
    local max_biasdrv = menu.prompt_number("Maximum TX Amplitude(biasdrv)", 24, 0, 31)
    local min_tcoeff = menu.prompt_number("Minimum TX Demphasis(tcoeff)", 6, 0, 15)
    local max_tcoeff = menu.prompt_number("Maximum TX Demphasis(tcoeff)", 15, 0, 15)

    local settings = {} -- Stores the settings we are currently testing
    local lane_num = -1 -- Test all lanes on each QLM
    local summary = {} -- Good values will be stored here as they are found
    local iter_count = 0
    local iter_max = (max_rx_cap - min_rx_cap + 1) * (max_rx_eq - min_rx_eq + 1) * (max_biasdrv - min_biasdrv + 1) * (max_tcoeff - min_tcoeff + 1)
    for rx_cap = min_rx_cap, max_rx_cap do
        for rx_eq = min_rx_eq, max_rx_eq do
            for biasdrv = min_biasdrv, max_biasdrv do
                for tcoeff = min_tcoeff, max_tcoeff do
                    iter_count = iter_count + 1
                    printf("%4d of %4d: rx_cap=%2d rx_eq=%2d biasdrv=%2d tcoeff=%2d\n", iter_count, iter_max, rx_cap, rx_eq, biasdrv, tcoeff)
                    -- Change the settings of all QLMs
                    settings["rx_eq"] = rx_eq
                    settings["rx_cap"] = rx_cap
                    settings["biasdrv"] = biasdrv
                    settings["tcoeff"] = tcoeff
                    for _,qlm in ipairs(qlm_list) do
                        change_tx(qlm, settings, lane_num)
                        change_rx(qlm, settings, lane_num)
                    end
                    -- Run PRBS
                    start_prbs(prbs_mode, qlm_list)
                    -- Check for complete
                    local prbs_result
                    local start_time = os.time()
                    repeat
                        local run_time = os.time() - start_time
                        prbs_result = auto_done_check(run_time)
                        -- Check for a user abort
                        if prbs_result == "abort" then
                            return
                        end
                    until prbs_result
                    -- Search to see if any QLM passed
                    for _,qlm in ipairs(qlm_list) do
                        local all_good = true -- Are all lanes good?
                        for lane=0, octeon.c.bdk_qlm_get_lanes(qlm)-1 do
                            all_good = all_good and (prbs_result[qlm][lane] == 0)
                        end
                        if all_good then
                            -- Record this good result
                            local key = "%d,%d,%d,%d" % {qlm, biasdrv, tcoeff, rx_eq, rx_cap}
                            summary[key] = true
                        end
                    end
                end
            end
        end
    end

    -- Display summary
    printf("\n")
    printf("Automatic Tuning Results\n")
    printf("----------------------------------------------\n")
    printf("The following settings gave error free results\n")
    printf("\n")
    for _,qlm in ipairs(qlm_list) do
        local title = {}

        title[1] = "%-14s|" % ("QLM/DLM%d" % qlm)
        title[2] = "%14s|" % "RX Cap"
        title[3] = "%14s|" % ""
        title[4] = "%14s|" % ""
        title[5] = "%14s|" % "RX Eq"
        title[6] = "%14s|" % "biasdrv|tcoeff"
        for rx_cap = min_rx_cap, max_rx_cap do
            for rx_eq = min_rx_eq, max_rx_eq do
                local column = "%2d-%2d-" % {rx_cap, rx_eq}
                for i=1, 6 do
                    title[i] = title[i] .. column:sub(i,i)
                end
            end
        end
        for i=1,6 do
            printf("%s|\n", title[i])
        end
        for biasdrv = min_biasdrv, max_biasdrv do
            for tcoeff = min_tcoeff, max_tcoeff do
                printf("%7d|%6d|", biasdrv, tcoeff)
                for rx_cap = min_rx_cap, max_rx_cap do
                    for rx_eq = min_rx_eq, max_rx_eq do
                        local key = "%d,%d,%d,%d" % {qlm, biasdrv, tcoeff, rx_eq, rx_cap}
                        printf(summary[key] and "#" or " ")
                    end
                end
                printf("|\n")
            end
        end
        printf("----------------------------------------------\n")
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
        m:item("prbs7",  "PRBS-7", do_prbs, 7)
        if not octeon.is_model(octeon.CN63XX) then
            m:item("prbs15", "PRBS-15", do_prbs, 15)
            m:item("prbs23", "PRBS-23", do_prbs, 23)
        end
        m:item("prbs31", "PRBS-31", do_prbs, 31)
        m:item("auto",   "Automatically Tune using PRBS", auto_tune)
        m:item("read",   "Read JTAG field",     read_jtag, qlm_tuning.qlm)
        m:item("write",  "Write JTAG field",    write_jtag, qlm_tuning.qlm)
        m:item("dump",   "Dump JTAG chain",     octeon.c.bdk_qlm_dump_jtag, qlm_tuning.qlm)
        m:item("quit",   "Main menu")
    until (m:show() == "quit")
end

return qlm_tuning
