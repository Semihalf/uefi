-- BDK QLM menu.
-- Displays the GUI interface for accessing QLM settings.
require("strict")
require("utils")
require("menu")
local bit64 = require("bit64")
local readline = require("readline")

local qlm_tuning = {}
qlm_tuning.qlm = 0

-- Prompt for which QLM/DLM to edit
local function select_qlm()
    local num_qlms = cavium.c.bdk_qlm_get_num(menu.node)
    qlm_tuning.qlm = menu.prompt_number("QLM/DLM", qlm_tuning.qlm, 0, num_qlms-1)
    return qlm_tuning.qlm
end

-- Prompt for which lane to edit
local function select_lane(qlm_num, allow_all)
    local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm_num)
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
    local num_qlms = cavium.c.bdk_qlm_get_num(menu.node)
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
        s = s .. "," .. tostring(qlm_num)
    end
    -- Remove the extra ","
    s = s:sub(2)
    -- Ask the user
    s = menu.prompt_string("List of QLM/DLM to use", s)
    qlm_list = {}
    for w in string.gmatch(s, "%d+") do
        local qlm_num = tonumber(w)
        assert((qlm_num >= 0) and (qlm_num < num_qlms), "Invalid QLM/DLM number")
        table.insert(qlm_list, qlm_num)
    end
    return qlm_list
end

-- Polarity swap P/N on all lanes of QLMs
local function do_polarity_swap()
    local qlm_list = select_qlm_list()
    for _,qlm in pairs(qlm_list) do
        local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm)
        for lane=0,num_lanes-1 do
            local v = cavium.csr[menu.node].GSERX_LANEX_RX_CFG_0(qlm,lane).cfg_rx_pol_invert
            v = (v == 1) and 0 or 1
            cavium.csr[menu.node].GSERX_LANEX_RX_CFG_0(qlm,lane).cfg_rx_pol_invert = v
        end
    end
end

-- Issue a "Base-R RX Link Training equalization evaluation request", wait for
-- it to complete, and display the results
local function do_rx_evaluation(node, qlm, lane)
    -- Enable software control
    cavium.csr[node].GSERX_BR_RXX_CTL(qlm,lane).RXT_SWM = 1
    -- Clear the completion flag
    cavium.csr[node].GSERX_BR_RXX_EER(qlm,lane).RXT_ESV=0
    -- Initiate a new request
    cavium.csr[node].GSERX_BR_RXX_EER(qlm,lane).RXT_EER = 1
    -- Wait for it to complete
    local wait_ms = 0
    while cavium.csr[node].GSERX_BR_RXX_EER(qlm,lane).RXT_ESV == 0 do
        if wait_ms > 1000 then -- 1 second
            printf("QLM%d, Lane %d: RX equalization timeout\n", qlm, lane)
            return
        end
        cavium.c.bdk_wait_usec(1000)
        wait_ms = wait_ms + 1
    end
    -- Extract the results
    local rxt_esm = cavium.csr[node].GSERX_BR_RXX_EER(qlm,lane).RXT_ESM
    -- Switch back to hardware control
    cavium.csr[node].GSERX_BR_RXX_CTL(qlm,lane).RXT_SWM = 0
    -- Display the results
    local merit = bit64.bextract(rxt_esm, 6, 13)
    printf("QLM%d, Lane %d: Figure of merit %d (rxt_esm=0x%x)\n", qlm, lane, merit, rxt_esm)
end

-- Start PRBS on a list of QLMs
local function start_prbs(mode, qlm_list)
    -- Start PRBS on the QLMs.
    for _,qlm_num in ipairs(qlm_list) do
        cavium.c.bdk_qlm_enable_prbs(menu.node, qlm_num, mode, 1)
    end
    -- Let TX run for 1ms before starting RX
    cavium.c.bdk_wait_usec(1000)
    for _,qlm_num in ipairs(qlm_list) do
        cavium.c.bdk_qlm_enable_prbs(menu.node, qlm_num, mode, 2)
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
            local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm_num)
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
        printf("Time: %d seconds (Press return to exit, 'E' to inject an error, 'C' to clear errors,\n", run_time)
        printf("                  'P' to change TX pre-emphasis, 'S' to change TX swing)\n")
        for qlm_base=1,#qlm_list,3 do
            output_line(qlm_base, "", function(qlm, lane)
                return (lane == 0) and ("--- QLM " .. qlm) or "----------"
            end)
            output_line(qlm_base, "", function(qlm, lane)
                return "Lane " .. lane
            end)
            output_line(qlm_base, "Errors", function(qlm, lane)
                local v = cavium.c.bdk_qlm_get_prbs_errors(menu.node, qlm, lane, false)
                if v == -1 then
                    return "No Lock"
                else
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
            output_line(qlm_base, "Error Rate", function(qlm, lane)
                local qlm_speed = cavium.c.bdk_qlm_get_gbaud_mhz(menu.node, qlm)
                local v = cavium.c.bdk_qlm_get_prbs_errors(menu.node, qlm, lane, false)
                if (v == -1) or (run_time == 0) then
                    return "-"
                else
                    -- Calculate the error rate as a fraction of the bits
                    -- transmitted
                    local total_bits = qlm_speed * run_time
                    if total_bits == 0 then
                        total_bits = 1
                    end
                    local rate_exponent = -6 -- Since qlm_speed is in Mbps
                    local rate
                    -- If no errors then act like the next bit is an error
                    -- This way we always can calculate an error rate
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

    printf("Running. Statistics shown every 5 seconds\n", mode)
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
        local key = readline.getkey()
        if (key == 'e') or (key == 'E') then
            print("Injecting error into bit stream")
            for _,qlm_num in ipairs(qlm_list) do
                local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm_num)
                for lane=0, num_lanes-1 do
                    cavium.c.bdk_qlm_inject_prbs_error(menu.node, qlm_num, lane)
                end
            end
        end
        if (key == 'c') or (key == 'C') then
            print("Clearing error counts")
            for _,qlm_num in ipairs(qlm_list) do
                local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm_num)
                for lane=0, num_lanes-1 do
                    cavium.c.bdk_qlm_get_prbs_errors(menu.node, qlm_num, lane, true)
                end
            end
            start_time = os.time()
        end
        if (key == 'p') or (key =='P') then
            for _,qlm_num in ipairs(qlm_list) do
                local csr_value = cavium.csr[menu.node].GSERX_LANEX_TX_PRE_EMPHASIS(qlm_num,0).cfg_tx_premptap
                printf("GSERX_LANEX_TX_PRE_EMPHASIS(%d,0)[CFG_TX_PREMPTAP] = 0x%x\n", qlm_num, csr_value)
                local csr_setting = menu.prompt_number("New setting for CFG_TX_PREMTAP", csr_value, 0, 511)
                local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm_num)
                for lane=0, num_lanes-1 do
                    cavium.csr[menu.node].GSERX_LANEX_TX_PRE_EMPHASIS(qlm_num,lane).cfg_tx_premptap = csr_setting
                    cavium.csr[menu.node].GSERX_LANEX_TX_CFG_1(qlm_num,lane).tx_premptap_ovrd_val = 1
                    do_rx_evaluation(menu.node, qlm_num, lane)
                end
            end
        end
        if (key == 's') or (key =='S') then
            for _,qlm_num in ipairs(qlm_list) do
                local csr_value = cavium.csr[menu.node].GSERX_LANEX_TX_CFG_0(qlm_num,0).cfg_tx_swing
                printf("GSERX_LANEX_TX_CFG_0(%d,0)[CFG_TX_SWING] = 0x%x\n", qlm_num, csr_value)
                local csr_setting = menu.prompt_number("New setting for CFG_TX_SWING", csr_value, 0, 31)
                local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm_num)
                for lane=0, num_lanes-1 do
                    cavium.csr[menu.node].GSERX_LANEX_TX_CFG_0(qlm_num,lane).cfg_tx_swing = csr_setting
                    cavium.csr[menu.node].GSERX_LANEX_TX_CFG_1(qlm_num,lane).tx_swing_ovrd_en = 1
                    do_rx_evaluation(menu.node, qlm_num, lane)
                end
            end
         end

    until key == '\r'
end

local function set_preemphasis(qlm)
    local csr_value = 0
    local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm)
    for lane=0, num_lanes-1 do
        csr_value = cavium.csr[menu.node].GSERX_LANEX_TX_PRE_EMPHASIS(qlm,lane).cfg_tx_premptap
        printf("GSERX_LANEX_TX_PRE_EMPHASIS(%d,%d)[CFG_TX_PREMPTAP] = 0x%x\n", qlm, lane, csr_value)
    end
    local csr_setting = menu.prompt_number("New setting for QLM%s CFG_TX_PREMTAP" % qlm, csr_value, 0, 511)
    for lane=0, num_lanes-1 do
        cavium.csr[menu.node].GSERX_LANEX_TX_PRE_EMPHASIS(qlm,lane).cfg_tx_premptap = csr_setting
        cavium.csr[menu.node].GSERX_LANEX_TX_CFG_1(qlm,lane).tx_premptap_ovrd_val = 1
        do_rx_evaluation(menu.node, qlm, lane)
    end
end

local function set_preandpost(qlm)
    local csr_value = 0
    local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm)
    for lane=0, num_lanes-1 do
        csr_value = cavium.csr[menu.node].GSERX_LANEX_TX_CFG_0(qlm,lane).cfg_tx_swing
        printf("GSERX_LANEX_TX_CFG_0(%d,%d)[CFG_TX_SWING] = 0x%x\n", qlm, lane, csr_value)
    end
    local csr_setting = menu.prompt_number("New setting for QLM%s CFG_TX_SWING" % qlm, csr_value, 0, 31)
    for lane=0, num_lanes-1 do
        cavium.csr[menu.node].GSERX_LANEX_TX_CFG_0(qlm,lane).cfg_tx_swing = csr_setting
        cavium.csr[menu.node].GSERX_LANEX_TX_CFG_1(qlm,lane).tx_swing_ovrd_en = 1
        do_rx_evaluation(menu.node, qlm, lane)
    end
end

local function manual_rx_evaluation(qlm)
    local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm)
    for lane=0, num_lanes-1 do
        do_rx_evaluation(menu.node, qlm, lane)
    end
end

local function do_custom(mode)
    local pattern = menu.prompt_number("10 bit pattern", 0x155, 0, 0x3ff)
    do_prbs(pattern * 256 + mode)
end

-- Main menu
function qlm_tuning.run()
    local m = menu.new("PRBS and SERDES Tuning Menu")
    repeat
        local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm_tuning.qlm)
        local current_qlm = (num_lanes == 2) and "DLM" or "QLM"
        current_qlm = current_qlm .. qlm_tuning.qlm
        m:item("qlm",    "Select active QLM/DLM (Currently %s)" % current_qlm, select_qlm)
        m:item("down",   "Reset and power down", cavium.c.bdk_qlm_reset, menu.node, qlm_tuning.qlm)
        m:item("invert",  "Polarity swap receive P/N", do_polarity_swap)
        m:item("prbs7",  "PRBS-7", do_prbs, 7)
        m:item("prbs11", "PRBS-11", do_prbs, 11)
        m:item("prbs15", "PRBS-15", do_prbs, 15)
        m:item("prbs16", "PRBS-16", do_prbs, 16)
        m:item("prbs23", "PRBS-23", do_prbs, 23)
        m:item("prbs31", "PRBS-31", do_prbs, 31)
        m:item("fixedw", "Fixed 10 bit word (PAT)", do_custom, 0x8)
        m:item("dc-bal", "DC-balanced word (PAT, ~PAT)", do_custom, 0x9)
        m:item("fixedp", "Fixed pattern (000, PAT, 3ff, ~PAT)", do_custom, 0xa)
        m:item("preemphasis",  "Set QLM pre-emphasis", set_preemphasis, qlm_tuning.qlm)
        m:item("preandpost",  "Set QLM pre and post taps", set_preandpost, qlm_tuning.qlm)
        m:item("rx_eval",  "Perform a RX equalization evaluation", manual_rx_evaluation, qlm_tuning.qlm)

        m:item("quit",   "Main menu")
    until (m:show() == "quit")
end

return qlm_tuning
